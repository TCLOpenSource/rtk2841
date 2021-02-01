/******************************************************************************
*
*   Copyright(c) 2016 Realtek Semiconductor Corp. All rights reserved.
*
*   @author realtek.com
*
******************************************************************************/
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/dma-mapping.h>
#include <linux/sched.h>
#include <linux/ioctl.h>
#include <mach/io.h>
#include <linux/miscdevice.h>
#include <rtk_kdriver/mcp/rtk_rcp.h>
#include "rtk_rcp_dbg.h"
#include "rtk_rcp_dev.h"


static DEFINE_MUTEX(rtk_rcp_pre_buffer_mutex);
#define RCP_PRE_BUFFER_LOCK()              mutex_lock(&rtk_rcp_pre_buffer_mutex)
#define RCP_PRE_BUFFER_UNLOCK()            mutex_unlock(&rtk_rcp_pre_buffer_mutex)

#define RCP_PRE_ALLOCATED_BUFFER_LEN        PAGE_SIZE
static unsigned char *rcp_pre_allocated_buffer;

extern int rtk_rcp_do_command(RCP_DESC * p_desc);

struct device *rcp_device;

bool rcp_dbg_onoff = false;

static int rtk_rcp_dev_open(struct inode* inode, struct file* filp)
{
    return 0;
}

static int rtk_rcp_dev_release(struct inode* inode, struct file* filp)
{
    return 0;
}

static ssize_t rtk_rcp_dev_read(struct file *filp, char __user *buf,
                                size_t count, loff_t  *f_pos)
{
    return -EFAULT;
}

ssize_t rtk_rcp_dev_write(struct file *filp, const char __user *buf,
                          size_t count, loff_t *f_pos)
{
    return -EFAULT;
}

static unsigned char * rtk_rcp_allocate_buffer(unsigned int len)
{
    if(len <= RCP_PRE_ALLOCATED_BUFFER_LEN) {
        RCP_PRE_BUFFER_LOCK();
        return rcp_pre_allocated_buffer;
    } else {
        return kmalloc(len, GFP_KERNEL);
    }
}
static void rtk_rcp_release_buffer(unsigned char *buffer, unsigned int len)
{
    if(len <= RCP_PRE_ALLOCATED_BUFFER_LEN) {
        RCP_PRE_BUFFER_UNLOCK();
    } else {
        kfree(buffer);
    }
}


int rtk_rcp_do_command_user(RCP_DESC_USER __user * p_desc)
{
    int i = 0;
    int ret = -1;
    unsigned char *buffer = NULL;
    RCP_DESC_USER desc_user;
    RCP_DESC desc;
    unsigned long user_data_out = 0;
    unsigned long user_data_in = 0;
    
    if (p_desc == NULL)
        goto fail;
        
    memset(&desc_user, 0, sizeof(RCP_DESC_USER));
    memset(&desc, 0, sizeof(RCP_DESC));

    if(copy_from_user(&desc_user, (RCP_DESC_USER __user *)p_desc, sizeof(RCP_DESC_USER))) {
        RCP_WARNING("do ioctl command failed - copy desc from user failed\n");
        goto fail;
    }

    if(desc_user.len == 0 || desc_user.data_in == NULL || desc_user.data_out == NULL)
        goto fail;

    desc.flags = desc_user.flags;

    if(RCP_KEY_FROM(desc_user.flags) == RCP_KEY_FROM_OTP) {
        desc.key = NULL;
    } else if(RCP_KEY_FROM(desc_user.flags) == RCP_KEY_FROM_CW) {
        desc.key = desc_user.key[0];
    } else {
        desc.key = desc_user.key;
    }

    if(RCP_IV_FROM(desc_user.flags) == RCP_IV_FROM_OTP) {
        desc.iv = NULL;
    } else if(RCP_IV_FROM(desc_user.flags) == RCP_IV_FROM_CW) {
        desc.iv = desc_user.iv[0];
    } else {
        desc.iv = desc_user.iv;
    }

    desc.len = desc_user.len;
    desc.data_out = desc_user.data_out;
    desc.data_in = desc_user.data_in;

    user_data_out = (unsigned long)desc_user.data_out;
    user_data_in = (unsigned long)desc_user.data_in;

    /*only for aes ctr cipher*/    
    if(RCP_CHECK_ADDR_ALIGN(desc_user.flags) == RCP_NEED_CHECK_ADDR_ALIGN)
        desc.addr_align = ((user_data_in & 0x3) || (user_data_out & 0x3)) ? 0 : 1; 


    if(user_data_out > MAX_CW_ENTRY || user_data_in > MAX_CW_ENTRY) {
        //KWarning: checked ok by qibing_huang@apowertec.com
        buffer = rtk_rcp_allocate_buffer(desc.len);
        if(buffer == NULL)
            goto fail;
        if((unsigned long)desc.data_in > MAX_CW_ENTRY) {
            if(copy_from_user(buffer, (void __user *)desc.data_in, desc.len)) {
                RCP_WARNING("do ioctl command failed - copy data from user failed\n");
                goto fail;
            }
            desc.data_in = buffer;
        }
        if((unsigned long)desc.data_out > MAX_CW_ENTRY)
            desc.data_out = buffer;
    }


    ret = rtk_rcp_do_command(&desc);
    desc_user.out_len = desc.out_len;
    if(ret == 0) {
        if(user_data_out > MAX_CW_ENTRY) {
            if(copy_to_user((void __user *)user_data_out, buffer, desc_user.out_len)) {
                RCP_WARNING("do ioctl command failed - copy data to user failed\n");
                ret = -1;
                goto fail;
            }
        }
        if(copy_to_user((void __user *)p_desc, &desc_user, sizeof(RCP_DESC_USER))) {
            ret = -1;
            RCP_WARNING("do ioctl command failed - copy data to user failed\n");
            goto fail;
        }
        if(RCP_IV_POST_CRYPT(desc_user.flags) == RCP_IV_NEED_UPDATE
            && RCP_IV_FROM(desc_user.flags) == RCP_IV_FROM_DDR) {
            if(copy_to_user((void __user *)p_desc->iv, desc.iv , 32)) {
                ret = -1;
                RCP_WARNING("do ioctl command failed - copy data to user failed\n");
                goto fail;
            }
        }
    }
fail:
    if(buffer != NULL)
        rtk_rcp_release_buffer(buffer, desc.len);
    return ret;
}



static long rtk_rcp_dev_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    int retval = 0;
    RCP_DESC desc;
    switch(cmd) {
        case RCP_IOCTL_DO_COMMAND:
            return rtk_rcp_do_command_user((RCP_DESC_USER __user *)arg);
            break;
        default:
            retval = -ENOTTY;
            break;
    }
    return retval;
}

#ifdef CONFIG_COMPAT
static long rtk_rcp_dev_compat_ioctl(struct file *filp, unsigned int cmd,
                                     unsigned long arg)
{
    return rtk_rcp_dev_ioctl(filp, cmd, arg);
}
#endif

struct file_operations rcp_fops = {
    .owner                  = THIS_MODULE,
    .read                   = rtk_rcp_dev_read,
    .write                  = rtk_rcp_dev_write,
    .unlocked_ioctl         = rtk_rcp_dev_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl           = rtk_rcp_dev_compat_ioctl,
#endif
    .open                   = rtk_rcp_dev_open,
    .release                = rtk_rcp_dev_release,
};


static ssize_t rtk_rcp_debug_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return 0;
}

static ssize_t rtk_rcp_debug_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t n)
{
    extern void do_rcp_function_test(void);
    do_rcp_function_test();
    return -EINVAL;
}

struct kobject *rcp_kobj;
#define rcp_attr(_name) \
static struct kobj_attribute _name##_attr = {   \
    .attr   = {                             \
    .name = __stringify(_name),     \
    .mode = 0644,                   \
    },                                      \
    .show   = rtk_rcp_debug_show,                        \
    .store  = rtk_rcp_debug_store,               \
}

rcp_attr(rcp_dbg_onoff);
rcp_attr(rcp_test_case);
static struct attribute * rcp_attrs[] = {
    &rcp_dbg_onoff_attr.attr,
    &rcp_test_case_attr.attr,
    NULL,
};

static struct attribute_group rcp_attr_group = {
    .attrs = rcp_attrs,
};


static struct miscdevice rcp_miscdev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = RCP_DEV_NAME,
    .fops = &rcp_fops,
    .mode = 0666,

};

static int rtk_rcp_setup_cdev(void)
{
    int ret = 0;
    if (misc_register(&rcp_miscdev)) {
        RCP_ERR("register rcp misc dev file failed\n");
        ret = -ENODEV;
        goto FAIL_REGISTER_MISC_DEV;
    }

    rcp_kobj = kobject_create_and_add("rcp", NULL);
    if(!rcp_kobj) {
        ret = -ENOMEM;
        goto FAIL_KOBJECT_CREATE;
    }

    ret = sysfs_create_group(rcp_kobj, &rcp_attr_group);
    if(ret != 0) {
        goto FAIL_SYSFS_CREATE_GROUP;
    }
    return 0;

FAIL_SYSFS_CREATE_GROUP:
    kobject_put(rcp_kobj);
FAIL_KOBJECT_CREATE:
    misc_deregister(&rcp_miscdev);
FAIL_REGISTER_MISC_DEV:
    return ret;
}

static void rtk_rcp_unsetup_cdev(void)
{
    kobject_put(rcp_kobj);
    misc_deregister(&rcp_miscdev);
}


__init int rtk_rcp_dev_init(void)
{
    int ret = 0;
    rcp_pre_allocated_buffer = kmalloc(RCP_PRE_ALLOCATED_BUFFER_LEN, GFP_KERNEL);
    if(!rcp_pre_allocated_buffer) {
        RCP_ERR("allocate buffer failed\n");
        return -ENOMEM;
    }
    ret = rtk_rcp_setup_cdev();
    if(ret != 0) {
        kfree(rcp_pre_allocated_buffer);
        rcp_pre_allocated_buffer = NULL;
    }
    return ret;
}

__exit void rtk_rcp_dev_exit(void)
{
    rtk_rcp_unsetup_cdev();
    kfree(rcp_pre_allocated_buffer);
    rcp_pre_allocated_buffer = NULL;
}


