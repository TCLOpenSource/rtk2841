/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		MHL_detect.c
 *
 * author: 	War Machine, James "Rhodey" Rhodes
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include "hdmi_common.h"
#include "mhl_driver.h"


#if MHL_SUPPORT

unsigned char newbase_mhl_cts_mode(void)
{
	UserMHLMscCHECK_MODE();
	SET_ISMHL(TRUE);
	mhl_clk_switch(MHL_CHANNEL, 1);
	MHL_CheckPPMode();
	MHLSwitch(MHL_CHANNEL, 1);
	lib_hdmi_z0_set(MHL_CHANNEL, LN_ALL, 1);

	newbase_hdmi_set_is_mhl(MHL_CHANNEL, 1);
	newbase_hdmi_set_is_mhl_ppmode(MHL_CHANNEL, MHL_IsPPMode());

	HDMI_PRINTF("MHL CTS MODE SET !!!!!! \n");
	return TRUE;
}

unsigned char newbase_mhl_detect_mode(unsigned char port)
{
	unsigned char prev_pp;
#if MHL3_ENABLE
	unsigned char prev_link_mode;
#endif

	if (DETECT_MHL2_IN) {
#if  CBUS_NOT_BYPASS
		if (GET_SETTINGMHL() == 0) {
			lib_hdmi_z0_set(port, LN_B, 0);
			PINMUX_SEL_MHL_OUT();
			CBUSSwitch(1);
			//Cbus_Power(1);
			SET_SETTINGMHL(1);

		} else {
			MHLMscRAPHandler();
		}

		if (!MHLNormalPreDetect()) {
			return FALSE;    /* _MODE_NOSIGNAL;*/
		} else
#endif
		{
			UserMHLMscCHECK_MODE();

			mhl_clk_switch(port, 1);
			SET_ISMHL(TRUE);
			newbase_hdmi_set_is_mhl(port, 1);

			if (newbase_rxphy_get_clk(port) < VALID_MIN_CLOCK) {
				return FALSE;
			}

			prev_pp = MHL_IsPPMode();
			MHL_CheckPPMode();
			//HDMI_PRINTF("[MHL] clk=%d, pp=%d\n", newbase_rxphy_get_clk(port), MHL_IsPPMode());

#if MHL3_ENABLE
			newbase_hdmi_set_is_mhl3(port, mhl_is_ver3x());

			prev_link_mode = mhl3_get_link_rate();
			mhl3_check_link_rate();
			//HDMI_PRINTF("[MHL3] link mode=%d\n", mhl3_get_link_rate());

			if (prev_pp != MHL_IsPPMode() || prev_link_mode != mhl3_get_link_rate()) {
				newbase_rxphy_reset_setphy_proc(port);
			}
#else
			if (prev_pp != MHL_IsPPMode()) {
				newbase_rxphy_reset_setphy_proc(port);
			}
#endif

			MHLSwitch(port, 1); //sony z3 set mhl_ctrl after clock is stable

			newbase_hdmi_set_is_mhl_ppmode(port, MHL_IsPPMode());



			return TRUE;  /* MHL OK */
		}
	} else {

		newbase_hdmi_set_is_mhl(MHL_CHANNEL, 0);
		newbase_hdmi_set_is_mhl_ppmode(MHL_CHANNEL, MHL_IsPPMode());
		SET_ISMHL(0);
		SET_MHL_PROCESS_STATE(_MHL_STATE_INITIAL);
		if (GET_SETTINGMHL()) {
			lib_hdmi_z0_set(MHL_CHANNEL, LN_ALL, 1);
			mhl_clk_switch(MHL_CHANNEL, 0);
			MHLSwitch(MHL_CHANNEL,0);
			CBUSSwitch(0);

			PINMUX_SEL_HDMI_OUT();
			SET_SETTINGMHL(0);
		}
		return TRUE;
	}



}










#if MHL3_ENABLE
void lib_mhl3_set_detectmode(unsigned char nport, unsigned char mhl3)
{
	if (mhl3) {
		hdmiport_mask(HDMI_HDMI_SCR_reg, ~(HDMI_HDMI_SCR_dvi_reset_ds_cm_en_mask), 0);
		hdmiport_mask(HDMI_HDMI_SCR_reg, ~(HDMI_HDMI_SCR_mode_mask|HDMI_HDMI_SCR_msmode_mask), (HDMI_HDMI_SCR_mode_mask|HDMI_HDMI_SCR_msmode_mask));
	} else {
		hdmiport_mask(HDMI_HDMI_SCR_reg, ~(HDMI_HDMI_SCR_dvi_reset_ds_cm_en_mask), HDMI_HDMI_SCR_dvi_reset_ds_cm_en_mask);
		hdmiport_mask(HDMI_HDMI_SCR_reg, ~(HDMI_HDMI_SCR_mode_mask|HDMI_HDMI_SCR_msmode_mask), 0);
	}

}
#endif










#endif

