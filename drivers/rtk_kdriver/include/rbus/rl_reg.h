/**
* @file Mac5_VE_RL_Arch_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_RL_REG_H_
#define _RBUS_RL_REG_H_

#include "rbus_types.h"



//  RL Register Address
#define  RL_RLCNTL                                                               0x1800EC00
#define  RL_RLCNTL_reg_addr                                                      "0xB800EC00"
#define  RL_RLCNTL_reg                                                           0xB800EC00
#define  RL_RLCNTL_inst_addr                                                     "0x0000"
#define  set_RL_RLCNTL_reg(data)                                                 (*((volatile unsigned int*)RL_RLCNTL_reg)=data)
#define  get_RL_RLCNTL_reg                                                       (*((volatile unsigned int*)RL_RLCNTL_reg))
#define  RL_RLCNTL_disppic_h_shift                                               (16)
#define  RL_RLCNTL_disppic_w_shift                                               (1)
#define  RL_RLCNTL_cur_rangeredfrm_shift                                         (0)
#define  RL_RLCNTL_disppic_h_mask                                                (0x1FFF0000)
#define  RL_RLCNTL_disppic_w_mask                                                (0x00007FFE)
#define  RL_RLCNTL_cur_rangeredfrm_mask                                          (0x00000001)
#define  RL_RLCNTL_disppic_h(data)                                               (0x1FFF0000&((data)<<16))
#define  RL_RLCNTL_disppic_w(data)                                               (0x00007FFE&((data)<<1))
#define  RL_RLCNTL_cur_rangeredfrm(data)                                         (0x00000001&(data))
#define  RL_RLCNTL_get_disppic_h(data)                                           ((0x1FFF0000&(data))>>16)
#define  RL_RLCNTL_get_disppic_w(data)                                           ((0x00007FFE&(data))>>1)
#define  RL_RLCNTL_get_cur_rangeredfrm(data)                                     (0x00000001&(data))

#define  RL_RLCNTL2                                                              0x1800EC04
#define  RL_RLCNTL2_reg_addr                                                     "0xB800EC04"
#define  RL_RLCNTL2_reg                                                          0xB800EC04
#define  RL_RLCNTL2_inst_addr                                                    "0x0001"
#define  set_RL_RLCNTL2_reg(data)                                                (*((volatile unsigned int*)RL_RLCNTL2_reg)=data)
#define  get_RL_RLCNTL2_reg                                                      (*((volatile unsigned int*)RL_RLCNTL2_reg))
#define  RL_RLCNTL2_write_enable3_shift                                          (13)
#define  RL_RLCNTL2_rmem_wptr_rst_shift                                          (12)
#define  RL_RLCNTL2_write_enable2_shift                                          (11)
#define  RL_RLCNTL2_ldmc_bypass_shift                                            (10)
#define  RL_RLCNTL2_pred_enable_shift                                            (9)
#define  RL_RLCNTL2_ldmc_enable_shift                                            (8)
#define  RL_RLCNTL2_write_enable1_shift                                          (7)
#define  RL_RLCNTL2_manual_thresh_ena_shift                                      (6)
#define  RL_RLCNTL2_rm_threshold_shift                                           (0)
#define  RL_RLCNTL2_write_enable3_mask                                           (0x00002000)
#define  RL_RLCNTL2_rmem_wptr_rst_mask                                           (0x00001000)
#define  RL_RLCNTL2_write_enable2_mask                                           (0x00000800)
#define  RL_RLCNTL2_ldmc_bypass_mask                                             (0x00000400)
#define  RL_RLCNTL2_pred_enable_mask                                             (0x00000200)
#define  RL_RLCNTL2_ldmc_enable_mask                                             (0x00000100)
#define  RL_RLCNTL2_write_enable1_mask                                           (0x00000080)
#define  RL_RLCNTL2_manual_thresh_ena_mask                                       (0x00000040)
#define  RL_RLCNTL2_rm_threshold_mask                                            (0x0000003F)
#define  RL_RLCNTL2_write_enable3(data)                                          (0x00002000&((data)<<13))
#define  RL_RLCNTL2_rmem_wptr_rst(data)                                          (0x00001000&((data)<<12))
#define  RL_RLCNTL2_write_enable2(data)                                          (0x00000800&((data)<<11))
#define  RL_RLCNTL2_ldmc_bypass(data)                                            (0x00000400&((data)<<10))
#define  RL_RLCNTL2_pred_enable(data)                                            (0x00000200&((data)<<9))
#define  RL_RLCNTL2_ldmc_enable(data)                                            (0x00000100&((data)<<8))
#define  RL_RLCNTL2_write_enable1(data)                                          (0x00000080&((data)<<7))
#define  RL_RLCNTL2_manual_thresh_ena(data)                                      (0x00000040&((data)<<6))
#define  RL_RLCNTL2_rm_threshold(data)                                           (0x0000003F&(data))
#define  RL_RLCNTL2_get_write_enable3(data)                                      ((0x00002000&(data))>>13)
#define  RL_RLCNTL2_get_rmem_wptr_rst(data)                                      ((0x00001000&(data))>>12)
#define  RL_RLCNTL2_get_write_enable2(data)                                      ((0x00000800&(data))>>11)
#define  RL_RLCNTL2_get_ldmc_bypass(data)                                        ((0x00000400&(data))>>10)
#define  RL_RLCNTL2_get_pred_enable(data)                                        ((0x00000200&(data))>>9)
#define  RL_RLCNTL2_get_ldmc_enable(data)                                        ((0x00000100&(data))>>8)
#define  RL_RLCNTL2_get_write_enable1(data)                                      ((0x00000080&(data))>>7)
#define  RL_RLCNTL2_get_manual_thresh_ena(data)                                  ((0x00000040&(data))>>6)
#define  RL_RLCNTL2_get_rm_threshold(data)                                       (0x0000003F&(data))

#define  RL_CCPAR                                                                0x1800EC08
#define  RL_CCPAR_reg_addr                                                       "0xB800EC08"
#define  RL_CCPAR_reg                                                            0xB800EC08
#define  RL_CCPAR_inst_addr                                                      "0x0002"
#define  set_RL_CCPAR_reg(data)                                                  (*((volatile unsigned int*)RL_CCPAR_reg)=data)
#define  get_RL_CCPAR_reg                                                        (*((volatile unsigned int*)RL_CCPAR_reg))
#define  RL_CCPAR_hevc_zidx_shift                                                (24)
#define  RL_CCPAR_hevc_log2cbsize_minus3_shift                                   (22)
#define  RL_CCPAR_pictype_shift                                                  (19)
#define  RL_CCPAR_first_mb_shift                                                 (18)
#define  RL_CCPAR_cur_mb_x_shift                                                 (9)
#define  RL_CCPAR_cur_mb_y_shift                                                 (0)
#define  RL_CCPAR_hevc_zidx_mask                                                 (0xFF000000)
#define  RL_CCPAR_hevc_log2cbsize_minus3_mask                                    (0x00C00000)
#define  RL_CCPAR_pictype_mask                                                   (0x00380000)
#define  RL_CCPAR_first_mb_mask                                                  (0x00040000)
#define  RL_CCPAR_cur_mb_x_mask                                                  (0x0003FE00)
#define  RL_CCPAR_cur_mb_y_mask                                                  (0x000001FF)
#define  RL_CCPAR_hevc_zidx(data)                                                (0xFF000000&((data)<<24))
#define  RL_CCPAR_hevc_log2cbsize_minus3(data)                                   (0x00C00000&((data)<<22))
#define  RL_CCPAR_pictype(data)                                                  (0x00380000&((data)<<19))
#define  RL_CCPAR_first_mb(data)                                                 (0x00040000&((data)<<18))
#define  RL_CCPAR_cur_mb_x(data)                                                 (0x0003FE00&((data)<<9))
#define  RL_CCPAR_cur_mb_y(data)                                                 (0x000001FF&(data))
#define  RL_CCPAR_get_hevc_zidx(data)                                            ((0xFF000000&(data))>>24)
#define  RL_CCPAR_get_hevc_log2cbsize_minus3(data)                               ((0x00C00000&(data))>>22)
#define  RL_CCPAR_get_pictype(data)                                              ((0x00380000&(data))>>19)
#define  RL_CCPAR_get_first_mb(data)                                             ((0x00040000&(data))>>18)
#define  RL_CCPAR_get_cur_mb_x(data)                                             ((0x0003FE00&(data))>>9)
#define  RL_CCPAR_get_cur_mb_y(data)                                             (0x000001FF&(data))

#define  RL_H264CCPAR                                                            0x1800EC0C
#define  RL_H264CCPAR_reg_addr                                                   "0xB800EC0C"
#define  RL_H264CCPAR_reg                                                        0xB800EC0C
#define  RL_H264CCPAR_inst_addr                                                  "0x0003"
#define  set_RL_H264CCPAR_reg(data)                                              (*((volatile unsigned int*)RL_H264CCPAR_reg)=data)
#define  get_RL_H264CCPAR_reg                                                    (*((volatile unsigned int*)RL_H264CCPAR_reg))
#define  RL_H264CCPAR_paddingcu_shift                                            (12)
#define  RL_H264CCPAR_dummycolctb_shift                                          (11)
#define  RL_H264CCPAR_dummyrowctb_shift                                          (10)
#define  RL_H264CCPAR_mb_field_decoding_flag_shift                               (9)
#define  RL_H264CCPAR_mb_partition_shift                                         (0)
#define  RL_H264CCPAR_paddingcu_mask                                             (0x00001000)
#define  RL_H264CCPAR_dummycolctb_mask                                           (0x00000800)
#define  RL_H264CCPAR_dummyrowctb_mask                                           (0x00000400)
#define  RL_H264CCPAR_mb_field_decoding_flag_mask                                (0x00000200)
#define  RL_H264CCPAR_mb_partition_mask                                          (0x000001FF)
#define  RL_H264CCPAR_paddingcu(data)                                            (0x00001000&((data)<<12))
#define  RL_H264CCPAR_dummycolctb(data)                                          (0x00000800&((data)<<11))
#define  RL_H264CCPAR_dummyrowctb(data)                                          (0x00000400&((data)<<10))
#define  RL_H264CCPAR_mb_field_decoding_flag(data)                               (0x00000200&((data)<<9))
#define  RL_H264CCPAR_mb_partition(data)                                         (0x000001FF&(data))
#define  RL_H264CCPAR_get_paddingcu(data)                                        ((0x00001000&(data))>>12)
#define  RL_H264CCPAR_get_dummycolctb(data)                                      ((0x00000800&(data))>>11)
#define  RL_H264CCPAR_get_dummyrowctb(data)                                      ((0x00000400&(data))>>10)
#define  RL_H264CCPAR_get_mb_field_decoding_flag(data)                           ((0x00000200&(data))>>9)
#define  RL_H264CCPAR_get_mb_partition(data)                                     (0x000001FF&(data))

#define  RL_VC1CCPAR                                                             0x1800EC10
#define  RL_VC1CCPAR_reg_addr                                                    "0xB800EC10"
#define  RL_VC1CCPAR_reg                                                         0xB800EC10
#define  RL_VC1CCPAR_inst_addr                                                   "0x0004"
#define  set_RL_VC1CCPAR_reg(data)                                               (*((volatile unsigned int*)RL_VC1CCPAR_reg)=data)
#define  get_RL_VC1CCPAR_reg                                                     (*((volatile unsigned int*)RL_VC1CCPAR_reg))
#define  RL_VC1CCPAR_intramb_flag_shift                                          (21)
#define  RL_VC1CCPAR_intra_flag_shift                                            (16)
#define  RL_VC1CCPAR_submb_partition_shift                                       (4)
#define  RL_VC1CCPAR_mvtype_shift                                                (2)
#define  RL_VC1CCPAR_fieldtx_shift                                               (1)
#define  RL_VC1CCPAR_overflag_shift                                              (0)
#define  RL_VC1CCPAR_intramb_flag_mask                                           (0x00200000)
#define  RL_VC1CCPAR_intra_flag_mask                                             (0x001F0000)
#define  RL_VC1CCPAR_submb_partition_mask                                        (0x0000FFF0)
#define  RL_VC1CCPAR_mvtype_mask                                                 (0x0000000C)
#define  RL_VC1CCPAR_fieldtx_mask                                                (0x00000002)
#define  RL_VC1CCPAR_overflag_mask                                               (0x00000001)
#define  RL_VC1CCPAR_intramb_flag(data)                                          (0x00200000&((data)<<21))
#define  RL_VC1CCPAR_intra_flag(data)                                            (0x001F0000&((data)<<16))
#define  RL_VC1CCPAR_submb_partition(data)                                       (0x0000FFF0&((data)<<4))
#define  RL_VC1CCPAR_mvtype(data)                                                (0x0000000C&((data)<<2))
#define  RL_VC1CCPAR_fieldtx(data)                                               (0x00000002&((data)<<1))
#define  RL_VC1CCPAR_overflag(data)                                              (0x00000001&(data))
#define  RL_VC1CCPAR_get_intramb_flag(data)                                      ((0x00200000&(data))>>21)
#define  RL_VC1CCPAR_get_intra_flag(data)                                        ((0x001F0000&(data))>>16)
#define  RL_VC1CCPAR_get_submb_partition(data)                                   ((0x0000FFF0&(data))>>4)
#define  RL_VC1CCPAR_get_mvtype(data)                                            ((0x0000000C&(data))>>2)
#define  RL_VC1CCPAR_get_fieldtx(data)                                           ((0x00000002&(data))>>1)
#define  RL_VC1CCPAR_get_overflag(data)                                          (0x00000001&(data))

#define  RL_POPAR                                                                0x1800EC14
#define  RL_POPAR_reg_addr                                                       "0xB800EC14"
#define  RL_POPAR_reg                                                            0xB800EC14
#define  RL_POPAR_inst_addr                                                      "0x0005"
#define  set_RL_POPAR_reg(data)                                                  (*((volatile unsigned int*)RL_POPAR_reg)=data)
#define  get_RL_POPAR_reg                                                        (*((volatile unsigned int*)RL_POPAR_reg))
#define  RL_POPAR_chroma_predict_part0_shift                                     (14)
#define  RL_POPAR_chroma_predict_part1_shift                                     (12)
#define  RL_POPAR_chroma_predict_part2_shift                                     (10)
#define  RL_POPAR_chroma_predict_part3_shift                                     (8)
#define  RL_POPAR_inter_predict_part0_shift                                      (6)
#define  RL_POPAR_inter_predict_part1_shift                                      (4)
#define  RL_POPAR_inter_predict_part2_shift                                      (2)
#define  RL_POPAR_inter_predict_part3_shift                                      (0)
#define  RL_POPAR_chroma_predict_part0_mask                                      (0x0000C000)
#define  RL_POPAR_chroma_predict_part1_mask                                      (0x00003000)
#define  RL_POPAR_chroma_predict_part2_mask                                      (0x00000C00)
#define  RL_POPAR_chroma_predict_part3_mask                                      (0x00000300)
#define  RL_POPAR_inter_predict_part0_mask                                       (0x000000C0)
#define  RL_POPAR_inter_predict_part1_mask                                       (0x00000030)
#define  RL_POPAR_inter_predict_part2_mask                                       (0x0000000C)
#define  RL_POPAR_inter_predict_part3_mask                                       (0x00000003)
#define  RL_POPAR_chroma_predict_part0(data)                                     (0x0000C000&((data)<<14))
#define  RL_POPAR_chroma_predict_part1(data)                                     (0x00003000&((data)<<12))
#define  RL_POPAR_chroma_predict_part2(data)                                     (0x00000C00&((data)<<10))
#define  RL_POPAR_chroma_predict_part3(data)                                     (0x00000300&((data)<<8))
#define  RL_POPAR_inter_predict_part0(data)                                      (0x000000C0&((data)<<6))
#define  RL_POPAR_inter_predict_part1(data)                                      (0x00000030&((data)<<4))
#define  RL_POPAR_inter_predict_part2(data)                                      (0x0000000C&((data)<<2))
#define  RL_POPAR_inter_predict_part3(data)                                      (0x00000003&(data))
#define  RL_POPAR_get_chroma_predict_part0(data)                                 ((0x0000C000&(data))>>14)
#define  RL_POPAR_get_chroma_predict_part1(data)                                 ((0x00003000&(data))>>12)
#define  RL_POPAR_get_chroma_predict_part2(data)                                 ((0x00000C00&(data))>>10)
#define  RL_POPAR_get_chroma_predict_part3(data)                                 ((0x00000300&(data))>>8)
#define  RL_POPAR_get_inter_predict_part0(data)                                  ((0x000000C0&(data))>>6)
#define  RL_POPAR_get_inter_predict_part1(data)                                  ((0x00000030&(data))>>4)
#define  RL_POPAR_get_inter_predict_part2(data)                                  ((0x0000000C&(data))>>2)
#define  RL_POPAR_get_inter_predict_part3(data)                                  (0x00000003&(data))

#define  RL_L0REFDMA_0                                                           0x1800E500
#define  RL_L0REFDMA_0_reg_addr                                                  "0xB800E500"
#define  RL_L0REFDMA_0_reg                                                       0xB800E500
#define  RL_L0REFDMA_0_inst_addr                                                 "0x0006"
#define  set_RL_L0REFDMA_0_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_0_reg)=data)
#define  get_RL_L0REFDMA_0_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_0_reg))
#define  RL_L0REFDMA_0_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_0_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_0_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_0_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_0_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_0_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_0_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_0_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_0_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_0_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_0_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_0_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_0_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_0_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_0_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_0_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_1                                                           0x1800E504
#define  RL_L0REFDMA_1_reg_addr                                                  "0xB800E504"
#define  RL_L0REFDMA_1_reg                                                       0xB800E504
#define  RL_L0REFDMA_1_inst_addr                                                 "0x0007"
#define  set_RL_L0REFDMA_1_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_1_reg)=data)
#define  get_RL_L0REFDMA_1_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_1_reg))
#define  RL_L0REFDMA_1_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_1_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_1_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_1_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_1_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_1_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_1_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_1_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_1_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_1_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_1_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_1_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_1_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_1_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_1_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_1_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_2                                                           0x1800E508
#define  RL_L0REFDMA_2_reg_addr                                                  "0xB800E508"
#define  RL_L0REFDMA_2_reg                                                       0xB800E508
#define  RL_L0REFDMA_2_inst_addr                                                 "0x0008"
#define  set_RL_L0REFDMA_2_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_2_reg)=data)
#define  get_RL_L0REFDMA_2_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_2_reg))
#define  RL_L0REFDMA_2_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_2_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_2_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_2_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_2_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_2_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_2_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_2_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_2_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_2_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_2_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_2_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_2_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_2_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_2_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_2_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_3                                                           0x1800E50C
#define  RL_L0REFDMA_3_reg_addr                                                  "0xB800E50C"
#define  RL_L0REFDMA_3_reg                                                       0xB800E50C
#define  RL_L0REFDMA_3_inst_addr                                                 "0x0009"
#define  set_RL_L0REFDMA_3_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_3_reg)=data)
#define  get_RL_L0REFDMA_3_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_3_reg))
#define  RL_L0REFDMA_3_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_3_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_3_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_3_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_3_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_3_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_3_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_3_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_3_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_3_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_3_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_3_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_3_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_3_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_3_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_3_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_4                                                           0x1800E510
#define  RL_L0REFDMA_4_reg_addr                                                  "0xB800E510"
#define  RL_L0REFDMA_4_reg                                                       0xB800E510
#define  RL_L0REFDMA_4_inst_addr                                                 "0x000A"
#define  set_RL_L0REFDMA_4_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_4_reg)=data)
#define  get_RL_L0REFDMA_4_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_4_reg))
#define  RL_L0REFDMA_4_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_4_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_4_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_4_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_4_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_4_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_4_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_4_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_4_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_4_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_4_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_4_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_4_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_4_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_4_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_4_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_5                                                           0x1800E514
#define  RL_L0REFDMA_5_reg_addr                                                  "0xB800E514"
#define  RL_L0REFDMA_5_reg                                                       0xB800E514
#define  RL_L0REFDMA_5_inst_addr                                                 "0x000B"
#define  set_RL_L0REFDMA_5_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_5_reg)=data)
#define  get_RL_L0REFDMA_5_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_5_reg))
#define  RL_L0REFDMA_5_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_5_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_5_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_5_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_5_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_5_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_5_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_5_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_5_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_5_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_5_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_5_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_5_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_5_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_5_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_5_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_6                                                           0x1800E518
#define  RL_L0REFDMA_6_reg_addr                                                  "0xB800E518"
#define  RL_L0REFDMA_6_reg                                                       0xB800E518
#define  RL_L0REFDMA_6_inst_addr                                                 "0x000C"
#define  set_RL_L0REFDMA_6_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_6_reg)=data)
#define  get_RL_L0REFDMA_6_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_6_reg))
#define  RL_L0REFDMA_6_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_6_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_6_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_6_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_6_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_6_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_6_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_6_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_6_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_6_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_6_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_6_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_6_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_6_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_6_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_6_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_7                                                           0x1800E51C
#define  RL_L0REFDMA_7_reg_addr                                                  "0xB800E51C"
#define  RL_L0REFDMA_7_reg                                                       0xB800E51C
#define  RL_L0REFDMA_7_inst_addr                                                 "0x000D"
#define  set_RL_L0REFDMA_7_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_7_reg)=data)
#define  get_RL_L0REFDMA_7_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_7_reg))
#define  RL_L0REFDMA_7_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_7_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_7_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_7_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_7_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_7_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_7_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_7_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_7_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_7_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_7_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_7_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_7_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_7_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_7_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_7_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_8                                                           0x1800E520
#define  RL_L0REFDMA_8_reg_addr                                                  "0xB800E520"
#define  RL_L0REFDMA_8_reg                                                       0xB800E520
#define  RL_L0REFDMA_8_inst_addr                                                 "0x000E"
#define  set_RL_L0REFDMA_8_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_8_reg)=data)
#define  get_RL_L0REFDMA_8_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_8_reg))
#define  RL_L0REFDMA_8_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_8_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_8_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_8_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_8_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_8_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_8_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_8_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_8_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_8_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_8_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_8_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_8_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_8_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_8_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_8_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_9                                                           0x1800E524
#define  RL_L0REFDMA_9_reg_addr                                                  "0xB800E524"
#define  RL_L0REFDMA_9_reg                                                       0xB800E524
#define  RL_L0REFDMA_9_inst_addr                                                 "0x000F"
#define  set_RL_L0REFDMA_9_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_9_reg)=data)
#define  get_RL_L0REFDMA_9_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_9_reg))
#define  RL_L0REFDMA_9_ref_rangeredfrm_shift                                     (15)
#define  RL_L0REFDMA_9_bottom_field_flag_shift                                   (14)
#define  RL_L0REFDMA_9_lu_addr_index_shift                                       (7)
#define  RL_L0REFDMA_9_ch_addr_index_shift                                       (0)
#define  RL_L0REFDMA_9_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L0REFDMA_9_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L0REFDMA_9_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L0REFDMA_9_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L0REFDMA_9_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L0REFDMA_9_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L0REFDMA_9_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_9_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L0REFDMA_9_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_9_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_9_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_9_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L0REFDMA_10                                                          0x1800E528
#define  RL_L0REFDMA_10_reg_addr                                                 "0xB800E528"
#define  RL_L0REFDMA_10_reg                                                      0xB800E528
#define  RL_L0REFDMA_10_inst_addr                                                "0x0010"
#define  set_RL_L0REFDMA_10_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_10_reg)=data)
#define  get_RL_L0REFDMA_10_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_10_reg))
#define  RL_L0REFDMA_10_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_10_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_10_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_10_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_10_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_10_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_10_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_10_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_10_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_10_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_10_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_10_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_10_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_10_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_10_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_10_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_11                                                          0x1800E52C
#define  RL_L0REFDMA_11_reg_addr                                                 "0xB800E52C"
#define  RL_L0REFDMA_11_reg                                                      0xB800E52C
#define  RL_L0REFDMA_11_inst_addr                                                "0x0011"
#define  set_RL_L0REFDMA_11_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_11_reg)=data)
#define  get_RL_L0REFDMA_11_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_11_reg))
#define  RL_L0REFDMA_11_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_11_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_11_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_11_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_11_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_11_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_11_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_11_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_11_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_11_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_11_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_11_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_11_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_11_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_11_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_11_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_12                                                          0x1800E530
#define  RL_L0REFDMA_12_reg_addr                                                 "0xB800E530"
#define  RL_L0REFDMA_12_reg                                                      0xB800E530
#define  RL_L0REFDMA_12_inst_addr                                                "0x0012"
#define  set_RL_L0REFDMA_12_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_12_reg)=data)
#define  get_RL_L0REFDMA_12_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_12_reg))
#define  RL_L0REFDMA_12_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_12_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_12_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_12_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_12_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_12_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_12_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_12_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_12_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_12_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_12_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_12_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_12_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_12_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_12_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_12_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_13                                                          0x1800E534
#define  RL_L0REFDMA_13_reg_addr                                                 "0xB800E534"
#define  RL_L0REFDMA_13_reg                                                      0xB800E534
#define  RL_L0REFDMA_13_inst_addr                                                "0x0013"
#define  set_RL_L0REFDMA_13_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_13_reg)=data)
#define  get_RL_L0REFDMA_13_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_13_reg))
#define  RL_L0REFDMA_13_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_13_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_13_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_13_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_13_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_13_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_13_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_13_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_13_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_13_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_13_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_13_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_13_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_13_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_13_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_13_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_14                                                          0x1800E538
#define  RL_L0REFDMA_14_reg_addr                                                 "0xB800E538"
#define  RL_L0REFDMA_14_reg                                                      0xB800E538
#define  RL_L0REFDMA_14_inst_addr                                                "0x0014"
#define  set_RL_L0REFDMA_14_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_14_reg)=data)
#define  get_RL_L0REFDMA_14_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_14_reg))
#define  RL_L0REFDMA_14_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_14_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_14_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_14_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_14_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_14_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_14_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_14_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_14_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_14_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_14_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_14_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_14_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_14_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_14_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_14_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_15                                                          0x1800E53C
#define  RL_L0REFDMA_15_reg_addr                                                 "0xB800E53C"
#define  RL_L0REFDMA_15_reg                                                      0xB800E53C
#define  RL_L0REFDMA_15_inst_addr                                                "0x0015"
#define  set_RL_L0REFDMA_15_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_15_reg)=data)
#define  get_RL_L0REFDMA_15_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_15_reg))
#define  RL_L0REFDMA_15_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_15_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_15_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_15_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_15_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_15_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_15_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_15_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_15_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_15_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_15_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_15_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_15_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_15_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_15_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_15_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_16                                                          0x1800E540
#define  RL_L0REFDMA_16_reg_addr                                                 "0xB800E540"
#define  RL_L0REFDMA_16_reg                                                      0xB800E540
#define  RL_L0REFDMA_16_inst_addr                                                "0x0016"
#define  set_RL_L0REFDMA_16_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_16_reg)=data)
#define  get_RL_L0REFDMA_16_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_16_reg))
#define  RL_L0REFDMA_16_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_16_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_16_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_16_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_16_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_16_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_16_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_16_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_16_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_16_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_16_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_16_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_16_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_16_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_16_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_16_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_17                                                          0x1800E544
#define  RL_L0REFDMA_17_reg_addr                                                 "0xB800E544"
#define  RL_L0REFDMA_17_reg                                                      0xB800E544
#define  RL_L0REFDMA_17_inst_addr                                                "0x0017"
#define  set_RL_L0REFDMA_17_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_17_reg)=data)
#define  get_RL_L0REFDMA_17_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_17_reg))
#define  RL_L0REFDMA_17_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_17_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_17_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_17_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_17_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_17_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_17_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_17_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_17_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_17_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_17_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_17_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_17_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_17_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_17_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_17_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_18                                                          0x1800E548
#define  RL_L0REFDMA_18_reg_addr                                                 "0xB800E548"
#define  RL_L0REFDMA_18_reg                                                      0xB800E548
#define  RL_L0REFDMA_18_inst_addr                                                "0x0018"
#define  set_RL_L0REFDMA_18_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_18_reg)=data)
#define  get_RL_L0REFDMA_18_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_18_reg))
#define  RL_L0REFDMA_18_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_18_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_18_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_18_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_18_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_18_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_18_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_18_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_18_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_18_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_18_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_18_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_18_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_18_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_18_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_18_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_19                                                          0x1800E54C
#define  RL_L0REFDMA_19_reg_addr                                                 "0xB800E54C"
#define  RL_L0REFDMA_19_reg                                                      0xB800E54C
#define  RL_L0REFDMA_19_inst_addr                                                "0x0019"
#define  set_RL_L0REFDMA_19_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_19_reg)=data)
#define  get_RL_L0REFDMA_19_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_19_reg))
#define  RL_L0REFDMA_19_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_19_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_19_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_19_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_19_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_19_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_19_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_19_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_19_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_19_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_19_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_19_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_19_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_19_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_19_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_19_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_20                                                          0x1800E550
#define  RL_L0REFDMA_20_reg_addr                                                 "0xB800E550"
#define  RL_L0REFDMA_20_reg                                                      0xB800E550
#define  RL_L0REFDMA_20_inst_addr                                                "0x001A"
#define  set_RL_L0REFDMA_20_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_20_reg)=data)
#define  get_RL_L0REFDMA_20_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_20_reg))
#define  RL_L0REFDMA_20_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_20_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_20_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_20_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_20_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_20_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_20_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_20_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_20_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_20_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_20_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_20_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_20_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_20_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_20_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_20_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_21                                                          0x1800E554
#define  RL_L0REFDMA_21_reg_addr                                                 "0xB800E554"
#define  RL_L0REFDMA_21_reg                                                      0xB800E554
#define  RL_L0REFDMA_21_inst_addr                                                "0x001B"
#define  set_RL_L0REFDMA_21_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_21_reg)=data)
#define  get_RL_L0REFDMA_21_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_21_reg))
#define  RL_L0REFDMA_21_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_21_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_21_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_21_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_21_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_21_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_21_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_21_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_21_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_21_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_21_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_21_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_21_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_21_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_21_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_21_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_22                                                          0x1800E558
#define  RL_L0REFDMA_22_reg_addr                                                 "0xB800E558"
#define  RL_L0REFDMA_22_reg                                                      0xB800E558
#define  RL_L0REFDMA_22_inst_addr                                                "0x001C"
#define  set_RL_L0REFDMA_22_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_22_reg)=data)
#define  get_RL_L0REFDMA_22_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_22_reg))
#define  RL_L0REFDMA_22_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_22_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_22_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_22_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_22_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_22_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_22_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_22_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_22_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_22_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_22_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_22_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_22_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_22_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_22_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_22_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_23                                                          0x1800E55C
#define  RL_L0REFDMA_23_reg_addr                                                 "0xB800E55C"
#define  RL_L0REFDMA_23_reg                                                      0xB800E55C
#define  RL_L0REFDMA_23_inst_addr                                                "0x001D"
#define  set_RL_L0REFDMA_23_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_23_reg)=data)
#define  get_RL_L0REFDMA_23_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_23_reg))
#define  RL_L0REFDMA_23_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_23_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_23_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_23_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_23_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_23_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_23_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_23_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_23_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_23_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_23_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_23_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_23_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_23_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_23_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_23_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_24                                                          0x1800E560
#define  RL_L0REFDMA_24_reg_addr                                                 "0xB800E560"
#define  RL_L0REFDMA_24_reg                                                      0xB800E560
#define  RL_L0REFDMA_24_inst_addr                                                "0x001E"
#define  set_RL_L0REFDMA_24_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_24_reg)=data)
#define  get_RL_L0REFDMA_24_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_24_reg))
#define  RL_L0REFDMA_24_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_24_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_24_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_24_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_24_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_24_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_24_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_24_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_24_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_24_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_24_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_24_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_24_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_24_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_24_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_24_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_25                                                          0x1800E564
#define  RL_L0REFDMA_25_reg_addr                                                 "0xB800E564"
#define  RL_L0REFDMA_25_reg                                                      0xB800E564
#define  RL_L0REFDMA_25_inst_addr                                                "0x001F"
#define  set_RL_L0REFDMA_25_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_25_reg)=data)
#define  get_RL_L0REFDMA_25_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_25_reg))
#define  RL_L0REFDMA_25_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_25_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_25_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_25_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_25_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_25_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_25_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_25_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_25_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_25_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_25_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_25_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_25_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_25_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_25_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_25_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_26                                                          0x1800E568
#define  RL_L0REFDMA_26_reg_addr                                                 "0xB800E568"
#define  RL_L0REFDMA_26_reg                                                      0xB800E568
#define  RL_L0REFDMA_26_inst_addr                                                "0x0020"
#define  set_RL_L0REFDMA_26_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_26_reg)=data)
#define  get_RL_L0REFDMA_26_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_26_reg))
#define  RL_L0REFDMA_26_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_26_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_26_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_26_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_26_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_26_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_26_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_26_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_26_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_26_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_26_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_26_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_26_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_26_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_26_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_26_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_27                                                          0x1800E56C
#define  RL_L0REFDMA_27_reg_addr                                                 "0xB800E56C"
#define  RL_L0REFDMA_27_reg                                                      0xB800E56C
#define  RL_L0REFDMA_27_inst_addr                                                "0x0021"
#define  set_RL_L0REFDMA_27_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_27_reg)=data)
#define  get_RL_L0REFDMA_27_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_27_reg))
#define  RL_L0REFDMA_27_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_27_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_27_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_27_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_27_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_27_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_27_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_27_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_27_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_27_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_27_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_27_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_27_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_27_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_27_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_27_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_28                                                          0x1800E570
#define  RL_L0REFDMA_28_reg_addr                                                 "0xB800E570"
#define  RL_L0REFDMA_28_reg                                                      0xB800E570
#define  RL_L0REFDMA_28_inst_addr                                                "0x0022"
#define  set_RL_L0REFDMA_28_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_28_reg)=data)
#define  get_RL_L0REFDMA_28_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_28_reg))
#define  RL_L0REFDMA_28_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_28_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_28_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_28_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_28_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_28_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_28_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_28_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_28_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_28_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_28_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_28_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_28_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_28_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_28_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_28_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_29                                                          0x1800E574
#define  RL_L0REFDMA_29_reg_addr                                                 "0xB800E574"
#define  RL_L0REFDMA_29_reg                                                      0xB800E574
#define  RL_L0REFDMA_29_inst_addr                                                "0x0023"
#define  set_RL_L0REFDMA_29_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_29_reg)=data)
#define  get_RL_L0REFDMA_29_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_29_reg))
#define  RL_L0REFDMA_29_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_29_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_29_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_29_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_29_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_29_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_29_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_29_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_29_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_29_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_29_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_29_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_29_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_29_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_29_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_29_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_30                                                          0x1800E578
#define  RL_L0REFDMA_30_reg_addr                                                 "0xB800E578"
#define  RL_L0REFDMA_30_reg                                                      0xB800E578
#define  RL_L0REFDMA_30_inst_addr                                                "0x0024"
#define  set_RL_L0REFDMA_30_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_30_reg)=data)
#define  get_RL_L0REFDMA_30_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_30_reg))
#define  RL_L0REFDMA_30_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_30_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_30_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_30_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_30_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_30_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_30_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_30_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_30_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_30_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_30_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_30_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_30_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_30_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_30_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_30_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L0REFDMA_31                                                          0x1800E57C
#define  RL_L0REFDMA_31_reg_addr                                                 "0xB800E57C"
#define  RL_L0REFDMA_31_reg                                                      0xB800E57C
#define  RL_L0REFDMA_31_inst_addr                                                "0x0025"
#define  set_RL_L0REFDMA_31_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_31_reg)=data)
#define  get_RL_L0REFDMA_31_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_31_reg))
#define  RL_L0REFDMA_31_ref_rangeredfrm_shift                                    (15)
#define  RL_L0REFDMA_31_bottom_field_flag_shift                                  (14)
#define  RL_L0REFDMA_31_lu_addr_index_shift                                      (7)
#define  RL_L0REFDMA_31_ch_addr_index_shift                                      (0)
#define  RL_L0REFDMA_31_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L0REFDMA_31_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L0REFDMA_31_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L0REFDMA_31_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L0REFDMA_31_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L0REFDMA_31_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L0REFDMA_31_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_31_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L0REFDMA_31_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_31_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_31_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_31_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_0                                                           0x1800E580
#define  RL_L1REFDMA_0_reg_addr                                                  "0xB800E580"
#define  RL_L1REFDMA_0_reg                                                       0xB800E580
#define  RL_L1REFDMA_0_inst_addr                                                 "0x0026"
#define  set_RL_L1REFDMA_0_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_0_reg)=data)
#define  get_RL_L1REFDMA_0_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_0_reg))
#define  RL_L1REFDMA_0_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_0_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_0_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_0_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_0_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_0_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_0_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_0_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_0_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_0_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_0_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_0_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_0_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_0_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_0_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_0_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_1                                                           0x1800E584
#define  RL_L1REFDMA_1_reg_addr                                                  "0xB800E584"
#define  RL_L1REFDMA_1_reg                                                       0xB800E584
#define  RL_L1REFDMA_1_inst_addr                                                 "0x0027"
#define  set_RL_L1REFDMA_1_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_1_reg)=data)
#define  get_RL_L1REFDMA_1_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_1_reg))
#define  RL_L1REFDMA_1_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_1_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_1_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_1_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_1_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_1_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_1_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_1_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_1_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_1_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_1_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_1_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_1_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_1_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_1_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_1_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_2                                                           0x1800E588
#define  RL_L1REFDMA_2_reg_addr                                                  "0xB800E588"
#define  RL_L1REFDMA_2_reg                                                       0xB800E588
#define  RL_L1REFDMA_2_inst_addr                                                 "0x0028"
#define  set_RL_L1REFDMA_2_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_2_reg)=data)
#define  get_RL_L1REFDMA_2_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_2_reg))
#define  RL_L1REFDMA_2_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_2_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_2_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_2_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_2_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_2_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_2_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_2_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_2_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_2_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_2_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_2_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_2_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_2_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_2_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_2_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_3                                                           0x1800E58C
#define  RL_L1REFDMA_3_reg_addr                                                  "0xB800E58C"
#define  RL_L1REFDMA_3_reg                                                       0xB800E58C
#define  RL_L1REFDMA_3_inst_addr                                                 "0x0029"
#define  set_RL_L1REFDMA_3_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_3_reg)=data)
#define  get_RL_L1REFDMA_3_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_3_reg))
#define  RL_L1REFDMA_3_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_3_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_3_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_3_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_3_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_3_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_3_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_3_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_3_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_3_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_3_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_3_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_3_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_3_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_3_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_3_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_4                                                           0x1800E590
#define  RL_L1REFDMA_4_reg_addr                                                  "0xB800E590"
#define  RL_L1REFDMA_4_reg                                                       0xB800E590
#define  RL_L1REFDMA_4_inst_addr                                                 "0x002A"
#define  set_RL_L1REFDMA_4_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_4_reg)=data)
#define  get_RL_L1REFDMA_4_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_4_reg))
#define  RL_L1REFDMA_4_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_4_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_4_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_4_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_4_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_4_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_4_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_4_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_4_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_4_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_4_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_4_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_4_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_4_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_4_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_4_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_5                                                           0x1800E594
#define  RL_L1REFDMA_5_reg_addr                                                  "0xB800E594"
#define  RL_L1REFDMA_5_reg                                                       0xB800E594
#define  RL_L1REFDMA_5_inst_addr                                                 "0x002B"
#define  set_RL_L1REFDMA_5_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_5_reg)=data)
#define  get_RL_L1REFDMA_5_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_5_reg))
#define  RL_L1REFDMA_5_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_5_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_5_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_5_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_5_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_5_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_5_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_5_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_5_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_5_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_5_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_5_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_5_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_5_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_5_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_5_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_6                                                           0x1800E598
#define  RL_L1REFDMA_6_reg_addr                                                  "0xB800E598"
#define  RL_L1REFDMA_6_reg                                                       0xB800E598
#define  RL_L1REFDMA_6_inst_addr                                                 "0x002C"
#define  set_RL_L1REFDMA_6_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_6_reg)=data)
#define  get_RL_L1REFDMA_6_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_6_reg))
#define  RL_L1REFDMA_6_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_6_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_6_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_6_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_6_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_6_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_6_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_6_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_6_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_6_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_6_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_6_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_6_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_6_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_6_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_6_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_7                                                           0x1800E59C
#define  RL_L1REFDMA_7_reg_addr                                                  "0xB800E59C"
#define  RL_L1REFDMA_7_reg                                                       0xB800E59C
#define  RL_L1REFDMA_7_inst_addr                                                 "0x002D"
#define  set_RL_L1REFDMA_7_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_7_reg)=data)
#define  get_RL_L1REFDMA_7_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_7_reg))
#define  RL_L1REFDMA_7_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_7_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_7_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_7_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_7_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_7_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_7_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_7_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_7_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_7_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_7_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_7_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_7_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_7_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_7_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_7_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_8                                                           0x1800E5A0
#define  RL_L1REFDMA_8_reg_addr                                                  "0xB800E5A0"
#define  RL_L1REFDMA_8_reg                                                       0xB800E5A0
#define  RL_L1REFDMA_8_inst_addr                                                 "0x002E"
#define  set_RL_L1REFDMA_8_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_8_reg)=data)
#define  get_RL_L1REFDMA_8_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_8_reg))
#define  RL_L1REFDMA_8_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_8_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_8_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_8_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_8_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_8_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_8_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_8_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_8_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_8_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_8_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_8_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_8_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_8_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_8_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_8_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_9                                                           0x1800E5A4
#define  RL_L1REFDMA_9_reg_addr                                                  "0xB800E5A4"
#define  RL_L1REFDMA_9_reg                                                       0xB800E5A4
#define  RL_L1REFDMA_9_inst_addr                                                 "0x002F"
#define  set_RL_L1REFDMA_9_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_9_reg)=data)
#define  get_RL_L1REFDMA_9_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_9_reg))
#define  RL_L1REFDMA_9_ref_rangeredfrm_shift                                     (15)
#define  RL_L1REFDMA_9_bottom_field_flag_shift                                   (14)
#define  RL_L1REFDMA_9_lu_addr_index_shift                                       (7)
#define  RL_L1REFDMA_9_ch_addr_index_shift                                       (0)
#define  RL_L1REFDMA_9_ref_rangeredfrm_mask                                      (0x00008000)
#define  RL_L1REFDMA_9_bottom_field_flag_mask                                    (0x00004000)
#define  RL_L1REFDMA_9_lu_addr_index_mask                                        (0x00003F80)
#define  RL_L1REFDMA_9_ch_addr_index_mask                                        (0x0000007F)
#define  RL_L1REFDMA_9_ref_rangeredfrm(data)                                     (0x00008000&((data)<<15))
#define  RL_L1REFDMA_9_bottom_field_flag(data)                                   (0x00004000&((data)<<14))
#define  RL_L1REFDMA_9_lu_addr_index(data)                                       (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_9_ch_addr_index(data)                                       (0x0000007F&(data))
#define  RL_L1REFDMA_9_get_ref_rangeredfrm(data)                                 ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_9_get_bottom_field_flag(data)                               ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_9_get_lu_addr_index(data)                                   ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_9_get_ch_addr_index(data)                                   (0x0000007F&(data))

#define  RL_L1REFDMA_10                                                          0x1800E5A8
#define  RL_L1REFDMA_10_reg_addr                                                 "0xB800E5A8"
#define  RL_L1REFDMA_10_reg                                                      0xB800E5A8
#define  RL_L1REFDMA_10_inst_addr                                                "0x0030"
#define  set_RL_L1REFDMA_10_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_10_reg)=data)
#define  get_RL_L1REFDMA_10_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_10_reg))
#define  RL_L1REFDMA_10_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_10_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_10_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_10_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_10_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_10_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_10_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_10_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_10_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_10_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_10_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_10_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_10_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_10_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_10_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_10_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_11                                                          0x1800E5AC
#define  RL_L1REFDMA_11_reg_addr                                                 "0xB800E5AC"
#define  RL_L1REFDMA_11_reg                                                      0xB800E5AC
#define  RL_L1REFDMA_11_inst_addr                                                "0x0031"
#define  set_RL_L1REFDMA_11_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_11_reg)=data)
#define  get_RL_L1REFDMA_11_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_11_reg))
#define  RL_L1REFDMA_11_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_11_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_11_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_11_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_11_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_11_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_11_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_11_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_11_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_11_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_11_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_11_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_11_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_11_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_11_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_11_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_12                                                          0x1800E5B0
#define  RL_L1REFDMA_12_reg_addr                                                 "0xB800E5B0"
#define  RL_L1REFDMA_12_reg                                                      0xB800E5B0
#define  RL_L1REFDMA_12_inst_addr                                                "0x0032"
#define  set_RL_L1REFDMA_12_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_12_reg)=data)
#define  get_RL_L1REFDMA_12_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_12_reg))
#define  RL_L1REFDMA_12_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_12_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_12_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_12_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_12_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_12_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_12_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_12_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_12_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_12_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_12_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_12_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_12_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_12_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_12_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_12_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_13                                                          0x1800E5B4
#define  RL_L1REFDMA_13_reg_addr                                                 "0xB800E5B4"
#define  RL_L1REFDMA_13_reg                                                      0xB800E5B4
#define  RL_L1REFDMA_13_inst_addr                                                "0x0033"
#define  set_RL_L1REFDMA_13_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_13_reg)=data)
#define  get_RL_L1REFDMA_13_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_13_reg))
#define  RL_L1REFDMA_13_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_13_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_13_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_13_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_13_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_13_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_13_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_13_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_13_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_13_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_13_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_13_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_13_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_13_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_13_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_13_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_14                                                          0x1800E5B8
#define  RL_L1REFDMA_14_reg_addr                                                 "0xB800E5B8"
#define  RL_L1REFDMA_14_reg                                                      0xB800E5B8
#define  RL_L1REFDMA_14_inst_addr                                                "0x0034"
#define  set_RL_L1REFDMA_14_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_14_reg)=data)
#define  get_RL_L1REFDMA_14_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_14_reg))
#define  RL_L1REFDMA_14_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_14_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_14_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_14_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_14_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_14_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_14_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_14_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_14_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_14_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_14_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_14_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_14_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_14_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_14_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_14_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_15                                                          0x1800E5BC
#define  RL_L1REFDMA_15_reg_addr                                                 "0xB800E5BC"
#define  RL_L1REFDMA_15_reg                                                      0xB800E5BC
#define  RL_L1REFDMA_15_inst_addr                                                "0x0035"
#define  set_RL_L1REFDMA_15_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_15_reg)=data)
#define  get_RL_L1REFDMA_15_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_15_reg))
#define  RL_L1REFDMA_15_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_15_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_15_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_15_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_15_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_15_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_15_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_15_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_15_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_15_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_15_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_15_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_15_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_15_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_15_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_15_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_16                                                          0x1800E5C0
#define  RL_L1REFDMA_16_reg_addr                                                 "0xB800E5C0"
#define  RL_L1REFDMA_16_reg                                                      0xB800E5C0
#define  RL_L1REFDMA_16_inst_addr                                                "0x0036"
#define  set_RL_L1REFDMA_16_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_16_reg)=data)
#define  get_RL_L1REFDMA_16_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_16_reg))
#define  RL_L1REFDMA_16_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_16_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_16_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_16_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_16_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_16_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_16_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_16_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_16_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_16_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_16_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_16_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_16_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_16_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_16_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_16_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_17                                                          0x1800E5C4
#define  RL_L1REFDMA_17_reg_addr                                                 "0xB800E5C4"
#define  RL_L1REFDMA_17_reg                                                      0xB800E5C4
#define  RL_L1REFDMA_17_inst_addr                                                "0x0037"
#define  set_RL_L1REFDMA_17_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_17_reg)=data)
#define  get_RL_L1REFDMA_17_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_17_reg))
#define  RL_L1REFDMA_17_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_17_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_17_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_17_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_17_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_17_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_17_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_17_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_17_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_17_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_17_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_17_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_17_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_17_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_17_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_17_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_18                                                          0x1800E5C8
#define  RL_L1REFDMA_18_reg_addr                                                 "0xB800E5C8"
#define  RL_L1REFDMA_18_reg                                                      0xB800E5C8
#define  RL_L1REFDMA_18_inst_addr                                                "0x0038"
#define  set_RL_L1REFDMA_18_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_18_reg)=data)
#define  get_RL_L1REFDMA_18_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_18_reg))
#define  RL_L1REFDMA_18_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_18_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_18_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_18_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_18_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_18_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_18_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_18_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_18_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_18_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_18_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_18_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_18_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_18_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_18_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_18_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_19                                                          0x1800E5CC
#define  RL_L1REFDMA_19_reg_addr                                                 "0xB800E5CC"
#define  RL_L1REFDMA_19_reg                                                      0xB800E5CC
#define  RL_L1REFDMA_19_inst_addr                                                "0x0039"
#define  set_RL_L1REFDMA_19_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_19_reg)=data)
#define  get_RL_L1REFDMA_19_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_19_reg))
#define  RL_L1REFDMA_19_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_19_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_19_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_19_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_19_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_19_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_19_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_19_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_19_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_19_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_19_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_19_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_19_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_19_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_19_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_19_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_20                                                          0x1800E5D0
#define  RL_L1REFDMA_20_reg_addr                                                 "0xB800E5D0"
#define  RL_L1REFDMA_20_reg                                                      0xB800E5D0
#define  RL_L1REFDMA_20_inst_addr                                                "0x003A"
#define  set_RL_L1REFDMA_20_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_20_reg)=data)
#define  get_RL_L1REFDMA_20_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_20_reg))
#define  RL_L1REFDMA_20_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_20_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_20_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_20_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_20_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_20_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_20_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_20_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_20_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_20_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_20_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_20_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_20_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_20_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_20_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_20_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_21                                                          0x1800E5D4
#define  RL_L1REFDMA_21_reg_addr                                                 "0xB800E5D4"
#define  RL_L1REFDMA_21_reg                                                      0xB800E5D4
#define  RL_L1REFDMA_21_inst_addr                                                "0x003B"
#define  set_RL_L1REFDMA_21_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_21_reg)=data)
#define  get_RL_L1REFDMA_21_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_21_reg))
#define  RL_L1REFDMA_21_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_21_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_21_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_21_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_21_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_21_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_21_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_21_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_21_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_21_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_21_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_21_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_21_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_21_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_21_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_21_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_22                                                          0x1800E5D8
#define  RL_L1REFDMA_22_reg_addr                                                 "0xB800E5D8"
#define  RL_L1REFDMA_22_reg                                                      0xB800E5D8
#define  RL_L1REFDMA_22_inst_addr                                                "0x003C"
#define  set_RL_L1REFDMA_22_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_22_reg)=data)
#define  get_RL_L1REFDMA_22_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_22_reg))
#define  RL_L1REFDMA_22_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_22_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_22_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_22_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_22_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_22_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_22_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_22_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_22_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_22_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_22_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_22_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_22_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_22_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_22_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_22_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_23                                                          0x1800E5DC
#define  RL_L1REFDMA_23_reg_addr                                                 "0xB800E5DC"
#define  RL_L1REFDMA_23_reg                                                      0xB800E5DC
#define  RL_L1REFDMA_23_inst_addr                                                "0x003D"
#define  set_RL_L1REFDMA_23_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_23_reg)=data)
#define  get_RL_L1REFDMA_23_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_23_reg))
#define  RL_L1REFDMA_23_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_23_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_23_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_23_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_23_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_23_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_23_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_23_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_23_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_23_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_23_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_23_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_23_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_23_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_23_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_23_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_24                                                          0x1800E5E0
#define  RL_L1REFDMA_24_reg_addr                                                 "0xB800E5E0"
#define  RL_L1REFDMA_24_reg                                                      0xB800E5E0
#define  RL_L1REFDMA_24_inst_addr                                                "0x003E"
#define  set_RL_L1REFDMA_24_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_24_reg)=data)
#define  get_RL_L1REFDMA_24_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_24_reg))
#define  RL_L1REFDMA_24_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_24_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_24_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_24_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_24_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_24_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_24_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_24_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_24_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_24_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_24_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_24_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_24_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_24_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_24_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_24_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_25                                                          0x1800E5E4
#define  RL_L1REFDMA_25_reg_addr                                                 "0xB800E5E4"
#define  RL_L1REFDMA_25_reg                                                      0xB800E5E4
#define  RL_L1REFDMA_25_inst_addr                                                "0x003F"
#define  set_RL_L1REFDMA_25_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_25_reg)=data)
#define  get_RL_L1REFDMA_25_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_25_reg))
#define  RL_L1REFDMA_25_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_25_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_25_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_25_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_25_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_25_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_25_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_25_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_25_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_25_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_25_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_25_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_25_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_25_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_25_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_25_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_26                                                          0x1800E5E8
#define  RL_L1REFDMA_26_reg_addr                                                 "0xB800E5E8"
#define  RL_L1REFDMA_26_reg                                                      0xB800E5E8
#define  RL_L1REFDMA_26_inst_addr                                                "0x0040"
#define  set_RL_L1REFDMA_26_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_26_reg)=data)
#define  get_RL_L1REFDMA_26_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_26_reg))
#define  RL_L1REFDMA_26_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_26_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_26_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_26_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_26_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_26_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_26_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_26_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_26_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_26_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_26_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_26_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_26_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_26_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_26_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_26_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_27                                                          0x1800E5EC
#define  RL_L1REFDMA_27_reg_addr                                                 "0xB800E5EC"
#define  RL_L1REFDMA_27_reg                                                      0xB800E5EC
#define  RL_L1REFDMA_27_inst_addr                                                "0x0041"
#define  set_RL_L1REFDMA_27_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_27_reg)=data)
#define  get_RL_L1REFDMA_27_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_27_reg))
#define  RL_L1REFDMA_27_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_27_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_27_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_27_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_27_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_27_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_27_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_27_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_27_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_27_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_27_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_27_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_27_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_27_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_27_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_27_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_28                                                          0x1800E5F0
#define  RL_L1REFDMA_28_reg_addr                                                 "0xB800E5F0"
#define  RL_L1REFDMA_28_reg                                                      0xB800E5F0
#define  RL_L1REFDMA_28_inst_addr                                                "0x0042"
#define  set_RL_L1REFDMA_28_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_28_reg)=data)
#define  get_RL_L1REFDMA_28_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_28_reg))
#define  RL_L1REFDMA_28_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_28_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_28_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_28_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_28_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_28_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_28_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_28_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_28_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_28_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_28_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_28_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_28_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_28_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_28_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_28_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_29                                                          0x1800E5F4
#define  RL_L1REFDMA_29_reg_addr                                                 "0xB800E5F4"
#define  RL_L1REFDMA_29_reg                                                      0xB800E5F4
#define  RL_L1REFDMA_29_inst_addr                                                "0x0043"
#define  set_RL_L1REFDMA_29_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_29_reg)=data)
#define  get_RL_L1REFDMA_29_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_29_reg))
#define  RL_L1REFDMA_29_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_29_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_29_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_29_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_29_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_29_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_29_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_29_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_29_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_29_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_29_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_29_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_29_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_29_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_29_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_29_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_30                                                          0x1800E5F8
#define  RL_L1REFDMA_30_reg_addr                                                 "0xB800E5F8"
#define  RL_L1REFDMA_30_reg                                                      0xB800E5F8
#define  RL_L1REFDMA_30_inst_addr                                                "0x0044"
#define  set_RL_L1REFDMA_30_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_30_reg)=data)
#define  get_RL_L1REFDMA_30_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_30_reg))
#define  RL_L1REFDMA_30_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_30_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_30_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_30_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_30_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_30_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_30_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_30_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_30_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_30_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_30_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_30_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_30_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_30_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_30_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_30_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_L1REFDMA_31                                                          0x1800E5FC
#define  RL_L1REFDMA_31_reg_addr                                                 "0xB800E5FC"
#define  RL_L1REFDMA_31_reg                                                      0xB800E5FC
#define  RL_L1REFDMA_31_inst_addr                                                "0x0045"
#define  set_RL_L1REFDMA_31_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_31_reg)=data)
#define  get_RL_L1REFDMA_31_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_31_reg))
#define  RL_L1REFDMA_31_ref_rangeredfrm_shift                                    (15)
#define  RL_L1REFDMA_31_bottom_field_flag_shift                                  (14)
#define  RL_L1REFDMA_31_lu_addr_index_shift                                      (7)
#define  RL_L1REFDMA_31_ch_addr_index_shift                                      (0)
#define  RL_L1REFDMA_31_ref_rangeredfrm_mask                                     (0x00008000)
#define  RL_L1REFDMA_31_bottom_field_flag_mask                                   (0x00004000)
#define  RL_L1REFDMA_31_lu_addr_index_mask                                       (0x00003F80)
#define  RL_L1REFDMA_31_ch_addr_index_mask                                       (0x0000007F)
#define  RL_L1REFDMA_31_ref_rangeredfrm(data)                                    (0x00008000&((data)<<15))
#define  RL_L1REFDMA_31_bottom_field_flag(data)                                  (0x00004000&((data)<<14))
#define  RL_L1REFDMA_31_lu_addr_index(data)                                      (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_31_ch_addr_index(data)                                      (0x0000007F&(data))
#define  RL_L1REFDMA_31_get_ref_rangeredfrm(data)                                ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_31_get_bottom_field_flag(data)                              ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_31_get_lu_addr_index(data)                                  ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_31_get_ch_addr_index(data)                                  (0x0000007F&(data))

#define  RL_DBG_SEL                                                              0x1800EC18
#define  RL_DBG_SEL_reg_addr                                                     "0xB800EC18"
#define  RL_DBG_SEL_reg                                                          0xB800EC18
#define  RL_DBG_SEL_inst_addr                                                    "0x0046"
#define  set_RL_DBG_SEL_reg(data)                                                (*((volatile unsigned int*)RL_DBG_SEL_reg)=data)
#define  get_RL_DBG_SEL_reg                                                      (*((volatile unsigned int*)RL_DBG_SEL_reg))
#define  RL_DBG_SEL_write_enable3_shift                                          (31)
#define  RL_DBG_SEL_trigger_status_shift                                         (30)
#define  RL_DBG_SEL_zero_w_lr_shift                                              (28)
#define  RL_DBG_SEL_write_enable2_shift                                          (27)
#define  RL_DBG_SEL_trigger_select_shift                                         (23)
#define  RL_DBG_SEL_trigger_cond_mb_x_shift                                      (12)
#define  RL_DBG_SEL_trigger_cond_mb_y_shift                                      (4)
#define  RL_DBG_SEL_write_enable1_shift                                          (3)
#define  RL_DBG_SEL_debug_port_sel_shift                                         (0)
#define  RL_DBG_SEL_write_enable3_mask                                           (0x80000000)
#define  RL_DBG_SEL_trigger_status_mask                                          (0x40000000)
#define  RL_DBG_SEL_zero_w_lr_mask                                               (0x30000000)
#define  RL_DBG_SEL_write_enable2_mask                                           (0x08000000)
#define  RL_DBG_SEL_trigger_select_mask                                          (0x07800000)
#define  RL_DBG_SEL_trigger_cond_mb_x_mask                                       (0x001FF000)
#define  RL_DBG_SEL_trigger_cond_mb_y_mask                                       (0x00000FF0)
#define  RL_DBG_SEL_write_enable1_mask                                           (0x00000008)
#define  RL_DBG_SEL_debug_port_sel_mask                                          (0x00000007)
#define  RL_DBG_SEL_write_enable3(data)                                          (0x80000000&((data)<<31))
#define  RL_DBG_SEL_trigger_status(data)                                         (0x40000000&((data)<<30))
#define  RL_DBG_SEL_zero_w_lr(data)                                              (0x30000000&((data)<<28))
#define  RL_DBG_SEL_write_enable2(data)                                          (0x08000000&((data)<<27))
#define  RL_DBG_SEL_trigger_select(data)                                         (0x07800000&((data)<<23))
#define  RL_DBG_SEL_trigger_cond_mb_x(data)                                      (0x001FF000&((data)<<12))
#define  RL_DBG_SEL_trigger_cond_mb_y(data)                                      (0x00000FF0&((data)<<4))
#define  RL_DBG_SEL_write_enable1(data)                                          (0x00000008&((data)<<3))
#define  RL_DBG_SEL_debug_port_sel(data)                                         (0x00000007&(data))
#define  RL_DBG_SEL_get_write_enable3(data)                                      ((0x80000000&(data))>>31)
#define  RL_DBG_SEL_get_trigger_status(data)                                     ((0x40000000&(data))>>30)
#define  RL_DBG_SEL_get_zero_w_lr(data)                                          ((0x30000000&(data))>>28)
#define  RL_DBG_SEL_get_write_enable2(data)                                      ((0x08000000&(data))>>27)
#define  RL_DBG_SEL_get_trigger_select(data)                                     ((0x07800000&(data))>>23)
#define  RL_DBG_SEL_get_trigger_cond_mb_x(data)                                  ((0x001FF000&(data))>>12)
#define  RL_DBG_SEL_get_trigger_cond_mb_y(data)                                  ((0x00000FF0&(data))>>4)
#define  RL_DBG_SEL_get_write_enable1(data)                                      ((0x00000008&(data))>>3)
#define  RL_DBG_SEL_get_debug_port_sel(data)                                     (0x00000007&(data))

#define  RL_DBG_STS0                                                             0x1800EC1C
#define  RL_DBG_STS0_reg_addr                                                    "0xB800EC1C"
#define  RL_DBG_STS0_reg                                                         0xB800EC1C
#define  RL_DBG_STS0_inst_addr                                                   "0x0047"
#define  set_RL_DBG_STS0_reg(data)                                               (*((volatile unsigned int*)RL_DBG_STS0_reg)=data)
#define  get_RL_DBG_STS0_reg                                                     (*((volatile unsigned int*)RL_DBG_STS0_reg))
#define  RL_DBG_STS0_tbl_cnt_shift                                               (16)
#define  RL_DBG_STS0_trigger_tbl_cnt_shift                                       (0)
#define  RL_DBG_STS0_tbl_cnt_mask                                                (0xFFFF0000)
#define  RL_DBG_STS0_trigger_tbl_cnt_mask                                        (0x0000FFFF)
#define  RL_DBG_STS0_tbl_cnt(data)                                               (0xFFFF0000&((data)<<16))
#define  RL_DBG_STS0_trigger_tbl_cnt(data)                                       (0x0000FFFF&(data))
#define  RL_DBG_STS0_get_tbl_cnt(data)                                           ((0xFFFF0000&(data))>>16)
#define  RL_DBG_STS0_get_trigger_tbl_cnt(data)                                   (0x0000FFFF&(data))

#define  RL_DBG_STS1                                                             0x1800EC20
#define  RL_DBG_STS1_reg_addr                                                    "0xB800EC20"
#define  RL_DBG_STS1_reg                                                         0xB800EC20
#define  RL_DBG_STS1_inst_addr                                                   "0x0048"
#define  set_RL_DBG_STS1_reg(data)                                               (*((volatile unsigned int*)RL_DBG_STS1_reg)=data)
#define  get_RL_DBG_STS1_reg                                                     (*((volatile unsigned int*)RL_DBG_STS1_reg))
#define  RL_DBG_STS1_dbg_sts_shift                                               (0)
#define  RL_DBG_STS1_dbg_sts_mask                                                (0xFFFFFFFF)
#define  RL_DBG_STS1_dbg_sts(data)                                               (0xFFFFFFFF&(data))
#define  RL_DBG_STS1_get_dbg_sts(data)                                           (0xFFFFFFFF&(data))

#define  RL_DBG_STS2                                                             0x1800EC24
#define  RL_DBG_STS2_reg_addr                                                    "0xB800EC24"
#define  RL_DBG_STS2_reg                                                         0xB800EC24
#define  RL_DBG_STS2_inst_addr                                                   "0x0049"
#define  set_RL_DBG_STS2_reg(data)                                               (*((volatile unsigned int*)RL_DBG_STS2_reg)=data)
#define  get_RL_DBG_STS2_reg                                                     (*((volatile unsigned int*)RL_DBG_STS2_reg))
#define  RL_DBG_STS2_dbg_sts_shift                                               (0)
#define  RL_DBG_STS2_dbg_sts_mask                                                (0xFFFFFFFF)
#define  RL_DBG_STS2_dbg_sts(data)                                               (0xFFFFFFFF&(data))
#define  RL_DBG_STS2_get_dbg_sts(data)                                           (0xFFFFFFFF&(data))

#define  RL_INTR_THRES                                                           0x1800EC28
#define  RL_INTR_THRES_reg_addr                                                  "0xB800EC28"
#define  RL_INTR_THRES_reg                                                       0xB800EC28
#define  RL_INTR_THRES_inst_addr                                                 "0x004A"
#define  set_RL_INTR_THRES_reg(data)                                             (*((volatile unsigned int*)RL_INTR_THRES_reg)=data)
#define  get_RL_INTR_THRES_reg                                                   (*((volatile unsigned int*)RL_INTR_THRES_reg))
#define  RL_INTR_THRES_intr_shift                                                (28)
#define  RL_INTR_THRES_value_shift                                               (0)
#define  RL_INTR_THRES_intr_mask                                                 (0x10000000)
#define  RL_INTR_THRES_value_mask                                                (0x0FFFFFFF)
#define  RL_INTR_THRES_intr(data)                                                (0x10000000&((data)<<28))
#define  RL_INTR_THRES_value(data)                                               (0x0FFFFFFF&(data))
#define  RL_INTR_THRES_get_intr(data)                                            ((0x10000000&(data))>>28)
#define  RL_INTR_THRES_get_value(data)                                           (0x0FFFFFFF&(data))

#define  RL_MVBUF_WADD                                                           0x1800EC80
#define  RL_MVBUF_WADD_reg_addr                                                  "0xB800EC80"
#define  RL_MVBUF_WADD_reg                                                       0xB800EC80
#define  RL_MVBUF_WADD_inst_addr                                                 "0x004B"
#define  set_RL_MVBUF_WADD_reg(data)                                             (*((volatile unsigned int*)RL_MVBUF_WADD_reg)=data)
#define  get_RL_MVBUF_WADD_reg                                                   (*((volatile unsigned int*)RL_MVBUF_WADD_reg))
#define  RL_MVBUF_WADD_mvbuf_write_address_shift                                 (0)
#define  RL_MVBUF_WADD_mvbuf_write_address_mask                                  (0x0000007F)
#define  RL_MVBUF_WADD_mvbuf_write_address(data)                                 (0x0000007F&(data))
#define  RL_MVBUF_WADD_get_mvbuf_write_address(data)                             (0x0000007F&(data))

#define  RL_MVBUF_DATA_0                                                         0x1800EC84
#define  RL_MVBUF_DATA_0_reg_addr                                                "0xB800EC84"
#define  RL_MVBUF_DATA_0_reg                                                     0xB800EC84
#define  RL_MVBUF_DATA_0_inst_addr                                               "0x004C"
#define  set_RL_MVBUF_DATA_0_reg(data)                                           (*((volatile unsigned int*)RL_MVBUF_DATA_0_reg)=data)
#define  get_RL_MVBUF_DATA_0_reg                                                 (*((volatile unsigned int*)RL_MVBUF_DATA_0_reg))
#define  RL_MVBUF_DATA_0_mvbuf_read_write_data_shift                             (0)
#define  RL_MVBUF_DATA_0_mvbuf_read_write_data_mask                              (0xFFFFFFFF)
#define  RL_MVBUF_DATA_0_mvbuf_read_write_data(data)                             (0xFFFFFFFF&(data))
#define  RL_MVBUF_DATA_0_get_mvbuf_read_write_data(data)                         (0xFFFFFFFF&(data))

#define  RL_MVBUF_DATA_1                                                         0x1800EC88
#define  RL_MVBUF_DATA_1_reg_addr                                                "0xB800EC88"
#define  RL_MVBUF_DATA_1_reg                                                     0xB800EC88
#define  RL_MVBUF_DATA_1_inst_addr                                               "0x004D"
#define  set_RL_MVBUF_DATA_1_reg(data)                                           (*((volatile unsigned int*)RL_MVBUF_DATA_1_reg)=data)
#define  get_RL_MVBUF_DATA_1_reg                                                 (*((volatile unsigned int*)RL_MVBUF_DATA_1_reg))
#define  RL_MVBUF_DATA_1_mvbuf_read_write_data_shift                             (0)
#define  RL_MVBUF_DATA_1_mvbuf_read_write_data_mask                              (0xFFFFFFFF)
#define  RL_MVBUF_DATA_1_mvbuf_read_write_data(data)                             (0xFFFFFFFF&(data))
#define  RL_MVBUF_DATA_1_get_mvbuf_read_write_data(data)                         (0xFFFFFFFF&(data))

#define  RL_MVBUF_DATA_2                                                         0x1800EC8C
#define  RL_MVBUF_DATA_2_reg_addr                                                "0xB800EC8C"
#define  RL_MVBUF_DATA_2_reg                                                     0xB800EC8C
#define  RL_MVBUF_DATA_2_inst_addr                                               "0x004E"
#define  set_RL_MVBUF_DATA_2_reg(data)                                           (*((volatile unsigned int*)RL_MVBUF_DATA_2_reg)=data)
#define  get_RL_MVBUF_DATA_2_reg                                                 (*((volatile unsigned int*)RL_MVBUF_DATA_2_reg))
#define  RL_MVBUF_DATA_2_mvbuf_read_write_data_shift                             (0)
#define  RL_MVBUF_DATA_2_mvbuf_read_write_data_mask                              (0xFFFFFFFF)
#define  RL_MVBUF_DATA_2_mvbuf_read_write_data(data)                             (0xFFFFFFFF&(data))
#define  RL_MVBUF_DATA_2_get_mvbuf_read_write_data(data)                         (0xFFFFFFFF&(data))

#define  RL_MVBUF_RADD                                                           0x1800EC90
#define  RL_MVBUF_RADD_reg_addr                                                  "0xB800EC90"
#define  RL_MVBUF_RADD_reg                                                       0xB800EC90
#define  RL_MVBUF_RADD_inst_addr                                                 "0x004F"
#define  set_RL_MVBUF_RADD_reg(data)                                             (*((volatile unsigned int*)RL_MVBUF_RADD_reg)=data)
#define  get_RL_MVBUF_RADD_reg                                                   (*((volatile unsigned int*)RL_MVBUF_RADD_reg))
#define  RL_MVBUF_RADD_mvbuf_read_address_shift                                  (0)
#define  RL_MVBUF_RADD_mvbuf_read_address_mask                                   (0x0000007F)
#define  RL_MVBUF_RADD_mvbuf_read_address(data)                                  (0x0000007F&(data))
#define  RL_MVBUF_RADD_get_mvbuf_read_address(data)                              (0x0000007F&(data))

#define  RL_MVBUF_STS0                                                           0x1800EC94
#define  RL_MVBUF_STS0_reg_addr                                                  "0xB800EC94"
#define  RL_MVBUF_STS0_reg                                                       0xB800EC94
#define  RL_MVBUF_STS0_inst_addr                                                 "0x0050"
#define  set_RL_MVBUF_STS0_reg(data)                                             (*((volatile unsigned int*)RL_MVBUF_STS0_reg)=data)
#define  get_RL_MVBUF_STS0_reg                                                   (*((volatile unsigned int*)RL_MVBUF_STS0_reg))
#define  RL_MVBUF_STS0_write_enable2_shift                                       (22)
#define  RL_MVBUF_STS0_mvbuf_hdr_shift                                           (12)
#define  RL_MVBUF_STS0_write_enable1_shift                                       (11)
#define  RL_MVBUF_STS0_mvbuf_mvd_wptr_shift                                      (0)
#define  RL_MVBUF_STS0_write_enable2_mask                                        (0x00400000)
#define  RL_MVBUF_STS0_mvbuf_hdr_mask                                            (0x003FF000)
#define  RL_MVBUF_STS0_write_enable1_mask                                        (0x00000800)
#define  RL_MVBUF_STS0_mvbuf_mvd_wptr_mask                                       (0x000007FF)
#define  RL_MVBUF_STS0_write_enable2(data)                                       (0x00400000&((data)<<22))
#define  RL_MVBUF_STS0_mvbuf_hdr(data)                                           (0x003FF000&((data)<<12))
#define  RL_MVBUF_STS0_write_enable1(data)                                       (0x00000800&((data)<<11))
#define  RL_MVBUF_STS0_mvbuf_mvd_wptr(data)                                      (0x000007FF&(data))
#define  RL_MVBUF_STS0_get_write_enable2(data)                                   ((0x00400000&(data))>>22)
#define  RL_MVBUF_STS0_get_mvbuf_hdr(data)                                       ((0x003FF000&(data))>>12)
#define  RL_MVBUF_STS0_get_write_enable1(data)                                   ((0x00000800&(data))>>11)
#define  RL_MVBUF_STS0_get_mvbuf_mvd_wptr(data)                                  (0x000007FF&(data))

#define  RL_MVBUF_STS1                                                           0x1800EC98
#define  RL_MVBUF_STS1_reg_addr                                                  "0xB800EC98"
#define  RL_MVBUF_STS1_reg                                                       0xB800EC98
#define  RL_MVBUF_STS1_inst_addr                                                 "0x0051"
#define  set_RL_MVBUF_STS1_reg(data)                                             (*((volatile unsigned int*)RL_MVBUF_STS1_reg)=data)
#define  get_RL_MVBUF_STS1_reg                                                   (*((volatile unsigned int*)RL_MVBUF_STS1_reg))
#define  RL_MVBUF_STS1_write_enable2_shift                                       (23)
#define  RL_MVBUF_STS1_mvbuf_pred_rptr_shift                                     (12)
#define  RL_MVBUF_STS1_write_enable11_shift                                      (11)
#define  RL_MVBUF_STS1_mvbuf_rl_rptr_shift                                       (0)
#define  RL_MVBUF_STS1_write_enable2_mask                                        (0x00800000)
#define  RL_MVBUF_STS1_mvbuf_pred_rptr_mask                                      (0x007FF000)
#define  RL_MVBUF_STS1_write_enable11_mask                                       (0x00000800)
#define  RL_MVBUF_STS1_mvbuf_rl_rptr_mask                                        (0x000007FF)
#define  RL_MVBUF_STS1_write_enable2(data)                                       (0x00800000&((data)<<23))
#define  RL_MVBUF_STS1_mvbuf_pred_rptr(data)                                     (0x007FF000&((data)<<12))
#define  RL_MVBUF_STS1_write_enable11(data)                                      (0x00000800&((data)<<11))
#define  RL_MVBUF_STS1_mvbuf_rl_rptr(data)                                       (0x000007FF&(data))
#define  RL_MVBUF_STS1_get_write_enable2(data)                                   ((0x00800000&(data))>>23)
#define  RL_MVBUF_STS1_get_mvbuf_pred_rptr(data)                                 ((0x007FF000&(data))>>12)
#define  RL_MVBUF_STS1_get_write_enable11(data)                                  ((0x00000800&(data))>>11)
#define  RL_MVBUF_STS1_get_mvbuf_rl_rptr(data)                                   (0x000007FF&(data))

#define  RL_cache_set                                                            0x1800EC9C
#define  RL_cache_set_reg_addr                                                   "0xB800EC9C"
#define  RL_cache_set_reg                                                        0xB800EC9C
#define  RL_cache_set_inst_addr                                                  "0x0052"
#define  set_RL_cache_set_reg(data)                                              (*((volatile unsigned int*)RL_cache_set_reg)=data)
#define  get_RL_cache_set_reg                                                    (*((volatile unsigned int*)RL_cache_set_reg))
#define  RL_cache_set_write_enable3_shift                                        (7)
#define  RL_cache_set_hdr_ref_pic_cnt_shift                                      (6)
#define  RL_cache_set_write_enable2_shift                                        (5)
#define  RL_cache_set_vg_en_shift                                                (3)
#define  RL_cache_set_write_enable1_shift                                        (2)
#define  RL_cache_set_ref_pic_cnt_shift                                          (0)
#define  RL_cache_set_write_enable3_mask                                         (0x00000080)
#define  RL_cache_set_hdr_ref_pic_cnt_mask                                       (0x00000040)
#define  RL_cache_set_write_enable2_mask                                         (0x00000020)
#define  RL_cache_set_vg_en_mask                                                 (0x00000018)
#define  RL_cache_set_write_enable1_mask                                         (0x00000004)
#define  RL_cache_set_ref_pic_cnt_mask                                           (0x00000003)
#define  RL_cache_set_write_enable3(data)                                        (0x00000080&((data)<<7))
#define  RL_cache_set_hdr_ref_pic_cnt(data)                                      (0x00000040&((data)<<6))
#define  RL_cache_set_write_enable2(data)                                        (0x00000020&((data)<<5))
#define  RL_cache_set_vg_en(data)                                                (0x00000018&((data)<<3))
#define  RL_cache_set_write_enable1(data)                                        (0x00000004&((data)<<2))
#define  RL_cache_set_ref_pic_cnt(data)                                          (0x00000003&(data))
#define  RL_cache_set_get_write_enable3(data)                                    ((0x00000080&(data))>>7)
#define  RL_cache_set_get_hdr_ref_pic_cnt(data)                                  ((0x00000040&(data))>>6)
#define  RL_cache_set_get_write_enable2(data)                                    ((0x00000020&(data))>>5)
#define  RL_cache_set_get_vg_en(data)                                            ((0x00000018&(data))>>3)
#define  RL_cache_set_get_write_enable1(data)                                    ((0x00000004&(data))>>2)
#define  RL_cache_set_get_ref_pic_cnt(data)                                      (0x00000003&(data))

#define  RL_cache_en                                                             0x1800ECA0
#define  RL_cache_en_reg_addr                                                    "0xB800ECA0"
#define  RL_cache_en_reg                                                         0xB800ECA0
#define  RL_cache_en_inst_addr                                                   "0x0053"
#define  set_RL_cache_en_reg(data)                                               (*((volatile unsigned int*)RL_cache_en_reg)=data)
#define  get_RL_cache_en_reg                                                     (*((volatile unsigned int*)RL_cache_en_reg))
#define  RL_cache_en_hdr_cah_en_shift                                            (1)
#define  RL_cache_en_cah_en_shift                                                (0)
#define  RL_cache_en_hdr_cah_en_mask                                             (0x00000002)
#define  RL_cache_en_cah_en_mask                                                 (0x00000001)
#define  RL_cache_en_hdr_cah_en(data)                                            (0x00000002&((data)<<1))
#define  RL_cache_en_cah_en(data)                                                (0x00000001&(data))
#define  RL_cache_en_get_hdr_cah_en(data)                                        ((0x00000002&(data))>>1)
#define  RL_cache_en_get_cah_en(data)                                            (0x00000001&(data))

#define  RL_cache_inv                                                            0x1800ECA4
#define  RL_cache_inv_reg_addr                                                   "0xB800ECA4"
#define  RL_cache_inv_reg                                                        0xB800ECA4
#define  RL_cache_inv_inst_addr                                                  "0x0054"
#define  set_RL_cache_inv_reg(data)                                              (*((volatile unsigned int*)RL_cache_inv_reg)=data)
#define  get_RL_cache_inv_reg                                                    (*((volatile unsigned int*)RL_cache_inv_reg))
#define  RL_cache_inv_hdr_cah_inv_shift                                          (1)
#define  RL_cache_inv_cah_inv_shift                                              (0)
#define  RL_cache_inv_hdr_cah_inv_mask                                           (0x00000002)
#define  RL_cache_inv_cah_inv_mask                                               (0x00000001)
#define  RL_cache_inv_hdr_cah_inv(data)                                          (0x00000002&((data)<<1))
#define  RL_cache_inv_cah_inv(data)                                              (0x00000001&(data))
#define  RL_cache_inv_get_hdr_cah_inv(data)                                      ((0x00000002&(data))>>1)
#define  RL_cache_inv_get_cah_inv(data)                                          (0x00000001&(data))

#define  RL_cah_pindx                                                            0x1800ECA8
#define  RL_cah_pindx_reg_addr                                                   "0xB800ECA8"
#define  RL_cah_pindx_reg                                                        0xB800ECA8
#define  RL_cah_pindx_inst_addr                                                  "0x0055"
#define  set_RL_cah_pindx_reg(data)                                              (*((volatile unsigned int*)RL_cah_pindx_reg)=data)
#define  get_RL_cah_pindx_reg                                                    (*((volatile unsigned int*)RL_cah_pindx_reg))
#define  RL_cah_pindx_cah_pindx0_luml0_shift                                     (24)
#define  RL_cah_pindx_cah_pindx1_luml1_shift                                     (16)
#define  RL_cah_pindx_cah_pindx2_chrl0_shift                                     (8)
#define  RL_cah_pindx_cah_pindx3_chrl1_shift                                     (0)
#define  RL_cah_pindx_cah_pindx0_luml0_mask                                      (0xFF000000)
#define  RL_cah_pindx_cah_pindx1_luml1_mask                                      (0x00FF0000)
#define  RL_cah_pindx_cah_pindx2_chrl0_mask                                      (0x0000FF00)
#define  RL_cah_pindx_cah_pindx3_chrl1_mask                                      (0x000000FF)
#define  RL_cah_pindx_cah_pindx0_luml0(data)                                     (0xFF000000&((data)<<24))
#define  RL_cah_pindx_cah_pindx1_luml1(data)                                     (0x00FF0000&((data)<<16))
#define  RL_cah_pindx_cah_pindx2_chrl0(data)                                     (0x0000FF00&((data)<<8))
#define  RL_cah_pindx_cah_pindx3_chrl1(data)                                     (0x000000FF&(data))
#define  RL_cah_pindx_get_cah_pindx0_luml0(data)                                 ((0xFF000000&(data))>>24)
#define  RL_cah_pindx_get_cah_pindx1_luml1(data)                                 ((0x00FF0000&(data))>>16)
#define  RL_cah_pindx_get_cah_pindx2_chrl0(data)                                 ((0x0000FF00&(data))>>8)
#define  RL_cah_pindx_get_cah_pindx3_chrl1(data)                                 (0x000000FF&(data))

#define  RL_hdr_cah_pindx_ext_luma                                               0x1800ECAC
#define  RL_hdr_cah_pindx_ext_luma_reg_addr                                      "0xB800ECAC"
#define  RL_hdr_cah_pindx_ext_luma_reg                                           0xB800ECAC
#define  RL_hdr_cah_pindx_ext_luma_inst_addr                                     "0x0056"
#define  set_RL_hdr_cah_pindx_ext_luma_reg(data)                                 (*((volatile unsigned int*)RL_hdr_cah_pindx_ext_luma_reg)=data)
#define  get_RL_hdr_cah_pindx_ext_luma_reg                                       (*((volatile unsigned int*)RL_hdr_cah_pindx_ext_luma_reg))
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum0_shift                      (24)
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum1_shift                      (16)
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum2_shift                      (8)
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum3_shift                      (0)
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum0_mask                       (0xFF000000)
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum1_mask                       (0x00FF0000)
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum2_mask                       (0x0000FF00)
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum3_mask                       (0x000000FF)
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum0(data)                      (0xFF000000&((data)<<24))
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum1(data)                      (0x00FF0000&((data)<<16))
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum2(data)                      (0x0000FF00&((data)<<8))
#define  RL_hdr_cah_pindx_ext_luma_ext_cah_pindx_lum3(data)                      (0x000000FF&(data))
#define  RL_hdr_cah_pindx_ext_luma_get_ext_cah_pindx_lum0(data)                  ((0xFF000000&(data))>>24)
#define  RL_hdr_cah_pindx_ext_luma_get_ext_cah_pindx_lum1(data)                  ((0x00FF0000&(data))>>16)
#define  RL_hdr_cah_pindx_ext_luma_get_ext_cah_pindx_lum2(data)                  ((0x0000FF00&(data))>>8)
#define  RL_hdr_cah_pindx_ext_luma_get_ext_cah_pindx_lum3(data)                  (0x000000FF&(data))

#define  RL_hdr_cah_pindx_ext_chroma                                             0x1800ECB0
#define  RL_hdr_cah_pindx_ext_chroma_reg_addr                                    "0xB800ECB0"
#define  RL_hdr_cah_pindx_ext_chroma_reg                                         0xB800ECB0
#define  RL_hdr_cah_pindx_ext_chroma_inst_addr                                   "0x0057"
#define  set_RL_hdr_cah_pindx_ext_chroma_reg(data)                               (*((volatile unsigned int*)RL_hdr_cah_pindx_ext_chroma_reg)=data)
#define  get_RL_hdr_cah_pindx_ext_chroma_reg                                     (*((volatile unsigned int*)RL_hdr_cah_pindx_ext_chroma_reg))
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr0_shift                    (24)
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr1_shift                    (16)
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr2_shift                    (8)
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr3_shift                    (0)
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr0_mask                     (0xFF000000)
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr1_mask                     (0x00FF0000)
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr2_mask                     (0x0000FF00)
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr3_mask                     (0x000000FF)
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr0(data)                    (0xFF000000&((data)<<24))
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr1(data)                    (0x00FF0000&((data)<<16))
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr2(data)                    (0x0000FF00&((data)<<8))
#define  RL_hdr_cah_pindx_ext_chroma_ext_cah_pindx_chr3(data)                    (0x000000FF&(data))
#define  RL_hdr_cah_pindx_ext_chroma_get_ext_cah_pindx_chr0(data)                ((0xFF000000&(data))>>24)
#define  RL_hdr_cah_pindx_ext_chroma_get_ext_cah_pindx_chr1(data)                ((0x00FF0000&(data))>>16)
#define  RL_hdr_cah_pindx_ext_chroma_get_ext_cah_pindx_chr2(data)                ((0x0000FF00&(data))>>8)
#define  RL_hdr_cah_pindx_ext_chroma_get_ext_cah_pindx_chr3(data)                (0x000000FF&(data))

#define  RL_scale_pic_0                                                          0x1800ECB4
#define  RL_scale_pic_0_reg_addr                                                 "0xB800ECB4"
#define  RL_scale_pic_0_reg                                                      0xB800ECB4
#define  RL_scale_pic_0_inst_addr                                                "0x0058"
#define  set_RL_scale_pic_0_reg(data)                                            (*((volatile unsigned int*)RL_scale_pic_0_reg)=data)
#define  get_RL_scale_pic_0_reg                                                  (*((volatile unsigned int*)RL_scale_pic_0_reg))
#define  RL_scale_pic_0_disppic_h_shift                                          (16)
#define  RL_scale_pic_0_disppic_w_shift                                          (0)
#define  RL_scale_pic_0_disppic_h_mask                                           (0x1FFF0000)
#define  RL_scale_pic_0_disppic_w_mask                                           (0x00003FFF)
#define  RL_scale_pic_0_disppic_h(data)                                          (0x1FFF0000&((data)<<16))
#define  RL_scale_pic_0_disppic_w(data)                                          (0x00003FFF&(data))
#define  RL_scale_pic_0_get_disppic_h(data)                                      ((0x1FFF0000&(data))>>16)
#define  RL_scale_pic_0_get_disppic_w(data)                                      (0x00003FFF&(data))

#define  RL_scale_pic_1                                                          0x1800ECB8
#define  RL_scale_pic_1_reg_addr                                                 "0xB800ECB8"
#define  RL_scale_pic_1_reg                                                      0xB800ECB8
#define  RL_scale_pic_1_inst_addr                                                "0x0059"
#define  set_RL_scale_pic_1_reg(data)                                            (*((volatile unsigned int*)RL_scale_pic_1_reg)=data)
#define  get_RL_scale_pic_1_reg                                                  (*((volatile unsigned int*)RL_scale_pic_1_reg))
#define  RL_scale_pic_1_disppic_h_shift                                          (16)
#define  RL_scale_pic_1_disppic_w_shift                                          (0)
#define  RL_scale_pic_1_disppic_h_mask                                           (0x1FFF0000)
#define  RL_scale_pic_1_disppic_w_mask                                           (0x00003FFF)
#define  RL_scale_pic_1_disppic_h(data)                                          (0x1FFF0000&((data)<<16))
#define  RL_scale_pic_1_disppic_w(data)                                          (0x00003FFF&(data))
#define  RL_scale_pic_1_get_disppic_h(data)                                      ((0x1FFF0000&(data))>>16)
#define  RL_scale_pic_1_get_disppic_w(data)                                      (0x00003FFF&(data))

#define  RL_scale_pic_2                                                          0x1800ECBC
#define  RL_scale_pic_2_reg_addr                                                 "0xB800ECBC"
#define  RL_scale_pic_2_reg                                                      0xB800ECBC
#define  RL_scale_pic_2_inst_addr                                                "0x005A"
#define  set_RL_scale_pic_2_reg(data)                                            (*((volatile unsigned int*)RL_scale_pic_2_reg)=data)
#define  get_RL_scale_pic_2_reg                                                  (*((volatile unsigned int*)RL_scale_pic_2_reg))
#define  RL_scale_pic_2_disppic_h_shift                                          (16)
#define  RL_scale_pic_2_disppic_w_shift                                          (0)
#define  RL_scale_pic_2_disppic_h_mask                                           (0x1FFF0000)
#define  RL_scale_pic_2_disppic_w_mask                                           (0x00003FFF)
#define  RL_scale_pic_2_disppic_h(data)                                          (0x1FFF0000&((data)<<16))
#define  RL_scale_pic_2_disppic_w(data)                                          (0x00003FFF&(data))
#define  RL_scale_pic_2_get_disppic_h(data)                                      ((0x1FFF0000&(data))>>16)
#define  RL_scale_pic_2_get_disppic_w(data)                                      (0x00003FFF&(data))

#define  RL_hdr_str_addr_lu_0                                                    0x1800ED00
#define  RL_hdr_str_addr_lu_0_reg_addr                                           "0xB800ED00"
#define  RL_hdr_str_addr_lu_0_reg                                                0xB800ED00
#define  RL_hdr_str_addr_lu_0_inst_addr                                          "0x005B"
#define  set_RL_hdr_str_addr_lu_0_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_0_reg)=data)
#define  get_RL_hdr_str_addr_lu_0_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_0_reg))
#define  RL_hdr_str_addr_lu_0_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_0_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_0_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_0_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_1                                                    0x1800ED04
#define  RL_hdr_str_addr_lu_1_reg_addr                                           "0xB800ED04"
#define  RL_hdr_str_addr_lu_1_reg                                                0xB800ED04
#define  RL_hdr_str_addr_lu_1_inst_addr                                          "0x005C"
#define  set_RL_hdr_str_addr_lu_1_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_1_reg)=data)
#define  get_RL_hdr_str_addr_lu_1_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_1_reg))
#define  RL_hdr_str_addr_lu_1_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_1_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_1_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_1_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_2                                                    0x1800ED08
#define  RL_hdr_str_addr_lu_2_reg_addr                                           "0xB800ED08"
#define  RL_hdr_str_addr_lu_2_reg                                                0xB800ED08
#define  RL_hdr_str_addr_lu_2_inst_addr                                          "0x005D"
#define  set_RL_hdr_str_addr_lu_2_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_2_reg)=data)
#define  get_RL_hdr_str_addr_lu_2_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_2_reg))
#define  RL_hdr_str_addr_lu_2_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_2_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_2_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_2_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_3                                                    0x1800ED0C
#define  RL_hdr_str_addr_lu_3_reg_addr                                           "0xB800ED0C"
#define  RL_hdr_str_addr_lu_3_reg                                                0xB800ED0C
#define  RL_hdr_str_addr_lu_3_inst_addr                                          "0x005E"
#define  set_RL_hdr_str_addr_lu_3_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_3_reg)=data)
#define  get_RL_hdr_str_addr_lu_3_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_3_reg))
#define  RL_hdr_str_addr_lu_3_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_3_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_3_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_3_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_4                                                    0x1800ED10
#define  RL_hdr_str_addr_lu_4_reg_addr                                           "0xB800ED10"
#define  RL_hdr_str_addr_lu_4_reg                                                0xB800ED10
#define  RL_hdr_str_addr_lu_4_inst_addr                                          "0x005F"
#define  set_RL_hdr_str_addr_lu_4_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_4_reg)=data)
#define  get_RL_hdr_str_addr_lu_4_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_4_reg))
#define  RL_hdr_str_addr_lu_4_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_4_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_4_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_4_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_5                                                    0x1800ED14
#define  RL_hdr_str_addr_lu_5_reg_addr                                           "0xB800ED14"
#define  RL_hdr_str_addr_lu_5_reg                                                0xB800ED14
#define  RL_hdr_str_addr_lu_5_inst_addr                                          "0x0060"
#define  set_RL_hdr_str_addr_lu_5_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_5_reg)=data)
#define  get_RL_hdr_str_addr_lu_5_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_5_reg))
#define  RL_hdr_str_addr_lu_5_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_5_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_5_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_5_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_6                                                    0x1800ED18
#define  RL_hdr_str_addr_lu_6_reg_addr                                           "0xB800ED18"
#define  RL_hdr_str_addr_lu_6_reg                                                0xB800ED18
#define  RL_hdr_str_addr_lu_6_inst_addr                                          "0x0061"
#define  set_RL_hdr_str_addr_lu_6_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_6_reg)=data)
#define  get_RL_hdr_str_addr_lu_6_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_6_reg))
#define  RL_hdr_str_addr_lu_6_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_6_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_6_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_6_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_7                                                    0x1800ED1C
#define  RL_hdr_str_addr_lu_7_reg_addr                                           "0xB800ED1C"
#define  RL_hdr_str_addr_lu_7_reg                                                0xB800ED1C
#define  RL_hdr_str_addr_lu_7_inst_addr                                          "0x0062"
#define  set_RL_hdr_str_addr_lu_7_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_7_reg)=data)
#define  get_RL_hdr_str_addr_lu_7_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_7_reg))
#define  RL_hdr_str_addr_lu_7_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_7_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_7_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_7_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_8                                                    0x1800ED20
#define  RL_hdr_str_addr_lu_8_reg_addr                                           "0xB800ED20"
#define  RL_hdr_str_addr_lu_8_reg                                                0xB800ED20
#define  RL_hdr_str_addr_lu_8_inst_addr                                          "0x0063"
#define  set_RL_hdr_str_addr_lu_8_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_8_reg)=data)
#define  get_RL_hdr_str_addr_lu_8_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_8_reg))
#define  RL_hdr_str_addr_lu_8_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_8_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_8_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_8_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_9                                                    0x1800ED24
#define  RL_hdr_str_addr_lu_9_reg_addr                                           "0xB800ED24"
#define  RL_hdr_str_addr_lu_9_reg                                                0xB800ED24
#define  RL_hdr_str_addr_lu_9_inst_addr                                          "0x0064"
#define  set_RL_hdr_str_addr_lu_9_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_lu_9_reg)=data)
#define  get_RL_hdr_str_addr_lu_9_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_lu_9_reg))
#define  RL_hdr_str_addr_lu_9_hdr_str_addr_lu_shift                              (0)
#define  RL_hdr_str_addr_lu_9_hdr_str_addr_lu_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_9_hdr_str_addr_lu(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_9_get_hdr_str_addr_lu(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_10                                                   0x1800ED28
#define  RL_hdr_str_addr_lu_10_reg_addr                                          "0xB800ED28"
#define  RL_hdr_str_addr_lu_10_reg                                               0xB800ED28
#define  RL_hdr_str_addr_lu_10_inst_addr                                         "0x0065"
#define  set_RL_hdr_str_addr_lu_10_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_10_reg)=data)
#define  get_RL_hdr_str_addr_lu_10_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_10_reg))
#define  RL_hdr_str_addr_lu_10_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_10_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_10_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_10_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_11                                                   0x1800ED2C
#define  RL_hdr_str_addr_lu_11_reg_addr                                          "0xB800ED2C"
#define  RL_hdr_str_addr_lu_11_reg                                               0xB800ED2C
#define  RL_hdr_str_addr_lu_11_inst_addr                                         "0x0066"
#define  set_RL_hdr_str_addr_lu_11_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_11_reg)=data)
#define  get_RL_hdr_str_addr_lu_11_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_11_reg))
#define  RL_hdr_str_addr_lu_11_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_11_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_11_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_11_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_12                                                   0x1800ED30
#define  RL_hdr_str_addr_lu_12_reg_addr                                          "0xB800ED30"
#define  RL_hdr_str_addr_lu_12_reg                                               0xB800ED30
#define  RL_hdr_str_addr_lu_12_inst_addr                                         "0x0067"
#define  set_RL_hdr_str_addr_lu_12_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_12_reg)=data)
#define  get_RL_hdr_str_addr_lu_12_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_12_reg))
#define  RL_hdr_str_addr_lu_12_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_12_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_12_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_12_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_13                                                   0x1800ED34
#define  RL_hdr_str_addr_lu_13_reg_addr                                          "0xB800ED34"
#define  RL_hdr_str_addr_lu_13_reg                                               0xB800ED34
#define  RL_hdr_str_addr_lu_13_inst_addr                                         "0x0068"
#define  set_RL_hdr_str_addr_lu_13_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_13_reg)=data)
#define  get_RL_hdr_str_addr_lu_13_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_13_reg))
#define  RL_hdr_str_addr_lu_13_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_13_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_13_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_13_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_14                                                   0x1800ED38
#define  RL_hdr_str_addr_lu_14_reg_addr                                          "0xB800ED38"
#define  RL_hdr_str_addr_lu_14_reg                                               0xB800ED38
#define  RL_hdr_str_addr_lu_14_inst_addr                                         "0x0069"
#define  set_RL_hdr_str_addr_lu_14_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_14_reg)=data)
#define  get_RL_hdr_str_addr_lu_14_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_14_reg))
#define  RL_hdr_str_addr_lu_14_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_14_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_14_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_14_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_15                                                   0x1800ED3C
#define  RL_hdr_str_addr_lu_15_reg_addr                                          "0xB800ED3C"
#define  RL_hdr_str_addr_lu_15_reg                                               0xB800ED3C
#define  RL_hdr_str_addr_lu_15_inst_addr                                         "0x006A"
#define  set_RL_hdr_str_addr_lu_15_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_15_reg)=data)
#define  get_RL_hdr_str_addr_lu_15_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_15_reg))
#define  RL_hdr_str_addr_lu_15_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_15_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_15_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_15_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_16                                                   0x1800ED40
#define  RL_hdr_str_addr_lu_16_reg_addr                                          "0xB800ED40"
#define  RL_hdr_str_addr_lu_16_reg                                               0xB800ED40
#define  RL_hdr_str_addr_lu_16_inst_addr                                         "0x006B"
#define  set_RL_hdr_str_addr_lu_16_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_16_reg)=data)
#define  get_RL_hdr_str_addr_lu_16_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_16_reg))
#define  RL_hdr_str_addr_lu_16_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_16_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_16_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_16_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_17                                                   0x1800ED44
#define  RL_hdr_str_addr_lu_17_reg_addr                                          "0xB800ED44"
#define  RL_hdr_str_addr_lu_17_reg                                               0xB800ED44
#define  RL_hdr_str_addr_lu_17_inst_addr                                         "0x006C"
#define  set_RL_hdr_str_addr_lu_17_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_17_reg)=data)
#define  get_RL_hdr_str_addr_lu_17_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_17_reg))
#define  RL_hdr_str_addr_lu_17_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_17_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_17_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_17_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_18                                                   0x1800ED48
#define  RL_hdr_str_addr_lu_18_reg_addr                                          "0xB800ED48"
#define  RL_hdr_str_addr_lu_18_reg                                               0xB800ED48
#define  RL_hdr_str_addr_lu_18_inst_addr                                         "0x006D"
#define  set_RL_hdr_str_addr_lu_18_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_18_reg)=data)
#define  get_RL_hdr_str_addr_lu_18_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_18_reg))
#define  RL_hdr_str_addr_lu_18_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_18_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_18_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_18_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_lu_19                                                   0x1800ED4C
#define  RL_hdr_str_addr_lu_19_reg_addr                                          "0xB800ED4C"
#define  RL_hdr_str_addr_lu_19_reg                                               0xB800ED4C
#define  RL_hdr_str_addr_lu_19_inst_addr                                         "0x006E"
#define  set_RL_hdr_str_addr_lu_19_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_lu_19_reg)=data)
#define  get_RL_hdr_str_addr_lu_19_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_lu_19_reg))
#define  RL_hdr_str_addr_lu_19_hdr_str_addr_lu_shift                             (0)
#define  RL_hdr_str_addr_lu_19_hdr_str_addr_lu_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_lu_19_hdr_str_addr_lu(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_lu_19_get_hdr_str_addr_lu(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_0                                                    0x1800ED50
#define  RL_hdr_str_addr_ch_0_reg_addr                                           "0xB800ED50"
#define  RL_hdr_str_addr_ch_0_reg                                                0xB800ED50
#define  RL_hdr_str_addr_ch_0_inst_addr                                          "0x006F"
#define  set_RL_hdr_str_addr_ch_0_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_0_reg)=data)
#define  get_RL_hdr_str_addr_ch_0_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_0_reg))
#define  RL_hdr_str_addr_ch_0_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_0_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_0_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_0_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_1                                                    0x1800ED54
#define  RL_hdr_str_addr_ch_1_reg_addr                                           "0xB800ED54"
#define  RL_hdr_str_addr_ch_1_reg                                                0xB800ED54
#define  RL_hdr_str_addr_ch_1_inst_addr                                          "0x0070"
#define  set_RL_hdr_str_addr_ch_1_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_1_reg)=data)
#define  get_RL_hdr_str_addr_ch_1_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_1_reg))
#define  RL_hdr_str_addr_ch_1_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_1_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_1_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_1_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_2                                                    0x1800ED58
#define  RL_hdr_str_addr_ch_2_reg_addr                                           "0xB800ED58"
#define  RL_hdr_str_addr_ch_2_reg                                                0xB800ED58
#define  RL_hdr_str_addr_ch_2_inst_addr                                          "0x0071"
#define  set_RL_hdr_str_addr_ch_2_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_2_reg)=data)
#define  get_RL_hdr_str_addr_ch_2_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_2_reg))
#define  RL_hdr_str_addr_ch_2_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_2_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_2_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_2_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_3                                                    0x1800ED5C
#define  RL_hdr_str_addr_ch_3_reg_addr                                           "0xB800ED5C"
#define  RL_hdr_str_addr_ch_3_reg                                                0xB800ED5C
#define  RL_hdr_str_addr_ch_3_inst_addr                                          "0x0072"
#define  set_RL_hdr_str_addr_ch_3_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_3_reg)=data)
#define  get_RL_hdr_str_addr_ch_3_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_3_reg))
#define  RL_hdr_str_addr_ch_3_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_3_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_3_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_3_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_4                                                    0x1800ED60
#define  RL_hdr_str_addr_ch_4_reg_addr                                           "0xB800ED60"
#define  RL_hdr_str_addr_ch_4_reg                                                0xB800ED60
#define  RL_hdr_str_addr_ch_4_inst_addr                                          "0x0073"
#define  set_RL_hdr_str_addr_ch_4_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_4_reg)=data)
#define  get_RL_hdr_str_addr_ch_4_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_4_reg))
#define  RL_hdr_str_addr_ch_4_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_4_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_4_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_4_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_5                                                    0x1800ED64
#define  RL_hdr_str_addr_ch_5_reg_addr                                           "0xB800ED64"
#define  RL_hdr_str_addr_ch_5_reg                                                0xB800ED64
#define  RL_hdr_str_addr_ch_5_inst_addr                                          "0x0074"
#define  set_RL_hdr_str_addr_ch_5_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_5_reg)=data)
#define  get_RL_hdr_str_addr_ch_5_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_5_reg))
#define  RL_hdr_str_addr_ch_5_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_5_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_5_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_5_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_6                                                    0x1800ED68
#define  RL_hdr_str_addr_ch_6_reg_addr                                           "0xB800ED68"
#define  RL_hdr_str_addr_ch_6_reg                                                0xB800ED68
#define  RL_hdr_str_addr_ch_6_inst_addr                                          "0x0075"
#define  set_RL_hdr_str_addr_ch_6_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_6_reg)=data)
#define  get_RL_hdr_str_addr_ch_6_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_6_reg))
#define  RL_hdr_str_addr_ch_6_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_6_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_6_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_6_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_7                                                    0x1800ED6C
#define  RL_hdr_str_addr_ch_7_reg_addr                                           "0xB800ED6C"
#define  RL_hdr_str_addr_ch_7_reg                                                0xB800ED6C
#define  RL_hdr_str_addr_ch_7_inst_addr                                          "0x0076"
#define  set_RL_hdr_str_addr_ch_7_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_7_reg)=data)
#define  get_RL_hdr_str_addr_ch_7_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_7_reg))
#define  RL_hdr_str_addr_ch_7_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_7_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_7_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_7_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_8                                                    0x1800ED70
#define  RL_hdr_str_addr_ch_8_reg_addr                                           "0xB800ED70"
#define  RL_hdr_str_addr_ch_8_reg                                                0xB800ED70
#define  RL_hdr_str_addr_ch_8_inst_addr                                          "0x0077"
#define  set_RL_hdr_str_addr_ch_8_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_8_reg)=data)
#define  get_RL_hdr_str_addr_ch_8_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_8_reg))
#define  RL_hdr_str_addr_ch_8_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_8_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_8_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_8_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_9                                                    0x1800ED74
#define  RL_hdr_str_addr_ch_9_reg_addr                                           "0xB800ED74"
#define  RL_hdr_str_addr_ch_9_reg                                                0xB800ED74
#define  RL_hdr_str_addr_ch_9_inst_addr                                          "0x0078"
#define  set_RL_hdr_str_addr_ch_9_reg(data)                                      (*((volatile unsigned int*)RL_hdr_str_addr_ch_9_reg)=data)
#define  get_RL_hdr_str_addr_ch_9_reg                                            (*((volatile unsigned int*)RL_hdr_str_addr_ch_9_reg))
#define  RL_hdr_str_addr_ch_9_hdr_str_addr_ch_shift                              (0)
#define  RL_hdr_str_addr_ch_9_hdr_str_addr_ch_mask                               (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_9_hdr_str_addr_ch(data)                              (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_9_get_hdr_str_addr_ch(data)                          (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_10                                                   0x1800ED78
#define  RL_hdr_str_addr_ch_10_reg_addr                                          "0xB800ED78"
#define  RL_hdr_str_addr_ch_10_reg                                               0xB800ED78
#define  RL_hdr_str_addr_ch_10_inst_addr                                         "0x0079"
#define  set_RL_hdr_str_addr_ch_10_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_10_reg)=data)
#define  get_RL_hdr_str_addr_ch_10_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_10_reg))
#define  RL_hdr_str_addr_ch_10_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_10_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_10_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_10_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_11                                                   0x1800ED7C
#define  RL_hdr_str_addr_ch_11_reg_addr                                          "0xB800ED7C"
#define  RL_hdr_str_addr_ch_11_reg                                               0xB800ED7C
#define  RL_hdr_str_addr_ch_11_inst_addr                                         "0x007A"
#define  set_RL_hdr_str_addr_ch_11_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_11_reg)=data)
#define  get_RL_hdr_str_addr_ch_11_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_11_reg))
#define  RL_hdr_str_addr_ch_11_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_11_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_11_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_11_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_12                                                   0x1800ED80
#define  RL_hdr_str_addr_ch_12_reg_addr                                          "0xB800ED80"
#define  RL_hdr_str_addr_ch_12_reg                                               0xB800ED80
#define  RL_hdr_str_addr_ch_12_inst_addr                                         "0x007B"
#define  set_RL_hdr_str_addr_ch_12_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_12_reg)=data)
#define  get_RL_hdr_str_addr_ch_12_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_12_reg))
#define  RL_hdr_str_addr_ch_12_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_12_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_12_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_12_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_13                                                   0x1800ED84
#define  RL_hdr_str_addr_ch_13_reg_addr                                          "0xB800ED84"
#define  RL_hdr_str_addr_ch_13_reg                                               0xB800ED84
#define  RL_hdr_str_addr_ch_13_inst_addr                                         "0x007C"
#define  set_RL_hdr_str_addr_ch_13_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_13_reg)=data)
#define  get_RL_hdr_str_addr_ch_13_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_13_reg))
#define  RL_hdr_str_addr_ch_13_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_13_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_13_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_13_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_14                                                   0x1800ED88
#define  RL_hdr_str_addr_ch_14_reg_addr                                          "0xB800ED88"
#define  RL_hdr_str_addr_ch_14_reg                                               0xB800ED88
#define  RL_hdr_str_addr_ch_14_inst_addr                                         "0x007D"
#define  set_RL_hdr_str_addr_ch_14_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_14_reg)=data)
#define  get_RL_hdr_str_addr_ch_14_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_14_reg))
#define  RL_hdr_str_addr_ch_14_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_14_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_14_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_14_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_15                                                   0x1800ED8C
#define  RL_hdr_str_addr_ch_15_reg_addr                                          "0xB800ED8C"
#define  RL_hdr_str_addr_ch_15_reg                                               0xB800ED8C
#define  RL_hdr_str_addr_ch_15_inst_addr                                         "0x007E"
#define  set_RL_hdr_str_addr_ch_15_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_15_reg)=data)
#define  get_RL_hdr_str_addr_ch_15_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_15_reg))
#define  RL_hdr_str_addr_ch_15_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_15_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_15_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_15_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_16                                                   0x1800ED90
#define  RL_hdr_str_addr_ch_16_reg_addr                                          "0xB800ED90"
#define  RL_hdr_str_addr_ch_16_reg                                               0xB800ED90
#define  RL_hdr_str_addr_ch_16_inst_addr                                         "0x007F"
#define  set_RL_hdr_str_addr_ch_16_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_16_reg)=data)
#define  get_RL_hdr_str_addr_ch_16_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_16_reg))
#define  RL_hdr_str_addr_ch_16_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_16_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_16_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_16_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_17                                                   0x1800ED94
#define  RL_hdr_str_addr_ch_17_reg_addr                                          "0xB800ED94"
#define  RL_hdr_str_addr_ch_17_reg                                               0xB800ED94
#define  RL_hdr_str_addr_ch_17_inst_addr                                         "0x0080"
#define  set_RL_hdr_str_addr_ch_17_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_17_reg)=data)
#define  get_RL_hdr_str_addr_ch_17_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_17_reg))
#define  RL_hdr_str_addr_ch_17_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_17_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_17_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_17_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_18                                                   0x1800ED98
#define  RL_hdr_str_addr_ch_18_reg_addr                                          "0xB800ED98"
#define  RL_hdr_str_addr_ch_18_reg                                               0xB800ED98
#define  RL_hdr_str_addr_ch_18_inst_addr                                         "0x0081"
#define  set_RL_hdr_str_addr_ch_18_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_18_reg)=data)
#define  get_RL_hdr_str_addr_ch_18_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_18_reg))
#define  RL_hdr_str_addr_ch_18_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_18_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_18_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_18_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_str_addr_ch_19                                                   0x1800ED9C
#define  RL_hdr_str_addr_ch_19_reg_addr                                          "0xB800ED9C"
#define  RL_hdr_str_addr_ch_19_reg                                               0xB800ED9C
#define  RL_hdr_str_addr_ch_19_inst_addr                                         "0x0082"
#define  set_RL_hdr_str_addr_ch_19_reg(data)                                     (*((volatile unsigned int*)RL_hdr_str_addr_ch_19_reg)=data)
#define  get_RL_hdr_str_addr_ch_19_reg                                           (*((volatile unsigned int*)RL_hdr_str_addr_ch_19_reg))
#define  RL_hdr_str_addr_ch_19_hdr_str_addr_ch_shift                             (0)
#define  RL_hdr_str_addr_ch_19_hdr_str_addr_ch_mask                              (0xFFFFFFFF)
#define  RL_hdr_str_addr_ch_19_hdr_str_addr_ch(data)                             (0xFFFFFFFF&(data))
#define  RL_hdr_str_addr_ch_19_get_hdr_str_addr_ch(data)                         (0xFFFFFFFF&(data))

#define  RL_hdr_map_idx_0                                                        0x1800EDA0
#define  RL_hdr_map_idx_0_reg_addr                                               "0xB800EDA0"
#define  RL_hdr_map_idx_0_reg                                                    0xB800EDA0
#define  RL_hdr_map_idx_0_inst_addr                                              "0x0083"
#define  set_RL_hdr_map_idx_0_reg(data)                                          (*((volatile unsigned int*)RL_hdr_map_idx_0_reg)=data)
#define  get_RL_hdr_map_idx_0_reg                                                (*((volatile unsigned int*)RL_hdr_map_idx_0_reg))
#define  RL_hdr_map_idx_0_dmy_shift                                              (28)
#define  RL_hdr_map_idx_0_hdr_map_idx_0_shift                                    (21)
#define  RL_hdr_map_idx_0_hdr_map_idx_1_shift                                    (14)
#define  RL_hdr_map_idx_0_hdr_map_idx_2_shift                                    (7)
#define  RL_hdr_map_idx_0_hdr_map_idx_3_shift                                    (0)
#define  RL_hdr_map_idx_0_dmy_mask                                               (0xF0000000)
#define  RL_hdr_map_idx_0_hdr_map_idx_0_mask                                     (0x0FE00000)
#define  RL_hdr_map_idx_0_hdr_map_idx_1_mask                                     (0x001FC000)
#define  RL_hdr_map_idx_0_hdr_map_idx_2_mask                                     (0x00003F80)
#define  RL_hdr_map_idx_0_hdr_map_idx_3_mask                                     (0x0000007F)
#define  RL_hdr_map_idx_0_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_hdr_map_idx_0_hdr_map_idx_0(data)                                    (0x0FE00000&((data)<<21))
#define  RL_hdr_map_idx_0_hdr_map_idx_1(data)                                    (0x001FC000&((data)<<14))
#define  RL_hdr_map_idx_0_hdr_map_idx_2(data)                                    (0x00003F80&((data)<<7))
#define  RL_hdr_map_idx_0_hdr_map_idx_3(data)                                    (0x0000007F&(data))
#define  RL_hdr_map_idx_0_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_hdr_map_idx_0_get_hdr_map_idx_0(data)                                ((0x0FE00000&(data))>>21)
#define  RL_hdr_map_idx_0_get_hdr_map_idx_1(data)                                ((0x001FC000&(data))>>14)
#define  RL_hdr_map_idx_0_get_hdr_map_idx_2(data)                                ((0x00003F80&(data))>>7)
#define  RL_hdr_map_idx_0_get_hdr_map_idx_3(data)                                (0x0000007F&(data))

#define  RL_hdr_map_idx_1                                                        0x1800EDA4
#define  RL_hdr_map_idx_1_reg_addr                                               "0xB800EDA4"
#define  RL_hdr_map_idx_1_reg                                                    0xB800EDA4
#define  RL_hdr_map_idx_1_inst_addr                                              "0x0084"
#define  set_RL_hdr_map_idx_1_reg(data)                                          (*((volatile unsigned int*)RL_hdr_map_idx_1_reg)=data)
#define  get_RL_hdr_map_idx_1_reg                                                (*((volatile unsigned int*)RL_hdr_map_idx_1_reg))
#define  RL_hdr_map_idx_1_dmy_shift                                              (28)
#define  RL_hdr_map_idx_1_hdr_map_idx_4_shift                                    (21)
#define  RL_hdr_map_idx_1_hdr_map_idx_5_shift                                    (14)
#define  RL_hdr_map_idx_1_hdr_map_idx_6_shift                                    (7)
#define  RL_hdr_map_idx_1_hdr_map_idx_7_shift                                    (0)
#define  RL_hdr_map_idx_1_dmy_mask                                               (0xF0000000)
#define  RL_hdr_map_idx_1_hdr_map_idx_4_mask                                     (0x0FE00000)
#define  RL_hdr_map_idx_1_hdr_map_idx_5_mask                                     (0x001FC000)
#define  RL_hdr_map_idx_1_hdr_map_idx_6_mask                                     (0x00003F80)
#define  RL_hdr_map_idx_1_hdr_map_idx_7_mask                                     (0x0000007F)
#define  RL_hdr_map_idx_1_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_hdr_map_idx_1_hdr_map_idx_4(data)                                    (0x0FE00000&((data)<<21))
#define  RL_hdr_map_idx_1_hdr_map_idx_5(data)                                    (0x001FC000&((data)<<14))
#define  RL_hdr_map_idx_1_hdr_map_idx_6(data)                                    (0x00003F80&((data)<<7))
#define  RL_hdr_map_idx_1_hdr_map_idx_7(data)                                    (0x0000007F&(data))
#define  RL_hdr_map_idx_1_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_hdr_map_idx_1_get_hdr_map_idx_4(data)                                ((0x0FE00000&(data))>>21)
#define  RL_hdr_map_idx_1_get_hdr_map_idx_5(data)                                ((0x001FC000&(data))>>14)
#define  RL_hdr_map_idx_1_get_hdr_map_idx_6(data)                                ((0x00003F80&(data))>>7)
#define  RL_hdr_map_idx_1_get_hdr_map_idx_7(data)                                (0x0000007F&(data))

#define  RL_hdr_map_idx_2                                                        0x1800EDA8
#define  RL_hdr_map_idx_2_reg_addr                                               "0xB800EDA8"
#define  RL_hdr_map_idx_2_reg                                                    0xB800EDA8
#define  RL_hdr_map_idx_2_inst_addr                                              "0x0085"
#define  set_RL_hdr_map_idx_2_reg(data)                                          (*((volatile unsigned int*)RL_hdr_map_idx_2_reg)=data)
#define  get_RL_hdr_map_idx_2_reg                                                (*((volatile unsigned int*)RL_hdr_map_idx_2_reg))
#define  RL_hdr_map_idx_2_dmy_shift                                              (28)
#define  RL_hdr_map_idx_2_hdr_map_idx_8_shift                                    (21)
#define  RL_hdr_map_idx_2_hdr_map_idx_9_shift                                    (14)
#define  RL_hdr_map_idx_2_hdr_map_idx_10_shift                                   (7)
#define  RL_hdr_map_idx_2_hdr_map_idx_11_shift                                   (0)
#define  RL_hdr_map_idx_2_dmy_mask                                               (0xF0000000)
#define  RL_hdr_map_idx_2_hdr_map_idx_8_mask                                     (0x0FE00000)
#define  RL_hdr_map_idx_2_hdr_map_idx_9_mask                                     (0x001FC000)
#define  RL_hdr_map_idx_2_hdr_map_idx_10_mask                                    (0x00003F80)
#define  RL_hdr_map_idx_2_hdr_map_idx_11_mask                                    (0x0000007F)
#define  RL_hdr_map_idx_2_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_hdr_map_idx_2_hdr_map_idx_8(data)                                    (0x0FE00000&((data)<<21))
#define  RL_hdr_map_idx_2_hdr_map_idx_9(data)                                    (0x001FC000&((data)<<14))
#define  RL_hdr_map_idx_2_hdr_map_idx_10(data)                                   (0x00003F80&((data)<<7))
#define  RL_hdr_map_idx_2_hdr_map_idx_11(data)                                   (0x0000007F&(data))
#define  RL_hdr_map_idx_2_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_hdr_map_idx_2_get_hdr_map_idx_8(data)                                ((0x0FE00000&(data))>>21)
#define  RL_hdr_map_idx_2_get_hdr_map_idx_9(data)                                ((0x001FC000&(data))>>14)
#define  RL_hdr_map_idx_2_get_hdr_map_idx_10(data)                               ((0x00003F80&(data))>>7)
#define  RL_hdr_map_idx_2_get_hdr_map_idx_11(data)                               (0x0000007F&(data))

#define  RL_hdr_map_idx_3                                                        0x1800EDAC
#define  RL_hdr_map_idx_3_reg_addr                                               "0xB800EDAC"
#define  RL_hdr_map_idx_3_reg                                                    0xB800EDAC
#define  RL_hdr_map_idx_3_inst_addr                                              "0x0086"
#define  set_RL_hdr_map_idx_3_reg(data)                                          (*((volatile unsigned int*)RL_hdr_map_idx_3_reg)=data)
#define  get_RL_hdr_map_idx_3_reg                                                (*((volatile unsigned int*)RL_hdr_map_idx_3_reg))
#define  RL_hdr_map_idx_3_dmy_shift                                              (28)
#define  RL_hdr_map_idx_3_hdr_map_idx_12_shift                                   (21)
#define  RL_hdr_map_idx_3_hdr_map_idx_13_shift                                   (14)
#define  RL_hdr_map_idx_3_hdr_map_idx_14_shift                                   (7)
#define  RL_hdr_map_idx_3_hdr_map_idx_15_shift                                   (0)
#define  RL_hdr_map_idx_3_dmy_mask                                               (0xF0000000)
#define  RL_hdr_map_idx_3_hdr_map_idx_12_mask                                    (0x0FE00000)
#define  RL_hdr_map_idx_3_hdr_map_idx_13_mask                                    (0x001FC000)
#define  RL_hdr_map_idx_3_hdr_map_idx_14_mask                                    (0x00003F80)
#define  RL_hdr_map_idx_3_hdr_map_idx_15_mask                                    (0x0000007F)
#define  RL_hdr_map_idx_3_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_hdr_map_idx_3_hdr_map_idx_12(data)                                   (0x0FE00000&((data)<<21))
#define  RL_hdr_map_idx_3_hdr_map_idx_13(data)                                   (0x001FC000&((data)<<14))
#define  RL_hdr_map_idx_3_hdr_map_idx_14(data)                                   (0x00003F80&((data)<<7))
#define  RL_hdr_map_idx_3_hdr_map_idx_15(data)                                   (0x0000007F&(data))
#define  RL_hdr_map_idx_3_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_hdr_map_idx_3_get_hdr_map_idx_12(data)                               ((0x0FE00000&(data))>>21)
#define  RL_hdr_map_idx_3_get_hdr_map_idx_13(data)                               ((0x001FC000&(data))>>14)
#define  RL_hdr_map_idx_3_get_hdr_map_idx_14(data)                               ((0x00003F80&(data))>>7)
#define  RL_hdr_map_idx_3_get_hdr_map_idx_15(data)                               (0x0000007F&(data))

#define  RL_hdr_map_idx_4                                                        0x1800EDB0
#define  RL_hdr_map_idx_4_reg_addr                                               "0xB800EDB0"
#define  RL_hdr_map_idx_4_reg                                                    0xB800EDB0
#define  RL_hdr_map_idx_4_inst_addr                                              "0x0087"
#define  set_RL_hdr_map_idx_4_reg(data)                                          (*((volatile unsigned int*)RL_hdr_map_idx_4_reg)=data)
#define  get_RL_hdr_map_idx_4_reg                                                (*((volatile unsigned int*)RL_hdr_map_idx_4_reg))
#define  RL_hdr_map_idx_4_dmy_shift                                              (28)
#define  RL_hdr_map_idx_4_hdr_map_idx_16_shift                                   (21)
#define  RL_hdr_map_idx_4_hdr_map_idx_17_shift                                   (14)
#define  RL_hdr_map_idx_4_hdr_map_idx_18_shift                                   (7)
#define  RL_hdr_map_idx_4_hdr_map_idx_19_shift                                   (0)
#define  RL_hdr_map_idx_4_dmy_mask                                               (0xF0000000)
#define  RL_hdr_map_idx_4_hdr_map_idx_16_mask                                    (0x0FE00000)
#define  RL_hdr_map_idx_4_hdr_map_idx_17_mask                                    (0x001FC000)
#define  RL_hdr_map_idx_4_hdr_map_idx_18_mask                                    (0x00003F80)
#define  RL_hdr_map_idx_4_hdr_map_idx_19_mask                                    (0x0000007F)
#define  RL_hdr_map_idx_4_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_hdr_map_idx_4_hdr_map_idx_16(data)                                   (0x0FE00000&((data)<<21))
#define  RL_hdr_map_idx_4_hdr_map_idx_17(data)                                   (0x001FC000&((data)<<14))
#define  RL_hdr_map_idx_4_hdr_map_idx_18(data)                                   (0x00003F80&((data)<<7))
#define  RL_hdr_map_idx_4_hdr_map_idx_19(data)                                   (0x0000007F&(data))
#define  RL_hdr_map_idx_4_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_hdr_map_idx_4_get_hdr_map_idx_16(data)                               ((0x0FE00000&(data))>>21)
#define  RL_hdr_map_idx_4_get_hdr_map_idx_17(data)                               ((0x001FC000&(data))>>14)
#define  RL_hdr_map_idx_4_get_hdr_map_idx_18(data)                               ((0x00003F80&(data))>>7)
#define  RL_hdr_map_idx_4_get_hdr_map_idx_19(data)                               (0x0000007F&(data))

#define  RL_dcmprs_core_flag_en                                                  0x1800EDB4
#define  RL_dcmprs_core_flag_en_reg_addr                                         "0xB800EDB4"
#define  RL_dcmprs_core_flag_en_reg                                              0xB800EDB4
#define  RL_dcmprs_core_flag_en_inst_addr                                        "0x0088"
#define  set_RL_dcmprs_core_flag_en_reg(data)                                    (*((volatile unsigned int*)RL_dcmprs_core_flag_en_reg)=data)
#define  get_RL_dcmprs_core_flag_en_reg                                          (*((volatile unsigned int*)RL_dcmprs_core_flag_en_reg))
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_3_shift                         (24)
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_2_shift                         (16)
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_1_shift                         (8)
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_0_shift                         (0)
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_3_mask                          (0xFF000000)
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_2_mask                          (0x00FF0000)
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_1_mask                          (0x0000FF00)
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_0_mask                          (0x000000FF)
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_3(data)                         (0xFF000000&((data)<<24))
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_2(data)                         (0x00FF0000&((data)<<16))
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_1(data)                         (0x0000FF00&((data)<<8))
#define  RL_dcmprs_core_flag_en_core_flag2irq_en_0(data)                         (0x000000FF&(data))
#define  RL_dcmprs_core_flag_en_get_core_flag2irq_en_3(data)                     ((0xFF000000&(data))>>24)
#define  RL_dcmprs_core_flag_en_get_core_flag2irq_en_2(data)                     ((0x00FF0000&(data))>>16)
#define  RL_dcmprs_core_flag_en_get_core_flag2irq_en_1(data)                     ((0x0000FF00&(data))>>8)
#define  RL_dcmprs_core_flag_en_get_core_flag2irq_en_0(data)                     (0x000000FF&(data))

#define  RL_dcmprs_core_flag_clr                                                 0x1800EDB8
#define  RL_dcmprs_core_flag_clr_reg_addr                                        "0xB800EDB8"
#define  RL_dcmprs_core_flag_clr_reg                                             0xB800EDB8
#define  RL_dcmprs_core_flag_clr_inst_addr                                       "0x0089"
#define  set_RL_dcmprs_core_flag_clr_reg(data)                                   (*((volatile unsigned int*)RL_dcmprs_core_flag_clr_reg)=data)
#define  get_RL_dcmprs_core_flag_clr_reg                                         (*((volatile unsigned int*)RL_dcmprs_core_flag_clr_reg))
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_3_shift                        (24)
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_2_shift                        (16)
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_1_shift                        (8)
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_0_shift                        (0)
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_3_mask                         (0xFF000000)
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_2_mask                         (0x00FF0000)
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_1_mask                         (0x0000FF00)
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_0_mask                         (0x000000FF)
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_3(data)                        (0xFF000000&((data)<<24))
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_2(data)                        (0x00FF0000&((data)<<16))
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_1(data)                        (0x0000FF00&((data)<<8))
#define  RL_dcmprs_core_flag_clr_core_errflag_clr_0(data)                        (0x000000FF&(data))
#define  RL_dcmprs_core_flag_clr_get_core_errflag_clr_3(data)                    ((0xFF000000&(data))>>24)
#define  RL_dcmprs_core_flag_clr_get_core_errflag_clr_2(data)                    ((0x00FF0000&(data))>>16)
#define  RL_dcmprs_core_flag_clr_get_core_errflag_clr_1(data)                    ((0x0000FF00&(data))>>8)
#define  RL_dcmprs_core_flag_clr_get_core_errflag_clr_0(data)                    (0x000000FF&(data))

#define  RL_dcmprs_core_flag                                                     0x1800EDBC
#define  RL_dcmprs_core_flag_reg_addr                                            "0xB800EDBC"
#define  RL_dcmprs_core_flag_reg                                                 0xB800EDBC
#define  RL_dcmprs_core_flag_inst_addr                                           "0x008A"
#define  set_RL_dcmprs_core_flag_reg(data)                                       (*((volatile unsigned int*)RL_dcmprs_core_flag_reg)=data)
#define  get_RL_dcmprs_core_flag_reg                                             (*((volatile unsigned int*)RL_dcmprs_core_flag_reg))
#define  RL_dcmprs_core_flag_core_errflag_ro_3_shift                             (24)
#define  RL_dcmprs_core_flag_core_errflag_ro_2_shift                             (16)
#define  RL_dcmprs_core_flag_core_errflag_ro_1_shift                             (8)
#define  RL_dcmprs_core_flag_core_errflag_ro_0_shift                             (0)
#define  RL_dcmprs_core_flag_core_errflag_ro_3_mask                              (0xFF000000)
#define  RL_dcmprs_core_flag_core_errflag_ro_2_mask                              (0x00FF0000)
#define  RL_dcmprs_core_flag_core_errflag_ro_1_mask                              (0x0000FF00)
#define  RL_dcmprs_core_flag_core_errflag_ro_0_mask                              (0x000000FF)
#define  RL_dcmprs_core_flag_core_errflag_ro_3(data)                             (0xFF000000&((data)<<24))
#define  RL_dcmprs_core_flag_core_errflag_ro_2(data)                             (0x00FF0000&((data)<<16))
#define  RL_dcmprs_core_flag_core_errflag_ro_1(data)                             (0x0000FF00&((data)<<8))
#define  RL_dcmprs_core_flag_core_errflag_ro_0(data)                             (0x000000FF&(data))
#define  RL_dcmprs_core_flag_get_core_errflag_ro_3(data)                         ((0xFF000000&(data))>>24)
#define  RL_dcmprs_core_flag_get_core_errflag_ro_2(data)                         ((0x00FF0000&(data))>>16)
#define  RL_dcmprs_core_flag_get_core_errflag_ro_1(data)                         ((0x0000FF00&(data))>>8)
#define  RL_dcmprs_core_flag_get_core_errflag_ro_0(data)                         (0x000000FF&(data))

#define  RL_dcmprs_core_flag_irq                                                 0x1800EDC0
#define  RL_dcmprs_core_flag_irq_reg_addr                                        "0xB800EDC0"
#define  RL_dcmprs_core_flag_irq_reg                                             0xB800EDC0
#define  RL_dcmprs_core_flag_irq_inst_addr                                       "0x008B"
#define  set_RL_dcmprs_core_flag_irq_reg(data)                                   (*((volatile unsigned int*)RL_dcmprs_core_flag_irq_reg)=data)
#define  get_RL_dcmprs_core_flag_irq_reg                                         (*((volatile unsigned int*)RL_dcmprs_core_flag_irq_reg))
#define  RL_dcmprs_core_flag_irq_dmy_shift                                       (4)
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_3_shift                        (3)
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_2_shift                        (2)
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_1_shift                        (1)
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_0_shift                        (0)
#define  RL_dcmprs_core_flag_irq_dmy_mask                                        (0xFFFFFFF0)
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_3_mask                         (0x00000008)
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_2_mask                         (0x00000004)
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_1_mask                         (0x00000002)
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_0_mask                         (0x00000001)
#define  RL_dcmprs_core_flag_irq_dmy(data)                                       (0xFFFFFFF0&((data)<<4))
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_3(data)                        (0x00000008&((data)<<3))
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_2(data)                        (0x00000004&((data)<<2))
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_1(data)                        (0x00000002&((data)<<1))
#define  RL_dcmprs_core_flag_irq_core_errflag_irq_0(data)                        (0x00000001&(data))
#define  RL_dcmprs_core_flag_irq_get_dmy(data)                                   ((0xFFFFFFF0&(data))>>4)
#define  RL_dcmprs_core_flag_irq_get_core_errflag_irq_3(data)                    ((0x00000008&(data))>>3)
#define  RL_dcmprs_core_flag_irq_get_core_errflag_irq_2(data)                    ((0x00000004&(data))>>2)
#define  RL_dcmprs_core_flag_irq_get_core_errflag_irq_1(data)                    ((0x00000002&(data))>>1)
#define  RL_dcmprs_core_flag_irq_get_core_errflag_irq_0(data)                    (0x00000001&(data))

#define  RL_dcmprs_wrap_width                                                    0x1800EDC4
#define  RL_dcmprs_wrap_width_reg_addr                                           "0xB800EDC4"
#define  RL_dcmprs_wrap_width_reg                                                0xB800EDC4
#define  RL_dcmprs_wrap_width_inst_addr                                          "0x008C"
#define  set_RL_dcmprs_wrap_width_reg(data)                                      (*((volatile unsigned int*)RL_dcmprs_wrap_width_reg)=data)
#define  get_RL_dcmprs_wrap_width_reg                                            (*((volatile unsigned int*)RL_dcmprs_wrap_width_reg))
#define  RL_dcmprs_wrap_width_dmy_shift                                          (30)
#define  RL_dcmprs_wrap_width_wrap_width_2_shift                                 (20)
#define  RL_dcmprs_wrap_width_wrap_width_1_shift                                 (10)
#define  RL_dcmprs_wrap_width_wrap_width_0_shift                                 (0)
#define  RL_dcmprs_wrap_width_dmy_mask                                           (0xC0000000)
#define  RL_dcmprs_wrap_width_wrap_width_2_mask                                  (0x3FF00000)
#define  RL_dcmprs_wrap_width_wrap_width_1_mask                                  (0x000FFC00)
#define  RL_dcmprs_wrap_width_wrap_width_0_mask                                  (0x000003FF)
#define  RL_dcmprs_wrap_width_dmy(data)                                          (0xC0000000&((data)<<30))
#define  RL_dcmprs_wrap_width_wrap_width_2(data)                                 (0x3FF00000&((data)<<20))
#define  RL_dcmprs_wrap_width_wrap_width_1(data)                                 (0x000FFC00&((data)<<10))
#define  RL_dcmprs_wrap_width_wrap_width_0(data)                                 (0x000003FF&(data))
#define  RL_dcmprs_wrap_width_get_dmy(data)                                      ((0xC0000000&(data))>>30)
#define  RL_dcmprs_wrap_width_get_wrap_width_2(data)                             ((0x3FF00000&(data))>>20)
#define  RL_dcmprs_wrap_width_get_wrap_width_1(data)                             ((0x000FFC00&(data))>>10)
#define  RL_dcmprs_wrap_width_get_wrap_width_0(data)                             (0x000003FF&(data))

#define  RL_dcmprs_dbg_out                                                       0x1800EDC8
#define  RL_dcmprs_dbg_out_reg_addr                                              "0xB800EDC8"
#define  RL_dcmprs_dbg_out_reg                                                   0xB800EDC8
#define  RL_dcmprs_dbg_out_inst_addr                                             "0x008D"
#define  set_RL_dcmprs_dbg_out_reg(data)                                         (*((volatile unsigned int*)RL_dcmprs_dbg_out_reg)=data)
#define  get_RL_dcmprs_dbg_out_reg                                               (*((volatile unsigned int*)RL_dcmprs_dbg_out_reg))
#define  RL_dcmprs_dbg_out_debug_out1_shift                                      (16)
#define  RL_dcmprs_dbg_out_debug_out0_shift                                      (0)
#define  RL_dcmprs_dbg_out_debug_out1_mask                                       (0xFFFF0000)
#define  RL_dcmprs_dbg_out_debug_out0_mask                                       (0x0000FFFF)
#define  RL_dcmprs_dbg_out_debug_out1(data)                                      (0xFFFF0000&((data)<<16))
#define  RL_dcmprs_dbg_out_debug_out0(data)                                      (0x0000FFFF&(data))
#define  RL_dcmprs_dbg_out_get_debug_out1(data)                                  ((0xFFFF0000&(data))>>16)
#define  RL_dcmprs_dbg_out_get_debug_out0(data)                                  (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======RL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disppic_h:13;
        RBus_UInt32  res2:1;
        RBus_UInt32  disppic_w:14;
        RBus_UInt32  cur_rangeredfrm:1;
    };
}rl_rlcntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  rmem_wptr_rst:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  ldmc_bypass:1;
        RBus_UInt32  pred_enable:1;
        RBus_UInt32  ldmc_enable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  manual_thresh_ena:1;
        RBus_UInt32  rm_threshold:6;
    };
}rl_rlcntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hevc_zidx:8;
        RBus_UInt32  hevc_log2cbsize_minus3:2;
        RBus_UInt32  pictype:3;
        RBus_UInt32  first_mb:1;
        RBus_UInt32  cur_mb_x:9;
        RBus_UInt32  cur_mb_y:9;
    };
}rl_ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  paddingcu:1;
        RBus_UInt32  dummycolctb:1;
        RBus_UInt32  dummyrowctb:1;
        RBus_UInt32  mb_field_decoding_flag:1;
        RBus_UInt32  mb_partition:9;
    };
}rl_h264ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  intramb_flag:1;
        RBus_UInt32  intra_flag:5;
        RBus_UInt32  submb_partition:12;
        RBus_UInt32  mvtype:2;
        RBus_UInt32  fieldtx:1;
        RBus_UInt32  overflag:1;
    };
}rl_vc1ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  chroma_predict_part0:2;
        RBus_UInt32  chroma_predict_part1:2;
        RBus_UInt32  chroma_predict_part2:2;
        RBus_UInt32  chroma_predict_part3:2;
        RBus_UInt32  inter_predict_part0:2;
        RBus_UInt32  inter_predict_part1:2;
        RBus_UInt32  inter_predict_part2:2;
        RBus_UInt32  inter_predict_part3:2;
    };
}rl_popar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ref_rangeredfrm:1;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  lu_addr_index:7;
        RBus_UInt32  ch_addr_index:7;
    };
}rl_l0refdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ref_rangeredfrm:1;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  lu_addr_index:7;
        RBus_UInt32  ch_addr_index:7;
    };
}rl_l1refdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  trigger_status:1;
        RBus_UInt32  zero_w_lr:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  trigger_select:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  trigger_cond_mb_x:9;
        RBus_UInt32  trigger_cond_mb_y:8;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  debug_port_sel:3;
    };
}rl_dbg_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbl_cnt:16;
        RBus_UInt32  trigger_tbl_cnt:16;
    };
}rl_dbg_sts0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sts:32;
    };
}rl_dbg_sts1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sts:32;
    };
}rl_dbg_sts2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  intr:1;
        RBus_UInt32  value:28;
    };
}rl_intr_thres_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  mvbuf_write_address:7;
    };
}rl_mvbuf_wadd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_read_write_data:32;
    };
}rl_mvbuf_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  mvbuf_read_address:7;
    };
}rl_mvbuf_radd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  mvbuf_hdr:10;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mvbuf_mvd_wptr:11;
    };
}rl_mvbuf_sts0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  mvbuf_pred_rptr:11;
        RBus_UInt32  write_enable11:1;
        RBus_UInt32  mvbuf_rl_rptr:11;
    };
}rl_mvbuf_sts1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  hdr_ref_pic_cnt:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  vg_en:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  ref_pic_cnt:2;
    };
}rl_cache_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  hdr_cah_en:1;
        RBus_UInt32  cah_en:1;
    };
}rl_cache_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  hdr_cah_inv:1;
        RBus_UInt32  cah_inv:1;
    };
}rl_cache_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cah_pindx0_luml0:8;
        RBus_UInt32  cah_pindx1_luml1:8;
        RBus_UInt32  cah_pindx2_chrl0:8;
        RBus_UInt32  cah_pindx3_chrl1:8;
    };
}rl_cah_pindx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_cah_pindx_lum0:8;
        RBus_UInt32  ext_cah_pindx_lum1:8;
        RBus_UInt32  ext_cah_pindx_lum2:8;
        RBus_UInt32  ext_cah_pindx_lum3:8;
    };
}rl_hdr_cah_pindx_ext_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_cah_pindx_chr0:8;
        RBus_UInt32  ext_cah_pindx_chr1:8;
        RBus_UInt32  ext_cah_pindx_chr2:8;
        RBus_UInt32  ext_cah_pindx_chr3:8;
    };
}rl_hdr_cah_pindx_ext_chroma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disppic_h:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  disppic_w:14;
    };
}rl_scale_pic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_str_addr_lu:32;
    };
}rl_hdr_str_addr_lu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_str_addr_ch:32;
    };
}rl_hdr_str_addr_ch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  hdr_map_idx_0:7;
        RBus_UInt32  hdr_map_idx_1:7;
        RBus_UInt32  hdr_map_idx_2:7;
        RBus_UInt32  hdr_map_idx_3:7;
    };
}rl_hdr_map_idx_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  hdr_map_idx_4:7;
        RBus_UInt32  hdr_map_idx_5:7;
        RBus_UInt32  hdr_map_idx_6:7;
        RBus_UInt32  hdr_map_idx_7:7;
    };
}rl_hdr_map_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  hdr_map_idx_8:7;
        RBus_UInt32  hdr_map_idx_9:7;
        RBus_UInt32  hdr_map_idx_10:7;
        RBus_UInt32  hdr_map_idx_11:7;
    };
}rl_hdr_map_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  hdr_map_idx_12:7;
        RBus_UInt32  hdr_map_idx_13:7;
        RBus_UInt32  hdr_map_idx_14:7;
        RBus_UInt32  hdr_map_idx_15:7;
    };
}rl_hdr_map_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  hdr_map_idx_16:7;
        RBus_UInt32  hdr_map_idx_17:7;
        RBus_UInt32  hdr_map_idx_18:7;
        RBus_UInt32  hdr_map_idx_19:7;
    };
}rl_hdr_map_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_flag2irq_en_3:8;
        RBus_UInt32  core_flag2irq_en_2:8;
        RBus_UInt32  core_flag2irq_en_1:8;
        RBus_UInt32  core_flag2irq_en_0:8;
    };
}rl_dcmprs_core_flag_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_errflag_clr_3:8;
        RBus_UInt32  core_errflag_clr_2:8;
        RBus_UInt32  core_errflag_clr_1:8;
        RBus_UInt32  core_errflag_clr_0:8;
    };
}rl_dcmprs_core_flag_clr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_errflag_ro_3:8;
        RBus_UInt32  core_errflag_ro_2:8;
        RBus_UInt32  core_errflag_ro_1:8;
        RBus_UInt32  core_errflag_ro_0:8;
    };
}rl_dcmprs_core_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:28;
        RBus_UInt32  core_errflag_irq_3:1;
        RBus_UInt32  core_errflag_irq_2:1;
        RBus_UInt32  core_errflag_irq_1:1;
        RBus_UInt32  core_errflag_irq_0:1;
    };
}rl_dcmprs_core_flag_irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:2;
        RBus_UInt32  wrap_width_2:10;
        RBus_UInt32  wrap_width_1:10;
        RBus_UInt32  wrap_width_0:10;
    };
}rl_dcmprs_wrap_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_out1:16;
        RBus_UInt32  debug_out0:16;
    };
}rl_dcmprs_dbg_out_RBUS;

#else //apply LITTLE_ENDIAN

//======RL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_rangeredfrm:1;
        RBus_UInt32  disppic_w:14;
        RBus_UInt32  res1:1;
        RBus_UInt32  disppic_h:13;
        RBus_UInt32  res2:3;
    };
}rl_rlcntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_threshold:6;
        RBus_UInt32  manual_thresh_ena:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  ldmc_enable:1;
        RBus_UInt32  pred_enable:1;
        RBus_UInt32  ldmc_bypass:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  rmem_wptr_rst:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:18;
    };
}rl_rlcntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_mb_y:9;
        RBus_UInt32  cur_mb_x:9;
        RBus_UInt32  first_mb:1;
        RBus_UInt32  pictype:3;
        RBus_UInt32  hevc_log2cbsize_minus3:2;
        RBus_UInt32  hevc_zidx:8;
    };
}rl_ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_partition:9;
        RBus_UInt32  mb_field_decoding_flag:1;
        RBus_UInt32  dummyrowctb:1;
        RBus_UInt32  dummycolctb:1;
        RBus_UInt32  paddingcu:1;
        RBus_UInt32  res1:19;
    };
}rl_h264ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  overflag:1;
        RBus_UInt32  fieldtx:1;
        RBus_UInt32  mvtype:2;
        RBus_UInt32  submb_partition:12;
        RBus_UInt32  intra_flag:5;
        RBus_UInt32  intramb_flag:1;
        RBus_UInt32  res1:10;
    };
}rl_vc1ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inter_predict_part3:2;
        RBus_UInt32  inter_predict_part2:2;
        RBus_UInt32  inter_predict_part1:2;
        RBus_UInt32  inter_predict_part0:2;
        RBus_UInt32  chroma_predict_part3:2;
        RBus_UInt32  chroma_predict_part2:2;
        RBus_UInt32  chroma_predict_part1:2;
        RBus_UInt32  chroma_predict_part0:2;
        RBus_UInt32  res1:16;
    };
}rl_popar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_addr_index:7;
        RBus_UInt32  lu_addr_index:7;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  ref_rangeredfrm:1;
        RBus_UInt32  res1:16;
    };
}rl_l0refdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_addr_index:7;
        RBus_UInt32  lu_addr_index:7;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  ref_rangeredfrm:1;
        RBus_UInt32  res1:16;
    };
}rl_l1refdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_port_sel:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  trigger_cond_mb_y:8;
        RBus_UInt32  trigger_cond_mb_x:9;
        RBus_UInt32  res1:2;
        RBus_UInt32  trigger_select:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  zero_w_lr:2;
        RBus_UInt32  trigger_status:1;
        RBus_UInt32  write_enable3:1;
    };
}rl_dbg_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trigger_tbl_cnt:16;
        RBus_UInt32  tbl_cnt:16;
    };
}rl_dbg_sts0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sts:32;
    };
}rl_dbg_sts1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sts:32;
    };
}rl_dbg_sts2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:28;
        RBus_UInt32  intr:1;
        RBus_UInt32  res1:3;
    };
}rl_intr_thres_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_write_address:7;
        RBus_UInt32  res1:25;
    };
}rl_mvbuf_wadd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_read_write_data:32;
    };
}rl_mvbuf_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_read_address:7;
        RBus_UInt32  res1:25;
    };
}rl_mvbuf_radd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_mvd_wptr:11;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mvbuf_hdr:10;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  res1:9;
    };
}rl_mvbuf_sts0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_rl_rptr:11;
        RBus_UInt32  write_enable11:1;
        RBus_UInt32  mvbuf_pred_rptr:11;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  res1:8;
    };
}rl_mvbuf_sts1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ref_pic_cnt:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  vg_en:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  hdr_ref_pic_cnt:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:24;
    };
}rl_cache_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cah_en:1;
        RBus_UInt32  hdr_cah_en:1;
        RBus_UInt32  res1:30;
    };
}rl_cache_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cah_inv:1;
        RBus_UInt32  hdr_cah_inv:1;
        RBus_UInt32  res1:30;
    };
}rl_cache_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cah_pindx3_chrl1:8;
        RBus_UInt32  cah_pindx2_chrl0:8;
        RBus_UInt32  cah_pindx1_luml1:8;
        RBus_UInt32  cah_pindx0_luml0:8;
    };
}rl_cah_pindx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_cah_pindx_lum3:8;
        RBus_UInt32  ext_cah_pindx_lum2:8;
        RBus_UInt32  ext_cah_pindx_lum1:8;
        RBus_UInt32  ext_cah_pindx_lum0:8;
    };
}rl_hdr_cah_pindx_ext_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_cah_pindx_chr3:8;
        RBus_UInt32  ext_cah_pindx_chr2:8;
        RBus_UInt32  ext_cah_pindx_chr1:8;
        RBus_UInt32  ext_cah_pindx_chr0:8;
    };
}rl_hdr_cah_pindx_ext_chroma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disppic_w:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  disppic_h:13;
        RBus_UInt32  res2:3;
    };
}rl_scale_pic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_str_addr_lu:32;
    };
}rl_hdr_str_addr_lu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_str_addr_ch:32;
    };
}rl_hdr_str_addr_ch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_map_idx_3:7;
        RBus_UInt32  hdr_map_idx_2:7;
        RBus_UInt32  hdr_map_idx_1:7;
        RBus_UInt32  hdr_map_idx_0:7;
        RBus_UInt32  dmy:4;
    };
}rl_hdr_map_idx_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_map_idx_7:7;
        RBus_UInt32  hdr_map_idx_6:7;
        RBus_UInt32  hdr_map_idx_5:7;
        RBus_UInt32  hdr_map_idx_4:7;
        RBus_UInt32  dmy:4;
    };
}rl_hdr_map_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_map_idx_11:7;
        RBus_UInt32  hdr_map_idx_10:7;
        RBus_UInt32  hdr_map_idx_9:7;
        RBus_UInt32  hdr_map_idx_8:7;
        RBus_UInt32  dmy:4;
    };
}rl_hdr_map_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_map_idx_15:7;
        RBus_UInt32  hdr_map_idx_14:7;
        RBus_UInt32  hdr_map_idx_13:7;
        RBus_UInt32  hdr_map_idx_12:7;
        RBus_UInt32  dmy:4;
    };
}rl_hdr_map_idx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_map_idx_19:7;
        RBus_UInt32  hdr_map_idx_18:7;
        RBus_UInt32  hdr_map_idx_17:7;
        RBus_UInt32  hdr_map_idx_16:7;
        RBus_UInt32  dmy:4;
    };
}rl_hdr_map_idx_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_flag2irq_en_0:8;
        RBus_UInt32  core_flag2irq_en_1:8;
        RBus_UInt32  core_flag2irq_en_2:8;
        RBus_UInt32  core_flag2irq_en_3:8;
    };
}rl_dcmprs_core_flag_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_errflag_clr_0:8;
        RBus_UInt32  core_errflag_clr_1:8;
        RBus_UInt32  core_errflag_clr_2:8;
        RBus_UInt32  core_errflag_clr_3:8;
    };
}rl_dcmprs_core_flag_clr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_errflag_ro_0:8;
        RBus_UInt32  core_errflag_ro_1:8;
        RBus_UInt32  core_errflag_ro_2:8;
        RBus_UInt32  core_errflag_ro_3:8;
    };
}rl_dcmprs_core_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_errflag_irq_0:1;
        RBus_UInt32  core_errflag_irq_1:1;
        RBus_UInt32  core_errflag_irq_2:1;
        RBus_UInt32  core_errflag_irq_3:1;
        RBus_UInt32  dmy:28;
    };
}rl_dcmprs_core_flag_irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_width_0:10;
        RBus_UInt32  wrap_width_1:10;
        RBus_UInt32  wrap_width_2:10;
        RBus_UInt32  dmy:2;
    };
}rl_dcmprs_wrap_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_out0:16;
        RBus_UInt32  debug_out1:16;
    };
}rl_dcmprs_dbg_out_RBUS;




#endif 


#endif 
