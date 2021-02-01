/**
* @file Mac5_LGCY_VE_IME_Arch_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGCY_IME_REG_H_
#define _RBUS_LGCY_IME_REG_H_

#include "rbus_types.h"



//  LGCY_IME Register Address
#define  LGCY_IME_CTRL                                                           0x1800F200
#define  LGCY_IME_CTRL_reg_addr                                                  "0xB800F200"
#define  LGCY_IME_CTRL_reg                                                       0xB800F200
#define  LGCY_IME_CTRL_inst_addr                                                 "0x0000"
#define  set_LGCY_IME_CTRL_reg(data)                                             (*((volatile unsigned int*)LGCY_IME_CTRL_reg)=data)
#define  get_LGCY_IME_CTRL_reg                                                   (*((volatile unsigned int*)LGCY_IME_CTRL_reg))
#define  LGCY_IME_CTRL_ignore_ldref_shift                                        (20)
#define  LGCY_IME_CTRL_int_stat_shift                                            (17)
#define  LGCY_IME_CTRL_int_en_shift                                              (16)
#define  LGCY_IME_CTRL_swind_y_shift                                             (8)
#define  LGCY_IME_CTRL_swind_x_shift                                             (4)
#define  LGCY_IME_CTRL_ignore_fme_shift                                          (3)
#define  LGCY_IME_CTRL_mul_dec_shift                                             (2)
#define  LGCY_IME_CTRL_mul_req_shift                                             (1)
#define  LGCY_IME_CTRL_only16_shift                                              (0)
#define  LGCY_IME_CTRL_ignore_ldref_mask                                         (0x00100000)
#define  LGCY_IME_CTRL_int_stat_mask                                             (0x00020000)
#define  LGCY_IME_CTRL_int_en_mask                                               (0x00010000)
#define  LGCY_IME_CTRL_swind_y_mask                                              (0x00000F00)
#define  LGCY_IME_CTRL_swind_x_mask                                              (0x000000F0)
#define  LGCY_IME_CTRL_ignore_fme_mask                                           (0x00000008)
#define  LGCY_IME_CTRL_mul_dec_mask                                              (0x00000004)
#define  LGCY_IME_CTRL_mul_req_mask                                              (0x00000002)
#define  LGCY_IME_CTRL_only16_mask                                               (0x00000001)
#define  LGCY_IME_CTRL_ignore_ldref(data)                                        (0x00100000&((data)<<20))
#define  LGCY_IME_CTRL_int_stat(data)                                            (0x00020000&((data)<<17))
#define  LGCY_IME_CTRL_int_en(data)                                              (0x00010000&((data)<<16))
#define  LGCY_IME_CTRL_swind_y(data)                                             (0x00000F00&((data)<<8))
#define  LGCY_IME_CTRL_swind_x(data)                                             (0x000000F0&((data)<<4))
#define  LGCY_IME_CTRL_ignore_fme(data)                                          (0x00000008&((data)<<3))
#define  LGCY_IME_CTRL_mul_dec(data)                                             (0x00000004&((data)<<2))
#define  LGCY_IME_CTRL_mul_req(data)                                             (0x00000002&((data)<<1))
#define  LGCY_IME_CTRL_only16(data)                                              (0x00000001&(data))
#define  LGCY_IME_CTRL_get_ignore_ldref(data)                                    ((0x00100000&(data))>>20)
#define  LGCY_IME_CTRL_get_int_stat(data)                                        ((0x00020000&(data))>>17)
#define  LGCY_IME_CTRL_get_int_en(data)                                          ((0x00010000&(data))>>16)
#define  LGCY_IME_CTRL_get_swind_y(data)                                         ((0x00000F00&(data))>>8)
#define  LGCY_IME_CTRL_get_swind_x(data)                                         ((0x000000F0&(data))>>4)
#define  LGCY_IME_CTRL_get_ignore_fme(data)                                      ((0x00000008&(data))>>3)
#define  LGCY_IME_CTRL_get_mul_dec(data)                                         ((0x00000004&(data))>>2)
#define  LGCY_IME_CTRL_get_mul_req(data)                                         ((0x00000002&(data))>>1)
#define  LGCY_IME_CTRL_get_only16(data)                                          (0x00000001&(data))

#define  LGCY_IME_CTRL3                                                          0x1800F204
#define  LGCY_IME_CTRL3_reg_addr                                                 "0xB800F204"
#define  LGCY_IME_CTRL3_reg                                                      0xB800F204
#define  LGCY_IME_CTRL3_inst_addr                                                "0x0001"
#define  set_LGCY_IME_CTRL3_reg(data)                                            (*((volatile unsigned int*)LGCY_IME_CTRL3_reg)=data)
#define  get_LGCY_IME_CTRL3_reg                                                  (*((volatile unsigned int*)LGCY_IME_CTRL3_reg))
#define  LGCY_IME_CTRL3_write_enable6_shift                                      (11)
#define  LGCY_IME_CTRL3_sub1616_md_shift                                         (10)
#define  LGCY_IME_CTRL3_write_enable5_shift                                      (9)
#define  LGCY_IME_CTRL3_cr_thr_shift                                             (8)
#define  LGCY_IME_CTRL3_write_enable2_shift                                      (7)
#define  LGCY_IME_CTRL3_e0_cr_on_shift                                           (6)
#define  LGCY_IME_CTRL3_e0_cr_dst_sub3_shift                                     (4)
#define  LGCY_IME_CTRL3_write_enable1_shift                                      (3)
#define  LGCY_IME_CTRL3_e0_cr_src_shift                                          (0)
#define  LGCY_IME_CTRL3_write_enable6_mask                                       (0x00000800)
#define  LGCY_IME_CTRL3_sub1616_md_mask                                          (0x00000400)
#define  LGCY_IME_CTRL3_write_enable5_mask                                       (0x00000200)
#define  LGCY_IME_CTRL3_cr_thr_mask                                              (0x00000100)
#define  LGCY_IME_CTRL3_write_enable2_mask                                       (0x00000080)
#define  LGCY_IME_CTRL3_e0_cr_on_mask                                            (0x00000040)
#define  LGCY_IME_CTRL3_e0_cr_dst_sub3_mask                                      (0x00000030)
#define  LGCY_IME_CTRL3_write_enable1_mask                                       (0x00000008)
#define  LGCY_IME_CTRL3_e0_cr_src_mask                                           (0x00000007)
#define  LGCY_IME_CTRL3_write_enable6(data)                                      (0x00000800&((data)<<11))
#define  LGCY_IME_CTRL3_sub1616_md(data)                                         (0x00000400&((data)<<10))
#define  LGCY_IME_CTRL3_write_enable5(data)                                      (0x00000200&((data)<<9))
#define  LGCY_IME_CTRL3_cr_thr(data)                                             (0x00000100&((data)<<8))
#define  LGCY_IME_CTRL3_write_enable2(data)                                      (0x00000080&((data)<<7))
#define  LGCY_IME_CTRL3_e0_cr_on(data)                                           (0x00000040&((data)<<6))
#define  LGCY_IME_CTRL3_e0_cr_dst_sub3(data)                                     (0x00000030&((data)<<4))
#define  LGCY_IME_CTRL3_write_enable1(data)                                      (0x00000008&((data)<<3))
#define  LGCY_IME_CTRL3_e0_cr_src(data)                                          (0x00000007&(data))
#define  LGCY_IME_CTRL3_get_write_enable6(data)                                  ((0x00000800&(data))>>11)
#define  LGCY_IME_CTRL3_get_sub1616_md(data)                                     ((0x00000400&(data))>>10)
#define  LGCY_IME_CTRL3_get_write_enable5(data)                                  ((0x00000200&(data))>>9)
#define  LGCY_IME_CTRL3_get_cr_thr(data)                                         ((0x00000100&(data))>>8)
#define  LGCY_IME_CTRL3_get_write_enable2(data)                                  ((0x00000080&(data))>>7)
#define  LGCY_IME_CTRL3_get_e0_cr_on(data)                                       ((0x00000040&(data))>>6)
#define  LGCY_IME_CTRL3_get_e0_cr_dst_sub3(data)                                 ((0x00000030&(data))>>4)
#define  LGCY_IME_CTRL3_get_write_enable1(data)                                  ((0x00000008&(data))>>3)
#define  LGCY_IME_CTRL3_get_e0_cr_src(data)                                      (0x00000007&(data))

#define  LGCY_IME_TMB_IDX_0                                                      0x1800F208
#define  LGCY_IME_TMB_IDX_0_reg_addr                                             "0xB800F208"
#define  LGCY_IME_TMB_IDX_0_reg                                                  0xB800F208
#define  LGCY_IME_TMB_IDX_0_inst_addr                                            "0x0002"
#define  set_LGCY_IME_TMB_IDX_0_reg(data)                                        (*((volatile unsigned int*)LGCY_IME_TMB_IDX_0_reg)=data)
#define  get_LGCY_IME_TMB_IDX_0_reg                                              (*((volatile unsigned int*)LGCY_IME_TMB_IDX_0_reg))
#define  LGCY_IME_TMB_IDX_0_idx_shift                                            (0)
#define  LGCY_IME_TMB_IDX_0_idx_mask                                             (0x0000007F)
#define  LGCY_IME_TMB_IDX_0_idx(data)                                            (0x0000007F&(data))
#define  LGCY_IME_TMB_IDX_0_get_idx(data)                                        (0x0000007F&(data))

#define  LGCY_IME_TMB_IDX_1                                                      0x1800F20C
#define  LGCY_IME_TMB_IDX_1_reg_addr                                             "0xB800F20C"
#define  LGCY_IME_TMB_IDX_1_reg                                                  0xB800F20C
#define  LGCY_IME_TMB_IDX_1_inst_addr                                            "0x0003"
#define  set_LGCY_IME_TMB_IDX_1_reg(data)                                        (*((volatile unsigned int*)LGCY_IME_TMB_IDX_1_reg)=data)
#define  get_LGCY_IME_TMB_IDX_1_reg                                              (*((volatile unsigned int*)LGCY_IME_TMB_IDX_1_reg))
#define  LGCY_IME_TMB_IDX_1_idx_shift                                            (0)
#define  LGCY_IME_TMB_IDX_1_idx_mask                                             (0x0000007F)
#define  LGCY_IME_TMB_IDX_1_idx(data)                                            (0x0000007F&(data))
#define  LGCY_IME_TMB_IDX_1_get_idx(data)                                        (0x0000007F&(data))

#define  LGCY_IME_TMB_POS_0                                                      0x1800F210
#define  LGCY_IME_TMB_POS_0_reg_addr                                             "0xB800F210"
#define  LGCY_IME_TMB_POS_0_reg                                                  0xB800F210
#define  LGCY_IME_TMB_POS_0_inst_addr                                            "0x0004"
#define  set_LGCY_IME_TMB_POS_0_reg(data)                                        (*((volatile unsigned int*)LGCY_IME_TMB_POS_0_reg)=data)
#define  get_LGCY_IME_TMB_POS_0_reg                                              (*((volatile unsigned int*)LGCY_IME_TMB_POS_0_reg))
#define  LGCY_IME_TMB_POS_0_y_shift                                              (16)
#define  LGCY_IME_TMB_POS_0_x_shift                                              (0)
#define  LGCY_IME_TMB_POS_0_y_mask                                               (0x0FFF0000)
#define  LGCY_IME_TMB_POS_0_x_mask                                               (0x00000FFF)
#define  LGCY_IME_TMB_POS_0_y(data)                                              (0x0FFF0000&((data)<<16))
#define  LGCY_IME_TMB_POS_0_x(data)                                              (0x00000FFF&(data))
#define  LGCY_IME_TMB_POS_0_get_y(data)                                          ((0x0FFF0000&(data))>>16)
#define  LGCY_IME_TMB_POS_0_get_x(data)                                          (0x00000FFF&(data))

#define  LGCY_IME_TMB_POS_1                                                      0x1800F214
#define  LGCY_IME_TMB_POS_1_reg_addr                                             "0xB800F214"
#define  LGCY_IME_TMB_POS_1_reg                                                  0xB800F214
#define  LGCY_IME_TMB_POS_1_inst_addr                                            "0x0005"
#define  set_LGCY_IME_TMB_POS_1_reg(data)                                        (*((volatile unsigned int*)LGCY_IME_TMB_POS_1_reg)=data)
#define  get_LGCY_IME_TMB_POS_1_reg                                              (*((volatile unsigned int*)LGCY_IME_TMB_POS_1_reg))
#define  LGCY_IME_TMB_POS_1_y_shift                                              (16)
#define  LGCY_IME_TMB_POS_1_x_shift                                              (0)
#define  LGCY_IME_TMB_POS_1_y_mask                                               (0x0FFF0000)
#define  LGCY_IME_TMB_POS_1_x_mask                                               (0x00000FFF)
#define  LGCY_IME_TMB_POS_1_y(data)                                              (0x0FFF0000&((data)<<16))
#define  LGCY_IME_TMB_POS_1_x(data)                                              (0x00000FFF&(data))
#define  LGCY_IME_TMB_POS_1_get_y(data)                                          ((0x0FFF0000&(data))>>16)
#define  LGCY_IME_TMB_POS_1_get_x(data)                                          (0x00000FFF&(data))

#define  LGCY_IME_RMB_IDX_0                                                      0x1800F218
#define  LGCY_IME_RMB_IDX_0_reg_addr                                             "0xB800F218"
#define  LGCY_IME_RMB_IDX_0_reg                                                  0xB800F218
#define  LGCY_IME_RMB_IDX_0_inst_addr                                            "0x0006"
#define  set_LGCY_IME_RMB_IDX_0_reg(data)                                        (*((volatile unsigned int*)LGCY_IME_RMB_IDX_0_reg)=data)
#define  get_LGCY_IME_RMB_IDX_0_reg                                              (*((volatile unsigned int*)LGCY_IME_RMB_IDX_0_reg))
#define  LGCY_IME_RMB_IDX_0_idx_shift                                            (0)
#define  LGCY_IME_RMB_IDX_0_idx_mask                                             (0x0000007F)
#define  LGCY_IME_RMB_IDX_0_idx(data)                                            (0x0000007F&(data))
#define  LGCY_IME_RMB_IDX_0_get_idx(data)                                        (0x0000007F&(data))

#define  LGCY_IME_RMB_IDX_1                                                      0x1800F21C
#define  LGCY_IME_RMB_IDX_1_reg_addr                                             "0xB800F21C"
#define  LGCY_IME_RMB_IDX_1_reg                                                  0xB800F21C
#define  LGCY_IME_RMB_IDX_1_inst_addr                                            "0x0007"
#define  set_LGCY_IME_RMB_IDX_1_reg(data)                                        (*((volatile unsigned int*)LGCY_IME_RMB_IDX_1_reg)=data)
#define  get_LGCY_IME_RMB_IDX_1_reg                                              (*((volatile unsigned int*)LGCY_IME_RMB_IDX_1_reg))
#define  LGCY_IME_RMB_IDX_1_idx_shift                                            (0)
#define  LGCY_IME_RMB_IDX_1_idx_mask                                             (0x0000007F)
#define  LGCY_IME_RMB_IDX_1_idx(data)                                            (0x0000007F&(data))
#define  LGCY_IME_RMB_IDX_1_get_idx(data)                                        (0x0000007F&(data))

#define  LGCY_IME_RMB_SPOS_0                                                     0x1800F220
#define  LGCY_IME_RMB_SPOS_0_reg_addr                                            "0xB800F220"
#define  LGCY_IME_RMB_SPOS_0_reg                                                 0xB800F220
#define  LGCY_IME_RMB_SPOS_0_inst_addr                                           "0x0008"
#define  set_LGCY_IME_RMB_SPOS_0_reg(data)                                       (*((volatile unsigned int*)LGCY_IME_RMB_SPOS_0_reg)=data)
#define  get_LGCY_IME_RMB_SPOS_0_reg                                             (*((volatile unsigned int*)LGCY_IME_RMB_SPOS_0_reg))
#define  LGCY_IME_RMB_SPOS_0_rsy_shift                                           (16)
#define  LGCY_IME_RMB_SPOS_0_rsx_shift                                           (0)
#define  LGCY_IME_RMB_SPOS_0_rsy_mask                                            (0x0FFF0000)
#define  LGCY_IME_RMB_SPOS_0_rsx_mask                                            (0x00000FFF)
#define  LGCY_IME_RMB_SPOS_0_rsy(data)                                           (0x0FFF0000&((data)<<16))
#define  LGCY_IME_RMB_SPOS_0_rsx(data)                                           (0x00000FFF&(data))
#define  LGCY_IME_RMB_SPOS_0_get_rsy(data)                                       ((0x0FFF0000&(data))>>16)
#define  LGCY_IME_RMB_SPOS_0_get_rsx(data)                                       (0x00000FFF&(data))

#define  LGCY_IME_RMB_SPOS_1                                                     0x1800F224
#define  LGCY_IME_RMB_SPOS_1_reg_addr                                            "0xB800F224"
#define  LGCY_IME_RMB_SPOS_1_reg                                                 0xB800F224
#define  LGCY_IME_RMB_SPOS_1_inst_addr                                           "0x0009"
#define  set_LGCY_IME_RMB_SPOS_1_reg(data)                                       (*((volatile unsigned int*)LGCY_IME_RMB_SPOS_1_reg)=data)
#define  get_LGCY_IME_RMB_SPOS_1_reg                                             (*((volatile unsigned int*)LGCY_IME_RMB_SPOS_1_reg))
#define  LGCY_IME_RMB_SPOS_1_rsy_shift                                           (16)
#define  LGCY_IME_RMB_SPOS_1_rsx_shift                                           (0)
#define  LGCY_IME_RMB_SPOS_1_rsy_mask                                            (0x0FFF0000)
#define  LGCY_IME_RMB_SPOS_1_rsx_mask                                            (0x00000FFF)
#define  LGCY_IME_RMB_SPOS_1_rsy(data)                                           (0x0FFF0000&((data)<<16))
#define  LGCY_IME_RMB_SPOS_1_rsx(data)                                           (0x00000FFF&(data))
#define  LGCY_IME_RMB_SPOS_1_get_rsy(data)                                       ((0x0FFF0000&(data))>>16)
#define  LGCY_IME_RMB_SPOS_1_get_rsx(data)                                       (0x00000FFF&(data))

#define  LGCY_IME_RMB_EPOS_0                                                     0x1800F228
#define  LGCY_IME_RMB_EPOS_0_reg_addr                                            "0xB800F228"
#define  LGCY_IME_RMB_EPOS_0_reg                                                 0xB800F228
#define  LGCY_IME_RMB_EPOS_0_inst_addr                                           "0x000A"
#define  set_LGCY_IME_RMB_EPOS_0_reg(data)                                       (*((volatile unsigned int*)LGCY_IME_RMB_EPOS_0_reg)=data)
#define  get_LGCY_IME_RMB_EPOS_0_reg                                             (*((volatile unsigned int*)LGCY_IME_RMB_EPOS_0_reg))
#define  LGCY_IME_RMB_EPOS_0_rey_shift                                           (16)
#define  LGCY_IME_RMB_EPOS_0_rex_shift                                           (0)
#define  LGCY_IME_RMB_EPOS_0_rey_mask                                            (0x0FFF0000)
#define  LGCY_IME_RMB_EPOS_0_rex_mask                                            (0x00000FFF)
#define  LGCY_IME_RMB_EPOS_0_rey(data)                                           (0x0FFF0000&((data)<<16))
#define  LGCY_IME_RMB_EPOS_0_rex(data)                                           (0x00000FFF&(data))
#define  LGCY_IME_RMB_EPOS_0_get_rey(data)                                       ((0x0FFF0000&(data))>>16)
#define  LGCY_IME_RMB_EPOS_0_get_rex(data)                                       (0x00000FFF&(data))

#define  LGCY_IME_RMB_EPOS_1                                                     0x1800F22C
#define  LGCY_IME_RMB_EPOS_1_reg_addr                                            "0xB800F22C"
#define  LGCY_IME_RMB_EPOS_1_reg                                                 0xB800F22C
#define  LGCY_IME_RMB_EPOS_1_inst_addr                                           "0x000B"
#define  set_LGCY_IME_RMB_EPOS_1_reg(data)                                       (*((volatile unsigned int*)LGCY_IME_RMB_EPOS_1_reg)=data)
#define  get_LGCY_IME_RMB_EPOS_1_reg                                             (*((volatile unsigned int*)LGCY_IME_RMB_EPOS_1_reg))
#define  LGCY_IME_RMB_EPOS_1_rey_shift                                           (16)
#define  LGCY_IME_RMB_EPOS_1_rex_shift                                           (0)
#define  LGCY_IME_RMB_EPOS_1_rey_mask                                            (0x0FFF0000)
#define  LGCY_IME_RMB_EPOS_1_rex_mask                                            (0x00000FFF)
#define  LGCY_IME_RMB_EPOS_1_rey(data)                                           (0x0FFF0000&((data)<<16))
#define  LGCY_IME_RMB_EPOS_1_rex(data)                                           (0x00000FFF&(data))
#define  LGCY_IME_RMB_EPOS_1_get_rey(data)                                       ((0x0FFF0000&(data))>>16)
#define  LGCY_IME_RMB_EPOS_1_get_rex(data)                                       (0x00000FFF&(data))

#define  LGCY_IME_CAND_CTRL                                                      0x1800F230
#define  LGCY_IME_CAND_CTRL_reg_addr                                             "0xB800F230"
#define  LGCY_IME_CAND_CTRL_reg                                                  0xB800F230
#define  LGCY_IME_CAND_CTRL_inst_addr                                            "0x000C"
#define  set_LGCY_IME_CAND_CTRL_reg(data)                                        (*((volatile unsigned int*)LGCY_IME_CAND_CTRL_reg)=data)
#define  get_LGCY_IME_CAND_CTRL_reg                                              (*((volatile unsigned int*)LGCY_IME_CAND_CTRL_reg))
#define  LGCY_IME_CAND_CTRL_num_shift                                            (0)
#define  LGCY_IME_CAND_CTRL_num_mask                                             (0x0000000F)
#define  LGCY_IME_CAND_CTRL_num(data)                                            (0x0000000F&(data))
#define  LGCY_IME_CAND_CTRL_get_num(data)                                        (0x0000000F&(data))

#define  LGCY_IME_CAND_LIST_0                                                    0x1800F234
#define  LGCY_IME_CAND_LIST_0_reg_addr                                           "0xB800F234"
#define  LGCY_IME_CAND_LIST_0_reg                                                0xB800F234
#define  LGCY_IME_CAND_LIST_0_inst_addr                                          "0x000D"
#define  set_LGCY_IME_CAND_LIST_0_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_0_reg)=data)
#define  get_LGCY_IME_CAND_LIST_0_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_0_reg))
#define  LGCY_IME_CAND_LIST_0_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_0_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_0_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_0_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_0_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_0_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_0_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_0_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_1                                                    0x1800F238
#define  LGCY_IME_CAND_LIST_1_reg_addr                                           "0xB800F238"
#define  LGCY_IME_CAND_LIST_1_reg                                                0xB800F238
#define  LGCY_IME_CAND_LIST_1_inst_addr                                          "0x000E"
#define  set_LGCY_IME_CAND_LIST_1_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_1_reg)=data)
#define  get_LGCY_IME_CAND_LIST_1_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_1_reg))
#define  LGCY_IME_CAND_LIST_1_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_1_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_1_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_1_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_1_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_1_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_1_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_1_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_2                                                    0x1800F23C
#define  LGCY_IME_CAND_LIST_2_reg_addr                                           "0xB800F23C"
#define  LGCY_IME_CAND_LIST_2_reg                                                0xB800F23C
#define  LGCY_IME_CAND_LIST_2_inst_addr                                          "0x000F"
#define  set_LGCY_IME_CAND_LIST_2_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_2_reg)=data)
#define  get_LGCY_IME_CAND_LIST_2_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_2_reg))
#define  LGCY_IME_CAND_LIST_2_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_2_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_2_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_2_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_2_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_2_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_2_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_2_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_3                                                    0x1800F240
#define  LGCY_IME_CAND_LIST_3_reg_addr                                           "0xB800F240"
#define  LGCY_IME_CAND_LIST_3_reg                                                0xB800F240
#define  LGCY_IME_CAND_LIST_3_inst_addr                                          "0x0010"
#define  set_LGCY_IME_CAND_LIST_3_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_3_reg)=data)
#define  get_LGCY_IME_CAND_LIST_3_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_3_reg))
#define  LGCY_IME_CAND_LIST_3_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_3_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_3_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_3_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_3_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_3_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_3_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_3_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_4                                                    0x1800F244
#define  LGCY_IME_CAND_LIST_4_reg_addr                                           "0xB800F244"
#define  LGCY_IME_CAND_LIST_4_reg                                                0xB800F244
#define  LGCY_IME_CAND_LIST_4_inst_addr                                          "0x0011"
#define  set_LGCY_IME_CAND_LIST_4_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_4_reg)=data)
#define  get_LGCY_IME_CAND_LIST_4_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_4_reg))
#define  LGCY_IME_CAND_LIST_4_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_4_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_4_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_4_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_4_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_4_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_4_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_4_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_5                                                    0x1800F248
#define  LGCY_IME_CAND_LIST_5_reg_addr                                           "0xB800F248"
#define  LGCY_IME_CAND_LIST_5_reg                                                0xB800F248
#define  LGCY_IME_CAND_LIST_5_inst_addr                                          "0x0012"
#define  set_LGCY_IME_CAND_LIST_5_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_5_reg)=data)
#define  get_LGCY_IME_CAND_LIST_5_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_5_reg))
#define  LGCY_IME_CAND_LIST_5_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_5_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_5_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_5_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_5_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_5_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_5_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_5_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_6                                                    0x1800F24C
#define  LGCY_IME_CAND_LIST_6_reg_addr                                           "0xB800F24C"
#define  LGCY_IME_CAND_LIST_6_reg                                                0xB800F24C
#define  LGCY_IME_CAND_LIST_6_inst_addr                                          "0x0013"
#define  set_LGCY_IME_CAND_LIST_6_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_6_reg)=data)
#define  get_LGCY_IME_CAND_LIST_6_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_6_reg))
#define  LGCY_IME_CAND_LIST_6_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_6_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_6_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_6_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_6_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_6_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_6_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_6_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_7                                                    0x1800F250
#define  LGCY_IME_CAND_LIST_7_reg_addr                                           "0xB800F250"
#define  LGCY_IME_CAND_LIST_7_reg                                                0xB800F250
#define  LGCY_IME_CAND_LIST_7_inst_addr                                          "0x0014"
#define  set_LGCY_IME_CAND_LIST_7_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_7_reg)=data)
#define  get_LGCY_IME_CAND_LIST_7_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_7_reg))
#define  LGCY_IME_CAND_LIST_7_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_7_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_7_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_7_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_7_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_7_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_7_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_7_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_8                                                    0x1800F254
#define  LGCY_IME_CAND_LIST_8_reg_addr                                           "0xB800F254"
#define  LGCY_IME_CAND_LIST_8_reg                                                0xB800F254
#define  LGCY_IME_CAND_LIST_8_inst_addr                                          "0x0015"
#define  set_LGCY_IME_CAND_LIST_8_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_8_reg)=data)
#define  get_LGCY_IME_CAND_LIST_8_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_8_reg))
#define  LGCY_IME_CAND_LIST_8_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_8_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_8_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_8_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_8_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_8_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_8_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_8_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_9                                                    0x1800F258
#define  LGCY_IME_CAND_LIST_9_reg_addr                                           "0xB800F258"
#define  LGCY_IME_CAND_LIST_9_reg                                                0xB800F258
#define  LGCY_IME_CAND_LIST_9_inst_addr                                          "0x0016"
#define  set_LGCY_IME_CAND_LIST_9_reg(data)                                      (*((volatile unsigned int*)LGCY_IME_CAND_LIST_9_reg)=data)
#define  get_LGCY_IME_CAND_LIST_9_reg                                            (*((volatile unsigned int*)LGCY_IME_CAND_LIST_9_reg))
#define  LGCY_IME_CAND_LIST_9_mvx_shift                                          (8)
#define  LGCY_IME_CAND_LIST_9_mvy_shift                                          (0)
#define  LGCY_IME_CAND_LIST_9_mvx_mask                                           (0x0003FF00)
#define  LGCY_IME_CAND_LIST_9_mvy_mask                                           (0x0000007F)
#define  LGCY_IME_CAND_LIST_9_mvx(data)                                          (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_9_mvy(data)                                          (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_9_get_mvx(data)                                      ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_9_get_mvy(data)                                      (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_10                                                   0x1800F25C
#define  LGCY_IME_CAND_LIST_10_reg_addr                                          "0xB800F25C"
#define  LGCY_IME_CAND_LIST_10_reg                                               0xB800F25C
#define  LGCY_IME_CAND_LIST_10_inst_addr                                         "0x0017"
#define  set_LGCY_IME_CAND_LIST_10_reg(data)                                     (*((volatile unsigned int*)LGCY_IME_CAND_LIST_10_reg)=data)
#define  get_LGCY_IME_CAND_LIST_10_reg                                           (*((volatile unsigned int*)LGCY_IME_CAND_LIST_10_reg))
#define  LGCY_IME_CAND_LIST_10_mvx_shift                                         (8)
#define  LGCY_IME_CAND_LIST_10_mvy_shift                                         (0)
#define  LGCY_IME_CAND_LIST_10_mvx_mask                                          (0x0003FF00)
#define  LGCY_IME_CAND_LIST_10_mvy_mask                                          (0x0000007F)
#define  LGCY_IME_CAND_LIST_10_mvx(data)                                         (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_10_mvy(data)                                         (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_10_get_mvx(data)                                     ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_10_get_mvy(data)                                     (0x0000007F&(data))

#define  LGCY_IME_CAND_LIST_11                                                   0x1800F260
#define  LGCY_IME_CAND_LIST_11_reg_addr                                          "0xB800F260"
#define  LGCY_IME_CAND_LIST_11_reg                                               0xB800F260
#define  LGCY_IME_CAND_LIST_11_inst_addr                                         "0x0018"
#define  set_LGCY_IME_CAND_LIST_11_reg(data)                                     (*((volatile unsigned int*)LGCY_IME_CAND_LIST_11_reg)=data)
#define  get_LGCY_IME_CAND_LIST_11_reg                                           (*((volatile unsigned int*)LGCY_IME_CAND_LIST_11_reg))
#define  LGCY_IME_CAND_LIST_11_mvx_shift                                         (8)
#define  LGCY_IME_CAND_LIST_11_mvy_shift                                         (0)
#define  LGCY_IME_CAND_LIST_11_mvx_mask                                          (0x0003FF00)
#define  LGCY_IME_CAND_LIST_11_mvy_mask                                          (0x0000007F)
#define  LGCY_IME_CAND_LIST_11_mvx(data)                                         (0x0003FF00&((data)<<8))
#define  LGCY_IME_CAND_LIST_11_mvy(data)                                         (0x0000007F&(data))
#define  LGCY_IME_CAND_LIST_11_get_mvx(data)                                     ((0x0003FF00&(data))>>8)
#define  LGCY_IME_CAND_LIST_11_get_mvy(data)                                     (0x0000007F&(data))

#define  LGCY_IME_MVP                                                            0x1800F264
#define  LGCY_IME_MVP_reg_addr                                                   "0xB800F264"
#define  LGCY_IME_MVP_reg                                                        0xB800F264
#define  LGCY_IME_MVP_inst_addr                                                  "0x0019"
#define  set_LGCY_IME_MVP_reg(data)                                              (*((volatile unsigned int*)LGCY_IME_MVP_reg)=data)
#define  get_LGCY_IME_MVP_reg                                                    (*((volatile unsigned int*)LGCY_IME_MVP_reg))
#define  LGCY_IME_MVP_pmvx_shift                                                 (16)
#define  LGCY_IME_MVP_pmvy_shift                                                 (0)
#define  LGCY_IME_MVP_pmvx_mask                                                  (0x0FFF0000)
#define  LGCY_IME_MVP_pmvy_mask                                                  (0x000001FF)
#define  LGCY_IME_MVP_pmvx(data)                                                 (0x0FFF0000&((data)<<16))
#define  LGCY_IME_MVP_pmvy(data)                                                 (0x000001FF&(data))
#define  LGCY_IME_MVP_get_pmvx(data)                                             ((0x0FFF0000&(data))>>16)
#define  LGCY_IME_MVP_get_pmvy(data)                                             (0x000001FF&(data))

#define  LGCY_IME_MVC                                                            0x1800F268
#define  LGCY_IME_MVC_reg_addr                                                   "0xB800F268"
#define  LGCY_IME_MVC_reg                                                        0xB800F268
#define  LGCY_IME_MVC_inst_addr                                                  "0x001A"
#define  set_LGCY_IME_MVC_reg(data)                                              (*((volatile unsigned int*)LGCY_IME_MVC_reg)=data)
#define  get_LGCY_IME_MVC_reg                                                    (*((volatile unsigned int*)LGCY_IME_MVC_reg))
#define  LGCY_IME_MVC_maxfrac_shift                                              (24)
#define  LGCY_IME_MVC_maxint_shift                                               (16)
#define  LGCY_IME_MVC_cbias_shift                                                (8)
#define  LGCY_IME_MVC_lambda_shift                                               (0)
#define  LGCY_IME_MVC_maxfrac_mask                                               (0x1F000000)
#define  LGCY_IME_MVC_maxint_mask                                                (0x000F0000)
#define  LGCY_IME_MVC_cbias_mask                                                 (0x0000FF00)
#define  LGCY_IME_MVC_lambda_mask                                                (0x0000007F)
#define  LGCY_IME_MVC_maxfrac(data)                                              (0x1F000000&((data)<<24))
#define  LGCY_IME_MVC_maxint(data)                                               (0x000F0000&((data)<<16))
#define  LGCY_IME_MVC_cbias(data)                                                (0x0000FF00&((data)<<8))
#define  LGCY_IME_MVC_lambda(data)                                               (0x0000007F&(data))
#define  LGCY_IME_MVC_get_maxfrac(data)                                          ((0x1F000000&(data))>>24)
#define  LGCY_IME_MVC_get_maxint(data)                                           ((0x000F0000&(data))>>16)
#define  LGCY_IME_MVC_get_cbias(data)                                            ((0x0000FF00&(data))>>8)
#define  LGCY_IME_MVC_get_lambda(data)                                           (0x0000007F&(data))

#define  LGCY_IME_RSLT16                                                         0x1800F26C
#define  LGCY_IME_RSLT16_reg_addr                                                "0xB800F26C"
#define  LGCY_IME_RSLT16_reg                                                     0xB800F26C
#define  LGCY_IME_RSLT16_inst_addr                                               "0x001B"
#define  set_LGCY_IME_RSLT16_reg(data)                                           (*((volatile unsigned int*)LGCY_IME_RSLT16_reg)=data)
#define  get_LGCY_IME_RSLT16_reg                                                 (*((volatile unsigned int*)LGCY_IME_RSLT16_reg))
#define  LGCY_IME_RSLT16_mvx_shift                                               (8)
#define  LGCY_IME_RSLT16_mvy_shift                                               (0)
#define  LGCY_IME_RSLT16_mvx_mask                                                (0x0003FF00)
#define  LGCY_IME_RSLT16_mvy_mask                                                (0x0000007F)
#define  LGCY_IME_RSLT16_mvx(data)                                               (0x0003FF00&((data)<<8))
#define  LGCY_IME_RSLT16_mvy(data)                                               (0x0000007F&(data))
#define  LGCY_IME_RSLT16_get_mvx(data)                                           ((0x0003FF00&(data))>>8)
#define  LGCY_IME_RSLT16_get_mvy(data)                                           (0x0000007F&(data))

#define  LGCY_IME_RSLT16_TCOST                                                   0x1800F270
#define  LGCY_IME_RSLT16_TCOST_reg_addr                                          "0xB800F270"
#define  LGCY_IME_RSLT16_TCOST_reg                                               0xB800F270
#define  LGCY_IME_RSLT16_TCOST_inst_addr                                         "0x001C"
#define  set_LGCY_IME_RSLT16_TCOST_reg(data)                                     (*((volatile unsigned int*)LGCY_IME_RSLT16_TCOST_reg)=data)
#define  get_LGCY_IME_RSLT16_TCOST_reg                                           (*((volatile unsigned int*)LGCY_IME_RSLT16_TCOST_reg))
#define  LGCY_IME_RSLT16_TCOST_tcost_shift                                       (0)
#define  LGCY_IME_RSLT16_TCOST_tcost_mask                                        (0x001FFFFF)
#define  LGCY_IME_RSLT16_TCOST_tcost(data)                                       (0x001FFFFF&(data))
#define  LGCY_IME_RSLT16_TCOST_get_tcost(data)                                   (0x001FFFFF&(data))

#define  LGCY_IME_RSLT8_0                                                        0x1800F274
#define  LGCY_IME_RSLT8_0_reg_addr                                               "0xB800F274"
#define  LGCY_IME_RSLT8_0_reg                                                    0xB800F274
#define  LGCY_IME_RSLT8_0_inst_addr                                              "0x001D"
#define  set_LGCY_IME_RSLT8_0_reg(data)                                          (*((volatile unsigned int*)LGCY_IME_RSLT8_0_reg)=data)
#define  get_LGCY_IME_RSLT8_0_reg                                                (*((volatile unsigned int*)LGCY_IME_RSLT8_0_reg))
#define  LGCY_IME_RSLT8_0_mvx_shift                                              (8)
#define  LGCY_IME_RSLT8_0_mvy_shift                                              (0)
#define  LGCY_IME_RSLT8_0_mvx_mask                                               (0x0003FF00)
#define  LGCY_IME_RSLT8_0_mvy_mask                                               (0x0000007F)
#define  LGCY_IME_RSLT8_0_mvx(data)                                              (0x0003FF00&((data)<<8))
#define  LGCY_IME_RSLT8_0_mvy(data)                                              (0x0000007F&(data))
#define  LGCY_IME_RSLT8_0_get_mvx(data)                                          ((0x0003FF00&(data))>>8)
#define  LGCY_IME_RSLT8_0_get_mvy(data)                                          (0x0000007F&(data))

#define  LGCY_IME_RSLT8_1                                                        0x1800F278
#define  LGCY_IME_RSLT8_1_reg_addr                                               "0xB800F278"
#define  LGCY_IME_RSLT8_1_reg                                                    0xB800F278
#define  LGCY_IME_RSLT8_1_inst_addr                                              "0x001E"
#define  set_LGCY_IME_RSLT8_1_reg(data)                                          (*((volatile unsigned int*)LGCY_IME_RSLT8_1_reg)=data)
#define  get_LGCY_IME_RSLT8_1_reg                                                (*((volatile unsigned int*)LGCY_IME_RSLT8_1_reg))
#define  LGCY_IME_RSLT8_1_mvx_shift                                              (8)
#define  LGCY_IME_RSLT8_1_mvy_shift                                              (0)
#define  LGCY_IME_RSLT8_1_mvx_mask                                               (0x0003FF00)
#define  LGCY_IME_RSLT8_1_mvy_mask                                               (0x0000007F)
#define  LGCY_IME_RSLT8_1_mvx(data)                                              (0x0003FF00&((data)<<8))
#define  LGCY_IME_RSLT8_1_mvy(data)                                              (0x0000007F&(data))
#define  LGCY_IME_RSLT8_1_get_mvx(data)                                          ((0x0003FF00&(data))>>8)
#define  LGCY_IME_RSLT8_1_get_mvy(data)                                          (0x0000007F&(data))

#define  LGCY_IME_RSLT8_2                                                        0x1800F27C
#define  LGCY_IME_RSLT8_2_reg_addr                                               "0xB800F27C"
#define  LGCY_IME_RSLT8_2_reg                                                    0xB800F27C
#define  LGCY_IME_RSLT8_2_inst_addr                                              "0x001F"
#define  set_LGCY_IME_RSLT8_2_reg(data)                                          (*((volatile unsigned int*)LGCY_IME_RSLT8_2_reg)=data)
#define  get_LGCY_IME_RSLT8_2_reg                                                (*((volatile unsigned int*)LGCY_IME_RSLT8_2_reg))
#define  LGCY_IME_RSLT8_2_mvx_shift                                              (8)
#define  LGCY_IME_RSLT8_2_mvy_shift                                              (0)
#define  LGCY_IME_RSLT8_2_mvx_mask                                               (0x0003FF00)
#define  LGCY_IME_RSLT8_2_mvy_mask                                               (0x0000007F)
#define  LGCY_IME_RSLT8_2_mvx(data)                                              (0x0003FF00&((data)<<8))
#define  LGCY_IME_RSLT8_2_mvy(data)                                              (0x0000007F&(data))
#define  LGCY_IME_RSLT8_2_get_mvx(data)                                          ((0x0003FF00&(data))>>8)
#define  LGCY_IME_RSLT8_2_get_mvy(data)                                          (0x0000007F&(data))

#define  LGCY_IME_RSLT8_3                                                        0x1800F280
#define  LGCY_IME_RSLT8_3_reg_addr                                               "0xB800F280"
#define  LGCY_IME_RSLT8_3_reg                                                    0xB800F280
#define  LGCY_IME_RSLT8_3_inst_addr                                              "0x0020"
#define  set_LGCY_IME_RSLT8_3_reg(data)                                          (*((volatile unsigned int*)LGCY_IME_RSLT8_3_reg)=data)
#define  get_LGCY_IME_RSLT8_3_reg                                                (*((volatile unsigned int*)LGCY_IME_RSLT8_3_reg))
#define  LGCY_IME_RSLT8_3_mvx_shift                                              (8)
#define  LGCY_IME_RSLT8_3_mvy_shift                                              (0)
#define  LGCY_IME_RSLT8_3_mvx_mask                                               (0x0003FF00)
#define  LGCY_IME_RSLT8_3_mvy_mask                                               (0x0000007F)
#define  LGCY_IME_RSLT8_3_mvx(data)                                              (0x0003FF00&((data)<<8))
#define  LGCY_IME_RSLT8_3_mvy(data)                                              (0x0000007F&(data))
#define  LGCY_IME_RSLT8_3_get_mvx(data)                                          ((0x0003FF00&(data))>>8)
#define  LGCY_IME_RSLT8_3_get_mvy(data)                                          (0x0000007F&(data))

#define  LGCY_IME_RSLT8_TCOST_0                                                  0x1800F284
#define  LGCY_IME_RSLT8_TCOST_0_reg_addr                                         "0xB800F284"
#define  LGCY_IME_RSLT8_TCOST_0_reg                                              0xB800F284
#define  LGCY_IME_RSLT8_TCOST_0_inst_addr                                        "0x0021"
#define  set_LGCY_IME_RSLT8_TCOST_0_reg(data)                                    (*((volatile unsigned int*)LGCY_IME_RSLT8_TCOST_0_reg)=data)
#define  get_LGCY_IME_RSLT8_TCOST_0_reg                                          (*((volatile unsigned int*)LGCY_IME_RSLT8_TCOST_0_reg))
#define  LGCY_IME_RSLT8_TCOST_0_tcost_shift                                      (0)
#define  LGCY_IME_RSLT8_TCOST_0_tcost_mask                                       (0x001FFFFF)
#define  LGCY_IME_RSLT8_TCOST_0_tcost(data)                                      (0x001FFFFF&(data))
#define  LGCY_IME_RSLT8_TCOST_0_get_tcost(data)                                  (0x001FFFFF&(data))

#define  LGCY_IME_RSLT8_TCOST_1                                                  0x1800F288
#define  LGCY_IME_RSLT8_TCOST_1_reg_addr                                         "0xB800F288"
#define  LGCY_IME_RSLT8_TCOST_1_reg                                              0xB800F288
#define  LGCY_IME_RSLT8_TCOST_1_inst_addr                                        "0x0022"
#define  set_LGCY_IME_RSLT8_TCOST_1_reg(data)                                    (*((volatile unsigned int*)LGCY_IME_RSLT8_TCOST_1_reg)=data)
#define  get_LGCY_IME_RSLT8_TCOST_1_reg                                          (*((volatile unsigned int*)LGCY_IME_RSLT8_TCOST_1_reg))
#define  LGCY_IME_RSLT8_TCOST_1_tcost_shift                                      (0)
#define  LGCY_IME_RSLT8_TCOST_1_tcost_mask                                       (0x001FFFFF)
#define  LGCY_IME_RSLT8_TCOST_1_tcost(data)                                      (0x001FFFFF&(data))
#define  LGCY_IME_RSLT8_TCOST_1_get_tcost(data)                                  (0x001FFFFF&(data))

#define  LGCY_IME_RSLT8_TCOST_2                                                  0x1800F28C
#define  LGCY_IME_RSLT8_TCOST_2_reg_addr                                         "0xB800F28C"
#define  LGCY_IME_RSLT8_TCOST_2_reg                                              0xB800F28C
#define  LGCY_IME_RSLT8_TCOST_2_inst_addr                                        "0x0023"
#define  set_LGCY_IME_RSLT8_TCOST_2_reg(data)                                    (*((volatile unsigned int*)LGCY_IME_RSLT8_TCOST_2_reg)=data)
#define  get_LGCY_IME_RSLT8_TCOST_2_reg                                          (*((volatile unsigned int*)LGCY_IME_RSLT8_TCOST_2_reg))
#define  LGCY_IME_RSLT8_TCOST_2_tcost_shift                                      (0)
#define  LGCY_IME_RSLT8_TCOST_2_tcost_mask                                       (0x001FFFFF)
#define  LGCY_IME_RSLT8_TCOST_2_tcost(data)                                      (0x001FFFFF&(data))
#define  LGCY_IME_RSLT8_TCOST_2_get_tcost(data)                                  (0x001FFFFF&(data))

#define  LGCY_IME_RSLT8_TCOST_3                                                  0x1800F290
#define  LGCY_IME_RSLT8_TCOST_3_reg_addr                                         "0xB800F290"
#define  LGCY_IME_RSLT8_TCOST_3_reg                                              0xB800F290
#define  LGCY_IME_RSLT8_TCOST_3_inst_addr                                        "0x0024"
#define  set_LGCY_IME_RSLT8_TCOST_3_reg(data)                                    (*((volatile unsigned int*)LGCY_IME_RSLT8_TCOST_3_reg)=data)
#define  get_LGCY_IME_RSLT8_TCOST_3_reg                                          (*((volatile unsigned int*)LGCY_IME_RSLT8_TCOST_3_reg))
#define  LGCY_IME_RSLT8_TCOST_3_tcost_shift                                      (0)
#define  LGCY_IME_RSLT8_TCOST_3_tcost_mask                                       (0x001FFFFF)
#define  LGCY_IME_RSLT8_TCOST_3_tcost(data)                                      (0x001FFFFF&(data))
#define  LGCY_IME_RSLT8_TCOST_3_get_tcost(data)                                  (0x001FFFFF&(data))

#define  LGCY_IME_ZMV                                                            0x1800F294
#define  LGCY_IME_ZMV_reg_addr                                                   "0xB800F294"
#define  LGCY_IME_ZMV_reg                                                        0xB800F294
#define  LGCY_IME_ZMV_inst_addr                                                  "0x0025"
#define  set_LGCY_IME_ZMV_reg(data)                                              (*((volatile unsigned int*)LGCY_IME_ZMV_reg)=data)
#define  get_LGCY_IME_ZMV_reg                                                    (*((volatile unsigned int*)LGCY_IME_ZMV_reg))
#define  LGCY_IME_ZMV_satd00_shift                                               (0)
#define  LGCY_IME_ZMV_satd00_mask                                                (0x001FFFFF)
#define  LGCY_IME_ZMV_satd00(data)                                               (0x001FFFFF&(data))
#define  LGCY_IME_ZMV_get_satd00(data)                                           (0x001FFFFF&(data))

#define  LGCY_IME_RSLT16x8_0                                                     0x1800F298
#define  LGCY_IME_RSLT16x8_0_reg_addr                                            "0xB800F298"
#define  LGCY_IME_RSLT16x8_0_reg                                                 0xB800F298
#define  LGCY_IME_RSLT16x8_0_inst_addr                                           "0x0026"
#define  set_LGCY_IME_RSLT16x8_0_reg(data)                                       (*((volatile unsigned int*)LGCY_IME_RSLT16x8_0_reg)=data)
#define  get_LGCY_IME_RSLT16x8_0_reg                                             (*((volatile unsigned int*)LGCY_IME_RSLT16x8_0_reg))
#define  LGCY_IME_RSLT16x8_0_mvx_shift                                           (8)
#define  LGCY_IME_RSLT16x8_0_mvy_shift                                           (0)
#define  LGCY_IME_RSLT16x8_0_mvx_mask                                            (0x0003FF00)
#define  LGCY_IME_RSLT16x8_0_mvy_mask                                            (0x0000007F)
#define  LGCY_IME_RSLT16x8_0_mvx(data)                                           (0x0003FF00&((data)<<8))
#define  LGCY_IME_RSLT16x8_0_mvy(data)                                           (0x0000007F&(data))
#define  LGCY_IME_RSLT16x8_0_get_mvx(data)                                       ((0x0003FF00&(data))>>8)
#define  LGCY_IME_RSLT16x8_0_get_mvy(data)                                       (0x0000007F&(data))

#define  LGCY_IME_RSLT16x8_1                                                     0x1800F29C
#define  LGCY_IME_RSLT16x8_1_reg_addr                                            "0xB800F29C"
#define  LGCY_IME_RSLT16x8_1_reg                                                 0xB800F29C
#define  LGCY_IME_RSLT16x8_1_inst_addr                                           "0x0027"
#define  set_LGCY_IME_RSLT16x8_1_reg(data)                                       (*((volatile unsigned int*)LGCY_IME_RSLT16x8_1_reg)=data)
#define  get_LGCY_IME_RSLT16x8_1_reg                                             (*((volatile unsigned int*)LGCY_IME_RSLT16x8_1_reg))
#define  LGCY_IME_RSLT16x8_1_mvx_shift                                           (8)
#define  LGCY_IME_RSLT16x8_1_mvy_shift                                           (0)
#define  LGCY_IME_RSLT16x8_1_mvx_mask                                            (0x0003FF00)
#define  LGCY_IME_RSLT16x8_1_mvy_mask                                            (0x0000007F)
#define  LGCY_IME_RSLT16x8_1_mvx(data)                                           (0x0003FF00&((data)<<8))
#define  LGCY_IME_RSLT16x8_1_mvy(data)                                           (0x0000007F&(data))
#define  LGCY_IME_RSLT16x8_1_get_mvx(data)                                       ((0x0003FF00&(data))>>8)
#define  LGCY_IME_RSLT16x8_1_get_mvy(data)                                       (0x0000007F&(data))

#define  LGCY_IME_RSLT16x8_TCOST_0                                               0x1800F2A0
#define  LGCY_IME_RSLT16x8_TCOST_0_reg_addr                                      "0xB800F2A0"
#define  LGCY_IME_RSLT16x8_TCOST_0_reg                                           0xB800F2A0
#define  LGCY_IME_RSLT16x8_TCOST_0_inst_addr                                     "0x0028"
#define  set_LGCY_IME_RSLT16x8_TCOST_0_reg(data)                                 (*((volatile unsigned int*)LGCY_IME_RSLT16x8_TCOST_0_reg)=data)
#define  get_LGCY_IME_RSLT16x8_TCOST_0_reg                                       (*((volatile unsigned int*)LGCY_IME_RSLT16x8_TCOST_0_reg))
#define  LGCY_IME_RSLT16x8_TCOST_0_tcost_shift                                   (0)
#define  LGCY_IME_RSLT16x8_TCOST_0_tcost_mask                                    (0x001FFFFF)
#define  LGCY_IME_RSLT16x8_TCOST_0_tcost(data)                                   (0x001FFFFF&(data))
#define  LGCY_IME_RSLT16x8_TCOST_0_get_tcost(data)                               (0x001FFFFF&(data))

#define  LGCY_IME_RSLT16x8_TCOST_1                                               0x1800F2A4
#define  LGCY_IME_RSLT16x8_TCOST_1_reg_addr                                      "0xB800F2A4"
#define  LGCY_IME_RSLT16x8_TCOST_1_reg                                           0xB800F2A4
#define  LGCY_IME_RSLT16x8_TCOST_1_inst_addr                                     "0x0029"
#define  set_LGCY_IME_RSLT16x8_TCOST_1_reg(data)                                 (*((volatile unsigned int*)LGCY_IME_RSLT16x8_TCOST_1_reg)=data)
#define  get_LGCY_IME_RSLT16x8_TCOST_1_reg                                       (*((volatile unsigned int*)LGCY_IME_RSLT16x8_TCOST_1_reg))
#define  LGCY_IME_RSLT16x8_TCOST_1_tcost_shift                                   (0)
#define  LGCY_IME_RSLT16x8_TCOST_1_tcost_mask                                    (0x001FFFFF)
#define  LGCY_IME_RSLT16x8_TCOST_1_tcost(data)                                   (0x001FFFFF&(data))
#define  LGCY_IME_RSLT16x8_TCOST_1_get_tcost(data)                               (0x001FFFFF&(data))

#define  LGCY_IME_RSLT8x16_0                                                     0x1800F2A8
#define  LGCY_IME_RSLT8x16_0_reg_addr                                            "0xB800F2A8"
#define  LGCY_IME_RSLT8x16_0_reg                                                 0xB800F2A8
#define  LGCY_IME_RSLT8x16_0_inst_addr                                           "0x002A"
#define  set_LGCY_IME_RSLT8x16_0_reg(data)                                       (*((volatile unsigned int*)LGCY_IME_RSLT8x16_0_reg)=data)
#define  get_LGCY_IME_RSLT8x16_0_reg                                             (*((volatile unsigned int*)LGCY_IME_RSLT8x16_0_reg))
#define  LGCY_IME_RSLT8x16_0_mvx_shift                                           (8)
#define  LGCY_IME_RSLT8x16_0_mvy_shift                                           (0)
#define  LGCY_IME_RSLT8x16_0_mvx_mask                                            (0x0003FF00)
#define  LGCY_IME_RSLT8x16_0_mvy_mask                                            (0x0000007F)
#define  LGCY_IME_RSLT8x16_0_mvx(data)                                           (0x0003FF00&((data)<<8))
#define  LGCY_IME_RSLT8x16_0_mvy(data)                                           (0x0000007F&(data))
#define  LGCY_IME_RSLT8x16_0_get_mvx(data)                                       ((0x0003FF00&(data))>>8)
#define  LGCY_IME_RSLT8x16_0_get_mvy(data)                                       (0x0000007F&(data))

#define  LGCY_IME_RSLT8x16_1                                                     0x1800F2AC
#define  LGCY_IME_RSLT8x16_1_reg_addr                                            "0xB800F2AC"
#define  LGCY_IME_RSLT8x16_1_reg                                                 0xB800F2AC
#define  LGCY_IME_RSLT8x16_1_inst_addr                                           "0x002B"
#define  set_LGCY_IME_RSLT8x16_1_reg(data)                                       (*((volatile unsigned int*)LGCY_IME_RSLT8x16_1_reg)=data)
#define  get_LGCY_IME_RSLT8x16_1_reg                                             (*((volatile unsigned int*)LGCY_IME_RSLT8x16_1_reg))
#define  LGCY_IME_RSLT8x16_1_mvx_shift                                           (8)
#define  LGCY_IME_RSLT8x16_1_mvy_shift                                           (0)
#define  LGCY_IME_RSLT8x16_1_mvx_mask                                            (0x0003FF00)
#define  LGCY_IME_RSLT8x16_1_mvy_mask                                            (0x0000007F)
#define  LGCY_IME_RSLT8x16_1_mvx(data)                                           (0x0003FF00&((data)<<8))
#define  LGCY_IME_RSLT8x16_1_mvy(data)                                           (0x0000007F&(data))
#define  LGCY_IME_RSLT8x16_1_get_mvx(data)                                       ((0x0003FF00&(data))>>8)
#define  LGCY_IME_RSLT8x16_1_get_mvy(data)                                       (0x0000007F&(data))

#define  LGCY_IME_RSLT8x16_TCOST_0                                               0x1800F2B0
#define  LGCY_IME_RSLT8x16_TCOST_0_reg_addr                                      "0xB800F2B0"
#define  LGCY_IME_RSLT8x16_TCOST_0_reg                                           0xB800F2B0
#define  LGCY_IME_RSLT8x16_TCOST_0_inst_addr                                     "0x002C"
#define  set_LGCY_IME_RSLT8x16_TCOST_0_reg(data)                                 (*((volatile unsigned int*)LGCY_IME_RSLT8x16_TCOST_0_reg)=data)
#define  get_LGCY_IME_RSLT8x16_TCOST_0_reg                                       (*((volatile unsigned int*)LGCY_IME_RSLT8x16_TCOST_0_reg))
#define  LGCY_IME_RSLT8x16_TCOST_0_tcost_shift                                   (0)
#define  LGCY_IME_RSLT8x16_TCOST_0_tcost_mask                                    (0x001FFFFF)
#define  LGCY_IME_RSLT8x16_TCOST_0_tcost(data)                                   (0x001FFFFF&(data))
#define  LGCY_IME_RSLT8x16_TCOST_0_get_tcost(data)                               (0x001FFFFF&(data))

#define  LGCY_IME_RSLT8x16_TCOST_1                                               0x1800F2B4
#define  LGCY_IME_RSLT8x16_TCOST_1_reg_addr                                      "0xB800F2B4"
#define  LGCY_IME_RSLT8x16_TCOST_1_reg                                           0xB800F2B4
#define  LGCY_IME_RSLT8x16_TCOST_1_inst_addr                                     "0x002D"
#define  set_LGCY_IME_RSLT8x16_TCOST_1_reg(data)                                 (*((volatile unsigned int*)LGCY_IME_RSLT8x16_TCOST_1_reg)=data)
#define  get_LGCY_IME_RSLT8x16_TCOST_1_reg                                       (*((volatile unsigned int*)LGCY_IME_RSLT8x16_TCOST_1_reg))
#define  LGCY_IME_RSLT8x16_TCOST_1_tcost_shift                                   (0)
#define  LGCY_IME_RSLT8x16_TCOST_1_tcost_mask                                    (0x001FFFFF)
#define  LGCY_IME_RSLT8x16_TCOST_1_tcost(data)                                   (0x001FFFFF&(data))
#define  LGCY_IME_RSLT8x16_TCOST_1_get_tcost(data)                               (0x001FFFFF&(data))

#define  LGCY_IME_REF_COST                                                       0x1800F3B8
#define  LGCY_IME_REF_COST_reg_addr                                              "0xB800F3B8"
#define  LGCY_IME_REF_COST_reg                                                   0xB800F3B8
#define  LGCY_IME_REF_COST_inst_addr                                             "0x002E"
#define  set_LGCY_IME_REF_COST_reg(data)                                         (*((volatile unsigned int*)LGCY_IME_REF_COST_reg)=data)
#define  get_LGCY_IME_REF_COST_reg                                               (*((volatile unsigned int*)LGCY_IME_REF_COST_reg))
#define  LGCY_IME_REF_COST_ref_cost_shift                                        (0)
#define  LGCY_IME_REF_COST_ref_cost_mask                                         (0x0000FFFF)
#define  LGCY_IME_REF_COST_ref_cost(data)                                        (0x0000FFFF&(data))
#define  LGCY_IME_REF_COST_get_ref_cost(data)                                    (0x0000FFFF&(data))

#define  LGCY_IME_DBG                                                            0x1800F3BC
#define  LGCY_IME_DBG_reg_addr                                                   "0xB800F3BC"
#define  LGCY_IME_DBG_reg                                                        0xB800F3BC
#define  LGCY_IME_DBG_inst_addr                                                  "0x002F"
#define  set_LGCY_IME_DBG_reg(data)                                              (*((volatile unsigned int*)LGCY_IME_DBG_reg)=data)
#define  get_LGCY_IME_DBG_reg                                                    (*((volatile unsigned int*)LGCY_IME_DBG_reg))
#define  LGCY_IME_DBG_sel1_shift                                                 (4)
#define  LGCY_IME_DBG_sel0_shift                                                 (1)
#define  LGCY_IME_DBG_enable_shift                                               (0)
#define  LGCY_IME_DBG_sel1_mask                                                  (0x00000070)
#define  LGCY_IME_DBG_sel0_mask                                                  (0x0000000E)
#define  LGCY_IME_DBG_enable_mask                                                (0x00000001)
#define  LGCY_IME_DBG_sel1(data)                                                 (0x00000070&((data)<<4))
#define  LGCY_IME_DBG_sel0(data)                                                 (0x0000000E&((data)<<1))
#define  LGCY_IME_DBG_enable(data)                                               (0x00000001&(data))
#define  LGCY_IME_DBG_get_sel1(data)                                             ((0x00000070&(data))>>4)
#define  LGCY_IME_DBG_get_sel0(data)                                             ((0x0000000E&(data))>>1)
#define  LGCY_IME_DBG_get_enable(data)                                           (0x00000001&(data))

#define  LGCY_IME_RDBG                                                           0x1800F3D0
#define  LGCY_IME_RDBG_reg_addr                                                  "0xB800F3D0"
#define  LGCY_IME_RDBG_reg                                                       0xB800F3D0
#define  LGCY_IME_RDBG_inst_addr                                                 "0x0030"
#define  set_LGCY_IME_RDBG_reg(data)                                             (*((volatile unsigned int*)LGCY_IME_RDBG_reg)=data)
#define  get_LGCY_IME_RDBG_reg                                                   (*((volatile unsigned int*)LGCY_IME_RDBG_reg))
#define  LGCY_IME_RDBG_reg1_shift                                                (16)
#define  LGCY_IME_RDBG_reg0_shift                                                (0)
#define  LGCY_IME_RDBG_reg1_mask                                                 (0xFFFF0000)
#define  LGCY_IME_RDBG_reg0_mask                                                 (0x0000FFFF)
#define  LGCY_IME_RDBG_reg1(data)                                                (0xFFFF0000&((data)<<16))
#define  LGCY_IME_RDBG_reg0(data)                                                (0x0000FFFF&(data))
#define  LGCY_IME_RDBG_get_reg1(data)                                            ((0xFFFF0000&(data))>>16)
#define  LGCY_IME_RDBG_get_reg0(data)                                            (0x0000FFFF&(data))

#define  LGCY_IME_DBG_FME_PMVCTL                                                 0x1800F3D4
#define  LGCY_IME_DBG_FME_PMVCTL_reg_addr                                        "0xB800F3D4"
#define  LGCY_IME_DBG_FME_PMVCTL_reg                                             0xB800F3D4
#define  LGCY_IME_DBG_FME_PMVCTL_inst_addr                                       "0x0031"
#define  set_LGCY_IME_DBG_FME_PMVCTL_reg(data)                                   (*((volatile unsigned int*)LGCY_IME_DBG_FME_PMVCTL_reg)=data)
#define  get_LGCY_IME_DBG_FME_PMVCTL_reg                                         (*((volatile unsigned int*)LGCY_IME_DBG_FME_PMVCTL_reg))
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable4_shift                             (29)
#define  LGCY_IME_DBG_FME_PMVCTL_ignore_fme_shift                                (28)
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable3_shift                             (27)
#define  LGCY_IME_DBG_FME_PMVCTL_force_valid_shift                               (26)
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable2_shift                             (25)
#define  LGCY_IME_DBG_FME_PMVCTL_trig_shift                                      (24)
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable1_shift                             (18)
#define  LGCY_IME_DBG_FME_PMVCTL_mvx_shift                                       (8)
#define  LGCY_IME_DBG_FME_PMVCTL_mvy_shift                                       (0)
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable4_mask                              (0x20000000)
#define  LGCY_IME_DBG_FME_PMVCTL_ignore_fme_mask                                 (0x10000000)
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable3_mask                              (0x08000000)
#define  LGCY_IME_DBG_FME_PMVCTL_force_valid_mask                                (0x04000000)
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable2_mask                              (0x02000000)
#define  LGCY_IME_DBG_FME_PMVCTL_trig_mask                                       (0x01000000)
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable1_mask                              (0x00040000)
#define  LGCY_IME_DBG_FME_PMVCTL_mvx_mask                                        (0x0003FF00)
#define  LGCY_IME_DBG_FME_PMVCTL_mvy_mask                                        (0x0000007F)
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable4(data)                             (0x20000000&((data)<<29))
#define  LGCY_IME_DBG_FME_PMVCTL_ignore_fme(data)                                (0x10000000&((data)<<28))
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable3(data)                             (0x08000000&((data)<<27))
#define  LGCY_IME_DBG_FME_PMVCTL_force_valid(data)                               (0x04000000&((data)<<26))
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable2(data)                             (0x02000000&((data)<<25))
#define  LGCY_IME_DBG_FME_PMVCTL_trig(data)                                      (0x01000000&((data)<<24))
#define  LGCY_IME_DBG_FME_PMVCTL_write_enable1(data)                             (0x00040000&((data)<<18))
#define  LGCY_IME_DBG_FME_PMVCTL_mvx(data)                                       (0x0003FF00&((data)<<8))
#define  LGCY_IME_DBG_FME_PMVCTL_mvy(data)                                       (0x0000007F&(data))
#define  LGCY_IME_DBG_FME_PMVCTL_get_write_enable4(data)                         ((0x20000000&(data))>>29)
#define  LGCY_IME_DBG_FME_PMVCTL_get_ignore_fme(data)                            ((0x10000000&(data))>>28)
#define  LGCY_IME_DBG_FME_PMVCTL_get_write_enable3(data)                         ((0x08000000&(data))>>27)
#define  LGCY_IME_DBG_FME_PMVCTL_get_force_valid(data)                           ((0x04000000&(data))>>26)
#define  LGCY_IME_DBG_FME_PMVCTL_get_write_enable2(data)                         ((0x02000000&(data))>>25)
#define  LGCY_IME_DBG_FME_PMVCTL_get_trig(data)                                  ((0x01000000&(data))>>24)
#define  LGCY_IME_DBG_FME_PMVCTL_get_write_enable1(data)                         ((0x00040000&(data))>>18)
#define  LGCY_IME_DBG_FME_PMVCTL_get_mvx(data)                                   ((0x0003FF00&(data))>>8)
#define  LGCY_IME_DBG_FME_PMVCTL_get_mvy(data)                                   (0x0000007F&(data))

#define  LGCY_IME_DBG_HWCTL                                                      0x1800F3D8
#define  LGCY_IME_DBG_HWCTL_reg_addr                                             "0xB800F3D8"
#define  LGCY_IME_DBG_HWCTL_reg                                                  0xB800F3D8
#define  LGCY_IME_DBG_HWCTL_inst_addr                                            "0x0032"
#define  set_LGCY_IME_DBG_HWCTL_reg(data)                                        (*((volatile unsigned int*)LGCY_IME_DBG_HWCTL_reg)=data)
#define  get_LGCY_IME_DBG_HWCTL_reg                                              (*((volatile unsigned int*)LGCY_IME_DBG_HWCTL_reg))
#define  LGCY_IME_DBG_HWCTL_write_enable1_shift                                  (1)
#define  LGCY_IME_DBG_HWCTL_fsearch_busy_shift                                   (0)
#define  LGCY_IME_DBG_HWCTL_write_enable1_mask                                   (0x00000002)
#define  LGCY_IME_DBG_HWCTL_fsearch_busy_mask                                    (0x00000001)
#define  LGCY_IME_DBG_HWCTL_write_enable1(data)                                  (0x00000002&((data)<<1))
#define  LGCY_IME_DBG_HWCTL_fsearch_busy(data)                                   (0x00000001&(data))
#define  LGCY_IME_DBG_HWCTL_get_write_enable1(data)                              ((0x00000002&(data))>>1)
#define  LGCY_IME_DBG_HWCTL_get_fsearch_busy(data)                               (0x00000001&(data))

#define  LGCY_IME_DBG_GPREG                                                      0x1800F3DC
#define  LGCY_IME_DBG_GPREG_reg_addr                                             "0xB800F3DC"
#define  LGCY_IME_DBG_GPREG_reg                                                  0xB800F3DC
#define  LGCY_IME_DBG_GPREG_inst_addr                                            "0x0033"
#define  set_LGCY_IME_DBG_GPREG_reg(data)                                        (*((volatile unsigned int*)LGCY_IME_DBG_GPREG_reg)=data)
#define  get_LGCY_IME_DBG_GPREG_reg                                              (*((volatile unsigned int*)LGCY_IME_DBG_GPREG_reg))
#define  LGCY_IME_DBG_GPREG_gp1_shift                                            (16)
#define  LGCY_IME_DBG_GPREG_gp0_shift                                            (0)
#define  LGCY_IME_DBG_GPREG_gp1_mask                                             (0xFFFF0000)
#define  LGCY_IME_DBG_GPREG_gp0_mask                                             (0x0000FFFF)
#define  LGCY_IME_DBG_GPREG_gp1(data)                                            (0xFFFF0000&((data)<<16))
#define  LGCY_IME_DBG_GPREG_gp0(data)                                            (0x0000FFFF&(data))
#define  LGCY_IME_DBG_GPREG_get_gp1(data)                                        ((0xFFFF0000&(data))>>16)
#define  LGCY_IME_DBG_GPREG_get_gp0(data)                                        (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGCY_IME register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  ignore_ldref:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  int_stat:1;
        RBus_UInt32  int_en:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  swind_y:4;
        RBus_UInt32  swind_x:4;
        RBus_UInt32  ignore_fme:1;
        RBus_UInt32  mul_dec:1;
        RBus_UInt32  mul_req:1;
        RBus_UInt32  only16:1;
    };
}lgcy_ime_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  sub1616_md:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  cr_thr:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  e0_cr_on:1;
        RBus_UInt32  e0_cr_dst_sub3:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  e0_cr_src:3;
    };
}lgcy_ime_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  idx:7;
    };
}lgcy_ime_tmb_idx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  y:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  x:12;
    };
}lgcy_ime_tmb_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  idx:7;
    };
}lgcy_ime_rmb_idx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rsy:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  rsx:12;
    };
}lgcy_ime_rmb_spos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rey:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  rex:12;
    };
}lgcy_ime_rmb_epos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  num:4;
    };
}lgcy_ime_cand_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  mvy:7;
    };
}lgcy_ime_cand_list_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pmvx:12;
        RBus_UInt32  res2:7;
        RBus_UInt32  pmvy:9;
    };
}lgcy_ime_mvp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  maxfrac:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  maxint:4;
        RBus_UInt32  cbias:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  lambda:7;
    };
}lgcy_ime_mvc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  mvy:7;
    };
}lgcy_ime_rslt16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  tcost:21;
    };
}lgcy_ime_rslt16_tcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  mvy:7;
    };
}lgcy_ime_rslt8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  tcost:21;
    };
}lgcy_ime_rslt8_tcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  satd00:21;
    };
}lgcy_ime_zmv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  mvy:7;
    };
}lgcy_ime_rslt16x8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  tcost:21;
    };
}lgcy_ime_rslt16x8_tcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  mvy:7;
    };
}lgcy_ime_rslt8x16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  tcost:21;
    };
}lgcy_ime_rslt8x16_tcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ref_cost:16;
    };
}lgcy_ime_ref_cost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  sel1:3;
        RBus_UInt32  sel0:3;
        RBus_UInt32  enable:1;
    };
}lgcy_ime_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg1:16;
        RBus_UInt32  reg0:16;
    };
}lgcy_ime_rdbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  ignore_fme:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  force_valid:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  trig:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  mvy:7;
    };
}lgcy_ime_dbg_fme_pmvctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  fsearch_busy:1;
    };
}lgcy_ime_dbg_hwctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp1:16;
        RBus_UInt32  gp0:16;
    };
}lgcy_ime_dbg_gpreg_RBUS;

#else //apply LITTLE_ENDIAN

//======LGCY_IME register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  only16:1;
        RBus_UInt32  mul_req:1;
        RBus_UInt32  mul_dec:1;
        RBus_UInt32  ignore_fme:1;
        RBus_UInt32  swind_x:4;
        RBus_UInt32  swind_y:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  int_en:1;
        RBus_UInt32  int_stat:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ignore_ldref:1;
        RBus_UInt32  res3:11;
    };
}lgcy_ime_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  e0_cr_src:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  e0_cr_dst_sub3:2;
        RBus_UInt32  e0_cr_on:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cr_thr:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  sub1616_md:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  res1:20;
    };
}lgcy_ime_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ime_tmb_idx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  y:12;
        RBus_UInt32  res2:4;
    };
}lgcy_ime_tmb_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:7;
        RBus_UInt32  res1:25;
    };
}lgcy_ime_rmb_idx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsx:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  rsy:12;
        RBus_UInt32  res2:4;
    };
}lgcy_ime_rmb_spos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rex:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  rey:12;
        RBus_UInt32  res2:4;
    };
}lgcy_ime_rmb_epos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  num:4;
        RBus_UInt32  res1:28;
    };
}lgcy_ime_cand_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:14;
    };
}lgcy_ime_cand_list_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pmvy:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  pmvx:12;
        RBus_UInt32  res2:4;
    };
}lgcy_ime_mvp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lambda:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cbias:8;
        RBus_UInt32  maxint:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  maxfrac:5;
        RBus_UInt32  res3:3;
    };
}lgcy_ime_mvc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:14;
    };
}lgcy_ime_rslt16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcost:21;
        RBus_UInt32  res1:11;
    };
}lgcy_ime_rslt16_tcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:14;
    };
}lgcy_ime_rslt8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcost:21;
        RBus_UInt32  res1:11;
    };
}lgcy_ime_rslt8_tcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  satd00:21;
        RBus_UInt32  res1:11;
    };
}lgcy_ime_zmv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:14;
    };
}lgcy_ime_rslt16x8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcost:21;
        RBus_UInt32  res1:11;
    };
}lgcy_ime_rslt16x8_tcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  mvx:10;
        RBus_UInt32  res2:14;
    };
}lgcy_ime_rslt8x16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcost:21;
        RBus_UInt32  res1:11;
    };
}lgcy_ime_rslt8x16_tcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ref_cost:16;
        RBus_UInt32  res1:16;
    };
}lgcy_ime_ref_cost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  sel0:3;
        RBus_UInt32  sel1:3;
        RBus_UInt32  res1:25;
    };
}lgcy_ime_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg0:16;
        RBus_UInt32  reg1:16;
    };
}lgcy_ime_rdbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  mvx:10;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  trig:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  force_valid:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  ignore_fme:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  res3:2;
    };
}lgcy_ime_dbg_fme_pmvctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsearch_busy:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res1:30;
    };
}lgcy_ime_dbg_hwctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp0:16;
        RBus_UInt32  gp1:16;
    };
}lgcy_ime_dbg_gpreg_RBUS;




#endif 


#endif 
