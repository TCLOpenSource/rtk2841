/**
* @file rbusScaleupReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SCALEUP_REG_H_
#define _RBUS_SCALEUP_REG_H_

#include "rbusTypes.h"



//  SCALEUP Register Address



#define  SCALEUP_D_UZU_GLOBLE_CTRL_VADDR                    	(0xb8029000)
#define  SCALEUP_DM_UZU_CTRL_VADDR                          	(0xb8029004)
#define  SCALEUP_DM_UZU_SCALE_HOR_FACTOR_VADDR              	(0xb8029008)
#define  SCALEUP_DM_UZU_SCALE_VER_FACTOR_VADDR              	(0xb802900c)
#define  SCALEUP_DM_UZU_HOR_DELTA1_VADDR                    	(0xb8029010)
#define  SCALEUP_DM_UZU_HOR_DELTA2_VADDR                    	(0xb8029014)
#define  SCALEUP_DM_UZU_HOR_SEGMENT1_VADDR                  	(0xb8029018)
#define  SCALEUP_DM_UZU_HOR_SEGMENT2_VADDR                  	(0xb802901c)
#define  SCALEUP_DM_UZU_HOR_SEGMENT3_VADDR                  	(0xb8029020)
#define  SCALEUP_DM_UZU_INITIAL_VALUE_VADDR                 	(0xb8029024)
#define  SCALEUP_DM_UZU_INPUT_SIZE_VADDR                    	(0xb8029028)
#define  SCALEUP_DM_UZU_10TAP_DERING_VADDR                  	(0xb802902c)
#define  SCALEUP_DM_UZU_8TAP_DERINGV_VADDR                  	(0xb8029030)
#define  SCALEUP_DM_UZU_PEAKING_CORING_VADDR                	(0xb8029038)
#define  SCALEUP_DM_UZU_PEAKING_GAIN_VADDR                  	(0xb802903c)
#define  SCALEUP_DM_MEM_CRC_CTRL_VADDR                      	(0xb8029040)
#define  SCALEUP_DM_MEM_CRC_RESULT_VADDR                    	(0xb8029044)
#define  SCALEUP_MEM_CRC_CTR2_VADDR                         	(0xb8029048)
#define  SCALEUP_MEM_CRC_R_RESULT_VADDR                     	(0xb802904c)
#define  SCALEUP_MEM_L_DES_CRC_VADDR                        	(0xb8029050)
#define  SCALEUP_MEM_R_DES_CRC_VADDR                        	(0xb8029054)
#define  SCALEUP_MEM_CRC_ERR_CNT_VADDR                      	(0xb8029058)
#define  SCALEUP_D_UZU_CRC_CTRL_VADDR                       	(0xb802905c)
#define  SCALEUP_D_UZU_CRC_RESULT_VADDR                     	(0xb8029060)
#define  SCALEUP_D_UZU_PATGEN_COLOR0_VADDR                  	(0xb8029064)
#define  SCALEUP_D_UZU_PATGEN_COLOR1_VADDR                  	(0xb8029068)
#define  SCALEUP_D_UZU_PATGEN_COLOR2_VADDR                  	(0xb802906c)
#define  SCALEUP_D_UZU_PATGEN_COLOR3_VADDR                  	(0xb8029070)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_VADDR            	(0xb8029074)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_VADDR           	(0xb8029078)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_VADDR           	(0xb802907c)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_VADDR           	(0xb8029080)
#define  SCALEUP_ACCESSDATA_CTRL_UZU_VADDR                  	(0xb8029090)
#define  SCALEUP_ACCESSDATA_POSCTRL_UZU_VADDR               	(0xb8029094)
#define  SCALEUP_READDATA_DATA_Y1_UZU_VADDR                 	(0xb8029098)
#define  SCALEUP_READDATA_DATA_Y2_UZU_VADDR                 	(0xb802909c)
#define  SCALEUP_READDATA_DATA_C1_UZU_VADDR                 	(0xb80290a0)
#define  SCALEUP_READDATA_DATA_C2_UZU_VADDR                 	(0xb80290a4)
#define  SCALEUP_READDATA_DATA_C3_UZU_VADDR                 	(0xb80290a8)
#define  SCALEUP_READDATA_DATA_C4_UZU_VADDR                 	(0xb80290ac)
#define  SCALEUP_WRITEDATA_DATA_UZU_VADDR                   	(0xb80290b0)
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_VADDR            	(0xb80290b4)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_VADDR            	(0xb80290b8)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_VADDR             	(0xb80290bc)
#define  SCALEUP_DM_UZUMAIN_ADAPT8TAP_VADDR                 	(0xb80290c0)
#define  SCALEUP_DM_USM_VADDR                               	(0xb80290c4)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_VADDR                  	(0xb80290c8)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_VADDR                  	(0xb80290cc)
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_VADDR                 	(0xb80290d0)
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_VADDR                 	(0xb80290d4)
#define  SCALEUP_DM_USM_HLPF_COEF_VADDR                     	(0xb80290d8)
#define  SCALEUP_DM_UZU_V8CTRL_VADDR                        	(0xb80290e0)
#define  SCALEUP_DM_UZU_ADAPTV8CTRL_VADDR                   	(0xb80290e4)
#define  SCALEUP_DM_UZU_INITIAL_VALUE_LEFT_VADDR            	(0xb80290e8)
#define  SCALEUP_DM_UZU_DB_CTRL_VADDR                       	(0xb80290f0)
#define  SCALEUP_DM_UZU_WCLR_VADDR                          	(0xb80290f4)
#define  SCALEUP_LEFT_3D_PTG_CTRL3_VADDR                    	(0xb8029100)
#define  SCALEUP_LEFT_3D_PTG_CTRL4_VADDR                    	(0xb8029104)
#define  SCALEUP_LEFT_3D_PTG_CTRL5_VADDR                    	(0xb8029108)
#define  SCALEUP_RIGHT_3D_PTG_CTRL1_VADDR                   	(0xb802910c)
#define  SCALEUP_RIGHT_3D_PTG_CTRL2_VADDR                   	(0xb8029110)
#define  SCALEUP_RIGHT_3D_PTG_CTRL3_VADDR                   	(0xb8029114)
#define  SCALEUP_PTG_3D_CTR1_VADDR                          	(0xb8029118)
#define  SCALEUP_DM_DIR_UZU_CTRL_VADDR                      	(0xb8029130)
#define  SCALEUP_DM_DIR_UZU_TRANSANG1_VADDR                 	(0xb8029134)
#define  SCALEUP_DM_DIR_UZU_TRANSANG2_VADDR                 	(0xb8029138)
#define  SCALEUP_DM_DIR_UZU_ANGMAGSCORE_VADDR               	(0xb8029140)
#define  SCALEUP_DM_DIR_UZU_ONEPIXELDETECT_VADDR            	(0xb8029144)
#define  SCALEUP_DM_DIR_UZU_CONF_VADDR                      	(0xb8029148)
#define  SCALEUP_DM_DIR_UZU_ANGLECHECK_VADDR                	(0xb802914c)
#define  SCALEUP_DM_UZU_BIST_0_VADDR                        	(0xb8029180)
#define  SCALEUP_DM_UZU_BIST_1_VADDR                        	(0xb8029184)
#define  SCALEUP_DM_UZU_BIST_2_VADDR                        	(0xb8029188)
#define  SCALEUP_DM_UZU_BIST_3_VADDR                        	(0xb802918c)
#define  SCALEUP_DM_UZU_BIST_4_VADDR                        	(0xb8029190)
#define  SCALEUP_DM_UZU_BIST_5_VADDR                        	(0xb8029194)
#define  SCALEUP_DM_UZU_BIST_6_VADDR                        	(0xb8029198)
#define  SCALEUP_COEF_TABLE_RW_CTL_VADDR                    	(0xb8029390)
#define  SCALEUP_COEF_TABLE_CTL_VADDR                       	(0xb8029394)
#define  SCALEUP_COEF_TABLE_CTL_0_VADDR                     	(0xb8029398)
#define  SCALEUP_COEF_TABLE_CTL_1_VADDR                     	(0xb802939c)
#define  SCALEUP_COEF_TABLE_CTL_2_VADDR                     	(0xb80293a0)
#define  SCALEUP_COEF_TABLE_CTL_3_VADDR                     	(0xb80293a4)
#define  SCALEUP_COEF_TABLE_CTL_4_VADDR                     	(0xb80293a8)
#define  SCALEUP_COEF_TABLE_ERR_VADDR                       	(0xb80293b0)
#define  SCALEUP_DS_UZU_CTRL_VADDR                          	(0xb8029200)
#define  SCALEUP_DS_UZU_SCALE_HOR_FACTOR_VADDR              	(0xb8029204)
#define  SCALEUP_DS_UZU_SCALE_VER_FACTOR_VADDR              	(0xb8029208)
#define  SCALEUP_DS_UZU_INITIAL_VALUE_VADDR                 	(0xb802920c)
#define  SCALEUP_DS_UZU_INPUT_SIZE_VADDR                    	(0xb8029210)
#define  SCALEUP_DS_MEM_CRC_CTRL_VADDR                      	(0xb8029214)
#define  SCALEUP_DS_MEM_CRC_RESULT_VADDR                    	(0xb8029218)
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_VADDR             	(0xb802921c)
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_VADDR             	(0xb8029220)
#define  SCALEUP_DS_UZU_DB_CTRL_VADDR                       	(0xb8029224)
#define  SCALEUP_DS_MEM_CRC_CTR2_VADDR                      	(0xb8029228)
#define  SCALEUP_DS_MEM_L_DES_CRC_VADDR                     	(0xb802922c)
#define  SCALEUP_DS_MEM_CRC_ERR_CNT_VADDR                   	(0xb8029230)
#define  SCALEUP_DS_UZU_WCLR_VADDR                          	(0xb8029234)
#define  SCALEUP_DS_UZU_FIR_COEF_VER_C0_C3_VADDR            	(0xb8029240)
#define  SCALEUP_DS_UZU_FIR_COEF_VER_C4_C7_VADDR            	(0xb8029244)
#define  SCALEUP_DS_UZU_FIR_COEF_VER_C8_C11_VADDR           	(0xb8029248)
#define  SCALEUP_DS_UZU_FIR_COEF_VER_C12_C15_VADDR          	(0xb802924c)
#define  SCALEUP_DS_UZU_FIR_COEF_HOR_C0_VADDR               	(0xb8029250)
#define  SCALEUP_DS_UZU_FIR_COEF_HOR_C4_VADDR               	(0xb8029254)
#define  SCALEUP_DS_UZU_FIR_COEF_HOR_C8_VADDR               	(0xb8029258)
#define  SCALEUP_DS_UZU_FIR_COEF_HOR_C12_VADDR              	(0xb802925c)
#define  SCALEUP_DS_UZU_BIST_0_VADDR                        	(0xb8029260)
#define  SCALEUP_DS_UZU_BIST_1_VADDR                        	(0xb8029264)
#define  SCALEUP_DS_UZU_GLOBLE_CTRL_VADDR                   	(0xb8029290)
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_VADDR                 	(0xb8029294)
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_VADDR                 	(0xb8029298)
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_VADDR                 	(0xb802929c)
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_VADDR                 	(0xb80292a0)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_VADDR           	(0xb80292a4)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_VADDR          	(0xb80292a8)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_VADDR          	(0xb80292ac)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_VADDR          	(0xb80292b0)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SCALEUP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029000_31_16:16;
        RBus_UInt32  uzu_bypass_no_pwrsave:1;
        RBus_UInt32  uzu_bypass_force:1;
        RBus_UInt32  lr_black_en:1;
        RBus_UInt32  lr_black_sel:1;
        RBus_UInt32  in_black_en:1;
        RBus_UInt32  in_even_black:1;
        RBus_UInt32  out_black_en:1;
        RBus_UInt32  out_even_black:1;
        RBus_UInt32  patgen_sync:1;
        RBus_UInt32  patgen_mode:3;
        RBus_UInt32  patgen_lflag_en:1;
        RBus_UInt32  patgen_field:1;
        RBus_UInt32  patgen_sel:2;
    };
}scaleup_d_uzu_globle_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_mode_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_pr_mode:2;
        RBus_UInt32  wd_main_buf_udf_en:1;
        RBus_UInt32  irq_main_buf_udf_en:1;
        RBus_UInt32  bypassfornr:1;
        RBus_UInt32  v_y_consttab_sel:2;
        RBus_UInt32  v_c_consttab_sel:2;
        RBus_UInt32  h_y_consttab_sel:2;
        RBus_UInt32  h_c_consttab_sel:2;
        RBus_UInt32  hor10_table_sel:2;
        RBus_UInt32  d_3d_sel_en:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  in_fmt_conv:1;
        RBus_UInt32  conv_type:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  in_fmt_dup:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  h_zoom_en:1;
    };
}scaleup_dm_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hor_factor:20;
    };
}scaleup_dm_uzu_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ver_factor:20;
    };
}scaleup_dm_uzu_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  hor_delta1:13;
    };
}scaleup_dm_uzu_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  hor_delta2:13;
    };
}scaleup_dm_uzu_hor_delta2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  hor_segment1:11;
    };
}scaleup_dm_uzu_hor_segment1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  hor_segment2:11;
    };
}scaleup_dm_uzu_hor_segment2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  hor_segment3:12;
    };
}scaleup_dm_uzu_hor_segment3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  ver_ini:8;
    };
}scaleup_dm_uzu_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hor_input_size:13;
        RBus_UInt32  res2:4;
        RBus_UInt32  ver_input_size:12;
    };
}scaleup_dm_uzu_input_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  level_flatness_coeff:3;
        RBus_UInt32  dering_dbg_mode:2;
        RBus_UInt32  h4h10_blend_range:2;
        RBus_UInt32  h4h10_blend_lowbound:8;
        RBus_UInt32  lpf_blend_mask_sel:1;
        RBus_UInt32  level_maxmin_coeff:3;
        RBus_UInt32  h4h10_blend_en:1;
        RBus_UInt32  lpf_blend_en:1;
        RBus_UInt32  lpf_blend_range:2;
        RBus_UInt32  lpf_blend_lowbound:8;
    };
}scaleup_dm_uzu_10tap_dering_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  level_flatness_coeff:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  level_maxmin_coeff:3;
        RBus_UInt32  dering_dbg_mode:2;
        RBus_UInt32  v4v8_blend_range:2;
        RBus_UInt32  res3:4;
        RBus_UInt32  v4v8_blend_lowbound:8;
        RBus_UInt32  res4:6;
        RBus_UInt32  range_center:1;
        RBus_UInt32  range_side:1;
    };
}scaleup_dm_uzu_8tap_deringv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pk_mask_c0:5;
        RBus_UInt32  pk_mask_c1:4;
        RBus_UInt32  pk_mask_c2:4;
        RBus_UInt32  pk_en:1;
        RBus_UInt32  pk_coring:8;
        RBus_UInt32  pk_x1:8;
    };
}scaleup_dm_uzu_peaking_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pk_mask_c3:4;
        RBus_UInt32  pk_shiftbit:2;
        RBus_UInt32  pk_offset:8;
        RBus_UInt32  pk_lmtp:4;
        RBus_UInt32  pk_lmtn:4;
        RBus_UInt32  pk_g1:4;
        RBus_UInt32  pk_g2:4;
    };
}scaleup_dm_uzu_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vcti_type3_thd:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  vcti_gain:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  vcti_select:2;
        RBus_UInt32  vcti_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}scaleup_dm_mem_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_dm_mem_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  crc_3d_en:1;
    };
}scaleup_mem_crc_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}scaleup_mem_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}scaleup_mem_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}scaleup_mem_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_err_cnt:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}scaleup_mem_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ch_sel:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}scaleup_d_uzu_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uzu_crc:32;
    };
}scaleup_d_uzu_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c0_y:8;
        RBus_UInt32  patgen_c0_cr:8;
        RBus_UInt32  patgen_c0_cb:8;
    };
}scaleup_d_uzu_patgen_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c1_y:8;
        RBus_UInt32  patgen_c1_cr:8;
        RBus_UInt32  patgen_c1_cb:8;
    };
}scaleup_d_uzu_patgen_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c2_y:8;
        RBus_UInt32  patgen_c2_cr:8;
        RBus_UInt32  patgen_c2_cb:8;
    };
}scaleup_d_uzu_patgen_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c3_y:8;
        RBus_UInt32  patgen_c3_cr:8;
        RBus_UInt32  patgen_c3_cb:8;
    };
}scaleup_d_uzu_patgen_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_tog_num:5;
        RBus_UInt32  patgen_tog_sel:2;
        RBus_UInt32  patgen_lflag:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_width:22;
    };
}scaleup_d_uzu_patgen_frame_toggle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  patgen_lflag_1:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_width_1:22;
    };
}scaleup_d_uzu_patgen_frame_toggle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  patgen_lflag_2:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_width_2:22;
    };
}scaleup_d_uzu_patgen_frame_toggle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  patgen_lflag_3:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_width_3:22;
    };
}scaleup_d_uzu_patgen_frame_toggle3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ch_sel:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}scaleup_accessdata_ctrl_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  starty:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  startx:13;
    };
}scaleup_accessdata_posctrl_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}scaleup_readdata_data_y1_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y10:10;
    };
}scaleup_readdata_data_y2_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}scaleup_readdata_data_c1_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}scaleup_readdata_data_c2_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}scaleup_readdata_data_c3_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}scaleup_readdata_data_c4_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcti_lpf_lbound2:10;
        RBus_UInt32  vcti_lpf_hbound2:10;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}scaleup_writedata_data_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcti_lpf_lbound1:10;
        RBus_UInt32  hor_m_front_drop:11;
        RBus_UInt32  hor_m_back_drop:11;
    };
}scaleup_dm_uzumain_h_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcti_lpf_hbound1:10;
        RBus_UInt32  vcti_low_pass_filter_en:1;
        RBus_UInt32  ver_m_front_drop:9;
        RBus_UInt32  res1:2;
        RBus_UInt32  vcti_lpf_mode:1;
        RBus_UInt32  ver_m_back_drop:9;
    };
}scaleup_dm_uzumain_v_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  hor_m_front_drop_odd:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  hor_m_back_drop_odd:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  pixel_drop_mode:1;
        RBus_UInt32  res4:2;
    };
}scaleup_dm_uzu_partial_drop_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt8_upbnd:8;
        RBus_UInt32  adapt8_sec3:8;
        RBus_UInt32  adapt8_sec2:8;
        RBus_UInt32  adapt8_sec1:8;
    };
}scaleup_dm_uzumain_adapt8tap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode:3;
        RBus_UInt32  res1:15;
        RBus_UInt32  usm_gain:6;
        RBus_UInt32  max_min_range:2;
        RBus_UInt32  max_minus_min_range:2;
        RBus_UInt32  max_minus_min_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  usm_en:1;
    };
}scaleup_dm_usm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_curve_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  gain_curve_thd0:8;
        RBus_UInt32  gain_curve_thd1:8;
        RBus_UInt32  gain_curve_thd2:8;
    };
}scaleup_dm_usm_gain_curve_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gain_curve_step0:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  gain_curve_step1:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  gain_curve_gain0:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  gain_curve_gain1:5;
    };
}scaleup_dm_usm_gain_curve_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_blend_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  limit_blend_thd0:8;
        RBus_UInt32  limit_blend_thd1:8;
    };
}scaleup_dm_usm_limit_blend_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  limit_blend_step:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  limit_blend_weight0:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  limit_blend_weight1:5;
    };
}scaleup_dm_usm_limit_blend_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  usm_hlpf_c3:6;
        RBus_UInt32  usm_hlpf_c2:4;
        RBus_UInt32  usm_hlpf_c1:4;
        RBus_UInt32  usm_hlpf_c0:4;
    };
}scaleup_dm_usm_hlpf_coef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180290e0_31_4:28;
        RBus_UInt32  v8tap_table_sel:2;
        RBus_UInt32  ver_mode_sel:2;
    };
}scaleup_dm_uzu_v8ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adaptv8_upbnd:8;
        RBus_UInt32  adaptv8_sec3:8;
        RBus_UInt32  adaptv8_sec2:8;
        RBus_UInt32  adaptv8_sec1:8;
    };
}scaleup_dm_uzu_adaptv8ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  ver_ini_l:8;
    };
}scaleup_dm_uzu_initial_value_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
    };
}scaleup_dm_uzu_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  buff_unf:1;
    };
}scaleup_dm_uzu_wclr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  left_ydi:8;
        RBus_UInt32  left_udi:8;
        RBus_UInt32  left_vdi:8;
    };
}scaleup_left_3d_ptg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_h_saddr:8;
        RBus_UInt32  left_v_saddr:8;
        RBus_UInt32  left_h_limit:8;
        RBus_UInt32  left_v_limit:8;
    };
}scaleup_left_3d_ptg_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_hsize:8;
        RBus_UInt32  left_vsize:8;
        RBus_UInt32  see_sadr_only_l:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  left_hstep:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  left_vstep:6;
    };
}scaleup_left_3d_ptg_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  right_ydi:8;
        RBus_UInt32  right_udi:8;
        RBus_UInt32  right_vdi:8;
    };
}scaleup_right_3d_ptg_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_h_saddr:8;
        RBus_UInt32  right_v_saddr:8;
        RBus_UInt32  right_h_limit:8;
        RBus_UInt32  right_v_limit:8;
    };
}scaleup_right_3d_ptg_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_hsize:8;
        RBus_UInt32  right_vsize:8;
        RBus_UInt32  see_sadr_only_r:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  right_hstep:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  right_vstep:6;
    };
}scaleup_right_3d_ptg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ptg_bg_ydi:8;
        RBus_UInt32  ptg_bg_udi:8;
        RBus_UInt32  ptg_bg_vdi:8;
    };
}scaleup_ptg_3d_ctr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  directionalscale_en:1;
        RBus_UInt32  mag_ang_lpf_en:1;
        RBus_UInt32  ds_phase_en:1;
        RBus_UInt32  ds_vlpf_en:1;
        RBus_UInt32  ds_hlpf_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  db_mode:4;
        RBus_UInt32  db_magfilter:4;
        RBus_UInt32  dummy18029130_15_0:16;
    };
}scaleup_dm_dir_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  transang_sec3:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  transang_sec2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  transang_sec1:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  transang_sec0:6;
    };
}scaleup_dm_dir_uzu_transang1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  transang_sec4:7;
        RBus_UInt32  res2:4;
        RBus_UInt32  transang_step4:4;
        RBus_UInt32  transang_step3:4;
        RBus_UInt32  transang_step2:4;
        RBus_UInt32  transang_step1:4;
        RBus_UInt32  transang_step0:4;
    };
}scaleup_dm_dir_uzu_transang2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  angdiff_lowbnd:6;
        RBus_UInt32  res2:5;
        RBus_UInt32  angdiff_step:3;
        RBus_UInt32  mag_lowbnd:8;
        RBus_UInt32  res3:5;
        RBus_UInt32  mag_step:3;
    };
}scaleup_dm_dir_uzu_angmagscore_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  onepx_en:1;
        RBus_UInt32  onepx_centerdiffthd:4;
        RBus_UInt32  onepx_sidediffthd:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  onepx_diffstep:3;
        RBus_UInt32  onepx_lowbnd:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  onepx_step:3;
        RBus_UInt32  res4:4;
    };
}scaleup_dm_dir_uzu_onepixeldetect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  angdiff_lowbnd2:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  angdiff_step2:3;
        RBus_UInt32  res3:4;
        RBus_UInt32  conf_step:3;
        RBus_UInt32  conf_offset:5;
        RBus_UInt32  conf_lowbnd:8;
    };
}scaleup_dm_dir_uzu_conf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  checkhv_angrange:4;
        RBus_UInt32  checkhv_en:1;
        RBus_UInt32  checkhv_angstep:3;
        RBus_UInt32  checkhv_diffstep:3;
        RBus_UInt32  checkhv_diffrange:5;
        RBus_UInt32  checkpn_angrange:4;
        RBus_UInt32  checkpn_en:1;
        RBus_UInt32  checkpn_angstep:3;
        RBus_UInt32  checkpn_diffstep:3;
        RBus_UInt32  checkpn_diffrange:5;
    };
}scaleup_dm_dir_uzu_anglecheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  bist_fail_25:1;
        RBus_UInt32  bist_fail_24:1;
        RBus_UInt32  bist_fail_23:1;
        RBus_UInt32  bist_fail_22:1;
        RBus_UInt32  bist_fail_21:1;
        RBus_UInt32  bist_fail_20:1;
        RBus_UInt32  bist_fail_19:1;
        RBus_UInt32  bist_fail_18:1;
        RBus_UInt32  bist_fail_17:1;
        RBus_UInt32  bist_fail_16:1;
        RBus_UInt32  bist_fail_15:1;
        RBus_UInt32  bist_fail_14:1;
        RBus_UInt32  bist_fail_13:1;
        RBus_UInt32  bist_fail_12:1;
        RBus_UInt32  bist_fail_11:1;
        RBus_UInt32  bist_fail_10:1;
        RBus_UInt32  bist_fail_9:1;
        RBus_UInt32  bist_fail_8:1;
        RBus_UInt32  bist_fail_7:1;
        RBus_UInt32  bist_fail_6:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}scaleup_dm_uzu_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  drf_bist_fail_25:1;
        RBus_UInt32  drf_bist_fail_24:1;
        RBus_UInt32  drf_bist_fail_23:1;
        RBus_UInt32  drf_bist_fail_22:1;
        RBus_UInt32  drf_bist_fail_21:1;
        RBus_UInt32  drf_bist_fail_20:1;
        RBus_UInt32  drf_bist_fail_19:1;
        RBus_UInt32  drf_bist_fail_18:1;
        RBus_UInt32  drf_bist_fail_17:1;
        RBus_UInt32  drf_bist_fail_16:1;
        RBus_UInt32  drf_bist_fail_15:1;
        RBus_UInt32  drf_bist_fail_14:1;
        RBus_UInt32  drf_bist_fail_13:1;
        RBus_UInt32  drf_bist_fail_12:1;
        RBus_UInt32  drf_bist_fail_11:1;
        RBus_UInt32  drf_bist_fail_10:1;
        RBus_UInt32  drf_bist_fail_9:1;
        RBus_UInt32  drf_bist_fail_8:1;
        RBus_UInt32  drf_bist_fail_7:1;
        RBus_UInt32  drf_bist_fail_6:1;
        RBus_UInt32  drf_bist_fail_5:1;
        RBus_UInt32  drf_bist_fail_4:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
    };
}scaleup_dm_uzu_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_0:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  rme_25:1;
        RBus_UInt32  rme_24:1;
        RBus_UInt32  rme_23:1;
        RBus_UInt32  rme_22:1;
        RBus_UInt32  rme_21:1;
        RBus_UInt32  rme_20:1;
        RBus_UInt32  rme_19:1;
        RBus_UInt32  rme_18:1;
        RBus_UInt32  rme_17:1;
        RBus_UInt32  rme_16:1;
        RBus_UInt32  rme_15:1;
        RBus_UInt32  rme_14:1;
        RBus_UInt32  rme_13:1;
        RBus_UInt32  rme_12:1;
        RBus_UInt32  rme_11:1;
        RBus_UInt32  rme_10:1;
        RBus_UInt32  rme_9:1;
        RBus_UInt32  rme_8:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
    };
}scaleup_dm_uzu_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_7:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
    };
}scaleup_dm_uzu_bist_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_15:4;
        RBus_UInt32  rm_14:4;
        RBus_UInt32  rm_13:4;
        RBus_UInt32  rm_12:4;
        RBus_UInt32  rm_11:4;
        RBus_UInt32  rm_10:4;
        RBus_UInt32  rm_9:4;
        RBus_UInt32  rm_8:4;
    };
}scaleup_dm_uzu_bist_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_23:4;
        RBus_UInt32  rm_22:4;
        RBus_UInt32  rm_21:4;
        RBus_UInt32  rm_20:4;
        RBus_UInt32  rm_19:4;
        RBus_UInt32  rm_18:4;
        RBus_UInt32  rm_17:4;
        RBus_UInt32  rm_16:4;
    };
}scaleup_dm_uzu_bist_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rm_25:4;
        RBus_UInt32  rm_24:4;
    };
}scaleup_dm_uzu_bist_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  coef_rw_en:1;
        RBus_UInt32  coef_rw_sel:1;
        RBus_UInt32  coef_tab_sel:3;
    };
}scaleup_coef_table_rw_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  coef_addr:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  coef_write:1;
        RBus_UInt32  res3:4;
    };
}scaleup_coef_table_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coef1:12;
    };
}scaleup_coef_table_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coef3:12;
    };
}scaleup_coef_table_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coef5:12;
    };
}scaleup_coef_table_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coef7:12;
    };
}scaleup_coef_table_ctl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coef9:12;
    };
}scaleup_coef_table_ctl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  coef_acc_error:1;
    };
}scaleup_coef_table_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  wd_sub_buf_udf_en:1;
        RBus_UInt32  irq_sub_buf_udf_en:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  in_fmt_dup:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  in_fmt_conv:1;
        RBus_UInt32  conv_type:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  h_zoom_en:1;
    };
}scaleup_ds_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hor_factor:20;
    };
}scaleup_ds_uzu_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ver_factor:20;
    };
}scaleup_ds_uzu_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  ver_ini:8;
    };
}scaleup_ds_uzu_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hor_input_size:13;
        RBus_UInt32  res2:4;
        RBus_UInt32  ver_input_size:12;
    };
}scaleup_ds_uzu_input_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}scaleup_ds_mem_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_ds_mem_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  hor_s_front_drop:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  hor_s_back_drop:11;
    };
}scaleup_ds_uzusub_h_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ver_s_front_drop:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  ver_s_back_drop:9;
    };
}scaleup_ds_uzusub_v_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
    };
}scaleup_ds_uzu_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  auto_cmp_en:1;
    };
}scaleup_ds_mem_crc_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_crc:32;
    };
}scaleup_ds_mem_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_err_cnt:16;
    };
}scaleup_ds_mem_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  buff_unf:1;
    };
}scaleup_ds_uzu_wclr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c0:8;
        RBus_UInt32  ver_c1:8;
        RBus_UInt32  ver_c2:8;
        RBus_UInt32  ver_c3:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c0_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c4:8;
        RBus_UInt32  ver_c5:8;
        RBus_UInt32  ver_c6:8;
        RBus_UInt32  ver_c7:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c4_c7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c8:8;
        RBus_UInt32  ver_c9:8;
        RBus_UInt32  ver_c10:8;
        RBus_UInt32  ver_c11:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c8_c11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c12:8;
        RBus_UInt32  ver_c13:8;
        RBus_UInt32  ver_c14:8;
        RBus_UInt32  ver_c15:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c12_c15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c0:8;
        RBus_UInt32  hor_c1:8;
        RBus_UInt32  hor_c2:8;
        RBus_UInt32  hor_c3:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c4:8;
        RBus_UInt32  hor_c5:8;
        RBus_UInt32  hor_c6:8;
        RBus_UInt32  hor_c7:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c8:8;
        RBus_UInt32  hor_c9:8;
        RBus_UInt32  hor_c10:8;
        RBus_UInt32  hor_c11:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c12:8;
        RBus_UInt32  hor_c13:8;
        RBus_UInt32  hor_c14:8;
        RBus_UInt32  hor_c15:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}scaleup_ds_uzu_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}scaleup_ds_uzu_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  patgen_sync:1;
        RBus_UInt32  patgen_mode:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_field:1;
        RBus_UInt32  patgen_sel:1;
    };
}scaleup_ds_uzu_globle_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c0_y:8;
        RBus_UInt32  patgen_c0_cr:8;
        RBus_UInt32  patgen_c0_cb:8;
    };
}scaleup_ds_uzu_patgen_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c1_y:8;
        RBus_UInt32  patgen_c1_cr:8;
        RBus_UInt32  patgen_c1_cb:8;
    };
}scaleup_ds_uzu_patgen_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c2_y:8;
        RBus_UInt32  patgen_c2_cr:8;
        RBus_UInt32  patgen_c2_cb:8;
    };
}scaleup_ds_uzu_patgen_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c3_y:8;
        RBus_UInt32  patgen_c3_cr:8;
        RBus_UInt32  patgen_c3_cb:8;
    };
}scaleup_ds_uzu_patgen_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_tog_num:5;
        RBus_UInt32  patgen_tog_sel:2;
        RBus_UInt32  res1:3;
        RBus_UInt32  patgen_width:22;
    };
}scaleup_ds_uzu_patgen_frame_toggle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  patgen_width_1:22;
    };
}scaleup_ds_uzu_patgen_frame_toggle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  patgen_width_2:22;
    };
}scaleup_ds_uzu_patgen_frame_toggle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  patgen_width_3:22;
    };
}scaleup_ds_uzu_patgen_frame_toggle3_RBUS;

#else //apply LITTLE_ENDIAN

//======SCALEUP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_sel:2;
        RBus_UInt32  patgen_field:1;
        RBus_UInt32  patgen_lflag_en:1;
        RBus_UInt32  patgen_mode:3;
        RBus_UInt32  patgen_sync:1;
        RBus_UInt32  out_even_black:1;
        RBus_UInt32  out_black_en:1;
        RBus_UInt32  in_even_black:1;
        RBus_UInt32  in_black_en:1;
        RBus_UInt32  lr_black_sel:1;
        RBus_UInt32  lr_black_en:1;
        RBus_UInt32  uzu_bypass_force:1;
        RBus_UInt32  uzu_bypass_no_pwrsave:1;
        RBus_UInt32  dummy18029000_31_16:16;
    };
}scaleup_d_uzu_globle_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  in_fmt_dup:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  conv_type:1;
        RBus_UInt32  in_fmt_conv:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  d_3d_sel_en:1;
        RBus_UInt32  hor10_table_sel:2;
        RBus_UInt32  h_c_consttab_sel:2;
        RBus_UInt32  h_y_consttab_sel:2;
        RBus_UInt32  v_c_consttab_sel:2;
        RBus_UInt32  v_y_consttab_sel:2;
        RBus_UInt32  bypassfornr:1;
        RBus_UInt32  irq_main_buf_udf_en:1;
        RBus_UInt32  wd_main_buf_udf_en:1;
        RBus_UInt32  ver_pr_mode:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  hor_mode_sel:3;
    };
}scaleup_dm_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_dm_uzu_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_dm_uzu_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_delta1:13;
        RBus_UInt32  res1:19;
    };
}scaleup_dm_uzu_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_delta2:13;
        RBus_UInt32  res1:19;
    };
}scaleup_dm_uzu_hor_delta2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_segment1:11;
        RBus_UInt32  res1:21;
    };
}scaleup_dm_uzu_hor_segment1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_segment2:11;
        RBus_UInt32  res1:21;
    };
}scaleup_dm_uzu_hor_segment2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_segment3:12;
        RBus_UInt32  res1:20;
    };
}scaleup_dm_uzu_hor_segment3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res1:16;
    };
}scaleup_dm_uzu_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_input_size:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  hor_input_size:13;
        RBus_UInt32  res2:3;
    };
}scaleup_dm_uzu_input_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpf_blend_lowbound:8;
        RBus_UInt32  lpf_blend_range:2;
        RBus_UInt32  lpf_blend_en:1;
        RBus_UInt32  h4h10_blend_en:1;
        RBus_UInt32  level_maxmin_coeff:3;
        RBus_UInt32  lpf_blend_mask_sel:1;
        RBus_UInt32  h4h10_blend_lowbound:8;
        RBus_UInt32  h4h10_blend_range:2;
        RBus_UInt32  dering_dbg_mode:2;
        RBus_UInt32  level_flatness_coeff:3;
        RBus_UInt32  res1:1;
    };
}scaleup_dm_uzu_10tap_dering_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  range_side:1;
        RBus_UInt32  range_center:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  v4v8_blend_lowbound:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  v4v8_blend_range:2;
        RBus_UInt32  dering_dbg_mode:2;
        RBus_UInt32  level_maxmin_coeff:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  level_flatness_coeff:3;
        RBus_UInt32  res4:1;
    };
}scaleup_dm_uzu_8tap_deringv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pk_x1:8;
        RBus_UInt32  pk_coring:8;
        RBus_UInt32  pk_en:1;
        RBus_UInt32  pk_mask_c2:4;
        RBus_UInt32  pk_mask_c1:4;
        RBus_UInt32  pk_mask_c0:5;
        RBus_UInt32  res1:2;
    };
}scaleup_dm_uzu_peaking_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pk_g2:4;
        RBus_UInt32  pk_g1:4;
        RBus_UInt32  pk_lmtn:4;
        RBus_UInt32  pk_lmtp:4;
        RBus_UInt32  pk_offset:8;
        RBus_UInt32  pk_shiftbit:2;
        RBus_UInt32  pk_mask_c3:4;
        RBus_UInt32  res1:2;
    };
}scaleup_dm_uzu_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  vcti_en:1;
        RBus_UInt32  vcti_select:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  vcti_gain:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  vcti_type3_thd:6;
        RBus_UInt32  res4:10;
    };
}scaleup_dm_mem_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_dm_mem_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  res1:29;
    };
}scaleup_mem_crc_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}scaleup_mem_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}scaleup_mem_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}scaleup_mem_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  r_crc_err_cnt:16;
    };
}scaleup_mem_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  ch_sel:1;
        RBus_UInt32  res1:29;
    };
}scaleup_d_uzu_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uzu_crc:32;
    };
}scaleup_d_uzu_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c0_cb:8;
        RBus_UInt32  patgen_c0_cr:8;
        RBus_UInt32  patgen_c0_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_d_uzu_patgen_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c1_cb:8;
        RBus_UInt32  patgen_c1_cr:8;
        RBus_UInt32  patgen_c1_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_d_uzu_patgen_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c2_cb:8;
        RBus_UInt32  patgen_c2_cr:8;
        RBus_UInt32  patgen_c2_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_d_uzu_patgen_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c3_cb:8;
        RBus_UInt32  patgen_c3_cr:8;
        RBus_UInt32  patgen_c3_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_d_uzu_patgen_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width:22;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_lflag:1;
        RBus_UInt32  patgen_tog_sel:2;
        RBus_UInt32  patgen_tog_num:5;
    };
}scaleup_d_uzu_patgen_frame_toggle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_1:22;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_lflag_1:1;
        RBus_UInt32  res2:7;
    };
}scaleup_d_uzu_patgen_frame_toggle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_2:22;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_lflag_2:1;
        RBus_UInt32  res2:7;
    };
}scaleup_d_uzu_patgen_frame_toggle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_3:22;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_lflag_3:1;
        RBus_UInt32  res2:7;
    };
}scaleup_d_uzu_patgen_frame_toggle3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  ch_sel:1;
        RBus_UInt32  res1:29;
    };
}scaleup_accessdata_ctrl_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:12;
        RBus_UInt32  res2:4;
    };
}scaleup_accessdata_posctrl_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_y1_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_y2_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_c1_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_c2_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_c3_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_c4_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  vcti_lpf_hbound2:10;
        RBus_UInt32  vcti_lpf_lbound2:10;
    };
}scaleup_writedata_data_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_m_back_drop:11;
        RBus_UInt32  hor_m_front_drop:11;
        RBus_UInt32  vcti_lpf_lbound1:10;
    };
}scaleup_dm_uzumain_h_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_m_back_drop:9;
        RBus_UInt32  vcti_lpf_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ver_m_front_drop:9;
        RBus_UInt32  vcti_low_pass_filter_en:1;
        RBus_UInt32  vcti_lpf_hbound1:10;
    };
}scaleup_dm_uzumain_v_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pixel_drop_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hor_m_back_drop_odd:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  hor_m_front_drop_odd:11;
        RBus_UInt32  res4:5;
    };
}scaleup_dm_uzu_partial_drop_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt8_sec1:8;
        RBus_UInt32  adapt8_sec2:8;
        RBus_UInt32  adapt8_sec3:8;
        RBus_UInt32  adapt8_upbnd:8;
    };
}scaleup_dm_uzumain_adapt8tap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usm_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  max_minus_min_mode:1;
        RBus_UInt32  max_minus_min_range:2;
        RBus_UInt32  max_min_range:2;
        RBus_UInt32  usm_gain:6;
        RBus_UInt32  res2:15;
        RBus_UInt32  debug_mode:3;
    };
}scaleup_dm_usm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_curve_thd2:8;
        RBus_UInt32  gain_curve_thd1:8;
        RBus_UInt32  gain_curve_thd0:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  gain_curve_en:1;
    };
}scaleup_dm_usm_gain_curve_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_curve_gain1:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  gain_curve_gain0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  gain_curve_step1:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  gain_curve_step0:3;
        RBus_UInt32  res4:5;
    };
}scaleup_dm_usm_gain_curve_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_blend_thd1:8;
        RBus_UInt32  limit_blend_thd0:8;
        RBus_UInt32  res1:15;
        RBus_UInt32  limit_blend_en:1;
    };
}scaleup_dm_usm_limit_blend_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_blend_weight1:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  limit_blend_weight0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  limit_blend_step:3;
        RBus_UInt32  res3:13;
    };
}scaleup_dm_usm_limit_blend_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usm_hlpf_c0:4;
        RBus_UInt32  usm_hlpf_c1:4;
        RBus_UInt32  usm_hlpf_c2:4;
        RBus_UInt32  usm_hlpf_c3:6;
        RBus_UInt32  res1:14;
    };
}scaleup_dm_usm_hlpf_coef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_mode_sel:2;
        RBus_UInt32  v8tap_table_sel:2;
        RBus_UInt32  dummy180290e0_31_4:28;
    };
}scaleup_dm_uzu_v8ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adaptv8_sec1:8;
        RBus_UInt32  adaptv8_sec2:8;
        RBus_UInt32  adaptv8_sec3:8;
        RBus_UInt32  adaptv8_upbnd:8;
    };
}scaleup_dm_uzu_adaptv8ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini_l:8;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  res1:16;
    };
}scaleup_dm_uzu_initial_value_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  res1:29;
    };
}scaleup_dm_uzu_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buff_unf:1;
        RBus_UInt32  res1:31;
    };
}scaleup_dm_uzu_wclr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_vdi:8;
        RBus_UInt32  left_udi:8;
        RBus_UInt32  left_ydi:8;
        RBus_UInt32  res1:8;
    };
}scaleup_left_3d_ptg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_v_limit:8;
        RBus_UInt32  left_h_limit:8;
        RBus_UInt32  left_v_saddr:8;
        RBus_UInt32  left_h_saddr:8;
    };
}scaleup_left_3d_ptg_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_vstep:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  left_hstep:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  see_sadr_only_l:1;
        RBus_UInt32  left_vsize:8;
        RBus_UInt32  left_hsize:8;
    };
}scaleup_left_3d_ptg_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_vdi:8;
        RBus_UInt32  right_udi:8;
        RBus_UInt32  right_ydi:8;
        RBus_UInt32  res1:8;
    };
}scaleup_right_3d_ptg_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_v_limit:8;
        RBus_UInt32  right_h_limit:8;
        RBus_UInt32  right_v_saddr:8;
        RBus_UInt32  right_h_saddr:8;
    };
}scaleup_right_3d_ptg_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_vstep:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  right_hstep:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  see_sadr_only_r:1;
        RBus_UInt32  right_vsize:8;
        RBus_UInt32  right_hsize:8;
    };
}scaleup_right_3d_ptg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ptg_bg_vdi:8;
        RBus_UInt32  ptg_bg_udi:8;
        RBus_UInt32  ptg_bg_ydi:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ptg_3d_ctr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029130_15_0:16;
        RBus_UInt32  db_magfilter:4;
        RBus_UInt32  db_mode:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  ds_hlpf_en:1;
        RBus_UInt32  ds_vlpf_en:1;
        RBus_UInt32  ds_phase_en:1;
        RBus_UInt32  mag_ang_lpf_en:1;
        RBus_UInt32  directionalscale_en:1;
    };
}scaleup_dm_dir_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  transang_sec0:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  transang_sec1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  transang_sec2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  transang_sec3:7;
        RBus_UInt32  res4:1;
    };
}scaleup_dm_dir_uzu_transang1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  transang_step0:4;
        RBus_UInt32  transang_step1:4;
        RBus_UInt32  transang_step2:4;
        RBus_UInt32  transang_step3:4;
        RBus_UInt32  transang_step4:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  transang_sec4:7;
        RBus_UInt32  res2:1;
    };
}scaleup_dm_dir_uzu_transang2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mag_step:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  mag_lowbnd:8;
        RBus_UInt32  angdiff_step:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  angdiff_lowbnd:6;
        RBus_UInt32  res3:2;
    };
}scaleup_dm_dir_uzu_angmagscore_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  onepx_step:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  onepx_lowbnd:8;
        RBus_UInt32  onepx_diffstep:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  onepx_sidediffthd:4;
        RBus_UInt32  onepx_centerdiffthd:4;
        RBus_UInt32  onepx_en:1;
        RBus_UInt32  res4:3;
    };
}scaleup_dm_dir_uzu_onepixeldetect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  conf_lowbnd:8;
        RBus_UInt32  conf_offset:5;
        RBus_UInt32  conf_step:3;
        RBus_UInt32  res1:4;
        RBus_UInt32  angdiff_step2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  angdiff_lowbnd2:6;
        RBus_UInt32  res3:2;
    };
}scaleup_dm_dir_uzu_conf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  checkpn_diffrange:5;
        RBus_UInt32  checkpn_diffstep:3;
        RBus_UInt32  checkpn_angstep:3;
        RBus_UInt32  checkpn_en:1;
        RBus_UInt32  checkpn_angrange:4;
        RBus_UInt32  checkhv_diffrange:5;
        RBus_UInt32  checkhv_diffstep:3;
        RBus_UInt32  checkhv_angstep:3;
        RBus_UInt32  checkhv_en:1;
        RBus_UInt32  checkhv_angrange:4;
    };
}scaleup_dm_dir_uzu_anglecheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_6:1;
        RBus_UInt32  bist_fail_7:1;
        RBus_UInt32  bist_fail_8:1;
        RBus_UInt32  bist_fail_9:1;
        RBus_UInt32  bist_fail_10:1;
        RBus_UInt32  bist_fail_11:1;
        RBus_UInt32  bist_fail_12:1;
        RBus_UInt32  bist_fail_13:1;
        RBus_UInt32  bist_fail_14:1;
        RBus_UInt32  bist_fail_15:1;
        RBus_UInt32  bist_fail_16:1;
        RBus_UInt32  bist_fail_17:1;
        RBus_UInt32  bist_fail_18:1;
        RBus_UInt32  bist_fail_19:1;
        RBus_UInt32  bist_fail_20:1;
        RBus_UInt32  bist_fail_21:1;
        RBus_UInt32  bist_fail_22:1;
        RBus_UInt32  bist_fail_23:1;
        RBus_UInt32  bist_fail_24:1;
        RBus_UInt32  bist_fail_25:1;
        RBus_UInt32  res1:6;
    };
}scaleup_dm_uzu_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_4:1;
        RBus_UInt32  drf_bist_fail_5:1;
        RBus_UInt32  drf_bist_fail_6:1;
        RBus_UInt32  drf_bist_fail_7:1;
        RBus_UInt32  drf_bist_fail_8:1;
        RBus_UInt32  drf_bist_fail_9:1;
        RBus_UInt32  drf_bist_fail_10:1;
        RBus_UInt32  drf_bist_fail_11:1;
        RBus_UInt32  drf_bist_fail_12:1;
        RBus_UInt32  drf_bist_fail_13:1;
        RBus_UInt32  drf_bist_fail_14:1;
        RBus_UInt32  drf_bist_fail_15:1;
        RBus_UInt32  drf_bist_fail_16:1;
        RBus_UInt32  drf_bist_fail_17:1;
        RBus_UInt32  drf_bist_fail_18:1;
        RBus_UInt32  drf_bist_fail_19:1;
        RBus_UInt32  drf_bist_fail_20:1;
        RBus_UInt32  drf_bist_fail_21:1;
        RBus_UInt32  drf_bist_fail_22:1;
        RBus_UInt32  drf_bist_fail_23:1;
        RBus_UInt32  drf_bist_fail_24:1;
        RBus_UInt32  drf_bist_fail_25:1;
        RBus_UInt32  res1:6;
    };
}scaleup_dm_uzu_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  rme_8:1;
        RBus_UInt32  rme_9:1;
        RBus_UInt32  rme_10:1;
        RBus_UInt32  rme_11:1;
        RBus_UInt32  rme_12:1;
        RBus_UInt32  rme_13:1;
        RBus_UInt32  rme_14:1;
        RBus_UInt32  rme_15:1;
        RBus_UInt32  rme_16:1;
        RBus_UInt32  rme_17:1;
        RBus_UInt32  rme_18:1;
        RBus_UInt32  rme_19:1;
        RBus_UInt32  rme_20:1;
        RBus_UInt32  rme_21:1;
        RBus_UInt32  rme_22:1;
        RBus_UInt32  rme_23:1;
        RBus_UInt32  rme_24:1;
        RBus_UInt32  rme_25:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  ls_0:1;
    };
}scaleup_dm_uzu_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_7:4;
    };
}scaleup_dm_uzu_bist_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_8:4;
        RBus_UInt32  rm_9:4;
        RBus_UInt32  rm_10:4;
        RBus_UInt32  rm_11:4;
        RBus_UInt32  rm_12:4;
        RBus_UInt32  rm_13:4;
        RBus_UInt32  rm_14:4;
        RBus_UInt32  rm_15:4;
    };
}scaleup_dm_uzu_bist_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_16:4;
        RBus_UInt32  rm_17:4;
        RBus_UInt32  rm_18:4;
        RBus_UInt32  rm_19:4;
        RBus_UInt32  rm_20:4;
        RBus_UInt32  rm_21:4;
        RBus_UInt32  rm_22:4;
        RBus_UInt32  rm_23:4;
    };
}scaleup_dm_uzu_bist_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_24:4;
        RBus_UInt32  rm_25:4;
        RBus_UInt32  res1:24;
    };
}scaleup_dm_uzu_bist_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_tab_sel:3;
        RBus_UInt32  coef_rw_sel:1;
        RBus_UInt32  coef_rw_en:1;
        RBus_UInt32  res1:27;
    };
}scaleup_coef_table_rw_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef_write:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  coef_addr:8;
        RBus_UInt32  res3:16;
    };
}scaleup_coef_table_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coef0:12;
        RBus_UInt32  res2:4;
    };
}scaleup_coef_table_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coef2:12;
        RBus_UInt32  res2:4;
    };
}scaleup_coef_table_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coef4:12;
        RBus_UInt32  res2:4;
    };
}scaleup_coef_table_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coef6:12;
        RBus_UInt32  res2:4;
    };
}scaleup_coef_table_ctl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coef8:12;
        RBus_UInt32  res2:4;
    };
}scaleup_coef_table_ctl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_acc_error:1;
        RBus_UInt32  res1:31;
    };
}scaleup_coef_table_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  conv_type:1;
        RBus_UInt32  in_fmt_conv:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  in_fmt_dup:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  irq_sub_buf_udf_en:1;
        RBus_UInt32  wd_sub_buf_udf_en:1;
        RBus_UInt32  res2:7;
    };
}scaleup_ds_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_ds_uzu_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_ds_uzu_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res1:16;
    };
}scaleup_ds_uzu_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_input_size:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  hor_input_size:13;
        RBus_UInt32  res2:3;
    };
}scaleup_ds_uzu_input_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  res1:30;
    };
}scaleup_ds_mem_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_ds_mem_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_s_back_drop:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  hor_s_front_drop:11;
        RBus_UInt32  res2:9;
    };
}scaleup_ds_uzusub_h_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_s_back_drop:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  ver_s_front_drop:9;
        RBus_UInt32  res2:7;
    };
}scaleup_ds_uzusub_v_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  res1:29;
    };
}scaleup_ds_uzu_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_cmp_en:1;
        RBus_UInt32  res1:31;
    };
}scaleup_ds_mem_crc_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_crc:32;
    };
}scaleup_ds_mem_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_err_cnt:16;
        RBus_UInt32  res1:16;
    };
}scaleup_ds_mem_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buff_unf:1;
        RBus_UInt32  res1:31;
    };
}scaleup_ds_uzu_wclr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c3:8;
        RBus_UInt32  ver_c2:8;
        RBus_UInt32  ver_c1:8;
        RBus_UInt32  ver_c0:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c0_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c7:8;
        RBus_UInt32  ver_c6:8;
        RBus_UInt32  ver_c5:8;
        RBus_UInt32  ver_c4:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c4_c7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c11:8;
        RBus_UInt32  ver_c10:8;
        RBus_UInt32  ver_c9:8;
        RBus_UInt32  ver_c8:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c8_c11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c15:8;
        RBus_UInt32  ver_c14:8;
        RBus_UInt32  ver_c13:8;
        RBus_UInt32  ver_c12:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c12_c15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c3:8;
        RBus_UInt32  hor_c2:8;
        RBus_UInt32  hor_c1:8;
        RBus_UInt32  hor_c0:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c7:8;
        RBus_UInt32  hor_c6:8;
        RBus_UInt32  hor_c5:8;
        RBus_UInt32  hor_c4:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c11:8;
        RBus_UInt32  hor_c10:8;
        RBus_UInt32  hor_c9:8;
        RBus_UInt32  hor_c8:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c15:8;
        RBus_UInt32  hor_c14:8;
        RBus_UInt32  hor_c13:8;
        RBus_UInt32  hor_c12:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}scaleup_ds_uzu_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
    };
}scaleup_ds_uzu_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_sel:1;
        RBus_UInt32  patgen_field:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_mode:3;
        RBus_UInt32  patgen_sync:1;
        RBus_UInt32  res2:24;
    };
}scaleup_ds_uzu_globle_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c0_cb:8;
        RBus_UInt32  patgen_c0_cr:8;
        RBus_UInt32  patgen_c0_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ds_uzu_patgen_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c1_cb:8;
        RBus_UInt32  patgen_c1_cr:8;
        RBus_UInt32  patgen_c1_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ds_uzu_patgen_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c2_cb:8;
        RBus_UInt32  patgen_c2_cr:8;
        RBus_UInt32  patgen_c2_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ds_uzu_patgen_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c3_cb:8;
        RBus_UInt32  patgen_c3_cr:8;
        RBus_UInt32  patgen_c3_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ds_uzu_patgen_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width:22;
        RBus_UInt32  res1:3;
        RBus_UInt32  patgen_tog_sel:2;
        RBus_UInt32  patgen_tog_num:5;
    };
}scaleup_ds_uzu_patgen_frame_toggle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_1:22;
        RBus_UInt32  res1:10;
    };
}scaleup_ds_uzu_patgen_frame_toggle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_2:22;
        RBus_UInt32  res1:10;
    };
}scaleup_ds_uzu_patgen_frame_toggle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_3:22;
        RBus_UInt32  res1:10;
    };
}scaleup_ds_uzu_patgen_frame_toggle3_RBUS;




#endif 


#endif 
