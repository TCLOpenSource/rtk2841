/**
* @file MacArthur5-DesignSpec-I-Domain_dlti
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PEAKING_REG_H_
#define _RBUS_PEAKING_REG_H_

#include "rbus_types.h"



//  PEAKING Register Address
#define  PEAKING_I_DLTI_CTRL                                                     0x18023170
#define  PEAKING_I_DLTI_CTRL_reg_addr                                            "0xB8023170"
#define  PEAKING_I_DLTI_CTRL_reg                                                 0xB8023170
#define  PEAKING_I_DLTI_CTRL_inst_addr                                           "0x0000"
#define  set_PEAKING_I_DLTI_CTRL_reg(data)                                       (*((volatile unsigned int*)PEAKING_I_DLTI_CTRL_reg)=data)
#define  get_PEAKING_I_DLTI_CTRL_reg                                             (*((volatile unsigned int*)PEAKING_I_DLTI_CTRL_reg))
#define  PEAKING_I_DLTI_CTRL_dummy_29_26_shift                                   (26)
#define  PEAKING_I_DLTI_CTRL_new_function_blend_shift                            (25)
#define  PEAKING_I_DLTI_CTRL_undo_pixel_shift                                    (20)
#define  PEAKING_I_DLTI_CTRL_ch1_dlti_gain_shift                                 (9)
#define  PEAKING_I_DLTI_CTRL_ch1_lope_search_range_left_shift                    (7)
#define  PEAKING_I_DLTI_CTRL_ch1_lope_search_range_right_shift                   (5)
#define  PEAKING_I_DLTI_CTRL_ch1_mean_search_range_shift                         (3)
#define  PEAKING_I_DLTI_CTRL_ch1_lope_det_en_shift                               (2)
#define  PEAKING_I_DLTI_CTRL_ch1_filter_det_en_shift                             (1)
#define  PEAKING_I_DLTI_CTRL_ch1_dlti_en_shift                                   (0)
#define  PEAKING_I_DLTI_CTRL_dummy_29_26_mask                                    (0x3C000000)
#define  PEAKING_I_DLTI_CTRL_new_function_blend_mask                             (0x02000000)
#define  PEAKING_I_DLTI_CTRL_undo_pixel_mask                                     (0x00300000)
#define  PEAKING_I_DLTI_CTRL_ch1_dlti_gain_mask                                  (0x00007E00)
#define  PEAKING_I_DLTI_CTRL_ch1_lope_search_range_left_mask                     (0x00000180)
#define  PEAKING_I_DLTI_CTRL_ch1_lope_search_range_right_mask                    (0x00000060)
#define  PEAKING_I_DLTI_CTRL_ch1_mean_search_range_mask                          (0x00000018)
#define  PEAKING_I_DLTI_CTRL_ch1_lope_det_en_mask                                (0x00000004)
#define  PEAKING_I_DLTI_CTRL_ch1_filter_det_en_mask                              (0x00000002)
#define  PEAKING_I_DLTI_CTRL_ch1_dlti_en_mask                                    (0x00000001)
#define  PEAKING_I_DLTI_CTRL_dummy_29_26(data)                                   (0x3C000000&((data)<<26))
#define  PEAKING_I_DLTI_CTRL_new_function_blend(data)                            (0x02000000&((data)<<25))
#define  PEAKING_I_DLTI_CTRL_undo_pixel(data)                                    (0x00300000&((data)<<20))
#define  PEAKING_I_DLTI_CTRL_ch1_dlti_gain(data)                                 (0x00007E00&((data)<<9))
#define  PEAKING_I_DLTI_CTRL_ch1_lope_search_range_left(data)                    (0x00000180&((data)<<7))
#define  PEAKING_I_DLTI_CTRL_ch1_lope_search_range_right(data)                   (0x00000060&((data)<<5))
#define  PEAKING_I_DLTI_CTRL_ch1_mean_search_range(data)                         (0x00000018&((data)<<3))
#define  PEAKING_I_DLTI_CTRL_ch1_lope_det_en(data)                               (0x00000004&((data)<<2))
#define  PEAKING_I_DLTI_CTRL_ch1_filter_det_en(data)                             (0x00000002&((data)<<1))
#define  PEAKING_I_DLTI_CTRL_ch1_dlti_en(data)                                   (0x00000001&(data))
#define  PEAKING_I_DLTI_CTRL_get_dummy_29_26(data)                               ((0x3C000000&(data))>>26)
#define  PEAKING_I_DLTI_CTRL_get_new_function_blend(data)                        ((0x02000000&(data))>>25)
#define  PEAKING_I_DLTI_CTRL_get_undo_pixel(data)                                ((0x00300000&(data))>>20)
#define  PEAKING_I_DLTI_CTRL_get_ch1_dlti_gain(data)                             ((0x00007E00&(data))>>9)
#define  PEAKING_I_DLTI_CTRL_get_ch1_lope_search_range_left(data)                ((0x00000180&(data))>>7)
#define  PEAKING_I_DLTI_CTRL_get_ch1_lope_search_range_right(data)               ((0x00000060&(data))>>5)
#define  PEAKING_I_DLTI_CTRL_get_ch1_mean_search_range(data)                     ((0x00000018&(data))>>3)
#define  PEAKING_I_DLTI_CTRL_get_ch1_lope_det_en(data)                           ((0x00000004&(data))>>2)
#define  PEAKING_I_DLTI_CTRL_get_ch1_filter_det_en(data)                         ((0x00000002&(data))>>1)
#define  PEAKING_I_DLTI_CTRL_get_ch1_dlti_en(data)                               (0x00000001&(data))

#define  PEAKING_ICH1_DLTI_TH                                                    0x18023174
#define  PEAKING_ICH1_DLTI_TH_reg_addr                                           "0xB8023174"
#define  PEAKING_ICH1_DLTI_TH_reg                                                0xB8023174
#define  PEAKING_ICH1_DLTI_TH_inst_addr                                          "0x0001"
#define  set_PEAKING_ICH1_DLTI_TH_reg(data)                                      (*((volatile unsigned int*)PEAKING_ICH1_DLTI_TH_reg)=data)
#define  get_PEAKING_ICH1_DLTI_TH_reg                                            (*((volatile unsigned int*)PEAKING_ICH1_DLTI_TH_reg))
#define  PEAKING_ICH1_DLTI_TH_ch1_upper_th_shift                                 (16)
#define  PEAKING_ICH1_DLTI_TH_ch1_lower_th_shift                                 (0)
#define  PEAKING_ICH1_DLTI_TH_ch1_upper_th_mask                                  (0x03FF0000)
#define  PEAKING_ICH1_DLTI_TH_ch1_lower_th_mask                                  (0x000003FF)
#define  PEAKING_ICH1_DLTI_TH_ch1_upper_th(data)                                 (0x03FF0000&((data)<<16))
#define  PEAKING_ICH1_DLTI_TH_ch1_lower_th(data)                                 (0x000003FF&(data))
#define  PEAKING_ICH1_DLTI_TH_get_ch1_upper_th(data)                             ((0x03FF0000&(data))>>16)
#define  PEAKING_ICH1_DLTI_TH_get_ch1_lower_th(data)                             (0x000003FF&(data))

#define  PEAKING_ICH1_DLTI_C0                                                    0x18023178
#define  PEAKING_ICH1_DLTI_C0_reg_addr                                           "0xB8023178"
#define  PEAKING_ICH1_DLTI_C0_reg                                                0xB8023178
#define  PEAKING_ICH1_DLTI_C0_inst_addr                                          "0x0002"
#define  set_PEAKING_ICH1_DLTI_C0_reg(data)                                      (*((volatile unsigned int*)PEAKING_ICH1_DLTI_C0_reg)=data)
#define  get_PEAKING_ICH1_DLTI_C0_reg                                            (*((volatile unsigned int*)PEAKING_ICH1_DLTI_C0_reg))
#define  PEAKING_ICH1_DLTI_C0_ch1_filter_c1_shift                                (16)
#define  PEAKING_ICH1_DLTI_C0_ch1_filter_c0_shift                                (0)
#define  PEAKING_ICH1_DLTI_C0_ch1_filter_c1_mask                                 (0x01FF0000)
#define  PEAKING_ICH1_DLTI_C0_ch1_filter_c0_mask                                 (0x000001FF)
#define  PEAKING_ICH1_DLTI_C0_ch1_filter_c1(data)                                (0x01FF0000&((data)<<16))
#define  PEAKING_ICH1_DLTI_C0_ch1_filter_c0(data)                                (0x000001FF&(data))
#define  PEAKING_ICH1_DLTI_C0_get_ch1_filter_c1(data)                            ((0x01FF0000&(data))>>16)
#define  PEAKING_ICH1_DLTI_C0_get_ch1_filter_c0(data)                            (0x000001FF&(data))

#define  PEAKING_ICH1_DLTI_C2                                                    0x1802317C
#define  PEAKING_ICH1_DLTI_C2_reg_addr                                           "0xB802317C"
#define  PEAKING_ICH1_DLTI_C2_reg                                                0xB802317C
#define  PEAKING_ICH1_DLTI_C2_inst_addr                                          "0x0003"
#define  set_PEAKING_ICH1_DLTI_C2_reg(data)                                      (*((volatile unsigned int*)PEAKING_ICH1_DLTI_C2_reg)=data)
#define  get_PEAKING_ICH1_DLTI_C2_reg                                            (*((volatile unsigned int*)PEAKING_ICH1_DLTI_C2_reg))
#define  PEAKING_ICH1_DLTI_C2_ch1_filter_c3_shift                                (16)
#define  PEAKING_ICH1_DLTI_C2_ch1_filter_c2_shift                                (0)
#define  PEAKING_ICH1_DLTI_C2_ch1_filter_c3_mask                                 (0x01FF0000)
#define  PEAKING_ICH1_DLTI_C2_ch1_filter_c2_mask                                 (0x000001FF)
#define  PEAKING_ICH1_DLTI_C2_ch1_filter_c3(data)                                (0x01FF0000&((data)<<16))
#define  PEAKING_ICH1_DLTI_C2_ch1_filter_c2(data)                                (0x000001FF&(data))
#define  PEAKING_ICH1_DLTI_C2_get_ch1_filter_c3(data)                            ((0x01FF0000&(data))>>16)
#define  PEAKING_ICH1_DLTI_C2_get_ch1_filter_c2(data)                            (0x000001FF&(data))

#define  PEAKING_ICH1_DLTI_C4                                                    0x18023180
#define  PEAKING_ICH1_DLTI_C4_reg_addr                                           "0xB8023180"
#define  PEAKING_ICH1_DLTI_C4_reg                                                0xB8023180
#define  PEAKING_ICH1_DLTI_C4_inst_addr                                          "0x0004"
#define  set_PEAKING_ICH1_DLTI_C4_reg(data)                                      (*((volatile unsigned int*)PEAKING_ICH1_DLTI_C4_reg)=data)
#define  get_PEAKING_ICH1_DLTI_C4_reg                                            (*((volatile unsigned int*)PEAKING_ICH1_DLTI_C4_reg))
#define  PEAKING_ICH1_DLTI_C4_ch1_filter_c4_shift                                (0)
#define  PEAKING_ICH1_DLTI_C4_ch1_filter_c4_mask                                 (0x000001FF)
#define  PEAKING_ICH1_DLTI_C4_ch1_filter_c4(data)                                (0x000001FF&(data))
#define  PEAKING_ICH1_DLTI_C4_get_ch1_filter_c4(data)                            (0x000001FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PEAKING register structure define==========

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
        RBus_UInt32  dummy18023170_29_26:4;
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
