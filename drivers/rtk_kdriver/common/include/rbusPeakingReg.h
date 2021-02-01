/**
* @file rbusPeakingReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PEAKING_REG_H_
#define _RBUS_PEAKING_REG_H_

#include "rbusTypes.h"



//  PEAKING Register Address



#define  PEAKING_ICH1_PEAKING_FILTER_VADDR                  	(0xb8023100)
#define  PEAKING_ICH1_PEAKING_GAIN_VADDR                    	(0xb8023104)
#define  PEAKING_ICH1_PEAKING_BOUND_VADDR                   	(0xb8023108)
#define  PEAKING_ICH2_PEAKING_FILTER_VADDR                  	(0xb802310c)
#define  PEAKING_ICH2_PEAKING_GAIN_VADDR                    	(0xb8023110)
#define  PEAKING_ICH2_PEAKING_BOUND_VADDR                   	(0xb8023114)
#define  PEAKING_I_DLTI_CTRL_VADDR                          	(0xb8023170)
#define  PEAKING_ICH1_DLTI_TH_VADDR                         	(0xb8023174)
#define  PEAKING_ICH1_DLTI_C0_VADDR                         	(0xb8023178)
#define  PEAKING_ICH1_DLTI_C2_VADDR                         	(0xb802317c)
#define  PEAKING_ICH1_DLTI_C4_VADDR                         	(0xb8023180)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PEAKING register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  peaking_enable:1;
        RBus_UInt32  pxlsel:2;
        RBus_UInt32  c0:8;
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
    };
}peaking_ich1_peaking_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  gain_blr:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}peaking_ich1_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}peaking_ich1_peaking_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  peaking_enable:1;
        RBus_UInt32  pxlsel:2;
        RBus_UInt32  c0:8;
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
    };
}peaking_ich2_peaking_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  gain_blr:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}peaking_ich2_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  hv_neg:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  lv:6;
        RBus_UInt32  res4:2;
    };
}peaking_ich2_peaking_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dummy18023170_29_26:4;
        RBus_UInt32  new_function_blend:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  undo_pixel:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  ch1_dlti_gain:6;
        RBus_UInt32  ch1_lope_search_range_left:2;
        RBus_UInt32  ch1_lope_search_range_right:2;
        RBus_UInt32  ch1_mean_search_range:2;
        RBus_UInt32  ch1_lope_det_en:1;
        RBus_UInt32  ch1_filter_det_en:1;
        RBus_UInt32  ch1_dlti_en:1;
    };
}peaking_i_dlti_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_upper_th:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_lower_th:10;
    };
}peaking_ich1_dlti_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ch1_filter_c1:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  ch1_filter_c0:9;
    };
}peaking_ich1_dlti_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ch1_filter_c3:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  ch1_filter_c2:9;
    };
}peaking_ich1_dlti_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ch1_filter_c4:9;
    };
}peaking_ich1_dlti_c4_RBUS;

#else //apply LITTLE_ENDIAN

//======PEAKING register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
        RBus_UInt32  c0:8;
        RBus_UInt32  pxlsel:2;
        RBus_UInt32  peaking_enable:1;
        RBus_UInt32  res1:5;
    };
}peaking_ich1_peaking_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_blr:8;
        RBus_UInt32  res1:8;
    };
}peaking_ich1_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}peaking_ich1_peaking_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
        RBus_UInt32  c0:8;
        RBus_UInt32  pxlsel:2;
        RBus_UInt32  peaking_enable:1;
        RBus_UInt32  res1:5;
    };
}peaking_ich2_peaking_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_blr:8;
        RBus_UInt32  res1:8;
    };
}peaking_ich2_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lv:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hv_neg:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  hv_pos:8;
        RBus_UInt32  res4:4;
    };
}peaking_ich2_peaking_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_dlti_en:1;
        RBus_UInt32  ch1_filter_det_en:1;
        RBus_UInt32  ch1_lope_det_en:1;
        RBus_UInt32  ch1_mean_search_range:2;
        RBus_UInt32  ch1_lope_search_range_right:2;
        RBus_UInt32  ch1_lope_search_range_left:2;
        RBus_UInt32  ch1_dlti_gain:6;
        RBus_UInt32  res1:5;
        RBus_UInt32  undo_pixel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  new_function_blend:1;
        RBus_UInt32  dummy18023170_29:4;
        RBus_UInt32  res3:2;
    };
}peaking_i_dlti_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_lower_th:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_upper_th:10;
        RBus_UInt32  res2:6;
    };
}peaking_ich1_dlti_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_filter_c0:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  ch1_filter_c1:9;
        RBus_UInt32  res2:7;
    };
}peaking_ich1_dlti_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_filter_c2:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  ch1_filter_c3:9;
        RBus_UInt32  res2:7;
    };
}peaking_ich1_dlti_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_filter_c4:9;
        RBus_UInt32  res1:23;
    };
}peaking_ich1_dlti_c4_RBUS;




#endif 


#endif 
