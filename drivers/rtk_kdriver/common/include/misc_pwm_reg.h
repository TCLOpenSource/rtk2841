/**
* @file rbusMISC_PWMReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MISC_PWM_REG_H_
#define _RBUS_MISC_PWM_REG_H_

#include "rbus_types.h"



//  MISC_PWM Register Address
#define  MISC_PWM_PWM_DB_CTRL                                                    0x1801BC80
#define  MISC_PWM_PWM_DB_CTRL_reg_addr                                           "0xB801BC80"
#define  MISC_PWM_PWM_DB_CTRL_reg                                                0xB801BC80
#define  MISC_PWM_PWM_DB_CTRL_inst_addr                                          "0x0000"
#define  set_MISC_PWM_PWM_DB_CTRL_reg(data)                                      (*((volatile unsigned int*)MISC_PWM_PWM_DB_CTRL_reg)=data)
#define  get_MISC_PWM_PWM_DB_CTRL_reg                                            (*((volatile unsigned int*)MISC_PWM_PWM_DB_CTRL_reg))
#define  MISC_PWM_PWM_DB_CTRL_pwm_w_db_en_shift                                  (31)
#define  MISC_PWM_PWM_DB_CTRL_db_rd_sel_shift                                    (30)
#define  MISC_PWM_PWM_DB_CTRL_pwm_w_db_wr_shift                                  (29)
#define  MISC_PWM_PWM_DB_CTRL_pwm_w_db_mode_shift                                (28)
#define  MISC_PWM_PWM_DB_CTRL_global_delay_en_shift                              (27)
#define  MISC_PWM_PWM_DB_CTRL_db_pulse_sel_shift                                 (26)
#define  MISC_PWM_PWM_DB_CTRL_pwm_w_db_en_mask                                   (0x80000000)
#define  MISC_PWM_PWM_DB_CTRL_db_rd_sel_mask                                     (0x40000000)
#define  MISC_PWM_PWM_DB_CTRL_pwm_w_db_wr_mask                                   (0x20000000)
#define  MISC_PWM_PWM_DB_CTRL_pwm_w_db_mode_mask                                 (0x10000000)
#define  MISC_PWM_PWM_DB_CTRL_global_delay_en_mask                               (0x08000000)
#define  MISC_PWM_PWM_DB_CTRL_db_pulse_sel_mask                                  (0x04000000)
#define  MISC_PWM_PWM_DB_CTRL_pwm_w_db_en(data)                                  (0x80000000&((data)<<31))
#define  MISC_PWM_PWM_DB_CTRL_db_rd_sel(data)                                    (0x40000000&((data)<<30))
#define  MISC_PWM_PWM_DB_CTRL_pwm_w_db_wr(data)                                  (0x20000000&((data)<<29))
#define  MISC_PWM_PWM_DB_CTRL_pwm_w_db_mode(data)                                (0x10000000&((data)<<28))
#define  MISC_PWM_PWM_DB_CTRL_global_delay_en(data)                              (0x08000000&((data)<<27))
#define  MISC_PWM_PWM_DB_CTRL_db_pulse_sel(data)                                 (0x04000000&((data)<<26))
#define  MISC_PWM_PWM_DB_CTRL_get_pwm_w_db_en(data)                              ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM_DB_CTRL_get_db_rd_sel(data)                                ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM_DB_CTRL_get_pwm_w_db_wr(data)                              ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM_DB_CTRL_get_pwm_w_db_mode(data)                            ((0x10000000&(data))>>28)
#define  MISC_PWM_PWM_DB_CTRL_get_global_delay_en(data)                          ((0x08000000&(data))>>27)
#define  MISC_PWM_PWM_DB_CTRL_get_db_pulse_sel(data)                             ((0x04000000&(data))>>26)

#define  MISC_PWM_PWM0_CTRL                                                      0x1801BC84
#define  MISC_PWM_PWM0_CTRL_reg_addr                                             "0xB801BC84"
#define  MISC_PWM_PWM0_CTRL_reg                                                  0xB801BC84
#define  MISC_PWM_PWM0_CTRL_inst_addr                                            "0x0001"
#define  set_MISC_PWM_PWM0_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_PWM_PWM0_CTRL_reg)=data)
#define  get_MISC_PWM_PWM0_CTRL_reg                                              (*((volatile unsigned int*)MISC_PWM_PWM0_CTRL_reg))
#define  MISC_PWM_PWM0_CTRL_pwm0l_shift                                          (31)
#define  MISC_PWM_PWM0_CTRL_pwm0_ck_shift                                        (30)
#define  MISC_PWM_PWM0_CTRL_pwm0_en_shift                                        (29)
#define  MISC_PWM_PWM0_CTRL_pwm0_vs_rst_en_shift                                 (28)
#define  MISC_PWM_PWM0_CTRL_pwm0_dut_8b_shift                                    (27)
#define  MISC_PWM_PWM0_CTRL_pwm0_vs_delay_thr_shift                              (6)
#define  MISC_PWM_PWM0_CTRL_pwm0_vs_delay_en_shift                               (5)
#define  MISC_PWM_PWM0_CTRL_pwm0_dim_duty_en_shift                               (4)
#define  MISC_PWM_PWM0_CTRL_dut0_rounding_en_shift                               (3)
#define  MISC_PWM_PWM0_CTRL_pwm0_width_sel_shift                                 (0)
#define  MISC_PWM_PWM0_CTRL_pwm0l_mask                                           (0x80000000)
#define  MISC_PWM_PWM0_CTRL_pwm0_ck_mask                                         (0x40000000)
#define  MISC_PWM_PWM0_CTRL_pwm0_en_mask                                         (0x20000000)
#define  MISC_PWM_PWM0_CTRL_pwm0_vs_rst_en_mask                                  (0x10000000)
#define  MISC_PWM_PWM0_CTRL_pwm0_dut_8b_mask                                     (0x08000000)
#define  MISC_PWM_PWM0_CTRL_pwm0_vs_delay_thr_mask                               (0x07FFFFC0)
#define  MISC_PWM_PWM0_CTRL_pwm0_vs_delay_en_mask                                (0x00000020)
#define  MISC_PWM_PWM0_CTRL_pwm0_dim_duty_en_mask                                (0x00000010)
#define  MISC_PWM_PWM0_CTRL_dut0_rounding_en_mask                                (0x00000008)
#define  MISC_PWM_PWM0_CTRL_pwm0_width_sel_mask                                  (0x00000001)
#define  MISC_PWM_PWM0_CTRL_pwm0l(data)                                          (0x80000000&((data)<<31))
#define  MISC_PWM_PWM0_CTRL_pwm0_ck(data)                                        (0x40000000&((data)<<30))
#define  MISC_PWM_PWM0_CTRL_pwm0_en(data)                                        (0x20000000&((data)<<29))
#define  MISC_PWM_PWM0_CTRL_pwm0_vs_rst_en(data)                                 (0x10000000&((data)<<28))
#define  MISC_PWM_PWM0_CTRL_pwm0_dut_8b(data)                                    (0x08000000&((data)<<27))
#define  MISC_PWM_PWM0_CTRL_pwm0_vs_delay_thr(data)                              (0x07FFFFC0&((data)<<6))
#define  MISC_PWM_PWM0_CTRL_pwm0_vs_delay_en(data)                               (0x00000020&((data)<<5))
#define  MISC_PWM_PWM0_CTRL_pwm0_dim_duty_en(data)                               (0x00000010&((data)<<4))
#define  MISC_PWM_PWM0_CTRL_dut0_rounding_en(data)                               (0x00000008&((data)<<3))
#define  MISC_PWM_PWM0_CTRL_pwm0_width_sel(data)                                 (0x00000001&(data))
#define  MISC_PWM_PWM0_CTRL_get_pwm0l(data)                                      ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM0_CTRL_get_pwm0_ck(data)                                    ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM0_CTRL_get_pwm0_en(data)                                    ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM0_CTRL_get_pwm0_vs_rst_en(data)                             ((0x10000000&(data))>>28)
#define  MISC_PWM_PWM0_CTRL_get_pwm0_dut_8b(data)                                ((0x08000000&(data))>>27)
#define  MISC_PWM_PWM0_CTRL_get_pwm0_vs_delay_thr(data)                          ((0x07FFFFC0&(data))>>6)
#define  MISC_PWM_PWM0_CTRL_get_pwm0_vs_delay_en(data)                           ((0x00000020&(data))>>5)
#define  MISC_PWM_PWM0_CTRL_get_pwm0_dim_duty_en(data)                           ((0x00000010&(data))>>4)
#define  MISC_PWM_PWM0_CTRL_get_dut0_rounding_en(data)                           ((0x00000008&(data))>>3)
#define  MISC_PWM_PWM0_CTRL_get_pwm0_width_sel(data)                             (0x00000001&(data))

#define  MISC_PWM_PWM0_Timing_CTRL                                               0x1801BC88
#define  MISC_PWM_PWM0_Timing_CTRL_reg_addr                                      "0xB801BC88"
#define  MISC_PWM_PWM0_Timing_CTRL_reg                                           0xB801BC88
#define  MISC_PWM_PWM0_Timing_CTRL_inst_addr                                     "0x0002"
#define  set_MISC_PWM_PWM0_Timing_CTRL_reg(data)                                 (*((volatile unsigned int*)MISC_PWM_PWM0_Timing_CTRL_reg)=data)
#define  get_MISC_PWM_PWM0_Timing_CTRL_reg                                       (*((volatile unsigned int*)MISC_PWM_PWM0_Timing_CTRL_reg))
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_cnt_mode_shift                           (31)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_ck_sel_hs_shift                          (30)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_ck_sel_shift                             (29)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_cycle_max_shift                          (24)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_m_shift                                  (12)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_n_shift                                  (0)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_cnt_mode_mask                            (0x80000000)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_ck_sel_hs_mask                           (0x40000000)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_ck_sel_mask                              (0x20000000)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_cycle_max_mask                           (0x0F000000)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_m_mask                                   (0x00003000)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_n_mask                                   (0x00000FFF)
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_cnt_mode(data)                           (0x80000000&((data)<<31))
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_ck_sel_hs(data)                          (0x40000000&((data)<<30))
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_ck_sel(data)                             (0x20000000&((data)<<29))
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_cycle_max(data)                          (0x0F000000&((data)<<24))
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_m(data)                                  (0x00003000&((data)<<12))
#define  MISC_PWM_PWM0_Timing_CTRL_pwm0_n(data)                                  (0x00000FFF&(data))
#define  MISC_PWM_PWM0_Timing_CTRL_get_pwm0_cnt_mode(data)                       ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM0_Timing_CTRL_get_pwm0_ck_sel_hs(data)                      ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM0_Timing_CTRL_get_pwm0_ck_sel(data)                         ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM0_Timing_CTRL_get_pwm0_cycle_max(data)                      ((0x0F000000&(data))>>24)
#define  MISC_PWM_PWM0_Timing_CTRL_get_pwm0_m(data)                              ((0x00003000&(data))>>12)
#define  MISC_PWM_PWM0_Timing_CTRL_get_pwm0_n(data)                              (0x00000FFF&(data))

#define  MISC_PWM_PWM0_DUTY_SET                                                  0x1801BC8C
#define  MISC_PWM_PWM0_DUTY_SET_reg_addr                                         "0xB801BC8C"
#define  MISC_PWM_PWM0_DUTY_SET_reg                                              0xB801BC8C
#define  MISC_PWM_PWM0_DUTY_SET_inst_addr                                        "0x0003"
#define  set_MISC_PWM_PWM0_DUTY_SET_reg(data)                                    (*((volatile unsigned int*)MISC_PWM_PWM0_DUTY_SET_reg)=data)
#define  get_MISC_PWM_PWM0_DUTY_SET_reg                                          (*((volatile unsigned int*)MISC_PWM_PWM0_DUTY_SET_reg))
#define  MISC_PWM_PWM0_DUTY_SET_pwm0_dut_shift                                   (16)
#define  MISC_PWM_PWM0_DUTY_SET_pwm0_totalcnt_shift                              (0)
#define  MISC_PWM_PWM0_DUTY_SET_pwm0_dut_mask                                    (0x0FFF0000)
#define  MISC_PWM_PWM0_DUTY_SET_pwm0_totalcnt_mask                               (0x00000FFF)
#define  MISC_PWM_PWM0_DUTY_SET_pwm0_dut(data)                                   (0x0FFF0000&((data)<<16))
#define  MISC_PWM_PWM0_DUTY_SET_pwm0_totalcnt(data)                              (0x00000FFF&(data))
#define  MISC_PWM_PWM0_DUTY_SET_get_pwm0_dut(data)                               ((0x0FFF0000&(data))>>16)
#define  MISC_PWM_PWM0_DUTY_SET_get_pwm0_totalcnt(data)                          (0x00000FFF&(data))

#define  MISC_PWM_PWM1_CTRL                                                      0x1801BC90
#define  MISC_PWM_PWM1_CTRL_reg_addr                                             "0xB801BC90"
#define  MISC_PWM_PWM1_CTRL_reg                                                  0xB801BC90
#define  MISC_PWM_PWM1_CTRL_inst_addr                                            "0x0004"
#define  set_MISC_PWM_PWM1_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_PWM_PWM1_CTRL_reg)=data)
#define  get_MISC_PWM_PWM1_CTRL_reg                                              (*((volatile unsigned int*)MISC_PWM_PWM1_CTRL_reg))
#define  MISC_PWM_PWM1_CTRL_pwm1l_shift                                          (31)
#define  MISC_PWM_PWM1_CTRL_pwm1_ck_shift                                        (30)
#define  MISC_PWM_PWM1_CTRL_pwm1_en_shift                                        (29)
#define  MISC_PWM_PWM1_CTRL_pwm1_vs_rst_en_shift                                 (28)
#define  MISC_PWM_PWM1_CTRL_pwm1_dut_8b_shift                                    (27)
#define  MISC_PWM_PWM1_CTRL_pwm1_vs_delay_thr_shift                              (6)
#define  MISC_PWM_PWM1_CTRL_pwm1_vs_delay_en_shift                               (5)
#define  MISC_PWM_PWM1_CTRL_pwm1_dim_duty_en_shift                               (4)
#define  MISC_PWM_PWM1_CTRL_dut1_rounding_en_shift                               (3)
#define  MISC_PWM_PWM1_CTRL_pwm1l_mask                                           (0x80000000)
#define  MISC_PWM_PWM1_CTRL_pwm1_ck_mask                                         (0x40000000)
#define  MISC_PWM_PWM1_CTRL_pwm1_en_mask                                         (0x20000000)
#define  MISC_PWM_PWM1_CTRL_pwm1_vs_rst_en_mask                                  (0x10000000)
#define  MISC_PWM_PWM1_CTRL_pwm1_dut_8b_mask                                     (0x08000000)
#define  MISC_PWM_PWM1_CTRL_pwm1_vs_delay_thr_mask                               (0x07FFFFC0)
#define  MISC_PWM_PWM1_CTRL_pwm1_vs_delay_en_mask                                (0x00000020)
#define  MISC_PWM_PWM1_CTRL_pwm1_dim_duty_en_mask                                (0x00000010)
#define  MISC_PWM_PWM1_CTRL_dut1_rounding_en_mask                                (0x00000008)
#define  MISC_PWM_PWM1_CTRL_pwm1l(data)                                          (0x80000000&((data)<<31))
#define  MISC_PWM_PWM1_CTRL_pwm1_ck(data)                                        (0x40000000&((data)<<30))
#define  MISC_PWM_PWM1_CTRL_pwm1_en(data)                                        (0x20000000&((data)<<29))
#define  MISC_PWM_PWM1_CTRL_pwm1_vs_rst_en(data)                                 (0x10000000&((data)<<28))
#define  MISC_PWM_PWM1_CTRL_pwm1_dut_8b(data)                                    (0x08000000&((data)<<27))
#define  MISC_PWM_PWM1_CTRL_pwm1_vs_delay_thr(data)                              (0x07FFFFC0&((data)<<6))
#define  MISC_PWM_PWM1_CTRL_pwm1_vs_delay_en(data)                               (0x00000020&((data)<<5))
#define  MISC_PWM_PWM1_CTRL_pwm1_dim_duty_en(data)                               (0x00000010&((data)<<4))
#define  MISC_PWM_PWM1_CTRL_dut1_rounding_en(data)                               (0x00000008&((data)<<3))
#define  MISC_PWM_PWM1_CTRL_get_pwm1l(data)                                      ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM1_CTRL_get_pwm1_ck(data)                                    ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM1_CTRL_get_pwm1_en(data)                                    ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM1_CTRL_get_pwm1_vs_rst_en(data)                             ((0x10000000&(data))>>28)
#define  MISC_PWM_PWM1_CTRL_get_pwm1_dut_8b(data)                                ((0x08000000&(data))>>27)
#define  MISC_PWM_PWM1_CTRL_get_pwm1_vs_delay_thr(data)                          ((0x07FFFFC0&(data))>>6)
#define  MISC_PWM_PWM1_CTRL_get_pwm1_vs_delay_en(data)                           ((0x00000020&(data))>>5)
#define  MISC_PWM_PWM1_CTRL_get_pwm1_dim_duty_en(data)                           ((0x00000010&(data))>>4)
#define  MISC_PWM_PWM1_CTRL_get_dut1_rounding_en(data)                           ((0x00000008&(data))>>3)

#define  MISC_PWM_PWM1_Timing_CTRL                                               0x1801BC94
#define  MISC_PWM_PWM1_Timing_CTRL_reg_addr                                      "0xB801BC94"
#define  MISC_PWM_PWM1_Timing_CTRL_reg                                           0xB801BC94
#define  MISC_PWM_PWM1_Timing_CTRL_inst_addr                                     "0x0005"
#define  set_MISC_PWM_PWM1_Timing_CTRL_reg(data)                                 (*((volatile unsigned int*)MISC_PWM_PWM1_Timing_CTRL_reg)=data)
#define  get_MISC_PWM_PWM1_Timing_CTRL_reg                                       (*((volatile unsigned int*)MISC_PWM_PWM1_Timing_CTRL_reg))
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_cnt_mode_shift                           (31)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_ck_sel_hs_shift                          (30)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_ck_sel_shift                             (29)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_cycle_max_shift                          (24)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_m_shift                                  (12)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_n_shift                                  (0)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_cnt_mode_mask                            (0x80000000)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_ck_sel_hs_mask                           (0x40000000)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_ck_sel_mask                              (0x20000000)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_cycle_max_mask                           (0x0F000000)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_m_mask                                   (0x00003000)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_n_mask                                   (0x00000FFF)
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_cnt_mode(data)                           (0x80000000&((data)<<31))
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_ck_sel_hs(data)                          (0x40000000&((data)<<30))
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_ck_sel(data)                             (0x20000000&((data)<<29))
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_cycle_max(data)                          (0x0F000000&((data)<<24))
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_m(data)                                  (0x00003000&((data)<<12))
#define  MISC_PWM_PWM1_Timing_CTRL_pwm1_n(data)                                  (0x00000FFF&(data))
#define  MISC_PWM_PWM1_Timing_CTRL_get_pwm1_cnt_mode(data)                       ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM1_Timing_CTRL_get_pwm1_ck_sel_hs(data)                      ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM1_Timing_CTRL_get_pwm1_ck_sel(data)                         ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM1_Timing_CTRL_get_pwm1_cycle_max(data)                      ((0x0F000000&(data))>>24)
#define  MISC_PWM_PWM1_Timing_CTRL_get_pwm1_m(data)                              ((0x00003000&(data))>>12)
#define  MISC_PWM_PWM1_Timing_CTRL_get_pwm1_n(data)                              (0x00000FFF&(data))

#define  MISC_PWM_PWM1_DUTY_SET                                                  0x1801BC98
#define  MISC_PWM_PWM1_DUTY_SET_reg_addr                                         "0xB801BC98"
#define  MISC_PWM_PWM1_DUTY_SET_reg                                              0xB801BC98
#define  MISC_PWM_PWM1_DUTY_SET_inst_addr                                        "0x0006"
#define  set_MISC_PWM_PWM1_DUTY_SET_reg(data)                                    (*((volatile unsigned int*)MISC_PWM_PWM1_DUTY_SET_reg)=data)
#define  get_MISC_PWM_PWM1_DUTY_SET_reg                                          (*((volatile unsigned int*)MISC_PWM_PWM1_DUTY_SET_reg))
#define  MISC_PWM_PWM1_DUTY_SET_pwm1_dut_shift                                   (16)
#define  MISC_PWM_PWM1_DUTY_SET_pwm1_totalcnt_shift                              (0)
#define  MISC_PWM_PWM1_DUTY_SET_pwm1_dut_mask                                    (0x0FFF0000)
#define  MISC_PWM_PWM1_DUTY_SET_pwm1_totalcnt_mask                               (0x00000FFF)
#define  MISC_PWM_PWM1_DUTY_SET_pwm1_dut(data)                                   (0x0FFF0000&((data)<<16))
#define  MISC_PWM_PWM1_DUTY_SET_pwm1_totalcnt(data)                              (0x00000FFF&(data))
#define  MISC_PWM_PWM1_DUTY_SET_get_pwm1_dut(data)                               ((0x0FFF0000&(data))>>16)
#define  MISC_PWM_PWM1_DUTY_SET_get_pwm1_totalcnt(data)                          (0x00000FFF&(data))

#define  MISC_PWM_PWM2_CTRL                                                      0x1801BC9C
#define  MISC_PWM_PWM2_CTRL_reg_addr                                             "0xB801BC9C"
#define  MISC_PWM_PWM2_CTRL_reg                                                  0xB801BC9C
#define  MISC_PWM_PWM2_CTRL_inst_addr                                            "0x0007"
#define  set_MISC_PWM_PWM2_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_PWM_PWM2_CTRL_reg)=data)
#define  get_MISC_PWM_PWM2_CTRL_reg                                              (*((volatile unsigned int*)MISC_PWM_PWM2_CTRL_reg))
#define  MISC_PWM_PWM2_CTRL_pwm2l_shift                                          (31)
#define  MISC_PWM_PWM2_CTRL_pwm2_ck_shift                                        (30)
#define  MISC_PWM_PWM2_CTRL_pwm2_en_shift                                        (29)
#define  MISC_PWM_PWM2_CTRL_pwm2_vs_rst_en_shift                                 (28)
#define  MISC_PWM_PWM2_CTRL_pwm2_dut_8b_shift                                    (27)
#define  MISC_PWM_PWM2_CTRL_pwm2_vs_delay_thr_shift                              (6)
#define  MISC_PWM_PWM2_CTRL_pwm2_vs_delay_en_shift                               (5)
#define  MISC_PWM_PWM2_CTRL_pwm2_dim_duty_en_shift                               (4)
#define  MISC_PWM_PWM2_CTRL_dut2_rounding_en_shift                               (3)
#define  MISC_PWM_PWM2_CTRL_pwm2l_mask                                           (0x80000000)
#define  MISC_PWM_PWM2_CTRL_pwm2_ck_mask                                         (0x40000000)
#define  MISC_PWM_PWM2_CTRL_pwm2_en_mask                                         (0x20000000)
#define  MISC_PWM_PWM2_CTRL_pwm2_vs_rst_en_mask                                  (0x10000000)
#define  MISC_PWM_PWM2_CTRL_pwm2_dut_8b_mask                                     (0x08000000)
#define  MISC_PWM_PWM2_CTRL_pwm2_vs_delay_thr_mask                               (0x07FFFFC0)
#define  MISC_PWM_PWM2_CTRL_pwm2_vs_delay_en_mask                                (0x00000020)
#define  MISC_PWM_PWM2_CTRL_pwm2_dim_duty_en_mask                                (0x00000010)
#define  MISC_PWM_PWM2_CTRL_dut2_rounding_en_mask                                (0x00000008)
#define  MISC_PWM_PWM2_CTRL_pwm2l(data)                                          (0x80000000&((data)<<31))
#define  MISC_PWM_PWM2_CTRL_pwm2_ck(data)                                        (0x40000000&((data)<<30))
#define  MISC_PWM_PWM2_CTRL_pwm2_en(data)                                        (0x20000000&((data)<<29))
#define  MISC_PWM_PWM2_CTRL_pwm2_vs_rst_en(data)                                 (0x10000000&((data)<<28))
#define  MISC_PWM_PWM2_CTRL_pwm2_dut_8b(data)                                    (0x08000000&((data)<<27))
#define  MISC_PWM_PWM2_CTRL_pwm2_vs_delay_thr(data)                              (0x07FFFFC0&((data)<<6))
#define  MISC_PWM_PWM2_CTRL_pwm2_vs_delay_en(data)                               (0x00000020&((data)<<5))
#define  MISC_PWM_PWM2_CTRL_pwm2_dim_duty_en(data)                               (0x00000010&((data)<<4))
#define  MISC_PWM_PWM2_CTRL_dut2_rounding_en(data)                               (0x00000008&((data)<<3))
#define  MISC_PWM_PWM2_CTRL_get_pwm2l(data)                                      ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM2_CTRL_get_pwm2_ck(data)                                    ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM2_CTRL_get_pwm2_en(data)                                    ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM2_CTRL_get_pwm2_vs_rst_en(data)                             ((0x10000000&(data))>>28)
#define  MISC_PWM_PWM2_CTRL_get_pwm2_dut_8b(data)                                ((0x08000000&(data))>>27)
#define  MISC_PWM_PWM2_CTRL_get_pwm2_vs_delay_thr(data)                          ((0x07FFFFC0&(data))>>6)
#define  MISC_PWM_PWM2_CTRL_get_pwm2_vs_delay_en(data)                           ((0x00000020&(data))>>5)
#define  MISC_PWM_PWM2_CTRL_get_pwm2_dim_duty_en(data)                           ((0x00000010&(data))>>4)
#define  MISC_PWM_PWM2_CTRL_get_dut2_rounding_en(data)                           ((0x00000008&(data))>>3)

#define  MISC_PWM_PWM2_Timing_CTRL                                               0x1801BCA0
#define  MISC_PWM_PWM2_Timing_CTRL_reg_addr                                      "0xB801BCA0"
#define  MISC_PWM_PWM2_Timing_CTRL_reg                                           0xB801BCA0
#define  MISC_PWM_PWM2_Timing_CTRL_inst_addr                                     "0x0008"
#define  set_MISC_PWM_PWM2_Timing_CTRL_reg(data)                                 (*((volatile unsigned int*)MISC_PWM_PWM2_Timing_CTRL_reg)=data)
#define  get_MISC_PWM_PWM2_Timing_CTRL_reg                                       (*((volatile unsigned int*)MISC_PWM_PWM2_Timing_CTRL_reg))
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_cnt_mode_shift                           (31)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_ck_sel_hs_shift                          (30)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_ck_sel_shift                             (29)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_cycle_max_shift                          (24)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_m_shift                                  (12)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_n_shift                                  (0)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_cnt_mode_mask                            (0x80000000)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_ck_sel_hs_mask                           (0x40000000)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_ck_sel_mask                              (0x20000000)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_cycle_max_mask                           (0x0F000000)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_m_mask                                   (0x00003000)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_n_mask                                   (0x00000FFF)
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_cnt_mode(data)                           (0x80000000&((data)<<31))
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_ck_sel_hs(data)                          (0x40000000&((data)<<30))
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_ck_sel(data)                             (0x20000000&((data)<<29))
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_cycle_max(data)                          (0x0F000000&((data)<<24))
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_m(data)                                  (0x00003000&((data)<<12))
#define  MISC_PWM_PWM2_Timing_CTRL_pwm2_n(data)                                  (0x00000FFF&(data))
#define  MISC_PWM_PWM2_Timing_CTRL_get_pwm2_cnt_mode(data)                       ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM2_Timing_CTRL_get_pwm2_ck_sel_hs(data)                      ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM2_Timing_CTRL_get_pwm2_ck_sel(data)                         ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM2_Timing_CTRL_get_pwm2_cycle_max(data)                      ((0x0F000000&(data))>>24)
#define  MISC_PWM_PWM2_Timing_CTRL_get_pwm2_m(data)                              ((0x00003000&(data))>>12)
#define  MISC_PWM_PWM2_Timing_CTRL_get_pwm2_n(data)                              (0x00000FFF&(data))

#define  MISC_PWM_PWM2_DUTY_SET                                                  0x1801BCA4
#define  MISC_PWM_PWM2_DUTY_SET_reg_addr                                         "0xB801BCA4"
#define  MISC_PWM_PWM2_DUTY_SET_reg                                              0xB801BCA4
#define  MISC_PWM_PWM2_DUTY_SET_inst_addr                                        "0x0009"
#define  set_MISC_PWM_PWM2_DUTY_SET_reg(data)                                    (*((volatile unsigned int*)MISC_PWM_PWM2_DUTY_SET_reg)=data)
#define  get_MISC_PWM_PWM2_DUTY_SET_reg                                          (*((volatile unsigned int*)MISC_PWM_PWM2_DUTY_SET_reg))
#define  MISC_PWM_PWM2_DUTY_SET_pwm2_dut_shift                                   (16)
#define  MISC_PWM_PWM2_DUTY_SET_pwm2_totalcnt_shift                              (0)
#define  MISC_PWM_PWM2_DUTY_SET_pwm2_dut_mask                                    (0x0FFF0000)
#define  MISC_PWM_PWM2_DUTY_SET_pwm2_totalcnt_mask                               (0x00000FFF)
#define  MISC_PWM_PWM2_DUTY_SET_pwm2_dut(data)                                   (0x0FFF0000&((data)<<16))
#define  MISC_PWM_PWM2_DUTY_SET_pwm2_totalcnt(data)                              (0x00000FFF&(data))
#define  MISC_PWM_PWM2_DUTY_SET_get_pwm2_dut(data)                               ((0x0FFF0000&(data))>>16)
#define  MISC_PWM_PWM2_DUTY_SET_get_pwm2_totalcnt(data)                          (0x00000FFF&(data))

#define  MISC_PWM_PWM3_CTRL                                                      0x1801BCA8
#define  MISC_PWM_PWM3_CTRL_reg_addr                                             "0xB801BCA8"
#define  MISC_PWM_PWM3_CTRL_reg                                                  0xB801BCA8
#define  MISC_PWM_PWM3_CTRL_inst_addr                                            "0x000A"
#define  set_MISC_PWM_PWM3_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_PWM_PWM3_CTRL_reg)=data)
#define  get_MISC_PWM_PWM3_CTRL_reg                                              (*((volatile unsigned int*)MISC_PWM_PWM3_CTRL_reg))
#define  MISC_PWM_PWM3_CTRL_pwm3l_shift                                          (31)
#define  MISC_PWM_PWM3_CTRL_pwm3_ck_shift                                        (30)
#define  MISC_PWM_PWM3_CTRL_pwm3_en_shift                                        (29)
#define  MISC_PWM_PWM3_CTRL_pwm3_vs_rst_en_shift                                 (28)
#define  MISC_PWM_PWM3_CTRL_pwm3_dut_8b_shift                                    (27)
#define  MISC_PWM_PWM3_CTRL_pwm3_vs_delay_thr_shift                              (6)
#define  MISC_PWM_PWM3_CTRL_pwm3_vs_delay_en_shift                               (5)
#define  MISC_PWM_PWM3_CTRL_pwm3_dim_duty_en_shift                               (4)
#define  MISC_PWM_PWM3_CTRL_dut3_rounding_en_shift                               (3)
#define  MISC_PWM_PWM3_CTRL_pwm3l_mask                                           (0x80000000)
#define  MISC_PWM_PWM3_CTRL_pwm3_ck_mask                                         (0x40000000)
#define  MISC_PWM_PWM3_CTRL_pwm3_en_mask                                         (0x20000000)
#define  MISC_PWM_PWM3_CTRL_pwm3_vs_rst_en_mask                                  (0x10000000)
#define  MISC_PWM_PWM3_CTRL_pwm3_dut_8b_mask                                     (0x08000000)
#define  MISC_PWM_PWM3_CTRL_pwm3_vs_delay_thr_mask                               (0x07FFFFC0)
#define  MISC_PWM_PWM3_CTRL_pwm3_vs_delay_en_mask                                (0x00000020)
#define  MISC_PWM_PWM3_CTRL_pwm3_dim_duty_en_mask                                (0x00000010)
#define  MISC_PWM_PWM3_CTRL_dut3_rounding_en_mask                                (0x00000008)
#define  MISC_PWM_PWM3_CTRL_pwm3l(data)                                          (0x80000000&((data)<<31))
#define  MISC_PWM_PWM3_CTRL_pwm3_ck(data)                                        (0x40000000&((data)<<30))
#define  MISC_PWM_PWM3_CTRL_pwm3_en(data)                                        (0x20000000&((data)<<29))
#define  MISC_PWM_PWM3_CTRL_pwm3_vs_rst_en(data)                                 (0x10000000&((data)<<28))
#define  MISC_PWM_PWM3_CTRL_pwm3_dut_8b(data)                                    (0x08000000&((data)<<27))
#define  MISC_PWM_PWM3_CTRL_pwm3_vs_delay_thr(data)                              (0x07FFFFC0&((data)<<6))
#define  MISC_PWM_PWM3_CTRL_pwm3_vs_delay_en(data)                               (0x00000020&((data)<<5))
#define  MISC_PWM_PWM3_CTRL_pwm3_dim_duty_en(data)                               (0x00000010&((data)<<4))
#define  MISC_PWM_PWM3_CTRL_dut3_rounding_en(data)                               (0x00000008&((data)<<3))
#define  MISC_PWM_PWM3_CTRL_get_pwm3l(data)                                      ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM3_CTRL_get_pwm3_ck(data)                                    ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM3_CTRL_get_pwm3_en(data)                                    ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM3_CTRL_get_pwm3_vs_rst_en(data)                             ((0x10000000&(data))>>28)
#define  MISC_PWM_PWM3_CTRL_get_pwm3_dut_8b(data)                                ((0x08000000&(data))>>27)
#define  MISC_PWM_PWM3_CTRL_get_pwm3_vs_delay_thr(data)                          ((0x07FFFFC0&(data))>>6)
#define  MISC_PWM_PWM3_CTRL_get_pwm3_vs_delay_en(data)                           ((0x00000020&(data))>>5)
#define  MISC_PWM_PWM3_CTRL_get_pwm3_dim_duty_en(data)                           ((0x00000010&(data))>>4)
#define  MISC_PWM_PWM3_CTRL_get_dut3_rounding_en(data)                           ((0x00000008&(data))>>3)

#define  MISC_PWM_PWM3_Timing_CTRL                                               0x1801BCAC
#define  MISC_PWM_PWM3_Timing_CTRL_reg_addr                                      "0xB801BCAC"
#define  MISC_PWM_PWM3_Timing_CTRL_reg                                           0xB801BCAC
#define  MISC_PWM_PWM3_Timing_CTRL_inst_addr                                     "0x000B"
#define  set_MISC_PWM_PWM3_Timing_CTRL_reg(data)                                 (*((volatile unsigned int*)MISC_PWM_PWM3_Timing_CTRL_reg)=data)
#define  get_MISC_PWM_PWM3_Timing_CTRL_reg                                       (*((volatile unsigned int*)MISC_PWM_PWM3_Timing_CTRL_reg))
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_cnt_mode_shift                           (31)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_ck_sel_hs_shift                          (30)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_ck_sel_shift                             (29)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_cycle_max_shift                          (24)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_m_shift                                  (12)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_n_shift                                  (0)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_cnt_mode_mask                            (0x80000000)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_ck_sel_hs_mask                           (0x40000000)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_ck_sel_mask                              (0x20000000)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_cycle_max_mask                           (0x0F000000)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_m_mask                                   (0x00003000)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_n_mask                                   (0x00000FFF)
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_cnt_mode(data)                           (0x80000000&((data)<<31))
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_ck_sel_hs(data)                          (0x40000000&((data)<<30))
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_ck_sel(data)                             (0x20000000&((data)<<29))
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_cycle_max(data)                          (0x0F000000&((data)<<24))
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_m(data)                                  (0x00003000&((data)<<12))
#define  MISC_PWM_PWM3_Timing_CTRL_pwm3_n(data)                                  (0x00000FFF&(data))
#define  MISC_PWM_PWM3_Timing_CTRL_get_pwm3_cnt_mode(data)                       ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM3_Timing_CTRL_get_pwm3_ck_sel_hs(data)                      ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM3_Timing_CTRL_get_pwm3_ck_sel(data)                         ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM3_Timing_CTRL_get_pwm3_cycle_max(data)                      ((0x0F000000&(data))>>24)
#define  MISC_PWM_PWM3_Timing_CTRL_get_pwm3_m(data)                              ((0x00003000&(data))>>12)
#define  MISC_PWM_PWM3_Timing_CTRL_get_pwm3_n(data)                              (0x00000FFF&(data))

#define  MISC_PWM_PWM3_DUTY_SET                                                  0x1801BCB0
#define  MISC_PWM_PWM3_DUTY_SET_reg_addr                                         "0xB801BCB0"
#define  MISC_PWM_PWM3_DUTY_SET_reg                                              0xB801BCB0
#define  MISC_PWM_PWM3_DUTY_SET_inst_addr                                        "0x000C"
#define  set_MISC_PWM_PWM3_DUTY_SET_reg(data)                                    (*((volatile unsigned int*)MISC_PWM_PWM3_DUTY_SET_reg)=data)
#define  get_MISC_PWM_PWM3_DUTY_SET_reg                                          (*((volatile unsigned int*)MISC_PWM_PWM3_DUTY_SET_reg))
#define  MISC_PWM_PWM3_DUTY_SET_pwm3_dut_shift                                   (16)
#define  MISC_PWM_PWM3_DUTY_SET_pwm3_totalcnt_shift                              (0)
#define  MISC_PWM_PWM3_DUTY_SET_pwm3_dut_mask                                    (0x0FFF0000)
#define  MISC_PWM_PWM3_DUTY_SET_pwm3_totalcnt_mask                               (0x00000FFF)
#define  MISC_PWM_PWM3_DUTY_SET_pwm3_dut(data)                                   (0x0FFF0000&((data)<<16))
#define  MISC_PWM_PWM3_DUTY_SET_pwm3_totalcnt(data)                              (0x00000FFF&(data))
#define  MISC_PWM_PWM3_DUTY_SET_get_pwm3_dut(data)                               ((0x0FFF0000&(data))>>16)
#define  MISC_PWM_PWM3_DUTY_SET_get_pwm3_totalcnt(data)                          (0x00000FFF&(data))

#define  MISC_PWM_PWM4_CTRL                                                      0x1801BCB4
#define  MISC_PWM_PWM4_CTRL_reg_addr                                             "0xB801BCB4"
#define  MISC_PWM_PWM4_CTRL_reg                                                  0xB801BCB4
#define  MISC_PWM_PWM4_CTRL_inst_addr                                            "0x000D"
#define  set_MISC_PWM_PWM4_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_PWM_PWM4_CTRL_reg)=data)
#define  get_MISC_PWM_PWM4_CTRL_reg                                              (*((volatile unsigned int*)MISC_PWM_PWM4_CTRL_reg))
#define  MISC_PWM_PWM4_CTRL_pwm4l_shift                                          (31)
#define  MISC_PWM_PWM4_CTRL_pwm4_ck_shift                                        (30)
#define  MISC_PWM_PWM4_CTRL_pwm4_en_shift                                        (29)
#define  MISC_PWM_PWM4_CTRL_pwm4_vs_rst_en_shift                                 (28)
#define  MISC_PWM_PWM4_CTRL_pwm4_dut_8b_shift                                    (27)
#define  MISC_PWM_PWM4_CTRL_pwm4_vs_delay_thr_shift                              (6)
#define  MISC_PWM_PWM4_CTRL_pwm4_vs_delay_en_shift                               (5)
#define  MISC_PWM_PWM4_CTRL_pwm4_dim_duty_en_shift                               (4)
#define  MISC_PWM_PWM4_CTRL_dut4_rounding_en_shift                               (3)
#define  MISC_PWM_PWM4_CTRL_pwm4l_mask                                           (0x80000000)
#define  MISC_PWM_PWM4_CTRL_pwm4_ck_mask                                         (0x40000000)
#define  MISC_PWM_PWM4_CTRL_pwm4_en_mask                                         (0x20000000)
#define  MISC_PWM_PWM4_CTRL_pwm4_vs_rst_en_mask                                  (0x10000000)
#define  MISC_PWM_PWM4_CTRL_pwm4_dut_8b_mask                                     (0x08000000)
#define  MISC_PWM_PWM4_CTRL_pwm4_vs_delay_thr_mask                               (0x07FFFFC0)
#define  MISC_PWM_PWM4_CTRL_pwm4_vs_delay_en_mask                                (0x00000020)
#define  MISC_PWM_PWM4_CTRL_pwm4_dim_duty_en_mask                                (0x00000010)
#define  MISC_PWM_PWM4_CTRL_dut4_rounding_en_mask                                (0x00000008)
#define  MISC_PWM_PWM4_CTRL_pwm4l(data)                                          (0x80000000&((data)<<31))
#define  MISC_PWM_PWM4_CTRL_pwm4_ck(data)                                        (0x40000000&((data)<<30))
#define  MISC_PWM_PWM4_CTRL_pwm4_en(data)                                        (0x20000000&((data)<<29))
#define  MISC_PWM_PWM4_CTRL_pwm4_vs_rst_en(data)                                 (0x10000000&((data)<<28))
#define  MISC_PWM_PWM4_CTRL_pwm4_dut_8b(data)                                    (0x08000000&((data)<<27))
#define  MISC_PWM_PWM4_CTRL_pwm4_vs_delay_thr(data)                              (0x07FFFFC0&((data)<<6))
#define  MISC_PWM_PWM4_CTRL_pwm4_vs_delay_en(data)                               (0x00000020&((data)<<5))
#define  MISC_PWM_PWM4_CTRL_pwm4_dim_duty_en(data)                               (0x00000010&((data)<<4))
#define  MISC_PWM_PWM4_CTRL_dut4_rounding_en(data)                               (0x00000008&((data)<<3))
#define  MISC_PWM_PWM4_CTRL_get_pwm4l(data)                                      ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM4_CTRL_get_pwm4_ck(data)                                    ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM4_CTRL_get_pwm4_en(data)                                    ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM4_CTRL_get_pwm4_vs_rst_en(data)                             ((0x10000000&(data))>>28)
#define  MISC_PWM_PWM4_CTRL_get_pwm4_dut_8b(data)                                ((0x08000000&(data))>>27)
#define  MISC_PWM_PWM4_CTRL_get_pwm4_vs_delay_thr(data)                          ((0x07FFFFC0&(data))>>6)
#define  MISC_PWM_PWM4_CTRL_get_pwm4_vs_delay_en(data)                           ((0x00000020&(data))>>5)
#define  MISC_PWM_PWM4_CTRL_get_pwm4_dim_duty_en(data)                           ((0x00000010&(data))>>4)
#define  MISC_PWM_PWM4_CTRL_get_dut4_rounding_en(data)                           ((0x00000008&(data))>>3)

#define  MISC_PWM_PWM4_Timing_CTRL                                               0x1801BCB8
#define  MISC_PWM_PWM4_Timing_CTRL_reg_addr                                      "0xB801BCB8"
#define  MISC_PWM_PWM4_Timing_CTRL_reg                                           0xB801BCB8
#define  MISC_PWM_PWM4_Timing_CTRL_inst_addr                                     "0x000E"
#define  set_MISC_PWM_PWM4_Timing_CTRL_reg(data)                                 (*((volatile unsigned int*)MISC_PWM_PWM4_Timing_CTRL_reg)=data)
#define  get_MISC_PWM_PWM4_Timing_CTRL_reg                                       (*((volatile unsigned int*)MISC_PWM_PWM4_Timing_CTRL_reg))
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_cnt_mode_shift                           (31)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_ck_sel_hs_shift                          (30)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_ck_sel_shift                             (29)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_cycle_max_shift                          (24)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_m_shift                                  (12)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_n_shift                                  (0)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_cnt_mode_mask                            (0x80000000)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_ck_sel_hs_mask                           (0x40000000)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_ck_sel_mask                              (0x20000000)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_cycle_max_mask                           (0x0F000000)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_m_mask                                   (0x00003000)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_n_mask                                   (0x00000FFF)
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_cnt_mode(data)                           (0x80000000&((data)<<31))
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_ck_sel_hs(data)                          (0x40000000&((data)<<30))
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_ck_sel(data)                             (0x20000000&((data)<<29))
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_cycle_max(data)                          (0x0F000000&((data)<<24))
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_m(data)                                  (0x00003000&((data)<<12))
#define  MISC_PWM_PWM4_Timing_CTRL_pwm4_n(data)                                  (0x00000FFF&(data))
#define  MISC_PWM_PWM4_Timing_CTRL_get_pwm4_cnt_mode(data)                       ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM4_Timing_CTRL_get_pwm4_ck_sel_hs(data)                      ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM4_Timing_CTRL_get_pwm4_ck_sel(data)                         ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM4_Timing_CTRL_get_pwm4_cycle_max(data)                      ((0x0F000000&(data))>>24)
#define  MISC_PWM_PWM4_Timing_CTRL_get_pwm4_m(data)                              ((0x00003000&(data))>>12)
#define  MISC_PWM_PWM4_Timing_CTRL_get_pwm4_n(data)                              (0x00000FFF&(data))

#define  MISC_PWM_PWM4_DUTY_SET                                                  0x1801BCBC
#define  MISC_PWM_PWM4_DUTY_SET_reg_addr                                         "0xB801BCBC"
#define  MISC_PWM_PWM4_DUTY_SET_reg                                              0xB801BCBC
#define  MISC_PWM_PWM4_DUTY_SET_inst_addr                                        "0x000F"
#define  set_MISC_PWM_PWM4_DUTY_SET_reg(data)                                    (*((volatile unsigned int*)MISC_PWM_PWM4_DUTY_SET_reg)=data)
#define  get_MISC_PWM_PWM4_DUTY_SET_reg                                          (*((volatile unsigned int*)MISC_PWM_PWM4_DUTY_SET_reg))
#define  MISC_PWM_PWM4_DUTY_SET_pwm4_dut_shift                                   (16)
#define  MISC_PWM_PWM4_DUTY_SET_pwm4_totalcnt_shift                              (0)
#define  MISC_PWM_PWM4_DUTY_SET_pwm4_dut_mask                                    (0x0FFF0000)
#define  MISC_PWM_PWM4_DUTY_SET_pwm4_totalcnt_mask                               (0x00000FFF)
#define  MISC_PWM_PWM4_DUTY_SET_pwm4_dut(data)                                   (0x0FFF0000&((data)<<16))
#define  MISC_PWM_PWM4_DUTY_SET_pwm4_totalcnt(data)                              (0x00000FFF&(data))
#define  MISC_PWM_PWM4_DUTY_SET_get_pwm4_dut(data)                               ((0x0FFF0000&(data))>>16)
#define  MISC_PWM_PWM4_DUTY_SET_get_pwm4_totalcnt(data)                          (0x00000FFF&(data))

#define  MISC_PWM_PWM5_CTRL                                                      0x1801BCC0
#define  MISC_PWM_PWM5_CTRL_reg_addr                                             "0xB801BCC0"
#define  MISC_PWM_PWM5_CTRL_reg                                                  0xB801BCC0
#define  MISC_PWM_PWM5_CTRL_inst_addr                                            "0x0010"
#define  set_MISC_PWM_PWM5_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_PWM_PWM5_CTRL_reg)=data)
#define  get_MISC_PWM_PWM5_CTRL_reg                                              (*((volatile unsigned int*)MISC_PWM_PWM5_CTRL_reg))
#define  MISC_PWM_PWM5_CTRL_pwm5l_shift                                          (31)
#define  MISC_PWM_PWM5_CTRL_pwm5_ck_shift                                        (30)
#define  MISC_PWM_PWM5_CTRL_pwm5_en_shift                                        (29)
#define  MISC_PWM_PWM5_CTRL_pwm5_vs_rst_en_shift                                 (28)
#define  MISC_PWM_PWM5_CTRL_pwm5_dut_8b_shift                                    (27)
#define  MISC_PWM_PWM5_CTRL_pwm5_vs_delay_thr_shift                              (6)
#define  MISC_PWM_PWM5_CTRL_pwm5_vs_delay_en_shift                               (5)
#define  MISC_PWM_PWM5_CTRL_pwm5_dim_duty_en_shift                               (4)
#define  MISC_PWM_PWM5_CTRL_dut5_rounding_en_shift                               (3)
#define  MISC_PWM_PWM5_CTRL_pwm5l_mask                                           (0x80000000)
#define  MISC_PWM_PWM5_CTRL_pwm5_ck_mask                                         (0x40000000)
#define  MISC_PWM_PWM5_CTRL_pwm5_en_mask                                         (0x20000000)
#define  MISC_PWM_PWM5_CTRL_pwm5_vs_rst_en_mask                                  (0x10000000)
#define  MISC_PWM_PWM5_CTRL_pwm5_dut_8b_mask                                     (0x08000000)
#define  MISC_PWM_PWM5_CTRL_pwm5_vs_delay_thr_mask                               (0x07FFFFC0)
#define  MISC_PWM_PWM5_CTRL_pwm5_vs_delay_en_mask                                (0x00000020)
#define  MISC_PWM_PWM5_CTRL_pwm5_dim_duty_en_mask                                (0x00000010)
#define  MISC_PWM_PWM5_CTRL_dut5_rounding_en_mask                                (0x00000008)
#define  MISC_PWM_PWM5_CTRL_pwm5l(data)                                          (0x80000000&((data)<<31))
#define  MISC_PWM_PWM5_CTRL_pwm5_ck(data)                                        (0x40000000&((data)<<30))
#define  MISC_PWM_PWM5_CTRL_pwm5_en(data)                                        (0x20000000&((data)<<29))
#define  MISC_PWM_PWM5_CTRL_pwm5_vs_rst_en(data)                                 (0x10000000&((data)<<28))
#define  MISC_PWM_PWM5_CTRL_pwm5_dut_8b(data)                                    (0x08000000&((data)<<27))
#define  MISC_PWM_PWM5_CTRL_pwm5_vs_delay_thr(data)                              (0x07FFFFC0&((data)<<6))
#define  MISC_PWM_PWM5_CTRL_pwm5_vs_delay_en(data)                               (0x00000020&((data)<<5))
#define  MISC_PWM_PWM5_CTRL_pwm5_dim_duty_en(data)                               (0x00000010&((data)<<4))
#define  MISC_PWM_PWM5_CTRL_dut5_rounding_en(data)                               (0x00000008&((data)<<3))
#define  MISC_PWM_PWM5_CTRL_get_pwm5l(data)                                      ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM5_CTRL_get_pwm5_ck(data)                                    ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM5_CTRL_get_pwm5_en(data)                                    ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM5_CTRL_get_pwm5_vs_rst_en(data)                             ((0x10000000&(data))>>28)
#define  MISC_PWM_PWM5_CTRL_get_pwm5_dut_8b(data)                                ((0x08000000&(data))>>27)
#define  MISC_PWM_PWM5_CTRL_get_pwm5_vs_delay_thr(data)                          ((0x07FFFFC0&(data))>>6)
#define  MISC_PWM_PWM5_CTRL_get_pwm5_vs_delay_en(data)                           ((0x00000020&(data))>>5)
#define  MISC_PWM_PWM5_CTRL_get_pwm5_dim_duty_en(data)                           ((0x00000010&(data))>>4)
#define  MISC_PWM_PWM5_CTRL_get_dut5_rounding_en(data)                           ((0x00000008&(data))>>3)

#define  MISC_PWM_PWM5_Timing_CTRL                                               0x1801BCC4
#define  MISC_PWM_PWM5_Timing_CTRL_reg_addr                                      "0xB801BCC4"
#define  MISC_PWM_PWM5_Timing_CTRL_reg                                           0xB801BCC4
#define  MISC_PWM_PWM5_Timing_CTRL_inst_addr                                     "0x0011"
#define  set_MISC_PWM_PWM5_Timing_CTRL_reg(data)                                 (*((volatile unsigned int*)MISC_PWM_PWM5_Timing_CTRL_reg)=data)
#define  get_MISC_PWM_PWM5_Timing_CTRL_reg                                       (*((volatile unsigned int*)MISC_PWM_PWM5_Timing_CTRL_reg))
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_cnt_mode_shift                           (31)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_ck_sel_hs_shift                          (30)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_ck_sel_shift                             (29)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_cycle_max_shift                          (24)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_m_shift                                  (12)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_n_shift                                  (0)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_cnt_mode_mask                            (0x80000000)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_ck_sel_hs_mask                           (0x40000000)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_ck_sel_mask                              (0x20000000)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_cycle_max_mask                           (0x0F000000)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_m_mask                                   (0x00003000)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_n_mask                                   (0x00000FFF)
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_cnt_mode(data)                           (0x80000000&((data)<<31))
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_ck_sel_hs(data)                          (0x40000000&((data)<<30))
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_ck_sel(data)                             (0x20000000&((data)<<29))
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_cycle_max(data)                          (0x0F000000&((data)<<24))
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_m(data)                                  (0x00003000&((data)<<12))
#define  MISC_PWM_PWM5_Timing_CTRL_pwm5_n(data)                                  (0x00000FFF&(data))
#define  MISC_PWM_PWM5_Timing_CTRL_get_pwm5_cnt_mode(data)                       ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM5_Timing_CTRL_get_pwm5_ck_sel_hs(data)                      ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM5_Timing_CTRL_get_pwm5_ck_sel(data)                         ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM5_Timing_CTRL_get_pwm5_cycle_max(data)                      ((0x0F000000&(data))>>24)
#define  MISC_PWM_PWM5_Timing_CTRL_get_pwm5_m(data)                              ((0x00003000&(data))>>12)
#define  MISC_PWM_PWM5_Timing_CTRL_get_pwm5_n(data)                              (0x00000FFF&(data))

#define  MISC_PWM_PWM5_DUTY_SET                                                  0x1801BCC8
#define  MISC_PWM_PWM5_DUTY_SET_reg_addr                                         "0xB801BCC8"
#define  MISC_PWM_PWM5_DUTY_SET_reg                                              0xB801BCC8
#define  MISC_PWM_PWM5_DUTY_SET_inst_addr                                        "0x0012"
#define  set_MISC_PWM_PWM5_DUTY_SET_reg(data)                                    (*((volatile unsigned int*)MISC_PWM_PWM5_DUTY_SET_reg)=data)
#define  get_MISC_PWM_PWM5_DUTY_SET_reg                                          (*((volatile unsigned int*)MISC_PWM_PWM5_DUTY_SET_reg))
#define  MISC_PWM_PWM5_DUTY_SET_pwm5_dut_shift                                   (16)
#define  MISC_PWM_PWM5_DUTY_SET_pwm5_totalcnt_shift                              (0)
#define  MISC_PWM_PWM5_DUTY_SET_pwm5_dut_mask                                    (0x0FFF0000)
#define  MISC_PWM_PWM5_DUTY_SET_pwm5_totalcnt_mask                               (0x00000FFF)
#define  MISC_PWM_PWM5_DUTY_SET_pwm5_dut(data)                                   (0x0FFF0000&((data)<<16))
#define  MISC_PWM_PWM5_DUTY_SET_pwm5_totalcnt(data)                              (0x00000FFF&(data))
#define  MISC_PWM_PWM5_DUTY_SET_get_pwm5_dut(data)                               ((0x0FFF0000&(data))>>16)
#define  MISC_PWM_PWM5_DUTY_SET_get_pwm5_totalcnt(data)                          (0x00000FFF&(data))

#define  MISC_PWM_PWM6_CTRL                                                      0x1801BCCC
#define  MISC_PWM_PWM6_CTRL_reg_addr                                             "0xB801BCCC"
#define  MISC_PWM_PWM6_CTRL_reg                                                  0xB801BCCC
#define  MISC_PWM_PWM6_CTRL_inst_addr                                            "0x0013"
#define  set_MISC_PWM_PWM6_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_PWM_PWM6_CTRL_reg)=data)
#define  get_MISC_PWM_PWM6_CTRL_reg                                              (*((volatile unsigned int*)MISC_PWM_PWM6_CTRL_reg))
#define  MISC_PWM_PWM6_CTRL_pwm6l_shift                                          (31)
#define  MISC_PWM_PWM6_CTRL_pwm6_ck_shift                                        (30)
#define  MISC_PWM_PWM6_CTRL_pwm6_en_shift                                        (29)
#define  MISC_PWM_PWM6_CTRL_pwm6_vs_rst_en_shift                                 (28)
#define  MISC_PWM_PWM6_CTRL_pwm6_dut_8b_shift                                    (27)
#define  MISC_PWM_PWM6_CTRL_pwm6_vs_delay_thr_shift                              (6)
#define  MISC_PWM_PWM6_CTRL_pwm6_vs_delay_en_shift                               (5)
#define  MISC_PWM_PWM6_CTRL_pwm6_dim_duty_en_shift                               (4)
#define  MISC_PWM_PWM6_CTRL_dut6_rounding_en_shift                               (3)
#define  MISC_PWM_PWM6_CTRL_pwm6l_mask                                           (0x80000000)
#define  MISC_PWM_PWM6_CTRL_pwm6_ck_mask                                         (0x40000000)
#define  MISC_PWM_PWM6_CTRL_pwm6_en_mask                                         (0x20000000)
#define  MISC_PWM_PWM6_CTRL_pwm6_vs_rst_en_mask                                  (0x10000000)
#define  MISC_PWM_PWM6_CTRL_pwm6_dut_8b_mask                                     (0x08000000)
#define  MISC_PWM_PWM6_CTRL_pwm6_vs_delay_thr_mask                               (0x07FFFFC0)
#define  MISC_PWM_PWM6_CTRL_pwm6_vs_delay_en_mask                                (0x00000020)
#define  MISC_PWM_PWM6_CTRL_pwm6_dim_duty_en_mask                                (0x00000010)
#define  MISC_PWM_PWM6_CTRL_dut6_rounding_en_mask                                (0x00000008)
#define  MISC_PWM_PWM6_CTRL_pwm6l(data)                                          (0x80000000&((data)<<31))
#define  MISC_PWM_PWM6_CTRL_pwm6_ck(data)                                        (0x40000000&((data)<<30))
#define  MISC_PWM_PWM6_CTRL_pwm6_en(data)                                        (0x20000000&((data)<<29))
#define  MISC_PWM_PWM6_CTRL_pwm6_vs_rst_en(data)                                 (0x10000000&((data)<<28))
#define  MISC_PWM_PWM6_CTRL_pwm6_dut_8b(data)                                    (0x08000000&((data)<<27))
#define  MISC_PWM_PWM6_CTRL_pwm6_vs_delay_thr(data)                              (0x07FFFFC0&((data)<<6))
#define  MISC_PWM_PWM6_CTRL_pwm6_vs_delay_en(data)                               (0x00000020&((data)<<5))
#define  MISC_PWM_PWM6_CTRL_pwm6_dim_duty_en(data)                               (0x00000010&((data)<<4))
#define  MISC_PWM_PWM6_CTRL_dut6_rounding_en(data)                               (0x00000008&((data)<<3))
#define  MISC_PWM_PWM6_CTRL_get_pwm6l(data)                                      ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM6_CTRL_get_pwm6_ck(data)                                    ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM6_CTRL_get_pwm6_en(data)                                    ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM6_CTRL_get_pwm6_vs_rst_en(data)                             ((0x10000000&(data))>>28)
#define  MISC_PWM_PWM6_CTRL_get_pwm6_dut_8b(data)                                ((0x08000000&(data))>>27)
#define  MISC_PWM_PWM6_CTRL_get_pwm6_vs_delay_thr(data)                          ((0x07FFFFC0&(data))>>6)
#define  MISC_PWM_PWM6_CTRL_get_pwm6_vs_delay_en(data)                           ((0x00000020&(data))>>5)
#define  MISC_PWM_PWM6_CTRL_get_pwm6_dim_duty_en(data)                           ((0x00000010&(data))>>4)
#define  MISC_PWM_PWM6_CTRL_get_dut6_rounding_en(data)                           ((0x00000008&(data))>>3)

#define  MISC_PWM_PWM6_Timing_CTRL                                               0x1801BCD0
#define  MISC_PWM_PWM6_Timing_CTRL_reg_addr                                      "0xB801BCD0"
#define  MISC_PWM_PWM6_Timing_CTRL_reg                                           0xB801BCD0
#define  MISC_PWM_PWM6_Timing_CTRL_inst_addr                                     "0x0014"
#define  set_MISC_PWM_PWM6_Timing_CTRL_reg(data)                                 (*((volatile unsigned int*)MISC_PWM_PWM6_Timing_CTRL_reg)=data)
#define  get_MISC_PWM_PWM6_Timing_CTRL_reg                                       (*((volatile unsigned int*)MISC_PWM_PWM6_Timing_CTRL_reg))
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_cnt_mode_shift                           (31)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_ck_sel_hs_shift                          (30)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_ck_sel_shift                             (29)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_cycle_max_shift                          (24)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_m_shift                                  (12)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_n_shift                                  (0)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_cnt_mode_mask                            (0x80000000)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_ck_sel_hs_mask                           (0x40000000)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_ck_sel_mask                              (0x20000000)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_cycle_max_mask                           (0x0F000000)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_m_mask                                   (0x00003000)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_n_mask                                   (0x00000FFF)
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_cnt_mode(data)                           (0x80000000&((data)<<31))
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_ck_sel_hs(data)                          (0x40000000&((data)<<30))
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_ck_sel(data)                             (0x20000000&((data)<<29))
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_cycle_max(data)                          (0x0F000000&((data)<<24))
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_m(data)                                  (0x00003000&((data)<<12))
#define  MISC_PWM_PWM6_Timing_CTRL_pwm6_n(data)                                  (0x00000FFF&(data))
#define  MISC_PWM_PWM6_Timing_CTRL_get_pwm6_cnt_mode(data)                       ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM6_Timing_CTRL_get_pwm6_ck_sel_hs(data)                      ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM6_Timing_CTRL_get_pwm6_ck_sel(data)                         ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM6_Timing_CTRL_get_pwm6_cycle_max(data)                      ((0x0F000000&(data))>>24)
#define  MISC_PWM_PWM6_Timing_CTRL_get_pwm6_m(data)                              ((0x00003000&(data))>>12)
#define  MISC_PWM_PWM6_Timing_CTRL_get_pwm6_n(data)                              (0x00000FFF&(data))

#define  MISC_PWM_PWM6_DUTY_SET                                                  0x1801BCD4
#define  MISC_PWM_PWM6_DUTY_SET_reg_addr                                         "0xB801BCD4"
#define  MISC_PWM_PWM6_DUTY_SET_reg                                              0xB801BCD4
#define  MISC_PWM_PWM6_DUTY_SET_inst_addr                                        "0x0015"
#define  set_MISC_PWM_PWM6_DUTY_SET_reg(data)                                    (*((volatile unsigned int*)MISC_PWM_PWM6_DUTY_SET_reg)=data)
#define  get_MISC_PWM_PWM6_DUTY_SET_reg                                          (*((volatile unsigned int*)MISC_PWM_PWM6_DUTY_SET_reg))
#define  MISC_PWM_PWM6_DUTY_SET_pwm6_dut_shift                                   (16)
#define  MISC_PWM_PWM6_DUTY_SET_pwm6_totalcnt_shift                              (0)
#define  MISC_PWM_PWM6_DUTY_SET_pwm6_dut_mask                                    (0x0FFF0000)
#define  MISC_PWM_PWM6_DUTY_SET_pwm6_totalcnt_mask                               (0x00000FFF)
#define  MISC_PWM_PWM6_DUTY_SET_pwm6_dut(data)                                   (0x0FFF0000&((data)<<16))
#define  MISC_PWM_PWM6_DUTY_SET_pwm6_totalcnt(data)                              (0x00000FFF&(data))
#define  MISC_PWM_PWM6_DUTY_SET_get_pwm6_dut(data)                               ((0x0FFF0000&(data))>>16)
#define  MISC_PWM_PWM6_DUTY_SET_get_pwm6_totalcnt(data)                          (0x00000FFF&(data))

#define  MISC_PWM_PWM7_CTRL                                                      0x1801BCD8
#define  MISC_PWM_PWM7_CTRL_reg_addr                                             "0xB801BCD8"
#define  MISC_PWM_PWM7_CTRL_reg                                                  0xB801BCD8
#define  MISC_PWM_PWM7_CTRL_inst_addr                                            "0x0016"
#define  set_MISC_PWM_PWM7_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_PWM_PWM7_CTRL_reg)=data)
#define  get_MISC_PWM_PWM7_CTRL_reg                                              (*((volatile unsigned int*)MISC_PWM_PWM7_CTRL_reg))
#define  MISC_PWM_PWM7_CTRL_pwm7l_shift                                          (31)
#define  MISC_PWM_PWM7_CTRL_pwm7_ck_shift                                        (30)
#define  MISC_PWM_PWM7_CTRL_pwm7_en_shift                                        (29)
#define  MISC_PWM_PWM7_CTRL_pwm7_vs_rst_en_shift                                 (28)
#define  MISC_PWM_PWM7_CTRL_pwm7_dut_8b_shift                                    (27)
#define  MISC_PWM_PWM7_CTRL_pwm7_vs_delay_thr_shift                              (6)
#define  MISC_PWM_PWM7_CTRL_pwm7_vs_delay_en_shift                               (5)
#define  MISC_PWM_PWM7_CTRL_pwm7_dim_duty_en_shift                               (4)
#define  MISC_PWM_PWM7_CTRL_dut7_rounding_en_shift                               (3)
#define  MISC_PWM_PWM7_CTRL_pwm7l_mask                                           (0x80000000)
#define  MISC_PWM_PWM7_CTRL_pwm7_ck_mask                                         (0x40000000)
#define  MISC_PWM_PWM7_CTRL_pwm7_en_mask                                         (0x20000000)
#define  MISC_PWM_PWM7_CTRL_pwm7_vs_rst_en_mask                                  (0x10000000)
#define  MISC_PWM_PWM7_CTRL_pwm7_dut_8b_mask                                     (0x08000000)
#define  MISC_PWM_PWM7_CTRL_pwm7_vs_delay_thr_mask                               (0x07FFFFC0)
#define  MISC_PWM_PWM7_CTRL_pwm7_vs_delay_en_mask                                (0x00000020)
#define  MISC_PWM_PWM7_CTRL_pwm7_dim_duty_en_mask                                (0x00000010)
#define  MISC_PWM_PWM7_CTRL_dut7_rounding_en_mask                                (0x00000008)
#define  MISC_PWM_PWM7_CTRL_pwm7l(data)                                          (0x80000000&((data)<<31))
#define  MISC_PWM_PWM7_CTRL_pwm7_ck(data)                                        (0x40000000&((data)<<30))
#define  MISC_PWM_PWM7_CTRL_pwm7_en(data)                                        (0x20000000&((data)<<29))
#define  MISC_PWM_PWM7_CTRL_pwm7_vs_rst_en(data)                                 (0x10000000&((data)<<28))
#define  MISC_PWM_PWM7_CTRL_pwm7_dut_8b(data)                                    (0x08000000&((data)<<27))
#define  MISC_PWM_PWM7_CTRL_pwm7_vs_delay_thr(data)                              (0x07FFFFC0&((data)<<6))
#define  MISC_PWM_PWM7_CTRL_pwm7_vs_delay_en(data)                               (0x00000020&((data)<<5))
#define  MISC_PWM_PWM7_CTRL_pwm7_dim_duty_en(data)                               (0x00000010&((data)<<4))
#define  MISC_PWM_PWM7_CTRL_dut7_rounding_en(data)                               (0x00000008&((data)<<3))
#define  MISC_PWM_PWM7_CTRL_get_pwm7l(data)                                      ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM7_CTRL_get_pwm7_ck(data)                                    ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM7_CTRL_get_pwm7_en(data)                                    ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM7_CTRL_get_pwm7_vs_rst_en(data)                             ((0x10000000&(data))>>28)
#define  MISC_PWM_PWM7_CTRL_get_pwm7_dut_8b(data)                                ((0x08000000&(data))>>27)
#define  MISC_PWM_PWM7_CTRL_get_pwm7_vs_delay_thr(data)                          ((0x07FFFFC0&(data))>>6)
#define  MISC_PWM_PWM7_CTRL_get_pwm7_vs_delay_en(data)                           ((0x00000020&(data))>>5)
#define  MISC_PWM_PWM7_CTRL_get_pwm7_dim_duty_en(data)                           ((0x00000010&(data))>>4)
#define  MISC_PWM_PWM7_CTRL_get_dut7_rounding_en(data)                           ((0x00000008&(data))>>3)

#define  MISC_PWM_PWM7_Timing_CTRL                                               0x1801BCDC
#define  MISC_PWM_PWM7_Timing_CTRL_reg_addr                                      "0xB801BCDC"
#define  MISC_PWM_PWM7_Timing_CTRL_reg                                           0xB801BCDC
#define  MISC_PWM_PWM7_Timing_CTRL_inst_addr                                     "0x0017"
#define  set_MISC_PWM_PWM7_Timing_CTRL_reg(data)                                 (*((volatile unsigned int*)MISC_PWM_PWM7_Timing_CTRL_reg)=data)
#define  get_MISC_PWM_PWM7_Timing_CTRL_reg                                       (*((volatile unsigned int*)MISC_PWM_PWM7_Timing_CTRL_reg))
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_cnt_mode_shift                           (31)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_ck_sel_hs_shift                          (30)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_ck_sel_shift                             (29)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_cycle_max_shift                          (24)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_m_shift                                  (12)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_n_shift                                  (0)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_cnt_mode_mask                            (0x80000000)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_ck_sel_hs_mask                           (0x40000000)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_ck_sel_mask                              (0x20000000)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_cycle_max_mask                           (0x0F000000)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_m_mask                                   (0x00003000)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_n_mask                                   (0x00000FFF)
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_cnt_mode(data)                           (0x80000000&((data)<<31))
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_ck_sel_hs(data)                          (0x40000000&((data)<<30))
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_ck_sel(data)                             (0x20000000&((data)<<29))
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_cycle_max(data)                          (0x0F000000&((data)<<24))
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_m(data)                                  (0x00003000&((data)<<12))
#define  MISC_PWM_PWM7_Timing_CTRL_pwm7_n(data)                                  (0x00000FFF&(data))
#define  MISC_PWM_PWM7_Timing_CTRL_get_pwm7_cnt_mode(data)                       ((0x80000000&(data))>>31)
#define  MISC_PWM_PWM7_Timing_CTRL_get_pwm7_ck_sel_hs(data)                      ((0x40000000&(data))>>30)
#define  MISC_PWM_PWM7_Timing_CTRL_get_pwm7_ck_sel(data)                         ((0x20000000&(data))>>29)
#define  MISC_PWM_PWM7_Timing_CTRL_get_pwm7_cycle_max(data)                      ((0x0F000000&(data))>>24)
#define  MISC_PWM_PWM7_Timing_CTRL_get_pwm7_m(data)                              ((0x00003000&(data))>>12)
#define  MISC_PWM_PWM7_Timing_CTRL_get_pwm7_n(data)                              (0x00000FFF&(data))

#define  MISC_PWM_PWM7_DUTY_SET                                                  0x1801BCE0
#define  MISC_PWM_PWM7_DUTY_SET_reg_addr                                         "0xB801BCE0"
#define  MISC_PWM_PWM7_DUTY_SET_reg                                              0xB801BCE0
#define  MISC_PWM_PWM7_DUTY_SET_inst_addr                                        "0x0018"
#define  set_MISC_PWM_PWM7_DUTY_SET_reg(data)                                    (*((volatile unsigned int*)MISC_PWM_PWM7_DUTY_SET_reg)=data)
#define  get_MISC_PWM_PWM7_DUTY_SET_reg                                          (*((volatile unsigned int*)MISC_PWM_PWM7_DUTY_SET_reg))
#define  MISC_PWM_PWM7_DUTY_SET_pwm7_dut_shift                                   (16)
#define  MISC_PWM_PWM7_DUTY_SET_pwm7_totalcnt_shift                              (0)
#define  MISC_PWM_PWM7_DUTY_SET_pwm7_dut_mask                                    (0x0FFF0000)
#define  MISC_PWM_PWM7_DUTY_SET_pwm7_totalcnt_mask                               (0x00000FFF)
#define  MISC_PWM_PWM7_DUTY_SET_pwm7_dut(data)                                   (0x0FFF0000&((data)<<16))
#define  MISC_PWM_PWM7_DUTY_SET_pwm7_totalcnt(data)                              (0x00000FFF&(data))
#define  MISC_PWM_PWM7_DUTY_SET_get_pwm7_dut(data)                               ((0x0FFF0000&(data))>>16)
#define  MISC_PWM_PWM7_DUTY_SET_get_pwm7_totalcnt(data)                          (0x00000FFF&(data))

#define  MISC_PWM_DUMMY                                                          0x1801BCE4
#define  MISC_PWM_DUMMY_reg_addr                                                 "0xB801BCE4"
#define  MISC_PWM_DUMMY_reg                                                      0xB801BCE4
#define  MISC_PWM_DUMMY_inst_addr                                                "0x0019"
#define  set_MISC_PWM_DUMMY_reg(data)                                            (*((volatile unsigned int*)MISC_PWM_DUMMY_reg)=data)
#define  get_MISC_PWM_DUMMY_reg                                                  (*((volatile unsigned int*)MISC_PWM_DUMMY_reg))
#define  MISC_PWM_DUMMY_pwm7_od_mode_shift                                       (11)
#define  MISC_PWM_DUMMY_pwm6_od_mode_shift                                       (10)
#define  MISC_PWM_DUMMY_pwm5_od_mode_shift                                       (9)
#define  MISC_PWM_DUMMY_pwm4_od_mode_shift                                       (8)
#define  MISC_PWM_DUMMY_pwm3_od_mode_shift                                       (7)
#define  MISC_PWM_DUMMY_pwm2_od_mode_shift                                       (6)
#define  MISC_PWM_DUMMY_pwm1_od_mode_shift                                       (5)
#define  MISC_PWM_DUMMY_pwm0_od_mode_shift                                       (4)
#define  MISC_PWM_DUMMY_pwm7_od_mode_mask                                        (0x00000800)
#define  MISC_PWM_DUMMY_pwm6_od_mode_mask                                        (0x00000400)
#define  MISC_PWM_DUMMY_pwm5_od_mode_mask                                        (0x00000200)
#define  MISC_PWM_DUMMY_pwm4_od_mode_mask                                        (0x00000100)
#define  MISC_PWM_DUMMY_pwm3_od_mode_mask                                        (0x00000080)
#define  MISC_PWM_DUMMY_pwm2_od_mode_mask                                        (0x00000040)
#define  MISC_PWM_DUMMY_pwm1_od_mode_mask                                        (0x00000020)
#define  MISC_PWM_DUMMY_pwm0_od_mode_mask                                        (0x00000010)
#define  MISC_PWM_DUMMY_pwm7_od_mode(data)                                       (0x00000800&((data)<<11))
#define  MISC_PWM_DUMMY_pwm6_od_mode(data)                                       (0x00000400&((data)<<10))
#define  MISC_PWM_DUMMY_pwm5_od_mode(data)                                       (0x00000200&((data)<<9))
#define  MISC_PWM_DUMMY_pwm4_od_mode(data)                                       (0x00000100&((data)<<8))
#define  MISC_PWM_DUMMY_pwm3_od_mode(data)                                       (0x00000080&((data)<<7))
#define  MISC_PWM_DUMMY_pwm2_od_mode(data)                                       (0x00000040&((data)<<6))
#define  MISC_PWM_DUMMY_pwm1_od_mode(data)                                       (0x00000020&((data)<<5))
#define  MISC_PWM_DUMMY_pwm0_od_mode(data)                                       (0x00000010&((data)<<4))
#define  MISC_PWM_DUMMY_get_pwm7_od_mode(data)                                   ((0x00000800&(data))>>11)
#define  MISC_PWM_DUMMY_get_pwm6_od_mode(data)                                   ((0x00000400&(data))>>10)
#define  MISC_PWM_DUMMY_get_pwm5_od_mode(data)                                   ((0x00000200&(data))>>9)
#define  MISC_PWM_DUMMY_get_pwm4_od_mode(data)                                   ((0x00000100&(data))>>8)
#define  MISC_PWM_DUMMY_get_pwm3_od_mode(data)                                   ((0x00000080&(data))>>7)
#define  MISC_PWM_DUMMY_get_pwm2_od_mode(data)                                   ((0x00000040&(data))>>6)
#define  MISC_PWM_DUMMY_get_pwm1_od_mode(data)                                   ((0x00000020&(data))>>5)
#define  MISC_PWM_DUMMY_get_pwm0_od_mode(data)                                   ((0x00000010&(data))>>4)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MISC_PWM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm_w_db_en:1;
        RBus_UInt32  db_rd_sel:1;
        RBus_UInt32  pwm_w_db_wr:1;
        RBus_UInt32  pwm_w_db_mode:1;
        RBus_UInt32  global_delay_en:1;
        RBus_UInt32  db_pulse_sel:1;
        RBus_UInt32  res1:26;
    };
}misc_pwm_pwm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm0l:1;
        RBus_UInt32  pwm0_ck:1;
        RBus_UInt32  pwm0_en:1;
        RBus_UInt32  pwm0_vs_rst_en:1;
        RBus_UInt32  pwm0_dut_8b:1;
        RBus_UInt32  pwm0_vs_delay_thr:21;
        RBus_UInt32  pwm0_vs_delay_en:1;
        RBus_UInt32  pwm0_dim_duty_en:1;
        RBus_UInt32  dut0_rounding_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pwm0_width_sel:1;
    };
}misc_pwm_pwm0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm0_cnt_mode:1;
        RBus_UInt32  pwm0_ck_sel_hs:1;
        RBus_UInt32  pwm0_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm0_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm0_m:2;
        RBus_UInt32  pwm0_n:12;
    };
}misc_pwm_pwm0_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm0_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm0_totalcnt:12;
    };
}misc_pwm_pwm0_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm1l:1;
        RBus_UInt32  pwm1_ck:1;
        RBus_UInt32  pwm1_en:1;
        RBus_UInt32  pwm1_vs_rst_en:1;
        RBus_UInt32  pwm1_dut_8b:1;
        RBus_UInt32  pwm1_vs_delay_thr:21;
        RBus_UInt32  pwm1_vs_delay_en:1;
        RBus_UInt32  pwm1_dim_duty_en:1;
        RBus_UInt32  dut1_rounding_en:1;
        RBus_UInt32  res1:3;
    };
}misc_pwm_pwm1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm1_cnt_mode:1;
        RBus_UInt32  pwm1_ck_sel_hs:1;
        RBus_UInt32  pwm1_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm1_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm1_m:2;
        RBus_UInt32  pwm1_n:12;
    };
}misc_pwm_pwm1_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm1_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm1_totalcnt:12;
    };
}misc_pwm_pwm1_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm2l:1;
        RBus_UInt32  pwm2_ck:1;
        RBus_UInt32  pwm2_en:1;
        RBus_UInt32  pwm2_vs_rst_en:1;
        RBus_UInt32  pwm2_dut_8b:1;
        RBus_UInt32  pwm2_vs_delay_thr:21;
        RBus_UInt32  pwm2_vs_delay_en:1;
        RBus_UInt32  pwm2_dim_duty_en:1;
        RBus_UInt32  dut2_rounding_en:1;
        RBus_UInt32  res1:3;
    };
}misc_pwm_pwm2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm2_cnt_mode:1;
        RBus_UInt32  pwm2_ck_sel_hs:1;
        RBus_UInt32  pwm2_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm2_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm2_m:2;
        RBus_UInt32  pwm2_n:12;
    };
}misc_pwm_pwm2_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm2_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm2_totalcnt:12;
    };
}misc_pwm_pwm2_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm3l:1;
        RBus_UInt32  pwm3_ck:1;
        RBus_UInt32  pwm3_en:1;
        RBus_UInt32  pwm3_vs_rst_en:1;
        RBus_UInt32  pwm3_dut_8b:1;
        RBus_UInt32  pwm3_vs_delay_thr:21;
        RBus_UInt32  pwm3_vs_delay_en:1;
        RBus_UInt32  pwm3_dim_duty_en:1;
        RBus_UInt32  dut3_rounding_en:1;
        RBus_UInt32  res1:3;
    };
}misc_pwm_pwm3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm3_cnt_mode:1;
        RBus_UInt32  pwm3_ck_sel_hs:1;
        RBus_UInt32  pwm3_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm3_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm3_m:2;
        RBus_UInt32  pwm3_n:12;
    };
}misc_pwm_pwm3_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm3_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm3_totalcnt:12;
    };
}misc_pwm_pwm3_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm4l:1;
        RBus_UInt32  pwm4_ck:1;
        RBus_UInt32  pwm4_en:1;
        RBus_UInt32  pwm4_vs_rst_en:1;
        RBus_UInt32  pwm4_dut_8b:1;
        RBus_UInt32  pwm4_vs_delay_thr:21;
        RBus_UInt32  pwm4_vs_delay_en:1;
        RBus_UInt32  pwm4_dim_duty_en:1;
        RBus_UInt32  dut4_rounding_en:1;
        RBus_UInt32  res1:3;
    };
}misc_pwm_pwm4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm4_cnt_mode:1;
        RBus_UInt32  pwm4_ck_sel_hs:1;
        RBus_UInt32  pwm4_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm4_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm4_m:2;
        RBus_UInt32  pwm4_n:12;
    };
}misc_pwm_pwm4_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm4_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm4_totalcnt:12;
    };
}misc_pwm_pwm4_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm5l:1;
        RBus_UInt32  pwm5_ck:1;
        RBus_UInt32  pwm5_en:1;
        RBus_UInt32  pwm5_vs_rst_en:1;
        RBus_UInt32  pwm5_dut_8b:1;
        RBus_UInt32  pwm5_vs_delay_thr:21;
        RBus_UInt32  pwm5_vs_delay_en:1;
        RBus_UInt32  pwm5_dim_duty_en:1;
        RBus_UInt32  dut5_rounding_en:1;
        RBus_UInt32  res1:3;
    };
}misc_pwm_pwm5_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm5_cnt_mode:1;
        RBus_UInt32  pwm5_ck_sel_hs:1;
        RBus_UInt32  pwm5_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm5_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm5_m:2;
        RBus_UInt32  pwm5_n:12;
    };
}misc_pwm_pwm5_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm5_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm5_totalcnt:12;
    };
}misc_pwm_pwm5_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm6l:1;
        RBus_UInt32  pwm6_ck:1;
        RBus_UInt32  pwm6_en:1;
        RBus_UInt32  pwm6_vs_rst_en:1;
        RBus_UInt32  pwm6_dut_8b:1;
        RBus_UInt32  pwm6_vs_delay_thr:21;
        RBus_UInt32  pwm6_vs_delay_en:1;
        RBus_UInt32  pwm6_dim_duty_en:1;
        RBus_UInt32  dut6_rounding_en:1;
        RBus_UInt32  res1:3;
    };
}misc_pwm_pwm6_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm6_cnt_mode:1;
        RBus_UInt32  pwm6_ck_sel_hs:1;
        RBus_UInt32  pwm6_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm6_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm6_m:2;
        RBus_UInt32  pwm6_n:12;
    };
}misc_pwm_pwm6_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm6_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm6_totalcnt:12;
    };
}misc_pwm_pwm6_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm7l:1;
        RBus_UInt32  pwm7_ck:1;
        RBus_UInt32  pwm7_en:1;
        RBus_UInt32  pwm7_vs_rst_en:1;
        RBus_UInt32  pwm7_dut_8b:1;
        RBus_UInt32  pwm7_vs_delay_thr:21;
        RBus_UInt32  pwm7_vs_delay_en:1;
        RBus_UInt32  pwm7_dim_duty_en:1;
        RBus_UInt32  dut7_rounding_en:1;
        RBus_UInt32  res1:3;
    };
}misc_pwm_pwm7_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm7_cnt_mode:1;
        RBus_UInt32  pwm7_ck_sel_hs:1;
        RBus_UInt32  pwm7_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm7_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm7_m:2;
        RBus_UInt32  pwm7_n:12;
    };
}misc_pwm_pwm7_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm7_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm7_totalcnt:12;
    };
}misc_pwm_pwm7_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  pwm7_od_mode:1;
        RBus_UInt32  pwm6_od_mode:1;
        RBus_UInt32  pwm5_od_mode:1;
        RBus_UInt32  pwm4_od_mode:1;
        RBus_UInt32  pwm3_od_mode:1;
        RBus_UInt32  pwm2_od_mode:1;
        RBus_UInt32  pwm1_od_mode:1;
        RBus_UInt32  pwm0_od_mode:1;
        RBus_UInt32  res2:4;
    };
}misc_pwm_dummy_RBUS;

#else //apply LITTLE_ENDIAN

//======MISC_PWM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  db_pulse_sel:1;
        RBus_UInt32  global_delay_en:1;
        RBus_UInt32  pwm_w_db_mode:1;
        RBus_UInt32  pwm_w_db_wr:1;
        RBus_UInt32  db_rd_sel:1;
        RBus_UInt32  pwm_w_db_en:1;
    };
}misc_pwm_pwm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm0_width_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dut0_rounding_en:1;
        RBus_UInt32  pwm0_dim_duty_en:1;
        RBus_UInt32  pwm0_vs_delay_en:1;
        RBus_UInt32  pwm0_vs_delay_thr:21;
        RBus_UInt32  pwm0_dut_8b:1;
        RBus_UInt32  pwm0_vs_rst_en:1;
        RBus_UInt32  pwm0_en:1;
        RBus_UInt32  pwm0_ck:1;
        RBus_UInt32  pwm0l:1;
    };
}misc_pwm_pwm0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm0_n:12;
        RBus_UInt32  pwm0_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  pwm0_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pwm0_ck_sel:1;
        RBus_UInt32  pwm0_ck_sel_hs:1;
        RBus_UInt32  pwm0_cnt_mode:1;
    };
}misc_pwm_pwm0_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm0_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm0_dut:12;
        RBus_UInt32  res2:4;
    };
}misc_pwm_pwm0_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dut1_rounding_en:1;
        RBus_UInt32  pwm1_dim_duty_en:1;
        RBus_UInt32  pwm1_vs_delay_en:1;
        RBus_UInt32  pwm1_vs_delay_thr:21;
        RBus_UInt32  pwm1_dut_8b:1;
        RBus_UInt32  pwm1_vs_rst_en:1;
        RBus_UInt32  pwm1_en:1;
        RBus_UInt32  pwm1_ck:1;
        RBus_UInt32  pwm1l:1;
    };
}misc_pwm_pwm1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm1_n:12;
        RBus_UInt32  pwm1_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  pwm1_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pwm1_ck_sel:1;
        RBus_UInt32  pwm1_ck_sel_hs:1;
        RBus_UInt32  pwm1_cnt_mode:1;
    };
}misc_pwm_pwm1_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm1_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm1_dut:12;
        RBus_UInt32  res2:4;
    };
}misc_pwm_pwm1_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dut2_rounding_en:1;
        RBus_UInt32  pwm2_dim_duty_en:1;
        RBus_UInt32  pwm2_vs_delay_en:1;
        RBus_UInt32  pwm2_vs_delay_thr:21;
        RBus_UInt32  pwm2_dut_8b:1;
        RBus_UInt32  pwm2_vs_rst_en:1;
        RBus_UInt32  pwm2_en:1;
        RBus_UInt32  pwm2_ck:1;
        RBus_UInt32  pwm2l:1;
    };
}misc_pwm_pwm2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm2_n:12;
        RBus_UInt32  pwm2_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  pwm2_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pwm2_ck_sel:1;
        RBus_UInt32  pwm2_ck_sel_hs:1;
        RBus_UInt32  pwm2_cnt_mode:1;
    };
}misc_pwm_pwm2_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm2_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm2_dut:12;
        RBus_UInt32  res2:4;
    };
}misc_pwm_pwm2_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dut3_rounding_en:1;
        RBus_UInt32  pwm3_dim_duty_en:1;
        RBus_UInt32  pwm3_vs_delay_en:1;
        RBus_UInt32  pwm3_vs_delay_thr:21;
        RBus_UInt32  pwm3_dut_8b:1;
        RBus_UInt32  pwm3_vs_rst_en:1;
        RBus_UInt32  pwm3_en:1;
        RBus_UInt32  pwm3_ck:1;
        RBus_UInt32  pwm3l:1;
    };
}misc_pwm_pwm3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm3_n:12;
        RBus_UInt32  pwm3_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  pwm3_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pwm3_ck_sel:1;
        RBus_UInt32  pwm3_ck_sel_hs:1;
        RBus_UInt32  pwm3_cnt_mode:1;
    };
}misc_pwm_pwm3_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm3_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm3_dut:12;
        RBus_UInt32  res2:4;
    };
}misc_pwm_pwm3_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dut4_rounding_en:1;
        RBus_UInt32  pwm4_dim_duty_en:1;
        RBus_UInt32  pwm4_vs_delay_en:1;
        RBus_UInt32  pwm4_vs_delay_thr:21;
        RBus_UInt32  pwm4_dut_8b:1;
        RBus_UInt32  pwm4_vs_rst_en:1;
        RBus_UInt32  pwm4_en:1;
        RBus_UInt32  pwm4_ck:1;
        RBus_UInt32  pwm4l:1;
    };
}misc_pwm_pwm4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm4_n:12;
        RBus_UInt32  pwm4_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  pwm4_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pwm4_ck_sel:1;
        RBus_UInt32  pwm4_ck_sel_hs:1;
        RBus_UInt32  pwm4_cnt_mode:1;
    };
}misc_pwm_pwm4_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm4_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm4_dut:12;
        RBus_UInt32  res2:4;
    };
}misc_pwm_pwm4_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dut5_rounding_en:1;
        RBus_UInt32  pwm5_dim_duty_en:1;
        RBus_UInt32  pwm5_vs_delay_en:1;
        RBus_UInt32  pwm5_vs_delay_thr:21;
        RBus_UInt32  pwm5_dut_8b:1;
        RBus_UInt32  pwm5_vs_rst_en:1;
        RBus_UInt32  pwm5_en:1;
        RBus_UInt32  pwm5_ck:1;
        RBus_UInt32  pwm5l:1;
    };
}misc_pwm_pwm5_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm5_n:12;
        RBus_UInt32  pwm5_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  pwm5_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pwm5_ck_sel:1;
        RBus_UInt32  pwm5_ck_sel_hs:1;
        RBus_UInt32  pwm5_cnt_mode:1;
    };
}misc_pwm_pwm5_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm5_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm5_dut:12;
        RBus_UInt32  res2:4;
    };
}misc_pwm_pwm5_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dut6_rounding_en:1;
        RBus_UInt32  pwm6_dim_duty_en:1;
        RBus_UInt32  pwm6_vs_delay_en:1;
        RBus_UInt32  pwm6_vs_delay_thr:21;
        RBus_UInt32  pwm6_dut_8b:1;
        RBus_UInt32  pwm6_vs_rst_en:1;
        RBus_UInt32  pwm6_en:1;
        RBus_UInt32  pwm6_ck:1;
        RBus_UInt32  pwm6l:1;
    };
}misc_pwm_pwm6_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm6_n:12;
        RBus_UInt32  pwm6_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  pwm6_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pwm6_ck_sel:1;
        RBus_UInt32  pwm6_ck_sel_hs:1;
        RBus_UInt32  pwm6_cnt_mode:1;
    };
}misc_pwm_pwm6_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm6_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm6_dut:12;
        RBus_UInt32  res2:4;
    };
}misc_pwm_pwm6_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dut7_rounding_en:1;
        RBus_UInt32  pwm7_dim_duty_en:1;
        RBus_UInt32  pwm7_vs_delay_en:1;
        RBus_UInt32  pwm7_vs_delay_thr:21;
        RBus_UInt32  pwm7_dut_8b:1;
        RBus_UInt32  pwm7_vs_rst_en:1;
        RBus_UInt32  pwm7_en:1;
        RBus_UInt32  pwm7_ck:1;
        RBus_UInt32  pwm7l:1;
    };
}misc_pwm_pwm7_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm7_n:12;
        RBus_UInt32  pwm7_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  pwm7_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pwm7_ck_sel:1;
        RBus_UInt32  pwm7_ck_sel_hs:1;
        RBus_UInt32  pwm7_cnt_mode:1;
    };
}misc_pwm_pwm7_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm7_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm7_dut:12;
        RBus_UInt32  res2:4;
    };
}misc_pwm_pwm7_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm0_od_mode:1;
        RBus_UInt32  pwm1_od_mode:1;
        RBus_UInt32  pwm2_od_mode:1;
        RBus_UInt32  pwm3_od_mode:1;
        RBus_UInt32  pwm4_od_mode:1;
        RBus_UInt32  pwm5_od_mode:1;
        RBus_UInt32  pwm6_od_mode:1;
        RBus_UInt32  pwm7_od_mode:1;
        RBus_UInt32  res2:20;
    };
}misc_pwm_dummy_RBUS;




#endif 


#endif 
