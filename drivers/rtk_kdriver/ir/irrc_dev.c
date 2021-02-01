//#include <linux/config.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>       /* DBG_PRINT() */
#include <linux/slab.h>         /* kmalloc() */
#include <linux/fs.h>           /* everything... */
#include <linux/errno.h>        /* error codes */
#include <linux/types.h>        /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>        /* O_ACCMODE */
#include <linux/seq_file.h>
#include <linux/cdev.h>
#include <linux/kfifo.h>
#include <linux/sysfs.h>
#include <linux/poll.h>
#include <linux/wait.h>
#include <linux/jiffies.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/freezer.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/io.h>
#include <mach/io.h>
#include <asm/irq.h>
#include <linux/signal.h>
#include "irrc_common.h"
#include "irrc_core.h"
#include "irrc_dev.h"

extern struct attribute_group ir_attr_group;
static struct kobject *ir_kobj;
static dev_t dev_ir = 0;
static struct cdev ir_cdev;
static struct class *irrp_class;
static struct platform_device *ir_devs;

#ifdef CONFIG_PM
static int ir_pm_suspend(struct platform_device * dev, pm_message_t state)
{
    return ir_core_pm_suspend(dev, state);
}

static int ir_pm_resume(struct platform_device * dev)
{
    return ir_core_pm_resume(dev);
}
#endif

static struct platform_driver ir_platform_driver = {
#ifdef CONFIG_PM
    .suspend    = ir_pm_suspend,
    .resume     = ir_pm_resume,
#endif
    .driver = {
        .name       = "VenusIR",
        .bus        = &platform_bus_type,
    },
} ;

static int ir_open(struct inode * inode, struct file * filp)
{
    return ir_core_open(inode, filp);
}

static ssize_t ir_read(struct file * filp, char __user * buf, size_t count, loff_t *f_pos)
{
    return ir_core_read(filp, buf, count, f_pos);
}

static unsigned int ir_poll(struct file * filp, poll_table * wait)
{
    return ir_core_poll(filp, wait);
}

static long ir_ioctl(struct file * file, unsigned int cmd, unsigned long arg)
{
    int err = 0;
    int retval = 0;
    if (_IOC_TYPE(cmd) != IR_IOC_MAGIC) return -ENOTTY;
    if (_IOC_NR(cmd) > IR_IOC_MAXNR) return -ENOTTY;

    if (_IOC_DIR(cmd) & _IOC_READ)
        err = !access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd));
    else if (_IOC_DIR(cmd) & _IOC_WRITE)
        err =  !access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd));

    if (err)
        return -EFAULT;

    if (!capable (CAP_SYS_ADMIN))
        return -EPERM;

    return ir_core_ioctl(file, cmd, arg);
}

#ifdef CONFIG_COMPAT
static long ir_compat_ioctl(struct file * file, unsigned int cmd, unsigned long arg)
{
    return ir_ioctl(file, cmd, arg);
}
#endif

static struct file_operations ir_fops = {
    .owner = THIS_MODULE,
    .open  = ir_open,
    .read  = ir_read,
    .poll  = ir_poll,
    .unlocked_ioctl = ir_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl = ir_compat_ioctl,
#endif
};

static int __init ir_platform_driver_init(void)
{
    int ret = 0;
    ir_devs = platform_device_register_simple("VenusIR", -1, NULL, 0);
    if(ir_devs == NULL) {
        IR_WARNING(" fail to register platform device.\n");
        ret = -ENOMEM;
        goto FAIL_REGIST_PLATFORM_DEVICE;
    }
    if(platform_driver_register(&ir_platform_driver) != 0) {
        IR_WARNING(" fail to register platform driver.\n");
        ret = -1;
        goto FAIL_REGIST_PLATFORM_DRIVER;
    }
    return ret;
FAIL_REGIST_PLATFORM_DRIVER:
    platform_device_unregister(ir_devs);
    ir_devs = NULL;
FAIL_REGIST_PLATFORM_DEVICE:
    return ret;
}

static void __exit ir_platform_driver_uninit(void)
{
    platform_driver_unregister(&ir_platform_driver);
    platform_device_unregister(ir_devs);
    ir_devs = NULL;

}

static char *irrp_devnode(struct device * dev, mode_t *mode)
{
    if(mode)
        *mode = 0666;
    return NULL;
}

static int __init ir_chardev_init(void)
{
    int result = 0;
    dev_ir = MKDEV(IR_MAJOR, IR_MINOR_RP);
    result = register_chrdev_region(dev_ir, IR_DEVICE_NUM, IR_DEVICE_NAME);
    if(result < 0) {
        IR_DBG( " can't register device number.\n");
        goto FAIL_REGIST_CHADEV_REGION;
    }

    cdev_init(&ir_cdev, &ir_fops);
    if(cdev_add(&ir_cdev, MKDEV(IR_MAJOR, IR_MINOR_RP), 1)) {
        IR_WARNING(" can't add character device for irrp\n");
        result = -ENOMEM;
        goto FAIL_ADD_CHAR_DEV;
    }

    irrp_class = class_create(THIS_MODULE, "irrp");
    if (IS_ERR(irrp_class)) {
        IR_WARNING(" can't class_create irrp\n");
        result = PTR_ERR(irrp_class);
        goto FAIL_CREATE_CLASS;
    }
    irrp_class->devnode = irrp_devnode;
    if(!device_create(irrp_class, NULL, MKDEV(IR_MAJOR, IR_MINOR_RP), NULL, "venus_irrp")) {
        IR_WARNING(" can't create device for irrp\n");
        result = -ENOMEM;
        goto FAIL_CREATE_DEVICE;
    }
    ir_kobj = kobject_create_and_add("venus_ir", NULL);
    if (!ir_kobj) {
        result = -ENOMEM;
        goto FAIL_CREATE_KOBJ;
    }
    result = sysfs_create_group(ir_kobj, &ir_attr_group);
    if (result != 0) {
        goto FAIL_CREATE_SYSFS_GROUP;
    }
    return result;
FAIL_CREATE_SYSFS_GROUP:
    kobject_put(ir_kobj);
    ir_kobj = NULL;
FAIL_CREATE_KOBJ:
    device_destroy(irrp_class, MKDEV(IR_MAJOR, IR_MINOR_RP));
FAIL_CREATE_DEVICE:
    class_destroy(irrp_class);
    irrp_class = NULL;
FAIL_CREATE_CLASS:
    cdev_del(&ir_cdev);
FAIL_ADD_CHAR_DEV:
    unregister_chrdev_region(dev_ir, IR_DEVICE_NUM);
FAIL_REGIST_CHADEV_REGION:
    return result;

}

static void __exit ir_chardev_uninit(void)
{
    kobject_put(ir_kobj);
    ir_kobj = NULL;
    device_destroy(irrp_class, MKDEV(IR_MAJOR, IR_MINOR_RP));
    class_destroy(irrp_class);
    irrp_class = NULL;
    cdev_del(&ir_cdev);
    unregister_chrdev_region(dev_ir, IR_DEVICE_NUM);

}



static __init int ir_drv_module_init(void)
{
    int result;
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    if ((result = venus_ir_input_init()) != 0) {
        IR_WARNING(" fail to register as an input device.\n");
        goto FAIL_IR_INPUT_INIT;
    }
#if defined(CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE)
    if ((result = venus_ir_mouse_init()) != 0) {
        IR_WARNING(" fail to register as an mouse device.\n");
        goto FAIL_IR_MOUSE_INIT;
    }
#endif
#endif
    if((result = ir_core_init()) != 0) {
        goto FAIL_IR_CORE_INIT;
    }
    if((result = ir_chardev_init()) != 0) {
        IR_WARNING(" fail to register chardev.\n");
        goto FAIL_REGIST_CHAR_DEV;
    }
    if((result = ir_platform_driver_init()) != 0) {
        IR_WARNING(" fail to register chardev.\n");
        goto FAIL_REGIST_PLATFORM_DRIVER;
    }
#ifdef CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND
    voice_dev_init();
#endif
    return result;
FAIL_REGIST_PLATFORM_DRIVER:
    ir_chardev_uninit();
FAIL_REGIST_CHAR_DEV:
    ir_core_uninit();
FAIL_IR_CORE_INIT:
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
#if defined(CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE)
    venus_ir_mouse_cleanup();
FAIL_IR_MOUSE_INIT:
#endif
    venus_ir_input_cleanup();
FAIL_IR_INPUT_INIT:
#endif
    return result;
}

void __exit ir_drv_module_exit(void)
{
    ir_platform_driver_uninit();
    ir_chardev_uninit();
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE
    venus_ir_mouse_cleanup();
#endif
    venus_ir_input_cleanup();
#endif

#ifdef CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND
    voice_dev_uninit();
#endif
    ir_core_uninit();

}

module_init(ir_drv_module_init);
module_exit(ir_drv_module_exit);

