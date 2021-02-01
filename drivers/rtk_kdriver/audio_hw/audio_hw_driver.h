#ifndef AUDIO_HW_DRIVER_H
#define AUDIO_HW_DRIVER_H

#include <linux/types.h>		/* size_t, dev_t */
#include <linux/mutex.h>		/* mutex */
#include <linux/cdev.h>			/* char device */

struct device;
struct class;
struct audio_hw_pm;

struct audio_hw_drvdata {
	dev_t devt;
	struct cdev cdev;
	struct mutex mtx;
	struct class *cls;
	struct device *clsdev;
	struct audio_hw_pm *pm;
};

extern struct audio_hw_drvdata *audio_driver_data;

#endif
