/**
* @file Mac5_VE_IPMD_Arch_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IPMD_REG_H_
#define _RBUS_IPMD_REG_H_

#include "rbus_types.h"



//  IPMD Register Address
#define  IPMD_CTRL                                                               0x1800F100
#define  IPMD_CTRL_reg_addr                                                      "0xB800F100"
#define  IPMD_CTRL_reg                                                           0xB800F100
#define  IPMD_CTRL_inst_addr                                                     "0x0000"
#define  set_IPMD_CTRL_reg(data)                                                 (*((volatile unsigned int*)IPMD_CTRL_reg)=data)
#define  get_IPMD_CTRL_reg                                                       (*((volatile unsigned int*)IPMD_CTRL_reg))
#define  IPMD_CTRL_write_enable7_shift                                           (13)
#define  IPMD_CTRL_off4x4_shift                                                  (12)
#define  IPMD_CTRL_write_enable6_shift                                           (11)
#define  IPMD_CTRL_flush_cmd_disable_shift                                       (10)
#define  IPMD_CTRL_write_enable5_shift                                           (9)
#define  IPMD_CTRL_softrst_disable_shift                                         (8)
#define  IPMD_CTRL_write_enable4_shift                                           (7)
#define  IPMD_CTRL_umem_bypass_shift                                             (6)
#define  IPMD_CTRL_write_enable3_shift                                           (5)
#define  IPMD_CTRL_sreset_busy_clr_shift                                         (4)
#define  IPMD_CTRL_write_enable2_shift                                           (3)
#define  IPMD_CTRL_pwmem_override_shift                                          (2)
#define  IPMD_CTRL_write_enable1_shift                                           (1)
#define  IPMD_CTRL_constr_intra_pred_shift                                       (0)
#define  IPMD_CTRL_write_enable7_mask                                            (0x00002000)
#define  IPMD_CTRL_off4x4_mask                                                   (0x00001000)
#define  IPMD_CTRL_write_enable6_mask                                            (0x00000800)
#define  IPMD_CTRL_flush_cmd_disable_mask                                        (0x00000400)
#define  IPMD_CTRL_write_enable5_mask                                            (0x00000200)
#define  IPMD_CTRL_softrst_disable_mask                                          (0x00000100)
#define  IPMD_CTRL_write_enable4_mask                                            (0x00000080)
#define  IPMD_CTRL_umem_bypass_mask                                              (0x00000040)
#define  IPMD_CTRL_write_enable3_mask                                            (0x00000020)
#define  IPMD_CTRL_sreset_busy_clr_mask                                          (0x00000010)
#define  IPMD_CTRL_write_enable2_mask                                            (0x00000008)
#define  IPMD_CTRL_pwmem_override_mask                                           (0x00000004)
#define  IPMD_CTRL_write_enable1_mask                                            (0x00000002)
#define  IPMD_CTRL_constr_intra_pred_mask                                        (0x00000001)
#define  IPMD_CTRL_write_enable7(data)                                           (0x00002000&((data)<<13))
#define  IPMD_CTRL_off4x4(data)                                                  (0x00001000&((data)<<12))
#define  IPMD_CTRL_write_enable6(data)                                           (0x00000800&((data)<<11))
#define  IPMD_CTRL_flush_cmd_disable(data)                                       (0x00000400&((data)<<10))
#define  IPMD_CTRL_write_enable5(data)                                           (0x00000200&((data)<<9))
#define  IPMD_CTRL_softrst_disable(data)                                         (0x00000100&((data)<<8))
#define  IPMD_CTRL_write_enable4(data)                                           (0x00000080&((data)<<7))
#define  IPMD_CTRL_umem_bypass(data)                                             (0x00000040&((data)<<6))
#define  IPMD_CTRL_write_enable3(data)                                           (0x00000020&((data)<<5))
#define  IPMD_CTRL_sreset_busy_clr(data)                                         (0x00000010&((data)<<4))
#define  IPMD_CTRL_write_enable2(data)                                           (0x00000008&((data)<<3))
#define  IPMD_CTRL_pwmem_override(data)                                          (0x00000004&((data)<<2))
#define  IPMD_CTRL_write_enable1(data)                                           (0x00000002&((data)<<1))
#define  IPMD_CTRL_constr_intra_pred(data)                                       (0x00000001&(data))
#define  IPMD_CTRL_get_write_enable7(data)                                       ((0x00002000&(data))>>13)
#define  IPMD_CTRL_get_off4x4(data)                                              ((0x00001000&(data))>>12)
#define  IPMD_CTRL_get_write_enable6(data)                                       ((0x00000800&(data))>>11)
#define  IPMD_CTRL_get_flush_cmd_disable(data)                                   ((0x00000400&(data))>>10)
#define  IPMD_CTRL_get_write_enable5(data)                                       ((0x00000200&(data))>>9)
#define  IPMD_CTRL_get_softrst_disable(data)                                     ((0x00000100&(data))>>8)
#define  IPMD_CTRL_get_write_enable4(data)                                       ((0x00000080&(data))>>7)
#define  IPMD_CTRL_get_umem_bypass(data)                                         ((0x00000040&(data))>>6)
#define  IPMD_CTRL_get_write_enable3(data)                                       ((0x00000020&(data))>>5)
#define  IPMD_CTRL_get_sreset_busy_clr(data)                                     ((0x00000010&(data))>>4)
#define  IPMD_CTRL_get_write_enable2(data)                                       ((0x00000008&(data))>>3)
#define  IPMD_CTRL_get_pwmem_override(data)                                      ((0x00000004&(data))>>2)
#define  IPMD_CTRL_get_write_enable1(data)                                       ((0x00000002&(data))>>1)
#define  IPMD_CTRL_get_constr_intra_pred(data)                                   (0x00000001&(data))

#define  IPMD_INTRA_0                                                            0x1800F10C
#define  IPMD_INTRA_0_reg_addr                                                   "0xB800F10C"
#define  IPMD_INTRA_0_reg                                                        0xB800F10C
#define  IPMD_INTRA_0_inst_addr                                                  "0x0001"
#define  set_IPMD_INTRA_0_reg(data)                                              (*((volatile unsigned int*)IPMD_INTRA_0_reg)=data)
#define  get_IPMD_INTRA_0_reg                                                    (*((volatile unsigned int*)IPMD_INTRA_0_reg))
#define  IPMD_INTRA_0_intra_flag_shift                                           (0)
#define  IPMD_INTRA_0_intra_flag_mask                                            (0xFFFFFFFF)
#define  IPMD_INTRA_0_intra_flag(data)                                           (0xFFFFFFFF&(data))
#define  IPMD_INTRA_0_get_intra_flag(data)                                       (0xFFFFFFFF&(data))

#define  IPMD_INTRA_1                                                            0x1800F110
#define  IPMD_INTRA_1_reg_addr                                                   "0xB800F110"
#define  IPMD_INTRA_1_reg                                                        0xB800F110
#define  IPMD_INTRA_1_inst_addr                                                  "0x0002"
#define  set_IPMD_INTRA_1_reg(data)                                              (*((volatile unsigned int*)IPMD_INTRA_1_reg)=data)
#define  get_IPMD_INTRA_1_reg                                                    (*((volatile unsigned int*)IPMD_INTRA_1_reg))
#define  IPMD_INTRA_1_intra_flag_shift                                           (0)
#define  IPMD_INTRA_1_intra_flag_mask                                            (0xFFFFFFFF)
#define  IPMD_INTRA_1_intra_flag(data)                                           (0xFFFFFFFF&(data))
#define  IPMD_INTRA_1_get_intra_flag(data)                                       (0xFFFFFFFF&(data))

#define  IPMD_INTRA_2                                                            0x1800F114
#define  IPMD_INTRA_2_reg_addr                                                   "0xB800F114"
#define  IPMD_INTRA_2_reg                                                        0xB800F114
#define  IPMD_INTRA_2_inst_addr                                                  "0x0003"
#define  set_IPMD_INTRA_2_reg(data)                                              (*((volatile unsigned int*)IPMD_INTRA_2_reg)=data)
#define  get_IPMD_INTRA_2_reg                                                    (*((volatile unsigned int*)IPMD_INTRA_2_reg))
#define  IPMD_INTRA_2_intra_flag_shift                                           (0)
#define  IPMD_INTRA_2_intra_flag_mask                                            (0xFFFFFFFF)
#define  IPMD_INTRA_2_intra_flag(data)                                           (0xFFFFFFFF&(data))
#define  IPMD_INTRA_2_get_intra_flag(data)                                       (0xFFFFFFFF&(data))

#define  IPMD_INTRA_3                                                            0x1800F118
#define  IPMD_INTRA_3_reg_addr                                                   "0xB800F118"
#define  IPMD_INTRA_3_reg                                                        0xB800F118
#define  IPMD_INTRA_3_inst_addr                                                  "0x0004"
#define  set_IPMD_INTRA_3_reg(data)                                              (*((volatile unsigned int*)IPMD_INTRA_3_reg)=data)
#define  get_IPMD_INTRA_3_reg                                                    (*((volatile unsigned int*)IPMD_INTRA_3_reg))
#define  IPMD_INTRA_3_intra_flag_shift                                           (0)
#define  IPMD_INTRA_3_intra_flag_mask                                            (0xFFFFFFFF)
#define  IPMD_INTRA_3_intra_flag(data)                                           (0xFFFFFFFF&(data))
#define  IPMD_INTRA_3_get_intra_flag(data)                                       (0xFFFFFFFF&(data))

#define  IPMD_INTR_THRESH                                                        0x1800F120
#define  IPMD_INTR_THRESH_reg_addr                                               "0xB800F120"
#define  IPMD_INTR_THRESH_reg                                                    0xB800F120
#define  IPMD_INTR_THRESH_inst_addr                                              "0x0005"
#define  set_IPMD_INTR_THRESH_reg(data)                                          (*((volatile unsigned int*)IPMD_INTR_THRESH_reg)=data)
#define  get_IPMD_INTR_THRESH_reg                                                (*((volatile unsigned int*)IPMD_INTR_THRESH_reg))
#define  IPMD_INTR_THRESH_value_shift                                            (0)
#define  IPMD_INTR_THRESH_value_mask                                             (0x0FFFFFFF)
#define  IPMD_INTR_THRESH_value(data)                                            (0x0FFFFFFF&(data))
#define  IPMD_INTR_THRESH_get_value(data)                                        (0x0FFFFFFF&(data))

#define  IPMD_BUSY                                                               0x1800F124
#define  IPMD_BUSY_reg_addr                                                      "0xB800F124"
#define  IPMD_BUSY_reg                                                           0xB800F124
#define  IPMD_BUSY_inst_addr                                                     "0x0006"
#define  set_IPMD_BUSY_reg(data)                                                 (*((volatile unsigned int*)IPMD_BUSY_reg)=data)
#define  get_IPMD_BUSY_reg                                                       (*((volatile unsigned int*)IPMD_BUSY_reg))
#define  IPMD_BUSY_reach_thresh_shift                                            (28)
#define  IPMD_BUSY_count_shift                                                   (0)
#define  IPMD_BUSY_reach_thresh_mask                                             (0x10000000)
#define  IPMD_BUSY_count_mask                                                    (0x0FFFFFFF)
#define  IPMD_BUSY_reach_thresh(data)                                            (0x10000000&((data)<<28))
#define  IPMD_BUSY_count(data)                                                   (0x0FFFFFFF&(data))
#define  IPMD_BUSY_get_reach_thresh(data)                                        ((0x10000000&(data))>>28)
#define  IPMD_BUSY_get_count(data)                                               (0x0FFFFFFF&(data))

#define  IPMD_RESULT0                                                            0x1800F128
#define  IPMD_RESULT0_reg_addr                                                   "0xB800F128"
#define  IPMD_RESULT0_reg                                                        0xB800F128
#define  IPMD_RESULT0_inst_addr                                                  "0x0007"
#define  set_IPMD_RESULT0_reg(data)                                              (*((volatile unsigned int*)IPMD_RESULT0_reg)=data)
#define  get_IPMD_RESULT0_reg                                                    (*((volatile unsigned int*)IPMD_RESULT0_reg))
#define  IPMD_RESULT0_luma_part_shift                                            (28)
#define  IPMD_RESULT0_luma_cost_shift                                            (0)
#define  IPMD_RESULT0_luma_part_mask                                             (0x30000000)
#define  IPMD_RESULT0_luma_cost_mask                                             (0x001FFFFF)
#define  IPMD_RESULT0_luma_part(data)                                            (0x30000000&((data)<<28))
#define  IPMD_RESULT0_luma_cost(data)                                            (0x001FFFFF&(data))
#define  IPMD_RESULT0_get_luma_part(data)                                        ((0x30000000&(data))>>28)
#define  IPMD_RESULT0_get_luma_cost(data)                                        (0x001FFFFF&(data))

#define  IPMD_RESULT1                                                            0x1800F12C
#define  IPMD_RESULT1_reg_addr                                                   "0xB800F12C"
#define  IPMD_RESULT1_reg                                                        0xB800F12C
#define  IPMD_RESULT1_inst_addr                                                  "0x0008"
#define  set_IPMD_RESULT1_reg(data)                                              (*((volatile unsigned int*)IPMD_RESULT1_reg)=data)
#define  get_IPMD_RESULT1_reg                                                    (*((volatile unsigned int*)IPMD_RESULT1_reg))
#define  IPMD_RESULT1_chroma_cost_shift                                          (0)
#define  IPMD_RESULT1_chroma_cost_mask                                           (0x001FFFFF)
#define  IPMD_RESULT1_chroma_cost(data)                                          (0x001FFFFF&(data))
#define  IPMD_RESULT1_get_chroma_cost(data)                                      (0x001FFFFF&(data))

#define  IPMD_LAMBDA                                                             0x1800F130
#define  IPMD_LAMBDA_reg_addr                                                    "0xB800F130"
#define  IPMD_LAMBDA_reg                                                         0xB800F130
#define  IPMD_LAMBDA_inst_addr                                                   "0x0009"
#define  set_IPMD_LAMBDA_reg(data)                                               (*((volatile unsigned int*)IPMD_LAMBDA_reg)=data)
#define  get_IPMD_LAMBDA_reg                                                     (*((volatile unsigned int*)IPMD_LAMBDA_reg))
#define  IPMD_LAMBDA_value_shift                                                 (0)
#define  IPMD_LAMBDA_value_mask                                                  (0x0000007F)
#define  IPMD_LAMBDA_value(data)                                                 (0x0000007F&(data))
#define  IPMD_LAMBDA_get_value(data)                                             (0x0000007F&(data))

#define  IPMD_WEIGHT_0                                                           0x1800F134
#define  IPMD_WEIGHT_0_reg_addr                                                  "0xB800F134"
#define  IPMD_WEIGHT_0_reg                                                       0xB800F134
#define  IPMD_WEIGHT_0_inst_addr                                                 "0x000A"
#define  set_IPMD_WEIGHT_0_reg(data)                                             (*((volatile unsigned int*)IPMD_WEIGHT_0_reg)=data)
#define  get_IPMD_WEIGHT_0_reg                                                   (*((volatile unsigned int*)IPMD_WEIGHT_0_reg))
#define  IPMD_WEIGHT_0_value_shift                                               (0)
#define  IPMD_WEIGHT_0_value_mask                                                (0x001FFFFF)
#define  IPMD_WEIGHT_0_value(data)                                               (0x001FFFFF&(data))
#define  IPMD_WEIGHT_0_get_value(data)                                           (0x001FFFFF&(data))

#define  IPMD_WEIGHT_1                                                           0x1800F138
#define  IPMD_WEIGHT_1_reg_addr                                                  "0xB800F138"
#define  IPMD_WEIGHT_1_reg                                                       0xB800F138
#define  IPMD_WEIGHT_1_inst_addr                                                 "0x000B"
#define  set_IPMD_WEIGHT_1_reg(data)                                             (*((volatile unsigned int*)IPMD_WEIGHT_1_reg)=data)
#define  get_IPMD_WEIGHT_1_reg                                                   (*((volatile unsigned int*)IPMD_WEIGHT_1_reg))
#define  IPMD_WEIGHT_1_value_shift                                               (0)
#define  IPMD_WEIGHT_1_value_mask                                                (0x001FFFFF)
#define  IPMD_WEIGHT_1_value(data)                                               (0x001FFFFF&(data))
#define  IPMD_WEIGHT_1_get_value(data)                                           (0x001FFFFF&(data))

#define  IPMD_WEIGHT_2                                                           0x1800F13C
#define  IPMD_WEIGHT_2_reg_addr                                                  "0xB800F13C"
#define  IPMD_WEIGHT_2_reg                                                       0xB800F13C
#define  IPMD_WEIGHT_2_inst_addr                                                 "0x000C"
#define  set_IPMD_WEIGHT_2_reg(data)                                             (*((volatile unsigned int*)IPMD_WEIGHT_2_reg)=data)
#define  get_IPMD_WEIGHT_2_reg                                                   (*((volatile unsigned int*)IPMD_WEIGHT_2_reg))
#define  IPMD_WEIGHT_2_value_shift                                               (0)
#define  IPMD_WEIGHT_2_value_mask                                                (0x001FFFFF)
#define  IPMD_WEIGHT_2_value(data)                                               (0x001FFFFF&(data))
#define  IPMD_WEIGHT_2_get_value(data)                                           (0x001FFFFF&(data))

#define  IPMD_DBUS1                                                              0x1800F140
#define  IPMD_DBUS1_reg_addr                                                     "0xB800F140"
#define  IPMD_DBUS1_reg                                                          0xB800F140
#define  IPMD_DBUS1_inst_addr                                                    "0x000D"
#define  set_IPMD_DBUS1_reg(data)                                                (*((volatile unsigned int*)IPMD_DBUS1_reg)=data)
#define  get_IPMD_DBUS1_reg                                                      (*((volatile unsigned int*)IPMD_DBUS1_reg))
#define  IPMD_DBUS1_genpulse_shift                                               (31)
#define  IPMD_DBUS1_dbgctrl_shift                                                (28)
#define  IPMD_DBUS1_piccount_shift                                               (14)
#define  IPMD_DBUS1_mbaddrx_shift                                                (7)
#define  IPMD_DBUS1_mbaddry_shift                                                (0)
#define  IPMD_DBUS1_genpulse_mask                                                (0x80000000)
#define  IPMD_DBUS1_dbgctrl_mask                                                 (0x70000000)
#define  IPMD_DBUS1_piccount_mask                                                (0x0FFFC000)
#define  IPMD_DBUS1_mbaddrx_mask                                                 (0x00003F80)
#define  IPMD_DBUS1_mbaddry_mask                                                 (0x0000007F)
#define  IPMD_DBUS1_genpulse(data)                                               (0x80000000&((data)<<31))
#define  IPMD_DBUS1_dbgctrl(data)                                                (0x70000000&((data)<<28))
#define  IPMD_DBUS1_piccount(data)                                               (0x0FFFC000&((data)<<14))
#define  IPMD_DBUS1_mbaddrx(data)                                                (0x00003F80&((data)<<7))
#define  IPMD_DBUS1_mbaddry(data)                                                (0x0000007F&(data))
#define  IPMD_DBUS1_get_genpulse(data)                                           ((0x80000000&(data))>>31)
#define  IPMD_DBUS1_get_dbgctrl(data)                                            ((0x70000000&(data))>>28)
#define  IPMD_DBUS1_get_piccount(data)                                           ((0x0FFFC000&(data))>>14)
#define  IPMD_DBUS1_get_mbaddrx(data)                                            ((0x00003F80&(data))>>7)
#define  IPMD_DBUS1_get_mbaddry(data)                                            (0x0000007F&(data))

#define  IPMD_DBUS2                                                              0x1800F144
#define  IPMD_DBUS2_reg_addr                                                     "0xB800F144"
#define  IPMD_DBUS2_reg                                                          0xB800F144
#define  IPMD_DBUS2_inst_addr                                                    "0x000E"
#define  set_IPMD_DBUS2_reg(data)                                                (*((volatile unsigned int*)IPMD_DBUS2_reg)=data)
#define  get_IPMD_DBUS2_reg                                                      (*((volatile unsigned int*)IPMD_DBUS2_reg))
#define  IPMD_DBUS2_dbgctrl_shift                                                (0)
#define  IPMD_DBUS2_dbgctrl_mask                                                 (0xFFFFFFFF)
#define  IPMD_DBUS2_dbgctrl(data)                                                (0xFFFFFFFF&(data))
#define  IPMD_DBUS2_get_dbgctrl(data)                                            (0xFFFFFFFF&(data))

#define  IPMD_COST0                                                              0x1800F148
#define  IPMD_COST0_reg_addr                                                     "0xB800F148"
#define  IPMD_COST0_reg                                                          0xB800F148
#define  IPMD_COST0_inst_addr                                                    "0x000F"
#define  set_IPMD_COST0_reg(data)                                                (*((volatile unsigned int*)IPMD_COST0_reg)=data)
#define  get_IPMD_COST0_reg                                                      (*((volatile unsigned int*)IPMD_COST0_reg))
#define  IPMD_COST0_r_16x16_0_shift                                              (28)
#define  IPMD_COST0_r_16x16_1_shift                                              (24)
#define  IPMD_COST0_r_16x16_2_shift                                              (20)
#define  IPMD_COST0_r_16x16_3_shift                                              (16)
#define  IPMD_COST0_r_chroma_0_shift                                             (12)
#define  IPMD_COST0_r_chroma_1_shift                                             (8)
#define  IPMD_COST0_r_chroma_2_shift                                             (4)
#define  IPMD_COST0_r_chroma_3_shift                                             (0)
#define  IPMD_COST0_r_16x16_0_mask                                               (0xF0000000)
#define  IPMD_COST0_r_16x16_1_mask                                               (0x0F000000)
#define  IPMD_COST0_r_16x16_2_mask                                               (0x00F00000)
#define  IPMD_COST0_r_16x16_3_mask                                               (0x000F0000)
#define  IPMD_COST0_r_chroma_0_mask                                              (0x0000F000)
#define  IPMD_COST0_r_chroma_1_mask                                              (0x00000F00)
#define  IPMD_COST0_r_chroma_2_mask                                              (0x000000F0)
#define  IPMD_COST0_r_chroma_3_mask                                              (0x0000000F)
#define  IPMD_COST0_r_16x16_0(data)                                              (0xF0000000&((data)<<28))
#define  IPMD_COST0_r_16x16_1(data)                                              (0x0F000000&((data)<<24))
#define  IPMD_COST0_r_16x16_2(data)                                              (0x00F00000&((data)<<20))
#define  IPMD_COST0_r_16x16_3(data)                                              (0x000F0000&((data)<<16))
#define  IPMD_COST0_r_chroma_0(data)                                             (0x0000F000&((data)<<12))
#define  IPMD_COST0_r_chroma_1(data)                                             (0x00000F00&((data)<<8))
#define  IPMD_COST0_r_chroma_2(data)                                             (0x000000F0&((data)<<4))
#define  IPMD_COST0_r_chroma_3(data)                                             (0x0000000F&(data))
#define  IPMD_COST0_get_r_16x16_0(data)                                          ((0xF0000000&(data))>>28)
#define  IPMD_COST0_get_r_16x16_1(data)                                          ((0x0F000000&(data))>>24)
#define  IPMD_COST0_get_r_16x16_2(data)                                          ((0x00F00000&(data))>>20)
#define  IPMD_COST0_get_r_16x16_3(data)                                          ((0x000F0000&(data))>>16)
#define  IPMD_COST0_get_r_chroma_0(data)                                         ((0x0000F000&(data))>>12)
#define  IPMD_COST0_get_r_chroma_1(data)                                         ((0x00000F00&(data))>>8)
#define  IPMD_COST0_get_r_chroma_2(data)                                         ((0x000000F0&(data))>>4)
#define  IPMD_COST0_get_r_chroma_3(data)                                         (0x0000000F&(data))

#define  IPMD_COST1                                                              0x1800F14C
#define  IPMD_COST1_reg_addr                                                     "0xB800F14C"
#define  IPMD_COST1_reg                                                          0xB800F14C
#define  IPMD_COST1_inst_addr                                                    "0x0010"
#define  set_IPMD_COST1_reg(data)                                                (*((volatile unsigned int*)IPMD_COST1_reg)=data)
#define  get_IPMD_COST1_reg                                                      (*((volatile unsigned int*)IPMD_COST1_reg))
#define  IPMD_COST1_r_same_8x8_shift                                             (12)
#define  IPMD_COST1_r_diff_8x8_shift                                             (8)
#define  IPMD_COST1_r_same_4x4_shift                                             (4)
#define  IPMD_COST1_r_diff_4x4_shift                                             (0)
#define  IPMD_COST1_r_same_8x8_mask                                              (0x0000F000)
#define  IPMD_COST1_r_diff_8x8_mask                                              (0x00000F00)
#define  IPMD_COST1_r_same_4x4_mask                                              (0x000000F0)
#define  IPMD_COST1_r_diff_4x4_mask                                              (0x0000000F)
#define  IPMD_COST1_r_same_8x8(data)                                             (0x0000F000&((data)<<12))
#define  IPMD_COST1_r_diff_8x8(data)                                             (0x00000F00&((data)<<8))
#define  IPMD_COST1_r_same_4x4(data)                                             (0x000000F0&((data)<<4))
#define  IPMD_COST1_r_diff_4x4(data)                                             (0x0000000F&(data))
#define  IPMD_COST1_get_r_same_8x8(data)                                         ((0x0000F000&(data))>>12)
#define  IPMD_COST1_get_r_diff_8x8(data)                                         ((0x00000F00&(data))>>8)
#define  IPMD_COST1_get_r_same_4x4(data)                                         ((0x000000F0&(data))>>4)
#define  IPMD_COST1_get_r_diff_4x4(data)                                         (0x0000000F&(data))

#define  IPMD_INTRAMODE_0                                                        0x1800F150
#define  IPMD_INTRAMODE_0_reg_addr                                               "0xB800F150"
#define  IPMD_INTRAMODE_0_reg                                                    0xB800F150
#define  IPMD_INTRAMODE_0_inst_addr                                              "0x0011"
#define  set_IPMD_INTRAMODE_0_reg(data)                                          (*((volatile unsigned int*)IPMD_INTRAMODE_0_reg)=data)
#define  get_IPMD_INTRAMODE_0_reg                                                (*((volatile unsigned int*)IPMD_INTRAMODE_0_reg))
#define  IPMD_INTRAMODE_0_value_shift                                            (0)
#define  IPMD_INTRAMODE_0_value_mask                                             (0xFFFFFFFF)
#define  IPMD_INTRAMODE_0_value(data)                                            (0xFFFFFFFF&(data))
#define  IPMD_INTRAMODE_0_get_value(data)                                        (0xFFFFFFFF&(data))

#define  IPMD_INTRAMODE_1                                                        0x1800F154
#define  IPMD_INTRAMODE_1_reg_addr                                               "0xB800F154"
#define  IPMD_INTRAMODE_1_reg                                                    0xB800F154
#define  IPMD_INTRAMODE_1_inst_addr                                              "0x0012"
#define  set_IPMD_INTRAMODE_1_reg(data)                                          (*((volatile unsigned int*)IPMD_INTRAMODE_1_reg)=data)
#define  get_IPMD_INTRAMODE_1_reg                                                (*((volatile unsigned int*)IPMD_INTRAMODE_1_reg))
#define  IPMD_INTRAMODE_1_value_shift                                            (0)
#define  IPMD_INTRAMODE_1_value_mask                                             (0xFFFFFFFF)
#define  IPMD_INTRAMODE_1_value(data)                                            (0xFFFFFFFF&(data))
#define  IPMD_INTRAMODE_1_get_value(data)                                        (0xFFFFFFFF&(data))

#define  IPMD_INTRAMODE_2                                                        0x1800F158
#define  IPMD_INTRAMODE_2_reg_addr                                               "0xB800F158"
#define  IPMD_INTRAMODE_2_reg                                                    0xB800F158
#define  IPMD_INTRAMODE_2_inst_addr                                              "0x0013"
#define  set_IPMD_INTRAMODE_2_reg(data)                                          (*((volatile unsigned int*)IPMD_INTRAMODE_2_reg)=data)
#define  get_IPMD_INTRAMODE_2_reg                                                (*((volatile unsigned int*)IPMD_INTRAMODE_2_reg))
#define  IPMD_INTRAMODE_2_value_shift                                            (0)
#define  IPMD_INTRAMODE_2_value_mask                                             (0xFFFFFFFF)
#define  IPMD_INTRAMODE_2_value(data)                                            (0xFFFFFFFF&(data))
#define  IPMD_INTRAMODE_2_get_value(data)                                        (0xFFFFFFFF&(data))

#define  IPMD_REMMODE_0                                                          0x1800F15C
#define  IPMD_REMMODE_0_reg_addr                                                 "0xB800F15C"
#define  IPMD_REMMODE_0_reg                                                      0xB800F15C
#define  IPMD_REMMODE_0_inst_addr                                                "0x0014"
#define  set_IPMD_REMMODE_0_reg(data)                                            (*((volatile unsigned int*)IPMD_REMMODE_0_reg)=data)
#define  get_IPMD_REMMODE_0_reg                                                  (*((volatile unsigned int*)IPMD_REMMODE_0_reg))
#define  IPMD_REMMODE_0_luma_shift                                               (0)
#define  IPMD_REMMODE_0_luma_mask                                                (0xFFFFFFFF)
#define  IPMD_REMMODE_0_luma(data)                                               (0xFFFFFFFF&(data))
#define  IPMD_REMMODE_0_get_luma(data)                                           (0xFFFFFFFF&(data))

#define  IPMD_REMMODE_1                                                          0x1800F160
#define  IPMD_REMMODE_1_reg_addr                                                 "0xB800F160"
#define  IPMD_REMMODE_1_reg                                                      0xB800F160
#define  IPMD_REMMODE_1_inst_addr                                                "0x0015"
#define  set_IPMD_REMMODE_1_reg(data)                                            (*((volatile unsigned int*)IPMD_REMMODE_1_reg)=data)
#define  get_IPMD_REMMODE_1_reg                                                  (*((volatile unsigned int*)IPMD_REMMODE_1_reg))
#define  IPMD_REMMODE_1_luma_shift                                               (0)
#define  IPMD_REMMODE_1_luma_mask                                                (0xFFFFFFFF)
#define  IPMD_REMMODE_1_luma(data)                                               (0xFFFFFFFF&(data))
#define  IPMD_REMMODE_1_get_luma(data)                                           (0xFFFFFFFF&(data))

#define  IPMD_REMMODE_2                                                          0x1800F164
#define  IPMD_REMMODE_2_reg_addr                                                 "0xB800F164"
#define  IPMD_REMMODE_2_reg                                                      0xB800F164
#define  IPMD_REMMODE_2_inst_addr                                                "0x0016"
#define  set_IPMD_REMMODE_2_reg(data)                                            (*((volatile unsigned int*)IPMD_REMMODE_2_reg)=data)
#define  get_IPMD_REMMODE_2_reg                                                  (*((volatile unsigned int*)IPMD_REMMODE_2_reg))
#define  IPMD_REMMODE_2_luma_shift                                               (0)
#define  IPMD_REMMODE_2_luma_mask                                                (0xFFFFFFFF)
#define  IPMD_REMMODE_2_luma(data)                                               (0xFFFFFFFF&(data))
#define  IPMD_REMMODE_2_get_luma(data)                                           (0xFFFFFFFF&(data))

#define  IPMD_SLICE                                                              0x1800F168
#define  IPMD_SLICE_reg_addr                                                     "0xB800F168"
#define  IPMD_SLICE_reg                                                          0xB800F168
#define  IPMD_SLICE_inst_addr                                                    "0x0017"
#define  set_IPMD_SLICE_reg(data)                                                (*((volatile unsigned int*)IPMD_SLICE_reg)=data)
#define  get_IPMD_SLICE_reg                                                      (*((volatile unsigned int*)IPMD_SLICE_reg))
#define  IPMD_SLICE_y_shift                                                      (0)
#define  IPMD_SLICE_y_mask                                                       (0x0000007F)
#define  IPMD_SLICE_y(data)                                                      (0x0000007F&(data))
#define  IPMD_SLICE_get_y(data)                                                  (0x0000007F&(data))

#define  IPMD_NPM_CTRL                                                           0x1800F16C
#define  IPMD_NPM_CTRL_reg_addr                                                  "0xB800F16C"
#define  IPMD_NPM_CTRL_reg                                                       0xB800F16C
#define  IPMD_NPM_CTRL_inst_addr                                                 "0x0018"
#define  set_IPMD_NPM_CTRL_reg(data)                                             (*((volatile unsigned int*)IPMD_NPM_CTRL_reg)=data)
#define  get_IPMD_NPM_CTRL_reg                                                   (*((volatile unsigned int*)IPMD_NPM_CTRL_reg))
#define  IPMD_NPM_CTRL_write_pulse_shift                                         (31)
#define  IPMD_NPM_CTRL_read_pulse_shift                                          (30)
#define  IPMD_NPM_CTRL_address_shift                                             (20)
#define  IPMD_NPM_CTRL_intrasel_shift                                            (16)
#define  IPMD_NPM_CTRL_subpart0_shift                                            (12)
#define  IPMD_NPM_CTRL_subpart1_shift                                            (8)
#define  IPMD_NPM_CTRL_subpart2_shift                                            (4)
#define  IPMD_NPM_CTRL_subpart3_shift                                            (0)
#define  IPMD_NPM_CTRL_write_pulse_mask                                          (0x80000000)
#define  IPMD_NPM_CTRL_read_pulse_mask                                           (0x40000000)
#define  IPMD_NPM_CTRL_address_mask                                              (0x07F00000)
#define  IPMD_NPM_CTRL_intrasel_mask                                             (0x00030000)
#define  IPMD_NPM_CTRL_subpart0_mask                                             (0x0000F000)
#define  IPMD_NPM_CTRL_subpart1_mask                                             (0x00000F00)
#define  IPMD_NPM_CTRL_subpart2_mask                                             (0x000000F0)
#define  IPMD_NPM_CTRL_subpart3_mask                                             (0x0000000F)
#define  IPMD_NPM_CTRL_write_pulse(data)                                         (0x80000000&((data)<<31))
#define  IPMD_NPM_CTRL_read_pulse(data)                                          (0x40000000&((data)<<30))
#define  IPMD_NPM_CTRL_address(data)                                             (0x07F00000&((data)<<20))
#define  IPMD_NPM_CTRL_intrasel(data)                                            (0x00030000&((data)<<16))
#define  IPMD_NPM_CTRL_subpart0(data)                                            (0x0000F000&((data)<<12))
#define  IPMD_NPM_CTRL_subpart1(data)                                            (0x00000F00&((data)<<8))
#define  IPMD_NPM_CTRL_subpart2(data)                                            (0x000000F0&((data)<<4))
#define  IPMD_NPM_CTRL_subpart3(data)                                            (0x0000000F&(data))
#define  IPMD_NPM_CTRL_get_write_pulse(data)                                     ((0x80000000&(data))>>31)
#define  IPMD_NPM_CTRL_get_read_pulse(data)                                      ((0x40000000&(data))>>30)
#define  IPMD_NPM_CTRL_get_address(data)                                         ((0x07F00000&(data))>>20)
#define  IPMD_NPM_CTRL_get_intrasel(data)                                        ((0x00030000&(data))>>16)
#define  IPMD_NPM_CTRL_get_subpart0(data)                                        ((0x0000F000&(data))>>12)
#define  IPMD_NPM_CTRL_get_subpart1(data)                                        ((0x00000F00&(data))>>8)
#define  IPMD_NPM_CTRL_get_subpart2(data)                                        ((0x000000F0&(data))>>4)
#define  IPMD_NPM_CTRL_get_subpart3(data)                                        (0x0000000F&(data))

#define  IPMD_ULPRED                                                             0x1800F170
#define  IPMD_ULPRED_reg_addr                                                    "0xB800F170"
#define  IPMD_ULPRED_reg                                                         0xB800F170
#define  IPMD_ULPRED_inst_addr                                                   "0x0019"
#define  set_IPMD_ULPRED_reg(data)                                               (*((volatile unsigned int*)IPMD_ULPRED_reg)=data)
#define  get_IPMD_ULPRED_reg                                                     (*((volatile unsigned int*)IPMD_ULPRED_reg))
#define  IPMD_ULPRED_luma_wr_shift                                               (26)
#define  IPMD_ULPRED_cb_wr_shift                                                 (25)
#define  IPMD_ULPRED_cr_wr_shift                                                 (24)
#define  IPMD_ULPRED_luma_shift                                                  (16)
#define  IPMD_ULPRED_cb_shift                                                    (8)
#define  IPMD_ULPRED_cr_shift                                                    (0)
#define  IPMD_ULPRED_luma_wr_mask                                                (0x04000000)
#define  IPMD_ULPRED_cb_wr_mask                                                  (0x02000000)
#define  IPMD_ULPRED_cr_wr_mask                                                  (0x01000000)
#define  IPMD_ULPRED_luma_mask                                                   (0x00FF0000)
#define  IPMD_ULPRED_cb_mask                                                     (0x0000FF00)
#define  IPMD_ULPRED_cr_mask                                                     (0x000000FF)
#define  IPMD_ULPRED_luma_wr(data)                                               (0x04000000&((data)<<26))
#define  IPMD_ULPRED_cb_wr(data)                                                 (0x02000000&((data)<<25))
#define  IPMD_ULPRED_cr_wr(data)                                                 (0x01000000&((data)<<24))
#define  IPMD_ULPRED_luma(data)                                                  (0x00FF0000&((data)<<16))
#define  IPMD_ULPRED_cb(data)                                                    (0x0000FF00&((data)<<8))
#define  IPMD_ULPRED_cr(data)                                                    (0x000000FF&(data))
#define  IPMD_ULPRED_get_luma_wr(data)                                           ((0x04000000&(data))>>26)
#define  IPMD_ULPRED_get_cb_wr(data)                                             ((0x02000000&(data))>>25)
#define  IPMD_ULPRED_get_cr_wr(data)                                             ((0x01000000&(data))>>24)
#define  IPMD_ULPRED_get_luma(data)                                              ((0x00FF0000&(data))>>16)
#define  IPMD_ULPRED_get_cb(data)                                                ((0x0000FF00&(data))>>8)
#define  IPMD_ULPRED_get_cr(data)                                                (0x000000FF&(data))

#define  IPMD_CBPCTRL                                                            0x1800F174
#define  IPMD_CBPCTRL_reg_addr                                                   "0xB800F174"
#define  IPMD_CBPCTRL_reg                                                        0xB800F174
#define  IPMD_CBPCTRL_inst_addr                                                  "0x001A"
#define  set_IPMD_CBPCTRL_reg(data)                                              (*((volatile unsigned int*)IPMD_CBPCTRL_reg)=data)
#define  get_IPMD_CBPCTRL_reg                                                    (*((volatile unsigned int*)IPMD_CBPCTRL_reg))
#define  IPMD_CBPCTRL_intralumastylesel_shift                                    (5)
#define  IPMD_CBPCTRL_intralumastylesel_mask                                     (0x00000020)
#define  IPMD_CBPCTRL_intralumastylesel(data)                                    (0x00000020&((data)<<5))
#define  IPMD_CBPCTRL_get_intralumastylesel(data)                                ((0x00000020&(data))>>5)

#define  IPMD_SUMRUNCOST_4x4_0                                                   0x1800F198
#define  IPMD_SUMRUNCOST_4x4_0_reg_addr                                          "0xB800F198"
#define  IPMD_SUMRUNCOST_4x4_0_reg                                               0xB800F198
#define  IPMD_SUMRUNCOST_4x4_0_inst_addr                                         "0x001B"
#define  set_IPMD_SUMRUNCOST_4x4_0_reg(data)                                     (*((volatile unsigned int*)IPMD_SUMRUNCOST_4x4_0_reg)=data)
#define  get_IPMD_SUMRUNCOST_4x4_0_reg                                           (*((volatile unsigned int*)IPMD_SUMRUNCOST_4x4_0_reg))
#define  IPMD_SUMRUNCOST_4x4_0_lookup_shift                                      (0)
#define  IPMD_SUMRUNCOST_4x4_0_lookup_mask                                       (0xFFFFFFFF)
#define  IPMD_SUMRUNCOST_4x4_0_lookup(data)                                      (0xFFFFFFFF&(data))
#define  IPMD_SUMRUNCOST_4x4_0_get_lookup(data)                                  (0xFFFFFFFF&(data))

#define  IPMD_SUMRUNCOST_4x4_1                                                   0x1800F19C
#define  IPMD_SUMRUNCOST_4x4_1_reg_addr                                          "0xB800F19C"
#define  IPMD_SUMRUNCOST_4x4_1_reg                                               0xB800F19C
#define  IPMD_SUMRUNCOST_4x4_1_inst_addr                                         "0x001C"
#define  set_IPMD_SUMRUNCOST_4x4_1_reg(data)                                     (*((volatile unsigned int*)IPMD_SUMRUNCOST_4x4_1_reg)=data)
#define  get_IPMD_SUMRUNCOST_4x4_1_reg                                           (*((volatile unsigned int*)IPMD_SUMRUNCOST_4x4_1_reg))
#define  IPMD_SUMRUNCOST_4x4_1_lookup_shift                                      (0)
#define  IPMD_SUMRUNCOST_4x4_1_lookup_mask                                       (0xFFFFFFFF)
#define  IPMD_SUMRUNCOST_4x4_1_lookup(data)                                      (0xFFFFFFFF&(data))
#define  IPMD_SUMRUNCOST_4x4_1_get_lookup(data)                                  (0xFFFFFFFF&(data))

#define  IPMD_MBLevel_DROP                                                       0x1800F1A0
#define  IPMD_MBLevel_DROP_reg_addr                                              "0xB800F1A0"
#define  IPMD_MBLevel_DROP_reg                                                   0xB800F1A0
#define  IPMD_MBLevel_DROP_inst_addr                                             "0x001D"
#define  set_IPMD_MBLevel_DROP_reg(data)                                         (*((volatile unsigned int*)IPMD_MBLevel_DROP_reg)=data)
#define  get_IPMD_MBLevel_DROP_reg                                               (*((volatile unsigned int*)IPMD_MBLevel_DROP_reg))
#define  IPMD_MBLevel_DROP_enable_shift                                          (13)
#define  IPMD_MBLevel_DROP_thresh_shift                                          (0)
#define  IPMD_MBLevel_DROP_enable_mask                                           (0x00002000)
#define  IPMD_MBLevel_DROP_thresh_mask                                           (0x00001FFF)
#define  IPMD_MBLevel_DROP_enable(data)                                          (0x00002000&((data)<<13))
#define  IPMD_MBLevel_DROP_thresh(data)                                          (0x00001FFF&(data))
#define  IPMD_MBLevel_DROP_get_enable(data)                                      ((0x00002000&(data))>>13)
#define  IPMD_MBLevel_DROP_get_thresh(data)                                      (0x00001FFF&(data))

#define  IPMD_QUANTIZER                                                          0x1800F1A4
#define  IPMD_QUANTIZER_reg_addr                                                 "0xB800F1A4"
#define  IPMD_QUANTIZER_reg                                                      0xB800F1A4
#define  IPMD_QUANTIZER_inst_addr                                                "0x001E"
#define  set_IPMD_QUANTIZER_reg(data)                                            (*((volatile unsigned int*)IPMD_QUANTIZER_reg)=data)
#define  get_IPMD_QUANTIZER_reg                                                  (*((volatile unsigned int*)IPMD_QUANTIZER_reg))
#define  IPMD_QUANTIZER_write_enable3_shift                                      (15)
#define  IPMD_QUANTIZER_flat_qtable_shift                                        (14)
#define  IPMD_QUANTIZER_write_enable2_shift                                      (13)
#define  IPMD_QUANTIZER_qpy_shift                                                (7)
#define  IPMD_QUANTIZER_write_enable1_shift                                      (6)
#define  IPMD_QUANTIZER_qpc_shift                                                (0)
#define  IPMD_QUANTIZER_write_enable3_mask                                       (0x00008000)
#define  IPMD_QUANTIZER_flat_qtable_mask                                         (0x00004000)
#define  IPMD_QUANTIZER_write_enable2_mask                                       (0x00002000)
#define  IPMD_QUANTIZER_qpy_mask                                                 (0x00001F80)
#define  IPMD_QUANTIZER_write_enable1_mask                                       (0x00000040)
#define  IPMD_QUANTIZER_qpc_mask                                                 (0x0000003F)
#define  IPMD_QUANTIZER_write_enable3(data)                                      (0x00008000&((data)<<15))
#define  IPMD_QUANTIZER_flat_qtable(data)                                        (0x00004000&((data)<<14))
#define  IPMD_QUANTIZER_write_enable2(data)                                      (0x00002000&((data)<<13))
#define  IPMD_QUANTIZER_qpy(data)                                                (0x00001F80&((data)<<7))
#define  IPMD_QUANTIZER_write_enable1(data)                                      (0x00000040&((data)<<6))
#define  IPMD_QUANTIZER_qpc(data)                                                (0x0000003F&(data))
#define  IPMD_QUANTIZER_get_write_enable3(data)                                  ((0x00008000&(data))>>15)
#define  IPMD_QUANTIZER_get_flat_qtable(data)                                    ((0x00004000&(data))>>14)
#define  IPMD_QUANTIZER_get_write_enable2(data)                                  ((0x00002000&(data))>>13)
#define  IPMD_QUANTIZER_get_qpy(data)                                            ((0x00001F80&(data))>>7)
#define  IPMD_QUANTIZER_get_write_enable1(data)                                  ((0x00000040&(data))>>6)
#define  IPMD_QUANTIZER_get_qpc(data)                                            (0x0000003F&(data))

#define  IPMD_MBINFO                                                             0x1800F1A8
#define  IPMD_MBINFO_reg_addr                                                    "0xB800F1A8"
#define  IPMD_MBINFO_reg                                                         0xB800F1A8
#define  IPMD_MBINFO_inst_addr                                                   "0x001F"
#define  set_IPMD_MBINFO_reg(data)                                               (*((volatile unsigned int*)IPMD_MBINFO_reg)=data)
#define  get_IPMD_MBINFO_reg                                                     (*((volatile unsigned int*)IPMD_MBINFO_reg))
#define  IPMD_MBINFO_picturetype_shift                                           (21)
#define  IPMD_MBINFO_picturetype_mask                                            (0x00600000)
#define  IPMD_MBINFO_picturetype(data)                                           (0x00600000&((data)<<21))
#define  IPMD_MBINFO_get_picturetype(data)                                       ((0x00600000&(data))>>21)

#define  IPMD_CBP                                                                0x1800F1AC
#define  IPMD_CBP_reg_addr                                                       "0xB800F1AC"
#define  IPMD_CBP_reg                                                            0xB800F1AC
#define  IPMD_CBP_inst_addr                                                      "0x0020"
#define  set_IPMD_CBP_reg(data)                                                  (*((volatile unsigned int*)IPMD_CBP_reg)=data)
#define  get_IPMD_CBP_reg                                                        (*((volatile unsigned int*)IPMD_CBP_reg))
#define  IPMD_CBP_cbp_stay_shift                                                 (4)
#define  IPMD_CBP_cbp_base_shift                                                 (0)
#define  IPMD_CBP_cbp_stay_mask                                                  (0x000000F0)
#define  IPMD_CBP_cbp_base_mask                                                  (0x0000000F)
#define  IPMD_CBP_cbp_stay(data)                                                 (0x000000F0&((data)<<4))
#define  IPMD_CBP_cbp_base(data)                                                 (0x0000000F&(data))
#define  IPMD_CBP_get_cbp_stay(data)                                             ((0x000000F0&(data))>>4)
#define  IPMD_CBP_get_cbp_base(data)                                             (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IPMD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  off4x4:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  flush_cmd_disable:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  softrst_disable:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  umem_bypass:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  sreset_busy_clr:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  pwmem_override:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  constr_intra_pred:1;
    };
}ipmd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}ipmd_intra_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  value:28;
    };
}ipmd_intr_thresh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reach_thresh:1;
        RBus_UInt32  count:28;
    };
}ipmd_busy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  luma_part:2;
        RBus_UInt32  res2:7;
        RBus_UInt32  luma_cost:21;
    };
}ipmd_result0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  chroma_cost:21;
    };
}ipmd_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  value:7;
    };
}ipmd_lambda_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  value:21;
    };
}ipmd_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  genpulse:1;
        RBus_UInt32  dbgctrl:3;
        RBus_UInt32  piccount:14;
        RBus_UInt32  mbaddrx:7;
        RBus_UInt32  mbaddry:7;
    };
}ipmd_dbus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgctrl:32;
    };
}ipmd_dbus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_16x16_0:4;
        RBus_UInt32  r_16x16_1:4;
        RBus_UInt32  r_16x16_2:4;
        RBus_UInt32  r_16x16_3:4;
        RBus_UInt32  r_chroma_0:4;
        RBus_UInt32  r_chroma_1:4;
        RBus_UInt32  r_chroma_2:4;
        RBus_UInt32  r_chroma_3:4;
    };
}ipmd_cost0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  r_same_8x8:4;
        RBus_UInt32  r_diff_8x8:4;
        RBus_UInt32  r_same_4x4:4;
        RBus_UInt32  r_diff_4x4:4;
    };
}ipmd_cost1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}ipmd_intramode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  luma:32;
    };
}ipmd_remmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  y:7;
    };
}ipmd_slice_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_pulse:1;
        RBus_UInt32  read_pulse:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  address:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  intrasel:2;
        RBus_UInt32  subpart0:4;
        RBus_UInt32  subpart1:4;
        RBus_UInt32  subpart2:4;
        RBus_UInt32  subpart3:4;
    };
}ipmd_npm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  luma_wr:1;
        RBus_UInt32  cb_wr:1;
        RBus_UInt32  cr_wr:1;
        RBus_UInt32  luma:8;
        RBus_UInt32  cb:8;
        RBus_UInt32  cr:8;
    };
}ipmd_ulpred_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  intralumastylesel:1;
        RBus_UInt32  res2:5;
    };
}ipmd_cbpctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lookup:32;
    };
}ipmd_sumruncost_4x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  enable:1;
        RBus_UInt32  thresh:13;
    };
}ipmd_mblevel_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  flat_qtable:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  qpc:6;
    };
}ipmd_quantizer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  picturetype:2;
        RBus_UInt32  res2:21;
    };
}ipmd_mbinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbp_stay:4;
        RBus_UInt32  cbp_base:4;
    };
}ipmd_cbp_RBUS;

#else //apply LITTLE_ENDIAN

//======IPMD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  constr_intra_pred:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  pwmem_override:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  sreset_busy_clr:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  umem_bypass:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  softrst_disable:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  flush_cmd_disable:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  off4x4:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  res1:18;
    };
}ipmd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}ipmd_intra_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:28;
        RBus_UInt32  res1:4;
    };
}ipmd_intr_thresh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count:28;
        RBus_UInt32  reach_thresh:1;
        RBus_UInt32  res1:3;
    };
}ipmd_busy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  luma_cost:21;
        RBus_UInt32  res1:7;
        RBus_UInt32  luma_part:2;
        RBus_UInt32  res2:2;
    };
}ipmd_result0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_cost:21;
        RBus_UInt32  res1:11;
    };
}ipmd_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:7;
        RBus_UInt32  res1:25;
    };
}ipmd_lambda_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:21;
        RBus_UInt32  res1:11;
    };
}ipmd_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbaddry:7;
        RBus_UInt32  mbaddrx:7;
        RBus_UInt32  piccount:14;
        RBus_UInt32  dbgctrl:3;
        RBus_UInt32  genpulse:1;
    };
}ipmd_dbus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgctrl:32;
    };
}ipmd_dbus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_chroma_3:4;
        RBus_UInt32  r_chroma_2:4;
        RBus_UInt32  r_chroma_1:4;
        RBus_UInt32  r_chroma_0:4;
        RBus_UInt32  r_16x16_3:4;
        RBus_UInt32  r_16x16_2:4;
        RBus_UInt32  r_16x16_1:4;
        RBus_UInt32  r_16x16_0:4;
    };
}ipmd_cost0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_diff_4x4:4;
        RBus_UInt32  r_same_4x4:4;
        RBus_UInt32  r_diff_8x8:4;
        RBus_UInt32  r_same_8x8:4;
        RBus_UInt32  res1:16;
    };
}ipmd_cost1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}ipmd_intramode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  luma:32;
    };
}ipmd_remmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:7;
        RBus_UInt32  res1:25;
    };
}ipmd_slice_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subpart3:4;
        RBus_UInt32  subpart2:4;
        RBus_UInt32  subpart1:4;
        RBus_UInt32  subpart0:4;
        RBus_UInt32  intrasel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  address:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_pulse:1;
        RBus_UInt32  write_pulse:1;
    };
}ipmd_npm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr:8;
        RBus_UInt32  cb:8;
        RBus_UInt32  luma:8;
        RBus_UInt32  cr_wr:1;
        RBus_UInt32  cb_wr:1;
        RBus_UInt32  luma_wr:1;
        RBus_UInt32  res1:5;
    };
}ipmd_ulpred_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  intralumastylesel:1;
        RBus_UInt32  res2:26;
    };
}ipmd_cbpctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lookup:32;
    };
}ipmd_sumruncost_4x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  thresh:13;
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:18;
    };
}ipmd_mblevel_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qpc:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  flat_qtable:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:16;
    };
}ipmd_quantizer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  picturetype:2;
        RBus_UInt32  res2:9;
    };
}ipmd_mbinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbp_base:4;
        RBus_UInt32  cbp_stay:4;
        RBus_UInt32  res1:24;
    };
}ipmd_cbp_RBUS;




#endif 


#endif 
