/**
* @file rbusECBUS_RXReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ECBUS_RX_REG_H_
#define _RBUS_ECBUS_RX_REG_H_

#include "rbus_types.h"



//  ECBUS_RX Register Address
#define  ECBUS_RX_ECBUS_STARTUP_CTRL                                             0x1800A500
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_reg_addr                                    "0xB800A500"
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_reg                                         0xB800A500
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_inst_addr                                   "0x0000"
#define  set_ECBUS_RX_ECBUS_STARTUP_CTRL_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_STARTUP_CTRL_reg)=data)
#define  get_ECBUS_RX_ECBUS_STARTUP_CTRL_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_STARTUP_CTRL_reg))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_mac_in_latch_clk_inv_sel_shift        (8)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_cbus1_inout_swap_shift                      (7)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_emsc_inout_swap_shift                       (6)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_cbus1_cmd_swap_shift                        (5)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_mark_swap_shift                             (4)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_pwup_shift                            (3)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_irq_shift                             (2)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_reset_shift                           (1)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_comma2_det_en_shift                         (0)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_mac_in_latch_clk_inv_sel_mask         (0x00000100)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_cbus1_inout_swap_mask                       (0x00000080)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_emsc_inout_swap_mask                        (0x00000040)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_cbus1_cmd_swap_mask                         (0x00000020)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_mark_swap_mask                              (0x00000010)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_pwup_mask                             (0x00000008)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_irq_mask                              (0x00000004)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_reset_mask                            (0x00000002)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_comma2_det_en_mask                          (0x00000001)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_mac_in_latch_clk_inv_sel(data)        (0x00000100&((data)<<8))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_cbus1_inout_swap(data)                      (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_emsc_inout_swap(data)                       (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_cbus1_cmd_swap(data)                        (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_mark_swap(data)                             (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_pwup(data)                            (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_irq(data)                             (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_ecbus_reset(data)                           (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_comma2_det_en(data)                         (0x00000001&(data))
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_get_ecbus_mac_in_latch_clk_inv_sel(data)    ((0x00000100&(data))>>8)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_get_cbus1_inout_swap(data)                  ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_get_emsc_inout_swap(data)                   ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_get_cbus1_cmd_swap(data)                    ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_get_mark_swap(data)                         ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_get_ecbus_pwup(data)                        ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_get_ecbus_irq(data)                         ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_get_ecbus_reset(data)                       ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_STARTUP_CTRL_get_comma2_det_en(data)                     (0x00000001&(data))

#define  ECBUS_RX_ECBUS_STARTUP_CONFIG                                           0x1800A504
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_reg_addr                                  "0xB800A504"
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_reg                                       0xB800A504
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_inst_addr                                 "0x0001"
#define  set_ECBUS_RX_ECBUS_STARTUP_CONFIG_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_STARTUP_CONFIG_reg)=data)
#define  get_ECBUS_RX_ECBUS_STARTUP_CONFIG_reg                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_STARTUP_CONFIG_reg))
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_fwd_valid_shift                           (7)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_comma_lsb_first_shift                     (6)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_bwd_type_shift                            (4)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_comma2_debounce_shift                     (2)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_comma2_loss_thd_shift                     (0)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_fwd_valid_mask                            (0x00000080)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_comma_lsb_first_mask                      (0x00000040)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_bwd_type_mask                             (0x00000030)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_comma2_debounce_mask                      (0x0000000C)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_comma2_loss_thd_mask                      (0x00000003)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_fwd_valid(data)                           (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_comma_lsb_first(data)                     (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_bwd_type(data)                            (0x00000030&((data)<<4))
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_comma2_debounce(data)                     (0x0000000C&((data)<<2))
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_comma2_loss_thd(data)                     (0x00000003&(data))
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_get_fwd_valid(data)                       ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_get_comma_lsb_first(data)                 ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_get_bwd_type(data)                        ((0x00000030&(data))>>4)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_get_comma2_debounce(data)                 ((0x0000000C&(data))>>2)
#define  ECBUS_RX_ECBUS_STARTUP_CONFIG_get_comma2_loss_thd(data)                 (0x00000003&(data))

#define  ECBUS_RX_ECBUS_STARTUP_DET                                              0x1800A508
#define  ECBUS_RX_ECBUS_STARTUP_DET_reg_addr                                     "0xB800A508"
#define  ECBUS_RX_ECBUS_STARTUP_DET_reg                                          0xB800A508
#define  ECBUS_RX_ECBUS_STARTUP_DET_inst_addr                                    "0x0002"
#define  set_ECBUS_RX_ECBUS_STARTUP_DET_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_ECBUS_STARTUP_DET_reg)=data)
#define  get_ECBUS_RX_ECBUS_STARTUP_DET_reg                                      (*((volatile unsigned int*)ECBUS_RX_ECBUS_STARTUP_DET_reg))
#define  ECBUS_RX_ECBUS_STARTUP_DET_force_startup_done_shift                     (7)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma_tx_disp0_shift                         (6)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma_tx_disp1_shift                         (5)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_chk_disp_shift                        (4)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_rcv_irq_shift                         (3)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_rcv_irq_en_shift                      (2)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_loss_irq_shift                        (1)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_loss_irq_en_shift                     (0)
#define  ECBUS_RX_ECBUS_STARTUP_DET_force_startup_done_mask                      (0x00000080)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma_tx_disp0_mask                          (0x00000040)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma_tx_disp1_mask                          (0x00000020)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_chk_disp_mask                         (0x00000010)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_rcv_irq_mask                          (0x00000008)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_rcv_irq_en_mask                       (0x00000004)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_loss_irq_mask                         (0x00000002)
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_loss_irq_en_mask                      (0x00000001)
#define  ECBUS_RX_ECBUS_STARTUP_DET_force_startup_done(data)                     (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma_tx_disp0(data)                         (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma_tx_disp1(data)                         (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_chk_disp(data)                        (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_rcv_irq(data)                         (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_rcv_irq_en(data)                      (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_loss_irq(data)                        (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_STARTUP_DET_comma2_loss_irq_en(data)                     (0x00000001&(data))
#define  ECBUS_RX_ECBUS_STARTUP_DET_get_force_startup_done(data)                 ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_STARTUP_DET_get_comma_tx_disp0(data)                     ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_STARTUP_DET_get_comma_tx_disp1(data)                     ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_STARTUP_DET_get_comma2_chk_disp(data)                    ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_STARTUP_DET_get_comma2_rcv_irq(data)                     ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_STARTUP_DET_get_comma2_rcv_irq_en(data)                  ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_STARTUP_DET_get_comma2_loss_irq(data)                    ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_STARTUP_DET_get_comma2_loss_irq_en(data)                 (0x00000001&(data))

#define  ECBUS_RX_ECBUS_STARTUP_OPTION                                           0x1800A50C
#define  ECBUS_RX_ECBUS_STARTUP_OPTION_reg_addr                                  "0xB800A50C"
#define  ECBUS_RX_ECBUS_STARTUP_OPTION_reg                                       0xB800A50C
#define  ECBUS_RX_ECBUS_STARTUP_OPTION_inst_addr                                 "0x0003"
#define  set_ECBUS_RX_ECBUS_STARTUP_OPTION_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_STARTUP_OPTION_reg)=data)
#define  get_ECBUS_RX_ECBUS_STARTUP_OPTION_reg                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_STARTUP_OPTION_reg))
#define  ECBUS_RX_ECBUS_STARTUP_OPTION_dummy_7_0_shift                           (0)
#define  ECBUS_RX_ECBUS_STARTUP_OPTION_dummy_7_0_mask                            (0x000000FF)
#define  ECBUS_RX_ECBUS_STARTUP_OPTION_dummy_7_0(data)                           (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_STARTUP_OPTION_get_dummy_7_0(data)                       (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL                                            0x1800A510
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_reg_addr                                   "0xB800A510"
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_reg                                        0xB800A510
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_inst_addr                                  "0x0004"
#define  set_ECBUS_RX_ECBUS_TDM_SYNC_CTRL_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_CTRL_reg)=data)
#define  get_ECBUS_RX_ECBUS_TDM_SYNC_CTRL_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_CTRL_reg))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_resp_com2_m_shift                          (7)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_sent_com2_shift                            (6)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_enter_tdm_active_shift                     (5)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_com1_det_en_shift                          (4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_ignore_idle_det_shift                      (3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_sent_com1_shift                            (2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_tdm_sync_retry_shift                       (1)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_tdm_sync_reinit_shift                      (0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_resp_com2_m_mask                           (0x00000080)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_sent_com2_mask                             (0x00000040)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_enter_tdm_active_mask                      (0x00000020)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_com1_det_en_mask                           (0x00000010)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_ignore_idle_det_mask                       (0x00000008)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_sent_com1_mask                             (0x00000004)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_tdm_sync_retry_mask                        (0x00000002)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_tdm_sync_reinit_mask                       (0x00000001)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_resp_com2_m(data)                          (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_sent_com2(data)                            (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_enter_tdm_active(data)                     (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_com1_det_en(data)                          (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_ignore_idle_det(data)                      (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_sent_com1(data)                            (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_tdm_sync_retry(data)                       (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_tdm_sync_reinit(data)                      (0x00000001&(data))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_get_resp_com2_m(data)                      ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_get_sent_com2(data)                        ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_get_enter_tdm_active(data)                 ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_get_com1_det_en(data)                      ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_get_ignore_idle_det(data)                  ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_get_sent_com1(data)                        ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_get_tdm_sync_retry(data)                   ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CTRL_get_tdm_sync_reinit(data)                  (0x00000001&(data))

#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1                                        0x1800A514
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_reg_addr                               "0xB800A514"
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_reg                                    0xB800A514
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_inst_addr                              "0x0005"
#define  set_ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_reg(data)                          (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_reg                                (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_reg))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_com1_debounce_shift                    (6)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_com1_loss_thd_shift                    (4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_idle_err_thd_shift                     (2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_com2_debounce_shift                    (0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_com1_debounce_mask                     (0x000000C0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_com1_loss_thd_mask                     (0x00000030)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_idle_err_thd_mask                      (0x0000000C)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_com2_debounce_mask                     (0x00000003)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_com1_debounce(data)                    (0x000000C0&((data)<<6))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_com1_loss_thd(data)                    (0x00000030&((data)<<4))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_idle_err_thd(data)                     (0x0000000C&((data)<<2))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_com2_debounce(data)                    (0x00000003&(data))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_get_com1_debounce(data)                ((0x000000C0&(data))>>6)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_get_com1_loss_thd(data)                ((0x00000030&(data))>>4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_get_idle_err_thd(data)                 ((0x0000000C&(data))>>2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_1_get_com2_debounce(data)                (0x00000003&(data))

#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2                                        0x1800A518
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_reg_addr                               "0xB800A518"
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_reg                                    0xB800A518
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_inst_addr                              "0x0006"
#define  set_ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_reg(data)                          (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_reg                                (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_reg))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_tdm_sync_loss_thd_shift                (0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_tdm_sync_loss_thd_mask                 (0x000000FF)
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_tdm_sync_loss_thd(data)                (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_TDM_SYNC_CONFIG_2_get_tdm_sync_loss_thd(data)            (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1                                           0x1800A51C
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_reg_addr                                  "0xB800A51C"
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_reg                                       0xB800A51C
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_inst_addr                                 "0x0007"
#define  set_ECBUS_RX_ECBUS_TDM_SYNC_DET_1_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_DET_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_TDM_SYNC_DET_1_reg                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_DET_1_reg))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_dummy_7_6_shift                           (6)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com2_rcv_irq_en_shift                     (5)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_idle_err_shift                       (4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_rcv_irq_shift                        (3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_rcv_irq_en_shift                     (2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_loss_shift                           (1)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com2_rcv_irq_shift                        (0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_dummy_7_6_mask                            (0x000000C0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com2_rcv_irq_en_mask                      (0x00000020)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_idle_err_mask                        (0x00000010)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_rcv_irq_mask                         (0x00000008)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_rcv_irq_en_mask                      (0x00000004)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_loss_mask                            (0x00000002)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com2_rcv_irq_mask                         (0x00000001)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_dummy_7_6(data)                           (0x000000C0&((data)<<6))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com2_rcv_irq_en(data)                     (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_idle_err(data)                       (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_rcv_irq(data)                        (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_rcv_irq_en(data)                     (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com1_loss(data)                           (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_com2_rcv_irq(data)                        (0x00000001&(data))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_get_dummy_7_6(data)                       ((0x000000C0&(data))>>6)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_get_com2_rcv_irq_en(data)                 ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_get_com1_idle_err(data)                   ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_get_com1_rcv_irq(data)                    ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_get_com1_rcv_irq_en(data)                 ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_get_com1_loss(data)                       ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_1_get_com2_rcv_irq(data)                    (0x00000001&(data))

#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2                                           0x1800A520
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_reg_addr                                  "0xB800A520"
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_reg                                       0xB800A520
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_inst_addr                                 "0x0008"
#define  set_ECBUS_RX_ECBUS_TDM_SYNC_DET_2_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_DET_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_TDM_SYNC_DET_2_reg                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_DET_2_reg))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_dummy_7_5_shift                           (5)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_chk_when_loss_shift                       (4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_irq_shift                        (3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_irq_en_shift                     (2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_loss_irq_shift                   (1)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_loss_irq_en_shift                (0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_dummy_7_5_mask                            (0x000000E0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_chk_when_loss_mask                        (0x00000010)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_irq_mask                         (0x00000008)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_irq_en_mask                      (0x00000004)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_loss_irq_mask                    (0x00000002)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_loss_irq_en_mask                 (0x00000001)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_dummy_7_5(data)                           (0x000000E0&((data)<<5))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_chk_when_loss(data)                       (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_irq(data)                        (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_irq_en(data)                     (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_loss_irq(data)                   (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_tdm_sync_loss_irq_en(data)                (0x00000001&(data))
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_get_dummy_7_5(data)                       ((0x000000E0&(data))>>5)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_get_chk_when_loss(data)                   ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_get_tdm_sync_irq(data)                    ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_get_tdm_sync_irq_en(data)                 ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_get_tdm_sync_loss_irq(data)               ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_TDM_SYNC_DET_2_get_tdm_sync_loss_irq_en(data)            (0x00000001&(data))

#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET                                       0x1800A524
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_reg_addr                              "0xB800A524"
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_reg                                   0xB800A524
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_inst_addr                             "0x0009"
#define  set_ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_reg(data)                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_reg)=data)
#define  get_ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_reg                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_reg))
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_set_tx_offset_shift                   (4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_dummy_3_shift                         (3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_set_tx_offset_fine_shift              (0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_set_tx_offset_mask                    (0x000000F0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_dummy_3_mask                          (0x00000008)
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_set_tx_offset_fine_mask               (0x00000007)
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_set_tx_offset(data)                   (0x000000F0&((data)<<4))
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_dummy_3(data)                         (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_set_tx_offset_fine(data)              (0x00000007&(data))
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_get_set_tx_offset(data)               ((0x000000F0&(data))>>4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_get_dummy_3(data)                     ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_TX_OFFSET_get_set_tx_offset_fine(data)          (0x00000007&(data))

#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET                                       0x1800A528
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_reg_addr                              "0xB800A528"
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_reg                                   0xB800A528
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_inst_addr                             "0x000A"
#define  set_ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_reg(data)                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_reg)=data)
#define  get_ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_reg                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_reg))
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_check_rx_offset_shift                 (4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_dummy_3_shift                         (3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_check_rx_offset_fine_shift            (0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_check_rx_offset_mask                  (0x000000F0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_dummy_3_mask                          (0x00000008)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_check_rx_offset_fine_mask             (0x00000007)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_check_rx_offset(data)                 (0x000000F0&((data)<<4))
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_dummy_3(data)                         (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_check_rx_offset_fine(data)            (0x00000007&(data))
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_get_check_rx_offset(data)             ((0x000000F0&(data))>>4)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_get_dummy_3(data)                     ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RX_OFFSET_get_check_rx_offset_fine(data)        (0x00000007&(data))

#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE                                         0x1800A52C
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_reg_addr                                "0xB800A52C"
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_reg                                     0xB800A52C
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_inst_addr                               "0x000B"
#define  set_ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_reg(data)                           (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_reg)=data)
#define  get_ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_reg                                 (*((volatile unsigned int*)ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_reg))
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_dummy_7_2_shift                         (2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_check_rx_offset_range_shift             (0)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_dummy_7_2_mask                          (0x000000FC)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_check_rx_offset_range_mask              (0x00000003)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_dummy_7_2(data)                         (0x000000FC&((data)<<2))
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_check_rx_offset_range(data)             (0x00000003&(data))
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_get_dummy_7_2(data)                     ((0x000000FC&(data))>>2)
#define  ECBUS_RX_ECBUS_TDM_SYNC_RESERVE_get_check_rx_offset_range(data)         (0x00000003&(data))

#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL                                           0x1800A530
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_reg_addr                                  "0xB800A530"
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_reg                                       0xB800A530
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_inst_addr                                 "0x000C"
#define  set_ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_reg                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_reg))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_dummy_7_5_shift                           (5)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_emsc_reset_shift                          (4)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_sent_mark_sel_shift                       (3)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_emsc_sync_start_shift                     (2)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_sync_err_det_en_shift                     (1)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_mark2_accept_shift                        (0)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_dummy_7_5_mask                            (0x000000E0)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_emsc_reset_mask                           (0x00000010)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_sent_mark_sel_mask                        (0x00000008)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_emsc_sync_start_mask                      (0x00000004)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_sync_err_det_en_mask                      (0x00000002)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_mark2_accept_mask                         (0x00000001)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_dummy_7_5(data)                           (0x000000E0&((data)<<5))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_emsc_reset(data)                          (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_sent_mark_sel(data)                       (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_emsc_sync_start(data)                     (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_sync_err_det_en(data)                     (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_mark2_accept(data)                        (0x00000001&(data))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_get_dummy_7_5(data)                       ((0x000000E0&(data))>>5)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_get_emsc_reset(data)                      ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_get_sent_mark_sel(data)                   ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_get_emsc_sync_start(data)                 ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_get_sync_err_det_en(data)                 ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CTRL_get_mark2_accept(data)                    (0x00000001&(data))

#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1                                       0x1800A534
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_reg_addr                              "0xB800A534"
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_reg                                   0xB800A534
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_inst_addr                             "0x000D"
#define  set_ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_reg(data)                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_reg                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_reg))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_sync_debounce_shift                   (5)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_sync_err_thd_shift                    (3)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_mark_loss_thd_shift                   (0)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_sync_debounce_mask                    (0x000000E0)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_sync_err_thd_mask                     (0x00000018)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_mark_loss_thd_mask                    (0x00000007)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_sync_debounce(data)                   (0x000000E0&((data)<<5))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_sync_err_thd(data)                    (0x00000018&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_mark_loss_thd(data)                   (0x00000007&(data))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_get_sync_debounce(data)               ((0x000000E0&(data))>>5)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_get_sync_err_thd(data)                ((0x00000018&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_1_get_mark_loss_thd(data)               (0x00000007&(data))

#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2                                       0x1800A538
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_reg_addr                              "0xB800A538"
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_reg                                   0xB800A538
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_inst_addr                             "0x000E"
#define  set_ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_reg(data)                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_reg                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_reg))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_dummy_7_4_shift                       (4)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_rx_sync_thd_shift                     (2)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_tx_sync_thd_shift                     (0)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_dummy_7_4_mask                        (0x000000F0)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_rx_sync_thd_mask                      (0x0000000C)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_tx_sync_thd_mask                      (0x00000003)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_dummy_7_4(data)                       (0x000000F0&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_rx_sync_thd(data)                     (0x0000000C&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_tx_sync_thd(data)                     (0x00000003&(data))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_get_dummy_7_4(data)                   ((0x000000F0&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_get_rx_sync_thd(data)                 ((0x0000000C&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_CONFIG_2_get_tx_sync_thd(data)                 (0x00000003&(data))

#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET                                            0x1800A53C
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_reg_addr                                   "0xB800A53C"
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_reg                                        0xB800A53C
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_inst_addr                                  "0x000F"
#define  set_ECBUS_RX_ECBUS_EMSC_SYNC_DET_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_DET_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SYNC_DET_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_DET_reg))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_sync_rcv_shift                             (7)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_sync_loss_shift                            (6)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_rx_sync_meet_shift                         (5)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_mark_rcv_shift                             (4)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_emsc_link_done_shift                       (3)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_slot_det_done_shift                        (2)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_mark_loss_irq_shift                        (1)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_mark_loss_irq_en_shift                     (0)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_sync_rcv_mask                              (0x00000080)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_sync_loss_mask                             (0x00000040)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_rx_sync_meet_mask                          (0x00000020)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_mark_rcv_mask                              (0x00000010)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_emsc_link_done_mask                        (0x00000008)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_slot_det_done_mask                         (0x00000004)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_mark_loss_irq_mask                         (0x00000002)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_mark_loss_irq_en_mask                      (0x00000001)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_sync_rcv(data)                             (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_sync_loss(data)                            (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_rx_sync_meet(data)                         (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_mark_rcv(data)                             (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_emsc_link_done(data)                       (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_slot_det_done(data)                        (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_mark_loss_irq(data)                        (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_mark_loss_irq_en(data)                     (0x00000001&(data))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_get_sync_rcv(data)                         ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_get_sync_loss(data)                        ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_get_rx_sync_meet(data)                     ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_get_mark_rcv(data)                         ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_get_emsc_link_done(data)                   ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_get_slot_det_done(data)                    ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_get_mark_loss_irq(data)                    ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_DET_get_mark_loss_irq_en(data)                 (0x00000001&(data))

#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1                                          0x1800A540
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_reg_addr                                 "0xB800A540"
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_reg                                      0xB800A540
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_inst_addr                                "0x0010"
#define  set_ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_reg))
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_emsc_slot_map_h_shift                    (0)
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_emsc_slot_map_h_mask                     (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_emsc_slot_map_h(data)                    (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_1_get_emsc_slot_map_h(data)                (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2                                          0x1800A544
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_reg_addr                                 "0xB800A544"
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_reg                                      0xB800A544
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_inst_addr                                "0x0011"
#define  set_ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_reg))
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_emsc_slot_map_m_shift                    (0)
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_emsc_slot_map_m_mask                     (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_emsc_slot_map_m(data)                    (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_2_get_emsc_slot_map_m(data)                (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3                                          0x1800A548
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_reg_addr                                 "0xB800A548"
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_reg                                      0xB800A548
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_inst_addr                                "0x0012"
#define  set_ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_reg))
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_emsc_slot_map_l_shift                    (0)
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_emsc_slot_map_l_mask                     (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_emsc_slot_map_l(data)                    (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_SLOT_MAP_3_get_emsc_slot_map_l(data)                (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1                                   0x1800A54C
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_reg_addr                          "0xB800A54C"
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_reg                               0xB800A54C
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_inst_addr                         "0x0013"
#define  set_ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_reg                           (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_reg))
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_sourse_slot_map_h_shift           (0)
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_sourse_slot_map_h_mask            (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_sourse_slot_map_h(data)           (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_1_get_sourse_slot_map_h(data)       (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2                                   0x1800A550
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_reg_addr                          "0xB800A550"
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_reg                               0xB800A550
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_inst_addr                         "0x0014"
#define  set_ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_reg                           (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_reg))
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_sourse_slot_map_m_shift           (0)
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_sourse_slot_map_m_mask            (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_sourse_slot_map_m(data)           (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_2_get_sourse_slot_map_m(data)       (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3                                   0x1800A554
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_reg_addr                          "0xB800A554"
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_reg                               0xB800A554
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_inst_addr                         "0x0015"
#define  set_ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_reg(data)                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_reg                           (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_reg))
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_sourse_slot_map_l_shift           (0)
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_sourse_slot_map_l_mask            (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_sourse_slot_map_l(data)           (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_SOURCE_SLOT_DET_3_get_sourse_slot_map_l(data)       (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE                                        0x1800A558
#define  ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_reg_addr                               "0xB800A558"
#define  ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_reg                                    0xB800A558
#define  ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_inst_addr                              "0x0016"
#define  set_ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_reg(data)                          (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_reg                                (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_reg))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_dummy_7_0_shift                        (0)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_dummy_7_0_mask                         (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_dummy_7_0(data)                        (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_SYNC_RESERVE_get_dummy_7_0(data)                    (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_RX_ADDR                                             0x1800A55C
#define  ECBUS_RX_ECBUS_EMSC_RX_ADDR_reg_addr                                    "0xB800A55C"
#define  ECBUS_RX_ECBUS_EMSC_RX_ADDR_reg                                         0xB800A55C
#define  ECBUS_RX_ECBUS_EMSC_RX_ADDR_inst_addr                                   "0x0017"
#define  set_ECBUS_RX_ECBUS_EMSC_RX_ADDR_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_ADDR_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_RX_ADDR_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_ADDR_reg))
#define  ECBUS_RX_ECBUS_EMSC_RX_ADDR_emsc_rxbuf_rpt_shift                        (0)
#define  ECBUS_RX_ECBUS_EMSC_RX_ADDR_emsc_rxbuf_rpt_mask                         (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_RX_ADDR_emsc_rxbuf_rpt(data)                        (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_RX_ADDR_get_emsc_rxbuf_rpt(data)                    (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_RX_DATA                                             0x1800A560
#define  ECBUS_RX_ECBUS_EMSC_RX_DATA_reg_addr                                    "0xB800A560"
#define  ECBUS_RX_ECBUS_EMSC_RX_DATA_reg                                         0xB800A560
#define  ECBUS_RX_ECBUS_EMSC_RX_DATA_inst_addr                                   "0x0018"
#define  set_ECBUS_RX_ECBUS_EMSC_RX_DATA_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_DATA_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_RX_DATA_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_DATA_reg))
#define  ECBUS_RX_ECBUS_EMSC_RX_DATA_emsc_rxbuf_rdata_shift                      (0)
#define  ECBUS_RX_ECBUS_EMSC_RX_DATA_emsc_rxbuf_rdata_mask                       (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_RX_DATA_emsc_rxbuf_rdata(data)                      (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_RX_DATA_get_emsc_rxbuf_rdata(data)                  (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_ADDR                                             0x1800A564
#define  ECBUS_RX_ECBUS_EMSC_TX_ADDR_reg_addr                                    "0xB800A564"
#define  ECBUS_RX_ECBUS_EMSC_TX_ADDR_reg                                         0xB800A564
#define  ECBUS_RX_ECBUS_EMSC_TX_ADDR_inst_addr                                   "0x0019"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_ADDR_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_ADDR_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_ADDR_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_ADDR_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_ADDR_emsc_txbuf_wpt_shift                        (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_ADDR_emsc_txbuf_wpt_mask                         (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TX_ADDR_emsc_txbuf_wpt(data)                        (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_ADDR_get_emsc_txbuf_wpt(data)                    (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_DATA                                             0x1800A568
#define  ECBUS_RX_ECBUS_EMSC_TX_DATA_reg_addr                                    "0xB800A568"
#define  ECBUS_RX_ECBUS_EMSC_TX_DATA_reg                                         0xB800A568
#define  ECBUS_RX_ECBUS_EMSC_TX_DATA_inst_addr                                   "0x001A"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_DATA_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_DATA_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_DATA_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_DATA_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_DATA_emsc_txbuf_wdata_shift                      (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_DATA_emsc_txbuf_wdata_mask                       (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TX_DATA_emsc_txbuf_wdata(data)                      (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_DATA_get_emsc_txbuf_wdata(data)                  (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR                                          0x1800A56C
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_reg_addr                                 "0xB800A56C"
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_reg                                      0xB800A56C
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_inst_addr                                "0x001B"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_emsc_txbuf_rpt_shift                     (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_emsc_txbuf_rpt_mask                      (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_emsc_txbuf_rpt(data)                     (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_ADDR_get_emsc_txbuf_rpt(data)                 (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_RD_DATA                                          0x1800A570
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_reg_addr                                 "0xB800A570"
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_reg                                      0xB800A570
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_inst_addr                                "0x001C"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_emsc_txbuf_rdata_shift                   (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_emsc_txbuf_rdata_mask                    (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_emsc_txbuf_rdata(data)                   (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_RD_DATA_get_emsc_txbuf_rdata(data)               (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL                                          0x1800A574
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_reg_addr                                 "0xB800A574"
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_reg                                      0xB800A574
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_inst_addr                                "0x001D"
#define  set_ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_reg))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_dummy_7_shift                            (7)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_tx_dstart_option_shift                   (6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_hw_chk_remain_shift                      (5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_chk_cmd_option_shift                     (4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_unexpect_option_shift                    (3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_block_fw_done_shift                      (2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_emsc_tx_sent_shift                       (1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_emsc_txbuf_fw_mode_shift                 (0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_dummy_7_mask                             (0x00000080)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_tx_dstart_option_mask                    (0x00000040)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_hw_chk_remain_mask                       (0x00000020)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_chk_cmd_option_mask                      (0x00000010)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_unexpect_option_mask                     (0x00000008)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_block_fw_done_mask                       (0x00000004)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_emsc_tx_sent_mask                        (0x00000002)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_emsc_txbuf_fw_mode_mask                  (0x00000001)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_dummy_7(data)                            (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_tx_dstart_option(data)                   (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_hw_chk_remain(data)                      (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_chk_cmd_option(data)                     (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_unexpect_option(data)                    (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_block_fw_done(data)                      (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_emsc_tx_sent(data)                       (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_emsc_txbuf_fw_mode(data)                 (0x00000001&(data))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_get_dummy_7(data)                        ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_get_tx_dstart_option(data)               ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_get_hw_chk_remain(data)                  ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_get_chk_cmd_option(data)                 ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_get_unexpect_option(data)                ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_get_block_fw_done(data)                  ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_get_emsc_tx_sent(data)                   ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CTRL_get_emsc_txbuf_fw_mode(data)             (0x00000001&(data))

#define  ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT                                          0x1800A578
#define  ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_reg_addr                                 "0xB800A578"
#define  ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_reg                                      0xB800A578
#define  ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_inst_addr                                "0x001E"
#define  set_ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_reg))
#define  ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_emsc_rx_block_cnt_shift                  (0)
#define  ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_emsc_rx_block_cnt_mask                   (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_emsc_rx_block_cnt(data)                  (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_RX_BLK_CNT_get_emsc_rx_block_cnt(data)              (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT                                          0x1800A57C
#define  ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_reg_addr                                 "0xB800A57C"
#define  ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_reg                                      0xB800A57C
#define  ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_inst_addr                                "0x001F"
#define  set_ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_reg))
#define  ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_emsc_rx_wr_point_shift                   (0)
#define  ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_emsc_rx_wr_point_mask                    (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_emsc_rx_wr_point(data)                   (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_RX_WRT_PNT_get_emsc_rx_wr_point(data)               (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT                                          0x1800A580
#define  ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_reg_addr                                 "0xB800A580"
#define  ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_reg                                      0xB800A580
#define  ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_inst_addr                                "0x0020"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_emsc_tx_rd_point_shift                   (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_emsc_tx_rd_point_mask                    (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_emsc_tx_rd_point(data)                   (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_WRT_PNT_get_emsc_tx_rd_point(data)               (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT                                          0x1800A584
#define  ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_reg_addr                                 "0xB800A584"
#define  ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_reg                                      0xB800A584
#define  ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_inst_addr                                "0x0021"
#define  set_ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_reg))
#define  ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_emsc_rx_req_cnt_shift                    (0)
#define  ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_emsc_rx_req_cnt_mask                     (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_emsc_rx_req_cnt(data)                    (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_RX_REQ_CNT_get_emsc_rx_req_cnt(data)                (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT                                          0x1800A588
#define  ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_reg_addr                                 "0xB800A588"
#define  ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_reg                                      0xB800A588
#define  ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_inst_addr                                "0x0022"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_emsc_tx_req_cnt_shift                    (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_emsc_tx_req_cnt_mask                     (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_emsc_tx_req_cnt(data)                    (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_REQ_CNT_get_emsc_tx_req_cnt(data)                (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1                                      0x1800A58C
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_reg_addr                             "0xB800A58C"
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_reg                                  0xB800A58C
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_inst_addr                            "0x0023"
#define  set_ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_reg(data)                        (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_reg                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_reg))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_dummy_7_4_shift                      (4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_rx_ignore_byte_shift                 (0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_dummy_7_4_mask                       (0x000000F0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_rx_ignore_byte_mask                  (0x0000000F)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_dummy_7_4(data)                      (0x000000F0&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_rx_ignore_byte(data)                 (0x0000000F&(data))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_get_dummy_7_4(data)                  ((0x000000F0&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_1_get_rx_ignore_byte(data)             (0x0000000F&(data))

#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2                                      0x1800A590
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_reg_addr                             "0xB800A590"
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_reg                                  0xB800A590
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_inst_addr                            "0x0024"
#define  set_ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_reg(data)                        (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_reg                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_reg))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_emsc_req_tout_shift                  (6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_retry_num_shift                      (4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_retry_wait_shift                     (0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_emsc_req_tout_mask                   (0x000000C0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_retry_num_mask                       (0x00000030)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_retry_wait_mask                      (0x0000000F)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_emsc_req_tout(data)                  (0x000000C0&((data)<<6))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_retry_num(data)                      (0x00000030&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_retry_wait(data)                     (0x0000000F&(data))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_get_emsc_req_tout(data)              ((0x000000C0&(data))>>6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_get_retry_num(data)                  ((0x00000030&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_CONFIG_2_get_retry_wait(data)                 (0x0000000F&(data))

#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1                                         0x1800A594
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_reg_addr                                "0xB800A594"
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_reg                                     0xB800A594
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_inst_addr                               "0x0025"
#define  set_ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_reg(data)                           (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_reg                                 (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_reg))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_full_shift                        (7)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_empty_shift                       (6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_clr_shift                         (5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rx_reply_nack_shift                     (4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_ovfl_irq_shift                    (3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_ovfl_irq_en_shift                 (2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_udfl_irq_shift                    (1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_udfl_irq_en_shift                 (0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_full_mask                         (0x00000080)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_empty_mask                        (0x00000040)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_clr_mask                          (0x00000020)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rx_reply_nack_mask                      (0x00000010)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_ovfl_irq_mask                     (0x00000008)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_ovfl_irq_en_mask                  (0x00000004)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_udfl_irq_mask                     (0x00000002)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_udfl_irq_en_mask                  (0x00000001)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_full(data)                        (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_empty(data)                       (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_clr(data)                         (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rx_reply_nack(data)                     (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_ovfl_irq(data)                    (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_ovfl_irq_en(data)                 (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_udfl_irq(data)                    (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_rxbuf_udfl_irq_en(data)                 (0x00000001&(data))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_get_rxbuf_full(data)                    ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_get_rxbuf_empty(data)                   ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_get_rxbuf_clr(data)                     ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_get_rx_reply_nack(data)                 ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_get_rxbuf_ovfl_irq(data)                ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_get_rxbuf_ovfl_irq_en(data)             ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_get_rxbuf_udfl_irq(data)                ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_1_get_rxbuf_udfl_irq_en(data)             (0x00000001&(data))

#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2                                         0x1800A598
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_reg_addr                                "0xB800A598"
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_reg                                     0xB800A598
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_inst_addr                               "0x0026"
#define  set_ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_reg(data)                           (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_reg                                 (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_reg))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_full_shift                        (7)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_empty_shift                       (6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_clr_shift                         (5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_payload_crc_err_shift                   (4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_ovfl_irq_shift                    (3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_ovfl_irq_en_shift                 (2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_udfl_irq_shift                    (1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_udfl_irq_en_shift                 (0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_full_mask                         (0x00000080)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_empty_mask                        (0x00000040)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_clr_mask                          (0x00000020)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_payload_crc_err_mask                    (0x00000010)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_ovfl_irq_mask                     (0x00000008)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_ovfl_irq_en_mask                  (0x00000004)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_udfl_irq_mask                     (0x00000002)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_udfl_irq_en_mask                  (0x00000001)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_full(data)                        (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_empty(data)                       (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_clr(data)                         (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_payload_crc_err(data)                   (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_ovfl_irq(data)                    (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_ovfl_irq_en(data)                 (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_udfl_irq(data)                    (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_txbuf_udfl_irq_en(data)                 (0x00000001&(data))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_get_txbuf_full(data)                    ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_get_txbuf_empty(data)                   ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_get_txbuf_clr(data)                     ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_get_payload_crc_err(data)               ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_get_txbuf_ovfl_irq(data)                ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_get_txbuf_ovfl_irq_en(data)             ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_get_txbuf_udfl_irq(data)                ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_2_get_txbuf_udfl_irq_en(data)             (0x00000001&(data))

#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3                                         0x1800A59C
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_reg_addr                                "0xB800A59C"
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_reg                                     0xB800A59C
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_inst_addr                               "0x0027"
#define  set_ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_reg(data)                           (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_reg                                 (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_reg))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_dummy_7_shift                           (7)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_rx_remain_noneq_cnt_shift               (6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_rx_done_irq_shift                  (5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_rx_done_irq_en_shift               (4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_tx_done_irq_shift                  (3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_tx_done_irq_en_shift               (2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_retry_limit_irq_shift                   (1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_retry_limit_irq_en_shift                (0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_dummy_7_mask                            (0x00000080)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_rx_remain_noneq_cnt_mask                (0x00000040)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_rx_done_irq_mask                   (0x00000020)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_rx_done_irq_en_mask                (0x00000010)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_tx_done_irq_mask                   (0x00000008)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_tx_done_irq_en_mask                (0x00000004)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_retry_limit_irq_mask                    (0x00000002)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_retry_limit_irq_en_mask                 (0x00000001)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_dummy_7(data)                           (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_rx_remain_noneq_cnt(data)               (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_rx_done_irq(data)                  (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_rx_done_irq_en(data)               (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_tx_done_irq(data)                  (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_emsc_tx_done_irq_en(data)               (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_retry_limit_irq(data)                   (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_retry_limit_irq_en(data)                (0x00000001&(data))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_get_dummy_7(data)                       ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_get_rx_remain_noneq_cnt(data)           ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_get_emsc_rx_done_irq(data)              ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_get_emsc_rx_done_irq_en(data)           ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_get_emsc_tx_done_irq(data)              ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_get_emsc_tx_done_irq_en(data)           ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_get_retry_limit_irq(data)               ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_3_get_retry_limit_irq_en(data)            (0x00000001&(data))

#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4                                         0x1800A5A0
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_reg_addr                                "0xB800A5A0"
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_reg                                     0xB800A5A0
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_inst_addr                               "0x0028"
#define  set_ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_reg(data)                           (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_reg                                 (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_reg))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_dummy_7_5_shift                         (5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_rx_time_out_shift                       (4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_time_out_shift                       (3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_get_nack_shift                       (2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_get_error_shift                      (1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_crc_inverted_shift                   (0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_dummy_7_5_mask                          (0x000000E0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_rx_time_out_mask                        (0x00000010)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_time_out_mask                        (0x00000008)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_get_nack_mask                        (0x00000004)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_get_error_mask                       (0x00000002)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_crc_inverted_mask                    (0x00000001)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_dummy_7_5(data)                         (0x000000E0&((data)<<5))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_rx_time_out(data)                       (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_time_out(data)                       (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_get_nack(data)                       (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_get_error(data)                      (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_tx_crc_inverted(data)                   (0x00000001&(data))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_get_dummy_7_5(data)                     ((0x000000E0&(data))>>5)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_get_rx_time_out(data)                   ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_get_tx_time_out(data)                   ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_get_tx_get_nack(data)                   ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_get_tx_get_error(data)                  ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_DET_4_get_tx_crc_inverted(data)               (0x00000001&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE                                         0x1800A5A4
#define  ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_reg_addr                                "0xB800A5A4"
#define  ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_reg                                     0xB800A5A4
#define  ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_inst_addr                               "0x0029"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_reg(data)                           (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_reg                                 (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_get_error_code_shift                    (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_get_error_code_mask                     (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_get_error_code(data)                    (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_ERR_CODE_get_get_error_code(data)                (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0                                     0x1800A5A8
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_reg_addr                            "0xB800A5A8"
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_reg                                 0xB800A5A8
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_inst_addr                           "0x002A"
#define  set_ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_reg(data)                       (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_reg                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_reg))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_rx_remain_shift                     (0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_rx_remain_mask                      (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_rx_remain(data)                     (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_0_get_rx_remain(data)                 (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1                                            0x1800A5AC
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_reg_addr                                   "0xB800A5AC"
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_reg                                        0xB800A5AC
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_inst_addr                                  "0x002B"
#define  set_ECBUS_RX_ECBUS_EMSC_RX_CRC_1_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_CRC_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_RX_CRC_1_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_CRC_1_reg))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_ack_crc_shift                          (6)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_nack_crc_shift                         (4)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_grant_crc_shift                        (2)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_dstart_crc_shift                       (0)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_ack_crc_mask                           (0x000000C0)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_nack_crc_mask                          (0x00000030)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_grant_crc_mask                         (0x0000000C)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_dstart_crc_mask                        (0x00000003)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_ack_crc(data)                          (0x000000C0&((data)<<6))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_nack_crc(data)                         (0x00000030&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_grant_crc(data)                        (0x0000000C&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_dstart_crc(data)                       (0x00000003&(data))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_get_ack_crc(data)                      ((0x000000C0&(data))>>6)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_get_nack_crc(data)                     ((0x00000030&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_get_grant_crc(data)                    ((0x0000000C&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_1_get_get_dstart_crc(data)                   (0x00000003&(data))

#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2                                            0x1800A5B0
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_reg_addr                                   "0xB800A5B0"
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_reg                                        0xB800A5B0
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_inst_addr                                  "0x002C"
#define  set_ECBUS_RX_ECBUS_EMSC_RX_CRC_2_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_CRC_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_RX_CRC_2_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_CRC_2_reg))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_dummy_7_6_shift                            (6)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_get_err00_crc_shift                        (3)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_get_err01_crc_shift                        (0)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_dummy_7_6_mask                             (0x000000C0)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_get_err00_crc_mask                         (0x00000038)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_get_err01_crc_mask                         (0x00000007)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_dummy_7_6(data)                            (0x000000C0&((data)<<6))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_get_err00_crc(data)                        (0x00000038&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_get_err01_crc(data)                        (0x00000007&(data))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_get_dummy_7_6(data)                        ((0x000000C0&(data))>>6)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_get_get_err00_crc(data)                    ((0x00000038&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_2_get_get_err01_crc(data)                    (0x00000007&(data))

#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_3                                            0x1800A5B4
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_3_reg_addr                                   "0xB800A5B4"
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_3_reg                                        0xB800A5B4
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_3_inst_addr                                  "0x002D"
#define  set_ECBUS_RX_ECBUS_EMSC_RX_CRC_3_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_CRC_3_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_RX_CRC_3_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_CRC_3_reg))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_3_get_payload_crc_15_8_shift                 (0)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_3_get_payload_crc_15_8_mask                  (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_3_get_payload_crc_15_8(data)                 (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_3_get_get_payload_crc_15_8(data)             (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_4                                            0x1800A5B8
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_4_reg_addr                                   "0xB800A5B8"
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_4_reg                                        0xB800A5B8
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_4_inst_addr                                  "0x002E"
#define  set_ECBUS_RX_ECBUS_EMSC_RX_CRC_4_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_CRC_4_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_RX_CRC_4_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_RX_CRC_4_reg))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_4_get_payload_crc_7_0_shift                  (0)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_4_get_payload_crc_7_0_mask                   (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_4_get_payload_crc_7_0(data)                  (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_RX_CRC_4_get_get_payload_crc_7_0(data)              (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1                                            0x1800A5BC
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_reg_addr                                   "0xB800A5BC"
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_reg                                        0xB800A5BC
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_inst_addr                                  "0x002F"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_CRC_1_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_CRC_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_CRC_1_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_CRC_1_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_ack_crc_shift                           (6)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_nack_crc_shift                          (4)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_grant_crc_shift                         (2)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_dstart_crc_shift                        (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_ack_crc_mask                            (0x000000C0)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_nack_crc_mask                           (0x00000030)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_grant_crc_mask                          (0x0000000C)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_dstart_crc_mask                         (0x00000003)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_ack_crc(data)                           (0x000000C0&((data)<<6))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_nack_crc(data)                          (0x00000030&((data)<<4))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_grant_crc(data)                         (0x0000000C&((data)<<2))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_tx_dstart_crc(data)                        (0x00000003&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_get_tx_ack_crc(data)                       ((0x000000C0&(data))>>6)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_get_tx_nack_crc(data)                      ((0x00000030&(data))>>4)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_get_tx_grant_crc(data)                     ((0x0000000C&(data))>>2)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_1_get_tx_dstart_crc(data)                    (0x00000003&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2                                            0x1800A5C0
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_reg_addr                                   "0xB800A5C0"
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_reg                                        0xB800A5C0
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_inst_addr                                  "0x0030"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_CRC_2_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_CRC_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_CRC_2_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_CRC_2_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_dummy_7_3_shift                            (3)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_tx_err01_crc_shift                         (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_dummy_7_3_mask                             (0x000000F8)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_tx_err01_crc_mask                          (0x00000007)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_dummy_7_3(data)                            (0x000000F8&((data)<<3))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_tx_err01_crc(data)                         (0x00000007&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_get_dummy_7_3(data)                        ((0x000000F8&(data))>>3)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_2_get_tx_err01_crc(data)                     (0x00000007&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_3                                            0x1800A5C4
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_3_reg_addr                                   "0xB800A5C4"
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_3_reg                                        0xB800A5C4
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_3_inst_addr                                  "0x0031"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_CRC_3_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_CRC_3_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_CRC_3_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_CRC_3_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_3_tx_payload_crc_15_8_shift                  (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_3_tx_payload_crc_15_8_mask                   (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_3_tx_payload_crc_15_8(data)                  (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_3_get_tx_payload_crc_15_8(data)              (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_4                                            0x1800A5C8
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_4_reg_addr                                   "0xB800A5C8"
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_4_reg                                        0xB800A5C8
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_4_inst_addr                                  "0x0032"
#define  set_ECBUS_RX_ECBUS_EMSC_TX_CRC_4_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_CRC_4_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TX_CRC_4_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TX_CRC_4_reg))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_4_tx_payload_crc_7_0_shift                   (0)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_4_tx_payload_crc_7_0_mask                    (0x000000FF)
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_4_tx_payload_crc_7_0(data)                   (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_EMSC_TX_CRC_4_get_tx_payload_crc_7_0(data)               (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1                                     0x1800A5CC
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_reg_addr                            "0xB800A5CC"
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_reg                                 0xB800A5CC
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_inst_addr                           "0x0033"
#define  set_ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_reg(data)                       (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_reg                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_reg))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_dummy_7_1_shift                     (1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_bist_out_inv_shift                  (0)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_dummy_7_1_mask                      (0x000000FE)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_bist_out_inv_mask                   (0x00000001)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_dummy_7_1(data)                     (0x000000FE&((data)<<1))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_bist_out_inv(data)                  (0x00000001&(data))
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_get_dummy_7_1(data)                 ((0x000000FE&(data))>>1)
#define  ECBUS_RX_ECBUS_EMSC_TRANS_RESERVE_1_get_bist_out_inv(data)              (0x00000001&(data))

#define  ECBUS_RX_ECBUS_BIST_CTRL                                                0x1800A5D0
#define  ECBUS_RX_ECBUS_BIST_CTRL_reg_addr                                       "0xB800A5D0"
#define  ECBUS_RX_ECBUS_BIST_CTRL_reg                                            0xB800A5D0
#define  ECBUS_RX_ECBUS_BIST_CTRL_inst_addr                                      "0x0034"
#define  set_ECBUS_RX_ECBUS_BIST_CTRL_reg(data)                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_CTRL_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_CTRL_reg                                        (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_CTRL_reg))
#define  ECBUS_RX_ECBUS_BIST_CTRL_lq_inv_shift                                   (7)
#define  ECBUS_RX_ECBUS_BIST_CTRL_gx_inv_shift                                   (6)
#define  ECBUS_RX_ECBUS_BIST_CTRL_bist_out_swap_shift                            (5)
#define  ECBUS_RX_ECBUS_BIST_CTRL_ecbus_bist_en_shift                            (4)
#define  ECBUS_RX_ECBUS_BIST_CTRL_bist_err_reset_shift                           (3)
#define  ECBUS_RX_ECBUS_BIST_CTRL_prbs_reset_shift                               (2)
#define  ECBUS_RX_ECBUS_BIST_CTRL_bist_comp_start_shift                          (1)
#define  ECBUS_RX_ECBUS_BIST_CTRL_rx_bist_stop_shift                             (0)
#define  ECBUS_RX_ECBUS_BIST_CTRL_lq_inv_mask                                    (0x00000080)
#define  ECBUS_RX_ECBUS_BIST_CTRL_gx_inv_mask                                    (0x00000040)
#define  ECBUS_RX_ECBUS_BIST_CTRL_bist_out_swap_mask                             (0x00000020)
#define  ECBUS_RX_ECBUS_BIST_CTRL_ecbus_bist_en_mask                             (0x00000010)
#define  ECBUS_RX_ECBUS_BIST_CTRL_bist_err_reset_mask                            (0x00000008)
#define  ECBUS_RX_ECBUS_BIST_CTRL_prbs_reset_mask                                (0x00000004)
#define  ECBUS_RX_ECBUS_BIST_CTRL_bist_comp_start_mask                           (0x00000002)
#define  ECBUS_RX_ECBUS_BIST_CTRL_rx_bist_stop_mask                              (0x00000001)
#define  ECBUS_RX_ECBUS_BIST_CTRL_lq_inv(data)                                   (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_BIST_CTRL_gx_inv(data)                                   (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_BIST_CTRL_bist_out_swap(data)                            (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_BIST_CTRL_ecbus_bist_en(data)                            (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_BIST_CTRL_bist_err_reset(data)                           (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_BIST_CTRL_prbs_reset(data)                               (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_BIST_CTRL_bist_comp_start(data)                          (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_BIST_CTRL_rx_bist_stop(data)                             (0x00000001&(data))
#define  ECBUS_RX_ECBUS_BIST_CTRL_get_lq_inv(data)                               ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_BIST_CTRL_get_gx_inv(data)                               ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_BIST_CTRL_get_bist_out_swap(data)                        ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_BIST_CTRL_get_ecbus_bist_en(data)                        ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_BIST_CTRL_get_bist_err_reset(data)                       ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_BIST_CTRL_get_prbs_reset(data)                           ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_BIST_CTRL_get_bist_comp_start(data)                      ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_BIST_CTRL_get_rx_bist_stop(data)                         (0x00000001&(data))

#define  ECBUS_RX_ECBUS_BIST_CONFIG                                              0x1800A5D4
#define  ECBUS_RX_ECBUS_BIST_CONFIG_reg_addr                                     "0xB800A5D4"
#define  ECBUS_RX_ECBUS_BIST_CONFIG_reg                                          0xB800A5D4
#define  ECBUS_RX_ECBUS_BIST_CONFIG_inst_addr                                    "0x0035"
#define  set_ECBUS_RX_ECBUS_BIST_CONFIG_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_CONFIG_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_CONFIG_reg                                      (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_CONFIG_reg))
#define  ECBUS_RX_ECBUS_BIST_CONFIG_tx_bist_shift                                (7)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_rx_bist_shift                                (6)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_bist_rx_debounce_shift                       (4)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_bist_pattern_shift                           (3)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_fix8_alter_shift                             (2)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_bist_err_sel_shift                           (1)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_prbs_gen_sel_shift                           (0)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_tx_bist_mask                                 (0x00000080)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_rx_bist_mask                                 (0x00000040)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_bist_rx_debounce_mask                        (0x00000030)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_bist_pattern_mask                            (0x00000008)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_fix8_alter_mask                              (0x00000004)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_bist_err_sel_mask                            (0x00000002)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_prbs_gen_sel_mask                            (0x00000001)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_tx_bist(data)                                (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_BIST_CONFIG_rx_bist(data)                                (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_BIST_CONFIG_bist_rx_debounce(data)                       (0x00000030&((data)<<4))
#define  ECBUS_RX_ECBUS_BIST_CONFIG_bist_pattern(data)                           (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_BIST_CONFIG_fix8_alter(data)                             (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_BIST_CONFIG_bist_err_sel(data)                           (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_BIST_CONFIG_prbs_gen_sel(data)                           (0x00000001&(data))
#define  ECBUS_RX_ECBUS_BIST_CONFIG_get_tx_bist(data)                            ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_get_rx_bist(data)                            ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_get_bist_rx_debounce(data)                   ((0x00000030&(data))>>4)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_get_bist_pattern(data)                       ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_get_fix8_alter(data)                         ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_get_bist_err_sel(data)                       ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_BIST_CONFIG_get_prbs_gen_sel(data)                       (0x00000001&(data))

#define  ECBUS_RX_ECBUS_BIST_FIXED8                                              0x1800A5D8
#define  ECBUS_RX_ECBUS_BIST_FIXED8_reg_addr                                     "0xB800A5D8"
#define  ECBUS_RX_ECBUS_BIST_FIXED8_reg                                          0xB800A5D8
#define  ECBUS_RX_ECBUS_BIST_FIXED8_inst_addr                                    "0x0036"
#define  set_ECBUS_RX_ECBUS_BIST_FIXED8_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_FIXED8_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_FIXED8_reg                                      (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_FIXED8_reg))
#define  ECBUS_RX_ECBUS_BIST_FIXED8_fix8_data_shift                              (0)
#define  ECBUS_RX_ECBUS_BIST_FIXED8_fix8_data_mask                               (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_FIXED8_fix8_data(data)                              (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_FIXED8_get_fix8_data(data)                          (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_BIST_RX_INIT                                             0x1800A5DC
#define  ECBUS_RX_ECBUS_BIST_RX_INIT_reg_addr                                    "0xB800A5DC"
#define  ECBUS_RX_ECBUS_BIST_RX_INIT_reg                                         0xB800A5DC
#define  ECBUS_RX_ECBUS_BIST_RX_INIT_inst_addr                                   "0x0037"
#define  set_ECBUS_RX_ECBUS_BIST_RX_INIT_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_RX_INIT_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_RX_INIT_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_RX_INIT_reg))
#define  ECBUS_RX_ECBUS_BIST_RX_INIT_bist_rx_ini_shift                           (0)
#define  ECBUS_RX_ECBUS_BIST_RX_INIT_bist_rx_ini_mask                            (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_RX_INIT_bist_rx_ini(data)                           (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_RX_INIT_get_bist_rx_ini(data)                       (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_BIST_TX_INIT                                             0x1800A5E0
#define  ECBUS_RX_ECBUS_BIST_TX_INIT_reg_addr                                    "0xB800A5E0"
#define  ECBUS_RX_ECBUS_BIST_TX_INIT_reg                                         0xB800A5E0
#define  ECBUS_RX_ECBUS_BIST_TX_INIT_inst_addr                                   "0x0038"
#define  set_ECBUS_RX_ECBUS_BIST_TX_INIT_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_TX_INIT_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_TX_INIT_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_TX_INIT_reg))
#define  ECBUS_RX_ECBUS_BIST_TX_INIT_bist_tx_ini_shift                           (0)
#define  ECBUS_RX_ECBUS_BIST_TX_INIT_bist_tx_ini_mask                            (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_TX_INIT_bist_tx_ini(data)                           (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_TX_INIT_get_bist_tx_ini(data)                       (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_H                                           0x1800A5E4
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_H_reg_addr                                  "0xB800A5E4"
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_H_reg                                       0xB800A5E4
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_H_inst_addr                                 "0x0039"
#define  set_ECBUS_RX_ECBUS_BIST_ERR_CNT_H_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_ERR_CNT_H_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_ERR_CNT_H_reg                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_ERR_CNT_H_reg))
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_H_bist_err_cnt_15_8_shift                   (0)
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_H_bist_err_cnt_15_8_mask                    (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_H_bist_err_cnt_15_8(data)                   (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_H_get_bist_err_cnt_15_8(data)               (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_L                                           0x1800A5E8
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_L_reg_addr                                  "0xB800A5E8"
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_L_reg                                       0xB800A5E8
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_L_inst_addr                                 "0x003A"
#define  set_ECBUS_RX_ECBUS_BIST_ERR_CNT_L_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_ERR_CNT_L_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_ERR_CNT_L_reg                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_ERR_CNT_L_reg))
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_L_bist_err_cnt_7_0_shift                    (0)
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_L_bist_err_cnt_7_0_mask                     (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_L_bist_err_cnt_7_0(data)                    (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_ERR_CNT_L_get_bist_err_cnt_7_0(data)                (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_BIST_RESERVE                                             0x1800A5EC
#define  ECBUS_RX_ECBUS_BIST_RESERVE_reg_addr                                    "0xB800A5EC"
#define  ECBUS_RX_ECBUS_BIST_RESERVE_reg                                         0xB800A5EC
#define  ECBUS_RX_ECBUS_BIST_RESERVE_inst_addr                                   "0x003B"
#define  set_ECBUS_RX_ECBUS_BIST_RESERVE_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_RESERVE_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_RESERVE_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_RESERVE_reg))
#define  ECBUS_RX_ECBUS_BIST_RESERVE_prbs_coef_shift                             (0)
#define  ECBUS_RX_ECBUS_BIST_RESERVE_prbs_coef_mask                              (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_RESERVE_prbs_coef(data)                             (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_RESERVE_get_prbs_coef(data)                         (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_SRAM_BIST                                                0x1800A5F0
#define  ECBUS_RX_ECBUS_SRAM_BIST_reg_addr                                       "0xB800A5F0"
#define  ECBUS_RX_ECBUS_SRAM_BIST_reg                                            0xB800A5F0
#define  ECBUS_RX_ECBUS_SRAM_BIST_inst_addr                                      "0x003C"
#define  set_ECBUS_RX_ECBUS_SRAM_BIST_reg(data)                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_SRAM_BIST_reg)=data)
#define  get_ECBUS_RX_ECBUS_SRAM_BIST_reg                                        (*((volatile unsigned int*)ECBUS_RX_ECBUS_SRAM_BIST_reg))
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_mode_shift                                (7)
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_done_shift                                (6)
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_fail_0_shift                              (5)
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_fail_1_shift                              (4)
#define  ECBUS_RX_ECBUS_SRAM_BIST_dummy_3_0_shift                                (0)
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_mode_mask                                 (0x00000080)
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_done_mask                                 (0x00000040)
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_fail_0_mask                               (0x00000020)
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_fail_1_mask                               (0x00000010)
#define  ECBUS_RX_ECBUS_SRAM_BIST_dummy_3_0_mask                                 (0x0000000F)
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_mode(data)                                (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_done(data)                                (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_fail_0(data)                              (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_SRAM_BIST_bist_fail_1(data)                              (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_SRAM_BIST_dummy_3_0(data)                                (0x0000000F&(data))
#define  ECBUS_RX_ECBUS_SRAM_BIST_get_bist_mode(data)                            ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_SRAM_BIST_get_bist_done(data)                            ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_SRAM_BIST_get_bist_fail_0(data)                          ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_SRAM_BIST_get_bist_fail_1(data)                          ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_SRAM_BIST_get_dummy_3_0(data)                            (0x0000000F&(data))

#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST                                            0x1800A5F4
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_reg_addr                                   "0xB800A5F4"
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_reg                                        0xB800A5F4
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_inst_addr                                  "0x003D"
#define  set_ECBUS_RX_ECBUS_SRAM_DRF_BIST_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_SRAM_DRF_BIST_reg)=data)
#define  get_ECBUS_RX_ECBUS_SRAM_DRF_BIST_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_SRAM_DRF_BIST_reg))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_ls_0_shift                                 (19)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_ls_1_shift                                 (18)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rme_0_shift                                (17)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rme_1_shift                                (16)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rm_0_shift                                 (12)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rm_1_shift                                 (8)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_mode_shift                        (7)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_test_resume_shift                      (6)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_start_pause_shift                      (5)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_done_shift                        (4)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_fail_0_shift                      (3)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_fail_1_shift                      (2)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_dummy_1_0_shift                            (0)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_ls_0_mask                                  (0x00080000)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_ls_1_mask                                  (0x00040000)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rme_0_mask                                 (0x00020000)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rme_1_mask                                 (0x00010000)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rm_0_mask                                  (0x0000F000)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rm_1_mask                                  (0x00000F00)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_mode_mask                         (0x00000080)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_test_resume_mask                       (0x00000040)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_start_pause_mask                       (0x00000020)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_done_mask                         (0x00000010)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_fail_0_mask                       (0x00000008)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_fail_1_mask                       (0x00000004)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_dummy_1_0_mask                             (0x00000003)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_ls_0(data)                                 (0x00080000&((data)<<19))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_ls_1(data)                                 (0x00040000&((data)<<18))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rme_0(data)                                (0x00020000&((data)<<17))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rme_1(data)                                (0x00010000&((data)<<16))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rm_0(data)                                 (0x0000F000&((data)<<12))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_rm_1(data)                                 (0x00000F00&((data)<<8))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_mode(data)                        (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_test_resume(data)                      (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_start_pause(data)                      (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_done(data)                        (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_fail_0(data)                      (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_drf_bist_fail_1(data)                      (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_dummy_1_0(data)                            (0x00000003&(data))
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_ls_0(data)                             ((0x00080000&(data))>>19)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_ls_1(data)                             ((0x00040000&(data))>>18)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_rme_0(data)                            ((0x00020000&(data))>>17)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_rme_1(data)                            ((0x00010000&(data))>>16)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_rm_0(data)                             ((0x0000F000&(data))>>12)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_rm_1(data)                             ((0x00000F00&(data))>>8)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_drf_bist_mode(data)                    ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_drf_test_resume(data)                  ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_drf_start_pause(data)                  ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_drf_bist_done(data)                    ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_drf_bist_fail_0(data)                  ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_drf_bist_fail_1(data)                  ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_SRAM_DRF_BIST_get_dummy_1_0(data)                        (0x00000003&(data))

#define  ECBUS_RX_ECBUS_GLOBAL_CTRL                                              0x1800A5F8
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_reg_addr                                     "0xB800A5F8"
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_reg                                          0xB800A5F8
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_inst_addr                                    "0x003E"
#define  set_ECBUS_RX_ECBUS_GLOBAL_CTRL_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_ECBUS_GLOBAL_CTRL_reg)=data)
#define  get_ECBUS_RX_ECBUS_GLOBAL_CTRL_reg                                      (*((volatile unsigned int*)ECBUS_RX_ECBUS_GLOBAL_CTRL_reg))
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_dummy_7_shift                                (7)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_cbus1_crc_opt_shift                          (6)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_tby_crc_opt_shift                            (5)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_out_swap_shift                           (4)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_not_inv_shift                            (3)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_in_swap_shift                            (2)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_ignore_shift                             (1)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_sel_fw_shift                             (0)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_dummy_7_mask                                 (0x00000080)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_cbus1_crc_opt_mask                           (0x00000040)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_tby_crc_opt_mask                             (0x00000020)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_out_swap_mask                            (0x00000010)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_not_inv_mask                             (0x00000008)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_in_swap_mask                             (0x00000004)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_ignore_mask                              (0x00000002)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_sel_fw_mask                              (0x00000001)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_dummy_7(data)                                (0x00000080&((data)<<7))
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_cbus1_crc_opt(data)                          (0x00000040&((data)<<6))
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_tby_crc_opt(data)                            (0x00000020&((data)<<5))
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_out_swap(data)                           (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_not_inv(data)                            (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_in_swap(data)                            (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_ignore(data)                             (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_crc_sel_fw(data)                             (0x00000001&(data))
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_get_dummy_7(data)                            ((0x00000080&(data))>>7)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_get_cbus1_crc_opt(data)                      ((0x00000040&(data))>>6)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_get_tby_crc_opt(data)                        ((0x00000020&(data))>>5)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_get_crc_out_swap(data)                       ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_get_crc_not_inv(data)                        ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_get_crc_in_swap(data)                        ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_get_crc_ignore(data)                         ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_GLOBAL_CTRL_get_crc_sel_fw(data)                         (0x00000001&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B0_H                                              0x1800A5FC
#define  ECBUS_RX_CBUS1_FW_CRC_B0_H_reg_addr                                     "0xB800A5FC"
#define  ECBUS_RX_CBUS1_FW_CRC_B0_H_reg                                          0xB800A5FC
#define  ECBUS_RX_CBUS1_FW_CRC_B0_H_inst_addr                                    "0x003F"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B0_H_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B0_H_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B0_H_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B0_H_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B0_H_cbus1_b0_coef_h_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B0_H_cbus1_b0_coef_h_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B0_H_cbus1_b0_coef_h(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B0_H_get_cbus1_b0_coef_h(data)                    (0x000000FF&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B0_L                                              0x1800A600
#define  ECBUS_RX_CBUS1_FW_CRC_B0_L_reg_addr                                     "0xB800A600"
#define  ECBUS_RX_CBUS1_FW_CRC_B0_L_reg                                          0xB800A600
#define  ECBUS_RX_CBUS1_FW_CRC_B0_L_inst_addr                                    "0x0040"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B0_L_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B0_L_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B0_L_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B0_L_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B0_L_cbus1_b0_coef_l_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B0_L_cbus1_b0_coef_l_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B0_L_cbus1_b0_coef_l(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B0_L_get_cbus1_b0_coef_l(data)                    (0x000000FF&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B1_H                                              0x1800A604
#define  ECBUS_RX_CBUS1_FW_CRC_B1_H_reg_addr                                     "0xB800A604"
#define  ECBUS_RX_CBUS1_FW_CRC_B1_H_reg                                          0xB800A604
#define  ECBUS_RX_CBUS1_FW_CRC_B1_H_inst_addr                                    "0x0041"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B1_H_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B1_H_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B1_H_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B1_H_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B1_H_cbus1_b1_coef_h_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B1_H_cbus1_b1_coef_h_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B1_H_cbus1_b1_coef_h(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B1_H_get_cbus1_b1_coef_h(data)                    (0x000000FF&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B1_L                                              0x1800A608
#define  ECBUS_RX_CBUS1_FW_CRC_B1_L_reg_addr                                     "0xB800A608"
#define  ECBUS_RX_CBUS1_FW_CRC_B1_L_reg                                          0xB800A608
#define  ECBUS_RX_CBUS1_FW_CRC_B1_L_inst_addr                                    "0x0042"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B1_L_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B1_L_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B1_L_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B1_L_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B1_L_cbus1_b1_coef_l_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B1_L_cbus1_b1_coef_l_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B1_L_cbus1_b1_coef_l(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B1_L_get_cbus1_b1_coef_l(data)                    (0x000000FF&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B2_H                                              0x1800A60C
#define  ECBUS_RX_CBUS1_FW_CRC_B2_H_reg_addr                                     "0xB800A60C"
#define  ECBUS_RX_CBUS1_FW_CRC_B2_H_reg                                          0xB800A60C
#define  ECBUS_RX_CBUS1_FW_CRC_B2_H_inst_addr                                    "0x0043"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B2_H_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B2_H_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B2_H_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B2_H_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B2_H_cbus1_b2_coef_h_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B2_H_cbus1_b2_coef_h_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B2_H_cbus1_b2_coef_h(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B2_H_get_cbus1_b2_coef_h(data)                    (0x000000FF&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B2_L                                              0x1800A610
#define  ECBUS_RX_CBUS1_FW_CRC_B2_L_reg_addr                                     "0xB800A610"
#define  ECBUS_RX_CBUS1_FW_CRC_B2_L_reg                                          0xB800A610
#define  ECBUS_RX_CBUS1_FW_CRC_B2_L_inst_addr                                    "0x0044"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B2_L_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B2_L_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B2_L_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B2_L_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B2_L_cbus1_b2_coef_l_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B2_L_cbus1_b2_coef_l_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B2_L_cbus1_b2_coef_l(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B2_L_get_cbus1_b2_coef_l(data)                    (0x000000FF&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B3_H                                              0x1800A614
#define  ECBUS_RX_CBUS1_FW_CRC_B3_H_reg_addr                                     "0xB800A614"
#define  ECBUS_RX_CBUS1_FW_CRC_B3_H_reg                                          0xB800A614
#define  ECBUS_RX_CBUS1_FW_CRC_B3_H_inst_addr                                    "0x0045"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B3_H_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B3_H_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B3_H_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B3_H_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B3_H_cbus1_b3_coef_h_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B3_H_cbus1_b3_coef_h_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B3_H_cbus1_b3_coef_h(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B3_H_get_cbus1_b3_coef_h(data)                    (0x000000FF&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B3_L                                              0x1800A618
#define  ECBUS_RX_CBUS1_FW_CRC_B3_L_reg_addr                                     "0xB800A618"
#define  ECBUS_RX_CBUS1_FW_CRC_B3_L_reg                                          0xB800A618
#define  ECBUS_RX_CBUS1_FW_CRC_B3_L_inst_addr                                    "0x0046"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B3_L_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B3_L_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B3_L_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B3_L_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B3_L_cbus1_b3_coef_l_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B3_L_cbus1_b3_coef_l_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B3_L_cbus1_b3_coef_l(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B3_L_get_cbus1_b3_coef_l(data)                    (0x000000FF&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B4_H                                              0x1800A61C
#define  ECBUS_RX_CBUS1_FW_CRC_B4_H_reg_addr                                     "0xB800A61C"
#define  ECBUS_RX_CBUS1_FW_CRC_B4_H_reg                                          0xB800A61C
#define  ECBUS_RX_CBUS1_FW_CRC_B4_H_inst_addr                                    "0x0047"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B4_H_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B4_H_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B4_H_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B4_H_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B4_H_cbus1_b4_coef_h_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B4_H_cbus1_b4_coef_h_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B4_H_cbus1_b4_coef_h(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B4_H_get_cbus1_b4_coef_h(data)                    (0x000000FF&(data))

#define  ECBUS_RX_CBUS1_FW_CRC_B4_L                                              0x1800A620
#define  ECBUS_RX_CBUS1_FW_CRC_B4_L_reg_addr                                     "0xB800A620"
#define  ECBUS_RX_CBUS1_FW_CRC_B4_L_reg                                          0xB800A620
#define  ECBUS_RX_CBUS1_FW_CRC_B4_L_inst_addr                                    "0x0048"
#define  set_ECBUS_RX_CBUS1_FW_CRC_B4_L_reg(data)                                (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B4_L_reg)=data)
#define  get_ECBUS_RX_CBUS1_FW_CRC_B4_L_reg                                      (*((volatile unsigned int*)ECBUS_RX_CBUS1_FW_CRC_B4_L_reg))
#define  ECBUS_RX_CBUS1_FW_CRC_B4_L_cbus1_b4_coef_l_shift                        (0)
#define  ECBUS_RX_CBUS1_FW_CRC_B4_L_cbus1_b4_coef_l_mask                         (0x000000FF)
#define  ECBUS_RX_CBUS1_FW_CRC_B4_L_cbus1_b4_coef_l(data)                        (0x000000FF&(data))
#define  ECBUS_RX_CBUS1_FW_CRC_B4_L_get_cbus1_b4_coef_l(data)                    (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1                                             0x1800A624
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_reg_addr                                    "0xB800A624"
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_reg                                         0xB800A624
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_inst_addr                                   "0x0049"
#define  set_ECBUS_RX_ECBUS_TIMEOUT_CLK1_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_TIMEOUT_CLK1_reg)=data)
#define  get_ECBUS_RX_ECBUS_TIMEOUT_CLK1_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_TIMEOUT_CLK1_reg))
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_clk_1m_div_shift                            (4)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_dummy_3_2_shift                             (2)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_clk_1k_div_9_8_shift                        (0)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_clk_1m_div_mask                             (0x000000F0)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_dummy_3_2_mask                              (0x0000000C)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_clk_1k_div_9_8_mask                         (0x00000003)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_clk_1m_div(data)                            (0x000000F0&((data)<<4))
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_dummy_3_2(data)                             (0x0000000C&((data)<<2))
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_clk_1k_div_9_8(data)                        (0x00000003&(data))
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_get_clk_1m_div(data)                        ((0x000000F0&(data))>>4)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_get_dummy_3_2(data)                         ((0x0000000C&(data))>>2)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK1_get_clk_1k_div_9_8(data)                    (0x00000003&(data))

#define  ECBUS_RX_ECBUS_TIMEOUT_CLK2                                             0x1800A628
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK2_reg_addr                                    "0xB800A628"
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK2_reg                                         0xB800A628
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK2_inst_addr                                   "0x004A"
#define  set_ECBUS_RX_ECBUS_TIMEOUT_CLK2_reg(data)                               (*((volatile unsigned int*)ECBUS_RX_ECBUS_TIMEOUT_CLK2_reg)=data)
#define  get_ECBUS_RX_ECBUS_TIMEOUT_CLK2_reg                                     (*((volatile unsigned int*)ECBUS_RX_ECBUS_TIMEOUT_CLK2_reg))
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK2_clk_1k_div_7_0_shift                        (0)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK2_clk_1k_div_7_0_mask                         (0x000000FF)
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK2_clk_1k_div_7_0(data)                        (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_TIMEOUT_CLK2_get_clk_1k_div_7_0(data)                    (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_TIMEOUT_RESERVE                                          0x1800A62C
#define  ECBUS_RX_ECBUS_TIMEOUT_RESERVE_reg_addr                                 "0xB800A62C"
#define  ECBUS_RX_ECBUS_TIMEOUT_RESERVE_reg                                      0xB800A62C
#define  ECBUS_RX_ECBUS_TIMEOUT_RESERVE_inst_addr                                "0x004B"
#define  set_ECBUS_RX_ECBUS_TIMEOUT_RESERVE_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_TIMEOUT_RESERVE_reg)=data)
#define  get_ECBUS_RX_ECBUS_TIMEOUT_RESERVE_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_TIMEOUT_RESERVE_reg))
#define  ECBUS_RX_ECBUS_TIMEOUT_RESERVE_dummy_7_0_shift                          (0)
#define  ECBUS_RX_ECBUS_TIMEOUT_RESERVE_dummy_7_0_mask                           (0x000000FF)
#define  ECBUS_RX_ECBUS_TIMEOUT_RESERVE_dummy_7_0(data)                          (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_TIMEOUT_RESERVE_get_dummy_7_0(data)                      (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_HW_FSM_1                                                 0x1800A630
#define  ECBUS_RX_ECBUS_HW_FSM_1_reg_addr                                        "0xB800A630"
#define  ECBUS_RX_ECBUS_HW_FSM_1_reg                                             0xB800A630
#define  ECBUS_RX_ECBUS_HW_FSM_1_inst_addr                                       "0x004C"
#define  set_ECBUS_RX_ECBUS_HW_FSM_1_reg(data)                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_HW_FSM_1_reg                                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_1_reg))
#define  ECBUS_RX_ECBUS_HW_FSM_1_ecbus_st_shift                                  (0)
#define  ECBUS_RX_ECBUS_HW_FSM_1_ecbus_st_mask                                   (0x000000FF)
#define  ECBUS_RX_ECBUS_HW_FSM_1_ecbus_st(data)                                  (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_HW_FSM_1_get_ecbus_st(data)                              (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_HW_FSM_2                                                 0x1800A634
#define  ECBUS_RX_ECBUS_HW_FSM_2_reg_addr                                        "0xB800A634"
#define  ECBUS_RX_ECBUS_HW_FSM_2_reg                                             0xB800A634
#define  ECBUS_RX_ECBUS_HW_FSM_2_inst_addr                                       "0x004D"
#define  set_ECBUS_RX_ECBUS_HW_FSM_2_reg(data)                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_HW_FSM_2_reg                                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_2_reg))
#define  ECBUS_RX_ECBUS_HW_FSM_2_cbus1_st_shift                                  (0)
#define  ECBUS_RX_ECBUS_HW_FSM_2_cbus1_st_mask                                   (0x000000FF)
#define  ECBUS_RX_ECBUS_HW_FSM_2_cbus1_st(data)                                  (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_HW_FSM_2_get_cbus1_st(data)                              (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_HW_FSM_3                                                 0x1800A638
#define  ECBUS_RX_ECBUS_HW_FSM_3_reg_addr                                        "0xB800A638"
#define  ECBUS_RX_ECBUS_HW_FSM_3_reg                                             0xB800A638
#define  ECBUS_RX_ECBUS_HW_FSM_3_inst_addr                                       "0x004E"
#define  set_ECBUS_RX_ECBUS_HW_FSM_3_reg(data)                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_3_reg)=data)
#define  get_ECBUS_RX_ECBUS_HW_FSM_3_reg                                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_3_reg))
#define  ECBUS_RX_ECBUS_HW_FSM_3_emsc_st_3_0_shift                               (4)
#define  ECBUS_RX_ECBUS_HW_FSM_3_dummy_3_shift                                   (3)
#define  ECBUS_RX_ECBUS_HW_FSM_3_emsc_tx_st_10_8_shift                           (0)
#define  ECBUS_RX_ECBUS_HW_FSM_3_emsc_st_3_0_mask                                (0x000000F0)
#define  ECBUS_RX_ECBUS_HW_FSM_3_dummy_3_mask                                    (0x00000008)
#define  ECBUS_RX_ECBUS_HW_FSM_3_emsc_tx_st_10_8_mask                            (0x00000007)
#define  ECBUS_RX_ECBUS_HW_FSM_3_emsc_st_3_0(data)                               (0x000000F0&((data)<<4))
#define  ECBUS_RX_ECBUS_HW_FSM_3_dummy_3(data)                                   (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_HW_FSM_3_emsc_tx_st_10_8(data)                           (0x00000007&(data))
#define  ECBUS_RX_ECBUS_HW_FSM_3_get_emsc_st_3_0(data)                           ((0x000000F0&(data))>>4)
#define  ECBUS_RX_ECBUS_HW_FSM_3_get_dummy_3(data)                               ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_HW_FSM_3_get_emsc_tx_st_10_8(data)                       (0x00000007&(data))

#define  ECBUS_RX_ECBUS_HW_FSM_4                                                 0x1800A63C
#define  ECBUS_RX_ECBUS_HW_FSM_4_reg_addr                                        "0xB800A63C"
#define  ECBUS_RX_ECBUS_HW_FSM_4_reg                                             0xB800A63C
#define  ECBUS_RX_ECBUS_HW_FSM_4_inst_addr                                       "0x004F"
#define  set_ECBUS_RX_ECBUS_HW_FSM_4_reg(data)                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_4_reg)=data)
#define  get_ECBUS_RX_ECBUS_HW_FSM_4_reg                                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_4_reg))
#define  ECBUS_RX_ECBUS_HW_FSM_4_emsc_tx_st_7_0_shift                            (0)
#define  ECBUS_RX_ECBUS_HW_FSM_4_emsc_tx_st_7_0_mask                             (0x000000FF)
#define  ECBUS_RX_ECBUS_HW_FSM_4_emsc_tx_st_7_0(data)                            (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_HW_FSM_4_get_emsc_tx_st_7_0(data)                        (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_HW_FSM_5                                                 0x1800A640
#define  ECBUS_RX_ECBUS_HW_FSM_5_reg_addr                                        "0xB800A640"
#define  ECBUS_RX_ECBUS_HW_FSM_5_reg                                             0xB800A640
#define  ECBUS_RX_ECBUS_HW_FSM_5_inst_addr                                       "0x0050"
#define  set_ECBUS_RX_ECBUS_HW_FSM_5_reg(data)                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_5_reg)=data)
#define  get_ECBUS_RX_ECBUS_HW_FSM_5_reg                                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_5_reg))
#define  ECBUS_RX_ECBUS_HW_FSM_5_dummy_7_2_shift                                 (2)
#define  ECBUS_RX_ECBUS_HW_FSM_5_emsc_rx_st_9_8_shift                            (0)
#define  ECBUS_RX_ECBUS_HW_FSM_5_dummy_7_2_mask                                  (0x000000FC)
#define  ECBUS_RX_ECBUS_HW_FSM_5_emsc_rx_st_9_8_mask                             (0x00000003)
#define  ECBUS_RX_ECBUS_HW_FSM_5_dummy_7_2(data)                                 (0x000000FC&((data)<<2))
#define  ECBUS_RX_ECBUS_HW_FSM_5_emsc_rx_st_9_8(data)                            (0x00000003&(data))
#define  ECBUS_RX_ECBUS_HW_FSM_5_get_dummy_7_2(data)                             ((0x000000FC&(data))>>2)
#define  ECBUS_RX_ECBUS_HW_FSM_5_get_emsc_rx_st_9_8(data)                        (0x00000003&(data))

#define  ECBUS_RX_ECBUS_HW_FSM_6                                                 0x1800A644
#define  ECBUS_RX_ECBUS_HW_FSM_6_reg_addr                                        "0xB800A644"
#define  ECBUS_RX_ECBUS_HW_FSM_6_reg                                             0xB800A644
#define  ECBUS_RX_ECBUS_HW_FSM_6_inst_addr                                       "0x0051"
#define  set_ECBUS_RX_ECBUS_HW_FSM_6_reg(data)                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_6_reg)=data)
#define  get_ECBUS_RX_ECBUS_HW_FSM_6_reg                                         (*((volatile unsigned int*)ECBUS_RX_ECBUS_HW_FSM_6_reg))
#define  ECBUS_RX_ECBUS_HW_FSM_6_emsc_rx_st_7_0_shift                            (0)
#define  ECBUS_RX_ECBUS_HW_FSM_6_emsc_rx_st_7_0_mask                             (0x000000FF)
#define  ECBUS_RX_ECBUS_HW_FSM_6_emsc_rx_st_7_0(data)                            (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_HW_FSM_6_get_emsc_rx_st_7_0(data)                        (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT                                           0x1800A648
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_reg_addr                                  "0xB800A648"
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_reg                                       0xB800A648
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_inst_addr                                 "0x0052"
#define  set_ECBUS_RX_ECBUS_TEST_FORCE_OUT_reg(data)                             (*((volatile unsigned int*)ECBUS_RX_ECBUS_TEST_FORCE_OUT_reg)=data)
#define  get_ECBUS_RX_ECBUS_TEST_FORCE_OUT_reg                                   (*((volatile unsigned int*)ECBUS_RX_ECBUS_TEST_FORCE_OUT_reg))
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_ecbus_tst_sel_shift                       (4)
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_force_testout_en_shift                    (3)
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_force_testout_sel_shift                   (0)
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_ecbus_tst_sel_mask                        (0x000000F0)
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_force_testout_en_mask                     (0x00000008)
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_force_testout_sel_mask                    (0x00000007)
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_ecbus_tst_sel(data)                       (0x000000F0&((data)<<4))
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_force_testout_en(data)                    (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_force_testout_sel(data)                   (0x00000007&(data))
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_get_ecbus_tst_sel(data)                   ((0x000000F0&(data))>>4)
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_get_force_testout_en(data)                ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_TEST_FORCE_OUT_get_force_testout_sel(data)               (0x00000007&(data))

#define  ECBUS_RX_ECBUS_TESTOUT_RESERVE                                          0x1800A64C
#define  ECBUS_RX_ECBUS_TESTOUT_RESERVE_reg_addr                                 "0xB800A64C"
#define  ECBUS_RX_ECBUS_TESTOUT_RESERVE_reg                                      0xB800A64C
#define  ECBUS_RX_ECBUS_TESTOUT_RESERVE_inst_addr                                "0x0053"
#define  set_ECBUS_RX_ECBUS_TESTOUT_RESERVE_reg(data)                            (*((volatile unsigned int*)ECBUS_RX_ECBUS_TESTOUT_RESERVE_reg)=data)
#define  get_ECBUS_RX_ECBUS_TESTOUT_RESERVE_reg                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_TESTOUT_RESERVE_reg))
#define  ECBUS_RX_ECBUS_TESTOUT_RESERVE_dummy_7_0_shift                          (0)
#define  ECBUS_RX_ECBUS_TESTOUT_RESERVE_dummy_7_0_mask                           (0x000000FF)
#define  ECBUS_RX_ECBUS_TESTOUT_RESERVE_dummy_7_0(data)                          (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_TESTOUT_RESERVE_get_dummy_7_0(data)                      (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_BIST_OPTION_0                                            0x1800A650
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_reg_addr                                   "0xB800A650"
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_reg                                        0xB800A650
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_inst_addr                                  "0x0054"
#define  set_ECBUS_RX_ECBUS_BIST_OPTION_0_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_0_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_OPTION_0_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_0_reg))
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_dummy_7_5_shift                            (5)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_bist_10b_ini_calcu_shift                   (4)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_bist_10b_en_shift                          (3)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_tx_disp_ini_inv_shift                      (2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_force_start_num_shift                      (1)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_start_odd_shift                            (0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_dummy_7_5_mask                             (0x000000E0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_bist_10b_ini_calcu_mask                    (0x00000010)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_bist_10b_en_mask                           (0x00000008)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_tx_disp_ini_inv_mask                       (0x00000004)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_force_start_num_mask                       (0x00000002)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_start_odd_mask                             (0x00000001)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_dummy_7_5(data)                            (0x000000E0&((data)<<5))
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_bist_10b_ini_calcu(data)                   (0x00000010&((data)<<4))
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_bist_10b_en(data)                          (0x00000008&((data)<<3))
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_tx_disp_ini_inv(data)                      (0x00000004&((data)<<2))
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_force_start_num(data)                      (0x00000002&((data)<<1))
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_start_odd(data)                            (0x00000001&(data))
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_get_dummy_7_5(data)                        ((0x000000E0&(data))>>5)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_get_bist_10b_ini_calcu(data)               ((0x00000010&(data))>>4)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_get_bist_10b_en(data)                      ((0x00000008&(data))>>3)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_get_tx_disp_ini_inv(data)                  ((0x00000004&(data))>>2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_get_force_start_num(data)                  ((0x00000002&(data))>>1)
#define  ECBUS_RX_ECBUS_BIST_OPTION_0_get_start_odd(data)                        (0x00000001&(data))

#define  ECBUS_RX_ECBUS_BIST_OPTION_1                                            0x1800A654
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_reg_addr                                   "0xB800A654"
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_reg                                        0xB800A654
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_inst_addr                                  "0x0055"
#define  set_ECBUS_RX_ECBUS_BIST_OPTION_1_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_OPTION_1_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_1_reg))
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_dummy_7_2_shift                            (2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_reg_bist_8b10b_ini_out_1_9_8_shift         (0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_dummy_7_2_mask                             (0x000000FC)
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_reg_bist_8b10b_ini_out_1_9_8_mask          (0x00000003)
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_dummy_7_2(data)                            (0x000000FC&((data)<<2))
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_reg_bist_8b10b_ini_out_1_9_8(data)         (0x00000003&(data))
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_get_dummy_7_2(data)                        ((0x000000FC&(data))>>2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_1_get_reg_bist_8b10b_ini_out_1_9_8(data)     (0x00000003&(data))

#define  ECBUS_RX_ECBUS_BIST_OPTION_2                                            0x1800A658
#define  ECBUS_RX_ECBUS_BIST_OPTION_2_reg_addr                                   "0xB800A658"
#define  ECBUS_RX_ECBUS_BIST_OPTION_2_reg                                        0xB800A658
#define  ECBUS_RX_ECBUS_BIST_OPTION_2_inst_addr                                  "0x0056"
#define  set_ECBUS_RX_ECBUS_BIST_OPTION_2_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_OPTION_2_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_2_reg))
#define  ECBUS_RX_ECBUS_BIST_OPTION_2_reg_bist_8b10b_ini_out_1_7_0_shift         (0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_2_reg_bist_8b10b_ini_out_1_7_0_mask          (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_OPTION_2_reg_bist_8b10b_ini_out_1_7_0(data)         (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_OPTION_2_get_reg_bist_8b10b_ini_out_1_7_0(data)     (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_BIST_OPTION_3                                            0x1800A65C
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_reg_addr                                   "0xB800A65C"
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_reg                                        0xB800A65C
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_inst_addr                                  "0x0057"
#define  set_ECBUS_RX_ECBUS_BIST_OPTION_3_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_3_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_OPTION_3_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_3_reg))
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_dummy_7_2_shift                            (2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_reg_bist_8b10b_ini_out_0_9_8_shift         (0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_dummy_7_2_mask                             (0x000000FC)
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_reg_bist_8b10b_ini_out_0_9_8_mask          (0x00000003)
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_dummy_7_2(data)                            (0x000000FC&((data)<<2))
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_reg_bist_8b10b_ini_out_0_9_8(data)         (0x00000003&(data))
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_get_dummy_7_2(data)                        ((0x000000FC&(data))>>2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_3_get_reg_bist_8b10b_ini_out_0_9_8(data)     (0x00000003&(data))

#define  ECBUS_RX_ECBUS_BIST_OPTION_4                                            0x1800A660
#define  ECBUS_RX_ECBUS_BIST_OPTION_4_reg_addr                                   "0xB800A660"
#define  ECBUS_RX_ECBUS_BIST_OPTION_4_reg                                        0xB800A660
#define  ECBUS_RX_ECBUS_BIST_OPTION_4_inst_addr                                  "0x0058"
#define  set_ECBUS_RX_ECBUS_BIST_OPTION_4_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_4_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_OPTION_4_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_4_reg))
#define  ECBUS_RX_ECBUS_BIST_OPTION_4_reg_bist_8b10b_ini_out_0_7_0_shift         (0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_4_reg_bist_8b10b_ini_out_0_7_0_mask          (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_OPTION_4_reg_bist_8b10b_ini_out_0_7_0(data)         (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_OPTION_4_get_reg_bist_8b10b_ini_out_0_7_0(data)     (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_BIST_OPTION_5                                            0x1800A664
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_reg_addr                                   "0xB800A664"
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_reg                                        0xB800A664
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_inst_addr                                  "0x0059"
#define  set_ECBUS_RX_ECBUS_BIST_OPTION_5_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_5_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_OPTION_5_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_5_reg))
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_dummy_7_2_shift                            (2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_bist_rx_ini_10b_1_9_8_shift                (0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_dummy_7_2_mask                             (0x000000FC)
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_bist_rx_ini_10b_1_9_8_mask                 (0x00000003)
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_dummy_7_2(data)                            (0x000000FC&((data)<<2))
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_bist_rx_ini_10b_1_9_8(data)                (0x00000003&(data))
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_get_dummy_7_2(data)                        ((0x000000FC&(data))>>2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_5_get_bist_rx_ini_10b_1_9_8(data)            (0x00000003&(data))

#define  ECBUS_RX_ECBUS_BIST_OPTION_6                                            0x1800A668
#define  ECBUS_RX_ECBUS_BIST_OPTION_6_reg_addr                                   "0xB800A668"
#define  ECBUS_RX_ECBUS_BIST_OPTION_6_reg                                        0xB800A668
#define  ECBUS_RX_ECBUS_BIST_OPTION_6_inst_addr                                  "0x005A"
#define  set_ECBUS_RX_ECBUS_BIST_OPTION_6_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_6_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_OPTION_6_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_6_reg))
#define  ECBUS_RX_ECBUS_BIST_OPTION_6_bist_rx_ini_10b_1_7_0_shift                (0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_6_bist_rx_ini_10b_1_7_0_mask                 (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_OPTION_6_bist_rx_ini_10b_1_7_0(data)                (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_OPTION_6_get_bist_rx_ini_10b_1_7_0(data)            (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_BIST_OPTION_7                                            0x1800A66C
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_reg_addr                                   "0xB800A66C"
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_reg                                        0xB800A66C
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_inst_addr                                  "0x005B"
#define  set_ECBUS_RX_ECBUS_BIST_OPTION_7_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_7_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_OPTION_7_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_7_reg))
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_dummy_7_2_shift                            (2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_bist_rx_ini_10b_0_9_8_shift                (0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_dummy_7_2_mask                             (0x000000FC)
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_bist_rx_ini_10b_0_9_8_mask                 (0x00000003)
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_dummy_7_2(data)                            (0x000000FC&((data)<<2))
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_bist_rx_ini_10b_0_9_8(data)                (0x00000003&(data))
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_get_dummy_7_2(data)                        ((0x000000FC&(data))>>2)
#define  ECBUS_RX_ECBUS_BIST_OPTION_7_get_bist_rx_ini_10b_0_9_8(data)            (0x00000003&(data))

#define  ECBUS_RX_ECBUS_BIST_OPTION_8                                            0x1800A670
#define  ECBUS_RX_ECBUS_BIST_OPTION_8_reg_addr                                   "0xB800A670"
#define  ECBUS_RX_ECBUS_BIST_OPTION_8_reg                                        0xB800A670
#define  ECBUS_RX_ECBUS_BIST_OPTION_8_inst_addr                                  "0x005C"
#define  set_ECBUS_RX_ECBUS_BIST_OPTION_8_reg(data)                              (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_8_reg)=data)
#define  get_ECBUS_RX_ECBUS_BIST_OPTION_8_reg                                    (*((volatile unsigned int*)ECBUS_RX_ECBUS_BIST_OPTION_8_reg))
#define  ECBUS_RX_ECBUS_BIST_OPTION_8_bist_rx_ini_10b_0_7_0_shift                (0)
#define  ECBUS_RX_ECBUS_BIST_OPTION_8_bist_rx_ini_10b_0_7_0_mask                 (0x000000FF)
#define  ECBUS_RX_ECBUS_BIST_OPTION_8_bist_rx_ini_10b_0_7_0(data)                (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_BIST_OPTION_8_get_bist_rx_ini_10b_0_7_0(data)            (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_RESERVE_0                                                0x1800A674
#define  ECBUS_RX_ECBUS_RESERVE_0_reg_addr                                       "0xB800A674"
#define  ECBUS_RX_ECBUS_RESERVE_0_reg                                            0xB800A674
#define  ECBUS_RX_ECBUS_RESERVE_0_inst_addr                                      "0x005D"
#define  set_ECBUS_RX_ECBUS_RESERVE_0_reg(data)                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_RESERVE_0_reg)=data)
#define  get_ECBUS_RX_ECBUS_RESERVE_0_reg                                        (*((volatile unsigned int*)ECBUS_RX_ECBUS_RESERVE_0_reg))
#define  ECBUS_RX_ECBUS_RESERVE_0_dummy_7_0_shift                                (0)
#define  ECBUS_RX_ECBUS_RESERVE_0_dummy_7_0_mask                                 (0x000000FF)
#define  ECBUS_RX_ECBUS_RESERVE_0_dummy_7_0(data)                                (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_RESERVE_0_get_dummy_7_0(data)                            (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_RESERVE_1                                                0x1800A678
#define  ECBUS_RX_ECBUS_RESERVE_1_reg_addr                                       "0xB800A678"
#define  ECBUS_RX_ECBUS_RESERVE_1_reg                                            0xB800A678
#define  ECBUS_RX_ECBUS_RESERVE_1_inst_addr                                      "0x005E"
#define  set_ECBUS_RX_ECBUS_RESERVE_1_reg(data)                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_RESERVE_1_reg)=data)
#define  get_ECBUS_RX_ECBUS_RESERVE_1_reg                                        (*((volatile unsigned int*)ECBUS_RX_ECBUS_RESERVE_1_reg))
#define  ECBUS_RX_ECBUS_RESERVE_1_dummy_7_0_shift                                (0)
#define  ECBUS_RX_ECBUS_RESERVE_1_dummy_7_0_mask                                 (0x000000FF)
#define  ECBUS_RX_ECBUS_RESERVE_1_dummy_7_0(data)                                (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_RESERVE_1_get_dummy_7_0(data)                            (0x000000FF&(data))

#define  ECBUS_RX_ECBUS_RESERVE_2                                                0x1800A67C
#define  ECBUS_RX_ECBUS_RESERVE_2_reg_addr                                       "0xB800A67C"
#define  ECBUS_RX_ECBUS_RESERVE_2_reg                                            0xB800A67C
#define  ECBUS_RX_ECBUS_RESERVE_2_inst_addr                                      "0x005F"
#define  set_ECBUS_RX_ECBUS_RESERVE_2_reg(data)                                  (*((volatile unsigned int*)ECBUS_RX_ECBUS_RESERVE_2_reg)=data)
#define  get_ECBUS_RX_ECBUS_RESERVE_2_reg                                        (*((volatile unsigned int*)ECBUS_RX_ECBUS_RESERVE_2_reg))
#define  ECBUS_RX_ECBUS_RESERVE_2_dummy_7_0_shift                                (0)
#define  ECBUS_RX_ECBUS_RESERVE_2_dummy_7_0_mask                                 (0x000000FF)
#define  ECBUS_RX_ECBUS_RESERVE_2_dummy_7_0(data)                                (0x000000FF&(data))
#define  ECBUS_RX_ECBUS_RESERVE_2_get_dummy_7_0(data)                            (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ECBUS_RX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ecbus_mac_in_latch_clk_inv_sel:1;
        RBus_UInt32  cbus1_inout_swap:1;
        RBus_UInt32  emsc_inout_swap:1;
        RBus_UInt32  cbus1_cmd_swap:1;
        RBus_UInt32  mark_swap:1;
        RBus_UInt32  ecbus_pwup:1;
        RBus_UInt32  ecbus_irq:1;
        RBus_UInt32  ecbus_reset:1;
        RBus_UInt32  comma2_det_en:1;
    };
}ecbus_rx_ecbus_startup_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fwd_valid:1;
        RBus_UInt32  comma_lsb_first:1;
        RBus_UInt32  bwd_type:2;
        RBus_UInt32  comma2_debounce:2;
        RBus_UInt32  comma2_loss_thd:2;
    };
}ecbus_rx_ecbus_startup_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  force_startup_done:1;
        RBus_UInt32  comma_tx_disp0:1;
        RBus_UInt32  comma_tx_disp1:1;
        RBus_UInt32  comma2_chk_disp:1;
        RBus_UInt32  comma2_rcv_irq:1;
        RBus_UInt32  comma2_rcv_irq_en:1;
        RBus_UInt32  comma2_loss_irq:1;
        RBus_UInt32  comma2_loss_irq_en:1;
    };
}ecbus_rx_ecbus_startup_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a50c_7_0:8;
    };
}ecbus_rx_ecbus_startup_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  resp_com2_m:1;
        RBus_UInt32  sent_com2:1;
        RBus_UInt32  enter_tdm_active:1;
        RBus_UInt32  com1_det_en:1;
        RBus_UInt32  ignore_idle_det:1;
        RBus_UInt32  sent_com1:1;
        RBus_UInt32  tdm_sync_retry:1;
        RBus_UInt32  tdm_sync_reinit:1;
    };
}ecbus_rx_ecbus_tdm_sync_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  com1_debounce:2;
        RBus_UInt32  com1_loss_thd:2;
        RBus_UInt32  idle_err_thd:2;
        RBus_UInt32  com2_debounce:2;
    };
}ecbus_rx_ecbus_tdm_sync_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tdm_sync_loss_thd:8;
    };
}ecbus_rx_ecbus_tdm_sync_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a51c_7_6:2;
        RBus_UInt32  com2_rcv_irq_en:1;
        RBus_UInt32  com1_idle_err:1;
        RBus_UInt32  com1_rcv_irq:1;
        RBus_UInt32  com1_rcv_irq_en:1;
        RBus_UInt32  com1_loss:1;
        RBus_UInt32  com2_rcv_irq:1;
    };
}ecbus_rx_ecbus_tdm_sync_det_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a520_7_5:3;
        RBus_UInt32  chk_when_loss:1;
        RBus_UInt32  tdm_sync_irq:1;
        RBus_UInt32  tdm_sync_irq_en:1;
        RBus_UInt32  tdm_sync_loss_irq:1;
        RBus_UInt32  tdm_sync_loss_irq_en:1;
    };
}ecbus_rx_ecbus_tdm_sync_det_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  set_tx_offset:4;
        RBus_UInt32  dummy1800a524_3:1;
        RBus_UInt32  set_tx_offset_fine:3;
    };
}ecbus_rx_ecbus_tdm_sync_tx_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  check_rx_offset:4;
        RBus_UInt32  dummy1800a528_3:1;
        RBus_UInt32  check_rx_offset_fine:3;
    };
}ecbus_rx_ecbus_tdm_sync_rx_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a52c_7_2:6;
        RBus_UInt32  check_rx_offset_range:2;
    };
}ecbus_rx_ecbus_tdm_sync_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a530_7_5:3;
        RBus_UInt32  emsc_reset:1;
        RBus_UInt32  sent_mark_sel:1;
        RBus_UInt32  emsc_sync_start:1;
        RBus_UInt32  sync_err_det_en:1;
        RBus_UInt32  mark2_accept:1;
    };
}ecbus_rx_ecbus_emsc_sync_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sync_debounce:3;
        RBus_UInt32  sync_err_thd:2;
        RBus_UInt32  mark_loss_thd:3;
    };
}ecbus_rx_ecbus_emsc_sync_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a538_7_4:4;
        RBus_UInt32  rx_sync_thd:2;
        RBus_UInt32  tx_sync_thd:2;
    };
}ecbus_rx_ecbus_emsc_sync_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sync_rcv:1;
        RBus_UInt32  sync_loss:1;
        RBus_UInt32  rx_sync_meet:1;
        RBus_UInt32  mark_rcv:1;
        RBus_UInt32  emsc_link_done:1;
        RBus_UInt32  slot_det_done:1;
        RBus_UInt32  mark_loss_irq:1;
        RBus_UInt32  mark_loss_irq_en:1;
    };
}ecbus_rx_ecbus_emsc_sync_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_slot_map_h:8;
    };
}ecbus_rx_ecbus_emsc_slot_map_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_slot_map_m:8;
    };
}ecbus_rx_ecbus_emsc_slot_map_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_slot_map_l:8;
    };
}ecbus_rx_ecbus_emsc_slot_map_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sourse_slot_map_h:8;
    };
}ecbus_rx_ecbus_emsc_source_slot_det_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sourse_slot_map_m:8;
    };
}ecbus_rx_ecbus_emsc_source_slot_det_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sourse_slot_map_l:8;
    };
}ecbus_rx_ecbus_emsc_source_slot_det_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a558_7_0:8;
    };
}ecbus_rx_ecbus_emsc_sync_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_rxbuf_rpt:8;
    };
}ecbus_rx_ecbus_emsc_rx_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_rxbuf_rdata:8;
    };
}ecbus_rx_ecbus_emsc_rx_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_txbuf_wpt:8;
    };
}ecbus_rx_ecbus_emsc_tx_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_txbuf_wdata:8;
    };
}ecbus_rx_ecbus_emsc_tx_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_txbuf_rpt:8;
    };
}ecbus_rx_ecbus_emsc_tx_rd_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_txbuf_rdata:8;
    };
}ecbus_rx_ecbus_emsc_tx_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a574_7:1;
        RBus_UInt32  tx_dstart_option:1;
        RBus_UInt32  hw_chk_remain:1;
        RBus_UInt32  chk_cmd_option:1;
        RBus_UInt32  unexpect_option:1;
        RBus_UInt32  block_fw_done:1;
        RBus_UInt32  emsc_tx_sent:1;
        RBus_UInt32  emsc_txbuf_fw_mode:1;
    };
}ecbus_rx_ecbus_emsc_trans_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_rx_block_cnt:8;
    };
}ecbus_rx_ecbus_emsc_rx_blk_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_rx_wr_point:8;
    };
}ecbus_rx_ecbus_emsc_rx_wrt_pnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_tx_rd_point:8;
    };
}ecbus_rx_ecbus_emsc_tx_wrt_pnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_rx_req_cnt:8;
    };
}ecbus_rx_ecbus_emsc_rx_req_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_tx_req_cnt:8;
    };
}ecbus_rx_ecbus_emsc_tx_req_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a58c_7_4:4;
        RBus_UInt32  rx_ignore_byte:4;
    };
}ecbus_rx_ecbus_emsc_trans_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_req_tout:2;
        RBus_UInt32  retry_num:2;
        RBus_UInt32  retry_wait:4;
    };
}ecbus_rx_ecbus_emsc_trans_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rxbuf_full:1;
        RBus_UInt32  rxbuf_empty:1;
        RBus_UInt32  rxbuf_clr:1;
        RBus_UInt32  rx_reply_nack:1;
        RBus_UInt32  rxbuf_ovfl_irq:1;
        RBus_UInt32  rxbuf_ovfl_irq_en:1;
        RBus_UInt32  rxbuf_udfl_irq:1;
        RBus_UInt32  rxbuf_udfl_irq_en:1;
    };
}ecbus_rx_ecbus_emsc_trans_det_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  txbuf_full:1;
        RBus_UInt32  txbuf_empty:1;
        RBus_UInt32  txbuf_clr:1;
        RBus_UInt32  payload_crc_err:1;
        RBus_UInt32  txbuf_ovfl_irq:1;
        RBus_UInt32  txbuf_ovfl_irq_en:1;
        RBus_UInt32  txbuf_udfl_irq:1;
        RBus_UInt32  txbuf_udfl_irq_en:1;
    };
}ecbus_rx_ecbus_emsc_trans_det_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a59c_7:1;
        RBus_UInt32  rx_remain_noneq_cnt:1;
        RBus_UInt32  emsc_rx_done_irq:1;
        RBus_UInt32  emsc_rx_done_irq_en:1;
        RBus_UInt32  emsc_tx_done_irq:1;
        RBus_UInt32  emsc_tx_done_irq_en:1;
        RBus_UInt32  retry_limit_irq:1;
        RBus_UInt32  retry_limit_irq_en:1;
    };
}ecbus_rx_ecbus_emsc_trans_det_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a5a0_7_5:3;
        RBus_UInt32  rx_time_out:1;
        RBus_UInt32  tx_time_out:1;
        RBus_UInt32  tx_get_nack:1;
        RBus_UInt32  tx_get_error:1;
        RBus_UInt32  tx_crc_inverted:1;
    };
}ecbus_rx_ecbus_emsc_trans_det_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  get_error_code:8;
    };
}ecbus_rx_ecbus_emsc_tx_err_code_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rx_remain:8;
    };
}ecbus_rx_ecbus_emsc_trans_reserve_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  get_ack_crc:2;
        RBus_UInt32  get_nack_crc:2;
        RBus_UInt32  get_grant_crc:2;
        RBus_UInt32  get_dstart_crc:2;
    };
}ecbus_rx_ecbus_emsc_rx_crc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a5b0_7_6:2;
        RBus_UInt32  get_err00_crc:3;
        RBus_UInt32  get_err01_crc:3;
    };
}ecbus_rx_ecbus_emsc_rx_crc_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  get_payload_crc_15_8:8;
    };
}ecbus_rx_ecbus_emsc_rx_crc_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  get_payload_crc_7_0:8;
    };
}ecbus_rx_ecbus_emsc_rx_crc_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tx_ack_crc:2;
        RBus_UInt32  tx_nack_crc:2;
        RBus_UInt32  tx_grant_crc:2;
        RBus_UInt32  tx_dstart_crc:2;
    };
}ecbus_rx_ecbus_emsc_tx_crc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a5c0_7_3:5;
        RBus_UInt32  tx_err01_crc:3;
    };
}ecbus_rx_ecbus_emsc_tx_crc_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tx_payload_crc_15_8:8;
    };
}ecbus_rx_ecbus_emsc_tx_crc_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tx_payload_crc_7_0:8;
    };
}ecbus_rx_ecbus_emsc_tx_crc_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a5cc_7_1:7;
        RBus_UInt32  bist_out_inv:1;
    };
}ecbus_rx_ecbus_emsc_trans_reserve_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lq_inv:1;
        RBus_UInt32  gx_inv:1;
        RBus_UInt32  bist_out_swap:1;
        RBus_UInt32  ecbus_bist_en:1;
        RBus_UInt32  bist_err_reset:1;
        RBus_UInt32  prbs_reset:1;
        RBus_UInt32  bist_comp_start:1;
        RBus_UInt32  rx_bist_stop:1;
    };
}ecbus_rx_ecbus_bist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tx_bist:1;
        RBus_UInt32  rx_bist:1;
        RBus_UInt32  bist_rx_debounce:2;
        RBus_UInt32  bist_pattern:1;
        RBus_UInt32  fix8_alter:1;
        RBus_UInt32  bist_err_sel:1;
        RBus_UInt32  prbs_gen_sel:1;
    };
}ecbus_rx_ecbus_bist_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fix8_data:8;
    };
}ecbus_rx_ecbus_bist_fixed8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bist_rx_ini:8;
    };
}ecbus_rx_ecbus_bist_rx_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bist_tx_ini:8;
    };
}ecbus_rx_ecbus_bist_tx_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bist_err_cnt_15_8:8;
    };
}ecbus_rx_ecbus_bist_err_cnt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bist_err_cnt_7_0:8;
    };
}ecbus_rx_ecbus_bist_err_cnt_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  prbs_coef:8;
    };
}ecbus_rx_ecbus_bist_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  dummy1800a5f0_3_0:4;
    };
}ecbus_rx_ecbus_sram_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  drf_bist_mode:1;
        RBus_UInt32  drf_test_resume:1;
        RBus_UInt32  drf_start_pause:1;
        RBus_UInt32  drf_bist_done:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  dummy1800a5f4_1_0:2;
    };
}ecbus_rx_ecbus_sram_drf_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a5f8_7:1;
        RBus_UInt32  cbus1_crc_opt:1;
        RBus_UInt32  tby_crc_opt:1;
        RBus_UInt32  crc_out_swap:1;
        RBus_UInt32  crc_not_inv:1;
        RBus_UInt32  crc_in_swap:1;
        RBus_UInt32  crc_ignore:1;
        RBus_UInt32  crc_sel_fw:1;
    };
}ecbus_rx_ecbus_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b0_coef_h:8;
    };
}ecbus_rx_cbus1_fw_crc_b0_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b0_coef_l:8;
    };
}ecbus_rx_cbus1_fw_crc_b0_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b1_coef_h:8;
    };
}ecbus_rx_cbus1_fw_crc_b1_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b1_coef_l:8;
    };
}ecbus_rx_cbus1_fw_crc_b1_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b2_coef_h:8;
    };
}ecbus_rx_cbus1_fw_crc_b2_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b2_coef_l:8;
    };
}ecbus_rx_cbus1_fw_crc_b2_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b3_coef_h:8;
    };
}ecbus_rx_cbus1_fw_crc_b3_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b3_coef_l:8;
    };
}ecbus_rx_cbus1_fw_crc_b3_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b4_coef_h:8;
    };
}ecbus_rx_cbus1_fw_crc_b4_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_b4_coef_l:8;
    };
}ecbus_rx_cbus1_fw_crc_b4_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  clk_1m_div:4;
        RBus_UInt32  dummy1800a624_3_2:2;
        RBus_UInt32  clk_1k_div_9_8:2;
    };
}ecbus_rx_ecbus_timeout_clk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  clk_1k_div_7_0:8;
    };
}ecbus_rx_ecbus_timeout_clk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a62c_7_0:8;
    };
}ecbus_rx_ecbus_timeout_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ecbus_st:8;
    };
}ecbus_rx_ecbus_hw_fsm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cbus1_st:8;
    };
}ecbus_rx_ecbus_hw_fsm_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_st_3_0:4;
        RBus_UInt32  dummy1800a638_3:1;
        RBus_UInt32  emsc_tx_st_10_8:3;
    };
}ecbus_rx_ecbus_hw_fsm_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_tx_st_7_0:8;
    };
}ecbus_rx_ecbus_hw_fsm_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a640_7_2:6;
        RBus_UInt32  emsc_rx_st_9_8:2;
    };
}ecbus_rx_ecbus_hw_fsm_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  emsc_rx_st_7_0:8;
    };
}ecbus_rx_ecbus_hw_fsm_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ecbus_tst_sel:4;
        RBus_UInt32  force_testout_en:1;
        RBus_UInt32  force_testout_sel:3;
    };
}ecbus_rx_ecbus_test_force_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a64c_7_0:8;
    };
}ecbus_rx_ecbus_testout_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a650_7_5:3;
        RBus_UInt32  bist_10b_ini_calcu:1;
        RBus_UInt32  bist_10b_en:1;
        RBus_UInt32  tx_disp_ini_inv:1;
        RBus_UInt32  force_start_num:1;
        RBus_UInt32  start_odd:1;
    };
}ecbus_rx_ecbus_bist_option_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a654_7_2:6;
        RBus_UInt32  reg_bist_8b10b_ini_out_1_9_8:2;
    };
}ecbus_rx_ecbus_bist_option_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_bist_8b10b_ini_out_1_7_0:8;
    };
}ecbus_rx_ecbus_bist_option_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a65c_7_2:6;
        RBus_UInt32  reg_bist_8b10b_ini_out_0_9_8:2;
    };
}ecbus_rx_ecbus_bist_option_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_bist_8b10b_ini_out_0_7_0:8;
    };
}ecbus_rx_ecbus_bist_option_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a664_7_2:6;
        RBus_UInt32  bist_rx_ini_10b_1_9_8:2;
    };
}ecbus_rx_ecbus_bist_option_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bist_rx_ini_10b_1_7_0:8;
    };
}ecbus_rx_ecbus_bist_option_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a66c_7_2:6;
        RBus_UInt32  bist_rx_ini_10b_0_9_8:2;
    };
}ecbus_rx_ecbus_bist_option_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bist_rx_ini_10b_0_7_0:8;
    };
}ecbus_rx_ecbus_bist_option_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a674_7_0:8;
    };
}ecbus_rx_ecbus_reserve_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a678_7_0:8;
    };
}ecbus_rx_ecbus_reserve_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy1800a67c_7_0:8;
    };
}ecbus_rx_ecbus_reserve_2_RBUS;

#else //apply LITTLE_ENDIAN

//======ECBUS_RX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comma2_det_en:1;
        RBus_UInt32  ecbus_reset:1;
        RBus_UInt32  ecbus_irq:1;
        RBus_UInt32  ecbus_pwup:1;
        RBus_UInt32  mark_swap:1;
        RBus_UInt32  cbus1_cmd_swap:1;
        RBus_UInt32  emsc_inout_swap:1;
        RBus_UInt32  cbus1_inout_swap:1;
        RBus_UInt32  ecbus_mac_in_latch_clk_inv_sel:1;
        RBus_UInt32  res1:23;
    };
}ecbus_rx_ecbus_startup_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comma2_loss_thd:2;
        RBus_UInt32  comma2_debounce:2;
        RBus_UInt32  bwd_type:2;
        RBus_UInt32  comma_lsb_first:1;
        RBus_UInt32  fwd_valid:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_startup_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comma2_loss_irq_en:1;
        RBus_UInt32  comma2_loss_irq:1;
        RBus_UInt32  comma2_rcv_irq_en:1;
        RBus_UInt32  comma2_rcv_irq:1;
        RBus_UInt32  comma2_chk_disp:1;
        RBus_UInt32  comma_tx_disp1:1;
        RBus_UInt32  comma_tx_disp0:1;
        RBus_UInt32  force_startup_done:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_startup_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800a50c_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_startup_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tdm_sync_reinit:1;
        RBus_UInt32  tdm_sync_retry:1;
        RBus_UInt32  sent_com1:1;
        RBus_UInt32  ignore_idle_det:1;
        RBus_UInt32  com1_det_en:1;
        RBus_UInt32  enter_tdm_active:1;
        RBus_UInt32  sent_com2:1;
        RBus_UInt32  resp_com2_m:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_tdm_sync_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  com2_debounce:2;
        RBus_UInt32  idle_err_thd:2;
        RBus_UInt32  com1_loss_thd:2;
        RBus_UInt32  com1_debounce:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_tdm_sync_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tdm_sync_loss_thd:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_tdm_sync_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  com2_rcv_irq:1;
        RBus_UInt32  com1_loss:1;
        RBus_UInt32  com1_rcv_irq_en:1;
        RBus_UInt32  com1_rcv_irq:1;
        RBus_UInt32  com1_idle_err:1;
        RBus_UInt32  com2_rcv_irq_en:1;
        RBus_UInt32  dummy1800a51c_7:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_tdm_sync_det_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tdm_sync_loss_irq_en:1;
        RBus_UInt32  tdm_sync_loss_irq:1;
        RBus_UInt32  tdm_sync_irq_en:1;
        RBus_UInt32  tdm_sync_irq:1;
        RBus_UInt32  chk_when_loss:1;
        RBus_UInt32  dummy1800a520_7:3;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_tdm_sync_det_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set_tx_offset_fine:3;
        RBus_UInt32  dummy1800a524_3_3:1;
        RBus_UInt32  set_tx_offset:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_tdm_sync_tx_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  check_rx_offset_fine:3;
        RBus_UInt32  dummy1800a528_3_3:1;
        RBus_UInt32  check_rx_offset:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_tdm_sync_rx_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  check_rx_offset_range:2;
        RBus_UInt32  dummy1800a52c_7_2:6;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_tdm_sync_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark2_accept:1;
        RBus_UInt32  sync_err_det_en:1;
        RBus_UInt32  emsc_sync_start:1;
        RBus_UInt32  sent_mark_sel:1;
        RBus_UInt32  emsc_reset:1;
        RBus_UInt32  dummy1800a530_7:3;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_sync_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_loss_thd:3;
        RBus_UInt32  sync_err_thd:2;
        RBus_UInt32  sync_debounce:3;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_sync_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_sync_thd:2;
        RBus_UInt32  rx_sync_thd:2;
        RBus_UInt32  dummy1800a538_7_4:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_sync_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_loss_irq_en:1;
        RBus_UInt32  mark_loss_irq:1;
        RBus_UInt32  slot_det_done:1;
        RBus_UInt32  emsc_link_done:1;
        RBus_UInt32  mark_rcv:1;
        RBus_UInt32  rx_sync_meet:1;
        RBus_UInt32  sync_loss:1;
        RBus_UInt32  sync_rcv:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_sync_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_slot_map_h:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_slot_map_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_slot_map_m:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_slot_map_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_slot_map_l:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_slot_map_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sourse_slot_map_h:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_source_slot_det_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sourse_slot_map_m:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_source_slot_det_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sourse_slot_map_l:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_source_slot_det_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800a558_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_sync_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_rxbuf_rpt:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_rx_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_rxbuf_rdata:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_rx_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_txbuf_wpt:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_txbuf_wdata:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_txbuf_rpt:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_rd_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_txbuf_rdata:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_txbuf_fw_mode:1;
        RBus_UInt32  emsc_tx_sent:1;
        RBus_UInt32  block_fw_done:1;
        RBus_UInt32  unexpect_option:1;
        RBus_UInt32  chk_cmd_option:1;
        RBus_UInt32  hw_chk_remain:1;
        RBus_UInt32  tx_dstart_option:1;
        RBus_UInt32  dummy1800a574_7:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_trans_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_rx_block_cnt:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_rx_blk_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_rx_wr_point:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_rx_wrt_pnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_tx_rd_point:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_wrt_pnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_rx_req_cnt:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_rx_req_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_tx_req_cnt:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_req_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_ignore_byte:4;
        RBus_UInt32  dummy1800a58c_7_4:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_trans_config_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  retry_wait:4;
        RBus_UInt32  retry_num:2;
        RBus_UInt32  emsc_req_tout:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_trans_config_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxbuf_udfl_irq_en:1;
        RBus_UInt32  rxbuf_udfl_irq:1;
        RBus_UInt32  rxbuf_ovfl_irq_en:1;
        RBus_UInt32  rxbuf_ovfl_irq:1;
        RBus_UInt32  rx_reply_nack:1;
        RBus_UInt32  rxbuf_clr:1;
        RBus_UInt32  rxbuf_empty:1;
        RBus_UInt32  rxbuf_full:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_trans_det_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txbuf_udfl_irq_en:1;
        RBus_UInt32  txbuf_udfl_irq:1;
        RBus_UInt32  txbuf_ovfl_irq_en:1;
        RBus_UInt32  txbuf_ovfl_irq:1;
        RBus_UInt32  payload_crc_err:1;
        RBus_UInt32  txbuf_clr:1;
        RBus_UInt32  txbuf_empty:1;
        RBus_UInt32  txbuf_full:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_trans_det_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  retry_limit_irq_en:1;
        RBus_UInt32  retry_limit_irq:1;
        RBus_UInt32  emsc_tx_done_irq_en:1;
        RBus_UInt32  emsc_tx_done_irq:1;
        RBus_UInt32  emsc_rx_done_irq_en:1;
        RBus_UInt32  emsc_rx_done_irq:1;
        RBus_UInt32  rx_remain_noneq_cnt:1;
        RBus_UInt32  dummy1800a59c_7:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_trans_det_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_crc_inverted:1;
        RBus_UInt32  tx_get_error:1;
        RBus_UInt32  tx_get_nack:1;
        RBus_UInt32  tx_time_out:1;
        RBus_UInt32  rx_time_out:1;
        RBus_UInt32  dummy1800a5a0_7:3;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_trans_det_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  get_error_code:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_err_code_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_remain:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_trans_reserve_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  get_dstart_crc:2;
        RBus_UInt32  get_grant_crc:2;
        RBus_UInt32  get_nack_crc:2;
        RBus_UInt32  get_ack_crc:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_rx_crc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  get_err01_crc:3;
        RBus_UInt32  get_err00_crc:3;
        RBus_UInt32  dummy1800a5b0_7_6:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_rx_crc_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  get_payload_crc_15_8:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_rx_crc_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  get_payload_crc_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_rx_crc_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_dstart_crc:2;
        RBus_UInt32  tx_grant_crc:2;
        RBus_UInt32  tx_nack_crc:2;
        RBus_UInt32  tx_ack_crc:2;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_crc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_err01_crc:3;
        RBus_UInt32  dummy1800a5c0_7_3:5;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_crc_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_payload_crc_15_8:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_crc_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_payload_crc_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_tx_crc_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_out_inv:1;
        RBus_UInt32  dummy1800a5cc_7:7;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_emsc_trans_reserve_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_bist_stop:1;
        RBus_UInt32  bist_comp_start:1;
        RBus_UInt32  prbs_reset:1;
        RBus_UInt32  bist_err_reset:1;
        RBus_UInt32  ecbus_bist_en:1;
        RBus_UInt32  bist_out_swap:1;
        RBus_UInt32  gx_inv:1;
        RBus_UInt32  lq_inv:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs_gen_sel:1;
        RBus_UInt32  bist_err_sel:1;
        RBus_UInt32  fix8_alter:1;
        RBus_UInt32  bist_pattern:1;
        RBus_UInt32  bist_rx_debounce:2;
        RBus_UInt32  rx_bist:1;
        RBus_UInt32  tx_bist:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fix8_data:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_fixed8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_rx_ini:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_rx_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_tx_ini:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_tx_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_err_cnt_15_8:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_err_cnt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_err_cnt_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_err_cnt_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs_coef:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800a5f0_3_0:4;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_sram_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800a5f4_1_0:2;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_done:1;
        RBus_UInt32  drf_start_pause:1;
        RBus_UInt32  drf_test_resume:1;
        RBus_UInt32  drf_bist_mode:1;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  res1:12;
    };
}ecbus_rx_ecbus_sram_drf_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_sel_fw:1;
        RBus_UInt32  crc_ignore:1;
        RBus_UInt32  crc_in_swap:1;
        RBus_UInt32  crc_not_inv:1;
        RBus_UInt32  crc_out_swap:1;
        RBus_UInt32  tby_crc_opt:1;
        RBus_UInt32  cbus1_crc_opt:1;
        RBus_UInt32  dummy1800a5f8_7:1;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b0_coef_h:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b0_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b0_coef_l:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b0_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b1_coef_h:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b1_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b1_coef_l:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b1_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b2_coef_h:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b2_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b2_coef_l:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b2_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b3_coef_h:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b3_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b3_coef_l:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b3_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b4_coef_h:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b4_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_b4_coef_l:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_cbus1_fw_crc_b4_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_1k_div_9_8:2;
        RBus_UInt32  dummy1800a624_3_2:2;
        RBus_UInt32  clk_1m_div:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_timeout_clk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_1k_div_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_timeout_clk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800a62c_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_timeout_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecbus_st:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_hw_fsm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cbus1_st:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_hw_fsm_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_tx_st_10_8:3;
        RBus_UInt32  dummy1800a638_3_3:1;
        RBus_UInt32  emsc_st_3_0:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_hw_fsm_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_tx_st_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_hw_fsm_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_rx_st_9_8:2;
        RBus_UInt32  dummy1800a640_7_2:6;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_hw_fsm_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emsc_rx_st_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_hw_fsm_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  force_testout_sel:3;
        RBus_UInt32  force_testout_en:1;
        RBus_UInt32  ecbus_tst_sel:4;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_test_force_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800a64c_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_testout_reserve_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_odd:1;
        RBus_UInt32  force_start_num:1;
        RBus_UInt32  tx_disp_ini_inv:1;
        RBus_UInt32  bist_10b_en:1;
        RBus_UInt32  bist_10b_ini_calcu:1;
        RBus_UInt32  dummy1800a650_7:3;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_option_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bist_8b10b_ini_out_1_9_8:2;
        RBus_UInt32  dummy1800a654_7_2:6;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_option_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bist_8b10b_ini_out_1_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_option_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bist_8b10b_ini_out_0_9_8:2;
        RBus_UInt32  dummy1800a65c_7_2:6;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_option_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bist_8b10b_ini_out_0_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_option_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_rx_ini_10b_1_9_8:2;
        RBus_UInt32  dummy1800a664_7_2:6;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_option_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_rx_ini_10b_1_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_option_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_rx_ini_10b_0_9_8:2;
        RBus_UInt32  dummy1800a66c_7_2:6;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_option_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_rx_ini_10b_0_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_bist_option_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800a674_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_reserve_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800a678_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_reserve_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800a67c_7_0:8;
        RBus_UInt32  res1:24;
    };
}ecbus_rx_ecbus_reserve_2_RBUS;




#endif 


#endif 
