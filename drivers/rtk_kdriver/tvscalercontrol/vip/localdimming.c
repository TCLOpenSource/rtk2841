/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2014
  * All rights reserved.
  * ========================================================================*/
  /*================= File Description =======================================*/
  /**
   * @file
   *  This file is for FILM related functions.
   *
   * @author  $Author$
   * @date	  $Date$
   * @version	  $Revision$
   */

  /**
   * @addtogroup film
   * @{
   */

  /*============================ Module dependency	===========================*/

#if CONFIG_FIRMWARE_IN_KERNEL
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/vip/localdimming.h>
#include <tvscalercontrol/scaler/vipinclude.h> /* for typedef that used in VIP_reg_def.h*/
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <mach/io.h>
#include <mach/rtk_log.h>
#define TAG_NAME "VPQ"
#else

#include <unistd.h>			// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "Platform_Lib/TVScalerControl/vip/localdimming.h"
#include <Platform_Lib/TVScalerControl/scaler/vipInclude.h> // for typedef that used in VIP_reg_def.h
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
#include <tvscalercontrol/vip/scalerColor.h>

#include "rbusLDSPIReg.h"
#endif
#define LocalDimming_Debug 0

#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ##args)//printk(KERN_DEBUG fmt, ##args)
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#endif

//static unsigned char localDimmingFullSet = 0;


/* Function Description : This function is for LD enable*/
void drvif_color_set_LD_Enable(unsigned char enable)
{
	blu_ld_global_ctrl2_RBUS blu_ld_global_ctrl2;
	blu_ld_global_ctrl2.regValue = IoReg_Read32(BLU_LD_Global_Ctrl2_reg);

	blu_ld_global_ctrl2.ld_valid = enable;

	#ifdef LocalDimming_Debug
	VIPprintf("ld_valid = %d\n", blu_ld_global_ctrl2.ld_valid);
	#endif

	IoReg_Write32(BLU_LD_Global_Ctrl2_reg, blu_ld_global_ctrl2.regValue);

}

unsigned char drvif_color_get_LD_Enable(void)
{
	blu_ld_global_ctrl2_RBUS blu_ld_global_ctrl2;
	blu_ld_global_ctrl2.regValue = IoReg_Read32(BLU_LD_Global_Ctrl2_reg);
	rtd_printk(KERN_INFO, TAG_NAME, "get_LD_Enable=%d\n",blu_ld_global_ctrl2.ld_valid);

	return blu_ld_global_ctrl2.ld_valid;
}

void drvif_color_set_LD_Global_Ctrl(DRV_LD_Global_Ctrl *ptr)
{
	blu_ld_global_ctrl0_RBUS blu_ld_global_ctrl0;
	blu_ld_global_ctrl1_RBUS blu_ld_global_ctrl1;
	blu_ld_global_ctrl2_RBUS blu_ld_global_ctrl2;
	blu_ld_global_ctrl3_RBUS blu_ld_global_ctrl3;

	blu_ld_global_ctrl0.regValue = IoReg_Read32(BLU_LD_Global_Ctrl0_reg);
	blu_ld_global_ctrl1.regValue = IoReg_Read32(BLU_LD_Global_Ctrl1_reg);
	blu_ld_global_ctrl2.regValue = IoReg_Read32(BLU_LD_Global_Ctrl2_reg);
	blu_ld_global_ctrl3.regValue = IoReg_Read32(BLU_LD_Global_Ctrl3_reg);


	blu_ld_global_ctrl1.ld_db_en = ptr->ld_db_en;
	blu_ld_global_ctrl1.ld_db_read_level = ptr->ld_db_read_level;
	IoReg_Write32(BLU_LD_Global_Ctrl1_reg, blu_ld_global_ctrl1.regValue);

	blu_ld_global_ctrl2.ld_3d_mode = ptr->ld_3d_mode;
	blu_ld_global_ctrl2.ld_blk_hnum = ptr->ld_blk_hnum;
	blu_ld_global_ctrl2.ld_blk_vnum = ptr->ld_blk_vnum;
	blu_ld_global_ctrl2.ld_subblk_mode = ptr->ld_subblk_mode;
	blu_ld_global_ctrl2.ld_gdim_mode = ptr->ld_gdim_mode;
	blu_ld_global_ctrl2.ld_blk_type = ptr->ld_blk_type;
	blu_ld_global_ctrl2.ld_hist_mode = ptr->ld_hist_mode;
	blu_ld_global_ctrl2.ld_tenable = ptr->ld_tenable;
	blu_ld_global_ctrl2.ld_valid = ptr->ld_valid;
	blu_ld_global_ctrl3.ld_blk_hsize = ptr->ld_blk_hsize;
	blu_ld_global_ctrl3.ld_blk_vsize = ptr->ld_blk_vsize;

	IoReg_Write32(BLU_LD_Global_Ctrl2_reg, blu_ld_global_ctrl2.regValue);
	IoReg_Write32(BLU_LD_Global_Ctrl3_reg, blu_ld_global_ctrl3.regValue);

	blu_ld_global_ctrl0.ld_comp_en = ptr->ld_comp_en;
	IoReg_Write32(BLU_LD_Global_Ctrl0_reg, blu_ld_global_ctrl0.regValue);
	blu_ld_global_ctrl1.ld_db_apply = 1;
	IoReg_Write32(BLU_LD_Global_Ctrl1_reg, blu_ld_global_ctrl1.regValue);

}



void drvif_color_set_LD_Backlight_Decision(DRV_LD_Backlight_Decision *ptr)
{
	blu_ld_decision_ctrl1_RBUS blu_ld_decision_ctrl1;
	blu_ld_decision_ctrl2_RBUS blu_ld_decision_ctrl2;
	blu_ld_decision_ctrl3_RBUS blu_ld_decision_ctrl3;

	blu_ld_decision_ctrl1.regValue = IoReg_Read32(BLU_LD_Decision_Ctrl1_reg);
	blu_ld_decision_ctrl2.regValue = IoReg_Read32(BLU_LD_Decision_Ctrl2_reg);
	blu_ld_decision_ctrl3.regValue = IoReg_Read32(BLU_LD_Decision_Ctrl3_reg);

	blu_ld_decision_ctrl1.ld_maxgain = ptr->ld_maxgain;
	blu_ld_decision_ctrl1.ld_avegain = ptr->ld_avegain;
	blu_ld_decision_ctrl1.ld_histshiftbit = ptr->ld_histshiftbit;
	blu_ld_decision_ctrl2.ld_hist0gain = ptr->ld_hist0gain;
	blu_ld_decision_ctrl2.ld_hist1gain = ptr->ld_hist1gain;
	blu_ld_decision_ctrl2.ld_hist2gain = ptr->ld_hist2gain;
	blu_ld_decision_ctrl2.ld_hist3gain = ptr->ld_hist3gain;
	blu_ld_decision_ctrl3.ld_hist4gain = ptr->ld_hist4gain;
	blu_ld_decision_ctrl3.ld_hist5gain = ptr->ld_hist5gain;
	blu_ld_decision_ctrl3.ld_hist6gain = ptr->ld_hist6gain;
	blu_ld_decision_ctrl3.ld_hist7gain = ptr->ld_hist7gain;


	IoReg_Write32(BLU_LD_Decision_Ctrl1_reg, blu_ld_decision_ctrl1.regValue);
	IoReg_Write32(BLU_LD_Decision_Ctrl2_reg, blu_ld_decision_ctrl2.regValue);
	IoReg_Write32(BLU_LD_Decision_Ctrl3_reg, blu_ld_decision_ctrl3.regValue);

}

void drvif_color_set_LD_Spatial_Filter(DRV_LD_Spatial_Filter *ptr)
{
	blu_ld_spatial_ctrl1_RBUS blu_ld_spatial_ctrl1;
	blu_ld_spatial_ctrl2_RBUS blu_ld_spatial_ctrl2;
	blu_ld_spatial_ctrl5_RBUS blu_ld_spatial_ctrl5;
	blu_ld_spatial_ctrl6_RBUS blu_ld_spatial_ctrl6;
	blu_ld_spatial_ctrl7_RBUS blu_ld_spatial_ctrl7;
	blu_ld_spatial_ctrl8_RBUS blu_ld_spatial_ctrl8;
	blu_ld_spatial_ctrl9_RBUS blu_ld_spatial_ctrl9;
	blu_ld_spatial_ctrla_RBUS blu_ld_spatial_ctrla;

	blu_ld_spatial_ctrl1.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl1_reg);
	blu_ld_spatial_ctrl2.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl2_reg);
	blu_ld_spatial_ctrl5.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl5_reg);
	blu_ld_spatial_ctrl6.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl6_reg);
	blu_ld_spatial_ctrl7.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl7_reg);
	blu_ld_spatial_ctrl8.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl8_reg);
	blu_ld_spatial_ctrl9.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl9_reg);
	blu_ld_spatial_ctrla.regValue = IoReg_Read32(BLU_LD_Spatial_CtrlA_reg);

	blu_ld_spatial_ctrl1.ld_spatialcoef0 = ptr->ld_spatialcoef0;
	blu_ld_spatial_ctrl1.ld_spatialcoef1 = ptr->ld_spatialcoef1;
	blu_ld_spatial_ctrl1.ld_spatialcoef2 = ptr->ld_spatialcoef2;
	blu_ld_spatial_ctrl1.ld_spatialcoef3 = ptr->ld_spatialcoef3;
	blu_ld_spatial_ctrl1.ld_spatialcoef4 = ptr->ld_spatialcoef4;
	blu_ld_spatial_ctrl1.ld_spatialcoef5 = ptr->ld_spatialcoef5;
	blu_ld_spatial_ctrl1.ld_spatialcoef6 = ptr->ld_spatialcoef6;
	blu_ld_spatial_ctrl1.ld_spatialcoef7 = ptr->ld_spatialcoef7;
	blu_ld_spatial_ctrl2.ld_spatialcoef8 = ptr->ld_spatialcoef8;
	blu_ld_spatial_ctrl2.ld_spatialcoef9 = ptr->ld_spatialcoef9;
	blu_ld_spatial_ctrl2.ld_spatialcoef10 = ptr->ld_spatialcoef10;
	blu_ld_spatial_ctrl5.spatial_new_mode = ptr->spatial_new_mode;
	blu_ld_spatial_ctrl5.ld_spatialnewcoef00 = ptr->ld_spatialnewcoef00;
	blu_ld_spatial_ctrl5.ld_spatialnewcoef01 = ptr->ld_spatialnewcoef01;
	blu_ld_spatial_ctrl5.ld_spatialnewcoef02 = ptr->ld_spatialnewcoef02;
	blu_ld_spatial_ctrl5.ld_spatialnewcoef03 = ptr->ld_spatialnewcoef03;
	blu_ld_spatial_ctrl5.ld_spatialnewcoef04 = ptr->ld_spatialnewcoef04;
	blu_ld_spatial_ctrl6.ld_spatialnewcoef10 = ptr->ld_spatialnewcoef10;
	blu_ld_spatial_ctrl6.ld_spatialnewcoef11 = ptr->ld_spatialnewcoef11;
	blu_ld_spatial_ctrl6.ld_spatialnewcoef12 = ptr->ld_spatialnewcoef12;
	blu_ld_spatial_ctrl6.ld_spatialnewcoef13 = ptr->ld_spatialnewcoef13;
	blu_ld_spatial_ctrl6.ld_spatialnewcoef14 = ptr->ld_spatialnewcoef14;
	blu_ld_spatial_ctrl7.ld_spatialnewcoef20 = ptr->ld_spatialnewcoef20;
	blu_ld_spatial_ctrl7.ld_spatialnewcoef21 = ptr->ld_spatialnewcoef21;
	blu_ld_spatial_ctrl7.ld_spatialnewcoef22 = ptr->ld_spatialnewcoef22;
	blu_ld_spatial_ctrl7.ld_spatialnewcoef23 = ptr->ld_spatialnewcoef23;
	blu_ld_spatial_ctrl7.ld_spatialnewcoef24 = ptr->ld_spatialnewcoef24;
	blu_ld_spatial_ctrl8.ld_spatialnewcoef30 = ptr->ld_spatialnewcoef30;
	blu_ld_spatial_ctrl8.ld_spatialnewcoef31 = ptr->ld_spatialnewcoef31;
	blu_ld_spatial_ctrl8.ld_spatialnewcoef32 = ptr->ld_spatialnewcoef32;
	blu_ld_spatial_ctrl8.ld_spatialnewcoef33 = ptr->ld_spatialnewcoef33;
	blu_ld_spatial_ctrl8.ld_spatialnewcoef34 = ptr->ld_spatialnewcoef34;
	blu_ld_spatial_ctrl9.ld_spatialnewcoef05 = ptr->ld_spatialnewcoef05;
	blu_ld_spatial_ctrl9.ld_spatialnewcoef15 = ptr->ld_spatialnewcoef15;
	blu_ld_spatial_ctrl9.ld_spatialnewcoef25 = ptr->ld_spatialnewcoef25;
	blu_ld_spatial_ctrl9.ld_spatialnewcoef35 = ptr->ld_spatialnewcoef35;
	blu_ld_spatial_ctrla.ld_spatialnewcoef40 = ptr->ld_spatialnewcoef40;
	blu_ld_spatial_ctrla.ld_spatialnewcoef41 = ptr->ld_spatialnewcoef41;
	blu_ld_spatial_ctrla.ld_spatialnewcoef50 = ptr->ld_spatialnewcoef50;

	IoReg_Write32(BLU_LD_Spatial_Ctrl1_reg, blu_ld_spatial_ctrl1.regValue);
	IoReg_Write32(BLU_LD_Spatial_Ctrl2_reg, blu_ld_spatial_ctrl2.regValue);
	IoReg_Write32(BLU_LD_Spatial_Ctrl5_reg, blu_ld_spatial_ctrl5.regValue);
	IoReg_Write32(BLU_LD_Spatial_Ctrl6_reg, blu_ld_spatial_ctrl6.regValue);
	IoReg_Write32(BLU_LD_Spatial_Ctrl7_reg, blu_ld_spatial_ctrl7.regValue);
	IoReg_Write32(BLU_LD_Spatial_Ctrl8_reg, blu_ld_spatial_ctrl8.regValue);
	IoReg_Write32(BLU_LD_Spatial_Ctrl9_reg, blu_ld_spatial_ctrl9.regValue);
	IoReg_Write32(BLU_LD_Spatial_CtrlA_reg, blu_ld_spatial_ctrla.regValue);

}

void drvif_color_set_LD_Spatial_Remap(DRV_LD_Spatial_Remap *ptr)
{

	blu_ld_spatial_ctrl2_RBUS blu_ld_spatial_ctrl2;
	blu_ld_spatial_ctrl3_RBUS blu_ld_spatial_ctrl3;
	blu_ld_spatial_ctrl4_RBUS blu_ld_spatial_ctrl4;
	unsigned char i=0;

	blu_ld_spatial_ctrl2.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl2_reg);
	blu_ld_spatial_ctrl3.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl3_reg);
	blu_ld_spatial_ctrl4.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl4_reg);

	blu_ld_spatial_ctrl2.ld_spatialremapen = ptr->ld_spatialremapen;
	blu_ld_spatial_ctrl4.ld_spatialremaptab_initial = ptr->ld_spatialremaptab[0];
	IoReg_Write32(BLU_LD_Spatial_Ctrl4_reg, blu_ld_spatial_ctrl4.regValue);


	for (i = 0; i < 32; i++) {
		blu_ld_spatial_ctrl3.ld_spatialremapadr = i;
		blu_ld_spatial_ctrl3.ld_spatialremaptab0 = (ptr->ld_spatialremaptab[2*i+1] > 1023) ? 1023 : ptr->ld_spatialremaptab[2*i+1];
		blu_ld_spatial_ctrl3.ld_spatialremaptab1 = (ptr->ld_spatialremaptab[2*i+2] > 1023) ? 1023 : ptr->ld_spatialremaptab[2*i+2];
		IoReg_Write32(BLU_LD_Spatial_Ctrl3_reg, blu_ld_spatial_ctrl3.regValue);
	}

	IoReg_Write32(BLU_LD_Spatial_Ctrl2_reg, blu_ld_spatial_ctrl2.regValue);

}

void drvif_color_set_LD_Boost(DRV_LD_Boost *ptr)
{

	blu_ld_spatial_ctrl2_RBUS blu_ld_spatial_ctrl2;
	blu_ld_spatial_ctrl3_RBUS blu_ld_spatial_ctrl3;
	blu_ld_spatial_ctrl4_RBUS blu_ld_spatial_ctrl4;
	unsigned char i=0;

	blu_ld_spatial_ctrl2.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl2_reg);
	blu_ld_spatial_ctrl3.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl3_reg);
	blu_ld_spatial_ctrl4.regValue = IoReg_Read32(BLU_LD_Spatial_Ctrl4_reg);

	blu_ld_spatial_ctrl2.ld_backlightboosten= ptr->ld_backlightboosten;
	blu_ld_spatial_ctrl4.ld_spatialremaptab_initial3= ptr->ld_boost_gain_lut[0];
	blu_ld_spatial_ctrl4.ld_spatialremaptab_initial2= ptr->ld_boost_curve_lut[0];
	IoReg_Write32(BLU_LD_Spatial_Ctrl4_reg, blu_ld_spatial_ctrl4.regValue);


	/* Gain LUT*/
	for (i = 0; i < 32; i++) {
		blu_ld_spatial_ctrl3.ld_spatialremapadr = i+32;
		blu_ld_spatial_ctrl3.ld_spatialremaptab0 = (ptr->ld_boost_gain_lut[2*i+1] > 1023) ? 1023 : ptr->ld_boost_gain_lut[2*i+1];
		blu_ld_spatial_ctrl3.ld_spatialremaptab1 = (ptr->ld_boost_gain_lut[2*i+2] > 1023) ? 1023 : ptr->ld_boost_gain_lut[2*i+2];
		IoReg_Write32(BLU_LD_Spatial_Ctrl3_reg, blu_ld_spatial_ctrl3.regValue);
	}

	/* Boost LUT*/
	for (i = 0; i < 32; i++) {
		blu_ld_spatial_ctrl3.ld_spatialremapadr = i+64;
		blu_ld_spatial_ctrl3.ld_spatialremaptab0 = (ptr->ld_boost_curve_lut[2*i+1] > 1023) ? 1023 : ptr->ld_boost_curve_lut[2*i+1];
		blu_ld_spatial_ctrl3.ld_spatialremaptab1 = (ptr->ld_boost_curve_lut[2*i+2] > 1023) ? 1023 : ptr->ld_boost_curve_lut[2*i+2];
		IoReg_Write32(BLU_LD_Spatial_Ctrl3_reg, blu_ld_spatial_ctrl3.regValue);
	}

	IoReg_Write32(BLU_LD_Spatial_Ctrl2_reg, blu_ld_spatial_ctrl2.regValue);



}

void drvif_color_set_LD_Temporal_Filter(DRV_LD_Temporal_Filter *ptr)
{

	blu_ld_temporal_ctrl1_RBUS blu_ld_temporal_ctrl1;
	blu_ld_temporal_ctrl2_RBUS blu_ld_temporal_ctrl2;
	blu_ld_temporal_ctrl3_RBUS blu_ld_temporal_ctrl3;

	blu_ld_temporal_ctrl1.regValue = IoReg_Read32(BLU_LD_Temporal_Ctrl1_reg);
	blu_ld_temporal_ctrl2.regValue = IoReg_Read32(BLU_LD_Temporal_Ctrl2_reg);
	blu_ld_temporal_ctrl3.regValue = IoReg_Read32(BLU_LD_Temporal_Ctrl3_reg);

	blu_ld_temporal_ctrl1.ld_tmp_pos0thd = ptr->ld_tmp_pos0thd;
	blu_ld_temporal_ctrl1.ld_tmp_pos1thd = ptr->ld_tmp_pos1thd;
	blu_ld_temporal_ctrl1.ld_tmp_posmingain = ptr->ld_tmp_posmingain;
	blu_ld_temporal_ctrl1.ld_tmp_posmaxgain = ptr->ld_tmp_posmaxgain;
	blu_ld_temporal_ctrl2.ld_tmp_neg0thd = ptr->ld_tmp_neg0thd;
	blu_ld_temporal_ctrl2.ld_tmp_neg1thd = ptr->ld_tmp_neg1thd;
	blu_ld_temporal_ctrl2.ld_tmp_negmingain = ptr->ld_tmp_negmingain;
	blu_ld_temporal_ctrl2.ld_tmp_negmaxgain = ptr->ld_tmp_negmaxgain;
	blu_ld_temporal_ctrl3.ld_tmp_maxdiff = ptr->ld_tmp_maxdiff;
	blu_ld_temporal_ctrl3.ld_tmp_scenechangegain1 = ptr->ld_tmp_scenechangegain1;


	IoReg_Write32(BLU_LD_Temporal_Ctrl1_reg, blu_ld_temporal_ctrl1.regValue);
	IoReg_Write32(BLU_LD_Temporal_Ctrl2_reg, blu_ld_temporal_ctrl2.regValue);
	IoReg_Write32(BLU_LD_Temporal_Ctrl3_reg, blu_ld_temporal_ctrl3.regValue);



}

void drvif_color_set_LD_Backlight_Final_Decision(DRV_LD_Backlight_Final_Decision *ptr)
{
	blu_ld_backlight_ctrl1_RBUS blu_ld_backlight_ctrl1;

	blu_ld_backlight_ctrl1.regValue = IoReg_Read32(BLU_LD_Backlight_Ctrl1_reg);

	blu_ld_backlight_ctrl1.ld_blu_wr_num = ptr->ld_blu_wr_num;
	blu_ld_backlight_ctrl1.ld_blu_spitotal = ptr->ld_blu_spitotal;
	blu_ld_backlight_ctrl1.ld_blu_spien = ptr->ld_blu_spien;
	blu_ld_backlight_ctrl1.ld_blu_nodim = ptr->ld_blu_nodim;
	blu_ld_backlight_ctrl1.ld_blu_usergain = ptr->ld_blu_usergain;

	IoReg_Write32(BLU_LD_Backlight_Ctrl1_reg, blu_ld_backlight_ctrl1.regValue);

}

void drvif_color_set_LD_Data_Compensation(DRV_LD_Data_Compensation *ptr)
{
	blu_ld_global_ctrl0_RBUS blu_ld_global_ctrl0;
	blu_ld_data_comp_ctrl_RBUS blu_ld_data_comp_ctrl;
	blu_ld_datacomp_ctrl1_RBUS blu_ld_datacomp_ctrl1;
	blu_ld_datacomp_ctrl2_RBUS blu_ld_datacomp_ctrl2;

	blu_ld_global_ctrl0.regValue = IoReg_Read32(BLU_LD_Global_Ctrl0_reg);
	blu_ld_data_comp_ctrl.regValue = IoReg_Read32(BLU_LD_DATA_COMP_CTRL_reg);
	blu_ld_datacomp_ctrl1.regValue = IoReg_Read32(BLU_LD_DataComp_Ctrl1_reg);
	blu_ld_datacomp_ctrl2.regValue = IoReg_Read32(BLU_LD_DataComp_Ctrl2_reg);

	if (blu_ld_global_ctrl0.ld_comp_en == 1)
		blu_ld_data_comp_ctrl.ld_data_comp_mode = ptr->ld_data_comp_mode;
	else
		blu_ld_data_comp_ctrl.ld_data_comp_mode = 0;

	blu_ld_datacomp_ctrl1.ld_comp_satrange = ptr->ld_comp_satrange;
	blu_ld_datacomp_ctrl1.ld_comp_softmax = ptr->ld_comp_softmax;
	blu_ld_datacomp_ctrl1.ld_comp_minlimit = ptr->ld_comp_minlimit;
	blu_ld_datacomp_ctrl1.ld_softcomp_gain = ptr->ld_softcomp_gain;
	blu_ld_datacomp_ctrl1.ld_comp_maxmode = ptr->ld_comp_maxmode;
	blu_ld_datacomp_ctrl2.ld_comp_inv_shift = ptr->ld_comp_inv_shift;
	blu_ld_datacomp_ctrl2.ld_comp_inv_mode = ptr->ld_comp_inv_mode;
	blu_ld_datacomp_ctrl2.ld_srcgainsel = ptr->ld_srcgainsel;

	IoReg_Write32(BLU_LD_DATA_COMP_CTRL_reg, blu_ld_data_comp_ctrl.regValue);
	IoReg_Write32(BLU_LD_DataComp_Ctrl1_reg, blu_ld_datacomp_ctrl1.regValue);
	IoReg_Write32(BLU_LD_DataComp_Ctrl2_reg, blu_ld_datacomp_ctrl2.regValue);

}

void drvif_color_set_LD_Data_Compensation_NewMode_2DTable(DRV_LD_Data_Compensation_NewMode_2DTable *ptr)
{
	int i,j;
	unsigned char ld_data_comp_mode_tmp;
	blu_ld_data_comp_ctrl_RBUS blu_ld_data_comp_ctrl;
	blu_ld_lut_data_RBUS blu_ld_lut_data;

	blu_ld_data_comp_ctrl.regValue = IoReg_Read32(BLU_LD_DATA_COMP_CTRL_reg);
	ld_data_comp_mode_tmp = blu_ld_data_comp_ctrl.ld_data_comp_mode;

	blu_ld_data_comp_ctrl.ld_data_comp_mode = 0;
	blu_ld_data_comp_ctrl.ld_lut_row_addr = 0;
	blu_ld_data_comp_ctrl.ld_lut_column_addr = 0;
	blu_ld_data_comp_ctrl.ld_lut_ax_en = 1;
	blu_ld_data_comp_ctrl.ld_lut_ax_mode = 0;
	blu_ld_data_comp_ctrl.ld_lut_adr_mode = 0;
	fwif_color_WaitFor_DEN_STOP_UZUDTG();
	IoReg_Write32(BLU_LD_DATA_COMP_CTRL_reg, blu_ld_data_comp_ctrl.regValue);

	for(i=0;i<17;i++) {
		for(j=0;j<17;j++) {
			blu_ld_lut_data.ld_lut_data = ptr->ld_comp_2Dtable[i][j];
			IoReg_Write32(BLU_LD_LUT_DATA_reg, blu_ld_lut_data.regValue);
		}
	}

	blu_ld_data_comp_ctrl.regValue = IoReg_Read32(BLU_LD_DATA_COMP_CTRL_reg);
	blu_ld_data_comp_ctrl.ld_lut_ax_en = 0;
	blu_ld_data_comp_ctrl.ld_data_comp_mode = ld_data_comp_mode_tmp;
	IoReg_Write32(BLU_LD_DATA_COMP_CTRL_reg, blu_ld_data_comp_ctrl.regValue);

}


void drvif_color_set_LD_Backlight_Profile_Interpolation(DRV_LD_Backlight_Profile_Interpolation *ptr)
{
	blu_ld_inter_hctrl1_RBUS blu_ld_inter_hctrl1;
	blu_ld_inter_hctrl2_RBUS blu_ld_inter_hctrl2;
	blu_ld_inter_vctrl1_RBUS blu_ld_inter_vctrl1;
	blu_ld_inter_vctrl2_RBUS blu_ld_inter_vctrl2;


	blu_ld_sram_ctrl_RBUS blu_ld_sram_ctrl;
	/*---- by table ----*/
	blu_ld_blight_ap_RBUS blu_ld_blight_ap;
	blu_ld_blight_dp_RBUS blu_ld_blight_dp;
	/*----------------*/
	blu_ld_inter_htabsel1_RBUS blu_ld_inter_htabsel1;
	blu_ld_inter_htabsel2_RBUS blu_ld_inter_htabsel2;
	blu_ld_inter_htabsel3_RBUS blu_ld_inter_htabsel3;
	blu_ld_inter_htabsel4_RBUS blu_ld_inter_htabsel4;
	blu_ld_inter_htabsel5_RBUS blu_ld_inter_htabsel5;
	blu_ld_inter_htabsel6_RBUS blu_ld_inter_htabsel6;
	blu_ld_inter_htabsel7_RBUS blu_ld_inter_htabsel7;
	blu_ld_inter_htabsel8_RBUS blu_ld_inter_htabsel8;
	blu_ld_inter_vtabsel1_RBUS blu_ld_inter_vtabsel1;
	blu_ld_inter_vtabsel2_RBUS blu_ld_inter_vtabsel2;
	blu_ld_inter_vtabsel3_RBUS blu_ld_inter_vtabsel3;
	blu_ld_inter_vtabsel4_RBUS blu_ld_inter_vtabsel4;
	blu_ld_inter_vtabsel5_RBUS blu_ld_inter_vtabsel5;
	blu_ld_inter_vtabsel6_RBUS blu_ld_inter_vtabsel6;
	blu_ld_inter_vtabsel7_RBUS blu_ld_inter_vtabsel7;
	blu_ld_inter_vtabsel8_RBUS blu_ld_inter_vtabsel8;

	blu_ld_inter_hctrl1.regValue = IoReg_Read32(BLU_LD_Inter_HCtrl1_reg);
	blu_ld_inter_hctrl2.regValue = IoReg_Read32(BLU_LD_Inter_HCtrl2_reg);
	blu_ld_inter_vctrl1.regValue = IoReg_Read32(BLU_LD_Inter_VCtrl1_reg);
	blu_ld_inter_vctrl2.regValue = IoReg_Read32(BLU_LD_Inter_VCtrl2_reg);

	blu_ld_sram_ctrl.regValue = IoReg_Read32(BLU_LD_SRAM_CTRL_reg);
	/*---- by table ----*/
	blu_ld_blight_ap.regValue = IoReg_Read32(BLU_LD_BLIGHT_AP_reg);
	blu_ld_blight_dp.regValue = IoReg_Read32(BLU_LD_BLIGHT_DP_reg);
	/*----------------*/
	blu_ld_inter_htabsel1.regValue = IoReg_Read32(BLU_LD_Inter_HTabSel1_reg);
	blu_ld_inter_htabsel2.regValue = IoReg_Read32(BLU_LD_Inter_HtabSel2_reg);
	blu_ld_inter_htabsel3.regValue = IoReg_Read32(BLU_LD_Inter_HtabSel3_reg);
	blu_ld_inter_htabsel4.regValue = IoReg_Read32(BLU_LD_Inter_HtabSel4_reg);
	blu_ld_inter_htabsel5.regValue = IoReg_Read32(BLU_LD_Inter_HtabSel5_reg);
	blu_ld_inter_htabsel6.regValue = IoReg_Read32(BLU_LD_Inter_HtabSel6_reg);
	blu_ld_inter_htabsel7.regValue = IoReg_Read32(BLU_LD_Inter_HtabSel7_reg);
	blu_ld_inter_htabsel8.regValue = IoReg_Read32(BLU_LD_Inter_HtabSel8_reg);
	blu_ld_inter_vtabsel1.regValue = IoReg_Read32(BLU_LD_Inter_VtabSel1_reg);
	blu_ld_inter_vtabsel2.regValue = IoReg_Read32(BLU_LD_Inter_VtabSel2_reg);
	blu_ld_inter_vtabsel3.regValue = IoReg_Read32(BLU_LD_Inter_VtabSel3_reg);
	blu_ld_inter_vtabsel4.regValue = IoReg_Read32(BLU_LD_Inter_VtabSel4_reg);
	blu_ld_inter_vtabsel5.regValue = IoReg_Read32(BLU_LD_Inter_VtabSel5_reg);
	blu_ld_inter_vtabsel6.regValue = IoReg_Read32(BLU_LD_Inter_VtabSel6_reg);
	blu_ld_inter_vtabsel7.regValue = IoReg_Read32(BLU_LD_Inter_VtabSel7_reg);
	blu_ld_inter_vtabsel8.regValue = IoReg_Read32(BLU_LD_Inter_VtabSel8_reg);

	blu_ld_inter_hctrl1.ld_tab_hsize = ptr->ld_tab_hsize;
	blu_ld_inter_hctrl1.ld_hfactor = ptr->ld_hfactor;
	blu_ld_inter_hctrl2.ld_hinitphase3_right = ptr->ld_hinitphase3_right;
	blu_ld_inter_hctrl2.ld_hboundary = ptr->ld_hboundary;
	blu_ld_inter_hctrl2.ld_hinitphase1 = ptr->ld_hinitphase1;
	blu_ld_inter_hctrl2.ld_hinitphase2 = ptr->ld_hinitphase2;
	blu_ld_inter_hctrl2.ld_hinitphase3_left = ptr->ld_hinitphase3_left;
	blu_ld_inter_vctrl1.ld_tab_vsize = ptr->ld_tab_vsize;
	blu_ld_inter_vctrl1.ld_vfactor = ptr->ld_vfactor;
	blu_ld_inter_vctrl2.ld_vinitphase3_right = ptr->ld_vinitphase3_right;
	blu_ld_inter_vctrl2.ld_vboundary = ptr->ld_vboundary;
	blu_ld_inter_vctrl2.ld_vinitphase1 = ptr->ld_vinitphase1;
	blu_ld_inter_vctrl2.ld_vinitphase2 = ptr->ld_vinitphase2;
	blu_ld_inter_vctrl2.ld_vinitphase3_left = ptr->ld_vinitphase3_left;

	blu_ld_sram_ctrl.ld_blight_update_en = ptr->ld_blight_update_en;
	blu_ld_sram_ctrl.ld_blight_sw_mode = ptr->ld_blight_sw_mode;


	blu_ld_inter_htabsel1.ld_htabsel_0 = ptr->ld_htabsel_0;
	blu_ld_inter_htabsel1.ld_htabsel_1 = ptr->ld_htabsel_1;
	blu_ld_inter_htabsel1.ld_htabsel_2 = ptr->ld_htabsel_2;
	blu_ld_inter_htabsel1.ld_htabsel_3 = ptr->ld_htabsel_3;
	blu_ld_inter_htabsel2.ld_htabsel_4 = ptr->ld_htabsel_4;
	blu_ld_inter_htabsel2.ld_htabsel_5 = ptr->ld_htabsel_5;
	blu_ld_inter_htabsel2.ld_htabsel_6 = ptr->ld_htabsel_6;
	blu_ld_inter_htabsel2.ld_htabsel_7 = ptr->ld_htabsel_7;
	blu_ld_inter_htabsel3.ld_htabsel_8 = ptr->ld_htabsel_8;
	blu_ld_inter_htabsel3.ld_htabsel_9 = ptr->ld_htabsel_9;
	blu_ld_inter_htabsel3.ld_htabsel_10 = ptr->ld_htabsel_10;
	blu_ld_inter_htabsel3.ld_htabsel_11 = ptr->ld_htabsel_11;
	blu_ld_inter_htabsel4.ld_htabsel_12 = ptr->ld_htabsel_12;
	blu_ld_inter_htabsel4.ld_htabsel_13 = ptr->ld_htabsel_13;
	blu_ld_inter_htabsel4.ld_htabsel_14 = ptr->ld_htabsel_14;
	blu_ld_inter_htabsel4.ld_htabsel_15 = ptr->ld_htabsel_15;
	blu_ld_inter_htabsel5.ld_htabsel_16 = ptr->ld_htabsel_16;
	blu_ld_inter_htabsel5.ld_htabsel_17 = ptr->ld_htabsel_17;
	blu_ld_inter_htabsel5.ld_htabsel_18 = ptr->ld_htabsel_18;
	blu_ld_inter_htabsel5.ld_htabsel_19 = ptr->ld_htabsel_19;
	blu_ld_inter_htabsel6.ld_htabsel_20 = ptr->ld_htabsel_20;
	blu_ld_inter_htabsel6.ld_htabsel_21 = ptr->ld_htabsel_21;
	blu_ld_inter_htabsel6.ld_htabsel_22 = ptr->ld_htabsel_22;
	blu_ld_inter_htabsel6.ld_htabsel_23 = ptr->ld_htabsel_23;
	blu_ld_inter_htabsel7.ld_htabsel_24 = ptr->ld_htabsel_24;
	blu_ld_inter_htabsel7.ld_htabsel_25 = ptr->ld_htabsel_25;
	blu_ld_inter_htabsel7.ld_htabsel_26 = ptr->ld_htabsel_26;
	blu_ld_inter_htabsel7.ld_htabsel_27 = ptr->ld_htabsel_27;
	blu_ld_inter_htabsel8.ld_htabsel_28 = ptr->ld_htabsel_28;
	blu_ld_inter_htabsel8.ld_htabsel_29 = ptr->ld_htabsel_29;
	blu_ld_inter_htabsel8.ld_htabsel_30 = ptr->ld_htabsel_30;
	blu_ld_inter_htabsel8.ld_htabsel_31 = ptr->ld_htabsel_31;
	blu_ld_inter_vtabsel1.ld_vtabsel_0 = ptr->ld_vtabsel_0;
	blu_ld_inter_vtabsel1.ld_vtabsel_1 = ptr->ld_vtabsel_1;
	blu_ld_inter_vtabsel1.ld_vtabsel_2 = ptr->ld_vtabsel_2;
	blu_ld_inter_vtabsel1.ld_vtabsel_3 = ptr->ld_vtabsel_3;
	blu_ld_inter_vtabsel2.ld_vtabsel_4 = ptr->ld_vtabsel_4;
	blu_ld_inter_vtabsel2.ld_vtabsel_5 = ptr->ld_vtabsel_5;
	blu_ld_inter_vtabsel2.ld_vtabsel_6 = ptr->ld_vtabsel_6;
	blu_ld_inter_vtabsel2.ld_vtabsel_7 = ptr->ld_vtabsel_7;
	blu_ld_inter_vtabsel3.ld_vtabsel_8 = ptr->ld_vtabsel_8;
	blu_ld_inter_vtabsel3.ld_vtabsel_9 = ptr->ld_vtabsel_9;
	blu_ld_inter_vtabsel3.ld_vtabsel_10 = ptr->ld_vtabsel_10;
	blu_ld_inter_vtabsel3.ld_vtabsel_11 = ptr->ld_vtabsel_11;
	blu_ld_inter_vtabsel4.ld_vtabsel_12 = ptr->ld_vtabsel_12;
	blu_ld_inter_vtabsel4.ld_vtabsel_13 = ptr->ld_vtabsel_13;
	blu_ld_inter_vtabsel4.ld_vtabsel_14 = ptr->ld_vtabsel_14;
	blu_ld_inter_vtabsel4.ld_vtabsel_15 = ptr->ld_vtabsel_15;
	blu_ld_inter_vtabsel5.ld_vtabsel_16 = ptr->ld_vtabsel_16;
	blu_ld_inter_vtabsel5.ld_vtabsel_17 = ptr->ld_vtabsel_17;
	blu_ld_inter_vtabsel5.ld_vtabsel_18 = ptr->ld_vtabsel_18;
	blu_ld_inter_vtabsel5.ld_vtabsel_19 = ptr->ld_vtabsel_19;
	blu_ld_inter_vtabsel6.ld_vtabsel_20 = ptr->ld_vtabsel_20;
	blu_ld_inter_vtabsel6.ld_vtabsel_21 = ptr->ld_vtabsel_21;
	blu_ld_inter_vtabsel6.ld_vtabsel_22 = ptr->ld_vtabsel_22;
	blu_ld_inter_vtabsel6.ld_vtabsel_23 = ptr->ld_vtabsel_23;
	blu_ld_inter_vtabsel7.ld_vtabsel_24 = ptr->ld_vtabsel_24;
	blu_ld_inter_vtabsel7.ld_vtabsel_25 = ptr->ld_vtabsel_25;
	blu_ld_inter_vtabsel7.ld_vtabsel_26 = ptr->ld_vtabsel_26;
	blu_ld_inter_vtabsel7.ld_vtabsel_27 = ptr->ld_vtabsel_27;
	blu_ld_inter_vtabsel8.ld_vtabsel_28 = ptr->ld_vtabsel_28;
	blu_ld_inter_vtabsel8.ld_vtabsel_29 = ptr->ld_vtabsel_29;
	blu_ld_inter_vtabsel8.ld_vtabsel_30 = ptr->ld_vtabsel_30;
	blu_ld_inter_vtabsel8.ld_vtabsel_31 = ptr->ld_vtabsel_31;


	IoReg_Write32(BLU_LD_SRAM_CTRL_reg, blu_ld_sram_ctrl.regValue);


	IoReg_Write32(BLU_LD_Inter_HCtrl1_reg, blu_ld_inter_hctrl1.regValue);
	IoReg_Write32(BLU_LD_Inter_HCtrl2_reg, blu_ld_inter_hctrl2.regValue);
	IoReg_Write32(BLU_LD_Inter_VCtrl1_reg, blu_ld_inter_vctrl1.regValue);
	IoReg_Write32(BLU_LD_Inter_VCtrl2_reg, blu_ld_inter_vctrl2.regValue);

	IoReg_Write32(BLU_LD_BLIGHT_AP_reg, blu_ld_blight_ap.regValue);
	IoReg_Write32(BLU_LD_BLIGHT_DP_reg, blu_ld_blight_dp.regValue);

	IoReg_Write32(BLU_LD_Inter_HTabSel1_reg, blu_ld_inter_htabsel1.regValue);
	IoReg_Write32(BLU_LD_Inter_HtabSel2_reg, blu_ld_inter_htabsel2.regValue);
	IoReg_Write32(BLU_LD_Inter_HtabSel3_reg, blu_ld_inter_htabsel3.regValue);
	IoReg_Write32(BLU_LD_Inter_HtabSel4_reg, blu_ld_inter_htabsel4.regValue);
	IoReg_Write32(BLU_LD_Inter_HtabSel5_reg, blu_ld_inter_htabsel5.regValue);
	IoReg_Write32(BLU_LD_Inter_HtabSel6_reg, blu_ld_inter_htabsel6.regValue);
	IoReg_Write32(BLU_LD_Inter_HtabSel7_reg, blu_ld_inter_htabsel7.regValue);
	IoReg_Write32(BLU_LD_Inter_HtabSel8_reg, blu_ld_inter_htabsel8.regValue);
	IoReg_Write32(BLU_LD_Inter_VtabSel1_reg, blu_ld_inter_vtabsel1.regValue);
	IoReg_Write32(BLU_LD_Inter_VtabSel2_reg, blu_ld_inter_vtabsel2.regValue);
	IoReg_Write32(BLU_LD_Inter_VtabSel3_reg, blu_ld_inter_vtabsel3.regValue);
	IoReg_Write32(BLU_LD_Inter_VtabSel4_reg, blu_ld_inter_vtabsel4.regValue);
	IoReg_Write32(BLU_LD_Inter_VtabSel5_reg, blu_ld_inter_vtabsel5.regValue);
	IoReg_Write32(BLU_LD_Inter_VtabSel6_reg, blu_ld_inter_vtabsel6.regValue);
	IoReg_Write32(BLU_LD_Inter_VtabSel7_reg, blu_ld_inter_vtabsel7.regValue);
	IoReg_Write32(BLU_LD_Inter_VtabSel8_reg, blu_ld_inter_vtabsel8.regValue);


}

void drvif_color_set_LD_BL_Profile_Interpolation_Table(unsigned int *ptr)
{
	int i, j, k;
	unsigned int *hlsb_ptr;
	unsigned int *hmsb_ptr;
	unsigned int *vlsb_ptr;
	unsigned int *vmsb_ptr;
	/*---- by table ----*/
	blu_ld_vtab_ap_RBUS blu_ld_vtab_ap;
	blu_ld_vtab_dp_RBUS blu_ld_vtab_dp;
	blu_ld_htab_ap_RBUS blu_ld_htab_ap;
	blu_ld_htab_dp_RBUS blu_ld_htab_dp;
	/*----------------*/

	blu_ld_sram_ctrl_RBUS blu_ld_sram_ctrl;

	/*---- by table ----*/
	blu_ld_vtab_ap.regValue = IoReg_Read32(BLU_LD_VTAB_AP_reg);
	blu_ld_vtab_dp.regValue = IoReg_Read32(BLU_LD_VTAB_DP_reg);
	blu_ld_htab_ap.regValue = IoReg_Read32(BLU_LD_HTAB_AP_reg);
	blu_ld_htab_dp.regValue = IoReg_Read32(BLU_LD_HTAB_DP_reg);
	/*----------------*/
	blu_ld_sram_ctrl.regValue = IoReg_Read32(BLU_LD_SRAM_CTRL_reg);

	blu_ld_sram_ctrl.ld_table_sw_mode = 1; /*software mode enable*/
	IoReg_Write32(BLU_LD_SRAM_CTRL_reg, blu_ld_sram_ctrl.regValue);

	blu_ld_vtab_ap.ld_vtab_adr = 0;
	blu_ld_htab_ap.ld_htab_adr = 0;
	IoReg_Write32(BLU_LD_VTAB_AP_reg, blu_ld_vtab_ap.regValue);
	IoReg_Write32(BLU_LD_HTAB_AP_reg, blu_ld_htab_ap.regValue);

	for (i = 0; i < BL_Profile_Table_NUM; i++) {
		for (k=0; k<BL_Profile_Table_ROW/4;k++) {

			hlsb_ptr = ptr+i*BL_Profile_Table_ROW*BL_Profile_Table_COLUMN + 2*k*BL_Profile_Table_COLUMN;
			hmsb_ptr = ptr+i*BL_Profile_Table_ROW*BL_Profile_Table_COLUMN + (BL_Profile_Table_ROW-2*k-1)*BL_Profile_Table_COLUMN;
			vlsb_ptr = ptr+i*BL_Profile_Table_ROW*BL_Profile_Table_COLUMN + (2*k+1)*BL_Profile_Table_COLUMN;
			vmsb_ptr = ptr+i*BL_Profile_Table_ROW*BL_Profile_Table_COLUMN + (BL_Profile_Table_ROW-2*k-2)*BL_Profile_Table_COLUMN;

			for (j = 0; j < BL_Profile_Table_COLUMN; j++) {

				blu_ld_vtab_dp.ld_vtab_dat_msb = *(vmsb_ptr+j);/*ptr->ld_vtab_dat_msb;*/
				blu_ld_vtab_dp.ld_vtab_dat_lsb = *(vlsb_ptr+j);/*ptr->ld_vtab_dat_lsb;*/

				blu_ld_htab_dp.ld_htab_dat_msb = *(hmsb_ptr+j);/*ptr->ld_htab_dat_msb;*/
				blu_ld_htab_dp.ld_htab_dat_lsb = *(hlsb_ptr+j);/*ptr->ld_htab_dat_lsb;*/

				//blu_ld_vtab_dp.ld_vtab_dat_msb = *(ptr+i*BL_Profile_Table_ROW*BL_Profile_Table_COLUMN+2*BL_Profile_Table_COLUMN+j);/*ptr->ld_vtab_dat_msb;*/
				//blu_ld_vtab_dp.ld_vtab_dat_lsb = *(ptr+i*BL_Profile_Table_ROW*BL_Profile_Table_COLUMN+1*BL_Profile_Table_COLUMN+j);/*ptr->ld_vtab_dat_lsb;*/

				//blu_ld_htab_dp.ld_htab_dat_msb = *(ptr+i*BL_Profile_Table_ROW*BL_Profile_Table_COLUMN+3*BL_Profile_Table_COLUMN+j);/*ptr->ld_htab_dat_msb;*/
				//blu_ld_htab_dp.ld_htab_dat_lsb = *(ptr+i*BL_Profile_Table_ROW*BL_Profile_Table_COLUMN+0*BL_Profile_Table_COLUMN+j);/*ptr->ld_htab_dat_lsb;*/

				IoReg_Write32(BLU_LD_VTAB_DP_reg, blu_ld_vtab_dp.regValue);
				IoReg_Write32(BLU_LD_HTAB_DP_reg, blu_ld_htab_dp.regValue);
			}
		}
	}

	blu_ld_sram_ctrl.ld_table_sw_mode = 0; /* software mode disable*/
	IoReg_Write32(BLU_LD_SRAM_CTRL_reg, blu_ld_sram_ctrl.regValue);


}

void drvif_color_set_LD_Demo_Window(DRV_LD_Demo_Window *ptr)
{
	blu_ld_demo_window_ctrl0_RBUS blu_ld_demo_window_ctrl0;
	blu_ld_demo_window_ctrl1_RBUS blu_ld_demo_window_ctrl1;

	blu_ld_demo_window_ctrl0.regValue = IoReg_Read32(BLU_LD_Demo_window_ctrl0_reg);
	blu_ld_demo_window_ctrl1.regValue = IoReg_Read32(BLU_LD_Demo_window_ctrl1_reg);

	blu_ld_demo_window_ctrl0.ld_demo_en = ptr->ld_demo_en;
	blu_ld_demo_window_ctrl0.ld_demo_mode = ptr->ld_demo_mode;
	blu_ld_demo_window_ctrl0.ld_demo_top = ptr->ld_demo_top;
	blu_ld_demo_window_ctrl0.ld_demo_bottom = ptr->ld_demo_bottom;
	blu_ld_demo_window_ctrl1.ld_demo_left = ptr->ld_demo_left;
	blu_ld_demo_window_ctrl1.ld_demo_right = ptr->ld_demo_right;

	IoReg_Write32(BLU_LD_Demo_window_ctrl0_reg, blu_ld_demo_window_ctrl0.regValue);
	IoReg_Write32(BLU_LD_Demo_window_ctrl1_reg, blu_ld_demo_window_ctrl1.regValue);

}

#if CONFIG_FIRMWARE_IN_KERNEL
void drvif_HAL_VPQ_LED_LDEnable(unsigned char bCtrl)
{
	RBus_UInt32 staAddr = 0;
	RBus_UInt32 blvle = 0xff;
	int i;


	blu_ld_backlight_ctrl1_RBUS blu_ld_backlight_ctrl1;
	blu_ld_global_ctrl2_RBUS blu_ld_global_ctrl2;

	blu_ld_backlight_ctrl1.regValue = IoReg_Read32(BLU_LD_Backlight_Ctrl1_reg);
	blu_ld_global_ctrl2.regValue = IoReg_Read32(BLU_LD_Global_Ctrl2_reg);

	blu_ld_backlight_ctrl1.ld_blu_spien = bCtrl;

	fwif_color_WaitFor_DEN_STOP_MEMCDTG();
	IoReg_Write32(BLU_LD_Backlight_Ctrl1_reg, blu_ld_backlight_ctrl1.regValue);

	if (bCtrl == 0) {	/*reset LD interface sram*/

		IoReg_Write32(LDSPI_Data_Addr_CTRL_reg, staAddr);
		for (i = 0; i < 64; i++) {		/*in Mac3 data sram size is 64 + header size = 128, clear data part.*/

			IoReg_Write32(LDSPI_Data_Rwport_reg, blvle);
		}

	}

	drvif_HAL_VPQ_LED_LDEnablePixelCompensation(bCtrl);


}
#endif
void drvif_HAL_VPQ_LED_LDEnablePixelCompensation(unsigned char bCtrl)
{
	unsigned int buffer_status_count = 0;
	unsigned int buffer_status_level;

	blu_ld_global_ctrl0_RBUS blu_ld_global_ctrl0;
	blu_ld_data_comp_ctrl_RBUS blu_ld_data_comp_ctrl;

	blu_ld_global_ctrl0.regValue = IoReg_Read32(BLU_LD_Global_Ctrl0_reg);
	blu_ld_data_comp_ctrl.regValue = IoReg_Read32(BLU_LD_DATA_COMP_CTRL_reg);

	if (blu_ld_global_ctrl0.ld_comp_en == 1)
		blu_ld_data_comp_ctrl.ld_data_comp_mode = bCtrl;
	else
		blu_ld_data_comp_ctrl.ld_data_comp_mode = 0;

	IoReg_Write32(BLU_LD_DATA_COMP_CTRL_reg, blu_ld_data_comp_ctrl.regValue);
}

void drvif_HAL_VPQ_LED_LDCtrlDemoMode(DRV_HAL_VPQ_LED_LDCtrlDemoMode *ptr)
{
	blu_ld_demo_window_ctrl0_RBUS blu_ld_demo_window_ctrl0;
	blu_ld_demo_window_ctrl1_RBUS blu_ld_demo_window_ctrl1;
	blu_ld_global_ctrl0_RBUS blu_ld_global_ctrl0;

	blu_ld_global_ctrl2_RBUS blu_ld_global_ctrl2;
	unsigned char ucld_blk_hnum, ucld_blk_vnum = 0;

	bool bCtrl = ptr->bCtrl;/*LDCtrlDemoMode.bCtrl;*/
	UINT8 bType = ptr->ctrlMode;/*LDCtrlDemoMode.ctrlMode;*/

	blu_ld_demo_window_ctrl0.regValue = IoReg_Read32(BLU_LD_Demo_window_ctrl0_reg);
	blu_ld_demo_window_ctrl1.regValue = IoReg_Read32(BLU_LD_Demo_window_ctrl1_reg);
	blu_ld_global_ctrl0.regValue = IoReg_Read32(BLU_LD_Global_Ctrl0_reg);

	blu_ld_global_ctrl2.regValue = IoReg_Read32(BLU_LD_Global_Ctrl2_reg);

	ucld_blk_hnum = blu_ld_global_ctrl2.ld_blk_hnum;
	ucld_blk_vnum = blu_ld_global_ctrl2.ld_blk_vnum;
	if (bCtrl) {
		if (bType == LED_ONOFF) {	/*Each LED should blink sequentially*/
			/*autoMA do that?*/
			/*Use blu_ld_global_ctrl0.dummy1802c200_30_0 to save enable bit & number of backlight*/
			/*bit 0 -> enable bit*/
			/*bit 1~9 -> number of backlight*/
			/*bit 10~15 -> timer*/
			unsigned int numOfbacklight = ucld_blk_hnum+1; /*max - need to be fixed by LD spec*/
			unsigned int blinkTimer = 60;
			blu_ld_global_ctrl0.dummy1802c200_30_0 = (blinkTimer<<10) + (numOfbacklight << 1) + 1;
		} else if (bType == SPLIT_SCREEN) {		/*Change half of screen as full white and show local dimming effect.*/
			blu_ld_demo_window_ctrl0.ld_demo_en = bCtrl;
			blu_ld_demo_window_ctrl0.ld_demo_mode = 0;
			blu_ld_demo_window_ctrl0.ld_demo_top = 0;
			blu_ld_demo_window_ctrl0.ld_demo_bottom = ptr->height;
			blu_ld_demo_window_ctrl1.ld_demo_left = 0;
			blu_ld_demo_window_ctrl1.ld_demo_right = ptr->width;
			blu_ld_global_ctrl0.dummy1802c200_30_0 = 0;

		}
	} else {
		blu_ld_demo_window_ctrl0.ld_demo_en = bCtrl;
		blu_ld_global_ctrl0.dummy1802c200_30_0 = 0;
	}
	IoReg_Write32(BLU_LD_Demo_window_ctrl0_reg, blu_ld_demo_window_ctrl0.regValue);
	IoReg_Write32(BLU_LD_Demo_window_ctrl1_reg, blu_ld_demo_window_ctrl1.regValue);
	IoReg_Write32(BLU_LD_Global_Ctrl0_reg, blu_ld_global_ctrl0.regValue);
}

extern unsigned char LD_CMD;
void drvif_HAL_VPQ_LED_LDCtrlSPI(unsigned char *LDCtrlSPI)
{

	unsigned char bitMask;
	unsigned char bCtrl;
	unsigned char cmd;

	ldspi_ld_ctrl_RBUS ld_ctrl;
	ldspi_data_addr_ctrl_RBUS ldspi_data_addr_ctrl;
	ldspi_data_rwport_RBUS ldspi_data_rwport;

	ld_ctrl.regValue = IoReg_Read32(LDSPI_LD_CTRL_reg);
	ld_ctrl.start_enable = 0;/*Ld_spi disable*/
	IoReg_Write32(LDSPI_LD_CTRL_reg, ld_ctrl.regValue);


	bitMask = *(LDCtrlSPI+0);
	bCtrl = *(LDCtrlSPI+1);

	cmd = LD_CMD;

	if (bCtrl == 1) {
		cmd = cmd | bitMask;
	} else if(bCtrl ==0) {
		cmd = cmd & ~bitMask;
	} else
		VIPprintf( "[VPQ] [Error] drvif_HAL_VPQ_LED_LDCtrlSPI, bCtrl=%d\n",bCtrl);

	ldspi_data_addr_ctrl.regValue = IoReg_Read32(LDSPI_Data_Addr_CTRL_reg);
	ldspi_data_addr_ctrl.data_rw_pointer_set = 0x7f;
	IoReg_Write32(LDSPI_Data_Addr_CTRL_reg, ldspi_data_addr_ctrl.regValue); /*Modify data in data SRAM for cmd*/


	ldspi_data_rwport.data_rw_data_port = cmd;
	IoReg_Write32(LDSPI_Data_Rwport_reg, ldspi_data_rwport.regValue); /*Cmd*/
	LD_CMD = cmd;
	ld_ctrl.send_follow_vsync = 1; /*Send_follow_Vsync*/
	ld_ctrl.start_enable = 1;/*Ld_spi enable*/
	IoReg_Write32(LDSPI_LD_CTRL_reg, ld_ctrl.regValue);

}

unsigned char drvif_color_get_LD_GetAPL_TV006(unsigned short *BLValue)
{
	unsigned char ret = 1;

	blu_ld_global_ctrl2_RBUS blu_ld_global_ctrl2;
	ldspi_data_addr_ctrl_RBUS ldspi_data_addr_ctrl;
	ldspi_data_rwport_RBUS ldspi_data_rwport;
	unsigned char ld_blk_type, ld_blk_hnum, ld_blk_vnum;
	int i=0;
	unsigned short max =0, min=255, dummy;//, tmp=0;

	if(BLValue == NULL) {
		VIPprintf(" [Warning] drv GetAPL is not correct, BLValue is NULL\n");
		ret = 0;
		return ret;
	}

	blu_ld_global_ctrl2.regValue = IoReg_Read32(BLU_LD_Global_Ctrl2_reg);
	ld_blk_type = blu_ld_global_ctrl2.ld_blk_type;
	ld_blk_hnum = blu_ld_global_ctrl2.ld_blk_hnum;
	ld_blk_vnum = blu_ld_global_ctrl2.ld_blk_vnum;

	ldspi_data_addr_ctrl.regValue = IoReg_Read32(LDSPI_Data_Addr_CTRL_reg);
	ldspi_data_addr_ctrl.data_rw_pointer_set = 0x00;
	IoReg_Write32(LDSPI_Data_Addr_CTRL_reg, ldspi_data_addr_ctrl.regValue);
	dummy = IoReg_Read32(LDSPI_Data_Rwport_reg);


	max = 0;
	min = 255;
	if (ld_blk_type == 1 || ld_blk_type==2) {/*edge type*/
		if (ld_blk_vnum == 0) {/*1 sided*/
			for(i=0;i<2*(ld_blk_hnum+1);i+=2) {
				ldspi_data_rwport.regValue = IoReg_Read32(LDSPI_Data_Rwport_reg);

				if (ldspi_data_rwport.data_rw_data_port > max)
					max = ldspi_data_rwport.data_rw_data_port;
				if (ldspi_data_rwport.data_rw_data_port < min)
					min = ldspi_data_rwport.data_rw_data_port;
				ldspi_data_rwport.regValue = IoReg_Read32(LDSPI_Data_Rwport_reg);


			}
			VIPprintf("[VPQLED] 1. max=%d, min=%d\n", max,min);
		} else {/*2 sided*/
			for(i=0;i<2*(ld_blk_hnum+1);i++) {
				ldspi_data_rwport.regValue = IoReg_Read32(LDSPI_Data_Rwport_reg);
				if (ldspi_data_rwport.data_rw_data_port > max)
					max = ldspi_data_rwport.data_rw_data_port;
				if (ldspi_data_rwport.data_rw_data_port < min)
					min = ldspi_data_rwport.data_rw_data_port;
			}
			VIPprintf("[VPQLED] 2. max=%d, min=%d\n", max,min);

		}

	} else if(ld_blk_type == 0) { /*direct type*/
		for(i=0;i<(ld_blk_vnum+1)*(ld_blk_hnum+1);i++) {
			ldspi_data_rwport.regValue = IoReg_Read32(LDSPI_Data_Rwport_reg);
			if (ldspi_data_rwport.data_rw_data_port > max)
				max = ldspi_data_rwport.data_rw_data_port;
			if (ldspi_data_rwport.data_rw_data_port < min)
				min = ldspi_data_rwport.data_rw_data_port;

		}
		VIPprintf("[VPQLED] 3. max=%d, min=%d\n", max,min);

	} else {
		VIPprintf("[VPQLED][Warning] GetAPL is not correct, id type = %d\n", ld_blk_type);

	}

	*BLValue = max * 4;
	*(BLValue+1) = min * 4;

	return ret;
}

static void rtd_part_outl(unsigned int reg_addr, unsigned int endBit, unsigned int startBit, unsigned int value)
{
    unsigned int X,A,result;
    X=(1<<(endBit-startBit+1))-1;
    A=rtd_inl(reg_addr);
    result = (A & (~(X<<startBit))) | (value<<startBit);
    rtd_outl(reg_addr,result);
}
void drvif_color_Set_Local_Dimming_Full(unsigned char nValue)
{

	rtd_part_outl(0xb802C900,0,0,0x0);		//Ld_spi disable
	//---Script Start---

	//-------------------------
	//	LD SPI Pin Share
	//-------------------------
	rtd_part_outl(0xb8000888,31,28,0x5);	//ld_spi0_p1_cs1,<O>			gpio147 (Ball_AT38)
	rtd_part_outl(0xb8000888,15,12,0x5);	//ld_spi0_p5_v_sync,<O> 		gpio151 (Ball_AP36)
	rtd_part_outl(0xb8000888,27,24,0x5);	//ld_spi0_p2_sck_src3,<I/O> 	gpio148 (Ball_AR36)
	rtd_part_outl(0xb80008b4,27,25,0x3);	//sck_pin_mux src3
	rtd_part_outl(0xb8000888,23,20,0x5);	//ld_spi0_p3_sdo_SRC3,<I/O> 	gpio149 (Ball_AR38)
	rtd_part_outl(0xb80008b4,24,22,0x3);	//sdo_pin_mux src3


	//-------------------------
	//	LD InterFace Init
	//-------------------------
	rtd_part_outl(0xb802C900,31,30,0x1);	//LGD mode(default)
	rtd_part_outl(0xb802C900,4,4,0x1);		//LD_SPI1
	rtd_part_outl(0xb802C900,3,3,0x0);		//one SPI local dimming block

	rtd_part_outl(0xb802C904,31,31,0x1);	//First received bit or transmitted bit is in the MSB of SRAM or register
	rtd_part_outl(0xb802C904,13,4,0x70);	//Output Unit:8 unit(= set+1)	  Output Unit:113 unit(= set+1)
	rtd_part_outl(0xb802C904,1,0,0x0);		//Output_Data_format:8 bit

	rtd_part_outl(0xb802C908,23,16,0x4f);	//SCK_H
	rtd_part_outl(0xb802C908,7,0,0x4f); 	//SCK_L
	rtd_part_outl(0xb802C90c,31,8,0xea60);	//Data_send_Delay
	rtd_part_outl(0xb802C910,31,8,0xd4c);	//Each_unit_delay
	rtd_part_outl(0xb802C914,31,24,0x32);	//Vsync_d
	rtd_part_outl(0xb802C918,24,16,0x4f);	//Data_hold_time, must to set equal SCK_H!!!


	//------------------------------
	//	LD Data Output Index SRAM
	//------------------------------
	rtd_outl(0xb802C91c,0x00);		//Output data index RW_port pointer set

	rtd_outl(0xb802C920,0x5a);		//Start_ID 1st byte
	rtd_outl(0xb802C920,0x5b);		//Start_ID 2nd byte
	rtd_outl(0xb802C920,0x5c);		//command

	rtd_outl(0xb802C920,0x0);		//col 1
	rtd_outl(0xb802C920,0x0);
	rtd_outl(0xb802C920,0x1);
	rtd_outl(0xb802C920,0x1);
	rtd_outl(0xb802C920,0x2);
	rtd_outl(0xb802C920,0x2);
	rtd_outl(0xb802C920,0x3);
	rtd_outl(0xb802C920,0x3);
	rtd_outl(0xb802C920,0x4);
	rtd_outl(0xb802C920,0x4);
	rtd_outl(0xb802C920,0x5);
	rtd_outl(0xb802C920,0x5);
	rtd_outl(0xb802C920,0x6);
	rtd_outl(0xb802C920,0x6);
	rtd_outl(0xb802C920,0x7);
	rtd_outl(0xb802C920,0x7);
	rtd_outl(0xb802C920,0x8);
	rtd_outl(0xb802C920,0x8);// 9 block repeat to 18 block


	rtd_outl(0xb802C920,0x9);// col 2
	rtd_outl(0xb802C920,0xa);
	rtd_outl(0xb802C920,0xb);
	rtd_outl(0xb802C920,0xc);
	rtd_outl(0xb802C920,0xd);
	rtd_outl(0xb802C920,0xe);
	rtd_outl(0xb802C920,0xf);
	rtd_outl(0xb802C920,0x10);
	rtd_outl(0xb802C920,0x11);

	rtd_outl(0xb802C920,0x12);// col 3
	rtd_outl(0xb802C920,0x13);
	rtd_outl(0xb802C920,0x14);
	rtd_outl(0xb802C920,0x15);
	rtd_outl(0xb802C920,0x16);
	rtd_outl(0xb802C920,0x17);
	rtd_outl(0xb802C920,0x18);
	rtd_outl(0xb802C920,0x19);
	rtd_outl(0xb802C920,0x1a);

	rtd_outl(0xb802C920,0x1b);// col 4
	rtd_outl(0xb802C920,0x1c);
	rtd_outl(0xb802C920,0x1d);
	rtd_outl(0xb802C920,0x1e);
	rtd_outl(0xb802C920,0x1f);
	rtd_outl(0xb802C920,0x20);
	rtd_outl(0xb802C920,0x21);
	rtd_outl(0xb802C920,0x22);
	rtd_outl(0xb802C920,0x23);

	rtd_outl(0xb802C920,0x24);// col 5
	rtd_outl(0xb802C920,0x25);
	rtd_outl(0xb802C920,0x26);
	rtd_outl(0xb802C920,0x27);
	rtd_outl(0xb802C920,0x28);
	rtd_outl(0xb802C920,0x29);
	rtd_outl(0xb802C920,0x2a);
	rtd_outl(0xb802C920,0x2b);
	rtd_outl(0xb802C920,0x2c);

	rtd_outl(0xb802C920,0x2d);// col 6
	rtd_outl(0xb802C920,0x2e);
	rtd_outl(0xb802C920,0x2f);
	rtd_outl(0xb802C920,0x30);
	rtd_outl(0xb802C920,0x31);
	rtd_outl(0xb802C920,0x32);
	rtd_outl(0xb802C920,0x33);
	rtd_outl(0xb802C920,0x34);
	rtd_outl(0xb802C920,0x35);

	rtd_outl(0xb802C920,0x36);// col 7
	rtd_outl(0xb802C920,0x37);
	rtd_outl(0xb802C920,0x38);
	rtd_outl(0xb802C920,0x39);
	rtd_outl(0xb802C920,0x3a);
	rtd_outl(0xb802C920,0x3b);
	rtd_outl(0xb802C920,0x3c);
	rtd_outl(0xb802C920,0x3d);
	rtd_outl(0xb802C920,0x3e);

	rtd_outl(0xb802C920,0x3f);// col 8
	rtd_outl(0xb802C920,0x40);
	rtd_outl(0xb802C920,0x41);
	rtd_outl(0xb802C920,0x42);
	rtd_outl(0xb802C920,0x43);
	rtd_outl(0xb802C920,0x44);
	rtd_outl(0xb802C920,0x45);
	rtd_outl(0xb802C920,0x46);
	rtd_outl(0xb802C920,0x47);

	rtd_outl(0xb802C920,0x48);// col 9
	rtd_outl(0xb802C920,0x49);
	rtd_outl(0xb802C920,0x4a);
	rtd_outl(0xb802C920,0x4b);
	rtd_outl(0xb802C920,0x4c);
	rtd_outl(0xb802C920,0x4d);
	rtd_outl(0xb802C920,0x4e);
	rtd_outl(0xb802C920,0x4f);
	rtd_outl(0xb802C920,0x50);

	rtd_outl(0xb802C920,0x51);// col 10
	rtd_outl(0xb802C920,0x51);
	rtd_outl(0xb802C920,0x52);
	rtd_outl(0xb802C920,0x52);
	rtd_outl(0xb802C920,0x53);
	rtd_outl(0xb802C920,0x53);
	rtd_outl(0xb802C920,0x54);
	rtd_outl(0xb802C920,0x54);
	rtd_outl(0xb802C920,0x55);
	rtd_outl(0xb802C920,0x55);
	rtd_outl(0xb802C920,0x56);
	rtd_outl(0xb802C920,0x56);
	rtd_outl(0xb802C920,0x57);
	rtd_outl(0xb802C920,0x57);
	rtd_outl(0xb802C920,0x58);
	rtd_outl(0xb802C920,0x58);
	rtd_outl(0xb802C920,0x59);
	rtd_outl(0xb802C920,0x59);// 9 block repeat to 18 block

	rtd_outl(0xb802C920,0x5d);		//End_ID 1st byte
	rtd_outl(0xb802C920,0x5e);		//End_ID 2nd byte


	//------------------------------
	//	LD Data SRAM
	//------------------------------

	rtd_outl(0xb802C924,0x00);	//Data RW_port pointer set

	rtd_outl(0xb802C928,1); 	//line 1
	rtd_outl(0xb802C928,2);
	rtd_outl(0xb802C928,3);
	rtd_outl(0xb802C928,4);
	rtd_outl(0xb802C928,5);
	rtd_outl(0xb802C928,6);
	rtd_outl(0xb802C928,7);
	rtd_outl(0xb802C928,8);
	rtd_outl(0xb802C928,9);

	rtd_outl(0xb802C928,10);	//line 2
	rtd_outl(0xb802C928,11);
	rtd_outl(0xb802C928,12);
	rtd_outl(0xb802C928,13);
	rtd_outl(0xb802C928,14);
	rtd_outl(0xb802C928,15);
	rtd_outl(0xb802C928,16);
	rtd_outl(0xb802C928,17);
	rtd_outl(0xb802C928,18);

	rtd_outl(0xb802C928,19);	//line 3
	rtd_outl(0xb802C928,20);
	rtd_outl(0xb802C928,21);
	rtd_outl(0xb802C928,22);
	rtd_outl(0xb802C928,23);
	rtd_outl(0xb802C928,24);
	rtd_outl(0xb802C928,25);
	rtd_outl(0xb802C928,26);
	rtd_outl(0xb802C928,27);

	rtd_outl(0xb802C928,28);	//line 4
	rtd_outl(0xb802C928,29);
	rtd_outl(0xb802C928,30);
	rtd_outl(0xb802C928,31);
	rtd_outl(0xb802C928,32);
	rtd_outl(0xb802C928,33);
	rtd_outl(0xb802C928,34);
	rtd_outl(0xb802C928,35);
	rtd_outl(0xb802C928,36);

	rtd_outl(0xb802C928,37);	//line 5
	rtd_outl(0xb802C928,38);
	rtd_outl(0xb802C928,39);
	rtd_outl(0xb802C928,40);
	rtd_outl(0xb802C928,41);
	rtd_outl(0xb802C928,42);
	rtd_outl(0xb802C928,43);
	rtd_outl(0xb802C928,44);
	rtd_outl(0xb802C928,45);

	rtd_outl(0xb802C928,46);	//line 6
	rtd_outl(0xb802C928,47);
	rtd_outl(0xb802C928,48);
	rtd_outl(0xb802C928,49);
	rtd_outl(0xb802C928,50);
	rtd_outl(0xb802C928,51);
	rtd_outl(0xb802C928,52);
	rtd_outl(0xb802C928,53);
	rtd_outl(0xb802C928,54);

	rtd_outl(0xb802C928,55);	//line 7
	rtd_outl(0xb802C928,56);
	rtd_outl(0xb802C928,57);
	rtd_outl(0xb802C928,58);
	rtd_outl(0xb802C928,59);
	rtd_outl(0xb802C928,60);
	rtd_outl(0xb802C928,61);
	rtd_outl(0xb802C928,62);
	rtd_outl(0xb802C928,63);

	rtd_outl(0xb802C928,64);	//line 8
	rtd_outl(0xb802C928,65);
	rtd_outl(0xb802C928,66);
	rtd_outl(0xb802C928,67);
	rtd_outl(0xb802C928,68);
	rtd_outl(0xb802C928,69);
	rtd_outl(0xb802C928,70);
	rtd_outl(0xb802C928,71);
	rtd_outl(0xb802C928,72);

	rtd_outl(0xb802C928,73);	//line 9
	rtd_outl(0xb802C928,74);
	rtd_outl(0xb802C928,75);
	rtd_outl(0xb802C928,76);
	rtd_outl(0xb802C928,77);
	rtd_outl(0xb802C928,78);
	rtd_outl(0xb802C928,79);
	rtd_outl(0xb802C928,80);
	rtd_outl(0xb802C928,81);

	rtd_outl(0xb802C928,82);	//line 10
	rtd_outl(0xb802C928,83);
	rtd_outl(0xb802C928,84);
	rtd_outl(0xb802C928,85);
	rtd_outl(0xb802C928,86);
	rtd_outl(0xb802C928,87);
	rtd_outl(0xb802C928,88);
	rtd_outl(0xb802C928,89);
	rtd_outl(0xb802C928,90);

	rtd_outl(0xb802C928,0x00);	//data : start_ID_high : 0x00
	rtd_outl(0xb802C928,0xff);	//data : start_ID_low : 0xff
	rtd_outl(0xb802C928,0x01);	//data : cmd, bit0-3 enable

	rtd_outl(0xb802C928,0xff);	//data : end_ID_high : 0xff
	rtd_outl(0xb802C928,0xff);	//data : end_ID_low : 0xff


	#if 0
	ldspi_data_rwport_RBUS ldspi_data_rwport;
	ldspi_data_rwport.regValue = IoReg_Read32(LDSPI_Data_Rwport_reg);
	ldspi_data_rwport.data_rw_data_port=nValue;
	IoReg_Write32(LDSPI_Data_Rwport_reg, ldspi_data_rwport.regValue);
	#else
	rtd_outl(0xb802C928,0xfe);		//data : for fix bl=254
	#endif

	//checksum :
	rtd_part_outl(0xb802C900,2,2,0x1); //Send_follow_Vsync
	rtd_part_outl(0xb802C900,0,0,0x1); //Ld_spi enable



}
void drvif_color_Set_Local_Dimming_Off(unsigned char nValue)
{

	rtd_part_outl(0xb802C900,0,0,0x0);		//Ld_spi disable

	//---Script Start---

	//-------------------------
	//	LD SPI Pin Share
	//-------------------------
	rtd_part_outl(0xb8000888,31,28,0x5);	//ld_spi0_p1_cs1,<O>			gpio147 (Ball_AT38)
	rtd_part_outl(0xb8000888,15,12,0x5);	//ld_spi0_p5_v_sync,<O> 		gpio151 (Ball_AP36)
	rtd_part_outl(0xb8000888,27,24,0x5);	//ld_spi0_p2_sck_src3,<I/O> 	gpio148 (Ball_AR36)
	rtd_part_outl(0xb80008b4,27,25,0x3);	//sck_pin_mux src3
	rtd_part_outl(0xb8000888,23,20,0x5);	//ld_spi0_p3_sdo_SRC3,<I/O> 	gpio149 (Ball_AR38)
	rtd_part_outl(0xb80008b4,24,22,0x3);	//sdo_pin_mux src3


	//-------------------------
	//	LD InterFace Init
	//-------------------------
	rtd_part_outl(0xb802C900,31,30,0x1);	//LGD mode(default)
	rtd_part_outl(0xb802C900,4,4,0x1);		//LD_SPI1
	rtd_part_outl(0xb802C900,3,3,0x0);		//one SPI local dimming block

	rtd_part_outl(0xb802C904,31,31,0x1);	//First received bit or transmitted bit is in the MSB of SRAM or register
	rtd_part_outl(0xb802C904,13,4,0x70);	//Output Unit:8 unit(= set+1)	  Output Unit:113 unit(= set+1)
	rtd_part_outl(0xb802C904,1,0,0x0);		//Output_Data_format:8 bit

	rtd_part_outl(0xb802C908,23,16,0x4f);	//SCK_H
	rtd_part_outl(0xb802C908,7,0,0x4f); 	//SCK_L
	rtd_part_outl(0xb802C90c,31,8,0xea60);	//Data_send_Delay
	rtd_part_outl(0xb802C910,31,8,0xd4c);	//Each_unit_delay
	rtd_part_outl(0xb802C914,31,24,0x32);	//Vsync_d
	rtd_part_outl(0xb802C918,24,16,0x4f);	//Data_hold_time, must to set equal SCK_H!!!


	//------------------------------
	//	LD Data Output Index SRAM
	//------------------------------
	rtd_outl(0xb802C91c,0x00);		//Output data index RW_port pointer set

	rtd_outl(0xb802C920,0x5a);		//Start_ID 1st byte
	rtd_outl(0xb802C920,0x5b);		//Start_ID 2nd byte
	rtd_outl(0xb802C920,0x5c);		//command

	rtd_outl(0xb802C920,0x5f);		//col 1
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);// 9 block repeat to 18 block


	rtd_outl(0xb802C920,0x5f);// col 2
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);

	rtd_outl(0xb802C920,0x5f);// col 3
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);

	rtd_outl(0xb802C920,0x5f);// col 4
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);

	rtd_outl(0xb802C920,0x5f);// col 5
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);

	rtd_outl(0xb802C920,0x5f);// col 6
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);

	rtd_outl(0xb802C920,0x5f);// col 7
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);

	rtd_outl(0xb802C920,0x5f);// col 8
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);

	rtd_outl(0xb802C920,0x5f);// col 9
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);

	rtd_outl(0xb802C920,0x5f);// col 10
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);
	rtd_outl(0xb802C920,0x5f);// 9 block repeat to 18 block

	rtd_outl(0xb802C920,0x5d);		//End_ID 1st byte
	rtd_outl(0xb802C920,0x5e);		//End_ID 2nd byte


	//------------------------------
	//	LD Data SRAM
	//------------------------------

	rtd_outl(0xb802C924,0x00);	//Data RW_port pointer set


	rtd_outl(0xb802C928,1); 	//line 1
	rtd_outl(0xb802C928,2);
	rtd_outl(0xb802C928,3);
	rtd_outl(0xb802C928,4);
	rtd_outl(0xb802C928,5);
	rtd_outl(0xb802C928,6);
	rtd_outl(0xb802C928,7);
	rtd_outl(0xb802C928,8);
	rtd_outl(0xb802C928,9);

	rtd_outl(0xb802C928,10);	//line 2
	rtd_outl(0xb802C928,11);
	rtd_outl(0xb802C928,12);
	rtd_outl(0xb802C928,13);
	rtd_outl(0xb802C928,14);
	rtd_outl(0xb802C928,15);
	rtd_outl(0xb802C928,16);
	rtd_outl(0xb802C928,17);
	rtd_outl(0xb802C928,18);

	rtd_outl(0xb802C928,19);	//line 3
	rtd_outl(0xb802C928,20);
	rtd_outl(0xb802C928,21);
	rtd_outl(0xb802C928,22);
	rtd_outl(0xb802C928,23);
	rtd_outl(0xb802C928,24);
	rtd_outl(0xb802C928,25);
	rtd_outl(0xb802C928,26);
	rtd_outl(0xb802C928,27);

	rtd_outl(0xb802C928,28);	//line 4
	rtd_outl(0xb802C928,29);
	rtd_outl(0xb802C928,30);
	rtd_outl(0xb802C928,31);
	rtd_outl(0xb802C928,32);
	rtd_outl(0xb802C928,33);
	rtd_outl(0xb802C928,34);
	rtd_outl(0xb802C928,35);
	rtd_outl(0xb802C928,36);

	rtd_outl(0xb802C928,37);	//line 5
	rtd_outl(0xb802C928,38);
	rtd_outl(0xb802C928,39);
	rtd_outl(0xb802C928,40);
	rtd_outl(0xb802C928,41);
	rtd_outl(0xb802C928,42);
	rtd_outl(0xb802C928,43);
	rtd_outl(0xb802C928,44);
	rtd_outl(0xb802C928,45);

	rtd_outl(0xb802C928,46);	//line 6
	rtd_outl(0xb802C928,47);
	rtd_outl(0xb802C928,48);
	rtd_outl(0xb802C928,49);
	rtd_outl(0xb802C928,50);
	rtd_outl(0xb802C928,51);
	rtd_outl(0xb802C928,52);
	rtd_outl(0xb802C928,53);
	rtd_outl(0xb802C928,54);

	rtd_outl(0xb802C928,55);	//line 7
	rtd_outl(0xb802C928,56);
	rtd_outl(0xb802C928,57);
	rtd_outl(0xb802C928,58);
	rtd_outl(0xb802C928,59);
	rtd_outl(0xb802C928,60);
	rtd_outl(0xb802C928,61);
	rtd_outl(0xb802C928,62);
	rtd_outl(0xb802C928,63);

	rtd_outl(0xb802C928,64);	//line 8
	rtd_outl(0xb802C928,65);
	rtd_outl(0xb802C928,66);
	rtd_outl(0xb802C928,67);
	rtd_outl(0xb802C928,68);
	rtd_outl(0xb802C928,69);
	rtd_outl(0xb802C928,70);
	rtd_outl(0xb802C928,71);
	rtd_outl(0xb802C928,72);

	rtd_outl(0xb802C928,73);	//line 9
	rtd_outl(0xb802C928,74);
	rtd_outl(0xb802C928,75);
	rtd_outl(0xb802C928,76);
	rtd_outl(0xb802C928,77);
	rtd_outl(0xb802C928,78);
	rtd_outl(0xb802C928,79);
	rtd_outl(0xb802C928,80);
	rtd_outl(0xb802C928,81);

	rtd_outl(0xb802C928,82);	//line 10
	rtd_outl(0xb802C928,83);
	rtd_outl(0xb802C928,84);
	rtd_outl(0xb802C928,85);
	rtd_outl(0xb802C928,86);
	rtd_outl(0xb802C928,87);
	rtd_outl(0xb802C928,88);
	rtd_outl(0xb802C928,89);
	rtd_outl(0xb802C928,90);

	rtd_outl(0xb802C928,0x00);	//data : start_ID_high : 0x00
	rtd_outl(0xb802C928,0xff);	//data : start_ID_low : 0xff
	rtd_outl(0xb802C928,0x01);	//data : cmd, bit0-3 enable

	rtd_outl(0xb802C928,0xff);	//data : end_ID_high : 0xff
	rtd_outl(0xb802C928,0xff);	//data : end_ID_low : 0xff


	#if 0
	ldspi_data_rwport_RBUS ldspi_data_rwport;
	ldspi_data_rwport.regValue = IoReg_Read32(LDSPI_Data_Rwport_reg);
	ldspi_data_rwport.data_rw_data_port=nValue;
	IoReg_Write32(LDSPI_Data_Rwport_reg, ldspi_data_rwport.regValue);
	#else
	rtd_outl(0xb802C928,0xfe);		//data : for fix bl=254
	#endif

	//checksum :
	rtd_part_outl(0xb802C900,2,2,0x1); //Send_follow_Vsync
	rtd_part_outl(0xb802C900,0,0,0x1); //Ld_spi enable


}

void drvif_color_Local_Dimming_Init(unsigned char nValue)
{

	// This script is for skyworth 108 regions backlight test

	rtd_part_outl(0xb802C900,0,0,0x0); // Ld_spi disable



	// LD algo setting
	rtd_part_outl(0xb802C268,31,25,0x3);
	// BLU WR NUM = 3
	rtd_part_outl(0xb802C268,24,16,0x59);
	// SPI total = 89
	rtd_part_outl(0xb802C268,7,0,0x10);
	// BLU gain = 16
	rtd_part_outl(0xb802C208,0,0,0x1);
	// LD valid

	rtd_part_outl(0xb802C268,9,9,0x1);
	// SPI enable
	rtd_part_outl(0xb802C294,1,1,0x0);
	// SW off
	//rtd_part_outl(0xb802c200,31,31,0x0);
	// Comp off

	rtd_part_outl(0xb802c208,1,1,0x1);
	// LD_T_Enable
	rtd_part_outl(0xb802c208,5,4,0x0);
	// direct-lit type
	rtd_part_outl(0xb802c204,31,31,0x0);
	// db off
	rtd_part_outl(0xb802c208,28,24,0x8);
	// Hunm
	rtd_part_outl(0xb802c208,20,16,0x9);
	// Vunm
	rtd_part_outl(0xb802c20c,28,16,0x1aa);
	// Hsize 3840/9 = 426.666 = 426
	rtd_part_outl(0xb802c20c,11,0,0xD8);
	// Vsize 2160/10 = 216

	rtd_part_outl(0xb802c23c,29,24,0x1e);
	// max gain
	rtd_part_outl(0xb802c23c,20,16,0x1e);
	// avg gain
	rtd_part_outl(0xb802c23c,3,0,0x5);
	// hist shift bit
	rtd_part_outl(0xb802c240,29,24,0x2);
	// hist0 gain
	rtd_part_outl(0xb802c240,21,16,0xa);
	// hist1 gain
	rtd_part_outl(0xb802c240,13,8,0xb);
	// hist2 gain
	rtd_part_outl(0xb802c240,5,0,0xc);
	// hist3 gain
	rtd_part_outl(0xb802c244,29,24,0xc);
	// hist4 gain
	rtd_part_outl(0xb802c244,21,16,0xc);
	// hist5 gain
	rtd_part_outl(0xb802c244,13,8,0xc);
	// hist6 gain
	rtd_part_outl(0xb802c244,5,0,0xc);
	// hist7 gain

	// backlight decision
	rtd_outl(0xb802c23c, 0x1e1e0006);
	rtd_outl(0xb802c240, 0x000a0b0c);
	rtd_outl(0xb802c244, 0x0c0c0c0c);

	// temporal filter
	rtd_outl(0xb802c25c, 0x08300418);
	rtd_outl(0xb802c260, 0x08300210);
	rtd_outl(0xb802c264, 0x00400400);

	rtd_outl(0xb802c250, 0x00000000);
	rtd_outl(0xb802c254, 0x00000001);


	rtd_part_outl(0xb802c2e8,9,0,0x00000000);  //rtd_part_outl(0xb802c2e8,9,0,0x00000004);
	#if 1
	{
	blu_ld_spatial_ctrl3_RBUS blu_ld_spatial_ctrl3;
	unsigned long temp = 0;
	int nIndex =0;

	VIPprintf("\n---BL Value(0-255)--- =%d \n", nValue);

	for(nIndex =0;nIndex<32 ;nIndex++){
		blu_ld_spatial_ctrl3.ld_spatialremapadr = nIndex;

		temp = nIndex << 5;
		temp += nIndex;
		temp = (temp * nValue) >> 8;

		blu_ld_spatial_ctrl3.ld_spatialremaptab0 = temp;
		blu_ld_spatial_ctrl3.ld_spatialremaptab1 = temp;

//		VIPprintf("---lhh--- table_1[%d]=%x\n", nIndex,blu_ld_spatial_ctrl3.ld_spatialremaptab1);

		IoReg_Write32(BLU_LD_Spatial_Ctrl3_reg, blu_ld_spatial_ctrl3.regValue);
	}
	}
	#else

	rtd_outl(0xb802c258,0x00020010);//  1
	rtd_outl(0xb802c258,0x01040030);
	rtd_outl(0xb802c258,0x02060050);
	rtd_outl(0xb802c258,0x03080070);
	rtd_outl(0xb802c258,0x040a0090);
	rtd_outl(0xb802c258,0x050c00b0);
	rtd_outl(0xb802c258,0x060e00d0);
	rtd_outl(0xb802c258,0x071000f0);
	rtd_outl(0xb802c258,0x08120110);
	rtd_outl(0xb802c258,0x09140130);  //10
	rtd_outl(0xb802c258,0x0a160150);
	rtd_outl(0xb802c258,0x0b180170);
	rtd_outl(0xb802c258,0x0c1a0190);
	rtd_outl(0xb802c258,0x0d1c01b0);
	rtd_outl(0xb802c258,0x0e1e01d0);
	rtd_outl(0xb802c258,0x0f2001f0);
	rtd_outl(0xb802c258,0x10220210);
	rtd_outl(0xb802c258,0x11240230);
	rtd_outl(0xb802c258,0x12260250);
	rtd_outl(0xb802c258,0x13280270);  //20
	rtd_outl(0xb802c258,0x142a0290);
	rtd_outl(0xb802c258,0x152c02b0);
	rtd_outl(0xb802c258,0x162e02d0);
	rtd_outl(0xb802c258,0x173002f0);
	rtd_outl(0xb802c258,0x18320310);
	rtd_outl(0xb802c258,0x19340330);
	rtd_outl(0xb802c258,0x1a360350);
	rtd_outl(0xb802c258,0x1b380370);
	rtd_outl(0xb802c258,0x1c3a0390);
	rtd_outl(0xb802c258,0x1d3c03b0);  //30
	rtd_outl(0xb802c258,0x1e3e03d0);
	rtd_outl(0xb802c258,0x1f3fc3f0);  //32
	#endif

	rtd_part_outl(0xb802C900,0,0,0x1); // Ld_spi enable

}




