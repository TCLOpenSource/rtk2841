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
#include <mach/platform.h>

#include <rtk_kdriver/rtk_crt.h>
#include <rtk_kdriver/rtk_lsadc.h>
#include "rtk_lsadc_reg.h"

extern LSADC_PCBINFO _gLsadcInfo[];
extern unsigned int lsadc_init_status_mask;
extern struct class *_gstlsadc_class;
struct device *lsadc_device_node[MAX_LSADC_COUNT];
int m_ioctl_enable = 1;
int log_onoff = 0;


ssize_t rtk_lsadc_show_param(struct device *dev,
                  struct device_attribute *attr, char *buf)
{
    int *index = 0;
    int ret = 0;
    unsigned char value;
    index = (int *)(dev->platform_data);
    if (strncmp(attr->attr.name, "adcValue", strlen("adcValue")) == 0) {
        rtk_lsadc_get_adcValue(*index,&value);
        ret = sprintf(buf, "%u\n", value);
    }else if (strncmp(attr->attr.name, "threshold", strlen("threshold")) == 0) {
        rtk_lsadc_get_threshold(*index,&value);
        ret = sprintf(buf, "%u\n", value);
    }else if (strncmp(attr->attr.name, "active", strlen("active")) == 0) {
        rtk_lsadc_get_activeStatus(*index,&value);
        ret = sprintf(buf, "%u\n", value);
    }else if (strncmp(attr->attr.name, "padSwitch", strlen("padSwitch")) == 0) {
        rtk_lsadc_get_padSwitch(*index,&value);
        ret = sprintf(buf, "%u\n", value);
    }else if (strncmp(attr->attr.name, "voltageMode", strlen("voltageMode")) == 0) {
        rtk_lsadc_get_voltageMode(*index,&value);
            ret = sprintf(buf, "%u\n", value);
    }

    return ret;
}

ssize_t rtk_lsadc_set_param(struct device *dev,
                 struct device_attribute *attr,
                 const char *buf, size_t count)
{
    unsigned char val = 0;
    int *index;
    sscanf(buf, "%c\n", &val);
    index = (int *)(dev->platform_data);
    if (strncmp(attr->attr.name, "adcValue", strlen("adcValue")) == 0) {
    }else if (strncmp(attr->attr.name, "threshold", strlen("threshold")) == 0) {
        rtk_lsadc_set_threshold(*index,val);
    }else if (strncmp(attr->attr.name, "active", strlen("active")) == 0) {
        rtk_lsadc_set_active(*index,val);
    }else if (strncmp(attr->attr.name, "padSwitch", strlen("padSwitch")) == 0) {
        rtk_lsadc_set_padSwitch(*index,val);
    }else if (strncmp(attr->attr.name, "voltageMode", strlen("voltageMode")) == 0) {
        rtk_lsadc_set_voltageMode(*index,val);
    }

    return count;
}


 ssize_t rtk_lsadc_cls_show_param(struct class *class, 
                     struct class_attribute *attr,char *buf)
{
    int ret = 0;
    int value;
    if (strncmp(attr->attr.name, "mainAnalogCtrl", strlen("mainAnalogCtrl")) == 0) {
        value = rtk_lsadc_dump_mainAnalogCtrl();
        ret = sprintf(buf, "0x%8x\n", value);
    }else if (strncmp(attr->attr.name, "mainLsadcCtrl", strlen("mainLsadcCtrl")) == 0) {
        value = rtk_lsadc_dump_mainLsadcCtrl();
        ret = sprintf(buf, "0x%8x\n", value);
    }else if (strncmp(attr->attr.name, "ioctl_enable", strlen("ioctl_enable")) == 0) {
        ret = sprintf(buf, "%d\n", m_ioctl_enable);
    }else if (strncmp(attr->attr.name, "dbglog_onoff", strlen("dbglog_onoff")) == 0) {
        ret = sprintf(buf, "%d\n", log_onoff);
    }

    return ret;
}
 ssize_t rtk_lsadc_cls_set_param(struct class *class, struct class_attribute *attr,
                    const char *buf, size_t count)
{
     int val = 0;
     sscanf(buf, "%d\n", &val);

    if (strncmp(attr->attr.name, "ioctl_enable", strlen("ioctl_enable")) == 0) {
        m_ioctl_enable = val;
    }if (strncmp(attr->attr.name, "dbglog_onoff", strlen("dbglog_onoff")) == 0) {
        log_onoff = val;
    }
    return count;
}

CLASS_ATTR(mainLsadcCtrl    ,S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP ,rtk_lsadc_cls_show_param, rtk_lsadc_cls_set_param);
CLASS_ATTR(mainAnalogCtrl, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP ,rtk_lsadc_cls_show_param, rtk_lsadc_cls_set_param);
CLASS_ATTR(ioctl_enable, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lsadc_cls_show_param, rtk_lsadc_cls_set_param);
CLASS_ATTR(dbglog_onoff, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lsadc_cls_show_param, rtk_lsadc_cls_set_param);

DEVICE_ATTR(adcValue    , S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lsadc_show_param, rtk_lsadc_set_param);
DEVICE_ATTR(threshold, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lsadc_show_param, rtk_lsadc_set_param);
DEVICE_ATTR(active     , S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lsadc_show_param, rtk_lsadc_set_param);
DEVICE_ATTR(padSwitch, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lsadc_show_param, rtk_lsadc_set_param);
DEVICE_ATTR(voltageMode     , S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lsadc_show_param, rtk_lsadc_set_param);

int  rtk_lsadc_create_class_attr(struct class *cls)
{
    int ret;
    ret = class_create_file(cls, &class_attr_mainLsadcCtrl);
    ret = class_create_file(cls, &class_attr_mainAnalogCtrl);
    ret = class_create_file(cls, &class_attr_ioctl_enable);
    ret = class_create_file(cls, &class_attr_dbglog_onoff);
    return ret;
}

void  rtk_lsadc_remove_class_attr(struct class *cls)
{
    class_remove_file(cls, &class_attr_mainLsadcCtrl);
    class_remove_file(cls, &class_attr_mainAnalogCtrl);
    class_remove_file(cls, &class_attr_ioctl_enable);
    class_remove_file(cls, &class_attr_dbglog_onoff);
}

int  rtk_lsadc_create_attr(struct device *device)
{
    int ret;
    ret = device_create_file(device, &dev_attr_adcValue);
    ret = device_create_file(device, &dev_attr_threshold);
    ret = device_create_file(device, &dev_attr_active);
    ret = device_create_file(device, &dev_attr_padSwitch);
    ret = device_create_file(device, &dev_attr_voltageMode);
    return ret;
}
void rtk_lsadc_remove_attr(struct device *device)
{
    device_remove_file(device, &dev_attr_adcValue);
    device_remove_file(device, &dev_attr_threshold);
    device_remove_file(device, &dev_attr_active);
    device_remove_file(device, &dev_attr_padSwitch);
    device_remove_file(device, &dev_attr_voltageMode);
}

int rtk_lsadc_dev_attr_init(struct class * cls)
{
    int i;
    int count = 0;
    int ret;
    unsigned char nodename[64];
    for(i = 0; i < MAX_LSADC_COUNT; i++){
        if(0 == get_lsadc_init_status(i)){
            snprintf(nodename, 16, "lsadc-%d",i);
            lsadc_device_node[count] = device_create(cls, NULL, MKDEV(0, 0), NULL, nodename);
            lsadc_device_node[count]->platform_data = (int*)kmalloc(sizeof(int),GFP_KERNEL);
            *(int *)(lsadc_device_node[count]->platform_data) = i;
            ret = rtk_lsadc_create_attr(lsadc_device_node[count]);
            count ++;
        }
    }
    if(0 == count)
        return -1;
    else
        return 0;

}

void rtk_lsadc_dev_attr_unint(void)
{
    int i = 0;

    for(i = 0; i < MAX_LSADC_COUNT; i++){
        if(NULL !=lsadc_device_node[i]){
        rtk_lsadc_remove_attr(lsadc_device_node[i]);
        kfree(lsadc_device_node[i]->platform_data);
        }
    }
}

