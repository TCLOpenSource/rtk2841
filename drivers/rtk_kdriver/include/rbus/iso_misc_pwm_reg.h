/**
* @file Macarthur5-DesignSpec-ISO_MISC_PWM
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ISO_MISC_PWM_REG_H_
#define _RBUS_ISO_MISC_PWM_REG_H_

#include "rbus_types.h"



//  ISO_MISC_PWM Register Address
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL                                            0x18061280
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_reg_addr                                   "0xB8061280"
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_reg                                        0xB8061280
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_inst_addr                                  "0x0000"
#define  set_ISO_MISC_PWM_MIS_PWM_DB_CTRL_reg(data)                              (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM_DB_CTRL_reg)=data)
#define  get_ISO_MISC_PWM_MIS_PWM_DB_CTRL_reg                                    (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM_DB_CTRL_reg))
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_mis_pwm_w_db_en_shift                      (31)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_db_rd_sel_shift                            (30)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_mis_pwm_w_db_mode_shift                    (28)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_mis_global_delay_en_shift                  (27)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_mis_pwm_w_db_en_mask                       (0x80000000)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_db_rd_sel_mask                             (0x40000000)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_mis_pwm_w_db_mode_mask                     (0x10000000)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_mis_global_delay_en_mask                   (0x08000000)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_mis_pwm_w_db_en(data)                      (0x80000000&((data)<<31))
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_db_rd_sel(data)                            (0x40000000&((data)<<30))
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_mis_pwm_w_db_mode(data)                    (0x10000000&((data)<<28))
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_mis_global_delay_en(data)                  (0x08000000&((data)<<27))
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_get_mis_pwm_w_db_en(data)                  ((0x80000000&(data))>>31)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_get_db_rd_sel(data)                        ((0x40000000&(data))>>30)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_get_mis_pwm_w_db_mode(data)                ((0x10000000&(data))>>28)
#define  ISO_MISC_PWM_MIS_PWM_DB_CTRL_get_mis_global_delay_en(data)              ((0x08000000&(data))>>27)

#define  ISO_MISC_PWM_MIS_PWM0_CTRL                                              0x18061284
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_reg_addr                                     "0xB8061284"
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_reg                                          0xB8061284
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_inst_addr                                    "0x0001"
#define  set_ISO_MISC_PWM_MIS_PWM0_CTRL_reg(data)                                (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM0_CTRL_reg)=data)
#define  get_ISO_MISC_PWM_MIS_PWM0_CTRL_reg                                      (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM0_CTRL_reg))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0l_shift                              (31)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_ck_shift                            (30)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_en_shift                            (29)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_vs_rst_en_shift                     (28)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_dut_8b_shift                        (27)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_pwm0_vs_delay_thr_shift                      (6)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_pwm0_vs_delay_en_shift                       (5)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_w_db_wr_shift                       (4)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm_width_sel_shift                      (0)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0l_mask                               (0x80000000)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_ck_mask                             (0x40000000)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_en_mask                             (0x20000000)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_vs_rst_en_mask                      (0x10000000)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_dut_8b_mask                         (0x08000000)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_pwm0_vs_delay_thr_mask                       (0x07FFFFC0)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_pwm0_vs_delay_en_mask                        (0x00000020)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_w_db_wr_mask                        (0x00000010)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm_width_sel_mask                       (0x00000001)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0l(data)                              (0x80000000&((data)<<31))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_ck(data)                            (0x40000000&((data)<<30))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_en(data)                            (0x20000000&((data)<<29))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_vs_rst_en(data)                     (0x10000000&((data)<<28))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_dut_8b(data)                        (0x08000000&((data)<<27))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_pwm0_vs_delay_thr(data)                      (0x07FFFFC0&((data)<<6))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_pwm0_vs_delay_en(data)                       (0x00000020&((data)<<5))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm0_w_db_wr(data)                       (0x00000010&((data)<<4))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_mis_pwm_width_sel(data)                      (0x00000001&(data))
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_get_mis_pwm0l(data)                          ((0x80000000&(data))>>31)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_get_mis_pwm0_ck(data)                        ((0x40000000&(data))>>30)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_get_mis_pwm0_en(data)                        ((0x20000000&(data))>>29)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_get_mis_pwm0_vs_rst_en(data)                 ((0x10000000&(data))>>28)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_get_mis_pwm0_dut_8b(data)                    ((0x08000000&(data))>>27)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_get_pwm0_vs_delay_thr(data)                  ((0x07FFFFC0&(data))>>6)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_get_pwm0_vs_delay_en(data)                   ((0x00000020&(data))>>5)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_get_mis_pwm0_w_db_wr(data)                   ((0x00000010&(data))>>4)
#define  ISO_MISC_PWM_MIS_PWM0_CTRL_get_mis_pwm_width_sel(data)                  (0x00000001&(data))

#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL                                       0x18061288
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_reg_addr                              "0xB8061288"
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_reg                                   0xB8061288
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_inst_addr                             "0x0002"
#define  set_ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_reg(data)                         (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_reg)=data)
#define  get_ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_reg                               (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_reg))
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_cnt_mode_shift               (31)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_ck_sel_hs_shift              (30)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_ck_sel_shift                 (29)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_cycle_max_shift              (24)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_m_shift                      (12)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_n_shift                      (0)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_cnt_mode_mask                (0x80000000)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_ck_sel_hs_mask               (0x40000000)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_ck_sel_mask                  (0x20000000)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_cycle_max_mask               (0x0F000000)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_m_mask                       (0x00003000)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_n_mask                       (0x00000FFF)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_cnt_mode(data)               (0x80000000&((data)<<31))
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_ck_sel_hs(data)              (0x40000000&((data)<<30))
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_ck_sel(data)                 (0x20000000&((data)<<29))
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_cycle_max(data)              (0x0F000000&((data)<<24))
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_m(data)                      (0x00003000&((data)<<12))
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_mis_pwm0_n(data)                      (0x00000FFF&(data))
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_get_mis_pwm0_cnt_mode(data)           ((0x80000000&(data))>>31)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_get_mis_pwm0_ck_sel_hs(data)          ((0x40000000&(data))>>30)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_get_mis_pwm0_ck_sel(data)             ((0x20000000&(data))>>29)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_get_mis_pwm0_cycle_max(data)          ((0x0F000000&(data))>>24)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_get_mis_pwm0_m(data)                  ((0x00003000&(data))>>12)
#define  ISO_MISC_PWM_MIS_PWM0_Timing_CTRL_get_mis_pwm0_n(data)                  (0x00000FFF&(data))

#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET                                          0x1806128C
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_reg_addr                                 "0xB806128C"
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_reg                                      0xB806128C
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_inst_addr                                "0x0003"
#define  set_ISO_MISC_PWM_MIS_PWM0_DUTY_SET_reg(data)                            (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM0_DUTY_SET_reg)=data)
#define  get_ISO_MISC_PWM_MIS_PWM0_DUTY_SET_reg                                  (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM0_DUTY_SET_reg))
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_mis_pwm0_dut_shift                       (16)
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_mis_pwm0_totalcnt_shift                  (0)
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_mis_pwm0_dut_mask                        (0x0FFF0000)
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_mis_pwm0_totalcnt_mask                   (0x00000FFF)
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_mis_pwm0_dut(data)                       (0x0FFF0000&((data)<<16))
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_mis_pwm0_totalcnt(data)                  (0x00000FFF&(data))
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_get_mis_pwm0_dut(data)                   ((0x0FFF0000&(data))>>16)
#define  ISO_MISC_PWM_MIS_PWM0_DUTY_SET_get_mis_pwm0_totalcnt(data)              (0x00000FFF&(data))

#define  ISO_MISC_PWM_MIS_PWM1_CTRL                                              0x18061290
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_reg_addr                                     "0xB8061290"
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_reg                                          0xB8061290
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_inst_addr                                    "0x0004"
#define  set_ISO_MISC_PWM_MIS_PWM1_CTRL_reg(data)                                (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM1_CTRL_reg)=data)
#define  get_ISO_MISC_PWM_MIS_PWM1_CTRL_reg                                      (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM1_CTRL_reg))
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1l_shift                              (31)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_ck_shift                            (30)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_en_shift                            (29)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_vs_rst_en_shift                     (28)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_dut_8b_shift                        (27)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_pwm1_vs_delay_thr_shift                      (6)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_pwm1_vs_delay_en_shift                       (5)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_w_db_wr_shift                       (4)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1l_mask                               (0x80000000)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_ck_mask                             (0x40000000)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_en_mask                             (0x20000000)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_vs_rst_en_mask                      (0x10000000)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_dut_8b_mask                         (0x08000000)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_pwm1_vs_delay_thr_mask                       (0x07FFFFC0)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_pwm1_vs_delay_en_mask                        (0x00000020)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_w_db_wr_mask                        (0x00000010)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1l(data)                              (0x80000000&((data)<<31))
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_ck(data)                            (0x40000000&((data)<<30))
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_en(data)                            (0x20000000&((data)<<29))
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_vs_rst_en(data)                     (0x10000000&((data)<<28))
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_dut_8b(data)                        (0x08000000&((data)<<27))
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_pwm1_vs_delay_thr(data)                      (0x07FFFFC0&((data)<<6))
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_pwm1_vs_delay_en(data)                       (0x00000020&((data)<<5))
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_mis_pwm1_w_db_wr(data)                       (0x00000010&((data)<<4))
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_get_mis_pwm1l(data)                          ((0x80000000&(data))>>31)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_get_mis_pwm1_ck(data)                        ((0x40000000&(data))>>30)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_get_mis_pwm1_en(data)                        ((0x20000000&(data))>>29)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_get_mis_pwm1_vs_rst_en(data)                 ((0x10000000&(data))>>28)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_get_mis_pwm1_dut_8b(data)                    ((0x08000000&(data))>>27)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_get_pwm1_vs_delay_thr(data)                  ((0x07FFFFC0&(data))>>6)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_get_pwm1_vs_delay_en(data)                   ((0x00000020&(data))>>5)
#define  ISO_MISC_PWM_MIS_PWM1_CTRL_get_mis_pwm1_w_db_wr(data)                   ((0x00000010&(data))>>4)

#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL                                       0x18061294
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_reg_addr                              "0xB8061294"
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_reg                                   0xB8061294
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_inst_addr                             "0x0005"
#define  set_ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_reg(data)                         (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_reg)=data)
#define  get_ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_reg                               (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_reg))
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_cnt_mode_shift               (31)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_ck_sel_hs_shift              (30)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_ck_sel_shift                 (29)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_cycle_max_shift              (24)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_m_shift                      (12)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_n_shift                      (0)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_cnt_mode_mask                (0x80000000)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_ck_sel_hs_mask               (0x40000000)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_ck_sel_mask                  (0x20000000)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_cycle_max_mask               (0x0F000000)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_m_mask                       (0x00003000)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_n_mask                       (0x00000FFF)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_cnt_mode(data)               (0x80000000&((data)<<31))
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_ck_sel_hs(data)              (0x40000000&((data)<<30))
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_ck_sel(data)                 (0x20000000&((data)<<29))
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_cycle_max(data)              (0x0F000000&((data)<<24))
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_m(data)                      (0x00003000&((data)<<12))
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_mis_pwm1_n(data)                      (0x00000FFF&(data))
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_get_mis_pwm1_cnt_mode(data)           ((0x80000000&(data))>>31)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_get_mis_pwm1_ck_sel_hs(data)          ((0x40000000&(data))>>30)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_get_mis_pwm1_ck_sel(data)             ((0x20000000&(data))>>29)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_get_mis_pwm1_cycle_max(data)          ((0x0F000000&(data))>>24)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_get_mis_pwm1_m(data)                  ((0x00003000&(data))>>12)
#define  ISO_MISC_PWM_MIS_PWM1_Timing_CTRL_get_mis_pwm1_n(data)                  (0x00000FFF&(data))

#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET                                          0x18061298
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_reg_addr                                 "0xB8061298"
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_reg                                      0xB8061298
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_inst_addr                                "0x0006"
#define  set_ISO_MISC_PWM_MIS_PWM1_DUTY_SET_reg(data)                            (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM1_DUTY_SET_reg)=data)
#define  get_ISO_MISC_PWM_MIS_PWM1_DUTY_SET_reg                                  (*((volatile unsigned int*)ISO_MISC_PWM_MIS_PWM1_DUTY_SET_reg))
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_mis_pwm1_dut_shift                       (16)
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_mis_pwm1_totalcnt_shift                  (0)
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_mis_pwm1_dut_mask                        (0x0FFF0000)
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_mis_pwm1_totalcnt_mask                   (0x00000FFF)
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_mis_pwm1_dut(data)                       (0x0FFF0000&((data)<<16))
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_mis_pwm1_totalcnt(data)                  (0x00000FFF&(data))
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_get_mis_pwm1_dut(data)                   ((0x0FFF0000&(data))>>16)
#define  ISO_MISC_PWM_MIS_PWM1_DUTY_SET_get_mis_pwm1_totalcnt(data)              (0x00000FFF&(data))

#define  ISO_MISC_PWM_PWM_ODMODE_CR                                              0x180612B4
#define  ISO_MISC_PWM_PWM_ODMODE_CR_reg_addr                                     "0xB80612B4"
#define  ISO_MISC_PWM_PWM_ODMODE_CR_reg                                          0xB80612B4
#define  ISO_MISC_PWM_PWM_ODMODE_CR_inst_addr                                    "0x0007"
#define  set_ISO_MISC_PWM_PWM_ODMODE_CR_reg(data)                                (*((volatile unsigned int*)ISO_MISC_PWM_PWM_ODMODE_CR_reg)=data)
#define  get_ISO_MISC_PWM_PWM_ODMODE_CR_reg                                      (*((volatile unsigned int*)ISO_MISC_PWM_PWM_ODMODE_CR_reg))
#define  ISO_MISC_PWM_PWM_ODMODE_CR_pwm1_od_mode_shift                           (31)
#define  ISO_MISC_PWM_PWM_ODMODE_CR_pwm0_od_mode_shift                           (30)
#define  ISO_MISC_PWM_PWM_ODMODE_CR_pwm1_od_mode_mask                            (0x80000000)
#define  ISO_MISC_PWM_PWM_ODMODE_CR_pwm0_od_mode_mask                            (0x40000000)
#define  ISO_MISC_PWM_PWM_ODMODE_CR_pwm1_od_mode(data)                           (0x80000000&((data)<<31))
#define  ISO_MISC_PWM_PWM_ODMODE_CR_pwm0_od_mode(data)                           (0x40000000&((data)<<30))
#define  ISO_MISC_PWM_PWM_ODMODE_CR_get_pwm1_od_mode(data)                       ((0x80000000&(data))>>31)
#define  ISO_MISC_PWM_PWM_ODMODE_CR_get_pwm0_od_mode(data)                       ((0x40000000&(data))>>30)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ISO_MISC_PWM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm_w_db_en:1;
        RBus_UInt32  db_rd_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mis_pwm_w_db_mode:1;
        RBus_UInt32  mis_global_delay_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:26;
    };
}iso_misc_pwm_mis_pwm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm0l:1;
        RBus_UInt32  mis_pwm0_ck:1;
        RBus_UInt32  mis_pwm0_en:1;
        RBus_UInt32  mis_pwm0_vs_rst_en:1;
        RBus_UInt32  mis_pwm0_dut_8b:1;
        RBus_UInt32  pwm0_vs_delay_thr:21;
        RBus_UInt32  pwm0_vs_delay_en:1;
        RBus_UInt32  mis_pwm0_w_db_wr:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  mis_pwm_width_sel:1;
    };
}iso_misc_pwm_mis_pwm0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm0_cnt_mode:1;
        RBus_UInt32  mis_pwm0_ck_sel_hs:1;
        RBus_UInt32  mis_pwm0_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mis_pwm0_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  mis_pwm0_m:2;
        RBus_UInt32  mis_pwm0_n:12;
    };
}iso_misc_pwm_mis_pwm0_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mis_pwm0_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  mis_pwm0_totalcnt:12;
    };
}iso_misc_pwm_mis_pwm0_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm1l:1;
        RBus_UInt32  mis_pwm1_ck:1;
        RBus_UInt32  mis_pwm1_en:1;
        RBus_UInt32  mis_pwm1_vs_rst_en:1;
        RBus_UInt32  mis_pwm1_dut_8b:1;
        RBus_UInt32  pwm1_vs_delay_thr:21;
        RBus_UInt32  pwm1_vs_delay_en:1;
        RBus_UInt32  mis_pwm1_w_db_wr:1;
        RBus_UInt32  res1:4;
    };
}iso_misc_pwm_mis_pwm1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm1_cnt_mode:1;
        RBus_UInt32  mis_pwm1_ck_sel_hs:1;
        RBus_UInt32  mis_pwm1_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mis_pwm1_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  mis_pwm1_m:2;
        RBus_UInt32  mis_pwm1_n:12;
    };
}iso_misc_pwm_mis_pwm1_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mis_pwm1_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  mis_pwm1_totalcnt:12;
    };
}iso_misc_pwm_mis_pwm1_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm1_od_mode:1;
        RBus_UInt32  pwm0_od_mode:1;
        RBus_UInt32  res1:30;
    };
}iso_misc_pwm_pwm_odmode_cr_RBUS;

#else //apply LITTLE_ENDIAN

//======ISO_MISC_PWM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  res2:1;
        RBus_UInt32  mis_global_delay_en:1;
        RBus_UInt32  mis_pwm_w_db_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  db_rd_sel:1;
        RBus_UInt32  mis_pwm_w_db_en:1;
    };
}iso_misc_pwm_mis_pwm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm_width_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  mis_pwm0_w_db_wr:1;
        RBus_UInt32  pwm0_vs_delay_en:1;
        RBus_UInt32  pwm0_vs_delay_thr:21;
        RBus_UInt32  mis_pwm0_dut_8b:1;
        RBus_UInt32  mis_pwm0_vs_rst_en:1;
        RBus_UInt32  mis_pwm0_en:1;
        RBus_UInt32  mis_pwm0_ck:1;
        RBus_UInt32  mis_pwm0l:1;
    };
}iso_misc_pwm_mis_pwm0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm0_n:12;
        RBus_UInt32  mis_pwm0_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  mis_pwm0_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  mis_pwm0_ck_sel:1;
        RBus_UInt32  mis_pwm0_ck_sel_hs:1;
        RBus_UInt32  mis_pwm0_cnt_mode:1;
    };
}iso_misc_pwm_mis_pwm0_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm0_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  mis_pwm0_dut:12;
        RBus_UInt32  res2:4;
    };
}iso_misc_pwm_mis_pwm0_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mis_pwm1_w_db_wr:1;
        RBus_UInt32  pwm1_vs_delay_en:1;
        RBus_UInt32  pwm1_vs_delay_thr:21;
        RBus_UInt32  mis_pwm1_dut_8b:1;
        RBus_UInt32  mis_pwm1_vs_rst_en:1;
        RBus_UInt32  mis_pwm1_en:1;
        RBus_UInt32  mis_pwm1_ck:1;
        RBus_UInt32  mis_pwm1l:1;
    };
}iso_misc_pwm_mis_pwm1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm1_n:12;
        RBus_UInt32  mis_pwm1_m:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  mis_pwm1_cycle_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  mis_pwm1_ck_sel:1;
        RBus_UInt32  mis_pwm1_ck_sel_hs:1;
        RBus_UInt32  mis_pwm1_cnt_mode:1;
    };
}iso_misc_pwm_mis_pwm1_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mis_pwm1_totalcnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  mis_pwm1_dut:12;
        RBus_UInt32  res2:4;
    };
}iso_misc_pwm_mis_pwm1_duty_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  pwm0_od_mode:1;
        RBus_UInt32  pwm1_od_mode:1;
    };
}iso_misc_pwm_pwm_odmode_cr_RBUS;




#endif 


#endif 
