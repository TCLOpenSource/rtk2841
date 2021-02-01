/**
* @file rbusDe_ContourReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DE_CONTOUR_REG_H_
#define _RBUS_DE_CONTOUR_REG_H_

#include "rbusTypes.h"



//  DE_CONTOUR Register Address



#define  DE_CONTOUR_DCT_CONTROL_VADDR                       	(0xb802a900)
#define  DE_CONTOUR_DCT_LPF_VADDR                           	(0xb802a904)
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_VADDR               	(0xb802a908)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_VADDR                    	(0xb802a90c)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DE_CONTOUR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dct_debug:1;
        RBus_UInt32  dct_en:1;
    };
}de_contour_dct_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dct_lp_shift:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dct_lp_k5:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  dct_lp_k4:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  dct_lp_k3:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  dct_lp_k2:4;
        RBus_UInt32  res5:1;
        RBus_UInt32  dct_lp_k1:4;
        RBus_UInt32  res6:1;
        RBus_UInt32  dct_lp_k0:4;
    };
}de_contour_dct_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dct_smooth_w1_w2_weight:5;
        RBus_UInt32  res1:4;
        RBus_UInt32  dct_smooth_tex_w2:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  dct_smooth_mean_w1:9;
    };
}de_contour_dct_weight_mean_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dct_all_channel_blend_weight:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  dct_smooth_gap_weight:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  dct_gap_w3:11;
        RBus_UInt32  res3:2;
        RBus_UInt32  dct_min_gap_w3:7;
    };
}de_contour_dct_weight_gap_RBUS;

#else //apply LITTLE_ENDIAN

//======DE_CONTOUR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dct_en:1;
        RBus_UInt32  dct_debug:1;
        RBus_UInt32  res1:30;
    };
}de_contour_dct_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dct_lp_k0:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  dct_lp_k1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  dct_lp_k2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  dct_lp_k3:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  dct_lp_k4:4;
        RBus_UInt32  res5:1;
        RBus_UInt32  dct_lp_k5:4;
        RBus_UInt32  res6:2;
        RBus_UInt32  dct_lp_shift:1;
    };
}de_contour_dct_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dct_smooth_mean_w1:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  dct_smooth_tex_w2:11;
        RBus_UInt32  res2:4;
        RBus_UInt32  dct_smooth_w1_w2_weight:5;
    };
}de_contour_dct_weight_mean_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dct_min_gap_w3:7;
        RBus_UInt32  res1:2;
        RBus_UInt32  dct_gap_w3:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  dct_smooth_gap_weight:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  dct_all_channel_blend_weight:4;
    };
}de_contour_dct_weight_gap_RBUS;




#endif 


#endif 
