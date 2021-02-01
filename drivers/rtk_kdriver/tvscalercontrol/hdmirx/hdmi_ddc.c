/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		hdmi_ddc.c
 *
 * author: 	Ant Man, Scott Lang
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include "hdmi_common.h"
#include <rtk_kdriver/rtk_ddc_lib.h>




/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/


/**********************************************************************************************
*
*	Const Declarations
*
**********************************************************************************************/



/**********************************************************************************************
*
*	Funtion Declarations
*
**********************************************************************************************/




/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/

void lib_hdmiddc_crt_on(void)
{
	hdmi_out(SYS_REG_SYS_SRST0_reg, (SYS_REG_SYS_SRST0_rstn_hdmi_common_mask|
		SYS_REG_SYS_SRST0_rstn_hdmi_pre3_mask|SYS_REG_SYS_SRST0_rstn_hdmi_pre2_mask|
		SYS_REG_SYS_SRST0_rstn_hdmi_pre1_mask|SYS_REG_SYS_SRST0_rstn_hdmi_pre0_mask|
		SYS_REG_SYS_SRST0_write_data_mask));
	hdmi_out(SYS_REG_SYS_SRST1_reg, (SYS_REG_SYS_SRST1_rstn_hdmi_mask|SYS_REG_SYS_SRST1_write_data_mask));

	hdmi_out(SYS_REG_SYS_CLKEN0_reg, (SYS_REG_SYS_CLKEN0_clken_hdmi_common_mask|
		SYS_REG_SYS_CLKEN0_clken_hdmi_pre3_mask|SYS_REG_SYS_CLKEN0_clken_hdmi_pre2_mask|
		SYS_REG_SYS_CLKEN0_clken_hdmi_pre1_mask|SYS_REG_SYS_CLKEN0_clken_hdmi_pre0_mask|
		SYS_REG_SYS_CLKEN0_write_data_mask));
	hdmi_out(SYS_REG_SYS_CLKEN1_reg, (SYS_REG_SYS_CLKEN1_clken_hdmi_mask|SYS_REG_SYS_CLKEN1_write_data_mask));


	hdmi_out(STB_ST_SRST1_reg, (STB_ST_SRST1_write_data_mask|STB_ST_SRST1_rstn_ddc1_mask|STB_ST_SRST1_rstn_ddc2_mask|STB_ST_SRST1_rstn_ddc3_mask|STB_ST_SRST1_rstn_ddc4_mask));
	hdmi_out(STB_ST_CLKEN1_reg, (STB_ST_CLKEN1_write_data_mask|STB_ST_CLKEN1_clken_ddc1_mask|STB_ST_CLKEN1_clken_ddc2_mask|STB_ST_CLKEN1_clken_ddc3_mask|STB_ST_CLKEN1_clken_ddc4_mask));

	hdmi_out(SYS_REG_SYS_SRST3_reg, SYS_REG_SYS_SRST3_write_data_mask|SYS_REG_SYS_SRST3_rstn_ddc_mask);
	hdmi_out(SYS_REG_SYS_CLKEN3_reg, SYS_REG_SYS_CLKEN3_write_data_mask|SYS_REG_SYS_CLKEN3_clken_ddc_mask);

	hdmi_out(STB_ST_SRST1_reg, (STB_ST_SRST1_write_data_mask|STB_ST_SRST1_rstn_ddc_mask));
	hdmi_out(STB_ST_CLKEN1_reg, (STB_ST_CLKEN1_write_data_mask|STB_ST_CLKEN1_clken_ddc_mask));

#if MHL_SUPPORT
	hdmi_out(STB_ST_SRST1_reg, (STB_ST_SRST1_write_data_mask|STB_ST_SRST1_rstn_cbus_mask));
	hdmi_out(STB_ST_CLKEN1_reg, (STB_ST_CLKEN1_write_data_mask|STB_ST_CLKEN1_clken_cbus_mask));
#endif
}


void lib_hdmiddc_sync_reset(unsigned char port)
{
    rtk_hddc_sync_reset(port);	
}



unsigned char lib_hdmiddc_write(unsigned char port, unsigned char* EDID, unsigned int len)
{
    int ret;    
    ret  = rtk_hddc_set_write_debounce(port, 2);
    ret |= rtk_hddc_write_edid(port, EDID, len);
    return ret == 0? TRUE:FALSE;
}


unsigned char lib_hdmiddc_read(unsigned char port, unsigned char *edid_tbl, unsigned int len)
{
    return (rtk_hddc_read_edid(port, edid_tbl, len)==0)? TRUE :FALSE;
}


void lib_hdmiddc_enable(unsigned char port, unsigned char enable)
{
    rtk_hddc_enable(port, enable);
}


void lib_hdmiddc_set_sda_delay(unsigned char port, unsigned char delay_sel)
{
    rtk_hddc_lib_set_sda_delay(port, delay_sel);
}


void lib_hdmiddc_set_write_debounce(unsigned char port, unsigned char debounce)
{
    rtk_hddc_set_write_debounce(port, debounce);
}


#if MHL_SUPPORT

unsigned char lib_hdmiddc_mhl_write(unsigned char* EDID, unsigned int len)
{
    int ret;    
    ret  = rtk_mhl_ddc_set_write_debounce(2);
    ret |= rtk_mhl_ddc_write_edid(EDID, len);
    return ret == 0? TRUE:FALSE;
}

void lib_hdmiddc_mhl_enable(unsigned char enable)
{
    rtk_mhl_ddc_enable(enable);	
}

#endif

void lib_hdmiddc_sda2gpio(unsigned char port)
{
//#ifndef ENABLE_FUNCTIONAL_TEST
//        //MT board use GPIO, disable it for safe sake
//	hdmi_mask(pinmux_reg[port], ~(0xF0000000), 0xF<<28);
//#endif
}

void lib_hdmiddc_gpio2sda(unsigned char port)
{
//#ifndef ENABLE_FUNCTIONAL_TEST
//        //MT board use GPIO, disable it for safe sake
//	hdmi_mask(pinmux_reg[port], ~(0xF0000000), 0x5<<28);
//#endif
}

void lib_hdmiddc_sda_dir_out(unsigned char port, unsigned char dir_o)
{
//#ifndef ENABLE_FUNCTIONAL_TEST
//	if (port >= HDMI_PORT_TOTAL_NUM)
//		return;
//	hdmi_mask(GPIO_DIR_REG, ~gpio_dir_bit[port], (dir_o)?gpio_dir_bit[port]:0);
//#endif
}

