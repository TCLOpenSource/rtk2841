/**
* @file rbusMAIN_DITHERReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MAIN_DITHER_REG_H_
#define _RBUS_MAIN_DITHER_REG_H_

#include "rbus_types.h"



//  MAIN_DITHER Register Address



#define  MAIN_DITHER_I_MAIN_DITHER_CTRL1_VADDR              	(0xb8022600)
#define  MAIN_DITHER_I_MAIN_DITHER_SEQ_R_00_15_VADDR        	(0xb8022604)
#define  MAIN_DITHER_I_MAIN_DITHER_SEQ_R_16_31_VADDR        	(0xb8022608)
#define  MAIN_DITHER_I_MAIN_DITHER_SEQ_G_00_07_VADDR        	(0xb802260c)
#define  MAIN_DITHER_I_MAIN_DITHER_SEQ_G_16_31_VADDR        	(0xb8022610)
#define  MAIN_DITHER_I_MAIN_DITHER_SEQ_B_00_15_VADDR        	(0xb8022614)
#define  MAIN_DITHER_I_MAIN_DITHER_SEQ_B_16_31_VADDR        	(0xb8022618)
#define  MAIN_DITHER_I_MAIN_DITHER_TB1_R_00_VADDR           	(0xb802261c)
#define  MAIN_DITHER_I_MAIN_DITHER_TB1_R_02_VADDR           	(0xb8022620)
#define  MAIN_DITHER_I_MAIN_DITHER_TB1_G_00_VADDR           	(0xb8022624)
#define  MAIN_DITHER_I_MAIN_DITHER_TB1_G_02_VADDR           	(0xb8022628)
#define  MAIN_DITHER_I_MAIN_DITHER_TB1_B_00_VADDR           	(0xb802262c)
#define  MAIN_DITHER_I_MAIN_DITHER_TB1_B_02_VADDR           	(0xb8022630)
#define  MAIN_DITHER_I_MAIN_DITHER_TEMP_TB1_VADDR           	(0xb8022634)
#define  MAIN_DITHER_I_MAIN_DITHER_TB2_R_00_VADDR           	(0xb8022638)
#define  MAIN_DITHER_I_MAIN_DITHER_TB2_R_02_VADDR           	(0xb802263c)
#define  MAIN_DITHER_I_MAIN_DITHER_TB2_G_00_VADDR           	(0xb8022640)
#define  MAIN_DITHER_I_MAIN_DITHER_TB2_G_02_VADDR           	(0xb8022644)
#define  MAIN_DITHER_I_MAIN_DITHER_TB2_B_00_VADDR           	(0xb8022648)
#define  MAIN_DITHER_I_MAIN_DITHER_TB2_B_02_VADDR           	(0xb802264c)
#define  MAIN_DITHER_I_MAIN_DITHER_TEMP_TB2_VADDR           	(0xb8022650)
#define  MAIN_DITHER_I_MAIN_DITHER_LR_CRC_CTRL_VADDR        	(0xb8022660)
#define  MAIN_DITHER_I_MAIN_DITHER_CRC_L_RESULT_VADDR       	(0xb8022664)
#define  MAIN_DITHER_I_MAIN_DITHER_CRC_R_RESULT_VADDR       	(0xb8022668)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MAIN_DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dither_bit_sel:1;
        RBus_UInt32  ch1_field_odd_temporal_offset_select:1;
        RBus_UInt32  ch1_field_even_temporal_offset_select:1;
        RBus_UInt32  ch1_temporal_offset_separate_mode:1;
        RBus_UInt32  ch1_dithering_table_select:2;
        RBus_UInt32  ch1_temporal_enable:1;
        RBus_UInt32  ch1_value_sign:1;
        RBus_UInt32  ch1_dithering_mode:1;
        RBus_UInt32  ch1_v_modulation:1;
        RBus_UInt32  ch1_h_modulation:1;
    };
}main_dither_i_main_dither_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_15:2;
        RBus_UInt32  seq_r_14:2;
        RBus_UInt32  seq_r_13:2;
        RBus_UInt32  seq_r_12:2;
        RBus_UInt32  seq_r_11:2;
        RBus_UInt32  seq_r_10:2;
        RBus_UInt32  seq_r_9:2;
        RBus_UInt32  seq_r_8:2;
        RBus_UInt32  seq_r_7:2;
        RBus_UInt32  seq_r_6:2;
        RBus_UInt32  seq_r_5:2;
        RBus_UInt32  seq_r_4:2;
        RBus_UInt32  seq_r_3:2;
        RBus_UInt32  seq_r_2:2;
        RBus_UInt32  seq_r_1:2;
        RBus_UInt32  seq_r_0:2;
    };
}main_dither_i_main_dither_seq_r_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_31:2;
        RBus_UInt32  seq_r_30:2;
        RBus_UInt32  seq_r_29:2;
        RBus_UInt32  seq_r_28:2;
        RBus_UInt32  seq_r_27:2;
        RBus_UInt32  seq_r_26:2;
        RBus_UInt32  seq_r_25:2;
        RBus_UInt32  seq_r_24:2;
        RBus_UInt32  seq_r_23:2;
        RBus_UInt32  seq_r_22:2;
        RBus_UInt32  seq_r_21:2;
        RBus_UInt32  seq_r_20:2;
        RBus_UInt32  seq_r_19:2;
        RBus_UInt32  seq_r_18:2;
        RBus_UInt32  seq_r_17:2;
        RBus_UInt32  seq_r_16:2;
    };
}main_dither_i_main_dither_seq_r_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_15:2;
        RBus_UInt32  seq_g_14:2;
        RBus_UInt32  seq_g_13:2;
        RBus_UInt32  seq_g_12:2;
        RBus_UInt32  seq_g_11:2;
        RBus_UInt32  seq_g_10:2;
        RBus_UInt32  seq_g_9:2;
        RBus_UInt32  seq_g_8:2;
        RBus_UInt32  seq_g_7:2;
        RBus_UInt32  seq_g_6:2;
        RBus_UInt32  seq_g_5:2;
        RBus_UInt32  seq_g_4:2;
        RBus_UInt32  seq_g_3:2;
        RBus_UInt32  seq_g_2:2;
        RBus_UInt32  seq_g_1:2;
        RBus_UInt32  seq_g_0:2;
    };
}main_dither_i_main_dither_seq_g_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_31:2;
        RBus_UInt32  seq_g_30:2;
        RBus_UInt32  seq_g_29:2;
        RBus_UInt32  seq_g_28:2;
        RBus_UInt32  seq_g_27:2;
        RBus_UInt32  seq_g_26:2;
        RBus_UInt32  seq_g_25:2;
        RBus_UInt32  seq_g_24:2;
        RBus_UInt32  seq_g_23:2;
        RBus_UInt32  seq_g_22:2;
        RBus_UInt32  seq_g_21:2;
        RBus_UInt32  seq_g_20:2;
        RBus_UInt32  seq_g_19:2;
        RBus_UInt32  seq_g_18:2;
        RBus_UInt32  seq_g_17:2;
        RBus_UInt32  seq_g_16:2;
    };
}main_dither_i_main_dither_seq_g_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_15:2;
        RBus_UInt32  seq_b_14:2;
        RBus_UInt32  seq_b_13:2;
        RBus_UInt32  seq_b_12:2;
        RBus_UInt32  seq_b_11:2;
        RBus_UInt32  seq_b_10:2;
        RBus_UInt32  seq_b_9:2;
        RBus_UInt32  seq_b_8:2;
        RBus_UInt32  seq_b_7:2;
        RBus_UInt32  seq_b_6:2;
        RBus_UInt32  seq_b_5:2;
        RBus_UInt32  seq_b_4:2;
        RBus_UInt32  seq_b_3:2;
        RBus_UInt32  seq_b_2:2;
        RBus_UInt32  seq_b_1:2;
        RBus_UInt32  seq_b_0:2;
    };
}main_dither_i_main_dither_seq_b_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_31:2;
        RBus_UInt32  seq_b_30:2;
        RBus_UInt32  seq_b_29:2;
        RBus_UInt32  seq_b_28:2;
        RBus_UInt32  seq_b_27:2;
        RBus_UInt32  seq_b_26:2;
        RBus_UInt32  seq_b_25:2;
        RBus_UInt32  seq_b_24:2;
        RBus_UInt32  seq_b_23:2;
        RBus_UInt32  seq_b_22:2;
        RBus_UInt32  seq_b_21:2;
        RBus_UInt32  seq_b_20:2;
        RBus_UInt32  seq_b_19:2;
        RBus_UInt32  seq_b_18:2;
        RBus_UInt32  seq_b_17:2;
        RBus_UInt32  seq_b_16:2;
    };
}main_dither_i_main_dither_seq_b_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_r_13:4;
        RBus_UInt32  tab1_r_12:4;
        RBus_UInt32  tab1_r_11:4;
        RBus_UInt32  tab1_r_10:4;
        RBus_UInt32  tab1_r_03:4;
        RBus_UInt32  tab1_r_02:4;
        RBus_UInt32  tab1_r_01:4;
        RBus_UInt32  tab1_r_00:4;
    };
}main_dither_i_main_dither_tb1_r_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_r_33:4;
        RBus_UInt32  tab1_r_32:4;
        RBus_UInt32  tab1_r_31:4;
        RBus_UInt32  tab1_r_30:4;
        RBus_UInt32  tab1_r_23:4;
        RBus_UInt32  tab1_r_22:4;
        RBus_UInt32  tab1_r_21:4;
        RBus_UInt32  tab1_r_20:4;
    };
}main_dither_i_main_dither_tb1_r_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_g_13:4;
        RBus_UInt32  tab1_g_12:4;
        RBus_UInt32  tab1_g_11:4;
        RBus_UInt32  tab1_g_10:4;
        RBus_UInt32  tab1_g_03:4;
        RBus_UInt32  tab1_g_02:4;
        RBus_UInt32  tab1_g_01:4;
        RBus_UInt32  tab1_g_00:4;
    };
}main_dither_i_main_dither_tb1_g_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_g_33:4;
        RBus_UInt32  tab1_g_32:4;
        RBus_UInt32  tab1_g_31:4;
        RBus_UInt32  tab1_g_30:4;
        RBus_UInt32  tab1_g_23:4;
        RBus_UInt32  tab1_g_22:4;
        RBus_UInt32  tab1_g_21:4;
        RBus_UInt32  tab1_g_20:4;
    };
}main_dither_i_main_dither_tb1_g_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_b_13:4;
        RBus_UInt32  tab1_b_12:4;
        RBus_UInt32  tab1_b_11:4;
        RBus_UInt32  tab1_b_10:4;
        RBus_UInt32  tab1_b_03:4;
        RBus_UInt32  tab1_b_02:4;
        RBus_UInt32  tab1_b_01:4;
        RBus_UInt32  tab1_b_00:4;
    };
}main_dither_i_main_dither_tb1_b_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_b_33:4;
        RBus_UInt32  tab1_b_32:4;
        RBus_UInt32  tab1_b_31:4;
        RBus_UInt32  tab1_b_30:4;
        RBus_UInt32  tab1_b_23:4;
        RBus_UInt32  tab1_b_22:4;
        RBus_UInt32  tab1_b_21:4;
        RBus_UInt32  tab1_b_20:4;
    };
}main_dither_i_main_dither_tb1_b_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_temp_offset_15:2;
        RBus_UInt32  tab1_temp_offset_14:2;
        RBus_UInt32  tab1_temp_offset_13:2;
        RBus_UInt32  tab1_temp_offset_12:2;
        RBus_UInt32  tab1_temp_offset_11:2;
        RBus_UInt32  tab1_temp_offset_10:2;
        RBus_UInt32  tab1_temp_offset_9:2;
        RBus_UInt32  tab1_temp_offset_8:2;
        RBus_UInt32  tab1_temp_offset_7:2;
        RBus_UInt32  tab1_temp_offset_6:2;
        RBus_UInt32  tab1_temp_offset_5:2;
        RBus_UInt32  tab1_temp_offset_4:2;
        RBus_UInt32  tab1_temp_offset_3:2;
        RBus_UInt32  tab1_temp_offset_2:2;
        RBus_UInt32  tab1_temp_offset_1:2;
        RBus_UInt32  tab1_temp_offset_0:2;
    };
}main_dither_i_main_dither_temp_tb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_r_13:4;
        RBus_UInt32  tab2_r_12:4;
        RBus_UInt32  tab2_r_11:4;
        RBus_UInt32  tab2_r_10:4;
        RBus_UInt32  tab2_r_03:4;
        RBus_UInt32  tab2_r_02:4;
        RBus_UInt32  tab2_r_01:4;
        RBus_UInt32  tab2_r_00:4;
    };
}main_dither_i_main_dither_tb2_r_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_r_33:4;
        RBus_UInt32  tab2_r_32:4;
        RBus_UInt32  tab2_r_31:4;
        RBus_UInt32  tab2_r_30:4;
        RBus_UInt32  tab2_r_23:4;
        RBus_UInt32  tab2_r_22:4;
        RBus_UInt32  tab2_r_21:4;
        RBus_UInt32  tab2_r_20:4;
    };
}main_dither_i_main_dither_tb2_r_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_g_13:4;
        RBus_UInt32  tab2_g_12:4;
        RBus_UInt32  tab2_g_11:4;
        RBus_UInt32  tab2_g_10:4;
        RBus_UInt32  tab2_g_03:4;
        RBus_UInt32  tab2_g_02:4;
        RBus_UInt32  tab2_g_01:4;
        RBus_UInt32  tab2_g_00:4;
    };
}main_dither_i_main_dither_tb2_g_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_g_33:4;
        RBus_UInt32  tab2_g_32:4;
        RBus_UInt32  tab2_g_31:4;
        RBus_UInt32  tab2_g_30:4;
        RBus_UInt32  tab2_g_23:4;
        RBus_UInt32  tab2_g_22:4;
        RBus_UInt32  tab2_g_21:4;
        RBus_UInt32  tab2_g_20:4;
    };
}main_dither_i_main_dither_tb2_g_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_b_13:4;
        RBus_UInt32  tab2_b_12:4;
        RBus_UInt32  tab2_b_11:4;
        RBus_UInt32  tab2_b_10:4;
        RBus_UInt32  tab2_b_03:4;
        RBus_UInt32  tab2_b_02:4;
        RBus_UInt32  tab2_b_01:4;
        RBus_UInt32  tab2_b_00:4;
    };
}main_dither_i_main_dither_tb2_b_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_b_33:4;
        RBus_UInt32  tab2_b_32:4;
        RBus_UInt32  tab2_b_31:4;
        RBus_UInt32  tab2_b_30:4;
        RBus_UInt32  tab2_b_23:4;
        RBus_UInt32  tab2_b_22:4;
        RBus_UInt32  tab2_b_21:4;
        RBus_UInt32  tab2_b_20:4;
    };
}main_dither_i_main_dither_tb2_b_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_temp_offset_15:2;
        RBus_UInt32  tab2_temp_offset_14:2;
        RBus_UInt32  tab2_temp_offset_13:2;
        RBus_UInt32  tab2_temp_offset_12:2;
        RBus_UInt32  tab2_temp_offset_11:2;
        RBus_UInt32  tab2_temp_offset_10:2;
        RBus_UInt32  tab2_temp_offset_9:2;
        RBus_UInt32  tab2_temp_offset_8:2;
        RBus_UInt32  tab2_temp_offset_7:2;
        RBus_UInt32  tab2_temp_offset_6:2;
        RBus_UInt32  tab2_temp_offset_5:2;
        RBus_UInt32  tab2_temp_offset_4:2;
        RBus_UInt32  tab2_temp_offset_3:2;
        RBus_UInt32  tab2_temp_offset_2:2;
        RBus_UInt32  tab2_temp_offset_1:2;
        RBus_UInt32  tab2_temp_offset_0:2;
    };
}main_dither_i_main_dither_temp_tb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  r_crc_conti:1;
        RBus_UInt32  r_crc_start:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  crc_3d_mode:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  l_crc_start:1;
    };
}main_dither_i_main_dither_lr_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}main_dither_i_main_dither_crc_l_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}main_dither_i_main_dither_crc_r_result_RBUS;

#else //apply LITTLE_ENDIAN

//======MAIN_DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_h_modulation:1;
        RBus_UInt32  ch1_v_modulation:1;
        RBus_UInt32  ch1_dithering_mode:1;
        RBus_UInt32  ch1_value_sign:1;
        RBus_UInt32  ch1_temporal_enable:1;
        RBus_UInt32  ch1_dithering_table_select:2;
        RBus_UInt32  ch1_temporal_offset_separate_mode:1;
        RBus_UInt32  ch1_field_even_temporal_offset_select:1;
        RBus_UInt32  ch1_field_odd_temporal_offset_select:1;
        RBus_UInt32  dither_bit_sel:1;
        RBus_UInt32  res1:21;
    };
}main_dither_i_main_dither_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_0:2;
        RBus_UInt32  seq_r_1:2;
        RBus_UInt32  seq_r_2:2;
        RBus_UInt32  seq_r_3:2;
        RBus_UInt32  seq_r_4:2;
        RBus_UInt32  seq_r_5:2;
        RBus_UInt32  seq_r_6:2;
        RBus_UInt32  seq_r_7:2;
        RBus_UInt32  seq_r_8:2;
        RBus_UInt32  seq_r_9:2;
        RBus_UInt32  seq_r_10:2;
        RBus_UInt32  seq_r_11:2;
        RBus_UInt32  seq_r_12:2;
        RBus_UInt32  seq_r_13:2;
        RBus_UInt32  seq_r_14:2;
        RBus_UInt32  seq_r_15:2;
    };
}main_dither_i_main_dither_seq_r_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_16:2;
        RBus_UInt32  seq_r_17:2;
        RBus_UInt32  seq_r_18:2;
        RBus_UInt32  seq_r_19:2;
        RBus_UInt32  seq_r_20:2;
        RBus_UInt32  seq_r_21:2;
        RBus_UInt32  seq_r_22:2;
        RBus_UInt32  seq_r_23:2;
        RBus_UInt32  seq_r_24:2;
        RBus_UInt32  seq_r_25:2;
        RBus_UInt32  seq_r_26:2;
        RBus_UInt32  seq_r_27:2;
        RBus_UInt32  seq_r_28:2;
        RBus_UInt32  seq_r_29:2;
        RBus_UInt32  seq_r_30:2;
        RBus_UInt32  seq_r_31:2;
    };
}main_dither_i_main_dither_seq_r_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_0:2;
        RBus_UInt32  seq_g_1:2;
        RBus_UInt32  seq_g_2:2;
        RBus_UInt32  seq_g_3:2;
        RBus_UInt32  seq_g_4:2;
        RBus_UInt32  seq_g_5:2;
        RBus_UInt32  seq_g_6:2;
        RBus_UInt32  seq_g_7:2;
        RBus_UInt32  seq_g_8:2;
        RBus_UInt32  seq_g_9:2;
        RBus_UInt32  seq_g_10:2;
        RBus_UInt32  seq_g_11:2;
        RBus_UInt32  seq_g_12:2;
        RBus_UInt32  seq_g_13:2;
        RBus_UInt32  seq_g_14:2;
        RBus_UInt32  seq_g_15:2;
    };
}main_dither_i_main_dither_seq_g_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_16:2;
        RBus_UInt32  seq_g_17:2;
        RBus_UInt32  seq_g_18:2;
        RBus_UInt32  seq_g_19:2;
        RBus_UInt32  seq_g_20:2;
        RBus_UInt32  seq_g_21:2;
        RBus_UInt32  seq_g_22:2;
        RBus_UInt32  seq_g_23:2;
        RBus_UInt32  seq_g_24:2;
        RBus_UInt32  seq_g_25:2;
        RBus_UInt32  seq_g_26:2;
        RBus_UInt32  seq_g_27:2;
        RBus_UInt32  seq_g_28:2;
        RBus_UInt32  seq_g_29:2;
        RBus_UInt32  seq_g_30:2;
        RBus_UInt32  seq_g_31:2;
    };
}main_dither_i_main_dither_seq_g_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_0:2;
        RBus_UInt32  seq_b_1:2;
        RBus_UInt32  seq_b_2:2;
        RBus_UInt32  seq_b_3:2;
        RBus_UInt32  seq_b_4:2;
        RBus_UInt32  seq_b_5:2;
        RBus_UInt32  seq_b_6:2;
        RBus_UInt32  seq_b_7:2;
        RBus_UInt32  seq_b_8:2;
        RBus_UInt32  seq_b_9:2;
        RBus_UInt32  seq_b_10:2;
        RBus_UInt32  seq_b_11:2;
        RBus_UInt32  seq_b_12:2;
        RBus_UInt32  seq_b_13:2;
        RBus_UInt32  seq_b_14:2;
        RBus_UInt32  seq_b_15:2;
    };
}main_dither_i_main_dither_seq_b_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_16:2;
        RBus_UInt32  seq_b_17:2;
        RBus_UInt32  seq_b_18:2;
        RBus_UInt32  seq_b_19:2;
        RBus_UInt32  seq_b_20:2;
        RBus_UInt32  seq_b_21:2;
        RBus_UInt32  seq_b_22:2;
        RBus_UInt32  seq_b_23:2;
        RBus_UInt32  seq_b_24:2;
        RBus_UInt32  seq_b_25:2;
        RBus_UInt32  seq_b_26:2;
        RBus_UInt32  seq_b_27:2;
        RBus_UInt32  seq_b_28:2;
        RBus_UInt32  seq_b_29:2;
        RBus_UInt32  seq_b_30:2;
        RBus_UInt32  seq_b_31:2;
    };
}main_dither_i_main_dither_seq_b_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_r_00:4;
        RBus_UInt32  tab1_r_01:4;
        RBus_UInt32  tab1_r_02:4;
        RBus_UInt32  tab1_r_03:4;
        RBus_UInt32  tab1_r_10:4;
        RBus_UInt32  tab1_r_11:4;
        RBus_UInt32  tab1_r_12:4;
        RBus_UInt32  tab1_r_13:4;
    };
}main_dither_i_main_dither_tb1_r_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_r_20:4;
        RBus_UInt32  tab1_r_21:4;
        RBus_UInt32  tab1_r_22:4;
        RBus_UInt32  tab1_r_23:4;
        RBus_UInt32  tab1_r_30:4;
        RBus_UInt32  tab1_r_31:4;
        RBus_UInt32  tab1_r_32:4;
        RBus_UInt32  tab1_r_33:4;
    };
}main_dither_i_main_dither_tb1_r_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_g_00:4;
        RBus_UInt32  tab1_g_01:4;
        RBus_UInt32  tab1_g_02:4;
        RBus_UInt32  tab1_g_03:4;
        RBus_UInt32  tab1_g_10:4;
        RBus_UInt32  tab1_g_11:4;
        RBus_UInt32  tab1_g_12:4;
        RBus_UInt32  tab1_g_13:4;
    };
}main_dither_i_main_dither_tb1_g_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_g_20:4;
        RBus_UInt32  tab1_g_21:4;
        RBus_UInt32  tab1_g_22:4;
        RBus_UInt32  tab1_g_23:4;
        RBus_UInt32  tab1_g_30:4;
        RBus_UInt32  tab1_g_31:4;
        RBus_UInt32  tab1_g_32:4;
        RBus_UInt32  tab1_g_33:4;
    };
}main_dither_i_main_dither_tb1_g_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_b_00:4;
        RBus_UInt32  tab1_b_01:4;
        RBus_UInt32  tab1_b_02:4;
        RBus_UInt32  tab1_b_03:4;
        RBus_UInt32  tab1_b_10:4;
        RBus_UInt32  tab1_b_11:4;
        RBus_UInt32  tab1_b_12:4;
        RBus_UInt32  tab1_b_13:4;
    };
}main_dither_i_main_dither_tb1_b_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_b_20:4;
        RBus_UInt32  tab1_b_21:4;
        RBus_UInt32  tab1_b_22:4;
        RBus_UInt32  tab1_b_23:4;
        RBus_UInt32  tab1_b_30:4;
        RBus_UInt32  tab1_b_31:4;
        RBus_UInt32  tab1_b_32:4;
        RBus_UInt32  tab1_b_33:4;
    };
}main_dither_i_main_dither_tb1_b_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_temp_offset_0:2;
        RBus_UInt32  tab1_temp_offset_1:2;
        RBus_UInt32  tab1_temp_offset_2:2;
        RBus_UInt32  tab1_temp_offset_3:2;
        RBus_UInt32  tab1_temp_offset_4:2;
        RBus_UInt32  tab1_temp_offset_5:2;
        RBus_UInt32  tab1_temp_offset_6:2;
        RBus_UInt32  tab1_temp_offset_7:2;
        RBus_UInt32  tab1_temp_offset_8:2;
        RBus_UInt32  tab1_temp_offset_9:2;
        RBus_UInt32  tab1_temp_offset_10:2;
        RBus_UInt32  tab1_temp_offset_11:2;
        RBus_UInt32  tab1_temp_offset_12:2;
        RBus_UInt32  tab1_temp_offset_13:2;
        RBus_UInt32  tab1_temp_offset_14:2;
        RBus_UInt32  tab1_temp_offset_15:2;
    };
}main_dither_i_main_dither_temp_tb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_r_00:4;
        RBus_UInt32  tab2_r_01:4;
        RBus_UInt32  tab2_r_02:4;
        RBus_UInt32  tab2_r_03:4;
        RBus_UInt32  tab2_r_10:4;
        RBus_UInt32  tab2_r_11:4;
        RBus_UInt32  tab2_r_12:4;
        RBus_UInt32  tab2_r_13:4;
    };
}main_dither_i_main_dither_tb2_r_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_r_20:4;
        RBus_UInt32  tab2_r_21:4;
        RBus_UInt32  tab2_r_22:4;
        RBus_UInt32  tab2_r_23:4;
        RBus_UInt32  tab2_r_30:4;
        RBus_UInt32  tab2_r_31:4;
        RBus_UInt32  tab2_r_32:4;
        RBus_UInt32  tab2_r_33:4;
    };
}main_dither_i_main_dither_tb2_r_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_g_00:4;
        RBus_UInt32  tab2_g_01:4;
        RBus_UInt32  tab2_g_02:4;
        RBus_UInt32  tab2_g_03:4;
        RBus_UInt32  tab2_g_10:4;
        RBus_UInt32  tab2_g_11:4;
        RBus_UInt32  tab2_g_12:4;
        RBus_UInt32  tab2_g_13:4;
    };
}main_dither_i_main_dither_tb2_g_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_g_20:4;
        RBus_UInt32  tab2_g_21:4;
        RBus_UInt32  tab2_g_22:4;
        RBus_UInt32  tab2_g_23:4;
        RBus_UInt32  tab2_g_30:4;
        RBus_UInt32  tab2_g_31:4;
        RBus_UInt32  tab2_g_32:4;
        RBus_UInt32  tab2_g_33:4;
    };
}main_dither_i_main_dither_tb2_g_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_b_00:4;
        RBus_UInt32  tab2_b_01:4;
        RBus_UInt32  tab2_b_02:4;
        RBus_UInt32  tab2_b_03:4;
        RBus_UInt32  tab2_b_10:4;
        RBus_UInt32  tab2_b_11:4;
        RBus_UInt32  tab2_b_12:4;
        RBus_UInt32  tab2_b_13:4;
    };
}main_dither_i_main_dither_tb2_b_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_b_20:4;
        RBus_UInt32  tab2_b_21:4;
        RBus_UInt32  tab2_b_22:4;
        RBus_UInt32  tab2_b_23:4;
        RBus_UInt32  tab2_b_30:4;
        RBus_UInt32  tab2_b_31:4;
        RBus_UInt32  tab2_b_32:4;
        RBus_UInt32  tab2_b_33:4;
    };
}main_dither_i_main_dither_tb2_b_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_temp_offset_0:2;
        RBus_UInt32  tab2_temp_offset_1:2;
        RBus_UInt32  tab2_temp_offset_2:2;
        RBus_UInt32  tab2_temp_offset_3:2;
        RBus_UInt32  tab2_temp_offset_4:2;
        RBus_UInt32  tab2_temp_offset_5:2;
        RBus_UInt32  tab2_temp_offset_6:2;
        RBus_UInt32  tab2_temp_offset_7:2;
        RBus_UInt32  tab2_temp_offset_8:2;
        RBus_UInt32  tab2_temp_offset_9:2;
        RBus_UInt32  tab2_temp_offset_10:2;
        RBus_UInt32  tab2_temp_offset_11:2;
        RBus_UInt32  tab2_temp_offset_12:2;
        RBus_UInt32  tab2_temp_offset_13:2;
        RBus_UInt32  tab2_temp_offset_14:2;
        RBus_UInt32  tab2_temp_offset_15:2;
    };
}main_dither_i_main_dither_temp_tb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_start:1;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  crc_3d_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  r_crc_start:1;
        RBus_UInt32  r_crc_conti:1;
        RBus_UInt32  res3:22;
    };
}main_dither_i_main_dither_lr_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}main_dither_i_main_dither_crc_l_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}main_dither_i_main_dither_crc_r_result_RBUS;




#endif 


#endif 
