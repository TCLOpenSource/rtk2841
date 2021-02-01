/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for scaler clock related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	state
 */

/**
 * @addtogroup clock
 * @{
 */

//Kernel Header file
#include <linux/kernel.h>
#include <linux/delay.h>
//#include <unistd.h>			// 'close()'
//#include <fcntl.h>			// 'open()'
//#include <stdio.h>

//RBUS Header file
#include <rbus/vgip_reg.h>
#include <rbus/sub_vgip_reg.h>
#include <rbus/dds_pll_reg.h>
#include <rbus/adc_reg.h>
#include <rbus/adc_smartfit_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/ppoverlay_reg.h>
//#include <rbus/rbusScaledownReg.h>

//TVScaler Header file
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scalerdrv/scalerclock.h>
#include <tvscalercontrol/scalerdrv/framesync.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/adcsource/ypbpr.h>
#include <tvscalercontrol/adcsource/vga.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/scalerdrv/auto.h>
#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <mach/rtk_log.h>

#define TAG_NAME_VBE "VBE"
#define TAG_NAME_ADC "ADC"

#ifdef ADJUST_APLL_NEW_METHOD
unsigned int uOldPllClock = 1;
unsigned int uOldMKRecord = 0;
#endif //#ifdef ADJUST_APLL_NEW_METHOD
/*===================================  Types ================================*/
/*================================== Variables ==============================*/
/*================================ Definitions ==============================*/
#define _MAX_M_CODE 0x23
static unsigned short usPE_Value_rtd2622 = 120;

//[Code Sync][AlanLi][0980617][1]
unsigned char select_adc_vco_div = 0;
//[Code Sync][AlanLi][0980617][1][end]
unsigned char flag_3d = 0;
#if 1//#ifdef CONFIG_ZOOM_IN_OUT_ENABLE
// USER: chengying DATE:2010/04/02
//fixed bug: if dclk > panel , scaler may occur state of osd shifting
unsigned char dclkmax_zoom = 0;
#endif

static unsigned int fine_tune_dclk;

//USER:LewisLee DATE:2010/08/12
//for Dclk adjust Mcode slowly
//static DPLL_ADJUST_MCODE_STATE Adjust_Dpll_Mcode_State = DPLL_ADJUST_MCODE_FINISH;
//static unsigned short TargetMcode = 0, OriginalMcode = 0;

static DCLK_RANGE_TYPE Dclk_Range_Temp_Flag = DCLK_IN_RANGE;
static DCLK_RANGE_TYPE Dclk_Range_Flag = DCLK_IN_RANGE;

/*=================== Local Functions Phototype ==============*/
/*=========================== Functions ===================== */
/*============================================================================*/

//USER:LewisLee DATE:2010/08/12
//adjust Mcode after image show, adjust it slowly
//to fix panel tolerance too samll
#define ADJUST_MCODE_INCREASE	0
#define ADJUST_MCODE_DECREASE	1
#if 0
DPLL_ADJUST_MCODE_STATE drvif_clock_dpll_M_adjust(void)
{
	crt_sys_pll_disp1_RBUS pll_disp0_reg;
	static unsigned short Step = 0;
	static unsigned char AdjustDirect = 0;

	//if(FALSE == Scaler_Get_SetDPLL_M_Later())
		return DPLL_ADJUST_MCODE_FINISH;
	switch(Adjust_Dpll_Mcode_State)
	{
		case DPLL_ADJUST_MCODE_INITIAL:
			if(OriginalMcode > TargetMcode)
			{
				Step = OriginalMcode - TargetMcode;
				AdjustDirect = ADJUST_MCODE_DECREASE;
				Adjust_Dpll_Mcode_State = DPLL_ADJUST_MCODE_ADJUST;
			}
			else if(TargetMcode > OriginalMcode)
			{
				Step = TargetMcode - OriginalMcode;
				AdjustDirect = ADJUST_MCODE_INCREASE;
				Adjust_Dpll_Mcode_State = DPLL_ADJUST_MCODE_ADJUST;
			}
			else
				Adjust_Dpll_Mcode_State = DPLL_ADJUST_MCODE_FINISH;
		break;

		case DPLL_ADJUST_MCODE_ADJUST:
			if(ADJUST_MCODE_DECREASE == AdjustDirect)
			{
				pll_disp0_reg.regValue = IoReg_Read32(CRT_SYS_PLL_DISP1_VADDR);
				pll_disp0_reg.dpll_m -= 1;
				IoReg_Write32(CRT_SYS_PLL_DISP1_VADDR, pll_disp0_reg.regValue);

				Step--;

				if(0 == Step)
					Adjust_Dpll_Mcode_State = DPLL_ADJUST_MCODE_FINISH;
			}
			else if(ADJUST_MCODE_INCREASE == AdjustDirect)
			{
				pll_disp0_reg.regValue = IoReg_Read32(CRT_SYS_PLL_DISP1_VADDR);
				pll_disp0_reg.dpll_m += 1;
				IoReg_Write32(CRT_SYS_PLL_DISP1_VADDR, pll_disp0_reg.regValue);

				Step--;

				if(0 == Step)
					Adjust_Dpll_Mcode_State = DPLL_ADJUST_MCODE_FINISH;
			}
			else
			{
				Adjust_Dpll_Mcode_State = DPLL_ADJUST_MCODE_FINISH;
			}
		break;

		case DPLL_ADJUST_MCODE_NONE:
		case DPLL_ADJUST_MCODE_FINISH:

		break;
	}

	return Adjust_Dpll_Mcode_State;

}
#endif

/**
 * drvif_clock_set_pll
 * Set PLL register.
 *
 * @param <M_Code> { M code}
 * @param <N_Code> { N code}
 * @param <CPC> { charge pump current}
 * @return { none }
 *
 */

 #define DCLK_OFFSET_MIDDLE_VALUE	0x800

void drvif_clock_set_pll(unsigned int M_Code, unsigned int N_Code, unsigned int div, unsigned int CPC)
{
//	unsigned int offset;
	pll27x_reg_sys_pll_disp1_RBUS pll_disp1_reg;
	pll27x_reg_sys_pll_disp3_RBUS pll_disp3_reg;
//	sys_dclkss_RBUS dclkss_reg;
#if 0 //fix me later by ben wang
	dpll_in_fsync_tracking_debug_RBUS dpll_in_fsync_tracking_debug_reg;
#endif
	//unsigned short change_step = 0; //for Mcode adjust

	//Modify by tyan
	if(div == 1)
		div = 0;
	else	if(div == 2)
		div = 1;
	else if(div == 4)
		div = 2;
	else if(div == 8)
		div = 3;
#if 0 //fix me later by ben wang
    //frank@1106 add below to protect m code change protect
    dpll_in_fsync_tracking_debug_reg.regValue = IoReg_Read32(CRT_DPLL_IN_FSYNC_TRACKING_DEBUG_VADDR);
    dpll_in_fsync_tracking_debug_reg.dpll_mcode_protection = 1;
    IoReg_Write32(CRT_DPLL_IN_FSYNC_TRACKING_DEBUG_VADDR, dpll_in_fsync_tracking_debug_reg.regValue);
#endif
	//can't add RTD_Log in this function it may blinking

	/*WaitFor_DEN_STOP();*/
#if 0
	if(TRUE == Scaler_Get_SetDPLL_M_Slowly_flag())
	{
//		dclkss_reg.regValue = IoReg_Read32(SYSTEM_SYS_DCLKSS_VADDR);
//		offset = dclkss_reg.dclk_offset_11_0;
//		dclkss_reg.dclk_offset_11_0 = DCLK_OFFSET_MIDDLE_VALUE;
//		dclkss_reg.dclk_ss_en = 0;
//		dclkss_reg.dclk_ss_load = 1;
//		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

//		IoReg_ClearBits(SYSTEM_PLL_DISP2_VADDR, _BIT17); //dpll phase swallow check after
		msleep(1);

		pll_disp1_reg.regValue =  IoReg_Read32(CRT_SYS_PLL_DISP1_reg);
		pll_disp3_reg.regValue =  IoReg_Read32(CRT_SYS_PLL_DISP3_reg);
		OriginalMcode = pll_disp1_reg.dpll_m;
		TargetMcode = M_Code - 3;

		pll_disp1_reg.regValue = 0;
		pll_disp1_reg.dpll_m = OriginalMcode;
		pll_disp2_reg.dpll_o = div;
		pll_disp1_reg.dpll_n = N_Code - 2;
		pll_disp1_reg.dpll_ip = CPC;

		if (flag_3d)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"set 3d 1....\n");

			// Set Display free run to avoid output 120Hz to Panel directly.
			// Fix mantis:5125
			ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
			display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
			display_timing_ctrl1_reg.disp_frc_on_fsync = _FALSE;
			display_timing_ctrl1_reg.disp_fix_last_line = _DISABLE;
			display_timing_ctrl1_reg.disp_fsync_en = _DISABLE;
			IoReg_Write32(PPOVERLAY_Display_Timing_CTRL1_reg, display_timing_ctrl1_reg.regValue);

			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);
		}

		WaitFor_DEN_STOP();
		IoReg_Write32(CRT_SYS_PLL_DISP1_reg, pll_disp1_reg.regValue);
		IoReg_Write32(CRT_SYS_PLL_DISP3_reg, pll_disp3_reg.regValue);
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Target M/N/O code : %x/%x/%x\n", TargetMcode, pll_disp1_reg.dpll_n, pll_disp2_reg.dpll_o);
		msleep(1);

		// set dclk/dmaclk select here to prevent dclk will be set too high
		if (GET_PANEL_DCLK_DIV() == 1)
		{
			if(Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE() && ((_DISP_WID <= 1920) && (_DISP_LEN <= 1080))){
				unsigned char bDoubleDvsTiming=FALSE;
				// double DVS condition
				// 1) non-VO/OSD source, 2) 2D full screen display mode, 3) frame rate > 30Hz & data FRC
				if((Scaler_InputSrcGetMainChType() != _SRC_VO) && (Scaler_InputSrcGetMainChType() != _SRC_OSD)
					&& (drvif_scaelr3d_decide_is_3D_display_mode() == FALSE) && (Scaler_DispGetRatioMode() != SLR_RATIO_CUSTOM)
					&& (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 310)
					&& (Scaler_DispGetInputInfo(SLR_INPUT_STATE) >= _MODE_STATE_ACTIVE))
				{
					bDoubleDvsTiming = TRUE;
				}

  #if !defined(OPEN_CELL_PANEL) // Due to bandwidth constrain open cell platform 2D mode run at 60Hz
				if((bDoubleDvsTiming == FALSE) /*&& !drvif_scaler4k2k_get_forceDisplayOutput_60Hz()*/)
				{
					// d-clock pull high to 300MHZ excepting enter double DVS timing
					drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL, DISP_DCLK_IS_DPLL );
				}else
  #endif
				{
  #if defined (ENABLE_QUADFHD)
	  				// [4k2k][#25055] Prevent Millet3 LVDS RX noise issue when frame rate less than 100Hz
	  				unsigned char uc3dmode = Scaler_Get3DMode();
  					if((Scaler_InputSrcGetMainChType() != _SRC_VO) && ((uc3dmode == SLR_3DMODE_2D) || ((uc3dmode >= SLR_3DMODE_3D_AUTO_CVT_2D) && (uc3dmode <= SLR_3DMODE_3D_SENSIO_CVT_2D))))
  						Scaler_ForcePanelBg(_ENABLE);
  #endif
					drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);
				}
			} else
			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);
		}

		WaitFor_DEN_STOP();
		if(TRUE == Scaler_Get_SetDPLL_M_Later())
		{
			Adjust_Dpll_Mcode_State = DPLL_ADJUST_MCODE_INITIAL;
		}
		else// if(FALSE == Scaler_Get_SetDPLL_M_Later())
		{
			Adjust_Dpll_Mcode_State = DPLL_ADJUST_MCODE_FINISH;

			if(TargetMcode > OriginalMcode)
			{
				change_step = TargetMcode - OriginalMcode;
				while(change_step --)
				{
					pll_disp1_reg.regValue = IoReg_Read32(CRT_SYS_PLL_DISP1_reg);
					pll_disp1_reg.dpll_m += 1;
					IoReg_Write32(CRT_SYS_PLL_DISP1_reg, pll_disp1_reg.regValue);
				}
			}
			else if(OriginalMcode > TargetMcode)
			{
				change_step = OriginalMcode - TargetMcode;
				while(change_step --)
				{
					pll_disp1_reg.regValue = IoReg_Read32(CRT_SYS_PLL_DISP1_reg);
					pll_disp1_reg.dpll_m -= 1;
					IoReg_Write32(CRT_SYS_PLL_DISP1_reg, pll_disp1_reg.regValue);
				}
			}
		}

		// set dclk/dmaclk select here to prevent dclk will be set too high
		if (GET_PANEL_DCLK_DIV() == 2)
		{
			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL, DISP_DCLK_IS_DPLL_DIV_2);
		}
	}
	else// if(FALSE == Scaler_Get_SetDPLL_M_Slowly_flag())
#endif
	{
//		dclkss_reg.regValue = IoReg_Read32(SYSTEM_SYS_DCLKSS_VADDR);
//		offset = dclkss_reg.dclk_offset_11_0;
//		dclkss_reg.dclk_offset_11_0 = DCLK_OFFSET_MIDDLE_VALUE;
//		dclkss_reg.dclk_ss_en = 0;
//		dclkss_reg.dclk_ss_load = 1;
//		WaitFor_DEN_STOP();
//		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

//		IoReg_ClearBits(SYSTEM_PLL_DISP2_VADDR, _BIT17); //<-- need or not ???
		msleep(1);

		//frank mark ,tyan add but not test yetPLL_SYSTEM_PLL_DISP0_VADDR
		pll_disp3_reg.regValue =  IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
		pll_disp1_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
		pll_disp1_reg.dpll_m = M_Code - 3;
		pll_disp3_reg.dpll_o = div;
		pll_disp1_reg.dpll_n= N_Code - 2;
		//pll_disp1_reg.dpll_ip= CPC;
#if 0	//mag2 un-used dclk sel, move to dpll_o
		if (flag_3d)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"set 3d....\n");

			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);

		}

		// set dclk/dmaclk select here to prevent dclk will be set too high
		if (GET_PANEL_DCLK_DIV() == 1)
		{
			if(Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE()){
  #if !defined(OPEN_CELL_PANEL) // Due to bandwidth constrain open cell platform 2D mode run at 60Hz
				if((Scaler_InputSrcGetMainChType() == _SRC_VO) && (Scaler_Get3DMode()== SLR_3DMODE_2D) && Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)
					&& (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) == (VO_FR_CTRL_FORCE_FRAMERATE_MAX/100)))
				{
					drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL, DISP_DCLK_IS_DPLL );
				}
				else if(Scaler_InputSrcGetIdxType(Scaler_GetUserInputSrc(SLR_MAIN_DISPLAY)) == _SRC_OSD/*(Scaler_InputSrcGetType(SLR_MAIN_DISPLAY)==_SRC_OSD)*/){
					//printk(KERN_INFO "[SG][OSD] set dclk = 300M!\n");
					drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL, DISP_DCLK_IS_DPLL );
				}else if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1){
					drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL, DISP_DCLK_IS_DPLL );
				}
				else
  #endif
					drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);
			}
			else{
				if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1)
					drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL, DISP_DCLK_IS_DPLL );
				else
			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL_DIV_2, DISP_DCLK_IS_DPLL_DIV_2);
		}
		}
#endif
		//WaitFor_DEN_STOP_Done();//Remove by Will. Ben Chenck no need
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP1_reg, pll_disp1_reg.regValue);
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, pll_disp3_reg.regValue);

		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Target M/N/O code(2) : %x/%x/%x\n", pll_disp1_reg.dpll_m, pll_disp1_reg.dpll_n, pll_disp3_reg.dpll_o);
		msleep(1);
#if 0	//mag2 un-used dclk sel, move to dpll_o
		// set dclk/dmaclk select here to prevent dclk will be set too high
		if (GET_PANEL_DCLK_DIV() == 2)
		{
			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL, DISP_DCLK_IS_DPLL_DIV_2);
		}
#endif
	}
#if 0	//mag2 un-used dclk sel, move to dpll_o
	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1){
		if(GET_PANEL_DCLK_DIV() == 1)
			drvif_scalerdisplay_set_dclk_sel(DISP_DMACLK_IS_DPLL, DISP_DCLK_IS_DPLL );
	}
#endif
//	dclkss_reg.dclk_offset_11_0 = offset;
//	dclkss_reg.dclk_ss_en = 1;
//	dclkss_reg.dclk_ss_load = 1;
//	WaitFor_DEN_STOP();
//	IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, dclkss_reg.regValue);

	pll_disp3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
	pll_disp3_reg.dpll_rstb = 1;
	//pll_disp3_reg.dpll_fupdn = 1; //k3l error will mark 0603
	//pll_disp3_reg.dpll_stop= 1;//k3l error will mark 0603

	#if 0 //darwin not exist
	if(N_Code>5)
		pll_disp2_reg.dplllpfmode = 1;
	else
		pll_disp2_reg.dplllpfmode = 0;
	#endif

	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, pll_disp3_reg.regValue);


#ifdef CONFIG_DPLL_RESET_NEW
	pll_disp2_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP2_reg);

	//Lewis, to prevent DPLL in reset mode
	if(0 == pll_disp2_reg.dpll_rstb) //reset
	{
		// Reset PLL_DISP
		// 0: reset
		// 1: normal

		pll_disp2_reg.dpll_rstb = 0; //reset
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP2_reg, pll_disp1_reg.regValue);

		Rt_Delay(1);//frank@0430 Change busy delay to save time

		pll_disp2_reg.regValue = IoReg_Read32(SYSTEM_PLL_DISP2_VADDR);
		pll_disp2_reg.dpll_rstb = 1; //normal
		//WaitFor_DEN_STOP_Done();//Remove by Will. Ben Chenck no need
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP2_reg, pll_disp2_reg.regValue);
	}
#endif //#ifdef CONFIG_DPLL_RESET_NEW

	//CSW+ 0961214 new code for frame sync by tyan/cal. dclk for path1
#if 0 //frank@0119 mrak for sirius bring up
	if ( Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) )
	{
		pll_disp2_reg.regValue = IoReg_Read32(SYSTEM_PLL_DISP2_VADDR);
		pll_disp2_reg.dpll_clksel = 0;
		pll_disp2_reg.dpll_bpn = 0;
		pll_disp2_reg.dpll_pwdn = 1;  //disp or all pll

		pll_disp2_reg.dpll_reserve= 1;
		IoReg_Write32(SYSTEM_PLL_DISP2_VADDR, pll_disp2_reg.regValue);
	}
	else
#endif
	{
		sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;
		sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
		sys_dispclksel_reg.dispd_memc_out_sel = 0;
		IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, sys_dispclksel_reg.regValue);

		pll_disp3_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP3_reg);
		//pll_disp3_reg.dpll_bpn = 0; //k3l error will mark 0603
		pll_disp3_reg.dpll_pow= 1;
		pll_disp3_reg.dpll_vcorstb = 1;
		IoReg_Write32(PLL27X_REG_SYS_PLL_DISP3_reg, pll_disp3_reg.regValue);
	}

}

 //modify by tyan
unsigned char drvif_clock_cal_cpc(unsigned int M_Code,unsigned int N_Code) // CPC : charge pump current
{
	unsigned int ucTemp1;
	unsigned int  ucTemp2 = 0;
	//sys_pll_disp2_RBUS pll_disp1_reg;

	//Modify by tyan start 20070701  but not test yet
	if( N_Code <= 5){
		//LPF_Mode = 0, suppose  iM / Ich = 1.673
		ucTemp1 = ((unsigned int) M_Code  *10000/ 1673);
	/*	pll_disp1_reg.regValue = IoReg_Read32(SYSTEM_PLL_DISP2_VADDR);
		pll_disp1_reg.dplllpfmode = 0;
		IoReg_Write32(SYSTEM_PLL_DISP2_VADDR, pll_disp1_reg.regValue);*/
	}
	else{
		//16>=N_Code>5
		//LPF_Mode = 1, suppose iM / Ich =17.6
		ucTemp1 = ( (unsigned int)M_Code *10000 / 17600);
		/*pll_disp1_reg.regValue = IoReg_Read32(SYSTEM_PLL_DISP2_VADDR);
		pll_disp1_reg.dplllpfmode = 1;
		IoReg_Write32(SYSTEM_PLL_DISP2_VADDR, pll_disp1_reg.regValue);*/
	}

	//ROSPrintf("\n Ich *10= %x",ucTemp1);

	//DPLL_CRNT[4:0] = DPLLSI[4:0]
	//I=(2.5uA+2.5uA*bit[0]+5uA*bit[1]+10uA*bit[2]+20uA*bit[3]+30uA*bit[4]) ,
	//Ip=I*[(bit[5]+1) / 2]Keep Icp/DPM constant

	ucTemp1=ucTemp1-25;

	if (ucTemp1 > 300) {
		ucTemp1 -= 300;
		ucTemp2 += 16;
	}

	if (ucTemp1 > 200) {
		ucTemp1 -= 200;
		ucTemp2 += 8;
	}

	if (ucTemp1 > 100) {
		ucTemp1 -= 100;
		ucTemp2 |= 4;
	}

	if (ucTemp1 > 50) {
		ucTemp1 -= 50;
		ucTemp2 += 2;
	}

	if (ucTemp1 > 25) {
		ucTemp1 -= 25;
		ucTemp2 += 1;
	}

	ucTemp2 += 32;

	return ucTemp2;
}




void drvif_clock_pfd_calibration()
{
	unsigned char count = 255;
	unsigned short usTemp;
	dds_pll_pfd_calibrated_results_RBUS dds_pll_pfd_calibrated_results_reg;
	static unsigned char YPbPr_Need_pfd_Calibration = 1;

	if(YPbPr_Need_pfd_Calibration)
	{
		IoReg_Write32(DDS_PLL_PFD_CALIBRATED_RESULTS_reg, 0); //clear
		dds_pll_pfd_calibrated_results_reg.regValue = IoReg_Read32(DDS_PLL_PFD_CALIBRATED_RESULTS_reg);
		dds_pll_pfd_calibrated_results_reg.pfd_cal_en = 1; //PFD Calibration Enable
		IoReg_Write32(DDS_PLL_PFD_CALIBRATED_RESULTS_reg, dds_pll_pfd_calibrated_results_reg.regValue);

		do {
			count--;
			dds_pll_pfd_calibrated_results_reg.regValue = IoReg_Read32(DDS_PLL_PFD_CALIBRATED_RESULTS_reg);
			if((dds_pll_pfd_calibrated_results_reg.pfd_cal_en == 0) || (count == 0))
				break;

			mdelay(4);
		}while(count);

		if(count == 0)
		{
			usPE_Value_rtd2622 = 70;//timeout, set a default value,uint : ps
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"####drvif_clock_pfd_calibration Fail#####\r\n");
		}
		else
		{
		#if 0 // setting delay chain to fixed value
			dds_pll_pfd_calibrated_results_reg.regValue = IoReg_Read32(DDS_PLL_PFD_CALIBRATED_RESULTS_reg);
			usTemp = dds_pll_pfd_calibrated_results_reg.q_pe_4cal;
		#else
			/********************************************
			 ** formular

				T = 1/27MHz,

				t_max = 0.0000000000885 s,
				v_max = T/t_max = 418, hex(418) = 0x1a2

				|mac5p      |MAX     |TYP      |MIN     |
				|-----------|--------|---------|--------|
				|delay chain|0.0885ns|0.0685ns|0.0485ns |
				|0130[14:0] |0x1a2   |0x21c    |0x2fb   |
			 ********************************************
			 */

			usTemp = 0x21c;
		#endif
			usPE_Value_rtd2622 = 1000000000/(CONFIG_CPU_XTAL_FREQ/1000) / usTemp; //uint :ps
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"####drvif_clock_pfd_calibration Success Count:%d#####\r\n", count);
		}
		YPbPr_Need_pfd_Calibration = 0;
	}
}

//USER:LewisLee DATE:2011/06/02
//let fix last line know current timing Dclk state
DCLK_RANGE_TYPE drvif_get_dclk_margin_check_result(void)
{
	return Dclk_Range_Flag;
}

//#ifdef CONFIG_DCLK_CHECK
#if 0 //mag2 un-used dclk sel, move to dpll_o
unsigned int drvif_get_dclk_margin(unsigned int ulFreq)
{

	unsigned int Dclk_sscg_range = 0;
	unsigned int max = 750; // 7.5%   // 0.075
	unsigned int resultfreq = ulFreq;

//	if (_TRUE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC))
//		return resultfreq;

	Dclk_sscg_range = ulFreq  /10000 / 2 * max;

	printk(KERN_INFO "dclk debug %d %d %d %d\n", ulFreq, Dclk_sscg_range, max,GET_PANEL_DCLK_DIV());
/*
	if(_ENABLE == modestate_decide_double_dvs_enable())
	{
		unsigned int ulDispClkMax = Get_DISPLAY_CLOCK_MAX();

		// LVDS 2ch output mode: Max d-clock /2
		if(Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE() && drvif_scaler4k2k_get_forceDisplayOutput_60Hz())
			ulDispClkMax = Get_DISPLAY_CLOCK_MAX()>>1;

		//USER:LewisLee DATE:2011/02/16
		//in Double DVS mode, the really output Dclk will double
		if ((ulFreq + Dclk_sscg_range) > ((ulDispClkMax / GET_PANEL_DCLK_DIV()) >>1)*1000000)  //  final dclk + final dclk * 0.0375 < max
		{
			printk(KERN_INFO "double DVS, over dclk, get fine tune dclk\n");
			resultfreq = ((ulDispClkMax / GET_PANEL_DCLK_DIV()) >>1)*1000000 / (10000 + (max >> 1)) * 10000;
			dclkmax_zoom = 1;
			// [FIX-ME] fps <= 30 double DVS timing should not enter this condition
			if(Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE() && (scalerdisplay_get_2D_MEMC_support() == TRUE) && (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) < 310))
				printk(KERN_INFO "[MEMC] Force In Range!!\n");
			else
			Dclk_Range_Temp_Flag = DCLK_OVER_RANGE;
		}
		else if ((ulFreq - Dclk_sscg_range) < ( (Get_DISPLAY_CLOCK_MIN() / GET_PANEL_DCLK_DIV())>>1)*1000000)    //  final dclk - final dclk * 0.0375 < min
		{
			printk(KERN_INFO "double DVS, under dlck , get fine tune dclk ....\n");
			resultfreq = ((Get_DISPLAY_CLOCK_MIN() / GET_PANEL_DCLK_DIV())>>1) * 1000000 / (10000 - (max >> 1)) * 10000;
			dclkmax_zoom = 0;
			Dclk_Range_Temp_Flag = DCLK_UNDER_RANGE;
		}
		else
		{
			dclkmax_zoom = 0;
			Dclk_Range_Temp_Flag = DCLK_IN_RANGE;
		}
	}
	else// if(_DISABLE == modestate_decide_double_dvs_enable())
*/

	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1)
		max = 700; // 7.0%   // 0.070

	{
		if ((ulFreq + Dclk_sscg_range) > Get_DISPLAY_CLOCK_MAX() / GET_PANEL_DCLK_DIV() *1000000)  //  final dclk + final dclk * 0.0375 < max
		{
			printk(KERN_INFO "over dclk, get fine tune dclk\n");
			resultfreq = Get_DISPLAY_CLOCK_MAX()/ GET_PANEL_DCLK_DIV() *1000000 / (10000 + (max >> 1)) * 10000;
			dclkmax_zoom = 1;
			Dclk_Range_Temp_Flag = DCLK_OVER_RANGE;
		}
		else if ((ulFreq - Dclk_sscg_range) < Get_DISPLAY_CLOCK_MIN() / GET_PANEL_DCLK_DIV() *1000000)    //  final dclk - final dclk * 0.0375 < min
		{
			printk(KERN_INFO "under dlck , get fine tune dclk ....\n");
			resultfreq = Get_DISPLAY_CLOCK_MIN()/ GET_PANEL_DCLK_DIV() * 1000000 / (10000 - (max >> 1)) * 10000;
			dclkmax_zoom = 0;
			Dclk_Range_Temp_Flag = DCLK_UNDER_RANGE;
		}
		else
		{
			dclkmax_zoom = 0;
			Dclk_Range_Temp_Flag = DCLK_IN_RANGE;
		}
		printk(KERN_INFO "dclk max.min (%d.%d) \n", Get_DISPLAY_CLOCK_MAX() / GET_PANEL_DCLK_DIV() *1000000, Get_DISPLAY_CLOCK_MIN() / GET_PANEL_DCLK_DIV() *1000000);
	}

	return resultfreq;
}

#else //#ifdef CONFIG_DCLK_CHECK

unsigned int drvif_get_dclk_margin(unsigned int ulFreq)
{

	unsigned int Dclk_sscg_range = 0;
	unsigned int max = 750; // 7.5%   // 0.075
	unsigned int resultfreq = ulFreq;

	if (_TRUE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC))
		return resultfreq;

	Dclk_sscg_range = ulFreq  /10000 / 2 * max;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"dclk debug %d %d %d", ulFreq, Dclk_sscg_range, max);

	if(_ENABLE == modestate_decide_double_dvs_enable())
	{
		//USER:LewisLee DATE:2011/02/16
		//in Double DVS mode, the really output Dclk will double
		if ((ulFreq + Dclk_sscg_range) > (Get_DISPLAY_CLOCK_MAX()>>1)*1000000)  //  final dclk + final dclk * 0.0375 < max
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"double DVS, over dclk, get fine tune dclk\n");
			resultfreq = (Get_DISPLAY_CLOCK_MAX()>>1)*1000000 / (10000 + (max >> 1)) * 10000;
			dclkmax_zoom = 1;
			Dclk_Range_Temp_Flag = DCLK_OVER_RANGE;
		}
		else if ((ulFreq - Dclk_sscg_range) < (Get_DISPLAY_CLOCK_MIN()>>1)*1000000)    //  final dclk - final dclk * 0.0375 < min
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"double DVS, under dlck , get fine tune dclk ....\n");
			resultfreq = (Get_DISPLAY_CLOCK_MIN()>>1) * 1000000 / (10000 - (max >> 1)) * 10000;
			dclkmax_zoom = 0;
			Dclk_Range_Temp_Flag = DCLK_UNDER_RANGE;
		}
		else
		{
			dclkmax_zoom = 0;
			Dclk_Range_Temp_Flag = DCLK_IN_RANGE;
		}
	}
	else// if(_DISABLE == modestate_decide_double_dvs_enable())
	{
		if ((ulFreq + Dclk_sscg_range) > Get_DISPLAY_CLOCK_MAX()*1000000)  //  final dclk + final dclk * 0.0375 < max
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"over dclk, get fine tune dclk\n");
			resultfreq = Get_DISPLAY_CLOCK_MAX()*1000000 / (10000 + (max >> 1)) * 10000;
			dclkmax_zoom = 1;
			Dclk_Range_Temp_Flag = DCLK_OVER_RANGE;
		}
		else if ((ulFreq - Dclk_sscg_range) < Get_DISPLAY_CLOCK_MIN()*1000000)    //  final dclk - final dclk * 0.0375 < min
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"under dlck , get fine tune dclk ....\n");
			resultfreq = Get_DISPLAY_CLOCK_MIN() * 1000000 / (10000 - (max >> 1)) * 10000;
			dclkmax_zoom = 0;
			Dclk_Range_Temp_Flag = DCLK_UNDER_RANGE;
		}
		else
		{
			dclkmax_zoom = 0;
			Dclk_Range_Temp_Flag = DCLK_IN_RANGE;
	        }
	}
	return resultfreq;
}
#endif //#ifdef CONFIG_DCLK_CHECK

UINT32 drvif_2Dcvt3D_FixDclk_IVTotal_Cal(void)
{
	UINT32 DVTotal;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"sub v freq=%d %d\n",Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_V_FREQ),Get_DISP_VERTICAL_TOTAL());

	if (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_V_FREQ) > 650)
		return Get_DISP_VERTICAL_TOTAL() - 1;


	if ((Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_V_FREQ) > 580) && (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_V_FREQ) < 620))
	{
		DVTotal =  fine_tune_dclk / (Get_DISP_HORIZONTAL_TOTAL() *  60);
	}
	else if ((Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_V_FREQ) > 480) && (Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_V_FREQ) < 520))
		{
			DVTotal =  fine_tune_dclk / (Get_DISP_HORIZONTAL_TOTAL() *  50);
	}
	else
	{
		DVTotal =  fine_tune_dclk / (Get_DISP_HORIZONTAL_TOTAL() *  Scaler_DispGetInputInfoByDisp(SLR_SUB_DISPLAY,SLR_INPUT_V_FREQ) / 10);

	}

	return DVTotal - 1;
}

unsigned int Get_fine_tune_dclk_forGameMode(void)
{
	return fine_tune_dclk;
}

void drvif_3ddma_DVTotal_Set(UINT8 div)  //id div == 1 , we don't reset DVTotal
{
      return;

}

#ifdef RUN_ON_TVBOX
///////////////////////// For TVBOX ///////////////////////////////////////

DCLK_PARAM_TABLE tDclk_param_table[] =
{
		{0x1f, 0x1, 0, 1},		//148.5Hz
		{0x1f, 0x1, 0, 2},		//74.25Hz
		{0x5, 0x1, 0, 1},		// 27Hz
		{0x1f, 0x1, 0, 0},		//297MHz
};


unsigned char drvif_set_dclk_sync_tvbox(UINT8 mode)
{
	UINT8 dclk_table_num = 0;
	pll_disp1_RBUS pll_disp1_reg;
	ppoverlay_dclk_sel_RBUS dclk_sel_reg;

	switch(mode)
	{

		case _MODE_1080I25:
		case _MODE_1080I30:
		case _MODE_1080P50:
		case _MODE_1080P60:
			dclk_table_num = 0;
			break;

		case _MODE_720P50:
		case _MODE_720P60:
			dclk_table_num = 1;
			break;

		case _MODE_480I:
		case _MODE_576I:
		case _MODE_480P:
		case _MODE_576P:
			dclk_table_num = 2;
			break;

		case _MODE_4k2kI30:
		case _MODE_4k2kP30:
			dclk_table_num = 3;
			break;
		default:
			dclk_table_num = 0;
			break;
	}


	pll_disp1_reg.regValue =  IoReg_Read32(SYSTEM_PLL_DISP1_VADDR);
	pll_disp1_reg.dpll_m = tDclk_param_table[dclk_table_num].M_CODE;
	pll_disp1_reg.dpll_n = tDclk_param_table[dclk_table_num].N_CODE;
	IoReg_Write32(SYSTEM_PLL_DISP1_VADDR, pll_disp1_reg.regValue);

	drvif_clock_offset(tDclk_param_table[dclk_table_num].DCLK_OFFSET);

	dclk_sel_reg.regValue = IoReg_Read32(PPOVERLAY_DCLK_SEL_VADDR);
	dclk_sel_reg.dclk_sel = tDclk_param_table[dclk_table_num].DCLK_SEL;
	IoReg_Write32(PPOVERLAY_DCLK_SEL_VADDR, dclk_sel_reg.regValue);


	drvif_clock_offset(tDclk_param_table[dclk_table_num].DCLK_OFFSET);

}
///////////////////////// END For TVBOX ///////////////////////////////////////
#endif


/*============================================================================*/
/**
 * drvif_clock_set_dclk
 * This function is used to set display clock.
 *
 * @param	<niHFreq>		{ IHFreq }
 * @param	<niVActLen>		{ input length (IVActLen for normal case; IVTotal for FRC ATV and JPEG RPTG) }
 * @param	<default_freq>	{ default frequency (Its priority is highest. Set 0 to calculate dclk.) }
 * @return					{ 0) FRC, 1) framesync }
 */
unsigned char drvif_clock_set_dclk(unsigned short niHFreq, unsigned short niVActLen, unsigned int default_freq)
{
//	unsigned char  cpc,cnt=0,div=1, ret=0;
	unsigned char  cpc, div=1, ret=0;
	unsigned int nMCode,nNCode, f_code;
//	unsigned int nDPLL,temp=0;
//	unsigned int nStep;
	unsigned int ulFreq;
    UINT32 dclk_Temp, en_ssc_Temp;
	pll27x_reg_pll_ssc0_RBUS pll_ssc0_reg;
	pll27x_reg_pll_ssc4_RBUS pll_ssc4_reg;
	pll27x_reg_pll_ssc5_RBUS pll_ssc5_reg;

//	sys_pll_disp1_RBUS pll_disp0_reg;
	//sys_pll_disp2_RBUS pll_disp2_reg;
	unsigned char IFrameRate=0;
	unsigned char cnt=0;
//	UINT32 DH_total_Temp; // for Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag()

	if((Get_DISPLAY_PANEL_TYPE() == P_VBY1_4K2K) ||
		(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI) ||
		(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI) ||
		(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K))
		return 1;

#ifdef CONFIG_ALL_SOURCE_DATA_FS
	return 1;
#endif

#if 0
	if(Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX){
		printk(KERN_INFO "Disp to TVBOX use fix dclk now. \n");
#ifdef RUN_ON_TVBOX
		drvif_set_dclk_sync_tvbox(scalerdisplay_get_display_tve_mode());
#endif

#if 0
		IoReg_Write32(SYSTEM_PLL_DISP1_VADDR, 0x01f01700);
		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, 0x00000001);
		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, 0x00000005);
#endif
		return 1;
	}
#endif

#ifdef CONFIG_VBY_ONE_M4_DEMO
	IoReg_Write32(PLL27X_REG_SYS_PLL_DISP1_VADDR, 0x01f01700);
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, 0x00000001);
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, 0x00000005);
	IoReg_Write32(PPOVERLAY_DCLK_SEL_VADDR, 0);
	return 1;
#endif

	if(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI){
#if 0 //fix me later by ben wang
		IoReg_Write32(CRT_SYS_PLL_DISP1_reg, 0x01f01600);
		IoReg_Write32(CRT_SYS_DCLKSS_reg, 0x00000001);
		IoReg_Write32(CRT_SYS_DCLKSS_reg, 0x00000005);
#endif
		return 0;
	}

	if ( default_freq != 0 ) {
		if (Scaler_DispGetInputInfo(SLR_INPUT_V_LEN) == 0)
			IFrameRate = 60;
		else
		{
			IFrameRate = niHFreq * 100 / Scaler_DispGetInputInfo(SLR_INPUT_V_LEN);
		}

		if ( IFrameRate > 62)  //frame rate over 60 + miss error
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"Warning !! frame rate = %d  over 62",IFrameRate);
			//frank@0621 add below code to solve mantis#41559 VGA over 65HZ have error Vsync
			Scaler_Set_FRC_Open_Fix_Lastline_2(FALSE);
			drvif_framesync_reset_dv_total();
			ret = 1;
		}else{
			Scaler_Set_FRC_Open_Fix_Lastline_2(TRUE);
		}
		ulFreq = default_freq;
	} else {
		// CSW+ 0970710 For 50 MHz in main and 60 MHz in sub , unplugging main signal and cause sub shaking
		if (/* Scaler_PipGetInfo(SLR_PIP_ENABLE) && */(!Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC))){ //((GET_INPUT_MODE(SLR_MAIN_DISPLAY) == _MODE_576I)) {
			niHFreq = 157;  // Set DClk to 60 MHz timing
			niVActLen = 231;
		}
		if ( niVActLen == 0 ) {
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"ERROR!! [drvif_clock_set_dclk] get niVActLen = 0, set to default 60 MHz\n");
			niHFreq = 157;  // Set DClk to 60 MHz timing
			niVActLen = 231;
		}
#ifdef CONFIG_ATV_FRC // hsliao 20090519
		if ( Scaler_InputSrcGetMainChType() == _SRC_TV )
			//		output frame rate = input frame rate
			// ==>	Dclk / ( DHTotal*DVTotal) = Iclk / (IHTotal*IVTotal)
			// ==>	Dclk = ( Iclk / (IHTotal*IVTotal) ) * ( DHTotal*DVTotal)
			// ==>	Dclk = ( IHFreq / IVTotal ) * (DHTotal*DVTotal)
			// ==>	Dclk = ( DHTotal * IHFreq / IVTotal ) * DVTotal
			ulFreq = ((Get_DISP_HORIZONTAL_TOTAL()*niHFreq*100*2) / niVActLen) * Get_DISP_VERTICAL_TOTAL();
		else
#endif
		if(Scaler_InputSrcGetMainChType() == _SRC_VO){
			ulFreq = ((Get_DISP_HORIZONTAL_TOTAL()*niHFreq*100*2) / niVActLen) * Get_DISP_VERTICAL_TOTAL();
			//ulFreq = ((Get_DISP_HORIZONTAL_TOTAL()*niHFreq*100) / niVActLen) * Get_DISP_VERTICAL_TOTAL();
		}
		else
		{
			//USER:LewisLee DATE:2012/04/19
			//if we have cut line, need adjust niVActLen
//			if((TRUE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC)) && (TRUE == fwif_scaler_decide_display_cut4line(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))))
			if(TRUE == fwif_scaler_decide_display_cut4line(SLR_MAIN_DISPLAY))
			{
				ulFreq = ((Get_DISP_HORIZONTAL_TOTAL()* niHFreq*100 * 2) / (niVActLen - 2)) * _DISP_LEN;
			}
			else
			{
				ulFreq = ((Get_DISP_HORIZONTAL_TOTAL()* niHFreq*100 * 2) / niVActLen) * _DISP_LEN;
			}

		}

		ulFreq = ((ulFreq >> 1) + (ulFreq & 0x01));



		//USER:LewisLee DATE:2012/05/17
		//in Double DVS mode, we need to Double Dclk
		if(_ENABLE == modestate_decide_double_dvs_enable())
		{
			ulFreq = ulFreq<<1;
			rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"drvif_clock_set_dclk, Double DVS need Double Dclk!\n");
	        }
		Scaler_Set_FRC_Open_Fix_Lastline_2(TRUE);
	}

	//printk(KERN_INFO "\n set_dclk frame rate = %d, srcType/defClk/frcLL[%d/%d/%d] \n ", IFrameRate,
		//Scaler_InputSrcGetMainChType(), default_freq, Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag());

//	printk(KERN_INFO "\n DISP_HORIZONTAL_TOTAL = %d \n",Get_DISP_HORIZONTAL_TOTAL());
//	printk(KERN_INFO "\n niHFreq = %d \n",niHFreq);
//	printk(KERN_INFO "\n IVL = %d \n",niVActLen);
//	printk(KERN_INFO "\n DVL = %d \n",_DISP_LEN);


//#ifdef CONFIG_DCLK_CHECK
#if 0	//mag2 un-used dclk sel, move to dpll_o
	printk(KERN_INFO "\n pre finetune  DClk = %d Hz  &  Max DClk = %d Hz\n", ulFreq, Get_DISPLAY_CLOCK_MAX()/GET_PANEL_DCLK_DIV()*1000000);
#else //#ifdef CONFIG_DCLK_CHECK
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n pre finetune  DClk = %d Hz  &  Max DClk = %d Hz\n", ulFreq, Get_DISPLAY_CLOCK_MAX()*1000000);
#endif //#ifdef CONFIG_DCLK_CHECK

#if 1
#ifndef CONFIG_PANEL_TVBOX
//	  ulFreq = drvif_get_dclk_margin(ulFreq);
#endif
	//if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 1){
		// 0xb802_8294[1:0] = 0, div =0
		//ulFreq = ((ulFreq >> 1) + (ulFreq & 0x01));
	//}
#if 0
	if(_ENABLE == Scaler_Get_EnterFRC_LastLine_DHtotal_Adjust_Enable_Flag())
	{
		Dclk_Range_Flag = Dclk_Range_Temp_Flag;

		if(DCLK_IN_RANGE == Dclk_Range_Temp_Flag)
		{
			//Do Nothing
		}
		else
		{
			framesync_lastlinefinetune_at_frc_mode_modify_dhtotal_value(_FALSE);

			DH_total_Temp = framesync_lastlinefinetune_at_frc_mode_get_dhtotal_value();

#ifdef CONFIG_ATV_FRC // hsliao 20090519
			if( _SRC_TV == Scaler_InputSrcGetMainChType())
			{
				//		output frame rate = input frame rate
				// ==>	Dclk / ( DHTotal*DVTotal) = Iclk / (IHTotal*IVTotal)
				// ==>	Dclk = ( Iclk / (IHTotal*IVTotal) ) * ( DHTotal*DVTotal)
				// ==>	Dclk = ( IHFreq / IVTotal ) * (DHTotal*DVTotal)
				// ==>	Dclk = ( DHTotal * IHFreq / IVTotal ) * DVTotal
				ulFreq = ((DH_total_Temp*niHFreq*100*2) / niVActLen) * Get_DISP_VERTICAL_TOTAL();
			}
			else
#endif //#ifdef CONFIG_ATV_FRC
			if(_SRC_VO == Scaler_InputSrcGetMainChType())
			{
				ulFreq = ((DH_total_Temp*niHFreq*100*2) / niVActLen) * Get_DISP_VERTICAL_TOTAL();
			}
			else
			{
				//USER:LewisLee DATE:2012/04/19
				//if we have cut line, need adjust niVActLen
//				if((TRUE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC)) && (TRUE == fwif_scaler_decide_display_cut4line(SLR_MAIN_DISPLAY)))
				if(TRUE == fwif_scaler_decide_display_cut4line(SLR_MAIN_DISPLAY))
				{
					ulFreq = ((DH_total_Temp* niHFreq*100 * 2) / (niVActLen - 2)) * _DISP_LEN;
				}
				else
				{
					ulFreq = ((DH_total_Temp* niHFreq*100 * 2) / niVActLen) * _DISP_LEN;
				}
			}

			ulFreq = ((ulFreq >> 1) + (ulFreq & 0x01));

			ulFreq = drvif_get_dclk_margin(ulFreq);
		}
	}
	else
#endif
	{	//dclk over range, force to switch frc timing
		if(Dclk_Range_Temp_Flag == DCLK_OVER_RANGE)
			ret = 1;
	}

	fine_tune_dclk = ulFreq;

//#ifdef CONFIG_DCLK_CHECK
#if 0	//mag2 un-used dclk sel, move to dpll_o
	printk(KERN_INFO "\n after finetune DClk = %d Hz  &  Max DClk = %d Hz Min Dclk = %d Hz\n", ulFreq, Get_DISPLAY_CLOCK_MAX()/GET_PANEL_DCLK_DIV()*1000000,Get_DISPLAY_CLOCK_MIN()/GET_PANEL_DCLK_DIV()*1000000);
#else //#ifdef CONFIG_DCLK_CHECK
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n after finetune DClk = %d Hz  &  Max DClk = %d Hz Min Dclk = %d Hz\n", ulFreq, Get_DISPLAY_CLOCK_MAX()*1000000,Get_DISPLAY_CLOCK_MIN()*1000000);
#endif //#ifdef CONFIG_DCLK_CHECK
#else //#if 1
	if (!Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC))
	{



		if (ulFreq>Get_DISPLAY_CLOCK_MAX()*1000000)
		{
			ulFreq = Get_DISPLAY_CLOCK_MAX() * 1000000;
			dclkmax_zoom = 1;
		}
		else if (ulFreq < Get_DISPLAY_CLOCK_MIN()*1000000)
		{
			   if (!modestate_decide_double_dvs_enable())
			  {
				ulFreq = Get_DISPLAY_CLOCK_MIN() * 1000000;
				dclkmax_zoom = 0;
			  }
		}
		else
			dclkmax_zoom = 0;
	}
	else
		dclkmax_zoom = 0;

#endif //#if 1
#if 0 // mark below code of AT IC patch code
//frank@0811 add below code to solve mantis28967
	if ((Scaler_InputSrcGetMainChType()==_SRC_VO) && (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane())==0)) {
		IoReg_Mask32(PPOVERLAY_FS_IV_DV_Fine_Tuning1_reg, 0xf0000000, 10000);
		IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, 0x00000000);
	}
#endif

#if 0	//mag2 use new dclk formula
	//ulFreq>200MHz===>ulFreq * 16  too big(>32bit)
	//24.567MHz*(nMCode/nNCode)<=500 MHz
	//24.567MHz*(nMCode/nNCode)>=100 MHz
	//nMCode/nNCode<=20.3
	//nMCode/nNCode>=4
	//div>=25MHz*15/(ulFreq*8)
	//div<=125MHz*15/(ulFreq*8)
	//225MHz>=ulFreq>=28MHz
	//250MHz===>   1.04>=div>=0.208
	//28MHz===>   8.37>=div>=1.67

	if((ulFreq<=234000000) && (ulFreq>=46800000))
		div=1;
	else if((ulFreq<=117000000) && (ulFreq>=23400000))
		div=2;
	else if((ulFreq<=58000000) && (ulFreq>=11700000))
		div=4;
	else if((ulFreq<=29200000) && (ulFreq>=5850000))
 		div=8;

	//nMCode/nNCode<=20;setting  nMCode=temp*nNCode
	//nMCode/nNCode>=4;setting  nMCode=temp*nNCode
	//temp=ulFreq/24.567MHz*div*2*16/15 <=20
	//temp=ulFreq/24.567MHz*div*2*16/15 >=4
	temp=(ulFreq)*div*2*4/15/(CONFIG_CPU_XTAL_FREQ/256);
	temp=temp*4;

	if(temp>=(20*256))
		temp=20*256;
	if(temp<=(4*256))
		temp=4*256;

	for(cnt=3;cnt<=15;cnt++){
		nNCode=cnt;
		nMCode=nNCode*2*temp/256;
		nMCode = ((nMCode >> 1) + (nMCode & 0x01));
		if ((nMCode<=255)&&(nMCode>=3))
			break;
	}
#endif

	if((ulFreq>=400*1000000) && (ulFreq <= 700*1000000)){
		div = 1;
	}else if((ulFreq>=200*1000000) && (ulFreq <= 350*1000000)){
		div = 2;
		ulFreq = ulFreq*2;
	}else if((ulFreq>=100*1000000) && (ulFreq <= 175*1000000)){
		div = 4;
		ulFreq = ulFreq*4;
	}else{
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Error Dclk Range!\n");
	}

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n After Mapping (ulFreq:%d) (div:%d)======\n", ulFreq, div);
	nNCode = 3;
	dclk_Temp = ((ulFreq*nNCode) /(27*100));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"dclk_Temp:%d\n", dclk_Temp);
	nMCode = dclk_Temp/10000;
	f_code = ((dclk_Temp % 10000)*2048)/10000;  // offset
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"nMCode:%d, f_code:%d\n", nMCode, f_code);
	cpc = drvif_clock_cal_cpc(nMCode,nNCode);

	pll_ssc4_reg.regValue= IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);
	en_ssc_Temp = pll_ssc4_reg.en_ssc;
	pll_ssc4_reg.en_ssc = 0;
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);
	pll_ssc0_reg.regValue= IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
	pll_ssc0_reg.oc_en = 0;
	pll_ssc0_reg.fcode_t_ssc = 0;
	pll_ssc0_reg.oc_step_set = 0x200;
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);

	drvif_clock_set_pll(nMCode, nNCode, div, cpc);

#if 0//frank@02252014 mark below code
	//DPLL WD Status register is Abnormal
	pll_wdout_reg.regValue = IoReg_Read32(CRT_SYS_PLL_WD_OUT_reg);
	if(pll_wdout_reg.plldisp_wdout){

		pll_disp2_reg.regValue = IoReg_Read32(SYSTEM_PLL_DISP2_VADDR);
		pll_disp2_reg.dpll_pwdn = 0;//DPll power down
		IoReg_Write32(SYSTEM_PLL_DISP2_VADDR, pll_disp2_reg.regValue);

		//frank@0619 change below code to speed up
		Rt_Delay(5);
		//msleep(5);
		pll_disp2_reg.dpll_pwdn = 1;//DPll power on
		IoReg_Write32(SYSTEM_PLL_DISP2_VADDR, pll_disp2_reg.regValue);

//#else
		//DPLL WD Reset
		IoReg_SetBits(SYSTEM_PLL_DISP2_VADDR, _BIT14);
		RtSystem_Sleep(5);
		//DPLL LPF Mode
		IoReg_ClearBits(SYSTEM_PLL_DISP2_VADDR, _BIT8);
	}
#endif


/*
	pll_disp1_reg.regValue = rtdf_inl(SYSTEM_PLL_DISP2_VADDR);
	if(pll_disp1_reg.plldisp_rstb)
	{
		pll_disp1_reg.regValue = rtdf_inl(SYSTEM_PLL_DISP2_VADDR);
		pll_disp1_reg.dpllwdrst = 1;
		rtdf_outl(SYSTEM_PLL_DISP2_VADDR, pll_disp1_reg.regValue);

		pll_disp1_reg.regValue = rtdf_inl(SYSTEM_PLL_DISP2_VADDR);
		pll_disp1_reg.dplllpfmode = 0;
		rtdf_outl(SYSTEM_PLL_DISP2_VADDR, pll_disp1_reg.regValue);
	}
*/
#if 0	//mag2 use new dclk formula	// Dclk frequency in Hz
	//CONFIG_SCALER_XTAL_FREQ * nMCode too big(>32bit)
	nDPLL = ((CONFIG_CPU_XTAL_FREQ/128 * nMCode) / (div * nNCode*2))*128;

	// Offset resolution (DPLL / 2^15) in Hz
	nStep = nDPLL >> 15;

	// Target frequency of Dclk in Hz
	if(ulFreq >= (nDPLL*15/16)){
		temp = (ulFreq-(nDPLL*15/16) ) / nStep;
		temp = 0x800-temp;
	}
	else{
		temp = ((nDPLL*15/16)-ulFreq ) / nStep;
		temp = 0x800+temp;
	}

	//Enable DDS spread spectrum output function
#endif
	drvif_clock_offset(f_code);

	pll_ssc0_reg.regValue= IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
	pll_ssc0_reg.oc_en = 1;
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);

	cnt=10;
	do{
		pll_ssc5_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC5_reg);
		msleep(10);
	}while((pll_ssc5_reg.oc_done != 1) && (cnt--));

	pll_ssc0_reg.oc_en = 0;
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);

	pll_ssc4_reg.regValue= IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);
	pll_ssc4_reg.en_ssc = en_ssc_Temp;
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);

	return ret;
}


unsigned char drvif_clock_set_dtg_uzu_div()
{
	sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;
	UINT32 dclk_fract_a, dclk_fract_b;

#ifdef CONFIG_MEMC_BYPASS
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n #### [%s] MEMC bypass. \n", __FUNCTION__);
	return 0;
#else
	if(Get_MEMC_Enable_Dynamic() == 0){
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n #### [%s]Not Vx1 panel. MEMC bypass. \n", __FUNCTION__);
		return 0;
	}
#endif

	dclk_fract_a = Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_REMOVE_RATIO)-1;
	dclk_fract_b = Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_MULTIPLE_RATIO)-1;
	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL)
            		dclk_fract_a = (Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_REMOVE_RATIO)*2)-1;
       	else
              	dclk_fract_a = Scaler_DispGetInputInfo(SLR_INPUT_FRAC_FS_REMOVE_RATIO)-1;
	sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	sys_dispclksel_reg.dclk_fract_a = dclk_fract_a;
	sys_dispclksel_reg.dclk_fract_b = (dclk_fract_b&0x1f);
	//sys_dispclksel_reg.dclk_fract_b_eco = (dclk_fract_b&_BIT5)?1:0; //k3l error will mark 0603
	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, sys_dispclksel_reg.regValue);

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n #### dclk_fract_a:%x, dclk_fract_b:%x\n", dclk_fract_a, dclk_fract_b);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n #### [%s]\n", __FUNCTION__);
	return 0;
}

unsigned char drvif_clock_set_dtg_uzu_divByDisp(unsigned char _channel)
{
        SCALER_DISP_CHANNEL channel = (SCALER_DISP_CHANNEL)_channel;
        sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;
        UINT32 dclk_fract_a, dclk_fract_b;

#ifdef CONFIG_MEMC_BYPASS
        rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n #### [%s] MEMC bypass. \n", __FUNCTION__);
        return 0;
#else
        if(Get_MEMC_Enable_Dynamic() == 0){
                rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n #### [%s]Not Vx1 panel. MEMC bypass. \n", __FUNCTION__);
                return 0;
        }
#endif

        dclk_fract_a = Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_FRAC_FS_REMOVE_RATIO)-1;
        dclk_fract_b = Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_FRAC_FS_MULTIPLE_RATIO)-1;
        if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL)
                dclk_fract_a = (Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_FRAC_FS_REMOVE_RATIO)*2)-1;
        else
                dclk_fract_a = Scaler_DispGetInputInfoByDisp(channel,SLR_INPUT_FRAC_FS_REMOVE_RATIO)-1;
        sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
        sys_dispclksel_reg.dclk_fract_a = dclk_fract_a;
        sys_dispclksel_reg.dclk_fract_b = (dclk_fract_b&0x1f);
        //sys_dispclksel_reg.dclk_fract_b_eco = (dclk_fract_b&_BIT5)?1:0; //k3l error will mark 0603
        IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, sys_dispclksel_reg.regValue);

        rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n #### dclk_fract_a:%x, dclk_fract_b:%x\n", dclk_fract_a, dclk_fract_b);
        rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n #### [%s]\n", __FUNCTION__);
        return 0;
}


unsigned char drvif_clock_set_dtg_memc_div()
{
	sys_reg_sys_dispclksel_RBUS sys_dispclksel_reg;
	sys_dispclksel_reg.regValue = IoReg_Read32(SYS_REG_SYS_DISPCLKSEL_reg);
	sys_dispclksel_reg.memc_me_div = 0;

	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_PIXEL_MODE) == PIXEL_MODE_2_PIXEL)
		sys_dispclksel_reg.dispd_memc_out_sel = 1;
	else
		sys_dispclksel_reg.dispd_memc_out_sel = 0;

	IoReg_Write32(SYS_REG_SYS_DISPCLKSEL_reg, sys_dispclksel_reg.regValue);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n #### [%s]\n", __FUNCTION__);
	return 0;
}


#ifdef CONFIG_DCLK_CHECK
void check_dclk2_is_underflow()
{
	unsigned int framerate = (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)+10)/10;
	unsigned int ulFreq;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"debug dclk2 %d %d %d %d\n",Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ),Get_DISP_HORIZONTAL_TOTAL(),Get_DISP_VERTICAL_TOTAL(),framerate);

	 ulFreq = (unsigned int)Get_DISP_HORIZONTAL_TOTAL() * (unsigned int)Get_DISP_VERTICAL_TOTAL() * framerate;

	   if(ulFreq < (unsigned int) Get_DISPLAY_CLOCK_MIN()  * 1000000)
	  {
		rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"dclk2 (div=1) is under flow ,  tune dhtotal to rising dclk\n");
		SET_PANEL_DCLK_STATUS(1); //under flow
	  }
	  else
		SET_PANEL_DCLK_STATUS(0);

}


void check_dclk_is_underflow()
{
	unsigned long long aclkcnt = 0;
	unsigned long long ulFreq;
	unsigned long long faclkcnt;
	unsigned long long ulparam1 =0;
	unsigned long ulparam2 =0;

	if(Scaler_InputSrcGetMainChType()==_SRC_VO){
		SLR_VOINFO* pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
		//if ( Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_THRIP) )
		if(TRUE == fwif_scaler_decide_display_cut4line(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))){
			ulparam1 = 27000000*(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-3)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
			ulparam2 = (unsigned long)pVOInfo->pixel_clk;
			//faclkcnt = 27000000*(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-3)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID))/(unsigned long)pVOInfo->pixel_clk;
			do_div(ulparam1, ulparam2);
			faclkcnt = ulparam1;
			// DI will remove 4 lines per frame ( 2 lines per field ), so we have to -2 more lines in active length.
		}else{
			ulparam1 = 27000000*(unsigned long)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-1)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
			ulparam2 = (unsigned long)pVOInfo->pixel_clk;
			//faclkcnt = 27000000*(unsigned long)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-1)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID))/(unsigned long)pVOInfo->pixel_clk;
			do_div(ulparam1, ulparam2);
			faclkcnt = ulparam1;
		}
		aclkcnt = faclkcnt;
	}
	else
	{
		SET_PANEL_DCLK_STATUS(0);
		return;

	}
	if(Scaler_InputSrcGetMainChType()!=_SRC_VO){
		if(TRUE == fwif_scaler_decide_display_cut4line(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))
		{
#if 0
			aclkcnt=(unsigned long long)(aclkcnt*(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-3)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)))/(unsigned long long)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)-1)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
#else //#if 0
// [Code Sync][LewisLee][0990623][1]
		//USER:LewisLee DATE:2010/6/23
		//if we want cut 4 line, we need re-calculate the clock
		//cut up 2 line => info->IHTotal * 2
		//cut down 2 line => info->IHTotal + info->IPH_ACT_WID
		//total => info->IHTotal * 3 + info->IPH_ACT_WID
			ulparam1 = (aclkcnt*(unsigned long long)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)<<1) - 3)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)));
            ulparam2 = (Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)<<1) - 1)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
			//aclkcnt=(unsigned long long)(aclkcnt*(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)<<1) - 3)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID)))/(unsigned long long)(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)*((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)<<1) - 1)+Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
			do_div(ulparam1, ulparam2);
			aclkcnt = ulparam1;
// [Code Sync][LewisLee][0990623][1][End]
#endif //#if 0
		}
	}

	ulparam1 = ((unsigned long long)(Get_DISP_HORIZONTAL_TOTAL())*(_DISP_LEN-1)+_DISP_WID)*27000000;

	ulparam2 = aclkcnt;
	//ulFreq = (unsigned int)(((unsigned long long)(Get_DISP_HORIZONTAL_TOTAL())*(_DISP_LEN-1)+_DISP_WID)*27000000/aclkcnt);
	do_div(ulparam1, ulparam2);
	ulFreq = ulparam1;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"ulFreq=%lld\n",ulFreq);

	  if(ulFreq < ((unsigned int) Get_DISPLAY_CLOCK_MIN() * 1000000))
	  {
	  	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"dclk is under flow ,  tune dhtotal to rising dclk\n");
	  	SET_PANEL_DCLK_STATUS(1);
	  }
	  else
	  	SET_PANEL_DCLK_STATUS(0);


	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "[check dclk ]   info->IPV_ACT_LEN=%x  info->IPH_ACT_WID = %x !!\n", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN),Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE, "[check dclk ]disp_h_total=%d, disp_len=%d, disp_wid=%d\n",Get_DISP_HORIZONTAL_TOTAL(), _DISP_LEN, _DISP_WID);
}


#else

void check_dclk2_is_underflow()
{
	unsigned int framerate = (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)+10)/10;
	unsigned int ulFreq;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"debug dclk2 %d %d %d %d\n",Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ),Get_DISP_HORIZONTAL_TOTAL(),Get_DISP_VERTICAL_TOTAL(),framerate);

	 ulFreq = (unsigned int)Get_DISP_HORIZONTAL_TOTAL() * (unsigned int)Get_DISP_VERTICAL_TOTAL()/2 * framerate;

	  if(ulFreq < (unsigned int) Get_DISPLAY_CLOCK_MIN() * 1000000)
	  {
	  	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"dclk2 is under flow ,  tune dhtotal to rising dclk\n");
	  	SET_PANEL_DCLK_STATUS(1); //under flow
	  }
	  else
	  	SET_PANEL_DCLK_STATUS(0);

}

#endif


unsigned char drvif_clock_set_dclk2(unsigned short htotal, unsigned short vtotal, unsigned short usFrameRate)
{
//    unsigned int cpc,cnt=0,div=1;
    unsigned int cpc,div=1;
    unsigned int nMCode,nNCode, f_code;
//    unsigned int nDPLL,temp=0;
    unsigned int temp=0;
//    unsigned int nStep;
    unsigned int ulFreq;
    unsigned short framerate = usFrameRate;
    UINT32 dclk_Temp, en_ssc_Temp;
	unsigned int cnt=0;
    pll27x_reg_pll_ssc0_RBUS pll_ssc0_reg;
	pll27x_reg_pll_ssc4_RBUS pll_ssc4_reg;
	pll27x_reg_pll_ssc5_RBUS pll_ssc5_reg;

	if((Get_DISPLAY_PANEL_TYPE() == P_VBY1_4K2K) ||
		(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI) ||
		(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI) ||
		(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_LVDS_2K))
		return 1;

#ifdef CONFIG_ALL_SOURCE_DATA_FS
	return 1;
#endif

#if 0
	if(Get_DISPLAY_PANEL_TYPE() == P_DISP_TO_TVOX){
		printk(KERN_INFO "Disp to TVBOX use fix dclk now. \n");
#ifdef RUN_ON_TVBOX
		drvif_set_dclk_sync_tvbox(scalerdisplay_get_display_tve_mode());
#endif
#if 0
		IoReg_Write32(SYSTEM_PLL_DISP1_VADDR, 0x01f01700);
		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, 0x00000001);
		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, 0x00000005);
#endif
		return 1;
	}
#endif
#ifdef CONFIG_VBY_ONE_M4_DEMO
		IoReg_Write32(SYSTEM_PLL_DISP1_VADDR, 0x01f01700);
		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, 0x00000001);
		IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, 0x00000005);
		IoReg_Write32(PPOVERLAY_DCLK_SEL_VADDR, 0);
		return 1;
#endif
	if(Get_DISPLAY_PANEL_TYPE() == P_LVDS_TO_HDMI)
	{
#if 0 //fix me later by ben wang
		IoReg_Write32(CRT_SYS_PLL_DISP1_VADDR, 0x01f01600);
		IoReg_Write32(CRT_SYS_DCLKSS_VADDR, 0x00000001);
		IoReg_Write32(CRT_SYS_DCLKSS_VADDR, 0x00000005);
#endif
		return 0;
	}

    ulFreq = (unsigned int)htotal * (unsigned int)vtotal * (unsigned int)framerate;

#ifdef CONFIG_DCLK_CHECK

    rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n DClk2 = %d Hz  &  Max DClk2 = %d Hz & Min Dclk2 = %d Hz\n", ulFreq, Get_DISPLAY_CLOCK_MAX()/GET_PANEL_DCLK_DIV()*1000000,Get_DISPLAY_CLOCK_MIN()/GET_PANEL_DCLK_DIV()*1000000);

    rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"hotal=%d vtotal=%d framerate=%d\n",htotal,vtotal,framerate);

    if(ulFreq>(unsigned int)Get_DISPLAY_CLOCK_MAX()/GET_PANEL_DCLK_DIV()*1000000)
        ulFreq=(unsigned int)Get_DISPLAY_CLOCK_MAX()/GET_PANEL_DCLK_DIV()*1000000;

    if(ulFreq<(unsigned int)Get_DISPLAY_CLOCK_MIN()/GET_PANEL_DCLK_DIV()*1000000)
        ulFreq=(unsigned int)Get_DISPLAY_CLOCK_MIN()/GET_PANEL_DCLK_DIV()*1000000;

#else
    rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n DClk = %d Hz  &  Max DClk = %d Hz & Min Dclk = %d Hz\n", ulFreq, Get_DISPLAY_CLOCK_MAX()*1000000,Get_DISPLAY_CLOCK_MIN()*1000000);

    if(ulFreq>(unsigned int)Get_DISPLAY_CLOCK_MAX()*1000000)
        ulFreq=(unsigned int)Get_DISPLAY_CLOCK_MAX()*1000000;

//	 if(ulFreq<(unsigned int)Get_DISPLAY_CLOCK_MIN()*1000000)
   //    	 ulFreq=(unsigned int)Get_DISPLAY_CLOCK_MIN()*1000000;
#endif

	if (_TRUE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_FRAMESYNC))
	{
//	    if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES() == 0)
//		ulFreq = drvif_get_dclk_margin(ulFreq);
#if 0	//mag2 un-used dclk sel, move to dpll_o
		 printk(KERN_INFO "\n after finetune DClk2 = %d Hz  &  Max DClk2 = %d Hz & Min Dclk2 = %d Hz\n", ulFreq, Get_DISPLAY_CLOCK_MAX()/GET_PANEL_DCLK_DIV()*1000000,Get_DISPLAY_CLOCK_MIN()/GET_PANEL_DCLK_DIV()*1000000);
#else
		 rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n after finetune DClk2 = %d Hz  &  Max DClk2 = %d Hz & Min Dclk2 = %d Hz\n", ulFreq, Get_DISPLAY_CLOCK_MAX()/1000000,Get_DISPLAY_CLOCK_MIN()/1000000);
#endif
	}
	//fine_tune_dclk = ulFreq;
	fine_tune_dclk = ulFreq;

#if 0	//mag2 use new dclk formula

    //ulFreq>200MHz===>ulFreq * 16  too big(>32bit)
    //24.567MHz*(nMCode/nNCode)<=500 MHz
    //24.567MHz*(nMCode/nNCode)>=100 MHz
    //nMCode/nNCode<=20.3
    //nMCode/nNCode>=4
    //div>=25MHz*15/(ulFreq*8)
    //div<=125MHz*15/(ulFreq*8)
    //225MHz>=ulFreq>=28MHz
    //250MHz===>   1.04>=div>=0.208
    //28MHz===>   8.37>=div>=1.67

	if((ulFreq<=234000000) && (ulFreq>=46800000))
		div=1;
	else if((ulFreq<=117000000) && (ulFreq>=23400000))
		div=2;
	else if((ulFreq<=58000000) && (ulFreq>=11700000))
		div=4;
	else if((ulFreq<=29200000) && (ulFreq>=5850000))
		div=8;

    //nMCode/nNCode<=20;setting  nMCode=temp*nNCode
    //nMCode/nNCode>=4;setting  nMCode=temp*nNCode
    //temp=ulFreq/24.567MHz*div*2*16/15 <=20
    //temp=ulFreq/24.567MHz*div*2*16/15 >=4
    temp=(ulFreq)*div*2*4/15/(CONFIG_CPU_XTAL_FREQ/256);
    temp=temp*4;

    if(temp>=(20*256))
        temp=20*256;
    if(temp<=(4*256))
        temp=4*256;

    for(cnt=3;cnt<=15;cnt++)
    {
        nNCode=cnt;
        nMCode=nNCode*2*temp/256;
        nMCode = ((nMCode >> 1) + (nMCode & 0x01));
        if ((nMCode<=255)&&(nMCode>=3))
            break;
    }

	// [SG] avoid d-clock too high
	if(Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE() && (nNCode == 3) && (nMCode > _MAX_M_CODE)){
			unsigned char ucHdmi4k2kModeFlag=FALSE;
  #ifdef ENABLE_HDMI_DMA_FOR_4K2K // [HDMI-DMA] HDMI-DMA source change control
  			ucHdmi4k2kModeFlag = Scaler_GetHdmiDmaCapture_Enable() && (Scaler_GetHdmiDmaCapture_Status() == HDMI_DMA_4K2K_STATE_CHANGE_SRC);
  #endif
		if((Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) && ((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) == (VO_FR_CTRL_FORCE_FRAMERATE_MAX/100))|| Scaler_VOFromJPEG(Scaler_Get_CurVoInfo_plane())))
			/*|| (drvif_scaler_decide_2D_freerun_120hz() && (framerate == 120))*/
			|| (ucHdmi4k2kModeFlag == TRUE))
		{
			printk(KERN_INFO "[SLR] Mcode[%x] change to[%x]\n", nMCode, _MAX_M_CODE);
			nMCode = _MAX_M_CODE;
		}
	}
#endif

    if((ulFreq>=400*1000000) && (ulFreq <= 700*1000000)){
    	div = 1;
    }else if((ulFreq>=200*1000000) && (ulFreq <= 350*1000000)){
    	div = 2;
    	ulFreq = ulFreq*2;
    }else if((ulFreq>=100*1000000) && (ulFreq <= 175*1000000)){
    	div = 4;
    	ulFreq = ulFreq*4;
    }else{
    	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n Error Dclk Range!\n");
    }

    rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n After Mapping (ulFreq:%d) (div:%d)======\n", ulFreq, div);
    nNCode = 3;
    dclk_Temp = ((ulFreq*nNCode) /(27*100));
    rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"dclk_Temp:%d\n", dclk_Temp);
    nMCode = dclk_Temp/10000;
    f_code = ((dclk_Temp % 10000)*2048)/10000;  // offset
    rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"nMCode:%d, f_code:%d\n", nMCode, f_code);
    cpc = drvif_clock_cal_cpc(nMCode,nNCode);


	pll_ssc4_reg.regValue= IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);
	en_ssc_Temp = pll_ssc4_reg.en_ssc;
	pll_ssc4_reg.en_ssc = 0;
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);
    pll_ssc0_reg.regValue= IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
    pll_ssc0_reg.oc_en = 0;
    pll_ssc0_reg.fcode_t_ssc = 0;
    pll_ssc0_reg.oc_step_set = 0x200;
    IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);


    drvif_clock_set_pll(nMCode, nNCode, div, cpc);
#if 0 //frank@0225 mark below code
	//DPLL WD Status register is Abnormal
	if(IoReg_ReadByte0(SYSTEM_PLL_WDOUT_VADDR)  & _BIT5)
	{
		IoReg_ClearBits(SYSTEM_PLL_DISP2_VADDR, _BIT0);//DPll power down
		msleep(5);
		IoReg_SetBits(SYSTEM_PLL_DISP2_VADDR, _BIT0);//DPll power on
	}
#endif
#if 0	//mag2 use new dclk formula	// Dclk frequency in Hz

    // Dclk frequency in Hz
    //CONFIG_SCALER_XTAL_FREQ * nMCode too big(>32bit)
    nDPLL = ((CONFIG_CPU_XTAL_FREQ/128 * nMCode) / (div * nNCode*2))*128;

    // Offset resolution (DPLL / 2^15) in Hz
    nStep = nDPLL >> 15;

    // Target frequency of Dclk in Hz
    if(ulFreq >= (nDPLL*15/16)){
    	temp = (ulFreq-(nDPLL*15/16) ) / nStep;
    	temp = 0x800-temp;
    }
    else{
    	temp = ((nDPLL*15/16)-ulFreq ) / nStep;
    	temp = 0x800+temp;
    }
#endif

    //Enable DDS spread spectrum output function
    drvif_clock_offset(temp);

	pll_ssc0_reg.oc_en = 1;
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);
	cnt=10;
	do{
		pll_ssc5_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC5_reg);
		msleep(10);
	}while((pll_ssc5_reg.oc_done != 1) && (cnt--));
    pll_ssc0_reg.regValue= IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
    pll_ssc0_reg.oc_en = 1;
    IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);

	pll_ssc4_reg.regValue= IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);
	pll_ssc4_reg.en_ssc = en_ssc_Temp;
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);
    return 1;
}



void drvif_clock_offset(unsigned short usDclkOffset)
{
	pll27x_reg_pll_ssc0_RBUS pll_ssc0_reg;
#if 0
//#ifdef VBY_ONE_PANEL
	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_4K2K)
		return;
//#endif
#endif
	pll_ssc0_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
	pll_ssc0_reg.fcode_t_ssc= usDclkOffset;
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);
}




static unsigned char get_apll_setting(unsigned char num, unsigned short usClock)
{

	unsigned short ucTemp = 0;
	dds_pll_plldiv_RBUS dds_pll_plldiv_reg;

	usClock -= 1;
	///////////////////////////////////////

	dds_pll_plldiv_reg.regValue = IoReg_Read32(DDS_PLL_PLLDIV_reg);
	ucTemp = dds_pll_plldiv_reg.pll_divider;


	rtd_printk(KERN_DEBUG, TAG_NAME_ADC,"\nTemp AClock = %x\n", num);

	if(ucTemp  != usClock){
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\n Clock no match !\n");
		return TRUE;
	}
	else{

		rtd_printk(KERN_DEBUG, TAG_NAME_ADC,"\n Clock match !\n");
		return FALSE;
	}

}

#ifdef ADJUST_APLL_NEW_METHOD
unsigned int Clock_GetCorrectSUM_I(void)
{
	unsigned int PLLRealSUM_I = 0x80000000;
	unsigned char ucTimeOutCount = 5;

	IoReg_Mask32(DDS_PLL_FAST_PLL_CTRL_reg, ~(_BIT2 | _BIT0), (_BIT2 | _BIT0)); //start measure SUM_I

	do
	{
		msleep(20);
		PLLRealSUM_I = (IoReg_Read32(DDS_PLL_FAST_PLL_CTRL_reg)&0x4)>>2;
	}while(--ucTimeOutCount && PLLRealSUM_I);

	if(ucTimeOutCount)
	{
		PLLRealSUM_I = (IoReg_Read32(DDS_PLL_FAST_PLL_SUM_I_MEASURE_reg)&0x07ffffff);
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC,"\n PLLRealSUM_I = %x\n",PLLRealSUM_I);
	}
	else //timeout
	{
		PLLRealSUM_I = 0x80000000;//fail
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC,"\n Measure Fail%c\n",'!');
	}

	return PLLRealSUM_I;
}

void Clock_SetCustomizePICode(unsigned char display)
{
	if ((Scaler_InputSrcGetType(display) == _SRC_VGA))
	{
		if(Scaler_DispGetStatus(display,SLR_DISP_THRIP))
		{
			// CSW+ 0960717 VGA interlace signal has internal field detection ODD signal
			if (display == SLR_MAIN_DISPLAY)
				IoReg_Mask32(VGIP_VGIP_CHN1_CTRL_reg, ~(_BIT18|_BIT16), (_BIT18|_BIT16));
			else
				IoReg_Mask32(SUB_VGIP_VGIP_CHN2_CTRL_reg, ~(_BIT18|_BIT16), (_BIT18|_BIT16));
		}
		else
		{
			// CSW+ 0961129 VGA progressive signal has no internal field detection ODD signal
			if (display == SLR_MAIN_DISPLAY)
				IoReg_Mask32(VGIP_VGIP_CHN1_CTRL_reg, ~(_BIT18|_BIT16), 0x0);
			else
				IoReg_Mask32(SUB_VGIP_VGIP_CHN2_CTRL_reg, ~(_BIT18|_BIT16), 0x0);
	}

	msleep(10);
}

void Clock_RecordCurrentMKSum(unsigned int OldClock, unsigned short mcode, char kcode)
{
	unsigned int tempSUM_I = 0;

	tempSUM_I= Clock_GetCorrectSUM_I(); //record the old Sum_I
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC,"\n RealSumI = %x\n",tempSUM_I);

	//Record (16M+K+Fraction_part) << _FRACTION_DIGIT
	if((tempSUM_I & 0x80000000) == 0)
	{
		if(kcode & 0x80) //negtive direction
			uOldMKRecord = ( mcode << 4) - (256-(kcode & 0x000000ff));
		else
			uOldMKRecord = ( mcode << 4) + kcode;

		uOldMKRecord = uOldMKRecord << _FRACTION_DIGIT;

		if(tempSUM_I & 0x07000000) //SUM_I is negtive
			uOldMKRecord = uOldMKRecord - ((0x07ffffff - tempSUM_I) >> (22 - _FRACTION_DIGIT));
		else
			uOldMKRecord = uOldMKRecord + (tempSUM_I >> (22 - _FRACTION_DIGIT));
	}
	uOldPllClock = OldClock;//record the old Pll clock
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC,"\n uOldMKRecord = %x\n",uOldMKRecord);
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC,"\n uOldPllClock = %x\n",uOldPllClock);
}
#endif //#ifdef ADJUST_APLL_NEW_METHOD

/*============================================================================*/
/**
 * drvif_clk_power_AdcApllEnable
 * Power on/off ADC and APLL.
 *
 * @param <on_off>	{ power up or down for system }
 * @return 			{ void }
 *
*/
void drvif_clk_power_AdcApllEnable(int src)
{
	switch(src)
	{
		case _SRC_VGA:
			VGA_ADCPowerControl(TRUE);
		break;

		case _SRC_YPBPR:
			YPbPr_ADCPowerControl(TRUE);
		break;

		default:
		break;
	}
}

//[Code Sync][AlanLi][0980617][1]
void drvif_clock_select_VCO_div(StructDisplayInfo * p_dispinfo)
{
	unsigned int clock;
	unsigned long long ulparam1 =0;
	unsigned long long ulparam2 =0;
	unsigned short IHTotal = p_dispinfo->IHTotal;
	unsigned short IHCount_PRE =  p_dispinfo->IHCount_PRE;
	ulparam1 = (unsigned long long)CONFIG_CPU_XTAL_FREQ * IHTotal;
    ulparam2 = (unsigned long long)IHCount_PRE;
	//clock =(unsigned int) ((unsigned long long)CONFIG_CPU_XTAL_FREQ * IHTotal /(unsigned long long)IHCount_PRE/1000);
	do_div(ulparam1, ulparam2);
	ulparam2 = (unsigned long long)1000;
	do_div(ulparam1, ulparam2);
	clock = ulparam1;

	select_adc_vco_div = clock < 100000 ? 4 : 2;

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] p_dispinfo->IHTotal=%d\n", __FUNCTION__, __LINE__, IHTotal );
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] select_adc_clk_div=%d\n", __FUNCTION__, __LINE__, select_adc_vco_div);
}
//[Code Sync][AlanLi][0980617][1][end]



/*============================================================================*/
/**
 * drvif_clock_set_aclk
 * Set ADC clock setup
 *
 * @param <unsigned short>	{ freq in KHz}
 * @return 			{ void }
 *
 */
 //#define _APLL_FAST_LOCK        TRUE

#if 1 //def CONFIG_VGA_JUMP_PHASE_SOLVED
#define _FRACTION_DIGIT           (16) //this value should not be larger than 7, or some timing will result in overflow in the calculation process
#else
#define _FRACTION_DIGIT           (7) //this value should not be larger than 7, or some timing will result in overflow in the calculation process
#endif


#if 0 // FIB_IC_PATCH
unsigned char Apll_m_n_code_patch(unsigned char display, unsigned short *mcode , unsigned short *ncode, char *kcode ,unsigned long long *SUM_I , unsigned int usClock)
{

		unsigned int 	tmpclock;
		static unsigned char vco_divider = 2;
		unsigned long long pllclock, icode;
		vco_divider =select_adc_vco_div;
		tmpclock = usClock;
	//	char kcode, g_value = 1;
		tmpclock =(unsigned int) ((unsigned long long)CONFIG_CPU_XTAL_FREQ * usClock/(unsigned long long)/*stModeInfo.IHCount*/Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_COUNT)/1000);

		while(( (*mcode - 3) & _BIT4) > 0)
		{
			*ncode = *ncode + 1;
			pllclock = (((unsigned long long)tmpclock * (*ncode) * vco_divider) << (4 + _FRACTION_DIGIT)) / (unsigned long long)(CONFIG_CPU_XTAL_FREQ/1000); //calculate the more precise one
			*SUM_I = ((((unsigned long long)tmpclock * (*ncode) * vco_divider) << 4) / (unsigned long long)(CONFIG_CPU_XTAL_FREQ/1000)) << _FRACTION_DIGIT; //calculate the truncated one

			*mcode = pllclock >> _FRACTION_DIGIT >> 4; //M1 is the integer part

			*kcode = (pllclock >> _FRACTION_DIGIT) -( (*mcode) << 4);
			*SUM_I = pllclock - *SUM_I;  //SUM_I is the truncated part by calculation quantized by 1024

			printk(KERN_INFO "\n mcode = %x", *mcode);
			printk(KERN_INFO "\n kcode = %x", *kcode);

			//k is range from -8 ~ 7
			if ( (*kcode)>7)
			{
				*mcode = *mcode + 1;
				*kcode = *kcode - 16;
			}
			else if((*kcode)<(-8))
			{
				*mcode = *mcode - 1;
				*kcode = *kcode + 16;
			}

		}

}
#endif


unsigned char drvif_clock_set_aclk(StructDisplayInfo * p_dispinfo, int src, unsigned int usClock, unsigned char fast_lock_enable)
{
	unsigned long long pllclock, icode,SUM_I;
	unsigned short mcode = 0, ncode = 0;
	unsigned char Data[4];
	char kcode, g_value = 1;
#if _max_bit_32	//if max bit lengh 32
	unsigned short pcode;
#else
	unsigned long long pcode;
#endif
	static unsigned char vco_divider = 2;
	unsigned short g_value_divider[6] = {4, 16, 64, 128, 256, 512};
	unsigned int 	tmpclock,pcode_remainder;
	unsigned long long ulparam1 =0;
	unsigned long long ulparam2 =0;
	unsigned int pixelclock;
	unsigned int apll_n_value_for_i_code;

	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;
	//#define _PE_VALUE   175 // Unit: ps
	dds_pll_pll_phase_interpolation_RBUS dds_pll_pll_phase_interpolation_reg;
	dds_pll_pll_div_ctrl_RBUS dds_pll_pll_div_ctrl_reg;
	dds_pll_fast_pll_ctrl_RBUS dds_pll_fast_pll_ctrl_reg;
	dds_pll_pe_tracking_method_RBUS dds_pll_pe_tracking_method_reg;
	dds_pll_dds_mix_w1_RBUS dds_pll_dds_mix_w1_reg;
	dds_pll_pll_set_RBUS dds_pll_pll_set_reg;
	dds_pll_pllphase_ctrl_RBUS dds_pll_pllphase_ctrl_reg;
	dds_pll_plldiv_RBUS dds_pll_plldiv_reg;
	dds_pll_fast_pll_sum_i_RBUS dds_pll_fast_pll_sum_i_reg;
	dds_pll_i_code_RBUS dds_pll_i_code_reg;
	dds_pll_p_code_mapping_methods_RBUS dds_pll_p_code_mapping_methods_reg;
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
//	vgip_chn2_ctrl_RBUS vgip_chn2_ctrl_reg;
//	vgip_chn2_status_RBUS vgip_chn2_status_reg;
#endif

	//if(!CAdjustCheckAdcClockRange(usClock, &delta))
	//    usClock = stModeInfo.IHTotal;
	//pllclock = (DWORD)stModeInfo.IHFreq * usClock * 2 * 100 / _RTD_XTAL;
	/**
	Fvco : Frequency of APLL
	Fxtal : Frequency of Crystal
	IHF : Input Horizontal Frequency
	usClock : Divider number of input clock
	stModeInfo.IHFreq = 10 * IHF(in KHz)
	_RTD_XTAl : Defined crystal clock unit in KHz

	Fvco = Fxtal*(M1+K/16)/N1 = IHF * usClock * vco_divider
	Assum N1 = 2
	(M1 + K/16) = IHF * usClock * N1 * vco_divider / Fxtal
	16*M1 + K = IHF * usClock * N1 * vco_divider * 16 / Fxtal = pllclock / 2^_FRACTION_DIGIT
	stModeInfo.IHFreq UINT in 100Hz

	*/

	if(p_dispinfo->IHFreq == 0) return FALSE;//Hardy20071018

	switch (p_dispinfo->ucMode_Curr) {
	case _MODE_480I:
	case _MODE_576I:
	case _MODE_480P:
	case _MODE_576P:
		apll_n_value_for_i_code = _SD_APLL_N_VALUE_FOR_I_CODE;//SD timing
		break;

	default:
		apll_n_value_for_i_code = _HD_APLL_N_VALUE_FOR_I_CODE;//HD timing
		break;
	}

	ncode = 3;

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] p_dispinfo->IHCount_PRE=%d\n", __FUNCTION__, __LINE__, p_dispinfo->IHCount_PRE);
	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] usClock=%d\n", __FUNCTION__, __LINE__, usClock);

	//ADC sampling clock, UNIT in KHz
	ulparam1 = (unsigned long long)CONFIG_CPU_XTAL_FREQ * usClock;

    ulparam2 = (unsigned long long)(p_dispinfo->IHCount_PRE);
	//tmpclock =(unsigned int) ((unsigned long long)CONFIG_CPU_XTAL_FREQ * usClock/(unsigned long long)/*stModeInfo.IHCount*/Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_COUNT)/1000);
	do_div(ulparam1, ulparam2);

	ulparam2 = (unsigned long long)1000;
	do_div(ulparam1, ulparam2);
	tmpclock = (unsigned int)ulparam1;

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] tmpclock=%d\n", __FUNCTION__, __LINE__, tmpclock);
	//[Code Sync][AlanLi][0980617][1]
	//vco_divider = tmpclock < 100000 ? 4 : 2;
	vco_divider =select_adc_vco_div;
	//[Code Sync][AlanLi][0980617][1][end]
	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] vco_divider=%d\n", __FUNCTION__, __LINE__, vco_divider);
	ulparam1 = (((unsigned long long)tmpclock * ncode * vco_divider) << (4 + _FRACTION_DIGIT));
	ulparam2 = (unsigned long long)(CONFIG_CPU_XTAL_FREQ/1000);
	//pllclock = (((unsigned long long)tmpclock * ncode * vco_divider) << (4 + _FRACTION_DIGIT)) / (unsigned long long)(CONFIG_CPU_XTAL_FREQ/1000); //calculate the more precise one
	do_div(ulparam1, ulparam2);
	pllclock = ulparam1;
	ulparam1 = (((unsigned long long)tmpclock * ncode * vco_divider) << 4);
	ulparam2 = (unsigned long long)(CONFIG_CPU_XTAL_FREQ/1000);
	//SUM_I = ((((unsigned long long)tmpclock * ncode * vco_divider) << 4) / (unsigned long long)(CONFIG_CPU_XTAL_FREQ/1000)) << _FRACTION_DIGIT; //calculate the truncated one
	do_div(ulparam1, ulparam2);
	SUM_I = ulparam1<< _FRACTION_DIGIT;

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] APLLclock 1 = 0x%08x\n", __FUNCTION__, __LINE__, (unsigned int)pllclock);//test by tyan

	dds_pll_pll_div_ctrl_reg.regValue = 0;

	dds_pll_pll_div_ctrl_reg.delay_cp_mode = 12;

	IoReg_Write32(DDS_PLL_PLL_DIV_CTRL_reg, dds_pll_pll_div_ctrl_reg.regValue);

	//enable fast lock
	if(fast_lock_enable)
	{
		dds_pll_fast_pll_ctrl_reg.regValue = 0;
		dds_pll_fast_pll_ctrl_reg.fast_lock_en = _ENABLE;
		IoReg_Write32(DDS_PLL_FAST_PLL_CTRL_reg, dds_pll_fast_pll_ctrl_reg.regValue);

		//IoReg_Mask32(DDS_PLL_PLL_DIV_CTRL_reg,~(0xfffffff3),_BIT5); //enable fast lock , check after ic back
	}

	dds_pll_pe_tracking_method_reg.regValue = 0;
	dds_pll_pe_tracking_method_reg.zoom_out_ratio = 2;
	IoReg_Write32(DDS_PLL_PE_tracking_method_reg, dds_pll_pe_tracking_method_reg.regValue);

	dds_pll_dds_mix_w1_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W1_reg);
	dds_pll_dds_mix_w1_reg.t_s = 3;
	dds_pll_dds_mix_w1_reg.pll_lock = 0;
	IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);

	//set the P_code_max
	dds_pll_dds_mix_w1_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W1_reg);
	dds_pll_dds_mix_w1_reg.p_code_max = 0x1FE00;
	IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);

	//need discuss, old mode do not need P code max

	//因目前APLL 調整Icp的MSB 2個bit沒有做,所以無法達到Icp / M code = constant(0.5).目前designer建議monitor的因應之道是無論M,N code設多少,Icp均設為15uA.designer認為在
	//現在無法固定constant的情況之下設為此值的tracking jitter會是較小的.而目前TV這邊的Icp都是固定設成default的10uA , 所以可能要改為建議的15uA.
	//在Dragon APLL Icp的設定 : 0x1805_0100[20:16]改設定成"5".

	//IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	//dds_pll_pll_set_reg.pllssi = 5;

	dds_pll_pllphase_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLLPHASE_CTRL_reg);
	dds_pll_pllphase_ctrl_reg.pllsph0path = PLLPH0PATH_LONG_PATH;//PLLPH0PATH;
	IoReg_Write32(DDS_PLL_PLLPHASE_CTRL_reg, dds_pll_pllphase_ctrl_reg.regValue);
	//rtd_printk(KERN_NOTICE, TAG_NAME_VBE,"#####[%s(%d)] DDS_PLL_PLLDIV_reg=0x%08x\n", __FUNCTION__, __LINE__, IoReg_Read32(DDS_PLL_PLLDIV_reg));
	adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut = 1;//Look-up table
	if(2 == vco_divider)
		adc_smartfit_adc_pllphase_ctrl_reg.pll2d2 = 0;//ADC CLK=1/2 VCO CLK
	else
		adc_smartfit_adc_pllphase_ctrl_reg.pll2d2 = 1;//ADC CLK=1/4 VCO CLK
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);

	adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_d2x = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_d2y = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2x = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2y = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_psel = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index_msb = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index = 0;
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);


	dds_pll_plldiv_reg.regValue = IoReg_Read32(DDS_PLL_PLLDIV_reg);
	dds_pll_plldiv_reg.pll_divider = usClock - 1;

	IoReg_Write32(DDS_PLL_PLLDIV_reg, dds_pll_plldiv_reg.regValue);
	// PLL N1
////////////////////////////////////////
//	get_apll_setting(0, usClock);
////////////////////////////////////////
	if(fast_lock_enable) //set the FAST PLL CONTROL
	{
		dds_pll_fast_pll_ctrl_reg.regValue = 0;
		dds_pll_fast_pll_ctrl_reg.fast_lock_en = 1;
		dds_pll_fast_pll_ctrl_reg.dummy1802013c_1 = 1;
		IoReg_Write32(DDS_PLL_FAST_PLL_CTRL_reg, dds_pll_fast_pll_ctrl_reg.regValue);
	}

	//set ncode
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pll_n = ncode - 2;
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);

	// PLL M1, K1
	// 16*M1 + K1 = pllclock/1024
	/**
	mcode = pllclock / 1024 / 16; //M1 is the integer part
	kcode = pllclock/1024 - 16*M1 //K1 is the fraction part quantized by 16
	*/
	mcode = pllclock >> _FRACTION_DIGIT >> 4; //M1 is the integer part
	kcode = (pllclock >> _FRACTION_DIGIT) -(mcode << 4);
	SUM_I = pllclock - SUM_I;  //SUM_I is the truncated part by calculation quantized by 1024

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] mcode = 0x%08x\n", __FUNCTION__, __LINE__, mcode);
	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] kcode = 0x%08x\n", __FUNCTION__, __LINE__, kcode);

	//k is range from -8 ~ 7
	if (kcode>7)
	{
		mcode +=1;
		kcode -= 16;
	}
	else if(kcode<(-8))
	{
		mcode -=1;
		kcode += 16;
	}


	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] mcode after = 0x%08x\n", __FUNCTION__, __LINE__, mcode - 3);
	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] kcode after = 0x%08x\n", __FUNCTION__, __LINE__, kcode);

	//forster modified 071030
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllsphnext = (kcode & 0x0f);
	dds_pll_pll_set_reg.pll_m = ((mcode - 3) & 0xff);
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);

	if(fast_lock_enable)
	{
		//Because SUM_I has 25 bits
		//SUM_I = ((DWORD)2^22*(DWORD)SUM_I)/2^_FRACTION_DIGIT; // over flow need to modify
		//SUM_I = SUM_I << (22 - _FRACTION_DIGIT); // over flow need to modify
		SUM_I = SUM_I << (22 - _FRACTION_DIGIT); // over flow need to modify
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] SUM_I1:0x%08x\n", __FUNCTION__, __LINE__,  (unsigned int)SUM_I);
		dds_pll_fast_pll_sum_i_reg.regValue = 0;
		dds_pll_fast_pll_sum_i_reg.sum_i_pre = SUM_I;
		IoReg_Write32(DDS_PLL_FAST_PLL_SUM_I_reg, dds_pll_fast_pll_sum_i_reg.regValue);
	}


      //pllclock = pllclock >> 4;

	/**
	Formula :
   	   I_gain          Ths                              PE(UNIT)                                      1
	--------- x  ------- = ------------------------------------ x  -----
	   2^22           Tbck               Txclk x 16N1/(16M1 +- K) x 1/16                8

	   I_gain             Ths                                 PE(UNIT)                                      1
	--------- x  ----------- = ------------------------------------ x  -----
	   2^22           Txclk x N1               Txclk x 16N1/(16M1 +- K) x 1/16                8

	                  2^22 x PE_U x (16M1 +- K)             1
	I_gain = ----------------------------- x -----
	                                   Ths                               8

	       2^19 x PE_U x (16M1 +- K)
	= -----------------------------
	                      Ths

	= IHF x 2^19 x PE_U x (16M1 +- K)

	*/

	//16M1 +- K = pllclock/2^_FRACTION_DIGIT
	// _PE_VALUE UNIT is ps, so result has to multiply 10^(-12)
	// stModeInfo.IHFreq/10 UNIT is KHz, so result has to multiply 10^2
       //10^(-12)*10^2 = 10^(-10)
	//icode = ((DWORD)(tYPbPrMODE_TABLE[st263xInfo.Mode_Curr].IHFreq* usRTD2622PE_Value * pllclock) << (19 - _FRACTION_DIGIT)) /10^10;
	//         =((DWORD)(tYPbPrMODE_TABLE[st263xInfo.Mode_Curr].IHFreq* usRTD2622PE_Value * pllclock) ) /(10^10 >> 2^(19 - _FRACTION_DIGIT));

	//icode = (unsigned long long)(disp_info[display].IHFreq) * usPE_Value_rtd2622 * (pllclock >> 4)/(10000000000 >> (19 + 4 -_FRACTION_DIGIT));

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] p_dispinfo->IHFreq = 0x%08x\n", __FUNCTION__, __LINE__,  p_dispinfo->IHFreq);

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] usPE_Value_rtd2622 = 0x%08x\n", __FUNCTION__, __LINE__, usPE_Value_rtd2622);

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] pllclock = 0x%08x\n", __FUNCTION__, __LINE__, (unsigned int)pllclock);

	ulparam1 = ((unsigned long long)p_dispinfo->IHFreq) * usPE_Value_rtd2622 * (pllclock >> 4);

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] ulparam1 = 0x%llx\n", __FUNCTION__, __LINE__, ulparam1);

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] apll_n_value_for_i_code = 0x%08x\n", __FUNCTION__, __LINE__, apll_n_value_for_i_code);

    ulparam2 = ((unsigned long long)10000000000LL >> ((22 - apll_n_value_for_i_code) + 4 -_FRACTION_DIGIT));

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] ulparam2 = 0x%llx\n", __FUNCTION__, __LINE__, ulparam2);

	do_div(ulparam1, ulparam2);

	icode = ulparam1;

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] origianl icode = 0x%08x\n", __FUNCTION__, __LINE__, (unsigned int)icode);

	if ( 0 == icode)
		icode = 1;

	switch (p_dispinfo->ucMode_Curr) {
	case _MODE_480I:
	case _MODE_576I:
	case _MODE_480P:
	case _MODE_576P:
		if (icode>0x30) icode=icode-4;	// for LG blu ray-BD690 //SD timing
		break;

	default://HD timing
		break;
	}
	dds_pll_pe_tracking_method_reg.regValue = 0;
	dds_pll_pe_tracking_method_reg.zoom_out_ratio = 2;
	IoReg_Write32(DDS_PLL_PE_tracking_method_reg, dds_pll_pe_tracking_method_reg.regValue);

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] icode1 = 0x%08x\n", __FUNCTION__, __LINE__, (unsigned int)icode);

	//Set the I_Code
	dds_pll_i_code_reg.regValue = 0;
	dds_pll_i_code_reg.i_code = icode & 0x00007fff;
	IoReg_Write32(DDS_PLL_I_CODE_reg, dds_pll_i_code_reg.regValue);

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] icode1 = 0x%08x\n", __FUNCTION__, __LINE__, (unsigned int)dds_pll_i_code_reg.i_code);

	// Set the P code (sync from pacific)
	//User:alanli Date:20100719 modify calculation to avoid overflow during calculation

	//pcode = ((_APLL_N_VALUE_FOR_P_CODE -1) * ((((unsigned int)icode)<<_APLL_N_VALUE_FOR_I_CODE)/_APLL_N_VALUE_FOR_P_CODE) * (CONFIG_CPU_XTAL_FREQ/1000) /Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_FREQ) /ncode) >> 7;

#if _max_bit_32	//if max bit lengh 32
	pcode = ((_APLL_N_VALUE_FOR_P_CODE -1) * ((((unsigned int)icode)<<apll_n_value_for_i_code)/_APLL_N_VALUE_FOR_P_CODE) /p_dispinfo->IHFreq * (CONFIG_CPU_XTAL_FREQ/1000) /ncode) >> 7;
	pcode_remainder=(_APLL_N_VALUE_FOR_P_CODE -1) * ((((unsigned int)icode)<<apll_n_value_for_i_code)/_APLL_N_VALUE_FOR_P_CODE) %p_dispinfo->IHFreq;
	pcode_remainder=((pcode_remainder*(CONFIG_CPU_XTAL_FREQ/1000)/ncode)>>7)/p_dispinfo->IHFreq;
	pcode = pcode+pcode_remainder;
#else
	ulparam1 = (_APLL_N_VALUE_FOR_P_CODE -1) * (((icode)<<apll_n_value_for_i_code)/_APLL_N_VALUE_FOR_P_CODE) * (CONFIG_CPU_XTAL_FREQ);
	ulparam2 = p_dispinfo->IHFreq * ncode * 10 * 100;	//freq * 100 = HZ
	do_div(ulparam1, ulparam2);
	pcode = ulparam1;
#endif

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] pcode = 0x%llx\n", __FUNCTION__, __LINE__, pcode);

	if(pcode > 255){

		for(Data[0] = 9; Data[0] < 14; Data[0]++){
			if((pcode >> Data[0]) == 0)
				break;
		}

#if _max_bit_32	//if max bit lengh 32
		pcode = pcode/g_value_divider[(Data[0] - 9)];		// notice: damage
#else
		do_div(pcode, g_value_divider[(Data[0] - 9)]);
#endif

		g_value = Data[0] -7;
#ifdef _PRINT_APLL_RESULT
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\n g_value_divider[(Data[0] - 9)] : %x\n",g_value_divider[(Data[0] - 9)]);
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\n Data[0] : %x\n",Data[0]);
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC,  "\n pcode : %x\n",pcode);
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\n g_value : %x\n",g_value);
#endif //#ifdef _PRINT_APLL_RESULT
	}

	dds_pll_p_code_mapping_methods_reg.regValue = 0;
	dds_pll_p_code_mapping_methods_reg.g_value = g_value & 0x0f;
	IoReg_Write32(DDS_PLL_P_CODE_mapping_methods_reg, dds_pll_p_code_mapping_methods_reg.regValue);

	//need discuss, old mode do not need p code max
	//set the P_code_max
	dds_pll_dds_mix_w1_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W1_reg);
	dds_pll_dds_mix_w1_reg.p_code_max = (0x51E<<1);
	IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] pcode = 0x%llx\n", __FUNCTION__, __LINE__, pcode);

	pcode = pcode<255?pcode:255;

	IoReg_Write32(DDS_PLL_P_CODE_reg, pcode);

	if(fast_lock_enable) //Enable Double buffer write in PLL M/N K PLLDIVDDS SUM_I
	{
		dds_pll_fast_pll_ctrl_reg.regValue = 0;
		dds_pll_fast_pll_ctrl_reg.apll_setting_en = 1;
		dds_pll_fast_pll_ctrl_reg.fast_lock_en = 1;
		IoReg_Write32(DDS_PLL_FAST_PLL_CTRL_reg, dds_pll_fast_pll_ctrl_reg.regValue);
	}
	else
	{
		dds_pll_fast_pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_FAST_PLL_CTRL_reg);
		dds_pll_fast_pll_ctrl_reg.apll_setting_en = 1;
		IoReg_Write32(DDS_PLL_FAST_PLL_CTRL_reg, dds_pll_fast_pll_ctrl_reg.regValue);
	}

	msleep(10);

	Data[0] = 200;
	do{
		dds_pll_plldiv_reg.regValue = IoReg_Read32(DDS_PLL_PLLDIV_reg);
		dds_pll_plldiv_reg.pll_divider = ((usClock - 1)&0x0fff);
		IoReg_Write32(DDS_PLL_PLLDIV_reg, dds_pll_plldiv_reg.regValue);
	}while(get_apll_setting(1,usClock) && --Data[0]);

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] Data[0]:%d#####\r\n", __FUNCTION__, __LINE__, Data[0]);

	drvif_clk_power_AdcApllEnable(src);

	// Calculate pixel clock rate (round to MHz)
	pixelclock  = (((unsigned int)(p_dispinfo->IHFreq) * (unsigned int)p_dispinfo->IHTotal) * 2 / (1000 * 10));
	pixelclock  = (pixelclock >> 1) + (pixelclock & 0x01);
	dds_pll_pll_phase_interpolation_reg.regValue = IoReg_Read32(DDS_PLL_PLL_PHASE_INTERPOLATION_reg);
	if(pixelclock < 25)//25M HZ
		dds_pll_pll_phase_interpolation_reg.pllsphrl = 1;  //sirus VCO interpolation
	else
		dds_pll_pll_phase_interpolation_reg.pllsphrl = 2;  //sirius VCO interpolation
	IoReg_Write32(DDS_PLL_PLL_PHASE_INTERPOLATION_reg, dds_pll_pll_phase_interpolation_reg.regValue);//will add from brandon suggestion

	dds_pll_pll_ctrl_RBUS dds_pll_pll_ctrl_reg;

	dds_pll_pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
	dds_pll_pll_ctrl_reg.pllpwdn = 1;//REG_APLLPWDN (PLL Power Down) 1: Power Down
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);
	msleep(2);
	dds_pll_pll_ctrl_reg.pllpwdn = 0;//REG_APLLPWDN (PLL Power Down) 1: Power Down
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);
	return ((Data[0] == 0) ? TRUE : FALSE);
}


/* fixed dclk by panel for vodma use */
void drvif_clock_vodma_dclk(void)
{
	ppoverlay_dv_den_start_end_RBUS ppoverlay_dv_den_start_end_reg;
	unsigned int panel_type;
	unsigned int v;
	ppoverlay_dv_den_start_end_reg.regValue = IoReg_Read32(PPOVERLAY_DV_DEN_Start_End_reg);

	v = ppoverlay_dv_den_start_end_reg.dv_den_end - ppoverlay_dv_den_start_end_reg.dv_den_sta;

	if ( v < 1019) //768, +-5 range
		panel_type = PANEL_NO_DEFINED_1366x768;
	else if ( v >= 1019 && v <= 1029) //1024, +-5 range
		panel_type = PANEL_SXGA_1280x1024;
	else
		panel_type = PANEL_HD1080_1920x1080;

	switch (panel_type)
	{
		case PANEL_NO_DEFINED_1366x768:
	        /* fix dclk 80.44Mhz for gatting clk */

		#if 1  // for darwin
		#if 0 //fix me later by ben wang
		  IoReg_Write32(CRT_SYS_PLL_DISP1_reg, 0x11023323);
		  IoReg_Write32(CRT_SYS_PLL_DISP2_VADDR, 0x00821001);
		  IoReg_Write32(CRT_SYS_DCLKSS_VADDR, 0x07930005);
		  #endif
		#else
	        IoReg_Write32(SYSTEM_PLL_DISP1_VADDR, 0x11012386);  // n = 0x23 div = 1  m = 110
	        IoReg_Write32(SYSTEM_PLL_DISP2_VADDR, 0x00000001);
	        IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, 0x07930005);
		#endif

		break;

		case PANEL_SXGA_1280x1024:
	        /* fix dclk 108Mhz for gatting clk */

		#if 1
		#if 0 //fix me later by ben wang
		IoReg_Write32(CRT_SYS_PLL_DISP1_reg, 0x18024323);
		 IoReg_Write32(CRT_SYS_PLL_DISP2_VADDR, 0x00821001);
		 IoReg_Write32(CRT_SYS_DCLKSS_VADDR, 0x09D90005);
		 #endif
		#else
	        IoReg_Write32(SYSTEM_PLL_DISP1_VADDR, 0x18012486);
	        IoReg_Write32(SYSTEM_PLL_DISP2_VADDR, 0x00000001);
	        IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, 0x09D90005);
		#endif


		break;

		case PANEL_HD1080_1920x1080:
	        /* fix dclk 148.5Mhz for gatting clk */

		#if 1
		#if 0 //fix me later by ben wang
		IoReg_Write32(CRT_SYS_PLL_DISP1_reg, 0x21024323);
	        IoReg_Write32(CRT_SYS_PLL_DISP2_VADDR, 0x00821001);
	        IoReg_Write32(CRT_SYS_DCLKSS_VADDR, 0x07B80005);
#endif
		#else
	        IoReg_Write32(SYSTEM_PLL_DISP1_VADDR, 0x21012486);
	        IoReg_Write32(SYSTEM_PLL_DISP2_VADDR, 0x00000001);
	        IoReg_Write32(SYSTEM_SYS_DCLKSS_VADDR, 0x07B80005);
		#endif

			break;

		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC,"%s :unknown panel type=%d\n", __FUNCTION__, panel_type);
			break;
	}
}

/**
 * This function is used to enable or disable the APLL power
 *
 * @param on_off: [input] you want to turn on or turn off the ADC.
 * @on_off: 0: Normal Run / 1: Power Down
 *
 * @return None
 *
 */
 void drvif_clock_apll_powercontrol(unsigned char on_off)
 {
	dds_pll_pll_ctrl_RBUS pll_ctrl_reg;
	// PLLPWDN (PLL Power Down)
	// 0: Normal Run
	// 1: Power Down

	if(_ENABLE == on_off)
	{

		#ifdef CONFIG_APLL_PROTECT
		pll_ctrl_reg.regValue  = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
		pll_ctrl_reg.pllswdrst = 1;
		IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);
		#endif

		pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
		pll_ctrl_reg.pllpwdn = 0;
		IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);

		#ifdef CONFIG_APLL_PROTECT
		msleep(1);
		pll_ctrl_reg.regValue  = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
		pll_ctrl_reg.pllswdrst = 0;
		IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);
		#endif
	}
	else// if(_DISABLE == on_off)
	{
		pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
		pll_ctrl_reg.pllpwdn = 1;
		IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);
	}
 }

/*======================== End of File =======================================*/
/**
*
* @}
*/

