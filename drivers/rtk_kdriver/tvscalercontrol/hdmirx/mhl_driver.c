/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file:        board.c
 *
 * author:  Star Lord, Peter Jason Quill
 * date:
 * version:     3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include <linux/kernel.h>
#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <rtk_kdriver/pcbMgr.h>
#include <rtk_kdriver/rtk_gpio.h>
#include "hdmi_debug.h"
#include "mhl_driver.h"

static int _pininfo_to_gpio_id(unsigned long long value, RTK_GPIO_ID* p_gid)
{
    switch (GET_PIN_TYPE(value))
    {
    case PCB_PIN_TYPE_GPIO:
        *p_gid = rtk_gpio_id(MIS_GPIO, GET_PIN_INDEX(value));
        break;

    case PCB_PIN_TYPE_ISO_GPIO:
        *p_gid = rtk_gpio_id(ISO_GPIO, GET_PIN_INDEX(value));
        break;

    default:
        HDMI_EMG("invalid pin type - %d\n", GET_PIN_TYPE(value));
        return -1;
    }

    return 0;
}


int get_is_support_mhl_circuit(void)
{
#if MHL_SUPPORT
    unsigned long long value = 0;
    if (pcb_mgr_get_enum_info_byname("PIN_MHL_CABLE_DETECT", &value) ==0)
        return 1;
#endif
    return 0;
}


int get_mhl_signal(void)
{
#if defined(CONFIG_CUSTOMER_TV001) ||  defined(CONFIG_CUSTOMER_TV030)  //CN

    unsigned long long value = 0;    
    
    if (pcb_mgr_get_enum_info_byname("PIN_MHL_CABLE_DETECT", &value) ==0)
    {
        RTK_GPIO_ID gid;    
        
        if (_pininfo_to_gpio_id(value, &gid)==0)
            return rtk_gpio_input(gid);                              
    }    
#endif

    return 0;
}


void set_hdmi_mhl_sel(unsigned char high_low)
{
    unsigned long long value = 0;
    RTK_GPIO_ID gid;    
    
    if (pcb_mgr_get_enum_info_byname("PIN_HDMI_MHL_SELECT", &value)==0 &&
        _pininfo_to_gpio_id(value, &gid)==0)
    {        
        rtk_gpio_output(gid, high_low);         
    }
    else
    {
        pr_debug("not set set_hdmi_mhl_sel\n");
    }
}


int get_hdmi_rx_mhl_channel(void)
{
    return 0;
}

