#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/kfifo.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/irq.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include <linux/ioctl.h>
#include <linux/signal.h>
#include <linux/interrupt.h>
#include <linux/jiffies.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <rtk_kdriver/rtk_crt.h>

#include <linux/kernel.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rtk_kdriver/rtk_lsadc.h>
#include "rtk_lsadc-attr.h"
#include "rtk_lsadc_reg.h"


//static int main_log_ioctl=0;
unsigned int lsadc_init_status_mask = LSADC_INIT_MASK_NONE;

void LSADC_ClockEnable(unsigned char On)
{
    if (On) {
        CRT_CLK_OnOff(LSADC, CLK_ON, NULL);
    } else {
        CRT_CLK_OnOff(LSADC, CLK_OFF, NULL);
    }
}

int get_lsadc_init_status(unsigned int index)
{
    if(lsadc_init_status_mask & (0x1 << index))
        return 0;
    else
        return-1;
}

int rtk_lsadc_get_adcValue(unsigned int index, unsigned char* value)
{
    st_pad0_RBUS st_pad0_reg;

    if(index < 0 || index >= MAX_LSADC_COUNT || value == NULL){
        LSADC_ERROR("Invalid parameter \n");
        return -1;
    }

    st_pad0_reg.regValue = rtd_inl(lsadcArray[index].p_reg_map->padCtrl);
    *value = st_pad0_reg.adc_val0;

    return 0;
}

EXPORT_SYMBOL(rtk_lsadc_get_adcValue);

int rtk_lsadc_get_threshold(unsigned int index, unsigned char* threshold)
{
    st_pad0_RBUS st_pad0_reg;

    if(index < 0 || index >= MAX_LSADC_COUNT || threshold == NULL){
        LSADC_ERROR("Invalid parameter \n");
        return -1;
    }

    st_pad0_reg.regValue = rtd_inl(lsadcArray[index].p_reg_map->padCtrl);
    *threshold = st_pad0_reg.pad0_thred;

    return 0;
}

EXPORT_SYMBOL(rtk_lsadc_get_threshold);

int rtk_lsadc_get_activeStatus(unsigned int index, unsigned char* activeStatus)
{
    st_pad0_RBUS st_pad0_reg;

    if(index < 0 || index >= MAX_LSADC_COUNT || activeStatus == NULL){
        LSADC_ERROR("Invalid parameter \n");
        return -1;
    }

    st_pad0_reg.regValue = rtd_inl(lsadcArray[index].p_reg_map->padCtrl);
    *activeStatus = st_pad0_reg.pad0_active;

    return 0;

}

EXPORT_SYMBOL(rtk_lsadc_get_activeStatus);

int rtk_lsadc_get_padSwitch(unsigned int index, unsigned char* padSwitch)
{
    st_pad0_RBUS st_pad0_reg;

    if(index < 0 || index >= MAX_LSADC_COUNT || padSwitch == NULL){
        LSADC_ERROR("Invalid parameter \n");
        return -1;
    }

    st_pad0_reg.regValue = rtd_inl(lsadcArray[index].p_reg_map->padCtrl);
    *padSwitch = st_pad0_reg.pad0_sw;

    return 0;

}

EXPORT_SYMBOL(rtk_lsadc_get_padSwitch);

int rtk_lsadc_get_voltageMode(unsigned int index, unsigned char* voltageMode)
{
    st_pad0_RBUS st_pad0_reg;

    if(index < 0 || index >= MAX_LSADC_COUNT || voltageMode == NULL){
        LSADC_ERROR("Invalid parameter \n");
        return -1;
    }

    st_pad0_reg.regValue = rtd_inl(lsadcArray[index].p_reg_map->padCtrl);
    *voltageMode = (st_pad0_reg.pad0_ctrl == 0) ? 1 : 0;

    return 0;

}

EXPORT_SYMBOL(rtk_lsadc_get_voltageMode);

int rtk_lsadc_set_threshold(unsigned int index, unsigned char threshold)
{
    st_pad0_RBUS st_pad0_reg;

    if((index < 0 )|| (index >= MAX_LSADC_COUNT ))
    {
        LSADC_ERROR("Invalid parameter \n");
        return -1;
    }

    st_pad0_reg.regValue = rtd_inl(lsadcArray[index].p_reg_map->padCtrl);
    st_pad0_reg.pad0_thred = threshold;
    rtd_outl(lsadcArray[index].p_reg_map->padCtrl,st_pad0_reg.regValue);
    return 0;

}

EXPORT_SYMBOL(rtk_lsadc_set_threshold);

int rtk_lsadc_set_active(unsigned int index, unsigned char activeStatus)
{
    st_pad0_RBUS st_pad0_reg;

    if(index < 0 || index >= MAX_LSADC_COUNT){
        LSADC_ERROR("Invalid parameter \n");
        return -1;
    }

    st_pad0_reg.regValue = rtd_inl(lsadcArray[index].p_reg_map->padCtrl);
    st_pad0_reg.pad0_active = (activeStatus == 0)? 0 : 1;
    rtd_outl(lsadcArray[index].p_reg_map->padCtrl,st_pad0_reg.regValue);
    return 0;

}

EXPORT_SYMBOL(rtk_lsadc_set_active);

int rtk_lsadc_set_padSwitch(unsigned int index, unsigned char padSwitch)
{
    st_pad0_RBUS st_pad0_reg;

    if(index < 0 || index >= MAX_LSADC_COUNT || padSwitch >= MAX_LSADC_COUNT){
        LSADC_ERROR("Invalid parameter \n");
        return -1;
    }


    st_pad0_reg.regValue = rtd_inl(lsadcArray[index].p_reg_map->padCtrl);
    st_pad0_reg.pad0_sw = padSwitch;
    rtd_outl(lsadcArray[index].p_reg_map->padCtrl,st_pad0_reg.regValue);

    return 0;

}

EXPORT_SYMBOL(rtk_lsadc_set_padSwitch);

int rtk_lsadc_set_voltageMode(unsigned int index, unsigned char voltageMode)
{
    st_pad0_RBUS st_pad0_reg;

    if(index < 0 || index >= MAX_LSADC_COUNT){
        LSADC_ERROR("Invalid parameter \n");
        return -1;
    }

    st_pad0_reg.regValue = rtd_inl(lsadcArray[index].p_reg_map->padCtrl);
    st_pad0_reg.pad0_ctrl = (voltageMode == 1)? 0 : 1;
    rtd_outl(lsadcArray[index].p_reg_map->padCtrl,st_pad0_reg.regValue);

    return 0;

}

EXPORT_SYMBOL(rtk_lsadc_set_voltageMode);

int rtk_lsadc_set_lsadc_config(RTK_LSADC_INFO  *lsadc_info)
{
    int ret   = -1;
    st_pad0_RBUS st_pad0_reg;
    st_lsadc_ctrl_RBUS st_lsadc_ctrl_reg;

    if(lsadc_info == NULL)
        return ret;

    if(lsadc_info->pinNumber >= 0) {
        st_pad0_reg.regValue = 0;
        st_pad0_reg.pad0_active = lsadc_info->pad_active;
        st_pad0_reg.pad0_thred = lsadc_info->pad_thred;
        st_pad0_reg.pad0_sw = lsadc_info->pad_sw;
        st_pad0_reg.pad0_ctrl = lsadc_info->pad_ctrl;
        rtd_outl(lsadcArray[lsadc_info->pinNumber].p_reg_map->padCtrl, st_pad0_reg.regValue);

        st_lsadc_ctrl_reg.regValue = rtd_inl(lsadcArray[lsadc_info->pinNumber].p_reg_map->padCtrl);
        if(!st_lsadc_ctrl_reg.enable && lsadc_info->pad_active) {
            st_lsadc_analog_ctrl_RBUS st_ana_ctrl_reg;
            st_ana_ctrl_reg.regValue = rtd_inl(lsadcArray[lsadc_info->pinNumber].p_reg_map->analog_ctrl);
            st_ana_ctrl_reg.jd_power = 0x1;

            rtd_outl(lsadcArray[lsadc_info->pinNumber].p_reg_map->analog_ctrl, st_ana_ctrl_reg.regValue);

            st_lsadc_ctrl_reg.sel_wait = 0x1;
            st_lsadc_ctrl_reg.sel_adc_ck = 0x6;
            st_lsadc_ctrl_reg.debounce_cnt = 0x1;
            st_lsadc_ctrl_reg.enable = 1;
            rtd_outl(lsadcArray[lsadc_info->pinNumber].p_reg_map->lsadc_ctrl, st_lsadc_ctrl_reg.regValue);
        }
        ret = 0;
    }
    return ret;
}

int rtk_lsadc_get_lsadc_config(RTK_LSADC_INFO  *lsadc_info)
{
    st_pad0_RBUS st_pad0_reg;

    int ret   = -1;

    if(lsadc_info == NULL)
        return ret;

    if(lsadc_info->pinNumber >= 0) {

        st_pad0_reg.regValue = rtd_inl(lsadcArray[lsadc_info->pinNumber].p_reg_map->padCtrl);
        lsadc_info->pad_active = st_pad0_reg.pad0_active;
        lsadc_info->pad_thred = st_pad0_reg.pad0_thred;
        lsadc_info->pad_sw = st_pad0_reg.pad0_sw;
        lsadc_info->pad_ctrl = st_pad0_reg.pad0_ctrl;
        lsadc_info->adc_val = st_pad0_reg.adc_val0;
        ret = 0;
    }
    return ret;
}

int rtk_lsadc_dump_mainAnalogCtrl(void)
{
    st_lsadc_analog_ctrl_RBUS anaglog;
    anaglog.regValue = rtd_inl(ST_LSADC_ANALOG_CTRL_VADDR);
    return anaglog.regValue;
}
int rtk_lsadc_dump_mainLsadcCtrl(void)
{
    st_lsadc_ctrl_RBUS ctrl;
    ctrl.regValue = rtd_inl(ST_LSADC_CTRL_VADDR);
    return ctrl.regValue;
}


/*
 * Add lsadc API for kernel call
 */

int rtk_lsadc_defualt_enable(int index, LSADC_MODE lsadc_mode)
{
    RTK_LSADC_INFO lsadc_info;
    if (index >= MAX_LSADC_COUNT || index < 0)
        return -1;
    
    memset(&lsadc_info, 0, sizeof(lsadc_info));
    lsadc_info.pinNumber = index;
    lsadc_info.pad_active = 1;
    lsadc_info.pad_sw = index;
    lsadc_info.pad_ctrl = lsadc_mode;
    return rtk_lsadc_set_lsadc_config(&lsadc_info);
}

EXPORT_SYMBOL(rtk_lsadc_defualt_enable);


