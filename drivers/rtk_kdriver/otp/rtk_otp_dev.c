#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/miscdevice.h>
#include <linux/compat.h>
#include <rtk_kdriver/rtk_otp_util.h>
#include "rtk_otp_dev.h"

/*------------------------------------------------------------------
 * Func : otp_dev_open
 *
 * Desc : open function of otp dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int otp_dev_open(struct inode *inode, struct file *file)
{
    return 0;
}

/*------------------------------------------------------------------
 * Func : otp_dev_release
 *
 * Desc : release function of otp dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int otp_dev_release(struct inode *inode, struct file *file)
{
    return 0;
}

/*------------------------------------------------------------------
 * Func : otp_dev_read
 *
 * Desc : read function of otp dev
 *
 * Parm : file  : context of file
 *        buff  : rx buffer addr
 *        size  : rx buffer size
 *        ofst  : read offset
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
ssize_t otp_dev_read(struct file *file,
                     char __user *buff, size_t size, loff_t *ofst)
{
    return 0;
}

/*------------------------------------------------------------------
 * Func : otp_dev_write
 *
 * Desc : write function of otp dev
 *
 * Parm : file  : context of file
 *        buff  : tx buffer addr
 *        size  : tx buffer size
 *        ofst  : write offset
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
ssize_t otp_dev_write(struct file *file,
                      const char __user *buff, size_t size, loff_t *ofst)
{
    return 0;
}


/*------------------------------------------------------------------
 * Func : otp_dev_ioctl
 *
 * Desc : ioctl function of otp dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long otp_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{

    int ret = 0;

    switch (cmd) {
        case OTP_CMD_READ: {
            unsigned char *buf = NULL;
            RTK_OTP_RW otp_rw_data;
            if((RTK_OTP_RW __user *) arg == NULL)
                return -EFAULT;
            if (copy_from_user
                (&otp_rw_data, (void __user *)arg, sizeof(otp_rw_data)))
                return -EFAULT;
            if(otp_rw_data.len == 0 || otp_rw_data.data == NULL)
                return -EFAULT;
            // KWarning: checked ok by liangliang_song@apowertec.com
            buf = (unsigned char *)kmalloc(otp_rw_data.len, GFP_KERNEL);
            if(!buf)
                return -ENOMEM;
            if(otp_read_region_byte(otp_rw_data.addr, buf, otp_rw_data.len) != 0)
                ret = -EIO;
            else
                ret = copy_to_user(otp_rw_data.data, buf, otp_rw_data.len);
            kfree(buf);
            return ret;
        }
        case OTP_CMD_AUTO_CRC: {
            unsigned int crc_value = 0x0;
            if((void __user *) arg == NULL)
                return -EFAULT;
            if(otp_crc_auto_region(&crc_value) != 0)
                ret = -1;
            else
                ret = copy_to_user(arg, &crc_value, sizeof(unsigned int));
            return ret;
        }
        case OTP_CMD_PARTIAL_CRC: {
            RTK_OTP_PARTIAL_CRC otp_partial_crc_data;
            if((RTK_OTP_PARTIAL_CRC __user *) arg == NULL)
                return -EFAULT;
            if (copy_from_user
                (&otp_partial_crc_data, (void __user *)arg, sizeof(otp_partial_crc_data)))
                return -EFAULT;
            if(otp_partial_crc_data.len == 0)
                return -EFAULT;
            if(otp_crc_partial_region(otp_partial_crc_data.addr,
                                      otp_partial_crc_data.len, &otp_partial_crc_data.crc_value) != 0)
                ret = -EIO;
            else
                ret = copy_to_user((void __user *)arg, &otp_partial_crc_data, sizeof(otp_partial_crc_data));
            return ret;
        }
        default: {
            return -EFAULT;
        }
    }
}

/*------------------------------------------------------------------
 * Func : otp_compat_dev_ioctl
 *
 * Desc : ioctl function of otp dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
#ifdef CONFIG_COMPAT
static
long otp_compat_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{

    int ret = 0;

    switch (cmd) {
        case COMPAT_OTP_CMD_READ: {
            COMPAT_RTK_OTP_RW otp_rw_data;
            unsigned char *buf = NULL;
            if((COMPAT_RTK_OTP_RW __user *) arg == NULL)
                return -EFAULT;
            if (copy_from_user
                (&otp_rw_data, (COMPAT_RTK_OTP_RW __user *) arg,
                 sizeof(otp_rw_data)))
                return -EFAULT;
            if(otp_rw_data.len == 0 || compat_ptr(otp_rw_data.data) == NULL)
                return -EFAULT;
            // KWarning: checked ok by liangliang_song@apowertec.com
            buf = (unsigned char *)kmalloc(otp_rw_data.len, GFP_KERNEL);
            if(!buf)
                return -ENOMEM;
            if(otp_read_region_byte(otp_rw_data.addr, buf, otp_rw_data.len) != 0)
                ret = -EIO;
            else
                ret = copy_to_user(compat_ptr(otp_rw_data.data),
                                   buf, otp_rw_data.len);
            kfree(buf);
            return ret;
        }
        case OTP_CMD_AUTO_CRC: {
            unsigned int crc_value = 0x0;
            if((void __user *) arg == NULL)
                return -EFAULT;
            if(otp_crc_auto_region(&crc_value) != 0)
                ret = -1;
            else
                ret = copy_to_user(arg, &crc_value, sizeof(unsigned int));
            return ret;
        }
        case OTP_CMD_PARTIAL_CRC: {
            RTK_OTP_PARTIAL_CRC otp_partial_crc_data;
            if((RTK_OTP_PARTIAL_CRC __user *) arg == NULL)
                return -EFAULT;
            if (copy_from_user
                (&otp_partial_crc_data, (void __user *)arg, sizeof(otp_partial_crc_data)))
                return -EFAULT;
            if(otp_partial_crc_data.len == 0)
                return -EFAULT;
            if(otp_crc_partial_region(otp_partial_crc_data.addr,
                                      otp_partial_crc_data.len, &otp_partial_crc_data.crc_value) != 0)
                ret = -EIO;
            else
                ret = copy_to_user((void __user *)arg, &otp_partial_crc_data, sizeof(otp_partial_crc_data));
            return ret;
        }
        default: {
            return -EFAULT;
        }
    }
}
#endif

static struct file_operations otp_dev_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = otp_dev_ioctl,
    .open = otp_dev_open,
    .read = otp_dev_read,
    .write = otp_dev_write,
    .release = otp_dev_release,
#ifdef CONFIG_COMPAT
    .compat_ioctl = otp_compat_dev_ioctl,
#endif
};

/*
 * module Init
 */
static struct miscdevice rtk_otp_miscdev = {
    MISC_DYNAMIC_MINOR,
    "otp",
    &otp_dev_fops
};

/*------------------------------------------------------------------
 * Func : otp_dev_module_init
 *
 * Desc : otp dev init function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int __init otp_dev_module_init(void)
{
    int ret = 0;
    if (misc_register(&rtk_otp_miscdev)) {
        OTP_WARNING("rtk_otp_module_init failed - register misc device failed\n");
        ret = -ENODEV;
    }
    return ret;
}

/*------------------------------------------------------------------
 * Func : otp_dev_module_exit
 *
 * Desc : otp dev module exit function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
void __exit otp_dev_module_exit(void)
{
    misc_deregister(&rtk_otp_miscdev);
}
module_init(otp_dev_module_init);
module_exit(otp_dev_module_exit);
MODULE_AUTHOR("liangliang song, Apowertec Semiconductor");
MODULE_LICENSE("GPL");

