/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#ifndef __RTK_CEC_H__
#define __RTK_CEC_H__

#include <linux/device.h>
#include <rtk_kdriver/rtk_diseqc.h>
#include "rtk_diseqc_debug.h"
#include "rtk_diseqc_data_buff.h"

extern struct bus_type diseqc_bus_type;

typedef struct {
	unsigned long id;
	char *name;
	struct device dev;
} diseqc_device;

#define to_diseqc_device(x)  container_of(x, diseqc_device, dev)

static inline void *diseqc_get_drvdata(diseqc_device *device)
{
	return dev_get_drvdata(&device->dev);
}

static inline void diseqc_set_drvdata(diseqc_device *device, void *data)
{
	struct device *dev = &device->dev;
	dev_set_drvdata(dev, data);
}

extern int register_diseqc_device(diseqc_device *device);
extern void unregister_diseqc_device(diseqc_device *device);

#define to_diseqc_driver(x)  container_of(x, diseqc_driver, drv)



typedef struct {
	char *name;
	struct device_driver drv;

	int (*probe)		(diseqc_device *dev);
	void (*remove)		(diseqc_device *dev);
	int (*xmit)		(diseqc_device *dev, diseqc_data_buff *cmg, unsigned long flags);
	int (*enable)		(diseqc_device *dev, unsigned char on_off);

	int (*suspend)	(diseqc_device *dev);
	int (*resume)	(diseqc_device *dev);

	int (* set_22k_on_off)(unsigned int diseqc_22k_on_off);
	int (* set_diseqc_cmd)(unsigned int data_length,unsigned char *data);
	int (* set_unmod_tone_burst)(void);
	int (* set_mod_tone_burst)(void);
	int (* set_tone_burst)(TONE_MODE mode);

	diseqc_data_buff * (*read) (diseqc_device *dev, unsigned long flags);

} diseqc_driver;

extern int register_diseqc_driver(diseqc_driver *driver);
extern void unregister_diseqc_driver(diseqc_driver *driver);

#define _BIT(x)         (1UL << x)
#define TEST_BIT(x, i) (x & (1<<i))




typedef enum {
	DISEQC_VERSION_1_1 = 0x00,
	DISEQC_VERSION_1_2 = 0x01,
	DISEQC_VERSION_1_2A = 0x02,
	DISEQC_VERSION_1_3 = 0x03,
	DISEQC_VERSION_1_3A = 0x04,
	DISEQC_VERSION_1_4 = 0x05,
	DISEQC_VERSION_UNKNOWN = 0xFF,
} DISEQC_VERSION;



#endif
