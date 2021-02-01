#ifndef __HDMI_ARC_PRIV_H__
#define __HDMI_ARC_PRIV_H__

/**************************************
 * ARC CFG
 **************************************
    D3:2    : default status    (0: default off, 1:default on, 2:default by pass this pinmux)
    D1:0    : ARC SPDIF Channel (now just use channel 0/1)
 **************************************/
#define ARC_CFG_ARC_DEFAULT_STATE(x)        ((x >>2) & 0x3)

#define ARC_DEFAULT_OFF          0
#define ARC_DEFAULT_ON           1
#define ARC_DEFAULT_DONT_CARE    2

#define ARC_CFG_ARC_SPDIF_CHANNEL(x)        (x & 0x3)


//------------------------------------------------------------------------
// Pin Mux information for each SOC
//------------------------------------------------------------------------
#include <rbus/pinmux_reg.h>
#include <rtk_kdriver/rtk_gpio.h>

typedef struct 
{    
    RTK_GPIO_ID   gid;                  // GPIO that associate with the SPDIF 
    unsigned int  pad_mux_reg;          // pin function selection register
    unsigned int  pad_mux_mask;         // pin function selection mask
    unsigned int  pad_mux_val_spdif;    // pin function selection value for spdif
    unsigned int  pad_mux_val_gpio;     // pin function selection value for gpio   
}RTK_SPDIF_INFO;


static RTK_SPDIF_INFO g_spdif_cfg[] =
{
    //spdif0-1
    {
        .gid               = rtk_gpio_id(MIS_GPIO, 39),
        .pad_mux_reg       = 0xB8000824,
        .pad_mux_mask      = (0xF<<28),
        .pad_mux_val_spdif = (9<<28),
        .pad_mux_val_gpio  = (0xF<<28),
    },
    
    //spdif-1
    {
        .gid               = rtk_gpio_id(ISO_GPIO, 17),
        .pad_mux_reg       = 0xB8060210,
        .pad_mux_mask      = (0xF<<20),
        .pad_mux_val_spdif = (9<<20),
        .pad_mux_val_gpio  = (0xF<<20),
    }
};

#define RTK_SPDIF_COUNT     (sizeof(g_spdif_cfg)/sizeof(RTK_SPDIF_INFO))



#endif // __HDMI_ARC_PRIV_H__
