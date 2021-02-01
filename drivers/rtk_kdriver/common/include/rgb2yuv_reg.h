/**
* @file MarArthur5-DesignSpec-I-Domain_Rgb2yuv
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_RGB2YUV_REG_H_
#define _RBUS_RGB2YUV_REG_H_

#include "rbus_types.h"



//  RGB2YUV Register Address
#define  RGB2YUV_ICH1_RGB2YUV_CTRL                                               0x18023000
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_reg_addr                                      "0xB8023000"
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_reg                                           0xB8023000
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_inst_addr                                     "0x0000"
#define  set_RGB2YUV_ICH1_RGB2YUV_CTRL_reg(data)                                 (*((volatile unsigned int*)RGB2YUV_ICH1_RGB2YUV_CTRL_reg)=data)
#define  get_RGB2YUV_ICH1_RGB2YUV_CTRL_reg                                       (*((volatile unsigned int*)RGB2YUV_ICH1_RGB2YUV_CTRL_reg))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_err_dif_bits_shift                            (13)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_err_dif_enable_shift                          (12)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_rgb_in_offset_shift                           (11)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_2x_gain_shift                             (10)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_y_gain_shift                              (9)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_matrix_bypass_shift                           (8)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_uv_off_shift                              (7)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_set_uv_out_offset_shift                       (6)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_set_r_in_offset_shift                         (5)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_rgb_shift                                 (4)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_sign_shift                                (3)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_table_shift                               (2)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_en_rgb2yuv_shift                              (0)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_err_dif_bits_mask                             (0x0000E000)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_err_dif_enable_mask                           (0x00001000)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_rgb_in_offset_mask                            (0x00000800)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_2x_gain_mask                              (0x00000400)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_y_gain_mask                               (0x00000200)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_matrix_bypass_mask                            (0x00000100)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_uv_off_mask                               (0x00000080)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_set_uv_out_offset_mask                        (0x00000040)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_set_r_in_offset_mask                          (0x00000020)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_rgb_mask                                  (0x00000010)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_sign_mask                                 (0x00000008)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_table_mask                                (0x00000004)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_en_rgb2yuv_mask                               (0x00000003)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_err_dif_bits(data)                            (0x0000E000&((data)<<13))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_err_dif_enable(data)                          (0x00001000&((data)<<12))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_rgb_in_offset(data)                           (0x00000800&((data)<<11))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_2x_gain(data)                             (0x00000400&((data)<<10))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_y_gain(data)                              (0x00000200&((data)<<9))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_matrix_bypass(data)                           (0x00000100&((data)<<8))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_uv_off(data)                              (0x00000080&((data)<<7))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_set_uv_out_offset(data)                       (0x00000040&((data)<<6))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_set_r_in_offset(data)                         (0x00000020&((data)<<5))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_rgb(data)                                 (0x00000010&((data)<<4))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_sign(data)                                (0x00000008&((data)<<3))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_sel_table(data)                               (0x00000004&((data)<<2))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_en_rgb2yuv(data)                              (0x00000003&(data))
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_err_dif_bits(data)                        ((0x0000E000&(data))>>13)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_err_dif_enable(data)                      ((0x00001000&(data))>>12)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_rgb_in_offset(data)                       ((0x00000800&(data))>>11)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_sel_2x_gain(data)                         ((0x00000400&(data))>>10)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_sel_y_gain(data)                          ((0x00000200&(data))>>9)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_matrix_bypass(data)                       ((0x00000100&(data))>>8)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_sel_uv_off(data)                          ((0x00000080&(data))>>7)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_set_uv_out_offset(data)                   ((0x00000040&(data))>>6)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_set_r_in_offset(data)                     ((0x00000020&(data))>>5)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_sel_rgb(data)                             ((0x00000010&(data))>>4)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_sel_sign(data)                            ((0x00000008&(data))>>3)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_sel_table(data)                           ((0x00000004&(data))>>2)
#define  RGB2YUV_ICH1_RGB2YUV_CTRL_get_en_rgb2yuv(data)                          (0x00000003&(data))

#define  RGB2YUV_Tab1_M11_M12                                                    0x18023008
#define  RGB2YUV_Tab1_M11_M12_reg_addr                                           "0xB8023008"
#define  RGB2YUV_Tab1_M11_M12_reg                                                0xB8023008
#define  RGB2YUV_Tab1_M11_M12_inst_addr                                          "0x0001"
#define  set_RGB2YUV_Tab1_M11_M12_reg(data)                                      (*((volatile unsigned int*)RGB2YUV_Tab1_M11_M12_reg)=data)
#define  get_RGB2YUV_Tab1_M11_M12_reg                                            (*((volatile unsigned int*)RGB2YUV_Tab1_M11_M12_reg))
#define  RGB2YUV_Tab1_M11_M12_m12_shift                                          (16)
#define  RGB2YUV_Tab1_M11_M12_m11_shift                                          (0)
#define  RGB2YUV_Tab1_M11_M12_m12_mask                                           (0x7FFF0000)
#define  RGB2YUV_Tab1_M11_M12_m11_mask                                           (0x00007FFF)
#define  RGB2YUV_Tab1_M11_M12_m12(data)                                          (0x7FFF0000&((data)<<16))
#define  RGB2YUV_Tab1_M11_M12_m11(data)                                          (0x00007FFF&(data))
#define  RGB2YUV_Tab1_M11_M12_get_m12(data)                                      ((0x7FFF0000&(data))>>16)
#define  RGB2YUV_Tab1_M11_M12_get_m11(data)                                      (0x00007FFF&(data))

#define  RGB2YUV_Tab1_M13_M21                                                    0x1802300C
#define  RGB2YUV_Tab1_M13_M21_reg_addr                                           "0xB802300C"
#define  RGB2YUV_Tab1_M13_M21_reg                                                0xB802300C
#define  RGB2YUV_Tab1_M13_M21_inst_addr                                          "0x0002"
#define  set_RGB2YUV_Tab1_M13_M21_reg(data)                                      (*((volatile unsigned int*)RGB2YUV_Tab1_M13_M21_reg)=data)
#define  get_RGB2YUV_Tab1_M13_M21_reg                                            (*((volatile unsigned int*)RGB2YUV_Tab1_M13_M21_reg))
#define  RGB2YUV_Tab1_M13_M21_m21_shift                                          (16)
#define  RGB2YUV_Tab1_M13_M21_m13_shift                                          (0)
#define  RGB2YUV_Tab1_M13_M21_m21_mask                                           (0x7FFF0000)
#define  RGB2YUV_Tab1_M13_M21_m13_mask                                           (0x00007FFF)
#define  RGB2YUV_Tab1_M13_M21_m21(data)                                          (0x7FFF0000&((data)<<16))
#define  RGB2YUV_Tab1_M13_M21_m13(data)                                          (0x00007FFF&(data))
#define  RGB2YUV_Tab1_M13_M21_get_m21(data)                                      ((0x7FFF0000&(data))>>16)
#define  RGB2YUV_Tab1_M13_M21_get_m13(data)                                      (0x00007FFF&(data))

#define  RGB2YUV_Tab1_M22_M23                                                    0x18023010
#define  RGB2YUV_Tab1_M22_M23_reg_addr                                           "0xB8023010"
#define  RGB2YUV_Tab1_M22_M23_reg                                                0xB8023010
#define  RGB2YUV_Tab1_M22_M23_inst_addr                                          "0x0003"
#define  set_RGB2YUV_Tab1_M22_M23_reg(data)                                      (*((volatile unsigned int*)RGB2YUV_Tab1_M22_M23_reg)=data)
#define  get_RGB2YUV_Tab1_M22_M23_reg                                            (*((volatile unsigned int*)RGB2YUV_Tab1_M22_M23_reg))
#define  RGB2YUV_Tab1_M22_M23_m23_shift                                          (16)
#define  RGB2YUV_Tab1_M22_M23_m22_shift                                          (0)
#define  RGB2YUV_Tab1_M22_M23_m23_mask                                           (0x7FFF0000)
#define  RGB2YUV_Tab1_M22_M23_m22_mask                                           (0x00007FFF)
#define  RGB2YUV_Tab1_M22_M23_m23(data)                                          (0x7FFF0000&((data)<<16))
#define  RGB2YUV_Tab1_M22_M23_m22(data)                                          (0x00007FFF&(data))
#define  RGB2YUV_Tab1_M22_M23_get_m23(data)                                      ((0x7FFF0000&(data))>>16)
#define  RGB2YUV_Tab1_M22_M23_get_m22(data)                                      (0x00007FFF&(data))

#define  RGB2YUV_Tab1_M31_M32                                                    0x18023014
#define  RGB2YUV_Tab1_M31_M32_reg_addr                                           "0xB8023014"
#define  RGB2YUV_Tab1_M31_M32_reg                                                0xB8023014
#define  RGB2YUV_Tab1_M31_M32_inst_addr                                          "0x0004"
#define  set_RGB2YUV_Tab1_M31_M32_reg(data)                                      (*((volatile unsigned int*)RGB2YUV_Tab1_M31_M32_reg)=data)
#define  get_RGB2YUV_Tab1_M31_M32_reg                                            (*((volatile unsigned int*)RGB2YUV_Tab1_M31_M32_reg))
#define  RGB2YUV_Tab1_M31_M32_m32_shift                                          (16)
#define  RGB2YUV_Tab1_M31_M32_m31_shift                                          (0)
#define  RGB2YUV_Tab1_M31_M32_m32_mask                                           (0x7FFF0000)
#define  RGB2YUV_Tab1_M31_M32_m31_mask                                           (0x00007FFF)
#define  RGB2YUV_Tab1_M31_M32_m32(data)                                          (0x7FFF0000&((data)<<16))
#define  RGB2YUV_Tab1_M31_M32_m31(data)                                          (0x00007FFF&(data))
#define  RGB2YUV_Tab1_M31_M32_get_m32(data)                                      ((0x7FFF0000&(data))>>16)
#define  RGB2YUV_Tab1_M31_M32_get_m31(data)                                      (0x00007FFF&(data))

#define  RGB2YUV_Tab1_M33_YGain                                                  0x18023018
#define  RGB2YUV_Tab1_M33_YGain_reg_addr                                         "0xB8023018"
#define  RGB2YUV_Tab1_M33_YGain_reg                                              0xB8023018
#define  RGB2YUV_Tab1_M33_YGain_inst_addr                                        "0x0005"
#define  set_RGB2YUV_Tab1_M33_YGain_reg(data)                                    (*((volatile unsigned int*)RGB2YUV_Tab1_M33_YGain_reg)=data)
#define  get_RGB2YUV_Tab1_M33_YGain_reg                                          (*((volatile unsigned int*)RGB2YUV_Tab1_M33_YGain_reg))
#define  RGB2YUV_Tab1_M33_YGain_y_gain_shift                                     (16)
#define  RGB2YUV_Tab1_M33_YGain_m33_shift                                        (0)
#define  RGB2YUV_Tab1_M33_YGain_y_gain_mask                                      (0x01FF0000)
#define  RGB2YUV_Tab1_M33_YGain_m33_mask                                         (0x00007FFF)
#define  RGB2YUV_Tab1_M33_YGain_y_gain(data)                                     (0x01FF0000&((data)<<16))
#define  RGB2YUV_Tab1_M33_YGain_m33(data)                                        (0x00007FFF&(data))
#define  RGB2YUV_Tab1_M33_YGain_get_y_gain(data)                                 ((0x01FF0000&(data))>>16)
#define  RGB2YUV_Tab1_M33_YGain_get_m33(data)                                    (0x00007FFF&(data))

#define  RGB2YUV_Tab1_Yo                                                         0x1802301C
#define  RGB2YUV_Tab1_Yo_reg_addr                                                "0xB802301C"
#define  RGB2YUV_Tab1_Yo_reg                                                     0xB802301C
#define  RGB2YUV_Tab1_Yo_inst_addr                                               "0x0006"
#define  set_RGB2YUV_Tab1_Yo_reg(data)                                           (*((volatile unsigned int*)RGB2YUV_Tab1_Yo_reg)=data)
#define  get_RGB2YUV_Tab1_Yo_reg                                                 (*((volatile unsigned int*)RGB2YUV_Tab1_Yo_reg))
#define  RGB2YUV_Tab1_Yo_yo_odd_shift                                            (16)
#define  RGB2YUV_Tab1_Yo_yo_even_shift                                           (0)
#define  RGB2YUV_Tab1_Yo_yo_odd_mask                                             (0x1FFF0000)
#define  RGB2YUV_Tab1_Yo_yo_even_mask                                            (0x00001FFF)
#define  RGB2YUV_Tab1_Yo_yo_odd(data)                                            (0x1FFF0000&((data)<<16))
#define  RGB2YUV_Tab1_Yo_yo_even(data)                                           (0x00001FFF&(data))
#define  RGB2YUV_Tab1_Yo_get_yo_odd(data)                                        ((0x1FFF0000&(data))>>16)
#define  RGB2YUV_Tab1_Yo_get_yo_even(data)                                       (0x00001FFF&(data))

#define  RGB2YUV_Tab2_M11_M12                                                    0x18023020
#define  RGB2YUV_Tab2_M11_M12_reg_addr                                           "0xB8023020"
#define  RGB2YUV_Tab2_M11_M12_reg                                                0xB8023020
#define  RGB2YUV_Tab2_M11_M12_inst_addr                                          "0x0007"
#define  set_RGB2YUV_Tab2_M11_M12_reg(data)                                      (*((volatile unsigned int*)RGB2YUV_Tab2_M11_M12_reg)=data)
#define  get_RGB2YUV_Tab2_M11_M12_reg                                            (*((volatile unsigned int*)RGB2YUV_Tab2_M11_M12_reg))
#define  RGB2YUV_Tab2_M11_M12_m12_shift                                          (16)
#define  RGB2YUV_Tab2_M11_M12_m11_shift                                          (0)
#define  RGB2YUV_Tab2_M11_M12_m12_mask                                           (0x7FFF0000)
#define  RGB2YUV_Tab2_M11_M12_m11_mask                                           (0x00007FFF)
#define  RGB2YUV_Tab2_M11_M12_m12(data)                                          (0x7FFF0000&((data)<<16))
#define  RGB2YUV_Tab2_M11_M12_m11(data)                                          (0x00007FFF&(data))
#define  RGB2YUV_Tab2_M11_M12_get_m12(data)                                      ((0x7FFF0000&(data))>>16)
#define  RGB2YUV_Tab2_M11_M12_get_m11(data)                                      (0x00007FFF&(data))

#define  RGB2YUV_Tab2_M13_M21                                                    0x18023024
#define  RGB2YUV_Tab2_M13_M21_reg_addr                                           "0xB8023024"
#define  RGB2YUV_Tab2_M13_M21_reg                                                0xB8023024
#define  RGB2YUV_Tab2_M13_M21_inst_addr                                          "0x0008"
#define  set_RGB2YUV_Tab2_M13_M21_reg(data)                                      (*((volatile unsigned int*)RGB2YUV_Tab2_M13_M21_reg)=data)
#define  get_RGB2YUV_Tab2_M13_M21_reg                                            (*((volatile unsigned int*)RGB2YUV_Tab2_M13_M21_reg))
#define  RGB2YUV_Tab2_M13_M21_m21_shift                                          (16)
#define  RGB2YUV_Tab2_M13_M21_m13_shift                                          (0)
#define  RGB2YUV_Tab2_M13_M21_m21_mask                                           (0x7FFF0000)
#define  RGB2YUV_Tab2_M13_M21_m13_mask                                           (0x00007FFF)
#define  RGB2YUV_Tab2_M13_M21_m21(data)                                          (0x7FFF0000&((data)<<16))
#define  RGB2YUV_Tab2_M13_M21_m13(data)                                          (0x00007FFF&(data))
#define  RGB2YUV_Tab2_M13_M21_get_m21(data)                                      ((0x7FFF0000&(data))>>16)
#define  RGB2YUV_Tab2_M13_M21_get_m13(data)                                      (0x00007FFF&(data))

#define  RGB2YUV_Tab2_M22_M23                                                    0x18023028
#define  RGB2YUV_Tab2_M22_M23_reg_addr                                           "0xB8023028"
#define  RGB2YUV_Tab2_M22_M23_reg                                                0xB8023028
#define  RGB2YUV_Tab2_M22_M23_inst_addr                                          "0x0009"
#define  set_RGB2YUV_Tab2_M22_M23_reg(data)                                      (*((volatile unsigned int*)RGB2YUV_Tab2_M22_M23_reg)=data)
#define  get_RGB2YUV_Tab2_M22_M23_reg                                            (*((volatile unsigned int*)RGB2YUV_Tab2_M22_M23_reg))
#define  RGB2YUV_Tab2_M22_M23_m23_shift                                          (16)
#define  RGB2YUV_Tab2_M22_M23_m22_shift                                          (0)
#define  RGB2YUV_Tab2_M22_M23_m23_mask                                           (0x7FFF0000)
#define  RGB2YUV_Tab2_M22_M23_m22_mask                                           (0x00007FFF)
#define  RGB2YUV_Tab2_M22_M23_m23(data)                                          (0x7FFF0000&((data)<<16))
#define  RGB2YUV_Tab2_M22_M23_m22(data)                                          (0x00007FFF&(data))
#define  RGB2YUV_Tab2_M22_M23_get_m23(data)                                      ((0x7FFF0000&(data))>>16)
#define  RGB2YUV_Tab2_M22_M23_get_m22(data)                                      (0x00007FFF&(data))

#define  RGB2YUV_Tab2_M31_M32                                                    0x1802302C
#define  RGB2YUV_Tab2_M31_M32_reg_addr                                           "0xB802302C"
#define  RGB2YUV_Tab2_M31_M32_reg                                                0xB802302C
#define  RGB2YUV_Tab2_M31_M32_inst_addr                                          "0x000A"
#define  set_RGB2YUV_Tab2_M31_M32_reg(data)                                      (*((volatile unsigned int*)RGB2YUV_Tab2_M31_M32_reg)=data)
#define  get_RGB2YUV_Tab2_M31_M32_reg                                            (*((volatile unsigned int*)RGB2YUV_Tab2_M31_M32_reg))
#define  RGB2YUV_Tab2_M31_M32_m32_shift                                          (16)
#define  RGB2YUV_Tab2_M31_M32_m31_shift                                          (0)
#define  RGB2YUV_Tab2_M31_M32_m32_mask                                           (0x7FFF0000)
#define  RGB2YUV_Tab2_M31_M32_m31_mask                                           (0x00007FFF)
#define  RGB2YUV_Tab2_M31_M32_m32(data)                                          (0x7FFF0000&((data)<<16))
#define  RGB2YUV_Tab2_M31_M32_m31(data)                                          (0x00007FFF&(data))
#define  RGB2YUV_Tab2_M31_M32_get_m32(data)                                      ((0x7FFF0000&(data))>>16)
#define  RGB2YUV_Tab2_M31_M32_get_m31(data)                                      (0x00007FFF&(data))

#define  RGB2YUV_Tab2_M33_Y_Gain                                                 0x18023030
#define  RGB2YUV_Tab2_M33_Y_Gain_reg_addr                                        "0xB8023030"
#define  RGB2YUV_Tab2_M33_Y_Gain_reg                                             0xB8023030
#define  RGB2YUV_Tab2_M33_Y_Gain_inst_addr                                       "0x000B"
#define  set_RGB2YUV_Tab2_M33_Y_Gain_reg(data)                                   (*((volatile unsigned int*)RGB2YUV_Tab2_M33_Y_Gain_reg)=data)
#define  get_RGB2YUV_Tab2_M33_Y_Gain_reg                                         (*((volatile unsigned int*)RGB2YUV_Tab2_M33_Y_Gain_reg))
#define  RGB2YUV_Tab2_M33_Y_Gain_y_gain_shift                                    (16)
#define  RGB2YUV_Tab2_M33_Y_Gain_m33_shift                                       (0)
#define  RGB2YUV_Tab2_M33_Y_Gain_y_gain_mask                                     (0x01FF0000)
#define  RGB2YUV_Tab2_M33_Y_Gain_m33_mask                                        (0x00007FFF)
#define  RGB2YUV_Tab2_M33_Y_Gain_y_gain(data)                                    (0x01FF0000&((data)<<16))
#define  RGB2YUV_Tab2_M33_Y_Gain_m33(data)                                       (0x00007FFF&(data))
#define  RGB2YUV_Tab2_M33_Y_Gain_get_y_gain(data)                                ((0x01FF0000&(data))>>16)
#define  RGB2YUV_Tab2_M33_Y_Gain_get_m33(data)                                   (0x00007FFF&(data))

#define  RGB2YUV_Tab2_Yo                                                         0x18023034
#define  RGB2YUV_Tab2_Yo_reg_addr                                                "0xB8023034"
#define  RGB2YUV_Tab2_Yo_reg                                                     0xB8023034
#define  RGB2YUV_Tab2_Yo_inst_addr                                               "0x000C"
#define  set_RGB2YUV_Tab2_Yo_reg(data)                                           (*((volatile unsigned int*)RGB2YUV_Tab2_Yo_reg)=data)
#define  get_RGB2YUV_Tab2_Yo_reg                                                 (*((volatile unsigned int*)RGB2YUV_Tab2_Yo_reg))
#define  RGB2YUV_Tab2_Yo_yo_odd_shift                                            (16)
#define  RGB2YUV_Tab2_Yo_yo_even_shift                                           (0)
#define  RGB2YUV_Tab2_Yo_yo_odd_mask                                             (0x1FFF0000)
#define  RGB2YUV_Tab2_Yo_yo_even_mask                                            (0x00001FFF)
#define  RGB2YUV_Tab2_Yo_yo_odd(data)                                            (0x1FFF0000&((data)<<16))
#define  RGB2YUV_Tab2_Yo_yo_even(data)                                           (0x00001FFF&(data))
#define  RGB2YUV_Tab2_Yo_get_yo_odd(data)                                        ((0x1FFF0000&(data))>>16)
#define  RGB2YUV_Tab2_Yo_get_yo_even(data)                                       (0x00001FFF&(data))

#define  RGB2YUV_ICH1_422to444_CTRL                                              0x18023038
#define  RGB2YUV_ICH1_422to444_CTRL_reg_addr                                     "0xB8023038"
#define  RGB2YUV_ICH1_422to444_CTRL_reg                                          0xB8023038
#define  RGB2YUV_ICH1_422to444_CTRL_inst_addr                                    "0x000D"
#define  set_RGB2YUV_ICH1_422to444_CTRL_reg(data)                                (*((volatile unsigned int*)RGB2YUV_ICH1_422to444_CTRL_reg)=data)
#define  get_RGB2YUV_ICH1_422to444_CTRL_reg                                      (*((volatile unsigned int*)RGB2YUV_ICH1_422to444_CTRL_reg))
#define  RGB2YUV_ICH1_422to444_CTRL_db_read_shift                                (5)
#define  RGB2YUV_ICH1_422to444_CTRL_db_en_shift                                  (4)
#define  RGB2YUV_ICH1_422to444_CTRL_db_apply_shift                               (3)
#define  RGB2YUV_ICH1_422to444_CTRL_cr_dly_cb_shift                              (2)
#define  RGB2YUV_ICH1_422to444_CTRL_dup_shift                                    (1)
#define  RGB2YUV_ICH1_422to444_CTRL_en_422to444_shift                            (0)
#define  RGB2YUV_ICH1_422to444_CTRL_db_read_mask                                 (0x00000020)
#define  RGB2YUV_ICH1_422to444_CTRL_db_en_mask                                   (0x00000010)
#define  RGB2YUV_ICH1_422to444_CTRL_db_apply_mask                                (0x00000008)
#define  RGB2YUV_ICH1_422to444_CTRL_cr_dly_cb_mask                               (0x00000004)
#define  RGB2YUV_ICH1_422to444_CTRL_dup_mask                                     (0x00000002)
#define  RGB2YUV_ICH1_422to444_CTRL_en_422to444_mask                             (0x00000001)
#define  RGB2YUV_ICH1_422to444_CTRL_db_read(data)                                (0x00000020&((data)<<5))
#define  RGB2YUV_ICH1_422to444_CTRL_db_en(data)                                  (0x00000010&((data)<<4))
#define  RGB2YUV_ICH1_422to444_CTRL_db_apply(data)                               (0x00000008&((data)<<3))
#define  RGB2YUV_ICH1_422to444_CTRL_cr_dly_cb(data)                              (0x00000004&((data)<<2))
#define  RGB2YUV_ICH1_422to444_CTRL_dup(data)                                    (0x00000002&((data)<<1))
#define  RGB2YUV_ICH1_422to444_CTRL_en_422to444(data)                            (0x00000001&(data))
#define  RGB2YUV_ICH1_422to444_CTRL_get_db_read(data)                            ((0x00000020&(data))>>5)
#define  RGB2YUV_ICH1_422to444_CTRL_get_db_en(data)                              ((0x00000010&(data))>>4)
#define  RGB2YUV_ICH1_422to444_CTRL_get_db_apply(data)                           ((0x00000008&(data))>>3)
#define  RGB2YUV_ICH1_422to444_CTRL_get_cr_dly_cb(data)                          ((0x00000004&(data))>>2)
#define  RGB2YUV_ICH1_422to444_CTRL_get_dup(data)                                ((0x00000002&(data))>>1)
#define  RGB2YUV_ICH1_422to444_CTRL_get_en_422to444(data)                        (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======RGB2YUV register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  err_dif_bits:3;
        RBus_UInt32  err_dif_enable:1;
        RBus_UInt32  rgb_in_offset:1;
        RBus_UInt32  sel_2x_gain:1;
        RBus_UInt32  sel_y_gain:1;
        RBus_UInt32  matrix_bypass:1;
        RBus_UInt32  sel_uv_off:1;
        RBus_UInt32  set_uv_out_offset:1;
        RBus_UInt32  set_r_in_offset:1;
        RBus_UInt32  sel_rgb:1;
        RBus_UInt32  sel_sign:1;
        RBus_UInt32  sel_table:1;
        RBus_UInt32  en_rgb2yuv:2;
    };
}rgb2yuv_ich1_rgb2yuv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m11:15;
    };
}rgb2yuv_tab1_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m13:15;
    };
}rgb2yuv_tab1_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m22:15;
    };
}rgb2yuv_tab1_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m31:15;
    };
}rgb2yuv_tab1_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res2:1;
        RBus_UInt32  m33:15;
    };
}rgb2yuv_tab1_m33_ygain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  yo_even:13;
    };
}rgb2yuv_tab1_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m11:15;
    };
}rgb2yuv_tab2_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m13:15;
    };
}rgb2yuv_tab2_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m22:15;
    };
}rgb2yuv_tab2_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m31:15;
    };
}rgb2yuv_tab2_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res2:1;
        RBus_UInt32  m33:15;
    };
}rgb2yuv_tab2_m33_y_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  yo_even:13;
    };
}rgb2yuv_tab2_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  dup:1;
        RBus_UInt32  en_422to444:1;
    };
}rgb2yuv_ich1_422to444_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======RGB2YUV register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_rgb2yuv:2;
        RBus_UInt32  sel_table:1;
        RBus_UInt32  sel_sign:1;
        RBus_UInt32  sel_rgb:1;
        RBus_UInt32  set_r_in_offset:1;
        RBus_UInt32  set_uv_out_offset:1;
        RBus_UInt32  sel_uv_off:1;
        RBus_UInt32  matrix_bypass:1;
        RBus_UInt32  sel_y_gain:1;
        RBus_UInt32  sel_2x_gain:1;
        RBus_UInt32  rgb_in_offset:1;
        RBus_UInt32  err_dif_enable:1;
        RBus_UInt32  err_dif_bits:3;
        RBus_UInt32  res1:16;
    };
}rgb2yuv_ich1_rgb2yuv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab1_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m13:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab1_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m22:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab1_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m31:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab1_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res2:7;
    };
}rgb2yuv_tab1_m33_ygain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yo_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
    };
}rgb2yuv_tab1_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab2_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m13:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab2_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m22:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab2_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m31:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
    };
}rgb2yuv_tab2_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_gain:9;
        RBus_UInt32  res2:7;
    };
}rgb2yuv_tab2_m33_y_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yo_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
    };
}rgb2yuv_tab2_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_422to444:1;
        RBus_UInt32  dup:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res1:26;
    };
}rgb2yuv_ich1_422to444_ctrl_RBUS;




#endif 


#endif 
