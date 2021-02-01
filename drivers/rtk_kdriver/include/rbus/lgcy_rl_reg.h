/**
* @file Mac5_LGCY_VE_RL_Arch_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGCY_RL_REG_H_
#define _RBUS_LGCY_RL_REG_H_

#include "rbus_types.h"



//  LGCY_RL Register Address
#define  LGCY_RL_RLCNTL                                                          0x1800EC00
#define  LGCY_RL_RLCNTL_reg_addr                                                 "0xB800EC00"
#define  LGCY_RL_RLCNTL_reg                                                      0xB800EC00
#define  LGCY_RL_RLCNTL_inst_addr                                                "0x0000"
#define  set_LGCY_RL_RLCNTL_reg(data)                                            (*((volatile unsigned int*)LGCY_RL_RLCNTL_reg)=data)
#define  get_LGCY_RL_RLCNTL_reg                                                  (*((volatile unsigned int*)LGCY_RL_RLCNTL_reg))
#define  LGCY_RL_RLCNTL_disppic_h_shift                                          (16)
#define  LGCY_RL_RLCNTL_disppic_w_shift                                          (1)
#define  LGCY_RL_RLCNTL_cur_rangeredfrm_shift                                    (0)
#define  LGCY_RL_RLCNTL_disppic_h_mask                                           (0x1FFF0000)
#define  LGCY_RL_RLCNTL_disppic_w_mask                                           (0x00007FFE)
#define  LGCY_RL_RLCNTL_cur_rangeredfrm_mask                                     (0x00000001)
#define  LGCY_RL_RLCNTL_disppic_h(data)                                          (0x1FFF0000&((data)<<16))
#define  LGCY_RL_RLCNTL_disppic_w(data)                                          (0x00007FFE&((data)<<1))
#define  LGCY_RL_RLCNTL_cur_rangeredfrm(data)                                    (0x00000001&(data))
#define  LGCY_RL_RLCNTL_get_disppic_h(data)                                      ((0x1FFF0000&(data))>>16)
#define  LGCY_RL_RLCNTL_get_disppic_w(data)                                      ((0x00007FFE&(data))>>1)
#define  LGCY_RL_RLCNTL_get_cur_rangeredfrm(data)                                (0x00000001&(data))

#define  LGCY_RL_RLCNTL2                                                         0x1800EC04
#define  LGCY_RL_RLCNTL2_reg_addr                                                "0xB800EC04"
#define  LGCY_RL_RLCNTL2_reg                                                     0xB800EC04
#define  LGCY_RL_RLCNTL2_inst_addr                                               "0x0001"
#define  set_LGCY_RL_RLCNTL2_reg(data)                                           (*((volatile unsigned int*)LGCY_RL_RLCNTL2_reg)=data)
#define  get_LGCY_RL_RLCNTL2_reg                                                 (*((volatile unsigned int*)LGCY_RL_RLCNTL2_reg))
#define  LGCY_RL_RLCNTL2_write_enable3_shift                                     (13)
#define  LGCY_RL_RLCNTL2_rmem_wptr_rst_shift                                     (12)
#define  LGCY_RL_RLCNTL2_write_enable2_shift                                     (11)
#define  LGCY_RL_RLCNTL2_ldmc_bypass_shift                                       (10)
#define  LGCY_RL_RLCNTL2_pred_enable_shift                                       (9)
#define  LGCY_RL_RLCNTL2_ldmc_enable_shift                                       (8)
#define  LGCY_RL_RLCNTL2_write_enable1_shift                                     (7)
#define  LGCY_RL_RLCNTL2_manual_thresh_ena_shift                                 (6)
#define  LGCY_RL_RLCNTL2_rm_threshold_shift                                      (0)
#define  LGCY_RL_RLCNTL2_write_enable3_mask                                      (0x00002000)
#define  LGCY_RL_RLCNTL2_rmem_wptr_rst_mask                                      (0x00001000)
#define  LGCY_RL_RLCNTL2_write_enable2_mask                                      (0x00000800)
#define  LGCY_RL_RLCNTL2_ldmc_bypass_mask                                        (0x00000400)
#define  LGCY_RL_RLCNTL2_pred_enable_mask                                        (0x00000200)
#define  LGCY_RL_RLCNTL2_ldmc_enable_mask                                        (0x00000100)
#define  LGCY_RL_RLCNTL2_write_enable1_mask                                      (0x00000080)
#define  LGCY_RL_RLCNTL2_manual_thresh_ena_mask                                  (0x00000040)
#define  LGCY_RL_RLCNTL2_rm_threshold_mask                                       (0x0000003F)
#define  LGCY_RL_RLCNTL2_write_enable3(data)                                     (0x00002000&((data)<<13))
#define  LGCY_RL_RLCNTL2_rmem_wptr_rst(data)                                     (0x00001000&((data)<<12))
#define  LGCY_RL_RLCNTL2_write_enable2(data)                                     (0x00000800&((data)<<11))
#define  LGCY_RL_RLCNTL2_ldmc_bypass(data)                                       (0x00000400&((data)<<10))
#define  LGCY_RL_RLCNTL2_pred_enable(data)                                       (0x00000200&((data)<<9))
#define  LGCY_RL_RLCNTL2_ldmc_enable(data)                                       (0x00000100&((data)<<8))
#define  LGCY_RL_RLCNTL2_write_enable1(data)                                     (0x00000080&((data)<<7))
#define  LGCY_RL_RLCNTL2_manual_thresh_ena(data)                                 (0x00000040&((data)<<6))
#define  LGCY_RL_RLCNTL2_rm_threshold(data)                                      (0x0000003F&(data))
#define  LGCY_RL_RLCNTL2_get_write_enable3(data)                                 ((0x00002000&(data))>>13)
#define  LGCY_RL_RLCNTL2_get_rmem_wptr_rst(data)                                 ((0x00001000&(data))>>12)
#define  LGCY_RL_RLCNTL2_get_write_enable2(data)                                 ((0x00000800&(data))>>11)
#define  LGCY_RL_RLCNTL2_get_ldmc_bypass(data)                                   ((0x00000400&(data))>>10)
#define  LGCY_RL_RLCNTL2_get_pred_enable(data)                                   ((0x00000200&(data))>>9)
#define  LGCY_RL_RLCNTL2_get_ldmc_enable(data)                                   ((0x00000100&(data))>>8)
#define  LGCY_RL_RLCNTL2_get_write_enable1(data)                                 ((0x00000080&(data))>>7)
#define  LGCY_RL_RLCNTL2_get_manual_thresh_ena(data)                             ((0x00000040&(data))>>6)
#define  LGCY_RL_RLCNTL2_get_rm_threshold(data)                                  (0x0000003F&(data))

#define  LGCY_RL_CCPAR                                                           0x1800EC08
#define  LGCY_RL_CCPAR_reg_addr                                                  "0xB800EC08"
#define  LGCY_RL_CCPAR_reg                                                       0xB800EC08
#define  LGCY_RL_CCPAR_inst_addr                                                 "0x0002"
#define  set_LGCY_RL_CCPAR_reg(data)                                             (*((volatile unsigned int*)LGCY_RL_CCPAR_reg)=data)
#define  get_LGCY_RL_CCPAR_reg                                                   (*((volatile unsigned int*)LGCY_RL_CCPAR_reg))
#define  LGCY_RL_CCPAR_hevc_zidx_shift                                           (24)
#define  LGCY_RL_CCPAR_hevc_log2cbsize_minus3_shift                              (22)
#define  LGCY_RL_CCPAR_pictype_shift                                             (19)
#define  LGCY_RL_CCPAR_first_mb_shift                                            (18)
#define  LGCY_RL_CCPAR_cur_mb_x_shift                                            (9)
#define  LGCY_RL_CCPAR_cur_mb_y_shift                                            (0)
#define  LGCY_RL_CCPAR_hevc_zidx_mask                                            (0xFF000000)
#define  LGCY_RL_CCPAR_hevc_log2cbsize_minus3_mask                               (0x00C00000)
#define  LGCY_RL_CCPAR_pictype_mask                                              (0x00380000)
#define  LGCY_RL_CCPAR_first_mb_mask                                             (0x00040000)
#define  LGCY_RL_CCPAR_cur_mb_x_mask                                             (0x0003FE00)
#define  LGCY_RL_CCPAR_cur_mb_y_mask                                             (0x000001FF)
#define  LGCY_RL_CCPAR_hevc_zidx(data)                                           (0xFF000000&((data)<<24))
#define  LGCY_RL_CCPAR_hevc_log2cbsize_minus3(data)                              (0x00C00000&((data)<<22))
#define  LGCY_RL_CCPAR_pictype(data)                                             (0x00380000&((data)<<19))
#define  LGCY_RL_CCPAR_first_mb(data)                                            (0x00040000&((data)<<18))
#define  LGCY_RL_CCPAR_cur_mb_x(data)                                            (0x0003FE00&((data)<<9))
#define  LGCY_RL_CCPAR_cur_mb_y(data)                                            (0x000001FF&(data))
#define  LGCY_RL_CCPAR_get_hevc_zidx(data)                                       ((0xFF000000&(data))>>24)
#define  LGCY_RL_CCPAR_get_hevc_log2cbsize_minus3(data)                          ((0x00C00000&(data))>>22)
#define  LGCY_RL_CCPAR_get_pictype(data)                                         ((0x00380000&(data))>>19)
#define  LGCY_RL_CCPAR_get_first_mb(data)                                        ((0x00040000&(data))>>18)
#define  LGCY_RL_CCPAR_get_cur_mb_x(data)                                        ((0x0003FE00&(data))>>9)
#define  LGCY_RL_CCPAR_get_cur_mb_y(data)                                        (0x000001FF&(data))

#define  LGCY_RL_H264CCPAR                                                       0x1800EC0C
#define  LGCY_RL_H264CCPAR_reg_addr                                              "0xB800EC0C"
#define  LGCY_RL_H264CCPAR_reg                                                   0xB800EC0C
#define  LGCY_RL_H264CCPAR_inst_addr                                             "0x0003"
#define  set_LGCY_RL_H264CCPAR_reg(data)                                         (*((volatile unsigned int*)LGCY_RL_H264CCPAR_reg)=data)
#define  get_LGCY_RL_H264CCPAR_reg                                               (*((volatile unsigned int*)LGCY_RL_H264CCPAR_reg))
#define  LGCY_RL_H264CCPAR_paddingcu_shift                                       (12)
#define  LGCY_RL_H264CCPAR_dummycolctb_shift                                     (11)
#define  LGCY_RL_H264CCPAR_dummyrowctb_shift                                     (10)
#define  LGCY_RL_H264CCPAR_mb_field_decoding_flag_shift                          (9)
#define  LGCY_RL_H264CCPAR_mb_partition_shift                                    (0)
#define  LGCY_RL_H264CCPAR_paddingcu_mask                                        (0x00001000)
#define  LGCY_RL_H264CCPAR_dummycolctb_mask                                      (0x00000800)
#define  LGCY_RL_H264CCPAR_dummyrowctb_mask                                      (0x00000400)
#define  LGCY_RL_H264CCPAR_mb_field_decoding_flag_mask                           (0x00000200)
#define  LGCY_RL_H264CCPAR_mb_partition_mask                                     (0x000001FF)
#define  LGCY_RL_H264CCPAR_paddingcu(data)                                       (0x00001000&((data)<<12))
#define  LGCY_RL_H264CCPAR_dummycolctb(data)                                     (0x00000800&((data)<<11))
#define  LGCY_RL_H264CCPAR_dummyrowctb(data)                                     (0x00000400&((data)<<10))
#define  LGCY_RL_H264CCPAR_mb_field_decoding_flag(data)                          (0x00000200&((data)<<9))
#define  LGCY_RL_H264CCPAR_mb_partition(data)                                    (0x000001FF&(data))
#define  LGCY_RL_H264CCPAR_get_paddingcu(data)                                   ((0x00001000&(data))>>12)
#define  LGCY_RL_H264CCPAR_get_dummycolctb(data)                                 ((0x00000800&(data))>>11)
#define  LGCY_RL_H264CCPAR_get_dummyrowctb(data)                                 ((0x00000400&(data))>>10)
#define  LGCY_RL_H264CCPAR_get_mb_field_decoding_flag(data)                      ((0x00000200&(data))>>9)
#define  LGCY_RL_H264CCPAR_get_mb_partition(data)                                (0x000001FF&(data))

#define  LGCY_RL_VC1CCPAR                                                        0x1800EC10
#define  LGCY_RL_VC1CCPAR_reg_addr                                               "0xB800EC10"
#define  LGCY_RL_VC1CCPAR_reg                                                    0xB800EC10
#define  LGCY_RL_VC1CCPAR_inst_addr                                              "0x0004"
#define  set_LGCY_RL_VC1CCPAR_reg(data)                                          (*((volatile unsigned int*)LGCY_RL_VC1CCPAR_reg)=data)
#define  get_LGCY_RL_VC1CCPAR_reg                                                (*((volatile unsigned int*)LGCY_RL_VC1CCPAR_reg))
#define  LGCY_RL_VC1CCPAR_intramb_flag_shift                                     (21)
#define  LGCY_RL_VC1CCPAR_intra_flag_shift                                       (16)
#define  LGCY_RL_VC1CCPAR_submb_partition_shift                                  (4)
#define  LGCY_RL_VC1CCPAR_mvtype_shift                                           (2)
#define  LGCY_RL_VC1CCPAR_fieldtx_shift                                          (1)
#define  LGCY_RL_VC1CCPAR_overflag_shift                                         (0)
#define  LGCY_RL_VC1CCPAR_intramb_flag_mask                                      (0x00200000)
#define  LGCY_RL_VC1CCPAR_intra_flag_mask                                        (0x001F0000)
#define  LGCY_RL_VC1CCPAR_submb_partition_mask                                   (0x0000FFF0)
#define  LGCY_RL_VC1CCPAR_mvtype_mask                                            (0x0000000C)
#define  LGCY_RL_VC1CCPAR_fieldtx_mask                                           (0x00000002)
#define  LGCY_RL_VC1CCPAR_overflag_mask                                          (0x00000001)
#define  LGCY_RL_VC1CCPAR_intramb_flag(data)                                     (0x00200000&((data)<<21))
#define  LGCY_RL_VC1CCPAR_intra_flag(data)                                       (0x001F0000&((data)<<16))
#define  LGCY_RL_VC1CCPAR_submb_partition(data)                                  (0x0000FFF0&((data)<<4))
#define  LGCY_RL_VC1CCPAR_mvtype(data)                                           (0x0000000C&((data)<<2))
#define  LGCY_RL_VC1CCPAR_fieldtx(data)                                          (0x00000002&((data)<<1))
#define  LGCY_RL_VC1CCPAR_overflag(data)                                         (0x00000001&(data))
#define  LGCY_RL_VC1CCPAR_get_intramb_flag(data)                                 ((0x00200000&(data))>>21)
#define  LGCY_RL_VC1CCPAR_get_intra_flag(data)                                   ((0x001F0000&(data))>>16)
#define  LGCY_RL_VC1CCPAR_get_submb_partition(data)                              ((0x0000FFF0&(data))>>4)
#define  LGCY_RL_VC1CCPAR_get_mvtype(data)                                       ((0x0000000C&(data))>>2)
#define  LGCY_RL_VC1CCPAR_get_fieldtx(data)                                      ((0x00000002&(data))>>1)
#define  LGCY_RL_VC1CCPAR_get_overflag(data)                                     (0x00000001&(data))

#define  LGCY_RL_POPAR                                                           0x1800EC14
#define  LGCY_RL_POPAR_reg_addr                                                  "0xB800EC14"
#define  LGCY_RL_POPAR_reg                                                       0xB800EC14
#define  LGCY_RL_POPAR_inst_addr                                                 "0x0005"
#define  set_LGCY_RL_POPAR_reg(data)                                             (*((volatile unsigned int*)LGCY_RL_POPAR_reg)=data)
#define  get_LGCY_RL_POPAR_reg                                                   (*((volatile unsigned int*)LGCY_RL_POPAR_reg))
#define  LGCY_RL_POPAR_chroma_predict_part0_shift                                (14)
#define  LGCY_RL_POPAR_chroma_predict_part1_shift                                (12)
#define  LGCY_RL_POPAR_chroma_predict_part2_shift                                (10)
#define  LGCY_RL_POPAR_chroma_predict_part3_shift                                (8)
#define  LGCY_RL_POPAR_inter_predict_part0_shift                                 (6)
#define  LGCY_RL_POPAR_inter_predict_part1_shift                                 (4)
#define  LGCY_RL_POPAR_inter_predict_part2_shift                                 (2)
#define  LGCY_RL_POPAR_inter_predict_part3_shift                                 (0)
#define  LGCY_RL_POPAR_chroma_predict_part0_mask                                 (0x0000C000)
#define  LGCY_RL_POPAR_chroma_predict_part1_mask                                 (0x00003000)
#define  LGCY_RL_POPAR_chroma_predict_part2_mask                                 (0x00000C00)
#define  LGCY_RL_POPAR_chroma_predict_part3_mask                                 (0x00000300)
#define  LGCY_RL_POPAR_inter_predict_part0_mask                                  (0x000000C0)
#define  LGCY_RL_POPAR_inter_predict_part1_mask                                  (0x00000030)
#define  LGCY_RL_POPAR_inter_predict_part2_mask                                  (0x0000000C)
#define  LGCY_RL_POPAR_inter_predict_part3_mask                                  (0x00000003)
#define  LGCY_RL_POPAR_chroma_predict_part0(data)                                (0x0000C000&((data)<<14))
#define  LGCY_RL_POPAR_chroma_predict_part1(data)                                (0x00003000&((data)<<12))
#define  LGCY_RL_POPAR_chroma_predict_part2(data)                                (0x00000C00&((data)<<10))
#define  LGCY_RL_POPAR_chroma_predict_part3(data)                                (0x00000300&((data)<<8))
#define  LGCY_RL_POPAR_inter_predict_part0(data)                                 (0x000000C0&((data)<<6))
#define  LGCY_RL_POPAR_inter_predict_part1(data)                                 (0x00000030&((data)<<4))
#define  LGCY_RL_POPAR_inter_predict_part2(data)                                 (0x0000000C&((data)<<2))
#define  LGCY_RL_POPAR_inter_predict_part3(data)                                 (0x00000003&(data))
#define  LGCY_RL_POPAR_get_chroma_predict_part0(data)                            ((0x0000C000&(data))>>14)
#define  LGCY_RL_POPAR_get_chroma_predict_part1(data)                            ((0x00003000&(data))>>12)
#define  LGCY_RL_POPAR_get_chroma_predict_part2(data)                            ((0x00000C00&(data))>>10)
#define  LGCY_RL_POPAR_get_chroma_predict_part3(data)                            ((0x00000300&(data))>>8)
#define  LGCY_RL_POPAR_get_inter_predict_part0(data)                             ((0x000000C0&(data))>>6)
#define  LGCY_RL_POPAR_get_inter_predict_part1(data)                             ((0x00000030&(data))>>4)
#define  LGCY_RL_POPAR_get_inter_predict_part2(data)                             ((0x0000000C&(data))>>2)
#define  LGCY_RL_POPAR_get_inter_predict_part3(data)                             (0x00000003&(data))

#define  LGCY_RL_L0REFDMA_0                                                      0x1800E500
#define  LGCY_RL_L0REFDMA_0_reg_addr                                             "0xB800E500"
#define  LGCY_RL_L0REFDMA_0_reg                                                  0xB800E500
#define  LGCY_RL_L0REFDMA_0_inst_addr                                            "0x0006"
#define  set_LGCY_RL_L0REFDMA_0_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_0_reg)=data)
#define  get_LGCY_RL_L0REFDMA_0_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_0_reg))
#define  LGCY_RL_L0REFDMA_0_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_0_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_0_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_0_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_0_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_0_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_0_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_0_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_0_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_0_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_0_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_0_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_0_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_0_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_0_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_0_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_1                                                      0x1800E504
#define  LGCY_RL_L0REFDMA_1_reg_addr                                             "0xB800E504"
#define  LGCY_RL_L0REFDMA_1_reg                                                  0xB800E504
#define  LGCY_RL_L0REFDMA_1_inst_addr                                            "0x0007"
#define  set_LGCY_RL_L0REFDMA_1_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_1_reg)=data)
#define  get_LGCY_RL_L0REFDMA_1_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_1_reg))
#define  LGCY_RL_L0REFDMA_1_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_1_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_1_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_1_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_1_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_1_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_1_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_1_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_1_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_1_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_1_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_1_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_1_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_1_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_1_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_1_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_2                                                      0x1800E508
#define  LGCY_RL_L0REFDMA_2_reg_addr                                             "0xB800E508"
#define  LGCY_RL_L0REFDMA_2_reg                                                  0xB800E508
#define  LGCY_RL_L0REFDMA_2_inst_addr                                            "0x0008"
#define  set_LGCY_RL_L0REFDMA_2_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_2_reg)=data)
#define  get_LGCY_RL_L0REFDMA_2_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_2_reg))
#define  LGCY_RL_L0REFDMA_2_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_2_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_2_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_2_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_2_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_2_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_2_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_2_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_2_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_2_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_2_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_2_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_2_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_2_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_2_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_2_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_3                                                      0x1800E50C
#define  LGCY_RL_L0REFDMA_3_reg_addr                                             "0xB800E50C"
#define  LGCY_RL_L0REFDMA_3_reg                                                  0xB800E50C
#define  LGCY_RL_L0REFDMA_3_inst_addr                                            "0x0009"
#define  set_LGCY_RL_L0REFDMA_3_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_3_reg)=data)
#define  get_LGCY_RL_L0REFDMA_3_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_3_reg))
#define  LGCY_RL_L0REFDMA_3_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_3_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_3_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_3_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_3_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_3_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_3_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_3_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_3_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_3_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_3_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_3_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_3_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_3_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_3_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_3_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_4                                                      0x1800E510
#define  LGCY_RL_L0REFDMA_4_reg_addr                                             "0xB800E510"
#define  LGCY_RL_L0REFDMA_4_reg                                                  0xB800E510
#define  LGCY_RL_L0REFDMA_4_inst_addr                                            "0x000A"
#define  set_LGCY_RL_L0REFDMA_4_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_4_reg)=data)
#define  get_LGCY_RL_L0REFDMA_4_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_4_reg))
#define  LGCY_RL_L0REFDMA_4_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_4_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_4_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_4_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_4_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_4_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_4_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_4_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_4_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_4_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_4_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_4_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_4_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_4_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_4_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_4_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_5                                                      0x1800E514
#define  LGCY_RL_L0REFDMA_5_reg_addr                                             "0xB800E514"
#define  LGCY_RL_L0REFDMA_5_reg                                                  0xB800E514
#define  LGCY_RL_L0REFDMA_5_inst_addr                                            "0x000B"
#define  set_LGCY_RL_L0REFDMA_5_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_5_reg)=data)
#define  get_LGCY_RL_L0REFDMA_5_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_5_reg))
#define  LGCY_RL_L0REFDMA_5_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_5_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_5_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_5_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_5_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_5_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_5_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_5_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_5_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_5_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_5_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_5_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_5_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_5_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_5_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_5_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_6                                                      0x1800E518
#define  LGCY_RL_L0REFDMA_6_reg_addr                                             "0xB800E518"
#define  LGCY_RL_L0REFDMA_6_reg                                                  0xB800E518
#define  LGCY_RL_L0REFDMA_6_inst_addr                                            "0x000C"
#define  set_LGCY_RL_L0REFDMA_6_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_6_reg)=data)
#define  get_LGCY_RL_L0REFDMA_6_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_6_reg))
#define  LGCY_RL_L0REFDMA_6_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_6_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_6_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_6_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_6_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_6_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_6_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_6_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_6_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_6_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_6_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_6_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_6_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_6_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_6_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_6_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_7                                                      0x1800E51C
#define  LGCY_RL_L0REFDMA_7_reg_addr                                             "0xB800E51C"
#define  LGCY_RL_L0REFDMA_7_reg                                                  0xB800E51C
#define  LGCY_RL_L0REFDMA_7_inst_addr                                            "0x000D"
#define  set_LGCY_RL_L0REFDMA_7_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_7_reg)=data)
#define  get_LGCY_RL_L0REFDMA_7_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_7_reg))
#define  LGCY_RL_L0REFDMA_7_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_7_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_7_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_7_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_7_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_7_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_7_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_7_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_7_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_7_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_7_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_7_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_7_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_7_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_7_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_7_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_8                                                      0x1800E520
#define  LGCY_RL_L0REFDMA_8_reg_addr                                             "0xB800E520"
#define  LGCY_RL_L0REFDMA_8_reg                                                  0xB800E520
#define  LGCY_RL_L0REFDMA_8_inst_addr                                            "0x000E"
#define  set_LGCY_RL_L0REFDMA_8_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_8_reg)=data)
#define  get_LGCY_RL_L0REFDMA_8_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_8_reg))
#define  LGCY_RL_L0REFDMA_8_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_8_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_8_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_8_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_8_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_8_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_8_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_8_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_8_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_8_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_8_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_8_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_8_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_8_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_8_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_8_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_9                                                      0x1800E524
#define  LGCY_RL_L0REFDMA_9_reg_addr                                             "0xB800E524"
#define  LGCY_RL_L0REFDMA_9_reg                                                  0xB800E524
#define  LGCY_RL_L0REFDMA_9_inst_addr                                            "0x000F"
#define  set_LGCY_RL_L0REFDMA_9_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L0REFDMA_9_reg)=data)
#define  get_LGCY_RL_L0REFDMA_9_reg                                              (*((volatile unsigned int*)LGCY_RL_L0REFDMA_9_reg))
#define  LGCY_RL_L0REFDMA_9_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L0REFDMA_9_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L0REFDMA_9_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L0REFDMA_9_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L0REFDMA_9_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L0REFDMA_9_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L0REFDMA_9_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L0REFDMA_9_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L0REFDMA_9_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_9_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_9_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_9_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_9_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_9_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_9_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_9_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_10                                                     0x1800E528
#define  LGCY_RL_L0REFDMA_10_reg_addr                                            "0xB800E528"
#define  LGCY_RL_L0REFDMA_10_reg                                                 0xB800E528
#define  LGCY_RL_L0REFDMA_10_inst_addr                                           "0x0010"
#define  set_LGCY_RL_L0REFDMA_10_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_10_reg)=data)
#define  get_LGCY_RL_L0REFDMA_10_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_10_reg))
#define  LGCY_RL_L0REFDMA_10_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_10_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_10_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_10_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_10_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_10_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_10_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_10_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_10_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_10_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_10_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_10_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_10_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_10_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_10_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_10_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_11                                                     0x1800E52C
#define  LGCY_RL_L0REFDMA_11_reg_addr                                            "0xB800E52C"
#define  LGCY_RL_L0REFDMA_11_reg                                                 0xB800E52C
#define  LGCY_RL_L0REFDMA_11_inst_addr                                           "0x0011"
#define  set_LGCY_RL_L0REFDMA_11_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_11_reg)=data)
#define  get_LGCY_RL_L0REFDMA_11_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_11_reg))
#define  LGCY_RL_L0REFDMA_11_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_11_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_11_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_11_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_11_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_11_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_11_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_11_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_11_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_11_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_11_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_11_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_11_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_11_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_11_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_11_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_12                                                     0x1800E530
#define  LGCY_RL_L0REFDMA_12_reg_addr                                            "0xB800E530"
#define  LGCY_RL_L0REFDMA_12_reg                                                 0xB800E530
#define  LGCY_RL_L0REFDMA_12_inst_addr                                           "0x0012"
#define  set_LGCY_RL_L0REFDMA_12_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_12_reg)=data)
#define  get_LGCY_RL_L0REFDMA_12_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_12_reg))
#define  LGCY_RL_L0REFDMA_12_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_12_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_12_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_12_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_12_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_12_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_12_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_12_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_12_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_12_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_12_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_12_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_12_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_12_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_12_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_12_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_13                                                     0x1800E534
#define  LGCY_RL_L0REFDMA_13_reg_addr                                            "0xB800E534"
#define  LGCY_RL_L0REFDMA_13_reg                                                 0xB800E534
#define  LGCY_RL_L0REFDMA_13_inst_addr                                           "0x0013"
#define  set_LGCY_RL_L0REFDMA_13_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_13_reg)=data)
#define  get_LGCY_RL_L0REFDMA_13_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_13_reg))
#define  LGCY_RL_L0REFDMA_13_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_13_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_13_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_13_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_13_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_13_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_13_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_13_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_13_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_13_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_13_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_13_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_13_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_13_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_13_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_13_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_14                                                     0x1800E538
#define  LGCY_RL_L0REFDMA_14_reg_addr                                            "0xB800E538"
#define  LGCY_RL_L0REFDMA_14_reg                                                 0xB800E538
#define  LGCY_RL_L0REFDMA_14_inst_addr                                           "0x0014"
#define  set_LGCY_RL_L0REFDMA_14_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_14_reg)=data)
#define  get_LGCY_RL_L0REFDMA_14_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_14_reg))
#define  LGCY_RL_L0REFDMA_14_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_14_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_14_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_14_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_14_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_14_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_14_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_14_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_14_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_14_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_14_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_14_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_14_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_14_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_14_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_14_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_15                                                     0x1800E53C
#define  LGCY_RL_L0REFDMA_15_reg_addr                                            "0xB800E53C"
#define  LGCY_RL_L0REFDMA_15_reg                                                 0xB800E53C
#define  LGCY_RL_L0REFDMA_15_inst_addr                                           "0x0015"
#define  set_LGCY_RL_L0REFDMA_15_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_15_reg)=data)
#define  get_LGCY_RL_L0REFDMA_15_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_15_reg))
#define  LGCY_RL_L0REFDMA_15_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_15_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_15_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_15_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_15_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_15_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_15_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_15_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_15_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_15_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_15_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_15_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_15_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_15_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_15_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_15_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_16                                                     0x1800E540
#define  LGCY_RL_L0REFDMA_16_reg_addr                                            "0xB800E540"
#define  LGCY_RL_L0REFDMA_16_reg                                                 0xB800E540
#define  LGCY_RL_L0REFDMA_16_inst_addr                                           "0x0016"
#define  set_LGCY_RL_L0REFDMA_16_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_16_reg)=data)
#define  get_LGCY_RL_L0REFDMA_16_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_16_reg))
#define  LGCY_RL_L0REFDMA_16_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_16_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_16_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_16_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_16_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_16_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_16_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_16_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_16_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_16_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_16_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_16_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_16_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_16_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_16_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_16_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_17                                                     0x1800E544
#define  LGCY_RL_L0REFDMA_17_reg_addr                                            "0xB800E544"
#define  LGCY_RL_L0REFDMA_17_reg                                                 0xB800E544
#define  LGCY_RL_L0REFDMA_17_inst_addr                                           "0x0017"
#define  set_LGCY_RL_L0REFDMA_17_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_17_reg)=data)
#define  get_LGCY_RL_L0REFDMA_17_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_17_reg))
#define  LGCY_RL_L0REFDMA_17_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_17_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_17_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_17_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_17_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_17_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_17_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_17_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_17_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_17_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_17_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_17_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_17_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_17_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_17_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_17_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_18                                                     0x1800E548
#define  LGCY_RL_L0REFDMA_18_reg_addr                                            "0xB800E548"
#define  LGCY_RL_L0REFDMA_18_reg                                                 0xB800E548
#define  LGCY_RL_L0REFDMA_18_inst_addr                                           "0x0018"
#define  set_LGCY_RL_L0REFDMA_18_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_18_reg)=data)
#define  get_LGCY_RL_L0REFDMA_18_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_18_reg))
#define  LGCY_RL_L0REFDMA_18_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_18_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_18_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_18_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_18_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_18_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_18_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_18_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_18_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_18_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_18_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_18_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_18_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_18_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_18_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_18_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_19                                                     0x1800E54C
#define  LGCY_RL_L0REFDMA_19_reg_addr                                            "0xB800E54C"
#define  LGCY_RL_L0REFDMA_19_reg                                                 0xB800E54C
#define  LGCY_RL_L0REFDMA_19_inst_addr                                           "0x0019"
#define  set_LGCY_RL_L0REFDMA_19_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_19_reg)=data)
#define  get_LGCY_RL_L0REFDMA_19_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_19_reg))
#define  LGCY_RL_L0REFDMA_19_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_19_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_19_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_19_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_19_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_19_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_19_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_19_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_19_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_19_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_19_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_19_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_19_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_19_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_19_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_19_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_20                                                     0x1800E550
#define  LGCY_RL_L0REFDMA_20_reg_addr                                            "0xB800E550"
#define  LGCY_RL_L0REFDMA_20_reg                                                 0xB800E550
#define  LGCY_RL_L0REFDMA_20_inst_addr                                           "0x001A"
#define  set_LGCY_RL_L0REFDMA_20_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_20_reg)=data)
#define  get_LGCY_RL_L0REFDMA_20_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_20_reg))
#define  LGCY_RL_L0REFDMA_20_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_20_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_20_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_20_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_20_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_20_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_20_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_20_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_20_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_20_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_20_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_20_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_20_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_20_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_20_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_20_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_21                                                     0x1800E554
#define  LGCY_RL_L0REFDMA_21_reg_addr                                            "0xB800E554"
#define  LGCY_RL_L0REFDMA_21_reg                                                 0xB800E554
#define  LGCY_RL_L0REFDMA_21_inst_addr                                           "0x001B"
#define  set_LGCY_RL_L0REFDMA_21_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_21_reg)=data)
#define  get_LGCY_RL_L0REFDMA_21_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_21_reg))
#define  LGCY_RL_L0REFDMA_21_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_21_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_21_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_21_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_21_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_21_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_21_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_21_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_21_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_21_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_21_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_21_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_21_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_21_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_21_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_21_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_22                                                     0x1800E558
#define  LGCY_RL_L0REFDMA_22_reg_addr                                            "0xB800E558"
#define  LGCY_RL_L0REFDMA_22_reg                                                 0xB800E558
#define  LGCY_RL_L0REFDMA_22_inst_addr                                           "0x001C"
#define  set_LGCY_RL_L0REFDMA_22_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_22_reg)=data)
#define  get_LGCY_RL_L0REFDMA_22_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_22_reg))
#define  LGCY_RL_L0REFDMA_22_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_22_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_22_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_22_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_22_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_22_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_22_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_22_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_22_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_22_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_22_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_22_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_22_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_22_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_22_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_22_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_23                                                     0x1800E55C
#define  LGCY_RL_L0REFDMA_23_reg_addr                                            "0xB800E55C"
#define  LGCY_RL_L0REFDMA_23_reg                                                 0xB800E55C
#define  LGCY_RL_L0REFDMA_23_inst_addr                                           "0x001D"
#define  set_LGCY_RL_L0REFDMA_23_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_23_reg)=data)
#define  get_LGCY_RL_L0REFDMA_23_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_23_reg))
#define  LGCY_RL_L0REFDMA_23_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_23_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_23_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_23_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_23_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_23_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_23_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_23_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_23_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_23_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_23_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_23_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_23_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_23_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_23_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_23_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_24                                                     0x1800E560
#define  LGCY_RL_L0REFDMA_24_reg_addr                                            "0xB800E560"
#define  LGCY_RL_L0REFDMA_24_reg                                                 0xB800E560
#define  LGCY_RL_L0REFDMA_24_inst_addr                                           "0x001E"
#define  set_LGCY_RL_L0REFDMA_24_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_24_reg)=data)
#define  get_LGCY_RL_L0REFDMA_24_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_24_reg))
#define  LGCY_RL_L0REFDMA_24_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_24_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_24_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_24_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_24_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_24_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_24_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_24_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_24_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_24_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_24_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_24_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_24_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_24_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_24_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_24_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_25                                                     0x1800E564
#define  LGCY_RL_L0REFDMA_25_reg_addr                                            "0xB800E564"
#define  LGCY_RL_L0REFDMA_25_reg                                                 0xB800E564
#define  LGCY_RL_L0REFDMA_25_inst_addr                                           "0x001F"
#define  set_LGCY_RL_L0REFDMA_25_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_25_reg)=data)
#define  get_LGCY_RL_L0REFDMA_25_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_25_reg))
#define  LGCY_RL_L0REFDMA_25_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_25_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_25_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_25_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_25_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_25_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_25_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_25_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_25_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_25_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_25_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_25_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_25_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_25_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_25_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_25_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_26                                                     0x1800E568
#define  LGCY_RL_L0REFDMA_26_reg_addr                                            "0xB800E568"
#define  LGCY_RL_L0REFDMA_26_reg                                                 0xB800E568
#define  LGCY_RL_L0REFDMA_26_inst_addr                                           "0x0020"
#define  set_LGCY_RL_L0REFDMA_26_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_26_reg)=data)
#define  get_LGCY_RL_L0REFDMA_26_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_26_reg))
#define  LGCY_RL_L0REFDMA_26_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_26_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_26_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_26_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_26_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_26_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_26_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_26_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_26_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_26_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_26_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_26_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_26_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_26_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_26_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_26_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_27                                                     0x1800E56C
#define  LGCY_RL_L0REFDMA_27_reg_addr                                            "0xB800E56C"
#define  LGCY_RL_L0REFDMA_27_reg                                                 0xB800E56C
#define  LGCY_RL_L0REFDMA_27_inst_addr                                           "0x0021"
#define  set_LGCY_RL_L0REFDMA_27_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_27_reg)=data)
#define  get_LGCY_RL_L0REFDMA_27_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_27_reg))
#define  LGCY_RL_L0REFDMA_27_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_27_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_27_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_27_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_27_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_27_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_27_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_27_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_27_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_27_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_27_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_27_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_27_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_27_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_27_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_27_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_28                                                     0x1800E570
#define  LGCY_RL_L0REFDMA_28_reg_addr                                            "0xB800E570"
#define  LGCY_RL_L0REFDMA_28_reg                                                 0xB800E570
#define  LGCY_RL_L0REFDMA_28_inst_addr                                           "0x0022"
#define  set_LGCY_RL_L0REFDMA_28_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_28_reg)=data)
#define  get_LGCY_RL_L0REFDMA_28_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_28_reg))
#define  LGCY_RL_L0REFDMA_28_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_28_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_28_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_28_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_28_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_28_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_28_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_28_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_28_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_28_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_28_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_28_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_28_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_28_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_28_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_28_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_29                                                     0x1800E574
#define  LGCY_RL_L0REFDMA_29_reg_addr                                            "0xB800E574"
#define  LGCY_RL_L0REFDMA_29_reg                                                 0xB800E574
#define  LGCY_RL_L0REFDMA_29_inst_addr                                           "0x0023"
#define  set_LGCY_RL_L0REFDMA_29_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_29_reg)=data)
#define  get_LGCY_RL_L0REFDMA_29_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_29_reg))
#define  LGCY_RL_L0REFDMA_29_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_29_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_29_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_29_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_29_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_29_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_29_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_29_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_29_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_29_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_29_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_29_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_29_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_29_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_29_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_29_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_30                                                     0x1800E578
#define  LGCY_RL_L0REFDMA_30_reg_addr                                            "0xB800E578"
#define  LGCY_RL_L0REFDMA_30_reg                                                 0xB800E578
#define  LGCY_RL_L0REFDMA_30_inst_addr                                           "0x0024"
#define  set_LGCY_RL_L0REFDMA_30_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_30_reg)=data)
#define  get_LGCY_RL_L0REFDMA_30_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_30_reg))
#define  LGCY_RL_L0REFDMA_30_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_30_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_30_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_30_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_30_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_30_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_30_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_30_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_30_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_30_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_30_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_30_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_30_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_30_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_30_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_30_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L0REFDMA_31                                                     0x1800E57C
#define  LGCY_RL_L0REFDMA_31_reg_addr                                            "0xB800E57C"
#define  LGCY_RL_L0REFDMA_31_reg                                                 0xB800E57C
#define  LGCY_RL_L0REFDMA_31_inst_addr                                           "0x0025"
#define  set_LGCY_RL_L0REFDMA_31_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L0REFDMA_31_reg)=data)
#define  get_LGCY_RL_L0REFDMA_31_reg                                             (*((volatile unsigned int*)LGCY_RL_L0REFDMA_31_reg))
#define  LGCY_RL_L0REFDMA_31_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L0REFDMA_31_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L0REFDMA_31_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L0REFDMA_31_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L0REFDMA_31_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L0REFDMA_31_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L0REFDMA_31_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L0REFDMA_31_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L0REFDMA_31_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L0REFDMA_31_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L0REFDMA_31_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L0REFDMA_31_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L0REFDMA_31_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L0REFDMA_31_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L0REFDMA_31_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L0REFDMA_31_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_0                                                      0x1800E580
#define  LGCY_RL_L1REFDMA_0_reg_addr                                             "0xB800E580"
#define  LGCY_RL_L1REFDMA_0_reg                                                  0xB800E580
#define  LGCY_RL_L1REFDMA_0_inst_addr                                            "0x0026"
#define  set_LGCY_RL_L1REFDMA_0_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_0_reg)=data)
#define  get_LGCY_RL_L1REFDMA_0_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_0_reg))
#define  LGCY_RL_L1REFDMA_0_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_0_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_0_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_0_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_0_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_0_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_0_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_0_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_0_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_0_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_0_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_0_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_0_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_0_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_0_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_0_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_1                                                      0x1800E584
#define  LGCY_RL_L1REFDMA_1_reg_addr                                             "0xB800E584"
#define  LGCY_RL_L1REFDMA_1_reg                                                  0xB800E584
#define  LGCY_RL_L1REFDMA_1_inst_addr                                            "0x0027"
#define  set_LGCY_RL_L1REFDMA_1_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_1_reg)=data)
#define  get_LGCY_RL_L1REFDMA_1_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_1_reg))
#define  LGCY_RL_L1REFDMA_1_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_1_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_1_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_1_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_1_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_1_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_1_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_1_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_1_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_1_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_1_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_1_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_1_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_1_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_1_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_1_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_2                                                      0x1800E588
#define  LGCY_RL_L1REFDMA_2_reg_addr                                             "0xB800E588"
#define  LGCY_RL_L1REFDMA_2_reg                                                  0xB800E588
#define  LGCY_RL_L1REFDMA_2_inst_addr                                            "0x0028"
#define  set_LGCY_RL_L1REFDMA_2_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_2_reg)=data)
#define  get_LGCY_RL_L1REFDMA_2_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_2_reg))
#define  LGCY_RL_L1REFDMA_2_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_2_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_2_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_2_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_2_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_2_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_2_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_2_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_2_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_2_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_2_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_2_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_2_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_2_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_2_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_2_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_3                                                      0x1800E58C
#define  LGCY_RL_L1REFDMA_3_reg_addr                                             "0xB800E58C"
#define  LGCY_RL_L1REFDMA_3_reg                                                  0xB800E58C
#define  LGCY_RL_L1REFDMA_3_inst_addr                                            "0x0029"
#define  set_LGCY_RL_L1REFDMA_3_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_3_reg)=data)
#define  get_LGCY_RL_L1REFDMA_3_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_3_reg))
#define  LGCY_RL_L1REFDMA_3_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_3_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_3_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_3_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_3_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_3_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_3_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_3_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_3_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_3_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_3_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_3_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_3_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_3_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_3_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_3_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_4                                                      0x1800E590
#define  LGCY_RL_L1REFDMA_4_reg_addr                                             "0xB800E590"
#define  LGCY_RL_L1REFDMA_4_reg                                                  0xB800E590
#define  LGCY_RL_L1REFDMA_4_inst_addr                                            "0x002A"
#define  set_LGCY_RL_L1REFDMA_4_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_4_reg)=data)
#define  get_LGCY_RL_L1REFDMA_4_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_4_reg))
#define  LGCY_RL_L1REFDMA_4_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_4_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_4_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_4_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_4_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_4_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_4_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_4_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_4_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_4_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_4_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_4_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_4_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_4_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_4_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_4_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_5                                                      0x1800E594
#define  LGCY_RL_L1REFDMA_5_reg_addr                                             "0xB800E594"
#define  LGCY_RL_L1REFDMA_5_reg                                                  0xB800E594
#define  LGCY_RL_L1REFDMA_5_inst_addr                                            "0x002B"
#define  set_LGCY_RL_L1REFDMA_5_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_5_reg)=data)
#define  get_LGCY_RL_L1REFDMA_5_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_5_reg))
#define  LGCY_RL_L1REFDMA_5_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_5_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_5_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_5_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_5_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_5_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_5_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_5_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_5_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_5_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_5_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_5_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_5_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_5_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_5_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_5_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_6                                                      0x1800E598
#define  LGCY_RL_L1REFDMA_6_reg_addr                                             "0xB800E598"
#define  LGCY_RL_L1REFDMA_6_reg                                                  0xB800E598
#define  LGCY_RL_L1REFDMA_6_inst_addr                                            "0x002C"
#define  set_LGCY_RL_L1REFDMA_6_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_6_reg)=data)
#define  get_LGCY_RL_L1REFDMA_6_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_6_reg))
#define  LGCY_RL_L1REFDMA_6_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_6_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_6_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_6_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_6_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_6_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_6_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_6_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_6_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_6_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_6_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_6_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_6_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_6_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_6_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_6_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_7                                                      0x1800E59C
#define  LGCY_RL_L1REFDMA_7_reg_addr                                             "0xB800E59C"
#define  LGCY_RL_L1REFDMA_7_reg                                                  0xB800E59C
#define  LGCY_RL_L1REFDMA_7_inst_addr                                            "0x002D"
#define  set_LGCY_RL_L1REFDMA_7_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_7_reg)=data)
#define  get_LGCY_RL_L1REFDMA_7_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_7_reg))
#define  LGCY_RL_L1REFDMA_7_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_7_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_7_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_7_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_7_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_7_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_7_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_7_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_7_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_7_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_7_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_7_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_7_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_7_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_7_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_7_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_8                                                      0x1800E5A0
#define  LGCY_RL_L1REFDMA_8_reg_addr                                             "0xB800E5A0"
#define  LGCY_RL_L1REFDMA_8_reg                                                  0xB800E5A0
#define  LGCY_RL_L1REFDMA_8_inst_addr                                            "0x002E"
#define  set_LGCY_RL_L1REFDMA_8_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_8_reg)=data)
#define  get_LGCY_RL_L1REFDMA_8_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_8_reg))
#define  LGCY_RL_L1REFDMA_8_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_8_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_8_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_8_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_8_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_8_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_8_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_8_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_8_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_8_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_8_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_8_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_8_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_8_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_8_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_8_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_9                                                      0x1800E5A4
#define  LGCY_RL_L1REFDMA_9_reg_addr                                             "0xB800E5A4"
#define  LGCY_RL_L1REFDMA_9_reg                                                  0xB800E5A4
#define  LGCY_RL_L1REFDMA_9_inst_addr                                            "0x002F"
#define  set_LGCY_RL_L1REFDMA_9_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_L1REFDMA_9_reg)=data)
#define  get_LGCY_RL_L1REFDMA_9_reg                                              (*((volatile unsigned int*)LGCY_RL_L1REFDMA_9_reg))
#define  LGCY_RL_L1REFDMA_9_ref_rangeredfrm_shift                                (15)
#define  LGCY_RL_L1REFDMA_9_bottom_field_flag_shift                              (14)
#define  LGCY_RL_L1REFDMA_9_lu_addr_index_shift                                  (7)
#define  LGCY_RL_L1REFDMA_9_ch_addr_index_shift                                  (0)
#define  LGCY_RL_L1REFDMA_9_ref_rangeredfrm_mask                                 (0x00008000)
#define  LGCY_RL_L1REFDMA_9_bottom_field_flag_mask                               (0x00004000)
#define  LGCY_RL_L1REFDMA_9_lu_addr_index_mask                                   (0x00003F80)
#define  LGCY_RL_L1REFDMA_9_ch_addr_index_mask                                   (0x0000007F)
#define  LGCY_RL_L1REFDMA_9_ref_rangeredfrm(data)                                (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_9_bottom_field_flag(data)                              (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_9_lu_addr_index(data)                                  (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_9_ch_addr_index(data)                                  (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_9_get_ref_rangeredfrm(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_9_get_bottom_field_flag(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_9_get_lu_addr_index(data)                              ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_9_get_ch_addr_index(data)                              (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_10                                                     0x1800E5A8
#define  LGCY_RL_L1REFDMA_10_reg_addr                                            "0xB800E5A8"
#define  LGCY_RL_L1REFDMA_10_reg                                                 0xB800E5A8
#define  LGCY_RL_L1REFDMA_10_inst_addr                                           "0x0030"
#define  set_LGCY_RL_L1REFDMA_10_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_10_reg)=data)
#define  get_LGCY_RL_L1REFDMA_10_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_10_reg))
#define  LGCY_RL_L1REFDMA_10_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_10_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_10_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_10_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_10_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_10_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_10_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_10_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_10_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_10_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_10_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_10_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_10_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_10_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_10_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_10_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_11                                                     0x1800E5AC
#define  LGCY_RL_L1REFDMA_11_reg_addr                                            "0xB800E5AC"
#define  LGCY_RL_L1REFDMA_11_reg                                                 0xB800E5AC
#define  LGCY_RL_L1REFDMA_11_inst_addr                                           "0x0031"
#define  set_LGCY_RL_L1REFDMA_11_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_11_reg)=data)
#define  get_LGCY_RL_L1REFDMA_11_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_11_reg))
#define  LGCY_RL_L1REFDMA_11_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_11_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_11_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_11_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_11_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_11_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_11_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_11_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_11_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_11_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_11_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_11_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_11_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_11_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_11_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_11_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_12                                                     0x1800E5B0
#define  LGCY_RL_L1REFDMA_12_reg_addr                                            "0xB800E5B0"
#define  LGCY_RL_L1REFDMA_12_reg                                                 0xB800E5B0
#define  LGCY_RL_L1REFDMA_12_inst_addr                                           "0x0032"
#define  set_LGCY_RL_L1REFDMA_12_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_12_reg)=data)
#define  get_LGCY_RL_L1REFDMA_12_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_12_reg))
#define  LGCY_RL_L1REFDMA_12_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_12_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_12_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_12_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_12_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_12_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_12_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_12_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_12_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_12_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_12_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_12_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_12_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_12_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_12_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_12_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_13                                                     0x1800E5B4
#define  LGCY_RL_L1REFDMA_13_reg_addr                                            "0xB800E5B4"
#define  LGCY_RL_L1REFDMA_13_reg                                                 0xB800E5B4
#define  LGCY_RL_L1REFDMA_13_inst_addr                                           "0x0033"
#define  set_LGCY_RL_L1REFDMA_13_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_13_reg)=data)
#define  get_LGCY_RL_L1REFDMA_13_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_13_reg))
#define  LGCY_RL_L1REFDMA_13_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_13_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_13_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_13_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_13_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_13_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_13_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_13_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_13_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_13_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_13_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_13_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_13_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_13_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_13_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_13_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_14                                                     0x1800E5B8
#define  LGCY_RL_L1REFDMA_14_reg_addr                                            "0xB800E5B8"
#define  LGCY_RL_L1REFDMA_14_reg                                                 0xB800E5B8
#define  LGCY_RL_L1REFDMA_14_inst_addr                                           "0x0034"
#define  set_LGCY_RL_L1REFDMA_14_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_14_reg)=data)
#define  get_LGCY_RL_L1REFDMA_14_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_14_reg))
#define  LGCY_RL_L1REFDMA_14_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_14_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_14_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_14_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_14_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_14_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_14_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_14_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_14_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_14_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_14_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_14_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_14_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_14_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_14_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_14_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_15                                                     0x1800E5BC
#define  LGCY_RL_L1REFDMA_15_reg_addr                                            "0xB800E5BC"
#define  LGCY_RL_L1REFDMA_15_reg                                                 0xB800E5BC
#define  LGCY_RL_L1REFDMA_15_inst_addr                                           "0x0035"
#define  set_LGCY_RL_L1REFDMA_15_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_15_reg)=data)
#define  get_LGCY_RL_L1REFDMA_15_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_15_reg))
#define  LGCY_RL_L1REFDMA_15_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_15_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_15_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_15_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_15_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_15_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_15_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_15_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_15_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_15_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_15_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_15_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_15_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_15_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_15_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_15_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_16                                                     0x1800E5C0
#define  LGCY_RL_L1REFDMA_16_reg_addr                                            "0xB800E5C0"
#define  LGCY_RL_L1REFDMA_16_reg                                                 0xB800E5C0
#define  LGCY_RL_L1REFDMA_16_inst_addr                                           "0x0036"
#define  set_LGCY_RL_L1REFDMA_16_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_16_reg)=data)
#define  get_LGCY_RL_L1REFDMA_16_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_16_reg))
#define  LGCY_RL_L1REFDMA_16_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_16_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_16_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_16_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_16_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_16_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_16_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_16_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_16_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_16_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_16_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_16_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_16_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_16_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_16_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_16_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_17                                                     0x1800E5C4
#define  LGCY_RL_L1REFDMA_17_reg_addr                                            "0xB800E5C4"
#define  LGCY_RL_L1REFDMA_17_reg                                                 0xB800E5C4
#define  LGCY_RL_L1REFDMA_17_inst_addr                                           "0x0037"
#define  set_LGCY_RL_L1REFDMA_17_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_17_reg)=data)
#define  get_LGCY_RL_L1REFDMA_17_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_17_reg))
#define  LGCY_RL_L1REFDMA_17_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_17_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_17_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_17_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_17_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_17_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_17_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_17_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_17_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_17_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_17_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_17_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_17_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_17_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_17_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_17_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_18                                                     0x1800E5C8
#define  LGCY_RL_L1REFDMA_18_reg_addr                                            "0xB800E5C8"
#define  LGCY_RL_L1REFDMA_18_reg                                                 0xB800E5C8
#define  LGCY_RL_L1REFDMA_18_inst_addr                                           "0x0038"
#define  set_LGCY_RL_L1REFDMA_18_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_18_reg)=data)
#define  get_LGCY_RL_L1REFDMA_18_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_18_reg))
#define  LGCY_RL_L1REFDMA_18_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_18_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_18_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_18_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_18_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_18_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_18_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_18_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_18_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_18_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_18_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_18_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_18_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_18_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_18_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_18_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_19                                                     0x1800E5CC
#define  LGCY_RL_L1REFDMA_19_reg_addr                                            "0xB800E5CC"
#define  LGCY_RL_L1REFDMA_19_reg                                                 0xB800E5CC
#define  LGCY_RL_L1REFDMA_19_inst_addr                                           "0x0039"
#define  set_LGCY_RL_L1REFDMA_19_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_19_reg)=data)
#define  get_LGCY_RL_L1REFDMA_19_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_19_reg))
#define  LGCY_RL_L1REFDMA_19_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_19_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_19_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_19_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_19_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_19_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_19_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_19_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_19_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_19_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_19_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_19_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_19_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_19_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_19_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_19_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_20                                                     0x1800E5D0
#define  LGCY_RL_L1REFDMA_20_reg_addr                                            "0xB800E5D0"
#define  LGCY_RL_L1REFDMA_20_reg                                                 0xB800E5D0
#define  LGCY_RL_L1REFDMA_20_inst_addr                                           "0x003A"
#define  set_LGCY_RL_L1REFDMA_20_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_20_reg)=data)
#define  get_LGCY_RL_L1REFDMA_20_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_20_reg))
#define  LGCY_RL_L1REFDMA_20_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_20_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_20_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_20_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_20_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_20_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_20_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_20_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_20_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_20_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_20_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_20_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_20_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_20_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_20_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_20_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_21                                                     0x1800E5D4
#define  LGCY_RL_L1REFDMA_21_reg_addr                                            "0xB800E5D4"
#define  LGCY_RL_L1REFDMA_21_reg                                                 0xB800E5D4
#define  LGCY_RL_L1REFDMA_21_inst_addr                                           "0x003B"
#define  set_LGCY_RL_L1REFDMA_21_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_21_reg)=data)
#define  get_LGCY_RL_L1REFDMA_21_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_21_reg))
#define  LGCY_RL_L1REFDMA_21_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_21_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_21_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_21_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_21_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_21_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_21_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_21_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_21_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_21_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_21_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_21_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_21_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_21_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_21_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_21_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_22                                                     0x1800E5D8
#define  LGCY_RL_L1REFDMA_22_reg_addr                                            "0xB800E5D8"
#define  LGCY_RL_L1REFDMA_22_reg                                                 0xB800E5D8
#define  LGCY_RL_L1REFDMA_22_inst_addr                                           "0x003C"
#define  set_LGCY_RL_L1REFDMA_22_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_22_reg)=data)
#define  get_LGCY_RL_L1REFDMA_22_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_22_reg))
#define  LGCY_RL_L1REFDMA_22_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_22_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_22_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_22_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_22_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_22_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_22_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_22_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_22_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_22_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_22_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_22_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_22_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_22_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_22_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_22_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_23                                                     0x1800E5DC
#define  LGCY_RL_L1REFDMA_23_reg_addr                                            "0xB800E5DC"
#define  LGCY_RL_L1REFDMA_23_reg                                                 0xB800E5DC
#define  LGCY_RL_L1REFDMA_23_inst_addr                                           "0x003D"
#define  set_LGCY_RL_L1REFDMA_23_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_23_reg)=data)
#define  get_LGCY_RL_L1REFDMA_23_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_23_reg))
#define  LGCY_RL_L1REFDMA_23_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_23_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_23_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_23_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_23_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_23_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_23_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_23_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_23_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_23_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_23_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_23_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_23_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_23_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_23_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_23_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_24                                                     0x1800E5E0
#define  LGCY_RL_L1REFDMA_24_reg_addr                                            "0xB800E5E0"
#define  LGCY_RL_L1REFDMA_24_reg                                                 0xB800E5E0
#define  LGCY_RL_L1REFDMA_24_inst_addr                                           "0x003E"
#define  set_LGCY_RL_L1REFDMA_24_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_24_reg)=data)
#define  get_LGCY_RL_L1REFDMA_24_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_24_reg))
#define  LGCY_RL_L1REFDMA_24_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_24_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_24_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_24_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_24_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_24_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_24_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_24_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_24_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_24_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_24_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_24_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_24_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_24_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_24_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_24_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_25                                                     0x1800E5E4
#define  LGCY_RL_L1REFDMA_25_reg_addr                                            "0xB800E5E4"
#define  LGCY_RL_L1REFDMA_25_reg                                                 0xB800E5E4
#define  LGCY_RL_L1REFDMA_25_inst_addr                                           "0x003F"
#define  set_LGCY_RL_L1REFDMA_25_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_25_reg)=data)
#define  get_LGCY_RL_L1REFDMA_25_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_25_reg))
#define  LGCY_RL_L1REFDMA_25_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_25_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_25_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_25_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_25_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_25_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_25_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_25_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_25_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_25_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_25_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_25_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_25_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_25_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_25_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_25_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_26                                                     0x1800E5E8
#define  LGCY_RL_L1REFDMA_26_reg_addr                                            "0xB800E5E8"
#define  LGCY_RL_L1REFDMA_26_reg                                                 0xB800E5E8
#define  LGCY_RL_L1REFDMA_26_inst_addr                                           "0x0040"
#define  set_LGCY_RL_L1REFDMA_26_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_26_reg)=data)
#define  get_LGCY_RL_L1REFDMA_26_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_26_reg))
#define  LGCY_RL_L1REFDMA_26_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_26_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_26_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_26_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_26_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_26_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_26_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_26_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_26_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_26_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_26_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_26_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_26_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_26_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_26_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_26_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_27                                                     0x1800E5EC
#define  LGCY_RL_L1REFDMA_27_reg_addr                                            "0xB800E5EC"
#define  LGCY_RL_L1REFDMA_27_reg                                                 0xB800E5EC
#define  LGCY_RL_L1REFDMA_27_inst_addr                                           "0x0041"
#define  set_LGCY_RL_L1REFDMA_27_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_27_reg)=data)
#define  get_LGCY_RL_L1REFDMA_27_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_27_reg))
#define  LGCY_RL_L1REFDMA_27_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_27_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_27_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_27_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_27_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_27_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_27_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_27_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_27_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_27_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_27_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_27_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_27_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_27_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_27_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_27_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_28                                                     0x1800E5F0
#define  LGCY_RL_L1REFDMA_28_reg_addr                                            "0xB800E5F0"
#define  LGCY_RL_L1REFDMA_28_reg                                                 0xB800E5F0
#define  LGCY_RL_L1REFDMA_28_inst_addr                                           "0x0042"
#define  set_LGCY_RL_L1REFDMA_28_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_28_reg)=data)
#define  get_LGCY_RL_L1REFDMA_28_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_28_reg))
#define  LGCY_RL_L1REFDMA_28_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_28_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_28_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_28_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_28_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_28_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_28_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_28_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_28_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_28_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_28_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_28_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_28_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_28_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_28_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_28_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_29                                                     0x1800E5F4
#define  LGCY_RL_L1REFDMA_29_reg_addr                                            "0xB800E5F4"
#define  LGCY_RL_L1REFDMA_29_reg                                                 0xB800E5F4
#define  LGCY_RL_L1REFDMA_29_inst_addr                                           "0x0043"
#define  set_LGCY_RL_L1REFDMA_29_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_29_reg)=data)
#define  get_LGCY_RL_L1REFDMA_29_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_29_reg))
#define  LGCY_RL_L1REFDMA_29_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_29_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_29_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_29_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_29_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_29_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_29_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_29_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_29_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_29_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_29_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_29_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_29_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_29_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_29_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_29_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_30                                                     0x1800E5F8
#define  LGCY_RL_L1REFDMA_30_reg_addr                                            "0xB800E5F8"
#define  LGCY_RL_L1REFDMA_30_reg                                                 0xB800E5F8
#define  LGCY_RL_L1REFDMA_30_inst_addr                                           "0x0044"
#define  set_LGCY_RL_L1REFDMA_30_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_30_reg)=data)
#define  get_LGCY_RL_L1REFDMA_30_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_30_reg))
#define  LGCY_RL_L1REFDMA_30_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_30_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_30_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_30_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_30_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_30_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_30_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_30_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_30_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_30_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_30_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_30_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_30_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_30_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_30_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_30_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_L1REFDMA_31                                                     0x1800E5FC
#define  LGCY_RL_L1REFDMA_31_reg_addr                                            "0xB800E5FC"
#define  LGCY_RL_L1REFDMA_31_reg                                                 0xB800E5FC
#define  LGCY_RL_L1REFDMA_31_inst_addr                                           "0x0045"
#define  set_LGCY_RL_L1REFDMA_31_reg(data)                                       (*((volatile unsigned int*)LGCY_RL_L1REFDMA_31_reg)=data)
#define  get_LGCY_RL_L1REFDMA_31_reg                                             (*((volatile unsigned int*)LGCY_RL_L1REFDMA_31_reg))
#define  LGCY_RL_L1REFDMA_31_ref_rangeredfrm_shift                               (15)
#define  LGCY_RL_L1REFDMA_31_bottom_field_flag_shift                             (14)
#define  LGCY_RL_L1REFDMA_31_lu_addr_index_shift                                 (7)
#define  LGCY_RL_L1REFDMA_31_ch_addr_index_shift                                 (0)
#define  LGCY_RL_L1REFDMA_31_ref_rangeredfrm_mask                                (0x00008000)
#define  LGCY_RL_L1REFDMA_31_bottom_field_flag_mask                              (0x00004000)
#define  LGCY_RL_L1REFDMA_31_lu_addr_index_mask                                  (0x00003F80)
#define  LGCY_RL_L1REFDMA_31_ch_addr_index_mask                                  (0x0000007F)
#define  LGCY_RL_L1REFDMA_31_ref_rangeredfrm(data)                               (0x00008000&((data)<<15))
#define  LGCY_RL_L1REFDMA_31_bottom_field_flag(data)                             (0x00004000&((data)<<14))
#define  LGCY_RL_L1REFDMA_31_lu_addr_index(data)                                 (0x00003F80&((data)<<7))
#define  LGCY_RL_L1REFDMA_31_ch_addr_index(data)                                 (0x0000007F&(data))
#define  LGCY_RL_L1REFDMA_31_get_ref_rangeredfrm(data)                           ((0x00008000&(data))>>15)
#define  LGCY_RL_L1REFDMA_31_get_bottom_field_flag(data)                         ((0x00004000&(data))>>14)
#define  LGCY_RL_L1REFDMA_31_get_lu_addr_index(data)                             ((0x00003F80&(data))>>7)
#define  LGCY_RL_L1REFDMA_31_get_ch_addr_index(data)                             (0x0000007F&(data))

#define  LGCY_RL_DBG_SEL                                                         0x1800EC18
#define  LGCY_RL_DBG_SEL_reg_addr                                                "0xB800EC18"
#define  LGCY_RL_DBG_SEL_reg                                                     0xB800EC18
#define  LGCY_RL_DBG_SEL_inst_addr                                               "0x0046"
#define  set_LGCY_RL_DBG_SEL_reg(data)                                           (*((volatile unsigned int*)LGCY_RL_DBG_SEL_reg)=data)
#define  get_LGCY_RL_DBG_SEL_reg                                                 (*((volatile unsigned int*)LGCY_RL_DBG_SEL_reg))
#define  LGCY_RL_DBG_SEL_write_enable3_shift                                     (31)
#define  LGCY_RL_DBG_SEL_trigger_status_shift                                    (30)
#define  LGCY_RL_DBG_SEL_zero_w_lr_shift                                         (28)
#define  LGCY_RL_DBG_SEL_write_enable2_shift                                     (27)
#define  LGCY_RL_DBG_SEL_trigger_select_shift                                    (23)
#define  LGCY_RL_DBG_SEL_trigger_cond_mb_x_shift                                 (12)
#define  LGCY_RL_DBG_SEL_trigger_cond_mb_y_shift                                 (4)
#define  LGCY_RL_DBG_SEL_write_enable1_shift                                     (3)
#define  LGCY_RL_DBG_SEL_debug_port_sel_shift                                    (0)
#define  LGCY_RL_DBG_SEL_write_enable3_mask                                      (0x80000000)
#define  LGCY_RL_DBG_SEL_trigger_status_mask                                     (0x40000000)
#define  LGCY_RL_DBG_SEL_zero_w_lr_mask                                          (0x30000000)
#define  LGCY_RL_DBG_SEL_write_enable2_mask                                      (0x08000000)
#define  LGCY_RL_DBG_SEL_trigger_select_mask                                     (0x07800000)
#define  LGCY_RL_DBG_SEL_trigger_cond_mb_x_mask                                  (0x001FF000)
#define  LGCY_RL_DBG_SEL_trigger_cond_mb_y_mask                                  (0x00000FF0)
#define  LGCY_RL_DBG_SEL_write_enable1_mask                                      (0x00000008)
#define  LGCY_RL_DBG_SEL_debug_port_sel_mask                                     (0x00000007)
#define  LGCY_RL_DBG_SEL_write_enable3(data)                                     (0x80000000&((data)<<31))
#define  LGCY_RL_DBG_SEL_trigger_status(data)                                    (0x40000000&((data)<<30))
#define  LGCY_RL_DBG_SEL_zero_w_lr(data)                                         (0x30000000&((data)<<28))
#define  LGCY_RL_DBG_SEL_write_enable2(data)                                     (0x08000000&((data)<<27))
#define  LGCY_RL_DBG_SEL_trigger_select(data)                                    (0x07800000&((data)<<23))
#define  LGCY_RL_DBG_SEL_trigger_cond_mb_x(data)                                 (0x001FF000&((data)<<12))
#define  LGCY_RL_DBG_SEL_trigger_cond_mb_y(data)                                 (0x00000FF0&((data)<<4))
#define  LGCY_RL_DBG_SEL_write_enable1(data)                                     (0x00000008&((data)<<3))
#define  LGCY_RL_DBG_SEL_debug_port_sel(data)                                    (0x00000007&(data))
#define  LGCY_RL_DBG_SEL_get_write_enable3(data)                                 ((0x80000000&(data))>>31)
#define  LGCY_RL_DBG_SEL_get_trigger_status(data)                                ((0x40000000&(data))>>30)
#define  LGCY_RL_DBG_SEL_get_zero_w_lr(data)                                     ((0x30000000&(data))>>28)
#define  LGCY_RL_DBG_SEL_get_write_enable2(data)                                 ((0x08000000&(data))>>27)
#define  LGCY_RL_DBG_SEL_get_trigger_select(data)                                ((0x07800000&(data))>>23)
#define  LGCY_RL_DBG_SEL_get_trigger_cond_mb_x(data)                             ((0x001FF000&(data))>>12)
#define  LGCY_RL_DBG_SEL_get_trigger_cond_mb_y(data)                             ((0x00000FF0&(data))>>4)
#define  LGCY_RL_DBG_SEL_get_write_enable1(data)                                 ((0x00000008&(data))>>3)
#define  LGCY_RL_DBG_SEL_get_debug_port_sel(data)                                (0x00000007&(data))

#define  LGCY_RL_DBG_STS0                                                        0x1800EC1C
#define  LGCY_RL_DBG_STS0_reg_addr                                               "0xB800EC1C"
#define  LGCY_RL_DBG_STS0_reg                                                    0xB800EC1C
#define  LGCY_RL_DBG_STS0_inst_addr                                              "0x0047"
#define  set_LGCY_RL_DBG_STS0_reg(data)                                          (*((volatile unsigned int*)LGCY_RL_DBG_STS0_reg)=data)
#define  get_LGCY_RL_DBG_STS0_reg                                                (*((volatile unsigned int*)LGCY_RL_DBG_STS0_reg))
#define  LGCY_RL_DBG_STS0_tbl_cnt_shift                                          (16)
#define  LGCY_RL_DBG_STS0_trigger_tbl_cnt_shift                                  (0)
#define  LGCY_RL_DBG_STS0_tbl_cnt_mask                                           (0xFFFF0000)
#define  LGCY_RL_DBG_STS0_trigger_tbl_cnt_mask                                   (0x0000FFFF)
#define  LGCY_RL_DBG_STS0_tbl_cnt(data)                                          (0xFFFF0000&((data)<<16))
#define  LGCY_RL_DBG_STS0_trigger_tbl_cnt(data)                                  (0x0000FFFF&(data))
#define  LGCY_RL_DBG_STS0_get_tbl_cnt(data)                                      ((0xFFFF0000&(data))>>16)
#define  LGCY_RL_DBG_STS0_get_trigger_tbl_cnt(data)                              (0x0000FFFF&(data))

#define  LGCY_RL_DBG_STS1                                                        0x1800EC20
#define  LGCY_RL_DBG_STS1_reg_addr                                               "0xB800EC20"
#define  LGCY_RL_DBG_STS1_reg                                                    0xB800EC20
#define  LGCY_RL_DBG_STS1_inst_addr                                              "0x0048"
#define  set_LGCY_RL_DBG_STS1_reg(data)                                          (*((volatile unsigned int*)LGCY_RL_DBG_STS1_reg)=data)
#define  get_LGCY_RL_DBG_STS1_reg                                                (*((volatile unsigned int*)LGCY_RL_DBG_STS1_reg))
#define  LGCY_RL_DBG_STS1_dbg_sts_shift                                          (0)
#define  LGCY_RL_DBG_STS1_dbg_sts_mask                                           (0xFFFFFFFF)
#define  LGCY_RL_DBG_STS1_dbg_sts(data)                                          (0xFFFFFFFF&(data))
#define  LGCY_RL_DBG_STS1_get_dbg_sts(data)                                      (0xFFFFFFFF&(data))

#define  LGCY_RL_DBG_STS2                                                        0x1800EC24
#define  LGCY_RL_DBG_STS2_reg_addr                                               "0xB800EC24"
#define  LGCY_RL_DBG_STS2_reg                                                    0xB800EC24
#define  LGCY_RL_DBG_STS2_inst_addr                                              "0x0049"
#define  set_LGCY_RL_DBG_STS2_reg(data)                                          (*((volatile unsigned int*)LGCY_RL_DBG_STS2_reg)=data)
#define  get_LGCY_RL_DBG_STS2_reg                                                (*((volatile unsigned int*)LGCY_RL_DBG_STS2_reg))
#define  LGCY_RL_DBG_STS2_dbg_sts_shift                                          (0)
#define  LGCY_RL_DBG_STS2_dbg_sts_mask                                           (0xFFFFFFFF)
#define  LGCY_RL_DBG_STS2_dbg_sts(data)                                          (0xFFFFFFFF&(data))
#define  LGCY_RL_DBG_STS2_get_dbg_sts(data)                                      (0xFFFFFFFF&(data))

#define  LGCY_RL_INTR_THRES                                                      0x1800EC28
#define  LGCY_RL_INTR_THRES_reg_addr                                             "0xB800EC28"
#define  LGCY_RL_INTR_THRES_reg                                                  0xB800EC28
#define  LGCY_RL_INTR_THRES_inst_addr                                            "0x004A"
#define  set_LGCY_RL_INTR_THRES_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_INTR_THRES_reg)=data)
#define  get_LGCY_RL_INTR_THRES_reg                                              (*((volatile unsigned int*)LGCY_RL_INTR_THRES_reg))
#define  LGCY_RL_INTR_THRES_intr_shift                                           (28)
#define  LGCY_RL_INTR_THRES_value_shift                                          (0)
#define  LGCY_RL_INTR_THRES_intr_mask                                            (0x10000000)
#define  LGCY_RL_INTR_THRES_value_mask                                           (0x0FFFFFFF)
#define  LGCY_RL_INTR_THRES_intr(data)                                           (0x10000000&((data)<<28))
#define  LGCY_RL_INTR_THRES_value(data)                                          (0x0FFFFFFF&(data))
#define  LGCY_RL_INTR_THRES_get_intr(data)                                       ((0x10000000&(data))>>28)
#define  LGCY_RL_INTR_THRES_get_value(data)                                      (0x0FFFFFFF&(data))

#define  LGCY_RL_MVBUF_WADD                                                      0x1800EC80
#define  LGCY_RL_MVBUF_WADD_reg_addr                                             "0xB800EC80"
#define  LGCY_RL_MVBUF_WADD_reg                                                  0xB800EC80
#define  LGCY_RL_MVBUF_WADD_inst_addr                                            "0x004B"
#define  set_LGCY_RL_MVBUF_WADD_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_MVBUF_WADD_reg)=data)
#define  get_LGCY_RL_MVBUF_WADD_reg                                              (*((volatile unsigned int*)LGCY_RL_MVBUF_WADD_reg))
#define  LGCY_RL_MVBUF_WADD_mvbuf_write_address_shift                            (0)
#define  LGCY_RL_MVBUF_WADD_mvbuf_write_address_mask                             (0x0000007F)
#define  LGCY_RL_MVBUF_WADD_mvbuf_write_address(data)                            (0x0000007F&(data))
#define  LGCY_RL_MVBUF_WADD_get_mvbuf_write_address(data)                        (0x0000007F&(data))

#define  LGCY_RL_MVBUF_DATA_0                                                    0x1800EC84
#define  LGCY_RL_MVBUF_DATA_0_reg_addr                                           "0xB800EC84"
#define  LGCY_RL_MVBUF_DATA_0_reg                                                0xB800EC84
#define  LGCY_RL_MVBUF_DATA_0_inst_addr                                          "0x004C"
#define  set_LGCY_RL_MVBUF_DATA_0_reg(data)                                      (*((volatile unsigned int*)LGCY_RL_MVBUF_DATA_0_reg)=data)
#define  get_LGCY_RL_MVBUF_DATA_0_reg                                            (*((volatile unsigned int*)LGCY_RL_MVBUF_DATA_0_reg))
#define  LGCY_RL_MVBUF_DATA_0_mvbuf_read_write_data_shift                        (0)
#define  LGCY_RL_MVBUF_DATA_0_mvbuf_read_write_data_mask                         (0xFFFFFFFF)
#define  LGCY_RL_MVBUF_DATA_0_mvbuf_read_write_data(data)                        (0xFFFFFFFF&(data))
#define  LGCY_RL_MVBUF_DATA_0_get_mvbuf_read_write_data(data)                    (0xFFFFFFFF&(data))

#define  LGCY_RL_MVBUF_DATA_1                                                    0x1800EC88
#define  LGCY_RL_MVBUF_DATA_1_reg_addr                                           "0xB800EC88"
#define  LGCY_RL_MVBUF_DATA_1_reg                                                0xB800EC88
#define  LGCY_RL_MVBUF_DATA_1_inst_addr                                          "0x004D"
#define  set_LGCY_RL_MVBUF_DATA_1_reg(data)                                      (*((volatile unsigned int*)LGCY_RL_MVBUF_DATA_1_reg)=data)
#define  get_LGCY_RL_MVBUF_DATA_1_reg                                            (*((volatile unsigned int*)LGCY_RL_MVBUF_DATA_1_reg))
#define  LGCY_RL_MVBUF_DATA_1_mvbuf_read_write_data_shift                        (0)
#define  LGCY_RL_MVBUF_DATA_1_mvbuf_read_write_data_mask                         (0xFFFFFFFF)
#define  LGCY_RL_MVBUF_DATA_1_mvbuf_read_write_data(data)                        (0xFFFFFFFF&(data))
#define  LGCY_RL_MVBUF_DATA_1_get_mvbuf_read_write_data(data)                    (0xFFFFFFFF&(data))

#define  LGCY_RL_MVBUF_DATA_2                                                    0x1800EC8C
#define  LGCY_RL_MVBUF_DATA_2_reg_addr                                           "0xB800EC8C"
#define  LGCY_RL_MVBUF_DATA_2_reg                                                0xB800EC8C
#define  LGCY_RL_MVBUF_DATA_2_inst_addr                                          "0x004E"
#define  set_LGCY_RL_MVBUF_DATA_2_reg(data)                                      (*((volatile unsigned int*)LGCY_RL_MVBUF_DATA_2_reg)=data)
#define  get_LGCY_RL_MVBUF_DATA_2_reg                                            (*((volatile unsigned int*)LGCY_RL_MVBUF_DATA_2_reg))
#define  LGCY_RL_MVBUF_DATA_2_mvbuf_read_write_data_shift                        (0)
#define  LGCY_RL_MVBUF_DATA_2_mvbuf_read_write_data_mask                         (0xFFFFFFFF)
#define  LGCY_RL_MVBUF_DATA_2_mvbuf_read_write_data(data)                        (0xFFFFFFFF&(data))
#define  LGCY_RL_MVBUF_DATA_2_get_mvbuf_read_write_data(data)                    (0xFFFFFFFF&(data))

#define  LGCY_RL_MVBUF_RADD                                                      0x1800EC90
#define  LGCY_RL_MVBUF_RADD_reg_addr                                             "0xB800EC90"
#define  LGCY_RL_MVBUF_RADD_reg                                                  0xB800EC90
#define  LGCY_RL_MVBUF_RADD_inst_addr                                            "0x004F"
#define  set_LGCY_RL_MVBUF_RADD_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_MVBUF_RADD_reg)=data)
#define  get_LGCY_RL_MVBUF_RADD_reg                                              (*((volatile unsigned int*)LGCY_RL_MVBUF_RADD_reg))
#define  LGCY_RL_MVBUF_RADD_mvbuf_read_address_shift                             (0)
#define  LGCY_RL_MVBUF_RADD_mvbuf_read_address_mask                              (0x0000007F)
#define  LGCY_RL_MVBUF_RADD_mvbuf_read_address(data)                             (0x0000007F&(data))
#define  LGCY_RL_MVBUF_RADD_get_mvbuf_read_address(data)                         (0x0000007F&(data))

#define  LGCY_RL_MVBUF_STS0                                                      0x1800EC94
#define  LGCY_RL_MVBUF_STS0_reg_addr                                             "0xB800EC94"
#define  LGCY_RL_MVBUF_STS0_reg                                                  0xB800EC94
#define  LGCY_RL_MVBUF_STS0_inst_addr                                            "0x0050"
#define  set_LGCY_RL_MVBUF_STS0_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_MVBUF_STS0_reg)=data)
#define  get_LGCY_RL_MVBUF_STS0_reg                                              (*((volatile unsigned int*)LGCY_RL_MVBUF_STS0_reg))
#define  LGCY_RL_MVBUF_STS0_write_enable2_shift                                  (22)
#define  LGCY_RL_MVBUF_STS0_mvbuf_hdr_shift                                      (12)
#define  LGCY_RL_MVBUF_STS0_write_enable1_shift                                  (11)
#define  LGCY_RL_MVBUF_STS0_mvbuf_mvd_wptr_shift                                 (0)
#define  LGCY_RL_MVBUF_STS0_write_enable2_mask                                   (0x00400000)
#define  LGCY_RL_MVBUF_STS0_mvbuf_hdr_mask                                       (0x003FF000)
#define  LGCY_RL_MVBUF_STS0_write_enable1_mask                                   (0x00000800)
#define  LGCY_RL_MVBUF_STS0_mvbuf_mvd_wptr_mask                                  (0x000007FF)
#define  LGCY_RL_MVBUF_STS0_write_enable2(data)                                  (0x00400000&((data)<<22))
#define  LGCY_RL_MVBUF_STS0_mvbuf_hdr(data)                                      (0x003FF000&((data)<<12))
#define  LGCY_RL_MVBUF_STS0_write_enable1(data)                                  (0x00000800&((data)<<11))
#define  LGCY_RL_MVBUF_STS0_mvbuf_mvd_wptr(data)                                 (0x000007FF&(data))
#define  LGCY_RL_MVBUF_STS0_get_write_enable2(data)                              ((0x00400000&(data))>>22)
#define  LGCY_RL_MVBUF_STS0_get_mvbuf_hdr(data)                                  ((0x003FF000&(data))>>12)
#define  LGCY_RL_MVBUF_STS0_get_write_enable1(data)                              ((0x00000800&(data))>>11)
#define  LGCY_RL_MVBUF_STS0_get_mvbuf_mvd_wptr(data)                             (0x000007FF&(data))

#define  LGCY_RL_MVBUF_STS1                                                      0x1800EC98
#define  LGCY_RL_MVBUF_STS1_reg_addr                                             "0xB800EC98"
#define  LGCY_RL_MVBUF_STS1_reg                                                  0xB800EC98
#define  LGCY_RL_MVBUF_STS1_inst_addr                                            "0x0051"
#define  set_LGCY_RL_MVBUF_STS1_reg(data)                                        (*((volatile unsigned int*)LGCY_RL_MVBUF_STS1_reg)=data)
#define  get_LGCY_RL_MVBUF_STS1_reg                                              (*((volatile unsigned int*)LGCY_RL_MVBUF_STS1_reg))
#define  LGCY_RL_MVBUF_STS1_write_enable2_shift                                  (23)
#define  LGCY_RL_MVBUF_STS1_mvbuf_pred_rptr_shift                                (12)
#define  LGCY_RL_MVBUF_STS1_write_enable11_shift                                 (11)
#define  LGCY_RL_MVBUF_STS1_mvbuf_rl_rptr_shift                                  (0)
#define  LGCY_RL_MVBUF_STS1_write_enable2_mask                                   (0x00800000)
#define  LGCY_RL_MVBUF_STS1_mvbuf_pred_rptr_mask                                 (0x007FF000)
#define  LGCY_RL_MVBUF_STS1_write_enable11_mask                                  (0x00000800)
#define  LGCY_RL_MVBUF_STS1_mvbuf_rl_rptr_mask                                   (0x000007FF)
#define  LGCY_RL_MVBUF_STS1_write_enable2(data)                                  (0x00800000&((data)<<23))
#define  LGCY_RL_MVBUF_STS1_mvbuf_pred_rptr(data)                                (0x007FF000&((data)<<12))
#define  LGCY_RL_MVBUF_STS1_write_enable11(data)                                 (0x00000800&((data)<<11))
#define  LGCY_RL_MVBUF_STS1_mvbuf_rl_rptr(data)                                  (0x000007FF&(data))
#define  LGCY_RL_MVBUF_STS1_get_write_enable2(data)                              ((0x00800000&(data))>>23)
#define  LGCY_RL_MVBUF_STS1_get_mvbuf_pred_rptr(data)                            ((0x007FF000&(data))>>12)
#define  LGCY_RL_MVBUF_STS1_get_write_enable11(data)                             ((0x00000800&(data))>>11)
#define  LGCY_RL_MVBUF_STS1_get_mvbuf_rl_rptr(data)                              (0x000007FF&(data))

#define  LGCY_RL_cache_set                                                       0x1800EC9C
#define  LGCY_RL_cache_set_reg_addr                                              "0xB800EC9C"
#define  LGCY_RL_cache_set_reg                                                   0xB800EC9C
#define  LGCY_RL_cache_set_inst_addr                                             "0x0052"
#define  set_LGCY_RL_cache_set_reg(data)                                         (*((volatile unsigned int*)LGCY_RL_cache_set_reg)=data)
#define  get_LGCY_RL_cache_set_reg                                               (*((volatile unsigned int*)LGCY_RL_cache_set_reg))
#define  LGCY_RL_cache_set_write_enable3_shift                                   (7)
#define  LGCY_RL_cache_set_hdr_ref_pic_cnt_shift                                 (6)
#define  LGCY_RL_cache_set_write_enable2_shift                                   (5)
#define  LGCY_RL_cache_set_vg_en_shift                                           (3)
#define  LGCY_RL_cache_set_write_enable1_shift                                   (2)
#define  LGCY_RL_cache_set_ref_pic_cnt_shift                                     (0)
#define  LGCY_RL_cache_set_write_enable3_mask                                    (0x00000080)
#define  LGCY_RL_cache_set_hdr_ref_pic_cnt_mask                                  (0x00000040)
#define  LGCY_RL_cache_set_write_enable2_mask                                    (0x00000020)
#define  LGCY_RL_cache_set_vg_en_mask                                            (0x00000018)
#define  LGCY_RL_cache_set_write_enable1_mask                                    (0x00000004)
#define  LGCY_RL_cache_set_ref_pic_cnt_mask                                      (0x00000003)
#define  LGCY_RL_cache_set_write_enable3(data)                                   (0x00000080&((data)<<7))
#define  LGCY_RL_cache_set_hdr_ref_pic_cnt(data)                                 (0x00000040&((data)<<6))
#define  LGCY_RL_cache_set_write_enable2(data)                                   (0x00000020&((data)<<5))
#define  LGCY_RL_cache_set_vg_en(data)                                           (0x00000018&((data)<<3))
#define  LGCY_RL_cache_set_write_enable1(data)                                   (0x00000004&((data)<<2))
#define  LGCY_RL_cache_set_ref_pic_cnt(data)                                     (0x00000003&(data))
#define  LGCY_RL_cache_set_get_write_enable3(data)                               ((0x00000080&(data))>>7)
#define  LGCY_RL_cache_set_get_hdr_ref_pic_cnt(data)                             ((0x00000040&(data))>>6)
#define  LGCY_RL_cache_set_get_write_enable2(data)                               ((0x00000020&(data))>>5)
#define  LGCY_RL_cache_set_get_vg_en(data)                                       ((0x00000018&(data))>>3)
#define  LGCY_RL_cache_set_get_write_enable1(data)                               ((0x00000004&(data))>>2)
#define  LGCY_RL_cache_set_get_ref_pic_cnt(data)                                 (0x00000003&(data))

#define  LGCY_RL_cache_en                                                        0x1800ECA0
#define  LGCY_RL_cache_en_reg_addr                                               "0xB800ECA0"
#define  LGCY_RL_cache_en_reg                                                    0xB800ECA0
#define  LGCY_RL_cache_en_inst_addr                                              "0x0053"
#define  set_LGCY_RL_cache_en_reg(data)                                          (*((volatile unsigned int*)LGCY_RL_cache_en_reg)=data)
#define  get_LGCY_RL_cache_en_reg                                                (*((volatile unsigned int*)LGCY_RL_cache_en_reg))
#define  LGCY_RL_cache_en_hdr_cah_en_shift                                       (1)
#define  LGCY_RL_cache_en_cah_en_shift                                           (0)
#define  LGCY_RL_cache_en_hdr_cah_en_mask                                        (0x00000002)
#define  LGCY_RL_cache_en_cah_en_mask                                            (0x00000001)
#define  LGCY_RL_cache_en_hdr_cah_en(data)                                       (0x00000002&((data)<<1))
#define  LGCY_RL_cache_en_cah_en(data)                                           (0x00000001&(data))
#define  LGCY_RL_cache_en_get_hdr_cah_en(data)                                   ((0x00000002&(data))>>1)
#define  LGCY_RL_cache_en_get_cah_en(data)                                       (0x00000001&(data))

#define  LGCY_RL_cache_inv                                                       0x1800ECA4
#define  LGCY_RL_cache_inv_reg_addr                                              "0xB800ECA4"
#define  LGCY_RL_cache_inv_reg                                                   0xB800ECA4
#define  LGCY_RL_cache_inv_inst_addr                                             "0x0054"
#define  set_LGCY_RL_cache_inv_reg(data)                                         (*((volatile unsigned int*)LGCY_RL_cache_inv_reg)=data)
#define  get_LGCY_RL_cache_inv_reg                                               (*((volatile unsigned int*)LGCY_RL_cache_inv_reg))
#define  LGCY_RL_cache_inv_hdr_cah_inv_shift                                     (1)
#define  LGCY_RL_cache_inv_cah_inv_shift                                         (0)
#define  LGCY_RL_cache_inv_hdr_cah_inv_mask                                      (0x00000002)
#define  LGCY_RL_cache_inv_cah_inv_mask                                          (0x00000001)
#define  LGCY_RL_cache_inv_hdr_cah_inv(data)                                     (0x00000002&((data)<<1))
#define  LGCY_RL_cache_inv_cah_inv(data)                                         (0x00000001&(data))
#define  LGCY_RL_cache_inv_get_hdr_cah_inv(data)                                 ((0x00000002&(data))>>1)
#define  LGCY_RL_cache_inv_get_cah_inv(data)                                     (0x00000001&(data))

#define  LGCY_RL_cah_pindx                                                       0x1800ECA8
#define  LGCY_RL_cah_pindx_reg_addr                                              "0xB800ECA8"
#define  LGCY_RL_cah_pindx_reg                                                   0xB800ECA8
#define  LGCY_RL_cah_pindx_inst_addr                                             "0x0055"
#define  set_LGCY_RL_cah_pindx_reg(data)                                         (*((volatile unsigned int*)LGCY_RL_cah_pindx_reg)=data)
#define  get_LGCY_RL_cah_pindx_reg                                               (*((volatile unsigned int*)LGCY_RL_cah_pindx_reg))
#define  LGCY_RL_cah_pindx_cah_pindx0_luml0_shift                                (24)
#define  LGCY_RL_cah_pindx_cah_pindx1_luml1_shift                                (16)
#define  LGCY_RL_cah_pindx_cah_pindx2_chrl0_shift                                (8)
#define  LGCY_RL_cah_pindx_cah_pindx3_chrl1_shift                                (0)
#define  LGCY_RL_cah_pindx_cah_pindx0_luml0_mask                                 (0xFF000000)
#define  LGCY_RL_cah_pindx_cah_pindx1_luml1_mask                                 (0x00FF0000)
#define  LGCY_RL_cah_pindx_cah_pindx2_chrl0_mask                                 (0x0000FF00)
#define  LGCY_RL_cah_pindx_cah_pindx3_chrl1_mask                                 (0x000000FF)
#define  LGCY_RL_cah_pindx_cah_pindx0_luml0(data)                                (0xFF000000&((data)<<24))
#define  LGCY_RL_cah_pindx_cah_pindx1_luml1(data)                                (0x00FF0000&((data)<<16))
#define  LGCY_RL_cah_pindx_cah_pindx2_chrl0(data)                                (0x0000FF00&((data)<<8))
#define  LGCY_RL_cah_pindx_cah_pindx3_chrl1(data)                                (0x000000FF&(data))
#define  LGCY_RL_cah_pindx_get_cah_pindx0_luml0(data)                            ((0xFF000000&(data))>>24)
#define  LGCY_RL_cah_pindx_get_cah_pindx1_luml1(data)                            ((0x00FF0000&(data))>>16)
#define  LGCY_RL_cah_pindx_get_cah_pindx2_chrl0(data)                            ((0x0000FF00&(data))>>8)
#define  LGCY_RL_cah_pindx_get_cah_pindx3_chrl1(data)                            (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGCY_RL register structure define==========

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
}lgcy_rl_rlcntl_RBUS;

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
}lgcy_rl_rlcntl2_RBUS;

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
}lgcy_rl_ccpar_RBUS;

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
}lgcy_rl_h264ccpar_RBUS;

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
}lgcy_rl_vc1ccpar_RBUS;

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
}lgcy_rl_popar_RBUS;

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
}lgcy_rl_l0refdma_RBUS;

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
}lgcy_rl_l1refdma_RBUS;

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
}lgcy_rl_dbg_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbl_cnt:16;
        RBus_UInt32  trigger_tbl_cnt:16;
    };
}lgcy_rl_dbg_sts0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sts:32;
    };
}lgcy_rl_dbg_sts1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sts:32;
    };
}lgcy_rl_dbg_sts2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  intr:1;
        RBus_UInt32  value:28;
    };
}lgcy_rl_intr_thres_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  mvbuf_write_address:7;
    };
}lgcy_rl_mvbuf_wadd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_read_write_data:32;
    };
}lgcy_rl_mvbuf_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  mvbuf_read_address:7;
    };
}lgcy_rl_mvbuf_radd_RBUS;

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
}lgcy_rl_mvbuf_sts0_RBUS;

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
}lgcy_rl_mvbuf_sts1_RBUS;

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
}lgcy_rl_cache_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  hdr_cah_en:1;
        RBus_UInt32  cah_en:1;
    };
}lgcy_rl_cache_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  hdr_cah_inv:1;
        RBus_UInt32  cah_inv:1;
    };
}lgcy_rl_cache_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cah_pindx0_luml0:8;
        RBus_UInt32  cah_pindx1_luml1:8;
        RBus_UInt32  cah_pindx2_chrl0:8;
        RBus_UInt32  cah_pindx3_chrl1:8;
    };
}lgcy_rl_cah_pindx_RBUS;

#else //apply LITTLE_ENDIAN

//======LGCY_RL register structure define==========

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
}lgcy_rl_rlcntl_RBUS;

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
}lgcy_rl_rlcntl2_RBUS;

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
}lgcy_rl_ccpar_RBUS;

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
}lgcy_rl_h264ccpar_RBUS;

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
}lgcy_rl_vc1ccpar_RBUS;

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
}lgcy_rl_popar_RBUS;

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
}lgcy_rl_l0refdma_RBUS;

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
}lgcy_rl_l1refdma_RBUS;

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
}lgcy_rl_dbg_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trigger_tbl_cnt:16;
        RBus_UInt32  tbl_cnt:16;
    };
}lgcy_rl_dbg_sts0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sts:32;
    };
}lgcy_rl_dbg_sts1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sts:32;
    };
}lgcy_rl_dbg_sts2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:28;
        RBus_UInt32  intr:1;
        RBus_UInt32  res1:3;
    };
}lgcy_rl_intr_thres_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_write_address:7;
        RBus_UInt32  res1:25;
    };
}lgcy_rl_mvbuf_wadd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_read_write_data:32;
    };
}lgcy_rl_mvbuf_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvbuf_read_address:7;
        RBus_UInt32  res1:25;
    };
}lgcy_rl_mvbuf_radd_RBUS;

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
}lgcy_rl_mvbuf_sts0_RBUS;

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
}lgcy_rl_mvbuf_sts1_RBUS;

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
}lgcy_rl_cache_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cah_en:1;
        RBus_UInt32  hdr_cah_en:1;
        RBus_UInt32  res1:30;
    };
}lgcy_rl_cache_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cah_inv:1;
        RBus_UInt32  hdr_cah_inv:1;
        RBus_UInt32  res1:30;
    };
}lgcy_rl_cache_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cah_pindx3_chrl1:8;
        RBus_UInt32  cah_pindx2_chrl0:8;
        RBus_UInt32  cah_pindx1_luml1:8;
        RBus_UInt32  cah_pindx0_luml0:8;
    };
}lgcy_rl_cah_pindx_RBUS;




#endif 


#endif 
