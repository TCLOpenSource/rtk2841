/**
* @file rbusColor_dccReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_DCC_REG_H_
#define _RBUS_COLOR_DCC_REG_H_

#include "rbusTypes.h"



//  COLOR_DCC Register Address



#define  COLOR_DCC_D_DCC_CTRL_VADDR                         	(0xb802e400)
#define  COLOR_DCC_DCC_Y_SRAM_TAB_CTL_VADDR                 	(0xb802e454)
#define  COLOR_DCC_DCC_Y_SRAM_TAB_PORT_VADDR                	(0xb802e458)
#define  COLOR_DCC_DCC_CTRL_LUMA_VADDR                      	(0xb802e404)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_MAIN_0_VADDR       	(0xb802e408)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_MAIN_1_VADDR       	(0xb802e40c)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_SUB_0_VADDR        	(0xb802e410)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_SUB_1_VADDR        	(0xb802e414)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_VADDR               	(0xb802e418)
#define  COLOR_DCC_DCC_C_SRAM_TAB_CTL_VADDR                 	(0xb802e41c)
#define  COLOR_DCC_DCC_C_SRAM_TAB_PORT_VADDR                	(0xb802e420)
#define  COLOR_DCC_D_DCC_DB_CTRL_VADDR                      	(0xb802e45c)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_VADDR                 	(0xb802e460)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_VADDR       	(0xb802e464)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_VADDR        	(0xb802e468)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_VADDR       	(0xb802e46c)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_VADDR        	(0xb802e470)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_VADDR       	(0xb802e474)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_VADDR        	(0xb802e478)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_VADDR       	(0xb802e47c)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_VADDR        	(0xb802e480)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_VADDR         	(0xb802e484)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_VADDR         	(0xb802e488)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_VADDR         	(0xb802e48c)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_VADDR         	(0xb802e490)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_VADDR         	(0xb802e494)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_VADDR         	(0xb802e498)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_VADDR         	(0xb802e49c)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_VADDR         	(0xb802e4a0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_VADDR       	(0xb802e4a4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_VADDR       	(0xb802e4a8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_VADDR       	(0xb802e4ac)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_VADDR       	(0xb802e4b0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_VADDR       	(0xb802e4b4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_VADDR       	(0xb802e4b8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_VADDR       	(0xb802e4bc)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_VADDR       	(0xb802e4c0)
#define  COLOR_DCC_D_DCC_FWUSED_0_VADDR                     	(0xb802e4f0)
#define  COLOR_DCC_D_DCC_FWUSED_1_VADDR                     	(0xb802e4f4)
#define  COLOR_DCC_D_DCC_FWUSED_2_VADDR                     	(0xb802e4f8)
#define  COLOR_DCC_D_DCC_FWUSED_3_VADDR                     	(0xb802e4fc)
#define  COLOR_DCC_D_DCC_BIST_0_VADDR                       	(0xb802e4e0)
#define  COLOR_DCC_D_DCC_BIST_1_VADDR                       	(0xb802e4e4)
#define  COLOR_DCC_D_DCC_BIST_2_VADDR                       	(0xb802e4e8)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_DCC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_overlay:1;
        RBus_UInt32  dummy1802e400_30_20:11;
        RBus_UInt32  main_table_segment:1;
        RBus_UInt32  main_table_sel:1;
        RBus_UInt32  dcc_main_mode_sel:2;
        RBus_UInt32  dummy1802e400_15_4:12;
        RBus_UInt32  sub_table_segment:1;
        RBus_UInt32  sub_table_sel:1;
        RBus_UInt32  dcc_sub_mode_sel:2;
    };
}color_dcc_d_dcc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  dcc_y_sram_tab_acc_index_cur:6;
        RBus_UInt32  dcc_y_sram_tab_acc_index:6;
        RBus_UInt32  dcc_y_sram_tab_rw_sel:2;
        RBus_UInt32  dcc_y_sram_tab_acc_sel:2;
        RBus_UInt32  dcc_y_sram_tab_acc_ready:1;
    };
}color_dcc_dcc_y_sram_tab_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_y_sram_tab_base:12;
        RBus_UInt32  dcc_y_sram_tab_g0:10;
        RBus_UInt32  dcc_y_sram_tab_g1:10;
    };
}color_dcc_dcc_y_sram_tab_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  luma_offset_main:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  luma_offset_sub:10;
    };
}color_dcc_dcc_ctrl_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_limit_en_main:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_limit_seg3_main:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg2_main:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg1_main:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  chroma_gain_limit_seg0_main:6;
    };
}color_dcc_dcc_chroma_gain_limit_main_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_gain_limit_seg7_main:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg6_main:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg5_main:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  chroma_gain_limit_seg4_main:6;
    };
}color_dcc_dcc_chroma_gain_limit_main_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_limit_en_sub:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_limit_seg3_sub:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg2_sub:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg1_sub:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  chroma_gain_limit_seg0_sub:6;
    };
}color_dcc_dcc_chroma_gain_limit_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_gain_limit_seg7_sub:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg6_sub:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg5_sub:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  chroma_gain_limit_seg4_sub:6;
    };
}color_dcc_dcc_chroma_gain_limit_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e418_31_30:2;
        RBus_UInt32  saturation_byy_v_tab_select_main:2;
        RBus_UInt32  saturation_byy_u_tab_select_main:2;
        RBus_UInt32  chroma_enhance_below_tab_select_main:2;
        RBus_UInt32  chroma_enhance_above_tab_select_main:2;
        RBus_UInt32  chroma_gain_base_main:3;
        RBus_UInt32  chroma_gain_lookup_mode_main:1;
        RBus_UInt32  chroma_gain_mode_main:1;
        RBus_UInt32  chroma_gain_en_main:1;
        RBus_UInt32  dummy1802e418_15_14:2;
        RBus_UInt32  saturation_byy_v_tab_select_sub:2;
        RBus_UInt32  saturation_byy_u_tab_select_sub:2;
        RBus_UInt32  chroma_enhance_below_tab_select_sub:2;
        RBus_UInt32  chroma_enhance_above_tab_select_sub:2;
        RBus_UInt32  chroma_gain_base_sub:3;
        RBus_UInt32  chroma_gain_lookup_mode_sub:1;
        RBus_UInt32  chroma_gain_mode_sub:1;
        RBus_UInt32  chroma_gain_en_sub:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dcc_c_sram_tab_acc_index_cur:5;
        RBus_UInt32  dcc_c_sram_tab_acc_index:5;
        RBus_UInt32  dcc_c_sram_tab_rw_sel:2;
        RBus_UInt32  dcc_c_sram_tab_acc_sel:3;
        RBus_UInt32  dcc_c_sram_tab_acc_ready:1;
    };
}color_dcc_dcc_c_sram_tab_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  dcc_c_sram_tab_base:7;
        RBus_UInt32  dcc_c_sram_tab_g0:7;
        RBus_UInt32  dcc_c_sram_tab_g1:7;
    };
}color_dcc_dcc_c_sram_tab_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
    };
}color_dcc_d_dcc_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  y_blending_debug_mode_en:1;
        RBus_UInt32  y_blending_debug_mode_sel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  y_blending_mode:1;
        RBus_UInt32  ratio_lpf_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_0_enhance_en:1;
        RBus_UInt32  y_blending_1_enhance_en:1;
        RBus_UInt32  y_blending_2_enhance_en:1;
        RBus_UInt32  y_blending_3_enhance_en:1;
        RBus_UInt32  y_blending_reg0_en:1;
        RBus_UInt32  y_blending_reg1_en:1;
        RBus_UInt32  y_blending_reg2_en:1;
        RBus_UInt32  y_blending_reg3_en:1;
        RBus_UInt32  y_blending_en:1;
    };
}color_dcc_d_dcc_skin_tone_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_0_u_center:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  y_blending_0_v_center:12;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_0_y_center:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  y_blending_0_y_range:4;
        RBus_UInt32  y_blending_0_u_range:4;
        RBus_UInt32  y_blending_0_v_range:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_1_u_center:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  y_blending_1_v_center:12;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_1_y_center:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  y_blending_1_y_range:4;
        RBus_UInt32  y_blending_1_u_range:4;
        RBus_UInt32  y_blending_1_v_range:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_2_u_center:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  y_blending_2_v_center:12;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_2_y_center:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  y_blending_2_y_range:4;
        RBus_UInt32  y_blending_2_u_range:4;
        RBus_UInt32  y_blending_2_v_range:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_3_u_center:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  y_blending_3_v_center:12;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_3_y_center:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  y_blending_3_y_range:4;
        RBus_UInt32  y_blending_3_u_range:4;
        RBus_UInt32  y_blending_3_v_range:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_0_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_0_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_0_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_0_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_0_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_0_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_0_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_0_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_1_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_1_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_1_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_1_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_1_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_1_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_1_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_1_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_2_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_2_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_2_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_2_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_2_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_2_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_2_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_2_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_3_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_3_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_3_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_3_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_3_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_3_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_3_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_3_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_0_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_0_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_0_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_0_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_0_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_0_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_0_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_0_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_1_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_1_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_1_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_1_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_1_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_1_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_1_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_1_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_2_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_2_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_2_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_2_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_2_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_2_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_2_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_2_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_3_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_3_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_3_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_3_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_3_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_3_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_3_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_3_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{

		RBus_UInt32  DCC_Level:4;// 28 ~ 31
		RBus_UInt32  res1:6; // 22:27
		RBus_UInt32  Boundary_Type:4; // 18:21
		RBus_UInt32  C_LPF_Tap:3; // 15~17
		RBus_UInt32  Curve_LPF_Enable:1; // 14
		RBus_UInt32  Hist_LPF_Enable:1; // 13
		RBus_UInt32  Output_LimitRange_Enable:1; // 12
		RBus_UInt32  Limit_range_Hist_Cut_Enable:1;// 11
		RBus_UInt32  Bin_boundary_Enable:1;// 10

		RBus_UInt32  Database_Enable:1; // 9
		RBus_UInt32  UserCurve_Enable:1; // 8
		RBus_UInt32  Expand_Enable:1; // 7
		RBus_UInt32  Scurve_Enable:1; // 6
		RBus_UInt32  Hist_Adjust_Enable:1;// 5
		RBus_UInt32  DCL_Enable:1; // 4

		RBus_UInt32  SkinTone:1; // 3
		RBus_UInt32  SceneChange:1; // 2
		RBus_UInt32  PureColor:1; // 1

		RBus_UInt32  Dummy_debug_enable:1;//0
    };
}color_dcc_d_dcc_fwused_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  VipInfo:1;
        RBus_UInt32  fw_1:7;
        RBus_UInt32  ThreeSEGXIndex1:8;
        RBus_UInt32  ThreeSEGXIndex0:8;
        RBus_UInt32  Res1:3;
        RBus_UInt32  HistogramScanningEnable:1;
        RBus_UInt32  CurveCoefInterpolationEnable:1;
        RBus_UInt32  Res0:1;
        RBus_UInt32  ThreeSegCurveEnable:1;
        RBus_UInt32  HighResCurveEnable:1;
    };
}color_dcc_d_dcc_fwused_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_2:24;
        RBus_UInt32  delay_time:8;
    };
}color_dcc_d_dcc_fwused_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ThreeSEGYNegOffset1:8;
		RBus_UInt32  ThreeSEGYNegOffset0:8;
        RBus_UInt32  ThreeSEGYPosOffset1:8;
        RBus_UInt32  ThreeSEGYPosOffset0:8;
    };
}color_dcc_d_dcc_fwused_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  drf_bist_fail_5:1;
        RBus_UInt32  drf_bist_fail_4:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
    };
}color_dcc_d_dcc_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
    };
}color_dcc_d_dcc_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  ls_5:1;
        RBus_UInt32  ls_4:1;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_0:1;
    };
}color_dcc_d_dcc_bist_2_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_DCC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_sub_mode_sel:2;
        RBus_UInt32  sub_table_sel:1;
        RBus_UInt32  sub_table_segment:1;
        RBus_UInt32  dummy1802e400_15_4:12;
        RBus_UInt32  dcc_main_mode_sel:2;
        RBus_UInt32  main_table_sel:1;
        RBus_UInt32  main_table_segment:1;
        RBus_UInt32  dummy1802e400_30_20:11;
        RBus_UInt32  dcc_overlay:1;
    };
}color_dcc_d_dcc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_y_sram_tab_acc_ready:1;
        RBus_UInt32  dcc_y_sram_tab_acc_sel:2;
        RBus_UInt32  dcc_y_sram_tab_rw_sel:2;
        RBus_UInt32  dcc_y_sram_tab_acc_index:6;
        RBus_UInt32  dcc_y_sram_tab_acc_index_cur:6;
        RBus_UInt32  res1:15;
    };
}color_dcc_dcc_y_sram_tab_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_y_sram_tab_g1:10;
        RBus_UInt32  dcc_y_sram_tab_g0:10;
        RBus_UInt32  dcc_y_sram_tab_base:12;
    };
}color_dcc_dcc_y_sram_tab_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  luma_offset_sub:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  luma_offset_main:10;
        RBus_UInt32  res2:6;
    };
}color_dcc_dcc_ctrl_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_limit_seg0_main:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_gain_limit_seg1_main:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg2_main:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg3_main:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_limit_en_main:1;
    };
}color_dcc_dcc_chroma_gain_limit_main_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_limit_seg4_main:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_gain_limit_seg5_main:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg6_main:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg7_main:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_dcc_chroma_gain_limit_main_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_limit_seg0_sub:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_gain_limit_seg1_sub:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg2_sub:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg3_sub:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_limit_en_sub:1;
    };
}color_dcc_dcc_chroma_gain_limit_sub_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_limit_seg4_sub:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_gain_limit_seg5_sub:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg6_sub:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg7_sub:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_dcc_chroma_gain_limit_sub_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_en_sub:1;
        RBus_UInt32  chroma_gain_mode_sub:1;
        RBus_UInt32  chroma_gain_lookup_mode_sub:1;
        RBus_UInt32  chroma_gain_base_sub:3;
        RBus_UInt32  chroma_enhance_above_tab_select_sub:2;
        RBus_UInt32  chroma_enhance_below_tab_select_sub:2;
        RBus_UInt32  saturation_byy_u_tab_select_sub:2;
        RBus_UInt32  saturation_byy_v_tab_select_sub:2;
        RBus_UInt32  dummy1802e418_15:2;
        RBus_UInt32  chroma_gain_en_main:1;
        RBus_UInt32  chroma_gain_mode_main:1;
        RBus_UInt32  chroma_gain_lookup_mode_main:1;
        RBus_UInt32  chroma_gain_base_main:3;
        RBus_UInt32  chroma_enhance_above_tab_select_main:2;
        RBus_UInt32  chroma_enhance_below_tab_select_main:2;
        RBus_UInt32  saturation_byy_u_tab_select_main:2;
        RBus_UInt32  saturation_byy_v_tab_select_main:2;
        RBus_UInt32  dummy1802e418_31:2;
    };
}color_dcc_dcc_ctrl_chroma_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_c_sram_tab_acc_ready:1;
        RBus_UInt32  dcc_c_sram_tab_acc_sel:3;
        RBus_UInt32  dcc_c_sram_tab_rw_sel:2;
        RBus_UInt32  dcc_c_sram_tab_acc_index:5;
        RBus_UInt32  dcc_c_sram_tab_acc_index_cur:5;
        RBus_UInt32  res1:16;
    };
}color_dcc_dcc_c_sram_tab_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_c_sram_tab_g1:7;
        RBus_UInt32  dcc_c_sram_tab_g0:7;
        RBus_UInt32  dcc_c_sram_tab_base:7;
        RBus_UInt32  res1:11;
    };
}color_dcc_dcc_c_sram_tab_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  res1:29;
    };
}color_dcc_d_dcc_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_en:1;
        RBus_UInt32  y_blending_reg3_en:1;
        RBus_UInt32  y_blending_reg2_en:1;
        RBus_UInt32  y_blending_reg1_en:1;
        RBus_UInt32  y_blending_reg0_en:1;
        RBus_UInt32  y_blending_3_enhance_en:1;
        RBus_UInt32  y_blending_2_enhance_en:1;
        RBus_UInt32  y_blending_1_enhance_en:1;
        RBus_UInt32  y_blending_0_enhance_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ratio_lpf_en:1;
        RBus_UInt32  y_blending_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  y_blending_debug_mode_sel:2;
        RBus_UInt32  y_blending_debug_mode_en:1;
        RBus_UInt32  res3:13;
    };
}color_dcc_d_dcc_skin_tone_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_0_v_center:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_0_u_center:12;
        RBus_UInt32  res2:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_0_v_range:4;
        RBus_UInt32  y_blending_0_u_range:4;
        RBus_UInt32  y_blending_0_y_range:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_0_y_center:12;
        RBus_UInt32  res2:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_1_v_center:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_1_u_center:12;
        RBus_UInt32  res2:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_1_v_range:4;
        RBus_UInt32  y_blending_1_u_range:4;
        RBus_UInt32  y_blending_1_y_range:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_1_y_center:12;
        RBus_UInt32  res2:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_2_v_center:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_2_u_center:12;
        RBus_UInt32  res2:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_2_v_range:4;
        RBus_UInt32  y_blending_2_u_range:4;
        RBus_UInt32  y_blending_2_y_range:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_2_y_center:12;
        RBus_UInt32  res2:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_3_v_center:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_3_u_center:12;
        RBus_UInt32  res2:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_3_v_range:4;
        RBus_UInt32  y_blending_3_u_range:4;
        RBus_UInt32  y_blending_3_y_range:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  y_blending_3_y_center:12;
        RBus_UInt32  res2:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_0_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_0_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_0_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_0_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_0_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_0_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_0_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_0_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_1_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_1_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_1_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_1_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_1_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_1_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_1_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_1_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_2_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_2_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_2_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_2_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_2_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_2_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_2_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_2_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_3_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_3_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_3_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_3_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_3_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_3_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_3_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_3_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_0_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_0_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_0_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_0_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_0_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_0_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_0_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_0_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_1_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_1_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_1_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_1_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_1_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_1_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_1_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_1_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_2_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_2_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_2_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_2_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_2_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_2_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_2_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_2_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_3_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_3_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_3_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_3_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_3_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_3_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_3_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_3_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
		RBus_UInt32  Dummy_debug_enable:1;//0
		RBus_UInt32  PureColor:1; // 1
		RBus_UInt32  SceneChange:1; // 2
		RBus_UInt32  SkinTone:1; // 3
		RBus_UInt32  DCL_Enable:1; // 4
		RBus_UInt32  Hist_Adjust_Enable:1;// 5
		RBus_UInt32  Scurve_Enable:1; // 6
		RBus_UInt32  Expand_Enable:1; // 7
		RBus_UInt32  UserCurve_Enable:1; // 8
		RBus_UInt32  Database_Enable:1; // 9
		RBus_UInt32  Bin_boundary_Enable:1;// 10
		RBus_UInt32  Limit_range_Hist_Cut_Enable:1;// 11
		RBus_UInt32  Output_LimitRange_Enable:1; // 12
		RBus_UInt32  Hist_LPF_Enable:1; // 13
		RBus_UInt32  Curve_LPF_Enable:1; // 14
		RBus_UInt32  C_LPF_Tap:3; // 15~17
		RBus_UInt32  Boundary_Type:4; // 18:21
		RBus_UInt32  res1:6;// 22:27
		RBus_UInt32  DCC_Level:4;// 28 ~ 31
    };
}color_dcc_d_dcc_fwused_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  HighResCurveEnable:1;
        RBus_UInt32  ThreeSegCurveEnable:1;
        RBus_UInt32  Res0:1;
        RBus_UInt32  CurveCoefInterpolationEnable:1;
        RBus_UInt32  HistogramScanningEnable:1;
        RBus_UInt32  Res1:3;
        RBus_UInt32  ThreeSEGXIndex0:8;
        RBus_UInt32  ThreeSEGXIndex1:8;
        RBus_UInt32  fw_1:7;
        RBus_UInt32  VipInfo:1;
    };
}color_dcc_d_dcc_fwused_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_time:8;
        RBus_UInt32  fw_2:24;
    };
}color_dcc_d_dcc_fwused_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ThreeSEGYPosOffset0:8;
        RBus_UInt32  ThreeSEGYPosOffset1:8;
	RBus_UInt32  ThreeSEGYNegOffset0:8;
        RBus_UInt32  ThreeSEGYNegOffset1:8;
    };
}color_dcc_d_dcc_fwused_3_RBUS;

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
        RBus_UInt32  res1:10;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  res2:10;
    };
}color_dcc_d_dcc_bist_0_RBUS;

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
        RBus_UInt32  res1:8;
    };
}color_dcc_d_dcc_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  ls_4:1;
        RBus_UInt32  ls_5:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  res2:10;
    };
}color_dcc_d_dcc_bist_2_RBUS;




#endif


#endif
