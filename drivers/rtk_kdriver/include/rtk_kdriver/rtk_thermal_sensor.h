#ifndef __ARCH_ARM_RTK_THERMAL_H
#define __ARCH_ARM_RTK_THERMAL_H
#include <linux/kref.h>
#include <linux/list.h>
#include <linux/platform_device.h>
void init_rtk_thermal_sensor(void);
void exit_rtk_thermal_sensor(void);
int rtk_get_thermal_value(void);
void rtk_thermal_sensor_enable(int enable);
unsigned int rtk_get_thermal_reg(void);
int rtk_get_thermal_value_ext(void);
int rtk_thermal_trigger_low(int temp_low);
int rtk_thermal_trigger_high(int temp_high);
int rtk_thermal_int_status(void);

#define THERMAL_DBG(fmt, args...)               rtd_printk(KERN_DEBUG, "THERMAL","[DBG] " fmt, ## args)
#define THERMAL_INFO(fmt, args...)              rtd_printk(KERN_INFO , "THERMAL",  "[Info] " fmt, ## args)
#define THERMAL_WARNING(fmt, args...)      rtd_printk(KERN_WARNING , "THERMAL", "[Warn] " fmt, ## args)
#define THERMAL_ERR(fmt, args...)               rtd_printk(KERN_ERR , "THERMAL", "[Err] " fmt, ## args)

#endif
