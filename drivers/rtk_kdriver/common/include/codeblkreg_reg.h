/**
* @file rbusCodeblkregReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_CODEBLKREG_REG_H_
#define _RBUS_CODEBLKREG_REG_H_

#include "rbusTypes.h"



//  CODEBLKREG Register Address
#define  CODEBLKREG_VE_CNTL                                                      0x1800E000
#define  CODEBLKREG_VE_CNTL_reg_addr                                             "0xB800E000"
#define  CODEBLKREG_VE_CNTL_reg                                                  0xB800E000
#define  CODEBLKREG_VE_CNTL_inst_addr                                            "0x0000"
#define  CODEBLKREG_VE_CNTL_inst_adr                                             "0x0000"
#define  CODEBLKREG_VE_CNTL_inst                                                 0x0000
#define  set_CODEBLKREG_VE_CNTL_reg(data)                                        (*((volatile unsigned int*)CODEBLKREG_VE_CNTL_reg)=data)
#define  get_CODEBLKREG_VE_CNTL_reg                                              (*((volatile unsigned int*)CODEBLKREG_VE_CNTL_reg))
#define  CODEBLKREG_VE_CNTL_write_enable5_shift                                  (24)
#define  CODEBLKREG_VE_CNTL_cm_bypass_shift                                      (23)
#define  CODEBLKREG_VE_CNTL_write_enable4_shift                                  (22)
#define  CODEBLKREG_VE_CNTL_ldstCmemCount_shift                                  (6)
#define  CODEBLKREG_VE_CNTL_write_enable3_shift                                  (5)
#define  CODEBLKREG_VE_CNTL_cabac_1p_mode_shift                                  (4)
#define  CODEBLKREG_VE_CNTL_write_enable2_shift                                  (3)
#define  CODEBLKREG_VE_CNTL_cabac_p2_p3_shift                                    (2)
#define  CODEBLKREG_VE_CNTL_write_enable1_shift                                  (1)
#define  CODEBLKREG_VE_CNTL_itblk_advmode_shift                                  (0)
#define  CODEBLKREG_VE_CNTL_write_enable5_mask                                   (0x01000000)
#define  CODEBLKREG_VE_CNTL_cm_bypass_mask                                       (0x00800000)
#define  CODEBLKREG_VE_CNTL_write_enable4_mask                                   (0x00400000)
#define  CODEBLKREG_VE_CNTL_ldstCmemCount_mask                                   (0x003FFFC0)
#define  CODEBLKREG_VE_CNTL_write_enable3_mask                                   (0x00000020)
#define  CODEBLKREG_VE_CNTL_cabac_1p_mode_mask                                   (0x00000010)
#define  CODEBLKREG_VE_CNTL_write_enable2_mask                                   (0x00000008)
#define  CODEBLKREG_VE_CNTL_cabac_p2_p3_mask                                     (0x00000004)
#define  CODEBLKREG_VE_CNTL_write_enable1_mask                                   (0x00000002)
#define  CODEBLKREG_VE_CNTL_itblk_advmode_mask                                   (0x00000001)
#define  CODEBLKREG_VE_CNTL_write_enable5(data)                                  (0x01000000&((data)<<24))
#define  CODEBLKREG_VE_CNTL_cm_bypass(data)                                      (0x00800000&((data)<<23))
#define  CODEBLKREG_VE_CNTL_write_enable4(data)                                  (0x00400000&((data)<<22))
#define  CODEBLKREG_VE_CNTL_ldstCmemCount(data)                                  (0x003FFFC0&((data)<<6))
#define  CODEBLKREG_VE_CNTL_write_enable3(data)                                  (0x00000020&((data)<<5))
#define  CODEBLKREG_VE_CNTL_cabac_1p_mode(data)                                  (0x00000010&((data)<<4))
#define  CODEBLKREG_VE_CNTL_write_enable2(data)                                  (0x00000008&((data)<<3))
#define  CODEBLKREG_VE_CNTL_cabac_p2_p3(data)                                    (0x00000004&((data)<<2))
#define  CODEBLKREG_VE_CNTL_write_enable1(data)                                  (0x00000002&((data)<<1))
#define  CODEBLKREG_VE_CNTL_itblk_advmode(data)                                  (0x00000001&(data))
#define  CODEBLKREG_VE_CNTL_get_write_enable5(data)                              ((0x01000000&(data))>>24)
#define  CODEBLKREG_VE_CNTL_get_cm_bypass(data)                                  ((0x00800000&(data))>>23)
#define  CODEBLKREG_VE_CNTL_get_write_enable4(data)                              ((0x00400000&(data))>>22)
#define  CODEBLKREG_VE_CNTL_get_ldstCmemCount(data)                              ((0x003FFFC0&(data))>>6)
#define  CODEBLKREG_VE_CNTL_get_write_enable3(data)                              ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_CNTL_get_cabac_1p_mode(data)                              ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_CNTL_get_write_enable2(data)                              ((0x00000008&(data))>>3)
#define  CODEBLKREG_VE_CNTL_get_cabac_p2_p3(data)                                ((0x00000004&(data))>>2)
#define  CODEBLKREG_VE_CNTL_get_write_enable1(data)                              ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_CNTL_get_itblk_advmode(data)                              (0x00000001&(data))
#define  CODEBLKREG_VE_CNTL_write_enable5_src(data)                              ((0x01000000&(data))>>24)
#define  CODEBLKREG_VE_CNTL_cm_bypass_src(data)                                  ((0x00800000&(data))>>23)
#define  CODEBLKREG_VE_CNTL_write_enable4_src(data)                              ((0x00400000&(data))>>22)
#define  CODEBLKREG_VE_CNTL_ldstCmemCount_src(data)                              ((0x003FFFC0&(data))>>6)
#define  CODEBLKREG_VE_CNTL_write_enable3_src(data)                              ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_CNTL_cabac_1p_mode_src(data)                              ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_CNTL_write_enable2_src(data)                              ((0x00000008&(data))>>3)
#define  CODEBLKREG_VE_CNTL_cabac_p2_p3_src(data)                                ((0x00000004&(data))>>2)
#define  CODEBLKREG_VE_CNTL_write_enable1_src(data)                              ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_CNTL_itblk_advmode_src(data)                              (0x00000001&(data))

#define  CODEBLKREG_UMEM_CTRL                                                    0x1800E004
#define  CODEBLKREG_UMEM_CTRL_reg_addr                                           "0xB800E004"
#define  CODEBLKREG_UMEM_CTRL_reg                                                0xB800E004
#define  CODEBLKREG_UMEM_CTRL_inst_addr                                          "0x0001"
#define  CODEBLKREG_UMEM_CTRL_inst_adr                                           "0x0001"
#define  CODEBLKREG_UMEM_CTRL_inst                                               0x0001
#define  set_CODEBLKREG_UMEM_CTRL_reg(data)                                      (*((volatile unsigned int*)CODEBLKREG_UMEM_CTRL_reg)=data)
#define  get_CODEBLKREG_UMEM_CTRL_reg                                            (*((volatile unsigned int*)CODEBLKREG_UMEM_CTRL_reg))
#define  CODEBLKREG_UMEM_CTRL_write_enable5_shift                                (28)
#define  CODEBLKREG_UMEM_CTRL_dummy_picmb_h_shift                                (18)
#define  CODEBLKREG_UMEM_CTRL_write_enable4_shift                                (17)
#define  CODEBLKREG_UMEM_CTRL_h264_prev_qp_shift                                 (11)
#define  CODEBLKREG_UMEM_CTRL_write_enable3_shift                                (10)
#define  CODEBLKREG_UMEM_CTRL_pred_bank_shift                                    (8)
#define  CODEBLKREG_UMEM_CTRL_write_enable2_shift                                (7)
#define  CODEBLKREG_UMEM_CTRL_dec_bank_shift                                     (5)
#define  CODEBLKREG_UMEM_CTRL_write_enable1_shift                                (4)
#define  CODEBLKREG_UMEM_CTRL_umem_mstr_shift                                    (0)
#define  CODEBLKREG_UMEM_CTRL_write_enable5_mask                                 (0x10000000)
#define  CODEBLKREG_UMEM_CTRL_dummy_picmb_h_mask                                 (0x0FFC0000)
#define  CODEBLKREG_UMEM_CTRL_write_enable4_mask                                 (0x00020000)
#define  CODEBLKREG_UMEM_CTRL_h264_prev_qp_mask                                  (0x0001F800)
#define  CODEBLKREG_UMEM_CTRL_write_enable3_mask                                 (0x00000400)
#define  CODEBLKREG_UMEM_CTRL_pred_bank_mask                                     (0x00000300)
#define  CODEBLKREG_UMEM_CTRL_write_enable2_mask                                 (0x00000080)
#define  CODEBLKREG_UMEM_CTRL_dec_bank_mask                                      (0x00000060)
#define  CODEBLKREG_UMEM_CTRL_write_enable1_mask                                 (0x00000010)
#define  CODEBLKREG_UMEM_CTRL_umem_mstr_mask                                     (0x0000000F)
#define  CODEBLKREG_UMEM_CTRL_write_enable5(data)                                (0x10000000&((data)<<28))
#define  CODEBLKREG_UMEM_CTRL_dummy_picmb_h(data)                                (0x0FFC0000&((data)<<18))
#define  CODEBLKREG_UMEM_CTRL_write_enable4(data)                                (0x00020000&((data)<<17))
#define  CODEBLKREG_UMEM_CTRL_h264_prev_qp(data)                                 (0x0001F800&((data)<<11))
#define  CODEBLKREG_UMEM_CTRL_write_enable3(data)                                (0x00000400&((data)<<10))
#define  CODEBLKREG_UMEM_CTRL_pred_bank(data)                                    (0x00000300&((data)<<8))
#define  CODEBLKREG_UMEM_CTRL_write_enable2(data)                                (0x00000080&((data)<<7))
#define  CODEBLKREG_UMEM_CTRL_dec_bank(data)                                     (0x00000060&((data)<<5))
#define  CODEBLKREG_UMEM_CTRL_write_enable1(data)                                (0x00000010&((data)<<4))
#define  CODEBLKREG_UMEM_CTRL_umem_mstr(data)                                    (0x0000000F&(data))
#define  CODEBLKREG_UMEM_CTRL_get_write_enable5(data)                            ((0x10000000&(data))>>28)
#define  CODEBLKREG_UMEM_CTRL_get_dummy_picmb_h(data)                            ((0x0FFC0000&(data))>>18)
#define  CODEBLKREG_UMEM_CTRL_get_write_enable4(data)                            ((0x00020000&(data))>>17)
#define  CODEBLKREG_UMEM_CTRL_get_h264_prev_qp(data)                             ((0x0001F800&(data))>>11)
#define  CODEBLKREG_UMEM_CTRL_get_write_enable3(data)                            ((0x00000400&(data))>>10)
#define  CODEBLKREG_UMEM_CTRL_get_pred_bank(data)                                ((0x00000300&(data))>>8)
#define  CODEBLKREG_UMEM_CTRL_get_write_enable2(data)                            ((0x00000080&(data))>>7)
#define  CODEBLKREG_UMEM_CTRL_get_dec_bank(data)                                 ((0x00000060&(data))>>5)
#define  CODEBLKREG_UMEM_CTRL_get_write_enable1(data)                            ((0x00000010&(data))>>4)
#define  CODEBLKREG_UMEM_CTRL_get_umem_mstr(data)                                (0x0000000F&(data))
#define  CODEBLKREG_UMEM_CTRL_write_enable5_src(data)                            ((0x10000000&(data))>>28)
#define  CODEBLKREG_UMEM_CTRL_dummy_picmb_h_src(data)                            ((0x0FFC0000&(data))>>18)
#define  CODEBLKREG_UMEM_CTRL_write_enable4_src(data)                            ((0x00020000&(data))>>17)
#define  CODEBLKREG_UMEM_CTRL_h264_prev_qp_src(data)                             ((0x0001F800&(data))>>11)
#define  CODEBLKREG_UMEM_CTRL_write_enable3_src(data)                            ((0x00000400&(data))>>10)
#define  CODEBLKREG_UMEM_CTRL_pred_bank_src(data)                                ((0x00000300&(data))>>8)
#define  CODEBLKREG_UMEM_CTRL_write_enable2_src(data)                            ((0x00000080&(data))>>7)
#define  CODEBLKREG_UMEM_CTRL_dec_bank_src(data)                                 ((0x00000060&(data))>>5)
#define  CODEBLKREG_UMEM_CTRL_write_enable1_src(data)                            ((0x00000010&(data))>>4)
#define  CODEBLKREG_UMEM_CTRL_umem_mstr_src(data)                                (0x0000000F&(data))

#define  CODEBLKREG_VE_SLICEGROUP                                                0x1800E008
#define  CODEBLKREG_VE_SLICEGROUP_reg_addr                                       "0xB800E008"
#define  CODEBLKREG_VE_SLICEGROUP_reg                                            0xB800E008
#define  CODEBLKREG_VE_SLICEGROUP_inst_addr                                      "0x0002"
#define  CODEBLKREG_VE_SLICEGROUP_inst_adr                                       "0x0002"
#define  CODEBLKREG_VE_SLICEGROUP_inst                                           0x0002
#define  set_CODEBLKREG_VE_SLICEGROUP_reg(data)                                  (*((volatile unsigned int*)CODEBLKREG_VE_SLICEGROUP_reg)=data)
#define  get_CODEBLKREG_VE_SLICEGROUP_reg                                        (*((volatile unsigned int*)CODEBLKREG_VE_SLICEGROUP_reg))
#define  CODEBLKREG_VE_SLICEGROUP_mbaddrb_na_shift                               (2)
#define  CODEBLKREG_VE_SLICEGROUP_mbaddra_na_shift                               (1)
#define  CODEBLKREG_VE_SLICEGROUP_slicegroup_en_shift                            (0)
#define  CODEBLKREG_VE_SLICEGROUP_mbaddrb_na_mask                                (0x00000004)
#define  CODEBLKREG_VE_SLICEGROUP_mbaddra_na_mask                                (0x00000002)
#define  CODEBLKREG_VE_SLICEGROUP_slicegroup_en_mask                             (0x00000001)
#define  CODEBLKREG_VE_SLICEGROUP_mbaddrb_na(data)                               (0x00000004&((data)<<2))
#define  CODEBLKREG_VE_SLICEGROUP_mbaddra_na(data)                               (0x00000002&((data)<<1))
#define  CODEBLKREG_VE_SLICEGROUP_slicegroup_en(data)                            (0x00000001&(data))
#define  CODEBLKREG_VE_SLICEGROUP_get_mbaddrb_na(data)                           ((0x00000004&(data))>>2)
#define  CODEBLKREG_VE_SLICEGROUP_get_mbaddra_na(data)                           ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_SLICEGROUP_get_slicegroup_en(data)                        (0x00000001&(data))
#define  CODEBLKREG_VE_SLICEGROUP_mbaddrb_na_src(data)                           ((0x00000004&(data))>>2)
#define  CODEBLKREG_VE_SLICEGROUP_mbaddra_na_src(data)                           ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_SLICEGROUP_slicegroup_en_src(data)                        (0x00000001&(data))

#define  CODEBLKREG_CURADR                                                       0x1800E00C
#define  CODEBLKREG_CURADR_reg_addr                                              "0xB800E00C"
#define  CODEBLKREG_CURADR_reg                                                   0xB800E00C
#define  CODEBLKREG_CURADR_inst_addr                                             "0x0003"
#define  CODEBLKREG_CURADR_inst_adr                                              "0x0003"
#define  CODEBLKREG_CURADR_inst                                                  0x0003
#define  set_CODEBLKREG_CURADR_reg(data)                                         (*((volatile unsigned int*)CODEBLKREG_CURADR_reg)=data)
#define  get_CODEBLKREG_CURADR_reg                                               (*((volatile unsigned int*)CODEBLKREG_CURADR_reg))
#define  CODEBLKREG_CURADR_write_enable3_shift                                   (30)
#define  CODEBLKREG_CURADR_cabac_curmb_addr_shift                                (20)
#define  CODEBLKREG_CURADR_write_enable2_shift                                   (19)
#define  CODEBLKREG_CURADR_vld_curmb_addr_shift                                  (9)
#define  CODEBLKREG_CURADR_write_enable1_shift                                   (8)
#define  CODEBLKREG_CURADR_acdc_curmb_addr_shift                                 (0)
#define  CODEBLKREG_CURADR_write_enable3_mask                                    (0x40000000)
#define  CODEBLKREG_CURADR_cabac_curmb_addr_mask                                 (0x3FF00000)
#define  CODEBLKREG_CURADR_write_enable2_mask                                    (0x00080000)
#define  CODEBLKREG_CURADR_vld_curmb_addr_mask                                   (0x0007FE00)
#define  CODEBLKREG_CURADR_write_enable1_mask                                    (0x00000100)
#define  CODEBLKREG_CURADR_acdc_curmb_addr_mask                                  (0x000000FF)
#define  CODEBLKREG_CURADR_write_enable3(data)                                   (0x40000000&((data)<<30))
#define  CODEBLKREG_CURADR_cabac_curmb_addr(data)                                (0x3FF00000&((data)<<20))
#define  CODEBLKREG_CURADR_write_enable2(data)                                   (0x00080000&((data)<<19))
#define  CODEBLKREG_CURADR_vld_curmb_addr(data)                                  (0x0007FE00&((data)<<9))
#define  CODEBLKREG_CURADR_write_enable1(data)                                   (0x00000100&((data)<<8))
#define  CODEBLKREG_CURADR_acdc_curmb_addr(data)                                 (0x000000FF&(data))
#define  CODEBLKREG_CURADR_get_write_enable3(data)                               ((0x40000000&(data))>>30)
#define  CODEBLKREG_CURADR_get_cabac_curmb_addr(data)                            ((0x3FF00000&(data))>>20)
#define  CODEBLKREG_CURADR_get_write_enable2(data)                               ((0x00080000&(data))>>19)
#define  CODEBLKREG_CURADR_get_vld_curmb_addr(data)                              ((0x0007FE00&(data))>>9)
#define  CODEBLKREG_CURADR_get_write_enable1(data)                               ((0x00000100&(data))>>8)
#define  CODEBLKREG_CURADR_get_acdc_curmb_addr(data)                             (0x000000FF&(data))
#define  CODEBLKREG_CURADR_write_enable3_src(data)                               ((0x40000000&(data))>>30)
#define  CODEBLKREG_CURADR_cabac_curmb_addr_src(data)                            ((0x3FF00000&(data))>>20)
#define  CODEBLKREG_CURADR_write_enable2_src(data)                               ((0x00080000&(data))>>19)
#define  CODEBLKREG_CURADR_vld_curmb_addr_src(data)                              ((0x0007FE00&(data))>>9)
#define  CODEBLKREG_CURADR_write_enable1_src(data)                               ((0x00000100&(data))>>8)
#define  CODEBLKREG_CURADR_acdc_curmb_addr_src(data)                             (0x000000FF&(data))

#define  CODEBLKREG_PREDCNTR                                                     0x1800E010
#define  CODEBLKREG_PREDCNTR_reg_addr                                            "0xB800E010"
#define  CODEBLKREG_PREDCNTR_reg                                                 0xB800E010
#define  CODEBLKREG_PREDCNTR_inst_addr                                           "0x0004"
#define  CODEBLKREG_PREDCNTR_inst_adr                                            "0x0004"
#define  CODEBLKREG_PREDCNTR_inst                                                0x0004
#define  set_CODEBLKREG_PREDCNTR_reg(data)                                       (*((volatile unsigned int*)CODEBLKREG_PREDCNTR_reg)=data)
#define  get_CODEBLKREG_PREDCNTR_reg                                             (*((volatile unsigned int*)CODEBLKREG_PREDCNTR_reg))
#define  CODEBLKREG_PREDCNTR_write_enable3_shift                                 (30)
#define  CODEBLKREG_PREDCNTR_cabac_pred_counter_shift                            (20)
#define  CODEBLKREG_PREDCNTR_write_enable2_shift                                 (19)
#define  CODEBLKREG_PREDCNTR_vld_pred_counter_shift                              (9)
#define  CODEBLKREG_PREDCNTR_write_enable1_shift                                 (8)
#define  CODEBLKREG_PREDCNTR_acdc_pred_counter_shift                             (0)
#define  CODEBLKREG_PREDCNTR_write_enable3_mask                                  (0x40000000)
#define  CODEBLKREG_PREDCNTR_cabac_pred_counter_mask                             (0x3FF00000)
#define  CODEBLKREG_PREDCNTR_write_enable2_mask                                  (0x00080000)
#define  CODEBLKREG_PREDCNTR_vld_pred_counter_mask                               (0x0007FE00)
#define  CODEBLKREG_PREDCNTR_write_enable1_mask                                  (0x00000100)
#define  CODEBLKREG_PREDCNTR_acdc_pred_counter_mask                              (0x000000FF)
#define  CODEBLKREG_PREDCNTR_write_enable3(data)                                 (0x40000000&((data)<<30))
#define  CODEBLKREG_PREDCNTR_cabac_pred_counter(data)                            (0x3FF00000&((data)<<20))
#define  CODEBLKREG_PREDCNTR_write_enable2(data)                                 (0x00080000&((data)<<19))
#define  CODEBLKREG_PREDCNTR_vld_pred_counter(data)                              (0x0007FE00&((data)<<9))
#define  CODEBLKREG_PREDCNTR_write_enable1(data)                                 (0x00000100&((data)<<8))
#define  CODEBLKREG_PREDCNTR_acdc_pred_counter(data)                             (0x000000FF&(data))
#define  CODEBLKREG_PREDCNTR_get_write_enable3(data)                             ((0x40000000&(data))>>30)
#define  CODEBLKREG_PREDCNTR_get_cabac_pred_counter(data)                        ((0x3FF00000&(data))>>20)
#define  CODEBLKREG_PREDCNTR_get_write_enable2(data)                             ((0x00080000&(data))>>19)
#define  CODEBLKREG_PREDCNTR_get_vld_pred_counter(data)                          ((0x0007FE00&(data))>>9)
#define  CODEBLKREG_PREDCNTR_get_write_enable1(data)                             ((0x00000100&(data))>>8)
#define  CODEBLKREG_PREDCNTR_get_acdc_pred_counter(data)                         (0x000000FF&(data))
#define  CODEBLKREG_PREDCNTR_write_enable3_src(data)                             ((0x40000000&(data))>>30)
#define  CODEBLKREG_PREDCNTR_cabac_pred_counter_src(data)                        ((0x3FF00000&(data))>>20)
#define  CODEBLKREG_PREDCNTR_write_enable2_src(data)                             ((0x00080000&(data))>>19)
#define  CODEBLKREG_PREDCNTR_vld_pred_counter_src(data)                          ((0x0007FE00&(data))>>9)
#define  CODEBLKREG_PREDCNTR_write_enable1_src(data)                             ((0x00000100&(data))>>8)
#define  CODEBLKREG_PREDCNTR_acdc_pred_counter_src(data)                         (0x000000FF&(data))

#define  CODEBLKREG_TOTAL_COEF1                                                  0x1800E014
#define  CODEBLKREG_TOTAL_COEF1_reg_addr                                         "0xB800E014"
#define  CODEBLKREG_TOTAL_COEF1_reg                                              0xB800E014
#define  CODEBLKREG_TOTAL_COEF1_inst_addr                                        "0x0005"
#define  CODEBLKREG_TOTAL_COEF1_inst_adr                                         "0x0005"
#define  CODEBLKREG_TOTAL_COEF1_inst                                             0x0005
#define  set_CODEBLKREG_TOTAL_COEF1_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_TOTAL_COEF1_reg)=data)
#define  get_CODEBLKREG_TOTAL_COEF1_reg                                          (*((volatile unsigned int*)CODEBLKREG_TOTAL_COEF1_reg))
#define  CODEBLKREG_TOTAL_COEF1_frame_field_mbpair_shift                         (20)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_d_shift                            (15)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_c_shift                            (10)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_b_shift                            (5)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_a_shift                            (0)
#define  CODEBLKREG_TOTAL_COEF1_frame_field_mbpair_mask                          (0x00100000)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_d_mask                             (0x000F8000)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_c_mask                             (0x00007C00)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_b_mask                             (0x000003E0)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_a_mask                             (0x0000001F)
#define  CODEBLKREG_TOTAL_COEF1_frame_field_mbpair(data)                         (0x00100000&((data)<<20))
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_d(data)                            (0x000F8000&((data)<<15))
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_c(data)                            (0x00007C00&((data)<<10))
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_b(data)                            (0x000003E0&((data)<<5))
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_a(data)                            (0x0000001F&(data))
#define  CODEBLKREG_TOTAL_COEF1_get_frame_field_mbpair(data)                     ((0x00100000&(data))>>20)
#define  CODEBLKREG_TOTAL_COEF1_get_left_top_luma_d(data)                        ((0x000F8000&(data))>>15)
#define  CODEBLKREG_TOTAL_COEF1_get_left_top_luma_c(data)                        ((0x00007C00&(data))>>10)
#define  CODEBLKREG_TOTAL_COEF1_get_left_top_luma_b(data)                        ((0x000003E0&(data))>>5)
#define  CODEBLKREG_TOTAL_COEF1_get_left_top_luma_a(data)                        (0x0000001F&(data))
#define  CODEBLKREG_TOTAL_COEF1_frame_field_mbpair_src(data)                     ((0x00100000&(data))>>20)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_d_src(data)                        ((0x000F8000&(data))>>15)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_c_src(data)                        ((0x00007C00&(data))>>10)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_b_src(data)                        ((0x000003E0&(data))>>5)
#define  CODEBLKREG_TOTAL_COEF1_left_top_luma_a_src(data)                        (0x0000001F&(data))

#define  CODEBLKREG_TOTAL_COEF2                                                  0x1800E018
#define  CODEBLKREG_TOTAL_COEF2_reg_addr                                         "0xB800E018"
#define  CODEBLKREG_TOTAL_COEF2_reg                                              0xB800E018
#define  CODEBLKREG_TOTAL_COEF2_inst_addr                                        "0x0006"
#define  CODEBLKREG_TOTAL_COEF2_inst_adr                                         "0x0006"
#define  CODEBLKREG_TOTAL_COEF2_inst                                             0x0006
#define  set_CODEBLKREG_TOTAL_COEF2_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_TOTAL_COEF2_reg)=data)
#define  get_CODEBLKREG_TOTAL_COEF2_reg                                          (*((volatile unsigned int*)CODEBLKREG_TOTAL_COEF2_reg))
#define  CODEBLKREG_TOTAL_COEF2_left_top_cb_a_shift                              (15)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cb_b_shift                              (10)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cr_a_shift                              (5)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cr_b_shift                              (0)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cb_a_mask                               (0x000F8000)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cb_b_mask                               (0x00007C00)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cr_a_mask                               (0x000003E0)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cr_b_mask                               (0x0000001F)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cb_a(data)                              (0x000F8000&((data)<<15))
#define  CODEBLKREG_TOTAL_COEF2_left_top_cb_b(data)                              (0x00007C00&((data)<<10))
#define  CODEBLKREG_TOTAL_COEF2_left_top_cr_a(data)                              (0x000003E0&((data)<<5))
#define  CODEBLKREG_TOTAL_COEF2_left_top_cr_b(data)                              (0x0000001F&(data))
#define  CODEBLKREG_TOTAL_COEF2_get_left_top_cb_a(data)                          ((0x000F8000&(data))>>15)
#define  CODEBLKREG_TOTAL_COEF2_get_left_top_cb_b(data)                          ((0x00007C00&(data))>>10)
#define  CODEBLKREG_TOTAL_COEF2_get_left_top_cr_a(data)                          ((0x000003E0&(data))>>5)
#define  CODEBLKREG_TOTAL_COEF2_get_left_top_cr_b(data)                          (0x0000001F&(data))
#define  CODEBLKREG_TOTAL_COEF2_left_top_cb_a_src(data)                          ((0x000F8000&(data))>>15)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cb_b_src(data)                          ((0x00007C00&(data))>>10)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cr_a_src(data)                          ((0x000003E0&(data))>>5)
#define  CODEBLKREG_TOTAL_COEF2_left_top_cr_b_src(data)                          (0x0000001F&(data))

#define  CODEBLKREG_TOTAL_COEF3                                                  0x1800E01C
#define  CODEBLKREG_TOTAL_COEF3_reg_addr                                         "0xB800E01C"
#define  CODEBLKREG_TOTAL_COEF3_reg                                              0xB800E01C
#define  CODEBLKREG_TOTAL_COEF3_inst_addr                                        "0x0007"
#define  CODEBLKREG_TOTAL_COEF3_inst_adr                                         "0x0007"
#define  CODEBLKREG_TOTAL_COEF3_inst                                             0x0007
#define  set_CODEBLKREG_TOTAL_COEF3_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_TOTAL_COEF3_reg)=data)
#define  get_CODEBLKREG_TOTAL_COEF3_reg                                          (*((volatile unsigned int*)CODEBLKREG_TOTAL_COEF3_reg))
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_d_shift                            (15)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_c_shift                            (10)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_b_shift                            (5)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_a_shift                            (0)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_d_mask                             (0x000F8000)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_c_mask                             (0x00007C00)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_b_mask                             (0x000003E0)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_a_mask                             (0x0000001F)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_d(data)                            (0x000F8000&((data)<<15))
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_c(data)                            (0x00007C00&((data)<<10))
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_b(data)                            (0x000003E0&((data)<<5))
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_a(data)                            (0x0000001F&(data))
#define  CODEBLKREG_TOTAL_COEF3_get_left_bot_luma_d(data)                        ((0x000F8000&(data))>>15)
#define  CODEBLKREG_TOTAL_COEF3_get_left_bot_luma_c(data)                        ((0x00007C00&(data))>>10)
#define  CODEBLKREG_TOTAL_COEF3_get_left_bot_luma_b(data)                        ((0x000003E0&(data))>>5)
#define  CODEBLKREG_TOTAL_COEF3_get_left_bot_luma_a(data)                        (0x0000001F&(data))
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_d_src(data)                        ((0x000F8000&(data))>>15)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_c_src(data)                        ((0x00007C00&(data))>>10)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_b_src(data)                        ((0x000003E0&(data))>>5)
#define  CODEBLKREG_TOTAL_COEF3_left_bot_luma_a_src(data)                        (0x0000001F&(data))

#define  CODEBLKREG_TOTAL_COEF4                                                  0x1800E020
#define  CODEBLKREG_TOTAL_COEF4_reg_addr                                         "0xB800E020"
#define  CODEBLKREG_TOTAL_COEF4_reg                                              0xB800E020
#define  CODEBLKREG_TOTAL_COEF4_inst_addr                                        "0x0008"
#define  CODEBLKREG_TOTAL_COEF4_inst_adr                                         "0x0008"
#define  CODEBLKREG_TOTAL_COEF4_inst                                             0x0008
#define  set_CODEBLKREG_TOTAL_COEF4_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_TOTAL_COEF4_reg)=data)
#define  get_CODEBLKREG_TOTAL_COEF4_reg                                          (*((volatile unsigned int*)CODEBLKREG_TOTAL_COEF4_reg))
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cb_a_shift                              (15)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cb_b_shift                              (10)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cr_a_shift                              (5)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cr_b_shift                              (0)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cb_a_mask                               (0x000F8000)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cb_b_mask                               (0x00007C00)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cr_a_mask                               (0x000003E0)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cr_b_mask                               (0x0000001F)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cb_a(data)                              (0x000F8000&((data)<<15))
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cb_b(data)                              (0x00007C00&((data)<<10))
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cr_a(data)                              (0x000003E0&((data)<<5))
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cr_b(data)                              (0x0000001F&(data))
#define  CODEBLKREG_TOTAL_COEF4_get_left_bot_cb_a(data)                          ((0x000F8000&(data))>>15)
#define  CODEBLKREG_TOTAL_COEF4_get_left_bot_cb_b(data)                          ((0x00007C00&(data))>>10)
#define  CODEBLKREG_TOTAL_COEF4_get_left_bot_cr_a(data)                          ((0x000003E0&(data))>>5)
#define  CODEBLKREG_TOTAL_COEF4_get_left_bot_cr_b(data)                          (0x0000001F&(data))
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cb_a_src(data)                          ((0x000F8000&(data))>>15)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cb_b_src(data)                          ((0x00007C00&(data))>>10)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cr_a_src(data)                          ((0x000003E0&(data))>>5)
#define  CODEBLKREG_TOTAL_COEF4_left_bot_cr_b_src(data)                          (0x0000001F&(data))

#define  CODEBLKREG_VE_AVS_CNTL                                                  0x1800E080
#define  CODEBLKREG_VE_AVS_CNTL_reg_addr                                         "0xB800E080"
#define  CODEBLKREG_VE_AVS_CNTL_reg                                              0xB800E080
#define  CODEBLKREG_VE_AVS_CNTL_inst_addr                                        "0x0009"
#define  CODEBLKREG_VE_AVS_CNTL_inst_adr                                         "0x0020"
#define  CODEBLKREG_VE_AVS_CNTL_inst                                             0x0020
#define  set_CODEBLKREG_VE_AVS_CNTL_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VE_AVS_CNTL_reg)=data)
#define  get_CODEBLKREG_VE_AVS_CNTL_reg                                          (*((volatile unsigned int*)CODEBLKREG_VE_AVS_CNTL_reg))
#define  CODEBLKREG_VE_AVS_CNTL_write_enable8_shift                              (26)
#define  CODEBLKREG_VE_AVS_CNTL_ch_q_param_delta_v_shift                         (20)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable7_shift                              (19)
#define  CODEBLKREG_VE_AVS_CNTL_ch_q_param_delta_u_shift                         (13)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable6_shift                              (12)
#define  CODEBLKREG_VE_AVS_CNTL_pb_fld_enhanced_flg_shift                        (11)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable5_shift                              (10)
#define  CODEBLKREG_VE_AVS_CNTL_frame_pic_type_shift                             (8)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable4_shift                              (7)
#define  CODEBLKREG_VE_AVS_CNTL_skip_mode_flag_shift                             (6)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable3_shift                              (5)
#define  CODEBLKREG_VE_AVS_CNTL_fixedQP_shift                                    (4)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable2_shift                              (3)
#define  CODEBLKREG_VE_AVS_CNTL_mbweightingflg_shift                             (2)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable1_shift                              (1)
#define  CODEBLKREG_VE_AVS_CNTL_pic_ref_flg_shift                                (0)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable8_mask                               (0x04000000)
#define  CODEBLKREG_VE_AVS_CNTL_ch_q_param_delta_v_mask                          (0x03F00000)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable7_mask                               (0x00080000)
#define  CODEBLKREG_VE_AVS_CNTL_ch_q_param_delta_u_mask                          (0x0007E000)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable6_mask                               (0x00001000)
#define  CODEBLKREG_VE_AVS_CNTL_pb_fld_enhanced_flg_mask                         (0x00000800)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable5_mask                               (0x00000400)
#define  CODEBLKREG_VE_AVS_CNTL_frame_pic_type_mask                              (0x00000300)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable4_mask                               (0x00000080)
#define  CODEBLKREG_VE_AVS_CNTL_skip_mode_flag_mask                              (0x00000040)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable3_mask                               (0x00000020)
#define  CODEBLKREG_VE_AVS_CNTL_fixedQP_mask                                     (0x00000010)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable2_mask                               (0x00000008)
#define  CODEBLKREG_VE_AVS_CNTL_mbweightingflg_mask                              (0x00000004)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable1_mask                               (0x00000002)
#define  CODEBLKREG_VE_AVS_CNTL_pic_ref_flg_mask                                 (0x00000001)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable8(data)                              (0x04000000&((data)<<26))
#define  CODEBLKREG_VE_AVS_CNTL_ch_q_param_delta_v(data)                         (0x03F00000&((data)<<20))
#define  CODEBLKREG_VE_AVS_CNTL_write_enable7(data)                              (0x00080000&((data)<<19))
#define  CODEBLKREG_VE_AVS_CNTL_ch_q_param_delta_u(data)                         (0x0007E000&((data)<<13))
#define  CODEBLKREG_VE_AVS_CNTL_write_enable6(data)                              (0x00001000&((data)<<12))
#define  CODEBLKREG_VE_AVS_CNTL_pb_fld_enhanced_flg(data)                        (0x00000800&((data)<<11))
#define  CODEBLKREG_VE_AVS_CNTL_write_enable5(data)                              (0x00000400&((data)<<10))
#define  CODEBLKREG_VE_AVS_CNTL_frame_pic_type(data)                             (0x00000300&((data)<<8))
#define  CODEBLKREG_VE_AVS_CNTL_write_enable4(data)                              (0x00000080&((data)<<7))
#define  CODEBLKREG_VE_AVS_CNTL_skip_mode_flag(data)                             (0x00000040&((data)<<6))
#define  CODEBLKREG_VE_AVS_CNTL_write_enable3(data)                              (0x00000020&((data)<<5))
#define  CODEBLKREG_VE_AVS_CNTL_fixedQP(data)                                    (0x00000010&((data)<<4))
#define  CODEBLKREG_VE_AVS_CNTL_write_enable2(data)                              (0x00000008&((data)<<3))
#define  CODEBLKREG_VE_AVS_CNTL_mbweightingflg(data)                             (0x00000004&((data)<<2))
#define  CODEBLKREG_VE_AVS_CNTL_write_enable1(data)                              (0x00000002&((data)<<1))
#define  CODEBLKREG_VE_AVS_CNTL_pic_ref_flg(data)                                (0x00000001&(data))
#define  CODEBLKREG_VE_AVS_CNTL_get_write_enable8(data)                          ((0x04000000&(data))>>26)
#define  CODEBLKREG_VE_AVS_CNTL_get_ch_q_param_delta_v(data)                     ((0x03F00000&(data))>>20)
#define  CODEBLKREG_VE_AVS_CNTL_get_write_enable7(data)                          ((0x00080000&(data))>>19)
#define  CODEBLKREG_VE_AVS_CNTL_get_ch_q_param_delta_u(data)                     ((0x0007E000&(data))>>13)
#define  CODEBLKREG_VE_AVS_CNTL_get_write_enable6(data)                          ((0x00001000&(data))>>12)
#define  CODEBLKREG_VE_AVS_CNTL_get_pb_fld_enhanced_flg(data)                    ((0x00000800&(data))>>11)
#define  CODEBLKREG_VE_AVS_CNTL_get_write_enable5(data)                          ((0x00000400&(data))>>10)
#define  CODEBLKREG_VE_AVS_CNTL_get_frame_pic_type(data)                         ((0x00000300&(data))>>8)
#define  CODEBLKREG_VE_AVS_CNTL_get_write_enable4(data)                          ((0x00000080&(data))>>7)
#define  CODEBLKREG_VE_AVS_CNTL_get_skip_mode_flag(data)                         ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_AVS_CNTL_get_write_enable3(data)                          ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_AVS_CNTL_get_fixedQP(data)                                ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_AVS_CNTL_get_write_enable2(data)                          ((0x00000008&(data))>>3)
#define  CODEBLKREG_VE_AVS_CNTL_get_mbweightingflg(data)                         ((0x00000004&(data))>>2)
#define  CODEBLKREG_VE_AVS_CNTL_get_write_enable1(data)                          ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_AVS_CNTL_get_pic_ref_flg(data)                            (0x00000001&(data))
#define  CODEBLKREG_VE_AVS_CNTL_write_enable8_src(data)                          ((0x04000000&(data))>>26)
#define  CODEBLKREG_VE_AVS_CNTL_ch_q_param_delta_v_src(data)                     ((0x03F00000&(data))>>20)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable7_src(data)                          ((0x00080000&(data))>>19)
#define  CODEBLKREG_VE_AVS_CNTL_ch_q_param_delta_u_src(data)                     ((0x0007E000&(data))>>13)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable6_src(data)                          ((0x00001000&(data))>>12)
#define  CODEBLKREG_VE_AVS_CNTL_pb_fld_enhanced_flg_src(data)                    ((0x00000800&(data))>>11)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable5_src(data)                          ((0x00000400&(data))>>10)
#define  CODEBLKREG_VE_AVS_CNTL_frame_pic_type_src(data)                         ((0x00000300&(data))>>8)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable4_src(data)                          ((0x00000080&(data))>>7)
#define  CODEBLKREG_VE_AVS_CNTL_skip_mode_flag_src(data)                         ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable3_src(data)                          ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_AVS_CNTL_fixedQP_src(data)                                ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable2_src(data)                          ((0x00000008&(data))>>3)
#define  CODEBLKREG_VE_AVS_CNTL_mbweightingflg_src(data)                         ((0x00000004&(data))>>2)
#define  CODEBLKREG_VE_AVS_CNTL_write_enable1_src(data)                          ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_AVS_CNTL_pic_ref_flg_src(data)                            (0x00000001&(data))

#define  CODEBLKREG_VE_H264_CNTL                                                 0x1800E100
#define  CODEBLKREG_VE_H264_CNTL_reg_addr                                        "0xB800E100"
#define  CODEBLKREG_VE_H264_CNTL_reg                                             0xB800E100
#define  CODEBLKREG_VE_H264_CNTL_inst_addr                                       "0x000A"
#define  CODEBLKREG_VE_H264_CNTL_inst_adr                                        "0x0040"
#define  CODEBLKREG_VE_H264_CNTL_inst                                            0x0040
#define  set_CODEBLKREG_VE_H264_CNTL_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_H264_CNTL_reg)=data)
#define  get_CODEBLKREG_VE_H264_CNTL_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_H264_CNTL_reg))
#define  CODEBLKREG_VE_H264_CNTL_qpprime_y_zero_transform_bypass_flag_shift      (29)
#define  CODEBLKREG_VE_H264_CNTL_entropy_coding_mode_shift                       (28)
#define  CODEBLKREG_VE_H264_CNTL_pic_init_qp_shift                               (22)
#define  CODEBLKREG_VE_H264_CNTL_chroma_qp_offset_shift                          (17)
#define  CODEBLKREG_VE_H264_CNTL_second_chroma_qp_offset_shift                   (12)
#define  CODEBLKREG_VE_H264_CNTL_direct_8x8_inferflg_shift                       (11)
#define  CODEBLKREG_VE_H264_CNTL_transform_8x8_mode_flg_shift                    (10)
#define  CODEBLKREG_VE_H264_CNTL_num_ref_idx_l0_active_minus1_shift              (5)
#define  CODEBLKREG_VE_H264_CNTL_num_ref_idx_l1_active_minus1_shift              (0)
#define  CODEBLKREG_VE_H264_CNTL_qpprime_y_zero_transform_bypass_flag_mask       (0x20000000)
#define  CODEBLKREG_VE_H264_CNTL_entropy_coding_mode_mask                        (0x10000000)
#define  CODEBLKREG_VE_H264_CNTL_pic_init_qp_mask                                (0x0FC00000)
#define  CODEBLKREG_VE_H264_CNTL_chroma_qp_offset_mask                           (0x003E0000)
#define  CODEBLKREG_VE_H264_CNTL_second_chroma_qp_offset_mask                    (0x0001F000)
#define  CODEBLKREG_VE_H264_CNTL_direct_8x8_inferflg_mask                        (0x00000800)
#define  CODEBLKREG_VE_H264_CNTL_transform_8x8_mode_flg_mask                     (0x00000400)
#define  CODEBLKREG_VE_H264_CNTL_num_ref_idx_l0_active_minus1_mask               (0x000003E0)
#define  CODEBLKREG_VE_H264_CNTL_num_ref_idx_l1_active_minus1_mask               (0x0000001F)
#define  CODEBLKREG_VE_H264_CNTL_qpprime_y_zero_transform_bypass_flag(data)      (0x20000000&((data)<<29))
#define  CODEBLKREG_VE_H264_CNTL_entropy_coding_mode(data)                       (0x10000000&((data)<<28))
#define  CODEBLKREG_VE_H264_CNTL_pic_init_qp(data)                               (0x0FC00000&((data)<<22))
#define  CODEBLKREG_VE_H264_CNTL_chroma_qp_offset(data)                          (0x003E0000&((data)<<17))
#define  CODEBLKREG_VE_H264_CNTL_second_chroma_qp_offset(data)                   (0x0001F000&((data)<<12))
#define  CODEBLKREG_VE_H264_CNTL_direct_8x8_inferflg(data)                       (0x00000800&((data)<<11))
#define  CODEBLKREG_VE_H264_CNTL_transform_8x8_mode_flg(data)                    (0x00000400&((data)<<10))
#define  CODEBLKREG_VE_H264_CNTL_num_ref_idx_l0_active_minus1(data)              (0x000003E0&((data)<<5))
#define  CODEBLKREG_VE_H264_CNTL_num_ref_idx_l1_active_minus1(data)              (0x0000001F&(data))
#define  CODEBLKREG_VE_H264_CNTL_get_qpprime_y_zero_transform_bypass_flag(data)  ((0x20000000&(data))>>29)
#define  CODEBLKREG_VE_H264_CNTL_get_entropy_coding_mode(data)                   ((0x10000000&(data))>>28)
#define  CODEBLKREG_VE_H264_CNTL_get_pic_init_qp(data)                           ((0x0FC00000&(data))>>22)
#define  CODEBLKREG_VE_H264_CNTL_get_chroma_qp_offset(data)                      ((0x003E0000&(data))>>17)
#define  CODEBLKREG_VE_H264_CNTL_get_second_chroma_qp_offset(data)               ((0x0001F000&(data))>>12)
#define  CODEBLKREG_VE_H264_CNTL_get_direct_8x8_inferflg(data)                   ((0x00000800&(data))>>11)
#define  CODEBLKREG_VE_H264_CNTL_get_transform_8x8_mode_flg(data)                ((0x00000400&(data))>>10)
#define  CODEBLKREG_VE_H264_CNTL_get_num_ref_idx_l0_active_minus1(data)          ((0x000003E0&(data))>>5)
#define  CODEBLKREG_VE_H264_CNTL_get_num_ref_idx_l1_active_minus1(data)          (0x0000001F&(data))
#define  CODEBLKREG_VE_H264_CNTL_qpprime_y_zero_transform_bypass_flag_src(data)  ((0x20000000&(data))>>29)
#define  CODEBLKREG_VE_H264_CNTL_entropy_coding_mode_src(data)                   ((0x10000000&(data))>>28)
#define  CODEBLKREG_VE_H264_CNTL_pic_init_qp_src(data)                           ((0x0FC00000&(data))>>22)
#define  CODEBLKREG_VE_H264_CNTL_chroma_qp_offset_src(data)                      ((0x003E0000&(data))>>17)
#define  CODEBLKREG_VE_H264_CNTL_second_chroma_qp_offset_src(data)               ((0x0001F000&(data))>>12)
#define  CODEBLKREG_VE_H264_CNTL_direct_8x8_inferflg_src(data)                   ((0x00000800&(data))>>11)
#define  CODEBLKREG_VE_H264_CNTL_transform_8x8_mode_flg_src(data)                ((0x00000400&(data))>>10)
#define  CODEBLKREG_VE_H264_CNTL_num_ref_idx_l0_active_minus1_src(data)          ((0x000003E0&(data))>>5)
#define  CODEBLKREG_VE_H264_CNTL_num_ref_idx_l1_active_minus1_src(data)          (0x0000001F&(data))

#define  CODEBLKREG_VE_H264_CNTL2                                                0x1800E104
#define  CODEBLKREG_VE_H264_CNTL2_reg_addr                                       "0xB800E104"
#define  CODEBLKREG_VE_H264_CNTL2_reg                                            0xB800E104
#define  CODEBLKREG_VE_H264_CNTL2_inst_addr                                      "0x000B"
#define  CODEBLKREG_VE_H264_CNTL2_inst_adr                                       "0x0041"
#define  CODEBLKREG_VE_H264_CNTL2_inst                                           0x0041
#define  set_CODEBLKREG_VE_H264_CNTL2_reg(data)                                  (*((volatile unsigned int*)CODEBLKREG_VE_H264_CNTL2_reg)=data)
#define  get_CODEBLKREG_VE_H264_CNTL2_reg                                        (*((volatile unsigned int*)CODEBLKREG_VE_H264_CNTL2_reg))
#define  CODEBLKREG_VE_H264_CNTL2_write_enable3_shift                            (14)
#define  CODEBLKREG_VE_H264_CNTL2_pic_type_shift                                 (11)
#define  CODEBLKREG_VE_H264_CNTL2_write_enable2_shift                            (10)
#define  CODEBLKREG_VE_H264_CNTL2_slice_qp_delta_shift                           (3)
#define  CODEBLKREG_VE_H264_CNTL2_write_enable1_shift                            (2)
#define  CODEBLKREG_VE_H264_CNTL2_cabac_init_idc_shift                           (0)
#define  CODEBLKREG_VE_H264_CNTL2_write_enable3_mask                             (0x00004000)
#define  CODEBLKREG_VE_H264_CNTL2_pic_type_mask                                  (0x00003800)
#define  CODEBLKREG_VE_H264_CNTL2_write_enable2_mask                             (0x00000400)
#define  CODEBLKREG_VE_H264_CNTL2_slice_qp_delta_mask                            (0x000003F8)
#define  CODEBLKREG_VE_H264_CNTL2_write_enable1_mask                             (0x00000004)
#define  CODEBLKREG_VE_H264_CNTL2_cabac_init_idc_mask                            (0x00000003)
#define  CODEBLKREG_VE_H264_CNTL2_write_enable3(data)                            (0x00004000&((data)<<14))
#define  CODEBLKREG_VE_H264_CNTL2_pic_type(data)                                 (0x00003800&((data)<<11))
#define  CODEBLKREG_VE_H264_CNTL2_write_enable2(data)                            (0x00000400&((data)<<10))
#define  CODEBLKREG_VE_H264_CNTL2_slice_qp_delta(data)                           (0x000003F8&((data)<<3))
#define  CODEBLKREG_VE_H264_CNTL2_write_enable1(data)                            (0x00000004&((data)<<2))
#define  CODEBLKREG_VE_H264_CNTL2_cabac_init_idc(data)                           (0x00000003&(data))
#define  CODEBLKREG_VE_H264_CNTL2_get_write_enable3(data)                        ((0x00004000&(data))>>14)
#define  CODEBLKREG_VE_H264_CNTL2_get_pic_type(data)                             ((0x00003800&(data))>>11)
#define  CODEBLKREG_VE_H264_CNTL2_get_write_enable2(data)                        ((0x00000400&(data))>>10)
#define  CODEBLKREG_VE_H264_CNTL2_get_slice_qp_delta(data)                       ((0x000003F8&(data))>>3)
#define  CODEBLKREG_VE_H264_CNTL2_get_write_enable1(data)                        ((0x00000004&(data))>>2)
#define  CODEBLKREG_VE_H264_CNTL2_get_cabac_init_idc(data)                       (0x00000003&(data))
#define  CODEBLKREG_VE_H264_CNTL2_write_enable3_src(data)                        ((0x00004000&(data))>>14)
#define  CODEBLKREG_VE_H264_CNTL2_pic_type_src(data)                             ((0x00003800&(data))>>11)
#define  CODEBLKREG_VE_H264_CNTL2_write_enable2_src(data)                        ((0x00000400&(data))>>10)
#define  CODEBLKREG_VE_H264_CNTL2_slice_qp_delta_src(data)                       ((0x000003F8&(data))>>3)
#define  CODEBLKREG_VE_H264_CNTL2_write_enable1_src(data)                        ((0x00000004&(data))>>2)
#define  CODEBLKREG_VE_H264_CNTL2_cabac_init_idc_src(data)                       (0x00000003&(data))

#define  CODEBLKREG_VE_VC1QUANT                                                  0x1800E108
#define  CODEBLKREG_VE_VC1QUANT_reg_addr                                         "0xB800E108"
#define  CODEBLKREG_VE_VC1QUANT_reg                                              0xB800E108
#define  CODEBLKREG_VE_VC1QUANT_inst_addr                                        "0x000C"
#define  CODEBLKREG_VE_VC1QUANT_inst_adr                                         "0x0042"
#define  CODEBLKREG_VE_VC1QUANT_inst                                             0x0042
#define  set_CODEBLKREG_VE_VC1QUANT_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VE_VC1QUANT_reg)=data)
#define  get_CODEBLKREG_VE_VC1QUANT_reg                                          (*((volatile unsigned int*)CODEBLKREG_VE_VC1QUANT_reg))
#define  CODEBLKREG_VE_VC1QUANT_write_enable8_shift                              (25)
#define  CODEBLKREG_VE_VC1QUANT_quan_type_shift                                  (24)
#define  CODEBLKREG_VE_VC1QUANT_write_enable7_shift                              (23)
#define  CODEBLKREG_VE_VC1QUANT_dquant_shift                                     (21)
#define  CODEBLKREG_VE_VC1QUANT_write_enable6_shift                              (20)
#define  CODEBLKREG_VE_VC1QUANT_pqindex_shift                                    (15)
#define  CODEBLKREG_VE_VC1QUANT_write_enable5_shift                              (14)
#define  CODEBLKREG_VE_VC1QUANT_halfqp_shift                                     (13)
#define  CODEBLKREG_VE_VC1QUANT_write_enable4_shift                              (12)
#define  CODEBLKREG_VE_VC1QUANT_altpquant_shift                                  (7)
#define  CODEBLKREG_VE_VC1QUANT_write_enable3_shift                              (6)
#define  CODEBLKREG_VE_VC1QUANT_dquantfrm_shift                                  (5)
#define  CODEBLKREG_VE_VC1QUANT_write_enable2_shift                              (4)
#define  CODEBLKREG_VE_VC1QUANT_dqprofile_shift                                  (2)
#define  CODEBLKREG_VE_VC1QUANT_write_enable1_shift                              (1)
#define  CODEBLKREG_VE_VC1QUANT_dqbilevel_shift                                  (0)
#define  CODEBLKREG_VE_VC1QUANT_write_enable8_mask                               (0x02000000)
#define  CODEBLKREG_VE_VC1QUANT_quan_type_mask                                   (0x01000000)
#define  CODEBLKREG_VE_VC1QUANT_write_enable7_mask                               (0x00800000)
#define  CODEBLKREG_VE_VC1QUANT_dquant_mask                                      (0x00600000)
#define  CODEBLKREG_VE_VC1QUANT_write_enable6_mask                               (0x00100000)
#define  CODEBLKREG_VE_VC1QUANT_pqindex_mask                                     (0x000F8000)
#define  CODEBLKREG_VE_VC1QUANT_write_enable5_mask                               (0x00004000)
#define  CODEBLKREG_VE_VC1QUANT_halfqp_mask                                      (0x00002000)
#define  CODEBLKREG_VE_VC1QUANT_write_enable4_mask                               (0x00001000)
#define  CODEBLKREG_VE_VC1QUANT_altpquant_mask                                   (0x00000F80)
#define  CODEBLKREG_VE_VC1QUANT_write_enable3_mask                               (0x00000040)
#define  CODEBLKREG_VE_VC1QUANT_dquantfrm_mask                                   (0x00000020)
#define  CODEBLKREG_VE_VC1QUANT_write_enable2_mask                               (0x00000010)
#define  CODEBLKREG_VE_VC1QUANT_dqprofile_mask                                   (0x0000000C)
#define  CODEBLKREG_VE_VC1QUANT_write_enable1_mask                               (0x00000002)
#define  CODEBLKREG_VE_VC1QUANT_dqbilevel_mask                                   (0x00000001)
#define  CODEBLKREG_VE_VC1QUANT_write_enable8(data)                              (0x02000000&((data)<<25))
#define  CODEBLKREG_VE_VC1QUANT_quan_type(data)                                  (0x01000000&((data)<<24))
#define  CODEBLKREG_VE_VC1QUANT_write_enable7(data)                              (0x00800000&((data)<<23))
#define  CODEBLKREG_VE_VC1QUANT_dquant(data)                                     (0x00600000&((data)<<21))
#define  CODEBLKREG_VE_VC1QUANT_write_enable6(data)                              (0x00100000&((data)<<20))
#define  CODEBLKREG_VE_VC1QUANT_pqindex(data)                                    (0x000F8000&((data)<<15))
#define  CODEBLKREG_VE_VC1QUANT_write_enable5(data)                              (0x00004000&((data)<<14))
#define  CODEBLKREG_VE_VC1QUANT_halfqp(data)                                     (0x00002000&((data)<<13))
#define  CODEBLKREG_VE_VC1QUANT_write_enable4(data)                              (0x00001000&((data)<<12))
#define  CODEBLKREG_VE_VC1QUANT_altpquant(data)                                  (0x00000F80&((data)<<7))
#define  CODEBLKREG_VE_VC1QUANT_write_enable3(data)                              (0x00000040&((data)<<6))
#define  CODEBLKREG_VE_VC1QUANT_dquantfrm(data)                                  (0x00000020&((data)<<5))
#define  CODEBLKREG_VE_VC1QUANT_write_enable2(data)                              (0x00000010&((data)<<4))
#define  CODEBLKREG_VE_VC1QUANT_dqprofile(data)                                  (0x0000000C&((data)<<2))
#define  CODEBLKREG_VE_VC1QUANT_write_enable1(data)                              (0x00000002&((data)<<1))
#define  CODEBLKREG_VE_VC1QUANT_dqbilevel(data)                                  (0x00000001&(data))
#define  CODEBLKREG_VE_VC1QUANT_get_write_enable8(data)                          ((0x02000000&(data))>>25)
#define  CODEBLKREG_VE_VC1QUANT_get_quan_type(data)                              ((0x01000000&(data))>>24)
#define  CODEBLKREG_VE_VC1QUANT_get_write_enable7(data)                          ((0x00800000&(data))>>23)
#define  CODEBLKREG_VE_VC1QUANT_get_dquant(data)                                 ((0x00600000&(data))>>21)
#define  CODEBLKREG_VE_VC1QUANT_get_write_enable6(data)                          ((0x00100000&(data))>>20)
#define  CODEBLKREG_VE_VC1QUANT_get_pqindex(data)                                ((0x000F8000&(data))>>15)
#define  CODEBLKREG_VE_VC1QUANT_get_write_enable5(data)                          ((0x00004000&(data))>>14)
#define  CODEBLKREG_VE_VC1QUANT_get_halfqp(data)                                 ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_VC1QUANT_get_write_enable4(data)                          ((0x00001000&(data))>>12)
#define  CODEBLKREG_VE_VC1QUANT_get_altpquant(data)                              ((0x00000F80&(data))>>7)
#define  CODEBLKREG_VE_VC1QUANT_get_write_enable3(data)                          ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_VC1QUANT_get_dquantfrm(data)                              ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_VC1QUANT_get_write_enable2(data)                          ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_VC1QUANT_get_dqprofile(data)                              ((0x0000000C&(data))>>2)
#define  CODEBLKREG_VE_VC1QUANT_get_write_enable1(data)                          ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_VC1QUANT_get_dqbilevel(data)                              (0x00000001&(data))
#define  CODEBLKREG_VE_VC1QUANT_write_enable8_src(data)                          ((0x02000000&(data))>>25)
#define  CODEBLKREG_VE_VC1QUANT_quan_type_src(data)                              ((0x01000000&(data))>>24)
#define  CODEBLKREG_VE_VC1QUANT_write_enable7_src(data)                          ((0x00800000&(data))>>23)
#define  CODEBLKREG_VE_VC1QUANT_dquant_src(data)                                 ((0x00600000&(data))>>21)
#define  CODEBLKREG_VE_VC1QUANT_write_enable6_src(data)                          ((0x00100000&(data))>>20)
#define  CODEBLKREG_VE_VC1QUANT_pqindex_src(data)                                ((0x000F8000&(data))>>15)
#define  CODEBLKREG_VE_VC1QUANT_write_enable5_src(data)                          ((0x00004000&(data))>>14)
#define  CODEBLKREG_VE_VC1QUANT_halfqp_src(data)                                 ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_VC1QUANT_write_enable4_src(data)                          ((0x00001000&(data))>>12)
#define  CODEBLKREG_VE_VC1QUANT_altpquant_src(data)                              ((0x00000F80&(data))>>7)
#define  CODEBLKREG_VE_VC1QUANT_write_enable3_src(data)                          ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_VC1QUANT_dquantfrm_src(data)                              ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_VC1QUANT_write_enable2_src(data)                          ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_VC1QUANT_dqprofile_src(data)                              ((0x0000000C&(data))>>2)
#define  CODEBLKREG_VE_VC1QUANT_write_enable1_src(data)                          ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_VC1QUANT_dqbilevel_src(data)                              (0x00000001&(data))

#define  CODEBLKREG_VE_VC1TRANSFORM                                              0x1800E10C
#define  CODEBLKREG_VE_VC1TRANSFORM_reg_addr                                     "0xB800E10C"
#define  CODEBLKREG_VE_VC1TRANSFORM_reg                                          0xB800E10C
#define  CODEBLKREG_VE_VC1TRANSFORM_inst_addr                                    "0x000D"
#define  CODEBLKREG_VE_VC1TRANSFORM_inst_adr                                     "0x0043"
#define  CODEBLKREG_VE_VC1TRANSFORM_inst                                         0x0043
#define  set_CODEBLKREG_VE_VC1TRANSFORM_reg(data)                                (*((volatile unsigned int*)CODEBLKREG_VE_VC1TRANSFORM_reg)=data)
#define  get_CODEBLKREG_VE_VC1TRANSFORM_reg                                      (*((volatile unsigned int*)CODEBLKREG_VE_VC1TRANSFORM_reg))
#define  CODEBLKREG_VE_VC1TRANSFORM_ttmbf_shift                                  (0)
#define  CODEBLKREG_VE_VC1TRANSFORM_ttmbf_mask                                   (0x00000001)
#define  CODEBLKREG_VE_VC1TRANSFORM_ttmbf(data)                                  (0x00000001&(data))
#define  CODEBLKREG_VE_VC1TRANSFORM_get_ttmbf(data)                              (0x00000001&(data))
#define  CODEBLKREG_VE_VC1TRANSFORM_ttmbf_src(data)                              (0x00000001&(data))

#define  CODEBLKREG_VE_VC1MV                                                     0x1800E110
#define  CODEBLKREG_VE_VC1MV_reg_addr                                            "0xB800E110"
#define  CODEBLKREG_VE_VC1MV_reg                                                 0xB800E110
#define  CODEBLKREG_VE_VC1MV_inst_addr                                           "0x000E"
#define  CODEBLKREG_VE_VC1MV_inst_adr                                            "0x0044"
#define  CODEBLKREG_VE_VC1MV_inst                                                0x0044
#define  set_CODEBLKREG_VE_VC1MV_reg(data)                                       (*((volatile unsigned int*)CODEBLKREG_VE_VC1MV_reg)=data)
#define  get_CODEBLKREG_VE_VC1MV_reg                                             (*((volatile unsigned int*)CODEBLKREG_VE_VC1MV_reg))
#define  CODEBLKREG_VE_VC1MV_write_enable5_shift                                 (26)
#define  CODEBLKREG_VE_VC1MV_vc1mvtab_shift                                      (23)
#define  CODEBLKREG_VE_VC1MV_write_enable4_shift                                 (22)
#define  CODEBLKREG_VE_VC1MV_mvrange_kx_shift                                    (18)
#define  CODEBLKREG_VE_VC1MV_mvrange_ky_shift                                    (14)
#define  CODEBLKREG_VE_VC1MV_write_enable3_shift                                 (13)
#define  CODEBLKREG_VE_VC1MV_dmv_extend_x_shift                                  (12)
#define  CODEBLKREG_VE_VC1MV_dmv_extend_y_shift                                  (11)
#define  CODEBLKREG_VE_VC1MV_write_enable2_shift                                 (10)
#define  CODEBLKREG_VE_VC1MV_tab2mvbp_shift                                      (8)
#define  CODEBLKREG_VE_VC1MV_tab4mvbp_shift                                      (6)
#define  CODEBLKREG_VE_VC1MV_write_enable1_shift                                 (5)
#define  CODEBLKREG_VE_VC1MV_bfraction_shift                                     (0)
#define  CODEBLKREG_VE_VC1MV_write_enable5_mask                                  (0x04000000)
#define  CODEBLKREG_VE_VC1MV_vc1mvtab_mask                                       (0x03800000)
#define  CODEBLKREG_VE_VC1MV_write_enable4_mask                                  (0x00400000)
#define  CODEBLKREG_VE_VC1MV_mvrange_kx_mask                                     (0x003C0000)
#define  CODEBLKREG_VE_VC1MV_mvrange_ky_mask                                     (0x0003C000)
#define  CODEBLKREG_VE_VC1MV_write_enable3_mask                                  (0x00002000)
#define  CODEBLKREG_VE_VC1MV_dmv_extend_x_mask                                   (0x00001000)
#define  CODEBLKREG_VE_VC1MV_dmv_extend_y_mask                                   (0x00000800)
#define  CODEBLKREG_VE_VC1MV_write_enable2_mask                                  (0x00000400)
#define  CODEBLKREG_VE_VC1MV_tab2mvbp_mask                                       (0x00000300)
#define  CODEBLKREG_VE_VC1MV_tab4mvbp_mask                                       (0x000000C0)
#define  CODEBLKREG_VE_VC1MV_write_enable1_mask                                  (0x00000020)
#define  CODEBLKREG_VE_VC1MV_bfraction_mask                                      (0x0000001F)
#define  CODEBLKREG_VE_VC1MV_write_enable5(data)                                 (0x04000000&((data)<<26))
#define  CODEBLKREG_VE_VC1MV_vc1mvtab(data)                                      (0x03800000&((data)<<23))
#define  CODEBLKREG_VE_VC1MV_write_enable4(data)                                 (0x00400000&((data)<<22))
#define  CODEBLKREG_VE_VC1MV_mvrange_kx(data)                                    (0x003C0000&((data)<<18))
#define  CODEBLKREG_VE_VC1MV_mvrange_ky(data)                                    (0x0003C000&((data)<<14))
#define  CODEBLKREG_VE_VC1MV_write_enable3(data)                                 (0x00002000&((data)<<13))
#define  CODEBLKREG_VE_VC1MV_dmv_extend_x(data)                                  (0x00001000&((data)<<12))
#define  CODEBLKREG_VE_VC1MV_dmv_extend_y(data)                                  (0x00000800&((data)<<11))
#define  CODEBLKREG_VE_VC1MV_write_enable2(data)                                 (0x00000400&((data)<<10))
#define  CODEBLKREG_VE_VC1MV_tab2mvbp(data)                                      (0x00000300&((data)<<8))
#define  CODEBLKREG_VE_VC1MV_tab4mvbp(data)                                      (0x000000C0&((data)<<6))
#define  CODEBLKREG_VE_VC1MV_write_enable1(data)                                 (0x00000020&((data)<<5))
#define  CODEBLKREG_VE_VC1MV_bfraction(data)                                     (0x0000001F&(data))
#define  CODEBLKREG_VE_VC1MV_get_write_enable5(data)                             ((0x04000000&(data))>>26)
#define  CODEBLKREG_VE_VC1MV_get_vc1mvtab(data)                                  ((0x03800000&(data))>>23)
#define  CODEBLKREG_VE_VC1MV_get_write_enable4(data)                             ((0x00400000&(data))>>22)
#define  CODEBLKREG_VE_VC1MV_get_mvrange_kx(data)                                ((0x003C0000&(data))>>18)
#define  CODEBLKREG_VE_VC1MV_get_mvrange_ky(data)                                ((0x0003C000&(data))>>14)
#define  CODEBLKREG_VE_VC1MV_get_write_enable3(data)                             ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_VC1MV_get_dmv_extend_x(data)                              ((0x00001000&(data))>>12)
#define  CODEBLKREG_VE_VC1MV_get_dmv_extend_y(data)                              ((0x00000800&(data))>>11)
#define  CODEBLKREG_VE_VC1MV_get_write_enable2(data)                             ((0x00000400&(data))>>10)
#define  CODEBLKREG_VE_VC1MV_get_tab2mvbp(data)                                  ((0x00000300&(data))>>8)
#define  CODEBLKREG_VE_VC1MV_get_tab4mvbp(data)                                  ((0x000000C0&(data))>>6)
#define  CODEBLKREG_VE_VC1MV_get_write_enable1(data)                             ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_VC1MV_get_bfraction(data)                                 (0x0000001F&(data))
#define  CODEBLKREG_VE_VC1MV_write_enable5_src(data)                             ((0x04000000&(data))>>26)
#define  CODEBLKREG_VE_VC1MV_vc1mvtab_src(data)                                  ((0x03800000&(data))>>23)
#define  CODEBLKREG_VE_VC1MV_write_enable4_src(data)                             ((0x00400000&(data))>>22)
#define  CODEBLKREG_VE_VC1MV_mvrange_kx_src(data)                                ((0x003C0000&(data))>>18)
#define  CODEBLKREG_VE_VC1MV_mvrange_ky_src(data)                                ((0x0003C000&(data))>>14)
#define  CODEBLKREG_VE_VC1MV_write_enable3_src(data)                             ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_VC1MV_dmv_extend_x_src(data)                              ((0x00001000&(data))>>12)
#define  CODEBLKREG_VE_VC1MV_dmv_extend_y_src(data)                              ((0x00000800&(data))>>11)
#define  CODEBLKREG_VE_VC1MV_write_enable2_src(data)                             ((0x00000400&(data))>>10)
#define  CODEBLKREG_VE_VC1MV_tab2mvbp_src(data)                                  ((0x00000300&(data))>>8)
#define  CODEBLKREG_VE_VC1MV_tab4mvbp_src(data)                                  ((0x000000C0&(data))>>6)
#define  CODEBLKREG_VE_VC1MV_write_enable1_src(data)                             ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_VC1MV_bfraction_src(data)                                 (0x0000001F&(data))

#define  CODEBLKREG_VE_MVFCODE                                                   0x1800E114
#define  CODEBLKREG_VE_MVFCODE_reg_addr                                          "0xB800E114"
#define  CODEBLKREG_VE_MVFCODE_reg                                               0xB800E114
#define  CODEBLKREG_VE_MVFCODE_inst_addr                                         "0x000F"
#define  CODEBLKREG_VE_MVFCODE_inst_adr                                          "0x0045"
#define  CODEBLKREG_VE_MVFCODE_inst                                              0x0045
#define  set_CODEBLKREG_VE_MVFCODE_reg(data)                                     (*((volatile unsigned int*)CODEBLKREG_VE_MVFCODE_reg)=data)
#define  get_CODEBLKREG_VE_MVFCODE_reg                                           (*((volatile unsigned int*)CODEBLKREG_VE_MVFCODE_reg))
#define  CODEBLKREG_VE_MVFCODE_write_enable6_shift                               (17)
#define  CODEBLKREG_VE_MVFCODE_bk_x_fcode_shift                                  (13)
#define  CODEBLKREG_VE_MVFCODE_bk_y_fcode_shift                                  (9)
#define  CODEBLKREG_VE_MVFCODE_write_enable5_shift                               (8)
#define  CODEBLKREG_VE_MVFCODE_fo_x_fcode_shift                                  (4)
#define  CODEBLKREG_VE_MVFCODE_fo_y_fcode_shift                                  (0)
#define  CODEBLKREG_VE_MVFCODE_write_enable6_mask                                (0x00020000)
#define  CODEBLKREG_VE_MVFCODE_bk_x_fcode_mask                                   (0x0001E000)
#define  CODEBLKREG_VE_MVFCODE_bk_y_fcode_mask                                   (0x00001E00)
#define  CODEBLKREG_VE_MVFCODE_write_enable5_mask                                (0x00000100)
#define  CODEBLKREG_VE_MVFCODE_fo_x_fcode_mask                                   (0x000000F0)
#define  CODEBLKREG_VE_MVFCODE_fo_y_fcode_mask                                   (0x0000000F)
#define  CODEBLKREG_VE_MVFCODE_write_enable6(data)                               (0x00020000&((data)<<17))
#define  CODEBLKREG_VE_MVFCODE_bk_x_fcode(data)                                  (0x0001E000&((data)<<13))
#define  CODEBLKREG_VE_MVFCODE_bk_y_fcode(data)                                  (0x00001E00&((data)<<9))
#define  CODEBLKREG_VE_MVFCODE_write_enable5(data)                               (0x00000100&((data)<<8))
#define  CODEBLKREG_VE_MVFCODE_fo_x_fcode(data)                                  (0x000000F0&((data)<<4))
#define  CODEBLKREG_VE_MVFCODE_fo_y_fcode(data)                                  (0x0000000F&(data))
#define  CODEBLKREG_VE_MVFCODE_get_write_enable6(data)                           ((0x00020000&(data))>>17)
#define  CODEBLKREG_VE_MVFCODE_get_bk_x_fcode(data)                              ((0x0001E000&(data))>>13)
#define  CODEBLKREG_VE_MVFCODE_get_bk_y_fcode(data)                              ((0x00001E00&(data))>>9)
#define  CODEBLKREG_VE_MVFCODE_get_write_enable5(data)                           ((0x00000100&(data))>>8)
#define  CODEBLKREG_VE_MVFCODE_get_fo_x_fcode(data)                              ((0x000000F0&(data))>>4)
#define  CODEBLKREG_VE_MVFCODE_get_fo_y_fcode(data)                              (0x0000000F&(data))
#define  CODEBLKREG_VE_MVFCODE_write_enable6_src(data)                           ((0x00020000&(data))>>17)
#define  CODEBLKREG_VE_MVFCODE_bk_x_fcode_src(data)                              ((0x0001E000&(data))>>13)
#define  CODEBLKREG_VE_MVFCODE_bk_y_fcode_src(data)                              ((0x00001E00&(data))>>9)
#define  CODEBLKREG_VE_MVFCODE_write_enable5_src(data)                           ((0x00000100&(data))>>8)
#define  CODEBLKREG_VE_MVFCODE_fo_x_fcode_src(data)                              ((0x000000F0&(data))>>4)
#define  CODEBLKREG_VE_MVFCODE_fo_y_fcode_src(data)                              (0x0000000F&(data))

#define  CODEBLKREG_VE_VC1TABLE                                                  0x1800E118
#define  CODEBLKREG_VE_VC1TABLE_reg_addr                                         "0xB800E118"
#define  CODEBLKREG_VE_VC1TABLE_reg                                              0xB800E118
#define  CODEBLKREG_VE_VC1TABLE_inst_addr                                        "0x0010"
#define  CODEBLKREG_VE_VC1TABLE_inst_adr                                         "0x0046"
#define  CODEBLKREG_VE_VC1TABLE_inst                                             0x0046
#define  set_CODEBLKREG_VE_VC1TABLE_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VE_VC1TABLE_reg)=data)
#define  get_CODEBLKREG_VE_VC1TABLE_reg                                          (*((volatile unsigned int*)CODEBLKREG_VE_VC1TABLE_reg))
#define  CODEBLKREG_VE_VC1TABLE_write_enable5_shift                              (16)
#define  CODEBLKREG_VE_VC1TABLE_dctable_sel_shift                                (15)
#define  CODEBLKREG_VE_VC1TABLE_write_enable4_shift                              (14)
#define  CODEBLKREG_VE_VC1TABLE_transacfrm_shift                                 (12)
#define  CODEBLKREG_VE_VC1TABLE_transacfrm2_shift                                (10)
#define  CODEBLKREG_VE_VC1TABLE_write_enable3_shift                              (9)
#define  CODEBLKREG_VE_VC1TABLE_cbp_table_shift                                  (6)
#define  CODEBLKREG_VE_VC1TABLE_write_enable2_shift                              (5)
#define  CODEBLKREG_VE_VC1TABLE_flg_4mvswitch_shift                              (4)
#define  CODEBLKREG_VE_VC1TABLE_write_enable1_shift                              (3)
#define  CODEBLKREG_VE_VC1TABLE_mbmodetab_shift                                  (0)
#define  CODEBLKREG_VE_VC1TABLE_write_enable5_mask                               (0x00010000)
#define  CODEBLKREG_VE_VC1TABLE_dctable_sel_mask                                 (0x00008000)
#define  CODEBLKREG_VE_VC1TABLE_write_enable4_mask                               (0x00004000)
#define  CODEBLKREG_VE_VC1TABLE_transacfrm_mask                                  (0x00003000)
#define  CODEBLKREG_VE_VC1TABLE_transacfrm2_mask                                 (0x00000C00)
#define  CODEBLKREG_VE_VC1TABLE_write_enable3_mask                               (0x00000200)
#define  CODEBLKREG_VE_VC1TABLE_cbp_table_mask                                   (0x000001C0)
#define  CODEBLKREG_VE_VC1TABLE_write_enable2_mask                               (0x00000020)
#define  CODEBLKREG_VE_VC1TABLE_flg_4mvswitch_mask                               (0x00000010)
#define  CODEBLKREG_VE_VC1TABLE_write_enable1_mask                               (0x00000008)
#define  CODEBLKREG_VE_VC1TABLE_mbmodetab_mask                                   (0x00000007)
#define  CODEBLKREG_VE_VC1TABLE_write_enable5(data)                              (0x00010000&((data)<<16))
#define  CODEBLKREG_VE_VC1TABLE_dctable_sel(data)                                (0x00008000&((data)<<15))
#define  CODEBLKREG_VE_VC1TABLE_write_enable4(data)                              (0x00004000&((data)<<14))
#define  CODEBLKREG_VE_VC1TABLE_transacfrm(data)                                 (0x00003000&((data)<<12))
#define  CODEBLKREG_VE_VC1TABLE_transacfrm2(data)                                (0x00000C00&((data)<<10))
#define  CODEBLKREG_VE_VC1TABLE_write_enable3(data)                              (0x00000200&((data)<<9))
#define  CODEBLKREG_VE_VC1TABLE_cbp_table(data)                                  (0x000001C0&((data)<<6))
#define  CODEBLKREG_VE_VC1TABLE_write_enable2(data)                              (0x00000020&((data)<<5))
#define  CODEBLKREG_VE_VC1TABLE_flg_4mvswitch(data)                              (0x00000010&((data)<<4))
#define  CODEBLKREG_VE_VC1TABLE_write_enable1(data)                              (0x00000008&((data)<<3))
#define  CODEBLKREG_VE_VC1TABLE_mbmodetab(data)                                  (0x00000007&(data))
#define  CODEBLKREG_VE_VC1TABLE_get_write_enable5(data)                          ((0x00010000&(data))>>16)
#define  CODEBLKREG_VE_VC1TABLE_get_dctable_sel(data)                            ((0x00008000&(data))>>15)
#define  CODEBLKREG_VE_VC1TABLE_get_write_enable4(data)                          ((0x00004000&(data))>>14)
#define  CODEBLKREG_VE_VC1TABLE_get_transacfrm(data)                             ((0x00003000&(data))>>12)
#define  CODEBLKREG_VE_VC1TABLE_get_transacfrm2(data)                            ((0x00000C00&(data))>>10)
#define  CODEBLKREG_VE_VC1TABLE_get_write_enable3(data)                          ((0x00000200&(data))>>9)
#define  CODEBLKREG_VE_VC1TABLE_get_cbp_table(data)                              ((0x000001C0&(data))>>6)
#define  CODEBLKREG_VE_VC1TABLE_get_write_enable2(data)                          ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_VC1TABLE_get_flg_4mvswitch(data)                          ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_VC1TABLE_get_write_enable1(data)                          ((0x00000008&(data))>>3)
#define  CODEBLKREG_VE_VC1TABLE_get_mbmodetab(data)                              (0x00000007&(data))
#define  CODEBLKREG_VE_VC1TABLE_write_enable5_src(data)                          ((0x00010000&(data))>>16)
#define  CODEBLKREG_VE_VC1TABLE_dctable_sel_src(data)                            ((0x00008000&(data))>>15)
#define  CODEBLKREG_VE_VC1TABLE_write_enable4_src(data)                          ((0x00004000&(data))>>14)
#define  CODEBLKREG_VE_VC1TABLE_transacfrm_src(data)                             ((0x00003000&(data))>>12)
#define  CODEBLKREG_VE_VC1TABLE_transacfrm2_src(data)                            ((0x00000C00&(data))>>10)
#define  CODEBLKREG_VE_VC1TABLE_write_enable3_src(data)                          ((0x00000200&(data))>>9)
#define  CODEBLKREG_VE_VC1TABLE_cbp_table_src(data)                              ((0x000001C0&(data))>>6)
#define  CODEBLKREG_VE_VC1TABLE_write_enable2_src(data)                          ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_VC1TABLE_flg_4mvswitch_src(data)                          ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_VC1TABLE_write_enable1_src(data)                          ((0x00000008&(data))>>3)
#define  CODEBLKREG_VE_VC1TABLE_mbmodetab_src(data)                              (0x00000007&(data))

#define  CODEBLKREG_VE_VC1ESC                                                    0x1800E11C
#define  CODEBLKREG_VE_VC1ESC_reg_addr                                           "0xB800E11C"
#define  CODEBLKREG_VE_VC1ESC_reg                                                0xB800E11C
#define  CODEBLKREG_VE_VC1ESC_inst_addr                                          "0x0011"
#define  CODEBLKREG_VE_VC1ESC_inst_adr                                           "0x0047"
#define  CODEBLKREG_VE_VC1ESC_inst                                               0x0047
#define  set_CODEBLKREG_VE_VC1ESC_reg(data)                                      (*((volatile unsigned int*)CODEBLKREG_VE_VC1ESC_reg)=data)
#define  get_CODEBLKREG_VE_VC1ESC_reg                                            (*((volatile unsigned int*)CODEBLKREG_VE_VC1ESC_reg))
#define  CODEBLKREG_VE_VC1ESC_write_enable1_shift                                (7)
#define  CODEBLKREG_VE_VC1ESC_escm3_rsize_shift                                  (4)
#define  CODEBLKREG_VE_VC1ESC_escm3_lsize_shift                                  (0)
#define  CODEBLKREG_VE_VC1ESC_write_enable1_mask                                 (0x00000080)
#define  CODEBLKREG_VE_VC1ESC_escm3_rsize_mask                                   (0x00000070)
#define  CODEBLKREG_VE_VC1ESC_escm3_lsize_mask                                   (0x0000000F)
#define  CODEBLKREG_VE_VC1ESC_write_enable1(data)                                (0x00000080&((data)<<7))
#define  CODEBLKREG_VE_VC1ESC_escm3_rsize(data)                                  (0x00000070&((data)<<4))
#define  CODEBLKREG_VE_VC1ESC_escm3_lsize(data)                                  (0x0000000F&(data))
#define  CODEBLKREG_VE_VC1ESC_get_write_enable1(data)                            ((0x00000080&(data))>>7)
#define  CODEBLKREG_VE_VC1ESC_get_escm3_rsize(data)                              ((0x00000070&(data))>>4)
#define  CODEBLKREG_VE_VC1ESC_get_escm3_lsize(data)                              (0x0000000F&(data))
#define  CODEBLKREG_VE_VC1ESC_write_enable1_src(data)                            ((0x00000080&(data))>>7)
#define  CODEBLKREG_VE_VC1ESC_escm3_rsize_src(data)                              ((0x00000070&(data))>>4)
#define  CODEBLKREG_VE_VC1ESC_escm3_lsize_src(data)                              (0x0000000F&(data))

#define  CODEBLKREG_VE_VC1BITPLN_CNTL                                            0x1800E120
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_reg_addr                                   "0xB800E120"
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_reg                                        0xB800E120
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_inst_addr                                  "0x0012"
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_inst_adr                                   "0x0048"
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_inst                                       0x0048
#define  set_CODEBLKREG_VE_VC1BITPLN_CNTL_reg(data)                              (*((volatile unsigned int*)CODEBLKREG_VE_VC1BITPLN_CNTL_reg)=data)
#define  get_CODEBLKREG_VE_VC1BITPLN_CNTL_reg                                    (*((volatile unsigned int*)CODEBLKREG_VE_VC1BITPLN_CNTL_reg))
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_rowMB_shift                                (24)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_colMB_shift                                (17)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_rowmb_mod3_shift                           (15)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_colmb_mod3_shift                           (13)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_bitplane_len_shift                         (0)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_rowMB_mask                                 (0xFF000000)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_colMB_mask                                 (0x00FE0000)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_rowmb_mod3_mask                            (0x00018000)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_colmb_mod3_mask                            (0x00006000)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_bitplane_len_mask                          (0x00001FFF)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_rowMB(data)                                (0xFF000000&((data)<<24))
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_colMB(data)                                (0x00FE0000&((data)<<17))
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_rowmb_mod3(data)                           (0x00018000&((data)<<15))
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_colmb_mod3(data)                           (0x00006000&((data)<<13))
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_bitplane_len(data)                         (0x00001FFF&(data))
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_get_rowMB(data)                            ((0xFF000000&(data))>>24)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_get_colMB(data)                            ((0x00FE0000&(data))>>17)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_get_rowmb_mod3(data)                       ((0x00018000&(data))>>15)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_get_colmb_mod3(data)                       ((0x00006000&(data))>>13)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_get_bitplane_len(data)                     (0x00001FFF&(data))
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_rowMB_src(data)                            ((0xFF000000&(data))>>24)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_colMB_src(data)                            ((0x00FE0000&(data))>>17)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_rowmb_mod3_src(data)                       ((0x00018000&(data))>>15)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_colmb_mod3_src(data)                       ((0x00006000&(data))>>13)
#define  CODEBLKREG_VE_VC1BITPLN_CNTL_bitplane_len_src(data)                     (0x00001FFF&(data))

#define  CODEBLKREG_VE_VC1BITPLN_BASE                                            0x1800E124
#define  CODEBLKREG_VE_VC1BITPLN_BASE_reg_addr                                   "0xB800E124"
#define  CODEBLKREG_VE_VC1BITPLN_BASE_reg                                        0xB800E124
#define  CODEBLKREG_VE_VC1BITPLN_BASE_inst_addr                                  "0x0013"
#define  CODEBLKREG_VE_VC1BITPLN_BASE_inst_adr                                   "0x0049"
#define  CODEBLKREG_VE_VC1BITPLN_BASE_inst                                       0x0049
#define  set_CODEBLKREG_VE_VC1BITPLN_BASE_reg(data)                              (*((volatile unsigned int*)CODEBLKREG_VE_VC1BITPLN_BASE_reg)=data)
#define  get_CODEBLKREG_VE_VC1BITPLN_BASE_reg                                    (*((volatile unsigned int*)CODEBLKREG_VE_VC1BITPLN_BASE_reg))
#define  CODEBLKREG_VE_VC1BITPLN_BASE_bitplane_addr_shift                        (0)
#define  CODEBLKREG_VE_VC1BITPLN_BASE_bitplane_addr_mask                         (0xFFFFFFFF)
#define  CODEBLKREG_VE_VC1BITPLN_BASE_bitplane_addr(data)                        (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_VC1BITPLN_BASE_get_bitplane_addr(data)                    (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_VC1BITPLN_BASE_bitplane_addr_src(data)                    (0xFFFFFFFF&(data))

#define  CODEBLKREG_VE_LDSTADDR                                                  0x1800E128
#define  CODEBLKREG_VE_LDSTADDR_reg_addr                                         "0xB800E128"
#define  CODEBLKREG_VE_LDSTADDR_reg                                              0xB800E128
#define  CODEBLKREG_VE_LDSTADDR_inst_addr                                        "0x0014"
#define  CODEBLKREG_VE_LDSTADDR_inst_adr                                         "0x004A"
#define  CODEBLKREG_VE_LDSTADDR_inst                                             0x004A
#define  set_CODEBLKREG_VE_LDSTADDR_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VE_LDSTADDR_reg)=data)
#define  get_CODEBLKREG_VE_LDSTADDR_reg                                          (*((volatile unsigned int*)CODEBLKREG_VE_LDSTADDR_reg))
#define  CODEBLKREG_VE_LDSTADDR_ldst_addr_shift                                  (0)
#define  CODEBLKREG_VE_LDSTADDR_ldst_addr_mask                                   (0xFFFFFFFF)
#define  CODEBLKREG_VE_LDSTADDR_ldst_addr(data)                                  (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_LDSTADDR_get_ldst_addr(data)                              (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_LDSTADDR_ldst_addr_src(data)                              (0xFFFFFFFF&(data))

#define  CODEBLKREG_VE_DECBITCNT                                                 0x1800E200
#define  CODEBLKREG_VE_DECBITCNT_reg_addr                                        "0xB800E200"
#define  CODEBLKREG_VE_DECBITCNT_reg                                             0xB800E200
#define  CODEBLKREG_VE_DECBITCNT_inst_addr                                       "0x0015"
#define  CODEBLKREG_VE_DECBITCNT_inst_adr                                        "0x0080"
#define  CODEBLKREG_VE_DECBITCNT_inst                                            0x0080
#define  set_CODEBLKREG_VE_DECBITCNT_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_DECBITCNT_reg)=data)
#define  get_CODEBLKREG_VE_DECBITCNT_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_DECBITCNT_reg))
#define  CODEBLKREG_VE_DECBITCNT_max_bit_shift                                   (0)
#define  CODEBLKREG_VE_DECBITCNT_max_bit_mask                                    (0xFFFFFFFF)
#define  CODEBLKREG_VE_DECBITCNT_max_bit(data)                                   (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_DECBITCNT_get_max_bit(data)                               (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_DECBITCNT_max_bit_src(data)                               (0xFFFFFFFF&(data))

#define  CODEBLKREG_VLD_BITCNT                                                   0x1800E204
#define  CODEBLKREG_VLD_BITCNT_reg_addr                                          "0xB800E204"
#define  CODEBLKREG_VLD_BITCNT_reg                                               0xB800E204
#define  CODEBLKREG_VLD_BITCNT_inst_addr                                         "0x0016"
#define  CODEBLKREG_VLD_BITCNT_inst_adr                                          "0x0081"
#define  CODEBLKREG_VLD_BITCNT_inst                                              0x0081
#define  set_CODEBLKREG_VLD_BITCNT_reg(data)                                     (*((volatile unsigned int*)CODEBLKREG_VLD_BITCNT_reg)=data)
#define  get_CODEBLKREG_VLD_BITCNT_reg                                           (*((volatile unsigned int*)CODEBLKREG_VLD_BITCNT_reg))
#define  CODEBLKREG_VLD_BITCNT_dec_bitcnt_shift                                  (0)
#define  CODEBLKREG_VLD_BITCNT_dec_bitcnt_mask                                   (0xFFFFFFFF)
#define  CODEBLKREG_VLD_BITCNT_dec_bitcnt(data)                                  (0xFFFFFFFF&(data))
#define  CODEBLKREG_VLD_BITCNT_get_dec_bitcnt(data)                              (0xFFFFFFFF&(data))
#define  CODEBLKREG_VLD_BITCNT_dec_bitcnt_src(data)                              (0xFFFFFFFF&(data))

#define  CODEBLKREG_VE_BSCNTL                                                    0x1800E208
#define  CODEBLKREG_VE_BSCNTL_reg_addr                                           "0xB800E208"
#define  CODEBLKREG_VE_BSCNTL_reg                                                0xB800E208
#define  CODEBLKREG_VE_BSCNTL_inst_addr                                          "0x0017"
#define  CODEBLKREG_VE_BSCNTL_inst_adr                                           "0x0082"
#define  CODEBLKREG_VE_BSCNTL_inst                                               0x0082
#define  set_CODEBLKREG_VE_BSCNTL_reg(data)                                      (*((volatile unsigned int*)CODEBLKREG_VE_BSCNTL_reg)=data)
#define  get_CODEBLKREG_VE_BSCNTL_reg                                            (*((volatile unsigned int*)CODEBLKREG_VE_BSCNTL_reg))
#define  CODEBLKREG_VE_BSCNTL_write_enable3_shift                                (6)
#define  CODEBLKREG_VE_BSCNTL_detect_startcode_error_shift                       (5)
#define  CODEBLKREG_VE_BSCNTL_write_enable2_shift                                (4)
#define  CODEBLKREG_VE_BSCNTL_min_xfer_size_shift                                (2)
#define  CODEBLKREG_VE_BSCNTL_write_enable1_shift                                (1)
#define  CODEBLKREG_VE_BSCNTL_startcode_prevnt_en_shift                          (0)
#define  CODEBLKREG_VE_BSCNTL_write_enable3_mask                                 (0x00000040)
#define  CODEBLKREG_VE_BSCNTL_detect_startcode_error_mask                        (0x00000020)
#define  CODEBLKREG_VE_BSCNTL_write_enable2_mask                                 (0x00000010)
#define  CODEBLKREG_VE_BSCNTL_min_xfer_size_mask                                 (0x0000000C)
#define  CODEBLKREG_VE_BSCNTL_write_enable1_mask                                 (0x00000002)
#define  CODEBLKREG_VE_BSCNTL_startcode_prevnt_en_mask                           (0x00000001)
#define  CODEBLKREG_VE_BSCNTL_write_enable3(data)                                (0x00000040&((data)<<6))
#define  CODEBLKREG_VE_BSCNTL_detect_startcode_error(data)                       (0x00000020&((data)<<5))
#define  CODEBLKREG_VE_BSCNTL_write_enable2(data)                                (0x00000010&((data)<<4))
#define  CODEBLKREG_VE_BSCNTL_min_xfer_size(data)                                (0x0000000C&((data)<<2))
#define  CODEBLKREG_VE_BSCNTL_write_enable1(data)                                (0x00000002&((data)<<1))
#define  CODEBLKREG_VE_BSCNTL_startcode_prevnt_en(data)                          (0x00000001&(data))
#define  CODEBLKREG_VE_BSCNTL_get_write_enable3(data)                            ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_BSCNTL_get_detect_startcode_error(data)                   ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_BSCNTL_get_write_enable2(data)                            ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_BSCNTL_get_min_xfer_size(data)                            ((0x0000000C&(data))>>2)
#define  CODEBLKREG_VE_BSCNTL_get_write_enable1(data)                            ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_BSCNTL_get_startcode_prevnt_en(data)                      (0x00000001&(data))
#define  CODEBLKREG_VE_BSCNTL_write_enable3_src(data)                            ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_BSCNTL_detect_startcode_error_src(data)                   ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_BSCNTL_write_enable2_src(data)                            ((0x00000010&(data))>>4)
#define  CODEBLKREG_VE_BSCNTL_min_xfer_size_src(data)                            ((0x0000000C&(data))>>2)
#define  CODEBLKREG_VE_BSCNTL_write_enable1_src(data)                            ((0x00000002&(data))>>1)
#define  CODEBLKREG_VE_BSCNTL_startcode_prevnt_en_src(data)                      (0x00000001&(data))

#define  CODEBLKREG_VE_BS_MIN_THR                                                0x1800E20C
#define  CODEBLKREG_VE_BS_MIN_THR_reg_addr                                       "0xB800E20C"
#define  CODEBLKREG_VE_BS_MIN_THR_reg                                            0xB800E20C
#define  CODEBLKREG_VE_BS_MIN_THR_inst_addr                                      "0x0018"
#define  CODEBLKREG_VE_BS_MIN_THR_inst_adr                                       "0x0083"
#define  CODEBLKREG_VE_BS_MIN_THR_inst                                           0x0083
#define  set_CODEBLKREG_VE_BS_MIN_THR_reg(data)                                  (*((volatile unsigned int*)CODEBLKREG_VE_BS_MIN_THR_reg)=data)
#define  get_CODEBLKREG_VE_BS_MIN_THR_reg                                        (*((volatile unsigned int*)CODEBLKREG_VE_BS_MIN_THR_reg))
#define  CODEBLKREG_VE_BS_MIN_THR_min_thre_shift                                 (0)
#define  CODEBLKREG_VE_BS_MIN_THR_min_thre_mask                                  (0x0000007F)
#define  CODEBLKREG_VE_BS_MIN_THR_min_thre(data)                                 (0x0000007F&(data))
#define  CODEBLKREG_VE_BS_MIN_THR_get_min_thre(data)                             (0x0000007F&(data))
#define  CODEBLKREG_VE_BS_MIN_THR_min_thre_src(data)                             (0x0000007F&(data))

#define  CODEBLKREG_VE_BSTIMER                                                   0x1800E210
#define  CODEBLKREG_VE_BSTIMER_reg_addr                                          "0xB800E210"
#define  CODEBLKREG_VE_BSTIMER_reg                                               0xB800E210
#define  CODEBLKREG_VE_BSTIMER_inst_addr                                         "0x0019"
#define  CODEBLKREG_VE_BSTIMER_inst_adr                                          "0x0084"
#define  CODEBLKREG_VE_BSTIMER_inst                                              0x0084
#define  set_CODEBLKREG_VE_BSTIMER_reg(data)                                     (*((volatile unsigned int*)CODEBLKREG_VE_BSTIMER_reg)=data)
#define  get_CODEBLKREG_VE_BSTIMER_reg                                           (*((volatile unsigned int*)CODEBLKREG_VE_BSTIMER_reg))
#define  CODEBLKREG_VE_BSTIMER_timer_value_shift                                 (0)
#define  CODEBLKREG_VE_BSTIMER_timer_value_mask                                  (0x00FFFFFF)
#define  CODEBLKREG_VE_BSTIMER_timer_value(data)                                 (0x00FFFFFF&(data))
#define  CODEBLKREG_VE_BSTIMER_get_timer_value(data)                             (0x00FFFFFF&(data))
#define  CODEBLKREG_VE_BSTIMER_timer_value_src(data)                             (0x00FFFFFF&(data))

#define  CODEBLKREG_VE_BSBASE                                                    0x1800E214
#define  CODEBLKREG_VE_BSBASE_reg_addr                                           "0xB800E214"
#define  CODEBLKREG_VE_BSBASE_reg                                                0xB800E214
#define  CODEBLKREG_VE_BSBASE_inst_addr                                          "0x001A"
#define  CODEBLKREG_VE_BSBASE_inst_adr                                           "0x0085"
#define  CODEBLKREG_VE_BSBASE_inst                                               0x0085
#define  set_CODEBLKREG_VE_BSBASE_reg(data)                                      (*((volatile unsigned int*)CODEBLKREG_VE_BSBASE_reg)=data)
#define  get_CODEBLKREG_VE_BSBASE_reg                                            (*((volatile unsigned int*)CODEBLKREG_VE_BSBASE_reg))
#define  CODEBLKREG_VE_BSBASE_base_addr_shift                                    (0)
#define  CODEBLKREG_VE_BSBASE_base_addr_mask                                     (0xFFFFFFFF)
#define  CODEBLKREG_VE_BSBASE_base_addr(data)                                    (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_BSBASE_get_base_addr(data)                                (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_BSBASE_base_addr_src(data)                                (0xFFFFFFFF&(data))

#define  CODEBLKREG_VE_BSLIMIT                                                   0x1800E218
#define  CODEBLKREG_VE_BSLIMIT_reg_addr                                          "0xB800E218"
#define  CODEBLKREG_VE_BSLIMIT_reg                                               0xB800E218
#define  CODEBLKREG_VE_BSLIMIT_inst_addr                                         "0x001B"
#define  CODEBLKREG_VE_BSLIMIT_inst_adr                                          "0x0086"
#define  CODEBLKREG_VE_BSLIMIT_inst                                              0x0086
#define  set_CODEBLKREG_VE_BSLIMIT_reg(data)                                     (*((volatile unsigned int*)CODEBLKREG_VE_BSLIMIT_reg)=data)
#define  get_CODEBLKREG_VE_BSLIMIT_reg                                           (*((volatile unsigned int*)CODEBLKREG_VE_BSLIMIT_reg))
#define  CODEBLKREG_VE_BSLIMIT_limit_addr_shift                                  (0)
#define  CODEBLKREG_VE_BSLIMIT_limit_addr_mask                                   (0xFFFFFFFF)
#define  CODEBLKREG_VE_BSLIMIT_limit_addr(data)                                  (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_BSLIMIT_get_limit_addr(data)                              (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_BSLIMIT_limit_addr_src(data)                              (0xFFFFFFFF&(data))

#define  CODEBLKREG_VE_BSWRPTR                                                   0x1800E21C
#define  CODEBLKREG_VE_BSWRPTR_reg_addr                                          "0xB800E21C"
#define  CODEBLKREG_VE_BSWRPTR_reg                                               0xB800E21C
#define  CODEBLKREG_VE_BSWRPTR_inst_addr                                         "0x001C"
#define  CODEBLKREG_VE_BSWRPTR_inst_adr                                          "0x0087"
#define  CODEBLKREG_VE_BSWRPTR_inst                                              0x0087
#define  set_CODEBLKREG_VE_BSWRPTR_reg(data)                                     (*((volatile unsigned int*)CODEBLKREG_VE_BSWRPTR_reg)=data)
#define  get_CODEBLKREG_VE_BSWRPTR_reg                                           (*((volatile unsigned int*)CODEBLKREG_VE_BSWRPTR_reg))
#define  CODEBLKREG_VE_BSWRPTR_wr_ptr_shift                                      (0)
#define  CODEBLKREG_VE_BSWRPTR_wr_ptr_mask                                       (0xFFFFFFFF)
#define  CODEBLKREG_VE_BSWRPTR_wr_ptr(data)                                      (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_BSWRPTR_get_wr_ptr(data)                                  (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_BSWRPTR_wr_ptr_src(data)                                  (0xFFFFFFFF&(data))

#define  CODEBLKREG_VE_BSCURPTR                                                  0x1800E220
#define  CODEBLKREG_VE_BSCURPTR_reg_addr                                         "0xB800E220"
#define  CODEBLKREG_VE_BSCURPTR_reg                                              0xB800E220
#define  CODEBLKREG_VE_BSCURPTR_inst_addr                                        "0x001D"
#define  CODEBLKREG_VE_BSCURPTR_inst_adr                                         "0x0088"
#define  CODEBLKREG_VE_BSCURPTR_inst                                             0x0088
#define  set_CODEBLKREG_VE_BSCURPTR_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VE_BSCURPTR_reg)=data)
#define  get_CODEBLKREG_VE_BSCURPTR_reg                                          (*((volatile unsigned int*)CODEBLKREG_VE_BSCURPTR_reg))
#define  CODEBLKREG_VE_BSCURPTR_cur_ptr_shift                                    (0)
#define  CODEBLKREG_VE_BSCURPTR_cur_ptr_mask                                     (0xFFFFFFFF)
#define  CODEBLKREG_VE_BSCURPTR_cur_ptr(data)                                    (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_BSCURPTR_get_cur_ptr(data)                                (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_BSCURPTR_cur_ptr_src(data)                                (0xFFFFFFFF&(data))

#define  CODEBLKREG_VE_DECBSPTR                                                  0x1800E224
#define  CODEBLKREG_VE_DECBSPTR_reg_addr                                         "0xB800E224"
#define  CODEBLKREG_VE_DECBSPTR_reg                                              0xB800E224
#define  CODEBLKREG_VE_DECBSPTR_inst_addr                                        "0x001E"
#define  CODEBLKREG_VE_DECBSPTR_inst_adr                                         "0x0089"
#define  CODEBLKREG_VE_DECBSPTR_inst                                             0x0089
#define  set_CODEBLKREG_VE_DECBSPTR_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VE_DECBSPTR_reg)=data)
#define  get_CODEBLKREG_VE_DECBSPTR_reg                                          (*((volatile unsigned int*)CODEBLKREG_VE_DECBSPTR_reg))
#define  CODEBLKREG_VE_DECBSPTR_dec_bit_ptr_shift                                (0)
#define  CODEBLKREG_VE_DECBSPTR_dec_bit_ptr_mask                                 (0xFFFFFFFF)
#define  CODEBLKREG_VE_DECBSPTR_dec_bit_ptr(data)                                (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_DECBSPTR_get_dec_bit_ptr(data)                            (0xFFFFFFFF&(data))
#define  CODEBLKREG_VE_DECBSPTR_dec_bit_ptr_src(data)                            (0xFFFFFFFF&(data))

#define  CODEBLKREG_VE_JPG_EMU_0                                                 0x1800E228
#define  CODEBLKREG_VE_JPG_EMU_0_reg_addr                                        "0xB800E228"
#define  CODEBLKREG_VE_JPG_EMU_0_reg                                             0xB800E228
#define  CODEBLKREG_VE_JPG_EMU_0_inst_addr                                       "0x001F"
#define  CODEBLKREG_VE_JPG_EMU_0_inst_adr                                        "0x008A"
#define  CODEBLKREG_VE_JPG_EMU_0_inst                                            0x008A
#define  set_CODEBLKREG_VE_JPG_EMU_0_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_0_reg)=data)
#define  get_CODEBLKREG_VE_JPG_EMU_0_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_0_reg))
#define  CODEBLKREG_VE_JPG_EMU_removal_counter_shift                             (0)
#define  CODEBLKREG_VE_JPG_EMU_removal_counter_mask                              (0x1FFFFFFF)
#define  CODEBLKREG_VE_JPG_EMU_removal_counter(data)                             (0x1FFFFFFF&(data))
#define  CODEBLKREG_VE_JPG_EMU_get_removal_counter(data)                         (0x1FFFFFFF&(data))
#define  CODEBLKREG_VE_JPG_EMU_removal_counter_src(data)                         (0x1FFFFFFF&(data))

#define  CODEBLKREG_VE_JPG_EMU_1                                                 0x1800E22C
#define  CODEBLKREG_VE_JPG_EMU_1_reg_addr                                        "0xB800E22C"
#define  CODEBLKREG_VE_JPG_EMU_1_reg                                             0xB800E22C
#define  CODEBLKREG_VE_JPG_EMU_1_inst_addr                                       "0x0020"
#define  CODEBLKREG_VE_JPG_EMU_1_inst_adr                                        "0x008B"
#define  CODEBLKREG_VE_JPG_EMU_1_inst                                            0x008B
#define  set_CODEBLKREG_VE_JPG_EMU_1_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_1_reg)=data)
#define  get_CODEBLKREG_VE_JPG_EMU_1_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_1_reg))

#define  CODEBLKREG_VE_JPG_EMU_2                                                 0x1800E230
#define  CODEBLKREG_VE_JPG_EMU_2_reg_addr                                        "0xB800E230"
#define  CODEBLKREG_VE_JPG_EMU_2_reg                                             0xB800E230
#define  CODEBLKREG_VE_JPG_EMU_2_inst_addr                                       "0x0021"
#define  CODEBLKREG_VE_JPG_EMU_2_inst_adr                                        "0x008C"
#define  CODEBLKREG_VE_JPG_EMU_2_inst                                            0x008C
#define  set_CODEBLKREG_VE_JPG_EMU_2_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_2_reg)=data)
#define  get_CODEBLKREG_VE_JPG_EMU_2_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_2_reg))

#define  CODEBLKREG_VE_JPG_EMU_3                                                 0x1800E234
#define  CODEBLKREG_VE_JPG_EMU_3_reg_addr                                        "0xB800E234"
#define  CODEBLKREG_VE_JPG_EMU_3_reg                                             0xB800E234
#define  CODEBLKREG_VE_JPG_EMU_3_inst_addr                                       "0x0022"
#define  CODEBLKREG_VE_JPG_EMU_3_inst_adr                                        "0x008D"
#define  CODEBLKREG_VE_JPG_EMU_3_inst                                            0x008D
#define  set_CODEBLKREG_VE_JPG_EMU_3_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_3_reg)=data)
#define  get_CODEBLKREG_VE_JPG_EMU_3_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_3_reg))

#define  CODEBLKREG_VE_JPG_EMU_4                                                 0x1800E238
#define  CODEBLKREG_VE_JPG_EMU_4_reg_addr                                        "0xB800E238"
#define  CODEBLKREG_VE_JPG_EMU_4_reg                                             0xB800E238
#define  CODEBLKREG_VE_JPG_EMU_4_inst_addr                                       "0x0023"
#define  CODEBLKREG_VE_JPG_EMU_4_inst_adr                                        "0x008E"
#define  CODEBLKREG_VE_JPG_EMU_4_inst                                            0x008E
#define  set_CODEBLKREG_VE_JPG_EMU_4_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_4_reg)=data)
#define  get_CODEBLKREG_VE_JPG_EMU_4_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_4_reg))

#define  CODEBLKREG_VE_JPG_EMU_5                                                 0x1800E23C
#define  CODEBLKREG_VE_JPG_EMU_5_reg_addr                                        "0xB800E23C"
#define  CODEBLKREG_VE_JPG_EMU_5_reg                                             0xB800E23C
#define  CODEBLKREG_VE_JPG_EMU_5_inst_addr                                       "0x0024"
#define  CODEBLKREG_VE_JPG_EMU_5_inst_adr                                        "0x008F"
#define  CODEBLKREG_VE_JPG_EMU_5_inst                                            0x008F
#define  set_CODEBLKREG_VE_JPG_EMU_5_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_5_reg)=data)
#define  get_CODEBLKREG_VE_JPG_EMU_5_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_5_reg))

#define  CODEBLKREG_VE_JPG_EMU_6                                                 0x1800E240
#define  CODEBLKREG_VE_JPG_EMU_6_reg_addr                                        "0xB800E240"
#define  CODEBLKREG_VE_JPG_EMU_6_reg                                             0xB800E240
#define  CODEBLKREG_VE_JPG_EMU_6_inst_addr                                       "0x0025"
#define  CODEBLKREG_VE_JPG_EMU_6_inst_adr                                        "0x0090"
#define  CODEBLKREG_VE_JPG_EMU_6_inst                                            0x0090
#define  set_CODEBLKREG_VE_JPG_EMU_6_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_6_reg)=data)
#define  get_CODEBLKREG_VE_JPG_EMU_6_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_6_reg))

#define  CODEBLKREG_VE_JPG_EMU_7                                                 0x1800E244
#define  CODEBLKREG_VE_JPG_EMU_7_reg_addr                                        "0xB800E244"
#define  CODEBLKREG_VE_JPG_EMU_7_reg                                             0xB800E244
#define  CODEBLKREG_VE_JPG_EMU_7_inst_addr                                       "0x0026"
#define  CODEBLKREG_VE_JPG_EMU_7_inst_adr                                        "0x0091"
#define  CODEBLKREG_VE_JPG_EMU_7_inst                                            0x0091
#define  set_CODEBLKREG_VE_JPG_EMU_7_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_7_reg)=data)
#define  get_CODEBLKREG_VE_JPG_EMU_7_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_JPG_EMU_7_reg))

#define  CODEBLKREG_VE_DECBSPTR_MSB                                              0x1800E248
#define  CODEBLKREG_VE_DECBSPTR_MSB_reg_addr                                     "0xB800E248"
#define  CODEBLKREG_VE_DECBSPTR_MSB_reg                                          0xB800E248
#define  CODEBLKREG_VE_DECBSPTR_MSB_inst_addr                                    "0x0027"
#define  CODEBLKREG_VE_DECBSPTR_MSB_inst_adr                                     "0x0092"
#define  CODEBLKREG_VE_DECBSPTR_MSB_inst                                         0x0092
#define  set_CODEBLKREG_VE_DECBSPTR_MSB_reg(data)                                (*((volatile unsigned int*)CODEBLKREG_VE_DECBSPTR_MSB_reg)=data)
#define  get_CODEBLKREG_VE_DECBSPTR_MSB_reg                                      (*((volatile unsigned int*)CODEBLKREG_VE_DECBSPTR_MSB_reg))
#define  CODEBLKREG_VE_DECBSPTR_MSB_dec_bit_ptr_msb_shift                        (0)
#define  CODEBLKREG_VE_DECBSPTR_MSB_dec_bit_ptr_msb_mask                         (0x00000007)
#define  CODEBLKREG_VE_DECBSPTR_MSB_dec_bit_ptr_msb(data)                        (0x00000007&(data))
#define  CODEBLKREG_VE_DECBSPTR_MSB_get_dec_bit_ptr_msb(data)                    (0x00000007&(data))
#define  CODEBLKREG_VE_DECBSPTR_MSB_dec_bit_ptr_msb_src(data)                    (0x00000007&(data))

#define  CODEBLKREG_VE_TRANSFORM                                                 0x1800E300
#define  CODEBLKREG_VE_TRANSFORM_reg_addr                                        "0xB800E300"
#define  CODEBLKREG_VE_TRANSFORM_reg                                             0xB800E300
#define  CODEBLKREG_VE_TRANSFORM_inst_addr                                       "0x0028"
#define  CODEBLKREG_VE_TRANSFORM_inst_adr                                        "0x00C0"
#define  CODEBLKREG_VE_TRANSFORM_inst                                            0x00C0
#define  set_CODEBLKREG_VE_TRANSFORM_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_TRANSFORM_reg)=data)
#define  get_CODEBLKREG_VE_TRANSFORM_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_TRANSFORM_reg))
#define  CODEBLKREG_VE_TRANSFORM_write_enable6_shift                             (31)
#define  CODEBLKREG_VE_TRANSFORM_sad_en_shift                                    (30)
#define  CODEBLKREG_VE_TRANSFORM_write_enable5_shift                             (29)
#define  CODEBLKREG_VE_TRANSFORM_sad_threshold_shift                             (19)
#define  CODEBLKREG_VE_TRANSFORM_write_enable4_shift                             (18)
#define  CODEBLKREG_VE_TRANSFORM_flat_qtable_shift                               (17)
#define  CODEBLKREG_VE_TRANSFORM_write_enable3_shift                             (16)
#define  CODEBLKREG_VE_TRANSFORM_transform_size_8x8_shift                        (15)
#define  CODEBLKREG_VE_TRANSFORM_write_enable2_shift                             (14)
#define  CODEBLKREG_VE_TRANSFORM_field_transform_shift                           (13)
#define  CODEBLKREG_VE_TRANSFORM_write_enable1_shift                             (12)
#define  CODEBLKREG_VE_TRANSFORM_mb_ttfrm_shift                                  (0)
#define  CODEBLKREG_VE_TRANSFORM_write_enable6_mask                              (0x80000000)
#define  CODEBLKREG_VE_TRANSFORM_sad_en_mask                                     (0x40000000)
#define  CODEBLKREG_VE_TRANSFORM_write_enable5_mask                              (0x20000000)
#define  CODEBLKREG_VE_TRANSFORM_sad_threshold_mask                              (0x1FF80000)
#define  CODEBLKREG_VE_TRANSFORM_write_enable4_mask                              (0x00040000)
#define  CODEBLKREG_VE_TRANSFORM_flat_qtable_mask                                (0x00020000)
#define  CODEBLKREG_VE_TRANSFORM_write_enable3_mask                              (0x00010000)
#define  CODEBLKREG_VE_TRANSFORM_transform_size_8x8_mask                         (0x00008000)
#define  CODEBLKREG_VE_TRANSFORM_write_enable2_mask                              (0x00004000)
#define  CODEBLKREG_VE_TRANSFORM_field_transform_mask                            (0x00002000)
#define  CODEBLKREG_VE_TRANSFORM_write_enable1_mask                              (0x00001000)
#define  CODEBLKREG_VE_TRANSFORM_mb_ttfrm_mask                                   (0x00000FFF)
#define  CODEBLKREG_VE_TRANSFORM_write_enable6(data)                             (0x80000000&((data)<<31))
#define  CODEBLKREG_VE_TRANSFORM_sad_en(data)                                    (0x40000000&((data)<<30))
#define  CODEBLKREG_VE_TRANSFORM_write_enable5(data)                             (0x20000000&((data)<<29))
#define  CODEBLKREG_VE_TRANSFORM_sad_threshold(data)                             (0x1FF80000&((data)<<19))
#define  CODEBLKREG_VE_TRANSFORM_write_enable4(data)                             (0x00040000&((data)<<18))
#define  CODEBLKREG_VE_TRANSFORM_flat_qtable(data)                               (0x00020000&((data)<<17))
#define  CODEBLKREG_VE_TRANSFORM_write_enable3(data)                             (0x00010000&((data)<<16))
#define  CODEBLKREG_VE_TRANSFORM_transform_size_8x8(data)                        (0x00008000&((data)<<15))
#define  CODEBLKREG_VE_TRANSFORM_write_enable2(data)                             (0x00004000&((data)<<14))
#define  CODEBLKREG_VE_TRANSFORM_field_transform(data)                           (0x00002000&((data)<<13))
#define  CODEBLKREG_VE_TRANSFORM_write_enable1(data)                             (0x00001000&((data)<<12))
#define  CODEBLKREG_VE_TRANSFORM_mb_ttfrm(data)                                  (0x00000FFF&(data))
#define  CODEBLKREG_VE_TRANSFORM_get_write_enable6(data)                         ((0x80000000&(data))>>31)
#define  CODEBLKREG_VE_TRANSFORM_get_sad_en(data)                                ((0x40000000&(data))>>30)
#define  CODEBLKREG_VE_TRANSFORM_get_write_enable5(data)                         ((0x20000000&(data))>>29)
#define  CODEBLKREG_VE_TRANSFORM_get_sad_threshold(data)                         ((0x1FF80000&(data))>>19)
#define  CODEBLKREG_VE_TRANSFORM_get_write_enable4(data)                         ((0x00040000&(data))>>18)
#define  CODEBLKREG_VE_TRANSFORM_get_flat_qtable(data)                           ((0x00020000&(data))>>17)
#define  CODEBLKREG_VE_TRANSFORM_get_write_enable3(data)                         ((0x00010000&(data))>>16)
#define  CODEBLKREG_VE_TRANSFORM_get_transform_size_8x8(data)                    ((0x00008000&(data))>>15)
#define  CODEBLKREG_VE_TRANSFORM_get_write_enable2(data)                         ((0x00004000&(data))>>14)
#define  CODEBLKREG_VE_TRANSFORM_get_field_transform(data)                       ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_TRANSFORM_get_write_enable1(data)                         ((0x00001000&(data))>>12)
#define  CODEBLKREG_VE_TRANSFORM_get_mb_ttfrm(data)                              (0x00000FFF&(data))
#define  CODEBLKREG_VE_TRANSFORM_write_enable6_src(data)                         ((0x80000000&(data))>>31)
#define  CODEBLKREG_VE_TRANSFORM_sad_en_src(data)                                ((0x40000000&(data))>>30)
#define  CODEBLKREG_VE_TRANSFORM_write_enable5_src(data)                         ((0x20000000&(data))>>29)
#define  CODEBLKREG_VE_TRANSFORM_sad_threshold_src(data)                         ((0x1FF80000&(data))>>19)
#define  CODEBLKREG_VE_TRANSFORM_write_enable4_src(data)                         ((0x00040000&(data))>>18)
#define  CODEBLKREG_VE_TRANSFORM_flat_qtable_src(data)                           ((0x00020000&(data))>>17)
#define  CODEBLKREG_VE_TRANSFORM_write_enable3_src(data)                         ((0x00010000&(data))>>16)
#define  CODEBLKREG_VE_TRANSFORM_transform_size_8x8_src(data)                    ((0x00008000&(data))>>15)
#define  CODEBLKREG_VE_TRANSFORM_write_enable2_src(data)                         ((0x00004000&(data))>>14)
#define  CODEBLKREG_VE_TRANSFORM_field_transform_src(data)                       ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_TRANSFORM_write_enable1_src(data)                         ((0x00001000&(data))>>12)
#define  CODEBLKREG_VE_TRANSFORM_mb_ttfrm_src(data)                              (0x00000FFF&(data))

#define  CODEBLKREG_VE_QUANTIZER                                                 0x1800E304
#define  CODEBLKREG_VE_QUANTIZER_reg_addr                                        "0xB800E304"
#define  CODEBLKREG_VE_QUANTIZER_reg                                             0xB800E304
#define  CODEBLKREG_VE_QUANTIZER_inst_addr                                       "0x0029"
#define  CODEBLKREG_VE_QUANTIZER_inst_adr                                        "0x00C1"
#define  CODEBLKREG_VE_QUANTIZER_inst                                            0x00C1
#define  set_CODEBLKREG_VE_QUANTIZER_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_VE_QUANTIZER_reg)=data)
#define  get_CODEBLKREG_VE_QUANTIZER_reg                                         (*((volatile unsigned int*)CODEBLKREG_VE_QUANTIZER_reg))
#define  CODEBLKREG_VE_QUANTIZER_write_enable6_shift                             (31)
#define  CODEBLKREG_VE_QUANTIZER_id_pred_shift                                   (29)
#define  CODEBLKREG_VE_QUANTIZER_write_enable5_shift                             (28)
#define  CODEBLKREG_VE_QUANTIZER_quant_type_shift                                (27)
#define  CODEBLKREG_VE_QUANTIZER_write_enable4_shift                             (26)
#define  CODEBLKREG_VE_QUANTIZER_mquant_shift                                    (21)
#define  CODEBLKREG_VE_QUANTIZER_write_enable3_shift                             (20)
#define  CODEBLKREG_VE_QUANTIZER_qpy_shift                                       (14)
#define  CODEBLKREG_VE_QUANTIZER_write_enable2_shift                             (13)
#define  CODEBLKREG_VE_QUANTIZER_qpcb_shift                                      (7)
#define  CODEBLKREG_VE_QUANTIZER_write_enable1_shift                             (6)
#define  CODEBLKREG_VE_QUANTIZER_qpcr_shift                                      (0)
#define  CODEBLKREG_VE_QUANTIZER_write_enable6_mask                              (0x80000000)
#define  CODEBLKREG_VE_QUANTIZER_id_pred_mask                                    (0x60000000)
#define  CODEBLKREG_VE_QUANTIZER_write_enable5_mask                              (0x10000000)
#define  CODEBLKREG_VE_QUANTIZER_quant_type_mask                                 (0x08000000)
#define  CODEBLKREG_VE_QUANTIZER_write_enable4_mask                              (0x04000000)
#define  CODEBLKREG_VE_QUANTIZER_mquant_mask                                     (0x03E00000)
#define  CODEBLKREG_VE_QUANTIZER_write_enable3_mask                              (0x00100000)
#define  CODEBLKREG_VE_QUANTIZER_qpy_mask                                        (0x000FC000)
#define  CODEBLKREG_VE_QUANTIZER_write_enable2_mask                              (0x00002000)
#define  CODEBLKREG_VE_QUANTIZER_qpcb_mask                                       (0x00001F80)
#define  CODEBLKREG_VE_QUANTIZER_write_enable1_mask                              (0x00000040)
#define  CODEBLKREG_VE_QUANTIZER_qpcr_mask                                       (0x0000003F)
#define  CODEBLKREG_VE_QUANTIZER_write_enable6(data)                             (0x80000000&((data)<<31))
#define  CODEBLKREG_VE_QUANTIZER_id_pred(data)                                   (0x60000000&((data)<<29))
#define  CODEBLKREG_VE_QUANTIZER_write_enable5(data)                             (0x10000000&((data)<<28))
#define  CODEBLKREG_VE_QUANTIZER_quant_type(data)                                (0x08000000&((data)<<27))
#define  CODEBLKREG_VE_QUANTIZER_write_enable4(data)                             (0x04000000&((data)<<26))
#define  CODEBLKREG_VE_QUANTIZER_mquant(data)                                    (0x03E00000&((data)<<21))
#define  CODEBLKREG_VE_QUANTIZER_write_enable3(data)                             (0x00100000&((data)<<20))
#define  CODEBLKREG_VE_QUANTIZER_qpy(data)                                       (0x000FC000&((data)<<14))
#define  CODEBLKREG_VE_QUANTIZER_write_enable2(data)                             (0x00002000&((data)<<13))
#define  CODEBLKREG_VE_QUANTIZER_qpcb(data)                                      (0x00001F80&((data)<<7))
#define  CODEBLKREG_VE_QUANTIZER_write_enable1(data)                             (0x00000040&((data)<<6))
#define  CODEBLKREG_VE_QUANTIZER_qpcr(data)                                      (0x0000003F&(data))
#define  CODEBLKREG_VE_QUANTIZER_get_write_enable6(data)                         ((0x80000000&(data))>>31)
#define  CODEBLKREG_VE_QUANTIZER_get_id_pred(data)                               ((0x60000000&(data))>>29)
#define  CODEBLKREG_VE_QUANTIZER_get_write_enable5(data)                         ((0x10000000&(data))>>28)
#define  CODEBLKREG_VE_QUANTIZER_get_quant_type(data)                            ((0x08000000&(data))>>27)
#define  CODEBLKREG_VE_QUANTIZER_get_write_enable4(data)                         ((0x04000000&(data))>>26)
#define  CODEBLKREG_VE_QUANTIZER_get_mquant(data)                                ((0x03E00000&(data))>>21)
#define  CODEBLKREG_VE_QUANTIZER_get_write_enable3(data)                         ((0x00100000&(data))>>20)
#define  CODEBLKREG_VE_QUANTIZER_get_qpy(data)                                   ((0x000FC000&(data))>>14)
#define  CODEBLKREG_VE_QUANTIZER_get_write_enable2(data)                         ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_QUANTIZER_get_qpcb(data)                                  ((0x00001F80&(data))>>7)
#define  CODEBLKREG_VE_QUANTIZER_get_write_enable1(data)                         ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_QUANTIZER_get_qpcr(data)                                  (0x0000003F&(data))
#define  CODEBLKREG_VE_QUANTIZER_write_enable6_src(data)                         ((0x80000000&(data))>>31)
#define  CODEBLKREG_VE_QUANTIZER_id_pred_src(data)                               ((0x60000000&(data))>>29)
#define  CODEBLKREG_VE_QUANTIZER_write_enable5_src(data)                         ((0x10000000&(data))>>28)
#define  CODEBLKREG_VE_QUANTIZER_quant_type_src(data)                            ((0x08000000&(data))>>27)
#define  CODEBLKREG_VE_QUANTIZER_write_enable4_src(data)                         ((0x04000000&(data))>>26)
#define  CODEBLKREG_VE_QUANTIZER_mquant_src(data)                                ((0x03E00000&(data))>>21)
#define  CODEBLKREG_VE_QUANTIZER_write_enable3_src(data)                         ((0x00100000&(data))>>20)
#define  CODEBLKREG_VE_QUANTIZER_qpy_src(data)                                   ((0x000FC000&(data))>>14)
#define  CODEBLKREG_VE_QUANTIZER_write_enable2_src(data)                         ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_QUANTIZER_qpcb_src(data)                                  ((0x00001F80&(data))>>7)
#define  CODEBLKREG_VE_QUANTIZER_write_enable1_src(data)                         ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_QUANTIZER_qpcr_src(data)                                  (0x0000003F&(data))

#define  CODEBLKREG_VE_QUANTIZER2                                                0x1800E3EC
#define  CODEBLKREG_VE_QUANTIZER2_reg_addr                                       "0xB800E3EC"
#define  CODEBLKREG_VE_QUANTIZER2_reg                                            0xB800E3EC
#define  CODEBLKREG_VE_QUANTIZER2_inst_addr                                      "0x002A"
#define  CODEBLKREG_VE_QUANTIZER2_inst_adr                                       "0x00FB"
#define  CODEBLKREG_VE_QUANTIZER2_inst                                           0x00FB
#define  set_CODEBLKREG_VE_QUANTIZER2_reg(data)                                  (*((volatile unsigned int*)CODEBLKREG_VE_QUANTIZER2_reg)=data)
#define  get_CODEBLKREG_VE_QUANTIZER2_reg                                        (*((volatile unsigned int*)CODEBLKREG_VE_QUANTIZER2_reg))
#define  CODEBLKREG_VE_QUANTIZER2_write_enable5_shift                            (31)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y2ac_shift                              (26)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable4_shift                            (25)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_uvdc_shift                              (20)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable3_shift                            (19)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y2dc_shift                              (14)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable2_shift                            (13)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y1dc_shift                              (8)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable1_shift                            (7)
#define  CODEBLKREG_VE_QUANTIZER2_vp8_qp_shift                                   (0)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable5_mask                             (0x80000000)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y2ac_mask                               (0x7C000000)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable4_mask                             (0x02000000)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_uvdc_mask                               (0x01F00000)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable3_mask                             (0x00080000)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y2dc_mask                               (0x0007C000)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable2_mask                             (0x00002000)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y1dc_mask                               (0x00001F00)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable1_mask                             (0x00000080)
#define  CODEBLKREG_VE_QUANTIZER2_vp8_qp_mask                                    (0x0000007F)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable5(data)                            (0x80000000&((data)<<31))
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y2ac(data)                              (0x7C000000&((data)<<26))
#define  CODEBLKREG_VE_QUANTIZER2_write_enable4(data)                            (0x02000000&((data)<<25))
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_uvdc(data)                              (0x01F00000&((data)<<20))
#define  CODEBLKREG_VE_QUANTIZER2_write_enable3(data)                            (0x00080000&((data)<<19))
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y2dc(data)                              (0x0007C000&((data)<<14))
#define  CODEBLKREG_VE_QUANTIZER2_write_enable2(data)                            (0x00002000&((data)<<13))
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y1dc(data)                              (0x00001F00&((data)<<8))
#define  CODEBLKREG_VE_QUANTIZER2_write_enable1(data)                            (0x00000080&((data)<<7))
#define  CODEBLKREG_VE_QUANTIZER2_vp8_qp(data)                                   (0x0000007F&(data))
#define  CODEBLKREG_VE_QUANTIZER2_get_write_enable5(data)                        ((0x80000000&(data))>>31)
#define  CODEBLKREG_VE_QUANTIZER2_get_qdelta_y2ac(data)                          ((0x7C000000&(data))>>26)
#define  CODEBLKREG_VE_QUANTIZER2_get_write_enable4(data)                        ((0x02000000&(data))>>25)
#define  CODEBLKREG_VE_QUANTIZER2_get_qdelta_uvdc(data)                          ((0x01F00000&(data))>>20)
#define  CODEBLKREG_VE_QUANTIZER2_get_write_enable3(data)                        ((0x00080000&(data))>>19)
#define  CODEBLKREG_VE_QUANTIZER2_get_qdelta_y2dc(data)                          ((0x0007C000&(data))>>14)
#define  CODEBLKREG_VE_QUANTIZER2_get_write_enable2(data)                        ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_QUANTIZER2_get_qdelta_y1dc(data)                          ((0x00001F00&(data))>>8)
#define  CODEBLKREG_VE_QUANTIZER2_get_write_enable1(data)                        ((0x00000080&(data))>>7)
#define  CODEBLKREG_VE_QUANTIZER2_get_vp8_qp(data)                               (0x0000007F&(data))
#define  CODEBLKREG_VE_QUANTIZER2_write_enable5_src(data)                        ((0x80000000&(data))>>31)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y2ac_src(data)                          ((0x7C000000&(data))>>26)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable4_src(data)                        ((0x02000000&(data))>>25)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_uvdc_src(data)                          ((0x01F00000&(data))>>20)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable3_src(data)                        ((0x00080000&(data))>>19)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y2dc_src(data)                          ((0x0007C000&(data))>>14)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable2_src(data)                        ((0x00002000&(data))>>13)
#define  CODEBLKREG_VE_QUANTIZER2_qdelta_y1dc_src(data)                          ((0x00001F00&(data))>>8)
#define  CODEBLKREG_VE_QUANTIZER2_write_enable1_src(data)                        ((0x00000080&(data))>>7)
#define  CODEBLKREG_VE_QUANTIZER2_vp8_qp_src(data)                               (0x0000007F&(data))

#define  CODEBLKREG_VE_ITDMA                                                     0x1800E3BC
#define  CODEBLKREG_VE_ITDMA_reg_addr                                            "0xB800E3BC"
#define  CODEBLKREG_VE_ITDMA_reg                                                 0xB800E3BC
#define  CODEBLKREG_VE_ITDMA_inst_addr                                           "0x002B"
#define  CODEBLKREG_VE_ITDMA_inst_adr                                            "0x00EF"
#define  CODEBLKREG_VE_ITDMA_inst                                                0x00EF
#define  set_CODEBLKREG_VE_ITDMA_reg(data)                                       (*((volatile unsigned int*)CODEBLKREG_VE_ITDMA_reg)=data)
#define  get_CODEBLKREG_VE_ITDMA_reg                                             (*((volatile unsigned int*)CODEBLKREG_VE_ITDMA_reg))
#define  CODEBLKREG_VE_ITDMA_blk_pic_idx_shift                                   (0)
#define  CODEBLKREG_VE_ITDMA_blk_pic_idx_mask                                    (0x0000007F)
#define  CODEBLKREG_VE_ITDMA_blk_pic_idx(data)                                   (0x0000007F&(data))
#define  CODEBLKREG_VE_ITDMA_get_blk_pic_idx(data)                               (0x0000007F&(data))
#define  CODEBLKREG_VE_ITDMA_blk_pic_idx_src(data)                               (0x0000007F&(data))

#define  CODEBLKREG_VE_CBP                                                       0x1800E308
#define  CODEBLKREG_VE_CBP_reg_addr                                              "0xB800E308"
#define  CODEBLKREG_VE_CBP_reg                                                   0xB800E308
#define  CODEBLKREG_VE_CBP_inst_addr                                             "0x002C"
#define  CODEBLKREG_VE_CBP_inst_adr                                              "0x00C2"
#define  CODEBLKREG_VE_CBP_inst                                                  0x00C2
#define  set_CODEBLKREG_VE_CBP_reg(data)                                         (*((volatile unsigned int*)CODEBLKREG_VE_CBP_reg)=data)
#define  get_CODEBLKREG_VE_CBP_reg                                               (*((volatile unsigned int*)CODEBLKREG_VE_CBP_reg))
#define  CODEBLKREG_VE_CBP_write_enable2_shift                                   (31)
#define  CODEBLKREG_VE_CBP_cbp6bits_shift                                        (25)
#define  CODEBLKREG_VE_CBP_write_enable1_shift                                   (24)
#define  CODEBLKREG_VE_CBP_subblkpat_shift                                       (0)
#define  CODEBLKREG_VE_CBP_write_enable2_mask                                    (0x80000000)
#define  CODEBLKREG_VE_CBP_cbp6bits_mask                                         (0x7E000000)
#define  CODEBLKREG_VE_CBP_write_enable1_mask                                    (0x01000000)
#define  CODEBLKREG_VE_CBP_subblkpat_mask                                        (0x00FFFFFF)
#define  CODEBLKREG_VE_CBP_write_enable2(data)                                   (0x80000000&((data)<<31))
#define  CODEBLKREG_VE_CBP_cbp6bits(data)                                        (0x7E000000&((data)<<25))
#define  CODEBLKREG_VE_CBP_write_enable1(data)                                   (0x01000000&((data)<<24))
#define  CODEBLKREG_VE_CBP_subblkpat(data)                                       (0x00FFFFFF&(data))
#define  CODEBLKREG_VE_CBP_get_write_enable2(data)                               ((0x80000000&(data))>>31)
#define  CODEBLKREG_VE_CBP_get_cbp6bits(data)                                    ((0x7E000000&(data))>>25)
#define  CODEBLKREG_VE_CBP_get_write_enable1(data)                               ((0x01000000&(data))>>24)
#define  CODEBLKREG_VE_CBP_get_subblkpat(data)                                   (0x00FFFFFF&(data))
#define  CODEBLKREG_VE_CBP_write_enable2_src(data)                               ((0x80000000&(data))>>31)
#define  CODEBLKREG_VE_CBP_cbp6bits_src(data)                                    ((0x7E000000&(data))>>25)
#define  CODEBLKREG_VE_CBP_write_enable1_src(data)                               ((0x01000000&(data))>>24)
#define  CODEBLKREG_VE_CBP_subblkpat_src(data)                                   (0x00FFFFFF&(data))

#define  CODEBLKREG_MB_PARTITION                                                 0x1800E30C
#define  CODEBLKREG_MB_PARTITION_reg_addr                                        "0xB800E30C"
#define  CODEBLKREG_MB_PARTITION_reg                                             0xB800E30C
#define  CODEBLKREG_MB_PARTITION_inst_addr                                       "0x002D"
#define  CODEBLKREG_MB_PARTITION_inst_adr                                        "0x00C3"
#define  CODEBLKREG_MB_PARTITION_inst                                            0x00C3
#define  set_CODEBLKREG_MB_PARTITION_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_MB_PARTITION_reg)=data)
#define  get_CODEBLKREG_MB_PARTITION_reg                                         (*((volatile unsigned int*)CODEBLKREG_MB_PARTITION_reg))
#define  CODEBLKREG_MB_PARTITION_mbpartition_shift                               (0)
#define  CODEBLKREG_MB_PARTITION_mbpartition_mask                                (0x000001FF)
#define  CODEBLKREG_MB_PARTITION_mbpartition(data)                               (0x000001FF&(data))
#define  CODEBLKREG_MB_PARTITION_get_mbpartition(data)                           (0x000001FF&(data))
#define  CODEBLKREG_MB_PARTITION_mbpartition_src(data)                           (0x000001FF&(data))

#define  CODEBLKREG_MB_PREDMODE                                                  0x1800E310
#define  CODEBLKREG_MB_PREDMODE_reg_addr                                         "0xB800E310"
#define  CODEBLKREG_MB_PREDMODE_reg                                              0xB800E310
#define  CODEBLKREG_MB_PREDMODE_inst_addr                                        "0x002E"
#define  CODEBLKREG_MB_PREDMODE_inst_adr                                         "0x00C4"
#define  CODEBLKREG_MB_PREDMODE_inst                                             0x00C4
#define  set_CODEBLKREG_MB_PREDMODE_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_MB_PREDMODE_reg)=data)
#define  get_CODEBLKREG_MB_PREDMODE_reg                                          (*((volatile unsigned int*)CODEBLKREG_MB_PREDMODE_reg))
#define  CODEBLKREG_MB_PREDMODE_mb_pred_mode_shift                               (0)
#define  CODEBLKREG_MB_PREDMODE_mb_pred_mode_mask                                (0x000000FF)
#define  CODEBLKREG_MB_PREDMODE_mb_pred_mode(data)                               (0x000000FF&(data))
#define  CODEBLKREG_MB_PREDMODE_get_mb_pred_mode(data)                           (0x000000FF&(data))
#define  CODEBLKREG_MB_PREDMODE_mb_pred_mode_src(data)                           (0x000000FF&(data))

#define  CODEBLKREG_MB_INFO                                                      0x1800E314
#define  CODEBLKREG_MB_INFO_reg_addr                                             "0xB800E314"
#define  CODEBLKREG_MB_INFO_reg                                                  0xB800E314
#define  CODEBLKREG_MB_INFO_inst_addr                                            "0x002F"
#define  CODEBLKREG_MB_INFO_inst_adr                                             "0x00C5"
#define  CODEBLKREG_MB_INFO_inst                                                 0x00C5
#define  set_CODEBLKREG_MB_INFO_reg(data)                                        (*((volatile unsigned int*)CODEBLKREG_MB_INFO_reg)=data)
#define  get_CODEBLKREG_MB_INFO_reg                                              (*((volatile unsigned int*)CODEBLKREG_MB_INFO_reg))
#define  CODEBLKREG_MB_INFO_write_enable9_shift                                  (31)
#define  CODEBLKREG_MB_INFO_vp9_lossless_shift                                   (30)
#define  CODEBLKREG_MB_INFO_write_enable8_shift                                  (29)
#define  CODEBLKREG_MB_INFO_vp6_ref_frame_shift                                  (27)
#define  CODEBLKREG_MB_INFO_write_enable7_shift                                  (26)
#define  CODEBLKREG_MB_INFO_mb_pattern_shift                                     (25)
#define  CODEBLKREG_MB_INFO_write_enable6_shift                                  (24)
#define  CODEBLKREG_MB_INFO_intrablks_flg_shift                                  (19)
#define  CODEBLKREG_MB_INFO_write_enable5_shift                                  (18)
#define  CODEBLKREG_MB_INFO_ac_pred_shift                                        (17)
#define  CODEBLKREG_MB_INFO_write_enable4_shift                                  (16)
#define  CODEBLKREG_MB_INFO_dc_pred_dir_shift                                    (10)
#define  CODEBLKREG_MB_INFO_write_enable3_shift                                  (9)
#define  CODEBLKREG_MB_INFO_mbtype_shift                                         (5)
#define  CODEBLKREG_MB_INFO_write_enable2_shift                                  (4)
#define  CODEBLKREG_MB_INFO_intra_c_pred_mode_shift                              (2)
#define  CODEBLKREG_MB_INFO_write_enable1_shift                                  (1)
#define  CODEBLKREG_MB_INFO_field_mb_shift                                       (0)
#define  CODEBLKREG_MB_INFO_write_enable9_mask                                   (0x80000000)
#define  CODEBLKREG_MB_INFO_vp9_lossless_mask                                    (0x40000000)
#define  CODEBLKREG_MB_INFO_write_enable8_mask                                   (0x20000000)
#define  CODEBLKREG_MB_INFO_vp6_ref_frame_mask                                   (0x18000000)
#define  CODEBLKREG_MB_INFO_write_enable7_mask                                   (0x04000000)
#define  CODEBLKREG_MB_INFO_mb_pattern_mask                                      (0x02000000)
#define  CODEBLKREG_MB_INFO_write_enable6_mask                                   (0x01000000)
#define  CODEBLKREG_MB_INFO_intrablks_flg_mask                                   (0x00F80000)
#define  CODEBLKREG_MB_INFO_write_enable5_mask                                   (0x00040000)
#define  CODEBLKREG_MB_INFO_ac_pred_mask                                         (0x00020000)
#define  CODEBLKREG_MB_INFO_write_enable4_mask                                   (0x00010000)
#define  CODEBLKREG_MB_INFO_dc_pred_dir_mask                                     (0x0000FC00)
#define  CODEBLKREG_MB_INFO_write_enable3_mask                                   (0x00000200)
#define  CODEBLKREG_MB_INFO_mbtype_mask                                          (0x000001E0)
#define  CODEBLKREG_MB_INFO_write_enable2_mask                                   (0x00000010)
#define  CODEBLKREG_MB_INFO_intra_c_pred_mode_mask                               (0x0000000C)
#define  CODEBLKREG_MB_INFO_write_enable1_mask                                   (0x00000002)
#define  CODEBLKREG_MB_INFO_field_mb_mask                                        (0x00000001)
#define  CODEBLKREG_MB_INFO_write_enable9(data)                                  (0x80000000&((data)<<31))
#define  CODEBLKREG_MB_INFO_vp9_lossless(data)                                   (0x40000000&((data)<<30))
#define  CODEBLKREG_MB_INFO_write_enable8(data)                                  (0x20000000&((data)<<29))
#define  CODEBLKREG_MB_INFO_vp6_ref_frame(data)                                  (0x18000000&((data)<<27))
#define  CODEBLKREG_MB_INFO_write_enable7(data)                                  (0x04000000&((data)<<26))
#define  CODEBLKREG_MB_INFO_mb_pattern(data)                                     (0x02000000&((data)<<25))
#define  CODEBLKREG_MB_INFO_write_enable6(data)                                  (0x01000000&((data)<<24))
#define  CODEBLKREG_MB_INFO_intrablks_flg(data)                                  (0x00F80000&((data)<<19))
#define  CODEBLKREG_MB_INFO_write_enable5(data)                                  (0x00040000&((data)<<18))
#define  CODEBLKREG_MB_INFO_ac_pred(data)                                        (0x00020000&((data)<<17))
#define  CODEBLKREG_MB_INFO_write_enable4(data)                                  (0x00010000&((data)<<16))
#define  CODEBLKREG_MB_INFO_dc_pred_dir(data)                                    (0x0000FC00&((data)<<10))
#define  CODEBLKREG_MB_INFO_write_enable3(data)                                  (0x00000200&((data)<<9))
#define  CODEBLKREG_MB_INFO_mbtype(data)                                         (0x000001E0&((data)<<5))
#define  CODEBLKREG_MB_INFO_write_enable2(data)                                  (0x00000010&((data)<<4))
#define  CODEBLKREG_MB_INFO_intra_c_pred_mode(data)                              (0x0000000C&((data)<<2))
#define  CODEBLKREG_MB_INFO_write_enable1(data)                                  (0x00000002&((data)<<1))
#define  CODEBLKREG_MB_INFO_field_mb(data)                                       (0x00000001&(data))
#define  CODEBLKREG_MB_INFO_get_write_enable9(data)                              ((0x80000000&(data))>>31)
#define  CODEBLKREG_MB_INFO_get_vp9_lossless(data)                               ((0x40000000&(data))>>30)
#define  CODEBLKREG_MB_INFO_get_write_enable8(data)                              ((0x20000000&(data))>>29)
#define  CODEBLKREG_MB_INFO_get_vp6_ref_frame(data)                              ((0x18000000&(data))>>27)
#define  CODEBLKREG_MB_INFO_get_write_enable7(data)                              ((0x04000000&(data))>>26)
#define  CODEBLKREG_MB_INFO_get_mb_pattern(data)                                 ((0x02000000&(data))>>25)
#define  CODEBLKREG_MB_INFO_get_write_enable6(data)                              ((0x01000000&(data))>>24)
#define  CODEBLKREG_MB_INFO_get_intrablks_flg(data)                              ((0x00F80000&(data))>>19)
#define  CODEBLKREG_MB_INFO_get_write_enable5(data)                              ((0x00040000&(data))>>18)
#define  CODEBLKREG_MB_INFO_get_ac_pred(data)                                    ((0x00020000&(data))>>17)
#define  CODEBLKREG_MB_INFO_get_write_enable4(data)                              ((0x00010000&(data))>>16)
#define  CODEBLKREG_MB_INFO_get_dc_pred_dir(data)                                ((0x0000FC00&(data))>>10)
#define  CODEBLKREG_MB_INFO_get_write_enable3(data)                              ((0x00000200&(data))>>9)
#define  CODEBLKREG_MB_INFO_get_mbtype(data)                                     ((0x000001E0&(data))>>5)
#define  CODEBLKREG_MB_INFO_get_write_enable2(data)                              ((0x00000010&(data))>>4)
#define  CODEBLKREG_MB_INFO_get_intra_c_pred_mode(data)                          ((0x0000000C&(data))>>2)
#define  CODEBLKREG_MB_INFO_get_write_enable1(data)                              ((0x00000002&(data))>>1)
#define  CODEBLKREG_MB_INFO_get_field_mb(data)                                   (0x00000001&(data))
#define  CODEBLKREG_MB_INFO_write_enable9_src(data)                              ((0x80000000&(data))>>31)
#define  CODEBLKREG_MB_INFO_vp9_lossless_src(data)                               ((0x40000000&(data))>>30)
#define  CODEBLKREG_MB_INFO_write_enable8_src(data)                              ((0x20000000&(data))>>29)
#define  CODEBLKREG_MB_INFO_vp6_ref_frame_src(data)                              ((0x18000000&(data))>>27)
#define  CODEBLKREG_MB_INFO_write_enable7_src(data)                              ((0x04000000&(data))>>26)
#define  CODEBLKREG_MB_INFO_mb_pattern_src(data)                                 ((0x02000000&(data))>>25)
#define  CODEBLKREG_MB_INFO_write_enable6_src(data)                              ((0x01000000&(data))>>24)
#define  CODEBLKREG_MB_INFO_intrablks_flg_src(data)                              ((0x00F80000&(data))>>19)
#define  CODEBLKREG_MB_INFO_write_enable5_src(data)                              ((0x00040000&(data))>>18)
#define  CODEBLKREG_MB_INFO_ac_pred_src(data)                                    ((0x00020000&(data))>>17)
#define  CODEBLKREG_MB_INFO_write_enable4_src(data)                              ((0x00010000&(data))>>16)
#define  CODEBLKREG_MB_INFO_dc_pred_dir_src(data)                                ((0x0000FC00&(data))>>10)
#define  CODEBLKREG_MB_INFO_write_enable3_src(data)                              ((0x00000200&(data))>>9)
#define  CODEBLKREG_MB_INFO_mbtype_src(data)                                     ((0x000001E0&(data))>>5)
#define  CODEBLKREG_MB_INFO_write_enable2_src(data)                              ((0x00000010&(data))>>4)
#define  CODEBLKREG_MB_INFO_intra_c_pred_mode_src(data)                          ((0x0000000C&(data))>>2)
#define  CODEBLKREG_MB_INFO_write_enable1_src(data)                              ((0x00000002&(data))>>1)
#define  CODEBLKREG_MB_INFO_field_mb_src(data)                                   (0x00000001&(data))

#define  CODEBLKREG_MB_INFO2                                                     0x1800E318
#define  CODEBLKREG_MB_INFO2_reg_addr                                            "0xB800E318"
#define  CODEBLKREG_MB_INFO2_reg                                                 0xB800E318
#define  CODEBLKREG_MB_INFO2_inst_addr                                           "0x0030"
#define  CODEBLKREG_MB_INFO2_inst_adr                                            "0x00C6"
#define  CODEBLKREG_MB_INFO2_inst                                                0x00C6
#define  set_CODEBLKREG_MB_INFO2_reg(data)                                       (*((volatile unsigned int*)CODEBLKREG_MB_INFO2_reg)=data)
#define  get_CODEBLKREG_MB_INFO2_reg                                             (*((volatile unsigned int*)CODEBLKREG_MB_INFO2_reg))
#define  CODEBLKREG_MB_INFO2_h263_flv_lg1_shift                                  (5)
#define  CODEBLKREG_MB_INFO2_ivf_shift                                           (4)
#define  CODEBLKREG_MB_INFO2_as_shift                                            (3)
#define  CODEBLKREG_MB_INFO2_intra_dc_vlc_shift                                  (2)
#define  CODEBLKREG_MB_INFO2_short_hdr_shift                                     (1)
#define  CODEBLKREG_MB_INFO2_write_data_shift                                    (0)
#define  CODEBLKREG_MB_INFO2_h263_flv_lg1_mask                                   (0x00000020)
#define  CODEBLKREG_MB_INFO2_ivf_mask                                            (0x00000010)
#define  CODEBLKREG_MB_INFO2_as_mask                                             (0x00000008)
#define  CODEBLKREG_MB_INFO2_intra_dc_vlc_mask                                   (0x00000004)
#define  CODEBLKREG_MB_INFO2_short_hdr_mask                                      (0x00000002)
#define  CODEBLKREG_MB_INFO2_write_data_mask                                     (0x00000001)
#define  CODEBLKREG_MB_INFO2_h263_flv_lg1(data)                                  (0x00000020&((data)<<5))
#define  CODEBLKREG_MB_INFO2_ivf(data)                                           (0x00000010&((data)<<4))
#define  CODEBLKREG_MB_INFO2_as(data)                                            (0x00000008&((data)<<3))
#define  CODEBLKREG_MB_INFO2_intra_dc_vlc(data)                                  (0x00000004&((data)<<2))
#define  CODEBLKREG_MB_INFO2_short_hdr(data)                                     (0x00000002&((data)<<1))
#define  CODEBLKREG_MB_INFO2_write_data(data)                                    (0x00000001&(data))
#define  CODEBLKREG_MB_INFO2_get_h263_flv_lg1(data)                              ((0x00000020&(data))>>5)
#define  CODEBLKREG_MB_INFO2_get_ivf(data)                                       ((0x00000010&(data))>>4)
#define  CODEBLKREG_MB_INFO2_get_as(data)                                        ((0x00000008&(data))>>3)
#define  CODEBLKREG_MB_INFO2_get_intra_dc_vlc(data)                              ((0x00000004&(data))>>2)
#define  CODEBLKREG_MB_INFO2_get_short_hdr(data)                                 ((0x00000002&(data))>>1)
#define  CODEBLKREG_MB_INFO2_get_write_data(data)                                (0x00000001&(data))
#define  CODEBLKREG_MB_INFO2_h263_flv_lg1_src(data)                              ((0x00000020&(data))>>5)
#define  CODEBLKREG_MB_INFO2_ivf_src(data)                                       ((0x00000010&(data))>>4)
#define  CODEBLKREG_MB_INFO2_as_src(data)                                        ((0x00000008&(data))>>3)
#define  CODEBLKREG_MB_INFO2_intra_dc_vlc_src(data)                              ((0x00000004&(data))>>2)
#define  CODEBLKREG_MB_INFO2_short_hdr_src(data)                                 ((0x00000002&(data))>>1)
#define  CODEBLKREG_MB_INFO2_write_data_src(data)                                (0x00000001&(data))

#define  CODEBLKREG_RV_CNTL                                                      0x1800E320
#define  CODEBLKREG_RV_CNTL_reg_addr                                             "0xB800E320"
#define  CODEBLKREG_RV_CNTL_reg                                                  0xB800E320
#define  CODEBLKREG_RV_CNTL_inst_addr                                            "0x0031"
#define  CODEBLKREG_RV_CNTL_inst_adr                                             "0x00C8"
#define  CODEBLKREG_RV_CNTL_inst                                                 0x00C8
#define  set_CODEBLKREG_RV_CNTL_reg(data)                                        (*((volatile unsigned int*)CODEBLKREG_RV_CNTL_reg)=data)
#define  get_CODEBLKREG_RV_CNTL_reg                                              (*((volatile unsigned int*)CODEBLKREG_RV_CNTL_reg))
#define  CODEBLKREG_RV_CNTL_write_enable2_shift                                  (4)
#define  CODEBLKREG_RV_CNTL_rv9_intramode_use_top_shift                          (3)
#define  CODEBLKREG_RV_CNTL_write_enable1_shift                                  (2)
#define  CODEBLKREG_RV_CNTL_rv_osvquant_shift                                    (0)
#define  CODEBLKREG_RV_CNTL_write_enable2_mask                                   (0x00000010)
#define  CODEBLKREG_RV_CNTL_rv9_intramode_use_top_mask                           (0x00000008)
#define  CODEBLKREG_RV_CNTL_write_enable1_mask                                   (0x00000004)
#define  CODEBLKREG_RV_CNTL_rv_osvquant_mask                                     (0x00000003)
#define  CODEBLKREG_RV_CNTL_write_enable2(data)                                  (0x00000010&((data)<<4))
#define  CODEBLKREG_RV_CNTL_rv9_intramode_use_top(data)                          (0x00000008&((data)<<3))
#define  CODEBLKREG_RV_CNTL_write_enable1(data)                                  (0x00000004&((data)<<2))
#define  CODEBLKREG_RV_CNTL_rv_osvquant(data)                                    (0x00000003&(data))
#define  CODEBLKREG_RV_CNTL_get_write_enable2(data)                              ((0x00000010&(data))>>4)
#define  CODEBLKREG_RV_CNTL_get_rv9_intramode_use_top(data)                      ((0x00000008&(data))>>3)
#define  CODEBLKREG_RV_CNTL_get_write_enable1(data)                              ((0x00000004&(data))>>2)
#define  CODEBLKREG_RV_CNTL_get_rv_osvquant(data)                                (0x00000003&(data))
#define  CODEBLKREG_RV_CNTL_write_enable2_src(data)                              ((0x00000010&(data))>>4)
#define  CODEBLKREG_RV_CNTL_rv9_intramode_use_top_src(data)                      ((0x00000008&(data))>>3)
#define  CODEBLKREG_RV_CNTL_write_enable1_src(data)                              ((0x00000004&(data))>>2)
#define  CODEBLKREG_RV_CNTL_rv_osvquant_src(data)                                (0x00000003&(data))

#define  CODEBLKREG_RV_STRUVLC                                                   0x1800E324
#define  CODEBLKREG_RV_STRUVLC_reg_addr                                          "0xB800E324"
#define  CODEBLKREG_RV_STRUVLC_reg                                               0xB800E324
#define  CODEBLKREG_RV_STRUVLC_inst_addr                                         "0x0032"
#define  CODEBLKREG_RV_STRUVLC_inst_adr                                          "0x00C9"
#define  CODEBLKREG_RV_STRUVLC_inst                                              0x00C9
#define  set_CODEBLKREG_RV_STRUVLC_reg(data)                                     (*((volatile unsigned int*)CODEBLKREG_RV_STRUVLC_reg)=data)
#define  get_CODEBLKREG_RV_STRUVLC_reg                                           (*((volatile unsigned int*)CODEBLKREG_RV_STRUVLC_reg))
#define  CODEBLKREG_RV_STRUVLC_struvlc_len_shift                                 (0)
#define  CODEBLKREG_RV_STRUVLC_struvlc_len_mask                                  (0x7FFFFFFF)
#define  CODEBLKREG_RV_STRUVLC_struvlc_len(data)                                 (0x7FFFFFFF&(data))
#define  CODEBLKREG_RV_STRUVLC_get_struvlc_len(data)                             (0x7FFFFFFF&(data))
#define  CODEBLKREG_RV_STRUVLC_struvlc_len_src(data)                             (0x7FFFFFFF&(data))

#define  CODEBLKREG_RV_INTRAMODE                                                 0x1800E328
#define  CODEBLKREG_RV_INTRAMODE_reg_addr                                        "0xB800E328"
#define  CODEBLKREG_RV_INTRAMODE_reg                                             0xB800E328
#define  CODEBLKREG_RV_INTRAMODE_inst_addr                                       "0x0033"
#define  CODEBLKREG_RV_INTRAMODE_inst_adr                                        "0x00CA"
#define  CODEBLKREG_RV_INTRAMODE_inst                                            0x00CA
#define  set_CODEBLKREG_RV_INTRAMODE_reg(data)                                   (*((volatile unsigned int*)CODEBLKREG_RV_INTRAMODE_reg)=data)
#define  get_CODEBLKREG_RV_INTRAMODE_reg                                         (*((volatile unsigned int*)CODEBLKREG_RV_INTRAMODE_reg))
#define  CODEBLKREG_RV_INTRAMODE_left_blocks_shift                               (0)
#define  CODEBLKREG_RV_INTRAMODE_left_blocks_mask                                (0x0000FFFF)
#define  CODEBLKREG_RV_INTRAMODE_left_blocks(data)                               (0x0000FFFF&(data))
#define  CODEBLKREG_RV_INTRAMODE_get_left_blocks(data)                           (0x0000FFFF&(data))
#define  CODEBLKREG_RV_INTRAMODE_left_blocks_src(data)                           (0x0000FFFF&(data))

#define  CODEBLKREG_VLDTBLPTR_0                                                  0x1800E330
#define  CODEBLKREG_VLDTBLPTR_0_reg_addr                                         "0xB800E330"
#define  CODEBLKREG_VLDTBLPTR_0_reg                                              0xB800E330
#define  CODEBLKREG_VLDTBLPTR_0_inst_addr                                        "0x0034"
#define  CODEBLKREG_VLDTBLPTR_0_inst_adr                                         "0x00CC"
#define  CODEBLKREG_VLDTBLPTR_0_inst                                             0x00CC
#define  set_CODEBLKREG_VLDTBLPTR_0_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VLDTBLPTR_0_reg)=data)
#define  get_CODEBLKREG_VLDTBLPTR_0_reg                                          (*((volatile unsigned int*)CODEBLKREG_VLDTBLPTR_0_reg))
#define  CODEBLKREG_VLDTBLPTR_write_enable4_shift                                (31)
#define  CODEBLKREG_VLDTBLPTR_jpg_dc_first_tbl_bits_shift                        (27)
#define  CODEBLKREG_VLDTBLPTR_write_enable3_shift                                (26)
#define  CODEBLKREG_VLDTBLPTR_jpg_dc_tbl_startaddr_shift                         (16)
#define  CODEBLKREG_VLDTBLPTR_write_enable2_shift                                (15)
#define  CODEBLKREG_VLDTBLPTR_first_tbl_bits_shift                               (11)
#define  CODEBLKREG_VLDTBLPTR_write_enable1_shift                                (10)
#define  CODEBLKREG_VLDTBLPTR_tbl_startaddr_shift                                (0)
#define  CODEBLKREG_VLDTBLPTR_write_enable4_mask                                 (0x80000000)
#define  CODEBLKREG_VLDTBLPTR_jpg_dc_first_tbl_bits_mask                         (0x78000000)
#define  CODEBLKREG_VLDTBLPTR_write_enable3_mask                                 (0x04000000)
#define  CODEBLKREG_VLDTBLPTR_jpg_dc_tbl_startaddr_mask                          (0x03FF0000)
#define  CODEBLKREG_VLDTBLPTR_write_enable2_mask                                 (0x00008000)
#define  CODEBLKREG_VLDTBLPTR_first_tbl_bits_mask                                (0x00007800)
#define  CODEBLKREG_VLDTBLPTR_write_enable1_mask                                 (0x00000400)
#define  CODEBLKREG_VLDTBLPTR_tbl_startaddr_mask                                 (0x000003FF)
#define  CODEBLKREG_VLDTBLPTR_write_enable4(data)                                (0x80000000&((data)<<31))
#define  CODEBLKREG_VLDTBLPTR_jpg_dc_first_tbl_bits(data)                        (0x78000000&((data)<<27))
#define  CODEBLKREG_VLDTBLPTR_write_enable3(data)                                (0x04000000&((data)<<26))
#define  CODEBLKREG_VLDTBLPTR_jpg_dc_tbl_startaddr(data)                         (0x03FF0000&((data)<<16))
#define  CODEBLKREG_VLDTBLPTR_write_enable2(data)                                (0x00008000&((data)<<15))
#define  CODEBLKREG_VLDTBLPTR_first_tbl_bits(data)                               (0x00007800&((data)<<11))
#define  CODEBLKREG_VLDTBLPTR_write_enable1(data)                                (0x00000400&((data)<<10))
#define  CODEBLKREG_VLDTBLPTR_tbl_startaddr(data)                                (0x000003FF&(data))
#define  CODEBLKREG_VLDTBLPTR_get_write_enable4(data)                            ((0x80000000&(data))>>31)
#define  CODEBLKREG_VLDTBLPTR_get_jpg_dc_first_tbl_bits(data)                    ((0x78000000&(data))>>27)
#define  CODEBLKREG_VLDTBLPTR_get_write_enable3(data)                            ((0x04000000&(data))>>26)
#define  CODEBLKREG_VLDTBLPTR_get_jpg_dc_tbl_startaddr(data)                     ((0x03FF0000&(data))>>16)
#define  CODEBLKREG_VLDTBLPTR_get_write_enable2(data)                            ((0x00008000&(data))>>15)
#define  CODEBLKREG_VLDTBLPTR_get_first_tbl_bits(data)                           ((0x00007800&(data))>>11)
#define  CODEBLKREG_VLDTBLPTR_get_write_enable1(data)                            ((0x00000400&(data))>>10)
#define  CODEBLKREG_VLDTBLPTR_get_tbl_startaddr(data)                            (0x000003FF&(data))
#define  CODEBLKREG_VLDTBLPTR_write_enable4_src(data)                            ((0x80000000&(data))>>31)
#define  CODEBLKREG_VLDTBLPTR_jpg_dc_first_tbl_bits_src(data)                    ((0x78000000&(data))>>27)
#define  CODEBLKREG_VLDTBLPTR_write_enable3_src(data)                            ((0x04000000&(data))>>26)
#define  CODEBLKREG_VLDTBLPTR_jpg_dc_tbl_startaddr_src(data)                     ((0x03FF0000&(data))>>16)
#define  CODEBLKREG_VLDTBLPTR_write_enable2_src(data)                            ((0x00008000&(data))>>15)
#define  CODEBLKREG_VLDTBLPTR_first_tbl_bits_src(data)                           ((0x00007800&(data))>>11)
#define  CODEBLKREG_VLDTBLPTR_write_enable1_src(data)                            ((0x00000400&(data))>>10)
#define  CODEBLKREG_VLDTBLPTR_tbl_startaddr_src(data)                            (0x000003FF&(data))

#define  CODEBLKREG_VLDTBLPTR_1                                                  0x1800E334
#define  CODEBLKREG_VLDTBLPTR_1_reg_addr                                         "0xB800E334"
#define  CODEBLKREG_VLDTBLPTR_1_reg                                              0xB800E334
#define  CODEBLKREG_VLDTBLPTR_1_inst_addr                                        "0x0035"
#define  CODEBLKREG_VLDTBLPTR_1_inst_adr                                         "0x00CD"
#define  CODEBLKREG_VLDTBLPTR_1_inst                                             0x00CD
#define  set_CODEBLKREG_VLDTBLPTR_1_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VLDTBLPTR_1_reg)=data)
#define  get_CODEBLKREG_VLDTBLPTR_1_reg                                          (*((volatile unsigned int*)CODEBLKREG_VLDTBLPTR_1_reg))

#define  CODEBLKREG_VLDESPPTR_0                                                  0x1800E340
#define  CODEBLKREG_VLDESPPTR_0_reg_addr                                         "0xB800E340"
#define  CODEBLKREG_VLDESPPTR_0_reg                                              0xB800E340
#define  CODEBLKREG_VLDESPPTR_0_inst_addr                                        "0x0036"
#define  CODEBLKREG_VLDESPPTR_0_inst_adr                                         "0x00D0"
#define  CODEBLKREG_VLDESPPTR_0_inst                                             0x00D0
#define  set_CODEBLKREG_VLDESPPTR_0_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VLDESPPTR_0_reg)=data)
#define  get_CODEBLKREG_VLDESPPTR_0_reg                                          (*((volatile unsigned int*)CODEBLKREG_VLDESPPTR_0_reg))
#define  CODEBLKREG_VLDESPPTR_tbl_espptr_saddr_shift                             (0)
#define  CODEBLKREG_VLDESPPTR_tbl_espptr_saddr_mask                              (0x000003FF)
#define  CODEBLKREG_VLDESPPTR_tbl_espptr_saddr(data)                             (0x000003FF&(data))
#define  CODEBLKREG_VLDESPPTR_get_tbl_espptr_saddr(data)                         (0x000003FF&(data))
#define  CODEBLKREG_VLDESPPTR_tbl_espptr_saddr_src(data)                         (0x000003FF&(data))

#define  CODEBLKREG_VLDESPPTR_1                                                  0x1800E344
#define  CODEBLKREG_VLDESPPTR_1_reg_addr                                         "0xB800E344"
#define  CODEBLKREG_VLDESPPTR_1_reg                                              0xB800E344
#define  CODEBLKREG_VLDESPPTR_1_inst_addr                                        "0x0037"
#define  CODEBLKREG_VLDESPPTR_1_inst_adr                                         "0x00D1"
#define  CODEBLKREG_VLDESPPTR_1_inst                                             0x00D1
#define  set_CODEBLKREG_VLDESPPTR_1_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VLDESPPTR_1_reg)=data)
#define  get_CODEBLKREG_VLDESPPTR_1_reg                                          (*((volatile unsigned int*)CODEBLKREG_VLDESPPTR_1_reg))

#define  CODEBLKREG_VLDESPPTR_2                                                  0x1800E348
#define  CODEBLKREG_VLDESPPTR_2_reg_addr                                         "0xB800E348"
#define  CODEBLKREG_VLDESPPTR_2_reg                                              0xB800E348
#define  CODEBLKREG_VLDESPPTR_2_inst_addr                                        "0x0038"
#define  CODEBLKREG_VLDESPPTR_2_inst_adr                                         "0x00D2"
#define  CODEBLKREG_VLDESPPTR_2_inst                                             0x00D2
#define  set_CODEBLKREG_VLDESPPTR_2_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VLDESPPTR_2_reg)=data)
#define  get_CODEBLKREG_VLDESPPTR_2_reg                                          (*((volatile unsigned int*)CODEBLKREG_VLDESPPTR_2_reg))

#define  CODEBLKREG_VLDESPPTR_3                                                  0x1800E34C
#define  CODEBLKREG_VLDESPPTR_3_reg_addr                                         "0xB800E34C"
#define  CODEBLKREG_VLDESPPTR_3_reg                                              0xB800E34C
#define  CODEBLKREG_VLDESPPTR_3_inst_addr                                        "0x0039"
#define  CODEBLKREG_VLDESPPTR_3_inst_adr                                         "0x00D3"
#define  CODEBLKREG_VLDESPPTR_3_inst                                             0x00D3
#define  set_CODEBLKREG_VLDESPPTR_3_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_VLDESPPTR_3_reg)=data)
#define  get_CODEBLKREG_VLDESPPTR_3_reg                                          (*((volatile unsigned int*)CODEBLKREG_VLDESPPTR_3_reg))

#define  CODEBLKREG_VE_ACDCP_LUMA                                                0x1800E350
#define  CODEBLKREG_VE_ACDCP_LUMA_reg_addr                                       "0xB800E350"
#define  CODEBLKREG_VE_ACDCP_LUMA_reg                                            0xB800E350
#define  CODEBLKREG_VE_ACDCP_LUMA_inst_addr                                      "0x003A"
#define  CODEBLKREG_VE_ACDCP_LUMA_inst_adr                                       "0x00D4"
#define  CODEBLKREG_VE_ACDCP_LUMA_inst                                           0x00D4
#define  set_CODEBLKREG_VE_ACDCP_LUMA_reg(data)                                  (*((volatile unsigned int*)CODEBLKREG_VE_ACDCP_LUMA_reg)=data)
#define  get_CODEBLKREG_VE_ACDCP_LUMA_reg                                        (*((volatile unsigned int*)CODEBLKREG_VE_ACDCP_LUMA_reg))
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_c_shift                                 (20)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_c_intra_shift                           (19)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_d_shift                                 (7)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_d_intra_shift                           (6)
#define  CODEBLKREG_VE_ACDCP_LUMA_dcstep_topmb_shift                             (0)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_c_mask                                  (0xFFF00000)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_c_intra_mask                            (0x00080000)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_d_mask                                  (0x0007FF80)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_d_intra_mask                            (0x00000040)
#define  CODEBLKREG_VE_ACDCP_LUMA_dcstep_topmb_mask                              (0x0000003F)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_c(data)                                 (0xFFF00000&((data)<<20))
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_c_intra(data)                           (0x00080000&((data)<<19))
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_d(data)                                 (0x0007FF80&((data)<<7))
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_d_intra(data)                           (0x00000040&((data)<<6))
#define  CODEBLKREG_VE_ACDCP_LUMA_dcstep_topmb(data)                             (0x0000003F&(data))
#define  CODEBLKREG_VE_ACDCP_LUMA_get_lumadc_c(data)                             ((0xFFF00000&(data))>>20)
#define  CODEBLKREG_VE_ACDCP_LUMA_get_lumadc_c_intra(data)                       ((0x00080000&(data))>>19)
#define  CODEBLKREG_VE_ACDCP_LUMA_get_lumadc_d(data)                             ((0x0007FF80&(data))>>7)
#define  CODEBLKREG_VE_ACDCP_LUMA_get_lumadc_d_intra(data)                       ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_ACDCP_LUMA_get_dcstep_topmb(data)                         (0x0000003F&(data))
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_c_src(data)                             ((0xFFF00000&(data))>>20)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_c_intra_src(data)                       ((0x00080000&(data))>>19)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_d_src(data)                             ((0x0007FF80&(data))>>7)
#define  CODEBLKREG_VE_ACDCP_LUMA_lumadc_d_intra_src(data)                       ((0x00000040&(data))>>6)
#define  CODEBLKREG_VE_ACDCP_LUMA_dcstep_topmb_src(data)                         (0x0000003F&(data))

#define  CODEBLKREG_VE_ACDCP_CHRO                                                0x1800E354
#define  CODEBLKREG_VE_ACDCP_CHRO_reg_addr                                       "0xB800E354"
#define  CODEBLKREG_VE_ACDCP_CHRO_reg                                            0xB800E354
#define  CODEBLKREG_VE_ACDCP_CHRO_inst_addr                                      "0x003B"
#define  CODEBLKREG_VE_ACDCP_CHRO_inst_adr                                       "0x00D5"
#define  CODEBLKREG_VE_ACDCP_CHRO_inst                                           0x00D5
#define  set_CODEBLKREG_VE_ACDCP_CHRO_reg(data)                                  (*((volatile unsigned int*)CODEBLKREG_VE_ACDCP_CHRO_reg)=data)
#define  get_CODEBLKREG_VE_ACDCP_CHRO_reg                                        (*((volatile unsigned int*)CODEBLKREG_VE_ACDCP_CHRO_reg))
#define  CODEBLKREG_VE_ACDCP_CHRO_cbdc_g_shift                                   (18)
#define  CODEBLKREG_VE_ACDCP_CHRO_crdc_g_shift                                   (6)
#define  CODEBLKREG_VE_ACDCP_CHRO_cbcr_intra_shift                               (5)
#define  CODEBLKREG_VE_ACDCP_CHRO_ch_dcstep_topmb_shift                          (0)
#define  CODEBLKREG_VE_ACDCP_CHRO_cbdc_g_mask                                    (0x3FFC0000)
#define  CODEBLKREG_VE_ACDCP_CHRO_crdc_g_mask                                    (0x0003FFC0)
#define  CODEBLKREG_VE_ACDCP_CHRO_cbcr_intra_mask                                (0x00000020)
#define  CODEBLKREG_VE_ACDCP_CHRO_ch_dcstep_topmb_mask                           (0x0000001F)
#define  CODEBLKREG_VE_ACDCP_CHRO_cbdc_g(data)                                   (0x3FFC0000&((data)<<18))
#define  CODEBLKREG_VE_ACDCP_CHRO_crdc_g(data)                                   (0x0003FFC0&((data)<<6))
#define  CODEBLKREG_VE_ACDCP_CHRO_cbcr_intra(data)                               (0x00000020&((data)<<5))
#define  CODEBLKREG_VE_ACDCP_CHRO_ch_dcstep_topmb(data)                          (0x0000001F&(data))
#define  CODEBLKREG_VE_ACDCP_CHRO_get_cbdc_g(data)                               ((0x3FFC0000&(data))>>18)
#define  CODEBLKREG_VE_ACDCP_CHRO_get_crdc_g(data)                               ((0x0003FFC0&(data))>>6)
#define  CODEBLKREG_VE_ACDCP_CHRO_get_cbcr_intra(data)                           ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_ACDCP_CHRO_get_ch_dcstep_topmb(data)                      (0x0000001F&(data))
#define  CODEBLKREG_VE_ACDCP_CHRO_cbdc_g_src(data)                               ((0x3FFC0000&(data))>>18)
#define  CODEBLKREG_VE_ACDCP_CHRO_crdc_g_src(data)                               ((0x0003FFC0&(data))>>6)
#define  CODEBLKREG_VE_ACDCP_CHRO_cbcr_intra_src(data)                           ((0x00000020&(data))>>5)
#define  CODEBLKREG_VE_ACDCP_CHRO_ch_dcstep_topmb_src(data)                      (0x0000001F&(data))

#define  CODEBLKREG_NDB_CTL                                                      0x1800E390
#define  CODEBLKREG_NDB_CTL_reg_addr                                             "0xB800E390"
#define  CODEBLKREG_NDB_CTL_reg                                                  0xB800E390
#define  CODEBLKREG_NDB_CTL_inst_addr                                            "0x003C"
#define  CODEBLKREG_NDB_CTL_inst_adr                                             "0x00E4"
#define  CODEBLKREG_NDB_CTL_inst                                                 0x00E4
#define  set_CODEBLKREG_NDB_CTL_reg(data)                                        (*((volatile unsigned int*)CODEBLKREG_NDB_CTL_reg)=data)
#define  get_CODEBLKREG_NDB_CTL_reg                                              (*((volatile unsigned int*)CODEBLKREG_NDB_CTL_reg))
#define  CODEBLKREG_NDB_CTL_write_enable3_shift                                  (5)
#define  CODEBLKREG_NDB_CTL_cavlc_halt_done_shift                                (4)
#define  CODEBLKREG_NDB_CTL_write_enable2_shift                                  (3)
#define  CODEBLKREG_NDB_CTL_cavlc_halt_shift                                     (2)
#define  CODEBLKREG_NDB_CTL_write_enable1_shift                                  (1)
#define  CODEBLKREG_NDB_CTL_postwrite_en_shift                                   (0)
#define  CODEBLKREG_NDB_CTL_write_enable3_mask                                   (0x00000020)
#define  CODEBLKREG_NDB_CTL_cavlc_halt_done_mask                                 (0x00000010)
#define  CODEBLKREG_NDB_CTL_write_enable2_mask                                   (0x00000008)
#define  CODEBLKREG_NDB_CTL_cavlc_halt_mask                                      (0x00000004)
#define  CODEBLKREG_NDB_CTL_write_enable1_mask                                   (0x00000002)
#define  CODEBLKREG_NDB_CTL_postwrite_en_mask                                    (0x00000001)
#define  CODEBLKREG_NDB_CTL_write_enable3(data)                                  (0x00000020&((data)<<5))
#define  CODEBLKREG_NDB_CTL_cavlc_halt_done(data)                                (0x00000010&((data)<<4))
#define  CODEBLKREG_NDB_CTL_write_enable2(data)                                  (0x00000008&((data)<<3))
#define  CODEBLKREG_NDB_CTL_cavlc_halt(data)                                     (0x00000004&((data)<<2))
#define  CODEBLKREG_NDB_CTL_write_enable1(data)                                  (0x00000002&((data)<<1))
#define  CODEBLKREG_NDB_CTL_postwrite_en(data)                                   (0x00000001&(data))
#define  CODEBLKREG_NDB_CTL_get_write_enable3(data)                              ((0x00000020&(data))>>5)
#define  CODEBLKREG_NDB_CTL_get_cavlc_halt_done(data)                            ((0x00000010&(data))>>4)
#define  CODEBLKREG_NDB_CTL_get_write_enable2(data)                              ((0x00000008&(data))>>3)
#define  CODEBLKREG_NDB_CTL_get_cavlc_halt(data)                                 ((0x00000004&(data))>>2)
#define  CODEBLKREG_NDB_CTL_get_write_enable1(data)                              ((0x00000002&(data))>>1)
#define  CODEBLKREG_NDB_CTL_get_postwrite_en(data)                               (0x00000001&(data))
#define  CODEBLKREG_NDB_CTL_write_enable3_src(data)                              ((0x00000020&(data))>>5)
#define  CODEBLKREG_NDB_CTL_cavlc_halt_done_src(data)                            ((0x00000010&(data))>>4)
#define  CODEBLKREG_NDB_CTL_write_enable2_src(data)                              ((0x00000008&(data))>>3)
#define  CODEBLKREG_NDB_CTL_cavlc_halt_src(data)                                 ((0x00000004&(data))>>2)
#define  CODEBLKREG_NDB_CTL_write_enable1_src(data)                              ((0x00000002&(data))>>1)
#define  CODEBLKREG_NDB_CTL_postwrite_en_src(data)                               (0x00000001&(data))

#define  CODEBLKREG_NDB_CAVLC_BASE                                               0x1800E3A8
#define  CODEBLKREG_NDB_CAVLC_BASE_reg_addr                                      "0xB800E3A8"
#define  CODEBLKREG_NDB_CAVLC_BASE_reg                                           0xB800E3A8
#define  CODEBLKREG_NDB_CAVLC_BASE_inst_addr                                     "0x003D"
#define  CODEBLKREG_NDB_CAVLC_BASE_inst_adr                                      "0x00EA"
#define  CODEBLKREG_NDB_CAVLC_BASE_inst                                          0x00EA
#define  set_CODEBLKREG_NDB_CAVLC_BASE_reg(data)                                 (*((volatile unsigned int*)CODEBLKREG_NDB_CAVLC_BASE_reg)=data)
#define  get_CODEBLKREG_NDB_CAVLC_BASE_reg                                       (*((volatile unsigned int*)CODEBLKREG_NDB_CAVLC_BASE_reg))
#define  CODEBLKREG_NDB_CAVLC_BASE_base_addr_shift                               (0)
#define  CODEBLKREG_NDB_CAVLC_BASE_base_addr_mask                                (0xFFFFFFFF)
#define  CODEBLKREG_NDB_CAVLC_BASE_base_addr(data)                               (0xFFFFFFFF&(data))
#define  CODEBLKREG_NDB_CAVLC_BASE_get_base_addr(data)                           (0xFFFFFFFF&(data))
#define  CODEBLKREG_NDB_CAVLC_BASE_base_addr_src(data)                           (0xFFFFFFFF&(data))

#define  CODEBLKREG_NDB_CAVLC_LIMIT                                              0x1800E3AC
#define  CODEBLKREG_NDB_CAVLC_LIMIT_reg_addr                                     "0xB800E3AC"
#define  CODEBLKREG_NDB_CAVLC_LIMIT_reg                                          0xB800E3AC
#define  CODEBLKREG_NDB_CAVLC_LIMIT_inst_addr                                    "0x003E"
#define  CODEBLKREG_NDB_CAVLC_LIMIT_inst_adr                                     "0x00EB"
#define  CODEBLKREG_NDB_CAVLC_LIMIT_inst                                         0x00EB
#define  set_CODEBLKREG_NDB_CAVLC_LIMIT_reg(data)                                (*((volatile unsigned int*)CODEBLKREG_NDB_CAVLC_LIMIT_reg)=data)
#define  get_CODEBLKREG_NDB_CAVLC_LIMIT_reg                                      (*((volatile unsigned int*)CODEBLKREG_NDB_CAVLC_LIMIT_reg))
#define  CODEBLKREG_NDB_CAVLC_LIMIT_limit_addr_shift                             (0)
#define  CODEBLKREG_NDB_CAVLC_LIMIT_limit_addr_mask                              (0xFFFFFFFF)
#define  CODEBLKREG_NDB_CAVLC_LIMIT_limit_addr(data)                             (0xFFFFFFFF&(data))
#define  CODEBLKREG_NDB_CAVLC_LIMIT_get_limit_addr(data)                         (0xFFFFFFFF&(data))
#define  CODEBLKREG_NDB_CAVLC_LIMIT_limit_addr_src(data)                         (0xFFFFFFFF&(data))

#define  CODEBLKREG_NDB_CAVLC_WPTR                                               0x1800E3B0
#define  CODEBLKREG_NDB_CAVLC_WPTR_reg_addr                                      "0xB800E3B0"
#define  CODEBLKREG_NDB_CAVLC_WPTR_reg                                           0xB800E3B0
#define  CODEBLKREG_NDB_CAVLC_WPTR_inst_addr                                     "0x003F"
#define  CODEBLKREG_NDB_CAVLC_WPTR_inst_adr                                      "0x00EC"
#define  CODEBLKREG_NDB_CAVLC_WPTR_inst                                          0x00EC
#define  set_CODEBLKREG_NDB_CAVLC_WPTR_reg(data)                                 (*((volatile unsigned int*)CODEBLKREG_NDB_CAVLC_WPTR_reg)=data)
#define  get_CODEBLKREG_NDB_CAVLC_WPTR_reg                                       (*((volatile unsigned int*)CODEBLKREG_NDB_CAVLC_WPTR_reg))
#define  CODEBLKREG_NDB_CAVLC_WPTR_wr_ptr_shift                                  (0)
#define  CODEBLKREG_NDB_CAVLC_WPTR_wr_ptr_mask                                   (0xFFFFFFFF)
#define  CODEBLKREG_NDB_CAVLC_WPTR_wr_ptr(data)                                  (0xFFFFFFFF&(data))
#define  CODEBLKREG_NDB_CAVLC_WPTR_get_wr_ptr(data)                              (0xFFFFFFFF&(data))
#define  CODEBLKREG_NDB_CAVLC_WPTR_wr_ptr_src(data)                              (0xFFFFFFFF&(data))

#define  CODEBLKREG_NDB_CAVLC_RPTR                                               0x1800E3B4
#define  CODEBLKREG_NDB_CAVLC_RPTR_reg_addr                                      "0xB800E3B4"
#define  CODEBLKREG_NDB_CAVLC_RPTR_reg                                           0xB800E3B4
#define  CODEBLKREG_NDB_CAVLC_RPTR_inst_addr                                     "0x0040"
#define  CODEBLKREG_NDB_CAVLC_RPTR_inst_adr                                      "0x00ED"
#define  CODEBLKREG_NDB_CAVLC_RPTR_inst                                          0x00ED
#define  set_CODEBLKREG_NDB_CAVLC_RPTR_reg(data)                                 (*((volatile unsigned int*)CODEBLKREG_NDB_CAVLC_RPTR_reg)=data)
#define  get_CODEBLKREG_NDB_CAVLC_RPTR_reg                                       (*((volatile unsigned int*)CODEBLKREG_NDB_CAVLC_RPTR_reg))
#define  CODEBLKREG_NDB_CAVLC_RPTR_rd_ptr_shift                                  (0)
#define  CODEBLKREG_NDB_CAVLC_RPTR_rd_ptr_mask                                   (0xFFFFFFFF)
#define  CODEBLKREG_NDB_CAVLC_RPTR_rd_ptr(data)                                  (0xFFFFFFFF&(data))
#define  CODEBLKREG_NDB_CAVLC_RPTR_get_rd_ptr(data)                              (0xFFFFFFFF&(data))
#define  CODEBLKREG_NDB_CAVLC_RPTR_rd_ptr_src(data)                              (0xFFFFFFFF&(data))

#define  CODEBLKREG_VP8_P3_FRM_MB1                                               0x1800E3F0
#define  CODEBLKREG_VP8_P3_FRM_MB1_reg_addr                                      "0xB800E3F0"
#define  CODEBLKREG_VP8_P3_FRM_MB1_reg                                           0xB800E3F0
#define  CODEBLKREG_VP8_P3_FRM_MB1_inst_addr                                     "0x0041"
#define  CODEBLKREG_VP8_P3_FRM_MB1_inst_adr                                      "0x00FC"
#define  CODEBLKREG_VP8_P3_FRM_MB1_inst                                          0x00FC
#define  set_CODEBLKREG_VP8_P3_FRM_MB1_reg(data)                                 (*((volatile unsigned int*)CODEBLKREG_VP8_P3_FRM_MB1_reg)=data)
#define  get_CODEBLKREG_VP8_P3_FRM_MB1_reg                                       (*((volatile unsigned int*)CODEBLKREG_VP8_P3_FRM_MB1_reg))
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable7_shift                           (25)
#define  CODEBLKREG_VP8_P3_FRM_MB1_segmentation_enabled_shift                    (24)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable6_shift                           (23)
#define  CODEBLKREG_VP8_P3_FRM_MB1_slice_cnt_shift                               (15)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable5_shift                           (14)
#define  CODEBLKREG_VP8_P3_FRM_MB1_uv_mode_shift                                 (12)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable4_shift                           (11)
#define  CODEBLKREG_VP8_P3_FRM_MB1_ref_frame_shift                               (9)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable3_shift                           (8)
#define  CODEBLKREG_VP8_P3_FRM_MB1_mode_shift                                    (4)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable2_shift                           (3)
#define  CODEBLKREG_VP8_P3_FRM_MB1_need_to_clamp_mvs_shift                       (2)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable1_shift                           (1)
#define  CODEBLKREG_VP8_P3_FRM_MB1_mb_skip_coeff_shift                           (0)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable7_mask                            (0x02000000)
#define  CODEBLKREG_VP8_P3_FRM_MB1_segmentation_enabled_mask                     (0x01000000)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable6_mask                            (0x00800000)
#define  CODEBLKREG_VP8_P3_FRM_MB1_slice_cnt_mask                                (0x007F8000)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable5_mask                            (0x00004000)
#define  CODEBLKREG_VP8_P3_FRM_MB1_uv_mode_mask                                  (0x00003000)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable4_mask                            (0x00000800)
#define  CODEBLKREG_VP8_P3_FRM_MB1_ref_frame_mask                                (0x00000600)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable3_mask                            (0x00000100)
#define  CODEBLKREG_VP8_P3_FRM_MB1_mode_mask                                     (0x000000F0)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable2_mask                            (0x00000008)
#define  CODEBLKREG_VP8_P3_FRM_MB1_need_to_clamp_mvs_mask                        (0x00000004)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable1_mask                            (0x00000002)
#define  CODEBLKREG_VP8_P3_FRM_MB1_mb_skip_coeff_mask                            (0x00000001)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable7(data)                           (0x02000000&((data)<<25))
#define  CODEBLKREG_VP8_P3_FRM_MB1_segmentation_enabled(data)                    (0x01000000&((data)<<24))
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable6(data)                           (0x00800000&((data)<<23))
#define  CODEBLKREG_VP8_P3_FRM_MB1_slice_cnt(data)                               (0x007F8000&((data)<<15))
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable5(data)                           (0x00004000&((data)<<14))
#define  CODEBLKREG_VP8_P3_FRM_MB1_uv_mode(data)                                 (0x00003000&((data)<<12))
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable4(data)                           (0x00000800&((data)<<11))
#define  CODEBLKREG_VP8_P3_FRM_MB1_ref_frame(data)                               (0x00000600&((data)<<9))
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable3(data)                           (0x00000100&((data)<<8))
#define  CODEBLKREG_VP8_P3_FRM_MB1_mode(data)                                    (0x000000F0&((data)<<4))
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable2(data)                           (0x00000008&((data)<<3))
#define  CODEBLKREG_VP8_P3_FRM_MB1_need_to_clamp_mvs(data)                       (0x00000004&((data)<<2))
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable1(data)                           (0x00000002&((data)<<1))
#define  CODEBLKREG_VP8_P3_FRM_MB1_mb_skip_coeff(data)                           (0x00000001&(data))
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_write_enable7(data)                       ((0x02000000&(data))>>25)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_segmentation_enabled(data)                ((0x01000000&(data))>>24)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_write_enable6(data)                       ((0x00800000&(data))>>23)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_slice_cnt(data)                           ((0x007F8000&(data))>>15)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_write_enable5(data)                       ((0x00004000&(data))>>14)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_uv_mode(data)                             ((0x00003000&(data))>>12)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_write_enable4(data)                       ((0x00000800&(data))>>11)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_ref_frame(data)                           ((0x00000600&(data))>>9)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_write_enable3(data)                       ((0x00000100&(data))>>8)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_mode(data)                                ((0x000000F0&(data))>>4)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_write_enable2(data)                       ((0x00000008&(data))>>3)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_need_to_clamp_mvs(data)                   ((0x00000004&(data))>>2)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_write_enable1(data)                       ((0x00000002&(data))>>1)
#define  CODEBLKREG_VP8_P3_FRM_MB1_get_mb_skip_coeff(data)                       (0x00000001&(data))
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable7_src(data)                       ((0x02000000&(data))>>25)
#define  CODEBLKREG_VP8_P3_FRM_MB1_segmentation_enabled_src(data)                ((0x01000000&(data))>>24)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable6_src(data)                       ((0x00800000&(data))>>23)
#define  CODEBLKREG_VP8_P3_FRM_MB1_slice_cnt_src(data)                           ((0x007F8000&(data))>>15)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable5_src(data)                       ((0x00004000&(data))>>14)
#define  CODEBLKREG_VP8_P3_FRM_MB1_uv_mode_src(data)                             ((0x00003000&(data))>>12)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable4_src(data)                       ((0x00000800&(data))>>11)
#define  CODEBLKREG_VP8_P3_FRM_MB1_ref_frame_src(data)                           ((0x00000600&(data))>>9)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable3_src(data)                       ((0x00000100&(data))>>8)
#define  CODEBLKREG_VP8_P3_FRM_MB1_mode_src(data)                                ((0x000000F0&(data))>>4)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable2_src(data)                       ((0x00000008&(data))>>3)
#define  CODEBLKREG_VP8_P3_FRM_MB1_need_to_clamp_mvs_src(data)                   ((0x00000004&(data))>>2)
#define  CODEBLKREG_VP8_P3_FRM_MB1_write_enable1_src(data)                       ((0x00000002&(data))>>1)
#define  CODEBLKREG_VP8_P3_FRM_MB1_mb_skip_coeff_src(data)                       (0x00000001&(data))

#define  CODEBLKREG_VP8_P3_MB2                                                   0x1800E3F4
#define  CODEBLKREG_VP8_P3_MB2_reg_addr                                          "0xB800E3F4"
#define  CODEBLKREG_VP8_P3_MB2_reg                                               0xB800E3F4
#define  CODEBLKREG_VP8_P3_MB2_inst_addr                                         "0x0042"
#define  CODEBLKREG_VP8_P3_MB2_inst_adr                                          "0x00FD"
#define  CODEBLKREG_VP8_P3_MB2_inst                                              0x00FD
#define  set_CODEBLKREG_VP8_P3_MB2_reg(data)                                     (*((volatile unsigned int*)CODEBLKREG_VP8_P3_MB2_reg)=data)
#define  get_CODEBLKREG_VP8_P3_MB2_reg                                           (*((volatile unsigned int*)CODEBLKREG_VP8_P3_MB2_reg))
#define  CODEBLKREG_VP8_P3_MB2_vp8_p3_curmb_shift                                (0)
#define  CODEBLKREG_VP8_P3_MB2_vp8_p3_curmb_mask                                 (0x000001FF)
#define  CODEBLKREG_VP8_P3_MB2_vp8_p3_curmb(data)                                (0x000001FF&(data))
#define  CODEBLKREG_VP8_P3_MB2_get_vp8_p3_curmb(data)                            (0x000001FF&(data))
#define  CODEBLKREG_VP8_P3_MB2_vp8_p3_curmb_src(data)                            (0x000001FF&(data))

#define  CODEBLKREG_VP8_BAC                                                      0x1800E3F8
#define  CODEBLKREG_VP8_BAC_reg_addr                                             "0xB800E3F8"
#define  CODEBLKREG_VP8_BAC_reg                                                  0xB800E3F8
#define  CODEBLKREG_VP8_BAC_inst_addr                                            "0x0043"
#define  CODEBLKREG_VP8_BAC_inst_adr                                             "0x00FE"
#define  CODEBLKREG_VP8_BAC_inst                                                 0x00FE
#define  set_CODEBLKREG_VP8_BAC_reg(data)                                        (*((volatile unsigned int*)CODEBLKREG_VP8_BAC_reg)=data)
#define  get_CODEBLKREG_VP8_BAC_reg                                              (*((volatile unsigned int*)CODEBLKREG_VP8_BAC_reg))
#define  CODEBLKREG_VP8_BAC_high_shift                                           (20)
#define  CODEBLKREG_VP8_BAC_bits_shift                                           (16)
#define  CODEBLKREG_VP8_BAC_code_word_shift                                      (0)
#define  CODEBLKREG_VP8_BAC_high_mask                                            (0x1FF00000)
#define  CODEBLKREG_VP8_BAC_bits_mask                                            (0x000F0000)
#define  CODEBLKREG_VP8_BAC_code_word_mask                                       (0x0000FFFF)
#define  CODEBLKREG_VP8_BAC_high(data)                                           (0x1FF00000&((data)<<20))
#define  CODEBLKREG_VP8_BAC_bits(data)                                           (0x000F0000&((data)<<16))
#define  CODEBLKREG_VP8_BAC_code_word(data)                                      (0x0000FFFF&(data))
#define  CODEBLKREG_VP8_BAC_get_high(data)                                       ((0x1FF00000&(data))>>20)
#define  CODEBLKREG_VP8_BAC_get_bits(data)                                       ((0x000F0000&(data))>>16)
#define  CODEBLKREG_VP8_BAC_get_code_word(data)                                  (0x0000FFFF&(data))
#define  CODEBLKREG_VP8_BAC_high_src(data)                                       ((0x1FF00000&(data))>>20)
#define  CODEBLKREG_VP8_BAC_bits_src(data)                                       ((0x000F0000&(data))>>16)
#define  CODEBLKREG_VP8_BAC_code_word_src(data)                                  (0x0000FFFF&(data))

#define  CODEBLKREG_SDE_P3_HEVC                                                  0x1800E090
#define  CODEBLKREG_SDE_P3_HEVC_reg_addr                                         "0xB800E090"
#define  CODEBLKREG_SDE_P3_HEVC_reg                                              0xB800E090
#define  CODEBLKREG_SDE_P3_HEVC_inst_addr                                        "0x0044"
#define  CODEBLKREG_SDE_P3_HEVC_inst_adr                                         "0x0024"
#define  CODEBLKREG_SDE_P3_HEVC_inst                                             0x0024
#define  set_CODEBLKREG_SDE_P3_HEVC_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_SDE_P3_HEVC_reg)=data)
#define  get_CODEBLKREG_SDE_P3_HEVC_reg                                          (*((volatile unsigned int*)CODEBLKREG_SDE_P3_HEVC_reg))
#define  CODEBLKREG_SDE_P3_HEVC_dec_ctb_max_cycle_shift                          (12)
#define  CODEBLKREG_SDE_P3_HEVC_dec_ctb_cycle_chken_shift                        (11)
#define  CODEBLKREG_SDE_P3_HEVC_pcm_bit_depth_chroma_shift                       (7)
#define  CODEBLKREG_SDE_P3_HEVC_pcm_bit_depth_luma_shift                         (3)
#define  CODEBLKREG_SDE_P3_HEVC_transform_skip_enabled_flag_shift                (2)
#define  CODEBLKREG_SDE_P3_HEVC_transquant_bypass_enable_flag_shift              (1)
#define  CODEBLKREG_SDE_P3_HEVC_sign_data_hiding_flag_shift                      (0)
#define  CODEBLKREG_SDE_P3_HEVC_dec_ctb_max_cycle_mask                           (0x000FF000)
#define  CODEBLKREG_SDE_P3_HEVC_dec_ctb_cycle_chken_mask                         (0x00000800)
#define  CODEBLKREG_SDE_P3_HEVC_pcm_bit_depth_chroma_mask                        (0x00000780)
#define  CODEBLKREG_SDE_P3_HEVC_pcm_bit_depth_luma_mask                          (0x00000078)
#define  CODEBLKREG_SDE_P3_HEVC_transform_skip_enabled_flag_mask                 (0x00000004)
#define  CODEBLKREG_SDE_P3_HEVC_transquant_bypass_enable_flag_mask               (0x00000002)
#define  CODEBLKREG_SDE_P3_HEVC_sign_data_hiding_flag_mask                       (0x00000001)
#define  CODEBLKREG_SDE_P3_HEVC_dec_ctb_max_cycle(data)                          (0x000FF000&((data)<<12))
#define  CODEBLKREG_SDE_P3_HEVC_dec_ctb_cycle_chken(data)                        (0x00000800&((data)<<11))
#define  CODEBLKREG_SDE_P3_HEVC_pcm_bit_depth_chroma(data)                       (0x00000780&((data)<<7))
#define  CODEBLKREG_SDE_P3_HEVC_pcm_bit_depth_luma(data)                         (0x00000078&((data)<<3))
#define  CODEBLKREG_SDE_P3_HEVC_transform_skip_enabled_flag(data)                (0x00000004&((data)<<2))
#define  CODEBLKREG_SDE_P3_HEVC_transquant_bypass_enable_flag(data)              (0x00000002&((data)<<1))
#define  CODEBLKREG_SDE_P3_HEVC_sign_data_hiding_flag(data)                      (0x00000001&(data))
#define  CODEBLKREG_SDE_P3_HEVC_get_dec_ctb_max_cycle(data)                      ((0x000FF000&(data))>>12)
#define  CODEBLKREG_SDE_P3_HEVC_get_dec_ctb_cycle_chken(data)                    ((0x00000800&(data))>>11)
#define  CODEBLKREG_SDE_P3_HEVC_get_pcm_bit_depth_chroma(data)                   ((0x00000780&(data))>>7)
#define  CODEBLKREG_SDE_P3_HEVC_get_pcm_bit_depth_luma(data)                     ((0x00000078&(data))>>3)
#define  CODEBLKREG_SDE_P3_HEVC_get_transform_skip_enabled_flag(data)            ((0x00000004&(data))>>2)
#define  CODEBLKREG_SDE_P3_HEVC_get_transquant_bypass_enable_flag(data)          ((0x00000002&(data))>>1)
#define  CODEBLKREG_SDE_P3_HEVC_get_sign_data_hiding_flag(data)                  (0x00000001&(data))
#define  CODEBLKREG_SDE_P3_HEVC_dec_ctb_max_cycle_src(data)                      ((0x000FF000&(data))>>12)
#define  CODEBLKREG_SDE_P3_HEVC_dec_ctb_cycle_chken_src(data)                    ((0x00000800&(data))>>11)
#define  CODEBLKREG_SDE_P3_HEVC_pcm_bit_depth_chroma_src(data)                   ((0x00000780&(data))>>7)
#define  CODEBLKREG_SDE_P3_HEVC_pcm_bit_depth_luma_src(data)                     ((0x00000078&(data))>>3)
#define  CODEBLKREG_SDE_P3_HEVC_transform_skip_enabled_flag_src(data)            ((0x00000004&(data))>>2)
#define  CODEBLKREG_SDE_P3_HEVC_transquant_bypass_enable_flag_src(data)          ((0x00000002&(data))>>1)
#define  CODEBLKREG_SDE_P3_HEVC_sign_data_hiding_flag_src(data)                  (0x00000001&(data))

#define  CODEBLKREG_HEVC_LDQMEM                                                  0x1800E094
#define  CODEBLKREG_HEVC_LDQMEM_reg_addr                                         "0xB800E094"
#define  CODEBLKREG_HEVC_LDQMEM_reg                                              0xB800E094
#define  CODEBLKREG_HEVC_LDQMEM_inst_addr                                        "0x0045"
#define  CODEBLKREG_HEVC_LDQMEM_inst_adr                                         "0x0025"
#define  CODEBLKREG_HEVC_LDQMEM_inst                                             0x0025
#define  set_CODEBLKREG_HEVC_LDQMEM_reg(data)                                    (*((volatile unsigned int*)CODEBLKREG_HEVC_LDQMEM_reg)=data)
#define  get_CODEBLKREG_HEVC_LDQMEM_reg                                          (*((volatile unsigned int*)CODEBLKREG_HEVC_LDQMEM_reg))
#define  CODEBLKREG_HEVC_LDQMEM_start_trigger_shift                              (6)
#define  CODEBLKREG_HEVC_LDQMEM_group_cnt_shift                                  (3)
#define  CODEBLKREG_HEVC_LDQMEM_start_group_shift                                (0)
#define  CODEBLKREG_HEVC_LDQMEM_start_trigger_mask                               (0x00000040)
#define  CODEBLKREG_HEVC_LDQMEM_group_cnt_mask                                   (0x00000038)
#define  CODEBLKREG_HEVC_LDQMEM_start_group_mask                                 (0x00000007)
#define  CODEBLKREG_HEVC_LDQMEM_start_trigger(data)                              (0x00000040&((data)<<6))
#define  CODEBLKREG_HEVC_LDQMEM_group_cnt(data)                                  (0x00000038&((data)<<3))
#define  CODEBLKREG_HEVC_LDQMEM_start_group(data)                                (0x00000007&(data))
#define  CODEBLKREG_HEVC_LDQMEM_get_start_trigger(data)                          ((0x00000040&(data))>>6)
#define  CODEBLKREG_HEVC_LDQMEM_get_group_cnt(data)                              ((0x00000038&(data))>>3)
#define  CODEBLKREG_HEVC_LDQMEM_get_start_group(data)                            (0x00000007&(data))
#define  CODEBLKREG_HEVC_LDQMEM_start_trigger_src(data)                          ((0x00000040&(data))>>6)
#define  CODEBLKREG_HEVC_LDQMEM_group_cnt_src(data)                              ((0x00000038&(data))>>3)
#define  CODEBLKREG_HEVC_LDQMEM_start_group_src(data)                            (0x00000007&(data))

#define  CODEBLKREG_P3_VP9_PIC_LEVEL                                             0x1800E260
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_reg_addr                                    "0xB800E260"
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_reg                                         0xB800E260
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_inst_addr                                   "0x0046"
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_inst_adr                                    "0x0098"
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_inst                                        0x0098
#define  set_CODEBLKREG_P3_VP9_PIC_LEVEL_reg(data)                               (*((volatile unsigned int*)CODEBLKREG_P3_VP9_PIC_LEVEL_reg)=data)
#define  get_CODEBLKREG_P3_VP9_PIC_LEVEL_reg                                     (*((volatile unsigned int*)CODEBLKREG_P3_VP9_PIC_LEVEL_reg))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_reference_mode_shift                        (30)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_enable_shift                            (29)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_update_map_shift                        (28)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_0_mask_skip_shift                    (27)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_1_mask_skip_shift                    (26)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_2_mask_skip_shift                    (25)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_3_mask_skip_shift                    (24)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_4_mask_skip_shift                    (23)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_5_mask_skip_shift                    (22)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_6_mask_skip_shift                    (21)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_7_mask_skip_shift                    (20)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_subsampling_x_shift                         (19)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_subsampling_y_shift                         (18)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_intra_only_shift                            (17)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_interp_filter_shift                         (14)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_ref_frame_sign_bias_shift                   (10)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_tx_mode_shift                               (7)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_var_ref_1_shift                        (5)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_var_ref_0_shift                        (3)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_fixed_ref_shift                        (1)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_vp9_bit_high_shift                          (0)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_reference_mode_mask                         (0xC0000000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_enable_mask                             (0x20000000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_update_map_mask                         (0x10000000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_0_mask_skip_mask                     (0x08000000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_1_mask_skip_mask                     (0x04000000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_2_mask_skip_mask                     (0x02000000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_3_mask_skip_mask                     (0x01000000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_4_mask_skip_mask                     (0x00800000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_5_mask_skip_mask                     (0x00400000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_6_mask_skip_mask                     (0x00200000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_7_mask_skip_mask                     (0x00100000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_subsampling_x_mask                          (0x00080000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_subsampling_y_mask                          (0x00040000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_intra_only_mask                             (0x00020000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_interp_filter_mask                          (0x0001C000)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_ref_frame_sign_bias_mask                    (0x00003C00)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_tx_mode_mask                                (0x00000380)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_var_ref_1_mask                         (0x00000060)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_var_ref_0_mask                         (0x00000018)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_fixed_ref_mask                         (0x00000006)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_vp9_bit_high_mask                           (0x00000001)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_reference_mode(data)                        (0xC0000000&((data)<<30))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_enable(data)                            (0x20000000&((data)<<29))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_update_map(data)                        (0x10000000&((data)<<28))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_0_mask_skip(data)                    (0x08000000&((data)<<27))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_1_mask_skip(data)                    (0x04000000&((data)<<26))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_2_mask_skip(data)                    (0x02000000&((data)<<25))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_3_mask_skip(data)                    (0x01000000&((data)<<24))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_4_mask_skip(data)                    (0x00800000&((data)<<23))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_5_mask_skip(data)                    (0x00400000&((data)<<22))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_6_mask_skip(data)                    (0x00200000&((data)<<21))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_7_mask_skip(data)                    (0x00100000&((data)<<20))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_subsampling_x(data)                         (0x00080000&((data)<<19))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_subsampling_y(data)                         (0x00040000&((data)<<18))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_intra_only(data)                            (0x00020000&((data)<<17))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_interp_filter(data)                         (0x0001C000&((data)<<14))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_ref_frame_sign_bias(data)                   (0x00003C00&((data)<<10))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_tx_mode(data)                               (0x00000380&((data)<<7))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_var_ref_1(data)                        (0x00000060&((data)<<5))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_var_ref_0(data)                        (0x00000018&((data)<<3))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_fixed_ref(data)                        (0x00000006&((data)<<1))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_vp9_bit_high(data)                          (0x00000001&(data))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_reference_mode(data)                    ((0xC0000000&(data))>>30)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_enable(data)                        ((0x20000000&(data))>>29)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_update_map(data)                    ((0x10000000&(data))>>28)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_id_0_mask_skip(data)                ((0x08000000&(data))>>27)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_id_1_mask_skip(data)                ((0x04000000&(data))>>26)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_id_2_mask_skip(data)                ((0x02000000&(data))>>25)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_id_3_mask_skip(data)                ((0x01000000&(data))>>24)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_id_4_mask_skip(data)                ((0x00800000&(data))>>23)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_id_5_mask_skip(data)                ((0x00400000&(data))>>22)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_id_6_mask_skip(data)                ((0x00200000&(data))>>21)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_seg_id_7_mask_skip(data)                ((0x00100000&(data))>>20)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_subsampling_x(data)                     ((0x00080000&(data))>>19)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_subsampling_y(data)                     ((0x00040000&(data))>>18)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_intra_only(data)                        ((0x00020000&(data))>>17)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_interp_filter(data)                     ((0x0001C000&(data))>>14)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_ref_frame_sign_bias(data)               ((0x00003C00&(data))>>10)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_tx_mode(data)                           ((0x00000380&(data))>>7)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_comp_var_ref_1(data)                    ((0x00000060&(data))>>5)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_comp_var_ref_0(data)                    ((0x00000018&(data))>>3)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_comp_fixed_ref(data)                    ((0x00000006&(data))>>1)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_get_vp9_bit_high(data)                      (0x00000001&(data))
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_reference_mode_src(data)                    ((0xC0000000&(data))>>30)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_enable_src(data)                        ((0x20000000&(data))>>29)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_update_map_src(data)                    ((0x10000000&(data))>>28)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_0_mask_skip_src(data)                ((0x08000000&(data))>>27)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_1_mask_skip_src(data)                ((0x04000000&(data))>>26)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_2_mask_skip_src(data)                ((0x02000000&(data))>>25)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_3_mask_skip_src(data)                ((0x01000000&(data))>>24)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_4_mask_skip_src(data)                ((0x00800000&(data))>>23)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_5_mask_skip_src(data)                ((0x00400000&(data))>>22)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_6_mask_skip_src(data)                ((0x00200000&(data))>>21)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_seg_id_7_mask_skip_src(data)                ((0x00100000&(data))>>20)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_subsampling_x_src(data)                     ((0x00080000&(data))>>19)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_subsampling_y_src(data)                     ((0x00040000&(data))>>18)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_intra_only_src(data)                        ((0x00020000&(data))>>17)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_interp_filter_src(data)                     ((0x0001C000&(data))>>14)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_ref_frame_sign_bias_src(data)               ((0x00003C00&(data))>>10)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_tx_mode_src(data)                           ((0x00000380&(data))>>7)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_var_ref_1_src(data)                    ((0x00000060&(data))>>5)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_var_ref_0_src(data)                    ((0x00000018&(data))>>3)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_comp_fixed_ref_src(data)                    ((0x00000006&(data))>>1)
#define  CODEBLKREG_P3_VP9_PIC_LEVEL_vp9_bit_high_src(data)                      (0x00000001&(data))

#define  CODEBLKREG_P3_VP9_FRM_LEVEL                                             0x1800E264
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_reg_addr                                    "0xB800E264"
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_reg                                         0xB800E264
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_inst_addr                                   "0x0047"
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_inst_adr                                    "0x0099"
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_inst                                        0x0099
#define  set_CODEBLKREG_P3_VP9_FRM_LEVEL_reg(data)                               (*((volatile unsigned int*)CODEBLKREG_P3_VP9_FRM_LEVEL_reg)=data)
#define  get_CODEBLKREG_P3_VP9_FRM_LEVEL_reg                                     (*((volatile unsigned int*)CODEBLKREG_P3_VP9_FRM_LEVEL_reg))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id0_data_ref_frame_shift                (29)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id1_data_ref_frame_shift                (26)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id2_data_ref_frame_shift                (23)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id3_data_ref_frame_shift                (20)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id4_data_ref_frame_shift                (17)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id5_data_ref_frame_shift                (14)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id6_data_ref_frame_shift                (11)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id7_data_ref_frame_shift                (8)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id0_mask_ref_frame_shift                (7)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id1_mask_ref_frame_shift                (6)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id2_mask_ref_frame_shift                (5)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id3_mask_ref_frame_shift                (4)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id4_mask_ref_frame_shift                (3)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id5_mask_ref_frame_shift                (2)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id6_mask_ref_frame_shift                (1)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id7_mask_ref_frame_shift                (0)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id0_data_ref_frame_mask                 (0xE0000000)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id1_data_ref_frame_mask                 (0x1C000000)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id2_data_ref_frame_mask                 (0x03800000)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id3_data_ref_frame_mask                 (0x00700000)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id4_data_ref_frame_mask                 (0x000E0000)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id5_data_ref_frame_mask                 (0x0001C000)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id6_data_ref_frame_mask                 (0x00003800)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id7_data_ref_frame_mask                 (0x00000700)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id0_mask_ref_frame_mask                 (0x00000080)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id1_mask_ref_frame_mask                 (0x00000040)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id2_mask_ref_frame_mask                 (0x00000020)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id3_mask_ref_frame_mask                 (0x00000010)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id4_mask_ref_frame_mask                 (0x00000008)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id5_mask_ref_frame_mask                 (0x00000004)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id6_mask_ref_frame_mask                 (0x00000002)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id7_mask_ref_frame_mask                 (0x00000001)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id0_data_ref_frame(data)                (0xE0000000&((data)<<29))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id1_data_ref_frame(data)                (0x1C000000&((data)<<26))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id2_data_ref_frame(data)                (0x03800000&((data)<<23))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id3_data_ref_frame(data)                (0x00700000&((data)<<20))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id4_data_ref_frame(data)                (0x000E0000&((data)<<17))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id5_data_ref_frame(data)                (0x0001C000&((data)<<14))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id6_data_ref_frame(data)                (0x00003800&((data)<<11))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id7_data_ref_frame(data)                (0x00000700&((data)<<8))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id0_mask_ref_frame(data)                (0x00000080&((data)<<7))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id1_mask_ref_frame(data)                (0x00000040&((data)<<6))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id2_mask_ref_frame(data)                (0x00000020&((data)<<5))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id3_mask_ref_frame(data)                (0x00000010&((data)<<4))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id4_mask_ref_frame(data)                (0x00000008&((data)<<3))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id5_mask_ref_frame(data)                (0x00000004&((data)<<2))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id6_mask_ref_frame(data)                (0x00000002&((data)<<1))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id7_mask_ref_frame(data)                (0x00000001&(data))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id0_data_ref_frame(data)            ((0xE0000000&(data))>>29)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id1_data_ref_frame(data)            ((0x1C000000&(data))>>26)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id2_data_ref_frame(data)            ((0x03800000&(data))>>23)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id3_data_ref_frame(data)            ((0x00700000&(data))>>20)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id4_data_ref_frame(data)            ((0x000E0000&(data))>>17)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id5_data_ref_frame(data)            ((0x0001C000&(data))>>14)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id6_data_ref_frame(data)            ((0x00003800&(data))>>11)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id7_data_ref_frame(data)            ((0x00000700&(data))>>8)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id0_mask_ref_frame(data)            ((0x00000080&(data))>>7)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id1_mask_ref_frame(data)            ((0x00000040&(data))>>6)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id2_mask_ref_frame(data)            ((0x00000020&(data))>>5)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id3_mask_ref_frame(data)            ((0x00000010&(data))>>4)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id4_mask_ref_frame(data)            ((0x00000008&(data))>>3)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id5_mask_ref_frame(data)            ((0x00000004&(data))>>2)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id6_mask_ref_frame(data)            ((0x00000002&(data))>>1)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_get_seg_id7_mask_ref_frame(data)            (0x00000001&(data))
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id0_data_ref_frame_src(data)            ((0xE0000000&(data))>>29)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id1_data_ref_frame_src(data)            ((0x1C000000&(data))>>26)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id2_data_ref_frame_src(data)            ((0x03800000&(data))>>23)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id3_data_ref_frame_src(data)            ((0x00700000&(data))>>20)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id4_data_ref_frame_src(data)            ((0x000E0000&(data))>>17)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id5_data_ref_frame_src(data)            ((0x0001C000&(data))>>14)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id6_data_ref_frame_src(data)            ((0x00003800&(data))>>11)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id7_data_ref_frame_src(data)            ((0x00000700&(data))>>8)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id0_mask_ref_frame_src(data)            ((0x00000080&(data))>>7)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id1_mask_ref_frame_src(data)            ((0x00000040&(data))>>6)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id2_mask_ref_frame_src(data)            ((0x00000020&(data))>>5)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id3_mask_ref_frame_src(data)            ((0x00000010&(data))>>4)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id4_mask_ref_frame_src(data)            ((0x00000008&(data))>>3)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id5_mask_ref_frame_src(data)            ((0x00000004&(data))>>2)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id6_mask_ref_frame_src(data)            ((0x00000002&(data))>>1)
#define  CODEBLKREG_P3_VP9_FRM_LEVEL_seg_id7_mask_ref_frame_src(data)            (0x00000001&(data))

#ifdef _CODEBLKREG_USE_STRUCT
#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CODEBLKREG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  cm_bypass:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  ldstCmemCount:16;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cabac_1p_mode:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cabac_p2_p3:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  itblk_advmode:1;
    };
}CODEBLKREG_VE_CNTL_RBUS;

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
}CODEBLKREG_UMEM_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mbaddrb_na:1;
        RBus_UInt32  mbaddra_na:1;
        RBus_UInt32  slicegroup_en:1;
    };
}CODEBLKREG_VE_SLICEGROUP_RBUS;

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
}CODEBLKREG_CURADR_RBUS;

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
}CODEBLKREG_PREDCNTR_RBUS;

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
}CODEBLKREG_TOTAL_COEF1_RBUS;

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
}CODEBLKREG_TOTAL_COEF2_RBUS;

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
}CODEBLKREG_TOTAL_COEF3_RBUS;

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
}CODEBLKREG_TOTAL_COEF4_RBUS;

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
        RBus_UInt32  fixedQP:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  mbweightingflg:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  pic_ref_flg:1;
    };
}CODEBLKREG_VE_AVS_CNTL_RBUS;

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
}CODEBLKREG_VE_H264_CNTL_RBUS;

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
}CODEBLKREG_VE_H264_CNTL2_RBUS;

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
}CODEBLKREG_VE_VC1QUANT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ttmbf:1;
    };
}CODEBLKREG_VE_VC1TRANSFORM_RBUS;

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
}CODEBLKREG_VE_VC1MV_RBUS;

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
}CODEBLKREG_VE_MVFCODE_RBUS;

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
}CODEBLKREG_VE_VC1TABLE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  escm3_rsize:3;
        RBus_UInt32  escm3_lsize:4;
    };
}CODEBLKREG_VE_VC1ESC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rowMB:8;
        RBus_UInt32  colMB:7;
        RBus_UInt32  rowmb_mod3:2;
        RBus_UInt32  colmb_mod3:2;
        RBus_UInt32  bitplane_len:13;
    };
}CODEBLKREG_VE_VC1BITPLN_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bitplane_addr:32;
    };
}CODEBLKREG_VE_VC1BITPLN_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldst_addr:32;
    };
}CODEBLKREG_VE_LDSTADDR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_bit:32;
    };
}CODEBLKREG_VE_DECBITCNT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bitcnt:32;
    };
}CODEBLKREG_VLD_BITCNT_RBUS;

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
}CODEBLKREG_VE_BSCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  min_thre:7;
    };
}CODEBLKREG_VE_BS_MIN_THR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  timer_value:24;
    };
}CODEBLKREG_VE_BSTIMER_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CODEBLKREG_VE_BSBASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CODEBLKREG_VE_BSLIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CODEBLKREG_VE_BSWRPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_ptr:32;
    };
}CODEBLKREG_VE_BSCURPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bit_ptr:32;
    };
}CODEBLKREG_VE_DECBSPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  removal_counter:29;
    };
}CODEBLKREG_VE_JPG_EMU_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dec_bit_ptr_msb:3;
    };
}CODEBLKREG_VE_DECBSPTR_MSB_RBUS;

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
}CODEBLKREG_VE_TRANSFORM_RBUS;

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
}CODEBLKREG_VE_QUANTIZER_RBUS;

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
}CODEBLKREG_VE_QUANTIZER2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  blk_pic_idx:7;
    };
}CODEBLKREG_VE_ITDMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cbp6bits:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  subblkpat:24;
    };
}CODEBLKREG_VE_CBP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  mbpartition:9;
    };
}CODEBLKREG_MB_PARTITION_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mb_pred_mode:8;
    };
}CODEBLKREG_MB_PREDMODE_RBUS;

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
}CODEBLKREG_MB_INFO_RBUS;

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
}CODEBLKREG_MB_INFO2_RBUS;

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
}CODEBLKREG_RV_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  struvlc_len:31;
    };
}CODEBLKREG_RV_STRUVLC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  left_blocks:16;
    };
}CODEBLKREG_RV_INTRAMODE_RBUS;

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
}CODEBLKREG_VLDTBLPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  tbl_espptr_saddr:10;
    };
}CODEBLKREG_VLDESPPTR_RBUS;

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
}CODEBLKREG_VE_ACDCP_LUMA_RBUS;

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
}CODEBLKREG_VE_ACDCP_CHRO_RBUS;

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
}CODEBLKREG_NDB_CTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CODEBLKREG_NDB_CAVLC_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CODEBLKREG_NDB_CAVLC_LIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CODEBLKREG_NDB_CAVLC_WPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}CODEBLKREG_NDB_CAVLC_RPTR_RBUS;

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
}CODEBLKREG_VP8_P3_FRM_MB1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  vp8_p3_curmb:9;
    };
}CODEBLKREG_VP8_P3_MB2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  high:9;
        RBus_UInt32  bits:4;
        RBus_UInt32  code_word:16;
    };
}CODEBLKREG_VP8_BAC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  dec_ctb_max_cycle:8;
        RBus_UInt32  dec_ctb_cycle_chken:1;
        RBus_UInt32  pcm_bit_depth_chroma:4;
        RBus_UInt32  pcm_bit_depth_luma:4;
        RBus_UInt32  transform_skip_enabled_flag:1;
        RBus_UInt32  transquant_bypass_enable_flag:1;
        RBus_UInt32  sign_data_hiding_flag:1;
    };
}CODEBLKREG_SDE_P3_HEVC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  start_trigger:1;
        RBus_UInt32  group_cnt:3;
        RBus_UInt32  start_group:3;
    };
}CODEBLKREG_HEVC_LDQMEM_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reference_mode:2;
        RBus_UInt32  seg_enable:1;
        RBus_UInt32  seg_update_map:1;
        RBus_UInt32  seg_id_0_mask_skip:1;
        RBus_UInt32  seg_id_1_mask_skip:1;
        RBus_UInt32  seg_id_2_mask_skip:1;
        RBus_UInt32  seg_id_3_mask_skip:1;
        RBus_UInt32  seg_id_4_mask_skip:1;
        RBus_UInt32  seg_id_5_mask_skip:1;
        RBus_UInt32  seg_id_6_mask_skip:1;
        RBus_UInt32  seg_id_7_mask_skip:1;
        RBus_UInt32  subsampling_x:1;
        RBus_UInt32  subsampling_y:1;
        RBus_UInt32  intra_only:1;
        RBus_UInt32  interp_filter:3;
        RBus_UInt32  ref_frame_sign_bias:4;
        RBus_UInt32  tx_mode:3;
        RBus_UInt32  comp_var_ref_1:2;
        RBus_UInt32  comp_var_ref_0:2;
        RBus_UInt32  comp_fixed_ref:2;
        RBus_UInt32  vp9_bit_high:1;
    };
}CODEBLKREG_P3_VP9_PIC_LEVEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_id0_data_ref_frame:3;
        RBus_UInt32  seg_id1_data_ref_frame:3;
        RBus_UInt32  seg_id2_data_ref_frame:3;
        RBus_UInt32  seg_id3_data_ref_frame:3;
        RBus_UInt32  seg_id4_data_ref_frame:3;
        RBus_UInt32  seg_id5_data_ref_frame:3;
        RBus_UInt32  seg_id6_data_ref_frame:3;
        RBus_UInt32  seg_id7_data_ref_frame:3;
        RBus_UInt32  seg_id0_mask_ref_frame:1;
        RBus_UInt32  seg_id1_mask_ref_frame:1;
        RBus_UInt32  seg_id2_mask_ref_frame:1;
        RBus_UInt32  seg_id3_mask_ref_frame:1;
        RBus_UInt32  seg_id4_mask_ref_frame:1;
        RBus_UInt32  seg_id5_mask_ref_frame:1;
        RBus_UInt32  seg_id6_mask_ref_frame:1;
        RBus_UInt32  seg_id7_mask_ref_frame:1;
    };
}CODEBLKREG_P3_VP9_FRM_LEVEL_RBUS;

#else //apply LITTLE_ENDIAN

//======CODEBLKREG register structure define==========

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
        RBus_UInt32  ldstCmemCount:16;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  cm_bypass:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:7;
    };
}CODEBLKREG_VE_CNTL_RBUS;

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
}CODEBLKREG_UMEM_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slicegroup_en:1;
        RBus_UInt32  mbaddra_na:1;
        RBus_UInt32  mbaddrb_na:1;
        RBus_UInt32  res1:29;
    };
}CODEBLKREG_VE_SLICEGROUP_RBUS;

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
}CODEBLKREG_CURADR_RBUS;

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
}CODEBLKREG_PREDCNTR_RBUS;

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
}CODEBLKREG_TOTAL_COEF1_RBUS;

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
}CODEBLKREG_TOTAL_COEF2_RBUS;

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
}CODEBLKREG_TOTAL_COEF3_RBUS;

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
}CODEBLKREG_TOTAL_COEF4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pic_ref_flg:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mbweightingflg:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  fixedQP:1;
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
}CODEBLKREG_VE_AVS_CNTL_RBUS;

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
}CODEBLKREG_VE_H264_CNTL_RBUS;

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
}CODEBLKREG_VE_H264_CNTL2_RBUS;

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
}CODEBLKREG_VE_VC1QUANT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ttmbf:1;
        RBus_UInt32  res1:31;
    };
}CODEBLKREG_VE_VC1TRANSFORM_RBUS;

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
}CODEBLKREG_VE_VC1MV_RBUS;

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
}CODEBLKREG_VE_MVFCODE_RBUS;

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
}CODEBLKREG_VE_VC1TABLE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  escm3_lsize:4;
        RBus_UInt32  escm3_rsize:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res1:24;
    };
}CODEBLKREG_VE_VC1ESC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bitplane_len:13;
        RBus_UInt32  colmb_mod3:2;
        RBus_UInt32  rowmb_mod3:2;
        RBus_UInt32  colMB:7;
        RBus_UInt32  rowMB:8;
    };
}CODEBLKREG_VE_VC1BITPLN_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bitplane_addr:32;
    };
}CODEBLKREG_VE_VC1BITPLN_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldst_addr:32;
    };
}CODEBLKREG_VE_LDSTADDR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_bit:32;
    };
}CODEBLKREG_VE_DECBITCNT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bitcnt:32;
    };
}CODEBLKREG_VLD_BITCNT_RBUS;

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
}CODEBLKREG_VE_BSCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_thre:7;
        RBus_UInt32  res1:25;
    };
}CODEBLKREG_VE_BS_MIN_THR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timer_value:24;
        RBus_UInt32  res1:8;
    };
}CODEBLKREG_VE_BSTIMER_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CODEBLKREG_VE_BSBASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CODEBLKREG_VE_BSLIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CODEBLKREG_VE_BSWRPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_ptr:32;
    };
}CODEBLKREG_VE_BSCURPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bit_ptr:32;
    };
}CODEBLKREG_VE_DECBSPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  removal_counter:29;
        RBus_UInt32  res1:3;
    };
}CODEBLKREG_VE_JPG_EMU_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bit_ptr_msb:3;
        RBus_UInt32  res1:29;
    };
}CODEBLKREG_VE_DECBSPTR_MSB_RBUS;

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
}CODEBLKREG_VE_TRANSFORM_RBUS;

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
}CODEBLKREG_VE_QUANTIZER_RBUS;

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
}CODEBLKREG_VE_QUANTIZER2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blk_pic_idx:7;
        RBus_UInt32  res1:25;
    };
}CODEBLKREG_VE_ITDMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subblkpat:24;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cbp6bits:6;
        RBus_UInt32  write_enable2:1;
    };
}CODEBLKREG_VE_CBP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbpartition:9;
        RBus_UInt32  res1:23;
    };
}CODEBLKREG_MB_PARTITION_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_pred_mode:8;
        RBus_UInt32  res1:24;
    };
}CODEBLKREG_MB_PREDMODE_RBUS;

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
}CODEBLKREG_MB_INFO_RBUS;

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
}CODEBLKREG_MB_INFO2_RBUS;

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
}CODEBLKREG_RV_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  struvlc_len:31;
        RBus_UInt32  res1:1;
    };
}CODEBLKREG_RV_STRUVLC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_blocks:16;
        RBus_UInt32  res1:16;
    };
}CODEBLKREG_RV_INTRAMODE_RBUS;

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
}CODEBLKREG_VLDTBLPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbl_espptr_saddr:10;
        RBus_UInt32  res1:22;
    };
}CODEBLKREG_VLDESPPTR_RBUS;

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
}CODEBLKREG_VE_ACDCP_LUMA_RBUS;

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
}CODEBLKREG_VE_ACDCP_CHRO_RBUS;

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
}CODEBLKREG_NDB_CTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CODEBLKREG_NDB_CAVLC_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CODEBLKREG_NDB_CAVLC_LIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CODEBLKREG_NDB_CAVLC_WPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}CODEBLKREG_NDB_CAVLC_RPTR_RBUS;

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
}CODEBLKREG_VP8_P3_FRM_MB1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vp8_p3_curmb:9;
        RBus_UInt32  res1:23;
    };
}CODEBLKREG_VP8_P3_MB2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  code_word:16;
        RBus_UInt32  bits:4;
        RBus_UInt32  high:9;
        RBus_UInt32  res1:3;
    };
}CODEBLKREG_VP8_BAC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sign_data_hiding_flag:1;
        RBus_UInt32  transquant_bypass_enable_flag:1;
        RBus_UInt32  transform_skip_enabled_flag:1;
        RBus_UInt32  pcm_bit_depth_luma:4;
        RBus_UInt32  pcm_bit_depth_chroma:4;
        RBus_UInt32  dec_ctb_cycle_chken:1;
        RBus_UInt32  dec_ctb_max_cycle:8;
        RBus_UInt32  res1:12;
    };
}CODEBLKREG_SDE_P3_HEVC_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_group:3;
        RBus_UInt32  group_cnt:3;
        RBus_UInt32  start_trigger:1;
        RBus_UInt32  res1:25;
    };
}CODEBLKREG_HEVC_LDQMEM_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vp9_bit_high:1;
        RBus_UInt32  comp_fixed_ref:2;
        RBus_UInt32  comp_var_ref_0:2;
        RBus_UInt32  comp_var_ref_1:2;
        RBus_UInt32  tx_mode:3;
        RBus_UInt32  ref_frame_sign_bias:4;
        RBus_UInt32  interp_filter:3;
        RBus_UInt32  intra_only:1;
        RBus_UInt32  subsampling_y:1;
        RBus_UInt32  subsampling_x:1;
        RBus_UInt32  seg_id_7_mask_skip:1;
        RBus_UInt32  seg_id_6_mask_skip:1;
        RBus_UInt32  seg_id_5_mask_skip:1;
        RBus_UInt32  seg_id_4_mask_skip:1;
        RBus_UInt32  seg_id_3_mask_skip:1;
        RBus_UInt32  seg_id_2_mask_skip:1;
        RBus_UInt32  seg_id_1_mask_skip:1;
        RBus_UInt32  seg_id_0_mask_skip:1;
        RBus_UInt32  seg_update_map:1;
        RBus_UInt32  seg_enable:1;
        RBus_UInt32  reference_mode:2;
    };
}CODEBLKREG_P3_VP9_PIC_LEVEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg_id7_mask_ref_frame:1;
        RBus_UInt32  seg_id6_mask_ref_frame:1;
        RBus_UInt32  seg_id5_mask_ref_frame:1;
        RBus_UInt32  seg_id4_mask_ref_frame:1;
        RBus_UInt32  seg_id3_mask_ref_frame:1;
        RBus_UInt32  seg_id2_mask_ref_frame:1;
        RBus_UInt32  seg_id1_mask_ref_frame:1;
        RBus_UInt32  seg_id0_mask_ref_frame:1;
        RBus_UInt32  seg_id7_data_ref_frame:3;
        RBus_UInt32  seg_id6_data_ref_frame:3;
        RBus_UInt32  seg_id5_data_ref_frame:3;
        RBus_UInt32  seg_id4_data_ref_frame:3;
        RBus_UInt32  seg_id3_data_ref_frame:3;
        RBus_UInt32  seg_id2_data_ref_frame:3;
        RBus_UInt32  seg_id1_data_ref_frame:3;
        RBus_UInt32  seg_id0_data_ref_frame:3;
    };
}CODEBLKREG_P3_VP9_FRM_LEVEL_RBUS;




#endif 


#endif 
#endif 
