/*
 * rtd_hotplug.c
 *
 * The hotplug of block layer functions
 *
 * Copyright (C) 2010 Ching-Yuh Huang <cyhuang@realtek.com>
 *
 * Author : Ching-Yuh Huang
 * Date   : 2010/10/27
 *
 */
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/genhd.h>
#include <linux/ctype.h> // for isdigit()

#include "rtd_hotplug.h"

// ----------------------------------------------------------------------------------------------------------
/*
 *
 *      Add for Hotplug helper function API.
 */

/**
 * rtd_get_device_by_type_name - get "type name" device
 * @blk_dev: device of block
 * @type_name: device type name
 *
 * This function get parent device for the given device @blk_dev and @type_name.
 *
 */

static struct device *rtd_get_device_by_type_name(struct device *blk_dev,const char *type_name)
{
	struct device *dev = blk_dev;

	if (blk_dev == NULL)
		return NULL;

	while(dev)
	{
		dev = dev->parent;

		if (dev && dev->type && dev->type->name && (!strncmp(dev->type->name,type_name,strlen(type_name))))
		{
			return dev;
		}
	}

	return NULL;
}

/**
 * rtd_get_device_by_bus_name - get device by "bus name"
 * @blk_dev: device of block
 * @bus_name: bus name of device
 *
 * This function get parent device for the given device @blk_dev and @bus_name.
 *
 */

static struct device *rtd_get_device_by_bus_name(struct device *blk_dev,const char *bus_name)
{
	struct device *dev = blk_dev;

	if (blk_dev == NULL)
		return NULL;


	while(dev)
	{
		dev = dev->parent;

		if (dev && dev->bus && dev->bus->name && (!strncmp(dev->bus->name,bus_name,strlen(bus_name))))
		{
			return dev;
		}
	}

	return NULL;
}


/**
 * rtd_disk_get_part_num - get number of total parts.
 * @gd : gendisk of block
 *
 * This function get parent disk and return total parts for the given gendisk @gd.
 *
 */
/*
   static int rtd_disk_get_part_num(struct gendisk *gd)
   {
   int i,part_num = 0;
   struct disk_part_tbl *ptbl = NULL;

   if (gd == NULL)
   return -ENODEV;

//rcu_read_lock();
ptbl = gd->part_tbl;
//ptbl = rcu_dereference(gd->part_tbl);

if (ptbl == NULL)
{
//rcu_read_unlock();
return -ENOMEM;
}

for (i=0;i<ptbl->len;i++)
{
if (ptbl->part[i])
part_num++;

}

//rcu_read_unlock();
return part_num -1;
}
 */


/**
 * rtd_disk_get_parent - get parent of gendisk.
 * @gd : gendisk of block
 *
 * This function get parent disk for the given gendisk @gd.
 *
 */
static inline struct gendisk *rtd_disk_get_parent(struct gendisk *disk)
{
	if (disk == NULL)
		return NULL;

	return part_to_disk(&disk->part0);
}

/**
 * rtd_disk_is_single_part - check disk is single partition.
 * @gd : gendisk of block
 *
 * @return : true => single , false => multi-partition.
 * This function check the gendisk is single partition or not for the given gendisk @gd.
 *
 */

static inline bool rtd_disk_is_single_part(struct gendisk *disk)
{
	struct disk_part_tbl *ptbl = NULL;

	if (disk == NULL)
		return false;

	if (disk->part0.partno >= 1)
		return true;

	//rcu_read_lock();

	ptbl = disk->part_tbl;
	//ptbl = rcu_dereference(disk->part_tbl);

	if (ptbl == NULL)
	{
		//rcu_read_unlock();
		return false;
	}

	// printk("%s [DEBUG] : dev = %s ,ptbl->len = %d \n",__func__,dev_name(disk_to_dev(disk)),ptbl->len);

	if (ptbl->len <= 1)
	{
		//rcu_read_unlock();
		return true;
	}

	//rcu_read_unlock();
	return false;
}

/**
 * rtd_device_get_bus_type - Get bus type name of device.
 * @dev : Device
 *
 * @return : Bus name , NULL => Can not find bus name.
 * This function get the bus type name  for the given device @dev.
 *
 */

static inline char *rtd_device_get_bus_type(struct device *dev)
{
	struct device *phy_bus_dev = NULL;
	char *bus_type = NULL;

	phy_bus_dev = rtd_get_device_by_bus_name(dev,"usb");

	if (phy_bus_dev)
	{
		bus_type = "usb";
		return bus_type;
	}

	// Find platform physical bus.
	phy_bus_dev = rtd_get_device_by_bus_name(dev,"platform");

	if (phy_bus_dev && phy_bus_dev->driver && phy_bus_dev->driver->name)
	{
		/* cyhuang (2011/02/11) : SATA use platform bus not older SATA bus. */
		if (!strncmp(phy_bus_dev->driver->name,"sata",strlen("sata")))
			bus_type = "sata";
		else if (!strncmp(phy_bus_dev->driver->name,"rtksdio",strlen("rtksdio")))
			bus_type = "card";
		else
			bus_type = (char *) phy_bus_dev->bus->name;

		// printk("%s [DEBUG] : phys bus name = %s\n",__func__,bus_type);
	}

	return bus_type;
}

/**
 * RtdBlockHotplugUevent - Hack function in kobject_uevent_env() <kobject_uevent.c>.
 * @kobj: kernel objec
 * @subsystem: subsystem string (block)
 * @env: environment variable of user helper funtion.
 *
 * This function send uevent of block subsystem for RTD hotplug.
 *
 */
rtd_uevent_t RtdBlockHotplugUevent(struct kobject *kobj,const char *subsystem,struct kobj_uevent_env *env)
{
	struct device *dev;
	struct device *scsi_dev = NULL;
	struct gendisk *disk = NULL;
	char *bus_type = NULL;
	char *kobj_path = NULL;
	char *block_path = NULL;
	int is_part = 0;
	int part_serial = 0;
	int nparts = 0;
	int partno = 0;
	struct disk_part_iter piter;
	struct hd_struct *part;

	// Not block subsystem
	if ((subsystem == NULL) || strncmp(subsystem,"block",5))
		return RTD_HOTPLUG_NONE_BLOCK_UEVENT;

	if (kobj == NULL)
		return RTD_HOTPLUG_NONE_BLOCK_UEVENT;

	// kobj_path of emmc, sdio, and scsi_disk
	// emmc /devices/platform/rtkemmc/mmc_host/mmc0/mmc0:0001/block/mmcblk0
	//      /devices/platform/rtkemmc/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p1
	//      /devices/platform/rtkemmc/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0boot1
	// sdio /devices/platform/rtksdio/mmc_host/mmc1/mmc1:f730/block/mmcblk1
	//      /devices/platform/rtksdio/mmc_host/mmc1/mmc1:f730/block/mmcblk1/mmcblk1p1
	// scsi_disk /devices/platform/xhci-hcd/usb1/1-2/1-2:1.0/host0/target0:0:0/0:0:0:0/block/sda
	//           /devices/platform/xhci-hcd/usb1/1-2/1-2:1.0/host0/target0:0:0/0:0:0:0/block/sda/sda1

	kobj_path = kobject_get_path(kobj, GFP_KERNEL);
	if (kobj_path == NULL)
		return RTD_HOTPLUG_NONE_BLOCK_UEVENT;

	block_path = strstr(kobj_path, "block");
	if (block_path == NULL)
		return RTD_HOTPLUG_NONE_BLOCK_UEVENT;

#ifndef CONFIG_ANDROID
	// skip emmc block devices
	if ((strstr(kobj_path, "emmc"))) {
		kfree(kobj_path);
		return RTD_HOTPLUG_HIDE_BLOCK_UEVENT;
	}

	// Not a scsi disk or sdio devices
	if (!(strstr(kobj_path, "sd"))) {
		kfree(kobj_path);
		return RTD_HOTPLUG_NONE_BLOCK_UEVENT;
	}
#else 

	// installer will program mmcblk0boot0 and mmcblk0boot1, so don't skip
	// skip emmc block like mmcblk0boot0 or mmcblk0boot1
	//if ((strstr(kobj_path, "boot")) && (strstr(kobj_path, "emmc"))) {
	//	kfree(kobj_path);
	//	return RTD_HOTPLUG_HIDE_BLOCK_UEVENT;
	//}

	// Not a scsi disk or sdio devices
	//if (!(strstr(kobj_path, "sd"))) {
	// Not a scsi disk , sdio devices, or emmc block
	if (!(strstr(kobj_path, "sd") || strstr(kobj_path, "emmc"))) {
		kfree(kobj_path);
		return RTD_HOTPLUG_NONE_BLOCK_UEVENT;
	}
#endif

	dev = kobj_to_dev(kobj);

	if (dev == NULL)
		return RTD_HOTPLUG_NONE_BLOCK_UEVENT;

	// this dev is a partition of disk
	// for a scsi disk
	if (strstr(block_path, "sd")) {
		is_part = isdigit(block_path[strlen(block_path) - 1]);
		if (is_part)
			disk = dev_to_disk(dev->parent);
		else
			disk = dev_to_disk(dev);
		// for emmc/sdio block
	} else {
		is_part = strstr(strstr(block_path, "mmcblk"), "p");
		if (is_part)
			disk = dev_to_disk(dev->parent);
		else
			disk = dev_to_disk(dev);
	}

	kfree(kobj_path);

	if (disk == NULL)
		return RTD_HOTPLUG_NONE_BLOCK_UEVENT;

	disk_part_iter_init(&piter, disk,
			DISK_PITER_INCL_EMPTY | DISK_PITER_REVERSE);
	while ((part = disk_part_iter_next(&piter))) {
		if (dev == part_to_dev(part)) {
#ifdef CONFIG_RTK_HOT_PLUG_SUPPORT			
			part_serial = part->part_serial;
			nparts = part->nparts;
#endif			
			partno = part->partno;
		}
	}
	disk_part_iter_exit(&piter);


#if defined(CONFIG_ANDROID)
	if (rtd_disk_get_parent(disk)->signature)
	{
		disk->signature = rtd_disk_get_parent(disk)->signature;
	}
#else
	// Hide not signle partition for sdx (Ex : sda)
	if (!is_part && (rtd_disk_is_single_part(disk) == false))
	{
		// printk("%s [DEBUG] : dev = %s , none single\n",__func__,dev_name(dev));
		if (!is_part)
			return RTD_HOTPLUG_HIDE_BLOCK_UEVENT;
	} else {
		if (rtd_disk_get_parent(disk)->signature) {
			disk->signature = rtd_disk_get_parent(disk)->signature;
		}
	}
#endif

	// In Android VOLD, we need the extend partition info.
#if 0
#ifndef CONFIG_ANDROID
	// Hide extended partition.
	if ((disk->part_extended != 0) && (partno == disk->part_extended))
	{
		// printk("%s [DEBUG] : dev = %s , part_extended\n",__func__,dev_name(dev));
		return RTD_HOTPLUG_HIDE_BLOCK_UEVENT;
	}
#endif
#endif

	// Find SCSI Device.
	scsi_dev = rtd_get_device_by_type_name(dev,"scsi_device");

	if (scsi_dev)
	{
		char *path = kobject_get_path(&scsi_dev->kobj, GFP_KERNEL);

		if (path)
		{
			// printk("%s [DEBUG] : path = %s , type name = %s\n",__func__,path,scsi_dev->type->name);
			add_uevent_var(env, "PHYSDEVPATH=%s", path);
			kfree(path);
		}
	}

	bus_type = rtd_device_get_bus_type(dev);

	if (bus_type)
		add_uevent_var(env, "BUS_TYPE=%s", bus_type);

	if (disk)
	{

#ifdef CONFIG_ANDROID
		if (is_part)
			add_uevent_var(env, "NPARTS=%d", nparts);
		else
			add_uevent_var(env, "NPARTS=%d", disk->part_num);
		add_uevent_var(env, "PARTN=%d", part_serial);
#else
		add_uevent_var(env, "PART_NUM=%d", disk->part_num);
		add_uevent_var(env, "PART_SERIAL=%d", part_serial);
#endif /* CONFIG_ANDROID */
		add_uevent_var(env, "PORT_STRUCT=%s", disk->port_structure);
		add_uevent_var(env, "PART_EXTENDED=%d", disk->part_extended);
		add_uevent_var(env, "PART_EXTENDED_SERIAL=%d", disk->part_extended_serial);

		if (disk->signature)
			add_uevent_var(env, "RT_SIGNATURE=%d", disk->signature);

		// printk("%s [DEBUG] : dev = %s ,PART_NUM=%d , PART_EXTENDED=%d , PART_EXTENDED_SERIAL=%d , NPARTS=%d\n",__func__,dev_name(dev),disk->part_num, disk->part_extended, disk->part_extended_serial, nparts);
	}

	return RTD_HOTPLUG_BLOCK_UEVENT;
}

