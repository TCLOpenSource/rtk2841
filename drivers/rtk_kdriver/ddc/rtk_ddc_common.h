#ifndef __RTK_DDC_COMMON_H__
#define __RTK_DDC_COMMON_H__
#include "rtk_ddc_dbg.h"

#define RTK_DDC_NAME                "rtk_ddc"
#define RTK_RESOURCE_NAME_DDC       "DDC"
#define RTK_RESOURCE_NAME_STB       "STANDBY"
#define RTK_RESOURCE_NAME_SYS_RST   "CRT_RESET"

#define RTK_DDC_NAME_MAX        24
#define RTK_DDC_MAX_NUM         6

typedef enum
{
    DDC_HDMI,
    DDC_MHL,
    DDC_VGA,
    MAX_DDC_TYPE
} ERTK_DDC_TYPE;

typedef struct srtk_ddc_platform_data
{
    ERTK_DDC_TYPE ddc_type;
    int write_debounce;
    int read_delay;
    unsigned int clock_enable_mask;
    unsigned int reset_mask;
} srtk_ddc_platform_data;

#endif
