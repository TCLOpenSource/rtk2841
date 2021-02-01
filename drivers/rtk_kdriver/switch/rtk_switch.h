#ifndef __RTK_SWITCH_CLASS_H__
#define __RTK_SWITCH_CLASS_H__

#include <mach/rtk_log.h>

struct switch_dev {
    char name[26];
    struct device *dev;
    int index;
    int state;
    ssize_t (*print_name)(struct switch_dev *sdev, char *buf);
    ssize_t (*print_state)(struct switch_dev *sdev, char *buf);
};

int rtk_switch_get_state(struct switch_dev *sdev);
void rtk_switch_set_state(struct switch_dev *sdev, int state);
int rtk_switch_dev_register(struct switch_dev *sdev);
void rtk_switch_dev_unregister(struct switch_dev *sdev);

#define RTK_SWITCH_DEBUG(fmt, args...)	rtd_printk(KERN_DEBUG, "SWITCH" , fmt, ## args)
#define RTK_SWITCH_INFO(fmt, args...)	rtd_printk(KERN_INFO, "SWITCH" , fmt, ## args)
#define RTK_SWITCH_WARN(fmt, args...)	rtd_printk(KERN_WARNING, "SWITCH" , fmt, ## args)
#define RTK_SWITCH_ERR(fmt, args...)	rtd_printk(KERN_ERR  , "SWITCH" , fmt, ## args)

#endif
