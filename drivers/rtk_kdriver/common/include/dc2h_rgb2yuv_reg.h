/**
* @file Mac5-DesignSpec-D-Domain_DC2H
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DC2H_RGB2YUV_REG_H_
#define _RBUS_DC2H_RGB2YUV_REG_H_

#include "rbus_types.h"



//  DC2H_RGB2YUV Register Address
#define  DC2H_RGB2YUV_DC2H_clken                                                 0x18029C20
#define  DC2H_RGB2YUV_DC2H_clken_reg_addr                                        "0xB8029C20"
#define  DC2H_RGB2YUV_DC2H_clken_reg                                             0xB8029C20
#define  DC2H_RGB2YUV_DC2H_clken_inst_addr                                       "0x0000"
#define  set_DC2H_RGB2YUV_DC2H_clken_reg(data)                                   (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_clken_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_clken_reg                                         (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_clken_reg))
#define  DC2H_RGB2YUV_DC2H_clken_clken_disp_dc2h_shift                           (0)
#define  DC2H_RGB2YUV_DC2H_clken_clken_disp_dc2h_mask                            (0x00000001)
#define  DC2H_RGB2YUV_DC2H_clken_clken_disp_dc2h(data)                           (0x00000001&(data))
#define  DC2H_RGB2YUV_DC2H_clken_get_clken_disp_dc2h(data)                       (0x00000001&(data))

#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL                                          0x18029C00
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg_addr                                 "0xB8029C00"
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg                                      0xB8029C00
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_inst_addr                                "0x0001"
#define  set_DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg(data)                            (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg                                  (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_reg))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_dc2h_in_sel_shift                        (16)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_err_dif_bits_shift                       (13)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_err_dif_enable_shift                     (12)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_rgb_in_offset_shift                      (11)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_2x_gain_shift                        (10)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_y_gain_shift                         (9)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_matrix_bypass_shift                      (8)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_uv_off_shift                         (7)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_set_uv_out_offset_shift                  (6)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_set_r_in_offset_shift                    (5)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_rgb_shift                            (4)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_sign_shift                           (3)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_en_rgb2yuv_shift                         (0)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_dc2h_in_sel_mask                         (0x00070000)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_err_dif_bits_mask                        (0x0000E000)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_err_dif_enable_mask                      (0x00001000)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_rgb_in_offset_mask                       (0x00000800)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_2x_gain_mask                         (0x00000400)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_y_gain_mask                          (0x00000200)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_matrix_bypass_mask                       (0x00000100)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_uv_off_mask                          (0x00000080)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_set_uv_out_offset_mask                   (0x00000040)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_set_r_in_offset_mask                     (0x00000020)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_rgb_mask                             (0x00000010)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_sign_mask                            (0x00000008)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_en_rgb2yuv_mask                          (0x00000003)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_dc2h_in_sel(data)                        (0x00070000&((data)<<16))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_err_dif_bits(data)                       (0x0000E000&((data)<<13))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_err_dif_enable(data)                     (0x00001000&((data)<<12))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_rgb_in_offset(data)                      (0x00000800&((data)<<11))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_2x_gain(data)                        (0x00000400&((data)<<10))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_y_gain(data)                         (0x00000200&((data)<<9))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_matrix_bypass(data)                      (0x00000100&((data)<<8))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_uv_off(data)                         (0x00000080&((data)<<7))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_set_uv_out_offset(data)                  (0x00000040&((data)<<6))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_set_r_in_offset(data)                    (0x00000020&((data)<<5))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_rgb(data)                            (0x00000010&((data)<<4))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_sel_sign(data)                           (0x00000008&((data)<<3))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_en_rgb2yuv(data)                         (0x00000003&(data))
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_dc2h_in_sel(data)                    ((0x00070000&(data))>>16)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_err_dif_bits(data)                   ((0x0000E000&(data))>>13)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_err_dif_enable(data)                 ((0x00001000&(data))>>12)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_rgb_in_offset(data)                  ((0x00000800&(data))>>11)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_sel_2x_gain(data)                    ((0x00000400&(data))>>10)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_sel_y_gain(data)                     ((0x00000200&(data))>>9)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_matrix_bypass(data)                  ((0x00000100&(data))>>8)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_sel_uv_off(data)                     ((0x00000080&(data))>>7)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_set_uv_out_offset(data)              ((0x00000040&(data))>>6)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_set_r_in_offset(data)                ((0x00000020&(data))>>5)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_sel_rgb(data)                        ((0x00000010&(data))>>4)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_sel_sign(data)                       ((0x00000008&(data))>>3)
#define  DC2H_RGB2YUV_DC2H_RGB2YUV_CTRL_get_en_rgb2yuv(data)                     (0x00000003&(data))

#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12                                          0x18029C04
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_reg_addr                                 "0xB8029C04"
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_reg                                      0xB8029C04
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_inst_addr                                "0x0002"
#define  set_DC2H_RGB2YUV_DC2H_Tab1_M11_M12_reg(data)                            (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M11_M12_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_Tab1_M11_M12_reg                                  (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M11_M12_reg))
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_m12_shift                                (16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_m11_shift                                (0)
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_m12_mask                                 (0x7FFF0000)
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_m11_mask                                 (0x00007FFF)
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_m12(data)                                (0x7FFF0000&((data)<<16))
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_m11(data)                                (0x00007FFF&(data))
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_get_m12(data)                            ((0x7FFF0000&(data))>>16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M11_M12_get_m11(data)                            (0x00007FFF&(data))

#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21                                          0x18029C08
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_reg_addr                                 "0xB8029C08"
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_reg                                      0xB8029C08
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_inst_addr                                "0x0003"
#define  set_DC2H_RGB2YUV_DC2H_Tab1_M13_M21_reg(data)                            (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M13_M21_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_Tab1_M13_M21_reg                                  (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M13_M21_reg))
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_m21_shift                                (16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_m13_shift                                (0)
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_m21_mask                                 (0x7FFF0000)
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_m13_mask                                 (0x00007FFF)
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_m21(data)                                (0x7FFF0000&((data)<<16))
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_m13(data)                                (0x00007FFF&(data))
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_get_m21(data)                            ((0x7FFF0000&(data))>>16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M13_M21_get_m13(data)                            (0x00007FFF&(data))

#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23                                          0x18029C0C
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_reg_addr                                 "0xB8029C0C"
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_reg                                      0xB8029C0C
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_inst_addr                                "0x0004"
#define  set_DC2H_RGB2YUV_DC2H_Tab1_M22_M23_reg(data)                            (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M22_M23_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_Tab1_M22_M23_reg                                  (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M22_M23_reg))
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_m23_shift                                (16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_m22_shift                                (0)
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_m23_mask                                 (0x7FFF0000)
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_m22_mask                                 (0x00007FFF)
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_m23(data)                                (0x7FFF0000&((data)<<16))
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_m22(data)                                (0x00007FFF&(data))
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_get_m23(data)                            ((0x7FFF0000&(data))>>16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M22_M23_get_m22(data)                            (0x00007FFF&(data))

#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32                                          0x18029C10
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_reg_addr                                 "0xB8029C10"
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_reg                                      0xB8029C10
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_inst_addr                                "0x0005"
#define  set_DC2H_RGB2YUV_DC2H_Tab1_M31_M32_reg(data)                            (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M31_M32_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_Tab1_M31_M32_reg                                  (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M31_M32_reg))
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_m32_shift                                (16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_m31_shift                                (0)
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_m32_mask                                 (0x7FFF0000)
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_m31_mask                                 (0x00007FFF)
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_m32(data)                                (0x7FFF0000&((data)<<16))
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_m31(data)                                (0x00007FFF&(data))
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_get_m32(data)                            ((0x7FFF0000&(data))>>16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M31_M32_get_m31(data)                            (0x00007FFF&(data))

#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain                                       0x18029C14
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_reg_addr                              "0xB8029C14"
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_reg                                   0xB8029C14
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_inst_addr                             "0x0006"
#define  set_DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_reg(data)                         (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_reg                               (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_reg))
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_yo_gain_shift                         (16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_m33_shift                             (0)
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_yo_gain_mask                          (0x01FF0000)
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_m33_mask                              (0x00007FFF)
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_yo_gain(data)                         (0x01FF0000&((data)<<16))
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_m33(data)                             (0x00007FFF&(data))
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_get_yo_gain(data)                     ((0x01FF0000&(data))>>16)
#define  DC2H_RGB2YUV_DC2H_Tab1_M33_Y_Gain_get_m33(data)                         (0x00007FFF&(data))

#define  DC2H_RGB2YUV_DC2H_Tab1_Yo                                               0x18029C18
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_reg_addr                                      "0xB8029C18"
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_reg                                           0xB8029C18
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_inst_addr                                     "0x0007"
#define  set_DC2H_RGB2YUV_DC2H_Tab1_Yo_reg(data)                                 (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_Yo_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_Tab1_Yo_reg                                       (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_Tab1_Yo_reg))
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_yo_odd_shift                                  (16)
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_yo_even_shift                                 (0)
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_yo_odd_mask                                   (0x1FFF0000)
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_yo_even_mask                                  (0x00001FFF)
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_yo_odd(data)                                  (0x1FFF0000&((data)<<16))
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_yo_even(data)                                 (0x00001FFF&(data))
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_get_yo_odd(data)                              ((0x1FFF0000&(data))>>16)
#define  DC2H_RGB2YUV_DC2H_Tab1_Yo_get_yo_even(data)                             (0x00001FFF&(data))

#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl                                       0x18029C80
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg_addr                              "0xB8029C80"
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg                                   0xB8029C80
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_inst_addr                             "0x0008"
#define  set_DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg(data)                         (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg                               (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_reg))
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_dc2h_3dmaskto2d_3dformat_shift        (4)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_dc2h_3dmaskto2d_mode_shift            (1)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_dc2h_3dmaskto2d_en_shift              (0)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_dc2h_3dmaskto2d_3dformat_mask         (0x00000070)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_dc2h_3dmaskto2d_mode_mask             (0x00000002)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_dc2h_3dmaskto2d_en_mask               (0x00000001)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_dc2h_3dmaskto2d_3dformat(data)        (0x00000070&((data)<<4))
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_dc2h_3dmaskto2d_mode(data)            (0x00000002&((data)<<1))
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_dc2h_3dmaskto2d_en(data)              (0x00000001&(data))
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_get_dc2h_3dmaskto2d_3dformat(data)    ((0x00000070&(data))>>4)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_get_dc2h_3dmaskto2d_mode(data)        ((0x00000002&(data))>>1)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl_get_dc2h_3dmaskto2d_en(data)          (0x00000001&(data))

#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0                                        0x18029C84
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_reg_addr                               "0xB8029C84"
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_reg                                    0xB8029C84
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_inst_addr                              "0x0009"
#define  set_DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_reg(data)                          (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_reg                                (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_reg))
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_dc2h_overscan_left_shift               (16)
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_dc2h_overscan_right_shift              (0)
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_dc2h_overscan_left_mask                (0x1FFF0000)
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_dc2h_overscan_right_mask               (0x00001FFF)
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_dc2h_overscan_left(data)               (0x1FFF0000&((data)<<16))
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_dc2h_overscan_right(data)              (0x00001FFF&(data))
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_get_dc2h_overscan_left(data)           ((0x1FFF0000&(data))>>16)
#define  DC2H_RGB2YUV_DC2H_OVERSCAN_Ctrl0_get_dc2h_overscan_right(data)          (0x00001FFF&(data))

#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1                                      0x18029C88
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_reg_addr                             "0xB8029C88"
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_reg                                  0xB8029C88
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_inst_addr                            "0x000A"
#define  set_DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_reg(data)                        (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_reg)=data)
#define  get_DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_reg                              (*((volatile unsigned int*)DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_reg))
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_dc2h_overscan_top_shift              (16)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_dc2h_overscan_bottom_shift           (0)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_dc2h_overscan_top_mask               (0x1FFF0000)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_dc2h_overscan_bottom_mask            (0x00001FFF)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_dc2h_overscan_top(data)              (0x1FFF0000&((data)<<16))
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_dc2h_overscan_bottom(data)           (0x00001FFF&(data))
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_get_dc2h_overscan_top(data)          ((0x1FFF0000&(data))>>16)
#define  DC2H_RGB2YUV_DC2H_3DMaskTo2D_Ctrl1_get_dc2h_overscan_bottom(data)       (0x00001FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DC2H_RGB2YUV register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clken_disp_dc2h:1;
    };
}dc2h_rgb2yuv_dc2h_clken_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dc2h_in_sel:3;
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
        RBus_UInt32  res2:1;
        RBus_UInt32  en_rgb2yuv:2;
    };
}dc2h_rgb2yuv_dc2h_rgb2yuv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m11:15;
    };
}dc2h_rgb2yuv_dc2h_tab1_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m13:15;
    };
}dc2h_rgb2yuv_dc2h_tab1_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m22:15;
    };
}dc2h_rgb2yuv_dc2h_tab1_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  m31:15;
    };
}dc2h_rgb2yuv_dc2h_tab1_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  yo_gain:9;
        RBus_UInt32  res2:1;
        RBus_UInt32  m33:15;
    };
}dc2h_rgb2yuv_dc2h_tab1_m33_y_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  yo_even:13;
    };
}dc2h_rgb2yuv_dc2h_tab1_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dc2h_3dmaskto2d_3dformat:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  dc2h_3dmaskto2d_mode:1;
        RBus_UInt32  dc2h_3dmaskto2d_en:1;
    };
}dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dc2h_overscan_left:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dc2h_overscan_right:13;
    };
}dc2h_rgb2yuv_dc2h_overscan_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dc2h_overscan_top:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dc2h_overscan_bottom:13;
    };
}dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl1_RBUS;

#else //apply LITTLE_ENDIAN

//======DC2H_RGB2YUV register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_disp_dc2h:1;
        RBus_UInt32  res1:31;
    };
}dc2h_rgb2yuv_dc2h_clken_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_rgb2yuv:2;
        RBus_UInt32  res1:1;
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
        RBus_UInt32  dc2h_in_sel:3;
        RBus_UInt32  res2:13;
    };
}dc2h_rgb2yuv_dc2h_rgb2yuv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m12:15;
        RBus_UInt32  res2:1;
    };
}dc2h_rgb2yuv_dc2h_tab1_m11_m12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m13:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m21:15;
        RBus_UInt32  res2:1;
    };
}dc2h_rgb2yuv_dc2h_tab1_m13_m21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m22:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m23:15;
        RBus_UInt32  res2:1;
    };
}dc2h_rgb2yuv_dc2h_tab1_m22_m23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m31:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m32:15;
        RBus_UInt32  res2:1;
    };
}dc2h_rgb2yuv_dc2h_tab1_m31_m32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m33:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  yo_gain:9;
        RBus_UInt32  res2:7;
    };
}dc2h_rgb2yuv_dc2h_tab1_m33_y_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yo_even:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yo_odd:13;
        RBus_UInt32  res2:3;
    };
}dc2h_rgb2yuv_dc2h_tab1_yo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc2h_3dmaskto2d_en:1;
        RBus_UInt32  dc2h_3dmaskto2d_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dc2h_3dmaskto2d_3dformat:3;
        RBus_UInt32  res2:25;
    };
}dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc2h_overscan_right:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dc2h_overscan_left:13;
        RBus_UInt32  res2:3;
    };
}dc2h_rgb2yuv_dc2h_overscan_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc2h_overscan_bottom:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dc2h_overscan_top:13;
        RBus_UInt32  res2:3;
    };
}dc2h_rgb2yuv_dc2h_3dmaskto2d_ctrl1_RBUS;




#endif 


#endif 
