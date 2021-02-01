/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for de-interlace IP control functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version 	$Revision$
 * @ingroup 	ip
 */

 /**
 * @addtogroup ip
 * @{
 */

/*================ Module dependency  =============== */
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/semaphore.h>



//#include "rtd_regs.h"
//#include "rtd_macro.h"
#include <rbus/di_reg.h> //no this file 20160603
//#include <rbus/scaler/dc_sys_reg.h>
//#include <rbusScaledownReg.h>
#include <rbus/vgip_reg.h>
#include <rbus/sub_vgip_reg.h>
#include <rbus/adc_reg.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/dds_pll_reg.h>
//#include <rbus/scaler/rbustv-sb2-dcu1reg.h>
//#include <rbus/scaler/rbusCRTReg.h>
//#include <rbus/crt_reg.h>	 //no this file 20160603
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/vodma_reg.h>
#include <rbus/timer_reg.h>//for timer counter
#include <scalercommon/scalerCommon.h>
#include <rbus/hsd_dither_reg.h>	 //no this file 20160603
#include <tvscalercontrol/io/ioregdrv.h>
//#include "libs/utils/rtSystem.h"
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scaler/scalervideo.h>
#include <tvscalercontrol/scalerdrv/scalerclock.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scalerdrv/pipmp.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/scalerdrv/scalerip.h>
#include <tvscalercontrol/hdmirx/hdmifun.h>
#if 1  //fixme:vip
#include <tvscalercontrol/vip/di_ma.h>
#include <tvscalercontrol/vip/film.h>
#include <tvscalercontrol/vip/di_ma.h>
#include <tvscalercontrol/vip/intra.h>
#include <tvscalercontrol/vip/xc.h>
#include <tvscalercontrol/vip/nr.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/vip/ultrazoom.h>

#endif
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/scalerdrv/scaler_2dcvt3d_ctrl.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>

//#include <tvscalercontrol/scaler/scalerLib.h>

//#include <tvscalercontrol/scaler/modeState.h"
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
#include "tvscalercontrol/scaler/scalervideo.h" //for fw_video_get_27mhz_mode()
#endif //#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
#include <../tvscalercontrol/scaler_vscdev.h>

/*======================== PRIVATE CONSTANTS =================================*/

/*======================== PRIVATE MACROS ====================================*/

/*======================== PRIVATE TYPES =====================================*/

/*==================== Variables ================= */
//static unsigned char force_reset_di_flag = FALSE;//Force to reset DI flag
static unsigned char DI_chroma_10bits_in = FALSE;
static unsigned char DI_Gamemode_EN = FALSE;

static unsigned char DI_wait_frame_num = 0;//we need to wait DI frame and let DI ready
static unsigned int record_timer_counter = 0;// record TIMER_SCPU_CLK90K_LO_reg when set DI

#ifdef CONFIG_I2RND_ENABLE
extern unsigned char vsc_i2rnd_sub_stage;
#endif


#define VO_FIXED_2K1K_HTOTAL 2480
#define VO_FIXED_4K2K_HTOTAL 4400
/*======================== PRIVATE FUNCTIONS =================================*/
/*============================================================================*/
/**
 * scalerip_bypass
 * Set whether channel enter IP or not
 *
 * @param <info> { display-info struecture }
 * @param <byPass> { enter/no enter }
 * @return { none }
 *
 */
static void scalerip_bypass(unsigned char byPass)
{
	vgip_data_path_select_RBUS data_path_select_reg;
	data_path_select_reg.regValue = IoReg_Read32(VGIP_Data_Path_Select_reg);
	if(byPass){ // bypass
		if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)){
#if 0
			if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (data_path_select_reg.uzd1_in_sel ==1))
				data_path_select_reg.uzd2_in_sel = 1;
			else if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (data_path_select_reg.uzd1_in_sel ==0))
				data_path_select_reg.uzd2_in_sel = 3;
			else
				data_path_select_reg.uzd2_in_sel = 0;
			IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
#endif
		}else{
			/* always on for snr hw issue, elieli*/
			if (drvif_color_Get_DRV_SNR_Clock(0) == 1) {
				drvif_color_Set_DRV_SNR_Clock(0);
				data_path_select_reg.uzd1_in_sel = 0;
				data_path_select_reg.di_i_clk_en = 0;
				IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
				drvif_color_Set_DRV_SNR_Clock(1);
			} else {
				data_path_select_reg.uzd1_in_sel = 0;
				data_path_select_reg.di_i_clk_en = 0;
				IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
			}
		}
	}else{
		if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)){
			//data_path_select_reg.xcdi_in_sel = 1;
			//data_path_select_reg.uzd2_in_sel = 1;
			IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
		}else{
			/* always on for snr hw issue, elieli*/
			if (drvif_color_Get_DRV_SNR_Clock(0) == 1) {
				drvif_color_Set_DRV_SNR_Clock(0);
				//data_path_select_reg.xcdi_in_sel = 0;
				data_path_select_reg.uzd1_in_sel = 1;
				IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
				drvif_color_Set_DRV_SNR_Clock(1);
			} else {
				//data_path_select_reg.xcdi_in_sel = 0;
				data_path_select_reg.uzd1_in_sel = 1;
				IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
			}
		}
	}

}

void sub_VGIP_sample_needDItiming(unsigned char bonoff)
{
	di_tr2to1_RBUS di_tr2to1_Reg;
	di_tr2to1_Reg.regValue = IoReg_Read32(DI_tr2to1_reg);

	if(bonoff == TRUE)
		di_tr2to1_Reg.tr2to1_dist = 8;
	else
		di_tr2to1_Reg.tr2to1_dist = 0;

	IoReg_Write32(DI_tr2to1_reg, di_tr2to1_Reg.regValue);
}

void scalerip_livezoom_updatesubmux(void)
{
	if (Get_Live_zoom_mode() == LIVE_ZOOM_OFF)
		return;

	vgip_data_path_select_RBUS data_path_select_reg;
	data_path_select_reg.regValue = IoReg_Read32(VGIP_Data_Path_Select_reg);
#if 0
	if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (data_path_select_reg.uzd1_in_sel ==1))
		data_path_select_reg.uzd2_in_sel = 1;
	else if ((Get_Live_zoom_mode() == LIVE_ZOOM_SUB) && (data_path_select_reg.uzd1_in_sel ==0))
		data_path_select_reg.uzd2_in_sel = 3;
	else
		data_path_select_reg.uzd2_in_sel = 0;
#endif
	IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
}
/*============================================================================*/
/**
 * Modify_DI_RdStart
 * Set DI-ReadStart
 *
 * @param <channel> { i domain- channel }
 * @param <di_f>	{ input source: interlace or progressive}
 * @param <rtnr_f>		{ project: RTNR on or off}
  * @param <hscaledown_f>		{ Horizontal Scale Down on or off }
 * @return { none }
 *
 */
static void scalerip_modify_rdstart(unsigned char channel, unsigned char di_f, unsigned char rtnr_f, unsigned char hscaledown_f)
{
	unsigned int hsd_act_large = 0, hsd_act_small = 0;
	di_im_di_debug_mode_RBUS reg_input_di_ctrl_REG;
	di_im_di_active_window_control_RBUS reg_active_window_REG;
	hsd_dither_di_hsd_scale_hor_factor_RBUS		di_hsd_scale_hor_factor_REG;
	hsd_dither_di_hsd_initial_value_RBUS			di_hsd_initial_value_REG;
	hsd_dither_di_hsd_hor_segment_RBUS			di_hsd_hor_segment_REG;
	hsd_dither_di_hsd_hor_delta1_RBUS			di_hsd_hor_delta1_REG;
	pr_debug("Into Modify_DI_RdStart()\n");
	pr_debug("channel=%d, di_f=%d, rtnr_f=%d, hscaledown_f=%d\n",channel,di_f,rtnr_f,hscaledown_f);
	if(rtnr_f)
	{
		if(!hscaledown_f)
			return;
	}
	else if( (!di_f) || (!hscaledown_f))
		return;


	//Elsie 20130308: Using hsd dither instead of UZD in Magellan
	if (channel == _CHANNEL1)
	{
		di_hsd_scale_hor_factor_REG.regValue 	= IoReg_Read32(HSD_DITHER_DI_HSD_Scale_Hor_Factor_reg);
		di_hsd_initial_value_REG.regValue		= IoReg_Read32(HSD_DITHER_DI_HSD_Initial_Value_reg);
		di_hsd_hor_segment_REG.regValue 		= IoReg_Read32(HSD_DITHER_DI_HSD_Hor_Segment_reg);
		di_hsd_hor_delta1_REG.regValue		= IoReg_Read32(HSD_DITHER_DI_HSD_Hor_Delta1_reg);
#if 0 //frank@0704 mark below code to solve some size will display fail problem to solve mantis#40619,43672
	if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) > 3840){//frank@0626 change below code to solve mantis#40619
		hsd_act_large = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);
	}else{
		hsd_act_large = 1+(((di_hsd_initial_value_REG.hor_ini << 12) + di_hsd_scale_hor_factor_REG.hor_fac *
		  (di_hsd_hor_segment_REG.nl_seg1 *2 + di_hsd_hor_segment_REG.nl_seg2) +
		  (di_hsd_hor_delta1_REG.nl_d1 * di_hsd_hor_segment_REG.nl_seg1) *
		  (di_hsd_hor_segment_REG.nl_seg1 + di_hsd_hor_segment_REG.nl_seg2) -
		  di_hsd_scale_hor_factor_REG.hor_fac)>>20);
	}
#else
		hsd_act_large = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);
#endif
		hsd_act_small = di_hsd_hor_segment_REG.nl_seg1 *2 + di_hsd_hor_segment_REG.nl_seg2;

	pr_debug("h_ini=%d, h_fac=%x, Seg1=%d, Seg2=%d, NL_D1=%d\n",di_hsd_initial_value_REG.hor_ini,
		di_hsd_scale_hor_factor_REG.hor_fac, di_hsd_hor_segment_REG.nl_seg1,
		di_hsd_hor_segment_REG.nl_seg2,	di_hsd_hor_delta1_REG.nl_d1);
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else
	{
		di_hsd_hor_segment_REG.regValue 		= IoReg_Read32(HSD_DITHER_DI_HSD_Hor_Segment_reg);

		hsd_act_large = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);//Thur added, recommended by Fishtail 20080423
		hsd_act_small = di_hsd_hor_segment_REG.nl_seg1 *2 + di_hsd_hor_segment_REG.nl_seg2;
	}
#endif


#if 0	//Old way
	if (channel == _CHANNEL1)
	{
		scaledown_ich1_uzd_Scale_Hor_Factor_RBUS		ich1_uzd_Scale_Hor_Factor_REG;
		scaledown_ich1_uzd_Initial_Value_RBUS			ich1_uzd_Initial_Value_REG;
		scaledown_ich1_uzd_Hor_Segment_RBUS		ich1_uzd_Hor_Segment_REG;
		scaledown_ich1_uzd_Hor_Delta1_RBUS			ich1_uzd_Hor_Delta1_REG;

		ich1_uzd_Scale_Hor_Factor_REG.regValue 	= IoReg_Read32(SCALEDOWN_ICH1_UZD_SCALE_HOR_FACTOR_VADDR);
		ich1_uzd_Initial_Value_REG.regValue		= IoReg_Read32(SCALEDOWN_ICH1_UZD_INITIAL_VALUE_VADDR);
		ich1_uzd_Hor_Segment_REG.regValue 		= IoReg_Read32(SCALEDOWN_ICH1_UZD_HOR_SEGMENT_VADDR);
		ich1_uzd_Hor_Delta1_REG.regValue		= IoReg_Read32(SCALEDOWN_ICH1_UZD_HOR_DELTA1_VADDR);

		hsd_act_large = 1+(((ich1_uzd_Initial_Value_REG.hor_ini << 12) + ich1_uzd_Scale_Hor_Factor_REG.hor_fac *
		  (ich1_uzd_Hor_Segment_REG.nl_seg1 *2 + ich1_uzd_Hor_Segment_REG.nl_seg2) +
		  (ich1_uzd_Hor_Delta1_REG.nl_d1 * ich1_uzd_Hor_Segment_REG.nl_seg1) *
		  (ich1_uzd_Hor_Segment_REG.nl_seg1 + ich1_uzd_Hor_Segment_REG.nl_seg2) -
		  ich1_uzd_Scale_Hor_Factor_REG.hor_fac)>>20);
		hsd_act_small = ich1_uzd_Hor_Segment_REG.nl_seg1 *2 + ich1_uzd_Hor_Segment_REG.nl_seg2;

	printk("h_ini=%d, h_fac=%x, Seg1=%d, Seg2=%d, NL_D1=%d\n",ich1_uzd_Initial_Value_REG.hor_ini,
		ich1_uzd_Scale_Hor_Factor_REG.hor_fac, ich1_uzd_Hor_Segment_REG.nl_seg1,
		ich1_uzd_Hor_Segment_REG.nl_seg2,	ich1_uzd_Hor_Delta1_REG.nl_d1);
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else
	{
		scaledown_ich2_uzd_H_Output_Size_RBUS		ich2_uzd_H_Output_Size_REG;
		scaledown_ich2_uzd_Scale_Hor_Factor_RBUS		ich2_uzd_Scale_Hor_Factor_REG;
		scaledown_ich2_uzd_Initial_Value_RBUS			ich2_uzd_Initial_Value_REG;

		ich2_uzd_H_Output_Size_REG.regValue	= IoReg_Read32(SCALEDOWN_ICH2_UZD_H_OUTPUT_SIZE_VADDR);
		ich2_uzd_Scale_Hor_Factor_REG.regValue	= IoReg_Read32(SCALEDOWN_ICH2_UZD_SCALE_HOR_FACTOR_VADDR);
		ich2_uzd_Initial_Value_REG.regValue		= IoReg_Read32(SCALEDOWN_ICH2_UZD_INITIAL_VALUE_VADDR);

		/*
		hsd_act_large = 1 + (((ich2_uzd_Initial_Value_REG.hor_ini << 12) +
		(ich2_uzd_Scale_Hor_Factor_REG.hor_fac * ich2_uzd_H_Output_Size_REG.h_output_size) -
			(ich2_uzd_Scale_Hor_Factor_REG.hor_fac)) >> 20);
		*/
		hsd_act_large = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);//Thur added, recommended by Fishtail 20080423
		hsd_act_small = ich2_uzd_H_Output_Size_REG.h_output_size;

	}
#endif
#endif

	reg_input_di_ctrl_REG.regValue = IoReg_Read32(DI_IM_DI_DEBUG_MODE_reg);
	reg_active_window_REG.regValue = IoReg_Read32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);

	// In 2D convert to 3D mode, need force to enable the scaling down IP even in/out picture horizontal size is 1:1
	// [WORKAROUND] set readstart to 2 in (hsd_act_large == hsd_act_small) case to avoid the picture offset error
	if(Get_PANEL_SCALER_2D_3D_CVT_HWSHIFT_ENABLE() && (hsd_act_large == hsd_act_small))
		reg_input_di_ctrl_REG.readstart = 2;
	else{
		unsigned int m_readstart = 0;

#if (CONFIG_ARCH_RTK284X)		
		m_readstart = hsd_act_large - hsd_act_small - 3;
#else
		m_readstart = hsd_act_large - hsd_act_small;
#endif
		#if 0
		if(m_readstart > 2047)
			m_readstart = 2047;
		#endif
		reg_input_di_ctrl_REG.readstart = m_readstart;		
	}
	reg_active_window_REG.hsize = hsd_act_small;

//	reg_active_window_REG.hblksize = Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) - hsd_act_small; // Blank;
	//for freeze framesync underflow case
	reg_active_window_REG.hblksize = 64;
//      reg_active_window_REG.hblksize = Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) - hsd_act_small; // Blank;
	IoReg_Write32(DI_IM_DI_DEBUG_MODE_reg, reg_input_di_ctrl_REG.regValue);
	IoReg_Write32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg, reg_active_window_REG.regValue);

	pr_debug("Modify_DI_readstart\n");
//	printk("ch=%d, readstart=%d, large=%d, small=%d\n",
//		Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), reg18061010_REG.readstart, hsd_act_large, hsd_act_small);
}

/*============================================================================*/
extern unsigned char get_sub_OutputVencMode(void);
#if 0
void set_di_doublebuf_write(unsigned char diflag,unsigned char _2d_flag)
{
	unsigned char timeout = 0, frame_count = 0, frame_num=0;
	//_2d_flag = 0; // 20140930 disable Force2D function in Mac3

	if(get_sub_OutputVencMode() == TRUE)
		IoReg_ClearBits(VGIP_VGIP_CHN1_CTRL_reg, _BIT24|_BIT25);
	else
		IoReg_ClearBits(VGIP_INT_CTL_reg, _BIT3); //avoid double buffer set fail, if i-domain isr usable
	if(diflag){
		//disable force 2d,enable ip with double buffer register
		//IoReg_SetBits(DI_db_reg_ctl_reg, _BIT0);
		IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, (diflag << 28));
		while(((IoReg_Read32(DI_IM_DI_CONTROL_reg) & _BIT28) >> 28) != diflag)
		{
			IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, (diflag << 28));
			msleep(1);//frank@0430 change busy delay to speed up boot time
			if(++timeout>60)	//30)
			{
				break;
			}
		}

		if (timeout > 60)	//30)
		{
			pr_debug("DI Write Double Buffer Write Error !!!!!!!!!!!!!!!!!!\n");
		}
		//IoReg_ClearBits(BUS_TV_SB2_DCU1_ARB_CR1_VADDR, _BIT0);
		// avoid DC_SYS2 client separate enable fail issue due to DI send zero write command to bus
		drv_memory_disable_di_write_req(TRUE);

		//msleep(40);

		IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~(_BIT19|_BIT20), (_2d_flag <<19)); //noicte: IoReg_Mask32 can't set _BIT19 & _BIT20 seperately

		timeout = 0;
		while((((IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg) & _BIT19) >> 19) != _2d_flag) ||
		   (((IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg) & _BIT20) >> 20) != 0))
		{
			IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~(_BIT19|_BIT20), (_2d_flag <<19));
			msleep(1);//frank@0430 change busy delay to speed up boot time
			if(++timeout>60)	//30)
			{
				break;
			}
		}

		//WaitFor_IVS1();
		//WaitFor_IVS1();

		//IoReg_SetBits(BUS_TV_SB2_DCU1_ARB_CR1_VADDR, _BIT0);
		// avoid DC_SYS2 client separate enable fail issue due to DI send zero write command to bus
		drv_memory_disable_di_write_req(FALSE);

		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_THRIP)) {
			if(((IoReg_Read32(DI_IM_DI_CONTROL_reg) & _BIT4) >> 4) == 1) {		// 3A
				frame_num = 3;
			} else {	// 5A
				frame_num = 5;
			}
		} else { //p
			frame_num = 2;
		}
		frame_count = 0;
		timeout = 0;
		while(frame_count < frame_num && timeout < 30) {
			WaitFor_IVS1();
			if(((IoReg_Read32(DI_IM_DI_DEBUG_MODE_reg) & _BIT8) >> 8) == 0){
				frame_count++;
			} else {
				frame_count = 0;
			}
			timeout++;
		}

	}else{
		//force 2D
		//disable  double buffer register
		//IoReg_ClearBits(DI_db_reg_ctl_reg, _BIT1|_BIT0);
		IoReg_ClearBits(DI_db_reg_ctl_reg, _BIT2);
			IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~(_BIT19|_BIT20), (_2d_flag <<19)); //noicte: IoReg_Mask32 can't set _BIT19 & _BIT20 seperately
 		while((((IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg) & _BIT19) >> 19) != _2d_flag) ||
		   (((IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg) & _BIT20) >> 20) != 0))
		{
			IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~(_BIT19|_BIT20), (_2d_flag <<19));
			msleep(1);//frank@0430 change busy delay to speed up boot time
			if(++timeout>60)	//30)
			{
				break;
			}
		}
		if (timeout > 60)	//30)
		{
			pr_debug("DI Write 2 Double Buffer Write Error !!!!!!!!!!!!!!!!!!\n");
		}
		//enable  double buffer register
		//IoReg_SetBits(DI_db_reg_ctl_reg, _BIT1);
		IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, (diflag << 28));
		//IoReg_SetBits(DI_db_reg_ctl_reg, _BIT0);

		//di disable
		timeout = 0;
		while(((IoReg_Read32(DI_IM_DI_CONTROL_reg) & _BIT28) >> 28) != diflag)
		{
			IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, (diflag << 28));
			msleep(1);//frank@0430 change busy delay to speed up boot time
			if(++timeout>60)	//30)
			{
				break;
			}
		}
		IoReg_SetBits(DI_db_reg_ctl_reg, _BIT2);
	}

	if(get_sub_OutputVencMode() == TRUE)
		IoReg_SetBits(VGIP_VGIP_CHN1_CTRL_reg, _BIT24|_BIT25);
	else
		IoReg_SetBits(VGIP_INT_CTL_reg, _BIT3);

//	printk("timeout count = %d\n",timeout);
	if (timeout > 60)	//30)
	{
		pr_debug("DI Double Buffer Write Error !!!!!!!!!!!!!!!!!!\n");
	}

}
#else
unsigned char set_di_doublebuf_write_TV006(unsigned char diflag,unsigned char _2d_flag)
{
	unsigned char timeout = 0, frame_count = 0, frame_num=0;

	di_im_di_control_RBUS di_im_di_control_reg;
	di_im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);

	//_2d_flag = 0; // 20140930 disable Force2D function in Mac3
	if(get_sub_OutputVencMode() == TRUE)
		IoReg_ClearBits(VGIP_VGIP_CHN1_CTRL_reg, _BIT24|_BIT25);
	else
		IoReg_ClearBits(VGIP_INT_CTL_reg, _BIT3); //avoid double buffer set fail, if i-domain isr usable

	if(diflag){
		//disable force 2d,enable ip with double buffer register
		//IoReg_SetBits(DI_db_reg_ctl_reg, _BIT0);
		//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, (diflag << 28));
		//while(((IoReg_Read32(DI_IM_DI_CONTROL_reg) & _BIT28) >> 28) != diflag)
		di_im_di_control_reg.ip_enable=diflag;
		di_im_di_control_reg.write_enable_8=1;
		IoReg_Write32(DI_IM_DI_CONTROL_reg, di_im_di_control_reg.regValue);
		di_im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
		while(di_im_di_control_reg.ip_enable != diflag)
		{
			//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, (diflag << 28));
			di_im_di_control_reg.ip_enable=diflag;
			di_im_di_control_reg.write_enable_8=1;
			IoReg_Write32(DI_IM_DI_CONTROL_reg, di_im_di_control_reg.regValue);
			msleep(1);//frank@0430 change busy delay to speed up boot time
			if(++timeout>60)	//30)
			{
				break;
			}
		}

		if (timeout > 60)	//30)
		{
			pr_debug("DI Write Double Buffer Write Error !!!!!!!!!!!!!!!!!!\n");
		}
		//IoReg_ClearBits(BUS_TV_SB2_DCU1_ARB_CR1_VADDR, _BIT0);
		// avoid DC_SYS2 client separate enable fail issue due to DI send zero write command to bus
		drv_memory_disable_di_write_req(TRUE);

		//msleep(40);

		IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~(_BIT19|_BIT20), (_2d_flag <<19)); //noicte: IoReg_Mask32 can't set _BIT19 & _BIT20 seperately

		timeout = 0;
		while((((IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg) & _BIT19) >> 19) != _2d_flag) ||
		   (((IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg) & _BIT20) >> 20) != 0))
		{
			IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~(_BIT19|_BIT20), (_2d_flag <<19));
			msleep(1);//frank@0430 change busy delay to speed up boot time
			if(++timeout>60)	//30)
			{
				break;
			}
		}

		//WaitFor_IVS1();
		//WaitFor_IVS1();

		//IoReg_SetBits(BUS_TV_SB2_DCU1_ARB_CR1_VADDR, _BIT0);
		// avoid DC_SYS2 client separate enable fail issue due to DI send zero write command to bus
		drv_memory_disable_di_write_req(FALSE);

		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_THRIP)) {
			if(((IoReg_Read32(DI_IM_DI_CONTROL_reg) & _BIT4) >> 4) == 1) {		// 3A
				frame_num = 3;
			} else {	// 5A
				frame_num = 5;
			}
		} else { //p
			frame_num = 2;
		}
		#if 0
		frame_count = 0;
		timeout = 0;
		while(frame_count < frame_num && timeout < 30) {
			WaitFor_IVS1();
			if(((IoReg_Read32(DI_IM_DI_DEBUG_MODE_reg) & _BIT8) >> 8) == 0){
				frame_count++;
			} else {
				frame_count = 0;
			}
			timeout++;
		}
		#endif
	}else{
		//force 2D
		//disable  double buffer register
		//IoReg_ClearBits(DI_db_reg_ctl_reg, _BIT1|_BIT0);
		IoReg_ClearBits(DI_db_reg_ctl_reg, _BIT2);
			IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~(_BIT19|_BIT20), (_2d_flag <<19)); //noicte: IoReg_Mask32 can't set _BIT19 & _BIT20 seperately
 		while((((IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg) & _BIT19) >> 19) != _2d_flag) ||
		   (((IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg) & _BIT20) >> 20) != 0))
		{
			IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~(_BIT19|_BIT20), (_2d_flag <<19));
			msleep(1);//frank@0430 change busy delay to speed up boot time
			if(++timeout>60)	//30)
			{
				break;
			}
		}
		if (timeout > 60)	//30)
		{
			pr_debug("DI Write 2 Double Buffer Write Error !!!!!!!!!!!!!!!!!!\n");
		}
		//enable  double buffer register
		//IoReg_SetBits(DI_db_reg_ctl_reg, _BIT1);
		//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, (diflag << 28));
		//IoReg_SetBits(DI_db_reg_ctl_reg, _BIT0);

		di_im_di_control_reg.ip_enable=diflag;
		di_im_di_control_reg.write_enable_8=1;
		IoReg_Write32(DI_IM_DI_CONTROL_reg, di_im_di_control_reg.regValue);
		di_im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);

		//di disable
		timeout = 0;
		//while(((IoReg_Read32(DI_IM_DI_CONTROL_reg) & _BIT28) >> 28) != diflag)
		while(di_im_di_control_reg.ip_enable != diflag)
		{
			//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, (diflag << 28));
			di_im_di_control_reg.ip_enable=diflag;
			di_im_di_control_reg.write_enable_8=1;
			IoReg_Write32(DI_IM_DI_CONTROL_reg, di_im_di_control_reg.regValue);
			msleep(1);//frank@0430 change busy delay to speed up boot time
			if(++timeout>60)	//30)
			{
				break;
			}
		}
		IoReg_SetBits(DI_db_reg_ctl_reg, _BIT2);
	}

	if(get_sub_OutputVencMode() == TRUE)
		IoReg_SetBits(VGIP_VGIP_CHN1_CTRL_reg, _BIT24|_BIT25);
	else
		IoReg_SetBits(VGIP_INT_CTL_reg, _BIT3);


//	printk("timeout count = %d\n",timeout);
	if (timeout > 60)	//30)
	{
		pr_debug("DI Double Buffer Write Error !!!!!!!!!!!!!!!!!!\n");
	}
	record_timer_counter = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg);//record current 90k counter
	DI_wait_frame_num = frame_num;//record need wait frame number
	return frame_num;
}
#endif

extern unsigned char vsc_get_adaptivestream_flag(void);
/*============================================================================*/
/**
 * fw_scalerip_set_di
 * Set IP (video process) registers, includes its memory setting
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
void fw_scalerip_set_di(void)
{
	unsigned short temp;
	unsigned char m_3DDIFlag = 0;
	unsigned char diflag = 0;
	unsigned char input_src_type;
	unsigned char input_src_form;
	vgip_data_path_select_RBUS data_path_select_reg;
	di_im_di_active_window_control_RBUS	 reg_Active_Win_di_Reg;
	di_im_di_weave_window_control_RBUS im_di_weave_window_control_reg;
	di_color_recovery_option_RBUS Color_Recovery_Option_Reg;
	vgip_vgip_chn1_ctrl_RBUS vgip_chn1_ctrl_reg;
	vgip_vgip_chn1_misc_RBUS vgip_chn1_misc_reg;
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	sub_vgip_vgip_chn2_misc_RBUS vgip_chn2_misc_reg;
	sub_vgip_vgip_chn2_ctrl_RBUS vgip_chn2_ctrl_reg;
#endif

	di_im_di_control_RBUS im_di_control_reg;


//	vp9_ctrl0_RBUS vodma_vp9_ctrl0_reg;
	//frank@1008 add below code to enable DI apply default
	di_db_reg_ctl_RBUS di_db_reg_ctl_reg;
	di_db_reg_ctl_reg.regValue = IoReg_Read32(DI_db_reg_ctl_reg);
#ifdef CONFIG_I2RND_ENABLE
	if(Scaler_I2rnd_get_enable())
		di_db_reg_ctl_reg.db_en = 0;	//i2rnd do not enable double buffer
#endif
	di_db_reg_ctl_reg.db_apply = 1;
	IoReg_Write32(DI_db_reg_ctl_reg, di_db_reg_ctl_reg.regValue);

	unsigned short display = Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	if (fwif_color_get_force_run_i3ddma_enable(display)) {
		fwif_color_vsc_to_scaler_src_mapping(Get_DisplayMode_Src(display), &input_src_type, &input_src_form);
	}else{
		input_src_type = Scaler_InputSrcGetMainChType();
	}

	if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP) || Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_RTNR)) {	// will added in future
		// disable exSRAM access mux (Let DI run correctly)
 		//IoReg_ClearBits(EXSRAM_CTRL_reg, _BIT0);
		// DI 8 or 10 bits by LearnRPG

		Color_Recovery_Option_Reg.regValue = IoReg_Read32(DI_Color_Recovery_Option_reg);
		if (fw_scalerip_get_DI_chroma_10bits()) {
			Color_Recovery_Option_Reg.y10bitsin = 1;
			Color_Recovery_Option_Reg.c10bitsin= 1;
		} else {
			Color_Recovery_Option_Reg.y10bitsin = 0;
			Color_Recovery_Option_Reg.c10bitsin= 0;
		}
		IoReg_Write32(DI_Color_Recovery_Option_reg, Color_Recovery_Option_Reg.regValue);
		// END

		drvif_scaler_vactive_end_irq(_DISABLE, display);//disable VGIP ISR (for automa)
		drvif_scaler_vactive_sta_irq(_DISABLE, display);//disable VGIP ISR (for automa)

	        //forster modified 071122
		if (Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display) == _SRC_FROM_ADC) {
			IoReg_Mask32(DDS_PLL_PLL_CTRL_reg, ~(_BIT9 | _BIT10), _BIT9 | _BIT10);
#if 1 //def CONFIG_VGA_JUMP_PHASE_SOLVED
			IoReg_SetBits(ADC_ADC_CLOCK_reg, _BIT21); // 1x ADC clock invert
#endif
			pr_debug("\n Set dual ADC clock%c",'!');
		}
		//frank@0514 move this position let force 2d and disable DI double buffer register work
		IoReg_SetBits(VGIP_Data_Path_Select_reg, _BIT3);

		// Disable IP temp
		//frank@0312 mark below code to change doublebuf_write to confirm DI disable to solve mantis#40113
		set_di_doublebuf_write_TV006(0, 1);

#if 0
		// [Code Sync][LewisLee][0990226][1]
		if(_CHANNEL2 == Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))
		{
			data_path_select_reg.regValue = IoReg_Read32(VGIP_Data_Path_Select_reg);
			data_path_select_reg.uzd2_in_sel = _ENABLE;
			data_path_select_reg.xcdi_in_sel = _CHANNEL2;
			IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
		}
		// [Code Sync][LewisLee][0990226][1][End]
#endif
		if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP)) {
			//if(Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID) >= 960) {	 //motion adaptive 3A
			// VO source in SG@120Hz 3D platform
			// [3D FRC] (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 288)  // bandwidth issue when video timing > 576i FRC mode (+5 for overscan margin)
#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
				if(VD_27M_HSD960_DI5A == fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)display))
				{
//					if(Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID) >= 960)
					if((Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID) > 960)
						||fw_scalerip_get_di_gamemode())
					{	//sync from pacific
						drv_memory_set_ip_fifo(0);
						IoReg_ClearBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
						im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
						im_di_control_reg.ma_3aenable = 1;
						im_di_control_reg.write_enable_1 = 1;
						IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);
						//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, _BIT4);
						Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_MA3A,TRUE);
						//printk("\nDI 3A\n");
					}
					else //motion adaptive 5A or 3A
					{	// 5A
						drv_memory_set_ip_fifo(1);
						IoReg_SetBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
						im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
						im_di_control_reg.ma_3aenable = 0;
						im_di_control_reg.write_enable_1 = 1;
						IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);
						//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, 0);
						Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_MA3A,FALSE);
						//printk("\nDI 5A\n");
					}
				}
				else// if(VD_27M_HSD960_DI5A != fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)display))
				{
					if(((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE())  && (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF_CVT_2D)&&(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 288))
						|| (Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE() && modestate_I3DDMA_get_In3dMode() && (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE) && (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 288))
						/*((Scaler_InputSrcGetMainChType() == _SRC_VO) && (GET_IS3DFMT() == 0 && GET_HDMI_3DTYPE() == HDMI3D_FRAMESEQUENCE) && (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > (288+5)))*/
						||((input_src_type == _SRC_VO)&&((vsc_get_adaptivestream_flag())||(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>960)))
						||((input_src_type == _SRC_HDMI)&&(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>960))
						||((input_src_type == _SRC_YPBPR)&&(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>960))
						||((input_src_type == _SRC_VGA)&&(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>960))
						||fw_scalerip_get_di_gamemode())
					{	//sync from pacific
						drv_memory_set_ip_fifo(0);
						IoReg_ClearBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
						im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
						im_di_control_reg.ma_3aenable = 1;
						im_di_control_reg.write_enable_1 = 1;
						IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);
						//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, _BIT4);
						Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_MA3A,TRUE);
						//printk("\nDI 3A\n");
					}
					else //motion adaptive 5A or 3A
					{	// 5A
						drv_memory_set_ip_fifo(1);
						IoReg_SetBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
						im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
						im_di_control_reg.ma_3aenable = 0;
						im_di_control_reg.write_enable_1 = 1;
						IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);
						//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, 0);
						Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_MA3A,FALSE);
						//When enter 5A mode, HW need more stable time @Crixus 20151204
						if(input_src_type == _SRC_HDMI)
							msleep(100);
						//printk("\nDI 5A\n");
					}
				}
#else //#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
				if(((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE())  && (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF_CVT_2D)&&(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 288))
					/*((Scaler_InputSrcGetMainChType() == _SRC_VO) && (GET_IS3DFMT() == 0 && GET_HDMI_3DTYPE() == HDMI3D_FRAMESEQUENCE) && (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > (288+5)))*/
					|| (Get_PANEL_3D_SG_OUTPUT_120HZ_ENABLE() && modestate_I3DDMA_get_In3dMode() && (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) == FALSE) && (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 288))
					||((input_src_type == _SRC_VO)&&((vsc_get_adaptivestream_flag())||(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>960)))
					||((input_src_type == _SRC_HDMI)&&(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>960))
					||((input_src_type == _SRC_YPBPR)&&(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>960))
					||((input_src_type == _SRC_VGA)&&(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>960))
					||fw_scalerip_get_di_gamemode())
			{   //sync from pacific
				drv_memory_set_ip_fifo(0);
				IoReg_ClearBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
				im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
				im_di_control_reg.ma_3aenable = 1;
				im_di_control_reg.write_enable_1 = 1;
				IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);
				//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, _BIT4);
				Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_MA3A,TRUE);
				//printk("\nSet DI Memory Main 3A\n");
			}
				else //motion adaptive 5A or 3A
				{	// 5A
				drv_memory_set_ip_fifo(1);
				IoReg_SetBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
				im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
				im_di_control_reg.ma_3aenable = 0;
				im_di_control_reg.write_enable_1 = 1;
				IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);
				//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, 0);
				Scaler_DispSetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_MA3A,FALSE);
				//printk("\nSet DI Memory Main 5A\n");
			}
#endif //#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
		}
		else {
			drv_memory_set_ip_fifo(2);
			IoReg_ClearBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
			im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
			im_di_control_reg.ma_3aenable = 0;
			im_di_control_reg.write_enable_1 = 1;
			IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);
			//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, 0);//20080610 weihauo for progressive, jaosn9.ccc
			//printk("\nSet RTNR Memory\n");
		}

		//frank@0311 Open vodma film mode control
		if (Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display) == _SRC_FROM_VO)
			IoReg_SetBits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT7);
		else
			IoReg_ClearBits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT7);

		//enable 3ddi//Frank@0514 move to front od set di to set 2D DI and disable DI
		//IoReg_SetBits(VGIP_Data_Path_Select_reg, _BIT3);

		pr_debug("3A,5A reg=%x\n",IoReg_Read32(DI_IM_DI_CONTROL_reg));

		//frank@04262010 add below code avoid 3ddi write data to the address 0 let code haneg ++
		//frank@0817 sync LV to speed up switch channel
		//fw_scaler_double_buffer_maskl((SCALER_DISP_CHANNEL)display,DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);
		// IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);
		m_3DDIFlag = 0;
		//frank@04262010 add below code avoid 3ddi write data to the address 0 let code haneg --
		if(/*Scaler_PipGetInfo(SLR_PIP_ENABLE) && */((display == SLR_MAIN_DISPLAY) && ((Scaler_InputSrcGetType(SLR_MAIN_DISPLAY) == _SRC_VGA) &&  ((Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR) == _MODE_1080I25) || (Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR) == _MODE_1080I30))))) {
#ifdef CONFIG_1080I_THROUGH_FRAMESYNC
			if ((Scaler_PipGetInfo(SLR_PIP_TYPE)>=SUBTYPE_PIPMLSR)&&(Scaler_PipGetInfo(SLR_PIP_TYPE)<=SUBTYPE_PIPMLSR_4x3))
			{
				//frank@0817 sync LV to speed up switch channel
				//fw_scaler_double_buffer_maskl((SCALER_DISP_CHANNEL)display,DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);  // 2D DI
				// IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);  // 2D DI
				//frank@0414 free DI memory to avoid memory overlay of main and sub channel
				drvif_memory_free_block(MEMIDX_DI);
				Scaler_DispSetStatus(SLR_MAIN_DISPLAY,SLR_DISP_RTNR,FALSE);
			}
			else
				m_3DDIFlag = 1;
#else
			// IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);  // 2D DI
			//frank@0414 free DI memory to avoid memory overlay of main and sub channel
			drvif_memory_free_block(MEMIDX_DI);
			Scaler_DispSetStatus(SLR_MAIN_DISPLAY,SLR_DISP_RTNR,FALSE);
#endif
		}
	#if 0
 		else if(Scaler_TVGetScanMode()) {
			// IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);
			Scaler_DispSetStatus(SLR_MAIN_DISPLAY,SLR_DISP_RTNR,FALSE);
		}
	#endif
		else if(display == SLR_SUB_DISPLAY) {
			if((((input_src_type == _SRC_HDMI || input_src_type == _SRC_DISPLAYPORT)||(Scaler_InputSrcGetMainChFrom() == _SRC_FROM_ADC)||(Scaler_InputSrcGetMainChFrom() == _SRC_FROM_VO))&&
				((Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR) >= _MODE_1080I25) && (Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR) <= _MODE_1080I30)) ) ||
			    ((input_src_type == _SRC_HDMI || input_src_type == _SRC_DISPLAYPORT) && drvif_Hdmi_GetInterlace() && (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) >=0x06F0))){
				// fw_scaler_double_buffer_maskl((SCALER_DISP_CHANNEL)display,DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);
				//frank@0414 free DI memory to avoid memory overlay of main and sub channel
				drvif_memory_free_block(MEMIDX_DI);
			}else{
				m_3DDIFlag = 1;
			}
		} else {
			if(Scaler_InputSrcGetType(display) == _SRC_VO) {
				if(vbe_disp_get_adaptivestream_fs_mode()==1)  {
					if( (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>3000) &&
					    (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>310))
						m_3DDIFlag = 0;//4k2k50,4k2k60
					else
						m_3DDIFlag = 1; // 3D DI
				}
				else
					m_3DDIFlag = 1; // 3D DI
			} else {
				m_3DDIFlag = 1; // 3D DI
			}
		}

		drvif_scaler_vactive_end_irq(_ENABLE, display);//disable VGIP ISR (for automa)
		drvif_scaler_vactive_sta_irq(_ENABLE, display);//disable VGIP ISR (for automa)



				// Decide whether enable delete 4 line (Up 2 line and down 2 line) and calculate line
		if(fwif_scaler_decide_display_cut4line(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)))
		{
			im_di_weave_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);
			im_di_weave_window_control_reg.dellineen = _ENABLE;
			IoReg_Write32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, im_di_weave_window_control_reg.regValue);
		}
		else
		{
			im_di_weave_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);
			im_di_weave_window_control_reg.dellineen = _DISABLE;
			IoReg_Write32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, im_di_weave_window_control_reg.regValue);
		}

		// Set active size to normalizing size in order to avoid to conflict
		reg_Active_Win_di_Reg.regValue = IoReg_Read32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);
		reg_Active_Win_di_Reg.hsize = Scaler_DispGetInputInfo(SLR_INPUT_DI_WID);// Width;
//#ifdef CONFIG_SDNR_CROP
//		reg_Active_Win_di_Reg.vsize = Scaler_DispGetInputInfo(SLR_INPUT_DI_LEN); // Height;
//#else
		reg_Active_Win_di_Reg.vsize = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN); // Height;
//#endif		
		reg_Active_Win_di_Reg.hblksize = Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) - Scaler_DispGetInputInfo(SLR_INPUT_DI_WID); // Blank;
		IoReg_Write32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg, reg_Active_Win_di_Reg.regValue);

		//frank@0418 add below code for 4k2k input size ++//frank@0503 reset hsize_msb/vsize_msb/hblksize_msb avoid image noise
		im_di_weave_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);
		if(Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)>0x7FF){
			im_di_weave_window_control_reg.hsize_msb= (Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)>>11);
		}else{
			im_di_weave_window_control_reg.hsize_msb= 0;
		}
//#ifdef CONFIG_SDNR_CROP
//		if(Scaler_DispGetInputInfo(SLR_INPUT_DI_LEN)>0x3FF){
//			im_di_weave_window_control_reg.vsize_msb= (Scaler_DispGetInputInfo(SLR_INPUT_DI_LEN)>>10);
//		}else{
//			im_di_weave_window_control_reg.vsize_msb= 0;
//		}
//#else
		if(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)>0x3FF){
			im_di_weave_window_control_reg.vsize_msb= (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)>>10);
		}else{
			im_di_weave_window_control_reg.vsize_msb= 0;
		}
//#endif
		if((Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) - Scaler_DispGetInputInfo(SLR_INPUT_DI_WID))>0x3FF){
			im_di_weave_window_control_reg.hblksize_msb = ((Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) - Scaler_DispGetInputInfo(SLR_INPUT_DI_WID))>>10);
		}else{
			im_di_weave_window_control_reg.hblksize_msb = 0;
		}
		IoReg_Write32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, im_di_weave_window_control_reg.regValue);
		//frank@0418 add below code for 4k2k input size --

	//	if (!Scaler_Get_DisplayRatio_Change_Flag())
		{
		//fix me:vip
		#if 1
			#if 0
			drvif_module_film_init(display);
			#else
			Scaler_SetFilm_Setting();
			#endif
			drvif_color_intra_init();
			drvif_color_ma_init();
			drvif_color_auto_bal_init(display,Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP));//20090907 jason9.ccc add
		#endif
		}


		if(display == _CHANNEL1)
		{
			vgip_chn1_ctrl_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg);
			if(vgip_chn1_ctrl_reg.ch1_digital_mode) //digital mode need to set porch
			{
				vgip_chn1_misc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_MISC_reg);
				if(Scaler_InputSrcGetType(display) == _SRC_VO){
					if ((vsc_get_adaptivestream_flag())&& ((Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) == VO_FIXED_4K2K_HTOTAL) ||(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) == VO_FIXED_2K1K_HTOTAL)))
					{
						vgip_chn1_misc_reg.ch1_hporch_num = 520;
					}
					else if(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) > (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) + VGIP_H_PORCH_MARGIN)){
						vgip_chn1_misc_reg.ch1_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) - Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) - VGIP_H_PORCH_MARGIN;
					}
					else{
						vgip_chn1_misc_reg.ch1_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
						pr_debug("The H total porch is not enough!!!!\n");
					}
				}
				else//hdmi case
					vgip_chn1_misc_reg.ch1_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
				IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);
			}
			else//analog mode
			{
				vgip_chn1_misc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_MISC_reg);
				vgip_chn1_misc_reg.ch1_hporch_num = 0;
				IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);
			}
		}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		else
		{

			vgip_chn2_ctrl_reg.regValue = IoReg_Read32(SUB_VGIP_VGIP_CHN2_CTRL_reg);
			if(vgip_chn2_ctrl_reg.ch2_digital_mode)
			{
				vgip_chn2_misc_reg.regValue = IoReg_Read32(SUB_VGIP_VGIP_CHN2_MISC_reg);
				if(Scaler_InputSrcGetType(display) == _SRC_VO)
					vgip_chn2_misc_reg.ch2_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE) + 4;
				else//hdmi case
					vgip_chn2_misc_reg.ch2_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
				IoReg_Write32(SUB_VGIP_VGIP_CHN2_MISC_reg, vgip_chn2_misc_reg.regValue);

			}
			else
			{
				vgip_chn2_misc_reg.regValue = IoReg_Read32(SUB_VGIP_VGIP_CHN2_MISC_reg);
				vgip_chn2_misc_reg.ch2_hporch_num = 0;
				IoReg_Write32(SUB_VGIP_VGIP_CHN2_MISC_reg, vgip_chn2_misc_reg.regValue);
			}
		}
#endif


		// Di read start must be set if turn on horizontal UZD
//		scalerip_modify_rdstart();
		scalerip_modify_rdstart(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP),Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_RTNR),Scaler_Get_di_hsd_flag());


		// no matter RTNR flag, must check progressive mode again. by LearnRPG
		drvif_color_rtnr_progressive_check(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_THRIP),Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));

#ifndef CONFIG_FIRMWARE_IN_KERNEL
		if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_RTNR)) {//20080609 jason9.ccc add for RTNR
		//fix me:vip
		#if 0
			fwif_color_RTNR_flow((Manual_NR_TABLE+ Scaler_GetDNR_table()*DRV_NR_Level_MAX + Scaler_GetDNR()));
		#endif
			di_im_di_rtnr_new_control_RBUS rtnr_new_Ctrl;
			rtnr_new_Ctrl.regValue = IoReg_Read32(DI_IM_DI_RTNR_CONTROL_reg);
			if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)>1920){
				rtnr_new_Ctrl.prtnr_4k2k = 0x1;
			}else{
				rtnr_new_Ctrl.prtnr_4k2k = 0x0;
			}
			IoReg_Write32(DI_IM_DI_RTNR_CONTROL_reg, rtnr_new_Ctrl.regValue);
		}
		else
		{
		//fix me:vip
		#if 0
			fwif_color_RTNR_flow((Manual_NR_TABLE+ Scaler_GetDNR_table()*DRV_NR_Level_MAX + DRV_NR_OFF));
		#endif
		}
#endif
		diflag = 1;  // set di

		set_di_doublebuf_write_TV006(diflag, !m_3DDIFlag);

		if(_CHANNEL1 == display)
		{
			/* always on for snr hw issue, elieli*/
			if (drvif_color_Get_DRV_SNR_Clock(0) == 1) {
				drvif_color_Set_DRV_SNR_Clock(0);
				data_path_select_reg.regValue = IoReg_Read32(VGIP_Data_Path_Select_reg);
				data_path_select_reg.uzd1_in_sel = _ENABLE;
				//data_path_select_reg.xcdi_in_sel = _CHANNEL1;
	            		data_path_select_reg.di_i_clk_en = _ENABLE;
				data_path_select_reg.xcdi_clk_en = _ENABLE;//Enable clock. Will Add 20151218
				IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
				drvif_color_Set_DRV_SNR_Clock(1);
			} else {
				data_path_select_reg.regValue = IoReg_Read32(VGIP_Data_Path_Select_reg);
				data_path_select_reg.uzd1_in_sel = _ENABLE;
				//data_path_select_reg.xcdi_in_sel = _CHANNEL1;
	            		data_path_select_reg.di_i_clk_en = _ENABLE;
				data_path_select_reg.xcdi_clk_en = _ENABLE;//Enable clock. Will Add 20151218
				IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);
			}
		}

	}
	else {
#ifdef CONFIG_VGIP_DIGITAL_MODE
		if(display == _CHANNEL1)
		{
			vgip_chn1_ctrl_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg);
			if(vgip_chn1_ctrl_reg.ch1_digital_mode)
			{
				vgip_chn1_misc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_MISC_reg);

				if(Scaler_InputSrcGetType(display) == _SRC_VO){
					if ((vsc_get_adaptivestream_flag())&& ((Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) == VO_FIXED_4K2K_HTOTAL) ||(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) == VO_FIXED_2K1K_HTOTAL)))
					{
						vgip_chn1_misc_reg.ch1_hporch_num = 520;
					}
 					else if(Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) > (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) + VGIP_H_PORCH_MARGIN)){
						vgip_chn1_misc_reg.ch1_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_H_LEN) - Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) - VGIP_H_PORCH_MARGIN;
					}
					else{
						vgip_chn1_misc_reg.ch1_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
						pr_debug("The H total porch is not enough!!!!\n");
					}
				}
				else//hdmi case
					vgip_chn1_misc_reg.ch1_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
				IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);
			}
			else
			{
				vgip_chn1_misc_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_MISC_reg);
				vgip_chn1_misc_reg.ch1_hporch_num = 0;
				IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc_reg.regValue);
			}
		}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		else
		{
			vgip_chn2_ctrl_reg.regValue = IoReg_Read32(SUB_VGIP_VGIP_CHN2_CTRL_reg);
			if(vgip_chn2_ctrl_reg.ch2_digital_mode)
			{
				vgip_chn2_misc_reg.regValue = IoReg_Read32(SUB_VGIP_VGIP_CHN2_MISC_reg);
				if(Scaler_InputSrcGetType(display) == _SRC_VO)
					vgip_chn2_misc_reg.ch2_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE) + 4;
				else//hdmi case
					vgip_chn2_misc_reg.ch2_hporch_num = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE);
				IoReg_Write32(SUB_VGIP_VGIP_CHN2_MISC_reg, vgip_chn2_misc_reg.regValue);
			}
			else
			{
				vgip_chn2_misc_reg.regValue = IoReg_Read32(SUB_VGIP_VGIP_CHN2_MISC_reg);
				vgip_chn2_misc_reg.ch2_hporch_num = 0;
				IoReg_Write32(SUB_VGIP_VGIP_CHN2_MISC_reg, vgip_chn2_misc_reg.regValue);
			}
		}
#endif
#endif//CONFIG_VGIP_DIGITAL_MODE

		if(display == SLR_MAIN_DISPLAY) {
			//  if sub enters DI/RTNR, do not close DI
				if(!(/*Scaler_PipGetInfo(SLR_PIP_ENABLE)&&*/(Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_THRIP)||Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_RTNR)))) {
					//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, 0); //chengying mark set by double buffer
					diflag = 0;
					//frank@0514 move this position let force 2d and disable DI double buffer register work
					IoReg_SetBits(VGIP_Data_Path_Select_reg, _BIT3);
					set_di_doublebuf_write_TV006(diflag, !m_3DDIFlag);
				}
        }
		scalerip_bypass(TRUE);
		pr_debug("display: %x, Not Enter DI \n", display);
	}


	di_db_reg_ctl_reg.regValue = IoReg_Read32(DI_db_reg_ctl_reg);
	di_db_reg_ctl_reg.db_apply = 1;
	IoReg_Write32(DI_db_reg_ctl_reg, di_db_reg_ctl_reg.regValue);
}


//not close rtnr
void fw_scalerip_disable_onlyip(UINT8 display)
{


	drvif_scaler_vactive_end_irq(_DISABLE, display);//disable VGIP interrupt (for auto ma)
	drvif_scaler_vactive_sta_irq(_DISABLE, display);//disable VGIP interrupt (for auto ma)
	#if 0 // Use table base
	drvif_color_ma_auto_init(); // reset auto ma
	#else
	//fix me:vip
	//Scaler_SetMADI_INIT();
	#endif

	IoReg_BusyCheckRegBit(PPOVERLAY_DTG_pending_status_reg, _BIT0,0x1FFFF);

	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)== _CHANNEL1)
		IoReg_ClearBits(VGIP_Data_Path_Select_reg, _BIT10);
	else
		IoReg_ClearBits(VGIP_Data_Path_Select_reg, _BIT8);

	// Close IP enable
	di_im_di_control_RBUS im_di_control_reg;
	im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	im_di_control_reg.ip_enable= 0;
	im_di_control_reg.write_enable_8 = 1;
	IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);
	//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, 0);

	//frank@0518 add for disable RTNR

	drvif_memory_free_block(MEMIDX_DI);
}



void fw_scalerip_disable_ip(unsigned char display)
{
	 //USER:LewisLee DATE:2014/02/07
        //When Disable DI, need reset Di chroma error
        //to prevent Vsync not correvt
     //fix me:vip
	//Scaler_SetMA_Chroma_Error(0);
	di_im_new_mcnr_control_RBUS	di_im_new_mcnr_control;
	di_db_reg_ctl_RBUS	di_db_reg_ctl_reg;

	drvif_scaler_vactive_end_irq(_DISABLE, display);//disable VGIP interrupt (for auto ma)
	drvif_scaler_vactive_sta_irq(_DISABLE, display);//disable VGIP interrupt (for auto ma)
	#if 0 // Use table base
	drvif_color_ma_auto_init(); // reset auto ma
	#else
	//fix me:vip
	//Scaler_SetMADI_INIT();
	#endif

//frank@1103 mark to reduce time
	//IoReg_BusyCheckRegBit(PPOVERLAY_DTG_pending_status_reg, _BIT0,0x1FFFF);

	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)== _CHANNEL1)
		IoReg_ClearBits(VGIP_Data_Path_Select_reg, _BIT10);
	else
		IoReg_ClearBits(VGIP_Data_Path_Select_reg, _BIT8);

	di_im_new_mcnr_control.regValue	= IoReg_Read32(DI_IM_DI_RTNR_HMCNR_reg);
	di_im_new_mcnr_control.n_mcnr_new_en = 0;
	IoReg_Write32(DI_IM_DI_RTNR_HMCNR_reg, di_im_new_mcnr_control.regValue);

        //frank@1016[KTASKWBS-1860]When not enter smooth toggle flow, need set below control bit 1
	di_db_reg_ctl_reg.regValue = IoReg_Read32(DI_db_reg_ctl_reg);
	di_db_reg_ctl_reg.sm_tog_apply_disable = 1;
	IoReg_Write32(DI_db_reg_ctl_reg, di_db_reg_ctl_reg.regValue);

	// Close IP enable
	di_im_di_control_RBUS im_di_control_reg;
	im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	im_di_control_reg.ip_enable= 0;
	im_di_control_reg.write_enable_8 = 1;
	IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);

	//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, 0);
//fix me:vip
#if 0
	//frank@0518 add for disable RTNR
	drvif_color_rtnr_off(display);
#endif
	drvif_memory_free_block(MEMIDX_DI);
}


#if 0
/*============================================================================*/
/**
* fw_scalerip_set_di_for_MaincvtSub
* Set IP (video process) registers, includes its memory setting for MaincvtSub conversion mode
*
* @param <info> { display-info struecture }
* @return { none }
*
*/

void fw_scalerip_set_di_for_MaincvtSub(unsigned char diEnable, unsigned char rtnrEnable)
{
	unsigned short temp;
	unsigned char m_3DDIFlag = 0;
	unsigned char diflag = 0;
	vgip_data_path_select_RBUS data_path_select_reg;
	di_im_di_active_window_control_RBUS	 reg_Active_Win_di_Reg;
	di_im_di_weave_window_control_RBUS im_di_weave_window_control_reg;
	unsigned short vgip2Display = SLR_MAIN_DISPLAY;
	unsigned short vgip2Channel = _CHANNEL2;
	unsigned char srcFrom = scaler_MaincvtSub_get_vgip2SrcFrom();
	unsigned int vgip2Height = scaler_MaincvtSub_get_vgip2IvHeight();
	unsigned int dispIHCount = scaler_MaincvtSub_get_vgip2IhCount();
	unsigned int vgip2Width =scaler_MaincvtSub_get_vgip2IhWidth();

	if (diEnable) {	// will added in future
		// DI 8 or 10 bits by LearnRPG
		di_color_recovery_option_RBUS Color_Recovery_Option_Reg;
		Color_Recovery_Option_Reg.regValue = IoReg_Read32(DI_Color_Recovery_Option_reg);
		if(fw_scalerip_get_DI_chroma_10bits())
		{
			Color_Recovery_Option_Reg.y10bitsin = 1;
			if(fw_scalerip_get_DI_chroma_10bits())
				Color_Recovery_Option_Reg.c10bitsin= 1;
			else
				Color_Recovery_Option_Reg.c10bitsin= 0;
		}
		else
		{
			Color_Recovery_Option_Reg.y10bitsin = 0;
			Color_Recovery_Option_Reg.c10bitsin= 0;
		}
		IoReg_Write32(DI_Color_Recovery_Option_reg, Color_Recovery_Option_Reg.regValue);
		// END

		// move to modestate_set_display_on()
		drvif_scaler_vactive_end_irq(_DISABLE, vgip2Channel);//disable VGIP ISR (for automa)
		drvif_scaler_vactive_sta_irq(_DISABLE, vgip2Channel);//disable VGIP ISR (for automa)
	        //forster modified 071122
		if (srcFrom == _SRC_FROM_ADC) {
			IoReg_Mask32(DDS_PLL_PLL_CTRL_VADDR, ~(_BIT9 | _BIT10), _BIT9 | _BIT10);

  			IoReg_SetBits(ADC_ADC_CLOCK_VADDR, _BIT21); // 1x ADC clock invert

			printk("\n [2D3D] Set dual ADC clock%c",'!');
		}

		// Disable IP temp
		//frank@0817 sync LV to speed up switch channel
		//fw_scaler_double_buffer_maskl((SCALER_DISP_CHANNEL)display, DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);
		//fw_scaler_double_buffer_maskl((SCALER_DISP_CHANNEL)display,DI_IM_DI_CONTROL_reg, ~_BIT28, 0);
		//IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);
		//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, 0);
		IoReg_SetBits(VGIP_Data_Path_Select_reg, _BIT3);

		set_di_doublebuf_write(0, 1);


		data_path_select_reg.regValue = IoReg_Read32(VGIP_Data_Path_Select_reg);
		data_path_select_reg.uzd2_in_sel = _ENABLE;
		data_path_select_reg.xcdi_in_sel = _CHANNEL2;
		IoReg_Write32(VGIP_Data_Path_Select_reg, data_path_select_reg.regValue);


		if(diEnable) {
			//if(Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID) >= 960) {	 //motion adaptive 3A
			if(vgip2Width >= 960) {   //sync from pacific
				drv_memory_set_ip_fifo(0);
				IoReg_ClearBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
				IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, _BIT4);
				Scaler_DispSetStatus((SCALER_DISP_CHANNEL)vgip2Display,SLR_DISP_MA3A,TRUE);
				printk("\n[2D3D] Set DI Memory Main 3A(w=%d)\n", vgip2Width);
			}
			else {   //motion adaptive 5A or 3A
				// 5A
				drv_memory_set_ip_fifo(1);
				IoReg_SetBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
				IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, 0);
				Scaler_DispSetStatus((SCALER_DISP_CHANNEL)vgip2Display,SLR_DISP_MA3A,FALSE);
				printk("\n[2D3D] Set DI Memory Main 5A(w=%d)\n", vgip2Width);
			}
		}
		else {
			drv_memory_set_ip_fifo(2);
			IoReg_ClearBits(DI_IM_DI_BTR_CONTROL_reg, _BIT9);
			IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT4, 0);//20080610 weihauo for progressive, jaosn9.ccc
			printk("\n[2D3D] Set RTNR Memory\n");
		}

		IoReg_ClearBits(DI_IM_DI_MPEG_SEQUENCE_APP_reg, _BIT7);

		//enable 3ddi
		//IoReg_SetBits(VGIP_Data_Path_Select_reg, _BIT3);

		printk("[2D3D] 1...3A,5A condition :force 3A=%x\n",IoReg_Read32(DI_IM_DI_CONTROL_reg));

		//frank@04262010 add below code avoid 3ddi write data to the address 0 let code haneg ++
		//frank@0817 sync LV to speed up switch channel
		//fw_scaler_double_buffer_maskl((SCALER_DISP_CHANNEL)display,DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);
		// IoReg_Mask32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, ~_BIT19, _BIT19);

		m_3DDIFlag = 1; // 3D DI
		//frank@0924 Diable DI arbitrator avoid enable 3D DI let system hang
		//if(m_3DDIFlag)
			//IoReg_ClearBits(BUS_TV_SB2_DCU2_ARB_CR1_VADDR, _BIT0);

		drvif_scaler_vactive_end_irq(_ENABLE, vgip2Channel);//disable VGIP ISR (for automa)
		drvif_scaler_vactive_sta_irq(_ENABLE, vgip2Channel);//disable VGIP ISR (for automa)

		// disable delete 4 line (Up 2 line and down 2 line) and calculate line

		im_di_weave_window_control_reg.regValue = IoReg_Read32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg);
		im_di_weave_window_control_reg.dellineen = _DISABLE;
		IoReg_Write32(DI_IM_DI_WEAVE_WINDOW_CONTROL_reg, im_di_weave_window_control_reg.regValue);

		// Set active size to normalizing size in order to avoid to conflict
		reg_Active_Win_di_Reg.regValue = IoReg_Read32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg);
		reg_Active_Win_di_Reg.hsize = vgip2Width;// Width;
		reg_Active_Win_di_Reg.vsize = vgip2Height; // Height;
		reg_Active_Win_di_Reg.hblksize = dispIHCount - reg_Active_Win_di_Reg.hsize; // Blank;
		IoReg_Write32(DI_IM_DI_ACTIVE_WINDOW_CONTROL_reg, reg_Active_Win_di_Reg.regValue);

		#if 0
		drvif_module_film_init(vgip2Display);
		#else
		Scaler_SetFilm_Setting();
		#endif

		drvif_color_intra_init();
		drvif_color_ma_init();
		drvif_color_auto_bal_init(vgip2Display, diEnable);//20090907 jason9.ccc add
		temp = (dispIHCount -vgip2Width)/8;

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		IoReg_Mask32(SUB_VGIP_VGIP_CHN2_MISC_reg , 0xfff000ff, (temp & 0x00000fff) << 8);
#endif

		// Di read start must be set if turn on horizontal UZD

		scalerip_modify_rdstart(vgip2Channel, diEnable, rtnrEnable, FALSE);//scaler_2Dcvt3D_get_vgip2InHoriDecMode());

		// no matter RTNR flag, must check progressive mode again. by LearnRPG
		drvif_color_rtnr_progressive_check(diEnable, vgip2Channel);

		if(rtnrEnable) {//20080609 jason9.ccc add for RTNR
			drvif_color_rtnr_init(vgip2Channel);
		}
		else
			drvif_color_rtnr_off(vgip2Channel);

		diflag = 1;  // set di

		set_di_doublebuf_write(diflag, !m_3DDIFlag);

		//frank@0924 Enable DI arbitrator avoid enable 3D DI let system hang
		//if(m_3DDIFlag)
			//IoReg_ClearBits(BUS_TV_SB2_DCU2_ARB_CR1_VADDR, _BIT0);
	}
	else {
		set_di_doublebuf_write(FALSE, TRUE);
		IoReg_ClearBits(VGIP_Data_Path_Select_reg, _BIT8);
		//printk("[2D3D] display: %x, Not Enter DI \n", vgip2Display);
	}
}
#endif
//Elsie 20140117
/*============================================================================*/
/**
* fw_scalerip_set_DI_chroma_10bits
* Turn on/off DI chroma 10-bit input
*
* @param <isEnable> { TRUE: enable DI chroma 10-bit input, FALSE: disable }
* @return { none }
*
*/
extern unsigned char get_AVD_Input_Source(void);
void fw_scalerip_set_DI_chroma_10bits(unsigned char isEnable)
{
	DI_chroma_10bits_in = isEnable;
}

/*============================================================================*/
/**
* fw_scalerip_set_DI_chroma_10bits
* Get whether DI chroma 10-bit input is turned on
*
* @param <none>
* @return { DI_chroma_10bits_in } { TRUE: DI chroma 10-bit input is enabled, FALSE: DI chroma 10-bit input is disabled }
*
*/
unsigned char fw_scalerip_get_DI_chroma_10bits(void)
{
	return DI_chroma_10bits_in;
}
/*
void drvif_color_rtnr_progressive_check(unsigned char interlace_flag, unsigned char channel)
{

//Set RTNR Progressive mode:
	di_im_di_rtnr_control_RBUS RecursiveTemporalNRCtrl_reg;
	RecursiveTemporalNRCtrl_reg.regValue = IoReg_Read32(DI_IM_DI_RTNR_CONTROL_VADDR);

	//frank@0518 mark this to avoid sub channel into DI fail
	//if( channel==_CHANNEL1)
	{
		if(!interlace_flag)
			RecursiveTemporalNRCtrl_reg.cp_rtnr_progressive = 0x1;
		else
			RecursiveTemporalNRCtrl_reg.cp_rtnr_progressive = 0x0;

		IoReg_Write32( DI_IM_DI_RTNR_CONTROL_VADDR,RecursiveTemporalNRCtrl_reg.regValue);
	}

}
*/
void fw_scalerip_set_di_gamemode_setting(unsigned char isEnable)
{
	di_color_recovery_option_RBUS Color_Recovery_Option_Reg;
	unsigned char source=255;

	source = fwif_vip_source_check(3, 0);

	Color_Recovery_Option_Reg.regValue = IoReg_Read32(DI_Color_Recovery_Option_reg);
	if((isEnable == 1)&&(source != VIP_QUALITY_CVBS_SECAN)) {
	       Color_Recovery_Option_Reg.game_mode_3a = 1;
	} else {
	       Color_Recovery_Option_Reg.game_mode_3a = 0;
	}

	IoReg_Write32(DI_Color_Recovery_Option_reg, Color_Recovery_Option_Reg.regValue);
}



void fw_scalerip_set_di_gamemode(unsigned char isEnable)
{
	DI_Gamemode_EN = isEnable;
}

unsigned char fw_scalerip_get_di_gamemode(void)
{
	unsigned char source=255;
	source = fwif_vip_source_check(3, 0);

	/*livezoom and magnifier not support single buffer mode*/
	if(/*(Get_LivezoomOffMainForceBG() == TRUE) ||*/ (Get_Live_zoom_mode()!=LIVE_ZOOM_OFF)) {
		return FALSE;
	}

	/*factory self diagnosis grab pixel from third buffer,so not support single buffer mode*/
	if(Get_Factory_SelfDiagnosis_Mode()) {
		return FALSE;
	}
	/*Only support HDMI and Component*/
//	if((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_AVD) && (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_ADC) && (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) != VSC_INPUTSRC_HDMI))
	if(!((Get_DisplayMode_Src(SLR_MAIN_DISPLAY)==VSC_INPUTSRC_ADC)||(Get_DisplayMode_Src(SLR_MAIN_DISPLAY)==VSC_INPUTSRC_HDMI)||((Get_DisplayMode_Src(SLR_MAIN_DISPLAY)==VSC_INPUTSRC_AVD)&&(get_AVD_Input_Source()!=_SRC_TV)&&(source != VIP_QUALITY_CVBS_SECAN))))

		return FALSE;

	return DI_Gamemode_EN;
}

/*======================== End of File =======================================*/

void check_di_buffer_mode(void)
{//This is for whether DI mode setting is worng. If wrong, recover the right setting. Recover API

	di_im_di_control_RBUS im_di_control_reg;
	im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	unsigned char DI_3a_flag = im_di_control_reg.ma_3aenable;

	if(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_THRIP))
	{
		IoReg_ClearBits(DI_db_reg_ctl_reg, _BIT2);//Let read value be HW setting
		im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
		if(im_di_control_reg.ma_3aenable != DI_3a_flag)
		{
			pr_notice("\r\n#####DI buffer mode need recover(%d)####\r\n", DI_3a_flag);
			down(get_DI_semaphore());
			if(DI_3a_flag) {
				im_di_control_reg.ma_3aenable = 1;
				im_di_control_reg.write_enable_1 = 1;
				IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);

			} else {
				im_di_control_reg.ma_3aenable = 0;
				im_di_control_reg.write_enable_1 = 1;
				IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);

			}
			up(get_DI_semaphore());
		}
		IoReg_SetBits(DI_db_reg_ctl_reg, _BIT2);//Let read value be rbus setting
	}
}

void fw_scalerip_set_di_size_change_hw_detect(unsigned char enable)
{
	//DI default size setting for sub start address sample issue @Crixus 20160725
	di_i2r_db_reg_ctl_RBUS di_i2r_db_reg_ctl_reg;
	di_i2r_db_reg_ctl_reg.regValue = IoReg_Read32(DI_i2r_db_reg_ctl_reg);
	di_i2r_db_reg_ctl_reg.reg_sm_size_change_hw_detect_en = enable;
	IoReg_Write32(DI_i2r_db_reg_ctl_reg, di_i2r_db_reg_ctl_reg.regValue);
}


void set_di_wait_frame_num(unsigned char num)
{
	DI_wait_frame_num = num;
}


void wait_DI_ready(void)
{//this api is for wait DI buffer ready
	unsigned int cur_counter;
	unsigned int need_time, vfreq;
	unsigned char timeout = 10;

	if(DI_wait_frame_num != 0)
	{
		vfreq = Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ);
		if(vfreq)
			need_time = 900000 * DI_wait_frame_num / vfreq;
		else
		{
			pr_err("\r\n#####func:%s err frame rate zero####\r\n", __FUNCTION__);
			return;
		}

		pr_notice("\r\n###func:%s ori:0x%x needwait num:%d time:0x%x#####\r\n", __FUNCTION__, record_timer_counter, DI_wait_frame_num, need_time);

		while(timeout)
		{
			cur_counter = IoReg_Read32(TIMER_SCPU_CLK90K_LO_reg);
			if(cur_counter < record_timer_counter)
			{
				if((cur_counter + (0xFFFFFFFF - record_timer_counter)) >= need_time)
					break;
			}
			else if ((cur_counter - record_timer_counter) >= need_time)
					break;
			msleep(10);
			timeout --;
		}
		if(!timeout)
			pr_err("\r\n#####func:%s err wait timeout#####\r\n", __FUNCTION__);
	}
}
/**
  * @}
  */


