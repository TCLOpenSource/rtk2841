/**
* @file Mac5_VE_VP8P2_arch_spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VP8_P2_REG_H_
#define _RBUS_VP8_P2_REG_H_

#include "rbus_types.h"



//  VP8_P2 Register Address
#define  VP8_P2_vp8_p2_frm1                                                      0x1800FD00
#define  VP8_P2_vp8_p2_frm1_reg_addr                                             "0xB800FD00"
#define  VP8_P2_vp8_p2_frm1_reg                                                  0xB800FD00
#define  VP8_P2_vp8_p2_frm1_inst_addr                                            "0x0000"
#define  set_VP8_P2_vp8_p2_frm1_reg(data)                                        (*((volatile unsigned int*)VP8_P2_vp8_p2_frm1_reg)=data)
#define  get_VP8_P2_vp8_p2_frm1_reg                                              (*((volatile unsigned int*)VP8_P2_vp8_p2_frm1_reg))
#define  VP8_P2_vp8_p2_frm1_write_enable7_shift                                  (30)
#define  VP8_P2_vp8_p2_frm1_slice_cnt_shift                                      (22)
#define  VP8_P2_vp8_p2_frm1_write_enable6_shift                                  (21)
#define  VP8_P2_vp8_p2_frm1_full_pixel_shift                                     (20)
#define  VP8_P2_vp8_p2_frm1_write_enable5_shift                                  (19)
#define  VP8_P2_vp8_p2_frm1_ref_frame_sign_bias_shift                            (15)
#define  VP8_P2_vp8_p2_frm1_write_enable4_shift                                  (14)
#define  VP8_P2_vp8_p2_frm1_mb_no_coeff_skip_shift                               (13)
#define  VP8_P2_vp8_p2_frm1_write_enable3_shift                                  (12)
#define  VP8_P2_vp8_p2_frm1_segmentation_enabled_shift                           (11)
#define  VP8_P2_vp8_p2_frm1_write_enable2_shift                                  (10)
#define  VP8_P2_vp8_p2_frm1_update_mb_segmentation_map_shift                     (9)
#define  VP8_P2_vp8_p2_frm1_write_enable1_shift                                  (8)
#define  VP8_P2_vp8_p2_frm1_prob_skip_false_shift                                (0)
#define  VP8_P2_vp8_p2_frm1_write_enable7_mask                                   (0x40000000)
#define  VP8_P2_vp8_p2_frm1_slice_cnt_mask                                       (0x3FC00000)
#define  VP8_P2_vp8_p2_frm1_write_enable6_mask                                   (0x00200000)
#define  VP8_P2_vp8_p2_frm1_full_pixel_mask                                      (0x00100000)
#define  VP8_P2_vp8_p2_frm1_write_enable5_mask                                   (0x00080000)
#define  VP8_P2_vp8_p2_frm1_ref_frame_sign_bias_mask                             (0x00078000)
#define  VP8_P2_vp8_p2_frm1_write_enable4_mask                                   (0x00004000)
#define  VP8_P2_vp8_p2_frm1_mb_no_coeff_skip_mask                                (0x00002000)
#define  VP8_P2_vp8_p2_frm1_write_enable3_mask                                   (0x00001000)
#define  VP8_P2_vp8_p2_frm1_segmentation_enabled_mask                            (0x00000800)
#define  VP8_P2_vp8_p2_frm1_write_enable2_mask                                   (0x00000400)
#define  VP8_P2_vp8_p2_frm1_update_mb_segmentation_map_mask                      (0x00000200)
#define  VP8_P2_vp8_p2_frm1_write_enable1_mask                                   (0x00000100)
#define  VP8_P2_vp8_p2_frm1_prob_skip_false_mask                                 (0x000000FF)
#define  VP8_P2_vp8_p2_frm1_write_enable7(data)                                  (0x40000000&((data)<<30))
#define  VP8_P2_vp8_p2_frm1_slice_cnt(data)                                      (0x3FC00000&((data)<<22))
#define  VP8_P2_vp8_p2_frm1_write_enable6(data)                                  (0x00200000&((data)<<21))
#define  VP8_P2_vp8_p2_frm1_full_pixel(data)                                     (0x00100000&((data)<<20))
#define  VP8_P2_vp8_p2_frm1_write_enable5(data)                                  (0x00080000&((data)<<19))
#define  VP8_P2_vp8_p2_frm1_ref_frame_sign_bias(data)                            (0x00078000&((data)<<15))
#define  VP8_P2_vp8_p2_frm1_write_enable4(data)                                  (0x00004000&((data)<<14))
#define  VP8_P2_vp8_p2_frm1_mb_no_coeff_skip(data)                               (0x00002000&((data)<<13))
#define  VP8_P2_vp8_p2_frm1_write_enable3(data)                                  (0x00001000&((data)<<12))
#define  VP8_P2_vp8_p2_frm1_segmentation_enabled(data)                           (0x00000800&((data)<<11))
#define  VP8_P2_vp8_p2_frm1_write_enable2(data)                                  (0x00000400&((data)<<10))
#define  VP8_P2_vp8_p2_frm1_update_mb_segmentation_map(data)                     (0x00000200&((data)<<9))
#define  VP8_P2_vp8_p2_frm1_write_enable1(data)                                  (0x00000100&((data)<<8))
#define  VP8_P2_vp8_p2_frm1_prob_skip_false(data)                                (0x000000FF&(data))
#define  VP8_P2_vp8_p2_frm1_get_write_enable7(data)                              ((0x40000000&(data))>>30)
#define  VP8_P2_vp8_p2_frm1_get_slice_cnt(data)                                  ((0x3FC00000&(data))>>22)
#define  VP8_P2_vp8_p2_frm1_get_write_enable6(data)                              ((0x00200000&(data))>>21)
#define  VP8_P2_vp8_p2_frm1_get_full_pixel(data)                                 ((0x00100000&(data))>>20)
#define  VP8_P2_vp8_p2_frm1_get_write_enable5(data)                              ((0x00080000&(data))>>19)
#define  VP8_P2_vp8_p2_frm1_get_ref_frame_sign_bias(data)                        ((0x00078000&(data))>>15)
#define  VP8_P2_vp8_p2_frm1_get_write_enable4(data)                              ((0x00004000&(data))>>14)
#define  VP8_P2_vp8_p2_frm1_get_mb_no_coeff_skip(data)                           ((0x00002000&(data))>>13)
#define  VP8_P2_vp8_p2_frm1_get_write_enable3(data)                              ((0x00001000&(data))>>12)
#define  VP8_P2_vp8_p2_frm1_get_segmentation_enabled(data)                       ((0x00000800&(data))>>11)
#define  VP8_P2_vp8_p2_frm1_get_write_enable2(data)                              ((0x00000400&(data))>>10)
#define  VP8_P2_vp8_p2_frm1_get_update_mb_segmentation_map(data)                 ((0x00000200&(data))>>9)
#define  VP8_P2_vp8_p2_frm1_get_write_enable1(data)                              ((0x00000100&(data))>>8)
#define  VP8_P2_vp8_p2_frm1_get_prob_skip_false(data)                            (0x000000FF&(data))

#define  VP8_P2_vp8_p2_frm2                                                      0x1800FD04
#define  VP8_P2_vp8_p2_frm2_reg_addr                                             "0xB800FD04"
#define  VP8_P2_vp8_p2_frm2_reg                                                  0xB800FD04
#define  VP8_P2_vp8_p2_frm2_inst_addr                                            "0x0001"
#define  set_VP8_P2_vp8_p2_frm2_reg(data)                                        (*((volatile unsigned int*)VP8_P2_vp8_p2_frm2_reg)=data)
#define  get_VP8_P2_vp8_p2_frm2_reg                                              (*((volatile unsigned int*)VP8_P2_vp8_p2_frm2_reg))
#define  VP8_P2_vp8_p2_frm2_write_enable3_shift                                  (26)
#define  VP8_P2_vp8_p2_frm2_prob_gf_shift                                        (18)
#define  VP8_P2_vp8_p2_frm2_write_enable2_shift                                  (17)
#define  VP8_P2_vp8_p2_frm2_prob_last_shift                                      (9)
#define  VP8_P2_vp8_p2_frm2_write_enable1_shift                                  (8)
#define  VP8_P2_vp8_p2_frm2_prob_intra_shift                                     (0)
#define  VP8_P2_vp8_p2_frm2_write_enable3_mask                                   (0x04000000)
#define  VP8_P2_vp8_p2_frm2_prob_gf_mask                                         (0x03FC0000)
#define  VP8_P2_vp8_p2_frm2_write_enable2_mask                                   (0x00020000)
#define  VP8_P2_vp8_p2_frm2_prob_last_mask                                       (0x0001FE00)
#define  VP8_P2_vp8_p2_frm2_write_enable1_mask                                   (0x00000100)
#define  VP8_P2_vp8_p2_frm2_prob_intra_mask                                      (0x000000FF)
#define  VP8_P2_vp8_p2_frm2_write_enable3(data)                                  (0x04000000&((data)<<26))
#define  VP8_P2_vp8_p2_frm2_prob_gf(data)                                        (0x03FC0000&((data)<<18))
#define  VP8_P2_vp8_p2_frm2_write_enable2(data)                                  (0x00020000&((data)<<17))
#define  VP8_P2_vp8_p2_frm2_prob_last(data)                                      (0x0001FE00&((data)<<9))
#define  VP8_P2_vp8_p2_frm2_write_enable1(data)                                  (0x00000100&((data)<<8))
#define  VP8_P2_vp8_p2_frm2_prob_intra(data)                                     (0x000000FF&(data))
#define  VP8_P2_vp8_p2_frm2_get_write_enable3(data)                              ((0x04000000&(data))>>26)
#define  VP8_P2_vp8_p2_frm2_get_prob_gf(data)                                    ((0x03FC0000&(data))>>18)
#define  VP8_P2_vp8_p2_frm2_get_write_enable2(data)                              ((0x00020000&(data))>>17)
#define  VP8_P2_vp8_p2_frm2_get_prob_last(data)                                  ((0x0001FE00&(data))>>9)
#define  VP8_P2_vp8_p2_frm2_get_write_enable1(data)                              ((0x00000100&(data))>>8)
#define  VP8_P2_vp8_p2_frm2_get_prob_intra(data)                                 (0x000000FF&(data))

#define  VP8_P2_vp8_p2_frm3                                                      0x1800FD08
#define  VP8_P2_vp8_p2_frm3_reg_addr                                             "0xB800FD08"
#define  VP8_P2_vp8_p2_frm3_reg                                                  0xB800FD08
#define  VP8_P2_vp8_p2_frm3_inst_addr                                            "0x0002"
#define  set_VP8_P2_vp8_p2_frm3_reg(data)                                        (*((volatile unsigned int*)VP8_P2_vp8_p2_frm3_reg)=data)
#define  get_VP8_P2_vp8_p2_frm3_reg                                              (*((volatile unsigned int*)VP8_P2_vp8_p2_frm3_reg))
#define  VP8_P2_vp8_p2_frm3_write_enable1_shift                                  (7)
#define  VP8_P2_vp8_p2_frm3_picmb_h_shift                                        (0)
#define  VP8_P2_vp8_p2_frm3_write_enable1_mask                                   (0x00000080)
#define  VP8_P2_vp8_p2_frm3_picmb_h_mask                                         (0x0000007F)
#define  VP8_P2_vp8_p2_frm3_write_enable1(data)                                  (0x00000080&((data)<<7))
#define  VP8_P2_vp8_p2_frm3_picmb_h(data)                                        (0x0000007F&(data))
#define  VP8_P2_vp8_p2_frm3_get_write_enable1(data)                              ((0x00000080&(data))>>7)
#define  VP8_P2_vp8_p2_frm3_get_picmb_h(data)                                    (0x0000007F&(data))

#define  VP8_P2_vp8_p2_mb1                                                       0x1800FD0C
#define  VP8_P2_vp8_p2_mb1_reg_addr                                              "0xB800FD0C"
#define  VP8_P2_vp8_p2_mb1_reg                                                   0xB800FD0C
#define  VP8_P2_vp8_p2_mb1_inst_addr                                             "0x0003"
#define  set_VP8_P2_vp8_p2_mb1_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_p2_mb1_reg)=data)
#define  get_VP8_P2_vp8_p2_mb1_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_p2_mb1_reg))
#define  VP8_P2_vp8_p2_mb1_need_to_clamp_mvs_shift                               (11)
#define  VP8_P2_vp8_p2_mb1_ref_frame_shift                                       (9)
#define  VP8_P2_vp8_p2_mb1_uv_mode_shift                                         (7)
#define  VP8_P2_vp8_p2_mb1_mode_shift                                            (3)
#define  VP8_P2_vp8_p2_mb1_mb_skip_coeff_shift                                   (2)
#define  VP8_P2_vp8_p2_mb1_segment_id_shift                                      (0)
#define  VP8_P2_vp8_p2_mb1_need_to_clamp_mvs_mask                                (0x00000800)
#define  VP8_P2_vp8_p2_mb1_ref_frame_mask                                        (0x00000600)
#define  VP8_P2_vp8_p2_mb1_uv_mode_mask                                          (0x00000180)
#define  VP8_P2_vp8_p2_mb1_mode_mask                                             (0x00000078)
#define  VP8_P2_vp8_p2_mb1_mb_skip_coeff_mask                                    (0x00000004)
#define  VP8_P2_vp8_p2_mb1_segment_id_mask                                       (0x00000003)
#define  VP8_P2_vp8_p2_mb1_need_to_clamp_mvs(data)                               (0x00000800&((data)<<11))
#define  VP8_P2_vp8_p2_mb1_ref_frame(data)                                       (0x00000600&((data)<<9))
#define  VP8_P2_vp8_p2_mb1_uv_mode(data)                                         (0x00000180&((data)<<7))
#define  VP8_P2_vp8_p2_mb1_mode(data)                                            (0x00000078&((data)<<3))
#define  VP8_P2_vp8_p2_mb1_mb_skip_coeff(data)                                   (0x00000004&((data)<<2))
#define  VP8_P2_vp8_p2_mb1_segment_id(data)                                      (0x00000003&(data))
#define  VP8_P2_vp8_p2_mb1_get_need_to_clamp_mvs(data)                           ((0x00000800&(data))>>11)
#define  VP8_P2_vp8_p2_mb1_get_ref_frame(data)                                   ((0x00000600&(data))>>9)
#define  VP8_P2_vp8_p2_mb1_get_uv_mode(data)                                     ((0x00000180&(data))>>7)
#define  VP8_P2_vp8_p2_mb1_get_mode(data)                                        ((0x00000078&(data))>>3)
#define  VP8_P2_vp8_p2_mb1_get_mb_skip_coeff(data)                               ((0x00000004&(data))>>2)
#define  VP8_P2_vp8_p2_mb1_get_segment_id(data)                                  (0x00000003&(data))

#define  VP8_P2_vp8_p2_mb2                                                       0x1800FD10
#define  VP8_P2_vp8_p2_mb2_reg_addr                                              "0xB800FD10"
#define  VP8_P2_vp8_p2_mb2_reg                                                   0xB800FD10
#define  VP8_P2_vp8_p2_mb2_inst_addr                                             "0x0004"
#define  set_VP8_P2_vp8_p2_mb2_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_p2_mb2_reg)=data)
#define  get_VP8_P2_vp8_p2_mb2_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_p2_mb2_reg))
#define  VP8_P2_vp8_p2_mb2_write_enable3_shift                                   (26)
#define  VP8_P2_vp8_p2_mb2_ndb_p2_flush_shift                                    (25)
#define  VP8_P2_vp8_p2_mb2_write_enable2_shift                                   (24)
#define  VP8_P2_vp8_p2_mb2_mby_shift                                             (17)
#define  VP8_P2_vp8_p2_mb2_write_enable1_shift                                   (16)
#define  VP8_P2_vp8_p2_mb2_left_sub_block_mode_shift                             (0)
#define  VP8_P2_vp8_p2_mb2_write_enable3_mask                                    (0x04000000)
#define  VP8_P2_vp8_p2_mb2_ndb_p2_flush_mask                                     (0x02000000)
#define  VP8_P2_vp8_p2_mb2_write_enable2_mask                                    (0x01000000)
#define  VP8_P2_vp8_p2_mb2_mby_mask                                              (0x00FE0000)
#define  VP8_P2_vp8_p2_mb2_write_enable1_mask                                    (0x00010000)
#define  VP8_P2_vp8_p2_mb2_left_sub_block_mode_mask                              (0x0000FFFF)
#define  VP8_P2_vp8_p2_mb2_write_enable3(data)                                   (0x04000000&((data)<<26))
#define  VP8_P2_vp8_p2_mb2_ndb_p2_flush(data)                                    (0x02000000&((data)<<25))
#define  VP8_P2_vp8_p2_mb2_write_enable2(data)                                   (0x01000000&((data)<<24))
#define  VP8_P2_vp8_p2_mb2_mby(data)                                             (0x00FE0000&((data)<<17))
#define  VP8_P2_vp8_p2_mb2_write_enable1(data)                                   (0x00010000&((data)<<16))
#define  VP8_P2_vp8_p2_mb2_left_sub_block_mode(data)                             (0x0000FFFF&(data))
#define  VP8_P2_vp8_p2_mb2_get_write_enable3(data)                               ((0x04000000&(data))>>26)
#define  VP8_P2_vp8_p2_mb2_get_ndb_p2_flush(data)                                ((0x02000000&(data))>>25)
#define  VP8_P2_vp8_p2_mb2_get_write_enable2(data)                               ((0x01000000&(data))>>24)
#define  VP8_P2_vp8_p2_mb2_get_mby(data)                                         ((0x00FE0000&(data))>>17)
#define  VP8_P2_vp8_p2_mb2_get_write_enable1(data)                               ((0x00010000&(data))>>16)
#define  VP8_P2_vp8_p2_mb2_get_left_sub_block_mode(data)                         (0x0000FFFF&(data))

#define  VP8_P2_vp8_p2_sub_blk0                                                  0x1800FD14
#define  VP8_P2_vp8_p2_sub_blk0_reg_addr                                         "0xB800FD14"
#define  VP8_P2_vp8_p2_sub_blk0_reg                                              0xB800FD14
#define  VP8_P2_vp8_p2_sub_blk0_inst_addr                                        "0x0005"
#define  set_VP8_P2_vp8_p2_sub_blk0_reg(data)                                    (*((volatile unsigned int*)VP8_P2_vp8_p2_sub_blk0_reg)=data)
#define  get_VP8_P2_vp8_p2_sub_blk0_reg                                          (*((volatile unsigned int*)VP8_P2_vp8_p2_sub_blk0_reg))
#define  VP8_P2_vp8_p2_sub_blk0_sub_blk_mode_p0_shift                            (0)
#define  VP8_P2_vp8_p2_sub_blk0_sub_blk_mode_p0_mask                             (0xFFFFFFFF)
#define  VP8_P2_vp8_p2_sub_blk0_sub_blk_mode_p0(data)                            (0xFFFFFFFF&(data))
#define  VP8_P2_vp8_p2_sub_blk0_get_sub_blk_mode_p0(data)                        (0xFFFFFFFF&(data))

#define  VP8_P2_vp8_p2_sub_blk1                                                  0x1800FD18
#define  VP8_P2_vp8_p2_sub_blk1_reg_addr                                         "0xB800FD18"
#define  VP8_P2_vp8_p2_sub_blk1_reg                                              0xB800FD18
#define  VP8_P2_vp8_p2_sub_blk1_inst_addr                                        "0x0006"
#define  set_VP8_P2_vp8_p2_sub_blk1_reg(data)                                    (*((volatile unsigned int*)VP8_P2_vp8_p2_sub_blk1_reg)=data)
#define  get_VP8_P2_vp8_p2_sub_blk1_reg                                          (*((volatile unsigned int*)VP8_P2_vp8_p2_sub_blk1_reg))
#define  VP8_P2_vp8_p2_sub_blk1_sub_blk_mode_p1_shift                            (0)
#define  VP8_P2_vp8_p2_sub_blk1_sub_blk_mode_p1_mask                             (0xFFFFFFFF)
#define  VP8_P2_vp8_p2_sub_blk1_sub_blk_mode_p1(data)                            (0xFFFFFFFF&(data))
#define  VP8_P2_vp8_p2_sub_blk1_get_sub_blk_mode_p1(data)                        (0xFFFFFFFF&(data))

#define  VP8_P2_vp8_p2_mb_info                                                   0x1800FD1C
#define  VP8_P2_vp8_p2_mb_info_reg_addr                                          "0xB800FD1C"
#define  VP8_P2_vp8_p2_mb_info_reg                                               0xB800FD1C
#define  VP8_P2_vp8_p2_mb_info_inst_addr                                         "0x0007"
#define  set_VP8_P2_vp8_p2_mb_info_reg(data)                                     (*((volatile unsigned int*)VP8_P2_vp8_p2_mb_info_reg)=data)
#define  get_VP8_P2_vp8_p2_mb_info_reg                                           (*((volatile unsigned int*)VP8_P2_vp8_p2_mb_info_reg))
#define  VP8_P2_vp8_p2_mb_info_vp8_p2_curmb_shift                                (17)
#define  VP8_P2_vp8_p2_mb_info_vp8_mbpartition_shift                             (8)
#define  VP8_P2_vp8_p2_mb_info_vp8_inter_pred_option_shift                       (0)
#define  VP8_P2_vp8_p2_mb_info_vp8_p2_curmb_mask                                 (0x03FE0000)
#define  VP8_P2_vp8_p2_mb_info_vp8_mbpartition_mask                              (0x0001FF00)
#define  VP8_P2_vp8_p2_mb_info_vp8_inter_pred_option_mask                        (0x000000FF)
#define  VP8_P2_vp8_p2_mb_info_vp8_p2_curmb(data)                                (0x03FE0000&((data)<<17))
#define  VP8_P2_vp8_p2_mb_info_vp8_mbpartition(data)                             (0x0001FF00&((data)<<8))
#define  VP8_P2_vp8_p2_mb_info_vp8_inter_pred_option(data)                       (0x000000FF&(data))
#define  VP8_P2_vp8_p2_mb_info_get_vp8_p2_curmb(data)                            ((0x03FE0000&(data))>>17)
#define  VP8_P2_vp8_p2_mb_info_get_vp8_mbpartition(data)                         ((0x0001FF00&(data))>>8)
#define  VP8_P2_vp8_p2_mb_info_get_vp8_inter_pred_option(data)                   (0x000000FF&(data))

#define  VP8_P2_vp8_bac                                                          0x1800FD20
#define  VP8_P2_vp8_bac_reg_addr                                                 "0xB800FD20"
#define  VP8_P2_vp8_bac_reg                                                      0xB800FD20
#define  VP8_P2_vp8_bac_inst_addr                                                "0x0008"
#define  set_VP8_P2_vp8_bac_reg(data)                                            (*((volatile unsigned int*)VP8_P2_vp8_bac_reg)=data)
#define  get_VP8_P2_vp8_bac_reg                                                  (*((volatile unsigned int*)VP8_P2_vp8_bac_reg))
#define  VP8_P2_vp8_bac_high_shift                                               (20)
#define  VP8_P2_vp8_bac_bits_shift                                               (16)
#define  VP8_P2_vp8_bac_code_word_shift                                          (0)
#define  VP8_P2_vp8_bac_high_mask                                                (0x1FF00000)
#define  VP8_P2_vp8_bac_bits_mask                                                (0x000F0000)
#define  VP8_P2_vp8_bac_code_word_mask                                           (0x0000FFFF)
#define  VP8_P2_vp8_bac_high(data)                                               (0x1FF00000&((data)<<20))
#define  VP8_P2_vp8_bac_bits(data)                                               (0x000F0000&((data)<<16))
#define  VP8_P2_vp8_bac_code_word(data)                                          (0x0000FFFF&(data))
#define  VP8_P2_vp8_bac_get_high(data)                                           ((0x1FF00000&(data))>>20)
#define  VP8_P2_vp8_bac_get_bits(data)                                           ((0x000F0000&(data))>>16)
#define  VP8_P2_vp8_bac_get_code_word(data)                                      (0x0000FFFF&(data))

#define  VP8_P2_vp8_mb_mv0                                                       0x1800FD24
#define  VP8_P2_vp8_mb_mv0_reg_addr                                              "0xB800FD24"
#define  VP8_P2_vp8_mb_mv0_reg                                                   0xB800FD24
#define  VP8_P2_vp8_mb_mv0_inst_addr                                             "0x0009"
#define  set_VP8_P2_vp8_mb_mv0_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv0_reg)=data)
#define  get_VP8_P2_vp8_mb_mv0_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv0_reg))
#define  VP8_P2_vp8_mb_mv0_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv0_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv0_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv0_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv0_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv0_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv0_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv0_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv1                                                       0x1800FD28
#define  VP8_P2_vp8_mb_mv1_reg_addr                                              "0xB800FD28"
#define  VP8_P2_vp8_mb_mv1_reg                                                   0xB800FD28
#define  VP8_P2_vp8_mb_mv1_inst_addr                                             "0x000A"
#define  set_VP8_P2_vp8_mb_mv1_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv1_reg)=data)
#define  get_VP8_P2_vp8_mb_mv1_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv1_reg))
#define  VP8_P2_vp8_mb_mv1_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv1_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv1_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv1_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv1_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv1_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv1_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv1_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv2                                                       0x1800FD2C
#define  VP8_P2_vp8_mb_mv2_reg_addr                                              "0xB800FD2C"
#define  VP8_P2_vp8_mb_mv2_reg                                                   0xB800FD2C
#define  VP8_P2_vp8_mb_mv2_inst_addr                                             "0x000B"
#define  set_VP8_P2_vp8_mb_mv2_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv2_reg)=data)
#define  get_VP8_P2_vp8_mb_mv2_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv2_reg))
#define  VP8_P2_vp8_mb_mv2_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv2_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv2_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv2_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv2_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv2_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv2_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv2_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv3                                                       0x1800FD30
#define  VP8_P2_vp8_mb_mv3_reg_addr                                              "0xB800FD30"
#define  VP8_P2_vp8_mb_mv3_reg                                                   0xB800FD30
#define  VP8_P2_vp8_mb_mv3_inst_addr                                             "0x000C"
#define  set_VP8_P2_vp8_mb_mv3_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv3_reg)=data)
#define  get_VP8_P2_vp8_mb_mv3_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv3_reg))
#define  VP8_P2_vp8_mb_mv3_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv3_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv3_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv3_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv3_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv3_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv3_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv3_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv4                                                       0x1800FD34
#define  VP8_P2_vp8_mb_mv4_reg_addr                                              "0xB800FD34"
#define  VP8_P2_vp8_mb_mv4_reg                                                   0xB800FD34
#define  VP8_P2_vp8_mb_mv4_inst_addr                                             "0x000D"
#define  set_VP8_P2_vp8_mb_mv4_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv4_reg)=data)
#define  get_VP8_P2_vp8_mb_mv4_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv4_reg))
#define  VP8_P2_vp8_mb_mv4_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv4_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv4_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv4_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv4_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv4_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv4_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv4_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv5                                                       0x1800FD38
#define  VP8_P2_vp8_mb_mv5_reg_addr                                              "0xB800FD38"
#define  VP8_P2_vp8_mb_mv5_reg                                                   0xB800FD38
#define  VP8_P2_vp8_mb_mv5_inst_addr                                             "0x000E"
#define  set_VP8_P2_vp8_mb_mv5_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv5_reg)=data)
#define  get_VP8_P2_vp8_mb_mv5_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv5_reg))
#define  VP8_P2_vp8_mb_mv5_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv5_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv5_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv5_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv5_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv5_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv5_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv5_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv6                                                       0x1800FD3C
#define  VP8_P2_vp8_mb_mv6_reg_addr                                              "0xB800FD3C"
#define  VP8_P2_vp8_mb_mv6_reg                                                   0xB800FD3C
#define  VP8_P2_vp8_mb_mv6_inst_addr                                             "0x000F"
#define  set_VP8_P2_vp8_mb_mv6_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv6_reg)=data)
#define  get_VP8_P2_vp8_mb_mv6_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv6_reg))
#define  VP8_P2_vp8_mb_mv6_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv6_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv6_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv6_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv6_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv6_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv6_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv6_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv7                                                       0x1800FD40
#define  VP8_P2_vp8_mb_mv7_reg_addr                                              "0xB800FD40"
#define  VP8_P2_vp8_mb_mv7_reg                                                   0xB800FD40
#define  VP8_P2_vp8_mb_mv7_inst_addr                                             "0x0010"
#define  set_VP8_P2_vp8_mb_mv7_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv7_reg)=data)
#define  get_VP8_P2_vp8_mb_mv7_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv7_reg))
#define  VP8_P2_vp8_mb_mv7_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv7_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv7_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv7_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv7_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv7_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv7_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv7_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv8                                                       0x1800FD44
#define  VP8_P2_vp8_mb_mv8_reg_addr                                              "0xB800FD44"
#define  VP8_P2_vp8_mb_mv8_reg                                                   0xB800FD44
#define  VP8_P2_vp8_mb_mv8_inst_addr                                             "0x0011"
#define  set_VP8_P2_vp8_mb_mv8_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv8_reg)=data)
#define  get_VP8_P2_vp8_mb_mv8_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv8_reg))
#define  VP8_P2_vp8_mb_mv8_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv8_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv8_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv8_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv8_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv8_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv8_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv8_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv9                                                       0x1800FD48
#define  VP8_P2_vp8_mb_mv9_reg_addr                                              "0xB800FD48"
#define  VP8_P2_vp8_mb_mv9_reg                                                   0xB800FD48
#define  VP8_P2_vp8_mb_mv9_inst_addr                                             "0x0012"
#define  set_VP8_P2_vp8_mb_mv9_reg(data)                                         (*((volatile unsigned int*)VP8_P2_vp8_mb_mv9_reg)=data)
#define  get_VP8_P2_vp8_mb_mv9_reg                                               (*((volatile unsigned int*)VP8_P2_vp8_mb_mv9_reg))
#define  VP8_P2_vp8_mb_mv9_mv_x_shift                                            (14)
#define  VP8_P2_vp8_mb_mv9_mv_y_shift                                            (0)
#define  VP8_P2_vp8_mb_mv9_mv_x_mask                                             (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv9_mv_y_mask                                             (0x00003FFF)
#define  VP8_P2_vp8_mb_mv9_mv_x(data)                                            (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv9_mv_y(data)                                            (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv9_get_mv_x(data)                                        ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv9_get_mv_y(data)                                        (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv10                                                      0x1800FD4C
#define  VP8_P2_vp8_mb_mv10_reg_addr                                             "0xB800FD4C"
#define  VP8_P2_vp8_mb_mv10_reg                                                  0xB800FD4C
#define  VP8_P2_vp8_mb_mv10_inst_addr                                            "0x0013"
#define  set_VP8_P2_vp8_mb_mv10_reg(data)                                        (*((volatile unsigned int*)VP8_P2_vp8_mb_mv10_reg)=data)
#define  get_VP8_P2_vp8_mb_mv10_reg                                              (*((volatile unsigned int*)VP8_P2_vp8_mb_mv10_reg))
#define  VP8_P2_vp8_mb_mv10_mv_x_shift                                           (14)
#define  VP8_P2_vp8_mb_mv10_mv_y_shift                                           (0)
#define  VP8_P2_vp8_mb_mv10_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv10_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_vp8_mb_mv10_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv10_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv10_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv10_get_mv_y(data)                                       (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv11                                                      0x1800FD50
#define  VP8_P2_vp8_mb_mv11_reg_addr                                             "0xB800FD50"
#define  VP8_P2_vp8_mb_mv11_reg                                                  0xB800FD50
#define  VP8_P2_vp8_mb_mv11_inst_addr                                            "0x0014"
#define  set_VP8_P2_vp8_mb_mv11_reg(data)                                        (*((volatile unsigned int*)VP8_P2_vp8_mb_mv11_reg)=data)
#define  get_VP8_P2_vp8_mb_mv11_reg                                              (*((volatile unsigned int*)VP8_P2_vp8_mb_mv11_reg))
#define  VP8_P2_vp8_mb_mv11_mv_x_shift                                           (14)
#define  VP8_P2_vp8_mb_mv11_mv_y_shift                                           (0)
#define  VP8_P2_vp8_mb_mv11_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv11_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_vp8_mb_mv11_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv11_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv11_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv11_get_mv_y(data)                                       (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv12                                                      0x1800FD54
#define  VP8_P2_vp8_mb_mv12_reg_addr                                             "0xB800FD54"
#define  VP8_P2_vp8_mb_mv12_reg                                                  0xB800FD54
#define  VP8_P2_vp8_mb_mv12_inst_addr                                            "0x0015"
#define  set_VP8_P2_vp8_mb_mv12_reg(data)                                        (*((volatile unsigned int*)VP8_P2_vp8_mb_mv12_reg)=data)
#define  get_VP8_P2_vp8_mb_mv12_reg                                              (*((volatile unsigned int*)VP8_P2_vp8_mb_mv12_reg))
#define  VP8_P2_vp8_mb_mv12_mv_x_shift                                           (14)
#define  VP8_P2_vp8_mb_mv12_mv_y_shift                                           (0)
#define  VP8_P2_vp8_mb_mv12_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv12_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_vp8_mb_mv12_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv12_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv12_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv12_get_mv_y(data)                                       (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv13                                                      0x1800FD58
#define  VP8_P2_vp8_mb_mv13_reg_addr                                             "0xB800FD58"
#define  VP8_P2_vp8_mb_mv13_reg                                                  0xB800FD58
#define  VP8_P2_vp8_mb_mv13_inst_addr                                            "0x0016"
#define  set_VP8_P2_vp8_mb_mv13_reg(data)                                        (*((volatile unsigned int*)VP8_P2_vp8_mb_mv13_reg)=data)
#define  get_VP8_P2_vp8_mb_mv13_reg                                              (*((volatile unsigned int*)VP8_P2_vp8_mb_mv13_reg))
#define  VP8_P2_vp8_mb_mv13_mv_x_shift                                           (14)
#define  VP8_P2_vp8_mb_mv13_mv_y_shift                                           (0)
#define  VP8_P2_vp8_mb_mv13_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv13_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_vp8_mb_mv13_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv13_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv13_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv13_get_mv_y(data)                                       (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv14                                                      0x1800FD5C
#define  VP8_P2_vp8_mb_mv14_reg_addr                                             "0xB800FD5C"
#define  VP8_P2_vp8_mb_mv14_reg                                                  0xB800FD5C
#define  VP8_P2_vp8_mb_mv14_inst_addr                                            "0x0017"
#define  set_VP8_P2_vp8_mb_mv14_reg(data)                                        (*((volatile unsigned int*)VP8_P2_vp8_mb_mv14_reg)=data)
#define  get_VP8_P2_vp8_mb_mv14_reg                                              (*((volatile unsigned int*)VP8_P2_vp8_mb_mv14_reg))
#define  VP8_P2_vp8_mb_mv14_mv_x_shift                                           (14)
#define  VP8_P2_vp8_mb_mv14_mv_y_shift                                           (0)
#define  VP8_P2_vp8_mb_mv14_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv14_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_vp8_mb_mv14_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv14_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv14_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv14_get_mv_y(data)                                       (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_mv15                                                      0x1800FD60
#define  VP8_P2_vp8_mb_mv15_reg_addr                                             "0xB800FD60"
#define  VP8_P2_vp8_mb_mv15_reg                                                  0xB800FD60
#define  VP8_P2_vp8_mb_mv15_inst_addr                                            "0x0018"
#define  set_VP8_P2_vp8_mb_mv15_reg(data)                                        (*((volatile unsigned int*)VP8_P2_vp8_mb_mv15_reg)=data)
#define  get_VP8_P2_vp8_mb_mv15_reg                                              (*((volatile unsigned int*)VP8_P2_vp8_mb_mv15_reg))
#define  VP8_P2_vp8_mb_mv15_mv_x_shift                                           (14)
#define  VP8_P2_vp8_mb_mv15_mv_y_shift                                           (0)
#define  VP8_P2_vp8_mb_mv15_mv_x_mask                                            (0x1FFFC000)
#define  VP8_P2_vp8_mb_mv15_mv_y_mask                                            (0x00003FFF)
#define  VP8_P2_vp8_mb_mv15_mv_x(data)                                           (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_mv15_mv_y(data)                                           (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_mv15_get_mv_x(data)                                       ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_mv15_get_mv_y(data)                                       (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_ch_mv0                                                    0x1800FD64
#define  VP8_P2_vp8_mb_ch_mv0_reg_addr                                           "0xB800FD64"
#define  VP8_P2_vp8_mb_ch_mv0_reg                                                0xB800FD64
#define  VP8_P2_vp8_mb_ch_mv0_inst_addr                                          "0x0019"
#define  set_VP8_P2_vp8_mb_ch_mv0_reg(data)                                      (*((volatile unsigned int*)VP8_P2_vp8_mb_ch_mv0_reg)=data)
#define  get_VP8_P2_vp8_mb_ch_mv0_reg                                            (*((volatile unsigned int*)VP8_P2_vp8_mb_ch_mv0_reg))
#define  VP8_P2_vp8_mb_ch_mv0_mv_x_shift                                         (14)
#define  VP8_P2_vp8_mb_ch_mv0_mv_y_shift                                         (0)
#define  VP8_P2_vp8_mb_ch_mv0_mv_x_mask                                          (0x1FFFC000)
#define  VP8_P2_vp8_mb_ch_mv0_mv_y_mask                                          (0x00003FFF)
#define  VP8_P2_vp8_mb_ch_mv0_mv_x(data)                                         (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_ch_mv0_mv_y(data)                                         (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_ch_mv0_get_mv_x(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_ch_mv0_get_mv_y(data)                                     (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_ch_mv1                                                    0x1800FD68
#define  VP8_P2_vp8_mb_ch_mv1_reg_addr                                           "0xB800FD68"
#define  VP8_P2_vp8_mb_ch_mv1_reg                                                0xB800FD68
#define  VP8_P2_vp8_mb_ch_mv1_inst_addr                                          "0x001A"
#define  set_VP8_P2_vp8_mb_ch_mv1_reg(data)                                      (*((volatile unsigned int*)VP8_P2_vp8_mb_ch_mv1_reg)=data)
#define  get_VP8_P2_vp8_mb_ch_mv1_reg                                            (*((volatile unsigned int*)VP8_P2_vp8_mb_ch_mv1_reg))
#define  VP8_P2_vp8_mb_ch_mv1_mv_x_shift                                         (14)
#define  VP8_P2_vp8_mb_ch_mv1_mv_y_shift                                         (0)
#define  VP8_P2_vp8_mb_ch_mv1_mv_x_mask                                          (0x1FFFC000)
#define  VP8_P2_vp8_mb_ch_mv1_mv_y_mask                                          (0x00003FFF)
#define  VP8_P2_vp8_mb_ch_mv1_mv_x(data)                                         (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_ch_mv1_mv_y(data)                                         (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_ch_mv1_get_mv_x(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_ch_mv1_get_mv_y(data)                                     (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_ch_mv2                                                    0x1800FD6C
#define  VP8_P2_vp8_mb_ch_mv2_reg_addr                                           "0xB800FD6C"
#define  VP8_P2_vp8_mb_ch_mv2_reg                                                0xB800FD6C
#define  VP8_P2_vp8_mb_ch_mv2_inst_addr                                          "0x001B"
#define  set_VP8_P2_vp8_mb_ch_mv2_reg(data)                                      (*((volatile unsigned int*)VP8_P2_vp8_mb_ch_mv2_reg)=data)
#define  get_VP8_P2_vp8_mb_ch_mv2_reg                                            (*((volatile unsigned int*)VP8_P2_vp8_mb_ch_mv2_reg))
#define  VP8_P2_vp8_mb_ch_mv2_mv_x_shift                                         (14)
#define  VP8_P2_vp8_mb_ch_mv2_mv_y_shift                                         (0)
#define  VP8_P2_vp8_mb_ch_mv2_mv_x_mask                                          (0x1FFFC000)
#define  VP8_P2_vp8_mb_ch_mv2_mv_y_mask                                          (0x00003FFF)
#define  VP8_P2_vp8_mb_ch_mv2_mv_x(data)                                         (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_ch_mv2_mv_y(data)                                         (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_ch_mv2_get_mv_x(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_ch_mv2_get_mv_y(data)                                     (0x00003FFF&(data))

#define  VP8_P2_vp8_mb_ch_mv3                                                    0x1800FD70
#define  VP8_P2_vp8_mb_ch_mv3_reg_addr                                           "0xB800FD70"
#define  VP8_P2_vp8_mb_ch_mv3_reg                                                0xB800FD70
#define  VP8_P2_vp8_mb_ch_mv3_inst_addr                                          "0x001C"
#define  set_VP8_P2_vp8_mb_ch_mv3_reg(data)                                      (*((volatile unsigned int*)VP8_P2_vp8_mb_ch_mv3_reg)=data)
#define  get_VP8_P2_vp8_mb_ch_mv3_reg                                            (*((volatile unsigned int*)VP8_P2_vp8_mb_ch_mv3_reg))
#define  VP8_P2_vp8_mb_ch_mv3_mv_x_shift                                         (14)
#define  VP8_P2_vp8_mb_ch_mv3_mv_y_shift                                         (0)
#define  VP8_P2_vp8_mb_ch_mv3_mv_x_mask                                          (0x1FFFC000)
#define  VP8_P2_vp8_mb_ch_mv3_mv_y_mask                                          (0x00003FFF)
#define  VP8_P2_vp8_mb_ch_mv3_mv_x(data)                                         (0x1FFFC000&((data)<<14))
#define  VP8_P2_vp8_mb_ch_mv3_mv_y(data)                                         (0x00003FFF&(data))
#define  VP8_P2_vp8_mb_ch_mv3_get_mv_x(data)                                     ((0x1FFFC000&(data))>>14)
#define  VP8_P2_vp8_mb_ch_mv3_get_mv_y(data)                                     (0x00003FFF&(data))

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
}vp8_p2_vp8_p2_frm1_RBUS;

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
}vp8_p2_vp8_p2_frm2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  picmb_h:7;
    };
}vp8_p2_vp8_p2_frm3_RBUS;

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
}vp8_p2_vp8_p2_mb1_RBUS;

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
}vp8_p2_vp8_p2_mb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_blk_mode_p0:32;
    };
}vp8_p2_vp8_p2_sub_blk0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_blk_mode_p1:32;
    };
}vp8_p2_vp8_p2_sub_blk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vp8_p2_curmb:9;
        RBus_UInt32  vp8_mbpartition:9;
        RBus_UInt32  vp8_inter_pred_option:8;
    };
}vp8_p2_vp8_p2_mb_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  high:9;
        RBus_UInt32  bits:4;
        RBus_UInt32  code_word:16;
    };
}vp8_p2_vp8_bac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_mv15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_ch_mv0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_ch_mv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_ch_mv2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  mv_y:14;
    };
}vp8_p2_vp8_mb_ch_mv3_RBUS;

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
}vp8_p2_vp8_p2_frm1_RBUS;

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
}vp8_p2_vp8_p2_frm2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  picmb_h:7;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res1:24;
    };
}vp8_p2_vp8_p2_frm3_RBUS;

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
}vp8_p2_vp8_p2_mb1_RBUS;

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
}vp8_p2_vp8_p2_mb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_blk_mode_p0:32;
    };
}vp8_p2_vp8_p2_sub_blk0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_blk_mode_p1:32;
    };
}vp8_p2_vp8_p2_sub_blk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vp8_inter_pred_option:8;
        RBus_UInt32  vp8_mbpartition:9;
        RBus_UInt32  vp8_p2_curmb:9;
        RBus_UInt32  res1:6;
    };
}vp8_p2_vp8_p2_mb_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  code_word:16;
        RBus_UInt32  bits:4;
        RBus_UInt32  high:9;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_bac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_mv15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_ch_mv0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_ch_mv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_ch_mv2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_y:14;
        RBus_UInt32  mv_x:15;
        RBus_UInt32  res1:3;
    };
}vp8_p2_vp8_mb_ch_mv3_RBUS;




#endif 


#endif 
