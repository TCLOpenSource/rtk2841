/*
 *  Copyright (C) 2017 Realtek
 *  All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/ctype.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/printk.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/spinlock.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <mach/io.h>

#include <mach/platform.h>
#include <rtk_kdriver/pcbMgr.h>
#include <rtk_kdriver/rtk_emcu_export.h>
#include "rtk_kdv_emcu.h"
#include "../ir/inc/ir_input.h"
#include "../ir/inc/irrc_common.h"

/***************************************************************************
Information:
1. sample code porting from AP\system\src\Platform_Lib\miscMgr\wakeup.cpp
    GoogleTV/kernel/android/nougat/device/realtek/frameworks/native/libs/Platform_Lib/miscMgr/wakeup.cpp
2. Device node allocate at /dev/emcu_kdv
3. Device attribute allocate at /sys/devices/virtual/misc/emcu_kdv
4. To check pcb param on target over cmd "ls /sys/realtek_boards/pcb_enum"
5. There are two method to enable Auto Parse.
    One is modify config of kernel, another is key in command at bootcode.
    bootcode command is "env set mmc_param_1 emcu_auto=1;env save"


****************************************************************************/

/************************************************************************
 * Local definition
 ************************************************************************/
#ifdef CONFIG_EMCU_AUTO_PARSER
#define AUTO_PCB_PARAM
#endif

//#define FAKE_PCB_PIN_NAME // fake pin name for testing

#ifndef FAKE_PCB_PIN_NAME
#define EMCU_WIFI_REKEY_PIN_NAME    "1,PIN_WIFI_REKEY_EN"
#define EMCU_WOWLAN_PIN_NAME    "1,PIN_WOWLAN_EN"
#define EMCU_POWER_PIN_NAME     "PIN_POWER_EN,PIN_POWER_EN2"
#define EMCU_DDR_POWER_NAME     "PIN_DDR_POWER_EN"
#define EMCU_IRDA_PIN_NAME      "3,PIN_IRDA_UKEY_0,PIN_IRDA_UKEY_1,PIN_IRDA_UKEY_2"
#define EMCU_KEYPAD_PIN_NAME \
            "10,PIN_KEYPAD_0,PIN_KEYPAD_1,PIN_KEYPAD_2,PIN_KEYPAD_3,PIN_KEYPAD_4,"\
            "PIN_KEYPAD_5,PIN_KEYPAD_6,PIN_KEYPAD_7,PIN_KEYPAD_8,PIN_KEYPAD_9"
#else
#define EMCU_WIFI_REKEY_PIN_NAME    "1,PIN_DDR_POWER_EN"
#define EMCU_WOWLAN_PIN_NAME    "1,PIN_DDR_POWER_EN"
#define EMCU_POWER_PIN_NAME     "PIN_USB_5V_GYGY,PIN_DDR_POWER_EN"
#define EMCU_DDR_POWER_NAME     "PIN_LIGHT_SENSOR_ON"
#define EMCU_IRDA_PIN_NAME      "3,PIN_USB_5V_EN,PIN_POWER_EN,PIN_LIGHT_SENSOR_ON"  //test pattern 1
#define EMCU_KEYPAD_PIN_NAME \
            "10,PIN_USB_5V_GYGY,PIN_DDR_POWER_EN,PIN_LIGHT_SENSOR_ON,"\
            "PIN_5V_DET_HDMI_1,PIN_5V_DET_HDMI_2,PIN_5V_DET_HDMI_3,"\
            "PIN_5V_DET_HDMI_4,PIN_OTP_POWER_INFO,PIN_MHL_CABLE_DETECT,PIN_USB_5V_EN"

#endif

#define PARSE_USER              0
#define PARSE_AUTO              1
#define PARSE_IN_CASE           2

#define EMCU_IRDA_ALERT         BIT(1)
#define EMCU_POWER_EN_ALERT     BIT(2)
#define EMCU_KEYPAD_ALERT       BIT(3)
#define EMCU_WOWLAN_ALERT       BIT(4)
#define EMCU_WIFI_DG_ALERT      BIT(5)


#define IDX_REKEY               (0x57ULL)
#define IDX_DDR_POWER           (0x56ULL)

#define IO_TPYE_REKEY           (IDX_REKEY<<56)
#define IO_TPYE_DDR_POWER       (IDX_DDR_POWER<<56)


/************************************************************************
 * Local variable
 ************************************************************************/
static unsigned int emcu_auto_event;
static unsigned int emcu_test_ctl;
static unsigned int local_sharemem_sup[32];
static unsigned int local_sharemem_res[32];

#define EMCU_PARSE_EN   BIT(0)
#define EMCU_CHK_SKIP   BIT(1)

/************************************************************************
 * Return format
 * [7:0] = address (0: for GPIO 0~31, 4: for GPIO 32~61)
 * [15:8] = gpio_no (base on address, Range is 0~31 )
 * example:
 *          gpio 10  ==> 0x0a00
 *          gpio 31  ==> 0x1f00
 *          gpio 32  ==> 0x0004
 *          gpio 48  ==> 0x1004
 ************************************************************************/
static
unsigned int get_gpio_info(unsigned char GPIO_NUM)
{
    unsigned int loop = 0;
    unsigned int bitOffset = 0;
    unsigned int regAddr = 0;

    while(loop < 2){    //iso gpio have 2 set only
        if(GPIO_NUM <= (31+(32*loop))){
            bitOffset = GPIO_NUM - (32*loop);
            regAddr = loop*4;
            return ((bitOffset<<SHT_GPIO_BIT) | regAddr );
        }
        loop++;
    }
    return 0xff;
}

/************************************************************************
 * This function handle GPIO type iopad always.
 * Return format
 * [7:0] = address (0: for GPIO 0~31, 4: for GPIO 32~61)
 * [15:8] = gpio_no (base on address, Range is 0~31 )
 * [19:16] = invert.
 * [23:20] = iso_gpio type(0x4)
 * [31:24] = special event flag.
 *           ex. 0x57: re-key; 0x56: ddr power pin
 ************************************************************************/
static
unsigned int powerMgr_interpret_gpio_value(unsigned long long param)
{
    unsigned int ptype;
    unsigned int index;
    unsigned int invert;
    unsigned int para_tmp;
    unsigned int event_type;

    event_type = ((param >> 56) & 0xff);
    ptype   = GET_PIN_TYPE(param);
    index   = GET_PIN_INDEX(param);
    invert  = GET_GPIO_INVERT(param);
    para_tmp = get_gpio_info(index);
    if(para_tmp == 0xff)
        return para_tmp;
    para_tmp |= (invert<<SHT_GPIO_IVR)|(ptype<<SHT_GPIO_TYP)|(event_type<<24);

    EMCU_DEBUG("index=0x%x\n",index);
    EMCU_DEBUG("invert=0x%x\n",invert);
    EMCU_DEBUG("para_tmp=0x%x\n",para_tmp);

    return para_tmp;
}

/************************************************************************
 * @type   : transfer data type in Dec od Hex
 * @i_cnt  : max param count, if beyond, report error
 * @*o_cnt : pointer for report how many param get
 * @param  : pointer of arry that data parsed.
 * @buf    : input data buffer
 * @count  : length of input data
 ************************************************************************/
static
int emcu_get_param_single(int type,
        unsigned long long* param,
        const char *buf, size_t count)
{
    int ret = -1;
    unsigned long long tmp_long;

    if (kstrtoull(buf, type, &tmp_long)){
        goto FINISH_OUT;
    }else{
        *param = tmp_long;
    }
    ret = 0;

FINISH_OUT:
    if(ret)
        EMCU_DEBUG("get param fail\n");

    return ret;
}


/************************************************************************
 * @type   : transfer data type in Dec od Hex
 * @i_cnt  : max param count, if beyond, report error
 * @*o_cnt : pointer for report how many param get
 * @param  : pointer of arry that data parsed.
 * @buf    : input data buffer
 * @count  : length of input data
 * return  : return -1 if
 *                  1. There is no any parameter was found.
 *                  2. Number of found parameters big then i_cnt.
 *
 ************************************************************************/
static
int emcu_get_param_multi(int type,
        int i_cnt,
        int* o_cnt,
        unsigned long long* param,
        const char *buf, size_t count)
{
    int ret = -1;
    int i;
    char last_char;
    char *opt = NULL;
    char *buftmp = NULL;
    char *buforg = NULL;
    unsigned long long tmp_long;

    buforg = buftmp = kmalloc(count, GFP_KERNEL);
    if(!buftmp){
        goto FINISH_OUT;
    }
    memset(buftmp,0,count);
    strcpy(buftmp, buf);

    i = strlen(buftmp)-1;
    last_char = buftmp[i];

    if(!isdigit(last_char)&& !isalpha(last_char) ){
        buftmp[i] = 0;
    }

    i = 0;
    while ((opt = strsep(&buftmp, ",")) != NULL) {

        if(i && (type == 0xff)){    // parse PCB parameter
            if(pcb_mgr_get_enum_info_byname(opt, &tmp_long) == 0){
                param[i] = tmp_long;
                if (!strncmp(opt, EMCU_DDR_POWER_NAME, strlen(EMCU_DDR_POWER_NAME))){
                    EMCU_DEBUG("DDR power pin hit\n");
                    param[i] |= IO_TPYE_DDR_POWER;
                }
                EMCU_DEBUG("%s[0x%llx] got.\n",opt,param[i]);
                i++;
            }else{
                EMCU_INFO("%s can't be found.\n",opt);
            }
        }else{
            if (kstrtoull(opt, type, &tmp_long)){
                goto FINISH_OUT;
            }else{
                param[i] = tmp_long;
                EMCU_DEBUG("param[%d]=0x%llx\n",i,param[i]);
                i++;
            }
        }
    }
    *o_cnt = i;
    if((*o_cnt == 0) || ((*o_cnt) > i_cnt)) {
        goto FINISH_OUT;
    }
    ret = 0;

FINISH_OUT:
    if(buforg)
        kfree(buforg);
    if(ret)
        EMCU_DEBUG("get param fail\n");

    return ret;
}

/************************************************************************
 * FUNC: clear assignee operation, not clear all share memory
 *
 * example:
 *  cat emcu_clr_pm_task
 *  echo 1 > emcu_clr_pm_task
 *
 ************************************************************************/
static
ssize_t emcu_clr_pm_task_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
#if 1
    return sprintf(buf,
            "please key in \"echo param > /sys/devices/virtual/misc/emcu_kdv/emcu_clr_pm_task\"\n"
            "  nibble: 0:KEYPAD; 1:CEC; 2:PPS; 3:WUT; 4:IRDA; 5:PWEN; 6:WOW_nible; 7:STM_nible\n"
            "  bit:    24:WOW; 25:MHL; 26:REV; 27:UART; 28|29:STM; 30:RTC; 31:REV\n");

#else
    return sprintf(buf, "0x%x\n",(unsigned int)GET_EVENT_MSG());
#endif
}

static
ssize_t emcu_clr_pm_task_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    unsigned int msg;
    unsigned long long loc;
    size_t ret = count;

    const char* str[]={
        "KEYPAD","CEC","PPS","WUT",
        "IRDA","PWEN","WOW","STM" };

    if(emcu_get_param_single(16,(unsigned long long*)&loc,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    /*
     The input value between 0~7 is meaning group func.
     The input value between 20~31 is meaning bit func. Make sure which func you want to clear.
     bit[24:31] These area are bit operation.
    */

    if(((loc > 7) && (loc < 20)) || (loc > 31)){
        EMCU_DEBUG("input mismatch\n");
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(loc < (sizeof(str) / sizeof(str[0])))
        EMCU_INFO("\n%sYou like to clear %s task.\n",__func__,str[loc]);

    msg = GET_EVENT_MSG();

    if(loc < 8){
        msg &= ~(0xf<<(loc*4));
    }else{
        if((loc == 28) || (loc == 29) ){
            /* bit[29:28] are area for STM */
            msg &= ~(0x3<<loc);
        }else{
            msg &= ~(0x1<<loc);
        }
    }

    SET_EVENT_MSG(msg);

    EMCU_INFO("pm_event_msg=0x%x\n",msg);

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_clr_pm_task, S_IRUGO | S_IWUSR,
        emcu_clr_pm_task_dev_show,emcu_clr_pm_task_dev_store);

/************************************************************************
 * FUNC: claer all share memory immediately
 * example:
 *  cat emcu_clr_share_mem
 *  echo 1 > emcu_clr_share_mem
 *
 ************************************************************************/
static
ssize_t emcu_clr_share_mem_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{

    int i;
    char buf_tmp[512]={0};

    EMCU_INFO("%s(%u)\n", __func__, __LINE__);
#define EMCU_TEST_ENABLE
#ifdef  EMCU_TEST_ENABLE
    for(i=0;i<RTD_SHARE_MEM_LEN;i++){
        rtd_outl(RTD_SHARE_MEM_BASE+(4*i),0xffffffff);
    }
    EMCU_INFO("for test only, fill 0xffffffff to reg0~31\n");
#endif

    for(i=0;i<RTD_SHARE_MEM_LEN;i++){
        if(i)
            sprintf(buf_tmp+strlen(buf_tmp),",");
        sprintf(buf_tmp+strlen(buf_tmp),"%08x",rtd_inl(RTD_SHARE_MEM_BASE+(4*i)));
    }
    emcu_auto_event = 0;
    return sprintf(buf, "%s\n",buf_tmp);
}

static
ssize_t emcu_clr_share_mem_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    int i;
    unsigned long long in_val;
    size_t ret = count;

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(in_val == 1){
        for(i=0;i<RTD_SHARE_MEM_LEN;i++){
            rtd_outl(RTD_SHARE_MEM_BASE+(4*i),0);
        }
        emcu_auto_event = 0;
    }else{
        ret = -EINVAL;
        EMCU_DEBUG("input mismatch\n");
    }

FINISH_OUT:
    return ret;


}

DEVICE_ATTR(emcu_clr_share_mem, S_IRUGO | S_IWUSR,
        emcu_clr_share_mem_dev_show,emcu_clr_share_mem_dev_store);

/************************************************************************
  * FUNC: display share memory value
 * example:
 *  cat emcu_show_share_mem
 *
 ************************************************************************/
static
ssize_t emcu_show_share_mem_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    int i;
    unsigned int share_tmp[32];

    for(i=0;i<RTD_SHARE_MEM_LEN;i++){
        share_tmp[i] = rtd_inl(RTD_SHARE_MEM_BASE+(4*i));
        //EMCU_INFO("mem[%02d]=0x%08x\n",i,share_mem[i]);
    }
    return sprintf(buf,
            "mem[00]=0x%08x mem[01]=0x%08x mem[02]=0x%08x mem[03]=0x%08x\n"
            "mem[04]=0x%08x mem[05]=0x%08x mem[06]=0x%08x mem[07]=0x%08x\n"
            "mem[08]=0x%08x mem[09]=0x%08x mem[0a]=0x%08x mem[0b]=0x%08x\n"
            "mem[0c]=0x%08x mem[0d]=0x%08x mem[0e]=0x%08x mem[0f]=0x%08x\n"
            "mem[10]=0x%08x mem[11]=0x%08x mem[12]=0x%08x mem[13]=0x%08x\n"
            "mem[14]=0x%08x mem[15]=0x%08x mem[16]=0x%08x mem[17]=0x%08x\n"
            "mem[18]=0x%08x mem[19]=0x%08x mem[1a]=0x%08x mem[1b]=0x%08x\n"
            "mem[1c]=0x%08x mem[1d]=0x%08x mem[1e]=0x%08x mem[1f]=0x%08x\n",
            share_tmp[ 0],share_tmp[ 1],share_tmp[ 2],share_tmp[ 3],
            share_tmp[ 4],share_tmp[ 5],share_tmp[ 6],share_tmp[ 7],
            share_tmp[ 8],share_tmp[ 9],share_tmp[10],share_tmp[11],
            share_tmp[12],share_tmp[13],share_tmp[14],share_tmp[15],
            share_tmp[16],share_tmp[17],share_tmp[18],share_tmp[19],
            share_tmp[20],share_tmp[21],share_tmp[22],share_tmp[23],
            share_tmp[24],share_tmp[25],share_tmp[26],share_tmp[27],
            share_tmp[28],share_tmp[29],share_tmp[30],share_tmp[31]);
}

static
ssize_t emcu_show_share_mem_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    EMCU_INFO("\n(%s)no operation!\n",__func__);

    return count;
}

DEVICE_ATTR(emcu_show_share_mem, S_IRUGO | S_IWUSR,
        emcu_show_share_mem_dev_show,
        emcu_show_share_mem_dev_store);

/************************************************************************
 * FUNC: enable weke on WIFI dongle rekey func,
 *       emcu will check this func with emcu_set_WOL simultaneously.
 * example:
 *  cat emcu_set_WOWLAN
 *  echo 1 > emcu_set_WOWLAN
 ************************************************************************/
static
ssize_t emcu_set_wifi_dg_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
            "please key in \"echo param > /sys/devices/virtual/misc/emcu_kdv/emcu_set_wifi_dg\"\n"
            "        only one param which format match PCB param.");

}

/************************************************************************
 *
 ************************************************************************/
static
int powerMgr_wifi_dg_parser(const char *buf, size_t count,unsigned int ctl)
{
    int ret = 0;
    unsigned long long in_val;
    unsigned int pm_event_msg;
    unsigned int para_tmp;
    unsigned char kptype;
    int param_cnt;
    unsigned long long param[2];

    if(ctl == PARSE_AUTO){
        if(!(emcu_test_ctl & EMCU_PARSE_EN)){
            EMCU_DEBUG("%s(%d)auto parser have not support\n",__func__,__LINE__);
            ret = -EINVAL;
            goto FINISH_OUT;
        }
        if(emcu_get_param_multi(0xff,2,&param_cnt,param,
                EMCU_WIFI_REKEY_PIN_NAME,
                sizeof(EMCU_WIFI_REKEY_PIN_NAME)))
        {
            ret = -EINVAL;
            goto FINISH_OUT;
        }
        if(param_cnt != 2){
            ret = -EINVAL;
            goto FINISH_OUT;
        }

        in_val = param[1];
        EMCU_DEBUG("pin value: 0x%llx \n",param[1]);

    }else if(ctl == PARSE_USER){
        if(emcu_get_param_single(16,&in_val,buf,count)){
            ret = -EINVAL;
            goto FINISH_OUT;
        }
    }else{
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    EMCU_DEBUG("WIFI dongle GPIO = 0x%llx\n",in_val);
    EMCU_DEBUG("GET_PIN_TYPE:%x\n",GET_PIN_TYPE(in_val));

    in_val |= IO_TPYE_REKEY;    //add re-key flag
    kptype = GET_PIN_TYPE(in_val);
    if( (kptype == PCB_PIN_TYPE_ISO_GPIO) ||
        (kptype == PCB_PIN_TYPE_ISO_GPI) )
    {
        pm_event_msg = GET_EVENT_MSG();
        para_tmp = powerMgr_interpret_gpio_value(in_val);
        if(para_tmp == 0xff)
            goto INVAILD;

/*
WIFI dongle event Format define below:
[7:0] = address (0: 0~31, 4:32~)
[15:8] = gpio_no
[19:16] = invert.
[23:20] = iso_gpio type(0x4)
[31:24] = 0x57 (opcode for WIFI dongle rekey func)
*/
        SET_WIFI_DG_PARM(para_tmp);

        pm_event_msg |= ((unsigned int)0x1 << loc_wow); // bit0:WOW enable
        SET_EVENT_MSG(pm_event_msg);
        EMCU_INFO("pm_event_msg=0x%x\n",pm_event_msg);
    }else{
INVAILD:
        EMCU_DEBUG("Has not vaild pin assigne!\n");
        ret = -EINVAL;
        goto FINISH_OUT;
    }

FINISH_OUT:
    return ret;
}

/************************************************************************
 *
 ************************************************************************/
static
ssize_t emcu_set_wifi_dg_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    size_t ret = 0;

    if(emcu_test_ctl & EMCU_PARSE_EN){
        ret = powerMgr_wifi_dg_parser(buf,count,PARSE_AUTO);
    }else{
        ret = powerMgr_wifi_dg_parser(buf,count,PARSE_USER);
    }

    if(ret){
        ret = -EINVAL;
        goto FINISH_OUT;
    }else{
        ret = count;
        emcu_auto_event |= EMCU_WIFI_DG_ALERT;
    }

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_set_wifi_dg, S_IRUGO | S_IWUSR,
        emcu_set_wifi_dg_dev_show,emcu_set_wifi_dg_dev_store);

/************************************************************************
 * FUNC: enable weke on LAN func
 * example:
 *  cat emcu_set_WOWLAN
 *  echo 1 > emcu_set_WOWLAN
 ************************************************************************/
static
ssize_t emcu_set_WOL_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf, "0x%x\n",(unsigned int)GET_EVENT_MSG());
#if 0
    return sprintf(buf,
            "please key in \"echo param > /sys/devices/virtual/misc/emcu_kdv/emcu_enable_wowlan\"\n"
            "        param maust as 0~15");
#endif
}

static
ssize_t emcu_set_WOL_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{

    unsigned long long in_val;
    unsigned int pm_event_msg;
    size_t ret = count;

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }
    if(in_val >1){
        EMCU_DEBUG("\nparameter big then 1. Ignore setting.\n");
    }
    pm_event_msg = GET_EVENT_MSG();
    pm_event_msg &= ~((unsigned int)0x1 << loc_wow);
    pm_event_msg |= ((unsigned int)in_val << loc_wow); // bit0:WOW enable
    SET_EVENT_MSG(pm_event_msg);
    EMCU_INFO("pm_event_msg=0x%x\n",pm_event_msg);

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_set_WOL, S_IRUGO | S_IWUSR,
        emcu_set_WOL_dev_show,emcu_set_WOL_dev_store);


/************************************************************************
 * FUNC: enable weke on wide LAN func
 * example:
 *  cat emcu_set_WOWLAN
 *  echo 1 > emcu_set_WOWLAN
 ************************************************************************/
static
ssize_t emcu_set_WOWLAN_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
            "please key in \"echo param > /sys/devices/virtual/misc/emcu_kdv/emcu_enable_wowlan\"\n"
            "        param maust be pcb_param about GPIO of extern WOW_Module");

}

/************************************************************************
 *
 ************************************************************************/
static
int powerMgr_wowlan_parser(const char *buf, size_t count,unsigned int ctl)
{
    int ret = 0;
    unsigned long long in_val;
    unsigned int pm_event_msg;
    unsigned int para_tmp;
    unsigned char valid_num;
    unsigned char kptype;
    int param_cnt;
    unsigned long long param[2];
    /*
     Note:
        Currently, wake on wide LAN use extern module
        and send messange by GPIO to inform EMCU.
        So, It's need to know which GPIO pin used.
    */
    if(ctl == PARSE_AUTO){
        if(!(emcu_test_ctl & EMCU_PARSE_EN)){
            EMCU_DEBUG("%s(%d)auto parser have not support\n",__func__,__LINE__);
            ret = -EINVAL;
            goto FINISH_OUT;
        }
        if(emcu_get_param_multi(0xff,2,&param_cnt,param,
                EMCU_WOWLAN_PIN_NAME,
                sizeof(EMCU_WOWLAN_PIN_NAME)))
        {
            ret = -EINVAL;
            goto FINISH_OUT;
        }

        EMCU_DEBUG("pin cnt: %d \n",param_cnt-1);
        if(param_cnt != 2){
            ret = -EINVAL;
            goto FINISH_OUT;
        }

        in_val = param[1];
        EMCU_DEBUG("pin value: 0x%llx \n",param[1]);

    }else if(ctl == PARSE_USER){
        if(emcu_get_param_single(16,&in_val,buf,count)){
            ret = -EINVAL;
            goto FINISH_OUT;
        }
    }else{
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    EMCU_DEBUG("WOWLAN GPIO = 0x%llx\n",in_val);
    EMCU_DEBUG("GET_PIN_TYPE:%x\n",GET_PIN_TYPE(in_val));

    kptype = GET_PIN_TYPE(in_val);
    if( (kptype == PCB_PIN_TYPE_ISO_GPIO) ||
        (kptype == PCB_PIN_TYPE_ISO_GPI) )
    {
        pm_event_msg = GET_EVENT_MSG();
        para_tmp = powerMgr_interpret_gpio_value(in_val);
        if(para_tmp == 0xff)
            goto INVAILD;
        /*
         To check if there are keypad parameter already.
         if not, enable keypad function and to set one parameter
         */
        valid_num = ((pm_event_msg >> loc_keypad) & 0xf);

        /* wowlan info locate at last keypad field always */
        if(emcu_auto_event & EMCU_WOWLAN_ALERT){
            SET_KEYPAD_PARM(valid_num-1,para_tmp);
        }else{
            if(valid_num == PARAM_LEN_KEYPAD){
                /*
                 Force insert WOWLAN PIn to last field of keypad.
                 It's will cause to lost last original keypad pcb enum.
                 */
                valid_num -= 1;
            }
            SET_KEYPAD_PARM(valid_num,para_tmp);
            valid_num += 1;
        }
        EMCU_DEBUG("valid_num:%u\n",valid_num);

        SET_EVENT_IDX(pm_event_msg,loc_keypad,valid_num);
        SET_EVENT_MSG(pm_event_msg);
        EMCU_INFO("pm_event_msg=0x%x\n",pm_event_msg);
    }else{
INVAILD:
        EMCU_DEBUG("Has not vaild pin assigne!\n");
        ret = -EINVAL;
        goto FINISH_OUT;
    }

FINISH_OUT:
    return ret;

}

/************************************************************************
 *
 ************************************************************************/
static
ssize_t emcu_set_WOWLAN_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    size_t ret = 0;

    if(emcu_test_ctl & EMCU_PARSE_EN){
        ret = powerMgr_wowlan_parser(buf,count,PARSE_AUTO);
    }else{
        ret = powerMgr_wowlan_parser(buf,count,PARSE_USER);
    }

    if(ret){
        ret = -EINVAL;
        goto FINISH_OUT;
    }else{
        ret = count;
        emcu_auto_event |= EMCU_WOWLAN_ALERT;
    }

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_set_WOWLAN, S_IRUGO | S_IWUSR,
        emcu_set_WOWLAN_dev_show,emcu_set_WOWLAN_dev_store);

/************************************************************************
 * To reference ./drivers/rtk_kdriver/include/rtk_kdriver/pcbMgr.h for PIN define
 ************************************************************************/

static
void powerMgr_setup_keypad_multi(unsigned int num,unsigned long long* param)
{
    unsigned int para_tmp;
    unsigned int pm_event_msg;
    unsigned char kptype;
    unsigned char kpidx;
    unsigned char param1;
    unsigned char param2;
    unsigned char i;
    unsigned char valid_flag;
    unsigned char valid_num;

    unsigned char valid_num_old = 0;
    unsigned int para_old = 0;

    if(num>PARAM_LEN_KEYPAD)
        num = PARAM_LEN_KEYPAD;

    /* To check if wake on wide lan info has been setted. */
    valid_num_old = ((GET_EVENT_MSG() >> loc_keypad) & 0xf);
    if( (emcu_auto_event & EMCU_WOWLAN_ALERT) &&
        (valid_num_old) )
    {
        para_old = GET_KEYPAD_PARM(valid_num_old-1);
        EMCU_DEBUG("last keypad param%d=0x%x\n",(valid_num_old-1),para_old);
        if(num == PARAM_LEN_KEYPAD){
            /*It's need to reserve one field for WOWLAN. */
            num -= 1;
        }
    }

    for(i=0;i<PARAM_LEN_KEYPAD;i++){
        SET_KEYPAD_PARM(i,0);
    }

    valid_num = 0;
    for(i=0;i<num;i++){
        EMCU_DEBUG("keypad param%u=0x%llx\n",i,*(param+i));
        valid_flag = 0;
        kptype = GET_PIN_TYPE(*(param+i));
        kpidx = GET_PIN_INDEX(*(param+i));
        EMCU_DEBUG("kptype=%u\n",kptype);
        EMCU_DEBUG("kpidx=%u\n",kpidx);
        switch(kptype){
        case PCB_PIN_TYPE_ISO_GPIO:
        case PCB_PIN_TYPE_ISO_GPI:
            EMCU_DEBUG("PCB_PIN_TYPE_ISO_GPIO\n");
            para_tmp = powerMgr_interpret_gpio_value(*(param+i));
            if(para_tmp == 0xff)
                break;
            valid_flag =1;
            break;
        case PCB_PIN_TYPE_LSADC:
            EMCU_DEBUG("PCB_PIN_TYPE_LSADC\n");
            //kpidx  = lsadc set
            param1 = GET_LSADC_HITVALUE(*(param+i));    //get hit value
            param2 = GET_LSADC_TOLERANCE(*(param+i));   //get tolerance
            para_tmp = (param1<<8)|param2;
            para_tmp|=(kpidx&0xf)<<16;
            para_tmp|=(kptype&0xf)<<20;
            valid_flag =1;
            break;
        case PCB_PIN_TYPE_ISO_UNIPWM:
        case PCB_PIN_TYPE_ISO_PWM:
        default:
            EMCU_DEBUG("unknow pin type\n");
            break;
        }

        if(valid_flag){
            EMCU_DEBUG("KEYPAD_PARM%u=0x%08x\n",valid_num,para_tmp);
            SET_KEYPAD_PARM(valid_num,para_tmp);
            valid_num++;
        }
    }

    if( (emcu_auto_event & EMCU_WOWLAN_ALERT) &&
        (valid_num_old) )
    {
        SET_KEYPAD_PARM(valid_num,para_old);
        valid_num++;
        EMCU_DEBUG("To add WOWLAN gpio [0x%08x]\n",para_old);
    }

    pm_event_msg = GET_EVENT_MSG();
    EMCU_DEBUG("Valid keypad paramteter have %u set.\n",valid_num);
    SET_EVENT_IDX(pm_event_msg,loc_keypad,valid_num);
    SET_EVENT_MSG(pm_event_msg);
    EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);

    return;
}

/************************************************************************
 * FUNC: enable and setting keypad parameter
 * example:
 *  cat emcu_setup_keypad_multi
 *  echo key_num,param1,param2,...,... > /sys/devices/virtual/misc/emcu_kdv/emcu_setup_keypad_multi
 *      echo 6,12345678aabbcdd,aabbccddeeff3456,100011204,222,444,100011204 > emcu_setup_keypad_multi
 * Note:
 *  1. the max number of keypad are 10
 *  2. get pcb info at "/sys/realtek_boards/pcb_enum/"
 *  2. get pcb info by "cat /sys/realtek_boards/pcb_enum/PIN_XXXX"
 *
 ************************************************************************/
static
ssize_t emcu_setup_keypad_multi_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo key_num,param1,param2,...,... > /sys/devices/virtual/misc/emcu_kdv/emcu_setup_keypad_multi\"\n");
}


/************************************************************************
 To reference ./drivers/rtk_kdriver/include/rtk_kdriver/pcbMgr.h for PIN define
  PIN_KEYPAD_N  N =0~9
 ************************************************************************/
static
int powerMgr_keypad_parser(const char *buf, size_t count,unsigned int ctl)
{
    int ret = 0;
    int i;
    int param_cnt;
    unsigned long long param[11];
    const char* buf_pt;
    int  pmode;
    int cnt_tmp;

    if(ctl != PARSE_AUTO){
        pmode = 16;
        buf_pt = buf;
        cnt_tmp = count;
    }else{
        if(!(emcu_test_ctl & EMCU_PARSE_EN)){
            EMCU_DEBUG("%s(%d)auto parser have not support\n",__func__,__LINE__);
            ret = -EINVAL;
            goto FINISH_OUT;
        }
        pmode = 0xff;
        buf_pt = EMCU_KEYPAD_PIN_NAME;
        cnt_tmp = sizeof(EMCU_KEYPAD_PIN_NAME);

    }

    if(emcu_get_param_multi(pmode,11,&param_cnt,param,buf_pt,cnt_tmp)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(ctl != PARSE_AUTO){
        if(param[0] != (param_cnt-1)){
            EMCU_DEBUG("input mismatch\n");
            ret = -EINVAL;
            goto FINISH_OUT;
        }
    }else{
        if(param_cnt < 2){
            ret = -EINVAL;
            goto FINISH_OUT;
        }
        param[0] = (param_cnt-1);
        for(i=0;i<param_cnt;i++){
            EMCU_DEBUG("pin%d: 0x%llx \n",i+1,param[i+1]);
        }
    }

    powerMgr_setup_keypad_multi((unsigned int)param[0],&param[1]);
    emcu_auto_event |= EMCU_KEYPAD_ALERT;

FINISH_OUT:
    return ret;
}

/************************************************************************

 ************************************************************************/
static
ssize_t emcu_setup_keypad_multi_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    size_t ret = 0;

    if(emcu_test_ctl & EMCU_PARSE_EN){
        ret = powerMgr_keypad_parser(buf,count,PARSE_AUTO);
    }else{
        ret = powerMgr_keypad_parser(buf,count,PARSE_USER);
    }

    if(ret){
        ret = -EINVAL;
        goto FINISH_OUT;
    }else{
        ret = count;
        emcu_auto_event |= EMCU_KEYPAD_ALERT;
    }

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_setup_keypad_multi, S_IRUGO | S_IWUSR,
        emcu_setup_keypad_multi_dev_show,
        emcu_setup_keypad_multi_dev_store);

/************************************************************************
 * FUNC: enable and setting keypad parameter
 * example:
 *  cat emcu_setup_cec
 *  echo 1 > emcu_setup_cec
 * Note:
 *
 ************************************************************************/
static
ssize_t emcu_setup_cec_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "%x\n",GET_EVENT_MSG());
}

static
ssize_t emcu_setup_cec_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    ssize_t ret = count;
    unsigned int pm_event_msg;
    unsigned long long in_val;

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(in_val >15){
        EMCU_DEBUG("\nparameter big then 15. Ignore setting.\n");
        ret = -EINVAL;
        goto FINISH_OUT;
    }else{
        pm_event_msg = GET_EVENT_MSG();
            SET_EVENT_IDX(pm_event_msg,loc_cec,(unsigned int)in_val);
            SET_EVENT_MSG(pm_event_msg);
            EMCU_INFO("pm_event_msg=0x%x\n",pm_event_msg);
    }
FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_setup_cec, S_IRUGO | S_IWUSR,
        emcu_setup_cec_dev_show,emcu_setup_cec_dev_store);


/************************************************************************
 * FUNC: enable mhl func
 * example:
 *  cat emcu_setup_mhl
 *  echo 1 > emcu_setup_mhl
 * Note:
 *
 ************************************************************************/
static
ssize_t emcu_setup_mhl_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo 1 > /sys/devices/virtual/misc/emcu_kdv/emcu_setup_mhl\"\n");
}

static
ssize_t emcu_setup_mhl_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{

    unsigned int pm_event_msg;
    unsigned long long in_val;
    size_t ret = count;

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }
    if(in_val == 1){
        pm_event_msg = GET_EVENT_MSG();
        pm_event_msg |= ((unsigned int)0x2 << loc_mhl); // bit1:MHL enable
        SET_EVENT_MSG(pm_event_msg);
        EMCU_INFO("CBUS pm_event_msg=0x%x\n",pm_event_msg);
    }else{
        ret = -EINVAL;
        EMCU_DEBUG("input mismatch\n");
    }
FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_setup_mhl, S_IRUGO | S_IWUSR,
        emcu_setup_mhl_dev_show,emcu_setup_mhl_dev_store);


/************************************************************************
 * FUNC: enable uart func
 * example:
 *  cat emcu_setup_uart
 *  echo 1 > emcu_setup_uart
 * Note:
 *
 ************************************************************************/
static
ssize_t emcu_setup_uart_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo 1 > /sys/devices/virtual/misc/emcu_kdv/emcu_setup_uart\"\n");
}

static
ssize_t emcu_setup_uart_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{

    unsigned int pm_event_msg;
    unsigned long long in_val;
    size_t ret = count;

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(in_val == 1){
        pm_event_msg = GET_EVENT_MSG();
        pm_event_msg |= ((unsigned int)0x8 << loc_uart); // bit3:UART0 disable
        SET_EVENT_MSG(pm_event_msg);
        EMCU_INFO("UART pm_event_msg=0x%x\n",pm_event_msg);

    }else{
        ret = -EINVAL;
        EMCU_DEBUG("input mismatch\n");
    }

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_setup_uart, S_IRUGO | S_IWUSR,
        emcu_setup_uart_dev_show,emcu_setup_uart_dev_store);

/************************************************************************
 * FUNC: enable pervious power on source func
 * example:
 *  cat emcu_setup_ppsource
 *  echo 1 > emcu_setup_ppsource
 * Note:
 *
 ************************************************************************/
static
ssize_t emcu_setup_ppsource_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo param > /sys/devices/virtual/misc/emcu_kdv/emcu_setup_ppsource\"\n"
        "        note: support VGA1 only, please setting param=3");
}

static
ssize_t emcu_setup_ppsource_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{

    unsigned int pm_event_msg;
    unsigned long long in_val;
    size_t ret = count;
    char str[][10]={"HDMI1","HDMI2","HDMI3",
            "VGA1","VGA2","VGA3",
            "AV1","AV2","AV3"};

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }
    if(in_val < 10){
        EMCU_INFO("previously source is %s\n",str[in_val]);
        SET_PPS_PARM((unsigned int)in_val);
        pm_event_msg = GET_EVENT_MSG();
        SET_EVENT_IDX(pm_event_msg,loc_pps,PARAM_LEN_PPS);
        SET_EVENT_MSG(pm_event_msg);
        EMCU_INFO("pm_event_msg=0x%x\n",pm_event_msg);
    }else{
        ret = -EINVAL;
        EMCU_DEBUG("unknow previously source.\n");
    }

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_setup_ppsource, S_IRUGO | S_IWUSR,
        emcu_setup_ppsource_dev_show,emcu_setup_ppsource_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
void powerMgr_setup_wakeup_timer(unsigned int days,unsigned int hours,unsigned int mins)
{
    unsigned int pm_event_msg;
    unsigned int total_mins;

    if(hours > 23)
        hours = 23;
    if(mins > 59)
        mins = 59;

    total_mins = (days * 24 *60) + (hours *60) + mins;

    EMCU_DEBUG("sleeping time is %ddays %dhours %dmins\n",days,hours,mins);
    EMCU_DEBUG("total sleeping time is %u minute\n",total_mins);

    SET_WUT_PARM(total_mins);

    EMCU_DEBUG("IDX_REG_WUT adr =0x%x\n",
        RTD_SHARE_MEM_BASE+4*IDX_REG_WUT);
    EMCU_DEBUG("IDX_REG_WUT val =0x%x\n",
        rtd_inl(RTD_SHARE_MEM_BASE+4*IDX_REG_WUT));
    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_wut,PARAM_LEN_WUT);
    SET_EVENT_MSG(pm_event_msg);
    EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);
    EMCU_DEBUG("msg adr =0x%x\n",PM_EVENT_MSG);
    EMCU_DEBUG("msg val =0x%x\n",rtd_inl(PM_EVENT_MSG));

}


/************************************************************************
 * FUNC: set wake up in timers function, minimum is minute
 * example:
 *  cat emcu_setup_wakeup_timer
 *  echo days,hours,mins > emcu_setup_wakeup_timer
 * Note: format days,hours,mins in DEC
 ************************************************************************/
static
ssize_t emcu_setup_wakeup_timer_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo days,hours,mins > /sys/devices/virtual/misc/emcu_kdv/emcu_setup_wakeup_timer\"\n"
        "        Noteice: days\"hours\"mins are DEC format\n");
}

static
ssize_t emcu_setup_wakeup_timer_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{

    int param_cnt;
    unsigned long long param[3];
    size_t ret = count;

    if(emcu_get_param_multi(10,3,&param_cnt,param,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(param_cnt != 3){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    powerMgr_setup_wakeup_timer(
        (unsigned int)param[0],
        (unsigned int)param[1],
        (unsigned int)param[2]);

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_setup_wakeup_timer, S_IRUGO | S_IWUSR,
        emcu_setup_wakeup_timer_dev_show,emcu_setup_wakeup_timer_dev_store);


/************************************************************************
 *
 ************************************************************************/
static
void powerMgr_setup_wakeup_timer1(int days, int hours, int mins, int sec)
{
    unsigned int pm_event_msg;
    unsigned int total_secs;

    if(hours > 23)
        hours = 23;

    if(mins > 59)
        mins = 59;

    if(sec > 60)
        sec = 60;

    total_secs = (days*24*60*60) + (hours *60*60) + (mins *60) + sec;

    EMCU_DEBUG("sleeping time is %ddays %dhours %dmins, %dsec\n",days,hours,mins, sec);
    EMCU_DEBUG("total sleeping time is %u sec\n",total_secs);

    SET_WUT_PARM(total_secs);

    EMCU_DEBUG("IDX_REG_WUT adr =0x%x\n", RTD_SHARE_MEM_BASE+4*IDX_REG_WUT);
    EMCU_DEBUG("IDX_REG_WUT val =0x%x\n", rtd_inl(RTD_SHARE_MEM_BASE+4*IDX_REG_WUT));

    // Read back from index register
    pm_event_msg = GET_EVENT_MSG();

    // set index for WUT to infor emcu using sec paramter
    SET_EVENT_IDX(pm_event_msg,loc_wut,0x2);

    // Write to Index register
    SET_EVENT_MSG(pm_event_msg);
    EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);
    EMCU_DEBUG("msg adr =0x%x\n",PM_EVENT_MSG);
    EMCU_DEBUG("msg val =0x%x\n",rtd_inl(PM_EVENT_MSG));
}


/************************************************************************
 * FUNC: set wake up in timers function, minimum is sec
 * example:
 *  cat emcu_setup_wakeup_timer1
 *  echo days,hours,mins,sec > emcu_setup_wakeup_timer1
 * Note: format days,hours,mins,sec  in DEC
 ************************************************************************/
static
ssize_t emcu_setup_wakeup_timer1_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo days,hours,mins,sec > /sys/devices/virtual/misc/emcu_kdv/emcu_setup_wakeup_timer1\"\n"
        "        Noteice: days\"hours\"mins\"sec are DEC format\n");
}

static
ssize_t emcu_setup_wakeup_timer1_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    int param_cnt;
    unsigned long long param[4];
    size_t ret = count;

    if(emcu_get_param_multi(10,4,&param_cnt,param,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(param_cnt != 4){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    powerMgr_setup_wakeup_timer1(
        (unsigned int)param[0],
        (unsigned int)param[1],
        (unsigned int)param[2],
        (unsigned int)param[3]);
FINISH_OUT:
    return ret;
}

DEVICE_ATTR(emcu_setup_wakeup_timer1, S_IRUGO | S_IWUSR,
        emcu_setup_wakeup_timer1_dev_show,emcu_setup_wakeup_timer1_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
void powerMgr_setup_wakeup_min( unsigned int reason,
                                unsigned int mins)
{
    unsigned int pm_event_msg;
    unsigned int s_reason;

    /* the argument reason is useless, It's fixed as '1' at min case. */
    s_reason = 1;

    EMCU_DEBUG("sleeping time is %u minute\n",mins);
    EMCU_DEBUG("sleeping reason is %u\n",s_reason);

    SET_WUT_PARM(mins);

    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_wut,s_reason);
    SET_EVENT_MSG(pm_event_msg);
    EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);
    EMCU_DEBUG("msg adr =0x%x\n",PM_EVENT_MSG);
    EMCU_DEBUG("msg val =0x%x\n",rtd_inl(PM_EVENT_MSG));
}


/************************************************************************
 * FUNC: set wake up in timers and reason function, minimum is min
 * example:
 *  cat emcu_setup_wakeup_min
 *  echo reason,mins > emcu_setup_wakeup_min
 * Note: format reason,mins  in DEC
 ************************************************************************/
static
ssize_t emcu_setup_wakeup_min_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo reason,mins > /sys/devices/virtual/misc/emcu_kdv/emcu_setup_wakeup_min\"\n"
        "        Noteice: reason\"mins are DEC format\n");
}

static
ssize_t emcu_setup_wakeup_min_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{

    int param_cnt;
    unsigned long long param[2];
    size_t ret = count;

    if(emcu_get_param_multi(10,2,&param_cnt,param,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(param_cnt != 2){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    powerMgr_setup_wakeup_min(
        (unsigned int)param[0],
        (unsigned int)param[1]);

FINISH_OUT:
    return ret;


}

DEVICE_ATTR(emcu_setup_wakeup_min, S_IRUGO | S_IWUSR,
        emcu_setup_wakeup_min_dev_show,emcu_setup_wakeup_min_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
void powerMgr_setup_wakeup_sec( unsigned int reason,
                                unsigned int sec)
{
    unsigned int pm_event_msg;
    unsigned int s_reason;

    /* the argument reason is useless, It's fixed as '2' at sec case. */
    s_reason = 2;

    EMCU_DEBUG("sleeping time is %u seconds\n",sec);
    EMCU_DEBUG("sleeping reason is %u\n",s_reason);

    SET_WUT_PARM_SEC(sec);

    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_wut_sec,s_reason);
    SET_EVENT_MSG(pm_event_msg);
    EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);
    EMCU_DEBUG("msg adr =0x%x\n",PM_EVENT_MSG);
    EMCU_DEBUG("msg val =0x%x\n",rtd_inl(PM_EVENT_MSG));
}


/************************************************************************
 * FUNC: set wake up in timers and reason function, minimum is sec
 * example:
 *  cat emcu_setup_wakeup_sec
 *  echo reason,mins > emcu_setup_wakeup_sec
 * Note: format reason,mins  in DEC
 ************************************************************************/
static
ssize_t emcu_setup_wakeup_sec_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo reason,sec > /sys/devices/virtual/misc/emcu_kdv/emcu_setup_wakeup_sec_\"\n"
        "        Noteice: reason\"sec are DEC format\n");
}

static
ssize_t emcu_setup_wakeup_sec_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{

    int param_cnt;
    unsigned long long param[2];
    size_t ret = count;

    if(emcu_get_param_multi(10,2,&param_cnt,param,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(param_cnt != 2){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    powerMgr_setup_wakeup_sec(
        (unsigned int)param[0],
        (unsigned int)param[1]);

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_setup_wakeup_sec, S_IRUGO | S_IWUSR,
        emcu_setup_wakeup_sec_dev_show,emcu_setup_wakeup_sec_dev_store);


/************************************************************************
 *
 ************************************************************************/
static
void powerMgr_setup_irda(unsigned int protocol ,
                         unsigned int key_num,
                         unsigned int * key_array )
{
    unsigned int i;
    unsigned int pm_event_msg;

    EMCU_DEBUG("IrDA Protocol is %u key_num:%u\n",protocol,key_num);

    /* initialize all data */
    for(i=0 ;i<PARAM_LEN_IRDA; i++){
        SET_IRDA_PARM(i,0);
    }

    if(!key_num)
        return;

    /* To set protocol */
    SET_IRDA_PARM(0,protocol);
    if(key_num > (PARAM_LEN_IRDA-1)){
        /*
         The PARAM_LEN_IRDA include procotol and lot of set of key codes,
         So, the number of irda key are (PARAM_LEN_IRDA-1)
         */
        key_num = (PARAM_LEN_IRDA-1);
    }

    /* To set physical key code */
    for(i=0 ;i<key_num; i++){
        EMCU_DEBUG("IR_KEY%u=0x%x\n",1+i,*(key_array+i));
        SET_IRDA_PARM(1+i,*(key_array+i));
    }

    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_irda,key_num);
    SET_EVENT_MSG(pm_event_msg);
    EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);
}

/************************************************************************
 *
 ************************************************************************/
#define MAX_IRKEY_NUM   (PARAM_LEN_IRDA-1)
#define MAX_IR_PARAM_CNT (MAX_IRKEY_NUM+2)

static
int powerMgr_irda_parser(const char *buf, size_t count,unsigned int ctl)
{
    int ret = 0;
    unsigned long long param[18];
    unsigned int ir_key[18];
    uint32_t user_key[18];
    int i;
    int param_cnt;
    const char* buf_pt;
    int  pmode;
    int  pmax_cnt;
    size_t cnt_tmp;

    /*
     Because the max number of irda is 15 before.
     The AP maybe send up to 15 set of irda key.
     So, to reserve 18 set for safety reason.
     */

    if(ctl == PARSE_USER){
        pmode = 16;
        buf_pt = buf;
        cnt_tmp = count;
        /* string format of user mode:
            "protocol,key_num,keycode1,keycode2,.. > emcu_setup_irda" */
        pmax_cnt = MAX_IRKEY_NUM+2;
    }else if(ctl == PARSE_IN_CASE){
        pmode = 16;
        buf_pt = buf;
        cnt_tmp = count;
        /* string format of key code mode:
            "key_num,keycode1,keycode2,.. > emcu_setup_irda_in_code" */
        pmax_cnt = MAX_IRKEY_NUM+1;
    }else if(ctl == PARSE_AUTO){
        if(!(emcu_test_ctl & EMCU_PARSE_EN)){
            EMCU_DEBUG("%s(%d)auto parser have not support\n",__func__,__LINE__);
            ret = -EINVAL;
            goto FINISH_OUT;
        }

        pmode = 0xff;
        buf_pt = EMCU_IRDA_PIN_NAME;
        cnt_tmp = sizeof(EMCU_IRDA_PIN_NAME);
        /* string format of auto mode:
            "3,PIN_IRDA_UKEY_0,PIN_IRDA_UKEY_1,PIN_IRDA_UKEY_2" */
        pmax_cnt = 4;

    }else{
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(emcu_get_param_multi(pmode,pmax_cnt,&param_cnt,param,buf_pt,cnt_tmp)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(ctl == PARSE_USER){
        if(param[1] != (param_cnt-2))
        {
            EMCU_DEBUG("param_cnt=%d param[0]=%lld\n",param_cnt,param[1]);
            EMCU_DEBUG("input mismatch\n");
            ret = -EINVAL;
            goto FINISH_OUT;
        }

        for(i=0;i<param[1];i++){
            ir_key[i] = (unsigned int)param[i+2];
        }
    }else if(ctl == PARSE_IN_CASE){
        if(param[0] != (param_cnt-1))
        {
            EMCU_DEBUG("param_cnt=%d param[0]=%lld\n",param_cnt,param[0]);
            EMCU_DEBUG("input mismatch\n");
            ret = -EINVAL;
            goto FINISH_OUT;
        }

        for(i=0;i<param[0];i++){
            user_key[i] = (uint32_t)param[i+1];
            EMCU_INFO("user keycode%d=0x%08x\n",i,user_key[i]);
        }
        param[1] = param[0];
        param[0] = 0;

    }else if(ctl == PARSE_AUTO){
#ifndef CONFIG_RTK_KDRV_INPUT_DEVICE
        EMCU_ALERT("irda keycode transfer function not ready\n");
        ret = -EINVAL;
        goto FINISH_OUT;
#else
        int j;

        if(param_cnt < 2){
            ret = -EINVAL;
            goto FINISH_OUT;
        }

        EMCU_DEBUG("pin cnt: %d \n",param_cnt-1);
        for(i=0;i<(param_cnt-1);i++){
            EMCU_DEBUG("pin%d: 0x%llx \n",i+1,param[i+1]);
            for(j=0;j<6;j++){
                user_key[(i*6)+j] = (param[i+1] >> (10*j))  & 0x3ff;
                EMCU_DEBUG("  ukey%d=0x%03x\n",(i*6)+j,user_key[(i*6)+j]);
            }

        }

        EMCU_DEBUG("===================================\n");
        param[0] = 0;
        param[1] = 0;
        for(i=0;i<18;i++){
            if(user_key[i] == 0){
                for(j=(i+1);j<18;j++){
                    if(user_key[j]){
                        user_key[i] = user_key[j];
                        user_key[j] = 0;
                        break;
                    }
                }
            }
            EMCU_DEBUG("  ukey%d=0x%03x\n",i,user_key[i]);
            if(user_key[i]){
                param[1]+=1;
                if(param[1] >= MAX_IRKEY_NUM)
                    break;
            }
        }
        EMCU_DEBUG("total ukey is %llu\n",param[1]);
#endif
    }else{
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(ctl != PARSE_USER){

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
        venus_ir_keylist_to_scanlist(user_key, ir_key, (uint32_t)param[1]);

        for(i=0;i<(param[1]);i++){
            EMCU_ALERT("irda keycode%d=0x%08x\n",i,ir_key[i]);
        }
#else
        EMCU_ALERT("irda keycode transfer function not ready\n");
        ret = -EINVAL;
        goto FINISH_OUT;
#endif
    }
    powerMgr_setup_irda(
            (unsigned int)param[0],(unsigned int)param[1],ir_key);

FINISH_OUT:
    return ret;
}


/************************************************************************
 * FUNC: set IRDA key to wakeup
 * example:
 *  cat emcu_setup_irda
 *  echo protocol,key_num,keycode1,keycode2,.. > emcu_setup_irda

 ************************************************************************/
static
ssize_t emcu_setup_irda_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo protocol,key_num,keycode1,keycode2,... > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_setup_irda\"\n");
}

static
ssize_t emcu_setup_irda_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    size_t ret = 0;

    if(emcu_test_ctl & EMCU_PARSE_EN){
        ret = powerMgr_irda_parser(buf,count,PARSE_AUTO);
    }else{
        ret = powerMgr_irda_parser(buf,count,PARSE_USER);
    }

    if(ret){
        ret = -EINVAL;
        goto FINISH_OUT;
    }else{
        ret = count;
        emcu_auto_event |= EMCU_IRDA_ALERT;
    }

FINISH_OUT:
    return ret;
}

DEVICE_ATTR(emcu_setup_irda, S_IRUGO | S_IWUSR,
        emcu_setup_irda_dev_show,emcu_setup_irda_dev_store);

/************************************************************************
 * FUNC: set IRDA key to wakeup, parameter in name
 * example:
 *  cat emcu_setup_irda_in_code
 *  echo key_num,keyName1,keyName2,.. > emcu_setup_irda_in_code

 ************************************************************************/
static
ssize_t emcu_setup_irda_in_code_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo key_num,keycode1,keycode2,... > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_setup_irda_in_code\"\n");
}


static
ssize_t emcu_setup_irda_in_code_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    size_t ret = 0;

    if(emcu_test_ctl & EMCU_PARSE_EN){
        ret = powerMgr_irda_parser(buf,count,PARSE_AUTO);
    }else{
        ret = powerMgr_irda_parser(buf,count,PARSE_IN_CASE);
    }

    if(ret){
        ret = -EINVAL;
        goto FINISH_OUT;
    }else{
        ret = count;
        emcu_auto_event |= EMCU_IRDA_ALERT;
    }

FINISH_OUT:
    return ret;
}

DEVICE_ATTR(emcu_setup_irda_in_code, S_IRUGO | S_IWUSR,
        emcu_setup_irda_in_code_dev_show,
        emcu_setup_irda_in_code_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
void powerMgr_setup_power_en(unsigned int pw_num,
                             unsigned long long * pw_array )
{
    unsigned int i;
    unsigned int pm_event_msg;
    unsigned int para_tmp;
    unsigned int valid_num;
    unsigned char kptype;

    EMCU_DEBUG("\n(%s)2012/05/09 15:55\n",__func__);
    EMCU_DEBUG("Power enable line have %u set.\n",pw_num);

    for(i=0 ;i<PARAM_LEN_PWEN; i++)
        SET_PWEN_PARM(i,0);

    if(pw_num>PARAM_LEN_PWEN)
        pw_num = PARAM_LEN_PWEN;

    valid_num = 0;
    for(i=0 ;i<pw_num; i++){
        EMCU_DEBUG("en_power para%u=0x%llx\n",i,*(pw_array+i));
        EMCU_DEBUG("GET_PIN_TYPE:%x\n",GET_PIN_TYPE(*(pw_array+i)));

        kptype = GET_PIN_TYPE(*(pw_array+i));
        if( (kptype == PCB_PIN_TYPE_ISO_GPIO) ||
            (kptype == PCB_PIN_TYPE_ISO_GPI) )
        {
            para_tmp = powerMgr_interpret_gpio_value(*(pw_array+i));
            if(para_tmp == 0xff)
                continue;
            SET_PWEN_PARM(valid_num,para_tmp);
            valid_num++;
        }
    }

    pm_event_msg = GET_EVENT_MSG();
    SET_EVENT_IDX(pm_event_msg,loc_pwen,valid_num);
    SET_EVENT_MSG(pm_event_msg);
    EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);
}

/************************************************************************
 * This func is going to provide pm.c to call.
 ************************************************************************/
int powerMgr_power_en_parser(const char *buf, size_t count,unsigned int ctl)
{
    int ret = 0;
    int param_cnt;
    unsigned long long param[4];
    char pin_buf[128] = {0};
    const char* buf_pt = NULL;
    int  pmode;
    size_t cnt_tmp;

    if(ctl == PARSE_USER){
        pmode = 16;
        buf_pt = buf;
        cnt_tmp = count;
    }else if(ctl == PARSE_IN_CASE){
        pmode = 0xff;
        buf_pt = buf;
        cnt_tmp = count;
    }else if(ctl == PARSE_AUTO){
        unsigned int pm_event_msg;

        if(!(emcu_test_ctl & EMCU_PARSE_EN)){
            ret = -EINVAL;
            goto FINISH_OUT;
        }

        /* To check if STM case */
        pmode = 0xff;
        pm_event_msg = GET_EVENT_MSG();
        if(pm_event_msg  & (0x03 << loc_stm)){
            sprintf(pin_buf, "2,%s\n",EMCU_POWER_PIN_NAME);
        }else{
            sprintf(pin_buf, "3,%s,%s\n",EMCU_POWER_PIN_NAME,EMCU_DDR_POWER_NAME);
        }

        buf_pt = pin_buf;
        cnt_tmp = strlen(pin_buf);

    }else{
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(emcu_get_param_multi(pmode,4,&param_cnt,param,buf_pt,cnt_tmp)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(ctl != PARSE_AUTO){
        /*
         * The number of parameter should same with parameter input over user.
         * It's to make sure parameter input correctly.
         */
        if(param[0] != (param_cnt-1))
        {
            EMCU_DEBUG("param_cnt=%d param[0]=%lld\n",param_cnt,param[0]);
            EMCU_DEBUG("input mismatch\n");
            ret = -EINVAL;
            goto FINISH_OUT;
        }
    }else{
        int i;
        /*
         * The number of parameter may small then max number,
         * because pab paremeter have not to define.
         */
        if(param_cnt < 2)
        {
            EMCU_DEBUG("param_cnt=%d param[0]=%lld\n",param_cnt,param[0]);
            EMCU_DEBUG("input mismatch\n");
            ret = -EINVAL;
            goto FINISH_OUT;
        }

        EMCU_DEBUG("pin cnt: %d \n",param_cnt-1);
        for(i=0;i<(param_cnt-1);i++){
            EMCU_DEBUG("pin%d: 0x%llx \n",i+1,param[i+1]);
        }
    }
    powerMgr_setup_power_en((unsigned int)(param_cnt-1),&param[1]);
    emcu_auto_event |= EMCU_POWER_EN_ALERT;

FINISH_OUT:
    return ret;
}

/************************************************************************
 * FUNC: set power pin information to EMCU
 * example:
 *  cat emcu_setup_power_en
 *  echo pw_num,pw_num,pw_num,.. > emcu_setup_power_en
 * note: max number of power pin are 3
 ************************************************************************/
static
ssize_t emcu_setup_power_en_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo pw_num,power_pin1,power_pin2,... > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_setup_power_en\"\n");
}

static
ssize_t emcu_setup_power_en_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    size_t ret = 0;

    if(emcu_test_ctl & EMCU_PARSE_EN){
        ret = powerMgr_power_en_parser(buf,count,PARSE_AUTO);
    }else{
        ret = powerMgr_power_en_parser(buf,count,PARSE_USER);
    }

    if(ret){
        ret = -EINVAL;
        goto FINISH_OUT;
    }else{
        ret = count;
    }

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_setup_power_en, S_IRUGO | S_IWUSR,
        emcu_setup_power_en_dev_show,emcu_setup_power_en_dev_store);


/************************************************************************
 * FUNC: set power pin information in name to EMCU
 * example:
 *  cat setup_power_en_in_name
 *  echo pw_num,pw_name1,pw_name1,.. > setup_power_en_in_name
 * note: max number of power pin are 3,
    To get pcb param by cmd below
    ex. ls /sys/realtek_boards/pcb_enum
 ************************************************************************/
static
ssize_t emcu_setup_power_en_in_name_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo pw_num,pw_name1,pw_name2,... > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_setup_power_en\"\n");
}

static
ssize_t emcu_setup_power_en_in_name_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    size_t ret = 0;

    if(emcu_test_ctl & EMCU_PARSE_EN){
        ret = powerMgr_power_en_parser(buf,count,PARSE_AUTO);
    }else{
        ret = powerMgr_power_en_parser(buf,count,PARSE_IN_CASE);
    }

    if(ret){
        ret = -EINVAL;
        goto FINISH_OUT;
    }else{
        ret = count;
        emcu_auto_event |= EMCU_POWER_EN_ALERT;
    }

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_setup_power_en_in_name, S_IRUGO | S_IWUSR,
        emcu_setup_power_en_in_name_dev_show,
        emcu_setup_power_en_in_name_dev_store);

/************************************************************************
 * FUNC: get how long sleep from emcu
 * example:
 *  cat emcu_get_sleep_dur
 *
 ************************************************************************/
static
ssize_t emcu_get_sleep_dur_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    unsigned int dur_h;
    unsigned int dur_l;
    unsigned int dur_ary[3];

    dur_h = dur_l = 0;
        GET_TIME_DUR(dur_h,dur_l);

    dur_ary[0] = dur_l;                    //min
    dur_ary[1] = (dur_h >> 24) & 0xff;     //sec
    dur_ary[2] = dur_h & 0xffffff;         //ms
    EMCU_INFO("\nsleep duration: %umin %usec %ums\n",
        dur_ary[0],dur_ary[1],dur_ary[2]);

    return sprintf(buf, "%u,%u,%u\n",dur_ary[0],dur_ary[1],dur_ary[2]);
}

static
ssize_t emcu_get_sleep_dur_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    EMCU_INFO("\n(%s)no operation!\n",__func__);

    return count;
}

DEVICE_ATTR(emcu_get_sleep_dur, S_IRUGO | S_IWUSR,
        emcu_get_sleep_dur_dev_show,emcu_get_sleep_dur_dev_store);

/************************************************************************
 * FUNC: get wake up source  from emcu
 * example:
 *  cat emcu_get_wakeup_source
 ************************************************************************/
int powerMgr_get_wakeup_source(unsigned int* row, unsigned int* status)
{
    int res = 0;
    unsigned int tmp1 = 0;
    unsigned int tmp2 = 0;
    const char* str[]={"UNDEF","KEYPAD","WUT","IRDA","CEC","PPS","WOW","HML","RTC","WOV"};
    WAKE_UP_T reason;

    if((row == NULL ) && (status == NULL))
        return -ENOMEM;

    tmp1 = GET_WK_SOR();
    tmp2 = GET_WK_STS();
    if(row)
        *row = tmp1;
    if(status)
        *status = tmp2;

    reason = (WAKE_UP_T)(tmp1 & 0xff);
    if((reason) >= WKSOR_END){
        res = -EINVAL;
        goto ERR_OUT;
    }

    EMCU_INFO("\n%s(%d)wakeup source:%s; row:0x%08x; status:0x%08x\n",
        __func__,__LINE__,str[reason],tmp1,tmp2);

ERR_OUT:
    return res;
}

static
ssize_t emcu_get_wakeup_source_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    unsigned int ir_key = 0;
    unsigned int wk_source = 0;

    powerMgr_get_wakeup_source(&wk_source,&ir_key);

    return sprintf(buf, "0x%x\n",wk_source);
}

static
ssize_t emcu_get_wakeup_source_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{

    EMCU_INFO("\n(%s)no operation!\n",__func__);
    return count;
}

DEVICE_ATTR(emcu_get_wakeup_source, S_IRUGO | S_IWUSR,
        emcu_get_wakeup_source_dev_show,emcu_get_wakeup_source_dev_store);

/************************************************************************
 * FUNC: get wake up status
 * example:
 *  cat emcu_get_wakeup_status
 ************************************************************************/
static
ssize_t emcu_get_wakeup_status_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    unsigned int wk_status;

    wk_status = GET_WK_STS();
    EMCU_INFO("%s(%u)wakeup status = 0x%x\n", __func__, __LINE__,wk_status);
    return sprintf(buf, "0x%x\n",wk_status);
}

static
ssize_t emcu_get_wakeup_status_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    EMCU_INFO("\n(%s)no operation!\n",__func__);
    return count;
}

DEVICE_ATTR(emcu_get_wakeup_status, S_IRUGO | S_IWUSR,
        emcu_get_wakeup_status_dev_show,emcu_get_wakeup_status_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
void powerMgr_set_cur_time(int hours,int mins,int sec)
{
    unsigned int cur_time;

    if(hours > 23)
        hours = 23;
    if(mins > 59)
        mins = 59;
    if(sec > 59)
        sec = 59;
    cur_time = (hours<<24)|(mins<<16)|(sec<<8);
    SET_CUR_TIME(cur_time);

    EMCU_DEBUG("\nrecord current time : %dhour, %dmin, %dsec\n",
        hours,mins,sec);

}

/************************************************************************
 * FUNC: set current time to emcu
 * example:
 *  cat emcu_set_cur_time
 *  echo  hours,mins,sec > emcu_set_cur_time
 ************************************************************************/
static
ssize_t emcu_set_cur_time_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo  hours,mins,sec > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_set_cur_time\"\n"
        "        Noteice: \"hours,mins,sec\" are DEC format\n");
}

static
ssize_t emcu_set_cur_time_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    int param_cnt;
    unsigned long long param[3];
    size_t ret = count;

    if(emcu_get_param_multi(10,3,&param_cnt,param,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }
    if(param_cnt != 3){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    powerMgr_set_cur_time((int)param[0],(int)param[1],(int)param[2]);

FINISH_OUT:
    return ret;
}

DEVICE_ATTR(emcu_set_cur_time, S_IRUGO | S_IWUSR,
        emcu_set_cur_time_dev_show,emcu_set_cur_time_dev_store);

/************************************************************************
 * FUNC: get recorded time from emcu
 * example:
 *  cat emcu_get_rec_time
 *
 ************************************************************************/
static
ssize_t emcu_get_rec_time_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    unsigned int cur_time;

    cur_time = GET_CUR_TIME();
    cur_time = (cur_time>>8);

    EMCU_INFO("\nrecorded time : %uhour, %umin, %usec\n",
        (cur_time>>16)& 0xff,
        (cur_time>> 8)& 0xff,
        (cur_time>> 0)& 0xff);

    return sprintf(buf, "%x\n",cur_time);
}

static
ssize_t emcu_get_rec_time_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    EMCU_INFO("\n(%s)no operation!\n",__func__);
    return count;
}

DEVICE_ATTR(emcu_get_rec_time, S_IRUGO | S_IWUSR,
        emcu_get_rec_time_dev_show,emcu_get_rec_time_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
void powerMgr_set_sharemem(unsigned char addr,unsigned int value)
{
    if(addr>31){
        EMCU_DEBUG("The address is to much.\n");
    }else{
        rtd_outl(RTD_SHARE_MEM_BASE+(4*addr),value);

        EMCU_DEBUG("\nthe share_memory %u = 0x%08x",
            addr,rtd_inl(RTD_SHARE_MEM_BASE+4*addr));
    }
}

/************************************************************************
 * FUNC: set expect value to certent share_mem
 * example:
 *  cat emcu_set_sharemem
 *  echo addr,value > emcu_set_sharemem
 *
 ************************************************************************/
static
ssize_t emcu_set_sharemem_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo  addr,value > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_set_sharemem\"\n");
}

static
ssize_t emcu_set_sharemem_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    int param_cnt;
    unsigned long long param[2];
    size_t ret = count;

    if(emcu_get_param_multi(16,2,&param_cnt,param,buf,count)){
        EMCU_INFO("\n(%s)get param fail\n",__func__);
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(param_cnt != 2){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    powerMgr_set_sharemem((unsigned char)param[0],(unsigned int)param[1]);

FINISH_OUT:
    return ret;
}

DEVICE_ATTR(emcu_set_sharemem, S_IRUGO | S_IWUSR,
        emcu_set_sharemem_dev_show,emcu_set_sharemem_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
int powerMgr_set_sharemem_mask(
    unsigned char addr,unsigned int mask,unsigned int value)
{
    int ret = 0;
    if(addr>31){
        EMCU_DEBUG("The address is to much.\n");
        ret = -EINVAL;;
    }else{
        unsigned int reginfo;

        reginfo = rtd_inl(RTD_SHARE_MEM_BASE+(4*addr));
        reginfo = ((reginfo & mask)|(value & ~mask));
        rtd_outl(RTD_SHARE_MEM_BASE+(4*addr),reginfo);

        EMCU_DEBUG("\nthe share_memory %u = 0x%08x",
            addr,rtd_inl(RTD_SHARE_MEM_BASE+4*addr));
    }
    return ret;
}

/************************************************************************
 * FUNC: set expect value to certent share_mem with mask
 * example:
 *  cat emcu_set_sharemem_mask
 *  echo addr,mask,value > emcu_set_sharemem_mask
 *
 ************************************************************************/
static
ssize_t emcu_set_sharemem_mask_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo  addr,mask,value > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_set_sharemem_mask\"\n");
}

static
ssize_t emcu_set_sharemem_mask_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    int param_cnt;
    unsigned long long param[3];
    size_t ret = 0;

    if(emcu_get_param_multi(16,3,&param_cnt,param,buf,count)){
        EMCU_INFO("\n(%s)get param fail\n",__func__);
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(param_cnt != 3){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    ret = powerMgr_set_sharemem_mask(
                (unsigned char)param[0],
                (unsigned int) param[1],
                (unsigned int) param[2]);

    if(ret == 0)
        ret = count;

FINISH_OUT:
    return ret;
}

DEVICE_ATTR(emcu_set_sharemem_mask, S_IRUGO | S_IWUSR,
        emcu_set_sharemem_mask_dev_show,emcu_set_sharemem_mask_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
int powerMgr_set_STM(unsigned int value)
{
    unsigned int pm_event_msg;
    unsigned int stm_tmp;

    if(value >3){
        EMCU_DEBUG("\nparameter big then 3. Ignore setting.\n");
        return -1;
    }else{
        pm_event_msg = GET_EVENT_MSG();
        stm_tmp = (((pm_event_msg >> loc_stm) &0xf) & (~0x03));
        SET_EVENT_IDX(pm_event_msg,loc_stm,(value|stm_tmp));
        SET_EVENT_MSG(pm_event_msg);
        EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);

        /*
         To make sure power pin of DDR has been remove form share mem.
         Call power_en related func here.
         */
        if(!(emcu_auto_event & EMCU_POWER_EN_ALERT)){
            if(powerMgr_power_en_parser(NULL,0,PARSE_AUTO)){
                EMCU_WARNING("%s(%d)power_en auto parse fail!\n",__func__,__LINE__);
            }
        }

        return 0;
    }
}

/************************************************************************
 * FUNC: enable suspend to RAM
 * example:
 *  cat emcu_set_STM
 *  echo 1 > emcu_set_STM
 ************************************************************************/
static
ssize_t emcu_set_STM_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo  smt_val > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_set_STM\"\n"
        "        notice: smt_val is \"1\" now\n");
}

static
ssize_t emcu_set_STM_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    unsigned long long in_val;
    size_t ret = count;

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(powerMgr_set_STM((unsigned int)in_val)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_set_STM, S_IRUGO | S_IWUSR,
        emcu_set_STM_dev_show,emcu_set_STM_dev_store);


/************************************************************************
 *
 ************************************************************************/
static
void powerMgr_set_RTC(void)
{
    unsigned int pm_event_msg;
    unsigned int stm_tmp;

    pm_event_msg = GET_EVENT_MSG();
    stm_tmp = (((pm_event_msg >> loc_rtc) &0xf) | 0x4); //use bit2, index bit30
    SET_EVENT_IDX(pm_event_msg,loc_rtc,stm_tmp);
    SET_EVENT_MSG(pm_event_msg);
    EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);

}

/************************************************************************
 * FUNC: enable RTC wake up
 * example:
 *  cat emcu_set_RTC
 *  echo 1 > emcu_set_RTC
 ************************************************************************/
static
ssize_t emcu_set_RTC_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo 1 > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_set_RTC\"\n");
}

static
ssize_t emcu_set_RTC_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    unsigned long long in_val;
    size_t ret = count;

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }

    if(in_val > 1){
        ret = -EINVAL;
        goto FINISH_OUT;
    }
    powerMgr_set_RTC();

FINISH_OUT:
    return count;

}

DEVICE_ATTR(emcu_set_RTC, S_IRUGO | S_IWUSR,
        emcu_set_RTC_dev_show,emcu_set_RTC_dev_store);


/************************************************************************
 *
 ************************************************************************/
/* #define INTERNAL_WOW_SUPPORT */
#ifdef INTERNAL_WOW_SUPPORT
static
void powerMgr_set_WOW(unsigned int value,
                      unsigned char *ptr_sip,
                      unsigned char *ptr_hip,
                      unsigned char *ptr_smac,
                      unsigned char *ptr_hmac)
{
    unsigned int pm_event_msg;

    EMCU_DEBUG("value=%x\n",value);
    EMCU_DEBUG("server IP : %02x:%02x:%02x:%02x (%u:%u:%u:%u)\n",
        *(ptr_sip+0),*(ptr_sip+1),*(ptr_sip+2),*(ptr_sip+3),
        *(ptr_sip+0),*(ptr_sip+1),*(ptr_sip+2),*(ptr_sip+3));
    EMCU_DEBUG("host   IP : %02x:%02x:%02x:%02x (%u:%u:%u:%u)\n",
        *(ptr_hip+0),*(ptr_hip+1),*(ptr_hip+2),*(ptr_hip+3),
        *(ptr_hip+0),*(ptr_hip+1),*(ptr_hip+2),*(ptr_hip+3));
    EMCU_DEBUG("server MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
        *(ptr_smac+0),*(ptr_smac+1),*(ptr_smac+2),
        *(ptr_smac+3),*(ptr_smac+4),*(ptr_smac+5));
    EMCU_DEBUG("host   MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
        *(ptr_hmac+0),*(ptr_hmac+1),*(ptr_hmac+2),
        *(ptr_hmac+3),*(ptr_hmac+4),*(ptr_hmac+5));

    if(value >1){
        EMCU_DEBUG("\nparameter big then 1. Ignore setting.\n");
    }
    else{
        SET_SVER_IP(ptr_sip);
        SET_SVER_MAC(ptr_smac);
        SET_HOST_IP(ptr_hip);
        SET_HOST_MAC(ptr_hmac);

        pm_event_msg = GET_EVENT_MSG();
        pm_event_msg |= ((unsigned int)0x1 << loc_wow); // bit0:WOW enable
        SET_EVENT_MSG(pm_event_msg);

        EMCU_DEBUG("pm_event_msg=0x%x\n",pm_event_msg);
    }
}

/************************************************************************
 * FUNC: set WOW parameter
 * example:
 *  cat emcu_set_WOW
 *  echo value,sip,hip,smac,hmac > emcu_set_WOW
 *      echo 4,168.32.1.12,172.55.20.5,33:44:55:66:77:88,12:34:56:78:aa:bb > /sys/devices/virtual/misc/emcu_kdv/emcu_set_WOW
 *
 ************************************************************************/
static
ssize_t emcu_set_WOW_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo  value,sip,hip,smac,hmac > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_set_WOW\"\n"
        "        notice: sip/hip in format \"xxx.xxx.xxx.xxx\"\n"
        "                smac/hmac in format \"xx:xx:xx:xx:xx:xx\"\n\n"
        "example  \"echo 4,168.32.1.12,172.55.20.5,33:44:55:66:77:88,12:34:56:78:aa:bb > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_set_WOW\"\n");
}

static
ssize_t emcu_set_WOW_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    int i,j;
    int len;
    char *opt = NULL;
    char *buftmp;
    char *buforg;
    char *IP_buf;
    char *ip_buf;
    unsigned long long tmp_long;
    unsigned long long param[1];
    unsigned char ip_tmp[4][6];
    size_t ret = count;

    buforg = buftmp = kmalloc(count, GFP_KERNEL);
    ip_buf = kmalloc(64, GFP_KERNEL);
    if(!buftmp || !ip_buf){
        EMCU_DEBUG( "buftmp is NULL\n");
        ret = -EINVAL;
        goto FINISH_OUT;
    }
    memset(buftmp,0,count);
    strcpy(buftmp, buf);

    i = 0;
    while ((opt = strsep(&buftmp, ",")) != NULL) {
        len = strlen(opt);
        if(i){
            unsigned int base;
            unsigned int max_cnt;
            char *delim;
            if((i==1) || (i==2)){
                base = 10;
                max_cnt = 4;
                delim =  ".";
            }else{
                base = 16;
                max_cnt = 6;
                delim =  ":";
            }

            j = 0;
            memset(ip_buf,0,64);
            IP_buf = ip_buf;
            strcpy(ip_buf, opt);
            while ((opt = strsep(&IP_buf, delim)) != NULL) {
                if (kstrtoull(opt, base, &tmp_long)){
                    EMCU_DEBUG("get param fail 1\n");
                    ret = -EINVAL;
                    goto FINISH_OUT;
                }else{
                    ip_tmp[i-1][j] = (unsigned char)tmp_long;
                }
                j++;
            }
            if(j != max_cnt){
                EMCU_DEBUG("get param fail 2\n");
                ret = -EINVAL;
                goto FINISH_OUT;
            }
#if 0
            if(max_cnt == 4)
                EMCU_INFO("IP[%d]: %u.%u.%u.%u\n",
                    i,ip_tmp[i-1][0],ip_tmp[i-1][1],ip_tmp[i-1][2],ip_tmp[i-1][3]);
            else
                EMCU_INFO("MAC[%d]: %x:%x:%x:%x:%x:%x\n",
                    i,
                    ip_tmp[i-1][0],ip_tmp[i-1][1],ip_tmp[i-1][2],
                    ip_tmp[i-1][3],ip_tmp[i-1][4],ip_tmp[i-1][5]);
#endif
        }else{
            if (kstrtoull(opt, 16, &tmp_long)){
                EMCU_DEBUG("get param fail 3\n");
                ret = -EINVAL;
                goto FINISH_OUT;
            }else{
                param[i] = tmp_long;
            }
            EMCU_INFO("param[%d]=0x%llx\n",i,param[i]);
        }
        i++;
    }

    if(i != 5){
        EMCU_DEBUG("param count mismatch\n");
        ret = -EINVAL;
        goto FINISH_OUT;
    }
    powerMgr_set_WOW(param[0],
            (unsigned char*)&ip_tmp[0],
            (unsigned char*)&ip_tmp[1],
            (unsigned char*)&ip_tmp[2],
            (unsigned char*)&ip_tmp[3]);

FINISH_OUT:
    if(buforg)
        kfree(buforg);
    if(ip_buf)
        kfree(ip_buf);

    return ret;
}

DEVICE_ATTR(emcu_set_WOW, S_IRUGO | S_IWUSR,
        emcu_set_WOW_dev_show,emcu_set_WOW_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
ssize_t emcu_set_WOW_chksum_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "please key in \"echo  chksum > "
        "/sys/devices/virtual/misc/emcu_kdv/emcu_set_WOW_chksum\"\n");
}

static
ssize_t emcu_set_WOW_chksum_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    unsigned long long in_val;
    size_t ret = count;

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }
    SET_WOW_CHKSUM((unsigned int)in_val);

FINISH_OUT:
    return ret;

}

DEVICE_ATTR(emcu_set_WOW_chksum, S_IRUGO | S_IWUSR,
        emcu_set_WOW_chksum_dev_show,emcu_set_WOW_chksum_dev_store);
#endif  //#ifdef INTERNAL_WOW_SUPPORT

/************************************************************************
 *
 ************************************************************************/
static
ssize_t emcu_show_version_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf, "EMCU Libs 2017/03/06 21:40\n");
}


static
ssize_t emcu_show_version_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    return count;
}

DEVICE_ATTR(emcu_show_version, S_IRUGO | S_IWUSR,
        emcu_show_version_dev_show,emcu_show_version_dev_store);

/************************************************************************
 *
 ************************************************************************/
static
int emcu_chk_gpix(unsigned int pcb_info,unsigned int pin_cnt)
{
    unsigned int tmp1,tmp2,tmp3,tmp4,tmp5;

    tmp1 = (pcb_info>>20) & 0xf;
    tmp2 = (pcb_info>>16) & 0xf;
    tmp3 = (pcb_info>>8)  & 0xff;
    tmp4 = (pcb_info>>0)  & 0xff;
    tmp5 = (pcb_info>>24) & 0xff;
    if((tmp1 == 4)||(tmp1 == 0xd)){
        EMCU_ALERT("pin%d: %s%d; default level:%s; special index:0x%x \n",
        pin_cnt,
        (tmp1 == 4)?"iso_gpio":"iso_gpi",
        (tmp4 == 4)?(32+tmp3):tmp3,
        (tmp2)?"high":"low",tmp5);
    }else if(tmp1 == 1){
        EMCU_ALERT("key%d: LSADC set%d; HITVALUE:0x%x; TOLERANCE:0x%x \n",
        pin_cnt,tmp2,tmp3,tmp4);
    }else{
        EMCU_ALERT("pin type[%d] unsupport!\n",tmp1);
    }
    return 0;
}


/************************************************************************
 *
 ************************************************************************/
static
void emcu_show_sharemem(void)
{
    int i;
    unsigned int share_tmp[32];

    for(i=0;i<RTD_SHARE_MEM_LEN;i++){
        share_tmp[i] = rtd_inl(RTD_SHARE_MEM_BASE+(4*i));
        EMCU_INFO("mem[%02d]=0x%08x\n",i,share_tmp[i]);
    }
}

/************************************************************************
 *
 ************************************************************************/
#define ENCU_CHK_DEBUG
int emcu_chk_event(void)
{
    int i;
    unsigned int pm_event_msg;
    unsigned int tmp1,tmp2,tmp3;

    EMCU_ALERT("\nCheck setting that suspend need!!!!\n");

    emcu_show_sharemem();

    pm_event_msg = GET_EVENT_MSG();

    /* To check power pin */
    tmp1 = (pm_event_msg >> loc_pwen) & 0xf;
    if(tmp1){
        EMCU_ALERT("Total Power pin count are %u\n",tmp1);
        for(i=0; i< tmp1; i++){
            tmp2 = GET_PWEN_PARM(i);
            emcu_chk_gpix(tmp2,i+1);
        }

    }else{
        EMCU_ALERT("Warning!!! No Power pin for sleeping assigned!\n");
    }

    /* To check IRDA setting */
    tmp1 = (pm_event_msg >> loc_irda) & 0xf;
    if(tmp1){
        EMCU_ALERT("Total IRDA key used for wakeup are %u sets.\n",tmp1);
        tmp2 = GET_IRDA_PARM(0);
        EMCU_ALERT("irda protocol is %u\n",tmp2);
        for(i=1; i< tmp1; i++){
            tmp3 = GET_IRDA_PARM(i);
            EMCU_ALERT("Irda key%d:0x%08x\n",i,tmp3);
        }

    }else{
        EMCU_ALERT("Warning!!! No IRDA key for wakeup assigned!\n");
    }

    /* To check KeyPad setting */
    tmp1 = (pm_event_msg >> loc_keypad) & 0xf;
    if(tmp1){
        EMCU_ALERT("Total Keypad used for wakeup are %u sets.\n",tmp1);
        for(i=0; i< tmp1; i++){
            if(emcu_auto_event & EMCU_WOWLAN_ALERT){
                if((i+1) == tmp1)
                    EMCU_ALERT("Wake on wide Lan no re-key alert.\n");
            }
            tmp2 = GET_KEYPAD_PARM(i);
            emcu_chk_gpix(tmp2,i+1);
        }
    }else{
        EMCU_ALERT("Warning!!! No Keypad pin for wakeup assigned!\n");
    }

    /* To check CEC setting */
    tmp1 = (pm_event_msg >> loc_cec) & 0xf;
    EMCU_ALERT("There are %sCEC function for wake up.[event=%u] \n",(tmp1)?"":"no ",tmp1);

    /* To check PPS setting */
    tmp1 = (pm_event_msg >> loc_pps) & 0xf;
    tmp2 = GET_PPS_PARM();
    EMCU_ALERT("There are %spervious power source  function for wake up.[event=%u] \n",(tmp1)?"":"no ",tmp2);

    /* To check WUT setting */
    tmp1 = (pm_event_msg >> loc_wut) & 0xf;
    if(tmp1 & (tmp1<2)){
        tmp2 = GET_WUT_PARM();
        EMCU_ALERT("Timer wake up after %u %s.\n",tmp2,(tmp1==1)?"min":"sec");
    }else{
        EMCU_ALERT("There are no timer function for wake up.\n");
    }

    /* To check WOL and WOWLAN[re-key] */
    tmp1 = (pm_event_msg >> loc_wow) & 0xf;
    if(tmp1 & BIT(0)){
        EMCU_ALERT("Wake on LAN function alert.\n");

        tmp2 = GET_WIFI_DG_PARM();
        tmp3 = ((tmp2>>24) & 0xff);
        if(tmp3 == IDX_REKEY){
            EMCU_ALERT("Wake on Wide LAN re-key function enable.\n");
            emcu_chk_gpix(tmp2,1);
        }
    }else{
        EMCU_ALERT("There are no \"Wake on LAN\" or \"Wake on Wide LAN re-key\".\n");
    }

    /* To check MHL */
    EMCU_ALERT("There are %sMHL function for wake up.\n",(tmp1 & BIT(1))?"":"no ");

    /* To check STR */
    tmp1 = (pm_event_msg >> loc_stm) & 0xf;
    EMCU_ALERT("There are %sSTR function for wake up.[event=%u]\n",(tmp1 & 0x03)?"":"no ",tmp1&0x03);

    /* To check RTC */
    EMCU_ALERT("There are %sRTC function for wake up.\n",(tmp1 & 0x04)?"":"no ");

    return 0;
}


/************************************************************************
 *
 ************************************************************************/
static
ssize_t emcu_show_help_dev_show(struct device *dev,
    struct device_attribute *attr,
    char *buf)
{
    return sprintf(buf,
        "\n"
        "All Command List:\n"
        "=========================================================================\n"
        " @ emcu_show_share_mem : display all share memory value.\n"
        " @ emcu_set_sharemem   : Fill data to certian share memory.\n"
        " @ emcu_set_sharemem_mask   : Fill data to certian share memory with mask.\n"
        " @ emcu_clr_share_mem  : claer all share memory immediately.\n"
        " @ emcu_clr_pm_task    : clear assigned operation, not clear all share memory.\n"
        " @ emcu_set_STM        : enable suspend to RAM.\n"
        " @ emcu_set_RTC        : enable RTC wakeup function.\n"
        " @ emcu_set_WOWLAN     : enable weke on wide LAN func.\n"
        " @ emcu_setup_cec      : enable and setting keypad parameter.\n"
        " @ emcu_setup_mhl      : enable mhl func.\n"
        " @ emcu_setup_uart     : enable uart func.\n"
        " @ emcu_setup_ppsource : enable pervious power on source.\n"
        " @ emcu_setup_irda     : set IRDA key to wakeup.\n"
        " @ emcu_setup_power_en : set power pin information to EMCU.\n"
        " @ emcu_set_cur_time   : set current time to emcu.\n"
        " @ emcu_get_rec_time   : get recorded time from emcu.\n"
        " @ emcu_get_sleep_dur  : get how long sleeping from emcu.\n"
        " @ emcu_setup_keypad_multi  : enable and setting keypad parameter.\n"
        " @ emcu_setup_wakeup_timer  : set wake up timers, minimum is minute.\n"
        " @ emcu_setup_wakeup_timer1 : set wake up timers, minimum is sec.\n"
        " @ emcu_setup_wakeup_min    : set wake up timers and reason, minimum is min.\n"
        " @ emcu_setup_wakeup_sec    : set wake up timers and reason, minimum is sec.\n"
        " @ emcu_get_wakeup_source   : get wake up source from emcu.\n"
        " @ emcu_get_wakeup_status   : get wake up status.\n"
        "=========================================================================\n"
        "\n");
}

static
ssize_t emcu_show_help_dev_store(struct device *dev,
    struct device_attribute *attr,
    const char *buf, size_t count)
{
    unsigned long long in_val;
    size_t ret = count;

    if(emcu_get_param_single(16,&in_val,buf,count)){
        ret = -EINVAL;
        goto FINISH_OUT;
    }
    if(in_val == 1){
        EMCU_ALERT("\n"
            "User guide of emcu device attribute cmd.\n");
        EMCU_ALERT("\n"
            " @ emcu_show_share_mem: Display all share memory value.\n"
            "    example:\n"
            "        echo 1 > emcu_show_share_mem\n");
        EMCU_ALERT("\n"
            " @ emcu_set_sharemem: Fill data to certian share memory.\n"
            "    example:\n"
            "       echo [addr],[value] > emcu_set_sharemem\n");
        EMCU_ALERT("\n"
            " @ emcu_set_sharemem_mask: Fill data to certian share memory with mask.\n"
            "    example:\n"
            "       echo [addr],[mask],[value] > emcu_set_sharemem_mask\n");
        EMCU_ALERT("\n"
            " @ emcu_clr_share_mem: claer all share memory immediately.\n"
            "    example:\n"
            "        echo 1 > emcu_clr_share_mem\n");
        EMCU_ALERT("\n"
            " @ emcu_clr_pm_task: clear assigned operation, not clear all share memory.\n"
            "    example:\n"
            "        echo [param] > emcu_clr_pm_task\n");
        EMCU_ALERT("\n"
            " @ emcu_set_STM: enable suspend to RAM.\n"
            "    example:\n"
            "       echo 1 > emcu_set_STM\n");
        EMCU_ALERT("\n"
            " @ emcu_set_WOWLAN:  enable weke on wide LAN func.\n"
            "    example:\n"
            "        echo 1 > emcu_set_WOWLAN\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_cec: enable and setting keypad parameter.\n"
            "    example:\n"
            "        echo 1 > emcu_setup_cec\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_mhl: enable mhl func.\n"
            "    example:\n"
            "        echo 1 > emcu_setup_mhl\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_uart: enable uart func.\n"
            "    example:\n"
            "        echo 1 > emcu_setup_uart\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_ppsource: enable pervious power on source func.\n"
            "    example:\n"
            "        echo [param] > emcu_setup_uart\n"
            "    note: support VGA1 only, please to set param=3\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_irda: set IRDA key to wakeup.\n"
            "    example:\n"
            "        echo [protocol],[key_num],[keycode1],[keycode2],.. > emcu_setup_irda\n"
            "    note: The max number of key is 15.\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_power_en: set power pin information to EMCU.\n"
            "    example:\n"
            "       echo [pw_num],[pin1],[pin2],.. > emcu_setup_power_en\n"
            "    note: The max number of power pin is 3.\n");
        EMCU_ALERT("\n"
            " @ emcu_set_cur_time: set current time to emcu.\n"
            "    example:\n"
            "       echo  [hours],[mins],[sec] > emcu_set_cur_time\n"
            "    note: The format of \"hours,mins,sec\" are DEC\n");
        EMCU_ALERT("\n"
            " @ emcu_get_rec_time: get recorded time from emcu.\n"
            "    example:\n"
            "       cat emcu_get_rec_time\n");
        EMCU_ALERT("\n"
            " @ emcu_get_sleep_dur: get how long sleeping from emcu.\n"
            "    example:\n"
            "       cat emcu_get_sleep_dur\n"
            "    note: the report format is \"min,sec,ms\"\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_keypad_multi: enable and setting keypad parameter.\n"
            "    example:\n"
            "        echo [key_num],[param1],[param2],...,... > "
            "/sys/devices/virtual/misc/emcu_kdv/emcu_setup_keypad_multi\n"
            "    note: the max number of keypad are 10\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_wakeup_timer: set wake up timers, minimum is minute.\n"
            "    example:\n"
            "        echo [days],[hours],[mins] > emcu_setup_wakeup_timer\n"
            "    note: The format of \"days,hours,mins\" are DEC\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_wakeup_timer1: set wake up timers, minimum is sec.\n"
            "    example:\n"
            "        echo [days],[hours],[mins],[sec] > emcu_setup_wakeup_timer1\n"
            "    note: The format of \"days,hours,mins,sec\" are DEC\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_wakeup_min: set wake up timers and reason, minimum is min.\n"
            "    example:\n"
            "        echo [reason],[mins] > emcu_setup_wakeup_min\n"
            "    note: The format of \"reason,mins\" are DEC\n");
        EMCU_ALERT("\n"
            " @ emcu_setup_wakeup_sec: set wake up timers and reason, minimum is sec.\n"
            "    example:\n"
            "        echo [reason],[mins] > emcu_setup_wakeup_sec\n"
            "    note: The format of \"reason,sec\" are DEC\n");
        EMCU_ALERT("\n"
            " @ emcu_get_wakeup_source: get wake up source from emcu.\n"
            "    example:\n"
            "       cat emcu_get_wakeup_source\n"
            "    note: The meaning of report data is below.\n"
            "       str[][7]={\"UNDEF\",\"KEYPAD\",\"WUT\",\"IRDA\",\"CEC\",\"PPS\"} \n");
        EMCU_ALERT("\n"
            " @ emcu_get_wakeup_status:  get wake up status.\n"
            "    example:\n"
            "       cat emcu_get_wakeup_status\n");
        EMCU_ALERT("\n\n");
    }
FINISH_OUT:
    return ret;
}

DEVICE_ATTR(emcu_show_help, S_IRUGO | S_IWUSR,
        emcu_show_help_dev_show,emcu_show_help_dev_store);

/*-----------------------------------------------------------------------------------
 * File Operations
 *------------------------------------------------------------------------------------*/
/************************************************************************
 *
 ************************************************************************/
int rtk_emcu_open(struct inode *inode, struct file *file)
{
    EMCU_INFO("%s(%d) Open\n",__func__,__LINE__);
    return 0;
}

/************************************************************************
 *
 ************************************************************************/
int rtk_emcu_release(struct inode *inode, struct file *file)
{
    EMCU_INFO("%s(%d) Release\n",__func__,__LINE__);
    return 0;
}

/************************************************************************
 *
 ************************************************************************/
static long rtk_emcu_ioctl(struct file *file, unsigned int cmd,
                 unsigned long arg)
{
    EMCU_INFO("%s(%d) \n",__func__,__LINE__);
    return 0;
}

/************************************************************************
 *
 ************************************************************************/
#ifdef CONFIG_COMPAT
long rtk_emcu_compat_ioctl(struct file *file, unsigned int cmd,
                 unsigned long arg)
{
    EMCU_INFO("%s(%d)\n",__func__,__LINE__);
    return 0;
}
#endif

static
struct file_operations rtk_emcu_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = rtk_emcu_ioctl,
    .open = rtk_emcu_open,
    .release = rtk_emcu_release,
#ifdef CONFIG_COMPAT
    .compat_ioctl = rtk_emcu_compat_ioctl,
#endif
};

static struct miscdevice rtk_emcu_miscdev = {
    MISC_DYNAMIC_MINOR,
    "emcu_kdv",
    &rtk_emcu_fops
};


#define EMCU_DRV_NAME  "emcu_drv"

static int emcu_drv_suspend    (struct platform_device *pdev, pm_message_t state);
static int emcu_drv_resume    (struct platform_device *pdev);

static struct platform_device emcu_drv_pm_device = {
    .name          = EMCU_DRV_NAME,
    .id            = -1,
};

static struct platform_driver emcu_drv_pm_driver = {
    .driver    = {
        .name  = EMCU_DRV_NAME,
        .owner = THIS_MODULE,
    },
    .suspend   = emcu_drv_suspend,
    .resume    = emcu_drv_resume,
};

#ifdef CONFIG_PM
static int emcu_drv_suspend(struct platform_device *pdev, pm_message_t state)
{
    int i;

    EMCU_INFO("%s(%d)\n",__func__,__LINE__);

    if(emcu_test_ctl & EMCU_PARSE_EN){
        /*
         * When Auto parse mode enable, enable Power_En,IRDA,WIFI_dongle and Keypad self.
         * To check if it's settd because AP may call emcu's API still.
         */
        /* check Power enable pin */
        if(!(emcu_auto_event & EMCU_POWER_EN_ALERT)){
            if(powerMgr_power_en_parser(NULL,0,PARSE_AUTO)){
                EMCU_WARNING("%s(%d)power_en auto parse fail!\n",__func__,__LINE__);
            }
        }else{
            EMCU_WARNING("%s(%d)skip auto parse!\n",__func__,__LINE__);
        }

        /* check Irda  */
        if(!(emcu_auto_event & EMCU_IRDA_ALERT)){
            if(powerMgr_irda_parser(NULL,0,PARSE_AUTO)){
                EMCU_WARNING("%s(%d)irda auto parse fail!\n",__func__,__LINE__);
            }
        }else{
            EMCU_WARNING("%s(%d)skip auto parse!\n",__func__,__LINE__);
        }

        /* check Keypad */
        if(!(emcu_auto_event & EMCU_KEYPAD_ALERT)){
            if(powerMgr_keypad_parser(NULL,0,PARSE_AUTO)){
                EMCU_WARNING("%s(%d)keypad auto parse fail!\n",__func__,__LINE__);
            }
        }else{
            EMCU_WARNING("%s(%d)skip auto parse!\n",__func__,__LINE__);
        }
    }

    for(i=0; i<RTD_SHARE_MEM_LEN; i++)
        local_sharemem_sup[i] = rtd_inl(RTD_SHARE_MEM_BASE+4*i);

    emcu_auto_event = 0;
    return 0;
}

static int emcu_drv_resume(struct platform_device *pdev)
{
    int i;

    EMCU_INFO("%s(%d)\n",__func__,__LINE__);

    for(i=0; i<RTD_SHARE_MEM_LEN; i++)
        local_sharemem_res[i] = rtd_inl(RTD_SHARE_MEM_BASE+4*i);

    return 0;
}

#else

#define emcu_drv_suspend   NULL
#define emcu_drv_resume    NULL

#endif

/************************************************************************
 * To use mmc param for dynamic operation
 ************************************************************************/
static
int rtk_emcu_parse_param(void)
{
    char *opt = NULL;
    char *platform_mmc_param = NULL;
    __attribute__((unused))int value;

#ifdef AUTO_PCB_PARAM
    emcu_test_ctl |= EMCU_PARSE_EN;
    EMCU_ALERT("CONFIG_EMCU_AUTO_PARSER enable\n");
#endif

    if (platform_info.mmc_param == NULL)
        return 0;

    platform_mmc_param = kmalloc(MMC_PARAM_LEN,GFP_KERNEL);
    if(platform_mmc_param == NULL)
        return 0;

    memcpy(platform_mmc_param,platform_info.mmc_param,MMC_PARAM_LEN);

    EMCU_INFO("mmc_param: \"%s\"\n",platform_mmc_param);

    while ((opt = strsep(&platform_mmc_param, " ")) != NULL) {
        if (!*opt){
            continue;
        }
#ifndef AUTO_PCB_PARAM
        if (!strncmp(opt, "emcu_auto=", 10)) {
            if (!kstrtol(opt + 10, 10, (long *)&value)){
                if(value == 1){
                    emcu_test_ctl |= EMCU_PARSE_EN;
                }else{
                    emcu_test_ctl &= ~EMCU_PARSE_EN;
                }
                EMCU_ALERT("emcu auto parse %s by bootcode.\n",
                        ((emcu_test_ctl & EMCU_PARSE_EN))?"enable":"disable");
            }
        }
#endif
        if (!strncmp(opt, "emcu_chk_skip", 13)) {
            EMCU_ALERT("emcu skip panic if no setting\n");
            emcu_test_ctl |= EMCU_CHK_SKIP;
        }
    }

    if(platform_mmc_param)
        kfree(platform_mmc_param);

    return 0;

}

/************************************************************************
 *
 ************************************************************************/
static
int __init rtk_emcu_module_init(void)
{
    int retval = 0;

    emcu_auto_event = 0;
    emcu_test_ctl = 0;
    rtk_emcu_parse_param();

    if (misc_register(&rtk_emcu_miscdev)) {
        EMCU_INFO("rtk_emcu_module_init failed - register misc device failed\n");
        retval = -ENODEV;
        goto FINISH_OUT;
    }

    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_clr_pm_task);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_clr_share_mem);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_show_share_mem);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_wifi_dg);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_WOL);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_WOWLAN);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_keypad_multi);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_cec);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_mhl);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_uart);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_ppsource);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_wakeup_timer);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_wakeup_timer1);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_wakeup_min);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_wakeup_sec);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_irda);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_irda_in_code);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_power_en);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_power_en_in_name);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_get_sleep_dur);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_get_wakeup_source);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_get_wakeup_status);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_cur_time);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_get_rec_time);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_sharemem);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_sharemem_mask);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_STM);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_RTC);
#ifdef INTERNAL_WOW_SUPPORT
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_WOW);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_WOW_chksum);
#endif
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_show_version);
    device_create_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_show_help);

    retval = platform_device_register(&emcu_drv_pm_device);
    if (retval)
        goto FINISH_OUT;

    retval = platform_driver_probe(&emcu_drv_pm_driver, NULL);
    if (retval)
        goto FINISH_OUT;

    EMCU_INFO("emcu_kdv driver install success\n");

FINISH_OUT:
    return retval;
}

/************************************************************************
 *
 ************************************************************************/
static
void __exit rtk_emcu_module_exit(void)
{
    platform_driver_unregister(&emcu_drv_pm_driver);

    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_clr_pm_task);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_clr_share_mem);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_show_share_mem);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_wifi_dg);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_WOL);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_WOWLAN);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_keypad_multi);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_cec);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_mhl);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_uart);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_ppsource);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_wakeup_timer);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_wakeup_timer1);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_wakeup_min);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_wakeup_sec);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_irda_in_code);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_irda);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_power_en);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_setup_power_en_in_name);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_get_sleep_dur);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_get_wakeup_source);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_get_wakeup_status);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_cur_time);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_get_rec_time);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_sharemem);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_sharemem_mask);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_STM);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_RTC);
#ifdef INTERNAL_WOW_SUPPORT
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_WOW);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_set_WOW_chksum);
#endif
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_show_version);
    device_remove_file(rtk_emcu_miscdev.this_device, &dev_attr_emcu_show_help);

    EMCU_INFO("%s(%d)rtk emcu_kdv driver uninstall success\n",__func__,__LINE__);
}


/* =======================================================================
 * Kernel setup function
 * ======================================================================= */
extern eirda_keymap_type ir_keymap_type;
extern int ir_proto_init(char *options);
int rtk_emcu_smem_set_ir(char *ibuf){
#define MAX_IRKEY_LEN 100
    int i;
    u32 len = 0;
    char buff[MAX_IRKEY_LEN] = {0};
    char *opt = NULL;
    char *pbuff = NULL;
    unsigned long tmp_val;
    unsigned int ir_key[15];
    uint32_t user_key[15];

    pbuff = buff;
    len = strlen(ibuf);
    EMCU_DEBUG("%s(%u)parameter len is %u.\n",__func__,__LINE__,len);
    if(len < 1 )
        return -EINVAL;

    if(len > MAX_IRKEY_LEN ){
        EMCU_ALERT("%s(%u)parameter size bigger then buffer(%u).\n",__func__,__LINE__,len);
        len = MAX_IRKEY_LEN;
    }
    strncpy(buff,ibuf,len);
    len = 0;
    while ((opt = strsep(&pbuff, ",")) != NULL) {
        if (!*opt)
            continue;

        if(len == 0){
            unsigned int boot_sel_proto = 0;
            unsigned char remoter[32] = {0};
            if (sscanf(opt, "%d-%31s", &boot_sel_proto, remoter) < 1){
                EMCU_ALERT("%s(%u)get IR protocol fail\n",__func__,__LINE__);
                return -EINVAL;
            }
            ir_proto_init(opt);
            user_key[0] = boot_sel_proto;
            len++;
        }else{
            if (!kstrtol(opt, 16, &tmp_val)){
                user_key[len] = (uint32_t)tmp_val;
                EMCU_DEBUG("%s(%u)get param = 0x%x\n",__func__,__LINE__,user_key[len]);
                len++;
            }else {
                EMCU_ALERT("%s(%u)get param fail\n",__func__,__LINE__);
            }
        }
    }
    if(len <2){
        EMCU_ALERT("%s(%u)There are no vaild key\n",__func__,__LINE__);
        return -EINVAL;
    }
    EMCU_DEBUG("%s(%u)get %d set key\n",__func__,__LINE__,len);

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    ir_key[0] = user_key[0];
	if(ir_key[0] == 8) {
		 ir_key[1] = 0xf2a0d5;
         ir_key[2] = 0xfef010;
         ir_key[3] = 0xf300cf;
         ir_key[4] = 0xf310ce;
         ir_key[5] = 0xf320cd;
         ir_key[6] = 0xf330cc;
         ir_key[7] = 0xf340cb;
         ir_key[8] = 0xf350ca;
         ir_key[9] = 0xf360c9;
         ir_key[10] = 0xf370c8;
         ir_key[11] = 0xf380c7;
         ir_key[12] = 0xf390c6;
         len = 13;
     }
	 else if(ir_key[0] == 19)  {
         ir_key[1] = 0x2ad59966;
         ir_key[2] = 0x31ce9966;
         ir_key[3] = 0x32cd9966;
         ir_key[4] = 0x33cd9966;
         ir_key[5] = 0x34cd9966;
         ir_key[6] = 0x35cd9966;
         ir_key[7] = 0x36cd9966;
         ir_key[8] = 0x37cd9966;
         ir_key[9] = 0x38cd9966;
         ir_key[10] = 0x39cd9966;
         ir_key[11] = 0x30cd9966;
         ir_key[12] = 0xef109966; // CARD key for Netflix test
         len = 13;
     }
     else if(ir_key[0] == 1)  {
         ir_key[1] = 0xa05ffb04;
         ir_key[2] = 0xbb44fb04;
         ir_key[3] = 0xac53fb04;
         ir_key[4] = 0xaf50fb04;
         ir_key[5] = 0xed12fb04;
         ir_key[6] = 0xb04ffb04;
         ir_key[7] = 0xb34cfb04;
         ir_key[8] = 0xf10efb04;
         ir_key[9] = 0xb44bfb04;
         ir_key[10] = 0xb748fb04;
         ir_key[11] = 0xf50afb04;
         ir_key[12] = 0xff00fb04; // CARD key for Netflix test
         len = 13;
     }
     else {
         venus_ir_keylist_to_scanlist(user_key+1, ir_key+1, (uint32_t)len);
     }
    for(i=0;i<(len-1);i++){
        EMCU_DEBUG("irda keycode%d=0x%08x\n",i,ir_key[i+1]);
    }

//#define EMCU_FAKE_IR_KEY
#ifdef EMCU_FAKE_IR_KEY
        EMCU_ALERT("hack for testing\n");
        ir_key[0] = 0x11;   //protocol
        ir_key[1] = 0x123456aa;
        ir_key[2] = 0x123456bb;
        ir_key[3] = 0x123456cc;
        EMCU_ALERT("irda protocol=0x%x\n",ir_key[0]);
        for(i=0;i<(len-1);i++){
            EMCU_ALERT("irda keycode%d=0x%08x\n",i,ir_key[i+1]);
        }
#endif
#else
        EMCU_ALERT("irda keycode transfer function not ready\n");
        return -EINVAL;
#endif

    powerMgr_setup_irda(ir_key[0],len-1,ir_key+1);

    return 0;
}


module_init(rtk_emcu_module_init);
module_exit(rtk_emcu_module_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alexkh <alexkh@realtek.com>");
