/**
* @file rbusTconReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TCON_REG_H_
#define _RBUS_TCON_REG_H_

#include "rbusTypes.h"



//  TCON Register Address
#define  TCON_TCON_CTRL                                                          0x1802D200
#define  TCON_TCON_CTRL_reg_addr                                                 "0xB802D200"
#define  TCON_TCON_CTRL_reg                                                      0xB802D200
#define  TCON_TCON_CTRL_inst_addr                                                "0x0000"
#define  set_TCON_TCON_CTRL_reg(data)                                            (*((volatile unsigned int*)TCON_TCON_CTRL_reg)=data)
#define  get_TCON_TCON_CTRL_reg                                                  (*((volatile unsigned int*)TCON_TCON_CTRL_reg))
#define  TCON_TCON_CTRL_tcon_no_sscg_clk_sel_shift                               (31)
#define  TCON_TCON_CTRL_tcon_across_frame_en_shift                               (30)
#define  TCON_TCON_CTRL_tcon_output_shift                                        (0)
#define  TCON_TCON_CTRL_tcon_no_sscg_clk_sel_mask                                (0x80000000)
#define  TCON_TCON_CTRL_tcon_across_frame_en_mask                                (0x40000000)
#define  TCON_TCON_CTRL_tcon_output_mask                                         (0x00007FFF)
#define  TCON_TCON_CTRL_tcon_no_sscg_clk_sel(data)                               (0x80000000&((data)<<31))
#define  TCON_TCON_CTRL_tcon_across_frame_en(data)                               (0x40000000&((data)<<30))
#define  TCON_TCON_CTRL_tcon_output(data)                                        (0x00007FFF&(data))
#define  TCON_TCON_CTRL_get_tcon_no_sscg_clk_sel(data)                           ((0x80000000&(data))>>31)
#define  TCON_TCON_CTRL_get_tcon_across_frame_en(data)                           ((0x40000000&(data))>>30)
#define  TCON_TCON_CTRL_get_tcon_output(data)                                    (0x00007FFF&(data))

#define  TCON_TCON0_HSE                                                          0x1802D204
#define  TCON_TCON0_HSE_reg_addr                                                 "0xB802D204"
#define  TCON_TCON0_HSE_reg                                                      0xB802D204
#define  TCON_TCON0_HSE_inst_addr                                                "0x0001"
#define  set_TCON_TCON0_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON0_HSE_reg)=data)
#define  get_TCON_TCON0_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON0_HSE_reg))
#define  TCON_TCON0_HSE_dummy_0_shift                                            (29)
#define  TCON_TCON0_HSE_tcon0_hstart_shift                                       (16)
#define  TCON_TCON0_HSE_tcon0_hend_shift                                         (0)
#define  TCON_TCON0_HSE_dummy_0_mask                                             (0xE0000000)
#define  TCON_TCON0_HSE_tcon0_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON0_HSE_tcon0_hend_mask                                          (0x00001FFF)
#define  TCON_TCON0_HSE_dummy_0(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON0_HSE_tcon0_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON0_HSE_tcon0_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON0_HSE_get_dummy_0(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON0_HSE_get_tcon0_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON0_HSE_get_tcon0_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON0_VSE                                                          0x1802D208
#define  TCON_TCON0_VSE_reg_addr                                                 "0xB802D208"
#define  TCON_TCON0_VSE_reg                                                      0xB802D208
#define  TCON_TCON0_VSE_inst_addr                                                "0x0002"
#define  set_TCON_TCON0_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON0_VSE_reg)=data)
#define  get_TCON_TCON0_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON0_VSE_reg))
#define  TCON_TCON0_VSE_tcon0_vstart_shift                                       (16)
#define  TCON_TCON0_VSE_tcon0_vend_shift                                         (0)
#define  TCON_TCON0_VSE_tcon0_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON0_VSE_tcon0_vend_mask                                          (0x00000FFF)
#define  TCON_TCON0_VSE_tcon0_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON0_VSE_tcon0_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON0_VSE_get_tcon0_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON0_VSE_get_tcon0_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON0_Ctrl                                                         0x1802D20C
#define  TCON_TCON0_Ctrl_reg_addr                                                "0xB802D20C"
#define  TCON_TCON0_Ctrl_reg                                                     0xB802D20C
#define  TCON_TCON0_Ctrl_inst_addr                                               "0x0003"
#define  set_TCON_TCON0_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON0_Ctrl_reg)=data)
#define  get_TCON_TCON0_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON0_Ctrl_reg))
#define  TCON_TCON0_Ctrl_tcon0_l_flag_sel_shift                                  (13)
#define  TCON_TCON0_Ctrl_tcon0_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON0_Ctrl_tcon0_mode_shift                                        (8)
#define  TCON_TCON0_Ctrl_tcon0_en_shift                                          (7)
#define  TCON_TCON0_Ctrl_tcon0_inv_shift                                         (6)
#define  TCON_TCON0_Ctrl_tcon0_frame_tog_en_shift                                (3)
#define  TCON_TCON0_Ctrl_tcon0_comb_shift                                        (0)
#define  TCON_TCON0_Ctrl_tcon0_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON0_Ctrl_tcon0_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON0_Ctrl_tcon0_mode_mask                                         (0x00000700)
#define  TCON_TCON0_Ctrl_tcon0_en_mask                                           (0x00000080)
#define  TCON_TCON0_Ctrl_tcon0_inv_mask                                          (0x00000040)
#define  TCON_TCON0_Ctrl_tcon0_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON0_Ctrl_tcon0_comb_mask                                         (0x00000007)
#define  TCON_TCON0_Ctrl_tcon0_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON0_Ctrl_tcon0_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON0_Ctrl_tcon0_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON0_Ctrl_tcon0_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON0_Ctrl_tcon0_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON0_Ctrl_tcon0_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON0_Ctrl_tcon0_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON0_Ctrl_get_tcon0_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON0_Ctrl_get_tcon0_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON0_Ctrl_get_tcon0_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON0_Ctrl_get_tcon0_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON0_Ctrl_get_tcon0_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON0_Ctrl_get_tcon0_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON0_Ctrl_get_tcon0_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON0_ACROSS_LINE_CONTROL3                                         0x1802D210
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D210"
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_reg                                     0xB802D210
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_inst_addr                               "0x0004"
#define  set_TCON_TCON0_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON0_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON0_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON0_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_across_frame_int_shift            (28)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_across_ctrl3_rp_shift             (16)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_frame_hl_num_shift                (12)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_across_ctrl3_hp_shift             (0)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_across_frame_int_mask             (0x10000000)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_tcon0_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_get_tcon0_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_get_tcon0_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_get_tcon0_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON0_ACROSS_LINE_CONTROL3_get_tcon0_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON0_ACROSS_FRAME_CONTROL                                         0x1802D214
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D214"
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_reg                                     0xB802D214
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_inst_addr                               "0x0005"
#define  set_TCON_TCON0_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON0_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON0_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON0_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_tcon0_frame_offset_shift                (16)
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_tcon0_frame_period_shift                (0)
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_tcon0_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_tcon0_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_tcon0_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_tcon0_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_get_tcon0_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON0_ACROSS_FRAME_CONTROL_get_tcon0_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON0_FRAME_HL_CONTROL                                             0x1802D218
#define  TCON_TCON0_FRAME_HL_CONTROL_reg_addr                                    "0xB802D218"
#define  TCON_TCON0_FRAME_HL_CONTROL_reg                                         0xB802D218
#define  TCON_TCON0_FRAME_HL_CONTROL_inst_addr                                   "0x0006"
#define  set_TCON_TCON0_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON0_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON0_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON0_FRAME_HL_CONTROL_reg))
#define  TCON_TCON0_FRAME_HL_CONTROL_tcon0_frame_hl_shift                        (16)
#define  TCON_TCON0_FRAME_HL_CONTROL_tcon0_l_flag_prime_shift                    (0)
#define  TCON_TCON0_FRAME_HL_CONTROL_tcon0_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON0_FRAME_HL_CONTROL_tcon0_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON0_FRAME_HL_CONTROL_tcon0_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON0_FRAME_HL_CONTROL_tcon0_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON0_FRAME_HL_CONTROL_get_tcon0_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON0_FRAME_HL_CONTROL_get_tcon0_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON0_H_OFFSET_SHIFT                                               0x1802D21C
#define  TCON_TCON0_H_OFFSET_SHIFT_reg_addr                                      "0xB802D21C"
#define  TCON_TCON0_H_OFFSET_SHIFT_reg                                           0xB802D21C
#define  TCON_TCON0_H_OFFSET_SHIFT_inst_addr                                     "0x0007"
#define  set_TCON_TCON0_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON0_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON0_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON0_H_OFFSET_SHIFT_reg))
#define  TCON_TCON0_H_OFFSET_SHIFT_tcon0_hoffset_shift_en_shift                  (18)
#define  TCON_TCON0_H_OFFSET_SHIFT_tcon0_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON0_H_OFFSET_SHIFT_tcon0_hoffset_shift_value_shift               (0)
#define  TCON_TCON0_H_OFFSET_SHIFT_tcon0_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON0_H_OFFSET_SHIFT_tcon0_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON0_H_OFFSET_SHIFT_tcon0_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON0_H_OFFSET_SHIFT_tcon0_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON0_H_OFFSET_SHIFT_tcon0_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON0_H_OFFSET_SHIFT_tcon0_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON0_H_OFFSET_SHIFT_get_tcon0_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON0_H_OFFSET_SHIFT_get_tcon0_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON0_H_OFFSET_SHIFT_get_tcon0_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_TCON1_HSE                                                          0x1802D220
#define  TCON_TCON1_HSE_reg_addr                                                 "0xB802D220"
#define  TCON_TCON1_HSE_reg                                                      0xB802D220
#define  TCON_TCON1_HSE_inst_addr                                                "0x0008"
#define  set_TCON_TCON1_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON1_HSE_reg)=data)
#define  get_TCON_TCON1_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON1_HSE_reg))
#define  TCON_TCON1_HSE_dummy_1_shift                                            (29)
#define  TCON_TCON1_HSE_tcon1_hstart_shift                                       (16)
#define  TCON_TCON1_HSE_tcon1_hend_shift                                         (0)
#define  TCON_TCON1_HSE_dummy_1_mask                                             (0xE0000000)
#define  TCON_TCON1_HSE_tcon1_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON1_HSE_tcon1_hend_mask                                          (0x00001FFF)
#define  TCON_TCON1_HSE_dummy_1(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON1_HSE_tcon1_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON1_HSE_tcon1_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON1_HSE_get_dummy_1(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON1_HSE_get_tcon1_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON1_HSE_get_tcon1_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON1_VSE                                                          0x1802D224
#define  TCON_TCON1_VSE_reg_addr                                                 "0xB802D224"
#define  TCON_TCON1_VSE_reg                                                      0xB802D224
#define  TCON_TCON1_VSE_inst_addr                                                "0x0009"
#define  set_TCON_TCON1_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON1_VSE_reg)=data)
#define  get_TCON_TCON1_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON1_VSE_reg))
#define  TCON_TCON1_VSE_tcon1_vstart_shift                                       (16)
#define  TCON_TCON1_VSE_tcon1_vend_shift                                         (0)
#define  TCON_TCON1_VSE_tcon1_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON1_VSE_tcon1_vend_mask                                          (0x00000FFF)
#define  TCON_TCON1_VSE_tcon1_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON1_VSE_tcon1_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON1_VSE_get_tcon1_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON1_VSE_get_tcon1_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON1_Ctrl                                                         0x1802D228
#define  TCON_TCON1_Ctrl_reg_addr                                                "0xB802D228"
#define  TCON_TCON1_Ctrl_reg                                                     0xB802D228
#define  TCON_TCON1_Ctrl_inst_addr                                               "0x000A"
#define  set_TCON_TCON1_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON1_Ctrl_reg)=data)
#define  get_TCON_TCON1_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON1_Ctrl_reg))
#define  TCON_TCON1_Ctrl_tcon1_l_flag_sel_shift                                  (13)
#define  TCON_TCON1_Ctrl_tcon1_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON1_Ctrl_tcon1_mode_shift                                        (8)
#define  TCON_TCON1_Ctrl_tcon1_en_shift                                          (7)
#define  TCON_TCON1_Ctrl_tcon1_inv_shift                                         (6)
#define  TCON_TCON1_Ctrl_tcon1_frame_tog_en_shift                                (3)
#define  TCON_TCON1_Ctrl_tcon1_comb_shift                                        (0)
#define  TCON_TCON1_Ctrl_tcon1_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON1_Ctrl_tcon1_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON1_Ctrl_tcon1_mode_mask                                         (0x00000700)
#define  TCON_TCON1_Ctrl_tcon1_en_mask                                           (0x00000080)
#define  TCON_TCON1_Ctrl_tcon1_inv_mask                                          (0x00000040)
#define  TCON_TCON1_Ctrl_tcon1_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON1_Ctrl_tcon1_comb_mask                                         (0x00000007)
#define  TCON_TCON1_Ctrl_tcon1_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON1_Ctrl_tcon1_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON1_Ctrl_tcon1_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON1_Ctrl_tcon1_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON1_Ctrl_tcon1_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON1_Ctrl_tcon1_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON1_Ctrl_tcon1_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON1_Ctrl_get_tcon1_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON1_Ctrl_get_tcon1_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON1_Ctrl_get_tcon1_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON1_Ctrl_get_tcon1_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON1_Ctrl_get_tcon1_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON1_Ctrl_get_tcon1_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON1_Ctrl_get_tcon1_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON1_ACROSS_LINE_CONTROL3                                         0x1802D22C
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D22C"
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_reg                                     0xB802D22C
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_inst_addr                               "0x000B"
#define  set_TCON_TCON1_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON1_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON1_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON1_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_across_frame_int_shift            (28)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_across_ctrl3_rp_shift             (16)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_frame_hl_num_shift                (12)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_across_ctrl3_hp_shift             (0)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_across_frame_int_mask             (0x10000000)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_tcon1_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_get_tcon1_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_get_tcon1_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_get_tcon1_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON1_ACROSS_LINE_CONTROL3_get_tcon1_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON1_ACROSS_FRAME_CONTROL                                         0x1802D230
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D230"
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_reg                                     0xB802D230
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_inst_addr                               "0x000C"
#define  set_TCON_TCON1_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON1_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON1_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON1_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_tcon1_frame_offset_shift                (16)
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_tcon1_frame_period_shift                (0)
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_tcon1_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_tcon1_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_tcon1_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_tcon1_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_get_tcon1_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON1_ACROSS_FRAME_CONTROL_get_tcon1_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON1_FRAME_HL_CONTROL                                             0x1802D234
#define  TCON_TCON1_FRAME_HL_CONTROL_reg_addr                                    "0xB802D234"
#define  TCON_TCON1_FRAME_HL_CONTROL_reg                                         0xB802D234
#define  TCON_TCON1_FRAME_HL_CONTROL_inst_addr                                   "0x000D"
#define  set_TCON_TCON1_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON1_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON1_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON1_FRAME_HL_CONTROL_reg))
#define  TCON_TCON1_FRAME_HL_CONTROL_tcon1_frame_hl_shift                        (16)
#define  TCON_TCON1_FRAME_HL_CONTROL_tcon1_l_flag_prime_shift                    (0)
#define  TCON_TCON1_FRAME_HL_CONTROL_tcon1_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON1_FRAME_HL_CONTROL_tcon1_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON1_FRAME_HL_CONTROL_tcon1_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON1_FRAME_HL_CONTROL_tcon1_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON1_FRAME_HL_CONTROL_get_tcon1_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON1_FRAME_HL_CONTROL_get_tcon1_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON1_H_OFFSET_SHIFT                                               0x1802D238
#define  TCON_TCON1_H_OFFSET_SHIFT_reg_addr                                      "0xB802D238"
#define  TCON_TCON1_H_OFFSET_SHIFT_reg                                           0xB802D238
#define  TCON_TCON1_H_OFFSET_SHIFT_inst_addr                                     "0x000E"
#define  set_TCON_TCON1_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON1_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON1_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON1_H_OFFSET_SHIFT_reg))
#define  TCON_TCON1_H_OFFSET_SHIFT_tcon1_hoffset_shift_en_shift                  (18)
#define  TCON_TCON1_H_OFFSET_SHIFT_tcon1_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON1_H_OFFSET_SHIFT_tcon1_hoffset_shift_value_shift               (0)
#define  TCON_TCON1_H_OFFSET_SHIFT_tcon1_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON1_H_OFFSET_SHIFT_tcon1_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON1_H_OFFSET_SHIFT_tcon1_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON1_H_OFFSET_SHIFT_tcon1_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON1_H_OFFSET_SHIFT_tcon1_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON1_H_OFFSET_SHIFT_tcon1_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON1_H_OFFSET_SHIFT_get_tcon1_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON1_H_OFFSET_SHIFT_get_tcon1_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON1_H_OFFSET_SHIFT_get_tcon1_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_TCON2_HSE                                                          0x1802D23C
#define  TCON_TCON2_HSE_reg_addr                                                 "0xB802D23C"
#define  TCON_TCON2_HSE_reg                                                      0xB802D23C
#define  TCON_TCON2_HSE_inst_addr                                                "0x000F"
#define  set_TCON_TCON2_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON2_HSE_reg)=data)
#define  get_TCON_TCON2_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON2_HSE_reg))
#define  TCON_TCON2_HSE_dummy_2_shift                                            (29)
#define  TCON_TCON2_HSE_tcon2_hstart_shift                                       (16)
#define  TCON_TCON2_HSE_tcon2_hend_shift                                         (0)
#define  TCON_TCON2_HSE_dummy_2_mask                                             (0xE0000000)
#define  TCON_TCON2_HSE_tcon2_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON2_HSE_tcon2_hend_mask                                          (0x00001FFF)
#define  TCON_TCON2_HSE_dummy_2(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON2_HSE_tcon2_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON2_HSE_tcon2_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON2_HSE_get_dummy_2(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON2_HSE_get_tcon2_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON2_HSE_get_tcon2_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON2_VSE                                                          0x1802D240
#define  TCON_TCON2_VSE_reg_addr                                                 "0xB802D240"
#define  TCON_TCON2_VSE_reg                                                      0xB802D240
#define  TCON_TCON2_VSE_inst_addr                                                "0x0010"
#define  set_TCON_TCON2_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON2_VSE_reg)=data)
#define  get_TCON_TCON2_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON2_VSE_reg))
#define  TCON_TCON2_VSE_tcon2_vstart_shift                                       (16)
#define  TCON_TCON2_VSE_tcon2_vend_shift                                         (0)
#define  TCON_TCON2_VSE_tcon2_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON2_VSE_tcon2_vend_mask                                          (0x00000FFF)
#define  TCON_TCON2_VSE_tcon2_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON2_VSE_tcon2_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON2_VSE_get_tcon2_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON2_VSE_get_tcon2_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON2_Ctrl                                                         0x1802D244
#define  TCON_TCON2_Ctrl_reg_addr                                                "0xB802D244"
#define  TCON_TCON2_Ctrl_reg                                                     0xB802D244
#define  TCON_TCON2_Ctrl_inst_addr                                               "0x0011"
#define  set_TCON_TCON2_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON2_Ctrl_reg)=data)
#define  get_TCON_TCON2_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON2_Ctrl_reg))
#define  TCON_TCON2_Ctrl_tcon2_l_flag_sel_shift                                  (13)
#define  TCON_TCON2_Ctrl_tcon2_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON2_Ctrl_tcon2_mode_shift                                        (8)
#define  TCON_TCON2_Ctrl_tcon2_en_shift                                          (7)
#define  TCON_TCON2_Ctrl_tcon2_inv_shift                                         (6)
#define  TCON_TCON2_Ctrl_tcon2_frame_tog_en_shift                                (3)
#define  TCON_TCON2_Ctrl_tcon2_comb_shift                                        (0)
#define  TCON_TCON2_Ctrl_tcon2_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON2_Ctrl_tcon2_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON2_Ctrl_tcon2_mode_mask                                         (0x00000700)
#define  TCON_TCON2_Ctrl_tcon2_en_mask                                           (0x00000080)
#define  TCON_TCON2_Ctrl_tcon2_inv_mask                                          (0x00000040)
#define  TCON_TCON2_Ctrl_tcon2_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON2_Ctrl_tcon2_comb_mask                                         (0x00000007)
#define  TCON_TCON2_Ctrl_tcon2_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON2_Ctrl_tcon2_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON2_Ctrl_tcon2_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON2_Ctrl_tcon2_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON2_Ctrl_tcon2_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON2_Ctrl_tcon2_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON2_Ctrl_tcon2_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON2_Ctrl_get_tcon2_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON2_Ctrl_get_tcon2_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON2_Ctrl_get_tcon2_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON2_Ctrl_get_tcon2_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON2_Ctrl_get_tcon2_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON2_Ctrl_get_tcon2_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON2_Ctrl_get_tcon2_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON2_ACROSS_LINE_CONTROL3                                         0x1802D248
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D248"
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_reg                                     0xB802D248
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_inst_addr                               "0x0012"
#define  set_TCON_TCON2_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON2_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON2_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON2_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_across_frame_int_shift            (28)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_across_ctrl3_rp_shift             (16)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_frame_hl_num_shift                (12)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_across_ctrl3_hp_shift             (0)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_across_frame_int_mask             (0x10000000)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_tcon2_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_get_tcon2_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_get_tcon2_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_get_tcon2_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON2_ACROSS_LINE_CONTROL3_get_tcon2_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON2_ACROSS_FRAME_CONTROL                                         0x1802D24C
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D24C"
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_reg                                     0xB802D24C
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_inst_addr                               "0x0013"
#define  set_TCON_TCON2_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON2_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON2_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON2_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_tcon2_frame_offset_shift                (16)
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_tcon2_frame_period_shift                (0)
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_tcon2_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_tcon2_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_tcon2_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_tcon2_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_get_tcon2_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON2_ACROSS_FRAME_CONTROL_get_tcon2_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON2_FRAME_HL_CONTROL                                             0x1802D250
#define  TCON_TCON2_FRAME_HL_CONTROL_reg_addr                                    "0xB802D250"
#define  TCON_TCON2_FRAME_HL_CONTROL_reg                                         0xB802D250
#define  TCON_TCON2_FRAME_HL_CONTROL_inst_addr                                   "0x0014"
#define  set_TCON_TCON2_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON2_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON2_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON2_FRAME_HL_CONTROL_reg))
#define  TCON_TCON2_FRAME_HL_CONTROL_tcon2_frame_hl_shift                        (16)
#define  TCON_TCON2_FRAME_HL_CONTROL_tcon2_l_flag_prime_shift                    (0)
#define  TCON_TCON2_FRAME_HL_CONTROL_tcon2_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON2_FRAME_HL_CONTROL_tcon2_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON2_FRAME_HL_CONTROL_tcon2_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON2_FRAME_HL_CONTROL_tcon2_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON2_FRAME_HL_CONTROL_get_tcon2_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON2_FRAME_HL_CONTROL_get_tcon2_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON2_H_OFFSET_SHIFT                                               0x1802D254
#define  TCON_TCON2_H_OFFSET_SHIFT_reg_addr                                      "0xB802D254"
#define  TCON_TCON2_H_OFFSET_SHIFT_reg                                           0xB802D254
#define  TCON_TCON2_H_OFFSET_SHIFT_inst_addr                                     "0x0015"
#define  set_TCON_TCON2_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON2_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON2_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON2_H_OFFSET_SHIFT_reg))
#define  TCON_TCON2_H_OFFSET_SHIFT_tcon2_hoffset_shift_en_shift                  (18)
#define  TCON_TCON2_H_OFFSET_SHIFT_tcon2_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON2_H_OFFSET_SHIFT_tcon2_hoffset_shift_value_shift               (0)
#define  TCON_TCON2_H_OFFSET_SHIFT_tcon2_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON2_H_OFFSET_SHIFT_tcon2_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON2_H_OFFSET_SHIFT_tcon2_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON2_H_OFFSET_SHIFT_tcon2_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON2_H_OFFSET_SHIFT_tcon2_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON2_H_OFFSET_SHIFT_tcon2_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON2_H_OFFSET_SHIFT_get_tcon2_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON2_H_OFFSET_SHIFT_get_tcon2_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON2_H_OFFSET_SHIFT_get_tcon2_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_TCON3_HSE                                                          0x1802D258
#define  TCON_TCON3_HSE_reg_addr                                                 "0xB802D258"
#define  TCON_TCON3_HSE_reg                                                      0xB802D258
#define  TCON_TCON3_HSE_inst_addr                                                "0x0016"
#define  set_TCON_TCON3_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON3_HSE_reg)=data)
#define  get_TCON_TCON3_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON3_HSE_reg))
#define  TCON_TCON3_HSE_dummy_3_shift                                            (29)
#define  TCON_TCON3_HSE_tcon3_hstart_shift                                       (16)
#define  TCON_TCON3_HSE_tcon3_hend_shift                                         (0)
#define  TCON_TCON3_HSE_dummy_3_mask                                             (0xE0000000)
#define  TCON_TCON3_HSE_tcon3_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON3_HSE_tcon3_hend_mask                                          (0x00001FFF)
#define  TCON_TCON3_HSE_dummy_3(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON3_HSE_tcon3_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON3_HSE_tcon3_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON3_HSE_get_dummy_3(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON3_HSE_get_tcon3_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON3_HSE_get_tcon3_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON3_VSE                                                          0x1802D25C
#define  TCON_TCON3_VSE_reg_addr                                                 "0xB802D25C"
#define  TCON_TCON3_VSE_reg                                                      0xB802D25C
#define  TCON_TCON3_VSE_inst_addr                                                "0x0017"
#define  set_TCON_TCON3_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON3_VSE_reg)=data)
#define  get_TCON_TCON3_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON3_VSE_reg))
#define  TCON_TCON3_VSE_tcon3_vstart_shift                                       (16)
#define  TCON_TCON3_VSE_tcon3_vend_shift                                         (0)
#define  TCON_TCON3_VSE_tcon3_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON3_VSE_tcon3_vend_mask                                          (0x00000FFF)
#define  TCON_TCON3_VSE_tcon3_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON3_VSE_tcon3_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON3_VSE_get_tcon3_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON3_VSE_get_tcon3_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON3_Ctrl                                                         0x1802D260
#define  TCON_TCON3_Ctrl_reg_addr                                                "0xB802D260"
#define  TCON_TCON3_Ctrl_reg                                                     0xB802D260
#define  TCON_TCON3_Ctrl_inst_addr                                               "0x0018"
#define  set_TCON_TCON3_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON3_Ctrl_reg)=data)
#define  get_TCON_TCON3_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON3_Ctrl_reg))
#define  TCON_TCON3_Ctrl_tcon3_l_flag_sel_shift                                  (13)
#define  TCON_TCON3_Ctrl_tcon3_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON3_Ctrl_tcon3_mode_shift                                        (8)
#define  TCON_TCON3_Ctrl_tcon3_en_shift                                          (7)
#define  TCON_TCON3_Ctrl_tcon3_inv_shift                                         (6)
#define  TCON_TCON3_Ctrl_tcon3_frame_tog_en_shift                                (3)
#define  TCON_TCON3_Ctrl_tcon3_comb_shift                                        (0)
#define  TCON_TCON3_Ctrl_tcon3_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON3_Ctrl_tcon3_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON3_Ctrl_tcon3_mode_mask                                         (0x00000700)
#define  TCON_TCON3_Ctrl_tcon3_en_mask                                           (0x00000080)
#define  TCON_TCON3_Ctrl_tcon3_inv_mask                                          (0x00000040)
#define  TCON_TCON3_Ctrl_tcon3_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON3_Ctrl_tcon3_comb_mask                                         (0x00000007)
#define  TCON_TCON3_Ctrl_tcon3_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON3_Ctrl_tcon3_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON3_Ctrl_tcon3_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON3_Ctrl_tcon3_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON3_Ctrl_tcon3_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON3_Ctrl_tcon3_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON3_Ctrl_tcon3_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON3_Ctrl_get_tcon3_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON3_Ctrl_get_tcon3_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON3_Ctrl_get_tcon3_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON3_Ctrl_get_tcon3_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON3_Ctrl_get_tcon3_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON3_Ctrl_get_tcon3_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON3_Ctrl_get_tcon3_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON3_ACROSS_LINE_CONTROL3                                         0x1802D264
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D264"
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_reg                                     0xB802D264
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_inst_addr                               "0x0019"
#define  set_TCON_TCON3_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON3_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON3_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON3_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_across_frame_int_shift            (28)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_across_ctrl3_rp_shift             (16)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_frame_hl_num_shift                (12)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_across_ctrl3_hp_shift             (0)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_across_frame_int_mask             (0x10000000)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_tcon3_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_get_tcon3_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_get_tcon3_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_get_tcon3_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON3_ACROSS_LINE_CONTROL3_get_tcon3_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON3_ACROSS_FRAME_CONTROL                                         0x1802D268
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D268"
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_reg                                     0xB802D268
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_inst_addr                               "0x001A"
#define  set_TCON_TCON3_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON3_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON3_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON3_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_tcon3_frame_offset_shift                (16)
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_tcon3_frame_period_shift                (0)
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_tcon3_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_tcon3_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_tcon3_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_tcon3_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_get_tcon3_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON3_ACROSS_FRAME_CONTROL_get_tcon3_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON3_FRAME_HL_CONTROL                                             0x1802D26C
#define  TCON_TCON3_FRAME_HL_CONTROL_reg_addr                                    "0xB802D26C"
#define  TCON_TCON3_FRAME_HL_CONTROL_reg                                         0xB802D26C
#define  TCON_TCON3_FRAME_HL_CONTROL_inst_addr                                   "0x001B"
#define  set_TCON_TCON3_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON3_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON3_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON3_FRAME_HL_CONTROL_reg))
#define  TCON_TCON3_FRAME_HL_CONTROL_tcon3_frame_hl_shift                        (16)
#define  TCON_TCON3_FRAME_HL_CONTROL_tcon3_l_flag_prime_shift                    (0)
#define  TCON_TCON3_FRAME_HL_CONTROL_tcon3_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON3_FRAME_HL_CONTROL_tcon3_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON3_FRAME_HL_CONTROL_tcon3_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON3_FRAME_HL_CONTROL_tcon3_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON3_FRAME_HL_CONTROL_get_tcon3_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON3_FRAME_HL_CONTROL_get_tcon3_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON3_H_OFFSET_SHIFT                                               0x1802D270
#define  TCON_TCON3_H_OFFSET_SHIFT_reg_addr                                      "0xB802D270"
#define  TCON_TCON3_H_OFFSET_SHIFT_reg                                           0xB802D270
#define  TCON_TCON3_H_OFFSET_SHIFT_inst_addr                                     "0x001C"
#define  set_TCON_TCON3_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON3_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON3_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON3_H_OFFSET_SHIFT_reg))
#define  TCON_TCON3_H_OFFSET_SHIFT_tcon3_hoffset_shift_en_shift                  (18)
#define  TCON_TCON3_H_OFFSET_SHIFT_tcon3_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON3_H_OFFSET_SHIFT_tcon3_hoffset_shift_value_shift               (0)
#define  TCON_TCON3_H_OFFSET_SHIFT_tcon3_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON3_H_OFFSET_SHIFT_tcon3_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON3_H_OFFSET_SHIFT_tcon3_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON3_H_OFFSET_SHIFT_tcon3_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON3_H_OFFSET_SHIFT_tcon3_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON3_H_OFFSET_SHIFT_tcon3_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON3_H_OFFSET_SHIFT_get_tcon3_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON3_H_OFFSET_SHIFT_get_tcon3_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON3_H_OFFSET_SHIFT_get_tcon3_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_TCON4_HSE                                                          0x1802D274
#define  TCON_TCON4_HSE_reg_addr                                                 "0xB802D274"
#define  TCON_TCON4_HSE_reg                                                      0xB802D274
#define  TCON_TCON4_HSE_inst_addr                                                "0x001D"
#define  set_TCON_TCON4_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON4_HSE_reg)=data)
#define  get_TCON_TCON4_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON4_HSE_reg))
#define  TCON_TCON4_HSE_dummy_4_shift                                            (29)
#define  TCON_TCON4_HSE_tcon4_hstart_shift                                       (16)
#define  TCON_TCON4_HSE_tcon4_hend_shift                                         (0)
#define  TCON_TCON4_HSE_dummy_4_mask                                             (0xE0000000)
#define  TCON_TCON4_HSE_tcon4_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON4_HSE_tcon4_hend_mask                                          (0x00001FFF)
#define  TCON_TCON4_HSE_dummy_4(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON4_HSE_tcon4_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON4_HSE_tcon4_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON4_HSE_get_dummy_4(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON4_HSE_get_tcon4_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON4_HSE_get_tcon4_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON4_VSE                                                          0x1802D278
#define  TCON_TCON4_VSE_reg_addr                                                 "0xB802D278"
#define  TCON_TCON4_VSE_reg                                                      0xB802D278
#define  TCON_TCON4_VSE_inst_addr                                                "0x001E"
#define  set_TCON_TCON4_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON4_VSE_reg)=data)
#define  get_TCON_TCON4_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON4_VSE_reg))
#define  TCON_TCON4_VSE_tcon4_vstart_shift                                       (16)
#define  TCON_TCON4_VSE_tcon4_vend_shift                                         (0)
#define  TCON_TCON4_VSE_tcon4_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON4_VSE_tcon4_vend_mask                                          (0x00000FFF)
#define  TCON_TCON4_VSE_tcon4_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON4_VSE_tcon4_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON4_VSE_get_tcon4_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON4_VSE_get_tcon4_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON4_Ctrl                                                         0x1802D27C
#define  TCON_TCON4_Ctrl_reg_addr                                                "0xB802D27C"
#define  TCON_TCON4_Ctrl_reg                                                     0xB802D27C
#define  TCON_TCON4_Ctrl_inst_addr                                               "0x001F"
#define  set_TCON_TCON4_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON4_Ctrl_reg)=data)
#define  get_TCON_TCON4_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON4_Ctrl_reg))
#define  TCON_TCON4_Ctrl_tcon4_l_flag_sel_shift                                  (13)
#define  TCON_TCON4_Ctrl_tcon4_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON4_Ctrl_tcon4_mode_shift                                        (8)
#define  TCON_TCON4_Ctrl_tcon4_en_shift                                          (7)
#define  TCON_TCON4_Ctrl_tcon4_inv_shift                                         (6)
#define  TCON_TCON4_Ctrl_tcon4_frame_tog_en_shift                                (3)
#define  TCON_TCON4_Ctrl_tcon4_comb_shift                                        (0)
#define  TCON_TCON4_Ctrl_tcon4_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON4_Ctrl_tcon4_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON4_Ctrl_tcon4_mode_mask                                         (0x00000700)
#define  TCON_TCON4_Ctrl_tcon4_en_mask                                           (0x00000080)
#define  TCON_TCON4_Ctrl_tcon4_inv_mask                                          (0x00000040)
#define  TCON_TCON4_Ctrl_tcon4_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON4_Ctrl_tcon4_comb_mask                                         (0x00000007)
#define  TCON_TCON4_Ctrl_tcon4_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON4_Ctrl_tcon4_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON4_Ctrl_tcon4_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON4_Ctrl_tcon4_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON4_Ctrl_tcon4_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON4_Ctrl_tcon4_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON4_Ctrl_tcon4_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON4_Ctrl_get_tcon4_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON4_Ctrl_get_tcon4_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON4_Ctrl_get_tcon4_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON4_Ctrl_get_tcon4_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON4_Ctrl_get_tcon4_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON4_Ctrl_get_tcon4_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON4_Ctrl_get_tcon4_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON4_ACROSS_LINE_CONTROL3                                         0x1802D280
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D280"
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_reg                                     0xB802D280
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_inst_addr                               "0x0020"
#define  set_TCON_TCON4_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON4_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON4_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON4_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_across_frame_int_shift            (28)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_across_ctrl3_rp_shift             (16)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_frame_hl_num_shift                (12)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_across_ctrl3_hp_shift             (0)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_across_frame_int_mask             (0x10000000)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_tcon4_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_get_tcon4_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_get_tcon4_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_get_tcon4_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON4_ACROSS_LINE_CONTROL3_get_tcon4_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON4_ACROSS_FRAME_CONTROL                                         0x1802D284
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D284"
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_reg                                     0xB802D284
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_inst_addr                               "0x0021"
#define  set_TCON_TCON4_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON4_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON4_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON4_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_tcon4_frame_offset_shift                (16)
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_tcon4_frame_period_shift                (0)
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_tcon4_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_tcon4_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_tcon4_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_tcon4_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_get_tcon4_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON4_ACROSS_FRAME_CONTROL_get_tcon4_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON4_FRAME_HL_CONTROL                                             0x1802D288
#define  TCON_TCON4_FRAME_HL_CONTROL_reg_addr                                    "0xB802D288"
#define  TCON_TCON4_FRAME_HL_CONTROL_reg                                         0xB802D288
#define  TCON_TCON4_FRAME_HL_CONTROL_inst_addr                                   "0x0022"
#define  set_TCON_TCON4_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON4_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON4_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON4_FRAME_HL_CONTROL_reg))
#define  TCON_TCON4_FRAME_HL_CONTROL_tcon4_frame_hl_shift                        (16)
#define  TCON_TCON4_FRAME_HL_CONTROL_tcon4_l_flag_prime_shift                    (0)
#define  TCON_TCON4_FRAME_HL_CONTROL_tcon4_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON4_FRAME_HL_CONTROL_tcon4_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON4_FRAME_HL_CONTROL_tcon4_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON4_FRAME_HL_CONTROL_tcon4_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON4_FRAME_HL_CONTROL_get_tcon4_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON4_FRAME_HL_CONTROL_get_tcon4_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON4_H_OFFSET_SHIFT                                               0x1802D28C
#define  TCON_TCON4_H_OFFSET_SHIFT_reg_addr                                      "0xB802D28C"
#define  TCON_TCON4_H_OFFSET_SHIFT_reg                                           0xB802D28C
#define  TCON_TCON4_H_OFFSET_SHIFT_inst_addr                                     "0x0023"
#define  set_TCON_TCON4_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON4_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON4_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON4_H_OFFSET_SHIFT_reg))
#define  TCON_TCON4_H_OFFSET_SHIFT_tcon4_hoffset_shift_en_shift                  (18)
#define  TCON_TCON4_H_OFFSET_SHIFT_tcon4_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON4_H_OFFSET_SHIFT_tcon4_hoffset_shift_value_shift               (0)
#define  TCON_TCON4_H_OFFSET_SHIFT_tcon4_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON4_H_OFFSET_SHIFT_tcon4_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON4_H_OFFSET_SHIFT_tcon4_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON4_H_OFFSET_SHIFT_tcon4_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON4_H_OFFSET_SHIFT_tcon4_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON4_H_OFFSET_SHIFT_tcon4_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON4_H_OFFSET_SHIFT_get_tcon4_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON4_H_OFFSET_SHIFT_get_tcon4_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON4_H_OFFSET_SHIFT_get_tcon4_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_TCON5_HSE                                                          0x1802D290
#define  TCON_TCON5_HSE_reg_addr                                                 "0xB802D290"
#define  TCON_TCON5_HSE_reg                                                      0xB802D290
#define  TCON_TCON5_HSE_inst_addr                                                "0x0024"
#define  set_TCON_TCON5_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON5_HSE_reg)=data)
#define  get_TCON_TCON5_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON5_HSE_reg))
#define  TCON_TCON5_HSE_dummy_5_shift                                            (29)
#define  TCON_TCON5_HSE_tcon5_hstart_shift                                       (16)
#define  TCON_TCON5_HSE_tcon5_hend_shift                                         (0)
#define  TCON_TCON5_HSE_dummy_5_mask                                             (0xE0000000)
#define  TCON_TCON5_HSE_tcon5_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON5_HSE_tcon5_hend_mask                                          (0x00001FFF)
#define  TCON_TCON5_HSE_dummy_5(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON5_HSE_tcon5_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON5_HSE_tcon5_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON5_HSE_get_dummy_5(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON5_HSE_get_tcon5_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON5_HSE_get_tcon5_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON5_VSE                                                          0x1802D294
#define  TCON_TCON5_VSE_reg_addr                                                 "0xB802D294"
#define  TCON_TCON5_VSE_reg                                                      0xB802D294
#define  TCON_TCON5_VSE_inst_addr                                                "0x0025"
#define  set_TCON_TCON5_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON5_VSE_reg)=data)
#define  get_TCON_TCON5_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON5_VSE_reg))
#define  TCON_TCON5_VSE_tcon5_vstart_shift                                       (16)
#define  TCON_TCON5_VSE_tcon5_vend_shift                                         (0)
#define  TCON_TCON5_VSE_tcon5_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON5_VSE_tcon5_vend_mask                                          (0x00000FFF)
#define  TCON_TCON5_VSE_tcon5_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON5_VSE_tcon5_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON5_VSE_get_tcon5_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON5_VSE_get_tcon5_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON5_Ctrl                                                         0x1802D298
#define  TCON_TCON5_Ctrl_reg_addr                                                "0xB802D298"
#define  TCON_TCON5_Ctrl_reg                                                     0xB802D298
#define  TCON_TCON5_Ctrl_inst_addr                                               "0x0026"
#define  set_TCON_TCON5_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON5_Ctrl_reg)=data)
#define  get_TCON_TCON5_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON5_Ctrl_reg))
#define  TCON_TCON5_Ctrl_tcon5_l_flag_sel_shift                                  (13)
#define  TCON_TCON5_Ctrl_tcon5_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON5_Ctrl_tcon5_mode_shift                                        (8)
#define  TCON_TCON5_Ctrl_tcon5_en_shift                                          (7)
#define  TCON_TCON5_Ctrl_tcon5_inv_shift                                         (6)
#define  TCON_TCON5_Ctrl_tcon5_frame_tog_en_shift                                (3)
#define  TCON_TCON5_Ctrl_tcon5_comb_shift                                        (0)
#define  TCON_TCON5_Ctrl_tcon5_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON5_Ctrl_tcon5_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON5_Ctrl_tcon5_mode_mask                                         (0x00000700)
#define  TCON_TCON5_Ctrl_tcon5_en_mask                                           (0x00000080)
#define  TCON_TCON5_Ctrl_tcon5_inv_mask                                          (0x00000040)
#define  TCON_TCON5_Ctrl_tcon5_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON5_Ctrl_tcon5_comb_mask                                         (0x00000007)
#define  TCON_TCON5_Ctrl_tcon5_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON5_Ctrl_tcon5_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON5_Ctrl_tcon5_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON5_Ctrl_tcon5_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON5_Ctrl_tcon5_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON5_Ctrl_tcon5_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON5_Ctrl_tcon5_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON5_Ctrl_get_tcon5_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON5_Ctrl_get_tcon5_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON5_Ctrl_get_tcon5_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON5_Ctrl_get_tcon5_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON5_Ctrl_get_tcon5_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON5_Ctrl_get_tcon5_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON5_Ctrl_get_tcon5_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON5_ACROSS_LINE_CONTROL3                                         0x1802D29C
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D29C"
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_reg                                     0xB802D29C
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_inst_addr                               "0x0027"
#define  set_TCON_TCON5_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON5_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON5_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON5_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_across_frame_int_shift            (28)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_across_ctrl3_rp_shift             (16)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_frame_hl_num_shift                (12)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_across_ctrl3_hp_shift             (0)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_across_frame_int_mask             (0x10000000)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_tcon5_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_get_tcon5_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_get_tcon5_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_get_tcon5_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON5_ACROSS_LINE_CONTROL3_get_tcon5_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON5_ACROSS_FRAME_CONTROL                                         0x1802D2A0
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D2A0"
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_reg                                     0xB802D2A0
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_inst_addr                               "0x0028"
#define  set_TCON_TCON5_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON5_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON5_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON5_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_tcon5_frame_offset_shift                (16)
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_tcon5_frame_period_shift                (0)
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_tcon5_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_tcon5_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_tcon5_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_tcon5_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_get_tcon5_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON5_ACROSS_FRAME_CONTROL_get_tcon5_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON5_FRAME_HL_CONTROL                                             0x1802D2A4
#define  TCON_TCON5_FRAME_HL_CONTROL_reg_addr                                    "0xB802D2A4"
#define  TCON_TCON5_FRAME_HL_CONTROL_reg                                         0xB802D2A4
#define  TCON_TCON5_FRAME_HL_CONTROL_inst_addr                                   "0x0029"
#define  set_TCON_TCON5_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON5_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON5_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON5_FRAME_HL_CONTROL_reg))
#define  TCON_TCON5_FRAME_HL_CONTROL_tcon5_frame_hl_shift                        (16)
#define  TCON_TCON5_FRAME_HL_CONTROL_tcon5_l_flag_prime_shift                    (0)
#define  TCON_TCON5_FRAME_HL_CONTROL_tcon5_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON5_FRAME_HL_CONTROL_tcon5_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON5_FRAME_HL_CONTROL_tcon5_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON5_FRAME_HL_CONTROL_tcon5_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON5_FRAME_HL_CONTROL_get_tcon5_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON5_FRAME_HL_CONTROL_get_tcon5_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON5_H_OFFSET_SHIFT                                               0x1802D2A8
#define  TCON_TCON5_H_OFFSET_SHIFT_reg_addr                                      "0xB802D2A8"
#define  TCON_TCON5_H_OFFSET_SHIFT_reg                                           0xB802D2A8
#define  TCON_TCON5_H_OFFSET_SHIFT_inst_addr                                     "0x002A"
#define  set_TCON_TCON5_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON5_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON5_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON5_H_OFFSET_SHIFT_reg))
#define  TCON_TCON5_H_OFFSET_SHIFT_tcon5_hoffset_shift_en_shift                  (18)
#define  TCON_TCON5_H_OFFSET_SHIFT_tcon5_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON5_H_OFFSET_SHIFT_tcon5_hoffset_shift_value_shift               (0)
#define  TCON_TCON5_H_OFFSET_SHIFT_tcon5_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON5_H_OFFSET_SHIFT_tcon5_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON5_H_OFFSET_SHIFT_tcon5_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON5_H_OFFSET_SHIFT_tcon5_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON5_H_OFFSET_SHIFT_tcon5_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON5_H_OFFSET_SHIFT_tcon5_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON5_H_OFFSET_SHIFT_get_tcon5_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON5_H_OFFSET_SHIFT_get_tcon5_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON5_H_OFFSET_SHIFT_get_tcon5_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_TCON6_HSE                                                          0x1802D2AC
#define  TCON_TCON6_HSE_reg_addr                                                 "0xB802D2AC"
#define  TCON_TCON6_HSE_reg                                                      0xB802D2AC
#define  TCON_TCON6_HSE_inst_addr                                                "0x002B"
#define  set_TCON_TCON6_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON6_HSE_reg)=data)
#define  get_TCON_TCON6_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON6_HSE_reg))
#define  TCON_TCON6_HSE_dummy_6_shift                                            (29)
#define  TCON_TCON6_HSE_tcon6_hstart_shift                                       (16)
#define  TCON_TCON6_HSE_tcon6_hend_shift                                         (0)
#define  TCON_TCON6_HSE_dummy_6_mask                                             (0xE0000000)
#define  TCON_TCON6_HSE_tcon6_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON6_HSE_tcon6_hend_mask                                          (0x00001FFF)
#define  TCON_TCON6_HSE_dummy_6(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON6_HSE_tcon6_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON6_HSE_tcon6_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON6_HSE_get_dummy_6(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON6_HSE_get_tcon6_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON6_HSE_get_tcon6_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON6_VSE                                                          0x1802D2B0
#define  TCON_TCON6_VSE_reg_addr                                                 "0xB802D2B0"
#define  TCON_TCON6_VSE_reg                                                      0xB802D2B0
#define  TCON_TCON6_VSE_inst_addr                                                "0x002C"
#define  set_TCON_TCON6_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON6_VSE_reg)=data)
#define  get_TCON_TCON6_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON6_VSE_reg))
#define  TCON_TCON6_VSE_tcon6_vstart_shift                                       (16)
#define  TCON_TCON6_VSE_tcon6_vend_shift                                         (0)
#define  TCON_TCON6_VSE_tcon6_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON6_VSE_tcon6_vend_mask                                          (0x00000FFF)
#define  TCON_TCON6_VSE_tcon6_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON6_VSE_tcon6_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON6_VSE_get_tcon6_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON6_VSE_get_tcon6_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON6_Ctrl                                                         0x1802D2B4
#define  TCON_TCON6_Ctrl_reg_addr                                                "0xB802D2B4"
#define  TCON_TCON6_Ctrl_reg                                                     0xB802D2B4
#define  TCON_TCON6_Ctrl_inst_addr                                               "0x002D"
#define  set_TCON_TCON6_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON6_Ctrl_reg)=data)
#define  get_TCON_TCON6_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON6_Ctrl_reg))
#define  TCON_TCON6_Ctrl_tcon6_l_flag_sel_shift                                  (13)
#define  TCON_TCON6_Ctrl_tcon6_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON6_Ctrl_tcon6_mode_shift                                        (8)
#define  TCON_TCON6_Ctrl_tcon6_en_shift                                          (7)
#define  TCON_TCON6_Ctrl_tcon6_inv_shift                                         (6)
#define  TCON_TCON6_Ctrl_tcon6_frame_tog_en_shift                                (3)
#define  TCON_TCON6_Ctrl_tcon6_comb_shift                                        (0)
#define  TCON_TCON6_Ctrl_tcon6_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON6_Ctrl_tcon6_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON6_Ctrl_tcon6_mode_mask                                         (0x00000700)
#define  TCON_TCON6_Ctrl_tcon6_en_mask                                           (0x00000080)
#define  TCON_TCON6_Ctrl_tcon6_inv_mask                                          (0x00000040)
#define  TCON_TCON6_Ctrl_tcon6_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON6_Ctrl_tcon6_comb_mask                                         (0x00000007)
#define  TCON_TCON6_Ctrl_tcon6_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON6_Ctrl_tcon6_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON6_Ctrl_tcon6_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON6_Ctrl_tcon6_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON6_Ctrl_tcon6_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON6_Ctrl_tcon6_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON6_Ctrl_tcon6_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON6_Ctrl_get_tcon6_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON6_Ctrl_get_tcon6_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON6_Ctrl_get_tcon6_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON6_Ctrl_get_tcon6_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON6_Ctrl_get_tcon6_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON6_Ctrl_get_tcon6_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON6_Ctrl_get_tcon6_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON6_ACROSS_LINE_CONTROL3                                         0x1802D2B8
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D2B8"
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_reg                                     0xB802D2B8
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_inst_addr                               "0x002E"
#define  set_TCON_TCON6_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON6_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON6_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON6_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_across_frame_int_shift            (28)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_across_ctrl3_rp_shift             (16)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_frame_hl_num_shift                (12)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_across_ctrl3_hp_shift             (0)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_across_frame_int_mask             (0x10000000)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_tcon6_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_get_tcon6_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_get_tcon6_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_get_tcon6_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON6_ACROSS_LINE_CONTROL3_get_tcon6_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON6_ACROSS_FRAME_CONTROL                                         0x1802D2BC
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D2BC"
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_reg                                     0xB802D2BC
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_inst_addr                               "0x002F"
#define  set_TCON_TCON6_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON6_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON6_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON6_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_tcon6_frame_offset_shift                (16)
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_tcon6_frame_period_shift                (0)
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_tcon6_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_tcon6_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_tcon6_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_tcon6_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_get_tcon6_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON6_ACROSS_FRAME_CONTROL_get_tcon6_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON6_FRAME_HL_CONTROL                                             0x1802D2C0
#define  TCON_TCON6_FRAME_HL_CONTROL_reg_addr                                    "0xB802D2C0"
#define  TCON_TCON6_FRAME_HL_CONTROL_reg                                         0xB802D2C0
#define  TCON_TCON6_FRAME_HL_CONTROL_inst_addr                                   "0x0030"
#define  set_TCON_TCON6_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON6_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON6_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON6_FRAME_HL_CONTROL_reg))
#define  TCON_TCON6_FRAME_HL_CONTROL_tcon6_frame_hl_shift                        (16)
#define  TCON_TCON6_FRAME_HL_CONTROL_tcon6_l_flag_prime_shift                    (0)
#define  TCON_TCON6_FRAME_HL_CONTROL_tcon6_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON6_FRAME_HL_CONTROL_tcon6_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON6_FRAME_HL_CONTROL_tcon6_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON6_FRAME_HL_CONTROL_tcon6_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON6_FRAME_HL_CONTROL_get_tcon6_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON6_FRAME_HL_CONTROL_get_tcon6_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON6_H_OFFSET_SHIFT                                               0x1802D2C4
#define  TCON_TCON6_H_OFFSET_SHIFT_reg_addr                                      "0xB802D2C4"
#define  TCON_TCON6_H_OFFSET_SHIFT_reg                                           0xB802D2C4
#define  TCON_TCON6_H_OFFSET_SHIFT_inst_addr                                     "0x0031"
#define  set_TCON_TCON6_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON6_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON6_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON6_H_OFFSET_SHIFT_reg))
#define  TCON_TCON6_H_OFFSET_SHIFT_tcon6_hoffset_shift_en_shift                  (18)
#define  TCON_TCON6_H_OFFSET_SHIFT_tcon6_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON6_H_OFFSET_SHIFT_tcon6_hoffset_shift_value_shift               (0)
#define  TCON_TCON6_H_OFFSET_SHIFT_tcon6_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON6_H_OFFSET_SHIFT_tcon6_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON6_H_OFFSET_SHIFT_tcon6_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON6_H_OFFSET_SHIFT_tcon6_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON6_H_OFFSET_SHIFT_tcon6_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON6_H_OFFSET_SHIFT_tcon6_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON6_H_OFFSET_SHIFT_get_tcon6_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON6_H_OFFSET_SHIFT_get_tcon6_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON6_H_OFFSET_SHIFT_get_tcon6_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_TCON7_HSE                                                          0x1802D2C8
#define  TCON_TCON7_HSE_reg_addr                                                 "0xB802D2C8"
#define  TCON_TCON7_HSE_reg                                                      0xB802D2C8
#define  TCON_TCON7_HSE_inst_addr                                                "0x0032"
#define  set_TCON_TCON7_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON7_HSE_reg)=data)
#define  get_TCON_TCON7_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON7_HSE_reg))
#define  TCON_TCON7_HSE_dummy_7_shift                                            (29)
#define  TCON_TCON7_HSE_tcon7_hstart_shift                                       (16)
#define  TCON_TCON7_HSE_tcon7_hend_shift                                         (0)
#define  TCON_TCON7_HSE_dummy_7_mask                                             (0xE0000000)
#define  TCON_TCON7_HSE_tcon7_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON7_HSE_tcon7_hend_mask                                          (0x00001FFF)
#define  TCON_TCON7_HSE_dummy_7(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON7_HSE_tcon7_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON7_HSE_tcon7_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON7_HSE_get_dummy_7(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON7_HSE_get_tcon7_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON7_HSE_get_tcon7_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON7_VSE                                                          0x1802D2CC
#define  TCON_TCON7_VSE_reg_addr                                                 "0xB802D2CC"
#define  TCON_TCON7_VSE_reg                                                      0xB802D2CC
#define  TCON_TCON7_VSE_inst_addr                                                "0x0033"
#define  set_TCON_TCON7_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON7_VSE_reg)=data)
#define  get_TCON_TCON7_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON7_VSE_reg))
#define  TCON_TCON7_VSE_tcon7_vstart_shift                                       (16)
#define  TCON_TCON7_VSE_tcon7_vend_shift                                         (0)
#define  TCON_TCON7_VSE_tcon7_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON7_VSE_tcon7_vend_mask                                          (0x00000FFF)
#define  TCON_TCON7_VSE_tcon7_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON7_VSE_tcon7_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON7_VSE_get_tcon7_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON7_VSE_get_tcon7_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON7_Ctrl                                                         0x1802D2D0
#define  TCON_TCON7_Ctrl_reg_addr                                                "0xB802D2D0"
#define  TCON_TCON7_Ctrl_reg                                                     0xB802D2D0
#define  TCON_TCON7_Ctrl_inst_addr                                               "0x0034"
#define  set_TCON_TCON7_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON7_Ctrl_reg)=data)
#define  get_TCON_TCON7_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON7_Ctrl_reg))
#define  TCON_TCON7_Ctrl_tcon7_l_flag_sel_shift                                  (13)
#define  TCON_TCON7_Ctrl_tcon7_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON7_Ctrl_tcon7_mode_shift                                        (8)
#define  TCON_TCON7_Ctrl_tcon7_en_shift                                          (7)
#define  TCON_TCON7_Ctrl_tcon7_inv_shift                                         (6)
#define  TCON_TCON7_Ctrl_tcon7_frame_tog_en_shift                                (3)
#define  TCON_TCON7_Ctrl_tcon7_comb_shift                                        (0)
#define  TCON_TCON7_Ctrl_tcon7_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON7_Ctrl_tcon7_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON7_Ctrl_tcon7_mode_mask                                         (0x00000700)
#define  TCON_TCON7_Ctrl_tcon7_en_mask                                           (0x00000080)
#define  TCON_TCON7_Ctrl_tcon7_inv_mask                                          (0x00000040)
#define  TCON_TCON7_Ctrl_tcon7_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON7_Ctrl_tcon7_comb_mask                                         (0x00000007)
#define  TCON_TCON7_Ctrl_tcon7_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON7_Ctrl_tcon7_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON7_Ctrl_tcon7_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON7_Ctrl_tcon7_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON7_Ctrl_tcon7_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON7_Ctrl_tcon7_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON7_Ctrl_tcon7_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON7_Ctrl_get_tcon7_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON7_Ctrl_get_tcon7_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON7_Ctrl_get_tcon7_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON7_Ctrl_get_tcon7_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON7_Ctrl_get_tcon7_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON7_Ctrl_get_tcon7_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON7_Ctrl_get_tcon7_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON7_ACROSS_LINE_CONTROL3                                         0x1802D2D4
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D2D4"
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_reg                                     0xB802D2D4
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_inst_addr                               "0x0035"
#define  set_TCON_TCON7_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON7_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON7_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON7_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_across_frame_int_shift            (28)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_across_ctrl3_rp_shift             (16)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_frame_hl_num_shift                (12)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_across_ctrl3_hp_shift             (0)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_across_frame_int_mask             (0x10000000)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_tcon7_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_get_tcon7_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_get_tcon7_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_get_tcon7_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON7_ACROSS_LINE_CONTROL3_get_tcon7_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON7_ACROSS_FRAME_CONTROL                                         0x1802D2D8
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D2D8"
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_reg                                     0xB802D2D8
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_inst_addr                               "0x0036"
#define  set_TCON_TCON7_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON7_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON7_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON7_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_tcon7_frame_offset_shift                (16)
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_tcon7_frame_period_shift                (0)
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_tcon7_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_tcon7_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_tcon7_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_tcon7_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_get_tcon7_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON7_ACROSS_FRAME_CONTROL_get_tcon7_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON7_FRAME_HL_CONTROL                                             0x1802D2DC
#define  TCON_TCON7_FRAME_HL_CONTROL_reg_addr                                    "0xB802D2DC"
#define  TCON_TCON7_FRAME_HL_CONTROL_reg                                         0xB802D2DC
#define  TCON_TCON7_FRAME_HL_CONTROL_inst_addr                                   "0x0037"
#define  set_TCON_TCON7_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON7_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON7_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON7_FRAME_HL_CONTROL_reg))
#define  TCON_TCON7_FRAME_HL_CONTROL_tcon7_frame_hl_shift                        (16)
#define  TCON_TCON7_FRAME_HL_CONTROL_tcon7_l_flag_prime_shift                    (0)
#define  TCON_TCON7_FRAME_HL_CONTROL_tcon7_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON7_FRAME_HL_CONTROL_tcon7_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON7_FRAME_HL_CONTROL_tcon7_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON7_FRAME_HL_CONTROL_tcon7_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON7_FRAME_HL_CONTROL_get_tcon7_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON7_FRAME_HL_CONTROL_get_tcon7_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON7_H_OFFSET_SHIFT                                               0x1802D2E0
#define  TCON_TCON7_H_OFFSET_SHIFT_reg_addr                                      "0xB802D2E0"
#define  TCON_TCON7_H_OFFSET_SHIFT_reg                                           0xB802D2E0
#define  TCON_TCON7_H_OFFSET_SHIFT_inst_addr                                     "0x0038"
#define  set_TCON_TCON7_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON7_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON7_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON7_H_OFFSET_SHIFT_reg))
#define  TCON_TCON7_H_OFFSET_SHIFT_tcon7_hoffset_shift_en_shift                  (18)
#define  TCON_TCON7_H_OFFSET_SHIFT_tcon7_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON7_H_OFFSET_SHIFT_tcon7_hoffset_shift_value_shift               (0)
#define  TCON_TCON7_H_OFFSET_SHIFT_tcon7_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON7_H_OFFSET_SHIFT_tcon7_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON7_H_OFFSET_SHIFT_tcon7_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON7_H_OFFSET_SHIFT_tcon7_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON7_H_OFFSET_SHIFT_tcon7_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON7_H_OFFSET_SHIFT_tcon7_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON7_H_OFFSET_SHIFT_get_tcon7_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON7_H_OFFSET_SHIFT_get_tcon7_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON7_H_OFFSET_SHIFT_get_tcon7_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_TCON8_HSE                                                          0x1802D2E4
#define  TCON_TCON8_HSE_reg_addr                                                 "0xB802D2E4"
#define  TCON_TCON8_HSE_reg                                                      0xB802D2E4
#define  TCON_TCON8_HSE_inst_addr                                                "0x0039"
#define  set_TCON_TCON8_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON8_HSE_reg)=data)
#define  get_TCON_TCON8_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON8_HSE_reg))
#define  TCON_TCON8_HSE_dummy_8_shift                                            (29)
#define  TCON_TCON8_HSE_tcon8_hstart_shift                                       (16)
#define  TCON_TCON8_HSE_tcon8_hend_shift                                         (0)
#define  TCON_TCON8_HSE_dummy_8_mask                                             (0xE0000000)
#define  TCON_TCON8_HSE_tcon8_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON8_HSE_tcon8_hend_mask                                          (0x00001FFF)
#define  TCON_TCON8_HSE_dummy_8(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON8_HSE_tcon8_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON8_HSE_tcon8_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON8_HSE_get_dummy_8(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON8_HSE_get_tcon8_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON8_HSE_get_tcon8_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON8_VSE                                                          0x1802D2E8
#define  TCON_TCON8_VSE_reg_addr                                                 "0xB802D2E8"
#define  TCON_TCON8_VSE_reg                                                      0xB802D2E8
#define  TCON_TCON8_VSE_inst_addr                                                "0x003A"
#define  set_TCON_TCON8_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON8_VSE_reg)=data)
#define  get_TCON_TCON8_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON8_VSE_reg))
#define  TCON_TCON8_VSE_tcon8_vstart_shift                                       (16)
#define  TCON_TCON8_VSE_tcon8_vend_shift                                         (0)
#define  TCON_TCON8_VSE_tcon8_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON8_VSE_tcon8_vend_mask                                          (0x00000FFF)
#define  TCON_TCON8_VSE_tcon8_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON8_VSE_tcon8_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON8_VSE_get_tcon8_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON8_VSE_get_tcon8_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON8_Ctrl                                                         0x1802D2EC
#define  TCON_TCON8_Ctrl_reg_addr                                                "0xB802D2EC"
#define  TCON_TCON8_Ctrl_reg                                                     0xB802D2EC
#define  TCON_TCON8_Ctrl_inst_addr                                               "0x003B"
#define  set_TCON_TCON8_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON8_Ctrl_reg)=data)
#define  get_TCON_TCON8_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON8_Ctrl_reg))
#define  TCON_TCON8_Ctrl_tcon8_l_flag_sel_shift                                  (13)
#define  TCON_TCON8_Ctrl_tcon8_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON8_Ctrl_tcon8_mode_shift                                        (8)
#define  TCON_TCON8_Ctrl_tcon8_en_shift                                          (7)
#define  TCON_TCON8_Ctrl_tcon8_inv_shift                                         (6)
#define  TCON_TCON8_Ctrl_tcon8_frame_tog_en_shift                                (3)
#define  TCON_TCON8_Ctrl_tcon8_comb_shift                                        (0)
#define  TCON_TCON8_Ctrl_tcon8_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON8_Ctrl_tcon8_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON8_Ctrl_tcon8_mode_mask                                         (0x00000700)
#define  TCON_TCON8_Ctrl_tcon8_en_mask                                           (0x00000080)
#define  TCON_TCON8_Ctrl_tcon8_inv_mask                                          (0x00000040)
#define  TCON_TCON8_Ctrl_tcon8_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON8_Ctrl_tcon8_comb_mask                                         (0x00000007)
#define  TCON_TCON8_Ctrl_tcon8_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON8_Ctrl_tcon8_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON8_Ctrl_tcon8_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON8_Ctrl_tcon8_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON8_Ctrl_tcon8_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON8_Ctrl_tcon8_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON8_Ctrl_tcon8_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON8_Ctrl_get_tcon8_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON8_Ctrl_get_tcon8_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON8_Ctrl_get_tcon8_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON8_Ctrl_get_tcon8_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON8_Ctrl_get_tcon8_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON8_Ctrl_get_tcon8_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON8_Ctrl_get_tcon8_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON8_ACROSS_LINE_CONTROL3                                         0x1802D2F0
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D2F0"
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_reg                                     0xB802D2F0
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_inst_addr                               "0x003C"
#define  set_TCON_TCON8_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON8_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON8_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON8_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_across_frame_int_shift            (28)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_across_ctrl3_rp_shift             (16)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_frame_hl_num_shift                (12)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_across_ctrl3_hp_shift             (0)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_across_frame_int_mask             (0x10000000)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_tcon8_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_get_tcon8_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_get_tcon8_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_get_tcon8_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON8_ACROSS_LINE_CONTROL3_get_tcon8_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON8_ACROSS_FRAME_CONTROL                                         0x1802D2F4
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D2F4"
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_reg                                     0xB802D2F4
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_inst_addr                               "0x003D"
#define  set_TCON_TCON8_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON8_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON8_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON8_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_tcon8_frame_offset_shift                (16)
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_tcon8_frame_period_shift                (0)
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_tcon8_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_tcon8_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_tcon8_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_tcon8_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_get_tcon8_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON8_ACROSS_FRAME_CONTROL_get_tcon8_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON8_FRAME_HL_CONTROL                                             0x1802D2F8
#define  TCON_TCON8_FRAME_HL_CONTROL_reg_addr                                    "0xB802D2F8"
#define  TCON_TCON8_FRAME_HL_CONTROL_reg                                         0xB802D2F8
#define  TCON_TCON8_FRAME_HL_CONTROL_inst_addr                                   "0x003E"
#define  set_TCON_TCON8_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON8_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON8_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON8_FRAME_HL_CONTROL_reg))
#define  TCON_TCON8_FRAME_HL_CONTROL_tcon8_frame_hl_shift                        (16)
#define  TCON_TCON8_FRAME_HL_CONTROL_tcon8_l_flag_prime_shift                    (0)
#define  TCON_TCON8_FRAME_HL_CONTROL_tcon8_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON8_FRAME_HL_CONTROL_tcon8_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON8_FRAME_HL_CONTROL_tcon8_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON8_FRAME_HL_CONTROL_tcon8_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON8_FRAME_HL_CONTROL_get_tcon8_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON8_FRAME_HL_CONTROL_get_tcon8_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON8_H_OFFSET_SHIFT                                               0x1802D2FC
#define  TCON_TCON8_H_OFFSET_SHIFT_reg_addr                                      "0xB802D2FC"
#define  TCON_TCON8_H_OFFSET_SHIFT_reg                                           0xB802D2FC
#define  TCON_TCON8_H_OFFSET_SHIFT_inst_addr                                     "0x003F"
#define  set_TCON_TCON8_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON8_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON8_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON8_H_OFFSET_SHIFT_reg))
#define  TCON_TCON8_H_OFFSET_SHIFT_tcon8_hoffset_shift_en_shift                  (18)
#define  TCON_TCON8_H_OFFSET_SHIFT_tcon8_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON8_H_OFFSET_SHIFT_tcon8_hoffset_shift_value_shift               (0)
#define  TCON_TCON8_H_OFFSET_SHIFT_tcon8_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON8_H_OFFSET_SHIFT_tcon8_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON8_H_OFFSET_SHIFT_tcon8_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON8_H_OFFSET_SHIFT_tcon8_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON8_H_OFFSET_SHIFT_tcon8_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON8_H_OFFSET_SHIFT_tcon8_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON8_H_OFFSET_SHIFT_get_tcon8_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON8_H_OFFSET_SHIFT_get_tcon8_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON8_H_OFFSET_SHIFT_get_tcon8_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_TCON9_HSE                                                          0x1802D300
#define  TCON_TCON9_HSE_reg_addr                                                 "0xB802D300"
#define  TCON_TCON9_HSE_reg                                                      0xB802D300
#define  TCON_TCON9_HSE_inst_addr                                                "0x0040"
#define  set_TCON_TCON9_HSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON9_HSE_reg)=data)
#define  get_TCON_TCON9_HSE_reg                                                  (*((volatile unsigned int*)TCON_TCON9_HSE_reg))
#define  TCON_TCON9_HSE_dummy_9_shift                                            (29)
#define  TCON_TCON9_HSE_tcon9_hstart_shift                                       (16)
#define  TCON_TCON9_HSE_tcon9_hend_shift                                         (0)
#define  TCON_TCON9_HSE_dummy_9_mask                                             (0xE0000000)
#define  TCON_TCON9_HSE_tcon9_hstart_mask                                        (0x1FFF0000)
#define  TCON_TCON9_HSE_tcon9_hend_mask                                          (0x00001FFF)
#define  TCON_TCON9_HSE_dummy_9(data)                                            (0xE0000000&((data)<<29))
#define  TCON_TCON9_HSE_tcon9_hstart(data)                                       (0x1FFF0000&((data)<<16))
#define  TCON_TCON9_HSE_tcon9_hend(data)                                         (0x00001FFF&(data))
#define  TCON_TCON9_HSE_get_dummy_9(data)                                        ((0xE0000000&(data))>>29)
#define  TCON_TCON9_HSE_get_tcon9_hstart(data)                                   ((0x1FFF0000&(data))>>16)
#define  TCON_TCON9_HSE_get_tcon9_hend(data)                                     (0x00001FFF&(data))

#define  TCON_TCON9_VSE                                                          0x1802D304
#define  TCON_TCON9_VSE_reg_addr                                                 "0xB802D304"
#define  TCON_TCON9_VSE_reg                                                      0xB802D304
#define  TCON_TCON9_VSE_inst_addr                                                "0x0041"
#define  set_TCON_TCON9_VSE_reg(data)                                            (*((volatile unsigned int*)TCON_TCON9_VSE_reg)=data)
#define  get_TCON_TCON9_VSE_reg                                                  (*((volatile unsigned int*)TCON_TCON9_VSE_reg))
#define  TCON_TCON9_VSE_tcon9_vstart_shift                                       (16)
#define  TCON_TCON9_VSE_tcon9_vend_shift                                         (0)
#define  TCON_TCON9_VSE_tcon9_vstart_mask                                        (0x0FFF0000)
#define  TCON_TCON9_VSE_tcon9_vend_mask                                          (0x00000FFF)
#define  TCON_TCON9_VSE_tcon9_vstart(data)                                       (0x0FFF0000&((data)<<16))
#define  TCON_TCON9_VSE_tcon9_vend(data)                                         (0x00000FFF&(data))
#define  TCON_TCON9_VSE_get_tcon9_vstart(data)                                   ((0x0FFF0000&(data))>>16)
#define  TCON_TCON9_VSE_get_tcon9_vend(data)                                     (0x00000FFF&(data))

#define  TCON_TCON9_Ctrl                                                         0x1802D308
#define  TCON_TCON9_Ctrl_reg_addr                                                "0xB802D308"
#define  TCON_TCON9_Ctrl_reg                                                     0xB802D308
#define  TCON_TCON9_Ctrl_inst_addr                                               "0x0042"
#define  set_TCON_TCON9_Ctrl_reg(data)                                           (*((volatile unsigned int*)TCON_TCON9_Ctrl_reg)=data)
#define  get_TCON_TCON9_Ctrl_reg                                                 (*((volatile unsigned int*)TCON_TCON9_Ctrl_reg))
#define  TCON_TCON9_Ctrl_tcon9_l_flag_sel_shift                                  (13)
#define  TCON_TCON9_Ctrl_tcon9_across_ctrl3_reset_shift                          (11)
#define  TCON_TCON9_Ctrl_tcon9_mode_shift                                        (8)
#define  TCON_TCON9_Ctrl_tcon9_en_shift                                          (7)
#define  TCON_TCON9_Ctrl_tcon9_inv_shift                                         (6)
#define  TCON_TCON9_Ctrl_tcon9_frame_tog_en_shift                                (3)
#define  TCON_TCON9_Ctrl_tcon9_comb_shift                                        (0)
#define  TCON_TCON9_Ctrl_tcon9_l_flag_sel_mask                                   (0x0003E000)
#define  TCON_TCON9_Ctrl_tcon9_across_ctrl3_reset_mask                           (0x00000800)
#define  TCON_TCON9_Ctrl_tcon9_mode_mask                                         (0x00000700)
#define  TCON_TCON9_Ctrl_tcon9_en_mask                                           (0x00000080)
#define  TCON_TCON9_Ctrl_tcon9_inv_mask                                          (0x00000040)
#define  TCON_TCON9_Ctrl_tcon9_frame_tog_en_mask                                 (0x00000008)
#define  TCON_TCON9_Ctrl_tcon9_comb_mask                                         (0x00000007)
#define  TCON_TCON9_Ctrl_tcon9_l_flag_sel(data)                                  (0x0003E000&((data)<<13))
#define  TCON_TCON9_Ctrl_tcon9_across_ctrl3_reset(data)                          (0x00000800&((data)<<11))
#define  TCON_TCON9_Ctrl_tcon9_mode(data)                                        (0x00000700&((data)<<8))
#define  TCON_TCON9_Ctrl_tcon9_en(data)                                          (0x00000080&((data)<<7))
#define  TCON_TCON9_Ctrl_tcon9_inv(data)                                         (0x00000040&((data)<<6))
#define  TCON_TCON9_Ctrl_tcon9_frame_tog_en(data)                                (0x00000008&((data)<<3))
#define  TCON_TCON9_Ctrl_tcon9_comb(data)                                        (0x00000007&(data))
#define  TCON_TCON9_Ctrl_get_tcon9_l_flag_sel(data)                              ((0x0003E000&(data))>>13)
#define  TCON_TCON9_Ctrl_get_tcon9_across_ctrl3_reset(data)                      ((0x00000800&(data))>>11)
#define  TCON_TCON9_Ctrl_get_tcon9_mode(data)                                    ((0x00000700&(data))>>8)
#define  TCON_TCON9_Ctrl_get_tcon9_en(data)                                      ((0x00000080&(data))>>7)
#define  TCON_TCON9_Ctrl_get_tcon9_inv(data)                                     ((0x00000040&(data))>>6)
#define  TCON_TCON9_Ctrl_get_tcon9_frame_tog_en(data)                            ((0x00000008&(data))>>3)
#define  TCON_TCON9_Ctrl_get_tcon9_comb(data)                                    (0x00000007&(data))

#define  TCON_TCON9_ACROSS_LINE_CONTROL3                                         0x1802D30C
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_reg_addr                                "0xB802D30C"
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_reg                                     0xB802D30C
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_inst_addr                               "0x0043"
#define  set_TCON_TCON9_ACROSS_LINE_CONTROL3_reg(data)                           (*((volatile unsigned int*)TCON_TCON9_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON9_ACROSS_LINE_CONTROL3_reg                                 (*((volatile unsigned int*)TCON_TCON9_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_across_frame_int_shift            (28)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_across_ctrl3_rp_shift             (16)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_frame_hl_num_shift                (12)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_across_ctrl3_hp_shift             (0)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_across_frame_int_mask             (0x10000000)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_across_ctrl3_rp_mask              (0x0FFF0000)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_frame_hl_num_mask                 (0x0000F000)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_across_ctrl3_hp_mask              (0x00000FFF)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_across_frame_int(data)            (0x10000000&((data)<<28))
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_across_ctrl3_rp(data)             (0x0FFF0000&((data)<<16))
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_frame_hl_num(data)                (0x0000F000&((data)<<12))
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_tcon9_across_ctrl3_hp(data)             (0x00000FFF&(data))
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_get_tcon9_across_frame_int(data)        ((0x10000000&(data))>>28)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_get_tcon9_across_ctrl3_rp(data)         ((0x0FFF0000&(data))>>16)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_get_tcon9_frame_hl_num(data)            ((0x0000F000&(data))>>12)
#define  TCON_TCON9_ACROSS_LINE_CONTROL3_get_tcon9_across_ctrl3_hp(data)         (0x00000FFF&(data))

#define  TCON_TCON9_ACROSS_FRAME_CONTROL                                         0x1802D310
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_reg_addr                                "0xB802D310"
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_reg                                     0xB802D310
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_inst_addr                               "0x0044"
#define  set_TCON_TCON9_ACROSS_FRAME_CONTROL_reg(data)                           (*((volatile unsigned int*)TCON_TCON9_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON9_ACROSS_FRAME_CONTROL_reg                                 (*((volatile unsigned int*)TCON_TCON9_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_tcon9_frame_offset_shift                (16)
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_tcon9_frame_period_shift                (0)
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_tcon9_frame_offset_mask                 (0x0FFF0000)
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_tcon9_frame_period_mask                 (0x00000FFF)
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_tcon9_frame_offset(data)                (0x0FFF0000&((data)<<16))
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_tcon9_frame_period(data)                (0x00000FFF&(data))
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_get_tcon9_frame_offset(data)            ((0x0FFF0000&(data))>>16)
#define  TCON_TCON9_ACROSS_FRAME_CONTROL_get_tcon9_frame_period(data)            (0x00000FFF&(data))

#define  TCON_TCON9_FRAME_HL_CONTROL                                             0x1802D314
#define  TCON_TCON9_FRAME_HL_CONTROL_reg_addr                                    "0xB802D314"
#define  TCON_TCON9_FRAME_HL_CONTROL_reg                                         0xB802D314
#define  TCON_TCON9_FRAME_HL_CONTROL_inst_addr                                   "0x0045"
#define  set_TCON_TCON9_FRAME_HL_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON9_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON9_FRAME_HL_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON9_FRAME_HL_CONTROL_reg))
#define  TCON_TCON9_FRAME_HL_CONTROL_tcon9_frame_hl_shift                        (16)
#define  TCON_TCON9_FRAME_HL_CONTROL_tcon9_l_flag_prime_shift                    (0)
#define  TCON_TCON9_FRAME_HL_CONTROL_tcon9_frame_hl_mask                         (0xFFFF0000)
#define  TCON_TCON9_FRAME_HL_CONTROL_tcon9_l_flag_prime_mask                     (0x0000FFFF)
#define  TCON_TCON9_FRAME_HL_CONTROL_tcon9_frame_hl(data)                        (0xFFFF0000&((data)<<16))
#define  TCON_TCON9_FRAME_HL_CONTROL_tcon9_l_flag_prime(data)                    (0x0000FFFF&(data))
#define  TCON_TCON9_FRAME_HL_CONTROL_get_tcon9_frame_hl(data)                    ((0xFFFF0000&(data))>>16)
#define  TCON_TCON9_FRAME_HL_CONTROL_get_tcon9_l_flag_prime(data)                (0x0000FFFF&(data))

#define  TCON_TCON9_H_OFFSET_SHIFT                                               0x1802D318
#define  TCON_TCON9_H_OFFSET_SHIFT_reg_addr                                      "0xB802D318"
#define  TCON_TCON9_H_OFFSET_SHIFT_reg                                           0xB802D318
#define  TCON_TCON9_H_OFFSET_SHIFT_inst_addr                                     "0x0046"
#define  set_TCON_TCON9_H_OFFSET_SHIFT_reg(data)                                 (*((volatile unsigned int*)TCON_TCON9_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON9_H_OFFSET_SHIFT_reg                                       (*((volatile unsigned int*)TCON_TCON9_H_OFFSET_SHIFT_reg))
#define  TCON_TCON9_H_OFFSET_SHIFT_tcon9_hoffset_shift_en_shift                  (18)
#define  TCON_TCON9_H_OFFSET_SHIFT_tcon9_hoffset_shift_thd_shift                 (6)
#define  TCON_TCON9_H_OFFSET_SHIFT_tcon9_hoffset_shift_value_shift               (0)
#define  TCON_TCON9_H_OFFSET_SHIFT_tcon9_hoffset_shift_en_mask                   (0x00040000)
#define  TCON_TCON9_H_OFFSET_SHIFT_tcon9_hoffset_shift_thd_mask                  (0x0003FFC0)
#define  TCON_TCON9_H_OFFSET_SHIFT_tcon9_hoffset_shift_value_mask                (0x0000003F)
#define  TCON_TCON9_H_OFFSET_SHIFT_tcon9_hoffset_shift_en(data)                  (0x00040000&((data)<<18))
#define  TCON_TCON9_H_OFFSET_SHIFT_tcon9_hoffset_shift_thd(data)                 (0x0003FFC0&((data)<<6))
#define  TCON_TCON9_H_OFFSET_SHIFT_tcon9_hoffset_shift_value(data)               (0x0000003F&(data))
#define  TCON_TCON9_H_OFFSET_SHIFT_get_tcon9_hoffset_shift_en(data)              ((0x00040000&(data))>>18)
#define  TCON_TCON9_H_OFFSET_SHIFT_get_tcon9_hoffset_shift_thd(data)             ((0x0003FFC0&(data))>>6)
#define  TCON_TCON9_H_OFFSET_SHIFT_get_tcon9_hoffset_shift_value(data)           (0x0000003F&(data))

#define  TCON_Double_Buffer_CTRL0                                                0x1802D31C
#define  TCON_Double_Buffer_CTRL0_reg_addr                                       "0xB802D31C"
#define  TCON_Double_Buffer_CTRL0_reg                                            0xB802D31C
#define  TCON_Double_Buffer_CTRL0_inst_addr                                      "0x0047"
#define  set_TCON_Double_Buffer_CTRL0_reg(data)                                  (*((volatile unsigned int*)TCON_Double_Buffer_CTRL0_reg)=data)
#define  get_TCON_Double_Buffer_CTRL0_reg                                        (*((volatile unsigned int*)TCON_Double_Buffer_CTRL0_reg))
#define  TCON_Double_Buffer_CTRL0_dreg_dbuf0_en_n_shift                          (2)
#define  TCON_Double_Buffer_CTRL0_dreg_dbuf0_read_sel_shift                      (1)
#define  TCON_Double_Buffer_CTRL0_dreg_dbuf0_set_shift                           (0)
#define  TCON_Double_Buffer_CTRL0_dreg_dbuf0_en_n_mask                           (0x00000004)
#define  TCON_Double_Buffer_CTRL0_dreg_dbuf0_read_sel_mask                       (0x00000002)
#define  TCON_Double_Buffer_CTRL0_dreg_dbuf0_set_mask                            (0x00000001)
#define  TCON_Double_Buffer_CTRL0_dreg_dbuf0_en_n(data)                          (0x00000004&((data)<<2))
#define  TCON_Double_Buffer_CTRL0_dreg_dbuf0_read_sel(data)                      (0x00000002&((data)<<1))
#define  TCON_Double_Buffer_CTRL0_dreg_dbuf0_set(data)                           (0x00000001&(data))
#define  TCON_Double_Buffer_CTRL0_get_dreg_dbuf0_en_n(data)                      ((0x00000004&(data))>>2)
#define  TCON_Double_Buffer_CTRL0_get_dreg_dbuf0_read_sel(data)                  ((0x00000002&(data))>>1)
#define  TCON_Double_Buffer_CTRL0_get_dreg_dbuf0_set(data)                       (0x00000001&(data))

#define  TCON_TCON10_HSE                                                         0x1802D320
#define  TCON_TCON10_HSE_reg_addr                                                "0xB802D320"
#define  TCON_TCON10_HSE_reg                                                     0xB802D320
#define  TCON_TCON10_HSE_inst_addr                                               "0x0048"
#define  set_TCON_TCON10_HSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON10_HSE_reg)=data)
#define  get_TCON_TCON10_HSE_reg                                                 (*((volatile unsigned int*)TCON_TCON10_HSE_reg))
#define  TCON_TCON10_HSE_dummy_10_shift                                          (29)
#define  TCON_TCON10_HSE_tcon10_hstart_shift                                     (16)
#define  TCON_TCON10_HSE_tcon10_hend_shift                                       (0)
#define  TCON_TCON10_HSE_dummy_10_mask                                           (0xE0000000)
#define  TCON_TCON10_HSE_tcon10_hstart_mask                                      (0x1FFF0000)
#define  TCON_TCON10_HSE_tcon10_hend_mask                                        (0x00001FFF)
#define  TCON_TCON10_HSE_dummy_10(data)                                          (0xE0000000&((data)<<29))
#define  TCON_TCON10_HSE_tcon10_hstart(data)                                     (0x1FFF0000&((data)<<16))
#define  TCON_TCON10_HSE_tcon10_hend(data)                                       (0x00001FFF&(data))
#define  TCON_TCON10_HSE_get_dummy_10(data)                                      ((0xE0000000&(data))>>29)
#define  TCON_TCON10_HSE_get_tcon10_hstart(data)                                 ((0x1FFF0000&(data))>>16)
#define  TCON_TCON10_HSE_get_tcon10_hend(data)                                   (0x00001FFF&(data))

#define  TCON_TCON10_VSE                                                         0x1802D324
#define  TCON_TCON10_VSE_reg_addr                                                "0xB802D324"
#define  TCON_TCON10_VSE_reg                                                     0xB802D324
#define  TCON_TCON10_VSE_inst_addr                                               "0x0049"
#define  set_TCON_TCON10_VSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON10_VSE_reg)=data)
#define  get_TCON_TCON10_VSE_reg                                                 (*((volatile unsigned int*)TCON_TCON10_VSE_reg))
#define  TCON_TCON10_VSE_tcon10_vstart_shift                                     (16)
#define  TCON_TCON10_VSE_tcon10_vend_shift                                       (0)
#define  TCON_TCON10_VSE_tcon10_vstart_mask                                      (0x0FFF0000)
#define  TCON_TCON10_VSE_tcon10_vend_mask                                        (0x00000FFF)
#define  TCON_TCON10_VSE_tcon10_vstart(data)                                     (0x0FFF0000&((data)<<16))
#define  TCON_TCON10_VSE_tcon10_vend(data)                                       (0x00000FFF&(data))
#define  TCON_TCON10_VSE_get_tcon10_vstart(data)                                 ((0x0FFF0000&(data))>>16)
#define  TCON_TCON10_VSE_get_tcon10_vend(data)                                   (0x00000FFF&(data))

#define  TCON_TCON10_Ctrl                                                        0x1802D328
#define  TCON_TCON10_Ctrl_reg_addr                                               "0xB802D328"
#define  TCON_TCON10_Ctrl_reg                                                    0xB802D328
#define  TCON_TCON10_Ctrl_inst_addr                                              "0x004A"
#define  set_TCON_TCON10_Ctrl_reg(data)                                          (*((volatile unsigned int*)TCON_TCON10_Ctrl_reg)=data)
#define  get_TCON_TCON10_Ctrl_reg                                                (*((volatile unsigned int*)TCON_TCON10_Ctrl_reg))
#define  TCON_TCON10_Ctrl_tcon10_l_flag_sel_shift                                (13)
#define  TCON_TCON10_Ctrl_tcon10_across_ctrl3_reset_shift                        (11)
#define  TCON_TCON10_Ctrl_tcon10_mode_shift                                      (8)
#define  TCON_TCON10_Ctrl_tcon10_en_shift                                        (7)
#define  TCON_TCON10_Ctrl_tcon10_inv_shift                                       (6)
#define  TCON_TCON10_Ctrl_tcon10_frame_tog_en_shift                              (3)
#define  TCON_TCON10_Ctrl_tcon10_comb_shift                                      (0)
#define  TCON_TCON10_Ctrl_tcon10_l_flag_sel_mask                                 (0x0003E000)
#define  TCON_TCON10_Ctrl_tcon10_across_ctrl3_reset_mask                         (0x00000800)
#define  TCON_TCON10_Ctrl_tcon10_mode_mask                                       (0x00000700)
#define  TCON_TCON10_Ctrl_tcon10_en_mask                                         (0x00000080)
#define  TCON_TCON10_Ctrl_tcon10_inv_mask                                        (0x00000040)
#define  TCON_TCON10_Ctrl_tcon10_frame_tog_en_mask                               (0x00000008)
#define  TCON_TCON10_Ctrl_tcon10_comb_mask                                       (0x00000007)
#define  TCON_TCON10_Ctrl_tcon10_l_flag_sel(data)                                (0x0003E000&((data)<<13))
#define  TCON_TCON10_Ctrl_tcon10_across_ctrl3_reset(data)                        (0x00000800&((data)<<11))
#define  TCON_TCON10_Ctrl_tcon10_mode(data)                                      (0x00000700&((data)<<8))
#define  TCON_TCON10_Ctrl_tcon10_en(data)                                        (0x00000080&((data)<<7))
#define  TCON_TCON10_Ctrl_tcon10_inv(data)                                       (0x00000040&((data)<<6))
#define  TCON_TCON10_Ctrl_tcon10_frame_tog_en(data)                              (0x00000008&((data)<<3))
#define  TCON_TCON10_Ctrl_tcon10_comb(data)                                      (0x00000007&(data))
#define  TCON_TCON10_Ctrl_get_tcon10_l_flag_sel(data)                            ((0x0003E000&(data))>>13)
#define  TCON_TCON10_Ctrl_get_tcon10_across_ctrl3_reset(data)                    ((0x00000800&(data))>>11)
#define  TCON_TCON10_Ctrl_get_tcon10_mode(data)                                  ((0x00000700&(data))>>8)
#define  TCON_TCON10_Ctrl_get_tcon10_en(data)                                    ((0x00000080&(data))>>7)
#define  TCON_TCON10_Ctrl_get_tcon10_inv(data)                                   ((0x00000040&(data))>>6)
#define  TCON_TCON10_Ctrl_get_tcon10_frame_tog_en(data)                          ((0x00000008&(data))>>3)
#define  TCON_TCON10_Ctrl_get_tcon10_comb(data)                                  (0x00000007&(data))

#define  TCON_TCON10_ACROSS_LINE_CONTROL3                                        0x1802D32C
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_reg_addr                               "0xB802D32C"
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_reg                                    0xB802D32C
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_inst_addr                              "0x004B"
#define  set_TCON_TCON10_ACROSS_LINE_CONTROL3_reg(data)                          (*((volatile unsigned int*)TCON_TCON10_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON10_ACROSS_LINE_CONTROL3_reg                                (*((volatile unsigned int*)TCON_TCON10_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_across_frame_int_shift          (28)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_across_ctrl3_rp_shift           (16)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_frame_hl_num_shift              (12)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_across_ctrl3_hp_shift           (0)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_across_frame_int_mask           (0x10000000)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_across_ctrl3_rp_mask            (0x0FFF0000)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_frame_hl_num_mask               (0x0000F000)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_across_ctrl3_hp_mask            (0x00000FFF)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_across_frame_int(data)          (0x10000000&((data)<<28))
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_across_ctrl3_rp(data)           (0x0FFF0000&((data)<<16))
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_frame_hl_num(data)              (0x0000F000&((data)<<12))
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_tcon10_across_ctrl3_hp(data)           (0x00000FFF&(data))
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_get_tcon10_across_frame_int(data)      ((0x10000000&(data))>>28)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_get_tcon10_across_ctrl3_rp(data)       ((0x0FFF0000&(data))>>16)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_get_tcon10_frame_hl_num(data)          ((0x0000F000&(data))>>12)
#define  TCON_TCON10_ACROSS_LINE_CONTROL3_get_tcon10_across_ctrl3_hp(data)       (0x00000FFF&(data))

#define  TCON_TCON10_ACROSS_FRAME_CONTROL                                        0x1802D330
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_reg_addr                               "0xB802D330"
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_reg                                    0xB802D330
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_inst_addr                              "0x004C"
#define  set_TCON_TCON10_ACROSS_FRAME_CONTROL_reg(data)                          (*((volatile unsigned int*)TCON_TCON10_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON10_ACROSS_FRAME_CONTROL_reg                                (*((volatile unsigned int*)TCON_TCON10_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_tcon10_frame_offset_shift              (16)
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_tcon10_frame_period_shift              (0)
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_tcon10_frame_offset_mask               (0x0FFF0000)
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_tcon10_frame_period_mask               (0x00000FFF)
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_tcon10_frame_offset(data)              (0x0FFF0000&((data)<<16))
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_tcon10_frame_period(data)              (0x00000FFF&(data))
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_get_tcon10_frame_offset(data)          ((0x0FFF0000&(data))>>16)
#define  TCON_TCON10_ACROSS_FRAME_CONTROL_get_tcon10_frame_period(data)          (0x00000FFF&(data))

#define  TCON_TCON10_FRAME_HL_CONTROL                                            0x1802D334
#define  TCON_TCON10_FRAME_HL_CONTROL_reg_addr                                   "0xB802D334"
#define  TCON_TCON10_FRAME_HL_CONTROL_reg                                        0xB802D334
#define  TCON_TCON10_FRAME_HL_CONTROL_inst_addr                                  "0x004D"
#define  set_TCON_TCON10_FRAME_HL_CONTROL_reg(data)                              (*((volatile unsigned int*)TCON_TCON10_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON10_FRAME_HL_CONTROL_reg                                    (*((volatile unsigned int*)TCON_TCON10_FRAME_HL_CONTROL_reg))
#define  TCON_TCON10_FRAME_HL_CONTROL_tcon10_frame_hl_shift                      (16)
#define  TCON_TCON10_FRAME_HL_CONTROL_tcon10_l_flag_prime_shift                  (0)
#define  TCON_TCON10_FRAME_HL_CONTROL_tcon10_frame_hl_mask                       (0xFFFF0000)
#define  TCON_TCON10_FRAME_HL_CONTROL_tcon10_l_flag_prime_mask                   (0x0000FFFF)
#define  TCON_TCON10_FRAME_HL_CONTROL_tcon10_frame_hl(data)                      (0xFFFF0000&((data)<<16))
#define  TCON_TCON10_FRAME_HL_CONTROL_tcon10_l_flag_prime(data)                  (0x0000FFFF&(data))
#define  TCON_TCON10_FRAME_HL_CONTROL_get_tcon10_frame_hl(data)                  ((0xFFFF0000&(data))>>16)
#define  TCON_TCON10_FRAME_HL_CONTROL_get_tcon10_l_flag_prime(data)              (0x0000FFFF&(data))

#define  TCON_TCON10_H_OFFSET_SHIFT                                              0x1802D338
#define  TCON_TCON10_H_OFFSET_SHIFT_reg_addr                                     "0xB802D338"
#define  TCON_TCON10_H_OFFSET_SHIFT_reg                                          0xB802D338
#define  TCON_TCON10_H_OFFSET_SHIFT_inst_addr                                    "0x004E"
#define  set_TCON_TCON10_H_OFFSET_SHIFT_reg(data)                                (*((volatile unsigned int*)TCON_TCON10_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON10_H_OFFSET_SHIFT_reg                                      (*((volatile unsigned int*)TCON_TCON10_H_OFFSET_SHIFT_reg))
#define  TCON_TCON10_H_OFFSET_SHIFT_tcon10_hoffset_shift_en_shift                (18)
#define  TCON_TCON10_H_OFFSET_SHIFT_tcon10_hoffset_shift_thd_shift               (6)
#define  TCON_TCON10_H_OFFSET_SHIFT_tcon10_hoffset_shift_value_shift             (0)
#define  TCON_TCON10_H_OFFSET_SHIFT_tcon10_hoffset_shift_en_mask                 (0x00040000)
#define  TCON_TCON10_H_OFFSET_SHIFT_tcon10_hoffset_shift_thd_mask                (0x0003FFC0)
#define  TCON_TCON10_H_OFFSET_SHIFT_tcon10_hoffset_shift_value_mask              (0x0000003F)
#define  TCON_TCON10_H_OFFSET_SHIFT_tcon10_hoffset_shift_en(data)                (0x00040000&((data)<<18))
#define  TCON_TCON10_H_OFFSET_SHIFT_tcon10_hoffset_shift_thd(data)               (0x0003FFC0&((data)<<6))
#define  TCON_TCON10_H_OFFSET_SHIFT_tcon10_hoffset_shift_value(data)             (0x0000003F&(data))
#define  TCON_TCON10_H_OFFSET_SHIFT_get_tcon10_hoffset_shift_en(data)            ((0x00040000&(data))>>18)
#define  TCON_TCON10_H_OFFSET_SHIFT_get_tcon10_hoffset_shift_thd(data)           ((0x0003FFC0&(data))>>6)
#define  TCON_TCON10_H_OFFSET_SHIFT_get_tcon10_hoffset_shift_value(data)         (0x0000003F&(data))

#define  TCON_Double_Buffer_CTRL1                                                0x1802D33C
#define  TCON_Double_Buffer_CTRL1_reg_addr                                       "0xB802D33C"
#define  TCON_Double_Buffer_CTRL1_reg                                            0xB802D33C
#define  TCON_Double_Buffer_CTRL1_inst_addr                                      "0x004F"
#define  set_TCON_Double_Buffer_CTRL1_reg(data)                                  (*((volatile unsigned int*)TCON_Double_Buffer_CTRL1_reg)=data)
#define  get_TCON_Double_Buffer_CTRL1_reg                                        (*((volatile unsigned int*)TCON_Double_Buffer_CTRL1_reg))
#define  TCON_Double_Buffer_CTRL1_dreg_dbuf1_en_n_shift                          (2)
#define  TCON_Double_Buffer_CTRL1_dreg_dbuf1_read_sel_shift                      (1)
#define  TCON_Double_Buffer_CTRL1_dreg_dbuf1_set_shift                           (0)
#define  TCON_Double_Buffer_CTRL1_dreg_dbuf1_en_n_mask                           (0x00000004)
#define  TCON_Double_Buffer_CTRL1_dreg_dbuf1_read_sel_mask                       (0x00000002)
#define  TCON_Double_Buffer_CTRL1_dreg_dbuf1_set_mask                            (0x00000001)
#define  TCON_Double_Buffer_CTRL1_dreg_dbuf1_en_n(data)                          (0x00000004&((data)<<2))
#define  TCON_Double_Buffer_CTRL1_dreg_dbuf1_read_sel(data)                      (0x00000002&((data)<<1))
#define  TCON_Double_Buffer_CTRL1_dreg_dbuf1_set(data)                           (0x00000001&(data))
#define  TCON_Double_Buffer_CTRL1_get_dreg_dbuf1_en_n(data)                      ((0x00000004&(data))>>2)
#define  TCON_Double_Buffer_CTRL1_get_dreg_dbuf1_read_sel(data)                  ((0x00000002&(data))>>1)
#define  TCON_Double_Buffer_CTRL1_get_dreg_dbuf1_set(data)                       (0x00000001&(data))

#define  TCON_TCON11_HSE                                                         0x1802D340
#define  TCON_TCON11_HSE_reg_addr                                                "0xB802D340"
#define  TCON_TCON11_HSE_reg                                                     0xB802D340
#define  TCON_TCON11_HSE_inst_addr                                               "0x0050"
#define  set_TCON_TCON11_HSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON11_HSE_reg)=data)
#define  get_TCON_TCON11_HSE_reg                                                 (*((volatile unsigned int*)TCON_TCON11_HSE_reg))
#define  TCON_TCON11_HSE_dummy_11_shift                                          (29)
#define  TCON_TCON11_HSE_tcon11_hstart_shift                                     (16)
#define  TCON_TCON11_HSE_tcon11_hend_shift                                       (0)
#define  TCON_TCON11_HSE_dummy_11_mask                                           (0xE0000000)
#define  TCON_TCON11_HSE_tcon11_hstart_mask                                      (0x1FFF0000)
#define  TCON_TCON11_HSE_tcon11_hend_mask                                        (0x00001FFF)
#define  TCON_TCON11_HSE_dummy_11(data)                                          (0xE0000000&((data)<<29))
#define  TCON_TCON11_HSE_tcon11_hstart(data)                                     (0x1FFF0000&((data)<<16))
#define  TCON_TCON11_HSE_tcon11_hend(data)                                       (0x00001FFF&(data))
#define  TCON_TCON11_HSE_get_dummy_11(data)                                      ((0xE0000000&(data))>>29)
#define  TCON_TCON11_HSE_get_tcon11_hstart(data)                                 ((0x1FFF0000&(data))>>16)
#define  TCON_TCON11_HSE_get_tcon11_hend(data)                                   (0x00001FFF&(data))

#define  TCON_TCON11_VSE                                                         0x1802D344
#define  TCON_TCON11_VSE_reg_addr                                                "0xB802D344"
#define  TCON_TCON11_VSE_reg                                                     0xB802D344
#define  TCON_TCON11_VSE_inst_addr                                               "0x0051"
#define  set_TCON_TCON11_VSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON11_VSE_reg)=data)
#define  get_TCON_TCON11_VSE_reg                                                 (*((volatile unsigned int*)TCON_TCON11_VSE_reg))
#define  TCON_TCON11_VSE_tcon11_vstart_shift                                     (16)
#define  TCON_TCON11_VSE_tcon11_vend_shift                                       (0)
#define  TCON_TCON11_VSE_tcon11_vstart_mask                                      (0x0FFF0000)
#define  TCON_TCON11_VSE_tcon11_vend_mask                                        (0x00000FFF)
#define  TCON_TCON11_VSE_tcon11_vstart(data)                                     (0x0FFF0000&((data)<<16))
#define  TCON_TCON11_VSE_tcon11_vend(data)                                       (0x00000FFF&(data))
#define  TCON_TCON11_VSE_get_tcon11_vstart(data)                                 ((0x0FFF0000&(data))>>16)
#define  TCON_TCON11_VSE_get_tcon11_vend(data)                                   (0x00000FFF&(data))

#define  TCON_TCON11_Ctrl                                                        0x1802D348
#define  TCON_TCON11_Ctrl_reg_addr                                               "0xB802D348"
#define  TCON_TCON11_Ctrl_reg                                                    0xB802D348
#define  TCON_TCON11_Ctrl_inst_addr                                              "0x0052"
#define  set_TCON_TCON11_Ctrl_reg(data)                                          (*((volatile unsigned int*)TCON_TCON11_Ctrl_reg)=data)
#define  get_TCON_TCON11_Ctrl_reg                                                (*((volatile unsigned int*)TCON_TCON11_Ctrl_reg))
#define  TCON_TCON11_Ctrl_tcon11_l_flag_sel_shift                                (13)
#define  TCON_TCON11_Ctrl_tcon11_across_ctrl3_reset_shift                        (11)
#define  TCON_TCON11_Ctrl_tcon11_mode_shift                                      (8)
#define  TCON_TCON11_Ctrl_tcon11_en_shift                                        (7)
#define  TCON_TCON11_Ctrl_tcon11_inv_shift                                       (6)
#define  TCON_TCON11_Ctrl_tcon11_frame_tog_en_shift                              (3)
#define  TCON_TCON11_Ctrl_tcon11_comb_shift                                      (0)
#define  TCON_TCON11_Ctrl_tcon11_l_flag_sel_mask                                 (0x0003E000)
#define  TCON_TCON11_Ctrl_tcon11_across_ctrl3_reset_mask                         (0x00000800)
#define  TCON_TCON11_Ctrl_tcon11_mode_mask                                       (0x00000700)
#define  TCON_TCON11_Ctrl_tcon11_en_mask                                         (0x00000080)
#define  TCON_TCON11_Ctrl_tcon11_inv_mask                                        (0x00000040)
#define  TCON_TCON11_Ctrl_tcon11_frame_tog_en_mask                               (0x00000008)
#define  TCON_TCON11_Ctrl_tcon11_comb_mask                                       (0x00000007)
#define  TCON_TCON11_Ctrl_tcon11_l_flag_sel(data)                                (0x0003E000&((data)<<13))
#define  TCON_TCON11_Ctrl_tcon11_across_ctrl3_reset(data)                        (0x00000800&((data)<<11))
#define  TCON_TCON11_Ctrl_tcon11_mode(data)                                      (0x00000700&((data)<<8))
#define  TCON_TCON11_Ctrl_tcon11_en(data)                                        (0x00000080&((data)<<7))
#define  TCON_TCON11_Ctrl_tcon11_inv(data)                                       (0x00000040&((data)<<6))
#define  TCON_TCON11_Ctrl_tcon11_frame_tog_en(data)                              (0x00000008&((data)<<3))
#define  TCON_TCON11_Ctrl_tcon11_comb(data)                                      (0x00000007&(data))
#define  TCON_TCON11_Ctrl_get_tcon11_l_flag_sel(data)                            ((0x0003E000&(data))>>13)
#define  TCON_TCON11_Ctrl_get_tcon11_across_ctrl3_reset(data)                    ((0x00000800&(data))>>11)
#define  TCON_TCON11_Ctrl_get_tcon11_mode(data)                                  ((0x00000700&(data))>>8)
#define  TCON_TCON11_Ctrl_get_tcon11_en(data)                                    ((0x00000080&(data))>>7)
#define  TCON_TCON11_Ctrl_get_tcon11_inv(data)                                   ((0x00000040&(data))>>6)
#define  TCON_TCON11_Ctrl_get_tcon11_frame_tog_en(data)                          ((0x00000008&(data))>>3)
#define  TCON_TCON11_Ctrl_get_tcon11_comb(data)                                  (0x00000007&(data))

#define  TCON_TCON11_ACROSS_LINE_CONTROL3                                        0x1802D34C
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_reg_addr                               "0xB802D34C"
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_reg                                    0xB802D34C
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_inst_addr                              "0x0053"
#define  set_TCON_TCON11_ACROSS_LINE_CONTROL3_reg(data)                          (*((volatile unsigned int*)TCON_TCON11_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON11_ACROSS_LINE_CONTROL3_reg                                (*((volatile unsigned int*)TCON_TCON11_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_across_frame_int_shift          (28)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_across_ctrl3_rp_shift           (16)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_frame_hl_num_shift              (12)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_across_ctrl3_hp_shift           (0)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_across_frame_int_mask           (0x10000000)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_across_ctrl3_rp_mask            (0x0FFF0000)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_frame_hl_num_mask               (0x0000F000)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_across_ctrl3_hp_mask            (0x00000FFF)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_across_frame_int(data)          (0x10000000&((data)<<28))
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_across_ctrl3_rp(data)           (0x0FFF0000&((data)<<16))
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_frame_hl_num(data)              (0x0000F000&((data)<<12))
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_tcon11_across_ctrl3_hp(data)           (0x00000FFF&(data))
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_get_tcon11_across_frame_int(data)      ((0x10000000&(data))>>28)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_get_tcon11_across_ctrl3_rp(data)       ((0x0FFF0000&(data))>>16)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_get_tcon11_frame_hl_num(data)          ((0x0000F000&(data))>>12)
#define  TCON_TCON11_ACROSS_LINE_CONTROL3_get_tcon11_across_ctrl3_hp(data)       (0x00000FFF&(data))

#define  TCON_TCON11_ACROSS_FRAME_CONTROL                                        0x1802D350
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_reg_addr                               "0xB802D350"
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_reg                                    0xB802D350
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_inst_addr                              "0x0054"
#define  set_TCON_TCON11_ACROSS_FRAME_CONTROL_reg(data)                          (*((volatile unsigned int*)TCON_TCON11_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON11_ACROSS_FRAME_CONTROL_reg                                (*((volatile unsigned int*)TCON_TCON11_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_tcon11_frame_offset_shift              (16)
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_tcon11_frame_period_shift              (0)
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_tcon11_frame_offset_mask               (0x0FFF0000)
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_tcon11_frame_period_mask               (0x00000FFF)
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_tcon11_frame_offset(data)              (0x0FFF0000&((data)<<16))
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_tcon11_frame_period(data)              (0x00000FFF&(data))
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_get_tcon11_frame_offset(data)          ((0x0FFF0000&(data))>>16)
#define  TCON_TCON11_ACROSS_FRAME_CONTROL_get_tcon11_frame_period(data)          (0x00000FFF&(data))

#define  TCON_TCON11_FRAME_HL_CONTROL                                            0x1802D354
#define  TCON_TCON11_FRAME_HL_CONTROL_reg_addr                                   "0xB802D354"
#define  TCON_TCON11_FRAME_HL_CONTROL_reg                                        0xB802D354
#define  TCON_TCON11_FRAME_HL_CONTROL_inst_addr                                  "0x0055"
#define  set_TCON_TCON11_FRAME_HL_CONTROL_reg(data)                              (*((volatile unsigned int*)TCON_TCON11_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON11_FRAME_HL_CONTROL_reg                                    (*((volatile unsigned int*)TCON_TCON11_FRAME_HL_CONTROL_reg))
#define  TCON_TCON11_FRAME_HL_CONTROL_tcon11_frame_hl_shift                      (16)
#define  TCON_TCON11_FRAME_HL_CONTROL_tcon11_l_flag_prime_shift                  (0)
#define  TCON_TCON11_FRAME_HL_CONTROL_tcon11_frame_hl_mask                       (0xFFFF0000)
#define  TCON_TCON11_FRAME_HL_CONTROL_tcon11_l_flag_prime_mask                   (0x0000FFFF)
#define  TCON_TCON11_FRAME_HL_CONTROL_tcon11_frame_hl(data)                      (0xFFFF0000&((data)<<16))
#define  TCON_TCON11_FRAME_HL_CONTROL_tcon11_l_flag_prime(data)                  (0x0000FFFF&(data))
#define  TCON_TCON11_FRAME_HL_CONTROL_get_tcon11_frame_hl(data)                  ((0xFFFF0000&(data))>>16)
#define  TCON_TCON11_FRAME_HL_CONTROL_get_tcon11_l_flag_prime(data)              (0x0000FFFF&(data))

#define  TCON_TCON11_H_OFFSET_SHIFT                                              0x1802D358
#define  TCON_TCON11_H_OFFSET_SHIFT_reg_addr                                     "0xB802D358"
#define  TCON_TCON11_H_OFFSET_SHIFT_reg                                          0xB802D358
#define  TCON_TCON11_H_OFFSET_SHIFT_inst_addr                                    "0x0056"
#define  set_TCON_TCON11_H_OFFSET_SHIFT_reg(data)                                (*((volatile unsigned int*)TCON_TCON11_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON11_H_OFFSET_SHIFT_reg                                      (*((volatile unsigned int*)TCON_TCON11_H_OFFSET_SHIFT_reg))
#define  TCON_TCON11_H_OFFSET_SHIFT_tcon11_hoffset_shift_en_shift                (18)
#define  TCON_TCON11_H_OFFSET_SHIFT_tcon11_hoffset_shift_thd_shift               (6)
#define  TCON_TCON11_H_OFFSET_SHIFT_tcon11_hoffset_shift_value_shift             (0)
#define  TCON_TCON11_H_OFFSET_SHIFT_tcon11_hoffset_shift_en_mask                 (0x00040000)
#define  TCON_TCON11_H_OFFSET_SHIFT_tcon11_hoffset_shift_thd_mask                (0x0003FFC0)
#define  TCON_TCON11_H_OFFSET_SHIFT_tcon11_hoffset_shift_value_mask              (0x0000003F)
#define  TCON_TCON11_H_OFFSET_SHIFT_tcon11_hoffset_shift_en(data)                (0x00040000&((data)<<18))
#define  TCON_TCON11_H_OFFSET_SHIFT_tcon11_hoffset_shift_thd(data)               (0x0003FFC0&((data)<<6))
#define  TCON_TCON11_H_OFFSET_SHIFT_tcon11_hoffset_shift_value(data)             (0x0000003F&(data))
#define  TCON_TCON11_H_OFFSET_SHIFT_get_tcon11_hoffset_shift_en(data)            ((0x00040000&(data))>>18)
#define  TCON_TCON11_H_OFFSET_SHIFT_get_tcon11_hoffset_shift_thd(data)           ((0x0003FFC0&(data))>>6)
#define  TCON_TCON11_H_OFFSET_SHIFT_get_tcon11_hoffset_shift_value(data)         (0x0000003F&(data))

#define  TCON_TCON12_HSE                                                         0x1802D35C
#define  TCON_TCON12_HSE_reg_addr                                                "0xB802D35C"
#define  TCON_TCON12_HSE_reg                                                     0xB802D35C
#define  TCON_TCON12_HSE_inst_addr                                               "0x0057"
#define  set_TCON_TCON12_HSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON12_HSE_reg)=data)
#define  get_TCON_TCON12_HSE_reg                                                 (*((volatile unsigned int*)TCON_TCON12_HSE_reg))
#define  TCON_TCON12_HSE_dummy_12_shift                                          (29)
#define  TCON_TCON12_HSE_tcon12_hstart_shift                                     (16)
#define  TCON_TCON12_HSE_tcon12_hend_shift                                       (0)
#define  TCON_TCON12_HSE_dummy_12_mask                                           (0xE0000000)
#define  TCON_TCON12_HSE_tcon12_hstart_mask                                      (0x1FFF0000)
#define  TCON_TCON12_HSE_tcon12_hend_mask                                        (0x00001FFF)
#define  TCON_TCON12_HSE_dummy_12(data)                                          (0xE0000000&((data)<<29))
#define  TCON_TCON12_HSE_tcon12_hstart(data)                                     (0x1FFF0000&((data)<<16))
#define  TCON_TCON12_HSE_tcon12_hend(data)                                       (0x00001FFF&(data))
#define  TCON_TCON12_HSE_get_dummy_12(data)                                      ((0xE0000000&(data))>>29)
#define  TCON_TCON12_HSE_get_tcon12_hstart(data)                                 ((0x1FFF0000&(data))>>16)
#define  TCON_TCON12_HSE_get_tcon12_hend(data)                                   (0x00001FFF&(data))

#define  TCON_TCON12_VSE                                                         0x1802D360
#define  TCON_TCON12_VSE_reg_addr                                                "0xB802D360"
#define  TCON_TCON12_VSE_reg                                                     0xB802D360
#define  TCON_TCON12_VSE_inst_addr                                               "0x0058"
#define  set_TCON_TCON12_VSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON12_VSE_reg)=data)
#define  get_TCON_TCON12_VSE_reg                                                 (*((volatile unsigned int*)TCON_TCON12_VSE_reg))
#define  TCON_TCON12_VSE_tcon12_vstart_shift                                     (16)
#define  TCON_TCON12_VSE_tcon12_vend_shift                                       (0)
#define  TCON_TCON12_VSE_tcon12_vstart_mask                                      (0x0FFF0000)
#define  TCON_TCON12_VSE_tcon12_vend_mask                                        (0x00000FFF)
#define  TCON_TCON12_VSE_tcon12_vstart(data)                                     (0x0FFF0000&((data)<<16))
#define  TCON_TCON12_VSE_tcon12_vend(data)                                       (0x00000FFF&(data))
#define  TCON_TCON12_VSE_get_tcon12_vstart(data)                                 ((0x0FFF0000&(data))>>16)
#define  TCON_TCON12_VSE_get_tcon12_vend(data)                                   (0x00000FFF&(data))

#define  TCON_TCON12_Ctrl                                                        0x1802D364
#define  TCON_TCON12_Ctrl_reg_addr                                               "0xB802D364"
#define  TCON_TCON12_Ctrl_reg                                                    0xB802D364
#define  TCON_TCON12_Ctrl_inst_addr                                              "0x0059"
#define  set_TCON_TCON12_Ctrl_reg(data)                                          (*((volatile unsigned int*)TCON_TCON12_Ctrl_reg)=data)
#define  get_TCON_TCON12_Ctrl_reg                                                (*((volatile unsigned int*)TCON_TCON12_Ctrl_reg))
#define  TCON_TCON12_Ctrl_tcon12_l_flag_sel_shift                                (13)
#define  TCON_TCON12_Ctrl_tcon12_across_ctrl3_reset_shift                        (11)
#define  TCON_TCON12_Ctrl_tcon12_mode_shift                                      (8)
#define  TCON_TCON12_Ctrl_tcon12_en_shift                                        (7)
#define  TCON_TCON12_Ctrl_tcon12_inv_shift                                       (6)
#define  TCON_TCON12_Ctrl_tcon12_frame_tog_en_shift                              (3)
#define  TCON_TCON12_Ctrl_tcon12_comb_shift                                      (0)
#define  TCON_TCON12_Ctrl_tcon12_l_flag_sel_mask                                 (0x0003E000)
#define  TCON_TCON12_Ctrl_tcon12_across_ctrl3_reset_mask                         (0x00000800)
#define  TCON_TCON12_Ctrl_tcon12_mode_mask                                       (0x00000700)
#define  TCON_TCON12_Ctrl_tcon12_en_mask                                         (0x00000080)
#define  TCON_TCON12_Ctrl_tcon12_inv_mask                                        (0x00000040)
#define  TCON_TCON12_Ctrl_tcon12_frame_tog_en_mask                               (0x00000008)
#define  TCON_TCON12_Ctrl_tcon12_comb_mask                                       (0x00000007)
#define  TCON_TCON12_Ctrl_tcon12_l_flag_sel(data)                                (0x0003E000&((data)<<13))
#define  TCON_TCON12_Ctrl_tcon12_across_ctrl3_reset(data)                        (0x00000800&((data)<<11))
#define  TCON_TCON12_Ctrl_tcon12_mode(data)                                      (0x00000700&((data)<<8))
#define  TCON_TCON12_Ctrl_tcon12_en(data)                                        (0x00000080&((data)<<7))
#define  TCON_TCON12_Ctrl_tcon12_inv(data)                                       (0x00000040&((data)<<6))
#define  TCON_TCON12_Ctrl_tcon12_frame_tog_en(data)                              (0x00000008&((data)<<3))
#define  TCON_TCON12_Ctrl_tcon12_comb(data)                                      (0x00000007&(data))
#define  TCON_TCON12_Ctrl_get_tcon12_l_flag_sel(data)                            ((0x0003E000&(data))>>13)
#define  TCON_TCON12_Ctrl_get_tcon12_across_ctrl3_reset(data)                    ((0x00000800&(data))>>11)
#define  TCON_TCON12_Ctrl_get_tcon12_mode(data)                                  ((0x00000700&(data))>>8)
#define  TCON_TCON12_Ctrl_get_tcon12_en(data)                                    ((0x00000080&(data))>>7)
#define  TCON_TCON12_Ctrl_get_tcon12_inv(data)                                   ((0x00000040&(data))>>6)
#define  TCON_TCON12_Ctrl_get_tcon12_frame_tog_en(data)                          ((0x00000008&(data))>>3)
#define  TCON_TCON12_Ctrl_get_tcon12_comb(data)                                  (0x00000007&(data))

#define  TCON_TCON12_ACROSS_LINE_CONTROL3                                        0x1802D368
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_reg_addr                               "0xB802D368"
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_reg                                    0xB802D368
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_inst_addr                              "0x005A"
#define  set_TCON_TCON12_ACROSS_LINE_CONTROL3_reg(data)                          (*((volatile unsigned int*)TCON_TCON12_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON12_ACROSS_LINE_CONTROL3_reg                                (*((volatile unsigned int*)TCON_TCON12_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_across_frame_int_shift          (28)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_across_ctrl3_rp_shift           (16)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_frame_hl_num_shift              (12)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_across_ctrl3_hp_shift           (0)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_across_frame_int_mask           (0x10000000)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_across_ctrl3_rp_mask            (0x0FFF0000)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_frame_hl_num_mask               (0x0000F000)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_across_ctrl3_hp_mask            (0x00000FFF)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_across_frame_int(data)          (0x10000000&((data)<<28))
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_across_ctrl3_rp(data)           (0x0FFF0000&((data)<<16))
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_frame_hl_num(data)              (0x0000F000&((data)<<12))
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_tcon12_across_ctrl3_hp(data)           (0x00000FFF&(data))
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_get_tcon12_across_frame_int(data)      ((0x10000000&(data))>>28)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_get_tcon12_across_ctrl3_rp(data)       ((0x0FFF0000&(data))>>16)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_get_tcon12_frame_hl_num(data)          ((0x0000F000&(data))>>12)
#define  TCON_TCON12_ACROSS_LINE_CONTROL3_get_tcon12_across_ctrl3_hp(data)       (0x00000FFF&(data))

#define  TCON_TCON12_ACROSS_FRAME_CONTROL                                        0x1802D36C
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_reg_addr                               "0xB802D36C"
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_reg                                    0xB802D36C
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_inst_addr                              "0x005B"
#define  set_TCON_TCON12_ACROSS_FRAME_CONTROL_reg(data)                          (*((volatile unsigned int*)TCON_TCON12_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON12_ACROSS_FRAME_CONTROL_reg                                (*((volatile unsigned int*)TCON_TCON12_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_tcon12_frame_offset_shift              (16)
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_tcon12_frame_period_shift              (0)
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_tcon12_frame_offset_mask               (0x0FFF0000)
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_tcon12_frame_period_mask               (0x00000FFF)
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_tcon12_frame_offset(data)              (0x0FFF0000&((data)<<16))
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_tcon12_frame_period(data)              (0x00000FFF&(data))
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_get_tcon12_frame_offset(data)          ((0x0FFF0000&(data))>>16)
#define  TCON_TCON12_ACROSS_FRAME_CONTROL_get_tcon12_frame_period(data)          (0x00000FFF&(data))

#define  TCON_TCON12_FRAME_HL_CONTROL                                            0x1802D370
#define  TCON_TCON12_FRAME_HL_CONTROL_reg_addr                                   "0xB802D370"
#define  TCON_TCON12_FRAME_HL_CONTROL_reg                                        0xB802D370
#define  TCON_TCON12_FRAME_HL_CONTROL_inst_addr                                  "0x005C"
#define  set_TCON_TCON12_FRAME_HL_CONTROL_reg(data)                              (*((volatile unsigned int*)TCON_TCON12_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON12_FRAME_HL_CONTROL_reg                                    (*((volatile unsigned int*)TCON_TCON12_FRAME_HL_CONTROL_reg))
#define  TCON_TCON12_FRAME_HL_CONTROL_tcon12_frame_hl_shift                      (16)
#define  TCON_TCON12_FRAME_HL_CONTROL_tcon12_l_flag_prime_shift                  (0)
#define  TCON_TCON12_FRAME_HL_CONTROL_tcon12_frame_hl_mask                       (0xFFFF0000)
#define  TCON_TCON12_FRAME_HL_CONTROL_tcon12_l_flag_prime_mask                   (0x0000FFFF)
#define  TCON_TCON12_FRAME_HL_CONTROL_tcon12_frame_hl(data)                      (0xFFFF0000&((data)<<16))
#define  TCON_TCON12_FRAME_HL_CONTROL_tcon12_l_flag_prime(data)                  (0x0000FFFF&(data))
#define  TCON_TCON12_FRAME_HL_CONTROL_get_tcon12_frame_hl(data)                  ((0xFFFF0000&(data))>>16)
#define  TCON_TCON12_FRAME_HL_CONTROL_get_tcon12_l_flag_prime(data)              (0x0000FFFF&(data))

#define  TCON_TCON12_H_OFFSET_SHIFT                                              0x1802D374
#define  TCON_TCON12_H_OFFSET_SHIFT_reg_addr                                     "0xB802D374"
#define  TCON_TCON12_H_OFFSET_SHIFT_reg                                          0xB802D374
#define  TCON_TCON12_H_OFFSET_SHIFT_inst_addr                                    "0x005D"
#define  set_TCON_TCON12_H_OFFSET_SHIFT_reg(data)                                (*((volatile unsigned int*)TCON_TCON12_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON12_H_OFFSET_SHIFT_reg                                      (*((volatile unsigned int*)TCON_TCON12_H_OFFSET_SHIFT_reg))
#define  TCON_TCON12_H_OFFSET_SHIFT_tcon12_hoffset_shift_en_shift                (18)
#define  TCON_TCON12_H_OFFSET_SHIFT_tcon12_hoffset_shift_thd_shift               (6)
#define  TCON_TCON12_H_OFFSET_SHIFT_tcon12_hoffset_shift_value_shift             (0)
#define  TCON_TCON12_H_OFFSET_SHIFT_tcon12_hoffset_shift_en_mask                 (0x00040000)
#define  TCON_TCON12_H_OFFSET_SHIFT_tcon12_hoffset_shift_thd_mask                (0x0003FFC0)
#define  TCON_TCON12_H_OFFSET_SHIFT_tcon12_hoffset_shift_value_mask              (0x0000003F)
#define  TCON_TCON12_H_OFFSET_SHIFT_tcon12_hoffset_shift_en(data)                (0x00040000&((data)<<18))
#define  TCON_TCON12_H_OFFSET_SHIFT_tcon12_hoffset_shift_thd(data)               (0x0003FFC0&((data)<<6))
#define  TCON_TCON12_H_OFFSET_SHIFT_tcon12_hoffset_shift_value(data)             (0x0000003F&(data))
#define  TCON_TCON12_H_OFFSET_SHIFT_get_tcon12_hoffset_shift_en(data)            ((0x00040000&(data))>>18)
#define  TCON_TCON12_H_OFFSET_SHIFT_get_tcon12_hoffset_shift_thd(data)           ((0x0003FFC0&(data))>>6)
#define  TCON_TCON12_H_OFFSET_SHIFT_get_tcon12_hoffset_shift_value(data)         (0x0000003F&(data))

#define  TCON_Double_Buffer_CTRL2                                                0x1802D378
#define  TCON_Double_Buffer_CTRL2_reg_addr                                       "0xB802D378"
#define  TCON_Double_Buffer_CTRL2_reg                                            0xB802D378
#define  TCON_Double_Buffer_CTRL2_inst_addr                                      "0x005E"
#define  set_TCON_Double_Buffer_CTRL2_reg(data)                                  (*((volatile unsigned int*)TCON_Double_Buffer_CTRL2_reg)=data)
#define  get_TCON_Double_Buffer_CTRL2_reg                                        (*((volatile unsigned int*)TCON_Double_Buffer_CTRL2_reg))
#define  TCON_Double_Buffer_CTRL2_dreg_dbuf2_en_n_shift                          (2)
#define  TCON_Double_Buffer_CTRL2_dreg_dbuf2_read_sel_shift                      (1)
#define  TCON_Double_Buffer_CTRL2_dreg_dbuf2_set_shift                           (0)
#define  TCON_Double_Buffer_CTRL2_dreg_dbuf2_en_n_mask                           (0x00000004)
#define  TCON_Double_Buffer_CTRL2_dreg_dbuf2_read_sel_mask                       (0x00000002)
#define  TCON_Double_Buffer_CTRL2_dreg_dbuf2_set_mask                            (0x00000001)
#define  TCON_Double_Buffer_CTRL2_dreg_dbuf2_en_n(data)                          (0x00000004&((data)<<2))
#define  TCON_Double_Buffer_CTRL2_dreg_dbuf2_read_sel(data)                      (0x00000002&((data)<<1))
#define  TCON_Double_Buffer_CTRL2_dreg_dbuf2_set(data)                           (0x00000001&(data))
#define  TCON_Double_Buffer_CTRL2_get_dreg_dbuf2_en_n(data)                      ((0x00000004&(data))>>2)
#define  TCON_Double_Buffer_CTRL2_get_dreg_dbuf2_read_sel(data)                  ((0x00000002&(data))>>1)
#define  TCON_Double_Buffer_CTRL2_get_dreg_dbuf2_set(data)                       (0x00000001&(data))

#define  TCON_TCON13_HSE                                                         0x1802D37C
#define  TCON_TCON13_HSE_reg_addr                                                "0xB802D37C"
#define  TCON_TCON13_HSE_reg                                                     0xB802D37C
#define  TCON_TCON13_HSE_inst_addr                                               "0x005F"
#define  set_TCON_TCON13_HSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON13_HSE_reg)=data)
#define  get_TCON_TCON13_HSE_reg                                                 (*((volatile unsigned int*)TCON_TCON13_HSE_reg))
#define  TCON_TCON13_HSE_dummy_13_shift                                          (29)
#define  TCON_TCON13_HSE_tcon13_hstart_shift                                     (16)
#define  TCON_TCON13_HSE_tcon13_hend_shift                                       (0)
#define  TCON_TCON13_HSE_dummy_13_mask                                           (0xE0000000)
#define  TCON_TCON13_HSE_tcon13_hstart_mask                                      (0x1FFF0000)
#define  TCON_TCON13_HSE_tcon13_hend_mask                                        (0x00001FFF)
#define  TCON_TCON13_HSE_dummy_13(data)                                          (0xE0000000&((data)<<29))
#define  TCON_TCON13_HSE_tcon13_hstart(data)                                     (0x1FFF0000&((data)<<16))
#define  TCON_TCON13_HSE_tcon13_hend(data)                                       (0x00001FFF&(data))
#define  TCON_TCON13_HSE_get_dummy_13(data)                                      ((0xE0000000&(data))>>29)
#define  TCON_TCON13_HSE_get_tcon13_hstart(data)                                 ((0x1FFF0000&(data))>>16)
#define  TCON_TCON13_HSE_get_tcon13_hend(data)                                   (0x00001FFF&(data))

#define  TCON_TCON13_VSE                                                         0x1802D380
#define  TCON_TCON13_VSE_reg_addr                                                "0xB802D380"
#define  TCON_TCON13_VSE_reg                                                     0xB802D380
#define  TCON_TCON13_VSE_inst_addr                                               "0x0060"
#define  set_TCON_TCON13_VSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON13_VSE_reg)=data)
#define  get_TCON_TCON13_VSE_reg                                                 (*((volatile unsigned int*)TCON_TCON13_VSE_reg))
#define  TCON_TCON13_VSE_tcon13_vstart_shift                                     (16)
#define  TCON_TCON13_VSE_tcon13_vend_shift                                       (0)
#define  TCON_TCON13_VSE_tcon13_vstart_mask                                      (0x0FFF0000)
#define  TCON_TCON13_VSE_tcon13_vend_mask                                        (0x00000FFF)
#define  TCON_TCON13_VSE_tcon13_vstart(data)                                     (0x0FFF0000&((data)<<16))
#define  TCON_TCON13_VSE_tcon13_vend(data)                                       (0x00000FFF&(data))
#define  TCON_TCON13_VSE_get_tcon13_vstart(data)                                 ((0x0FFF0000&(data))>>16)
#define  TCON_TCON13_VSE_get_tcon13_vend(data)                                   (0x00000FFF&(data))

#define  TCON_TCON13_Ctrl                                                        0x1802D384
#define  TCON_TCON13_Ctrl_reg_addr                                               "0xB802D384"
#define  TCON_TCON13_Ctrl_reg                                                    0xB802D384
#define  TCON_TCON13_Ctrl_inst_addr                                              "0x0061"
#define  set_TCON_TCON13_Ctrl_reg(data)                                          (*((volatile unsigned int*)TCON_TCON13_Ctrl_reg)=data)
#define  get_TCON_TCON13_Ctrl_reg                                                (*((volatile unsigned int*)TCON_TCON13_Ctrl_reg))
#define  TCON_TCON13_Ctrl_tcon13_l_flag_sel_shift                                (13)
#define  TCON_TCON13_Ctrl_tcon13_across_ctrl3_reset_shift                        (11)
#define  TCON_TCON13_Ctrl_tcon13_mode_shift                                      (8)
#define  TCON_TCON13_Ctrl_tcon13_en_shift                                        (7)
#define  TCON_TCON13_Ctrl_tcon13_inv_shift                                       (6)
#define  TCON_TCON13_Ctrl_tcon13_frame_tog_en_shift                              (3)
#define  TCON_TCON13_Ctrl_tcon13_comb_shift                                      (0)
#define  TCON_TCON13_Ctrl_tcon13_l_flag_sel_mask                                 (0x0003E000)
#define  TCON_TCON13_Ctrl_tcon13_across_ctrl3_reset_mask                         (0x00000800)
#define  TCON_TCON13_Ctrl_tcon13_mode_mask                                       (0x00000700)
#define  TCON_TCON13_Ctrl_tcon13_en_mask                                         (0x00000080)
#define  TCON_TCON13_Ctrl_tcon13_inv_mask                                        (0x00000040)
#define  TCON_TCON13_Ctrl_tcon13_frame_tog_en_mask                               (0x00000008)
#define  TCON_TCON13_Ctrl_tcon13_comb_mask                                       (0x00000007)
#define  TCON_TCON13_Ctrl_tcon13_l_flag_sel(data)                                (0x0003E000&((data)<<13))
#define  TCON_TCON13_Ctrl_tcon13_across_ctrl3_reset(data)                        (0x00000800&((data)<<11))
#define  TCON_TCON13_Ctrl_tcon13_mode(data)                                      (0x00000700&((data)<<8))
#define  TCON_TCON13_Ctrl_tcon13_en(data)                                        (0x00000080&((data)<<7))
#define  TCON_TCON13_Ctrl_tcon13_inv(data)                                       (0x00000040&((data)<<6))
#define  TCON_TCON13_Ctrl_tcon13_frame_tog_en(data)                              (0x00000008&((data)<<3))
#define  TCON_TCON13_Ctrl_tcon13_comb(data)                                      (0x00000007&(data))
#define  TCON_TCON13_Ctrl_get_tcon13_l_flag_sel(data)                            ((0x0003E000&(data))>>13)
#define  TCON_TCON13_Ctrl_get_tcon13_across_ctrl3_reset(data)                    ((0x00000800&(data))>>11)
#define  TCON_TCON13_Ctrl_get_tcon13_mode(data)                                  ((0x00000700&(data))>>8)
#define  TCON_TCON13_Ctrl_get_tcon13_en(data)                                    ((0x00000080&(data))>>7)
#define  TCON_TCON13_Ctrl_get_tcon13_inv(data)                                   ((0x00000040&(data))>>6)
#define  TCON_TCON13_Ctrl_get_tcon13_frame_tog_en(data)                          ((0x00000008&(data))>>3)
#define  TCON_TCON13_Ctrl_get_tcon13_comb(data)                                  (0x00000007&(data))

#define  TCON_TCON13_ACROSS_LINE_CONTROL3                                        0x1802D388
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_reg_addr                               "0xB802D388"
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_reg                                    0xB802D388
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_inst_addr                              "0x0062"
#define  set_TCON_TCON13_ACROSS_LINE_CONTROL3_reg(data)                          (*((volatile unsigned int*)TCON_TCON13_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON13_ACROSS_LINE_CONTROL3_reg                                (*((volatile unsigned int*)TCON_TCON13_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_across_frame_int_shift          (28)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_across_ctrl3_rp_shift           (16)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_frame_hl_num_shift              (12)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_across_ctrl3_hp_shift           (0)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_across_frame_int_mask           (0x10000000)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_across_ctrl3_rp_mask            (0x0FFF0000)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_frame_hl_num_mask               (0x0000F000)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_across_ctrl3_hp_mask            (0x00000FFF)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_across_frame_int(data)          (0x10000000&((data)<<28))
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_across_ctrl3_rp(data)           (0x0FFF0000&((data)<<16))
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_frame_hl_num(data)              (0x0000F000&((data)<<12))
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_tcon13_across_ctrl3_hp(data)           (0x00000FFF&(data))
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_get_tcon13_across_frame_int(data)      ((0x10000000&(data))>>28)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_get_tcon13_across_ctrl3_rp(data)       ((0x0FFF0000&(data))>>16)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_get_tcon13_frame_hl_num(data)          ((0x0000F000&(data))>>12)
#define  TCON_TCON13_ACROSS_LINE_CONTROL3_get_tcon13_across_ctrl3_hp(data)       (0x00000FFF&(data))

#define  TCON_TCON13_ACROSS_FRAME_CONTROL                                        0x1802D38C
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_reg_addr                               "0xB802D38C"
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_reg                                    0xB802D38C
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_inst_addr                              "0x0063"
#define  set_TCON_TCON13_ACROSS_FRAME_CONTROL_reg(data)                          (*((volatile unsigned int*)TCON_TCON13_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON13_ACROSS_FRAME_CONTROL_reg                                (*((volatile unsigned int*)TCON_TCON13_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_tcon13_frame_offset_shift              (16)
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_tcon13_frame_period_shift              (0)
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_tcon13_frame_offset_mask               (0x0FFF0000)
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_tcon13_frame_period_mask               (0x00000FFF)
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_tcon13_frame_offset(data)              (0x0FFF0000&((data)<<16))
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_tcon13_frame_period(data)              (0x00000FFF&(data))
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_get_tcon13_frame_offset(data)          ((0x0FFF0000&(data))>>16)
#define  TCON_TCON13_ACROSS_FRAME_CONTROL_get_tcon13_frame_period(data)          (0x00000FFF&(data))

#define  TCON_TCON13_FRAME_HL_CONTROL                                            0x1802D390
#define  TCON_TCON13_FRAME_HL_CONTROL_reg_addr                                   "0xB802D390"
#define  TCON_TCON13_FRAME_HL_CONTROL_reg                                        0xB802D390
#define  TCON_TCON13_FRAME_HL_CONTROL_inst_addr                                  "0x0064"
#define  set_TCON_TCON13_FRAME_HL_CONTROL_reg(data)                              (*((volatile unsigned int*)TCON_TCON13_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON13_FRAME_HL_CONTROL_reg                                    (*((volatile unsigned int*)TCON_TCON13_FRAME_HL_CONTROL_reg))
#define  TCON_TCON13_FRAME_HL_CONTROL_tcon13_frame_hl_shift                      (16)
#define  TCON_TCON13_FRAME_HL_CONTROL_tcon13_l_flag_prime_shift                  (0)
#define  TCON_TCON13_FRAME_HL_CONTROL_tcon13_frame_hl_mask                       (0xFFFF0000)
#define  TCON_TCON13_FRAME_HL_CONTROL_tcon13_l_flag_prime_mask                   (0x0000FFFF)
#define  TCON_TCON13_FRAME_HL_CONTROL_tcon13_frame_hl(data)                      (0xFFFF0000&((data)<<16))
#define  TCON_TCON13_FRAME_HL_CONTROL_tcon13_l_flag_prime(data)                  (0x0000FFFF&(data))
#define  TCON_TCON13_FRAME_HL_CONTROL_get_tcon13_frame_hl(data)                  ((0xFFFF0000&(data))>>16)
#define  TCON_TCON13_FRAME_HL_CONTROL_get_tcon13_l_flag_prime(data)              (0x0000FFFF&(data))

#define  TCON_TCON13_H_OFFSET_SHIFT                                              0x1802D394
#define  TCON_TCON13_H_OFFSET_SHIFT_reg_addr                                     "0xB802D394"
#define  TCON_TCON13_H_OFFSET_SHIFT_reg                                          0xB802D394
#define  TCON_TCON13_H_OFFSET_SHIFT_inst_addr                                    "0x0065"
#define  set_TCON_TCON13_H_OFFSET_SHIFT_reg(data)                                (*((volatile unsigned int*)TCON_TCON13_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON13_H_OFFSET_SHIFT_reg                                      (*((volatile unsigned int*)TCON_TCON13_H_OFFSET_SHIFT_reg))
#define  TCON_TCON13_H_OFFSET_SHIFT_tcon13_hoffset_shift_en_shift                (18)
#define  TCON_TCON13_H_OFFSET_SHIFT_tcon13_hoffset_shift_thd_shift               (6)
#define  TCON_TCON13_H_OFFSET_SHIFT_tcon13_hoffset_shift_value_shift             (0)
#define  TCON_TCON13_H_OFFSET_SHIFT_tcon13_hoffset_shift_en_mask                 (0x00040000)
#define  TCON_TCON13_H_OFFSET_SHIFT_tcon13_hoffset_shift_thd_mask                (0x0003FFC0)
#define  TCON_TCON13_H_OFFSET_SHIFT_tcon13_hoffset_shift_value_mask              (0x0000003F)
#define  TCON_TCON13_H_OFFSET_SHIFT_tcon13_hoffset_shift_en(data)                (0x00040000&((data)<<18))
#define  TCON_TCON13_H_OFFSET_SHIFT_tcon13_hoffset_shift_thd(data)               (0x0003FFC0&((data)<<6))
#define  TCON_TCON13_H_OFFSET_SHIFT_tcon13_hoffset_shift_value(data)             (0x0000003F&(data))
#define  TCON_TCON13_H_OFFSET_SHIFT_get_tcon13_hoffset_shift_en(data)            ((0x00040000&(data))>>18)
#define  TCON_TCON13_H_OFFSET_SHIFT_get_tcon13_hoffset_shift_thd(data)           ((0x0003FFC0&(data))>>6)
#define  TCON_TCON13_H_OFFSET_SHIFT_get_tcon13_hoffset_shift_value(data)         (0x0000003F&(data))

#define  TCON_TCON14_HSE                                                         0x1802D398
#define  TCON_TCON14_HSE_reg_addr                                                "0xB802D398"
#define  TCON_TCON14_HSE_reg                                                     0xB802D398
#define  TCON_TCON14_HSE_inst_addr                                               "0x0066"
#define  set_TCON_TCON14_HSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON14_HSE_reg)=data)
#define  get_TCON_TCON14_HSE_reg                                                 (*((volatile unsigned int*)TCON_TCON14_HSE_reg))
#define  TCON_TCON14_HSE_dummy_14_shift                                          (29)
#define  TCON_TCON14_HSE_tcon14_hstart_shift                                     (16)
#define  TCON_TCON14_HSE_tcon14_hend_shift                                       (0)
#define  TCON_TCON14_HSE_dummy_14_mask                                           (0xE0000000)
#define  TCON_TCON14_HSE_tcon14_hstart_mask                                      (0x1FFF0000)
#define  TCON_TCON14_HSE_tcon14_hend_mask                                        (0x00001FFF)
#define  TCON_TCON14_HSE_dummy_14(data)                                          (0xE0000000&((data)<<29))
#define  TCON_TCON14_HSE_tcon14_hstart(data)                                     (0x1FFF0000&((data)<<16))
#define  TCON_TCON14_HSE_tcon14_hend(data)                                       (0x00001FFF&(data))
#define  TCON_TCON14_HSE_get_dummy_14(data)                                      ((0xE0000000&(data))>>29)
#define  TCON_TCON14_HSE_get_tcon14_hstart(data)                                 ((0x1FFF0000&(data))>>16)
#define  TCON_TCON14_HSE_get_tcon14_hend(data)                                   (0x00001FFF&(data))

#define  TCON_TCON14_VSE                                                         0x1802D39C
#define  TCON_TCON14_VSE_reg_addr                                                "0xB802D39C"
#define  TCON_TCON14_VSE_reg                                                     0xB802D39C
#define  TCON_TCON14_VSE_inst_addr                                               "0x0067"
#define  set_TCON_TCON14_VSE_reg(data)                                           (*((volatile unsigned int*)TCON_TCON14_VSE_reg)=data)
#define  get_TCON_TCON14_VSE_reg                                                 (*((volatile unsigned int*)TCON_TCON14_VSE_reg))
#define  TCON_TCON14_VSE_tcon14_vstart_shift                                     (16)
#define  TCON_TCON14_VSE_tcon14_vend_shift                                       (0)
#define  TCON_TCON14_VSE_tcon14_vstart_mask                                      (0x0FFF0000)
#define  TCON_TCON14_VSE_tcon14_vend_mask                                        (0x00000FFF)
#define  TCON_TCON14_VSE_tcon14_vstart(data)                                     (0x0FFF0000&((data)<<16))
#define  TCON_TCON14_VSE_tcon14_vend(data)                                       (0x00000FFF&(data))
#define  TCON_TCON14_VSE_get_tcon14_vstart(data)                                 ((0x0FFF0000&(data))>>16)
#define  TCON_TCON14_VSE_get_tcon14_vend(data)                                   (0x00000FFF&(data))

#define  TCON_TCON14_Ctrl                                                        0x1802D3A0
#define  TCON_TCON14_Ctrl_reg_addr                                               "0xB802D3A0"
#define  TCON_TCON14_Ctrl_reg                                                    0xB802D3A0
#define  TCON_TCON14_Ctrl_inst_addr                                              "0x0068"
#define  set_TCON_TCON14_Ctrl_reg(data)                                          (*((volatile unsigned int*)TCON_TCON14_Ctrl_reg)=data)
#define  get_TCON_TCON14_Ctrl_reg                                                (*((volatile unsigned int*)TCON_TCON14_Ctrl_reg))
#define  TCON_TCON14_Ctrl_tcon14_l_flag_sel_shift                                (13)
#define  TCON_TCON14_Ctrl_tcon14_across_ctrl3_reset_shift                        (11)
#define  TCON_TCON14_Ctrl_tcon14_mode_shift                                      (8)
#define  TCON_TCON14_Ctrl_tcon14_en_shift                                        (7)
#define  TCON_TCON14_Ctrl_tcon14_inv_shift                                       (6)
#define  TCON_TCON14_Ctrl_tcon14_frame_tog_en_shift                              (3)
#define  TCON_TCON14_Ctrl_tcon14_comb_shift                                      (0)
#define  TCON_TCON14_Ctrl_tcon14_l_flag_sel_mask                                 (0x0003E000)
#define  TCON_TCON14_Ctrl_tcon14_across_ctrl3_reset_mask                         (0x00000800)
#define  TCON_TCON14_Ctrl_tcon14_mode_mask                                       (0x00000700)
#define  TCON_TCON14_Ctrl_tcon14_en_mask                                         (0x00000080)
#define  TCON_TCON14_Ctrl_tcon14_inv_mask                                        (0x00000040)
#define  TCON_TCON14_Ctrl_tcon14_frame_tog_en_mask                               (0x00000008)
#define  TCON_TCON14_Ctrl_tcon14_comb_mask                                       (0x00000007)
#define  TCON_TCON14_Ctrl_tcon14_l_flag_sel(data)                                (0x0003E000&((data)<<13))
#define  TCON_TCON14_Ctrl_tcon14_across_ctrl3_reset(data)                        (0x00000800&((data)<<11))
#define  TCON_TCON14_Ctrl_tcon14_mode(data)                                      (0x00000700&((data)<<8))
#define  TCON_TCON14_Ctrl_tcon14_en(data)                                        (0x00000080&((data)<<7))
#define  TCON_TCON14_Ctrl_tcon14_inv(data)                                       (0x00000040&((data)<<6))
#define  TCON_TCON14_Ctrl_tcon14_frame_tog_en(data)                              (0x00000008&((data)<<3))
#define  TCON_TCON14_Ctrl_tcon14_comb(data)                                      (0x00000007&(data))
#define  TCON_TCON14_Ctrl_get_tcon14_l_flag_sel(data)                            ((0x0003E000&(data))>>13)
#define  TCON_TCON14_Ctrl_get_tcon14_across_ctrl3_reset(data)                    ((0x00000800&(data))>>11)
#define  TCON_TCON14_Ctrl_get_tcon14_mode(data)                                  ((0x00000700&(data))>>8)
#define  TCON_TCON14_Ctrl_get_tcon14_en(data)                                    ((0x00000080&(data))>>7)
#define  TCON_TCON14_Ctrl_get_tcon14_inv(data)                                   ((0x00000040&(data))>>6)
#define  TCON_TCON14_Ctrl_get_tcon14_frame_tog_en(data)                          ((0x00000008&(data))>>3)
#define  TCON_TCON14_Ctrl_get_tcon14_comb(data)                                  (0x00000007&(data))

#define  TCON_TCON14_ACROSS_LINE_CONTROL3                                        0x1802D3A4
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_reg_addr                               "0xB802D3A4"
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_reg                                    0xB802D3A4
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_inst_addr                              "0x0069"
#define  set_TCON_TCON14_ACROSS_LINE_CONTROL3_reg(data)                          (*((volatile unsigned int*)TCON_TCON14_ACROSS_LINE_CONTROL3_reg)=data)
#define  get_TCON_TCON14_ACROSS_LINE_CONTROL3_reg                                (*((volatile unsigned int*)TCON_TCON14_ACROSS_LINE_CONTROL3_reg))
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_across_frame_int_shift          (28)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_across_ctrl3_rp_shift           (16)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_frame_hl_num_shift              (12)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_across_ctrl3_hp_shift           (0)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_across_frame_int_mask           (0x10000000)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_across_ctrl3_rp_mask            (0x0FFF0000)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_frame_hl_num_mask               (0x0000F000)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_across_ctrl3_hp_mask            (0x00000FFF)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_across_frame_int(data)          (0x10000000&((data)<<28))
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_across_ctrl3_rp(data)           (0x0FFF0000&((data)<<16))
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_frame_hl_num(data)              (0x0000F000&((data)<<12))
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_tcon14_across_ctrl3_hp(data)           (0x00000FFF&(data))
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_get_tcon14_across_frame_int(data)      ((0x10000000&(data))>>28)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_get_tcon14_across_ctrl3_rp(data)       ((0x0FFF0000&(data))>>16)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_get_tcon14_frame_hl_num(data)          ((0x0000F000&(data))>>12)
#define  TCON_TCON14_ACROSS_LINE_CONTROL3_get_tcon14_across_ctrl3_hp(data)       (0x00000FFF&(data))

#define  TCON_TCON14_ACROSS_FRAME_CONTROL                                        0x1802D3A8
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_reg_addr                               "0xB802D3A8"
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_reg                                    0xB802D3A8
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_inst_addr                              "0x006A"
#define  set_TCON_TCON14_ACROSS_FRAME_CONTROL_reg(data)                          (*((volatile unsigned int*)TCON_TCON14_ACROSS_FRAME_CONTROL_reg)=data)
#define  get_TCON_TCON14_ACROSS_FRAME_CONTROL_reg                                (*((volatile unsigned int*)TCON_TCON14_ACROSS_FRAME_CONTROL_reg))
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_tcon14_frame_offset_shift              (16)
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_tcon14_frame_period_shift              (0)
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_tcon14_frame_offset_mask               (0x0FFF0000)
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_tcon14_frame_period_mask               (0x00000FFF)
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_tcon14_frame_offset(data)              (0x0FFF0000&((data)<<16))
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_tcon14_frame_period(data)              (0x00000FFF&(data))
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_get_tcon14_frame_offset(data)          ((0x0FFF0000&(data))>>16)
#define  TCON_TCON14_ACROSS_FRAME_CONTROL_get_tcon14_frame_period(data)          (0x00000FFF&(data))

#define  TCON_TCON14_FRAME_HL_CONTROL                                            0x1802D3AC
#define  TCON_TCON14_FRAME_HL_CONTROL_reg_addr                                   "0xB802D3AC"
#define  TCON_TCON14_FRAME_HL_CONTROL_reg                                        0xB802D3AC
#define  TCON_TCON14_FRAME_HL_CONTROL_inst_addr                                  "0x006B"
#define  set_TCON_TCON14_FRAME_HL_CONTROL_reg(data)                              (*((volatile unsigned int*)TCON_TCON14_FRAME_HL_CONTROL_reg)=data)
#define  get_TCON_TCON14_FRAME_HL_CONTROL_reg                                    (*((volatile unsigned int*)TCON_TCON14_FRAME_HL_CONTROL_reg))
#define  TCON_TCON14_FRAME_HL_CONTROL_tcon14_frame_hl_shift                      (16)
#define  TCON_TCON14_FRAME_HL_CONTROL_tcon14_l_flag_prime_shift                  (0)
#define  TCON_TCON14_FRAME_HL_CONTROL_tcon14_frame_hl_mask                       (0xFFFF0000)
#define  TCON_TCON14_FRAME_HL_CONTROL_tcon14_l_flag_prime_mask                   (0x0000FFFF)
#define  TCON_TCON14_FRAME_HL_CONTROL_tcon14_frame_hl(data)                      (0xFFFF0000&((data)<<16))
#define  TCON_TCON14_FRAME_HL_CONTROL_tcon14_l_flag_prime(data)                  (0x0000FFFF&(data))
#define  TCON_TCON14_FRAME_HL_CONTROL_get_tcon14_frame_hl(data)                  ((0xFFFF0000&(data))>>16)
#define  TCON_TCON14_FRAME_HL_CONTROL_get_tcon14_l_flag_prime(data)              (0x0000FFFF&(data))

#define  TCON_TCON14_H_OFFSET_SHIFT                                              0x1802D3B0
#define  TCON_TCON14_H_OFFSET_SHIFT_reg_addr                                     "0xB802D3B0"
#define  TCON_TCON14_H_OFFSET_SHIFT_reg                                          0xB802D3B0
#define  TCON_TCON14_H_OFFSET_SHIFT_inst_addr                                    "0x006C"
#define  set_TCON_TCON14_H_OFFSET_SHIFT_reg(data)                                (*((volatile unsigned int*)TCON_TCON14_H_OFFSET_SHIFT_reg)=data)
#define  get_TCON_TCON14_H_OFFSET_SHIFT_reg                                      (*((volatile unsigned int*)TCON_TCON14_H_OFFSET_SHIFT_reg))
#define  TCON_TCON14_H_OFFSET_SHIFT_tcon14_hoffset_shift_en_shift                (18)
#define  TCON_TCON14_H_OFFSET_SHIFT_tcon14_hoffset_shift_thd_shift               (6)
#define  TCON_TCON14_H_OFFSET_SHIFT_tcon14_hoffset_shift_value_shift             (0)
#define  TCON_TCON14_H_OFFSET_SHIFT_tcon14_hoffset_shift_en_mask                 (0x00040000)
#define  TCON_TCON14_H_OFFSET_SHIFT_tcon14_hoffset_shift_thd_mask                (0x0003FFC0)
#define  TCON_TCON14_H_OFFSET_SHIFT_tcon14_hoffset_shift_value_mask              (0x0000003F)
#define  TCON_TCON14_H_OFFSET_SHIFT_tcon14_hoffset_shift_en(data)                (0x00040000&((data)<<18))
#define  TCON_TCON14_H_OFFSET_SHIFT_tcon14_hoffset_shift_thd(data)               (0x0003FFC0&((data)<<6))
#define  TCON_TCON14_H_OFFSET_SHIFT_tcon14_hoffset_shift_value(data)             (0x0000003F&(data))
#define  TCON_TCON14_H_OFFSET_SHIFT_get_tcon14_hoffset_shift_en(data)            ((0x00040000&(data))>>18)
#define  TCON_TCON14_H_OFFSET_SHIFT_get_tcon14_hoffset_shift_thd(data)           ((0x0003FFC0&(data))>>6)
#define  TCON_TCON14_H_OFFSET_SHIFT_get_tcon14_hoffset_shift_value(data)         (0x0000003F&(data))

#define  TCON_TCON0_NO_SSCG_CONTROL                                              0x1802D3B4
#define  TCON_TCON0_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3B4"
#define  TCON_TCON0_NO_SSCG_CONTROL_reg                                          0xB802D3B4
#define  TCON_TCON0_NO_SSCG_CONTROL_inst_addr                                    "0x006D"
#define  set_TCON_TCON0_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON0_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON0_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON0_NO_SSCG_CONTROL_reg))
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_nosscg_en_shift                        (23)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_sel_shift                              (22)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_no_sscg_inv_shift                      (21)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_last_trig_en_shift                     (20)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_no_sscg_mode_shift                     (19)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_no_sscg_ctl_shift                      (16)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_sel_mask                               (0x00400000)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON0_NO_SSCG_CONTROL_tcon0_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON0_NO_SSCG_CONTROL_get_tcon0_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON0_NO_SSCG_CONTROL_get_tcon0_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON0_NO_SSCG_CONTROL_get_tcon0_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON0_NO_SSCG_CONTROL_get_tcon0_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON0_NO_SSCG_CONTROL_get_tcon0_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON0_NO_SSCG_CONTROL_get_tcon0_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON0_no_SSCG_SE                                                   0x1802D3B8
#define  TCON_TCON0_no_SSCG_SE_reg_addr                                          "0xB802D3B8"
#define  TCON_TCON0_no_SSCG_SE_reg                                               0xB802D3B8
#define  TCON_TCON0_no_SSCG_SE_inst_addr                                         "0x006E"
#define  set_TCON_TCON0_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON0_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON0_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON0_no_SSCG_SE_reg))
#define  TCON_TCON0_no_SSCG_SE_tcon0_no_sscg_start_shift                         (16)
#define  TCON_TCON0_no_SSCG_SE_tcon0_no_sscg_end_shift                           (0)
#define  TCON_TCON0_no_SSCG_SE_tcon0_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON0_no_SSCG_SE_tcon0_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON0_no_SSCG_SE_tcon0_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON0_no_SSCG_SE_tcon0_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON0_no_SSCG_SE_get_tcon0_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON0_no_SSCG_SE_get_tcon0_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON1_NO_SSCG_CONTROL                                              0x1802D3BC
#define  TCON_TCON1_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3BC"
#define  TCON_TCON1_NO_SSCG_CONTROL_reg                                          0xB802D3BC
#define  TCON_TCON1_NO_SSCG_CONTROL_inst_addr                                    "0x006F"
#define  set_TCON_TCON1_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON1_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON1_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON1_NO_SSCG_CONTROL_reg))
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_nosscg_en_shift                        (23)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_sel_shift                              (22)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_no_sscg_inv_shift                      (21)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_last_trig_en_shift                     (20)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_no_sscg_mode_shift                     (19)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_no_sscg_ctl_shift                      (16)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_sel_mask                               (0x00400000)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON1_NO_SSCG_CONTROL_tcon1_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON1_NO_SSCG_CONTROL_get_tcon1_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON1_NO_SSCG_CONTROL_get_tcon1_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON1_NO_SSCG_CONTROL_get_tcon1_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON1_NO_SSCG_CONTROL_get_tcon1_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON1_NO_SSCG_CONTROL_get_tcon1_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON1_NO_SSCG_CONTROL_get_tcon1_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON1_no_SSCG_SE                                                   0x1802D3C0
#define  TCON_TCON1_no_SSCG_SE_reg_addr                                          "0xB802D3C0"
#define  TCON_TCON1_no_SSCG_SE_reg                                               0xB802D3C0
#define  TCON_TCON1_no_SSCG_SE_inst_addr                                         "0x0070"
#define  set_TCON_TCON1_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON1_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON1_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON1_no_SSCG_SE_reg))
#define  TCON_TCON1_no_SSCG_SE_tcon1_no_sscg_start_shift                         (16)
#define  TCON_TCON1_no_SSCG_SE_tcon1_no_sscg_end_shift                           (0)
#define  TCON_TCON1_no_SSCG_SE_tcon1_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON1_no_SSCG_SE_tcon1_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON1_no_SSCG_SE_tcon1_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON1_no_SSCG_SE_tcon1_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON1_no_SSCG_SE_get_tcon1_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON1_no_SSCG_SE_get_tcon1_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON2_NO_SSCG_CONTROL                                              0x1802D3C4
#define  TCON_TCON2_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3C4"
#define  TCON_TCON2_NO_SSCG_CONTROL_reg                                          0xB802D3C4
#define  TCON_TCON2_NO_SSCG_CONTROL_inst_addr                                    "0x0071"
#define  set_TCON_TCON2_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON2_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON2_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON2_NO_SSCG_CONTROL_reg))
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_nosscg_en_shift                        (23)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_sel_shift                              (22)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_no_sscg_inv_shift                      (21)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_last_trig_en_shift                     (20)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_no_sscg_mode_shift                     (19)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_no_sscg_ctl_shift                      (16)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_sel_mask                               (0x00400000)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON2_NO_SSCG_CONTROL_tcon2_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON2_NO_SSCG_CONTROL_get_tcon2_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON2_NO_SSCG_CONTROL_get_tcon2_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON2_NO_SSCG_CONTROL_get_tcon2_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON2_NO_SSCG_CONTROL_get_tcon2_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON2_NO_SSCG_CONTROL_get_tcon2_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON2_NO_SSCG_CONTROL_get_tcon2_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON2_no_SSCG_SE                                                   0x1802D3C8
#define  TCON_TCON2_no_SSCG_SE_reg_addr                                          "0xB802D3C8"
#define  TCON_TCON2_no_SSCG_SE_reg                                               0xB802D3C8
#define  TCON_TCON2_no_SSCG_SE_inst_addr                                         "0x0072"
#define  set_TCON_TCON2_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON2_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON2_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON2_no_SSCG_SE_reg))
#define  TCON_TCON2_no_SSCG_SE_tcon2_no_sscg_start_shift                         (16)
#define  TCON_TCON2_no_SSCG_SE_tcon2_no_sscg_end_shift                           (0)
#define  TCON_TCON2_no_SSCG_SE_tcon2_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON2_no_SSCG_SE_tcon2_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON2_no_SSCG_SE_tcon2_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON2_no_SSCG_SE_tcon2_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON2_no_SSCG_SE_get_tcon2_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON2_no_SSCG_SE_get_tcon2_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON3_NO_SSCG_CONTROL                                              0x1802D3CC
#define  TCON_TCON3_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3CC"
#define  TCON_TCON3_NO_SSCG_CONTROL_reg                                          0xB802D3CC
#define  TCON_TCON3_NO_SSCG_CONTROL_inst_addr                                    "0x0073"
#define  set_TCON_TCON3_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON3_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON3_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON3_NO_SSCG_CONTROL_reg))
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_nosscg_en_shift                        (23)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_sel_shift                              (22)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_no_sscg_inv_shift                      (21)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_last_trig_en_shift                     (20)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_no_sscg_mode_shift                     (19)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_no_sscg_ctl_shift                      (16)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_sel_mask                               (0x00400000)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON3_NO_SSCG_CONTROL_tcon3_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON3_NO_SSCG_CONTROL_get_tcon3_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON3_NO_SSCG_CONTROL_get_tcon3_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON3_NO_SSCG_CONTROL_get_tcon3_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON3_NO_SSCG_CONTROL_get_tcon3_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON3_NO_SSCG_CONTROL_get_tcon3_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON3_NO_SSCG_CONTROL_get_tcon3_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON3_no_SSCG_SE                                                   0x1802D3D0
#define  TCON_TCON3_no_SSCG_SE_reg_addr                                          "0xB802D3D0"
#define  TCON_TCON3_no_SSCG_SE_reg                                               0xB802D3D0
#define  TCON_TCON3_no_SSCG_SE_inst_addr                                         "0x0074"
#define  set_TCON_TCON3_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON3_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON3_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON3_no_SSCG_SE_reg))
#define  TCON_TCON3_no_SSCG_SE_tcon3_no_sscg_start_shift                         (16)
#define  TCON_TCON3_no_SSCG_SE_tcon3_no_sscg_end_shift                           (0)
#define  TCON_TCON3_no_SSCG_SE_tcon3_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON3_no_SSCG_SE_tcon3_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON3_no_SSCG_SE_tcon3_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON3_no_SSCG_SE_tcon3_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON3_no_SSCG_SE_get_tcon3_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON3_no_SSCG_SE_get_tcon3_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON4_NO_SSCG_CONTROL                                              0x1802D3D4
#define  TCON_TCON4_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3D4"
#define  TCON_TCON4_NO_SSCG_CONTROL_reg                                          0xB802D3D4
#define  TCON_TCON4_NO_SSCG_CONTROL_inst_addr                                    "0x0075"
#define  set_TCON_TCON4_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON4_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON4_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON4_NO_SSCG_CONTROL_reg))
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_nosscg_en_shift                        (23)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_sel_shift                              (22)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_no_sscg_inv_shift                      (21)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_last_trig_en_shift                     (20)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_no_sscg_mode_shift                     (19)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_no_sscg_ctl_shift                      (16)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_sel_mask                               (0x00400000)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON4_NO_SSCG_CONTROL_tcon4_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON4_NO_SSCG_CONTROL_get_tcon4_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON4_NO_SSCG_CONTROL_get_tcon4_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON4_NO_SSCG_CONTROL_get_tcon4_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON4_NO_SSCG_CONTROL_get_tcon4_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON4_NO_SSCG_CONTROL_get_tcon4_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON4_NO_SSCG_CONTROL_get_tcon4_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON4_no_SSCG_SE                                                   0x1802D3D8
#define  TCON_TCON4_no_SSCG_SE_reg_addr                                          "0xB802D3D8"
#define  TCON_TCON4_no_SSCG_SE_reg                                               0xB802D3D8
#define  TCON_TCON4_no_SSCG_SE_inst_addr                                         "0x0076"
#define  set_TCON_TCON4_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON4_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON4_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON4_no_SSCG_SE_reg))
#define  TCON_TCON4_no_SSCG_SE_tcon4_no_sscg_start_shift                         (16)
#define  TCON_TCON4_no_SSCG_SE_tcon4_no_sscg_end_shift                           (0)
#define  TCON_TCON4_no_SSCG_SE_tcon4_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON4_no_SSCG_SE_tcon4_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON4_no_SSCG_SE_tcon4_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON4_no_SSCG_SE_tcon4_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON4_no_SSCG_SE_get_tcon4_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON4_no_SSCG_SE_get_tcon4_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON5_NO_SSCG_CONTROL                                              0x1802D3DC
#define  TCON_TCON5_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3DC"
#define  TCON_TCON5_NO_SSCG_CONTROL_reg                                          0xB802D3DC
#define  TCON_TCON5_NO_SSCG_CONTROL_inst_addr                                    "0x0077"
#define  set_TCON_TCON5_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON5_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON5_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON5_NO_SSCG_CONTROL_reg))
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_nosscg_en_shift                        (23)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_sel_shift                              (22)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_no_sscg_inv_shift                      (21)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_last_trig_en_shift                     (20)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_no_sscg_mode_shift                     (19)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_no_sscg_ctl_shift                      (16)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_sel_mask                               (0x00400000)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON5_NO_SSCG_CONTROL_tcon5_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON5_NO_SSCG_CONTROL_get_tcon5_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON5_NO_SSCG_CONTROL_get_tcon5_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON5_NO_SSCG_CONTROL_get_tcon5_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON5_NO_SSCG_CONTROL_get_tcon5_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON5_NO_SSCG_CONTROL_get_tcon5_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON5_NO_SSCG_CONTROL_get_tcon5_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON5_no_SSCG_SE                                                   0x1802D3E0
#define  TCON_TCON5_no_SSCG_SE_reg_addr                                          "0xB802D3E0"
#define  TCON_TCON5_no_SSCG_SE_reg                                               0xB802D3E0
#define  TCON_TCON5_no_SSCG_SE_inst_addr                                         "0x0078"
#define  set_TCON_TCON5_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON5_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON5_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON5_no_SSCG_SE_reg))
#define  TCON_TCON5_no_SSCG_SE_tcon5_no_sscg_start_shift                         (16)
#define  TCON_TCON5_no_SSCG_SE_tcon5_no_sscg_end_shift                           (0)
#define  TCON_TCON5_no_SSCG_SE_tcon5_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON5_no_SSCG_SE_tcon5_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON5_no_SSCG_SE_tcon5_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON5_no_SSCG_SE_tcon5_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON5_no_SSCG_SE_get_tcon5_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON5_no_SSCG_SE_get_tcon5_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON6_NO_SSCG_CONTROL                                              0x1802D3E4
#define  TCON_TCON6_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3E4"
#define  TCON_TCON6_NO_SSCG_CONTROL_reg                                          0xB802D3E4
#define  TCON_TCON6_NO_SSCG_CONTROL_inst_addr                                    "0x0079"
#define  set_TCON_TCON6_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON6_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON6_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON6_NO_SSCG_CONTROL_reg))
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_nosscg_en_shift                        (23)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_sel_shift                              (22)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_no_sscg_inv_shift                      (21)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_last_trig_en_shift                     (20)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_no_sscg_mode_shift                     (19)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_no_sscg_ctl_shift                      (16)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_sel_mask                               (0x00400000)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON6_NO_SSCG_CONTROL_tcon6_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON6_NO_SSCG_CONTROL_get_tcon6_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON6_NO_SSCG_CONTROL_get_tcon6_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON6_NO_SSCG_CONTROL_get_tcon6_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON6_NO_SSCG_CONTROL_get_tcon6_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON6_NO_SSCG_CONTROL_get_tcon6_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON6_NO_SSCG_CONTROL_get_tcon6_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON6_no_SSCG_SE                                                   0x1802D3E8
#define  TCON_TCON6_no_SSCG_SE_reg_addr                                          "0xB802D3E8"
#define  TCON_TCON6_no_SSCG_SE_reg                                               0xB802D3E8
#define  TCON_TCON6_no_SSCG_SE_inst_addr                                         "0x007A"
#define  set_TCON_TCON6_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON6_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON6_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON6_no_SSCG_SE_reg))
#define  TCON_TCON6_no_SSCG_SE_tcon6_no_sscg_start_shift                         (16)
#define  TCON_TCON6_no_SSCG_SE_tcon6_no_sscg_end_shift                           (0)
#define  TCON_TCON6_no_SSCG_SE_tcon6_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON6_no_SSCG_SE_tcon6_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON6_no_SSCG_SE_tcon6_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON6_no_SSCG_SE_tcon6_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON6_no_SSCG_SE_get_tcon6_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON6_no_SSCG_SE_get_tcon6_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON7_NO_SSCG_CONTROL                                              0x1802D3EC
#define  TCON_TCON7_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3EC"
#define  TCON_TCON7_NO_SSCG_CONTROL_reg                                          0xB802D3EC
#define  TCON_TCON7_NO_SSCG_CONTROL_inst_addr                                    "0x007B"
#define  set_TCON_TCON7_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON7_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON7_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON7_NO_SSCG_CONTROL_reg))
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_nosscg_en_shift                        (23)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_sel_shift                              (22)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_no_sscg_inv_shift                      (21)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_last_trig_en_shift                     (20)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_no_sscg_mode_shift                     (19)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_no_sscg_ctl_shift                      (16)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_sel_mask                               (0x00400000)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON7_NO_SSCG_CONTROL_tcon7_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON7_NO_SSCG_CONTROL_get_tcon7_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON7_NO_SSCG_CONTROL_get_tcon7_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON7_NO_SSCG_CONTROL_get_tcon7_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON7_NO_SSCG_CONTROL_get_tcon7_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON7_NO_SSCG_CONTROL_get_tcon7_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON7_NO_SSCG_CONTROL_get_tcon7_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON7_no_SSCG_SE                                                   0x1802D3F0
#define  TCON_TCON7_no_SSCG_SE_reg_addr                                          "0xB802D3F0"
#define  TCON_TCON7_no_SSCG_SE_reg                                               0xB802D3F0
#define  TCON_TCON7_no_SSCG_SE_inst_addr                                         "0x007C"
#define  set_TCON_TCON7_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON7_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON7_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON7_no_SSCG_SE_reg))
#define  TCON_TCON7_no_SSCG_SE_tcon7_no_sscg_start_shift                         (16)
#define  TCON_TCON7_no_SSCG_SE_tcon7_no_sscg_end_shift                           (0)
#define  TCON_TCON7_no_SSCG_SE_tcon7_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON7_no_SSCG_SE_tcon7_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON7_no_SSCG_SE_tcon7_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON7_no_SSCG_SE_tcon7_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON7_no_SSCG_SE_get_tcon7_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON7_no_SSCG_SE_get_tcon7_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON8_NO_SSCG_CONTROL                                              0x1802D3F4
#define  TCON_TCON8_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3F4"
#define  TCON_TCON8_NO_SSCG_CONTROL_reg                                          0xB802D3F4
#define  TCON_TCON8_NO_SSCG_CONTROL_inst_addr                                    "0x007D"
#define  set_TCON_TCON8_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON8_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON8_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON8_NO_SSCG_CONTROL_reg))
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_nosscg_en_shift                        (23)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_sel_shift                              (22)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_no_sscg_inv_shift                      (21)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_last_trig_en_shift                     (20)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_no_sscg_mode_shift                     (19)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_no_sscg_ctl_shift                      (16)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_sel_mask                               (0x00400000)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON8_NO_SSCG_CONTROL_tcon8_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON8_NO_SSCG_CONTROL_get_tcon8_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON8_NO_SSCG_CONTROL_get_tcon8_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON8_NO_SSCG_CONTROL_get_tcon8_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON8_NO_SSCG_CONTROL_get_tcon8_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON8_NO_SSCG_CONTROL_get_tcon8_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON8_NO_SSCG_CONTROL_get_tcon8_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON8_no_SSCG_SE                                                   0x1802D3F8
#define  TCON_TCON8_no_SSCG_SE_reg_addr                                          "0xB802D3F8"
#define  TCON_TCON8_no_SSCG_SE_reg                                               0xB802D3F8
#define  TCON_TCON8_no_SSCG_SE_inst_addr                                         "0x007E"
#define  set_TCON_TCON8_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON8_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON8_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON8_no_SSCG_SE_reg))
#define  TCON_TCON8_no_SSCG_SE_tcon8_no_sscg_start_shift                         (16)
#define  TCON_TCON8_no_SSCG_SE_tcon8_no_sscg_end_shift                           (0)
#define  TCON_TCON8_no_SSCG_SE_tcon8_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON8_no_SSCG_SE_tcon8_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON8_no_SSCG_SE_tcon8_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON8_no_SSCG_SE_tcon8_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON8_no_SSCG_SE_get_tcon8_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON8_no_SSCG_SE_get_tcon8_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON9_NO_SSCG_CONTROL                                              0x1802D3FC
#define  TCON_TCON9_NO_SSCG_CONTROL_reg_addr                                     "0xB802D3FC"
#define  TCON_TCON9_NO_SSCG_CONTROL_reg                                          0xB802D3FC
#define  TCON_TCON9_NO_SSCG_CONTROL_inst_addr                                    "0x007F"
#define  set_TCON_TCON9_NO_SSCG_CONTROL_reg(data)                                (*((volatile unsigned int*)TCON_TCON9_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON9_NO_SSCG_CONTROL_reg                                      (*((volatile unsigned int*)TCON_TCON9_NO_SSCG_CONTROL_reg))
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_nosscg_en_shift                        (23)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_sel_shift                              (22)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_no_sscg_inv_shift                      (21)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_last_trig_en_shift                     (20)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_no_sscg_mode_shift                     (19)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_no_sscg_ctl_shift                      (16)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_nosscg_en_mask                         (0x00800000)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_sel_mask                               (0x00400000)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_no_sscg_inv_mask                       (0x00200000)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_last_trig_en_mask                      (0x00100000)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_no_sscg_mode_mask                      (0x00080000)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_no_sscg_ctl_mask                       (0x00070000)
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_nosscg_en(data)                        (0x00800000&((data)<<23))
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_sel(data)                              (0x00400000&((data)<<22))
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_no_sscg_inv(data)                      (0x00200000&((data)<<21))
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_last_trig_en(data)                     (0x00100000&((data)<<20))
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_no_sscg_mode(data)                     (0x00080000&((data)<<19))
#define  TCON_TCON9_NO_SSCG_CONTROL_tcon9_no_sscg_ctl(data)                      (0x00070000&((data)<<16))
#define  TCON_TCON9_NO_SSCG_CONTROL_get_tcon9_nosscg_en(data)                    ((0x00800000&(data))>>23)
#define  TCON_TCON9_NO_SSCG_CONTROL_get_tcon9_sel(data)                          ((0x00400000&(data))>>22)
#define  TCON_TCON9_NO_SSCG_CONTROL_get_tcon9_no_sscg_inv(data)                  ((0x00200000&(data))>>21)
#define  TCON_TCON9_NO_SSCG_CONTROL_get_tcon9_last_trig_en(data)                 ((0x00100000&(data))>>20)
#define  TCON_TCON9_NO_SSCG_CONTROL_get_tcon9_no_sscg_mode(data)                 ((0x00080000&(data))>>19)
#define  TCON_TCON9_NO_SSCG_CONTROL_get_tcon9_no_sscg_ctl(data)                  ((0x00070000&(data))>>16)

#define  TCON_TCON9_no_SSCG_SE                                                   0x1802D400
#define  TCON_TCON9_no_SSCG_SE_reg_addr                                          "0xB802D400"
#define  TCON_TCON9_no_SSCG_SE_reg                                               0xB802D400
#define  TCON_TCON9_no_SSCG_SE_inst_addr                                         "0x0080"
#define  set_TCON_TCON9_no_SSCG_SE_reg(data)                                     (*((volatile unsigned int*)TCON_TCON9_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON9_no_SSCG_SE_reg                                           (*((volatile unsigned int*)TCON_TCON9_no_SSCG_SE_reg))
#define  TCON_TCON9_no_SSCG_SE_tcon9_no_sscg_start_shift                         (16)
#define  TCON_TCON9_no_SSCG_SE_tcon9_no_sscg_end_shift                           (0)
#define  TCON_TCON9_no_SSCG_SE_tcon9_no_sscg_start_mask                          (0xFFFF0000)
#define  TCON_TCON9_no_SSCG_SE_tcon9_no_sscg_end_mask                            (0x0000FFFF)
#define  TCON_TCON9_no_SSCG_SE_tcon9_no_sscg_start(data)                         (0xFFFF0000&((data)<<16))
#define  TCON_TCON9_no_SSCG_SE_tcon9_no_sscg_end(data)                           (0x0000FFFF&(data))
#define  TCON_TCON9_no_SSCG_SE_get_tcon9_no_sscg_start(data)                     ((0xFFFF0000&(data))>>16)
#define  TCON_TCON9_no_SSCG_SE_get_tcon9_no_sscg_end(data)                       (0x0000FFFF&(data))

#define  TCON_TCON10_NO_SSCG_CONTROL                                             0x1802D404
#define  TCON_TCON10_NO_SSCG_CONTROL_reg_addr                                    "0xB802D404"
#define  TCON_TCON10_NO_SSCG_CONTROL_reg                                         0xB802D404
#define  TCON_TCON10_NO_SSCG_CONTROL_inst_addr                                   "0x0081"
#define  set_TCON_TCON10_NO_SSCG_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON10_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON10_NO_SSCG_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON10_NO_SSCG_CONTROL_reg))
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_nosscg_en_shift                      (23)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_sel_shift                            (22)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_no_sscg_inv_shift                    (21)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_last_trig_en_shift                   (20)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_no_sscg_mode_shift                   (19)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_no_sscg_ctl_shift                    (16)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_nosscg_en_mask                       (0x00800000)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_sel_mask                             (0x00400000)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_no_sscg_inv_mask                     (0x00200000)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_last_trig_en_mask                    (0x00100000)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_no_sscg_mode_mask                    (0x00080000)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_no_sscg_ctl_mask                     (0x00070000)
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_nosscg_en(data)                      (0x00800000&((data)<<23))
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_sel(data)                            (0x00400000&((data)<<22))
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_no_sscg_inv(data)                    (0x00200000&((data)<<21))
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_last_trig_en(data)                   (0x00100000&((data)<<20))
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_no_sscg_mode(data)                   (0x00080000&((data)<<19))
#define  TCON_TCON10_NO_SSCG_CONTROL_tcon10_no_sscg_ctl(data)                    (0x00070000&((data)<<16))
#define  TCON_TCON10_NO_SSCG_CONTROL_get_tcon10_nosscg_en(data)                  ((0x00800000&(data))>>23)
#define  TCON_TCON10_NO_SSCG_CONTROL_get_tcon10_sel(data)                        ((0x00400000&(data))>>22)
#define  TCON_TCON10_NO_SSCG_CONTROL_get_tcon10_no_sscg_inv(data)                ((0x00200000&(data))>>21)
#define  TCON_TCON10_NO_SSCG_CONTROL_get_tcon10_last_trig_en(data)               ((0x00100000&(data))>>20)
#define  TCON_TCON10_NO_SSCG_CONTROL_get_tcon10_no_sscg_mode(data)               ((0x00080000&(data))>>19)
#define  TCON_TCON10_NO_SSCG_CONTROL_get_tcon10_no_sscg_ctl(data)                ((0x00070000&(data))>>16)

#define  TCON_TCON10_no_SSCG_SE                                                  0x1802D408
#define  TCON_TCON10_no_SSCG_SE_reg_addr                                         "0xB802D408"
#define  TCON_TCON10_no_SSCG_SE_reg                                              0xB802D408
#define  TCON_TCON10_no_SSCG_SE_inst_addr                                        "0x0082"
#define  set_TCON_TCON10_no_SSCG_SE_reg(data)                                    (*((volatile unsigned int*)TCON_TCON10_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON10_no_SSCG_SE_reg                                          (*((volatile unsigned int*)TCON_TCON10_no_SSCG_SE_reg))
#define  TCON_TCON10_no_SSCG_SE_tcon10_no_sscg_start_shift                       (16)
#define  TCON_TCON10_no_SSCG_SE_tcon10_no_sscg_end_shift                         (0)
#define  TCON_TCON10_no_SSCG_SE_tcon10_no_sscg_start_mask                        (0xFFFF0000)
#define  TCON_TCON10_no_SSCG_SE_tcon10_no_sscg_end_mask                          (0x0000FFFF)
#define  TCON_TCON10_no_SSCG_SE_tcon10_no_sscg_start(data)                       (0xFFFF0000&((data)<<16))
#define  TCON_TCON10_no_SSCG_SE_tcon10_no_sscg_end(data)                         (0x0000FFFF&(data))
#define  TCON_TCON10_no_SSCG_SE_get_tcon10_no_sscg_start(data)                   ((0xFFFF0000&(data))>>16)
#define  TCON_TCON10_no_SSCG_SE_get_tcon10_no_sscg_end(data)                     (0x0000FFFF&(data))

#define  TCON_TCON11_NO_SSCG_CONTROL                                             0x1802D40C
#define  TCON_TCON11_NO_SSCG_CONTROL_reg_addr                                    "0xB802D40C"
#define  TCON_TCON11_NO_SSCG_CONTROL_reg                                         0xB802D40C
#define  TCON_TCON11_NO_SSCG_CONTROL_inst_addr                                   "0x0083"
#define  set_TCON_TCON11_NO_SSCG_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON11_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON11_NO_SSCG_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON11_NO_SSCG_CONTROL_reg))
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_nosscg_en_shift                      (23)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_sel_shift                            (22)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_no_sscg_inv_shift                    (21)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_last_trig_en_shift                   (20)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_no_sscg_mode_shift                   (19)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_no_sscg_ctl_shift                    (16)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_nosscg_en_mask                       (0x00800000)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_sel_mask                             (0x00400000)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_no_sscg_inv_mask                     (0x00200000)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_last_trig_en_mask                    (0x00100000)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_no_sscg_mode_mask                    (0x00080000)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_no_sscg_ctl_mask                     (0x00070000)
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_nosscg_en(data)                      (0x00800000&((data)<<23))
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_sel(data)                            (0x00400000&((data)<<22))
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_no_sscg_inv(data)                    (0x00200000&((data)<<21))
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_last_trig_en(data)                   (0x00100000&((data)<<20))
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_no_sscg_mode(data)                   (0x00080000&((data)<<19))
#define  TCON_TCON11_NO_SSCG_CONTROL_tcon11_no_sscg_ctl(data)                    (0x00070000&((data)<<16))
#define  TCON_TCON11_NO_SSCG_CONTROL_get_tcon11_nosscg_en(data)                  ((0x00800000&(data))>>23)
#define  TCON_TCON11_NO_SSCG_CONTROL_get_tcon11_sel(data)                        ((0x00400000&(data))>>22)
#define  TCON_TCON11_NO_SSCG_CONTROL_get_tcon11_no_sscg_inv(data)                ((0x00200000&(data))>>21)
#define  TCON_TCON11_NO_SSCG_CONTROL_get_tcon11_last_trig_en(data)               ((0x00100000&(data))>>20)
#define  TCON_TCON11_NO_SSCG_CONTROL_get_tcon11_no_sscg_mode(data)               ((0x00080000&(data))>>19)
#define  TCON_TCON11_NO_SSCG_CONTROL_get_tcon11_no_sscg_ctl(data)                ((0x00070000&(data))>>16)

#define  TCON_TCON11_no_SSCG_SE                                                  0x1802D410
#define  TCON_TCON11_no_SSCG_SE_reg_addr                                         "0xB802D410"
#define  TCON_TCON11_no_SSCG_SE_reg                                              0xB802D410
#define  TCON_TCON11_no_SSCG_SE_inst_addr                                        "0x0084"
#define  set_TCON_TCON11_no_SSCG_SE_reg(data)                                    (*((volatile unsigned int*)TCON_TCON11_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON11_no_SSCG_SE_reg                                          (*((volatile unsigned int*)TCON_TCON11_no_SSCG_SE_reg))
#define  TCON_TCON11_no_SSCG_SE_tcon11_no_sscg_start_shift                       (16)
#define  TCON_TCON11_no_SSCG_SE_tcon11_no_sscg_end_shift                         (0)
#define  TCON_TCON11_no_SSCG_SE_tcon11_no_sscg_start_mask                        (0xFFFF0000)
#define  TCON_TCON11_no_SSCG_SE_tcon11_no_sscg_end_mask                          (0x0000FFFF)
#define  TCON_TCON11_no_SSCG_SE_tcon11_no_sscg_start(data)                       (0xFFFF0000&((data)<<16))
#define  TCON_TCON11_no_SSCG_SE_tcon11_no_sscg_end(data)                         (0x0000FFFF&(data))
#define  TCON_TCON11_no_SSCG_SE_get_tcon11_no_sscg_start(data)                   ((0xFFFF0000&(data))>>16)
#define  TCON_TCON11_no_SSCG_SE_get_tcon11_no_sscg_end(data)                     (0x0000FFFF&(data))

#define  TCON_TCON12_NO_SSCG_CONTROL                                             0x1802D414
#define  TCON_TCON12_NO_SSCG_CONTROL_reg_addr                                    "0xB802D414"
#define  TCON_TCON12_NO_SSCG_CONTROL_reg                                         0xB802D414
#define  TCON_TCON12_NO_SSCG_CONTROL_inst_addr                                   "0x0085"
#define  set_TCON_TCON12_NO_SSCG_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON12_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON12_NO_SSCG_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON12_NO_SSCG_CONTROL_reg))
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_nosscg_en_shift                      (23)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_sel_shift                            (22)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_no_sscg_inv_shift                    (21)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_last_trig_en_shift                   (20)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_no_sscg_mode_shift                   (19)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_no_sscg_ctl_shift                    (16)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_nosscg_en_mask                       (0x00800000)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_sel_mask                             (0x00400000)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_no_sscg_inv_mask                     (0x00200000)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_last_trig_en_mask                    (0x00100000)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_no_sscg_mode_mask                    (0x00080000)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_no_sscg_ctl_mask                     (0x00070000)
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_nosscg_en(data)                      (0x00800000&((data)<<23))
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_sel(data)                            (0x00400000&((data)<<22))
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_no_sscg_inv(data)                    (0x00200000&((data)<<21))
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_last_trig_en(data)                   (0x00100000&((data)<<20))
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_no_sscg_mode(data)                   (0x00080000&((data)<<19))
#define  TCON_TCON12_NO_SSCG_CONTROL_tcon12_no_sscg_ctl(data)                    (0x00070000&((data)<<16))
#define  TCON_TCON12_NO_SSCG_CONTROL_get_tcon12_nosscg_en(data)                  ((0x00800000&(data))>>23)
#define  TCON_TCON12_NO_SSCG_CONTROL_get_tcon12_sel(data)                        ((0x00400000&(data))>>22)
#define  TCON_TCON12_NO_SSCG_CONTROL_get_tcon12_no_sscg_inv(data)                ((0x00200000&(data))>>21)
#define  TCON_TCON12_NO_SSCG_CONTROL_get_tcon12_last_trig_en(data)               ((0x00100000&(data))>>20)
#define  TCON_TCON12_NO_SSCG_CONTROL_get_tcon12_no_sscg_mode(data)               ((0x00080000&(data))>>19)
#define  TCON_TCON12_NO_SSCG_CONTROL_get_tcon12_no_sscg_ctl(data)                ((0x00070000&(data))>>16)

#define  TCON_TCON12_no_SSCG_SE                                                  0x1802D418
#define  TCON_TCON12_no_SSCG_SE_reg_addr                                         "0xB802D418"
#define  TCON_TCON12_no_SSCG_SE_reg                                              0xB802D418
#define  TCON_TCON12_no_SSCG_SE_inst_addr                                        "0x0086"
#define  set_TCON_TCON12_no_SSCG_SE_reg(data)                                    (*((volatile unsigned int*)TCON_TCON12_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON12_no_SSCG_SE_reg                                          (*((volatile unsigned int*)TCON_TCON12_no_SSCG_SE_reg))
#define  TCON_TCON12_no_SSCG_SE_tcon12_no_sscg_start_shift                       (16)
#define  TCON_TCON12_no_SSCG_SE_tcon12_no_sscg_end_shift                         (0)
#define  TCON_TCON12_no_SSCG_SE_tcon12_no_sscg_start_mask                        (0xFFFF0000)
#define  TCON_TCON12_no_SSCG_SE_tcon12_no_sscg_end_mask                          (0x0000FFFF)
#define  TCON_TCON12_no_SSCG_SE_tcon12_no_sscg_start(data)                       (0xFFFF0000&((data)<<16))
#define  TCON_TCON12_no_SSCG_SE_tcon12_no_sscg_end(data)                         (0x0000FFFF&(data))
#define  TCON_TCON12_no_SSCG_SE_get_tcon12_no_sscg_start(data)                   ((0xFFFF0000&(data))>>16)
#define  TCON_TCON12_no_SSCG_SE_get_tcon12_no_sscg_end(data)                     (0x0000FFFF&(data))

#define  TCON_TCON13_NO_SSCG_CONTROL                                             0x1802D41C
#define  TCON_TCON13_NO_SSCG_CONTROL_reg_addr                                    "0xB802D41C"
#define  TCON_TCON13_NO_SSCG_CONTROL_reg                                         0xB802D41C
#define  TCON_TCON13_NO_SSCG_CONTROL_inst_addr                                   "0x0087"
#define  set_TCON_TCON13_NO_SSCG_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON13_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON13_NO_SSCG_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON13_NO_SSCG_CONTROL_reg))
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_nosscg_en_shift                      (23)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_sel_shift                            (22)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_no_sscg_inv_shift                    (21)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_last_trig_en_shift                   (20)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_no_sscg_mode_shift                   (19)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_no_sscg_ctl_shift                    (16)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_nosscg_en_mask                       (0x00800000)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_sel_mask                             (0x00400000)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_no_sscg_inv_mask                     (0x00200000)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_last_trig_en_mask                    (0x00100000)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_no_sscg_mode_mask                    (0x00080000)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_no_sscg_ctl_mask                     (0x00070000)
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_nosscg_en(data)                      (0x00800000&((data)<<23))
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_sel(data)                            (0x00400000&((data)<<22))
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_no_sscg_inv(data)                    (0x00200000&((data)<<21))
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_last_trig_en(data)                   (0x00100000&((data)<<20))
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_no_sscg_mode(data)                   (0x00080000&((data)<<19))
#define  TCON_TCON13_NO_SSCG_CONTROL_tcon13_no_sscg_ctl(data)                    (0x00070000&((data)<<16))
#define  TCON_TCON13_NO_SSCG_CONTROL_get_tcon13_nosscg_en(data)                  ((0x00800000&(data))>>23)
#define  TCON_TCON13_NO_SSCG_CONTROL_get_tcon13_sel(data)                        ((0x00400000&(data))>>22)
#define  TCON_TCON13_NO_SSCG_CONTROL_get_tcon13_no_sscg_inv(data)                ((0x00200000&(data))>>21)
#define  TCON_TCON13_NO_SSCG_CONTROL_get_tcon13_last_trig_en(data)               ((0x00100000&(data))>>20)
#define  TCON_TCON13_NO_SSCG_CONTROL_get_tcon13_no_sscg_mode(data)               ((0x00080000&(data))>>19)
#define  TCON_TCON13_NO_SSCG_CONTROL_get_tcon13_no_sscg_ctl(data)                ((0x00070000&(data))>>16)

#define  TCON_TCON13_no_SSCG_SE                                                  0x1802D420
#define  TCON_TCON13_no_SSCG_SE_reg_addr                                         "0xB802D420"
#define  TCON_TCON13_no_SSCG_SE_reg                                              0xB802D420
#define  TCON_TCON13_no_SSCG_SE_inst_addr                                        "0x0088"
#define  set_TCON_TCON13_no_SSCG_SE_reg(data)                                    (*((volatile unsigned int*)TCON_TCON13_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON13_no_SSCG_SE_reg                                          (*((volatile unsigned int*)TCON_TCON13_no_SSCG_SE_reg))
#define  TCON_TCON13_no_SSCG_SE_tcon13_no_sscg_start_shift                       (16)
#define  TCON_TCON13_no_SSCG_SE_tcon13_no_sscg_end_shift                         (0)
#define  TCON_TCON13_no_SSCG_SE_tcon13_no_sscg_start_mask                        (0xFFFF0000)
#define  TCON_TCON13_no_SSCG_SE_tcon13_no_sscg_end_mask                          (0x0000FFFF)
#define  TCON_TCON13_no_SSCG_SE_tcon13_no_sscg_start(data)                       (0xFFFF0000&((data)<<16))
#define  TCON_TCON13_no_SSCG_SE_tcon13_no_sscg_end(data)                         (0x0000FFFF&(data))
#define  TCON_TCON13_no_SSCG_SE_get_tcon13_no_sscg_start(data)                   ((0xFFFF0000&(data))>>16)
#define  TCON_TCON13_no_SSCG_SE_get_tcon13_no_sscg_end(data)                     (0x0000FFFF&(data))

#define  TCON_TCON14_NO_SSCG_CONTROL                                             0x1802D424
#define  TCON_TCON14_NO_SSCG_CONTROL_reg_addr                                    "0xB802D424"
#define  TCON_TCON14_NO_SSCG_CONTROL_reg                                         0xB802D424
#define  TCON_TCON14_NO_SSCG_CONTROL_inst_addr                                   "0x0089"
#define  set_TCON_TCON14_NO_SSCG_CONTROL_reg(data)                               (*((volatile unsigned int*)TCON_TCON14_NO_SSCG_CONTROL_reg)=data)
#define  get_TCON_TCON14_NO_SSCG_CONTROL_reg                                     (*((volatile unsigned int*)TCON_TCON14_NO_SSCG_CONTROL_reg))
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_nosscg_en_shift                      (23)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_sel_shift                            (22)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_no_sscg_inv_shift                    (21)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_last_trig_en_shift                   (20)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_no_sscg_mode_shift                   (19)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_no_sscg_ctl_shift                    (16)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_nosscg_en_mask                       (0x00800000)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_sel_mask                             (0x00400000)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_no_sscg_inv_mask                     (0x00200000)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_last_trig_en_mask                    (0x00100000)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_no_sscg_mode_mask                    (0x00080000)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_no_sscg_ctl_mask                     (0x00070000)
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_nosscg_en(data)                      (0x00800000&((data)<<23))
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_sel(data)                            (0x00400000&((data)<<22))
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_no_sscg_inv(data)                    (0x00200000&((data)<<21))
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_last_trig_en(data)                   (0x00100000&((data)<<20))
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_no_sscg_mode(data)                   (0x00080000&((data)<<19))
#define  TCON_TCON14_NO_SSCG_CONTROL_tcon14_no_sscg_ctl(data)                    (0x00070000&((data)<<16))
#define  TCON_TCON14_NO_SSCG_CONTROL_get_tcon14_nosscg_en(data)                  ((0x00800000&(data))>>23)
#define  TCON_TCON14_NO_SSCG_CONTROL_get_tcon14_sel(data)                        ((0x00400000&(data))>>22)
#define  TCON_TCON14_NO_SSCG_CONTROL_get_tcon14_no_sscg_inv(data)                ((0x00200000&(data))>>21)
#define  TCON_TCON14_NO_SSCG_CONTROL_get_tcon14_last_trig_en(data)               ((0x00100000&(data))>>20)
#define  TCON_TCON14_NO_SSCG_CONTROL_get_tcon14_no_sscg_mode(data)               ((0x00080000&(data))>>19)
#define  TCON_TCON14_NO_SSCG_CONTROL_get_tcon14_no_sscg_ctl(data)                ((0x00070000&(data))>>16)

#define  TCON_TCON14_no_SSCG_SE                                                  0x1802D428
#define  TCON_TCON14_no_SSCG_SE_reg_addr                                         "0xB802D428"
#define  TCON_TCON14_no_SSCG_SE_reg                                              0xB802D428
#define  TCON_TCON14_no_SSCG_SE_inst_addr                                        "0x008A"
#define  set_TCON_TCON14_no_SSCG_SE_reg(data)                                    (*((volatile unsigned int*)TCON_TCON14_no_SSCG_SE_reg)=data)
#define  get_TCON_TCON14_no_SSCG_SE_reg                                          (*((volatile unsigned int*)TCON_TCON14_no_SSCG_SE_reg))
#define  TCON_TCON14_no_SSCG_SE_tcon14_no_sscg_start_shift                       (16)
#define  TCON_TCON14_no_SSCG_SE_tcon14_no_sscg_end_shift                         (0)
#define  TCON_TCON14_no_SSCG_SE_tcon14_no_sscg_start_mask                        (0xFFFF0000)
#define  TCON_TCON14_no_SSCG_SE_tcon14_no_sscg_end_mask                          (0x0000FFFF)
#define  TCON_TCON14_no_SSCG_SE_tcon14_no_sscg_start(data)                       (0xFFFF0000&((data)<<16))
#define  TCON_TCON14_no_SSCG_SE_tcon14_no_sscg_end(data)                         (0x0000FFFF&(data))
#define  TCON_TCON14_no_SSCG_SE_get_tcon14_no_sscg_start(data)                   ((0xFFFF0000&(data))>>16)
#define  TCON_TCON14_no_SSCG_SE_get_tcon14_no_sscg_end(data)                     (0x0000FFFF&(data))

#define  TCON_TCON_IP_EN                                                         0x1802D42C
#define  TCON_TCON_IP_EN_reg_addr                                                "0xB802D42C"
#define  TCON_TCON_IP_EN_reg                                                     0xB802D42C
#define  TCON_TCON_IP_EN_inst_addr                                               "0x008B"
#define  set_TCON_TCON_IP_EN_reg(data)                                           (*((volatile unsigned int*)TCON_TCON_IP_EN_reg)=data)
#define  get_TCON_TCON_IP_EN_reg                                                 (*((volatile unsigned int*)TCON_TCON_IP_EN_reg))
#define  TCON_TCON_IP_EN_tcon_en_shift                                           (0)
#define  TCON_TCON_IP_EN_tcon_en_mask                                            (0x00000001)
#define  TCON_TCON_IP_EN_tcon_en(data)                                           (0x00000001&(data))
#define  TCON_TCON_IP_EN_get_tcon_en(data)                                       (0x00000001&(data))

#define  TCON_Double_Buffer_CTRL3                                                0x1802D430
#define  TCON_Double_Buffer_CTRL3_reg_addr                                       "0xB802D430"
#define  TCON_Double_Buffer_CTRL3_reg                                            0xB802D430
#define  TCON_Double_Buffer_CTRL3_inst_addr                                      "0x008C"
#define  set_TCON_Double_Buffer_CTRL3_reg(data)                                  (*((volatile unsigned int*)TCON_Double_Buffer_CTRL3_reg)=data)
#define  get_TCON_Double_Buffer_CTRL3_reg                                        (*((volatile unsigned int*)TCON_Double_Buffer_CTRL3_reg))
#define  TCON_Double_Buffer_CTRL3_dreg_dbuf3_en_n_shift                          (2)
#define  TCON_Double_Buffer_CTRL3_dreg_dbuf3_read_sel_shift                      (1)
#define  TCON_Double_Buffer_CTRL3_dreg_dbuf3_set_shift                           (0)
#define  TCON_Double_Buffer_CTRL3_dreg_dbuf3_en_n_mask                           (0x00000004)
#define  TCON_Double_Buffer_CTRL3_dreg_dbuf3_read_sel_mask                       (0x00000002)
#define  TCON_Double_Buffer_CTRL3_dreg_dbuf3_set_mask                            (0x00000001)
#define  TCON_Double_Buffer_CTRL3_dreg_dbuf3_en_n(data)                          (0x00000004&((data)<<2))
#define  TCON_Double_Buffer_CTRL3_dreg_dbuf3_read_sel(data)                      (0x00000002&((data)<<1))
#define  TCON_Double_Buffer_CTRL3_dreg_dbuf3_set(data)                           (0x00000001&(data))
#define  TCON_Double_Buffer_CTRL3_get_dreg_dbuf3_en_n(data)                      ((0x00000004&(data))>>2)
#define  TCON_Double_Buffer_CTRL3_get_dreg_dbuf3_read_sel(data)                  ((0x00000002&(data))>>1)
#define  TCON_Double_Buffer_CTRL3_get_dreg_dbuf3_set(data)                       (0x00000001&(data))

#define  TCON_Double_Buffer_CTRL4                                                0x1802D434
#define  TCON_Double_Buffer_CTRL4_reg_addr                                       "0xB802D434"
#define  TCON_Double_Buffer_CTRL4_reg                                            0xB802D434
#define  TCON_Double_Buffer_CTRL4_inst_addr                                      "0x008D"
#define  set_TCON_Double_Buffer_CTRL4_reg(data)                                  (*((volatile unsigned int*)TCON_Double_Buffer_CTRL4_reg)=data)
#define  get_TCON_Double_Buffer_CTRL4_reg                                        (*((volatile unsigned int*)TCON_Double_Buffer_CTRL4_reg))
#define  TCON_Double_Buffer_CTRL4_dreg_dbuf4_en_n_shift                          (2)
#define  TCON_Double_Buffer_CTRL4_dreg_dbuf4_read_sel_shift                      (1)
#define  TCON_Double_Buffer_CTRL4_dreg_dbuf4_set_shift                           (0)
#define  TCON_Double_Buffer_CTRL4_dreg_dbuf4_en_n_mask                           (0x00000004)
#define  TCON_Double_Buffer_CTRL4_dreg_dbuf4_read_sel_mask                       (0x00000002)
#define  TCON_Double_Buffer_CTRL4_dreg_dbuf4_set_mask                            (0x00000001)
#define  TCON_Double_Buffer_CTRL4_dreg_dbuf4_en_n(data)                          (0x00000004&((data)<<2))
#define  TCON_Double_Buffer_CTRL4_dreg_dbuf4_read_sel(data)                      (0x00000002&((data)<<1))
#define  TCON_Double_Buffer_CTRL4_dreg_dbuf4_set(data)                           (0x00000001&(data))
#define  TCON_Double_Buffer_CTRL4_get_dreg_dbuf4_en_n(data)                      ((0x00000004&(data))>>2)
#define  TCON_Double_Buffer_CTRL4_get_dreg_dbuf4_read_sel(data)                  ((0x00000002&(data))>>1)
#define  TCON_Double_Buffer_CTRL4_get_dreg_dbuf4_set(data)                       (0x00000001&(data))

#define  TCON_Double_Buffer_CTRL5                                                0x1802D438
#define  TCON_Double_Buffer_CTRL5_reg_addr                                       "0xB802D438"
#define  TCON_Double_Buffer_CTRL5_reg                                            0xB802D438
#define  TCON_Double_Buffer_CTRL5_inst_addr                                      "0x008E"
#define  set_TCON_Double_Buffer_CTRL5_reg(data)                                  (*((volatile unsigned int*)TCON_Double_Buffer_CTRL5_reg)=data)
#define  get_TCON_Double_Buffer_CTRL5_reg                                        (*((volatile unsigned int*)TCON_Double_Buffer_CTRL5_reg))
#define  TCON_Double_Buffer_CTRL5_dreg_dbuf5_en_n_shift                          (2)
#define  TCON_Double_Buffer_CTRL5_dreg_dbuf5_read_sel_shift                      (1)
#define  TCON_Double_Buffer_CTRL5_dreg_dbuf5_set_shift                           (0)
#define  TCON_Double_Buffer_CTRL5_dreg_dbuf5_en_n_mask                           (0x00000004)
#define  TCON_Double_Buffer_CTRL5_dreg_dbuf5_read_sel_mask                       (0x00000002)
#define  TCON_Double_Buffer_CTRL5_dreg_dbuf5_set_mask                            (0x00000001)
#define  TCON_Double_Buffer_CTRL5_dreg_dbuf5_en_n(data)                          (0x00000004&((data)<<2))
#define  TCON_Double_Buffer_CTRL5_dreg_dbuf5_read_sel(data)                      (0x00000002&((data)<<1))
#define  TCON_Double_Buffer_CTRL5_dreg_dbuf5_set(data)                           (0x00000001&(data))
#define  TCON_Double_Buffer_CTRL5_get_dreg_dbuf5_en_n(data)                      ((0x00000004&(data))>>2)
#define  TCON_Double_Buffer_CTRL5_get_dreg_dbuf5_read_sel(data)                  ((0x00000002&(data))>>1)
#define  TCON_Double_Buffer_CTRL5_get_dreg_dbuf5_set(data)                       (0x00000001&(data))

#define  TCON_Double_Buffer_CTRL6                                                0x1802D43C
#define  TCON_Double_Buffer_CTRL6_reg_addr                                       "0xB802D43C"
#define  TCON_Double_Buffer_CTRL6_reg                                            0xB802D43C
#define  TCON_Double_Buffer_CTRL6_inst_addr                                      "0x008F"
#define  set_TCON_Double_Buffer_CTRL6_reg(data)                                  (*((volatile unsigned int*)TCON_Double_Buffer_CTRL6_reg)=data)
#define  get_TCON_Double_Buffer_CTRL6_reg                                        (*((volatile unsigned int*)TCON_Double_Buffer_CTRL6_reg))
#define  TCON_Double_Buffer_CTRL6_dreg_dbuf6_en_n_shift                          (2)
#define  TCON_Double_Buffer_CTRL6_dreg_dbuf6_read_sel_shift                      (1)
#define  TCON_Double_Buffer_CTRL6_dreg_dbuf6_set_shift                           (0)
#define  TCON_Double_Buffer_CTRL6_dreg_dbuf6_en_n_mask                           (0x00000004)
#define  TCON_Double_Buffer_CTRL6_dreg_dbuf6_read_sel_mask                       (0x00000002)
#define  TCON_Double_Buffer_CTRL6_dreg_dbuf6_set_mask                            (0x00000001)
#define  TCON_Double_Buffer_CTRL6_dreg_dbuf6_en_n(data)                          (0x00000004&((data)<<2))
#define  TCON_Double_Buffer_CTRL6_dreg_dbuf6_read_sel(data)                      (0x00000002&((data)<<1))
#define  TCON_Double_Buffer_CTRL6_dreg_dbuf6_set(data)                           (0x00000001&(data))
#define  TCON_Double_Buffer_CTRL6_get_dreg_dbuf6_en_n(data)                      ((0x00000004&(data))>>2)
#define  TCON_Double_Buffer_CTRL6_get_dreg_dbuf6_read_sel(data)                  ((0x00000002&(data))>>1)
#define  TCON_Double_Buffer_CTRL6_get_dreg_dbuf6_set(data)                       (0x00000001&(data))

#define  TCON_Double_Buffer_CTRL7                                                0x1802D440
#define  TCON_Double_Buffer_CTRL7_reg_addr                                       "0xB802D440"
#define  TCON_Double_Buffer_CTRL7_reg                                            0xB802D440
#define  TCON_Double_Buffer_CTRL7_inst_addr                                      "0x0090"
#define  set_TCON_Double_Buffer_CTRL7_reg(data)                                  (*((volatile unsigned int*)TCON_Double_Buffer_CTRL7_reg)=data)
#define  get_TCON_Double_Buffer_CTRL7_reg                                        (*((volatile unsigned int*)TCON_Double_Buffer_CTRL7_reg))
#define  TCON_Double_Buffer_CTRL7_dreg_dbuf7_en_n_shift                          (2)
#define  TCON_Double_Buffer_CTRL7_dreg_dbuf7_read_sel_shift                      (1)
#define  TCON_Double_Buffer_CTRL7_dreg_dbuf7_set_shift                           (0)
#define  TCON_Double_Buffer_CTRL7_dreg_dbuf7_en_n_mask                           (0x00000004)
#define  TCON_Double_Buffer_CTRL7_dreg_dbuf7_read_sel_mask                       (0x00000002)
#define  TCON_Double_Buffer_CTRL7_dreg_dbuf7_set_mask                            (0x00000001)
#define  TCON_Double_Buffer_CTRL7_dreg_dbuf7_en_n(data)                          (0x00000004&((data)<<2))
#define  TCON_Double_Buffer_CTRL7_dreg_dbuf7_read_sel(data)                      (0x00000002&((data)<<1))
#define  TCON_Double_Buffer_CTRL7_dreg_dbuf7_set(data)                           (0x00000001&(data))
#define  TCON_Double_Buffer_CTRL7_get_dreg_dbuf7_en_n(data)                      ((0x00000004&(data))>>2)
#define  TCON_Double_Buffer_CTRL7_get_dreg_dbuf7_read_sel(data)                  ((0x00000002&(data))>>1)
#define  TCON_Double_Buffer_CTRL7_get_dreg_dbuf7_set(data)                       (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TCON register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_no_sscg_clk_sel:1;
        RBus_UInt32  tcon_across_frame_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  tcon_output:15;
    };
}tcon_tcon_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_0:3;
        RBus_UInt32  tcon0_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon0_hend:13;
    };
}tcon_tcon0_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon0_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon0_vend:12;
    };
}tcon_tcon0_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon0_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon0_across_ctrl3_reset:1;
        RBus_UInt32  tcon0_mode:3;
        RBus_UInt32  tcon0_en:1;
        RBus_UInt32  tcon0_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon0_frame_tog_en:1;
        RBus_UInt32  tcon0_comb:3;
    };
}tcon_tcon0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon0_across_frame_int:1;
        RBus_UInt32  tcon0_across_ctrl3_rp:12;
        RBus_UInt32  tcon0_frame_hl_num:4;
        RBus_UInt32  tcon0_across_ctrl3_hp:12;
    };
}tcon_tcon0_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon0_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon0_frame_period:12;
    };
}tcon_tcon0_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_frame_hl:16;
        RBus_UInt32  tcon0_l_flag_prime:16;
    };
}tcon_tcon0_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon0_hoffset_shift_en:1;
        RBus_UInt32  tcon0_hoffset_shift_thd:12;
        RBus_UInt32  tcon0_hoffset_shift_value:6;
    };
}tcon_tcon0_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_1:3;
        RBus_UInt32  tcon1_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon1_hend:13;
    };
}tcon_tcon1_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon1_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon1_vend:12;
    };
}tcon_tcon1_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon1_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon1_across_ctrl3_reset:1;
        RBus_UInt32  tcon1_mode:3;
        RBus_UInt32  tcon1_en:1;
        RBus_UInt32  tcon1_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon1_frame_tog_en:1;
        RBus_UInt32  tcon1_comb:3;
    };
}tcon_tcon1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon1_across_frame_int:1;
        RBus_UInt32  tcon1_across_ctrl3_rp:12;
        RBus_UInt32  tcon1_frame_hl_num:4;
        RBus_UInt32  tcon1_across_ctrl3_hp:12;
    };
}tcon_tcon1_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon1_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon1_frame_period:12;
    };
}tcon_tcon1_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_frame_hl:16;
        RBus_UInt32  tcon1_l_flag_prime:16;
    };
}tcon_tcon1_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon1_hoffset_shift_en:1;
        RBus_UInt32  tcon1_hoffset_shift_thd:12;
        RBus_UInt32  tcon1_hoffset_shift_value:6;
    };
}tcon_tcon1_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_2:3;
        RBus_UInt32  tcon2_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon2_hend:13;
    };
}tcon_tcon2_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon2_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon2_vend:12;
    };
}tcon_tcon2_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon2_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon2_across_ctrl3_reset:1;
        RBus_UInt32  tcon2_mode:3;
        RBus_UInt32  tcon2_en:1;
        RBus_UInt32  tcon2_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon2_frame_tog_en:1;
        RBus_UInt32  tcon2_comb:3;
    };
}tcon_tcon2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon2_across_frame_int:1;
        RBus_UInt32  tcon2_across_ctrl3_rp:12;
        RBus_UInt32  tcon2_frame_hl_num:4;
        RBus_UInt32  tcon2_across_ctrl3_hp:12;
    };
}tcon_tcon2_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon2_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon2_frame_period:12;
    };
}tcon_tcon2_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_frame_hl:16;
        RBus_UInt32  tcon2_l_flag_prime:16;
    };
}tcon_tcon2_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon2_hoffset_shift_en:1;
        RBus_UInt32  tcon2_hoffset_shift_thd:12;
        RBus_UInt32  tcon2_hoffset_shift_value:6;
    };
}tcon_tcon2_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_3:3;
        RBus_UInt32  tcon3_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon3_hend:13;
    };
}tcon_tcon3_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon3_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon3_vend:12;
    };
}tcon_tcon3_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon3_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon3_across_ctrl3_reset:1;
        RBus_UInt32  tcon3_mode:3;
        RBus_UInt32  tcon3_en:1;
        RBus_UInt32  tcon3_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon3_frame_tog_en:1;
        RBus_UInt32  tcon3_comb:3;
    };
}tcon_tcon3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon3_across_frame_int:1;
        RBus_UInt32  tcon3_across_ctrl3_rp:12;
        RBus_UInt32  tcon3_frame_hl_num:4;
        RBus_UInt32  tcon3_across_ctrl3_hp:12;
    };
}tcon_tcon3_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon3_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon3_frame_period:12;
    };
}tcon_tcon3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_frame_hl:16;
        RBus_UInt32  tcon3_l_flag_prime:16;
    };
}tcon_tcon3_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon3_hoffset_shift_en:1;
        RBus_UInt32  tcon3_hoffset_shift_thd:12;
        RBus_UInt32  tcon3_hoffset_shift_value:6;
    };
}tcon_tcon3_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_4:3;
        RBus_UInt32  tcon4_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon4_hend:13;
    };
}tcon_tcon4_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon4_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon4_vend:12;
    };
}tcon_tcon4_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon4_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon4_across_ctrl3_reset:1;
        RBus_UInt32  tcon4_mode:3;
        RBus_UInt32  tcon4_en:1;
        RBus_UInt32  tcon4_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon4_frame_tog_en:1;
        RBus_UInt32  tcon4_comb:3;
    };
}tcon_tcon4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon4_across_frame_int:1;
        RBus_UInt32  tcon4_across_ctrl3_rp:12;
        RBus_UInt32  tcon4_frame_hl_num:4;
        RBus_UInt32  tcon4_across_ctrl3_hp:12;
    };
}tcon_tcon4_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon4_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon4_frame_period:12;
    };
}tcon_tcon4_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_frame_hl:16;
        RBus_UInt32  tcon4_l_flag_prime:16;
    };
}tcon_tcon4_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon4_hoffset_shift_en:1;
        RBus_UInt32  tcon4_hoffset_shift_thd:12;
        RBus_UInt32  tcon4_hoffset_shift_value:6;
    };
}tcon_tcon4_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_5:3;
        RBus_UInt32  tcon5_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon5_hend:13;
    };
}tcon_tcon5_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon5_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon5_vend:12;
    };
}tcon_tcon5_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon5_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon5_across_ctrl3_reset:1;
        RBus_UInt32  tcon5_mode:3;
        RBus_UInt32  tcon5_en:1;
        RBus_UInt32  tcon5_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon5_frame_tog_en:1;
        RBus_UInt32  tcon5_comb:3;
    };
}tcon_tcon5_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon5_across_frame_int:1;
        RBus_UInt32  tcon5_across_ctrl3_rp:12;
        RBus_UInt32  tcon5_frame_hl_num:4;
        RBus_UInt32  tcon5_across_ctrl3_hp:12;
    };
}tcon_tcon5_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon5_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon5_frame_period:12;
    };
}tcon_tcon5_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_frame_hl:16;
        RBus_UInt32  tcon5_l_flag_prime:16;
    };
}tcon_tcon5_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon5_hoffset_shift_en:1;
        RBus_UInt32  tcon5_hoffset_shift_thd:12;
        RBus_UInt32  tcon5_hoffset_shift_value:6;
    };
}tcon_tcon5_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_6:3;
        RBus_UInt32  tcon6_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon6_hend:13;
    };
}tcon_tcon6_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon6_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon6_vend:12;
    };
}tcon_tcon6_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon6_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon6_across_ctrl3_reset:1;
        RBus_UInt32  tcon6_mode:3;
        RBus_UInt32  tcon6_en:1;
        RBus_UInt32  tcon6_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon6_frame_tog_en:1;
        RBus_UInt32  tcon6_comb:3;
    };
}tcon_tcon6_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon6_across_frame_int:1;
        RBus_UInt32  tcon6_across_ctrl3_rp:12;
        RBus_UInt32  tcon6_frame_hl_num:4;
        RBus_UInt32  tcon6_across_ctrl3_hp:12;
    };
}tcon_tcon6_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon6_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon6_frame_period:12;
    };
}tcon_tcon6_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_frame_hl:16;
        RBus_UInt32  tcon6_l_flag_prime:16;
    };
}tcon_tcon6_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon6_hoffset_shift_en:1;
        RBus_UInt32  tcon6_hoffset_shift_thd:12;
        RBus_UInt32  tcon6_hoffset_shift_value:6;
    };
}tcon_tcon6_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_7:3;
        RBus_UInt32  tcon7_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon7_hend:13;
    };
}tcon_tcon7_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon7_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon7_vend:12;
    };
}tcon_tcon7_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon7_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon7_across_ctrl3_reset:1;
        RBus_UInt32  tcon7_mode:3;
        RBus_UInt32  tcon7_en:1;
        RBus_UInt32  tcon7_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon7_frame_tog_en:1;
        RBus_UInt32  tcon7_comb:3;
    };
}tcon_tcon7_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon7_across_frame_int:1;
        RBus_UInt32  tcon7_across_ctrl3_rp:12;
        RBus_UInt32  tcon7_frame_hl_num:4;
        RBus_UInt32  tcon7_across_ctrl3_hp:12;
    };
}tcon_tcon7_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon7_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon7_frame_period:12;
    };
}tcon_tcon7_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_frame_hl:16;
        RBus_UInt32  tcon7_l_flag_prime:16;
    };
}tcon_tcon7_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon7_hoffset_shift_en:1;
        RBus_UInt32  tcon7_hoffset_shift_thd:12;
        RBus_UInt32  tcon7_hoffset_shift_value:6;
    };
}tcon_tcon7_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_8:3;
        RBus_UInt32  tcon8_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon8_hend:13;
    };
}tcon_tcon8_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon8_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon8_vend:12;
    };
}tcon_tcon8_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon8_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon8_across_ctrl3_reset:1;
        RBus_UInt32  tcon8_mode:3;
        RBus_UInt32  tcon8_en:1;
        RBus_UInt32  tcon8_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon8_frame_tog_en:1;
        RBus_UInt32  tcon8_comb:3;
    };
}tcon_tcon8_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon8_across_frame_int:1;
        RBus_UInt32  tcon8_across_ctrl3_rp:12;
        RBus_UInt32  tcon8_frame_hl_num:4;
        RBus_UInt32  tcon8_across_ctrl3_hp:12;
    };
}tcon_tcon8_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon8_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon8_frame_period:12;
    };
}tcon_tcon8_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_frame_hl:16;
        RBus_UInt32  tcon8_l_flag_prime:16;
    };
}tcon_tcon8_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon8_hoffset_shift_en:1;
        RBus_UInt32  tcon8_hoffset_shift_thd:12;
        RBus_UInt32  tcon8_hoffset_shift_value:6;
    };
}tcon_tcon8_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_9:3;
        RBus_UInt32  tcon9_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon9_hend:13;
    };
}tcon_tcon9_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon9_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon9_vend:12;
    };
}tcon_tcon9_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon9_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon9_across_ctrl3_reset:1;
        RBus_UInt32  tcon9_mode:3;
        RBus_UInt32  tcon9_en:1;
        RBus_UInt32  tcon9_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon9_frame_tog_en:1;
        RBus_UInt32  tcon9_comb:3;
    };
}tcon_tcon9_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon9_across_frame_int:1;
        RBus_UInt32  tcon9_across_ctrl3_rp:12;
        RBus_UInt32  tcon9_frame_hl_num:4;
        RBus_UInt32  tcon9_across_ctrl3_hp:12;
    };
}tcon_tcon9_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon9_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon9_frame_period:12;
    };
}tcon_tcon9_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_frame_hl:16;
        RBus_UInt32  tcon9_l_flag_prime:16;
    };
}tcon_tcon9_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon9_hoffset_shift_en:1;
        RBus_UInt32  tcon9_hoffset_shift_thd:12;
        RBus_UInt32  tcon9_hoffset_shift_value:6;
    };
}tcon_tcon9_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf0_en_n:1;
        RBus_UInt32  dreg_dbuf0_read_sel:1;
        RBus_UInt32  dreg_dbuf0_set:1;
    };
}tcon_double_buffer_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_10:3;
        RBus_UInt32  tcon10_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon10_hend:13;
    };
}tcon_tcon10_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon10_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon10_vend:12;
    };
}tcon_tcon10_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon10_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon10_across_ctrl3_reset:1;
        RBus_UInt32  tcon10_mode:3;
        RBus_UInt32  tcon10_en:1;
        RBus_UInt32  tcon10_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon10_frame_tog_en:1;
        RBus_UInt32  tcon10_comb:3;
    };
}tcon_tcon10_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon10_across_frame_int:1;
        RBus_UInt32  tcon10_across_ctrl3_rp:12;
        RBus_UInt32  tcon10_frame_hl_num:4;
        RBus_UInt32  tcon10_across_ctrl3_hp:12;
    };
}tcon_tcon10_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon10_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon10_frame_period:12;
    };
}tcon_tcon10_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_frame_hl:16;
        RBus_UInt32  tcon10_l_flag_prime:16;
    };
}tcon_tcon10_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon10_hoffset_shift_en:1;
        RBus_UInt32  tcon10_hoffset_shift_thd:12;
        RBus_UInt32  tcon10_hoffset_shift_value:6;
    };
}tcon_tcon10_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf1_en_n:1;
        RBus_UInt32  dreg_dbuf1_read_sel:1;
        RBus_UInt32  dreg_dbuf1_set:1;
    };
}tcon_double_buffer_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_11:3;
        RBus_UInt32  tcon11_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon11_hend:13;
    };
}tcon_tcon11_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon11_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon11_vend:12;
    };
}tcon_tcon11_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon11_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon11_across_ctrl3_reset:1;
        RBus_UInt32  tcon11_mode:3;
        RBus_UInt32  tcon11_en:1;
        RBus_UInt32  tcon11_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon11_frame_tog_en:1;
        RBus_UInt32  tcon11_comb:3;
    };
}tcon_tcon11_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon11_across_frame_int:1;
        RBus_UInt32  tcon11_across_ctrl3_rp:12;
        RBus_UInt32  tcon11_frame_hl_num:4;
        RBus_UInt32  tcon11_across_ctrl3_hp:12;
    };
}tcon_tcon11_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon11_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon11_frame_period:12;
    };
}tcon_tcon11_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_frame_hl:16;
        RBus_UInt32  tcon11_l_flag_prime:16;
    };
}tcon_tcon11_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon11_hoffset_shift_en:1;
        RBus_UInt32  tcon11_hoffset_shift_thd:12;
        RBus_UInt32  tcon11_hoffset_shift_value:6;
    };
}tcon_tcon11_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_12:3;
        RBus_UInt32  tcon12_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon12_hend:13;
    };
}tcon_tcon12_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon12_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon12_vend:12;
    };
}tcon_tcon12_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon12_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon12_across_ctrl3_reset:1;
        RBus_UInt32  tcon12_mode:3;
        RBus_UInt32  tcon12_en:1;
        RBus_UInt32  tcon12_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon12_frame_tog_en:1;
        RBus_UInt32  tcon12_comb:3;
    };
}tcon_tcon12_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon12_across_frame_int:1;
        RBus_UInt32  tcon12_across_ctrl3_rp:12;
        RBus_UInt32  tcon12_frame_hl_num:4;
        RBus_UInt32  tcon12_across_ctrl3_hp:12;
    };
}tcon_tcon12_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon12_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon12_frame_period:12;
    };
}tcon_tcon12_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_frame_hl:16;
        RBus_UInt32  tcon12_l_flag_prime:16;
    };
}tcon_tcon12_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon12_hoffset_shift_en:1;
        RBus_UInt32  tcon12_hoffset_shift_thd:12;
        RBus_UInt32  tcon12_hoffset_shift_value:6;
    };
}tcon_tcon12_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf2_en_n:1;
        RBus_UInt32  dreg_dbuf2_read_sel:1;
        RBus_UInt32  dreg_dbuf2_set:1;
    };
}tcon_double_buffer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_13:3;
        RBus_UInt32  tcon13_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon13_hend:13;
    };
}tcon_tcon13_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon13_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon13_vend:12;
    };
}tcon_tcon13_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon13_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon13_across_ctrl3_reset:1;
        RBus_UInt32  tcon13_mode:3;
        RBus_UInt32  tcon13_en:1;
        RBus_UInt32  tcon13_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon13_frame_tog_en:1;
        RBus_UInt32  tcon13_comb:3;
    };
}tcon_tcon13_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon13_across_frame_int:1;
        RBus_UInt32  tcon13_across_ctrl3_rp:12;
        RBus_UInt32  tcon13_frame_hl_num:4;
        RBus_UInt32  tcon13_across_ctrl3_hp:12;
    };
}tcon_tcon13_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon13_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon13_frame_period:12;
    };
}tcon_tcon13_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_frame_hl:16;
        RBus_UInt32  tcon13_l_flag_prime:16;
    };
}tcon_tcon13_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon13_hoffset_shift_en:1;
        RBus_UInt32  tcon13_hoffset_shift_thd:12;
        RBus_UInt32  tcon13_hoffset_shift_value:6;
    };
}tcon_tcon13_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_14:3;
        RBus_UInt32  tcon14_hstart:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon14_hend:13;
    };
}tcon_tcon14_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon14_vstart:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon14_vend:12;
    };
}tcon_tcon14_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tcon14_l_flag_sel:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon14_across_ctrl3_reset:1;
        RBus_UInt32  tcon14_mode:3;
        RBus_UInt32  tcon14_en:1;
        RBus_UInt32  tcon14_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tcon14_frame_tog_en:1;
        RBus_UInt32  tcon14_comb:3;
    };
}tcon_tcon14_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon14_across_frame_int:1;
        RBus_UInt32  tcon14_across_ctrl3_rp:12;
        RBus_UInt32  tcon14_frame_hl_num:4;
        RBus_UInt32  tcon14_across_ctrl3_hp:12;
    };
}tcon_tcon14_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon14_frame_offset:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tcon14_frame_period:12;
    };
}tcon_tcon14_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_frame_hl:16;
        RBus_UInt32  tcon14_l_flag_prime:16;
    };
}tcon_tcon14_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tcon14_hoffset_shift_en:1;
        RBus_UInt32  tcon14_hoffset_shift_thd:12;
        RBus_UInt32  tcon14_hoffset_shift_value:6;
    };
}tcon_tcon14_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon0_nosscg_en:1;
        RBus_UInt32  tcon0_sel:1;
        RBus_UInt32  tcon0_no_sscg_inv:1;
        RBus_UInt32  tcon0_last_trig_en:1;
        RBus_UInt32  tcon0_no_sscg_mode:1;
        RBus_UInt32  tcon0_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon0_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_no_sscg_start:16;
        RBus_UInt32  tcon0_no_sscg_end:16;
    };
}tcon_tcon0_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon1_nosscg_en:1;
        RBus_UInt32  tcon1_sel:1;
        RBus_UInt32  tcon1_no_sscg_inv:1;
        RBus_UInt32  tcon1_last_trig_en:1;
        RBus_UInt32  tcon1_no_sscg_mode:1;
        RBus_UInt32  tcon1_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon1_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_no_sscg_start:16;
        RBus_UInt32  tcon1_no_sscg_end:16;
    };
}tcon_tcon1_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon2_nosscg_en:1;
        RBus_UInt32  tcon2_sel:1;
        RBus_UInt32  tcon2_no_sscg_inv:1;
        RBus_UInt32  tcon2_last_trig_en:1;
        RBus_UInt32  tcon2_no_sscg_mode:1;
        RBus_UInt32  tcon2_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon2_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_no_sscg_start:16;
        RBus_UInt32  tcon2_no_sscg_end:16;
    };
}tcon_tcon2_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon3_nosscg_en:1;
        RBus_UInt32  tcon3_sel:1;
        RBus_UInt32  tcon3_no_sscg_inv:1;
        RBus_UInt32  tcon3_last_trig_en:1;
        RBus_UInt32  tcon3_no_sscg_mode:1;
        RBus_UInt32  tcon3_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon3_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_no_sscg_start:16;
        RBus_UInt32  tcon3_no_sscg_end:16;
    };
}tcon_tcon3_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon4_nosscg_en:1;
        RBus_UInt32  tcon4_sel:1;
        RBus_UInt32  tcon4_no_sscg_inv:1;
        RBus_UInt32  tcon4_last_trig_en:1;
        RBus_UInt32  tcon4_no_sscg_mode:1;
        RBus_UInt32  tcon4_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon4_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_no_sscg_start:16;
        RBus_UInt32  tcon4_no_sscg_end:16;
    };
}tcon_tcon4_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon5_nosscg_en:1;
        RBus_UInt32  tcon5_sel:1;
        RBus_UInt32  tcon5_no_sscg_inv:1;
        RBus_UInt32  tcon5_last_trig_en:1;
        RBus_UInt32  tcon5_no_sscg_mode:1;
        RBus_UInt32  tcon5_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon5_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_no_sscg_start:16;
        RBus_UInt32  tcon5_no_sscg_end:16;
    };
}tcon_tcon5_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon6_nosscg_en:1;
        RBus_UInt32  tcon6_sel:1;
        RBus_UInt32  tcon6_no_sscg_inv:1;
        RBus_UInt32  tcon6_last_trig_en:1;
        RBus_UInt32  tcon6_no_sscg_mode:1;
        RBus_UInt32  tcon6_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon6_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_no_sscg_start:16;
        RBus_UInt32  tcon6_no_sscg_end:16;
    };
}tcon_tcon6_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon7_nosscg_en:1;
        RBus_UInt32  tcon7_sel:1;
        RBus_UInt32  tcon7_no_sscg_inv:1;
        RBus_UInt32  tcon7_last_trig_en:1;
        RBus_UInt32  tcon7_no_sscg_mode:1;
        RBus_UInt32  tcon7_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon7_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_no_sscg_start:16;
        RBus_UInt32  tcon7_no_sscg_end:16;
    };
}tcon_tcon7_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon8_nosscg_en:1;
        RBus_UInt32  tcon8_sel:1;
        RBus_UInt32  tcon8_no_sscg_inv:1;
        RBus_UInt32  tcon8_last_trig_en:1;
        RBus_UInt32  tcon8_no_sscg_mode:1;
        RBus_UInt32  tcon8_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon8_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_no_sscg_start:16;
        RBus_UInt32  tcon8_no_sscg_end:16;
    };
}tcon_tcon8_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon9_nosscg_en:1;
        RBus_UInt32  tcon9_sel:1;
        RBus_UInt32  tcon9_no_sscg_inv:1;
        RBus_UInt32  tcon9_last_trig_en:1;
        RBus_UInt32  tcon9_no_sscg_mode:1;
        RBus_UInt32  tcon9_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon9_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_no_sscg_start:16;
        RBus_UInt32  tcon9_no_sscg_end:16;
    };
}tcon_tcon9_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon10_nosscg_en:1;
        RBus_UInt32  tcon10_sel:1;
        RBus_UInt32  tcon10_no_sscg_inv:1;
        RBus_UInt32  tcon10_last_trig_en:1;
        RBus_UInt32  tcon10_no_sscg_mode:1;
        RBus_UInt32  tcon10_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon10_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_no_sscg_start:16;
        RBus_UInt32  tcon10_no_sscg_end:16;
    };
}tcon_tcon10_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon11_nosscg_en:1;
        RBus_UInt32  tcon11_sel:1;
        RBus_UInt32  tcon11_no_sscg_inv:1;
        RBus_UInt32  tcon11_last_trig_en:1;
        RBus_UInt32  tcon11_no_sscg_mode:1;
        RBus_UInt32  tcon11_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon11_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_no_sscg_start:16;
        RBus_UInt32  tcon11_no_sscg_end:16;
    };
}tcon_tcon11_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon12_nosscg_en:1;
        RBus_UInt32  tcon12_sel:1;
        RBus_UInt32  tcon12_no_sscg_inv:1;
        RBus_UInt32  tcon12_last_trig_en:1;
        RBus_UInt32  tcon12_no_sscg_mode:1;
        RBus_UInt32  tcon12_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon12_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_no_sscg_start:16;
        RBus_UInt32  tcon12_no_sscg_end:16;
    };
}tcon_tcon12_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon13_nosscg_en:1;
        RBus_UInt32  tcon13_sel:1;
        RBus_UInt32  tcon13_no_sscg_inv:1;
        RBus_UInt32  tcon13_last_trig_en:1;
        RBus_UInt32  tcon13_no_sscg_mode:1;
        RBus_UInt32  tcon13_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon13_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_no_sscg_start:16;
        RBus_UInt32  tcon13_no_sscg_end:16;
    };
}tcon_tcon13_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tcon14_nosscg_en:1;
        RBus_UInt32  tcon14_sel:1;
        RBus_UInt32  tcon14_no_sscg_inv:1;
        RBus_UInt32  tcon14_last_trig_en:1;
        RBus_UInt32  tcon14_no_sscg_mode:1;
        RBus_UInt32  tcon14_no_sscg_ctl:3;
        RBus_UInt32  res2:16;
    };
}tcon_tcon14_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_no_sscg_start:16;
        RBus_UInt32  tcon14_no_sscg_end:16;
    };
}tcon_tcon14_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  tcon_en:1;
    };
}tcon_tcon_ip_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf3_en_n:1;
        RBus_UInt32  dreg_dbuf3_read_sel:1;
        RBus_UInt32  dreg_dbuf3_set:1;
    };
}tcon_double_buffer_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf4_en_n:1;
        RBus_UInt32  dreg_dbuf4_read_sel:1;
        RBus_UInt32  dreg_dbuf4_set:1;
    };
}tcon_double_buffer_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf5_en_n:1;
        RBus_UInt32  dreg_dbuf5_read_sel:1;
        RBus_UInt32  dreg_dbuf5_set:1;
    };
}tcon_double_buffer_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf6_en_n:1;
        RBus_UInt32  dreg_dbuf6_read_sel:1;
        RBus_UInt32  dreg_dbuf6_set:1;
    };
}tcon_double_buffer_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dreg_dbuf7_en_n:1;
        RBus_UInt32  dreg_dbuf7_read_sel:1;
        RBus_UInt32  dreg_dbuf7_set:1;
    };
}tcon_double_buffer_ctrl7_RBUS;

#else //apply LITTLE_ENDIAN

//======TCON register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_output:15;
        RBus_UInt32  res1:15;
        RBus_UInt32  tcon_across_frame_en:1;
        RBus_UInt32  tcon_no_sscg_clk_sel:1;
    };
}tcon_tcon_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon0_hstart:13;
        RBus_UInt32  dummy_0:3;
    };
}tcon_tcon0_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon0_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon0_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_comb:3;
        RBus_UInt32  tcon0_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon0_inv:1;
        RBus_UInt32  tcon0_en:1;
        RBus_UInt32  tcon0_mode:3;
        RBus_UInt32  tcon0_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon0_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_across_ctrl3_hp:12;
        RBus_UInt32  tcon0_frame_hl_num:4;
        RBus_UInt32  tcon0_across_ctrl3_rp:12;
        RBus_UInt32  tcon0_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon0_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon0_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon0_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_l_flag_prime:16;
        RBus_UInt32  tcon0_frame_hl:16;
    };
}tcon_tcon0_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_hoffset_shift_value:6;
        RBus_UInt32  tcon0_hoffset_shift_thd:12;
        RBus_UInt32  tcon0_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon0_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon1_hstart:13;
        RBus_UInt32  dummy_1:3;
    };
}tcon_tcon1_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon1_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon1_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_comb:3;
        RBus_UInt32  tcon1_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon1_inv:1;
        RBus_UInt32  tcon1_en:1;
        RBus_UInt32  tcon1_mode:3;
        RBus_UInt32  tcon1_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon1_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_across_ctrl3_hp:12;
        RBus_UInt32  tcon1_frame_hl_num:4;
        RBus_UInt32  tcon1_across_ctrl3_rp:12;
        RBus_UInt32  tcon1_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon1_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon1_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon1_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_l_flag_prime:16;
        RBus_UInt32  tcon1_frame_hl:16;
    };
}tcon_tcon1_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_hoffset_shift_value:6;
        RBus_UInt32  tcon1_hoffset_shift_thd:12;
        RBus_UInt32  tcon1_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon1_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon2_hstart:13;
        RBus_UInt32  dummy_2:3;
    };
}tcon_tcon2_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon2_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon2_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_comb:3;
        RBus_UInt32  tcon2_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon2_inv:1;
        RBus_UInt32  tcon2_en:1;
        RBus_UInt32  tcon2_mode:3;
        RBus_UInt32  tcon2_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon2_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_across_ctrl3_hp:12;
        RBus_UInt32  tcon2_frame_hl_num:4;
        RBus_UInt32  tcon2_across_ctrl3_rp:12;
        RBus_UInt32  tcon2_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon2_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon2_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon2_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_l_flag_prime:16;
        RBus_UInt32  tcon2_frame_hl:16;
    };
}tcon_tcon2_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_hoffset_shift_value:6;
        RBus_UInt32  tcon2_hoffset_shift_thd:12;
        RBus_UInt32  tcon2_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon2_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon3_hstart:13;
        RBus_UInt32  dummy_3:3;
    };
}tcon_tcon3_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon3_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon3_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_comb:3;
        RBus_UInt32  tcon3_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon3_inv:1;
        RBus_UInt32  tcon3_en:1;
        RBus_UInt32  tcon3_mode:3;
        RBus_UInt32  tcon3_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon3_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_across_ctrl3_hp:12;
        RBus_UInt32  tcon3_frame_hl_num:4;
        RBus_UInt32  tcon3_across_ctrl3_rp:12;
        RBus_UInt32  tcon3_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon3_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon3_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon3_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_l_flag_prime:16;
        RBus_UInt32  tcon3_frame_hl:16;
    };
}tcon_tcon3_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_hoffset_shift_value:6;
        RBus_UInt32  tcon3_hoffset_shift_thd:12;
        RBus_UInt32  tcon3_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon3_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon4_hstart:13;
        RBus_UInt32  dummy_4:3;
    };
}tcon_tcon4_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon4_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon4_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_comb:3;
        RBus_UInt32  tcon4_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon4_inv:1;
        RBus_UInt32  tcon4_en:1;
        RBus_UInt32  tcon4_mode:3;
        RBus_UInt32  tcon4_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon4_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_across_ctrl3_hp:12;
        RBus_UInt32  tcon4_frame_hl_num:4;
        RBus_UInt32  tcon4_across_ctrl3_rp:12;
        RBus_UInt32  tcon4_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon4_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon4_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon4_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_l_flag_prime:16;
        RBus_UInt32  tcon4_frame_hl:16;
    };
}tcon_tcon4_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_hoffset_shift_value:6;
        RBus_UInt32  tcon4_hoffset_shift_thd:12;
        RBus_UInt32  tcon4_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon4_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon5_hstart:13;
        RBus_UInt32  dummy_5:3;
    };
}tcon_tcon5_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon5_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon5_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_comb:3;
        RBus_UInt32  tcon5_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon5_inv:1;
        RBus_UInt32  tcon5_en:1;
        RBus_UInt32  tcon5_mode:3;
        RBus_UInt32  tcon5_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon5_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon5_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_across_ctrl3_hp:12;
        RBus_UInt32  tcon5_frame_hl_num:4;
        RBus_UInt32  tcon5_across_ctrl3_rp:12;
        RBus_UInt32  tcon5_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon5_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon5_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon5_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_l_flag_prime:16;
        RBus_UInt32  tcon5_frame_hl:16;
    };
}tcon_tcon5_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_hoffset_shift_value:6;
        RBus_UInt32  tcon5_hoffset_shift_thd:12;
        RBus_UInt32  tcon5_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon5_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon6_hstart:13;
        RBus_UInt32  dummy_6:3;
    };
}tcon_tcon6_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon6_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon6_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_comb:3;
        RBus_UInt32  tcon6_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon6_inv:1;
        RBus_UInt32  tcon6_en:1;
        RBus_UInt32  tcon6_mode:3;
        RBus_UInt32  tcon6_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon6_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon6_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_across_ctrl3_hp:12;
        RBus_UInt32  tcon6_frame_hl_num:4;
        RBus_UInt32  tcon6_across_ctrl3_rp:12;
        RBus_UInt32  tcon6_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon6_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon6_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon6_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_l_flag_prime:16;
        RBus_UInt32  tcon6_frame_hl:16;
    };
}tcon_tcon6_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_hoffset_shift_value:6;
        RBus_UInt32  tcon6_hoffset_shift_thd:12;
        RBus_UInt32  tcon6_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon6_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon7_hstart:13;
        RBus_UInt32  dummy_7:3;
    };
}tcon_tcon7_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon7_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon7_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_comb:3;
        RBus_UInt32  tcon7_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon7_inv:1;
        RBus_UInt32  tcon7_en:1;
        RBus_UInt32  tcon7_mode:3;
        RBus_UInt32  tcon7_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon7_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon7_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_across_ctrl3_hp:12;
        RBus_UInt32  tcon7_frame_hl_num:4;
        RBus_UInt32  tcon7_across_ctrl3_rp:12;
        RBus_UInt32  tcon7_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon7_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon7_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon7_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_l_flag_prime:16;
        RBus_UInt32  tcon7_frame_hl:16;
    };
}tcon_tcon7_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_hoffset_shift_value:6;
        RBus_UInt32  tcon7_hoffset_shift_thd:12;
        RBus_UInt32  tcon7_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon7_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon8_hstart:13;
        RBus_UInt32  dummy_8:3;
    };
}tcon_tcon8_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon8_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon8_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_comb:3;
        RBus_UInt32  tcon8_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon8_inv:1;
        RBus_UInt32  tcon8_en:1;
        RBus_UInt32  tcon8_mode:3;
        RBus_UInt32  tcon8_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon8_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon8_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_across_ctrl3_hp:12;
        RBus_UInt32  tcon8_frame_hl_num:4;
        RBus_UInt32  tcon8_across_ctrl3_rp:12;
        RBus_UInt32  tcon8_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon8_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon8_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon8_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_l_flag_prime:16;
        RBus_UInt32  tcon8_frame_hl:16;
    };
}tcon_tcon8_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_hoffset_shift_value:6;
        RBus_UInt32  tcon8_hoffset_shift_thd:12;
        RBus_UInt32  tcon8_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon8_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon9_hstart:13;
        RBus_UInt32  dummy_9:3;
    };
}tcon_tcon9_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon9_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon9_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_comb:3;
        RBus_UInt32  tcon9_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon9_inv:1;
        RBus_UInt32  tcon9_en:1;
        RBus_UInt32  tcon9_mode:3;
        RBus_UInt32  tcon9_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon9_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon9_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_across_ctrl3_hp:12;
        RBus_UInt32  tcon9_frame_hl_num:4;
        RBus_UInt32  tcon9_across_ctrl3_rp:12;
        RBus_UInt32  tcon9_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon9_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon9_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon9_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_l_flag_prime:16;
        RBus_UInt32  tcon9_frame_hl:16;
    };
}tcon_tcon9_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_hoffset_shift_value:6;
        RBus_UInt32  tcon9_hoffset_shift_thd:12;
        RBus_UInt32  tcon9_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon9_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf0_set:1;
        RBus_UInt32  dreg_dbuf0_read_sel:1;
        RBus_UInt32  dreg_dbuf0_en_n:1;
        RBus_UInt32  res1:29;
    };
}tcon_double_buffer_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon10_hstart:13;
        RBus_UInt32  dummy_10:3;
    };
}tcon_tcon10_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon10_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon10_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_comb:3;
        RBus_UInt32  tcon10_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon10_inv:1;
        RBus_UInt32  tcon10_en:1;
        RBus_UInt32  tcon10_mode:3;
        RBus_UInt32  tcon10_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon10_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon10_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_across_ctrl3_hp:12;
        RBus_UInt32  tcon10_frame_hl_num:4;
        RBus_UInt32  tcon10_across_ctrl3_rp:12;
        RBus_UInt32  tcon10_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon10_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon10_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon10_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_l_flag_prime:16;
        RBus_UInt32  tcon10_frame_hl:16;
    };
}tcon_tcon10_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_hoffset_shift_value:6;
        RBus_UInt32  tcon10_hoffset_shift_thd:12;
        RBus_UInt32  tcon10_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon10_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf1_set:1;
        RBus_UInt32  dreg_dbuf1_read_sel:1;
        RBus_UInt32  dreg_dbuf1_en_n:1;
        RBus_UInt32  res1:29;
    };
}tcon_double_buffer_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon11_hstart:13;
        RBus_UInt32  dummy_11:3;
    };
}tcon_tcon11_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon11_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon11_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_comb:3;
        RBus_UInt32  tcon11_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon11_inv:1;
        RBus_UInt32  tcon11_en:1;
        RBus_UInt32  tcon11_mode:3;
        RBus_UInt32  tcon11_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon11_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon11_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_across_ctrl3_hp:12;
        RBus_UInt32  tcon11_frame_hl_num:4;
        RBus_UInt32  tcon11_across_ctrl3_rp:12;
        RBus_UInt32  tcon11_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon11_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon11_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon11_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_l_flag_prime:16;
        RBus_UInt32  tcon11_frame_hl:16;
    };
}tcon_tcon11_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_hoffset_shift_value:6;
        RBus_UInt32  tcon11_hoffset_shift_thd:12;
        RBus_UInt32  tcon11_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon11_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon12_hstart:13;
        RBus_UInt32  dummy_12:3;
    };
}tcon_tcon12_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon12_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon12_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_comb:3;
        RBus_UInt32  tcon12_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon12_inv:1;
        RBus_UInt32  tcon12_en:1;
        RBus_UInt32  tcon12_mode:3;
        RBus_UInt32  tcon12_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon12_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon12_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_across_ctrl3_hp:12;
        RBus_UInt32  tcon12_frame_hl_num:4;
        RBus_UInt32  tcon12_across_ctrl3_rp:12;
        RBus_UInt32  tcon12_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon12_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon12_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon12_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_l_flag_prime:16;
        RBus_UInt32  tcon12_frame_hl:16;
    };
}tcon_tcon12_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_hoffset_shift_value:6;
        RBus_UInt32  tcon12_hoffset_shift_thd:12;
        RBus_UInt32  tcon12_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon12_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf2_set:1;
        RBus_UInt32  dreg_dbuf2_read_sel:1;
        RBus_UInt32  dreg_dbuf2_en_n:1;
        RBus_UInt32  res1:29;
    };
}tcon_double_buffer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon13_hstart:13;
        RBus_UInt32  dummy_13:3;
    };
}tcon_tcon13_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon13_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon13_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_comb:3;
        RBus_UInt32  tcon13_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon13_inv:1;
        RBus_UInt32  tcon13_en:1;
        RBus_UInt32  tcon13_mode:3;
        RBus_UInt32  tcon13_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon13_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon13_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_across_ctrl3_hp:12;
        RBus_UInt32  tcon13_frame_hl_num:4;
        RBus_UInt32  tcon13_across_ctrl3_rp:12;
        RBus_UInt32  tcon13_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon13_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon13_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon13_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_l_flag_prime:16;
        RBus_UInt32  tcon13_frame_hl:16;
    };
}tcon_tcon13_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_hoffset_shift_value:6;
        RBus_UInt32  tcon13_hoffset_shift_thd:12;
        RBus_UInt32  tcon13_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon13_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_hend:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tcon14_hstart:13;
        RBus_UInt32  dummy_14:3;
    };
}tcon_tcon14_hse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_vend:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon14_vstart:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon14_vse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_comb:3;
        RBus_UInt32  tcon14_frame_tog_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tcon14_inv:1;
        RBus_UInt32  tcon14_en:1;
        RBus_UInt32  tcon14_mode:3;
        RBus_UInt32  tcon14_across_ctrl3_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tcon14_l_flag_sel:5;
        RBus_UInt32  res3:14;
    };
}tcon_tcon14_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_across_ctrl3_hp:12;
        RBus_UInt32  tcon14_frame_hl_num:4;
        RBus_UInt32  tcon14_across_ctrl3_rp:12;
        RBus_UInt32  tcon14_across_frame_int:1;
        RBus_UInt32  res1:3;
    };
}tcon_tcon14_across_line_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_frame_period:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tcon14_frame_offset:12;
        RBus_UInt32  res2:4;
    };
}tcon_tcon14_across_frame_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_l_flag_prime:16;
        RBus_UInt32  tcon14_frame_hl:16;
    };
}tcon_tcon14_frame_hl_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_hoffset_shift_value:6;
        RBus_UInt32  tcon14_hoffset_shift_thd:12;
        RBus_UInt32  tcon14_hoffset_shift_en:1;
        RBus_UInt32  res1:13;
    };
}tcon_tcon14_h_offset_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon0_no_sscg_ctl:3;
        RBus_UInt32  tcon0_no_sscg_mode:1;
        RBus_UInt32  tcon0_last_trig_en:1;
        RBus_UInt32  tcon0_no_sscg_inv:1;
        RBus_UInt32  tcon0_sel:1;
        RBus_UInt32  tcon0_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon0_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon0_no_sscg_end:16;
        RBus_UInt32  tcon0_no_sscg_start:16;
    };
}tcon_tcon0_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon1_no_sscg_ctl:3;
        RBus_UInt32  tcon1_no_sscg_mode:1;
        RBus_UInt32  tcon1_last_trig_en:1;
        RBus_UInt32  tcon1_no_sscg_inv:1;
        RBus_UInt32  tcon1_sel:1;
        RBus_UInt32  tcon1_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon1_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon1_no_sscg_end:16;
        RBus_UInt32  tcon1_no_sscg_start:16;
    };
}tcon_tcon1_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon2_no_sscg_ctl:3;
        RBus_UInt32  tcon2_no_sscg_mode:1;
        RBus_UInt32  tcon2_last_trig_en:1;
        RBus_UInt32  tcon2_no_sscg_inv:1;
        RBus_UInt32  tcon2_sel:1;
        RBus_UInt32  tcon2_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon2_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon2_no_sscg_end:16;
        RBus_UInt32  tcon2_no_sscg_start:16;
    };
}tcon_tcon2_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon3_no_sscg_ctl:3;
        RBus_UInt32  tcon3_no_sscg_mode:1;
        RBus_UInt32  tcon3_last_trig_en:1;
        RBus_UInt32  tcon3_no_sscg_inv:1;
        RBus_UInt32  tcon3_sel:1;
        RBus_UInt32  tcon3_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon3_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon3_no_sscg_end:16;
        RBus_UInt32  tcon3_no_sscg_start:16;
    };
}tcon_tcon3_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon4_no_sscg_ctl:3;
        RBus_UInt32  tcon4_no_sscg_mode:1;
        RBus_UInt32  tcon4_last_trig_en:1;
        RBus_UInt32  tcon4_no_sscg_inv:1;
        RBus_UInt32  tcon4_sel:1;
        RBus_UInt32  tcon4_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon4_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon4_no_sscg_end:16;
        RBus_UInt32  tcon4_no_sscg_start:16;
    };
}tcon_tcon4_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon5_no_sscg_ctl:3;
        RBus_UInt32  tcon5_no_sscg_mode:1;
        RBus_UInt32  tcon5_last_trig_en:1;
        RBus_UInt32  tcon5_no_sscg_inv:1;
        RBus_UInt32  tcon5_sel:1;
        RBus_UInt32  tcon5_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon5_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon5_no_sscg_end:16;
        RBus_UInt32  tcon5_no_sscg_start:16;
    };
}tcon_tcon5_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon6_no_sscg_ctl:3;
        RBus_UInt32  tcon6_no_sscg_mode:1;
        RBus_UInt32  tcon6_last_trig_en:1;
        RBus_UInt32  tcon6_no_sscg_inv:1;
        RBus_UInt32  tcon6_sel:1;
        RBus_UInt32  tcon6_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon6_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon6_no_sscg_end:16;
        RBus_UInt32  tcon6_no_sscg_start:16;
    };
}tcon_tcon6_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon7_no_sscg_ctl:3;
        RBus_UInt32  tcon7_no_sscg_mode:1;
        RBus_UInt32  tcon7_last_trig_en:1;
        RBus_UInt32  tcon7_no_sscg_inv:1;
        RBus_UInt32  tcon7_sel:1;
        RBus_UInt32  tcon7_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon7_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon7_no_sscg_end:16;
        RBus_UInt32  tcon7_no_sscg_start:16;
    };
}tcon_tcon7_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon8_no_sscg_ctl:3;
        RBus_UInt32  tcon8_no_sscg_mode:1;
        RBus_UInt32  tcon8_last_trig_en:1;
        RBus_UInt32  tcon8_no_sscg_inv:1;
        RBus_UInt32  tcon8_sel:1;
        RBus_UInt32  tcon8_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon8_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon8_no_sscg_end:16;
        RBus_UInt32  tcon8_no_sscg_start:16;
    };
}tcon_tcon8_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon9_no_sscg_ctl:3;
        RBus_UInt32  tcon9_no_sscg_mode:1;
        RBus_UInt32  tcon9_last_trig_en:1;
        RBus_UInt32  tcon9_no_sscg_inv:1;
        RBus_UInt32  tcon9_sel:1;
        RBus_UInt32  tcon9_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon9_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon9_no_sscg_end:16;
        RBus_UInt32  tcon9_no_sscg_start:16;
    };
}tcon_tcon9_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon10_no_sscg_ctl:3;
        RBus_UInt32  tcon10_no_sscg_mode:1;
        RBus_UInt32  tcon10_last_trig_en:1;
        RBus_UInt32  tcon10_no_sscg_inv:1;
        RBus_UInt32  tcon10_sel:1;
        RBus_UInt32  tcon10_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon10_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon10_no_sscg_end:16;
        RBus_UInt32  tcon10_no_sscg_start:16;
    };
}tcon_tcon10_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon11_no_sscg_ctl:3;
        RBus_UInt32  tcon11_no_sscg_mode:1;
        RBus_UInt32  tcon11_last_trig_en:1;
        RBus_UInt32  tcon11_no_sscg_inv:1;
        RBus_UInt32  tcon11_sel:1;
        RBus_UInt32  tcon11_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon11_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon11_no_sscg_end:16;
        RBus_UInt32  tcon11_no_sscg_start:16;
    };
}tcon_tcon11_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon12_no_sscg_ctl:3;
        RBus_UInt32  tcon12_no_sscg_mode:1;
        RBus_UInt32  tcon12_last_trig_en:1;
        RBus_UInt32  tcon12_no_sscg_inv:1;
        RBus_UInt32  tcon12_sel:1;
        RBus_UInt32  tcon12_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon12_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon12_no_sscg_end:16;
        RBus_UInt32  tcon12_no_sscg_start:16;
    };
}tcon_tcon12_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon13_no_sscg_ctl:3;
        RBus_UInt32  tcon13_no_sscg_mode:1;
        RBus_UInt32  tcon13_last_trig_en:1;
        RBus_UInt32  tcon13_no_sscg_inv:1;
        RBus_UInt32  tcon13_sel:1;
        RBus_UInt32  tcon13_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon13_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon13_no_sscg_end:16;
        RBus_UInt32  tcon13_no_sscg_start:16;
    };
}tcon_tcon13_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tcon14_no_sscg_ctl:3;
        RBus_UInt32  tcon14_no_sscg_mode:1;
        RBus_UInt32  tcon14_last_trig_en:1;
        RBus_UInt32  tcon14_no_sscg_inv:1;
        RBus_UInt32  tcon14_sel:1;
        RBus_UInt32  tcon14_nosscg_en:1;
        RBus_UInt32  res2:8;
    };
}tcon_tcon14_no_sscg_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon14_no_sscg_end:16;
        RBus_UInt32  tcon14_no_sscg_start:16;
    };
}tcon_tcon14_no_sscg_se_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_en:1;
        RBus_UInt32  res1:31;
    };
}tcon_tcon_ip_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf3_set:1;
        RBus_UInt32  dreg_dbuf3_read_sel:1;
        RBus_UInt32  dreg_dbuf3_en_n:1;
        RBus_UInt32  res1:29;
    };
}tcon_double_buffer_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf4_set:1;
        RBus_UInt32  dreg_dbuf4_read_sel:1;
        RBus_UInt32  dreg_dbuf4_en_n:1;
        RBus_UInt32  res1:29;
    };
}tcon_double_buffer_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf5_set:1;
        RBus_UInt32  dreg_dbuf5_read_sel:1;
        RBus_UInt32  dreg_dbuf5_en_n:1;
        RBus_UInt32  res1:29;
    };
}tcon_double_buffer_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf6_set:1;
        RBus_UInt32  dreg_dbuf6_read_sel:1;
        RBus_UInt32  dreg_dbuf6_en_n:1;
        RBus_UInt32  res1:29;
    };
}tcon_double_buffer_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dreg_dbuf7_set:1;
        RBus_UInt32  dreg_dbuf7_read_sel:1;
        RBus_UInt32  dreg_dbuf7_en_n:1;
        RBus_UInt32  res1:29;
    };
}tcon_double_buffer_ctrl7_RBUS;




#endif 


#endif 
