/**
* @file rbusDe_ContourReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DE_CONTOUR_REG_H_
#define _RBUS_DE_CONTOUR_REG_H_

#include "rbus_types.h"



//  DE_CONTOUR Register Address
#define  DE_CONTOUR_DCT_CONTROL                                                  0x1802A900
#define  DE_CONTOUR_DCT_CONTROL_reg_addr                                         "0xB802A900"
#define  DE_CONTOUR_DCT_CONTROL_reg                                              0xB802A900
#define  DE_CONTOUR_DCT_CONTROL_inst_addr                                        "0x0000"
#define  set_DE_CONTOUR_DCT_CONTROL_reg(data)                                    (*((volatile unsigned int*)DE_CONTOUR_DCT_CONTROL_reg)=data)
#define  get_DE_CONTOUR_DCT_CONTROL_reg                                          (*((volatile unsigned int*)DE_CONTOUR_DCT_CONTROL_reg))
#define  DE_CONTOUR_DCT_CONTROL_dct_debug_shift                                  (1)
#define  DE_CONTOUR_DCT_CONTROL_dct_en_shift                                     (0)
#define  DE_CONTOUR_DCT_CONTROL_dct_debug_mask                                   (0x00000002)
#define  DE_CONTOUR_DCT_CONTROL_dct_en_mask                                      (0x00000001)
#define  DE_CONTOUR_DCT_CONTROL_dct_debug(data)                                  (0x00000002&((data)<<1))
#define  DE_CONTOUR_DCT_CONTROL_dct_en(data)                                     (0x00000001&(data))
#define  DE_CONTOUR_DCT_CONTROL_get_dct_debug(data)                              ((0x00000002&(data))>>1)
#define  DE_CONTOUR_DCT_CONTROL_get_dct_en(data)                                 (0x00000001&(data))

#define  DE_CONTOUR_DCT_LPF                                                      0x1802A904
#define  DE_CONTOUR_DCT_LPF_reg_addr                                             "0xB802A904"
#define  DE_CONTOUR_DCT_LPF_reg                                                  0xB802A904
#define  DE_CONTOUR_DCT_LPF_inst_addr                                            "0x0001"
#define  set_DE_CONTOUR_DCT_LPF_reg(data)                                        (*((volatile unsigned int*)DE_CONTOUR_DCT_LPF_reg)=data)
#define  get_DE_CONTOUR_DCT_LPF_reg                                              (*((volatile unsigned int*)DE_CONTOUR_DCT_LPF_reg))
#define  DE_CONTOUR_DCT_LPF_dct_lp_shift_shift                                   (31)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k5_shift                                      (25)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k4_shift                                      (20)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k3_shift                                      (15)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k2_shift                                      (10)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k1_shift                                      (5)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k0_shift                                      (0)
#define  DE_CONTOUR_DCT_LPF_dct_lp_shift_mask                                    (0x80000000)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k5_mask                                       (0x1E000000)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k4_mask                                       (0x00F00000)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k3_mask                                       (0x00078000)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k2_mask                                       (0x00003C00)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k1_mask                                       (0x000001E0)
#define  DE_CONTOUR_DCT_LPF_dct_lp_k0_mask                                       (0x0000000F)
#define  DE_CONTOUR_DCT_LPF_dct_lp_shift(data)                                   (0x80000000&((data)<<31))
#define  DE_CONTOUR_DCT_LPF_dct_lp_k5(data)                                      (0x1E000000&((data)<<25))
#define  DE_CONTOUR_DCT_LPF_dct_lp_k4(data)                                      (0x00F00000&((data)<<20))
#define  DE_CONTOUR_DCT_LPF_dct_lp_k3(data)                                      (0x00078000&((data)<<15))
#define  DE_CONTOUR_DCT_LPF_dct_lp_k2(data)                                      (0x00003C00&((data)<<10))
#define  DE_CONTOUR_DCT_LPF_dct_lp_k1(data)                                      (0x000001E0&((data)<<5))
#define  DE_CONTOUR_DCT_LPF_dct_lp_k0(data)                                      (0x0000000F&(data))
#define  DE_CONTOUR_DCT_LPF_get_dct_lp_shift(data)                               ((0x80000000&(data))>>31)
#define  DE_CONTOUR_DCT_LPF_get_dct_lp_k5(data)                                  ((0x1E000000&(data))>>25)
#define  DE_CONTOUR_DCT_LPF_get_dct_lp_k4(data)                                  ((0x00F00000&(data))>>20)
#define  DE_CONTOUR_DCT_LPF_get_dct_lp_k3(data)                                  ((0x00078000&(data))>>15)
#define  DE_CONTOUR_DCT_LPF_get_dct_lp_k2(data)                                  ((0x00003C00&(data))>>10)
#define  DE_CONTOUR_DCT_LPF_get_dct_lp_k1(data)                                  ((0x000001E0&(data))>>5)
#define  DE_CONTOUR_DCT_LPF_get_dct_lp_k0(data)                                  (0x0000000F&(data))

#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX                                          0x1802A908
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_reg_addr                                 "0xB802A908"
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_reg                                      0xB802A908
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_inst_addr                                "0x0002"
#define  set_DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_reg(data)                            (*((volatile unsigned int*)DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_reg)=data)
#define  get_DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_reg                                  (*((volatile unsigned int*)DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_reg))
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_dct_smooth_w1_w2_weight_shift            (27)
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_dct_smooth_tex_w2_shift                  (12)
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_dct_smooth_mean_w1_shift                 (0)
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_dct_smooth_w1_w2_weight_mask             (0xF8000000)
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_dct_smooth_tex_w2_mask                   (0x007FF000)
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_dct_smooth_mean_w1_mask                  (0x000001FF)
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_dct_smooth_w1_w2_weight(data)            (0xF8000000&((data)<<27))
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_dct_smooth_tex_w2(data)                  (0x007FF000&((data)<<12))
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_dct_smooth_mean_w1(data)                 (0x000001FF&(data))
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_get_dct_smooth_w1_w2_weight(data)        ((0xF8000000&(data))>>27)
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_get_dct_smooth_tex_w2(data)              ((0x007FF000&(data))>>12)
#define  DE_CONTOUR_DCT_WEIGHT_MEAN_TEX_get_dct_smooth_mean_w1(data)             (0x000001FF&(data))

#define  DE_CONTOUR_DCT_WEIGHT_GAP                                               0x1802A90C
#define  DE_CONTOUR_DCT_WEIGHT_GAP_reg_addr                                      "0xB802A90C"
#define  DE_CONTOUR_DCT_WEIGHT_GAP_reg                                           0xB802A90C
#define  DE_CONTOUR_DCT_WEIGHT_GAP_inst_addr                                     "0x0003"
#define  set_DE_CONTOUR_DCT_WEIGHT_GAP_reg(data)                                 (*((volatile unsigned int*)DE_CONTOUR_DCT_WEIGHT_GAP_reg)=data)
#define  get_DE_CONTOUR_DCT_WEIGHT_GAP_reg                                       (*((volatile unsigned int*)DE_CONTOUR_DCT_WEIGHT_GAP_reg))
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_all_channel_blend_weight_shift            (28)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_smooth_gap_weight_shift                   (22)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_gap_w3_shift                              (9)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_min_gap_w3_shift                          (0)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_all_channel_blend_weight_mask             (0xF0000000)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_smooth_gap_weight_mask                    (0x03C00000)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_gap_w3_mask                               (0x000FFE00)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_min_gap_w3_mask                           (0x0000007F)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_all_channel_blend_weight(data)            (0xF0000000&((data)<<28))
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_smooth_gap_weight(data)                   (0x03C00000&((data)<<22))
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_gap_w3(data)                              (0x000FFE00&((data)<<9))
#define  DE_CONTOUR_DCT_WEIGHT_GAP_dct_min_gap_w3(data)                          (0x0000007F&(data))
#define  DE_CONTOUR_DCT_WEIGHT_GAP_get_dct_all_channel_blend_weight(data)        ((0xF0000000&(data))>>28)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_get_dct_smooth_gap_weight(data)               ((0x03C00000&(data))>>22)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_get_dct_gap_w3(data)                          ((0x000FFE00&(data))>>9)
#define  DE_CONTOUR_DCT_WEIGHT_GAP_get_dct_min_gap_w3(data)                      (0x0000007F&(data))

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
