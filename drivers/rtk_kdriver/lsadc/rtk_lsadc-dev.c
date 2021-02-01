#include <asm/uaccess.h>
#include <linux/bitops.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/export.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/io.h>
#include <mach/io.h>
#include <linux/irq.h>
#include <linux/init.h>
#include <linux/ioctl.h>
#include <linux/input.h>
#include <linux/ioport.h>
#include <linux/interrupt.h>
#include <linux/jiffies.h>
#include <linux/kfifo.h>
#include <linux/kthread.h>
#include <linux/of.h>
#include <linux/pci.h>
#include <linux/poll.h>
#include <linux/platform_device.h>
#include <linux/random.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/signal.h>
#include <linux/stat.h>
#include <linux/string.h>
#include <mach/pcbMgr.h>

#include <linux/kernel.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rtk_kdriver/rtk_lsadc.h>
#include <rtk_kdriver/rtk_lsadc-dev.h>
#include "rtk_lsadc_reg.h"
#include "rtk_lsadc-attr.h"

int lsadc_dev_major;
int lsadc_dev_minor;

static RTK_LSADC_INFO backup_config_lsadc[MAX_LSADC_COUNT];
extern int m_ioctl_enable;
static struct cdev *dev_cdevp_lsadc = NULL;
static struct class *_gstlsadc_class;
static struct device *lsadc_device_st;
static struct platform_device *pst_rtk_lsadc_platform_dev;
LSADC_PCBINFO _gLsadcInfo[MAX_LSADC_PCBINFO_COUNT];
extern unsigned int lsadc_init_status_mask;
int _gLsadcInfo_count=0;

static int rtk_lsadc_dump_all_pininfo(RTK_ALL_LSADC_PIN_T* pcbInfo)
{
    int i;
    RTK_LSADC_INFO lsadc_info;
    for(i = 0; i < _gLsadcInfo_count; i ++){
        memcpy(pcbInfo->pcbInfo[i].pin_name, _gLsadcInfo[i].pinName,sizeof(pcbInfo->pcbInfo[i].pin_name));
        memset(&lsadc_info,0,sizeof(RTK_LSADC_INFO));
        lsadc_info.pinNumber = _gLsadcInfo[i].index;
        rtk_lsadc_get_lsadc_config(&lsadc_info);
        memcpy(&(pcbInfo->pcbInfo[i].info), &lsadc_info,sizeof(RTK_LSADC_INFO));
    }
    pcbInfo->count = _gLsadcInfo_count;
    return 0;
}

static void rtk_lsadc_init_pcb_pin(void){
    int i;
    unsigned int pin_type,pin_index;
    for(i = 0; i < PCB_ENUM_MAX; i++){
        if(memcmp(pcb_enum_all[i].name, "PIN", 3) == 0 && pcb_enum_all[i].value != 0)
        {
            pin_type  = GET_PIN_TYPE(pcb_enum_all[i].value);
            pin_index = GET_PIN_INDEX(pcb_enum_all[i].value);
            if(pin_type == PCB_PIN_TYPE_LSADC)
            {
                strcpy(_gLsadcInfo[_gLsadcInfo_count].pinName,pcb_enum_all[i].name);
                _gLsadcInfo[_gLsadcInfo_count].ullPcbMgrValue = pcb_enum_all[i].value;
                _gLsadcInfo[_gLsadcInfo_count].index = pin_index;
                _gLsadcInfo_count ++;
            }

        }

    }

}

static int rtk_hw_setting_adc_init(void)
{
    int i;
    LSADC_ClockEnable(1);
    rtk_lsadc_init_pcb_pin();
    if(0 == _gLsadcInfo_count){
        return -1;
    }
    for(i = 0;i < _gLsadcInfo_count; i++)
    {
        if(0 != get_lsadc_init_status(_gLsadcInfo[i].index)){
            rtk_lsadc_defualt_enable(_gLsadcInfo[i].index,VOLTAGE_MODE);
            lsadc_init_status_mask = lsadc_init_status_mask | (0x1 << _gLsadcInfo[i].index);
        }
    }

    return 0;
}

static int rtk_lsadc_get_index_byName(char* pinName,unsigned int *val)
{
    int i = 0;
    for(i = 0; i < _gLsadcInfo_count; i++) {
        LSADC_DEBUG("%s:_gLsadcInfo.pinName = %s pinName =%s,_gLsadcInfo.index = %d\n",
                __FUNCTION__,_gLsadcInfo[i].pinName ,pinName,_gLsadcInfo[i].index);
        if(strcmp(_gLsadcInfo[i].pinName, pinName) == 0 ) {
            *val = _gLsadcInfo[i].index;
            return 0;
        }
    }
    return -1;
}

static void rtk_lsadc_backup_info(void)
{
    int i = 0;
    for(i = 0; i < MAX_LSADC_COUNT; i++){ 
        backup_config_lsadc[i].pinNumber = i;
        rtk_lsadc_get_lsadc_config(&backup_config_lsadc[i]);
    }
}

static void rtk_lsadc_restore_info(void)
{
    int i = 0;
    for(i = 0; i < MAX_LSADC_COUNT; i++)
        rtk_lsadc_set_lsadc_config(&backup_config_lsadc[i]);
}

#ifdef CONFIG_PM
/*static int rtk_pwm_suspend(struct platform_device *dev, pm_message_t state)*/
static int rtk_lsadc_suspend(struct device *dev)
{
    LSADC_WARN("suspend\n");
    rtk_lsadc_backup_info();
    //LSADC_ClockEnable(0);    // do not disable lsadc here, due to emcu may use it for wakeup detection
    return 0;
}

/*static int rtk_pwm_resume(struct platform_device *dev)*/
static int rtk_lsadc_resume(struct device *dev)
{

    LSADC_WARN("resume\n");
    LSADC_ClockEnable(1);
    rtk_lsadc_restore_info();
    return 0;
}

#ifdef CONFIG_HIBERNATION
static int rtk_lsadc_suspend_std(struct device *dev)
{
    LSADC_WARN("%s \n" , __func__);
    rtk_lsadc_backup_info();
    LSADC_ClockEnable(0);
    return 0;
}
static int rtk_lsadc_resume_std(struct device *dev)
{
    LSADC_WARN("%s \n" , __func__);
    LSADC_ClockEnable(1);
    rtk_lsadc_restore_info();
    return 0;
}

static int rtk_lsadc_poweroff(struct device *dev)
{
    LSADC_WARN("%s \n" , __func__);
    LSADC_ClockEnable(0);
    return 0;
}
static int rtk_lsadc_restore(struct device *dev)
{
    LSADC_WARN("%s \n" , __func__);
    LSADC_ClockEnable(1);
    rtk_lsadc_restore_info();
    return 0;
}


#endif

static const struct dev_pm_ops rtk_lsadc_pm_ops = {

    .suspend_noirq = rtk_lsadc_suspend,
    .resume_noirq = rtk_lsadc_resume,
#ifdef CONFIG_HIBERNATION
    .freeze_noirq     = rtk_lsadc_suspend_std,
    .thaw_noirq       = rtk_lsadc_resume_std,
    .poweroff_noirq     = rtk_lsadc_poweroff,
    .restore_noirq       = rtk_lsadc_restore,    
#endif
};

#endif

static int rtk_lsadc_probe(struct platform_device *pdev)
{
    LSADC_WARN("%s():\n", __FUNCTION__);
    return 0;
}

static int rtk_lsadc_remove(struct platform_device *pdev)
{
    LSADC_WARN("%s():\n", __FUNCTION__);

    /*rtk_hw_setting_power_off(0);*/
    /*rtk_hw_setting_power_off(1);*/
    return 0;
}


ssize_t rtk_lsadc_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    LSADC_WARN("%s():\n", __FUNCTION__);
    return -EFAULT;
}
ssize_t rtk_lsadc_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
    LSADC_WARN("%s():\n", __FUNCTION__);
    return -EFAULT;
}

int rtk_lsadc_open(struct inode *inode, struct file *filp)
{
    /*LSADC_WARN(KERN_"%s():\n", __FUNCTION__);*/
    return 0;
}

int rtk_lsadc_release(struct inode *inode, struct file *filp)
{
    //LSADC_WARN("%s():\n", __FUNCTION__);
    return 0;
}

long rtk_lsadc_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    int retval = 0;
    RTK_LSADC_VAL_T lsadc_info;
    unsigned int index;
    RTK_ALL_LSADC_PIN_T *pcbInfo = NULL;
    if(m_ioctl_enable == 0)
        return retval;

    LSADC_DEBUG("%s() enter\n", __FUNCTION__);
    if(cmd != RTK_LSADC_DUMP){
        if (copy_from_user(&lsadc_info, (void __user *)arg,
               sizeof(RTK_LSADC_VAL_T))) {
            LSADC_ERROR("read write LSADC failed, copy data from user space failed\n");
            return -EFAULT;
        }
        retval = rtk_lsadc_get_index_byName(lsadc_info.pin_name,&index);

        LSADC_DEBUG("piname = %s,val = %u,get index_by_name=%d ",lsadc_info.pin_name,lsadc_info.val,index);

        if(retval < 0)
            return index;
    }

    switch (cmd) {
    case RTK_LSADC_GET_ADCVAL:
        if(0 != rtk_lsadc_get_adcValue(index,&lsadc_info.val))
            return -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_SET_ACTIVE:
        retval = rtk_lsadc_set_active(index,lsadc_info.val);
        break;
    case RTK_LSADC_SET_TRESHOLD:
        retval = rtk_lsadc_set_threshold(index,lsadc_info.val);
        break;
    case RTK_LSADC_SET_SW:
        retval = rtk_lsadc_set_padSwitch(index,lsadc_info.val);
        break;
    case RTK_LSADC_SET_MODE:
        retval = rtk_lsadc_set_voltageMode(index,lsadc_info.val);
        break;
    case RTK_LSADC_GET_ACTIVE:
        if(0 != rtk_lsadc_get_activeStatus(index,&lsadc_info.val))
            return  -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_GET_THRESHOLD:
        if(0 != rtk_lsadc_get_threshold(index,&lsadc_info.val))
            return  -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_GET_SW:
        if(0 != rtk_lsadc_get_padSwitch(index,&lsadc_info.val))
            return  -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_GET_MODE:
        if(0 != rtk_lsadc_get_voltageMode(index,&lsadc_info.val))
            return  -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_DUMP:
        pcbInfo = (RTK_ALL_LSADC_PIN_T*)kmalloc(sizeof(RTK_ALL_LSADC_PIN_T), GFP_KERNEL);
        memset(pcbInfo, 0 ,sizeof(RTK_ALL_LSADC_PIN_T));
        rtk_lsadc_dump_all_pininfo(pcbInfo);
        retval = copy_to_user((void __user *)arg, pcbInfo, sizeof(RTK_ALL_LSADC_PIN_T));
        kfree(pcbInfo);
        break;

    default:
        retval = -ENOTTY;
    }

    LSADC_DEBUG("%s() exit\n", __FUNCTION__);

    return retval;

}

#ifdef CONFIG_COMPAT
long rtk_lsadc_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    int retval = 0;
    RTK_LSADC_VAL_T lsadc_info;
    unsigned int index;
    RTK_ALL_LSADC_PIN_T *pcbInfo = NULL;
    if(m_ioctl_enable == 0)
        return retval;
    if(cmd != RTK_LSADC_DUMP){
        if (copy_from_user(&lsadc_info, (void __user *)arg,
               sizeof(RTK_LSADC_VAL_T))) {
        return -EFAULT;
        }
        retval = rtk_lsadc_get_index_byName(lsadc_info.pin_name,&index);

        LSADC_DEBUG("piname = %s,val = %u,index=%u ",lsadc_info.pin_name,lsadc_info.val,index);

        if(index < 0)
            return index;
    }
    LSADC_DEBUG("%s() enter\n", __FUNCTION__);
    switch (cmd) {
    case RTK_LSADC_GET_ADCVAL:
        if(0 != rtk_lsadc_get_adcValue(index,&lsadc_info.val))
            return  -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_SET_ACTIVE:
        retval = rtk_lsadc_set_active(index,lsadc_info.val);
        break;
    case RTK_LSADC_SET_TRESHOLD:
        retval = rtk_lsadc_set_threshold(index,lsadc_info.val);
        break;
    case RTK_LSADC_SET_SW:
        retval = rtk_lsadc_set_padSwitch(index,lsadc_info.val);
        break;
    case RTK_LSADC_SET_MODE:
        retval = rtk_lsadc_set_voltageMode(index,lsadc_info.val);
        break;
    case RTK_LSADC_GET_ACTIVE:
        if(0 != rtk_lsadc_get_activeStatus(index,&lsadc_info.val))
            return -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_GET_THRESHOLD:
        if(0 != rtk_lsadc_get_threshold(index,&lsadc_info.val))
            return -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_GET_SW:
        if(0 != rtk_lsadc_get_padSwitch(index,&lsadc_info.val))
            return -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_GET_MODE:
        if(0 != rtk_lsadc_get_voltageMode(index,&lsadc_info.val))
            return -EFAULT;
        retval = copy_to_user((void __user *)arg, &lsadc_info, sizeof(RTK_LSADC_VAL_T));
        break;
    case RTK_LSADC_DUMP:
        pcbInfo = (RTK_ALL_LSADC_PIN_T*)kmalloc(sizeof(RTK_ALL_LSADC_PIN_T), GFP_KERNEL);
        memset(pcbInfo, 0 ,sizeof(RTK_ALL_LSADC_PIN_T));
        rtk_lsadc_dump_all_pininfo(pcbInfo);
        retval = copy_to_user((void __user *)arg, pcbInfo, sizeof(RTK_ALL_LSADC_PIN_T));
        kfree(pcbInfo);
        break;

    default:
        retval = -ENOTTY;
    }

    LSADC_DEBUG("%s() exit\n", __FUNCTION__);

    return retval;
}
#endif

static struct file_operations rtk_lsadc_fops = {
    .owner = THIS_MODULE,
    .read = rtk_lsadc_read,
    .write = rtk_lsadc_write,
    .unlocked_ioctl = rtk_lsadc_ioctl,
    .release = rtk_lsadc_release,
    .open = rtk_lsadc_open,
#ifdef CONFIG_COMPAT
    .compat_ioctl = rtk_lsadc_compat_ioctl,
#endif
};


static const struct of_device_id rtk_lsadc_devices[] = {
    {.compatible = "rtk-lsadc",},
    {},
};

static struct platform_driver rtk_lsadc_driver = {
    .driver = {
            .name = "rtk-lsadc",
            .owner = THIS_MODULE,
            .of_match_table = of_match_ptr(rtk_lsadc_devices),
            #ifdef CONFIG_PM
            .pm    = &rtk_lsadc_pm_ops,
            #endif
        },
    .probe = rtk_lsadc_probe,
    .remove = rtk_lsadc_remove,
};

static int register_lsadc_cdev(void) {
    dev_t dev;
    int ret = 0;


    ret = alloc_chrdev_region(&dev, 0, 1, "lsadc");
    if (ret) {
        LSADC_ERROR("can't alloc chrdev\n");
        return -1;
    }

    lsadc_dev_major = MAJOR(dev);
    lsadc_dev_minor = MINOR(dev);


    dev_cdevp_lsadc = kzalloc(sizeof(struct cdev), GFP_KERNEL);
    if (dev_cdevp_lsadc == NULL) {
        LSADC_ERROR("kzalloc failed\n");
        goto FAIL_TO_ALLOCATE_LSADC_CDEV;
    }
    cdev_init(dev_cdevp_lsadc, &rtk_lsadc_fops);
    dev_cdevp_lsadc->owner = THIS_MODULE;
    dev_cdevp_lsadc->ops = &rtk_lsadc_fops;
    ret = cdev_add(dev_cdevp_lsadc, MKDEV(lsadc_dev_major, lsadc_dev_minor), 1);
    if (ret < 0) {
        LSADC_WARN(" add chr dev failed\n");
        goto FAIL_TO_ADD_LSADC_CDEV;
    }

    lsadc_device_st = device_create(_gstlsadc_class, NULL, MKDEV(lsadc_dev_major, lsadc_dev_minor), NULL, "rtkLsadc0");
    ret = rtk_lsadc_create_class_attr(_gstlsadc_class);
    ret = rtk_lsadc_dev_attr_init(_gstlsadc_class);
    if(lsadc_device_st == NULL) {
        LSADC_WARN(" device create lsadc dev failed\n");
        goto FAIL_TO_CREATE_LSADC_DEVICE;
    }
    LSADC_WARN("register chrdev(%d,%d) success.\n", lsadc_dev_major, lsadc_dev_minor);
    return 0;
    
FAIL_TO_CREATE_LSADC_DEVICE:
    rtk_lsadc_dev_attr_unint();
    rtk_lsadc_remove_class_attr(_gstlsadc_class);
    cdev_del(dev_cdevp_lsadc);
FAIL_TO_ADD_LSADC_CDEV:
    if(dev_cdevp_lsadc) {
        kfree(dev_cdevp_lsadc);
        dev_cdevp_lsadc = NULL;
    }
FAIL_TO_ALLOCATE_LSADC_CDEV:
    unregister_chrdev_region(MKDEV(lsadc_dev_major, lsadc_dev_minor), 1);
    lsadc_dev_major = 0;
    lsadc_dev_minor = 0;
    return -1;

}


static int unregister_lsadc_cdev(void)
{
    rtk_lsadc_remove_class_attr(_gstlsadc_class);
    rtk_lsadc_dev_attr_unint();
    device_destroy(_gstlsadc_class, MKDEV(lsadc_dev_major, lsadc_dev_minor));
    cdev_del(dev_cdevp_lsadc);
    kfree(dev_cdevp_lsadc);
    dev_cdevp_lsadc = NULL;
    unregister_chrdev_region(MKDEV(lsadc_dev_major, lsadc_dev_minor), 1);
    lsadc_dev_major = 0;
    lsadc_dev_minor = 0;
    return 0;

}



int __init rtk_lsadc_dev_init(void)
{
    int ret = 0;
    LSADC_ClockEnable(1);
    ret = platform_driver_register(&rtk_lsadc_driver);
    if (ret != 0)
        goto FAILED_REGISTER_PLATFORM_DRIVER;

    _gstlsadc_class = class_create(THIS_MODULE, "rtk-lsadc");

    if (_gstlsadc_class == NULL)
        goto FAILED_CREATE_GSTLSADC_CLASS;

    pst_rtk_lsadc_platform_dev =platform_device_register_simple("rtk-lsadc", -1, NULL, 0);
    if (pst_rtk_lsadc_platform_dev == NULL)
        goto FAILED_REGISTER_PLATFORM_DEVICE;

    rtk_hw_setting_adc_init();

    if(register_lsadc_cdev() != 0)
        goto FAILED_REGISTER_LSADC_CDEV;

    LSADC_INFO( "[%s] LSADC device init ok !\n", __func__);

    return 0;
    
FAILED_REGISTER_LSADC_CDEV:
    platform_device_unregister(pst_rtk_lsadc_platform_dev);
FAILED_REGISTER_PLATFORM_DEVICE:
    device_destroy(_gstlsadc_class, MKDEV(0, 0));
    class_destroy(_gstlsadc_class);
FAILED_CREATE_GSTLSADC_CLASS:
    platform_driver_unregister(&rtk_lsadc_driver);
FAILED_REGISTER_PLATFORM_DRIVER:
    LSADC_ClockEnable(0);
    LSADC_ERROR( "[%s] ======================================\n",__func__);
    LSADC_ERROR( "[%s] LSADC Register Error!\n", __func__);
    LSADC_ERROR( "[%s] ======================================\n",__func__);
    return -1;


}

static void __exit rtk_lsadc_dev_uninit(void)
{
    unregister_lsadc_cdev();
    platform_device_unregister(pst_rtk_lsadc_platform_dev);
    device_destroy(_gstlsadc_class, MKDEV(0, 0));
    class_destroy(_gstlsadc_class);
    platform_driver_unregister(&rtk_lsadc_driver);
    LSADC_ClockEnable(0);
}

module_init(rtk_lsadc_dev_init);
module_exit(rtk_lsadc_dev_uninit);
MODULE_AUTHOR("Banghui_yin, Realtek Semiconductor");
MODULE_LICENSE("GPL");


