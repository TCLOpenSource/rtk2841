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
#include <linux/freezer.h>
#include <linux/slab.h>
#include <linux/wait.h>
#include <linux/delay.h>
#include <linux/string.h>
#include <mach/platform.h>
#include <asm/uaccess.h>        /* copy_*_user */
#include <rtk_kdriver/pcbMgr.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_gpio-dev.h>
#include <rtk_kdriver/rtk_gpio-db.h>
#include <rtk_kdriver/rtk_gpio-chipset.h>
#ifdef CONFIG_RTK_KDRV_GPIO_WITH_SYSFS_DEBUG
#include <rtk_kdriver/rtk_gpio-attr.h>
#endif
#include "rtk_gpio-reg.h"
#include <rtk_gpio-debug.h>


static RTK_GPIO_DEV_DATA rtk_gpio_dev_data[2];
Array RTK_GPIO_DB;
int bShowStrMessage = Disable_MSG;



/*-------------------------------------------------------------------------*/
static void mis_gpio_ioctl_isr(RTK_GPIO_ID gid, unsigned char assert, void *dev)
{
    int ret = 0;
    RTK_GPIO_DEV_DATA *p_this = (RTK_GPIO_DEV_DATA *) dev;
    ret = kfifo_out(&p_this->fifo, (void *)&gid, sizeof(int));
    if (ret != sizeof(int))
        RTK_GPIO_INFO("B:%s-%s , kfifo_out return value %d\n", __FILE__,
               __func__, ret);

}


/*--------------------------------------------------------------------------
 * File Operations
 *-------------------------------------------------------------------------*/


static int rtk_gpio_open(struct inode *inode, struct file *file)
{
    RTK_GPIO_DEV_DATA *p_this = NULL;

    if (iminor(inode) == rtk_gpio_dev_data[0].minor)
        p_this = &rtk_gpio_dev_data[0];
    else if (iminor(inode) == rtk_gpio_dev_data[1].minor)
        p_this = &rtk_gpio_dev_data[1];
    else {
        RTK_GPIO_INFO
            ("rtk_gpio_open failed, invalid device minor number %d\n",
             iminor(inode));
        return -EFAULT;
    }

    kfifo_reset(&p_this->fifo);
    file->private_data = (void *)p_this;
    return 0;
}



static int rtk_gpio_release(struct inode *inode, struct file *file)
{
    /* do nothing */
    return 0;
}


static ssize_t rtk_gpio_read(struct file *filp, char __user *buf,
                             size_t count, loff_t *f_pos)
{
    RTK_GPIO_DEV_DATA *p_this = (RTK_GPIO_DEV_DATA *) filp->private_data;
    char uintBuf;
    int i, readCount = count, ret = 0;

restart:

    if (wait_event_interruptible(p_this->wq, kfifo_len(&p_this->fifo) > 0) != 0) {
        if (unlikely(current->flags & PF_FROZEN)) {
            freeze_processes();
            /* refrigerator() */
            goto restart;
        }

        return -ERESTARTSYS;
    }

    if (kfifo_len(&p_this->fifo) < count)
        readCount = kfifo_len(&p_this->fifo);

    for (i = 0; i < readCount; i++) {
        ret = kfifo_out(&p_this->fifo, (void *)&uintBuf, sizeof(char));
        if (ret != sizeof(char))
            RTK_GPIO_WARNING("B:%s-%s , kfifo_out return value %d\n",
                             __FILE__, __func__, ret);

        ret = copy_to_user((void *)buf, (void *)&uintBuf, sizeof(char));

        if (ret != 0)
            RTK_GPIO_WARNING("B:%s-%s , copy_to_user return value %d\n",
                             __FILE__, __func__, ret);
        buf++;
    }

    return readCount;
}


static unsigned int rtk_gpio_poll(struct file *filp, poll_table *wait)
{
    RTK_GPIO_DEV_DATA *p_this = (RTK_GPIO_DEV_DATA *) filp->private_data;

    poll_wait(filp, &p_this->wq, wait);

    if (kfifo_len(&p_this->fifo) > 0)
        return POLLIN | POLLRDNORM;

    return 0;
}

static long rtk_gpio_ioctl(struct file *file,
                           unsigned int cmd, unsigned long arg)
{
    int err = 0;
    int ret = 0;
    RTK_GPIO_PCBINFO_T pinInfo;
    RTK_GPIO_VAL_T gpio_val;
    RTK_GPIO_DIR_T gpio_dir;
    RTK_GPIO_IRQ_SET_T gpio_irq_set;
    RTK_GPIO_IRQ_EN_T gpio_irq_en;
    RTK_GPIO_IRQ_FLAG_T gpio_irq_flag;
    RTK_GPIO_GET_ALL_GPIO_PIN_T gpio_all_gpio_pin;

    if ((_IOC_TYPE(cmd) != RTK_GPIO_IOC_MAGIC) ||
        (_IOC_NR(cmd) > RTK_GPIO_IOC_MAXNR))
        return -ENOTTY;

    if (_IOC_DIR(cmd) & _IOC_READ)
        err = !access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd));
    else if (_IOC_DIR(cmd) & _IOC_WRITE)
        err = !access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd));

    if (err)
        return -EFAULT;

#ifndef CONFIG_RTK_KDRV_GPIO_IGNORE_ADMIN_CHECK
    if (!capable(CAP_SYS_ADMIN))
        return -EPERM;
#endif

    switch (cmd) {

        case RTK_GPIO_SET_VAL:
            if (copy_from_user ((void *)&gpio_val, (const void __user *)arg, sizeof(RTK_GPIO_VAL_T))) {
                ret = -EFAULT;
                break;
            }
            ret = rtk_gpio_get_pcb_info(gpio_val.pin_name,&pinInfo);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_SET_VAL: can not find the pin:%s ,please check bootcode pcbenmu!!\n",gpio_val.pin_name);
                return GPIO_PIN_UNDEFINED;
            }

            ret = rtk_gpio_output(pinInfo.gid,gpio_val.val);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_SET_VAL: input PIN can not set to output,gpio_type=%s,pin:%s ,please check bootcode pcbenmu!!\n",gpio_type(pinInfo.gpio_type),gpio_val.pin_name);
                return GPIO_TYPE_WRONG;
            }

            ret =  rtk_gpio_set_dir(pinInfo.gid,GPIO_OUTPUT);

            break;

        case RTK_GPIO_GET_VAL:
            if (copy_from_user ((void *)&gpio_val, (const void __user *)arg, sizeof(RTK_GPIO_VAL_T))) {
                return -EFAULT;
            }
            ret = rtk_gpio_get_pcb_info(gpio_val.pin_name,&pinInfo);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_VAL: can not find the pin:%s ,please check bootcode pcbenmu!!\n",gpio_val.pin_name);
                return GPIO_PIN_UNDEFINED;
            }
            if(pinInfo.input_type==PCB_GPIO_TYPE_OUPUT){
                ret = rtk_gpio_output_get(pinInfo.gid);
                if(ret<0){
                    RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_VAL: input PIN can'nt get output value,gpio_type=%s,pin:%s ,please check bootcode pcbenmu!!\n",gpio_type(pinInfo.gpio_type),gpio_val.pin_name);
                    return GPIO_TYPE_WRONG;
                }
            }else{
                ret = rtk_gpio_input(pinInfo.gid);
                if(ret<0){
                    RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_VAL: output PIN can'nt get input value,gpio_type=%s,pin:%s ,please check bootcode pcbenmu!!\n",gpio_type(pinInfo.gpio_type),gpio_val.pin_name);
                    return GPIO_TYPE_WRONG;
                }
            }
            gpio_val.val = ret;

            ret = copy_to_user((void __user *)arg,(void *)&gpio_val ,sizeof(RTK_GPIO_VAL_T));
            if ( ret != 0 ) {
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_VAL: , copy data to user space failed, ret = 0x%X\n", ret);
                return -EFAULT;
            }

            break;
        case RTK_GPIO_SET_DIR:
            if (copy_from_user ((void *)&gpio_dir, (const void __user *)arg, sizeof(RTK_GPIO_DIR_T))) {
                return -EFAULT;
            }
            ret = rtk_gpio_get_pcb_info(gpio_dir.pin_name,&pinInfo);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_SET_DIR: can not find the pin:%s ,please check bootcode pcbenmu!!\n",gpio_dir.pin_name);
                return GPIO_PIN_UNDEFINED;
            }
            ret = rtk_gpio_set_dir(pinInfo.gid,gpio_dir.dir);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_SET_DIR: only MIS_GPIO & ISO_GPIO can set direction,gpio_type=%s,pin:%s ,please check bootcode pcbenmu!!\n",gpio_type(pinInfo.gpio_type),gpio_dir.pin_name);
                return GPIO_TYPE_WRONG;
            }
            break;

        case RTK_GPIO_GET_DIR:
            if (copy_from_user( (void *)&gpio_dir, (const void __user *)arg, sizeof(RTK_GPIO_DIR_T)))
                return -EFAULT;

            ret = rtk_gpio_get_pcb_info(gpio_dir.pin_name,&pinInfo);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_DIR: can not find the pin:%s ,please check bootcode pcbenmu!!\n",gpio_dir.pin_name);
                return GPIO_PIN_UNDEFINED;
            }

            ret = rtk_gpio_get_dir(pinInfo.gid);

            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_DIR: only MIS_GPIO & ISO_GPIO can get direction,gpio_type=%s,pin:%s ,please check bootcode pcbenmu!!\n",gpio_type(pinInfo.gpio_type),gpio_dir.pin_name);
                return GPIO_TYPE_WRONG;
            }

            gpio_dir.dir = ret;

            ret = copy_to_user((void __user *)arg, (void *)&gpio_dir , sizeof(RTK_GPIO_DIR_T));

            if ( ret != 0 ) {
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_DIR:  copy data to user space failed, ret = 0x%X\n", ret);
                return -EFAULT;
            }
            break;

        case RTK_GPIO_SET_IRQ:
            if (copy_from_user ((void *)&gpio_irq_set, (const void __user *)arg, sizeof(RTK_GPIO_IRQ_SET_T))) {
                return -EFAULT;
            }
            ret = rtk_gpio_get_pcb_info(gpio_irq_set.pin_name,&pinInfo);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_SET_IRQ_PARAM: can not find the pin:%s ,please check bootcode pcbenmu!!\n",gpio_irq_set.pin_name);
                return GPIO_PIN_UNDEFINED;
            }

            if(pinInfo.gpio_type == ISO_GPIO || pinInfo.gpio_type == MIS_GPIO) {
                ret =  rtk_gpio_set_dir(pinInfo.gid,GPIO_INPUT);
            }

            ret = rtk_gpio_set_debounce(pinInfo.gid,gpio_irq_set.debounce);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_SET_IRQ_PARAM: only MIS_GPIO & ISO_GPIO can set debounce,gpio_type=%s,pin:%s ,please check bootcode pcbenmu!!\n",gpio_type(pinInfo.gpio_type),gpio_irq_set.pin_name);
                return GPIO_TYPE_WRONG;
            }
            ret = rtk_gpio_set_irq_polarity(pinInfo.gid, 0);

            //ret = rtk_gpio_set_irq_trigger_type(pinInfo.gid, gpio_irq_set.edge_type);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_SET_IRQ_PARAM: only MIS_GPIO & ISO_GPIO can set debounce,gpio_type=%s,pin:%s ,please check bootcode pcbenmu!!\n",gpio_type(pinInfo.gpio_type),gpio_irq_set.pin_name);
                return GPIO_TYPE_WRONG;
            }

            ret = rtk_gpio_request_irq(pinInfo.gid,rtk_gpio_rtk_int_isr,"RHAL_GPIO_CALLBACK",rtk_gpio_lg_hal_int_isr);		

            if(gpio_irq_set.irq_en){
                ret = rtk_gpio_set_irq_enable(pinInfo.gid,1);
            }

            break;

        case RTK_GPIO_SET_IRQ_EN:
            if (copy_from_user ((void *)&gpio_irq_en, (const void __user *)arg, sizeof(RTK_GPIO_IRQ_EN_T))) {
                return -EFAULT;
            }
            ret = rtk_gpio_get_pcb_info(gpio_irq_en.pin_name,&pinInfo);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_SET_IRQ_EN: can not find the pin:%s ,please check bootcode pcbenmu!!\n",gpio_irq_en.pin_name);
                return GPIO_PIN_UNDEFINED;
            }
            ret = rtk_gpio_set_irq_enable(pinInfo.gid, gpio_irq_en.irq_en);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_SET_IRQ_EN: only MIS_GPIO & ISO_GPIO can set debounce,gpio_type=%s,pin:%s ,please check bootcode pcbenmu!!\n",gpio_type(pinInfo.gpio_type),gpio_irq_en.pin_name);
                return GPIO_TYPE_WRONG;
            }
            break;

        case RTK_GPIO_GET_IRQ_FLAG:
            if (copy_from_user ((void *)&gpio_irq_flag, (const void __user *)arg, sizeof(RTK_GPIO_IRQ_FLAG_T))) {
                return -EFAULT;
            }
            ret = rtk_gpio_get_pcb_info(gpio_irq_flag.pin_name,&pinInfo);
            if(ret<0){
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_IRQ_FLAG: can not find the pin:%s ,please check bootcode pcbenmu!!\n",gpio_irq_flag.pin_name);
                return GPIO_PIN_UNDEFINED;
            }
            ret = rtk_gpio_get_irq_flag_ex(pinInfo.gid, gpio_irq_flag.trigger_type);

            gpio_irq_flag.irq_flag = ret;

            ret = copy_to_user((void __user *)arg, (void *)&gpio_irq_flag , sizeof(RTK_GPIO_IRQ_FLAG_T));

            if ( ret != 0 ) {
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_IRQ_FLAG:  copy data to user space failed, ret = 0x%X\n", ret);
                return -EFAULT;
            }
            break;
        case RTK_GPIO_GET_ALL_GPIO_PIN:
            if (copy_from_user ((void *)&gpio_all_gpio_pin, (const void __user *)arg, sizeof(RTK_GPIO_GET_ALL_GPIO_PIN_T))) {
                return -EFAULT;
            }

            rtk_gpio_get_all_pinInfo(gpio_all_gpio_pin.pinInfo,&gpio_all_gpio_pin.count);
            ret = copy_to_user((void __user *)arg, (void *)&gpio_all_gpio_pin , sizeof(RTK_GPIO_GET_ALL_GPIO_PIN_T));

            if ( ret != 0 ) {
                RTK_GPIO_IOCTL_DBG("RTK_GPIO_GET_IRQ_FLAG:  copy data to user space failed, ret = 0x%X\n", ret);
                return -EFAULT;
            }
            break;

        default:
            ret = -ENOIOCTLCMD;
    }


    return ret;
}


#ifdef CONFIG_COMPAT
static long rtk_gpio_compat_ioctl(struct file *file,
                           unsigned int cmd, unsigned long arg)
{
    void __user *compat_arg = compat_ptr(arg);
    return rtk_gpio_ioctl(file, cmd, compat_arg);
}
#endif

static struct file_operations rtk_gpio_fops = {
    .owner          = THIS_MODULE,
    .unlocked_ioctl = rtk_gpio_ioctl,
    .open           = rtk_gpio_open,
    .poll           = rtk_gpio_poll,
    .read           = rtk_gpio_read,
    .release        = rtk_gpio_release,
#ifdef CONFIG_COMPAT
    .compat_ioctl   = rtk_gpio_compat_ioctl,
#endif
};

/////////////////////////////////////////////////////////////////////////////////
// module Init
/////////////////////////////////////////////////////////////////////////////////

static struct miscdevice rtk_gpio_miscdev = 
{
    MISC_DYNAMIC_MINOR,
    "venus_gpio",
    &rtk_gpio_fops
};

static struct miscdevice rtk_iso_gpio_miscdev = 
{
    MISC_DYNAMIC_MINOR,
    "venus_iso_gpio",
    &rtk_gpio_fops
};

int __init rtk_gpio_dev_init(void)
{
    int ret = 0;

    rtk_gpio_dev_data[0].minor = 0;
    rtk_gpio_dev_data[1].minor = 0;

    if (kfifo_alloc
        (&rtk_gpio_dev_data[0].fifo, FIFO_DEPTH * sizeof(uint32_t),
         GFP_KERNEL)) {
        RTK_GPIO_WARNING
            ("rtk_gpio_dev_init failed, allocate rtk gpio fifo failed\n");
        ret = -ENOMEM;
        goto err_alloc_gpio_fifo_failed;
    }

    if (kfifo_alloc
        (&rtk_gpio_dev_data[1].fifo, FIFO_DEPTH * sizeof(uint32_t),
         GFP_KERNEL)) {
        RTK_GPIO_WARNING
            ("rtk_gpio_dev_init failed, allocate rtk iso gpio fifo failed\n");
        ret = -ENOMEM;
        goto err_alloc_iso_gpio_fifo_failed;
    }

    init_waitqueue_head(&rtk_gpio_dev_data[0].wq);
    init_waitqueue_head(&rtk_gpio_dev_data[1].wq);

    if (misc_register(&rtk_gpio_miscdev)) {
        RTK_GPIO_WARNING
            ("rtk_gpio_dev_init failed, register misc gpio device failed\n");
        ret = -ENODEV;
        goto err_register_misc_gpio_device_failed;
    }

    if (misc_register(&rtk_iso_gpio_miscdev)) {
        RTK_GPIO_WARNING
            ("rtk_gpio_dev_init failed, register iso gpio device failed\n");
        ret = -ENODEV;
        goto err_register_iso_gpio_device_failed;
    }

    rtk_gpio_dev_data[0].minor = rtk_gpio_miscdev.minor;
    rtk_gpio_dev_data[1].minor = rtk_iso_gpio_miscdev.minor;

    // Create GPIO Data Base
    rtk_gpio_array_new(&RTK_GPIO_DB, 128);      // create an empty GPIO data base for latter ise
    rtk_gpio_sort(&RTK_GPIO_DB,RTK_GPIO_DB.count,pin_compare);
    RTK_GPIO_DB.sort_type = SORT_PIN;
    rtk_gpio_syncInfo_toDB();
    rtk_gpio_init_debug_proc();
    // Create SYSFS device attribute for GPIO debug
#ifdef CONFIG_RTK_KDRV_GPIO_WITH_SYSFS_DEBUG
    rtk_gpio_create_attr(rtk_gpio_miscdev.this_device);
    rtk_gpio_create_attr(rtk_iso_gpio_miscdev.this_device);
#endif

    RTK_GPIO_INFO("rtk_gpio_dev_init successed\n");

    return ret;

/* ------------ */

err_register_iso_gpio_device_failed:
    misc_deregister(&rtk_gpio_miscdev);

err_register_misc_gpio_device_failed:
    kfifo_free(&rtk_gpio_dev_data[1].fifo);

err_alloc_iso_gpio_fifo_failed:
    kfifo_free(&rtk_gpio_dev_data[0].fifo);

err_alloc_gpio_fifo_failed:
    return ret;
}

static void __exit rtk_gpio_dev_exit(void)
{
    kfifo_free(&rtk_gpio_dev_data[0].fifo);
    kfifo_free(&rtk_gpio_dev_data[1].fifo);
    misc_deregister(&rtk_gpio_miscdev);
    misc_deregister(&rtk_iso_gpio_miscdev);
    rtk_gpio_uninit_debug_proc();
    // remove SYSFS device attribute for GPIO debug
#ifdef CONFIG_RTK_KDRV_GPIO_WITH_SYSFS_DEBUG
    rtk_gpio_remove_attr(rtk_gpio_miscdev.this_device);
    rtk_gpio_remove_attr(rtk_iso_gpio_miscdev.this_device);
#endif
}

module_init(rtk_gpio_dev_init);
module_exit(rtk_gpio_dev_exit);

MODULE_AUTHOR("Chih-pin Wu, Realtek Semiconductor");
MODULE_LICENSE("GPL");
