/**
* @file Mac5-DesignSpec-RNG
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_RNG_REG_H_
#define _RBUS_RNG_REG_H_

#include "rbus_types.h"



//  RNG Register Address
#define  RNG_ctrl                                                                0x18001800
#define  RNG_ctrl_reg_addr                                                       "0xB8001800"
#define  RNG_ctrl_reg                                                            0xB8001800
#define  RNG_ctrl_inst_addr                                                      "0x0000"
#define  set_RNG_ctrl_reg(data)                                                  (*((volatile unsigned int*)RNG_ctrl_reg)=data)
#define  get_RNG_ctrl_reg                                                        (*((volatile unsigned int*)RNG_ctrl_reg))
#define  RNG_ctrl_lfsr_bypass_1_shift                                            (16)
#define  RNG_ctrl_dbg1_sel_shift                                                 (12)
#define  RNG_ctrl_dbg0_sel_shift                                                 (8)
#define  RNG_ctrl_reg_pwr_clk_gate_en_shift                                      (6)
#define  RNG_ctrl_corrector_imode_shift                                          (5)
#define  RNG_ctrl_lfsr_bypass_0_shift                                            (4)
#define  RNG_ctrl_rng_cali_srst_shift                                            (3)
#define  RNG_ctrl_corrector_bypass_shift                                         (2)
#define  RNG_ctrl_clk_hf_sel_shift                                               (1)
#define  RNG_ctrl_rng_srst_shift                                                 (0)
#define  RNG_ctrl_lfsr_bypass_1_mask                                             (0x00010000)
#define  RNG_ctrl_dbg1_sel_mask                                                  (0x0000F000)
#define  RNG_ctrl_dbg0_sel_mask                                                  (0x00000F00)
#define  RNG_ctrl_reg_pwr_clk_gate_en_mask                                       (0x00000040)
#define  RNG_ctrl_corrector_imode_mask                                           (0x00000020)
#define  RNG_ctrl_lfsr_bypass_0_mask                                             (0x00000010)
#define  RNG_ctrl_rng_cali_srst_mask                                             (0x00000008)
#define  RNG_ctrl_corrector_bypass_mask                                          (0x00000004)
#define  RNG_ctrl_clk_hf_sel_mask                                                (0x00000002)
#define  RNG_ctrl_rng_srst_mask                                                  (0x00000001)
#define  RNG_ctrl_lfsr_bypass_1(data)                                            (0x00010000&((data)<<16))
#define  RNG_ctrl_dbg1_sel(data)                                                 (0x0000F000&((data)<<12))
#define  RNG_ctrl_dbg0_sel(data)                                                 (0x00000F00&((data)<<8))
#define  RNG_ctrl_reg_pwr_clk_gate_en(data)                                      (0x00000040&((data)<<6))
#define  RNG_ctrl_corrector_imode(data)                                          (0x00000020&((data)<<5))
#define  RNG_ctrl_lfsr_bypass_0(data)                                            (0x00000010&((data)<<4))
#define  RNG_ctrl_rng_cali_srst(data)                                            (0x00000008&((data)<<3))
#define  RNG_ctrl_corrector_bypass(data)                                         (0x00000004&((data)<<2))
#define  RNG_ctrl_clk_hf_sel(data)                                               (0x00000002&((data)<<1))
#define  RNG_ctrl_rng_srst(data)                                                 (0x00000001&(data))
#define  RNG_ctrl_get_lfsr_bypass_1(data)                                        ((0x00010000&(data))>>16)
#define  RNG_ctrl_get_dbg1_sel(data)                                             ((0x0000F000&(data))>>12)
#define  RNG_ctrl_get_dbg0_sel(data)                                             ((0x00000F00&(data))>>8)
#define  RNG_ctrl_get_reg_pwr_clk_gate_en(data)                                  ((0x00000040&(data))>>6)
#define  RNG_ctrl_get_corrector_imode(data)                                      ((0x00000020&(data))>>5)
#define  RNG_ctrl_get_lfsr_bypass_0(data)                                        ((0x00000010&(data))>>4)
#define  RNG_ctrl_get_rng_cali_srst(data)                                        ((0x00000008&(data))>>3)
#define  RNG_ctrl_get_corrector_bypass(data)                                     ((0x00000004&(data))>>2)
#define  RNG_ctrl_get_clk_hf_sel(data)                                           ((0x00000002&(data))>>1)
#define  RNG_ctrl_get_rng_srst(data)                                             (0x00000001&(data))

#define  RNG_return0                                                             0x18001804
#define  RNG_return0_reg_addr                                                    "0xB8001804"
#define  RNG_return0_reg                                                         0xB8001804
#define  RNG_return0_inst_addr                                                   "0x0001"
#define  set_RNG_return0_reg(data)                                               (*((volatile unsigned int*)RNG_return0_reg)=data)
#define  get_RNG_return0_reg                                                     (*((volatile unsigned int*)RNG_return0_reg))
#define  RNG_return0_reach_full_shift                                            (1)
#define  RNG_return0_out_ready_shift                                             (0)
#define  RNG_return0_reach_full_mask                                             (0x00000002)
#define  RNG_return0_out_ready_mask                                              (0x00000001)
#define  RNG_return0_reach_full(data)                                            (0x00000002&((data)<<1))
#define  RNG_return0_out_ready(data)                                             (0x00000001&(data))
#define  RNG_return0_get_reach_full(data)                                        ((0x00000002&(data))>>1)
#define  RNG_return0_get_out_ready(data)                                         (0x00000001&(data))

#define  RNG_return1                                                             0x18001808
#define  RNG_return1_reg_addr                                                    "0xB8001808"
#define  RNG_return1_reg                                                         0xB8001808
#define  RNG_return1_inst_addr                                                   "0x0002"
#define  set_RNG_return1_reg(data)                                               (*((volatile unsigned int*)RNG_return1_reg)=data)
#define  get_RNG_return1_reg                                                     (*((volatile unsigned int*)RNG_return1_reg))
#define  RNG_return1_valid_bit_num_shift                                         (0)
#define  RNG_return1_valid_bit_num_mask                                          (0xFFFFFFFF)
#define  RNG_return1_valid_bit_num(data)                                         (0xFFFFFFFF&(data))
#define  RNG_return1_get_valid_bit_num(data)                                     (0xFFFFFFFF&(data))

#define  RNG_return2                                                             0x1800180C
#define  RNG_return2_reg_addr                                                    "0xB800180C"
#define  RNG_return2_reg                                                         0xB800180C
#define  RNG_return2_inst_addr                                                   "0x0003"
#define  set_RNG_return2_reg(data)                                               (*((volatile unsigned int*)RNG_return2_reg)=data)
#define  get_RNG_return2_reg                                                     (*((volatile unsigned int*)RNG_return2_reg))
#define  RNG_return2_drop_num_shift                                              (0)
#define  RNG_return2_drop_num_mask                                               (0xFFFFFFFF)
#define  RNG_return2_drop_num(data)                                              (0xFFFFFFFF&(data))
#define  RNG_return2_get_drop_num(data)                                          (0xFFFFFFFF&(data))

#define  RNG_resultn                                                             0x18001810
#define  RNG_resultn_reg_addr                                                    "0xB8001810"
#define  RNG_resultn_reg                                                         0xB8001810
#define  RNG_resultn_inst_addr                                                   "0x0004"
#define  set_RNG_resultn_reg(data)                                               (*((volatile unsigned int*)RNG_resultn_reg)=data)
#define  get_RNG_resultn_reg                                                     (*((volatile unsigned int*)RNG_resultn_reg))
#define  RNG_resultn_random_out_shift                                            (0)
#define  RNG_resultn_random_out_mask                                             (0xFFFFFFFF)
#define  RNG_resultn_random_out(data)                                            (0xFFFFFFFF&(data))
#define  RNG_resultn_get_random_out(data)                                        (0xFFFFFFFF&(data))

#define  RNG_analog                                                              0x18001814
#define  RNG_analog_reg_addr                                                     "0xB8001814"
#define  RNG_analog_reg                                                          0xB8001814
#define  RNG_analog_inst_addr                                                    "0x0005"
#define  set_RNG_analog_reg(data)                                                (*((volatile unsigned int*)RNG_analog_reg)=data)
#define  get_RNG_analog_reg                                                      (*((volatile unsigned int*)RNG_analog_reg))
#define  RNG_analog_rosc_d_shift                                                 (12)
#define  RNG_analog_rosc_res_shift                                               (10)
#define  RNG_analog_rosc_div_shift                                               (8)
#define  RNG_analog_rosc_gain_shift                                              (6)
#define  RNG_analog_rosc_fs_shift                                                (4)
#define  RNG_analog_rosc_test_shift                                              (1)
#define  RNG_analog_rosc_pow_shift                                               (0)
#define  RNG_analog_rosc_d_mask                                                  (0x0000F000)
#define  RNG_analog_rosc_res_mask                                                (0x00000C00)
#define  RNG_analog_rosc_div_mask                                                (0x00000300)
#define  RNG_analog_rosc_gain_mask                                               (0x000000C0)
#define  RNG_analog_rosc_fs_mask                                                 (0x00000030)
#define  RNG_analog_rosc_test_mask                                               (0x00000002)
#define  RNG_analog_rosc_pow_mask                                                (0x00000001)
#define  RNG_analog_rosc_d(data)                                                 (0x0000F000&((data)<<12))
#define  RNG_analog_rosc_res(data)                                               (0x00000C00&((data)<<10))
#define  RNG_analog_rosc_div(data)                                               (0x00000300&((data)<<8))
#define  RNG_analog_rosc_gain(data)                                              (0x000000C0&((data)<<6))
#define  RNG_analog_rosc_fs(data)                                                (0x00000030&((data)<<4))
#define  RNG_analog_rosc_test(data)                                              (0x00000002&((data)<<1))
#define  RNG_analog_rosc_pow(data)                                               (0x00000001&(data))
#define  RNG_analog_get_rosc_d(data)                                             ((0x0000F000&(data))>>12)
#define  RNG_analog_get_rosc_res(data)                                           ((0x00000C00&(data))>>10)
#define  RNG_analog_get_rosc_div(data)                                           ((0x00000300&(data))>>8)
#define  RNG_analog_get_rosc_gain(data)                                          ((0x000000C0&(data))>>6)
#define  RNG_analog_get_rosc_fs(data)                                            ((0x00000030&(data))>>4)
#define  RNG_analog_get_rosc_test(data)                                          ((0x00000002&(data))>>1)
#define  RNG_analog_get_rosc_pow(data)                                           (0x00000001&(data))

#define  RNG_cali_chk                                                            0x18001818
#define  RNG_cali_chk_reg_addr                                                   "0xB8001818"
#define  RNG_cali_chk_reg                                                        0xB8001818
#define  RNG_cali_chk_inst_addr                                                  "0x0006"
#define  set_RNG_cali_chk_reg(data)                                              (*((volatile unsigned int*)RNG_cali_chk_reg)=data)
#define  get_RNG_cali_chk_reg                                                    (*((volatile unsigned int*)RNG_cali_chk_reg))
#define  RNG_cali_chk_prd_ub_shift                                               (16)
#define  RNG_cali_chk_prd_lb_shift                                               (0)
#define  RNG_cali_chk_prd_ub_mask                                                (0xFFFF0000)
#define  RNG_cali_chk_prd_lb_mask                                                (0x0000FFFF)
#define  RNG_cali_chk_prd_ub(data)                                               (0xFFFF0000&((data)<<16))
#define  RNG_cali_chk_prd_lb(data)                                               (0x0000FFFF&(data))
#define  RNG_cali_chk_get_prd_ub(data)                                           ((0xFFFF0000&(data))>>16)
#define  RNG_cali_chk_get_prd_lb(data)                                           (0x0000FFFF&(data))

#define  RNG_cali_ctrl                                                           0x1800181C
#define  RNG_cali_ctrl_reg_addr                                                  "0xB800181C"
#define  RNG_cali_ctrl_reg                                                       0xB800181C
#define  RNG_cali_ctrl_inst_addr                                                 "0x0007"
#define  set_RNG_cali_ctrl_reg(data)                                             (*((volatile unsigned int*)RNG_cali_ctrl_reg)=data)
#define  get_RNG_cali_ctrl_reg                                                   (*((volatile unsigned int*)RNG_cali_ctrl_reg))
#define  RNG_cali_ctrl_shot_num_shift                                            (20)
#define  RNG_cali_ctrl_cyc_num_shift                                             (17)
#define  RNG_cali_ctrl_wait_num_shift                                            (12)
#define  RNG_cali_ctrl_dummy_opt_shift                                           (9)
#define  RNG_cali_ctrl_trig_num_shift                                            (4)
#define  RNG_cali_ctrl_lock_shift                                                (3)
#define  RNG_cali_ctrl_shot_mode_shift                                           (2)
#define  RNG_cali_ctrl_pol_shift                                                 (1)
#define  RNG_cali_ctrl_hw_en_shift                                               (0)
#define  RNG_cali_ctrl_shot_num_mask                                             (0xFFF00000)
#define  RNG_cali_ctrl_cyc_num_mask                                              (0x000E0000)
#define  RNG_cali_ctrl_wait_num_mask                                             (0x0001F000)
#define  RNG_cali_ctrl_dummy_opt_mask                                            (0x00000E00)
#define  RNG_cali_ctrl_trig_num_mask                                             (0x000001F0)
#define  RNG_cali_ctrl_lock_mask                                                 (0x00000008)
#define  RNG_cali_ctrl_shot_mode_mask                                            (0x00000004)
#define  RNG_cali_ctrl_pol_mask                                                  (0x00000002)
#define  RNG_cali_ctrl_hw_en_mask                                                (0x00000001)
#define  RNG_cali_ctrl_shot_num(data)                                            (0xFFF00000&((data)<<20))
#define  RNG_cali_ctrl_cyc_num(data)                                             (0x000E0000&((data)<<17))
#define  RNG_cali_ctrl_wait_num(data)                                            (0x0001F000&((data)<<12))
#define  RNG_cali_ctrl_dummy_opt(data)                                           (0x00000E00&((data)<<9))
#define  RNG_cali_ctrl_trig_num(data)                                            (0x000001F0&((data)<<4))
#define  RNG_cali_ctrl_lock(data)                                                (0x00000008&((data)<<3))
#define  RNG_cali_ctrl_shot_mode(data)                                           (0x00000004&((data)<<2))
#define  RNG_cali_ctrl_pol(data)                                                 (0x00000002&((data)<<1))
#define  RNG_cali_ctrl_hw_en(data)                                               (0x00000001&(data))
#define  RNG_cali_ctrl_get_shot_num(data)                                        ((0xFFF00000&(data))>>20)
#define  RNG_cali_ctrl_get_cyc_num(data)                                         ((0x000E0000&(data))>>17)
#define  RNG_cali_ctrl_get_wait_num(data)                                        ((0x0001F000&(data))>>12)
#define  RNG_cali_ctrl_get_dummy_opt(data)                                       ((0x00000E00&(data))>>9)
#define  RNG_cali_ctrl_get_trig_num(data)                                        ((0x000001F0&(data))>>4)
#define  RNG_cali_ctrl_get_lock(data)                                            ((0x00000008&(data))>>3)
#define  RNG_cali_ctrl_get_shot_mode(data)                                       ((0x00000004&(data))>>2)
#define  RNG_cali_ctrl_get_pol(data)                                             ((0x00000002&(data))>>1)
#define  RNG_cali_ctrl_get_hw_en(data)                                           (0x00000001&(data))

#define  RNG_cali_return                                                         0x18001820
#define  RNG_cali_return_reg_addr                                                "0xB8001820"
#define  RNG_cali_return_reg                                                     0xB8001820
#define  RNG_cali_return_inst_addr                                               "0x0008"
#define  set_RNG_cali_return_reg(data)                                           (*((volatile unsigned int*)RNG_cali_return_reg)=data)
#define  get_RNG_cali_return_reg                                                 (*((volatile unsigned int*)RNG_cali_return_reg))
#define  RNG_cali_return_hw_d_shift                                              (20)
#define  RNG_cali_return_rosc_lock_shift                                         (17)
#define  RNG_cali_return_cnt_ovflw_shift                                         (16)
#define  RNG_cali_return_cnt_shift                                               (0)
#define  RNG_cali_return_hw_d_mask                                               (0x00F00000)
#define  RNG_cali_return_rosc_lock_mask                                          (0x00020000)
#define  RNG_cali_return_cnt_ovflw_mask                                          (0x00010000)
#define  RNG_cali_return_cnt_mask                                                (0x0000FFFF)
#define  RNG_cali_return_hw_d(data)                                              (0x00F00000&((data)<<20))
#define  RNG_cali_return_rosc_lock(data)                                         (0x00020000&((data)<<17))
#define  RNG_cali_return_cnt_ovflw(data)                                         (0x00010000&((data)<<16))
#define  RNG_cali_return_cnt(data)                                               (0x0000FFFF&(data))
#define  RNG_cali_return_get_hw_d(data)                                          ((0x00F00000&(data))>>20)
#define  RNG_cali_return_get_rosc_lock(data)                                     ((0x00020000&(data))>>17)
#define  RNG_cali_return_get_cnt_ovflw(data)                                     ((0x00010000&(data))>>16)
#define  RNG_cali_return_get_cnt(data)                                           (0x0000FFFF&(data))

#define  RNG_lock_chk                                                            0x18001824
#define  RNG_lock_chk_reg_addr                                                   "0xB8001824"
#define  RNG_lock_chk_reg                                                        0xB8001824
#define  RNG_lock_chk_inst_addr                                                  "0x0009"
#define  set_RNG_lock_chk_reg(data)                                              (*((volatile unsigned int*)RNG_lock_chk_reg)=data)
#define  get_RNG_lock_chk_reg                                                    (*((volatile unsigned int*)RNG_lock_chk_reg))
#define  RNG_lock_chk_prd_ub_shift                                               (16)
#define  RNG_lock_chk_prd_lb_shift                                               (0)
#define  RNG_lock_chk_prd_ub_mask                                                (0xFFFF0000)
#define  RNG_lock_chk_prd_lb_mask                                                (0x0000FFFF)
#define  RNG_lock_chk_prd_ub(data)                                               (0xFFFF0000&((data)<<16))
#define  RNG_lock_chk_prd_lb(data)                                               (0x0000FFFF&(data))
#define  RNG_lock_chk_get_prd_ub(data)                                           ((0xFFFF0000&(data))>>16)
#define  RNG_lock_chk_get_prd_lb(data)                                           (0x0000FFFF&(data))

#define  RNG_lock_ctrl                                                           0x18001828
#define  RNG_lock_ctrl_reg_addr                                                  "0xB8001828"
#define  RNG_lock_ctrl_reg                                                       0xB8001828
#define  RNG_lock_ctrl_inst_addr                                                 "0x000A"
#define  set_RNG_lock_ctrl_reg(data)                                             (*((volatile unsigned int*)RNG_lock_ctrl_reg)=data)
#define  get_RNG_lock_ctrl_reg                                                   (*((volatile unsigned int*)RNG_lock_ctrl_reg))
#define  RNG_lock_ctrl_exit_num_shift                                            (16)
#define  RNG_lock_ctrl_enter_num_shift                                           (0)
#define  RNG_lock_ctrl_exit_num_mask                                             (0x000F0000)
#define  RNG_lock_ctrl_enter_num_mask                                            (0x0000000F)
#define  RNG_lock_ctrl_exit_num(data)                                            (0x000F0000&((data)<<16))
#define  RNG_lock_ctrl_enter_num(data)                                           (0x0000000F&(data))
#define  RNG_lock_ctrl_get_exit_num(data)                                        ((0x000F0000&(data))>>16)
#define  RNG_lock_ctrl_get_enter_num(data)                                       (0x0000000F&(data))

#define  RNG_return3                                                             0x1800182C
#define  RNG_return3_reg_addr                                                    "0xB800182C"
#define  RNG_return3_reg                                                         0xB800182C
#define  RNG_return3_inst_addr                                                   "0x000B"
#define  set_RNG_return3_reg(data)                                               (*((volatile unsigned int*)RNG_return3_reg)=data)
#define  get_RNG_return3_reg                                                     (*((volatile unsigned int*)RNG_return3_reg))
#define  RNG_return3_reach_full_shift                                            (1)
#define  RNG_return3_out_ready_shift                                             (0)
#define  RNG_return3_reach_full_mask                                             (0x00000002)
#define  RNG_return3_out_ready_mask                                              (0x00000001)
#define  RNG_return3_reach_full(data)                                            (0x00000002&((data)<<1))
#define  RNG_return3_out_ready(data)                                             (0x00000001&(data))
#define  RNG_return3_get_reach_full(data)                                        ((0x00000002&(data))>>1)
#define  RNG_return3_get_out_ready(data)                                         (0x00000001&(data))

#define  RNG_return4                                                             0x18001830
#define  RNG_return4_reg_addr                                                    "0xB8001830"
#define  RNG_return4_reg                                                         0xB8001830
#define  RNG_return4_inst_addr                                                   "0x000C"
#define  set_RNG_return4_reg(data)                                               (*((volatile unsigned int*)RNG_return4_reg)=data)
#define  get_RNG_return4_reg                                                     (*((volatile unsigned int*)RNG_return4_reg))
#define  RNG_return4_valid_bit_num_shift                                         (0)
#define  RNG_return4_valid_bit_num_mask                                          (0xFFFFFFFF)
#define  RNG_return4_valid_bit_num(data)                                         (0xFFFFFFFF&(data))
#define  RNG_return4_get_valid_bit_num(data)                                     (0xFFFFFFFF&(data))

#define  RNG_return5                                                             0x18001834
#define  RNG_return5_reg_addr                                                    "0xB8001834"
#define  RNG_return5_reg                                                         0xB8001834
#define  RNG_return5_inst_addr                                                   "0x000D"
#define  set_RNG_return5_reg(data)                                               (*((volatile unsigned int*)RNG_return5_reg)=data)
#define  get_RNG_return5_reg                                                     (*((volatile unsigned int*)RNG_return5_reg))
#define  RNG_return5_drop_num_shift                                              (0)
#define  RNG_return5_drop_num_mask                                               (0xFFFFFFFF)
#define  RNG_return5_drop_num(data)                                              (0xFFFFFFFF&(data))
#define  RNG_return5_get_drop_num(data)                                          (0xFFFFFFFF&(data))

#define  RNG_resultr                                                             0x18001838
#define  RNG_resultr_reg_addr                                                    "0xB8001838"
#define  RNG_resultr_reg                                                         0xB8001838
#define  RNG_resultr_inst_addr                                                   "0x000E"
#define  set_RNG_resultr_reg(data)                                               (*((volatile unsigned int*)RNG_resultr_reg)=data)
#define  get_RNG_resultr_reg                                                     (*((volatile unsigned int*)RNG_resultr_reg))
#define  RNG_resultr_random_out_shift                                            (0)
#define  RNG_resultr_random_out_mask                                             (0xFFFFFFFF)
#define  RNG_resultr_random_out(data)                                            (0xFFFFFFFF&(data))
#define  RNG_resultr_get_random_out(data)                                        (0xFFFFFFFF&(data))

#define  RNG_fosc_ana                                                            0x1800183C
#define  RNG_fosc_ana_reg_addr                                                   "0xB800183C"
#define  RNG_fosc_ana_reg                                                        0xB800183C
#define  RNG_fosc_ana_inst_addr                                                  "0x000F"
#define  set_RNG_fosc_ana_reg(data)                                              (*((volatile unsigned int*)RNG_fosc_ana_reg)=data)
#define  get_RNG_fosc_ana_reg                                                    (*((volatile unsigned int*)RNG_fosc_ana_reg))
#define  RNG_fosc_ana_sw_s_shift                                                 (12)
#define  RNG_fosc_ana_cap_shift                                                  (10)
#define  RNG_fosc_ana_div_shift                                                  (8)
#define  RNG_fosc_ana_pow_shift                                                  (0)
#define  RNG_fosc_ana_sw_s_mask                                                  (0x0003F000)
#define  RNG_fosc_ana_cap_mask                                                   (0x00000C00)
#define  RNG_fosc_ana_div_mask                                                   (0x00000300)
#define  RNG_fosc_ana_pow_mask                                                   (0x00000001)
#define  RNG_fosc_ana_sw_s(data)                                                 (0x0003F000&((data)<<12))
#define  RNG_fosc_ana_cap(data)                                                  (0x00000C00&((data)<<10))
#define  RNG_fosc_ana_div(data)                                                  (0x00000300&((data)<<8))
#define  RNG_fosc_ana_pow(data)                                                  (0x00000001&(data))
#define  RNG_fosc_ana_get_sw_s(data)                                             ((0x0003F000&(data))>>12)
#define  RNG_fosc_ana_get_cap(data)                                              ((0x00000C00&(data))>>10)
#define  RNG_fosc_ana_get_div(data)                                              ((0x00000300&(data))>>8)
#define  RNG_fosc_ana_get_pow(data)                                              (0x00000001&(data))

#define  RNG_fosc_cali_chk                                                       0x18001840
#define  RNG_fosc_cali_chk_reg_addr                                              "0xB8001840"
#define  RNG_fosc_cali_chk_reg                                                   0xB8001840
#define  RNG_fosc_cali_chk_inst_addr                                             "0x0010"
#define  set_RNG_fosc_cali_chk_reg(data)                                         (*((volatile unsigned int*)RNG_fosc_cali_chk_reg)=data)
#define  get_RNG_fosc_cali_chk_reg                                               (*((volatile unsigned int*)RNG_fosc_cali_chk_reg))
#define  RNG_fosc_cali_chk_prd_ub_shift                                          (16)
#define  RNG_fosc_cali_chk_prd_lb_shift                                          (0)
#define  RNG_fosc_cali_chk_prd_ub_mask                                           (0xFFFF0000)
#define  RNG_fosc_cali_chk_prd_lb_mask                                           (0x0000FFFF)
#define  RNG_fosc_cali_chk_prd_ub(data)                                          (0xFFFF0000&((data)<<16))
#define  RNG_fosc_cali_chk_prd_lb(data)                                          (0x0000FFFF&(data))
#define  RNG_fosc_cali_chk_get_prd_ub(data)                                      ((0xFFFF0000&(data))>>16)
#define  RNG_fosc_cali_chk_get_prd_lb(data)                                      (0x0000FFFF&(data))

#define  RNG_fosc_cali_ctrl                                                      0x18001844
#define  RNG_fosc_cali_ctrl_reg_addr                                             "0xB8001844"
#define  RNG_fosc_cali_ctrl_reg                                                  0xB8001844
#define  RNG_fosc_cali_ctrl_inst_addr                                            "0x0011"
#define  set_RNG_fosc_cali_ctrl_reg(data)                                        (*((volatile unsigned int*)RNG_fosc_cali_ctrl_reg)=data)
#define  get_RNG_fosc_cali_ctrl_reg                                              (*((volatile unsigned int*)RNG_fosc_cali_ctrl_reg))
#define  RNG_fosc_cali_ctrl_shot_num_shift                                       (20)
#define  RNG_fosc_cali_ctrl_cyc_num_shift                                        (17)
#define  RNG_fosc_cali_ctrl_wait_num_shift                                       (12)
#define  RNG_fosc_cali_ctrl_dummy_opt_shift                                      (9)
#define  RNG_fosc_cali_ctrl_trig_num_shift                                       (4)
#define  RNG_fosc_cali_ctrl_lock_shift                                           (3)
#define  RNG_fosc_cali_ctrl_shot_mode_shift                                      (2)
#define  RNG_fosc_cali_ctrl_pol_shift                                            (1)
#define  RNG_fosc_cali_ctrl_hw_en_shift                                          (0)
#define  RNG_fosc_cali_ctrl_shot_num_mask                                        (0xFFF00000)
#define  RNG_fosc_cali_ctrl_cyc_num_mask                                         (0x000E0000)
#define  RNG_fosc_cali_ctrl_wait_num_mask                                        (0x0001F000)
#define  RNG_fosc_cali_ctrl_dummy_opt_mask                                       (0x00000E00)
#define  RNG_fosc_cali_ctrl_trig_num_mask                                        (0x000001F0)
#define  RNG_fosc_cali_ctrl_lock_mask                                            (0x00000008)
#define  RNG_fosc_cali_ctrl_shot_mode_mask                                       (0x00000004)
#define  RNG_fosc_cali_ctrl_pol_mask                                             (0x00000002)
#define  RNG_fosc_cali_ctrl_hw_en_mask                                           (0x00000001)
#define  RNG_fosc_cali_ctrl_shot_num(data)                                       (0xFFF00000&((data)<<20))
#define  RNG_fosc_cali_ctrl_cyc_num(data)                                        (0x000E0000&((data)<<17))
#define  RNG_fosc_cali_ctrl_wait_num(data)                                       (0x0001F000&((data)<<12))
#define  RNG_fosc_cali_ctrl_dummy_opt(data)                                      (0x00000E00&((data)<<9))
#define  RNG_fosc_cali_ctrl_trig_num(data)                                       (0x000001F0&((data)<<4))
#define  RNG_fosc_cali_ctrl_lock(data)                                           (0x00000008&((data)<<3))
#define  RNG_fosc_cali_ctrl_shot_mode(data)                                      (0x00000004&((data)<<2))
#define  RNG_fosc_cali_ctrl_pol(data)                                            (0x00000002&((data)<<1))
#define  RNG_fosc_cali_ctrl_hw_en(data)                                          (0x00000001&(data))
#define  RNG_fosc_cali_ctrl_get_shot_num(data)                                   ((0xFFF00000&(data))>>20)
#define  RNG_fosc_cali_ctrl_get_cyc_num(data)                                    ((0x000E0000&(data))>>17)
#define  RNG_fosc_cali_ctrl_get_wait_num(data)                                   ((0x0001F000&(data))>>12)
#define  RNG_fosc_cali_ctrl_get_dummy_opt(data)                                  ((0x00000E00&(data))>>9)
#define  RNG_fosc_cali_ctrl_get_trig_num(data)                                   ((0x000001F0&(data))>>4)
#define  RNG_fosc_cali_ctrl_get_lock(data)                                       ((0x00000008&(data))>>3)
#define  RNG_fosc_cali_ctrl_get_shot_mode(data)                                  ((0x00000004&(data))>>2)
#define  RNG_fosc_cali_ctrl_get_pol(data)                                        ((0x00000002&(data))>>1)
#define  RNG_fosc_cali_ctrl_get_hw_en(data)                                      (0x00000001&(data))

#define  RNG_fosc_cali_return                                                    0x18001848
#define  RNG_fosc_cali_return_reg_addr                                           "0xB8001848"
#define  RNG_fosc_cali_return_reg                                                0xB8001848
#define  RNG_fosc_cali_return_inst_addr                                          "0x0012"
#define  set_RNG_fosc_cali_return_reg(data)                                      (*((volatile unsigned int*)RNG_fosc_cali_return_reg)=data)
#define  get_RNG_fosc_cali_return_reg                                            (*((volatile unsigned int*)RNG_fosc_cali_return_reg))
#define  RNG_fosc_cali_return_hw_s_shift                                         (20)
#define  RNG_fosc_cali_return_rosc_lock_shift                                    (17)
#define  RNG_fosc_cali_return_cnt_ovflw_shift                                    (16)
#define  RNG_fosc_cali_return_cnt_shift                                          (0)
#define  RNG_fosc_cali_return_hw_s_mask                                          (0x03F00000)
#define  RNG_fosc_cali_return_rosc_lock_mask                                     (0x00020000)
#define  RNG_fosc_cali_return_cnt_ovflw_mask                                     (0x00010000)
#define  RNG_fosc_cali_return_cnt_mask                                           (0x0000FFFF)
#define  RNG_fosc_cali_return_hw_s(data)                                         (0x03F00000&((data)<<20))
#define  RNG_fosc_cali_return_rosc_lock(data)                                    (0x00020000&((data)<<17))
#define  RNG_fosc_cali_return_cnt_ovflw(data)                                    (0x00010000&((data)<<16))
#define  RNG_fosc_cali_return_cnt(data)                                          (0x0000FFFF&(data))
#define  RNG_fosc_cali_return_get_hw_s(data)                                     ((0x03F00000&(data))>>20)
#define  RNG_fosc_cali_return_get_rosc_lock(data)                                ((0x00020000&(data))>>17)
#define  RNG_fosc_cali_return_get_cnt_ovflw(data)                                ((0x00010000&(data))>>16)
#define  RNG_fosc_cali_return_get_cnt(data)                                      (0x0000FFFF&(data))

#define  RNG_fosc_lock_chk_1                                                     0x1800184C
#define  RNG_fosc_lock_chk_1_reg_addr                                            "0xB800184C"
#define  RNG_fosc_lock_chk_1_reg                                                 0xB800184C
#define  RNG_fosc_lock_chk_1_inst_addr                                           "0x0013"
#define  set_RNG_fosc_lock_chk_1_reg(data)                                       (*((volatile unsigned int*)RNG_fosc_lock_chk_1_reg)=data)
#define  get_RNG_fosc_lock_chk_1_reg                                             (*((volatile unsigned int*)RNG_fosc_lock_chk_1_reg))
#define  RNG_fosc_lock_chk_1_prd_ub_shift                                        (16)
#define  RNG_fosc_lock_chk_1_prd_lb_shift                                        (0)
#define  RNG_fosc_lock_chk_1_prd_ub_mask                                         (0xFFFF0000)
#define  RNG_fosc_lock_chk_1_prd_lb_mask                                         (0x0000FFFF)
#define  RNG_fosc_lock_chk_1_prd_ub(data)                                        (0xFFFF0000&((data)<<16))
#define  RNG_fosc_lock_chk_1_prd_lb(data)                                        (0x0000FFFF&(data))
#define  RNG_fosc_lock_chk_1_get_prd_ub(data)                                    ((0xFFFF0000&(data))>>16)
#define  RNG_fosc_lock_chk_1_get_prd_lb(data)                                    (0x0000FFFF&(data))

#define  RNG_fosc_lock_ctrl                                                      0x18001850
#define  RNG_fosc_lock_ctrl_reg_addr                                             "0xB8001850"
#define  RNG_fosc_lock_ctrl_reg                                                  0xB8001850
#define  RNG_fosc_lock_ctrl_inst_addr                                            "0x0014"
#define  set_RNG_fosc_lock_ctrl_reg(data)                                        (*((volatile unsigned int*)RNG_fosc_lock_ctrl_reg)=data)
#define  get_RNG_fosc_lock_ctrl_reg                                              (*((volatile unsigned int*)RNG_fosc_lock_ctrl_reg))
#define  RNG_fosc_lock_ctrl_range_sel_shift                                      (31)
#define  RNG_fosc_lock_ctrl_exit_num_shift                                       (16)
#define  RNG_fosc_lock_ctrl_enter_num_shift                                      (0)
#define  RNG_fosc_lock_ctrl_range_sel_mask                                       (0x80000000)
#define  RNG_fosc_lock_ctrl_exit_num_mask                                        (0x000F0000)
#define  RNG_fosc_lock_ctrl_enter_num_mask                                       (0x0000000F)
#define  RNG_fosc_lock_ctrl_range_sel(data)                                      (0x80000000&((data)<<31))
#define  RNG_fosc_lock_ctrl_exit_num(data)                                       (0x000F0000&((data)<<16))
#define  RNG_fosc_lock_ctrl_enter_num(data)                                      (0x0000000F&(data))
#define  RNG_fosc_lock_ctrl_get_range_sel(data)                                  ((0x80000000&(data))>>31)
#define  RNG_fosc_lock_ctrl_get_exit_num(data)                                   ((0x000F0000&(data))>>16)
#define  RNG_fosc_lock_ctrl_get_enter_num(data)                                  (0x0000000F&(data))

#define  RNG_fosc_lock_chk_2                                                     0x18001854
#define  RNG_fosc_lock_chk_2_reg_addr                                            "0xB8001854"
#define  RNG_fosc_lock_chk_2_reg                                                 0xB8001854
#define  RNG_fosc_lock_chk_2_inst_addr                                           "0x0015"
#define  set_RNG_fosc_lock_chk_2_reg(data)                                       (*((volatile unsigned int*)RNG_fosc_lock_chk_2_reg)=data)
#define  get_RNG_fosc_lock_chk_2_reg                                             (*((volatile unsigned int*)RNG_fosc_lock_chk_2_reg))
#define  RNG_fosc_lock_chk_2_exit_ub_shift                                       (16)
#define  RNG_fosc_lock_chk_2_exit_lb_shift                                       (0)
#define  RNG_fosc_lock_chk_2_exit_ub_mask                                        (0xFFFF0000)
#define  RNG_fosc_lock_chk_2_exit_lb_mask                                        (0x0000FFFF)
#define  RNG_fosc_lock_chk_2_exit_ub(data)                                       (0xFFFF0000&((data)<<16))
#define  RNG_fosc_lock_chk_2_exit_lb(data)                                       (0x0000FFFF&(data))
#define  RNG_fosc_lock_chk_2_get_exit_ub(data)                                   ((0xFFFF0000&(data))>>16)
#define  RNG_fosc_lock_chk_2_get_exit_lb(data)                                   (0x0000FFFF&(data))

#define  RNG_eip76_ctrl                                                          0x18001858
#define  RNG_eip76_ctrl_reg_addr                                                 "0xB8001858"
#define  RNG_eip76_ctrl_reg                                                      0xB8001858
#define  RNG_eip76_ctrl_inst_addr                                                "0x0016"
#define  set_RNG_eip76_ctrl_reg(data)                                            (*((volatile unsigned int*)RNG_eip76_ctrl_reg)=data)
#define  get_RNG_eip76_ctrl_reg                                                  (*((volatile unsigned int*)RNG_eip76_ctrl_reg))
#define  RNG_eip76_ctrl_mode_shift                                               (20)
#define  RNG_eip76_ctrl_status_mask_shift                                        (12)
#define  RNG_eip76_ctrl_tst_fro_select_shift                                     (4)
#define  RNG_eip76_ctrl_tst_fro_iddq_shift                                       (3)
#define  RNG_eip76_ctrl_tst_fro_ctrl_en_shift                                    (2)
#define  RNG_eip76_ctrl_tst_fro_enable_shift                                     (1)
#define  RNG_eip76_ctrl_tst_fro_delay_shift                                      (0)
#define  RNG_eip76_ctrl_mode_mask                                                (0x00100000)
#define  RNG_eip76_ctrl_status_mask_mask                                         (0x000FF000)
#define  RNG_eip76_ctrl_tst_fro_select_mask                                      (0x000001F0)
#define  RNG_eip76_ctrl_tst_fro_iddq_mask                                        (0x00000008)
#define  RNG_eip76_ctrl_tst_fro_ctrl_en_mask                                     (0x00000004)
#define  RNG_eip76_ctrl_tst_fro_enable_mask                                      (0x00000002)
#define  RNG_eip76_ctrl_tst_fro_delay_mask                                       (0x00000001)
#define  RNG_eip76_ctrl_mode(data)                                               (0x00100000&((data)<<20))
#define  RNG_eip76_ctrl_status_mask(data)                                        (0x000FF000&((data)<<12))
#define  RNG_eip76_ctrl_tst_fro_select(data)                                     (0x000001F0&((data)<<4))
#define  RNG_eip76_ctrl_tst_fro_iddq(data)                                       (0x00000008&((data)<<3))
#define  RNG_eip76_ctrl_tst_fro_ctrl_en(data)                                    (0x00000004&((data)<<2))
#define  RNG_eip76_ctrl_tst_fro_enable(data)                                     (0x00000002&((data)<<1))
#define  RNG_eip76_ctrl_tst_fro_delay(data)                                      (0x00000001&(data))
#define  RNG_eip76_ctrl_get_mode(data)                                           ((0x00100000&(data))>>20)
#define  RNG_eip76_ctrl_get_status_mask(data)                                    ((0x000FF000&(data))>>12)
#define  RNG_eip76_ctrl_get_tst_fro_select(data)                                 ((0x000001F0&(data))>>4)
#define  RNG_eip76_ctrl_get_tst_fro_iddq(data)                                   ((0x00000008&(data))>>3)
#define  RNG_eip76_ctrl_get_tst_fro_ctrl_en(data)                                ((0x00000004&(data))>>2)
#define  RNG_eip76_ctrl_get_tst_fro_enable(data)                                 ((0x00000002&(data))>>1)
#define  RNG_eip76_ctrl_get_tst_fro_delay(data)                                  (0x00000001&(data))

#define  RNG_return6                                                             0x1800185C
#define  RNG_return6_reg_addr                                                    "0xB800185C"
#define  RNG_return6_reg                                                         0xB800185C
#define  RNG_return6_inst_addr                                                   "0x0017"
#define  set_RNG_return6_reg(data)                                               (*((volatile unsigned int*)RNG_return6_reg)=data)
#define  get_RNG_return6_reg                                                     (*((volatile unsigned int*)RNG_return6_reg))
#define  RNG_return6_bufr_cnt_shift                                              (16)
#define  RNG_return6_bufn_cnt_shift                                              (0)
#define  RNG_return6_bufr_cnt_mask                                               (0x00070000)
#define  RNG_return6_bufn_cnt_mask                                               (0x0000001F)
#define  RNG_return6_bufr_cnt(data)                                              (0x00070000&((data)<<16))
#define  RNG_return6_bufn_cnt(data)                                              (0x0000001F&(data))
#define  RNG_return6_get_bufr_cnt(data)                                          ((0x00070000&(data))>>16)
#define  RNG_return6_get_bufn_cnt(data)                                          (0x0000001F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======RNG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  lfsr_bypass_1:1;
        RBus_UInt32  dbg1_sel:4;
        RBus_UInt32  dbg0_sel:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_pwr_clk_gate_en:1;
        RBus_UInt32  corrector_imode:1;
        RBus_UInt32  lfsr_bypass_0:1;
        RBus_UInt32  rng_cali_srst:1;
        RBus_UInt32  corrector_bypass:1;
        RBus_UInt32  clk_hf_sel:1;
        RBus_UInt32  rng_srst:1;
    };
}rng_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  reach_full:1;
        RBus_UInt32  out_ready:1;
    };
}rng_return0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_bit_num:32;
    };
}rng_return1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drop_num:32;
    };
}rng_return2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  random_out:32;
    };
}rng_resultn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rosc_d:4;
        RBus_UInt32  rosc_res:2;
        RBus_UInt32  rosc_div:2;
        RBus_UInt32  rosc_gain:2;
        RBus_UInt32  rosc_fs:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  rosc_test:1;
        RBus_UInt32  rosc_pow:1;
    };
}rng_analog_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prd_ub:16;
        RBus_UInt32  prd_lb:16;
    };
}rng_cali_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shot_num:12;
        RBus_UInt32  cyc_num:3;
        RBus_UInt32  wait_num:5;
        RBus_UInt32  dummy_opt:3;
        RBus_UInt32  trig_num:5;
        RBus_UInt32  lock:1;
        RBus_UInt32  shot_mode:1;
        RBus_UInt32  pol:1;
        RBus_UInt32  hw_en:1;
    };
}rng_cali_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hw_d:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  rosc_lock:1;
        RBus_UInt32  cnt_ovflw:1;
        RBus_UInt32  cnt:16;
    };
}rng_cali_return_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prd_ub:16;
        RBus_UInt32  prd_lb:16;
    };
}rng_lock_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  exit_num:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  enter_num:4;
    };
}rng_lock_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  reach_full:1;
        RBus_UInt32  out_ready:1;
    };
}rng_return3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_bit_num:32;
    };
}rng_return4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drop_num:32;
    };
}rng_return5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  random_out:32;
    };
}rng_resultr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  sw_s:6;
        RBus_UInt32  cap:2;
        RBus_UInt32  div:2;
        RBus_UInt32  res2:7;
        RBus_UInt32  pow:1;
    };
}rng_fosc_ana_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prd_ub:16;
        RBus_UInt32  prd_lb:16;
    };
}rng_fosc_cali_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shot_num:12;
        RBus_UInt32  cyc_num:3;
        RBus_UInt32  wait_num:5;
        RBus_UInt32  dummy_opt:3;
        RBus_UInt32  trig_num:5;
        RBus_UInt32  lock:1;
        RBus_UInt32  shot_mode:1;
        RBus_UInt32  pol:1;
        RBus_UInt32  hw_en:1;
    };
}rng_fosc_cali_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  hw_s:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rosc_lock:1;
        RBus_UInt32  cnt_ovflw:1;
        RBus_UInt32  cnt:16;
    };
}rng_fosc_cali_return_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prd_ub:16;
        RBus_UInt32  prd_lb:16;
    };
}rng_fosc_lock_chk_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  range_sel:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  exit_num:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  enter_num:4;
    };
}rng_fosc_lock_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  exit_ub:16;
        RBus_UInt32  exit_lb:16;
    };
}rng_fosc_lock_chk_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mode:1;
        RBus_UInt32  status_mask:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  tst_fro_select:5;
        RBus_UInt32  tst_fro_iddq:1;
        RBus_UInt32  tst_fro_ctrl_en:1;
        RBus_UInt32  tst_fro_enable:1;
        RBus_UInt32  tst_fro_delay:1;
    };
}rng_eip76_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  bufr_cnt:3;
        RBus_UInt32  res2:11;
        RBus_UInt32  bufn_cnt:5;
    };
}rng_return6_RBUS;

#else //apply LITTLE_ENDIAN

//======RNG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rng_srst:1;
        RBus_UInt32  clk_hf_sel:1;
        RBus_UInt32  corrector_bypass:1;
        RBus_UInt32  rng_cali_srst:1;
        RBus_UInt32  lfsr_bypass_0:1;
        RBus_UInt32  corrector_imode:1;
        RBus_UInt32  reg_pwr_clk_gate_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dbg0_sel:4;
        RBus_UInt32  dbg1_sel:4;
        RBus_UInt32  lfsr_bypass_1:1;
        RBus_UInt32  res2:15;
    };
}rng_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out_ready:1;
        RBus_UInt32  reach_full:1;
        RBus_UInt32  res1:30;
    };
}rng_return0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_bit_num:32;
    };
}rng_return1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drop_num:32;
    };
}rng_return2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  random_out:32;
    };
}rng_resultn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rosc_pow:1;
        RBus_UInt32  rosc_test:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rosc_fs:2;
        RBus_UInt32  rosc_gain:2;
        RBus_UInt32  rosc_div:2;
        RBus_UInt32  rosc_res:2;
        RBus_UInt32  rosc_d:4;
        RBus_UInt32  res2:16;
    };
}rng_analog_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prd_lb:16;
        RBus_UInt32  prd_ub:16;
    };
}rng_cali_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_en:1;
        RBus_UInt32  pol:1;
        RBus_UInt32  shot_mode:1;
        RBus_UInt32  lock:1;
        RBus_UInt32  trig_num:5;
        RBus_UInt32  dummy_opt:3;
        RBus_UInt32  wait_num:5;
        RBus_UInt32  cyc_num:3;
        RBus_UInt32  shot_num:12;
    };
}rng_cali_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:16;
        RBus_UInt32  cnt_ovflw:1;
        RBus_UInt32  rosc_lock:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  hw_d:4;
        RBus_UInt32  res2:8;
    };
}rng_cali_return_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prd_lb:16;
        RBus_UInt32  prd_ub:16;
    };
}rng_lock_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enter_num:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  exit_num:4;
        RBus_UInt32  res2:12;
    };
}rng_lock_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out_ready:1;
        RBus_UInt32  reach_full:1;
        RBus_UInt32  res1:30;
    };
}rng_return3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_bit_num:32;
    };
}rng_return4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drop_num:32;
    };
}rng_return5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  random_out:32;
    };
}rng_resultr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pow:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  div:2;
        RBus_UInt32  cap:2;
        RBus_UInt32  sw_s:6;
        RBus_UInt32  res2:14;
    };
}rng_fosc_ana_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prd_lb:16;
        RBus_UInt32  prd_ub:16;
    };
}rng_fosc_cali_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_en:1;
        RBus_UInt32  pol:1;
        RBus_UInt32  shot_mode:1;
        RBus_UInt32  lock:1;
        RBus_UInt32  trig_num:5;
        RBus_UInt32  dummy_opt:3;
        RBus_UInt32  wait_num:5;
        RBus_UInt32  cyc_num:3;
        RBus_UInt32  shot_num:12;
    };
}rng_fosc_cali_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:16;
        RBus_UInt32  cnt_ovflw:1;
        RBus_UInt32  rosc_lock:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  hw_s:6;
        RBus_UInt32  res2:6;
    };
}rng_fosc_cali_return_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prd_lb:16;
        RBus_UInt32  prd_ub:16;
    };
}rng_fosc_lock_chk_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enter_num:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  exit_num:4;
        RBus_UInt32  res2:11;
        RBus_UInt32  range_sel:1;
    };
}rng_fosc_lock_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  exit_lb:16;
        RBus_UInt32  exit_ub:16;
    };
}rng_fosc_lock_chk_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tst_fro_delay:1;
        RBus_UInt32  tst_fro_enable:1;
        RBus_UInt32  tst_fro_ctrl_en:1;
        RBus_UInt32  tst_fro_iddq:1;
        RBus_UInt32  tst_fro_select:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  status_mask:8;
        RBus_UInt32  mode:1;
        RBus_UInt32  res2:11;
    };
}rng_eip76_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bufn_cnt:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  bufr_cnt:3;
        RBus_UInt32  res2:13;
    };
}rng_return6_RBUS;




#endif 


#endif 
