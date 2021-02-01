#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/stat.h>
#include <linux/types.h>
#include <mach/rtk_platform.h>
#include <asm/atomic.h>
#include <linux/proc_fs.h>
#include <rtk_kdriver/rtk_gpio.h>
#include "rtk_switch.h"

static struct class *switch_class;
static atomic_t deivce_count = ATOMIC_INIT(-1);

static ssize_t rtk_switch_state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    struct switch_dev *sdev = (struct switch_dev *)dev_get_drvdata(dev);

    if (sdev->print_state) {
        int ret = sdev->print_state(sdev,buf);
        if (ret >= 0)
            return ret;
        }
        return sprintf(buf, "%d\n",sdev->state);
}

ssize_t rtk_switch_state_store(struct device *dev, struct device_attribute *attr,
                const char *buf, size_t count)
{
    return -1;
}

static ssize_t rtk_switch_name_show(struct device*dev, struct device_attribute *attr, char *buf)
{
    struct switch_dev *sdev = (struct switch_dev *)dev_get_drvdata(dev);

    if (sdev->print_name) {
        int ret = sdev->print_name(sdev,buf);
        if (ret >= 0)
            return ret;
    }
    return sprintf(buf,"%s\n",sdev->name);
}

ssize_t rtk_switch_name_store(struct device *dev, struct device_attribute *attr,
                const char *buf, size_t count)
{
    return -1;
}

static DEVICE_ATTR(state, S_IRUGO | S_IWUSR, rtk_switch_state_show, rtk_switch_state_store);
static DEVICE_ATTR(name, S_IRUGO | S_IWUSR, rtk_switch_name_show, rtk_switch_name_store);

int rtk_switch_get_state(struct switch_dev *sdev)
{
    return sdev->state;
}

void rtk_switch_set_state(struct switch_dev *sdev, int state)
{
    char name_buf[120];
    char state_buf[120];
    char *prop_buf;
    char *envp[3];
    int env_offset= 0;
    int length;

    if(sdev->state != state) {
        sdev->state= state;
        prop_buf =(char *)get_zeroed_page(GFP_KERNEL);
        if(prop_buf){
            length = rtk_switch_name_show(sdev->dev, NULL, prop_buf);
            if (length > 0) {
                if(prop_buf[length-1] == '\n')
                    prop_buf[length-1] = 0;
                snprintf(name_buf,sizeof(name_buf),"SWITCH_NAME=%s", prop_buf);
                envp[env_offset++] = name_buf;
            }
            length = rtk_switch_state_show(sdev->dev, NULL, prop_buf);
            if (length >0) {
                if(prop_buf[length-1] == '\n')
                    prop_buf[length-1] = 0;
                   snprintf(state_buf,sizeof(state_buf), "SWITCH_STATE=%s", prop_buf);
                envp[env_offset++]= state_buf;
            }
            envp[env_offset]= NULL;
            kobject_uevent_env(&sdev->dev->kobj,KOBJ_CHANGE, envp);
            free_page((unsigned long)prop_buf);
        }
        else
        {
            RTK_SWITCH_ERR("out of memory in switch_set_state\n");
            kobject_uevent(&sdev->dev->kobj,KOBJ_CHANGE);
        }
    }
}

EXPORT_SYMBOL_GPL(rtk_switch_set_state);


static int rtk_create_switch_class(void)
{
    switch_class = class_create(THIS_MODULE, "switch");
    if (IS_ERR(switch_class))
        return PTR_ERR(switch_class);
    atomic_set(&deivce_count, 0);
    return 0;
}
int rtk_switch_dev_register(struct switch_dev *sdev)
{
    if (!switch_class)
        return -1;

    sdev->index = atomic_inc_return(&deivce_count);

    sdev->dev = device_create(switch_class, NULL,MKDEV(0, sdev->index), NULL,sdev->name);
    if (sdev->dev == NULL){
        RTK_SWITCH_ERR("Failed to register driver %s\n", sdev->name);
        goto err_create_device;
    }

    if(device_create_file(sdev->dev,&dev_attr_name) != 0)
        goto err_create_name_file;

    if(device_create_file(sdev->dev,&dev_attr_state) != 0)
        goto err_create_state_file;

    dev_set_drvdata(sdev->dev, sdev);
    sdev->state = 0;
    return 0;

err_create_state_file:    
    device_remove_file(sdev->dev,&dev_attr_name);
err_create_name_file:
    device_destroy(switch_class, MKDEV(0,sdev->index));
err_create_device:
    return -1;
}

void rtk_switch_dev_unregister(struct switch_dev *sdev)

{
    device_remove_file(sdev->dev,&dev_attr_name);
    device_remove_file(sdev->dev,&dev_attr_state);
    device_destroy(switch_class, MKDEV(0,sdev->index));
    dev_set_drvdata(sdev->dev, NULL);
}

EXPORT_SYMBOL_GPL(rtk_switch_dev_unregister);
EXPORT_SYMBOL_GPL(rtk_switch_dev_register);

static int __init rtk_switch_class_init(void)
{
    return rtk_create_switch_class();
}

static void __exit rtk_switch_class_exit(void)
{
    class_destroy(switch_class);
}

subsys_initcall(rtk_switch_class_init);
module_exit(rtk_switch_class_exit);
MODULE_DESCRIPTION("Realtek Switch Class Driver");
MODULE_ALIAS("platform:rtk-switch-class");
MODULE_LICENSE("GPL");
