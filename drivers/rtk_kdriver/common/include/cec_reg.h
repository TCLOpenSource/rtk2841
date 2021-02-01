/**
* @file rbusCECReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_CEC_REG_H_
#define _RBUS_CEC_REG_H_

#include "rbus_types.h"



//  CEC Register Address
#define  CEC_CEC_CR0                                                             0x18061E00
#define  CEC_CEC_CR0_reg_addr                                                    "0xB8061E00"
#define  CEC_CEC_CR0_reg                                                         0xB8061E00
#define  CEC_CEC_CR0_inst_addr                                                   "0x0000"
#define  set_CEC_CEC_CR0_reg(data)                                               (*((volatile unsigned int*)CEC_CEC_CR0_reg)=data)
#define  get_CEC_CEC_CR0_reg                                                     (*((volatile unsigned int*)CEC_CEC_CR0_reg))
#define  CEC_CEC_CR0_cec_mode_shift                                              (30)
#define  CEC_CEC_CR0_test_mode_pad_en_shift                                      (28)
#define  CEC_CEC_CR0_logical_addr_shift                                          (24)
#define  CEC_CEC_CR0_timer_div_shift                                             (16)
#define  CEC_CEC_CR0_pre_div_shift                                               (8)
#define  CEC_CEC_CR0_unreg_ack_en_shift                                          (7)
#define  CEC_CEC_CR0_cec_in_deb_mode_shift                                       (6)
#define  CEC_CEC_CR0_cdc_arbitration_en_shift                                    (5)
#define  CEC_CEC_CR0_test_mode_pad_data_shift                                    (0)
#define  CEC_CEC_CR0_cec_mode_mask                                               (0xC0000000)
#define  CEC_CEC_CR0_test_mode_pad_en_mask                                       (0x10000000)
#define  CEC_CEC_CR0_logical_addr_mask                                           (0x0F000000)
#define  CEC_CEC_CR0_timer_div_mask                                              (0x00FF0000)
#define  CEC_CEC_CR0_pre_div_mask                                                (0x0000FF00)
#define  CEC_CEC_CR0_unreg_ack_en_mask                                           (0x00000080)
#define  CEC_CEC_CR0_cec_in_deb_mode_mask                                        (0x00000040)
#define  CEC_CEC_CR0_cdc_arbitration_en_mask                                     (0x00000020)
#define  CEC_CEC_CR0_test_mode_pad_data_mask                                     (0x0000001F)
#define  CEC_CEC_CR0_cec_mode(data)                                              (0xC0000000&((data)<<30))
#define  CEC_CEC_CR0_test_mode_pad_en(data)                                      (0x10000000&((data)<<28))
#define  CEC_CEC_CR0_logical_addr(data)                                          (0x0F000000&((data)<<24))
#define  CEC_CEC_CR0_timer_div(data)                                             (0x00FF0000&((data)<<16))
#define  CEC_CEC_CR0_pre_div(data)                                               (0x0000FF00&((data)<<8))
#define  CEC_CEC_CR0_unreg_ack_en(data)                                          (0x00000080&((data)<<7))
#define  CEC_CEC_CR0_cec_in_deb_mode(data)                                       (0x00000040&((data)<<6))
#define  CEC_CEC_CR0_cdc_arbitration_en(data)                                    (0x00000020&((data)<<5))
#define  CEC_CEC_CR0_test_mode_pad_data(data)                                    (0x0000001F&(data))
#define  CEC_CEC_CR0_get_cec_mode(data)                                          ((0xC0000000&(data))>>30)
#define  CEC_CEC_CR0_get_test_mode_pad_en(data)                                  ((0x10000000&(data))>>28)
#define  CEC_CEC_CR0_get_logical_addr(data)                                      ((0x0F000000&(data))>>24)
#define  CEC_CEC_CR0_get_timer_div(data)                                         ((0x00FF0000&(data))>>16)
#define  CEC_CEC_CR0_get_pre_div(data)                                           ((0x0000FF00&(data))>>8)
#define  CEC_CEC_CR0_get_unreg_ack_en(data)                                      ((0x00000080&(data))>>7)
#define  CEC_CEC_CR0_get_cec_in_deb_mode(data)                                   ((0x00000040&(data))>>6)
#define  CEC_CEC_CR0_get_cdc_arbitration_en(data)                                ((0x00000020&(data))>>5)
#define  CEC_CEC_CR0_get_test_mode_pad_data(data)                                (0x0000001F&(data))

#define  CEC_CEC_RTCR0                                                           0x18061E04
#define  CEC_CEC_RTCR0_reg_addr                                                  "0xB8061E04"
#define  CEC_CEC_RTCR0_reg                                                       0xB8061E04
#define  CEC_CEC_RTCR0_inst_addr                                                 "0x0001"
#define  set_CEC_CEC_RTCR0_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_RTCR0_reg)=data)
#define  get_CEC_CEC_RTCR0_reg                                                   (*((volatile unsigned int*)CEC_CEC_RTCR0_reg))
#define  CEC_CEC_RTCR0_cec_pad_in_shift                                          (31)
#define  CEC_CEC_RTCR0_dummy_30_18_shift                                         (18)
#define  CEC_CEC_RTCR0_cec_pad_en_shift                                          (17)
#define  CEC_CEC_RTCR0_cec_pad_en_mode_shift                                     (16)
#define  CEC_CEC_RTCR0_dummy_15_14_shift                                         (14)
#define  CEC_CEC_RTCR0_cec_hw_retry_mode_shift                                   (13)
#define  CEC_CEC_RTCR0_cec_hw_retry_en_shift                                     (12)
#define  CEC_CEC_RTCR0_clear_cec_int_shift                                       (11)
#define  CEC_CEC_RTCR0_wt_cnt_shift                                              (5)
#define  CEC_CEC_RTCR0_lattest_shift                                             (4)
#define  CEC_CEC_RTCR0_retry_no_shift                                            (0)
#define  CEC_CEC_RTCR0_cec_pad_in_mask                                           (0x80000000)
#define  CEC_CEC_RTCR0_dummy_30_18_mask                                          (0x7FFC0000)
#define  CEC_CEC_RTCR0_cec_pad_en_mask                                           (0x00020000)
#define  CEC_CEC_RTCR0_cec_pad_en_mode_mask                                      (0x00010000)
#define  CEC_CEC_RTCR0_dummy_15_14_mask                                          (0x0000C000)
#define  CEC_CEC_RTCR0_cec_hw_retry_mode_mask                                    (0x00002000)
#define  CEC_CEC_RTCR0_cec_hw_retry_en_mask                                      (0x00001000)
#define  CEC_CEC_RTCR0_clear_cec_int_mask                                        (0x00000800)
#define  CEC_CEC_RTCR0_wt_cnt_mask                                               (0x000007E0)
#define  CEC_CEC_RTCR0_lattest_mask                                              (0x00000010)
#define  CEC_CEC_RTCR0_retry_no_mask                                             (0x0000000F)
#define  CEC_CEC_RTCR0_cec_pad_in(data)                                          (0x80000000&((data)<<31))
#define  CEC_CEC_RTCR0_dummy_30_18(data)                                         (0x7FFC0000&((data)<<18))
#define  CEC_CEC_RTCR0_cec_pad_en(data)                                          (0x00020000&((data)<<17))
#define  CEC_CEC_RTCR0_cec_pad_en_mode(data)                                     (0x00010000&((data)<<16))
#define  CEC_CEC_RTCR0_dummy_15_14(data)                                         (0x0000C000&((data)<<14))
#define  CEC_CEC_RTCR0_cec_hw_retry_mode(data)                                   (0x00002000&((data)<<13))
#define  CEC_CEC_RTCR0_cec_hw_retry_en(data)                                     (0x00001000&((data)<<12))
#define  CEC_CEC_RTCR0_clear_cec_int(data)                                       (0x00000800&((data)<<11))
#define  CEC_CEC_RTCR0_wt_cnt(data)                                              (0x000007E0&((data)<<5))
#define  CEC_CEC_RTCR0_lattest(data)                                             (0x00000010&((data)<<4))
#define  CEC_CEC_RTCR0_retry_no(data)                                            (0x0000000F&(data))
#define  CEC_CEC_RTCR0_get_cec_pad_in(data)                                      ((0x80000000&(data))>>31)
#define  CEC_CEC_RTCR0_get_dummy_30_18(data)                                     ((0x7FFC0000&(data))>>18)
#define  CEC_CEC_RTCR0_get_cec_pad_en(data)                                      ((0x00020000&(data))>>17)
#define  CEC_CEC_RTCR0_get_cec_pad_en_mode(data)                                 ((0x00010000&(data))>>16)
#define  CEC_CEC_RTCR0_get_dummy_15_14(data)                                     ((0x0000C000&(data))>>14)
#define  CEC_CEC_RTCR0_get_cec_hw_retry_mode(data)                               ((0x00002000&(data))>>13)
#define  CEC_CEC_RTCR0_get_cec_hw_retry_en(data)                                 ((0x00001000&(data))>>12)
#define  CEC_CEC_RTCR0_get_clear_cec_int(data)                                   ((0x00000800&(data))>>11)
#define  CEC_CEC_RTCR0_get_wt_cnt(data)                                          ((0x000007E0&(data))>>5)
#define  CEC_CEC_RTCR0_get_lattest(data)                                         ((0x00000010&(data))>>4)
#define  CEC_CEC_RTCR0_get_retry_no(data)                                        (0x0000000F&(data))

#define  CEC_CEC_RxCR0                                                           0x18061E08
#define  CEC_CEC_RxCR0_reg_addr                                                  "0xB8061E08"
#define  CEC_CEC_RxCR0_reg                                                       0xB8061E08
#define  CEC_CEC_RxCR0_inst_addr                                                 "0x0002"
#define  set_CEC_CEC_RxCR0_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_RxCR0_reg)=data)
#define  get_CEC_CEC_RxCR0_reg                                                   (*((volatile unsigned int*)CEC_CEC_RxCR0_reg))
#define  CEC_CEC_RxCR0_broadcast_addr_shift                                      (31)
#define  CEC_CEC_RxCR0_rx_same_la_direct_nack_shift                              (26)
#define  CEC_CEC_RxCR0_rx_no_accept_command_data_shift                           (25)
#define  CEC_CEC_RxCR0_rx_same_la_ack_shift                                      (24)
#define  CEC_CEC_RxCR0_rx_clear_fifo_data_en_shift                               (23)
#define  CEC_CEC_RxCR0_rx_clear_fifo_data_mode_shift                             (22)
#define  CEC_CEC_RxCR0_rx_clear_fifo_data_fw_shift                               (21)
#define  CEC_CEC_RxCR0_standby_addr_sel_shift                                    (20)
#define  CEC_CEC_RxCR0_standby_init_addr_shift                                   (16)
#define  CEC_CEC_RxCR0_rx_en_shift                                               (15)
#define  CEC_CEC_RxCR0_rx_rst_shift                                              (14)
#define  CEC_CEC_RxCR0_rx_continuous_shift                                       (13)
#define  CEC_CEC_RxCR0_rx_int_en_shift                                           (12)
#define  CEC_CEC_RxCR0_init_addr_shift                                           (8)
#define  CEC_CEC_RxCR0_rx_eom_shift                                              (7)
#define  CEC_CEC_RxCR0_rx_int_shift                                              (6)
#define  CEC_CEC_RxCR0_rx_fifo_ov_shift                                          (5)
#define  CEC_CEC_RxCR0_rx_fifo_cnt_shift                                         (0)
#define  CEC_CEC_RxCR0_broadcast_addr_mask                                       (0x80000000)
#define  CEC_CEC_RxCR0_rx_same_la_direct_nack_mask                               (0x04000000)
#define  CEC_CEC_RxCR0_rx_no_accept_command_data_mask                            (0x02000000)
#define  CEC_CEC_RxCR0_rx_same_la_ack_mask                                       (0x01000000)
#define  CEC_CEC_RxCR0_rx_clear_fifo_data_en_mask                                (0x00800000)
#define  CEC_CEC_RxCR0_rx_clear_fifo_data_mode_mask                              (0x00400000)
#define  CEC_CEC_RxCR0_rx_clear_fifo_data_fw_mask                                (0x00200000)
#define  CEC_CEC_RxCR0_standby_addr_sel_mask                                     (0x00100000)
#define  CEC_CEC_RxCR0_standby_init_addr_mask                                    (0x000F0000)
#define  CEC_CEC_RxCR0_rx_en_mask                                                (0x00008000)
#define  CEC_CEC_RxCR0_rx_rst_mask                                               (0x00004000)
#define  CEC_CEC_RxCR0_rx_continuous_mask                                        (0x00002000)
#define  CEC_CEC_RxCR0_rx_int_en_mask                                            (0x00001000)
#define  CEC_CEC_RxCR0_init_addr_mask                                            (0x00000F00)
#define  CEC_CEC_RxCR0_rx_eom_mask                                               (0x00000080)
#define  CEC_CEC_RxCR0_rx_int_mask                                               (0x00000040)
#define  CEC_CEC_RxCR0_rx_fifo_ov_mask                                           (0x00000020)
#define  CEC_CEC_RxCR0_rx_fifo_cnt_mask                                          (0x0000001F)
#define  CEC_CEC_RxCR0_broadcast_addr(data)                                      (0x80000000&((data)<<31))
#define  CEC_CEC_RxCR0_rx_same_la_direct_nack(data)                              (0x04000000&((data)<<26))
#define  CEC_CEC_RxCR0_rx_no_accept_command_data(data)                           (0x02000000&((data)<<25))
#define  CEC_CEC_RxCR0_rx_same_la_ack(data)                                      (0x01000000&((data)<<24))
#define  CEC_CEC_RxCR0_rx_clear_fifo_data_en(data)                               (0x00800000&((data)<<23))
#define  CEC_CEC_RxCR0_rx_clear_fifo_data_mode(data)                             (0x00400000&((data)<<22))
#define  CEC_CEC_RxCR0_rx_clear_fifo_data_fw(data)                               (0x00200000&((data)<<21))
#define  CEC_CEC_RxCR0_standby_addr_sel(data)                                    (0x00100000&((data)<<20))
#define  CEC_CEC_RxCR0_standby_init_addr(data)                                   (0x000F0000&((data)<<16))
#define  CEC_CEC_RxCR0_rx_en(data)                                               (0x00008000&((data)<<15))
#define  CEC_CEC_RxCR0_rx_rst(data)                                              (0x00004000&((data)<<14))
#define  CEC_CEC_RxCR0_rx_continuous(data)                                       (0x00002000&((data)<<13))
#define  CEC_CEC_RxCR0_rx_int_en(data)                                           (0x00001000&((data)<<12))
#define  CEC_CEC_RxCR0_init_addr(data)                                           (0x00000F00&((data)<<8))
#define  CEC_CEC_RxCR0_rx_eom(data)                                              (0x00000080&((data)<<7))
#define  CEC_CEC_RxCR0_rx_int(data)                                              (0x00000040&((data)<<6))
#define  CEC_CEC_RxCR0_rx_fifo_ov(data)                                          (0x00000020&((data)<<5))
#define  CEC_CEC_RxCR0_rx_fifo_cnt(data)                                         (0x0000001F&(data))
#define  CEC_CEC_RxCR0_get_broadcast_addr(data)                                  ((0x80000000&(data))>>31)
#define  CEC_CEC_RxCR0_get_rx_same_la_direct_nack(data)                          ((0x04000000&(data))>>26)
#define  CEC_CEC_RxCR0_get_rx_no_accept_command_data(data)                       ((0x02000000&(data))>>25)
#define  CEC_CEC_RxCR0_get_rx_same_la_ack(data)                                  ((0x01000000&(data))>>24)
#define  CEC_CEC_RxCR0_get_rx_clear_fifo_data_en(data)                           ((0x00800000&(data))>>23)
#define  CEC_CEC_RxCR0_get_rx_clear_fifo_data_mode(data)                         ((0x00400000&(data))>>22)
#define  CEC_CEC_RxCR0_get_rx_clear_fifo_data_fw(data)                           ((0x00200000&(data))>>21)
#define  CEC_CEC_RxCR0_get_standby_addr_sel(data)                                ((0x00100000&(data))>>20)
#define  CEC_CEC_RxCR0_get_standby_init_addr(data)                               ((0x000F0000&(data))>>16)
#define  CEC_CEC_RxCR0_get_rx_en(data)                                           ((0x00008000&(data))>>15)
#define  CEC_CEC_RxCR0_get_rx_rst(data)                                          ((0x00004000&(data))>>14)
#define  CEC_CEC_RxCR0_get_rx_continuous(data)                                   ((0x00002000&(data))>>13)
#define  CEC_CEC_RxCR0_get_rx_int_en(data)                                       ((0x00001000&(data))>>12)
#define  CEC_CEC_RxCR0_get_init_addr(data)                                       ((0x00000F00&(data))>>8)
#define  CEC_CEC_RxCR0_get_rx_eom(data)                                          ((0x00000080&(data))>>7)
#define  CEC_CEC_RxCR0_get_rx_int(data)                                          ((0x00000040&(data))>>6)
#define  CEC_CEC_RxCR0_get_rx_fifo_ov(data)                                      ((0x00000020&(data))>>5)
#define  CEC_CEC_RxCR0_get_rx_fifo_cnt(data)                                     (0x0000001F&(data))

#define  CEC_CEC_TxCR0                                                           0x18061E0C
#define  CEC_CEC_TxCR0_reg_addr                                                  "0xB8061E0C"
#define  CEC_CEC_TxCR0_reg                                                       0xB8061E0C
#define  CEC_CEC_TxCR0_inst_addr                                                 "0x0003"
#define  set_CEC_CEC_TxCR0_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_TxCR0_reg)=data)
#define  get_CEC_CEC_TxCR0_reg                                                   (*((volatile unsigned int*)CEC_CEC_TxCR0_reg))
#define  CEC_CEC_TxCR0_tx_addr_en_shift                                          (20)
#define  CEC_CEC_TxCR0_tx_addr_shift                                             (16)
#define  CEC_CEC_TxCR0_tx_en_shift                                               (15)
#define  CEC_CEC_TxCR0_tx_rst_shift                                              (14)
#define  CEC_CEC_TxCR0_tx_continuous_shift                                       (13)
#define  CEC_CEC_TxCR0_tx_int_en_shift                                           (12)
#define  CEC_CEC_TxCR0_dest_addr_shift                                           (8)
#define  CEC_CEC_TxCR0_tx_eom_shift                                              (7)
#define  CEC_CEC_TxCR0_tx_int_shift                                              (6)
#define  CEC_CEC_TxCR0_tx_fifo_ud_shift                                          (5)
#define  CEC_CEC_TxCR0_tx_fifo_cnt_shift                                         (0)
#define  CEC_CEC_TxCR0_tx_addr_en_mask                                           (0x00100000)
#define  CEC_CEC_TxCR0_tx_addr_mask                                              (0x000F0000)
#define  CEC_CEC_TxCR0_tx_en_mask                                                (0x00008000)
#define  CEC_CEC_TxCR0_tx_rst_mask                                               (0x00004000)
#define  CEC_CEC_TxCR0_tx_continuous_mask                                        (0x00002000)
#define  CEC_CEC_TxCR0_tx_int_en_mask                                            (0x00001000)
#define  CEC_CEC_TxCR0_dest_addr_mask                                            (0x00000F00)
#define  CEC_CEC_TxCR0_tx_eom_mask                                               (0x00000080)
#define  CEC_CEC_TxCR0_tx_int_mask                                               (0x00000040)
#define  CEC_CEC_TxCR0_tx_fifo_ud_mask                                           (0x00000020)
#define  CEC_CEC_TxCR0_tx_fifo_cnt_mask                                          (0x0000001F)
#define  CEC_CEC_TxCR0_tx_addr_en(data)                                          (0x00100000&((data)<<20))
#define  CEC_CEC_TxCR0_tx_addr(data)                                             (0x000F0000&((data)<<16))
#define  CEC_CEC_TxCR0_tx_en(data)                                               (0x00008000&((data)<<15))
#define  CEC_CEC_TxCR0_tx_rst(data)                                              (0x00004000&((data)<<14))
#define  CEC_CEC_TxCR0_tx_continuous(data)                                       (0x00002000&((data)<<13))
#define  CEC_CEC_TxCR0_tx_int_en(data)                                           (0x00001000&((data)<<12))
#define  CEC_CEC_TxCR0_dest_addr(data)                                           (0x00000F00&((data)<<8))
#define  CEC_CEC_TxCR0_tx_eom(data)                                              (0x00000080&((data)<<7))
#define  CEC_CEC_TxCR0_tx_int(data)                                              (0x00000040&((data)<<6))
#define  CEC_CEC_TxCR0_tx_fifo_ud(data)                                          (0x00000020&((data)<<5))
#define  CEC_CEC_TxCR0_tx_fifo_cnt(data)                                         (0x0000001F&(data))
#define  CEC_CEC_TxCR0_get_tx_addr_en(data)                                      ((0x00100000&(data))>>20)
#define  CEC_CEC_TxCR0_get_tx_addr(data)                                         ((0x000F0000&(data))>>16)
#define  CEC_CEC_TxCR0_get_tx_en(data)                                           ((0x00008000&(data))>>15)
#define  CEC_CEC_TxCR0_get_tx_rst(data)                                          ((0x00004000&(data))>>14)
#define  CEC_CEC_TxCR0_get_tx_continuous(data)                                   ((0x00002000&(data))>>13)
#define  CEC_CEC_TxCR0_get_tx_int_en(data)                                       ((0x00001000&(data))>>12)
#define  CEC_CEC_TxCR0_get_dest_addr(data)                                       ((0x00000F00&(data))>>8)
#define  CEC_CEC_TxCR0_get_tx_eom(data)                                          ((0x00000080&(data))>>7)
#define  CEC_CEC_TxCR0_get_tx_int(data)                                          ((0x00000040&(data))>>6)
#define  CEC_CEC_TxCR0_get_tx_fifo_ud(data)                                      ((0x00000020&(data))>>5)
#define  CEC_CEC_TxCR0_get_tx_fifo_cnt(data)                                     (0x0000001F&(data))

#define  CEC_CEC_TxDR0                                                           0x18061E10
#define  CEC_CEC_TxDR0_reg_addr                                                  "0xB8061E10"
#define  CEC_CEC_TxDR0_reg                                                       0xB8061E10
#define  CEC_CEC_TxDR0_inst_addr                                                 "0x0004"
#define  set_CEC_CEC_TxDR0_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_TxDR0_reg)=data)
#define  get_CEC_CEC_TxDR0_reg                                                   (*((volatile unsigned int*)CEC_CEC_TxDR0_reg))
#define  CEC_CEC_TxDR0_tx_add_cnt_shift                                          (6)
#define  CEC_CEC_TxDR0_rx_sub_cnt_shift                                          (5)
#define  CEC_CEC_TxDR0_fifo_cnt_shift                                            (0)
#define  CEC_CEC_TxDR0_tx_add_cnt_mask                                           (0x00000040)
#define  CEC_CEC_TxDR0_rx_sub_cnt_mask                                           (0x00000020)
#define  CEC_CEC_TxDR0_fifo_cnt_mask                                             (0x0000001F)
#define  CEC_CEC_TxDR0_tx_add_cnt(data)                                          (0x00000040&((data)<<6))
#define  CEC_CEC_TxDR0_rx_sub_cnt(data)                                          (0x00000020&((data)<<5))
#define  CEC_CEC_TxDR0_fifo_cnt(data)                                            (0x0000001F&(data))
#define  CEC_CEC_TxDR0_get_tx_add_cnt(data)                                      ((0x00000040&(data))>>6)
#define  CEC_CEC_TxDR0_get_rx_sub_cnt(data)                                      ((0x00000020&(data))>>5)
#define  CEC_CEC_TxDR0_get_fifo_cnt(data)                                        (0x0000001F&(data))

#define  CEC_CEC_TxDR1                                                           0x18061E14
#define  CEC_CEC_TxDR1_reg_addr                                                  "0xB8061E14"
#define  CEC_CEC_TxDR1_reg                                                       0xB8061E14
#define  CEC_CEC_TxDR1_inst_addr                                                 "0x0005"
#define  set_CEC_CEC_TxDR1_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_TxDR1_reg)=data)
#define  get_CEC_CEC_TxDR1_reg                                                   (*((volatile unsigned int*)CEC_CEC_TxDR1_reg))
#define  CEC_CEC_TxDR1_tx_fifo_0_shift                                           (24)
#define  CEC_CEC_TxDR1_tx_fifo_1_shift                                           (16)
#define  CEC_CEC_TxDR1_tx_fifo_2_shift                                           (8)
#define  CEC_CEC_TxDR1_tx_fifo_3_shift                                           (0)
#define  CEC_CEC_TxDR1_tx_fifo_0_mask                                            (0xFF000000)
#define  CEC_CEC_TxDR1_tx_fifo_1_mask                                            (0x00FF0000)
#define  CEC_CEC_TxDR1_tx_fifo_2_mask                                            (0x0000FF00)
#define  CEC_CEC_TxDR1_tx_fifo_3_mask                                            (0x000000FF)
#define  CEC_CEC_TxDR1_tx_fifo_0(data)                                           (0xFF000000&((data)<<24))
#define  CEC_CEC_TxDR1_tx_fifo_1(data)                                           (0x00FF0000&((data)<<16))
#define  CEC_CEC_TxDR1_tx_fifo_2(data)                                           (0x0000FF00&((data)<<8))
#define  CEC_CEC_TxDR1_tx_fifo_3(data)                                           (0x000000FF&(data))
#define  CEC_CEC_TxDR1_get_tx_fifo_0(data)                                       ((0xFF000000&(data))>>24)
#define  CEC_CEC_TxDR1_get_tx_fifo_1(data)                                       ((0x00FF0000&(data))>>16)
#define  CEC_CEC_TxDR1_get_tx_fifo_2(data)                                       ((0x0000FF00&(data))>>8)
#define  CEC_CEC_TxDR1_get_tx_fifo_3(data)                                       (0x000000FF&(data))

#define  CEC_CEC_TxDR2                                                           0x18061E18
#define  CEC_CEC_TxDR2_reg_addr                                                  "0xB8061E18"
#define  CEC_CEC_TxDR2_reg                                                       0xB8061E18
#define  CEC_CEC_TxDR2_inst_addr                                                 "0x0006"
#define  set_CEC_CEC_TxDR2_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_TxDR2_reg)=data)
#define  get_CEC_CEC_TxDR2_reg                                                   (*((volatile unsigned int*)CEC_CEC_TxDR2_reg))
#define  CEC_CEC_TxDR2_tx_fifo_4_shift                                           (24)
#define  CEC_CEC_TxDR2_tx_fifo_5_shift                                           (16)
#define  CEC_CEC_TxDR2_tx_fifo_6_shift                                           (8)
#define  CEC_CEC_TxDR2_tx_fifo_7_shift                                           (0)
#define  CEC_CEC_TxDR2_tx_fifo_4_mask                                            (0xFF000000)
#define  CEC_CEC_TxDR2_tx_fifo_5_mask                                            (0x00FF0000)
#define  CEC_CEC_TxDR2_tx_fifo_6_mask                                            (0x0000FF00)
#define  CEC_CEC_TxDR2_tx_fifo_7_mask                                            (0x000000FF)
#define  CEC_CEC_TxDR2_tx_fifo_4(data)                                           (0xFF000000&((data)<<24))
#define  CEC_CEC_TxDR2_tx_fifo_5(data)                                           (0x00FF0000&((data)<<16))
#define  CEC_CEC_TxDR2_tx_fifo_6(data)                                           (0x0000FF00&((data)<<8))
#define  CEC_CEC_TxDR2_tx_fifo_7(data)                                           (0x000000FF&(data))
#define  CEC_CEC_TxDR2_get_tx_fifo_4(data)                                       ((0xFF000000&(data))>>24)
#define  CEC_CEC_TxDR2_get_tx_fifo_5(data)                                       ((0x00FF0000&(data))>>16)
#define  CEC_CEC_TxDR2_get_tx_fifo_6(data)                                       ((0x0000FF00&(data))>>8)
#define  CEC_CEC_TxDR2_get_tx_fifo_7(data)                                       (0x000000FF&(data))

#define  CEC_CEC_TxDR3                                                           0x18061E1C
#define  CEC_CEC_TxDR3_reg_addr                                                  "0xB8061E1C"
#define  CEC_CEC_TxDR3_reg                                                       0xB8061E1C
#define  CEC_CEC_TxDR3_inst_addr                                                 "0x0007"
#define  set_CEC_CEC_TxDR3_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_TxDR3_reg)=data)
#define  get_CEC_CEC_TxDR3_reg                                                   (*((volatile unsigned int*)CEC_CEC_TxDR3_reg))
#define  CEC_CEC_TxDR3_tx_fifo_8_shift                                           (24)
#define  CEC_CEC_TxDR3_tx_fifo_9_shift                                           (16)
#define  CEC_CEC_TxDR3_tx_fifo_a_shift                                           (8)
#define  CEC_CEC_TxDR3_tx_fifo_b_shift                                           (0)
#define  CEC_CEC_TxDR3_tx_fifo_8_mask                                            (0xFF000000)
#define  CEC_CEC_TxDR3_tx_fifo_9_mask                                            (0x00FF0000)
#define  CEC_CEC_TxDR3_tx_fifo_a_mask                                            (0x0000FF00)
#define  CEC_CEC_TxDR3_tx_fifo_b_mask                                            (0x000000FF)
#define  CEC_CEC_TxDR3_tx_fifo_8(data)                                           (0xFF000000&((data)<<24))
#define  CEC_CEC_TxDR3_tx_fifo_9(data)                                           (0x00FF0000&((data)<<16))
#define  CEC_CEC_TxDR3_tx_fifo_a(data)                                           (0x0000FF00&((data)<<8))
#define  CEC_CEC_TxDR3_tx_fifo_b(data)                                           (0x000000FF&(data))
#define  CEC_CEC_TxDR3_get_tx_fifo_8(data)                                       ((0xFF000000&(data))>>24)
#define  CEC_CEC_TxDR3_get_tx_fifo_9(data)                                       ((0x00FF0000&(data))>>16)
#define  CEC_CEC_TxDR3_get_tx_fifo_a(data)                                       ((0x0000FF00&(data))>>8)
#define  CEC_CEC_TxDR3_get_tx_fifo_b(data)                                       (0x000000FF&(data))

#define  CEC_CEC_TxDR4                                                           0x18061E20
#define  CEC_CEC_TxDR4_reg_addr                                                  "0xB8061E20"
#define  CEC_CEC_TxDR4_reg                                                       0xB8061E20
#define  CEC_CEC_TxDR4_inst_addr                                                 "0x0008"
#define  set_CEC_CEC_TxDR4_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_TxDR4_reg)=data)
#define  get_CEC_CEC_TxDR4_reg                                                   (*((volatile unsigned int*)CEC_CEC_TxDR4_reg))
#define  CEC_CEC_TxDR4_tx_fifo_c_shift                                           (24)
#define  CEC_CEC_TxDR4_tx_fifo_d_shift                                           (16)
#define  CEC_CEC_TxDR4_tx_fifo_e_shift                                           (8)
#define  CEC_CEC_TxDR4_tx_fifo_f_shift                                           (0)
#define  CEC_CEC_TxDR4_tx_fifo_c_mask                                            (0xFF000000)
#define  CEC_CEC_TxDR4_tx_fifo_d_mask                                            (0x00FF0000)
#define  CEC_CEC_TxDR4_tx_fifo_e_mask                                            (0x0000FF00)
#define  CEC_CEC_TxDR4_tx_fifo_f_mask                                            (0x000000FF)
#define  CEC_CEC_TxDR4_tx_fifo_c(data)                                           (0xFF000000&((data)<<24))
#define  CEC_CEC_TxDR4_tx_fifo_d(data)                                           (0x00FF0000&((data)<<16))
#define  CEC_CEC_TxDR4_tx_fifo_e(data)                                           (0x0000FF00&((data)<<8))
#define  CEC_CEC_TxDR4_tx_fifo_f(data)                                           (0x000000FF&(data))
#define  CEC_CEC_TxDR4_get_tx_fifo_c(data)                                       ((0xFF000000&(data))>>24)
#define  CEC_CEC_TxDR4_get_tx_fifo_d(data)                                       ((0x00FF0000&(data))>>16)
#define  CEC_CEC_TxDR4_get_tx_fifo_e(data)                                       ((0x0000FF00&(data))>>8)
#define  CEC_CEC_TxDR4_get_tx_fifo_f(data)                                       (0x000000FF&(data))

#define  CEC_CEC_RxDR1                                                           0x18061E24
#define  CEC_CEC_RxDR1_reg_addr                                                  "0xB8061E24"
#define  CEC_CEC_RxDR1_reg                                                       0xB8061E24
#define  CEC_CEC_RxDR1_inst_addr                                                 "0x0009"
#define  set_CEC_CEC_RxDR1_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_RxDR1_reg)=data)
#define  get_CEC_CEC_RxDR1_reg                                                   (*((volatile unsigned int*)CEC_CEC_RxDR1_reg))
#define  CEC_CEC_RxDR1_rx_fifo_0_shift                                           (24)
#define  CEC_CEC_RxDR1_rx_fifo_1_shift                                           (16)
#define  CEC_CEC_RxDR1_rx_fifo_2_shift                                           (8)
#define  CEC_CEC_RxDR1_rx_fifo_3_shift                                           (0)
#define  CEC_CEC_RxDR1_rx_fifo_0_mask                                            (0xFF000000)
#define  CEC_CEC_RxDR1_rx_fifo_1_mask                                            (0x00FF0000)
#define  CEC_CEC_RxDR1_rx_fifo_2_mask                                            (0x0000FF00)
#define  CEC_CEC_RxDR1_rx_fifo_3_mask                                            (0x000000FF)
#define  CEC_CEC_RxDR1_rx_fifo_0(data)                                           (0xFF000000&((data)<<24))
#define  CEC_CEC_RxDR1_rx_fifo_1(data)                                           (0x00FF0000&((data)<<16))
#define  CEC_CEC_RxDR1_rx_fifo_2(data)                                           (0x0000FF00&((data)<<8))
#define  CEC_CEC_RxDR1_rx_fifo_3(data)                                           (0x000000FF&(data))
#define  CEC_CEC_RxDR1_get_rx_fifo_0(data)                                       ((0xFF000000&(data))>>24)
#define  CEC_CEC_RxDR1_get_rx_fifo_1(data)                                       ((0x00FF0000&(data))>>16)
#define  CEC_CEC_RxDR1_get_rx_fifo_2(data)                                       ((0x0000FF00&(data))>>8)
#define  CEC_CEC_RxDR1_get_rx_fifo_3(data)                                       (0x000000FF&(data))

#define  CEC_CEC_RxDR2                                                           0x18061E28
#define  CEC_CEC_RxDR2_reg_addr                                                  "0xB8061E28"
#define  CEC_CEC_RxDR2_reg                                                       0xB8061E28
#define  CEC_CEC_RxDR2_inst_addr                                                 "0x000A"
#define  set_CEC_CEC_RxDR2_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_RxDR2_reg)=data)
#define  get_CEC_CEC_RxDR2_reg                                                   (*((volatile unsigned int*)CEC_CEC_RxDR2_reg))
#define  CEC_CEC_RxDR2_rx_fifo_4_shift                                           (24)
#define  CEC_CEC_RxDR2_rx_fifo_5_shift                                           (16)
#define  CEC_CEC_RxDR2_rx_fifo_6_shift                                           (8)
#define  CEC_CEC_RxDR2_rx_fifo_7_shift                                           (0)
#define  CEC_CEC_RxDR2_rx_fifo_4_mask                                            (0xFF000000)
#define  CEC_CEC_RxDR2_rx_fifo_5_mask                                            (0x00FF0000)
#define  CEC_CEC_RxDR2_rx_fifo_6_mask                                            (0x0000FF00)
#define  CEC_CEC_RxDR2_rx_fifo_7_mask                                            (0x000000FF)
#define  CEC_CEC_RxDR2_rx_fifo_4(data)                                           (0xFF000000&((data)<<24))
#define  CEC_CEC_RxDR2_rx_fifo_5(data)                                           (0x00FF0000&((data)<<16))
#define  CEC_CEC_RxDR2_rx_fifo_6(data)                                           (0x0000FF00&((data)<<8))
#define  CEC_CEC_RxDR2_rx_fifo_7(data)                                           (0x000000FF&(data))
#define  CEC_CEC_RxDR2_get_rx_fifo_4(data)                                       ((0xFF000000&(data))>>24)
#define  CEC_CEC_RxDR2_get_rx_fifo_5(data)                                       ((0x00FF0000&(data))>>16)
#define  CEC_CEC_RxDR2_get_rx_fifo_6(data)                                       ((0x0000FF00&(data))>>8)
#define  CEC_CEC_RxDR2_get_rx_fifo_7(data)                                       (0x000000FF&(data))

#define  CEC_CEC_RxDR3                                                           0x18061E2C
#define  CEC_CEC_RxDR3_reg_addr                                                  "0xB8061E2C"
#define  CEC_CEC_RxDR3_reg                                                       0xB8061E2C
#define  CEC_CEC_RxDR3_inst_addr                                                 "0x000B"
#define  set_CEC_CEC_RxDR3_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_RxDR3_reg)=data)
#define  get_CEC_CEC_RxDR3_reg                                                   (*((volatile unsigned int*)CEC_CEC_RxDR3_reg))
#define  CEC_CEC_RxDR3_rx_fifo_8_shift                                           (24)
#define  CEC_CEC_RxDR3_rx_fifo_9_shift                                           (16)
#define  CEC_CEC_RxDR3_rx_fifo_a_shift                                           (8)
#define  CEC_CEC_RxDR3_rx_fifo_b_shift                                           (0)
#define  CEC_CEC_RxDR3_rx_fifo_8_mask                                            (0xFF000000)
#define  CEC_CEC_RxDR3_rx_fifo_9_mask                                            (0x00FF0000)
#define  CEC_CEC_RxDR3_rx_fifo_a_mask                                            (0x0000FF00)
#define  CEC_CEC_RxDR3_rx_fifo_b_mask                                            (0x000000FF)
#define  CEC_CEC_RxDR3_rx_fifo_8(data)                                           (0xFF000000&((data)<<24))
#define  CEC_CEC_RxDR3_rx_fifo_9(data)                                           (0x00FF0000&((data)<<16))
#define  CEC_CEC_RxDR3_rx_fifo_a(data)                                           (0x0000FF00&((data)<<8))
#define  CEC_CEC_RxDR3_rx_fifo_b(data)                                           (0x000000FF&(data))
#define  CEC_CEC_RxDR3_get_rx_fifo_8(data)                                       ((0xFF000000&(data))>>24)
#define  CEC_CEC_RxDR3_get_rx_fifo_9(data)                                       ((0x00FF0000&(data))>>16)
#define  CEC_CEC_RxDR3_get_rx_fifo_a(data)                                       ((0x0000FF00&(data))>>8)
#define  CEC_CEC_RxDR3_get_rx_fifo_b(data)                                       (0x000000FF&(data))

#define  CEC_CEC_RxDR4                                                           0x18061E30
#define  CEC_CEC_RxDR4_reg_addr                                                  "0xB8061E30"
#define  CEC_CEC_RxDR4_reg                                                       0xB8061E30
#define  CEC_CEC_RxDR4_inst_addr                                                 "0x000C"
#define  set_CEC_CEC_RxDR4_reg(data)                                             (*((volatile unsigned int*)CEC_CEC_RxDR4_reg)=data)
#define  get_CEC_CEC_RxDR4_reg                                                   (*((volatile unsigned int*)CEC_CEC_RxDR4_reg))
#define  CEC_CEC_RxDR4_rx_fifo_c_shift                                           (24)
#define  CEC_CEC_RxDR4_rx_fifo_d_shift                                           (16)
#define  CEC_CEC_RxDR4_rx_fifo_e_shift                                           (8)
#define  CEC_CEC_RxDR4_rx_fifo_f_shift                                           (0)
#define  CEC_CEC_RxDR4_rx_fifo_c_mask                                            (0xFF000000)
#define  CEC_CEC_RxDR4_rx_fifo_d_mask                                            (0x00FF0000)
#define  CEC_CEC_RxDR4_rx_fifo_e_mask                                            (0x0000FF00)
#define  CEC_CEC_RxDR4_rx_fifo_f_mask                                            (0x000000FF)
#define  CEC_CEC_RxDR4_rx_fifo_c(data)                                           (0xFF000000&((data)<<24))
#define  CEC_CEC_RxDR4_rx_fifo_d(data)                                           (0x00FF0000&((data)<<16))
#define  CEC_CEC_RxDR4_rx_fifo_e(data)                                           (0x0000FF00&((data)<<8))
#define  CEC_CEC_RxDR4_rx_fifo_f(data)                                           (0x000000FF&(data))
#define  CEC_CEC_RxDR4_get_rx_fifo_c(data)                                       ((0xFF000000&(data))>>24)
#define  CEC_CEC_RxDR4_get_rx_fifo_d(data)                                       ((0x00FF0000&(data))>>16)
#define  CEC_CEC_RxDR4_get_rx_fifo_e(data)                                       ((0x0000FF00&(data))>>8)
#define  CEC_CEC_RxDR4_get_rx_fifo_f(data)                                       (0x000000FF&(data))

#define  CEC_CEC_RxTCR0                                                          0x18061E34
#define  CEC_CEC_RxTCR0_reg_addr                                                 "0xB8061E34"
#define  CEC_CEC_RxTCR0_reg                                                      0xB8061E34
#define  CEC_CEC_RxTCR0_inst_addr                                                "0x000D"
#define  set_CEC_CEC_RxTCR0_reg(data)                                            (*((volatile unsigned int*)CEC_CEC_RxTCR0_reg)=data)
#define  get_CEC_CEC_RxTCR0_reg                                                  (*((volatile unsigned int*)CEC_CEC_RxTCR0_reg))
#define  CEC_CEC_RxTCR0_rx_start_low_shift                                       (24)
#define  CEC_CEC_RxTCR0_rx_start_period_shift                                    (16)
#define  CEC_CEC_RxTCR0_rx_data_sample_shift                                     (8)
#define  CEC_CEC_RxTCR0_rx_data_period_shift                                     (0)
#define  CEC_CEC_RxTCR0_rx_start_low_mask                                        (0xFF000000)
#define  CEC_CEC_RxTCR0_rx_start_period_mask                                     (0x00FF0000)
#define  CEC_CEC_RxTCR0_rx_data_sample_mask                                      (0x0000FF00)
#define  CEC_CEC_RxTCR0_rx_data_period_mask                                      (0x000000FF)
#define  CEC_CEC_RxTCR0_rx_start_low(data)                                       (0xFF000000&((data)<<24))
#define  CEC_CEC_RxTCR0_rx_start_period(data)                                    (0x00FF0000&((data)<<16))
#define  CEC_CEC_RxTCR0_rx_data_sample(data)                                     (0x0000FF00&((data)<<8))
#define  CEC_CEC_RxTCR0_rx_data_period(data)                                     (0x000000FF&(data))
#define  CEC_CEC_RxTCR0_get_rx_start_low(data)                                   ((0xFF000000&(data))>>24)
#define  CEC_CEC_RxTCR0_get_rx_start_period(data)                                ((0x00FF0000&(data))>>16)
#define  CEC_CEC_RxTCR0_get_rx_data_sample(data)                                 ((0x0000FF00&(data))>>8)
#define  CEC_CEC_RxTCR0_get_rx_data_period(data)                                 (0x000000FF&(data))

#define  CEC_CEC_TxTCR0                                                          0x18061E38
#define  CEC_CEC_TxTCR0_reg_addr                                                 "0xB8061E38"
#define  CEC_CEC_TxTCR0_reg                                                      0xB8061E38
#define  CEC_CEC_TxTCR0_inst_addr                                                "0x000E"
#define  set_CEC_CEC_TxTCR0_reg(data)                                            (*((volatile unsigned int*)CEC_CEC_TxTCR0_reg)=data)
#define  get_CEC_CEC_TxTCR0_reg                                                  (*((volatile unsigned int*)CEC_CEC_TxTCR0_reg))
#define  CEC_CEC_TxTCR0_tx_start_low_shift                                       (8)
#define  CEC_CEC_TxTCR0_tx_start_high_shift                                      (0)
#define  CEC_CEC_TxTCR0_tx_start_low_mask                                        (0x0000FF00)
#define  CEC_CEC_TxTCR0_tx_start_high_mask                                       (0x000000FF)
#define  CEC_CEC_TxTCR0_tx_start_low(data)                                       (0x0000FF00&((data)<<8))
#define  CEC_CEC_TxTCR0_tx_start_high(data)                                      (0x000000FF&(data))
#define  CEC_CEC_TxTCR0_get_tx_start_low(data)                                   ((0x0000FF00&(data))>>8)
#define  CEC_CEC_TxTCR0_get_tx_start_high(data)                                  (0x000000FF&(data))

#define  CEC_CEC_TxTCR1                                                          0x18061E3C
#define  CEC_CEC_TxTCR1_reg_addr                                                 "0xB8061E3C"
#define  CEC_CEC_TxTCR1_reg                                                      0xB8061E3C
#define  CEC_CEC_TxTCR1_inst_addr                                                "0x000F"
#define  set_CEC_CEC_TxTCR1_reg(data)                                            (*((volatile unsigned int*)CEC_CEC_TxTCR1_reg)=data)
#define  get_CEC_CEC_TxTCR1_reg                                                  (*((volatile unsigned int*)CEC_CEC_TxTCR1_reg))
#define  CEC_CEC_TxTCR1_tx_data_low_shift                                        (16)
#define  CEC_CEC_TxTCR1_tx_data_01_shift                                         (8)
#define  CEC_CEC_TxTCR1_tx_data_high_shift                                       (0)
#define  CEC_CEC_TxTCR1_tx_data_low_mask                                         (0x00FF0000)
#define  CEC_CEC_TxTCR1_tx_data_01_mask                                          (0x0000FF00)
#define  CEC_CEC_TxTCR1_tx_data_high_mask                                        (0x000000FF)
#define  CEC_CEC_TxTCR1_tx_data_low(data)                                        (0x00FF0000&((data)<<16))
#define  CEC_CEC_TxTCR1_tx_data_01(data)                                         (0x0000FF00&((data)<<8))
#define  CEC_CEC_TxTCR1_tx_data_high(data)                                       (0x000000FF&(data))
#define  CEC_CEC_TxTCR1_get_tx_data_low(data)                                    ((0x00FF0000&(data))>>16)
#define  CEC_CEC_TxTCR1_get_tx_data_01(data)                                     ((0x0000FF00&(data))>>8)
#define  CEC_CEC_TxTCR1_get_tx_data_high(data)                                   (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_01                                           0x18061E40
#define  CEC_GDI_CEC_COMPARE_OPCODE_01_reg_addr                                  "0xB8061E40"
#define  CEC_GDI_CEC_COMPARE_OPCODE_01_reg                                       0xB8061E40
#define  CEC_GDI_CEC_COMPARE_OPCODE_01_inst_addr                                 "0x0010"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_01_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_01_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_01_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_01_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_01_compare_opcode_01_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_01_compare_opcode_01_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_01_compare_opcode_01(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_01_get_compare_opcode_01(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_SEND_OPCODE_01                                              0x18061E44
#define  CEC_GDI_CEC_SEND_OPCODE_01_reg_addr                                     "0xB8061E44"
#define  CEC_GDI_CEC_SEND_OPCODE_01_reg                                          0xB8061E44
#define  CEC_GDI_CEC_SEND_OPCODE_01_inst_addr                                    "0x0011"
#define  set_CEC_GDI_CEC_SEND_OPCODE_01_reg(data)                                (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPCODE_01_reg)=data)
#define  get_CEC_GDI_CEC_SEND_OPCODE_01_reg                                      (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPCODE_01_reg))
#define  CEC_GDI_CEC_SEND_OPCODE_01_send_init_address_01_shift                   (12)
#define  CEC_GDI_CEC_SEND_OPCODE_01_init_address_01_shift                        (8)
#define  CEC_GDI_CEC_SEND_OPCODE_01_send_opcode_01_shift                         (0)
#define  CEC_GDI_CEC_SEND_OPCODE_01_send_init_address_01_mask                    (0x00001000)
#define  CEC_GDI_CEC_SEND_OPCODE_01_init_address_01_mask                         (0x00000F00)
#define  CEC_GDI_CEC_SEND_OPCODE_01_send_opcode_01_mask                          (0x000000FF)
#define  CEC_GDI_CEC_SEND_OPCODE_01_send_init_address_01(data)                   (0x00001000&((data)<<12))
#define  CEC_GDI_CEC_SEND_OPCODE_01_init_address_01(data)                        (0x00000F00&((data)<<8))
#define  CEC_GDI_CEC_SEND_OPCODE_01_send_opcode_01(data)                         (0x000000FF&(data))
#define  CEC_GDI_CEC_SEND_OPCODE_01_get_send_init_address_01(data)               ((0x00001000&(data))>>12)
#define  CEC_GDI_CEC_SEND_OPCODE_01_get_init_address_01(data)                    ((0x00000F00&(data))>>8)
#define  CEC_GDI_CEC_SEND_OPCODE_01_get_send_opcode_01(data)                     (0x000000FF&(data))

#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_01                                      0x18061E48
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_reg_addr                             "0xB8061E48"
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_reg                                  0xB8061E48
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_inst_addr                            "0x0012"
#define  set_CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_reg(data)                        (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_reg)=data)
#define  get_CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_reg                              (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_reg))
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_operand_number_01_shift              (0)
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_operand_number_01_mask               (0x00000003)
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_operand_number_01(data)              (0x00000003&(data))
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_get_operand_number_01(data)          (0x00000003&(data))

#define  CEC_GDI_CEC_OPERAND_01                                                  0x18061E4C
#define  CEC_GDI_CEC_OPERAND_01_reg_addr                                         "0xB8061E4C"
#define  CEC_GDI_CEC_OPERAND_01_reg                                              0xB8061E4C
#define  CEC_GDI_CEC_OPERAND_01_inst_addr                                        "0x0013"
#define  set_CEC_GDI_CEC_OPERAND_01_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_01_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_01_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_01_reg))
#define  CEC_GDI_CEC_OPERAND_01_operand_01_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_01_operand_01_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_01_operand_01(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_01_get_operand_01(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_OPERAND_02                                                  0x18061E50
#define  CEC_GDI_CEC_OPERAND_02_reg_addr                                         "0xB8061E50"
#define  CEC_GDI_CEC_OPERAND_02_reg                                              0xB8061E50
#define  CEC_GDI_CEC_OPERAND_02_inst_addr                                        "0x0014"
#define  set_CEC_GDI_CEC_OPERAND_02_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_02_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_02_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_02_reg))
#define  CEC_GDI_CEC_OPERAND_02_operand_02_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_02_operand_02_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_02_operand_02(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_02_get_operand_02(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_OPERAND_03                                                  0x18061E54
#define  CEC_GDI_CEC_OPERAND_03_reg_addr                                         "0xB8061E54"
#define  CEC_GDI_CEC_OPERAND_03_reg                                              0xB8061E54
#define  CEC_GDI_CEC_OPERAND_03_inst_addr                                        "0x0015"
#define  set_CEC_GDI_CEC_OPERAND_03_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_03_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_03_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_03_reg))
#define  CEC_GDI_CEC_OPERAND_03_operand_03_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_03_operand_03_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_03_operand_03(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_03_get_operand_03(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_02                                           0x18061E58
#define  CEC_GDI_CEC_COMPARE_OPCODE_02_reg_addr                                  "0xB8061E58"
#define  CEC_GDI_CEC_COMPARE_OPCODE_02_reg                                       0xB8061E58
#define  CEC_GDI_CEC_COMPARE_OPCODE_02_inst_addr                                 "0x0016"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_02_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_02_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_02_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_02_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_02_compare_opcode_02_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_02_compare_opcode_02_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_02_compare_opcode_02(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_02_get_compare_opcode_02(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_SEND_OPCODE_02                                              0x18061E5C
#define  CEC_GDI_CEC_SEND_OPCODE_02_reg_addr                                     "0xB8061E5C"
#define  CEC_GDI_CEC_SEND_OPCODE_02_reg                                          0xB8061E5C
#define  CEC_GDI_CEC_SEND_OPCODE_02_inst_addr                                    "0x0017"
#define  set_CEC_GDI_CEC_SEND_OPCODE_02_reg(data)                                (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPCODE_02_reg)=data)
#define  get_CEC_GDI_CEC_SEND_OPCODE_02_reg                                      (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPCODE_02_reg))
#define  CEC_GDI_CEC_SEND_OPCODE_02_send_init_address_02_shift                   (12)
#define  CEC_GDI_CEC_SEND_OPCODE_02_init_address_02_shift                        (8)
#define  CEC_GDI_CEC_SEND_OPCODE_02_send_opcode_02_shift                         (0)
#define  CEC_GDI_CEC_SEND_OPCODE_02_send_init_address_02_mask                    (0x00001000)
#define  CEC_GDI_CEC_SEND_OPCODE_02_init_address_02_mask                         (0x00000F00)
#define  CEC_GDI_CEC_SEND_OPCODE_02_send_opcode_02_mask                          (0x000000FF)
#define  CEC_GDI_CEC_SEND_OPCODE_02_send_init_address_02(data)                   (0x00001000&((data)<<12))
#define  CEC_GDI_CEC_SEND_OPCODE_02_init_address_02(data)                        (0x00000F00&((data)<<8))
#define  CEC_GDI_CEC_SEND_OPCODE_02_send_opcode_02(data)                         (0x000000FF&(data))
#define  CEC_GDI_CEC_SEND_OPCODE_02_get_send_init_address_02(data)               ((0x00001000&(data))>>12)
#define  CEC_GDI_CEC_SEND_OPCODE_02_get_init_address_02(data)                    ((0x00000F00&(data))>>8)
#define  CEC_GDI_CEC_SEND_OPCODE_02_get_send_opcode_02(data)                     (0x000000FF&(data))

#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_02                                      0x18061E60
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_reg_addr                             "0xB8061E60"
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_reg                                  0xB8061E60
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_inst_addr                            "0x0018"
#define  set_CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_reg(data)                        (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_reg)=data)
#define  get_CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_reg                              (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_reg))
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_operand_number_02_shift              (0)
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_operand_number_02_mask               (0x00000003)
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_operand_number_02(data)              (0x00000003&(data))
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_get_operand_number_02(data)          (0x00000003&(data))

#define  CEC_GDI_CEC_OPERAND_04                                                  0x18061E64
#define  CEC_GDI_CEC_OPERAND_04_reg_addr                                         "0xB8061E64"
#define  CEC_GDI_CEC_OPERAND_04_reg                                              0xB8061E64
#define  CEC_GDI_CEC_OPERAND_04_inst_addr                                        "0x0019"
#define  set_CEC_GDI_CEC_OPERAND_04_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_04_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_04_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_04_reg))
#define  CEC_GDI_CEC_OPERAND_04_operand_04_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_04_operand_04_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_04_operand_04(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_04_get_operand_04(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_OPERAND_05                                                  0x18061E68
#define  CEC_GDI_CEC_OPERAND_05_reg_addr                                         "0xB8061E68"
#define  CEC_GDI_CEC_OPERAND_05_reg                                              0xB8061E68
#define  CEC_GDI_CEC_OPERAND_05_inst_addr                                        "0x001A"
#define  set_CEC_GDI_CEC_OPERAND_05_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_05_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_05_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_05_reg))
#define  CEC_GDI_CEC_OPERAND_05_operand_05_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_05_operand_05_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_05_operand_05(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_05_get_operand_05(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_OPERAND_06                                                  0x18061E6C
#define  CEC_GDI_CEC_OPERAND_06_reg_addr                                         "0xB8061E6C"
#define  CEC_GDI_CEC_OPERAND_06_reg                                              0xB8061E6C
#define  CEC_GDI_CEC_OPERAND_06_inst_addr                                        "0x001B"
#define  set_CEC_GDI_CEC_OPERAND_06_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_06_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_06_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_06_reg))
#define  CEC_GDI_CEC_OPERAND_06_operand_06_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_06_operand_06_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_06_operand_06(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_06_get_operand_06(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_03                                           0x18061E70
#define  CEC_GDI_CEC_COMPARE_OPCODE_03_reg_addr                                  "0xB8061E70"
#define  CEC_GDI_CEC_COMPARE_OPCODE_03_reg                                       0xB8061E70
#define  CEC_GDI_CEC_COMPARE_OPCODE_03_inst_addr                                 "0x001C"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_03_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_03_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_03_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_03_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_03_compare_opcode_03_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_03_compare_opcode_03_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_03_compare_opcode_03(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_03_get_compare_opcode_03(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_SEND_OPCODE_03                                              0x18061E74
#define  CEC_GDI_CEC_SEND_OPCODE_03_reg_addr                                     "0xB8061E74"
#define  CEC_GDI_CEC_SEND_OPCODE_03_reg                                          0xB8061E74
#define  CEC_GDI_CEC_SEND_OPCODE_03_inst_addr                                    "0x001D"
#define  set_CEC_GDI_CEC_SEND_OPCODE_03_reg(data)                                (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPCODE_03_reg)=data)
#define  get_CEC_GDI_CEC_SEND_OPCODE_03_reg                                      (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPCODE_03_reg))
#define  CEC_GDI_CEC_SEND_OPCODE_03_send_init_address_03_shift                   (12)
#define  CEC_GDI_CEC_SEND_OPCODE_03_init_address_03_shift                        (8)
#define  CEC_GDI_CEC_SEND_OPCODE_03_send_opcode_03_shift                         (0)
#define  CEC_GDI_CEC_SEND_OPCODE_03_send_init_address_03_mask                    (0x00001000)
#define  CEC_GDI_CEC_SEND_OPCODE_03_init_address_03_mask                         (0x00000F00)
#define  CEC_GDI_CEC_SEND_OPCODE_03_send_opcode_03_mask                          (0x000000FF)
#define  CEC_GDI_CEC_SEND_OPCODE_03_send_init_address_03(data)                   (0x00001000&((data)<<12))
#define  CEC_GDI_CEC_SEND_OPCODE_03_init_address_03(data)                        (0x00000F00&((data)<<8))
#define  CEC_GDI_CEC_SEND_OPCODE_03_send_opcode_03(data)                         (0x000000FF&(data))
#define  CEC_GDI_CEC_SEND_OPCODE_03_get_send_init_address_03(data)               ((0x00001000&(data))>>12)
#define  CEC_GDI_CEC_SEND_OPCODE_03_get_init_address_03(data)                    ((0x00000F00&(data))>>8)
#define  CEC_GDI_CEC_SEND_OPCODE_03_get_send_opcode_03(data)                     (0x000000FF&(data))

#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_03                                      0x18061E78
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_reg_addr                             "0xB8061E78"
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_reg                                  0xB8061E78
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_inst_addr                            "0x001E"
#define  set_CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_reg(data)                        (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_reg)=data)
#define  get_CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_reg                              (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_reg))
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_operand_number_03_shift              (0)
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_operand_number_03_mask               (0x00000003)
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_operand_number_03(data)              (0x00000003&(data))
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_get_operand_number_03(data)          (0x00000003&(data))

#define  CEC_GDI_CEC_OPERAND_07                                                  0x18061E7C
#define  CEC_GDI_CEC_OPERAND_07_reg_addr                                         "0xB8061E7C"
#define  CEC_GDI_CEC_OPERAND_07_reg                                              0xB8061E7C
#define  CEC_GDI_CEC_OPERAND_07_inst_addr                                        "0x001F"
#define  set_CEC_GDI_CEC_OPERAND_07_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_07_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_07_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_07_reg))
#define  CEC_GDI_CEC_OPERAND_07_operand_07_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_07_operand_07_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_07_operand_07(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_07_get_operand_07(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_OPERAND_08                                                  0x18061E80
#define  CEC_GDI_CEC_OPERAND_08_reg_addr                                         "0xB8061E80"
#define  CEC_GDI_CEC_OPERAND_08_reg                                              0xB8061E80
#define  CEC_GDI_CEC_OPERAND_08_inst_addr                                        "0x0020"
#define  set_CEC_GDI_CEC_OPERAND_08_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_08_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_08_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_08_reg))
#define  CEC_GDI_CEC_OPERAND_08_operand_08_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_08_operand_08_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_08_operand_08(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_08_get_operand_08(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_OPERAND_09                                                  0x18061E84
#define  CEC_GDI_CEC_OPERAND_09_reg_addr                                         "0xB8061E84"
#define  CEC_GDI_CEC_OPERAND_09_reg                                              0xB8061E84
#define  CEC_GDI_CEC_OPERAND_09_inst_addr                                        "0x0021"
#define  set_CEC_GDI_CEC_OPERAND_09_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_09_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_09_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_09_reg))
#define  CEC_GDI_CEC_OPERAND_09_operand_09_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_09_operand_09_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_09_operand_09(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_09_get_operand_09(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_04                                           0x18061E88
#define  CEC_GDI_CEC_COMPARE_OPCODE_04_reg_addr                                  "0xB8061E88"
#define  CEC_GDI_CEC_COMPARE_OPCODE_04_reg                                       0xB8061E88
#define  CEC_GDI_CEC_COMPARE_OPCODE_04_inst_addr                                 "0x0022"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_04_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_04_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_04_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_04_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_04_compare_opcode_04_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_04_compare_opcode_04_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_04_compare_opcode_04(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_04_get_compare_opcode_04(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_SEND_OPCODE_04                                              0x18061E8C
#define  CEC_GDI_CEC_SEND_OPCODE_04_reg_addr                                     "0xB8061E8C"
#define  CEC_GDI_CEC_SEND_OPCODE_04_reg                                          0xB8061E8C
#define  CEC_GDI_CEC_SEND_OPCODE_04_inst_addr                                    "0x0023"
#define  set_CEC_GDI_CEC_SEND_OPCODE_04_reg(data)                                (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPCODE_04_reg)=data)
#define  get_CEC_GDI_CEC_SEND_OPCODE_04_reg                                      (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPCODE_04_reg))
#define  CEC_GDI_CEC_SEND_OPCODE_04_send_init_address_04_shift                   (12)
#define  CEC_GDI_CEC_SEND_OPCODE_04_init_address_04_shift                        (8)
#define  CEC_GDI_CEC_SEND_OPCODE_04_send_opcode_04_shift                         (0)
#define  CEC_GDI_CEC_SEND_OPCODE_04_send_init_address_04_mask                    (0x00001000)
#define  CEC_GDI_CEC_SEND_OPCODE_04_init_address_04_mask                         (0x00000F00)
#define  CEC_GDI_CEC_SEND_OPCODE_04_send_opcode_04_mask                          (0x000000FF)
#define  CEC_GDI_CEC_SEND_OPCODE_04_send_init_address_04(data)                   (0x00001000&((data)<<12))
#define  CEC_GDI_CEC_SEND_OPCODE_04_init_address_04(data)                        (0x00000F00&((data)<<8))
#define  CEC_GDI_CEC_SEND_OPCODE_04_send_opcode_04(data)                         (0x000000FF&(data))
#define  CEC_GDI_CEC_SEND_OPCODE_04_get_send_init_address_04(data)               ((0x00001000&(data))>>12)
#define  CEC_GDI_CEC_SEND_OPCODE_04_get_init_address_04(data)                    ((0x00000F00&(data))>>8)
#define  CEC_GDI_CEC_SEND_OPCODE_04_get_send_opcode_04(data)                     (0x000000FF&(data))

#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_04                                      0x18061E90
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_reg_addr                             "0xB8061E90"
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_reg                                  0xB8061E90
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_inst_addr                            "0x0024"
#define  set_CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_reg(data)                        (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_reg)=data)
#define  get_CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_reg                              (*((volatile unsigned int*)CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_reg))
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_operand_number_04_shift              (0)
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_operand_number_04_mask               (0x00000003)
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_operand_number_04(data)              (0x00000003&(data))
#define  CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_get_operand_number_04(data)          (0x00000003&(data))

#define  CEC_GDI_CEC_OPERAND_10                                                  0x18061E94
#define  CEC_GDI_CEC_OPERAND_10_reg_addr                                         "0xB8061E94"
#define  CEC_GDI_CEC_OPERAND_10_reg                                              0xB8061E94
#define  CEC_GDI_CEC_OPERAND_10_inst_addr                                        "0x0025"
#define  set_CEC_GDI_CEC_OPERAND_10_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_10_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_10_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_10_reg))
#define  CEC_GDI_CEC_OPERAND_10_operand_10_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_10_operand_10_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_10_operand_10(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_10_get_operand_10(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_OPERAND_11                                                  0x18061E98
#define  CEC_GDI_CEC_OPERAND_11_reg_addr                                         "0xB8061E98"
#define  CEC_GDI_CEC_OPERAND_11_reg                                              0xB8061E98
#define  CEC_GDI_CEC_OPERAND_11_inst_addr                                        "0x0026"
#define  set_CEC_GDI_CEC_OPERAND_11_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_11_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_11_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_11_reg))
#define  CEC_GDI_CEC_OPERAND_11_operand_11_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_11_operand_11_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_11_operand_11(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_11_get_operand_11(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_OPERAND_12                                                  0x18061E9C
#define  CEC_GDI_CEC_OPERAND_12_reg_addr                                         "0xB8061E9C"
#define  CEC_GDI_CEC_OPERAND_12_reg                                              0xB8061E9C
#define  CEC_GDI_CEC_OPERAND_12_inst_addr                                        "0x0027"
#define  set_CEC_GDI_CEC_OPERAND_12_reg(data)                                    (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_12_reg)=data)
#define  get_CEC_GDI_CEC_OPERAND_12_reg                                          (*((volatile unsigned int*)CEC_GDI_CEC_OPERAND_12_reg))
#define  CEC_GDI_CEC_OPERAND_12_operand_12_shift                                 (0)
#define  CEC_GDI_CEC_OPERAND_12_operand_12_mask                                  (0x000000FF)
#define  CEC_GDI_CEC_OPERAND_12_operand_12(data)                                 (0x000000FF&(data))
#define  CEC_GDI_CEC_OPERAND_12_get_operand_12(data)                             (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_05                                           0x18061EA0
#define  CEC_GDI_CEC_COMPARE_OPCODE_05_reg_addr                                  "0xB8061EA0"
#define  CEC_GDI_CEC_COMPARE_OPCODE_05_reg                                       0xB8061EA0
#define  CEC_GDI_CEC_COMPARE_OPCODE_05_inst_addr                                 "0x0028"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_05_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_05_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_05_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_05_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_05_compare_opcode_05_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_05_compare_opcode_05_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_05_compare_opcode_05(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_05_get_compare_opcode_05(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_06                                           0x18061EA4
#define  CEC_GDI_CEC_COMPARE_OPCODE_06_reg_addr                                  "0xB8061EA4"
#define  CEC_GDI_CEC_COMPARE_OPCODE_06_reg                                       0xB8061EA4
#define  CEC_GDI_CEC_COMPARE_OPCODE_06_inst_addr                                 "0x0029"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_06_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_06_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_06_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_06_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_06_compare_opcode_06_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_06_compare_opcode_06_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_06_compare_opcode_06(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_06_get_compare_opcode_06(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_07                                           0x18061EA8
#define  CEC_GDI_CEC_COMPARE_OPCODE_07_reg_addr                                  "0xB8061EA8"
#define  CEC_GDI_CEC_COMPARE_OPCODE_07_reg                                       0xB8061EA8
#define  CEC_GDI_CEC_COMPARE_OPCODE_07_inst_addr                                 "0x002A"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_07_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_07_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_07_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_07_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_07_compare_opcode_07_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_07_compare_opcode_07_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_07_compare_opcode_07(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_07_get_compare_opcode_07(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_08                                           0x18061EAC
#define  CEC_GDI_CEC_COMPARE_OPCODE_08_reg_addr                                  "0xB8061EAC"
#define  CEC_GDI_CEC_COMPARE_OPCODE_08_reg                                       0xB8061EAC
#define  CEC_GDI_CEC_COMPARE_OPCODE_08_inst_addr                                 "0x002B"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_08_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_08_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_08_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_08_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_08_compare_opcode_08_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_08_compare_opcode_08_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_08_compare_opcode_08(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_08_get_compare_opcode_08(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_09                                           0x18061EB0
#define  CEC_GDI_CEC_COMPARE_OPCODE_09_reg_addr                                  "0xB8061EB0"
#define  CEC_GDI_CEC_COMPARE_OPCODE_09_reg                                       0xB8061EB0
#define  CEC_GDI_CEC_COMPARE_OPCODE_09_inst_addr                                 "0x002C"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_09_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_09_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_09_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_09_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_09_compare_opcode_09_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_09_compare_opcode_09_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_09_compare_opcode_09(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_09_get_compare_opcode_09(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_10                                           0x18061EB4
#define  CEC_GDI_CEC_COMPARE_OPCODE_10_reg_addr                                  "0xB8061EB4"
#define  CEC_GDI_CEC_COMPARE_OPCODE_10_reg                                       0xB8061EB4
#define  CEC_GDI_CEC_COMPARE_OPCODE_10_inst_addr                                 "0x002D"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_10_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_10_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_10_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_10_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_10_compare_opcode_10_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_10_compare_opcode_10_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_10_compare_opcode_10(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_10_get_compare_opcode_10(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_11                                           0x18061EB8
#define  CEC_GDI_CEC_COMPARE_OPCODE_11_reg_addr                                  "0xB8061EB8"
#define  CEC_GDI_CEC_COMPARE_OPCODE_11_reg                                       0xB8061EB8
#define  CEC_GDI_CEC_COMPARE_OPCODE_11_inst_addr                                 "0x002E"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_11_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_11_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_11_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_11_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_11_compare_opcode_11_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_11_compare_opcode_11_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_11_compare_opcode_11(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_11_get_compare_opcode_11(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_12                                           0x18061EBC
#define  CEC_GDI_CEC_COMPARE_OPCODE_12_reg_addr                                  "0xB8061EBC"
#define  CEC_GDI_CEC_COMPARE_OPCODE_12_reg                                       0xB8061EBC
#define  CEC_GDI_CEC_COMPARE_OPCODE_12_inst_addr                                 "0x002F"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_12_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_12_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_12_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_12_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_12_compare_opcode_12_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_12_compare_opcode_12_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_12_compare_opcode_12(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_12_get_compare_opcode_12(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_13                                           0x18061EC0
#define  CEC_GDI_CEC_COMPARE_OPCODE_13_reg_addr                                  "0xB8061EC0"
#define  CEC_GDI_CEC_COMPARE_OPCODE_13_reg                                       0xB8061EC0
#define  CEC_GDI_CEC_COMPARE_OPCODE_13_inst_addr                                 "0x0030"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_13_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_13_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_13_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_13_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_13_compare_opcode_13_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_13_compare_opcode_13_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_13_compare_opcode_13(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_13_get_compare_opcode_13(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_14                                           0x18061EC4
#define  CEC_GDI_CEC_COMPARE_OPCODE_14_reg_addr                                  "0xB8061EC4"
#define  CEC_GDI_CEC_COMPARE_OPCODE_14_reg                                       0xB8061EC4
#define  CEC_GDI_CEC_COMPARE_OPCODE_14_inst_addr                                 "0x0031"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_14_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_14_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_14_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_14_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_14_compare_opcode_14_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_14_compare_opcode_14_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_14_compare_opcode_14(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_14_get_compare_opcode_14(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_COMPARE_OPCODE_15                                           0x18061EC8
#define  CEC_GDI_CEC_COMPARE_OPCODE_15_reg_addr                                  "0xB8061EC8"
#define  CEC_GDI_CEC_COMPARE_OPCODE_15_reg                                       0xB8061EC8
#define  CEC_GDI_CEC_COMPARE_OPCODE_15_inst_addr                                 "0x0032"
#define  set_CEC_GDI_CEC_COMPARE_OPCODE_15_reg(data)                             (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_15_reg)=data)
#define  get_CEC_GDI_CEC_COMPARE_OPCODE_15_reg                                   (*((volatile unsigned int*)CEC_GDI_CEC_COMPARE_OPCODE_15_reg))
#define  CEC_GDI_CEC_COMPARE_OPCODE_15_compare_opcode_15_shift                   (0)
#define  CEC_GDI_CEC_COMPARE_OPCODE_15_compare_opcode_15_mask                    (0x000000FF)
#define  CEC_GDI_CEC_COMPARE_OPCODE_15_compare_opcode_15(data)                   (0x000000FF&(data))
#define  CEC_GDI_CEC_COMPARE_OPCODE_15_get_compare_opcode_15(data)               (0x000000FF&(data))

#define  CEC_GDI_CEC_OPCODE_ENABLE                                               0x18061ECC
#define  CEC_GDI_CEC_OPCODE_ENABLE_reg_addr                                      "0xB8061ECC"
#define  CEC_GDI_CEC_OPCODE_ENABLE_reg                                           0xB8061ECC
#define  CEC_GDI_CEC_OPCODE_ENABLE_inst_addr                                     "0x0033"
#define  set_CEC_GDI_CEC_OPCODE_ENABLE_reg(data)                                 (*((volatile unsigned int*)CEC_GDI_CEC_OPCODE_ENABLE_reg)=data)
#define  get_CEC_GDI_CEC_OPCODE_ENABLE_reg                                       (*((volatile unsigned int*)CEC_GDI_CEC_OPCODE_ENABLE_reg))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_15_shift                    (14)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_14_shift                    (13)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_13_shift                    (12)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_12_shift                    (11)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_11_shift                    (10)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_10_shift                    (9)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_09_shift                    (8)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_08_shift                    (7)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_07_shift                    (6)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_06_shift                    (5)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_05_shift                    (4)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_04_shift                    (3)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_03_shift                    (2)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_02_shift                    (1)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_01_shift                    (0)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_15_mask                     (0x00004000)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_14_mask                     (0x00002000)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_13_mask                     (0x00001000)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_12_mask                     (0x00000800)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_11_mask                     (0x00000400)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_10_mask                     (0x00000200)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_09_mask                     (0x00000100)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_08_mask                     (0x00000080)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_07_mask                     (0x00000040)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_06_mask                     (0x00000020)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_05_mask                     (0x00000010)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_04_mask                     (0x00000008)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_03_mask                     (0x00000004)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_02_mask                     (0x00000002)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_01_mask                     (0x00000001)
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_15(data)                    (0x00004000&((data)<<14))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_14(data)                    (0x00002000&((data)<<13))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_13(data)                    (0x00001000&((data)<<12))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_12(data)                    (0x00000800&((data)<<11))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_11(data)                    (0x00000400&((data)<<10))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_10(data)                    (0x00000200&((data)<<9))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_09(data)                    (0x00000100&((data)<<8))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_08(data)                    (0x00000080&((data)<<7))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_07(data)                    (0x00000040&((data)<<6))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_06(data)                    (0x00000020&((data)<<5))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_05(data)                    (0x00000010&((data)<<4))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_04(data)                    (0x00000008&((data)<<3))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_03(data)                    (0x00000004&((data)<<2))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_02(data)                    (0x00000002&((data)<<1))
#define  CEC_GDI_CEC_OPCODE_ENABLE_en_compare_opcode_01(data)                    (0x00000001&(data))
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_15(data)                ((0x00004000&(data))>>14)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_14(data)                ((0x00002000&(data))>>13)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_13(data)                ((0x00001000&(data))>>12)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_12(data)                ((0x00000800&(data))>>11)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_11(data)                ((0x00000400&(data))>>10)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_10(data)                ((0x00000200&(data))>>9)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_09(data)                ((0x00000100&(data))>>8)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_08(data)                ((0x00000080&(data))>>7)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_07(data)                ((0x00000040&(data))>>6)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_06(data)                ((0x00000020&(data))>>5)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_05(data)                ((0x00000010&(data))>>4)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_04(data)                ((0x00000008&(data))>>3)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_03(data)                ((0x00000004&(data))>>2)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_02(data)                ((0x00000002&(data))>>1)
#define  CEC_GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_01(data)                (0x00000001&(data))

#define  CEC_GDI_POWER_SAVING_MODE                                               0x18061ED0
#define  CEC_GDI_POWER_SAVING_MODE_reg_addr                                      "0xB8061ED0"
#define  CEC_GDI_POWER_SAVING_MODE_reg                                           0xB8061ED0
#define  CEC_GDI_POWER_SAVING_MODE_inst_addr                                     "0x0034"
#define  set_CEC_GDI_POWER_SAVING_MODE_reg(data)                                 (*((volatile unsigned int*)CEC_GDI_POWER_SAVING_MODE_reg)=data)
#define  get_CEC_GDI_POWER_SAVING_MODE_reg                                       (*((volatile unsigned int*)CEC_GDI_POWER_SAVING_MODE_reg))
#define  CEC_GDI_POWER_SAVING_MODE_irq_pending_shift                             (31)
#define  CEC_GDI_POWER_SAVING_MODE_cec_msg_status_01_shift                       (25)
#define  CEC_GDI_POWER_SAVING_MODE_cec_msg_status_02_shift                       (24)
#define  CEC_GDI_POWER_SAVING_MODE_irq_by_cec_receive_special_cmd_shift          (8)
#define  CEC_GDI_POWER_SAVING_MODE_cec_rpu_en_shift                              (5)
#define  CEC_GDI_POWER_SAVING_MODE_cec_rsel_shift                                (0)
#define  CEC_GDI_POWER_SAVING_MODE_irq_pending_mask                              (0x80000000)
#define  CEC_GDI_POWER_SAVING_MODE_cec_msg_status_01_mask                        (0x02000000)
#define  CEC_GDI_POWER_SAVING_MODE_cec_msg_status_02_mask                        (0x01000000)
#define  CEC_GDI_POWER_SAVING_MODE_irq_by_cec_receive_special_cmd_mask           (0x00000100)
#define  CEC_GDI_POWER_SAVING_MODE_cec_rpu_en_mask                               (0x00000020)
#define  CEC_GDI_POWER_SAVING_MODE_cec_rsel_mask                                 (0x0000001F)
#define  CEC_GDI_POWER_SAVING_MODE_irq_pending(data)                             (0x80000000&((data)<<31))
#define  CEC_GDI_POWER_SAVING_MODE_cec_msg_status_01(data)                       (0x02000000&((data)<<25))
#define  CEC_GDI_POWER_SAVING_MODE_cec_msg_status_02(data)                       (0x01000000&((data)<<24))
#define  CEC_GDI_POWER_SAVING_MODE_irq_by_cec_receive_special_cmd(data)          (0x00000100&((data)<<8))
#define  CEC_GDI_POWER_SAVING_MODE_cec_rpu_en(data)                              (0x00000020&((data)<<5))
#define  CEC_GDI_POWER_SAVING_MODE_cec_rsel(data)                                (0x0000001F&(data))
#define  CEC_GDI_POWER_SAVING_MODE_get_irq_pending(data)                         ((0x80000000&(data))>>31)
#define  CEC_GDI_POWER_SAVING_MODE_get_cec_msg_status_01(data)                   ((0x02000000&(data))>>25)
#define  CEC_GDI_POWER_SAVING_MODE_get_cec_msg_status_02(data)                   ((0x01000000&(data))>>24)
#define  CEC_GDI_POWER_SAVING_MODE_get_irq_by_cec_receive_special_cmd(data)      ((0x00000100&(data))>>8)
#define  CEC_GDI_POWER_SAVING_MODE_get_cec_rpu_en(data)                          ((0x00000020&(data))>>5)
#define  CEC_GDI_POWER_SAVING_MODE_get_cec_rsel(data)                            (0x0000001F&(data))

#define  CEC_CEC_RxACKTCR0                                                       0x18061ED4
#define  CEC_CEC_RxACKTCR0_reg_addr                                              "0xB8061ED4"
#define  CEC_CEC_RxACKTCR0_reg                                                   0xB8061ED4
#define  CEC_CEC_RxACKTCR0_inst_addr                                             "0x0035"
#define  set_CEC_CEC_RxACKTCR0_reg(data)                                         (*((volatile unsigned int*)CEC_CEC_RxACKTCR0_reg)=data)
#define  get_CEC_CEC_RxACKTCR0_reg                                               (*((volatile unsigned int*)CEC_CEC_RxACKTCR0_reg))
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_1_sel_shift                               (26)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_2_sel_shift                               (25)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_3_sel_shift                               (24)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_1_shift                                   (16)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_2_shift                                   (8)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_3_shift                                   (0)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_1_sel_mask                                (0x04000000)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_2_sel_mask                                (0x02000000)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_3_sel_mask                                (0x01000000)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_1_mask                                    (0x00FF0000)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_2_mask                                    (0x0000FF00)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_3_mask                                    (0x000000FF)
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_1_sel(data)                               (0x04000000&((data)<<26))
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_2_sel(data)                               (0x02000000&((data)<<25))
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_3_sel(data)                               (0x01000000&((data)<<24))
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_1(data)                                   (0x00FF0000&((data)<<16))
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_2(data)                                   (0x0000FF00&((data)<<8))
#define  CEC_CEC_RxACKTCR0_rx_ack_wait_3(data)                                   (0x000000FF&(data))
#define  CEC_CEC_RxACKTCR0_get_rx_ack_wait_1_sel(data)                           ((0x04000000&(data))>>26)
#define  CEC_CEC_RxACKTCR0_get_rx_ack_wait_2_sel(data)                           ((0x02000000&(data))>>25)
#define  CEC_CEC_RxACKTCR0_get_rx_ack_wait_3_sel(data)                           ((0x01000000&(data))>>24)
#define  CEC_CEC_RxACKTCR0_get_rx_ack_wait_1(data)                               ((0x00FF0000&(data))>>16)
#define  CEC_CEC_RxACKTCR0_get_rx_ack_wait_2(data)                               ((0x0000FF00&(data))>>8)
#define  CEC_CEC_RxACKTCR0_get_rx_ack_wait_3(data)                               (0x000000FF&(data))

#define  CEC_CEC_RxACKTCR1                                                       0x18061ED8
#define  CEC_CEC_RxACKTCR1_reg_addr                                              "0xB8061ED8"
#define  CEC_CEC_RxACKTCR1_reg                                                   0xB8061ED8
#define  CEC_CEC_RxACKTCR1_inst_addr                                             "0x0036"
#define  set_CEC_CEC_RxACKTCR1_reg(data)                                         (*((volatile unsigned int*)CEC_CEC_RxACKTCR1_reg)=data)
#define  get_CEC_CEC_RxACKTCR1_reg                                               (*((volatile unsigned int*)CEC_CEC_RxACKTCR1_reg))
#define  CEC_CEC_RxACKTCR1_rx_ack_low_sel_shift                                  (26)
#define  CEC_CEC_RxACKTCR1_rx_ack_bit_sel_shift                                  (25)
#define  CEC_CEC_RxACKTCR1_rx_ack_line_err_sel_shift                             (24)
#define  CEC_CEC_RxACKTCR1_rx_ack_low_shift                                      (16)
#define  CEC_CEC_RxACKTCR1_rx_ack_bit_shift                                      (8)
#define  CEC_CEC_RxACKTCR1_rx_ack_line_err_shift                                 (0)
#define  CEC_CEC_RxACKTCR1_rx_ack_low_sel_mask                                   (0x04000000)
#define  CEC_CEC_RxACKTCR1_rx_ack_bit_sel_mask                                   (0x02000000)
#define  CEC_CEC_RxACKTCR1_rx_ack_line_err_sel_mask                              (0x01000000)
#define  CEC_CEC_RxACKTCR1_rx_ack_low_mask                                       (0x00FF0000)
#define  CEC_CEC_RxACKTCR1_rx_ack_bit_mask                                       (0x0000FF00)
#define  CEC_CEC_RxACKTCR1_rx_ack_line_err_mask                                  (0x000000FF)
#define  CEC_CEC_RxACKTCR1_rx_ack_low_sel(data)                                  (0x04000000&((data)<<26))
#define  CEC_CEC_RxACKTCR1_rx_ack_bit_sel(data)                                  (0x02000000&((data)<<25))
#define  CEC_CEC_RxACKTCR1_rx_ack_line_err_sel(data)                             (0x01000000&((data)<<24))
#define  CEC_CEC_RxACKTCR1_rx_ack_low(data)                                      (0x00FF0000&((data)<<16))
#define  CEC_CEC_RxACKTCR1_rx_ack_bit(data)                                      (0x0000FF00&((data)<<8))
#define  CEC_CEC_RxACKTCR1_rx_ack_line_err(data)                                 (0x000000FF&(data))
#define  CEC_CEC_RxACKTCR1_get_rx_ack_low_sel(data)                              ((0x04000000&(data))>>26)
#define  CEC_CEC_RxACKTCR1_get_rx_ack_bit_sel(data)                              ((0x02000000&(data))>>25)
#define  CEC_CEC_RxACKTCR1_get_rx_ack_line_err_sel(data)                         ((0x01000000&(data))>>24)
#define  CEC_CEC_RxACKTCR1_get_rx_ack_low(data)                                  ((0x00FF0000&(data))>>16)
#define  CEC_CEC_RxACKTCR1_get_rx_ack_bit(data)                                  ((0x0000FF00&(data))>>8)
#define  CEC_CEC_RxACKTCR1_get_rx_ack_line_err(data)                             (0x000000FF&(data))

#define  CEC_CEC_TxRxACKOPTION                                                   0x18061EDC
#define  CEC_CEC_TxRxACKOPTION_reg_addr                                          "0xB8061EDC"
#define  CEC_CEC_TxRxACKOPTION_reg                                               0xB8061EDC
#define  CEC_CEC_TxRxACKOPTION_inst_addr                                         "0x0037"
#define  set_CEC_CEC_TxRxACKOPTION_reg(data)                                     (*((volatile unsigned int*)CEC_CEC_TxRxACKOPTION_reg)=data)
#define  get_CEC_CEC_TxRxACKOPTION_reg                                           (*((volatile unsigned int*)CEC_CEC_TxRxACKOPTION_reg))
#define  CEC_CEC_TxRxACKOPTION_tx_send_another_shift                             (16)
#define  CEC_CEC_TxRxACKOPTION_other_device_access_after_ack_shift               (8)
#define  CEC_CEC_TxRxACKOPTION_tx_re_send_shift                                  (0)
#define  CEC_CEC_TxRxACKOPTION_tx_send_another_mask                              (0x000F0000)
#define  CEC_CEC_TxRxACKOPTION_other_device_access_after_ack_mask                (0x00000F00)
#define  CEC_CEC_TxRxACKOPTION_tx_re_send_mask                                   (0x0000000F)
#define  CEC_CEC_TxRxACKOPTION_tx_send_another(data)                             (0x000F0000&((data)<<16))
#define  CEC_CEC_TxRxACKOPTION_other_device_access_after_ack(data)               (0x00000F00&((data)<<8))
#define  CEC_CEC_TxRxACKOPTION_tx_re_send(data)                                  (0x0000000F&(data))
#define  CEC_CEC_TxRxACKOPTION_get_tx_send_another(data)                         ((0x000F0000&(data))>>16)
#define  CEC_CEC_TxRxACKOPTION_get_other_device_access_after_ack(data)           ((0x00000F00&(data))>>8)
#define  CEC_CEC_TxRxACKOPTION_get_tx_re_send(data)                              (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CEC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cec_mode:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  test_mode_pad_en:1;
        RBus_UInt32  logical_addr:4;
        RBus_UInt32  timer_div:8;
        RBus_UInt32  pre_div:8;
        RBus_UInt32  unreg_ack_en:1;
        RBus_UInt32  cec_in_deb_mode:1;
        RBus_UInt32  cdc_arbitration_en:1;
        RBus_UInt32  test_mode_pad_data:5;
    };
}cec_cec_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cec_pad_in:1;
        RBus_UInt32  dummy18061e04_30_18:13;
        RBus_UInt32  cec_pad_en:1;
        RBus_UInt32  cec_pad_en_mode:1;
        RBus_UInt32  dummy18061e04_15_14:2;
        RBus_UInt32  cec_hw_retry_mode:1;
        RBus_UInt32  cec_hw_retry_en:1;
        RBus_UInt32  clear_cec_int:1;
        RBus_UInt32  wt_cnt:6;
        RBus_UInt32  lattest:1;
        RBus_UInt32  retry_no:4;
    };
}cec_cec_rtcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  broadcast_addr:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  rx_same_la_direct_nack:1;
        RBus_UInt32  rx_no_accept_command_data:1;
        RBus_UInt32  rx_same_la_ack:1;
        RBus_UInt32  rx_clear_fifo_data_en:1;
        RBus_UInt32  rx_clear_fifo_data_mode:1;
        RBus_UInt32  rx_clear_fifo_data_fw:1;
        RBus_UInt32  standby_addr_sel:1;
        RBus_UInt32  standby_init_addr:4;
        RBus_UInt32  rx_en:1;
        RBus_UInt32  rx_rst:1;
        RBus_UInt32  rx_continuous:1;
        RBus_UInt32  rx_int_en:1;
        RBus_UInt32  init_addr:4;
        RBus_UInt32  rx_eom:1;
        RBus_UInt32  rx_int:1;
        RBus_UInt32  rx_fifo_ov:1;
        RBus_UInt32  rx_fifo_cnt:5;
    };
}cec_cec_rxcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  tx_addr_en:1;
        RBus_UInt32  tx_addr:4;
        RBus_UInt32  tx_en:1;
        RBus_UInt32  tx_rst:1;
        RBus_UInt32  tx_continuous:1;
        RBus_UInt32  tx_int_en:1;
        RBus_UInt32  dest_addr:4;
        RBus_UInt32  tx_eom:1;
        RBus_UInt32  tx_int:1;
        RBus_UInt32  tx_fifo_ud:1;
        RBus_UInt32  tx_fifo_cnt:5;
    };
}cec_cec_txcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  tx_add_cnt:1;
        RBus_UInt32  rx_sub_cnt:1;
        RBus_UInt32  fifo_cnt:5;
    };
}cec_cec_txdr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_fifo_0:8;
        RBus_UInt32  tx_fifo_1:8;
        RBus_UInt32  tx_fifo_2:8;
        RBus_UInt32  tx_fifo_3:8;
    };
}cec_cec_txdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_fifo_4:8;
        RBus_UInt32  tx_fifo_5:8;
        RBus_UInt32  tx_fifo_6:8;
        RBus_UInt32  tx_fifo_7:8;
    };
}cec_cec_txdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_fifo_8:8;
        RBus_UInt32  tx_fifo_9:8;
        RBus_UInt32  tx_fifo_a:8;
        RBus_UInt32  tx_fifo_b:8;
    };
}cec_cec_txdr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_fifo_c:8;
        RBus_UInt32  tx_fifo_d:8;
        RBus_UInt32  tx_fifo_e:8;
        RBus_UInt32  tx_fifo_f:8;
    };
}cec_cec_txdr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_0:8;
        RBus_UInt32  rx_fifo_1:8;
        RBus_UInt32  rx_fifo_2:8;
        RBus_UInt32  rx_fifo_3:8;
    };
}cec_cec_rxdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_4:8;
        RBus_UInt32  rx_fifo_5:8;
        RBus_UInt32  rx_fifo_6:8;
        RBus_UInt32  rx_fifo_7:8;
    };
}cec_cec_rxdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_8:8;
        RBus_UInt32  rx_fifo_9:8;
        RBus_UInt32  rx_fifo_a:8;
        RBus_UInt32  rx_fifo_b:8;
    };
}cec_cec_rxdr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_c:8;
        RBus_UInt32  rx_fifo_d:8;
        RBus_UInt32  rx_fifo_e:8;
        RBus_UInt32  rx_fifo_f:8;
    };
}cec_cec_rxdr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_start_low:8;
        RBus_UInt32  rx_start_period:8;
        RBus_UInt32  rx_data_sample:8;
        RBus_UInt32  rx_data_period:8;
    };
}cec_cec_rxtcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tx_start_low:8;
        RBus_UInt32  tx_start_high:8;
    };
}cec_cec_txtcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tx_data_low:8;
        RBus_UInt32  tx_data_01:8;
        RBus_UInt32  tx_data_high:8;
    };
}cec_cec_txtcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_01:8;
    };
}cec_gdi_cec_compare_opcode_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  send_init_address_01:1;
        RBus_UInt32  init_address_01:4;
        RBus_UInt32  send_opcode_01:8;
    };
}cec_gdi_cec_send_opcode_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:6;
        RBus_UInt32  operand_number_01:2;
    };
}cec_gdi_cec_send_operand_number_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_01:8;
    };
}cec_gdi_cec_operand_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_02:8;
    };
}cec_gdi_cec_operand_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_03:8;
    };
}cec_gdi_cec_operand_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_02:8;
    };
}cec_gdi_cec_compare_opcode_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  send_init_address_02:1;
        RBus_UInt32  init_address_02:4;
        RBus_UInt32  send_opcode_02:8;
    };
}cec_gdi_cec_send_opcode_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:6;
        RBus_UInt32  operand_number_02:2;
    };
}cec_gdi_cec_send_operand_number_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_04:8;
    };
}cec_gdi_cec_operand_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_05:8;
    };
}cec_gdi_cec_operand_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_06:8;
    };
}cec_gdi_cec_operand_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_03:8;
    };
}cec_gdi_cec_compare_opcode_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  send_init_address_03:1;
        RBus_UInt32  init_address_03:4;
        RBus_UInt32  send_opcode_03:8;
    };
}cec_gdi_cec_send_opcode_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:6;
        RBus_UInt32  operand_number_03:2;
    };
}cec_gdi_cec_send_operand_number_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_07:8;
    };
}cec_gdi_cec_operand_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_08:8;
    };
}cec_gdi_cec_operand_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_09:8;
    };
}cec_gdi_cec_operand_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_04:8;
    };
}cec_gdi_cec_compare_opcode_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  send_init_address_04:1;
        RBus_UInt32  init_address_04:4;
        RBus_UInt32  send_opcode_04:8;
    };
}cec_gdi_cec_send_opcode_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:6;
        RBus_UInt32  operand_number_04:2;
    };
}cec_gdi_cec_send_operand_number_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_10:8;
    };
}cec_gdi_cec_operand_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_11:8;
    };
}cec_gdi_cec_operand_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  operand_12:8;
    };
}cec_gdi_cec_operand_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_05:8;
    };
}cec_gdi_cec_compare_opcode_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_06:8;
    };
}cec_gdi_cec_compare_opcode_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_07:8;
    };
}cec_gdi_cec_compare_opcode_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_08:8;
    };
}cec_gdi_cec_compare_opcode_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_09:8;
    };
}cec_gdi_cec_compare_opcode_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_10:8;
    };
}cec_gdi_cec_compare_opcode_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_11:8;
    };
}cec_gdi_cec_compare_opcode_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_12:8;
    };
}cec_gdi_cec_compare_opcode_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_13:8;
    };
}cec_gdi_cec_compare_opcode_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_14:8;
    };
}cec_gdi_cec_compare_opcode_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  compare_opcode_15:8;
    };
}cec_gdi_cec_compare_opcode_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  en_compare_opcode_15:1;
        RBus_UInt32  en_compare_opcode_14:1;
        RBus_UInt32  en_compare_opcode_13:1;
        RBus_UInt32  en_compare_opcode_12:1;
        RBus_UInt32  en_compare_opcode_11:1;
        RBus_UInt32  en_compare_opcode_10:1;
        RBus_UInt32  en_compare_opcode_09:1;
        RBus_UInt32  en_compare_opcode_08:1;
        RBus_UInt32  en_compare_opcode_07:1;
        RBus_UInt32  en_compare_opcode_06:1;
        RBus_UInt32  en_compare_opcode_05:1;
        RBus_UInt32  en_compare_opcode_04:1;
        RBus_UInt32  en_compare_opcode_03:1;
        RBus_UInt32  en_compare_opcode_02:1;
        RBus_UInt32  en_compare_opcode_01:1;
    };
}cec_gdi_cec_opcode_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irq_pending:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  cec_msg_status_01:1;
        RBus_UInt32  cec_msg_status_02:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  irq_by_cec_receive_special_cmd:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  cec_rpu_en:1;
        RBus_UInt32  cec_rsel:5;
    };
}cec_gdi_power_saving_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  rx_ack_wait_1_sel:1;
        RBus_UInt32  rx_ack_wait_2_sel:1;
        RBus_UInt32  rx_ack_wait_3_sel:1;
        RBus_UInt32  rx_ack_wait_1:8;
        RBus_UInt32  rx_ack_wait_2:8;
        RBus_UInt32  rx_ack_wait_3:8;
    };
}cec_cec_rxacktcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  rx_ack_low_sel:1;
        RBus_UInt32  rx_ack_bit_sel:1;
        RBus_UInt32  rx_ack_line_err_sel:1;
        RBus_UInt32  rx_ack_low:8;
        RBus_UInt32  rx_ack_bit:8;
        RBus_UInt32  rx_ack_line_err:8;
    };
}cec_cec_rxacktcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  tx_send_another:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  other_device_access_after_ack:4;
        RBus_UInt32  res3:4;
        RBus_UInt32  tx_re_send:4;
    };
}cec_cec_txrxackoption_RBUS;

#else //apply LITTLE_ENDIAN

//======CEC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode_pad_data:5;
        RBus_UInt32  cdc_arbitration_en:1;
        RBus_UInt32  cec_in_deb_mode:1;
        RBus_UInt32  unreg_ack_en:1;
        RBus_UInt32  pre_div:8;
        RBus_UInt32  timer_div:8;
        RBus_UInt32  logical_addr:4;
        RBus_UInt32  test_mode_pad_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cec_mode:2;
    };
}cec_cec_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  retry_no:4;
        RBus_UInt32  lattest:1;
        RBus_UInt32  wt_cnt:6;
        RBus_UInt32  clear_cec_int:1;
        RBus_UInt32  cec_hw_retry_en:1;
        RBus_UInt32  cec_hw_retry_mode:1;
        RBus_UInt32  dummy18061e04_15_14:2;
        RBus_UInt32  cec_pad_en_mode:1;
        RBus_UInt32  cec_pad_en:1;
        RBus_UInt32  dummy18061e04_30_18:13;
        RBus_UInt32  cec_pad_in:1;
    };
}cec_cec_rtcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_cnt:5;
        RBus_UInt32  rx_fifo_ov:1;
        RBus_UInt32  rx_int:1;
        RBus_UInt32  rx_eom:1;
        RBus_UInt32  init_addr:4;
        RBus_UInt32  rx_int_en:1;
        RBus_UInt32  rx_continuous:1;
        RBus_UInt32  rx_rst:1;
        RBus_UInt32  rx_en:1;
        RBus_UInt32  standby_init_addr:4;
        RBus_UInt32  standby_addr_sel:1;
        RBus_UInt32  rx_clear_fifo_data_fw:1;
        RBus_UInt32  rx_clear_fifo_data_mode:1;
        RBus_UInt32  rx_clear_fifo_data_en:1;
        RBus_UInt32  rx_same_la_ack:1;
        RBus_UInt32  rx_no_accept_command_data:1;
        RBus_UInt32  rx_same_la_direct_nack:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  broadcast_addr:1;
    };
}cec_cec_rxcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_fifo_cnt:5;
        RBus_UInt32  tx_fifo_ud:1;
        RBus_UInt32  tx_int:1;
        RBus_UInt32  tx_eom:1;
        RBus_UInt32  dest_addr:4;
        RBus_UInt32  tx_int_en:1;
        RBus_UInt32  tx_continuous:1;
        RBus_UInt32  tx_rst:1;
        RBus_UInt32  tx_en:1;
        RBus_UInt32  tx_addr:4;
        RBus_UInt32  tx_addr_en:1;
        RBus_UInt32  res1:11;
    };
}cec_cec_txcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_cnt:5;
        RBus_UInt32  rx_sub_cnt:1;
        RBus_UInt32  tx_add_cnt:1;
        RBus_UInt32  res1:25;
    };
}cec_cec_txdr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_fifo_3:8;
        RBus_UInt32  tx_fifo_2:8;
        RBus_UInt32  tx_fifo_1:8;
        RBus_UInt32  tx_fifo_0:8;
    };
}cec_cec_txdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_fifo_7:8;
        RBus_UInt32  tx_fifo_6:8;
        RBus_UInt32  tx_fifo_5:8;
        RBus_UInt32  tx_fifo_4:8;
    };
}cec_cec_txdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_fifo_b:8;
        RBus_UInt32  tx_fifo_a:8;
        RBus_UInt32  tx_fifo_9:8;
        RBus_UInt32  tx_fifo_8:8;
    };
}cec_cec_txdr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_fifo_f:8;
        RBus_UInt32  tx_fifo_e:8;
        RBus_UInt32  tx_fifo_d:8;
        RBus_UInt32  tx_fifo_c:8;
    };
}cec_cec_txdr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_3:8;
        RBus_UInt32  rx_fifo_2:8;
        RBus_UInt32  rx_fifo_1:8;
        RBus_UInt32  rx_fifo_0:8;
    };
}cec_cec_rxdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_7:8;
        RBus_UInt32  rx_fifo_6:8;
        RBus_UInt32  rx_fifo_5:8;
        RBus_UInt32  rx_fifo_4:8;
    };
}cec_cec_rxdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_b:8;
        RBus_UInt32  rx_fifo_a:8;
        RBus_UInt32  rx_fifo_9:8;
        RBus_UInt32  rx_fifo_8:8;
    };
}cec_cec_rxdr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_fifo_f:8;
        RBus_UInt32  rx_fifo_e:8;
        RBus_UInt32  rx_fifo_d:8;
        RBus_UInt32  rx_fifo_c:8;
    };
}cec_cec_rxdr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_data_period:8;
        RBus_UInt32  rx_data_sample:8;
        RBus_UInt32  rx_start_period:8;
        RBus_UInt32  rx_start_low:8;
    };
}cec_cec_rxtcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_start_high:8;
        RBus_UInt32  tx_start_low:8;
        RBus_UInt32  res1:16;
    };
}cec_cec_txtcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_data_high:8;
        RBus_UInt32  tx_data_01:8;
        RBus_UInt32  tx_data_low:8;
        RBus_UInt32  res1:8;
    };
}cec_cec_txtcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_01:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  send_opcode_01:8;
        RBus_UInt32  init_address_01:4;
        RBus_UInt32  send_init_address_01:1;
        RBus_UInt32  res1:19;
    };
}cec_gdi_cec_send_opcode_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_number_01:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  res2:24;
    };
}cec_gdi_cec_send_operand_number_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_01:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_02:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_03:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_02:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  send_opcode_02:8;
        RBus_UInt32  init_address_02:4;
        RBus_UInt32  send_init_address_02:1;
        RBus_UInt32  res1:19;
    };
}cec_gdi_cec_send_opcode_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_number_02:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  res2:24;
    };
}cec_gdi_cec_send_operand_number_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_04:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_05:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_06:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_03:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  send_opcode_03:8;
        RBus_UInt32  init_address_03:4;
        RBus_UInt32  send_init_address_03:1;
        RBus_UInt32  res1:19;
    };
}cec_gdi_cec_send_opcode_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_number_03:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  res2:24;
    };
}cec_gdi_cec_send_operand_number_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_07:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_08:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_09:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_04:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  send_opcode_04:8;
        RBus_UInt32  init_address_04:4;
        RBus_UInt32  send_init_address_04:1;
        RBus_UInt32  res1:19;
    };
}cec_gdi_cec_send_opcode_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_number_04:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  res2:24;
    };
}cec_gdi_cec_send_operand_number_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_10:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_11:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  operand_12:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_operand_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_05:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_06:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_07:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_08:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_09:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_10:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_11:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_12:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_13:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_14:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  compare_opcode_15:8;
        RBus_UInt32  res1:24;
    };
}cec_gdi_cec_compare_opcode_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_compare_opcode_01:1;
        RBus_UInt32  en_compare_opcode_02:1;
        RBus_UInt32  en_compare_opcode_03:1;
        RBus_UInt32  en_compare_opcode_04:1;
        RBus_UInt32  en_compare_opcode_05:1;
        RBus_UInt32  en_compare_opcode_06:1;
        RBus_UInt32  en_compare_opcode_07:1;
        RBus_UInt32  en_compare_opcode_08:1;
        RBus_UInt32  en_compare_opcode_09:1;
        RBus_UInt32  en_compare_opcode_10:1;
        RBus_UInt32  en_compare_opcode_11:1;
        RBus_UInt32  en_compare_opcode_12:1;
        RBus_UInt32  en_compare_opcode_13:1;
        RBus_UInt32  en_compare_opcode_14:1;
        RBus_UInt32  en_compare_opcode_15:1;
        RBus_UInt32  res1:17;
    };
}cec_gdi_cec_opcode_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cec_rsel:5;
        RBus_UInt32  cec_rpu_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  irq_by_cec_receive_special_cmd:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  cec_msg_status_02:1;
        RBus_UInt32  cec_msg_status_01:1;
        RBus_UInt32  res3:5;
        RBus_UInt32  irq_pending:1;
    };
}cec_gdi_power_saving_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_ack_wait_3:8;
        RBus_UInt32  rx_ack_wait_2:8;
        RBus_UInt32  rx_ack_wait_1:8;
        RBus_UInt32  rx_ack_wait_3_sel:1;
        RBus_UInt32  rx_ack_wait_2_sel:1;
        RBus_UInt32  rx_ack_wait_1_sel:1;
        RBus_UInt32  res1:5;
    };
}cec_cec_rxacktcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_ack_line_err:8;
        RBus_UInt32  rx_ack_bit:8;
        RBus_UInt32  rx_ack_low:8;
        RBus_UInt32  rx_ack_line_err_sel:1;
        RBus_UInt32  rx_ack_bit_sel:1;
        RBus_UInt32  rx_ack_low_sel:1;
        RBus_UInt32  res1:5;
    };
}cec_cec_rxacktcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_re_send:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  other_device_access_after_ack:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  tx_send_another:4;
        RBus_UInt32  res3:12;
    };
}cec_cec_txrxackoption_RBUS;




#endif 


#endif 
