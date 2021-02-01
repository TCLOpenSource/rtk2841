/**
* @file rbusRlReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_RL_REG_H_
#define _RBUS_RL_REG_H_

#include "rbusTypes.h"



//  RL Register Address
#define  RL_RLCNTL                                                               0x1800EC00
#define  RL_RLCNTL_reg_addr                                                      "0xB800EC00"
#define  RL_RLCNTL_reg                                                           0xB800EC00
#define  RL_RLCNTL_inst_addr                                                     "0x0000"
#define  RL_RLCNTL_inst_adr                                                      "0x0000"
#define  RL_RLCNTL_inst                                                          0x0000
#define  set_RL_RLCNTL_reg(data)                                                 (*((volatile unsigned int*)RL_RLCNTL_reg)=data)
#define  get_RL_RLCNTL_reg                                                       (*((volatile unsigned int*)RL_RLCNTL_reg))
#define  RL_RLCNTL_disppic_h_shift                                               (16)
#define  RL_RLCNTL_disppic_w_shift                                               (1)
#define  RL_RLCNTL_Cur_RANGEREDFRM_shift                                         (0)
#define  RL_RLCNTL_disppic_h_mask                                                (0x1FFF0000)
#define  RL_RLCNTL_disppic_w_mask                                                (0x00007FFE)
#define  RL_RLCNTL_Cur_RANGEREDFRM_mask                                          (0x00000001)
#define  RL_RLCNTL_disppic_h(data)                                               (0x1FFF0000&((data)<<16))
#define  RL_RLCNTL_disppic_w(data)                                               (0x00007FFE&((data)<<1))
#define  RL_RLCNTL_Cur_RANGEREDFRM(data)                                         (0x00000001&(data))
#define  RL_RLCNTL_get_disppic_h(data)                                           ((0x1FFF0000&(data))>>16)
#define  RL_RLCNTL_get_disppic_w(data)                                           ((0x00007FFE&(data))>>1)
#define  RL_RLCNTL_get_Cur_RANGEREDFRM(data)                                     (0x00000001&(data))
#define  RL_RLCNTL_disppic_h_src(data)                                           ((0x1FFF0000&(data))>>16)
#define  RL_RLCNTL_disppic_w_src(data)                                           ((0x00007FFE&(data))>>1)
#define  RL_RLCNTL_Cur_RANGEREDFRM_src(data)                                     (0x00000001&(data))

#define  RL_RLCNTL2                                                              0x1800EC04
#define  RL_RLCNTL2_reg_addr                                                     "0xB800EC04"
#define  RL_RLCNTL2_reg                                                          0xB800EC04
#define  RL_RLCNTL2_inst_addr                                                    "0x0001"
#define  RL_RLCNTL2_inst_adr                                                     "0x0001"
#define  RL_RLCNTL2_inst                                                         0x0001
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
#define  RL_RLCNTL2_RM_threshold_shift                                           (0)
#define  RL_RLCNTL2_write_enable3_mask                                           (0x00002000)
#define  RL_RLCNTL2_rmem_wptr_rst_mask                                           (0x00001000)
#define  RL_RLCNTL2_write_enable2_mask                                           (0x00000800)
#define  RL_RLCNTL2_ldmc_bypass_mask                                             (0x00000400)
#define  RL_RLCNTL2_pred_enable_mask                                             (0x00000200)
#define  RL_RLCNTL2_ldmc_enable_mask                                             (0x00000100)
#define  RL_RLCNTL2_write_enable1_mask                                           (0x00000080)
#define  RL_RLCNTL2_manual_thresh_ena_mask                                       (0x00000040)
#define  RL_RLCNTL2_RM_threshold_mask                                            (0x0000003F)
#define  RL_RLCNTL2_write_enable3(data)                                          (0x00002000&((data)<<13))
#define  RL_RLCNTL2_rmem_wptr_rst(data)                                          (0x00001000&((data)<<12))
#define  RL_RLCNTL2_write_enable2(data)                                          (0x00000800&((data)<<11))
#define  RL_RLCNTL2_ldmc_bypass(data)                                            (0x00000400&((data)<<10))
#define  RL_RLCNTL2_pred_enable(data)                                            (0x00000200&((data)<<9))
#define  RL_RLCNTL2_ldmc_enable(data)                                            (0x00000100&((data)<<8))
#define  RL_RLCNTL2_write_enable1(data)                                          (0x00000080&((data)<<7))
#define  RL_RLCNTL2_manual_thresh_ena(data)                                      (0x00000040&((data)<<6))
#define  RL_RLCNTL2_RM_threshold(data)                                           (0x0000003F&(data))
#define  RL_RLCNTL2_get_write_enable3(data)                                      ((0x00002000&(data))>>13)
#define  RL_RLCNTL2_get_rmem_wptr_rst(data)                                      ((0x00001000&(data))>>12)
#define  RL_RLCNTL2_get_write_enable2(data)                                      ((0x00000800&(data))>>11)
#define  RL_RLCNTL2_get_ldmc_bypass(data)                                        ((0x00000400&(data))>>10)
#define  RL_RLCNTL2_get_pred_enable(data)                                        ((0x00000200&(data))>>9)
#define  RL_RLCNTL2_get_ldmc_enable(data)                                        ((0x00000100&(data))>>8)
#define  RL_RLCNTL2_get_write_enable1(data)                                      ((0x00000080&(data))>>7)
#define  RL_RLCNTL2_get_manual_thresh_ena(data)                                  ((0x00000040&(data))>>6)
#define  RL_RLCNTL2_get_RM_threshold(data)                                       (0x0000003F&(data))
#define  RL_RLCNTL2_write_enable3_src(data)                                      ((0x00002000&(data))>>13)
#define  RL_RLCNTL2_rmem_wptr_rst_src(data)                                      ((0x00001000&(data))>>12)
#define  RL_RLCNTL2_write_enable2_src(data)                                      ((0x00000800&(data))>>11)
#define  RL_RLCNTL2_ldmc_bypass_src(data)                                        ((0x00000400&(data))>>10)
#define  RL_RLCNTL2_pred_enable_src(data)                                        ((0x00000200&(data))>>9)
#define  RL_RLCNTL2_ldmc_enable_src(data)                                        ((0x00000100&(data))>>8)
#define  RL_RLCNTL2_write_enable1_src(data)                                      ((0x00000080&(data))>>7)
#define  RL_RLCNTL2_manual_thresh_ena_src(data)                                  ((0x00000040&(data))>>6)
#define  RL_RLCNTL2_RM_threshold_src(data)                                       (0x0000003F&(data))

#define  RL_CCPAR                                                                0x1800EC08
#define  RL_CCPAR_reg_addr                                                       "0xB800EC08"
#define  RL_CCPAR_reg                                                            0xB800EC08
#define  RL_CCPAR_inst_addr                                                      "0x0002"
#define  RL_CCPAR_inst_adr                                                       "0x0002"
#define  RL_CCPAR_inst                                                           0x0002
#define  set_RL_CCPAR_reg(data)                                                  (*((volatile unsigned int*)RL_CCPAR_reg)=data)
#define  get_RL_CCPAR_reg                                                        (*((volatile unsigned int*)RL_CCPAR_reg))
#define  RL_CCPAR_HEVC_Zidx_shift                                                (24)
#define  RL_CCPAR_HEVC_Log2CbSize_minus3_shift                                   (22)
#define  RL_CCPAR_PicType_shift                                                  (19)
#define  RL_CCPAR_First_mb_shift                                                 (18)
#define  RL_CCPAR_Cur_mb_x_shift                                                 (9)
#define  RL_CCPAR_Cur_mb_y_shift                                                 (0)
#define  RL_CCPAR_HEVC_Zidx_mask                                                 (0xFF000000)
#define  RL_CCPAR_HEVC_Log2CbSize_minus3_mask                                    (0x00C00000)
#define  RL_CCPAR_PicType_mask                                                   (0x00380000)
#define  RL_CCPAR_First_mb_mask                                                  (0x00040000)
#define  RL_CCPAR_Cur_mb_x_mask                                                  (0x0003FE00)
#define  RL_CCPAR_Cur_mb_y_mask                                                  (0x000001FF)
#define  RL_CCPAR_HEVC_Zidx(data)                                                (0xFF000000&((data)<<24))
#define  RL_CCPAR_HEVC_Log2CbSize_minus3(data)                                   (0x00C00000&((data)<<22))
#define  RL_CCPAR_PicType(data)                                                  (0x00380000&((data)<<19))
#define  RL_CCPAR_First_mb(data)                                                 (0x00040000&((data)<<18))
#define  RL_CCPAR_Cur_mb_x(data)                                                 (0x0003FE00&((data)<<9))
#define  RL_CCPAR_Cur_mb_y(data)                                                 (0x000001FF&(data))
#define  RL_CCPAR_get_HEVC_Zidx(data)                                            ((0xFF000000&(data))>>24)
#define  RL_CCPAR_get_HEVC_Log2CbSize_minus3(data)                               ((0x00C00000&(data))>>22)
#define  RL_CCPAR_get_PicType(data)                                              ((0x00380000&(data))>>19)
#define  RL_CCPAR_get_First_mb(data)                                             ((0x00040000&(data))>>18)
#define  RL_CCPAR_get_Cur_mb_x(data)                                             ((0x0003FE00&(data))>>9)
#define  RL_CCPAR_get_Cur_mb_y(data)                                             (0x000001FF&(data))
#define  RL_CCPAR_HEVC_Zidx_src(data)                                            ((0xFF000000&(data))>>24)
#define  RL_CCPAR_HEVC_Log2CbSize_minus3_src(data)                               ((0x00C00000&(data))>>22)
#define  RL_CCPAR_PicType_src(data)                                              ((0x00380000&(data))>>19)
#define  RL_CCPAR_First_mb_src(data)                                             ((0x00040000&(data))>>18)
#define  RL_CCPAR_Cur_mb_x_src(data)                                             ((0x0003FE00&(data))>>9)
#define  RL_CCPAR_Cur_mb_y_src(data)                                             (0x000001FF&(data))

#define  RL_H264CCPAR                                                            0x1800EC0C
#define  RL_H264CCPAR_reg_addr                                                   "0xB800EC0C"
#define  RL_H264CCPAR_reg                                                        0xB800EC0C
#define  RL_H264CCPAR_inst_addr                                                  "0x0003"
#define  RL_H264CCPAR_inst_adr                                                   "0x0003"
#define  RL_H264CCPAR_inst                                                       0x0003
#define  set_RL_H264CCPAR_reg(data)                                              (*((volatile unsigned int*)RL_H264CCPAR_reg)=data)
#define  get_RL_H264CCPAR_reg                                                    (*((volatile unsigned int*)RL_H264CCPAR_reg))
#define  RL_H264CCPAR_PaddingCU_shift                                            (12)
#define  RL_H264CCPAR_dummyColCTB_shift                                          (11)
#define  RL_H264CCPAR_dummyRowCTB_shift                                          (10)
#define  RL_H264CCPAR_mb_field_decoding_flag_shift                               (9)
#define  RL_H264CCPAR_Mb_partition_shift                                         (0)
#define  RL_H264CCPAR_PaddingCU_mask                                             (0x00001000)
#define  RL_H264CCPAR_dummyColCTB_mask                                           (0x00000800)
#define  RL_H264CCPAR_dummyRowCTB_mask                                           (0x00000400)
#define  RL_H264CCPAR_mb_field_decoding_flag_mask                                (0x00000200)
#define  RL_H264CCPAR_Mb_partition_mask                                          (0x000001FF)
#define  RL_H264CCPAR_PaddingCU(data)                                            (0x00001000&((data)<<12))
#define  RL_H264CCPAR_dummyColCTB(data)                                          (0x00000800&((data)<<11))
#define  RL_H264CCPAR_dummyRowCTB(data)                                          (0x00000400&((data)<<10))
#define  RL_H264CCPAR_mb_field_decoding_flag(data)                               (0x00000200&((data)<<9))
#define  RL_H264CCPAR_Mb_partition(data)                                         (0x000001FF&(data))
#define  RL_H264CCPAR_get_PaddingCU(data)                                        ((0x00001000&(data))>>12)
#define  RL_H264CCPAR_get_dummyColCTB(data)                                      ((0x00000800&(data))>>11)
#define  RL_H264CCPAR_get_dummyRowCTB(data)                                      ((0x00000400&(data))>>10)
#define  RL_H264CCPAR_get_mb_field_decoding_flag(data)                           ((0x00000200&(data))>>9)
#define  RL_H264CCPAR_get_Mb_partition(data)                                     (0x000001FF&(data))
#define  RL_H264CCPAR_PaddingCU_src(data)                                        ((0x00001000&(data))>>12)
#define  RL_H264CCPAR_dummyColCTB_src(data)                                      ((0x00000800&(data))>>11)
#define  RL_H264CCPAR_dummyRowCTB_src(data)                                      ((0x00000400&(data))>>10)
#define  RL_H264CCPAR_mb_field_decoding_flag_src(data)                           ((0x00000200&(data))>>9)
#define  RL_H264CCPAR_Mb_partition_src(data)                                     (0x000001FF&(data))

#define  RL_VC1CCPAR                                                             0x1800EC10
#define  RL_VC1CCPAR_reg_addr                                                    "0xB800EC10"
#define  RL_VC1CCPAR_reg                                                         0xB800EC10
#define  RL_VC1CCPAR_inst_addr                                                   "0x0004"
#define  RL_VC1CCPAR_inst_adr                                                    "0x0004"
#define  RL_VC1CCPAR_inst                                                        0x0004
#define  set_RL_VC1CCPAR_reg(data)                                               (*((volatile unsigned int*)RL_VC1CCPAR_reg)=data)
#define  get_RL_VC1CCPAR_reg                                                     (*((volatile unsigned int*)RL_VC1CCPAR_reg))
#define  RL_VC1CCPAR_IntraMB_flag_shift                                          (21)
#define  RL_VC1CCPAR_Intra_flag_shift                                            (16)
#define  RL_VC1CCPAR_SubMB_partition_shift                                       (4)
#define  RL_VC1CCPAR_mvtype_shift                                                (2)
#define  RL_VC1CCPAR_FIELDTX_shift                                               (1)
#define  RL_VC1CCPAR_OVERFLAG_shift                                              (0)
#define  RL_VC1CCPAR_IntraMB_flag_mask                                           (0x00200000)
#define  RL_VC1CCPAR_Intra_flag_mask                                             (0x001F0000)
#define  RL_VC1CCPAR_SubMB_partition_mask                                        (0x0000FFF0)
#define  RL_VC1CCPAR_mvtype_mask                                                 (0x0000000C)
#define  RL_VC1CCPAR_FIELDTX_mask                                                (0x00000002)
#define  RL_VC1CCPAR_OVERFLAG_mask                                               (0x00000001)
#define  RL_VC1CCPAR_IntraMB_flag(data)                                          (0x00200000&((data)<<21))
#define  RL_VC1CCPAR_Intra_flag(data)                                            (0x001F0000&((data)<<16))
#define  RL_VC1CCPAR_SubMB_partition(data)                                       (0x0000FFF0&((data)<<4))
#define  RL_VC1CCPAR_mvtype(data)                                                (0x0000000C&((data)<<2))
#define  RL_VC1CCPAR_FIELDTX(data)                                               (0x00000002&((data)<<1))
#define  RL_VC1CCPAR_OVERFLAG(data)                                              (0x00000001&(data))
#define  RL_VC1CCPAR_get_IntraMB_flag(data)                                      ((0x00200000&(data))>>21)
#define  RL_VC1CCPAR_get_Intra_flag(data)                                        ((0x001F0000&(data))>>16)
#define  RL_VC1CCPAR_get_SubMB_partition(data)                                   ((0x0000FFF0&(data))>>4)
#define  RL_VC1CCPAR_get_mvtype(data)                                            ((0x0000000C&(data))>>2)
#define  RL_VC1CCPAR_get_FIELDTX(data)                                           ((0x00000002&(data))>>1)
#define  RL_VC1CCPAR_get_OVERFLAG(data)                                          (0x00000001&(data))
#define  RL_VC1CCPAR_IntraMB_flag_src(data)                                      ((0x00200000&(data))>>21)
#define  RL_VC1CCPAR_Intra_flag_src(data)                                        ((0x001F0000&(data))>>16)
#define  RL_VC1CCPAR_SubMB_partition_src(data)                                   ((0x0000FFF0&(data))>>4)
#define  RL_VC1CCPAR_mvtype_src(data)                                            ((0x0000000C&(data))>>2)
#define  RL_VC1CCPAR_FIELDTX_src(data)                                           ((0x00000002&(data))>>1)
#define  RL_VC1CCPAR_OVERFLAG_src(data)                                          (0x00000001&(data))

#define  RL_POPAR                                                                0x1800EC14
#define  RL_POPAR_reg_addr                                                       "0xB800EC14"
#define  RL_POPAR_reg                                                            0xB800EC14
#define  RL_POPAR_inst_addr                                                      "0x0005"
#define  RL_POPAR_inst_adr                                                       "0x0005"
#define  RL_POPAR_inst                                                           0x0005
#define  set_RL_POPAR_reg(data)                                                  (*((volatile unsigned int*)RL_POPAR_reg)=data)
#define  get_RL_POPAR_reg                                                        (*((volatile unsigned int*)RL_POPAR_reg))
#define  RL_POPAR_Chroma_predict_part0_shift                                     (14)
#define  RL_POPAR_Chroma_predict_part1_shift                                     (12)
#define  RL_POPAR_Chroma_predict_part2_shift                                     (10)
#define  RL_POPAR_Chroma_predict_part3_shift                                     (8)
#define  RL_POPAR_Inter_predict_part0_shift                                      (6)
#define  RL_POPAR_Inter_predict_part1_shift                                      (4)
#define  RL_POPAR_Inter_predict_part2_shift                                      (2)
#define  RL_POPAR_Inter_predict_part3_shift                                      (0)
#define  RL_POPAR_Chroma_predict_part0_mask                                      (0x0000C000)
#define  RL_POPAR_Chroma_predict_part1_mask                                      (0x00003000)
#define  RL_POPAR_Chroma_predict_part2_mask                                      (0x00000C00)
#define  RL_POPAR_Chroma_predict_part3_mask                                      (0x00000300)
#define  RL_POPAR_Inter_predict_part0_mask                                       (0x000000C0)
#define  RL_POPAR_Inter_predict_part1_mask                                       (0x00000030)
#define  RL_POPAR_Inter_predict_part2_mask                                       (0x0000000C)
#define  RL_POPAR_Inter_predict_part3_mask                                       (0x00000003)
#define  RL_POPAR_Chroma_predict_part0(data)                                     (0x0000C000&((data)<<14))
#define  RL_POPAR_Chroma_predict_part1(data)                                     (0x00003000&((data)<<12))
#define  RL_POPAR_Chroma_predict_part2(data)                                     (0x00000C00&((data)<<10))
#define  RL_POPAR_Chroma_predict_part3(data)                                     (0x00000300&((data)<<8))
#define  RL_POPAR_Inter_predict_part0(data)                                      (0x000000C0&((data)<<6))
#define  RL_POPAR_Inter_predict_part1(data)                                      (0x00000030&((data)<<4))
#define  RL_POPAR_Inter_predict_part2(data)                                      (0x0000000C&((data)<<2))
#define  RL_POPAR_Inter_predict_part3(data)                                      (0x00000003&(data))
#define  RL_POPAR_get_Chroma_predict_part0(data)                                 ((0x0000C000&(data))>>14)
#define  RL_POPAR_get_Chroma_predict_part1(data)                                 ((0x00003000&(data))>>12)
#define  RL_POPAR_get_Chroma_predict_part2(data)                                 ((0x00000C00&(data))>>10)
#define  RL_POPAR_get_Chroma_predict_part3(data)                                 ((0x00000300&(data))>>8)
#define  RL_POPAR_get_Inter_predict_part0(data)                                  ((0x000000C0&(data))>>6)
#define  RL_POPAR_get_Inter_predict_part1(data)                                  ((0x00000030&(data))>>4)
#define  RL_POPAR_get_Inter_predict_part2(data)                                  ((0x0000000C&(data))>>2)
#define  RL_POPAR_get_Inter_predict_part3(data)                                  (0x00000003&(data))
#define  RL_POPAR_Chroma_predict_part0_src(data)                                 ((0x0000C000&(data))>>14)
#define  RL_POPAR_Chroma_predict_part1_src(data)                                 ((0x00003000&(data))>>12)
#define  RL_POPAR_Chroma_predict_part2_src(data)                                 ((0x00000C00&(data))>>10)
#define  RL_POPAR_Chroma_predict_part3_src(data)                                 ((0x00000300&(data))>>8)
#define  RL_POPAR_Inter_predict_part0_src(data)                                  ((0x000000C0&(data))>>6)
#define  RL_POPAR_Inter_predict_part1_src(data)                                  ((0x00000030&(data))>>4)
#define  RL_POPAR_Inter_predict_part2_src(data)                                  ((0x0000000C&(data))>>2)
#define  RL_POPAR_Inter_predict_part3_src(data)                                  (0x00000003&(data))

#define  RL_L0REFDMA_0                                                           0x1800E500
#define  RL_L0REFDMA_0_reg_addr                                                  "0xB800E500"
#define  RL_L0REFDMA_0_reg                                                       0xB800E500
#define  RL_L0REFDMA_0_inst_addr                                                 "0x0006"
#define  RL_L0REFDMA_0_inst_adr                                                  "0x0040"
#define  RL_L0REFDMA_0_inst                                                      0x0040
#define  set_RL_L0REFDMA_0_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_0_reg)=data)
#define  get_RL_L0REFDMA_0_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_0_reg))
#define  RL_L0REFDMA_ref_RANGEREDFRM_shift                                       (15)
#define  RL_L0REFDMA_bottom_field_flag_shift                                     (14)
#define  RL_L0REFDMA_lu_addr_index_shift                                         (7)
#define  RL_L0REFDMA_ch_addr_index_shift                                         (0)
#define  RL_L0REFDMA_ref_RANGEREDFRM_mask                                        (0x00008000)
#define  RL_L0REFDMA_bottom_field_flag_mask                                      (0x00004000)
#define  RL_L0REFDMA_lu_addr_index_mask                                          (0x00003F80)
#define  RL_L0REFDMA_ch_addr_index_mask                                          (0x0000007F)
#define  RL_L0REFDMA_ref_RANGEREDFRM(data)                                       (0x00008000&((data)<<15))
#define  RL_L0REFDMA_bottom_field_flag(data)                                     (0x00004000&((data)<<14))
#define  RL_L0REFDMA_lu_addr_index(data)                                         (0x00003F80&((data)<<7))
#define  RL_L0REFDMA_ch_addr_index(data)                                         (0x0000007F&(data))
#define  RL_L0REFDMA_get_ref_RANGEREDFRM(data)                                   ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_get_bottom_field_flag(data)                                 ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_get_lu_addr_index(data)                                     ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_get_ch_addr_index(data)                                     (0x0000007F&(data))
#define  RL_L0REFDMA_ref_RANGEREDFRM_src(data)                                   ((0x00008000&(data))>>15)
#define  RL_L0REFDMA_bottom_field_flag_src(data)                                 ((0x00004000&(data))>>14)
#define  RL_L0REFDMA_lu_addr_index_src(data)                                     ((0x00003F80&(data))>>7)
#define  RL_L0REFDMA_ch_addr_index_src(data)                                     (0x0000007F&(data))

#define  RL_L0REFDMA_1                                                           0x1800E504
#define  RL_L0REFDMA_1_reg_addr                                                  "0xB800E504"
#define  RL_L0REFDMA_1_reg                                                       0xB800E504
#define  RL_L0REFDMA_1_inst_addr                                                 "0x0007"
#define  RL_L0REFDMA_1_inst_adr                                                  "0x0041"
#define  RL_L0REFDMA_1_inst                                                      0x0041
#define  set_RL_L0REFDMA_1_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_1_reg)=data)
#define  get_RL_L0REFDMA_1_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_1_reg))

#define  RL_L0REFDMA_2                                                           0x1800E508
#define  RL_L0REFDMA_2_reg_addr                                                  "0xB800E508"
#define  RL_L0REFDMA_2_reg                                                       0xB800E508
#define  RL_L0REFDMA_2_inst_addr                                                 "0x0008"
#define  RL_L0REFDMA_2_inst_adr                                                  "0x0042"
#define  RL_L0REFDMA_2_inst                                                      0x0042
#define  set_RL_L0REFDMA_2_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_2_reg)=data)
#define  get_RL_L0REFDMA_2_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_2_reg))

#define  RL_L0REFDMA_3                                                           0x1800E50C
#define  RL_L0REFDMA_3_reg_addr                                                  "0xB800E50C"
#define  RL_L0REFDMA_3_reg                                                       0xB800E50C
#define  RL_L0REFDMA_3_inst_addr                                                 "0x0009"
#define  RL_L0REFDMA_3_inst_adr                                                  "0x0043"
#define  RL_L0REFDMA_3_inst                                                      0x0043
#define  set_RL_L0REFDMA_3_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_3_reg)=data)
#define  get_RL_L0REFDMA_3_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_3_reg))

#define  RL_L0REFDMA_4                                                           0x1800E510
#define  RL_L0REFDMA_4_reg_addr                                                  "0xB800E510"
#define  RL_L0REFDMA_4_reg                                                       0xB800E510
#define  RL_L0REFDMA_4_inst_addr                                                 "0x000A"
#define  RL_L0REFDMA_4_inst_adr                                                  "0x0044"
#define  RL_L0REFDMA_4_inst                                                      0x0044
#define  set_RL_L0REFDMA_4_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_4_reg)=data)
#define  get_RL_L0REFDMA_4_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_4_reg))

#define  RL_L0REFDMA_5                                                           0x1800E514
#define  RL_L0REFDMA_5_reg_addr                                                  "0xB800E514"
#define  RL_L0REFDMA_5_reg                                                       0xB800E514
#define  RL_L0REFDMA_5_inst_addr                                                 "0x000B"
#define  RL_L0REFDMA_5_inst_adr                                                  "0x0045"
#define  RL_L0REFDMA_5_inst                                                      0x0045
#define  set_RL_L0REFDMA_5_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_5_reg)=data)
#define  get_RL_L0REFDMA_5_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_5_reg))

#define  RL_L0REFDMA_6                                                           0x1800E518
#define  RL_L0REFDMA_6_reg_addr                                                  "0xB800E518"
#define  RL_L0REFDMA_6_reg                                                       0xB800E518
#define  RL_L0REFDMA_6_inst_addr                                                 "0x000C"
#define  RL_L0REFDMA_6_inst_adr                                                  "0x0046"
#define  RL_L0REFDMA_6_inst                                                      0x0046
#define  set_RL_L0REFDMA_6_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_6_reg)=data)
#define  get_RL_L0REFDMA_6_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_6_reg))

#define  RL_L0REFDMA_7                                                           0x1800E51C
#define  RL_L0REFDMA_7_reg_addr                                                  "0xB800E51C"
#define  RL_L0REFDMA_7_reg                                                       0xB800E51C
#define  RL_L0REFDMA_7_inst_addr                                                 "0x000D"
#define  RL_L0REFDMA_7_inst_adr                                                  "0x0047"
#define  RL_L0REFDMA_7_inst                                                      0x0047
#define  set_RL_L0REFDMA_7_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_7_reg)=data)
#define  get_RL_L0REFDMA_7_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_7_reg))

#define  RL_L0REFDMA_8                                                           0x1800E520
#define  RL_L0REFDMA_8_reg_addr                                                  "0xB800E520"
#define  RL_L0REFDMA_8_reg                                                       0xB800E520
#define  RL_L0REFDMA_8_inst_addr                                                 "0x000E"
#define  RL_L0REFDMA_8_inst_adr                                                  "0x0048"
#define  RL_L0REFDMA_8_inst                                                      0x0048
#define  set_RL_L0REFDMA_8_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_8_reg)=data)
#define  get_RL_L0REFDMA_8_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_8_reg))

#define  RL_L0REFDMA_9                                                           0x1800E524
#define  RL_L0REFDMA_9_reg_addr                                                  "0xB800E524"
#define  RL_L0REFDMA_9_reg                                                       0xB800E524
#define  RL_L0REFDMA_9_inst_addr                                                 "0x000F"
#define  RL_L0REFDMA_9_inst_adr                                                  "0x0049"
#define  RL_L0REFDMA_9_inst                                                      0x0049
#define  set_RL_L0REFDMA_9_reg(data)                                             (*((volatile unsigned int*)RL_L0REFDMA_9_reg)=data)
#define  get_RL_L0REFDMA_9_reg                                                   (*((volatile unsigned int*)RL_L0REFDMA_9_reg))

#define  RL_L0REFDMA_10                                                          0x1800E528
#define  RL_L0REFDMA_10_reg_addr                                                 "0xB800E528"
#define  RL_L0REFDMA_10_reg                                                      0xB800E528
#define  RL_L0REFDMA_10_inst_addr                                                "0x0010"
#define  RL_L0REFDMA_10_inst_adr                                                 "0x004A"
#define  RL_L0REFDMA_10_inst                                                     0x004A
#define  set_RL_L0REFDMA_10_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_10_reg)=data)
#define  get_RL_L0REFDMA_10_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_10_reg))

#define  RL_L0REFDMA_11                                                          0x1800E52C
#define  RL_L0REFDMA_11_reg_addr                                                 "0xB800E52C"
#define  RL_L0REFDMA_11_reg                                                      0xB800E52C
#define  RL_L0REFDMA_11_inst_addr                                                "0x0011"
#define  RL_L0REFDMA_11_inst_adr                                                 "0x004B"
#define  RL_L0REFDMA_11_inst                                                     0x004B
#define  set_RL_L0REFDMA_11_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_11_reg)=data)
#define  get_RL_L0REFDMA_11_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_11_reg))

#define  RL_L0REFDMA_12                                                          0x1800E530
#define  RL_L0REFDMA_12_reg_addr                                                 "0xB800E530"
#define  RL_L0REFDMA_12_reg                                                      0xB800E530
#define  RL_L0REFDMA_12_inst_addr                                                "0x0012"
#define  RL_L0REFDMA_12_inst_adr                                                 "0x004C"
#define  RL_L0REFDMA_12_inst                                                     0x004C
#define  set_RL_L0REFDMA_12_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_12_reg)=data)
#define  get_RL_L0REFDMA_12_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_12_reg))

#define  RL_L0REFDMA_13                                                          0x1800E534
#define  RL_L0REFDMA_13_reg_addr                                                 "0xB800E534"
#define  RL_L0REFDMA_13_reg                                                      0xB800E534
#define  RL_L0REFDMA_13_inst_addr                                                "0x0013"
#define  RL_L0REFDMA_13_inst_adr                                                 "0x004D"
#define  RL_L0REFDMA_13_inst                                                     0x004D
#define  set_RL_L0REFDMA_13_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_13_reg)=data)
#define  get_RL_L0REFDMA_13_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_13_reg))

#define  RL_L0REFDMA_14                                                          0x1800E538
#define  RL_L0REFDMA_14_reg_addr                                                 "0xB800E538"
#define  RL_L0REFDMA_14_reg                                                      0xB800E538
#define  RL_L0REFDMA_14_inst_addr                                                "0x0014"
#define  RL_L0REFDMA_14_inst_adr                                                 "0x004E"
#define  RL_L0REFDMA_14_inst                                                     0x004E
#define  set_RL_L0REFDMA_14_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_14_reg)=data)
#define  get_RL_L0REFDMA_14_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_14_reg))

#define  RL_L0REFDMA_15                                                          0x1800E53C
#define  RL_L0REFDMA_15_reg_addr                                                 "0xB800E53C"
#define  RL_L0REFDMA_15_reg                                                      0xB800E53C
#define  RL_L0REFDMA_15_inst_addr                                                "0x0015"
#define  RL_L0REFDMA_15_inst_adr                                                 "0x004F"
#define  RL_L0REFDMA_15_inst                                                     0x004F
#define  set_RL_L0REFDMA_15_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_15_reg)=data)
#define  get_RL_L0REFDMA_15_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_15_reg))

#define  RL_L0REFDMA_16                                                          0x1800E540
#define  RL_L0REFDMA_16_reg_addr                                                 "0xB800E540"
#define  RL_L0REFDMA_16_reg                                                      0xB800E540
#define  RL_L0REFDMA_16_inst_addr                                                "0x0016"
#define  RL_L0REFDMA_16_inst_adr                                                 "0x0050"
#define  RL_L0REFDMA_16_inst                                                     0x0050
#define  set_RL_L0REFDMA_16_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_16_reg)=data)
#define  get_RL_L0REFDMA_16_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_16_reg))

#define  RL_L0REFDMA_17                                                          0x1800E544
#define  RL_L0REFDMA_17_reg_addr                                                 "0xB800E544"
#define  RL_L0REFDMA_17_reg                                                      0xB800E544
#define  RL_L0REFDMA_17_inst_addr                                                "0x0017"
#define  RL_L0REFDMA_17_inst_adr                                                 "0x0051"
#define  RL_L0REFDMA_17_inst                                                     0x0051
#define  set_RL_L0REFDMA_17_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_17_reg)=data)
#define  get_RL_L0REFDMA_17_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_17_reg))

#define  RL_L0REFDMA_18                                                          0x1800E548
#define  RL_L0REFDMA_18_reg_addr                                                 "0xB800E548"
#define  RL_L0REFDMA_18_reg                                                      0xB800E548
#define  RL_L0REFDMA_18_inst_addr                                                "0x0018"
#define  RL_L0REFDMA_18_inst_adr                                                 "0x0052"
#define  RL_L0REFDMA_18_inst                                                     0x0052
#define  set_RL_L0REFDMA_18_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_18_reg)=data)
#define  get_RL_L0REFDMA_18_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_18_reg))

#define  RL_L0REFDMA_19                                                          0x1800E54C
#define  RL_L0REFDMA_19_reg_addr                                                 "0xB800E54C"
#define  RL_L0REFDMA_19_reg                                                      0xB800E54C
#define  RL_L0REFDMA_19_inst_addr                                                "0x0019"
#define  RL_L0REFDMA_19_inst_adr                                                 "0x0053"
#define  RL_L0REFDMA_19_inst                                                     0x0053
#define  set_RL_L0REFDMA_19_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_19_reg)=data)
#define  get_RL_L0REFDMA_19_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_19_reg))

#define  RL_L0REFDMA_20                                                          0x1800E550
#define  RL_L0REFDMA_20_reg_addr                                                 "0xB800E550"
#define  RL_L0REFDMA_20_reg                                                      0xB800E550
#define  RL_L0REFDMA_20_inst_addr                                                "0x001A"
#define  RL_L0REFDMA_20_inst_adr                                                 "0x0054"
#define  RL_L0REFDMA_20_inst                                                     0x0054
#define  set_RL_L0REFDMA_20_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_20_reg)=data)
#define  get_RL_L0REFDMA_20_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_20_reg))

#define  RL_L0REFDMA_21                                                          0x1800E554
#define  RL_L0REFDMA_21_reg_addr                                                 "0xB800E554"
#define  RL_L0REFDMA_21_reg                                                      0xB800E554
#define  RL_L0REFDMA_21_inst_addr                                                "0x001B"
#define  RL_L0REFDMA_21_inst_adr                                                 "0x0055"
#define  RL_L0REFDMA_21_inst                                                     0x0055
#define  set_RL_L0REFDMA_21_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_21_reg)=data)
#define  get_RL_L0REFDMA_21_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_21_reg))

#define  RL_L0REFDMA_22                                                          0x1800E558
#define  RL_L0REFDMA_22_reg_addr                                                 "0xB800E558"
#define  RL_L0REFDMA_22_reg                                                      0xB800E558
#define  RL_L0REFDMA_22_inst_addr                                                "0x001C"
#define  RL_L0REFDMA_22_inst_adr                                                 "0x0056"
#define  RL_L0REFDMA_22_inst                                                     0x0056
#define  set_RL_L0REFDMA_22_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_22_reg)=data)
#define  get_RL_L0REFDMA_22_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_22_reg))

#define  RL_L0REFDMA_23                                                          0x1800E55C
#define  RL_L0REFDMA_23_reg_addr                                                 "0xB800E55C"
#define  RL_L0REFDMA_23_reg                                                      0xB800E55C
#define  RL_L0REFDMA_23_inst_addr                                                "0x001D"
#define  RL_L0REFDMA_23_inst_adr                                                 "0x0057"
#define  RL_L0REFDMA_23_inst                                                     0x0057
#define  set_RL_L0REFDMA_23_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_23_reg)=data)
#define  get_RL_L0REFDMA_23_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_23_reg))

#define  RL_L0REFDMA_24                                                          0x1800E560
#define  RL_L0REFDMA_24_reg_addr                                                 "0xB800E560"
#define  RL_L0REFDMA_24_reg                                                      0xB800E560
#define  RL_L0REFDMA_24_inst_addr                                                "0x001E"
#define  RL_L0REFDMA_24_inst_adr                                                 "0x0058"
#define  RL_L0REFDMA_24_inst                                                     0x0058
#define  set_RL_L0REFDMA_24_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_24_reg)=data)
#define  get_RL_L0REFDMA_24_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_24_reg))

#define  RL_L0REFDMA_25                                                          0x1800E564
#define  RL_L0REFDMA_25_reg_addr                                                 "0xB800E564"
#define  RL_L0REFDMA_25_reg                                                      0xB800E564
#define  RL_L0REFDMA_25_inst_addr                                                "0x001F"
#define  RL_L0REFDMA_25_inst_adr                                                 "0x0059"
#define  RL_L0REFDMA_25_inst                                                     0x0059
#define  set_RL_L0REFDMA_25_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_25_reg)=data)
#define  get_RL_L0REFDMA_25_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_25_reg))

#define  RL_L0REFDMA_26                                                          0x1800E568
#define  RL_L0REFDMA_26_reg_addr                                                 "0xB800E568"
#define  RL_L0REFDMA_26_reg                                                      0xB800E568
#define  RL_L0REFDMA_26_inst_addr                                                "0x0020"
#define  RL_L0REFDMA_26_inst_adr                                                 "0x005A"
#define  RL_L0REFDMA_26_inst                                                     0x005A
#define  set_RL_L0REFDMA_26_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_26_reg)=data)
#define  get_RL_L0REFDMA_26_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_26_reg))

#define  RL_L0REFDMA_27                                                          0x1800E56C
#define  RL_L0REFDMA_27_reg_addr                                                 "0xB800E56C"
#define  RL_L0REFDMA_27_reg                                                      0xB800E56C
#define  RL_L0REFDMA_27_inst_addr                                                "0x0021"
#define  RL_L0REFDMA_27_inst_adr                                                 "0x005B"
#define  RL_L0REFDMA_27_inst                                                     0x005B
#define  set_RL_L0REFDMA_27_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_27_reg)=data)
#define  get_RL_L0REFDMA_27_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_27_reg))

#define  RL_L0REFDMA_28                                                          0x1800E570
#define  RL_L0REFDMA_28_reg_addr                                                 "0xB800E570"
#define  RL_L0REFDMA_28_reg                                                      0xB800E570
#define  RL_L0REFDMA_28_inst_addr                                                "0x0022"
#define  RL_L0REFDMA_28_inst_adr                                                 "0x005C"
#define  RL_L0REFDMA_28_inst                                                     0x005C
#define  set_RL_L0REFDMA_28_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_28_reg)=data)
#define  get_RL_L0REFDMA_28_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_28_reg))

#define  RL_L0REFDMA_29                                                          0x1800E574
#define  RL_L0REFDMA_29_reg_addr                                                 "0xB800E574"
#define  RL_L0REFDMA_29_reg                                                      0xB800E574
#define  RL_L0REFDMA_29_inst_addr                                                "0x0023"
#define  RL_L0REFDMA_29_inst_adr                                                 "0x005D"
#define  RL_L0REFDMA_29_inst                                                     0x005D
#define  set_RL_L0REFDMA_29_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_29_reg)=data)
#define  get_RL_L0REFDMA_29_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_29_reg))

#define  RL_L0REFDMA_30                                                          0x1800E578
#define  RL_L0REFDMA_30_reg_addr                                                 "0xB800E578"
#define  RL_L0REFDMA_30_reg                                                      0xB800E578
#define  RL_L0REFDMA_30_inst_addr                                                "0x0024"
#define  RL_L0REFDMA_30_inst_adr                                                 "0x005E"
#define  RL_L0REFDMA_30_inst                                                     0x005E
#define  set_RL_L0REFDMA_30_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_30_reg)=data)
#define  get_RL_L0REFDMA_30_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_30_reg))

#define  RL_L0REFDMA_31                                                          0x1800E57C
#define  RL_L0REFDMA_31_reg_addr                                                 "0xB800E57C"
#define  RL_L0REFDMA_31_reg                                                      0xB800E57C
#define  RL_L0REFDMA_31_inst_addr                                                "0x0025"
#define  RL_L0REFDMA_31_inst_adr                                                 "0x005F"
#define  RL_L0REFDMA_31_inst                                                     0x005F
#define  set_RL_L0REFDMA_31_reg(data)                                            (*((volatile unsigned int*)RL_L0REFDMA_31_reg)=data)
#define  get_RL_L0REFDMA_31_reg                                                  (*((volatile unsigned int*)RL_L0REFDMA_31_reg))

#define  RL_L1REFDMA_0                                                           0x1800E580
#define  RL_L1REFDMA_0_reg_addr                                                  "0xB800E580"
#define  RL_L1REFDMA_0_reg                                                       0xB800E580
#define  RL_L1REFDMA_0_inst_addr                                                 "0x0026"
#define  RL_L1REFDMA_0_inst_adr                                                  "0x0060"
#define  RL_L1REFDMA_0_inst                                                      0x0060
#define  set_RL_L1REFDMA_0_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_0_reg)=data)
#define  get_RL_L1REFDMA_0_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_0_reg))
#define  RL_L1REFDMA_ref_RANGEREDFRM_shift                                       (15)
#define  RL_L1REFDMA_bottom_field_flag_shift                                     (14)
#define  RL_L1REFDMA_lu_addr_index_shift                                         (7)
#define  RL_L1REFDMA_ch_addr_index_shift                                         (0)
#define  RL_L1REFDMA_ref_RANGEREDFRM_mask                                        (0x00008000)
#define  RL_L1REFDMA_bottom_field_flag_mask                                      (0x00004000)
#define  RL_L1REFDMA_lu_addr_index_mask                                          (0x00003F80)
#define  RL_L1REFDMA_ch_addr_index_mask                                          (0x0000007F)
#define  RL_L1REFDMA_ref_RANGEREDFRM(data)                                       (0x00008000&((data)<<15))
#define  RL_L1REFDMA_bottom_field_flag(data)                                     (0x00004000&((data)<<14))
#define  RL_L1REFDMA_lu_addr_index(data)                                         (0x00003F80&((data)<<7))
#define  RL_L1REFDMA_ch_addr_index(data)                                         (0x0000007F&(data))
#define  RL_L1REFDMA_get_ref_RANGEREDFRM(data)                                   ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_get_bottom_field_flag(data)                                 ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_get_lu_addr_index(data)                                     ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_get_ch_addr_index(data)                                     (0x0000007F&(data))
#define  RL_L1REFDMA_ref_RANGEREDFRM_src(data)                                   ((0x00008000&(data))>>15)
#define  RL_L1REFDMA_bottom_field_flag_src(data)                                 ((0x00004000&(data))>>14)
#define  RL_L1REFDMA_lu_addr_index_src(data)                                     ((0x00003F80&(data))>>7)
#define  RL_L1REFDMA_ch_addr_index_src(data)                                     (0x0000007F&(data))

#define  RL_L1REFDMA_1                                                           0x1800E584
#define  RL_L1REFDMA_1_reg_addr                                                  "0xB800E584"
#define  RL_L1REFDMA_1_reg                                                       0xB800E584
#define  RL_L1REFDMA_1_inst_addr                                                 "0x0027"
#define  RL_L1REFDMA_1_inst_adr                                                  "0x0061"
#define  RL_L1REFDMA_1_inst                                                      0x0061
#define  set_RL_L1REFDMA_1_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_1_reg)=data)
#define  get_RL_L1REFDMA_1_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_1_reg))

#define  RL_L1REFDMA_2                                                           0x1800E588
#define  RL_L1REFDMA_2_reg_addr                                                  "0xB800E588"
#define  RL_L1REFDMA_2_reg                                                       0xB800E588
#define  RL_L1REFDMA_2_inst_addr                                                 "0x0028"
#define  RL_L1REFDMA_2_inst_adr                                                  "0x0062"
#define  RL_L1REFDMA_2_inst                                                      0x0062
#define  set_RL_L1REFDMA_2_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_2_reg)=data)
#define  get_RL_L1REFDMA_2_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_2_reg))

#define  RL_L1REFDMA_3                                                           0x1800E58C
#define  RL_L1REFDMA_3_reg_addr                                                  "0xB800E58C"
#define  RL_L1REFDMA_3_reg                                                       0xB800E58C
#define  RL_L1REFDMA_3_inst_addr                                                 "0x0029"
#define  RL_L1REFDMA_3_inst_adr                                                  "0x0063"
#define  RL_L1REFDMA_3_inst                                                      0x0063
#define  set_RL_L1REFDMA_3_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_3_reg)=data)
#define  get_RL_L1REFDMA_3_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_3_reg))

#define  RL_L1REFDMA_4                                                           0x1800E590
#define  RL_L1REFDMA_4_reg_addr                                                  "0xB800E590"
#define  RL_L1REFDMA_4_reg                                                       0xB800E590
#define  RL_L1REFDMA_4_inst_addr                                                 "0x002A"
#define  RL_L1REFDMA_4_inst_adr                                                  "0x0064"
#define  RL_L1REFDMA_4_inst                                                      0x0064
#define  set_RL_L1REFDMA_4_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_4_reg)=data)
#define  get_RL_L1REFDMA_4_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_4_reg))

#define  RL_L1REFDMA_5                                                           0x1800E594
#define  RL_L1REFDMA_5_reg_addr                                                  "0xB800E594"
#define  RL_L1REFDMA_5_reg                                                       0xB800E594
#define  RL_L1REFDMA_5_inst_addr                                                 "0x002B"
#define  RL_L1REFDMA_5_inst_adr                                                  "0x0065"
#define  RL_L1REFDMA_5_inst                                                      0x0065
#define  set_RL_L1REFDMA_5_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_5_reg)=data)
#define  get_RL_L1REFDMA_5_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_5_reg))

#define  RL_L1REFDMA_6                                                           0x1800E598
#define  RL_L1REFDMA_6_reg_addr                                                  "0xB800E598"
#define  RL_L1REFDMA_6_reg                                                       0xB800E598
#define  RL_L1REFDMA_6_inst_addr                                                 "0x002C"
#define  RL_L1REFDMA_6_inst_adr                                                  "0x0066"
#define  RL_L1REFDMA_6_inst                                                      0x0066
#define  set_RL_L1REFDMA_6_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_6_reg)=data)
#define  get_RL_L1REFDMA_6_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_6_reg))

#define  RL_L1REFDMA_7                                                           0x1800E59C
#define  RL_L1REFDMA_7_reg_addr                                                  "0xB800E59C"
#define  RL_L1REFDMA_7_reg                                                       0xB800E59C
#define  RL_L1REFDMA_7_inst_addr                                                 "0x002D"
#define  RL_L1REFDMA_7_inst_adr                                                  "0x0067"
#define  RL_L1REFDMA_7_inst                                                      0x0067
#define  set_RL_L1REFDMA_7_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_7_reg)=data)
#define  get_RL_L1REFDMA_7_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_7_reg))

#define  RL_L1REFDMA_8                                                           0x1800E5A0
#define  RL_L1REFDMA_8_reg_addr                                                  "0xB800E5A0"
#define  RL_L1REFDMA_8_reg                                                       0xB800E5A0
#define  RL_L1REFDMA_8_inst_addr                                                 "0x002E"
#define  RL_L1REFDMA_8_inst_adr                                                  "0x0068"
#define  RL_L1REFDMA_8_inst                                                      0x0068
#define  set_RL_L1REFDMA_8_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_8_reg)=data)
#define  get_RL_L1REFDMA_8_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_8_reg))

#define  RL_L1REFDMA_9                                                           0x1800E5A4
#define  RL_L1REFDMA_9_reg_addr                                                  "0xB800E5A4"
#define  RL_L1REFDMA_9_reg                                                       0xB800E5A4
#define  RL_L1REFDMA_9_inst_addr                                                 "0x002F"
#define  RL_L1REFDMA_9_inst_adr                                                  "0x0069"
#define  RL_L1REFDMA_9_inst                                                      0x0069
#define  set_RL_L1REFDMA_9_reg(data)                                             (*((volatile unsigned int*)RL_L1REFDMA_9_reg)=data)
#define  get_RL_L1REFDMA_9_reg                                                   (*((volatile unsigned int*)RL_L1REFDMA_9_reg))

#define  RL_L1REFDMA_10                                                          0x1800E5A8
#define  RL_L1REFDMA_10_reg_addr                                                 "0xB800E5A8"
#define  RL_L1REFDMA_10_reg                                                      0xB800E5A8
#define  RL_L1REFDMA_10_inst_addr                                                "0x0030"
#define  RL_L1REFDMA_10_inst_adr                                                 "0x006A"
#define  RL_L1REFDMA_10_inst                                                     0x006A
#define  set_RL_L1REFDMA_10_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_10_reg)=data)
#define  get_RL_L1REFDMA_10_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_10_reg))

#define  RL_L1REFDMA_11                                                          0x1800E5AC
#define  RL_L1REFDMA_11_reg_addr                                                 "0xB800E5AC"
#define  RL_L1REFDMA_11_reg                                                      0xB800E5AC
#define  RL_L1REFDMA_11_inst_addr                                                "0x0031"
#define  RL_L1REFDMA_11_inst_adr                                                 "0x006B"
#define  RL_L1REFDMA_11_inst                                                     0x006B
#define  set_RL_L1REFDMA_11_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_11_reg)=data)
#define  get_RL_L1REFDMA_11_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_11_reg))

#define  RL_L1REFDMA_12                                                          0x1800E5B0
#define  RL_L1REFDMA_12_reg_addr                                                 "0xB800E5B0"
#define  RL_L1REFDMA_12_reg                                                      0xB800E5B0
#define  RL_L1REFDMA_12_inst_addr                                                "0x0032"
#define  RL_L1REFDMA_12_inst_adr                                                 "0x006C"
#define  RL_L1REFDMA_12_inst                                                     0x006C
#define  set_RL_L1REFDMA_12_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_12_reg)=data)
#define  get_RL_L1REFDMA_12_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_12_reg))

#define  RL_L1REFDMA_13                                                          0x1800E5B4
#define  RL_L1REFDMA_13_reg_addr                                                 "0xB800E5B4"
#define  RL_L1REFDMA_13_reg                                                      0xB800E5B4
#define  RL_L1REFDMA_13_inst_addr                                                "0x0033"
#define  RL_L1REFDMA_13_inst_adr                                                 "0x006D"
#define  RL_L1REFDMA_13_inst                                                     0x006D
#define  set_RL_L1REFDMA_13_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_13_reg)=data)
#define  get_RL_L1REFDMA_13_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_13_reg))

#define  RL_L1REFDMA_14                                                          0x1800E5B8
#define  RL_L1REFDMA_14_reg_addr                                                 "0xB800E5B8"
#define  RL_L1REFDMA_14_reg                                                      0xB800E5B8
#define  RL_L1REFDMA_14_inst_addr                                                "0x0034"
#define  RL_L1REFDMA_14_inst_adr                                                 "0x006E"
#define  RL_L1REFDMA_14_inst                                                     0x006E
#define  set_RL_L1REFDMA_14_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_14_reg)=data)
#define  get_RL_L1REFDMA_14_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_14_reg))

#define  RL_L1REFDMA_15                                                          0x1800E5BC
#define  RL_L1REFDMA_15_reg_addr                                                 "0xB800E5BC"
#define  RL_L1REFDMA_15_reg                                                      0xB800E5BC
#define  RL_L1REFDMA_15_inst_addr                                                "0x0035"
#define  RL_L1REFDMA_15_inst_adr                                                 "0x006F"
#define  RL_L1REFDMA_15_inst                                                     0x006F
#define  set_RL_L1REFDMA_15_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_15_reg)=data)
#define  get_RL_L1REFDMA_15_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_15_reg))

#define  RL_L1REFDMA_16                                                          0x1800E5C0
#define  RL_L1REFDMA_16_reg_addr                                                 "0xB800E5C0"
#define  RL_L1REFDMA_16_reg                                                      0xB800E5C0
#define  RL_L1REFDMA_16_inst_addr                                                "0x0036"
#define  RL_L1REFDMA_16_inst_adr                                                 "0x0070"
#define  RL_L1REFDMA_16_inst                                                     0x0070
#define  set_RL_L1REFDMA_16_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_16_reg)=data)
#define  get_RL_L1REFDMA_16_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_16_reg))

#define  RL_L1REFDMA_17                                                          0x1800E5C4
#define  RL_L1REFDMA_17_reg_addr                                                 "0xB800E5C4"
#define  RL_L1REFDMA_17_reg                                                      0xB800E5C4
#define  RL_L1REFDMA_17_inst_addr                                                "0x0037"
#define  RL_L1REFDMA_17_inst_adr                                                 "0x0071"
#define  RL_L1REFDMA_17_inst                                                     0x0071
#define  set_RL_L1REFDMA_17_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_17_reg)=data)
#define  get_RL_L1REFDMA_17_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_17_reg))

#define  RL_L1REFDMA_18                                                          0x1800E5C8
#define  RL_L1REFDMA_18_reg_addr                                                 "0xB800E5C8"
#define  RL_L1REFDMA_18_reg                                                      0xB800E5C8
#define  RL_L1REFDMA_18_inst_addr                                                "0x0038"
#define  RL_L1REFDMA_18_inst_adr                                                 "0x0072"
#define  RL_L1REFDMA_18_inst                                                     0x0072
#define  set_RL_L1REFDMA_18_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_18_reg)=data)
#define  get_RL_L1REFDMA_18_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_18_reg))

#define  RL_L1REFDMA_19                                                          0x1800E5CC
#define  RL_L1REFDMA_19_reg_addr                                                 "0xB800E5CC"
#define  RL_L1REFDMA_19_reg                                                      0xB800E5CC
#define  RL_L1REFDMA_19_inst_addr                                                "0x0039"
#define  RL_L1REFDMA_19_inst_adr                                                 "0x0073"
#define  RL_L1REFDMA_19_inst                                                     0x0073
#define  set_RL_L1REFDMA_19_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_19_reg)=data)
#define  get_RL_L1REFDMA_19_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_19_reg))

#define  RL_L1REFDMA_20                                                          0x1800E5D0
#define  RL_L1REFDMA_20_reg_addr                                                 "0xB800E5D0"
#define  RL_L1REFDMA_20_reg                                                      0xB800E5D0
#define  RL_L1REFDMA_20_inst_addr                                                "0x003A"
#define  RL_L1REFDMA_20_inst_adr                                                 "0x0074"
#define  RL_L1REFDMA_20_inst                                                     0x0074
#define  set_RL_L1REFDMA_20_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_20_reg)=data)
#define  get_RL_L1REFDMA_20_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_20_reg))

#define  RL_L1REFDMA_21                                                          0x1800E5D4
#define  RL_L1REFDMA_21_reg_addr                                                 "0xB800E5D4"
#define  RL_L1REFDMA_21_reg                                                      0xB800E5D4
#define  RL_L1REFDMA_21_inst_addr                                                "0x003B"
#define  RL_L1REFDMA_21_inst_adr                                                 "0x0075"
#define  RL_L1REFDMA_21_inst                                                     0x0075
#define  set_RL_L1REFDMA_21_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_21_reg)=data)
#define  get_RL_L1REFDMA_21_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_21_reg))

#define  RL_L1REFDMA_22                                                          0x1800E5D8
#define  RL_L1REFDMA_22_reg_addr                                                 "0xB800E5D8"
#define  RL_L1REFDMA_22_reg                                                      0xB800E5D8
#define  RL_L1REFDMA_22_inst_addr                                                "0x003C"
#define  RL_L1REFDMA_22_inst_adr                                                 "0x0076"
#define  RL_L1REFDMA_22_inst                                                     0x0076
#define  set_RL_L1REFDMA_22_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_22_reg)=data)
#define  get_RL_L1REFDMA_22_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_22_reg))

#define  RL_L1REFDMA_23                                                          0x1800E5DC
#define  RL_L1REFDMA_23_reg_addr                                                 "0xB800E5DC"
#define  RL_L1REFDMA_23_reg                                                      0xB800E5DC
#define  RL_L1REFDMA_23_inst_addr                                                "0x003D"
#define  RL_L1REFDMA_23_inst_adr                                                 "0x0077"
#define  RL_L1REFDMA_23_inst                                                     0x0077
#define  set_RL_L1REFDMA_23_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_23_reg)=data)
#define  get_RL_L1REFDMA_23_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_23_reg))

#define  RL_L1REFDMA_24                                                          0x1800E5E0
#define  RL_L1REFDMA_24_reg_addr                                                 "0xB800E5E0"
#define  RL_L1REFDMA_24_reg                                                      0xB800E5E0
#define  RL_L1REFDMA_24_inst_addr                                                "0x003E"
#define  RL_L1REFDMA_24_inst_adr                                                 "0x0078"
#define  RL_L1REFDMA_24_inst                                                     0x0078
#define  set_RL_L1REFDMA_24_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_24_reg)=data)
#define  get_RL_L1REFDMA_24_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_24_reg))

#define  RL_L1REFDMA_25                                                          0x1800E5E4
#define  RL_L1REFDMA_25_reg_addr                                                 "0xB800E5E4"
#define  RL_L1REFDMA_25_reg                                                      0xB800E5E4
#define  RL_L1REFDMA_25_inst_addr                                                "0x003F"
#define  RL_L1REFDMA_25_inst_adr                                                 "0x0079"
#define  RL_L1REFDMA_25_inst                                                     0x0079
#define  set_RL_L1REFDMA_25_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_25_reg)=data)
#define  get_RL_L1REFDMA_25_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_25_reg))

#define  RL_L1REFDMA_26                                                          0x1800E5E8
#define  RL_L1REFDMA_26_reg_addr                                                 "0xB800E5E8"
#define  RL_L1REFDMA_26_reg                                                      0xB800E5E8
#define  RL_L1REFDMA_26_inst_addr                                                "0x0040"
#define  RL_L1REFDMA_26_inst_adr                                                 "0x007A"
#define  RL_L1REFDMA_26_inst                                                     0x007A
#define  set_RL_L1REFDMA_26_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_26_reg)=data)
#define  get_RL_L1REFDMA_26_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_26_reg))

#define  RL_L1REFDMA_27                                                          0x1800E5EC
#define  RL_L1REFDMA_27_reg_addr                                                 "0xB800E5EC"
#define  RL_L1REFDMA_27_reg                                                      0xB800E5EC
#define  RL_L1REFDMA_27_inst_addr                                                "0x0041"
#define  RL_L1REFDMA_27_inst_adr                                                 "0x007B"
#define  RL_L1REFDMA_27_inst                                                     0x007B
#define  set_RL_L1REFDMA_27_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_27_reg)=data)
#define  get_RL_L1REFDMA_27_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_27_reg))

#define  RL_L1REFDMA_28                                                          0x1800E5F0
#define  RL_L1REFDMA_28_reg_addr                                                 "0xB800E5F0"
#define  RL_L1REFDMA_28_reg                                                      0xB800E5F0
#define  RL_L1REFDMA_28_inst_addr                                                "0x0042"
#define  RL_L1REFDMA_28_inst_adr                                                 "0x007C"
#define  RL_L1REFDMA_28_inst                                                     0x007C
#define  set_RL_L1REFDMA_28_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_28_reg)=data)
#define  get_RL_L1REFDMA_28_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_28_reg))

#define  RL_L1REFDMA_29                                                          0x1800E5F4
#define  RL_L1REFDMA_29_reg_addr                                                 "0xB800E5F4"
#define  RL_L1REFDMA_29_reg                                                      0xB800E5F4
#define  RL_L1REFDMA_29_inst_addr                                                "0x0043"
#define  RL_L1REFDMA_29_inst_adr                                                 "0x007D"
#define  RL_L1REFDMA_29_inst                                                     0x007D
#define  set_RL_L1REFDMA_29_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_29_reg)=data)
#define  get_RL_L1REFDMA_29_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_29_reg))

#define  RL_L1REFDMA_30                                                          0x1800E5F8
#define  RL_L1REFDMA_30_reg_addr                                                 "0xB800E5F8"
#define  RL_L1REFDMA_30_reg                                                      0xB800E5F8
#define  RL_L1REFDMA_30_inst_addr                                                "0x0044"
#define  RL_L1REFDMA_30_inst_adr                                                 "0x007E"
#define  RL_L1REFDMA_30_inst                                                     0x007E
#define  set_RL_L1REFDMA_30_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_30_reg)=data)
#define  get_RL_L1REFDMA_30_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_30_reg))

#define  RL_L1REFDMA_31                                                          0x1800E5FC
#define  RL_L1REFDMA_31_reg_addr                                                 "0xB800E5FC"
#define  RL_L1REFDMA_31_reg                                                      0xB800E5FC
#define  RL_L1REFDMA_31_inst_addr                                                "0x0045"
#define  RL_L1REFDMA_31_inst_adr                                                 "0x007F"
#define  RL_L1REFDMA_31_inst                                                     0x007F
#define  set_RL_L1REFDMA_31_reg(data)                                            (*((volatile unsigned int*)RL_L1REFDMA_31_reg)=data)
#define  get_RL_L1REFDMA_31_reg                                                  (*((volatile unsigned int*)RL_L1REFDMA_31_reg))

#define  RL_DBG_SEL                                                              0x1800EC18
#define  RL_DBG_SEL_reg_addr                                                     "0xB800EC18"
#define  RL_DBG_SEL_reg                                                          0xB800EC18
#define  RL_DBG_SEL_inst_addr                                                    "0x0046"
#define  RL_DBG_SEL_inst_adr                                                     "0x0006"
#define  RL_DBG_SEL_inst                                                         0x0006
#define  set_RL_DBG_SEL_reg(data)                                                (*((volatile unsigned int*)RL_DBG_SEL_reg)=data)
#define  get_RL_DBG_SEL_reg                                                      (*((volatile unsigned int*)RL_DBG_SEL_reg))
#define  RL_DBG_SEL_write_enable3_shift                                          (31)
#define  RL_DBG_SEL_Trigger_status_shift                                         (30)
#define  RL_DBG_SEL_Zero_w_lr_shift                                              (28)
#define  RL_DBG_SEL_write_enable2_shift                                          (27)
#define  RL_DBG_SEL_Trigger_select_shift                                         (23)
#define  RL_DBG_SEL_Trigger_cond_mb_x_shift                                      (12)
#define  RL_DBG_SEL_Trigger_cond_mb_y_shift                                      (4)
#define  RL_DBG_SEL_write_enable1_shift                                          (3)
#define  RL_DBG_SEL_Debug_port_sel_shift                                         (0)
#define  RL_DBG_SEL_write_enable3_mask                                           (0x80000000)
#define  RL_DBG_SEL_Trigger_status_mask                                          (0x40000000)
#define  RL_DBG_SEL_Zero_w_lr_mask                                               (0x30000000)
#define  RL_DBG_SEL_write_enable2_mask                                           (0x08000000)
#define  RL_DBG_SEL_Trigger_select_mask                                          (0x07800000)
#define  RL_DBG_SEL_Trigger_cond_mb_x_mask                                       (0x001FF000)
#define  RL_DBG_SEL_Trigger_cond_mb_y_mask                                       (0x00000FF0)
#define  RL_DBG_SEL_write_enable1_mask                                           (0x00000008)
#define  RL_DBG_SEL_Debug_port_sel_mask                                          (0x00000007)
#define  RL_DBG_SEL_write_enable3(data)                                          (0x80000000&((data)<<31))
#define  RL_DBG_SEL_Trigger_status(data)                                         (0x40000000&((data)<<30))
#define  RL_DBG_SEL_Zero_w_lr(data)                                              (0x30000000&((data)<<28))
#define  RL_DBG_SEL_write_enable2(data)                                          (0x08000000&((data)<<27))
#define  RL_DBG_SEL_Trigger_select(data)                                         (0x07800000&((data)<<23))
#define  RL_DBG_SEL_Trigger_cond_mb_x(data)                                      (0x001FF000&((data)<<12))
#define  RL_DBG_SEL_Trigger_cond_mb_y(data)                                      (0x00000FF0&((data)<<4))
#define  RL_DBG_SEL_write_enable1(data)                                          (0x00000008&((data)<<3))
#define  RL_DBG_SEL_Debug_port_sel(data)                                         (0x00000007&(data))
#define  RL_DBG_SEL_get_write_enable3(data)                                      ((0x80000000&(data))>>31)
#define  RL_DBG_SEL_get_Trigger_status(data)                                     ((0x40000000&(data))>>30)
#define  RL_DBG_SEL_get_Zero_w_lr(data)                                          ((0x30000000&(data))>>28)
#define  RL_DBG_SEL_get_write_enable2(data)                                      ((0x08000000&(data))>>27)
#define  RL_DBG_SEL_get_Trigger_select(data)                                     ((0x07800000&(data))>>23)
#define  RL_DBG_SEL_get_Trigger_cond_mb_x(data)                                  ((0x001FF000&(data))>>12)
#define  RL_DBG_SEL_get_Trigger_cond_mb_y(data)                                  ((0x00000FF0&(data))>>4)
#define  RL_DBG_SEL_get_write_enable1(data)                                      ((0x00000008&(data))>>3)
#define  RL_DBG_SEL_get_Debug_port_sel(data)                                     (0x00000007&(data))
#define  RL_DBG_SEL_write_enable3_src(data)                                      ((0x80000000&(data))>>31)
#define  RL_DBG_SEL_Trigger_status_src(data)                                     ((0x40000000&(data))>>30)
#define  RL_DBG_SEL_Zero_w_lr_src(data)                                          ((0x30000000&(data))>>28)
#define  RL_DBG_SEL_write_enable2_src(data)                                      ((0x08000000&(data))>>27)
#define  RL_DBG_SEL_Trigger_select_src(data)                                     ((0x07800000&(data))>>23)
#define  RL_DBG_SEL_Trigger_cond_mb_x_src(data)                                  ((0x001FF000&(data))>>12)
#define  RL_DBG_SEL_Trigger_cond_mb_y_src(data)                                  ((0x00000FF0&(data))>>4)
#define  RL_DBG_SEL_write_enable1_src(data)                                      ((0x00000008&(data))>>3)
#define  RL_DBG_SEL_Debug_port_sel_src(data)                                     (0x00000007&(data))

#define  RL_DBG_STS0                                                             0x1800EC1C
#define  RL_DBG_STS0_reg_addr                                                    "0xB800EC1C"
#define  RL_DBG_STS0_reg                                                         0xB800EC1C
#define  RL_DBG_STS0_inst_addr                                                   "0x0047"
#define  RL_DBG_STS0_inst_adr                                                    "0x0007"
#define  RL_DBG_STS0_inst                                                        0x0007
#define  set_RL_DBG_STS0_reg(data)                                               (*((volatile unsigned int*)RL_DBG_STS0_reg)=data)
#define  get_RL_DBG_STS0_reg                                                     (*((volatile unsigned int*)RL_DBG_STS0_reg))
#define  RL_DBG_STS0_Tbl_cnt_shift                                               (16)
#define  RL_DBG_STS0_Trigger_tbl_cnt_shift                                       (0)
#define  RL_DBG_STS0_Tbl_cnt_mask                                                (0xFFFF0000)
#define  RL_DBG_STS0_Trigger_tbl_cnt_mask                                        (0x0000FFFF)
#define  RL_DBG_STS0_Tbl_cnt(data)                                               (0xFFFF0000&((data)<<16))
#define  RL_DBG_STS0_Trigger_tbl_cnt(data)                                       (0x0000FFFF&(data))
#define  RL_DBG_STS0_get_Tbl_cnt(data)                                           ((0xFFFF0000&(data))>>16)
#define  RL_DBG_STS0_get_Trigger_tbl_cnt(data)                                   (0x0000FFFF&(data))
#define  RL_DBG_STS0_Tbl_cnt_src(data)                                           ((0xFFFF0000&(data))>>16)
#define  RL_DBG_STS0_Trigger_tbl_cnt_src(data)                                   (0x0000FFFF&(data))

#define  RL_DBG_STS1                                                             0x1800EC20
#define  RL_DBG_STS1_reg_addr                                                    "0xB800EC20"
#define  RL_DBG_STS1_reg                                                         0xB800EC20
#define  RL_DBG_STS1_inst_addr                                                   "0x0048"
#define  RL_DBG_STS1_inst_adr                                                    "0x0008"
#define  RL_DBG_STS1_inst                                                        0x0008
#define  set_RL_DBG_STS1_reg(data)                                               (*((volatile unsigned int*)RL_DBG_STS1_reg)=data)
#define  get_RL_DBG_STS1_reg                                                     (*((volatile unsigned int*)RL_DBG_STS1_reg))
#define  RL_DBG_STS1_DBG_STS_shift                                               (0)
#define  RL_DBG_STS1_DBG_STS_mask                                                (0xFFFFFFFF)
#define  RL_DBG_STS1_DBG_STS(data)                                               (0xFFFFFFFF&(data))
#define  RL_DBG_STS1_get_DBG_STS(data)                                           (0xFFFFFFFF&(data))
#define  RL_DBG_STS1_DBG_STS_src(data)                                           (0xFFFFFFFF&(data))

#define  RL_DBG_STS2                                                             0x1800EC24
#define  RL_DBG_STS2_reg_addr                                                    "0xB800EC24"
#define  RL_DBG_STS2_reg                                                         0xB800EC24
#define  RL_DBG_STS2_inst_addr                                                   "0x0049"
#define  RL_DBG_STS2_inst_adr                                                    "0x0009"
#define  RL_DBG_STS2_inst                                                        0x0009
#define  set_RL_DBG_STS2_reg(data)                                               (*((volatile unsigned int*)RL_DBG_STS2_reg)=data)
#define  get_RL_DBG_STS2_reg                                                     (*((volatile unsigned int*)RL_DBG_STS2_reg))
#define  RL_DBG_STS2_DBG_STS_shift                                               (0)
#define  RL_DBG_STS2_DBG_STS_mask                                                (0xFFFFFFFF)
#define  RL_DBG_STS2_DBG_STS(data)                                               (0xFFFFFFFF&(data))
#define  RL_DBG_STS2_get_DBG_STS(data)                                           (0xFFFFFFFF&(data))
#define  RL_DBG_STS2_DBG_STS_src(data)                                           (0xFFFFFFFF&(data))

#define  RL_INTR_THRES                                                           0x1800EC28
#define  RL_INTR_THRES_reg_addr                                                  "0xB800EC28"
#define  RL_INTR_THRES_reg                                                       0xB800EC28
#define  RL_INTR_THRES_inst_addr                                                 "0x004A"
#define  RL_INTR_THRES_inst_adr                                                  "0x000A"
#define  RL_INTR_THRES_inst                                                      0x000A
#define  set_RL_INTR_THRES_reg(data)                                             (*((volatile unsigned int*)RL_INTR_THRES_reg)=data)
#define  get_RL_INTR_THRES_reg                                                   (*((volatile unsigned int*)RL_INTR_THRES_reg))
#define  RL_INTR_THRES_Intr_shift                                                (28)
#define  RL_INTR_THRES_Value_shift                                               (0)
#define  RL_INTR_THRES_Intr_mask                                                 (0x10000000)
#define  RL_INTR_THRES_Value_mask                                                (0x0FFFFFFF)
#define  RL_INTR_THRES_Intr(data)                                                (0x10000000&((data)<<28))
#define  RL_INTR_THRES_Value(data)                                               (0x0FFFFFFF&(data))
#define  RL_INTR_THRES_get_Intr(data)                                            ((0x10000000&(data))>>28)
#define  RL_INTR_THRES_get_Value(data)                                           (0x0FFFFFFF&(data))
#define  RL_INTR_THRES_Intr_src(data)                                            ((0x10000000&(data))>>28)
#define  RL_INTR_THRES_Value_src(data)                                           (0x0FFFFFFF&(data))

#define  RL_MVBUF_WADD                                                           0x1800EC80
#define  RL_MVBUF_WADD_reg_addr                                                  "0xB800EC80"
#define  RL_MVBUF_WADD_reg                                                       0xB800EC80
#define  RL_MVBUF_WADD_inst_addr                                                 "0x004B"
#define  RL_MVBUF_WADD_inst_adr                                                  "0x0020"
#define  RL_MVBUF_WADD_inst                                                      0x0020
#define  set_RL_MVBUF_WADD_reg(data)                                             (*((volatile unsigned int*)RL_MVBUF_WADD_reg)=data)
#define  get_RL_MVBUF_WADD_reg                                                   (*((volatile unsigned int*)RL_MVBUF_WADD_reg))
#define  RL_MVBUF_WADD_MVBUF_write_address_shift                                 (0)
#define  RL_MVBUF_WADD_MVBUF_write_address_mask                                  (0x0000007F)
#define  RL_MVBUF_WADD_MVBUF_write_address(data)                                 (0x0000007F&(data))
#define  RL_MVBUF_WADD_get_MVBUF_write_address(data)                             (0x0000007F&(data))
#define  RL_MVBUF_WADD_MVBUF_write_address_src(data)                             (0x0000007F&(data))

#define  RL_MVBUF_DATA_0                                                         0x1800EC84
#define  RL_MVBUF_DATA_0_reg_addr                                                "0xB800EC84"
#define  RL_MVBUF_DATA_0_reg                                                     0xB800EC84
#define  RL_MVBUF_DATA_0_inst_addr                                               "0x004C"
#define  RL_MVBUF_DATA_0_inst_adr                                                "0x0021"
#define  RL_MVBUF_DATA_0_inst                                                    0x0021
#define  set_RL_MVBUF_DATA_0_reg(data)                                           (*((volatile unsigned int*)RL_MVBUF_DATA_0_reg)=data)
#define  get_RL_MVBUF_DATA_0_reg                                                 (*((volatile unsigned int*)RL_MVBUF_DATA_0_reg))
#define  RL_MVBUF_DATA_MVBUF_read_write_data_shift                               (0)
#define  RL_MVBUF_DATA_MVBUF_read_write_data_mask                                (0xFFFFFFFF)
#define  RL_MVBUF_DATA_MVBUF_read_write_data(data)                               (0xFFFFFFFF&(data))
#define  RL_MVBUF_DATA_get_MVBUF_read_write_data(data)                           (0xFFFFFFFF&(data))
#define  RL_MVBUF_DATA_MVBUF_read_write_data_src(data)                           (0xFFFFFFFF&(data))

#define  RL_MVBUF_DATA_1                                                         0x1800EC88
#define  RL_MVBUF_DATA_1_reg_addr                                                "0xB800EC88"
#define  RL_MVBUF_DATA_1_reg                                                     0xB800EC88
#define  RL_MVBUF_DATA_1_inst_addr                                               "0x004D"
#define  RL_MVBUF_DATA_1_inst_adr                                                "0x0022"
#define  RL_MVBUF_DATA_1_inst                                                    0x0022
#define  set_RL_MVBUF_DATA_1_reg(data)                                           (*((volatile unsigned int*)RL_MVBUF_DATA_1_reg)=data)
#define  get_RL_MVBUF_DATA_1_reg                                                 (*((volatile unsigned int*)RL_MVBUF_DATA_1_reg))

#define  RL_MVBUF_DATA_2                                                         0x1800EC8C
#define  RL_MVBUF_DATA_2_reg_addr                                                "0xB800EC8C"
#define  RL_MVBUF_DATA_2_reg                                                     0xB800EC8C
#define  RL_MVBUF_DATA_2_inst_addr                                               "0x004E"
#define  RL_MVBUF_DATA_2_inst_adr                                                "0x0023"
#define  RL_MVBUF_DATA_2_inst                                                    0x0023
#define  set_RL_MVBUF_DATA_2_reg(data)                                           (*((volatile unsigned int*)RL_MVBUF_DATA_2_reg)=data)
#define  get_RL_MVBUF_DATA_2_reg                                                 (*((volatile unsigned int*)RL_MVBUF_DATA_2_reg))

#define  RL_MVBUF_RADD                                                           0x1800EC90
#define  RL_MVBUF_RADD_reg_addr                                                  "0xB800EC90"
#define  RL_MVBUF_RADD_reg                                                       0xB800EC90
#define  RL_MVBUF_RADD_inst_addr                                                 "0x004F"
#define  RL_MVBUF_RADD_inst_adr                                                  "0x0024"
#define  RL_MVBUF_RADD_inst                                                      0x0024
#define  set_RL_MVBUF_RADD_reg(data)                                             (*((volatile unsigned int*)RL_MVBUF_RADD_reg)=data)
#define  get_RL_MVBUF_RADD_reg                                                   (*((volatile unsigned int*)RL_MVBUF_RADD_reg))
#define  RL_MVBUF_RADD_MVBUF_read_address_shift                                  (0)
#define  RL_MVBUF_RADD_MVBUF_read_address_mask                                   (0x0000007F)
#define  RL_MVBUF_RADD_MVBUF_read_address(data)                                  (0x0000007F&(data))
#define  RL_MVBUF_RADD_get_MVBUF_read_address(data)                              (0x0000007F&(data))
#define  RL_MVBUF_RADD_MVBUF_read_address_src(data)                              (0x0000007F&(data))

#define  RL_MVBUF_STS0                                                           0x1800EC94
#define  RL_MVBUF_STS0_reg_addr                                                  "0xB800EC94"
#define  RL_MVBUF_STS0_reg                                                       0xB800EC94
#define  RL_MVBUF_STS0_inst_addr                                                 "0x0050"
#define  RL_MVBUF_STS0_inst_adr                                                  "0x0025"
#define  RL_MVBUF_STS0_inst                                                      0x0025
#define  set_RL_MVBUF_STS0_reg(data)                                             (*((volatile unsigned int*)RL_MVBUF_STS0_reg)=data)
#define  get_RL_MVBUF_STS0_reg                                                   (*((volatile unsigned int*)RL_MVBUF_STS0_reg))
#define  RL_MVBUF_STS0_write_enable2_shift                                       (22)
#define  RL_MVBUF_STS0_MVBUF_hdr_shift                                           (12)
#define  RL_MVBUF_STS0_write_enable1_shift                                       (11)
#define  RL_MVBUF_STS0_MVBUF_mvd_wptr_shift                                      (0)
#define  RL_MVBUF_STS0_write_enable2_mask                                        (0x00400000)
#define  RL_MVBUF_STS0_MVBUF_hdr_mask                                            (0x003FF000)
#define  RL_MVBUF_STS0_write_enable1_mask                                        (0x00000800)
#define  RL_MVBUF_STS0_MVBUF_mvd_wptr_mask                                       (0x000007FF)
#define  RL_MVBUF_STS0_write_enable2(data)                                       (0x00400000&((data)<<22))
#define  RL_MVBUF_STS0_MVBUF_hdr(data)                                           (0x003FF000&((data)<<12))
#define  RL_MVBUF_STS0_write_enable1(data)                                       (0x00000800&((data)<<11))
#define  RL_MVBUF_STS0_MVBUF_mvd_wptr(data)                                      (0x000007FF&(data))
#define  RL_MVBUF_STS0_get_write_enable2(data)                                   ((0x00400000&(data))>>22)
#define  RL_MVBUF_STS0_get_MVBUF_hdr(data)                                       ((0x003FF000&(data))>>12)
#define  RL_MVBUF_STS0_get_write_enable1(data)                                   ((0x00000800&(data))>>11)
#define  RL_MVBUF_STS0_get_MVBUF_mvd_wptr(data)                                  (0x000007FF&(data))
#define  RL_MVBUF_STS0_write_enable2_src(data)                                   ((0x00400000&(data))>>22)
#define  RL_MVBUF_STS0_MVBUF_hdr_src(data)                                       ((0x003FF000&(data))>>12)
#define  RL_MVBUF_STS0_write_enable1_src(data)                                   ((0x00000800&(data))>>11)
#define  RL_MVBUF_STS0_MVBUF_mvd_wptr_src(data)                                  (0x000007FF&(data))

#define  RL_MVBUF_STS1                                                           0x1800EC98
#define  RL_MVBUF_STS1_reg_addr                                                  "0xB800EC98"
#define  RL_MVBUF_STS1_reg                                                       0xB800EC98
#define  RL_MVBUF_STS1_inst_addr                                                 "0x0051"
#define  RL_MVBUF_STS1_inst_adr                                                  "0x0026"
#define  RL_MVBUF_STS1_inst                                                      0x0026
#define  set_RL_MVBUF_STS1_reg(data)                                             (*((volatile unsigned int*)RL_MVBUF_STS1_reg)=data)
#define  get_RL_MVBUF_STS1_reg                                                   (*((volatile unsigned int*)RL_MVBUF_STS1_reg))
#define  RL_MVBUF_STS1_write_enable2_shift                                       (23)
#define  RL_MVBUF_STS1_MVBUF_pred_rptr_shift                                     (12)
#define  RL_MVBUF_STS1_write_enable11_shift                                      (11)
#define  RL_MVBUF_STS1_MVBUF_rl_rptr_shift                                       (0)
#define  RL_MVBUF_STS1_write_enable2_mask                                        (0x00800000)
#define  RL_MVBUF_STS1_MVBUF_pred_rptr_mask                                      (0x007FF000)
#define  RL_MVBUF_STS1_write_enable11_mask                                       (0x00000800)
#define  RL_MVBUF_STS1_MVBUF_rl_rptr_mask                                        (0x000007FF)
#define  RL_MVBUF_STS1_write_enable2(data)                                       (0x00800000&((data)<<23))
#define  RL_MVBUF_STS1_MVBUF_pred_rptr(data)                                     (0x007FF000&((data)<<12))
#define  RL_MVBUF_STS1_write_enable11(data)                                      (0x00000800&((data)<<11))
#define  RL_MVBUF_STS1_MVBUF_rl_rptr(data)                                       (0x000007FF&(data))
#define  RL_MVBUF_STS1_get_write_enable2(data)                                   ((0x00800000&(data))>>23)
#define  RL_MVBUF_STS1_get_MVBUF_pred_rptr(data)                                 ((0x007FF000&(data))>>12)
#define  RL_MVBUF_STS1_get_write_enable11(data)                                  ((0x00000800&(data))>>11)
#define  RL_MVBUF_STS1_get_MVBUF_rl_rptr(data)                                   (0x000007FF&(data))
#define  RL_MVBUF_STS1_write_enable2_src(data)                                   ((0x00800000&(data))>>23)
#define  RL_MVBUF_STS1_MVBUF_pred_rptr_src(data)                                 ((0x007FF000&(data))>>12)
#define  RL_MVBUF_STS1_write_enable11_src(data)                                  ((0x00000800&(data))>>11)
#define  RL_MVBUF_STS1_MVBUF_rl_rptr_src(data)                                   (0x000007FF&(data))

#define  RL_CACHE_SET                                                            0x1800EC9C
#define  RL_CACHE_SET_reg_addr                                                   "0xB800EC9C"
#define  RL_CACHE_SET_reg                                                        0xB800EC9C
#define  RL_CACHE_SET_inst_addr                                                  "0x0052"
#define  RL_CACHE_SET_inst_adr                                                   "0x0027"
#define  RL_CACHE_SET_inst                                                       0x0027
#define  set_RL_CACHE_SET_reg(data)                                              (*((volatile unsigned int*)RL_CACHE_SET_reg)=data)
#define  get_RL_CACHE_SET_reg                                                    (*((volatile unsigned int*)RL_CACHE_SET_reg))
#define  RL_CACHE_SET_write_enable3_shift                                        (7)
#define  RL_CACHE_SET_Hdr_ref_pic_cnt_shift                                      (6)
#define  RL_CACHE_SET_write_enable2_shift                                        (5)
#define  RL_CACHE_SET_Vg_en_shift                                                (3)
#define  RL_CACHE_SET_write_enable1_shift                                        (2)
#define  RL_CACHE_SET_Ref_pic_cnt_shift                                          (0)
#define  RL_CACHE_SET_write_enable3_mask                                         (0x00000080)
#define  RL_CACHE_SET_Hdr_ref_pic_cnt_mask                                       (0x00000040)
#define  RL_CACHE_SET_write_enable2_mask                                         (0x00000020)
#define  RL_CACHE_SET_Vg_en_mask                                                 (0x00000018)
#define  RL_CACHE_SET_write_enable1_mask                                         (0x00000004)
#define  RL_CACHE_SET_Ref_pic_cnt_mask                                           (0x00000003)
#define  RL_CACHE_SET_write_enable3(data)                                        (0x00000080&((data)<<7))
#define  RL_CACHE_SET_Hdr_ref_pic_cnt(data)                                      (0x00000040&((data)<<6))
#define  RL_CACHE_SET_write_enable2(data)                                        (0x00000020&((data)<<5))
#define  RL_CACHE_SET_Vg_en(data)                                                (0x00000018&((data)<<3))
#define  RL_CACHE_SET_write_enable1(data)                                        (0x00000004&((data)<<2))
#define  RL_CACHE_SET_Ref_pic_cnt(data)                                          (0x00000003&(data))
#define  RL_CACHE_SET_get_write_enable3(data)                                    ((0x00000080&(data))>>7)
#define  RL_CACHE_SET_get_Hdr_ref_pic_cnt(data)                                  ((0x00000040&(data))>>6)
#define  RL_CACHE_SET_get_write_enable2(data)                                    ((0x00000020&(data))>>5)
#define  RL_CACHE_SET_get_Vg_en(data)                                            ((0x00000018&(data))>>3)
#define  RL_CACHE_SET_get_write_enable1(data)                                    ((0x00000004&(data))>>2)
#define  RL_CACHE_SET_get_Ref_pic_cnt(data)                                      (0x00000003&(data))
#define  RL_CACHE_SET_write_enable3_src(data)                                    ((0x00000080&(data))>>7)
#define  RL_CACHE_SET_Hdr_ref_pic_cnt_src(data)                                  ((0x00000040&(data))>>6)
#define  RL_CACHE_SET_write_enable2_src(data)                                    ((0x00000020&(data))>>5)
#define  RL_CACHE_SET_Vg_en_src(data)                                            ((0x00000018&(data))>>3)
#define  RL_CACHE_SET_write_enable1_src(data)                                    ((0x00000004&(data))>>2)
#define  RL_CACHE_SET_Ref_pic_cnt_src(data)                                      (0x00000003&(data))

#define  RL_CACHE_EN                                                             0x1800ECA0
#define  RL_CACHE_EN_reg_addr                                                    "0xB800ECA0"
#define  RL_CACHE_EN_reg                                                         0xB800ECA0
#define  RL_CACHE_EN_inst_addr                                                   "0x0053"
#define  RL_CACHE_EN_inst_adr                                                    "0x0028"
#define  RL_CACHE_EN_inst                                                        0x0028
#define  set_RL_CACHE_EN_reg(data)                                               (*((volatile unsigned int*)RL_CACHE_EN_reg)=data)
#define  get_RL_CACHE_EN_reg                                                     (*((volatile unsigned int*)RL_CACHE_EN_reg))
#define  RL_CACHE_EN_Hdr_cah_en_shift                                            (1)
#define  RL_CACHE_EN_Cah_en_shift                                                (0)
#define  RL_CACHE_EN_Hdr_cah_en_mask                                             (0x00000002)
#define  RL_CACHE_EN_Cah_en_mask                                                 (0x00000001)
#define  RL_CACHE_EN_Hdr_cah_en(data)                                            (0x00000002&((data)<<1))
#define  RL_CACHE_EN_Cah_en(data)                                                (0x00000001&(data))
#define  RL_CACHE_EN_get_Hdr_cah_en(data)                                        ((0x00000002&(data))>>1)
#define  RL_CACHE_EN_get_Cah_en(data)                                            (0x00000001&(data))
#define  RL_CACHE_EN_Hdr_cah_en_src(data)                                        ((0x00000002&(data))>>1)
#define  RL_CACHE_EN_Cah_en_src(data)                                            (0x00000001&(data))

#define  RL_CACHE_INV                                                            0x1800ECA4
#define  RL_CACHE_INV_reg_addr                                                   "0xB800ECA4"
#define  RL_CACHE_INV_reg                                                        0xB800ECA4
#define  RL_CACHE_INV_inst_addr                                                  "0x0054"
#define  RL_CACHE_INV_inst_adr                                                   "0x0029"
#define  RL_CACHE_INV_inst                                                       0x0029
#define  set_RL_CACHE_INV_reg(data)                                              (*((volatile unsigned int*)RL_CACHE_INV_reg)=data)
#define  get_RL_CACHE_INV_reg                                                    (*((volatile unsigned int*)RL_CACHE_INV_reg))
#define  RL_CACHE_INV_Hdr_cah_inv_shift                                          (1)
#define  RL_CACHE_INV_Cah_inv_shift                                              (0)
#define  RL_CACHE_INV_Hdr_cah_inv_mask                                           (0x00000002)
#define  RL_CACHE_INV_Cah_inv_mask                                               (0x00000001)
#define  RL_CACHE_INV_Hdr_cah_inv(data)                                          (0x00000002&((data)<<1))
#define  RL_CACHE_INV_Cah_inv(data)                                              (0x00000001&(data))
#define  RL_CACHE_INV_get_Hdr_cah_inv(data)                                      ((0x00000002&(data))>>1)
#define  RL_CACHE_INV_get_Cah_inv(data)                                          (0x00000001&(data))
#define  RL_CACHE_INV_Hdr_cah_inv_src(data)                                      ((0x00000002&(data))>>1)
#define  RL_CACHE_INV_Cah_inv_src(data)                                          (0x00000001&(data))

#define  RL_CAH_PINDX                                                            0x1800ECA8
#define  RL_CAH_PINDX_reg_addr                                                   "0xB800ECA8"
#define  RL_CAH_PINDX_reg                                                        0xB800ECA8
#define  RL_CAH_PINDX_inst_addr                                                  "0x0055"
#define  RL_CAH_PINDX_inst_adr                                                   "0x002A"
#define  RL_CAH_PINDX_inst                                                       0x002A
#define  set_RL_CAH_PINDX_reg(data)                                              (*((volatile unsigned int*)RL_CAH_PINDX_reg)=data)
#define  get_RL_CAH_PINDX_reg                                                    (*((volatile unsigned int*)RL_CAH_PINDX_reg))
#define  RL_CAH_PINDX_Cah_pindx0_LumL0_shift                                     (24)
#define  RL_CAH_PINDX_Cah_pindx1_LumL1_shift                                     (16)
#define  RL_CAH_PINDX_Cah_pindx2_ChrL0_shift                                     (8)
#define  RL_CAH_PINDX_Cah_pindx3_ChrL1_shift                                     (0)
#define  RL_CAH_PINDX_Cah_pindx0_LumL0_mask                                      (0xFF000000)
#define  RL_CAH_PINDX_Cah_pindx1_LumL1_mask                                      (0x00FF0000)
#define  RL_CAH_PINDX_Cah_pindx2_ChrL0_mask                                      (0x0000FF00)
#define  RL_CAH_PINDX_Cah_pindx3_ChrL1_mask                                      (0x000000FF)
#define  RL_CAH_PINDX_Cah_pindx0_LumL0(data)                                     (0xFF000000&((data)<<24))
#define  RL_CAH_PINDX_Cah_pindx1_LumL1(data)                                     (0x00FF0000&((data)<<16))
#define  RL_CAH_PINDX_Cah_pindx2_ChrL0(data)                                     (0x0000FF00&((data)<<8))
#define  RL_CAH_PINDX_Cah_pindx3_ChrL1(data)                                     (0x000000FF&(data))
#define  RL_CAH_PINDX_get_Cah_pindx0_LumL0(data)                                 ((0xFF000000&(data))>>24)
#define  RL_CAH_PINDX_get_Cah_pindx1_LumL1(data)                                 ((0x00FF0000&(data))>>16)
#define  RL_CAH_PINDX_get_Cah_pindx2_ChrL0(data)                                 ((0x0000FF00&(data))>>8)
#define  RL_CAH_PINDX_get_Cah_pindx3_ChrL1(data)                                 (0x000000FF&(data))
#define  RL_CAH_PINDX_Cah_pindx0_LumL0_src(data)                                 ((0xFF000000&(data))>>24)
#define  RL_CAH_PINDX_Cah_pindx1_LumL1_src(data)                                 ((0x00FF0000&(data))>>16)
#define  RL_CAH_PINDX_Cah_pindx2_ChrL0_src(data)                                 ((0x0000FF00&(data))>>8)
#define  RL_CAH_PINDX_Cah_pindx3_ChrL1_src(data)                                 (0x000000FF&(data))

#define  RL_HDR_CAH_PINDX_EXT_LUMA                                               0x1800ECAC
#define  RL_HDR_CAH_PINDX_EXT_LUMA_reg_addr                                      "0xB800ECAC"
#define  RL_HDR_CAH_PINDX_EXT_LUMA_reg                                           0xB800ECAC
#define  RL_HDR_CAH_PINDX_EXT_LUMA_inst_addr                                     "0x0056"
#define  RL_HDR_CAH_PINDX_EXT_LUMA_inst_adr                                      "0x002B"
#define  RL_HDR_CAH_PINDX_EXT_LUMA_inst                                          0x002B
#define  set_RL_HDR_CAH_PINDX_EXT_LUMA_reg(data)                                 (*((volatile unsigned int*)RL_HDR_CAH_PINDX_EXT_LUMA_reg)=data)
#define  get_RL_HDR_CAH_PINDX_EXT_LUMA_reg                                       (*((volatile unsigned int*)RL_HDR_CAH_PINDX_EXT_LUMA_reg))
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum0_shift                      (24)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum1_shift                      (16)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum2_shift                      (8)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum3_shift                      (0)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum0_mask                       (0xFF000000)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum1_mask                       (0x00FF0000)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum2_mask                       (0x0000FF00)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum3_mask                       (0x000000FF)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum0(data)                      (0xFF000000&((data)<<24))
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum1(data)                      (0x00FF0000&((data)<<16))
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum2(data)                      (0x0000FF00&((data)<<8))
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum3(data)                      (0x000000FF&(data))
#define  RL_HDR_CAH_PINDX_EXT_LUMA_get_Ext_cah_pindx_Lum0(data)                  ((0xFF000000&(data))>>24)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_get_Ext_cah_pindx_Lum1(data)                  ((0x00FF0000&(data))>>16)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_get_Ext_cah_pindx_Lum2(data)                  ((0x0000FF00&(data))>>8)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_get_Ext_cah_pindx_Lum3(data)                  (0x000000FF&(data))
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum0_src(data)                  ((0xFF000000&(data))>>24)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum1_src(data)                  ((0x00FF0000&(data))>>16)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum2_src(data)                  ((0x0000FF00&(data))>>8)
#define  RL_HDR_CAH_PINDX_EXT_LUMA_Ext_cah_pindx_Lum3_src(data)                  (0x000000FF&(data))

#define  RL_HDR_CAH_PINDX_EXT_CHROMA                                             0x1800ECB0
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_reg_addr                                    "0xB800ECB0"
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_reg                                         0xB800ECB0
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_inst_addr                                   "0x0057"
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_inst_adr                                    "0x002C"
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_inst                                        0x002C
#define  set_RL_HDR_CAH_PINDX_EXT_CHROMA_reg(data)                               (*((volatile unsigned int*)RL_HDR_CAH_PINDX_EXT_CHROMA_reg)=data)
#define  get_RL_HDR_CAH_PINDX_EXT_CHROMA_reg                                     (*((volatile unsigned int*)RL_HDR_CAH_PINDX_EXT_CHROMA_reg))
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr0_shift                    (24)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr1_shift                    (16)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr2_shift                    (8)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr3_shift                    (0)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr0_mask                     (0xFF000000)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr1_mask                     (0x00FF0000)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr2_mask                     (0x0000FF00)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr3_mask                     (0x000000FF)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr0(data)                    (0xFF000000&((data)<<24))
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr1(data)                    (0x00FF0000&((data)<<16))
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr2(data)                    (0x0000FF00&((data)<<8))
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr3(data)                    (0x000000FF&(data))
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_get_Ext_cah_pindx_Chr0(data)                ((0xFF000000&(data))>>24)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_get_Ext_cah_pindx_Chr1(data)                ((0x00FF0000&(data))>>16)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_get_Ext_cah_pindx_Chr2(data)                ((0x0000FF00&(data))>>8)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_get_Ext_cah_pindx_Chr3(data)                (0x000000FF&(data))
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr0_src(data)                ((0xFF000000&(data))>>24)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr1_src(data)                ((0x00FF0000&(data))>>16)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr2_src(data)                ((0x0000FF00&(data))>>8)
#define  RL_HDR_CAH_PINDX_EXT_CHROMA_Ext_cah_pindx_Chr3_src(data)                (0x000000FF&(data))

#define  RL_SCALE_PIC_0                                                          0x1800ECB4
#define  RL_SCALE_PIC_0_reg_addr                                                 "0xB800ECB4"
#define  RL_SCALE_PIC_0_reg                                                      0xB800ECB4
#define  RL_SCALE_PIC_0_inst_addr                                                "0x0058"
#define  RL_SCALE_PIC_0_inst_adr                                                 "0x002D"
#define  RL_SCALE_PIC_0_inst                                                     0x002D
#define  set_RL_SCALE_PIC_0_reg(data)                                            (*((volatile unsigned int*)RL_SCALE_PIC_0_reg)=data)
#define  get_RL_SCALE_PIC_0_reg                                                  (*((volatile unsigned int*)RL_SCALE_PIC_0_reg))
#define  RL_SCALE_PIC_disppic_h_shift                                            (16)
#define  RL_SCALE_PIC_disppic_w_shift                                            (0)
#define  RL_SCALE_PIC_disppic_h_mask                                             (0x1FFF0000)
#define  RL_SCALE_PIC_disppic_w_mask                                             (0x00003FFF)
#define  RL_SCALE_PIC_disppic_h(data)                                            (0x1FFF0000&((data)<<16))
#define  RL_SCALE_PIC_disppic_w(data)                                            (0x00003FFF&(data))
#define  RL_SCALE_PIC_get_disppic_h(data)                                        ((0x1FFF0000&(data))>>16)
#define  RL_SCALE_PIC_get_disppic_w(data)                                        (0x00003FFF&(data))
#define  RL_SCALE_PIC_disppic_h_src(data)                                        ((0x1FFF0000&(data))>>16)
#define  RL_SCALE_PIC_disppic_w_src(data)                                        (0x00003FFF&(data))

#define  RL_SCALE_PIC_1                                                          0x1800ECB8
#define  RL_SCALE_PIC_1_reg_addr                                                 "0xB800ECB8"
#define  RL_SCALE_PIC_1_reg                                                      0xB800ECB8
#define  RL_SCALE_PIC_1_inst_addr                                                "0x0059"
#define  RL_SCALE_PIC_1_inst_adr                                                 "0x002E"
#define  RL_SCALE_PIC_1_inst                                                     0x002E
#define  set_RL_SCALE_PIC_1_reg(data)                                            (*((volatile unsigned int*)RL_SCALE_PIC_1_reg)=data)
#define  get_RL_SCALE_PIC_1_reg                                                  (*((volatile unsigned int*)RL_SCALE_PIC_1_reg))

#define  RL_SCALE_PIC_2                                                          0x1800ECBC
#define  RL_SCALE_PIC_2_reg_addr                                                 "0xB800ECBC"
#define  RL_SCALE_PIC_2_reg                                                      0xB800ECBC
#define  RL_SCALE_PIC_2_inst_addr                                                "0x005A"
#define  RL_SCALE_PIC_2_inst_adr                                                 "0x002F"
#define  RL_SCALE_PIC_2_inst                                                     0x002F
#define  set_RL_SCALE_PIC_2_reg(data)                                            (*((volatile unsigned int*)RL_SCALE_PIC_2_reg)=data)
#define  get_RL_SCALE_PIC_2_reg                                                  (*((volatile unsigned int*)RL_SCALE_PIC_2_reg))

#define  RL_HDR_STR_ADDR_LU_0                                                    0x1800ED00
#define  RL_HDR_STR_ADDR_LU_0_reg_addr                                           "0xB800ED00"
#define  RL_HDR_STR_ADDR_LU_0_reg                                                0xB800ED00
#define  RL_HDR_STR_ADDR_LU_0_inst_addr                                          "0x005B"
#define  RL_HDR_STR_ADDR_LU_0_inst_adr                                           "0x0040"
#define  RL_HDR_STR_ADDR_LU_0_inst                                               0x0040
#define  set_RL_HDR_STR_ADDR_LU_0_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_0_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_0_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_0_reg))
#define  RL_HDR_STR_ADDR_LU_Hdr_str_addr_lu_shift                                (0)
#define  RL_HDR_STR_ADDR_LU_Hdr_str_addr_lu_mask                                 (0xFFFFFFFF)
#define  RL_HDR_STR_ADDR_LU_Hdr_str_addr_lu(data)                                (0xFFFFFFFF&(data))
#define  RL_HDR_STR_ADDR_LU_get_Hdr_str_addr_lu(data)                            (0xFFFFFFFF&(data))
#define  RL_HDR_STR_ADDR_LU_Hdr_str_addr_lu_src(data)                            (0xFFFFFFFF&(data))

#define  RL_HDR_STR_ADDR_LU_1                                                    0x1800ED04
#define  RL_HDR_STR_ADDR_LU_1_reg_addr                                           "0xB800ED04"
#define  RL_HDR_STR_ADDR_LU_1_reg                                                0xB800ED04
#define  RL_HDR_STR_ADDR_LU_1_inst_addr                                          "0x005C"
#define  RL_HDR_STR_ADDR_LU_1_inst_adr                                           "0x0041"
#define  RL_HDR_STR_ADDR_LU_1_inst                                               0x0041
#define  set_RL_HDR_STR_ADDR_LU_1_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_1_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_1_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_1_reg))

#define  RL_HDR_STR_ADDR_LU_2                                                    0x1800ED08
#define  RL_HDR_STR_ADDR_LU_2_reg_addr                                           "0xB800ED08"
#define  RL_HDR_STR_ADDR_LU_2_reg                                                0xB800ED08
#define  RL_HDR_STR_ADDR_LU_2_inst_addr                                          "0x005D"
#define  RL_HDR_STR_ADDR_LU_2_inst_adr                                           "0x0042"
#define  RL_HDR_STR_ADDR_LU_2_inst                                               0x0042
#define  set_RL_HDR_STR_ADDR_LU_2_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_2_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_2_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_2_reg))

#define  RL_HDR_STR_ADDR_LU_3                                                    0x1800ED0C
#define  RL_HDR_STR_ADDR_LU_3_reg_addr                                           "0xB800ED0C"
#define  RL_HDR_STR_ADDR_LU_3_reg                                                0xB800ED0C
#define  RL_HDR_STR_ADDR_LU_3_inst_addr                                          "0x005E"
#define  RL_HDR_STR_ADDR_LU_3_inst_adr                                           "0x0043"
#define  RL_HDR_STR_ADDR_LU_3_inst                                               0x0043
#define  set_RL_HDR_STR_ADDR_LU_3_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_3_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_3_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_3_reg))

#define  RL_HDR_STR_ADDR_LU_4                                                    0x1800ED10
#define  RL_HDR_STR_ADDR_LU_4_reg_addr                                           "0xB800ED10"
#define  RL_HDR_STR_ADDR_LU_4_reg                                                0xB800ED10
#define  RL_HDR_STR_ADDR_LU_4_inst_addr                                          "0x005F"
#define  RL_HDR_STR_ADDR_LU_4_inst_adr                                           "0x0044"
#define  RL_HDR_STR_ADDR_LU_4_inst                                               0x0044
#define  set_RL_HDR_STR_ADDR_LU_4_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_4_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_4_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_4_reg))

#define  RL_HDR_STR_ADDR_LU_5                                                    0x1800ED14
#define  RL_HDR_STR_ADDR_LU_5_reg_addr                                           "0xB800ED14"
#define  RL_HDR_STR_ADDR_LU_5_reg                                                0xB800ED14
#define  RL_HDR_STR_ADDR_LU_5_inst_addr                                          "0x0060"
#define  RL_HDR_STR_ADDR_LU_5_inst_adr                                           "0x0045"
#define  RL_HDR_STR_ADDR_LU_5_inst                                               0x0045
#define  set_RL_HDR_STR_ADDR_LU_5_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_5_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_5_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_5_reg))

#define  RL_HDR_STR_ADDR_LU_6                                                    0x1800ED18
#define  RL_HDR_STR_ADDR_LU_6_reg_addr                                           "0xB800ED18"
#define  RL_HDR_STR_ADDR_LU_6_reg                                                0xB800ED18
#define  RL_HDR_STR_ADDR_LU_6_inst_addr                                          "0x0061"
#define  RL_HDR_STR_ADDR_LU_6_inst_adr                                           "0x0046"
#define  RL_HDR_STR_ADDR_LU_6_inst                                               0x0046
#define  set_RL_HDR_STR_ADDR_LU_6_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_6_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_6_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_6_reg))

#define  RL_HDR_STR_ADDR_LU_7                                                    0x1800ED1C
#define  RL_HDR_STR_ADDR_LU_7_reg_addr                                           "0xB800ED1C"
#define  RL_HDR_STR_ADDR_LU_7_reg                                                0xB800ED1C
#define  RL_HDR_STR_ADDR_LU_7_inst_addr                                          "0x0062"
#define  RL_HDR_STR_ADDR_LU_7_inst_adr                                           "0x0047"
#define  RL_HDR_STR_ADDR_LU_7_inst                                               0x0047
#define  set_RL_HDR_STR_ADDR_LU_7_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_7_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_7_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_7_reg))

#define  RL_HDR_STR_ADDR_LU_8                                                    0x1800ED20
#define  RL_HDR_STR_ADDR_LU_8_reg_addr                                           "0xB800ED20"
#define  RL_HDR_STR_ADDR_LU_8_reg                                                0xB800ED20
#define  RL_HDR_STR_ADDR_LU_8_inst_addr                                          "0x0063"
#define  RL_HDR_STR_ADDR_LU_8_inst_adr                                           "0x0048"
#define  RL_HDR_STR_ADDR_LU_8_inst                                               0x0048
#define  set_RL_HDR_STR_ADDR_LU_8_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_8_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_8_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_8_reg))

#define  RL_HDR_STR_ADDR_LU_9                                                    0x1800ED24
#define  RL_HDR_STR_ADDR_LU_9_reg_addr                                           "0xB800ED24"
#define  RL_HDR_STR_ADDR_LU_9_reg                                                0xB800ED24
#define  RL_HDR_STR_ADDR_LU_9_inst_addr                                          "0x0064"
#define  RL_HDR_STR_ADDR_LU_9_inst_adr                                           "0x0049"
#define  RL_HDR_STR_ADDR_LU_9_inst                                               0x0049
#define  set_RL_HDR_STR_ADDR_LU_9_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_9_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_9_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_9_reg))

#define  RL_HDR_STR_ADDR_LU_10                                                   0x1800ED28
#define  RL_HDR_STR_ADDR_LU_10_reg_addr                                          "0xB800ED28"
#define  RL_HDR_STR_ADDR_LU_10_reg                                               0xB800ED28
#define  RL_HDR_STR_ADDR_LU_10_inst_addr                                         "0x0065"
#define  RL_HDR_STR_ADDR_LU_10_inst_adr                                          "0x004A"
#define  RL_HDR_STR_ADDR_LU_10_inst                                              0x004A
#define  set_RL_HDR_STR_ADDR_LU_10_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_10_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_10_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_10_reg))

#define  RL_HDR_STR_ADDR_LU_11                                                   0x1800ED2C
#define  RL_HDR_STR_ADDR_LU_11_reg_addr                                          "0xB800ED2C"
#define  RL_HDR_STR_ADDR_LU_11_reg                                               0xB800ED2C
#define  RL_HDR_STR_ADDR_LU_11_inst_addr                                         "0x0066"
#define  RL_HDR_STR_ADDR_LU_11_inst_adr                                          "0x004B"
#define  RL_HDR_STR_ADDR_LU_11_inst                                              0x004B
#define  set_RL_HDR_STR_ADDR_LU_11_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_11_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_11_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_11_reg))

#define  RL_HDR_STR_ADDR_LU_12                                                   0x1800ED30
#define  RL_HDR_STR_ADDR_LU_12_reg_addr                                          "0xB800ED30"
#define  RL_HDR_STR_ADDR_LU_12_reg                                               0xB800ED30
#define  RL_HDR_STR_ADDR_LU_12_inst_addr                                         "0x0067"
#define  RL_HDR_STR_ADDR_LU_12_inst_adr                                          "0x004C"
#define  RL_HDR_STR_ADDR_LU_12_inst                                              0x004C
#define  set_RL_HDR_STR_ADDR_LU_12_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_12_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_12_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_12_reg))

#define  RL_HDR_STR_ADDR_LU_13                                                   0x1800ED34
#define  RL_HDR_STR_ADDR_LU_13_reg_addr                                          "0xB800ED34"
#define  RL_HDR_STR_ADDR_LU_13_reg                                               0xB800ED34
#define  RL_HDR_STR_ADDR_LU_13_inst_addr                                         "0x0068"
#define  RL_HDR_STR_ADDR_LU_13_inst_adr                                          "0x004D"
#define  RL_HDR_STR_ADDR_LU_13_inst                                              0x004D
#define  set_RL_HDR_STR_ADDR_LU_13_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_13_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_13_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_13_reg))

#define  RL_HDR_STR_ADDR_LU_14                                                   0x1800ED38
#define  RL_HDR_STR_ADDR_LU_14_reg_addr                                          "0xB800ED38"
#define  RL_HDR_STR_ADDR_LU_14_reg                                               0xB800ED38
#define  RL_HDR_STR_ADDR_LU_14_inst_addr                                         "0x0069"
#define  RL_HDR_STR_ADDR_LU_14_inst_adr                                          "0x004E"
#define  RL_HDR_STR_ADDR_LU_14_inst                                              0x004E
#define  set_RL_HDR_STR_ADDR_LU_14_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_14_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_14_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_14_reg))

#define  RL_HDR_STR_ADDR_LU_15                                                   0x1800ED3C
#define  RL_HDR_STR_ADDR_LU_15_reg_addr                                          "0xB800ED3C"
#define  RL_HDR_STR_ADDR_LU_15_reg                                               0xB800ED3C
#define  RL_HDR_STR_ADDR_LU_15_inst_addr                                         "0x006A"
#define  RL_HDR_STR_ADDR_LU_15_inst_adr                                          "0x004F"
#define  RL_HDR_STR_ADDR_LU_15_inst                                              0x004F
#define  set_RL_HDR_STR_ADDR_LU_15_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_15_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_15_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_15_reg))

#define  RL_HDR_STR_ADDR_LU_16                                                   0x1800ED40
#define  RL_HDR_STR_ADDR_LU_16_reg_addr                                          "0xB800ED40"
#define  RL_HDR_STR_ADDR_LU_16_reg                                               0xB800ED40
#define  RL_HDR_STR_ADDR_LU_16_inst_addr                                         "0x006B"
#define  RL_HDR_STR_ADDR_LU_16_inst_adr                                          "0x0050"
#define  RL_HDR_STR_ADDR_LU_16_inst                                              0x0050
#define  set_RL_HDR_STR_ADDR_LU_16_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_16_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_16_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_16_reg))

#define  RL_HDR_STR_ADDR_LU_17                                                   0x1800ED44
#define  RL_HDR_STR_ADDR_LU_17_reg_addr                                          "0xB800ED44"
#define  RL_HDR_STR_ADDR_LU_17_reg                                               0xB800ED44
#define  RL_HDR_STR_ADDR_LU_17_inst_addr                                         "0x006C"
#define  RL_HDR_STR_ADDR_LU_17_inst_adr                                          "0x0051"
#define  RL_HDR_STR_ADDR_LU_17_inst                                              0x0051
#define  set_RL_HDR_STR_ADDR_LU_17_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_17_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_17_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_17_reg))

#define  RL_HDR_STR_ADDR_LU_18                                                   0x1800ED48
#define  RL_HDR_STR_ADDR_LU_18_reg_addr                                          "0xB800ED48"
#define  RL_HDR_STR_ADDR_LU_18_reg                                               0xB800ED48
#define  RL_HDR_STR_ADDR_LU_18_inst_addr                                         "0x006D"
#define  RL_HDR_STR_ADDR_LU_18_inst_adr                                          "0x0052"
#define  RL_HDR_STR_ADDR_LU_18_inst                                              0x0052
#define  set_RL_HDR_STR_ADDR_LU_18_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_18_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_18_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_18_reg))

#define  RL_HDR_STR_ADDR_LU_19                                                   0x1800ED4C
#define  RL_HDR_STR_ADDR_LU_19_reg_addr                                          "0xB800ED4C"
#define  RL_HDR_STR_ADDR_LU_19_reg                                               0xB800ED4C
#define  RL_HDR_STR_ADDR_LU_19_inst_addr                                         "0x006E"
#define  RL_HDR_STR_ADDR_LU_19_inst_adr                                          "0x0053"
#define  RL_HDR_STR_ADDR_LU_19_inst                                              0x0053
#define  set_RL_HDR_STR_ADDR_LU_19_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_19_reg)=data)
#define  get_RL_HDR_STR_ADDR_LU_19_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_LU_19_reg))

#define  RL_HDR_STR_ADDR_CH_0                                                    0x1800ED50
#define  RL_HDR_STR_ADDR_CH_0_reg_addr                                           "0xB800ED50"
#define  RL_HDR_STR_ADDR_CH_0_reg                                                0xB800ED50
#define  RL_HDR_STR_ADDR_CH_0_inst_addr                                          "0x006F"
#define  RL_HDR_STR_ADDR_CH_0_inst_adr                                           "0x0054"
#define  RL_HDR_STR_ADDR_CH_0_inst                                               0x0054
#define  set_RL_HDR_STR_ADDR_CH_0_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_0_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_0_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_0_reg))
#define  RL_HDR_STR_ADDR_CH_Hdr_str_addr_ch_shift                                (0)
#define  RL_HDR_STR_ADDR_CH_Hdr_str_addr_ch_mask                                 (0xFFFFFFFF)
#define  RL_HDR_STR_ADDR_CH_Hdr_str_addr_ch(data)                                (0xFFFFFFFF&(data))
#define  RL_HDR_STR_ADDR_CH_get_Hdr_str_addr_ch(data)                            (0xFFFFFFFF&(data))
#define  RL_HDR_STR_ADDR_CH_Hdr_str_addr_ch_src(data)                            (0xFFFFFFFF&(data))

#define  RL_HDR_STR_ADDR_CH_1                                                    0x1800ED54
#define  RL_HDR_STR_ADDR_CH_1_reg_addr                                           "0xB800ED54"
#define  RL_HDR_STR_ADDR_CH_1_reg                                                0xB800ED54
#define  RL_HDR_STR_ADDR_CH_1_inst_addr                                          "0x0070"
#define  RL_HDR_STR_ADDR_CH_1_inst_adr                                           "0x0055"
#define  RL_HDR_STR_ADDR_CH_1_inst                                               0x0055
#define  set_RL_HDR_STR_ADDR_CH_1_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_1_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_1_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_1_reg))

#define  RL_HDR_STR_ADDR_CH_2                                                    0x1800ED58
#define  RL_HDR_STR_ADDR_CH_2_reg_addr                                           "0xB800ED58"
#define  RL_HDR_STR_ADDR_CH_2_reg                                                0xB800ED58
#define  RL_HDR_STR_ADDR_CH_2_inst_addr                                          "0x0071"
#define  RL_HDR_STR_ADDR_CH_2_inst_adr                                           "0x0056"
#define  RL_HDR_STR_ADDR_CH_2_inst                                               0x0056
#define  set_RL_HDR_STR_ADDR_CH_2_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_2_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_2_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_2_reg))

#define  RL_HDR_STR_ADDR_CH_3                                                    0x1800ED5C
#define  RL_HDR_STR_ADDR_CH_3_reg_addr                                           "0xB800ED5C"
#define  RL_HDR_STR_ADDR_CH_3_reg                                                0xB800ED5C
#define  RL_HDR_STR_ADDR_CH_3_inst_addr                                          "0x0072"
#define  RL_HDR_STR_ADDR_CH_3_inst_adr                                           "0x0057"
#define  RL_HDR_STR_ADDR_CH_3_inst                                               0x0057
#define  set_RL_HDR_STR_ADDR_CH_3_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_3_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_3_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_3_reg))

#define  RL_HDR_STR_ADDR_CH_4                                                    0x1800ED60
#define  RL_HDR_STR_ADDR_CH_4_reg_addr                                           "0xB800ED60"
#define  RL_HDR_STR_ADDR_CH_4_reg                                                0xB800ED60
#define  RL_HDR_STR_ADDR_CH_4_inst_addr                                          "0x0073"
#define  RL_HDR_STR_ADDR_CH_4_inst_adr                                           "0x0058"
#define  RL_HDR_STR_ADDR_CH_4_inst                                               0x0058
#define  set_RL_HDR_STR_ADDR_CH_4_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_4_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_4_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_4_reg))

#define  RL_HDR_STR_ADDR_CH_5                                                    0x1800ED64
#define  RL_HDR_STR_ADDR_CH_5_reg_addr                                           "0xB800ED64"
#define  RL_HDR_STR_ADDR_CH_5_reg                                                0xB800ED64
#define  RL_HDR_STR_ADDR_CH_5_inst_addr                                          "0x0074"
#define  RL_HDR_STR_ADDR_CH_5_inst_adr                                           "0x0059"
#define  RL_HDR_STR_ADDR_CH_5_inst                                               0x0059
#define  set_RL_HDR_STR_ADDR_CH_5_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_5_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_5_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_5_reg))

#define  RL_HDR_STR_ADDR_CH_6                                                    0x1800ED68
#define  RL_HDR_STR_ADDR_CH_6_reg_addr                                           "0xB800ED68"
#define  RL_HDR_STR_ADDR_CH_6_reg                                                0xB800ED68
#define  RL_HDR_STR_ADDR_CH_6_inst_addr                                          "0x0075"
#define  RL_HDR_STR_ADDR_CH_6_inst_adr                                           "0x005A"
#define  RL_HDR_STR_ADDR_CH_6_inst                                               0x005A
#define  set_RL_HDR_STR_ADDR_CH_6_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_6_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_6_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_6_reg))

#define  RL_HDR_STR_ADDR_CH_7                                                    0x1800ED6C
#define  RL_HDR_STR_ADDR_CH_7_reg_addr                                           "0xB800ED6C"
#define  RL_HDR_STR_ADDR_CH_7_reg                                                0xB800ED6C
#define  RL_HDR_STR_ADDR_CH_7_inst_addr                                          "0x0076"
#define  RL_HDR_STR_ADDR_CH_7_inst_adr                                           "0x005B"
#define  RL_HDR_STR_ADDR_CH_7_inst                                               0x005B
#define  set_RL_HDR_STR_ADDR_CH_7_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_7_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_7_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_7_reg))

#define  RL_HDR_STR_ADDR_CH_8                                                    0x1800ED70
#define  RL_HDR_STR_ADDR_CH_8_reg_addr                                           "0xB800ED70"
#define  RL_HDR_STR_ADDR_CH_8_reg                                                0xB800ED70
#define  RL_HDR_STR_ADDR_CH_8_inst_addr                                          "0x0077"
#define  RL_HDR_STR_ADDR_CH_8_inst_adr                                           "0x005C"
#define  RL_HDR_STR_ADDR_CH_8_inst                                               0x005C
#define  set_RL_HDR_STR_ADDR_CH_8_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_8_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_8_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_8_reg))

#define  RL_HDR_STR_ADDR_CH_9                                                    0x1800ED74
#define  RL_HDR_STR_ADDR_CH_9_reg_addr                                           "0xB800ED74"
#define  RL_HDR_STR_ADDR_CH_9_reg                                                0xB800ED74
#define  RL_HDR_STR_ADDR_CH_9_inst_addr                                          "0x0078"
#define  RL_HDR_STR_ADDR_CH_9_inst_adr                                           "0x005D"
#define  RL_HDR_STR_ADDR_CH_9_inst                                               0x005D
#define  set_RL_HDR_STR_ADDR_CH_9_reg(data)                                      (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_9_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_9_reg                                            (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_9_reg))

#define  RL_HDR_STR_ADDR_CH_10                                                   0x1800ED78
#define  RL_HDR_STR_ADDR_CH_10_reg_addr                                          "0xB800ED78"
#define  RL_HDR_STR_ADDR_CH_10_reg                                               0xB800ED78
#define  RL_HDR_STR_ADDR_CH_10_inst_addr                                         "0x0079"
#define  RL_HDR_STR_ADDR_CH_10_inst_adr                                          "0x005E"
#define  RL_HDR_STR_ADDR_CH_10_inst                                              0x005E
#define  set_RL_HDR_STR_ADDR_CH_10_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_10_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_10_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_10_reg))

#define  RL_HDR_STR_ADDR_CH_11                                                   0x1800ED7C
#define  RL_HDR_STR_ADDR_CH_11_reg_addr                                          "0xB800ED7C"
#define  RL_HDR_STR_ADDR_CH_11_reg                                               0xB800ED7C
#define  RL_HDR_STR_ADDR_CH_11_inst_addr                                         "0x007A"
#define  RL_HDR_STR_ADDR_CH_11_inst_adr                                          "0x005F"
#define  RL_HDR_STR_ADDR_CH_11_inst                                              0x005F
#define  set_RL_HDR_STR_ADDR_CH_11_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_11_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_11_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_11_reg))

#define  RL_HDR_STR_ADDR_CH_12                                                   0x1800ED80
#define  RL_HDR_STR_ADDR_CH_12_reg_addr                                          "0xB800ED80"
#define  RL_HDR_STR_ADDR_CH_12_reg                                               0xB800ED80
#define  RL_HDR_STR_ADDR_CH_12_inst_addr                                         "0x007B"
#define  RL_HDR_STR_ADDR_CH_12_inst_adr                                          "0x0060"
#define  RL_HDR_STR_ADDR_CH_12_inst                                              0x0060
#define  set_RL_HDR_STR_ADDR_CH_12_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_12_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_12_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_12_reg))

#define  RL_HDR_STR_ADDR_CH_13                                                   0x1800ED84
#define  RL_HDR_STR_ADDR_CH_13_reg_addr                                          "0xB800ED84"
#define  RL_HDR_STR_ADDR_CH_13_reg                                               0xB800ED84
#define  RL_HDR_STR_ADDR_CH_13_inst_addr                                         "0x007C"
#define  RL_HDR_STR_ADDR_CH_13_inst_adr                                          "0x0061"
#define  RL_HDR_STR_ADDR_CH_13_inst                                              0x0061
#define  set_RL_HDR_STR_ADDR_CH_13_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_13_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_13_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_13_reg))

#define  RL_HDR_STR_ADDR_CH_14                                                   0x1800ED88
#define  RL_HDR_STR_ADDR_CH_14_reg_addr                                          "0xB800ED88"
#define  RL_HDR_STR_ADDR_CH_14_reg                                               0xB800ED88
#define  RL_HDR_STR_ADDR_CH_14_inst_addr                                         "0x007D"
#define  RL_HDR_STR_ADDR_CH_14_inst_adr                                          "0x0062"
#define  RL_HDR_STR_ADDR_CH_14_inst                                              0x0062
#define  set_RL_HDR_STR_ADDR_CH_14_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_14_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_14_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_14_reg))

#define  RL_HDR_STR_ADDR_CH_15                                                   0x1800ED8C
#define  RL_HDR_STR_ADDR_CH_15_reg_addr                                          "0xB800ED8C"
#define  RL_HDR_STR_ADDR_CH_15_reg                                               0xB800ED8C
#define  RL_HDR_STR_ADDR_CH_15_inst_addr                                         "0x007E"
#define  RL_HDR_STR_ADDR_CH_15_inst_adr                                          "0x0063"
#define  RL_HDR_STR_ADDR_CH_15_inst                                              0x0063
#define  set_RL_HDR_STR_ADDR_CH_15_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_15_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_15_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_15_reg))

#define  RL_HDR_STR_ADDR_CH_16                                                   0x1800ED90
#define  RL_HDR_STR_ADDR_CH_16_reg_addr                                          "0xB800ED90"
#define  RL_HDR_STR_ADDR_CH_16_reg                                               0xB800ED90
#define  RL_HDR_STR_ADDR_CH_16_inst_addr                                         "0x007F"
#define  RL_HDR_STR_ADDR_CH_16_inst_adr                                          "0x0064"
#define  RL_HDR_STR_ADDR_CH_16_inst                                              0x0064
#define  set_RL_HDR_STR_ADDR_CH_16_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_16_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_16_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_16_reg))

#define  RL_HDR_STR_ADDR_CH_17                                                   0x1800ED94
#define  RL_HDR_STR_ADDR_CH_17_reg_addr                                          "0xB800ED94"
#define  RL_HDR_STR_ADDR_CH_17_reg                                               0xB800ED94
#define  RL_HDR_STR_ADDR_CH_17_inst_addr                                         "0x0080"
#define  RL_HDR_STR_ADDR_CH_17_inst_adr                                          "0x0065"
#define  RL_HDR_STR_ADDR_CH_17_inst                                              0x0065
#define  set_RL_HDR_STR_ADDR_CH_17_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_17_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_17_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_17_reg))

#define  RL_HDR_STR_ADDR_CH_18                                                   0x1800ED98
#define  RL_HDR_STR_ADDR_CH_18_reg_addr                                          "0xB800ED98"
#define  RL_HDR_STR_ADDR_CH_18_reg                                               0xB800ED98
#define  RL_HDR_STR_ADDR_CH_18_inst_addr                                         "0x0081"
#define  RL_HDR_STR_ADDR_CH_18_inst_adr                                          "0x0066"
#define  RL_HDR_STR_ADDR_CH_18_inst                                              0x0066
#define  set_RL_HDR_STR_ADDR_CH_18_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_18_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_18_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_18_reg))

#define  RL_HDR_STR_ADDR_CH_19                                                   0x1800ED9C
#define  RL_HDR_STR_ADDR_CH_19_reg_addr                                          "0xB800ED9C"
#define  RL_HDR_STR_ADDR_CH_19_reg                                               0xB800ED9C
#define  RL_HDR_STR_ADDR_CH_19_inst_addr                                         "0x0082"
#define  RL_HDR_STR_ADDR_CH_19_inst_adr                                          "0x0067"
#define  RL_HDR_STR_ADDR_CH_19_inst                                              0x0067
#define  set_RL_HDR_STR_ADDR_CH_19_reg(data)                                     (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_19_reg)=data)
#define  get_RL_HDR_STR_ADDR_CH_19_reg                                           (*((volatile unsigned int*)RL_HDR_STR_ADDR_CH_19_reg))

#define  RL_HDR_MAP_IDX_0                                                        0x1800EDA0
#define  RL_HDR_MAP_IDX_0_reg_addr                                               "0xB800EDA0"
#define  RL_HDR_MAP_IDX_0_reg                                                    0xB800EDA0
#define  RL_HDR_MAP_IDX_0_inst_addr                                              "0x0083"
#define  RL_HDR_MAP_IDX_0_inst_adr                                               "0x0068"
#define  RL_HDR_MAP_IDX_0_inst                                                   0x0068
#define  set_RL_HDR_MAP_IDX_0_reg(data)                                          (*((volatile unsigned int*)RL_HDR_MAP_IDX_0_reg)=data)
#define  get_RL_HDR_MAP_IDX_0_reg                                                (*((volatile unsigned int*)RL_HDR_MAP_IDX_0_reg))
#define  RL_HDR_MAP_IDX_0_dmy_shift                                              (28)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_0_shift                                    (21)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_1_shift                                    (14)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_2_shift                                    (7)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_3_shift                                    (0)
#define  RL_HDR_MAP_IDX_0_dmy_mask                                               (0xF0000000)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_0_mask                                     (0x0FE00000)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_1_mask                                     (0x001FC000)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_2_mask                                     (0x00003F80)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_3_mask                                     (0x0000007F)
#define  RL_HDR_MAP_IDX_0_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_0(data)                                    (0x0FE00000&((data)<<21))
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_1(data)                                    (0x001FC000&((data)<<14))
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_2(data)                                    (0x00003F80&((data)<<7))
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_3(data)                                    (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_0_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_0_get_Hdr_map_idx_0(data)                                ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_0_get_Hdr_map_idx_1(data)                                ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_0_get_Hdr_map_idx_2(data)                                ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_0_get_Hdr_map_idx_3(data)                                (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_0_dmy_src(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_0_src(data)                                ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_1_src(data)                                ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_2_src(data)                                ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_0_Hdr_map_idx_3_src(data)                                (0x0000007F&(data))

#define  RL_HDR_MAP_IDX_1                                                        0x1800EDA4
#define  RL_HDR_MAP_IDX_1_reg_addr                                               "0xB800EDA4"
#define  RL_HDR_MAP_IDX_1_reg                                                    0xB800EDA4
#define  RL_HDR_MAP_IDX_1_inst_addr                                              "0x0084"
#define  RL_HDR_MAP_IDX_1_inst_adr                                               "0x0069"
#define  RL_HDR_MAP_IDX_1_inst                                                   0x0069
#define  set_RL_HDR_MAP_IDX_1_reg(data)                                          (*((volatile unsigned int*)RL_HDR_MAP_IDX_1_reg)=data)
#define  get_RL_HDR_MAP_IDX_1_reg                                                (*((volatile unsigned int*)RL_HDR_MAP_IDX_1_reg))
#define  RL_HDR_MAP_IDX_1_dmy_shift                                              (28)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_4_shift                                    (21)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_5_shift                                    (14)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_6_shift                                    (7)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_7_shift                                    (0)
#define  RL_HDR_MAP_IDX_1_dmy_mask                                               (0xF0000000)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_4_mask                                     (0x0FE00000)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_5_mask                                     (0x001FC000)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_6_mask                                     (0x00003F80)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_7_mask                                     (0x0000007F)
#define  RL_HDR_MAP_IDX_1_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_4(data)                                    (0x0FE00000&((data)<<21))
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_5(data)                                    (0x001FC000&((data)<<14))
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_6(data)                                    (0x00003F80&((data)<<7))
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_7(data)                                    (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_1_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_1_get_Hdr_map_idx_4(data)                                ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_1_get_Hdr_map_idx_5(data)                                ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_1_get_Hdr_map_idx_6(data)                                ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_1_get_Hdr_map_idx_7(data)                                (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_1_dmy_src(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_4_src(data)                                ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_5_src(data)                                ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_6_src(data)                                ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_1_Hdr_map_idx_7_src(data)                                (0x0000007F&(data))

#define  RL_HDR_MAP_IDX_2                                                        0x1800EDA8
#define  RL_HDR_MAP_IDX_2_reg_addr                                               "0xB800EDA8"
#define  RL_HDR_MAP_IDX_2_reg                                                    0xB800EDA8
#define  RL_HDR_MAP_IDX_2_inst_addr                                              "0x0085"
#define  RL_HDR_MAP_IDX_2_inst_adr                                               "0x006A"
#define  RL_HDR_MAP_IDX_2_inst                                                   0x006A
#define  set_RL_HDR_MAP_IDX_2_reg(data)                                          (*((volatile unsigned int*)RL_HDR_MAP_IDX_2_reg)=data)
#define  get_RL_HDR_MAP_IDX_2_reg                                                (*((volatile unsigned int*)RL_HDR_MAP_IDX_2_reg))
#define  RL_HDR_MAP_IDX_2_dmy_shift                                              (28)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_8_shift                                    (21)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_9_shift                                    (14)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_10_shift                                   (7)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_11_shift                                   (0)
#define  RL_HDR_MAP_IDX_2_dmy_mask                                               (0xF0000000)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_8_mask                                     (0x0FE00000)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_9_mask                                     (0x001FC000)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_10_mask                                    (0x00003F80)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_11_mask                                    (0x0000007F)
#define  RL_HDR_MAP_IDX_2_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_8(data)                                    (0x0FE00000&((data)<<21))
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_9(data)                                    (0x001FC000&((data)<<14))
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_10(data)                                   (0x00003F80&((data)<<7))
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_11(data)                                   (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_2_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_2_get_Hdr_map_idx_8(data)                                ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_2_get_Hdr_map_idx_9(data)                                ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_2_get_Hdr_map_idx_10(data)                               ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_2_get_Hdr_map_idx_11(data)                               (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_2_dmy_src(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_8_src(data)                                ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_9_src(data)                                ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_10_src(data)                               ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_2_Hdr_map_idx_11_src(data)                               (0x0000007F&(data))

#define  RL_HDR_MAP_IDX_3                                                        0x1800EDAC
#define  RL_HDR_MAP_IDX_3_reg_addr                                               "0xB800EDAC"
#define  RL_HDR_MAP_IDX_3_reg                                                    0xB800EDAC
#define  RL_HDR_MAP_IDX_3_inst_addr                                              "0x0086"
#define  RL_HDR_MAP_IDX_3_inst_adr                                               "0x006B"
#define  RL_HDR_MAP_IDX_3_inst                                                   0x006B
#define  set_RL_HDR_MAP_IDX_3_reg(data)                                          (*((volatile unsigned int*)RL_HDR_MAP_IDX_3_reg)=data)
#define  get_RL_HDR_MAP_IDX_3_reg                                                (*((volatile unsigned int*)RL_HDR_MAP_IDX_3_reg))
#define  RL_HDR_MAP_IDX_3_dmy_shift                                              (28)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_12_shift                                   (21)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_13_shift                                   (14)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_14_shift                                   (7)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_15_shift                                   (0)
#define  RL_HDR_MAP_IDX_3_dmy_mask                                               (0xF0000000)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_12_mask                                    (0x0FE00000)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_13_mask                                    (0x001FC000)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_14_mask                                    (0x00003F80)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_15_mask                                    (0x0000007F)
#define  RL_HDR_MAP_IDX_3_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_12(data)                                   (0x0FE00000&((data)<<21))
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_13(data)                                   (0x001FC000&((data)<<14))
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_14(data)                                   (0x00003F80&((data)<<7))
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_15(data)                                   (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_3_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_3_get_Hdr_map_idx_12(data)                               ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_3_get_Hdr_map_idx_13(data)                               ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_3_get_Hdr_map_idx_14(data)                               ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_3_get_Hdr_map_idx_15(data)                               (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_3_dmy_src(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_12_src(data)                               ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_13_src(data)                               ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_14_src(data)                               ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_3_Hdr_map_idx_15_src(data)                               (0x0000007F&(data))

#define  RL_HDR_MAP_IDX_4                                                        0x1800EDB0
#define  RL_HDR_MAP_IDX_4_reg_addr                                               "0xB800EDB0"
#define  RL_HDR_MAP_IDX_4_reg                                                    0xB800EDB0
#define  RL_HDR_MAP_IDX_4_inst_addr                                              "0x0087"
#define  RL_HDR_MAP_IDX_4_inst_adr                                               "0x006C"
#define  RL_HDR_MAP_IDX_4_inst                                                   0x006C
#define  set_RL_HDR_MAP_IDX_4_reg(data)                                          (*((volatile unsigned int*)RL_HDR_MAP_IDX_4_reg)=data)
#define  get_RL_HDR_MAP_IDX_4_reg                                                (*((volatile unsigned int*)RL_HDR_MAP_IDX_4_reg))
#define  RL_HDR_MAP_IDX_4_dmy_shift                                              (28)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_16_shift                                   (21)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_17_shift                                   (14)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_18_shift                                   (7)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_19_shift                                   (0)
#define  RL_HDR_MAP_IDX_4_dmy_mask                                               (0xF0000000)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_16_mask                                    (0x0FE00000)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_17_mask                                    (0x001FC000)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_18_mask                                    (0x00003F80)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_19_mask                                    (0x0000007F)
#define  RL_HDR_MAP_IDX_4_dmy(data)                                              (0xF0000000&((data)<<28))
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_16(data)                                   (0x0FE00000&((data)<<21))
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_17(data)                                   (0x001FC000&((data)<<14))
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_18(data)                                   (0x00003F80&((data)<<7))
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_19(data)                                   (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_4_get_dmy(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_4_get_Hdr_map_idx_16(data)                               ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_4_get_Hdr_map_idx_17(data)                               ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_4_get_Hdr_map_idx_18(data)                               ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_4_get_Hdr_map_idx_19(data)                               (0x0000007F&(data))
#define  RL_HDR_MAP_IDX_4_dmy_src(data)                                          ((0xF0000000&(data))>>28)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_16_src(data)                               ((0x0FE00000&(data))>>21)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_17_src(data)                               ((0x001FC000&(data))>>14)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_18_src(data)                               ((0x00003F80&(data))>>7)
#define  RL_HDR_MAP_IDX_4_Hdr_map_idx_19_src(data)                               (0x0000007F&(data))

#define  RL_DCMPRS_CORE_FLAG_EN                                                  0x1800EDB4
#define  RL_DCMPRS_CORE_FLAG_EN_reg_addr                                         "0xB800EDB4"
#define  RL_DCMPRS_CORE_FLAG_EN_reg                                              0xB800EDB4
#define  RL_DCMPRS_CORE_FLAG_EN_inst_addr                                        "0x0088"
#define  RL_DCMPRS_CORE_FLAG_EN_inst_adr                                         "0x006D"
#define  RL_DCMPRS_CORE_FLAG_EN_inst                                             0x006D
#define  set_RL_DCMPRS_CORE_FLAG_EN_reg(data)                                    (*((volatile unsigned int*)RL_DCMPRS_CORE_FLAG_EN_reg)=data)
#define  get_RL_DCMPRS_CORE_FLAG_EN_reg                                          (*((volatile unsigned int*)RL_DCMPRS_CORE_FLAG_EN_reg))
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_3_shift                         (24)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_2_shift                         (16)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_1_shift                         (8)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_0_shift                         (0)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_3_mask                          (0xFF000000)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_2_mask                          (0x00FF0000)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_1_mask                          (0x0000FF00)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_0_mask                          (0x000000FF)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_3(data)                         (0xFF000000&((data)<<24))
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_2(data)                         (0x00FF0000&((data)<<16))
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_1(data)                         (0x0000FF00&((data)<<8))
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_0(data)                         (0x000000FF&(data))
#define  RL_DCMPRS_CORE_FLAG_EN_get_core_flag2irq_en_3(data)                     ((0xFF000000&(data))>>24)
#define  RL_DCMPRS_CORE_FLAG_EN_get_core_flag2irq_en_2(data)                     ((0x00FF0000&(data))>>16)
#define  RL_DCMPRS_CORE_FLAG_EN_get_core_flag2irq_en_1(data)                     ((0x0000FF00&(data))>>8)
#define  RL_DCMPRS_CORE_FLAG_EN_get_core_flag2irq_en_0(data)                     (0x000000FF&(data))
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_3_src(data)                     ((0xFF000000&(data))>>24)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_2_src(data)                     ((0x00FF0000&(data))>>16)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_1_src(data)                     ((0x0000FF00&(data))>>8)
#define  RL_DCMPRS_CORE_FLAG_EN_core_flag2irq_en_0_src(data)                     (0x000000FF&(data))

#define  RL_DCMPRS_CORE_FLAG_CLR                                                 0x1800EDB8
#define  RL_DCMPRS_CORE_FLAG_CLR_reg_addr                                        "0xB800EDB8"
#define  RL_DCMPRS_CORE_FLAG_CLR_reg                                             0xB800EDB8
#define  RL_DCMPRS_CORE_FLAG_CLR_inst_addr                                       "0x0089"
#define  RL_DCMPRS_CORE_FLAG_CLR_inst_adr                                        "0x006E"
#define  RL_DCMPRS_CORE_FLAG_CLR_inst                                            0x006E
#define  set_RL_DCMPRS_CORE_FLAG_CLR_reg(data)                                   (*((volatile unsigned int*)RL_DCMPRS_CORE_FLAG_CLR_reg)=data)
#define  get_RL_DCMPRS_CORE_FLAG_CLR_reg                                         (*((volatile unsigned int*)RL_DCMPRS_CORE_FLAG_CLR_reg))
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_3_shift                        (24)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_2_shift                        (16)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_1_shift                        (8)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_0_shift                        (0)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_3_mask                         (0xFF000000)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_2_mask                         (0x00FF0000)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_1_mask                         (0x0000FF00)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_0_mask                         (0x000000FF)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_3(data)                        (0xFF000000&((data)<<24))
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_2(data)                        (0x00FF0000&((data)<<16))
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_1(data)                        (0x0000FF00&((data)<<8))
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_0(data)                        (0x000000FF&(data))
#define  RL_DCMPRS_CORE_FLAG_CLR_get_core_errflag_clr_3(data)                    ((0xFF000000&(data))>>24)
#define  RL_DCMPRS_CORE_FLAG_CLR_get_core_errflag_clr_2(data)                    ((0x00FF0000&(data))>>16)
#define  RL_DCMPRS_CORE_FLAG_CLR_get_core_errflag_clr_1(data)                    ((0x0000FF00&(data))>>8)
#define  RL_DCMPRS_CORE_FLAG_CLR_get_core_errflag_clr_0(data)                    (0x000000FF&(data))
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_3_src(data)                    ((0xFF000000&(data))>>24)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_2_src(data)                    ((0x00FF0000&(data))>>16)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_1_src(data)                    ((0x0000FF00&(data))>>8)
#define  RL_DCMPRS_CORE_FLAG_CLR_core_errflag_clr_0_src(data)                    (0x000000FF&(data))

#define  RL_DCMPRS_CORE_FLAG                                                     0x1800EDBC
#define  RL_DCMPRS_CORE_FLAG_reg_addr                                            "0xB800EDBC"
#define  RL_DCMPRS_CORE_FLAG_reg                                                 0xB800EDBC
#define  RL_DCMPRS_CORE_FLAG_inst_addr                                           "0x008A"
#define  RL_DCMPRS_CORE_FLAG_inst_adr                                            "0x006F"
#define  RL_DCMPRS_CORE_FLAG_inst                                                0x006F
#define  set_RL_DCMPRS_CORE_FLAG_reg(data)                                       (*((volatile unsigned int*)RL_DCMPRS_CORE_FLAG_reg)=data)
#define  get_RL_DCMPRS_CORE_FLAG_reg                                             (*((volatile unsigned int*)RL_DCMPRS_CORE_FLAG_reg))
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_3_shift                             (24)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_2_shift                             (16)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_1_shift                             (8)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_0_shift                             (0)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_3_mask                              (0xFF000000)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_2_mask                              (0x00FF0000)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_1_mask                              (0x0000FF00)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_0_mask                              (0x000000FF)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_3(data)                             (0xFF000000&((data)<<24))
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_2(data)                             (0x00FF0000&((data)<<16))
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_1(data)                             (0x0000FF00&((data)<<8))
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_0(data)                             (0x000000FF&(data))
#define  RL_DCMPRS_CORE_FLAG_get_core_errflag_ro_3(data)                         ((0xFF000000&(data))>>24)
#define  RL_DCMPRS_CORE_FLAG_get_core_errflag_ro_2(data)                         ((0x00FF0000&(data))>>16)
#define  RL_DCMPRS_CORE_FLAG_get_core_errflag_ro_1(data)                         ((0x0000FF00&(data))>>8)
#define  RL_DCMPRS_CORE_FLAG_get_core_errflag_ro_0(data)                         (0x000000FF&(data))
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_3_src(data)                         ((0xFF000000&(data))>>24)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_2_src(data)                         ((0x00FF0000&(data))>>16)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_1_src(data)                         ((0x0000FF00&(data))>>8)
#define  RL_DCMPRS_CORE_FLAG_core_errflag_ro_0_src(data)                         (0x000000FF&(data))

#define  RL_DCMPRS_CORE_FLAG_IRQ                                                 0x1800EDC0
#define  RL_DCMPRS_CORE_FLAG_IRQ_reg_addr                                        "0xB800EDC0"
#define  RL_DCMPRS_CORE_FLAG_IRQ_reg                                             0xB800EDC0
#define  RL_DCMPRS_CORE_FLAG_IRQ_inst_addr                                       "0x008B"
#define  RL_DCMPRS_CORE_FLAG_IRQ_inst_adr                                        "0x0070"
#define  RL_DCMPRS_CORE_FLAG_IRQ_inst                                            0x0070
#define  set_RL_DCMPRS_CORE_FLAG_IRQ_reg(data)                                   (*((volatile unsigned int*)RL_DCMPRS_CORE_FLAG_IRQ_reg)=data)
#define  get_RL_DCMPRS_CORE_FLAG_IRQ_reg                                         (*((volatile unsigned int*)RL_DCMPRS_CORE_FLAG_IRQ_reg))
#define  RL_DCMPRS_CORE_FLAG_IRQ_dmy_shift                                       (4)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_3_shift                        (3)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_2_shift                        (2)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_1_shift                        (1)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_0_shift                        (0)
#define  RL_DCMPRS_CORE_FLAG_IRQ_dmy_mask                                        (0xFFFFFFF0)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_3_mask                         (0x00000008)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_2_mask                         (0x00000004)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_1_mask                         (0x00000002)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_0_mask                         (0x00000001)
#define  RL_DCMPRS_CORE_FLAG_IRQ_dmy(data)                                       (0xFFFFFFF0&((data)<<4))
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_3(data)                        (0x00000008&((data)<<3))
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_2(data)                        (0x00000004&((data)<<2))
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_1(data)                        (0x00000002&((data)<<1))
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_0(data)                        (0x00000001&(data))
#define  RL_DCMPRS_CORE_FLAG_IRQ_get_dmy(data)                                   ((0xFFFFFFF0&(data))>>4)
#define  RL_DCMPRS_CORE_FLAG_IRQ_get_core_errflag_irq_3(data)                    ((0x00000008&(data))>>3)
#define  RL_DCMPRS_CORE_FLAG_IRQ_get_core_errflag_irq_2(data)                    ((0x00000004&(data))>>2)
#define  RL_DCMPRS_CORE_FLAG_IRQ_get_core_errflag_irq_1(data)                    ((0x00000002&(data))>>1)
#define  RL_DCMPRS_CORE_FLAG_IRQ_get_core_errflag_irq_0(data)                    (0x00000001&(data))
#define  RL_DCMPRS_CORE_FLAG_IRQ_dmy_src(data)                                   ((0xFFFFFFF0&(data))>>4)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_3_src(data)                    ((0x00000008&(data))>>3)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_2_src(data)                    ((0x00000004&(data))>>2)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_1_src(data)                    ((0x00000002&(data))>>1)
#define  RL_DCMPRS_CORE_FLAG_IRQ_core_errflag_irq_0_src(data)                    (0x00000001&(data))

#define  RL_DCMPRS_WRAP_WIDTH                                                    0x1800EDC4
#define  RL_DCMPRS_WRAP_WIDTH_reg_addr                                           "0xB800EDC4"
#define  RL_DCMPRS_WRAP_WIDTH_reg                                                0xB800EDC4
#define  RL_DCMPRS_WRAP_WIDTH_inst_addr                                          "0x008C"
#define  RL_DCMPRS_WRAP_WIDTH_inst_adr                                           "0x0071"
#define  RL_DCMPRS_WRAP_WIDTH_inst                                               0x0071
#define  set_RL_DCMPRS_WRAP_WIDTH_reg(data)                                      (*((volatile unsigned int*)RL_DCMPRS_WRAP_WIDTH_reg)=data)
#define  get_RL_DCMPRS_WRAP_WIDTH_reg                                            (*((volatile unsigned int*)RL_DCMPRS_WRAP_WIDTH_reg))
#define  RL_DCMPRS_WRAP_WIDTH_dmy_shift                                          (30)
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_2_shift                                 (20)
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_1_shift                                 (10)
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_0_shift                                 (0)
#define  RL_DCMPRS_WRAP_WIDTH_dmy_mask                                           (0xC0000000)
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_2_mask                                  (0x3FF00000)
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_1_mask                                  (0x000FFC00)
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_0_mask                                  (0x000003FF)
#define  RL_DCMPRS_WRAP_WIDTH_dmy(data)                                          (0xC0000000&((data)<<30))
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_2(data)                                 (0x3FF00000&((data)<<20))
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_1(data)                                 (0x000FFC00&((data)<<10))
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_0(data)                                 (0x000003FF&(data))
#define  RL_DCMPRS_WRAP_WIDTH_get_dmy(data)                                      ((0xC0000000&(data))>>30)
#define  RL_DCMPRS_WRAP_WIDTH_get_wrap_width_2(data)                             ((0x3FF00000&(data))>>20)
#define  RL_DCMPRS_WRAP_WIDTH_get_wrap_width_1(data)                             ((0x000FFC00&(data))>>10)
#define  RL_DCMPRS_WRAP_WIDTH_get_wrap_width_0(data)                             (0x000003FF&(data))
#define  RL_DCMPRS_WRAP_WIDTH_dmy_src(data)                                      ((0xC0000000&(data))>>30)
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_2_src(data)                             ((0x3FF00000&(data))>>20)
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_1_src(data)                             ((0x000FFC00&(data))>>10)
#define  RL_DCMPRS_WRAP_WIDTH_wrap_width_0_src(data)                             (0x000003FF&(data))

#define  RL_DCMPRS_DBG_OUT                                                       0x1800EDC8
#define  RL_DCMPRS_DBG_OUT_reg_addr                                              "0xB800EDC8"
#define  RL_DCMPRS_DBG_OUT_reg                                                   0xB800EDC8
#define  RL_DCMPRS_DBG_OUT_inst_addr                                             "0x008D"
#define  RL_DCMPRS_DBG_OUT_inst_adr                                              "0x0072"
#define  RL_DCMPRS_DBG_OUT_inst                                                  0x0072
#define  set_RL_DCMPRS_DBG_OUT_reg(data)                                         (*((volatile unsigned int*)RL_DCMPRS_DBG_OUT_reg)=data)
#define  get_RL_DCMPRS_DBG_OUT_reg                                               (*((volatile unsigned int*)RL_DCMPRS_DBG_OUT_reg))
#define  RL_DCMPRS_DBG_OUT_Debug_out1_shift                                      (16)
#define  RL_DCMPRS_DBG_OUT_Debug_out0_shift                                      (0)
#define  RL_DCMPRS_DBG_OUT_Debug_out1_mask                                       (0xFFFF0000)
#define  RL_DCMPRS_DBG_OUT_Debug_out0_mask                                       (0x0000FFFF)
#define  RL_DCMPRS_DBG_OUT_Debug_out1(data)                                      (0xFFFF0000&((data)<<16))
#define  RL_DCMPRS_DBG_OUT_Debug_out0(data)                                      (0x0000FFFF&(data))
#define  RL_DCMPRS_DBG_OUT_get_Debug_out1(data)                                  ((0xFFFF0000&(data))>>16)
#define  RL_DCMPRS_DBG_OUT_get_Debug_out0(data)                                  (0x0000FFFF&(data))
#define  RL_DCMPRS_DBG_OUT_Debug_out1_src(data)                                  ((0xFFFF0000&(data))>>16)
#define  RL_DCMPRS_DBG_OUT_Debug_out0_src(data)                                  (0x0000FFFF&(data))

#ifdef _RL_USE_STRUCT
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
        RBus_UInt32  Cur_RANGEREDFRM:1;
    };
}RL_RLCNTL_RBUS;

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
        RBus_UInt32  RM_threshold:6;
    };
}RL_RLCNTL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  HEVC_Zidx:8;
        RBus_UInt32  HEVC_Log2CbSize_minus3:2;
        RBus_UInt32  PicType:3;
        RBus_UInt32  First_mb:1;
        RBus_UInt32  Cur_mb_x:9;
        RBus_UInt32  Cur_mb_y:9;
    };
}RL_CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  PaddingCU:1;
        RBus_UInt32  dummyColCTB:1;
        RBus_UInt32  dummyRowCTB:1;
        RBus_UInt32  mb_field_decoding_flag:1;
        RBus_UInt32  Mb_partition:9;
    };
}RL_H264CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  IntraMB_flag:1;
        RBus_UInt32  Intra_flag:5;
        RBus_UInt32  SubMB_partition:12;
        RBus_UInt32  mvtype:2;
        RBus_UInt32  FIELDTX:1;
        RBus_UInt32  OVERFLAG:1;
    };
}RL_VC1CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  Chroma_predict_part0:2;
        RBus_UInt32  Chroma_predict_part1:2;
        RBus_UInt32  Chroma_predict_part2:2;
        RBus_UInt32  Chroma_predict_part3:2;
        RBus_UInt32  Inter_predict_part0:2;
        RBus_UInt32  Inter_predict_part1:2;
        RBus_UInt32  Inter_predict_part2:2;
        RBus_UInt32  Inter_predict_part3:2;
    };
}RL_POPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ref_RANGEREDFRM:1;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  lu_addr_index:7;
        RBus_UInt32  ch_addr_index:7;
    };
}RL_L0REFDMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ref_RANGEREDFRM:1;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  lu_addr_index:7;
        RBus_UInt32  ch_addr_index:7;
    };
}RL_L1REFDMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  Trigger_status:1;
        RBus_UInt32  Zero_w_lr:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  Trigger_select:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  Trigger_cond_mb_x:9;
        RBus_UInt32  Trigger_cond_mb_y:8;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Debug_port_sel:3;
    };
}RL_DBG_SEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Tbl_cnt:16;
        RBus_UInt32  Trigger_tbl_cnt:16;
    };
}RL_DBG_STS0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DBG_STS:32;
    };
}RL_DBG_STS1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DBG_STS:32;
    };
}RL_DBG_STS2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  Intr:1;
        RBus_UInt32  Value:28;
    };
}RL_INTR_THRES_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  MVBUF_write_address:7;
    };
}RL_MVBUF_WADD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MVBUF_read_write_data:32;
    };
}RL_MVBUF_DATA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  MVBUF_read_address:7;
    };
}RL_MVBUF_RADD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  MVBUF_hdr:10;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  MVBUF_mvd_wptr:11;
    };
}RL_MVBUF_STS0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  MVBUF_pred_rptr:11;
        RBus_UInt32  write_enable11:1;
        RBus_UInt32  MVBUF_rl_rptr:11;
    };
}RL_MVBUF_STS1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  Hdr_ref_pic_cnt:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  Vg_en:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Ref_pic_cnt:2;
    };
}RL_CACHE_SET_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  Hdr_cah_en:1;
        RBus_UInt32  Cah_en:1;
    };
}RL_CACHE_EN_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  Hdr_cah_inv:1;
        RBus_UInt32  Cah_inv:1;
    };
}RL_CACHE_INV_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Cah_pindx0_LumL0:8;
        RBus_UInt32  Cah_pindx1_LumL1:8;
        RBus_UInt32  Cah_pindx2_ChrL0:8;
        RBus_UInt32  Cah_pindx3_ChrL1:8;
    };
}RL_CAH_PINDX_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Ext_cah_pindx_Lum0:8;
        RBus_UInt32  Ext_cah_pindx_Lum1:8;
        RBus_UInt32  Ext_cah_pindx_Lum2:8;
        RBus_UInt32  Ext_cah_pindx_Lum3:8;
    };
}RL_HDR_CAH_PINDX_EXT_LUMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Ext_cah_pindx_Chr0:8;
        RBus_UInt32  Ext_cah_pindx_Chr1:8;
        RBus_UInt32  Ext_cah_pindx_Chr2:8;
        RBus_UInt32  Ext_cah_pindx_Chr3:8;
    };
}RL_HDR_CAH_PINDX_EXT_CHROMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disppic_h:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  disppic_w:14;
    };
}RL_SCALE_PIC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Hdr_str_addr_lu:32;
    };
}RL_HDR_STR_ADDR_LU_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Hdr_str_addr_ch:32;
    };
}RL_HDR_STR_ADDR_CH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  Hdr_map_idx_0:7;
        RBus_UInt32  Hdr_map_idx_1:7;
        RBus_UInt32  Hdr_map_idx_2:7;
        RBus_UInt32  Hdr_map_idx_3:7;
    };
}RL_HDR_MAP_IDX_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  Hdr_map_idx_4:7;
        RBus_UInt32  Hdr_map_idx_5:7;
        RBus_UInt32  Hdr_map_idx_6:7;
        RBus_UInt32  Hdr_map_idx_7:7;
    };
}RL_HDR_MAP_IDX_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  Hdr_map_idx_8:7;
        RBus_UInt32  Hdr_map_idx_9:7;
        RBus_UInt32  Hdr_map_idx_10:7;
        RBus_UInt32  Hdr_map_idx_11:7;
    };
}RL_HDR_MAP_IDX_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  Hdr_map_idx_12:7;
        RBus_UInt32  Hdr_map_idx_13:7;
        RBus_UInt32  Hdr_map_idx_14:7;
        RBus_UInt32  Hdr_map_idx_15:7;
    };
}RL_HDR_MAP_IDX_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:4;
        RBus_UInt32  Hdr_map_idx_16:7;
        RBus_UInt32  Hdr_map_idx_17:7;
        RBus_UInt32  Hdr_map_idx_18:7;
        RBus_UInt32  Hdr_map_idx_19:7;
    };
}RL_HDR_MAP_IDX_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_flag2irq_en_3:8;
        RBus_UInt32  core_flag2irq_en_2:8;
        RBus_UInt32  core_flag2irq_en_1:8;
        RBus_UInt32  core_flag2irq_en_0:8;
    };
}RL_DCMPRS_CORE_FLAG_EN_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_errflag_clr_3:8;
        RBus_UInt32  core_errflag_clr_2:8;
        RBus_UInt32  core_errflag_clr_1:8;
        RBus_UInt32  core_errflag_clr_0:8;
    };
}RL_DCMPRS_CORE_FLAG_CLR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_errflag_ro_3:8;
        RBus_UInt32  core_errflag_ro_2:8;
        RBus_UInt32  core_errflag_ro_1:8;
        RBus_UInt32  core_errflag_ro_0:8;
    };
}RL_DCMPRS_CORE_FLAG_RBUS;

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
}RL_DCMPRS_CORE_FLAG_IRQ_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:2;
        RBus_UInt32  wrap_width_2:10;
        RBus_UInt32  wrap_width_1:10;
        RBus_UInt32  wrap_width_0:10;
    };
}RL_DCMPRS_WRAP_WIDTH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Debug_out1:16;
        RBus_UInt32  Debug_out0:16;
    };
}RL_DCMPRS_DBG_OUT_RBUS;

#else //apply LITTLE_ENDIAN

//======RL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Cur_RANGEREDFRM:1;
        RBus_UInt32  disppic_w:14;
        RBus_UInt32  res1:1;
        RBus_UInt32  disppic_h:13;
        RBus_UInt32  res2:3;
    };
}RL_RLCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  RM_threshold:6;
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
}RL_RLCNTL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Cur_mb_y:9;
        RBus_UInt32  Cur_mb_x:9;
        RBus_UInt32  First_mb:1;
        RBus_UInt32  PicType:3;
        RBus_UInt32  HEVC_Log2CbSize_minus3:2;
        RBus_UInt32  HEVC_Zidx:8;
    };
}RL_CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Mb_partition:9;
        RBus_UInt32  mb_field_decoding_flag:1;
        RBus_UInt32  dummyRowCTB:1;
        RBus_UInt32  dummyColCTB:1;
        RBus_UInt32  PaddingCU:1;
        RBus_UInt32  res1:19;
    };
}RL_H264CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  OVERFLAG:1;
        RBus_UInt32  FIELDTX:1;
        RBus_UInt32  mvtype:2;
        RBus_UInt32  SubMB_partition:12;
        RBus_UInt32  Intra_flag:5;
        RBus_UInt32  IntraMB_flag:1;
        RBus_UInt32  res1:10;
    };
}RL_VC1CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Inter_predict_part3:2;
        RBus_UInt32  Inter_predict_part2:2;
        RBus_UInt32  Inter_predict_part1:2;
        RBus_UInt32  Inter_predict_part0:2;
        RBus_UInt32  Chroma_predict_part3:2;
        RBus_UInt32  Chroma_predict_part2:2;
        RBus_UInt32  Chroma_predict_part1:2;
        RBus_UInt32  Chroma_predict_part0:2;
        RBus_UInt32  res1:16;
    };
}RL_POPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_addr_index:7;
        RBus_UInt32  lu_addr_index:7;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  ref_RANGEREDFRM:1;
        RBus_UInt32  res1:16;
    };
}RL_L0REFDMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_addr_index:7;
        RBus_UInt32  lu_addr_index:7;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  ref_RANGEREDFRM:1;
        RBus_UInt32  res1:16;
    };
}RL_L1REFDMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Debug_port_sel:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Trigger_cond_mb_y:8;
        RBus_UInt32  Trigger_cond_mb_x:9;
        RBus_UInt32  res1:2;
        RBus_UInt32  Trigger_select:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  Zero_w_lr:2;
        RBus_UInt32  Trigger_status:1;
        RBus_UInt32  write_enable3:1;
    };
}RL_DBG_SEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Trigger_tbl_cnt:16;
        RBus_UInt32  Tbl_cnt:16;
    };
}RL_DBG_STS0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DBG_STS:32;
    };
}RL_DBG_STS1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DBG_STS:32;
    };
}RL_DBG_STS2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Value:28;
        RBus_UInt32  Intr:1;
        RBus_UInt32  res1:3;
    };
}RL_INTR_THRES_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MVBUF_write_address:7;
        RBus_UInt32  res1:25;
    };
}RL_MVBUF_WADD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MVBUF_read_write_data:32;
    };
}RL_MVBUF_DATA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MVBUF_read_address:7;
        RBus_UInt32  res1:25;
    };
}RL_MVBUF_RADD_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MVBUF_mvd_wptr:11;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  MVBUF_hdr:10;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  res1:9;
    };
}RL_MVBUF_STS0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MVBUF_rl_rptr:11;
        RBus_UInt32  write_enable11:1;
        RBus_UInt32  MVBUF_pred_rptr:11;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  res1:8;
    };
}RL_MVBUF_STS1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Ref_pic_cnt:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Vg_en:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  Hdr_ref_pic_cnt:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:24;
    };
}RL_CACHE_SET_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Cah_en:1;
        RBus_UInt32  Hdr_cah_en:1;
        RBus_UInt32  res1:30;
    };
}RL_CACHE_EN_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Cah_inv:1;
        RBus_UInt32  Hdr_cah_inv:1;
        RBus_UInt32  res1:30;
    };
}RL_CACHE_INV_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Cah_pindx3_ChrL1:8;
        RBus_UInt32  Cah_pindx2_ChrL0:8;
        RBus_UInt32  Cah_pindx1_LumL1:8;
        RBus_UInt32  Cah_pindx0_LumL0:8;
    };
}RL_CAH_PINDX_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Ext_cah_pindx_Lum3:8;
        RBus_UInt32  Ext_cah_pindx_Lum2:8;
        RBus_UInt32  Ext_cah_pindx_Lum1:8;
        RBus_UInt32  Ext_cah_pindx_Lum0:8;
    };
}RL_HDR_CAH_PINDX_EXT_LUMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Ext_cah_pindx_Chr3:8;
        RBus_UInt32  Ext_cah_pindx_Chr2:8;
        RBus_UInt32  Ext_cah_pindx_Chr1:8;
        RBus_UInt32  Ext_cah_pindx_Chr0:8;
    };
}RL_HDR_CAH_PINDX_EXT_CHROMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disppic_w:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  disppic_h:13;
        RBus_UInt32  res2:3;
    };
}RL_SCALE_PIC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Hdr_str_addr_lu:32;
    };
}RL_HDR_STR_ADDR_LU_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Hdr_str_addr_ch:32;
    };
}RL_HDR_STR_ADDR_CH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Hdr_map_idx_3:7;
        RBus_UInt32  Hdr_map_idx_2:7;
        RBus_UInt32  Hdr_map_idx_1:7;
        RBus_UInt32  Hdr_map_idx_0:7;
        RBus_UInt32  dmy:4;
    };
}RL_HDR_MAP_IDX_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Hdr_map_idx_7:7;
        RBus_UInt32  Hdr_map_idx_6:7;
        RBus_UInt32  Hdr_map_idx_5:7;
        RBus_UInt32  Hdr_map_idx_4:7;
        RBus_UInt32  dmy:4;
    };
}RL_HDR_MAP_IDX_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Hdr_map_idx_11:7;
        RBus_UInt32  Hdr_map_idx_10:7;
        RBus_UInt32  Hdr_map_idx_9:7;
        RBus_UInt32  Hdr_map_idx_8:7;
        RBus_UInt32  dmy:4;
    };
}RL_HDR_MAP_IDX_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Hdr_map_idx_15:7;
        RBus_UInt32  Hdr_map_idx_14:7;
        RBus_UInt32  Hdr_map_idx_13:7;
        RBus_UInt32  Hdr_map_idx_12:7;
        RBus_UInt32  dmy:4;
    };
}RL_HDR_MAP_IDX_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Hdr_map_idx_19:7;
        RBus_UInt32  Hdr_map_idx_18:7;
        RBus_UInt32  Hdr_map_idx_17:7;
        RBus_UInt32  Hdr_map_idx_16:7;
        RBus_UInt32  dmy:4;
    };
}RL_HDR_MAP_IDX_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_flag2irq_en_0:8;
        RBus_UInt32  core_flag2irq_en_1:8;
        RBus_UInt32  core_flag2irq_en_2:8;
        RBus_UInt32  core_flag2irq_en_3:8;
    };
}RL_DCMPRS_CORE_FLAG_EN_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_errflag_clr_0:8;
        RBus_UInt32  core_errflag_clr_1:8;
        RBus_UInt32  core_errflag_clr_2:8;
        RBus_UInt32  core_errflag_clr_3:8;
    };
}RL_DCMPRS_CORE_FLAG_CLR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  core_errflag_ro_0:8;
        RBus_UInt32  core_errflag_ro_1:8;
        RBus_UInt32  core_errflag_ro_2:8;
        RBus_UInt32  core_errflag_ro_3:8;
    };
}RL_DCMPRS_CORE_FLAG_RBUS;

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
}RL_DCMPRS_CORE_FLAG_IRQ_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrap_width_0:10;
        RBus_UInt32  wrap_width_1:10;
        RBus_UInt32  wrap_width_2:10;
        RBus_UInt32  dmy:2;
    };
}RL_DCMPRS_WRAP_WIDTH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Debug_out0:16;
        RBus_UInt32  Debug_out1:16;
    };
}RL_DCMPRS_DBG_OUT_RBUS;




#endif 


#endif 
#endif 
