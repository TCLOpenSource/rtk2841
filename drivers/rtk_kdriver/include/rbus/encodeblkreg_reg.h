/**
* @file Mac5_VE_VLC_SPEC
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ENCODEBLKREG_REG_H_
#define _RBUS_ENCODEBLKREG_REG_H_

#include "rbus_types.h"



//  ENCODEBLKREG Register Address
#define  ENCODEBLKREG_cm_ctrl                                                    0x1800F400
#define  ENCODEBLKREG_cm_ctrl_reg_addr                                           "0xB800F400"
#define  ENCODEBLKREG_cm_ctrl_reg                                                0xB800F400
#define  ENCODEBLKREG_cm_ctrl_inst_addr                                          "0x0000"
#define  set_ENCODEBLKREG_cm_ctrl_reg(data)                                      (*((volatile unsigned int*)ENCODEBLKREG_cm_ctrl_reg)=data)
#define  get_ENCODEBLKREG_cm_ctrl_reg                                            (*((volatile unsigned int*)ENCODEBLKREG_cm_ctrl_reg))
#define  ENCODEBLKREG_cm_ctrl_write_enable3_shift                                (6)
#define  ENCODEBLKREG_cm_ctrl_vlc_bank_shift                                     (5)
#define  ENCODEBLKREG_cm_ctrl_write_enable2_shift                                (4)
#define  ENCODEBLKREG_cm_ctrl_tq_bank_shift                                      (3)
#define  ENCODEBLKREG_cm_ctrl_write_enable1_shift                                (2)
#define  ENCODEBLKREG_cm_ctrl_cm_mstr_shift                                      (0)
#define  ENCODEBLKREG_cm_ctrl_write_enable3_mask                                 (0x00000040)
#define  ENCODEBLKREG_cm_ctrl_vlc_bank_mask                                      (0x00000020)
#define  ENCODEBLKREG_cm_ctrl_write_enable2_mask                                 (0x00000010)
#define  ENCODEBLKREG_cm_ctrl_tq_bank_mask                                       (0x00000008)
#define  ENCODEBLKREG_cm_ctrl_write_enable1_mask                                 (0x00000004)
#define  ENCODEBLKREG_cm_ctrl_cm_mstr_mask                                       (0x00000003)
#define  ENCODEBLKREG_cm_ctrl_write_enable3(data)                                (0x00000040&((data)<<6))
#define  ENCODEBLKREG_cm_ctrl_vlc_bank(data)                                     (0x00000020&((data)<<5))
#define  ENCODEBLKREG_cm_ctrl_write_enable2(data)                                (0x00000010&((data)<<4))
#define  ENCODEBLKREG_cm_ctrl_tq_bank(data)                                      (0x00000008&((data)<<3))
#define  ENCODEBLKREG_cm_ctrl_write_enable1(data)                                (0x00000004&((data)<<2))
#define  ENCODEBLKREG_cm_ctrl_cm_mstr(data)                                      (0x00000003&(data))
#define  ENCODEBLKREG_cm_ctrl_get_write_enable3(data)                            ((0x00000040&(data))>>6)
#define  ENCODEBLKREG_cm_ctrl_get_vlc_bank(data)                                 ((0x00000020&(data))>>5)
#define  ENCODEBLKREG_cm_ctrl_get_write_enable2(data)                            ((0x00000010&(data))>>4)
#define  ENCODEBLKREG_cm_ctrl_get_tq_bank(data)                                  ((0x00000008&(data))>>3)
#define  ENCODEBLKREG_cm_ctrl_get_write_enable1(data)                            ((0x00000004&(data))>>2)
#define  ENCODEBLKREG_cm_ctrl_get_cm_mstr(data)                                  (0x00000003&(data))

#define  ENCODEBLKREG_curadr                                                     0x1800F404
#define  ENCODEBLKREG_curadr_reg_addr                                            "0xB800F404"
#define  ENCODEBLKREG_curadr_reg                                                 0xB800F404
#define  ENCODEBLKREG_curadr_inst_addr                                           "0x0001"
#define  set_ENCODEBLKREG_curadr_reg(data)                                       (*((volatile unsigned int*)ENCODEBLKREG_curadr_reg)=data)
#define  get_ENCODEBLKREG_curadr_reg                                             (*((volatile unsigned int*)ENCODEBLKREG_curadr_reg))
#define  ENCODEBLKREG_curadr_write_enable2_shift                                 (17)
#define  ENCODEBLKREG_curadr_vlc_pred_counter_shift                              (9)
#define  ENCODEBLKREG_curadr_write_enable1_shift                                 (8)
#define  ENCODEBLKREG_curadr_vlc_curmb_addr_shift                                (0)
#define  ENCODEBLKREG_curadr_write_enable2_mask                                  (0x00020000)
#define  ENCODEBLKREG_curadr_vlc_pred_counter_mask                               (0x0001FE00)
#define  ENCODEBLKREG_curadr_write_enable1_mask                                  (0x00000100)
#define  ENCODEBLKREG_curadr_vlc_curmb_addr_mask                                 (0x000000FF)
#define  ENCODEBLKREG_curadr_write_enable2(data)                                 (0x00020000&((data)<<17))
#define  ENCODEBLKREG_curadr_vlc_pred_counter(data)                              (0x0001FE00&((data)<<9))
#define  ENCODEBLKREG_curadr_write_enable1(data)                                 (0x00000100&((data)<<8))
#define  ENCODEBLKREG_curadr_vlc_curmb_addr(data)                                (0x000000FF&(data))
#define  ENCODEBLKREG_curadr_get_write_enable2(data)                             ((0x00020000&(data))>>17)
#define  ENCODEBLKREG_curadr_get_vlc_pred_counter(data)                          ((0x0001FE00&(data))>>9)
#define  ENCODEBLKREG_curadr_get_write_enable1(data)                             ((0x00000100&(data))>>8)
#define  ENCODEBLKREG_curadr_get_vlc_curmb_addr(data)                            (0x000000FF&(data))

#define  ENCODEBLKREG_h264_cntl                                                  0x1800F408
#define  ENCODEBLKREG_h264_cntl_reg_addr                                         "0xB800F408"
#define  ENCODEBLKREG_h264_cntl_reg                                              0xB800F408
#define  ENCODEBLKREG_h264_cntl_inst_addr                                        "0x0002"
#define  set_ENCODEBLKREG_h264_cntl_reg(data)                                    (*((volatile unsigned int*)ENCODEBLKREG_h264_cntl_reg)=data)
#define  get_ENCODEBLKREG_h264_cntl_reg                                          (*((volatile unsigned int*)ENCODEBLKREG_h264_cntl_reg))
#define  ENCODEBLKREG_h264_cntl_entropy_coding_mode_shift                        (18)
#define  ENCODEBLKREG_h264_cntl_pic_init_qp_shift                                (12)
#define  ENCODEBLKREG_h264_cntl_direct_8x8_inferflg_shift                        (11)
#define  ENCODEBLKREG_h264_cntl_transform_8x8_mode_flg_shift                     (10)
#define  ENCODEBLKREG_h264_cntl_num_ref_idx_l0_active_minus1_shift               (5)
#define  ENCODEBLKREG_h264_cntl_num_ref_idx_l1_active_minus1_shift               (0)
#define  ENCODEBLKREG_h264_cntl_entropy_coding_mode_mask                         (0x00040000)
#define  ENCODEBLKREG_h264_cntl_pic_init_qp_mask                                 (0x0003F000)
#define  ENCODEBLKREG_h264_cntl_direct_8x8_inferflg_mask                         (0x00000800)
#define  ENCODEBLKREG_h264_cntl_transform_8x8_mode_flg_mask                      (0x00000400)
#define  ENCODEBLKREG_h264_cntl_num_ref_idx_l0_active_minus1_mask                (0x000003E0)
#define  ENCODEBLKREG_h264_cntl_num_ref_idx_l1_active_minus1_mask                (0x0000001F)
#define  ENCODEBLKREG_h264_cntl_entropy_coding_mode(data)                        (0x00040000&((data)<<18))
#define  ENCODEBLKREG_h264_cntl_pic_init_qp(data)                                (0x0003F000&((data)<<12))
#define  ENCODEBLKREG_h264_cntl_direct_8x8_inferflg(data)                        (0x00000800&((data)<<11))
#define  ENCODEBLKREG_h264_cntl_transform_8x8_mode_flg(data)                     (0x00000400&((data)<<10))
#define  ENCODEBLKREG_h264_cntl_num_ref_idx_l0_active_minus1(data)               (0x000003E0&((data)<<5))
#define  ENCODEBLKREG_h264_cntl_num_ref_idx_l1_active_minus1(data)               (0x0000001F&(data))
#define  ENCODEBLKREG_h264_cntl_get_entropy_coding_mode(data)                    ((0x00040000&(data))>>18)
#define  ENCODEBLKREG_h264_cntl_get_pic_init_qp(data)                            ((0x0003F000&(data))>>12)
#define  ENCODEBLKREG_h264_cntl_get_direct_8x8_inferflg(data)                    ((0x00000800&(data))>>11)
#define  ENCODEBLKREG_h264_cntl_get_transform_8x8_mode_flg(data)                 ((0x00000400&(data))>>10)
#define  ENCODEBLKREG_h264_cntl_get_num_ref_idx_l0_active_minus1(data)           ((0x000003E0&(data))>>5)
#define  ENCODEBLKREG_h264_cntl_get_num_ref_idx_l1_active_minus1(data)           (0x0000001F&(data))

#define  ENCODEBLKREG_h264_cntl2                                                 0x1800F40C
#define  ENCODEBLKREG_h264_cntl2_reg_addr                                        "0xB800F40C"
#define  ENCODEBLKREG_h264_cntl2_reg                                             0xB800F40C
#define  ENCODEBLKREG_h264_cntl2_inst_addr                                       "0x0003"
#define  set_ENCODEBLKREG_h264_cntl2_reg(data)                                   (*((volatile unsigned int*)ENCODEBLKREG_h264_cntl2_reg)=data)
#define  get_ENCODEBLKREG_h264_cntl2_reg                                         (*((volatile unsigned int*)ENCODEBLKREG_h264_cntl2_reg))
#define  ENCODEBLKREG_h264_cntl2_write_enable3_shift                             (14)
#define  ENCODEBLKREG_h264_cntl2_pic_type_shift                                  (11)
#define  ENCODEBLKREG_h264_cntl2_write_enable2_shift                             (10)
#define  ENCODEBLKREG_h264_cntl2_slice_qp_delta_shift                            (3)
#define  ENCODEBLKREG_h264_cntl2_write_enable1_shift                             (2)
#define  ENCODEBLKREG_h264_cntl2_cabac_init_idc_shift                            (0)
#define  ENCODEBLKREG_h264_cntl2_write_enable3_mask                              (0x00004000)
#define  ENCODEBLKREG_h264_cntl2_pic_type_mask                                   (0x00003800)
#define  ENCODEBLKREG_h264_cntl2_write_enable2_mask                              (0x00000400)
#define  ENCODEBLKREG_h264_cntl2_slice_qp_delta_mask                             (0x000003F8)
#define  ENCODEBLKREG_h264_cntl2_write_enable1_mask                              (0x00000004)
#define  ENCODEBLKREG_h264_cntl2_cabac_init_idc_mask                             (0x00000003)
#define  ENCODEBLKREG_h264_cntl2_write_enable3(data)                             (0x00004000&((data)<<14))
#define  ENCODEBLKREG_h264_cntl2_pic_type(data)                                  (0x00003800&((data)<<11))
#define  ENCODEBLKREG_h264_cntl2_write_enable2(data)                             (0x00000400&((data)<<10))
#define  ENCODEBLKREG_h264_cntl2_slice_qp_delta(data)                            (0x000003F8&((data)<<3))
#define  ENCODEBLKREG_h264_cntl2_write_enable1(data)                             (0x00000004&((data)<<2))
#define  ENCODEBLKREG_h264_cntl2_cabac_init_idc(data)                            (0x00000003&(data))
#define  ENCODEBLKREG_h264_cntl2_get_write_enable3(data)                         ((0x00004000&(data))>>14)
#define  ENCODEBLKREG_h264_cntl2_get_pic_type(data)                              ((0x00003800&(data))>>11)
#define  ENCODEBLKREG_h264_cntl2_get_write_enable2(data)                         ((0x00000400&(data))>>10)
#define  ENCODEBLKREG_h264_cntl2_get_slice_qp_delta(data)                        ((0x000003F8&(data))>>3)
#define  ENCODEBLKREG_h264_cntl2_get_write_enable1(data)                         ((0x00000004&(data))>>2)
#define  ENCODEBLKREG_h264_cntl2_get_cabac_init_idc(data)                        (0x00000003&(data))

#define  ENCODEBLKREG_vlc_bitcnt                                                 0x1800F414
#define  ENCODEBLKREG_vlc_bitcnt_reg_addr                                        "0xB800F414"
#define  ENCODEBLKREG_vlc_bitcnt_reg                                             0xB800F414
#define  ENCODEBLKREG_vlc_bitcnt_inst_addr                                       "0x0004"
#define  set_ENCODEBLKREG_vlc_bitcnt_reg(data)                                   (*((volatile unsigned int*)ENCODEBLKREG_vlc_bitcnt_reg)=data)
#define  get_ENCODEBLKREG_vlc_bitcnt_reg                                         (*((volatile unsigned int*)ENCODEBLKREG_vlc_bitcnt_reg))
#define  ENCODEBLKREG_vlc_bitcnt_enc_bitcnt_shift                                (0)
#define  ENCODEBLKREG_vlc_bitcnt_enc_bitcnt_mask                                 (0xFFFFFFFF)
#define  ENCODEBLKREG_vlc_bitcnt_enc_bitcnt(data)                                (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_vlc_bitcnt_get_enc_bitcnt(data)                            (0xFFFFFFFF&(data))

#define  ENCODEBLKREG_vlc_mbtype                                                 0x1800F430
#define  ENCODEBLKREG_vlc_mbtype_reg_addr                                        "0xB800F430"
#define  ENCODEBLKREG_vlc_mbtype_reg                                             0xB800F430
#define  ENCODEBLKREG_vlc_mbtype_inst_addr                                       "0x0005"
#define  set_ENCODEBLKREG_vlc_mbtype_reg(data)                                   (*((volatile unsigned int*)ENCODEBLKREG_vlc_mbtype_reg)=data)
#define  get_ENCODEBLKREG_vlc_mbtype_reg                                         (*((volatile unsigned int*)ENCODEBLKREG_vlc_mbtype_reg))
#define  ENCODEBLKREG_vlc_mbtype_write_enable4_shift                             (20)
#define  ENCODEBLKREG_vlc_mbtype_qp_delta_shift                                  (14)
#define  ENCODEBLKREG_vlc_mbtype_write_enable3_shift                             (13)
#define  ENCODEBLKREG_vlc_mbtype_qpy_shift                                       (7)
#define  ENCODEBLKREG_vlc_mbtype_write_enable2_shift                             (6)
#define  ENCODEBLKREG_vlc_mbtype_mbtype_shift                                    (2)
#define  ENCODEBLKREG_vlc_mbtype_write_enable1_shift                             (1)
#define  ENCODEBLKREG_vlc_mbtype_transform_size_8x8_shift                        (0)
#define  ENCODEBLKREG_vlc_mbtype_write_enable4_mask                              (0x00100000)
#define  ENCODEBLKREG_vlc_mbtype_qp_delta_mask                                   (0x000FC000)
#define  ENCODEBLKREG_vlc_mbtype_write_enable3_mask                              (0x00002000)
#define  ENCODEBLKREG_vlc_mbtype_qpy_mask                                        (0x00001F80)
#define  ENCODEBLKREG_vlc_mbtype_write_enable2_mask                              (0x00000040)
#define  ENCODEBLKREG_vlc_mbtype_mbtype_mask                                     (0x0000003C)
#define  ENCODEBLKREG_vlc_mbtype_write_enable1_mask                              (0x00000002)
#define  ENCODEBLKREG_vlc_mbtype_transform_size_8x8_mask                         (0x00000001)
#define  ENCODEBLKREG_vlc_mbtype_write_enable4(data)                             (0x00100000&((data)<<20))
#define  ENCODEBLKREG_vlc_mbtype_qp_delta(data)                                  (0x000FC000&((data)<<14))
#define  ENCODEBLKREG_vlc_mbtype_write_enable3(data)                             (0x00002000&((data)<<13))
#define  ENCODEBLKREG_vlc_mbtype_qpy(data)                                       (0x00001F80&((data)<<7))
#define  ENCODEBLKREG_vlc_mbtype_write_enable2(data)                             (0x00000040&((data)<<6))
#define  ENCODEBLKREG_vlc_mbtype_mbtype(data)                                    (0x0000003C&((data)<<2))
#define  ENCODEBLKREG_vlc_mbtype_write_enable1(data)                             (0x00000002&((data)<<1))
#define  ENCODEBLKREG_vlc_mbtype_transform_size_8x8(data)                        (0x00000001&(data))
#define  ENCODEBLKREG_vlc_mbtype_get_write_enable4(data)                         ((0x00100000&(data))>>20)
#define  ENCODEBLKREG_vlc_mbtype_get_qp_delta(data)                              ((0x000FC000&(data))>>14)
#define  ENCODEBLKREG_vlc_mbtype_get_write_enable3(data)                         ((0x00002000&(data))>>13)
#define  ENCODEBLKREG_vlc_mbtype_get_qpy(data)                                   ((0x00001F80&(data))>>7)
#define  ENCODEBLKREG_vlc_mbtype_get_write_enable2(data)                         ((0x00000040&(data))>>6)
#define  ENCODEBLKREG_vlc_mbtype_get_mbtype(data)                                ((0x0000003C&(data))>>2)
#define  ENCODEBLKREG_vlc_mbtype_get_write_enable1(data)                         ((0x00000002&(data))>>1)
#define  ENCODEBLKREG_vlc_mbtype_get_transform_size_8x8(data)                    (0x00000001&(data))

#define  ENCODEBLKREG_vlc_cbp                                                    0x1800F434
#define  ENCODEBLKREG_vlc_cbp_reg_addr                                           "0xB800F434"
#define  ENCODEBLKREG_vlc_cbp_reg                                                0xB800F434
#define  ENCODEBLKREG_vlc_cbp_inst_addr                                          "0x0006"
#define  set_ENCODEBLKREG_vlc_cbp_reg(data)                                      (*((volatile unsigned int*)ENCODEBLKREG_vlc_cbp_reg)=data)
#define  get_ENCODEBLKREG_vlc_cbp_reg                                            (*((volatile unsigned int*)ENCODEBLKREG_vlc_cbp_reg))
#define  ENCODEBLKREG_vlc_cbp_write_enable2_shift                                (31)
#define  ENCODEBLKREG_vlc_cbp_cbp6bits_shift                                     (25)
#define  ENCODEBLKREG_vlc_cbp_write_enable1_shift                                (24)
#define  ENCODEBLKREG_vlc_cbp_subblkpat_shift                                    (0)
#define  ENCODEBLKREG_vlc_cbp_write_enable2_mask                                 (0x80000000)
#define  ENCODEBLKREG_vlc_cbp_cbp6bits_mask                                      (0x7E000000)
#define  ENCODEBLKREG_vlc_cbp_write_enable1_mask                                 (0x01000000)
#define  ENCODEBLKREG_vlc_cbp_subblkpat_mask                                     (0x00FFFFFF)
#define  ENCODEBLKREG_vlc_cbp_write_enable2(data)                                (0x80000000&((data)<<31))
#define  ENCODEBLKREG_vlc_cbp_cbp6bits(data)                                     (0x7E000000&((data)<<25))
#define  ENCODEBLKREG_vlc_cbp_write_enable1(data)                                (0x01000000&((data)<<24))
#define  ENCODEBLKREG_vlc_cbp_subblkpat(data)                                    (0x00FFFFFF&(data))
#define  ENCODEBLKREG_vlc_cbp_get_write_enable2(data)                            ((0x80000000&(data))>>31)
#define  ENCODEBLKREG_vlc_cbp_get_cbp6bits(data)                                 ((0x7E000000&(data))>>25)
#define  ENCODEBLKREG_vlc_cbp_get_write_enable1(data)                            ((0x01000000&(data))>>24)
#define  ENCODEBLKREG_vlc_cbp_get_subblkpat(data)                                (0x00FFFFFF&(data))

#define  ENCODEBLKREG_mb_partition                                               0x1800F438
#define  ENCODEBLKREG_mb_partition_reg_addr                                      "0xB800F438"
#define  ENCODEBLKREG_mb_partition_reg                                           0xB800F438
#define  ENCODEBLKREG_mb_partition_inst_addr                                     "0x0007"
#define  set_ENCODEBLKREG_mb_partition_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_mb_partition_reg)=data)
#define  get_ENCODEBLKREG_mb_partition_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_mb_partition_reg))
#define  ENCODEBLKREG_mb_partition_mbpartition_shift                             (0)
#define  ENCODEBLKREG_mb_partition_mbpartition_mask                              (0x000001FF)
#define  ENCODEBLKREG_mb_partition_mbpartition(data)                             (0x000001FF&(data))
#define  ENCODEBLKREG_mb_partition_get_mbpartition(data)                         (0x000001FF&(data))

#define  ENCODEBLKREG_mb_predmode                                                0x1800F43C
#define  ENCODEBLKREG_mb_predmode_reg_addr                                       "0xB800F43C"
#define  ENCODEBLKREG_mb_predmode_reg                                            0xB800F43C
#define  ENCODEBLKREG_mb_predmode_inst_addr                                      "0x0008"
#define  set_ENCODEBLKREG_mb_predmode_reg(data)                                  (*((volatile unsigned int*)ENCODEBLKREG_mb_predmode_reg)=data)
#define  get_ENCODEBLKREG_mb_predmode_reg                                        (*((volatile unsigned int*)ENCODEBLKREG_mb_predmode_reg))
#define  ENCODEBLKREG_mb_predmode_mb_pred_mode_shift                             (0)
#define  ENCODEBLKREG_mb_predmode_mb_pred_mode_mask                              (0x000000FF)
#define  ENCODEBLKREG_mb_predmode_mb_pred_mode(data)                             (0x000000FF&(data))
#define  ENCODEBLKREG_mb_predmode_get_mb_pred_mode(data)                         (0x000000FF&(data))

#define  ENCODEBLKREG_intra_pred_0                                               0x1800F440
#define  ENCODEBLKREG_intra_pred_0_reg_addr                                      "0xB800F440"
#define  ENCODEBLKREG_intra_pred_0_reg                                           0xB800F440
#define  ENCODEBLKREG_intra_pred_0_inst_addr                                     "0x0009"
#define  set_ENCODEBLKREG_intra_pred_0_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_intra_pred_0_reg)=data)
#define  get_ENCODEBLKREG_intra_pred_0_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_intra_pred_0_reg))
#define  ENCODEBLKREG_intra_pred_0_rem_mode_shift                                (0)
#define  ENCODEBLKREG_intra_pred_0_rem_mode_mask                                 (0xFFFFFFFF)
#define  ENCODEBLKREG_intra_pred_0_rem_mode(data)                                (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_intra_pred_0_get_rem_mode(data)                            (0xFFFFFFFF&(data))

#define  ENCODEBLKREG_intra_pred_1                                               0x1800F444
#define  ENCODEBLKREG_intra_pred_1_reg_addr                                      "0xB800F444"
#define  ENCODEBLKREG_intra_pred_1_reg                                           0xB800F444
#define  ENCODEBLKREG_intra_pred_1_inst_addr                                     "0x000A"
#define  set_ENCODEBLKREG_intra_pred_1_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_intra_pred_1_reg)=data)
#define  get_ENCODEBLKREG_intra_pred_1_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_intra_pred_1_reg))
#define  ENCODEBLKREG_intra_pred_1_rem_mode_shift                                (0)
#define  ENCODEBLKREG_intra_pred_1_rem_mode_mask                                 (0xFFFFFFFF)
#define  ENCODEBLKREG_intra_pred_1_rem_mode(data)                                (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_intra_pred_1_get_rem_mode(data)                            (0xFFFFFFFF&(data))

#define  ENCODEBLKREG_intra_pred_2                                               0x1800F448
#define  ENCODEBLKREG_intra_pred_2_reg_addr                                      "0xB800F448"
#define  ENCODEBLKREG_intra_pred_2_reg                                           0xB800F448
#define  ENCODEBLKREG_intra_pred_2_inst_addr                                     "0x000B"
#define  set_ENCODEBLKREG_intra_pred_2_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_intra_pred_2_reg)=data)
#define  get_ENCODEBLKREG_intra_pred_2_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_intra_pred_2_reg))
#define  ENCODEBLKREG_intra_pred_2_rem_mode_shift                                (0)
#define  ENCODEBLKREG_intra_pred_2_rem_mode_mask                                 (0xFFFFFFFF)
#define  ENCODEBLKREG_intra_pred_2_rem_mode(data)                                (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_intra_pred_2_get_rem_mode(data)                            (0xFFFFFFFF&(data))

#define  ENCODEBLKREG_ref_l0_0                                                   0x1800F450
#define  ENCODEBLKREG_ref_l0_0_reg_addr                                          "0xB800F450"
#define  ENCODEBLKREG_ref_l0_0_reg                                               0xB800F450
#define  ENCODEBLKREG_ref_l0_0_inst_addr                                         "0x000C"
#define  set_ENCODEBLKREG_ref_l0_0_reg(data)                                     (*((volatile unsigned int*)ENCODEBLKREG_ref_l0_0_reg)=data)
#define  get_ENCODEBLKREG_ref_l0_0_reg                                           (*((volatile unsigned int*)ENCODEBLKREG_ref_l0_0_reg))
#define  ENCODEBLKREG_ref_l0_0_ref_idx_l0_shift                                  (22)
#define  ENCODEBLKREG_ref_l0_0_mvd_l0_y_shift                                    (12)
#define  ENCODEBLKREG_ref_l0_0_mvd_l0_x_shift                                    (0)
#define  ENCODEBLKREG_ref_l0_0_ref_idx_l0_mask                                   (0x00C00000)
#define  ENCODEBLKREG_ref_l0_0_mvd_l0_y_mask                                     (0x003FF000)
#define  ENCODEBLKREG_ref_l0_0_mvd_l0_x_mask                                     (0x00000FFF)
#define  ENCODEBLKREG_ref_l0_0_ref_idx_l0(data)                                  (0x00C00000&((data)<<22))
#define  ENCODEBLKREG_ref_l0_0_mvd_l0_y(data)                                    (0x003FF000&((data)<<12))
#define  ENCODEBLKREG_ref_l0_0_mvd_l0_x(data)                                    (0x00000FFF&(data))
#define  ENCODEBLKREG_ref_l0_0_get_ref_idx_l0(data)                              ((0x00C00000&(data))>>22)
#define  ENCODEBLKREG_ref_l0_0_get_mvd_l0_y(data)                                ((0x003FF000&(data))>>12)
#define  ENCODEBLKREG_ref_l0_0_get_mvd_l0_x(data)                                (0x00000FFF&(data))

#define  ENCODEBLKREG_ref_l0_1                                                   0x1800F454
#define  ENCODEBLKREG_ref_l0_1_reg_addr                                          "0xB800F454"
#define  ENCODEBLKREG_ref_l0_1_reg                                               0xB800F454
#define  ENCODEBLKREG_ref_l0_1_inst_addr                                         "0x000D"
#define  set_ENCODEBLKREG_ref_l0_1_reg(data)                                     (*((volatile unsigned int*)ENCODEBLKREG_ref_l0_1_reg)=data)
#define  get_ENCODEBLKREG_ref_l0_1_reg                                           (*((volatile unsigned int*)ENCODEBLKREG_ref_l0_1_reg))
#define  ENCODEBLKREG_ref_l0_1_ref_idx_l0_shift                                  (22)
#define  ENCODEBLKREG_ref_l0_1_mvd_l0_y_shift                                    (12)
#define  ENCODEBLKREG_ref_l0_1_mvd_l0_x_shift                                    (0)
#define  ENCODEBLKREG_ref_l0_1_ref_idx_l0_mask                                   (0x00C00000)
#define  ENCODEBLKREG_ref_l0_1_mvd_l0_y_mask                                     (0x003FF000)
#define  ENCODEBLKREG_ref_l0_1_mvd_l0_x_mask                                     (0x00000FFF)
#define  ENCODEBLKREG_ref_l0_1_ref_idx_l0(data)                                  (0x00C00000&((data)<<22))
#define  ENCODEBLKREG_ref_l0_1_mvd_l0_y(data)                                    (0x003FF000&((data)<<12))
#define  ENCODEBLKREG_ref_l0_1_mvd_l0_x(data)                                    (0x00000FFF&(data))
#define  ENCODEBLKREG_ref_l0_1_get_ref_idx_l0(data)                              ((0x00C00000&(data))>>22)
#define  ENCODEBLKREG_ref_l0_1_get_mvd_l0_y(data)                                ((0x003FF000&(data))>>12)
#define  ENCODEBLKREG_ref_l0_1_get_mvd_l0_x(data)                                (0x00000FFF&(data))

#define  ENCODEBLKREG_ref_l0_2                                                   0x1800F458
#define  ENCODEBLKREG_ref_l0_2_reg_addr                                          "0xB800F458"
#define  ENCODEBLKREG_ref_l0_2_reg                                               0xB800F458
#define  ENCODEBLKREG_ref_l0_2_inst_addr                                         "0x000E"
#define  set_ENCODEBLKREG_ref_l0_2_reg(data)                                     (*((volatile unsigned int*)ENCODEBLKREG_ref_l0_2_reg)=data)
#define  get_ENCODEBLKREG_ref_l0_2_reg                                           (*((volatile unsigned int*)ENCODEBLKREG_ref_l0_2_reg))
#define  ENCODEBLKREG_ref_l0_2_ref_idx_l0_shift                                  (22)
#define  ENCODEBLKREG_ref_l0_2_mvd_l0_y_shift                                    (12)
#define  ENCODEBLKREG_ref_l0_2_mvd_l0_x_shift                                    (0)
#define  ENCODEBLKREG_ref_l0_2_ref_idx_l0_mask                                   (0x00C00000)
#define  ENCODEBLKREG_ref_l0_2_mvd_l0_y_mask                                     (0x003FF000)
#define  ENCODEBLKREG_ref_l0_2_mvd_l0_x_mask                                     (0x00000FFF)
#define  ENCODEBLKREG_ref_l0_2_ref_idx_l0(data)                                  (0x00C00000&((data)<<22))
#define  ENCODEBLKREG_ref_l0_2_mvd_l0_y(data)                                    (0x003FF000&((data)<<12))
#define  ENCODEBLKREG_ref_l0_2_mvd_l0_x(data)                                    (0x00000FFF&(data))
#define  ENCODEBLKREG_ref_l0_2_get_ref_idx_l0(data)                              ((0x00C00000&(data))>>22)
#define  ENCODEBLKREG_ref_l0_2_get_mvd_l0_y(data)                                ((0x003FF000&(data))>>12)
#define  ENCODEBLKREG_ref_l0_2_get_mvd_l0_x(data)                                (0x00000FFF&(data))

#define  ENCODEBLKREG_ref_l0_3                                                   0x1800F45C
#define  ENCODEBLKREG_ref_l0_3_reg_addr                                          "0xB800F45C"
#define  ENCODEBLKREG_ref_l0_3_reg                                               0xB800F45C
#define  ENCODEBLKREG_ref_l0_3_inst_addr                                         "0x000F"
#define  set_ENCODEBLKREG_ref_l0_3_reg(data)                                     (*((volatile unsigned int*)ENCODEBLKREG_ref_l0_3_reg)=data)
#define  get_ENCODEBLKREG_ref_l0_3_reg                                           (*((volatile unsigned int*)ENCODEBLKREG_ref_l0_3_reg))
#define  ENCODEBLKREG_ref_l0_3_ref_idx_l0_shift                                  (22)
#define  ENCODEBLKREG_ref_l0_3_mvd_l0_y_shift                                    (12)
#define  ENCODEBLKREG_ref_l0_3_mvd_l0_x_shift                                    (0)
#define  ENCODEBLKREG_ref_l0_3_ref_idx_l0_mask                                   (0x00C00000)
#define  ENCODEBLKREG_ref_l0_3_mvd_l0_y_mask                                     (0x003FF000)
#define  ENCODEBLKREG_ref_l0_3_mvd_l0_x_mask                                     (0x00000FFF)
#define  ENCODEBLKREG_ref_l0_3_ref_idx_l0(data)                                  (0x00C00000&((data)<<22))
#define  ENCODEBLKREG_ref_l0_3_mvd_l0_y(data)                                    (0x003FF000&((data)<<12))
#define  ENCODEBLKREG_ref_l0_3_mvd_l0_x(data)                                    (0x00000FFF&(data))
#define  ENCODEBLKREG_ref_l0_3_get_ref_idx_l0(data)                              ((0x00C00000&(data))>>22)
#define  ENCODEBLKREG_ref_l0_3_get_mvd_l0_y(data)                                ((0x003FF000&(data))>>12)
#define  ENCODEBLKREG_ref_l0_3_get_mvd_l0_x(data)                                (0x00000FFF&(data))

#define  ENCODEBLKREG_ref_l1_0                                                   0x1800F460
#define  ENCODEBLKREG_ref_l1_0_reg_addr                                          "0xB800F460"
#define  ENCODEBLKREG_ref_l1_0_reg                                               0xB800F460
#define  ENCODEBLKREG_ref_l1_0_inst_addr                                         "0x0010"
#define  set_ENCODEBLKREG_ref_l1_0_reg(data)                                     (*((volatile unsigned int*)ENCODEBLKREG_ref_l1_0_reg)=data)
#define  get_ENCODEBLKREG_ref_l1_0_reg                                           (*((volatile unsigned int*)ENCODEBLKREG_ref_l1_0_reg))
#define  ENCODEBLKREG_ref_l1_0_ref_idx_l1_shift                                  (22)
#define  ENCODEBLKREG_ref_l1_0_mvd_l1_y_shift                                    (12)
#define  ENCODEBLKREG_ref_l1_0_mvd_l1_x_shift                                    (0)
#define  ENCODEBLKREG_ref_l1_0_ref_idx_l1_mask                                   (0x00C00000)
#define  ENCODEBLKREG_ref_l1_0_mvd_l1_y_mask                                     (0x003FF000)
#define  ENCODEBLKREG_ref_l1_0_mvd_l1_x_mask                                     (0x00000FFF)
#define  ENCODEBLKREG_ref_l1_0_ref_idx_l1(data)                                  (0x00C00000&((data)<<22))
#define  ENCODEBLKREG_ref_l1_0_mvd_l1_y(data)                                    (0x003FF000&((data)<<12))
#define  ENCODEBLKREG_ref_l1_0_mvd_l1_x(data)                                    (0x00000FFF&(data))
#define  ENCODEBLKREG_ref_l1_0_get_ref_idx_l1(data)                              ((0x00C00000&(data))>>22)
#define  ENCODEBLKREG_ref_l1_0_get_mvd_l1_y(data)                                ((0x003FF000&(data))>>12)
#define  ENCODEBLKREG_ref_l1_0_get_mvd_l1_x(data)                                (0x00000FFF&(data))

#define  ENCODEBLKREG_ref_l1_1                                                   0x1800F464
#define  ENCODEBLKREG_ref_l1_1_reg_addr                                          "0xB800F464"
#define  ENCODEBLKREG_ref_l1_1_reg                                               0xB800F464
#define  ENCODEBLKREG_ref_l1_1_inst_addr                                         "0x0011"
#define  set_ENCODEBLKREG_ref_l1_1_reg(data)                                     (*((volatile unsigned int*)ENCODEBLKREG_ref_l1_1_reg)=data)
#define  get_ENCODEBLKREG_ref_l1_1_reg                                           (*((volatile unsigned int*)ENCODEBLKREG_ref_l1_1_reg))
#define  ENCODEBLKREG_ref_l1_1_ref_idx_l1_shift                                  (22)
#define  ENCODEBLKREG_ref_l1_1_mvd_l1_y_shift                                    (12)
#define  ENCODEBLKREG_ref_l1_1_mvd_l1_x_shift                                    (0)
#define  ENCODEBLKREG_ref_l1_1_ref_idx_l1_mask                                   (0x00C00000)
#define  ENCODEBLKREG_ref_l1_1_mvd_l1_y_mask                                     (0x003FF000)
#define  ENCODEBLKREG_ref_l1_1_mvd_l1_x_mask                                     (0x00000FFF)
#define  ENCODEBLKREG_ref_l1_1_ref_idx_l1(data)                                  (0x00C00000&((data)<<22))
#define  ENCODEBLKREG_ref_l1_1_mvd_l1_y(data)                                    (0x003FF000&((data)<<12))
#define  ENCODEBLKREG_ref_l1_1_mvd_l1_x(data)                                    (0x00000FFF&(data))
#define  ENCODEBLKREG_ref_l1_1_get_ref_idx_l1(data)                              ((0x00C00000&(data))>>22)
#define  ENCODEBLKREG_ref_l1_1_get_mvd_l1_y(data)                                ((0x003FF000&(data))>>12)
#define  ENCODEBLKREG_ref_l1_1_get_mvd_l1_x(data)                                (0x00000FFF&(data))

#define  ENCODEBLKREG_ref_l1_2                                                   0x1800F468
#define  ENCODEBLKREG_ref_l1_2_reg_addr                                          "0xB800F468"
#define  ENCODEBLKREG_ref_l1_2_reg                                               0xB800F468
#define  ENCODEBLKREG_ref_l1_2_inst_addr                                         "0x0012"
#define  set_ENCODEBLKREG_ref_l1_2_reg(data)                                     (*((volatile unsigned int*)ENCODEBLKREG_ref_l1_2_reg)=data)
#define  get_ENCODEBLKREG_ref_l1_2_reg                                           (*((volatile unsigned int*)ENCODEBLKREG_ref_l1_2_reg))
#define  ENCODEBLKREG_ref_l1_2_ref_idx_l1_shift                                  (22)
#define  ENCODEBLKREG_ref_l1_2_mvd_l1_y_shift                                    (12)
#define  ENCODEBLKREG_ref_l1_2_mvd_l1_x_shift                                    (0)
#define  ENCODEBLKREG_ref_l1_2_ref_idx_l1_mask                                   (0x00C00000)
#define  ENCODEBLKREG_ref_l1_2_mvd_l1_y_mask                                     (0x003FF000)
#define  ENCODEBLKREG_ref_l1_2_mvd_l1_x_mask                                     (0x00000FFF)
#define  ENCODEBLKREG_ref_l1_2_ref_idx_l1(data)                                  (0x00C00000&((data)<<22))
#define  ENCODEBLKREG_ref_l1_2_mvd_l1_y(data)                                    (0x003FF000&((data)<<12))
#define  ENCODEBLKREG_ref_l1_2_mvd_l1_x(data)                                    (0x00000FFF&(data))
#define  ENCODEBLKREG_ref_l1_2_get_ref_idx_l1(data)                              ((0x00C00000&(data))>>22)
#define  ENCODEBLKREG_ref_l1_2_get_mvd_l1_y(data)                                ((0x003FF000&(data))>>12)
#define  ENCODEBLKREG_ref_l1_2_get_mvd_l1_x(data)                                (0x00000FFF&(data))

#define  ENCODEBLKREG_ref_l1_3                                                   0x1800F46C
#define  ENCODEBLKREG_ref_l1_3_reg_addr                                          "0xB800F46C"
#define  ENCODEBLKREG_ref_l1_3_reg                                               0xB800F46C
#define  ENCODEBLKREG_ref_l1_3_inst_addr                                         "0x0013"
#define  set_ENCODEBLKREG_ref_l1_3_reg(data)                                     (*((volatile unsigned int*)ENCODEBLKREG_ref_l1_3_reg)=data)
#define  get_ENCODEBLKREG_ref_l1_3_reg                                           (*((volatile unsigned int*)ENCODEBLKREG_ref_l1_3_reg))
#define  ENCODEBLKREG_ref_l1_3_ref_idx_l1_shift                                  (22)
#define  ENCODEBLKREG_ref_l1_3_mvd_l1_y_shift                                    (12)
#define  ENCODEBLKREG_ref_l1_3_mvd_l1_x_shift                                    (0)
#define  ENCODEBLKREG_ref_l1_3_ref_idx_l1_mask                                   (0x00C00000)
#define  ENCODEBLKREG_ref_l1_3_mvd_l1_y_mask                                     (0x003FF000)
#define  ENCODEBLKREG_ref_l1_3_mvd_l1_x_mask                                     (0x00000FFF)
#define  ENCODEBLKREG_ref_l1_3_ref_idx_l1(data)                                  (0x00C00000&((data)<<22))
#define  ENCODEBLKREG_ref_l1_3_mvd_l1_y(data)                                    (0x003FF000&((data)<<12))
#define  ENCODEBLKREG_ref_l1_3_mvd_l1_x(data)                                    (0x00000FFF&(data))
#define  ENCODEBLKREG_ref_l1_3_get_ref_idx_l1(data)                              ((0x00C00000&(data))>>22)
#define  ENCODEBLKREG_ref_l1_3_get_mvd_l1_y(data)                                ((0x003FF000&(data))>>12)
#define  ENCODEBLKREG_ref_l1_3_get_mvd_l1_x(data)                                (0x00000FFF&(data))

#define  ENCODEBLKREG_total_coef1                                                0x1800F470
#define  ENCODEBLKREG_total_coef1_reg_addr                                       "0xB800F470"
#define  ENCODEBLKREG_total_coef1_reg                                            0xB800F470
#define  ENCODEBLKREG_total_coef1_inst_addr                                      "0x0014"
#define  set_ENCODEBLKREG_total_coef1_reg(data)                                  (*((volatile unsigned int*)ENCODEBLKREG_total_coef1_reg)=data)
#define  get_ENCODEBLKREG_total_coef1_reg                                        (*((volatile unsigned int*)ENCODEBLKREG_total_coef1_reg))
#define  ENCODEBLKREG_total_coef1_left_luma_d_shift                              (15)
#define  ENCODEBLKREG_total_coef1_left_luma_c_shift                              (10)
#define  ENCODEBLKREG_total_coef1_left_luma_b_shift                              (5)
#define  ENCODEBLKREG_total_coef1_left_luma_a_shift                              (0)
#define  ENCODEBLKREG_total_coef1_left_luma_d_mask                               (0x000F8000)
#define  ENCODEBLKREG_total_coef1_left_luma_c_mask                               (0x00007C00)
#define  ENCODEBLKREG_total_coef1_left_luma_b_mask                               (0x000003E0)
#define  ENCODEBLKREG_total_coef1_left_luma_a_mask                               (0x0000001F)
#define  ENCODEBLKREG_total_coef1_left_luma_d(data)                              (0x000F8000&((data)<<15))
#define  ENCODEBLKREG_total_coef1_left_luma_c(data)                              (0x00007C00&((data)<<10))
#define  ENCODEBLKREG_total_coef1_left_luma_b(data)                              (0x000003E0&((data)<<5))
#define  ENCODEBLKREG_total_coef1_left_luma_a(data)                              (0x0000001F&(data))
#define  ENCODEBLKREG_total_coef1_get_left_luma_d(data)                          ((0x000F8000&(data))>>15)
#define  ENCODEBLKREG_total_coef1_get_left_luma_c(data)                          ((0x00007C00&(data))>>10)
#define  ENCODEBLKREG_total_coef1_get_left_luma_b(data)                          ((0x000003E0&(data))>>5)
#define  ENCODEBLKREG_total_coef1_get_left_luma_a(data)                          (0x0000001F&(data))

#define  ENCODEBLKREG_total_coef2                                                0x1800F474
#define  ENCODEBLKREG_total_coef2_reg_addr                                       "0xB800F474"
#define  ENCODEBLKREG_total_coef2_reg                                            0xB800F474
#define  ENCODEBLKREG_total_coef2_inst_addr                                      "0x0015"
#define  set_ENCODEBLKREG_total_coef2_reg(data)                                  (*((volatile unsigned int*)ENCODEBLKREG_total_coef2_reg)=data)
#define  get_ENCODEBLKREG_total_coef2_reg                                        (*((volatile unsigned int*)ENCODEBLKREG_total_coef2_reg))
#define  ENCODEBLKREG_total_coef2_left_cb_a_shift                                (15)
#define  ENCODEBLKREG_total_coef2_left_cb_b_shift                                (10)
#define  ENCODEBLKREG_total_coef2_left_cr_a_shift                                (5)
#define  ENCODEBLKREG_total_coef2_left_cr_b_shift                                (0)
#define  ENCODEBLKREG_total_coef2_left_cb_a_mask                                 (0x000F8000)
#define  ENCODEBLKREG_total_coef2_left_cb_b_mask                                 (0x00007C00)
#define  ENCODEBLKREG_total_coef2_left_cr_a_mask                                 (0x000003E0)
#define  ENCODEBLKREG_total_coef2_left_cr_b_mask                                 (0x0000001F)
#define  ENCODEBLKREG_total_coef2_left_cb_a(data)                                (0x000F8000&((data)<<15))
#define  ENCODEBLKREG_total_coef2_left_cb_b(data)                                (0x00007C00&((data)<<10))
#define  ENCODEBLKREG_total_coef2_left_cr_a(data)                                (0x000003E0&((data)<<5))
#define  ENCODEBLKREG_total_coef2_left_cr_b(data)                                (0x0000001F&(data))
#define  ENCODEBLKREG_total_coef2_get_left_cb_a(data)                            ((0x000F8000&(data))>>15)
#define  ENCODEBLKREG_total_coef2_get_left_cb_b(data)                            ((0x00007C00&(data))>>10)
#define  ENCODEBLKREG_total_coef2_get_left_cr_a(data)                            ((0x000003E0&(data))>>5)
#define  ENCODEBLKREG_total_coef2_get_left_cr_b(data)                            (0x0000001F&(data))

#define  ENCODEBLKREG_cabac_left_0                                               0x1800F478
#define  ENCODEBLKREG_cabac_left_0_reg_addr                                      "0xB800F478"
#define  ENCODEBLKREG_cabac_left_0_reg                                           0xB800F478
#define  ENCODEBLKREG_cabac_left_0_inst_addr                                     "0x0016"
#define  set_ENCODEBLKREG_cabac_left_0_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_0_reg)=data)
#define  get_ENCODEBLKREG_cabac_left_0_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_0_reg))
#define  ENCODEBLKREG_cabac_left_0_left_nb_shift                                 (0)
#define  ENCODEBLKREG_cabac_left_0_left_nb_mask                                  (0xFFFFFFFF)
#define  ENCODEBLKREG_cabac_left_0_left_nb(data)                                 (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_cabac_left_0_get_left_nb(data)                             (0xFFFFFFFF&(data))

#define  ENCODEBLKREG_cabac_left_1                                               0x1800F47C
#define  ENCODEBLKREG_cabac_left_1_reg_addr                                      "0xB800F47C"
#define  ENCODEBLKREG_cabac_left_1_reg                                           0xB800F47C
#define  ENCODEBLKREG_cabac_left_1_inst_addr                                     "0x0017"
#define  set_ENCODEBLKREG_cabac_left_1_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_1_reg)=data)
#define  get_ENCODEBLKREG_cabac_left_1_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_1_reg))
#define  ENCODEBLKREG_cabac_left_1_left_nb_shift                                 (0)
#define  ENCODEBLKREG_cabac_left_1_left_nb_mask                                  (0xFFFFFFFF)
#define  ENCODEBLKREG_cabac_left_1_left_nb(data)                                 (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_cabac_left_1_get_left_nb(data)                             (0xFFFFFFFF&(data))

#define  ENCODEBLKREG_cabac_left_2                                               0x1800F480
#define  ENCODEBLKREG_cabac_left_2_reg_addr                                      "0xB800F480"
#define  ENCODEBLKREG_cabac_left_2_reg                                           0xB800F480
#define  ENCODEBLKREG_cabac_left_2_inst_addr                                     "0x0018"
#define  set_ENCODEBLKREG_cabac_left_2_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_2_reg)=data)
#define  get_ENCODEBLKREG_cabac_left_2_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_2_reg))
#define  ENCODEBLKREG_cabac_left_2_left_nb_shift                                 (0)
#define  ENCODEBLKREG_cabac_left_2_left_nb_mask                                  (0xFFFFFFFF)
#define  ENCODEBLKREG_cabac_left_2_left_nb(data)                                 (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_cabac_left_2_get_left_nb(data)                             (0xFFFFFFFF&(data))

#define  ENCODEBLKREG_cabac_left_3                                               0x1800F484
#define  ENCODEBLKREG_cabac_left_3_reg_addr                                      "0xB800F484"
#define  ENCODEBLKREG_cabac_left_3_reg                                           0xB800F484
#define  ENCODEBLKREG_cabac_left_3_inst_addr                                     "0x0019"
#define  set_ENCODEBLKREG_cabac_left_3_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_3_reg)=data)
#define  get_ENCODEBLKREG_cabac_left_3_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_3_reg))
#define  ENCODEBLKREG_cabac_left_3_left_nb_shift                                 (0)
#define  ENCODEBLKREG_cabac_left_3_left_nb_mask                                  (0xFFFFFFFF)
#define  ENCODEBLKREG_cabac_left_3_left_nb(data)                                 (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_cabac_left_3_get_left_nb(data)                             (0xFFFFFFFF&(data))

#define  ENCODEBLKREG_cabac_left_4                                               0x1800F488
#define  ENCODEBLKREG_cabac_left_4_reg_addr                                      "0xB800F488"
#define  ENCODEBLKREG_cabac_left_4_reg                                           0xB800F488
#define  ENCODEBLKREG_cabac_left_4_inst_addr                                     "0x001A"
#define  set_ENCODEBLKREG_cabac_left_4_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_4_reg)=data)
#define  get_ENCODEBLKREG_cabac_left_4_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_4_reg))
#define  ENCODEBLKREG_cabac_left_4_left_nb_shift                                 (0)
#define  ENCODEBLKREG_cabac_left_4_left_nb_mask                                  (0xFFFFFFFF)
#define  ENCODEBLKREG_cabac_left_4_left_nb(data)                                 (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_cabac_left_4_get_left_nb(data)                             (0xFFFFFFFF&(data))

#define  ENCODEBLKREG_cabac_left_5                                               0x1800F48C
#define  ENCODEBLKREG_cabac_left_5_reg_addr                                      "0xB800F48C"
#define  ENCODEBLKREG_cabac_left_5_reg                                           0xB800F48C
#define  ENCODEBLKREG_cabac_left_5_inst_addr                                     "0x001B"
#define  set_ENCODEBLKREG_cabac_left_5_reg(data)                                 (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_5_reg)=data)
#define  get_ENCODEBLKREG_cabac_left_5_reg                                       (*((volatile unsigned int*)ENCODEBLKREG_cabac_left_5_reg))
#define  ENCODEBLKREG_cabac_left_5_left_nb_shift                                 (0)
#define  ENCODEBLKREG_cabac_left_5_left_nb_mask                                  (0xFFFFFFFF)
#define  ENCODEBLKREG_cabac_left_5_left_nb(data)                                 (0xFFFFFFFF&(data))
#define  ENCODEBLKREG_cabac_left_5_get_left_nb(data)                             (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ENCODEBLKREG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  vlc_bank:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  tq_bank:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cm_mstr:2;
    };
}encodeblkreg_cm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  vlc_pred_counter:8;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  vlc_curmb_addr:8;
    };
}encodeblkreg_curadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  entropy_coding_mode:1;
        RBus_UInt32  pic_init_qp:6;
        RBus_UInt32  direct_8x8_inferflg:1;
        RBus_UInt32  transform_8x8_mode_flg:1;
        RBus_UInt32  num_ref_idx_l0_active_minus1:5;
        RBus_UInt32  num_ref_idx_l1_active_minus1:5;
    };
}encodeblkreg_h264_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  pic_type:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  slice_qp_delta:7;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cabac_init_idc:2;
    };
}encodeblkreg_h264_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enc_bitcnt:32;
    };
}encodeblkreg_vlc_bitcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  qp_delta:6;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  mbtype:4;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  transform_size_8x8:1;
    };
}encodeblkreg_vlc_mbtype_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cbp6bits:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  subblkpat:24;
    };
}encodeblkreg_vlc_cbp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  mbpartition:9;
    };
}encodeblkreg_mb_partition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mb_pred_mode:8;
    };
}encodeblkreg_mb_predmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rem_mode:32;
    };
}encodeblkreg_intra_pred_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ref_idx_l0:2;
        RBus_UInt32  mvd_l0_y:10;
        RBus_UInt32  mvd_l0_x:12;
    };
}encodeblkreg_ref_l0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ref_idx_l1:2;
        RBus_UInt32  mvd_l1_y:10;
        RBus_UInt32  mvd_l1_x:12;
    };
}encodeblkreg_ref_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  left_luma_d:5;
        RBus_UInt32  left_luma_c:5;
        RBus_UInt32  left_luma_b:5;
        RBus_UInt32  left_luma_a:5;
    };
}encodeblkreg_total_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  left_cb_a:5;
        RBus_UInt32  left_cb_b:5;
        RBus_UInt32  left_cr_a:5;
        RBus_UInt32  left_cr_b:5;
    };
}encodeblkreg_total_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_nb:32;
    };
}encodeblkreg_cabac_left_RBUS;

#else //apply LITTLE_ENDIAN

//======ENCODEBLKREG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm_mstr:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  tq_bank:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  vlc_bank:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:25;
    };
}encodeblkreg_cm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vlc_curmb_addr:8;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  vlc_pred_counter:8;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  res1:14;
    };
}encodeblkreg_curadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  num_ref_idx_l1_active_minus1:5;
        RBus_UInt32  num_ref_idx_l0_active_minus1:5;
        RBus_UInt32  transform_8x8_mode_flg:1;
        RBus_UInt32  direct_8x8_inferflg:1;
        RBus_UInt32  pic_init_qp:6;
        RBus_UInt32  entropy_coding_mode:1;
        RBus_UInt32  res1:13;
    };
}encodeblkreg_h264_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cabac_init_idc:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  slice_qp_delta:7;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  pic_type:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:17;
    };
}encodeblkreg_h264_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enc_bitcnt:32;
    };
}encodeblkreg_vlc_bitcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  transform_size_8x8:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mbtype:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  qp_delta:6;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  res1:11;
    };
}encodeblkreg_vlc_mbtype_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subblkpat:24;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cbp6bits:6;
        RBus_UInt32  write_enable2:1;
    };
}encodeblkreg_vlc_cbp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbpartition:9;
        RBus_UInt32  res1:23;
    };
}encodeblkreg_mb_partition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_pred_mode:8;
        RBus_UInt32  res1:24;
    };
}encodeblkreg_mb_predmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rem_mode:32;
    };
}encodeblkreg_intra_pred_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvd_l0_x:12;
        RBus_UInt32  mvd_l0_y:10;
        RBus_UInt32  ref_idx_l0:2;
        RBus_UInt32  res1:8;
    };
}encodeblkreg_ref_l0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvd_l1_x:12;
        RBus_UInt32  mvd_l1_y:10;
        RBus_UInt32  ref_idx_l1:2;
        RBus_UInt32  res1:8;
    };
}encodeblkreg_ref_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_luma_a:5;
        RBus_UInt32  left_luma_b:5;
        RBus_UInt32  left_luma_c:5;
        RBus_UInt32  left_luma_d:5;
        RBus_UInt32  res1:12;
    };
}encodeblkreg_total_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_cr_b:5;
        RBus_UInt32  left_cr_a:5;
        RBus_UInt32  left_cb_b:5;
        RBus_UInt32  left_cb_a:5;
        RBus_UInt32  res1:12;
    };
}encodeblkreg_total_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_nb:32;
    };
}encodeblkreg_cabac_left_RBUS;




#endif 


#endif 
