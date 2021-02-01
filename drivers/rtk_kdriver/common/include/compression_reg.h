/**
* @file rbusCompressionReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COMPRESSION_REG_H_
#define _RBUS_COMPRESSION_REG_H_

#include "rbus_types.h"



//  COMPRESSION Register Address
#define  COMPRESSION_cmp_resolution                                              0x18021D00
#define  COMPRESSION_cmp_resolution_reg_addr                                     "0xB8021D00"
#define  COMPRESSION_cmp_resolution_reg                                          0xB8021D00
#define  COMPRESSION_cmp_resolution_inst_addr                                    "0x0000"
#define  set_COMPRESSION_cmp_resolution_reg(data)                                (*((volatile unsigned int*)COMPRESSION_cmp_resolution_reg)=data)
#define  get_COMPRESSION_cmp_resolution_reg                                      (*((volatile unsigned int*)COMPRESSION_cmp_resolution_reg))
#define  COMPRESSION_cmp_resolution_cmp_segment_shift                            (24)
#define  COMPRESSION_cmp_resolution_cmp_width_shift                              (16)
#define  COMPRESSION_cmp_resolution_cmp_height_shift                             (0)
#define  COMPRESSION_cmp_resolution_cmp_segment_mask                             (0x03000000)
#define  COMPRESSION_cmp_resolution_cmp_width_mask                               (0x00FF0000)
#define  COMPRESSION_cmp_resolution_cmp_height_mask                              (0x0000FFFF)
#define  COMPRESSION_cmp_resolution_cmp_segment(data)                            (0x03000000&((data)<<24))
#define  COMPRESSION_cmp_resolution_cmp_width(data)                              (0x00FF0000&((data)<<16))
#define  COMPRESSION_cmp_resolution_cmp_height(data)                             (0x0000FFFF&(data))
#define  COMPRESSION_cmp_resolution_get_cmp_segment(data)                        ((0x03000000&(data))>>24)
#define  COMPRESSION_cmp_resolution_get_cmp_width(data)                          ((0x00FF0000&(data))>>16)
#define  COMPRESSION_cmp_resolution_get_cmp_height(data)                         (0x0000FFFF&(data))

#define  COMPRESSION_comp_setting                                                0x18021D04
#define  COMPRESSION_comp_setting_reg_addr                                       "0xB8021D04"
#define  COMPRESSION_comp_setting_reg                                            0xB8021D04
#define  COMPRESSION_comp_setting_inst_addr                                      "0x0001"
#define  set_COMPRESSION_comp_setting_reg(data)                                  (*((volatile unsigned int*)COMPRESSION_comp_setting_reg)=data)
#define  get_COMPRESSION_comp_setting_reg                                        (*((volatile unsigned int*)COMPRESSION_comp_setting_reg))
#define  COMPRESSION_comp_setting_cmp_a_ch_mark_shift                            (31)
#define  COMPRESSION_comp_setting_cmp_444to422_en_shift                          (30)
#define  COMPRESSION_comp_setting_cmp_rgb_yc_sel_shift                           (29)
#define  COMPRESSION_comp_setting_cmp_channel_bits_shift                         (28)
#define  COMPRESSION_comp_setting_max_pixel_bits_shift                           (12)
#define  COMPRESSION_comp_setting_short_term_bits_shift                          (6)
#define  COMPRESSION_comp_setting_frame_bits_shift                               (0)
#define  COMPRESSION_comp_setting_cmp_a_ch_mark_mask                             (0x80000000)
#define  COMPRESSION_comp_setting_cmp_444to422_en_mask                           (0x40000000)
#define  COMPRESSION_comp_setting_cmp_rgb_yc_sel_mask                            (0x20000000)
#define  COMPRESSION_comp_setting_cmp_channel_bits_mask                          (0x10000000)
#define  COMPRESSION_comp_setting_max_pixel_bits_mask                            (0x0003F000)
#define  COMPRESSION_comp_setting_short_term_bits_mask                           (0x00000FC0)
#define  COMPRESSION_comp_setting_frame_bits_mask                                (0x0000003F)
#define  COMPRESSION_comp_setting_cmp_a_ch_mark(data)                            (0x80000000&((data)<<31))
#define  COMPRESSION_comp_setting_cmp_444to422_en(data)                          (0x40000000&((data)<<30))
#define  COMPRESSION_comp_setting_cmp_rgb_yc_sel(data)                           (0x20000000&((data)<<29))
#define  COMPRESSION_comp_setting_cmp_channel_bits(data)                         (0x10000000&((data)<<28))
#define  COMPRESSION_comp_setting_max_pixel_bits(data)                           (0x0003F000&((data)<<12))
#define  COMPRESSION_comp_setting_short_term_bits(data)                          (0x00000FC0&((data)<<6))
#define  COMPRESSION_comp_setting_frame_bits(data)                               (0x0000003F&(data))
#define  COMPRESSION_comp_setting_get_cmp_a_ch_mark(data)                        ((0x80000000&(data))>>31)
#define  COMPRESSION_comp_setting_get_cmp_444to422_en(data)                      ((0x40000000&(data))>>30)
#define  COMPRESSION_comp_setting_get_cmp_rgb_yc_sel(data)                       ((0x20000000&(data))>>29)
#define  COMPRESSION_comp_setting_get_cmp_channel_bits(data)                     ((0x10000000&(data))>>28)
#define  COMPRESSION_comp_setting_get_max_pixel_bits(data)                       ((0x0003F000&(data))>>12)
#define  COMPRESSION_comp_setting_get_short_term_bits(data)                      ((0x00000FC0&(data))>>6)
#define  COMPRESSION_comp_setting_get_frame_bits(data)                           (0x0000003F&(data))

#define  COMPRESSION_threshold                                                   0x18021D08
#define  COMPRESSION_threshold_reg_addr                                          "0xB8021D08"
#define  COMPRESSION_threshold_reg                                               0xB8021D08
#define  COMPRESSION_threshold_inst_addr                                         "0x0002"
#define  set_COMPRESSION_threshold_reg(data)                                     (*((volatile unsigned int*)COMPRESSION_threshold_reg)=data)
#define  get_COMPRESSION_threshold_reg                                           (*((volatile unsigned int*)COMPRESSION_threshold_reg))
#define  COMPRESSION_threshold_delta_down_shift                                  (8)
#define  COMPRESSION_threshold_delta_up_shift                                    (0)
#define  COMPRESSION_threshold_delta_down_mask                                   (0x0000FF00)
#define  COMPRESSION_threshold_delta_up_mask                                     (0x000000FF)
#define  COMPRESSION_threshold_delta_down(data)                                  (0x0000FF00&((data)<<8))
#define  COMPRESSION_threshold_delta_up(data)                                    (0x000000FF&(data))
#define  COMPRESSION_threshold_get_delta_down(data)                              ((0x0000FF00&(data))>>8)
#define  COMPRESSION_threshold_get_delta_up(data)                                (0x000000FF&(data))

#define  COMPRESSION_compress_irq_en                                             0x18021D0C
#define  COMPRESSION_compress_irq_en_reg_addr                                    "0xB8021D0C"
#define  COMPRESSION_compress_irq_en_reg                                         0xB8021D0C
#define  COMPRESSION_compress_irq_en_inst_addr                                   "0x0003"
#define  set_COMPRESSION_compress_irq_en_reg(data)                               (*((volatile unsigned int*)COMPRESSION_compress_irq_en_reg)=data)
#define  get_COMPRESSION_compress_irq_en_reg                                     (*((volatile unsigned int*)COMPRESSION_compress_irq_en_reg))
#define  COMPRESSION_compress_irq_en_not_segement_status_clr_shift               (5)
#define  COMPRESSION_compress_irq_en_pixel_num_status_clr_shift                  (4)
#define  COMPRESSION_compress_irq_en_over_bits_status_clr_shift                  (3)
#define  COMPRESSION_compress_irq_en_comp_irq_en_shift                           (0)
#define  COMPRESSION_compress_irq_en_not_segement_status_clr_mask                (0x00000020)
#define  COMPRESSION_compress_irq_en_pixel_num_status_clr_mask                   (0x00000010)
#define  COMPRESSION_compress_irq_en_over_bits_status_clr_mask                   (0x00000008)
#define  COMPRESSION_compress_irq_en_comp_irq_en_mask                            (0x00000007)
#define  COMPRESSION_compress_irq_en_not_segement_status_clr(data)               (0x00000020&((data)<<5))
#define  COMPRESSION_compress_irq_en_pixel_num_status_clr(data)                  (0x00000010&((data)<<4))
#define  COMPRESSION_compress_irq_en_over_bits_status_clr(data)                  (0x00000008&((data)<<3))
#define  COMPRESSION_compress_irq_en_comp_irq_en(data)                           (0x00000007&(data))
#define  COMPRESSION_compress_irq_en_get_not_segement_status_clr(data)           ((0x00000020&(data))>>5)
#define  COMPRESSION_compress_irq_en_get_pixel_num_status_clr(data)              ((0x00000010&(data))>>4)
#define  COMPRESSION_compress_irq_en_get_over_bits_status_clr(data)              ((0x00000008&(data))>>3)
#define  COMPRESSION_compress_irq_en_get_comp_irq_en(data)                       (0x00000007&(data))

#define  COMPRESSION_compress_status                                             0x18021D10
#define  COMPRESSION_compress_status_reg_addr                                    "0xB8021D10"
#define  COMPRESSION_compress_status_reg                                         0xB8021D10
#define  COMPRESSION_compress_status_inst_addr                                   "0x0004"
#define  set_COMPRESSION_compress_status_reg(data)                               (*((volatile unsigned int*)COMPRESSION_compress_status_reg)=data)
#define  get_COMPRESSION_compress_status_reg                                     (*((volatile unsigned int*)COMPRESSION_compress_status_reg))
#define  COMPRESSION_compress_status_comp_irq_shift                              (3)
#define  COMPRESSION_compress_status_comp_status_shift                           (0)
#define  COMPRESSION_compress_status_comp_irq_mask                               (0x00000008)
#define  COMPRESSION_compress_status_comp_status_mask                            (0x00000007)
#define  COMPRESSION_compress_status_comp_irq(data)                              (0x00000008&((data)<<3))
#define  COMPRESSION_compress_status_comp_status(data)                           (0x00000007&(data))
#define  COMPRESSION_compress_status_get_comp_irq(data)                          ((0x00000008&(data))>>3)
#define  COMPRESSION_compress_status_get_comp_status(data)                       (0x00000007&(data))

#define  COMPRESSION_decmp_resolution                                            0x18021D14
#define  COMPRESSION_decmp_resolution_reg_addr                                   "0xB8021D14"
#define  COMPRESSION_decmp_resolution_reg                                        0xB8021D14
#define  COMPRESSION_decmp_resolution_inst_addr                                  "0x0005"
#define  set_COMPRESSION_decmp_resolution_reg(data)                              (*((volatile unsigned int*)COMPRESSION_decmp_resolution_reg)=data)
#define  get_COMPRESSION_decmp_resolution_reg                                    (*((volatile unsigned int*)COMPRESSION_decmp_resolution_reg))
#define  COMPRESSION_decmp_resolution_decmp_segment_shift                        (24)
#define  COMPRESSION_decmp_resolution_decmp_width_shift                          (16)
#define  COMPRESSION_decmp_resolution_decmp_height_shift                         (0)
#define  COMPRESSION_decmp_resolution_decmp_segment_mask                         (0x03000000)
#define  COMPRESSION_decmp_resolution_decmp_width_mask                           (0x00FF0000)
#define  COMPRESSION_decmp_resolution_decmp_height_mask                          (0x0000FFFF)
#define  COMPRESSION_decmp_resolution_decmp_segment(data)                        (0x03000000&((data)<<24))
#define  COMPRESSION_decmp_resolution_decmp_width(data)                          (0x00FF0000&((data)<<16))
#define  COMPRESSION_decmp_resolution_decmp_height(data)                         (0x0000FFFF&(data))
#define  COMPRESSION_decmp_resolution_get_decmp_segment(data)                    ((0x03000000&(data))>>24)
#define  COMPRESSION_decmp_resolution_get_decmp_width(data)                      ((0x00FF0000&(data))>>16)
#define  COMPRESSION_decmp_resolution_get_decmp_height(data)                     (0x0000FFFF&(data))

#define  COMPRESSION_decomp_setting                                              0x18021D18
#define  COMPRESSION_decomp_setting_reg_addr                                     "0xB8021D18"
#define  COMPRESSION_decomp_setting_reg                                          0xB8021D18
#define  COMPRESSION_decomp_setting_inst_addr                                    "0x0006"
#define  set_COMPRESSION_decomp_setting_reg(data)                                (*((volatile unsigned int*)COMPRESSION_decomp_setting_reg)=data)
#define  get_COMPRESSION_decomp_setting_reg                                      (*((volatile unsigned int*)COMPRESSION_decomp_setting_reg))
#define  COMPRESSION_decomp_setting_a_sat_en_shift                               (17)
#define  COMPRESSION_decomp_setting_b_cb_sat_en_shift                            (16)
#define  COMPRESSION_decomp_setting_g_y_sat_en_shift                             (15)
#define  COMPRESSION_decomp_setting_r_cr_sat_en_shift                            (14)
#define  COMPRESSION_decomp_setting_decmp_frame_bits_shift                       (8)
#define  COMPRESSION_decomp_setting_decmp_a_ch_mark_shift                        (5)
#define  COMPRESSION_decomp_setting_decmp_444to422_en_shift                      (4)
#define  COMPRESSION_decomp_setting_decmp_rgb_yc_sel_shift                       (3)
#define  COMPRESSION_decomp_setting_decmp_channel_bits_shift                     (2)
#define  COMPRESSION_decomp_setting_decmp_cbcr_recov_shift                       (1)
#define  COMPRESSION_decomp_setting_decmp_fl_mode_shift                          (0)
#define  COMPRESSION_decomp_setting_a_sat_en_mask                                (0x00020000)
#define  COMPRESSION_decomp_setting_b_cb_sat_en_mask                             (0x00010000)
#define  COMPRESSION_decomp_setting_g_y_sat_en_mask                              (0x00008000)
#define  COMPRESSION_decomp_setting_r_cr_sat_en_mask                             (0x00004000)
#define  COMPRESSION_decomp_setting_decmp_frame_bits_mask                        (0x00003F00)
#define  COMPRESSION_decomp_setting_decmp_a_ch_mark_mask                         (0x00000020)
#define  COMPRESSION_decomp_setting_decmp_444to422_en_mask                       (0x00000010)
#define  COMPRESSION_decomp_setting_decmp_rgb_yc_sel_mask                        (0x00000008)
#define  COMPRESSION_decomp_setting_decmp_channel_bits_mask                      (0x00000004)
#define  COMPRESSION_decomp_setting_decmp_cbcr_recov_mask                        (0x00000002)
#define  COMPRESSION_decomp_setting_decmp_fl_mode_mask                           (0x00000001)
#define  COMPRESSION_decomp_setting_a_sat_en(data)                               (0x00020000&((data)<<17))
#define  COMPRESSION_decomp_setting_b_cb_sat_en(data)                            (0x00010000&((data)<<16))
#define  COMPRESSION_decomp_setting_g_y_sat_en(data)                             (0x00008000&((data)<<15))
#define  COMPRESSION_decomp_setting_r_cr_sat_en(data)                            (0x00004000&((data)<<14))
#define  COMPRESSION_decomp_setting_decmp_frame_bits(data)                       (0x00003F00&((data)<<8))
#define  COMPRESSION_decomp_setting_decmp_a_ch_mark(data)                        (0x00000020&((data)<<5))
#define  COMPRESSION_decomp_setting_decmp_444to422_en(data)                      (0x00000010&((data)<<4))
#define  COMPRESSION_decomp_setting_decmp_rgb_yc_sel(data)                       (0x00000008&((data)<<3))
#define  COMPRESSION_decomp_setting_decmp_channel_bits(data)                     (0x00000004&((data)<<2))
#define  COMPRESSION_decomp_setting_decmp_cbcr_recov(data)                       (0x00000002&((data)<<1))
#define  COMPRESSION_decomp_setting_decmp_fl_mode(data)                          (0x00000001&(data))
#define  COMPRESSION_decomp_setting_get_a_sat_en(data)                           ((0x00020000&(data))>>17)
#define  COMPRESSION_decomp_setting_get_b_cb_sat_en(data)                        ((0x00010000&(data))>>16)
#define  COMPRESSION_decomp_setting_get_g_y_sat_en(data)                         ((0x00008000&(data))>>15)
#define  COMPRESSION_decomp_setting_get_r_cr_sat_en(data)                        ((0x00004000&(data))>>14)
#define  COMPRESSION_decomp_setting_get_decmp_frame_bits(data)                   ((0x00003F00&(data))>>8)
#define  COMPRESSION_decomp_setting_get_decmp_a_ch_mark(data)                    ((0x00000020&(data))>>5)
#define  COMPRESSION_decomp_setting_get_decmp_444to422_en(data)                  ((0x00000010&(data))>>4)
#define  COMPRESSION_decomp_setting_get_decmp_rgb_yc_sel(data)                   ((0x00000008&(data))>>3)
#define  COMPRESSION_decomp_setting_get_decmp_channel_bits(data)                 ((0x00000004&(data))>>2)
#define  COMPRESSION_decomp_setting_get_decmp_cbcr_recov(data)                   ((0x00000002&(data))>>1)
#define  COMPRESSION_decomp_setting_get_decmp_fl_mode(data)                      (0x00000001&(data))

#define  COMPRESSION_trunc_mark                                                  0x18021D1C
#define  COMPRESSION_trunc_mark_reg_addr                                         "0xB8021D1C"
#define  COMPRESSION_trunc_mark_reg                                              0xB8021D1C
#define  COMPRESSION_trunc_mark_inst_addr                                        "0x0007"
#define  set_COMPRESSION_trunc_mark_reg(data)                                    (*((volatile unsigned int*)COMPRESSION_trunc_mark_reg)=data)
#define  get_COMPRESSION_trunc_mark_reg                                          (*((volatile unsigned int*)COMPRESSION_trunc_mark_reg))
#define  COMPRESSION_trunc_mark_mark_en_9_shift                                  (9)
#define  COMPRESSION_trunc_mark_mark_en_8_shift                                  (8)
#define  COMPRESSION_trunc_mark_mark_en_7_shift                                  (7)
#define  COMPRESSION_trunc_mark_mark_en_6_shift                                  (6)
#define  COMPRESSION_trunc_mark_mark_en_5_shift                                  (5)
#define  COMPRESSION_trunc_mark_mark_en_4_shift                                  (4)
#define  COMPRESSION_trunc_mark_mark_en_3_shift                                  (3)
#define  COMPRESSION_trunc_mark_mark_en_2_shift                                  (2)
#define  COMPRESSION_trunc_mark_mark_en_1_shift                                  (1)
#define  COMPRESSION_trunc_mark_mark_en_0_shift                                  (0)
#define  COMPRESSION_trunc_mark_mark_en_9_mask                                   (0x00000200)
#define  COMPRESSION_trunc_mark_mark_en_8_mask                                   (0x00000100)
#define  COMPRESSION_trunc_mark_mark_en_7_mask                                   (0x00000080)
#define  COMPRESSION_trunc_mark_mark_en_6_mask                                   (0x00000040)
#define  COMPRESSION_trunc_mark_mark_en_5_mask                                   (0x00000020)
#define  COMPRESSION_trunc_mark_mark_en_4_mask                                   (0x00000010)
#define  COMPRESSION_trunc_mark_mark_en_3_mask                                   (0x00000008)
#define  COMPRESSION_trunc_mark_mark_en_2_mask                                   (0x00000004)
#define  COMPRESSION_trunc_mark_mark_en_1_mask                                   (0x00000002)
#define  COMPRESSION_trunc_mark_mark_en_0_mask                                   (0x00000001)
#define  COMPRESSION_trunc_mark_mark_en_9(data)                                  (0x00000200&((data)<<9))
#define  COMPRESSION_trunc_mark_mark_en_8(data)                                  (0x00000100&((data)<<8))
#define  COMPRESSION_trunc_mark_mark_en_7(data)                                  (0x00000080&((data)<<7))
#define  COMPRESSION_trunc_mark_mark_en_6(data)                                  (0x00000040&((data)<<6))
#define  COMPRESSION_trunc_mark_mark_en_5(data)                                  (0x00000020&((data)<<5))
#define  COMPRESSION_trunc_mark_mark_en_4(data)                                  (0x00000010&((data)<<4))
#define  COMPRESSION_trunc_mark_mark_en_3(data)                                  (0x00000008&((data)<<3))
#define  COMPRESSION_trunc_mark_mark_en_2(data)                                  (0x00000004&((data)<<2))
#define  COMPRESSION_trunc_mark_mark_en_1(data)                                  (0x00000002&((data)<<1))
#define  COMPRESSION_trunc_mark_mark_en_0(data)                                  (0x00000001&(data))
#define  COMPRESSION_trunc_mark_get_mark_en_9(data)                              ((0x00000200&(data))>>9)
#define  COMPRESSION_trunc_mark_get_mark_en_8(data)                              ((0x00000100&(data))>>8)
#define  COMPRESSION_trunc_mark_get_mark_en_7(data)                              ((0x00000080&(data))>>7)
#define  COMPRESSION_trunc_mark_get_mark_en_6(data)                              ((0x00000040&(data))>>6)
#define  COMPRESSION_trunc_mark_get_mark_en_5(data)                              ((0x00000020&(data))>>5)
#define  COMPRESSION_trunc_mark_get_mark_en_4(data)                              ((0x00000010&(data))>>4)
#define  COMPRESSION_trunc_mark_get_mark_en_3(data)                              ((0x00000008&(data))>>3)
#define  COMPRESSION_trunc_mark_get_mark_en_2(data)                              ((0x00000004&(data))>>2)
#define  COMPRESSION_trunc_mark_get_mark_en_1(data)                              ((0x00000002&(data))>>1)
#define  COMPRESSION_trunc_mark_get_mark_en_0(data)                              (0x00000001&(data))

#define  COMPRESSION_trunc_color_0                                               0x18021D20
#define  COMPRESSION_trunc_color_0_reg_addr                                      "0xB8021D20"
#define  COMPRESSION_trunc_color_0_reg                                           0xB8021D20
#define  COMPRESSION_trunc_color_0_inst_addr                                     "0x0008"
#define  set_COMPRESSION_trunc_color_0_reg(data)                                 (*((volatile unsigned int*)COMPRESSION_trunc_color_0_reg)=data)
#define  get_COMPRESSION_trunc_color_0_reg                                       (*((volatile unsigned int*)COMPRESSION_trunc_color_0_reg))
#define  COMPRESSION_trunc_color_0_mark_color_0_shift                            (16)
#define  COMPRESSION_trunc_color_0_mark_color_1_shift                            (0)
#define  COMPRESSION_trunc_color_0_mark_color_0_mask                             (0xFFFF0000)
#define  COMPRESSION_trunc_color_0_mark_color_1_mask                             (0x0000FFFF)
#define  COMPRESSION_trunc_color_0_mark_color_0(data)                            (0xFFFF0000&((data)<<16))
#define  COMPRESSION_trunc_color_0_mark_color_1(data)                            (0x0000FFFF&(data))
#define  COMPRESSION_trunc_color_0_get_mark_color_0(data)                        ((0xFFFF0000&(data))>>16)
#define  COMPRESSION_trunc_color_0_get_mark_color_1(data)                        (0x0000FFFF&(data))

#define  COMPRESSION_trunc_color_1                                               0x18021D24
#define  COMPRESSION_trunc_color_1_reg_addr                                      "0xB8021D24"
#define  COMPRESSION_trunc_color_1_reg                                           0xB8021D24
#define  COMPRESSION_trunc_color_1_inst_addr                                     "0x0009"
#define  set_COMPRESSION_trunc_color_1_reg(data)                                 (*((volatile unsigned int*)COMPRESSION_trunc_color_1_reg)=data)
#define  get_COMPRESSION_trunc_color_1_reg                                       (*((volatile unsigned int*)COMPRESSION_trunc_color_1_reg))
#define  COMPRESSION_trunc_color_1_mark_color_2_shift                            (16)
#define  COMPRESSION_trunc_color_1_mark_color_3_shift                            (0)
#define  COMPRESSION_trunc_color_1_mark_color_2_mask                             (0xFFFF0000)
#define  COMPRESSION_trunc_color_1_mark_color_3_mask                             (0x0000FFFF)
#define  COMPRESSION_trunc_color_1_mark_color_2(data)                            (0xFFFF0000&((data)<<16))
#define  COMPRESSION_trunc_color_1_mark_color_3(data)                            (0x0000FFFF&(data))
#define  COMPRESSION_trunc_color_1_get_mark_color_2(data)                        ((0xFFFF0000&(data))>>16)
#define  COMPRESSION_trunc_color_1_get_mark_color_3(data)                        (0x0000FFFF&(data))

#define  COMPRESSION_trunc_color_2                                               0x18021D28
#define  COMPRESSION_trunc_color_2_reg_addr                                      "0xB8021D28"
#define  COMPRESSION_trunc_color_2_reg                                           0xB8021D28
#define  COMPRESSION_trunc_color_2_inst_addr                                     "0x000A"
#define  set_COMPRESSION_trunc_color_2_reg(data)                                 (*((volatile unsigned int*)COMPRESSION_trunc_color_2_reg)=data)
#define  get_COMPRESSION_trunc_color_2_reg                                       (*((volatile unsigned int*)COMPRESSION_trunc_color_2_reg))
#define  COMPRESSION_trunc_color_2_mark_color_4_shift                            (16)
#define  COMPRESSION_trunc_color_2_mark_color_5_shift                            (0)
#define  COMPRESSION_trunc_color_2_mark_color_4_mask                             (0xFFFF0000)
#define  COMPRESSION_trunc_color_2_mark_color_5_mask                             (0x0000FFFF)
#define  COMPRESSION_trunc_color_2_mark_color_4(data)                            (0xFFFF0000&((data)<<16))
#define  COMPRESSION_trunc_color_2_mark_color_5(data)                            (0x0000FFFF&(data))
#define  COMPRESSION_trunc_color_2_get_mark_color_4(data)                        ((0xFFFF0000&(data))>>16)
#define  COMPRESSION_trunc_color_2_get_mark_color_5(data)                        (0x0000FFFF&(data))

#define  COMPRESSION_trunc_color_3                                               0x18021D2C
#define  COMPRESSION_trunc_color_3_reg_addr                                      "0xB8021D2C"
#define  COMPRESSION_trunc_color_3_reg                                           0xB8021D2C
#define  COMPRESSION_trunc_color_3_inst_addr                                     "0x000B"
#define  set_COMPRESSION_trunc_color_3_reg(data)                                 (*((volatile unsigned int*)COMPRESSION_trunc_color_3_reg)=data)
#define  get_COMPRESSION_trunc_color_3_reg                                       (*((volatile unsigned int*)COMPRESSION_trunc_color_3_reg))
#define  COMPRESSION_trunc_color_3_mark_color_6_shift                            (16)
#define  COMPRESSION_trunc_color_3_mark_color_7_shift                            (0)
#define  COMPRESSION_trunc_color_3_mark_color_6_mask                             (0xFFFF0000)
#define  COMPRESSION_trunc_color_3_mark_color_7_mask                             (0x0000FFFF)
#define  COMPRESSION_trunc_color_3_mark_color_6(data)                            (0xFFFF0000&((data)<<16))
#define  COMPRESSION_trunc_color_3_mark_color_7(data)                            (0x0000FFFF&(data))
#define  COMPRESSION_trunc_color_3_get_mark_color_6(data)                        ((0xFFFF0000&(data))>>16)
#define  COMPRESSION_trunc_color_3_get_mark_color_7(data)                        (0x0000FFFF&(data))

#define  COMPRESSION_trunc_color_4                                               0x18021D30
#define  COMPRESSION_trunc_color_4_reg_addr                                      "0xB8021D30"
#define  COMPRESSION_trunc_color_4_reg                                           0xB8021D30
#define  COMPRESSION_trunc_color_4_inst_addr                                     "0x000C"
#define  set_COMPRESSION_trunc_color_4_reg(data)                                 (*((volatile unsigned int*)COMPRESSION_trunc_color_4_reg)=data)
#define  get_COMPRESSION_trunc_color_4_reg                                       (*((volatile unsigned int*)COMPRESSION_trunc_color_4_reg))
#define  COMPRESSION_trunc_color_4_mark_color_8_shift                            (16)
#define  COMPRESSION_trunc_color_4_mark_color_9_shift                            (0)
#define  COMPRESSION_trunc_color_4_mark_color_8_mask                             (0xFFFF0000)
#define  COMPRESSION_trunc_color_4_mark_color_9_mask                             (0x0000FFFF)
#define  COMPRESSION_trunc_color_4_mark_color_8(data)                            (0xFFFF0000&((data)<<16))
#define  COMPRESSION_trunc_color_4_mark_color_9(data)                            (0x0000FFFF&(data))
#define  COMPRESSION_trunc_color_4_get_mark_color_8(data)                        ((0xFFFF0000&(data))>>16)
#define  COMPRESSION_trunc_color_4_get_mark_color_9(data)                        (0x0000FFFF&(data))

#define  COMPRESSION_frame_inst                                                  0x18021D34
#define  COMPRESSION_frame_inst_reg_addr                                         "0xB8021D34"
#define  COMPRESSION_frame_inst_reg                                              0xB8021D34
#define  COMPRESSION_frame_inst_inst_addr                                        "0x000D"
#define  set_COMPRESSION_frame_inst_reg(data)                                    (*((volatile unsigned int*)COMPRESSION_frame_inst_reg)=data)
#define  get_COMPRESSION_frame_inst_reg                                          (*((volatile unsigned int*)COMPRESSION_frame_inst_reg))
#define  COMPRESSION_frame_inst_frm_cnt_3_shift                                  (28)
#define  COMPRESSION_frame_inst_frm_cnt_2_shift                                  (24)
#define  COMPRESSION_frame_inst_frm_cnt_1_shift                                  (20)
#define  COMPRESSION_frame_inst_frm_cnt_0_shift                                  (16)
#define  COMPRESSION_frame_inst_max_truncation_3_shift                           (12)
#define  COMPRESSION_frame_inst_max_truncation_2_shift                           (8)
#define  COMPRESSION_frame_inst_max_truncation_1_shift                           (4)
#define  COMPRESSION_frame_inst_max_truncation_0_shift                           (0)
#define  COMPRESSION_frame_inst_frm_cnt_3_mask                                   (0xF0000000)
#define  COMPRESSION_frame_inst_frm_cnt_2_mask                                   (0x0F000000)
#define  COMPRESSION_frame_inst_frm_cnt_1_mask                                   (0x00F00000)
#define  COMPRESSION_frame_inst_frm_cnt_0_mask                                   (0x000F0000)
#define  COMPRESSION_frame_inst_max_truncation_3_mask                            (0x0000F000)
#define  COMPRESSION_frame_inst_max_truncation_2_mask                            (0x00000F00)
#define  COMPRESSION_frame_inst_max_truncation_1_mask                            (0x000000F0)
#define  COMPRESSION_frame_inst_max_truncation_0_mask                            (0x0000000F)
#define  COMPRESSION_frame_inst_frm_cnt_3(data)                                  (0xF0000000&((data)<<28))
#define  COMPRESSION_frame_inst_frm_cnt_2(data)                                  (0x0F000000&((data)<<24))
#define  COMPRESSION_frame_inst_frm_cnt_1(data)                                  (0x00F00000&((data)<<20))
#define  COMPRESSION_frame_inst_frm_cnt_0(data)                                  (0x000F0000&((data)<<16))
#define  COMPRESSION_frame_inst_max_truncation_3(data)                           (0x0000F000&((data)<<12))
#define  COMPRESSION_frame_inst_max_truncation_2(data)                           (0x00000F00&((data)<<8))
#define  COMPRESSION_frame_inst_max_truncation_1(data)                           (0x000000F0&((data)<<4))
#define  COMPRESSION_frame_inst_max_truncation_0(data)                           (0x0000000F&(data))
#define  COMPRESSION_frame_inst_get_frm_cnt_3(data)                              ((0xF0000000&(data))>>28)
#define  COMPRESSION_frame_inst_get_frm_cnt_2(data)                              ((0x0F000000&(data))>>24)
#define  COMPRESSION_frame_inst_get_frm_cnt_1(data)                              ((0x00F00000&(data))>>20)
#define  COMPRESSION_frame_inst_get_frm_cnt_0(data)                              ((0x000F0000&(data))>>16)
#define  COMPRESSION_frame_inst_get_max_truncation_3(data)                       ((0x0000F000&(data))>>12)
#define  COMPRESSION_frame_inst_get_max_truncation_2(data)                       ((0x00000F00&(data))>>8)
#define  COMPRESSION_frame_inst_get_max_truncation_1(data)                       ((0x000000F0&(data))>>4)
#define  COMPRESSION_frame_inst_get_max_truncation_0(data)                       (0x0000000F&(data))

#define  COMPRESSION_decomp_irq_en                                               0x18021D38
#define  COMPRESSION_decomp_irq_en_reg_addr                                      "0xB8021D38"
#define  COMPRESSION_decomp_irq_en_reg                                           0xB8021D38
#define  COMPRESSION_decomp_irq_en_inst_addr                                     "0x000E"
#define  set_COMPRESSION_decomp_irq_en_reg(data)                                 (*((volatile unsigned int*)COMPRESSION_decomp_irq_en_reg)=data)
#define  get_COMPRESSION_decomp_irq_en_reg                                       (*((volatile unsigned int*)COMPRESSION_decomp_irq_en_reg))
#define  COMPRESSION_decomp_irq_en_dummy_31_10_shift                             (10)
#define  COMPRESSION_decomp_irq_en_head_error_clr_shift                          (9)
#define  COMPRESSION_decomp_irq_en_pix_fifo_underflow_clr_shift                  (8)
#define  COMPRESSION_decomp_irq_en_head_error_irq_en_shift                       (4)
#define  COMPRESSION_decomp_irq_en_underflow_irq_en_shift                        (0)
#define  COMPRESSION_decomp_irq_en_dummy_31_10_mask                              (0xFFFFFC00)
#define  COMPRESSION_decomp_irq_en_head_error_clr_mask                           (0x00000200)
#define  COMPRESSION_decomp_irq_en_pix_fifo_underflow_clr_mask                   (0x00000100)
#define  COMPRESSION_decomp_irq_en_head_error_irq_en_mask                        (0x000000F0)
#define  COMPRESSION_decomp_irq_en_underflow_irq_en_mask                         (0x0000000F)
#define  COMPRESSION_decomp_irq_en_dummy_31_10(data)                             (0xFFFFFC00&((data)<<10))
#define  COMPRESSION_decomp_irq_en_head_error_clr(data)                          (0x00000200&((data)<<9))
#define  COMPRESSION_decomp_irq_en_pix_fifo_underflow_clr(data)                  (0x00000100&((data)<<8))
#define  COMPRESSION_decomp_irq_en_head_error_irq_en(data)                       (0x000000F0&((data)<<4))
#define  COMPRESSION_decomp_irq_en_underflow_irq_en(data)                        (0x0000000F&(data))
#define  COMPRESSION_decomp_irq_en_get_dummy_31_10(data)                         ((0xFFFFFC00&(data))>>10)
#define  COMPRESSION_decomp_irq_en_get_head_error_clr(data)                      ((0x00000200&(data))>>9)
#define  COMPRESSION_decomp_irq_en_get_pix_fifo_underflow_clr(data)              ((0x00000100&(data))>>8)
#define  COMPRESSION_decomp_irq_en_get_head_error_irq_en(data)                   ((0x000000F0&(data))>>4)
#define  COMPRESSION_decomp_irq_en_get_underflow_irq_en(data)                    (0x0000000F&(data))

#define  COMPRESSION_decomp_status                                               0x18021D3C
#define  COMPRESSION_decomp_status_reg_addr                                      "0xB8021D3C"
#define  COMPRESSION_decomp_status_reg                                           0xB8021D3C
#define  COMPRESSION_decomp_status_inst_addr                                     "0x000F"
#define  set_COMPRESSION_decomp_status_reg(data)                                 (*((volatile unsigned int*)COMPRESSION_decomp_status_reg)=data)
#define  get_COMPRESSION_decomp_status_reg                                       (*((volatile unsigned int*)COMPRESSION_decomp_status_reg))
#define  COMPRESSION_decomp_status_dummy_31_9_shift                              (9)
#define  COMPRESSION_decomp_status_decomp_irq_shift                              (8)
#define  COMPRESSION_decomp_status_head_error_shift                              (4)
#define  COMPRESSION_decomp_status_pix_fifo_underflow_shift                      (0)
#define  COMPRESSION_decomp_status_dummy_31_9_mask                               (0xFFFFFE00)
#define  COMPRESSION_decomp_status_decomp_irq_mask                               (0x00000100)
#define  COMPRESSION_decomp_status_head_error_mask                               (0x000000F0)
#define  COMPRESSION_decomp_status_pix_fifo_underflow_mask                       (0x0000000F)
#define  COMPRESSION_decomp_status_dummy_31_9(data)                              (0xFFFFFE00&((data)<<9))
#define  COMPRESSION_decomp_status_decomp_irq(data)                              (0x00000100&((data)<<8))
#define  COMPRESSION_decomp_status_head_error(data)                              (0x000000F0&((data)<<4))
#define  COMPRESSION_decomp_status_pix_fifo_underflow(data)                      (0x0000000F&(data))
#define  COMPRESSION_decomp_status_get_dummy_31_9(data)                          ((0xFFFFFE00&(data))>>9)
#define  COMPRESSION_decomp_status_get_decomp_irq(data)                          ((0x00000100&(data))>>8)
#define  COMPRESSION_decomp_status_get_head_error(data)                          ((0x000000F0&(data))>>4)
#define  COMPRESSION_decomp_status_get_pix_fifo_underflow(data)                  (0x0000000F&(data))

#define  COMPRESSION_dbg_mux                                                     0x18021D40
#define  COMPRESSION_dbg_mux_reg_addr                                            "0xB8021D40"
#define  COMPRESSION_dbg_mux_reg                                                 0xB8021D40
#define  COMPRESSION_dbg_mux_inst_addr                                           "0x0010"
#define  set_COMPRESSION_dbg_mux_reg(data)                                       (*((volatile unsigned int*)COMPRESSION_dbg_mux_reg)=data)
#define  get_COMPRESSION_dbg_mux_reg                                             (*((volatile unsigned int*)COMPRESSION_dbg_mux_reg))
#define  COMPRESSION_dbg_mux_dummy_31_16_shift                                   (16)
#define  COMPRESSION_dbg_mux_decomp_debug_mux_shift                              (8)
#define  COMPRESSION_dbg_mux_comp_debug_mux_shift                                (0)
#define  COMPRESSION_dbg_mux_dummy_31_16_mask                                    (0xFFFF0000)
#define  COMPRESSION_dbg_mux_decomp_debug_mux_mask                               (0x0000FF00)
#define  COMPRESSION_dbg_mux_comp_debug_mux_mask                                 (0x000000FF)
#define  COMPRESSION_dbg_mux_dummy_31_16(data)                                   (0xFFFF0000&((data)<<16))
#define  COMPRESSION_dbg_mux_decomp_debug_mux(data)                              (0x0000FF00&((data)<<8))
#define  COMPRESSION_dbg_mux_comp_debug_mux(data)                                (0x000000FF&(data))
#define  COMPRESSION_dbg_mux_get_dummy_31_16(data)                               ((0xFFFF0000&(data))>>16)
#define  COMPRESSION_dbg_mux_get_decomp_debug_mux(data)                          ((0x0000FF00&(data))>>8)
#define  COMPRESSION_dbg_mux_get_comp_debug_mux(data)                            (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COMPRESSION register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cmp_segment:2;
        RBus_UInt32  cmp_width:8;
        RBus_UInt32  cmp_height:16;
    };
}compression_cmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_a_ch_mark:1;
        RBus_UInt32  cmp_444to422_en:1;
        RBus_UInt32  cmp_rgb_yc_sel:1;
        RBus_UInt32  cmp_channel_bits:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  max_pixel_bits:6;
        RBus_UInt32  short_term_bits:6;
        RBus_UInt32  frame_bits:6;
    };
}compression_comp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  delta_down:8;
        RBus_UInt32  delta_up:8;
    };
}compression_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  not_segement_status_clr:1;
        RBus_UInt32  pixel_num_status_clr:1;
        RBus_UInt32  over_bits_status_clr:1;
        RBus_UInt32  comp_irq_en:3;
    };
}compression_compress_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  comp_irq:1;
        RBus_UInt32  comp_status:3;
    };
}compression_compress_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  decmp_segment:2;
        RBus_UInt32  decmp_width:8;
        RBus_UInt32  decmp_height:16;
    };
}compression_decmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  a_sat_en:1;
        RBus_UInt32  b_cb_sat_en:1;
        RBus_UInt32  g_y_sat_en:1;
        RBus_UInt32  r_cr_sat_en:1;
        RBus_UInt32  decmp_frame_bits:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  decmp_a_ch_mark:1;
        RBus_UInt32  decmp_444to422_en:1;
        RBus_UInt32  decmp_rgb_yc_sel:1;
        RBus_UInt32  decmp_channel_bits:1;
        RBus_UInt32  decmp_cbcr_recov:1;
        RBus_UInt32  decmp_fl_mode:1;
    };
}compression_decomp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  mark_en_9:1;
        RBus_UInt32  mark_en_8:1;
        RBus_UInt32  mark_en_7:1;
        RBus_UInt32  mark_en_6:1;
        RBus_UInt32  mark_en_5:1;
        RBus_UInt32  mark_en_4:1;
        RBus_UInt32  mark_en_3:1;
        RBus_UInt32  mark_en_2:1;
        RBus_UInt32  mark_en_1:1;
        RBus_UInt32  mark_en_0:1;
    };
}compression_trunc_mark_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_0:16;
        RBus_UInt32  mark_color_1:16;
    };
}compression_trunc_color_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_2:16;
        RBus_UInt32  mark_color_3:16;
    };
}compression_trunc_color_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_4:16;
        RBus_UInt32  mark_color_5:16;
    };
}compression_trunc_color_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_6:16;
        RBus_UInt32  mark_color_7:16;
    };
}compression_trunc_color_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_8:16;
        RBus_UInt32  mark_color_9:16;
    };
}compression_trunc_color_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frm_cnt_3:4;
        RBus_UInt32  frm_cnt_2:4;
        RBus_UInt32  frm_cnt_1:4;
        RBus_UInt32  frm_cnt_0:4;
        RBus_UInt32  max_truncation_3:4;
        RBus_UInt32  max_truncation_2:4;
        RBus_UInt32  max_truncation_1:4;
        RBus_UInt32  max_truncation_0:4;
    };
}compression_frame_inst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18021d38_31_10:22;
        RBus_UInt32  head_error_clr:1;
        RBus_UInt32  pix_fifo_underflow_clr:1;
        RBus_UInt32  head_error_irq_en:4;
        RBus_UInt32  underflow_irq_en:4;
    };
}compression_decomp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18021d3c_31_9:23;
        RBus_UInt32  decomp_irq:1;
        RBus_UInt32  head_error:4;
        RBus_UInt32  pix_fifo_underflow:4;
    };
}compression_decomp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18021d40_31_16:16;
        RBus_UInt32  decomp_debug_mux:8;
        RBus_UInt32  comp_debug_mux:8;
    };
}compression_dbg_mux_RBUS;

#else //apply LITTLE_ENDIAN

//======COMPRESSION register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_height:16;
        RBus_UInt32  cmp_width:8;
        RBus_UInt32  cmp_segment:2;
        RBus_UInt32  res1:6;
    };
}compression_cmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_bits:6;
        RBus_UInt32  short_term_bits:6;
        RBus_UInt32  max_pixel_bits:6;
        RBus_UInt32  res1:10;
        RBus_UInt32  cmp_channel_bits:1;
        RBus_UInt32  cmp_rgb_yc_sel:1;
        RBus_UInt32  cmp_444to422_en:1;
        RBus_UInt32  cmp_a_ch_mark:1;
    };
}compression_comp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delta_up:8;
        RBus_UInt32  delta_down:8;
        RBus_UInt32  res1:16;
    };
}compression_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_irq_en:3;
        RBus_UInt32  over_bits_status_clr:1;
        RBus_UInt32  pixel_num_status_clr:1;
        RBus_UInt32  not_segement_status_clr:1;
        RBus_UInt32  res1:26;
    };
}compression_compress_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_status:3;
        RBus_UInt32  comp_irq:1;
        RBus_UInt32  res1:28;
    };
}compression_compress_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_height:16;
        RBus_UInt32  decmp_width:8;
        RBus_UInt32  decmp_segment:2;
        RBus_UInt32  res1:6;
    };
}compression_decmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_fl_mode:1;
        RBus_UInt32  decmp_cbcr_recov:1;
        RBus_UInt32  decmp_channel_bits:1;
        RBus_UInt32  decmp_rgb_yc_sel:1;
        RBus_UInt32  decmp_444to422_en:1;
        RBus_UInt32  decmp_a_ch_mark:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  decmp_frame_bits:6;
        RBus_UInt32  r_cr_sat_en:1;
        RBus_UInt32  g_y_sat_en:1;
        RBus_UInt32  b_cb_sat_en:1;
        RBus_UInt32  a_sat_en:1;
        RBus_UInt32  res2:14;
    };
}compression_decomp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_en_0:1;
        RBus_UInt32  mark_en_1:1;
        RBus_UInt32  mark_en_2:1;
        RBus_UInt32  mark_en_3:1;
        RBus_UInt32  mark_en_4:1;
        RBus_UInt32  mark_en_5:1;
        RBus_UInt32  mark_en_6:1;
        RBus_UInt32  mark_en_7:1;
        RBus_UInt32  mark_en_8:1;
        RBus_UInt32  mark_en_9:1;
        RBus_UInt32  res1:22;
    };
}compression_trunc_mark_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_1:16;
        RBus_UInt32  mark_color_0:16;
    };
}compression_trunc_color_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_3:16;
        RBus_UInt32  mark_color_2:16;
    };
}compression_trunc_color_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_5:16;
        RBus_UInt32  mark_color_4:16;
    };
}compression_trunc_color_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_7:16;
        RBus_UInt32  mark_color_6:16;
    };
}compression_trunc_color_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_9:16;
        RBus_UInt32  mark_color_8:16;
    };
}compression_trunc_color_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_truncation_0:4;
        RBus_UInt32  max_truncation_1:4;
        RBus_UInt32  max_truncation_2:4;
        RBus_UInt32  max_truncation_3:4;
        RBus_UInt32  frm_cnt_0:4;
        RBus_UInt32  frm_cnt_1:4;
        RBus_UInt32  frm_cnt_2:4;
        RBus_UInt32  frm_cnt_3:4;
    };
}compression_frame_inst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  underflow_irq_en:4;
        RBus_UInt32  head_error_irq_en:4;
        RBus_UInt32  pix_fifo_underflow_clr:1;
        RBus_UInt32  head_error_clr:1;
        RBus_UInt32  dummy18021d38_31_10:22;
    };
}compression_decomp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_fifo_underflow:4;
        RBus_UInt32  head_error:4;
        RBus_UInt32  decomp_irq:1;
        RBus_UInt32  dummy18021d3c_31_9:23;
    };
}compression_decomp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_debug_mux:8;
        RBus_UInt32  decomp_debug_mux:8;
        RBus_UInt32  dummy18021d40_31_16:16;
    };
}compression_dbg_mux_RBUS;




#endif 


#endif 
