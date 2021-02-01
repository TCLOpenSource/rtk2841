#ifndef __RTK_DDC_DEV_H__
#define __RTK_DDC_DEV_H__
#include <linux/platform_device.h>
/*
 *  for platform_device
 */

/*
 *  for driver
 */
int rtk_ddc_platform_device_init(int*);
int rtk_ddc_platform_device_exit(void);

#endif
