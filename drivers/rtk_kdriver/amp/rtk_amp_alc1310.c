#include <linux/init.h>
#include <linux/delay.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/printk.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <rtk_kdriver/io.h>
#include <mach/platform.h>
#include <mach/rtk_platform.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <linux/i2c.h>
#include "rtk_amp_alc1310.h"
#ifdef CONFIG_REALTEK_PCBMGR
#include <mach/pcbMgr.h>
#endif

extern platform_info_t platform_info;

MODULE_LICENSE("Dual BSD/GPL");

#define AMP_MAJOR  0
#define DRV_NAME   "RTKamp"

static const char  drv_name[] = DRV_NAME;
static int amp_i2c_id  = -1;

#ifdef CONFIG_PM
static int amp_suspend(struct device *dev);
static int amp_resume(struct device *dev);
#endif

#ifdef CONFIG_PM
static struct platform_device *amp_devs;

static const struct dev_pm_ops amp_pm_ops = {
        .suspend    = amp_suspend,
        .resume     = amp_resume,
};
#endif

static struct platform_driver amp_driver = {
        .driver = {
                .name         = (char *)drv_name,
                .bus          = &platform_bus_type,
#ifdef CONFIG_PM
                .pm           = &amp_pm_ops,
#endif
        },
};

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;

int amp_get_i2c_id(void)
{
    unsigned long long param;

    if (pcb_mgr_get_enum_info_byname("AMP_I2C", &param) != 0)
    {
        AMP_ERR("%s line:%d bootcode pcb info lose to define  \"AMP_I2C\"  \n",__func__, __LINE__ );
        AMP_ERR("%s line:%d bootcode pcb info lose to define  \"AMP_I2C\"  \n",__func__, __LINE__ );
        AMP_ERR("%s line:%d bootcode pcb info lose to define  \"AMP_I2C\"  \n",__func__, __LINE__ );
        return -1;
    }

    AMP_WARN("%s line:%d get amp I2c id = %d  \n",__func__, __LINE__  , param );

    return param;
}

//void vbe_disp_suspend(void)
static int amp_suspend(struct device *dev)
{
    AMP_WARN("[AMP] amp_notify_suspend\n");
    return 0;
}

//void vbe_disp_resume(void)
static int amp_resume(struct device *dev)
{

// Please notice that this is only for REALTEK_AMP_TAS5711 & REALTEK_AMP_ACL1310
// If use different IC, please change this.

    unsigned char data[8] = {0};
    unsigned char u8Index=0;

    AMP_WARN("[AMP] amp_notify_resume\n");

    for(u8Index = 0; ; u8Index ++)
    {
        data[0] = Alc1310_DefautTbl[u8Index].bAddr;
        if(data[0] == END_FLAG)
        {
            break;
        }
        data[1] = Alc1310_DefautTbl[u8Index].bArray[0];
        data[2] = Alc1310_DefautTbl[u8Index].bArray[1];

        #ifdef AMP_DEBUG
            AMP_INFO("%s audio amp write addr:0x%x----data[1]=0x%x----data[2]=0x%x\n",__func__,data[0],data[1],data[2]);
        #endif

        if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &data[0], 3) < 0 )
        {
            AMP_ERR("%s line:%d program ACL1310 failed\n",__func__, __LINE__);
            AMP_ERR("\nwrite addr:0x%x----data[1]=0x%x----data[2]=0x%x\n",data[0],data[1],data[2]);
            break;
        }
    }
	return 0;
}

static char *amp_devnode(struct device *dev, mode_t *mode)
{
        return NULL;
}


struct file_operations amp_fops = {
        .owner                  = THIS_MODULE,
};

int rtk_amp_dump_all(const char *buf)
{
    int ret = 0;
    int result = 0;
    int i = 0;
    unsigned char addr[1] ={0};
    unsigned char data[3] ={0};
    //Read MX REgister
    AMP_WARN("== Dump MX 00~7F Reg ==\n");
    for (i=0x00; i<= 0x7f/*AMP_MX_REG_SIZE*/ ;++i){
        addr[0] = i;
        if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &addr[0], 1) < 0 ){
            AMP_ERR("I2C Write Reg:0x%x failed\n",addr[0]);
            break;
        }
        result = i2c_master_recv_ex(amp_i2c_id,AMP_DEVICE_ADDR,NULL,0,data,AMP_DATA_SIZE);
        AMP_WARN("MX_Reg:0x%x DataH:0x%x DataL:0x%x\n", addr[0],data[0], data[1]);
        mdelay(5);
        if(result<0) {
            AMP_ERR("Read AMP REG:0x%x failed !! \n",addr[0]);
            break;
       }
    }

    //Read PR Register
    AMP_WARN("== Dump PR 00~1F Reg ==\n");
    for (i=0; i<= AMP_PR_REG1_END ;++i){
	//PR Register Address Write
        data[0] = ALC_1310_PR6A_REG_INDEX;
        data[1] = 0;
        data[2] = i;
        if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &data[0], 3) < 0 ){
            AMP_ERR("I2C Write Reg:0x%x failed\n",data[0]);
            break;
        }
        AMP_WARN("[6A][Addr] DataH:0x%x DataL:0x%x\n", data[1], data[2]);

        //PR Register Data Read
        addr[0] = ALC_1310_PR6C_REG_DATA;
        data[0] = 0;
        data[1] = 0;
        data[2] = 0;
        if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &addr[0], 1) < 0 ){
            AMP_ERR("I2C Write Reg:0x%x failed\n",addr[0]);
            break;
        }
        result = i2c_master_recv_ex(amp_i2c_id,AMP_DEVICE_ADDR,NULL,0,data,AMP_DATA_SIZE);
        AMP_WARN("[6C][Data] DataH:0x%x DataL:0x%x\n", data[0], data[1]);
        mdelay(5);
        if(result<0) {
            AMP_ERR("Read AMP REG:0x%x failed !! \n",addr[0]);
            break;
       }
    }

    AMP_WARN("== Dump PR 90~FF Reg ==\n");
    for (i=AMP_PR_REG2_START; i<= AMP_PR_REG2_END ;++i){
        //PR Register Address Write
        data[0] = ALC_1310_PR6A_REG_INDEX;
        data[1] = 0;
        data[2] = i;
        if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &data[0], 3) < 0 ){
            AMP_ERR("I2C Write Reg:0x%x failed\n",data[0]);
            break;
        }
        AMP_WARN("[6A][Addr] DataH:0x%x DataL:0x%x\n", data[1], data[2]);

        //PR Register Data Read
        addr[0] = ALC_1310_PR6C_REG_DATA;
        if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &addr[0], 1) < 0 ){
            AMP_ERR("I2C Write Reg:0x%x failed\n",addr[0]);
            break;
        }
        result = i2c_master_recv_ex(amp_i2c_id,AMP_DEVICE_ADDR,NULL,0,data,AMP_DATA_SIZE);
        AMP_WARN("[6C][Data] DataH:0x%x DataL:0x%x\n", data[0], data[1]);
        mdelay(5);
        if(result<0) {
            AMP_ERR("Read AMP REG:0x%x failed !! \n",addr[0]);
            break;
       }
    }
    return ret;
}

int rtk_amp_mute_set(int on_off)
{
    int ret = 0;
    int result = 0;
    unsigned char addr[1] ={0};
    unsigned char data[2] ={0};
    unsigned char send_data[3] ={0};

    //Read
    addr[0] = ALC_1310_MX13_VOLUME_SETTING_2;
    if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &addr[0], 1) < 0 ){
        AMP_ERR("I2C Write Address Reg:0x%x failed\n",addr[0]);
        return (-1);
    }

    result = i2c_master_recv_ex(amp_i2c_id,AMP_DEVICE_ADDR,NULL,0,data,AMP_DATA_SIZE);

    if(result<0) {
        AMP_ERR("Read AMP REG:0x%x failed !! \n",ALC_1310_MX13_VOLUME_SETTING_2);
        return (-1);
    }

    if (on_off == AMP_MUTE_ON){
        data[0] = ALC_1310_MUTE_ON(data[0]);
    }
    else if (on_off == AMP_MUTE_OFF){
        data[0] = ALC_1310_MUTE_OFF(data[0]);
    }

    //Write
    send_data[0] = ALC_1310_MX13_VOLUME_SETTING_2;
    send_data[1] = data[0];
    send_data[2] = data[1];

    if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &send_data[0], 3) < 0 ){
        AMP_ERR("I2C Write Reg:0x%x Data_H:0x%x Data_L:0x%x failed\n",send_data[0],send_data[1],send_data[2]);
        return (-1);
    }
    else{
        AMP_WARN("Addr:0x%x Reg:0x%x Data_H:0x%x Data_L:0x%x\n", AMP_DEVICE_ADDR,ALC_1310_MX13_VOLUME_SETTING_2,data[0], data[1]);
    }

    return ret;
}

int parser_amp_cmd(const char *buf, int len,unsigned char *data)
{
    char* const delim = " ";
    char *token, *cur;
    cur = buf;
    int i = 0;
    while (token = strsep(&cur, delim)) {
        if(i >= 1)
        {
             data[i-1] = (unsigned char)simple_strtol( token,NULL,16);
        }
        i++;
    }
    if(i == len)
        return 0;
    else
        return (-1);
}

int rtk_amp_param_set(unsigned char *data_wr)
{
    int ret = 0;
    int result = 0;
    unsigned char addr[1] ={0};
    unsigned char send_data[3] ={0};

    send_data[0] = data_wr[0];
    send_data[1] = data_wr[1];
    send_data[2] = data_wr[2];

    if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &send_data[0], 3) < 0 ){
        AMP_ERR("I2C Write Reg:0x%x Data_H:0x%x Data_L:0x%x failed\n",send_data[0],send_data[1],send_data[2]);
        return (-1);
    }
    else{
        AMP_WARN("Addr:0x%x Reg:0x%x Data_H:0x%x Data_L:0x%x\n", AMP_DEVICE_ADDR,send_data[0],send_data[1], send_data[2]);
    }

    return ret;
}

int rtk_amp_param_get(unsigned char *reg)
{
    int ret = 0;
    int result = 0;
    unsigned char addr[1] ={0};
    unsigned char data[2] ={0};
    unsigned char send_data[3] ={0};

    //Read
    addr[0] = reg[0];
    if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &addr[0], 1) < 0 ){
        AMP_ERR("I2C Write Address Reg:0x%x failed\n",addr[0]);
        return (-1);
    }

    result = i2c_master_recv_ex(amp_i2c_id,AMP_DEVICE_ADDR,NULL,0,data,AMP_DATA_SIZE);

    if(result<0) {
        AMP_ERR("Read AMP REG:0x%x failed !! \n",*reg);
        return (-1);
    }

    AMP_WARN("Addr:0x%x Reg:0x%x Data_H:0x%x Data_L:0x%x\n", AMP_DEVICE_ADDR,addr[0],data[0], data[1]);

    return ret;
}

int rtk_amp_param_init(void)
{
    AMP_INFO("[AMP] rtk_amp_param_init\n");

    unsigned char data[8] = {0};
    unsigned char u8Index=0;
    for(u8Index = 0; ; u8Index ++)
    {
        data[0] = Alc1310_DefautTbl[u8Index].bAddr;
        if(data[0] == END_FLAG)
        {
            break;
        }
        data[1] = Alc1310_DefautTbl[u8Index].bArray[0];
        data[2] = Alc1310_DefautTbl[u8Index].bArray[1];

        AMP_WARN("%s audio amp write addr:0x%x----data[1]=0x%x----data[2]=0x%x\n",__func__,data[0],data[1],data[2]);

        if ( i2c_master_send_ex(amp_i2c_id, AMP_DEVICE_ADDR, &data[0], 3) < 0 )
        {
            AMP_ERR("%s line:%d program ACL1310 failed\n",__func__, __LINE__);
            AMP_ERR("\nwrite addr:0x%x----data[1]=0x%x----data[2]=0x%x\n",data[0],data[1],data[2]);
            break;
        }
    }
}

ssize_t rtk_amp_show_param(struct device *dev,
                            struct device_attribute *attr, char *buf)
{
    int ret = 0;

    //char cmd1[6];
    char buf_info[4096] ={0};
    //sscanf(buf, "%s%d\n", &cmd1);
    if (strcmp(attr->attr.name, "amp_dump") == 0) {
        ret = rtk_amp_dump_all(buf_info);
        return sprintf(buf, "%s\n", buf_info);
    }
    return ret;
}

ssize_t rtk_amp_store_param(struct device *dev,
                           struct device_attribute *attr,
                           const char *buf, size_t count)
{
    int ret = 0;
    int on_off = 0;
    char cmd1[4];
    char buf_info[4096] ={0};
    char reg = {0};
    unsigned char data[3] = {0};

    if (strcmp(attr->attr.name, "amp_mute") == 0) {
        sscanf(buf, "%d\n",&on_off);
        ret = rtk_amp_mute_set(on_off);
    }
    else if (strcmp(attr->attr.name, "amp_param") == 0) {
        sscanf(buf, "%s\n", &cmd1);
        if (strcmp(cmd1, "get") == 0) {
	    //sscanf(buf, "%s %s\n", &cmd1, &reg);
            ret = parser_amp_cmd(buf,1,data);
            ret = rtk_amp_param_get(data);
        }
        else if(strcmp(cmd1, "set") == 0) {
           ret = parser_amp_cmd(buf,3,data);
           ret = rtk_amp_param_set(data);
        }
        else if(strcmp(cmd1, "init") == 0) {
           ret = rtk_amp_param_init();
        }
        else {
           AMP_ERR("No this amp command\n");
        }

    }
    return count;
}

DEVICE_ATTR(amp_mute, S_IWUSR | S_IWGRP | S_IRUGO, rtk_amp_show_param,
                    rtk_amp_store_param);
DEVICE_ATTR(amp_dump, S_IWUSR | S_IWGRP | S_IRUGO, rtk_amp_show_param,
                    rtk_amp_store_param);
DEVICE_ATTR(amp_param, S_IWUSR | S_IWGRP | S_IRUGO, rtk_amp_show_param,
                    rtk_amp_store_param);
DEVICE_ATTR(amp_init, S_IWUSR | S_IWGRP | S_IRUGO, rtk_amp_show_param,
                    rtk_amp_store_param);


static struct class *amp_class = NULL;
static struct cdev amp_cdev;
static struct device *amp_device_this;

static int rtk_amp_init(void) {
        int result = 0;
        dev_t dev = MKDEV(AMP_MAJOR, 0);

        AMP_WARN("amp: AMP init for Realtek AMP(2016/10/25)\n");

        result = register_chrdev_region(dev, 1, "RTKamp");
        if (result < 0) {
                AMP_ERR("amp: can not get chrdev region...\n");
                return result;
        }

        amp_class = class_create(THIS_MODULE, "RTKamp");
        if (IS_ERR(amp_class)) {
                AMP_ERR("amp: can not create class...\n");
                result = PTR_ERR(amp_class);
                goto fail_class_create;
        }

        amp_class->devnode = amp_devnode;

        amp_devs = platform_device_register_simple("RTKamp", -1, NULL, 0);
        if (platform_driver_register(&amp_driver) != 0) {
                AMP_ERR("amp: can not register platform driver...\n");
                result = -EINVAL;
                goto fail_platform_driver_register;
        }

        cdev_init(&amp_cdev, &amp_fops);
        amp_cdev.owner = THIS_MODULE;
        amp_cdev.ops = &amp_fops;
        result = cdev_add(&amp_cdev, dev, 1);
        if (result < 0) {
                AMP_ERR("amp: can not add character device...\n");
                goto fail_cdev_init;
        }
        amp_device_this = device_create(amp_class, NULL, dev, NULL, "RTKamp");
        device_create_file(amp_device_this,&dev_attr_amp_mute);
        device_create_file(amp_device_this,&dev_attr_amp_dump);
        device_create_file(amp_device_this,&dev_attr_amp_param);

        amp_i2c_id = amp_get_i2c_id();

        if( -1 == amp_i2c_id )
        {
            AMP_ERR("%s line:%d amp i2c id failed \n",__func__, __LINE__);
            return -1;
        }

#ifdef CONFIG_RTK_AMP_USER_RESUME
        amp_devs->dev.power.is_userresume = true;
        device_enable_async_suspend(&(amp_devs->dev));
#endif

    	return 0;

fail_cdev_init:
        platform_driver_unregister(&amp_driver);
fail_platform_driver_register:
        platform_device_unregister(amp_devs);
        amp_devs = NULL;
        class_destroy(amp_class);
fail_class_create:
        amp_class = NULL;
        unregister_chrdev_region(dev, 1);
        return result;

}

static void rtk_amp_exit(void) {
        dev_t dev = MKDEV(AMP_MAJOR, 0);

        if ((amp_devs == NULL) || (amp_class == NULL))
                BUG();

        device_destroy(amp_class, dev);
        cdev_del(&amp_cdev);

        platform_driver_unregister(&amp_driver);
        platform_device_unregister(amp_devs);
        amp_devs = NULL;

        class_destroy(amp_class);
        amp_class = NULL;

        device_remove_file(amp_device_this, &dev_attr_amp_mute);
        device_remove_file(amp_device_this, &dev_attr_amp_dump);
        device_remove_file(amp_device_this, &dev_attr_amp_param);

        unregister_chrdev_region(dev, 1);
}

fs_initcall(rtk_amp_init);
module_exit(rtk_amp_exit);
