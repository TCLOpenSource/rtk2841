/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for INTRA related functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version 	$Revision$
 */

/**
 * @addtogroup intra
 * @{
 */

/*============================ Module dependency  ===========================*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/vip/intra.h>
#else
//#include "rtd_regs.h"
//#include "auto_conf.h"
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>
#include <Platform_Lib/TVScalerControl/vip/intra.h>
#endif


/*===================================  Types ================================*/

/*================================== Variables ==============================*/

/*================================ Definitions ==============================*/



#if 0
 unsigned char  tINTRA_INIT[] = {
	0x04, 0x00, 0xff, 0x02,            /* select page 2*/
	/* source size*/
	0x04, 0x00, 0x00, 0xb0,
	0x04, 0x00, 0x01, 0xd0,
	0x04, 0x00, 0x02, 0xf0,
	/*0x04, 0x00, 0x03, 0x8a,*/
	/* intra control*/
	0x04, 0x00, 0x11, 0xbf,
	/* intra threshold*/
	0x04, 0x00, 0x5c, 0x40,
	0x04, 0x00, 0x5d, 0x32,
	0x04, 0x00, 0x5e, 0x28,
	0x04, 0x00, 0x5f, 0x0a,
	0x04, 0x00, 0x60, 0x0f,
	0x04, 0x00, 0x61, 0x0f,
	0x04, 0x00, 0x62, 0x02,
	0x04, 0x00,	0x63, 0x0a,
	0
  };
#endif
/*================================== Function ===============================*/
/*o----------------------------------------------------o*/
/*      INTRA_init						*/
/*      ==> to initialize the setting of Intra interpolation		*/
/*      @param  {none}					*/
/*      @return {none}					*/
/*o----------------------------------------------------o*/
void drvif_color_intra_init(void)
{

	drvif_color_intra_all_pacific_new_switch(1);

}

/*============================================================================*/

/*------------------------------------------------------*/
/*      Intra All New Function Switch				*/
/*      ==>  To disable / enable all new functions in Pacific	*/
/*      @param <enable> { 0 : disable				*/
/*                                    1 : enable }			*/
/*      @return {  0: fail					*/
/*                      1: success }				*/
/*------------------------------------------------------*/
unsigned char drvif_color_intra_all_pacific_new_switch(unsigned char enable)		/*Erin add API 090806*/
{
	di_im_di_intra_th_RBUS intra_th_Reg;

	if (enable != 1 && enable != 0)
		return 0;

	intra_th_Reg.regValue = IoReg_Read32(DI_IM_DI_INTRA_TH_reg);

	intra_th_Reg.intra_ma_mess_enable = enable;

	IoReg_Write32(DI_IM_DI_INTRA_TH_reg, intra_th_Reg.regValue);
	return 1;
}


/*--------------------------------------------------------------------------------------*/
/*      Intra for Ma Mess									*/
/*      ==>  Use up/down line discontinuity function2 smooth to determine using force 90 degree intra or intra when DI MA mess class.*/
/*      @param <enable> { 0 : disable								*/
/*                                    1 : enable }							*/
/*      @return {  0: fail									*/
/*                      1: success }								*/
/*--------------------------------------------------------------------------------------*/
unsigned char drvif_color_intra_for_ma_mess(unsigned char enable)		/*Erin add API 090806*/
{
	di_im_di_intra_th_RBUS intra_th_Reg;
	if (enable == 0x1 || enable == 0x0) {
		intra_th_Reg.regValue = IoReg_Read32(DI_IM_DI_INTRA_TH_reg);
		intra_th_Reg.intra_ma_mess_enable = enable;
		IoReg_Write32(DI_IM_DI_INTRA_TH_reg, intra_th_Reg.regValue);
		return 1;
	} else
		return 0;

}

void drvif_color_Intra_Ver2_table(DRV_Intra_Ver2_Table *ptr)
{
	if(!ptr)
		return;

	di_im_di_nintra_control_RBUS			di_im_di_nintra_control;
	di_im_di_nintra_lowpass_source_RBUS		di_im_di_nintra_lowpass_source;
	di_im_di_nintra_search_dir_limit_RBUS		di_im_di_nintra_search_dir_limit;
	di_im_di_nintra_intersection_th_RBUS		di_im_di_nintra_intersection_th;
	di_im_di_nintra_1st_2nd_ydiff_th_RBUS		di_im_di_nintra_1st_2nd_ydiff_th;
	di_im_di_nintra_high_freq_limit_RBUS		di_im_di_nintra_high_freq_limit;

	// chen 160602
	di_im_di_nintra_1st_2nd_ydiff_th_2_RBUS	di_im_di_nintra_1st_2nd_ydiff_th_2;
	// end chen 160602

	di_im_di_nintra_control.regValue					= IoReg_Read32(DI_IM_DI_NINTRA_CONTROL_reg);
	di_im_di_nintra_lowpass_source.regValue		= IoReg_Read32(DI_IM_DI_NINTRA_LOWPASS_SOURCE_reg);
	di_im_di_nintra_search_dir_limit.regValue	= IoReg_Read32(DI_IM_DI_NINTRA_SEARCH_DIR_LIMIT_reg);
	di_im_di_nintra_intersection_th.regValue	= IoReg_Read32(DI_IM_DI_NINTRA_INTERSECTION_TH_reg);
	di_im_di_nintra_1st_2nd_ydiff_th.regValue	= IoReg_Read32(DI_IM_DI_NINTRA_1ST_2ND_YDIFF_TH_reg);
	di_im_di_nintra_high_freq_limit.regValue	= IoReg_Read32(DI_IM_DI_NINTRA_HIGH_FREQ_LIMIT_reg);

	// chen 160602
	di_im_di_nintra_1st_2nd_ydiff_th_2.regValue		= IoReg_Read32(DI_IM_DI_NINTRA_1ST_2ND_YDIFF_TH_2_reg);
	// end chen 160602



	di_im_di_nintra_control.nintra_new_mode_en        				= ptr->Intra_Input.nintra_new_mode_en;
	di_im_di_nintra_control.nintra_src_lpf_clamp_en 					= ptr->Intra_Input.nintra_src_lpf_clamp_en;
	di_im_di_nintra_lowpass_source.nintra_lp_src_edge_th1  		= ptr->Intra_Input.nintra_lp_src_edge_th1;
	di_im_di_nintra_lowpass_source.nintra_lp_src_edge_th2  		= ptr->Intra_Input.nintra_lp_src_edge_th2;
	di_im_di_nintra_lowpass_source.nintra_lp_src_edge_slope		= ptr->Intra_Input.nintra_lp_src_edge_slope;
	di_im_di_nintra_lowpass_source.nintra_lp_src_yclamp_th 		= ptr->Intra_Input.nintra_lp_src_yclamp_th;


	di_im_di_nintra_control.nintra_ydiff_mode           			= ptr->Intra_Search_Range.nintra_ydiff_mode;
	di_im_di_nintra_control.nintra_vbound_detect_en     			= ptr->Intra_Search_Range.nintra_vbound_detect_en;
	di_im_di_nintra_control.nintra_search_min_limit_en  			= ptr->Intra_Search_Range.nintra_search_min_limit_en;
	di_im_di_nintra_control.nintra_high_freq_detect_en  			= ptr->Intra_Search_Range.nintra_high_freq_detect_en;
	di_im_di_nintra_search_dir_limit.nintra_hdiff_th1         = ptr->Intra_Search_Range.nintra_hdiff_th1;
	di_im_di_nintra_search_dir_limit.nintra_hdiff_th2         = ptr->Intra_Search_Range.nintra_hdiff_th2;
	di_im_di_nintra_high_freq_limit.nintra_hfq_hdiff_th       = ptr->Intra_Search_Range.nintra_hfq_hdiff_th;
	di_im_di_nintra_high_freq_limit.nintra_trans_count_th1    = ptr->Intra_Search_Range.nintra_trans_count_th1;
	di_im_di_nintra_high_freq_limit.nintra_trans_count_th2    = ptr->Intra_Search_Range.nintra_trans_count_th2;
	di_im_di_nintra_search_dir_limit.nintra_dir_search_region_max = ptr->Intra_Search_Range.nintra_dir_search_region_max;

	// chen 160602
	di_im_di_nintra_control.nintra_sr_minus_value          		=ptr->Intra_Search_Range.nintra_sr_minus_value;
	// end chen 160602


	di_im_di_nintra_control.nintra_intersection_check_en    	= ptr->Intra_direction_refine.nintra_intersection_check_en;
	di_im_di_nintra_control.nintra_dynamic_cross_th_en       	= ptr->Intra_direction_refine.nintra_dynamic_cross_th_en;
	di_im_di_nintra_intersection_th.nintra_slopediff_th       = ptr->Intra_direction_refine.nintra_slopediff_th;
	di_im_di_nintra_intersection_th.nintra_crossdiff_th       = ptr->Intra_direction_refine.nintra_crossdiff_th;
	di_im_di_nintra_intersection_th.nintra_crossslope_diff_th = ptr->Intra_direction_refine.nintra_crossslope_diff_th;
	di_im_di_nintra_control.nintra_min_second_dir_check_en   	= ptr->Intra_direction_refine.nintra_min_second_dir_check_en;
	di_im_di_nintra_control.nintra_min_second_dir_check2_en  	= ptr->Intra_direction_refine.nintra_min_second_dir_check2_en;
	di_im_di_nintra_1st_2nd_ydiff_th.nintra_minsecond_diff_th = ptr->Intra_direction_refine.nintra_minsecond_diff_th;
	di_im_di_nintra_1st_2nd_ydiff_th.nintra_minsecond_diff_th2 = ptr->Intra_direction_refine.nintra_minsecond_diff_th2;
	di_im_di_nintra_1st_2nd_ydiff_th.nintra_minsecond_diff_th3 = ptr->Intra_direction_refine.nintra_minsecond_diff_th3;
	di_im_di_nintra_1st_2nd_ydiff_th.nintra_vertical_diff_th  = ptr->Intra_direction_refine.nintra_vertical_diff_th;
	di_im_di_nintra_control.nintra_lowpass_dir_check_en      	= ptr->Intra_direction_refine.nintra_lowpass_dir_check_en;
	di_im_di_nintra_control.nintra_pre_dir_check_en          	= ptr->Intra_direction_refine.nintra_pre_dir_check_en;
	di_im_di_nintra_control.nintra_preline_dir_check1_en     	= ptr->Intra_direction_refine.nintra_preline_dir_check1_en;
	di_im_di_nintra_control.nintra_preline_dir_check2_en     	= ptr->Intra_direction_refine.nintra_preline_dir_check2_en;
	di_im_di_nintra_control.nintra_n_check2_control_disable  	= ptr->Intra_direction_refine.nintra_n_check2_control_disable;
	di_im_di_nintra_control.nintra_lowpass_dir_count_th      	= ptr->Intra_direction_refine.nintra_lowpass_dir_count_th;
	di_im_di_nintra_control.nintra_check2_y_diff_th          	= ptr->Intra_direction_refine.nintra_check2_y_diff_th;

	// chen 160602
	di_im_di_nintra_1st_2nd_ydiff_th_2.nintra_vertical_diff_th2  				=ptr->Intra_direction_refine.nintra_vertical_diff_th2;
	di_im_di_nintra_1st_2nd_ydiff_th_2.nintra_min_second_diff_th4      	=ptr->Intra_direction_refine.nintra_min_second_diff_th4;
	// end chen 160602




	di_im_di_nintra_control.nintra_dyn_dir_lowpass_en   			= ptr->Intra_Out.nintra_dyn_dir_lowpass_en;
	di_im_di_nintra_control.nintra_output_lowpass_en    			= ptr->Intra_Out.nintra_output_lowpass_en;
	di_im_di_nintra_control.nintra_ud_boundary_repeat_en			= ptr->Intra_Out.nintra_ud_boundary_repeat_en;


	IoReg_Write32(DI_IM_DI_NINTRA_CONTROL_reg, di_im_di_nintra_control.regValue);
	IoReg_Write32(DI_IM_DI_NINTRA_LOWPASS_SOURCE_reg, di_im_di_nintra_lowpass_source.regValue);
	IoReg_Write32(DI_IM_DI_NINTRA_SEARCH_DIR_LIMIT_reg, di_im_di_nintra_search_dir_limit.regValue);
	IoReg_Write32(DI_IM_DI_NINTRA_INTERSECTION_TH_reg, di_im_di_nintra_intersection_th.regValue);
	IoReg_Write32(DI_IM_DI_NINTRA_1ST_2ND_YDIFF_TH_reg, di_im_di_nintra_1st_2nd_ydiff_th.regValue);
	IoReg_Write32(DI_IM_DI_NINTRA_HIGH_FREQ_LIMIT_reg, di_im_di_nintra_high_freq_limit.regValue);


	// chen 160602
	IoReg_Write32(DI_IM_DI_NINTRA_1ST_2ND_YDIFF_TH_2_reg, di_im_di_nintra_1st_2nd_ydiff_th_2.regValue);
	// end chen 160602

}