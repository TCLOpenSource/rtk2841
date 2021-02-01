/**
* @file rbusLGD_DitherReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGD_DITHER_REG_H_
#define _RBUS_LGD_DITHER_REG_H_

#include "rbus_types.h"



//  LGD_DITHER Register Address
#define  LGD_DITHER_LGD_DITHER_CTRL                                              0x18028E00
#define  LGD_DITHER_LGD_DITHER_CTRL_reg_addr                                     "0xB8028E00"
#define  LGD_DITHER_LGD_DITHER_CTRL_reg                                          0xB8028E00
#define  LGD_DITHER_LGD_DITHER_CTRL_inst_addr                                    "0x0000"
#define  set_LGD_DITHER_LGD_DITHER_CTRL_reg(data)                                (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_CTRL_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_CTRL_reg                                      (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_CTRL_reg))
#define  LGD_DITHER_LGD_DITHER_CTRL_location_sel_shift                           (6)
#define  LGD_DITHER_LGD_DITHER_CTRL_lgd_dither_en_shift                          (5)
#define  LGD_DITHER_LGD_DITHER_CTRL_temporal_enable_shift                        (4)
#define  LGD_DITHER_LGD_DITHER_CTRL_value_sign_shift                             (3)
#define  LGD_DITHER_LGD_DITHER_CTRL_dithering_mode_shift                         (2)
#define  LGD_DITHER_LGD_DITHER_CTRL_v_modulation_shift                           (1)
#define  LGD_DITHER_LGD_DITHER_CTRL_h_modulation_shift                           (0)
#define  LGD_DITHER_LGD_DITHER_CTRL_location_sel_mask                            (0x00000040)
#define  LGD_DITHER_LGD_DITHER_CTRL_lgd_dither_en_mask                           (0x00000020)
#define  LGD_DITHER_LGD_DITHER_CTRL_temporal_enable_mask                         (0x00000010)
#define  LGD_DITHER_LGD_DITHER_CTRL_value_sign_mask                              (0x00000008)
#define  LGD_DITHER_LGD_DITHER_CTRL_dithering_mode_mask                          (0x00000004)
#define  LGD_DITHER_LGD_DITHER_CTRL_v_modulation_mask                            (0x00000002)
#define  LGD_DITHER_LGD_DITHER_CTRL_h_modulation_mask                            (0x00000001)
#define  LGD_DITHER_LGD_DITHER_CTRL_location_sel(data)                           (0x00000040&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_CTRL_lgd_dither_en(data)                          (0x00000020&((data)<<5))
#define  LGD_DITHER_LGD_DITHER_CTRL_temporal_enable(data)                        (0x00000010&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_CTRL_value_sign(data)                             (0x00000008&((data)<<3))
#define  LGD_DITHER_LGD_DITHER_CTRL_dithering_mode(data)                         (0x00000004&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_CTRL_v_modulation(data)                           (0x00000002&((data)<<1))
#define  LGD_DITHER_LGD_DITHER_CTRL_h_modulation(data)                           (0x00000001&(data))
#define  LGD_DITHER_LGD_DITHER_CTRL_get_location_sel(data)                       ((0x00000040&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_CTRL_get_lgd_dither_en(data)                      ((0x00000020&(data))>>5)
#define  LGD_DITHER_LGD_DITHER_CTRL_get_temporal_enable(data)                    ((0x00000010&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_CTRL_get_value_sign(data)                         ((0x00000008&(data))>>3)
#define  LGD_DITHER_LGD_DITHER_CTRL_get_dithering_mode(data)                     ((0x00000004&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_CTRL_get_v_modulation(data)                       ((0x00000002&(data))>>1)
#define  LGD_DITHER_LGD_DITHER_CTRL_get_h_modulation(data)                       (0x00000001&(data))

#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15                                       0x18028E04
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_reg_addr                              "0xB8028E04"
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_reg                                   0xB8028E04
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_inst_addr                             "0x0001"
#define  set_LGD_DITHER_LGD_DITHER_SEQ_R_00_15_reg(data)                         (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_R_00_15_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_SEQ_R_00_15_reg                               (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_R_00_15_reg))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_15_shift                        (30)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_14_shift                        (28)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_13_shift                        (26)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_12_shift                        (24)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_11_shift                        (22)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_10_shift                        (20)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_9_shift                         (18)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_8_shift                         (16)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_7_shift                         (14)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_6_shift                         (12)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_5_shift                         (10)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_4_shift                         (8)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_3_shift                         (6)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_2_shift                         (4)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_1_shift                         (2)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_0_shift                         (0)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_15_mask                         (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_14_mask                         (0x30000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_13_mask                         (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_12_mask                         (0x03000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_11_mask                         (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_10_mask                         (0x00300000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_9_mask                          (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_8_mask                          (0x00030000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_7_mask                          (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_6_mask                          (0x00003000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_5_mask                          (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_4_mask                          (0x00000300)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_3_mask                          (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_2_mask                          (0x00000030)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_1_mask                          (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_0_mask                          (0x00000003)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_15(data)                        (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_14(data)                        (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_13(data)                        (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_12(data)                        (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_11(data)                        (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_10(data)                        (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_9(data)                         (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_8(data)                         (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_7(data)                         (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_6(data)                         (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_5(data)                         (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_4(data)                         (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_3(data)                         (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_2(data)                         (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_1(data)                         (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_seq_r_0(data)                         (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_15(data)                    ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_14(data)                    ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_13(data)                    ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_12(data)                    ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_11(data)                    ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_10(data)                    ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_9(data)                     ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_8(data)                     ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_7(data)                     ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_6(data)                     ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_5(data)                     ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_4(data)                     ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_3(data)                     ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_2(data)                     ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_1(data)                     ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_00_15_get_seq_r_0(data)                     (0x00000003&(data))

#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31                                       0x18028E08
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_reg_addr                              "0xB8028E08"
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_reg                                   0xB8028E08
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_inst_addr                             "0x0002"
#define  set_LGD_DITHER_LGD_DITHER_SEQ_R_16_31_reg(data)                         (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_R_16_31_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_SEQ_R_16_31_reg                               (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_R_16_31_reg))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_31_shift                        (30)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_30_shift                        (28)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_29_shift                        (26)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_28_shift                        (24)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_27_shift                        (22)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_26_shift                        (20)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_25_shift                        (18)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_24_shift                        (16)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_23_shift                        (14)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_22_shift                        (12)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_21_shift                        (10)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_20_shift                        (8)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_19_shift                        (6)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_18_shift                        (4)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_17_shift                        (2)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_16_shift                        (0)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_31_mask                         (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_30_mask                         (0x30000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_29_mask                         (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_28_mask                         (0x03000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_27_mask                         (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_26_mask                         (0x00300000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_25_mask                         (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_24_mask                         (0x00030000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_23_mask                         (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_22_mask                         (0x00003000)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_21_mask                         (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_20_mask                         (0x00000300)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_19_mask                         (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_18_mask                         (0x00000030)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_17_mask                         (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_16_mask                         (0x00000003)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_31(data)                        (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_30(data)                        (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_29(data)                        (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_28(data)                        (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_27(data)                        (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_26(data)                        (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_25(data)                        (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_24(data)                        (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_23(data)                        (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_22(data)                        (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_21(data)                        (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_20(data)                        (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_19(data)                        (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_18(data)                        (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_17(data)                        (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_seq_r_16(data)                        (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_31(data)                    ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_30(data)                    ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_29(data)                    ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_28(data)                    ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_27(data)                    ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_26(data)                    ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_25(data)                    ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_24(data)                    ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_23(data)                    ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_22(data)                    ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_21(data)                    ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_20(data)                    ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_19(data)                    ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_18(data)                    ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_17(data)                    ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_SEQ_R_16_31_get_seq_r_16(data)                    (0x00000003&(data))

#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15                                       0x18028E0C
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_reg_addr                              "0xB8028E0C"
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_reg                                   0xB8028E0C
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_inst_addr                             "0x0003"
#define  set_LGD_DITHER_LGD_DITHER_SEQ_G_00_15_reg(data)                         (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_G_00_15_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_SEQ_G_00_15_reg                               (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_G_00_15_reg))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_15_shift                        (30)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_14_shift                        (28)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_13_shift                        (26)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_12_shift                        (24)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_11_shift                        (22)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_10_shift                        (20)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_9_shift                         (18)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_8_shift                         (16)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_7_shift                         (14)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_6_shift                         (12)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_5_shift                         (10)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_4_shift                         (8)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_3_shift                         (6)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_2_shift                         (4)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_1_shift                         (2)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_0_shift                         (0)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_15_mask                         (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_14_mask                         (0x30000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_13_mask                         (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_12_mask                         (0x03000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_11_mask                         (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_10_mask                         (0x00300000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_9_mask                          (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_8_mask                          (0x00030000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_7_mask                          (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_6_mask                          (0x00003000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_5_mask                          (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_4_mask                          (0x00000300)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_3_mask                          (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_2_mask                          (0x00000030)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_1_mask                          (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_0_mask                          (0x00000003)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_15(data)                        (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_14(data)                        (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_13(data)                        (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_12(data)                        (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_11(data)                        (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_10(data)                        (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_9(data)                         (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_8(data)                         (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_7(data)                         (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_6(data)                         (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_5(data)                         (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_4(data)                         (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_3(data)                         (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_2(data)                         (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_1(data)                         (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_seq_g_0(data)                         (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_15(data)                    ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_14(data)                    ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_13(data)                    ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_12(data)                    ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_11(data)                    ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_10(data)                    ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_9(data)                     ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_8(data)                     ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_7(data)                     ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_6(data)                     ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_5(data)                     ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_4(data)                     ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_3(data)                     ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_2(data)                     ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_1(data)                     ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_00_15_get_seq_g_0(data)                     (0x00000003&(data))

#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31                                       0x18028E10
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_reg_addr                              "0xB8028E10"
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_reg                                   0xB8028E10
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_inst_addr                             "0x0004"
#define  set_LGD_DITHER_LGD_DITHER_SEQ_G_16_31_reg(data)                         (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_G_16_31_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_SEQ_G_16_31_reg                               (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_G_16_31_reg))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_31_shift                        (30)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_30_shift                        (28)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_29_shift                        (26)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_28_shift                        (24)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_27_shift                        (22)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_26_shift                        (20)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_25_shift                        (18)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_24_shift                        (16)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_23_shift                        (14)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_22_shift                        (12)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_21_shift                        (10)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_20_shift                        (8)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_19_shift                        (6)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_18_shift                        (4)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_17_shift                        (2)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_16_shift                        (0)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_31_mask                         (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_30_mask                         (0x30000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_29_mask                         (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_28_mask                         (0x03000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_27_mask                         (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_26_mask                         (0x00300000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_25_mask                         (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_24_mask                         (0x00030000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_23_mask                         (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_22_mask                         (0x00003000)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_21_mask                         (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_20_mask                         (0x00000300)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_19_mask                         (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_18_mask                         (0x00000030)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_17_mask                         (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_16_mask                         (0x00000003)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_31(data)                        (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_30(data)                        (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_29(data)                        (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_28(data)                        (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_27(data)                        (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_26(data)                        (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_25(data)                        (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_24(data)                        (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_23(data)                        (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_22(data)                        (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_21(data)                        (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_20(data)                        (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_19(data)                        (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_18(data)                        (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_17(data)                        (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_seq_g_16(data)                        (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_31(data)                    ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_30(data)                    ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_29(data)                    ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_28(data)                    ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_27(data)                    ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_26(data)                    ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_25(data)                    ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_24(data)                    ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_23(data)                    ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_22(data)                    ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_21(data)                    ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_20(data)                    ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_19(data)                    ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_18(data)                    ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_17(data)                    ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_SEQ_G_16_31_get_seq_g_16(data)                    (0x00000003&(data))

#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15                                       0x18028E14
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_reg_addr                              "0xB8028E14"
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_reg                                   0xB8028E14
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_inst_addr                             "0x0005"
#define  set_LGD_DITHER_LGD_DITHER_SEQ_B_00_15_reg(data)                         (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_B_00_15_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_SEQ_B_00_15_reg                               (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_B_00_15_reg))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_15_shift                        (30)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_14_shift                        (28)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_13_shift                        (26)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_12_shift                        (24)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_11_shift                        (22)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_10_shift                        (20)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_9_shift                         (18)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_8_shift                         (16)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_7_shift                         (14)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_6_shift                         (12)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_5_shift                         (10)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_4_shift                         (8)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_3_shift                         (6)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_2_shift                         (4)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_1_shift                         (2)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_0_shift                         (0)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_15_mask                         (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_14_mask                         (0x30000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_13_mask                         (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_12_mask                         (0x03000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_11_mask                         (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_10_mask                         (0x00300000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_9_mask                          (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_8_mask                          (0x00030000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_7_mask                          (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_6_mask                          (0x00003000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_5_mask                          (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_4_mask                          (0x00000300)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_3_mask                          (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_2_mask                          (0x00000030)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_1_mask                          (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_0_mask                          (0x00000003)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_15(data)                        (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_14(data)                        (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_13(data)                        (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_12(data)                        (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_11(data)                        (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_10(data)                        (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_9(data)                         (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_8(data)                         (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_7(data)                         (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_6(data)                         (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_5(data)                         (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_4(data)                         (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_3(data)                         (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_2(data)                         (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_1(data)                         (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_seq_b_0(data)                         (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_15(data)                    ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_14(data)                    ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_13(data)                    ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_12(data)                    ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_11(data)                    ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_10(data)                    ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_9(data)                     ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_8(data)                     ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_7(data)                     ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_6(data)                     ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_5(data)                     ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_4(data)                     ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_3(data)                     ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_2(data)                     ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_1(data)                     ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_00_15_get_seq_b_0(data)                     (0x00000003&(data))

#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31                                       0x18028E18
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_reg_addr                              "0xB8028E18"
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_reg                                   0xB8028E18
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_inst_addr                             "0x0006"
#define  set_LGD_DITHER_LGD_DITHER_SEQ_B_16_31_reg(data)                         (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_B_16_31_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_SEQ_B_16_31_reg                               (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_SEQ_B_16_31_reg))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_31_shift                        (30)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_30_shift                        (28)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_29_shift                        (26)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_28_shift                        (24)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_27_shift                        (22)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_26_shift                        (20)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_25_shift                        (18)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_24_shift                        (16)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_23_shift                        (14)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_22_shift                        (12)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_21_shift                        (10)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_20_shift                        (8)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_19_shift                        (6)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_18_shift                        (4)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_17_shift                        (2)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_16_shift                        (0)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_31_mask                         (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_30_mask                         (0x30000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_29_mask                         (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_28_mask                         (0x03000000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_27_mask                         (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_26_mask                         (0x00300000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_25_mask                         (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_24_mask                         (0x00030000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_23_mask                         (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_22_mask                         (0x00003000)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_21_mask                         (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_20_mask                         (0x00000300)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_19_mask                         (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_18_mask                         (0x00000030)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_17_mask                         (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_16_mask                         (0x00000003)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_31(data)                        (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_30(data)                        (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_29(data)                        (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_28(data)                        (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_27(data)                        (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_26(data)                        (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_25(data)                        (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_24(data)                        (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_23(data)                        (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_22(data)                        (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_21(data)                        (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_20(data)                        (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_19(data)                        (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_18(data)                        (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_17(data)                        (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_seq_b_16(data)                        (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_31(data)                    ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_30(data)                    ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_29(data)                    ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_28(data)                    ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_27(data)                    ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_26(data)                    ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_25(data)                    ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_24(data)                    ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_23(data)                    ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_22(data)                    ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_21(data)                    ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_20(data)                    ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_19(data)                    ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_18(data)                    ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_17(data)                    ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_SEQ_B_16_31_get_seq_b_16(data)                    (0x00000003&(data))

#define  LGD_DITHER_LGD_DITHER_TB_R                                              0x18028E1C
#define  LGD_DITHER_LGD_DITHER_TB_R_reg_addr                                     "0xB8028E1C"
#define  LGD_DITHER_LGD_DITHER_TB_R_reg                                          0xB8028E1C
#define  LGD_DITHER_LGD_DITHER_TB_R_inst_addr                                    "0x0007"
#define  set_LGD_DITHER_LGD_DITHER_TB_R_reg(data)                                (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_TB_R_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_TB_R_reg                                      (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_TB_R_reg))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_33_shift                               (30)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_32_shift                               (28)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_31_shift                               (26)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_30_shift                               (24)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_23_shift                               (22)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_22_shift                               (20)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_21_shift                               (18)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_20_shift                               (16)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_13_shift                               (14)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_12_shift                               (12)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_11_shift                               (10)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_10_shift                               (8)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_03_shift                               (6)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_02_shift                               (4)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_01_shift                               (2)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_00_shift                               (0)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_33_mask                                (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_32_mask                                (0x30000000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_31_mask                                (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_30_mask                                (0x03000000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_23_mask                                (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_22_mask                                (0x00300000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_21_mask                                (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_20_mask                                (0x00030000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_13_mask                                (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_12_mask                                (0x00003000)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_11_mask                                (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_10_mask                                (0x00000300)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_03_mask                                (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_02_mask                                (0x00000030)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_01_mask                                (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_00_mask                                (0x00000003)
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_33(data)                               (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_32(data)                               (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_31(data)                               (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_30(data)                               (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_23(data)                               (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_22(data)                               (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_21(data)                               (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_20(data)                               (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_13(data)                               (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_12(data)                               (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_11(data)                               (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_10(data)                               (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_03(data)                               (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_02(data)                               (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_01(data)                               (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_TB_R_tab_r_00(data)                               (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_33(data)                           ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_32(data)                           ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_31(data)                           ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_30(data)                           ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_23(data)                           ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_22(data)                           ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_21(data)                           ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_20(data)                           ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_13(data)                           ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_12(data)                           ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_11(data)                           ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_10(data)                           ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_03(data)                           ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_02(data)                           ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_01(data)                           ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_TB_R_get_tab_r_00(data)                           (0x00000003&(data))

#define  LGD_DITHER_LGD_DITHER_TB_G                                              0x18028E20
#define  LGD_DITHER_LGD_DITHER_TB_G_reg_addr                                     "0xB8028E20"
#define  LGD_DITHER_LGD_DITHER_TB_G_reg                                          0xB8028E20
#define  LGD_DITHER_LGD_DITHER_TB_G_inst_addr                                    "0x0008"
#define  set_LGD_DITHER_LGD_DITHER_TB_G_reg(data)                                (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_TB_G_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_TB_G_reg                                      (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_TB_G_reg))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_33_shift                               (30)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_32_shift                               (28)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_31_shift                               (26)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_30_shift                               (24)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_23_shift                               (22)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_22_shift                               (20)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_21_shift                               (18)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_20_shift                               (16)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_13_shift                               (14)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_12_shift                               (12)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_11_shift                               (10)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_10_shift                               (8)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_03_shift                               (6)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_02_shift                               (4)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_01_shift                               (2)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_00_shift                               (0)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_33_mask                                (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_32_mask                                (0x30000000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_31_mask                                (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_30_mask                                (0x03000000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_23_mask                                (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_22_mask                                (0x00300000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_21_mask                                (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_20_mask                                (0x00030000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_13_mask                                (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_12_mask                                (0x00003000)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_11_mask                                (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_10_mask                                (0x00000300)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_03_mask                                (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_02_mask                                (0x00000030)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_01_mask                                (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_00_mask                                (0x00000003)
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_33(data)                               (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_32(data)                               (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_31(data)                               (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_30(data)                               (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_23(data)                               (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_22(data)                               (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_21(data)                               (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_20(data)                               (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_13(data)                               (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_12(data)                               (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_11(data)                               (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_10(data)                               (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_03(data)                               (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_02(data)                               (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_01(data)                               (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_TB_G_tab_g_00(data)                               (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_33(data)                           ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_32(data)                           ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_31(data)                           ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_30(data)                           ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_23(data)                           ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_22(data)                           ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_21(data)                           ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_20(data)                           ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_13(data)                           ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_12(data)                           ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_11(data)                           ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_10(data)                           ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_03(data)                           ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_02(data)                           ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_01(data)                           ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_TB_G_get_tab_g_00(data)                           (0x00000003&(data))

#define  LGD_DITHER_LGD_DITHER_TB_B                                              0x18028E24
#define  LGD_DITHER_LGD_DITHER_TB_B_reg_addr                                     "0xB8028E24"
#define  LGD_DITHER_LGD_DITHER_TB_B_reg                                          0xB8028E24
#define  LGD_DITHER_LGD_DITHER_TB_B_inst_addr                                    "0x0009"
#define  set_LGD_DITHER_LGD_DITHER_TB_B_reg(data)                                (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_TB_B_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_TB_B_reg                                      (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_TB_B_reg))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_33_shift                               (30)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_32_shift                               (28)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_31_shift                               (26)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_30_shift                               (24)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_23_shift                               (22)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_22_shift                               (20)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_21_shift                               (18)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_20_shift                               (16)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_13_shift                               (14)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_12_shift                               (12)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_11_shift                               (10)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_10_shift                               (8)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_03_shift                               (6)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_02_shift                               (4)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_01_shift                               (2)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_00_shift                               (0)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_33_mask                                (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_32_mask                                (0x30000000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_31_mask                                (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_30_mask                                (0x03000000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_23_mask                                (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_22_mask                                (0x00300000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_21_mask                                (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_20_mask                                (0x00030000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_13_mask                                (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_12_mask                                (0x00003000)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_11_mask                                (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_10_mask                                (0x00000300)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_03_mask                                (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_02_mask                                (0x00000030)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_01_mask                                (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_00_mask                                (0x00000003)
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_33(data)                               (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_32(data)                               (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_31(data)                               (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_30(data)                               (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_23(data)                               (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_22(data)                               (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_21(data)                               (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_20(data)                               (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_13(data)                               (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_12(data)                               (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_11(data)                               (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_10(data)                               (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_03(data)                               (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_02(data)                               (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_01(data)                               (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_TB_B_tab_b_00(data)                               (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_33(data)                           ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_32(data)                           ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_31(data)                           ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_30(data)                           ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_23(data)                           ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_22(data)                           ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_21(data)                           ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_20(data)                           ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_13(data)                           ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_12(data)                           ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_11(data)                           ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_10(data)                           ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_03(data)                           ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_02(data)                           ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_01(data)                           ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_TB_B_get_tab_b_00(data)                           (0x00000003&(data))

#define  LGD_DITHER_LGD_DITHER_Temp                                              0x18028E28
#define  LGD_DITHER_LGD_DITHER_Temp_reg_addr                                     "0xB8028E28"
#define  LGD_DITHER_LGD_DITHER_Temp_reg                                          0xB8028E28
#define  LGD_DITHER_LGD_DITHER_Temp_inst_addr                                    "0x000A"
#define  set_LGD_DITHER_LGD_DITHER_Temp_reg(data)                                (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_Temp_reg)=data)
#define  get_LGD_DITHER_LGD_DITHER_Temp_reg                                      (*((volatile unsigned int*)LGD_DITHER_LGD_DITHER_Temp_reg))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_15_shift                         (30)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_14_shift                         (28)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_13_shift                         (26)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_12_shift                         (24)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_11_shift                         (22)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_10_shift                         (20)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_9_shift                          (18)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_8_shift                          (16)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_7_shift                          (14)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_6_shift                          (12)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_5_shift                          (10)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_4_shift                          (8)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_3_shift                          (6)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_2_shift                          (4)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_1_shift                          (2)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_0_shift                          (0)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_15_mask                          (0xC0000000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_14_mask                          (0x30000000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_13_mask                          (0x0C000000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_12_mask                          (0x03000000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_11_mask                          (0x00C00000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_10_mask                          (0x00300000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_9_mask                           (0x000C0000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_8_mask                           (0x00030000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_7_mask                           (0x0000C000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_6_mask                           (0x00003000)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_5_mask                           (0x00000C00)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_4_mask                           (0x00000300)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_3_mask                           (0x000000C0)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_2_mask                           (0x00000030)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_1_mask                           (0x0000000C)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_0_mask                           (0x00000003)
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_15(data)                         (0xC0000000&((data)<<30))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_14(data)                         (0x30000000&((data)<<28))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_13(data)                         (0x0C000000&((data)<<26))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_12(data)                         (0x03000000&((data)<<24))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_11(data)                         (0x00C00000&((data)<<22))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_10(data)                         (0x00300000&((data)<<20))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_9(data)                          (0x000C0000&((data)<<18))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_8(data)                          (0x00030000&((data)<<16))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_7(data)                          (0x0000C000&((data)<<14))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_6(data)                          (0x00003000&((data)<<12))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_5(data)                          (0x00000C00&((data)<<10))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_4(data)                          (0x00000300&((data)<<8))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_3(data)                          (0x000000C0&((data)<<6))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_2(data)                          (0x00000030&((data)<<4))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_1(data)                          (0x0000000C&((data)<<2))
#define  LGD_DITHER_LGD_DITHER_Temp_temp_offset_0(data)                          (0x00000003&(data))
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_15(data)                     ((0xC0000000&(data))>>30)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_14(data)                     ((0x30000000&(data))>>28)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_13(data)                     ((0x0C000000&(data))>>26)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_12(data)                     ((0x03000000&(data))>>24)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_11(data)                     ((0x00C00000&(data))>>22)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_10(data)                     ((0x00300000&(data))>>20)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_9(data)                      ((0x000C0000&(data))>>18)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_8(data)                      ((0x00030000&(data))>>16)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_7(data)                      ((0x0000C000&(data))>>14)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_6(data)                      ((0x00003000&(data))>>12)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_5(data)                      ((0x00000C00&(data))>>10)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_4(data)                      ((0x00000300&(data))>>8)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_3(data)                      ((0x000000C0&(data))>>6)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_2(data)                      ((0x00000030&(data))>>4)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_1(data)                      ((0x0000000C&(data))>>2)
#define  LGD_DITHER_LGD_DITHER_Temp_get_temp_offset_0(data)                      (0x00000003&(data))

#define  LGD_DITHER_PCID_DITHER_CTRL                                             0x18028E50
#define  LGD_DITHER_PCID_DITHER_CTRL_reg_addr                                    "0xB8028E50"
#define  LGD_DITHER_PCID_DITHER_CTRL_reg                                         0xB8028E50
#define  LGD_DITHER_PCID_DITHER_CTRL_inst_addr                                   "0x000B"
#define  set_LGD_DITHER_PCID_DITHER_CTRL_reg(data)                               (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_CTRL_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_CTRL_reg                                     (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_CTRL_reg))
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_dither_en_shift                        (5)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_temporal_enable_shift                  (4)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_value_sign_shift                       (3)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_dithering_mode_shift                   (2)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_v_modulation_shift                     (1)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_h_modulation_shift                     (0)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_dither_en_mask                         (0x00000020)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_temporal_enable_mask                   (0x00000010)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_value_sign_mask                        (0x00000008)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_dithering_mode_mask                    (0x00000004)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_v_modulation_mask                      (0x00000002)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_h_modulation_mask                      (0x00000001)
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_dither_en(data)                        (0x00000020&((data)<<5))
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_temporal_enable(data)                  (0x00000010&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_value_sign(data)                       (0x00000008&((data)<<3))
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_dithering_mode(data)                   (0x00000004&((data)<<2))
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_v_modulation(data)                     (0x00000002&((data)<<1))
#define  LGD_DITHER_PCID_DITHER_CTRL_pcid_h_modulation(data)                     (0x00000001&(data))
#define  LGD_DITHER_PCID_DITHER_CTRL_get_pcid_dither_en(data)                    ((0x00000020&(data))>>5)
#define  LGD_DITHER_PCID_DITHER_CTRL_get_pcid_temporal_enable(data)              ((0x00000010&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_CTRL_get_pcid_value_sign(data)                   ((0x00000008&(data))>>3)
#define  LGD_DITHER_PCID_DITHER_CTRL_get_pcid_dithering_mode(data)               ((0x00000004&(data))>>2)
#define  LGD_DITHER_PCID_DITHER_CTRL_get_pcid_v_modulation(data)                 ((0x00000002&(data))>>1)
#define  LGD_DITHER_PCID_DITHER_CTRL_get_pcid_h_modulation(data)                 (0x00000001&(data))

#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15                                      0x18028E54
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_reg_addr                             "0xB8028E54"
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_reg                                  0xB8028E54
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_inst_addr                            "0x000C"
#define  set_LGD_DITHER_PCID_DITHER_SEQ_R_00_15_reg(data)                        (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_R_00_15_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_SEQ_R_00_15_reg                              (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_R_00_15_reg))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_15_shift                  (30)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_14_shift                  (28)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_13_shift                  (26)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_12_shift                  (24)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_11_shift                  (22)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_10_shift                  (20)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_9_shift                   (18)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_8_shift                   (16)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_7_shift                   (14)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_6_shift                   (12)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_5_shift                   (10)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_4_shift                   (8)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_3_shift                   (6)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_2_shift                   (4)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_1_shift                   (2)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_0_shift                   (0)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_15_mask                   (0xC0000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_14_mask                   (0x30000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_13_mask                   (0x0C000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_12_mask                   (0x03000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_11_mask                   (0x00C00000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_10_mask                   (0x00300000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_9_mask                    (0x000C0000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_8_mask                    (0x00030000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_7_mask                    (0x0000C000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_6_mask                    (0x00003000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_5_mask                    (0x00000C00)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_4_mask                    (0x00000300)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_3_mask                    (0x000000C0)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_2_mask                    (0x00000030)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_1_mask                    (0x0000000C)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_0_mask                    (0x00000003)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_15(data)                  (0xC0000000&((data)<<30))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_14(data)                  (0x30000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_13(data)                  (0x0C000000&((data)<<26))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_12(data)                  (0x03000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_11(data)                  (0x00C00000&((data)<<22))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_10(data)                  (0x00300000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_9(data)                   (0x000C0000&((data)<<18))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_8(data)                   (0x00030000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_7(data)                   (0x0000C000&((data)<<14))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_6(data)                   (0x00003000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_5(data)                   (0x00000C00&((data)<<10))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_4(data)                   (0x00000300&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_3(data)                   (0x000000C0&((data)<<6))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_2(data)                   (0x00000030&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_1(data)                   (0x0000000C&((data)<<2))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_pcid_seq_r_0(data)                   (0x00000003&(data))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_15(data)              ((0xC0000000&(data))>>30)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_14(data)              ((0x30000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_13(data)              ((0x0C000000&(data))>>26)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_12(data)              ((0x03000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_11(data)              ((0x00C00000&(data))>>22)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_10(data)              ((0x00300000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_9(data)               ((0x000C0000&(data))>>18)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_8(data)               ((0x00030000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_7(data)               ((0x0000C000&(data))>>14)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_6(data)               ((0x00003000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_5(data)               ((0x00000C00&(data))>>10)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_4(data)               ((0x00000300&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_3(data)               ((0x000000C0&(data))>>6)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_2(data)               ((0x00000030&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_1(data)               ((0x0000000C&(data))>>2)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_00_15_get_pcid_seq_r_0(data)               (0x00000003&(data))

#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31                                      0x18028E58
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_reg_addr                             "0xB8028E58"
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_reg                                  0xB8028E58
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_inst_addr                            "0x000D"
#define  set_LGD_DITHER_PCID_DITHER_SEQ_R_16_31_reg(data)                        (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_R_16_31_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_SEQ_R_16_31_reg                              (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_R_16_31_reg))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_31_shift                  (30)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_30_shift                  (28)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_29_shift                  (26)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_28_shift                  (24)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_27_shift                  (22)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_26_shift                  (20)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_25_shift                  (18)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_24_shift                  (16)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_23_shift                  (14)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_22_shift                  (12)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_21_shift                  (10)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_20_shift                  (8)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_19_shift                  (6)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_18_shift                  (4)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_17_shift                  (2)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_16_shift                  (0)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_31_mask                   (0xC0000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_30_mask                   (0x30000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_29_mask                   (0x0C000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_28_mask                   (0x03000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_27_mask                   (0x00C00000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_26_mask                   (0x00300000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_25_mask                   (0x000C0000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_24_mask                   (0x00030000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_23_mask                   (0x0000C000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_22_mask                   (0x00003000)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_21_mask                   (0x00000C00)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_20_mask                   (0x00000300)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_19_mask                   (0x000000C0)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_18_mask                   (0x00000030)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_17_mask                   (0x0000000C)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_16_mask                   (0x00000003)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_31(data)                  (0xC0000000&((data)<<30))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_30(data)                  (0x30000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_29(data)                  (0x0C000000&((data)<<26))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_28(data)                  (0x03000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_27(data)                  (0x00C00000&((data)<<22))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_26(data)                  (0x00300000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_25(data)                  (0x000C0000&((data)<<18))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_24(data)                  (0x00030000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_23(data)                  (0x0000C000&((data)<<14))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_22(data)                  (0x00003000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_21(data)                  (0x00000C00&((data)<<10))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_20(data)                  (0x00000300&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_19(data)                  (0x000000C0&((data)<<6))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_18(data)                  (0x00000030&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_17(data)                  (0x0000000C&((data)<<2))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_pcid_seq_r_16(data)                  (0x00000003&(data))
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_31(data)              ((0xC0000000&(data))>>30)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_30(data)              ((0x30000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_29(data)              ((0x0C000000&(data))>>26)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_28(data)              ((0x03000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_27(data)              ((0x00C00000&(data))>>22)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_26(data)              ((0x00300000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_25(data)              ((0x000C0000&(data))>>18)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_24(data)              ((0x00030000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_23(data)              ((0x0000C000&(data))>>14)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_22(data)              ((0x00003000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_21(data)              ((0x00000C00&(data))>>10)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_20(data)              ((0x00000300&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_19(data)              ((0x000000C0&(data))>>6)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_18(data)              ((0x00000030&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_17(data)              ((0x0000000C&(data))>>2)
#define  LGD_DITHER_PCID_DITHER_SEQ_R_16_31_get_pcid_seq_r_16(data)              (0x00000003&(data))

#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15                                      0x18028E5C
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_reg_addr                             "0xB8028E5C"
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_reg                                  0xB8028E5C
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_inst_addr                            "0x000E"
#define  set_LGD_DITHER_PCID_DITHER_SEQ_G_00_15_reg(data)                        (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_G_00_15_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_SEQ_G_00_15_reg                              (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_G_00_15_reg))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_15_shift                  (30)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_14_shift                  (28)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_13_shift                  (26)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_12_shift                  (24)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_11_shift                  (22)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_10_shift                  (20)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_9_shift                   (18)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_8_shift                   (16)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_7_shift                   (14)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_6_shift                   (12)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_5_shift                   (10)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_4_shift                   (8)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_3_shift                   (6)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_2_shift                   (4)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_1_shift                   (2)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_0_shift                   (0)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_15_mask                   (0xC0000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_14_mask                   (0x30000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_13_mask                   (0x0C000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_12_mask                   (0x03000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_11_mask                   (0x00C00000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_10_mask                   (0x00300000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_9_mask                    (0x000C0000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_8_mask                    (0x00030000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_7_mask                    (0x0000C000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_6_mask                    (0x00003000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_5_mask                    (0x00000C00)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_4_mask                    (0x00000300)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_3_mask                    (0x000000C0)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_2_mask                    (0x00000030)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_1_mask                    (0x0000000C)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_0_mask                    (0x00000003)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_15(data)                  (0xC0000000&((data)<<30))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_14(data)                  (0x30000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_13(data)                  (0x0C000000&((data)<<26))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_12(data)                  (0x03000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_11(data)                  (0x00C00000&((data)<<22))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_10(data)                  (0x00300000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_9(data)                   (0x000C0000&((data)<<18))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_8(data)                   (0x00030000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_7(data)                   (0x0000C000&((data)<<14))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_6(data)                   (0x00003000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_5(data)                   (0x00000C00&((data)<<10))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_4(data)                   (0x00000300&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_3(data)                   (0x000000C0&((data)<<6))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_2(data)                   (0x00000030&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_1(data)                   (0x0000000C&((data)<<2))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_pcid_seq_g_0(data)                   (0x00000003&(data))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_15(data)              ((0xC0000000&(data))>>30)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_14(data)              ((0x30000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_13(data)              ((0x0C000000&(data))>>26)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_12(data)              ((0x03000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_11(data)              ((0x00C00000&(data))>>22)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_10(data)              ((0x00300000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_9(data)               ((0x000C0000&(data))>>18)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_8(data)               ((0x00030000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_7(data)               ((0x0000C000&(data))>>14)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_6(data)               ((0x00003000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_5(data)               ((0x00000C00&(data))>>10)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_4(data)               ((0x00000300&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_3(data)               ((0x000000C0&(data))>>6)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_2(data)               ((0x00000030&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_1(data)               ((0x0000000C&(data))>>2)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_00_15_get_pcid_seq_g_0(data)               (0x00000003&(data))

#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31                                      0x18028E60
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_reg_addr                             "0xB8028E60"
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_reg                                  0xB8028E60
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_inst_addr                            "0x000F"
#define  set_LGD_DITHER_PCID_DITHER_SEQ_G_16_31_reg(data)                        (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_G_16_31_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_SEQ_G_16_31_reg                              (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_G_16_31_reg))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_31_shift                  (30)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_30_shift                  (28)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_29_shift                  (26)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_28_shift                  (24)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_27_shift                  (22)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_26_shift                  (20)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_25_shift                  (18)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_24_shift                  (16)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_23_shift                  (14)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_22_shift                  (12)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_21_shift                  (10)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_20_shift                  (8)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_19_shift                  (6)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_18_shift                  (4)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_17_shift                  (2)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_16_shift                  (0)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_31_mask                   (0xC0000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_30_mask                   (0x30000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_29_mask                   (0x0C000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_28_mask                   (0x03000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_27_mask                   (0x00C00000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_26_mask                   (0x00300000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_25_mask                   (0x000C0000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_24_mask                   (0x00030000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_23_mask                   (0x0000C000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_22_mask                   (0x00003000)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_21_mask                   (0x00000C00)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_20_mask                   (0x00000300)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_19_mask                   (0x000000C0)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_18_mask                   (0x00000030)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_17_mask                   (0x0000000C)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_16_mask                   (0x00000003)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_31(data)                  (0xC0000000&((data)<<30))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_30(data)                  (0x30000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_29(data)                  (0x0C000000&((data)<<26))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_28(data)                  (0x03000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_27(data)                  (0x00C00000&((data)<<22))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_26(data)                  (0x00300000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_25(data)                  (0x000C0000&((data)<<18))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_24(data)                  (0x00030000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_23(data)                  (0x0000C000&((data)<<14))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_22(data)                  (0x00003000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_21(data)                  (0x00000C00&((data)<<10))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_20(data)                  (0x00000300&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_19(data)                  (0x000000C0&((data)<<6))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_18(data)                  (0x00000030&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_17(data)                  (0x0000000C&((data)<<2))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_pcid_seq_g_16(data)                  (0x00000003&(data))
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_31(data)              ((0xC0000000&(data))>>30)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_30(data)              ((0x30000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_29(data)              ((0x0C000000&(data))>>26)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_28(data)              ((0x03000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_27(data)              ((0x00C00000&(data))>>22)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_26(data)              ((0x00300000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_25(data)              ((0x000C0000&(data))>>18)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_24(data)              ((0x00030000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_23(data)              ((0x0000C000&(data))>>14)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_22(data)              ((0x00003000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_21(data)              ((0x00000C00&(data))>>10)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_20(data)              ((0x00000300&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_19(data)              ((0x000000C0&(data))>>6)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_18(data)              ((0x00000030&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_17(data)              ((0x0000000C&(data))>>2)
#define  LGD_DITHER_PCID_DITHER_SEQ_G_16_31_get_pcid_seq_g_16(data)              (0x00000003&(data))

#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15                                      0x18028E64
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_reg_addr                             "0xB8028E64"
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_reg                                  0xB8028E64
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_inst_addr                            "0x0010"
#define  set_LGD_DITHER_PCID_DITHER_SEQ_B_00_15_reg(data)                        (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_B_00_15_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_SEQ_B_00_15_reg                              (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_B_00_15_reg))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_15_shift                  (30)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_14_shift                  (28)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_13_shift                  (26)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_12_shift                  (24)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_11_shift                  (22)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_10_shift                  (20)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_9_shift                   (18)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_8_shift                   (16)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_7_shift                   (14)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_6_shift                   (12)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_5_shift                   (10)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_4_shift                   (8)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_3_shift                   (6)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_2_shift                   (4)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_1_shift                   (2)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_0_shift                   (0)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_15_mask                   (0xC0000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_14_mask                   (0x30000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_13_mask                   (0x0C000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_12_mask                   (0x03000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_11_mask                   (0x00C00000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_10_mask                   (0x00300000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_9_mask                    (0x000C0000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_8_mask                    (0x00030000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_7_mask                    (0x0000C000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_6_mask                    (0x00003000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_5_mask                    (0x00000C00)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_4_mask                    (0x00000300)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_3_mask                    (0x000000C0)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_2_mask                    (0x00000030)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_1_mask                    (0x0000000C)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_0_mask                    (0x00000003)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_15(data)                  (0xC0000000&((data)<<30))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_14(data)                  (0x30000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_13(data)                  (0x0C000000&((data)<<26))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_12(data)                  (0x03000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_11(data)                  (0x00C00000&((data)<<22))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_10(data)                  (0x00300000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_9(data)                   (0x000C0000&((data)<<18))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_8(data)                   (0x00030000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_7(data)                   (0x0000C000&((data)<<14))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_6(data)                   (0x00003000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_5(data)                   (0x00000C00&((data)<<10))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_4(data)                   (0x00000300&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_3(data)                   (0x000000C0&((data)<<6))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_2(data)                   (0x00000030&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_1(data)                   (0x0000000C&((data)<<2))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_pcid_seq_b_0(data)                   (0x00000003&(data))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_15(data)              ((0xC0000000&(data))>>30)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_14(data)              ((0x30000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_13(data)              ((0x0C000000&(data))>>26)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_12(data)              ((0x03000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_11(data)              ((0x00C00000&(data))>>22)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_10(data)              ((0x00300000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_9(data)               ((0x000C0000&(data))>>18)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_8(data)               ((0x00030000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_7(data)               ((0x0000C000&(data))>>14)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_6(data)               ((0x00003000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_5(data)               ((0x00000C00&(data))>>10)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_4(data)               ((0x00000300&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_3(data)               ((0x000000C0&(data))>>6)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_2(data)               ((0x00000030&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_1(data)               ((0x0000000C&(data))>>2)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_00_15_get_pcid_seq_b_0(data)               (0x00000003&(data))

#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31                                      0x18028E68
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_reg_addr                             "0xB8028E68"
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_reg                                  0xB8028E68
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_inst_addr                            "0x0011"
#define  set_LGD_DITHER_PCID_DITHER_SEQ_B_16_31_reg(data)                        (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_B_16_31_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_SEQ_B_16_31_reg                              (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_SEQ_B_16_31_reg))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_31_shift                  (30)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_30_shift                  (28)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_29_shift                  (26)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_28_shift                  (24)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_27_shift                  (22)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_26_shift                  (20)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_25_shift                  (18)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_24_shift                  (16)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_23_shift                  (14)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_22_shift                  (12)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_21_shift                  (10)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_20_shift                  (8)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_19_shift                  (6)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_18_shift                  (4)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_17_shift                  (2)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_16_shift                  (0)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_31_mask                   (0xC0000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_30_mask                   (0x30000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_29_mask                   (0x0C000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_28_mask                   (0x03000000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_27_mask                   (0x00C00000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_26_mask                   (0x00300000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_25_mask                   (0x000C0000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_24_mask                   (0x00030000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_23_mask                   (0x0000C000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_22_mask                   (0x00003000)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_21_mask                   (0x00000C00)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_20_mask                   (0x00000300)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_19_mask                   (0x000000C0)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_18_mask                   (0x00000030)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_17_mask                   (0x0000000C)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_16_mask                   (0x00000003)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_31(data)                  (0xC0000000&((data)<<30))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_30(data)                  (0x30000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_29(data)                  (0x0C000000&((data)<<26))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_28(data)                  (0x03000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_27(data)                  (0x00C00000&((data)<<22))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_26(data)                  (0x00300000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_25(data)                  (0x000C0000&((data)<<18))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_24(data)                  (0x00030000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_23(data)                  (0x0000C000&((data)<<14))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_22(data)                  (0x00003000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_21(data)                  (0x00000C00&((data)<<10))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_20(data)                  (0x00000300&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_19(data)                  (0x000000C0&((data)<<6))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_18(data)                  (0x00000030&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_17(data)                  (0x0000000C&((data)<<2))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_pcid_seq_b_16(data)                  (0x00000003&(data))
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_31(data)              ((0xC0000000&(data))>>30)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_30(data)              ((0x30000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_29(data)              ((0x0C000000&(data))>>26)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_28(data)              ((0x03000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_27(data)              ((0x00C00000&(data))>>22)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_26(data)              ((0x00300000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_25(data)              ((0x000C0000&(data))>>18)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_24(data)              ((0x00030000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_23(data)              ((0x0000C000&(data))>>14)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_22(data)              ((0x00003000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_21(data)              ((0x00000C00&(data))>>10)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_20(data)              ((0x00000300&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_19(data)              ((0x000000C0&(data))>>6)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_18(data)              ((0x00000030&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_17(data)              ((0x0000000C&(data))>>2)
#define  LGD_DITHER_PCID_DITHER_SEQ_B_16_31_get_pcid_seq_b_16(data)              (0x00000003&(data))

#define  LGD_DITHER_PCID_DITHER_TB_R_01                                          0x18028E6C
#define  LGD_DITHER_PCID_DITHER_TB_R_01_reg_addr                                 "0xB8028E6C"
#define  LGD_DITHER_PCID_DITHER_TB_R_01_reg                                      0xB8028E6C
#define  LGD_DITHER_PCID_DITHER_TB_R_01_inst_addr                                "0x0012"
#define  set_LGD_DITHER_PCID_DITHER_TB_R_01_reg(data)                            (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_R_01_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_TB_R_01_reg                                  (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_R_01_reg))
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_13_shift                      (28)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_12_shift                      (24)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_11_shift                      (20)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_10_shift                      (16)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_03_shift                      (12)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_02_shift                      (8)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_01_shift                      (4)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_00_shift                      (0)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_13_mask                       (0xF0000000)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_12_mask                       (0x0F000000)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_11_mask                       (0x00F00000)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_10_mask                       (0x000F0000)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_03_mask                       (0x0000F000)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_02_mask                       (0x00000F00)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_01_mask                       (0x000000F0)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_00_mask                       (0x0000000F)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_13(data)                      (0xF0000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_12(data)                      (0x0F000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_11(data)                      (0x00F00000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_10(data)                      (0x000F0000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_03(data)                      (0x0000F000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_02(data)                      (0x00000F00&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_01(data)                      (0x000000F0&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_TB_R_01_pcid_tab_r_00(data)                      (0x0000000F&(data))
#define  LGD_DITHER_PCID_DITHER_TB_R_01_get_pcid_tab_r_13(data)                  ((0xF0000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_get_pcid_tab_r_12(data)                  ((0x0F000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_get_pcid_tab_r_11(data)                  ((0x00F00000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_get_pcid_tab_r_10(data)                  ((0x000F0000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_get_pcid_tab_r_03(data)                  ((0x0000F000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_get_pcid_tab_r_02(data)                  ((0x00000F00&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_get_pcid_tab_r_01(data)                  ((0x000000F0&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_TB_R_01_get_pcid_tab_r_00(data)                  (0x0000000F&(data))

#define  LGD_DITHER_PCID_DITHER_TB_R_23                                          0x18028E70
#define  LGD_DITHER_PCID_DITHER_TB_R_23_reg_addr                                 "0xB8028E70"
#define  LGD_DITHER_PCID_DITHER_TB_R_23_reg                                      0xB8028E70
#define  LGD_DITHER_PCID_DITHER_TB_R_23_inst_addr                                "0x0013"
#define  set_LGD_DITHER_PCID_DITHER_TB_R_23_reg(data)                            (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_R_23_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_TB_R_23_reg                                  (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_R_23_reg))
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_33_shift                      (28)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_32_shift                      (24)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_31_shift                      (20)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_30_shift                      (16)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_23_shift                      (12)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_22_shift                      (8)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_21_shift                      (4)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_20_shift                      (0)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_33_mask                       (0xF0000000)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_32_mask                       (0x0F000000)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_31_mask                       (0x00F00000)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_30_mask                       (0x000F0000)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_23_mask                       (0x0000F000)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_22_mask                       (0x00000F00)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_21_mask                       (0x000000F0)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_20_mask                       (0x0000000F)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_33(data)                      (0xF0000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_32(data)                      (0x0F000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_31(data)                      (0x00F00000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_30(data)                      (0x000F0000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_23(data)                      (0x0000F000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_22(data)                      (0x00000F00&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_21(data)                      (0x000000F0&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_TB_R_23_pcid_tab_r_20(data)                      (0x0000000F&(data))
#define  LGD_DITHER_PCID_DITHER_TB_R_23_get_pcid_tab_r_33(data)                  ((0xF0000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_get_pcid_tab_r_32(data)                  ((0x0F000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_get_pcid_tab_r_31(data)                  ((0x00F00000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_get_pcid_tab_r_30(data)                  ((0x000F0000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_get_pcid_tab_r_23(data)                  ((0x0000F000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_get_pcid_tab_r_22(data)                  ((0x00000F00&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_get_pcid_tab_r_21(data)                  ((0x000000F0&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_TB_R_23_get_pcid_tab_r_20(data)                  (0x0000000F&(data))

#define  LGD_DITHER_PCID_DITHER_TB_G_01                                          0x18028E74
#define  LGD_DITHER_PCID_DITHER_TB_G_01_reg_addr                                 "0xB8028E74"
#define  LGD_DITHER_PCID_DITHER_TB_G_01_reg                                      0xB8028E74
#define  LGD_DITHER_PCID_DITHER_TB_G_01_inst_addr                                "0x0014"
#define  set_LGD_DITHER_PCID_DITHER_TB_G_01_reg(data)                            (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_G_01_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_TB_G_01_reg                                  (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_G_01_reg))
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_13_shift                      (28)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_12_shift                      (24)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_11_shift                      (20)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_10_shift                      (16)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_03_shift                      (12)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_02_shift                      (8)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_01_shift                      (4)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_00_shift                      (0)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_13_mask                       (0xF0000000)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_12_mask                       (0x0F000000)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_11_mask                       (0x00F00000)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_10_mask                       (0x000F0000)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_03_mask                       (0x0000F000)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_02_mask                       (0x00000F00)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_01_mask                       (0x000000F0)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_00_mask                       (0x0000000F)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_13(data)                      (0xF0000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_12(data)                      (0x0F000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_11(data)                      (0x00F00000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_10(data)                      (0x000F0000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_03(data)                      (0x0000F000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_02(data)                      (0x00000F00&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_01(data)                      (0x000000F0&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_TB_G_01_pcid_tab_g_00(data)                      (0x0000000F&(data))
#define  LGD_DITHER_PCID_DITHER_TB_G_01_get_pcid_tab_g_13(data)                  ((0xF0000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_get_pcid_tab_g_12(data)                  ((0x0F000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_get_pcid_tab_g_11(data)                  ((0x00F00000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_get_pcid_tab_g_10(data)                  ((0x000F0000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_get_pcid_tab_g_03(data)                  ((0x0000F000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_get_pcid_tab_g_02(data)                  ((0x00000F00&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_get_pcid_tab_g_01(data)                  ((0x000000F0&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_TB_G_01_get_pcid_tab_g_00(data)                  (0x0000000F&(data))

#define  LGD_DITHER_PCID_DITHER_TB_G_23                                          0x18028E78
#define  LGD_DITHER_PCID_DITHER_TB_G_23_reg_addr                                 "0xB8028E78"
#define  LGD_DITHER_PCID_DITHER_TB_G_23_reg                                      0xB8028E78
#define  LGD_DITHER_PCID_DITHER_TB_G_23_inst_addr                                "0x0015"
#define  set_LGD_DITHER_PCID_DITHER_TB_G_23_reg(data)                            (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_G_23_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_TB_G_23_reg                                  (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_G_23_reg))
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_33_shift                      (28)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_32_shift                      (24)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_31_shift                      (20)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_30_shift                      (16)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_23_shift                      (12)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_22_shift                      (8)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_21_shift                      (4)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_20_shift                      (0)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_33_mask                       (0xF0000000)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_32_mask                       (0x0F000000)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_31_mask                       (0x00F00000)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_30_mask                       (0x000F0000)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_23_mask                       (0x0000F000)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_22_mask                       (0x00000F00)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_21_mask                       (0x000000F0)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_20_mask                       (0x0000000F)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_33(data)                      (0xF0000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_32(data)                      (0x0F000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_31(data)                      (0x00F00000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_30(data)                      (0x000F0000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_23(data)                      (0x0000F000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_22(data)                      (0x00000F00&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_21(data)                      (0x000000F0&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_TB_G_23_pcid_tab_g_20(data)                      (0x0000000F&(data))
#define  LGD_DITHER_PCID_DITHER_TB_G_23_get_pcid_tab_g_33(data)                  ((0xF0000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_get_pcid_tab_g_32(data)                  ((0x0F000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_get_pcid_tab_g_31(data)                  ((0x00F00000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_get_pcid_tab_g_30(data)                  ((0x000F0000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_get_pcid_tab_g_23(data)                  ((0x0000F000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_get_pcid_tab_g_22(data)                  ((0x00000F00&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_get_pcid_tab_g_21(data)                  ((0x000000F0&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_TB_G_23_get_pcid_tab_g_20(data)                  (0x0000000F&(data))

#define  LGD_DITHER_PCID_DITHER_TB_B_01                                          0x18028E7C
#define  LGD_DITHER_PCID_DITHER_TB_B_01_reg_addr                                 "0xB8028E7C"
#define  LGD_DITHER_PCID_DITHER_TB_B_01_reg                                      0xB8028E7C
#define  LGD_DITHER_PCID_DITHER_TB_B_01_inst_addr                                "0x0016"
#define  set_LGD_DITHER_PCID_DITHER_TB_B_01_reg(data)                            (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_B_01_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_TB_B_01_reg                                  (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_B_01_reg))
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_13_shift                      (28)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_12_shift                      (24)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_11_shift                      (20)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_10_shift                      (16)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_03_shift                      (12)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_02_shift                      (8)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_01_shift                      (4)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_00_shift                      (0)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_13_mask                       (0xF0000000)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_12_mask                       (0x0F000000)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_11_mask                       (0x00F00000)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_10_mask                       (0x000F0000)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_03_mask                       (0x0000F000)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_02_mask                       (0x00000F00)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_01_mask                       (0x000000F0)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_00_mask                       (0x0000000F)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_13(data)                      (0xF0000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_12(data)                      (0x0F000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_11(data)                      (0x00F00000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_10(data)                      (0x000F0000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_03(data)                      (0x0000F000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_02(data)                      (0x00000F00&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_01(data)                      (0x000000F0&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_TB_B_01_pcid_tab_b_00(data)                      (0x0000000F&(data))
#define  LGD_DITHER_PCID_DITHER_TB_B_01_get_pcid_tab_b_13(data)                  ((0xF0000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_get_pcid_tab_b_12(data)                  ((0x0F000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_get_pcid_tab_b_11(data)                  ((0x00F00000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_get_pcid_tab_b_10(data)                  ((0x000F0000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_get_pcid_tab_b_03(data)                  ((0x0000F000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_get_pcid_tab_b_02(data)                  ((0x00000F00&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_get_pcid_tab_b_01(data)                  ((0x000000F0&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_TB_B_01_get_pcid_tab_b_00(data)                  (0x0000000F&(data))

#define  LGD_DITHER_PCID_DITHER_TB_B_23                                          0x18028E80
#define  LGD_DITHER_PCID_DITHER_TB_B_23_reg_addr                                 "0xB8028E80"
#define  LGD_DITHER_PCID_DITHER_TB_B_23_reg                                      0xB8028E80
#define  LGD_DITHER_PCID_DITHER_TB_B_23_inst_addr                                "0x0017"
#define  set_LGD_DITHER_PCID_DITHER_TB_B_23_reg(data)                            (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_B_23_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_TB_B_23_reg                                  (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_TB_B_23_reg))
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_33_shift                      (28)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_32_shift                      (24)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_31_shift                      (20)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_30_shift                      (16)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_23_shift                      (12)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_22_shift                      (8)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_21_shift                      (4)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_20_shift                      (0)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_33_mask                       (0xF0000000)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_32_mask                       (0x0F000000)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_31_mask                       (0x00F00000)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_30_mask                       (0x000F0000)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_23_mask                       (0x0000F000)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_22_mask                       (0x00000F00)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_21_mask                       (0x000000F0)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_20_mask                       (0x0000000F)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_33(data)                      (0xF0000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_32(data)                      (0x0F000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_31(data)                      (0x00F00000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_30(data)                      (0x000F0000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_23(data)                      (0x0000F000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_22(data)                      (0x00000F00&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_21(data)                      (0x000000F0&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_TB_B_23_pcid_tab_b_20(data)                      (0x0000000F&(data))
#define  LGD_DITHER_PCID_DITHER_TB_B_23_get_pcid_tab_b_33(data)                  ((0xF0000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_get_pcid_tab_b_32(data)                  ((0x0F000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_get_pcid_tab_b_31(data)                  ((0x00F00000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_get_pcid_tab_b_30(data)                  ((0x000F0000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_get_pcid_tab_b_23(data)                  ((0x0000F000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_get_pcid_tab_b_22(data)                  ((0x00000F00&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_get_pcid_tab_b_21(data)                  ((0x000000F0&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_TB_B_23_get_pcid_tab_b_20(data)                  (0x0000000F&(data))

#define  LGD_DITHER_PCID_DITHER_Temp                                             0x18028E84
#define  LGD_DITHER_PCID_DITHER_Temp_reg_addr                                    "0xB8028E84"
#define  LGD_DITHER_PCID_DITHER_Temp_reg                                         0xB8028E84
#define  LGD_DITHER_PCID_DITHER_Temp_inst_addr                                   "0x0018"
#define  set_LGD_DITHER_PCID_DITHER_Temp_reg(data)                               (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_Temp_reg)=data)
#define  get_LGD_DITHER_PCID_DITHER_Temp_reg                                     (*((volatile unsigned int*)LGD_DITHER_PCID_DITHER_Temp_reg))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_15_shift                   (30)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_14_shift                   (28)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_13_shift                   (26)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_12_shift                   (24)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_11_shift                   (22)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_10_shift                   (20)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_9_shift                    (18)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_8_shift                    (16)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_7_shift                    (14)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_6_shift                    (12)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_5_shift                    (10)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_4_shift                    (8)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_3_shift                    (6)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_2_shift                    (4)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_1_shift                    (2)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_0_shift                    (0)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_15_mask                    (0xC0000000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_14_mask                    (0x30000000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_13_mask                    (0x0C000000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_12_mask                    (0x03000000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_11_mask                    (0x00C00000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_10_mask                    (0x00300000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_9_mask                     (0x000C0000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_8_mask                     (0x00030000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_7_mask                     (0x0000C000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_6_mask                     (0x00003000)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_5_mask                     (0x00000C00)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_4_mask                     (0x00000300)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_3_mask                     (0x000000C0)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_2_mask                     (0x00000030)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_1_mask                     (0x0000000C)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_0_mask                     (0x00000003)
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_15(data)                   (0xC0000000&((data)<<30))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_14(data)                   (0x30000000&((data)<<28))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_13(data)                   (0x0C000000&((data)<<26))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_12(data)                   (0x03000000&((data)<<24))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_11(data)                   (0x00C00000&((data)<<22))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_10(data)                   (0x00300000&((data)<<20))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_9(data)                    (0x000C0000&((data)<<18))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_8(data)                    (0x00030000&((data)<<16))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_7(data)                    (0x0000C000&((data)<<14))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_6(data)                    (0x00003000&((data)<<12))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_5(data)                    (0x00000C00&((data)<<10))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_4(data)                    (0x00000300&((data)<<8))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_3(data)                    (0x000000C0&((data)<<6))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_2(data)                    (0x00000030&((data)<<4))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_1(data)                    (0x0000000C&((data)<<2))
#define  LGD_DITHER_PCID_DITHER_Temp_pcid_temp_offset_0(data)                    (0x00000003&(data))
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_15(data)               ((0xC0000000&(data))>>30)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_14(data)               ((0x30000000&(data))>>28)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_13(data)               ((0x0C000000&(data))>>26)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_12(data)               ((0x03000000&(data))>>24)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_11(data)               ((0x00C00000&(data))>>22)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_10(data)               ((0x00300000&(data))>>20)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_9(data)                ((0x000C0000&(data))>>18)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_8(data)                ((0x00030000&(data))>>16)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_7(data)                ((0x0000C000&(data))>>14)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_6(data)                ((0x00003000&(data))>>12)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_5(data)                ((0x00000C00&(data))>>10)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_4(data)                ((0x00000300&(data))>>8)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_3(data)                ((0x000000C0&(data))>>6)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_2(data)                ((0x00000030&(data))>>4)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_1(data)                ((0x0000000C&(data))>>2)
#define  LGD_DITHER_PCID_DITHER_Temp_get_pcid_temp_offset_0(data)                (0x00000003&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGD_DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  location_sel:1;
        RBus_UInt32  lgd_dither_en:1;
        RBus_UInt32  temporal_enable:1;
        RBus_UInt32  value_sign:1;
        RBus_UInt32  dithering_mode:1;
        RBus_UInt32  v_modulation:1;
        RBus_UInt32  h_modulation:1;
    };
}lgd_dither_lgd_dither_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_15:2;
        RBus_UInt32  seq_r_14:2;
        RBus_UInt32  seq_r_13:2;
        RBus_UInt32  seq_r_12:2;
        RBus_UInt32  seq_r_11:2;
        RBus_UInt32  seq_r_10:2;
        RBus_UInt32  seq_r_9:2;
        RBus_UInt32  seq_r_8:2;
        RBus_UInt32  seq_r_7:2;
        RBus_UInt32  seq_r_6:2;
        RBus_UInt32  seq_r_5:2;
        RBus_UInt32  seq_r_4:2;
        RBus_UInt32  seq_r_3:2;
        RBus_UInt32  seq_r_2:2;
        RBus_UInt32  seq_r_1:2;
        RBus_UInt32  seq_r_0:2;
    };
}lgd_dither_lgd_dither_seq_r_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_31:2;
        RBus_UInt32  seq_r_30:2;
        RBus_UInt32  seq_r_29:2;
        RBus_UInt32  seq_r_28:2;
        RBus_UInt32  seq_r_27:2;
        RBus_UInt32  seq_r_26:2;
        RBus_UInt32  seq_r_25:2;
        RBus_UInt32  seq_r_24:2;
        RBus_UInt32  seq_r_23:2;
        RBus_UInt32  seq_r_22:2;
        RBus_UInt32  seq_r_21:2;
        RBus_UInt32  seq_r_20:2;
        RBus_UInt32  seq_r_19:2;
        RBus_UInt32  seq_r_18:2;
        RBus_UInt32  seq_r_17:2;
        RBus_UInt32  seq_r_16:2;
    };
}lgd_dither_lgd_dither_seq_r_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_15:2;
        RBus_UInt32  seq_g_14:2;
        RBus_UInt32  seq_g_13:2;
        RBus_UInt32  seq_g_12:2;
        RBus_UInt32  seq_g_11:2;
        RBus_UInt32  seq_g_10:2;
        RBus_UInt32  seq_g_9:2;
        RBus_UInt32  seq_g_8:2;
        RBus_UInt32  seq_g_7:2;
        RBus_UInt32  seq_g_6:2;
        RBus_UInt32  seq_g_5:2;
        RBus_UInt32  seq_g_4:2;
        RBus_UInt32  seq_g_3:2;
        RBus_UInt32  seq_g_2:2;
        RBus_UInt32  seq_g_1:2;
        RBus_UInt32  seq_g_0:2;
    };
}lgd_dither_lgd_dither_seq_g_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_31:2;
        RBus_UInt32  seq_g_30:2;
        RBus_UInt32  seq_g_29:2;
        RBus_UInt32  seq_g_28:2;
        RBus_UInt32  seq_g_27:2;
        RBus_UInt32  seq_g_26:2;
        RBus_UInt32  seq_g_25:2;
        RBus_UInt32  seq_g_24:2;
        RBus_UInt32  seq_g_23:2;
        RBus_UInt32  seq_g_22:2;
        RBus_UInt32  seq_g_21:2;
        RBus_UInt32  seq_g_20:2;
        RBus_UInt32  seq_g_19:2;
        RBus_UInt32  seq_g_18:2;
        RBus_UInt32  seq_g_17:2;
        RBus_UInt32  seq_g_16:2;
    };
}lgd_dither_lgd_dither_seq_g_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_15:2;
        RBus_UInt32  seq_b_14:2;
        RBus_UInt32  seq_b_13:2;
        RBus_UInt32  seq_b_12:2;
        RBus_UInt32  seq_b_11:2;
        RBus_UInt32  seq_b_10:2;
        RBus_UInt32  seq_b_9:2;
        RBus_UInt32  seq_b_8:2;
        RBus_UInt32  seq_b_7:2;
        RBus_UInt32  seq_b_6:2;
        RBus_UInt32  seq_b_5:2;
        RBus_UInt32  seq_b_4:2;
        RBus_UInt32  seq_b_3:2;
        RBus_UInt32  seq_b_2:2;
        RBus_UInt32  seq_b_1:2;
        RBus_UInt32  seq_b_0:2;
    };
}lgd_dither_lgd_dither_seq_b_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_31:2;
        RBus_UInt32  seq_b_30:2;
        RBus_UInt32  seq_b_29:2;
        RBus_UInt32  seq_b_28:2;
        RBus_UInt32  seq_b_27:2;
        RBus_UInt32  seq_b_26:2;
        RBus_UInt32  seq_b_25:2;
        RBus_UInt32  seq_b_24:2;
        RBus_UInt32  seq_b_23:2;
        RBus_UInt32  seq_b_22:2;
        RBus_UInt32  seq_b_21:2;
        RBus_UInt32  seq_b_20:2;
        RBus_UInt32  seq_b_19:2;
        RBus_UInt32  seq_b_18:2;
        RBus_UInt32  seq_b_17:2;
        RBus_UInt32  seq_b_16:2;
    };
}lgd_dither_lgd_dither_seq_b_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_33:2;
        RBus_UInt32  tab_r_32:2;
        RBus_UInt32  tab_r_31:2;
        RBus_UInt32  tab_r_30:2;
        RBus_UInt32  tab_r_23:2;
        RBus_UInt32  tab_r_22:2;
        RBus_UInt32  tab_r_21:2;
        RBus_UInt32  tab_r_20:2;
        RBus_UInt32  tab_r_13:2;
        RBus_UInt32  tab_r_12:2;
        RBus_UInt32  tab_r_11:2;
        RBus_UInt32  tab_r_10:2;
        RBus_UInt32  tab_r_03:2;
        RBus_UInt32  tab_r_02:2;
        RBus_UInt32  tab_r_01:2;
        RBus_UInt32  tab_r_00:2;
    };
}lgd_dither_lgd_dither_tb_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_33:2;
        RBus_UInt32  tab_g_32:2;
        RBus_UInt32  tab_g_31:2;
        RBus_UInt32  tab_g_30:2;
        RBus_UInt32  tab_g_23:2;
        RBus_UInt32  tab_g_22:2;
        RBus_UInt32  tab_g_21:2;
        RBus_UInt32  tab_g_20:2;
        RBus_UInt32  tab_g_13:2;
        RBus_UInt32  tab_g_12:2;
        RBus_UInt32  tab_g_11:2;
        RBus_UInt32  tab_g_10:2;
        RBus_UInt32  tab_g_03:2;
        RBus_UInt32  tab_g_02:2;
        RBus_UInt32  tab_g_01:2;
        RBus_UInt32  tab_g_00:2;
    };
}lgd_dither_lgd_dither_tb_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_33:2;
        RBus_UInt32  tab_b_32:2;
        RBus_UInt32  tab_b_31:2;
        RBus_UInt32  tab_b_30:2;
        RBus_UInt32  tab_b_23:2;
        RBus_UInt32  tab_b_22:2;
        RBus_UInt32  tab_b_21:2;
        RBus_UInt32  tab_b_20:2;
        RBus_UInt32  tab_b_13:2;
        RBus_UInt32  tab_b_12:2;
        RBus_UInt32  tab_b_11:2;
        RBus_UInt32  tab_b_10:2;
        RBus_UInt32  tab_b_03:2;
        RBus_UInt32  tab_b_02:2;
        RBus_UInt32  tab_b_01:2;
        RBus_UInt32  tab_b_00:2;
    };
}lgd_dither_lgd_dither_tb_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  temp_offset_15:2;
        RBus_UInt32  temp_offset_14:2;
        RBus_UInt32  temp_offset_13:2;
        RBus_UInt32  temp_offset_12:2;
        RBus_UInt32  temp_offset_11:2;
        RBus_UInt32  temp_offset_10:2;
        RBus_UInt32  temp_offset_9:2;
        RBus_UInt32  temp_offset_8:2;
        RBus_UInt32  temp_offset_7:2;
        RBus_UInt32  temp_offset_6:2;
        RBus_UInt32  temp_offset_5:2;
        RBus_UInt32  temp_offset_4:2;
        RBus_UInt32  temp_offset_3:2;
        RBus_UInt32  temp_offset_2:2;
        RBus_UInt32  temp_offset_1:2;
        RBus_UInt32  temp_offset_0:2;
    };
}lgd_dither_lgd_dither_temp_RBUS;

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
}lgd_dither_pcid_dither_ctrl_RBUS;

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
}lgd_dither_pcid_dither_seq_r_00_15_RBUS;

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
}lgd_dither_pcid_dither_seq_r_16_31_RBUS;

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
}lgd_dither_pcid_dither_seq_g_00_15_RBUS;

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
}lgd_dither_pcid_dither_seq_g_16_31_RBUS;

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
}lgd_dither_pcid_dither_seq_b_00_15_RBUS;

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
}lgd_dither_pcid_dither_seq_b_16_31_RBUS;

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
}lgd_dither_pcid_dither_tb_r_01_RBUS;

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
}lgd_dither_pcid_dither_tb_r_23_RBUS;

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
}lgd_dither_pcid_dither_tb_g_01_RBUS;

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
}lgd_dither_pcid_dither_tb_g_23_RBUS;

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
}lgd_dither_pcid_dither_tb_b_01_RBUS;

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
}lgd_dither_pcid_dither_tb_b_23_RBUS;

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
}lgd_dither_pcid_dither_temp_RBUS;

#else //apply LITTLE_ENDIAN

//======LGD_DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_modulation:1;
        RBus_UInt32  v_modulation:1;
        RBus_UInt32  dithering_mode:1;
        RBus_UInt32  value_sign:1;
        RBus_UInt32  temporal_enable:1;
        RBus_UInt32  lgd_dither_en:1;
        RBus_UInt32  location_sel:1;
        RBus_UInt32  res1:25;
    };
}lgd_dither_lgd_dither_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_0:2;
        RBus_UInt32  seq_r_1:2;
        RBus_UInt32  seq_r_2:2;
        RBus_UInt32  seq_r_3:2;
        RBus_UInt32  seq_r_4:2;
        RBus_UInt32  seq_r_5:2;
        RBus_UInt32  seq_r_6:2;
        RBus_UInt32  seq_r_7:2;
        RBus_UInt32  seq_r_8:2;
        RBus_UInt32  seq_r_9:2;
        RBus_UInt32  seq_r_10:2;
        RBus_UInt32  seq_r_11:2;
        RBus_UInt32  seq_r_12:2;
        RBus_UInt32  seq_r_13:2;
        RBus_UInt32  seq_r_14:2;
        RBus_UInt32  seq_r_15:2;
    };
}lgd_dither_lgd_dither_seq_r_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_16:2;
        RBus_UInt32  seq_r_17:2;
        RBus_UInt32  seq_r_18:2;
        RBus_UInt32  seq_r_19:2;
        RBus_UInt32  seq_r_20:2;
        RBus_UInt32  seq_r_21:2;
        RBus_UInt32  seq_r_22:2;
        RBus_UInt32  seq_r_23:2;
        RBus_UInt32  seq_r_24:2;
        RBus_UInt32  seq_r_25:2;
        RBus_UInt32  seq_r_26:2;
        RBus_UInt32  seq_r_27:2;
        RBus_UInt32  seq_r_28:2;
        RBus_UInt32  seq_r_29:2;
        RBus_UInt32  seq_r_30:2;
        RBus_UInt32  seq_r_31:2;
    };
}lgd_dither_lgd_dither_seq_r_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_0:2;
        RBus_UInt32  seq_g_1:2;
        RBus_UInt32  seq_g_2:2;
        RBus_UInt32  seq_g_3:2;
        RBus_UInt32  seq_g_4:2;
        RBus_UInt32  seq_g_5:2;
        RBus_UInt32  seq_g_6:2;
        RBus_UInt32  seq_g_7:2;
        RBus_UInt32  seq_g_8:2;
        RBus_UInt32  seq_g_9:2;
        RBus_UInt32  seq_g_10:2;
        RBus_UInt32  seq_g_11:2;
        RBus_UInt32  seq_g_12:2;
        RBus_UInt32  seq_g_13:2;
        RBus_UInt32  seq_g_14:2;
        RBus_UInt32  seq_g_15:2;
    };
}lgd_dither_lgd_dither_seq_g_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_16:2;
        RBus_UInt32  seq_g_17:2;
        RBus_UInt32  seq_g_18:2;
        RBus_UInt32  seq_g_19:2;
        RBus_UInt32  seq_g_20:2;
        RBus_UInt32  seq_g_21:2;
        RBus_UInt32  seq_g_22:2;
        RBus_UInt32  seq_g_23:2;
        RBus_UInt32  seq_g_24:2;
        RBus_UInt32  seq_g_25:2;
        RBus_UInt32  seq_g_26:2;
        RBus_UInt32  seq_g_27:2;
        RBus_UInt32  seq_g_28:2;
        RBus_UInt32  seq_g_29:2;
        RBus_UInt32  seq_g_30:2;
        RBus_UInt32  seq_g_31:2;
    };
}lgd_dither_lgd_dither_seq_g_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_0:2;
        RBus_UInt32  seq_b_1:2;
        RBus_UInt32  seq_b_2:2;
        RBus_UInt32  seq_b_3:2;
        RBus_UInt32  seq_b_4:2;
        RBus_UInt32  seq_b_5:2;
        RBus_UInt32  seq_b_6:2;
        RBus_UInt32  seq_b_7:2;
        RBus_UInt32  seq_b_8:2;
        RBus_UInt32  seq_b_9:2;
        RBus_UInt32  seq_b_10:2;
        RBus_UInt32  seq_b_11:2;
        RBus_UInt32  seq_b_12:2;
        RBus_UInt32  seq_b_13:2;
        RBus_UInt32  seq_b_14:2;
        RBus_UInt32  seq_b_15:2;
    };
}lgd_dither_lgd_dither_seq_b_00_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_16:2;
        RBus_UInt32  seq_b_17:2;
        RBus_UInt32  seq_b_18:2;
        RBus_UInt32  seq_b_19:2;
        RBus_UInt32  seq_b_20:2;
        RBus_UInt32  seq_b_21:2;
        RBus_UInt32  seq_b_22:2;
        RBus_UInt32  seq_b_23:2;
        RBus_UInt32  seq_b_24:2;
        RBus_UInt32  seq_b_25:2;
        RBus_UInt32  seq_b_26:2;
        RBus_UInt32  seq_b_27:2;
        RBus_UInt32  seq_b_28:2;
        RBus_UInt32  seq_b_29:2;
        RBus_UInt32  seq_b_30:2;
        RBus_UInt32  seq_b_31:2;
    };
}lgd_dither_lgd_dither_seq_b_16_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_00:2;
        RBus_UInt32  tab_r_01:2;
        RBus_UInt32  tab_r_02:2;
        RBus_UInt32  tab_r_03:2;
        RBus_UInt32  tab_r_10:2;
        RBus_UInt32  tab_r_11:2;
        RBus_UInt32  tab_r_12:2;
        RBus_UInt32  tab_r_13:2;
        RBus_UInt32  tab_r_20:2;
        RBus_UInt32  tab_r_21:2;
        RBus_UInt32  tab_r_22:2;
        RBus_UInt32  tab_r_23:2;
        RBus_UInt32  tab_r_30:2;
        RBus_UInt32  tab_r_31:2;
        RBus_UInt32  tab_r_32:2;
        RBus_UInt32  tab_r_33:2;
    };
}lgd_dither_lgd_dither_tb_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_00:2;
        RBus_UInt32  tab_g_01:2;
        RBus_UInt32  tab_g_02:2;
        RBus_UInt32  tab_g_03:2;
        RBus_UInt32  tab_g_10:2;
        RBus_UInt32  tab_g_11:2;
        RBus_UInt32  tab_g_12:2;
        RBus_UInt32  tab_g_13:2;
        RBus_UInt32  tab_g_20:2;
        RBus_UInt32  tab_g_21:2;
        RBus_UInt32  tab_g_22:2;
        RBus_UInt32  tab_g_23:2;
        RBus_UInt32  tab_g_30:2;
        RBus_UInt32  tab_g_31:2;
        RBus_UInt32  tab_g_32:2;
        RBus_UInt32  tab_g_33:2;
    };
}lgd_dither_lgd_dither_tb_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_00:2;
        RBus_UInt32  tab_b_01:2;
        RBus_UInt32  tab_b_02:2;
        RBus_UInt32  tab_b_03:2;
        RBus_UInt32  tab_b_10:2;
        RBus_UInt32  tab_b_11:2;
        RBus_UInt32  tab_b_12:2;
        RBus_UInt32  tab_b_13:2;
        RBus_UInt32  tab_b_20:2;
        RBus_UInt32  tab_b_21:2;
        RBus_UInt32  tab_b_22:2;
        RBus_UInt32  tab_b_23:2;
        RBus_UInt32  tab_b_30:2;
        RBus_UInt32  tab_b_31:2;
        RBus_UInt32  tab_b_32:2;
        RBus_UInt32  tab_b_33:2;
    };
}lgd_dither_lgd_dither_tb_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  temp_offset_0:2;
        RBus_UInt32  temp_offset_1:2;
        RBus_UInt32  temp_offset_2:2;
        RBus_UInt32  temp_offset_3:2;
        RBus_UInt32  temp_offset_4:2;
        RBus_UInt32  temp_offset_5:2;
        RBus_UInt32  temp_offset_6:2;
        RBus_UInt32  temp_offset_7:2;
        RBus_UInt32  temp_offset_8:2;
        RBus_UInt32  temp_offset_9:2;
        RBus_UInt32  temp_offset_10:2;
        RBus_UInt32  temp_offset_11:2;
        RBus_UInt32  temp_offset_12:2;
        RBus_UInt32  temp_offset_13:2;
        RBus_UInt32  temp_offset_14:2;
        RBus_UInt32  temp_offset_15:2;
    };
}lgd_dither_lgd_dither_temp_RBUS;

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
}lgd_dither_pcid_dither_ctrl_RBUS;

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
}lgd_dither_pcid_dither_seq_r_00_15_RBUS;

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
}lgd_dither_pcid_dither_seq_r_16_31_RBUS;

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
}lgd_dither_pcid_dither_seq_g_00_15_RBUS;

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
}lgd_dither_pcid_dither_seq_g_16_31_RBUS;

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
}lgd_dither_pcid_dither_seq_b_00_15_RBUS;

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
}lgd_dither_pcid_dither_seq_b_16_31_RBUS;

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
}lgd_dither_pcid_dither_tb_r_01_RBUS;

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
}lgd_dither_pcid_dither_tb_r_23_RBUS;

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
}lgd_dither_pcid_dither_tb_g_01_RBUS;

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
}lgd_dither_pcid_dither_tb_g_23_RBUS;

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
}lgd_dither_pcid_dither_tb_b_01_RBUS;

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
}lgd_dither_pcid_dither_tb_b_23_RBUS;

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
}lgd_dither_pcid_dither_temp_RBUS;




#endif 


#endif 
