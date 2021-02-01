/**
* @file rbusDitherReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DITHER_REG_H_
#define _RBUS_DITHER_REG_H_

#include "rbusTypes.h"



//  DITHER Register Address



#define  DITHER_DITHERING_CTRL_VADDR                        	(0xb802c500)
#define  DITHER_DITHERING_SEQUENCE_TABLE_RED_00_07_VADDR    	(0xb802c504)
#define  DITHER_DITHERING_SEQUENCE_TABLE_RED_08_15_VADDR    	(0xb802c508)
#define  DITHER_DITHERING_SEQUENCE_TABLE_RED_16_23_VADDR    	(0xb802c50c)
#define  DITHER_DITHERING_SEQUENCE_TABLE_RED_24_31_VADDR    	(0xb802c510)
#define  DITHER_DITHERING_SEQUENCE_TABLE_GREEN_00_07_VADDR  	(0xb802c514)
#define  DITHER_DITHERING_SEQUENCE_TABLE_GREEN_08_15_VADDR  	(0xb802c518)
#define  DITHER_DITHERING_SEQUENCE_TABLE_GREEN_16_23_VADDR  	(0xb802c51c)
#define  DITHER_DITHERING_SEQUENCE_TABLE_GREEN_24_31_VADDR  	(0xb802c520)
#define  DITHER_DITHERING_SEQUENCE_TABLE_BLUE_00_07_VADDR   	(0xb802c524)
#define  DITHER_DITHERING_SEQUENCE_TABLE_BLUE_08_15_VADDR   	(0xb802c528)
#define  DITHER_DITHERING_SEQUENCE_TABLE_BLUE_16_23_VADDR   	(0xb802c52c)
#define  DITHER_DITHERING_SEQUENCE_TABLE_BLUE_24_31_VADDR   	(0xb802c530)
#define  DITHER_DITHERING_DITHER_TABLE_RED_00_VADDR         	(0xb802c534)
#define  DITHER_DITHERING_DITHER_TABLE_RED_01_VADDR         	(0xb802c538)
#define  DITHER_DITHERING_DITHER_TABLE_RED_02_VADDR         	(0xb802c53c)
#define  DITHER_DITHERING_DITHER_TABLE_RED_03_VADDR         	(0xb802c540)
#define  DITHER_DITHERING_DITHER_TABLE_RED_04_VADDR         	(0xb802c544)
#define  DITHER_DITHERING_DITHER_TABLE_RED_05_VADDR         	(0xb802c548)
#define  DITHER_DITHERING_DITHER_TABLE_RED_06_VADDR         	(0xb802c54c)
#define  DITHER_DITHERING_DITHER_TABLE_RED_07_VADDR         	(0xb802c550)
#define  DITHER_DITHERING_DITHER_TABLE_RED_08_VADDR         	(0xb802c554)
#define  DITHER_DITHERING_DITHER_TABLE_RED_09_VADDR         	(0xb802c558)
#define  DITHER_DITHERING_DITHER_TABLE_RED_0A_VADDR         	(0xb802c55c)
#define  DITHER_DITHERING_DITHER_TABLE_RED_0B_VADDR         	(0xb802c560)
#define  DITHER_DITHERING_DITHER_TABLE_RED_0C_VADDR         	(0xb802c564)
#define  DITHER_DITHERING_DITHER_TABLE_RED_0D_VADDR         	(0xb802c568)
#define  DITHER_DITHERING_DITHER_TABLE_RED_0E_VADDR         	(0xb802c56c)
#define  DITHER_DITHERING_DITHER_TABLE_RED_0F_VADDR         	(0xb802c570)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_00_VADDR       	(0xb802c574)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_01_VADDR       	(0xb802c578)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_02_VADDR       	(0xb802c57c)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_03_VADDR       	(0xb802c580)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_04_VADDR       	(0xb802c584)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_05_VADDR       	(0xb802c588)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_06_VADDR       	(0xb802c58c)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_07_VADDR       	(0xb802c590)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_08_VADDR       	(0xb802c594)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_09_VADDR       	(0xb802c598)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_0A_VADDR       	(0xb802c59c)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_0B_VADDR       	(0xb802c5a0)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_0C_VADDR       	(0xb802c5a4)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_0D_VADDR       	(0xb802c5a8)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_0E_VADDR       	(0xb802c5ac)
#define  DITHER_DITHERING_DITHER_TABLE_GREEN_0F_VADDR       	(0xb802c5b0)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_00_VADDR        	(0xb802c5b4)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_01_VADDR        	(0xb802c5b8)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_02_VADDR        	(0xb802c5bc)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_03_VADDR        	(0xb802c5c0)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_04_VADDR        	(0xb802c5c4)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_05_VADDR        	(0xb802c5c8)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_06_VADDR        	(0xb802c5cc)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_07_VADDR        	(0xb802c5d0)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_08_VADDR        	(0xb802c5d4)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_09_VADDR        	(0xb802c5d8)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_0A_VADDR        	(0xb802c5dc)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_0B_VADDR        	(0xb802c5e0)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_0C_VADDR        	(0xb802c5e4)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_0D_VADDR        	(0xb802c5e8)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_0E_VADDR        	(0xb802c5ec)
#define  DITHER_DITHERING_DITHER_TABLE_BLUE_0F_VADDR        	(0xb802c5f0)
#define  DITHER_TEMPORAL_OFFSET_VADDR                       	(0xb802c5f4)
#define  DITHER_DITHER_CRC_CTRL_VADDR                       	(0xb802c5f8)
#define  DITHER_DITHER_CRC_RESULT_VADDR                     	(0xb802c5fc)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_RED_00_07_VADDR 	(0xb802c600)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_RED_08_15_VADDR 	(0xb802c604)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_RED_16_23_VADDR 	(0xb802c608)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_RED_24_31_VADDR 	(0xb802c60c)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_GREEN_00_07_VADDR 	(0xb802c610)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_GREEN_08_15_VADDR 	(0xb802c614)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_GREEN_16_23_VADDR 	(0xb802c618)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_GREEN_24_31_VADDR 	(0xb802c61c)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_BLUE_00_07_VADDR 	(0xb802c620)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_BLUE_08_15_VADDR 	(0xb802c624)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_BLUE_16_23_VADDR 	(0xb802c628)
#define  DITHER_DITHERING_2ND_SEQUENCE_TABLE_BLUE_24_31_VADDR 	(0xb802c62c)
#define  DITHER_DITHERING_CTRL2_VADDR                       	(0xb802c630)
#define  DITHER_DITHERING_DD_TH_B_VADDR                     	(0xb802c634)
#define  DITHER_DITHERING_DD_TH_G_VADDR                     	(0xb802c638)
#define  DITHER_DITHERING_DD_TH_R_VADDR                     	(0xb802c63c)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_2nd_b_th:8;
        RBus_UInt32  seq_2nd_g_th:8;
        RBus_UInt32  seq_2nd_r_th:8;
        RBus_UInt32  seq_2nd_mode:1;
        RBus_UInt32  test_mode:1;
        RBus_UInt32  function_enable:1;
        RBus_UInt32  temporal_enable:1;
        RBus_UInt32  value_sign:1;
        RBus_UInt32  dithering_mode:1;
        RBus_UInt32  v_modulation:1;
        RBus_UInt32  h_modulation:1;
    };
}dither_dithering_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_7:4;
        RBus_UInt32  seq_r_6:4;
        RBus_UInt32  seq_r_5:4;
        RBus_UInt32  seq_r_4:4;
        RBus_UInt32  seq_r_3:4;
        RBus_UInt32  seq_r_2:4;
        RBus_UInt32  seq_r_1:4;
        RBus_UInt32  seq_r_0:4;
    };
}dither_dithering_sequence_table_red_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_15:4;
        RBus_UInt32  seq_r_14:4;
        RBus_UInt32  seq_r_13:4;
        RBus_UInt32  seq_r_12:4;
        RBus_UInt32  seq_r_11:4;
        RBus_UInt32  seq_r_10:4;
        RBus_UInt32  seq_r_9:4;
        RBus_UInt32  seq_r_8:4;
    };
}dither_dithering_sequence_table_red_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_23:4;
        RBus_UInt32  seq_r_22:4;
        RBus_UInt32  seq_r_21:4;
        RBus_UInt32  seq_r_20:4;
        RBus_UInt32  seq_r_19:4;
        RBus_UInt32  seq_r_18:4;
        RBus_UInt32  seq_r_17:4;
        RBus_UInt32  seq_r_16:4;
    };
}dither_dithering_sequence_table_red_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_31:4;
        RBus_UInt32  seq_r_30:4;
        RBus_UInt32  seq_r_29:4;
        RBus_UInt32  seq_r_28:4;
        RBus_UInt32  seq_r_27:4;
        RBus_UInt32  seq_r_26:4;
        RBus_UInt32  seq_r_25:4;
        RBus_UInt32  seq_r_24:4;
    };
}dither_dithering_sequence_table_red_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_7:4;
        RBus_UInt32  seq_g_6:4;
        RBus_UInt32  seq_g_5:4;
        RBus_UInt32  seq_g_4:4;
        RBus_UInt32  seq_g_3:4;
        RBus_UInt32  seq_g_2:4;
        RBus_UInt32  seq_g_1:4;
        RBus_UInt32  seq_g_0:4;
    };
}dither_dithering_sequence_table_green_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_15:4;
        RBus_UInt32  seq_g_14:4;
        RBus_UInt32  seq_g_13:4;
        RBus_UInt32  seq_g_12:4;
        RBus_UInt32  seq_g_11:4;
        RBus_UInt32  seq_g_10:4;
        RBus_UInt32  seq_g_9:4;
        RBus_UInt32  seq_g_8:4;
    };
}dither_dithering_sequence_table_green_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_23:4;
        RBus_UInt32  seq_g_22:4;
        RBus_UInt32  seq_g_21:4;
        RBus_UInt32  seq_g_20:4;
        RBus_UInt32  seq_g_19:4;
        RBus_UInt32  seq_g_18:4;
        RBus_UInt32  seq_g_17:4;
        RBus_UInt32  seq_g_16:4;
    };
}dither_dithering_sequence_table_green_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_31:4;
        RBus_UInt32  seq_g_30:4;
        RBus_UInt32  seq_g_29:4;
        RBus_UInt32  seq_g_28:4;
        RBus_UInt32  seq_g_27:4;
        RBus_UInt32  seq_g_26:4;
        RBus_UInt32  seq_g_25:4;
        RBus_UInt32  seq_g_24:4;
    };
}dither_dithering_sequence_table_green_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_7:4;
        RBus_UInt32  seq_b_6:4;
        RBus_UInt32  seq_b_5:4;
        RBus_UInt32  seq_b_4:4;
        RBus_UInt32  seq_b_3:4;
        RBus_UInt32  seq_b_2:4;
        RBus_UInt32  seq_b_1:4;
        RBus_UInt32  seq_b_0:4;
    };
}dither_dithering_sequence_table_blue_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_15:4;
        RBus_UInt32  seq_b_14:4;
        RBus_UInt32  seq_b_13:4;
        RBus_UInt32  seq_b_12:4;
        RBus_UInt32  seq_b_11:4;
        RBus_UInt32  seq_b_10:4;
        RBus_UInt32  seq_b_9:4;
        RBus_UInt32  seq_b_8:4;
    };
}dither_dithering_sequence_table_blue_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_23:4;
        RBus_UInt32  seq_b_22:4;
        RBus_UInt32  seq_b_21:4;
        RBus_UInt32  seq_b_20:4;
        RBus_UInt32  seq_b_19:4;
        RBus_UInt32  seq_b_18:4;
        RBus_UInt32  seq_b_17:4;
        RBus_UInt32  seq_b_16:4;
    };
}dither_dithering_sequence_table_blue_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_31:4;
        RBus_UInt32  seq_b_30:4;
        RBus_UInt32  seq_b_29:4;
        RBus_UInt32  seq_b_28:4;
        RBus_UInt32  seq_b_27:4;
        RBus_UInt32  seq_b_26:4;
        RBus_UInt32  seq_b_25:4;
        RBus_UInt32  seq_b_24:4;
    };
}dither_dithering_sequence_table_blue_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_03:6;
        RBus_UInt32  tab_r_02:6;
        RBus_UInt32  tab_r_01:6;
        RBus_UInt32  tab_r_00:6;
    };
}dither_dithering_dither_table_red_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_13:6;
        RBus_UInt32  tab_r_12:6;
        RBus_UInt32  tab_r_11:6;
        RBus_UInt32  tab_r_10:6;
    };
}dither_dithering_dither_table_red_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_23:6;
        RBus_UInt32  tab_r_22:6;
        RBus_UInt32  tab_r_21:6;
        RBus_UInt32  tab_r_20:6;
    };
}dither_dithering_dither_table_red_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_33:6;
        RBus_UInt32  tab_r_32:6;
        RBus_UInt32  tab_r_31:6;
        RBus_UInt32  tab_r_30:6;
    };
}dither_dithering_dither_table_red_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_43:6;
        RBus_UInt32  tab_r_42:6;
        RBus_UInt32  tab_r_41:6;
        RBus_UInt32  tab_r_40:6;
    };
}dither_dithering_dither_table_red_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_53:6;
        RBus_UInt32  tab_r_52:6;
        RBus_UInt32  tab_r_51:6;
        RBus_UInt32  tab_r_50:6;
    };
}dither_dithering_dither_table_red_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_63:6;
        RBus_UInt32  tab_r_62:6;
        RBus_UInt32  tab_r_61:6;
        RBus_UInt32  tab_r_60:6;
    };
}dither_dithering_dither_table_red_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_73:6;
        RBus_UInt32  tab_r_72:6;
        RBus_UInt32  tab_r_71:6;
        RBus_UInt32  tab_r_70:6;
    };
}dither_dithering_dither_table_red_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_83:6;
        RBus_UInt32  tab_r_82:6;
        RBus_UInt32  tab_r_81:6;
        RBus_UInt32  tab_r_80:6;
    };
}dither_dithering_dither_table_red_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_93:6;
        RBus_UInt32  tab_r_92:6;
        RBus_UInt32  tab_r_91:6;
        RBus_UInt32  tab_r_90:6;
    };
}dither_dithering_dither_table_red_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_a3:6;
        RBus_UInt32  tab_r_a2:6;
        RBus_UInt32  tab_r_a1:6;
        RBus_UInt32  tab_r_a0:6;
    };
}dither_dithering_dither_table_red_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_b3:6;
        RBus_UInt32  tab_r_b2:6;
        RBus_UInt32  tab_r_b1:6;
        RBus_UInt32  tab_r_b0:6;
    };
}dither_dithering_dither_table_red_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_c3:6;
        RBus_UInt32  tab_r_c2:6;
        RBus_UInt32  tab_r_c1:6;
        RBus_UInt32  tab_r_c0:6;
    };
}dither_dithering_dither_table_red_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_d3:6;
        RBus_UInt32  tab_r_d2:6;
        RBus_UInt32  tab_r_d1:6;
        RBus_UInt32  tab_r_d0:6;
    };
}dither_dithering_dither_table_red_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_e3:6;
        RBus_UInt32  tab_r_e2:6;
        RBus_UInt32  tab_r_e1:6;
        RBus_UInt32  tab_r_e0:6;
    };
}dither_dithering_dither_table_red_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_f3:6;
        RBus_UInt32  tab_r_f2:6;
        RBus_UInt32  tab_r_f1:6;
        RBus_UInt32  tab_r_f0:6;
    };
}dither_dithering_dither_table_red_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_03:6;
        RBus_UInt32  tab_g_02:6;
        RBus_UInt32  tab_g_01:6;
        RBus_UInt32  tab_g_00:6;
    };
}dither_dithering_dither_table_green_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_13:6;
        RBus_UInt32  tab_g_12:6;
        RBus_UInt32  tab_g_11:6;
        RBus_UInt32  tab_g_10:6;
    };
}dither_dithering_dither_table_green_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_23:6;
        RBus_UInt32  tab_g_22:6;
        RBus_UInt32  tab_g_21:6;
        RBus_UInt32  tab_g_20:6;
    };
}dither_dithering_dither_table_green_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_33:6;
        RBus_UInt32  tab_g_32:6;
        RBus_UInt32  tab_g_31:6;
        RBus_UInt32  tab_g_30:6;
    };
}dither_dithering_dither_table_green_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_43:6;
        RBus_UInt32  tab_g_42:6;
        RBus_UInt32  tab_g_41:6;
        RBus_UInt32  tab_g_40:6;
    };
}dither_dithering_dither_table_green_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_53:6;
        RBus_UInt32  tab_g_52:6;
        RBus_UInt32  tab_g_51:6;
        RBus_UInt32  tab_g_50:6;
    };
}dither_dithering_dither_table_green_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_63:6;
        RBus_UInt32  tab_g_62:6;
        RBus_UInt32  tab_g_61:6;
        RBus_UInt32  tab_g_60:6;
    };
}dither_dithering_dither_table_green_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_73:6;
        RBus_UInt32  tab_g_72:6;
        RBus_UInt32  tab_g_71:6;
        RBus_UInt32  tab_g_70:6;
    };
}dither_dithering_dither_table_green_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_83:6;
        RBus_UInt32  tab_g_82:6;
        RBus_UInt32  tab_g_81:6;
        RBus_UInt32  tab_g_80:6;
    };
}dither_dithering_dither_table_green_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_93:6;
        RBus_UInt32  tab_g_92:6;
        RBus_UInt32  tab_g_91:6;
        RBus_UInt32  tab_g_90:6;
    };
}dither_dithering_dither_table_green_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_a3:6;
        RBus_UInt32  tab_g_a2:6;
        RBus_UInt32  tab_g_a1:6;
        RBus_UInt32  tab_g_a0:6;
    };
}dither_dithering_dither_table_green_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_b3:6;
        RBus_UInt32  tab_g_b2:6;
        RBus_UInt32  tab_g_b1:6;
        RBus_UInt32  tab_g_b0:6;
    };
}dither_dithering_dither_table_green_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_c3:6;
        RBus_UInt32  tab_g_c2:6;
        RBus_UInt32  tab_g_c1:6;
        RBus_UInt32  tab_g_c0:6;
    };
}dither_dithering_dither_table_green_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_d3:6;
        RBus_UInt32  tab_g_d2:6;
        RBus_UInt32  tab_g_d1:6;
        RBus_UInt32  tab_g_d0:6;
    };
}dither_dithering_dither_table_green_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_e3:6;
        RBus_UInt32  tab_g_e2:6;
        RBus_UInt32  tab_g_e1:6;
        RBus_UInt32  tab_g_e0:6;
    };
}dither_dithering_dither_table_green_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_f3:6;
        RBus_UInt32  tab_g_f2:6;
        RBus_UInt32  tab_g_f1:6;
        RBus_UInt32  tab_g_f0:6;
    };
}dither_dithering_dither_table_green_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_03:6;
        RBus_UInt32  tab_b_02:6;
        RBus_UInt32  tab_b_01:6;
        RBus_UInt32  tab_b_00:6;
    };
}dither_dithering_dither_table_blue_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_13:6;
        RBus_UInt32  tab_b_12:6;
        RBus_UInt32  tab_b_11:6;
        RBus_UInt32  tab_b_10:6;
    };
}dither_dithering_dither_table_blue_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_23:6;
        RBus_UInt32  tab_b_22:6;
        RBus_UInt32  tab_b_21:6;
        RBus_UInt32  tab_b_20:6;
    };
}dither_dithering_dither_table_blue_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_33:6;
        RBus_UInt32  tab_b_32:6;
        RBus_UInt32  tab_b_31:6;
        RBus_UInt32  tab_b_30:6;
    };
}dither_dithering_dither_table_blue_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_43:6;
        RBus_UInt32  tab_b_42:6;
        RBus_UInt32  tab_b_41:6;
        RBus_UInt32  tab_b_40:6;
    };
}dither_dithering_dither_table_blue_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_53:6;
        RBus_UInt32  tab_b_52:6;
        RBus_UInt32  tab_b_51:6;
        RBus_UInt32  tab_b_50:6;
    };
}dither_dithering_dither_table_blue_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_63:6;
        RBus_UInt32  tab_b_62:6;
        RBus_UInt32  tab_b_61:6;
        RBus_UInt32  tab_b_60:6;
    };
}dither_dithering_dither_table_blue_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_73:6;
        RBus_UInt32  tab_b_72:6;
        RBus_UInt32  tab_b_71:6;
        RBus_UInt32  tab_b_70:6;
    };
}dither_dithering_dither_table_blue_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_83:6;
        RBus_UInt32  tab_b_82:6;
        RBus_UInt32  tab_b_81:6;
        RBus_UInt32  tab_b_80:6;
    };
}dither_dithering_dither_table_blue_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_93:6;
        RBus_UInt32  tab_b_92:6;
        RBus_UInt32  tab_b_91:6;
        RBus_UInt32  tab_b_90:6;
    };
}dither_dithering_dither_table_blue_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_a3:6;
        RBus_UInt32  tab_b_a2:6;
        RBus_UInt32  tab_b_a1:6;
        RBus_UInt32  tab_b_a0:6;
    };
}dither_dithering_dither_table_blue_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_b3:6;
        RBus_UInt32  tab_b_b2:6;
        RBus_UInt32  tab_b_b1:6;
        RBus_UInt32  tab_b_b0:6;
    };
}dither_dithering_dither_table_blue_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_c3:6;
        RBus_UInt32  tab_b_c2:6;
        RBus_UInt32  tab_b_c1:6;
        RBus_UInt32  tab_b_c0:6;
    };
}dither_dithering_dither_table_blue_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_d3:6;
        RBus_UInt32  tab_b_d2:6;
        RBus_UInt32  tab_b_d1:6;
        RBus_UInt32  tab_b_d0:6;
    };
}dither_dithering_dither_table_blue_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_e3:6;
        RBus_UInt32  tab_b_e2:6;
        RBus_UInt32  tab_b_e1:6;
        RBus_UInt32  tab_b_e0:6;
    };
}dither_dithering_dither_table_blue_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_f3:6;
        RBus_UInt32  tab_b_f2:6;
        RBus_UInt32  tab_b_f1:6;
        RBus_UInt32  tab_b_f0:6;
    };
}dither_dithering_dither_table_blue_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  temp_offset_15:2;
        RBus_UInt32  temp_offset_14:2;
        RBus_UInt32  temp_offset_13:2;
        RBus_UInt32  temp_offset_12:2;
        RBus_UInt32  temp_offset_11:2;
        RBus_UInt32  temp_offset_10:2;
        RBus_UInt32  temp_offset_9:2;
        RBus_UInt32  temp_offset_8:2;
        RBus_UInt32  temp_offset_7:2;
        RBus_UInt32  temp_offset_6:2;
        RBus_UInt32  temp_offset_5:2;
        RBus_UInt32  temp_offset_4:2;
        RBus_UInt32  temp_offset_3:2;
        RBus_UInt32  temp_offset_2:2;
        RBus_UInt32  temp_offset_1:2;
        RBus_UInt32  temp_offset_0:2;
    };
}dither_temporal_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dither_crc_conti:1;
        RBus_UInt32  dither_crc_start:1;
    };
}dither_dither_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_crc_result:32;
    };
}dither_dither_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_7:4;
        RBus_UInt32  seq_r_6:4;
        RBus_UInt32  seq_r_5:4;
        RBus_UInt32  seq_r_4:4;
        RBus_UInt32  seq_r_3:4;
        RBus_UInt32  seq_r_2:4;
        RBus_UInt32  seq_r_1:4;
        RBus_UInt32  seq_r_0:4;
    };
}dither_dithering_2nd_sequence_table_red_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_15:4;
        RBus_UInt32  seq_r_14:4;
        RBus_UInt32  seq_r_13:4;
        RBus_UInt32  seq_r_12:4;
        RBus_UInt32  seq_r_11:4;
        RBus_UInt32  seq_r_10:4;
        RBus_UInt32  seq_r_9:4;
        RBus_UInt32  seq_r_8:4;
    };
}dither_dithering_2nd_sequence_table_red_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_23:4;
        RBus_UInt32  seq_r_22:4;
        RBus_UInt32  seq_r_21:4;
        RBus_UInt32  seq_r_20:4;
        RBus_UInt32  seq_r_19:4;
        RBus_UInt32  seq_r_18:4;
        RBus_UInt32  seq_r_17:4;
        RBus_UInt32  seq_r_16:4;
    };
}dither_dithering_2nd_sequence_table_red_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_31:4;
        RBus_UInt32  seq_r_30:4;
        RBus_UInt32  seq_r_29:4;
        RBus_UInt32  seq_r_28:4;
        RBus_UInt32  seq_r_27:4;
        RBus_UInt32  seq_r_26:4;
        RBus_UInt32  seq_r_25:4;
        RBus_UInt32  seq_r_24:4;
    };
}dither_dithering_2nd_sequence_table_red_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_7:4;
        RBus_UInt32  seq_g_6:4;
        RBus_UInt32  seq_g_5:4;
        RBus_UInt32  seq_g_4:4;
        RBus_UInt32  seq_g_3:4;
        RBus_UInt32  seq_g_2:4;
        RBus_UInt32  seq_g_1:4;
        RBus_UInt32  seq_g_0:4;
    };
}dither_dithering_2nd_sequence_table_green_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_15:4;
        RBus_UInt32  seq_g_14:4;
        RBus_UInt32  seq_g_13:4;
        RBus_UInt32  seq_g_12:4;
        RBus_UInt32  seq_g_11:4;
        RBus_UInt32  seq_g_10:4;
        RBus_UInt32  seq_g_9:4;
        RBus_UInt32  seq_g_8:4;
    };
}dither_dithering_2nd_sequence_table_green_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_23:4;
        RBus_UInt32  seq_g_22:4;
        RBus_UInt32  seq_g_21:4;
        RBus_UInt32  seq_g_20:4;
        RBus_UInt32  seq_g_19:4;
        RBus_UInt32  seq_g_18:4;
        RBus_UInt32  seq_g_17:4;
        RBus_UInt32  seq_g_16:4;
    };
}dither_dithering_2nd_sequence_table_green_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_31:4;
        RBus_UInt32  seq_g_30:4;
        RBus_UInt32  seq_g_29:4;
        RBus_UInt32  seq_g_28:4;
        RBus_UInt32  seq_g_27:4;
        RBus_UInt32  seq_g_26:4;
        RBus_UInt32  seq_g_25:4;
        RBus_UInt32  seq_g_24:4;
    };
}dither_dithering_2nd_sequence_table_green_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_7:4;
        RBus_UInt32  seq_b_6:4;
        RBus_UInt32  seq_b_5:4;
        RBus_UInt32  seq_b_4:4;
        RBus_UInt32  seq_b_3:4;
        RBus_UInt32  seq_b_2:4;
        RBus_UInt32  seq_b_1:4;
        RBus_UInt32  seq_b_0:4;
    };
}dither_dithering_2nd_sequence_table_blue_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_15:4;
        RBus_UInt32  seq_b_14:4;
        RBus_UInt32  seq_b_13:4;
        RBus_UInt32  seq_b_12:4;
        RBus_UInt32  seq_b_11:4;
        RBus_UInt32  seq_b_10:4;
        RBus_UInt32  seq_b_9:4;
        RBus_UInt32  seq_b_8:4;
    };
}dither_dithering_2nd_sequence_table_blue_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_23:4;
        RBus_UInt32  seq_b_22:4;
        RBus_UInt32  seq_b_21:4;
        RBus_UInt32  seq_b_20:4;
        RBus_UInt32  seq_b_19:4;
        RBus_UInt32  seq_b_18:4;
        RBus_UInt32  seq_b_17:4;
        RBus_UInt32  seq_b_16:4;
    };
}dither_dithering_2nd_sequence_table_blue_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_31:4;
        RBus_UInt32  seq_b_30:4;
        RBus_UInt32  seq_b_29:4;
        RBus_UInt32  seq_b_28:4;
        RBus_UInt32  seq_b_27:4;
        RBus_UInt32  seq_b_26:4;
        RBus_UInt32  seq_b_25:4;
        RBus_UInt32  seq_b_24:4;
    };
}dither_dithering_2nd_sequence_table_blue_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  frame_count_by_3d_l_flag_inv:1;
        RBus_UInt32  frame_count_by_3d_flag_en:1;
    };
}dither_dithering_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dd_en:1;
        RBus_UInt32  dd_b_0_th:12;
        RBus_UInt32  dd_b_1_th:12;
        RBus_UInt32  dd_b_b0_type:2;
        RBus_UInt32  dd_b_b1_type:2;
        RBus_UInt32  dd_b_b2_type:2;
    };
}dither_dithering_dd_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dd_g_0_th:12;
        RBus_UInt32  dd_g_1_th:12;
        RBus_UInt32  dd_g_b0_type:2;
        RBus_UInt32  dd_g_b1_type:2;
        RBus_UInt32  dd_g_b2_type:2;
    };
}dither_dithering_dd_th_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dd_r_0_th:12;
        RBus_UInt32  dd_r_1_th:12;
        RBus_UInt32  dd_r_b0_type:2;
        RBus_UInt32  dd_r_b1_type:2;
        RBus_UInt32  dd_r_b2_type:2;
    };
}dither_dithering_dd_th_r_RBUS;

#else //apply LITTLE_ENDIAN

//======DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_modulation:1;
        RBus_UInt32  v_modulation:1;
        RBus_UInt32  dithering_mode:1;
        RBus_UInt32  value_sign:1;
        RBus_UInt32  temporal_enable:1;
        RBus_UInt32  function_enable:1;
        RBus_UInt32  test_mode:1;
        RBus_UInt32  seq_2nd_mode:1;
        RBus_UInt32  seq_2nd_r_th:8;
        RBus_UInt32  seq_2nd_g_th:8;
        RBus_UInt32  seq_2nd_b_th:8;
    };
}dither_dithering_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_0:4;
        RBus_UInt32  seq_r_1:4;
        RBus_UInt32  seq_r_2:4;
        RBus_UInt32  seq_r_3:4;
        RBus_UInt32  seq_r_4:4;
        RBus_UInt32  seq_r_5:4;
        RBus_UInt32  seq_r_6:4;
        RBus_UInt32  seq_r_7:4;
    };
}dither_dithering_sequence_table_red_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_8:4;
        RBus_UInt32  seq_r_9:4;
        RBus_UInt32  seq_r_10:4;
        RBus_UInt32  seq_r_11:4;
        RBus_UInt32  seq_r_12:4;
        RBus_UInt32  seq_r_13:4;
        RBus_UInt32  seq_r_14:4;
        RBus_UInt32  seq_r_15:4;
    };
}dither_dithering_sequence_table_red_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_16:4;
        RBus_UInt32  seq_r_17:4;
        RBus_UInt32  seq_r_18:4;
        RBus_UInt32  seq_r_19:4;
        RBus_UInt32  seq_r_20:4;
        RBus_UInt32  seq_r_21:4;
        RBus_UInt32  seq_r_22:4;
        RBus_UInt32  seq_r_23:4;
    };
}dither_dithering_sequence_table_red_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_24:4;
        RBus_UInt32  seq_r_25:4;
        RBus_UInt32  seq_r_26:4;
        RBus_UInt32  seq_r_27:4;
        RBus_UInt32  seq_r_28:4;
        RBus_UInt32  seq_r_29:4;
        RBus_UInt32  seq_r_30:4;
        RBus_UInt32  seq_r_31:4;
    };
}dither_dithering_sequence_table_red_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_0:4;
        RBus_UInt32  seq_g_1:4;
        RBus_UInt32  seq_g_2:4;
        RBus_UInt32  seq_g_3:4;
        RBus_UInt32  seq_g_4:4;
        RBus_UInt32  seq_g_5:4;
        RBus_UInt32  seq_g_6:4;
        RBus_UInt32  seq_g_7:4;
    };
}dither_dithering_sequence_table_green_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_8:4;
        RBus_UInt32  seq_g_9:4;
        RBus_UInt32  seq_g_10:4;
        RBus_UInt32  seq_g_11:4;
        RBus_UInt32  seq_g_12:4;
        RBus_UInt32  seq_g_13:4;
        RBus_UInt32  seq_g_14:4;
        RBus_UInt32  seq_g_15:4;
    };
}dither_dithering_sequence_table_green_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_16:4;
        RBus_UInt32  seq_g_17:4;
        RBus_UInt32  seq_g_18:4;
        RBus_UInt32  seq_g_19:4;
        RBus_UInt32  seq_g_20:4;
        RBus_UInt32  seq_g_21:4;
        RBus_UInt32  seq_g_22:4;
        RBus_UInt32  seq_g_23:4;
    };
}dither_dithering_sequence_table_green_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_24:4;
        RBus_UInt32  seq_g_25:4;
        RBus_UInt32  seq_g_26:4;
        RBus_UInt32  seq_g_27:4;
        RBus_UInt32  seq_g_28:4;
        RBus_UInt32  seq_g_29:4;
        RBus_UInt32  seq_g_30:4;
        RBus_UInt32  seq_g_31:4;
    };
}dither_dithering_sequence_table_green_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_0:4;
        RBus_UInt32  seq_b_1:4;
        RBus_UInt32  seq_b_2:4;
        RBus_UInt32  seq_b_3:4;
        RBus_UInt32  seq_b_4:4;
        RBus_UInt32  seq_b_5:4;
        RBus_UInt32  seq_b_6:4;
        RBus_UInt32  seq_b_7:4;
    };
}dither_dithering_sequence_table_blue_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_8:4;
        RBus_UInt32  seq_b_9:4;
        RBus_UInt32  seq_b_10:4;
        RBus_UInt32  seq_b_11:4;
        RBus_UInt32  seq_b_12:4;
        RBus_UInt32  seq_b_13:4;
        RBus_UInt32  seq_b_14:4;
        RBus_UInt32  seq_b_15:4;
    };
}dither_dithering_sequence_table_blue_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_16:4;
        RBus_UInt32  seq_b_17:4;
        RBus_UInt32  seq_b_18:4;
        RBus_UInt32  seq_b_19:4;
        RBus_UInt32  seq_b_20:4;
        RBus_UInt32  seq_b_21:4;
        RBus_UInt32  seq_b_22:4;
        RBus_UInt32  seq_b_23:4;
    };
}dither_dithering_sequence_table_blue_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_24:4;
        RBus_UInt32  seq_b_25:4;
        RBus_UInt32  seq_b_26:4;
        RBus_UInt32  seq_b_27:4;
        RBus_UInt32  seq_b_28:4;
        RBus_UInt32  seq_b_29:4;
        RBus_UInt32  seq_b_30:4;
        RBus_UInt32  seq_b_31:4;
    };
}dither_dithering_sequence_table_blue_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_00:6;
        RBus_UInt32  tab_r_01:6;
        RBus_UInt32  tab_r_02:6;
        RBus_UInt32  tab_r_03:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_10:6;
        RBus_UInt32  tab_r_11:6;
        RBus_UInt32  tab_r_12:6;
        RBus_UInt32  tab_r_13:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_20:6;
        RBus_UInt32  tab_r_21:6;
        RBus_UInt32  tab_r_22:6;
        RBus_UInt32  tab_r_23:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_30:6;
        RBus_UInt32  tab_r_31:6;
        RBus_UInt32  tab_r_32:6;
        RBus_UInt32  tab_r_33:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_40:6;
        RBus_UInt32  tab_r_41:6;
        RBus_UInt32  tab_r_42:6;
        RBus_UInt32  tab_r_43:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_50:6;
        RBus_UInt32  tab_r_51:6;
        RBus_UInt32  tab_r_52:6;
        RBus_UInt32  tab_r_53:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_60:6;
        RBus_UInt32  tab_r_61:6;
        RBus_UInt32  tab_r_62:6;
        RBus_UInt32  tab_r_63:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_70:6;
        RBus_UInt32  tab_r_71:6;
        RBus_UInt32  tab_r_72:6;
        RBus_UInt32  tab_r_73:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_80:6;
        RBus_UInt32  tab_r_81:6;
        RBus_UInt32  tab_r_82:6;
        RBus_UInt32  tab_r_83:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_90:6;
        RBus_UInt32  tab_r_91:6;
        RBus_UInt32  tab_r_92:6;
        RBus_UInt32  tab_r_93:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_a0:6;
        RBus_UInt32  tab_r_a1:6;
        RBus_UInt32  tab_r_a2:6;
        RBus_UInt32  tab_r_a3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_b0:6;
        RBus_UInt32  tab_r_b1:6;
        RBus_UInt32  tab_r_b2:6;
        RBus_UInt32  tab_r_b3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_c0:6;
        RBus_UInt32  tab_r_c1:6;
        RBus_UInt32  tab_r_c2:6;
        RBus_UInt32  tab_r_c3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_d0:6;
        RBus_UInt32  tab_r_d1:6;
        RBus_UInt32  tab_r_d2:6;
        RBus_UInt32  tab_r_d3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_e0:6;
        RBus_UInt32  tab_r_e1:6;
        RBus_UInt32  tab_r_e2:6;
        RBus_UInt32  tab_r_e3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_f0:6;
        RBus_UInt32  tab_r_f1:6;
        RBus_UInt32  tab_r_f2:6;
        RBus_UInt32  tab_r_f3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_00:6;
        RBus_UInt32  tab_g_01:6;
        RBus_UInt32  tab_g_02:6;
        RBus_UInt32  tab_g_03:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_10:6;
        RBus_UInt32  tab_g_11:6;
        RBus_UInt32  tab_g_12:6;
        RBus_UInt32  tab_g_13:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_20:6;
        RBus_UInt32  tab_g_21:6;
        RBus_UInt32  tab_g_22:6;
        RBus_UInt32  tab_g_23:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_30:6;
        RBus_UInt32  tab_g_31:6;
        RBus_UInt32  tab_g_32:6;
        RBus_UInt32  tab_g_33:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_40:6;
        RBus_UInt32  tab_g_41:6;
        RBus_UInt32  tab_g_42:6;
        RBus_UInt32  tab_g_43:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_50:6;
        RBus_UInt32  tab_g_51:6;
        RBus_UInt32  tab_g_52:6;
        RBus_UInt32  tab_g_53:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_60:6;
        RBus_UInt32  tab_g_61:6;
        RBus_UInt32  tab_g_62:6;
        RBus_UInt32  tab_g_63:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_70:6;
        RBus_UInt32  tab_g_71:6;
        RBus_UInt32  tab_g_72:6;
        RBus_UInt32  tab_g_73:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_80:6;
        RBus_UInt32  tab_g_81:6;
        RBus_UInt32  tab_g_82:6;
        RBus_UInt32  tab_g_83:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_90:6;
        RBus_UInt32  tab_g_91:6;
        RBus_UInt32  tab_g_92:6;
        RBus_UInt32  tab_g_93:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_a0:6;
        RBus_UInt32  tab_g_a1:6;
        RBus_UInt32  tab_g_a2:6;
        RBus_UInt32  tab_g_a3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_b0:6;
        RBus_UInt32  tab_g_b1:6;
        RBus_UInt32  tab_g_b2:6;
        RBus_UInt32  tab_g_b3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_c0:6;
        RBus_UInt32  tab_g_c1:6;
        RBus_UInt32  tab_g_c2:6;
        RBus_UInt32  tab_g_c3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_d0:6;
        RBus_UInt32  tab_g_d1:6;
        RBus_UInt32  tab_g_d2:6;
        RBus_UInt32  tab_g_d3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_e0:6;
        RBus_UInt32  tab_g_e1:6;
        RBus_UInt32  tab_g_e2:6;
        RBus_UInt32  tab_g_e3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_f0:6;
        RBus_UInt32  tab_g_f1:6;
        RBus_UInt32  tab_g_f2:6;
        RBus_UInt32  tab_g_f3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_00:6;
        RBus_UInt32  tab_b_01:6;
        RBus_UInt32  tab_b_02:6;
        RBus_UInt32  tab_b_03:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_10:6;
        RBus_UInt32  tab_b_11:6;
        RBus_UInt32  tab_b_12:6;
        RBus_UInt32  tab_b_13:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_20:6;
        RBus_UInt32  tab_b_21:6;
        RBus_UInt32  tab_b_22:6;
        RBus_UInt32  tab_b_23:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_30:6;
        RBus_UInt32  tab_b_31:6;
        RBus_UInt32  tab_b_32:6;
        RBus_UInt32  tab_b_33:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_40:6;
        RBus_UInt32  tab_b_41:6;
        RBus_UInt32  tab_b_42:6;
        RBus_UInt32  tab_b_43:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_50:6;
        RBus_UInt32  tab_b_51:6;
        RBus_UInt32  tab_b_52:6;
        RBus_UInt32  tab_b_53:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_60:6;
        RBus_UInt32  tab_b_61:6;
        RBus_UInt32  tab_b_62:6;
        RBus_UInt32  tab_b_63:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_70:6;
        RBus_UInt32  tab_b_71:6;
        RBus_UInt32  tab_b_72:6;
        RBus_UInt32  tab_b_73:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_80:6;
        RBus_UInt32  tab_b_81:6;
        RBus_UInt32  tab_b_82:6;
        RBus_UInt32  tab_b_83:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_90:6;
        RBus_UInt32  tab_b_91:6;
        RBus_UInt32  tab_b_92:6;
        RBus_UInt32  tab_b_93:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_a0:6;
        RBus_UInt32  tab_b_a1:6;
        RBus_UInt32  tab_b_a2:6;
        RBus_UInt32  tab_b_a3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_b0:6;
        RBus_UInt32  tab_b_b1:6;
        RBus_UInt32  tab_b_b2:6;
        RBus_UInt32  tab_b_b3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_c0:6;
        RBus_UInt32  tab_b_c1:6;
        RBus_UInt32  tab_b_c2:6;
        RBus_UInt32  tab_b_c3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_d0:6;
        RBus_UInt32  tab_b_d1:6;
        RBus_UInt32  tab_b_d2:6;
        RBus_UInt32  tab_b_d3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_e0:6;
        RBus_UInt32  tab_b_e1:6;
        RBus_UInt32  tab_b_e2:6;
        RBus_UInt32  tab_b_e3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_f0:6;
        RBus_UInt32  tab_b_f1:6;
        RBus_UInt32  tab_b_f2:6;
        RBus_UInt32  tab_b_f3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  temp_offset_0:2;
        RBus_UInt32  temp_offset_1:2;
        RBus_UInt32  temp_offset_2:2;
        RBus_UInt32  temp_offset_3:2;
        RBus_UInt32  temp_offset_4:2;
        RBus_UInt32  temp_offset_5:2;
        RBus_UInt32  temp_offset_6:2;
        RBus_UInt32  temp_offset_7:2;
        RBus_UInt32  temp_offset_8:2;
        RBus_UInt32  temp_offset_9:2;
        RBus_UInt32  temp_offset_10:2;
        RBus_UInt32  temp_offset_11:2;
        RBus_UInt32  temp_offset_12:2;
        RBus_UInt32  temp_offset_13:2;
        RBus_UInt32  temp_offset_14:2;
        RBus_UInt32  temp_offset_15:2;
    };
}dither_temporal_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dither_crc_start:1;
        RBus_UInt32  dither_crc_conti:1;
        RBus_UInt32  res1:30;
    };
}dither_dither_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_crc_result:32;
    };
}dither_dither_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_0:4;
        RBus_UInt32  seq_r_1:4;
        RBus_UInt32  seq_r_2:4;
        RBus_UInt32  seq_r_3:4;
        RBus_UInt32  seq_r_4:4;
        RBus_UInt32  seq_r_5:4;
        RBus_UInt32  seq_r_6:4;
        RBus_UInt32  seq_r_7:4;
    };
}dither_dithering_2nd_sequence_table_red_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_8:4;
        RBus_UInt32  seq_r_9:4;
        RBus_UInt32  seq_r_10:4;
        RBus_UInt32  seq_r_11:4;
        RBus_UInt32  seq_r_12:4;
        RBus_UInt32  seq_r_13:4;
        RBus_UInt32  seq_r_14:4;
        RBus_UInt32  seq_r_15:4;
    };
}dither_dithering_2nd_sequence_table_red_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_16:4;
        RBus_UInt32  seq_r_17:4;
        RBus_UInt32  seq_r_18:4;
        RBus_UInt32  seq_r_19:4;
        RBus_UInt32  seq_r_20:4;
        RBus_UInt32  seq_r_21:4;
        RBus_UInt32  seq_r_22:4;
        RBus_UInt32  seq_r_23:4;
    };
}dither_dithering_2nd_sequence_table_red_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_24:4;
        RBus_UInt32  seq_r_25:4;
        RBus_UInt32  seq_r_26:4;
        RBus_UInt32  seq_r_27:4;
        RBus_UInt32  seq_r_28:4;
        RBus_UInt32  seq_r_29:4;
        RBus_UInt32  seq_r_30:4;
        RBus_UInt32  seq_r_31:4;
    };
}dither_dithering_2nd_sequence_table_red_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_0:4;
        RBus_UInt32  seq_g_1:4;
        RBus_UInt32  seq_g_2:4;
        RBus_UInt32  seq_g_3:4;
        RBus_UInt32  seq_g_4:4;
        RBus_UInt32  seq_g_5:4;
        RBus_UInt32  seq_g_6:4;
        RBus_UInt32  seq_g_7:4;
    };
}dither_dithering_2nd_sequence_table_green_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_8:4;
        RBus_UInt32  seq_g_9:4;
        RBus_UInt32  seq_g_10:4;
        RBus_UInt32  seq_g_11:4;
        RBus_UInt32  seq_g_12:4;
        RBus_UInt32  seq_g_13:4;
        RBus_UInt32  seq_g_14:4;
        RBus_UInt32  seq_g_15:4;
    };
}dither_dithering_2nd_sequence_table_green_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_16:4;
        RBus_UInt32  seq_g_17:4;
        RBus_UInt32  seq_g_18:4;
        RBus_UInt32  seq_g_19:4;
        RBus_UInt32  seq_g_20:4;
        RBus_UInt32  seq_g_21:4;
        RBus_UInt32  seq_g_22:4;
        RBus_UInt32  seq_g_23:4;
    };
}dither_dithering_2nd_sequence_table_green_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_24:4;
        RBus_UInt32  seq_g_25:4;
        RBus_UInt32  seq_g_26:4;
        RBus_UInt32  seq_g_27:4;
        RBus_UInt32  seq_g_28:4;
        RBus_UInt32  seq_g_29:4;
        RBus_UInt32  seq_g_30:4;
        RBus_UInt32  seq_g_31:4;
    };
}dither_dithering_2nd_sequence_table_green_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_0:4;
        RBus_UInt32  seq_b_1:4;
        RBus_UInt32  seq_b_2:4;
        RBus_UInt32  seq_b_3:4;
        RBus_UInt32  seq_b_4:4;
        RBus_UInt32  seq_b_5:4;
        RBus_UInt32  seq_b_6:4;
        RBus_UInt32  seq_b_7:4;
    };
}dither_dithering_2nd_sequence_table_blue_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_8:4;
        RBus_UInt32  seq_b_9:4;
        RBus_UInt32  seq_b_10:4;
        RBus_UInt32  seq_b_11:4;
        RBus_UInt32  seq_b_12:4;
        RBus_UInt32  seq_b_13:4;
        RBus_UInt32  seq_b_14:4;
        RBus_UInt32  seq_b_15:4;
    };
}dither_dithering_2nd_sequence_table_blue_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_16:4;
        RBus_UInt32  seq_b_17:4;
        RBus_UInt32  seq_b_18:4;
        RBus_UInt32  seq_b_19:4;
        RBus_UInt32  seq_b_20:4;
        RBus_UInt32  seq_b_21:4;
        RBus_UInt32  seq_b_22:4;
        RBus_UInt32  seq_b_23:4;
    };
}dither_dithering_2nd_sequence_table_blue_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_24:4;
        RBus_UInt32  seq_b_25:4;
        RBus_UInt32  seq_b_26:4;
        RBus_UInt32  seq_b_27:4;
        RBus_UInt32  seq_b_28:4;
        RBus_UInt32  seq_b_29:4;
        RBus_UInt32  seq_b_30:4;
        RBus_UInt32  seq_b_31:4;
    };
}dither_dithering_2nd_sequence_table_blue_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_count_by_3d_flag_en:1;
        RBus_UInt32  frame_count_by_3d_l_flag_inv:1;
        RBus_UInt32  res1:30;
    };
}dither_dithering_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dd_b_b2_type:2;
        RBus_UInt32  dd_b_b1_type:2;
        RBus_UInt32  dd_b_b0_type:2;
        RBus_UInt32  dd_b_1_th:12;
        RBus_UInt32  dd_b_0_th:12;
        RBus_UInt32  dd_en:1;
        RBus_UInt32  res1:1;
    };
}dither_dithering_dd_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dd_g_b2_type:2;
        RBus_UInt32  dd_g_b1_type:2;
        RBus_UInt32  dd_g_b0_type:2;
        RBus_UInt32  dd_g_1_th:12;
        RBus_UInt32  dd_g_0_th:12;
        RBus_UInt32  res1:2;
    };
}dither_dithering_dd_th_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dd_r_b2_type:2;
        RBus_UInt32  dd_r_b1_type:2;
        RBus_UInt32  dd_r_b0_type:2;
        RBus_UInt32  dd_r_1_th:12;
        RBus_UInt32  dd_r_0_th:12;
        RBus_UInt32  res1:2;
    };
}dither_dithering_dd_th_r_RBUS;




#endif 


#endif 
