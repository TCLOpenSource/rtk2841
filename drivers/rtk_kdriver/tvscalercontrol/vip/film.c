/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for FILM related functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version 	$Revision$
 */

/**
 * @addtogroup film
 * @{
 */

/*============================ Module dependency  ===========================*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/vip/film.h>
#include <mach/rtk_log.h>
#define TAG_NAME "VPQ"
#else
//#include "rtd_regs.h"
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerStruct.h>
#include <Platform_Lib/TVScalerControl/vip/film.h>

/*
#include "scaler/film.h"
#include "VIP/VIP_reg_def.h"
#include "dragon.h"
*/
#endif
/*===================================  Types ================================*/

/*================================== Variables ==============================*/

/*================================ Definitions ==============================*/



#if 0

 unsigned char  tFILM_INIT[] = {
	0x04, 0x00, 0xff, 0x02,            /* select page 2*/
	/* source size*/
	0x04, 0x00, RSPI_GETADDRESS(_P2_00_ACTIVEWINDOWCTRL_MSB), 0xb0,
	0x04, 0x00, RSPI_GETADDRESS(_P2_01_ACTIVEWINDOWCTRL_H_LSB), 0xd0,
	0x04, 0x00, RSPI_GETADDRESS(_P2_02_ACTIVEWINDOWCTRL_V_LSB), 0xf0,
	0x04, 0x00, RSPI_GETADDRESS(_P2_03_ACTIVEWINDOWCTRL_B_LSB), 0x8a,

	/* film control*/
	0x04, 0x00, RSPI_GETADDRESS(_P2_13_IP_FILM_MODE), 0xbf,
	/* film threshold*/
	0x04, 0x00, RSPI_GETADDRESS(_P2_79_), 0x10,
	0x04, 0x00, RSPI_GETADDRESS(_P2_7A_), 0x10,
	0x04, 0x00, RSPI_GETADDRESS(_P2_7B_), 0x15,
	0x04, 0x00, RSPI_GETADDRESS(_P2_7C_), 0x14,
	0x04, 0x00, RSPI_GETADDRESS(_P2_7D_), 0x78,
	0x04, 0x00, RSPI_GETADDRESS(_P2_7E_), 0x13,
	0x04, 0x00, RSPI_GETADDRESS(_P2_7F_), 0x88,
	0x04, 0x00, RSPI_GETADDRESS(_P2_80_), 0x0f,
	0x04, 0x00, RSPI_GETADDRESS(_P2_81_), 0x14,
	0x04, 0x00, RSPI_GETADDRESS(_P2_82_), 0x32,
	0x04, 0x00, RSPI_GETADDRESS(_P2_83_), 0x07,
	0x04, 0x00, RSPI_GETADDRESS(_P2_84_), 0xd0,
	0
  };



/*=====================Init Table===================*/

UINT32 film32_init_table_TSB[26][2] = {
	/* SD		HD*/
	{	    2,       2  	},	/*Film_sawtooth_choose*/
	{	    0,       0  	},	/*Film LeaveQuick en*/
	{	    1,       1  	},	/*Film_VerScrollingText_en*/
	{	    0,       0         },	/*Film_thumbnail_en*/
	{	    1,       1  	},	/*Film_Pair1_en*/
	{	    0,       0  	},	/*Film_Pair2_en*/
	{	    0,       0  	},	/*Film_Pair_en_auto*/
	{	    1,       1  	},	/*Film_Violate_strict_en*/
	{	   22,     56	},	/*Film_SawtoothThl*/
	{	    18,      42	},	/*Film_FrMotionThl*/
	{	   40,     40	},	/*Film_FieldMotionSumThl*/
	{	   21,     21 	},	/*Film_FrStaticSThl*/
	{	   20,     20	},	/*Film_FiStaticSThl*/
	{	     8,       8	},	/*Film_PairRatio_all1*/
	{ 	     8,       8	},	/*Film_PairRatio_all2*/
	{	 120,     120	},	/*Film_FiMinSThl*/
	{	5000,   5000      },	/*Film_FiMaxSThl*/
	{	   40,       40	},	/*Film_SubFieldMotionSumThl*/
	{	   15,	       15     },	/*Film_SubFrStaticsSTh1*/
	{	   20,	       20     },	/*Film_SubFiStaticsSTh1*/
	{	     8,	        8      },	/*Film_PairRatio_sub1*/
	{	     8,	        8      },	/*Film_PairRatio_sub2*/
	{	   50,	      50      },	/*Film_SubFiMinSTh1*/
	{	2000,    2000    },	/*	Film_SubFiMaxSTh1*/
	{	   50,	       50     },	/*Film_SubFiMinSTh1*/
	{	    0,	        0      },	/*Film32_debounce_FieldNum*/
};

UINT32 film22_init_table_TSB[28][2] = {
	/* SD		HD*/
	{	2,		2	},	/*Film_sawtooth_choose*/
	{	0,		0	},	/*Film LeaveQuick en*/
	{	1,		1	},	/*Film_VerScrollingText_en*/
	{	0,		0	},	/*Film_thumbnail_en*/
	{	1,		1	},	/*Film_Pair1_en*/
	{	0,		0	},	/*Film_Pair2_en*/
	{	0,		0	},	/*Film_Pair_en_auto*/
	{	1,		1	},	/*Film_Violate_strict_en*/
	{	60,		60	},	/*Film22_SawtoothTh1*/
	{	22,		26	},	/*Film_SawtoothThl*/
	{	16,		16	},	/*Film_FrMotionThl*/
	{	40,		40	},	/*Film_FieldMotionSumThl*/
	{	20,		20	},	/*Film22_FiStaticSTh1*/
	{	21,		21	},	/*Film_FrStaticSThl*/
	{	8,		8	},	/*Film_PairRatio_all1*/
	{	8,		8	},	/*Film_PairRatio_all2*/
	{	120,		120	},	/*Film_FiMinSThl*/
	{	5000,	5000},	/*Film_FiMaxSThl*/
	{	40,		40	},	/*Film_SubFieldMotionSumThl*/
	{	20,		20	},	/*Film_SubFiStaticSTh1*/
	{	15,		15	},	/*Film_SubFrStaticsSTh1*/
	{	8,		8	},	/*Film_PairRatio_sub1*/
	{	8,		8	},	/*Film_PairRatio_sub2*/
	{	50,		50	},	/*Film_SubFiMinSTh1*/
	{	2000,	2000},	/*Film_SubFiMaxSTh1*/
	{	4,		4	},	/*Film22_debounce_FieldNum*/
	{	0,		0	},	/*Film22_SubFieldMotionSumThl*/
	{	40,		40	},	/*Film22_FieldMotionSumThl*/
};

UINT32 film32_init_table[27][2] = {
	/* SD		HD*/
	{	    2,       2  	},	/*Film_sawtooth_choose*/
	{	    0,       0  	},	/*Film LeaveQuick en*/
	{	    1,       1  	},	/*Film_VerScrollingText_en*/
	{	    0,       0         },	/*Film_thumbnail_en*/
	{	    1,       1  	},	/*Film_Pair1_en*/
	{	    0,       0  	},	/*Film_Pair2_en*/
	{	    0,       0  	},	/*Film_Pair_en_auto*/
	{	    1,       1  	},	/*Film_Violate_strict_en*/
	{	   22,     56	},	/*Film_SawtoothThl*/
	{	    18,      42	},	/*Film_FrMotionThl*/
	{	   40,     40	},	/*Film_FieldMotionSumThl*/
	{	   21,     21 	},	/*Film_FrStaticSThl*/
	{	   20,     20	},	/*Film_FiStaticSThl*/
	{	     8,       8	},	/*Film_PairRatio_all1*/
	{ 	     8,       8	},	/*Film_PairRatio_all2*/
	{	 120,     120	},	/*Film_FiMinSThl*/
	{	5000,   5000      },	/*Film_FiMaxSThl*/
	{	   40,       40	},	/*Film_SubFieldMotionSumThl*/
	{	   15,	       15     },	/*Film_SubFrStaticsSTh1*/
	{	   20,	       20     },	/*Film_SubFiStaticsSTh1*/
	{	     8,	        8      },	/*Film_PairRatio_sub1*/
	{	     8,	        8      },	/*Film_PairRatio_sub2*/
	{	   50,	      50      },	/*Film_SubFiMinSTh1*/
	{	2000,    2000    },	/*	Film_SubFiMaxSTh1*/
	{	   50,	       50     },	/*Film_SubFiMinSTh1*/
	{	    0,	        0      },	/*Film32_debounce_FieldNum*/
	{	1,		0	},	/*fw film enable*/
};

UINT32 film22_init_table[29][2] = {
	/* SD		HD*/
	{	2,		2	},	/*Film_sawtooth_choose*/
	{	0,		0	},	/*Film LeaveQuick en*/
	{	1,		1	},	/*Film_VerScrollingText_en*/
	{	0,		0	},	/*Film_thumbnail_en*/
	{	1,		1	},	/*Film_Pair1_en*/
	{	0,		0	},	/*Film_Pair2_en*/
	{	0,		0	},	/*Film_Pair_en_auto*/
	{	1,		1	},	/*Film_Violate_strict_en*/
	{	60,		60	},	/*Film22_SawtoothTh1*/
	{	22,		26	},	/*Film_SawtoothThl*/
	{	16,		16	},	/*Film_FrMotionThl*/
	{	40,		40	},	/*Film_FieldMotionSumThl*/
	{	20,		20	},	/*Film22_FiStaticSTh1*/
	{	21,		21	},	/*Film_FrStaticSThl*/
	{	8,		8	},	/*Film_PairRatio_all1*/
	{	8,		8	},	/*Film_PairRatio_all2*/
	{	120,		120	},	/*Film_FiMinSThl*/
	{	5000,	5000},	/*Film_FiMaxSThl*/
	{	40,		40	},	/*Film_SubFieldMotionSumThl*/
	{	20,		20	},	/*Film_SubFiStaticSTh1*/
	{	15,		15	},	/*Film_SubFrStaticsSTh1*/
	{	8,		8	},	/*Film_PairRatio_sub1*/
	{	8,		8	},	/*Film_PairRatio_sub2*/
	{	50,		50	},	/*Film_SubFiMinSTh1*/
	{	2000,	2000},	/*Film_SubFiMaxSTh1*/
	{	4,		4	},	/*Film22_debounce_FieldNum*/
	{	0,		0	},	/*Film22_SubFieldMotionSumThl*/
	{	40,		40	},	/*Film22_FieldMotionSumThl*/
	{	1,		0	},	/*fw film enable*/
};
#endif
/*================================== Function ===============================*/

/*o---------------------------------------------------o*/
/*      FILM_init*/
/*      ==> to initialize the FILM setting*/
/*      @param  {none}*/
/*      @return {none}*/
/*o---------------------------------------------------o*/
void drvif_module_film_init(unsigned char display)  /*nick187    many error should be fixed.....*/
{
/*	unsigned short    Width, Height,Blank;*/
	di_im_di_control_RBUS di_control_reg;
	di_im_di_film_sawtooth_filmframe_th_RBUS film_sawtooth_filmframe_th_reg;
	di_im_di_film_static_sum_th_RBUS film_static_sum_th_reg;
	di_im_di_film_field_judge_th_RBUS film_field_judge_th_reg;
	di_im_di_film_static_sum_sub_th_RBUS film_static_sum_sub_th_reg;
	di_im_di_film_field_judge_sub_th_RBUS film_field_judge_sub_th_reg;

	/* fw film setting*/
	di_im_di_film_new_function_main_RBUS film_new_function_main_reg;

/*	Width  = info->CapWid;*/
/*	Height = info->IPV_ACT_LEN;*/
/*	Blank = info->IHTotal - Width;*/
	/* FILM main/sub select*/
	/*tFILM_INIT[3]  = 0x2 + ((info->display)<<3);       */ /* main/sub*/
    /* source size*/
	/*tFILM_INIT[7]  = 0x80 | (Width>>8)<<4 | (Height>>8)<<2 | (Blank >> 8) ;*/
	/*tFILM_INIT[11] = Width & 0xff;*/
	/*tFILM_INIT[15] = Height & 0xff;*/

	/*tFILM_INIT[19] = 0x8a;*/
	/*tFILM_INIT[19] = Blank & 0xff;*/

	/* set register*/
	/*----------> Rspi_CodeW(tFILM_INIT);*/

	di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
/*-->w	di_control_reg.ip_enable = 1;*/
	/*di_control_reg.ma_3aenable = (Width>=960)?1:0;*/
	di_control_reg.film_enable = 0x1f; // write_enable[16]

	/* henry @ mac5 161219 DI write enable bit */
	//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_5_mask;
	di_control_reg.write_enable_5 = 1;

	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
	film_sawtooth_filmframe_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg);
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 0xc;  /* 20140226 chris modify need to be check*/
	/*film_sawtooth_filmframe_th_reg.film_frmotionthl = 0x10;*/
	film_sawtooth_filmframe_th_reg.film_leavequick_en = 0; /* 20110419 by flora*/
	IoReg_Write32(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg, film_sawtooth_filmframe_th_reg.regValue);

	film_static_sum_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_STATIC_SUM_TH_reg);
	film_static_sum_th_reg.film22_fistaticsthl = 0x14; /* for demo*/
	film_static_sum_th_reg.film_frstaticsthl = 0x15;
	film_static_sum_th_reg.film_fistaticsthl = 0x14;
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_TH_reg, film_static_sum_th_reg.regValue);

	film_field_judge_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_FIELD_JUDGE_TH_reg);
	film_field_judge_th_reg.film_fiminsthl = 0x78;
	film_field_judge_th_reg.film_fimaxsthl = 0x1388;
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_TH_reg, film_field_judge_th_reg.regValue);

	film_static_sum_sub_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_reg);
	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 0x28;
	film_static_sum_sub_th_reg.film22_subfistaticsthl = 0x14;
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 0x0f;
	film_static_sum_sub_th_reg.film_subfistaticsthl = 0x14;
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_reg, film_static_sum_sub_th_reg.regValue);


	film_field_judge_sub_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_reg);
	film_field_judge_sub_th_reg.film_subfiminsthl = 0x32;
	film_field_judge_sub_th_reg.film_subfimaxsthl = 0x07d0;
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_reg, film_field_judge_sub_th_reg.regValue);

	/* fw film setting*/
	film_new_function_main_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg);
	film_new_function_main_reg.fw_film_en = 0x1;
	film_new_function_main_reg.film_mixedfilm_margin = 0x2;
	film_new_function_main_reg.fw_film_reg_sel = 0x0;
	film_new_function_main_reg.badeditor_ratio = 0x2;
	film_new_function_main_reg.force_badeditor_en = 0x0;
	IoReg_Write32(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg, film_new_function_main_reg.regValue);

	/* film mask for 22 sequence */
	{
	di_im_di_film_mask_detection_RBUS film_mask_detection_reg;
	film_mask_detection_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_MASK_DETECTION_reg);
	film_mask_detection_reg.film_mask_en = 1;
	IoReg_Write32(DI_IM_DI_FILM_MASK_DETECTION_reg, film_mask_detection_reg.regValue);
	}

}
/*o---------------------------------------------------o*/
/*      FILM_enable*/
/*      ==> to enable FILM detection function*/
/*      @param <film_sel> { 0 ~ 3, default 3*/
/*                          0  : Disable*/
/*						    1  : 32 film enable*/
/*							2  : 32 + 32sub film enable*/
/*                          3  : 32 + 32sub + 22 film enable  }*/
/*      @return {none}*/
/*o---------------------------------------------------o*/

void drvif_module_film_mode(DRV_film_mode *ptr)
{
	di_im_di_control_RBUS di_control_reg;
	di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	di_control_reg.film_enable = ptr->film_status;// write_enable[16]

	/* henry @ mac5 161219 DI write enable bit */
	//di_control_reg.regValue = di_control_reg.regValue | DI_IM_DI_CONTROL_write_enable_5_mask;
	di_control_reg.write_enable_5 = 1;
	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
}


void drvif_module_film_setting(DRV_film_table_t *ptr)
{
	di_im_di_control_RBUS di_control_reg;
	di_im_di_film_sawtooth_filmframe_th_RBUS film_sawtooth_filmframe_th_reg;
	di_im_di_film_static_sum_th_RBUS film_static_sum_th_reg;
	di_im_di_film_field_judge_th_RBUS film_field_judge_th_reg;
	di_im_di_film_static_sum_sub_th_RBUS film_static_sum_sub_th_reg;
	di_im_di_film_field_judge_sub_th_RBUS film_field_judge_sub_th_reg;
	di_im_di_film_motion_sum_th_RBUS film_motion_sum_th_reg;
	di_im_di_film_new_function_main_RBUS film_new_function_main_reg;	/* fw film setting*/
	di_im_di_film_mask_detection_RBUS film_mask_detection_reg;

	di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
	film_sawtooth_filmframe_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg);
	film_static_sum_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_STATIC_SUM_TH_reg);
	film_field_judge_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_FIELD_JUDGE_TH_reg);
	film_static_sum_sub_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_reg);
	film_field_judge_sub_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_reg);
	film_motion_sum_th_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_MOTION_SUM_TH_reg);
	film_new_function_main_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg);	/* fw film setting*/
	film_mask_detection_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_MASK_DETECTION_reg);

	/*extern DRV_film32_table_t gFilm32InitTable[2];*/

	di_control_reg.film_sawtooth_choose = ptr->film_sawtooth_choose;

	film_sawtooth_filmframe_th_reg.film_leavequick_en = 			ptr->film_LeaveQuick_en;
	film_sawtooth_filmframe_th_reg.film_verscrollingtext_en = 		ptr->film_VerScrollingText_en;
	film_sawtooth_filmframe_th_reg.film_thumbnail_en = 			ptr->film_thumbnail_en;
	film_sawtooth_filmframe_th_reg.film_pair1_en = 				ptr->film_pair1_en;
	film_sawtooth_filmframe_th_reg.film_pair2_en = 				ptr->film_pair2_en;
	film_sawtooth_filmframe_th_reg.film_pair_en_auto = 			ptr->film_pair_en_auto;
	film_sawtooth_filmframe_th_reg.film_violate_strict_en = 			ptr->film_violate_strict_en;
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 				ptr->film_SawtoothThl;
	film_sawtooth_filmframe_th_reg.film22_sawtooththl = 			ptr->film_film22_SawtoothTh1;
	film_sawtooth_filmframe_th_reg.film_frmotionthl = 				ptr->film_FrMotionThl;

	film_static_sum_th_reg.film_fieldmotionsumthl = 		ptr->film_FieldMotionSumThl;
	film_static_sum_th_reg.film22_fistaticsthl = 			ptr->film_film22_FiStaticSThl;
	film_static_sum_th_reg.film_frstaticsthl = 				ptr->film_FrStaticSThl;
	film_static_sum_th_reg.film_fistaticsthl = 				ptr->film_FiStaticSThl;

	film_field_judge_th_reg.film_pairratio_all1 = 			ptr->film_PairRatio_all1;
	film_field_judge_th_reg.film_pairratio_all2 = 			ptr->film_PairRatio_all2;
	film_field_judge_th_reg.film_fiminsthl = 				ptr->film_FiMinSThl;
	film_field_judge_th_reg.film_fimaxsthl = 				ptr->film_FiMaxSThl;

	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 		ptr->film_SubFieldMotionSumThl;
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 			ptr->film_SubFrStaticsSTh1;
	film_static_sum_sub_th_reg.film_subfistaticsthl = 			ptr->film_SubFiStaticsSTh1;

	film_field_judge_sub_th_reg.film_pairratio_sub1 = 			ptr->film_PairRatio_sub1;
	film_field_judge_sub_th_reg.film_pairratio_sub2 = 			ptr->film_PairRatio_sub2;
	film_field_judge_sub_th_reg.film_subfiminsthl = 				ptr->film_SubFiMinSTh1;
	film_field_judge_sub_th_reg.film_subfimaxsthl = 			ptr->film_SubFiMaxSTh1;

	film_motion_sum_th_reg.film32_debounce_fieldnum = 		ptr->film_film32_debounce_fieldnum;
	film_motion_sum_th_reg.film22_debounce_fieldnum = 		ptr->film_film22_debounce_fieldnum;
	film_motion_sum_th_reg.film22_subfieldmotionsumthl = 	ptr->film_film22_SubFieldMotionSumThl;
	film_motion_sum_th_reg.film22_fieldmotionsumthl = 		ptr->film_film22_FieldMotionSumThl;

	film_new_function_main_reg.fw_film_en =	ptr->film_fw_en;
	film_new_function_main_reg.fw_film_doublebuffer_en = 0x1; 		/*jzl 20150815 for boundary issue*/

	film_mask_detection_reg.film_mask_en = 1;	/* jzl film mask for 22 sequence */

	IoReg_Write32(DI_IM_DI_CONTROL_reg, di_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_reg, film_sawtooth_filmframe_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_TH_reg, film_static_sum_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_TH_reg, film_field_judge_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_reg, film_static_sum_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_reg, film_field_judge_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_MOTION_SUM_TH_reg, film_motion_sum_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_reg, film_new_function_main_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_MASK_DETECTION_reg, film_mask_detection_reg.regValue);
}


/*============================================================================*/

/***************************************************
					Pseudo MEMC
****************************************************/

void drvif_module_32_pseudo_memc_select(unsigned char display, unsigned char mode_useless, unsigned char level)
{
	unsigned char mode, weight;
/*    Classify_Threshold_RBUS classify_threshold_reg;*/
	di_im_di_blend_and_weighting_method_RBUS blend_and_weighting_method_reg;

	mode =  level / 4;    /* range : 0~15*/
	weight = level % 4;  /* range : 0~3*/

	blend_and_weighting_method_reg.regValue = IoReg_Read32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg);
	blend_and_weighting_method_reg.pseudo_memc_en = (unsigned char)mode;
	blend_and_weighting_method_reg.pseudo_memc_film32_sequence = mode;
	blend_and_weighting_method_reg.pseudo_memc_film32_weight0 = weight;
	blend_and_weighting_method_reg.pseudo_memc_film32_weight1 = weight;
	blend_and_weighting_method_reg.pseudo_memc_film32_weight2 = weight;
	blend_and_weighting_method_reg.pseudo_memc_film32_weight3 = weight;
	IoReg_Write32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg, blend_and_weighting_method_reg.regValue);
}

void drvif_module_22_pseudo_memc_select(unsigned char display, unsigned char mode_useless, unsigned char level)   /* level range :0~15*/
{
	unsigned char mode, weight;
	di_im_di_classify_thclassify_threshold_RBUS classify_threshold_reg;
	di_im_di_blend_and_weighting_method_RBUS blend_and_weighting_method_reg;

	mode =  level / 4;    /* range : 0~3*/
	weight = level % 4;  /* range : 0~3*/

	classify_threshold_reg.regValue = IoReg_Read32(DI_IM_DI_CLASSIFY_THClassify_Threshold_reg);

	classify_threshold_reg.pseudo_memc_film22_sequence = mode;
	classify_threshold_reg.pseudo_memc_film22_weight0 = weight;
	classify_threshold_reg.pseudo_memc_film22_weight1 = weight;
	IoReg_Write32(DI_IM_DI_CLASSIFY_THClassify_Threshold_reg, classify_threshold_reg.regValue);

	blend_and_weighting_method_reg.regValue = IoReg_Read32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg);
	blend_and_weighting_method_reg.pseudo_memc_en = (unsigned char)mode;
	IoReg_Write32(DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_reg, blend_and_weighting_method_reg.regValue);
}

#if 0
void drvif_module_32film_enter_speed(unsigned char level)
{
}

void drvif_module_TSB_film32_init(UINT8 pulldwn32_tble)
{
	di_im_di_control_RBUS di_control_reg;
	di_im_di_film_sawtooth_filmframe_th_RBUS film_sawtooth_filmframe_th_reg;
	di_im_di_film_static_sum_th_RBUS film_static_sum_th_reg;
	di_im_di_film_field_judge_th_RBUS film_field_judge_th_reg;
	di_im_di_film_static_sum_sub_th_RBUS film_static_sum_sub_th_reg;
	di_im_di_film_field_judge_sub_th_RBUS film_field_judge_sub_th_reg;
	di_im_di_film_motion_sum_th_RBUS film_motion_sum_th_reg;

	di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_VADDR);
	film_sawtooth_filmframe_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_VADDR);
	film_static_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_TH_VADDR);
	film_field_judge_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_FIELD_JUDGE_TH_VADDR);
	film_static_sum_sub_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_VADDR);
	film_field_judge_sub_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_VADDR);
	film_motion_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_MOTION_SUM_TH_VADDR);

#if 0
	di_control_reg.film_sawtooth_choose = 		film32_init_table_TSB[0][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_leavequick_en = 			film32_init_table_TSB[1][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_verscrollingtext_en = 		film32_init_table_TSB[2][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_thumbnail_en = 			film32_init_table_TSB[3][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_pair1_en = 				film32_init_table_TSB[4][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_pair2_en = 				film32_init_table_TSB[5][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_pair_en_auto = 			film32_init_table_TSB[6][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_violate_strict_en = 			film32_init_table_TSB[7][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 				film32_init_table_TSB[8][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_frmotionthl = 				film32_init_table_TSB[9][pulldwn32_tble];
	film_static_sum_th_reg.film_fieldmotionsumthl = 		film32_init_table_TSB[10][pulldwn32_tble];
	film_static_sum_th_reg.film_frstaticsthl = 				film32_init_table_TSB[11][pulldwn32_tble];
	film_static_sum_th_reg.film_fistaticsthl = 				film32_init_table_TSB[12][pulldwn32_tble];
	film_field_judge_th_reg.film_pairratio_all1 = 			film32_init_table_TSB[13][pulldwn32_tble];
	film_field_judge_th_reg.film_pairratio_all2 = 			film32_init_table_TSB[14][pulldwn32_tble];
	film_field_judge_th_reg.film_fiminsthl = 				film32_init_table_TSB[15][pulldwn32_tble];
	film_field_judge_th_reg.film_fimaxsthl = 				film32_init_table_TSB[16][pulldwn32_tble];
	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 		film32_init_table_TSB[17][pulldwn32_tble];
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 			film32_init_table_TSB[18][pulldwn32_tble];
	film_static_sum_sub_th_reg.film_subfistaticsthl = 			film32_init_table_TSB[19][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_pairratio_sub1 = 			film32_init_table_TSB[20][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_pairratio_sub2 = 			film32_init_table_TSB[21][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_subfiminsthl = 			film32_init_table_TSB[22][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_subfimaxsthl = 			film32_init_table_TSB[23][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_subfiminsthl = 			film32_init_table_TSB[24][pulldwn32_tble];
	film_motion_sum_th_reg.film32_debounce_fieldnum = 		film32_init_table_TSB[25][pulldwn32_tble];
	/*film_motion_sum_th_reg.dummy180240b4_23_16 = 0xff;*/
#else
	extern DRV_film32_table_t gFilm32InitTableTSB[2];

	di_control_reg.film_sawtooth_choose = 		gFilm32InitTableTSB[pulldwn32_tble].sawtooth_choose;
	film_sawtooth_filmframe_th_reg.film_leavequick_en = 			gFilm32InitTableTSB[pulldwn32_tble].LeaveQuick_en;
	film_sawtooth_filmframe_th_reg.film_verscrollingtext_en = 		gFilm32InitTableTSB[pulldwn32_tble].VerScrollingText_en;
	film_sawtooth_filmframe_th_reg.film_thumbnail_en = 			gFilm32InitTableTSB[pulldwn32_tble].thumbnail_en;
	film_sawtooth_filmframe_th_reg.film_pair1_en = 				gFilm32InitTableTSB[pulldwn32_tble].pair1_en;
	film_sawtooth_filmframe_th_reg.film_pair2_en = 				gFilm32InitTableTSB[pulldwn32_tble].pair2_en;
	film_sawtooth_filmframe_th_reg.film_pair_en_auto = 			gFilm32InitTableTSB[pulldwn32_tble].pair_en_auto;
	film_sawtooth_filmframe_th_reg.film_violate_strict_en = 			gFilm32InitTableTSB[pulldwn32_tble].violate_strict_en;
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 				gFilm32InitTableTSB[pulldwn32_tble].SawtoothThl;
	film_sawtooth_filmframe_th_reg.film_frmotionthl = 				gFilm32InitTableTSB[pulldwn32_tble].FrMotionThl;
	film_static_sum_th_reg.film_fieldmotionsumthl = 		gFilm32InitTableTSB[pulldwn32_tble].FieldMotionSumThl;
	film_static_sum_th_reg.film_frstaticsthl = 				gFilm32InitTableTSB[pulldwn32_tble].FrStaticSThl;
	film_static_sum_th_reg.film_fistaticsthl = 				gFilm32InitTableTSB[pulldwn32_tble].FiStaticSThl;
	film_field_judge_th_reg.film_pairratio_all1 = 			gFilm32InitTableTSB[pulldwn32_tble].PairRatio_all1;
	film_field_judge_th_reg.film_pairratio_all2 = 			gFilm32InitTableTSB[pulldwn32_tble].PairRatio_all2;
	film_field_judge_th_reg.film_fiminsthl = 				gFilm32InitTableTSB[pulldwn32_tble].FiMinSThl;
	film_field_judge_th_reg.film_fimaxsthl = 				gFilm32InitTableTSB[pulldwn32_tble].FiMaxSThl;
	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 		gFilm32InitTableTSB[pulldwn32_tble].SubFieldMotionSumThl;
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 			gFilm32InitTableTSB[pulldwn32_tble].SubFrStaticsSTh1;
	film_static_sum_sub_th_reg.film_subfistaticsthl = 			gFilm32InitTableTSB[pulldwn32_tble].SubFiStaticsSTh1;
	film_field_judge_sub_th_reg.film_pairratio_sub1 = 			gFilm32InitTableTSB[pulldwn32_tble].PairRatio_sub1;
	film_field_judge_sub_th_reg.film_pairratio_sub2 = 			gFilm32InitTableTSB[pulldwn32_tble].PairRatio_sub2;
	film_field_judge_sub_th_reg.film_subfiminsthl = 				gFilm32InitTableTSB[pulldwn32_tble].SubFiMinSTh1;
	film_field_judge_sub_th_reg.film_subfimaxsthl = 			gFilm32InitTableTSB[pulldwn32_tble].SubFiMaxSTh1;
	film_motion_sum_th_reg.film32_debounce_fieldnum = 		gFilm32InitTableTSB[pulldwn32_tble].debounce_fieldnum;
#endif

	IoReg_Write32(DI_IM_DI_CONTROL_VADDR, di_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_VADDR, film_sawtooth_filmframe_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_TH_VADDR, film_static_sum_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_TH_VADDR, film_field_judge_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_VADDR, film_static_sum_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_VADDR, film_field_judge_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_MOTION_SUM_TH_VADDR, film_motion_sum_th_reg.regValue);
}

void drvif_module_TSB_film22_init(UINT8 pulldwn22_tble)
{

	di_im_di_control_RBUS di_control_reg;
	di_im_di_film_sawtooth_filmframe_th_RBUS film_sawtooth_filmframe_th_reg;
	di_im_di_film_static_sum_th_RBUS film_static_sum_th_reg;
	di_im_di_film_field_judge_th_RBUS film_field_judge_th_reg;
	di_im_di_film_static_sum_sub_th_RBUS film_static_sum_sub_th_reg;
	di_im_di_film_field_judge_sub_th_RBUS film_field_judge_sub_th_reg;
	di_im_di_film_motion_sum_th_RBUS film_motion_sum_th_reg;

	di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_VADDR);
	film_sawtooth_filmframe_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_VADDR);
	film_static_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_TH_VADDR);
	film_field_judge_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_FIELD_JUDGE_TH_VADDR);
	film_static_sum_sub_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_VADDR);
	film_field_judge_sub_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_VADDR);
	film_motion_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_MOTION_SUM_TH_VADDR);

#if 0
	di_control_reg.film_sawtooth_choose = 		film22_init_table_TSB[0][pulldwn22_tble];

	film_sawtooth_filmframe_th_reg.film_leavequick_en = 			film22_init_table_TSB[1][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_verscrollingtext_en = 		film22_init_table_TSB[2][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_thumbnail_en = 			film22_init_table_TSB[3][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_pair1_en = 				film22_init_table_TSB[4][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_pair2_en = 				film22_init_table_TSB[5][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_pair_en_auto = 			film22_init_table_TSB[6][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_violate_strict_en = 			film22_init_table_TSB[7][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film22_sawtooththl = 			film22_init_table_TSB[8][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 				film22_init_table_TSB[9][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_frmotionthl = 				film22_init_table_TSB[10][pulldwn22_tble];

	film_static_sum_th_reg.film_fieldmotionsumthl = 		film22_init_table_TSB[11][pulldwn22_tble];
	film_static_sum_th_reg.film22_fistaticsthl = 			film22_init_table_TSB[12][pulldwn22_tble];
	film_static_sum_th_reg.film_frstaticsthl =				film22_init_table_TSB[13][pulldwn22_tble];

	film_field_judge_th_reg.film_pairratio_all1 = 			film22_init_table_TSB[14][pulldwn22_tble];
	film_field_judge_th_reg.film_pairratio_all2 = 			film22_init_table_TSB[15][pulldwn22_tble];
	film_field_judge_th_reg.film_fiminsthl = 				film22_init_table_TSB[16][pulldwn22_tble];
	film_field_judge_th_reg.film_fimaxsthl = 				film22_init_table_TSB[17][pulldwn22_tble];

	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 		film22_init_table_TSB[18][pulldwn22_tble];
	film_static_sum_sub_th_reg.film_subfistaticsthl = 			film22_init_table_TSB[19][pulldwn22_tble];
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 			film22_init_table_TSB[20][pulldwn22_tble];

	film_field_judge_sub_th_reg.film_pairratio_sub1 = 			film22_init_table_TSB[21][pulldwn22_tble];
	film_field_judge_sub_th_reg.film_pairratio_sub2 = 			film22_init_table_TSB[22][pulldwn22_tble];
	film_field_judge_sub_th_reg.film_subfiminsthl = 				film22_init_table_TSB[23][pulldwn22_tble];
	film_field_judge_sub_th_reg.film_subfimaxsthl = 			film22_init_table_TSB[24][pulldwn22_tble];

	film_motion_sum_th_reg.film22_debounce_fieldnum = 		film22_init_table_TSB[25][pulldwn22_tble];
	film_motion_sum_th_reg.film22_subfieldmotionsumthl = 	film22_init_table_TSB[26][pulldwn22_tble];
	film_motion_sum_th_reg.film22_fieldmotionsumthl = 		film22_init_table_TSB[27][pulldwn22_tble];
	/*film_motion_sum_th_reg.dummy180240b4_23_16 = 0xff;*/
#else
	extern DRV_film22_table_t gFilm22InitTableTSB[2];

	di_control_reg.film_sawtooth_choose = 		gFilm22InitTableTSB[pulldwn22_tble].sawtooth_choose;
	film_sawtooth_filmframe_th_reg.film_leavequick_en = 			gFilm22InitTableTSB[pulldwn22_tble].LeaveQuick_en;
	film_sawtooth_filmframe_th_reg.film_verscrollingtext_en = 		gFilm22InitTableTSB[pulldwn22_tble].VerScrollingText_en;
	film_sawtooth_filmframe_th_reg.film_thumbnail_en = 			gFilm22InitTableTSB[pulldwn22_tble].thumbnail_en;
	film_sawtooth_filmframe_th_reg.film_pair1_en = 				gFilm22InitTableTSB[pulldwn22_tble].pair1_en;
	film_sawtooth_filmframe_th_reg.film_pair2_en = 				gFilm22InitTableTSB[pulldwn22_tble].pair2_en;
	film_sawtooth_filmframe_th_reg.film_pair_en_auto = 			gFilm22InitTableTSB[pulldwn22_tble].pair_en_auto;
	film_sawtooth_filmframe_th_reg.film_violate_strict_en = 			gFilm22InitTableTSB[pulldwn22_tble].violate_strict_en;
	film_sawtooth_filmframe_th_reg.film22_sawtooththl = 			gFilm22InitTableTSB[pulldwn22_tble].Film22_SawtoothTh1;
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 				gFilm22InitTableTSB[pulldwn22_tble].Film_SawtoothThl;
	film_sawtooth_filmframe_th_reg.film_frmotionthl = 				gFilm22InitTableTSB[pulldwn22_tble].FrMotionThl;

	film_static_sum_th_reg.film_fieldmotionsumthl = 		gFilm22InitTableTSB[pulldwn22_tble].FieldMotionSumThl;
	film_static_sum_th_reg.film22_fistaticsthl = 			gFilm22InitTableTSB[pulldwn22_tble].film22_FiStaticSThl;
	film_static_sum_th_reg.film_frstaticsthl =				gFilm22InitTableTSB[pulldwn22_tble].film_FrStaticSThl;

	film_field_judge_th_reg.film_pairratio_all1 = 			gFilm22InitTableTSB[pulldwn22_tble].PairRatio_all1;
	film_field_judge_th_reg.film_pairratio_all2 = 			gFilm22InitTableTSB[pulldwn22_tble].PairRatio_all2;
	film_field_judge_th_reg.film_fiminsthl = 				gFilm22InitTableTSB[pulldwn22_tble].FiMinSThl;
	film_field_judge_th_reg.film_fimaxsthl = 				gFilm22InitTableTSB[pulldwn22_tble].FiMaxSThl;

	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 		gFilm22InitTableTSB[pulldwn22_tble].film_SubFieldMotionSumThl;
	film_static_sum_sub_th_reg.film_subfistaticsthl = 			gFilm22InitTableTSB[pulldwn22_tble].SubFiStaticsSTh1;
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 			gFilm22InitTableTSB[pulldwn22_tble].SubFrStaticsSTh1;

	film_field_judge_sub_th_reg.film_pairratio_sub1 = 			gFilm22InitTableTSB[pulldwn22_tble].PairRatio_sub1;
	film_field_judge_sub_th_reg.film_pairratio_sub2 = 			gFilm22InitTableTSB[pulldwn22_tble].PairRatio_sub2;
	film_field_judge_sub_th_reg.film_subfiminsthl = 				gFilm22InitTableTSB[pulldwn22_tble].SubFiMinSTh1;
	film_field_judge_sub_th_reg.film_subfimaxsthl = 			gFilm22InitTableTSB[pulldwn22_tble].SubFiMaxSTh1;

	film_motion_sum_th_reg.film22_debounce_fieldnum = 		gFilm22InitTableTSB[pulldwn22_tble].film22_debounce_fieldnum;
	film_motion_sum_th_reg.film22_subfieldmotionsumthl = 	gFilm22InitTableTSB[pulldwn22_tble].film22_SubFieldMotionSumThl;
	film_motion_sum_th_reg.film22_fieldmotionsumthl = 		gFilm22InitTableTSB[pulldwn22_tble].film22_FieldMotionSumThl;
#endif

	IoReg_Write32(DI_IM_DI_CONTROL_VADDR, di_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_VADDR, film_sawtooth_filmframe_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_TH_VADDR, film_static_sum_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_TH_VADDR, film_field_judge_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_VADDR, film_static_sum_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_VADDR, film_field_judge_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_MOTION_SUM_TH_VADDR, film_motion_sum_th_reg.regValue);

}

void drvif_module_film32_init(UINT8 pulldwn32_tble)
{
	di_im_di_control_RBUS di_control_reg;
	di_im_di_film_sawtooth_filmframe_th_RBUS film_sawtooth_filmframe_th_reg;
	di_im_di_film_static_sum_th_RBUS film_static_sum_th_reg;
	di_im_di_film_field_judge_th_RBUS film_field_judge_th_reg;
	di_im_di_film_static_sum_sub_th_RBUS film_static_sum_sub_th_reg;
	di_im_di_film_field_judge_sub_th_RBUS film_field_judge_sub_th_reg;
	di_im_di_film_motion_sum_th_RBUS film_motion_sum_th_reg;
	di_im_di_film_new_function_main_RBUS film_new_function_main_reg;	/* fw film setting*/

	di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_VADDR);
	film_sawtooth_filmframe_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_VADDR);
	film_static_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_TH_VADDR);
	film_field_judge_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_FIELD_JUDGE_TH_VADDR);
	film_static_sum_sub_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_VADDR);
	film_field_judge_sub_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_VADDR);
	film_motion_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_MOTION_SUM_TH_VADDR);
	film_new_function_main_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_VADDR);	/* fw film setting*/

#if 0
	di_control_reg.film_sawtooth_choose = 		film32_init_table[0][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_leavequick_en = 			film32_init_table[1][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_verscrollingtext_en = 		film32_init_table[2][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_thumbnail_en = 			film32_init_table[3][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_pair1_en = 				film32_init_table[4][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_pair2_en = 				film32_init_table[5][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_pair_en_auto = 			film32_init_table[6][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_violate_strict_en = 			film32_init_table[7][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 				film32_init_table[8][pulldwn32_tble];
	film_sawtooth_filmframe_th_reg.film_frmotionthl = 				film32_init_table[9][pulldwn32_tble];
	film_static_sum_th_reg.film_fieldmotionsumthl = 		film32_init_table[10][pulldwn32_tble];
	film_static_sum_th_reg.film_frstaticsthl = 				film32_init_table[11][pulldwn32_tble];
	film_static_sum_th_reg.film_fistaticsthl = 				film32_init_table[12][pulldwn32_tble];
	film_field_judge_th_reg.film_pairratio_all1 = 			film32_init_table[13][pulldwn32_tble];
	film_field_judge_th_reg.film_pairratio_all2 = 			film32_init_table[14][pulldwn32_tble];
	film_field_judge_th_reg.film_fiminsthl = 				film32_init_table[15][pulldwn32_tble];
	film_field_judge_th_reg.film_fimaxsthl = 				film32_init_table[16][pulldwn32_tble];
	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 		film32_init_table[17][pulldwn32_tble];
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 			film32_init_table[18][pulldwn32_tble];
	film_static_sum_sub_th_reg.film_subfistaticsthl = 			film32_init_table[19][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_pairratio_sub1 = 			film32_init_table[20][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_pairratio_sub2 = 			film32_init_table[21][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_subfiminsthl = 				film32_init_table[22][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_subfimaxsthl = 			film32_init_table[23][pulldwn32_tble];
	film_field_judge_sub_th_reg.film_subfiminsthl = 				film32_init_table[24][pulldwn32_tble];
	film_motion_sum_th_reg.film32_debounce_fieldnum = 		film32_init_table[25][pulldwn32_tble];
	/*film_motion_sum_th_reg.dummy180240b4_23_16 = 0xff;*/
	film_new_function_main_reg.fw_film_en 		=			film32_init_table[26][pulldwn32_tble];
#else
	extern DRV_film32_table_t gFilm32InitTable[2];

	di_control_reg.film_sawtooth_choose = 		gFilm32InitTable[pulldwn32_tble].sawtooth_choose;
	film_sawtooth_filmframe_th_reg.film_leavequick_en = 			gFilm32InitTable[pulldwn32_tble].LeaveQuick_en;
	film_sawtooth_filmframe_th_reg.film_verscrollingtext_en = 		gFilm32InitTable[pulldwn32_tble].VerScrollingText_en;
	film_sawtooth_filmframe_th_reg.film_thumbnail_en = 			gFilm32InitTable[pulldwn32_tble].thumbnail_en;
	film_sawtooth_filmframe_th_reg.film_pair1_en = 				gFilm32InitTable[pulldwn32_tble].pair1_en;
	film_sawtooth_filmframe_th_reg.film_pair2_en = 				gFilm32InitTable[pulldwn32_tble].pair2_en;
	film_sawtooth_filmframe_th_reg.film_pair_en_auto = 			gFilm32InitTable[pulldwn32_tble].pair_en_auto;
	film_sawtooth_filmframe_th_reg.film_violate_strict_en = 			gFilm32InitTable[pulldwn32_tble].violate_strict_en;
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 				gFilm32InitTable[pulldwn32_tble].SawtoothThl;
	film_sawtooth_filmframe_th_reg.film_frmotionthl = 				gFilm32InitTable[pulldwn32_tble].FrMotionThl;
	film_static_sum_th_reg.film_fieldmotionsumthl = 		gFilm32InitTable[pulldwn32_tble].FieldMotionSumThl;
	film_static_sum_th_reg.film_frstaticsthl = 				gFilm32InitTable[pulldwn32_tble].FrStaticSThl;
	film_static_sum_th_reg.film_fistaticsthl = 				gFilm32InitTable[pulldwn32_tble].FiStaticSThl;
	film_field_judge_th_reg.film_pairratio_all1 = 			gFilm32InitTable[pulldwn32_tble].PairRatio_all1;
	film_field_judge_th_reg.film_pairratio_all2 = 			gFilm32InitTable[pulldwn32_tble].PairRatio_all2;
	film_field_judge_th_reg.film_fiminsthl = 				gFilm32InitTable[pulldwn32_tble].FiMinSThl;
	film_field_judge_th_reg.film_fimaxsthl = 				gFilm32InitTable[pulldwn32_tble].FiMaxSThl;
	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 		gFilm32InitTable[pulldwn32_tble].SubFieldMotionSumThl;
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 			gFilm32InitTable[pulldwn32_tble].SubFrStaticsSTh1;
	film_static_sum_sub_th_reg.film_subfistaticsthl = 			gFilm32InitTable[pulldwn32_tble].SubFiStaticsSTh1;
	film_field_judge_sub_th_reg.film_pairratio_sub1 = 			gFilm32InitTable[pulldwn32_tble].PairRatio_sub1;
	film_field_judge_sub_th_reg.film_pairratio_sub2 = 			gFilm32InitTable[pulldwn32_tble].PairRatio_sub2;
	film_field_judge_sub_th_reg.film_subfiminsthl = 				gFilm32InitTable[pulldwn32_tble].SubFiMinSTh1;
	film_field_judge_sub_th_reg.film_subfimaxsthl = 			gFilm32InitTable[pulldwn32_tble].SubFiMaxSTh1;
	film_motion_sum_th_reg.film32_debounce_fieldnum = 		gFilm32InitTable[pulldwn32_tble].debounce_fieldnum;
	film_new_function_main_reg.fw_film_en 		=			gFilm32InitTable[pulldwn32_tble].fw_film_en;
#endif

	IoReg_Write32(DI_IM_DI_CONTROL_VADDR, di_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_VADDR, film_sawtooth_filmframe_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_TH_VADDR, film_static_sum_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_TH_VADDR, film_field_judge_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_VADDR, film_static_sum_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_VADDR, film_field_judge_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_MOTION_SUM_TH_VADDR, film_motion_sum_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_VADDR, film_new_function_main_reg.regValue);
}

void drvif_module_film22_init(UINT8 pulldwn22_tble)
{
	extern DRV_film22_table_t gFilm22InitTable[2];

	di_im_di_control_RBUS di_control_reg;
	di_im_di_film_sawtooth_filmframe_th_RBUS film_sawtooth_filmframe_th_reg;
	di_im_di_film_static_sum_th_RBUS film_static_sum_th_reg;
	di_im_di_film_field_judge_th_RBUS film_field_judge_th_reg;
	di_im_di_film_static_sum_sub_th_RBUS film_static_sum_sub_th_reg;
	di_im_di_film_field_judge_sub_th_RBUS film_field_judge_sub_th_reg;
	di_im_di_film_motion_sum_th_RBUS film_motion_sum_th_reg;
	di_im_di_film_new_function_main_RBUS film_new_function_main_reg;	/* fw film setting*/

	di_control_reg.regValue = rtd_inl(DI_IM_DI_CONTROL_VADDR);
	film_sawtooth_filmframe_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_VADDR);
	film_static_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_TH_VADDR);
	film_field_judge_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_FIELD_JUDGE_TH_VADDR);
	film_static_sum_sub_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_VADDR);
	film_field_judge_sub_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_VADDR);
	film_motion_sum_th_reg.regValue = rtd_inl(DI_IM_DI_FILM_MOTION_SUM_TH_VADDR);
	film_new_function_main_reg.regValue = IoReg_Read32(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_VADDR);	/* fw film setting*/

#if 0
	di_control_reg.film_sawtooth_choose = 		film22_init_table[0][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_leavequick_en = 			film22_init_table[1][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_verscrollingtext_en = 		film22_init_table[2][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_thumbnail_en = 			film22_init_table[3][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_pair1_en = 				film22_init_table[4][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_pair2_en = 				film22_init_table[5][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_pair_en_auto = 			film22_init_table[6][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_violate_strict_en = 			film22_init_table[7][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film22_sawtooththl = 			film22_init_table[8][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 				film22_init_table[9][pulldwn22_tble];
	film_sawtooth_filmframe_th_reg.film_frmotionthl = 				film22_init_table[10][pulldwn22_tble];

	film_static_sum_th_reg.film_fieldmotionsumthl = 		film22_init_table[11][pulldwn22_tble];
	film_static_sum_th_reg.film22_fistaticsthl = 			film22_init_table[12][pulldwn22_tble];
	film_static_sum_th_reg.film_frstaticsthl =				film22_init_table[13][pulldwn22_tble];

	film_field_judge_th_reg.film_pairratio_all1 = 			film22_init_table[14][pulldwn22_tble];
	film_field_judge_th_reg.film_pairratio_all2 = 			film22_init_table[15][pulldwn22_tble];
	film_field_judge_th_reg.film_fiminsthl = 				film22_init_table[16][pulldwn22_tble];
	film_field_judge_th_reg.film_fimaxsthl = 				film22_init_table[17][pulldwn22_tble];

	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 		film22_init_table[18][pulldwn22_tble];
	film_static_sum_sub_th_reg.film_subfistaticsthl = 			film22_init_table[19][pulldwn22_tble];
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 			film22_init_table[20][pulldwn22_tble];

	film_field_judge_sub_th_reg.film_pairratio_sub1 = 			film22_init_table[21][pulldwn22_tble];
	film_field_judge_sub_th_reg.film_pairratio_sub2 = 			film22_init_table[22][pulldwn22_tble];
	film_field_judge_sub_th_reg.film_subfiminsthl = 				film22_init_table[23][pulldwn22_tble];
	film_field_judge_sub_th_reg.film_subfimaxsthl = 			film22_init_table[24][pulldwn22_tble];

	film_motion_sum_th_reg.film22_debounce_fieldnum = 		film22_init_table[25][pulldwn22_tble];
	film_motion_sum_th_reg.film22_subfieldmotionsumthl = 	film22_init_table[26][pulldwn22_tble];
	film_motion_sum_th_reg.film22_fieldmotionsumthl = 		film22_init_table[27][pulldwn22_tble];
	/*film_motion_sum_th_reg.dummy180240b4_23_16 = 0xff;*/
	film_new_function_main_reg.fw_film_en 		=			film22_init_table[28][pulldwn22_tble];
#else
	extern DRV_film22_table_t gFilm22InitTable[2];

	di_control_reg.film_sawtooth_choose = 		gFilm22InitTable[pulldwn22_tble].sawtooth_choose;
	film_sawtooth_filmframe_th_reg.film_leavequick_en = 			gFilm22InitTable[pulldwn22_tble].LeaveQuick_en;
	film_sawtooth_filmframe_th_reg.film_verscrollingtext_en = 		gFilm22InitTable[pulldwn22_tble].VerScrollingText_en;
	film_sawtooth_filmframe_th_reg.film_thumbnail_en = 			gFilm22InitTable[pulldwn22_tble].thumbnail_en;
	film_sawtooth_filmframe_th_reg.film_pair1_en = 				gFilm22InitTable[pulldwn22_tble].pair1_en;
	film_sawtooth_filmframe_th_reg.film_pair2_en = 				gFilm22InitTable[pulldwn22_tble].pair2_en;
	film_sawtooth_filmframe_th_reg.film_pair_en_auto = 			gFilm22InitTable[pulldwn22_tble].pair_en_auto;
	film_sawtooth_filmframe_th_reg.film_violate_strict_en = 			gFilm22InitTable[pulldwn22_tble].violate_strict_en;
	film_sawtooth_filmframe_th_reg.film22_sawtooththl = 			gFilm22InitTable[pulldwn22_tble].Film22_SawtoothTh1;
	film_sawtooth_filmframe_th_reg.film_sawtooththl = 				gFilm22InitTable[pulldwn22_tble].Film_SawtoothThl;
	film_sawtooth_filmframe_th_reg.film_frmotionthl = 				gFilm22InitTable[pulldwn22_tble].FrMotionThl;

	film_static_sum_th_reg.film_fieldmotionsumthl = 		gFilm22InitTable[pulldwn22_tble].FieldMotionSumThl;
	film_static_sum_th_reg.film22_fistaticsthl = 			gFilm22InitTable[pulldwn22_tble].film22_FiStaticSThl;
	film_static_sum_th_reg.film_frstaticsthl =				gFilm22InitTable[pulldwn22_tble].film_FrStaticSThl;

	film_field_judge_th_reg.film_pairratio_all1 = 			gFilm22InitTable[pulldwn22_tble].PairRatio_all1;
	film_field_judge_th_reg.film_pairratio_all2 = 			gFilm22InitTable[pulldwn22_tble].PairRatio_all2;
	film_field_judge_th_reg.film_fiminsthl = 				gFilm22InitTable[pulldwn22_tble].FiMinSThl;
	film_field_judge_th_reg.film_fimaxsthl = 				gFilm22InitTable[pulldwn22_tble].FiMaxSThl;

	film_static_sum_sub_th_reg.film_subfieldmotionsumthl = 		gFilm22InitTable[pulldwn22_tble].film_SubFieldMotionSumThl;
	film_static_sum_sub_th_reg.film_subfistaticsthl = 			gFilm22InitTable[pulldwn22_tble].SubFiStaticsSTh1;
	film_static_sum_sub_th_reg.film_subfrstaticsthl = 			gFilm22InitTable[pulldwn22_tble].SubFrStaticsSTh1;

	film_field_judge_sub_th_reg.film_pairratio_sub1 = 			gFilm22InitTable[pulldwn22_tble].PairRatio_sub1;
	film_field_judge_sub_th_reg.film_pairratio_sub2 = 			gFilm22InitTable[pulldwn22_tble].PairRatio_sub2;
	film_field_judge_sub_th_reg.film_subfiminsthl = 				gFilm22InitTable[pulldwn22_tble].SubFiMinSTh1;
	film_field_judge_sub_th_reg.film_subfimaxsthl = 			gFilm22InitTable[pulldwn22_tble].SubFiMaxSTh1;

	film_motion_sum_th_reg.film22_debounce_fieldnum = 		gFilm22InitTable[pulldwn22_tble].film22_debounce_fieldnum;
	film_motion_sum_th_reg.film22_subfieldmotionsumthl = 	gFilm22InitTable[pulldwn22_tble].film22_SubFieldMotionSumThl;
	film_motion_sum_th_reg.film22_fieldmotionsumthl = 		gFilm22InitTable[pulldwn22_tble].film22_FieldMotionSumThl;
	film_new_function_main_reg.fw_film_en 		=			gFilm22InitTable[pulldwn22_tble].fw_film_en;
#endif

	IoReg_Write32(DI_IM_DI_CONTROL_VADDR, di_control_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_VADDR, film_sawtooth_filmframe_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_TH_VADDR, film_static_sum_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_TH_VADDR, film_field_judge_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_STATIC_SUM_SUB_TH_VADDR, film_static_sum_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_VADDR, film_field_judge_sub_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_MOTION_SUM_TH_VADDR, film_motion_sum_th_reg.regValue);
	IoReg_Write32(DI_IM_DI_FILM_NEW_FUNCTION_MAIN_VADDR, film_new_function_main_reg.regValue);
}

#endif

