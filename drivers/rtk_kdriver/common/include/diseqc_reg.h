/**
* @file rbusDiseqcReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DISEQC_REG_H_
#define _RBUS_DISEQC_REG_H_

#include "rbus_types.h"



//  DISEQC Register Address
#define  DISEQC_DSCU_CTL                                                         0x18070000
#define  DISEQC_DSCU_CTL_reg_addr                                                "0xB8070000"
#define  DISEQC_DSCU_CTL_reg                                                     0xB8070000
#define  DISEQC_DSCU_CTL_inst_addr                                               "0x0000"
#define  set_DISEQC_DSCU_CTL_reg(data)                                           (*((volatile unsigned int*)DISEQC_DSCU_CTL_reg)=data)
#define  get_DISEQC_DSCU_CTL_reg                                                 (*((volatile unsigned int*)DISEQC_DSCU_CTL_reg))
#define  DISEQC_DSCU_CTL_dsc_pol_od_ctrl_shift                                   (29)
#define  DISEQC_DSCU_CTL_dsc_22k_od_ctrl_shift                                   (28)
#define  DISEQC_DSCU_CTL_eorm_timeout_reg_shift                                  (24)
#define  DISEQC_DSCU_CTL_mili_second_define_shift                                (5)
#define  DISEQC_DSCU_CTL_lnb_pol_shift                                           (4)
#define  DISEQC_DSCU_CTL_int_en_shift                                            (3)
#define  DISEQC_DSCU_CTL_level_shift                                             (1)
#define  DISEQC_DSCU_CTL_dsc_pol_od_ctrl_mask                                    (0x20000000)
#define  DISEQC_DSCU_CTL_dsc_22k_od_ctrl_mask                                    (0x10000000)
#define  DISEQC_DSCU_CTL_eorm_timeout_reg_mask                                   (0x0F000000)
#define  DISEQC_DSCU_CTL_mili_second_define_mask                                 (0x00FFFFE0)
#define  DISEQC_DSCU_CTL_lnb_pol_mask                                            (0x00000010)
#define  DISEQC_DSCU_CTL_int_en_mask                                             (0x00000008)
#define  DISEQC_DSCU_CTL_level_mask                                              (0x00000006)
#define  DISEQC_DSCU_CTL_dsc_pol_od_ctrl(data)                                   (0x20000000&((data)<<29))
#define  DISEQC_DSCU_CTL_dsc_22k_od_ctrl(data)                                   (0x10000000&((data)<<28))
#define  DISEQC_DSCU_CTL_eorm_timeout_reg(data)                                  (0x0F000000&((data)<<24))
#define  DISEQC_DSCU_CTL_mili_second_define(data)                                (0x00FFFFE0&((data)<<5))
#define  DISEQC_DSCU_CTL_lnb_pol(data)                                           (0x00000010&((data)<<4))
#define  DISEQC_DSCU_CTL_int_en(data)                                            (0x00000008&((data)<<3))
#define  DISEQC_DSCU_CTL_level(data)                                             (0x00000006&((data)<<1))
#define  DISEQC_DSCU_CTL_get_dsc_pol_od_ctrl(data)                               ((0x20000000&(data))>>29)
#define  DISEQC_DSCU_CTL_get_dsc_22k_od_ctrl(data)                               ((0x10000000&(data))>>28)
#define  DISEQC_DSCU_CTL_get_eorm_timeout_reg(data)                              ((0x0F000000&(data))>>24)
#define  DISEQC_DSCU_CTL_get_mili_second_define(data)                            ((0x00FFFFE0&(data))>>5)
#define  DISEQC_DSCU_CTL_get_lnb_pol(data)                                       ((0x00000010&(data))>>4)
#define  DISEQC_DSCU_CTL_get_int_en(data)                                        ((0x00000008&(data))>>3)
#define  DISEQC_DSCU_CTL_get_level(data)                                         ((0x00000006&(data))>>1)

#define  DISEQC_DSCU_TX_CTL                                                      0x18070004
#define  DISEQC_DSCU_TX_CTL_reg_addr                                             "0xB8070004"
#define  DISEQC_DSCU_TX_CTL_reg                                                  0xB8070004
#define  DISEQC_DSCU_TX_CTL_inst_addr                                            "0x0001"
#define  set_DISEQC_DSCU_TX_CTL_reg(data)                                        (*((volatile unsigned int*)DISEQC_DSCU_TX_CTL_reg)=data)
#define  get_DISEQC_DSCU_TX_CTL_reg                                              (*((volatile unsigned int*)DISEQC_DSCU_TX_CTL_reg))
#define  DISEQC_DSCU_TX_CTL_loop_back_mode_shift                                 (31)
#define  DISEQC_DSCU_TX_CTL_listen_dly_shift                                     (27)
#define  DISEQC_DSCU_TX_CTL_third_bit_shift                                      (22)
#define  DISEQC_DSCU_TX_CTL_eot_len_shift                                        (17)
#define  DISEQC_DSCU_TX_CTL_tx_pty_shift                                         (16)
#define  DISEQC_DSCU_TX_CTL_xmt_mode_shift                                       (14)
#define  DISEQC_DSCU_TX_CTL_msg_len_shift                                        (11)
#define  DISEQC_DSCU_TX_CTL_tx_go_shift                                          (10)
#define  DISEQC_DSCU_TX_CTL_tone_div_shift                                       (0)
#define  DISEQC_DSCU_TX_CTL_loop_back_mode_mask                                  (0x80000000)
#define  DISEQC_DSCU_TX_CTL_listen_dly_mask                                      (0x78000000)
#define  DISEQC_DSCU_TX_CTL_third_bit_mask                                       (0x07C00000)
#define  DISEQC_DSCU_TX_CTL_eot_len_mask                                         (0x003E0000)
#define  DISEQC_DSCU_TX_CTL_tx_pty_mask                                          (0x00010000)
#define  DISEQC_DSCU_TX_CTL_xmt_mode_mask                                        (0x0000C000)
#define  DISEQC_DSCU_TX_CTL_msg_len_mask                                         (0x00003800)
#define  DISEQC_DSCU_TX_CTL_tx_go_mask                                           (0x00000400)
#define  DISEQC_DSCU_TX_CTL_tone_div_mask                                        (0x000003FF)
#define  DISEQC_DSCU_TX_CTL_loop_back_mode(data)                                 (0x80000000&((data)<<31))
#define  DISEQC_DSCU_TX_CTL_listen_dly(data)                                     (0x78000000&((data)<<27))
#define  DISEQC_DSCU_TX_CTL_third_bit(data)                                      (0x07C00000&((data)<<22))
#define  DISEQC_DSCU_TX_CTL_eot_len(data)                                        (0x003E0000&((data)<<17))
#define  DISEQC_DSCU_TX_CTL_tx_pty(data)                                         (0x00010000&((data)<<16))
#define  DISEQC_DSCU_TX_CTL_xmt_mode(data)                                       (0x0000C000&((data)<<14))
#define  DISEQC_DSCU_TX_CTL_msg_len(data)                                        (0x00003800&((data)<<11))
#define  DISEQC_DSCU_TX_CTL_tx_go(data)                                          (0x00000400&((data)<<10))
#define  DISEQC_DSCU_TX_CTL_tone_div(data)                                       (0x000003FF&(data))
#define  DISEQC_DSCU_TX_CTL_get_loop_back_mode(data)                             ((0x80000000&(data))>>31)
#define  DISEQC_DSCU_TX_CTL_get_listen_dly(data)                                 ((0x78000000&(data))>>27)
#define  DISEQC_DSCU_TX_CTL_get_third_bit(data)                                  ((0x07C00000&(data))>>22)
#define  DISEQC_DSCU_TX_CTL_get_eot_len(data)                                    ((0x003E0000&(data))>>17)
#define  DISEQC_DSCU_TX_CTL_get_tx_pty(data)                                     ((0x00010000&(data))>>16)
#define  DISEQC_DSCU_TX_CTL_get_xmt_mode(data)                                   ((0x0000C000&(data))>>14)
#define  DISEQC_DSCU_TX_CTL_get_msg_len(data)                                    ((0x00003800&(data))>>11)
#define  DISEQC_DSCU_TX_CTL_get_tx_go(data)                                      ((0x00000400&(data))>>10)
#define  DISEQC_DSCU_TX_CTL_get_tone_div(data)                                   (0x000003FF&(data))

#define  DISEQC_DSCU_RX_CTL                                                      0x18070008
#define  DISEQC_DSCU_RX_CTL_reg_addr                                             "0xB8070008"
#define  DISEQC_DSCU_RX_CTL_reg                                                  0xB8070008
#define  DISEQC_DSCU_RX_CTL_inst_addr                                            "0x0002"
#define  set_DISEQC_DSCU_RX_CTL_reg(data)                                        (*((volatile unsigned int*)DISEQC_DSCU_RX_CTL_reg)=data)
#define  get_DISEQC_DSCU_RX_CTL_reg                                              (*((volatile unsigned int*)DISEQC_DSCU_RX_CTL_reg))
#define  DISEQC_DSCU_RX_CTL_median_flt_en_shift                                  (31)
#define  DISEQC_DSCU_RX_CTL_dscu_exp_win_shift                                   (21)
#define  DISEQC_DSCU_RX_CTL_silence_threshold_shift                              (11)
#define  DISEQC_DSCU_RX_CTL_to_val_shift                                         (3)
#define  DISEQC_DSCU_RX_CTL_to_chk_shift                                         (2)
#define  DISEQC_DSCU_RX_CTL_rx_pty_shift                                         (1)
#define  DISEQC_DSCU_RX_CTL_median_flt_en_mask                                   (0x80000000)
#define  DISEQC_DSCU_RX_CTL_dscu_exp_win_mask                                    (0x7FE00000)
#define  DISEQC_DSCU_RX_CTL_silence_threshold_mask                               (0x001FF800)
#define  DISEQC_DSCU_RX_CTL_to_val_mask                                          (0x000007F8)
#define  DISEQC_DSCU_RX_CTL_to_chk_mask                                          (0x00000004)
#define  DISEQC_DSCU_RX_CTL_rx_pty_mask                                          (0x00000002)
#define  DISEQC_DSCU_RX_CTL_median_flt_en(data)                                  (0x80000000&((data)<<31))
#define  DISEQC_DSCU_RX_CTL_dscu_exp_win(data)                                   (0x7FE00000&((data)<<21))
#define  DISEQC_DSCU_RX_CTL_silence_threshold(data)                              (0x001FF800&((data)<<11))
#define  DISEQC_DSCU_RX_CTL_to_val(data)                                         (0x000007F8&((data)<<3))
#define  DISEQC_DSCU_RX_CTL_to_chk(data)                                         (0x00000004&((data)<<2))
#define  DISEQC_DSCU_RX_CTL_rx_pty(data)                                         (0x00000002&((data)<<1))
#define  DISEQC_DSCU_RX_CTL_get_median_flt_en(data)                              ((0x80000000&(data))>>31)
#define  DISEQC_DSCU_RX_CTL_get_dscu_exp_win(data)                               ((0x7FE00000&(data))>>21)
#define  DISEQC_DSCU_RX_CTL_get_silence_threshold(data)                          ((0x001FF800&(data))>>11)
#define  DISEQC_DSCU_RX_CTL_get_to_val(data)                                     ((0x000007F8&(data))>>3)
#define  DISEQC_DSCU_RX_CTL_get_to_chk(data)                                     ((0x00000004&(data))>>2)
#define  DISEQC_DSCU_RX_CTL_get_rx_pty(data)                                     ((0x00000002&(data))>>1)

#define  DISEQC_DSCU_INTR_ENA                                                    0x1807000C
#define  DISEQC_DSCU_INTR_ENA_reg_addr                                           "0xB807000C"
#define  DISEQC_DSCU_INTR_ENA_reg                                                0xB807000C
#define  DISEQC_DSCU_INTR_ENA_inst_addr                                          "0x0003"
#define  set_DISEQC_DSCU_INTR_ENA_reg(data)                                      (*((volatile unsigned int*)DISEQC_DSCU_INTR_ENA_reg)=data)
#define  get_DISEQC_DSCU_INTR_ENA_reg                                            (*((volatile unsigned int*)DISEQC_DSCU_INTR_ENA_reg))
#define  DISEQC_DSCU_INTR_ENA_to_interrupt_ena_shift                             (6)
#define  DISEQC_DSCU_INTR_ENA_tx_msg_done_ena_shift                              (5)
#define  DISEQC_DSCU_INTR_ENA_tx_done_ena_shift                                  (4)
#define  DISEQC_DSCU_INTR_ENA_rx_full_ena_shift                                  (2)
#define  DISEQC_DSCU_INTR_ENA_eorm_ena_shift                                     (1)
#define  DISEQC_DSCU_INTR_ENA_incoming_ena_shift                                 (0)
#define  DISEQC_DSCU_INTR_ENA_to_interrupt_ena_mask                              (0x00000040)
#define  DISEQC_DSCU_INTR_ENA_tx_msg_done_ena_mask                               (0x00000020)
#define  DISEQC_DSCU_INTR_ENA_tx_done_ena_mask                                   (0x00000010)
#define  DISEQC_DSCU_INTR_ENA_rx_full_ena_mask                                   (0x00000004)
#define  DISEQC_DSCU_INTR_ENA_eorm_ena_mask                                      (0x00000002)
#define  DISEQC_DSCU_INTR_ENA_incoming_ena_mask                                  (0x00000001)
#define  DISEQC_DSCU_INTR_ENA_to_interrupt_ena(data)                             (0x00000040&((data)<<6))
#define  DISEQC_DSCU_INTR_ENA_tx_msg_done_ena(data)                              (0x00000020&((data)<<5))
#define  DISEQC_DSCU_INTR_ENA_tx_done_ena(data)                                  (0x00000010&((data)<<4))
#define  DISEQC_DSCU_INTR_ENA_rx_full_ena(data)                                  (0x00000004&((data)<<2))
#define  DISEQC_DSCU_INTR_ENA_eorm_ena(data)                                     (0x00000002&((data)<<1))
#define  DISEQC_DSCU_INTR_ENA_incoming_ena(data)                                 (0x00000001&(data))
#define  DISEQC_DSCU_INTR_ENA_get_to_interrupt_ena(data)                         ((0x00000040&(data))>>6)
#define  DISEQC_DSCU_INTR_ENA_get_tx_msg_done_ena(data)                          ((0x00000020&(data))>>5)
#define  DISEQC_DSCU_INTR_ENA_get_tx_done_ena(data)                              ((0x00000010&(data))>>4)
#define  DISEQC_DSCU_INTR_ENA_get_rx_full_ena(data)                              ((0x00000004&(data))>>2)
#define  DISEQC_DSCU_INTR_ENA_get_eorm_ena(data)                                 ((0x00000002&(data))>>1)
#define  DISEQC_DSCU_INTR_ENA_get_incoming_ena(data)                             (0x00000001&(data))

#define  DISEQC_DSCU_INTR                                                        0x18070010
#define  DISEQC_DSCU_INTR_reg_addr                                               "0xB8070010"
#define  DISEQC_DSCU_INTR_reg                                                    0xB8070010
#define  DISEQC_DSCU_INTR_inst_addr                                              "0x0004"
#define  set_DISEQC_DSCU_INTR_reg(data)                                          (*((volatile unsigned int*)DISEQC_DSCU_INTR_reg)=data)
#define  get_DISEQC_DSCU_INTR_reg                                                (*((volatile unsigned int*)DISEQC_DSCU_INTR_reg))
#define  DISEQC_DSCU_INTR_to_interrupt_int_shift                                 (6)
#define  DISEQC_DSCU_INTR_tx_msg_done_int_shift                                  (5)
#define  DISEQC_DSCU_INTR_tx_done_int_shift                                      (4)
#define  DISEQC_DSCU_INTR_rx_full_int_shift                                      (2)
#define  DISEQC_DSCU_INTR_eorm_int_shift                                         (1)
#define  DISEQC_DSCU_INTR_incoming_int_shift                                     (0)
#define  DISEQC_DSCU_INTR_to_interrupt_int_mask                                  (0x00000040)
#define  DISEQC_DSCU_INTR_tx_msg_done_int_mask                                   (0x00000020)
#define  DISEQC_DSCU_INTR_tx_done_int_mask                                       (0x00000010)
#define  DISEQC_DSCU_INTR_rx_full_int_mask                                       (0x00000004)
#define  DISEQC_DSCU_INTR_eorm_int_mask                                          (0x00000002)
#define  DISEQC_DSCU_INTR_incoming_int_mask                                      (0x00000001)
#define  DISEQC_DSCU_INTR_to_interrupt_int(data)                                 (0x00000040&((data)<<6))
#define  DISEQC_DSCU_INTR_tx_msg_done_int(data)                                  (0x00000020&((data)<<5))
#define  DISEQC_DSCU_INTR_tx_done_int(data)                                      (0x00000010&((data)<<4))
#define  DISEQC_DSCU_INTR_rx_full_int(data)                                      (0x00000004&((data)<<2))
#define  DISEQC_DSCU_INTR_eorm_int(data)                                         (0x00000002&((data)<<1))
#define  DISEQC_DSCU_INTR_incoming_int(data)                                     (0x00000001&(data))
#define  DISEQC_DSCU_INTR_get_to_interrupt_int(data)                             ((0x00000040&(data))>>6)
#define  DISEQC_DSCU_INTR_get_tx_msg_done_int(data)                              ((0x00000020&(data))>>5)
#define  DISEQC_DSCU_INTR_get_tx_done_int(data)                                  ((0x00000010&(data))>>4)
#define  DISEQC_DSCU_INTR_get_rx_full_int(data)                                  ((0x00000004&(data))>>2)
#define  DISEQC_DSCU_INTR_get_eorm_int(data)                                     ((0x00000002&(data))>>1)
#define  DISEQC_DSCU_INTR_get_incoming_int(data)                                 (0x00000001&(data))

#define  DISEQC_DSCU_RX_STATUS                                                   0x18070014
#define  DISEQC_DSCU_RX_STATUS_reg_addr                                          "0xB8070014"
#define  DISEQC_DSCU_RX_STATUS_reg                                               0xB8070014
#define  DISEQC_DSCU_RX_STATUS_inst_addr                                         "0x0005"
#define  set_DISEQC_DSCU_RX_STATUS_reg(data)                                     (*((volatile unsigned int*)DISEQC_DSCU_RX_STATUS_reg)=data)
#define  get_DISEQC_DSCU_RX_STATUS_reg                                           (*((volatile unsigned int*)DISEQC_DSCU_RX_STATUS_reg))
#define  DISEQC_DSCU_RX_STATUS_to_interrupt_shift                                (7)
#define  DISEQC_DSCU_RX_STATUS_rx_count_shift                                    (3)
#define  DISEQC_DSCU_RX_STATUS_rx_full_shift                                     (2)
#define  DISEQC_DSCU_RX_STATUS_eorm_shift                                        (1)
#define  DISEQC_DSCU_RX_STATUS_incoming_shift                                    (0)
#define  DISEQC_DSCU_RX_STATUS_to_interrupt_mask                                 (0x00000080)
#define  DISEQC_DSCU_RX_STATUS_rx_count_mask                                     (0x00000078)
#define  DISEQC_DSCU_RX_STATUS_rx_full_mask                                      (0x00000004)
#define  DISEQC_DSCU_RX_STATUS_eorm_mask                                         (0x00000002)
#define  DISEQC_DSCU_RX_STATUS_incoming_mask                                     (0x00000001)
#define  DISEQC_DSCU_RX_STATUS_to_interrupt(data)                                (0x00000080&((data)<<7))
#define  DISEQC_DSCU_RX_STATUS_rx_count(data)                                    (0x00000078&((data)<<3))
#define  DISEQC_DSCU_RX_STATUS_rx_full(data)                                     (0x00000004&((data)<<2))
#define  DISEQC_DSCU_RX_STATUS_eorm(data)                                        (0x00000002&((data)<<1))
#define  DISEQC_DSCU_RX_STATUS_incoming(data)                                    (0x00000001&(data))
#define  DISEQC_DSCU_RX_STATUS_get_to_interrupt(data)                            ((0x00000080&(data))>>7)
#define  DISEQC_DSCU_RX_STATUS_get_rx_count(data)                                ((0x00000078&(data))>>3)
#define  DISEQC_DSCU_RX_STATUS_get_rx_full(data)                                 ((0x00000004&(data))>>2)
#define  DISEQC_DSCU_RX_STATUS_get_eorm(data)                                    ((0x00000002&(data))>>1)
#define  DISEQC_DSCU_RX_STATUS_get_incoming(data)                                (0x00000001&(data))

#define  DISEQC_DSCU_TX_STATUS                                                   0x18070018
#define  DISEQC_DSCU_TX_STATUS_reg_addr                                          "0xB8070018"
#define  DISEQC_DSCU_TX_STATUS_reg                                               0xB8070018
#define  DISEQC_DSCU_TX_STATUS_inst_addr                                         "0x0006"
#define  set_DISEQC_DSCU_TX_STATUS_reg(data)                                     (*((volatile unsigned int*)DISEQC_DSCU_TX_STATUS_reg)=data)
#define  get_DISEQC_DSCU_TX_STATUS_reg                                           (*((volatile unsigned int*)DISEQC_DSCU_TX_STATUS_reg))
#define  DISEQC_DSCU_TX_STATUS_tx_count_shift                                    (3)
#define  DISEQC_DSCU_TX_STATUS_tx_msg_done_shift                                 (2)
#define  DISEQC_DSCU_TX_STATUS_tx_done_shift                                     (1)
#define  DISEQC_DSCU_TX_STATUS_tx_busy_shift                                     (0)
#define  DISEQC_DSCU_TX_STATUS_tx_count_mask                                     (0x00000078)
#define  DISEQC_DSCU_TX_STATUS_tx_msg_done_mask                                  (0x00000004)
#define  DISEQC_DSCU_TX_STATUS_tx_done_mask                                      (0x00000002)
#define  DISEQC_DSCU_TX_STATUS_tx_busy_mask                                      (0x00000001)
#define  DISEQC_DSCU_TX_STATUS_tx_count(data)                                    (0x00000078&((data)<<3))
#define  DISEQC_DSCU_TX_STATUS_tx_msg_done(data)                                 (0x00000004&((data)<<2))
#define  DISEQC_DSCU_TX_STATUS_tx_done(data)                                     (0x00000002&((data)<<1))
#define  DISEQC_DSCU_TX_STATUS_tx_busy(data)                                     (0x00000001&(data))
#define  DISEQC_DSCU_TX_STATUS_get_tx_count(data)                                ((0x00000078&(data))>>3)
#define  DISEQC_DSCU_TX_STATUS_get_tx_msg_done(data)                             ((0x00000004&(data))>>2)
#define  DISEQC_DSCU_TX_STATUS_get_tx_done(data)                                 ((0x00000002&(data))>>1)
#define  DISEQC_DSCU_TX_STATUS_get_tx_busy(data)                                 (0x00000001&(data))

#define  DISEQC_DSCU_TX_BUF0                                                     0x1807001C
#define  DISEQC_DSCU_TX_BUF0_reg_addr                                            "0xB807001C"
#define  DISEQC_DSCU_TX_BUF0_reg                                                 0xB807001C
#define  DISEQC_DSCU_TX_BUF0_inst_addr                                           "0x0007"
#define  set_DISEQC_DSCU_TX_BUF0_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF0_reg)=data)
#define  get_DISEQC_DSCU_TX_BUF0_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF0_reg))
#define  DISEQC_DSCU_TX_BUF0_dscu_tx_buf_0_shift                                 (0)
#define  DISEQC_DSCU_TX_BUF0_dscu_tx_buf_0_mask                                  (0x000000FF)
#define  DISEQC_DSCU_TX_BUF0_dscu_tx_buf_0(data)                                 (0x000000FF&(data))
#define  DISEQC_DSCU_TX_BUF0_get_dscu_tx_buf_0(data)                             (0x000000FF&(data))

#define  DISEQC_DSCU_TX_BUF1                                                     0x18070020
#define  DISEQC_DSCU_TX_BUF1_reg_addr                                            "0xB8070020"
#define  DISEQC_DSCU_TX_BUF1_reg                                                 0xB8070020
#define  DISEQC_DSCU_TX_BUF1_inst_addr                                           "0x0008"
#define  set_DISEQC_DSCU_TX_BUF1_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF1_reg)=data)
#define  get_DISEQC_DSCU_TX_BUF1_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF1_reg))
#define  DISEQC_DSCU_TX_BUF1_dscu_tx_buf_1_shift                                 (0)
#define  DISEQC_DSCU_TX_BUF1_dscu_tx_buf_1_mask                                  (0x000000FF)
#define  DISEQC_DSCU_TX_BUF1_dscu_tx_buf_1(data)                                 (0x000000FF&(data))
#define  DISEQC_DSCU_TX_BUF1_get_dscu_tx_buf_1(data)                             (0x000000FF&(data))

#define  DISEQC_DSCU_TX_BUF2                                                     0x18070024
#define  DISEQC_DSCU_TX_BUF2_reg_addr                                            "0xB8070024"
#define  DISEQC_DSCU_TX_BUF2_reg                                                 0xB8070024
#define  DISEQC_DSCU_TX_BUF2_inst_addr                                           "0x0009"
#define  set_DISEQC_DSCU_TX_BUF2_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF2_reg)=data)
#define  get_DISEQC_DSCU_TX_BUF2_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF2_reg))
#define  DISEQC_DSCU_TX_BUF2_dscu_tx_buf_2_shift                                 (0)
#define  DISEQC_DSCU_TX_BUF2_dscu_tx_buf_2_mask                                  (0x000000FF)
#define  DISEQC_DSCU_TX_BUF2_dscu_tx_buf_2(data)                                 (0x000000FF&(data))
#define  DISEQC_DSCU_TX_BUF2_get_dscu_tx_buf_2(data)                             (0x000000FF&(data))

#define  DISEQC_DSCU_TX_BUF3                                                     0x18070028
#define  DISEQC_DSCU_TX_BUF3_reg_addr                                            "0xB8070028"
#define  DISEQC_DSCU_TX_BUF3_reg                                                 0xB8070028
#define  DISEQC_DSCU_TX_BUF3_inst_addr                                           "0x000A"
#define  set_DISEQC_DSCU_TX_BUF3_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF3_reg)=data)
#define  get_DISEQC_DSCU_TX_BUF3_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF3_reg))
#define  DISEQC_DSCU_TX_BUF3_dscu_tx_buf_3_shift                                 (0)
#define  DISEQC_DSCU_TX_BUF3_dscu_tx_buf_3_mask                                  (0x000000FF)
#define  DISEQC_DSCU_TX_BUF3_dscu_tx_buf_3(data)                                 (0x000000FF&(data))
#define  DISEQC_DSCU_TX_BUF3_get_dscu_tx_buf_3(data)                             (0x000000FF&(data))

#define  DISEQC_DSCU_TX_BUF4                                                     0x1807002C
#define  DISEQC_DSCU_TX_BUF4_reg_addr                                            "0xB807002C"
#define  DISEQC_DSCU_TX_BUF4_reg                                                 0xB807002C
#define  DISEQC_DSCU_TX_BUF4_inst_addr                                           "0x000B"
#define  set_DISEQC_DSCU_TX_BUF4_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF4_reg)=data)
#define  get_DISEQC_DSCU_TX_BUF4_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF4_reg))
#define  DISEQC_DSCU_TX_BUF4_dscu_tx_buf_4_shift                                 (0)
#define  DISEQC_DSCU_TX_BUF4_dscu_tx_buf_4_mask                                  (0x000000FF)
#define  DISEQC_DSCU_TX_BUF4_dscu_tx_buf_4(data)                                 (0x000000FF&(data))
#define  DISEQC_DSCU_TX_BUF4_get_dscu_tx_buf_4(data)                             (0x000000FF&(data))

#define  DISEQC_DSCU_TX_BUF5                                                     0x18070030
#define  DISEQC_DSCU_TX_BUF5_reg_addr                                            "0xB8070030"
#define  DISEQC_DSCU_TX_BUF5_reg                                                 0xB8070030
#define  DISEQC_DSCU_TX_BUF5_inst_addr                                           "0x000C"
#define  set_DISEQC_DSCU_TX_BUF5_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF5_reg)=data)
#define  get_DISEQC_DSCU_TX_BUF5_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF5_reg))
#define  DISEQC_DSCU_TX_BUF5_dscu_tx_buf_5_shift                                 (0)
#define  DISEQC_DSCU_TX_BUF5_dscu_tx_buf_5_mask                                  (0x000000FF)
#define  DISEQC_DSCU_TX_BUF5_dscu_tx_buf_5(data)                                 (0x000000FF&(data))
#define  DISEQC_DSCU_TX_BUF5_get_dscu_tx_buf_5(data)                             (0x000000FF&(data))

#define  DISEQC_DSCU_TX_BUF6                                                     0x18070034
#define  DISEQC_DSCU_TX_BUF6_reg_addr                                            "0xB8070034"
#define  DISEQC_DSCU_TX_BUF6_reg                                                 0xB8070034
#define  DISEQC_DSCU_TX_BUF6_inst_addr                                           "0x000D"
#define  set_DISEQC_DSCU_TX_BUF6_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF6_reg)=data)
#define  get_DISEQC_DSCU_TX_BUF6_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF6_reg))
#define  DISEQC_DSCU_TX_BUF6_dscu_tx_buf_6_shift                                 (0)
#define  DISEQC_DSCU_TX_BUF6_dscu_tx_buf_6_mask                                  (0x000000FF)
#define  DISEQC_DSCU_TX_BUF6_dscu_tx_buf_6(data)                                 (0x000000FF&(data))
#define  DISEQC_DSCU_TX_BUF6_get_dscu_tx_buf_6(data)                             (0x000000FF&(data))

#define  DISEQC_DSCU_TX_BUF7                                                     0x18070038
#define  DISEQC_DSCU_TX_BUF7_reg_addr                                            "0xB8070038"
#define  DISEQC_DSCU_TX_BUF7_reg                                                 0xB8070038
#define  DISEQC_DSCU_TX_BUF7_inst_addr                                           "0x000E"
#define  set_DISEQC_DSCU_TX_BUF7_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF7_reg)=data)
#define  get_DISEQC_DSCU_TX_BUF7_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_TX_BUF7_reg))
#define  DISEQC_DSCU_TX_BUF7_dscu_tx_buf_7_shift                                 (0)
#define  DISEQC_DSCU_TX_BUF7_dscu_tx_buf_7_mask                                  (0x000000FF)
#define  DISEQC_DSCU_TX_BUF7_dscu_tx_buf_7(data)                                 (0x000000FF&(data))
#define  DISEQC_DSCU_TX_BUF7_get_dscu_tx_buf_7(data)                             (0x000000FF&(data))

#define  DISEQC_DSCU_RX_BUF0                                                     0x1807003C
#define  DISEQC_DSCU_RX_BUF0_reg_addr                                            "0xB807003C"
#define  DISEQC_DSCU_RX_BUF0_reg                                                 0xB807003C
#define  DISEQC_DSCU_RX_BUF0_inst_addr                                           "0x000F"
#define  set_DISEQC_DSCU_RX_BUF0_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF0_reg)=data)
#define  get_DISEQC_DSCU_RX_BUF0_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF0_reg))
#define  DISEQC_DSCU_RX_BUF0_perr0_shift                                         (9)
#define  DISEQC_DSCU_RX_BUF0_pty0_shift                                          (8)
#define  DISEQC_DSCU_RX_BUF0_byte0_shift                                         (0)
#define  DISEQC_DSCU_RX_BUF0_perr0_mask                                          (0x00000200)
#define  DISEQC_DSCU_RX_BUF0_pty0_mask                                           (0x00000100)
#define  DISEQC_DSCU_RX_BUF0_byte0_mask                                          (0x000000FF)
#define  DISEQC_DSCU_RX_BUF0_perr0(data)                                         (0x00000200&((data)<<9))
#define  DISEQC_DSCU_RX_BUF0_pty0(data)                                          (0x00000100&((data)<<8))
#define  DISEQC_DSCU_RX_BUF0_byte0(data)                                         (0x000000FF&(data))
#define  DISEQC_DSCU_RX_BUF0_get_perr0(data)                                     ((0x00000200&(data))>>9)
#define  DISEQC_DSCU_RX_BUF0_get_pty0(data)                                      ((0x00000100&(data))>>8)
#define  DISEQC_DSCU_RX_BUF0_get_byte0(data)                                     (0x000000FF&(data))

#define  DISEQC_DSCU_RX_BUF1                                                     0x18070040
#define  DISEQC_DSCU_RX_BUF1_reg_addr                                            "0xB8070040"
#define  DISEQC_DSCU_RX_BUF1_reg                                                 0xB8070040
#define  DISEQC_DSCU_RX_BUF1_inst_addr                                           "0x0010"
#define  set_DISEQC_DSCU_RX_BUF1_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF1_reg)=data)
#define  get_DISEQC_DSCU_RX_BUF1_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF1_reg))
#define  DISEQC_DSCU_RX_BUF1_perr1_shift                                         (9)
#define  DISEQC_DSCU_RX_BUF1_pty1_shift                                          (8)
#define  DISEQC_DSCU_RX_BUF1_byte1_shift                                         (0)
#define  DISEQC_DSCU_RX_BUF1_perr1_mask                                          (0x00000200)
#define  DISEQC_DSCU_RX_BUF1_pty1_mask                                           (0x00000100)
#define  DISEQC_DSCU_RX_BUF1_byte1_mask                                          (0x000000FF)
#define  DISEQC_DSCU_RX_BUF1_perr1(data)                                         (0x00000200&((data)<<9))
#define  DISEQC_DSCU_RX_BUF1_pty1(data)                                          (0x00000100&((data)<<8))
#define  DISEQC_DSCU_RX_BUF1_byte1(data)                                         (0x000000FF&(data))
#define  DISEQC_DSCU_RX_BUF1_get_perr1(data)                                     ((0x00000200&(data))>>9)
#define  DISEQC_DSCU_RX_BUF1_get_pty1(data)                                      ((0x00000100&(data))>>8)
#define  DISEQC_DSCU_RX_BUF1_get_byte1(data)                                     (0x000000FF&(data))

#define  DISEQC_DSCU_RX_BUF2                                                     0x18070044
#define  DISEQC_DSCU_RX_BUF2_reg_addr                                            "0xB8070044"
#define  DISEQC_DSCU_RX_BUF2_reg                                                 0xB8070044
#define  DISEQC_DSCU_RX_BUF2_inst_addr                                           "0x0011"
#define  set_DISEQC_DSCU_RX_BUF2_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF2_reg)=data)
#define  get_DISEQC_DSCU_RX_BUF2_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF2_reg))
#define  DISEQC_DSCU_RX_BUF2_perr2_shift                                         (9)
#define  DISEQC_DSCU_RX_BUF2_pty2_shift                                          (8)
#define  DISEQC_DSCU_RX_BUF2_byte2_shift                                         (0)
#define  DISEQC_DSCU_RX_BUF2_perr2_mask                                          (0x00000200)
#define  DISEQC_DSCU_RX_BUF2_pty2_mask                                           (0x00000100)
#define  DISEQC_DSCU_RX_BUF2_byte2_mask                                          (0x000000FF)
#define  DISEQC_DSCU_RX_BUF2_perr2(data)                                         (0x00000200&((data)<<9))
#define  DISEQC_DSCU_RX_BUF2_pty2(data)                                          (0x00000100&((data)<<8))
#define  DISEQC_DSCU_RX_BUF2_byte2(data)                                         (0x000000FF&(data))
#define  DISEQC_DSCU_RX_BUF2_get_perr2(data)                                     ((0x00000200&(data))>>9)
#define  DISEQC_DSCU_RX_BUF2_get_pty2(data)                                      ((0x00000100&(data))>>8)
#define  DISEQC_DSCU_RX_BUF2_get_byte2(data)                                     (0x000000FF&(data))

#define  DISEQC_DSCU_RX_BUF3                                                     0x18070048
#define  DISEQC_DSCU_RX_BUF3_reg_addr                                            "0xB8070048"
#define  DISEQC_DSCU_RX_BUF3_reg                                                 0xB8070048
#define  DISEQC_DSCU_RX_BUF3_inst_addr                                           "0x0012"
#define  set_DISEQC_DSCU_RX_BUF3_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF3_reg)=data)
#define  get_DISEQC_DSCU_RX_BUF3_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF3_reg))
#define  DISEQC_DSCU_RX_BUF3_perr3_shift                                         (9)
#define  DISEQC_DSCU_RX_BUF3_pty3_shift                                          (8)
#define  DISEQC_DSCU_RX_BUF3_byte3_shift                                         (0)
#define  DISEQC_DSCU_RX_BUF3_perr3_mask                                          (0x00000200)
#define  DISEQC_DSCU_RX_BUF3_pty3_mask                                           (0x00000100)
#define  DISEQC_DSCU_RX_BUF3_byte3_mask                                          (0x000000FF)
#define  DISEQC_DSCU_RX_BUF3_perr3(data)                                         (0x00000200&((data)<<9))
#define  DISEQC_DSCU_RX_BUF3_pty3(data)                                          (0x00000100&((data)<<8))
#define  DISEQC_DSCU_RX_BUF3_byte3(data)                                         (0x000000FF&(data))
#define  DISEQC_DSCU_RX_BUF3_get_perr3(data)                                     ((0x00000200&(data))>>9)
#define  DISEQC_DSCU_RX_BUF3_get_pty3(data)                                      ((0x00000100&(data))>>8)
#define  DISEQC_DSCU_RX_BUF3_get_byte3(data)                                     (0x000000FF&(data))

#define  DISEQC_DSCU_RX_BUF4                                                     0x1807004C
#define  DISEQC_DSCU_RX_BUF4_reg_addr                                            "0xB807004C"
#define  DISEQC_DSCU_RX_BUF4_reg                                                 0xB807004C
#define  DISEQC_DSCU_RX_BUF4_inst_addr                                           "0x0013"
#define  set_DISEQC_DSCU_RX_BUF4_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF4_reg)=data)
#define  get_DISEQC_DSCU_RX_BUF4_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF4_reg))
#define  DISEQC_DSCU_RX_BUF4_perr4_shift                                         (9)
#define  DISEQC_DSCU_RX_BUF4_pty4_shift                                          (8)
#define  DISEQC_DSCU_RX_BUF4_byte4_shift                                         (0)
#define  DISEQC_DSCU_RX_BUF4_perr4_mask                                          (0x00000200)
#define  DISEQC_DSCU_RX_BUF4_pty4_mask                                           (0x00000100)
#define  DISEQC_DSCU_RX_BUF4_byte4_mask                                          (0x000000FF)
#define  DISEQC_DSCU_RX_BUF4_perr4(data)                                         (0x00000200&((data)<<9))
#define  DISEQC_DSCU_RX_BUF4_pty4(data)                                          (0x00000100&((data)<<8))
#define  DISEQC_DSCU_RX_BUF4_byte4(data)                                         (0x000000FF&(data))
#define  DISEQC_DSCU_RX_BUF4_get_perr4(data)                                     ((0x00000200&(data))>>9)
#define  DISEQC_DSCU_RX_BUF4_get_pty4(data)                                      ((0x00000100&(data))>>8)
#define  DISEQC_DSCU_RX_BUF4_get_byte4(data)                                     (0x000000FF&(data))

#define  DISEQC_DSCU_RX_BUF5                                                     0x18070050
#define  DISEQC_DSCU_RX_BUF5_reg_addr                                            "0xB8070050"
#define  DISEQC_DSCU_RX_BUF5_reg                                                 0xB8070050
#define  DISEQC_DSCU_RX_BUF5_inst_addr                                           "0x0014"
#define  set_DISEQC_DSCU_RX_BUF5_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF5_reg)=data)
#define  get_DISEQC_DSCU_RX_BUF5_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF5_reg))
#define  DISEQC_DSCU_RX_BUF5_perr5_shift                                         (9)
#define  DISEQC_DSCU_RX_BUF5_pty5_shift                                          (8)
#define  DISEQC_DSCU_RX_BUF5_byte5_shift                                         (0)
#define  DISEQC_DSCU_RX_BUF5_perr5_mask                                          (0x00000200)
#define  DISEQC_DSCU_RX_BUF5_pty5_mask                                           (0x00000100)
#define  DISEQC_DSCU_RX_BUF5_byte5_mask                                          (0x000000FF)
#define  DISEQC_DSCU_RX_BUF5_perr5(data)                                         (0x00000200&((data)<<9))
#define  DISEQC_DSCU_RX_BUF5_pty5(data)                                          (0x00000100&((data)<<8))
#define  DISEQC_DSCU_RX_BUF5_byte5(data)                                         (0x000000FF&(data))
#define  DISEQC_DSCU_RX_BUF5_get_perr5(data)                                     ((0x00000200&(data))>>9)
#define  DISEQC_DSCU_RX_BUF5_get_pty5(data)                                      ((0x00000100&(data))>>8)
#define  DISEQC_DSCU_RX_BUF5_get_byte5(data)                                     (0x000000FF&(data))

#define  DISEQC_DSCU_RX_BUF6                                                     0x18070054
#define  DISEQC_DSCU_RX_BUF6_reg_addr                                            "0xB8070054"
#define  DISEQC_DSCU_RX_BUF6_reg                                                 0xB8070054
#define  DISEQC_DSCU_RX_BUF6_inst_addr                                           "0x0015"
#define  set_DISEQC_DSCU_RX_BUF6_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF6_reg)=data)
#define  get_DISEQC_DSCU_RX_BUF6_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF6_reg))
#define  DISEQC_DSCU_RX_BUF6_perr6_shift                                         (9)
#define  DISEQC_DSCU_RX_BUF6_pty6_shift                                          (8)
#define  DISEQC_DSCU_RX_BUF6_byte6_shift                                         (0)
#define  DISEQC_DSCU_RX_BUF6_perr6_mask                                          (0x00000200)
#define  DISEQC_DSCU_RX_BUF6_pty6_mask                                           (0x00000100)
#define  DISEQC_DSCU_RX_BUF6_byte6_mask                                          (0x000000FF)
#define  DISEQC_DSCU_RX_BUF6_perr6(data)                                         (0x00000200&((data)<<9))
#define  DISEQC_DSCU_RX_BUF6_pty6(data)                                          (0x00000100&((data)<<8))
#define  DISEQC_DSCU_RX_BUF6_byte6(data)                                         (0x000000FF&(data))
#define  DISEQC_DSCU_RX_BUF6_get_perr6(data)                                     ((0x00000200&(data))>>9)
#define  DISEQC_DSCU_RX_BUF6_get_pty6(data)                                      ((0x00000100&(data))>>8)
#define  DISEQC_DSCU_RX_BUF6_get_byte6(data)                                     (0x000000FF&(data))

#define  DISEQC_DSCU_RX_BUF7                                                     0x18070058
#define  DISEQC_DSCU_RX_BUF7_reg_addr                                            "0xB8070058"
#define  DISEQC_DSCU_RX_BUF7_reg                                                 0xB8070058
#define  DISEQC_DSCU_RX_BUF7_inst_addr                                           "0x0016"
#define  set_DISEQC_DSCU_RX_BUF7_reg(data)                                       (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF7_reg)=data)
#define  get_DISEQC_DSCU_RX_BUF7_reg                                             (*((volatile unsigned int*)DISEQC_DSCU_RX_BUF7_reg))
#define  DISEQC_DSCU_RX_BUF7_perr7_shift                                         (9)
#define  DISEQC_DSCU_RX_BUF7_pty7_shift                                          (8)
#define  DISEQC_DSCU_RX_BUF7_byte7_shift                                         (0)
#define  DISEQC_DSCU_RX_BUF7_perr7_mask                                          (0x00000200)
#define  DISEQC_DSCU_RX_BUF7_pty7_mask                                           (0x00000100)
#define  DISEQC_DSCU_RX_BUF7_byte7_mask                                          (0x000000FF)
#define  DISEQC_DSCU_RX_BUF7_perr7(data)                                         (0x00000200&((data)<<9))
#define  DISEQC_DSCU_RX_BUF7_pty7(data)                                          (0x00000100&((data)<<8))
#define  DISEQC_DSCU_RX_BUF7_byte7(data)                                         (0x000000FF&(data))
#define  DISEQC_DSCU_RX_BUF7_get_perr7(data)                                     ((0x00000200&(data))>>9)
#define  DISEQC_DSCU_RX_BUF7_get_pty7(data)                                      ((0x00000100&(data))>>8)
#define  DISEQC_DSCU_RX_BUF7_get_byte7(data)                                     (0x000000FF&(data))

#define  DISEQC_DSCU_FLT                                                         0x1807005C
#define  DISEQC_DSCU_FLT_reg_addr                                                "0xB807005C"
#define  DISEQC_DSCU_FLT_reg                                                     0xB807005C
#define  DISEQC_DSCU_FLT_inst_addr                                               "0x0017"
#define  set_DISEQC_DSCU_FLT_reg(data)                                           (*((volatile unsigned int*)DISEQC_DSCU_FLT_reg)=data)
#define  get_DISEQC_DSCU_FLT_reg                                                 (*((volatile unsigned int*)DISEQC_DSCU_FLT_reg))
#define  DISEQC_DSCU_FLT_high_low_time_window_shift                              (12)
#define  DISEQC_DSCU_FLT_threshold_shift                                         (2)
#define  DISEQC_DSCU_FLT_src_shift                                               (0)
#define  DISEQC_DSCU_FLT_high_low_time_window_mask                               (0x0007F000)
#define  DISEQC_DSCU_FLT_threshold_mask                                          (0x00000FFC)
#define  DISEQC_DSCU_FLT_src_mask                                                (0x00000003)
#define  DISEQC_DSCU_FLT_high_low_time_window(data)                              (0x0007F000&((data)<<12))
#define  DISEQC_DSCU_FLT_threshold(data)                                         (0x00000FFC&((data)<<2))
#define  DISEQC_DSCU_FLT_src(data)                                               (0x00000003&(data))
#define  DISEQC_DSCU_FLT_get_high_low_time_window(data)                          ((0x0007F000&(data))>>12)
#define  DISEQC_DSCU_FLT_get_threshold(data)                                     ((0x00000FFC&(data))>>2)
#define  DISEQC_DSCU_FLT_get_src(data)                                           (0x00000003&(data))

#define  DISEQC_DSCU_INIT_EXP_WIN                                                0x18070060
#define  DISEQC_DSCU_INIT_EXP_WIN_reg_addr                                       "0xB8070060"
#define  DISEQC_DSCU_INIT_EXP_WIN_reg                                            0xB8070060
#define  DISEQC_DSCU_INIT_EXP_WIN_inst_addr                                      "0x0018"
#define  set_DISEQC_DSCU_INIT_EXP_WIN_reg(data)                                  (*((volatile unsigned int*)DISEQC_DSCU_INIT_EXP_WIN_reg)=data)
#define  get_DISEQC_DSCU_INIT_EXP_WIN_reg                                        (*((volatile unsigned int*)DISEQC_DSCU_INIT_EXP_WIN_reg))
#define  DISEQC_DSCU_INIT_EXP_WIN_initial_expected_window_shift                  (0)
#define  DISEQC_DSCU_INIT_EXP_WIN_initial_expected_window_mask                   (0x001FFFFF)
#define  DISEQC_DSCU_INIT_EXP_WIN_initial_expected_window(data)                  (0x001FFFFF&(data))
#define  DISEQC_DSCU_INIT_EXP_WIN_get_initial_expected_window(data)              (0x001FFFFF&(data))

#define  DISEQC_DSCU_PM_SEL                                                      0x18070064
#define  DISEQC_DSCU_PM_SEL_reg_addr                                             "0xB8070064"
#define  DISEQC_DSCU_PM_SEL_reg                                                  0xB8070064
#define  DISEQC_DSCU_PM_SEL_inst_addr                                            "0x0019"
#define  set_DISEQC_DSCU_PM_SEL_reg(data)                                        (*((volatile unsigned int*)DISEQC_DSCU_PM_SEL_reg)=data)
#define  get_DISEQC_DSCU_PM_SEL_reg                                              (*((volatile unsigned int*)DISEQC_DSCU_PM_SEL_reg))
#define  DISEQC_DSCU_PM_SEL_dsc_pm_sel_shift                                     (0)
#define  DISEQC_DSCU_PM_SEL_dsc_pm_sel_mask                                      (0x00000003)
#define  DISEQC_DSCU_PM_SEL_dsc_pm_sel(data)                                     (0x00000003&(data))
#define  DISEQC_DSCU_PM_SEL_get_dsc_pm_sel(data)                                 (0x00000003&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DISEQC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dsc_pol_od_ctrl:1;
        RBus_UInt32  dsc_22k_od_ctrl:1;
        RBus_UInt32  eorm_timeout_reg:4;
        RBus_UInt32  mili_second_define:19;
        RBus_UInt32  lnb_pol:1;
        RBus_UInt32  int_en:1;
        RBus_UInt32  level:2;
        RBus_UInt32  res2:1;
    };
}diseqc_dscu_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loop_back_mode:1;
        RBus_UInt32  listen_dly:4;
        RBus_UInt32  third_bit:5;
        RBus_UInt32  eot_len:5;
        RBus_UInt32  tx_pty:1;
        RBus_UInt32  xmt_mode:2;
        RBus_UInt32  msg_len:3;
        RBus_UInt32  tx_go:1;
        RBus_UInt32  tone_div:10;
    };
}diseqc_dscu_tx_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  median_flt_en:1;
        RBus_UInt32  dscu_exp_win:10;
        RBus_UInt32  silence_threshold:10;
        RBus_UInt32  to_val:8;
        RBus_UInt32  to_chk:1;
        RBus_UInt32  rx_pty:1;
        RBus_UInt32  res1:1;
    };
}diseqc_dscu_rx_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  to_interrupt_ena:1;
        RBus_UInt32  tx_msg_done_ena:1;
        RBus_UInt32  tx_done_ena:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rx_full_ena:1;
        RBus_UInt32  eorm_ena:1;
        RBus_UInt32  incoming_ena:1;
    };
}diseqc_dscu_intr_ena_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  to_interrupt_int:1;
        RBus_UInt32  tx_msg_done_int:1;
        RBus_UInt32  tx_done_int:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rx_full_int:1;
        RBus_UInt32  eorm_int:1;
        RBus_UInt32  incoming_int:1;
    };
}diseqc_dscu_intr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  to_interrupt:1;
        RBus_UInt32  rx_count:4;
        RBus_UInt32  rx_full:1;
        RBus_UInt32  eorm:1;
        RBus_UInt32  incoming:1;
    };
}diseqc_dscu_rx_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  tx_count:4;
        RBus_UInt32  tx_msg_done:1;
        RBus_UInt32  tx_done:1;
        RBus_UInt32  tx_busy:1;
    };
}diseqc_dscu_tx_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dscu_tx_buf_0:8;
    };
}diseqc_dscu_tx_buf0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dscu_tx_buf_1:8;
    };
}diseqc_dscu_tx_buf1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dscu_tx_buf_2:8;
    };
}diseqc_dscu_tx_buf2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dscu_tx_buf_3:8;
    };
}diseqc_dscu_tx_buf3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dscu_tx_buf_4:8;
    };
}diseqc_dscu_tx_buf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dscu_tx_buf_5:8;
    };
}diseqc_dscu_tx_buf5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dscu_tx_buf_6:8;
    };
}diseqc_dscu_tx_buf6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dscu_tx_buf_7:8;
    };
}diseqc_dscu_tx_buf7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  perr0:1;
        RBus_UInt32  pty0:1;
        RBus_UInt32  byte0:8;
    };
}diseqc_dscu_rx_buf0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  perr1:1;
        RBus_UInt32  pty1:1;
        RBus_UInt32  byte1:8;
    };
}diseqc_dscu_rx_buf1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  perr2:1;
        RBus_UInt32  pty2:1;
        RBus_UInt32  byte2:8;
    };
}diseqc_dscu_rx_buf2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  perr3:1;
        RBus_UInt32  pty3:1;
        RBus_UInt32  byte3:8;
    };
}diseqc_dscu_rx_buf3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  perr4:1;
        RBus_UInt32  pty4:1;
        RBus_UInt32  byte4:8;
    };
}diseqc_dscu_rx_buf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  perr5:1;
        RBus_UInt32  pty5:1;
        RBus_UInt32  byte5:8;
    };
}diseqc_dscu_rx_buf5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  perr6:1;
        RBus_UInt32  pty6:1;
        RBus_UInt32  byte6:8;
    };
}diseqc_dscu_rx_buf6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  perr7:1;
        RBus_UInt32  pty7:1;
        RBus_UInt32  byte7:8;
    };
}diseqc_dscu_rx_buf7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  high_low_time_window:7;
        RBus_UInt32  threshold:10;
        RBus_UInt32  src:2;
    };
}diseqc_dscu_flt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  initial_expected_window:21;
    };
}diseqc_dscu_init_exp_win_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dsc_pm_sel:2;
    };
}diseqc_dscu_pm_sel_RBUS;

#else //apply LITTLE_ENDIAN

//======DISEQC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  level:2;
        RBus_UInt32  int_en:1;
        RBus_UInt32  lnb_pol:1;
        RBus_UInt32  mili_second_define:19;
        RBus_UInt32  eorm_timeout_reg:4;
        RBus_UInt32  dsc_22k_od_ctrl:1;
        RBus_UInt32  dsc_pol_od_ctrl:1;
        RBus_UInt32  res2:2;
    };
}diseqc_dscu_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tone_div:10;
        RBus_UInt32  tx_go:1;
        RBus_UInt32  msg_len:3;
        RBus_UInt32  xmt_mode:2;
        RBus_UInt32  tx_pty:1;
        RBus_UInt32  eot_len:5;
        RBus_UInt32  third_bit:5;
        RBus_UInt32  listen_dly:4;
        RBus_UInt32  loop_back_mode:1;
    };
}diseqc_dscu_tx_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rx_pty:1;
        RBus_UInt32  to_chk:1;
        RBus_UInt32  to_val:8;
        RBus_UInt32  silence_threshold:10;
        RBus_UInt32  dscu_exp_win:10;
        RBus_UInt32  median_flt_en:1;
    };
}diseqc_dscu_rx_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  incoming_ena:1;
        RBus_UInt32  eorm_ena:1;
        RBus_UInt32  rx_full_ena:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  tx_done_ena:1;
        RBus_UInt32  tx_msg_done_ena:1;
        RBus_UInt32  to_interrupt_ena:1;
        RBus_UInt32  res2:25;
    };
}diseqc_dscu_intr_ena_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  incoming_int:1;
        RBus_UInt32  eorm_int:1;
        RBus_UInt32  rx_full_int:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  tx_done_int:1;
        RBus_UInt32  tx_msg_done_int:1;
        RBus_UInt32  to_interrupt_int:1;
        RBus_UInt32  res2:25;
    };
}diseqc_dscu_intr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  incoming:1;
        RBus_UInt32  eorm:1;
        RBus_UInt32  rx_full:1;
        RBus_UInt32  rx_count:4;
        RBus_UInt32  to_interrupt:1;
        RBus_UInt32  res1:24;
    };
}diseqc_dscu_rx_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_busy:1;
        RBus_UInt32  tx_done:1;
        RBus_UInt32  tx_msg_done:1;
        RBus_UInt32  tx_count:4;
        RBus_UInt32  res1:25;
    };
}diseqc_dscu_tx_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dscu_tx_buf_0:8;
        RBus_UInt32  res1:24;
    };
}diseqc_dscu_tx_buf0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dscu_tx_buf_1:8;
        RBus_UInt32  res1:24;
    };
}diseqc_dscu_tx_buf1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dscu_tx_buf_2:8;
        RBus_UInt32  res1:24;
    };
}diseqc_dscu_tx_buf2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dscu_tx_buf_3:8;
        RBus_UInt32  res1:24;
    };
}diseqc_dscu_tx_buf3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dscu_tx_buf_4:8;
        RBus_UInt32  res1:24;
    };
}diseqc_dscu_tx_buf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dscu_tx_buf_5:8;
        RBus_UInt32  res1:24;
    };
}diseqc_dscu_tx_buf5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dscu_tx_buf_6:8;
        RBus_UInt32  res1:24;
    };
}diseqc_dscu_tx_buf6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dscu_tx_buf_7:8;
        RBus_UInt32  res1:24;
    };
}diseqc_dscu_tx_buf7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte0:8;
        RBus_UInt32  pty0:1;
        RBus_UInt32  perr0:1;
        RBus_UInt32  res1:22;
    };
}diseqc_dscu_rx_buf0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte1:8;
        RBus_UInt32  pty1:1;
        RBus_UInt32  perr1:1;
        RBus_UInt32  res1:22;
    };
}diseqc_dscu_rx_buf1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte2:8;
        RBus_UInt32  pty2:1;
        RBus_UInt32  perr2:1;
        RBus_UInt32  res1:22;
    };
}diseqc_dscu_rx_buf2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte3:8;
        RBus_UInt32  pty3:1;
        RBus_UInt32  perr3:1;
        RBus_UInt32  res1:22;
    };
}diseqc_dscu_rx_buf3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte4:8;
        RBus_UInt32  pty4:1;
        RBus_UInt32  perr4:1;
        RBus_UInt32  res1:22;
    };
}diseqc_dscu_rx_buf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte5:8;
        RBus_UInt32  pty5:1;
        RBus_UInt32  perr5:1;
        RBus_UInt32  res1:22;
    };
}diseqc_dscu_rx_buf5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte6:8;
        RBus_UInt32  pty6:1;
        RBus_UInt32  perr6:1;
        RBus_UInt32  res1:22;
    };
}diseqc_dscu_rx_buf6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte7:8;
        RBus_UInt32  pty7:1;
        RBus_UInt32  perr7:1;
        RBus_UInt32  res1:22;
    };
}diseqc_dscu_rx_buf7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src:2;
        RBus_UInt32  threshold:10;
        RBus_UInt32  high_low_time_window:7;
        RBus_UInt32  res1:13;
    };
}diseqc_dscu_flt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  initial_expected_window:21;
        RBus_UInt32  res1:11;
    };
}diseqc_dscu_init_exp_win_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dsc_pm_sel:2;
        RBus_UInt32  res1:30;
    };
}diseqc_dscu_pm_sel_RBUS;




#endif 


#endif 
