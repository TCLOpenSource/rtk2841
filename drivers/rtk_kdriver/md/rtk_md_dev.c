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
#include <rtk_kdriver/md/rtk_md_debug.h>
#include <rtk_kdriver/md/rtk_md_dev.h>
#include <rtk_kdriver/md/rtk_md_platform.h>
#include <rtk_kdriver/md/rtk_md.h>
#include <rtk_kdriver/md/rtk_md_test.h>

#define MD_DEV_NAME "md0"

struct device *md_device;

bool md_dbg_onoff = false;
static unsigned int md_test_len = 4096;
unsigned int md_test_loops = 100; 
int md_open(struct inode* inode, struct file* filp)
{
    return 0;
}

int md_release(struct inode* inode, struct file* filp)
{
    return 0;
}

ssize_t md_read(struct file *filp, char __user *buf,
                size_t count, loff_t  *f_pos)
{
    return -EFAULT;
}

ssize_t md_write(struct file *filp, const char __user *buf,
                 size_t count, loff_t *f_pos)
{
    ssize_t retval = -ENOMEM; /* value used in "goto out" statements */
    unsigned char buffer[256];
    unsigned char *cmd_buffer = NULL;
    if(count <= 256)
        cmd_buffer = buffer;
    else
        cmd_buffer = kmalloc(count, GFP_KERNEL);
    if(!cmd_buffer) {
        retval = -ENOMEM;
        goto out;
    }
    if(copy_from_user(cmd_buffer, buf, count)) {
        retval = -EFAULT;
        goto out;
    }
    retval = md_do_cmds(cmd_buffer, count);
    if(retval == MD_SUCCESS)
        retval = count;
    *f_pos += count;
out:
    if(cmd_buffer && count > 256)
        kfree(cmd_buffer);
    return retval;
}

static long md_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    int retval = 0;
    switch(cmd) {
        case MD_IOC_WAIT_FOR_COMPLETE: {
            md_wait_hw_stopped(2 * HZ);
            break;
        }
        case MD_IOC_READ_ISSUED_INST_COUNT: {
            uint64_t u64IssuedInstCnt = 0;
            md_get_issued_inst_count(&u64IssuedInstCnt);
            if (copy_to_user((__u64 *)arg, (void *)&u64IssuedInstCnt, sizeof(u64IssuedInstCnt))) {
                retval = -EFAULT;
                goto out;
            }

            break;
        }
        case MD_IOC_READ_INST_COUNT: {
            uint64_t u64InstCnt = 0;
            retval = md_get_inst_count(&u64InstCnt);
            if(retval != MD_SUCCESS)
                goto out;
            if (copy_to_user((__u64 *)arg, (void *)&u64InstCnt, sizeof(u64InstCnt))) {
                retval = -EFAULT;
                goto out;
            }

            break;
        }
        case MD_IOC_WRITE_ISSUE_CMD: {
            uint32_t length = 0;
            uint8_t  buffer[256];
            uint8_t *cmd_buffer = NULL;
            if (copy_from_user((void *)&length, (const void __user *)arg,
                               sizeof(__u32)) || length == 0) {
                retval = -EFAULT;
                goto out;
            }

            if(length <= 256)
                cmd_buffer = buffer;
            else
                cmd_buffer = kmalloc(length, GFP_KERNEL);
            if(!cmd_buffer) {
                retval = -ENOMEM;
                goto out;
            }
            if(copy_from_user(cmd_buffer, arg + sizeof(__u32), length)) {
                if(length > 256)
                    kfree(cmd_buffer);
                retval = -EFAULT;
                goto out;
            }
            retval = md_do_cmds(cmd_buffer, length);
            if(length > 256)
                kfree(cmd_buffer);
            break;
        }

        case MD_IOC_DO_MEMCPY_TRANSACTION: {
            MD_MEMCPY_TRANSACTION param;
            if(copy_from_user((void *)&param, (const void __user *)arg, sizeof(param))) {
                retval = -EFAULT;
                goto out;
            }

            if(param.len <= 0) {
                PDEWAR("_md_memcpy with zero param.len = %d, ignore it\n", param.len);
                return -EINVAL;
            }
            // KWarning: checked ok by qibing_huang@apowertec.com
            retval = md_memcpy(param.dst, param.src,
                               param.len, param.flags, 0);
            break;
        }

        case MD_IOC_COPY_PAGES: {
            struct copy_pages_cmd param;
            if(copy_from_user((void *)&param, (const void __user *)arg,
                              sizeof(struct copy_pages_cmd))) {
                retval = -EFAULT;
                goto out;
            }
            if(param.length <= 0) {
                PDEWAR("md_copy_pages with zero param.length = %d, ignore it\n", param.length);
                return -EINVAL;
            }
            PDEBUG("dst phys = 0x%08x, src phys = 0x%08x, length = %d\n", param.phys_dst, param.phys_src, param.length);
            retval = md_memcpy(param.phys_dst,
                               param.phys_src, param.length, (param.op ? BIT(0) : 0), 1);
            break;
        }

        case MD_IOC_DO_ABILITY_PROBE: {
            int flag = 1;
            if (copy_to_user((int *)arg, (void *)&flag, sizeof(flag))) {
                retval = -EFAULT;
                goto out;
            }
            break;
        }

        default:  /* redundant, as cmd was checked against MAXNR */
            PDEWAR("md ioctl code not supported\n");
            retval = -ENOTTY;
            goto out;
    }
out:

    return retval;
}

#ifdef CONFIG_COMPAT
static long md_compat_ioctl(struct file *filp, unsigned int cmd,
                            unsigned long arg)
{
    return md_ioctl(filp, cmd, arg);
}
#endif

struct file_operations md_fops = {
    .owner                  = THIS_MODULE,
    .read                   = md_read,
    .write                  = md_write,
    .unlocked_ioctl         = md_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl           = md_compat_ioctl,
#endif
    .open                   = md_open,
    .release                = md_release,
};


static ssize_t md_debug_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    if (strcmp(attr->attr.name, "md_dbg_onoff") == 0) {
        buf[0] = 0;
        sprintf(buf + strlen(buf), "md_dbg_onoff = %d\n", md_dbg_onoff);
        sprintf(buf + strlen(buf), "echo 1/0 > md_dbg_onoff  to enable or disable md_debug\n");
        return strlen(buf);
    }else if(strcmp(attr->attr.name, "md_test_loops")==0){
        buf[0] = 0;
        sprintf(buf + strlen(buf), "md_test_loops = %d\n", md_test_loops);
        sprintf(buf + strlen(buf), "echo loops > md_test_loops\n");
        return strlen(buf);
    }else if(strcmp(attr->attr.name, "md_test_len")==0){
        buf[0] = 0;
        sprintf(buf + strlen(buf), "md_test_len = %d\n", md_test_len);
        sprintf(buf + strlen(buf), "echo data_len > md_test_len\n");
        return strlen(buf);
    } else if(strcmp(attr->attr.name, "md_test_case") == 0) {
        buf[0] = 0;
        sprintf(buf + strlen(buf), "echo 1 > md_test_case  to do md_unit_test\n");
        sprintf(buf + strlen(buf), "echo 2 > md_test_case  to do md_test_all\n");
        sprintf(buf + strlen(buf), "echo 3 > md_test_case  to do md_fill_test\n");
        sprintf(buf + strlen(buf), "echo 4 > md_test_case  to do rtk_md_unit_test\n");
        sprintf(buf + strlen(buf), "echo 5 > md_test_case  to do multi_vs_signal\n");
        return strlen(buf);
    }
    return 0;
}

static ssize_t md_debug_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t n)
{
    if(strcmp(attr->attr.name, "md_dbg_onoff") == 0) {
        int val;
        if (sscanf(buf, "%d", &val) == 1) {
            md_dbg_onoff = val;
            return n;
        }
    }else if(strcmp(attr->attr.name, "md_test_loops")==0) {
        int loops;
        if (sscanf(buf, "%d", &loops) == 1) {
            md_test_loops = loops;
            return n;
        }
    }else if(strcmp(attr->attr.name, "md_test_len")==0) {
        int len;
        if (sscanf(buf, "%d", &len) == 1) {
            md_test_len = len;
            return n;
        }
    }else if(strcmp(attr->attr.name, "md_test_case") == 0) {
        unsigned int md_test_case = 0;
        if (sscanf(buf, "%u", &md_test_case) == 1) {
#ifdef CONFIG_RTK_KDRV_MD_TEST
            if(md_test_case == 1)
                md_unit_test(md_test_len);
            else if (md_test_case == 2)
                md_test_all(md_test_len);
            else if (md_test_case == 3)
                md_fill_test();
            else if(md_test_case == 4)
                rtk_md_unit_test();
            else if(md_test_case == 5) {
                multi_vs_signal(md_test_len, 200);
                udelay(50);
                multi_vs_signal(md_test_len, 200);
                udelay(50);
            }
#endif
            return n;
        }
    }
    return -EINVAL;
}

struct kobject *md_kobj;
#define md_attr(_name) \
static struct kobj_attribute _name##_attr = {   \
    .attr   = {                             \
    .name = __stringify(_name),     \
    .mode = 0644,                   \
    },                                      \
    .show   = md_debug_show,                        \
    .store  = md_debug_store,               \
}

md_attr(md_dbg_onoff);
md_attr(md_test_case);
md_attr(md_test_len);
md_attr(md_test_loops);
static struct attribute * md_attrs[] = {
    &md_dbg_onoff_attr.attr,
    &md_test_case_attr.attr,
    &md_test_len_attr.attr,
    &md_test_loops_attr.attr,
    NULL,
};

static struct attribute_group md_attr_group = {
    .attrs = md_attrs,
};


static struct miscdevice rtk_md_miscdev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = MD_DEV_NAME,
    .fops = &md_fops,
    .mode = 0666,
};

static int md_setup_cdev(void)
{
    int ret = 0;
    if (misc_register(&rtk_md_miscdev)) {
        PDEERR("register cw misc dev file failed\n");
        ret = -ENODEV;
        goto FAIL_REGISTER_MISC_DEV;
    }

    md_kobj = kobject_create_and_add("md", NULL);
    if(!md_kobj) {
        ret = -ENOMEM;
        goto FAIL_KOBJECT_CREATE;
    }

    ret = sysfs_create_group(md_kobj, &md_attr_group);
    if(ret != 0) {
        goto FAIL_SYSFS_CREATE_GROUP;
    }

    md_device = rtk_md_miscdev.this_device;
    md_device->coherent_dma_mask = DMA_BIT_MASK(32);
    md_device->dma_mask = &md_device->coherent_dma_mask;
#ifdef CONFIG_ARM64
    arch_setup_dma_ops(md_device, 0, 0, NULL, false);
#endif
    if(dma_set_mask(md_device, DMA_BIT_MASK(32))) {
        PDEERR("[MD] DMA not supported!\n");
    }
    dma_set_coherent_mask(md_device, DMA_BIT_MASK(32));
    return 0;

FAIL_SYSFS_CREATE_GROUP:
    kobject_put(md_kobj);
FAIL_KOBJECT_CREATE:
    misc_deregister(&rtk_md_miscdev);
FAIL_REGISTER_MISC_DEV:
    return ret;
}

static void md_unsetup_cdev(void)
{
    kobject_put(md_kobj);
    misc_deregister(&rtk_md_miscdev);
}


static __init int md_dev_init_module(void)
{
    int ret = 0;
    ret = md_setup_cdev();
    if(ret != 0)
        goto FAIL_CREATE_MD_CDEV;
    ret = md_platform_init();
    if(ret != 0)
        goto FAIL_INIT_PLATOFRM;
    ret = rtk_md_init(md_device);
    if(ret == 0)
        return ret;
FAIL_INIT_MD:
    md_platform_uninit();
FAIL_INIT_PLATOFRM:
    md_unsetup_cdev();
FAIL_CREATE_MD_CDEV:

    return ret;
}

static __exit void md_dev_cleanup_module(void)
{
    rtk_md_uninit();
    md_platform_uninit();
    md_unsetup_cdev();

}


module_init(md_dev_init_module);
module_exit(md_dev_cleanup_module);
MODULE_AUTHOR("Realtek.com");
MODULE_LICENSE("GPL");

