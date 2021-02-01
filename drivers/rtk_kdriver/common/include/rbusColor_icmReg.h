/**
* @file rbusColor_icmReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_ICM_REG_H_
#define _RBUS_COLOR_ICM_REG_H_

#include "rbusTypes.h"



//  COLOR_ICM Register Address



#define  COLOR_ICM_DM_ICM_CTRL_VADDR                        	(0xb802a100)
#define  COLOR_ICM_DM_ICM_DEBUG_VADDR                       	(0xb802a300)
#define  COLOR_ICM_DM_UV_CORING_VADDR                       	(0xb802a104)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_VADDR               	(0xb802a108)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_VADDR               	(0xb802a10c)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_VADDR               	(0xb802a110)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_VADDR               	(0xb802a114)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_VADDR               	(0xb802a118)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_VADDR               	(0xb802a11c)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_VADDR               	(0xb802a120)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_VADDR               	(0xb802a124)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_VADDR               	(0xb802a128)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_VADDR               	(0xb802a12c)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_VADDR              	(0xb802a130)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_VADDR              	(0xb802a134)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_VADDR               	(0xb802a138)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_VADDR               	(0xb802a13c)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_VADDR            	(0xb802a23c)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_VADDR         	(0xb802a240)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_VADDR         	(0xb802a244)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_VADDR         	(0xb802a248)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_VADDR         	(0xb802a24c)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_VADDR         	(0xb802a250)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_VADDR         	(0xb802a254)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_VADDR         	(0xb802a258)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_VADDR         	(0xb802a25c)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_VADDR         	(0xb802a260)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_VADDR         	(0xb802a264)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_VADDR         	(0xb802a268)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_VADDR         	(0xb802a26c)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_VADDR         	(0xb802a270)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_VADDR         	(0xb802a274)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_VADDR         	(0xb802a278)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_VADDR         	(0xb802a27c)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_VADDR         	(0xb802a280)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_VADDR         	(0xb802a284)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_VADDR         	(0xb802a288)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_VADDR         	(0xb802a28c)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_VADDR         	(0xb802a290)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_VADDR         	(0xb802a294)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_VADDR         	(0xb802a298)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_VADDR         	(0xb802a29c)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_VADDR          	(0xb802a2a0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_VADDR          	(0xb802a2a4)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_VADDR          	(0xb802a2a8)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_VADDR          	(0xb802a2ac)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_VADDR          	(0xb802a2b0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_VADDR          	(0xb802a2b4)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_VADDR          	(0xb802a2b8)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_VADDR          	(0xb802a2bc)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_VADDR          	(0xb802a2c0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_VADDR          	(0xb802a2c4)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_VADDR          	(0xb802a2c8)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_VADDR          	(0xb802a2cc)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_VADDR               	(0xb802a140)
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_VADDR          	(0xb802a144)
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_VADDR          	(0xb802a148)
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_VADDR          	(0xb802a14c)
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_VADDR          	(0xb802a150)
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_VADDR         	(0xb802a154)
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_VADDR         	(0xb802a158)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_VADDR              	(0xb802a15c)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_VADDR              	(0xb802a160)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_VADDR          	(0xb802a164)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_VADDR       	(0xb802a168)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_VADDR       	(0xb802a16c)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_VADDR       	(0xb802a170)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_VADDR       	(0xb802a174)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_VADDR       	(0xb802a178)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_VADDR       	(0xb802a17c)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_VADDR       	(0xb802a180)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_VADDR       	(0xb802a184)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_VADDR       	(0xb802a188)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_VADDR       	(0xb802a18c)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_VADDR       	(0xb802a190)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_VADDR       	(0xb802a194)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_VADDR       	(0xb802a198)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_VADDR       	(0xb802a19c)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_VADDR       	(0xb802a1a0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_VADDR       	(0xb802a1a4)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_VADDR       	(0xb802a1a8)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_VADDR       	(0xb802a1ac)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_VADDR          	(0xb802a1b0)
#define  COLOR_ICM_ICM_AUTO_CTRL_VADDR                      	(0xb802a1b4)
#define  COLOR_ICM_HUE_HIST_SETTINGS0_VADDR                 	(0xb802a1b8)
#define  COLOR_ICM_HUE_HIST_SETTINGS1_VADDR                 	(0xb802a1bc)
#define  COLOR_ICM_HUE_COUNT_00_VADDR                       	(0xb802a1c0)
#define  COLOR_ICM_HUE_COUNT_01_VADDR                       	(0xb802a1c4)
#define  COLOR_ICM_HUE_COUNT_02_VADDR                       	(0xb802a1c8)
#define  COLOR_ICM_HUE_COUNT_03_VADDR                       	(0xb802a1cc)
#define  COLOR_ICM_HUE_COUNT_04_VADDR                       	(0xb802a1d0)
#define  COLOR_ICM_HUE_COUNT_05_VADDR                       	(0xb802a1d4)
#define  COLOR_ICM_HUE_COUNT_06_VADDR                       	(0xb802a1d8)
#define  COLOR_ICM_HUE_COUNT_07_VADDR                       	(0xb802a1dc)
#define  COLOR_ICM_HUE_COUNT_08_VADDR                       	(0xb802a1e0)
#define  COLOR_ICM_HUE_COUNT_09_VADDR                       	(0xb802a1e4)
#define  COLOR_ICM_HUE_COUNT_0A_VADDR                       	(0xb802a1e8)
#define  COLOR_ICM_HUE_COUNT_0B_VADDR                       	(0xb802a1ec)
#define  COLOR_ICM_HUE_COUNT_0C_VADDR                       	(0xb802a1f0)
#define  COLOR_ICM_HUE_COUNT_0D_VADDR                       	(0xb802a1f4)
#define  COLOR_ICM_HUE_COUNT_0E_VADDR                       	(0xb802a1f8)
#define  COLOR_ICM_HUE_COUNT_0F_VADDR                       	(0xb802a1fc)
#define  COLOR_ICM_HUE_COUNT_10_VADDR                       	(0xb802a200)
#define  COLOR_ICM_HUE_COUNT_11_VADDR                       	(0xb802a204)
#define  COLOR_ICM_HUE_COUNT_12_VADDR                       	(0xb802a208)
#define  COLOR_ICM_HUE_COUNT_13_VADDR                       	(0xb802a20c)
#define  COLOR_ICM_HUE_COUNT_14_VADDR                       	(0xb802a210)
#define  COLOR_ICM_HUE_COUNT_15_VADDR                       	(0xb802a214)
#define  COLOR_ICM_HUE_COUNT_16_VADDR                       	(0xb802a218)
#define  COLOR_ICM_HUE_COUNT_17_VADDR                       	(0xb802a21c)
#define  COLOR_ICM_HUE_SUM_00_VADDR                         	(0xb802a220)
#define  COLOR_ICM_HUE_SUM_01_VADDR                         	(0xb802a224)
#define  COLOR_ICM_HUE_SUM_02_VADDR                         	(0xb802a228)
#define  COLOR_ICM_HUE_SUM_03_VADDR                         	(0xb802a22c)
#define  COLOR_ICM_HUE_SUM_04_VADDR                         	(0xb802a230)
#define  COLOR_ICM_HUE_SUM_05_VADDR                         	(0xb802a234)
#define  COLOR_ICM_DM_ICM_ACCESSDATA_CTRL_VADDR             	(0xb802a2d0)
#define  COLOR_ICM_DM_ICM_ACCESSDATA_POSCTRL_VADDR          	(0xb802a2d4)
#define  COLOR_ICM_DM_ICM_READDATA_DATA_H1_VADDR            	(0xb802a2d8)
#define  COLOR_ICM_DM_ICM_READDATA_DATA_H2_VADDR            	(0xb802a2dc)
#define  COLOR_ICM_DM_ICM_READDATA_DATA_S1_VADDR            	(0xb802a2e0)
#define  COLOR_ICM_DM_ICM_READDATA_DATA_S2_VADDR            	(0xb802a2e4)
#define  COLOR_ICM_DM_ICM_READDATA_DATA_I1_VADDR            	(0xb802a2e8)
#define  COLOR_ICM_DM_ICM_READDATA_DATA_I2_VADDR            	(0xb802a2ec)
#define  COLOR_ICM_DM_ICM_WRITEDATA_DATA1_VADDR             	(0xb802a2f0)
#define  COLOR_ICM_DM_ICM_WRITEDATA_DATA2_VADDR             	(0xb802a2f4)
#define  COLOR_ICM_ICM_CRC_CTRL_VADDR                       	(0xb802a2f8)
#define  COLOR_ICM_ICM_CRC_RESULT_VADDR                     	(0xb802a2fc)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_VADDR       	(0xb802a330)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_VADDR        	(0xb802a334)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_VADDR        	(0xb802a338)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_VADDR        	(0xb802a33c)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_VADDR         	(0xb802a340)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_VADDR         	(0xb802a344)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_VADDR       	(0xb802a348)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_VADDR        	(0xb802a34c)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_VADDR        	(0xb802a350)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_VADDR        	(0xb802a354)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_VADDR         	(0xb802a358)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_VADDR         	(0xb802a35c)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_ICM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table_mode:1;
        RBus_UInt32  hsi_grid_sel:1;
        RBus_UInt32  bypass_yuv2rgb_enable:1;
        RBus_UInt32  out_grid_process:1;
        RBus_UInt32  y_ctrl:1;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  debug_color:2;
        RBus_UInt32  icm_overlay:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  dummy1802a100_15_0:16;
    };
}color_icm_dm_icm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  debug_h_pillar_sta:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  debug_h_pillar_end:7;
        RBus_UInt32  debug_s_pillar_sta:4;
        RBus_UInt32  debug_s_pillar_end:4;
        RBus_UInt32  debug_i_pillar_sta:4;
        RBus_UInt32  debug_i_pillar_end:4;
    };
}color_icm_dm_icm_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  u_coring:8;
        RBus_UInt32  v_coring:8;
    };
}color_icm_dm_uv_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_4:6;
    };
}color_icm_dm_icm_hue_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_5:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_6:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_7:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_8:6;
    };
}color_icm_dm_icm_hue_segment_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_9:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_10:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_11:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_12:6;
    };
}color_icm_dm_icm_hue_segment_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_13:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_14:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_15:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_16:6;
    };
}color_icm_dm_icm_hue_segment_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_17:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_18:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_19:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_20:6;
    };
}color_icm_dm_icm_hue_segment_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_21:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_22:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_23:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_24:6;
    };
}color_icm_dm_icm_hue_segment_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_25:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_26:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_27:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_28:6;
    };
}color_icm_dm_icm_hue_segment_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_29:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_30:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_31:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_32:6;
    };
}color_icm_dm_icm_hue_segment_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_33:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_34:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_35:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_36:6;
    };
}color_icm_dm_icm_hue_segment_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_37:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_38:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_39:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_40:6;
    };
}color_icm_dm_icm_hue_segment_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_41:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_42:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_43:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_44:6;
    };
}color_icm_dm_icm_hue_segment_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_45:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_46:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_47:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  h_pillar_48:7;
    };
}color_icm_dm_icm_hue_segment_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_pillar_1:4;
        RBus_UInt32  s_pillar_2:4;
        RBus_UInt32  s_pillar_3:4;
        RBus_UInt32  s_pillar_4:4;
        RBus_UInt32  s_pillar_5:4;
        RBus_UInt32  s_pillar_6:4;
        RBus_UInt32  s_pillar_7:4;
        RBus_UInt32  s_pillar_8:4;
    };
}color_icm_dm_icm_sat_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_pillar_1:4;
        RBus_UInt32  i_pillar_2:4;
        RBus_UInt32  i_pillar_3:4;
        RBus_UInt32  i_pillar_4:4;
        RBus_UInt32  i_pillar_5:4;
        RBus_UInt32  i_pillar_6:4;
        RBus_UInt32  i_pillar_7:4;
        RBus_UInt32  i_pillar_8:4;
    };
}color_icm_dm_icm_int_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  sram_addrres_h:6;
        RBus_UInt32  sram_addrres_s:4;
        RBus_UInt32  sram_addrres_i:4;
        RBus_UInt32  res2:11;
        RBus_UInt32  sram_type:1;
        RBus_UInt32  read_sel:1;
        RBus_UInt32  write_random_access_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}color_icm_dm_icm_3d_tab_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h0:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s0:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i0:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h1:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s1:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i1:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s2:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i2:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h3:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s3:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i3:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h4:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s4:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i4:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h5:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s5:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i5:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h6:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s6:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i6:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h7:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s7:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i7:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h8:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s8:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_80_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i8:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_81_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h9:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s9:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_90_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i9:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_91_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_ha:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_sa:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_ia:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_a1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_hb:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_sb:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_ib:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h0:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s0:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i0:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h1:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s1:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i1:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s2:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i2:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h3:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s3:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i3:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h4:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s4:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i4:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h5:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s5:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i5:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  sat_hist_mode:1;
        RBus_UInt32  d_auto_sat_ctrl_sat_hist_mode_sel:1;
        RBus_UInt32  hist_sat_ok:1;
        RBus_UInt32  hist_sat_enable:1;
        RBus_UInt32  res2:2;
    };
}color_icm_d_auto_sat_hist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist0_thrd_auto_sat_i_u_thre0:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  d_hist0_thrd_auto_sat_i_l_thre0:14;
    };
}color_icm_d_auto_sat_hist0_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist1_thrd_auto_sat_i_u_thre1:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  d_hist1_thrd_auto_sat_i_l_thre1:14;
    };
}color_icm_d_auto_sat_hist1_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist2_thrd_auto_sat_i_u_thre2:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  d_hist2_thrd_auto_sat_i_l_thre2:14;
    };
}color_icm_d_auto_sat_hist2_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist3_thrd_auto_sat_i_u_thre3:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  d_hist3_thrd_auto_sat_i_l_thre3:14;
    };
}color_icm_d_auto_sat_hist3_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  d_hist0_thrd_auto_sat_s_thre0:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d_hist1_thrd_auto_sat_s_thre1:13;
    };
}color_icm_d_auto_sat_hist01_sat_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  d_hist2_thrd_auto_sat_s_thre2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d_hist3_thrd_auto_sat_s_thre3:13;
    };
}color_icm_d_auto_sat_hist23_sat_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist0_hue_sta:8;
        RBus_UInt32  sat_hist0_hue_end:8;
        RBus_UInt32  sat_hist1_hue_sta:8;
        RBus_UInt32  sat_hist1_hue_end:8;
    };
}color_icm_d_auto_sat_hist_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist2_hue_sta:8;
        RBus_UInt32  sat_hist2_hue_end:8;
        RBus_UInt32  sat_hist3_hue_sta:8;
        RBus_UInt32  sat_hist3_hue_end:8;
    };
}color_icm_d_auto_sat_hist_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sram_read:1;
        RBus_UInt32  hist_ctrl:2;
        RBus_UInt32  cnt_block:1;
        RBus_UInt32  res1:28;
    };
}color_icm_d_auto_sat_hist_read_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist0_hue_sta_status:8;
        RBus_UInt32  sat_hist0_hue_end_status:8;
        RBus_UInt32  sat_hist1_hue_sta_status:8;
        RBus_UInt32  sat_hist1_hue_end_status:8;
    };
}color_icm_d_auto_sat_hist_ctrl0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist2_hue_sta_status:8;
        RBus_UInt32  sat_hist2_hue_end_status:8;
        RBus_UInt32  sat_hist3_hue_sta_status:8;
        RBus_UInt32  sat_hist3_hue_end_status:8;
    };
}color_icm_d_auto_sat_hist_ctrl1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_00_or_16:24;
    };
}color_icm_d_auto_sat_hist_cnt_00_or_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_01_or_17:24;
    };
}color_icm_d_auto_sat_hist_cnt_01_or_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_02_or_18:24;
    };
}color_icm_d_auto_sat_hist_cnt_02_or_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_03_or_19:24;
    };
}color_icm_d_auto_sat_hist_cnt_03_or_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_04_or_20:24;
    };
}color_icm_d_auto_sat_hist_cnt_04_or_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_05_or_21:24;
    };
}color_icm_d_auto_sat_hist_cnt_05_or_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_06_or_22:24;
    };
}color_icm_d_auto_sat_hist_cnt_06_or_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_07_or_23:24;
    };
}color_icm_d_auto_sat_hist_cnt_07_or_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_08_or_24:24;
    };
}color_icm_d_auto_sat_hist_cnt_08_or_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_09_or_25:24;
    };
}color_icm_d_auto_sat_hist_cnt_09_or_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_10_or_26:24;
    };
}color_icm_d_auto_sat_hist_cnt_10_or_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_11_or_27:24;
    };
}color_icm_d_auto_sat_hist_cnt_11_or_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_12_or_28:24;
    };
}color_icm_d_auto_sat_hist_cnt_12_or_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_13_or_29:24;
    };
}color_icm_d_auto_sat_hist_cnt_13_or_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_14_or_30:24;
    };
}color_icm_d_auto_sat_hist_cnt_14_or_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_15_or_31:24;
    };
}color_icm_d_auto_sat_hist_cnt_15_or_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_sram_read_consistent_flag:1;
        RBus_UInt32  res1:31;
    };
}color_icm_d_auto_sat_hist_read_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  icm_auto_ctrl_hue_hist_mode_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hist_hue_ok:1;
        RBus_UInt32  hist_hue_enable:1;
        RBus_UInt32  inside_enable:1;
    };
}color_icm_icm_auto_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  hue_hist_offset_add:10;
        RBus_UInt32  res2:3;
        RBus_UInt32  hue_hist_sat_lb:13;
    };
}color_icm_hue_hist_settings0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hue_hist_itn_hb:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  hue_hist_itn_lb:14;
    };
}color_icm_hue_hist_settings1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_00_lut0:24;
    };
}color_icm_hue_count_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_01_lut1:24;
    };
}color_icm_hue_count_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_02_lut2:24;
    };
}color_icm_hue_count_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_03_lut3:24;
    };
}color_icm_hue_count_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_04_lut4:24;
    };
}color_icm_hue_count_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_05_lut5:24;
    };
}color_icm_hue_count_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_06_lut6:24;
    };
}color_icm_hue_count_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_07_lut7:24;
    };
}color_icm_hue_count_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_08_lut8:24;
    };
}color_icm_hue_count_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_09_lut9:24;
    };
}color_icm_hue_count_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0a_lut10:24;
    };
}color_icm_hue_count_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0b_lut11:24;
    };
}color_icm_hue_count_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0c_lut12:24;
    };
}color_icm_hue_count_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0d_lut13:24;
    };
}color_icm_hue_count_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0e_lut14:24;
    };
}color_icm_hue_count_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0f_lut15:24;
    };
}color_icm_hue_count_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_10_lut16:24;
    };
}color_icm_hue_count_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_11_lut17:24;
    };
}color_icm_hue_count_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_12_lut18:24;
    };
}color_icm_hue_count_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_13_lut19:24;
    };
}color_icm_hue_count_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_14_lut20:24;
    };
}color_icm_hue_count_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_15_lut21:24;
    };
}color_icm_hue_count_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_16_lut22:24;
    };
}color_icm_hue_count_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_17_lut23:24;
    };
}color_icm_hue_count_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_00_lut0:32;
    };
}color_icm_hue_sum_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_01_lut1:32;
    };
}color_icm_hue_sum_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_02_lut2:32;
    };
}color_icm_hue_sum_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_03_lut3:32;
    };
}color_icm_hue_sum_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_04_lut4:32;
    };
}color_icm_hue_sum_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_05_lut5:32;
    };
}color_icm_hue_sum_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  main_sub_sel:1;
        RBus_UInt32  accessdata_write_en:1;
        RBus_UInt32  accessdata_read_en:1;
    };
}color_icm_dm_icm_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  accessdata_starty:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  accessdata_startx:13;
    };
}color_icm_dm_icm_accessdata_posctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_h00:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  readdata_h01:13;
    };
}color_icm_dm_icm_readdata_data_h1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_h10:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  readdata_h11:13;
    };
}color_icm_dm_icm_readdata_data_h2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_s00:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  readdata_s01:13;
    };
}color_icm_dm_icm_readdata_data_s1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_s10:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  readdata_s11:13;
    };
}color_icm_dm_icm_readdata_data_s2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  readdata_i00:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  readdata_i01:14;
    };
}color_icm_dm_icm_readdata_data_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  readdata_i10:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  readdata_i11:14;
    };
}color_icm_dm_icm_readdata_data_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  writedata_h:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  writedata_s:13;
    };
}color_icm_dm_icm_writedata_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  writedata_i:13;
    };
}color_icm_dm_icm_writedata_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  icm_crc_conti:1;
        RBus_UInt32  icm_crc_start:1;
    };
}color_icm_icm_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icm_crc_result:32;
    };
}color_icm_icm_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_7:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_6:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_5:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_4:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_3:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_2:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_1:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_0:1;
    };
}color_icm_mbist_icm_3d_table_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_3:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_2:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_1:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_0:1;
    };
}color_icm_mbist_icm_hist_2p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_3:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_2:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_1:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_0:1;
    };
}color_icm_mbist_icm_hist_1p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_7:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_6:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_5:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_4:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_3:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_2:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_1:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_0:1;
    };
}color_icm_mbist_icm_3d_table_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_3:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_2:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_1:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_0:1;
    };
}color_icm_mbist_icm_hist_2p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_3:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_2:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_1:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_0:1;
    };
}color_icm_mbist_icm_hist_1p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_7:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_6:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_5:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_4:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_3:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_0:1;
    };
}color_icm_mbist_icm_3d_table_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  mbist_icm_hist_2p_bist_testrwm:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_3:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_0:1;
    };
}color_icm_mbist_icm_hist_2p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_3:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_0:1;
    };
}color_icm_mbist_icm_hist_1p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_7:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_6:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_5:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_4:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_3:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_0:4;
    };
}color_icm_mbist_icm_3d_table_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_3:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_0:4;
    };
}color_icm_mbist_icm_hist_2p_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_3:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_0:4;
    };
}color_icm_mbist_icm_hist_1p_bist_dvs_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_ICM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802a100_15_0:16;
        RBus_UInt32  res1:7;
        RBus_UInt32  icm_overlay:1;
        RBus_UInt32  debug_color:2;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  y_ctrl:1;
        RBus_UInt32  out_grid_process:1;
        RBus_UInt32  bypass_yuv2rgb_enable:1;
        RBus_UInt32  hsi_grid_sel:1;
        RBus_UInt32  table_mode:1;
    };
}color_icm_dm_icm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_i_pillar_end:4;
        RBus_UInt32  debug_i_pillar_sta:4;
        RBus_UInt32  debug_s_pillar_end:4;
        RBus_UInt32  debug_s_pillar_sta:4;
        RBus_UInt32  debug_h_pillar_end:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  debug_h_pillar_sta:7;
        RBus_UInt32  res2:1;
    };
}color_icm_dm_icm_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_coring:8;
        RBus_UInt32  u_coring:8;
        RBus_UInt32  res1:16;
    };
}color_icm_dm_uv_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_1:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_8:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_7:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_6:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_5:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_12:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_11:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_10:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_9:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_16:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_15:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_14:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_13:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_20:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_19:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_18:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_17:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_24:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_23:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_22:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_21:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_28:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_27:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_26:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_25:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_32:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_31:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_30:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_29:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_36:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_35:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_34:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_33:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_40:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_39:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_38:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_37:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_44:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_43:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_42:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_41:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_48:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  h_pillar_47:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_46:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_45:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_pillar_8:4;
        RBus_UInt32  s_pillar_7:4;
        RBus_UInt32  s_pillar_6:4;
        RBus_UInt32  s_pillar_5:4;
        RBus_UInt32  s_pillar_4:4;
        RBus_UInt32  s_pillar_3:4;
        RBus_UInt32  s_pillar_2:4;
        RBus_UInt32  s_pillar_1:4;
    };
}color_icm_dm_icm_sat_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_pillar_8:4;
        RBus_UInt32  i_pillar_7:4;
        RBus_UInt32  i_pillar_6:4;
        RBus_UInt32  i_pillar_5:4;
        RBus_UInt32  i_pillar_4:4;
        RBus_UInt32  i_pillar_3:4;
        RBus_UInt32  i_pillar_2:4;
        RBus_UInt32  i_pillar_1:4;
    };
}color_icm_dm_icm_int_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  write_random_access_en:1;
        RBus_UInt32  read_sel:1;
        RBus_UInt32  sram_type:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  sram_addrres_i:4;
        RBus_UInt32  sram_addrres_s:4;
        RBus_UInt32  sram_addrres_h:6;
        RBus_UInt32  res2:2;
    };
}color_icm_dm_icm_3d_tab_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s0:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h0:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i0:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h1:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i1:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h2:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i2:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h3:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i3:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s4:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h4:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i4:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s5:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h5:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i5:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s6:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h6:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i6:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s7:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h7:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i7:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s8:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h8:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_80_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i8:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_81_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s9:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h9:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_90_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i9:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_91_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_sa:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_ha:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_ia:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_a1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_sb:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_hb:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_write_hsi_b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_ib:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s0:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h0:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_read_hsi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i0:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h1:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_read_hsi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i1:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h2:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_read_hsi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i2:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h3:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_read_hsi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i3:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s4:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h4:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_read_hsi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i4:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s5:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h5:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_3d_tab_read_hsi_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i5:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hist_sat_enable:1;
        RBus_UInt32  hist_sat_ok:1;
        RBus_UInt32  d_auto_sat_ctrl_sat_hist_mode_sel:1;
        RBus_UInt32  sat_hist_mode:1;
        RBus_UInt32  res2:26;
    };
}color_icm_d_auto_sat_hist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist0_thrd_auto_sat_i_l_thre0:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist0_thrd_auto_sat_i_u_thre0:14;
        RBus_UInt32  res2:2;
    };
}color_icm_d_auto_sat_hist0_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist1_thrd_auto_sat_i_l_thre1:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist1_thrd_auto_sat_i_u_thre1:14;
        RBus_UInt32  res2:2;
    };
}color_icm_d_auto_sat_hist1_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist2_thrd_auto_sat_i_l_thre2:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist2_thrd_auto_sat_i_u_thre2:14;
        RBus_UInt32  res2:2;
    };
}color_icm_d_auto_sat_hist2_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist3_thrd_auto_sat_i_l_thre3:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist3_thrd_auto_sat_i_u_thre3:14;
        RBus_UInt32  res2:2;
    };
}color_icm_d_auto_sat_hist3_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist1_thrd_auto_sat_s_thre1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  d_hist0_thrd_auto_sat_s_thre0:13;
        RBus_UInt32  res2:3;
    };
}color_icm_d_auto_sat_hist01_sat_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist3_thrd_auto_sat_s_thre3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  d_hist2_thrd_auto_sat_s_thre2:13;
        RBus_UInt32  res2:3;
    };
}color_icm_d_auto_sat_hist23_sat_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist1_hue_end:8;
        RBus_UInt32  sat_hist1_hue_sta:8;
        RBus_UInt32  sat_hist0_hue_end:8;
        RBus_UInt32  sat_hist0_hue_sta:8;
    };
}color_icm_d_auto_sat_hist_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist3_hue_end:8;
        RBus_UInt32  sat_hist3_hue_sta:8;
        RBus_UInt32  sat_hist2_hue_end:8;
        RBus_UInt32  sat_hist2_hue_sta:8;
    };
}color_icm_d_auto_sat_hist_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  cnt_block:1;
        RBus_UInt32  hist_ctrl:2;
        RBus_UInt32  sram_read:1;
    };
}color_icm_d_auto_sat_hist_read_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist1_hue_end_status:8;
        RBus_UInt32  sat_hist1_hue_sta_status:8;
        RBus_UInt32  sat_hist0_hue_end_status:8;
        RBus_UInt32  sat_hist0_hue_sta_status:8;
    };
}color_icm_d_auto_sat_hist_ctrl0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist3_hue_end_status:8;
        RBus_UInt32  sat_hist3_hue_sta_status:8;
        RBus_UInt32  sat_hist2_hue_end_status:8;
        RBus_UInt32  sat_hist2_hue_sta_status:8;
    };
}color_icm_d_auto_sat_hist_ctrl1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_00_or_16:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_00_or_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_01_or_17:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_01_or_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_02_or_18:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_02_or_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_03_or_19:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_03_or_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_04_or_20:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_04_or_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_05_or_21:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_05_or_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_06_or_22:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_06_or_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_07_or_23:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_07_or_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_08_or_24:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_08_or_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_09_or_25:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_09_or_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_10_or_26:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_10_or_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_11_or_27:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_11_or_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_12_or_28:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_12_or_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_13_or_29:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_13_or_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_14_or_30:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_14_or_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_15_or_31:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_15_or_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sat_hist_sram_read_consistent_flag:1;
    };
}color_icm_d_auto_sat_hist_read_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inside_enable:1;
        RBus_UInt32  hist_hue_enable:1;
        RBus_UInt32  hist_hue_ok:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  icm_auto_ctrl_hue_hist_mode_sel:1;
        RBus_UInt32  res2:27;
    };
}color_icm_icm_auto_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_hist_sat_lb:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  hue_hist_offset_add:10;
        RBus_UInt32  res2:6;
    };
}color_icm_hue_hist_settings0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_hist_itn_lb:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hue_hist_itn_hb:14;
        RBus_UInt32  res2:2;
    };
}color_icm_hue_hist_settings1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_00_lut0:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_01_lut1:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_02_lut2:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_03_lut3:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_04_lut4:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_05_lut5:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_06_lut6:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_07_lut7:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_08_lut8:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_09_lut9:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0a_lut10:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0b_lut11:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0c_lut12:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0d_lut13:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0e_lut14:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0f_lut15:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_10_lut16:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_11_lut17:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_12_lut18:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_13_lut19:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_14_lut20:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_15_lut21:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_16_lut22:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_17_lut23:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_00_lut0:32;
    };
}color_icm_hue_sum_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_01_lut1:32;
    };
}color_icm_hue_sum_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_02_lut2:32;
    };
}color_icm_hue_sum_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_03_lut3:32;
    };
}color_icm_hue_sum_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_04_lut4:32;
    };
}color_icm_hue_sum_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_05_lut5:32;
    };
}color_icm_hue_sum_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  accessdata_read_en:1;
        RBus_UInt32  accessdata_write_en:1;
        RBus_UInt32  main_sub_sel:1;
        RBus_UInt32  res1:29;
    };
}color_icm_dm_icm_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  accessdata_startx:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  accessdata_starty:12;
        RBus_UInt32  res2:4;
    };
}color_icm_dm_icm_accessdata_posctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_h01:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_h00:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_readdata_data_h1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_h11:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_h10:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_readdata_data_h2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_s01:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_s00:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_readdata_data_s1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_s11:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_s10:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_readdata_data_s2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_i01:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  readdata_i00:14;
        RBus_UInt32  res2:2;
    };
}color_icm_dm_icm_readdata_data_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_i11:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  readdata_i10:14;
        RBus_UInt32  res2:2;
    };
}color_icm_dm_icm_readdata_data_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  writedata_s:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  writedata_h:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_writedata_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  writedata_i:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_writedata_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icm_crc_start:1;
        RBus_UInt32  icm_crc_conti:1;
        RBus_UInt32  res1:30;
    };
}color_icm_icm_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icm_crc_result:32;
    };
}color_icm_icm_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_bist_fail_0:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_1:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_2:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_3:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_4:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_5:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_6:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_7:1;
        RBus_UInt32  res1:24;
    };
}color_icm_mbist_icm_3d_table_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_0:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_1:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_2:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_2p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_0:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_1:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_2:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_1p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_drf_fail_0:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_1:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_2:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_3:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_4:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_5:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_6:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_7:1;
        RBus_UInt32  res1:24;
    };
}color_icm_mbist_icm_3d_table_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_0:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_1:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_2:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_2p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_0:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_1:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_2:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_1p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_0:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_3:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_4:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_5:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_6:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_7:1;
        RBus_UInt32  res1:24;
    };
}color_icm_mbist_icm_3d_table_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_0:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_3:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_testrwm:1;
        RBus_UInt32  res1:27;
    };
}color_icm_mbist_icm_hist_2p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_0:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_1p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_0:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_3:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_4:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_5:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_6:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_7:4;
    };
}color_icm_mbist_icm_3d_table_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_0:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_3:4;
        RBus_UInt32  res1:16;
    };
}color_icm_mbist_icm_hist_2p_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_0:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_3:4;
        RBus_UInt32  res1:16;
    };
}color_icm_mbist_icm_hist_1p_bist_dvs_RBUS;




#endif 


#endif 
