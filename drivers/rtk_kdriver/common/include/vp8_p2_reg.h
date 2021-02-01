/**
* @file rbusVp8_p2Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/22
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VP8_P2_REG_H_
#define _RBUS_VP8_P2_REG_H_

#include "rbusTypes.h"



//  VP8_P2 Register Address
#define  VP8_P2_VP8_P2_FRM1                                                      0x1800FD00
#define  VP8_P2_VP8_P2_FRM1_reg_addr                                             "0xB800FD00"
#define  VP8_P2_VP8_P2_FRM1_reg                                                  0xB800FD00
#define  VP8_P2_VP8_P2_FRM1_inst_addr                                            "0x0000"
#define  VP8_P2_VP8_P2_FRM1_inst_adr                                             "0x0040"
#define  VP8_P2_VP8_P2_FRM1_inst                                                 0x0040
#define  set_VP8_P2_VP8_P2_FRM1_reg(data)                                        (*((volatile unsigned int*)VP8_P2_VP8_P2_FRM1_reg)=data)
#define  get_VP8_P2_VP8_P2_FRM1_reg                                              (*((volatile unsigned int*)VP8_P2_VP8_P2_FRM1_reg))
#define  VP8_P2_VP8_P2_FRM1_write_enable7_shift                                  (30)
#define  VP8_P2_VP8_P2_FRM1_slice_cnt_shift                                      (22)
#define  VP8_P2_VP8_P2_FRM1_write_enable6_shift                                  (21)
#define  VP8_P2_VP8_P2_FRM1_full_pixel_shift                                     (20)
#define  VP8_P2_VP8_P2_FRM1_write_enable5_shift                                  (19)
#define  VP8_P2_VP8_P2_FRM1_ref_frame_sign_bias_shift                            (15)
#define  VP8_P2_VP8_P2_FRM1_write_enable4_shift                                  (14)
#define  VP8_P2_VP8_P2_FRM1_mb_no_coeff_skip_shift                               (13)
#define  VP8_P2_VP8_P2_FRM1_write_enable3_shift                                  (12)
#define  VP8_P2_VP8_P2_FRM1_segmentation_enabled_shift                           (11)
#define  VP8_P2_VP8_P2_FRM1_write_enable2_shift                                  (10)
#define  VP8_P2_VP8_P2_FRM1_update_mb_segmentation_map_shift                     (9)
#define  VP8_P2_VP8_P2_FRM1_write_enable1_shift                                  (8)
#define  VP8_P2_VP8_P2_FRM1_prob_skip_false_shift                                (0)
#define  VP8_P2_VP8_P2_FRM1_write_enable7_mask                                   (0x40000000)
#define  VP8_P2_VP8_P2_FRM1_slice_cnt_mask                                       (0x3FC00000)
#define  VP8_P2_VP8_P2_FRM1_write_enable6_mask                                   (0x00200000)
#define  VP8_P2_VP8_P2_FRM1_full_pixel_mask                                      (0x00100000)
#define  VP8_P2_VP8_P2_FRM1_write_enable5_mask                                   (0x00080000)
#define  VP8_P2_VP8_P2_FRM1_ref_frame_sign_bias_mask                             (0x00078000)
#define  VP8_P2_VP8_P2_FRM1_write_enable4_mask                                   (0x00004000)
#define  VP8_P2_VP8_P2_FRM1_mb_no_coeff_skip_mask                                (0x00002000)
#define  VP8_P2_VP8_P2_FRM1_write_enable3_mask                                   (0x00001000)
#define  VP8_P2_VP8_P2_FRM1_segmentation_enabled_mask                            (0x00000800)
#define  VP8_P2_VP8_P2_FRM1_write_enable2_mask                                   (0x00000400)
#define  VP8_P2_VP8_P2_FRM1_update_mb_segmentation_map_mask                      (0x00000200)
#define  VP8_P2_VP8_P2_FRM1_write_enable1_mask                                   (0x00000100)
#define  VP8_P2_VP8_P2_FRM1_prob_skip_false_mask                                 (0x000000FF)
#define  VP8_P2_VP8_P2_FRM1_write_enable7(data)                                  (0x40000000&((data)<<30))
#define  VP8_P2_VP8_P2_FRM1_slice_cnt(data)                                      (0x3FC00000&((data)<<22))
#define  VP8_P2_VP8_P2_FRM1_write_enable6(data)                                  (0x00200000&((data)<<21))
#define  VP8_P2_VP8_P2_FRM1_full_pixel(data)                                     (0x00100000&((data)<<20))
#define  VP8_P2_VP8_P2_FRM1_write_enable5(data)                                  (0x00080000&((data)<<19))
#define  VP8_P2_VP8_P2_FRM1_ref_frame_sign_bias(data)                            (0x00078000&((data)<<15))
#define  VP8_P2_VP8_P2_FRM1_write_enable4(data)                                  (0x00004000&((data)<<14))
#define  VP8_P2_VP8_P2_FRM1_mb_no_coeff_skip(data)                               (0x00002000&((data)<<13))
#define  VP8_P2_VP8_P2_FRM1_write_enable3(data)                                  (0x00001000&((data)<<12))
#define  VP8_P2_VP8_P2_FRM1_segmentation_enabled(data)                           (0x00000800&((data)<<11))
#define  VP8_P2_VP8_P2_FRM1_write_enable2(data)                                  (0x00000400&((data)<<10))
#define  VP8_P2_VP8_P2_FRM1_update_mb_segmentation_map(data)                     (0x00000200&((data)<<9))
#define  VP8_P2_VP8_P2_FRM1_write_enable1(data)                                  (0x00000100&((data)<<8))
#define  VP8_P2_VP8_P2_FRM1_prob_skip_false(data)                                (0x000000FF&(data))
#define  VP8_P2_VP8_P2_FRM1_get_write_enable7(data)                              ((0x40000000&(data))>>30)
#define  VP8_P2_VP8_P2_FRM1_get_slice_cnt(data)                                  ((0x3FC00000&(data))>>22)
#define  VP8_P2_VP8_P2_FRM1_get_write_enable6(data)                              ((0x00200000&(data))>>21)
#define  VP8_P2_VP8_P2_FRM1_get_full_pixel(data)                                 ((0x00100000&(data))>>20)
#define  VP8_P2_VP8_P2_FRM1_get_write_enable5(data)                              ((0x00080000&(data))>>19)
#define  VP8_P2_VP8_P2_FRM1_get_ref_frame_sign_bias(data)                        ((0x00078000&(data))>>15)
#define  VP8_P2_VP8_P2_FRM1_get_write_enable4(data)                              ((0x00004000&(data))>>14)
#define  VP8_P2_VP8_P2_FRM1_get_mb_no_coeff_skip(data)                           ((0x00002000&(data))>>13)
#define  VP8_P2_VP8_P2_FRM1_get_write_enable3(data)                              ((0x00001000&(data))>>12)
#define  VP8_P2_VP8_P2_FRM1_get_segmentation_enabled(data)                       ((0x00000800&(data))>>11)
#define  VP8_P2_VP8_P2_FRM1_get_write_enable2(data)                              ((0x00000400&(data))>>10)
#define  VP8_P2_VP8_P2_FRM1_get_update_mb_segmentation_map(data)                 ((0x00000200&(data))>>9)
#define  VP8_P2_VP8_P2_FRM1_get_write_enable1(data)                              ((0x00000100&(data))>>8)
#define  VP8_P2_VP8_P2_FRM1_get_prob_skip_false(data)                            (0x000000FF&(data))
#define  VP8_P2_VP8_P2_FRM1_write_enable7_src(data)                              ((0x40000000&(data))>>30)
#define  VP8_P2_VP8_P2_FRM1_slice_cnt_src(data)                                  ((0x3FC00000&(data))>>22)
#define  VP8_P2_VP8_P2_FRM1_write_enable6_src(data)                              ((0x00200000&(data))>>21)
#define  VP8_P2_VP8_P2_FRM1_full_pixel_src(data)                                 ((0x00100000&(data))>>20)
#define  VP8_P2_VP8_P2_FRM1_write_enable5_src(data)                              ((0x00080000&(data))>>19)
#define  VP8_P2_VP8_P2_FRM1_ref_frame_sign_bias_src(data)                        ((0x00078000&(data))>>15)
#define  VP8_P2_VP8_P2_FRM1_write_enable4_src(data)                              ((0x00004000&(data))>>14)
#define  VP8_P2_VP8_P2_FRM1_mb_no_coeff_skip_src(data)                           ((0x00002000&(data))>>13)
#define  VP8_P2_VP8_P2_FRM1_write_enable3_src(data)                              ((0x00001000&(data))>>12)
#define  VP8_P2_VP8_P2_FRM1_segmentation_enabled_src(data)                       ((0x00000800&(data))>>11)
#define  VP8_P2_VP8_P2_FRM1_write_enable2_src(data)                              ((0x00000400&(data))>>10)
#define  VP8_P2_VP8_P2_FRM1_update_mb_segmentation_map_src(data)                 ((0x00000200&(data))>>9)
#define  VP8_P2_VP8_P2_FRM1_write_enable1_src(data)                              ((0x00000100&(data))>>8)
#define  VP8_P2_VP8_P2_FRM1_prob_skip_false_src(data)                            (0x000000FF&(data))

#define  VP8_P2_VP8_P2_FRM2                                                      0x1800FD04
#define  VP8_P2_VP8_P2_FRM2_reg_addr                                             "0xB800FD04"
#define  VP8_P2_VP8_P2_FRM2_reg                                                  0xB800FD04
#define  VP8_P2_VP8_P2_FRM2_inst_addr                                            "0x0001"
#define  VP8_P2_VP8_P2_FRM2_inst_adr                                             "0x0041"
#define  VP8_P2_VP8_P2_FRM2_inst                                                 0x0041
#define  set_VP8_P2_VP8_P2_FRM2_reg(data)                                        (*((volatile unsigned int*)VP8_P2_VP8_P2_FRM2_reg)=data)
#define  get_VP8_P2_VP8_P2_FRM2_reg                                              (*((volatile unsigned int*)VP8_P2_VP8_P2_FRM2_reg))
#define  VP8_P2_VP8_P2_FRM2_write_enable3_shift                                  (26)
#define  VP8_P2_VP8_P2_FRM2_prob_gf_shift                                        (18)
#define  VP8_P2_VP8_P2_FRM2_write_enable2_shift                                  (17)
#define  VP8_P2_VP8_P2_FRM2_prob_last_shift                                      (9)
#define  VP8_P2_VP8_P2_FRM2_write_enable1_shift                                  (8)
#define  VP8_P2_VP8_P2_FRM2_prob_intra_shift                                     (0)
#define  VP8_P2_VP8_P2_FRM2_write_enable3_mask                                   (0x04000000)
#define  VP8_P2_VP8_P2_FRM2_prob_gf_mask                                         (0x03FC0000)
#define  VP8_P2_VP8_P2_FRM2_write_enable2_mask                                   (0x00020000)
#define  VP8_P2_VP8_P2_FRM2_prob_last_mask                                       (0x0001FE00)
#define  VP8_P2_VP8_P2_FRM2_write_enable1_mask                                   (0x00000100)
#define  VP8_P2_VP8_P2_FRM2_prob_intra_mask                                      (0x000000FF)
#define  VP8_P2_VP8_P2_FRM2_write_enable3(data)                                  (0x04000000&((data)<<26))
#define  VP8_P2_VP8_P2_FRM2_prob_gf(data)                                        (0x03FC0000&((data)<<18))
#define  VP8_P2_VP8_P2_FRM2_write_enable2(data)                                  (0x00020000&((data)<<17))
#define  VP8_P2_VP8_P2_FRM2_prob_last(data)                                      (0x0001FE00&((data)<<9))
#define  VP8_P2_VP8_P2_FRM2_write_enable1(data)                                  (0x00000100&((data)<<8))
#define  VP8_P2_VP8_P2_FRM2_prob_intra(data)                                     (0x000000FF&(data))
#define  VP8_P2_VP8_P2_FRM2_get_write_enable3(data)                              ((0x04000000&(data))>>26)
#define  VP8_P2_VP8_P2_FRM2_get_prob_gf(data)                                    ((0x03FC0000&(data))>>18)
#define  VP8_P2_VP8_P2_FRM2_get_write_enable2(data)                              ((0x00020000&(data))>>17)
#define  VP8_P2_VP8_P2_FRM2_get_prob_last(data)                                  ((0x0001FE00&(data))>>9)
#define  VP8_P2_VP8_P2_FRM2_get_write_enable1(data)                              ((0x00000100&(data))>>8)
#define  VP8_P2_VP8_P2_FRM2_get_prob_intra(data)                                 (0x000000FF&(data))
#define  VP8_P2_VP8_P2_FRM2_write_enable3_src(data)                              ((0x04000000&(data))>>26)
#define  VP8_P2_VP8_P2_FRM2_prob_gf_src(data)                                    ((0x03FC0000&(data))>>18)
#define  VP8_P2_VP8_P2_FRM2_write_enable2_src(data)                              ((0x00020000&(data))>>17)
#define  VP8_P2_VP8_P2_FRM2_prob_last_src(data)                                  ((0x0001FE00&(data))>>9)
#define  VP8_P2_VP8_P2_FRM2_write_enable1_src(data)                              ((0x00000100&(data))>>8)
#define  VP8_P2_VP8_P2_FRM2_prob_intra_src(data)                                 (0x000000FF&(data))

#define  VP8_P2_VP8_P2_FRM3                                                      0x1800FD08
#define  VP8_P2_VP8_P2_FRM3_reg_addr                                             "0xB800FD08"
#define  VP8_P2_VP8_P2_FRM3_reg                                                  0xB800FD08
#define  VP8_P2_VP8_P2_FRM3_inst_addr                                            "0x0002"
#define  VP8_P2_VP8_P2_FRM3_inst_adr                                             "0x0042"
#define  VP8_P2_VP8_P2_FRM3_inst                                                 0x0042
#define  set_VP8_P2_VP8_P2_FRM3_reg(data)                                        (*((volatile unsigned int*)VP8_P2_VP8_P2_FRM3_reg)=data)
#define  get_VP8_P2_VP8_P2_FRM3_reg                                              (*((volatile unsigned int*)VP8_P2_VP8_P2_FRM3_reg))
#define  VP8_P2_VP8_P2_FRM3_write_enable1_shift                                  (7)
#define  VP8_P2_VP8_P2_FRM3_picmb_h_shift                                        (0)
#define  VP8_P2_VP8_P2_FRM3_write_enable1_mask                                   (0x00000080)
#define  VP8_P2_VP8_P2_FRM3_picmb_h_mask                                         (0x0000007F)
#define  VP8_P2_VP8_P2_FRM3_write_enable1(data)                                  (0x00000080&((data)<<7))
#define  VP8_P2_VP8_P2_FRM3_picmb_h(data)                                        (0x0000007F&(data))
#define  VP8_P2_VP8_P2_FRM3_get_write_enable1(data)                              ((0x00000080&(data))>>7)
#define  VP8_P2_VP8_P2_FRM3_get_picmb_h(data)                                    (0x0000007F&(data))
#define  VP8_P2_VP8_P2_FRM3_write_enable1_src(data)                              ((0x00000080&(data))>>7)
#define  VP8_P2_VP8_P2_FRM3_picmb_h_src(data)                                    (0x0000007F&(data))

#define  VP8_P2_VP8_P2_MB1                                                       0x1800FD0C
#define  VP8_P2_VP8_P2_MB1_reg_addr                                              "0xB800FD0C"
#define  VP8_P2_VP8_P2_MB1_reg                                                   0xB800FD0C
#define  VP8_P2_VP8_P2_MB1_inst_addr                                             "0x0003"
#define  VP8_P2_VP8_P2_MB1_inst_adr                                              "0x0043"
#define  VP8_P2_VP8_P2_MB1_inst                                                  0x0043
#define  set_VP8_P2_VP8_P2_MB1_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_P2_MB1_reg)=data)
#define  get_VP8_P2_VP8_P2_MB1_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_P2_MB1_reg))
#define  VP8_P2_VP8_P2_MB1_need_to_clamp_mvs_shift                               (11)
#define  VP8_P2_VP8_P2_MB1_ref_frame_shift                                       (9)
#define  VP8_P2_VP8_P2_MB1_uv_mode_shift                                         (7)
#define  VP8_P2_VP8_P2_MB1_mode_shift                                            (3)
#define  VP8_P2_VP8_P2_MB1_mb_skip_coeff_shift                                   (2)
#define  VP8_P2_VP8_P2_MB1_segment_id_shift                                      (0)
#define  VP8_P2_VP8_P2_MB1_need_to_clamp_mvs_mask                                (0x00000800)
#define  VP8_P2_VP8_P2_MB1_ref_frame_mask                                        (0x00000600)
#define  VP8_P2_VP8_P2_MB1_uv_mode_mask                                          (0x00000180)
#define  VP8_P2_VP8_P2_MB1_mode_mask                                             (0x00000078)
#define  VP8_P2_VP8_P2_MB1_mb_skip_coeff_mask                                    (0x00000004)
#define  VP8_P2_VP8_P2_MB1_segment_id_mask                                       (0x00000003)
#define  VP8_P2_VP8_P2_MB1_need_to_clamp_mvs(data)                               (0x00000800&((data)<<11))
#define  VP8_P2_VP8_P2_MB1_ref_frame(data)                                       (0x00000600&((data)<<9))
#define  VP8_P2_VP8_P2_MB1_uv_mode(data)                                         (0x00000180&((data)<<7))
#define  VP8_P2_VP8_P2_MB1_mode(data)                                            (0x00000078&((data)<<3))
#define  VP8_P2_VP8_P2_MB1_mb_skip_coeff(data)                                   (0x00000004&((data)<<2))
#define  VP8_P2_VP8_P2_MB1_segment_id(data)                                      (0x00000003&(data))
#define  VP8_P2_VP8_P2_MB1_get_need_to_clamp_mvs(data)                           ((0x00000800&(data))>>11)
#define  VP8_P2_VP8_P2_MB1_get_ref_frame(data)                                   ((0x00000600&(data))>>9)
#define  VP8_P2_VP8_P2_MB1_get_uv_mode(data)                                     ((0x00000180&(data))>>7)
#define  VP8_P2_VP8_P2_MB1_get_mode(data)                                        ((0x00000078&(data))>>3)
#define  VP8_P2_VP8_P2_MB1_get_mb_skip_coeff(data)                               ((0x00000004&(data))>>2)
#define  VP8_P2_VP8_P2_MB1_get_segment_id(data)                                  (0x00000003&(data))
#define  VP8_P2_VP8_P2_MB1_need_to_clamp_mvs_src(data)                           ((0x00000800&(data))>>11)
#define  VP8_P2_VP8_P2_MB1_ref_frame_src(data)                                   ((0x00000600&(data))>>9)
#define  VP8_P2_VP8_P2_MB1_uv_mode_src(data)                                     ((0x00000180&(data))>>7)
#define  VP8_P2_VP8_P2_MB1_mode_src(data)                                        ((0x00000078&(data))>>3)
#define  VP8_P2_VP8_P2_MB1_mb_skip_coeff_src(data)                               ((0x00000004&(data))>>2)
#define  VP8_P2_VP8_P2_MB1_segment_id_src(data)                                  (0x00000003&(data))

#define  VP8_P2_VP8_P2_MB2                                                       0x1800FD10
#define  VP8_P2_VP8_P2_MB2_reg_addr                                              "0xB800FD10"
#define  VP8_P2_VP8_P2_MB2_reg                                                   0xB800FD10
#define  VP8_P2_VP8_P2_MB2_inst_addr                                             "0x0004"
#define  VP8_P2_VP8_P2_MB2_inst_adr                                              "0x0044"
#define  VP8_P2_VP8_P2_MB2_inst                                                  0x0044
#define  set_VP8_P2_VP8_P2_MB2_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_P2_MB2_reg)=data)
#define  get_VP8_P2_VP8_P2_MB2_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_P2_MB2_reg))
#define  VP8_P2_VP8_P2_MB2_write_enable3_shift                                   (26)
#define  VP8_P2_VP8_P2_MB2_ndb_p2_flush_shift                                    (25)
#define  VP8_P2_VP8_P2_MB2_write_enable2_shift                                   (24)
#define  VP8_P2_VP8_P2_MB2_mby_shift                                             (17)
#define  VP8_P2_VP8_P2_MB2_write_enable1_shift                                   (16)
#define  VP8_P2_VP8_P2_MB2_left_sub_block_mode_shift                             (0)
#define  VP8_P2_VP8_P2_MB2_write_enable3_mask                                    (0x04000000)
#define  VP8_P2_VP8_P2_MB2_ndb_p2_flush_mask                                     (0x02000000)
#define  VP8_P2_VP8_P2_MB2_write_enable2_mask                                    (0x01000000)
#define  VP8_P2_VP8_P2_MB2_mby_mask                                              (0x00FE0000)
#define  VP8_P2_VP8_P2_MB2_write_enable1_mask                                    (0x00010000)
#define  VP8_P2_VP8_P2_MB2_left_sub_block_mode_mask                              (0x0000FFFF)
#define  VP8_P2_VP8_P2_MB2_write_enable3(data)                                   (0x04000000&((data)<<26))
#define  VP8_P2_VP8_P2_MB2_ndb_p2_flush(data)                                    (0x02000000&((data)<<25))
#define  VP8_P2_VP8_P2_MB2_write_enable2(data)                                   (0x01000000&((data)<<24))
#define  VP8_P2_VP8_P2_MB2_mby(data)                                             (0x00FE0000&((data)<<17))
#define  VP8_P2_VP8_P2_MB2_write_enable1(data)                                   (0x00010000&((data)<<16))
#define  VP8_P2_VP8_P2_MB2_left_sub_block_mode(data)                             (0x0000FFFF&(data))
#define  VP8_P2_VP8_P2_MB2_get_write_enable3(data)                               ((0x04000000&(data))>>26)
#define  VP8_P2_VP8_P2_MB2_get_ndb_p2_flush(data)                                ((0x02000000&(data))>>25)
#define  VP8_P2_VP8_P2_MB2_get_write_enable2(data)                               ((0x01000000&(data))>>24)
#define  VP8_P2_VP8_P2_MB2_get_mby(data)                                         ((0x00FE0000&(data))>>17)
#define  VP8_P2_VP8_P2_MB2_get_write_enable1(data)                               ((0x00010000&(data))>>16)
#define  VP8_P2_VP8_P2_MB2_get_left_sub_block_mode(data)                         (0x0000FFFF&(data))
#define  VP8_P2_VP8_P2_MB2_write_enable3_src(data)                               ((0x04000000&(data))>>26)
#define  VP8_P2_VP8_P2_MB2_ndb_p2_flush_src(data)                                ((0x02000000&(data))>>25)
#define  VP8_P2_VP8_P2_MB2_write_enable2_src(data)                               ((0x01000000&(data))>>24)
#define  VP8_P2_VP8_P2_MB2_mby_src(data)                                         ((0x00FE0000&(data))>>17)
#define  VP8_P2_VP8_P2_MB2_write_enable1_src(data)                               ((0x00010000&(data))>>16)
#define  VP8_P2_VP8_P2_MB2_left_sub_block_mode_src(data)                         (0x0000FFFF&(data))

#define  VP8_P2_VP8_P2_SUB_BLK0                                                  0x1800FD14
#define  VP8_P2_VP8_P2_SUB_BLK0_reg_addr                                         "0xB800FD14"
#define  VP8_P2_VP8_P2_SUB_BLK0_reg                                              0xB800FD14
#define  VP8_P2_VP8_P2_SUB_BLK0_inst_addr                                        "0x0005"
#define  VP8_P2_VP8_P2_SUB_BLK0_inst_adr                                         "0x0045"
#define  VP8_P2_VP8_P2_SUB_BLK0_inst                                             0x0045
#define  set_VP8_P2_VP8_P2_SUB_BLK0_reg(data)                                    (*((volatile unsigned int*)VP8_P2_VP8_P2_SUB_BLK0_reg)=data)
#define  get_VP8_P2_VP8_P2_SUB_BLK0_reg                                          (*((volatile unsigned int*)VP8_P2_VP8_P2_SUB_BLK0_reg))
#define  VP8_P2_VP8_P2_SUB_BLK0_sub_blk_mode_p0_shift                            (0)
#define  VP8_P2_VP8_P2_SUB_BLK0_sub_blk_mode_p0_mask                             (0xFFFFFFFF)
#define  VP8_P2_VP8_P2_SUB_BLK0_sub_blk_mode_p0(data)                            (0xFFFFFFFF&(data))
#define  VP8_P2_VP8_P2_SUB_BLK0_get_sub_blk_mode_p0(data)                        (0xFFFFFFFF&(data))
#define  VP8_P2_VP8_P2_SUB_BLK0_sub_blk_mode_p0_src(data)                        (0xFFFFFFFF&(data))

#define  VP8_P2_VP8_P2_SUB_BLK1                                                  0x1800FD18
#define  VP8_P2_VP8_P2_SUB_BLK1_reg_addr                                         "0xB800FD18"
#define  VP8_P2_VP8_P2_SUB_BLK1_reg                                              0xB800FD18
#define  VP8_P2_VP8_P2_SUB_BLK1_inst_addr                                        "0x0006"
#define  VP8_P2_VP8_P2_SUB_BLK1_inst_adr                                         "0x0046"
#define  VP8_P2_VP8_P2_SUB_BLK1_inst                                             0x0046
#define  set_VP8_P2_VP8_P2_SUB_BLK1_reg(data)                                    (*((volatile unsigned int*)VP8_P2_VP8_P2_SUB_BLK1_reg)=data)
#define  get_VP8_P2_VP8_P2_SUB_BLK1_reg                                          (*((volatile unsigned int*)VP8_P2_VP8_P2_SUB_BLK1_reg))
#define  VP8_P2_VP8_P2_SUB_BLK1_sub_blk_mode_p1_shift                            (0)
#define  VP8_P2_VP8_P2_SUB_BLK1_sub_blk_mode_p1_mask                             (0xFFFFFFFF)
#define  VP8_P2_VP8_P2_SUB_BLK1_sub_blk_mode_p1(data)                            (0xFFFFFFFF&(data))
#define  VP8_P2_VP8_P2_SUB_BLK1_get_sub_blk_mode_p1(data)                        (0xFFFFFFFF&(data))
#define  VP8_P2_VP8_P2_SUB_BLK1_sub_blk_mode_p1_src(data)                        (0xFFFFFFFF&(data))

#define  VP8_P2_VP8_P2_MB_INFO                                                   0x1800FD1C
#define  VP8_P2_VP8_P2_MB_INFO_reg_addr                                          "0xB800FD1C"
#define  VP8_P2_VP8_P2_MB_INFO_reg                                               0xB800FD1C
#define  VP8_P2_VP8_P2_MB_INFO_inst_addr                                         "0x0007"
#define  VP8_P2_VP8_P2_MB_INFO_inst_adr                                          "0x0047"
#define  VP8_P2_VP8_P2_MB_INFO_inst                                              0x0047
#define  set_VP8_P2_VP8_P2_MB_INFO_reg(data)                                     (*((volatile unsigned int*)VP8_P2_VP8_P2_MB_INFO_reg)=data)
#define  get_VP8_P2_VP8_P2_MB_INFO_reg                                           (*((volatile unsigned int*)VP8_P2_VP8_P2_MB_INFO_reg))
#define  VP8_P2_VP8_P2_MB_INFO_vp8_p2_curmb_shift                                (17)
#define  VP8_P2_VP8_P2_MB_INFO_vp8_mbpartition_shift                             (8)
#define  VP8_P2_VP8_P2_MB_INFO_vp8_Inter_pred_option_shift                       (0)
#define  VP8_P2_VP8_P2_MB_INFO_vp8_p2_curmb_mask                                 (0x03FE0000)
#define  VP8_P2_VP8_P2_MB_INFO_vp8_mbpartition_mask                              (0x0001FF00)
#define  VP8_P2_VP8_P2_MB_INFO_vp8_Inter_pred_option_mask                        (0x000000FF)
#define  VP8_P2_VP8_P2_MB_INFO_vp8_p2_curmb(data)                                (0x03FE0000&((data)<<17))
#define  VP8_P2_VP8_P2_MB_INFO_vp8_mbpartition(data)                             (0x0001FF00&((data)<<8))
#define  VP8_P2_VP8_P2_MB_INFO_vp8_Inter_pred_option(data)                       (0x000000FF&(data))
#define  VP8_P2_VP8_P2_MB_INFO_get_vp8_p2_curmb(data)                            ((0x03FE0000&(data))>>17)
#define  VP8_P2_VP8_P2_MB_INFO_get_vp8_mbpartition(data)                         ((0x0001FF00&(data))>>8)
#define  VP8_P2_VP8_P2_MB_INFO_get_vp8_Inter_pred_option(data)                   (0x000000FF&(data))
#define  VP8_P2_VP8_P2_MB_INFO_vp8_p2_curmb_src(data)                            ((0x03FE0000&(data))>>17)
#define  VP8_P2_VP8_P2_MB_INFO_vp8_mbpartition_src(data)                         ((0x0001FF00&(data))>>8)
#define  VP8_P2_VP8_P2_MB_INFO_vp8_Inter_pred_option_src(data)                   (0x000000FF&(data))

#define  VP8_P2_VP8_BAC                                                          0x1800FD20
#define  VP8_P2_VP8_BAC_reg_addr                                                 "0xB800FD20"
#define  VP8_P2_VP8_BAC_reg                                                      0xB800FD20
#define  VP8_P2_VP8_BAC_inst_addr                                                "0x0008"
#define  VP8_P2_VP8_BAC_inst_adr                                                 "0x0048"
#define  VP8_P2_VP8_BAC_inst                                                     0x0048
#define  set_VP8_P2_VP8_BAC_reg(data)                                            (*((volatile unsigned int*)VP8_P2_VP8_BAC_reg)=data)
#define  get_VP8_P2_VP8_BAC_reg                                                  (*((volatile unsigned int*)VP8_P2_VP8_BAC_reg))
#define  VP8_P2_VP8_BAC_high_shift                                               (20)
#define  VP8_P2_VP8_BAC_bits_shift                                               (16)
#define  VP8_P2_VP8_BAC_code_word_shift                                          (0)
#define  VP8_P2_VP8_BAC_high_mask                                                (0x1FF00000)
#define  VP8_P2_VP8_BAC_bits_mask                                                (0x000F0000)
#define  VP8_P2_VP8_BAC_code_word_mask                                           (0x0000FFFF)
#define  VP8_P2_VP8_BAC_high(data)                                               (0x1FF00000&((data)<<20))
#define  VP8_P2_VP8_BAC_bits(data)                                               (0x000F0000&((data)<<16))
#define  VP8_P2_VP8_BAC_code_word(data)                                          (0x0000FFFF&(data))
#define  VP8_P2_VP8_BAC_get_high(data)                                           ((0x1FF00000&(data))>>20)
#define  VP8_P2_VP8_BAC_get_bits(data)                                           ((0x000F0000&(data))>>16)
#define  VP8_P2_VP8_BAC_get_code_word(data)                                      (0x0000FFFF&(data))
#define  VP8_P2_VP8_BAC_high_src(data)                                           ((0x1FF00000&(data))>>20)
#define  VP8_P2_VP8_BAC_bits_src(data)                                           ((0x000F0000&(data))>>16)
#define  VP8_P2_VP8_BAC_code_word_src(data)                                      (0x0000FFFF&(data))

#define  VP8_P2_VP8_MB_MV0                                                       0x1800FD24
#define  VP8_P2_VP8_MB_MV0_reg_addr                                              "0xB800FD24"
#define  VP8_P2_VP8_MB_MV0_reg                                                   0xB800FD24
#define  VP8_P2_VP8_MB_MV0_inst_addr                                             "0x0009"
#define  VP8_P2_VP8_MB_MV0_inst_adr                                              "0x0049"
#define  VP8_P2_VP8_MB_MV0_inst                                                  0x0049
#define  set_VP8_P2_VP8_MB_MV0_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV0_reg)=data)
#define  get_VP8_P2_VP8_MB_MV0_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV0_reg))
#define  VP8_P2_VP8_MB_MV0_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV0_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV0_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV0_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV0_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV0_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV0_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV0_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV0_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV0_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV1                                                       0x1800FD28
#define  VP8_P2_VP8_MB_MV1_reg_addr                                              "0xB800FD28"
#define  VP8_P2_VP8_MB_MV1_reg                                                   0xB800FD28
#define  VP8_P2_VP8_MB_MV1_inst_addr                                             "0x000A"
#define  VP8_P2_VP8_MB_MV1_inst_adr                                              "0x004A"
#define  VP8_P2_VP8_MB_MV1_inst                                                  0x004A
#define  set_VP8_P2_VP8_MB_MV1_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV1_reg)=data)
#define  get_VP8_P2_VP8_MB_MV1_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV1_reg))
#define  VP8_P2_VP8_MB_MV1_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV1_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV1_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV1_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV1_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV1_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV1_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV1_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV1_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV1_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV2                                                       0x1800FD2C
#define  VP8_P2_VP8_MB_MV2_reg_addr                                              "0xB800FD2C"
#define  VP8_P2_VP8_MB_MV2_reg                                                   0xB800FD2C
#define  VP8_P2_VP8_MB_MV2_inst_addr                                             "0x000B"
#define  VP8_P2_VP8_MB_MV2_inst_adr                                              "0x004B"
#define  VP8_P2_VP8_MB_MV2_inst                                                  0x004B
#define  set_VP8_P2_VP8_MB_MV2_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV2_reg)=data)
#define  get_VP8_P2_VP8_MB_MV2_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV2_reg))
#define  VP8_P2_VP8_MB_MV2_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV2_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV2_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV2_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV2_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV2_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV2_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV2_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV2_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV2_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV3                                                       0x1800FD30
#define  VP8_P2_VP8_MB_MV3_reg_addr                                              "0xB800FD30"
#define  VP8_P2_VP8_MB_MV3_reg                                                   0xB800FD30
#define  VP8_P2_VP8_MB_MV3_inst_addr                                             "0x000C"
#define  VP8_P2_VP8_MB_MV3_inst_adr                                              "0x004C"
#define  VP8_P2_VP8_MB_MV3_inst                                                  0x004C
#define  set_VP8_P2_VP8_MB_MV3_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV3_reg)=data)
#define  get_VP8_P2_VP8_MB_MV3_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV3_reg))
#define  VP8_P2_VP8_MB_MV3_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV3_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV3_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV3_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV3_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV3_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV3_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV3_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV3_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV3_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV4                                                       0x1800FD34
#define  VP8_P2_VP8_MB_MV4_reg_addr                                              "0xB800FD34"
#define  VP8_P2_VP8_MB_MV4_reg                                                   0xB800FD34
#define  VP8_P2_VP8_MB_MV4_inst_addr                                             "0x000D"
#define  VP8_P2_VP8_MB_MV4_inst_adr                                              "0x004D"
#define  VP8_P2_VP8_MB_MV4_inst                                                  0x004D
#define  set_VP8_P2_VP8_MB_MV4_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV4_reg)=data)
#define  get_VP8_P2_VP8_MB_MV4_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV4_reg))
#define  VP8_P2_VP8_MB_MV4_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV4_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV4_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV4_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV4_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV4_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV4_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV4_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV4_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV4_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV5                                                       0x1800FD38
#define  VP8_P2_VP8_MB_MV5_reg_addr                                              "0xB800FD38"
#define  VP8_P2_VP8_MB_MV5_reg                                                   0xB800FD38
#define  VP8_P2_VP8_MB_MV5_inst_addr                                             "0x000E"
#define  VP8_P2_VP8_MB_MV5_inst_adr                                              "0x004E"
#define  VP8_P2_VP8_MB_MV5_inst                                                  0x004E
#define  set_VP8_P2_VP8_MB_MV5_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV5_reg)=data)
#define  get_VP8_P2_VP8_MB_MV5_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV5_reg))
#define  VP8_P2_VP8_MB_MV5_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV5_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV5_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV5_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV5_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV5_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV5_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV5_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV5_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV5_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV6                                                       0x1800FD3C
#define  VP8_P2_VP8_MB_MV6_reg_addr                                              "0xB800FD3C"
#define  VP8_P2_VP8_MB_MV6_reg                                                   0xB800FD3C
#define  VP8_P2_VP8_MB_MV6_inst_addr                                             "0x000F"
#define  VP8_P2_VP8_MB_MV6_inst_adr                                              "0x004F"
#define  VP8_P2_VP8_MB_MV6_inst                                                  0x004F
#define  set_VP8_P2_VP8_MB_MV6_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV6_reg)=data)
#define  get_VP8_P2_VP8_MB_MV6_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV6_reg))
#define  VP8_P2_VP8_MB_MV6_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV6_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV6_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV6_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV6_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV6_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV6_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV6_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV6_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV6_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV7                                                       0x1800FD40
#define  VP8_P2_VP8_MB_MV7_reg_addr                                              "0xB800FD40"
#define  VP8_P2_VP8_MB_MV7_reg                                                   0xB800FD40
#define  VP8_P2_VP8_MB_MV7_inst_addr                                             "0x0010"
#define  VP8_P2_VP8_MB_MV7_inst_adr                                              "0x0050"
#define  VP8_P2_VP8_MB_MV7_inst                                                  0x0050
#define  set_VP8_P2_VP8_MB_MV7_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV7_reg)=data)
#define  get_VP8_P2_VP8_MB_MV7_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV7_reg))
#define  VP8_P2_VP8_MB_MV7_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV7_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV7_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV7_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV7_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV7_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV7_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV7_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV7_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV7_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV8                                                       0x1800FD44
#define  VP8_P2_VP8_MB_MV8_reg_addr                                              "0xB800FD44"
#define  VP8_P2_VP8_MB_MV8_reg                                                   0xB800FD44
#define  VP8_P2_VP8_MB_MV8_inst_addr                                             "0x0011"
#define  VP8_P2_VP8_MB_MV8_inst_adr                                              "0x0051"
#define  VP8_P2_VP8_MB_MV8_inst                                                  0x0051
#define  set_VP8_P2_VP8_MB_MV8_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV8_reg)=data)
#define  get_VP8_P2_VP8_MB_MV8_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV8_reg))
#define  VP8_P2_VP8_MB_MV8_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV8_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV8_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV8_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV8_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV8_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV8_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV8_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV8_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV8_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV9                                                       0x1800FD48
#define  VP8_P2_VP8_MB_MV9_reg_addr                                              "0xB800FD48"
#define  VP8_P2_VP8_MB_MV9_reg                                                   0xB800FD48
#define  VP8_P2_VP8_MB_MV9_inst_addr                                             "0x0012"
#define  VP8_P2_VP8_MB_MV9_inst_adr                                              "0x0052"
#define  VP8_P2_VP8_MB_MV9_inst                                                  0x0052
#define  set_VP8_P2_VP8_MB_MV9_reg(data)                                         (*((volatile unsigned int*)VP8_P2_VP8_MB_MV9_reg)=data)
#define  get_VP8_P2_VP8_MB_MV9_reg                                               (*((volatile unsigned int*)VP8_P2_VP8_MB_MV9_reg))
#define  VP8_P2_VP8_MB_MV9_mv_x_shift                                            (14)
#define  VP8_P2_VP8_MB_MV9_mv_y_shift                                            (0)
#define  VP8_P2_VP8_MB_MV9_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV9_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_VP8_MB_MV9_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV9_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV9_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV9_get_mv_y(data)                                        (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV9_mv_x_src(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV9_mv_y_src(data)                                        (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV10                                                      0x1800FD4C
#define  VP8_P2_VP8_MB_MV10_reg_addr                                             "0xB800FD4C"
#define  VP8_P2_VP8_MB_MV10_reg                                                  0xB800FD4C
#define  VP8_P2_VP8_MB_MV10_inst_addr                                            "0x0013"
#define  VP8_P2_VP8_MB_MV10_inst_adr                                             "0x0053"
#define  VP8_P2_VP8_MB_MV10_inst                                                 0x0053
#define  set_VP8_P2_VP8_MB_MV10_reg(data)                                        (*((volatile unsigned int*)VP8_P2_VP8_MB_MV10_reg)=data)
#define  get_VP8_P2_VP8_MB_MV10_reg                                              (*((volatile unsigned int*)VP8_P2_VP8_MB_MV10_reg))
#define  VP8_P2_VP8_MB_MV10_mv_x_shift                                           (14)
#define  VP8_P2_VP8_MB_MV10_mv_y_shift                                           (0)
#define  VP8_P2_VP8_MB_MV10_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV10_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_VP8_MB_MV10_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV10_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV10_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV10_get_mv_y(data)                                       (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV10_mv_x_src(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV10_mv_y_src(data)                                       (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV11                                                      0x1800FD50
#define  VP8_P2_VP8_MB_MV11_reg_addr                                             "0xB800FD50"
#define  VP8_P2_VP8_MB_MV11_reg                                                  0xB800FD50
#define  VP8_P2_VP8_MB_MV11_inst_addr                                            "0x0014"
#define  VP8_P2_VP8_MB_MV11_inst_adr                                             "0x0054"
#define  VP8_P2_VP8_MB_MV11_inst                                                 0x0054
#define  set_VP8_P2_VP8_MB_MV11_reg(data)                                        (*((volatile unsigned int*)VP8_P2_VP8_MB_MV11_reg)=data)
#define  get_VP8_P2_VP8_MB_MV11_reg                                              (*((volatile unsigned int*)VP8_P2_VP8_MB_MV11_reg))
#define  VP8_P2_VP8_MB_MV11_mv_x_shift                                           (14)
#define  VP8_P2_VP8_MB_MV11_mv_y_shift                                           (0)
#define  VP8_P2_VP8_MB_MV11_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV11_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_VP8_MB_MV11_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV11_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV11_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV11_get_mv_y(data)                                       (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV11_mv_x_src(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV11_mv_y_src(data)                                       (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV12                                                      0x1800FD54
#define  VP8_P2_VP8_MB_MV12_reg_addr                                             "0xB800FD54"
#define  VP8_P2_VP8_MB_MV12_reg                                                  0xB800FD54
#define  VP8_P2_VP8_MB_MV12_inst_addr                                            "0x0015"
#define  VP8_P2_VP8_MB_MV12_inst_adr                                             "0x0055"
#define  VP8_P2_VP8_MB_MV12_inst                                                 0x0055
#define  set_VP8_P2_VP8_MB_MV12_reg(data)                                        (*((volatile unsigned int*)VP8_P2_VP8_MB_MV12_reg)=data)
#define  get_VP8_P2_VP8_MB_MV12_reg                                              (*((volatile unsigned int*)VP8_P2_VP8_MB_MV12_reg))
#define  VP8_P2_VP8_MB_MV12_mv_x_shift                                           (14)
#define  VP8_P2_VP8_MB_MV12_mv_y_shift                                           (0)
#define  VP8_P2_VP8_MB_MV12_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV12_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_VP8_MB_MV12_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV12_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV12_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV12_get_mv_y(data)                                       (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV12_mv_x_src(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV12_mv_y_src(data)                                       (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV13                                                      0x1800FD58
#define  VP8_P2_VP8_MB_MV13_reg_addr                                             "0xB800FD58"
#define  VP8_P2_VP8_MB_MV13_reg                                                  0xB800FD58
#define  VP8_P2_VP8_MB_MV13_inst_addr                                            "0x0016"
#define  VP8_P2_VP8_MB_MV13_inst_adr                                             "0x0056"
#define  VP8_P2_VP8_MB_MV13_inst                                                 0x0056
#define  set_VP8_P2_VP8_MB_MV13_reg(data)                                        (*((volatile unsigned int*)VP8_P2_VP8_MB_MV13_reg)=data)
#define  get_VP8_P2_VP8_MB_MV13_reg                                              (*((volatile unsigned int*)VP8_P2_VP8_MB_MV13_reg))
#define  VP8_P2_VP8_MB_MV13_mv_x_shift                                           (14)
#define  VP8_P2_VP8_MB_MV13_mv_y_shift                                           (0)
#define  VP8_P2_VP8_MB_MV13_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV13_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_VP8_MB_MV13_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV13_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV13_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV13_get_mv_y(data)                                       (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV13_mv_x_src(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV13_mv_y_src(data)                                       (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV14                                                      0x1800FD5C
#define  VP8_P2_VP8_MB_MV14_reg_addr                                             "0xB800FD5C"
#define  VP8_P2_VP8_MB_MV14_reg                                                  0xB800FD5C
#define  VP8_P2_VP8_MB_MV14_inst_addr                                            "0x0017"
#define  VP8_P2_VP8_MB_MV14_inst_adr                                             "0x0057"
#define  VP8_P2_VP8_MB_MV14_inst                                                 0x0057
#define  set_VP8_P2_VP8_MB_MV14_reg(data)                                        (*((volatile unsigned int*)VP8_P2_VP8_MB_MV14_reg)=data)
#define  get_VP8_P2_VP8_MB_MV14_reg                                              (*((volatile unsigned int*)VP8_P2_VP8_MB_MV14_reg))
#define  VP8_P2_VP8_MB_MV14_mv_x_shift                                           (14)
#define  VP8_P2_VP8_MB_MV14_mv_y_shift                                           (0)
#define  VP8_P2_VP8_MB_MV14_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV14_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_VP8_MB_MV14_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV14_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV14_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV14_get_mv_y(data)                                       (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV14_mv_x_src(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV14_mv_y_src(data)                                       (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_MV15                                                      0x1800FD60
#define  VP8_P2_VP8_MB_MV15_reg_addr                                             "0xB800FD60"
#define  VP8_P2_VP8_MB_MV15_reg                                                  0xB800FD60
#define  VP8_P2_VP8_MB_MV15_inst_addr                                            "0x0018"
#define  VP8_P2_VP8_MB_MV15_inst_adr                                             "0x0058"
#define  VP8_P2_VP8_MB_MV15_inst                                                 0x0058
#define  set_VP8_P2_VP8_MB_MV15_reg(data)                                        (*((volatile unsigned int*)VP8_P2_VP8_MB_MV15_reg)=data)
#define  get_VP8_P2_VP8_MB_MV15_reg                                              (*((volatile unsigned int*)VP8_P2_VP8_MB_MV15_reg))
#define  VP8_P2_VP8_MB_MV15_mv_x_shift                                           (14)
#define  VP8_P2_VP8_MB_MV15_mv_y_shift                                           (0)
#define  VP8_P2_VP8_MB_MV15_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_VP8_MB_MV15_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_VP8_MB_MV15_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_MV15_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV15_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV15_get_mv_y(data)                                       (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_MV15_mv_x_src(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_MV15_mv_y_src(data)                                       (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_CH_MV0                                                    0x1800FD64
#define  VP8_P2_VP8_MB_CH_MV0_reg_addr                                           "0xB800FD64"
#define  VP8_P2_VP8_MB_CH_MV0_reg                                                0xB800FD64
#define  VP8_P2_VP8_MB_CH_MV0_inst_addr                                          "0x0019"
#define  VP8_P2_VP8_MB_CH_MV0_inst_adr                                           "0x0059"
#define  VP8_P2_VP8_MB_CH_MV0_inst                                               0x0059
#define  set_VP8_P2_VP8_MB_CH_MV0_reg(data)                                      (*((volatile unsigned int*)VP8_P2_VP8_MB_CH_MV0_reg)=data)
#define  get_VP8_P2_VP8_MB_CH_MV0_reg                                            (*((volatile unsigned int*)VP8_P2_VP8_MB_CH_MV0_reg))
#define  VP8_P2_VP8_MB_CH_MV0_mv_x_shift                                         (14)
#define  VP8_P2_VP8_MB_CH_MV0_mv_y_shift                                         (0)
#define  VP8_P2_VP8_MB_CH_MV0_mv_x_mask                                          (0x1FFFC000)
#define  VP8_P2_VP8_MB_CH_MV0_mv_y_mask                                          (0x00003FFF)
#define  VP8_P2_VP8_MB_CH_MV0_mv_x(data)                                         (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_CH_MV0_mv_y(data)                                         (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_CH_MV0_get_mv_x(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_CH_MV0_get_mv_y(data)                                     (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_CH_MV0_mv_x_src(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_CH_MV0_mv_y_src(data)                                     (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_CH_MV1                                                    0x1800FD68
#define  VP8_P2_VP8_MB_CH_MV1_reg_addr                                           "0xB800FD68"
#define  VP8_P2_VP8_MB_CH_MV1_reg                                                0xB800FD68
#define  VP8_P2_VP8_MB_CH_MV1_inst_addr                                          "0x001A"
#define  VP8_P2_VP8_MB_CH_MV1_inst_adr                                           "0x005A"
#define  VP8_P2_VP8_MB_CH_MV1_inst                                               0x005A
#define  set_VP8_P2_VP8_MB_CH_MV1_reg(data)                                      (*((volatile unsigned int*)VP8_P2_VP8_MB_CH_MV1_reg)=data)
#define  get_VP8_P2_VP8_MB_CH_MV1_reg                                            (*((volatile unsigned int*)VP8_P2_VP8_MB_CH_MV1_reg))
#define  VP8_P2_VP8_MB_CH_MV1_mv_x_shift                                         (14)
#define  VP8_P2_VP8_MB_CH_MV1_mv_y_shift                                         (0)
#define  VP8_P2_VP8_MB_CH_MV1_mv_x_mask                                          (0x1FFFC000)
#define  VP8_P2_VP8_MB_CH_MV1_mv_y_mask                                          (0x00003FFF)
#define  VP8_P2_VP8_MB_CH_MV1_mv_x(data)                                         (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_CH_MV1_mv_y(data)                                         (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_CH_MV1_get_mv_x(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_CH_MV1_get_mv_y(data)                                     (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_CH_MV1_mv_x_src(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_CH_MV1_mv_y_src(data)                                     (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_CH_MV2                                                    0x1800FD6C
#define  VP8_P2_VP8_MB_CH_MV2_reg_addr                                           "0xB800FD6C"
#define  VP8_P2_VP8_MB_CH_MV2_reg                                                0xB800FD6C
#define  VP8_P2_VP8_MB_CH_MV2_inst_addr                                          "0x001B"
#define  VP8_P2_VP8_MB_CH_MV2_inst_adr                                           "0x005B"
#define  VP8_P2_VP8_MB_CH_MV2_inst                                               0x005B
#define  set_VP8_P2_VP8_MB_CH_MV2_reg(data)                                      (*((volatile unsigned int*)VP8_P2_VP8_MB_CH_MV2_reg)=data)
#define  get_VP8_P2_VP8_MB_CH_MV2_reg                                            (*((volatile unsigned int*)VP8_P2_VP8_MB_CH_MV2_reg))
#define  VP8_P2_VP8_MB_CH_MV2_mv_x_shift                                         (14)
#define  VP8_P2_VP8_MB_CH_MV2_mv_y_shift                                         (0)
#define  VP8_P2_VP8_MB_CH_MV2_mv_x_mask                                          (0x1FFFC000)
#define  VP8_P2_VP8_MB_CH_MV2_mv_y_mask                                          (0x00003FFF)
#define  VP8_P2_VP8_MB_CH_MV2_mv_x(data)                                         (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_CH_MV2_mv_y(data)                                         (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_CH_MV2_get_mv_x(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_CH_MV2_get_mv_y(data)                                     (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_CH_MV2_mv_x_src(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_CH_MV2_mv_y_src(data)                                     (0x00003FFF&(data))

#define  VP8_P2_VP8_MB_CH_MV3                                                    0x1800FD70
#define  VP8_P2_VP8_MB_CH_MV3_reg_addr                                           "0xB800FD70"
#define  VP8_P2_VP8_MB_CH_MV3_reg                                                0xB800FD70
#define  VP8_P2_VP8_MB_CH_MV3_inst_addr                                          "0x001C"
#define  VP8_P2_VP8_MB_CH_MV3_inst_adr                                           "0x005C"
#define  VP8_P2_VP8_MB_CH_MV3_inst                                               0x005C
#define  set_VP8_P2_VP8_MB_CH_MV3_reg(data)                                      (*((volatile unsigned int*)VP8_P2_VP8_MB_CH_MV3_reg)=data)
#define  get_VP8_P2_VP8_MB_CH_MV3_reg                                            (*((volatile unsigned int*)VP8_P2_VP8_MB_CH_MV3_reg))
#define  VP8_P2_VP8_MB_CH_MV3_mv_x_shift                                         (14)
#define  VP8_P2_VP8_MB_CH_MV3_mv_y_shift                                         (0)
#define  VP8_P2_VP8_MB_CH_MV3_mv_x_mask                                          (0x1FFFC000)
#define  VP8_P2_VP8_MB_CH_MV3_mv_y_mask                                          (0x00003FFF)
#define  VP8_P2_VP8_MB_CH_MV3_mv_x(data)                                         (0x1FFFC000&((data)<<14))
#define  VP8_P2_VP8_MB_CH_MV3_mv_y(data)                                         (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_CH_MV3_get_mv_x(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_CH_MV3_get_mv_y(data)                                     (0x00003FFF&(data))
#define  VP8_P2_VP8_MB_CH_MV3_mv_x_src(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_VP8_MB_CH_MV3_mv_y_src(data)                                     (0x00003FFF&(data))

#ifdef _VP8_P2_USE_STRUCT
#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VP8_P2 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  slice_cnt:8;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  full_pixel:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  ref_frame_sign_bias:4;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  mb_no_coeff_skip:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  segmentation_enabled:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  update_mb_segmentation_map:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  prob_skip_false:8;
    };
}VP8_P2_VP8_P2_FRM1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  prob_gf:8;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  prob_last:8;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  prob_intra:8;
    };
}VP8_P2_VP8_P2_FRM2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  picmb_h:7;
    };
}VP8_P2_VP8_P2_FRM3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  need_to_clamp_mvs:1;
        RBus_UInt32  ref_frame:2;
        RBus_UInt32  uv_mode:2;
        RBus_UInt32  mode:4;
        RBus_UInt32  mb_skip_coeff:1;
        RBus_UInt32  segment_id:2;
    };
}VP8_P2_VP8_P2_MB1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  ndb_p2_flush:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  mby:7;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  left_sub_block_mode:16;
    };
}VP8_P2_VP8_P2_MB2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_blk_mode_p0:32;
    };
}VP8_P2_VP8_P2_SUB_BLK0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_blk_mode_p1:32;
    };
}VP8_P2_VP8_P2_SUB_BLK1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vp8_p2_curmb:9;
        RBus_UInt32  vp8_mbpartition:9;
        RBus_UInt32  vp8_Inter_pred_option:8;
    };
}VP8_P2_VP8_P2_MB_INFO_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  high:9;
        RBus_UInt32  bits:4;
        RBus_UInt32  code_word:16;
    };
}VP8_P2_VP8_BAC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_MV15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_CH_MV0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_CH_MV1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_CH_MV2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}VP8_P2_VP8_MB_CH_MV3_RBUS;

#else //apply LITTLE_ENDIAN

//======VP8_P2 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prob_skip_false:8;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  update_mb_segmentation_map:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  segmentation_enabled:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  mb_no_coeff_skip:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  ref_frame_sign_bias:4;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  full_pixel:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  slice_cnt:8;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  res1:1;
    };
}VP8_P2_VP8_P2_FRM1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prob_intra:8;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  prob_last:8;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  prob_gf:8;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:5;
    };
}VP8_P2_VP8_P2_FRM2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  picmb_h:7;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res1:24;
    };
}VP8_P2_VP8_P2_FRM3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  segment_id:2;
        RBus_UInt32  mb_skip_coeff:1;
        RBus_UInt32  mode:4;
        RBus_UInt32  uv_mode:2;
        RBus_UInt32  ref_frame:2;
        RBus_UInt32  need_to_clamp_mvs:1;
        RBus_UInt32  res1:20;
    };
}VP8_P2_VP8_P2_MB1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_sub_block_mode:16;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mby:7;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  ndb_p2_flush:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:5;
    };
}VP8_P2_VP8_P2_MB2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_blk_mode_p0:32;
    };
}VP8_P2_VP8_P2_SUB_BLK0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_blk_mode_p1:32;
    };
}VP8_P2_VP8_P2_SUB_BLK1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vp8_Inter_pred_option:8;
        RBus_UInt32  vp8_mbpartition:9;
        RBus_UInt32  vp8_p2_curmb:9;
        RBus_UInt32  res1:6;
    };
}VP8_P2_VP8_P2_MB_INFO_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  code_word:16;
        RBus_UInt32  bits:4;
        RBus_UInt32  high:9;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_BAC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_MV15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_CH_MV0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_CH_MV1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_CH_MV2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}VP8_P2_VP8_MB_CH_MV3_RBUS;




#endif 


#endif 
#endif 
