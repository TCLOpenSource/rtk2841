/**
* @file rbusCBUS_PMMReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/21
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
#define  CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_shift                           (3)
#define  CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_shift                            (2)
#define  CBUS_PMM_CBUS_STANDBY_00_wake_irq_en_shift                              (1)
#define  CBUS_PMM_CBUS_STANDBY_00_dis_irq_en_shift                               (0)
#define  CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det_mask                            (0x00000008)
#define  CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det_mask                             (0x00000004)
#define  CBUS_PMM_CBUS_STANDBY_00_wake_irq_en_mask                               (0x00000002)
#define  CBUS_PMM_CBUS_STANDBY_00_dis_irq_en_mask                                (0x00000001)
#define  CBUS_PMM_CBUS_STANDBY_00_wake_pulse_det(data)                           (0x00000008&((data)<<3))
#define  CBUS_PMM_CBUS_STANDBY_00_dis_pulse_det(data)                            (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_STANDBY_00_wake_irq_en(data)                              (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_STANDBY_00_dis_irq_en(data)                               (0x00000001&(data))
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
#define  CBUS_PMM_CBUS_STANDBY_05_dis_upper_mask                                 (0x000000F0)
#define  CBUS_PMM_CBUS_STANDBY_05_dis_lower_mask                                 (0x0000000E)
#define  CBUS_PMM_CBUS_STANDBY_05_dis_upper(data)                                (0x000000F0&((data)<<4))
#define  CBUS_PMM_CBUS_STANDBY_05_dis_lower(data)                                (0x0000000E&((data)<<1))
#define  CBUS_PMM_CBUS_STANDBY_05_get_dis_upper(data)                            ((0x000000F0&(data))>>4)
#define  CBUS_PMM_CBUS_STANDBY_05_get_dis_lower(data)                            ((0x0000000E&(data))>>1)

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
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_imp_auto_shift                            (7)
#define  CBUS_PMM_CBUS_STANDBY_07_bypass_mode_shift                              (6)
#define  CBUS_PMM_CBUS_STANDBY_07_sink_fsm_st_shift                              (3)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_100k_en_shift                             (2)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_1k_en_shift                               (1)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_in_sig_shift                              (0)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_imp_auto_mask                             (0x00000080)
#define  CBUS_PMM_CBUS_STANDBY_07_bypass_mode_mask                               (0x00000040)
#define  CBUS_PMM_CBUS_STANDBY_07_sink_fsm_st_mask                               (0x00000038)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_100k_en_mask                              (0x00000004)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_1k_en_mask                                (0x00000002)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_in_sig_mask                               (0x00000001)
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_imp_auto(data)                            (0x00000080&((data)<<7))
#define  CBUS_PMM_CBUS_STANDBY_07_bypass_mode(data)                              (0x00000040&((data)<<6))
#define  CBUS_PMM_CBUS_STANDBY_07_sink_fsm_st(data)                              (0x00000038&((data)<<3))
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_100k_en(data)                             (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_1k_en(data)                               (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_STANDBY_07_cbus_in_sig(data)                              (0x00000001&(data))
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

#define  CBUS_PMM_CBUS_PHY_0                                                     0x18062B30
#define  CBUS_PMM_CBUS_PHY_0_reg_addr                                            "0xB8062B30"
#define  CBUS_PMM_CBUS_PHY_0_reg                                                 0xB8062B30
#define  CBUS_PMM_CBUS_PHY_0_inst_addr                                           "0x0008"
#define  set_CBUS_PMM_CBUS_PHY_0_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_0_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_0_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_0_reg))
#define  CBUS_PMM_CBUS_PHY_0_sel_phy_soft_rst_n_shift                            (0)
#define  CBUS_PMM_CBUS_PHY_0_sel_phy_soft_rst_n_mask                             (0x00000001)
#define  CBUS_PMM_CBUS_PHY_0_sel_phy_soft_rst_n(data)                            (0x00000001&(data))
#define  CBUS_PMM_CBUS_PHY_0_get_sel_phy_soft_rst_n(data)                        (0x00000001&(data))

#define  CBUS_PMM_CBUS_PHY_2                                                     0x18062B38
#define  CBUS_PMM_CBUS_PHY_2_reg_addr                                            "0xB8062B38"
#define  CBUS_PMM_CBUS_PHY_2_reg                                                 0xB8062B38
#define  CBUS_PMM_CBUS_PHY_2_inst_addr                                           "0x0009"
#define  set_CBUS_PMM_CBUS_PHY_2_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_2_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_2_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_2_reg))
#define  CBUS_PMM_CBUS_PHY_2_en_driver_tx_shift                                  (2)
#define  CBUS_PMM_CBUS_PHY_2_en_driver_tx_mask                                   (0x00000004)
#define  CBUS_PMM_CBUS_PHY_2_en_driver_tx(data)                                  (0x00000004&((data)<<2))
#define  CBUS_PMM_CBUS_PHY_2_get_en_driver_tx(data)                              ((0x00000004&(data))>>2)

#define  CBUS_PMM_CBUS_PHY_3                                                     0x18062B3C
#define  CBUS_PMM_CBUS_PHY_3_reg_addr                                            "0xB8062B3C"
#define  CBUS_PMM_CBUS_PHY_3_reg                                                 0xB8062B3C
#define  CBUS_PMM_CBUS_PHY_3_inst_addr                                           "0x000A"
#define  set_CBUS_PMM_CBUS_PHY_3_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_3_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_3_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_3_reg))
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
#define  CBUS_PMM_CBUS_PHY_4_inst_addr                                           "0x000B"
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

#define  CBUS_PMM_CBUS_PHY_7                                                     0x18062B4C
#define  CBUS_PMM_CBUS_PHY_7_reg_addr                                            "0xB8062B4C"
#define  CBUS_PMM_CBUS_PHY_7_reg                                                 0xB8062B4C
#define  CBUS_PMM_CBUS_PHY_7_inst_addr                                           "0x000C"
#define  set_CBUS_PMM_CBUS_PHY_7_reg(data)                                       (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_7_reg)=data)
#define  get_CBUS_PMM_CBUS_PHY_7_reg                                             (*((volatile unsigned int*)CBUS_PMM_CBUS_PHY_7_reg))
#define  CBUS_PMM_CBUS_PHY_7_ldo_vsel_rx_shift                                   (2)
#define  CBUS_PMM_CBUS_PHY_7_en_ldo_rx_shift                                     (1)
#define  CBUS_PMM_CBUS_PHY_7_en_bias_rx_shift                                    (0)
#define  CBUS_PMM_CBUS_PHY_7_ldo_vsel_rx_mask                                    (0x0000001C)
#define  CBUS_PMM_CBUS_PHY_7_en_ldo_rx_mask                                      (0x00000002)
#define  CBUS_PMM_CBUS_PHY_7_en_bias_rx_mask                                     (0x00000001)
#define  CBUS_PMM_CBUS_PHY_7_ldo_vsel_rx(data)                                   (0x0000001C&((data)<<2))
#define  CBUS_PMM_CBUS_PHY_7_en_ldo_rx(data)                                     (0x00000002&((data)<<1))
#define  CBUS_PMM_CBUS_PHY_7_en_bias_rx(data)                                    (0x00000001&(data))
#define  CBUS_PMM_CBUS_PHY_7_get_ldo_vsel_rx(data)                               ((0x0000001C&(data))>>2)
#define  CBUS_PMM_CBUS_PHY_7_get_en_ldo_rx(data)                                 ((0x00000002&(data))>>1)
#define  CBUS_PMM_CBUS_PHY_7_get_en_bias_rx(data)                                (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CBUS_PMM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
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
        RBus_UInt32  res2:1;
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
        RBus_UInt32  res1:24;
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
        RBus_UInt32  res1:32;
    };
}cbus_pmm_cbus_standby_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
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
        RBus_UInt32  res1:29;
        RBus_UInt32  en_driver_tx:1;
        RBus_UInt32  res2:2;
    };
}cbus_pmm_cbus_phy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hpd_r1k_bypass:1;
        RBus_UInt32  hdmi_mhl_sel:1;
        RBus_UInt32  res2:2;
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
        RBus_UInt32  res1:32;
    };
}cbus_pmm_cbus_phy_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}cbus_pmm_cbus_phy_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ldo_vsel_rx:3;
        RBus_UInt32  en_ldo_rx:1;
        RBus_UInt32  en_bias_rx:1;
    };
}cbus_pmm_cbus_phy_7_RBUS;

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
        RBus_UInt32  res1:28;
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
        RBus_UInt32  res1:1;
        RBus_UInt32  dis_lower:3;
        RBus_UInt32  dis_upper:4;
        RBus_UInt32  res2:24;
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
        RBus_UInt32  res1:24;
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
        RBus_UInt32  res1:32;
    };
}cbus_pmm_cbus_standby_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_phy_soft_rst_n:1;
        RBus_UInt32  res1:31;
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
        RBus_UInt32  res2:29;
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
        RBus_UInt32  res2:16;
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
        RBus_UInt32  res1:32;
    };
}cbus_pmm_cbus_phy_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}cbus_pmm_cbus_phy_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_bias_rx:1;
        RBus_UInt32  en_ldo_rx:1;
        RBus_UInt32  ldo_vsel_rx:3;
        RBus_UInt32  res1:27;
    };
}cbus_pmm_cbus_phy_7_RBUS;




#endif 


#endif 
