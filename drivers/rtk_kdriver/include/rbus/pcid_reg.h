/**
* @file Mac5-DesignSpec-D-Domain_PCID
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PCID_REG_H_
#define _RBUS_PCID_REG_H_

#include "rbus_types.h"



//  PCID Register Address
#define  PCID_PCID_DITHER_CTRL                                                   0x1802EF00
#define  PCID_PCID_DITHER_CTRL_reg_addr                                          "0xB802EF00"
#define  PCID_PCID_DITHER_CTRL_reg                                               0xB802EF00
#define  PCID_PCID_DITHER_CTRL_inst_addr                                         "0x0000"
#define  set_PCID_PCID_DITHER_CTRL_reg(data)                                     (*((volatile unsigned int*)PCID_PCID_DITHER_CTRL_reg)=data)
#define  get_PCID_PCID_DITHER_CTRL_reg                                           (*((volatile unsigned int*)PCID_PCID_DITHER_CTRL_reg))
#define  PCID_PCID_DITHER_CTRL_pcid_dither_en_shift                              (5)
#define  PCID_PCID_DITHER_CTRL_pcid_temporal_enable_shift                        (4)
#define  PCID_PCID_DITHER_CTRL_pcid_value_sign_shift                             (3)
#define  PCID_PCID_DITHER_CTRL_pcid_dithering_mode_shift                         (2)
#define  PCID_PCID_DITHER_CTRL_pcid_v_modulation_shift                           (1)
#define  PCID_PCID_DITHER_CTRL_pcid_h_modulation_shift                           (0)
#define  PCID_PCID_DITHER_CTRL_pcid_dither_en_mask                               (0x00000020)
#define  PCID_PCID_DITHER_CTRL_pcid_temporal_enable_mask                         (0x00000010)
#define  PCID_PCID_DITHER_CTRL_pcid_value_sign_mask                              (0x00000008)
#define  PCID_PCID_DITHER_CTRL_pcid_dithering_mode_mask                          (0x00000004)
#define  PCID_PCID_DITHER_CTRL_pcid_v_modulation_mask                            (0x00000002)
#define  PCID_PCID_DITHER_CTRL_pcid_h_modulation_mask                            (0x00000001)
#define  PCID_PCID_DITHER_CTRL_pcid_dither_en(data)                              (0x00000020&((data)<<5))
#define  PCID_PCID_DITHER_CTRL_pcid_temporal_enable(data)                        (0x00000010&((data)<<4))
#define  PCID_PCID_DITHER_CTRL_pcid_value_sign(data)                             (0x00000008&((data)<<3))
#define  PCID_PCID_DITHER_CTRL_pcid_dithering_mode(data)                         (0x00000004&((data)<<2))
#define  PCID_PCID_DITHER_CTRL_pcid_v_modulation(data)                           (0x00000002&((data)<<1))
#define  PCID_PCID_DITHER_CTRL_pcid_h_modulation(data)                           (0x00000001&(data))
#define  PCID_PCID_DITHER_CTRL_get_pcid_dither_en(data)                          ((0x00000020&(data))>>5)
#define  PCID_PCID_DITHER_CTRL_get_pcid_temporal_enable(data)                    ((0x00000010&(data))>>4)
#define  PCID_PCID_DITHER_CTRL_get_pcid_value_sign(data)                         ((0x00000008&(data))>>3)
#define  PCID_PCID_DITHER_CTRL_get_pcid_dithering_mode(data)                     ((0x00000004&(data))>>2)
#define  PCID_PCID_DITHER_CTRL_get_pcid_v_modulation(data)                       ((0x00000002&(data))>>1)
#define  PCID_PCID_DITHER_CTRL_get_pcid_h_modulation(data)                       (0x00000001&(data))

#define  PCID_PCID_DITHER_SEQ_R_00_15                                            0x1802EF04
#define  PCID_PCID_DITHER_SEQ_R_00_15_reg_addr                                   "0xB802EF04"
#define  PCID_PCID_DITHER_SEQ_R_00_15_reg                                        0xB802EF04
#define  PCID_PCID_DITHER_SEQ_R_00_15_inst_addr                                  "0x0001"
#define  set_PCID_PCID_DITHER_SEQ_R_00_15_reg(data)                              (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_R_00_15_reg)=data)
#define  get_PCID_PCID_DITHER_SEQ_R_00_15_reg                                    (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_R_00_15_reg))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_15_shift                        (30)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_14_shift                        (28)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_13_shift                        (26)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_12_shift                        (24)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_11_shift                        (22)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_10_shift                        (20)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_9_shift                         (18)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_8_shift                         (16)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_7_shift                         (14)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_6_shift                         (12)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_5_shift                         (10)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_4_shift                         (8)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_3_shift                         (6)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_2_shift                         (4)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_1_shift                         (2)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_0_shift                         (0)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_15_mask                         (0xC0000000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_14_mask                         (0x30000000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_13_mask                         (0x0C000000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_12_mask                         (0x03000000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_11_mask                         (0x00C00000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_10_mask                         (0x00300000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_9_mask                          (0x000C0000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_8_mask                          (0x00030000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_7_mask                          (0x0000C000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_6_mask                          (0x00003000)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_5_mask                          (0x00000C00)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_4_mask                          (0x00000300)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_3_mask                          (0x000000C0)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_2_mask                          (0x00000030)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_1_mask                          (0x0000000C)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_0_mask                          (0x00000003)
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_15(data)                        (0xC0000000&((data)<<30))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_14(data)                        (0x30000000&((data)<<28))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_13(data)                        (0x0C000000&((data)<<26))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_12(data)                        (0x03000000&((data)<<24))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_11(data)                        (0x00C00000&((data)<<22))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_10(data)                        (0x00300000&((data)<<20))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_9(data)                         (0x000C0000&((data)<<18))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_8(data)                         (0x00030000&((data)<<16))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_7(data)                         (0x0000C000&((data)<<14))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_6(data)                         (0x00003000&((data)<<12))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_5(data)                         (0x00000C00&((data)<<10))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_4(data)                         (0x00000300&((data)<<8))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_3(data)                         (0x000000C0&((data)<<6))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_2(data)                         (0x00000030&((data)<<4))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_1(data)                         (0x0000000C&((data)<<2))
#define  PCID_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_0(data)                         (0x00000003&(data))
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_15(data)                    ((0xC0000000&(data))>>30)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_14(data)                    ((0x30000000&(data))>>28)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_13(data)                    ((0x0C000000&(data))>>26)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_12(data)                    ((0x03000000&(data))>>24)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_11(data)                    ((0x00C00000&(data))>>22)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_10(data)                    ((0x00300000&(data))>>20)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_9(data)                     ((0x000C0000&(data))>>18)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_8(data)                     ((0x00030000&(data))>>16)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_7(data)                     ((0x0000C000&(data))>>14)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_6(data)                     ((0x00003000&(data))>>12)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_5(data)                     ((0x00000C00&(data))>>10)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_4(data)                     ((0x00000300&(data))>>8)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_3(data)                     ((0x000000C0&(data))>>6)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_2(data)                     ((0x00000030&(data))>>4)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_1(data)                     ((0x0000000C&(data))>>2)
#define  PCID_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_0(data)                     (0x00000003&(data))

#define  PCID_PCID_DITHER_SEQ_R_16_31                                            0x1802EF08
#define  PCID_PCID_DITHER_SEQ_R_16_31_reg_addr                                   "0xB802EF08"
#define  PCID_PCID_DITHER_SEQ_R_16_31_reg                                        0xB802EF08
#define  PCID_PCID_DITHER_SEQ_R_16_31_inst_addr                                  "0x0002"
#define  set_PCID_PCID_DITHER_SEQ_R_16_31_reg(data)                              (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_R_16_31_reg)=data)
#define  get_PCID_PCID_DITHER_SEQ_R_16_31_reg                                    (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_R_16_31_reg))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_31_shift                        (30)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_30_shift                        (28)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_29_shift                        (26)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_28_shift                        (24)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_27_shift                        (22)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_26_shift                        (20)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_25_shift                        (18)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_24_shift                        (16)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_23_shift                        (14)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_22_shift                        (12)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_21_shift                        (10)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_20_shift                        (8)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_19_shift                        (6)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_18_shift                        (4)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_17_shift                        (2)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_16_shift                        (0)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_31_mask                         (0xC0000000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_30_mask                         (0x30000000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_29_mask                         (0x0C000000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_28_mask                         (0x03000000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_27_mask                         (0x00C00000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_26_mask                         (0x00300000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_25_mask                         (0x000C0000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_24_mask                         (0x00030000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_23_mask                         (0x0000C000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_22_mask                         (0x00003000)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_21_mask                         (0x00000C00)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_20_mask                         (0x00000300)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_19_mask                         (0x000000C0)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_18_mask                         (0x00000030)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_17_mask                         (0x0000000C)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_16_mask                         (0x00000003)
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_31(data)                        (0xC0000000&((data)<<30))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_30(data)                        (0x30000000&((data)<<28))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_29(data)                        (0x0C000000&((data)<<26))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_28(data)                        (0x03000000&((data)<<24))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_27(data)                        (0x00C00000&((data)<<22))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_26(data)                        (0x00300000&((data)<<20))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_25(data)                        (0x000C0000&((data)<<18))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_24(data)                        (0x00030000&((data)<<16))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_23(data)                        (0x0000C000&((data)<<14))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_22(data)                        (0x00003000&((data)<<12))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_21(data)                        (0x00000C00&((data)<<10))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_20(data)                        (0x00000300&((data)<<8))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_19(data)                        (0x000000C0&((data)<<6))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_18(data)                        (0x00000030&((data)<<4))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_17(data)                        (0x0000000C&((data)<<2))
#define  PCID_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_16(data)                        (0x00000003&(data))
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_31(data)                    ((0xC0000000&(data))>>30)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_30(data)                    ((0x30000000&(data))>>28)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_29(data)                    ((0x0C000000&(data))>>26)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_28(data)                    ((0x03000000&(data))>>24)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_27(data)                    ((0x00C00000&(data))>>22)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_26(data)                    ((0x00300000&(data))>>20)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_25(data)                    ((0x000C0000&(data))>>18)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_24(data)                    ((0x00030000&(data))>>16)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_23(data)                    ((0x0000C000&(data))>>14)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_22(data)                    ((0x00003000&(data))>>12)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_21(data)                    ((0x00000C00&(data))>>10)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_20(data)                    ((0x00000300&(data))>>8)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_19(data)                    ((0x000000C0&(data))>>6)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_18(data)                    ((0x00000030&(data))>>4)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_17(data)                    ((0x0000000C&(data))>>2)
#define  PCID_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_16(data)                    (0x00000003&(data))

#define  PCID_PCID_DITHER_SEQ_G_00_15                                            0x1802EF0C
#define  PCID_PCID_DITHER_SEQ_G_00_15_reg_addr                                   "0xB802EF0C"
#define  PCID_PCID_DITHER_SEQ_G_00_15_reg                                        0xB802EF0C
#define  PCID_PCID_DITHER_SEQ_G_00_15_inst_addr                                  "0x0003"
#define  set_PCID_PCID_DITHER_SEQ_G_00_15_reg(data)                              (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_G_00_15_reg)=data)
#define  get_PCID_PCID_DITHER_SEQ_G_00_15_reg                                    (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_G_00_15_reg))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_15_shift                        (30)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_14_shift                        (28)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_13_shift                        (26)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_12_shift                        (24)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_11_shift                        (22)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_10_shift                        (20)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_9_shift                         (18)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_8_shift                         (16)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_7_shift                         (14)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_6_shift                         (12)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_5_shift                         (10)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_4_shift                         (8)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_3_shift                         (6)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_2_shift                         (4)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_1_shift                         (2)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_0_shift                         (0)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_15_mask                         (0xC0000000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_14_mask                         (0x30000000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_13_mask                         (0x0C000000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_12_mask                         (0x03000000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_11_mask                         (0x00C00000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_10_mask                         (0x00300000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_9_mask                          (0x000C0000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_8_mask                          (0x00030000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_7_mask                          (0x0000C000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_6_mask                          (0x00003000)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_5_mask                          (0x00000C00)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_4_mask                          (0x00000300)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_3_mask                          (0x000000C0)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_2_mask                          (0x00000030)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_1_mask                          (0x0000000C)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_0_mask                          (0x00000003)
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_15(data)                        (0xC0000000&((data)<<30))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_14(data)                        (0x30000000&((data)<<28))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_13(data)                        (0x0C000000&((data)<<26))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_12(data)                        (0x03000000&((data)<<24))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_11(data)                        (0x00C00000&((data)<<22))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_10(data)                        (0x00300000&((data)<<20))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_9(data)                         (0x000C0000&((data)<<18))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_8(data)                         (0x00030000&((data)<<16))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_7(data)                         (0x0000C000&((data)<<14))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_6(data)                         (0x00003000&((data)<<12))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_5(data)                         (0x00000C00&((data)<<10))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_4(data)                         (0x00000300&((data)<<8))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_3(data)                         (0x000000C0&((data)<<6))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_2(data)                         (0x00000030&((data)<<4))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_1(data)                         (0x0000000C&((data)<<2))
#define  PCID_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_0(data)                         (0x00000003&(data))
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_15(data)                    ((0xC0000000&(data))>>30)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_14(data)                    ((0x30000000&(data))>>28)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_13(data)                    ((0x0C000000&(data))>>26)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_12(data)                    ((0x03000000&(data))>>24)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_11(data)                    ((0x00C00000&(data))>>22)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_10(data)                    ((0x00300000&(data))>>20)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_9(data)                     ((0x000C0000&(data))>>18)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_8(data)                     ((0x00030000&(data))>>16)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_7(data)                     ((0x0000C000&(data))>>14)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_6(data)                     ((0x00003000&(data))>>12)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_5(data)                     ((0x00000C00&(data))>>10)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_4(data)                     ((0x00000300&(data))>>8)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_3(data)                     ((0x000000C0&(data))>>6)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_2(data)                     ((0x00000030&(data))>>4)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_1(data)                     ((0x0000000C&(data))>>2)
#define  PCID_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_0(data)                     (0x00000003&(data))

#define  PCID_PCID_DITHER_SEQ_G_16_31                                            0x1802EF10
#define  PCID_PCID_DITHER_SEQ_G_16_31_reg_addr                                   "0xB802EF10"
#define  PCID_PCID_DITHER_SEQ_G_16_31_reg                                        0xB802EF10
#define  PCID_PCID_DITHER_SEQ_G_16_31_inst_addr                                  "0x0004"
#define  set_PCID_PCID_DITHER_SEQ_G_16_31_reg(data)                              (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_G_16_31_reg)=data)
#define  get_PCID_PCID_DITHER_SEQ_G_16_31_reg                                    (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_G_16_31_reg))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_31_shift                        (30)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_30_shift                        (28)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_29_shift                        (26)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_28_shift                        (24)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_27_shift                        (22)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_26_shift                        (20)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_25_shift                        (18)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_24_shift                        (16)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_23_shift                        (14)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_22_shift                        (12)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_21_shift                        (10)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_20_shift                        (8)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_19_shift                        (6)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_18_shift                        (4)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_17_shift                        (2)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_16_shift                        (0)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_31_mask                         (0xC0000000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_30_mask                         (0x30000000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_29_mask                         (0x0C000000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_28_mask                         (0x03000000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_27_mask                         (0x00C00000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_26_mask                         (0x00300000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_25_mask                         (0x000C0000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_24_mask                         (0x00030000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_23_mask                         (0x0000C000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_22_mask                         (0x00003000)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_21_mask                         (0x00000C00)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_20_mask                         (0x00000300)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_19_mask                         (0x000000C0)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_18_mask                         (0x00000030)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_17_mask                         (0x0000000C)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_16_mask                         (0x00000003)
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_31(data)                        (0xC0000000&((data)<<30))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_30(data)                        (0x30000000&((data)<<28))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_29(data)                        (0x0C000000&((data)<<26))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_28(data)                        (0x03000000&((data)<<24))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_27(data)                        (0x00C00000&((data)<<22))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_26(data)                        (0x00300000&((data)<<20))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_25(data)                        (0x000C0000&((data)<<18))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_24(data)                        (0x00030000&((data)<<16))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_23(data)                        (0x0000C000&((data)<<14))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_22(data)                        (0x00003000&((data)<<12))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_21(data)                        (0x00000C00&((data)<<10))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_20(data)                        (0x00000300&((data)<<8))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_19(data)                        (0x000000C0&((data)<<6))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_18(data)                        (0x00000030&((data)<<4))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_17(data)                        (0x0000000C&((data)<<2))
#define  PCID_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_16(data)                        (0x00000003&(data))
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_31(data)                    ((0xC0000000&(data))>>30)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_30(data)                    ((0x30000000&(data))>>28)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_29(data)                    ((0x0C000000&(data))>>26)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_28(data)                    ((0x03000000&(data))>>24)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_27(data)                    ((0x00C00000&(data))>>22)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_26(data)                    ((0x00300000&(data))>>20)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_25(data)                    ((0x000C0000&(data))>>18)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_24(data)                    ((0x00030000&(data))>>16)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_23(data)                    ((0x0000C000&(data))>>14)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_22(data)                    ((0x00003000&(data))>>12)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_21(data)                    ((0x00000C00&(data))>>10)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_20(data)                    ((0x00000300&(data))>>8)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_19(data)                    ((0x000000C0&(data))>>6)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_18(data)                    ((0x00000030&(data))>>4)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_17(data)                    ((0x0000000C&(data))>>2)
#define  PCID_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_16(data)                    (0x00000003&(data))

#define  PCID_PCID_DITHER_SEQ_B_00_15                                            0x1802EF14
#define  PCID_PCID_DITHER_SEQ_B_00_15_reg_addr                                   "0xB802EF14"
#define  PCID_PCID_DITHER_SEQ_B_00_15_reg                                        0xB802EF14
#define  PCID_PCID_DITHER_SEQ_B_00_15_inst_addr                                  "0x0005"
#define  set_PCID_PCID_DITHER_SEQ_B_00_15_reg(data)                              (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_B_00_15_reg)=data)
#define  get_PCID_PCID_DITHER_SEQ_B_00_15_reg                                    (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_B_00_15_reg))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_15_shift                        (30)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_14_shift                        (28)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_13_shift                        (26)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_12_shift                        (24)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_11_shift                        (22)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_10_shift                        (20)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_9_shift                         (18)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_8_shift                         (16)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_7_shift                         (14)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_6_shift                         (12)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_5_shift                         (10)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_4_shift                         (8)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_3_shift                         (6)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_2_shift                         (4)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_1_shift                         (2)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_0_shift                         (0)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_15_mask                         (0xC0000000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_14_mask                         (0x30000000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_13_mask                         (0x0C000000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_12_mask                         (0x03000000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_11_mask                         (0x00C00000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_10_mask                         (0x00300000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_9_mask                          (0x000C0000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_8_mask                          (0x00030000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_7_mask                          (0x0000C000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_6_mask                          (0x00003000)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_5_mask                          (0x00000C00)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_4_mask                          (0x00000300)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_3_mask                          (0x000000C0)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_2_mask                          (0x00000030)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_1_mask                          (0x0000000C)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_0_mask                          (0x00000003)
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_15(data)                        (0xC0000000&((data)<<30))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_14(data)                        (0x30000000&((data)<<28))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_13(data)                        (0x0C000000&((data)<<26))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_12(data)                        (0x03000000&((data)<<24))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_11(data)                        (0x00C00000&((data)<<22))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_10(data)                        (0x00300000&((data)<<20))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_9(data)                         (0x000C0000&((data)<<18))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_8(data)                         (0x00030000&((data)<<16))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_7(data)                         (0x0000C000&((data)<<14))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_6(data)                         (0x00003000&((data)<<12))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_5(data)                         (0x00000C00&((data)<<10))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_4(data)                         (0x00000300&((data)<<8))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_3(data)                         (0x000000C0&((data)<<6))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_2(data)                         (0x00000030&((data)<<4))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_1(data)                         (0x0000000C&((data)<<2))
#define  PCID_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_0(data)                         (0x00000003&(data))
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_15(data)                    ((0xC0000000&(data))>>30)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_14(data)                    ((0x30000000&(data))>>28)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_13(data)                    ((0x0C000000&(data))>>26)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_12(data)                    ((0x03000000&(data))>>24)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_11(data)                    ((0x00C00000&(data))>>22)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_10(data)                    ((0x00300000&(data))>>20)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_9(data)                     ((0x000C0000&(data))>>18)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_8(data)                     ((0x00030000&(data))>>16)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_7(data)                     ((0x0000C000&(data))>>14)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_6(data)                     ((0x00003000&(data))>>12)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_5(data)                     ((0x00000C00&(data))>>10)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_4(data)                     ((0x00000300&(data))>>8)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_3(data)                     ((0x000000C0&(data))>>6)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_2(data)                     ((0x00000030&(data))>>4)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_1(data)                     ((0x0000000C&(data))>>2)
#define  PCID_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_0(data)                     (0x00000003&(data))

#define  PCID_PCID_DITHER_SEQ_B_16_31                                            0x1802EF18
#define  PCID_PCID_DITHER_SEQ_B_16_31_reg_addr                                   "0xB802EF18"
#define  PCID_PCID_DITHER_SEQ_B_16_31_reg                                        0xB802EF18
#define  PCID_PCID_DITHER_SEQ_B_16_31_inst_addr                                  "0x0006"
#define  set_PCID_PCID_DITHER_SEQ_B_16_31_reg(data)                              (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_B_16_31_reg)=data)
#define  get_PCID_PCID_DITHER_SEQ_B_16_31_reg                                    (*((volatile unsigned int*)PCID_PCID_DITHER_SEQ_B_16_31_reg))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_31_shift                        (30)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_30_shift                        (28)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_29_shift                        (26)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_28_shift                        (24)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_27_shift                        (22)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_26_shift                        (20)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_25_shift                        (18)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_24_shift                        (16)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_23_shift                        (14)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_22_shift                        (12)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_21_shift                        (10)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_20_shift                        (8)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_19_shift                        (6)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_18_shift                        (4)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_17_shift                        (2)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_16_shift                        (0)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_31_mask                         (0xC0000000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_30_mask                         (0x30000000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_29_mask                         (0x0C000000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_28_mask                         (0x03000000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_27_mask                         (0x00C00000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_26_mask                         (0x00300000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_25_mask                         (0x000C0000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_24_mask                         (0x00030000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_23_mask                         (0x0000C000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_22_mask                         (0x00003000)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_21_mask                         (0x00000C00)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_20_mask                         (0x00000300)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_19_mask                         (0x000000C0)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_18_mask                         (0x00000030)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_17_mask                         (0x0000000C)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_16_mask                         (0x00000003)
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_31(data)                        (0xC0000000&((data)<<30))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_30(data)                        (0x30000000&((data)<<28))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_29(data)                        (0x0C000000&((data)<<26))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_28(data)                        (0x03000000&((data)<<24))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_27(data)                        (0x00C00000&((data)<<22))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_26(data)                        (0x00300000&((data)<<20))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_25(data)                        (0x000C0000&((data)<<18))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_24(data)                        (0x00030000&((data)<<16))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_23(data)                        (0x0000C000&((data)<<14))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_22(data)                        (0x00003000&((data)<<12))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_21(data)                        (0x00000C00&((data)<<10))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_20(data)                        (0x00000300&((data)<<8))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_19(data)                        (0x000000C0&((data)<<6))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_18(data)                        (0x00000030&((data)<<4))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_17(data)                        (0x0000000C&((data)<<2))
#define  PCID_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_16(data)                        (0x00000003&(data))
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_31(data)                    ((0xC0000000&(data))>>30)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_30(data)                    ((0x30000000&(data))>>28)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_29(data)                    ((0x0C000000&(data))>>26)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_28(data)                    ((0x03000000&(data))>>24)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_27(data)                    ((0x00C00000&(data))>>22)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_26(data)                    ((0x00300000&(data))>>20)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_25(data)                    ((0x000C0000&(data))>>18)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_24(data)                    ((0x00030000&(data))>>16)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_23(data)                    ((0x0000C000&(data))>>14)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_22(data)                    ((0x00003000&(data))>>12)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_21(data)                    ((0x00000C00&(data))>>10)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_20(data)                    ((0x00000300&(data))>>8)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_19(data)                    ((0x000000C0&(data))>>6)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_18(data)                    ((0x00000030&(data))>>4)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_17(data)                    ((0x0000000C&(data))>>2)
#define  PCID_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_16(data)                    (0x00000003&(data))

#define  PCID_PCID_DITHER_TB_R_01                                                0x1802EF1C
#define  PCID_PCID_DITHER_TB_R_01_reg_addr                                       "0xB802EF1C"
#define  PCID_PCID_DITHER_TB_R_01_reg                                            0xB802EF1C
#define  PCID_PCID_DITHER_TB_R_01_inst_addr                                      "0x0007"
#define  set_PCID_PCID_DITHER_TB_R_01_reg(data)                                  (*((volatile unsigned int*)PCID_PCID_DITHER_TB_R_01_reg)=data)
#define  get_PCID_PCID_DITHER_TB_R_01_reg                                        (*((volatile unsigned int*)PCID_PCID_DITHER_TB_R_01_reg))
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_13_shift                            (28)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_12_shift                            (24)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_11_shift                            (20)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_10_shift                            (16)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_03_shift                            (12)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_02_shift                            (8)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_01_shift                            (4)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_00_shift                            (0)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_13_mask                             (0xF0000000)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_12_mask                             (0x0F000000)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_11_mask                             (0x00F00000)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_10_mask                             (0x000F0000)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_03_mask                             (0x0000F000)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_02_mask                             (0x00000F00)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_01_mask                             (0x000000F0)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_00_mask                             (0x0000000F)
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_13(data)                            (0xF0000000&((data)<<28))
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_12(data)                            (0x0F000000&((data)<<24))
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_11(data)                            (0x00F00000&((data)<<20))
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_10(data)                            (0x000F0000&((data)<<16))
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_03(data)                            (0x0000F000&((data)<<12))
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_02(data)                            (0x00000F00&((data)<<8))
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_01(data)                            (0x000000F0&((data)<<4))
#define  PCID_PCID_DITHER_TB_R_01_pcid_tab_r_00(data)                            (0x0000000F&(data))
#define  PCID_PCID_DITHER_TB_R_01_get_pcid_tab_r_13(data)                        ((0xF0000000&(data))>>28)
#define  PCID_PCID_DITHER_TB_R_01_get_pcid_tab_r_12(data)                        ((0x0F000000&(data))>>24)
#define  PCID_PCID_DITHER_TB_R_01_get_pcid_tab_r_11(data)                        ((0x00F00000&(data))>>20)
#define  PCID_PCID_DITHER_TB_R_01_get_pcid_tab_r_10(data)                        ((0x000F0000&(data))>>16)
#define  PCID_PCID_DITHER_TB_R_01_get_pcid_tab_r_03(data)                        ((0x0000F000&(data))>>12)
#define  PCID_PCID_DITHER_TB_R_01_get_pcid_tab_r_02(data)                        ((0x00000F00&(data))>>8)
#define  PCID_PCID_DITHER_TB_R_01_get_pcid_tab_r_01(data)                        ((0x000000F0&(data))>>4)
#define  PCID_PCID_DITHER_TB_R_01_get_pcid_tab_r_00(data)                        (0x0000000F&(data))

#define  PCID_PCID_DITHER_TB_R_23                                                0x1802EF20
#define  PCID_PCID_DITHER_TB_R_23_reg_addr                                       "0xB802EF20"
#define  PCID_PCID_DITHER_TB_R_23_reg                                            0xB802EF20
#define  PCID_PCID_DITHER_TB_R_23_inst_addr                                      "0x0008"
#define  set_PCID_PCID_DITHER_TB_R_23_reg(data)                                  (*((volatile unsigned int*)PCID_PCID_DITHER_TB_R_23_reg)=data)
#define  get_PCID_PCID_DITHER_TB_R_23_reg                                        (*((volatile unsigned int*)PCID_PCID_DITHER_TB_R_23_reg))
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_33_shift                            (28)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_32_shift                            (24)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_31_shift                            (20)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_30_shift                            (16)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_23_shift                            (12)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_22_shift                            (8)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_21_shift                            (4)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_20_shift                            (0)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_33_mask                             (0xF0000000)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_32_mask                             (0x0F000000)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_31_mask                             (0x00F00000)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_30_mask                             (0x000F0000)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_23_mask                             (0x0000F000)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_22_mask                             (0x00000F00)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_21_mask                             (0x000000F0)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_20_mask                             (0x0000000F)
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_33(data)                            (0xF0000000&((data)<<28))
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_32(data)                            (0x0F000000&((data)<<24))
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_31(data)                            (0x00F00000&((data)<<20))
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_30(data)                            (0x000F0000&((data)<<16))
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_23(data)                            (0x0000F000&((data)<<12))
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_22(data)                            (0x00000F00&((data)<<8))
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_21(data)                            (0x000000F0&((data)<<4))
#define  PCID_PCID_DITHER_TB_R_23_pcid_tab_r_20(data)                            (0x0000000F&(data))
#define  PCID_PCID_DITHER_TB_R_23_get_pcid_tab_r_33(data)                        ((0xF0000000&(data))>>28)
#define  PCID_PCID_DITHER_TB_R_23_get_pcid_tab_r_32(data)                        ((0x0F000000&(data))>>24)
#define  PCID_PCID_DITHER_TB_R_23_get_pcid_tab_r_31(data)                        ((0x00F00000&(data))>>20)
#define  PCID_PCID_DITHER_TB_R_23_get_pcid_tab_r_30(data)                        ((0x000F0000&(data))>>16)
#define  PCID_PCID_DITHER_TB_R_23_get_pcid_tab_r_23(data)                        ((0x0000F000&(data))>>12)
#define  PCID_PCID_DITHER_TB_R_23_get_pcid_tab_r_22(data)                        ((0x00000F00&(data))>>8)
#define  PCID_PCID_DITHER_TB_R_23_get_pcid_tab_r_21(data)                        ((0x000000F0&(data))>>4)
#define  PCID_PCID_DITHER_TB_R_23_get_pcid_tab_r_20(data)                        (0x0000000F&(data))

#define  PCID_PCID_DITHER_TB_G_01                                                0x1802EF24
#define  PCID_PCID_DITHER_TB_G_01_reg_addr                                       "0xB802EF24"
#define  PCID_PCID_DITHER_TB_G_01_reg                                            0xB802EF24
#define  PCID_PCID_DITHER_TB_G_01_inst_addr                                      "0x0009"
#define  set_PCID_PCID_DITHER_TB_G_01_reg(data)                                  (*((volatile unsigned int*)PCID_PCID_DITHER_TB_G_01_reg)=data)
#define  get_PCID_PCID_DITHER_TB_G_01_reg                                        (*((volatile unsigned int*)PCID_PCID_DITHER_TB_G_01_reg))
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_13_shift                            (28)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_12_shift                            (24)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_11_shift                            (20)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_10_shift                            (16)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_03_shift                            (12)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_02_shift                            (8)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_01_shift                            (4)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_00_shift                            (0)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_13_mask                             (0xF0000000)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_12_mask                             (0x0F000000)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_11_mask                             (0x00F00000)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_10_mask                             (0x000F0000)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_03_mask                             (0x0000F000)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_02_mask                             (0x00000F00)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_01_mask                             (0x000000F0)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_00_mask                             (0x0000000F)
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_13(data)                            (0xF0000000&((data)<<28))
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_12(data)                            (0x0F000000&((data)<<24))
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_11(data)                            (0x00F00000&((data)<<20))
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_10(data)                            (0x000F0000&((data)<<16))
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_03(data)                            (0x0000F000&((data)<<12))
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_02(data)                            (0x00000F00&((data)<<8))
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_01(data)                            (0x000000F0&((data)<<4))
#define  PCID_PCID_DITHER_TB_G_01_pcid_tab_g_00(data)                            (0x0000000F&(data))
#define  PCID_PCID_DITHER_TB_G_01_get_pcid_tab_g_13(data)                        ((0xF0000000&(data))>>28)
#define  PCID_PCID_DITHER_TB_G_01_get_pcid_tab_g_12(data)                        ((0x0F000000&(data))>>24)
#define  PCID_PCID_DITHER_TB_G_01_get_pcid_tab_g_11(data)                        ((0x00F00000&(data))>>20)
#define  PCID_PCID_DITHER_TB_G_01_get_pcid_tab_g_10(data)                        ((0x000F0000&(data))>>16)
#define  PCID_PCID_DITHER_TB_G_01_get_pcid_tab_g_03(data)                        ((0x0000F000&(data))>>12)
#define  PCID_PCID_DITHER_TB_G_01_get_pcid_tab_g_02(data)                        ((0x00000F00&(data))>>8)
#define  PCID_PCID_DITHER_TB_G_01_get_pcid_tab_g_01(data)                        ((0x000000F0&(data))>>4)
#define  PCID_PCID_DITHER_TB_G_01_get_pcid_tab_g_00(data)                        (0x0000000F&(data))

#define  PCID_PCID_DITHER_TB_G_23                                                0x1802EF28
#define  PCID_PCID_DITHER_TB_G_23_reg_addr                                       "0xB802EF28"
#define  PCID_PCID_DITHER_TB_G_23_reg                                            0xB802EF28
#define  PCID_PCID_DITHER_TB_G_23_inst_addr                                      "0x000A"
#define  set_PCID_PCID_DITHER_TB_G_23_reg(data)                                  (*((volatile unsigned int*)PCID_PCID_DITHER_TB_G_23_reg)=data)
#define  get_PCID_PCID_DITHER_TB_G_23_reg                                        (*((volatile unsigned int*)PCID_PCID_DITHER_TB_G_23_reg))
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_33_shift                            (28)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_32_shift                            (24)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_31_shift                            (20)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_30_shift                            (16)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_23_shift                            (12)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_22_shift                            (8)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_21_shift                            (4)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_20_shift                            (0)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_33_mask                             (0xF0000000)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_32_mask                             (0x0F000000)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_31_mask                             (0x00F00000)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_30_mask                             (0x000F0000)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_23_mask                             (0x0000F000)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_22_mask                             (0x00000F00)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_21_mask                             (0x000000F0)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_20_mask                             (0x0000000F)
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_33(data)                            (0xF0000000&((data)<<28))
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_32(data)                            (0x0F000000&((data)<<24))
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_31(data)                            (0x00F00000&((data)<<20))
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_30(data)                            (0x000F0000&((data)<<16))
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_23(data)                            (0x0000F000&((data)<<12))
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_22(data)                            (0x00000F00&((data)<<8))
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_21(data)                            (0x000000F0&((data)<<4))
#define  PCID_PCID_DITHER_TB_G_23_pcid_tab_g_20(data)                            (0x0000000F&(data))
#define  PCID_PCID_DITHER_TB_G_23_get_pcid_tab_g_33(data)                        ((0xF0000000&(data))>>28)
#define  PCID_PCID_DITHER_TB_G_23_get_pcid_tab_g_32(data)                        ((0x0F000000&(data))>>24)
#define  PCID_PCID_DITHER_TB_G_23_get_pcid_tab_g_31(data)                        ((0x00F00000&(data))>>20)
#define  PCID_PCID_DITHER_TB_G_23_get_pcid_tab_g_30(data)                        ((0x000F0000&(data))>>16)
#define  PCID_PCID_DITHER_TB_G_23_get_pcid_tab_g_23(data)                        ((0x0000F000&(data))>>12)
#define  PCID_PCID_DITHER_TB_G_23_get_pcid_tab_g_22(data)                        ((0x00000F00&(data))>>8)
#define  PCID_PCID_DITHER_TB_G_23_get_pcid_tab_g_21(data)                        ((0x000000F0&(data))>>4)
#define  PCID_PCID_DITHER_TB_G_23_get_pcid_tab_g_20(data)                        (0x0000000F&(data))

#define  PCID_PCID_DITHER_TB_B_01                                                0x1802EF2C
#define  PCID_PCID_DITHER_TB_B_01_reg_addr                                       "0xB802EF2C"
#define  PCID_PCID_DITHER_TB_B_01_reg                                            0xB802EF2C
#define  PCID_PCID_DITHER_TB_B_01_inst_addr                                      "0x000B"
#define  set_PCID_PCID_DITHER_TB_B_01_reg(data)                                  (*((volatile unsigned int*)PCID_PCID_DITHER_TB_B_01_reg)=data)
#define  get_PCID_PCID_DITHER_TB_B_01_reg                                        (*((volatile unsigned int*)PCID_PCID_DITHER_TB_B_01_reg))
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_13_shift                            (28)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_12_shift                            (24)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_11_shift                            (20)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_10_shift                            (16)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_03_shift                            (12)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_02_shift                            (8)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_01_shift                            (4)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_00_shift                            (0)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_13_mask                             (0xF0000000)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_12_mask                             (0x0F000000)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_11_mask                             (0x00F00000)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_10_mask                             (0x000F0000)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_03_mask                             (0x0000F000)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_02_mask                             (0x00000F00)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_01_mask                             (0x000000F0)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_00_mask                             (0x0000000F)
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_13(data)                            (0xF0000000&((data)<<28))
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_12(data)                            (0x0F000000&((data)<<24))
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_11(data)                            (0x00F00000&((data)<<20))
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_10(data)                            (0x000F0000&((data)<<16))
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_03(data)                            (0x0000F000&((data)<<12))
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_02(data)                            (0x00000F00&((data)<<8))
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_01(data)                            (0x000000F0&((data)<<4))
#define  PCID_PCID_DITHER_TB_B_01_pcid_tab_b_00(data)                            (0x0000000F&(data))
#define  PCID_PCID_DITHER_TB_B_01_get_pcid_tab_b_13(data)                        ((0xF0000000&(data))>>28)
#define  PCID_PCID_DITHER_TB_B_01_get_pcid_tab_b_12(data)                        ((0x0F000000&(data))>>24)
#define  PCID_PCID_DITHER_TB_B_01_get_pcid_tab_b_11(data)                        ((0x00F00000&(data))>>20)
#define  PCID_PCID_DITHER_TB_B_01_get_pcid_tab_b_10(data)                        ((0x000F0000&(data))>>16)
#define  PCID_PCID_DITHER_TB_B_01_get_pcid_tab_b_03(data)                        ((0x0000F000&(data))>>12)
#define  PCID_PCID_DITHER_TB_B_01_get_pcid_tab_b_02(data)                        ((0x00000F00&(data))>>8)
#define  PCID_PCID_DITHER_TB_B_01_get_pcid_tab_b_01(data)                        ((0x000000F0&(data))>>4)
#define  PCID_PCID_DITHER_TB_B_01_get_pcid_tab_b_00(data)                        (0x0000000F&(data))

#define  PCID_PCID_DITHER_TB_B_23                                                0x1802EF30
#define  PCID_PCID_DITHER_TB_B_23_reg_addr                                       "0xB802EF30"
#define  PCID_PCID_DITHER_TB_B_23_reg                                            0xB802EF30
#define  PCID_PCID_DITHER_TB_B_23_inst_addr                                      "0x000C"
#define  set_PCID_PCID_DITHER_TB_B_23_reg(data)                                  (*((volatile unsigned int*)PCID_PCID_DITHER_TB_B_23_reg)=data)
#define  get_PCID_PCID_DITHER_TB_B_23_reg                                        (*((volatile unsigned int*)PCID_PCID_DITHER_TB_B_23_reg))
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_33_shift                            (28)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_32_shift                            (24)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_31_shift                            (20)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_30_shift                            (16)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_23_shift                            (12)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_22_shift                            (8)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_21_shift                            (4)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_20_shift                            (0)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_33_mask                             (0xF0000000)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_32_mask                             (0x0F000000)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_31_mask                             (0x00F00000)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_30_mask                             (0x000F0000)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_23_mask                             (0x0000F000)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_22_mask                             (0x00000F00)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_21_mask                             (0x000000F0)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_20_mask                             (0x0000000F)
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_33(data)                            (0xF0000000&((data)<<28))
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_32(data)                            (0x0F000000&((data)<<24))
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_31(data)                            (0x00F00000&((data)<<20))
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_30(data)                            (0x000F0000&((data)<<16))
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_23(data)                            (0x0000F000&((data)<<12))
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_22(data)                            (0x00000F00&((data)<<8))
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_21(data)                            (0x000000F0&((data)<<4))
#define  PCID_PCID_DITHER_TB_B_23_pcid_tab_b_20(data)                            (0x0000000F&(data))
#define  PCID_PCID_DITHER_TB_B_23_get_pcid_tab_b_33(data)                        ((0xF0000000&(data))>>28)
#define  PCID_PCID_DITHER_TB_B_23_get_pcid_tab_b_32(data)                        ((0x0F000000&(data))>>24)
#define  PCID_PCID_DITHER_TB_B_23_get_pcid_tab_b_31(data)                        ((0x00F00000&(data))>>20)
#define  PCID_PCID_DITHER_TB_B_23_get_pcid_tab_b_30(data)                        ((0x000F0000&(data))>>16)
#define  PCID_PCID_DITHER_TB_B_23_get_pcid_tab_b_23(data)                        ((0x0000F000&(data))>>12)
#define  PCID_PCID_DITHER_TB_B_23_get_pcid_tab_b_22(data)                        ((0x00000F00&(data))>>8)
#define  PCID_PCID_DITHER_TB_B_23_get_pcid_tab_b_21(data)                        ((0x000000F0&(data))>>4)
#define  PCID_PCID_DITHER_TB_B_23_get_pcid_tab_b_20(data)                        (0x0000000F&(data))

#define  PCID_PCID_DITHER_Temp                                                   0x1802EF34
#define  PCID_PCID_DITHER_Temp_reg_addr                                          "0xB802EF34"
#define  PCID_PCID_DITHER_Temp_reg                                               0xB802EF34
#define  PCID_PCID_DITHER_Temp_inst_addr                                         "0x000D"
#define  set_PCID_PCID_DITHER_Temp_reg(data)                                     (*((volatile unsigned int*)PCID_PCID_DITHER_Temp_reg)=data)
#define  get_PCID_PCID_DITHER_Temp_reg                                           (*((volatile unsigned int*)PCID_PCID_DITHER_Temp_reg))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_15_shift                         (30)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_14_shift                         (28)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_13_shift                         (26)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_12_shift                         (24)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_11_shift                         (22)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_10_shift                         (20)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_9_shift                          (18)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_8_shift                          (16)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_7_shift                          (14)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_6_shift                          (12)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_5_shift                          (10)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_4_shift                          (8)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_3_shift                          (6)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_2_shift                          (4)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_1_shift                          (2)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_0_shift                          (0)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_15_mask                          (0xC0000000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_14_mask                          (0x30000000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_13_mask                          (0x0C000000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_12_mask                          (0x03000000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_11_mask                          (0x00C00000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_10_mask                          (0x00300000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_9_mask                           (0x000C0000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_8_mask                           (0x00030000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_7_mask                           (0x0000C000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_6_mask                           (0x00003000)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_5_mask                           (0x00000C00)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_4_mask                           (0x00000300)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_3_mask                           (0x000000C0)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_2_mask                           (0x00000030)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_1_mask                           (0x0000000C)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_0_mask                           (0x00000003)
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_15(data)                         (0xC0000000&((data)<<30))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_14(data)                         (0x30000000&((data)<<28))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_13(data)                         (0x0C000000&((data)<<26))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_12(data)                         (0x03000000&((data)<<24))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_11(data)                         (0x00C00000&((data)<<22))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_10(data)                         (0x00300000&((data)<<20))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_9(data)                          (0x000C0000&((data)<<18))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_8(data)                          (0x00030000&((data)<<16))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_7(data)                          (0x0000C000&((data)<<14))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_6(data)                          (0x00003000&((data)<<12))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_5(data)                          (0x00000C00&((data)<<10))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_4(data)                          (0x00000300&((data)<<8))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_3(data)                          (0x000000C0&((data)<<6))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_2(data)                          (0x00000030&((data)<<4))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_1(data)                          (0x0000000C&((data)<<2))
#define  PCID_PCID_DITHER_Temp_pcid_temp_offset_0(data)                          (0x00000003&(data))
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_15(data)                     ((0xC0000000&(data))>>30)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_14(data)                     ((0x30000000&(data))>>28)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_13(data)                     ((0x0C000000&(data))>>26)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_12(data)                     ((0x03000000&(data))>>24)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_11(data)                     ((0x00C00000&(data))>>22)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_10(data)                     ((0x00300000&(data))>>20)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_9(data)                      ((0x000C0000&(data))>>18)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_8(data)                      ((0x00030000&(data))>>16)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_7(data)                      ((0x0000C000&(data))>>14)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_6(data)                      ((0x00003000&(data))>>12)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_5(data)                      ((0x00000C00&(data))>>10)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_4(data)                      ((0x00000300&(data))>>8)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_3(data)                      ((0x000000C0&(data))>>6)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_2(data)                      ((0x00000030&(data))>>4)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_1(data)                      ((0x0000000C&(data))>>2)
#define  PCID_PCID_DITHER_Temp_get_pcid_temp_offset_0(data)                      (0x00000003&(data))

#define  PCID_PCID_CTRL                                                          0x1802EF40
#define  PCID_PCID_CTRL_reg_addr                                                 "0xB802EF40"
#define  PCID_PCID_CTRL_reg                                                      0xB802EF40
#define  PCID_PCID_CTRL_inst_addr                                                "0x000E"
#define  set_PCID_PCID_CTRL_reg(data)                                            (*((volatile unsigned int*)PCID_PCID_CTRL_reg)=data)
#define  get_PCID_PCID_CTRL_reg                                                  (*((volatile unsigned int*)PCID_PCID_CTRL_reg))
#define  PCID_PCID_CTRL_dummy_31_14_shift                                        (14)
#define  PCID_PCID_CTRL_lsb_add_nr_thd_shift                                     (8)
#define  PCID_PCID_CTRL_lsb_add_slope_check_en_shift                             (6)
#define  PCID_PCID_CTRL_lsb_add_nr_en_shift                                      (5)
#define  PCID_PCID_CTRL_lsb_add_en_shift                                         (4)
#define  PCID_PCID_CTRL_ref_4line_shift                                          (1)
#define  PCID_PCID_CTRL_boundary_mode_shift                                      (0)
#define  PCID_PCID_CTRL_dummy_31_14_mask                                         (0xFFFFC000)
#define  PCID_PCID_CTRL_lsb_add_nr_thd_mask                                      (0x00003F00)
#define  PCID_PCID_CTRL_lsb_add_slope_check_en_mask                              (0x00000040)
#define  PCID_PCID_CTRL_lsb_add_nr_en_mask                                       (0x00000020)
#define  PCID_PCID_CTRL_lsb_add_en_mask                                          (0x00000010)
#define  PCID_PCID_CTRL_ref_4line_mask                                           (0x00000002)
#define  PCID_PCID_CTRL_boundary_mode_mask                                       (0x00000001)
#define  PCID_PCID_CTRL_dummy_31_14(data)                                        (0xFFFFC000&((data)<<14))
#define  PCID_PCID_CTRL_lsb_add_nr_thd(data)                                     (0x00003F00&((data)<<8))
#define  PCID_PCID_CTRL_lsb_add_slope_check_en(data)                             (0x00000040&((data)<<6))
#define  PCID_PCID_CTRL_lsb_add_nr_en(data)                                      (0x00000020&((data)<<5))
#define  PCID_PCID_CTRL_lsb_add_en(data)                                         (0x00000010&((data)<<4))
#define  PCID_PCID_CTRL_ref_4line(data)                                          (0x00000002&((data)<<1))
#define  PCID_PCID_CTRL_boundary_mode(data)                                      (0x00000001&(data))
#define  PCID_PCID_CTRL_get_dummy_31_14(data)                                    ((0xFFFFC000&(data))>>14)
#define  PCID_PCID_CTRL_get_lsb_add_nr_thd(data)                                 ((0x00003F00&(data))>>8)
#define  PCID_PCID_CTRL_get_lsb_add_slope_check_en(data)                         ((0x00000040&(data))>>6)
#define  PCID_PCID_CTRL_get_lsb_add_nr_en(data)                                  ((0x00000020&(data))>>5)
#define  PCID_PCID_CTRL_get_lsb_add_en(data)                                     ((0x00000010&(data))>>4)
#define  PCID_PCID_CTRL_get_ref_4line(data)                                      ((0x00000002&(data))>>1)
#define  PCID_PCID_CTRL_get_boundary_mode(data)                                  (0x00000001&(data))

#define  PCID_PCID_CTRL_2                                                        0x1802EF44
#define  PCID_PCID_CTRL_2_reg_addr                                               "0xB802EF44"
#define  PCID_PCID_CTRL_2_reg                                                    0xB802EF44
#define  PCID_PCID_CTRL_2_inst_addr                                              "0x000F"
#define  set_PCID_PCID_CTRL_2_reg(data)                                          (*((volatile unsigned int*)PCID_PCID_CTRL_2_reg)=data)
#define  get_PCID_PCID_CTRL_2_reg                                                (*((volatile unsigned int*)PCID_PCID_CTRL_2_reg))
#define  PCID_PCID_CTRL_2_pcid_tab1_xtr_en_shift                                 (30)
#define  PCID_PCID_CTRL_2_pcid_thd_mode_shift                                    (29)
#define  PCID_PCID_CTRL_2_pcid_thd_en_shift                                      (28)
#define  PCID_PCID_CTRL_2_pcid_tab1_b_thd_shift                                  (16)
#define  PCID_PCID_CTRL_2_pcid_tab1_g_thd_shift                                  (8)
#define  PCID_PCID_CTRL_2_pcid_tab1_r_thd_shift                                  (0)
#define  PCID_PCID_CTRL_2_pcid_tab1_xtr_en_mask                                  (0x40000000)
#define  PCID_PCID_CTRL_2_pcid_thd_mode_mask                                     (0x20000000)
#define  PCID_PCID_CTRL_2_pcid_thd_en_mask                                       (0x10000000)
#define  PCID_PCID_CTRL_2_pcid_tab1_b_thd_mask                                   (0x00FF0000)
#define  PCID_PCID_CTRL_2_pcid_tab1_g_thd_mask                                   (0x0000FF00)
#define  PCID_PCID_CTRL_2_pcid_tab1_r_thd_mask                                   (0x000000FF)
#define  PCID_PCID_CTRL_2_pcid_tab1_xtr_en(data)                                 (0x40000000&((data)<<30))
#define  PCID_PCID_CTRL_2_pcid_thd_mode(data)                                    (0x20000000&((data)<<29))
#define  PCID_PCID_CTRL_2_pcid_thd_en(data)                                      (0x10000000&((data)<<28))
#define  PCID_PCID_CTRL_2_pcid_tab1_b_thd(data)                                  (0x00FF0000&((data)<<16))
#define  PCID_PCID_CTRL_2_pcid_tab1_g_thd(data)                                  (0x0000FF00&((data)<<8))
#define  PCID_PCID_CTRL_2_pcid_tab1_r_thd(data)                                  (0x000000FF&(data))
#define  PCID_PCID_CTRL_2_get_pcid_tab1_xtr_en(data)                             ((0x40000000&(data))>>30)
#define  PCID_PCID_CTRL_2_get_pcid_thd_mode(data)                                ((0x20000000&(data))>>29)
#define  PCID_PCID_CTRL_2_get_pcid_thd_en(data)                                  ((0x10000000&(data))>>28)
#define  PCID_PCID_CTRL_2_get_pcid_tab1_b_thd(data)                              ((0x00FF0000&(data))>>16)
#define  PCID_PCID_CTRL_2_get_pcid_tab1_g_thd(data)                              ((0x0000FF00&(data))>>8)
#define  PCID_PCID_CTRL_2_get_pcid_tab1_r_thd(data)                              (0x000000FF&(data))

#define  PCID_PCID_LINE_1                                                        0x1802EF50
#define  PCID_PCID_LINE_1_reg_addr                                               "0xB802EF50"
#define  PCID_PCID_LINE_1_reg                                                    0xB802EF50
#define  PCID_PCID_LINE_1_inst_addr                                              "0x0010"
#define  set_PCID_PCID_LINE_1_reg(data)                                          (*((volatile unsigned int*)PCID_PCID_LINE_1_reg)=data)
#define  get_PCID_PCID_LINE_1_reg                                                (*((volatile unsigned int*)PCID_PCID_LINE_1_reg))
#define  PCID_PCID_LINE_1_line1_odd_b_color_select_shift                         (30)
#define  PCID_PCID_LINE_1_line1_odd_g_color_select_shift                         (28)
#define  PCID_PCID_LINE_1_line1_odd_r_color_select_shift                         (26)
#define  PCID_PCID_LINE_1_line1_odd_b_point_select_shift                         (24)
#define  PCID_PCID_LINE_1_line1_odd_g_point_select_shift                         (22)
#define  PCID_PCID_LINE_1_line1_odd_r_point_select_shift                         (20)
#define  PCID_PCID_LINE_1_line1_odd_b_line_select_shift                          (18)
#define  PCID_PCID_LINE_1_line1_odd_g_line_select_shift                          (17)
#define  PCID_PCID_LINE_1_line1_odd_r_line_select_shift                          (16)
#define  PCID_PCID_LINE_1_line1_even_b_color_select_shift                        (14)
#define  PCID_PCID_LINE_1_line1_even_g_color_select_shift                        (12)
#define  PCID_PCID_LINE_1_line1_even_r_color_select_shift                        (10)
#define  PCID_PCID_LINE_1_line1_even_b_point_select_shift                        (8)
#define  PCID_PCID_LINE_1_line1_even_g_point_select_shift                        (6)
#define  PCID_PCID_LINE_1_line1_even_r_point_select_shift                        (4)
#define  PCID_PCID_LINE_1_line1_even_b_line_select_shift                         (2)
#define  PCID_PCID_LINE_1_line1_even_g_line_select_shift                         (1)
#define  PCID_PCID_LINE_1_line1_even_r_line_select_shift                         (0)
#define  PCID_PCID_LINE_1_line1_odd_b_color_select_mask                          (0xC0000000)
#define  PCID_PCID_LINE_1_line1_odd_g_color_select_mask                          (0x30000000)
#define  PCID_PCID_LINE_1_line1_odd_r_color_select_mask                          (0x0C000000)
#define  PCID_PCID_LINE_1_line1_odd_b_point_select_mask                          (0x03000000)
#define  PCID_PCID_LINE_1_line1_odd_g_point_select_mask                          (0x00C00000)
#define  PCID_PCID_LINE_1_line1_odd_r_point_select_mask                          (0x00300000)
#define  PCID_PCID_LINE_1_line1_odd_b_line_select_mask                           (0x00040000)
#define  PCID_PCID_LINE_1_line1_odd_g_line_select_mask                           (0x00020000)
#define  PCID_PCID_LINE_1_line1_odd_r_line_select_mask                           (0x00010000)
#define  PCID_PCID_LINE_1_line1_even_b_color_select_mask                         (0x0000C000)
#define  PCID_PCID_LINE_1_line1_even_g_color_select_mask                         (0x00003000)
#define  PCID_PCID_LINE_1_line1_even_r_color_select_mask                         (0x00000C00)
#define  PCID_PCID_LINE_1_line1_even_b_point_select_mask                         (0x00000300)
#define  PCID_PCID_LINE_1_line1_even_g_point_select_mask                         (0x000000C0)
#define  PCID_PCID_LINE_1_line1_even_r_point_select_mask                         (0x00000030)
#define  PCID_PCID_LINE_1_line1_even_b_line_select_mask                          (0x00000004)
#define  PCID_PCID_LINE_1_line1_even_g_line_select_mask                          (0x00000002)
#define  PCID_PCID_LINE_1_line1_even_r_line_select_mask                          (0x00000001)
#define  PCID_PCID_LINE_1_line1_odd_b_color_select(data)                         (0xC0000000&((data)<<30))
#define  PCID_PCID_LINE_1_line1_odd_g_color_select(data)                         (0x30000000&((data)<<28))
#define  PCID_PCID_LINE_1_line1_odd_r_color_select(data)                         (0x0C000000&((data)<<26))
#define  PCID_PCID_LINE_1_line1_odd_b_point_select(data)                         (0x03000000&((data)<<24))
#define  PCID_PCID_LINE_1_line1_odd_g_point_select(data)                         (0x00C00000&((data)<<22))
#define  PCID_PCID_LINE_1_line1_odd_r_point_select(data)                         (0x00300000&((data)<<20))
#define  PCID_PCID_LINE_1_line1_odd_b_line_select(data)                          (0x00040000&((data)<<18))
#define  PCID_PCID_LINE_1_line1_odd_g_line_select(data)                          (0x00020000&((data)<<17))
#define  PCID_PCID_LINE_1_line1_odd_r_line_select(data)                          (0x00010000&((data)<<16))
#define  PCID_PCID_LINE_1_line1_even_b_color_select(data)                        (0x0000C000&((data)<<14))
#define  PCID_PCID_LINE_1_line1_even_g_color_select(data)                        (0x00003000&((data)<<12))
#define  PCID_PCID_LINE_1_line1_even_r_color_select(data)                        (0x00000C00&((data)<<10))
#define  PCID_PCID_LINE_1_line1_even_b_point_select(data)                        (0x00000300&((data)<<8))
#define  PCID_PCID_LINE_1_line1_even_g_point_select(data)                        (0x000000C0&((data)<<6))
#define  PCID_PCID_LINE_1_line1_even_r_point_select(data)                        (0x00000030&((data)<<4))
#define  PCID_PCID_LINE_1_line1_even_b_line_select(data)                         (0x00000004&((data)<<2))
#define  PCID_PCID_LINE_1_line1_even_g_line_select(data)                         (0x00000002&((data)<<1))
#define  PCID_PCID_LINE_1_line1_even_r_line_select(data)                         (0x00000001&(data))
#define  PCID_PCID_LINE_1_get_line1_odd_b_color_select(data)                     ((0xC0000000&(data))>>30)
#define  PCID_PCID_LINE_1_get_line1_odd_g_color_select(data)                     ((0x30000000&(data))>>28)
#define  PCID_PCID_LINE_1_get_line1_odd_r_color_select(data)                     ((0x0C000000&(data))>>26)
#define  PCID_PCID_LINE_1_get_line1_odd_b_point_select(data)                     ((0x03000000&(data))>>24)
#define  PCID_PCID_LINE_1_get_line1_odd_g_point_select(data)                     ((0x00C00000&(data))>>22)
#define  PCID_PCID_LINE_1_get_line1_odd_r_point_select(data)                     ((0x00300000&(data))>>20)
#define  PCID_PCID_LINE_1_get_line1_odd_b_line_select(data)                      ((0x00040000&(data))>>18)
#define  PCID_PCID_LINE_1_get_line1_odd_g_line_select(data)                      ((0x00020000&(data))>>17)
#define  PCID_PCID_LINE_1_get_line1_odd_r_line_select(data)                      ((0x00010000&(data))>>16)
#define  PCID_PCID_LINE_1_get_line1_even_b_color_select(data)                    ((0x0000C000&(data))>>14)
#define  PCID_PCID_LINE_1_get_line1_even_g_color_select(data)                    ((0x00003000&(data))>>12)
#define  PCID_PCID_LINE_1_get_line1_even_r_color_select(data)                    ((0x00000C00&(data))>>10)
#define  PCID_PCID_LINE_1_get_line1_even_b_point_select(data)                    ((0x00000300&(data))>>8)
#define  PCID_PCID_LINE_1_get_line1_even_g_point_select(data)                    ((0x000000C0&(data))>>6)
#define  PCID_PCID_LINE_1_get_line1_even_r_point_select(data)                    ((0x00000030&(data))>>4)
#define  PCID_PCID_LINE_1_get_line1_even_b_line_select(data)                     ((0x00000004&(data))>>2)
#define  PCID_PCID_LINE_1_get_line1_even_g_line_select(data)                     ((0x00000002&(data))>>1)
#define  PCID_PCID_LINE_1_get_line1_even_r_line_select(data)                     (0x00000001&(data))

#define  PCID_PCID_LINE_2                                                        0x1802EF54
#define  PCID_PCID_LINE_2_reg_addr                                               "0xB802EF54"
#define  PCID_PCID_LINE_2_reg                                                    0xB802EF54
#define  PCID_PCID_LINE_2_inst_addr                                              "0x0011"
#define  set_PCID_PCID_LINE_2_reg(data)                                          (*((volatile unsigned int*)PCID_PCID_LINE_2_reg)=data)
#define  get_PCID_PCID_LINE_2_reg                                                (*((volatile unsigned int*)PCID_PCID_LINE_2_reg))
#define  PCID_PCID_LINE_2_line2_odd_b_color_select_shift                         (30)
#define  PCID_PCID_LINE_2_line2_odd_g_color_select_shift                         (28)
#define  PCID_PCID_LINE_2_line2_odd_r_color_select_shift                         (26)
#define  PCID_PCID_LINE_2_line2_odd_b_point_select_shift                         (24)
#define  PCID_PCID_LINE_2_line2_odd_g_point_select_shift                         (22)
#define  PCID_PCID_LINE_2_line2_odd_r_point_select_shift                         (20)
#define  PCID_PCID_LINE_2_line2_odd_b_line_select_shift                          (18)
#define  PCID_PCID_LINE_2_line2_odd_g_line_select_shift                          (17)
#define  PCID_PCID_LINE_2_line2_odd_r_line_select_shift                          (16)
#define  PCID_PCID_LINE_2_line2_even_b_color_select_shift                        (14)
#define  PCID_PCID_LINE_2_line2_even_g_color_select_shift                        (12)
#define  PCID_PCID_LINE_2_line2_even_r_color_select_shift                        (10)
#define  PCID_PCID_LINE_2_line2_even_b_point_select_shift                        (8)
#define  PCID_PCID_LINE_2_line2_even_g_point_select_shift                        (6)
#define  PCID_PCID_LINE_2_line2_even_r_point_select_shift                        (4)
#define  PCID_PCID_LINE_2_line2_even_b_line_select_shift                         (2)
#define  PCID_PCID_LINE_2_line2_even_g_line_select_shift                         (1)
#define  PCID_PCID_LINE_2_line2_even_r_line_select_shift                         (0)
#define  PCID_PCID_LINE_2_line2_odd_b_color_select_mask                          (0xC0000000)
#define  PCID_PCID_LINE_2_line2_odd_g_color_select_mask                          (0x30000000)
#define  PCID_PCID_LINE_2_line2_odd_r_color_select_mask                          (0x0C000000)
#define  PCID_PCID_LINE_2_line2_odd_b_point_select_mask                          (0x03000000)
#define  PCID_PCID_LINE_2_line2_odd_g_point_select_mask                          (0x00C00000)
#define  PCID_PCID_LINE_2_line2_odd_r_point_select_mask                          (0x00300000)
#define  PCID_PCID_LINE_2_line2_odd_b_line_select_mask                           (0x00040000)
#define  PCID_PCID_LINE_2_line2_odd_g_line_select_mask                           (0x00020000)
#define  PCID_PCID_LINE_2_line2_odd_r_line_select_mask                           (0x00010000)
#define  PCID_PCID_LINE_2_line2_even_b_color_select_mask                         (0x0000C000)
#define  PCID_PCID_LINE_2_line2_even_g_color_select_mask                         (0x00003000)
#define  PCID_PCID_LINE_2_line2_even_r_color_select_mask                         (0x00000C00)
#define  PCID_PCID_LINE_2_line2_even_b_point_select_mask                         (0x00000300)
#define  PCID_PCID_LINE_2_line2_even_g_point_select_mask                         (0x000000C0)
#define  PCID_PCID_LINE_2_line2_even_r_point_select_mask                         (0x00000030)
#define  PCID_PCID_LINE_2_line2_even_b_line_select_mask                          (0x00000004)
#define  PCID_PCID_LINE_2_line2_even_g_line_select_mask                          (0x00000002)
#define  PCID_PCID_LINE_2_line2_even_r_line_select_mask                          (0x00000001)
#define  PCID_PCID_LINE_2_line2_odd_b_color_select(data)                         (0xC0000000&((data)<<30))
#define  PCID_PCID_LINE_2_line2_odd_g_color_select(data)                         (0x30000000&((data)<<28))
#define  PCID_PCID_LINE_2_line2_odd_r_color_select(data)                         (0x0C000000&((data)<<26))
#define  PCID_PCID_LINE_2_line2_odd_b_point_select(data)                         (0x03000000&((data)<<24))
#define  PCID_PCID_LINE_2_line2_odd_g_point_select(data)                         (0x00C00000&((data)<<22))
#define  PCID_PCID_LINE_2_line2_odd_r_point_select(data)                         (0x00300000&((data)<<20))
#define  PCID_PCID_LINE_2_line2_odd_b_line_select(data)                          (0x00040000&((data)<<18))
#define  PCID_PCID_LINE_2_line2_odd_g_line_select(data)                          (0x00020000&((data)<<17))
#define  PCID_PCID_LINE_2_line2_odd_r_line_select(data)                          (0x00010000&((data)<<16))
#define  PCID_PCID_LINE_2_line2_even_b_color_select(data)                        (0x0000C000&((data)<<14))
#define  PCID_PCID_LINE_2_line2_even_g_color_select(data)                        (0x00003000&((data)<<12))
#define  PCID_PCID_LINE_2_line2_even_r_color_select(data)                        (0x00000C00&((data)<<10))
#define  PCID_PCID_LINE_2_line2_even_b_point_select(data)                        (0x00000300&((data)<<8))
#define  PCID_PCID_LINE_2_line2_even_g_point_select(data)                        (0x000000C0&((data)<<6))
#define  PCID_PCID_LINE_2_line2_even_r_point_select(data)                        (0x00000030&((data)<<4))
#define  PCID_PCID_LINE_2_line2_even_b_line_select(data)                         (0x00000004&((data)<<2))
#define  PCID_PCID_LINE_2_line2_even_g_line_select(data)                         (0x00000002&((data)<<1))
#define  PCID_PCID_LINE_2_line2_even_r_line_select(data)                         (0x00000001&(data))
#define  PCID_PCID_LINE_2_get_line2_odd_b_color_select(data)                     ((0xC0000000&(data))>>30)
#define  PCID_PCID_LINE_2_get_line2_odd_g_color_select(data)                     ((0x30000000&(data))>>28)
#define  PCID_PCID_LINE_2_get_line2_odd_r_color_select(data)                     ((0x0C000000&(data))>>26)
#define  PCID_PCID_LINE_2_get_line2_odd_b_point_select(data)                     ((0x03000000&(data))>>24)
#define  PCID_PCID_LINE_2_get_line2_odd_g_point_select(data)                     ((0x00C00000&(data))>>22)
#define  PCID_PCID_LINE_2_get_line2_odd_r_point_select(data)                     ((0x00300000&(data))>>20)
#define  PCID_PCID_LINE_2_get_line2_odd_b_line_select(data)                      ((0x00040000&(data))>>18)
#define  PCID_PCID_LINE_2_get_line2_odd_g_line_select(data)                      ((0x00020000&(data))>>17)
#define  PCID_PCID_LINE_2_get_line2_odd_r_line_select(data)                      ((0x00010000&(data))>>16)
#define  PCID_PCID_LINE_2_get_line2_even_b_color_select(data)                    ((0x0000C000&(data))>>14)
#define  PCID_PCID_LINE_2_get_line2_even_g_color_select(data)                    ((0x00003000&(data))>>12)
#define  PCID_PCID_LINE_2_get_line2_even_r_color_select(data)                    ((0x00000C00&(data))>>10)
#define  PCID_PCID_LINE_2_get_line2_even_b_point_select(data)                    ((0x00000300&(data))>>8)
#define  PCID_PCID_LINE_2_get_line2_even_g_point_select(data)                    ((0x000000C0&(data))>>6)
#define  PCID_PCID_LINE_2_get_line2_even_r_point_select(data)                    ((0x00000030&(data))>>4)
#define  PCID_PCID_LINE_2_get_line2_even_b_line_select(data)                     ((0x00000004&(data))>>2)
#define  PCID_PCID_LINE_2_get_line2_even_g_line_select(data)                     ((0x00000002&(data))>>1)
#define  PCID_PCID_LINE_2_get_line2_even_r_line_select(data)                     (0x00000001&(data))

#define  PCID_PCID_LINE_3                                                        0x1802EF58
#define  PCID_PCID_LINE_3_reg_addr                                               "0xB802EF58"
#define  PCID_PCID_LINE_3_reg                                                    0xB802EF58
#define  PCID_PCID_LINE_3_inst_addr                                              "0x0012"
#define  set_PCID_PCID_LINE_3_reg(data)                                          (*((volatile unsigned int*)PCID_PCID_LINE_3_reg)=data)
#define  get_PCID_PCID_LINE_3_reg                                                (*((volatile unsigned int*)PCID_PCID_LINE_3_reg))
#define  PCID_PCID_LINE_3_line3_odd_b_color_select_shift                         (30)
#define  PCID_PCID_LINE_3_line3_odd_g_color_select_shift                         (28)
#define  PCID_PCID_LINE_3_line3_odd_r_color_select_shift                         (26)
#define  PCID_PCID_LINE_3_line3_odd_b_point_select_shift                         (24)
#define  PCID_PCID_LINE_3_line3_odd_g_point_select_shift                         (22)
#define  PCID_PCID_LINE_3_line3_odd_r_point_select_shift                         (20)
#define  PCID_PCID_LINE_3_line3_odd_b_line_select_shift                          (18)
#define  PCID_PCID_LINE_3_line3_odd_g_line_select_shift                          (17)
#define  PCID_PCID_LINE_3_line3_odd_r_line_select_shift                          (16)
#define  PCID_PCID_LINE_3_line3_even_b_color_select_shift                        (14)
#define  PCID_PCID_LINE_3_line3_even_g_color_select_shift                        (12)
#define  PCID_PCID_LINE_3_line3_even_r_color_select_shift                        (10)
#define  PCID_PCID_LINE_3_line3_even_b_point_select_shift                        (8)
#define  PCID_PCID_LINE_3_line3_even_g_point_select_shift                        (6)
#define  PCID_PCID_LINE_3_line3_even_r_point_select_shift                        (4)
#define  PCID_PCID_LINE_3_line3_even_b_line_select_shift                         (2)
#define  PCID_PCID_LINE_3_line3_even_g_line_select_shift                         (1)
#define  PCID_PCID_LINE_3_line3_even_r_line_select_shift                         (0)
#define  PCID_PCID_LINE_3_line3_odd_b_color_select_mask                          (0xC0000000)
#define  PCID_PCID_LINE_3_line3_odd_g_color_select_mask                          (0x30000000)
#define  PCID_PCID_LINE_3_line3_odd_r_color_select_mask                          (0x0C000000)
#define  PCID_PCID_LINE_3_line3_odd_b_point_select_mask                          (0x03000000)
#define  PCID_PCID_LINE_3_line3_odd_g_point_select_mask                          (0x00C00000)
#define  PCID_PCID_LINE_3_line3_odd_r_point_select_mask                          (0x00300000)
#define  PCID_PCID_LINE_3_line3_odd_b_line_select_mask                           (0x00040000)
#define  PCID_PCID_LINE_3_line3_odd_g_line_select_mask                           (0x00020000)
#define  PCID_PCID_LINE_3_line3_odd_r_line_select_mask                           (0x00010000)
#define  PCID_PCID_LINE_3_line3_even_b_color_select_mask                         (0x0000C000)
#define  PCID_PCID_LINE_3_line3_even_g_color_select_mask                         (0x00003000)
#define  PCID_PCID_LINE_3_line3_even_r_color_select_mask                         (0x00000C00)
#define  PCID_PCID_LINE_3_line3_even_b_point_select_mask                         (0x00000300)
#define  PCID_PCID_LINE_3_line3_even_g_point_select_mask                         (0x000000C0)
#define  PCID_PCID_LINE_3_line3_even_r_point_select_mask                         (0x00000030)
#define  PCID_PCID_LINE_3_line3_even_b_line_select_mask                          (0x00000004)
#define  PCID_PCID_LINE_3_line3_even_g_line_select_mask                          (0x00000002)
#define  PCID_PCID_LINE_3_line3_even_r_line_select_mask                          (0x00000001)
#define  PCID_PCID_LINE_3_line3_odd_b_color_select(data)                         (0xC0000000&((data)<<30))
#define  PCID_PCID_LINE_3_line3_odd_g_color_select(data)                         (0x30000000&((data)<<28))
#define  PCID_PCID_LINE_3_line3_odd_r_color_select(data)                         (0x0C000000&((data)<<26))
#define  PCID_PCID_LINE_3_line3_odd_b_point_select(data)                         (0x03000000&((data)<<24))
#define  PCID_PCID_LINE_3_line3_odd_g_point_select(data)                         (0x00C00000&((data)<<22))
#define  PCID_PCID_LINE_3_line3_odd_r_point_select(data)                         (0x00300000&((data)<<20))
#define  PCID_PCID_LINE_3_line3_odd_b_line_select(data)                          (0x00040000&((data)<<18))
#define  PCID_PCID_LINE_3_line3_odd_g_line_select(data)                          (0x00020000&((data)<<17))
#define  PCID_PCID_LINE_3_line3_odd_r_line_select(data)                          (0x00010000&((data)<<16))
#define  PCID_PCID_LINE_3_line3_even_b_color_select(data)                        (0x0000C000&((data)<<14))
#define  PCID_PCID_LINE_3_line3_even_g_color_select(data)                        (0x00003000&((data)<<12))
#define  PCID_PCID_LINE_3_line3_even_r_color_select(data)                        (0x00000C00&((data)<<10))
#define  PCID_PCID_LINE_3_line3_even_b_point_select(data)                        (0x00000300&((data)<<8))
#define  PCID_PCID_LINE_3_line3_even_g_point_select(data)                        (0x000000C0&((data)<<6))
#define  PCID_PCID_LINE_3_line3_even_r_point_select(data)                        (0x00000030&((data)<<4))
#define  PCID_PCID_LINE_3_line3_even_b_line_select(data)                         (0x00000004&((data)<<2))
#define  PCID_PCID_LINE_3_line3_even_g_line_select(data)                         (0x00000002&((data)<<1))
#define  PCID_PCID_LINE_3_line3_even_r_line_select(data)                         (0x00000001&(data))
#define  PCID_PCID_LINE_3_get_line3_odd_b_color_select(data)                     ((0xC0000000&(data))>>30)
#define  PCID_PCID_LINE_3_get_line3_odd_g_color_select(data)                     ((0x30000000&(data))>>28)
#define  PCID_PCID_LINE_3_get_line3_odd_r_color_select(data)                     ((0x0C000000&(data))>>26)
#define  PCID_PCID_LINE_3_get_line3_odd_b_point_select(data)                     ((0x03000000&(data))>>24)
#define  PCID_PCID_LINE_3_get_line3_odd_g_point_select(data)                     ((0x00C00000&(data))>>22)
#define  PCID_PCID_LINE_3_get_line3_odd_r_point_select(data)                     ((0x00300000&(data))>>20)
#define  PCID_PCID_LINE_3_get_line3_odd_b_line_select(data)                      ((0x00040000&(data))>>18)
#define  PCID_PCID_LINE_3_get_line3_odd_g_line_select(data)                      ((0x00020000&(data))>>17)
#define  PCID_PCID_LINE_3_get_line3_odd_r_line_select(data)                      ((0x00010000&(data))>>16)
#define  PCID_PCID_LINE_3_get_line3_even_b_color_select(data)                    ((0x0000C000&(data))>>14)
#define  PCID_PCID_LINE_3_get_line3_even_g_color_select(data)                    ((0x00003000&(data))>>12)
#define  PCID_PCID_LINE_3_get_line3_even_r_color_select(data)                    ((0x00000C00&(data))>>10)
#define  PCID_PCID_LINE_3_get_line3_even_b_point_select(data)                    ((0x00000300&(data))>>8)
#define  PCID_PCID_LINE_3_get_line3_even_g_point_select(data)                    ((0x000000C0&(data))>>6)
#define  PCID_PCID_LINE_3_get_line3_even_r_point_select(data)                    ((0x00000030&(data))>>4)
#define  PCID_PCID_LINE_3_get_line3_even_b_line_select(data)                     ((0x00000004&(data))>>2)
#define  PCID_PCID_LINE_3_get_line3_even_g_line_select(data)                     ((0x00000002&(data))>>1)
#define  PCID_PCID_LINE_3_get_line3_even_r_line_select(data)                     (0x00000001&(data))

#define  PCID_PCID_LINE_4                                                        0x1802EF5C
#define  PCID_PCID_LINE_4_reg_addr                                               "0xB802EF5C"
#define  PCID_PCID_LINE_4_reg                                                    0xB802EF5C
#define  PCID_PCID_LINE_4_inst_addr                                              "0x0013"
#define  set_PCID_PCID_LINE_4_reg(data)                                          (*((volatile unsigned int*)PCID_PCID_LINE_4_reg)=data)
#define  get_PCID_PCID_LINE_4_reg                                                (*((volatile unsigned int*)PCID_PCID_LINE_4_reg))
#define  PCID_PCID_LINE_4_line4_odd_b_color_select_shift                         (30)
#define  PCID_PCID_LINE_4_line4_odd_g_color_select_shift                         (28)
#define  PCID_PCID_LINE_4_line4_odd_r_color_select_shift                         (26)
#define  PCID_PCID_LINE_4_line4_odd_b_point_select_shift                         (24)
#define  PCID_PCID_LINE_4_line4_odd_g_point_select_shift                         (22)
#define  PCID_PCID_LINE_4_line4_odd_r_point_select_shift                         (20)
#define  PCID_PCID_LINE_4_line4_odd_b_line_select_shift                          (18)
#define  PCID_PCID_LINE_4_line4_odd_g_line_select_shift                          (17)
#define  PCID_PCID_LINE_4_line4_odd_r_line_select_shift                          (16)
#define  PCID_PCID_LINE_4_line4_even_b_color_select_shift                        (14)
#define  PCID_PCID_LINE_4_line4_even_g_color_select_shift                        (12)
#define  PCID_PCID_LINE_4_line4_even_r_color_select_shift                        (10)
#define  PCID_PCID_LINE_4_line4_even_b_point_select_shift                        (8)
#define  PCID_PCID_LINE_4_line4_even_g_point_select_shift                        (6)
#define  PCID_PCID_LINE_4_line4_even_r_point_select_shift                        (4)
#define  PCID_PCID_LINE_4_line4_even_b_line_select_shift                         (2)
#define  PCID_PCID_LINE_4_line4_even_g_line_select_shift                         (1)
#define  PCID_PCID_LINE_4_line4_even_r_line_select_shift                         (0)
#define  PCID_PCID_LINE_4_line4_odd_b_color_select_mask                          (0xC0000000)
#define  PCID_PCID_LINE_4_line4_odd_g_color_select_mask                          (0x30000000)
#define  PCID_PCID_LINE_4_line4_odd_r_color_select_mask                          (0x0C000000)
#define  PCID_PCID_LINE_4_line4_odd_b_point_select_mask                          (0x03000000)
#define  PCID_PCID_LINE_4_line4_odd_g_point_select_mask                          (0x00C00000)
#define  PCID_PCID_LINE_4_line4_odd_r_point_select_mask                          (0x00300000)
#define  PCID_PCID_LINE_4_line4_odd_b_line_select_mask                           (0x00040000)
#define  PCID_PCID_LINE_4_line4_odd_g_line_select_mask                           (0x00020000)
#define  PCID_PCID_LINE_4_line4_odd_r_line_select_mask                           (0x00010000)
#define  PCID_PCID_LINE_4_line4_even_b_color_select_mask                         (0x0000C000)
#define  PCID_PCID_LINE_4_line4_even_g_color_select_mask                         (0x00003000)
#define  PCID_PCID_LINE_4_line4_even_r_color_select_mask                         (0x00000C00)
#define  PCID_PCID_LINE_4_line4_even_b_point_select_mask                         (0x00000300)
#define  PCID_PCID_LINE_4_line4_even_g_point_select_mask                         (0x000000C0)
#define  PCID_PCID_LINE_4_line4_even_r_point_select_mask                         (0x00000030)
#define  PCID_PCID_LINE_4_line4_even_b_line_select_mask                          (0x00000004)
#define  PCID_PCID_LINE_4_line4_even_g_line_select_mask                          (0x00000002)
#define  PCID_PCID_LINE_4_line4_even_r_line_select_mask                          (0x00000001)
#define  PCID_PCID_LINE_4_line4_odd_b_color_select(data)                         (0xC0000000&((data)<<30))
#define  PCID_PCID_LINE_4_line4_odd_g_color_select(data)                         (0x30000000&((data)<<28))
#define  PCID_PCID_LINE_4_line4_odd_r_color_select(data)                         (0x0C000000&((data)<<26))
#define  PCID_PCID_LINE_4_line4_odd_b_point_select(data)                         (0x03000000&((data)<<24))
#define  PCID_PCID_LINE_4_line4_odd_g_point_select(data)                         (0x00C00000&((data)<<22))
#define  PCID_PCID_LINE_4_line4_odd_r_point_select(data)                         (0x00300000&((data)<<20))
#define  PCID_PCID_LINE_4_line4_odd_b_line_select(data)                          (0x00040000&((data)<<18))
#define  PCID_PCID_LINE_4_line4_odd_g_line_select(data)                          (0x00020000&((data)<<17))
#define  PCID_PCID_LINE_4_line4_odd_r_line_select(data)                          (0x00010000&((data)<<16))
#define  PCID_PCID_LINE_4_line4_even_b_color_select(data)                        (0x0000C000&((data)<<14))
#define  PCID_PCID_LINE_4_line4_even_g_color_select(data)                        (0x00003000&((data)<<12))
#define  PCID_PCID_LINE_4_line4_even_r_color_select(data)                        (0x00000C00&((data)<<10))
#define  PCID_PCID_LINE_4_line4_even_b_point_select(data)                        (0x00000300&((data)<<8))
#define  PCID_PCID_LINE_4_line4_even_g_point_select(data)                        (0x000000C0&((data)<<6))
#define  PCID_PCID_LINE_4_line4_even_r_point_select(data)                        (0x00000030&((data)<<4))
#define  PCID_PCID_LINE_4_line4_even_b_line_select(data)                         (0x00000004&((data)<<2))
#define  PCID_PCID_LINE_4_line4_even_g_line_select(data)                         (0x00000002&((data)<<1))
#define  PCID_PCID_LINE_4_line4_even_r_line_select(data)                         (0x00000001&(data))
#define  PCID_PCID_LINE_4_get_line4_odd_b_color_select(data)                     ((0xC0000000&(data))>>30)
#define  PCID_PCID_LINE_4_get_line4_odd_g_color_select(data)                     ((0x30000000&(data))>>28)
#define  PCID_PCID_LINE_4_get_line4_odd_r_color_select(data)                     ((0x0C000000&(data))>>26)
#define  PCID_PCID_LINE_4_get_line4_odd_b_point_select(data)                     ((0x03000000&(data))>>24)
#define  PCID_PCID_LINE_4_get_line4_odd_g_point_select(data)                     ((0x00C00000&(data))>>22)
#define  PCID_PCID_LINE_4_get_line4_odd_r_point_select(data)                     ((0x00300000&(data))>>20)
#define  PCID_PCID_LINE_4_get_line4_odd_b_line_select(data)                      ((0x00040000&(data))>>18)
#define  PCID_PCID_LINE_4_get_line4_odd_g_line_select(data)                      ((0x00020000&(data))>>17)
#define  PCID_PCID_LINE_4_get_line4_odd_r_line_select(data)                      ((0x00010000&(data))>>16)
#define  PCID_PCID_LINE_4_get_line4_even_b_color_select(data)                    ((0x0000C000&(data))>>14)
#define  PCID_PCID_LINE_4_get_line4_even_g_color_select(data)                    ((0x00003000&(data))>>12)
#define  PCID_PCID_LINE_4_get_line4_even_r_color_select(data)                    ((0x00000C00&(data))>>10)
#define  PCID_PCID_LINE_4_get_line4_even_b_point_select(data)                    ((0x00000300&(data))>>8)
#define  PCID_PCID_LINE_4_get_line4_even_g_point_select(data)                    ((0x000000C0&(data))>>6)
#define  PCID_PCID_LINE_4_get_line4_even_r_point_select(data)                    ((0x00000030&(data))>>4)
#define  PCID_PCID_LINE_4_get_line4_even_b_line_select(data)                     ((0x00000004&(data))>>2)
#define  PCID_PCID_LINE_4_get_line4_even_g_line_select(data)                     ((0x00000002&(data))>>1)
#define  PCID_PCID_LINE_4_get_line4_even_r_line_select(data)                     (0x00000001&(data))

#define  PCID_PCID_RM                                                            0x1802EFB0
#define  PCID_PCID_RM_reg_addr                                                   "0xB802EFB0"
#define  PCID_PCID_RM_reg                                                        0xB802EFB0
#define  PCID_PCID_RM_inst_addr                                                  "0x0014"
#define  set_PCID_PCID_RM_reg(data)                                              (*((volatile unsigned int*)PCID_PCID_RM_reg)=data)
#define  get_PCID_PCID_RM_reg                                                    (*((volatile unsigned int*)PCID_PCID_RM_reg))
#define  PCID_PCID_RM_pcid_tab_rm_2_shift                                        (24)
#define  PCID_PCID_RM_pcid_tab_rm_1_shift                                        (20)
#define  PCID_PCID_RM_pcid_tab_rm_0_shift                                        (16)
#define  PCID_PCID_RM_pcid_lb_rm_1_shift                                         (4)
#define  PCID_PCID_RM_pcid_lb_rm_0_shift                                         (0)
#define  PCID_PCID_RM_pcid_tab_rm_2_mask                                         (0x0F000000)
#define  PCID_PCID_RM_pcid_tab_rm_1_mask                                         (0x00F00000)
#define  PCID_PCID_RM_pcid_tab_rm_0_mask                                         (0x000F0000)
#define  PCID_PCID_RM_pcid_lb_rm_1_mask                                          (0x000000F0)
#define  PCID_PCID_RM_pcid_lb_rm_0_mask                                          (0x0000000F)
#define  PCID_PCID_RM_pcid_tab_rm_2(data)                                        (0x0F000000&((data)<<24))
#define  PCID_PCID_RM_pcid_tab_rm_1(data)                                        (0x00F00000&((data)<<20))
#define  PCID_PCID_RM_pcid_tab_rm_0(data)                                        (0x000F0000&((data)<<16))
#define  PCID_PCID_RM_pcid_lb_rm_1(data)                                         (0x000000F0&((data)<<4))
#define  PCID_PCID_RM_pcid_lb_rm_0(data)                                         (0x0000000F&(data))
#define  PCID_PCID_RM_get_pcid_tab_rm_2(data)                                    ((0x0F000000&(data))>>24)
#define  PCID_PCID_RM_get_pcid_tab_rm_1(data)                                    ((0x00F00000&(data))>>20)
#define  PCID_PCID_RM_get_pcid_tab_rm_0(data)                                    ((0x000F0000&(data))>>16)
#define  PCID_PCID_RM_get_pcid_lb_rm_1(data)                                     ((0x000000F0&(data))>>4)
#define  PCID_PCID_RM_get_pcid_lb_rm_0(data)                                     (0x0000000F&(data))

#define  PCID_PCID_RME_LS                                                        0x1802EFB4
#define  PCID_PCID_RME_LS_reg_addr                                               "0xB802EFB4"
#define  PCID_PCID_RME_LS_reg                                                    0xB802EFB4
#define  PCID_PCID_RME_LS_inst_addr                                              "0x0015"
#define  set_PCID_PCID_RME_LS_reg(data)                                          (*((volatile unsigned int*)PCID_PCID_RME_LS_reg)=data)
#define  get_PCID_PCID_RME_LS_reg                                                (*((volatile unsigned int*)PCID_PCID_RME_LS_reg))
#define  PCID_PCID_RME_LS_pcid_tab_ls_2_shift                                    (22)
#define  PCID_PCID_RME_LS_pcid_tab_ls_1_shift                                    (21)
#define  PCID_PCID_RME_LS_pcid_tab_ls_0_shift                                    (20)
#define  PCID_PCID_RME_LS_pcid_lb_ls_1_shift                                     (17)
#define  PCID_PCID_RME_LS_pcid_lb_ls_0_shift                                     (16)
#define  PCID_PCID_RME_LS_pcid_tab_rme_2_shift                                   (6)
#define  PCID_PCID_RME_LS_pcid_tab_rme_1_shift                                   (5)
#define  PCID_PCID_RME_LS_pcid_tab_rme_0_shift                                   (4)
#define  PCID_PCID_RME_LS_pcid_lb_rme_1_shift                                    (1)
#define  PCID_PCID_RME_LS_pcid_lb_rme_0_shift                                    (0)
#define  PCID_PCID_RME_LS_pcid_tab_ls_2_mask                                     (0x00400000)
#define  PCID_PCID_RME_LS_pcid_tab_ls_1_mask                                     (0x00200000)
#define  PCID_PCID_RME_LS_pcid_tab_ls_0_mask                                     (0x00100000)
#define  PCID_PCID_RME_LS_pcid_lb_ls_1_mask                                      (0x00020000)
#define  PCID_PCID_RME_LS_pcid_lb_ls_0_mask                                      (0x00010000)
#define  PCID_PCID_RME_LS_pcid_tab_rme_2_mask                                    (0x00000040)
#define  PCID_PCID_RME_LS_pcid_tab_rme_1_mask                                    (0x00000020)
#define  PCID_PCID_RME_LS_pcid_tab_rme_0_mask                                    (0x00000010)
#define  PCID_PCID_RME_LS_pcid_lb_rme_1_mask                                     (0x00000002)
#define  PCID_PCID_RME_LS_pcid_lb_rme_0_mask                                     (0x00000001)
#define  PCID_PCID_RME_LS_pcid_tab_ls_2(data)                                    (0x00400000&((data)<<22))
#define  PCID_PCID_RME_LS_pcid_tab_ls_1(data)                                    (0x00200000&((data)<<21))
#define  PCID_PCID_RME_LS_pcid_tab_ls_0(data)                                    (0x00100000&((data)<<20))
#define  PCID_PCID_RME_LS_pcid_lb_ls_1(data)                                     (0x00020000&((data)<<17))
#define  PCID_PCID_RME_LS_pcid_lb_ls_0(data)                                     (0x00010000&((data)<<16))
#define  PCID_PCID_RME_LS_pcid_tab_rme_2(data)                                   (0x00000040&((data)<<6))
#define  PCID_PCID_RME_LS_pcid_tab_rme_1(data)                                   (0x00000020&((data)<<5))
#define  PCID_PCID_RME_LS_pcid_tab_rme_0(data)                                   (0x00000010&((data)<<4))
#define  PCID_PCID_RME_LS_pcid_lb_rme_1(data)                                    (0x00000002&((data)<<1))
#define  PCID_PCID_RME_LS_pcid_lb_rme_0(data)                                    (0x00000001&(data))
#define  PCID_PCID_RME_LS_get_pcid_tab_ls_2(data)                                ((0x00400000&(data))>>22)
#define  PCID_PCID_RME_LS_get_pcid_tab_ls_1(data)                                ((0x00200000&(data))>>21)
#define  PCID_PCID_RME_LS_get_pcid_tab_ls_0(data)                                ((0x00100000&(data))>>20)
#define  PCID_PCID_RME_LS_get_pcid_lb_ls_1(data)                                 ((0x00020000&(data))>>17)
#define  PCID_PCID_RME_LS_get_pcid_lb_ls_0(data)                                 ((0x00010000&(data))>>16)
#define  PCID_PCID_RME_LS_get_pcid_tab_rme_2(data)                               ((0x00000040&(data))>>6)
#define  PCID_PCID_RME_LS_get_pcid_tab_rme_1(data)                               ((0x00000020&(data))>>5)
#define  PCID_PCID_RME_LS_get_pcid_tab_rme_0(data)                               ((0x00000010&(data))>>4)
#define  PCID_PCID_RME_LS_get_pcid_lb_rme_1(data)                                ((0x00000002&(data))>>1)
#define  PCID_PCID_RME_LS_get_pcid_lb_rme_0(data)                                (0x00000001&(data))

#define  PCID_PCID_FAIL                                                          0x1802EFB8
#define  PCID_PCID_FAIL_reg_addr                                                 "0xB802EFB8"
#define  PCID_PCID_FAIL_reg                                                      0xB802EFB8
#define  PCID_PCID_FAIL_inst_addr                                                "0x0016"
#define  set_PCID_PCID_FAIL_reg(data)                                            (*((volatile unsigned int*)PCID_PCID_FAIL_reg)=data)
#define  get_PCID_PCID_FAIL_reg                                                  (*((volatile unsigned int*)PCID_PCID_FAIL_reg))
#define  PCID_PCID_FAIL_pcid_tab_drf_fail_2_shift                                (22)
#define  PCID_PCID_FAIL_pcid_tab_drf_fail_1_shift                                (21)
#define  PCID_PCID_FAIL_pcid_tab_drf_fail_0_shift                                (20)
#define  PCID_PCID_FAIL_pcid_lb_drf_fail_1_shift                                 (17)
#define  PCID_PCID_FAIL_pcid_lb_drf_fail_0_shift                                 (16)
#define  PCID_PCID_FAIL_pcid_tab_bist_fail_2_shift                               (6)
#define  PCID_PCID_FAIL_pcid_tab_bist_fail_1_shift                               (5)
#define  PCID_PCID_FAIL_pcid_tab_bist_fail_0_shift                               (4)
#define  PCID_PCID_FAIL_pcid_lb_bist_fail_1_shift                                (1)
#define  PCID_PCID_FAIL_pcid_lb_bist_fail_0_shift                                (0)
#define  PCID_PCID_FAIL_pcid_tab_drf_fail_2_mask                                 (0x00400000)
#define  PCID_PCID_FAIL_pcid_tab_drf_fail_1_mask                                 (0x00200000)
#define  PCID_PCID_FAIL_pcid_tab_drf_fail_0_mask                                 (0x00100000)
#define  PCID_PCID_FAIL_pcid_lb_drf_fail_1_mask                                  (0x00020000)
#define  PCID_PCID_FAIL_pcid_lb_drf_fail_0_mask                                  (0x00010000)
#define  PCID_PCID_FAIL_pcid_tab_bist_fail_2_mask                                (0x00000040)
#define  PCID_PCID_FAIL_pcid_tab_bist_fail_1_mask                                (0x00000020)
#define  PCID_PCID_FAIL_pcid_tab_bist_fail_0_mask                                (0x00000010)
#define  PCID_PCID_FAIL_pcid_lb_bist_fail_1_mask                                 (0x00000002)
#define  PCID_PCID_FAIL_pcid_lb_bist_fail_0_mask                                 (0x00000001)
#define  PCID_PCID_FAIL_pcid_tab_drf_fail_2(data)                                (0x00400000&((data)<<22))
#define  PCID_PCID_FAIL_pcid_tab_drf_fail_1(data)                                (0x00200000&((data)<<21))
#define  PCID_PCID_FAIL_pcid_tab_drf_fail_0(data)                                (0x00100000&((data)<<20))
#define  PCID_PCID_FAIL_pcid_lb_drf_fail_1(data)                                 (0x00020000&((data)<<17))
#define  PCID_PCID_FAIL_pcid_lb_drf_fail_0(data)                                 (0x00010000&((data)<<16))
#define  PCID_PCID_FAIL_pcid_tab_bist_fail_2(data)                               (0x00000040&((data)<<6))
#define  PCID_PCID_FAIL_pcid_tab_bist_fail_1(data)                               (0x00000020&((data)<<5))
#define  PCID_PCID_FAIL_pcid_tab_bist_fail_0(data)                               (0x00000010&((data)<<4))
#define  PCID_PCID_FAIL_pcid_lb_bist_fail_1(data)                                (0x00000002&((data)<<1))
#define  PCID_PCID_FAIL_pcid_lb_bist_fail_0(data)                                (0x00000001&(data))
#define  PCID_PCID_FAIL_get_pcid_tab_drf_fail_2(data)                            ((0x00400000&(data))>>22)
#define  PCID_PCID_FAIL_get_pcid_tab_drf_fail_1(data)                            ((0x00200000&(data))>>21)
#define  PCID_PCID_FAIL_get_pcid_tab_drf_fail_0(data)                            ((0x00100000&(data))>>20)
#define  PCID_PCID_FAIL_get_pcid_lb_drf_fail_1(data)                             ((0x00020000&(data))>>17)
#define  PCID_PCID_FAIL_get_pcid_lb_drf_fail_0(data)                             ((0x00010000&(data))>>16)
#define  PCID_PCID_FAIL_get_pcid_tab_bist_fail_2(data)                           ((0x00000040&(data))>>6)
#define  PCID_PCID_FAIL_get_pcid_tab_bist_fail_1(data)                           ((0x00000020&(data))>>5)
#define  PCID_PCID_FAIL_get_pcid_tab_bist_fail_0(data)                           ((0x00000010&(data))>>4)
#define  PCID_PCID_FAIL_get_pcid_lb_bist_fail_1(data)                            ((0x00000002&(data))>>1)
#define  PCID_PCID_FAIL_get_pcid_lb_bist_fail_0(data)                            (0x00000001&(data))

#define  PCID_PCID_LUT_ADDR                                                      0x1802EFD0
#define  PCID_PCID_LUT_ADDR_reg_addr                                             "0xB802EFD0"
#define  PCID_PCID_LUT_ADDR_reg                                                  0xB802EFD0
#define  PCID_PCID_LUT_ADDR_inst_addr                                            "0x0017"
#define  set_PCID_PCID_LUT_ADDR_reg(data)                                        (*((volatile unsigned int*)PCID_PCID_LUT_ADDR_reg)=data)
#define  get_PCID_PCID_LUT_ADDR_reg                                              (*((volatile unsigned int*)PCID_PCID_LUT_ADDR_reg))
#define  PCID_PCID_LUT_ADDR_pcid_lut_ax_en_shift                                 (16)
#define  PCID_PCID_LUT_ADDR_pcid_lut_adr_mode_shift                              (14)
#define  PCID_PCID_LUT_ADDR_pcid_lut_sel_shift                                   (12)
#define  PCID_PCID_LUT_ADDR_pcid_lut_row_addr_shift                              (6)
#define  PCID_PCID_LUT_ADDR_pcid_lut_column_addr_shift                           (0)
#define  PCID_PCID_LUT_ADDR_pcid_lut_ax_en_mask                                  (0x00010000)
#define  PCID_PCID_LUT_ADDR_pcid_lut_adr_mode_mask                               (0x00004000)
#define  PCID_PCID_LUT_ADDR_pcid_lut_sel_mask                                    (0x00003000)
#define  PCID_PCID_LUT_ADDR_pcid_lut_row_addr_mask                               (0x00000FC0)
#define  PCID_PCID_LUT_ADDR_pcid_lut_column_addr_mask                            (0x0000003F)
#define  PCID_PCID_LUT_ADDR_pcid_lut_ax_en(data)                                 (0x00010000&((data)<<16))
#define  PCID_PCID_LUT_ADDR_pcid_lut_adr_mode(data)                              (0x00004000&((data)<<14))
#define  PCID_PCID_LUT_ADDR_pcid_lut_sel(data)                                   (0x00003000&((data)<<12))
#define  PCID_PCID_LUT_ADDR_pcid_lut_row_addr(data)                              (0x00000FC0&((data)<<6))
#define  PCID_PCID_LUT_ADDR_pcid_lut_column_addr(data)                           (0x0000003F&(data))
#define  PCID_PCID_LUT_ADDR_get_pcid_lut_ax_en(data)                             ((0x00010000&(data))>>16)
#define  PCID_PCID_LUT_ADDR_get_pcid_lut_adr_mode(data)                          ((0x00004000&(data))>>14)
#define  PCID_PCID_LUT_ADDR_get_pcid_lut_sel(data)                               ((0x00003000&(data))>>12)
#define  PCID_PCID_LUT_ADDR_get_pcid_lut_row_addr(data)                          ((0x00000FC0&(data))>>6)
#define  PCID_PCID_LUT_ADDR_get_pcid_lut_column_addr(data)                       (0x0000003F&(data))

#define  PCID_PCID_LUT_DATA                                                      0x1802EFD4
#define  PCID_PCID_LUT_DATA_reg_addr                                             "0xB802EFD4"
#define  PCID_PCID_LUT_DATA_reg                                                  0xB802EFD4
#define  PCID_PCID_LUT_DATA_inst_addr                                            "0x0018"
#define  set_PCID_PCID_LUT_DATA_reg(data)                                        (*((volatile unsigned int*)PCID_PCID_LUT_DATA_reg)=data)
#define  get_PCID_PCID_LUT_DATA_reg                                              (*((volatile unsigned int*)PCID_PCID_LUT_DATA_reg))
#define  PCID_PCID_LUT_DATA_pcid_lut_data_shift                                  (0)
#define  PCID_PCID_LUT_DATA_pcid_lut_data_mask                                   (0xFFFFFFFF)
#define  PCID_PCID_LUT_DATA_pcid_lut_data(data)                                  (0xFFFFFFFF&(data))
#define  PCID_PCID_LUT_DATA_get_pcid_lut_data(data)                              (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PCID register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  pcid_dither_en:1;
        RBus_UInt32  pcid_temporal_enable:1;
        RBus_UInt32  pcid_value_sign:1;
        RBus_UInt32  pcid_dithering_mode:1;
        RBus_UInt32  pcid_v_modulation:1;
        RBus_UInt32  pcid_h_modulation:1;
    };
}pcid_pcid_dither_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_r_15:2;
        RBus_UInt32  pcid_seq_r_14:2;
        RBus_UInt32  pcid_seq_r_13:2;
        RBus_UInt32  pcid_seq_r_12:2;
        RBus_UInt32  pcid_seq_r_11:2;
        RBus_UInt32  pcid_seq_r_10:2;
        RBus_UInt32  pcid_seq_r_9:2;
        RBus_UInt32  pcid_seq_r_8:2;
        RBus_UInt32  pcid_seq_r_7:2;
        RBus_UInt32  pcid_seq_r_6:2;
        RBus_UInt32  pcid_seq_r_5:2;
        RBus_UInt32  pcid_seq_r_4:2;
        RBus_UInt32  pcid_seq_r_3:2;
        RBus_UInt32  pcid_seq_r_2:2;
        RBus_UInt32  pcid_seq_r_1:2;
        RBus_UInt32  pcid_seq_r_0:2;
    };
}pcid_pcid_dither_seq_r_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_r_31:2;
        RBus_UInt32  pcid_seq_r_30:2;
        RBus_UInt32  pcid_seq_r_29:2;
        RBus_UInt32  pcid_seq_r_28:2;
        RBus_UInt32  pcid_seq_r_27:2;
        RBus_UInt32  pcid_seq_r_26:2;
        RBus_UInt32  pcid_seq_r_25:2;
        RBus_UInt32  pcid_seq_r_24:2;
        RBus_UInt32  pcid_seq_r_23:2;
        RBus_UInt32  pcid_seq_r_22:2;
        RBus_UInt32  pcid_seq_r_21:2;
        RBus_UInt32  pcid_seq_r_20:2;
        RBus_UInt32  pcid_seq_r_19:2;
        RBus_UInt32  pcid_seq_r_18:2;
        RBus_UInt32  pcid_seq_r_17:2;
        RBus_UInt32  pcid_seq_r_16:2;
    };
}pcid_pcid_dither_seq_r_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_g_15:2;
        RBus_UInt32  pcid_seq_g_14:2;
        RBus_UInt32  pcid_seq_g_13:2;
        RBus_UInt32  pcid_seq_g_12:2;
        RBus_UInt32  pcid_seq_g_11:2;
        RBus_UInt32  pcid_seq_g_10:2;
        RBus_UInt32  pcid_seq_g_9:2;
        RBus_UInt32  pcid_seq_g_8:2;
        RBus_UInt32  pcid_seq_g_7:2;
        RBus_UInt32  pcid_seq_g_6:2;
        RBus_UInt32  pcid_seq_g_5:2;
        RBus_UInt32  pcid_seq_g_4:2;
        RBus_UInt32  pcid_seq_g_3:2;
        RBus_UInt32  pcid_seq_g_2:2;
        RBus_UInt32  pcid_seq_g_1:2;
        RBus_UInt32  pcid_seq_g_0:2;
    };
}pcid_pcid_dither_seq_g_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_g_31:2;
        RBus_UInt32  pcid_seq_g_30:2;
        RBus_UInt32  pcid_seq_g_29:2;
        RBus_UInt32  pcid_seq_g_28:2;
        RBus_UInt32  pcid_seq_g_27:2;
        RBus_UInt32  pcid_seq_g_26:2;
        RBus_UInt32  pcid_seq_g_25:2;
        RBus_UInt32  pcid_seq_g_24:2;
        RBus_UInt32  pcid_seq_g_23:2;
        RBus_UInt32  pcid_seq_g_22:2;
        RBus_UInt32  pcid_seq_g_21:2;
        RBus_UInt32  pcid_seq_g_20:2;
        RBus_UInt32  pcid_seq_g_19:2;
        RBus_UInt32  pcid_seq_g_18:2;
        RBus_UInt32  pcid_seq_g_17:2;
        RBus_UInt32  pcid_seq_g_16:2;
    };
}pcid_pcid_dither_seq_g_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_b_15:2;
        RBus_UInt32  pcid_seq_b_14:2;
        RBus_UInt32  pcid_seq_b_13:2;
        RBus_UInt32  pcid_seq_b_12:2;
        RBus_UInt32  pcid_seq_b_11:2;
        RBus_UInt32  pcid_seq_b_10:2;
        RBus_UInt32  pcid_seq_b_9:2;
        RBus_UInt32  pcid_seq_b_8:2;
        RBus_UInt32  pcid_seq_b_7:2;
        RBus_UInt32  pcid_seq_b_6:2;
        RBus_UInt32  pcid_seq_b_5:2;
        RBus_UInt32  pcid_seq_b_4:2;
        RBus_UInt32  pcid_seq_b_3:2;
        RBus_UInt32  pcid_seq_b_2:2;
        RBus_UInt32  pcid_seq_b_1:2;
        RBus_UInt32  pcid_seq_b_0:2;
    };
}pcid_pcid_dither_seq_b_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_b_31:2;
        RBus_UInt32  pcid_seq_b_30:2;
        RBus_UInt32  pcid_seq_b_29:2;
        RBus_UInt32  pcid_seq_b_28:2;
        RBus_UInt32  pcid_seq_b_27:2;
        RBus_UInt32  pcid_seq_b_26:2;
        RBus_UInt32  pcid_seq_b_25:2;
        RBus_UInt32  pcid_seq_b_24:2;
        RBus_UInt32  pcid_seq_b_23:2;
        RBus_UInt32  pcid_seq_b_22:2;
        RBus_UInt32  pcid_seq_b_21:2;
        RBus_UInt32  pcid_seq_b_20:2;
        RBus_UInt32  pcid_seq_b_19:2;
        RBus_UInt32  pcid_seq_b_18:2;
        RBus_UInt32  pcid_seq_b_17:2;
        RBus_UInt32  pcid_seq_b_16:2;
    };
}pcid_pcid_dither_seq_b_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_r_13:4;
        RBus_UInt32  pcid_tab_r_12:4;
        RBus_UInt32  pcid_tab_r_11:4;
        RBus_UInt32  pcid_tab_r_10:4;
        RBus_UInt32  pcid_tab_r_03:4;
        RBus_UInt32  pcid_tab_r_02:4;
        RBus_UInt32  pcid_tab_r_01:4;
        RBus_UInt32  pcid_tab_r_00:4;
    };
}pcid_pcid_dither_tb_r_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_r_33:4;
        RBus_UInt32  pcid_tab_r_32:4;
        RBus_UInt32  pcid_tab_r_31:4;
        RBus_UInt32  pcid_tab_r_30:4;
        RBus_UInt32  pcid_tab_r_23:4;
        RBus_UInt32  pcid_tab_r_22:4;
        RBus_UInt32  pcid_tab_r_21:4;
        RBus_UInt32  pcid_tab_r_20:4;
    };
}pcid_pcid_dither_tb_r_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_g_13:4;
        RBus_UInt32  pcid_tab_g_12:4;
        RBus_UInt32  pcid_tab_g_11:4;
        RBus_UInt32  pcid_tab_g_10:4;
        RBus_UInt32  pcid_tab_g_03:4;
        RBus_UInt32  pcid_tab_g_02:4;
        RBus_UInt32  pcid_tab_g_01:4;
        RBus_UInt32  pcid_tab_g_00:4;
    };
}pcid_pcid_dither_tb_g_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_g_33:4;
        RBus_UInt32  pcid_tab_g_32:4;
        RBus_UInt32  pcid_tab_g_31:4;
        RBus_UInt32  pcid_tab_g_30:4;
        RBus_UInt32  pcid_tab_g_23:4;
        RBus_UInt32  pcid_tab_g_22:4;
        RBus_UInt32  pcid_tab_g_21:4;
        RBus_UInt32  pcid_tab_g_20:4;
    };
}pcid_pcid_dither_tb_g_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_b_13:4;
        RBus_UInt32  pcid_tab_b_12:4;
        RBus_UInt32  pcid_tab_b_11:4;
        RBus_UInt32  pcid_tab_b_10:4;
        RBus_UInt32  pcid_tab_b_03:4;
        RBus_UInt32  pcid_tab_b_02:4;
        RBus_UInt32  pcid_tab_b_01:4;
        RBus_UInt32  pcid_tab_b_00:4;
    };
}pcid_pcid_dither_tb_b_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_b_33:4;
        RBus_UInt32  pcid_tab_b_32:4;
        RBus_UInt32  pcid_tab_b_31:4;
        RBus_UInt32  pcid_tab_b_30:4;
        RBus_UInt32  pcid_tab_b_23:4;
        RBus_UInt32  pcid_tab_b_22:4;
        RBus_UInt32  pcid_tab_b_21:4;
        RBus_UInt32  pcid_tab_b_20:4;
    };
}pcid_pcid_dither_tb_b_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_temp_offset_15:2;
        RBus_UInt32  pcid_temp_offset_14:2;
        RBus_UInt32  pcid_temp_offset_13:2;
        RBus_UInt32  pcid_temp_offset_12:2;
        RBus_UInt32  pcid_temp_offset_11:2;
        RBus_UInt32  pcid_temp_offset_10:2;
        RBus_UInt32  pcid_temp_offset_9:2;
        RBus_UInt32  pcid_temp_offset_8:2;
        RBus_UInt32  pcid_temp_offset_7:2;
        RBus_UInt32  pcid_temp_offset_6:2;
        RBus_UInt32  pcid_temp_offset_5:2;
        RBus_UInt32  pcid_temp_offset_4:2;
        RBus_UInt32  pcid_temp_offset_3:2;
        RBus_UInt32  pcid_temp_offset_2:2;
        RBus_UInt32  pcid_temp_offset_1:2;
        RBus_UInt32  pcid_temp_offset_0:2;
    };
}pcid_pcid_dither_temp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802ef40_31_14:18;
        RBus_UInt32  lsb_add_nr_thd:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  lsb_add_slope_check_en:1;
        RBus_UInt32  lsb_add_nr_en:1;
        RBus_UInt32  lsb_add_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ref_4line:1;
        RBus_UInt32  boundary_mode:1;
    };
}pcid_pcid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pcid_tab1_xtr_en:1;
        RBus_UInt32  pcid_thd_mode:1;
        RBus_UInt32  pcid_thd_en:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pcid_tab1_b_thd:8;
        RBus_UInt32  pcid_tab1_g_thd:8;
        RBus_UInt32  pcid_tab1_r_thd:8;
    };
}pcid_pcid_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line1_odd_b_color_select:2;
        RBus_UInt32  line1_odd_g_color_select:2;
        RBus_UInt32  line1_odd_r_color_select:2;
        RBus_UInt32  line1_odd_b_point_select:2;
        RBus_UInt32  line1_odd_g_point_select:2;
        RBus_UInt32  line1_odd_r_point_select:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  line1_odd_b_line_select:1;
        RBus_UInt32  line1_odd_g_line_select:1;
        RBus_UInt32  line1_odd_r_line_select:1;
        RBus_UInt32  line1_even_b_color_select:2;
        RBus_UInt32  line1_even_g_color_select:2;
        RBus_UInt32  line1_even_r_color_select:2;
        RBus_UInt32  line1_even_b_point_select:2;
        RBus_UInt32  line1_even_g_point_select:2;
        RBus_UInt32  line1_even_r_point_select:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  line1_even_b_line_select:1;
        RBus_UInt32  line1_even_g_line_select:1;
        RBus_UInt32  line1_even_r_line_select:1;
    };
}pcid_pcid_line_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line2_odd_b_color_select:2;
        RBus_UInt32  line2_odd_g_color_select:2;
        RBus_UInt32  line2_odd_r_color_select:2;
        RBus_UInt32  line2_odd_b_point_select:2;
        RBus_UInt32  line2_odd_g_point_select:2;
        RBus_UInt32  line2_odd_r_point_select:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  line2_odd_b_line_select:1;
        RBus_UInt32  line2_odd_g_line_select:1;
        RBus_UInt32  line2_odd_r_line_select:1;
        RBus_UInt32  line2_even_b_color_select:2;
        RBus_UInt32  line2_even_g_color_select:2;
        RBus_UInt32  line2_even_r_color_select:2;
        RBus_UInt32  line2_even_b_point_select:2;
        RBus_UInt32  line2_even_g_point_select:2;
        RBus_UInt32  line2_even_r_point_select:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  line2_even_b_line_select:1;
        RBus_UInt32  line2_even_g_line_select:1;
        RBus_UInt32  line2_even_r_line_select:1;
    };
}pcid_pcid_line_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line3_odd_b_color_select:2;
        RBus_UInt32  line3_odd_g_color_select:2;
        RBus_UInt32  line3_odd_r_color_select:2;
        RBus_UInt32  line3_odd_b_point_select:2;
        RBus_UInt32  line3_odd_g_point_select:2;
        RBus_UInt32  line3_odd_r_point_select:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  line3_odd_b_line_select:1;
        RBus_UInt32  line3_odd_g_line_select:1;
        RBus_UInt32  line3_odd_r_line_select:1;
        RBus_UInt32  line3_even_b_color_select:2;
        RBus_UInt32  line3_even_g_color_select:2;
        RBus_UInt32  line3_even_r_color_select:2;
        RBus_UInt32  line3_even_b_point_select:2;
        RBus_UInt32  line3_even_g_point_select:2;
        RBus_UInt32  line3_even_r_point_select:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  line3_even_b_line_select:1;
        RBus_UInt32  line3_even_g_line_select:1;
        RBus_UInt32  line3_even_r_line_select:1;
    };
}pcid_pcid_line_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line4_odd_b_color_select:2;
        RBus_UInt32  line4_odd_g_color_select:2;
        RBus_UInt32  line4_odd_r_color_select:2;
        RBus_UInt32  line4_odd_b_point_select:2;
        RBus_UInt32  line4_odd_g_point_select:2;
        RBus_UInt32  line4_odd_r_point_select:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  line4_odd_b_line_select:1;
        RBus_UInt32  line4_odd_g_line_select:1;
        RBus_UInt32  line4_odd_r_line_select:1;
        RBus_UInt32  line4_even_b_color_select:2;
        RBus_UInt32  line4_even_g_color_select:2;
        RBus_UInt32  line4_even_r_color_select:2;
        RBus_UInt32  line4_even_b_point_select:2;
        RBus_UInt32  line4_even_g_point_select:2;
        RBus_UInt32  line4_even_r_point_select:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  line4_even_b_line_select:1;
        RBus_UInt32  line4_even_g_line_select:1;
        RBus_UInt32  line4_even_r_line_select:1;
    };
}pcid_pcid_line_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pcid_tab_rm_2:4;
        RBus_UInt32  pcid_tab_rm_1:4;
        RBus_UInt32  pcid_tab_rm_0:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  pcid_lb_rm_1:4;
        RBus_UInt32  pcid_lb_rm_0:4;
    };
}pcid_pcid_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pcid_tab_ls_2:1;
        RBus_UInt32  pcid_tab_ls_1:1;
        RBus_UInt32  pcid_tab_ls_0:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pcid_lb_ls_1:1;
        RBus_UInt32  pcid_lb_ls_0:1;
        RBus_UInt32  res3:9;
        RBus_UInt32  pcid_tab_rme_2:1;
        RBus_UInt32  pcid_tab_rme_1:1;
        RBus_UInt32  pcid_tab_rme_0:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  pcid_lb_rme_1:1;
        RBus_UInt32  pcid_lb_rme_0:1;
    };
}pcid_pcid_rme_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pcid_tab_drf_fail_2:1;
        RBus_UInt32  pcid_tab_drf_fail_1:1;
        RBus_UInt32  pcid_tab_drf_fail_0:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pcid_lb_drf_fail_1:1;
        RBus_UInt32  pcid_lb_drf_fail_0:1;
        RBus_UInt32  res3:9;
        RBus_UInt32  pcid_tab_bist_fail_2:1;
        RBus_UInt32  pcid_tab_bist_fail_1:1;
        RBus_UInt32  pcid_tab_bist_fail_0:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  pcid_lb_bist_fail_1:1;
        RBus_UInt32  pcid_lb_bist_fail_0:1;
    };
}pcid_pcid_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  pcid_lut_ax_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcid_lut_adr_mode:1;
        RBus_UInt32  pcid_lut_sel:2;
        RBus_UInt32  pcid_lut_row_addr:6;
        RBus_UInt32  pcid_lut_column_addr:6;
    };
}pcid_pcid_lut_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_lut_data:32;
    };
}pcid_pcid_lut_data_RBUS;

#else //apply LITTLE_ENDIAN

//======PCID register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_h_modulation:1;
        RBus_UInt32  pcid_v_modulation:1;
        RBus_UInt32  pcid_dithering_mode:1;
        RBus_UInt32  pcid_value_sign:1;
        RBus_UInt32  pcid_temporal_enable:1;
        RBus_UInt32  pcid_dither_en:1;
        RBus_UInt32  res1:26;
    };
}pcid_pcid_dither_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_r_0:2;
        RBus_UInt32  pcid_seq_r_1:2;
        RBus_UInt32  pcid_seq_r_2:2;
        RBus_UInt32  pcid_seq_r_3:2;
        RBus_UInt32  pcid_seq_r_4:2;
        RBus_UInt32  pcid_seq_r_5:2;
        RBus_UInt32  pcid_seq_r_6:2;
        RBus_UInt32  pcid_seq_r_7:2;
        RBus_UInt32  pcid_seq_r_8:2;
        RBus_UInt32  pcid_seq_r_9:2;
        RBus_UInt32  pcid_seq_r_10:2;
        RBus_UInt32  pcid_seq_r_11:2;
        RBus_UInt32  pcid_seq_r_12:2;
        RBus_UInt32  pcid_seq_r_13:2;
        RBus_UInt32  pcid_seq_r_14:2;
        RBus_UInt32  pcid_seq_r_15:2;
    };
}pcid_pcid_dither_seq_r_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_r_16:2;
        RBus_UInt32  pcid_seq_r_17:2;
        RBus_UInt32  pcid_seq_r_18:2;
        RBus_UInt32  pcid_seq_r_19:2;
        RBus_UInt32  pcid_seq_r_20:2;
        RBus_UInt32  pcid_seq_r_21:2;
        RBus_UInt32  pcid_seq_r_22:2;
        RBus_UInt32  pcid_seq_r_23:2;
        RBus_UInt32  pcid_seq_r_24:2;
        RBus_UInt32  pcid_seq_r_25:2;
        RBus_UInt32  pcid_seq_r_26:2;
        RBus_UInt32  pcid_seq_r_27:2;
        RBus_UInt32  pcid_seq_r_28:2;
        RBus_UInt32  pcid_seq_r_29:2;
        RBus_UInt32  pcid_seq_r_30:2;
        RBus_UInt32  pcid_seq_r_31:2;
    };
}pcid_pcid_dither_seq_r_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_g_0:2;
        RBus_UInt32  pcid_seq_g_1:2;
        RBus_UInt32  pcid_seq_g_2:2;
        RBus_UInt32  pcid_seq_g_3:2;
        RBus_UInt32  pcid_seq_g_4:2;
        RBus_UInt32  pcid_seq_g_5:2;
        RBus_UInt32  pcid_seq_g_6:2;
        RBus_UInt32  pcid_seq_g_7:2;
        RBus_UInt32  pcid_seq_g_8:2;
        RBus_UInt32  pcid_seq_g_9:2;
        RBus_UInt32  pcid_seq_g_10:2;
        RBus_UInt32  pcid_seq_g_11:2;
        RBus_UInt32  pcid_seq_g_12:2;
        RBus_UInt32  pcid_seq_g_13:2;
        RBus_UInt32  pcid_seq_g_14:2;
        RBus_UInt32  pcid_seq_g_15:2;
    };
}pcid_pcid_dither_seq_g_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_g_16:2;
        RBus_UInt32  pcid_seq_g_17:2;
        RBus_UInt32  pcid_seq_g_18:2;
        RBus_UInt32  pcid_seq_g_19:2;
        RBus_UInt32  pcid_seq_g_20:2;
        RBus_UInt32  pcid_seq_g_21:2;
        RBus_UInt32  pcid_seq_g_22:2;
        RBus_UInt32  pcid_seq_g_23:2;
        RBus_UInt32  pcid_seq_g_24:2;
        RBus_UInt32  pcid_seq_g_25:2;
        RBus_UInt32  pcid_seq_g_26:2;
        RBus_UInt32  pcid_seq_g_27:2;
        RBus_UInt32  pcid_seq_g_28:2;
        RBus_UInt32  pcid_seq_g_29:2;
        RBus_UInt32  pcid_seq_g_30:2;
        RBus_UInt32  pcid_seq_g_31:2;
    };
}pcid_pcid_dither_seq_g_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_b_0:2;
        RBus_UInt32  pcid_seq_b_1:2;
        RBus_UInt32  pcid_seq_b_2:2;
        RBus_UInt32  pcid_seq_b_3:2;
        RBus_UInt32  pcid_seq_b_4:2;
        RBus_UInt32  pcid_seq_b_5:2;
        RBus_UInt32  pcid_seq_b_6:2;
        RBus_UInt32  pcid_seq_b_7:2;
        RBus_UInt32  pcid_seq_b_8:2;
        RBus_UInt32  pcid_seq_b_9:2;
        RBus_UInt32  pcid_seq_b_10:2;
        RBus_UInt32  pcid_seq_b_11:2;
        RBus_UInt32  pcid_seq_b_12:2;
        RBus_UInt32  pcid_seq_b_13:2;
        RBus_UInt32  pcid_seq_b_14:2;
        RBus_UInt32  pcid_seq_b_15:2;
    };
}pcid_pcid_dither_seq_b_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_seq_b_16:2;
        RBus_UInt32  pcid_seq_b_17:2;
        RBus_UInt32  pcid_seq_b_18:2;
        RBus_UInt32  pcid_seq_b_19:2;
        RBus_UInt32  pcid_seq_b_20:2;
        RBus_UInt32  pcid_seq_b_21:2;
        RBus_UInt32  pcid_seq_b_22:2;
        RBus_UInt32  pcid_seq_b_23:2;
        RBus_UInt32  pcid_seq_b_24:2;
        RBus_UInt32  pcid_seq_b_25:2;
        RBus_UInt32  pcid_seq_b_26:2;
        RBus_UInt32  pcid_seq_b_27:2;
        RBus_UInt32  pcid_seq_b_28:2;
        RBus_UInt32  pcid_seq_b_29:2;
        RBus_UInt32  pcid_seq_b_30:2;
        RBus_UInt32  pcid_seq_b_31:2;
    };
}pcid_pcid_dither_seq_b_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_r_00:4;
        RBus_UInt32  pcid_tab_r_01:4;
        RBus_UInt32  pcid_tab_r_02:4;
        RBus_UInt32  pcid_tab_r_03:4;
        RBus_UInt32  pcid_tab_r_10:4;
        RBus_UInt32  pcid_tab_r_11:4;
        RBus_UInt32  pcid_tab_r_12:4;
        RBus_UInt32  pcid_tab_r_13:4;
    };
}pcid_pcid_dither_tb_r_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_r_20:4;
        RBus_UInt32  pcid_tab_r_21:4;
        RBus_UInt32  pcid_tab_r_22:4;
        RBus_UInt32  pcid_tab_r_23:4;
        RBus_UInt32  pcid_tab_r_30:4;
        RBus_UInt32  pcid_tab_r_31:4;
        RBus_UInt32  pcid_tab_r_32:4;
        RBus_UInt32  pcid_tab_r_33:4;
    };
}pcid_pcid_dither_tb_r_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_g_00:4;
        RBus_UInt32  pcid_tab_g_01:4;
        RBus_UInt32  pcid_tab_g_02:4;
        RBus_UInt32  pcid_tab_g_03:4;
        RBus_UInt32  pcid_tab_g_10:4;
        RBus_UInt32  pcid_tab_g_11:4;
        RBus_UInt32  pcid_tab_g_12:4;
        RBus_UInt32  pcid_tab_g_13:4;
    };
}pcid_pcid_dither_tb_g_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_g_20:4;
        RBus_UInt32  pcid_tab_g_21:4;
        RBus_UInt32  pcid_tab_g_22:4;
        RBus_UInt32  pcid_tab_g_23:4;
        RBus_UInt32  pcid_tab_g_30:4;
        RBus_UInt32  pcid_tab_g_31:4;
        RBus_UInt32  pcid_tab_g_32:4;
        RBus_UInt32  pcid_tab_g_33:4;
    };
}pcid_pcid_dither_tb_g_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_b_00:4;
        RBus_UInt32  pcid_tab_b_01:4;
        RBus_UInt32  pcid_tab_b_02:4;
        RBus_UInt32  pcid_tab_b_03:4;
        RBus_UInt32  pcid_tab_b_10:4;
        RBus_UInt32  pcid_tab_b_11:4;
        RBus_UInt32  pcid_tab_b_12:4;
        RBus_UInt32  pcid_tab_b_13:4;
    };
}pcid_pcid_dither_tb_b_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab_b_20:4;
        RBus_UInt32  pcid_tab_b_21:4;
        RBus_UInt32  pcid_tab_b_22:4;
        RBus_UInt32  pcid_tab_b_23:4;
        RBus_UInt32  pcid_tab_b_30:4;
        RBus_UInt32  pcid_tab_b_31:4;
        RBus_UInt32  pcid_tab_b_32:4;
        RBus_UInt32  pcid_tab_b_33:4;
    };
}pcid_pcid_dither_tb_b_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_temp_offset_0:2;
        RBus_UInt32  pcid_temp_offset_1:2;
        RBus_UInt32  pcid_temp_offset_2:2;
        RBus_UInt32  pcid_temp_offset_3:2;
        RBus_UInt32  pcid_temp_offset_4:2;
        RBus_UInt32  pcid_temp_offset_5:2;
        RBus_UInt32  pcid_temp_offset_6:2;
        RBus_UInt32  pcid_temp_offset_7:2;
        RBus_UInt32  pcid_temp_offset_8:2;
        RBus_UInt32  pcid_temp_offset_9:2;
        RBus_UInt32  pcid_temp_offset_10:2;
        RBus_UInt32  pcid_temp_offset_11:2;
        RBus_UInt32  pcid_temp_offset_12:2;
        RBus_UInt32  pcid_temp_offset_13:2;
        RBus_UInt32  pcid_temp_offset_14:2;
        RBus_UInt32  pcid_temp_offset_15:2;
    };
}pcid_pcid_dither_temp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  boundary_mode:1;
        RBus_UInt32  ref_4line:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  lsb_add_en:1;
        RBus_UInt32  lsb_add_nr_en:1;
        RBus_UInt32  lsb_add_slope_check_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  lsb_add_nr_thd:6;
        RBus_UInt32  dummy1802ef40_31_14:18;
    };
}pcid_pcid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_tab1_r_thd:8;
        RBus_UInt32  pcid_tab1_g_thd:8;
        RBus_UInt32  pcid_tab1_b_thd:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  pcid_thd_en:1;
        RBus_UInt32  pcid_thd_mode:1;
        RBus_UInt32  pcid_tab1_xtr_en:1;
        RBus_UInt32  res2:1;
    };
}pcid_pcid_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line1_even_r_line_select:1;
        RBus_UInt32  line1_even_g_line_select:1;
        RBus_UInt32  line1_even_b_line_select:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  line1_even_r_point_select:2;
        RBus_UInt32  line1_even_g_point_select:2;
        RBus_UInt32  line1_even_b_point_select:2;
        RBus_UInt32  line1_even_r_color_select:2;
        RBus_UInt32  line1_even_g_color_select:2;
        RBus_UInt32  line1_even_b_color_select:2;
        RBus_UInt32  line1_odd_r_line_select:1;
        RBus_UInt32  line1_odd_g_line_select:1;
        RBus_UInt32  line1_odd_b_line_select:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  line1_odd_r_point_select:2;
        RBus_UInt32  line1_odd_g_point_select:2;
        RBus_UInt32  line1_odd_b_point_select:2;
        RBus_UInt32  line1_odd_r_color_select:2;
        RBus_UInt32  line1_odd_g_color_select:2;
        RBus_UInt32  line1_odd_b_color_select:2;
    };
}pcid_pcid_line_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line2_even_r_line_select:1;
        RBus_UInt32  line2_even_g_line_select:1;
        RBus_UInt32  line2_even_b_line_select:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  line2_even_r_point_select:2;
        RBus_UInt32  line2_even_g_point_select:2;
        RBus_UInt32  line2_even_b_point_select:2;
        RBus_UInt32  line2_even_r_color_select:2;
        RBus_UInt32  line2_even_g_color_select:2;
        RBus_UInt32  line2_even_b_color_select:2;
        RBus_UInt32  line2_odd_r_line_select:1;
        RBus_UInt32  line2_odd_g_line_select:1;
        RBus_UInt32  line2_odd_b_line_select:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  line2_odd_r_point_select:2;
        RBus_UInt32  line2_odd_g_point_select:2;
        RBus_UInt32  line2_odd_b_point_select:2;
        RBus_UInt32  line2_odd_r_color_select:2;
        RBus_UInt32  line2_odd_g_color_select:2;
        RBus_UInt32  line2_odd_b_color_select:2;
    };
}pcid_pcid_line_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line3_even_r_line_select:1;
        RBus_UInt32  line3_even_g_line_select:1;
        RBus_UInt32  line3_even_b_line_select:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  line3_even_r_point_select:2;
        RBus_UInt32  line3_even_g_point_select:2;
        RBus_UInt32  line3_even_b_point_select:2;
        RBus_UInt32  line3_even_r_color_select:2;
        RBus_UInt32  line3_even_g_color_select:2;
        RBus_UInt32  line3_even_b_color_select:2;
        RBus_UInt32  line3_odd_r_line_select:1;
        RBus_UInt32  line3_odd_g_line_select:1;
        RBus_UInt32  line3_odd_b_line_select:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  line3_odd_r_point_select:2;
        RBus_UInt32  line3_odd_g_point_select:2;
        RBus_UInt32  line3_odd_b_point_select:2;
        RBus_UInt32  line3_odd_r_color_select:2;
        RBus_UInt32  line3_odd_g_color_select:2;
        RBus_UInt32  line3_odd_b_color_select:2;
    };
}pcid_pcid_line_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line4_even_r_line_select:1;
        RBus_UInt32  line4_even_g_line_select:1;
        RBus_UInt32  line4_even_b_line_select:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  line4_even_r_point_select:2;
        RBus_UInt32  line4_even_g_point_select:2;
        RBus_UInt32  line4_even_b_point_select:2;
        RBus_UInt32  line4_even_r_color_select:2;
        RBus_UInt32  line4_even_g_color_select:2;
        RBus_UInt32  line4_even_b_color_select:2;
        RBus_UInt32  line4_odd_r_line_select:1;
        RBus_UInt32  line4_odd_g_line_select:1;
        RBus_UInt32  line4_odd_b_line_select:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  line4_odd_r_point_select:2;
        RBus_UInt32  line4_odd_g_point_select:2;
        RBus_UInt32  line4_odd_b_point_select:2;
        RBus_UInt32  line4_odd_r_color_select:2;
        RBus_UInt32  line4_odd_g_color_select:2;
        RBus_UInt32  line4_odd_b_color_select:2;
    };
}pcid_pcid_line_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_lb_rm_0:4;
        RBus_UInt32  pcid_lb_rm_1:4;
        RBus_UInt32  res1:8;
        RBus_UInt32  pcid_tab_rm_0:4;
        RBus_UInt32  pcid_tab_rm_1:4;
        RBus_UInt32  pcid_tab_rm_2:4;
        RBus_UInt32  res2:4;
    };
}pcid_pcid_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_lb_rme_0:1;
        RBus_UInt32  pcid_lb_rme_1:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pcid_tab_rme_0:1;
        RBus_UInt32  pcid_tab_rme_1:1;
        RBus_UInt32  pcid_tab_rme_2:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  pcid_lb_ls_0:1;
        RBus_UInt32  pcid_lb_ls_1:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pcid_tab_ls_0:1;
        RBus_UInt32  pcid_tab_ls_1:1;
        RBus_UInt32  pcid_tab_ls_2:1;
        RBus_UInt32  res4:9;
    };
}pcid_pcid_rme_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_lb_bist_fail_0:1;
        RBus_UInt32  pcid_lb_bist_fail_1:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pcid_tab_bist_fail_0:1;
        RBus_UInt32  pcid_tab_bist_fail_1:1;
        RBus_UInt32  pcid_tab_bist_fail_2:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  pcid_lb_drf_fail_0:1;
        RBus_UInt32  pcid_lb_drf_fail_1:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pcid_tab_drf_fail_0:1;
        RBus_UInt32  pcid_tab_drf_fail_1:1;
        RBus_UInt32  pcid_tab_drf_fail_2:1;
        RBus_UInt32  res4:9;
    };
}pcid_pcid_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_lut_column_addr:6;
        RBus_UInt32  pcid_lut_row_addr:6;
        RBus_UInt32  pcid_lut_sel:2;
        RBus_UInt32  pcid_lut_adr_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pcid_lut_ax_en:1;
        RBus_UInt32  res2:15;
    };
}pcid_pcid_lut_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcid_lut_data:32;
    };
}pcid_pcid_lut_data_RBUS;




#endif 


#endif 
