#ifndef _LINUX_LIB_RTD_HOTPLUG_H
#define _LINUX_LIB_RTD_HOTPLUG_H

/*
 *  rtd_hotplug.h Copyright (C) 2010 Ching-Yuh Huang
 *  RTD kobject uevent of block subsystem header file by
 *      Ching-Yuh Huang
 *
 *      <cyhuang@realtek.com>
 */

typedef enum rtd_uevent
{
    RTD_HOTPLUG_NONE_BLOCK_UEVENT = 0,
	RTD_HOTPLUG_BLOCK_UEVENT = 1,
    RTD_HOTPLUG_HIDE_BLOCK_UEVENT = 2,
} rtd_uevent_t;

extern rtd_uevent_t RtdBlockHotplugUevent(struct kobject *kobj,const char *subsystem,struct kobj_uevent_env *env);

#endif // _LINUX_LIB_RTD_HOTPLUG_H

