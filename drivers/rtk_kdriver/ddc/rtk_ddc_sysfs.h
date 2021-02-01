#ifndef __RTK_DDC_SYSFS_H__
#define __RTK_DDC_SYSFS_H__
#include "rtk_ddc_drv.h"

#define RTK_DDC_SYSFS_CLASS     "rtk_ddc"

int rtk_ddc_sysfs_create(srtk_ddc_chip*);
int rtk_ddc_sysfs_destroy(srtk_ddc_chip*);
#endif
