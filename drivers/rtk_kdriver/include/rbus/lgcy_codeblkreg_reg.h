/**
* @file Mac5_LGCY_VE_CODEBLK_arch_spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGCY_CODEBLKREG_REG_H_
#define _RBUS_LGCY_CODEBLKREG_REG_H_

#include "rbus_types.h"



//  LGCY_CODEBLKREG Register Address
#define  LGCY_CODEBLKREG_ve_cntl                                                 0x1800E000
#define  LGCY_CODEBLKREG_ve_cntl_reg_addr                                        "0xB800E000"
#define  LGCY_CODEBLKREG_ve_cntl_reg                                             0xB800E000
#define  LGCY_CODEBLKREG_ve_cntl_inst_addr                                       "0x0000"
#define  set_LGCY_CODEBLKREG_ve_cntl_reg(data)                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_cntl_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_cntl_reg                                         (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_cntl_reg))
#define  LGCY_CODEBLKREG_ve_cntl_write_enable5_shift                             (24)
#define  LGCY_CODEBLKREG_ve_cntl_cm_bypass_shift                                 (23)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable4_shift                             (22)
#define  LGCY_CODEBLKREG_ve_cntl_ldstcmemcount_shift                             (6)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable3_shift                             (5)
#define  LGCY_CODEBLKREG_ve_cntl_cabac_1p_mode_shift                             (4)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable2_shift                             (3)
#define  LGCY_CODEBLKREG_ve_cntl_cabac_p2_p3_shift                               (2)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable1_shift                             (1)
#define  LGCY_CODEBLKREG_ve_cntl_itblk_advmode_shift                             (0)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable5_mask                              (0x01000000)
#define  LGCY_CODEBLKREG_ve_cntl_cm_bypass_mask                                  (0x00800000)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable4_mask                              (0x00400000)
#define  LGCY_CODEBLKREG_ve_cntl_ldstcmemcount_mask                              (0x003FFFC0)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable3_mask                              (0x00000020)
#define  LGCY_CODEBLKREG_ve_cntl_cabac_1p_mode_mask                              (0x00000010)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable2_mask                              (0x00000008)
#define  LGCY_CODEBLKREG_ve_cntl_cabac_p2_p3_mask                                (0x00000004)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable1_mask                              (0x00000002)
#define  LGCY_CODEBLKREG_ve_cntl_itblk_advmode_mask                              (0x00000001)
#define  LGCY_CODEBLKREG_ve_cntl_write_enable5(data)                             (0x01000000&((data)<<24))
#define  LGCY_CODEBLKREG_ve_cntl_cm_bypass(data)                                 (0x00800000&((data)<<23))
#define  LGCY_CODEBLKREG_ve_cntl_write_enable4(data)                             (0x00400000&((data)<<22))
#define  LGCY_CODEBLKREG_ve_cntl_ldstcmemcount(data)                             (0x003FFFC0&((data)<<6))
#define  LGCY_CODEBLKREG_ve_cntl_write_enable3(data)                             (0x00000020&((data)<<5))
#define  LGCY_CODEBLKREG_ve_cntl_cabac_1p_mode(data)                             (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_ve_cntl_write_enable2(data)                             (0x00000008&((data)<<3))
#define  LGCY_CODEBLKREG_ve_cntl_cabac_p2_p3(data)                               (0x00000004&((data)<<2))
#define  LGCY_CODEBLKREG_ve_cntl_write_enable1(data)                             (0x00000002&((data)<<1))
#define  LGCY_CODEBLKREG_ve_cntl_itblk_advmode(data)                             (0x00000001&(data))
#define  LGCY_CODEBLKREG_ve_cntl_get_write_enable5(data)                         ((0x01000000&(data))>>24)
#define  LGCY_CODEBLKREG_ve_cntl_get_cm_bypass(data)                             ((0x00800000&(data))>>23)
#define  LGCY_CODEBLKREG_ve_cntl_get_write_enable4(data)                         ((0x00400000&(data))>>22)
#define  LGCY_CODEBLKREG_ve_cntl_get_ldstcmemcount(data)                         ((0x003FFFC0&(data))>>6)
#define  LGCY_CODEBLKREG_ve_cntl_get_write_enable3(data)                         ((0x00000020&(data))>>5)
#define  LGCY_CODEBLKREG_ve_cntl_get_cabac_1p_mode(data)                         ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_ve_cntl_get_write_enable2(data)                         ((0x00000008&(data))>>3)
#define  LGCY_CODEBLKREG_ve_cntl_get_cabac_p2_p3(data)                           ((0x00000004&(data))>>2)
#define  LGCY_CODEBLKREG_ve_cntl_get_write_enable1(data)                         ((0x00000002&(data))>>1)
#define  LGCY_CODEBLKREG_ve_cntl_get_itblk_advmode(data)                         (0x00000001&(data))

#define  LGCY_CODEBLKREG_umem_ctrl                                               0x1800E004
#define  LGCY_CODEBLKREG_umem_ctrl_reg_addr                                      "0xB800E004"
#define  LGCY_CODEBLKREG_umem_ctrl_reg                                           0xB800E004
#define  LGCY_CODEBLKREG_umem_ctrl_inst_addr                                     "0x0001"
#define  set_LGCY_CODEBLKREG_umem_ctrl_reg(data)                                 (*((volatile unsigned int*)LGCY_CODEBLKREG_umem_ctrl_reg)=data)
#define  get_LGCY_CODEBLKREG_umem_ctrl_reg                                       (*((volatile unsigned int*)LGCY_CODEBLKREG_umem_ctrl_reg))
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable5_shift                           (28)
#define  LGCY_CODEBLKREG_umem_ctrl_dummy_picmb_h_shift                           (18)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable4_shift                           (17)
#define  LGCY_CODEBLKREG_umem_ctrl_h264_prev_qp_shift                            (11)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable3_shift                           (10)
#define  LGCY_CODEBLKREG_umem_ctrl_pred_bank_shift                               (8)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable2_shift                           (7)
#define  LGCY_CODEBLKREG_umem_ctrl_dec_bank_shift                                (5)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable1_shift                           (4)
#define  LGCY_CODEBLKREG_umem_ctrl_umem_mstr_shift                               (0)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable5_mask                            (0x10000000)
#define  LGCY_CODEBLKREG_umem_ctrl_dummy_picmb_h_mask                            (0x0FFC0000)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable4_mask                            (0x00020000)
#define  LGCY_CODEBLKREG_umem_ctrl_h264_prev_qp_mask                             (0x0001F800)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable3_mask                            (0x00000400)
#define  LGCY_CODEBLKREG_umem_ctrl_pred_bank_mask                                (0x00000300)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable2_mask                            (0x00000080)
#define  LGCY_CODEBLKREG_umem_ctrl_dec_bank_mask                                 (0x00000060)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable1_mask                            (0x00000010)
#define  LGCY_CODEBLKREG_umem_ctrl_umem_mstr_mask                                (0x0000000F)
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable5(data)                           (0x10000000&((data)<<28))
#define  LGCY_CODEBLKREG_umem_ctrl_dummy_picmb_h(data)                           (0x0FFC0000&((data)<<18))
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable4(data)                           (0x00020000&((data)<<17))
#define  LGCY_CODEBLKREG_umem_ctrl_h264_prev_qp(data)                            (0x0001F800&((data)<<11))
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable3(data)                           (0x00000400&((data)<<10))
#define  LGCY_CODEBLKREG_umem_ctrl_pred_bank(data)                               (0x00000300&((data)<<8))
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable2(data)                           (0x00000080&((data)<<7))
#define  LGCY_CODEBLKREG_umem_ctrl_dec_bank(data)                                (0x00000060&((data)<<5))
#define  LGCY_CODEBLKREG_umem_ctrl_write_enable1(data)                           (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_umem_ctrl_umem_mstr(data)                               (0x0000000F&(data))
#define  LGCY_CODEBLKREG_umem_ctrl_get_write_enable5(data)                       ((0x10000000&(data))>>28)
#define  LGCY_CODEBLKREG_umem_ctrl_get_dummy_picmb_h(data)                       ((0x0FFC0000&(data))>>18)
#define  LGCY_CODEBLKREG_umem_ctrl_get_write_enable4(data)                       ((0x00020000&(data))>>17)
#define  LGCY_CODEBLKREG_umem_ctrl_get_h264_prev_qp(data)                        ((0x0001F800&(data))>>11)
#define  LGCY_CODEBLKREG_umem_ctrl_get_write_enable3(data)                       ((0x00000400&(data))>>10)
#define  LGCY_CODEBLKREG_umem_ctrl_get_pred_bank(data)                           ((0x00000300&(data))>>8)
#define  LGCY_CODEBLKREG_umem_ctrl_get_write_enable2(data)                       ((0x00000080&(data))>>7)
#define  LGCY_CODEBLKREG_umem_ctrl_get_dec_bank(data)                            ((0x00000060&(data))>>5)
#define  LGCY_CODEBLKREG_umem_ctrl_get_write_enable1(data)                       ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_umem_ctrl_get_umem_mstr(data)                           (0x0000000F&(data))

#define  LGCY_CODEBLKREG_ve_slicegroup                                           0x1800E008
#define  LGCY_CODEBLKREG_ve_slicegroup_reg_addr                                  "0xB800E008"
#define  LGCY_CODEBLKREG_ve_slicegroup_reg                                       0xB800E008
#define  LGCY_CODEBLKREG_ve_slicegroup_inst_addr                                 "0x0002"
#define  set_LGCY_CODEBLKREG_ve_slicegroup_reg(data)                             (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_slicegroup_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_slicegroup_reg                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_slicegroup_reg))
#define  LGCY_CODEBLKREG_ve_slicegroup_mbaddrb_na_shift                          (2)
#define  LGCY_CODEBLKREG_ve_slicegroup_mbaddra_na_shift                          (1)
#define  LGCY_CODEBLKREG_ve_slicegroup_slicegroup_en_shift                       (0)
#define  LGCY_CODEBLKREG_ve_slicegroup_mbaddrb_na_mask                           (0x00000004)
#define  LGCY_CODEBLKREG_ve_slicegroup_mbaddra_na_mask                           (0x00000002)
#define  LGCY_CODEBLKREG_ve_slicegroup_slicegroup_en_mask                        (0x00000001)
#define  LGCY_CODEBLKREG_ve_slicegroup_mbaddrb_na(data)                          (0x00000004&((data)<<2))
#define  LGCY_CODEBLKREG_ve_slicegroup_mbaddra_na(data)                          (0x00000002&((data)<<1))
#define  LGCY_CODEBLKREG_ve_slicegroup_slicegroup_en(data)                       (0x00000001&(data))
#define  LGCY_CODEBLKREG_ve_slicegroup_get_mbaddrb_na(data)                      ((0x00000004&(data))>>2)
#define  LGCY_CODEBLKREG_ve_slicegroup_get_mbaddra_na(data)                      ((0x00000002&(data))>>1)
#define  LGCY_CODEBLKREG_ve_slicegroup_get_slicegroup_en(data)                   (0x00000001&(data))

#define  LGCY_CODEBLKREG_curadr                                                  0x1800E00C
#define  LGCY_CODEBLKREG_curadr_reg_addr                                         "0xB800E00C"
#define  LGCY_CODEBLKREG_curadr_reg                                              0xB800E00C
#define  LGCY_CODEBLKREG_curadr_inst_addr                                        "0x0003"
#define  set_LGCY_CODEBLKREG_curadr_reg(data)                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_curadr_reg)=data)
#define  get_LGCY_CODEBLKREG_curadr_reg                                          (*((volatile unsigned int*)LGCY_CODEBLKREG_curadr_reg))
#define  LGCY_CODEBLKREG_curadr_write_enable3_shift                              (30)
#define  LGCY_CODEBLKREG_curadr_cabac_curmb_addr_shift                           (20)
#define  LGCY_CODEBLKREG_curadr_write_enable2_shift                              (19)
#define  LGCY_CODEBLKREG_curadr_vld_curmb_addr_shift                             (9)
#define  LGCY_CODEBLKREG_curadr_write_enable1_shift                              (8)
#define  LGCY_CODEBLKREG_curadr_acdc_curmb_addr_shift                            (0)
#define  LGCY_CODEBLKREG_curadr_write_enable3_mask                               (0x40000000)
#define  LGCY_CODEBLKREG_curadr_cabac_curmb_addr_mask                            (0x3FF00000)
#define  LGCY_CODEBLKREG_curadr_write_enable2_mask                               (0x00080000)
#define  LGCY_CODEBLKREG_curadr_vld_curmb_addr_mask                              (0x0007FE00)
#define  LGCY_CODEBLKREG_curadr_write_enable1_mask                               (0x00000100)
#define  LGCY_CODEBLKREG_curadr_acdc_curmb_addr_mask                             (0x000000FF)
#define  LGCY_CODEBLKREG_curadr_write_enable3(data)                              (0x40000000&((data)<<30))
#define  LGCY_CODEBLKREG_curadr_cabac_curmb_addr(data)                           (0x3FF00000&((data)<<20))
#define  LGCY_CODEBLKREG_curadr_write_enable2(data)                              (0x00080000&((data)<<19))
#define  LGCY_CODEBLKREG_curadr_vld_curmb_addr(data)                             (0x0007FE00&((data)<<9))
#define  LGCY_CODEBLKREG_curadr_write_enable1(data)                              (0x00000100&((data)<<8))
#define  LGCY_CODEBLKREG_curadr_acdc_curmb_addr(data)                            (0x000000FF&(data))
#define  LGCY_CODEBLKREG_curadr_get_write_enable3(data)                          ((0x40000000&(data))>>30)
#define  LGCY_CODEBLKREG_curadr_get_cabac_curmb_addr(data)                       ((0x3FF00000&(data))>>20)
#define  LGCY_CODEBLKREG_curadr_get_write_enable2(data)                          ((0x00080000&(data))>>19)
#define  LGCY_CODEBLKREG_curadr_get_vld_curmb_addr(data)                         ((0x0007FE00&(data))>>9)
#define  LGCY_CODEBLKREG_curadr_get_write_enable1(data)                          ((0x00000100&(data))>>8)
#define  LGCY_CODEBLKREG_curadr_get_acdc_curmb_addr(data)                        (0x000000FF&(data))

#define  LGCY_CODEBLKREG_predcntr                                                0x1800E010
#define  LGCY_CODEBLKREG_predcntr_reg_addr                                       "0xB800E010"
#define  LGCY_CODEBLKREG_predcntr_reg                                            0xB800E010
#define  LGCY_CODEBLKREG_predcntr_inst_addr                                      "0x0004"
#define  set_LGCY_CODEBLKREG_predcntr_reg(data)                                  (*((volatile unsigned int*)LGCY_CODEBLKREG_predcntr_reg)=data)
#define  get_LGCY_CODEBLKREG_predcntr_reg                                        (*((volatile unsigned int*)LGCY_CODEBLKREG_predcntr_reg))
#define  LGCY_CODEBLKREG_predcntr_write_enable3_shift                            (30)
#define  LGCY_CODEBLKREG_predcntr_cabac_pred_counter_shift                       (20)
#define  LGCY_CODEBLKREG_predcntr_write_enable2_shift                            (19)
#define  LGCY_CODEBLKREG_predcntr_vld_pred_counter_shift                         (9)
#define  LGCY_CODEBLKREG_predcntr_write_enable1_shift                            (8)
#define  LGCY_CODEBLKREG_predcntr_acdc_pred_counter_shift                        (0)
#define  LGCY_CODEBLKREG_predcntr_write_enable3_mask                             (0x40000000)
#define  LGCY_CODEBLKREG_predcntr_cabac_pred_counter_mask                        (0x3FF00000)
#define  LGCY_CODEBLKREG_predcntr_write_enable2_mask                             (0x00080000)
#define  LGCY_CODEBLKREG_predcntr_vld_pred_counter_mask                          (0x0007FE00)
#define  LGCY_CODEBLKREG_predcntr_write_enable1_mask                             (0x00000100)
#define  LGCY_CODEBLKREG_predcntr_acdc_pred_counter_mask                         (0x000000FF)
#define  LGCY_CODEBLKREG_predcntr_write_enable3(data)                            (0x40000000&((data)<<30))
#define  LGCY_CODEBLKREG_predcntr_cabac_pred_counter(data)                       (0x3FF00000&((data)<<20))
#define  LGCY_CODEBLKREG_predcntr_write_enable2(data)                            (0x00080000&((data)<<19))
#define  LGCY_CODEBLKREG_predcntr_vld_pred_counter(data)                         (0x0007FE00&((data)<<9))
#define  LGCY_CODEBLKREG_predcntr_write_enable1(data)                            (0x00000100&((data)<<8))
#define  LGCY_CODEBLKREG_predcntr_acdc_pred_counter(data)                        (0x000000FF&(data))
#define  LGCY_CODEBLKREG_predcntr_get_write_enable3(data)                        ((0x40000000&(data))>>30)
#define  LGCY_CODEBLKREG_predcntr_get_cabac_pred_counter(data)                   ((0x3FF00000&(data))>>20)
#define  LGCY_CODEBLKREG_predcntr_get_write_enable2(data)                        ((0x00080000&(data))>>19)
#define  LGCY_CODEBLKREG_predcntr_get_vld_pred_counter(data)                     ((0x0007FE00&(data))>>9)
#define  LGCY_CODEBLKREG_predcntr_get_write_enable1(data)                        ((0x00000100&(data))>>8)
#define  LGCY_CODEBLKREG_predcntr_get_acdc_pred_counter(data)                    (0x000000FF&(data))

#define  LGCY_CODEBLKREG_total_coef1                                             0x1800E014
#define  LGCY_CODEBLKREG_total_coef1_reg_addr                                    "0xB800E014"
#define  LGCY_CODEBLKREG_total_coef1_reg                                         0xB800E014
#define  LGCY_CODEBLKREG_total_coef1_inst_addr                                   "0x0005"
#define  set_LGCY_CODEBLKREG_total_coef1_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_total_coef1_reg)=data)
#define  get_LGCY_CODEBLKREG_total_coef1_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_total_coef1_reg))
#define  LGCY_CODEBLKREG_total_coef1_frame_field_mbpair_shift                    (20)
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_d_shift                       (15)
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_c_shift                       (10)
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_b_shift                       (5)
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_a_shift                       (0)
#define  LGCY_CODEBLKREG_total_coef1_frame_field_mbpair_mask                     (0x00100000)
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_d_mask                        (0x000F8000)
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_c_mask                        (0x00007C00)
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_b_mask                        (0x000003E0)
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_a_mask                        (0x0000001F)
#define  LGCY_CODEBLKREG_total_coef1_frame_field_mbpair(data)                    (0x00100000&((data)<<20))
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_d(data)                       (0x000F8000&((data)<<15))
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_c(data)                       (0x00007C00&((data)<<10))
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_b(data)                       (0x000003E0&((data)<<5))
#define  LGCY_CODEBLKREG_total_coef1_left_top_luma_a(data)                       (0x0000001F&(data))
#define  LGCY_CODEBLKREG_total_coef1_get_frame_field_mbpair(data)                ((0x00100000&(data))>>20)
#define  LGCY_CODEBLKREG_total_coef1_get_left_top_luma_d(data)                   ((0x000F8000&(data))>>15)
#define  LGCY_CODEBLKREG_total_coef1_get_left_top_luma_c(data)                   ((0x00007C00&(data))>>10)
#define  LGCY_CODEBLKREG_total_coef1_get_left_top_luma_b(data)                   ((0x000003E0&(data))>>5)
#define  LGCY_CODEBLKREG_total_coef1_get_left_top_luma_a(data)                   (0x0000001F&(data))

#define  LGCY_CODEBLKREG_total_coef2                                             0x1800E018
#define  LGCY_CODEBLKREG_total_coef2_reg_addr                                    "0xB800E018"
#define  LGCY_CODEBLKREG_total_coef2_reg                                         0xB800E018
#define  LGCY_CODEBLKREG_total_coef2_inst_addr                                   "0x0006"
#define  set_LGCY_CODEBLKREG_total_coef2_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_total_coef2_reg)=data)
#define  get_LGCY_CODEBLKREG_total_coef2_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_total_coef2_reg))
#define  LGCY_CODEBLKREG_total_coef2_left_top_cb_a_shift                         (15)
#define  LGCY_CODEBLKREG_total_coef2_left_top_cb_b_shift                         (10)
#define  LGCY_CODEBLKREG_total_coef2_left_top_cr_a_shift                         (5)
#define  LGCY_CODEBLKREG_total_coef2_left_top_cr_b_shift                         (0)
#define  LGCY_CODEBLKREG_total_coef2_left_top_cb_a_mask                          (0x000F8000)
#define  LGCY_CODEBLKREG_total_coef2_left_top_cb_b_mask                          (0x00007C00)
#define  LGCY_CODEBLKREG_total_coef2_left_top_cr_a_mask                          (0x000003E0)
#define  LGCY_CODEBLKREG_total_coef2_left_top_cr_b_mask                          (0x0000001F)
#define  LGCY_CODEBLKREG_total_coef2_left_top_cb_a(data)                         (0x000F8000&((data)<<15))
#define  LGCY_CODEBLKREG_total_coef2_left_top_cb_b(data)                         (0x00007C00&((data)<<10))
#define  LGCY_CODEBLKREG_total_coef2_left_top_cr_a(data)                         (0x000003E0&((data)<<5))
#define  LGCY_CODEBLKREG_total_coef2_left_top_cr_b(data)                         (0x0000001F&(data))
#define  LGCY_CODEBLKREG_total_coef2_get_left_top_cb_a(data)                     ((0x000F8000&(data))>>15)
#define  LGCY_CODEBLKREG_total_coef2_get_left_top_cb_b(data)                     ((0x00007C00&(data))>>10)
#define  LGCY_CODEBLKREG_total_coef2_get_left_top_cr_a(data)                     ((0x000003E0&(data))>>5)
#define  LGCY_CODEBLKREG_total_coef2_get_left_top_cr_b(data)                     (0x0000001F&(data))

#define  LGCY_CODEBLKREG_total_coef3                                             0x1800E01C
#define  LGCY_CODEBLKREG_total_coef3_reg_addr                                    "0xB800E01C"
#define  LGCY_CODEBLKREG_total_coef3_reg                                         0xB800E01C
#define  LGCY_CODEBLKREG_total_coef3_inst_addr                                   "0x0007"
#define  set_LGCY_CODEBLKREG_total_coef3_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_total_coef3_reg)=data)
#define  get_LGCY_CODEBLKREG_total_coef3_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_total_coef3_reg))
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_d_shift                       (15)
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_c_shift                       (10)
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_b_shift                       (5)
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_a_shift                       (0)
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_d_mask                        (0x000F8000)
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_c_mask                        (0x00007C00)
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_b_mask                        (0x000003E0)
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_a_mask                        (0x0000001F)
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_d(data)                       (0x000F8000&((data)<<15))
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_c(data)                       (0x00007C00&((data)<<10))
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_b(data)                       (0x000003E0&((data)<<5))
#define  LGCY_CODEBLKREG_total_coef3_left_bot_luma_a(data)                       (0x0000001F&(data))
#define  LGCY_CODEBLKREG_total_coef3_get_left_bot_luma_d(data)                   ((0x000F8000&(data))>>15)
#define  LGCY_CODEBLKREG_total_coef3_get_left_bot_luma_c(data)                   ((0x00007C00&(data))>>10)
#define  LGCY_CODEBLKREG_total_coef3_get_left_bot_luma_b(data)                   ((0x000003E0&(data))>>5)
#define  LGCY_CODEBLKREG_total_coef3_get_left_bot_luma_a(data)                   (0x0000001F&(data))

#define  LGCY_CODEBLKREG_total_coef4                                             0x1800E020
#define  LGCY_CODEBLKREG_total_coef4_reg_addr                                    "0xB800E020"
#define  LGCY_CODEBLKREG_total_coef4_reg                                         0xB800E020
#define  LGCY_CODEBLKREG_total_coef4_inst_addr                                   "0x0008"
#define  set_LGCY_CODEBLKREG_total_coef4_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_total_coef4_reg)=data)
#define  get_LGCY_CODEBLKREG_total_coef4_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_total_coef4_reg))
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cb_a_shift                         (15)
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cb_b_shift                         (10)
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cr_a_shift                         (5)
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cr_b_shift                         (0)
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cb_a_mask                          (0x000F8000)
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cb_b_mask                          (0x00007C00)
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cr_a_mask                          (0x000003E0)
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cr_b_mask                          (0x0000001F)
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cb_a(data)                         (0x000F8000&((data)<<15))
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cb_b(data)                         (0x00007C00&((data)<<10))
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cr_a(data)                         (0x000003E0&((data)<<5))
#define  LGCY_CODEBLKREG_total_coef4_left_bot_cr_b(data)                         (0x0000001F&(data))
#define  LGCY_CODEBLKREG_total_coef4_get_left_bot_cb_a(data)                     ((0x000F8000&(data))>>15)
#define  LGCY_CODEBLKREG_total_coef4_get_left_bot_cb_b(data)                     ((0x00007C00&(data))>>10)
#define  LGCY_CODEBLKREG_total_coef4_get_left_bot_cr_a(data)                     ((0x000003E0&(data))>>5)
#define  LGCY_CODEBLKREG_total_coef4_get_left_bot_cr_b(data)                     (0x0000001F&(data))

#define  LGCY_CODEBLKREG_ve_avs_cntl                                             0x1800E080
#define  LGCY_CODEBLKREG_ve_avs_cntl_reg_addr                                    "0xB800E080"
#define  LGCY_CODEBLKREG_ve_avs_cntl_reg                                         0xB800E080
#define  LGCY_CODEBLKREG_ve_avs_cntl_inst_addr                                   "0x0009"
#define  set_LGCY_CODEBLKREG_ve_avs_cntl_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_avs_cntl_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_avs_cntl_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_avs_cntl_reg))
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable8_shift                         (26)
#define  LGCY_CODEBLKREG_ve_avs_cntl_ch_q_param_delta_v_shift                    (20)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable7_shift                         (19)
#define  LGCY_CODEBLKREG_ve_avs_cntl_ch_q_param_delta_u_shift                    (13)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable6_shift                         (12)
#define  LGCY_CODEBLKREG_ve_avs_cntl_pb_fld_enhanced_flg_shift                   (11)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable5_shift                         (10)
#define  LGCY_CODEBLKREG_ve_avs_cntl_frame_pic_type_shift                        (8)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable4_shift                         (7)
#define  LGCY_CODEBLKREG_ve_avs_cntl_skip_mode_flag_shift                        (6)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable3_shift                         (5)
#define  LGCY_CODEBLKREG_ve_avs_cntl_fixedqp_shift                               (4)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable2_shift                         (3)
#define  LGCY_CODEBLKREG_ve_avs_cntl_mbweightingflg_shift                        (2)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable1_shift                         (1)
#define  LGCY_CODEBLKREG_ve_avs_cntl_pic_ref_flg_shift                           (0)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable8_mask                          (0x04000000)
#define  LGCY_CODEBLKREG_ve_avs_cntl_ch_q_param_delta_v_mask                     (0x03F00000)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable7_mask                          (0x00080000)
#define  LGCY_CODEBLKREG_ve_avs_cntl_ch_q_param_delta_u_mask                     (0x0007E000)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable6_mask                          (0x00001000)
#define  LGCY_CODEBLKREG_ve_avs_cntl_pb_fld_enhanced_flg_mask                    (0x00000800)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable5_mask                          (0x00000400)
#define  LGCY_CODEBLKREG_ve_avs_cntl_frame_pic_type_mask                         (0x00000300)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable4_mask                          (0x00000080)
#define  LGCY_CODEBLKREG_ve_avs_cntl_skip_mode_flag_mask                         (0x00000040)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable3_mask                          (0x00000020)
#define  LGCY_CODEBLKREG_ve_avs_cntl_fixedqp_mask                                (0x00000010)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable2_mask                          (0x00000008)
#define  LGCY_CODEBLKREG_ve_avs_cntl_mbweightingflg_mask                         (0x00000004)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable1_mask                          (0x00000002)
#define  LGCY_CODEBLKREG_ve_avs_cntl_pic_ref_flg_mask                            (0x00000001)
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable8(data)                         (0x04000000&((data)<<26))
#define  LGCY_CODEBLKREG_ve_avs_cntl_ch_q_param_delta_v(data)                    (0x03F00000&((data)<<20))
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable7(data)                         (0x00080000&((data)<<19))
#define  LGCY_CODEBLKREG_ve_avs_cntl_ch_q_param_delta_u(data)                    (0x0007E000&((data)<<13))
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable6(data)                         (0x00001000&((data)<<12))
#define  LGCY_CODEBLKREG_ve_avs_cntl_pb_fld_enhanced_flg(data)                   (0x00000800&((data)<<11))
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable5(data)                         (0x00000400&((data)<<10))
#define  LGCY_CODEBLKREG_ve_avs_cntl_frame_pic_type(data)                        (0x00000300&((data)<<8))
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable4(data)                         (0x00000080&((data)<<7))
#define  LGCY_CODEBLKREG_ve_avs_cntl_skip_mode_flag(data)                        (0x00000040&((data)<<6))
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable3(data)                         (0x00000020&((data)<<5))
#define  LGCY_CODEBLKREG_ve_avs_cntl_fixedqp(data)                               (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable2(data)                         (0x00000008&((data)<<3))
#define  LGCY_CODEBLKREG_ve_avs_cntl_mbweightingflg(data)                        (0x00000004&((data)<<2))
#define  LGCY_CODEBLKREG_ve_avs_cntl_write_enable1(data)                         (0x00000002&((data)<<1))
#define  LGCY_CODEBLKREG_ve_avs_cntl_pic_ref_flg(data)                           (0x00000001&(data))
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_write_enable8(data)                     ((0x04000000&(data))>>26)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_ch_q_param_delta_v(data)                ((0x03F00000&(data))>>20)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_write_enable7(data)                     ((0x00080000&(data))>>19)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_ch_q_param_delta_u(data)                ((0x0007E000&(data))>>13)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_write_enable6(data)                     ((0x00001000&(data))>>12)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_pb_fld_enhanced_flg(data)               ((0x00000800&(data))>>11)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_write_enable5(data)                     ((0x00000400&(data))>>10)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_frame_pic_type(data)                    ((0x00000300&(data))>>8)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_write_enable4(data)                     ((0x00000080&(data))>>7)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_skip_mode_flag(data)                    ((0x00000040&(data))>>6)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_write_enable3(data)                     ((0x00000020&(data))>>5)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_fixedqp(data)                           ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_write_enable2(data)                     ((0x00000008&(data))>>3)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_mbweightingflg(data)                    ((0x00000004&(data))>>2)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_write_enable1(data)                     ((0x00000002&(data))>>1)
#define  LGCY_CODEBLKREG_ve_avs_cntl_get_pic_ref_flg(data)                       (0x00000001&(data))

#define  LGCY_CODEBLKREG_ve_h264_cntl                                            0x1800E100
#define  LGCY_CODEBLKREG_ve_h264_cntl_reg_addr                                   "0xB800E100"
#define  LGCY_CODEBLKREG_ve_h264_cntl_reg                                        0xB800E100
#define  LGCY_CODEBLKREG_ve_h264_cntl_inst_addr                                  "0x000A"
#define  set_LGCY_CODEBLKREG_ve_h264_cntl_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_h264_cntl_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_h264_cntl_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_h264_cntl_reg))
#define  LGCY_CODEBLKREG_ve_h264_cntl_qpprime_y_zero_transform_bypass_flag_shift (29)
#define  LGCY_CODEBLKREG_ve_h264_cntl_entropy_coding_mode_shift                  (28)
#define  LGCY_CODEBLKREG_ve_h264_cntl_pic_init_qp_shift                          (22)
#define  LGCY_CODEBLKREG_ve_h264_cntl_chroma_qp_offset_shift                     (17)
#define  LGCY_CODEBLKREG_ve_h264_cntl_second_chroma_qp_offset_shift              (12)
#define  LGCY_CODEBLKREG_ve_h264_cntl_direct_8x8_inferflg_shift                  (11)
#define  LGCY_CODEBLKREG_ve_h264_cntl_transform_8x8_mode_flg_shift               (10)
#define  LGCY_CODEBLKREG_ve_h264_cntl_num_ref_idx_l0_active_minus1_shift         (5)
#define  LGCY_CODEBLKREG_ve_h264_cntl_num_ref_idx_l1_active_minus1_shift         (0)
#define  LGCY_CODEBLKREG_ve_h264_cntl_qpprime_y_zero_transform_bypass_flag_mask  (0x20000000)
#define  LGCY_CODEBLKREG_ve_h264_cntl_entropy_coding_mode_mask                   (0x10000000)
#define  LGCY_CODEBLKREG_ve_h264_cntl_pic_init_qp_mask                           (0x0FC00000)
#define  LGCY_CODEBLKREG_ve_h264_cntl_chroma_qp_offset_mask                      (0x003E0000)
#define  LGCY_CODEBLKREG_ve_h264_cntl_second_chroma_qp_offset_mask               (0x0001F000)
#define  LGCY_CODEBLKREG_ve_h264_cntl_direct_8x8_inferflg_mask                   (0x00000800)
#define  LGCY_CODEBLKREG_ve_h264_cntl_transform_8x8_mode_flg_mask                (0x00000400)
#define  LGCY_CODEBLKREG_ve_h264_cntl_num_ref_idx_l0_active_minus1_mask          (0x000003E0)
#define  LGCY_CODEBLKREG_ve_h264_cntl_num_ref_idx_l1_active_minus1_mask          (0x0000001F)
#define  LGCY_CODEBLKREG_ve_h264_cntl_qpprime_y_zero_transform_bypass_flag(data) (0x20000000&((data)<<29))
#define  LGCY_CODEBLKREG_ve_h264_cntl_entropy_coding_mode(data)                  (0x10000000&((data)<<28))
#define  LGCY_CODEBLKREG_ve_h264_cntl_pic_init_qp(data)                          (0x0FC00000&((data)<<22))
#define  LGCY_CODEBLKREG_ve_h264_cntl_chroma_qp_offset(data)                     (0x003E0000&((data)<<17))
#define  LGCY_CODEBLKREG_ve_h264_cntl_second_chroma_qp_offset(data)              (0x0001F000&((data)<<12))
#define  LGCY_CODEBLKREG_ve_h264_cntl_direct_8x8_inferflg(data)                  (0x00000800&((data)<<11))
#define  LGCY_CODEBLKREG_ve_h264_cntl_transform_8x8_mode_flg(data)               (0x00000400&((data)<<10))
#define  LGCY_CODEBLKREG_ve_h264_cntl_num_ref_idx_l0_active_minus1(data)         (0x000003E0&((data)<<5))
#define  LGCY_CODEBLKREG_ve_h264_cntl_num_ref_idx_l1_active_minus1(data)         (0x0000001F&(data))
#define  LGCY_CODEBLKREG_ve_h264_cntl_get_qpprime_y_zero_transform_bypass_flag(data) ((0x20000000&(data))>>29)
#define  LGCY_CODEBLKREG_ve_h264_cntl_get_entropy_coding_mode(data)              ((0x10000000&(data))>>28)
#define  LGCY_CODEBLKREG_ve_h264_cntl_get_pic_init_qp(data)                      ((0x0FC00000&(data))>>22)
#define  LGCY_CODEBLKREG_ve_h264_cntl_get_chroma_qp_offset(data)                 ((0x003E0000&(data))>>17)
#define  LGCY_CODEBLKREG_ve_h264_cntl_get_second_chroma_qp_offset(data)          ((0x0001F000&(data))>>12)
#define  LGCY_CODEBLKREG_ve_h264_cntl_get_direct_8x8_inferflg(data)              ((0x00000800&(data))>>11)
#define  LGCY_CODEBLKREG_ve_h264_cntl_get_transform_8x8_mode_flg(data)           ((0x00000400&(data))>>10)
#define  LGCY_CODEBLKREG_ve_h264_cntl_get_num_ref_idx_l0_active_minus1(data)     ((0x000003E0&(data))>>5)
#define  LGCY_CODEBLKREG_ve_h264_cntl_get_num_ref_idx_l1_active_minus1(data)     (0x0000001F&(data))

#define  LGCY_CODEBLKREG_ve_h264_cntl2                                           0x1800E104
#define  LGCY_CODEBLKREG_ve_h264_cntl2_reg_addr                                  "0xB800E104"
#define  LGCY_CODEBLKREG_ve_h264_cntl2_reg                                       0xB800E104
#define  LGCY_CODEBLKREG_ve_h264_cntl2_inst_addr                                 "0x000B"
#define  set_LGCY_CODEBLKREG_ve_h264_cntl2_reg(data)                             (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_h264_cntl2_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_h264_cntl2_reg                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_h264_cntl2_reg))
#define  LGCY_CODEBLKREG_ve_h264_cntl2_write_enable3_shift                       (14)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_pic_type_shift                            (11)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_write_enable2_shift                       (10)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_slice_qp_delta_shift                      (3)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_write_enable1_shift                       (2)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_cabac_init_idc_shift                      (0)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_write_enable3_mask                        (0x00004000)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_pic_type_mask                             (0x00003800)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_write_enable2_mask                        (0x00000400)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_slice_qp_delta_mask                       (0x000003F8)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_write_enable1_mask                        (0x00000004)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_cabac_init_idc_mask                       (0x00000003)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_write_enable3(data)                       (0x00004000&((data)<<14))
#define  LGCY_CODEBLKREG_ve_h264_cntl2_pic_type(data)                            (0x00003800&((data)<<11))
#define  LGCY_CODEBLKREG_ve_h264_cntl2_write_enable2(data)                       (0x00000400&((data)<<10))
#define  LGCY_CODEBLKREG_ve_h264_cntl2_slice_qp_delta(data)                      (0x000003F8&((data)<<3))
#define  LGCY_CODEBLKREG_ve_h264_cntl2_write_enable1(data)                       (0x00000004&((data)<<2))
#define  LGCY_CODEBLKREG_ve_h264_cntl2_cabac_init_idc(data)                      (0x00000003&(data))
#define  LGCY_CODEBLKREG_ve_h264_cntl2_get_write_enable3(data)                   ((0x00004000&(data))>>14)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_get_pic_type(data)                        ((0x00003800&(data))>>11)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_get_write_enable2(data)                   ((0x00000400&(data))>>10)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_get_slice_qp_delta(data)                  ((0x000003F8&(data))>>3)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_get_write_enable1(data)                   ((0x00000004&(data))>>2)
#define  LGCY_CODEBLKREG_ve_h264_cntl2_get_cabac_init_idc(data)                  (0x00000003&(data))

#define  LGCY_CODEBLKREG_ve_vc1quant                                             0x1800E108
#define  LGCY_CODEBLKREG_ve_vc1quant_reg_addr                                    "0xB800E108"
#define  LGCY_CODEBLKREG_ve_vc1quant_reg                                         0xB800E108
#define  LGCY_CODEBLKREG_ve_vc1quant_inst_addr                                   "0x000C"
#define  set_LGCY_CODEBLKREG_ve_vc1quant_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1quant_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_vc1quant_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1quant_reg))
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable8_shift                         (25)
#define  LGCY_CODEBLKREG_ve_vc1quant_quan_type_shift                             (24)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable7_shift                         (23)
#define  LGCY_CODEBLKREG_ve_vc1quant_dquant_shift                                (21)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable6_shift                         (20)
#define  LGCY_CODEBLKREG_ve_vc1quant_pqindex_shift                               (15)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable5_shift                         (14)
#define  LGCY_CODEBLKREG_ve_vc1quant_halfqp_shift                                (13)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable4_shift                         (12)
#define  LGCY_CODEBLKREG_ve_vc1quant_altpquant_shift                             (7)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable3_shift                         (6)
#define  LGCY_CODEBLKREG_ve_vc1quant_dquantfrm_shift                             (5)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable2_shift                         (4)
#define  LGCY_CODEBLKREG_ve_vc1quant_dqprofile_shift                             (2)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable1_shift                         (1)
#define  LGCY_CODEBLKREG_ve_vc1quant_dqbilevel_shift                             (0)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable8_mask                          (0x02000000)
#define  LGCY_CODEBLKREG_ve_vc1quant_quan_type_mask                              (0x01000000)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable7_mask                          (0x00800000)
#define  LGCY_CODEBLKREG_ve_vc1quant_dquant_mask                                 (0x00600000)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable6_mask                          (0x00100000)
#define  LGCY_CODEBLKREG_ve_vc1quant_pqindex_mask                                (0x000F8000)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable5_mask                          (0x00004000)
#define  LGCY_CODEBLKREG_ve_vc1quant_halfqp_mask                                 (0x00002000)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable4_mask                          (0x00001000)
#define  LGCY_CODEBLKREG_ve_vc1quant_altpquant_mask                              (0x00000F80)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable3_mask                          (0x00000040)
#define  LGCY_CODEBLKREG_ve_vc1quant_dquantfrm_mask                              (0x00000020)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable2_mask                          (0x00000010)
#define  LGCY_CODEBLKREG_ve_vc1quant_dqprofile_mask                              (0x0000000C)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable1_mask                          (0x00000002)
#define  LGCY_CODEBLKREG_ve_vc1quant_dqbilevel_mask                              (0x00000001)
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable8(data)                         (0x02000000&((data)<<25))
#define  LGCY_CODEBLKREG_ve_vc1quant_quan_type(data)                             (0x01000000&((data)<<24))
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable7(data)                         (0x00800000&((data)<<23))
#define  LGCY_CODEBLKREG_ve_vc1quant_dquant(data)                                (0x00600000&((data)<<21))
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable6(data)                         (0x00100000&((data)<<20))
#define  LGCY_CODEBLKREG_ve_vc1quant_pqindex(data)                               (0x000F8000&((data)<<15))
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable5(data)                         (0x00004000&((data)<<14))
#define  LGCY_CODEBLKREG_ve_vc1quant_halfqp(data)                                (0x00002000&((data)<<13))
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable4(data)                         (0x00001000&((data)<<12))
#define  LGCY_CODEBLKREG_ve_vc1quant_altpquant(data)                             (0x00000F80&((data)<<7))
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable3(data)                         (0x00000040&((data)<<6))
#define  LGCY_CODEBLKREG_ve_vc1quant_dquantfrm(data)                             (0x00000020&((data)<<5))
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable2(data)                         (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_ve_vc1quant_dqprofile(data)                             (0x0000000C&((data)<<2))
#define  LGCY_CODEBLKREG_ve_vc1quant_write_enable1(data)                         (0x00000002&((data)<<1))
#define  LGCY_CODEBLKREG_ve_vc1quant_dqbilevel(data)                             (0x00000001&(data))
#define  LGCY_CODEBLKREG_ve_vc1quant_get_write_enable8(data)                     ((0x02000000&(data))>>25)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_quan_type(data)                         ((0x01000000&(data))>>24)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_write_enable7(data)                     ((0x00800000&(data))>>23)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_dquant(data)                            ((0x00600000&(data))>>21)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_write_enable6(data)                     ((0x00100000&(data))>>20)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_pqindex(data)                           ((0x000F8000&(data))>>15)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_write_enable5(data)                     ((0x00004000&(data))>>14)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_halfqp(data)                            ((0x00002000&(data))>>13)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_write_enable4(data)                     ((0x00001000&(data))>>12)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_altpquant(data)                         ((0x00000F80&(data))>>7)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_write_enable3(data)                     ((0x00000040&(data))>>6)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_dquantfrm(data)                         ((0x00000020&(data))>>5)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_write_enable2(data)                     ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_dqprofile(data)                         ((0x0000000C&(data))>>2)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_write_enable1(data)                     ((0x00000002&(data))>>1)
#define  LGCY_CODEBLKREG_ve_vc1quant_get_dqbilevel(data)                         (0x00000001&(data))

#define  LGCY_CODEBLKREG_ve_vc1transform                                         0x1800E10C
#define  LGCY_CODEBLKREG_ve_vc1transform_reg_addr                                "0xB800E10C"
#define  LGCY_CODEBLKREG_ve_vc1transform_reg                                     0xB800E10C
#define  LGCY_CODEBLKREG_ve_vc1transform_inst_addr                               "0x000D"
#define  set_LGCY_CODEBLKREG_ve_vc1transform_reg(data)                           (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1transform_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_vc1transform_reg                                 (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1transform_reg))
#define  LGCY_CODEBLKREG_ve_vc1transform_ttmbf_shift                             (0)
#define  LGCY_CODEBLKREG_ve_vc1transform_ttmbf_mask                              (0x00000001)
#define  LGCY_CODEBLKREG_ve_vc1transform_ttmbf(data)                             (0x00000001&(data))
#define  LGCY_CODEBLKREG_ve_vc1transform_get_ttmbf(data)                         (0x00000001&(data))

#define  LGCY_CODEBLKREG_ve_vc1mv                                                0x1800E110
#define  LGCY_CODEBLKREG_ve_vc1mv_reg_addr                                       "0xB800E110"
#define  LGCY_CODEBLKREG_ve_vc1mv_reg                                            0xB800E110
#define  LGCY_CODEBLKREG_ve_vc1mv_inst_addr                                      "0x000E"
#define  set_LGCY_CODEBLKREG_ve_vc1mv_reg(data)                                  (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1mv_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_vc1mv_reg                                        (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1mv_reg))
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable5_shift                            (26)
#define  LGCY_CODEBLKREG_ve_vc1mv_vc1mvtab_shift                                 (23)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable4_shift                            (22)
#define  LGCY_CODEBLKREG_ve_vc1mv_mvrange_kx_shift                               (18)
#define  LGCY_CODEBLKREG_ve_vc1mv_mvrange_ky_shift                               (14)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable3_shift                            (13)
#define  LGCY_CODEBLKREG_ve_vc1mv_dmv_extend_x_shift                             (12)
#define  LGCY_CODEBLKREG_ve_vc1mv_dmv_extend_y_shift                             (11)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable2_shift                            (10)
#define  LGCY_CODEBLKREG_ve_vc1mv_tab2mvbp_shift                                 (8)
#define  LGCY_CODEBLKREG_ve_vc1mv_tab4mvbp_shift                                 (6)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable1_shift                            (5)
#define  LGCY_CODEBLKREG_ve_vc1mv_bfraction_shift                                (0)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable5_mask                             (0x04000000)
#define  LGCY_CODEBLKREG_ve_vc1mv_vc1mvtab_mask                                  (0x03800000)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable4_mask                             (0x00400000)
#define  LGCY_CODEBLKREG_ve_vc1mv_mvrange_kx_mask                                (0x003C0000)
#define  LGCY_CODEBLKREG_ve_vc1mv_mvrange_ky_mask                                (0x0003C000)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable3_mask                             (0x00002000)
#define  LGCY_CODEBLKREG_ve_vc1mv_dmv_extend_x_mask                              (0x00001000)
#define  LGCY_CODEBLKREG_ve_vc1mv_dmv_extend_y_mask                              (0x00000800)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable2_mask                             (0x00000400)
#define  LGCY_CODEBLKREG_ve_vc1mv_tab2mvbp_mask                                  (0x00000300)
#define  LGCY_CODEBLKREG_ve_vc1mv_tab4mvbp_mask                                  (0x000000C0)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable1_mask                             (0x00000020)
#define  LGCY_CODEBLKREG_ve_vc1mv_bfraction_mask                                 (0x0000001F)
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable5(data)                            (0x04000000&((data)<<26))
#define  LGCY_CODEBLKREG_ve_vc1mv_vc1mvtab(data)                                 (0x03800000&((data)<<23))
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable4(data)                            (0x00400000&((data)<<22))
#define  LGCY_CODEBLKREG_ve_vc1mv_mvrange_kx(data)                               (0x003C0000&((data)<<18))
#define  LGCY_CODEBLKREG_ve_vc1mv_mvrange_ky(data)                               (0x0003C000&((data)<<14))
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable3(data)                            (0x00002000&((data)<<13))
#define  LGCY_CODEBLKREG_ve_vc1mv_dmv_extend_x(data)                             (0x00001000&((data)<<12))
#define  LGCY_CODEBLKREG_ve_vc1mv_dmv_extend_y(data)                             (0x00000800&((data)<<11))
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable2(data)                            (0x00000400&((data)<<10))
#define  LGCY_CODEBLKREG_ve_vc1mv_tab2mvbp(data)                                 (0x00000300&((data)<<8))
#define  LGCY_CODEBLKREG_ve_vc1mv_tab4mvbp(data)                                 (0x000000C0&((data)<<6))
#define  LGCY_CODEBLKREG_ve_vc1mv_write_enable1(data)                            (0x00000020&((data)<<5))
#define  LGCY_CODEBLKREG_ve_vc1mv_bfraction(data)                                (0x0000001F&(data))
#define  LGCY_CODEBLKREG_ve_vc1mv_get_write_enable5(data)                        ((0x04000000&(data))>>26)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_vc1mvtab(data)                             ((0x03800000&(data))>>23)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_write_enable4(data)                        ((0x00400000&(data))>>22)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_mvrange_kx(data)                           ((0x003C0000&(data))>>18)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_mvrange_ky(data)                           ((0x0003C000&(data))>>14)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_write_enable3(data)                        ((0x00002000&(data))>>13)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_dmv_extend_x(data)                         ((0x00001000&(data))>>12)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_dmv_extend_y(data)                         ((0x00000800&(data))>>11)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_write_enable2(data)                        ((0x00000400&(data))>>10)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_tab2mvbp(data)                             ((0x00000300&(data))>>8)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_tab4mvbp(data)                             ((0x000000C0&(data))>>6)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_write_enable1(data)                        ((0x00000020&(data))>>5)
#define  LGCY_CODEBLKREG_ve_vc1mv_get_bfraction(data)                            (0x0000001F&(data))

#define  LGCY_CODEBLKREG_ve_mvfcode                                              0x1800E114
#define  LGCY_CODEBLKREG_ve_mvfcode_reg_addr                                     "0xB800E114"
#define  LGCY_CODEBLKREG_ve_mvfcode_reg                                          0xB800E114
#define  LGCY_CODEBLKREG_ve_mvfcode_inst_addr                                    "0x000F"
#define  set_LGCY_CODEBLKREG_ve_mvfcode_reg(data)                                (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_mvfcode_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_mvfcode_reg                                      (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_mvfcode_reg))
#define  LGCY_CODEBLKREG_ve_mvfcode_write_enable6_shift                          (17)
#define  LGCY_CODEBLKREG_ve_mvfcode_bk_x_fcode_shift                             (13)
#define  LGCY_CODEBLKREG_ve_mvfcode_bk_y_fcode_shift                             (9)
#define  LGCY_CODEBLKREG_ve_mvfcode_write_enable5_shift                          (8)
#define  LGCY_CODEBLKREG_ve_mvfcode_fo_x_fcode_shift                             (4)
#define  LGCY_CODEBLKREG_ve_mvfcode_fo_y_fcode_shift                             (0)
#define  LGCY_CODEBLKREG_ve_mvfcode_write_enable6_mask                           (0x00020000)
#define  LGCY_CODEBLKREG_ve_mvfcode_bk_x_fcode_mask                              (0x0001E000)
#define  LGCY_CODEBLKREG_ve_mvfcode_bk_y_fcode_mask                              (0x00001E00)
#define  LGCY_CODEBLKREG_ve_mvfcode_write_enable5_mask                           (0x00000100)
#define  LGCY_CODEBLKREG_ve_mvfcode_fo_x_fcode_mask                              (0x000000F0)
#define  LGCY_CODEBLKREG_ve_mvfcode_fo_y_fcode_mask                              (0x0000000F)
#define  LGCY_CODEBLKREG_ve_mvfcode_write_enable6(data)                          (0x00020000&((data)<<17))
#define  LGCY_CODEBLKREG_ve_mvfcode_bk_x_fcode(data)                             (0x0001E000&((data)<<13))
#define  LGCY_CODEBLKREG_ve_mvfcode_bk_y_fcode(data)                             (0x00001E00&((data)<<9))
#define  LGCY_CODEBLKREG_ve_mvfcode_write_enable5(data)                          (0x00000100&((data)<<8))
#define  LGCY_CODEBLKREG_ve_mvfcode_fo_x_fcode(data)                             (0x000000F0&((data)<<4))
#define  LGCY_CODEBLKREG_ve_mvfcode_fo_y_fcode(data)                             (0x0000000F&(data))
#define  LGCY_CODEBLKREG_ve_mvfcode_get_write_enable6(data)                      ((0x00020000&(data))>>17)
#define  LGCY_CODEBLKREG_ve_mvfcode_get_bk_x_fcode(data)                         ((0x0001E000&(data))>>13)
#define  LGCY_CODEBLKREG_ve_mvfcode_get_bk_y_fcode(data)                         ((0x00001E00&(data))>>9)
#define  LGCY_CODEBLKREG_ve_mvfcode_get_write_enable5(data)                      ((0x00000100&(data))>>8)
#define  LGCY_CODEBLKREG_ve_mvfcode_get_fo_x_fcode(data)                         ((0x000000F0&(data))>>4)
#define  LGCY_CODEBLKREG_ve_mvfcode_get_fo_y_fcode(data)                         (0x0000000F&(data))

#define  LGCY_CODEBLKREG_ve_vc1table                                             0x1800E118
#define  LGCY_CODEBLKREG_ve_vc1table_reg_addr                                    "0xB800E118"
#define  LGCY_CODEBLKREG_ve_vc1table_reg                                         0xB800E118
#define  LGCY_CODEBLKREG_ve_vc1table_inst_addr                                   "0x0010"
#define  set_LGCY_CODEBLKREG_ve_vc1table_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1table_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_vc1table_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1table_reg))
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable5_shift                         (16)
#define  LGCY_CODEBLKREG_ve_vc1table_dctable_sel_shift                           (15)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable4_shift                         (14)
#define  LGCY_CODEBLKREG_ve_vc1table_transacfrm_shift                            (12)
#define  LGCY_CODEBLKREG_ve_vc1table_transacfrm2_shift                           (10)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable3_shift                         (9)
#define  LGCY_CODEBLKREG_ve_vc1table_cbp_table_shift                             (6)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable2_shift                         (5)
#define  LGCY_CODEBLKREG_ve_vc1table_flg_4mvswitch_shift                         (4)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable1_shift                         (3)
#define  LGCY_CODEBLKREG_ve_vc1table_mbmodetab_shift                             (0)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable5_mask                          (0x00010000)
#define  LGCY_CODEBLKREG_ve_vc1table_dctable_sel_mask                            (0x00008000)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable4_mask                          (0x00004000)
#define  LGCY_CODEBLKREG_ve_vc1table_transacfrm_mask                             (0x00003000)
#define  LGCY_CODEBLKREG_ve_vc1table_transacfrm2_mask                            (0x00000C00)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable3_mask                          (0x00000200)
#define  LGCY_CODEBLKREG_ve_vc1table_cbp_table_mask                              (0x000001C0)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable2_mask                          (0x00000020)
#define  LGCY_CODEBLKREG_ve_vc1table_flg_4mvswitch_mask                          (0x00000010)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable1_mask                          (0x00000008)
#define  LGCY_CODEBLKREG_ve_vc1table_mbmodetab_mask                              (0x00000007)
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable5(data)                         (0x00010000&((data)<<16))
#define  LGCY_CODEBLKREG_ve_vc1table_dctable_sel(data)                           (0x00008000&((data)<<15))
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable4(data)                         (0x00004000&((data)<<14))
#define  LGCY_CODEBLKREG_ve_vc1table_transacfrm(data)                            (0x00003000&((data)<<12))
#define  LGCY_CODEBLKREG_ve_vc1table_transacfrm2(data)                           (0x00000C00&((data)<<10))
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable3(data)                         (0x00000200&((data)<<9))
#define  LGCY_CODEBLKREG_ve_vc1table_cbp_table(data)                             (0x000001C0&((data)<<6))
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable2(data)                         (0x00000020&((data)<<5))
#define  LGCY_CODEBLKREG_ve_vc1table_flg_4mvswitch(data)                         (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_ve_vc1table_write_enable1(data)                         (0x00000008&((data)<<3))
#define  LGCY_CODEBLKREG_ve_vc1table_mbmodetab(data)                             (0x00000007&(data))
#define  LGCY_CODEBLKREG_ve_vc1table_get_write_enable5(data)                     ((0x00010000&(data))>>16)
#define  LGCY_CODEBLKREG_ve_vc1table_get_dctable_sel(data)                       ((0x00008000&(data))>>15)
#define  LGCY_CODEBLKREG_ve_vc1table_get_write_enable4(data)                     ((0x00004000&(data))>>14)
#define  LGCY_CODEBLKREG_ve_vc1table_get_transacfrm(data)                        ((0x00003000&(data))>>12)
#define  LGCY_CODEBLKREG_ve_vc1table_get_transacfrm2(data)                       ((0x00000C00&(data))>>10)
#define  LGCY_CODEBLKREG_ve_vc1table_get_write_enable3(data)                     ((0x00000200&(data))>>9)
#define  LGCY_CODEBLKREG_ve_vc1table_get_cbp_table(data)                         ((0x000001C0&(data))>>6)
#define  LGCY_CODEBLKREG_ve_vc1table_get_write_enable2(data)                     ((0x00000020&(data))>>5)
#define  LGCY_CODEBLKREG_ve_vc1table_get_flg_4mvswitch(data)                     ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_ve_vc1table_get_write_enable1(data)                     ((0x00000008&(data))>>3)
#define  LGCY_CODEBLKREG_ve_vc1table_get_mbmodetab(data)                         (0x00000007&(data))

#define  LGCY_CODEBLKREG_ve_vc1esc                                               0x1800E11C
#define  LGCY_CODEBLKREG_ve_vc1esc_reg_addr                                      "0xB800E11C"
#define  LGCY_CODEBLKREG_ve_vc1esc_reg                                           0xB800E11C
#define  LGCY_CODEBLKREG_ve_vc1esc_inst_addr                                     "0x0011"
#define  set_LGCY_CODEBLKREG_ve_vc1esc_reg(data)                                 (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1esc_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_vc1esc_reg                                       (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1esc_reg))
#define  LGCY_CODEBLKREG_ve_vc1esc_write_enable1_shift                           (7)
#define  LGCY_CODEBLKREG_ve_vc1esc_escm3_rsize_shift                             (4)
#define  LGCY_CODEBLKREG_ve_vc1esc_escm3_lsize_shift                             (0)
#define  LGCY_CODEBLKREG_ve_vc1esc_write_enable1_mask                            (0x00000080)
#define  LGCY_CODEBLKREG_ve_vc1esc_escm3_rsize_mask                              (0x00000070)
#define  LGCY_CODEBLKREG_ve_vc1esc_escm3_lsize_mask                              (0x0000000F)
#define  LGCY_CODEBLKREG_ve_vc1esc_write_enable1(data)                           (0x00000080&((data)<<7))
#define  LGCY_CODEBLKREG_ve_vc1esc_escm3_rsize(data)                             (0x00000070&((data)<<4))
#define  LGCY_CODEBLKREG_ve_vc1esc_escm3_lsize(data)                             (0x0000000F&(data))
#define  LGCY_CODEBLKREG_ve_vc1esc_get_write_enable1(data)                       ((0x00000080&(data))>>7)
#define  LGCY_CODEBLKREG_ve_vc1esc_get_escm3_rsize(data)                         ((0x00000070&(data))>>4)
#define  LGCY_CODEBLKREG_ve_vc1esc_get_escm3_lsize(data)                         (0x0000000F&(data))

#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl                                       0x1800E120
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_reg_addr                              "0xB800E120"
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_reg                                   0xB800E120
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_inst_addr                             "0x0012"
#define  set_LGCY_CODEBLKREG_ve_vc1bitpln_cntl_reg(data)                         (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1bitpln_cntl_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_vc1bitpln_cntl_reg                               (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1bitpln_cntl_reg))
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_rowmb_shift                           (24)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_colmb_shift                           (17)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_rowmb_mod3_shift                      (15)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_colmb_mod3_shift                      (13)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_bitplane_len_shift                    (0)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_rowmb_mask                            (0xFF000000)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_colmb_mask                            (0x00FE0000)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_rowmb_mod3_mask                       (0x00018000)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_colmb_mod3_mask                       (0x00006000)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_bitplane_len_mask                     (0x00001FFF)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_rowmb(data)                           (0xFF000000&((data)<<24))
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_colmb(data)                           (0x00FE0000&((data)<<17))
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_rowmb_mod3(data)                      (0x00018000&((data)<<15))
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_colmb_mod3(data)                      (0x00006000&((data)<<13))
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_bitplane_len(data)                    (0x00001FFF&(data))
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_get_rowmb(data)                       ((0xFF000000&(data))>>24)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_get_colmb(data)                       ((0x00FE0000&(data))>>17)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_get_rowmb_mod3(data)                  ((0x00018000&(data))>>15)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_get_colmb_mod3(data)                  ((0x00006000&(data))>>13)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_cntl_get_bitplane_len(data)                (0x00001FFF&(data))

#define  LGCY_CODEBLKREG_ve_vc1bitpln_base                                       0x1800E124
#define  LGCY_CODEBLKREG_ve_vc1bitpln_base_reg_addr                              "0xB800E124"
#define  LGCY_CODEBLKREG_ve_vc1bitpln_base_reg                                   0xB800E124
#define  LGCY_CODEBLKREG_ve_vc1bitpln_base_inst_addr                             "0x0013"
#define  set_LGCY_CODEBLKREG_ve_vc1bitpln_base_reg(data)                         (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1bitpln_base_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_vc1bitpln_base_reg                               (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_vc1bitpln_base_reg))
#define  LGCY_CODEBLKREG_ve_vc1bitpln_base_bitplane_addr_shift                   (0)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_base_bitplane_addr_mask                    (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ve_vc1bitpln_base_bitplane_addr(data)                   (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_vc1bitpln_base_get_bitplane_addr(data)               (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_ldstaddr                                             0x1800E128
#define  LGCY_CODEBLKREG_ve_ldstaddr_reg_addr                                    "0xB800E128"
#define  LGCY_CODEBLKREG_ve_ldstaddr_reg                                         0xB800E128
#define  LGCY_CODEBLKREG_ve_ldstaddr_inst_addr                                   "0x0014"
#define  set_LGCY_CODEBLKREG_ve_ldstaddr_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_ldstaddr_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_ldstaddr_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_ldstaddr_reg))
#define  LGCY_CODEBLKREG_ve_ldstaddr_ldst_addr_shift                             (0)
#define  LGCY_CODEBLKREG_ve_ldstaddr_ldst_addr_mask                              (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ve_ldstaddr_ldst_addr(data)                             (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_ldstaddr_get_ldst_addr(data)                         (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_decbitcnt                                            0x1800E200
#define  LGCY_CODEBLKREG_ve_decbitcnt_reg_addr                                   "0xB800E200"
#define  LGCY_CODEBLKREG_ve_decbitcnt_reg                                        0xB800E200
#define  LGCY_CODEBLKREG_ve_decbitcnt_inst_addr                                  "0x0015"
#define  set_LGCY_CODEBLKREG_ve_decbitcnt_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_decbitcnt_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_decbitcnt_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_decbitcnt_reg))
#define  LGCY_CODEBLKREG_ve_decbitcnt_max_bit_shift                              (0)
#define  LGCY_CODEBLKREG_ve_decbitcnt_max_bit_mask                               (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ve_decbitcnt_max_bit(data)                              (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_decbitcnt_get_max_bit(data)                          (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_vld_bitcnt                                              0x1800E204
#define  LGCY_CODEBLKREG_vld_bitcnt_reg_addr                                     "0xB800E204"
#define  LGCY_CODEBLKREG_vld_bitcnt_reg                                          0xB800E204
#define  LGCY_CODEBLKREG_vld_bitcnt_inst_addr                                    "0x0016"
#define  set_LGCY_CODEBLKREG_vld_bitcnt_reg(data)                                (*((volatile unsigned int*)LGCY_CODEBLKREG_vld_bitcnt_reg)=data)
#define  get_LGCY_CODEBLKREG_vld_bitcnt_reg                                      (*((volatile unsigned int*)LGCY_CODEBLKREG_vld_bitcnt_reg))
#define  LGCY_CODEBLKREG_vld_bitcnt_dec_bitcnt_shift                             (0)
#define  LGCY_CODEBLKREG_vld_bitcnt_dec_bitcnt_mask                              (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_vld_bitcnt_dec_bitcnt(data)                             (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_vld_bitcnt_get_dec_bitcnt(data)                         (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_bscntl                                               0x1800E208
#define  LGCY_CODEBLKREG_ve_bscntl_reg_addr                                      "0xB800E208"
#define  LGCY_CODEBLKREG_ve_bscntl_reg                                           0xB800E208
#define  LGCY_CODEBLKREG_ve_bscntl_inst_addr                                     "0x0017"
#define  set_LGCY_CODEBLKREG_ve_bscntl_reg(data)                                 (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bscntl_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_bscntl_reg                                       (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bscntl_reg))
#define  LGCY_CODEBLKREG_ve_bscntl_write_enable3_shift                           (6)
#define  LGCY_CODEBLKREG_ve_bscntl_detect_startcode_error_shift                  (5)
#define  LGCY_CODEBLKREG_ve_bscntl_write_enable2_shift                           (4)
#define  LGCY_CODEBLKREG_ve_bscntl_min_xfer_size_shift                           (2)
#define  LGCY_CODEBLKREG_ve_bscntl_write_enable1_shift                           (1)
#define  LGCY_CODEBLKREG_ve_bscntl_startcode_prevnt_en_shift                     (0)
#define  LGCY_CODEBLKREG_ve_bscntl_write_enable3_mask                            (0x00000040)
#define  LGCY_CODEBLKREG_ve_bscntl_detect_startcode_error_mask                   (0x00000020)
#define  LGCY_CODEBLKREG_ve_bscntl_write_enable2_mask                            (0x00000010)
#define  LGCY_CODEBLKREG_ve_bscntl_min_xfer_size_mask                            (0x0000000C)
#define  LGCY_CODEBLKREG_ve_bscntl_write_enable1_mask                            (0x00000002)
#define  LGCY_CODEBLKREG_ve_bscntl_startcode_prevnt_en_mask                      (0x00000001)
#define  LGCY_CODEBLKREG_ve_bscntl_write_enable3(data)                           (0x00000040&((data)<<6))
#define  LGCY_CODEBLKREG_ve_bscntl_detect_startcode_error(data)                  (0x00000020&((data)<<5))
#define  LGCY_CODEBLKREG_ve_bscntl_write_enable2(data)                           (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_ve_bscntl_min_xfer_size(data)                           (0x0000000C&((data)<<2))
#define  LGCY_CODEBLKREG_ve_bscntl_write_enable1(data)                           (0x00000002&((data)<<1))
#define  LGCY_CODEBLKREG_ve_bscntl_startcode_prevnt_en(data)                     (0x00000001&(data))
#define  LGCY_CODEBLKREG_ve_bscntl_get_write_enable3(data)                       ((0x00000040&(data))>>6)
#define  LGCY_CODEBLKREG_ve_bscntl_get_detect_startcode_error(data)              ((0x00000020&(data))>>5)
#define  LGCY_CODEBLKREG_ve_bscntl_get_write_enable2(data)                       ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_ve_bscntl_get_min_xfer_size(data)                       ((0x0000000C&(data))>>2)
#define  LGCY_CODEBLKREG_ve_bscntl_get_write_enable1(data)                       ((0x00000002&(data))>>1)
#define  LGCY_CODEBLKREG_ve_bscntl_get_startcode_prevnt_en(data)                 (0x00000001&(data))

#define  LGCY_CODEBLKREG_ve_bs_min_thr                                           0x1800E20C
#define  LGCY_CODEBLKREG_ve_bs_min_thr_reg_addr                                  "0xB800E20C"
#define  LGCY_CODEBLKREG_ve_bs_min_thr_reg                                       0xB800E20C
#define  LGCY_CODEBLKREG_ve_bs_min_thr_inst_addr                                 "0x0018"
#define  set_LGCY_CODEBLKREG_ve_bs_min_thr_reg(data)                             (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bs_min_thr_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_bs_min_thr_reg                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bs_min_thr_reg))
#define  LGCY_CODEBLKREG_ve_bs_min_thr_min_thre_shift                            (0)
#define  LGCY_CODEBLKREG_ve_bs_min_thr_min_thre_mask                             (0x0000007F)
#define  LGCY_CODEBLKREG_ve_bs_min_thr_min_thre(data)                            (0x0000007F&(data))
#define  LGCY_CODEBLKREG_ve_bs_min_thr_get_min_thre(data)                        (0x0000007F&(data))

#define  LGCY_CODEBLKREG_ve_bstimer                                              0x1800E210
#define  LGCY_CODEBLKREG_ve_bstimer_reg_addr                                     "0xB800E210"
#define  LGCY_CODEBLKREG_ve_bstimer_reg                                          0xB800E210
#define  LGCY_CODEBLKREG_ve_bstimer_inst_addr                                    "0x0019"
#define  set_LGCY_CODEBLKREG_ve_bstimer_reg(data)                                (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bstimer_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_bstimer_reg                                      (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bstimer_reg))
#define  LGCY_CODEBLKREG_ve_bstimer_timer_value_shift                            (0)
#define  LGCY_CODEBLKREG_ve_bstimer_timer_value_mask                             (0x00FFFFFF)
#define  LGCY_CODEBLKREG_ve_bstimer_timer_value(data)                            (0x00FFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_bstimer_get_timer_value(data)                        (0x00FFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_bsbase                                               0x1800E214
#define  LGCY_CODEBLKREG_ve_bsbase_reg_addr                                      "0xB800E214"
#define  LGCY_CODEBLKREG_ve_bsbase_reg                                           0xB800E214
#define  LGCY_CODEBLKREG_ve_bsbase_inst_addr                                     "0x001A"
#define  set_LGCY_CODEBLKREG_ve_bsbase_reg(data)                                 (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bsbase_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_bsbase_reg                                       (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bsbase_reg))
#define  LGCY_CODEBLKREG_ve_bsbase_base_addr_shift                               (0)
#define  LGCY_CODEBLKREG_ve_bsbase_base_addr_mask                                (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ve_bsbase_base_addr(data)                               (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_bsbase_get_base_addr(data)                           (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_bslimit                                              0x1800E218
#define  LGCY_CODEBLKREG_ve_bslimit_reg_addr                                     "0xB800E218"
#define  LGCY_CODEBLKREG_ve_bslimit_reg                                          0xB800E218
#define  LGCY_CODEBLKREG_ve_bslimit_inst_addr                                    "0x001B"
#define  set_LGCY_CODEBLKREG_ve_bslimit_reg(data)                                (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bslimit_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_bslimit_reg                                      (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bslimit_reg))
#define  LGCY_CODEBLKREG_ve_bslimit_limit_addr_shift                             (0)
#define  LGCY_CODEBLKREG_ve_bslimit_limit_addr_mask                              (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ve_bslimit_limit_addr(data)                             (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_bslimit_get_limit_addr(data)                         (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_bswrptr                                              0x1800E21C
#define  LGCY_CODEBLKREG_ve_bswrptr_reg_addr                                     "0xB800E21C"
#define  LGCY_CODEBLKREG_ve_bswrptr_reg                                          0xB800E21C
#define  LGCY_CODEBLKREG_ve_bswrptr_inst_addr                                    "0x001C"
#define  set_LGCY_CODEBLKREG_ve_bswrptr_reg(data)                                (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bswrptr_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_bswrptr_reg                                      (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bswrptr_reg))
#define  LGCY_CODEBLKREG_ve_bswrptr_wr_ptr_shift                                 (0)
#define  LGCY_CODEBLKREG_ve_bswrptr_wr_ptr_mask                                  (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ve_bswrptr_wr_ptr(data)                                 (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_bswrptr_get_wr_ptr(data)                             (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_bscurptr                                             0x1800E220
#define  LGCY_CODEBLKREG_ve_bscurptr_reg_addr                                    "0xB800E220"
#define  LGCY_CODEBLKREG_ve_bscurptr_reg                                         0xB800E220
#define  LGCY_CODEBLKREG_ve_bscurptr_inst_addr                                   "0x001D"
#define  set_LGCY_CODEBLKREG_ve_bscurptr_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bscurptr_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_bscurptr_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_bscurptr_reg))
#define  LGCY_CODEBLKREG_ve_bscurptr_cur_ptr_shift                               (0)
#define  LGCY_CODEBLKREG_ve_bscurptr_cur_ptr_mask                                (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ve_bscurptr_cur_ptr(data)                               (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_bscurptr_get_cur_ptr(data)                           (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_decbsptr                                             0x1800E224
#define  LGCY_CODEBLKREG_ve_decbsptr_reg_addr                                    "0xB800E224"
#define  LGCY_CODEBLKREG_ve_decbsptr_reg                                         0xB800E224
#define  LGCY_CODEBLKREG_ve_decbsptr_inst_addr                                   "0x001E"
#define  set_LGCY_CODEBLKREG_ve_decbsptr_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_decbsptr_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_decbsptr_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_decbsptr_reg))
#define  LGCY_CODEBLKREG_ve_decbsptr_dec_bit_ptr_shift                           (0)
#define  LGCY_CODEBLKREG_ve_decbsptr_dec_bit_ptr_mask                            (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ve_decbsptr_dec_bit_ptr(data)                           (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_decbsptr_get_dec_bit_ptr(data)                       (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_jpg_emu_0                                            0x1800E228
#define  LGCY_CODEBLKREG_ve_jpg_emu_0_reg_addr                                   "0xB800E228"
#define  LGCY_CODEBLKREG_ve_jpg_emu_0_reg                                        0xB800E228
#define  LGCY_CODEBLKREG_ve_jpg_emu_0_inst_addr                                  "0x001F"
#define  set_LGCY_CODEBLKREG_ve_jpg_emu_0_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_0_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_jpg_emu_0_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_0_reg))
#define  LGCY_CODEBLKREG_ve_jpg_emu_0_removal_counter_shift                      (0)
#define  LGCY_CODEBLKREG_ve_jpg_emu_0_removal_counter_mask                       (0x1FFFFFFF)
#define  LGCY_CODEBLKREG_ve_jpg_emu_0_removal_counter(data)                      (0x1FFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_jpg_emu_0_get_removal_counter(data)                  (0x1FFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_jpg_emu_1                                            0x1800E22C
#define  LGCY_CODEBLKREG_ve_jpg_emu_1_reg_addr                                   "0xB800E22C"
#define  LGCY_CODEBLKREG_ve_jpg_emu_1_reg                                        0xB800E22C
#define  LGCY_CODEBLKREG_ve_jpg_emu_1_inst_addr                                  "0x0020"
#define  set_LGCY_CODEBLKREG_ve_jpg_emu_1_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_1_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_jpg_emu_1_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_1_reg))
#define  LGCY_CODEBLKREG_ve_jpg_emu_1_removal_counter_shift                      (0)
#define  LGCY_CODEBLKREG_ve_jpg_emu_1_removal_counter_mask                       (0x1FFFFFFF)
#define  LGCY_CODEBLKREG_ve_jpg_emu_1_removal_counter(data)                      (0x1FFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_jpg_emu_1_get_removal_counter(data)                  (0x1FFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_jpg_emu_2                                            0x1800E230
#define  LGCY_CODEBLKREG_ve_jpg_emu_2_reg_addr                                   "0xB800E230"
#define  LGCY_CODEBLKREG_ve_jpg_emu_2_reg                                        0xB800E230
#define  LGCY_CODEBLKREG_ve_jpg_emu_2_inst_addr                                  "0x0021"
#define  set_LGCY_CODEBLKREG_ve_jpg_emu_2_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_2_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_jpg_emu_2_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_2_reg))
#define  LGCY_CODEBLKREG_ve_jpg_emu_2_removal_counter_shift                      (0)
#define  LGCY_CODEBLKREG_ve_jpg_emu_2_removal_counter_mask                       (0x1FFFFFFF)
#define  LGCY_CODEBLKREG_ve_jpg_emu_2_removal_counter(data)                      (0x1FFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_jpg_emu_2_get_removal_counter(data)                  (0x1FFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_jpg_emu_3                                            0x1800E234
#define  LGCY_CODEBLKREG_ve_jpg_emu_3_reg_addr                                   "0xB800E234"
#define  LGCY_CODEBLKREG_ve_jpg_emu_3_reg                                        0xB800E234
#define  LGCY_CODEBLKREG_ve_jpg_emu_3_inst_addr                                  "0x0022"
#define  set_LGCY_CODEBLKREG_ve_jpg_emu_3_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_3_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_jpg_emu_3_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_3_reg))
#define  LGCY_CODEBLKREG_ve_jpg_emu_3_removal_counter_shift                      (0)
#define  LGCY_CODEBLKREG_ve_jpg_emu_3_removal_counter_mask                       (0x1FFFFFFF)
#define  LGCY_CODEBLKREG_ve_jpg_emu_3_removal_counter(data)                      (0x1FFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_jpg_emu_3_get_removal_counter(data)                  (0x1FFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_jpg_emu_4                                            0x1800E238
#define  LGCY_CODEBLKREG_ve_jpg_emu_4_reg_addr                                   "0xB800E238"
#define  LGCY_CODEBLKREG_ve_jpg_emu_4_reg                                        0xB800E238
#define  LGCY_CODEBLKREG_ve_jpg_emu_4_inst_addr                                  "0x0023"
#define  set_LGCY_CODEBLKREG_ve_jpg_emu_4_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_4_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_jpg_emu_4_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_4_reg))
#define  LGCY_CODEBLKREG_ve_jpg_emu_4_removal_counter_shift                      (0)
#define  LGCY_CODEBLKREG_ve_jpg_emu_4_removal_counter_mask                       (0x1FFFFFFF)
#define  LGCY_CODEBLKREG_ve_jpg_emu_4_removal_counter(data)                      (0x1FFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_jpg_emu_4_get_removal_counter(data)                  (0x1FFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_jpg_emu_5                                            0x1800E23C
#define  LGCY_CODEBLKREG_ve_jpg_emu_5_reg_addr                                   "0xB800E23C"
#define  LGCY_CODEBLKREG_ve_jpg_emu_5_reg                                        0xB800E23C
#define  LGCY_CODEBLKREG_ve_jpg_emu_5_inst_addr                                  "0x0024"
#define  set_LGCY_CODEBLKREG_ve_jpg_emu_5_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_5_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_jpg_emu_5_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_5_reg))
#define  LGCY_CODEBLKREG_ve_jpg_emu_5_removal_counter_shift                      (0)
#define  LGCY_CODEBLKREG_ve_jpg_emu_5_removal_counter_mask                       (0x1FFFFFFF)
#define  LGCY_CODEBLKREG_ve_jpg_emu_5_removal_counter(data)                      (0x1FFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_jpg_emu_5_get_removal_counter(data)                  (0x1FFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_jpg_emu_6                                            0x1800E240
#define  LGCY_CODEBLKREG_ve_jpg_emu_6_reg_addr                                   "0xB800E240"
#define  LGCY_CODEBLKREG_ve_jpg_emu_6_reg                                        0xB800E240
#define  LGCY_CODEBLKREG_ve_jpg_emu_6_inst_addr                                  "0x0025"
#define  set_LGCY_CODEBLKREG_ve_jpg_emu_6_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_6_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_jpg_emu_6_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_6_reg))
#define  LGCY_CODEBLKREG_ve_jpg_emu_6_removal_counter_shift                      (0)
#define  LGCY_CODEBLKREG_ve_jpg_emu_6_removal_counter_mask                       (0x1FFFFFFF)
#define  LGCY_CODEBLKREG_ve_jpg_emu_6_removal_counter(data)                      (0x1FFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_jpg_emu_6_get_removal_counter(data)                  (0x1FFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_jpg_emu_7                                            0x1800E244
#define  LGCY_CODEBLKREG_ve_jpg_emu_7_reg_addr                                   "0xB800E244"
#define  LGCY_CODEBLKREG_ve_jpg_emu_7_reg                                        0xB800E244
#define  LGCY_CODEBLKREG_ve_jpg_emu_7_inst_addr                                  "0x0026"
#define  set_LGCY_CODEBLKREG_ve_jpg_emu_7_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_7_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_jpg_emu_7_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_jpg_emu_7_reg))
#define  LGCY_CODEBLKREG_ve_jpg_emu_7_removal_counter_shift                      (0)
#define  LGCY_CODEBLKREG_ve_jpg_emu_7_removal_counter_mask                       (0x1FFFFFFF)
#define  LGCY_CODEBLKREG_ve_jpg_emu_7_removal_counter(data)                      (0x1FFFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_jpg_emu_7_get_removal_counter(data)                  (0x1FFFFFFF&(data))

#define  LGCY_CODEBLKREG_ve_decbsptr_msb                                         0x1800E248
#define  LGCY_CODEBLKREG_ve_decbsptr_msb_reg_addr                                "0xB800E248"
#define  LGCY_CODEBLKREG_ve_decbsptr_msb_reg                                     0xB800E248
#define  LGCY_CODEBLKREG_ve_decbsptr_msb_inst_addr                               "0x0027"
#define  set_LGCY_CODEBLKREG_ve_decbsptr_msb_reg(data)                           (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_decbsptr_msb_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_decbsptr_msb_reg                                 (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_decbsptr_msb_reg))
#define  LGCY_CODEBLKREG_ve_decbsptr_msb_dec_bit_ptr_msb_shift                   (0)
#define  LGCY_CODEBLKREG_ve_decbsptr_msb_dec_bit_ptr_msb_mask                    (0x00000007)
#define  LGCY_CODEBLKREG_ve_decbsptr_msb_dec_bit_ptr_msb(data)                   (0x00000007&(data))
#define  LGCY_CODEBLKREG_ve_decbsptr_msb_get_dec_bit_ptr_msb(data)               (0x00000007&(data))

#define  LGCY_CODEBLKREG_ve_transform                                            0x1800E300
#define  LGCY_CODEBLKREG_ve_transform_reg_addr                                   "0xB800E300"
#define  LGCY_CODEBLKREG_ve_transform_reg                                        0xB800E300
#define  LGCY_CODEBLKREG_ve_transform_inst_addr                                  "0x0028"
#define  set_LGCY_CODEBLKREG_ve_transform_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_transform_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_transform_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_transform_reg))
#define  LGCY_CODEBLKREG_ve_transform_write_enable6_shift                        (31)
#define  LGCY_CODEBLKREG_ve_transform_sad_en_shift                               (30)
#define  LGCY_CODEBLKREG_ve_transform_write_enable5_shift                        (29)
#define  LGCY_CODEBLKREG_ve_transform_sad_threshold_shift                        (19)
#define  LGCY_CODEBLKREG_ve_transform_write_enable4_shift                        (18)
#define  LGCY_CODEBLKREG_ve_transform_flat_qtable_shift                          (17)
#define  LGCY_CODEBLKREG_ve_transform_write_enable3_shift                        (16)
#define  LGCY_CODEBLKREG_ve_transform_transform_size_8x8_shift                   (15)
#define  LGCY_CODEBLKREG_ve_transform_write_enable2_shift                        (14)
#define  LGCY_CODEBLKREG_ve_transform_field_transform_shift                      (13)
#define  LGCY_CODEBLKREG_ve_transform_write_enable1_shift                        (12)
#define  LGCY_CODEBLKREG_ve_transform_mb_ttfrm_shift                             (0)
#define  LGCY_CODEBLKREG_ve_transform_write_enable6_mask                         (0x80000000)
#define  LGCY_CODEBLKREG_ve_transform_sad_en_mask                                (0x40000000)
#define  LGCY_CODEBLKREG_ve_transform_write_enable5_mask                         (0x20000000)
#define  LGCY_CODEBLKREG_ve_transform_sad_threshold_mask                         (0x1FF80000)
#define  LGCY_CODEBLKREG_ve_transform_write_enable4_mask                         (0x00040000)
#define  LGCY_CODEBLKREG_ve_transform_flat_qtable_mask                           (0x00020000)
#define  LGCY_CODEBLKREG_ve_transform_write_enable3_mask                         (0x00010000)
#define  LGCY_CODEBLKREG_ve_transform_transform_size_8x8_mask                    (0x00008000)
#define  LGCY_CODEBLKREG_ve_transform_write_enable2_mask                         (0x00004000)
#define  LGCY_CODEBLKREG_ve_transform_field_transform_mask                       (0x00002000)
#define  LGCY_CODEBLKREG_ve_transform_write_enable1_mask                         (0x00001000)
#define  LGCY_CODEBLKREG_ve_transform_mb_ttfrm_mask                              (0x00000FFF)
#define  LGCY_CODEBLKREG_ve_transform_write_enable6(data)                        (0x80000000&((data)<<31))
#define  LGCY_CODEBLKREG_ve_transform_sad_en(data)                               (0x40000000&((data)<<30))
#define  LGCY_CODEBLKREG_ve_transform_write_enable5(data)                        (0x20000000&((data)<<29))
#define  LGCY_CODEBLKREG_ve_transform_sad_threshold(data)                        (0x1FF80000&((data)<<19))
#define  LGCY_CODEBLKREG_ve_transform_write_enable4(data)                        (0x00040000&((data)<<18))
#define  LGCY_CODEBLKREG_ve_transform_flat_qtable(data)                          (0x00020000&((data)<<17))
#define  LGCY_CODEBLKREG_ve_transform_write_enable3(data)                        (0x00010000&((data)<<16))
#define  LGCY_CODEBLKREG_ve_transform_transform_size_8x8(data)                   (0x00008000&((data)<<15))
#define  LGCY_CODEBLKREG_ve_transform_write_enable2(data)                        (0x00004000&((data)<<14))
#define  LGCY_CODEBLKREG_ve_transform_field_transform(data)                      (0x00002000&((data)<<13))
#define  LGCY_CODEBLKREG_ve_transform_write_enable1(data)                        (0x00001000&((data)<<12))
#define  LGCY_CODEBLKREG_ve_transform_mb_ttfrm(data)                             (0x00000FFF&(data))
#define  LGCY_CODEBLKREG_ve_transform_get_write_enable6(data)                    ((0x80000000&(data))>>31)
#define  LGCY_CODEBLKREG_ve_transform_get_sad_en(data)                           ((0x40000000&(data))>>30)
#define  LGCY_CODEBLKREG_ve_transform_get_write_enable5(data)                    ((0x20000000&(data))>>29)
#define  LGCY_CODEBLKREG_ve_transform_get_sad_threshold(data)                    ((0x1FF80000&(data))>>19)
#define  LGCY_CODEBLKREG_ve_transform_get_write_enable4(data)                    ((0x00040000&(data))>>18)
#define  LGCY_CODEBLKREG_ve_transform_get_flat_qtable(data)                      ((0x00020000&(data))>>17)
#define  LGCY_CODEBLKREG_ve_transform_get_write_enable3(data)                    ((0x00010000&(data))>>16)
#define  LGCY_CODEBLKREG_ve_transform_get_transform_size_8x8(data)               ((0x00008000&(data))>>15)
#define  LGCY_CODEBLKREG_ve_transform_get_write_enable2(data)                    ((0x00004000&(data))>>14)
#define  LGCY_CODEBLKREG_ve_transform_get_field_transform(data)                  ((0x00002000&(data))>>13)
#define  LGCY_CODEBLKREG_ve_transform_get_write_enable1(data)                    ((0x00001000&(data))>>12)
#define  LGCY_CODEBLKREG_ve_transform_get_mb_ttfrm(data)                         (0x00000FFF&(data))

#define  LGCY_CODEBLKREG_ve_quantizer                                            0x1800E304
#define  LGCY_CODEBLKREG_ve_quantizer_reg_addr                                   "0xB800E304"
#define  LGCY_CODEBLKREG_ve_quantizer_reg                                        0xB800E304
#define  LGCY_CODEBLKREG_ve_quantizer_inst_addr                                  "0x0029"
#define  set_LGCY_CODEBLKREG_ve_quantizer_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_quantizer_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_quantizer_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_quantizer_reg))
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable6_shift                        (31)
#define  LGCY_CODEBLKREG_ve_quantizer_id_pred_shift                              (29)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable5_shift                        (28)
#define  LGCY_CODEBLKREG_ve_quantizer_quant_type_shift                           (27)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable4_shift                        (26)
#define  LGCY_CODEBLKREG_ve_quantizer_mquant_shift                               (21)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable3_shift                        (20)
#define  LGCY_CODEBLKREG_ve_quantizer_qpy_shift                                  (14)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable2_shift                        (13)
#define  LGCY_CODEBLKREG_ve_quantizer_qpcb_shift                                 (7)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable1_shift                        (6)
#define  LGCY_CODEBLKREG_ve_quantizer_qpcr_shift                                 (0)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable6_mask                         (0x80000000)
#define  LGCY_CODEBLKREG_ve_quantizer_id_pred_mask                               (0x60000000)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable5_mask                         (0x10000000)
#define  LGCY_CODEBLKREG_ve_quantizer_quant_type_mask                            (0x08000000)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable4_mask                         (0x04000000)
#define  LGCY_CODEBLKREG_ve_quantizer_mquant_mask                                (0x03E00000)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable3_mask                         (0x00100000)
#define  LGCY_CODEBLKREG_ve_quantizer_qpy_mask                                   (0x000FC000)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable2_mask                         (0x00002000)
#define  LGCY_CODEBLKREG_ve_quantizer_qpcb_mask                                  (0x00001F80)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable1_mask                         (0x00000040)
#define  LGCY_CODEBLKREG_ve_quantizer_qpcr_mask                                  (0x0000003F)
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable6(data)                        (0x80000000&((data)<<31))
#define  LGCY_CODEBLKREG_ve_quantizer_id_pred(data)                              (0x60000000&((data)<<29))
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable5(data)                        (0x10000000&((data)<<28))
#define  LGCY_CODEBLKREG_ve_quantizer_quant_type(data)                           (0x08000000&((data)<<27))
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable4(data)                        (0x04000000&((data)<<26))
#define  LGCY_CODEBLKREG_ve_quantizer_mquant(data)                               (0x03E00000&((data)<<21))
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable3(data)                        (0x00100000&((data)<<20))
#define  LGCY_CODEBLKREG_ve_quantizer_qpy(data)                                  (0x000FC000&((data)<<14))
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable2(data)                        (0x00002000&((data)<<13))
#define  LGCY_CODEBLKREG_ve_quantizer_qpcb(data)                                 (0x00001F80&((data)<<7))
#define  LGCY_CODEBLKREG_ve_quantizer_write_enable1(data)                        (0x00000040&((data)<<6))
#define  LGCY_CODEBLKREG_ve_quantizer_qpcr(data)                                 (0x0000003F&(data))
#define  LGCY_CODEBLKREG_ve_quantizer_get_write_enable6(data)                    ((0x80000000&(data))>>31)
#define  LGCY_CODEBLKREG_ve_quantizer_get_id_pred(data)                          ((0x60000000&(data))>>29)
#define  LGCY_CODEBLKREG_ve_quantizer_get_write_enable5(data)                    ((0x10000000&(data))>>28)
#define  LGCY_CODEBLKREG_ve_quantizer_get_quant_type(data)                       ((0x08000000&(data))>>27)
#define  LGCY_CODEBLKREG_ve_quantizer_get_write_enable4(data)                    ((0x04000000&(data))>>26)
#define  LGCY_CODEBLKREG_ve_quantizer_get_mquant(data)                           ((0x03E00000&(data))>>21)
#define  LGCY_CODEBLKREG_ve_quantizer_get_write_enable3(data)                    ((0x00100000&(data))>>20)
#define  LGCY_CODEBLKREG_ve_quantizer_get_qpy(data)                              ((0x000FC000&(data))>>14)
#define  LGCY_CODEBLKREG_ve_quantizer_get_write_enable2(data)                    ((0x00002000&(data))>>13)
#define  LGCY_CODEBLKREG_ve_quantizer_get_qpcb(data)                             ((0x00001F80&(data))>>7)
#define  LGCY_CODEBLKREG_ve_quantizer_get_write_enable1(data)                    ((0x00000040&(data))>>6)
#define  LGCY_CODEBLKREG_ve_quantizer_get_qpcr(data)                             (0x0000003F&(data))

#define  LGCY_CODEBLKREG_ve_quantizer2                                           0x1800E3EC
#define  LGCY_CODEBLKREG_ve_quantizer2_reg_addr                                  "0xB800E3EC"
#define  LGCY_CODEBLKREG_ve_quantizer2_reg                                       0xB800E3EC
#define  LGCY_CODEBLKREG_ve_quantizer2_inst_addr                                 "0x002A"
#define  set_LGCY_CODEBLKREG_ve_quantizer2_reg(data)                             (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_quantizer2_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_quantizer2_reg                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_quantizer2_reg))
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable5_shift                       (31)
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_y2ac_shift                         (26)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable4_shift                       (25)
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_uvdc_shift                         (20)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable3_shift                       (19)
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_y2dc_shift                         (14)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable2_shift                       (13)
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_y1dc_shift                         (8)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable1_shift                       (7)
#define  LGCY_CODEBLKREG_ve_quantizer2_vp8_qp_shift                              (0)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable5_mask                        (0x80000000)
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_y2ac_mask                          (0x7C000000)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable4_mask                        (0x02000000)
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_uvdc_mask                          (0x01F00000)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable3_mask                        (0x00080000)
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_y2dc_mask                          (0x0007C000)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable2_mask                        (0x00002000)
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_y1dc_mask                          (0x00001F00)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable1_mask                        (0x00000080)
#define  LGCY_CODEBLKREG_ve_quantizer2_vp8_qp_mask                               (0x0000007F)
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable5(data)                       (0x80000000&((data)<<31))
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_y2ac(data)                         (0x7C000000&((data)<<26))
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable4(data)                       (0x02000000&((data)<<25))
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_uvdc(data)                         (0x01F00000&((data)<<20))
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable3(data)                       (0x00080000&((data)<<19))
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_y2dc(data)                         (0x0007C000&((data)<<14))
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable2(data)                       (0x00002000&((data)<<13))
#define  LGCY_CODEBLKREG_ve_quantizer2_qdelta_y1dc(data)                         (0x00001F00&((data)<<8))
#define  LGCY_CODEBLKREG_ve_quantizer2_write_enable1(data)                       (0x00000080&((data)<<7))
#define  LGCY_CODEBLKREG_ve_quantizer2_vp8_qp(data)                              (0x0000007F&(data))
#define  LGCY_CODEBLKREG_ve_quantizer2_get_write_enable5(data)                   ((0x80000000&(data))>>31)
#define  LGCY_CODEBLKREG_ve_quantizer2_get_qdelta_y2ac(data)                     ((0x7C000000&(data))>>26)
#define  LGCY_CODEBLKREG_ve_quantizer2_get_write_enable4(data)                   ((0x02000000&(data))>>25)
#define  LGCY_CODEBLKREG_ve_quantizer2_get_qdelta_uvdc(data)                     ((0x01F00000&(data))>>20)
#define  LGCY_CODEBLKREG_ve_quantizer2_get_write_enable3(data)                   ((0x00080000&(data))>>19)
#define  LGCY_CODEBLKREG_ve_quantizer2_get_qdelta_y2dc(data)                     ((0x0007C000&(data))>>14)
#define  LGCY_CODEBLKREG_ve_quantizer2_get_write_enable2(data)                   ((0x00002000&(data))>>13)
#define  LGCY_CODEBLKREG_ve_quantizer2_get_qdelta_y1dc(data)                     ((0x00001F00&(data))>>8)
#define  LGCY_CODEBLKREG_ve_quantizer2_get_write_enable1(data)                   ((0x00000080&(data))>>7)
#define  LGCY_CODEBLKREG_ve_quantizer2_get_vp8_qp(data)                          (0x0000007F&(data))

#define  LGCY_CODEBLKREG_ve_itdma                                                0x1800E3BC
#define  LGCY_CODEBLKREG_ve_itdma_reg_addr                                       "0xB800E3BC"
#define  LGCY_CODEBLKREG_ve_itdma_reg                                            0xB800E3BC
#define  LGCY_CODEBLKREG_ve_itdma_inst_addr                                      "0x002B"
#define  set_LGCY_CODEBLKREG_ve_itdma_reg(data)                                  (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_itdma_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_itdma_reg                                        (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_itdma_reg))
#define  LGCY_CODEBLKREG_ve_itdma_blk_pic_idx_shift                              (0)
#define  LGCY_CODEBLKREG_ve_itdma_blk_pic_idx_mask                               (0x0000007F)
#define  LGCY_CODEBLKREG_ve_itdma_blk_pic_idx(data)                              (0x0000007F&(data))
#define  LGCY_CODEBLKREG_ve_itdma_get_blk_pic_idx(data)                          (0x0000007F&(data))

#define  LGCY_CODEBLKREG_ve_cbp                                                  0x1800E308
#define  LGCY_CODEBLKREG_ve_cbp_reg_addr                                         "0xB800E308"
#define  LGCY_CODEBLKREG_ve_cbp_reg                                              0xB800E308
#define  LGCY_CODEBLKREG_ve_cbp_inst_addr                                        "0x002C"
#define  set_LGCY_CODEBLKREG_ve_cbp_reg(data)                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_cbp_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_cbp_reg                                          (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_cbp_reg))
#define  LGCY_CODEBLKREG_ve_cbp_write_enable2_shift                              (31)
#define  LGCY_CODEBLKREG_ve_cbp_cbp6bits_shift                                   (25)
#define  LGCY_CODEBLKREG_ve_cbp_write_enable1_shift                              (24)
#define  LGCY_CODEBLKREG_ve_cbp_subblkpat_shift                                  (0)
#define  LGCY_CODEBLKREG_ve_cbp_write_enable2_mask                               (0x80000000)
#define  LGCY_CODEBLKREG_ve_cbp_cbp6bits_mask                                    (0x7E000000)
#define  LGCY_CODEBLKREG_ve_cbp_write_enable1_mask                               (0x01000000)
#define  LGCY_CODEBLKREG_ve_cbp_subblkpat_mask                                   (0x00FFFFFF)
#define  LGCY_CODEBLKREG_ve_cbp_write_enable2(data)                              (0x80000000&((data)<<31))
#define  LGCY_CODEBLKREG_ve_cbp_cbp6bits(data)                                   (0x7E000000&((data)<<25))
#define  LGCY_CODEBLKREG_ve_cbp_write_enable1(data)                              (0x01000000&((data)<<24))
#define  LGCY_CODEBLKREG_ve_cbp_subblkpat(data)                                  (0x00FFFFFF&(data))
#define  LGCY_CODEBLKREG_ve_cbp_get_write_enable2(data)                          ((0x80000000&(data))>>31)
#define  LGCY_CODEBLKREG_ve_cbp_get_cbp6bits(data)                               ((0x7E000000&(data))>>25)
#define  LGCY_CODEBLKREG_ve_cbp_get_write_enable1(data)                          ((0x01000000&(data))>>24)
#define  LGCY_CODEBLKREG_ve_cbp_get_subblkpat(data)                              (0x00FFFFFF&(data))

#define  LGCY_CODEBLKREG_mb_partition                                            0x1800E30C
#define  LGCY_CODEBLKREG_mb_partition_reg_addr                                   "0xB800E30C"
#define  LGCY_CODEBLKREG_mb_partition_reg                                        0xB800E30C
#define  LGCY_CODEBLKREG_mb_partition_inst_addr                                  "0x002D"
#define  set_LGCY_CODEBLKREG_mb_partition_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_mb_partition_reg)=data)
#define  get_LGCY_CODEBLKREG_mb_partition_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_mb_partition_reg))
#define  LGCY_CODEBLKREG_mb_partition_mbpartition_shift                          (0)
#define  LGCY_CODEBLKREG_mb_partition_mbpartition_mask                           (0x000001FF)
#define  LGCY_CODEBLKREG_mb_partition_mbpartition(data)                          (0x000001FF&(data))
#define  LGCY_CODEBLKREG_mb_partition_get_mbpartition(data)                      (0x000001FF&(data))

#define  LGCY_CODEBLKREG_mb_predmode                                             0x1800E310
#define  LGCY_CODEBLKREG_mb_predmode_reg_addr                                    "0xB800E310"
#define  LGCY_CODEBLKREG_mb_predmode_reg                                         0xB800E310
#define  LGCY_CODEBLKREG_mb_predmode_inst_addr                                   "0x002E"
#define  set_LGCY_CODEBLKREG_mb_predmode_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_mb_predmode_reg)=data)
#define  get_LGCY_CODEBLKREG_mb_predmode_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_mb_predmode_reg))
#define  LGCY_CODEBLKREG_mb_predmode_mb_pred_mode_shift                          (0)
#define  LGCY_CODEBLKREG_mb_predmode_mb_pred_mode_mask                           (0x000000FF)
#define  LGCY_CODEBLKREG_mb_predmode_mb_pred_mode(data)                          (0x000000FF&(data))
#define  LGCY_CODEBLKREG_mb_predmode_get_mb_pred_mode(data)                      (0x000000FF&(data))

#define  LGCY_CODEBLKREG_mb_Info                                                 0x1800E314
#define  LGCY_CODEBLKREG_mb_Info_reg_addr                                        "0xB800E314"
#define  LGCY_CODEBLKREG_mb_Info_reg                                             0xB800E314
#define  LGCY_CODEBLKREG_mb_Info_inst_addr                                       "0x002F"
#define  set_LGCY_CODEBLKREG_mb_Info_reg(data)                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_mb_Info_reg)=data)
#define  get_LGCY_CODEBLKREG_mb_Info_reg                                         (*((volatile unsigned int*)LGCY_CODEBLKREG_mb_Info_reg))
#define  LGCY_CODEBLKREG_mb_Info_write_enable9_shift                             (31)
#define  LGCY_CODEBLKREG_mb_Info_vp9_lossless_shift                              (30)
#define  LGCY_CODEBLKREG_mb_Info_write_enable8_shift                             (29)
#define  LGCY_CODEBLKREG_mb_Info_vp6_ref_frame_shift                             (27)
#define  LGCY_CODEBLKREG_mb_Info_write_enable7_shift                             (26)
#define  LGCY_CODEBLKREG_mb_Info_mb_pattern_shift                                (25)
#define  LGCY_CODEBLKREG_mb_Info_write_enable6_shift                             (24)
#define  LGCY_CODEBLKREG_mb_Info_intrablks_flg_shift                             (19)
#define  LGCY_CODEBLKREG_mb_Info_write_enable5_shift                             (18)
#define  LGCY_CODEBLKREG_mb_Info_ac_pred_shift                                   (17)
#define  LGCY_CODEBLKREG_mb_Info_write_enable4_shift                             (16)
#define  LGCY_CODEBLKREG_mb_Info_dc_pred_dir_shift                               (10)
#define  LGCY_CODEBLKREG_mb_Info_write_enable3_shift                             (9)
#define  LGCY_CODEBLKREG_mb_Info_mbtype_shift                                    (5)
#define  LGCY_CODEBLKREG_mb_Info_write_enable2_shift                             (4)
#define  LGCY_CODEBLKREG_mb_Info_intra_c_pred_mode_shift                         (2)
#define  LGCY_CODEBLKREG_mb_Info_write_enable1_shift                             (1)
#define  LGCY_CODEBLKREG_mb_Info_field_mb_shift                                  (0)
#define  LGCY_CODEBLKREG_mb_Info_write_enable9_mask                              (0x80000000)
#define  LGCY_CODEBLKREG_mb_Info_vp9_lossless_mask                               (0x40000000)
#define  LGCY_CODEBLKREG_mb_Info_write_enable8_mask                              (0x20000000)
#define  LGCY_CODEBLKREG_mb_Info_vp6_ref_frame_mask                              (0x18000000)
#define  LGCY_CODEBLKREG_mb_Info_write_enable7_mask                              (0x04000000)
#define  LGCY_CODEBLKREG_mb_Info_mb_pattern_mask                                 (0x02000000)
#define  LGCY_CODEBLKREG_mb_Info_write_enable6_mask                              (0x01000000)
#define  LGCY_CODEBLKREG_mb_Info_intrablks_flg_mask                              (0x00F80000)
#define  LGCY_CODEBLKREG_mb_Info_write_enable5_mask                              (0x00040000)
#define  LGCY_CODEBLKREG_mb_Info_ac_pred_mask                                    (0x00020000)
#define  LGCY_CODEBLKREG_mb_Info_write_enable4_mask                              (0x00010000)
#define  LGCY_CODEBLKREG_mb_Info_dc_pred_dir_mask                                (0x0000FC00)
#define  LGCY_CODEBLKREG_mb_Info_write_enable3_mask                              (0x00000200)
#define  LGCY_CODEBLKREG_mb_Info_mbtype_mask                                     (0x000001E0)
#define  LGCY_CODEBLKREG_mb_Info_write_enable2_mask                              (0x00000010)
#define  LGCY_CODEBLKREG_mb_Info_intra_c_pred_mode_mask                          (0x0000000C)
#define  LGCY_CODEBLKREG_mb_Info_write_enable1_mask                              (0x00000002)
#define  LGCY_CODEBLKREG_mb_Info_field_mb_mask                                   (0x00000001)
#define  LGCY_CODEBLKREG_mb_Info_write_enable9(data)                             (0x80000000&((data)<<31))
#define  LGCY_CODEBLKREG_mb_Info_vp9_lossless(data)                              (0x40000000&((data)<<30))
#define  LGCY_CODEBLKREG_mb_Info_write_enable8(data)                             (0x20000000&((data)<<29))
#define  LGCY_CODEBLKREG_mb_Info_vp6_ref_frame(data)                             (0x18000000&((data)<<27))
#define  LGCY_CODEBLKREG_mb_Info_write_enable7(data)                             (0x04000000&((data)<<26))
#define  LGCY_CODEBLKREG_mb_Info_mb_pattern(data)                                (0x02000000&((data)<<25))
#define  LGCY_CODEBLKREG_mb_Info_write_enable6(data)                             (0x01000000&((data)<<24))
#define  LGCY_CODEBLKREG_mb_Info_intrablks_flg(data)                             (0x00F80000&((data)<<19))
#define  LGCY_CODEBLKREG_mb_Info_write_enable5(data)                             (0x00040000&((data)<<18))
#define  LGCY_CODEBLKREG_mb_Info_ac_pred(data)                                   (0x00020000&((data)<<17))
#define  LGCY_CODEBLKREG_mb_Info_write_enable4(data)                             (0x00010000&((data)<<16))
#define  LGCY_CODEBLKREG_mb_Info_dc_pred_dir(data)                               (0x0000FC00&((data)<<10))
#define  LGCY_CODEBLKREG_mb_Info_write_enable3(data)                             (0x00000200&((data)<<9))
#define  LGCY_CODEBLKREG_mb_Info_mbtype(data)                                    (0x000001E0&((data)<<5))
#define  LGCY_CODEBLKREG_mb_Info_write_enable2(data)                             (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_mb_Info_intra_c_pred_mode(data)                         (0x0000000C&((data)<<2))
#define  LGCY_CODEBLKREG_mb_Info_write_enable1(data)                             (0x00000002&((data)<<1))
#define  LGCY_CODEBLKREG_mb_Info_field_mb(data)                                  (0x00000001&(data))
#define  LGCY_CODEBLKREG_mb_Info_get_write_enable9(data)                         ((0x80000000&(data))>>31)
#define  LGCY_CODEBLKREG_mb_Info_get_vp9_lossless(data)                          ((0x40000000&(data))>>30)
#define  LGCY_CODEBLKREG_mb_Info_get_write_enable8(data)                         ((0x20000000&(data))>>29)
#define  LGCY_CODEBLKREG_mb_Info_get_vp6_ref_frame(data)                         ((0x18000000&(data))>>27)
#define  LGCY_CODEBLKREG_mb_Info_get_write_enable7(data)                         ((0x04000000&(data))>>26)
#define  LGCY_CODEBLKREG_mb_Info_get_mb_pattern(data)                            ((0x02000000&(data))>>25)
#define  LGCY_CODEBLKREG_mb_Info_get_write_enable6(data)                         ((0x01000000&(data))>>24)
#define  LGCY_CODEBLKREG_mb_Info_get_intrablks_flg(data)                         ((0x00F80000&(data))>>19)
#define  LGCY_CODEBLKREG_mb_Info_get_write_enable5(data)                         ((0x00040000&(data))>>18)
#define  LGCY_CODEBLKREG_mb_Info_get_ac_pred(data)                               ((0x00020000&(data))>>17)
#define  LGCY_CODEBLKREG_mb_Info_get_write_enable4(data)                         ((0x00010000&(data))>>16)
#define  LGCY_CODEBLKREG_mb_Info_get_dc_pred_dir(data)                           ((0x0000FC00&(data))>>10)
#define  LGCY_CODEBLKREG_mb_Info_get_write_enable3(data)                         ((0x00000200&(data))>>9)
#define  LGCY_CODEBLKREG_mb_Info_get_mbtype(data)                                ((0x000001E0&(data))>>5)
#define  LGCY_CODEBLKREG_mb_Info_get_write_enable2(data)                         ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_mb_Info_get_intra_c_pred_mode(data)                     ((0x0000000C&(data))>>2)
#define  LGCY_CODEBLKREG_mb_Info_get_write_enable1(data)                         ((0x00000002&(data))>>1)
#define  LGCY_CODEBLKREG_mb_Info_get_field_mb(data)                              (0x00000001&(data))

#define  LGCY_CODEBLKREG_mb_Info2                                                0x1800E318
#define  LGCY_CODEBLKREG_mb_Info2_reg_addr                                       "0xB800E318"
#define  LGCY_CODEBLKREG_mb_Info2_reg                                            0xB800E318
#define  LGCY_CODEBLKREG_mb_Info2_inst_addr                                      "0x0030"
#define  set_LGCY_CODEBLKREG_mb_Info2_reg(data)                                  (*((volatile unsigned int*)LGCY_CODEBLKREG_mb_Info2_reg)=data)
#define  get_LGCY_CODEBLKREG_mb_Info2_reg                                        (*((volatile unsigned int*)LGCY_CODEBLKREG_mb_Info2_reg))
#define  LGCY_CODEBLKREG_mb_Info2_h263_flv_lg1_shift                             (5)
#define  LGCY_CODEBLKREG_mb_Info2_ivf_shift                                      (4)
#define  LGCY_CODEBLKREG_mb_Info2_as_shift                                       (3)
#define  LGCY_CODEBLKREG_mb_Info2_intra_dc_vlc_shift                             (2)
#define  LGCY_CODEBLKREG_mb_Info2_short_hdr_shift                                (1)
#define  LGCY_CODEBLKREG_mb_Info2_write_data_shift                               (0)
#define  LGCY_CODEBLKREG_mb_Info2_h263_flv_lg1_mask                              (0x00000020)
#define  LGCY_CODEBLKREG_mb_Info2_ivf_mask                                       (0x00000010)
#define  LGCY_CODEBLKREG_mb_Info2_as_mask                                        (0x00000008)
#define  LGCY_CODEBLKREG_mb_Info2_intra_dc_vlc_mask                              (0x00000004)
#define  LGCY_CODEBLKREG_mb_Info2_short_hdr_mask                                 (0x00000002)
#define  LGCY_CODEBLKREG_mb_Info2_write_data_mask                                (0x00000001)
#define  LGCY_CODEBLKREG_mb_Info2_h263_flv_lg1(data)                             (0x00000020&((data)<<5))
#define  LGCY_CODEBLKREG_mb_Info2_ivf(data)                                      (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_mb_Info2_as(data)                                       (0x00000008&((data)<<3))
#define  LGCY_CODEBLKREG_mb_Info2_intra_dc_vlc(data)                             (0x00000004&((data)<<2))
#define  LGCY_CODEBLKREG_mb_Info2_short_hdr(data)                                (0x00000002&((data)<<1))
#define  LGCY_CODEBLKREG_mb_Info2_write_data(data)                               (0x00000001&(data))
#define  LGCY_CODEBLKREG_mb_Info2_get_h263_flv_lg1(data)                         ((0x00000020&(data))>>5)
#define  LGCY_CODEBLKREG_mb_Info2_get_ivf(data)                                  ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_mb_Info2_get_as(data)                                   ((0x00000008&(data))>>3)
#define  LGCY_CODEBLKREG_mb_Info2_get_intra_dc_vlc(data)                         ((0x00000004&(data))>>2)
#define  LGCY_CODEBLKREG_mb_Info2_get_short_hdr(data)                            ((0x00000002&(data))>>1)
#define  LGCY_CODEBLKREG_mb_Info2_get_write_data(data)                           (0x00000001&(data))

#define  LGCY_CODEBLKREG_rv_cntl                                                 0x1800E320
#define  LGCY_CODEBLKREG_rv_cntl_reg_addr                                        "0xB800E320"
#define  LGCY_CODEBLKREG_rv_cntl_reg                                             0xB800E320
#define  LGCY_CODEBLKREG_rv_cntl_inst_addr                                       "0x0031"
#define  set_LGCY_CODEBLKREG_rv_cntl_reg(data)                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_rv_cntl_reg)=data)
#define  get_LGCY_CODEBLKREG_rv_cntl_reg                                         (*((volatile unsigned int*)LGCY_CODEBLKREG_rv_cntl_reg))
#define  LGCY_CODEBLKREG_rv_cntl_write_enable2_shift                             (4)
#define  LGCY_CODEBLKREG_rv_cntl_rv9_intramode_use_top_shift                     (3)
#define  LGCY_CODEBLKREG_rv_cntl_write_enable1_shift                             (2)
#define  LGCY_CODEBLKREG_rv_cntl_rv_osvquant_shift                               (0)
#define  LGCY_CODEBLKREG_rv_cntl_write_enable2_mask                              (0x00000010)
#define  LGCY_CODEBLKREG_rv_cntl_rv9_intramode_use_top_mask                      (0x00000008)
#define  LGCY_CODEBLKREG_rv_cntl_write_enable1_mask                              (0x00000004)
#define  LGCY_CODEBLKREG_rv_cntl_rv_osvquant_mask                                (0x00000003)
#define  LGCY_CODEBLKREG_rv_cntl_write_enable2(data)                             (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_rv_cntl_rv9_intramode_use_top(data)                     (0x00000008&((data)<<3))
#define  LGCY_CODEBLKREG_rv_cntl_write_enable1(data)                             (0x00000004&((data)<<2))
#define  LGCY_CODEBLKREG_rv_cntl_rv_osvquant(data)                               (0x00000003&(data))
#define  LGCY_CODEBLKREG_rv_cntl_get_write_enable2(data)                         ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_rv_cntl_get_rv9_intramode_use_top(data)                 ((0x00000008&(data))>>3)
#define  LGCY_CODEBLKREG_rv_cntl_get_write_enable1(data)                         ((0x00000004&(data))>>2)
#define  LGCY_CODEBLKREG_rv_cntl_get_rv_osvquant(data)                           (0x00000003&(data))

#define  LGCY_CODEBLKREG_rv_struvlc                                              0x1800E324
#define  LGCY_CODEBLKREG_rv_struvlc_reg_addr                                     "0xB800E324"
#define  LGCY_CODEBLKREG_rv_struvlc_reg                                          0xB800E324
#define  LGCY_CODEBLKREG_rv_struvlc_inst_addr                                    "0x0032"
#define  set_LGCY_CODEBLKREG_rv_struvlc_reg(data)                                (*((volatile unsigned int*)LGCY_CODEBLKREG_rv_struvlc_reg)=data)
#define  get_LGCY_CODEBLKREG_rv_struvlc_reg                                      (*((volatile unsigned int*)LGCY_CODEBLKREG_rv_struvlc_reg))
#define  LGCY_CODEBLKREG_rv_struvlc_struvlc_len_shift                            (0)
#define  LGCY_CODEBLKREG_rv_struvlc_struvlc_len_mask                             (0x7FFFFFFF)
#define  LGCY_CODEBLKREG_rv_struvlc_struvlc_len(data)                            (0x7FFFFFFF&(data))
#define  LGCY_CODEBLKREG_rv_struvlc_get_struvlc_len(data)                        (0x7FFFFFFF&(data))

#define  LGCY_CODEBLKREG_rv_intramode                                            0x1800E328
#define  LGCY_CODEBLKREG_rv_intramode_reg_addr                                   "0xB800E328"
#define  LGCY_CODEBLKREG_rv_intramode_reg                                        0xB800E328
#define  LGCY_CODEBLKREG_rv_intramode_inst_addr                                  "0x0033"
#define  set_LGCY_CODEBLKREG_rv_intramode_reg(data)                              (*((volatile unsigned int*)LGCY_CODEBLKREG_rv_intramode_reg)=data)
#define  get_LGCY_CODEBLKREG_rv_intramode_reg                                    (*((volatile unsigned int*)LGCY_CODEBLKREG_rv_intramode_reg))
#define  LGCY_CODEBLKREG_rv_intramode_left_blocks_shift                          (0)
#define  LGCY_CODEBLKREG_rv_intramode_left_blocks_mask                           (0x0000FFFF)
#define  LGCY_CODEBLKREG_rv_intramode_left_blocks(data)                          (0x0000FFFF&(data))
#define  LGCY_CODEBLKREG_rv_intramode_get_left_blocks(data)                      (0x0000FFFF&(data))

#define  LGCY_CODEBLKREG_vldtblptr_0                                             0x1800E330
#define  LGCY_CODEBLKREG_vldtblptr_0_reg_addr                                    "0xB800E330"
#define  LGCY_CODEBLKREG_vldtblptr_0_reg                                         0xB800E330
#define  LGCY_CODEBLKREG_vldtblptr_0_inst_addr                                   "0x0034"
#define  set_LGCY_CODEBLKREG_vldtblptr_0_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_vldtblptr_0_reg)=data)
#define  get_LGCY_CODEBLKREG_vldtblptr_0_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_vldtblptr_0_reg))
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable4_shift                         (31)
#define  LGCY_CODEBLKREG_vldtblptr_0_jpg_dc_first_tbl_bits_shift                 (27)
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable3_shift                         (26)
#define  LGCY_CODEBLKREG_vldtblptr_0_jpg_dc_tbl_startaddr_shift                  (16)
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable2_shift                         (15)
#define  LGCY_CODEBLKREG_vldtblptr_0_first_tbl_bits_shift                        (11)
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable1_shift                         (10)
#define  LGCY_CODEBLKREG_vldtblptr_0_tbl_startaddr_shift                         (0)
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable4_mask                          (0x80000000)
#define  LGCY_CODEBLKREG_vldtblptr_0_jpg_dc_first_tbl_bits_mask                  (0x78000000)
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable3_mask                          (0x04000000)
#define  LGCY_CODEBLKREG_vldtblptr_0_jpg_dc_tbl_startaddr_mask                   (0x03FF0000)
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable2_mask                          (0x00008000)
#define  LGCY_CODEBLKREG_vldtblptr_0_first_tbl_bits_mask                         (0x00007800)
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable1_mask                          (0x00000400)
#define  LGCY_CODEBLKREG_vldtblptr_0_tbl_startaddr_mask                          (0x000003FF)
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable4(data)                         (0x80000000&((data)<<31))
#define  LGCY_CODEBLKREG_vldtblptr_0_jpg_dc_first_tbl_bits(data)                 (0x78000000&((data)<<27))
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable3(data)                         (0x04000000&((data)<<26))
#define  LGCY_CODEBLKREG_vldtblptr_0_jpg_dc_tbl_startaddr(data)                  (0x03FF0000&((data)<<16))
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable2(data)                         (0x00008000&((data)<<15))
#define  LGCY_CODEBLKREG_vldtblptr_0_first_tbl_bits(data)                        (0x00007800&((data)<<11))
#define  LGCY_CODEBLKREG_vldtblptr_0_write_enable1(data)                         (0x00000400&((data)<<10))
#define  LGCY_CODEBLKREG_vldtblptr_0_tbl_startaddr(data)                         (0x000003FF&(data))
#define  LGCY_CODEBLKREG_vldtblptr_0_get_write_enable4(data)                     ((0x80000000&(data))>>31)
#define  LGCY_CODEBLKREG_vldtblptr_0_get_jpg_dc_first_tbl_bits(data)             ((0x78000000&(data))>>27)
#define  LGCY_CODEBLKREG_vldtblptr_0_get_write_enable3(data)                     ((0x04000000&(data))>>26)
#define  LGCY_CODEBLKREG_vldtblptr_0_get_jpg_dc_tbl_startaddr(data)              ((0x03FF0000&(data))>>16)
#define  LGCY_CODEBLKREG_vldtblptr_0_get_write_enable2(data)                     ((0x00008000&(data))>>15)
#define  LGCY_CODEBLKREG_vldtblptr_0_get_first_tbl_bits(data)                    ((0x00007800&(data))>>11)
#define  LGCY_CODEBLKREG_vldtblptr_0_get_write_enable1(data)                     ((0x00000400&(data))>>10)
#define  LGCY_CODEBLKREG_vldtblptr_0_get_tbl_startaddr(data)                     (0x000003FF&(data))

#define  LGCY_CODEBLKREG_vldtblptr_1                                             0x1800E334
#define  LGCY_CODEBLKREG_vldtblptr_1_reg_addr                                    "0xB800E334"
#define  LGCY_CODEBLKREG_vldtblptr_1_reg                                         0xB800E334
#define  LGCY_CODEBLKREG_vldtblptr_1_inst_addr                                   "0x0035"
#define  set_LGCY_CODEBLKREG_vldtblptr_1_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_vldtblptr_1_reg)=data)
#define  get_LGCY_CODEBLKREG_vldtblptr_1_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_vldtblptr_1_reg))
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable4_shift                         (31)
#define  LGCY_CODEBLKREG_vldtblptr_1_jpg_dc_first_tbl_bits_shift                 (27)
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable3_shift                         (26)
#define  LGCY_CODEBLKREG_vldtblptr_1_jpg_dc_tbl_startaddr_shift                  (16)
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable2_shift                         (15)
#define  LGCY_CODEBLKREG_vldtblptr_1_first_tbl_bits_shift                        (11)
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable1_shift                         (10)
#define  LGCY_CODEBLKREG_vldtblptr_1_tbl_startaddr_shift                         (0)
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable4_mask                          (0x80000000)
#define  LGCY_CODEBLKREG_vldtblptr_1_jpg_dc_first_tbl_bits_mask                  (0x78000000)
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable3_mask                          (0x04000000)
#define  LGCY_CODEBLKREG_vldtblptr_1_jpg_dc_tbl_startaddr_mask                   (0x03FF0000)
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable2_mask                          (0x00008000)
#define  LGCY_CODEBLKREG_vldtblptr_1_first_tbl_bits_mask                         (0x00007800)
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable1_mask                          (0x00000400)
#define  LGCY_CODEBLKREG_vldtblptr_1_tbl_startaddr_mask                          (0x000003FF)
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable4(data)                         (0x80000000&((data)<<31))
#define  LGCY_CODEBLKREG_vldtblptr_1_jpg_dc_first_tbl_bits(data)                 (0x78000000&((data)<<27))
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable3(data)                         (0x04000000&((data)<<26))
#define  LGCY_CODEBLKREG_vldtblptr_1_jpg_dc_tbl_startaddr(data)                  (0x03FF0000&((data)<<16))
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable2(data)                         (0x00008000&((data)<<15))
#define  LGCY_CODEBLKREG_vldtblptr_1_first_tbl_bits(data)                        (0x00007800&((data)<<11))
#define  LGCY_CODEBLKREG_vldtblptr_1_write_enable1(data)                         (0x00000400&((data)<<10))
#define  LGCY_CODEBLKREG_vldtblptr_1_tbl_startaddr(data)                         (0x000003FF&(data))
#define  LGCY_CODEBLKREG_vldtblptr_1_get_write_enable4(data)                     ((0x80000000&(data))>>31)
#define  LGCY_CODEBLKREG_vldtblptr_1_get_jpg_dc_first_tbl_bits(data)             ((0x78000000&(data))>>27)
#define  LGCY_CODEBLKREG_vldtblptr_1_get_write_enable3(data)                     ((0x04000000&(data))>>26)
#define  LGCY_CODEBLKREG_vldtblptr_1_get_jpg_dc_tbl_startaddr(data)              ((0x03FF0000&(data))>>16)
#define  LGCY_CODEBLKREG_vldtblptr_1_get_write_enable2(data)                     ((0x00008000&(data))>>15)
#define  LGCY_CODEBLKREG_vldtblptr_1_get_first_tbl_bits(data)                    ((0x00007800&(data))>>11)
#define  LGCY_CODEBLKREG_vldtblptr_1_get_write_enable1(data)                     ((0x00000400&(data))>>10)
#define  LGCY_CODEBLKREG_vldtblptr_1_get_tbl_startaddr(data)                     (0x000003FF&(data))

#define  LGCY_CODEBLKREG_vldespptr_0                                             0x1800E340
#define  LGCY_CODEBLKREG_vldespptr_0_reg_addr                                    "0xB800E340"
#define  LGCY_CODEBLKREG_vldespptr_0_reg                                         0xB800E340
#define  LGCY_CODEBLKREG_vldespptr_0_inst_addr                                   "0x0036"
#define  set_LGCY_CODEBLKREG_vldespptr_0_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_vldespptr_0_reg)=data)
#define  get_LGCY_CODEBLKREG_vldespptr_0_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_vldespptr_0_reg))
#define  LGCY_CODEBLKREG_vldespptr_0_tbl_espptr_saddr_shift                      (0)
#define  LGCY_CODEBLKREG_vldespptr_0_tbl_espptr_saddr_mask                       (0x000003FF)
#define  LGCY_CODEBLKREG_vldespptr_0_tbl_espptr_saddr(data)                      (0x000003FF&(data))
#define  LGCY_CODEBLKREG_vldespptr_0_get_tbl_espptr_saddr(data)                  (0x000003FF&(data))

#define  LGCY_CODEBLKREG_vldespptr_1                                             0x1800E344
#define  LGCY_CODEBLKREG_vldespptr_1_reg_addr                                    "0xB800E344"
#define  LGCY_CODEBLKREG_vldespptr_1_reg                                         0xB800E344
#define  LGCY_CODEBLKREG_vldespptr_1_inst_addr                                   "0x0037"
#define  set_LGCY_CODEBLKREG_vldespptr_1_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_vldespptr_1_reg)=data)
#define  get_LGCY_CODEBLKREG_vldespptr_1_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_vldespptr_1_reg))
#define  LGCY_CODEBLKREG_vldespptr_1_tbl_espptr_saddr_shift                      (0)
#define  LGCY_CODEBLKREG_vldespptr_1_tbl_espptr_saddr_mask                       (0x000003FF)
#define  LGCY_CODEBLKREG_vldespptr_1_tbl_espptr_saddr(data)                      (0x000003FF&(data))
#define  LGCY_CODEBLKREG_vldespptr_1_get_tbl_espptr_saddr(data)                  (0x000003FF&(data))

#define  LGCY_CODEBLKREG_vldespptr_2                                             0x1800E348
#define  LGCY_CODEBLKREG_vldespptr_2_reg_addr                                    "0xB800E348"
#define  LGCY_CODEBLKREG_vldespptr_2_reg                                         0xB800E348
#define  LGCY_CODEBLKREG_vldespptr_2_inst_addr                                   "0x0038"
#define  set_LGCY_CODEBLKREG_vldespptr_2_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_vldespptr_2_reg)=data)
#define  get_LGCY_CODEBLKREG_vldespptr_2_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_vldespptr_2_reg))
#define  LGCY_CODEBLKREG_vldespptr_2_tbl_espptr_saddr_shift                      (0)
#define  LGCY_CODEBLKREG_vldespptr_2_tbl_espptr_saddr_mask                       (0x000003FF)
#define  LGCY_CODEBLKREG_vldespptr_2_tbl_espptr_saddr(data)                      (0x000003FF&(data))
#define  LGCY_CODEBLKREG_vldespptr_2_get_tbl_espptr_saddr(data)                  (0x000003FF&(data))

#define  LGCY_CODEBLKREG_vldespptr_3                                             0x1800E34C
#define  LGCY_CODEBLKREG_vldespptr_3_reg_addr                                    "0xB800E34C"
#define  LGCY_CODEBLKREG_vldespptr_3_reg                                         0xB800E34C
#define  LGCY_CODEBLKREG_vldespptr_3_inst_addr                                   "0x0039"
#define  set_LGCY_CODEBLKREG_vldespptr_3_reg(data)                               (*((volatile unsigned int*)LGCY_CODEBLKREG_vldespptr_3_reg)=data)
#define  get_LGCY_CODEBLKREG_vldespptr_3_reg                                     (*((volatile unsigned int*)LGCY_CODEBLKREG_vldespptr_3_reg))
#define  LGCY_CODEBLKREG_vldespptr_3_tbl_espptr_saddr_shift                      (0)
#define  LGCY_CODEBLKREG_vldespptr_3_tbl_espptr_saddr_mask                       (0x000003FF)
#define  LGCY_CODEBLKREG_vldespptr_3_tbl_espptr_saddr(data)                      (0x000003FF&(data))
#define  LGCY_CODEBLKREG_vldespptr_3_get_tbl_espptr_saddr(data)                  (0x000003FF&(data))

#define  LGCY_CODEBLKREG_ve_acdcp_luma                                           0x1800E350
#define  LGCY_CODEBLKREG_ve_acdcp_luma_reg_addr                                  "0xB800E350"
#define  LGCY_CODEBLKREG_ve_acdcp_luma_reg                                       0xB800E350
#define  LGCY_CODEBLKREG_ve_acdcp_luma_inst_addr                                 "0x003A"
#define  set_LGCY_CODEBLKREG_ve_acdcp_luma_reg(data)                             (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_acdcp_luma_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_acdcp_luma_reg                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_acdcp_luma_reg))
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_c_shift                            (20)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_c_intra_shift                      (19)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_d_shift                            (7)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_d_intra_shift                      (6)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_dcstep_topmb_shift                        (0)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_c_mask                             (0xFFF00000)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_c_intra_mask                       (0x00080000)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_d_mask                             (0x0007FF80)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_d_intra_mask                       (0x00000040)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_dcstep_topmb_mask                         (0x0000003F)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_c(data)                            (0xFFF00000&((data)<<20))
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_c_intra(data)                      (0x00080000&((data)<<19))
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_d(data)                            (0x0007FF80&((data)<<7))
#define  LGCY_CODEBLKREG_ve_acdcp_luma_lumadc_d_intra(data)                      (0x00000040&((data)<<6))
#define  LGCY_CODEBLKREG_ve_acdcp_luma_dcstep_topmb(data)                        (0x0000003F&(data))
#define  LGCY_CODEBLKREG_ve_acdcp_luma_get_lumadc_c(data)                        ((0xFFF00000&(data))>>20)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_get_lumadc_c_intra(data)                  ((0x00080000&(data))>>19)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_get_lumadc_d(data)                        ((0x0007FF80&(data))>>7)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_get_lumadc_d_intra(data)                  ((0x00000040&(data))>>6)
#define  LGCY_CODEBLKREG_ve_acdcp_luma_get_dcstep_topmb(data)                    (0x0000003F&(data))

#define  LGCY_CODEBLKREG_ve_acdcp_chro                                           0x1800E354
#define  LGCY_CODEBLKREG_ve_acdcp_chro_reg_addr                                  "0xB800E354"
#define  LGCY_CODEBLKREG_ve_acdcp_chro_reg                                       0xB800E354
#define  LGCY_CODEBLKREG_ve_acdcp_chro_inst_addr                                 "0x003B"
#define  set_LGCY_CODEBLKREG_ve_acdcp_chro_reg(data)                             (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_acdcp_chro_reg)=data)
#define  get_LGCY_CODEBLKREG_ve_acdcp_chro_reg                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_ve_acdcp_chro_reg))
#define  LGCY_CODEBLKREG_ve_acdcp_chro_cbdc_g_shift                              (18)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_crdc_g_shift                              (6)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_cbcr_intra_shift                          (5)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_ch_dcstep_topmb_shift                     (0)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_cbdc_g_mask                               (0x3FFC0000)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_crdc_g_mask                               (0x0003FFC0)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_cbcr_intra_mask                           (0x00000020)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_ch_dcstep_topmb_mask                      (0x0000001F)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_cbdc_g(data)                              (0x3FFC0000&((data)<<18))
#define  LGCY_CODEBLKREG_ve_acdcp_chro_crdc_g(data)                              (0x0003FFC0&((data)<<6))
#define  LGCY_CODEBLKREG_ve_acdcp_chro_cbcr_intra(data)                          (0x00000020&((data)<<5))
#define  LGCY_CODEBLKREG_ve_acdcp_chro_ch_dcstep_topmb(data)                     (0x0000001F&(data))
#define  LGCY_CODEBLKREG_ve_acdcp_chro_get_cbdc_g(data)                          ((0x3FFC0000&(data))>>18)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_get_crdc_g(data)                          ((0x0003FFC0&(data))>>6)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_get_cbcr_intra(data)                      ((0x00000020&(data))>>5)
#define  LGCY_CODEBLKREG_ve_acdcp_chro_get_ch_dcstep_topmb(data)                 (0x0000001F&(data))

#define  LGCY_CODEBLKREG_ndb_ctl                                                 0x1800E390
#define  LGCY_CODEBLKREG_ndb_ctl_reg_addr                                        "0xB800E390"
#define  LGCY_CODEBLKREG_ndb_ctl_reg                                             0xB800E390
#define  LGCY_CODEBLKREG_ndb_ctl_inst_addr                                       "0x003C"
#define  set_LGCY_CODEBLKREG_ndb_ctl_reg(data)                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_ctl_reg)=data)
#define  get_LGCY_CODEBLKREG_ndb_ctl_reg                                         (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_ctl_reg))
#define  LGCY_CODEBLKREG_ndb_ctl_write_enable3_shift                             (5)
#define  LGCY_CODEBLKREG_ndb_ctl_cavlc_halt_done_shift                           (4)
#define  LGCY_CODEBLKREG_ndb_ctl_write_enable2_shift                             (3)
#define  LGCY_CODEBLKREG_ndb_ctl_cavlc_halt_shift                                (2)
#define  LGCY_CODEBLKREG_ndb_ctl_write_enable1_shift                             (1)
#define  LGCY_CODEBLKREG_ndb_ctl_postwrite_en_shift                              (0)
#define  LGCY_CODEBLKREG_ndb_ctl_write_enable3_mask                              (0x00000020)
#define  LGCY_CODEBLKREG_ndb_ctl_cavlc_halt_done_mask                            (0x00000010)
#define  LGCY_CODEBLKREG_ndb_ctl_write_enable2_mask                              (0x00000008)
#define  LGCY_CODEBLKREG_ndb_ctl_cavlc_halt_mask                                 (0x00000004)
#define  LGCY_CODEBLKREG_ndb_ctl_write_enable1_mask                              (0x00000002)
#define  LGCY_CODEBLKREG_ndb_ctl_postwrite_en_mask                               (0x00000001)
#define  LGCY_CODEBLKREG_ndb_ctl_write_enable3(data)                             (0x00000020&((data)<<5))
#define  LGCY_CODEBLKREG_ndb_ctl_cavlc_halt_done(data)                           (0x00000010&((data)<<4))
#define  LGCY_CODEBLKREG_ndb_ctl_write_enable2(data)                             (0x00000008&((data)<<3))
#define  LGCY_CODEBLKREG_ndb_ctl_cavlc_halt(data)                                (0x00000004&((data)<<2))
#define  LGCY_CODEBLKREG_ndb_ctl_write_enable1(data)                             (0x00000002&((data)<<1))
#define  LGCY_CODEBLKREG_ndb_ctl_postwrite_en(data)                              (0x00000001&(data))
#define  LGCY_CODEBLKREG_ndb_ctl_get_write_enable3(data)                         ((0x00000020&(data))>>5)
#define  LGCY_CODEBLKREG_ndb_ctl_get_cavlc_halt_done(data)                       ((0x00000010&(data))>>4)
#define  LGCY_CODEBLKREG_ndb_ctl_get_write_enable2(data)                         ((0x00000008&(data))>>3)
#define  LGCY_CODEBLKREG_ndb_ctl_get_cavlc_halt(data)                            ((0x00000004&(data))>>2)
#define  LGCY_CODEBLKREG_ndb_ctl_get_write_enable1(data)                         ((0x00000002&(data))>>1)
#define  LGCY_CODEBLKREG_ndb_ctl_get_postwrite_en(data)                          (0x00000001&(data))

#define  LGCY_CODEBLKREG_ndb_cavlc_base                                          0x1800E3A8
#define  LGCY_CODEBLKREG_ndb_cavlc_base_reg_addr                                 "0xB800E3A8"
#define  LGCY_CODEBLKREG_ndb_cavlc_base_reg                                      0xB800E3A8
#define  LGCY_CODEBLKREG_ndb_cavlc_base_inst_addr                                "0x003D"
#define  set_LGCY_CODEBLKREG_ndb_cavlc_base_reg(data)                            (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_cavlc_base_reg)=data)
#define  get_LGCY_CODEBLKREG_ndb_cavlc_base_reg                                  (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_cavlc_base_reg))
#define  LGCY_CODEBLKREG_ndb_cavlc_base_base_addr_shift                          (0)
#define  LGCY_CODEBLKREG_ndb_cavlc_base_base_addr_mask                           (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ndb_cavlc_base_base_addr(data)                          (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ndb_cavlc_base_get_base_addr(data)                      (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ndb_cavlc_limit                                         0x1800E3AC
#define  LGCY_CODEBLKREG_ndb_cavlc_limit_reg_addr                                "0xB800E3AC"
#define  LGCY_CODEBLKREG_ndb_cavlc_limit_reg                                     0xB800E3AC
#define  LGCY_CODEBLKREG_ndb_cavlc_limit_inst_addr                               "0x003E"
#define  set_LGCY_CODEBLKREG_ndb_cavlc_limit_reg(data)                           (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_cavlc_limit_reg)=data)
#define  get_LGCY_CODEBLKREG_ndb_cavlc_limit_reg                                 (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_cavlc_limit_reg))
#define  LGCY_CODEBLKREG_ndb_cavlc_limit_limit_addr_shift                        (0)
#define  LGCY_CODEBLKREG_ndb_cavlc_limit_limit_addr_mask                         (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ndb_cavlc_limit_limit_addr(data)                        (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ndb_cavlc_limit_get_limit_addr(data)                    (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ndb_cavlc_wptr                                          0x1800E3B0
#define  LGCY_CODEBLKREG_ndb_cavlc_wptr_reg_addr                                 "0xB800E3B0"
#define  LGCY_CODEBLKREG_ndb_cavlc_wptr_reg                                      0xB800E3B0
#define  LGCY_CODEBLKREG_ndb_cavlc_wptr_inst_addr                                "0x003F"
#define  set_LGCY_CODEBLKREG_ndb_cavlc_wptr_reg(data)                            (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_cavlc_wptr_reg)=data)
#define  get_LGCY_CODEBLKREG_ndb_cavlc_wptr_reg                                  (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_cavlc_wptr_reg))
#define  LGCY_CODEBLKREG_ndb_cavlc_wptr_wr_ptr_shift                             (0)
#define  LGCY_CODEBLKREG_ndb_cavlc_wptr_wr_ptr_mask                              (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ndb_cavlc_wptr_wr_ptr(data)                             (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ndb_cavlc_wptr_get_wr_ptr(data)                         (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_ndb_cavlc_rptr                                          0x1800E3B4
#define  LGCY_CODEBLKREG_ndb_cavlc_rptr_reg_addr                                 "0xB800E3B4"
#define  LGCY_CODEBLKREG_ndb_cavlc_rptr_reg                                      0xB800E3B4
#define  LGCY_CODEBLKREG_ndb_cavlc_rptr_inst_addr                                "0x0040"
#define  set_LGCY_CODEBLKREG_ndb_cavlc_rptr_reg(data)                            (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_cavlc_rptr_reg)=data)
#define  get_LGCY_CODEBLKREG_ndb_cavlc_rptr_reg                                  (*((volatile unsigned int*)LGCY_CODEBLKREG_ndb_cavlc_rptr_reg))
#define  LGCY_CODEBLKREG_ndb_cavlc_rptr_rd_ptr_shift                             (0)
#define  LGCY_CODEBLKREG_ndb_cavlc_rptr_rd_ptr_mask                              (0xFFFFFFFF)
#define  LGCY_CODEBLKREG_ndb_cavlc_rptr_rd_ptr(data)                             (0xFFFFFFFF&(data))
#define  LGCY_CODEBLKREG_ndb_cavlc_rptr_get_rd_ptr(data)                         (0xFFFFFFFF&(data))

#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1                                          0x1800E3F0
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_reg_addr                                 "0xB800E3F0"
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_reg                                      0xB800E3F0
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_inst_addr                                "0x0041"
#define  set_LGCY_CODEBLKREG_vp8_p3_frm_mb1_reg(data)                            (*((volatile unsigned int*)LGCY_CODEBLKREG_vp8_p3_frm_mb1_reg)=data)
#define  get_LGCY_CODEBLKREG_vp8_p3_frm_mb1_reg                                  (*((volatile unsigned int*)LGCY_CODEBLKREG_vp8_p3_frm_mb1_reg))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable7_shift                      (25)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_segmentation_enabled_shift               (24)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable6_shift                      (23)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_slice_cnt_shift                          (15)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable5_shift                      (14)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_uv_mode_shift                            (12)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable4_shift                      (11)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_ref_frame_shift                          (9)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable3_shift                      (8)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_mode_shift                               (4)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable2_shift                      (3)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_need_to_clamp_mvs_shift                  (2)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable1_shift                      (1)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_mb_skip_coeff_shift                      (0)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable7_mask                       (0x02000000)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_segmentation_enabled_mask                (0x01000000)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable6_mask                       (0x00800000)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_slice_cnt_mask                           (0x007F8000)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable5_mask                       (0x00004000)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_uv_mode_mask                             (0x00003000)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable4_mask                       (0x00000800)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_ref_frame_mask                           (0x00000600)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable3_mask                       (0x00000100)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_mode_mask                                (0x000000F0)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable2_mask                       (0x00000008)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_need_to_clamp_mvs_mask                   (0x00000004)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable1_mask                       (0x00000002)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_mb_skip_coeff_mask                       (0x00000001)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable7(data)                      (0x02000000&((data)<<25))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_segmentation_enabled(data)               (0x01000000&((data)<<24))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable6(data)                      (0x00800000&((data)<<23))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_slice_cnt(data)                          (0x007F8000&((data)<<15))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable5(data)                      (0x00004000&((data)<<14))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_uv_mode(data)                            (0x00003000&((data)<<12))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable4(data)                      (0x00000800&((data)<<11))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_ref_frame(data)                          (0x00000600&((data)<<9))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable3(data)                      (0x00000100&((data)<<8))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_mode(data)                               (0x000000F0&((data)<<4))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable2(data)                      (0x00000008&((data)<<3))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_need_to_clamp_mvs(data)                  (0x00000004&((data)<<2))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_write_enable1(data)                      (0x00000002&((data)<<1))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_mb_skip_coeff(data)                      (0x00000001&(data))
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_write_enable7(data)                  ((0x02000000&(data))>>25)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_segmentation_enabled(data)           ((0x01000000&(data))>>24)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_write_enable6(data)                  ((0x00800000&(data))>>23)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_slice_cnt(data)                      ((0x007F8000&(data))>>15)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_write_enable5(data)                  ((0x00004000&(data))>>14)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_uv_mode(data)                        ((0x00003000&(data))>>12)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_write_enable4(data)                  ((0x00000800&(data))>>11)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_ref_frame(data)                      ((0x00000600&(data))>>9)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_write_enable3(data)                  ((0x00000100&(data))>>8)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_mode(data)                           ((0x000000F0&(data))>>4)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_write_enable2(data)                  ((0x00000008&(data))>>3)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_need_to_clamp_mvs(data)              ((0x00000004&(data))>>2)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_write_enable1(data)                  ((0x00000002&(data))>>1)
#define  LGCY_CODEBLKREG_vp8_p3_frm_mb1_get_mb_skip_coeff(data)                  (0x00000001&(data))

#define  LGCY_CODEBLKREG_vp8_p3_mb2                                              0x1800E3F4
#define  LGCY_CODEBLKREG_vp8_p3_mb2_reg_addr                                     "0xB800E3F4"
#define  LGCY_CODEBLKREG_vp8_p3_mb2_reg                                          0xB800E3F4
#define  LGCY_CODEBLKREG_vp8_p3_mb2_inst_addr                                    "0x0042"
#define  set_LGCY_CODEBLKREG_vp8_p3_mb2_reg(data)                                (*((volatile unsigned int*)LGCY_CODEBLKREG_vp8_p3_mb2_reg)=data)
#define  get_LGCY_CODEBLKREG_vp8_p3_mb2_reg                                      (*((volatile unsigned int*)LGCY_CODEBLKREG_vp8_p3_mb2_reg))
#define  LGCY_CODEBLKREG_vp8_p3_mb2_vp8_p3_curmb_shift                           (0)
#define  LGCY_CODEBLKREG_vp8_p3_mb2_vp8_p3_curmb_mask                            (0x000001FF)
#define  LGCY_CODEBLKREG_vp8_p3_mb2_vp8_p3_curmb(data)                           (0x000001FF&(data))
#define  LGCY_CODEBLKREG_vp8_p3_mb2_get_vp8_p3_curmb(data)                       (0x000001FF&(data))

#define  LGCY_CODEBLKREG_vp8_bac                                                 0x1800E3F8
#define  LGCY_CODEBLKREG_vp8_bac_reg_addr                                        "0xB800E3F8"
#define  LGCY_CODEBLKREG_vp8_bac_reg                                             0xB800E3F8
#define  LGCY_CODEBLKREG_vp8_bac_inst_addr                                       "0x0043"
#define  set_LGCY_CODEBLKREG_vp8_bac_reg(data)                                   (*((volatile unsigned int*)LGCY_CODEBLKREG_vp8_bac_reg)=data)
#define  get_LGCY_CODEBLKREG_vp8_bac_reg                                         (*((volatile unsigned int*)LGCY_CODEBLKREG_vp8_bac_reg))
#define  LGCY_CODEBLKREG_vp8_bac_high_shift                                      (20)
#define  LGCY_CODEBLKREG_vp8_bac_bits_shift                                      (16)
#define  LGCY_CODEBLKREG_vp8_bac_code_word_shift                                 (0)
#define  LGCY_CODEBLKREG_vp8_bac_high_mask                                       (0x1FF00000)
#define  LGCY_CODEBLKREG_vp8_bac_bits_mask                                       (0x000F0000)
#define  LGCY_CODEBLKREG_vp8_bac_code_word_mask                                  (0x0000FFFF)
#define  LGCY_CODEBLKREG_vp8_bac_high(data)                                      (0x1FF00000&((data)<<20))
#define  LGCY_CODEBLKREG_vp8_bac_bits(data)                                      (0x000F0000&((data)<<16))
#define  LGCY_CODEBLKREG_vp8_bac_code_word(data)                                 (0x0000FFFF&(data))
#define  LGCY_CODEBLKREG_vp8_bac_get_high(data)                                  ((0x1FF00000&(data))>>20)
#define  LGCY_CODEBLKREG_vp8_bac_get_bits(data)                                  ((0x000F0000&(data))>>16)
#define  LGCY_CODEBLKREG_vp8_bac_get_code_word(data)                             (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGCY_CODEBLKREG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  cm_bypass:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  ldstcmemcount:16;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cabac_1p_mode:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cabac_p2_p3:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  itblk_advmode:1;
    };
}lgcy_codeblkreg_ve_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  dummy_picmb_h:10;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  h264_prev_qp:6;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  pred_bank:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  dec_bank:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  umem_mstr:4;
    };
}lgcy_codeblkreg_umem_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mbaddrb_na:1;
        RBus_UInt32  mbaddra_na:1;
        RBus_UInt32  slicegroup_en:1;
    };
}lgcy_codeblkreg_ve_slicegroup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cabac_curmb_addr:10;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  vld_curmb_addr:10;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  acdc_curmb_addr:8;
    };
}lgcy_codeblkreg_curadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cabac_pred_counter:10;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  vld_pred_counter:10;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  acdc_pred_counter:8;
    };
}lgcy_codeblkreg_predcntr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  frame_field_mbpair:1;
        RBus_UInt32  left_top_luma_d:5;
        RBus_UInt32  left_top_luma_c:5;
        RBus_UInt32  left_top_luma_b:5;
        RBus_UInt32  left_top_luma_a:5;
    };
}lgcy_codeblkreg_total_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  left_top_cb_a:5;
        RBus_UInt32  left_top_cb_b:5;
        RBus_UInt32  left_top_cr_a:5;
        RBus_UInt32  left_top_cr_b:5;
    };
}lgcy_codeblkreg_total_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  left_bot_luma_d:5;
        RBus_UInt32  left_bot_luma_c:5;
        RBus_UInt32  left_bot_luma_b:5;
        RBus_UInt32  left_bot_luma_a:5;
    };
}lgcy_codeblkreg_total_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  left_bot_cb_a:5;
        RBus_UInt32  left_bot_cb_b:5;
        RBus_UInt32  left_bot_cr_a:5;
        RBus_UInt32  left_bot_cr_b:5;
    };
}lgcy_codeblkreg_total_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  ch_q_param_delta_v:6;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  ch_q_param_delta_u:6;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  pb_fld_enhanced_flg:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  frame_pic_type:2;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  skip_mode_flag:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  fixedqp:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  mbweightingflg:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  pic_ref_flg:1;
    };
}lgcy_codeblkreg_ve_avs_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  qpprime_y_zero_transform_bypass_flag:1;
        RBus_UInt32  entropy_coding_mode:1;
        RBus_UInt32  pic_init_qp:6;
        RBus_UInt32  chroma_qp_offset:5;
        RBus_UInt32  second_chroma_qp_offset:5;
        RBus_UInt32  direct_8x8_inferflg:1;
        RBus_UInt32  transform_8x8_mode_flg:1;
        RBus_UInt32  num_ref_idx_l0_active_minus1:5;
        RBus_UInt32  num_ref_idx_l1_active_minus1:5;
    };
}lgcy_codeblkreg_ve_h264_cntl_RBUS;

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
}lgcy_codeblkreg_ve_h264_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  quan_type:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  dquant:2;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  pqindex:5;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  halfqp:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  altpquant:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  dquantfrm:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  dqprofile:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  dqbilevel:1;
    };
}lgcy_codeblkreg_ve_vc1quant_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ttmbf:1;
    };
}lgcy_codeblkreg_ve_vc1transform_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  vc1mvtab:3;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  mvrange_kx:4;
        RBus_UInt32  mvrange_ky:4;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  dmv_extend_x:1;
        RBus_UInt32  dmv_extend_y:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  tab2mvbp:2;
        RBus_UInt32  tab4mvbp:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  bfraction:5;
    };
}lgcy_codeblkreg_ve_vc1mv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  bk_x_fcode:4;
        RBus_UInt32  bk_y_fcode:4;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  fo_x_fcode:4;
        RBus_UInt32  fo_y_fcode:4;
    };
}lgcy_codeblkreg_ve_mvfcode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  dctable_sel:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  transacfrm:2;
        RBus_UInt32  transacfrm2:2;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cbp_table:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  flg_4mvswitch:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mbmodetab:3;
    };
}lgcy_codeblkreg_ve_vc1table_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  escm3_rsize:3;
        RBus_UInt32  escm3_lsize:4;
    };
}lgcy_codeblkreg_ve_vc1esc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rowmb:8;
        RBus_UInt32  colmb:7;
        RBus_UInt32  rowmb_mod3:2;
        RBus_UInt32  colmb_mod3:2;
        RBus_UInt32  bitplane_len:13;
    };
}lgcy_codeblkreg_ve_vc1bitpln_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bitplane_addr:32;
    };
}lgcy_codeblkreg_ve_vc1bitpln_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldst_addr:32;
    };
}lgcy_codeblkreg_ve_ldstaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_bit:32;
    };
}lgcy_codeblkreg_ve_decbitcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bitcnt:32;
    };
}lgcy_codeblkreg_vld_bitcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  detect_startcode_error:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  min_xfer_size:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  startcode_prevnt_en:1;
    };
}lgcy_codeblkreg_ve_bscntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  min_thre:7;
    };
}lgcy_codeblkreg_ve_bs_min_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  timer_value:24;
    };
}lgcy_codeblkreg_ve_bstimer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}lgcy_codeblkreg_ve_bsbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}lgcy_codeblkreg_ve_bslimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}lgcy_codeblkreg_ve_bswrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_ptr:32;
    };
}lgcy_codeblkreg_ve_bscurptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bit_ptr:32;
    };
}lgcy_codeblkreg_ve_decbsptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  removal_counter:29;
    };
}lgcy_codeblkreg_ve_jpg_emu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dec_bit_ptr_msb:3;
    };
}lgcy_codeblkreg_ve_decbsptr_msb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  sad_en:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  sad_threshold:10;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  flat_qtable:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  transform_size_8x8:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  field_transform:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mb_ttfrm:12;
    };
}lgcy_codeblkreg_ve_transform_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  id_pred:2;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  quant_type:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  mquant:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  qpcb:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  qpcr:6;
    };
}lgcy_codeblkreg_ve_quantizer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  qdelta_y2ac:5;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  qdelta_uvdc:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  qdelta_y2dc:5;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  qdelta_y1dc:5;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  vp8_qp:7;
    };
}lgcy_codeblkreg_ve_quantizer2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  blk_pic_idx:7;
    };
}lgcy_codeblkreg_ve_itdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cbp6bits:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  subblkpat:24;
    };
}lgcy_codeblkreg_ve_cbp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  mbpartition:9;
    };
}lgcy_codeblkreg_mb_partition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mb_pred_mode:8;
    };
}lgcy_codeblkreg_mb_predmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable9:1;
        RBus_UInt32  vp9_lossless:1;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  vp6_ref_frame:2;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  mb_pattern:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  intrablks_flg:5;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  ac_pred:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  dc_pred_dir:6;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  mbtype:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  intra_c_pred_mode:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  field_mb:1;
    };
}lgcy_codeblkreg_mb_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  h263_flv_lg1:1;
        RBus_UInt32  ivf:1;
        RBus_UInt32  as:1;
        RBus_UInt32  intra_dc_vlc:1;
        RBus_UInt32  short_hdr:1;
        RBus_UInt32  write_data:1;
    };
}lgcy_codeblkreg_mb_info2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  rv9_intramode_use_top:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  rv_osvquant:2;
    };
}lgcy_codeblkreg_rv_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  struvlc_len:31;
    };
}lgcy_codeblkreg_rv_struvlc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  left_blocks:16;
    };
}lgcy_codeblkreg_rv_intramode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  jpg_dc_first_tbl_bits:4;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  jpg_dc_tbl_startaddr:10;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  first_tbl_bits:4;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  tbl_startaddr:10;
    };
}lgcy_codeblkreg_vldtblptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  tbl_espptr_saddr:10;
    };
}lgcy_codeblkreg_vldespptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lumadc_c:12;
        RBus_UInt32  lumadc_c_intra:1;
        RBus_UInt32  lumadc_d:12;
        RBus_UInt32  lumadc_d_intra:1;
        RBus_UInt32  dcstep_topmb:6;
    };
}lgcy_codeblkreg_ve_acdcp_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cbdc_g:12;
        RBus_UInt32  crdc_g:12;
        RBus_UInt32  cbcr_intra:1;
        RBus_UInt32  ch_dcstep_topmb:5;
    };
}lgcy_codeblkreg_ve_acdcp_chro_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cavlc_halt_done:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cavlc_halt:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  postwrite_en:1;
    };
}lgcy_codeblkreg_ndb_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}lgcy_codeblkreg_ndb_cavlc_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}lgcy_codeblkreg_ndb_cavlc_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}lgcy_codeblkreg_ndb_cavlc_wptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}lgcy_codeblkreg_ndb_cavlc_rptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  segmentation_enabled:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  slice_cnt:8;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  uv_mode:2;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  ref_frame:2;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  mode:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  need_to_clamp_mvs:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mb_skip_coeff:1;
    };
}lgcy_codeblkreg_vp8_p3_frm_mb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  vp8_p3_curmb:9;
    };
}lgcy_codeblkreg_vp8_p3_mb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  high:9;
        RBus_UInt32  bits:4;
        RBus_UInt32  code_word:16;
    };
}lgcy_codeblkreg_vp8_bac_RBUS;

#else //apply LITTLE_ENDIAN

//======LGCY_CODEBLKREG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itblk_advmode:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cabac_p2_p3:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cabac_1p_mode:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  ldstcmemcount:16;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  cm_bypass:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:7;
    };
}lgcy_codeblkreg_ve_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  umem_mstr:4;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  dec_bank:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  pred_bank:2;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  h264_prev_qp:6;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  dummy_picmb_h:10;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:3;
    };
}lgcy_codeblkreg_umem_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slicegroup_en:1;
        RBus_UInt32  mbaddra_na:1;
        RBus_UInt32  mbaddrb_na:1;
        RBus_UInt32  res1:29;
    };
}lgcy_codeblkreg_ve_slicegroup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acdc_curmb_addr:8;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  vld_curmb_addr:10;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cabac_curmb_addr:10;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:1;
    };
}lgcy_codeblkreg_curadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acdc_pred_counter:8;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  vld_pred_counter:10;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cabac_pred_counter:10;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:1;
    };
}lgcy_codeblkreg_predcntr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_top_luma_a:5;
        RBus_UInt32  left_top_luma_b:5;
        RBus_UInt32  left_top_luma_c:5;
        RBus_UInt32  left_top_luma_d:5;
        RBus_UInt32  frame_field_mbpair:1;
        RBus_UInt32  res1:11;
    };
}lgcy_codeblkreg_total_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_top_cr_b:5;
        RBus_UInt32  left_top_cr_a:5;
        RBus_UInt32  left_top_cb_b:5;
        RBus_UInt32  left_top_cb_a:5;
        RBus_UInt32  res1:12;
    };
}lgcy_codeblkreg_total_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_bot_luma_a:5;
        RBus_UInt32  left_bot_luma_b:5;
        RBus_UInt32  left_bot_luma_c:5;
        RBus_UInt32  left_bot_luma_d:5;
        RBus_UInt32  res1:12;
    };
}lgcy_codeblkreg_total_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_bot_cr_b:5;
        RBus_UInt32  left_bot_cr_a:5;
        RBus_UInt32  left_bot_cb_b:5;
        RBus_UInt32  left_bot_cb_a:5;
        RBus_UInt32  res1:12;
    };
}lgcy_codeblkreg_total_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pic_ref_flg:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mbweightingflg:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  fixedqp:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  skip_mode_flag:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  frame_pic_type:2;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  pb_fld_enhanced_flg:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  ch_q_param_delta_u:6;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  ch_q_param_delta_v:6;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  res1:5;
    };
}lgcy_codeblkreg_ve_avs_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  num_ref_idx_l1_active_minus1:5;
        RBus_UInt32  num_ref_idx_l0_active_minus1:5;
        RBus_UInt32  transform_8x8_mode_flg:1;
        RBus_UInt32  direct_8x8_inferflg:1;
        RBus_UInt32  second_chroma_qp_offset:5;
        RBus_UInt32  chroma_qp_offset:5;
        RBus_UInt32  pic_init_qp:6;
        RBus_UInt32  entropy_coding_mode:1;
        RBus_UInt32  qpprime_y_zero_transform_bypass_flag:1;
        RBus_UInt32  res1:2;
    };
}lgcy_codeblkreg_ve_h264_cntl_RBUS;

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
}lgcy_codeblkreg_ve_h264_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dqbilevel:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  dqprofile:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  dquantfrm:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  altpquant:5;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  halfqp:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  pqindex:5;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  dquant:2;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  quan_type:1;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  res1:6;
    };
}lgcy_codeblkreg_ve_vc1quant_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ttmbf:1;
        RBus_UInt32  res1:31;
    };
}lgcy_codeblkreg_ve_vc1transform_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bfraction:5;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  tab4mvbp:2;
        RBus_UInt32  tab2mvbp:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  dmv_extend_y:1;
        RBus_UInt32  dmv_extend_x:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  mvrange_ky:4;
        RBus_UInt32  mvrange_kx:4;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  vc1mvtab:3;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:5;
    };
}lgcy_codeblkreg_ve_vc1mv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fo_y_fcode:4;
        RBus_UInt32  fo_x_fcode:4;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  bk_y_fcode:4;
        RBus_UInt32  bk_x_fcode:4;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  res1:14;
    };
}lgcy_codeblkreg_ve_mvfcode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbmodetab:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  flg_4mvswitch:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cbp_table:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  transacfrm2:2;
        RBus_UInt32  transacfrm:2;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  dctable_sel:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:15;
    };
}lgcy_codeblkreg_ve_vc1table_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  escm3_lsize:4;
        RBus_UInt32  escm3_rsize:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res1:24;
    };
}lgcy_codeblkreg_ve_vc1esc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bitplane_len:13;
        RBus_UInt32  colmb_mod3:2;
        RBus_UInt32  rowmb_mod3:2;
        RBus_UInt32  colmb:7;
        RBus_UInt32  rowmb:8;
    };
}lgcy_codeblkreg_ve_vc1bitpln_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bitplane_addr:32;
    };
}lgcy_codeblkreg_ve_vc1bitpln_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldst_addr:32;
    };
}lgcy_codeblkreg_ve_ldstaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_bit:32;
    };
}lgcy_codeblkreg_ve_decbitcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bitcnt:32;
    };
}lgcy_codeblkreg_vld_bitcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startcode_prevnt_en:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  min_xfer_size:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  detect_startcode_error:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:25;
    };
}lgcy_codeblkreg_ve_bscntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_thre:7;
        RBus_UInt32  res1:25;
    };
}lgcy_codeblkreg_ve_bs_min_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timer_value:24;
        RBus_UInt32  res1:8;
    };
}lgcy_codeblkreg_ve_bstimer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}lgcy_codeblkreg_ve_bsbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}lgcy_codeblkreg_ve_bslimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}lgcy_codeblkreg_ve_bswrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_ptr:32;
    };
}lgcy_codeblkreg_ve_bscurptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bit_ptr:32;
    };
}lgcy_codeblkreg_ve_decbsptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  removal_counter:29;
        RBus_UInt32  res1:3;
    };
}lgcy_codeblkreg_ve_jpg_emu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bit_ptr_msb:3;
        RBus_UInt32  res1:29;
    };
}lgcy_codeblkreg_ve_decbsptr_msb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_ttfrm:12;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  field_transform:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  transform_size_8x8:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  flat_qtable:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  sad_threshold:10;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  sad_en:1;
        RBus_UInt32  write_enable6:1;
    };
}lgcy_codeblkreg_ve_transform_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qpcr:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  qpcb:6;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  mquant:5;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  quant_type:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  id_pred:2;
        RBus_UInt32  write_enable6:1;
    };
}lgcy_codeblkreg_ve_quantizer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vp8_qp:7;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  qdelta_y1dc:5;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  qdelta_y2dc:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  qdelta_uvdc:5;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  qdelta_y2ac:5;
        RBus_UInt32  write_enable5:1;
    };
}lgcy_codeblkreg_ve_quantizer2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blk_pic_idx:7;
        RBus_UInt32  res1:25;
    };
}lgcy_codeblkreg_ve_itdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subblkpat:24;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cbp6bits:6;
        RBus_UInt32  write_enable2:1;
    };
}lgcy_codeblkreg_ve_cbp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbpartition:9;
        RBus_UInt32  res1:23;
    };
}lgcy_codeblkreg_mb_partition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_pred_mode:8;
        RBus_UInt32  res1:24;
    };
}lgcy_codeblkreg_mb_predmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  field_mb:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  intra_c_pred_mode:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  mbtype:4;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  dc_pred_dir:6;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  ac_pred:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  intrablks_flg:5;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  mb_pattern:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  vp6_ref_frame:2;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  vp9_lossless:1;
        RBus_UInt32  write_enable9:1;
    };
}lgcy_codeblkreg_mb_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  short_hdr:1;
        RBus_UInt32  intra_dc_vlc:1;
        RBus_UInt32  as:1;
        RBus_UInt32  ivf:1;
        RBus_UInt32  h263_flv_lg1:1;
        RBus_UInt32  res1:26;
    };
}lgcy_codeblkreg_mb_info2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rv_osvquant:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  rv9_intramode_use_top:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  res1:27;
    };
}lgcy_codeblkreg_rv_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  struvlc_len:31;
        RBus_UInt32  res1:1;
    };
}lgcy_codeblkreg_rv_struvlc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_blocks:16;
        RBus_UInt32  res1:16;
    };
}lgcy_codeblkreg_rv_intramode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbl_startaddr:10;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  first_tbl_bits:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  jpg_dc_tbl_startaddr:10;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  jpg_dc_first_tbl_bits:4;
        RBus_UInt32  write_enable4:1;
    };
}lgcy_codeblkreg_vldtblptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbl_espptr_saddr:10;
        RBus_UInt32  res1:22;
    };
}lgcy_codeblkreg_vldespptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcstep_topmb:6;
        RBus_UInt32  lumadc_d_intra:1;
        RBus_UInt32  lumadc_d:12;
        RBus_UInt32  lumadc_c_intra:1;
        RBus_UInt32  lumadc_c:12;
    };
}lgcy_codeblkreg_ve_acdcp_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_dcstep_topmb:5;
        RBus_UInt32  cbcr_intra:1;
        RBus_UInt32  crdc_g:12;
        RBus_UInt32  cbdc_g:12;
        RBus_UInt32  res1:2;
    };
}lgcy_codeblkreg_ve_acdcp_chro_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postwrite_en:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cavlc_halt:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cavlc_halt_done:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:26;
    };
}lgcy_codeblkreg_ndb_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}lgcy_codeblkreg_ndb_cavlc_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}lgcy_codeblkreg_ndb_cavlc_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}lgcy_codeblkreg_ndb_cavlc_wptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}lgcy_codeblkreg_ndb_cavlc_rptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_skip_coeff:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  need_to_clamp_mvs:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  mode:4;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  ref_frame:2;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  uv_mode:2;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  slice_cnt:8;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  segmentation_enabled:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  res1:6;
    };
}lgcy_codeblkreg_vp8_p3_frm_mb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vp8_p3_curmb:9;
        RBus_UInt32  res1:23;
    };
}lgcy_codeblkreg_vp8_p3_mb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  code_word:16;
        RBus_UInt32  bits:4;
        RBus_UInt32  high:9;
        RBus_UInt32  res1:3;
    };
}lgcy_codeblkreg_vp8_bac_RBUS;




#endif 


#endif 
