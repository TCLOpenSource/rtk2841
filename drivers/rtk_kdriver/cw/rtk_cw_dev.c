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
#include <linux/seq_file.h>
#include <linux/proc_fs.h>
#include <linux/sysfs.h>
#include "rtk_cw_dbg.h"
#include "rtk_cw_dev.h"


static struct proc_dir_entry *proc_entry;
bool set_cw_dbg_en = false;
bool get_cw_dbg_en = false;

/*------------------------------------------------------------------
 * Func : cw_dev_open
 *
 * Desc : open function of cw dev
 *
 * Parm : inode : inode of dev
 *               file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int cw_dev_open(struct inode *inode, struct file *file)
{
    return 0;
}

/*------------------------------------------------------------------
 * Func : cw_dev_release
 *
 * Desc : release function of cw dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int cw_dev_release(struct inode *inode, struct file *file)
{
    return 0;
}

/*------------------------------------------------------------------
 * Func : cw_dev_read
 *
 * Desc : read function of cw dev
 *
 * Parm : file  : context of file
 *        buff  : rx buffer addr
 *        size  : rx buffer size
 *        ofst  : read offset
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static ssize_t cw_dev_read(struct file *file,
                           char __user *buff, size_t size, loff_t *ofst)
{
    return 0;
}

/*------------------------------------------------------------------
 * Func : cw_dev_write
 *
 * Desc : write function of cw dev
 *
 * Parm : file  : context of file
 *        buff  : tx buffer addr
 *        size  : tx buffer size
 *        ofst  : write offset
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static ssize_t cw_dev_write(struct file *file,
                            const char __user *buff, size_t size, loff_t *ofst)
{
    return 0;
}


/*------------------------------------------------------------------
 * Func : cw_dev_ioctl
 *
 * Desc : ioctl function of cw dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static long cw_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int ret = -EFAULT;
    int len = 0;
    RTK_CW_COMM_DATA   cw_ope_data;
    UINT8 *tmp_array = NULL;
    UINT8 *tmp_data = NULL;

    /*First Parameters checking and allocating buffer*/
    if((void *)arg == NULL)
        return -EFAULT;
    if (copy_from_user(&cw_ope_data, (void __user *)arg, sizeof(cw_ope_data)))
        return -EFAULT;
    if(cw_ope_data.index_array != NULL && cw_ope_data.array_len > 0) {
        tmp_array = (UINT8 *)kmalloc(cw_ope_data.array_len, GFP_KERNEL);
        if(!tmp_array)
            return -ENOMEM;
    }
    if(cw_ope_data.data != NULL && cw_ope_data.data_len > 0) {
        tmp_data = (UINT8 *)kmalloc(cw_ope_data.data_len, GFP_KERNEL);
        if(!tmp_data) {
            kfree(tmp_array);
            tmp_array = NULL;
            return -ENOMEM;
        }
    }


    switch (cmd) {
        case RTK_CMD_CW_RQUEST_MULTI_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, cw_ope_data.index_array, cw_ope_data.array_len))
                ret = rtk_cw_request_cw_array(cw_ope_data.module_name, tmp_array, cw_ope_data.array_len);
            break;
        case RTK_CMD_CW_RELEASE_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, cw_ope_data.index_array, cw_ope_data.array_len))
                ret = rtk_cw_release_cw(cw_ope_data.module_name, tmp_array[0]);
            break;
        case RTK_CMD_CW_RELEASE_CW_BY_MODULE:
            ret = rtk_cw_release_cw_by_module(cw_ope_data.module_name);
            break;
        case RTK_CMD_CW_SET_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, cw_ope_data.index_array, cw_ope_data.array_len)
               && tmp_data != NULL && !copy_from_user(tmp_data, cw_ope_data.data, cw_ope_data.data_len))
                ret = rtk_cw_set_cw(cw_ope_data.module_name, tmp_array[0], tmp_data, cw_ope_data.data_len);
            break;
        case RTK_CMD_CW_GET_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, cw_ope_data.index_array, cw_ope_data.array_len)
               && tmp_data != NULL)
                ret = rtk_cw_get_cw(cw_ope_data.module_name, tmp_array[0], tmp_data, cw_ope_data.data_len);
            if(ret == 0)
                ret = copy_to_user(cw_ope_data.data, tmp_data, cw_ope_data.data_len);
            break;
        case RTK_CMD_CW_SET_NONSEQ_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, cw_ope_data.index_array, cw_ope_data.array_len)
               && tmp_data != NULL && !copy_from_user(tmp_data, cw_ope_data.data, cw_ope_data.data_len))
                ret = rtk_cw_set_nonseq_cw(cw_ope_data.module_name, tmp_array, cw_ope_data.array_len, tmp_data, cw_ope_data.data_len);
            break;
        case RTK_CMD_CW_GET_NONSEQ_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, cw_ope_data.index_array, cw_ope_data.array_len)
               && tmp_data != NULL)
                ret = rtk_cw_get_nonseq_cw(cw_ope_data.module_name, tmp_array, cw_ope_data.array_len, tmp_data, cw_ope_data.data_len);
            if(ret == 0)
                ret = copy_to_user(cw_ope_data.data, tmp_data, cw_ope_data.data_len);
            break;
        case RTK_CMD_CW_QUERY_FREE_CW:
            if(tmp_array == NULL) {
                ret = -EFAULT;
                break;
            }
            len = rtk_cw_query_free_cw(tmp_array, cw_ope_data.array_len);
            cw_ope_data.array_len = len;
            ret = 0;
            if(copy_to_user((void __user *)arg, &cw_ope_data, sizeof(cw_ope_data))
               || copy_to_user(cw_ope_data.index_array, tmp_array, len))
                ret = -EFAULT;
            break;
        case RTK_CMD_CW_QUERY_USED_CW_BY_MODULE:
            if(tmp_array == NULL) {
                ret = -EFAULT;
                break;
            }
            len = rtk_cw_query_used_cw_by_module(cw_ope_data.module_name, tmp_array, cw_ope_data.array_len);
            cw_ope_data.array_len = len;
            ret = 0;
            if(copy_to_user((void __user *)arg, &cw_ope_data, sizeof(cw_ope_data))
               || copy_to_user(cw_ope_data.index_array, tmp_array, len))
                ret = -EFAULT;
            break;
        default:
            break;
    }
    if(tmp_array) {
        kfree(tmp_array);
        tmp_array = NULL;
    }
    if(tmp_data) {
        kfree(tmp_data);
        tmp_data = NULL;
    }
    return ret;
}

/*------------------------------------------------------------------
 * Func : cw_compat_dev_ioctl
 *
 * Desc : ioctl function of cw dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
#ifdef CONFIG_COMPAT
static long cw_compat_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int ret = -EFAULT;
    int len = 0;
    COMPAT_RTK_CW_COMM_DATA   cw_ope_data;
    UINT8 *tmp_array = NULL;
    UINT8 *tmp_data = NULL;

    /*First Parameters checking and allocating buffer*/
    if((void *)arg == NULL)
        return -EFAULT;
    if (copy_from_user(&cw_ope_data, (void *)arg, sizeof(cw_ope_data)))
        return -EFAULT;
    if(compat_ptr(cw_ope_data.index_array) != NULL && cw_ope_data.array_len > 0) {
        tmp_array = (UINT8 *)kmalloc(cw_ope_data.array_len, GFP_KERNEL);
        if(!tmp_array)
            return -ENOMEM;
    }
    if(compat_ptr(cw_ope_data.data) != NULL && cw_ope_data.data_len > 0) {
        tmp_data = (UINT8 *)kmalloc(cw_ope_data.data_len, GFP_KERNEL);
        if(!tmp_data) {
            kfree(tmp_array);
            tmp_array = NULL;
            return -ENOMEM;
        }
    }


    switch (cmd) {
        case COMPAT_RTK_CMD_CW_RQUEST_MULTI_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, compat_ptr(cw_ope_data.index_array), cw_ope_data.array_len))
                ret = rtk_cw_request_cw_array(cw_ope_data.module_name, tmp_array, cw_ope_data.array_len);
            break;
        case COMPAT_RTK_CMD_CW_RELEASE_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, compat_ptr(cw_ope_data.index_array), cw_ope_data.array_len))
                ret = rtk_cw_release_cw(cw_ope_data.module_name, tmp_array[0]);
            break;
        case RTK_CMD_CW_RELEASE_CW_BY_MODULE:
            ret = rtk_cw_release_cw_by_module(cw_ope_data.module_name);
            break;
        case COMPAT_RTK_CMD_CW_SET_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, compat_ptr(cw_ope_data.index_array), cw_ope_data.array_len)
               && tmp_data != NULL && !copy_from_user(tmp_data, compat_ptr(cw_ope_data.data), cw_ope_data.data_len))
                ret = rtk_cw_set_cw(cw_ope_data.module_name, tmp_array[0], tmp_data, cw_ope_data.data_len);
            break;
        case COMPAT_RTK_CMD_CW_GET_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, compat_ptr(cw_ope_data.index_array), cw_ope_data.array_len)
               && tmp_data != NULL)
                ret = rtk_cw_get_cw(cw_ope_data.module_name, tmp_array[0], tmp_data, cw_ope_data.data_len);
            if(ret == 0)
                ret = copy_to_user(compat_ptr(cw_ope_data.data), tmp_data, cw_ope_data.data_len);
            break;
        case COMPAT_RTK_CMD_CW_SET_NONSEQ_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, compat_ptr(cw_ope_data.index_array), cw_ope_data.array_len)
               && tmp_data != NULL && !copy_from_user(tmp_data, compat_ptr(cw_ope_data.data), cw_ope_data.data_len))
                ret = rtk_cw_set_nonseq_cw(cw_ope_data.module_name, tmp_array, cw_ope_data.array_len, tmp_data, cw_ope_data.data_len);
            break;
        case COMPAT_RTK_CMD_CW_GET_NONSEQ_CW:
            if(tmp_array != NULL && !copy_from_user(tmp_array, compat_ptr(cw_ope_data.index_array), cw_ope_data.array_len)
               && tmp_data != NULL)
                ret = rtk_cw_get_nonseq_cw(cw_ope_data.module_name, tmp_array, cw_ope_data.array_len, tmp_data, cw_ope_data.data_len);
            if(ret == 0)
                ret = copy_to_user(compat_ptr(cw_ope_data.data), tmp_data, cw_ope_data.data_len);
            break;
        case COMPAT_RTK_CMD_CW_QUERY_FREE_CW:
            if(tmp_array == NULL) {
                ret = -EFAULT;
                break;
            }
            len = rtk_cw_query_free_cw(tmp_array, cw_ope_data.array_len);
            cw_ope_data.array_len = len;
            ret = 0;
            if(copy_to_user(arg, &cw_ope_data, sizeof(cw_ope_data))
               || copy_to_user(compat_ptr(cw_ope_data.index_array), tmp_array, len))
                ret = -EFAULT;
            break;
        case COMPAT_RTK_CMD_CW_QUERY_USED_CW_BY_MODULE:
            if(tmp_array == NULL) {
                ret = -EFAULT;
                break;
            }
            len = rtk_cw_query_used_cw_by_module(cw_ope_data.module_name, tmp_array, cw_ope_data.array_len);
            cw_ope_data.array_len = len;
            ret = 0;
            if(copy_to_user(arg, &cw_ope_data, sizeof(cw_ope_data))
               || copy_to_user(compat_ptr(cw_ope_data.index_array), tmp_array, len))
                ret = -EFAULT;
            break;
        default:
            break;
    }
    if(tmp_array) {
        kfree(tmp_array);
        tmp_array = NULL;
    }
    if(tmp_data) {
        kfree(tmp_data);
        tmp_data = NULL;
    }
    return ret;
}
#endif

static struct file_operations cw_dev_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = cw_dev_ioctl,
    .open = cw_dev_open,
    .read = cw_dev_read,
    .write = cw_dev_write,
    .release = cw_dev_release,
#ifdef CONFIG_COMPAT
    .compat_ioctl = cw_compat_dev_ioctl,
#endif
};


static struct miscdevice rtk_cw_miscdev = {
    MISC_DYNAMIC_MINOR,
    "cw_util",
    &cw_dev_fops,
};

/*------------------------------------------------------------------
 * Func : cw_proc_show
 *
 * Desc : when cat /proc/cw , this function will be called once to show
 *           the status o f the whole cw.
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int cw_proc_show(struct seq_file *seq, void *v)
{
    char buf[1024] = {0};
    rtk_cw_dump_cw_status(buf);
    seq_puts(seq, buf);
    return 0;
}

static int cw_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, cw_proc_show, inode->i_private);
}

static struct file_operations proc_fops = {
    .open  = cw_proc_open,
    .read  = seq_read,
    .llseek  = seq_lseek,
    .release = single_release,
};

static ssize_t cw_debug_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    if (strcmp(attr->attr.name, "set_cw_dbg_en") == 0) {
        return sprintf(buf, "set_cw_dbg_en = %d\n", set_cw_dbg_en);
    } else if (strcmp(attr->attr.name, "get_cw_dbg_en") == 0) {
        return sprintf(buf, "get_cw_dbg_en = %d\n", get_cw_dbg_en);
    }
    return 0;
}

static ssize_t cw_debug_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t n)
{
    if(strcmp(attr->attr.name, "set_cw_dbg_en") == 0) {
        int val;
        if (sscanf(buf, "%d", &val) == 1) {
            set_cw_dbg_en = val;
            return n;
        }
    } else if (strcmp(attr->attr.name, "get_cw_dbg_en") == 0) {
        int val;
        if (sscanf(buf, "%d", &val) == 1) {
            get_cw_dbg_en = val;
            return n;
        }
    }


    return -EINVAL;
}

struct kobject *cw_kobj;
#define cw_attr(_name) \
static struct kobj_attribute _name##_attr = {   \
    .attr   = {             \
        .name = __stringify(_name), \
        .mode = 0644,           \
    },                  \
    .show   = cw_debug_show,            \
    .store  = cw_debug_store,       \
}

cw_attr(set_cw_dbg_en);
cw_attr(get_cw_dbg_en);
static struct attribute * cw_attrs[] = {
    &set_cw_dbg_en_attr.attr,
    &get_cw_dbg_en_attr.attr,
    NULL,
};

static struct attribute_group cw_attr_group = {
    .attrs = cw_attrs,
};

/*------------------------------------------------------------------
 * Func : cw_dev_module_init
 *
 * Desc : cw dev init function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int __init cw_dev_module_init(void)
{
    int ret = 0;
    if (misc_register(&rtk_cw_miscdev)) {
        CW_ERR("register cw misc dev file failed\n");
        ret = -ENODEV;
        goto FAIL_REGISTER_MISC_DEV;
    }
    proc_entry = proc_create( "cw", 0644, NULL, &proc_fops);
    if (proc_entry == NULL) {
        CW_ERR("Couldn't create proc entry\n");
        ret = -ENOMEM;
        goto FAIL_REGISTER_PROC_FILE;
    }
    cw_kobj = kobject_create_and_add("cw", NULL);
    if (!cw_kobj) {
        ret = -ENOMEM;
        goto FAIL_KOBJECT_CREATE;
    }
    ret = sysfs_create_group(cw_kobj, &cw_attr_group);
    if (ret != 0) {
        goto FAIL_SYSFS_CREATE_GROUP;
    }
    return 0;

FAIL_SYSFS_CREATE_GROUP:
    kobject_put(cw_kobj);
FAIL_KOBJECT_CREATE:
    proc_remove(proc_entry);
FAIL_REGISTER_PROC_FILE:
    misc_deregister(&rtk_cw_miscdev);
FAIL_REGISTER_MISC_DEV:
    return ret;
}

/*------------------------------------------------------------------
 * Func : cw_dev_module_exit
 *
 * Desc : cw dev module exit function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
void __exit cw_dev_module_exit(void)
{
    kobject_put(cw_kobj);
    proc_remove(proc_entry);
    misc_deregister(&rtk_cw_miscdev);

}

module_init(cw_dev_module_init);
module_exit(cw_dev_module_exit);
MODULE_LICENSE("GPL");

