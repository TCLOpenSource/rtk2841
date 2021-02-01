/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2014
  * All rights reserved.
  * ========================================================================*/
  /*================= File Description =======================================*/
  /**
   * @file
   *  This file is for Local Contrast related functions.
   *
   * @author  $Author$
   * @date	  $Date$
   * @version	  $Revision$
   */


  /*============================ Module dependency	===========================*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <linux/string.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <linux/kernel.h>
#include "tvscalercontrol/vip/still_logo_detect.h"
#include <tvscalercontrol/scaler/vipinclude.h> // for typedef that used in VIP_reg_def.h
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <mach/rtk_log.h>
#define TAG_NAME "VPQ"
#else
#include <unistd.h>		// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
#include <sys/ioctl.h>

#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
#include <Platform_Lib/TVScalerControl/vip/still_logo_detect.h>
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>
#endif

#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ##args)//printk(KERN_DEBUG fmt, ##args)
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#endif

#define SLD_Debug 0

// Function Description : This function is for SLD enable
//juwen, 0603, done
void drvif_color_set_SLD_Enable(unsigned char enable)
{
return;
#ifdef MAC5_NO_SLD
	color_sld_sld_control_RBUS color_sld_control;
	color_sld_control.regValue = IoReg_Read32(COLOR_SLD_SLD_CONTROL_reg);

	color_sld_control.sld_en= enable;

	#ifdef SLD_Debug
	VIPprintf("sld_valid = %d\n",color_sld_control.sld_en);
	#endif

	IoReg_Write32(COLOR_SLD_SLD_CONTROL_reg, color_sld_control.regValue);
#endif
}
#ifdef MAC5_NO_SLD
#if 1/*SLD, hack, elieli*/
//juwen, 0603, done
void drvif_color_set_SLD_control(DRV_SLD_Ctrl *ptr)
{
	color_sld_sld_control_RBUS color_sld_control;
	color_sld_control.regValue = IoReg_Read32(COLOR_SLD_SLD_CONTROL_reg);

	color_sld_control.sld_en = ptr->sld_en;
	color_sld_control.sld_blend_en= ptr->sld_blend_en;
	color_sld_control.sld_global_drop= ptr->sld_global_drop;
	color_sld_control.sld_hpf_type= ptr->sld_hpf_type;
	color_sld_control.sld_hpf_thl= ptr->sld_hpf_thl;
	color_sld_control.sld_scale_mode= ptr->sld_scale_mode;

	IoReg_Write32(COLOR_SLD_SLD_CONTROL_reg, color_sld_control.regValue);

}

//juwen, 0603
void drvif_color_set_SLD_input_size(DRV_SLD_Size *ptr)
{
	color_sld_sld_size_RBUS color_sld_size;

	color_sld_size.regValue = IoReg_Read32(COLOR_SLD_SLD_SIZE_reg);

	color_sld_size.sld_height = ptr->sld_height;
	color_sld_size.sld_width = ptr->sld_width;

	IoReg_Write32(COLOR_SLD_SLD_SIZE_reg,color_sld_size.regValue);

}

//juwen, 0603
void drvif_color_set_SLD_curve_map(DRV_SLD_CurveMap *ptr)
{
	color_sld_sld_curve_map_seg_RBUS color_sld_curve_map_seg;
	color_sld_sld_curve_map_gain_RBUS color_sld_curve_map_gain;
	color_sld_sld_curve_map_offset_0_RBUS color_sld_curve_map_offset_0;
	color_sld_sld_curve_map_offset_1_RBUS color_sld_curve_map_offset_1;

	color_sld_curve_map_seg.regValue = IoReg_Read32(COLOR_SLD_SLD_CURVE_MAP_SEG_reg);
	color_sld_curve_map_gain.regValue =IoReg_Read32(COLOR_SLD_SLD_CURVE_MAP_GAIN_reg);
	color_sld_curve_map_offset_0.regValue =IoReg_Read32(COLOR_SLD_SLD_CURVE_MAP_OFFSET_0_reg);
	color_sld_curve_map_offset_1.regValue =IoReg_Read32(COLOR_SLD_SLD_CURVE_MAP_OFFSET_1_reg);

	color_sld_curve_map_seg.sld_curve_seg_0 = ptr->sld_curve_seg_0;
	color_sld_curve_map_seg.sld_curve_seg_1 =  ptr->sld_curve_seg_1;

	color_sld_curve_map_gain.sld_curve_gain_0 = 	ptr->sld_curve_gain_0;
	color_sld_curve_map_gain.sld_curve_gain_1 = 	ptr->sld_curve_gain_1;
	color_sld_curve_map_gain.sld_curve_gain_2 = 	ptr->sld_curve_gain_2;

	color_sld_curve_map_offset_0.sld_curve_offset_0 = ptr->sld_curve_offset_0;
	color_sld_curve_map_offset_0.sld_curve_offset_1 = ptr->sld_curve_offset_1;

	color_sld_curve_map_offset_1.sld_curve_offset_2 = ptr->sld_curve_offset_2;

	IoReg_Write32(COLOR_SLD_SLD_CURVE_MAP_SEG_reg, color_sld_curve_map_seg.regValue);
	IoReg_Write32(COLOR_SLD_SLD_CURVE_MAP_GAIN_reg, color_sld_curve_map_gain.regValue);
	IoReg_Write32(COLOR_SLD_SLD_CURVE_MAP_OFFSET_0_reg, color_sld_curve_map_offset_0.regValue);
	IoReg_Write32(COLOR_SLD_SLD_CURVE_MAP_OFFSET_1_reg, color_sld_curve_map_offset_1.regValue);

}

//juwen, 0603
void drvif_color_set_SLD_drop(DRV_SLD_DROP *ptr)
{
	color_sld_sld_drop_RBUS color_sld_drop;

	color_sld_drop.regValue = IoReg_Read32(COLOR_SLD_SLD_DROP_reg);

	color_sld_drop.sld_cnt_thl = ptr->sld_cnt_thl;
	color_sld_drop.sld_hpf_diff_thl = ptr->sld_hpf_diff_thl;
	color_sld_drop.sld_pixel_diff_thl = ptr->sld_pixel_diff_thl;

	IoReg_Write32(COLOR_SLD_SLD_DROP_reg, color_sld_drop.regValue);
	
}
#endif
#endif

//juwen, 0603
//?????????read only need driver????????????????????????????????????????????????????????
void drvif_color_count_read_only(unsigned short sld_logo_cnt, unsigned short sld_drop_cnt)
{
	return;
	#ifdef MAC5_NO_SLD
	color_sld_sld_cnt_0_RBUS color_sld_read_only_logo_cnt;
	color_sld_sld_cnt_1_RBUS color_sld_read_only_drop_cnt;

	color_sld_read_only_logo_cnt.regValue = IoReg_Read32(COLOR_SLD_SLD_CNT_0_reg);
	color_sld_read_only_drop_cnt.regValue = IoReg_Read32(COLOR_SLD_SLD_CNT_1_reg);
/*
	color_sld_drop.sld_cnt_thl = ptr->sld_cnt_thl;
	color_sld_drop.sld_hpf_diff_thl = ptr->sld_hpf_diff_thl;
	color_sld_drop.sld_pixel_diff_thl = ptr->sld_pixel_diff_thl;

	IoReg_Write32(COLOR_SLD_SLD_CNT_0_reg, color_sld_read_only_logo_cnt.regValue);
	IoReg_Write32(COLOR_SLD_SLD_CNT_1_reg, color_sld_read_only_drop_cnt.regValue);
*/
	#endif
}


