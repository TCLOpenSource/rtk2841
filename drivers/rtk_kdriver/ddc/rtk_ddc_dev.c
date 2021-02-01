#include "rtk_ddc_dev.h"
#include "rtk_ddc_common.h"

/*
 *  for platform_device
 */
#include <rbus/iso_misc_ddc0_reg.h>
#include <rbus/iso_misc_ddc1_reg.h>
#include <rbus/iso_misc_ddc2_reg.h>
#include <rbus/iso_misc_ddc3_reg.h>
#include <rbus/misc_ddc_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/stb_reg.h>
#include <rtk_kdriver/tvscalercontrol/hdmirx/hdmifun.h>

#define RTK_DDC0_REG_SIZE       0xDC
#define RTK_DDC1_REG_SIZE       0xDC
#define RTK_DDC2_REG_SIZE       0xDC
#define RTK_DDC3_REG_SIZE       0xDC
#define RTK_DDC4_REG_SIZE       0xDC
#define RTK_STB_REG_SIZE        0x48
#define RTK_SYS_RST_SIZE        0x120


static struct resource rtk_ddc_resource0[]=
{
        {
                .name   = RTK_RESOURCE_NAME_DDC,
                .start  = ISO_MISC_DDC0_I2C_CR_reg,
                .end    = ISO_MISC_DDC0_I2C_CR_reg + RTK_DDC0_REG_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_STB,
                .start  = STB_ST_CTRL0_reg,
                .end    = STB_ST_CTRL0_reg + RTK_STB_REG_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_SYS_RST,
                .start  = SYS_REG_SYS_SRST0_reg,
                .end    = SYS_REG_SYS_SRST0_reg + RTK_SYS_RST_SIZE,
                .flags  = IORESOURCE_MEM,
        },
};

static srtk_ddc_platform_data rtk_ddc_platform_data0 =
{
        .ddc_type       = DDC_VGA,
        .write_debounce = 2,
        .read_delay     = 1,
        .clock_enable_mask  = STB_ST_CLKEN1_clken_ddc_mask,
        .reset_mask         = STB_ST_SRST1_rstn_ddc_mask,
};

static struct resource rtk_ddc_resource1[]=
{
        {
                .name   = RTK_RESOURCE_NAME_DDC,
                .start  = ISO_MISC_DDC1_I2C_CR_reg,
                .end    = ISO_MISC_DDC1_I2C_CR_reg + RTK_DDC1_REG_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_STB,
                .start  = STB_ST_CTRL0_reg,
                .end    = STB_ST_CTRL0_reg + RTK_STB_REG_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_SYS_RST,
                .start  = SYS_REG_SYS_SRST0_reg,
                .end    = SYS_REG_SYS_SRST0_reg + RTK_SYS_RST_SIZE,
                .flags  = IORESOURCE_MEM,
        },
};

static srtk_ddc_platform_data rtk_ddc_platform_data1 =
{
        .ddc_type       = DDC_HDMI,
        .write_debounce = 2,
        .read_delay     = 1,
        .clock_enable_mask  = STB_ST_CLKEN1_clken_ddc1_mask,
        .reset_mask         = STB_ST_SRST1_rstn_ddc1_mask,
};

static struct resource rtk_ddc_resource2[]=
{
        {
               .name   = RTK_RESOURCE_NAME_DDC,
               .start  = ISO_MISC_DDC2_I2C_CR_reg,
               .end    = ISO_MISC_DDC2_I2C_CR_reg + RTK_DDC2_REG_SIZE,
               .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_STB,
                .start  = STB_ST_CTRL0_reg,
                .end    = STB_ST_CTRL0_reg + RTK_STB_REG_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_SYS_RST,
                .start  = SYS_REG_SYS_SRST0_reg,
                .end    = SYS_REG_SYS_SRST0_reg + RTK_SYS_RST_SIZE,
                .flags  = IORESOURCE_MEM,
        },
};

static srtk_ddc_platform_data rtk_ddc_platform_data2 =
{
        .ddc_type       = DDC_HDMI,
        .write_debounce = 2,
        .read_delay     = 1,
        .clock_enable_mask  = STB_ST_CLKEN1_clken_ddc2_mask,
        .reset_mask         = STB_ST_SRST1_rstn_ddc2_mask,
};

static struct resource rtk_ddc_resource3[]=
{
        {
                .name   = RTK_RESOURCE_NAME_DDC,
                .start  = ISO_MISC_DDC3_I2C_CR_reg,
                .end    = ISO_MISC_DDC3_I2C_CR_reg + RTK_DDC3_REG_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_STB,
                .start  = STB_ST_CTRL0_reg,
                .end    = STB_ST_CTRL0_reg + RTK_STB_REG_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_SYS_RST,
                .start  = SYS_REG_SYS_SRST0_reg,
                .end    = SYS_REG_SYS_SRST0_reg + RTK_SYS_RST_SIZE,
                .flags  = IORESOURCE_MEM,
        },
};

static srtk_ddc_platform_data rtk_ddc_platform_data3 =
{
        .ddc_type       = DDC_HDMI,
        .write_debounce = 2,
        .read_delay     = 1,
        .clock_enable_mask  = STB_ST_CLKEN1_clken_ddc3_mask,
        .reset_mask         = STB_ST_SRST1_rstn_ddc3_mask,
};

#if MHL_SUPPORT
static struct resource rtk_ddc_resource4[]=
{
        {
                .name   = RTK_RESOURCE_NAME_DDC,
                .start  = MISC_DDC_I2C_CR_reg,
                .end    = MISC_DDC_I2C_CR_reg + RTK_DDC0_REG_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_STB,
                .start  = STB_ST_CTRL0_reg,
                .end    = STB_ST_CTRL0_reg + RTK_STB_REG_SIZE,
                .flags  = IORESOURCE_MEM,
        },
        {
                .name   = RTK_RESOURCE_NAME_SYS_RST,
                .start  = SYS_REG_SYS_SRST0_reg,
                .end    = SYS_REG_SYS_SRST0_reg + RTK_SYS_RST_SIZE,
                .flags  = IORESOURCE_MEM,
        },
};

static srtk_ddc_platform_data rtk_ddc_platform_data4 =
{
        .ddc_type       = DDC_MHL,
        .write_debounce = 2,
        .read_delay     = 1,
        .clock_enable_mask  = STB_ST_CLKEN1_clken_cbus_mask,
        .reset_mask         = STB_ST_SRST1_rstn_cbus_mask,
};
#endif

static void rtk_ddc_platform_device_release(struct device * dev)
{
    return;
}

#define RTK_DDC_PLATFORM_DEVICE(index)                                              \
        {                                                                           \
                .name           = RTK_DDC_NAME,                                     \
                .id             = index,                                            \
                .resource       = rtk_ddc_resource##index,                          \
                .num_resources  = ARRAY_SIZE(rtk_ddc_resource##index),              \
                .dev            =                                                   \
                {                                                                   \
                        .release        = rtk_ddc_platform_device_release,          \
                        .platform_data  = &rtk_ddc_platform_data##index,            \
                }                                                                   \
        }

static struct platform_device rtk_ddc_platform_devices[] =
{
        RTK_DDC_PLATFORM_DEVICE(0),     // for VGA
        RTK_DDC_PLATFORM_DEVICE(1),     // for HDMI PHY0
        RTK_DDC_PLATFORM_DEVICE(2),     // for HDMI PHY1
        RTK_DDC_PLATFORM_DEVICE(3),     // for HDMI PHY2
#if MHL_SUPPORT
        RTK_DDC_PLATFORM_DEVICE(4),
#endif
};

/*
 *  for driver
 */
static int num_registered_ddc_dev = 0;
int rtk_ddc_platform_device_exit(void)
{
    int i = 0;
    for(i=0;i<num_registered_ddc_dev;i++)
    {
        platform_device_unregister(&rtk_ddc_platform_devices[i]);
    }
    num_registered_ddc_dev=0;
    return 0;
}

int rtk_ddc_platform_device_init(int* numDev)
{
    int ret     = 0;
    int i       = 0;

    for(i=0;i<ARRAY_SIZE(rtk_ddc_platform_devices);i++)
    {
        ret = platform_device_register(&rtk_ddc_platform_devices[i]);
        if(ret)
        {
            num_registered_ddc_dev=i+1;
            RTK_DDC_ERR("platform device register failed\n");
            goto failure_register_ddc_platform_device;
        }
        num_registered_ddc_dev++;
    }
    *numDev = num_registered_ddc_dev;
    return ret;

failure_register_ddc_platform_device:
    rtk_ddc_platform_device_exit();
    return ret;
}

