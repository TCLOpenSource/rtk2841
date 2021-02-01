/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		hdmi_reg.c
 *
 * author: 	Falcon, Sam Wilson
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include "hdmi_common.h"


struct hdmi_dfe_reg_st *dfe[HDMI_RX_PORT_MAX_NUM] = {
	(struct hdmi_dfe_reg_st *) HDMI_DFE0_BASE,
	(struct hdmi_dfe_reg_st *) HDMI_DFE1_BASE,
	(struct hdmi_dfe_reg_st *) HDMI_DFE2_BASE,
#if HDMI_PHY_TOTAL_NUM==4
	(struct hdmi_dfe_reg_st *) HDMI_DFE3_BASE
#endif
};

struct hdmi_aphy_reg_st *aphy[HDMI_RX_PORT_MAX_NUM] = {
	(struct hdmi_aphy_reg_st *) HDMI_APHY0_BASE,
	(struct hdmi_aphy_reg_st *) HDMI_APHY1_BASE,
	(struct hdmi_aphy_reg_st *) HDMI_APHY2_BASE,
#if HDMI_PHY_TOTAL_NUM==4
	(struct hdmi_aphy_reg_st *) HDMI_APHY3_BASE
#endif
};

struct hdmi_mac_reg_st *mac[HDMI_RX_PORT_MAX_NUM] = {
	(struct hdmi_mac_reg_st *) HDMI_MAC0_BASE,
	(struct hdmi_mac_reg_st *) HDMI_MAC1_BASE,
	(struct hdmi_mac_reg_st *) HDMI_MAC2_BASE,
#if HDMI_PHY_TOTAL_NUM==4
	(struct hdmi_mac_reg_st *) HDMI_MAC3_BASE
#endif
};


void lib_hdmi_reg_init(void)
{
	static unsigned char init_flag = FALSE;

	if (init_flag)
		return;

	init_flag = TRUE;

//	This function can be removed in future??????? to check it.

//	dfe[0] = (struct hdmi_dfe_reg_st *) HDMI_DFE0_BASE;
//	dfe[1] = (struct hdmi_dfe_reg_st *) HDMI_DFE1_BASE;
//	dfe[2] = (struct hdmi_dfe_reg_st *) HDMI_DFE2_BASE;

//	mac[0] = (struct hdmi_mac_reg_st *) HDMI_MAC0_BASE;
//	mac[1] = (struct hdmi_mac_reg_st *) HDMI_MAC1_BASE;
//	mac[2] = (struct hdmi_mac_reg_st *) HDMI_MAC2_BASE;
}

