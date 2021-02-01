/**
* @file Mac5-DesignSpec-D-Domain_YUV2RGB
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_YUV2RGB_REG_H_
#define _RBUS_YUV2RGB_REG_H_

#include "rbus_types.h"



//  YUV2RGB Register Address
#define  YUV2RGB_D_YUV2RGB_Control                                               0x1802AC00
#define  YUV2RGB_D_YUV2RGB_Control_reg_addr                                      "0xB802AC00"
#define  YUV2RGB_D_YUV2RGB_Control_reg                                           0xB802AC00
#define  YUV2RGB_D_YUV2RGB_Control_inst_addr                                     "0x0000"
#define  set_YUV2RGB_D_YUV2RGB_Control_reg(data)                                 (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Control_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Control_reg                                       (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Control_reg))
#define  YUV2RGB_D_YUV2RGB_Control_yuv2rgb_main_tab_sel_shift                    (4)
#define  YUV2RGB_D_YUV2RGB_Control_yuv2rgb_main_out_shift_shift                  (2)
#define  YUV2RGB_D_YUV2RGB_Control_yuv2rgb_main_en_shift                         (0)
#define  YUV2RGB_D_YUV2RGB_Control_yuv2rgb_main_tab_sel_mask                     (0x00000010)
#define  YUV2RGB_D_YUV2RGB_Control_yuv2rgb_main_out_shift_mask                   (0x00000004)
#define  YUV2RGB_D_YUV2RGB_Control_yuv2rgb_main_en_mask                          (0x00000001)
#define  YUV2RGB_D_YUV2RGB_Control_yuv2rgb_main_tab_sel(data)                    (0x00000010&((data)<<4))
#define  YUV2RGB_D_YUV2RGB_Control_yuv2rgb_main_out_shift(data)                  (0x00000004&((data)<<2))
#define  YUV2RGB_D_YUV2RGB_Control_yuv2rgb_main_en(data)                         (0x00000001&(data))
#define  YUV2RGB_D_YUV2RGB_Control_get_yuv2rgb_main_tab_sel(data)                ((0x00000010&(data))>>4)
#define  YUV2RGB_D_YUV2RGB_Control_get_yuv2rgb_main_out_shift(data)              ((0x00000004&(data))>>2)
#define  YUV2RGB_D_YUV2RGB_Control_get_yuv2rgb_main_en(data)                     (0x00000001&(data))

#define  YUV2RGB_D_YUV2RGB_Control_1                                             0x1802AC04
#define  YUV2RGB_D_YUV2RGB_Control_1_reg_addr                                    "0xB802AC04"
#define  YUV2RGB_D_YUV2RGB_Control_1_reg                                         0xB802AC04
#define  YUV2RGB_D_YUV2RGB_Control_1_inst_addr                                   "0x0001"
#define  set_YUV2RGB_D_YUV2RGB_Control_1_reg(data)                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Control_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Control_1_reg                                     (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Control_1_reg))
#define  YUV2RGB_D_YUV2RGB_Control_1_yuv2rgb_db_read_level_shift                 (2)
#define  YUV2RGB_D_YUV2RGB_Control_1_yuv2rgb_db_en_shift                         (1)
#define  YUV2RGB_D_YUV2RGB_Control_1_yuv2rgb_db_apply_shift                      (0)
#define  YUV2RGB_D_YUV2RGB_Control_1_yuv2rgb_db_read_level_mask                  (0x00000004)
#define  YUV2RGB_D_YUV2RGB_Control_1_yuv2rgb_db_en_mask                          (0x00000002)
#define  YUV2RGB_D_YUV2RGB_Control_1_yuv2rgb_db_apply_mask                       (0x00000001)
#define  YUV2RGB_D_YUV2RGB_Control_1_yuv2rgb_db_read_level(data)                 (0x00000004&((data)<<2))
#define  YUV2RGB_D_YUV2RGB_Control_1_yuv2rgb_db_en(data)                         (0x00000002&((data)<<1))
#define  YUV2RGB_D_YUV2RGB_Control_1_yuv2rgb_db_apply(data)                      (0x00000001&(data))
#define  YUV2RGB_D_YUV2RGB_Control_1_get_yuv2rgb_db_read_level(data)             ((0x00000004&(data))>>2)
#define  YUV2RGB_D_YUV2RGB_Control_1_get_yuv2rgb_db_en(data)                     ((0x00000002&(data))>>1)
#define  YUV2RGB_D_YUV2RGB_Control_1_get_yuv2rgb_db_apply(data)                  (0x00000001&(data))

#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp                                       0x1802AC08
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg_addr                              "0xB802AC08"
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg                                   0xB802AC08
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_inst_addr                             "0x0002"
#define  set_YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_reg))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_cb_cr_clamp_shift                     (1)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_y_clamp_shift                         (0)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_cb_cr_clamp_mask                      (0x00000002)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_y_clamp_mask                          (0x00000001)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_cb_cr_clamp(data)                     (0x00000002&((data)<<1))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_y_clamp(data)                         (0x00000001&(data))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_get_cb_cr_clamp(data)                 ((0x00000002&(data))>>1)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_Clamp_get_y_clamp(data)                     (0x00000001&(data))

#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0                                           0x1802AC0C
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg_addr                                  "0xB802AC0C"
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg                                       0xB802AC0C
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_inst_addr                                 "0x0003"
#define  set_YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg                                   (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_0_reg))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_k11_shift                                 (16)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_k12_shift                                 (0)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_k11_mask                                  (0x07FF0000)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_k12_mask                                  (0x000007FF)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_k11(data)                                 (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_k12(data)                                 (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_get_k11(data)                             ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_0_get_k12(data)                             (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGB_Tab1_Data_1                                           0x1802AC10
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg_addr                                  "0xB802AC10"
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg                                       0xB802AC10
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_1_inst_addr                                 "0x0004"
#define  set_YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg                                   (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_1_reg))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_1_k13_shift                                 (0)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_1_k13_mask                                  (0x000007FF)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_1_k13(data)                                 (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_1_get_k13(data)                             (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2                                           0x1802AC14
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg_addr                                  "0xB802AC14"
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg                                       0xB802AC14
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_inst_addr                                 "0x0005"
#define  set_YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg                                   (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_2_reg))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_k22_shift                                 (16)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_k23_shift                                 (0)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_k22_mask                                  (0x07FF0000)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_k23_mask                                  (0x000007FF)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_k22(data)                                 (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_k23(data)                                 (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_get_k22(data)                             ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_2_get_k23(data)                             (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3                                           0x1802AC18
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg_addr                                  "0xB802AC18"
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg                                       0xB802AC18
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_inst_addr                                 "0x0006"
#define  set_YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg                                   (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_3_reg))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_k32_shift                                 (16)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_k33_shift                                 (0)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_k32_mask                                  (0x07FF0000)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_k33_mask                                  (0x000007FF)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_k32(data)                                 (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_k33(data)                                 (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_get_k32(data)                             ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_3_get_k33(data)                             (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGB_Tab1_Data_4                                           0x1802AC1C
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg_addr                                  "0xB802AC1C"
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg                                       0xB802AC1C
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_4_inst_addr                                 "0x0007"
#define  set_YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg                                   (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_4_reg))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_4_roffset_shift                             (0)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_4_roffset_mask                              (0x0001FFFF)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_4_roffset(data)                             (0x0001FFFF&(data))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_4_get_roffset(data)                         (0x0001FFFF&(data))

#define  YUV2RGB_D_YUV2RGB_Tab1_Data_5                                           0x1802AC20
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg_addr                                  "0xB802AC20"
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg                                       0xB802AC20
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_5_inst_addr                                 "0x0008"
#define  set_YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg                                   (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_5_reg))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_5_goffset_shift                             (0)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_5_goffset_mask                              (0x0001FFFF)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_5_goffset(data)                             (0x0001FFFF&(data))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_5_get_goffset(data)                         (0x0001FFFF&(data))

#define  YUV2RGB_D_YUV2RGB_Tab1_Data_6                                           0x1802AC24
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg_addr                                  "0xB802AC24"
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg                                       0xB802AC24
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_6_inst_addr                                 "0x0009"
#define  set_YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg)=data)
#define  get_YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg                                   (*((volatile unsigned int*)YUV2RGB_D_YUV2RGB_Tab1_Data_6_reg))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_6_boffset_shift                             (0)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_6_boffset_mask                              (0x0001FFFF)
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_6_boffset(data)                             (0x0001FFFF&(data))
#define  YUV2RGB_D_YUV2RGB_Tab1_Data_6_get_boffset(data)                         (0x0001FFFF&(data))

#define  YUV2RGB_D_COEFBYY_NONLINEAR_0                                           0x1802AC38
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_reg_addr                                  "0xB802AC38"
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_reg                                       0xB802AC38
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_inst_addr                                 "0x000A"
#define  set_YUV2RGB_D_COEFBYY_NONLINEAR_0_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_COEFBYY_NONLINEAR_0_reg)=data)
#define  get_YUV2RGB_D_COEFBYY_NONLINEAR_0_reg                                   (*((volatile unsigned int*)YUV2RGB_D_COEFBYY_NONLINEAR_0_reg))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_4_shift                             (24)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_3_shift                             (16)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_2_shift                             (8)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_1_shift                             (0)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_4_mask                              (0xFF000000)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_3_mask                              (0x00FF0000)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_2_mask                              (0x0000FF00)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_1_mask                              (0x000000FF)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_4(data)                             (0xFF000000&((data)<<24))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_3(data)                             (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_2(data)                             (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_index_1(data)                             (0x000000FF&(data))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_get_index_4(data)                         ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_get_index_3(data)                         ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_get_index_2(data)                         ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_0_get_index_1(data)                         (0x000000FF&(data))

#define  YUV2RGB_D_COEFBYY_NONLINEAR_1                                           0x1802AC3C
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_reg_addr                                  "0xB802AC3C"
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_reg                                       0xB802AC3C
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_inst_addr                                 "0x000B"
#define  set_YUV2RGB_D_COEFBYY_NONLINEAR_1_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_COEFBYY_NONLINEAR_1_reg)=data)
#define  get_YUV2RGB_D_COEFBYY_NONLINEAR_1_reg                                   (*((volatile unsigned int*)YUV2RGB_D_COEFBYY_NONLINEAR_1_reg))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_8_shift                             (24)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_7_shift                             (16)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_6_shift                             (8)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_5_shift                             (0)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_8_mask                              (0xFF000000)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_7_mask                              (0x00FF0000)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_6_mask                              (0x0000FF00)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_5_mask                              (0x000000FF)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_8(data)                             (0xFF000000&((data)<<24))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_7(data)                             (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_6(data)                             (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_index_5(data)                             (0x000000FF&(data))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_get_index_8(data)                         ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_get_index_7(data)                         ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_get_index_6(data)                         ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_1_get_index_5(data)                         (0x000000FF&(data))

#define  YUV2RGB_D_COEFBYY_NONLINEAR_2                                           0x1802AC40
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_reg_addr                                  "0xB802AC40"
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_reg                                       0xB802AC40
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_inst_addr                                 "0x000C"
#define  set_YUV2RGB_D_COEFBYY_NONLINEAR_2_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_COEFBYY_NONLINEAR_2_reg)=data)
#define  get_YUV2RGB_D_COEFBYY_NONLINEAR_2_reg                                   (*((volatile unsigned int*)YUV2RGB_D_COEFBYY_NONLINEAR_2_reg))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_12_shift                            (24)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_11_shift                            (16)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_10_shift                            (8)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_9_shift                             (0)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_12_mask                             (0xFF000000)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_11_mask                             (0x00FF0000)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_10_mask                             (0x0000FF00)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_9_mask                              (0x000000FF)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_12(data)                            (0xFF000000&((data)<<24))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_11(data)                            (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_10(data)                            (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_index_9(data)                             (0x000000FF&(data))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_get_index_12(data)                        ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_get_index_11(data)                        ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_get_index_10(data)                        ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_2_get_index_9(data)                         (0x000000FF&(data))

#define  YUV2RGB_D_COEFBYY_NONLINEAR_3                                           0x1802AC44
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_reg_addr                                  "0xB802AC44"
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_reg                                       0xB802AC44
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_inst_addr                                 "0x000D"
#define  set_YUV2RGB_D_COEFBYY_NONLINEAR_3_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_COEFBYY_NONLINEAR_3_reg)=data)
#define  get_YUV2RGB_D_COEFBYY_NONLINEAR_3_reg                                   (*((volatile unsigned int*)YUV2RGB_D_COEFBYY_NONLINEAR_3_reg))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_16_shift                            (24)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_15_shift                            (16)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_14_shift                            (8)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_13_shift                            (0)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_16_mask                             (0xFF000000)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_15_mask                             (0x00FF0000)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_14_mask                             (0x0000FF00)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_13_mask                             (0x000000FF)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_16(data)                            (0xFF000000&((data)<<24))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_15(data)                            (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_14(data)                            (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_index_13(data)                            (0x000000FF&(data))
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_get_index_16(data)                        ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_get_index_15(data)                        ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_get_index_14(data)                        ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_COEFBYY_NONLINEAR_3_get_index_13(data)                        (0x000000FF&(data))

#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0                                         0x1802AC48
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_reg_addr                                "0xB802AC48"
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_reg                                     0xB802AC48
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_inst_addr                               "0x000E"
#define  set_YUV2RGB_D_OFFSETBYY_NONLINEAR_0_reg(data)                           (*((volatile unsigned int*)YUV2RGB_D_OFFSETBYY_NONLINEAR_0_reg)=data)
#define  get_YUV2RGB_D_OFFSETBYY_NONLINEAR_0_reg                                 (*((volatile unsigned int*)YUV2RGB_D_OFFSETBYY_NONLINEAR_0_reg))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_4_shift                           (24)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_3_shift                           (16)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_2_shift                           (8)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_1_shift                           (0)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_4_mask                            (0xFF000000)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_3_mask                            (0x00FF0000)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_2_mask                            (0x0000FF00)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_1_mask                            (0x000000FF)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_4(data)                           (0xFF000000&((data)<<24))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_3(data)                           (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_2(data)                           (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_index_1(data)                           (0x000000FF&(data))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_get_index_4(data)                       ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_get_index_3(data)                       ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_get_index_2(data)                       ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_0_get_index_1(data)                       (0x000000FF&(data))

#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1                                         0x1802AC4C
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_reg_addr                                "0xB802AC4C"
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_reg                                     0xB802AC4C
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_inst_addr                               "0x000F"
#define  set_YUV2RGB_D_OFFSETBYY_NONLINEAR_1_reg(data)                           (*((volatile unsigned int*)YUV2RGB_D_OFFSETBYY_NONLINEAR_1_reg)=data)
#define  get_YUV2RGB_D_OFFSETBYY_NONLINEAR_1_reg                                 (*((volatile unsigned int*)YUV2RGB_D_OFFSETBYY_NONLINEAR_1_reg))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_8_shift                           (24)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_7_shift                           (16)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_6_shift                           (8)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_5_shift                           (0)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_8_mask                            (0xFF000000)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_7_mask                            (0x00FF0000)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_6_mask                            (0x0000FF00)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_5_mask                            (0x000000FF)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_8(data)                           (0xFF000000&((data)<<24))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_7(data)                           (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_6(data)                           (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_index_5(data)                           (0x000000FF&(data))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_get_index_8(data)                       ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_get_index_7(data)                       ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_get_index_6(data)                       ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_1_get_index_5(data)                       (0x000000FF&(data))

#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2                                         0x1802AC50
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_reg_addr                                "0xB802AC50"
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_reg                                     0xB802AC50
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_inst_addr                               "0x0010"
#define  set_YUV2RGB_D_OFFSETBYY_NONLINEAR_2_reg(data)                           (*((volatile unsigned int*)YUV2RGB_D_OFFSETBYY_NONLINEAR_2_reg)=data)
#define  get_YUV2RGB_D_OFFSETBYY_NONLINEAR_2_reg                                 (*((volatile unsigned int*)YUV2RGB_D_OFFSETBYY_NONLINEAR_2_reg))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_12_shift                          (24)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_11_shift                          (16)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_10_shift                          (8)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_9_shift                           (0)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_12_mask                           (0xFF000000)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_11_mask                           (0x00FF0000)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_10_mask                           (0x0000FF00)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_9_mask                            (0x000000FF)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_12(data)                          (0xFF000000&((data)<<24))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_11(data)                          (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_10(data)                          (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_index_9(data)                           (0x000000FF&(data))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_get_index_12(data)                      ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_get_index_11(data)                      ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_get_index_10(data)                      ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_2_get_index_9(data)                       (0x000000FF&(data))

#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3                                         0x1802AC54
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_reg_addr                                "0xB802AC54"
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_reg                                     0xB802AC54
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_inst_addr                               "0x0011"
#define  set_YUV2RGB_D_OFFSETBYY_NONLINEAR_3_reg(data)                           (*((volatile unsigned int*)YUV2RGB_D_OFFSETBYY_NONLINEAR_3_reg)=data)
#define  get_YUV2RGB_D_OFFSETBYY_NONLINEAR_3_reg                                 (*((volatile unsigned int*)YUV2RGB_D_OFFSETBYY_NONLINEAR_3_reg))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_16_shift                          (24)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_15_shift                          (16)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_14_shift                          (8)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_13_shift                          (0)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_16_mask                           (0xFF000000)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_15_mask                           (0x00FF0000)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_14_mask                           (0x0000FF00)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_13_mask                           (0x000000FF)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_16(data)                          (0xFF000000&((data)<<24))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_15(data)                          (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_14(data)                          (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_index_13(data)                          (0x000000FF&(data))
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_get_index_16(data)                      ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_get_index_15(data)                      ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_get_index_14(data)                      ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_OFFSETBYY_NONLINEAR_3_get_index_13(data)                      (0x000000FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_CONTROL                                            0x1802AC58
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_reg_addr                                   "0xB802AC58"
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_reg                                        0xB802AC58
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_inst_addr                                  "0x0012"
#define  set_YUV2RGB_D_YUV2RGBBYY_CONTROL_reg(data)                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_CONTROL_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_CONTROL_reg                                    (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_CONTROL_reg))
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_yuv2rgb_coef_by_sat_gain_shift             (8)
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_yuv2rgb_coef_by_sat_mode_shift             (2)
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_yuv2rgbbymode_main_en_shift                (0)
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_yuv2rgb_coef_by_sat_gain_mask              (0x0000FF00)
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_yuv2rgb_coef_by_sat_mode_mask              (0x00000004)
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_yuv2rgbbymode_main_en_mask                 (0x00000003)
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_yuv2rgb_coef_by_sat_gain(data)             (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_yuv2rgb_coef_by_sat_mode(data)             (0x00000004&((data)<<2))
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_yuv2rgbbymode_main_en(data)                (0x00000003&(data))
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_get_yuv2rgb_coef_by_sat_gain(data)         ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_get_yuv2rgb_coef_by_sat_mode(data)         ((0x00000004&(data))>>2)
#define  YUV2RGB_D_YUV2RGBBYY_CONTROL_get_yuv2rgbbymode_main_en(data)            (0x00000003&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0                                       0x1802AC5C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg_addr                              "0xB802AC5C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg                                   0xB802AC5C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_inst_addr                             "0x0013"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_k11_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_k12_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_k11_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_k12_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_k11(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_k12(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_get_k11(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_0_get_k12(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1                                       0x1802AC60
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_reg_addr                              "0xB802AC60"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_reg                                   0xB802AC60
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_inst_addr                             "0x0014"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_k13_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_k13_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_k13(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_1_get_k13(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2                                       0x1802AC64
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_reg_addr                              "0xB802AC64"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_reg                                   0xB802AC64
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_inst_addr                             "0x0015"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_k22_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_k23_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_k22_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_k23_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_k22(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_k23(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_get_k22(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_2_get_k23(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3                                       0x1802AC68
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_reg_addr                              "0xB802AC68"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_reg                                   0xB802AC68
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_inst_addr                             "0x0016"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_k32_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_k33_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_k32_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_k33_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_k32(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_k33(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_get_k32(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_1_3_get_k33(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0                                       0x1802AC6C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_reg_addr                              "0xB802AC6C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_reg                                   0xB802AC6C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_inst_addr                             "0x0017"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_k11_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_k12_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_k11_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_k12_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_k11(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_k12(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_get_k11(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_0_get_k12(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1                                       0x1802AC70
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_reg_addr                              "0xB802AC70"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_reg                                   0xB802AC70
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_inst_addr                             "0x0018"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_k13_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_k13_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_k13(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_1_get_k13(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2                                       0x1802AC74
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_reg_addr                              "0xB802AC74"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_reg                                   0xB802AC74
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_inst_addr                             "0x0019"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_k22_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_k23_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_k22_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_k23_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_k22(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_k23(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_get_k22(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_2_get_k23(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3                                       0x1802AC78
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_reg_addr                              "0xB802AC78"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_reg                                   0xB802AC78
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_inst_addr                             "0x001A"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_k32_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_k33_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_k32_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_k33_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_k32(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_k33(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_get_k32(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_2_3_get_k33(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0                                       0x1802AC7C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_reg_addr                              "0xB802AC7C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_reg                                   0xB802AC7C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_inst_addr                             "0x001B"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_k11_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_k12_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_k11_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_k12_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_k11(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_k12(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_get_k11(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_0_get_k12(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1                                       0x1802AC80
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_reg_addr                              "0xB802AC80"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_reg                                   0xB802AC80
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_inst_addr                             "0x001C"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_k13_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_k13_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_k13(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_1_get_k13(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2                                       0x1802AC84
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_reg_addr                              "0xB802AC84"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_reg                                   0xB802AC84
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_inst_addr                             "0x001D"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_k22_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_k23_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_k22_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_k23_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_k22(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_k23(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_get_k22(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_2_get_k23(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3                                       0x1802AC88
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_reg_addr                              "0xB802AC88"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_reg                                   0xB802AC88
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_inst_addr                             "0x001E"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_k32_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_k33_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_k32_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_k33_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_k32(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_k33(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_get_k32(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_3_3_get_k33(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0                                       0x1802AC8C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_reg_addr                              "0xB802AC8C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_reg                                   0xB802AC8C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_inst_addr                             "0x001F"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_k11_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_k12_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_k11_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_k12_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_k11(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_k12(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_get_k11(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_0_get_k12(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1                                       0x1802AC90
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_reg_addr                              "0xB802AC90"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_reg                                   0xB802AC90
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_inst_addr                             "0x0020"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_k13_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_k13_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_k13(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_1_get_k13(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2                                       0x1802AC94
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_reg_addr                              "0xB802AC94"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_reg                                   0xB802AC94
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_inst_addr                             "0x0021"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_k22_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_k23_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_k22_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_k23_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_k22(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_k23(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_get_k22(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_2_get_k23(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3                                       0x1802AC9C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_reg_addr                              "0xB802AC9C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_reg                                   0xB802AC9C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_inst_addr                             "0x0022"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_k32_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_k33_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_k32_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_k33_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_k32(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_k33(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_get_k32(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_4_3_get_k33(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0                                       0x1802ACA0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg_addr                              "0xB802ACA0"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg                                   0xB802ACA0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_inst_addr                             "0x0023"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_k11_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_k12_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_k11_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_k12_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_k11(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_k12(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_get_k11(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_0_get_k12(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1                                       0x1802ACA4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_reg_addr                              "0xB802ACA4"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_reg                                   0xB802ACA4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_inst_addr                             "0x0024"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_k13_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_k13_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_k13(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_1_get_k13(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2                                       0x1802ACA8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_reg_addr                              "0xB802ACA8"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_reg                                   0xB802ACA8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_inst_addr                             "0x0025"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_k22_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_k23_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_k22_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_k23_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_k22(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_k23(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_get_k22(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_2_get_k23(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3                                       0x1802ACAC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_reg_addr                              "0xB802ACAC"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_reg                                   0xB802ACAC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_inst_addr                             "0x0026"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_k32_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_k33_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_k32_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_k33_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_k32(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_k33(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_get_k32(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_5_3_get_k33(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0                                       0x1802ACB0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_reg_addr                              "0xB802ACB0"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_reg                                   0xB802ACB0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_inst_addr                             "0x0027"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_k11_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_k12_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_k11_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_k12_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_k11(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_k12(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_get_k11(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_0_get_k12(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1                                       0x1802ACB4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_reg_addr                              "0xB802ACB4"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_reg                                   0xB802ACB4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_inst_addr                             "0x0028"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_k13_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_k13_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_k13(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_1_get_k13(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2                                       0x1802ACB8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_reg_addr                              "0xB802ACB8"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_reg                                   0xB802ACB8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_inst_addr                             "0x0029"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_k22_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_k23_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_k22_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_k23_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_k22(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_k23(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_get_k22(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_2_get_k23(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3                                       0x1802ACBC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_reg_addr                              "0xB802ACBC"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_reg                                   0xB802ACBC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_inst_addr                             "0x002A"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_k32_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_k33_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_k32_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_k33_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_k32(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_k33(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_get_k32(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_6_3_get_k33(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0                                       0x1802ACC0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_reg_addr                              "0xB802ACC0"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_reg                                   0xB802ACC0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_inst_addr                             "0x002B"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_k11_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_k12_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_k11_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_k12_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_k11(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_k12(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_get_k11(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_0_get_k12(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1                                       0x1802ACC4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_reg_addr                              "0xB802ACC4"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_reg                                   0xB802ACC4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_inst_addr                             "0x002C"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_k13_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_k13_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_k13(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_1_get_k13(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2                                       0x1802ACC8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_reg_addr                              "0xB802ACC8"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_reg                                   0xB802ACC8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_inst_addr                             "0x002D"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_k22_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_k23_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_k22_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_k23_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_k22(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_k23(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_get_k22(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_2_get_k23(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3                                       0x1802ACCC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_reg_addr                              "0xB802ACCC"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_reg                                   0xB802ACCC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_inst_addr                             "0x002E"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_k32_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_k33_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_k32_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_k33_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_k32(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_k33(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_get_k32(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_7_3_get_k33(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0                                       0x1802ACD0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_reg_addr                              "0xB802ACD0"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_reg                                   0xB802ACD0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_inst_addr                             "0x002F"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_k11_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_k12_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_k11_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_k12_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_k11(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_k12(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_get_k11(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_0_get_k12(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1                                       0x1802ACD4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_reg_addr                              "0xB802ACD4"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_reg                                   0xB802ACD4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_inst_addr                             "0x0030"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_k13_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_k13_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_k13(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_1_get_k13(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2                                       0x1802ACD8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_reg_addr                              "0xB802ACD8"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_reg                                   0xB802ACD8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_inst_addr                             "0x0031"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_k22_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_k23_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_k22_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_k23_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_k22(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_k23(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_get_k22(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_2_get_k23(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3                                       0x1802ACDC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_reg_addr                              "0xB802ACDC"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_reg                                   0xB802ACDC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_inst_addr                             "0x0032"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_k32_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_k33_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_k32_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_k33_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_k32(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_k33(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_get_k32(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_8_3_get_k33(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0                                       0x1802ACE0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_reg_addr                              "0xB802ACE0"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_reg                                   0xB802ACE0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_inst_addr                             "0x0033"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_k11_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_k12_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_k11_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_k12_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_k11(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_k12(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_get_k11(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_0_get_k12(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1                                       0x1802ACE4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_reg_addr                              "0xB802ACE4"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_reg                                   0xB802ACE4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_inst_addr                             "0x0034"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_k13_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_k13_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_k13(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_1_get_k13(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2                                       0x1802ACE8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_reg_addr                              "0xB802ACE8"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_reg                                   0xB802ACE8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_inst_addr                             "0x0035"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_k22_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_k23_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_k22_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_k23_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_k22(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_k23(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_get_k22(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_2_get_k23(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3                                       0x1802ACEC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_reg_addr                              "0xB802ACEC"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_reg                                   0xB802ACEC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_inst_addr                             "0x0036"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_reg(data)                         (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_reg                               (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_k32_shift                             (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_k33_shift                             (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_k32_mask                              (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_k33_mask                              (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_k32(data)                             (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_k33(data)                             (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_get_k32(data)                         ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_9_3_get_k33(data)                         (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0                                      0x1802ACF0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_reg_addr                             "0xB802ACF0"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_reg                                  0xB802ACF0
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_inst_addr                            "0x0037"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_k11_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_k12_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_k11_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_k12_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_k11(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_k12(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_get_k11(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_0_get_k12(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1                                      0x1802ACF4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_reg_addr                             "0xB802ACF4"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_reg                                  0xB802ACF4
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_inst_addr                            "0x0038"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_k13_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_k13_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_k13(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_1_get_k13(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2                                      0x1802ACF8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_reg_addr                             "0xB802ACF8"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_reg                                  0xB802ACF8
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_inst_addr                            "0x0039"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_k22_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_k23_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_k22_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_k23_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_k22(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_k23(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_get_k22(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_2_get_k23(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3                                      0x1802ACFC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_reg_addr                             "0xB802ACFC"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_reg                                  0xB802ACFC
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_inst_addr                            "0x003A"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_k32_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_k33_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_k32_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_k33_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_k32(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_k33(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_get_k32(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_10_3_get_k33(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0                                      0x1802AD00
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_reg_addr                             "0xB802AD00"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_reg                                  0xB802AD00
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_inst_addr                            "0x003B"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_k11_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_k12_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_k11_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_k12_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_k11(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_k12(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_get_k11(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_0_get_k12(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1                                      0x1802AD04
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_reg_addr                             "0xB802AD04"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_reg                                  0xB802AD04
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_inst_addr                            "0x003C"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_k13_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_k13_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_k13(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_1_get_k13(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2                                      0x1802AD08
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_reg_addr                             "0xB802AD08"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_reg                                  0xB802AD08
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_inst_addr                            "0x003D"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_k22_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_k23_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_k22_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_k23_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_k22(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_k23(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_get_k22(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_2_get_k23(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3                                      0x1802AD0C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_reg_addr                             "0xB802AD0C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_reg                                  0xB802AD0C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_inst_addr                            "0x003E"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_k32_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_k33_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_k32_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_k33_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_k32(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_k33(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_get_k32(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_11_3_get_k33(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0                                      0x1802AD10
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_reg_addr                             "0xB802AD10"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_reg                                  0xB802AD10
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_inst_addr                            "0x003F"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_k11_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_k12_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_k11_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_k12_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_k11(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_k12(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_get_k11(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_0_get_k12(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1                                      0x1802AD14
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_reg_addr                             "0xB802AD14"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_reg                                  0xB802AD14
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_inst_addr                            "0x0040"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_k13_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_k13_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_k13(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_1_get_k13(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2                                      0x1802AD18
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_reg_addr                             "0xB802AD18"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_reg                                  0xB802AD18
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_inst_addr                            "0x0041"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_k22_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_k23_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_k22_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_k23_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_k22(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_k23(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_get_k22(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_2_get_k23(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3                                      0x1802AD1C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_reg_addr                             "0xB802AD1C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_reg                                  0xB802AD1C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_inst_addr                            "0x0042"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_k32_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_k33_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_k32_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_k33_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_k32(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_k33(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_get_k32(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_12_3_get_k33(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0                                      0x1802AD20
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_reg_addr                             "0xB802AD20"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_reg                                  0xB802AD20
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_inst_addr                            "0x0043"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_k11_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_k12_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_k11_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_k12_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_k11(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_k12(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_get_k11(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_0_get_k12(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1                                      0x1802AD24
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_reg_addr                             "0xB802AD24"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_reg                                  0xB802AD24
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_inst_addr                            "0x0044"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_k13_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_k13_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_k13(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_1_get_k13(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2                                      0x1802AD28
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_reg_addr                             "0xB802AD28"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_reg                                  0xB802AD28
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_inst_addr                            "0x0045"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_k22_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_k23_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_k22_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_k23_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_k22(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_k23(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_get_k22(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_2_get_k23(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3                                      0x1802AD2C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_reg_addr                             "0xB802AD2C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_reg                                  0xB802AD2C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_inst_addr                            "0x0046"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_k32_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_k33_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_k32_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_k33_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_k32(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_k33(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_get_k32(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_13_3_get_k33(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0                                      0x1802AD30
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_reg_addr                             "0xB802AD30"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_reg                                  0xB802AD30
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_inst_addr                            "0x0047"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_k11_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_k12_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_k11_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_k12_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_k11(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_k12(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_get_k11(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_0_get_k12(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1                                      0x1802AD34
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_reg_addr                             "0xB802AD34"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_reg                                  0xB802AD34
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_inst_addr                            "0x0048"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_k13_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_k13_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_k13(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_1_get_k13(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2                                      0x1802AD38
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_reg_addr                             "0xB802AD38"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_reg                                  0xB802AD38
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_inst_addr                            "0x0049"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_k22_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_k23_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_k22_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_k23_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_k22(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_k23(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_get_k22(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_2_get_k23(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3                                      0x1802AD3C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_reg_addr                             "0xB802AD3C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_reg                                  0xB802AD3C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_inst_addr                            "0x004A"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_k32_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_k33_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_k32_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_k33_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_k32(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_k33(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_get_k32(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_14_3_get_k33(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0                                      0x1802AD40
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_reg_addr                             "0xB802AD40"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_reg                                  0xB802AD40
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_inst_addr                            "0x004B"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_k11_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_k12_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_k11_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_k12_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_k11(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_k12(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_get_k11(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_0_get_k12(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1                                      0x1802AD44
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_reg_addr                             "0xB802AD44"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_reg                                  0xB802AD44
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_inst_addr                            "0x004C"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_k13_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_k13_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_k13(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_1_get_k13(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2                                      0x1802AD48
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_reg_addr                             "0xB802AD48"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_reg                                  0xB802AD48
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_inst_addr                            "0x004D"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_k22_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_k23_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_k22_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_k23_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_k22(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_k23(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_get_k22(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_2_get_k23(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3                                      0x1802AD4C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_reg_addr                             "0xB802AD4C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_reg                                  0xB802AD4C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_inst_addr                            "0x004E"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_k32_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_k33_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_k32_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_k33_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_k32(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_k33(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_get_k32(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_15_3_get_k33(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0                                      0x1802AD50
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_reg_addr                             "0xB802AD50"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_reg                                  0xB802AD50
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_inst_addr                            "0x004F"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_k11_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_k12_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_k11_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_k12_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_k11(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_k12(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_get_k11(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_0_get_k12(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1                                      0x1802AD54
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_reg_addr                             "0xB802AD54"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_reg                                  0xB802AD54
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_inst_addr                            "0x0050"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_k13_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_k13_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_k13(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_1_get_k13(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2                                      0x1802AD58
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_reg_addr                             "0xB802AD58"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_reg                                  0xB802AD58
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_inst_addr                            "0x0051"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_k22_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_k23_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_k22_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_k23_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_k22(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_k23(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_get_k22(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_2_get_k23(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3                                      0x1802AD5C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_reg_addr                             "0xB802AD5C"
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_reg                                  0xB802AD5C
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_inst_addr                            "0x0052"
#define  set_YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_reg)=data)
#define  get_YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_reg))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_k32_shift                            (16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_k33_shift                            (0)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_k32_mask                             (0x07FF0000)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_k33_mask                             (0x000007FF)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_k32(data)                            (0x07FF0000&((data)<<16))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_k33(data)                            (0x000007FF&(data))
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_get_k32(data)                        ((0x07FF0000&(data))>>16)
#define  YUV2RGB_D_YUV2RGBBYY_Tab_Data_16_3_get_k33(data)                        (0x000007FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_CONTROL                                           0x1802AD60
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_reg_addr                                  "0xB802AD60"
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_reg                                       0xB802AD60
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_inst_addr                                 "0x0053"
#define  set_YUV2RGB_D_UVOFFSETBYY_CONTROL_reg(data)                             (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_CONTROL_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_CONTROL_reg                                   (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_CONTROL_reg))
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_uvoffsetbyy_mode_shift                    (1)
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_uvoffsetbyy_main_en_shift                 (0)
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_uvoffsetbyy_mode_mask                     (0x00000006)
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_uvoffsetbyy_main_en_mask                  (0x00000001)
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_uvoffsetbyy_mode(data)                    (0x00000006&((data)<<1))
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_uvoffsetbyy_main_en(data)                 (0x00000001&(data))
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_get_uvoffsetbyy_mode(data)                ((0x00000006&(data))>>1)
#define  YUV2RGB_D_UVOFFSETBYY_CONTROL_get_uvoffsetbyy_main_en(data)             (0x00000001&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1                                      0x1802AD64
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_reg_addr                             "0xB802AD64"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_reg                                  0xB802AD64
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_inst_addr                            "0x0054"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m3_shift                     (24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m2_shift                     (16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m1_shift                     (8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m0_shift                     (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m3_mask                      (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m2_mask                      (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m1_mask                      (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m0_mask                      (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m3(data)                     (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m2(data)                     (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m1(data)                     (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_uoffset_m0(data)                     (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_get_uoffset_m3(data)                 ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_get_uoffset_m2(data)                 ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_get_uoffset_m1(data)                 ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_1_get_uoffset_m0(data)                 (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2                                      0x1802AD68
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_reg_addr                             "0xB802AD68"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_reg                                  0xB802AD68
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_inst_addr                            "0x0055"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m7_shift                     (24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m6_shift                     (16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m5_shift                     (8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m4_shift                     (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m7_mask                      (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m6_mask                      (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m5_mask                      (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m4_mask                      (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m7(data)                     (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m6(data)                     (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m5(data)                     (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_uoffset_m4(data)                     (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_get_uoffset_m7(data)                 ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_get_uoffset_m6(data)                 ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_get_uoffset_m5(data)                 ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_2_get_uoffset_m4(data)                 (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3                                      0x1802AD6C
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_reg_addr                             "0xB802AD6C"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_reg                                  0xB802AD6C
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_inst_addr                            "0x0056"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m11_shift                    (24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m10_shift                    (16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m9_shift                     (8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m8_shift                     (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m11_mask                     (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m10_mask                     (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m9_mask                      (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m8_mask                      (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m11(data)                    (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m10(data)                    (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m9(data)                     (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_uoffset_m8(data)                     (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_get_uoffset_m11(data)                ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_get_uoffset_m10(data)                ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_get_uoffset_m9(data)                 ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_3_get_uoffset_m8(data)                 (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4                                      0x1802AD70
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_reg_addr                             "0xB802AD70"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_reg                                  0xB802AD70
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_inst_addr                            "0x0057"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m15_shift                    (24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m14_shift                    (16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m13_shift                    (8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m12_shift                    (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m15_mask                     (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m14_mask                     (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m13_mask                     (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m12_mask                     (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m15(data)                    (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m14(data)                    (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m13(data)                    (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_uoffset_m12(data)                    (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_get_uoffset_m15(data)                ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_get_uoffset_m14(data)                ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_get_uoffset_m13(data)                ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_4_get_uoffset_m12(data)                (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5                                      0x1802AD74
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_reg_addr                             "0xB802AD74"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_reg                                  0xB802AD74
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_inst_addr                            "0x0058"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_uoffset_m16_shift                    (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_uoffset_m16_mask                     (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_uoffset_m16(data)                    (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Data_5_get_uoffset_m16(data)                (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1                                      0x1802AD78
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_reg_addr                             "0xB802AD78"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_reg                                  0xB802AD78
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_inst_addr                            "0x0059"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m3_shift                     (24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m2_shift                     (16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m1_shift                     (8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m0_shift                     (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m3_mask                      (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m2_mask                      (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m1_mask                      (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m0_mask                      (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m3(data)                     (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m2(data)                     (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m1(data)                     (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_voffset_m0(data)                     (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_get_voffset_m3(data)                 ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_get_voffset_m2(data)                 ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_get_voffset_m1(data)                 ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_1_get_voffset_m0(data)                 (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2                                      0x1802AD7C
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_reg_addr                             "0xB802AD7C"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_reg                                  0xB802AD7C
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_inst_addr                            "0x005A"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m7_shift                     (24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m6_shift                     (16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m5_shift                     (8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m4_shift                     (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m7_mask                      (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m6_mask                      (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m5_mask                      (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m4_mask                      (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m7(data)                     (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m6(data)                     (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m5(data)                     (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_voffset_m4(data)                     (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_get_voffset_m7(data)                 ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_get_voffset_m6(data)                 ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_get_voffset_m5(data)                 ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_2_get_voffset_m4(data)                 (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3                                      0x1802AD80
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_reg_addr                             "0xB802AD80"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_reg                                  0xB802AD80
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_inst_addr                            "0x005B"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m11_shift                    (24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m10_shift                    (16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m9_shift                     (8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m8_shift                     (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m11_mask                     (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m10_mask                     (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m9_mask                      (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m8_mask                      (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m11(data)                    (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m10(data)                    (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m9(data)                     (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_voffset_m8(data)                     (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_get_voffset_m11(data)                ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_get_voffset_m10(data)                ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_get_voffset_m9(data)                 ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_3_get_voffset_m8(data)                 (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4                                      0x1802AD84
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_reg_addr                             "0xB802AD84"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_reg                                  0xB802AD84
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_inst_addr                            "0x005C"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m15_shift                    (24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m14_shift                    (16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m13_shift                    (8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m12_shift                    (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m15_mask                     (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m14_mask                     (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m13_mask                     (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m12_mask                     (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m15(data)                    (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m14(data)                    (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m13(data)                    (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_voffset_m12(data)                    (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_get_voffset_m15(data)                ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_get_voffset_m14(data)                ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_get_voffset_m13(data)                ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_4_get_voffset_m12(data)                (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5                                      0x1802AD88
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_reg_addr                             "0xB802AD88"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_reg                                  0xB802AD88
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_inst_addr                            "0x005D"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_voffset_m16_shift                    (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_voffset_m16_mask                     (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_voffset_m16(data)                    (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Data_5_get_voffset_m16(data)                (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1                                      0x1802AD8C
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_reg_addr                             "0xB802AD8C"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_reg                                  0xB802AD8C
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_inst_addr                            "0x005E"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m3_shift                       (24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m2_shift                       (16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m1_shift                       (8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m0_shift                       (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m3_mask                        (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m2_mask                        (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m1_mask                        (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m0_mask                        (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m3(data)                       (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m2(data)                       (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m1(data)                       (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_ustep_m0(data)                       (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_get_ustep_m3(data)                   ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_get_ustep_m2(data)                   ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_get_ustep_m1(data)                   ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_1_get_ustep_m0(data)                   (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2                                      0x1802AD90
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_reg_addr                             "0xB802AD90"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_reg                                  0xB802AD90
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_inst_addr                            "0x005F"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m7_shift                       (24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m6_shift                       (16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m5_shift                       (8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m4_shift                       (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m7_mask                        (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m6_mask                        (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m5_mask                        (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m4_mask                        (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m7(data)                       (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m6(data)                       (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m5(data)                       (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_ustep_m4(data)                       (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_get_ustep_m7(data)                   ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_get_ustep_m6(data)                   ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_get_ustep_m5(data)                   ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_2_get_ustep_m4(data)                   (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3                                      0x1802AD94
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_reg_addr                             "0xB802AD94"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_reg                                  0xB802AD94
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_inst_addr                            "0x0060"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m11_shift                      (24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m10_shift                      (16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m9_shift                       (8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m8_shift                       (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m11_mask                       (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m10_mask                       (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m9_mask                        (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m8_mask                        (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m11(data)                      (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m10(data)                      (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m9(data)                       (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_ustep_m8(data)                       (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_get_ustep_m11(data)                  ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_get_ustep_m10(data)                  ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_get_ustep_m9(data)                   ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_3_get_ustep_m8(data)                   (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4                                      0x1802AD98
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_reg_addr                             "0xB802AD98"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_reg                                  0xB802AD98
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_inst_addr                            "0x0061"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m15_shift                      (24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m14_shift                      (16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m13_shift                      (8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m12_shift                      (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m15_mask                       (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m14_mask                       (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m13_mask                       (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m12_mask                       (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m15(data)                      (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m14(data)                      (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m13(data)                      (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_ustep_m12(data)                      (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_get_ustep_m15(data)                  ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_get_ustep_m14(data)                  ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_get_ustep_m13(data)                  ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_4_get_ustep_m12(data)                  (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5                                      0x1802AD9C
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_reg_addr                             "0xB802AD9C"
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_reg                                  0xB802AD9C
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_inst_addr                            "0x0062"
#define  set_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_reg))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_ustep_m16_shift                      (0)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_ustep_m16_mask                       (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_ustep_m16(data)                      (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_U_Tab_Step_5_get_ustep_m16(data)                  (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1                                      0x1802ADA0
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_reg_addr                             "0xB802ADA0"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_reg                                  0xB802ADA0
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_inst_addr                            "0x0063"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m3_shift                       (24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m2_shift                       (16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m1_shift                       (8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m0_shift                       (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m3_mask                        (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m2_mask                        (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m1_mask                        (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m0_mask                        (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m3(data)                       (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m2(data)                       (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m1(data)                       (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_vstep_m0(data)                       (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_get_vstep_m3(data)                   ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_get_vstep_m2(data)                   ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_get_vstep_m1(data)                   ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_1_get_vstep_m0(data)                   (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2                                      0x1802ADA4
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_reg_addr                             "0xB802ADA4"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_reg                                  0xB802ADA4
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_inst_addr                            "0x0064"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m7_shift                       (24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m6_shift                       (16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m5_shift                       (8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m4_shift                       (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m7_mask                        (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m6_mask                        (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m5_mask                        (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m4_mask                        (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m7(data)                       (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m6(data)                       (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m5(data)                       (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_vstep_m4(data)                       (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_get_vstep_m7(data)                   ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_get_vstep_m6(data)                   ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_get_vstep_m5(data)                   ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_2_get_vstep_m4(data)                   (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3                                      0x1802ADA8
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_reg_addr                             "0xB802ADA8"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_reg                                  0xB802ADA8
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_inst_addr                            "0x0065"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m11_shift                      (24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m10_shift                      (16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m9_shift                       (8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m8_shift                       (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m11_mask                       (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m10_mask                       (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m9_mask                        (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m8_mask                        (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m11(data)                      (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m10(data)                      (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m9(data)                       (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_vstep_m8(data)                       (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_get_vstep_m11(data)                  ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_get_vstep_m10(data)                  ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_get_vstep_m9(data)                   ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_3_get_vstep_m8(data)                   (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4                                      0x1802ADAC
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_reg_addr                             "0xB802ADAC"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_reg                                  0xB802ADAC
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_inst_addr                            "0x0066"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m15_shift                      (24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m14_shift                      (16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m13_shift                      (8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m12_shift                      (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m15_mask                       (0xFF000000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m14_mask                       (0x00FF0000)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m13_mask                       (0x0000FF00)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m12_mask                       (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m15(data)                      (0xFF000000&((data)<<24))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m14(data)                      (0x00FF0000&((data)<<16))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m13(data)                      (0x0000FF00&((data)<<8))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_vstep_m12(data)                      (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_get_vstep_m15(data)                  ((0xFF000000&(data))>>24)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_get_vstep_m14(data)                  ((0x00FF0000&(data))>>16)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_get_vstep_m13(data)                  ((0x0000FF00&(data))>>8)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_4_get_vstep_m12(data)                  (0x000000FF&(data))

#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5                                      0x1802ADB0
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_reg_addr                             "0xB802ADB0"
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_reg                                  0xB802ADB0
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_inst_addr                            "0x0067"
#define  set_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_reg(data)                        (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_reg)=data)
#define  get_YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_reg                              (*((volatile unsigned int*)YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_reg))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_vstep_m16_shift                      (0)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_vstep_m16_mask                       (0x000000FF)
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_vstep_m16(data)                      (0x000000FF&(data))
#define  YUV2RGB_D_UVOFFSETBYY_V_Tab_Step_5_get_vstep_m16(data)                  (0x000000FF&(data))

#define  YUV2RGB_AccessData_CTRL                                                 0x1802ADC0
#define  YUV2RGB_AccessData_CTRL_reg_addr                                        "0xB802ADC0"
#define  YUV2RGB_AccessData_CTRL_reg                                             0xB802ADC0
#define  YUV2RGB_AccessData_CTRL_inst_addr                                       "0x0068"
#define  set_YUV2RGB_AccessData_CTRL_reg(data)                                   (*((volatile unsigned int*)YUV2RGB_AccessData_CTRL_reg)=data)
#define  get_YUV2RGB_AccessData_CTRL_reg                                         (*((volatile unsigned int*)YUV2RGB_AccessData_CTRL_reg))
#define  YUV2RGB_AccessData_CTRL_write_en_shift                                  (1)
#define  YUV2RGB_AccessData_CTRL_read_en_shift                                   (0)
#define  YUV2RGB_AccessData_CTRL_write_en_mask                                   (0x00000002)
#define  YUV2RGB_AccessData_CTRL_read_en_mask                                    (0x00000001)
#define  YUV2RGB_AccessData_CTRL_write_en(data)                                  (0x00000002&((data)<<1))
#define  YUV2RGB_AccessData_CTRL_read_en(data)                                   (0x00000001&(data))
#define  YUV2RGB_AccessData_CTRL_get_write_en(data)                              ((0x00000002&(data))>>1)
#define  YUV2RGB_AccessData_CTRL_get_read_en(data)                               (0x00000001&(data))

#define  YUV2RGB_AccessData_PosCtrl                                              0x1802ADC4
#define  YUV2RGB_AccessData_PosCtrl_reg_addr                                     "0xB802ADC4"
#define  YUV2RGB_AccessData_PosCtrl_reg                                          0xB802ADC4
#define  YUV2RGB_AccessData_PosCtrl_inst_addr                                    "0x0069"
#define  set_YUV2RGB_AccessData_PosCtrl_reg(data)                                (*((volatile unsigned int*)YUV2RGB_AccessData_PosCtrl_reg)=data)
#define  get_YUV2RGB_AccessData_PosCtrl_reg                                      (*((volatile unsigned int*)YUV2RGB_AccessData_PosCtrl_reg))
#define  YUV2RGB_AccessData_PosCtrl_starty_shift                                 (16)
#define  YUV2RGB_AccessData_PosCtrl_startx_shift                                 (0)
#define  YUV2RGB_AccessData_PosCtrl_starty_mask                                  (0x0FFF0000)
#define  YUV2RGB_AccessData_PosCtrl_startx_mask                                  (0x00001FFF)
#define  YUV2RGB_AccessData_PosCtrl_starty(data)                                 (0x0FFF0000&((data)<<16))
#define  YUV2RGB_AccessData_PosCtrl_startx(data)                                 (0x00001FFF&(data))
#define  YUV2RGB_AccessData_PosCtrl_get_starty(data)                             ((0x0FFF0000&(data))>>16)
#define  YUV2RGB_AccessData_PosCtrl_get_startx(data)                             (0x00001FFF&(data))

#define  YUV2RGB_ReadData_DATA_Y1                                                0x1802ADC8
#define  YUV2RGB_ReadData_DATA_Y1_reg_addr                                       "0xB802ADC8"
#define  YUV2RGB_ReadData_DATA_Y1_reg                                            0xB802ADC8
#define  YUV2RGB_ReadData_DATA_Y1_inst_addr                                      "0x006A"
#define  set_YUV2RGB_ReadData_DATA_Y1_reg(data)                                  (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_Y1_reg)=data)
#define  get_YUV2RGB_ReadData_DATA_Y1_reg                                        (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_Y1_reg))
#define  YUV2RGB_ReadData_DATA_Y1_y01_shift                                      (16)
#define  YUV2RGB_ReadData_DATA_Y1_y00_shift                                      (0)
#define  YUV2RGB_ReadData_DATA_Y1_y01_mask                                       (0x3FFF0000)
#define  YUV2RGB_ReadData_DATA_Y1_y00_mask                                       (0x00003FFF)
#define  YUV2RGB_ReadData_DATA_Y1_y01(data)                                      (0x3FFF0000&((data)<<16))
#define  YUV2RGB_ReadData_DATA_Y1_y00(data)                                      (0x00003FFF&(data))
#define  YUV2RGB_ReadData_DATA_Y1_get_y01(data)                                  ((0x3FFF0000&(data))>>16)
#define  YUV2RGB_ReadData_DATA_Y1_get_y00(data)                                  (0x00003FFF&(data))

#define  YUV2RGB_ReadData_DATA_Y2                                                0x1802ADCC
#define  YUV2RGB_ReadData_DATA_Y2_reg_addr                                       "0xB802ADCC"
#define  YUV2RGB_ReadData_DATA_Y2_reg                                            0xB802ADCC
#define  YUV2RGB_ReadData_DATA_Y2_inst_addr                                      "0x006B"
#define  set_YUV2RGB_ReadData_DATA_Y2_reg(data)                                  (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_Y2_reg)=data)
#define  get_YUV2RGB_ReadData_DATA_Y2_reg                                        (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_Y2_reg))
#define  YUV2RGB_ReadData_DATA_Y2_y11_shift                                      (16)
#define  YUV2RGB_ReadData_DATA_Y2_y10_shift                                      (0)
#define  YUV2RGB_ReadData_DATA_Y2_y11_mask                                       (0x3FFF0000)
#define  YUV2RGB_ReadData_DATA_Y2_y10_mask                                       (0x00003FFF)
#define  YUV2RGB_ReadData_DATA_Y2_y11(data)                                      (0x3FFF0000&((data)<<16))
#define  YUV2RGB_ReadData_DATA_Y2_y10(data)                                      (0x00003FFF&(data))
#define  YUV2RGB_ReadData_DATA_Y2_get_y11(data)                                  ((0x3FFF0000&(data))>>16)
#define  YUV2RGB_ReadData_DATA_Y2_get_y10(data)                                  (0x00003FFF&(data))

#define  YUV2RGB_ReadData_DATA_C1                                                0x1802ADD0
#define  YUV2RGB_ReadData_DATA_C1_reg_addr                                       "0xB802ADD0"
#define  YUV2RGB_ReadData_DATA_C1_reg                                            0xB802ADD0
#define  YUV2RGB_ReadData_DATA_C1_inst_addr                                      "0x006C"
#define  set_YUV2RGB_ReadData_DATA_C1_reg(data)                                  (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_C1_reg)=data)
#define  get_YUV2RGB_ReadData_DATA_C1_reg                                        (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_C1_reg))
#define  YUV2RGB_ReadData_DATA_C1_v00_shift                                      (16)
#define  YUV2RGB_ReadData_DATA_C1_u00_shift                                      (0)
#define  YUV2RGB_ReadData_DATA_C1_v00_mask                                       (0x3FFF0000)
#define  YUV2RGB_ReadData_DATA_C1_u00_mask                                       (0x00003FFF)
#define  YUV2RGB_ReadData_DATA_C1_v00(data)                                      (0x3FFF0000&((data)<<16))
#define  YUV2RGB_ReadData_DATA_C1_u00(data)                                      (0x00003FFF&(data))
#define  YUV2RGB_ReadData_DATA_C1_get_v00(data)                                  ((0x3FFF0000&(data))>>16)
#define  YUV2RGB_ReadData_DATA_C1_get_u00(data)                                  (0x00003FFF&(data))

#define  YUV2RGB_ReadData_DATA_C2                                                0x1802ADD4
#define  YUV2RGB_ReadData_DATA_C2_reg_addr                                       "0xB802ADD4"
#define  YUV2RGB_ReadData_DATA_C2_reg                                            0xB802ADD4
#define  YUV2RGB_ReadData_DATA_C2_inst_addr                                      "0x006D"
#define  set_YUV2RGB_ReadData_DATA_C2_reg(data)                                  (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_C2_reg)=data)
#define  get_YUV2RGB_ReadData_DATA_C2_reg                                        (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_C2_reg))
#define  YUV2RGB_ReadData_DATA_C2_v01_shift                                      (16)
#define  YUV2RGB_ReadData_DATA_C2_u01_shift                                      (0)
#define  YUV2RGB_ReadData_DATA_C2_v01_mask                                       (0x3FFF0000)
#define  YUV2RGB_ReadData_DATA_C2_u01_mask                                       (0x00003FFF)
#define  YUV2RGB_ReadData_DATA_C2_v01(data)                                      (0x3FFF0000&((data)<<16))
#define  YUV2RGB_ReadData_DATA_C2_u01(data)                                      (0x00003FFF&(data))
#define  YUV2RGB_ReadData_DATA_C2_get_v01(data)                                  ((0x3FFF0000&(data))>>16)
#define  YUV2RGB_ReadData_DATA_C2_get_u01(data)                                  (0x00003FFF&(data))

#define  YUV2RGB_ReadData_DATA_C3                                                0x1802ADD8
#define  YUV2RGB_ReadData_DATA_C3_reg_addr                                       "0xB802ADD8"
#define  YUV2RGB_ReadData_DATA_C3_reg                                            0xB802ADD8
#define  YUV2RGB_ReadData_DATA_C3_inst_addr                                      "0x006E"
#define  set_YUV2RGB_ReadData_DATA_C3_reg(data)                                  (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_C3_reg)=data)
#define  get_YUV2RGB_ReadData_DATA_C3_reg                                        (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_C3_reg))
#define  YUV2RGB_ReadData_DATA_C3_v10_shift                                      (16)
#define  YUV2RGB_ReadData_DATA_C3_u10_shift                                      (0)
#define  YUV2RGB_ReadData_DATA_C3_v10_mask                                       (0x3FFF0000)
#define  YUV2RGB_ReadData_DATA_C3_u10_mask                                       (0x00003FFF)
#define  YUV2RGB_ReadData_DATA_C3_v10(data)                                      (0x3FFF0000&((data)<<16))
#define  YUV2RGB_ReadData_DATA_C3_u10(data)                                      (0x00003FFF&(data))
#define  YUV2RGB_ReadData_DATA_C3_get_v10(data)                                  ((0x3FFF0000&(data))>>16)
#define  YUV2RGB_ReadData_DATA_C3_get_u10(data)                                  (0x00003FFF&(data))

#define  YUV2RGB_ReadData_DATA_C4                                                0x1802ADDC
#define  YUV2RGB_ReadData_DATA_C4_reg_addr                                       "0xB802ADDC"
#define  YUV2RGB_ReadData_DATA_C4_reg                                            0xB802ADDC
#define  YUV2RGB_ReadData_DATA_C4_inst_addr                                      "0x006F"
#define  set_YUV2RGB_ReadData_DATA_C4_reg(data)                                  (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_C4_reg)=data)
#define  get_YUV2RGB_ReadData_DATA_C4_reg                                        (*((volatile unsigned int*)YUV2RGB_ReadData_DATA_C4_reg))
#define  YUV2RGB_ReadData_DATA_C4_v11_shift                                      (16)
#define  YUV2RGB_ReadData_DATA_C4_u11_shift                                      (0)
#define  YUV2RGB_ReadData_DATA_C4_v11_mask                                       (0x3FFF0000)
#define  YUV2RGB_ReadData_DATA_C4_u11_mask                                       (0x00003FFF)
#define  YUV2RGB_ReadData_DATA_C4_v11(data)                                      (0x3FFF0000&((data)<<16))
#define  YUV2RGB_ReadData_DATA_C4_u11(data)                                      (0x00003FFF&(data))
#define  YUV2RGB_ReadData_DATA_C4_get_v11(data)                                  ((0x3FFF0000&(data))>>16)
#define  YUV2RGB_ReadData_DATA_C4_get_u11(data)                                  (0x00003FFF&(data))

#define  YUV2RGB_WriteData_DATA                                                  0x1802ADE0
#define  YUV2RGB_WriteData_DATA_reg_addr                                         "0xB802ADE0"
#define  YUV2RGB_WriteData_DATA_reg                                              0xB802ADE0
#define  YUV2RGB_WriteData_DATA_inst_addr                                        "0x0070"
#define  set_YUV2RGB_WriteData_DATA_reg(data)                                    (*((volatile unsigned int*)YUV2RGB_WriteData_DATA_reg)=data)
#define  get_YUV2RGB_WriteData_DATA_reg                                          (*((volatile unsigned int*)YUV2RGB_WriteData_DATA_reg))
#define  YUV2RGB_WriteData_DATA_v_shift                                          (8)
#define  YUV2RGB_WriteData_DATA_u_shift                                          (4)
#define  YUV2RGB_WriteData_DATA_y_shift                                          (0)
#define  YUV2RGB_WriteData_DATA_v_mask                                           (0x00000F00)
#define  YUV2RGB_WriteData_DATA_u_mask                                           (0x000000F0)
#define  YUV2RGB_WriteData_DATA_y_mask                                           (0x0000000F)
#define  YUV2RGB_WriteData_DATA_v(data)                                          (0x00000F00&((data)<<8))
#define  YUV2RGB_WriteData_DATA_u(data)                                          (0x000000F0&((data)<<4))
#define  YUV2RGB_WriteData_DATA_y(data)                                          (0x0000000F&(data))
#define  YUV2RGB_WriteData_DATA_get_v(data)                                      ((0x00000F00&(data))>>8)
#define  YUV2RGB_WriteData_DATA_get_u(data)                                      ((0x000000F0&(data))>>4)
#define  YUV2RGB_WriteData_DATA_get_y(data)                                      (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======YUV2RGB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  yuv2rgb_main_tab_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  yuv2rgb_main_out_shift:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  yuv2rgb_main_en:1;
    };
}yuv2rgb_d_yuv2rgb_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  yuv2rgb_db_read_level:1;
        RBus_UInt32  yuv2rgb_db_en:1;
        RBus_UInt32  yuv2rgb_db_apply:1;
    };
}yuv2rgb_d_yuv2rgb_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  cb_cr_clamp:1;
        RBus_UInt32  y_clamp:1;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_clamp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  roffset:17;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  goffset:17;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  boffset:17;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_4:8;
        RBus_UInt32  index_3:8;
        RBus_UInt32  index_2:8;
        RBus_UInt32  index_1:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_8:8;
        RBus_UInt32  index_7:8;
        RBus_UInt32  index_6:8;
        RBus_UInt32  index_5:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_12:8;
        RBus_UInt32  index_11:8;
        RBus_UInt32  index_10:8;
        RBus_UInt32  index_9:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_16:8;
        RBus_UInt32  index_15:8;
        RBus_UInt32  index_14:8;
        RBus_UInt32  index_13:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_4:8;
        RBus_UInt32  index_3:8;
        RBus_UInt32  index_2:8;
        RBus_UInt32  index_1:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_8:8;
        RBus_UInt32  index_7:8;
        RBus_UInt32  index_6:8;
        RBus_UInt32  index_5:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_12:8;
        RBus_UInt32  index_11:8;
        RBus_UInt32  index_10:8;
        RBus_UInt32  index_9:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_16:8;
        RBus_UInt32  index_15:8;
        RBus_UInt32  index_14:8;
        RBus_UInt32  index_13:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  yuv2rgb_coef_by_sat_gain:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  yuv2rgb_coef_by_sat_mode:1;
        RBus_UInt32  yuv2rgbbymode_main_en:2;
    };
}yuv2rgb_d_yuv2rgbbyy_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k12:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  k13:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k23:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  k33:11;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  uvoffsetbyy_mode:2;
        RBus_UInt32  uvoffsetbyy_main_en:1;
    };
}yuv2rgb_d_uvoffsetbyy_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m3:8;
        RBus_UInt32  uoffset_m2:8;
        RBus_UInt32  uoffset_m1:8;
        RBus_UInt32  uoffset_m0:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m7:8;
        RBus_UInt32  uoffset_m6:8;
        RBus_UInt32  uoffset_m5:8;
        RBus_UInt32  uoffset_m4:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m11:8;
        RBus_UInt32  uoffset_m10:8;
        RBus_UInt32  uoffset_m9:8;
        RBus_UInt32  uoffset_m8:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m15:8;
        RBus_UInt32  uoffset_m14:8;
        RBus_UInt32  uoffset_m13:8;
        RBus_UInt32  uoffset_m12:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  uoffset_m16:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m3:8;
        RBus_UInt32  voffset_m2:8;
        RBus_UInt32  voffset_m1:8;
        RBus_UInt32  voffset_m0:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m7:8;
        RBus_UInt32  voffset_m6:8;
        RBus_UInt32  voffset_m5:8;
        RBus_UInt32  voffset_m4:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m11:8;
        RBus_UInt32  voffset_m10:8;
        RBus_UInt32  voffset_m9:8;
        RBus_UInt32  voffset_m8:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m15:8;
        RBus_UInt32  voffset_m14:8;
        RBus_UInt32  voffset_m13:8;
        RBus_UInt32  voffset_m12:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  voffset_m16:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m3:8;
        RBus_UInt32  ustep_m2:8;
        RBus_UInt32  ustep_m1:8;
        RBus_UInt32  ustep_m0:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m7:8;
        RBus_UInt32  ustep_m6:8;
        RBus_UInt32  ustep_m5:8;
        RBus_UInt32  ustep_m4:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m11:8;
        RBus_UInt32  ustep_m10:8;
        RBus_UInt32  ustep_m9:8;
        RBus_UInt32  ustep_m8:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m15:8;
        RBus_UInt32  ustep_m14:8;
        RBus_UInt32  ustep_m13:8;
        RBus_UInt32  ustep_m12:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ustep_m16:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m3:8;
        RBus_UInt32  vstep_m2:8;
        RBus_UInt32  vstep_m1:8;
        RBus_UInt32  vstep_m0:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m7:8;
        RBus_UInt32  vstep_m6:8;
        RBus_UInt32  vstep_m5:8;
        RBus_UInt32  vstep_m4:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m11:8;
        RBus_UInt32  vstep_m10:8;
        RBus_UInt32  vstep_m9:8;
        RBus_UInt32  vstep_m8:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m15:8;
        RBus_UInt32  vstep_m14:8;
        RBus_UInt32  vstep_m13:8;
        RBus_UInt32  vstep_m12:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vstep_m16:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}yuv2rgb_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  starty:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  startx:13;
    };
}yuv2rgb_accessdata_posctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y01:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  y00:14;
    };
}yuv2rgb_readdata_data_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y11:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  y10:14;
    };
}yuv2rgb_readdata_data_y2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v00:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  u00:14;
    };
}yuv2rgb_readdata_data_c1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v01:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  u01:14;
    };
}yuv2rgb_readdata_data_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v10:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  u10:14;
    };
}yuv2rgb_readdata_data_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  v11:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  u11:14;
    };
}yuv2rgb_readdata_data_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}yuv2rgb_writedata_data_RBUS;

#else //apply LITTLE_ENDIAN

//======YUV2RGB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yuv2rgb_main_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  yuv2rgb_main_out_shift:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  yuv2rgb_main_tab_sel:1;
        RBus_UInt32  res3:27;
    };
}yuv2rgb_d_yuv2rgb_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yuv2rgb_db_apply:1;
        RBus_UInt32  yuv2rgb_db_en:1;
        RBus_UInt32  yuv2rgb_db_read_level:1;
        RBus_UInt32  res1:29;
    };
}yuv2rgb_d_yuv2rgb_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_clamp:1;
        RBus_UInt32  cb_cr_clamp:1;
        RBus_UInt32  res1:30;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_clamp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  roffset:17;
        RBus_UInt32  res1:15;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  goffset:17;
        RBus_UInt32  res1:15;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  boffset:17;
        RBus_UInt32  res1:15;
    };
}yuv2rgb_d_yuv2rgb_tab1_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_1:8;
        RBus_UInt32  index_2:8;
        RBus_UInt32  index_3:8;
        RBus_UInt32  index_4:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_5:8;
        RBus_UInt32  index_6:8;
        RBus_UInt32  index_7:8;
        RBus_UInt32  index_8:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_9:8;
        RBus_UInt32  index_10:8;
        RBus_UInt32  index_11:8;
        RBus_UInt32  index_12:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_13:8;
        RBus_UInt32  index_14:8;
        RBus_UInt32  index_15:8;
        RBus_UInt32  index_16:8;
    };
}yuv2rgb_d_coefbyy_nonlinear_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_1:8;
        RBus_UInt32  index_2:8;
        RBus_UInt32  index_3:8;
        RBus_UInt32  index_4:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_5:8;
        RBus_UInt32  index_6:8;
        RBus_UInt32  index_7:8;
        RBus_UInt32  index_8:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_9:8;
        RBus_UInt32  index_10:8;
        RBus_UInt32  index_11:8;
        RBus_UInt32  index_12:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  index_13:8;
        RBus_UInt32  index_14:8;
        RBus_UInt32  index_15:8;
        RBus_UInt32  index_16:8;
    };
}yuv2rgb_d_offsetbyy_nonlinear_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yuv2rgbbymode_main_en:2;
        RBus_UInt32  yuv2rgb_coef_by_sat_mode:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  yuv2rgb_coef_by_sat_gain:8;
        RBus_UInt32  res2:16;
    };
}yuv2rgb_d_yuv2rgbbyy_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_3_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_4_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_5_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_6_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_7_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_8_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_9_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_10_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_11_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_12_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_13_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_14_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_15_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k12:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k11:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k13:11;
        RBus_UInt32  res1:21;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k23:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k22:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k33:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  k32:11;
        RBus_UInt32  res2:5;
    };
}yuv2rgb_d_yuv2rgbbyy_tab_data_16_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvoffsetbyy_main_en:1;
        RBus_UInt32  uvoffsetbyy_mode:2;
        RBus_UInt32  res1:29;
    };
}yuv2rgb_d_uvoffsetbyy_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m0:8;
        RBus_UInt32  uoffset_m1:8;
        RBus_UInt32  uoffset_m2:8;
        RBus_UInt32  uoffset_m3:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m4:8;
        RBus_UInt32  uoffset_m5:8;
        RBus_UInt32  uoffset_m6:8;
        RBus_UInt32  uoffset_m7:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m8:8;
        RBus_UInt32  uoffset_m9:8;
        RBus_UInt32  uoffset_m10:8;
        RBus_UInt32  uoffset_m11:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m12:8;
        RBus_UInt32  uoffset_m13:8;
        RBus_UInt32  uoffset_m14:8;
        RBus_UInt32  uoffset_m15:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uoffset_m16:8;
        RBus_UInt32  res1:24;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m0:8;
        RBus_UInt32  voffset_m1:8;
        RBus_UInt32  voffset_m2:8;
        RBus_UInt32  voffset_m3:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m4:8;
        RBus_UInt32  voffset_m5:8;
        RBus_UInt32  voffset_m6:8;
        RBus_UInt32  voffset_m7:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m8:8;
        RBus_UInt32  voffset_m9:8;
        RBus_UInt32  voffset_m10:8;
        RBus_UInt32  voffset_m11:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m12:8;
        RBus_UInt32  voffset_m13:8;
        RBus_UInt32  voffset_m14:8;
        RBus_UInt32  voffset_m15:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  voffset_m16:8;
        RBus_UInt32  res1:24;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m0:8;
        RBus_UInt32  ustep_m1:8;
        RBus_UInt32  ustep_m2:8;
        RBus_UInt32  ustep_m3:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m4:8;
        RBus_UInt32  ustep_m5:8;
        RBus_UInt32  ustep_m6:8;
        RBus_UInt32  ustep_m7:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m8:8;
        RBus_UInt32  ustep_m9:8;
        RBus_UInt32  ustep_m10:8;
        RBus_UInt32  ustep_m11:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m12:8;
        RBus_UInt32  ustep_m13:8;
        RBus_UInt32  ustep_m14:8;
        RBus_UInt32  ustep_m15:8;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ustep_m16:8;
        RBus_UInt32  res1:24;
    };
}yuv2rgb_d_uvoffsetbyy_u_tab_step_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m0:8;
        RBus_UInt32  vstep_m1:8;
        RBus_UInt32  vstep_m2:8;
        RBus_UInt32  vstep_m3:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m4:8;
        RBus_UInt32  vstep_m5:8;
        RBus_UInt32  vstep_m6:8;
        RBus_UInt32  vstep_m7:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m8:8;
        RBus_UInt32  vstep_m9:8;
        RBus_UInt32  vstep_m10:8;
        RBus_UInt32  vstep_m11:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m12:8;
        RBus_UInt32  vstep_m13:8;
        RBus_UInt32  vstep_m14:8;
        RBus_UInt32  vstep_m15:8;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstep_m16:8;
        RBus_UInt32  res1:24;
    };
}yuv2rgb_d_uvoffsetbyy_v_tab_step_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}yuv2rgb_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:12;
        RBus_UInt32  res2:4;
    };
}yuv2rgb_accessdata_posctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  y01:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  y11:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_y2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  v00:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_c1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  v01:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  v10:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  v11:14;
        RBus_UInt32  res2:2;
    };
}yuv2rgb_readdata_data_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  res1:20;
    };
}yuv2rgb_writedata_data_RBUS;




#endif 


#endif 
