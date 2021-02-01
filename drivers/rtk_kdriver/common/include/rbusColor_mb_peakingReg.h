/**
* @file rbusColor_mb_peakingReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_MB_PEAKING_REG_H_
#define _RBUS_COLOR_MB_PEAKING_REG_H_

#include "rbusTypes.h"



//  COLOR_MB_PEAKING Register Address



#define  COLOR_MB_PEAKING_MB_PEAKING_CTRL_VADDR             	(0xb8023c00)
#define  COLOR_MB_PEAKING_MB_PEAKING_HOR_FILTER_0_VADDR     	(0xb8023c04)
#define  COLOR_MB_PEAKING_MB_PEAKING_HOR_FILTER_1_VADDR     	(0xb8023c08)
#define  COLOR_MB_PEAKING_MB_PEAKING_HOR_FILTER_2_VADDR     	(0xb8023c0c)
#define  COLOR_MB_PEAKING_MB_PEAKING_HOR_GAIN_VADDR         	(0xb8023c10)
#define  COLOR_MB_PEAKING_MB_PEAKING_HOR_BOUND_VADDR        	(0xb8023c14)
#define  COLOR_MB_PEAKING_MB_PEAKING_HOR_GAIN_2_VADDR       	(0xb8023c18)
#define  COLOR_MB_PEAKING_MB_PEAKING_VER_FILTER_VADDR       	(0xb8023c1c)
#define  COLOR_MB_PEAKING_MB_PEAKING_VER_GAIN_VADDR         	(0xb8023c20)
#define  COLOR_MB_PEAKING_MB_PEAKING_VER_BOUND_VADDR        	(0xb8023c24)
#define  COLOR_MB_PEAKING_MB_PEAKING_VER_GAIN_2_VADDR       	(0xb8023c28)
#define  COLOR_MB_PEAKING_MB_DOUBLE_BUFFER_CTRL_VADDR       	(0xb8023c30)
#define  COLOR_MB_PEAKING_MB_DUMMY_VADDR                    	(0xb8023c34)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_MB_PEAKING register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mb_v_en:1;
        RBus_UInt32  mb_h_en:1;
        RBus_UInt32  mb_ver_vfilter_data:1;
        RBus_UInt32  mb_peaking_en:1;
    };
}color_mb_peaking_mb_peaking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  mb_hor_filter_c0:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  mb_hor_filter_c1:9;
    };
}color_mb_peaking_mb_peaking_hor_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_hor_filter_c2:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  mb_hor_filter_c3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  mb_hor_filter_c4:7;
        RBus_UInt32  res3:2;
        RBus_UInt32  mb_hor_filter_c5:6;
    };
}color_mb_peaking_mb_peaking_hor_filter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  mb_hor_filter_c6:6;
    };
}color_mb_peaking_mb_peaking_hor_filter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mb_gain_pos:8;
        RBus_UInt32  mb_gain_neg:8;
    };
}color_mb_peaking_mb_peaking_hor_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  mb_hv_pos:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  mb_hv_neg:10;
    };
}color_mb_peaking_mb_peaking_hor_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_lv:8;
        RBus_UInt32  mb_lv2:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  mb_gain_pos2:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  mb_gain_neg2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  mb_d2_shift_bit:2;
        RBus_UInt32  res4:4;
    };
}color_mb_peaking_mb_peaking_hor_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_ver_filter_c0:9;
        RBus_UInt32  res1:6;
        RBus_UInt32  mb_ver_filter_c1:9;
        RBus_UInt32  mb_ver_filter_c2:8;
    };
}color_mb_peaking_mb_peaking_ver_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mb_gain_pos_v:8;
        RBus_UInt32  mb_gain_neg_v:8;
    };
}color_mb_peaking_mb_peaking_ver_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  mb_hv_pos_v:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  mb_hv_neg_v:10;
    };
}color_mb_peaking_mb_peaking_ver_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_lv_v:8;
        RBus_UInt32  mb_lv2_v:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  mb_gain_pos2_v:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  mb_gain_neg2_v:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  mb_d2_shift_bit_v:2;
        RBus_UInt32  res4:4;
    };
}color_mb_peaking_mb_peaking_ver_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mb_db_en:1;
        RBus_UInt32  mb_db_read_sel:1;
        RBus_UInt32  mb_db_apply:1;
    };
}color_mb_peaking_mb_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18023c34_7_0:8;
    };
}color_mb_peaking_mb_dummy_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_MB_PEAKING register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_peaking_en:1;
        RBus_UInt32  mb_ver_vfilter_data:1;
        RBus_UInt32  mb_h_en:1;
        RBus_UInt32  mb_v_en:1;
        RBus_UInt32  res1:28;
    };
}color_mb_peaking_mb_peaking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_hor_filter_c1:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  mb_hor_filter_c0:9;
        RBus_UInt32  res2:7;
    };
}color_mb_peaking_mb_peaking_hor_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_hor_filter_c5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  mb_hor_filter_c4:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  mb_hor_filter_c3:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  mb_hor_filter_c2:8;
    };
}color_mb_peaking_mb_peaking_hor_filter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_hor_filter_c6:6;
        RBus_UInt32  res1:26;
    };
}color_mb_peaking_mb_peaking_hor_filter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_gain_neg:8;
        RBus_UInt32  mb_gain_pos:8;
        RBus_UInt32  res1:16;
    };
}color_mb_peaking_mb_peaking_hor_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_hv_neg:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  mb_hv_pos:10;
        RBus_UInt32  res2:6;
    };
}color_mb_peaking_mb_peaking_hor_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mb_d2_shift_bit:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  mb_gain_neg2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  mb_gain_pos2:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  mb_lv2:8;
        RBus_UInt32  mb_lv:8;
    };
}color_mb_peaking_mb_peaking_hor_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_ver_filter_c2:8;
        RBus_UInt32  mb_ver_filter_c1:9;
        RBus_UInt32  res1:6;
        RBus_UInt32  mb_ver_filter_c0:9;
    };
}color_mb_peaking_mb_peaking_ver_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_gain_neg_v:8;
        RBus_UInt32  mb_gain_pos_v:8;
        RBus_UInt32  res1:16;
    };
}color_mb_peaking_mb_peaking_ver_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_hv_neg_v:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  mb_hv_pos_v:10;
        RBus_UInt32  res2:6;
    };
}color_mb_peaking_mb_peaking_ver_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mb_d2_shift_bit_v:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  mb_gain_neg2_v:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  mb_gain_pos2_v:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  mb_lv2_v:8;
        RBus_UInt32  mb_lv_v:8;
    };
}color_mb_peaking_mb_peaking_ver_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_db_apply:1;
        RBus_UInt32  mb_db_read_sel:1;
        RBus_UInt32  mb_db_en:1;
        RBus_UInt32  res1:29;
    };
}color_mb_peaking_mb_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18023c34_7_0:8;
        RBus_UInt32  res1:24;
    };
}color_mb_peaking_mb_dummy_RBUS;




#endif 


#endif 
