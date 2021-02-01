/**
* @file rbusCBUS_PMMReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_CBUS_PMM_REG_H_
#define _RBUS_CBUS_PMM_REG_H_

#include "rbus_types.h"



//  CBUS_PMM Register Address
#define  CBUS_PMM_CBUS_STANDBY_00                                                0x18062B00
#define  CBUS_PMM_CBUS_STANDBY_00_reg_addr                                       "0xB8062B00"
#define  CBUS_PMM_CBUS_STANDBY_00_reg                                            0xB8062B00
#define  CBUS_PMM_CBUS_STANDBY_00_inst_addr                                      "0x0000"
#define  set_CBUS_PMM_CBUS_STANDBY_00_reg(data)                                  (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_00_reg)=data)
#define  get_CBUS_PMM_CBUS_STANDBY_00_reg                                        (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_00_reg))
#define  CBUS_PMM_CBUS_STANDBY_00_ecbus_dphy_in_latch_clk_inv_sel_shift          (8)
#define  CBUS_PMM_CBUS_STANDBY_00_rx_timeout_irq_shift                           (7)
#define  CBUS_PMM_CBUS_STANDBY_00_stat_ok_irq_shift                              (6)
#define  CBUS_PMM_CBUS_STANDBY_00_dummy_5_4_shift                                (4)
#define  CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_shift                           (3)
#define  CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_shift                            (2)
#define  CBUS_PMM_CBUS_STANDBY_00_wake_irq_en_shift                              (1)
#define  CBUS_PMM_CBUS_STANDBY_00_dis_irq_en_shift                               (0)
#define  CBUS_PMM_CBUS_STANDBY_00_ecbus_dphy_in_latch_clk_inv_sel_mask           (0x00000100)
#define  CBUS_PMM_CBUS_STANDBY_00_rx_timeout_irq_mask                            (0x00000080)
#define  CBUS_PMM_CBUS_STANDBY_00_stat_ok_irq_mask                               (0x00000040)
#define  CBUS_PMM_CBUS_STANDBY_00_dummy_5_4_mask                                 (0x00000030)
#define  CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask                            (0x00000008)
#define  CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask                             (0x00000004)
#define  CBUS_PMM_CBUS_STANDBY_00_wake_irq_en_mask                               (0x00000002)
#define  CBUS_PMM_CBUS_STANDBY_00_dis_irq_en_mask                                (0x00000001)
#define  CBUS_PMM_CBUS_STANDBY_00_ecbus_dphy_in_latch_clk_inv_sel(data)          (0x00000100&((data)<<8))
#define  CBUS_PMM_CBUS_STANDBY_00_rx_timeout_irq(data)                           (0x00000080&((data)<<7))
#define  CBUS_PMM_CBUS_STANDBY_00_stat_ok_irq(data)                              (0x00000040&((data)<<6))
#define  CBUS_PMM_CBUS_STANDBY_00_dummy_5_4(data)                                (0x00000030&((data)<<4))
#define  CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det(data)                           (0x00000008&((data)<<3))
#define  CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det(data)                            (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_STANDBY_00_wake_irq_en(data)                              (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_STANDBY_00_dis_irq_en(data)                               (0x00000001&(data))
#define  CBUS_PMM_CBUS_STANDBY_00_get_ecbus_dphy_in_latch_clk_inv_sel(data)      ((0x00000100&(data))>>8)
#define  CBUS_PMM_CBUS_STANDBY_00_get_rx_timeout_irq(data)                       ((0x00000080&(data))>>7)
#define  CBUS_PMM_CBUS_STANDBY_00_get_stat_ok_irq(data)                          ((0x00000040&(data))>>6)
#define  CBUS_PMM_CBUS_STANDBY_00_get_dummy_5_4(data)                            ((0x00000030&(data))>>4)
#define  CBUS_PMM_CBUS_STANDBY_00_get_wake_pulse_det(data)                       ((0x00000008&(data))>>3)
#define  CBUS_PMM_CBUS_STANDBY_00_get_dis_pulse_det(data)                        ((0x00000004&(data))>>2)
#define  CBUS_PMM_CBUS_STANDBY_00_get_wake_irq_en(data)                          ((0x00000002&(data))>>1)
#define  CBUS_PMM_CBUS_STANDBY_00_get_dis_irq_en(data)                           (0x00000001&(data))

#define  CBUS_PMM_CBUS_STANDBY_01                                                0x18062B04
#define  CBUS_PMM_CBUS_STANDBY_01_reg_addr                                       "0xB8062B04"
#define  CBUS_PMM_CBUS_STANDBY_01_reg                                            0xB8062B04
#define  CBUS_PMM_CBUS_STANDBY_01_inst_addr                                      "0x0001"
#define  set_CBUS_PMM_CBUS_STANDBY_01_reg(data)                                  (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_01_reg)=data)
#define  get_CBUS_PMM_CBUS_STANDBY_01_reg                                        (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_01_reg))
#define  CBUS_PMM_CBUS_STANDBY_01_clk_1m_div_shift                               (10)
#define  CBUS_PMM_CBUS_STANDBY_01_clk_1k_div_shift                               (0)
#define  CBUS_PMM_CBUS_STANDBY_01_clk_1m_div_mask                                (0x00003C00)
#define  CBUS_PMM_CBUS_STANDBY_01_clk_1k_div_mask                                (0x000003FF)
#define  CBUS_PMM_CBUS_STANDBY_01_clk_1m_div(data)                               (0x00003C00&((data)<<10))
#define  CBUS_PMM_CBUS_STANDBY_01_clk_1k_div(data)                               (0x000003FF&(data))
#define  CBUS_PMM_CBUS_STANDBY_01_get_clk_1m_div(data)                           ((0x00003C00&(data))>>10)
#define  CBUS_PMM_CBUS_STANDBY_01_get_clk_1k_div(data)                           (0x000003FF&(data))

#define  CBUS_PMM_CBUS_STANDBY_02                                                0x18062B08
#define  CBUS_PMM_CBUS_STANDBY_02_reg_addr                                       "0xB8062B08"
#define  CBUS_PMM_CBUS_STANDBY_02_reg                                            0xB8062B08
#define  CBUS_PMM_CBUS_STANDBY_02_inst_addr                                      "0x0002"
#define  set_CBUS_PMM_CBUS_STANDBY_02_reg(data)                                  (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_02_reg)=data)
#define  get_CBUS_PMM_CBUS_STANDBY_02_reg                                        (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_02_reg))
#define  CBUS_PMM_CBUS_STANDBY_02_dis_deb_lv_shift                               (5)
#define  CBUS_PMM_CBUS_STANDBY_02_deb_lv_shift                                   (2)
#define  CBUS_PMM_CBUS_STANDBY_02_disconn_shift                                  (0)
#define  CBUS_PMM_CBUS_STANDBY_02_dis_deb_lv_mask                                (0x000000E0)
#define  CBUS_PMM_CBUS_STANDBY_02_deb_lv_mask                                    (0x0000001C)
#define  CBUS_PMM_CBUS_STANDBY_02_disconn_mask                                   (0x00000003)
#define  CBUS_PMM_CBUS_STANDBY_02_dis_deb_lv(data)                               (0x000000E0&((data)<<5))
#define  CBUS_PMM_CBUS_STANDBY_02_deb_lv(data)                                   (0x0000001C&((data)<<2))
#define  CBUS_PMM_CBUS_STANDBY_02_disconn(data)                                  (0x00000003&(data))
#define  CBUS_PMM_CBUS_STANDBY_02_get_dis_deb_lv(data)                           ((0x000000E0&(data))>>5)
#define  CBUS_PMM_CBUS_STANDBY_02_get_deb_lv(data)                               ((0x0000001C&(data))>>2)
#define  CBUS_PMM_CBUS_STANDBY_02_get_disconn(data)                              (0x00000003&(data))

#define  CBUS_PMM_CBUS_STANDBY_04                                                0x18062B10
#define  CBUS_PMM_CBUS_STANDBY_04_reg_addr                                       "0xB8062B10"
#define  CBUS_PMM_CBUS_STANDBY_04_reg                                            0xB8062B10
#define  CBUS_PMM_CBUS_STANDBY_04_inst_addr                                      "0x0003"
#define  set_CBUS_PMM_CBUS_STANDBY_04_reg(data)                                  (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_04_reg)=data)
#define  get_CBUS_PMM_CBUS_STANDBY_04_reg                                        (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_04_reg))
#define  CBUS_PMM_CBUS_STANDBY_04_wake_offset_low2_shift                         (15)
#define  CBUS_PMM_CBUS_STANDBY_04_wake_offset_low_shift                          (10)
#define  CBUS_PMM_CBUS_STANDBY_04_wake_cnt_shift                                 (7)
#define  CBUS_PMM_CBUS_STANDBY_04_wake_offset_shift                              (2)
#define  CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_shift                             (1)
#define  CBUS_PMM_CBUS_STANDBY_04_disconn_irq_en_shift                           (0)
#define  CBUS_PMM_CBUS_STANDBY_04_wake_offset_low2_mask                          (0x000F8000)
#define  CBUS_PMM_CBUS_STANDBY_04_wake_offset_low_mask                           (0x00007C00)
#define  CBUS_PMM_CBUS_STANDBY_04_wake_cnt_mask                                  (0x00000380)
#define  CBUS_PMM_CBUS_STANDBY_04_wake_offset_mask                               (0x0000007C)
#define  CBUS_PMM_CBUS_STANDBY_04_cbus_disconn_mask                              (0x00000002)
#define  CBUS_PMM_CBUS_STANDBY_04_disconn_irq_en_mask                            (0x00000001)
#define  CBUS_PMM_CBUS_STANDBY_04_wake_offset_low2(data)                         (0x000F8000&((data)<<15))
#define  CBUS_PMM_CBUS_STANDBY_04_wake_offset_low(data)                          (0x00007C00&((data)<<10))
#define  CBUS_PMM_CBUS_STANDBY_04_wake_cnt(data)                                 (0x00000380&((data)<<7))
#define  CBUS_PMM_CBUS_STANDBY_04_wake_offset(data)                              (0x0000007C&((data)<<2))
#define  CBUS_PMM_CBUS_STANDBY_04_cbus_disconn(data)                             (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_STANDBY_04_disconn_irq_en(data)                           (0x00000001&(data))
#define  CBUS_PMM_CBUS_STANDBY_04_get_wake_offset_low2(data)                     ((0x000F8000&(data))>>15)
#define  CBUS_PMM_CBUS_STANDBY_04_get_wake_offset_low(data)                      ((0x00007C00&(data))>>10)
#define  CBUS_PMM_CBUS_STANDBY_04_get_wake_cnt(data)                             ((0x00000380&(data))>>7)
#define  CBUS_PMM_CBUS_STANDBY_04_get_wake_offset(data)                          ((0x0000007C&(data))>>2)
#define  CBUS_PMM_CBUS_STANDBY_04_get_cbus_disconn(data)                         ((0x00000002&(data))>>1)
#define  CBUS_PMM_CBUS_STANDBY_04_get_disconn_irq_en(data)                       (0x00000001&(data))

#define  CBUS_PMM_CBUS_STANDBY_05                                                0x18062B14
#define  CBUS_PMM_CBUS_STANDBY_05_reg_addr                                       "0xB8062B14"
#define  CBUS_PMM_CBUS_STANDBY_05_reg                                            0xB8062B14
#define  CBUS_PMM_CBUS_STANDBY_05_inst_addr                                      "0x0004"
#define  set_CBUS_PMM_CBUS_STANDBY_05_reg(data)                                  (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_05_reg)=data)
#define  get_CBUS_PMM_CBUS_STANDBY_05_reg                                        (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_05_reg))
#define  CBUS_PMM_CBUS_STANDBY_05_dis_upper_shift                                (4)
#define  CBUS_PMM_CBUS_STANDBY_05_dis_lower_shift                                (1)
#define  CBUS_PMM_CBUS_STANDBY_05_wake_eco_en_shift                              (0)
#define  CBUS_PMM_CBUS_STANDBY_05_dis_upper_mask                                 (0x000000F0)
#define  CBUS_PMM_CBUS_STANDBY_05_dis_lower_mask                                 (0x0000000E)
#define  CBUS_PMM_CBUS_STANDBY_05_wake_eco_en_mask                               (0x00000001)
#define  CBUS_PMM_CBUS_STANDBY_05_dis_upper(data)                                (0x000000F0&((data)<<4))
#define  CBUS_PMM_CBUS_STANDBY_05_dis_lower(data)                                (0x0000000E&((data)<<1))
#define  CBUS_PMM_CBUS_STANDBY_05_wake_eco_en(data)                              (0x00000001&(data))
#define  CBUS_PMM_CBUS_STANDBY_05_get_dis_upper(data)                            ((0x000000F0&(data))>>4)
#define  CBUS_PMM_CBUS_STANDBY_05_get_dis_lower(data)                            ((0x0000000E&(data))>>1)
#define  CBUS_PMM_CBUS_STANDBY_05_get_wake_eco_en(data)                          (0x00000001&(data))

#define  CBUS_PMM_CBUS_STANDBY_06                                                0x18062B18
#define  CBUS_PMM_CBUS_STANDBY_06_reg_addr                                       "0xB8062B18"
#define  CBUS_PMM_CBUS_STANDBY_06_reg                                            0xB8062B18
#define  CBUS_PMM_CBUS_STANDBY_06_inst_addr                                      "0x0005"
#define  set_CBUS_PMM_CBUS_STANDBY_06_reg(data)                                  (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_06_reg)=data)
#define  get_CBUS_PMM_CBUS_STANDBY_06_reg                                        (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_06_reg))
#define  CBUS_PMM_CBUS_STANDBY_06_wake_num_shift                                 (5)
#define  CBUS_PMM_CBUS_STANDBY_06_dis_num_shift                                  (0)
#define  CBUS_PMM_CBUS_STANDBY_06_wake_num_mask                                  (0x000000E0)
#define  CBUS_PMM_CBUS_STANDBY_06_dis_num_mask                                   (0x0000001F)
#define  CBUS_PMM_CBUS_STANDBY_06_wake_num(data)                                 (0x000000E0&((data)<<5))
#define  CBUS_PMM_CBUS_STANDBY_06_dis_num(data)                                  (0x0000001F&(data))
#define  CBUS_PMM_CBUS_STANDBY_06_get_wake_num(data)                             ((0x000000E0&(data))>>5)
#define  CBUS_PMM_CBUS_STANDBY_06_get_dis_num(data)                              (0x0000001F&(data))

#define  CBUS_PMM_CBUS_STANDBY_07                                                0x18062B1C
#define  CBUS_PMM_CBUS_STANDBY_07_reg_addr                                       "0xB8062B1C"
#define  CBUS_PMM_CBUS_STANDBY_07_reg                                            0xB8062B1C
#define  CBUS_PMM_CBUS_STANDBY_07_inst_addr                                      "0x0006"
#define  set_CBUS_PMM_CBUS_STANDBY_07_reg(data)                                  (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_07_reg)=data)
#define  get_CBUS_PMM_CBUS_STANDBY_07_reg                                        (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_07_reg))
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_in_tx_sig_shift                           (8)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_imp_auto_shift                            (7)
#define  CBUS_PMM_CBUS_STANDBY_07_bypass_mode_shift                              (6)
#define  CBUS_PMM_CBUS_STANDBY_07_sink_fsm_st_shift                              (3)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_100k_en_shift                             (2)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_1k_en_shift                               (1)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_in_sig_shift                              (0)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_in_tx_sig_mask                            (0x00000100)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_imp_auto_mask                             (0x00000080)
#define  CBUS_PMM_CBUS_STANDBY_07_bypass_mode_mask                               (0x00000040)
#define  CBUS_PMM_CBUS_STANDBY_07_sink_fsm_st_mask                               (0x00000038)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_100k_en_mask                              (0x00000004)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_1k_en_mask                                (0x00000002)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_in_sig_mask                               (0x00000001)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_in_tx_sig(data)                           (0x00000100&((data)<<8))
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_imp_auto(data)                            (0x00000080&((data)<<7))
#define  CBUS_PMM_CBUS_STANDBY_07_bypass_mode(data)                              (0x00000040&((data)<<6))
#define  CBUS_PMM_CBUS_STANDBY_07_sink_fsm_st(data)                              (0x00000038&((data)<<3))
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_100k_en(data)                             (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_1k_en(data)                               (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_in_sig(data)                              (0x00000001&(data))
#define  CBUS_PMM_CBUS_STANDBY_07_get_cbus_in_tx_sig(data)                       ((0x00000100&(data))>>8)
#define  CBUS_PMM_CBUS_STANDBY_07_get_cbus_imp_auto(data)                        ((0x00000080&(data))>>7)
#define  CBUS_PMM_CBUS_STANDBY_07_get_bypass_mode(data)                          ((0x00000040&(data))>>6)
#define  CBUS_PMM_CBUS_STANDBY_07_get_sink_fsm_st(data)                          ((0x00000038&(data))>>3)
#define  CBUS_PMM_CBUS_STANDBY_07_get_cbus_100k_en(data)                         ((0x00000004&(data))>>2)
#define  CBUS_PMM_CBUS_STANDBY_07_get_cbus_1k_en(data)                           ((0x00000002&(data))>>1)
#define  CBUS_PMM_CBUS_STANDBY_07_get_cbus_in_sig(data)                          (0x00000001&(data))

#define  CBUS_PMM_CBUS_STANDBY_08                                                0x18062B20
#define  CBUS_PMM_CBUS_STANDBY_08_reg_addr                                       "0xB8062B20"
#define  CBUS_PMM_CBUS_STANDBY_08_reg                                            0xB8062B20
#define  CBUS_PMM_CBUS_STANDBY_08_inst_addr                                      "0x0007"
#define  set_CBUS_PMM_CBUS_STANDBY_08_reg(data)                                  (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_08_reg)=data)
#define  get_CBUS_PMM_CBUS_STANDBY_08_reg                                        (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_08_reg))
#define  CBUS_PMM_CBUS_STANDBY_08_goto_sink1_pos_shift                           (5)
#define  CBUS_PMM_CBUS_STANDBY_08_goto_float_shift                               (4)
#define  CBUS_PMM_CBUS_STANDBY_08_goto_sink1_shift                               (3)
#define  CBUS_PMM_CBUS_STANDBY_08_cable_det_shift                                (2)
#define  CBUS_PMM_CBUS_STANDBY_08_dbg_sel_phy_shift                              (0)
#define  CBUS_PMM_CBUS_STANDBY_08_goto_sink1_pos_mask                            (0x00000020)
#define  CBUS_PMM_CBUS_STANDBY_08_goto_float_mask                                (0x00000010)
#define  CBUS_PMM_CBUS_STANDBY_08_goto_sink1_mask                                (0x00000008)
#define  CBUS_PMM_CBUS_STANDBY_08_cable_det_mask                                 (0x00000004)
#define  CBUS_PMM_CBUS_STANDBY_08_dbg_sel_phy_mask                               (0x00000003)
#define  CBUS_PMM_CBUS_STANDBY_08_goto_sink1_pos(data)                           (0x00000020&((data)<<5))
#define  CBUS_PMM_CBUS_STANDBY_08_goto_float(data)                               (0x00000010&((data)<<4))
#define  CBUS_PMM_CBUS_STANDBY_08_goto_sink1(data)                               (0x00000008&((data)<<3))
#define  CBUS_PMM_CBUS_STANDBY_08_cable_det(data)                                (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_STANDBY_08_dbg_sel_phy(data)                              (0x00000003&(data))
#define  CBUS_PMM_CBUS_STANDBY_08_get_goto_sink1_pos(data)                       ((0x00000020&(data))>>5)
#define  CBUS_PMM_CBUS_STANDBY_08_get_goto_float(data)                           ((0x00000010&(data))>>4)
#define  CBUS_PMM_CBUS_STANDBY_08_get_goto_sink1(data)                           ((0x00000008&(data))>>3)
#define  CBUS_PMM_CBUS_STANDBY_08_get_cable_det(data)                            ((0x00000004&(data))>>2)
#define  CBUS_PMM_CBUS_STANDBY_08_get_dbg_sel_phy(data)                          (0x00000003&(data))

#define  CBUS_PMM_CBUS_STANDBY_09                                                0x18062B24
#define  CBUS_PMM_CBUS_STANDBY_09_reg_addr                                       "0xB8062B24"
#define  CBUS_PMM_CBUS_STANDBY_09_reg                                            0xB8062B24
#define  CBUS_PMM_CBUS_STANDBY_09_inst_addr                                      "0x0008"
#define  set_CBUS_PMM_CBUS_STANDBY_09_reg(data)                                  (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_09_reg)=data)
#define  get_CBUS_PMM_CBUS_STANDBY_09_reg                                        (*((volatile unsigned int*)CBUS_PMM_CBUS_STANDBY_09_reg))
#define  CBUS_PMM_CBUS_STANDBY_09_ctrl_09_resv_shift                             (0)
#define  CBUS_PMM_CBUS_STANDBY_09_ctrl_09_resv_mask                              (0xFFFFFFFF)
#define  CBUS_PMM_CBUS_STANDBY_09_ctrl_09_resv(data)                             (0xFFFFFFFF&(data))
#define  CBUS_PMM_CBUS_STANDBY_09_get_ctrl_09_resv(data)                         (0xFFFFFFFF&(data))

#define  CBUS_PMM_CBUS_PHY_0                                                     0x18062B30
#define  CBUS_PMM_CBUS_PHY_0_reg_addr                                            "0xB8062B30"
#define  CBUS_PMM_CBUS_PHY_0_reg                                                 0xB8062B30
#define  CBUS_PMM_CBUS_PHY_0_inst_addr                                           "0x0009"
#define  set_CBUS_PMM_CBUS_PHY_0_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_0_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_0_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_0_reg))
#define  CBUS_PMM_CBUS_PHY_0_cbus_control_shift                                  (16)
#define  CBUS_PMM_CBUS_PHY_0_sel_phy_soft_rst_n_shift                            (0)
#define  CBUS_PMM_CBUS_PHY_0_cbus_control_mask                                   (0x00FF0000)
#define  CBUS_PMM_CBUS_PHY_0_sel_phy_soft_rst_n_mask                             (0x00000001)
#define  CBUS_PMM_CBUS_PHY_0_cbus_control(data)                                  (0x00FF0000&((data)<<16))
#define  CBUS_PMM_CBUS_PHY_0_sel_phy_soft_rst_n(data)                            (0x00000001&(data))
#define  CBUS_PMM_CBUS_PHY_0_get_cbus_control(data)                              ((0x00FF0000&(data))>>16)
#define  CBUS_PMM_CBUS_PHY_0_get_sel_phy_soft_rst_n(data)                        (0x00000001&(data))

#define  CBUS_PMM_CBUS_PHY_2                                                     0x18062B38
#define  CBUS_PMM_CBUS_PHY_2_reg_addr                                            "0xB8062B38"
#define  CBUS_PMM_CBUS_PHY_2_reg                                                 0xB8062B38
#define  CBUS_PMM_CBUS_PHY_2_inst_addr                                           "0x000A"
#define  set_CBUS_PMM_CBUS_PHY_2_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_2_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_2_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_2_reg))
#define  CBUS_PMM_CBUS_PHY_2_dummy_31_shift                                      (31)
#define  CBUS_PMM_CBUS_PHY_2_mhl_r10k_en_shift                                   (26)
#define  CBUS_PMM_CBUS_PHY_2_dummy_7_shift                                       (7)
#define  CBUS_PMM_CBUS_PHY_2_en_driver_tx_shift                                  (2)
#define  CBUS_PMM_CBUS_PHY_2_dummy_31_mask                                       (0x80000000)
#define  CBUS_PMM_CBUS_PHY_2_mhl_r10k_en_mask                                    (0x0C000000)
#define  CBUS_PMM_CBUS_PHY_2_dummy_7_mask                                        (0x00000080)
#define  CBUS_PMM_CBUS_PHY_2_en_driver_tx_mask                                   (0x00000004)
#define  CBUS_PMM_CBUS_PHY_2_dummy_31(data)                                      (0x80000000&((data)<<31))
#define  CBUS_PMM_CBUS_PHY_2_mhl_r10k_en(data)                                   (0x0C000000&((data)<<26))
#define  CBUS_PMM_CBUS_PHY_2_dummy_7(data)                                       (0x00000080&((data)<<7))
#define  CBUS_PMM_CBUS_PHY_2_en_driver_tx(data)                                  (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_PHY_2_get_dummy_31(data)                                  ((0x80000000&(data))>>31)
#define  CBUS_PMM_CBUS_PHY_2_get_mhl_r10k_en(data)                               ((0x0C000000&(data))>>26)
#define  CBUS_PMM_CBUS_PHY_2_get_dummy_7(data)                                   ((0x00000080&(data))>>7)
#define  CBUS_PMM_CBUS_PHY_2_get_en_driver_tx(data)                              ((0x00000004&(data))>>2)

#define  CBUS_PMM_CBUS_PHY_3                                                     0x18062B3C
#define  CBUS_PMM_CBUS_PHY_3_reg_addr                                            "0xB8062B3C"
#define  CBUS_PMM_CBUS_PHY_3_reg                                                 0xB8062B3C
#define  CBUS_PMM_CBUS_PHY_3_inst_addr                                           "0x000B"
#define  set_CBUS_PMM_CBUS_PHY_3_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_3_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_3_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_3_reg))
#define  CBUS_PMM_CBUS_PHY_3_en_100k_shift                                       (29)
#define  CBUS_PMM_CBUS_PHY_3_en_1k_shift                                         (28)
#define  CBUS_PMM_CBUS_PHY_3_cbus_res_tst_shift                                  (16)
#define  CBUS_PMM_CBUS_PHY_3_hpd_r1k_bypass_shift                                (15)
#define  CBUS_PMM_CBUS_PHY_3_hdmi_mhl_sel_shift                                  (14)
#define  CBUS_PMM_CBUS_PHY_3_cbus_5v_detect_shift                                (11)
#define  CBUS_PMM_CBUS_PHY_3_hpd_r1k_sel_shift                                   (8)
#define  CBUS_PMM_CBUS_PHY_3_cbus_o_rx_shift                                     (7)
#define  CBUS_PMM_CBUS_PHY_3_cbus_sr_rx_shift                                    (6)
#define  CBUS_PMM_CBUS_PHY_3_cbus_smt_rx_shift                                   (5)
#define  CBUS_PMM_CBUS_PHY_3_cbus_pu_rx_shift                                    (4)
#define  CBUS_PMM_CBUS_PHY_3_cbus_pd_rx_shift                                    (3)
#define  CBUS_PMM_CBUS_PHY_3_cbus_i_rx_shift                                     (2)
#define  CBUS_PMM_CBUS_PHY_3_cbus_e2_rx_shift                                    (1)
#define  CBUS_PMM_CBUS_PHY_3_cbus_e_rx_shift                                     (0)
#define  CBUS_PMM_CBUS_PHY_3_en_100k_mask                                        (0x20000000)
#define  CBUS_PMM_CBUS_PHY_3_en_1k_mask                                          (0x10000000)
#define  CBUS_PMM_CBUS_PHY_3_cbus_res_tst_mask                                   (0x03FF0000)
#define  CBUS_PMM_CBUS_PHY_3_hpd_r1k_bypass_mask                                 (0x00008000)
#define  CBUS_PMM_CBUS_PHY_3_hdmi_mhl_sel_mask                                   (0x00004000)
#define  CBUS_PMM_CBUS_PHY_3_cbus_5v_detect_mask                                 (0x00000800)
#define  CBUS_PMM_CBUS_PHY_3_hpd_r1k_sel_mask                                    (0x00000700)
#define  CBUS_PMM_CBUS_PHY_3_cbus_o_rx_mask                                      (0x00000080)
#define  CBUS_PMM_CBUS_PHY_3_cbus_sr_rx_mask                                     (0x00000040)
#define  CBUS_PMM_CBUS_PHY_3_cbus_smt_rx_mask                                    (0x00000020)
#define  CBUS_PMM_CBUS_PHY_3_cbus_pu_rx_mask                                     (0x00000010)
#define  CBUS_PMM_CBUS_PHY_3_cbus_pd_rx_mask                                     (0x00000008)
#define  CBUS_PMM_CBUS_PHY_3_cbus_i_rx_mask                                      (0x00000004)
#define  CBUS_PMM_CBUS_PHY_3_cbus_e2_rx_mask                                     (0x00000002)
#define  CBUS_PMM_CBUS_PHY_3_cbus_e_rx_mask                                      (0x00000001)
#define  CBUS_PMM_CBUS_PHY_3_en_100k(data)                                       (0x20000000&((data)<<29))
#define  CBUS_PMM_CBUS_PHY_3_en_1k(data)                                         (0x10000000&((data)<<28))
#define  CBUS_PMM_CBUS_PHY_3_cbus_res_tst(data)                                  (0x03FF0000&((data)<<16))
#define  CBUS_PMM_CBUS_PHY_3_hpd_r1k_bypass(data)                                (0x00008000&((data)<<15))
#define  CBUS_PMM_CBUS_PHY_3_hdmi_mhl_sel(data)                                  (0x00004000&((data)<<14))
#define  CBUS_PMM_CBUS_PHY_3_cbus_5v_detect(data)                                (0x00000800&((data)<<11))
#define  CBUS_PMM_CBUS_PHY_3_hpd_r1k_sel(data)                                   (0x00000700&((data)<<8))
#define  CBUS_PMM_CBUS_PHY_3_cbus_o_rx(data)                                     (0x00000080&((data)<<7))
#define  CBUS_PMM_CBUS_PHY_3_cbus_sr_rx(data)                                    (0x00000040&((data)<<6))
#define  CBUS_PMM_CBUS_PHY_3_cbus_smt_rx(data)                                   (0x00000020&((data)<<5))
#define  CBUS_PMM_CBUS_PHY_3_cbus_pu_rx(data)                                    (0x00000010&((data)<<4))
#define  CBUS_PMM_CBUS_PHY_3_cbus_pd_rx(data)                                    (0x00000008&((data)<<3))
#define  CBUS_PMM_CBUS_PHY_3_cbus_i_rx(data)                                     (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_PHY_3_cbus_e2_rx(data)                                    (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_PHY_3_cbus_e_rx(data)                                     (0x00000001&(data))
#define  CBUS_PMM_CBUS_PHY_3_get_en_100k(data)                                   ((0x20000000&(data))>>29)
#define  CBUS_PMM_CBUS_PHY_3_get_en_1k(data)                                     ((0x10000000&(data))>>28)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_res_tst(data)                              ((0x03FF0000&(data))>>16)
#define  CBUS_PMM_CBUS_PHY_3_get_hpd_r1k_bypass(data)                            ((0x00008000&(data))>>15)
#define  CBUS_PMM_CBUS_PHY_3_get_hdmi_mhl_sel(data)                              ((0x00004000&(data))>>14)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_5v_detect(data)                            ((0x00000800&(data))>>11)
#define  CBUS_PMM_CBUS_PHY_3_get_hpd_r1k_sel(data)                               ((0x00000700&(data))>>8)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_o_rx(data)                                 ((0x00000080&(data))>>7)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_sr_rx(data)                                ((0x00000040&(data))>>6)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_smt_rx(data)                               ((0x00000020&(data))>>5)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_pu_rx(data)                                ((0x00000010&(data))>>4)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_pd_rx(data)                                ((0x00000008&(data))>>3)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_i_rx(data)                                 ((0x00000004&(data))>>2)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_e2_rx(data)                                ((0x00000002&(data))>>1)
#define  CBUS_PMM_CBUS_PHY_3_get_cbus_e_rx(data)                                 (0x00000001&(data))

#define  CBUS_PMM_CBUS_PHY_4                                                     0x18062B40
#define  CBUS_PMM_CBUS_PHY_4_reg_addr                                            "0xB8062B40"
#define  CBUS_PMM_CBUS_PHY_4_reg                                                 0xB8062B40
#define  CBUS_PMM_CBUS_PHY_4_inst_addr                                           "0x000C"
#define  set_CBUS_PMM_CBUS_PHY_4_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_4_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_4_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_4_reg))
#define  CBUS_PMM_CBUS_PHY_4_cbus_res_tst_rx_shift                               (26)
#define  CBUS_PMM_CBUS_PHY_4_sel_input_high_rx_shift                             (24)
#define  CBUS_PMM_CBUS_PHY_4_sel_input_low_rx_shift                              (22)
#define  CBUS_PMM_CBUS_PHY_4_triming_mode_rx_shift                               (20)
#define  CBUS_PMM_CBUS_PHY_4_mhl_r1k_rx_shift                                    (16)
#define  CBUS_PMM_CBUS_PHY_4_res_ok_rx_shift                                     (15)
#define  CBUS_PMM_CBUS_PHY_4_mhl_bmos_en_rx_shift                                (14)
#define  CBUS_PMM_CBUS_PHY_4_en_res_cal_cbus_rx_shift                            (13)
#define  CBUS_PMM_CBUS_PHY_4_adjr_100k_rx_shift                                  (8)
#define  CBUS_PMM_CBUS_PHY_4_auto_k_100k_rx_shift                                (7)
#define  CBUS_PMM_CBUS_PHY_4_cbus_strc_rx_shift                                  (4)
#define  CBUS_PMM_CBUS_PHY_4_sel_cbusb_gpio_rx_shift                             (3)
#define  CBUS_PMM_CBUS_PHY_4_en_driver_rx_shift                                  (2)
#define  CBUS_PMM_CBUS_PHY_4_en_cmp_rx_shift                                     (1)
#define  CBUS_PMM_CBUS_PHY_4_en_cbus_rx_shift                                    (0)
#define  CBUS_PMM_CBUS_PHY_4_cbus_res_tst_rx_mask                                (0xFC000000)
#define  CBUS_PMM_CBUS_PHY_4_sel_input_high_rx_mask                              (0x03000000)
#define  CBUS_PMM_CBUS_PHY_4_sel_input_low_rx_mask                               (0x00C00000)
#define  CBUS_PMM_CBUS_PHY_4_triming_mode_rx_mask                                (0x00100000)
#define  CBUS_PMM_CBUS_PHY_4_mhl_r1k_rx_mask                                     (0x000F0000)
#define  CBUS_PMM_CBUS_PHY_4_res_ok_rx_mask                                      (0x00008000)
#define  CBUS_PMM_CBUS_PHY_4_mhl_bmos_en_rx_mask                                 (0x00004000)
#define  CBUS_PMM_CBUS_PHY_4_en_res_cal_cbus_rx_mask                             (0x00002000)
#define  CBUS_PMM_CBUS_PHY_4_adjr_100k_rx_mask                                   (0x00001F00)
#define  CBUS_PMM_CBUS_PHY_4_auto_k_100k_rx_mask                                 (0x00000080)
#define  CBUS_PMM_CBUS_PHY_4_cbus_strc_rx_mask                                   (0x00000070)
#define  CBUS_PMM_CBUS_PHY_4_sel_cbusb_gpio_rx_mask                              (0x00000008)
#define  CBUS_PMM_CBUS_PHY_4_en_driver_rx_mask                                   (0x00000004)
#define  CBUS_PMM_CBUS_PHY_4_en_cmp_rx_mask                                      (0x00000002)
#define  CBUS_PMM_CBUS_PHY_4_en_cbus_rx_mask                                     (0x00000001)
#define  CBUS_PMM_CBUS_PHY_4_cbus_res_tst_rx(data)                               (0xFC000000&((data)<<26))
#define  CBUS_PMM_CBUS_PHY_4_sel_input_high_rx(data)                             (0x03000000&((data)<<24))
#define  CBUS_PMM_CBUS_PHY_4_sel_input_low_rx(data)                              (0x00C00000&((data)<<22))
#define  CBUS_PMM_CBUS_PHY_4_triming_mode_rx(data)                               (0x00100000&((data)<<20))
#define  CBUS_PMM_CBUS_PHY_4_mhl_r1k_rx(data)                                    (0x000F0000&((data)<<16))
#define  CBUS_PMM_CBUS_PHY_4_res_ok_rx(data)                                     (0x00008000&((data)<<15))
#define  CBUS_PMM_CBUS_PHY_4_mhl_bmos_en_rx(data)                                (0x00004000&((data)<<14))
#define  CBUS_PMM_CBUS_PHY_4_en_res_cal_cbus_rx(data)                            (0x00002000&((data)<<13))
#define  CBUS_PMM_CBUS_PHY_4_adjr_100k_rx(data)                                  (0x00001F00&((data)<<8))
#define  CBUS_PMM_CBUS_PHY_4_auto_k_100k_rx(data)                                (0x00000080&((data)<<7))
#define  CBUS_PMM_CBUS_PHY_4_cbus_strc_rx(data)                                  (0x00000070&((data)<<4))
#define  CBUS_PMM_CBUS_PHY_4_sel_cbusb_gpio_rx(data)                             (0x00000008&((data)<<3))
#define  CBUS_PMM_CBUS_PHY_4_en_driver_rx(data)                                  (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_PHY_4_en_cmp_rx(data)                                     (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_PHY_4_en_cbus_rx(data)                                    (0x00000001&(data))
#define  CBUS_PMM_CBUS_PHY_4_get_cbus_res_tst_rx(data)                           ((0xFC000000&(data))>>26)
#define  CBUS_PMM_CBUS_PHY_4_get_sel_input_high_rx(data)                         ((0x03000000&(data))>>24)
#define  CBUS_PMM_CBUS_PHY_4_get_sel_input_low_rx(data)                          ((0x00C00000&(data))>>22)
#define  CBUS_PMM_CBUS_PHY_4_get_triming_mode_rx(data)                           ((0x00100000&(data))>>20)
#define  CBUS_PMM_CBUS_PHY_4_get_mhl_r1k_rx(data)                                ((0x000F0000&(data))>>16)
#define  CBUS_PMM_CBUS_PHY_4_get_res_ok_rx(data)                                 ((0x00008000&(data))>>15)
#define  CBUS_PMM_CBUS_PHY_4_get_mhl_bmos_en_rx(data)                            ((0x00004000&(data))>>14)
#define  CBUS_PMM_CBUS_PHY_4_get_en_res_cal_cbus_rx(data)                        ((0x00002000&(data))>>13)
#define  CBUS_PMM_CBUS_PHY_4_get_adjr_100k_rx(data)                              ((0x00001F00&(data))>>8)
#define  CBUS_PMM_CBUS_PHY_4_get_auto_k_100k_rx(data)                            ((0x00000080&(data))>>7)
#define  CBUS_PMM_CBUS_PHY_4_get_cbus_strc_rx(data)                              ((0x00000070&(data))>>4)
#define  CBUS_PMM_CBUS_PHY_4_get_sel_cbusb_gpio_rx(data)                         ((0x00000008&(data))>>3)
#define  CBUS_PMM_CBUS_PHY_4_get_en_driver_rx(data)                              ((0x00000004&(data))>>2)
#define  CBUS_PMM_CBUS_PHY_4_get_en_cmp_rx(data)                                 ((0x00000002&(data))>>1)
#define  CBUS_PMM_CBUS_PHY_4_get_en_cbus_rx(data)                                (0x00000001&(data))

#define  CBUS_PMM_CBUS_PHY_5                                                     0x18062B44
#define  CBUS_PMM_CBUS_PHY_5_reg_addr                                            "0xB8062B44"
#define  CBUS_PMM_CBUS_PHY_5_reg                                                 0xB8062B44
#define  CBUS_PMM_CBUS_PHY_5_inst_addr                                           "0x000D"
#define  set_CBUS_PMM_CBUS_PHY_5_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_5_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_5_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_5_reg))
#define  CBUS_PMM_CBUS_PHY_5_buf_rsel_ecbusrx_shift                              (28)
#define  CBUS_PMM_CBUS_PHY_5_buf_vref_sel_ecbusrx_shift                          (24)
#define  CBUS_PMM_CBUS_PHY_5_bkwd_byp_ecbusrx_shift                              (23)
#define  CBUS_PMM_CBUS_PHY_5_buf_r50_ecbusrx_shift                               (16)
#define  CBUS_PMM_CBUS_PHY_5_en_buf_ecbusrx_shift                                (15)
#define  CBUS_PMM_CBUS_PHY_5_buf_ibsel_ecbusrx_shift                             (12)
#define  CBUS_PMM_CBUS_PHY_5_pll_cp_ecbusrx_shift                                (10)
#define  CBUS_PMM_CBUS_PHY_5_pll_cs_ecbusrx_shift                                (8)
#define  CBUS_PMM_CBUS_PHY_5_pll_wdo_ecbusrx_shift                               (7)
#define  CBUS_PMM_CBUS_PHY_5_pll_rs_ecbusrx_shift                                (4)
#define  CBUS_PMM_CBUS_PHY_5_pll_ip_ecbusrx_shift                                (0)
#define  CBUS_PMM_CBUS_PHY_5_buf_rsel_ecbusrx_mask                               (0x30000000)
#define  CBUS_PMM_CBUS_PHY_5_buf_vref_sel_ecbusrx_mask                           (0x03000000)
#define  CBUS_PMM_CBUS_PHY_5_bkwd_byp_ecbusrx_mask                               (0x00800000)
#define  CBUS_PMM_CBUS_PHY_5_buf_r50_ecbusrx_mask                                (0x000F0000)
#define  CBUS_PMM_CBUS_PHY_5_en_buf_ecbusrx_mask                                 (0x00008000)
#define  CBUS_PMM_CBUS_PHY_5_buf_ibsel_ecbusrx_mask                              (0x00007000)
#define  CBUS_PMM_CBUS_PHY_5_pll_cp_ecbusrx_mask                                 (0x00000C00)
#define  CBUS_PMM_CBUS_PHY_5_pll_cs_ecbusrx_mask                                 (0x00000300)
#define  CBUS_PMM_CBUS_PHY_5_pll_wdo_ecbusrx_mask                                (0x00000080)
#define  CBUS_PMM_CBUS_PHY_5_pll_rs_ecbusrx_mask                                 (0x00000070)
#define  CBUS_PMM_CBUS_PHY_5_pll_ip_ecbusrx_mask                                 (0x00000007)
#define  CBUS_PMM_CBUS_PHY_5_buf_rsel_ecbusrx(data)                              (0x30000000&((data)<<28))
#define  CBUS_PMM_CBUS_PHY_5_buf_vref_sel_ecbusrx(data)                          (0x03000000&((data)<<24))
#define  CBUS_PMM_CBUS_PHY_5_bkwd_byp_ecbusrx(data)                              (0x00800000&((data)<<23))
#define  CBUS_PMM_CBUS_PHY_5_buf_r50_ecbusrx(data)                               (0x000F0000&((data)<<16))
#define  CBUS_PMM_CBUS_PHY_5_en_buf_ecbusrx(data)                                (0x00008000&((data)<<15))
#define  CBUS_PMM_CBUS_PHY_5_buf_ibsel_ecbusrx(data)                             (0x00007000&((data)<<12))
#define  CBUS_PMM_CBUS_PHY_5_pll_cp_ecbusrx(data)                                (0x00000C00&((data)<<10))
#define  CBUS_PMM_CBUS_PHY_5_pll_cs_ecbusrx(data)                                (0x00000300&((data)<<8))
#define  CBUS_PMM_CBUS_PHY_5_pll_wdo_ecbusrx(data)                               (0x00000080&((data)<<7))
#define  CBUS_PMM_CBUS_PHY_5_pll_rs_ecbusrx(data)                                (0x00000070&((data)<<4))
#define  CBUS_PMM_CBUS_PHY_5_pll_ip_ecbusrx(data)                                (0x00000007&(data))
#define  CBUS_PMM_CBUS_PHY_5_get_buf_rsel_ecbusrx(data)                          ((0x30000000&(data))>>28)
#define  CBUS_PMM_CBUS_PHY_5_get_buf_vref_sel_ecbusrx(data)                      ((0x03000000&(data))>>24)
#define  CBUS_PMM_CBUS_PHY_5_get_bkwd_byp_ecbusrx(data)                          ((0x00800000&(data))>>23)
#define  CBUS_PMM_CBUS_PHY_5_get_buf_r50_ecbusrx(data)                           ((0x000F0000&(data))>>16)
#define  CBUS_PMM_CBUS_PHY_5_get_en_buf_ecbusrx(data)                            ((0x00008000&(data))>>15)
#define  CBUS_PMM_CBUS_PHY_5_get_buf_ibsel_ecbusrx(data)                         ((0x00007000&(data))>>12)
#define  CBUS_PMM_CBUS_PHY_5_get_pll_cp_ecbusrx(data)                            ((0x00000C00&(data))>>10)
#define  CBUS_PMM_CBUS_PHY_5_get_pll_cs_ecbusrx(data)                            ((0x00000300&(data))>>8)
#define  CBUS_PMM_CBUS_PHY_5_get_pll_wdo_ecbusrx(data)                           ((0x00000080&(data))>>7)
#define  CBUS_PMM_CBUS_PHY_5_get_pll_rs_ecbusrx(data)                            ((0x00000070&(data))>>4)
#define  CBUS_PMM_CBUS_PHY_5_get_pll_ip_ecbusrx(data)                            (0x00000007&(data))

#define  CBUS_PMM_CBUS_PHY_6                                                     0x18062B48
#define  CBUS_PMM_CBUS_PHY_6_reg_addr                                            "0xB8062B48"
#define  CBUS_PMM_CBUS_PHY_6_reg                                                 0xB8062B48
#define  CBUS_PMM_CBUS_PHY_6_inst_addr                                           "0x000E"
#define  set_CBUS_PMM_CBUS_PHY_6_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_6_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_6_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_6_reg))
#define  CBUS_PMM_CBUS_PHY_6_ecbuspll_rstb_shift                                 (31)
#define  CBUS_PMM_CBUS_PHY_6_cko_tst_en_ecbusrx_shift                            (29)
#define  CBUS_PMM_CBUS_PHY_6_deglitch_en_ecbusrx_shift                           (28)
#define  CBUS_PMM_CBUS_PHY_6_test_en_ecbusrx_shift                               (27)
#define  CBUS_PMM_CBUS_PHY_6_pll_phsel_ecbusrx_shift                             (23)
#define  CBUS_PMM_CBUS_PHY_6_pll_tdsel_ecbusrx_shift                             (20)
#define  CBUS_PMM_CBUS_PHY_6_pll_n_ecbusrx_shift                                 (16)
#define  CBUS_PMM_CBUS_PHY_6_pll_m_ecbusrx_shift                                 (8)
#define  CBUS_PMM_CBUS_PHY_6_pll_ldo_sel_ecbusrx_shift                           (6)
#define  CBUS_PMM_CBUS_PHY_6_pll_freeze_ecbusrx_shift                            (5)
#define  CBUS_PMM_CBUS_PHY_6_pll_pow_ecbusrx_shift                               (4)
#define  CBUS_PMM_CBUS_PHY_6_pll_ldo_pow_ecbusrx_shift                           (3)
#define  CBUS_PMM_CBUS_PHY_6_pll_vcorstb_ecbusrx_shift                           (2)
#define  CBUS_PMM_CBUS_PHY_6_pll_wdrst_ecbusrx_shift                             (1)
#define  CBUS_PMM_CBUS_PHY_6_pll_wdset_ecbusrx_shift                             (0)
#define  CBUS_PMM_CBUS_PHY_6_ecbuspll_rstb_mask                                  (0x80000000)
#define  CBUS_PMM_CBUS_PHY_6_cko_tst_en_ecbusrx_mask                             (0x20000000)
#define  CBUS_PMM_CBUS_PHY_6_deglitch_en_ecbusrx_mask                            (0x10000000)
#define  CBUS_PMM_CBUS_PHY_6_test_en_ecbusrx_mask                                (0x08000000)
#define  CBUS_PMM_CBUS_PHY_6_pll_phsel_ecbusrx_mask                              (0x07800000)
#define  CBUS_PMM_CBUS_PHY_6_pll_tdsel_ecbusrx_mask                              (0x00700000)
#define  CBUS_PMM_CBUS_PHY_6_pll_n_ecbusrx_mask                                  (0x00070000)
#define  CBUS_PMM_CBUS_PHY_6_pll_m_ecbusrx_mask                                  (0x0000FF00)
#define  CBUS_PMM_CBUS_PHY_6_pll_ldo_sel_ecbusrx_mask                            (0x000000C0)
#define  CBUS_PMM_CBUS_PHY_6_pll_freeze_ecbusrx_mask                             (0x00000020)
#define  CBUS_PMM_CBUS_PHY_6_pll_pow_ecbusrx_mask                                (0x00000010)
#define  CBUS_PMM_CBUS_PHY_6_pll_ldo_pow_ecbusrx_mask                            (0x00000008)
#define  CBUS_PMM_CBUS_PHY_6_pll_vcorstb_ecbusrx_mask                            (0x00000004)
#define  CBUS_PMM_CBUS_PHY_6_pll_wdrst_ecbusrx_mask                              (0x00000002)
#define  CBUS_PMM_CBUS_PHY_6_pll_wdset_ecbusrx_mask                              (0x00000001)
#define  CBUS_PMM_CBUS_PHY_6_ecbuspll_rstb(data)                                 (0x80000000&((data)<<31))
#define  CBUS_PMM_CBUS_PHY_6_cko_tst_en_ecbusrx(data)                            (0x20000000&((data)<<29))
#define  CBUS_PMM_CBUS_PHY_6_deglitch_en_ecbusrx(data)                           (0x10000000&((data)<<28))
#define  CBUS_PMM_CBUS_PHY_6_test_en_ecbusrx(data)                               (0x08000000&((data)<<27))
#define  CBUS_PMM_CBUS_PHY_6_pll_phsel_ecbusrx(data)                             (0x07800000&((data)<<23))
#define  CBUS_PMM_CBUS_PHY_6_pll_tdsel_ecbusrx(data)                             (0x00700000&((data)<<20))
#define  CBUS_PMM_CBUS_PHY_6_pll_n_ecbusrx(data)                                 (0x00070000&((data)<<16))
#define  CBUS_PMM_CBUS_PHY_6_pll_m_ecbusrx(data)                                 (0x0000FF00&((data)<<8))
#define  CBUS_PMM_CBUS_PHY_6_pll_ldo_sel_ecbusrx(data)                           (0x000000C0&((data)<<6))
#define  CBUS_PMM_CBUS_PHY_6_pll_freeze_ecbusrx(data)                            (0x00000020&((data)<<5))
#define  CBUS_PMM_CBUS_PHY_6_pll_pow_ecbusrx(data)                               (0x00000010&((data)<<4))
#define  CBUS_PMM_CBUS_PHY_6_pll_ldo_pow_ecbusrx(data)                           (0x00000008&((data)<<3))
#define  CBUS_PMM_CBUS_PHY_6_pll_vcorstb_ecbusrx(data)                           (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_PHY_6_pll_wdrst_ecbusrx(data)                             (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_PHY_6_pll_wdset_ecbusrx(data)                             (0x00000001&(data))
#define  CBUS_PMM_CBUS_PHY_6_get_ecbuspll_rstb(data)                             ((0x80000000&(data))>>31)
#define  CBUS_PMM_CBUS_PHY_6_get_cko_tst_en_ecbusrx(data)                        ((0x20000000&(data))>>29)
#define  CBUS_PMM_CBUS_PHY_6_get_deglitch_en_ecbusrx(data)                       ((0x10000000&(data))>>28)
#define  CBUS_PMM_CBUS_PHY_6_get_test_en_ecbusrx(data)                           ((0x08000000&(data))>>27)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_phsel_ecbusrx(data)                         ((0x07800000&(data))>>23)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_tdsel_ecbusrx(data)                         ((0x00700000&(data))>>20)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_n_ecbusrx(data)                             ((0x00070000&(data))>>16)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_m_ecbusrx(data)                             ((0x0000FF00&(data))>>8)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_ldo_sel_ecbusrx(data)                       ((0x000000C0&(data))>>6)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_freeze_ecbusrx(data)                        ((0x00000020&(data))>>5)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_pow_ecbusrx(data)                           ((0x00000010&(data))>>4)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_ldo_pow_ecbusrx(data)                       ((0x00000008&(data))>>3)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_vcorstb_ecbusrx(data)                       ((0x00000004&(data))>>2)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_wdrst_ecbusrx(data)                         ((0x00000002&(data))>>1)
#define  CBUS_PMM_CBUS_PHY_6_get_pll_wdset_ecbusrx(data)                         (0x00000001&(data))

#define  CBUS_PMM_CBUS_PHY_7                                                     0x18062B4C
#define  CBUS_PMM_CBUS_PHY_7_reg_addr                                            "0xB8062B4C"
#define  CBUS_PMM_CBUS_PHY_7_reg                                                 0xB8062B4C
#define  CBUS_PMM_CBUS_PHY_7_inst_addr                                           "0x000F"
#define  set_CBUS_PMM_CBUS_PHY_7_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_7_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_7_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_7_reg))
#define  CBUS_PMM_CBUS_PHY_7_buf_delay_sel_ecbusrx_shift                         (19)
#define  CBUS_PMM_CBUS_PHY_7_ckin_bps_ecbusrx_shift                              (18)
#define  CBUS_PMM_CBUS_PHY_7_en_rcal_ecbusrx_shift                               (17)
#define  CBUS_PMM_CBUS_PHY_7_buf_cmp_vsel_ecbusrx_shift                          (15)
#define  CBUS_PMM_CBUS_PHY_7_buf_rcal_ecbusrx_shift                              (11)
#define  CBUS_PMM_CBUS_PHY_7_buf_delay_rsel_ecbusrx_shift                        (10)
#define  CBUS_PMM_CBUS_PHY_7_auto_k_r50_ecbusrx_shift                            (9)
#define  CBUS_PMM_CBUS_PHY_7_tst_sel_rx_shift                                    (6)
#define  CBUS_PMM_CBUS_PHY_7_mhl_tst_en_rx_shift                                 (5)
#define  CBUS_PMM_CBUS_PHY_7_ldo_vsel_rx_shift                                   (2)
#define  CBUS_PMM_CBUS_PHY_7_en_ldo_rx_shift                                     (1)
#define  CBUS_PMM_CBUS_PHY_7_en_bias_rx_shift                                    (0)
#define  CBUS_PMM_CBUS_PHY_7_buf_delay_sel_ecbusrx_mask                          (0x00780000)
#define  CBUS_PMM_CBUS_PHY_7_ckin_bps_ecbusrx_mask                               (0x00040000)
#define  CBUS_PMM_CBUS_PHY_7_en_rcal_ecbusrx_mask                                (0x00020000)
#define  CBUS_PMM_CBUS_PHY_7_buf_cmp_vsel_ecbusrx_mask                           (0x00018000)
#define  CBUS_PMM_CBUS_PHY_7_buf_rcal_ecbusrx_mask                               (0x00007800)
#define  CBUS_PMM_CBUS_PHY_7_buf_delay_rsel_ecbusrx_mask                         (0x00000400)
#define  CBUS_PMM_CBUS_PHY_7_auto_k_r50_ecbusrx_mask                             (0x00000200)
#define  CBUS_PMM_CBUS_PHY_7_tst_sel_rx_mask                                     (0x000001C0)
#define  CBUS_PMM_CBUS_PHY_7_mhl_tst_en_rx_mask                                  (0x00000020)
#define  CBUS_PMM_CBUS_PHY_7_ldo_vsel_rx_mask                                    (0x0000001C)
#define  CBUS_PMM_CBUS_PHY_7_en_ldo_rx_mask                                      (0x00000002)
#define  CBUS_PMM_CBUS_PHY_7_en_bias_rx_mask                                     (0x00000001)
#define  CBUS_PMM_CBUS_PHY_7_buf_delay_sel_ecbusrx(data)                         (0x00780000&((data)<<19))
#define  CBUS_PMM_CBUS_PHY_7_ckin_bps_ecbusrx(data)                              (0x00040000&((data)<<18))
#define  CBUS_PMM_CBUS_PHY_7_en_rcal_ecbusrx(data)                               (0x00020000&((data)<<17))
#define  CBUS_PMM_CBUS_PHY_7_buf_cmp_vsel_ecbusrx(data)                          (0x00018000&((data)<<15))
#define  CBUS_PMM_CBUS_PHY_7_buf_rcal_ecbusrx(data)                              (0x00007800&((data)<<11))
#define  CBUS_PMM_CBUS_PHY_7_buf_delay_rsel_ecbusrx(data)                        (0x00000400&((data)<<10))
#define  CBUS_PMM_CBUS_PHY_7_auto_k_r50_ecbusrx(data)                            (0x00000200&((data)<<9))
#define  CBUS_PMM_CBUS_PHY_7_tst_sel_rx(data)                                    (0x000001C0&((data)<<6))
#define  CBUS_PMM_CBUS_PHY_7_mhl_tst_en_rx(data)                                 (0x00000020&((data)<<5))
#define  CBUS_PMM_CBUS_PHY_7_ldo_vsel_rx(data)                                   (0x0000001C&((data)<<2))
#define  CBUS_PMM_CBUS_PHY_7_en_ldo_rx(data)                                     (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_PHY_7_en_bias_rx(data)                                    (0x00000001&(data))
#define  CBUS_PMM_CBUS_PHY_7_get_buf_delay_sel_ecbusrx(data)                     ((0x00780000&(data))>>19)
#define  CBUS_PMM_CBUS_PHY_7_get_ckin_bps_ecbusrx(data)                          ((0x00040000&(data))>>18)
#define  CBUS_PMM_CBUS_PHY_7_get_en_rcal_ecbusrx(data)                           ((0x00020000&(data))>>17)
#define  CBUS_PMM_CBUS_PHY_7_get_buf_cmp_vsel_ecbusrx(data)                      ((0x00018000&(data))>>15)
#define  CBUS_PMM_CBUS_PHY_7_get_buf_rcal_ecbusrx(data)                          ((0x00007800&(data))>>11)
#define  CBUS_PMM_CBUS_PHY_7_get_buf_delay_rsel_ecbusrx(data)                    ((0x00000400&(data))>>10)
#define  CBUS_PMM_CBUS_PHY_7_get_auto_k_r50_ecbusrx(data)                        ((0x00000200&(data))>>9)
#define  CBUS_PMM_CBUS_PHY_7_get_tst_sel_rx(data)                                ((0x000001C0&(data))>>6)
#define  CBUS_PMM_CBUS_PHY_7_get_mhl_tst_en_rx(data)                             ((0x00000020&(data))>>5)
#define  CBUS_PMM_CBUS_PHY_7_get_ldo_vsel_rx(data)                               ((0x0000001C&(data))>>2)
#define  CBUS_PMM_CBUS_PHY_7_get_en_ldo_rx(data)                                 ((0x00000002&(data))>>1)
#define  CBUS_PMM_CBUS_PHY_7_get_en_bias_rx(data)                                (0x00000001&(data))

#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA                                            0x18062B50
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_reg_addr                                   "0xB8062B50"
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_reg                                        0xB8062B50
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_inst_addr                                  "0x0010"
#define  set_CBUS_PMM_eCBUS_PRBS_CLK_DATA_reg(data)                              (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CLK_DATA_reg)=data)
#define  get_CBUS_PMM_eCBUS_PRBS_CLK_DATA_reg                                    (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CLK_DATA_reg))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_msb_lsb_swap_shift      (31)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_send_forward_data_detect_result_shift (30)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_150m_busy_shift               (29)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_75m_busy_shift                (28)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_inv_sel_shift                     (27)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_apply_shift                   (26)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_backward_data_msb_lsb_swap_shift     (25)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_en_shift                      (24)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_150m_to_75m_sample_select_shift      (23)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_0_1_detect_threshold_shift (16)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_backward_data_0_1_detect_threshold_shift (8)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_dummy_5_shift                              (5)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_backward_mode_shift          (4)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_backward_data_to_line_buffer_en_shift (3)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_detect_sel_line_buffer_align_shift (2)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_align_shift             (1)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_to_line_buffer_align_shift (0)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_msb_lsb_swap_mask       (0x80000000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_send_forward_data_detect_result_mask (0x40000000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_150m_busy_mask                (0x20000000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_75m_busy_mask                 (0x10000000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_inv_sel_mask                      (0x08000000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_apply_mask                    (0x04000000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_backward_data_msb_lsb_swap_mask      (0x02000000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_en_mask                       (0x01000000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_150m_to_75m_sample_select_mask       (0x00800000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_0_1_detect_threshold_mask (0x003F0000)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_backward_data_0_1_detect_threshold_mask (0x00003F00)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_dummy_5_mask                               (0x00000020)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_backward_mode_mask           (0x00000010)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_backward_data_to_line_buffer_en_mask (0x00000008)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_detect_sel_line_buffer_align_mask (0x00000004)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_align_mask              (0x00000002)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_to_line_buffer_align_mask (0x00000001)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_msb_lsb_swap(data)      (0x80000000&((data)<<31))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_send_forward_data_detect_result(data) (0x40000000&((data)<<30))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_150m_busy(data)               (0x20000000&((data)<<29))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_75m_busy(data)                (0x10000000&((data)<<28))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_inv_sel(data)                     (0x08000000&((data)<<27))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_apply(data)                   (0x04000000&((data)<<26))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_backward_data_msb_lsb_swap(data)     (0x02000000&((data)<<25))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_clk_300m_div_en(data)                      (0x01000000&((data)<<24))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_150m_to_75m_sample_select(data)      (0x00800000&((data)<<23))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_0_1_detect_threshold(data) (0x003F0000&((data)<<16))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_backward_data_0_1_detect_threshold(data) (0x00003F00&((data)<<8))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_dummy_5(data)                              (0x00000020&((data)<<5))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_backward_mode(data)          (0x00000010&((data)<<4))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_backward_data_to_line_buffer_en(data) (0x00000008&((data)<<3))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_detect_sel_line_buffer_align(data) (0x00000004&((data)<<2))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_align(data)             (0x00000002&((data)<<1))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_ecbus_forward_data_to_line_buffer_align(data) (0x00000001&(data))
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_forward_data_msb_lsb_swap(data)  ((0x80000000&(data))>>31)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_send_forward_data_detect_result(data) ((0x40000000&(data))>>30)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_clk_300m_div_150m_busy(data)           ((0x20000000&(data))>>29)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_clk_300m_div_75m_busy(data)            ((0x10000000&(data))>>28)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_clk_300m_inv_sel(data)                 ((0x08000000&(data))>>27)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_clk_300m_div_apply(data)               ((0x04000000&(data))>>26)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_backward_data_msb_lsb_swap(data) ((0x02000000&(data))>>25)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_clk_300m_div_en(data)                  ((0x01000000&(data))>>24)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_150m_to_75m_sample_select(data)  ((0x00800000&(data))>>23)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_forward_data_0_1_detect_threshold(data) ((0x003F0000&(data))>>16)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_backward_data_0_1_detect_threshold(data) ((0x00003F00&(data))>>8)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_dummy_5(data)                          ((0x00000020&(data))>>5)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_forward_backward_mode(data)      ((0x00000010&(data))>>4)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_backward_data_to_line_buffer_en(data) ((0x00000008&(data))>>3)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_forward_data_detect_sel_line_buffer_align(data) ((0x00000004&(data))>>2)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_forward_data_align(data)         ((0x00000002&(data))>>1)
#define  CBUS_PMM_eCBUS_PRBS_CLK_DATA_get_ecbus_forward_data_to_line_buffer_align(data) (0x00000001&(data))

#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX                                             0x18062B54
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_reg_addr                                    "0xB8062B54"
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_reg                                         0xB8062B54
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_inst_addr                                   "0x0011"
#define  set_CBUS_PMM_eCBUS_PRBS_CTRL_TX_reg(data)                               (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_TX_reg)=data)
#define  get_CBUS_PMM_eCBUS_PRBS_CTRL_TX_reg                                     (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_TX_reg))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_backward_1_high_low_shift             (31)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_backward_1_duty_shift                 (28)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_forward_data_sel_bit_shift            (20)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_forward_data_de_glitch_en_shift       (19)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_forward_data_de_glitch_level_shift    (16)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_prbs_tx_mode_select_shift                   (14)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_tx_0_1_pattern_select_shift                 (12)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_tx_0_1_pattern_select_en_shift              (11)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_prbs_tx_reverse_shift                       (1)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_prbs_tx_en_shift                            (0)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_backward_1_high_low_mask              (0x80000000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_backward_1_duty_mask                  (0x70000000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_forward_data_sel_bit_mask             (0x03F00000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_forward_data_de_glitch_en_mask        (0x00080000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_forward_data_de_glitch_level_mask     (0x00070000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_prbs_tx_mode_select_mask                    (0x0000C000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_tx_0_1_pattern_select_mask                  (0x00003000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_tx_0_1_pattern_select_en_mask               (0x00000800)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_prbs_tx_reverse_mask                        (0x00000002)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_prbs_tx_en_mask                             (0x00000001)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_backward_1_high_low(data)             (0x80000000&((data)<<31))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_backward_1_duty(data)                 (0x70000000&((data)<<28))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_forward_data_sel_bit(data)            (0x03F00000&((data)<<20))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_forward_data_de_glitch_en(data)       (0x00080000&((data)<<19))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_ecbus_forward_data_de_glitch_level(data)    (0x00070000&((data)<<16))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_prbs_tx_mode_select(data)                   (0x0000C000&((data)<<14))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_tx_0_1_pattern_select(data)                 (0x00003000&((data)<<12))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_tx_0_1_pattern_select_en(data)              (0x00000800&((data)<<11))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_prbs_tx_reverse(data)                       (0x00000002&((data)<<1))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_prbs_tx_en(data)                            (0x00000001&(data))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_ecbus_backward_1_high_low(data)         ((0x80000000&(data))>>31)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_ecbus_backward_1_duty(data)             ((0x70000000&(data))>>28)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_ecbus_forward_data_sel_bit(data)        ((0x03F00000&(data))>>20)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_ecbus_forward_data_de_glitch_en(data)   ((0x00080000&(data))>>19)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_ecbus_forward_data_de_glitch_level(data) ((0x00070000&(data))>>16)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_prbs_tx_mode_select(data)               ((0x0000C000&(data))>>14)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_tx_0_1_pattern_select(data)             ((0x00003000&(data))>>12)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_tx_0_1_pattern_select_en(data)          ((0x00000800&(data))>>11)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_prbs_tx_reverse(data)                   ((0x00000002&(data))>>1)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_TX_get_prbs_tx_en(data)                        (0x00000001&(data))

#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX                                             0x18062B58
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_reg_addr                                    "0xB8062B58"
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_reg                                         0xB8062B58
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_inst_addr                                   "0x0012"
#define  set_CBUS_PMM_eCBUS_PRBS_CTRL_RX_reg(data)                               (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_RX_reg)=data)
#define  get_CBUS_PMM_eCBUS_PRBS_CTRL_RX_reg                                     (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_RX_reg))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_detect_shift                           (28)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_bist_err_cnt_shift                     (20)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_err_cnt_shift                          (16)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_rx_mode_select_shift                   (14)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_bit_err_shift                          (4)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_lock_shift                             (3)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_err_cnt_clr_shift                      (2)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_rx_reverse_shift                       (1)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_rx_en_shift                            (0)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_detect_mask                            (0x10000000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_bist_err_cnt_mask                      (0x0FF00000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_err_cnt_mask                           (0x00070000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_rx_mode_select_mask                    (0x0000C000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_bit_err_mask                           (0x00003FF0)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_lock_mask                              (0x00000008)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_err_cnt_clr_mask                       (0x00000004)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_rx_reverse_mask                        (0x00000002)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_rx_en_mask                             (0x00000001)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_detect(data)                           (0x10000000&((data)<<28))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_bist_err_cnt(data)                     (0x0FF00000&((data)<<20))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_err_cnt(data)                          (0x00070000&((data)<<16))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_rx_mode_select(data)                   (0x0000C000&((data)<<14))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_bit_err(data)                          (0x00003FF0&((data)<<4))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_lock(data)                             (0x00000008&((data)<<3))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_err_cnt_clr(data)                      (0x00000004&((data)<<2))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_rx_reverse(data)                       (0x00000002&((data)<<1))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_prbs_rx_en(data)                            (0x00000001&(data))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_get_prbs_detect(data)                       ((0x10000000&(data))>>28)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_get_prbs_bist_err_cnt(data)                 ((0x0FF00000&(data))>>20)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_get_prbs_err_cnt(data)                      ((0x00070000&(data))>>16)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_get_prbs_rx_mode_select(data)               ((0x0000C000&(data))>>14)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_get_prbs_bit_err(data)                      ((0x00003FF0&(data))>>4)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_get_prbs_lock(data)                         ((0x00000008&(data))>>3)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_get_prbs_err_cnt_clr(data)                  ((0x00000004&(data))>>2)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_get_prbs_rx_reverse(data)                   ((0x00000002&(data))>>1)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_get_prbs_rx_en(data)                        (0x00000001&(data))

#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1                                           0x18062B5C
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_reg_addr                                  "0xB8062B5C"
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_reg                                       0xB8062B5C
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_inst_addr                                 "0x0013"
#define  set_CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_reg(data)                             (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_reg)=data)
#define  get_CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_reg                                   (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_reg))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_prbs7_reg_shift                           (16)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_prbs15_reg_shift                          (0)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_prbs7_reg_mask                            (0x007F0000)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_prbs15_reg_mask                           (0x00007FFF)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_prbs7_reg(data)                           (0x007F0000&((data)<<16))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_prbs15_reg(data)                          (0x00007FFF&(data))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_get_prbs7_reg(data)                       ((0x007F0000&(data))>>16)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_1_get_prbs15_reg(data)                      (0x00007FFF&(data))

#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_2                                           0x18062B60
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_reg_addr                                  "0xB8062B60"
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_reg                                       0xB8062B60
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_inst_addr                                 "0x0014"
#define  set_CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_reg(data)                             (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_reg)=data)
#define  get_CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_reg                                   (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_reg))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_prbs23_reg_shift                          (0)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_prbs23_reg_mask                           (0x007FFFFF)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_prbs23_reg(data)                          (0x007FFFFF&(data))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_2_get_prbs23_reg(data)                      (0x007FFFFF&(data))

#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_3                                           0x18062B64
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_reg_addr                                  "0xB8062B64"
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_reg                                       0xB8062B64
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_inst_addr                                 "0x0015"
#define  set_CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_reg(data)                             (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_reg)=data)
#define  get_CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_reg                                   (*((volatile unsigned int*)CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_reg))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_prbs31_reg_shift                          (0)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_prbs31_reg_mask                           (0x7FFFFFFF)
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_prbs31_reg(data)                          (0x7FFFFFFF&(data))
#define  CBUS_PMM_eCBUS_PRBS_CTRL_RX_3_get_prbs31_reg(data)                      (0x7FFFFFFF&(data))

#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL                                           0x18062B70
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_reg_addr                                  "0xB8062B70"
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_reg                                       0xB8062B70
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_inst_addr                                 "0x0016"
#define  set_CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_reg(data)                             (*((volatile unsigned int*)CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_reg)=data)
#define  get_CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_reg                                   (*((volatile unsigned int*)CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_reg))
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_backward_consec_start_shift           (24)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_backward_debug_div6_shift             (20)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_backward_debug_mode_shift             (16)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_forward_consec_start_shift            (8)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_forward_debug_div5_shift              (4)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_forward_debug_mode_shift              (0)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_backward_consec_start_mask            (0x3F000000)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_backward_debug_div6_mask              (0x00700000)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_backward_debug_mode_mask              (0x00010000)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_forward_consec_start_mask             (0x00003F00)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_forward_debug_div5_mask               (0x00000070)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_forward_debug_mode_mask               (0x00000001)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_backward_consec_start(data)           (0x3F000000&((data)<<24))
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_backward_debug_div6(data)             (0x00700000&((data)<<20))
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_backward_debug_mode(data)             (0x00010000&((data)<<16))
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_forward_consec_start(data)            (0x00003F00&((data)<<8))
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_forward_debug_div5(data)              (0x00000070&((data)<<4))
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_sel_forward_debug_mode(data)              (0x00000001&(data))
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_get_sel_backward_consec_start(data)       ((0x3F000000&(data))>>24)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_get_sel_backward_debug_div6(data)         ((0x00700000&(data))>>20)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_get_sel_backward_debug_mode(data)         ((0x00010000&(data))>>16)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_get_sel_forward_consec_start(data)        ((0x00003F00&(data))>>8)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_get_sel_forward_debug_div5(data)          ((0x00000070&(data))>>4)
#define  CBUS_PMM_eCBUS_DEBUG_DIV_CTRL_get_sel_forward_debug_mode(data)          (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CBUS_PMM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ecbus_dphy_in_latch_clk_inv_sel:1;
        RBus_UInt32  rx_timeout_irq:1;
        RBus_UInt32  stat_ok_irq:1;
        RBus_UInt32  dummy18062b00_5_4:2;
        RBus_UInt32  wake_pulse_det:1;
        RBus_UInt32  dis_pulse_det:1;
        RBus_UInt32  wake_irq_en:1;
        RBus_UInt32  dis_irq_en:1;
    };
}cbus_pmm_cbus_standby_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  clk_1m_div:4;
        RBus_UInt32  clk_1k_div:10;
    };
}cbus_pmm_cbus_standby_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dis_deb_lv:3;
        RBus_UInt32  deb_lv:3;
        RBus_UInt32  disconn:2;
    };
}cbus_pmm_cbus_standby_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  wake_offset_low2:5;
        RBus_UInt32  wake_offset_low:5;
        RBus_UInt32  wake_cnt:3;
        RBus_UInt32  wake_offset:5;
        RBus_UInt32  cbus_disconn:1;
        RBus_UInt32  disconn_irq_en:1;
    };
}cbus_pmm_cbus_standby_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dis_upper:4;
        RBus_UInt32  dis_lower:3;
        RBus_UInt32  wake_eco_en:1;
    };
}cbus_pmm_cbus_standby_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  wake_num:3;
        RBus_UInt32  dis_num:5;
    };
}cbus_pmm_cbus_standby_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  cbus_in_tx_sig:1;
        RBus_UInt32  cbus_imp_auto:1;
        RBus_UInt32  bypass_mode:1;
        RBus_UInt32  sink_fsm_st:3;
        RBus_UInt32  cbus_100k_en:1;
        RBus_UInt32  cbus_1k_en:1;
        RBus_UInt32  cbus_in_sig:1;
    };
}cbus_pmm_cbus_standby_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  goto_sink1_pos:1;
        RBus_UInt32  goto_float:1;
        RBus_UInt32  goto_sink1:1;
        RBus_UInt32  cable_det:1;
        RBus_UInt32  dbg_sel_phy:2;
    };
}cbus_pmm_cbus_standby_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_09_resv:32;
    };
}cbus_pmm_cbus_standby_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cbus_control:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  sel_phy_soft_rst_n:1;
    };
}cbus_pmm_cbus_phy_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}cbus_pmm_cbus_phy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18062b38_31:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  mhl_r10k_en:2;
        RBus_UInt32  res2:18;
        RBus_UInt32  dummy18062b38_7:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  en_driver_tx:1;
        RBus_UInt32  res4:2;
    };
}cbus_pmm_cbus_phy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  en_100k:1;
        RBus_UInt32  en_1k:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cbus_res_tst:10;
        RBus_UInt32  hpd_r1k_bypass:1;
        RBus_UInt32  hdmi_mhl_sel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  cbus_5v_detect:1;
        RBus_UInt32  hpd_r1k_sel:3;
        RBus_UInt32  cbus_o_rx:1;
        RBus_UInt32  cbus_sr_rx:1;
        RBus_UInt32  cbus_smt_rx:1;
        RBus_UInt32  cbus_pu_rx:1;
        RBus_UInt32  cbus_pd_rx:1;
        RBus_UInt32  cbus_i_rx:1;
        RBus_UInt32  cbus_e2_rx:1;
        RBus_UInt32  cbus_e_rx:1;
    };
}cbus_pmm_cbus_phy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus_res_tst_rx:6;
        RBus_UInt32  sel_input_high_rx:2;
        RBus_UInt32  sel_input_low_rx:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  triming_mode_rx:1;
        RBus_UInt32  mhl_r1k_rx:4;
        RBus_UInt32  res_ok_rx:1;
        RBus_UInt32  mhl_bmos_en_rx:1;
        RBus_UInt32  en_res_cal_cbus_rx:1;
        RBus_UInt32  adjr_100k_rx:5;
        RBus_UInt32  auto_k_100k_rx:1;
        RBus_UInt32  cbus_strc_rx:3;
        RBus_UInt32  sel_cbusb_gpio_rx:1;
        RBus_UInt32  en_driver_rx:1;
        RBus_UInt32  en_cmp_rx:1;
        RBus_UInt32  en_cbus_rx:1;
    };
}cbus_pmm_cbus_phy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  buf_rsel_ecbusrx:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  buf_vref_sel_ecbusrx:2;
        RBus_UInt32  bkwd_byp_ecbusrx:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  buf_r50_ecbusrx:4;
        RBus_UInt32  en_buf_ecbusrx:1;
        RBus_UInt32  buf_ibsel_ecbusrx:3;
        RBus_UInt32  pll_cp_ecbusrx:2;
        RBus_UInt32  pll_cs_ecbusrx:2;
        RBus_UInt32  pll_wdo_ecbusrx:1;
        RBus_UInt32  pll_rs_ecbusrx:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll_ip_ecbusrx:3;
    };
}cbus_pmm_cbus_phy_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecbuspll_rstb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cko_tst_en_ecbusrx:1;
        RBus_UInt32  deglitch_en_ecbusrx:1;
        RBus_UInt32  test_en_ecbusrx:1;
        RBus_UInt32  pll_phsel_ecbusrx:4;
        RBus_UInt32  pll_tdsel_ecbusrx:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll_n_ecbusrx:3;
        RBus_UInt32  pll_m_ecbusrx:8;
        RBus_UInt32  pll_ldo_sel_ecbusrx:2;
        RBus_UInt32  pll_freeze_ecbusrx:1;
        RBus_UInt32  pll_pow_ecbusrx:1;
        RBus_UInt32  pll_ldo_pow_ecbusrx:1;
        RBus_UInt32  pll_vcorstb_ecbusrx:1;
        RBus_UInt32  pll_wdrst_ecbusrx:1;
        RBus_UInt32  pll_wdset_ecbusrx:1;
    };
}cbus_pmm_cbus_phy_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  buf_delay_sel_ecbusrx:4;
        RBus_UInt32  ckin_bps_ecbusrx:1;
        RBus_UInt32  en_rcal_ecbusrx:1;
        RBus_UInt32  buf_cmp_vsel_ecbusrx:2;
        RBus_UInt32  buf_rcal_ecbusrx:4;
        RBus_UInt32  buf_delay_rsel_ecbusrx:1;
        RBus_UInt32  auto_k_r50_ecbusrx:1;
        RBus_UInt32  tst_sel_rx:3;
        RBus_UInt32  mhl_tst_en_rx:1;
        RBus_UInt32  ldo_vsel_rx:3;
        RBus_UInt32  en_ldo_rx:1;
        RBus_UInt32  en_bias_rx:1;
    };
}cbus_pmm_cbus_phy_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecbus_forward_data_msb_lsb_swap:1;
        RBus_UInt32  ecbus_send_forward_data_detect_result:1;
        RBus_UInt32  clk_300m_div_150m_busy:1;
        RBus_UInt32  clk_300m_div_75m_busy:1;
        RBus_UInt32  clk_300m_inv_sel:1;
        RBus_UInt32  clk_300m_div_apply:1;
        RBus_UInt32  ecbus_backward_data_msb_lsb_swap:1;
        RBus_UInt32  clk_300m_div_en:1;
        RBus_UInt32  ecbus_150m_to_75m_sample_select:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ecbus_forward_data_0_1_detect_threshold:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ecbus_backward_data_0_1_detect_threshold:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  dummy18062b50_5:1;
        RBus_UInt32  ecbus_forward_backward_mode:1;
        RBus_UInt32  ecbus_backward_data_to_line_buffer_en:1;
        RBus_UInt32  ecbus_forward_data_detect_sel_line_buffer_align:1;
        RBus_UInt32  ecbus_forward_data_align:1;
        RBus_UInt32  ecbus_forward_data_to_line_buffer_align:1;
    };
}cbus_pmm_ecbus_prbs_clk_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecbus_backward_1_high_low:1;
        RBus_UInt32  ecbus_backward_1_duty:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  ecbus_forward_data_sel_bit:6;
        RBus_UInt32  ecbus_forward_data_de_glitch_en:1;
        RBus_UInt32  ecbus_forward_data_de_glitch_level:3;
        RBus_UInt32  prbs_tx_mode_select:2;
        RBus_UInt32  tx_0_1_pattern_select:2;
        RBus_UInt32  tx_0_1_pattern_select_en:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  prbs_tx_reverse:1;
        RBus_UInt32  prbs_tx_en:1;
    };
}cbus_pmm_ecbus_prbs_ctrl_tx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  prbs_detect:1;
        RBus_UInt32  prbs_bist_err_cnt:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  prbs_err_cnt:3;
        RBus_UInt32  prbs_rx_mode_select:2;
        RBus_UInt32  prbs_bit_err:10;
        RBus_UInt32  prbs_lock:1;
        RBus_UInt32  prbs_err_cnt_clr:1;
        RBus_UInt32  prbs_rx_reverse:1;
        RBus_UInt32  prbs_rx_en:1;
    };
}cbus_pmm_ecbus_prbs_ctrl_rx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  prbs7_reg:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  prbs15_reg:15;
    };
}cbus_pmm_ecbus_prbs_ctrl_rx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  prbs23_reg:23;
    };
}cbus_pmm_ecbus_prbs_ctrl_rx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  prbs31_reg:31;
    };
}cbus_pmm_ecbus_prbs_ctrl_rx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  sel_backward_consec_start:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  sel_backward_debug_div6:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  sel_backward_debug_mode:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  sel_forward_consec_start:6;
        RBus_UInt32  res5:1;
        RBus_UInt32  sel_forward_debug_div5:3;
        RBus_UInt32  res6:3;
        RBus_UInt32  sel_forward_debug_mode:1;
    };
}cbus_pmm_ecbus_debug_div_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======CBUS_PMM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dis_irq_en:1;
        RBus_UInt32  wake_irq_en:1;
        RBus_UInt32  dis_pulse_det:1;
        RBus_UInt32  wake_pulse_det:1;
        RBus_UInt32  dummy18062b00_5:2;
        RBus_UInt32  stat_ok_irq:1;
        RBus_UInt32  rx_timeout_irq:1;
        RBus_UInt32  ecbus_dphy_in_latch_clk_inv_sel:1;
        RBus_UInt32  res1:23;
    };
}cbus_pmm_cbus_standby_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_1k_div:10;
        RBus_UInt32  clk_1m_div:4;
        RBus_UInt32  res1:18;
    };
}cbus_pmm_cbus_standby_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disconn:2;
        RBus_UInt32  deb_lv:3;
        RBus_UInt32  dis_deb_lv:3;
        RBus_UInt32  res1:24;
    };
}cbus_pmm_cbus_standby_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disconn_irq_en:1;
        RBus_UInt32  cbus_disconn:1;
        RBus_UInt32  wake_offset:5;
        RBus_UInt32  wake_cnt:3;
        RBus_UInt32  wake_offset_low:5;
        RBus_UInt32  wake_offset_low2:5;
        RBus_UInt32  res1:12;
    };
}cbus_pmm_cbus_standby_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wake_eco_en:1;
        RBus_UInt32  dis_lower:3;
        RBus_UInt32  dis_upper:4;
        RBus_UInt32  res1:24;
    };
}cbus_pmm_cbus_standby_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dis_num:5;
        RBus_UInt32  wake_num:3;
        RBus_UInt32  res1:24;
    };
}cbus_pmm_cbus_standby_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus_in_sig:1;
        RBus_UInt32  cbus_1k_en:1;
        RBus_UInt32  cbus_100k_en:1;
        RBus_UInt32  sink_fsm_st:3;
        RBus_UInt32  bypass_mode:1;
        RBus_UInt32  cbus_imp_auto:1;
        RBus_UInt32  cbus_in_tx_sig:1;
        RBus_UInt32  res1:23;
    };
}cbus_pmm_cbus_standby_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sel_phy:2;
        RBus_UInt32  cable_det:1;
        RBus_UInt32  goto_sink1:1;
        RBus_UInt32  goto_float:1;
        RBus_UInt32  goto_sink1_pos:1;
        RBus_UInt32  res1:26;
    };
}cbus_pmm_cbus_standby_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctrl_09_resv:32;
    };
}cbus_pmm_cbus_standby_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_phy_soft_rst_n:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  cbus_control:8;
        RBus_UInt32  res2:8;
    };
}cbus_pmm_cbus_phy_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}cbus_pmm_cbus_phy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  en_driver_tx:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  dummy18062b38_7_7:1;
        RBus_UInt32  res3:18;
        RBus_UInt32  mhl_r10k_en:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  dummy18062b38_31_31:1;
    };
}cbus_pmm_cbus_phy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus_e_rx:1;
        RBus_UInt32  cbus_e2_rx:1;
        RBus_UInt32  cbus_i_rx:1;
        RBus_UInt32  cbus_pd_rx:1;
        RBus_UInt32  cbus_pu_rx:1;
        RBus_UInt32  cbus_smt_rx:1;
        RBus_UInt32  cbus_sr_rx:1;
        RBus_UInt32  cbus_o_rx:1;
        RBus_UInt32  hpd_r1k_sel:3;
        RBus_UInt32  cbus_5v_detect:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  hdmi_mhl_sel:1;
        RBus_UInt32  hpd_r1k_bypass:1;
        RBus_UInt32  cbus_res_tst:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  en_1k:1;
        RBus_UInt32  en_100k:1;
        RBus_UInt32  res3:2;
    };
}cbus_pmm_cbus_phy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_cbus_rx:1;
        RBus_UInt32  en_cmp_rx:1;
        RBus_UInt32  en_driver_rx:1;
        RBus_UInt32  sel_cbusb_gpio_rx:1;
        RBus_UInt32  cbus_strc_rx:3;
        RBus_UInt32  auto_k_100k_rx:1;
        RBus_UInt32  adjr_100k_rx:5;
        RBus_UInt32  en_res_cal_cbus_rx:1;
        RBus_UInt32  mhl_bmos_en_rx:1;
        RBus_UInt32  res_ok_rx:1;
        RBus_UInt32  mhl_r1k_rx:4;
        RBus_UInt32  triming_mode_rx:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sel_input_low_rx:2;
        RBus_UInt32  sel_input_high_rx:2;
        RBus_UInt32  cbus_res_tst_rx:6;
    };
}cbus_pmm_cbus_phy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_ip_ecbusrx:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_rs_ecbusrx:3;
        RBus_UInt32  pll_wdo_ecbusrx:1;
        RBus_UInt32  pll_cs_ecbusrx:2;
        RBus_UInt32  pll_cp_ecbusrx:2;
        RBus_UInt32  buf_ibsel_ecbusrx:3;
        RBus_UInt32  en_buf_ecbusrx:1;
        RBus_UInt32  buf_r50_ecbusrx:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  bkwd_byp_ecbusrx:1;
        RBus_UInt32  buf_vref_sel_ecbusrx:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  buf_rsel_ecbusrx:2;
        RBus_UInt32  res4:2;
    };
}cbus_pmm_cbus_phy_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_wdset_ecbusrx:1;
        RBus_UInt32  pll_wdrst_ecbusrx:1;
        RBus_UInt32  pll_vcorstb_ecbusrx:1;
        RBus_UInt32  pll_ldo_pow_ecbusrx:1;
        RBus_UInt32  pll_pow_ecbusrx:1;
        RBus_UInt32  pll_freeze_ecbusrx:1;
        RBus_UInt32  pll_ldo_sel_ecbusrx:2;
        RBus_UInt32  pll_m_ecbusrx:8;
        RBus_UInt32  pll_n_ecbusrx:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_tdsel_ecbusrx:3;
        RBus_UInt32  pll_phsel_ecbusrx:4;
        RBus_UInt32  test_en_ecbusrx:1;
        RBus_UInt32  deglitch_en_ecbusrx:1;
        RBus_UInt32  cko_tst_en_ecbusrx:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ecbuspll_rstb:1;
    };
}cbus_pmm_cbus_phy_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_bias_rx:1;
        RBus_UInt32  en_ldo_rx:1;
        RBus_UInt32  ldo_vsel_rx:3;
        RBus_UInt32  mhl_tst_en_rx:1;
        RBus_UInt32  tst_sel_rx:3;
        RBus_UInt32  auto_k_r50_ecbusrx:1;
        RBus_UInt32  buf_delay_rsel_ecbusrx:1;
        RBus_UInt32  buf_rcal_ecbusrx:4;
        RBus_UInt32  buf_cmp_vsel_ecbusrx:2;
        RBus_UInt32  en_rcal_ecbusrx:1;
        RBus_UInt32  ckin_bps_ecbusrx:1;
        RBus_UInt32  buf_delay_sel_ecbusrx:4;
        RBus_UInt32  res1:9;
    };
}cbus_pmm_cbus_phy_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecbus_forward_data_to_line_buffer_align:1;
        RBus_UInt32  ecbus_forward_data_align:1;
        RBus_UInt32  ecbus_forward_data_detect_sel_line_buffer_align:1;
        RBus_UInt32  ecbus_backward_data_to_line_buffer_en:1;
        RBus_UInt32  ecbus_forward_backward_mode:1;
        RBus_UInt32  dummy18062b50_5:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ecbus_backward_data_0_1_detect_threshold:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ecbus_forward_data_0_1_detect_threshold:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  ecbus_150m_to_75m_sample_select:1;
        RBus_UInt32  clk_300m_div_en:1;
        RBus_UInt32  ecbus_backward_data_msb_lsb_swap:1;
        RBus_UInt32  clk_300m_div_apply:1;
        RBus_UInt32  clk_300m_inv_sel:1;
        RBus_UInt32  clk_300m_div_75m_busy:1;
        RBus_UInt32  clk_300m_div_150m_busy:1;
        RBus_UInt32  ecbus_send_forward_data_detect_result:1;
        RBus_UInt32  ecbus_forward_data_msb_lsb_swap:1;
    };
}cbus_pmm_ecbus_prbs_clk_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs_tx_en:1;
        RBus_UInt32  prbs_tx_reverse:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  tx_0_1_pattern_select_en:1;
        RBus_UInt32  tx_0_1_pattern_select:2;
        RBus_UInt32  prbs_tx_mode_select:2;
        RBus_UInt32  ecbus_forward_data_de_glitch_level:3;
        RBus_UInt32  ecbus_forward_data_de_glitch_en:1;
        RBus_UInt32  ecbus_forward_data_sel_bit:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ecbus_backward_1_duty:3;
        RBus_UInt32  ecbus_backward_1_high_low:1;
    };
}cbus_pmm_ecbus_prbs_ctrl_tx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs_rx_en:1;
        RBus_UInt32  prbs_rx_reverse:1;
        RBus_UInt32  prbs_err_cnt_clr:1;
        RBus_UInt32  prbs_lock:1;
        RBus_UInt32  prbs_bit_err:10;
        RBus_UInt32  prbs_rx_mode_select:2;
        RBus_UInt32  prbs_err_cnt:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  prbs_bist_err_cnt:8;
        RBus_UInt32  prbs_detect:1;
        RBus_UInt32  res2:3;
    };
}cbus_pmm_ecbus_prbs_ctrl_rx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs15_reg:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  prbs7_reg:7;
        RBus_UInt32  res2:9;
    };
}cbus_pmm_ecbus_prbs_ctrl_rx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs23_reg:23;
        RBus_UInt32  res1:9;
    };
}cbus_pmm_ecbus_prbs_ctrl_rx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs31_reg:31;
        RBus_UInt32  res1:1;
    };
}cbus_pmm_ecbus_prbs_ctrl_rx_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_forward_debug_mode:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sel_forward_debug_div5:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  sel_forward_consec_start:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  sel_backward_debug_mode:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sel_backward_debug_div6:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  sel_backward_consec_start:6;
        RBus_UInt32  res6:2;
    };
}cbus_pmm_ecbus_debug_div_ctrl_RBUS;




#endif 


#endif 
