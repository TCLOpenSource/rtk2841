#ifndef __RTK_DDC_DRV_H__
#define __RTK_DDC_DRV_H__
#include <linux/platform_device.h>
#include "rtk_ddc_common.h"

#define RTK_EDID_MAX_LEN    256

typedef struct srtk_edid{
    int len;
    unsigned char content[RTK_EDID_MAX_LEN];
}srtk_edid;

typedef struct srtk_ddc_chip{
    int             id;
    int             is_fs_registered;
    int             write_debounce;
    int             read_delay;
    unsigned int    clock_enable_mask;
    unsigned int    reset_mask;
    char            name[RTK_DDC_NAME_MAX];
    ERTK_DDC_TYPE   ddc_type;
    struct device   *dev;
    struct class    class;
    unsigned int     base;
    unsigned int     reset_base;
    unsigned int     standby_base;
    struct resource *resource;
    struct resource *reset_resource;
    struct resource *standby_resource;
    struct mutex    rw_edid_mutex;
} srtk_ddc_chip;

int rtk_ddc_drv_set_read_delay(srtk_ddc_chip* pchip);
int rtk_ddc_drv_set_write_debounce(srtk_ddc_chip* pchip);
int rtk_ddc_drv_crt_on(void);
int rtk_ddc_drv_set_enable(srtk_ddc_chip* pchip, int enable);
int rtk_ddc_drv_is_enable(srtk_ddc_chip* pchip);
int rtk_ddc_drv_is_enable(srtk_ddc_chip* pchip);
int rtk_ddc_drv_edid_content_is_valid(int content_len,const unsigned char* content);
int rtk_ddc_drv_enable_external_dev_access(srtk_ddc_chip* pchip,int enable);
int rtk_ddc_drv_reset(srtk_ddc_chip* pchip);
int rtk_ddc_drv_read(srtk_ddc_chip* pchip, srtk_edid* pedid);
int rtk_ddc_drv_write(srtk_ddc_chip* pchip, srtk_edid* pedid);

#endif
