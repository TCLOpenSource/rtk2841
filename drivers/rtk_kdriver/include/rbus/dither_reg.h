/**
* @file Mac5-DesignSpec-D-Domain_Panel_Compensation
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DITHER_REG_H_
#define _RBUS_DITHER_REG_H_

#include "rbus_types.h"



//  DITHER Register Address
#define  DITHER_DITHERING_CTRL                                                   0x1802C500
#define  DITHER_DITHERING_CTRL_reg_addr                                          "0xB802C500"
#define  DITHER_DITHERING_CTRL_reg                                               0xB802C500
#define  DITHER_DITHERING_CTRL_inst_addr                                         "0x0000"
#define  set_DITHER_DITHERING_CTRL_reg(data)                                     (*((volatile unsigned int*)DITHER_DITHERING_CTRL_reg)=data)
#define  get_DITHER_DITHERING_CTRL_reg                                           (*((volatile unsigned int*)DITHER_DITHERING_CTRL_reg))
#define  DITHER_DITHERING_CTRL_seq_2nd_b_th_shift                                (24)
#define  DITHER_DITHERING_CTRL_seq_2nd_g_th_shift                                (16)
#define  DITHER_DITHERING_CTRL_seq_2nd_r_th_shift                                (8)
#define  DITHER_DITHERING_CTRL_seq_2nd_mode_shift                                (7)
#define  DITHER_DITHERING_CTRL_test_mode_shift                                   (6)
#define  DITHER_DITHERING_CTRL_function_enable_shift                             (5)
#define  DITHER_DITHERING_CTRL_temporal_enable_shift                             (4)
#define  DITHER_DITHERING_CTRL_value_sign_shift                                  (3)
#define  DITHER_DITHERING_CTRL_dithering_mode_shift                              (2)
#define  DITHER_DITHERING_CTRL_v_modulation_shift                                (1)
#define  DITHER_DITHERING_CTRL_h_modulation_shift                                (0)
#define  DITHER_DITHERING_CTRL_seq_2nd_b_th_mask                                 (0xFF000000)
#define  DITHER_DITHERING_CTRL_seq_2nd_g_th_mask                                 (0x00FF0000)
#define  DITHER_DITHERING_CTRL_seq_2nd_r_th_mask                                 (0x0000FF00)
#define  DITHER_DITHERING_CTRL_seq_2nd_mode_mask                                 (0x00000080)
#define  DITHER_DITHERING_CTRL_test_mode_mask                                    (0x00000040)
#define  DITHER_DITHERING_CTRL_function_enable_mask                              (0x00000020)
#define  DITHER_DITHERING_CTRL_temporal_enable_mask                              (0x00000010)
#define  DITHER_DITHERING_CTRL_value_sign_mask                                   (0x00000008)
#define  DITHER_DITHERING_CTRL_dithering_mode_mask                               (0x00000004)
#define  DITHER_DITHERING_CTRL_v_modulation_mask                                 (0x00000002)
#define  DITHER_DITHERING_CTRL_h_modulation_mask                                 (0x00000001)
#define  DITHER_DITHERING_CTRL_seq_2nd_b_th(data)                                (0xFF000000&((data)<<24))
#define  DITHER_DITHERING_CTRL_seq_2nd_g_th(data)                                (0x00FF0000&((data)<<16))
#define  DITHER_DITHERING_CTRL_seq_2nd_r_th(data)                                (0x0000FF00&((data)<<8))
#define  DITHER_DITHERING_CTRL_seq_2nd_mode(data)                                (0x00000080&((data)<<7))
#define  DITHER_DITHERING_CTRL_test_mode(data)                                   (0x00000040&((data)<<6))
#define  DITHER_DITHERING_CTRL_function_enable(data)                             (0x00000020&((data)<<5))
#define  DITHER_DITHERING_CTRL_temporal_enable(data)                             (0x00000010&((data)<<4))
#define  DITHER_DITHERING_CTRL_value_sign(data)                                  (0x00000008&((data)<<3))
#define  DITHER_DITHERING_CTRL_dithering_mode(data)                              (0x00000004&((data)<<2))
#define  DITHER_DITHERING_CTRL_v_modulation(data)                                (0x00000002&((data)<<1))
#define  DITHER_DITHERING_CTRL_h_modulation(data)                                (0x00000001&(data))
#define  DITHER_DITHERING_CTRL_get_seq_2nd_b_th(data)                            ((0xFF000000&(data))>>24)
#define  DITHER_DITHERING_CTRL_get_seq_2nd_g_th(data)                            ((0x00FF0000&(data))>>16)
#define  DITHER_DITHERING_CTRL_get_seq_2nd_r_th(data)                            ((0x0000FF00&(data))>>8)
#define  DITHER_DITHERING_CTRL_get_seq_2nd_mode(data)                            ((0x00000080&(data))>>7)
#define  DITHER_DITHERING_CTRL_get_test_mode(data)                               ((0x00000040&(data))>>6)
#define  DITHER_DITHERING_CTRL_get_function_enable(data)                         ((0x00000020&(data))>>5)
#define  DITHER_DITHERING_CTRL_get_temporal_enable(data)                         ((0x00000010&(data))>>4)
#define  DITHER_DITHERING_CTRL_get_value_sign(data)                              ((0x00000008&(data))>>3)
#define  DITHER_DITHERING_CTRL_get_dithering_mode(data)                          ((0x00000004&(data))>>2)
#define  DITHER_DITHERING_CTRL_get_v_modulation(data)                            ((0x00000002&(data))>>1)
#define  DITHER_DITHERING_CTRL_get_h_modulation(data)                            (0x00000001&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07                               0x1802C504
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_reg_addr                      "0xB802C504"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_reg                           0xB802C504
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_inst_addr                     "0x0001"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_reg(data)                 (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_reg                       (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_7_shift                 (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_6_shift                 (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_5_shift                 (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_4_shift                 (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_3_shift                 (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_2_shift                 (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_1_shift                 (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_0_shift                 (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_7_mask                  (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_6_mask                  (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_5_mask                  (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_4_mask                  (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_3_mask                  (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_2_mask                  (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_1_mask                  (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_0_mask                  (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_7(data)                 (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_6(data)                 (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_5(data)                 (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_4(data)                 (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_3(data)                 (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_2(data)                 (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_1(data)                 (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_seq_r_0(data)                 (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_get_seq_r_7(data)             ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_get_seq_r_6(data)             ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_get_seq_r_5(data)             ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_get_seq_r_4(data)             ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_get_seq_r_3(data)             ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_get_seq_r_2(data)             ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_get_seq_r_1(data)             ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_00_07_get_seq_r_0(data)             (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15                               0x1802C508
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_reg_addr                      "0xB802C508"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_reg                           0xB802C508
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_inst_addr                     "0x0002"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_reg(data)                 (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_reg                       (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_15_shift                (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_14_shift                (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_13_shift                (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_12_shift                (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_11_shift                (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_10_shift                (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_9_shift                 (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_8_shift                 (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_15_mask                 (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_14_mask                 (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_13_mask                 (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_12_mask                 (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_11_mask                 (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_10_mask                 (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_9_mask                  (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_8_mask                  (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_15(data)                (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_14(data)                (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_13(data)                (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_12(data)                (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_11(data)                (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_10(data)                (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_9(data)                 (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_seq_r_8(data)                 (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_get_seq_r_15(data)            ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_get_seq_r_14(data)            ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_get_seq_r_13(data)            ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_get_seq_r_12(data)            ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_get_seq_r_11(data)            ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_get_seq_r_10(data)            ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_get_seq_r_9(data)             ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_08_15_get_seq_r_8(data)             (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23                               0x1802C50C
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_reg_addr                      "0xB802C50C"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_reg                           0xB802C50C
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_inst_addr                     "0x0003"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_reg(data)                 (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_reg                       (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_23_shift                (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_22_shift                (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_21_shift                (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_20_shift                (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_19_shift                (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_18_shift                (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_17_shift                (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_16_shift                (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_23_mask                 (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_22_mask                 (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_21_mask                 (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_20_mask                 (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_19_mask                 (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_18_mask                 (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_17_mask                 (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_16_mask                 (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_23(data)                (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_22(data)                (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_21(data)                (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_20(data)                (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_19(data)                (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_18(data)                (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_17(data)                (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_seq_r_16(data)                (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_get_seq_r_23(data)            ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_get_seq_r_22(data)            ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_get_seq_r_21(data)            ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_get_seq_r_20(data)            ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_get_seq_r_19(data)            ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_get_seq_r_18(data)            ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_get_seq_r_17(data)            ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_16_23_get_seq_r_16(data)            (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31                               0x1802C510
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_reg_addr                      "0xB802C510"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_reg                           0xB802C510
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_inst_addr                     "0x0004"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_reg(data)                 (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_reg                       (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_31_shift                (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_30_shift                (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_29_shift                (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_28_shift                (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_27_shift                (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_26_shift                (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_25_shift                (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_24_shift                (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_31_mask                 (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_30_mask                 (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_29_mask                 (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_28_mask                 (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_27_mask                 (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_26_mask                 (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_25_mask                 (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_24_mask                 (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_31(data)                (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_30(data)                (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_29(data)                (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_28(data)                (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_27(data)                (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_26(data)                (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_25(data)                (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_seq_r_24(data)                (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_get_seq_r_31(data)            ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_get_seq_r_30(data)            ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_get_seq_r_29(data)            ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_get_seq_r_28(data)            ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_get_seq_r_27(data)            ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_get_seq_r_26(data)            ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_get_seq_r_25(data)            ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Red_24_31_get_seq_r_24(data)            (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07                             0x1802C514
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_reg_addr                    "0xB802C514"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_reg                         0xB802C514
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_inst_addr                   "0x0005"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_reg(data)               (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_reg                     (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_7_shift               (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_6_shift               (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_5_shift               (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_4_shift               (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_3_shift               (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_2_shift               (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_1_shift               (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_0_shift               (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_7_mask                (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_6_mask                (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_5_mask                (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_4_mask                (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_3_mask                (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_2_mask                (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_1_mask                (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_0_mask                (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_7(data)               (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_6(data)               (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_5(data)               (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_4(data)               (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_3(data)               (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_2(data)               (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_1(data)               (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_seq_g_0(data)               (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_get_seq_g_7(data)           ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_get_seq_g_6(data)           ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_get_seq_g_5(data)           ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_get_seq_g_4(data)           ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_get_seq_g_3(data)           ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_get_seq_g_2(data)           ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_get_seq_g_1(data)           ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_00_07_get_seq_g_0(data)           (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15                             0x1802C518
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_reg_addr                    "0xB802C518"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_reg                         0xB802C518
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_inst_addr                   "0x0006"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_reg(data)               (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_reg                     (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_15_shift              (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_14_shift              (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_13_shift              (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_12_shift              (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_11_shift              (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_10_shift              (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_9_shift               (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_8_shift               (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_15_mask               (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_14_mask               (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_13_mask               (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_12_mask               (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_11_mask               (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_10_mask               (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_9_mask                (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_8_mask                (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_15(data)              (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_14(data)              (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_13(data)              (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_12(data)              (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_11(data)              (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_10(data)              (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_9(data)               (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_seq_g_8(data)               (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_get_seq_g_15(data)          ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_get_seq_g_14(data)          ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_get_seq_g_13(data)          ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_get_seq_g_12(data)          ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_get_seq_g_11(data)          ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_get_seq_g_10(data)          ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_get_seq_g_9(data)           ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_08_15_get_seq_g_8(data)           (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23                             0x1802C51C
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_reg_addr                    "0xB802C51C"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_reg                         0xB802C51C
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_inst_addr                   "0x0007"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_reg(data)               (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_reg                     (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_23_shift              (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_22_shift              (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_21_shift              (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_20_shift              (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_19_shift              (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_18_shift              (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_17_shift              (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_16_shift              (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_23_mask               (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_22_mask               (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_21_mask               (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_20_mask               (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_19_mask               (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_18_mask               (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_17_mask               (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_16_mask               (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_23(data)              (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_22(data)              (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_21(data)              (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_20(data)              (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_19(data)              (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_18(data)              (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_17(data)              (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_seq_g_16(data)              (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_get_seq_g_23(data)          ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_get_seq_g_22(data)          ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_get_seq_g_21(data)          ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_get_seq_g_20(data)          ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_get_seq_g_19(data)          ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_get_seq_g_18(data)          ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_get_seq_g_17(data)          ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_16_23_get_seq_g_16(data)          (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31                             0x1802C520
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_reg_addr                    "0xB802C520"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_reg                         0xB802C520
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_inst_addr                   "0x0008"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_reg(data)               (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_reg                     (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_31_shift              (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_30_shift              (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_29_shift              (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_28_shift              (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_27_shift              (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_26_shift              (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_25_shift              (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_24_shift              (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_31_mask               (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_30_mask               (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_29_mask               (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_28_mask               (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_27_mask               (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_26_mask               (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_25_mask               (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_24_mask               (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_31(data)              (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_30(data)              (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_29(data)              (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_28(data)              (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_27(data)              (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_26(data)              (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_25(data)              (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_seq_g_24(data)              (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_get_seq_g_31(data)          ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_get_seq_g_30(data)          ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_get_seq_g_29(data)          ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_get_seq_g_28(data)          ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_get_seq_g_27(data)          ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_get_seq_g_26(data)          ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_get_seq_g_25(data)          ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Green_24_31_get_seq_g_24(data)          (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07                              0x1802C524
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_reg_addr                     "0xB802C524"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_reg                          0xB802C524
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_inst_addr                    "0x0009"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_reg(data)                (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_reg                      (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_7_shift                (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_6_shift                (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_5_shift                (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_4_shift                (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_3_shift                (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_2_shift                (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_1_shift                (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_0_shift                (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_7_mask                 (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_6_mask                 (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_5_mask                 (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_4_mask                 (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_3_mask                 (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_2_mask                 (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_1_mask                 (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_0_mask                 (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_7(data)                (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_6(data)                (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_5(data)                (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_4(data)                (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_3(data)                (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_2(data)                (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_1(data)                (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_seq_b_0(data)                (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_get_seq_b_7(data)            ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_get_seq_b_6(data)            ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_get_seq_b_5(data)            ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_get_seq_b_4(data)            ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_get_seq_b_3(data)            ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_get_seq_b_2(data)            ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_get_seq_b_1(data)            ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_00_07_get_seq_b_0(data)            (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15                              0x1802C528
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_reg_addr                     "0xB802C528"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_reg                          0xB802C528
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_inst_addr                    "0x000A"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_reg(data)                (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_reg                      (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_15_shift               (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_14_shift               (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_13_shift               (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_12_shift               (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_11_shift               (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_10_shift               (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_9_shift                (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_8_shift                (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_15_mask                (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_14_mask                (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_13_mask                (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_12_mask                (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_11_mask                (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_10_mask                (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_9_mask                 (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_8_mask                 (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_15(data)               (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_14(data)               (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_13(data)               (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_12(data)               (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_11(data)               (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_10(data)               (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_9(data)                (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_seq_b_8(data)                (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_get_seq_b_15(data)           ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_get_seq_b_14(data)           ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_get_seq_b_13(data)           ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_get_seq_b_12(data)           ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_get_seq_b_11(data)           ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_get_seq_b_10(data)           ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_get_seq_b_9(data)            ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_08_15_get_seq_b_8(data)            (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23                              0x1802C52C
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_reg_addr                     "0xB802C52C"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_reg                          0xB802C52C
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_inst_addr                    "0x000B"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_reg(data)                (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_reg                      (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_23_shift               (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_22_shift               (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_21_shift               (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_20_shift               (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_19_shift               (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_18_shift               (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_17_shift               (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_16_shift               (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_23_mask                (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_22_mask                (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_21_mask                (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_20_mask                (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_19_mask                (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_18_mask                (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_17_mask                (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_16_mask                (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_23(data)               (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_22(data)               (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_21(data)               (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_20(data)               (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_19(data)               (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_18(data)               (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_17(data)               (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_seq_b_16(data)               (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_get_seq_b_23(data)           ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_get_seq_b_22(data)           ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_get_seq_b_21(data)           ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_get_seq_b_20(data)           ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_get_seq_b_19(data)           ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_get_seq_b_18(data)           ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_get_seq_b_17(data)           ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_16_23_get_seq_b_16(data)           (0x0000000F&(data))

#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31                              0x1802C530
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_reg_addr                     "0xB802C530"
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_reg                          0xB802C530
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_inst_addr                    "0x000C"
#define  set_DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_reg(data)                (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_reg)=data)
#define  get_DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_reg                      (*((volatile unsigned int*)DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_reg))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_31_shift               (28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_30_shift               (24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_29_shift               (20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_28_shift               (16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_27_shift               (12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_26_shift               (8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_25_shift               (4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_24_shift               (0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_31_mask                (0xF0000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_30_mask                (0x0F000000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_29_mask                (0x00F00000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_28_mask                (0x000F0000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_27_mask                (0x0000F000)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_26_mask                (0x00000F00)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_25_mask                (0x000000F0)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_24_mask                (0x0000000F)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_31(data)               (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_30(data)               (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_29(data)               (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_28(data)               (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_27(data)               (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_26(data)               (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_25(data)               (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_seq_b_24(data)               (0x0000000F&(data))
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_get_seq_b_31(data)           ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_get_seq_b_30(data)           ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_get_seq_b_29(data)           ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_get_seq_b_28(data)           ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_get_seq_b_27(data)           ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_get_seq_b_26(data)           ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_get_seq_b_25(data)           ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_SEQUENCE_TABLE_Blue_24_31_get_seq_b_24(data)           (0x0000000F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_00                                    0x1802C534
#define  DITHER_DITHERING_Dither_TABLE_Red_00_reg_addr                           "0xB802C534"
#define  DITHER_DITHERING_Dither_TABLE_Red_00_reg                                0xB802C534
#define  DITHER_DITHERING_Dither_TABLE_Red_00_inst_addr                          "0x000D"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_00_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_00_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_00_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_00_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_03_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_02_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_01_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_00_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_03_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_02_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_01_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_00_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_03(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_02(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_01(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_00_tab_r_00(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_00_get_tab_r_03(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_get_tab_r_02(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_get_tab_r_01(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_00_get_tab_r_00(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_01                                    0x1802C538
#define  DITHER_DITHERING_Dither_TABLE_Red_01_reg_addr                           "0xB802C538"
#define  DITHER_DITHERING_Dither_TABLE_Red_01_reg                                0xB802C538
#define  DITHER_DITHERING_Dither_TABLE_Red_01_inst_addr                          "0x000E"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_01_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_01_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_01_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_01_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_13_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_12_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_11_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_10_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_13_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_12_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_11_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_10_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_13(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_12(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_11(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_01_tab_r_10(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_01_get_tab_r_13(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_get_tab_r_12(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_get_tab_r_11(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_01_get_tab_r_10(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_02                                    0x1802C53C
#define  DITHER_DITHERING_Dither_TABLE_Red_02_reg_addr                           "0xB802C53C"
#define  DITHER_DITHERING_Dither_TABLE_Red_02_reg                                0xB802C53C
#define  DITHER_DITHERING_Dither_TABLE_Red_02_inst_addr                          "0x000F"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_02_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_02_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_02_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_02_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_23_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_22_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_21_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_20_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_23_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_22_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_21_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_20_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_23(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_22(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_21(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_02_tab_r_20(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_02_get_tab_r_23(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_get_tab_r_22(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_get_tab_r_21(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_02_get_tab_r_20(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_03                                    0x1802C540
#define  DITHER_DITHERING_Dither_TABLE_Red_03_reg_addr                           "0xB802C540"
#define  DITHER_DITHERING_Dither_TABLE_Red_03_reg                                0xB802C540
#define  DITHER_DITHERING_Dither_TABLE_Red_03_inst_addr                          "0x0010"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_03_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_03_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_03_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_03_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_33_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_32_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_31_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_30_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_33_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_32_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_31_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_30_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_33(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_32(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_31(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_03_tab_r_30(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_03_get_tab_r_33(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_get_tab_r_32(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_get_tab_r_31(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_03_get_tab_r_30(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_04                                    0x1802C544
#define  DITHER_DITHERING_Dither_TABLE_Red_04_reg_addr                           "0xB802C544"
#define  DITHER_DITHERING_Dither_TABLE_Red_04_reg                                0xB802C544
#define  DITHER_DITHERING_Dither_TABLE_Red_04_inst_addr                          "0x0011"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_04_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_04_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_04_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_04_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_43_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_42_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_41_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_40_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_43_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_42_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_41_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_40_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_43(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_42(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_41(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_04_tab_r_40(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_04_get_tab_r_43(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_get_tab_r_42(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_get_tab_r_41(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_04_get_tab_r_40(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_05                                    0x1802C548
#define  DITHER_DITHERING_Dither_TABLE_Red_05_reg_addr                           "0xB802C548"
#define  DITHER_DITHERING_Dither_TABLE_Red_05_reg                                0xB802C548
#define  DITHER_DITHERING_Dither_TABLE_Red_05_inst_addr                          "0x0012"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_05_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_05_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_05_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_05_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_53_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_52_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_51_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_50_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_53_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_52_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_51_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_50_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_53(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_52(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_51(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_05_tab_r_50(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_05_get_tab_r_53(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_get_tab_r_52(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_get_tab_r_51(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_05_get_tab_r_50(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_06                                    0x1802C54C
#define  DITHER_DITHERING_Dither_TABLE_Red_06_reg_addr                           "0xB802C54C"
#define  DITHER_DITHERING_Dither_TABLE_Red_06_reg                                0xB802C54C
#define  DITHER_DITHERING_Dither_TABLE_Red_06_inst_addr                          "0x0013"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_06_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_06_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_06_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_06_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_63_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_62_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_61_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_60_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_63_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_62_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_61_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_60_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_63(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_62(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_61(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_06_tab_r_60(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_06_get_tab_r_63(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_get_tab_r_62(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_get_tab_r_61(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_06_get_tab_r_60(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_07                                    0x1802C550
#define  DITHER_DITHERING_Dither_TABLE_Red_07_reg_addr                           "0xB802C550"
#define  DITHER_DITHERING_Dither_TABLE_Red_07_reg                                0xB802C550
#define  DITHER_DITHERING_Dither_TABLE_Red_07_inst_addr                          "0x0014"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_07_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_07_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_07_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_07_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_73_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_72_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_71_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_70_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_73_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_72_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_71_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_70_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_73(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_72(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_71(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_07_tab_r_70(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_07_get_tab_r_73(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_get_tab_r_72(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_get_tab_r_71(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_07_get_tab_r_70(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_08                                    0x1802C554
#define  DITHER_DITHERING_Dither_TABLE_Red_08_reg_addr                           "0xB802C554"
#define  DITHER_DITHERING_Dither_TABLE_Red_08_reg                                0xB802C554
#define  DITHER_DITHERING_Dither_TABLE_Red_08_inst_addr                          "0x0015"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_08_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_08_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_08_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_08_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_83_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_82_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_81_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_80_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_83_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_82_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_81_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_80_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_83(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_82(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_81(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_08_tab_r_80(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_08_get_tab_r_83(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_get_tab_r_82(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_get_tab_r_81(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_08_get_tab_r_80(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_09                                    0x1802C558
#define  DITHER_DITHERING_Dither_TABLE_Red_09_reg_addr                           "0xB802C558"
#define  DITHER_DITHERING_Dither_TABLE_Red_09_reg                                0xB802C558
#define  DITHER_DITHERING_Dither_TABLE_Red_09_inst_addr                          "0x0016"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_09_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_09_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_09_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_09_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_93_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_92_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_91_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_90_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_93_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_92_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_91_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_90_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_93(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_92(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_91(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_09_tab_r_90(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_09_get_tab_r_93(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_get_tab_r_92(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_get_tab_r_91(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_09_get_tab_r_90(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_0A                                    0x1802C55C
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_reg_addr                           "0xB802C55C"
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_reg                                0xB802C55C
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_inst_addr                          "0x0017"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_0A_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0A_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_0A_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0A_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a3_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a2_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a1_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a0_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a3_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a2_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a1_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a0_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a3(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a2(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a1(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_tab_r_a0(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_get_tab_r_a3(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_get_tab_r_a2(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_get_tab_r_a1(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0A_get_tab_r_a0(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_0B                                    0x1802C560
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_reg_addr                           "0xB802C560"
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_reg                                0xB802C560
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_inst_addr                          "0x0018"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_0B_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0B_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_0B_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0B_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b3_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b2_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b1_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b0_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b3_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b2_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b1_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b0_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b3(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b2(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b1(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_tab_r_b0(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_get_tab_r_b3(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_get_tab_r_b2(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_get_tab_r_b1(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0B_get_tab_r_b0(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_0C                                    0x1802C564
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_reg_addr                           "0xB802C564"
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_reg                                0xB802C564
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_inst_addr                          "0x0019"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_0C_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0C_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_0C_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0C_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c3_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c2_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c1_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c0_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c3_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c2_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c1_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c0_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c3(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c2(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c1(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_tab_r_c0(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_get_tab_r_c3(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_get_tab_r_c2(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_get_tab_r_c1(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0C_get_tab_r_c0(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_0D                                    0x1802C568
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_reg_addr                           "0xB802C568"
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_reg                                0xB802C568
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_inst_addr                          "0x001A"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_0D_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0D_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_0D_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0D_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d3_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d2_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d1_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d0_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d3_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d2_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d1_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d0_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d3(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d2(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d1(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_tab_r_d0(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_get_tab_r_d3(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_get_tab_r_d2(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_get_tab_r_d1(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0D_get_tab_r_d0(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_0E                                    0x1802C56C
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_reg_addr                           "0xB802C56C"
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_reg                                0xB802C56C
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_inst_addr                          "0x001B"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_0E_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0E_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_0E_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0E_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e3_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e2_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e1_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e0_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e3_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e2_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e1_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e0_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e3(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e2(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e1(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_tab_r_e0(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_get_tab_r_e3(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_get_tab_r_e2(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_get_tab_r_e1(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0E_get_tab_r_e0(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Red_0F                                    0x1802C570
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_reg_addr                           "0xB802C570"
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_reg                                0xB802C570
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_inst_addr                          "0x001C"
#define  set_DITHER_DITHERING_Dither_TABLE_Red_0F_reg(data)                      (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0F_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Red_0F_reg                            (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Red_0F_reg))
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f3_shift                     (18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f2_shift                     (12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f1_shift                     (6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f0_shift                     (0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f3_mask                      (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f2_mask                      (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f1_mask                      (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f0_mask                      (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f3(data)                     (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f2(data)                     (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f1(data)                     (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_tab_r_f0(data)                     (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_get_tab_r_f3(data)                 ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_get_tab_r_f2(data)                 ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_get_tab_r_f1(data)                 ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Red_0F_get_tab_r_f0(data)                 (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_00                                  0x1802C574
#define  DITHER_DITHERING_Dither_TABLE_Green_00_reg_addr                         "0xB802C574"
#define  DITHER_DITHERING_Dither_TABLE_Green_00_reg                              0xB802C574
#define  DITHER_DITHERING_Dither_TABLE_Green_00_inst_addr                        "0x001D"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_00_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_00_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_00_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_00_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_03_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_02_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_01_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_00_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_03_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_02_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_01_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_00_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_03(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_02(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_01(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_00_tab_g_00(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_00_get_tab_g_03(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_get_tab_g_02(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_get_tab_g_01(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_00_get_tab_g_00(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_01                                  0x1802C578
#define  DITHER_DITHERING_Dither_TABLE_Green_01_reg_addr                         "0xB802C578"
#define  DITHER_DITHERING_Dither_TABLE_Green_01_reg                              0xB802C578
#define  DITHER_DITHERING_Dither_TABLE_Green_01_inst_addr                        "0x001E"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_01_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_01_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_01_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_01_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_13_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_12_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_11_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_10_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_13_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_12_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_11_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_10_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_13(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_12(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_11(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_01_tab_g_10(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_01_get_tab_g_13(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_get_tab_g_12(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_get_tab_g_11(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_01_get_tab_g_10(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_02                                  0x1802C57C
#define  DITHER_DITHERING_Dither_TABLE_Green_02_reg_addr                         "0xB802C57C"
#define  DITHER_DITHERING_Dither_TABLE_Green_02_reg                              0xB802C57C
#define  DITHER_DITHERING_Dither_TABLE_Green_02_inst_addr                        "0x001F"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_02_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_02_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_02_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_02_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_23_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_22_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_21_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_20_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_23_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_22_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_21_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_20_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_23(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_22(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_21(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_02_tab_g_20(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_02_get_tab_g_23(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_get_tab_g_22(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_get_tab_g_21(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_02_get_tab_g_20(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_03                                  0x1802C580
#define  DITHER_DITHERING_Dither_TABLE_Green_03_reg_addr                         "0xB802C580"
#define  DITHER_DITHERING_Dither_TABLE_Green_03_reg                              0xB802C580
#define  DITHER_DITHERING_Dither_TABLE_Green_03_inst_addr                        "0x0020"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_03_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_03_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_03_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_03_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_33_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_32_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_31_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_30_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_33_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_32_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_31_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_30_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_33(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_32(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_31(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_03_tab_g_30(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_03_get_tab_g_33(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_get_tab_g_32(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_get_tab_g_31(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_03_get_tab_g_30(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_04                                  0x1802C584
#define  DITHER_DITHERING_Dither_TABLE_Green_04_reg_addr                         "0xB802C584"
#define  DITHER_DITHERING_Dither_TABLE_Green_04_reg                              0xB802C584
#define  DITHER_DITHERING_Dither_TABLE_Green_04_inst_addr                        "0x0021"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_04_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_04_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_04_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_04_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_43_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_42_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_41_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_40_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_43_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_42_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_41_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_40_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_43(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_42(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_41(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_04_tab_g_40(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_04_get_tab_g_43(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_get_tab_g_42(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_get_tab_g_41(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_04_get_tab_g_40(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_05                                  0x1802C588
#define  DITHER_DITHERING_Dither_TABLE_Green_05_reg_addr                         "0xB802C588"
#define  DITHER_DITHERING_Dither_TABLE_Green_05_reg                              0xB802C588
#define  DITHER_DITHERING_Dither_TABLE_Green_05_inst_addr                        "0x0022"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_05_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_05_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_05_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_05_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_53_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_52_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_51_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_50_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_53_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_52_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_51_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_50_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_53(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_52(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_51(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_05_tab_g_50(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_05_get_tab_g_53(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_get_tab_g_52(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_get_tab_g_51(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_05_get_tab_g_50(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_06                                  0x1802C58C
#define  DITHER_DITHERING_Dither_TABLE_Green_06_reg_addr                         "0xB802C58C"
#define  DITHER_DITHERING_Dither_TABLE_Green_06_reg                              0xB802C58C
#define  DITHER_DITHERING_Dither_TABLE_Green_06_inst_addr                        "0x0023"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_06_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_06_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_06_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_06_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_63_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_62_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_61_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_60_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_63_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_62_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_61_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_60_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_63(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_62(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_61(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_06_tab_g_60(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_06_get_tab_g_63(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_get_tab_g_62(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_get_tab_g_61(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_06_get_tab_g_60(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_07                                  0x1802C590
#define  DITHER_DITHERING_Dither_TABLE_Green_07_reg_addr                         "0xB802C590"
#define  DITHER_DITHERING_Dither_TABLE_Green_07_reg                              0xB802C590
#define  DITHER_DITHERING_Dither_TABLE_Green_07_inst_addr                        "0x0024"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_07_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_07_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_07_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_07_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_73_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_72_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_71_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_70_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_73_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_72_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_71_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_70_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_73(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_72(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_71(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_07_tab_g_70(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_07_get_tab_g_73(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_get_tab_g_72(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_get_tab_g_71(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_07_get_tab_g_70(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_08                                  0x1802C594
#define  DITHER_DITHERING_Dither_TABLE_Green_08_reg_addr                         "0xB802C594"
#define  DITHER_DITHERING_Dither_TABLE_Green_08_reg                              0xB802C594
#define  DITHER_DITHERING_Dither_TABLE_Green_08_inst_addr                        "0x0025"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_08_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_08_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_08_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_08_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_83_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_82_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_81_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_80_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_83_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_82_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_81_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_80_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_83(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_82(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_81(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_08_tab_g_80(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_08_get_tab_g_83(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_get_tab_g_82(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_get_tab_g_81(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_08_get_tab_g_80(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_09                                  0x1802C598
#define  DITHER_DITHERING_Dither_TABLE_Green_09_reg_addr                         "0xB802C598"
#define  DITHER_DITHERING_Dither_TABLE_Green_09_reg                              0xB802C598
#define  DITHER_DITHERING_Dither_TABLE_Green_09_inst_addr                        "0x0026"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_09_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_09_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_09_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_09_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_93_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_92_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_91_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_90_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_93_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_92_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_91_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_90_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_93(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_92(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_91(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_09_tab_g_90(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_09_get_tab_g_93(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_get_tab_g_92(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_get_tab_g_91(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_09_get_tab_g_90(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_0A                                  0x1802C59C
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_reg_addr                         "0xB802C59C"
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_reg                              0xB802C59C
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_inst_addr                        "0x0027"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_0A_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0A_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_0A_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0A_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a3_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a2_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a1_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a0_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a3_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a2_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a1_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a0_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a3(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a2(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a1(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_tab_g_a0(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_get_tab_g_a3(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_get_tab_g_a2(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_get_tab_g_a1(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0A_get_tab_g_a0(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_0B                                  0x1802C5A0
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_reg_addr                         "0xB802C5A0"
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_reg                              0xB802C5A0
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_inst_addr                        "0x0028"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_0B_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0B_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_0B_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0B_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b3_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b2_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b1_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b0_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b3_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b2_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b1_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b0_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b3(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b2(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b1(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_tab_g_b0(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_get_tab_g_b3(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_get_tab_g_b2(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_get_tab_g_b1(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0B_get_tab_g_b0(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_0C                                  0x1802C5A4
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_reg_addr                         "0xB802C5A4"
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_reg                              0xB802C5A4
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_inst_addr                        "0x0029"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_0C_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0C_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_0C_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0C_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c3_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c2_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c1_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c0_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c3_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c2_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c1_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c0_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c3(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c2(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c1(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_tab_g_c0(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_get_tab_g_c3(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_get_tab_g_c2(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_get_tab_g_c1(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0C_get_tab_g_c0(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_0D                                  0x1802C5A8
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_reg_addr                         "0xB802C5A8"
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_reg                              0xB802C5A8
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_inst_addr                        "0x002A"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_0D_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0D_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_0D_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0D_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d3_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d2_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d1_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d0_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d3_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d2_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d1_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d0_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d3(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d2(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d1(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_tab_g_d0(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_get_tab_g_d3(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_get_tab_g_d2(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_get_tab_g_d1(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0D_get_tab_g_d0(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_0E                                  0x1802C5AC
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_reg_addr                         "0xB802C5AC"
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_reg                              0xB802C5AC
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_inst_addr                        "0x002B"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_0E_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0E_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_0E_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0E_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e3_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e2_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e1_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e0_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e3_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e2_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e1_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e0_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e3(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e2(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e1(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_tab_g_e0(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_get_tab_g_e3(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_get_tab_g_e2(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_get_tab_g_e1(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0E_get_tab_g_e0(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Green_0F                                  0x1802C5B0
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_reg_addr                         "0xB802C5B0"
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_reg                              0xB802C5B0
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_inst_addr                        "0x002C"
#define  set_DITHER_DITHERING_Dither_TABLE_Green_0F_reg(data)                    (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0F_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Green_0F_reg                          (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Green_0F_reg))
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f3_shift                   (18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f2_shift                   (12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f1_shift                   (6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f0_shift                   (0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f3_mask                    (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f2_mask                    (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f1_mask                    (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f0_mask                    (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f3(data)                   (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f2(data)                   (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f1(data)                   (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_tab_g_f0(data)                   (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_get_tab_g_f3(data)               ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_get_tab_g_f2(data)               ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_get_tab_g_f1(data)               ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Green_0F_get_tab_g_f0(data)               (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_00                                   0x1802C5B4
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_reg_addr                          "0xB802C5B4"
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_reg                               0xB802C5B4
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_inst_addr                         "0x002D"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_00_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_00_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_00_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_00_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_03_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_02_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_01_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_00_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_03_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_02_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_01_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_00_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_03(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_02(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_01(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_tab_b_00(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_get_tab_b_03(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_get_tab_b_02(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_get_tab_b_01(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_00_get_tab_b_00(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_01                                   0x1802C5B8
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_reg_addr                          "0xB802C5B8"
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_reg                               0xB802C5B8
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_inst_addr                         "0x002E"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_01_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_01_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_01_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_01_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_13_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_12_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_11_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_10_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_13_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_12_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_11_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_10_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_13(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_12(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_11(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_tab_b_10(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_get_tab_b_13(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_get_tab_b_12(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_get_tab_b_11(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_01_get_tab_b_10(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_02                                   0x1802C5BC
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_reg_addr                          "0xB802C5BC"
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_reg                               0xB802C5BC
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_inst_addr                         "0x002F"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_02_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_02_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_02_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_02_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_23_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_22_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_21_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_20_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_23_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_22_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_21_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_20_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_23(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_22(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_21(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_tab_b_20(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_get_tab_b_23(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_get_tab_b_22(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_get_tab_b_21(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_02_get_tab_b_20(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_03                                   0x1802C5C0
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_reg_addr                          "0xB802C5C0"
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_reg                               0xB802C5C0
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_inst_addr                         "0x0030"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_03_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_03_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_03_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_03_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_33_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_32_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_31_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_30_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_33_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_32_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_31_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_30_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_33(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_32(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_31(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_tab_b_30(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_get_tab_b_33(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_get_tab_b_32(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_get_tab_b_31(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_03_get_tab_b_30(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_04                                   0x1802C5C4
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_reg_addr                          "0xB802C5C4"
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_reg                               0xB802C5C4
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_inst_addr                         "0x0031"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_04_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_04_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_04_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_04_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_43_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_42_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_41_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_40_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_43_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_42_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_41_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_40_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_43(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_42(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_41(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_tab_b_40(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_get_tab_b_43(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_get_tab_b_42(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_get_tab_b_41(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_04_get_tab_b_40(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_05                                   0x1802C5C8
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_reg_addr                          "0xB802C5C8"
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_reg                               0xB802C5C8
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_inst_addr                         "0x0032"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_05_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_05_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_05_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_05_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_53_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_52_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_51_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_50_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_53_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_52_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_51_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_50_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_53(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_52(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_51(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_tab_b_50(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_get_tab_b_53(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_get_tab_b_52(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_get_tab_b_51(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_05_get_tab_b_50(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_06                                   0x1802C5CC
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_reg_addr                          "0xB802C5CC"
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_reg                               0xB802C5CC
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_inst_addr                         "0x0033"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_06_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_06_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_06_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_06_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_63_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_62_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_61_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_60_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_63_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_62_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_61_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_60_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_63(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_62(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_61(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_tab_b_60(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_get_tab_b_63(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_get_tab_b_62(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_get_tab_b_61(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_06_get_tab_b_60(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_07                                   0x1802C5D0
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_reg_addr                          "0xB802C5D0"
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_reg                               0xB802C5D0
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_inst_addr                         "0x0034"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_07_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_07_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_07_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_07_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_73_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_72_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_71_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_70_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_73_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_72_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_71_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_70_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_73(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_72(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_71(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_tab_b_70(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_get_tab_b_73(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_get_tab_b_72(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_get_tab_b_71(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_07_get_tab_b_70(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_08                                   0x1802C5D4
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_reg_addr                          "0xB802C5D4"
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_reg                               0xB802C5D4
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_inst_addr                         "0x0035"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_08_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_08_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_08_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_08_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_83_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_82_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_81_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_80_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_83_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_82_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_81_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_80_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_83(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_82(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_81(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_tab_b_80(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_get_tab_b_83(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_get_tab_b_82(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_get_tab_b_81(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_08_get_tab_b_80(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_09                                   0x1802C5D8
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_reg_addr                          "0xB802C5D8"
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_reg                               0xB802C5D8
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_inst_addr                         "0x0036"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_09_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_09_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_09_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_09_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_93_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_92_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_91_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_90_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_93_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_92_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_91_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_90_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_93(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_92(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_91(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_tab_b_90(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_get_tab_b_93(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_get_tab_b_92(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_get_tab_b_91(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_09_get_tab_b_90(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_0A                                   0x1802C5DC
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_reg_addr                          "0xB802C5DC"
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_reg                               0xB802C5DC
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_inst_addr                         "0x0037"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_0A_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0A_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_0A_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0A_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a3_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a2_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a1_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a0_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a3_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a2_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a1_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a0_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a3(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a2(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a1(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_tab_b_a0(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_get_tab_b_a3(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_get_tab_b_a2(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_get_tab_b_a1(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0A_get_tab_b_a0(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_0B                                   0x1802C5E0
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_reg_addr                          "0xB802C5E0"
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_reg                               0xB802C5E0
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_inst_addr                         "0x0038"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_0B_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0B_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_0B_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0B_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b3_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b2_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b1_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b0_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b3_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b2_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b1_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b0_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b3(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b2(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b1(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_tab_b_b0(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_get_tab_b_b3(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_get_tab_b_b2(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_get_tab_b_b1(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0B_get_tab_b_b0(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_0C                                   0x1802C5E4
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_reg_addr                          "0xB802C5E4"
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_reg                               0xB802C5E4
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_inst_addr                         "0x0039"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_0C_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0C_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_0C_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0C_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c3_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c2_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c1_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c0_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c3_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c2_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c1_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c0_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c3(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c2(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c1(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_tab_b_c0(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_get_tab_b_c3(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_get_tab_b_c2(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_get_tab_b_c1(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0C_get_tab_b_c0(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_0D                                   0x1802C5E8
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_reg_addr                          "0xB802C5E8"
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_reg                               0xB802C5E8
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_inst_addr                         "0x003A"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_0D_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0D_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_0D_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0D_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d3_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d2_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d1_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d0_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d3_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d2_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d1_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d0_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d3(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d2(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d1(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_tab_b_d0(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_get_tab_b_d3(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_get_tab_b_d2(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_get_tab_b_d1(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0D_get_tab_b_d0(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_0E                                   0x1802C5EC
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_reg_addr                          "0xB802C5EC"
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_reg                               0xB802C5EC
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_inst_addr                         "0x003B"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_0E_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0E_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_0E_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0E_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e3_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e2_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e1_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e0_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e3_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e2_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e1_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e0_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e3(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e2(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e1(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_tab_b_e0(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_get_tab_b_e3(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_get_tab_b_e2(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_get_tab_b_e1(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0E_get_tab_b_e0(data)                (0x0000003F&(data))

#define  DITHER_DITHERING_Dither_TABLE_Blue_0F                                   0x1802C5F0
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_reg_addr                          "0xB802C5F0"
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_reg                               0xB802C5F0
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_inst_addr                         "0x003C"
#define  set_DITHER_DITHERING_Dither_TABLE_Blue_0F_reg(data)                     (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0F_reg)=data)
#define  get_DITHER_DITHERING_Dither_TABLE_Blue_0F_reg                           (*((volatile unsigned int*)DITHER_DITHERING_Dither_TABLE_Blue_0F_reg))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f3_shift                    (18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f2_shift                    (12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f1_shift                    (6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f0_shift                    (0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f3_mask                     (0x00FC0000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f2_mask                     (0x0003F000)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f1_mask                     (0x00000FC0)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f0_mask                     (0x0000003F)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f3(data)                    (0x00FC0000&((data)<<18))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f2(data)                    (0x0003F000&((data)<<12))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f1(data)                    (0x00000FC0&((data)<<6))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_tab_b_f0(data)                    (0x0000003F&(data))
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_get_tab_b_f3(data)                ((0x00FC0000&(data))>>18)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_get_tab_b_f2(data)                ((0x0003F000&(data))>>12)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_get_tab_b_f1(data)                ((0x00000FC0&(data))>>6)
#define  DITHER_DITHERING_Dither_TABLE_Blue_0F_get_tab_b_f0(data)                (0x0000003F&(data))

#define  DITHER_Temporal_offset                                                  0x1802C5F4
#define  DITHER_Temporal_offset_reg_addr                                         "0xB802C5F4"
#define  DITHER_Temporal_offset_reg                                              0xB802C5F4
#define  DITHER_Temporal_offset_inst_addr                                        "0x003D"
#define  set_DITHER_Temporal_offset_reg(data)                                    (*((volatile unsigned int*)DITHER_Temporal_offset_reg)=data)
#define  get_DITHER_Temporal_offset_reg                                          (*((volatile unsigned int*)DITHER_Temporal_offset_reg))
#define  DITHER_Temporal_offset_temp_offset_15_shift                             (30)
#define  DITHER_Temporal_offset_temp_offset_14_shift                             (28)
#define  DITHER_Temporal_offset_temp_offset_13_shift                             (26)
#define  DITHER_Temporal_offset_temp_offset_12_shift                             (24)
#define  DITHER_Temporal_offset_temp_offset_11_shift                             (22)
#define  DITHER_Temporal_offset_temp_offset_10_shift                             (20)
#define  DITHER_Temporal_offset_temp_offset_9_shift                              (18)
#define  DITHER_Temporal_offset_temp_offset_8_shift                              (16)
#define  DITHER_Temporal_offset_temp_offset_7_shift                              (14)
#define  DITHER_Temporal_offset_temp_offset_6_shift                              (12)
#define  DITHER_Temporal_offset_temp_offset_5_shift                              (10)
#define  DITHER_Temporal_offset_temp_offset_4_shift                              (8)
#define  DITHER_Temporal_offset_temp_offset_3_shift                              (6)
#define  DITHER_Temporal_offset_temp_offset_2_shift                              (4)
#define  DITHER_Temporal_offset_temp_offset_1_shift                              (2)
#define  DITHER_Temporal_offset_temp_offset_0_shift                              (0)
#define  DITHER_Temporal_offset_temp_offset_15_mask                              (0xC0000000)
#define  DITHER_Temporal_offset_temp_offset_14_mask                              (0x30000000)
#define  DITHER_Temporal_offset_temp_offset_13_mask                              (0x0C000000)
#define  DITHER_Temporal_offset_temp_offset_12_mask                              (0x03000000)
#define  DITHER_Temporal_offset_temp_offset_11_mask                              (0x00C00000)
#define  DITHER_Temporal_offset_temp_offset_10_mask                              (0x00300000)
#define  DITHER_Temporal_offset_temp_offset_9_mask                               (0x000C0000)
#define  DITHER_Temporal_offset_temp_offset_8_mask                               (0x00030000)
#define  DITHER_Temporal_offset_temp_offset_7_mask                               (0x0000C000)
#define  DITHER_Temporal_offset_temp_offset_6_mask                               (0x00003000)
#define  DITHER_Temporal_offset_temp_offset_5_mask                               (0x00000C00)
#define  DITHER_Temporal_offset_temp_offset_4_mask                               (0x00000300)
#define  DITHER_Temporal_offset_temp_offset_3_mask                               (0x000000C0)
#define  DITHER_Temporal_offset_temp_offset_2_mask                               (0x00000030)
#define  DITHER_Temporal_offset_temp_offset_1_mask                               (0x0000000C)
#define  DITHER_Temporal_offset_temp_offset_0_mask                               (0x00000003)
#define  DITHER_Temporal_offset_temp_offset_15(data)                             (0xC0000000&((data)<<30))
#define  DITHER_Temporal_offset_temp_offset_14(data)                             (0x30000000&((data)<<28))
#define  DITHER_Temporal_offset_temp_offset_13(data)                             (0x0C000000&((data)<<26))
#define  DITHER_Temporal_offset_temp_offset_12(data)                             (0x03000000&((data)<<24))
#define  DITHER_Temporal_offset_temp_offset_11(data)                             (0x00C00000&((data)<<22))
#define  DITHER_Temporal_offset_temp_offset_10(data)                             (0x00300000&((data)<<20))
#define  DITHER_Temporal_offset_temp_offset_9(data)                              (0x000C0000&((data)<<18))
#define  DITHER_Temporal_offset_temp_offset_8(data)                              (0x00030000&((data)<<16))
#define  DITHER_Temporal_offset_temp_offset_7(data)                              (0x0000C000&((data)<<14))
#define  DITHER_Temporal_offset_temp_offset_6(data)                              (0x00003000&((data)<<12))
#define  DITHER_Temporal_offset_temp_offset_5(data)                              (0x00000C00&((data)<<10))
#define  DITHER_Temporal_offset_temp_offset_4(data)                              (0x00000300&((data)<<8))
#define  DITHER_Temporal_offset_temp_offset_3(data)                              (0x000000C0&((data)<<6))
#define  DITHER_Temporal_offset_temp_offset_2(data)                              (0x00000030&((data)<<4))
#define  DITHER_Temporal_offset_temp_offset_1(data)                              (0x0000000C&((data)<<2))
#define  DITHER_Temporal_offset_temp_offset_0(data)                              (0x00000003&(data))
#define  DITHER_Temporal_offset_get_temp_offset_15(data)                         ((0xC0000000&(data))>>30)
#define  DITHER_Temporal_offset_get_temp_offset_14(data)                         ((0x30000000&(data))>>28)
#define  DITHER_Temporal_offset_get_temp_offset_13(data)                         ((0x0C000000&(data))>>26)
#define  DITHER_Temporal_offset_get_temp_offset_12(data)                         ((0x03000000&(data))>>24)
#define  DITHER_Temporal_offset_get_temp_offset_11(data)                         ((0x00C00000&(data))>>22)
#define  DITHER_Temporal_offset_get_temp_offset_10(data)                         ((0x00300000&(data))>>20)
#define  DITHER_Temporal_offset_get_temp_offset_9(data)                          ((0x000C0000&(data))>>18)
#define  DITHER_Temporal_offset_get_temp_offset_8(data)                          ((0x00030000&(data))>>16)
#define  DITHER_Temporal_offset_get_temp_offset_7(data)                          ((0x0000C000&(data))>>14)
#define  DITHER_Temporal_offset_get_temp_offset_6(data)                          ((0x00003000&(data))>>12)
#define  DITHER_Temporal_offset_get_temp_offset_5(data)                          ((0x00000C00&(data))>>10)
#define  DITHER_Temporal_offset_get_temp_offset_4(data)                          ((0x00000300&(data))>>8)
#define  DITHER_Temporal_offset_get_temp_offset_3(data)                          ((0x000000C0&(data))>>6)
#define  DITHER_Temporal_offset_get_temp_offset_2(data)                          ((0x00000030&(data))>>4)
#define  DITHER_Temporal_offset_get_temp_offset_1(data)                          ((0x0000000C&(data))>>2)
#define  DITHER_Temporal_offset_get_temp_offset_0(data)                          (0x00000003&(data))

#define  DITHER_Dither_CRC_CTRL                                                  0x1802C5F8
#define  DITHER_Dither_CRC_CTRL_reg_addr                                         "0xB802C5F8"
#define  DITHER_Dither_CRC_CTRL_reg                                              0xB802C5F8
#define  DITHER_Dither_CRC_CTRL_inst_addr                                        "0x003E"
#define  set_DITHER_Dither_CRC_CTRL_reg(data)                                    (*((volatile unsigned int*)DITHER_Dither_CRC_CTRL_reg)=data)
#define  get_DITHER_Dither_CRC_CTRL_reg                                          (*((volatile unsigned int*)DITHER_Dither_CRC_CTRL_reg))
#define  DITHER_Dither_CRC_CTRL_dither_crc_conti_shift                           (1)
#define  DITHER_Dither_CRC_CTRL_dither_crc_start_shift                           (0)
#define  DITHER_Dither_CRC_CTRL_dither_crc_conti_mask                            (0x00000002)
#define  DITHER_Dither_CRC_CTRL_dither_crc_start_mask                            (0x00000001)
#define  DITHER_Dither_CRC_CTRL_dither_crc_conti(data)                           (0x00000002&((data)<<1))
#define  DITHER_Dither_CRC_CTRL_dither_crc_start(data)                           (0x00000001&(data))
#define  DITHER_Dither_CRC_CTRL_get_dither_crc_conti(data)                       ((0x00000002&(data))>>1)
#define  DITHER_Dither_CRC_CTRL_get_dither_crc_start(data)                       (0x00000001&(data))

#define  DITHER_Dither_CRC_RESULT                                                0x1802C5FC
#define  DITHER_Dither_CRC_RESULT_reg_addr                                       "0xB802C5FC"
#define  DITHER_Dither_CRC_RESULT_reg                                            0xB802C5FC
#define  DITHER_Dither_CRC_RESULT_inst_addr                                      "0x003F"
#define  set_DITHER_Dither_CRC_RESULT_reg(data)                                  (*((volatile unsigned int*)DITHER_Dither_CRC_RESULT_reg)=data)
#define  get_DITHER_Dither_CRC_RESULT_reg                                        (*((volatile unsigned int*)DITHER_Dither_CRC_RESULT_reg))
#define  DITHER_Dither_CRC_RESULT_d_crc_result_shift                             (0)
#define  DITHER_Dither_CRC_RESULT_d_crc_result_mask                              (0xFFFFFFFF)
#define  DITHER_Dither_CRC_RESULT_d_crc_result(data)                             (0xFFFFFFFF&(data))
#define  DITHER_Dither_CRC_RESULT_get_d_crc_result(data)                         (0xFFFFFFFF&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07                           0x1802C600
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_reg_addr                  "0xB802C600"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_reg                       0xB802C600
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_inst_addr                 "0x0040"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_reg(data)             (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_reg                   (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_7_shift             (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_6_shift             (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_5_shift             (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_4_shift             (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_3_shift             (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_2_shift             (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_1_shift             (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_0_shift             (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_7_mask              (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_6_mask              (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_5_mask              (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_4_mask              (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_3_mask              (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_2_mask              (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_1_mask              (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_0_mask              (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_7(data)             (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_6(data)             (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_5(data)             (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_4(data)             (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_3(data)             (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_2(data)             (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_1(data)             (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_seq_r_0(data)             (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_get_seq_r_7(data)         ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_get_seq_r_6(data)         ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_get_seq_r_5(data)         ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_get_seq_r_4(data)         ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_get_seq_r_3(data)         ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_get_seq_r_2(data)         ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_get_seq_r_1(data)         ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_00_07_get_seq_r_0(data)         (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15                           0x1802C604
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_reg_addr                  "0xB802C604"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_reg                       0xB802C604
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_inst_addr                 "0x0041"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_reg(data)             (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_reg                   (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_15_shift            (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_14_shift            (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_13_shift            (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_12_shift            (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_11_shift            (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_10_shift            (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_9_shift             (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_8_shift             (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_15_mask             (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_14_mask             (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_13_mask             (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_12_mask             (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_11_mask             (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_10_mask             (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_9_mask              (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_8_mask              (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_15(data)            (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_14(data)            (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_13(data)            (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_12(data)            (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_11(data)            (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_10(data)            (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_9(data)             (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_seq_r_8(data)             (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_get_seq_r_15(data)        ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_get_seq_r_14(data)        ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_get_seq_r_13(data)        ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_get_seq_r_12(data)        ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_get_seq_r_11(data)        ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_get_seq_r_10(data)        ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_get_seq_r_9(data)         ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_08_15_get_seq_r_8(data)         (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23                           0x1802C608
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_reg_addr                  "0xB802C608"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_reg                       0xB802C608
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_inst_addr                 "0x0042"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_reg(data)             (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_reg                   (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_23_shift            (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_22_shift            (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_21_shift            (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_20_shift            (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_19_shift            (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_18_shift            (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_17_shift            (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_16_shift            (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_23_mask             (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_22_mask             (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_21_mask             (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_20_mask             (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_19_mask             (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_18_mask             (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_17_mask             (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_16_mask             (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_23(data)            (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_22(data)            (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_21(data)            (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_20(data)            (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_19(data)            (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_18(data)            (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_17(data)            (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_seq_r_16(data)            (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_get_seq_r_23(data)        ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_get_seq_r_22(data)        ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_get_seq_r_21(data)        ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_get_seq_r_20(data)        ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_get_seq_r_19(data)        ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_get_seq_r_18(data)        ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_get_seq_r_17(data)        ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_16_23_get_seq_r_16(data)        (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31                           0x1802C60C
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_reg_addr                  "0xB802C60C"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_reg                       0xB802C60C
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_inst_addr                 "0x0043"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_reg(data)             (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_reg                   (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_31_shift            (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_30_shift            (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_29_shift            (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_28_shift            (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_27_shift            (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_26_shift            (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_25_shift            (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_24_shift            (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_31_mask             (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_30_mask             (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_29_mask             (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_28_mask             (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_27_mask             (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_26_mask             (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_25_mask             (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_24_mask             (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_31(data)            (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_30(data)            (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_29(data)            (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_28(data)            (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_27(data)            (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_26(data)            (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_25(data)            (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_seq_r_24(data)            (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_get_seq_r_31(data)        ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_get_seq_r_30(data)        ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_get_seq_r_29(data)        ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_get_seq_r_28(data)        ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_get_seq_r_27(data)        ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_get_seq_r_26(data)        ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_get_seq_r_25(data)        ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Red_24_31_get_seq_r_24(data)        (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07                         0x1802C610
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_reg_addr                "0xB802C610"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_reg                     0xB802C610
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_inst_addr               "0x0044"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_reg(data)           (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_reg                 (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_7_shift           (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_6_shift           (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_5_shift           (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_4_shift           (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_3_shift           (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_2_shift           (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_1_shift           (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_0_shift           (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_7_mask            (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_6_mask            (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_5_mask            (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_4_mask            (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_3_mask            (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_2_mask            (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_1_mask            (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_0_mask            (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_7(data)           (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_6(data)           (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_5(data)           (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_4(data)           (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_3(data)           (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_2(data)           (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_1(data)           (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_seq_g_0(data)           (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_get_seq_g_7(data)       ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_get_seq_g_6(data)       ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_get_seq_g_5(data)       ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_get_seq_g_4(data)       ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_get_seq_g_3(data)       ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_get_seq_g_2(data)       ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_get_seq_g_1(data)       ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_00_07_get_seq_g_0(data)       (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15                         0x1802C614
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_reg_addr                "0xB802C614"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_reg                     0xB802C614
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_inst_addr               "0x0045"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_reg(data)           (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_reg                 (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_15_shift          (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_14_shift          (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_13_shift          (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_12_shift          (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_11_shift          (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_10_shift          (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_9_shift           (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_8_shift           (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_15_mask           (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_14_mask           (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_13_mask           (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_12_mask           (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_11_mask           (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_10_mask           (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_9_mask            (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_8_mask            (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_15(data)          (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_14(data)          (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_13(data)          (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_12(data)          (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_11(data)          (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_10(data)          (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_9(data)           (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_seq_g_8(data)           (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_get_seq_g_15(data)      ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_get_seq_g_14(data)      ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_get_seq_g_13(data)      ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_get_seq_g_12(data)      ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_get_seq_g_11(data)      ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_get_seq_g_10(data)      ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_get_seq_g_9(data)       ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_08_15_get_seq_g_8(data)       (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23                         0x1802C618
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_reg_addr                "0xB802C618"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_reg                     0xB802C618
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_inst_addr               "0x0046"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_reg(data)           (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_reg                 (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_23_shift          (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_22_shift          (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_21_shift          (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_20_shift          (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_19_shift          (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_18_shift          (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_17_shift          (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_16_shift          (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_23_mask           (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_22_mask           (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_21_mask           (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_20_mask           (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_19_mask           (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_18_mask           (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_17_mask           (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_16_mask           (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_23(data)          (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_22(data)          (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_21(data)          (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_20(data)          (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_19(data)          (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_18(data)          (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_17(data)          (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_seq_g_16(data)          (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_get_seq_g_23(data)      ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_get_seq_g_22(data)      ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_get_seq_g_21(data)      ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_get_seq_g_20(data)      ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_get_seq_g_19(data)      ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_get_seq_g_18(data)      ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_get_seq_g_17(data)      ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_16_23_get_seq_g_16(data)      (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31                         0x1802C61C
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_reg_addr                "0xB802C61C"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_reg                     0xB802C61C
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_inst_addr               "0x0047"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_reg(data)           (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_reg                 (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_31_shift          (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_30_shift          (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_29_shift          (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_28_shift          (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_27_shift          (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_26_shift          (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_25_shift          (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_24_shift          (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_31_mask           (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_30_mask           (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_29_mask           (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_28_mask           (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_27_mask           (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_26_mask           (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_25_mask           (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_24_mask           (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_31(data)          (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_30(data)          (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_29(data)          (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_28(data)          (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_27(data)          (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_26(data)          (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_25(data)          (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_seq_g_24(data)          (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_get_seq_g_31(data)      ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_get_seq_g_30(data)      ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_get_seq_g_29(data)      ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_get_seq_g_28(data)      ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_get_seq_g_27(data)      ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_get_seq_g_26(data)      ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_get_seq_g_25(data)      ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Green_24_31_get_seq_g_24(data)      (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07                          0x1802C620
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_reg_addr                 "0xB802C620"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_reg                      0xB802C620
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_inst_addr                "0x0048"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_reg(data)            (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_reg                  (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_7_shift            (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_6_shift            (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_5_shift            (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_4_shift            (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_3_shift            (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_2_shift            (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_1_shift            (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_0_shift            (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_7_mask             (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_6_mask             (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_5_mask             (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_4_mask             (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_3_mask             (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_2_mask             (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_1_mask             (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_0_mask             (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_7(data)            (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_6(data)            (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_5(data)            (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_4(data)            (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_3(data)            (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_2(data)            (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_1(data)            (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_seq_b_0(data)            (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_get_seq_b_7(data)        ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_get_seq_b_6(data)        ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_get_seq_b_5(data)        ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_get_seq_b_4(data)        ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_get_seq_b_3(data)        ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_get_seq_b_2(data)        ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_get_seq_b_1(data)        ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_00_07_get_seq_b_0(data)        (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15                          0x1802C624
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_reg_addr                 "0xB802C624"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_reg                      0xB802C624
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_inst_addr                "0x0049"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_reg(data)            (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_reg                  (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_15_shift           (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_14_shift           (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_13_shift           (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_12_shift           (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_11_shift           (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_10_shift           (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_9_shift            (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_8_shift            (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_15_mask            (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_14_mask            (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_13_mask            (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_12_mask            (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_11_mask            (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_10_mask            (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_9_mask             (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_8_mask             (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_15(data)           (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_14(data)           (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_13(data)           (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_12(data)           (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_11(data)           (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_10(data)           (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_9(data)            (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_seq_b_8(data)            (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_get_seq_b_15(data)       ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_get_seq_b_14(data)       ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_get_seq_b_13(data)       ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_get_seq_b_12(data)       ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_get_seq_b_11(data)       ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_get_seq_b_10(data)       ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_get_seq_b_9(data)        ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_08_15_get_seq_b_8(data)        (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23                          0x1802C628
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_reg_addr                 "0xB802C628"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_reg                      0xB802C628
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_inst_addr                "0x004A"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_reg(data)            (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_reg                  (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_23_shift           (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_22_shift           (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_21_shift           (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_20_shift           (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_19_shift           (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_18_shift           (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_17_shift           (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_16_shift           (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_23_mask            (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_22_mask            (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_21_mask            (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_20_mask            (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_19_mask            (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_18_mask            (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_17_mask            (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_16_mask            (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_23(data)           (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_22(data)           (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_21(data)           (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_20(data)           (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_19(data)           (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_18(data)           (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_17(data)           (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_seq_b_16(data)           (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_get_seq_b_23(data)       ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_get_seq_b_22(data)       ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_get_seq_b_21(data)       ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_get_seq_b_20(data)       ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_get_seq_b_19(data)       ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_get_seq_b_18(data)       ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_get_seq_b_17(data)       ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_16_23_get_seq_b_16(data)       (0x0000000F&(data))

#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31                          0x1802C62C
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_reg_addr                 "0xB802C62C"
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_reg                      0xB802C62C
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_inst_addr                "0x004B"
#define  set_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_reg(data)            (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_reg)=data)
#define  get_DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_reg                  (*((volatile unsigned int*)DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_reg))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_31_shift           (28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_30_shift           (24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_29_shift           (20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_28_shift           (16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_27_shift           (12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_26_shift           (8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_25_shift           (4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_24_shift           (0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_31_mask            (0xF0000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_30_mask            (0x0F000000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_29_mask            (0x00F00000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_28_mask            (0x000F0000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_27_mask            (0x0000F000)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_26_mask            (0x00000F00)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_25_mask            (0x000000F0)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_24_mask            (0x0000000F)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_31(data)           (0xF0000000&((data)<<28))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_30(data)           (0x0F000000&((data)<<24))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_29(data)           (0x00F00000&((data)<<20))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_28(data)           (0x000F0000&((data)<<16))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_27(data)           (0x0000F000&((data)<<12))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_26(data)           (0x00000F00&((data)<<8))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_25(data)           (0x000000F0&((data)<<4))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_seq_b_24(data)           (0x0000000F&(data))
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_get_seq_b_31(data)       ((0xF0000000&(data))>>28)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_get_seq_b_30(data)       ((0x0F000000&(data))>>24)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_get_seq_b_29(data)       ((0x00F00000&(data))>>20)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_get_seq_b_28(data)       ((0x000F0000&(data))>>16)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_get_seq_b_27(data)       ((0x0000F000&(data))>>12)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_get_seq_b_26(data)       ((0x00000F00&(data))>>8)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_get_seq_b_25(data)       ((0x000000F0&(data))>>4)
#define  DITHER_DITHERING_2nd_SEQUENCE_TABLE_Blue_24_31_get_seq_b_24(data)       (0x0000000F&(data))

#define  DITHER_DITHERING_CTRL2                                                  0x1802C630
#define  DITHER_DITHERING_CTRL2_reg_addr                                         "0xB802C630"
#define  DITHER_DITHERING_CTRL2_reg                                              0xB802C630
#define  DITHER_DITHERING_CTRL2_inst_addr                                        "0x004C"
#define  set_DITHER_DITHERING_CTRL2_reg(data)                                    (*((volatile unsigned int*)DITHER_DITHERING_CTRL2_reg)=data)
#define  get_DITHER_DITHERING_CTRL2_reg                                          (*((volatile unsigned int*)DITHER_DITHERING_CTRL2_reg))
#define  DITHER_DITHERING_CTRL2_frame_count_by_3d_l_flag_inv_shift               (1)
#define  DITHER_DITHERING_CTRL2_frame_count_by_3d_flag_en_shift                  (0)
#define  DITHER_DITHERING_CTRL2_frame_count_by_3d_l_flag_inv_mask                (0x00000002)
#define  DITHER_DITHERING_CTRL2_frame_count_by_3d_flag_en_mask                   (0x00000001)
#define  DITHER_DITHERING_CTRL2_frame_count_by_3d_l_flag_inv(data)               (0x00000002&((data)<<1))
#define  DITHER_DITHERING_CTRL2_frame_count_by_3d_flag_en(data)                  (0x00000001&(data))
#define  DITHER_DITHERING_CTRL2_get_frame_count_by_3d_l_flag_inv(data)           ((0x00000002&(data))>>1)
#define  DITHER_DITHERING_CTRL2_get_frame_count_by_3d_flag_en(data)              (0x00000001&(data))

#define  DITHER_DITHERING_DD_TH_B                                                0x1802C634
#define  DITHER_DITHERING_DD_TH_B_reg_addr                                       "0xB802C634"
#define  DITHER_DITHERING_DD_TH_B_reg                                            0xB802C634
#define  DITHER_DITHERING_DD_TH_B_inst_addr                                      "0x004D"
#define  set_DITHER_DITHERING_DD_TH_B_reg(data)                                  (*((volatile unsigned int*)DITHER_DITHERING_DD_TH_B_reg)=data)
#define  get_DITHER_DITHERING_DD_TH_B_reg                                        (*((volatile unsigned int*)DITHER_DITHERING_DD_TH_B_reg))
#define  DITHER_DITHERING_DD_TH_B_dd_en_shift                                    (30)
#define  DITHER_DITHERING_DD_TH_B_dd_b_0_th_shift                                (18)
#define  DITHER_DITHERING_DD_TH_B_dd_b_1_th_shift                                (6)
#define  DITHER_DITHERING_DD_TH_B_dd_b_b0_type_shift                             (4)
#define  DITHER_DITHERING_DD_TH_B_dd_b_b1_type_shift                             (2)
#define  DITHER_DITHERING_DD_TH_B_dd_b_b2_type_shift                             (0)
#define  DITHER_DITHERING_DD_TH_B_dd_en_mask                                     (0x40000000)
#define  DITHER_DITHERING_DD_TH_B_dd_b_0_th_mask                                 (0x3FFC0000)
#define  DITHER_DITHERING_DD_TH_B_dd_b_1_th_mask                                 (0x0003FFC0)
#define  DITHER_DITHERING_DD_TH_B_dd_b_b0_type_mask                              (0x00000030)
#define  DITHER_DITHERING_DD_TH_B_dd_b_b1_type_mask                              (0x0000000C)
#define  DITHER_DITHERING_DD_TH_B_dd_b_b2_type_mask                              (0x00000003)
#define  DITHER_DITHERING_DD_TH_B_dd_en(data)                                    (0x40000000&((data)<<30))
#define  DITHER_DITHERING_DD_TH_B_dd_b_0_th(data)                                (0x3FFC0000&((data)<<18))
#define  DITHER_DITHERING_DD_TH_B_dd_b_1_th(data)                                (0x0003FFC0&((data)<<6))
#define  DITHER_DITHERING_DD_TH_B_dd_b_b0_type(data)                             (0x00000030&((data)<<4))
#define  DITHER_DITHERING_DD_TH_B_dd_b_b1_type(data)                             (0x0000000C&((data)<<2))
#define  DITHER_DITHERING_DD_TH_B_dd_b_b2_type(data)                             (0x00000003&(data))
#define  DITHER_DITHERING_DD_TH_B_get_dd_en(data)                                ((0x40000000&(data))>>30)
#define  DITHER_DITHERING_DD_TH_B_get_dd_b_0_th(data)                            ((0x3FFC0000&(data))>>18)
#define  DITHER_DITHERING_DD_TH_B_get_dd_b_1_th(data)                            ((0x0003FFC0&(data))>>6)
#define  DITHER_DITHERING_DD_TH_B_get_dd_b_b0_type(data)                         ((0x00000030&(data))>>4)
#define  DITHER_DITHERING_DD_TH_B_get_dd_b_b1_type(data)                         ((0x0000000C&(data))>>2)
#define  DITHER_DITHERING_DD_TH_B_get_dd_b_b2_type(data)                         (0x00000003&(data))

#define  DITHER_DITHERING_DD_TH_G                                                0x1802C638
#define  DITHER_DITHERING_DD_TH_G_reg_addr                                       "0xB802C638"
#define  DITHER_DITHERING_DD_TH_G_reg                                            0xB802C638
#define  DITHER_DITHERING_DD_TH_G_inst_addr                                      "0x004E"
#define  set_DITHER_DITHERING_DD_TH_G_reg(data)                                  (*((volatile unsigned int*)DITHER_DITHERING_DD_TH_G_reg)=data)
#define  get_DITHER_DITHERING_DD_TH_G_reg                                        (*((volatile unsigned int*)DITHER_DITHERING_DD_TH_G_reg))
#define  DITHER_DITHERING_DD_TH_G_dd_g_0_th_shift                                (18)
#define  DITHER_DITHERING_DD_TH_G_dd_g_1_th_shift                                (6)
#define  DITHER_DITHERING_DD_TH_G_dd_g_b0_type_shift                             (4)
#define  DITHER_DITHERING_DD_TH_G_dd_g_b1_type_shift                             (2)
#define  DITHER_DITHERING_DD_TH_G_dd_g_b2_type_shift                             (0)
#define  DITHER_DITHERING_DD_TH_G_dd_g_0_th_mask                                 (0x3FFC0000)
#define  DITHER_DITHERING_DD_TH_G_dd_g_1_th_mask                                 (0x0003FFC0)
#define  DITHER_DITHERING_DD_TH_G_dd_g_b0_type_mask                              (0x00000030)
#define  DITHER_DITHERING_DD_TH_G_dd_g_b1_type_mask                              (0x0000000C)
#define  DITHER_DITHERING_DD_TH_G_dd_g_b2_type_mask                              (0x00000003)
#define  DITHER_DITHERING_DD_TH_G_dd_g_0_th(data)                                (0x3FFC0000&((data)<<18))
#define  DITHER_DITHERING_DD_TH_G_dd_g_1_th(data)                                (0x0003FFC0&((data)<<6))
#define  DITHER_DITHERING_DD_TH_G_dd_g_b0_type(data)                             (0x00000030&((data)<<4))
#define  DITHER_DITHERING_DD_TH_G_dd_g_b1_type(data)                             (0x0000000C&((data)<<2))
#define  DITHER_DITHERING_DD_TH_G_dd_g_b2_type(data)                             (0x00000003&(data))
#define  DITHER_DITHERING_DD_TH_G_get_dd_g_0_th(data)                            ((0x3FFC0000&(data))>>18)
#define  DITHER_DITHERING_DD_TH_G_get_dd_g_1_th(data)                            ((0x0003FFC0&(data))>>6)
#define  DITHER_DITHERING_DD_TH_G_get_dd_g_b0_type(data)                         ((0x00000030&(data))>>4)
#define  DITHER_DITHERING_DD_TH_G_get_dd_g_b1_type(data)                         ((0x0000000C&(data))>>2)
#define  DITHER_DITHERING_DD_TH_G_get_dd_g_b2_type(data)                         (0x00000003&(data))

#define  DITHER_DITHERING_DD_TH_R                                                0x1802C63C
#define  DITHER_DITHERING_DD_TH_R_reg_addr                                       "0xB802C63C"
#define  DITHER_DITHERING_DD_TH_R_reg                                            0xB802C63C
#define  DITHER_DITHERING_DD_TH_R_inst_addr                                      "0x004F"
#define  set_DITHER_DITHERING_DD_TH_R_reg(data)                                  (*((volatile unsigned int*)DITHER_DITHERING_DD_TH_R_reg)=data)
#define  get_DITHER_DITHERING_DD_TH_R_reg                                        (*((volatile unsigned int*)DITHER_DITHERING_DD_TH_R_reg))
#define  DITHER_DITHERING_DD_TH_R_dd_r_0_th_shift                                (18)
#define  DITHER_DITHERING_DD_TH_R_dd_r_1_th_shift                                (6)
#define  DITHER_DITHERING_DD_TH_R_dd_r_b0_type_shift                             (4)
#define  DITHER_DITHERING_DD_TH_R_dd_r_b1_type_shift                             (2)
#define  DITHER_DITHERING_DD_TH_R_dd_r_b2_type_shift                             (0)
#define  DITHER_DITHERING_DD_TH_R_dd_r_0_th_mask                                 (0x3FFC0000)
#define  DITHER_DITHERING_DD_TH_R_dd_r_1_th_mask                                 (0x0003FFC0)
#define  DITHER_DITHERING_DD_TH_R_dd_r_b0_type_mask                              (0x00000030)
#define  DITHER_DITHERING_DD_TH_R_dd_r_b1_type_mask                              (0x0000000C)
#define  DITHER_DITHERING_DD_TH_R_dd_r_b2_type_mask                              (0x00000003)
#define  DITHER_DITHERING_DD_TH_R_dd_r_0_th(data)                                (0x3FFC0000&((data)<<18))
#define  DITHER_DITHERING_DD_TH_R_dd_r_1_th(data)                                (0x0003FFC0&((data)<<6))
#define  DITHER_DITHERING_DD_TH_R_dd_r_b0_type(data)                             (0x00000030&((data)<<4))
#define  DITHER_DITHERING_DD_TH_R_dd_r_b1_type(data)                             (0x0000000C&((data)<<2))
#define  DITHER_DITHERING_DD_TH_R_dd_r_b2_type(data)                             (0x00000003&(data))
#define  DITHER_DITHERING_DD_TH_R_get_dd_r_0_th(data)                            ((0x3FFC0000&(data))>>18)
#define  DITHER_DITHERING_DD_TH_R_get_dd_r_1_th(data)                            ((0x0003FFC0&(data))>>6)
#define  DITHER_DITHERING_DD_TH_R_get_dd_r_b0_type(data)                         ((0x00000030&(data))>>4)
#define  DITHER_DITHERING_DD_TH_R_get_dd_r_b1_type(data)                         ((0x0000000C&(data))>>2)
#define  DITHER_DITHERING_DD_TH_R_get_dd_r_b2_type(data)                         (0x00000003&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_2nd_b_th:8;
        RBus_UInt32  seq_2nd_g_th:8;
        RBus_UInt32  seq_2nd_r_th:8;
        RBus_UInt32  seq_2nd_mode:1;
        RBus_UInt32  test_mode:1;
        RBus_UInt32  function_enable:1;
        RBus_UInt32  temporal_enable:1;
        RBus_UInt32  value_sign:1;
        RBus_UInt32  dithering_mode:1;
        RBus_UInt32  v_modulation:1;
        RBus_UInt32  h_modulation:1;
    };
}dither_dithering_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_7:4;
        RBus_UInt32  seq_r_6:4;
        RBus_UInt32  seq_r_5:4;
        RBus_UInt32  seq_r_4:4;
        RBus_UInt32  seq_r_3:4;
        RBus_UInt32  seq_r_2:4;
        RBus_UInt32  seq_r_1:4;
        RBus_UInt32  seq_r_0:4;
    };
}dither_dithering_sequence_table_red_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_15:4;
        RBus_UInt32  seq_r_14:4;
        RBus_UInt32  seq_r_13:4;
        RBus_UInt32  seq_r_12:4;
        RBus_UInt32  seq_r_11:4;
        RBus_UInt32  seq_r_10:4;
        RBus_UInt32  seq_r_9:4;
        RBus_UInt32  seq_r_8:4;
    };
}dither_dithering_sequence_table_red_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_23:4;
        RBus_UInt32  seq_r_22:4;
        RBus_UInt32  seq_r_21:4;
        RBus_UInt32  seq_r_20:4;
        RBus_UInt32  seq_r_19:4;
        RBus_UInt32  seq_r_18:4;
        RBus_UInt32  seq_r_17:4;
        RBus_UInt32  seq_r_16:4;
    };
}dither_dithering_sequence_table_red_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_31:4;
        RBus_UInt32  seq_r_30:4;
        RBus_UInt32  seq_r_29:4;
        RBus_UInt32  seq_r_28:4;
        RBus_UInt32  seq_r_27:4;
        RBus_UInt32  seq_r_26:4;
        RBus_UInt32  seq_r_25:4;
        RBus_UInt32  seq_r_24:4;
    };
}dither_dithering_sequence_table_red_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_7:4;
        RBus_UInt32  seq_g_6:4;
        RBus_UInt32  seq_g_5:4;
        RBus_UInt32  seq_g_4:4;
        RBus_UInt32  seq_g_3:4;
        RBus_UInt32  seq_g_2:4;
        RBus_UInt32  seq_g_1:4;
        RBus_UInt32  seq_g_0:4;
    };
}dither_dithering_sequence_table_green_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_15:4;
        RBus_UInt32  seq_g_14:4;
        RBus_UInt32  seq_g_13:4;
        RBus_UInt32  seq_g_12:4;
        RBus_UInt32  seq_g_11:4;
        RBus_UInt32  seq_g_10:4;
        RBus_UInt32  seq_g_9:4;
        RBus_UInt32  seq_g_8:4;
    };
}dither_dithering_sequence_table_green_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_23:4;
        RBus_UInt32  seq_g_22:4;
        RBus_UInt32  seq_g_21:4;
        RBus_UInt32  seq_g_20:4;
        RBus_UInt32  seq_g_19:4;
        RBus_UInt32  seq_g_18:4;
        RBus_UInt32  seq_g_17:4;
        RBus_UInt32  seq_g_16:4;
    };
}dither_dithering_sequence_table_green_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_31:4;
        RBus_UInt32  seq_g_30:4;
        RBus_UInt32  seq_g_29:4;
        RBus_UInt32  seq_g_28:4;
        RBus_UInt32  seq_g_27:4;
        RBus_UInt32  seq_g_26:4;
        RBus_UInt32  seq_g_25:4;
        RBus_UInt32  seq_g_24:4;
    };
}dither_dithering_sequence_table_green_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_7:4;
        RBus_UInt32  seq_b_6:4;
        RBus_UInt32  seq_b_5:4;
        RBus_UInt32  seq_b_4:4;
        RBus_UInt32  seq_b_3:4;
        RBus_UInt32  seq_b_2:4;
        RBus_UInt32  seq_b_1:4;
        RBus_UInt32  seq_b_0:4;
    };
}dither_dithering_sequence_table_blue_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_15:4;
        RBus_UInt32  seq_b_14:4;
        RBus_UInt32  seq_b_13:4;
        RBus_UInt32  seq_b_12:4;
        RBus_UInt32  seq_b_11:4;
        RBus_UInt32  seq_b_10:4;
        RBus_UInt32  seq_b_9:4;
        RBus_UInt32  seq_b_8:4;
    };
}dither_dithering_sequence_table_blue_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_23:4;
        RBus_UInt32  seq_b_22:4;
        RBus_UInt32  seq_b_21:4;
        RBus_UInt32  seq_b_20:4;
        RBus_UInt32  seq_b_19:4;
        RBus_UInt32  seq_b_18:4;
        RBus_UInt32  seq_b_17:4;
        RBus_UInt32  seq_b_16:4;
    };
}dither_dithering_sequence_table_blue_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_31:4;
        RBus_UInt32  seq_b_30:4;
        RBus_UInt32  seq_b_29:4;
        RBus_UInt32  seq_b_28:4;
        RBus_UInt32  seq_b_27:4;
        RBus_UInt32  seq_b_26:4;
        RBus_UInt32  seq_b_25:4;
        RBus_UInt32  seq_b_24:4;
    };
}dither_dithering_sequence_table_blue_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_03:6;
        RBus_UInt32  tab_r_02:6;
        RBus_UInt32  tab_r_01:6;
        RBus_UInt32  tab_r_00:6;
    };
}dither_dithering_dither_table_red_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_13:6;
        RBus_UInt32  tab_r_12:6;
        RBus_UInt32  tab_r_11:6;
        RBus_UInt32  tab_r_10:6;
    };
}dither_dithering_dither_table_red_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_23:6;
        RBus_UInt32  tab_r_22:6;
        RBus_UInt32  tab_r_21:6;
        RBus_UInt32  tab_r_20:6;
    };
}dither_dithering_dither_table_red_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_33:6;
        RBus_UInt32  tab_r_32:6;
        RBus_UInt32  tab_r_31:6;
        RBus_UInt32  tab_r_30:6;
    };
}dither_dithering_dither_table_red_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_43:6;
        RBus_UInt32  tab_r_42:6;
        RBus_UInt32  tab_r_41:6;
        RBus_UInt32  tab_r_40:6;
    };
}dither_dithering_dither_table_red_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_53:6;
        RBus_UInt32  tab_r_52:6;
        RBus_UInt32  tab_r_51:6;
        RBus_UInt32  tab_r_50:6;
    };
}dither_dithering_dither_table_red_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_63:6;
        RBus_UInt32  tab_r_62:6;
        RBus_UInt32  tab_r_61:6;
        RBus_UInt32  tab_r_60:6;
    };
}dither_dithering_dither_table_red_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_73:6;
        RBus_UInt32  tab_r_72:6;
        RBus_UInt32  tab_r_71:6;
        RBus_UInt32  tab_r_70:6;
    };
}dither_dithering_dither_table_red_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_83:6;
        RBus_UInt32  tab_r_82:6;
        RBus_UInt32  tab_r_81:6;
        RBus_UInt32  tab_r_80:6;
    };
}dither_dithering_dither_table_red_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_93:6;
        RBus_UInt32  tab_r_92:6;
        RBus_UInt32  tab_r_91:6;
        RBus_UInt32  tab_r_90:6;
    };
}dither_dithering_dither_table_red_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_a3:6;
        RBus_UInt32  tab_r_a2:6;
        RBus_UInt32  tab_r_a1:6;
        RBus_UInt32  tab_r_a0:6;
    };
}dither_dithering_dither_table_red_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_b3:6;
        RBus_UInt32  tab_r_b2:6;
        RBus_UInt32  tab_r_b1:6;
        RBus_UInt32  tab_r_b0:6;
    };
}dither_dithering_dither_table_red_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_c3:6;
        RBus_UInt32  tab_r_c2:6;
        RBus_UInt32  tab_r_c1:6;
        RBus_UInt32  tab_r_c0:6;
    };
}dither_dithering_dither_table_red_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_d3:6;
        RBus_UInt32  tab_r_d2:6;
        RBus_UInt32  tab_r_d1:6;
        RBus_UInt32  tab_r_d0:6;
    };
}dither_dithering_dither_table_red_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_e3:6;
        RBus_UInt32  tab_r_e2:6;
        RBus_UInt32  tab_r_e1:6;
        RBus_UInt32  tab_r_e0:6;
    };
}dither_dithering_dither_table_red_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_r_f3:6;
        RBus_UInt32  tab_r_f2:6;
        RBus_UInt32  tab_r_f1:6;
        RBus_UInt32  tab_r_f0:6;
    };
}dither_dithering_dither_table_red_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_03:6;
        RBus_UInt32  tab_g_02:6;
        RBus_UInt32  tab_g_01:6;
        RBus_UInt32  tab_g_00:6;
    };
}dither_dithering_dither_table_green_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_13:6;
        RBus_UInt32  tab_g_12:6;
        RBus_UInt32  tab_g_11:6;
        RBus_UInt32  tab_g_10:6;
    };
}dither_dithering_dither_table_green_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_23:6;
        RBus_UInt32  tab_g_22:6;
        RBus_UInt32  tab_g_21:6;
        RBus_UInt32  tab_g_20:6;
    };
}dither_dithering_dither_table_green_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_33:6;
        RBus_UInt32  tab_g_32:6;
        RBus_UInt32  tab_g_31:6;
        RBus_UInt32  tab_g_30:6;
    };
}dither_dithering_dither_table_green_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_43:6;
        RBus_UInt32  tab_g_42:6;
        RBus_UInt32  tab_g_41:6;
        RBus_UInt32  tab_g_40:6;
    };
}dither_dithering_dither_table_green_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_53:6;
        RBus_UInt32  tab_g_52:6;
        RBus_UInt32  tab_g_51:6;
        RBus_UInt32  tab_g_50:6;
    };
}dither_dithering_dither_table_green_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_63:6;
        RBus_UInt32  tab_g_62:6;
        RBus_UInt32  tab_g_61:6;
        RBus_UInt32  tab_g_60:6;
    };
}dither_dithering_dither_table_green_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_73:6;
        RBus_UInt32  tab_g_72:6;
        RBus_UInt32  tab_g_71:6;
        RBus_UInt32  tab_g_70:6;
    };
}dither_dithering_dither_table_green_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_83:6;
        RBus_UInt32  tab_g_82:6;
        RBus_UInt32  tab_g_81:6;
        RBus_UInt32  tab_g_80:6;
    };
}dither_dithering_dither_table_green_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_93:6;
        RBus_UInt32  tab_g_92:6;
        RBus_UInt32  tab_g_91:6;
        RBus_UInt32  tab_g_90:6;
    };
}dither_dithering_dither_table_green_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_a3:6;
        RBus_UInt32  tab_g_a2:6;
        RBus_UInt32  tab_g_a1:6;
        RBus_UInt32  tab_g_a0:6;
    };
}dither_dithering_dither_table_green_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_b3:6;
        RBus_UInt32  tab_g_b2:6;
        RBus_UInt32  tab_g_b1:6;
        RBus_UInt32  tab_g_b0:6;
    };
}dither_dithering_dither_table_green_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_c3:6;
        RBus_UInt32  tab_g_c2:6;
        RBus_UInt32  tab_g_c1:6;
        RBus_UInt32  tab_g_c0:6;
    };
}dither_dithering_dither_table_green_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_d3:6;
        RBus_UInt32  tab_g_d2:6;
        RBus_UInt32  tab_g_d1:6;
        RBus_UInt32  tab_g_d0:6;
    };
}dither_dithering_dither_table_green_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_e3:6;
        RBus_UInt32  tab_g_e2:6;
        RBus_UInt32  tab_g_e1:6;
        RBus_UInt32  tab_g_e0:6;
    };
}dither_dithering_dither_table_green_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_g_f3:6;
        RBus_UInt32  tab_g_f2:6;
        RBus_UInt32  tab_g_f1:6;
        RBus_UInt32  tab_g_f0:6;
    };
}dither_dithering_dither_table_green_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_03:6;
        RBus_UInt32  tab_b_02:6;
        RBus_UInt32  tab_b_01:6;
        RBus_UInt32  tab_b_00:6;
    };
}dither_dithering_dither_table_blue_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_13:6;
        RBus_UInt32  tab_b_12:6;
        RBus_UInt32  tab_b_11:6;
        RBus_UInt32  tab_b_10:6;
    };
}dither_dithering_dither_table_blue_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_23:6;
        RBus_UInt32  tab_b_22:6;
        RBus_UInt32  tab_b_21:6;
        RBus_UInt32  tab_b_20:6;
    };
}dither_dithering_dither_table_blue_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_33:6;
        RBus_UInt32  tab_b_32:6;
        RBus_UInt32  tab_b_31:6;
        RBus_UInt32  tab_b_30:6;
    };
}dither_dithering_dither_table_blue_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_43:6;
        RBus_UInt32  tab_b_42:6;
        RBus_UInt32  tab_b_41:6;
        RBus_UInt32  tab_b_40:6;
    };
}dither_dithering_dither_table_blue_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_53:6;
        RBus_UInt32  tab_b_52:6;
        RBus_UInt32  tab_b_51:6;
        RBus_UInt32  tab_b_50:6;
    };
}dither_dithering_dither_table_blue_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_63:6;
        RBus_UInt32  tab_b_62:6;
        RBus_UInt32  tab_b_61:6;
        RBus_UInt32  tab_b_60:6;
    };
}dither_dithering_dither_table_blue_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_73:6;
        RBus_UInt32  tab_b_72:6;
        RBus_UInt32  tab_b_71:6;
        RBus_UInt32  tab_b_70:6;
    };
}dither_dithering_dither_table_blue_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_83:6;
        RBus_UInt32  tab_b_82:6;
        RBus_UInt32  tab_b_81:6;
        RBus_UInt32  tab_b_80:6;
    };
}dither_dithering_dither_table_blue_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_93:6;
        RBus_UInt32  tab_b_92:6;
        RBus_UInt32  tab_b_91:6;
        RBus_UInt32  tab_b_90:6;
    };
}dither_dithering_dither_table_blue_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_a3:6;
        RBus_UInt32  tab_b_a2:6;
        RBus_UInt32  tab_b_a1:6;
        RBus_UInt32  tab_b_a0:6;
    };
}dither_dithering_dither_table_blue_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_b3:6;
        RBus_UInt32  tab_b_b2:6;
        RBus_UInt32  tab_b_b1:6;
        RBus_UInt32  tab_b_b0:6;
    };
}dither_dithering_dither_table_blue_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_c3:6;
        RBus_UInt32  tab_b_c2:6;
        RBus_UInt32  tab_b_c1:6;
        RBus_UInt32  tab_b_c0:6;
    };
}dither_dithering_dither_table_blue_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_d3:6;
        RBus_UInt32  tab_b_d2:6;
        RBus_UInt32  tab_b_d1:6;
        RBus_UInt32  tab_b_d0:6;
    };
}dither_dithering_dither_table_blue_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_e3:6;
        RBus_UInt32  tab_b_e2:6;
        RBus_UInt32  tab_b_e1:6;
        RBus_UInt32  tab_b_e0:6;
    };
}dither_dithering_dither_table_blue_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tab_b_f3:6;
        RBus_UInt32  tab_b_f2:6;
        RBus_UInt32  tab_b_f1:6;
        RBus_UInt32  tab_b_f0:6;
    };
}dither_dithering_dither_table_blue_0f_RBUS;

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
}dither_temporal_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dither_crc_conti:1;
        RBus_UInt32  dither_crc_start:1;
    };
}dither_dither_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_crc_result:32;
    };
}dither_dither_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_7:4;
        RBus_UInt32  seq_r_6:4;
        RBus_UInt32  seq_r_5:4;
        RBus_UInt32  seq_r_4:4;
        RBus_UInt32  seq_r_3:4;
        RBus_UInt32  seq_r_2:4;
        RBus_UInt32  seq_r_1:4;
        RBus_UInt32  seq_r_0:4;
    };
}dither_dithering_2nd_sequence_table_red_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_15:4;
        RBus_UInt32  seq_r_14:4;
        RBus_UInt32  seq_r_13:4;
        RBus_UInt32  seq_r_12:4;
        RBus_UInt32  seq_r_11:4;
        RBus_UInt32  seq_r_10:4;
        RBus_UInt32  seq_r_9:4;
        RBus_UInt32  seq_r_8:4;
    };
}dither_dithering_2nd_sequence_table_red_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_23:4;
        RBus_UInt32  seq_r_22:4;
        RBus_UInt32  seq_r_21:4;
        RBus_UInt32  seq_r_20:4;
        RBus_UInt32  seq_r_19:4;
        RBus_UInt32  seq_r_18:4;
        RBus_UInt32  seq_r_17:4;
        RBus_UInt32  seq_r_16:4;
    };
}dither_dithering_2nd_sequence_table_red_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_31:4;
        RBus_UInt32  seq_r_30:4;
        RBus_UInt32  seq_r_29:4;
        RBus_UInt32  seq_r_28:4;
        RBus_UInt32  seq_r_27:4;
        RBus_UInt32  seq_r_26:4;
        RBus_UInt32  seq_r_25:4;
        RBus_UInt32  seq_r_24:4;
    };
}dither_dithering_2nd_sequence_table_red_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_7:4;
        RBus_UInt32  seq_g_6:4;
        RBus_UInt32  seq_g_5:4;
        RBus_UInt32  seq_g_4:4;
        RBus_UInt32  seq_g_3:4;
        RBus_UInt32  seq_g_2:4;
        RBus_UInt32  seq_g_1:4;
        RBus_UInt32  seq_g_0:4;
    };
}dither_dithering_2nd_sequence_table_green_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_15:4;
        RBus_UInt32  seq_g_14:4;
        RBus_UInt32  seq_g_13:4;
        RBus_UInt32  seq_g_12:4;
        RBus_UInt32  seq_g_11:4;
        RBus_UInt32  seq_g_10:4;
        RBus_UInt32  seq_g_9:4;
        RBus_UInt32  seq_g_8:4;
    };
}dither_dithering_2nd_sequence_table_green_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_23:4;
        RBus_UInt32  seq_g_22:4;
        RBus_UInt32  seq_g_21:4;
        RBus_UInt32  seq_g_20:4;
        RBus_UInt32  seq_g_19:4;
        RBus_UInt32  seq_g_18:4;
        RBus_UInt32  seq_g_17:4;
        RBus_UInt32  seq_g_16:4;
    };
}dither_dithering_2nd_sequence_table_green_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_31:4;
        RBus_UInt32  seq_g_30:4;
        RBus_UInt32  seq_g_29:4;
        RBus_UInt32  seq_g_28:4;
        RBus_UInt32  seq_g_27:4;
        RBus_UInt32  seq_g_26:4;
        RBus_UInt32  seq_g_25:4;
        RBus_UInt32  seq_g_24:4;
    };
}dither_dithering_2nd_sequence_table_green_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_7:4;
        RBus_UInt32  seq_b_6:4;
        RBus_UInt32  seq_b_5:4;
        RBus_UInt32  seq_b_4:4;
        RBus_UInt32  seq_b_3:4;
        RBus_UInt32  seq_b_2:4;
        RBus_UInt32  seq_b_1:4;
        RBus_UInt32  seq_b_0:4;
    };
}dither_dithering_2nd_sequence_table_blue_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_15:4;
        RBus_UInt32  seq_b_14:4;
        RBus_UInt32  seq_b_13:4;
        RBus_UInt32  seq_b_12:4;
        RBus_UInt32  seq_b_11:4;
        RBus_UInt32  seq_b_10:4;
        RBus_UInt32  seq_b_9:4;
        RBus_UInt32  seq_b_8:4;
    };
}dither_dithering_2nd_sequence_table_blue_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_23:4;
        RBus_UInt32  seq_b_22:4;
        RBus_UInt32  seq_b_21:4;
        RBus_UInt32  seq_b_20:4;
        RBus_UInt32  seq_b_19:4;
        RBus_UInt32  seq_b_18:4;
        RBus_UInt32  seq_b_17:4;
        RBus_UInt32  seq_b_16:4;
    };
}dither_dithering_2nd_sequence_table_blue_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_31:4;
        RBus_UInt32  seq_b_30:4;
        RBus_UInt32  seq_b_29:4;
        RBus_UInt32  seq_b_28:4;
        RBus_UInt32  seq_b_27:4;
        RBus_UInt32  seq_b_26:4;
        RBus_UInt32  seq_b_25:4;
        RBus_UInt32  seq_b_24:4;
    };
}dither_dithering_2nd_sequence_table_blue_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  frame_count_by_3d_l_flag_inv:1;
        RBus_UInt32  frame_count_by_3d_flag_en:1;
    };
}dither_dithering_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dd_en:1;
        RBus_UInt32  dd_b_0_th:12;
        RBus_UInt32  dd_b_1_th:12;
        RBus_UInt32  dd_b_b0_type:2;
        RBus_UInt32  dd_b_b1_type:2;
        RBus_UInt32  dd_b_b2_type:2;
    };
}dither_dithering_dd_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dd_g_0_th:12;
        RBus_UInt32  dd_g_1_th:12;
        RBus_UInt32  dd_g_b0_type:2;
        RBus_UInt32  dd_g_b1_type:2;
        RBus_UInt32  dd_g_b2_type:2;
    };
}dither_dithering_dd_th_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dd_r_0_th:12;
        RBus_UInt32  dd_r_1_th:12;
        RBus_UInt32  dd_r_b0_type:2;
        RBus_UInt32  dd_r_b1_type:2;
        RBus_UInt32  dd_r_b2_type:2;
    };
}dither_dithering_dd_th_r_RBUS;

#else //apply LITTLE_ENDIAN

//======DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_modulation:1;
        RBus_UInt32  v_modulation:1;
        RBus_UInt32  dithering_mode:1;
        RBus_UInt32  value_sign:1;
        RBus_UInt32  temporal_enable:1;
        RBus_UInt32  function_enable:1;
        RBus_UInt32  test_mode:1;
        RBus_UInt32  seq_2nd_mode:1;
        RBus_UInt32  seq_2nd_r_th:8;
        RBus_UInt32  seq_2nd_g_th:8;
        RBus_UInt32  seq_2nd_b_th:8;
    };
}dither_dithering_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_0:4;
        RBus_UInt32  seq_r_1:4;
        RBus_UInt32  seq_r_2:4;
        RBus_UInt32  seq_r_3:4;
        RBus_UInt32  seq_r_4:4;
        RBus_UInt32  seq_r_5:4;
        RBus_UInt32  seq_r_6:4;
        RBus_UInt32  seq_r_7:4;
    };
}dither_dithering_sequence_table_red_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_8:4;
        RBus_UInt32  seq_r_9:4;
        RBus_UInt32  seq_r_10:4;
        RBus_UInt32  seq_r_11:4;
        RBus_UInt32  seq_r_12:4;
        RBus_UInt32  seq_r_13:4;
        RBus_UInt32  seq_r_14:4;
        RBus_UInt32  seq_r_15:4;
    };
}dither_dithering_sequence_table_red_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_16:4;
        RBus_UInt32  seq_r_17:4;
        RBus_UInt32  seq_r_18:4;
        RBus_UInt32  seq_r_19:4;
        RBus_UInt32  seq_r_20:4;
        RBus_UInt32  seq_r_21:4;
        RBus_UInt32  seq_r_22:4;
        RBus_UInt32  seq_r_23:4;
    };
}dither_dithering_sequence_table_red_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_24:4;
        RBus_UInt32  seq_r_25:4;
        RBus_UInt32  seq_r_26:4;
        RBus_UInt32  seq_r_27:4;
        RBus_UInt32  seq_r_28:4;
        RBus_UInt32  seq_r_29:4;
        RBus_UInt32  seq_r_30:4;
        RBus_UInt32  seq_r_31:4;
    };
}dither_dithering_sequence_table_red_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_0:4;
        RBus_UInt32  seq_g_1:4;
        RBus_UInt32  seq_g_2:4;
        RBus_UInt32  seq_g_3:4;
        RBus_UInt32  seq_g_4:4;
        RBus_UInt32  seq_g_5:4;
        RBus_UInt32  seq_g_6:4;
        RBus_UInt32  seq_g_7:4;
    };
}dither_dithering_sequence_table_green_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_8:4;
        RBus_UInt32  seq_g_9:4;
        RBus_UInt32  seq_g_10:4;
        RBus_UInt32  seq_g_11:4;
        RBus_UInt32  seq_g_12:4;
        RBus_UInt32  seq_g_13:4;
        RBus_UInt32  seq_g_14:4;
        RBus_UInt32  seq_g_15:4;
    };
}dither_dithering_sequence_table_green_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_16:4;
        RBus_UInt32  seq_g_17:4;
        RBus_UInt32  seq_g_18:4;
        RBus_UInt32  seq_g_19:4;
        RBus_UInt32  seq_g_20:4;
        RBus_UInt32  seq_g_21:4;
        RBus_UInt32  seq_g_22:4;
        RBus_UInt32  seq_g_23:4;
    };
}dither_dithering_sequence_table_green_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_24:4;
        RBus_UInt32  seq_g_25:4;
        RBus_UInt32  seq_g_26:4;
        RBus_UInt32  seq_g_27:4;
        RBus_UInt32  seq_g_28:4;
        RBus_UInt32  seq_g_29:4;
        RBus_UInt32  seq_g_30:4;
        RBus_UInt32  seq_g_31:4;
    };
}dither_dithering_sequence_table_green_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_0:4;
        RBus_UInt32  seq_b_1:4;
        RBus_UInt32  seq_b_2:4;
        RBus_UInt32  seq_b_3:4;
        RBus_UInt32  seq_b_4:4;
        RBus_UInt32  seq_b_5:4;
        RBus_UInt32  seq_b_6:4;
        RBus_UInt32  seq_b_7:4;
    };
}dither_dithering_sequence_table_blue_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_8:4;
        RBus_UInt32  seq_b_9:4;
        RBus_UInt32  seq_b_10:4;
        RBus_UInt32  seq_b_11:4;
        RBus_UInt32  seq_b_12:4;
        RBus_UInt32  seq_b_13:4;
        RBus_UInt32  seq_b_14:4;
        RBus_UInt32  seq_b_15:4;
    };
}dither_dithering_sequence_table_blue_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_16:4;
        RBus_UInt32  seq_b_17:4;
        RBus_UInt32  seq_b_18:4;
        RBus_UInt32  seq_b_19:4;
        RBus_UInt32  seq_b_20:4;
        RBus_UInt32  seq_b_21:4;
        RBus_UInt32  seq_b_22:4;
        RBus_UInt32  seq_b_23:4;
    };
}dither_dithering_sequence_table_blue_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_24:4;
        RBus_UInt32  seq_b_25:4;
        RBus_UInt32  seq_b_26:4;
        RBus_UInt32  seq_b_27:4;
        RBus_UInt32  seq_b_28:4;
        RBus_UInt32  seq_b_29:4;
        RBus_UInt32  seq_b_30:4;
        RBus_UInt32  seq_b_31:4;
    };
}dither_dithering_sequence_table_blue_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_00:6;
        RBus_UInt32  tab_r_01:6;
        RBus_UInt32  tab_r_02:6;
        RBus_UInt32  tab_r_03:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_10:6;
        RBus_UInt32  tab_r_11:6;
        RBus_UInt32  tab_r_12:6;
        RBus_UInt32  tab_r_13:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_20:6;
        RBus_UInt32  tab_r_21:6;
        RBus_UInt32  tab_r_22:6;
        RBus_UInt32  tab_r_23:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_30:6;
        RBus_UInt32  tab_r_31:6;
        RBus_UInt32  tab_r_32:6;
        RBus_UInt32  tab_r_33:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_40:6;
        RBus_UInt32  tab_r_41:6;
        RBus_UInt32  tab_r_42:6;
        RBus_UInt32  tab_r_43:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_50:6;
        RBus_UInt32  tab_r_51:6;
        RBus_UInt32  tab_r_52:6;
        RBus_UInt32  tab_r_53:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_60:6;
        RBus_UInt32  tab_r_61:6;
        RBus_UInt32  tab_r_62:6;
        RBus_UInt32  tab_r_63:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_70:6;
        RBus_UInt32  tab_r_71:6;
        RBus_UInt32  tab_r_72:6;
        RBus_UInt32  tab_r_73:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_80:6;
        RBus_UInt32  tab_r_81:6;
        RBus_UInt32  tab_r_82:6;
        RBus_UInt32  tab_r_83:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_90:6;
        RBus_UInt32  tab_r_91:6;
        RBus_UInt32  tab_r_92:6;
        RBus_UInt32  tab_r_93:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_a0:6;
        RBus_UInt32  tab_r_a1:6;
        RBus_UInt32  tab_r_a2:6;
        RBus_UInt32  tab_r_a3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_b0:6;
        RBus_UInt32  tab_r_b1:6;
        RBus_UInt32  tab_r_b2:6;
        RBus_UInt32  tab_r_b3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_c0:6;
        RBus_UInt32  tab_r_c1:6;
        RBus_UInt32  tab_r_c2:6;
        RBus_UInt32  tab_r_c3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_d0:6;
        RBus_UInt32  tab_r_d1:6;
        RBus_UInt32  tab_r_d2:6;
        RBus_UInt32  tab_r_d3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_e0:6;
        RBus_UInt32  tab_r_e1:6;
        RBus_UInt32  tab_r_e2:6;
        RBus_UInt32  tab_r_e3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_r_f0:6;
        RBus_UInt32  tab_r_f1:6;
        RBus_UInt32  tab_r_f2:6;
        RBus_UInt32  tab_r_f3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_red_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_00:6;
        RBus_UInt32  tab_g_01:6;
        RBus_UInt32  tab_g_02:6;
        RBus_UInt32  tab_g_03:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_10:6;
        RBus_UInt32  tab_g_11:6;
        RBus_UInt32  tab_g_12:6;
        RBus_UInt32  tab_g_13:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_20:6;
        RBus_UInt32  tab_g_21:6;
        RBus_UInt32  tab_g_22:6;
        RBus_UInt32  tab_g_23:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_30:6;
        RBus_UInt32  tab_g_31:6;
        RBus_UInt32  tab_g_32:6;
        RBus_UInt32  tab_g_33:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_40:6;
        RBus_UInt32  tab_g_41:6;
        RBus_UInt32  tab_g_42:6;
        RBus_UInt32  tab_g_43:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_50:6;
        RBus_UInt32  tab_g_51:6;
        RBus_UInt32  tab_g_52:6;
        RBus_UInt32  tab_g_53:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_60:6;
        RBus_UInt32  tab_g_61:6;
        RBus_UInt32  tab_g_62:6;
        RBus_UInt32  tab_g_63:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_70:6;
        RBus_UInt32  tab_g_71:6;
        RBus_UInt32  tab_g_72:6;
        RBus_UInt32  tab_g_73:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_80:6;
        RBus_UInt32  tab_g_81:6;
        RBus_UInt32  tab_g_82:6;
        RBus_UInt32  tab_g_83:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_90:6;
        RBus_UInt32  tab_g_91:6;
        RBus_UInt32  tab_g_92:6;
        RBus_UInt32  tab_g_93:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_a0:6;
        RBus_UInt32  tab_g_a1:6;
        RBus_UInt32  tab_g_a2:6;
        RBus_UInt32  tab_g_a3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_b0:6;
        RBus_UInt32  tab_g_b1:6;
        RBus_UInt32  tab_g_b2:6;
        RBus_UInt32  tab_g_b3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_c0:6;
        RBus_UInt32  tab_g_c1:6;
        RBus_UInt32  tab_g_c2:6;
        RBus_UInt32  tab_g_c3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_d0:6;
        RBus_UInt32  tab_g_d1:6;
        RBus_UInt32  tab_g_d2:6;
        RBus_UInt32  tab_g_d3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_e0:6;
        RBus_UInt32  tab_g_e1:6;
        RBus_UInt32  tab_g_e2:6;
        RBus_UInt32  tab_g_e3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_g_f0:6;
        RBus_UInt32  tab_g_f1:6;
        RBus_UInt32  tab_g_f2:6;
        RBus_UInt32  tab_g_f3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_green_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_00:6;
        RBus_UInt32  tab_b_01:6;
        RBus_UInt32  tab_b_02:6;
        RBus_UInt32  tab_b_03:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_10:6;
        RBus_UInt32  tab_b_11:6;
        RBus_UInt32  tab_b_12:6;
        RBus_UInt32  tab_b_13:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_20:6;
        RBus_UInt32  tab_b_21:6;
        RBus_UInt32  tab_b_22:6;
        RBus_UInt32  tab_b_23:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_30:6;
        RBus_UInt32  tab_b_31:6;
        RBus_UInt32  tab_b_32:6;
        RBus_UInt32  tab_b_33:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_40:6;
        RBus_UInt32  tab_b_41:6;
        RBus_UInt32  tab_b_42:6;
        RBus_UInt32  tab_b_43:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_50:6;
        RBus_UInt32  tab_b_51:6;
        RBus_UInt32  tab_b_52:6;
        RBus_UInt32  tab_b_53:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_60:6;
        RBus_UInt32  tab_b_61:6;
        RBus_UInt32  tab_b_62:6;
        RBus_UInt32  tab_b_63:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_70:6;
        RBus_UInt32  tab_b_71:6;
        RBus_UInt32  tab_b_72:6;
        RBus_UInt32  tab_b_73:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_80:6;
        RBus_UInt32  tab_b_81:6;
        RBus_UInt32  tab_b_82:6;
        RBus_UInt32  tab_b_83:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_90:6;
        RBus_UInt32  tab_b_91:6;
        RBus_UInt32  tab_b_92:6;
        RBus_UInt32  tab_b_93:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_a0:6;
        RBus_UInt32  tab_b_a1:6;
        RBus_UInt32  tab_b_a2:6;
        RBus_UInt32  tab_b_a3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_b0:6;
        RBus_UInt32  tab_b_b1:6;
        RBus_UInt32  tab_b_b2:6;
        RBus_UInt32  tab_b_b3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_c0:6;
        RBus_UInt32  tab_b_c1:6;
        RBus_UInt32  tab_b_c2:6;
        RBus_UInt32  tab_b_c3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_d0:6;
        RBus_UInt32  tab_b_d1:6;
        RBus_UInt32  tab_b_d2:6;
        RBus_UInt32  tab_b_d3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_e0:6;
        RBus_UInt32  tab_b_e1:6;
        RBus_UInt32  tab_b_e2:6;
        RBus_UInt32  tab_b_e3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab_b_f0:6;
        RBus_UInt32  tab_b_f1:6;
        RBus_UInt32  tab_b_f2:6;
        RBus_UInt32  tab_b_f3:6;
        RBus_UInt32  res1:8;
    };
}dither_dithering_dither_table_blue_0f_RBUS;

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
}dither_temporal_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dither_crc_start:1;
        RBus_UInt32  dither_crc_conti:1;
        RBus_UInt32  res1:30;
    };
}dither_dither_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_crc_result:32;
    };
}dither_dither_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_0:4;
        RBus_UInt32  seq_r_1:4;
        RBus_UInt32  seq_r_2:4;
        RBus_UInt32  seq_r_3:4;
        RBus_UInt32  seq_r_4:4;
        RBus_UInt32  seq_r_5:4;
        RBus_UInt32  seq_r_6:4;
        RBus_UInt32  seq_r_7:4;
    };
}dither_dithering_2nd_sequence_table_red_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_8:4;
        RBus_UInt32  seq_r_9:4;
        RBus_UInt32  seq_r_10:4;
        RBus_UInt32  seq_r_11:4;
        RBus_UInt32  seq_r_12:4;
        RBus_UInt32  seq_r_13:4;
        RBus_UInt32  seq_r_14:4;
        RBus_UInt32  seq_r_15:4;
    };
}dither_dithering_2nd_sequence_table_red_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_16:4;
        RBus_UInt32  seq_r_17:4;
        RBus_UInt32  seq_r_18:4;
        RBus_UInt32  seq_r_19:4;
        RBus_UInt32  seq_r_20:4;
        RBus_UInt32  seq_r_21:4;
        RBus_UInt32  seq_r_22:4;
        RBus_UInt32  seq_r_23:4;
    };
}dither_dithering_2nd_sequence_table_red_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_r_24:4;
        RBus_UInt32  seq_r_25:4;
        RBus_UInt32  seq_r_26:4;
        RBus_UInt32  seq_r_27:4;
        RBus_UInt32  seq_r_28:4;
        RBus_UInt32  seq_r_29:4;
        RBus_UInt32  seq_r_30:4;
        RBus_UInt32  seq_r_31:4;
    };
}dither_dithering_2nd_sequence_table_red_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_0:4;
        RBus_UInt32  seq_g_1:4;
        RBus_UInt32  seq_g_2:4;
        RBus_UInt32  seq_g_3:4;
        RBus_UInt32  seq_g_4:4;
        RBus_UInt32  seq_g_5:4;
        RBus_UInt32  seq_g_6:4;
        RBus_UInt32  seq_g_7:4;
    };
}dither_dithering_2nd_sequence_table_green_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_8:4;
        RBus_UInt32  seq_g_9:4;
        RBus_UInt32  seq_g_10:4;
        RBus_UInt32  seq_g_11:4;
        RBus_UInt32  seq_g_12:4;
        RBus_UInt32  seq_g_13:4;
        RBus_UInt32  seq_g_14:4;
        RBus_UInt32  seq_g_15:4;
    };
}dither_dithering_2nd_sequence_table_green_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_16:4;
        RBus_UInt32  seq_g_17:4;
        RBus_UInt32  seq_g_18:4;
        RBus_UInt32  seq_g_19:4;
        RBus_UInt32  seq_g_20:4;
        RBus_UInt32  seq_g_21:4;
        RBus_UInt32  seq_g_22:4;
        RBus_UInt32  seq_g_23:4;
    };
}dither_dithering_2nd_sequence_table_green_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_g_24:4;
        RBus_UInt32  seq_g_25:4;
        RBus_UInt32  seq_g_26:4;
        RBus_UInt32  seq_g_27:4;
        RBus_UInt32  seq_g_28:4;
        RBus_UInt32  seq_g_29:4;
        RBus_UInt32  seq_g_30:4;
        RBus_UInt32  seq_g_31:4;
    };
}dither_dithering_2nd_sequence_table_green_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_0:4;
        RBus_UInt32  seq_b_1:4;
        RBus_UInt32  seq_b_2:4;
        RBus_UInt32  seq_b_3:4;
        RBus_UInt32  seq_b_4:4;
        RBus_UInt32  seq_b_5:4;
        RBus_UInt32  seq_b_6:4;
        RBus_UInt32  seq_b_7:4;
    };
}dither_dithering_2nd_sequence_table_blue_00_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_8:4;
        RBus_UInt32  seq_b_9:4;
        RBus_UInt32  seq_b_10:4;
        RBus_UInt32  seq_b_11:4;
        RBus_UInt32  seq_b_12:4;
        RBus_UInt32  seq_b_13:4;
        RBus_UInt32  seq_b_14:4;
        RBus_UInt32  seq_b_15:4;
    };
}dither_dithering_2nd_sequence_table_blue_08_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_16:4;
        RBus_UInt32  seq_b_17:4;
        RBus_UInt32  seq_b_18:4;
        RBus_UInt32  seq_b_19:4;
        RBus_UInt32  seq_b_20:4;
        RBus_UInt32  seq_b_21:4;
        RBus_UInt32  seq_b_22:4;
        RBus_UInt32  seq_b_23:4;
    };
}dither_dithering_2nd_sequence_table_blue_16_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_b_24:4;
        RBus_UInt32  seq_b_25:4;
        RBus_UInt32  seq_b_26:4;
        RBus_UInt32  seq_b_27:4;
        RBus_UInt32  seq_b_28:4;
        RBus_UInt32  seq_b_29:4;
        RBus_UInt32  seq_b_30:4;
        RBus_UInt32  seq_b_31:4;
    };
}dither_dithering_2nd_sequence_table_blue_24_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_count_by_3d_flag_en:1;
        RBus_UInt32  frame_count_by_3d_l_flag_inv:1;
        RBus_UInt32  res1:30;
    };
}dither_dithering_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dd_b_b2_type:2;
        RBus_UInt32  dd_b_b1_type:2;
        RBus_UInt32  dd_b_b0_type:2;
        RBus_UInt32  dd_b_1_th:12;
        RBus_UInt32  dd_b_0_th:12;
        RBus_UInt32  dd_en:1;
        RBus_UInt32  res1:1;
    };
}dither_dithering_dd_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dd_g_b2_type:2;
        RBus_UInt32  dd_g_b1_type:2;
        RBus_UInt32  dd_g_b0_type:2;
        RBus_UInt32  dd_g_1_th:12;
        RBus_UInt32  dd_g_0_th:12;
        RBus_UInt32  res1:2;
    };
}dither_dithering_dd_th_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dd_r_b2_type:2;
        RBus_UInt32  dd_r_b1_type:2;
        RBus_UInt32  dd_r_b0_type:2;
        RBus_UInt32  dd_r_1_th:12;
        RBus_UInt32  dd_r_0_th:12;
        RBus_UInt32  res1:2;
    };
}dither_dithering_dd_th_r_RBUS;




#endif 


#endif 
