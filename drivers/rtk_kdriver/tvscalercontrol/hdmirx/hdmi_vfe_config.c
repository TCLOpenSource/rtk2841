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
#include "hdmi_vfe_config.h"
#include <rtk_kdriver/rtk_gpio.h>
#include "hdmi_debug.h"
#include "hdmiInternal.h"


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


int hdmi_vfe_get_rx_port_info(unsigned char port, HDMI_CHANNEL_T_PCB_INFO *p_info)
{
    unsigned long long value;
    unsigned long long val;
    char name[32]   ={0};

    snprintf(name, sizeof(name)-1, "HDMI%d_CFG", port+1);

    if (pcb_mgr_get_enum_info_byname(name, &val)==0)
    {
        /**********************HDMI_CFG format************************
         *  D63:60  : HDMI1_PHY_PORT
         *  D59     : HDMI SUPPORT ARC
         *  D58:56  : HDMI1_DDC
         *  D55:54  : HDMI1_EDID_TYPE       (0: on chip, 1:EEPROM 2: with MUX, 3:Not used)
         *  D53:52  : HDMI1_HPD_TYPE        (0: on chip, 1: with MUX, 2:Not used)
         *  D51:40  : Reserved
         *  D39:36  : HDMI1_MUX_PORT
         *  D35:32  : HDMI1_MUX_IC
         *  D31:28  : 5V_DET_GPIO_TYPE      (0: GPI, 1:GPO)
         *  D27     : Reserved
         *  D26     : 5V_DET_GPIO_INIT_VAL  (0: INIT_VALUE, 1: INIT_VALUE)
         *  D25     : 5V_DET_GPIO_POLARITY  (0: negative, 1: positive)
         *  D24     : 5V_DET_GPIO_PIN_TYPE  (0: MISC, 1: ISO)
         *  D23:16  : 5V_DET_GPIO_INDEX     (GPIO ID of 5V detect)
         *  D15:12  : HOTPLUG_GPIO_TYPE     (0: GPI, 1:GPO)
         *  D11     : Reserved
         *  D10     : HOTPLUG_GPIO_INIT_VAL (0: INIT_VALUE, 1: INIT_VALUE)
         *  D9      : HOTPLUG_GPIO_POLARITY (0: negative, 1: positive)
         *  D8      : HOTPLUG_GPIO_PIN_TYPE (0: MISC, 1: ISO)
         *  D7:0    : HOTPLUG_GPIO_INDEX    (GPIO ID of Hotplug GPIO)
         *****************************************************************/
        p_info->phy_port     =(HDMI_PHY_PORT_T) ((val >> 60) & 0xf);
        p_info->ddc_selected =(DDC_NUMBER_T)((val >> 56) & 0x7);
        p_info->edid_type    =(HDMI_EDID_TYPE_T)((val >> 54) & 0x7);

        p_info->hpd          = rtk_gpio_id((val & (0x1<<8))  ? ISO_GPIO : MIS_GPIO, (val & 0xFF));
        p_info->det_5v       = rtk_gpio_id((val & (0x1<<24)) ? ISO_GPIO : MIS_GPIO, ((val>>16) & 0xFF));
        p_info->arc_support  = (val >> 59) & 0x1;
    }
    else
    {
        //----------------------------
        // get Phy port
        //----------------------------
        snprintf(name, sizeof(name)-1,"HDMI%d_PHY_PORT", port+1);
        if (pcb_mgr_get_enum_info_byname(name, &val))
        {
            HDMI_EMG("missing PCB parameter -%s\n", name);
            goto fail;
        }
        p_info->phy_port = (HDMI_PHY_PORT_T) val;

        //----------------------------
        // get DDC channel
        //----------------------------
        snprintf(name, sizeof(name)-1, "HDMI%d_DDC", port+1);
        if (pcb_mgr_get_enum_info_byname(name, &val) < 0)
        {
            HDMI_EMG("missing PCB parameter -%s\n", name);
            goto fail;
        }
        p_info->ddc_selected = val;

        //----------------------------
        // get DDC channel
        //----------------------------
        snprintf(name, sizeof(name)-1, "HDMI%d_EDID_TYPE", port+1);

        if ((pcb_mgr_get_enum_info_byname(name, &val) < 0) || (value > HDMI_EDID_DISABLE))
            p_info->edid_type = HDMI_EDID_ONCHIP;
        else
            p_info->edid_type = (HDMI_EDID_TYPE_T) val;

        //----------------------------
        // 5V Det
        //----------------------------
        snprintf(name, sizeof(name)-1, "PIN_5V_DET_HDMI_%d", port+1);
        if ((pcb_mgr_get_enum_info_byname(name, &val) < 0))
        {
            HDMI_EMG("missing PCB parameter -%s\n", name);
            goto fail;
        }

        if (_pininfo_to_gpio_id(val, &p_info->det_5v)<0)
            goto fail;

        //----------------------------
        // hpd
        //----------------------------
        snprintf(name, sizeof(name)-1, "PIN_HDMI%d_HOTPLUG", port+1);

        if ((pcb_mgr_get_enum_info_byname(name, &val) < 0))
        {
            HDMI_EMG("missing PCB parameter -%s\n", name);
            goto fail;
        }

        if (_pininfo_to_gpio_id(val, &p_info->hpd)<0)
            goto fail;

        p_info->arc_support = 0;
    }

    HDMI_EMG("HDMI Port[%d] : Phy=%d, ddc_bus=%d, edid_type=%d, hpd=%s_%d, 5v_det=%s_%d, arc_support=%d\n",
        port, p_info->phy_port, p_info->ddc_selected, p_info->edid_type,
        gpio_type(gpio_group(p_info->hpd)), gpio_idx(p_info->hpd),
        gpio_type(gpio_group(p_info->det_5v)), gpio_idx(p_info->det_5v),
        p_info->arc_support);

    return 0;

fail:
    p_info->phy_port = HDMI_PHY_PORT_NOTUSED;
    return 1;
}


/*-------------------------------------------------
 * Func : hdmi_vfe_get_hdmi_port
 *
 * Desc : convert from logical hdmi channel to 
 *        phyiscal hdmi port
 *
 * Para : ch : hdmi channel input
 *        p_port : hdmi port output
 *
 * Retn : Physical HDMI port
 *-------------------------------------------------*/
int hdmi_vfe_get_hdmi_port(unsigned char ch, unsigned char* p_port)
{
	if (p_port==NULL || ch >= HDMI_RX_PORT_MAX_NUM) {
		HDMI_WARN("%s failed, ch=%d\n", __func__, ch);
		return -1;
	}
	
	*p_port = ch;
	return 0;
}


/*-------------------------------------------------
 * Func : hdmi_vfe_get_hdmi_channel
 *
 * Desc : convert from phyiscal hdmi port to logical hdmi channel 
 *
 * Para : port : hdmi port input
 *        p_ch : hdmi channel output
 *
 * Retn : Physical HDMI port
 *-------------------------------------------------*/
int hdmi_vfe_get_hdmi_channel(unsigned char port, unsigned char* p_ch)
{
	unsigned char ch;
	
	if (p_ch==NULL || port >= HDMI_RX_PORT_MAX_NUM) {
		HDMI_WARN("%s failed, port=%d\n", __func__, port);
		return -1;
	}
	
    *p_ch = port;
    return 0;	
}


char hdmi_vfe_get_arc_channel(void)
{
    unsigned long long val;
    unsigned char ui_port, arc_port_num=0;
    char arc_port =0;

    if (pcb_mgr_get_enum_info_byname("PCB_ARC_CHANNEL", &val) == 0)
    {
        //check ARC_CHANNEL define if HDMI1_CFG don't define
        return (char)val;
    }
    else
    {
        HDMI_CHANNEL_T_PCB_INFO info;

        pr_err("get_ARC_channel old fail!\n");

        for (ui_port = 0; ui_port < HDMI_RX_PORT_MAX_NUM; ui_port++)
        {
            if (hdmi_vfe_get_rx_port_info(ui_port, &info)<0)
                continue;

            if (info.arc_support)
            {
                arc_port = ui_port;
                arc_port_num++;
            }
        }

        if(arc_port_num == 0)
        {
            HDMI_EMG("NONE_ARC_PORT\n");
            arc_port = NONE_ARC_PORT;
        }
        else if(arc_port_num > 1)
        {
            arc_port= MULTI_ARC_PORT;
            HDMI_EMG("MULTI_ARC_PORT\n");
        }
    }

    return arc_port;
}
