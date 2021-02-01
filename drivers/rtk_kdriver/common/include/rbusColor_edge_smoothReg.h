/**
* @file rbusColor_edge_smoothReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_EDGE_SMOOTH_REG_H_
#define _RBUS_COLOR_EDGE_SMOOTH_REG_H_

#include "rbusTypes.h"



//  COLOR_EDGE_SMOOTH Register Address



#define  COLOR_EDGE_SMOOTH_DM_EDGESMOOTH_2DSHP_DIRLPF_CTRL_VADDR 	(0xb802aa00)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_VADDR   	(0xb802aa04)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_VADDR 	(0xb802aa08)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_VADDR 	(0xb802aa0c)
#define  COLOR_EDGE_SMOOTH_DM_EDGESMOOTH_DIRLPF_DECHAOS_VADDR 	(0xb802aa10)
#define  COLOR_EDGE_SMOOTH_DM_EDGESMOOTH_POSTSHP_GAIN_VADDR 	(0xb802aa14)
#define  COLOR_EDGE_SMOOTH_DM_EDGESMOOTH_POSTSHP_BOUND_VADDR 	(0xb802aa18)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_EDGE_SMOOTH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  verlpf_select:1;
        RBus_UInt32  weighting_factor:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  outcurline_mode:2;
        RBus_UInt32  incurline_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sobel_extend_enable:1;
        RBus_UInt32  sobel_debug_enable:1;
        RBus_UInt32  dirlpf_enable:1;
        RBus_UInt32  res4:8;
    };
}color_edge_smooth_dm_edgesmooth_2dshp_dirlpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_ths:8;
        RBus_UInt32  sobel_thm:8;
        RBus_UInt32  sobel_ths_lowang:8;
        RBus_UInt32  sobel_thm_lowang:8;
    };
}color_edge_smooth_dm_sobel_draft_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_ths_hiang:8;
        RBus_UInt32  sobel_thm_hiang:8;
        RBus_UInt32  sobel_th_v3:8;
        RBus_UInt32  sobel_th_h3:8;
    };
}color_edge_smooth_dm_sobel_threshold_lowangle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_th_v4:8;
        RBus_UInt32  sobel_th_h4:8;
        RBus_UInt32  sobel_th_v5:8;
        RBus_UInt32  sobel_th_h5:8;
    };
}color_edge_smooth_dm_sobel_threshold_hiangle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_th_v6:8;
        RBus_UInt32  five_lines_enable:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  chaos_weight:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  max1_thd:3;
        RBus_UInt32  chaos_thd:3;
        RBus_UInt32  chaos_en:1;
    };
}color_edge_smooth_dm_edgesmooth_dirlpf_dechaos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  postshp_enable:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  postshp_gain_pos:8;
        RBus_UInt32  postshp_gain_neg:8;
    };
}color_edge_smooth_dm_edgesmooth_postshp_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  postshp_hv_pos:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  postshp_hv_neg:10;
        RBus_UInt32  postshp_lv:8;
    };
}color_edge_smooth_dm_edgesmooth_postshp_bound_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_EDGE_SMOOTH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dirlpf_enable:1;
        RBus_UInt32  sobel_debug_enable:1;
        RBus_UInt32  sobel_extend_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  incurline_mode:1;
        RBus_UInt32  outcurline_mode:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  weighting_factor:4;
        RBus_UInt32  verlpf_select:1;
        RBus_UInt32  res4:11;
    };
}color_edge_smooth_dm_edgesmooth_2dshp_dirlpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_thm_lowang:8;
        RBus_UInt32  sobel_ths_lowang:8;
        RBus_UInt32  sobel_thm:8;
        RBus_UInt32  sobel_ths:8;
    };
}color_edge_smooth_dm_sobel_draft_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_th_h3:8;
        RBus_UInt32  sobel_th_v3:8;
        RBus_UInt32  sobel_thm_hiang:8;
        RBus_UInt32  sobel_ths_hiang:8;
    };
}color_edge_smooth_dm_sobel_threshold_lowangle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_th_h5:8;
        RBus_UInt32  sobel_th_v5:8;
        RBus_UInt32  sobel_th_h4:8;
        RBus_UInt32  sobel_th_v4:8;
    };
}color_edge_smooth_dm_sobel_threshold_hiangle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chaos_en:1;
        RBus_UInt32  chaos_thd:3;
        RBus_UInt32  max1_thd:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  chaos_weight:2;
        RBus_UInt32  res2:13;
        RBus_UInt32  five_lines_enable:1;
        RBus_UInt32  sobel_th_v6:8;
    };
}color_edge_smooth_dm_edgesmooth_dirlpf_dechaos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postshp_gain_neg:8;
        RBus_UInt32  postshp_gain_pos:8;
        RBus_UInt32  res1:12;
        RBus_UInt32  postshp_enable:1;
        RBus_UInt32  res2:3;
    };
}color_edge_smooth_dm_edgesmooth_postshp_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postshp_lv:8;
        RBus_UInt32  postshp_hv_neg:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  postshp_hv_pos:10;
        RBus_UInt32  res2:2;
    };
}color_edge_smooth_dm_edgesmooth_postshp_bound_RBUS;




#endif 


#endif 
