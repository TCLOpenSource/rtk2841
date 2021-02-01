/**
* @file MacArthur5-DesignSpec-I-Domain_SD_Dither
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_HSD_DITHER_REG_H_
#define _RBUS_HSD_DITHER_REG_H_

#include "rbus_types.h"



//  HSD_DITHER Register Address
#define  HSD_DITHER_SD_Dither_CTRL1                                              0x18023600
#define  HSD_DITHER_SD_Dither_CTRL1_reg_addr                                     "0xB8023600"
#define  HSD_DITHER_SD_Dither_CTRL1_reg                                          0xB8023600
#define  HSD_DITHER_SD_Dither_CTRL1_inst_addr                                    "0x0000"
#define  set_HSD_DITHER_SD_Dither_CTRL1_reg(data)                                (*((volatile unsigned int*)HSD_DITHER_SD_Dither_CTRL1_reg)=data)
#define  get_HSD_DITHER_SD_Dither_CTRL1_reg                                      (*((volatile unsigned int*)HSD_DITHER_SD_Dither_CTRL1_reg))
#define  HSD_DITHER_SD_Dither_CTRL1_uv_disable_shift                             (14)
#define  HSD_DITHER_SD_Dither_CTRL1_frame_count_by_3d_l_flag_inv_shift           (13)
#define  HSD_DITHER_SD_Dither_CTRL1_frame_count_by_3d_flag_en_shift              (12)
#define  HSD_DITHER_SD_Dither_CTRL1_dummy_11_10_shift                            (10)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_field_odd_temporal_offset_select_shift   (9)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_field_even_temporal_offset_select_shift  (8)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_temporal_offset_separate_mode_shift      (7)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_dithering_table_select_shift             (5)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_temporal_enable_shift                    (4)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_value_sign_shift                         (3)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_dithering_mode_shift                     (2)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_v_modulation_shift                       (1)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_h_modulation_shift                       (0)
#define  HSD_DITHER_SD_Dither_CTRL1_uv_disable_mask                              (0x00004000)
#define  HSD_DITHER_SD_Dither_CTRL1_frame_count_by_3d_l_flag_inv_mask            (0x00002000)
#define  HSD_DITHER_SD_Dither_CTRL1_frame_count_by_3d_flag_en_mask               (0x00001000)
#define  HSD_DITHER_SD_Dither_CTRL1_dummy_11_10_mask                             (0x00000C00)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_field_odd_temporal_offset_select_mask    (0x00000200)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_field_even_temporal_offset_select_mask   (0x00000100)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_temporal_offset_separate_mode_mask       (0x00000080)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_dithering_table_select_mask              (0x00000060)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_temporal_enable_mask                     (0x00000010)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_value_sign_mask                          (0x00000008)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_dithering_mode_mask                      (0x00000004)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_v_modulation_mask                        (0x00000002)
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_h_modulation_mask                        (0x00000001)
#define  HSD_DITHER_SD_Dither_CTRL1_uv_disable(data)                             (0x00004000&((data)<<14))
#define  HSD_DITHER_SD_Dither_CTRL1_frame_count_by_3d_l_flag_inv(data)           (0x00002000&((data)<<13))
#define  HSD_DITHER_SD_Dither_CTRL1_frame_count_by_3d_flag_en(data)              (0x00001000&((data)<<12))
#define  HSD_DITHER_SD_Dither_CTRL1_dummy_11_10(data)                            (0x00000C00&((data)<<10))
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_field_odd_temporal_offset_select(data)   (0x00000200&((data)<<9))
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_field_even_temporal_offset_select(data)  (0x00000100&((data)<<8))
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_temporal_offset_separate_mode(data)      (0x00000080&((data)<<7))
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_dithering_table_select(data)             (0x00000060&((data)<<5))
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_temporal_enable(data)                    (0x00000010&((data)<<4))
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_value_sign(data)                         (0x00000008&((data)<<3))
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_dithering_mode(data)                     (0x00000004&((data)<<2))
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_v_modulation(data)                       (0x00000002&((data)<<1))
#define  HSD_DITHER_SD_Dither_CTRL1_ch1_h_modulation(data)                       (0x00000001&(data))
#define  HSD_DITHER_SD_Dither_CTRL1_get_uv_disable(data)                         ((0x00004000&(data))>>14)
#define  HSD_DITHER_SD_Dither_CTRL1_get_frame_count_by_3d_l_flag_inv(data)       ((0x00002000&(data))>>13)
#define  HSD_DITHER_SD_Dither_CTRL1_get_frame_count_by_3d_flag_en(data)          ((0x00001000&(data))>>12)
#define  HSD_DITHER_SD_Dither_CTRL1_get_dummy_11_10(data)                        ((0x00000C00&(data))>>10)
#define  HSD_DITHER_SD_Dither_CTRL1_get_ch1_field_odd_temporal_offset_select(data) ((0x00000200&(data))>>9)
#define  HSD_DITHER_SD_Dither_CTRL1_get_ch1_field_even_temporal_offset_select(data) ((0x00000100&(data))>>8)
#define  HSD_DITHER_SD_Dither_CTRL1_get_ch1_temporal_offset_separate_mode(data)  ((0x00000080&(data))>>7)
#define  HSD_DITHER_SD_Dither_CTRL1_get_ch1_dithering_table_select(data)         ((0x00000060&(data))>>5)
#define  HSD_DITHER_SD_Dither_CTRL1_get_ch1_temporal_enable(data)                ((0x00000010&(data))>>4)
#define  HSD_DITHER_SD_Dither_CTRL1_get_ch1_value_sign(data)                     ((0x00000008&(data))>>3)
#define  HSD_DITHER_SD_Dither_CTRL1_get_ch1_dithering_mode(data)                 ((0x00000004&(data))>>2)
#define  HSD_DITHER_SD_Dither_CTRL1_get_ch1_v_modulation(data)                   ((0x00000002&(data))>>1)
#define  HSD_DITHER_SD_Dither_CTRL1_get_ch1_h_modulation(data)                   (0x00000001&(data))

#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1                              0x18023604
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_reg_addr                     "0xB8023604"
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_reg                          0xB8023604
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_inst_addr                    "0x0001"
#define  set_HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_reg(data)                (*((volatile unsigned int*)HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_reg)=data)
#define  get_HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_reg                      (*((volatile unsigned int*)HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_reg))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_15_shift         (30)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_14_shift         (28)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_13_shift         (26)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_12_shift         (24)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_11_shift         (22)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_10_shift         (20)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_9_shift          (18)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_8_shift          (16)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_7_shift          (14)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_6_shift          (12)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_5_shift          (10)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_4_shift          (8)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_3_shift          (6)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_2_shift          (4)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_1_shift          (2)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_0_shift          (0)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_15_mask          (0xC0000000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_14_mask          (0x30000000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_13_mask          (0x0C000000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_12_mask          (0x03000000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_11_mask          (0x00C00000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_10_mask          (0x00300000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_9_mask           (0x000C0000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_8_mask           (0x00030000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_7_mask           (0x0000C000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_6_mask           (0x00003000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_5_mask           (0x00000C00)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_4_mask           (0x00000300)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_3_mask           (0x000000C0)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_2_mask           (0x00000030)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_1_mask           (0x0000000C)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_0_mask           (0x00000003)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_15(data)         (0xC0000000&((data)<<30))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_14(data)         (0x30000000&((data)<<28))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_13(data)         (0x0C000000&((data)<<26))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_12(data)         (0x03000000&((data)<<24))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_11(data)         (0x00C00000&((data)<<22))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_10(data)         (0x00300000&((data)<<20))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_9(data)          (0x000C0000&((data)<<18))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_8(data)          (0x00030000&((data)<<16))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_7(data)          (0x0000C000&((data)<<14))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_6(data)          (0x00003000&((data)<<12))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_5(data)          (0x00000C00&((data)<<10))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_4(data)          (0x00000300&((data)<<8))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_3(data)          (0x000000C0&((data)<<6))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_2(data)          (0x00000030&((data)<<4))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_1(data)          (0x0000000C&((data)<<2))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_temp_offset_0(data)          (0x00000003&(data))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_15(data)     ((0xC0000000&(data))>>30)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_14(data)     ((0x30000000&(data))>>28)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_13(data)     ((0x0C000000&(data))>>26)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_12(data)     ((0x03000000&(data))>>24)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_11(data)     ((0x00C00000&(data))>>22)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_10(data)     ((0x00300000&(data))>>20)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_9(data)      ((0x000C0000&(data))>>18)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_8(data)      ((0x00030000&(data))>>16)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_7(data)      ((0x0000C000&(data))>>14)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_6(data)      ((0x00003000&(data))>>12)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_5(data)      ((0x00000C00&(data))>>10)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_4(data)      ((0x00000300&(data))>>8)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_3(data)      ((0x000000C0&(data))>>6)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_2(data)      ((0x00000030&(data))>>4)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_1(data)      ((0x0000000C&(data))>>2)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_1_get_temp_offset_0(data)      (0x00000003&(data))

#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2                              0x18023608
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_reg_addr                     "0xB8023608"
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_reg                          0xB8023608
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_inst_addr                    "0x0002"
#define  set_HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_reg(data)                (*((volatile unsigned int*)HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_reg)=data)
#define  get_HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_reg                      (*((volatile unsigned int*)HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_reg))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_15_shift         (30)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_14_shift         (28)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_13_shift         (26)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_12_shift         (24)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_11_shift         (22)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_10_shift         (20)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_9_shift          (18)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_8_shift          (16)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_7_shift          (14)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_6_shift          (12)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_5_shift          (10)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_4_shift          (8)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_3_shift          (6)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_2_shift          (4)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_1_shift          (2)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_0_shift          (0)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_15_mask          (0xC0000000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_14_mask          (0x30000000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_13_mask          (0x0C000000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_12_mask          (0x03000000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_11_mask          (0x00C00000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_10_mask          (0x00300000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_9_mask           (0x000C0000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_8_mask           (0x00030000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_7_mask           (0x0000C000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_6_mask           (0x00003000)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_5_mask           (0x00000C00)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_4_mask           (0x00000300)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_3_mask           (0x000000C0)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_2_mask           (0x00000030)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_1_mask           (0x0000000C)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_0_mask           (0x00000003)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_15(data)         (0xC0000000&((data)<<30))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_14(data)         (0x30000000&((data)<<28))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_13(data)         (0x0C000000&((data)<<26))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_12(data)         (0x03000000&((data)<<24))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_11(data)         (0x00C00000&((data)<<22))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_10(data)         (0x00300000&((data)<<20))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_9(data)          (0x000C0000&((data)<<18))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_8(data)          (0x00030000&((data)<<16))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_7(data)          (0x0000C000&((data)<<14))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_6(data)          (0x00003000&((data)<<12))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_5(data)          (0x00000C00&((data)<<10))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_4(data)          (0x00000300&((data)<<8))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_3(data)          (0x000000C0&((data)<<6))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_2(data)          (0x00000030&((data)<<4))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_1(data)          (0x0000000C&((data)<<2))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_temp_offset_0(data)          (0x00000003&(data))
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_15(data)     ((0xC0000000&(data))>>30)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_14(data)     ((0x30000000&(data))>>28)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_13(data)     ((0x0C000000&(data))>>26)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_12(data)     ((0x03000000&(data))>>24)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_11(data)     ((0x00C00000&(data))>>22)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_10(data)     ((0x00300000&(data))>>20)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_9(data)      ((0x000C0000&(data))>>18)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_8(data)      ((0x00030000&(data))>>16)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_7(data)      ((0x0000C000&(data))>>14)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_6(data)      ((0x00003000&(data))>>12)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_5(data)      ((0x00000C00&(data))>>10)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_4(data)      ((0x00000300&(data))>>8)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_3(data)      ((0x000000C0&(data))>>6)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_2(data)      ((0x00000030&(data))>>4)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_1(data)      ((0x0000000C&(data))>>2)
#define  HSD_DITHER_SD_Dither_Temporal_offset_Tab_2_get_temp_offset_0(data)      (0x00000003&(data))

#define  HSD_DITHER_DI_HSD_Ctrl0                                                 0x1802360C
#define  HSD_DITHER_DI_HSD_Ctrl0_reg_addr                                        "0xB802360C"
#define  HSD_DITHER_DI_HSD_Ctrl0_reg                                             0xB802360C
#define  HSD_DITHER_DI_HSD_Ctrl0_inst_addr                                       "0x0003"
#define  set_HSD_DITHER_DI_HSD_Ctrl0_reg(data)                                   (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Ctrl0_reg)=data)
#define  get_HSD_DITHER_DI_HSD_Ctrl0_reg                                         (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Ctrl0_reg))
#define  HSD_DITHER_DI_HSD_Ctrl0_h_3d_sel_en_shift                               (3)
#define  HSD_DITHER_DI_HSD_Ctrl0_h_y_table_sel_shift                             (2)
#define  HSD_DITHER_DI_HSD_Ctrl0_h_c_table_sel_shift                             (1)
#define  HSD_DITHER_DI_HSD_Ctrl0_h_zoom_en_shift                                 (0)
#define  HSD_DITHER_DI_HSD_Ctrl0_h_3d_sel_en_mask                                (0x00000008)
#define  HSD_DITHER_DI_HSD_Ctrl0_h_y_table_sel_mask                              (0x00000004)
#define  HSD_DITHER_DI_HSD_Ctrl0_h_c_table_sel_mask                              (0x00000002)
#define  HSD_DITHER_DI_HSD_Ctrl0_h_zoom_en_mask                                  (0x00000001)
#define  HSD_DITHER_DI_HSD_Ctrl0_h_3d_sel_en(data)                               (0x00000008&((data)<<3))
#define  HSD_DITHER_DI_HSD_Ctrl0_h_y_table_sel(data)                             (0x00000004&((data)<<2))
#define  HSD_DITHER_DI_HSD_Ctrl0_h_c_table_sel(data)                             (0x00000002&((data)<<1))
#define  HSD_DITHER_DI_HSD_Ctrl0_h_zoom_en(data)                                 (0x00000001&(data))
#define  HSD_DITHER_DI_HSD_Ctrl0_get_h_3d_sel_en(data)                           ((0x00000008&(data))>>3)
#define  HSD_DITHER_DI_HSD_Ctrl0_get_h_y_table_sel(data)                         ((0x00000004&(data))>>2)
#define  HSD_DITHER_DI_HSD_Ctrl0_get_h_c_table_sel(data)                         ((0x00000002&(data))>>1)
#define  HSD_DITHER_DI_HSD_Ctrl0_get_h_zoom_en(data)                             (0x00000001&(data))

#define  HSD_DITHER_DI_HSD_Scale_Hor_Factor                                      0x18023610
#define  HSD_DITHER_DI_HSD_Scale_Hor_Factor_reg_addr                             "0xB8023610"
#define  HSD_DITHER_DI_HSD_Scale_Hor_Factor_reg                                  0xB8023610
#define  HSD_DITHER_DI_HSD_Scale_Hor_Factor_inst_addr                            "0x0004"
#define  set_HSD_DITHER_DI_HSD_Scale_Hor_Factor_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Scale_Hor_Factor_reg)=data)
#define  get_HSD_DITHER_DI_HSD_Scale_Hor_Factor_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Scale_Hor_Factor_reg))
#define  HSD_DITHER_DI_HSD_Scale_Hor_Factor_hor_fac_shift                        (0)
#define  HSD_DITHER_DI_HSD_Scale_Hor_Factor_hor_fac_mask                         (0x01FFFFFF)
#define  HSD_DITHER_DI_HSD_Scale_Hor_Factor_hor_fac(data)                        (0x01FFFFFF&(data))
#define  HSD_DITHER_DI_HSD_Scale_Hor_Factor_get_hor_fac(data)                    (0x01FFFFFF&(data))

#define  HSD_DITHER_DI_HSD_Initial_Value                                         0x18023614
#define  HSD_DITHER_DI_HSD_Initial_Value_reg_addr                                "0xB8023614"
#define  HSD_DITHER_DI_HSD_Initial_Value_reg                                     0xB8023614
#define  HSD_DITHER_DI_HSD_Initial_Value_inst_addr                               "0x0005"
#define  set_HSD_DITHER_DI_HSD_Initial_Value_reg(data)                           (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Initial_Value_reg)=data)
#define  get_HSD_DITHER_DI_HSD_Initial_Value_reg                                 (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Initial_Value_reg))
#define  HSD_DITHER_DI_HSD_Initial_Value_hor_ini_l_shift                         (8)
#define  HSD_DITHER_DI_HSD_Initial_Value_hor_ini_shift                           (0)
#define  HSD_DITHER_DI_HSD_Initial_Value_hor_ini_l_mask                          (0x0000FF00)
#define  HSD_DITHER_DI_HSD_Initial_Value_hor_ini_mask                            (0x000000FF)
#define  HSD_DITHER_DI_HSD_Initial_Value_hor_ini_l(data)                         (0x0000FF00&((data)<<8))
#define  HSD_DITHER_DI_HSD_Initial_Value_hor_ini(data)                           (0x000000FF&(data))
#define  HSD_DITHER_DI_HSD_Initial_Value_get_hor_ini_l(data)                     ((0x0000FF00&(data))>>8)
#define  HSD_DITHER_DI_HSD_Initial_Value_get_hor_ini(data)                       (0x000000FF&(data))

#define  HSD_DITHER_DI_HSD_Hor_Delta1                                            0x18023618
#define  HSD_DITHER_DI_HSD_Hor_Delta1_reg_addr                                   "0xB8023618"
#define  HSD_DITHER_DI_HSD_Hor_Delta1_reg                                        0xB8023618
#define  HSD_DITHER_DI_HSD_Hor_Delta1_inst_addr                                  "0x0006"
#define  set_HSD_DITHER_DI_HSD_Hor_Delta1_reg(data)                              (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Hor_Delta1_reg)=data)
#define  get_HSD_DITHER_DI_HSD_Hor_Delta1_reg                                    (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Hor_Delta1_reg))
#define  HSD_DITHER_DI_HSD_Hor_Delta1_nl_d1_shift                                (0)
#define  HSD_DITHER_DI_HSD_Hor_Delta1_nl_d1_mask                                 (0x00003FFF)
#define  HSD_DITHER_DI_HSD_Hor_Delta1_nl_d1(data)                                (0x00003FFF&(data))
#define  HSD_DITHER_DI_HSD_Hor_Delta1_get_nl_d1(data)                            (0x00003FFF&(data))

#define  HSD_DITHER_DI_HSD_Hor_Segment                                           0x1802361C
#define  HSD_DITHER_DI_HSD_Hor_Segment_reg_addr                                  "0xB802361C"
#define  HSD_DITHER_DI_HSD_Hor_Segment_reg                                       0xB802361C
#define  HSD_DITHER_DI_HSD_Hor_Segment_inst_addr                                 "0x0007"
#define  set_HSD_DITHER_DI_HSD_Hor_Segment_reg(data)                             (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Hor_Segment_reg)=data)
#define  get_HSD_DITHER_DI_HSD_Hor_Segment_reg                                   (*((volatile unsigned int*)HSD_DITHER_DI_HSD_Hor_Segment_reg))
#define  HSD_DITHER_DI_HSD_Hor_Segment_nl_seg1_shift                             (16)
#define  HSD_DITHER_DI_HSD_Hor_Segment_nl_seg2_shift                             (0)
#define  HSD_DITHER_DI_HSD_Hor_Segment_nl_seg1_mask                              (0x0FFF0000)
#define  HSD_DITHER_DI_HSD_Hor_Segment_nl_seg2_mask                              (0x00000FFF)
#define  HSD_DITHER_DI_HSD_Hor_Segment_nl_seg1(data)                             (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_HSD_Hor_Segment_nl_seg2(data)                             (0x00000FFF&(data))
#define  HSD_DITHER_DI_HSD_Hor_Segment_get_nl_seg1(data)                         ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_HSD_Hor_Segment_get_nl_seg2(data)                         (0x00000FFF&(data))

#define  HSD_DITHER_DI_HSD_CRC_CTRL                                              0x18023620
#define  HSD_DITHER_DI_HSD_CRC_CTRL_reg_addr                                     "0xB8023620"
#define  HSD_DITHER_DI_HSD_CRC_CTRL_reg                                          0xB8023620
#define  HSD_DITHER_DI_HSD_CRC_CTRL_inst_addr                                    "0x0008"
#define  set_HSD_DITHER_DI_HSD_CRC_CTRL_reg(data)                                (*((volatile unsigned int*)HSD_DITHER_DI_HSD_CRC_CTRL_reg)=data)
#define  get_HSD_DITHER_DI_HSD_CRC_CTRL_reg                                      (*((volatile unsigned int*)HSD_DITHER_DI_HSD_CRC_CTRL_reg))
#define  HSD_DITHER_DI_HSD_CRC_CTRL_crc_3d_en_shift                              (4)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_r_auto_cmp_en_shift                          (3)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_l_auto_cmp_en_shift                          (2)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_ch1_hsd_crc_conti_shift                      (1)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_ch1_hsd_crc_start_shift                      (0)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_crc_3d_en_mask                               (0x00000010)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_r_auto_cmp_en_mask                           (0x00000008)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_l_auto_cmp_en_mask                           (0x00000004)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_ch1_hsd_crc_conti_mask                       (0x00000002)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_ch1_hsd_crc_start_mask                       (0x00000001)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_crc_3d_en(data)                              (0x00000010&((data)<<4))
#define  HSD_DITHER_DI_HSD_CRC_CTRL_r_auto_cmp_en(data)                          (0x00000008&((data)<<3))
#define  HSD_DITHER_DI_HSD_CRC_CTRL_l_auto_cmp_en(data)                          (0x00000004&((data)<<2))
#define  HSD_DITHER_DI_HSD_CRC_CTRL_ch1_hsd_crc_conti(data)                      (0x00000002&((data)<<1))
#define  HSD_DITHER_DI_HSD_CRC_CTRL_ch1_hsd_crc_start(data)                      (0x00000001&(data))
#define  HSD_DITHER_DI_HSD_CRC_CTRL_get_crc_3d_en(data)                          ((0x00000010&(data))>>4)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_get_r_auto_cmp_en(data)                      ((0x00000008&(data))>>3)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_get_l_auto_cmp_en(data)                      ((0x00000004&(data))>>2)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_get_ch1_hsd_crc_conti(data)                  ((0x00000002&(data))>>1)
#define  HSD_DITHER_DI_HSD_CRC_CTRL_get_ch1_hsd_crc_start(data)                  (0x00000001&(data))

#define  HSD_DITHER_DI_HSD_CRC_Result_left                                       0x18023624
#define  HSD_DITHER_DI_HSD_CRC_Result_left_reg_addr                              "0xB8023624"
#define  HSD_DITHER_DI_HSD_CRC_Result_left_reg                                   0xB8023624
#define  HSD_DITHER_DI_HSD_CRC_Result_left_inst_addr                             "0x0009"
#define  set_HSD_DITHER_DI_HSD_CRC_Result_left_reg(data)                         (*((volatile unsigned int*)HSD_DITHER_DI_HSD_CRC_Result_left_reg)=data)
#define  get_HSD_DITHER_DI_HSD_CRC_Result_left_reg                               (*((volatile unsigned int*)HSD_DITHER_DI_HSD_CRC_Result_left_reg))
#define  HSD_DITHER_DI_HSD_CRC_Result_left_ch1_hsd_crc_l_result_shift            (0)
#define  HSD_DITHER_DI_HSD_CRC_Result_left_ch1_hsd_crc_l_result_mask             (0xFFFFFFFF)
#define  HSD_DITHER_DI_HSD_CRC_Result_left_ch1_hsd_crc_l_result(data)            (0xFFFFFFFF&(data))
#define  HSD_DITHER_DI_HSD_CRC_Result_left_get_ch1_hsd_crc_l_result(data)        (0xFFFFFFFF&(data))

#define  HSD_DITHER_DI_HSD_CRC_Result                                            0x18023628
#define  HSD_DITHER_DI_HSD_CRC_Result_reg_addr                                   "0xB8023628"
#define  HSD_DITHER_DI_HSD_CRC_Result_reg                                        0xB8023628
#define  HSD_DITHER_DI_HSD_CRC_Result_inst_addr                                  "0x000A"
#define  set_HSD_DITHER_DI_HSD_CRC_Result_reg(data)                              (*((volatile unsigned int*)HSD_DITHER_DI_HSD_CRC_Result_reg)=data)
#define  get_HSD_DITHER_DI_HSD_CRC_Result_reg                                    (*((volatile unsigned int*)HSD_DITHER_DI_HSD_CRC_Result_reg))
#define  HSD_DITHER_DI_HSD_CRC_Result_ch1_hsd_crc_r_result_shift                 (0)
#define  HSD_DITHER_DI_HSD_CRC_Result_ch1_hsd_crc_r_result_mask                  (0xFFFFFFFF)
#define  HSD_DITHER_DI_HSD_CRC_Result_ch1_hsd_crc_r_result(data)                 (0xFFFFFFFF&(data))
#define  HSD_DITHER_DI_HSD_CRC_Result_get_ch1_hsd_crc_r_result(data)             (0xFFFFFFFF&(data))

#define  HSD_DITHER_DI_HSD_L_DES_CRC                                             0x1802362C
#define  HSD_DITHER_DI_HSD_L_DES_CRC_reg_addr                                    "0xB802362C"
#define  HSD_DITHER_DI_HSD_L_DES_CRC_reg                                         0xB802362C
#define  HSD_DITHER_DI_HSD_L_DES_CRC_inst_addr                                   "0x000B"
#define  set_HSD_DITHER_DI_HSD_L_DES_CRC_reg(data)                               (*((volatile unsigned int*)HSD_DITHER_DI_HSD_L_DES_CRC_reg)=data)
#define  get_HSD_DITHER_DI_HSD_L_DES_CRC_reg                                     (*((volatile unsigned int*)HSD_DITHER_DI_HSD_L_DES_CRC_reg))
#define  HSD_DITHER_DI_HSD_L_DES_CRC_l_des_crc_shift                             (0)
#define  HSD_DITHER_DI_HSD_L_DES_CRC_l_des_crc_mask                              (0xFFFFFFFF)
#define  HSD_DITHER_DI_HSD_L_DES_CRC_l_des_crc(data)                             (0xFFFFFFFF&(data))
#define  HSD_DITHER_DI_HSD_L_DES_CRC_get_l_des_crc(data)                         (0xFFFFFFFF&(data))

#define  HSD_DITHER_DI_HSD_R_DES_CRC                                             0x18023630
#define  HSD_DITHER_DI_HSD_R_DES_CRC_reg_addr                                    "0xB8023630"
#define  HSD_DITHER_DI_HSD_R_DES_CRC_reg                                         0xB8023630
#define  HSD_DITHER_DI_HSD_R_DES_CRC_inst_addr                                   "0x000C"
#define  set_HSD_DITHER_DI_HSD_R_DES_CRC_reg(data)                               (*((volatile unsigned int*)HSD_DITHER_DI_HSD_R_DES_CRC_reg)=data)
#define  get_HSD_DITHER_DI_HSD_R_DES_CRC_reg                                     (*((volatile unsigned int*)HSD_DITHER_DI_HSD_R_DES_CRC_reg))
#define  HSD_DITHER_DI_HSD_R_DES_CRC_r_des_crc_shift                             (0)
#define  HSD_DITHER_DI_HSD_R_DES_CRC_r_des_crc_mask                              (0xFFFFFFFF)
#define  HSD_DITHER_DI_HSD_R_DES_CRC_r_des_crc(data)                             (0xFFFFFFFF&(data))
#define  HSD_DITHER_DI_HSD_R_DES_CRC_get_r_des_crc(data)                         (0xFFFFFFFF&(data))

#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT                                           0x18023634
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_reg_addr                                  "0xB8023634"
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_reg                                       0xB8023634
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_inst_addr                                 "0x000D"
#define  set_HSD_DITHER_DI_HSD_CRC_ERR_CNT_reg(data)                             (*((volatile unsigned int*)HSD_DITHER_DI_HSD_CRC_ERR_CNT_reg)=data)
#define  get_HSD_DITHER_DI_HSD_CRC_ERR_CNT_reg                                   (*((volatile unsigned int*)HSD_DITHER_DI_HSD_CRC_ERR_CNT_reg))
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_r_crc_err_cnt_shift                       (16)
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_l_crc_err_cnt_shift                       (0)
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_r_crc_err_cnt_mask                        (0xFFFF0000)
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_l_crc_err_cnt_mask                        (0x0000FFFF)
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_r_crc_err_cnt(data)                       (0xFFFF0000&((data)<<16))
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_l_crc_err_cnt(data)                       (0x0000FFFF&(data))
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_get_r_crc_err_cnt(data)                   ((0xFFFF0000&(data))>>16)
#define  HSD_DITHER_DI_HSD_CRC_ERR_CNT_get_l_crc_err_cnt(data)                   (0x0000FFFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0                                      0x18023638
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_reg_addr                             "0xB8023638"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_reg                                  0xB8023638
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_inst_addr                            "0x000E"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_tab1_c0_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_tab1_c1_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_tab1_c0_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_tab1_c1_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_tab1_c0(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_tab1_c1(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_get_tab1_c0(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C0_get_tab1_c1(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2                                      0x1802363C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_reg_addr                             "0xB802363C"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_reg                                  0xB802363C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_inst_addr                            "0x000F"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_tab1_c2_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_tab1_c3_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_tab1_c2_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_tab1_c3_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_tab1_c2(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_tab1_c3(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_get_tab1_c2(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C2_get_tab1_c3(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4                                      0x18023640
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_reg_addr                             "0xB8023640"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_reg                                  0xB8023640
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_inst_addr                            "0x0010"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_tab1_c4_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_tab1_c5_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_tab1_c4_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_tab1_c5_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_tab1_c4(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_tab1_c5(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_get_tab1_c4(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C4_get_tab1_c5(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6                                      0x18023644
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_reg_addr                             "0xB8023644"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_reg                                  0xB8023644
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_inst_addr                            "0x0011"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_tab1_c6_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_tab1_c7_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_tab1_c6_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_tab1_c7_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_tab1_c6(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_tab1_c7(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_get_tab1_c6(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C6_get_tab1_c7(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8                                      0x18023648
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_reg_addr                             "0xB8023648"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_reg                                  0xB8023648
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_inst_addr                            "0x0012"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_tab1_c8_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_tab1_c9_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_tab1_c8_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_tab1_c9_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_tab1_c8(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_tab1_c9(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_get_tab1_c8(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C8_get_tab1_c9(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10                                     0x1802364C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_reg_addr                            "0xB802364C"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_reg                                 0xB802364C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_inst_addr                           "0x0013"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_tab1_c10_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_tab1_c11_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_tab1_c10_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_tab1_c11_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_tab1_c10(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_tab1_c11(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_get_tab1_c10(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C10_get_tab1_c11(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12                                     0x18023650
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_reg_addr                            "0xB8023650"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_reg                                 0xB8023650
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_inst_addr                           "0x0014"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_tab1_c12_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_tab1_c13_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_tab1_c12_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_tab1_c13_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_tab1_c12(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_tab1_c13(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_get_tab1_c12(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C12_get_tab1_c13(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14                                     0x18023654
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_reg_addr                            "0xB8023654"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_reg                                 0xB8023654
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_inst_addr                           "0x0015"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_tab1_c14_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_tab1_c15_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_tab1_c14_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_tab1_c15_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_tab1_c14(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_tab1_c15(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_get_tab1_c14(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C14_get_tab1_c15(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16                                     0x18023658
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_reg_addr                            "0xB8023658"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_reg                                 0xB8023658
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_inst_addr                           "0x0016"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_tab1_c16_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_tab1_c17_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_tab1_c16_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_tab1_c17_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_tab1_c16(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_tab1_c17(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_get_tab1_c16(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C16_get_tab1_c17(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18                                     0x1802365C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_reg_addr                            "0xB802365C"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_reg                                 0xB802365C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_inst_addr                           "0x0017"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_tab1_c18_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_tab1_c19_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_tab1_c18_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_tab1_c19_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_tab1_c18(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_tab1_c19(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_get_tab1_c18(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C18_get_tab1_c19(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20                                     0x18023660
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_reg_addr                            "0xB8023660"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_reg                                 0xB8023660
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_inst_addr                           "0x0018"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_tab1_c20_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_tab1_c21_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_tab1_c20_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_tab1_c21_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_tab1_c20(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_tab1_c21(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_get_tab1_c20(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C20_get_tab1_c21(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22                                     0x18023664
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_reg_addr                            "0xB8023664"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_reg                                 0xB8023664
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_inst_addr                           "0x0019"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_tab1_c22_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_tab1_c23_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_tab1_c22_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_tab1_c23_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_tab1_c22(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_tab1_c23(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_get_tab1_c22(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C22_get_tab1_c23(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24                                     0x18023668
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_reg_addr                            "0xB8023668"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_reg                                 0xB8023668
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_inst_addr                           "0x001A"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_tab1_c24_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_tab1_c25_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_tab1_c24_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_tab1_c25_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_tab1_c24(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_tab1_c25(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_get_tab1_c24(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C24_get_tab1_c25(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26                                     0x1802366C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_reg_addr                            "0xB802366C"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_reg                                 0xB802366C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_inst_addr                           "0x001B"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_tab1_c26_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_tab1_c27_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_tab1_c26_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_tab1_c27_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_tab1_c26(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_tab1_c27(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_get_tab1_c26(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C26_get_tab1_c27(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28                                     0x18023670
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_reg_addr                            "0xB8023670"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_reg                                 0xB8023670
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_inst_addr                           "0x001C"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_tab1_c28_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_tab1_c29_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_tab1_c28_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_tab1_c29_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_tab1_c28(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_tab1_c29(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_get_tab1_c28(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C28_get_tab1_c29(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30                                     0x18023674
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_reg_addr                            "0xB8023674"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_reg                                 0xB8023674
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_inst_addr                           "0x001D"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_tab1_c30_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_tab1_c31_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_tab1_c30_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_tab1_c31_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_tab1_c30(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_tab1_c31(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_get_tab1_c30(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab1_C30_get_tab1_c31(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0                                      0x18023678
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_reg_addr                             "0xB8023678"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_reg                                  0xB8023678
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_inst_addr                            "0x001E"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_tab2_c0_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_tab2_c1_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_tab2_c0_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_tab2_c1_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_tab2_c0(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_tab2_c1(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_get_tab2_c0(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C0_get_tab2_c1(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2                                      0x1802367C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_reg_addr                             "0xB802367C"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_reg                                  0xB802367C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_inst_addr                            "0x001F"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_tab2_c2_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_tab2_c3_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_tab2_c2_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_tab2_c3_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_tab2_c2(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_tab2_c3(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_get_tab2_c2(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C2_get_tab2_c3(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4                                      0x18023680
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_reg_addr                             "0xB8023680"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_reg                                  0xB8023680
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_inst_addr                            "0x0020"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_tab2_c4_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_tab2_c5_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_tab2_c4_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_tab2_c5_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_tab2_c4(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_tab2_c5(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_get_tab2_c4(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C4_get_tab2_c5(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6                                      0x18023684
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_reg_addr                             "0xB8023684"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_reg                                  0xB8023684
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_inst_addr                            "0x0021"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_tab2_c6_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_tab2_c7_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_tab2_c6_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_tab2_c7_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_tab2_c6(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_tab2_c7(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_get_tab2_c6(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C6_get_tab2_c7(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8                                      0x18023688
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_reg_addr                             "0xB8023688"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_reg                                  0xB8023688
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_inst_addr                            "0x0022"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_reg(data)                        (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_reg                              (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_tab2_c8_shift                        (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_tab2_c9_shift                        (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_tab2_c8_mask                         (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_tab2_c9_mask                         (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_tab2_c8(data)                        (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_tab2_c9(data)                        (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_get_tab2_c8(data)                    ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C8_get_tab2_c9(data)                    (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10                                     0x1802368C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_reg_addr                            "0xB802368C"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_reg                                 0xB802368C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_inst_addr                           "0x0023"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_tab2_c10_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_tab2_c11_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_tab2_c10_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_tab2_c11_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_tab2_c10(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_tab2_c11(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_get_tab2_c10(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C10_get_tab2_c11(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12                                     0x18023690
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_reg_addr                            "0xB8023690"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_reg                                 0xB8023690
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_inst_addr                           "0x0024"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_tab2_c12_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_tab2_c13_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_tab2_c12_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_tab2_c13_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_tab2_c12(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_tab2_c13(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_get_tab2_c12(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C12_get_tab2_c13(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14                                     0x18023694
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_reg_addr                            "0xB8023694"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_reg                                 0xB8023694
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_inst_addr                           "0x0025"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_tab2_c14_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_tab2_c15_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_tab2_c14_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_tab2_c15_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_tab2_c14(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_tab2_c15(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_get_tab2_c14(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C14_get_tab2_c15(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16                                     0x18023698
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_reg_addr                            "0xB8023698"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_reg                                 0xB8023698
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_inst_addr                           "0x0026"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_tab2_c16_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_tab2_c17_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_tab2_c16_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_tab2_c17_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_tab2_c16(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_tab2_c17(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_get_tab2_c16(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C16_get_tab2_c17(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18                                     0x1802369C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_reg_addr                            "0xB802369C"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_reg                                 0xB802369C
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_inst_addr                           "0x0027"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_tab2_c18_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_tab2_c19_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_tab2_c18_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_tab2_c19_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_tab2_c18(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_tab2_c19(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_get_tab2_c18(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C18_get_tab2_c19(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20                                     0x180236A0
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_reg_addr                            "0xB80236A0"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_reg                                 0xB80236A0
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_inst_addr                           "0x0028"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_tab2_c20_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_tab2_c21_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_tab2_c20_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_tab2_c21_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_tab2_c20(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_tab2_c21(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_get_tab2_c20(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C20_get_tab2_c21(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22                                     0x180236A4
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_reg_addr                            "0xB80236A4"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_reg                                 0xB80236A4
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_inst_addr                           "0x0029"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_tab2_c22_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_tab2_c23_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_tab2_c22_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_tab2_c23_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_tab2_c22(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_tab2_c23(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_get_tab2_c22(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C22_get_tab2_c23(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24                                     0x180236A8
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_reg_addr                            "0xB80236A8"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_reg                                 0xB80236A8
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_inst_addr                           "0x002A"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_tab2_c24_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_tab2_c25_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_tab2_c24_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_tab2_c25_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_tab2_c24(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_tab2_c25(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_get_tab2_c24(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C24_get_tab2_c25(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26                                     0x180236AC
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_reg_addr                            "0xB80236AC"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_reg                                 0xB80236AC
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_inst_addr                           "0x002B"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_tab2_c26_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_tab2_c27_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_tab2_c26_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_tab2_c27_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_tab2_c26(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_tab2_c27(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_get_tab2_c26(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C26_get_tab2_c27(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28                                     0x180236B0
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_reg_addr                            "0xB80236B0"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_reg                                 0xB80236B0
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_inst_addr                           "0x002C"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_tab2_c28_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_tab2_c29_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_tab2_c28_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_tab2_c29_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_tab2_c28(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_tab2_c29(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_get_tab2_c28(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C28_get_tab2_c29(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30                                     0x180236B4
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_reg_addr                            "0xB80236B4"
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_reg                                 0xB80236B4
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_inst_addr                           "0x002D"
#define  set_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_reg(data)                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_reg)=data)
#define  get_HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_reg                             (*((volatile unsigned int*)HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_reg))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_tab2_c30_shift                      (16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_tab2_c31_shift                      (0)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_tab2_c30_mask                       (0x0FFF0000)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_tab2_c31_mask                       (0x00000FFF)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_tab2_c30(data)                      (0x0FFF0000&((data)<<16))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_tab2_c31(data)                      (0x00000FFF&(data))
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_get_tab2_c30(data)                  ((0x0FFF0000&(data))>>16)
#define  HSD_DITHER_DI_UZD_FIR_Coef_Tab2_C30_get_tab2_c31(data)                  (0x00000FFF&(data))

#define  HSD_DITHER_DI_UZD_DB_CTRL                                               0x180236B8
#define  HSD_DITHER_DI_UZD_DB_CTRL_reg_addr                                      "0xB80236B8"
#define  HSD_DITHER_DI_UZD_DB_CTRL_reg                                           0xB80236B8
#define  HSD_DITHER_DI_UZD_DB_CTRL_inst_addr                                     "0x002E"
#define  set_HSD_DITHER_DI_UZD_DB_CTRL_reg(data)                                 (*((volatile unsigned int*)HSD_DITHER_DI_UZD_DB_CTRL_reg)=data)
#define  get_HSD_DITHER_DI_UZD_DB_CTRL_reg                                       (*((volatile unsigned int*)HSD_DITHER_DI_UZD_DB_CTRL_reg))
#define  HSD_DITHER_DI_UZD_DB_CTRL_h_db_apply_shift                              (6)
#define  HSD_DITHER_DI_UZD_DB_CTRL_h_db_rd_sel_shift                             (5)
#define  HSD_DITHER_DI_UZD_DB_CTRL_h_db_en_shift                                 (4)
#define  HSD_DITHER_DI_UZD_DB_CTRL_h_db_apply_mask                               (0x00000040)
#define  HSD_DITHER_DI_UZD_DB_CTRL_h_db_rd_sel_mask                              (0x00000020)
#define  HSD_DITHER_DI_UZD_DB_CTRL_h_db_en_mask                                  (0x00000010)
#define  HSD_DITHER_DI_UZD_DB_CTRL_h_db_apply(data)                              (0x00000040&((data)<<6))
#define  HSD_DITHER_DI_UZD_DB_CTRL_h_db_rd_sel(data)                             (0x00000020&((data)<<5))
#define  HSD_DITHER_DI_UZD_DB_CTRL_h_db_en(data)                                 (0x00000010&((data)<<4))
#define  HSD_DITHER_DI_UZD_DB_CTRL_get_h_db_apply(data)                          ((0x00000040&(data))>>6)
#define  HSD_DITHER_DI_UZD_DB_CTRL_get_h_db_rd_sel(data)                         ((0x00000020&(data))>>5)
#define  HSD_DITHER_DI_UZD_DB_CTRL_get_h_db_en(data)                             ((0x00000010&(data))>>4)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======HSD_DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  uv_disable:1;
        RBus_UInt32  frame_count_by_3d_l_flag_inv:1;
        RBus_UInt32  frame_count_by_3d_flag_en:1;
        RBus_UInt32  dummy18023600_11_10:2;
        RBus_UInt32  ch1_field_odd_temporal_offset_select:1;
        RBus_UInt32  ch1_field_even_temporal_offset_select:1;
        RBus_UInt32  ch1_temporal_offset_separate_mode:1;
        RBus_UInt32  ch1_dithering_table_select:2;
        RBus_UInt32  ch1_temporal_enable:1;
        RBus_UInt32  ch1_value_sign:1;
        RBus_UInt32  ch1_dithering_mode:1;
        RBus_UInt32  ch1_v_modulation:1;
        RBus_UInt32  ch1_h_modulation:1;
    };
}hsd_dither_sd_dither_ctrl1_RBUS;

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
}hsd_dither_sd_dither_temporal_offset_tab_1_RBUS;

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
}hsd_dither_sd_dither_temporal_offset_tab_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  h_3d_sel_en:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_zoom_en:1;
    };
}hsd_dither_di_hsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hor_fac:25;
    };
}hsd_dither_di_hsd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  hor_ini:8;
    };
}hsd_dither_di_hsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  nl_d1:14;
    };
}hsd_dither_di_hsd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  nl_seg1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  nl_seg2:12;
    };
}hsd_dither_di_hsd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  ch1_hsd_crc_conti:1;
        RBus_UInt32  ch1_hsd_crc_start:1;
    };
}hsd_dither_di_hsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_l_result:32;
    };
}hsd_dither_di_hsd_crc_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_r_result:32;
    };
}hsd_dither_di_hsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}hsd_dither_di_hsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}hsd_dither_di_hsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_err_cnt:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}hsd_dither_di_hsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c1:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c3:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c5:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c7:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c9:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c11:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c13:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c15:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c17:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c19:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c21:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c23:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c25:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c27:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c29:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c31:12;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c1:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c3:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c5:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c7:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c9:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c11:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c13:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c15:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c17:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c19:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c21:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c23:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c25:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c27:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c29:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c31:12;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_db_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======HSD_DITHER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_h_modulation:1;
        RBus_UInt32  ch1_v_modulation:1;
        RBus_UInt32  ch1_dithering_mode:1;
        RBus_UInt32  ch1_value_sign:1;
        RBus_UInt32  ch1_temporal_enable:1;
        RBus_UInt32  ch1_dithering_table_select:2;
        RBus_UInt32  ch1_temporal_offset_separate_mode:1;
        RBus_UInt32  ch1_field_even_temporal_offset_select:1;
        RBus_UInt32  ch1_field_odd_temporal_offset_select:1;
        RBus_UInt32  dummy18023600_11_10:2;
        RBus_UInt32  frame_count_by_3d_flag_en:1;
        RBus_UInt32  frame_count_by_3d_l_flag_inv:1;
        RBus_UInt32  uv_disable:1;
        RBus_UInt32  res1:17;
    };
}hsd_dither_sd_dither_ctrl1_RBUS;

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
}hsd_dither_sd_dither_temporal_offset_tab_1_RBUS;

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
}hsd_dither_sd_dither_temporal_offset_tab_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_3d_sel_en:1;
        RBus_UInt32  res1:28;
    };
}hsd_dither_di_hsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_fac:25;
        RBus_UInt32  res1:7;
    };
}hsd_dither_di_hsd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  res1:16;
    };
}hsd_dither_di_hsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_d1:14;
        RBus_UInt32  res1:18;
    };
}hsd_dither_di_hsd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_seg2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  nl_seg1:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_hsd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_start:1;
        RBus_UInt32  ch1_hsd_crc_conti:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  res1:27;
    };
}hsd_dither_di_hsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_l_result:32;
    };
}hsd_dither_di_hsd_crc_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_r_result:32;
    };
}hsd_dither_di_hsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}hsd_dither_di_hsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}hsd_dither_di_hsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  r_crc_err_cnt:16;
    };
}hsd_dither_di_hsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
    };
}hsd_dither_di_uzd_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  res2:25;
    };
}hsd_dither_di_uzd_db_ctrl_RBUS;




#endif 


#endif 
