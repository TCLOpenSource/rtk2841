/**
* @file rbusMISC_SMARTCARD0Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MISC_SMARTCARD0_REG_H_
#define _RBUS_MISC_SMARTCARD0_REG_H_

#include "rbus_types.h"



//  MISC_SMARTCARD0 Register Address
#define  MISC_SMARTCARD0_SC_FP                                                   0x1801B800
#define  MISC_SMARTCARD0_SC_FP_reg_addr                                          "0xB801B800"
#define  MISC_SMARTCARD0_SC_FP_reg                                               0xB801B800
#define  MISC_SMARTCARD0_SC_FP_inst_addr                                         "0x0000"
#define  set_MISC_SMARTCARD0_SC_FP_reg(data)                                     (*((volatile unsigned int*)MISC_SMARTCARD0_SC_FP_reg)=data)
#define  get_MISC_SMARTCARD0_SC_FP_reg                                           (*((volatile unsigned int*)MISC_SMARTCARD0_SC_FP_reg))
#define  MISC_SMARTCARD0_SC_FP_clk_en_shift                                      (24)
#define  MISC_SMARTCARD0_SC_FP_sc_clkdiv_shift                                   (18)
#define  MISC_SMARTCARD0_SC_FP_bauddiv2_shift                                    (16)
#define  MISC_SMARTCARD0_SC_FP_bauddiv1_shift                                    (8)
#define  MISC_SMARTCARD0_SC_FP_pre_clkdiv_shift                                  (0)
#define  MISC_SMARTCARD0_SC_FP_clk_en_mask                                       (0x01000000)
#define  MISC_SMARTCARD0_SC_FP_sc_clkdiv_mask                                    (0x00FC0000)
#define  MISC_SMARTCARD0_SC_FP_bauddiv2_mask                                     (0x00030000)
#define  MISC_SMARTCARD0_SC_FP_bauddiv1_mask                                     (0x0000FF00)
#define  MISC_SMARTCARD0_SC_FP_pre_clkdiv_mask                                   (0x000000FF)
#define  MISC_SMARTCARD0_SC_FP_clk_en(data)                                      (0x01000000&((data)<<24))
#define  MISC_SMARTCARD0_SC_FP_sc_clkdiv(data)                                   (0x00FC0000&((data)<<18))
#define  MISC_SMARTCARD0_SC_FP_bauddiv2(data)                                    (0x00030000&((data)<<16))
#define  MISC_SMARTCARD0_SC_FP_bauddiv1(data)                                    (0x0000FF00&((data)<<8))
#define  MISC_SMARTCARD0_SC_FP_pre_clkdiv(data)                                  (0x000000FF&(data))
#define  MISC_SMARTCARD0_SC_FP_get_clk_en(data)                                  ((0x01000000&(data))>>24)
#define  MISC_SMARTCARD0_SC_FP_get_sc_clkdiv(data)                               ((0x00FC0000&(data))>>18)
#define  MISC_SMARTCARD0_SC_FP_get_bauddiv2(data)                                ((0x00030000&(data))>>16)
#define  MISC_SMARTCARD0_SC_FP_get_bauddiv1(data)                                ((0x0000FF00&(data))>>8)
#define  MISC_SMARTCARD0_SC_FP_get_pre_clkdiv(data)                              (0x000000FF&(data))

#define  MISC_SMARTCARD0_SC_CR                                                   0x1801B804
#define  MISC_SMARTCARD0_SC_CR_reg_addr                                          "0xB801B804"
#define  MISC_SMARTCARD0_SC_CR_reg                                               0xB801B804
#define  MISC_SMARTCARD0_SC_CR_inst_addr                                         "0x0001"
#define  set_MISC_SMARTCARD0_SC_CR_reg(data)                                     (*((volatile unsigned int*)MISC_SMARTCARD0_SC_CR_reg)=data)
#define  get_MISC_SMARTCARD0_SC_CR_reg                                           (*((volatile unsigned int*)MISC_SMARTCARD0_SC_CR_reg))
#define  MISC_SMARTCARD0_SC_CR_fifo_rst_shift                                    (31)
#define  MISC_SMARTCARD0_SC_CR_rst_shift                                         (30)
#define  MISC_SMARTCARD0_SC_CR_scen_shift                                        (29)
#define  MISC_SMARTCARD0_SC_CR_tx_go_shift                                       (28)
#define  MISC_SMARTCARD0_SC_CR_auto_atr_shift                                    (27)
#define  MISC_SMARTCARD0_SC_CR_conv_shift                                        (26)
#define  MISC_SMARTCARD0_SC_CR_clk_stop_shift                                    (25)
#define  MISC_SMARTCARD0_SC_CR_ps_shift                                          (24)
#define  MISC_SMARTCARD0_SC_CR_mask_sc_pres_shift                                (23)
#define  MISC_SMARTCARD0_SC_CR_rst_waitmode_shift                                (22)
#define  MISC_SMARTCARD0_SC_CR_scc_conv_shift                                    (20)
#define  MISC_SMARTCARD0_SC_CR_act_seq_shift                                     (19)
#define  MISC_SMARTCARD0_SC_CR_fifo_rst_mask                                     (0x80000000)
#define  MISC_SMARTCARD0_SC_CR_rst_mask                                          (0x40000000)
#define  MISC_SMARTCARD0_SC_CR_scen_mask                                         (0x20000000)
#define  MISC_SMARTCARD0_SC_CR_tx_go_mask                                        (0x10000000)
#define  MISC_SMARTCARD0_SC_CR_auto_atr_mask                                     (0x08000000)
#define  MISC_SMARTCARD0_SC_CR_conv_mask                                         (0x04000000)
#define  MISC_SMARTCARD0_SC_CR_clk_stop_mask                                     (0x02000000)
#define  MISC_SMARTCARD0_SC_CR_ps_mask                                           (0x01000000)
#define  MISC_SMARTCARD0_SC_CR_mask_sc_pres_mask                                 (0x00800000)
#define  MISC_SMARTCARD0_SC_CR_rst_waitmode_mask                                 (0x00400000)
#define  MISC_SMARTCARD0_SC_CR_scc_conv_mask                                     (0x00100000)
#define  MISC_SMARTCARD0_SC_CR_act_seq_mask                                      (0x00080000)
#define  MISC_SMARTCARD0_SC_CR_fifo_rst(data)                                    (0x80000000&((data)<<31))
#define  MISC_SMARTCARD0_SC_CR_rst(data)                                         (0x40000000&((data)<<30))
#define  MISC_SMARTCARD0_SC_CR_scen(data)                                        (0x20000000&((data)<<29))
#define  MISC_SMARTCARD0_SC_CR_tx_go(data)                                       (0x10000000&((data)<<28))
#define  MISC_SMARTCARD0_SC_CR_auto_atr(data)                                    (0x08000000&((data)<<27))
#define  MISC_SMARTCARD0_SC_CR_conv(data)                                        (0x04000000&((data)<<26))
#define  MISC_SMARTCARD0_SC_CR_clk_stop(data)                                    (0x02000000&((data)<<25))
#define  MISC_SMARTCARD0_SC_CR_ps(data)                                          (0x01000000&((data)<<24))
#define  MISC_SMARTCARD0_SC_CR_mask_sc_pres(data)                                (0x00800000&((data)<<23))
#define  MISC_SMARTCARD0_SC_CR_rst_waitmode(data)                                (0x00400000&((data)<<22))
#define  MISC_SMARTCARD0_SC_CR_scc_conv(data)                                    (0x00100000&((data)<<20))
#define  MISC_SMARTCARD0_SC_CR_act_seq(data)                                     (0x00080000&((data)<<19))
#define  MISC_SMARTCARD0_SC_CR_get_fifo_rst(data)                                ((0x80000000&(data))>>31)
#define  MISC_SMARTCARD0_SC_CR_get_rst(data)                                     ((0x40000000&(data))>>30)
#define  MISC_SMARTCARD0_SC_CR_get_scen(data)                                    ((0x20000000&(data))>>29)
#define  MISC_SMARTCARD0_SC_CR_get_tx_go(data)                                   ((0x10000000&(data))>>28)
#define  MISC_SMARTCARD0_SC_CR_get_auto_atr(data)                                ((0x08000000&(data))>>27)
#define  MISC_SMARTCARD0_SC_CR_get_conv(data)                                    ((0x04000000&(data))>>26)
#define  MISC_SMARTCARD0_SC_CR_get_clk_stop(data)                                ((0x02000000&(data))>>25)
#define  MISC_SMARTCARD0_SC_CR_get_ps(data)                                      ((0x01000000&(data))>>24)
#define  MISC_SMARTCARD0_SC_CR_get_mask_sc_pres(data)                            ((0x00800000&(data))>>23)
#define  MISC_SMARTCARD0_SC_CR_get_rst_waitmode(data)                            ((0x00400000&(data))>>22)
#define  MISC_SMARTCARD0_SC_CR_get_scc_conv(data)                                ((0x00100000&(data))>>20)
#define  MISC_SMARTCARD0_SC_CR_get_act_seq(data)                                 ((0x00080000&(data))>>19)

#define  MISC_SMARTCARD0_SC_PCR                                                  0x1801B808
#define  MISC_SMARTCARD0_SC_PCR_reg_addr                                         "0xB801B808"
#define  MISC_SMARTCARD0_SC_PCR_reg                                              0xB801B808
#define  MISC_SMARTCARD0_SC_PCR_inst_addr                                        "0x0002"
#define  set_MISC_SMARTCARD0_SC_PCR_reg(data)                                    (*((volatile unsigned int*)MISC_SMARTCARD0_SC_PCR_reg)=data)
#define  get_MISC_SMARTCARD0_SC_PCR_reg                                          (*((volatile unsigned int*)MISC_SMARTCARD0_SC_PCR_reg))
#define  MISC_SMARTCARD0_SC_PCR_txgrdt_shift                                     (24)
#define  MISC_SMARTCARD0_SC_PCR_cwi_shift                                        (20)
#define  MISC_SMARTCARD0_SC_PCR_bwi_shift                                        (16)
#define  MISC_SMARTCARD0_SC_PCR_wwi_shift                                        (12)
#define  MISC_SMARTCARD0_SC_PCR_bgt_shift                                        (7)
#define  MISC_SMARTCARD0_SC_PCR_edc_en_shift                                     (6)
#define  MISC_SMARTCARD0_SC_PCR_crclrc_shift                                     (5)
#define  MISC_SMARTCARD0_SC_PCR_protocol_t_shift                                 (4)
#define  MISC_SMARTCARD0_SC_PCR_t0rty_shift                                      (3)
#define  MISC_SMARTCARD0_SC_PCR_t0rty_cnt_shift                                  (0)
#define  MISC_SMARTCARD0_SC_PCR_txgrdt_mask                                      (0xFF000000)
#define  MISC_SMARTCARD0_SC_PCR_cwi_mask                                         (0x00F00000)
#define  MISC_SMARTCARD0_SC_PCR_bwi_mask                                         (0x000F0000)
#define  MISC_SMARTCARD0_SC_PCR_wwi_mask                                         (0x0000F000)
#define  MISC_SMARTCARD0_SC_PCR_bgt_mask                                         (0x00000F80)
#define  MISC_SMARTCARD0_SC_PCR_edc_en_mask                                      (0x00000040)
#define  MISC_SMARTCARD0_SC_PCR_crclrc_mask                                      (0x00000020)
#define  MISC_SMARTCARD0_SC_PCR_protocol_t_mask                                  (0x00000010)
#define  MISC_SMARTCARD0_SC_PCR_t0rty_mask                                       (0x00000008)
#define  MISC_SMARTCARD0_SC_PCR_t0rty_cnt_mask                                   (0x00000007)
#define  MISC_SMARTCARD0_SC_PCR_txgrdt(data)                                     (0xFF000000&((data)<<24))
#define  MISC_SMARTCARD0_SC_PCR_cwi(data)                                        (0x00F00000&((data)<<20))
#define  MISC_SMARTCARD0_SC_PCR_bwi(data)                                        (0x000F0000&((data)<<16))
#define  MISC_SMARTCARD0_SC_PCR_wwi(data)                                        (0x0000F000&((data)<<12))
#define  MISC_SMARTCARD0_SC_PCR_bgt(data)                                        (0x00000F80&((data)<<7))
#define  MISC_SMARTCARD0_SC_PCR_edc_en(data)                                     (0x00000040&((data)<<6))
#define  MISC_SMARTCARD0_SC_PCR_crclrc(data)                                     (0x00000020&((data)<<5))
#define  MISC_SMARTCARD0_SC_PCR_protocol_t(data)                                 (0x00000010&((data)<<4))
#define  MISC_SMARTCARD0_SC_PCR_t0rty(data)                                      (0x00000008&((data)<<3))
#define  MISC_SMARTCARD0_SC_PCR_t0rty_cnt(data)                                  (0x00000007&(data))
#define  MISC_SMARTCARD0_SC_PCR_get_txgrdt(data)                                 ((0xFF000000&(data))>>24)
#define  MISC_SMARTCARD0_SC_PCR_get_cwi(data)                                    ((0x00F00000&(data))>>20)
#define  MISC_SMARTCARD0_SC_PCR_get_bwi(data)                                    ((0x000F0000&(data))>>16)
#define  MISC_SMARTCARD0_SC_PCR_get_wwi(data)                                    ((0x0000F000&(data))>>12)
#define  MISC_SMARTCARD0_SC_PCR_get_bgt(data)                                    ((0x00000F80&(data))>>7)
#define  MISC_SMARTCARD0_SC_PCR_get_edc_en(data)                                 ((0x00000040&(data))>>6)
#define  MISC_SMARTCARD0_SC_PCR_get_crclrc(data)                                 ((0x00000020&(data))>>5)
#define  MISC_SMARTCARD0_SC_PCR_get_protocol_t(data)                             ((0x00000010&(data))>>4)
#define  MISC_SMARTCARD0_SC_PCR_get_t0rty(data)                                  ((0x00000008&(data))>>3)
#define  MISC_SMARTCARD0_SC_PCR_get_t0rty_cnt(data)                              (0x00000007&(data))

#define  MISC_SMARTCARD0_SC_TXFIFO                                               0x1801B80C
#define  MISC_SMARTCARD0_SC_TXFIFO_reg_addr                                      "0xB801B80C"
#define  MISC_SMARTCARD0_SC_TXFIFO_reg                                           0xB801B80C
#define  MISC_SMARTCARD0_SC_TXFIFO_inst_addr                                     "0x0003"
#define  set_MISC_SMARTCARD0_SC_TXFIFO_reg(data)                                 (*((volatile unsigned int*)MISC_SMARTCARD0_SC_TXFIFO_reg)=data)
#define  get_MISC_SMARTCARD0_SC_TXFIFO_reg                                       (*((volatile unsigned int*)MISC_SMARTCARD0_SC_TXFIFO_reg))
#define  MISC_SMARTCARD0_SC_TXFIFO_tx_fifo_full_shift                            (8)
#define  MISC_SMARTCARD0_SC_TXFIFO_dat_shift                                     (0)
#define  MISC_SMARTCARD0_SC_TXFIFO_tx_fifo_full_mask                             (0x00000100)
#define  MISC_SMARTCARD0_SC_TXFIFO_dat_mask                                      (0x000000FF)
#define  MISC_SMARTCARD0_SC_TXFIFO_tx_fifo_full(data)                            (0x00000100&((data)<<8))
#define  MISC_SMARTCARD0_SC_TXFIFO_dat(data)                                     (0x000000FF&(data))
#define  MISC_SMARTCARD0_SC_TXFIFO_get_tx_fifo_full(data)                        ((0x00000100&(data))>>8)
#define  MISC_SMARTCARD0_SC_TXFIFO_get_dat(data)                                 (0x000000FF&(data))

#define  MISC_SMARTCARD0_SC_RXFIFO                                               0x1801B814
#define  MISC_SMARTCARD0_SC_RXFIFO_reg_addr                                      "0xB801B814"
#define  MISC_SMARTCARD0_SC_RXFIFO_reg                                           0xB801B814
#define  MISC_SMARTCARD0_SC_RXFIFO_inst_addr                                     "0x0004"
#define  set_MISC_SMARTCARD0_SC_RXFIFO_reg(data)                                 (*((volatile unsigned int*)MISC_SMARTCARD0_SC_RXFIFO_reg)=data)
#define  get_MISC_SMARTCARD0_SC_RXFIFO_reg                                       (*((volatile unsigned int*)MISC_SMARTCARD0_SC_RXFIFO_reg))
#define  MISC_SMARTCARD0_SC_RXFIFO_dat_shift                                     (0)
#define  MISC_SMARTCARD0_SC_RXFIFO_dat_mask                                      (0x000000FF)
#define  MISC_SMARTCARD0_SC_RXFIFO_dat(data)                                     (0x000000FF&(data))
#define  MISC_SMARTCARD0_SC_RXFIFO_get_dat(data)                                 (0x000000FF&(data))

#define  MISC_SMARTCARD0_SC_RXLENR                                               0x1801B818
#define  MISC_SMARTCARD0_SC_RXLENR_reg_addr                                      "0xB801B818"
#define  MISC_SMARTCARD0_SC_RXLENR_reg                                           0xB801B818
#define  MISC_SMARTCARD0_SC_RXLENR_inst_addr                                     "0x0005"
#define  set_MISC_SMARTCARD0_SC_RXLENR_reg(data)                                 (*((volatile unsigned int*)MISC_SMARTCARD0_SC_RXLENR_reg)=data)
#define  get_MISC_SMARTCARD0_SC_RXLENR_reg                                       (*((volatile unsigned int*)MISC_SMARTCARD0_SC_RXLENR_reg))
#define  MISC_SMARTCARD0_SC_RXLENR_fifo_level_shift                              (0)
#define  MISC_SMARTCARD0_SC_RXLENR_fifo_level_mask                               (0x0000003F)
#define  MISC_SMARTCARD0_SC_RXLENR_fifo_level(data)                              (0x0000003F&(data))
#define  MISC_SMARTCARD0_SC_RXLENR_get_fifo_level(data)                          (0x0000003F&(data))

#define  MISC_SMARTCARD0_SC_FCR                                                  0x1801B81C
#define  MISC_SMARTCARD0_SC_FCR_reg_addr                                         "0xB801B81C"
#define  MISC_SMARTCARD0_SC_FCR_reg                                              0xB801B81C
#define  MISC_SMARTCARD0_SC_FCR_inst_addr                                        "0x0006"
#define  set_MISC_SMARTCARD0_SC_FCR_reg(data)                                    (*((volatile unsigned int*)MISC_SMARTCARD0_SC_FCR_reg)=data)
#define  get_MISC_SMARTCARD0_SC_FCR_reg                                          (*((volatile unsigned int*)MISC_SMARTCARD0_SC_FCR_reg))
#define  MISC_SMARTCARD0_SC_FCR_rxflow_shift                                     (1)
#define  MISC_SMARTCARD0_SC_FCR_flow_en_shift                                    (0)
#define  MISC_SMARTCARD0_SC_FCR_rxflow_mask                                      (0x00000002)
#define  MISC_SMARTCARD0_SC_FCR_flow_en_mask                                     (0x00000001)
#define  MISC_SMARTCARD0_SC_FCR_rxflow(data)                                     (0x00000002&((data)<<1))
#define  MISC_SMARTCARD0_SC_FCR_flow_en(data)                                    (0x00000001&(data))
#define  MISC_SMARTCARD0_SC_FCR_get_rxflow(data)                                 ((0x00000002&(data))>>1)
#define  MISC_SMARTCARD0_SC_FCR_get_flow_en(data)                                (0x00000001&(data))

#define  MISC_SMARTCARD0_SC_IRSR                                                 0x1801B820
#define  MISC_SMARTCARD0_SC_IRSR_reg_addr                                        "0xB801B820"
#define  MISC_SMARTCARD0_SC_IRSR_reg                                             0xB801B820
#define  MISC_SMARTCARD0_SC_IRSR_inst_addr                                       "0x0007"
#define  set_MISC_SMARTCARD0_SC_IRSR_reg(data)                                   (*((volatile unsigned int*)MISC_SMARTCARD0_SC_IRSR_reg)=data)
#define  get_MISC_SMARTCARD0_SC_IRSR_reg                                         (*((volatile unsigned int*)MISC_SMARTCARD0_SC_IRSR_reg))
#define  MISC_SMARTCARD0_SC_IRSR_pres_shift                                      (16)
#define  MISC_SMARTCARD0_SC_IRSR_cpres_int_shift                                 (15)
#define  MISC_SMARTCARD0_SC_IRSR_tx_flow_int_shift                               (14)
#define  MISC_SMARTCARD0_SC_IRSR_txp_int_shift                                   (13)
#define  MISC_SMARTCARD0_SC_IRSR_txdone_int_shift                                (12)
#define  MISC_SMARTCARD0_SC_IRSR_txempty_int_shift                               (11)
#define  MISC_SMARTCARD0_SC_IRSR_edcerr_int_shift                                (10)
#define  MISC_SMARTCARD0_SC_IRSR_rx_fover_shift                                  (9)
#define  MISC_SMARTCARD0_SC_IRSR_rxp_int_shift                                   (8)
#define  MISC_SMARTCARD0_SC_IRSR_atrs_int_shift                                  (7)
#define  MISC_SMARTCARD0_SC_IRSR_bgt_int_shift                                   (6)
#define  MISC_SMARTCARD0_SC_IRSR_cwt_int_shift                                   (5)
#define  MISC_SMARTCARD0_SC_IRSR_rlen_int_shift                                  (4)
#define  MISC_SMARTCARD0_SC_IRSR_wwt_int_shift                                   (3)
#define  MISC_SMARTCARD0_SC_IRSR_bwt_int_shift                                   (2)
#define  MISC_SMARTCARD0_SC_IRSR_rcv_int_shift                                   (1)
#define  MISC_SMARTCARD0_SC_IRSR_drdy_int_shift                                  (0)
#define  MISC_SMARTCARD0_SC_IRSR_pres_mask                                       (0x00010000)
#define  MISC_SMARTCARD0_SC_IRSR_cpres_int_mask                                  (0x00008000)
#define  MISC_SMARTCARD0_SC_IRSR_tx_flow_int_mask                                (0x00004000)
#define  MISC_SMARTCARD0_SC_IRSR_txp_int_mask                                    (0x00002000)
#define  MISC_SMARTCARD0_SC_IRSR_txdone_int_mask                                 (0x00001000)
#define  MISC_SMARTCARD0_SC_IRSR_txempty_int_mask                                (0x00000800)
#define  MISC_SMARTCARD0_SC_IRSR_edcerr_int_mask                                 (0x00000400)
#define  MISC_SMARTCARD0_SC_IRSR_rx_fover_mask                                   (0x00000200)
#define  MISC_SMARTCARD0_SC_IRSR_rxp_int_mask                                    (0x00000100)
#define  MISC_SMARTCARD0_SC_IRSR_atrs_int_mask                                   (0x00000080)
#define  MISC_SMARTCARD0_SC_IRSR_bgt_int_mask                                    (0x00000040)
#define  MISC_SMARTCARD0_SC_IRSR_cwt_int_mask                                    (0x00000020)
#define  MISC_SMARTCARD0_SC_IRSR_rlen_int_mask                                   (0x00000010)
#define  MISC_SMARTCARD0_SC_IRSR_wwt_int_mask                                    (0x00000008)
#define  MISC_SMARTCARD0_SC_IRSR_bwt_int_mask                                    (0x00000004)
#define  MISC_SMARTCARD0_SC_IRSR_rcv_int_mask                                    (0x00000002)
#define  MISC_SMARTCARD0_SC_IRSR_drdy_int_mask                                   (0x00000001)
#define  MISC_SMARTCARD0_SC_IRSR_pres(data)                                      (0x00010000&((data)<<16))
#define  MISC_SMARTCARD0_SC_IRSR_cpres_int(data)                                 (0x00008000&((data)<<15))
#define  MISC_SMARTCARD0_SC_IRSR_tx_flow_int(data)                               (0x00004000&((data)<<14))
#define  MISC_SMARTCARD0_SC_IRSR_txp_int(data)                                   (0x00002000&((data)<<13))
#define  MISC_SMARTCARD0_SC_IRSR_txdone_int(data)                                (0x00001000&((data)<<12))
#define  MISC_SMARTCARD0_SC_IRSR_txempty_int(data)                               (0x00000800&((data)<<11))
#define  MISC_SMARTCARD0_SC_IRSR_edcerr_int(data)                                (0x00000400&((data)<<10))
#define  MISC_SMARTCARD0_SC_IRSR_rx_fover(data)                                  (0x00000200&((data)<<9))
#define  MISC_SMARTCARD0_SC_IRSR_rxp_int(data)                                   (0x00000100&((data)<<8))
#define  MISC_SMARTCARD0_SC_IRSR_atrs_int(data)                                  (0x00000080&((data)<<7))
#define  MISC_SMARTCARD0_SC_IRSR_bgt_int(data)                                   (0x00000040&((data)<<6))
#define  MISC_SMARTCARD0_SC_IRSR_cwt_int(data)                                   (0x00000020&((data)<<5))
#define  MISC_SMARTCARD0_SC_IRSR_rlen_int(data)                                  (0x00000010&((data)<<4))
#define  MISC_SMARTCARD0_SC_IRSR_wwt_int(data)                                   (0x00000008&((data)<<3))
#define  MISC_SMARTCARD0_SC_IRSR_bwt_int(data)                                   (0x00000004&((data)<<2))
#define  MISC_SMARTCARD0_SC_IRSR_rcv_int(data)                                   (0x00000002&((data)<<1))
#define  MISC_SMARTCARD0_SC_IRSR_drdy_int(data)                                  (0x00000001&(data))
#define  MISC_SMARTCARD0_SC_IRSR_get_pres(data)                                  ((0x00010000&(data))>>16)
#define  MISC_SMARTCARD0_SC_IRSR_get_cpres_int(data)                             ((0x00008000&(data))>>15)
#define  MISC_SMARTCARD0_SC_IRSR_get_tx_flow_int(data)                           ((0x00004000&(data))>>14)
#define  MISC_SMARTCARD0_SC_IRSR_get_txp_int(data)                               ((0x00002000&(data))>>13)
#define  MISC_SMARTCARD0_SC_IRSR_get_txdone_int(data)                            ((0x00001000&(data))>>12)
#define  MISC_SMARTCARD0_SC_IRSR_get_txempty_int(data)                           ((0x00000800&(data))>>11)
#define  MISC_SMARTCARD0_SC_IRSR_get_edcerr_int(data)                            ((0x00000400&(data))>>10)
#define  MISC_SMARTCARD0_SC_IRSR_get_rx_fover(data)                              ((0x00000200&(data))>>9)
#define  MISC_SMARTCARD0_SC_IRSR_get_rxp_int(data)                               ((0x00000100&(data))>>8)
#define  MISC_SMARTCARD0_SC_IRSR_get_atrs_int(data)                              ((0x00000080&(data))>>7)
#define  MISC_SMARTCARD0_SC_IRSR_get_bgt_int(data)                               ((0x00000040&(data))>>6)
#define  MISC_SMARTCARD0_SC_IRSR_get_cwt_int(data)                               ((0x00000020&(data))>>5)
#define  MISC_SMARTCARD0_SC_IRSR_get_rlen_int(data)                              ((0x00000010&(data))>>4)
#define  MISC_SMARTCARD0_SC_IRSR_get_wwt_int(data)                               ((0x00000008&(data))>>3)
#define  MISC_SMARTCARD0_SC_IRSR_get_bwt_int(data)                               ((0x00000004&(data))>>2)
#define  MISC_SMARTCARD0_SC_IRSR_get_rcv_int(data)                               ((0x00000002&(data))>>1)
#define  MISC_SMARTCARD0_SC_IRSR_get_drdy_int(data)                              (0x00000001&(data))

#define  MISC_SMARTCARD0_SC_IRER                                                 0x1801B824
#define  MISC_SMARTCARD0_SC_IRER_reg_addr                                        "0xB801B824"
#define  MISC_SMARTCARD0_SC_IRER_reg                                             0xB801B824
#define  MISC_SMARTCARD0_SC_IRER_inst_addr                                       "0x0008"
#define  set_MISC_SMARTCARD0_SC_IRER_reg(data)                                   (*((volatile unsigned int*)MISC_SMARTCARD0_SC_IRER_reg)=data)
#define  get_MISC_SMARTCARD0_SC_IRER_reg                                         (*((volatile unsigned int*)MISC_SMARTCARD0_SC_IRER_reg))
#define  MISC_SMARTCARD0_SC_IRER_cpres_en_shift                                  (15)
#define  MISC_SMARTCARD0_SC_IRER_txflow_int_en_shift                             (14)
#define  MISC_SMARTCARD0_SC_IRER_txp_en_shift                                    (13)
#define  MISC_SMARTCARD0_SC_IRER_txdone_en_shift                                 (12)
#define  MISC_SMARTCARD0_SC_IRER_txempty_en_shift                                (11)
#define  MISC_SMARTCARD0_SC_IRER_edcerr_en_shift                                 (10)
#define  MISC_SMARTCARD0_SC_IRER_rx_fover_en_shift                               (9)
#define  MISC_SMARTCARD0_SC_IRER_rxp_en_shift                                    (8)
#define  MISC_SMARTCARD0_SC_IRER_atrs_en_shift                                   (7)
#define  MISC_SMARTCARD0_SC_IRER_bgt_en_shift                                    (6)
#define  MISC_SMARTCARD0_SC_IRER_cwt_en_shift                                    (5)
#define  MISC_SMARTCARD0_SC_IRER_rlen_en_shift                                   (4)
#define  MISC_SMARTCARD0_SC_IRER_wwt_en_shift                                    (3)
#define  MISC_SMARTCARD0_SC_IRER_bwt_en_shift                                    (2)
#define  MISC_SMARTCARD0_SC_IRER_rcv_en_shift                                    (1)
#define  MISC_SMARTCARD0_SC_IRER_drdy_en_shift                                   (0)
#define  MISC_SMARTCARD0_SC_IRER_cpres_en_mask                                   (0x00008000)
#define  MISC_SMARTCARD0_SC_IRER_txflow_int_en_mask                              (0x00004000)
#define  MISC_SMARTCARD0_SC_IRER_txp_en_mask                                     (0x00002000)
#define  MISC_SMARTCARD0_SC_IRER_txdone_en_mask                                  (0x00001000)
#define  MISC_SMARTCARD0_SC_IRER_txempty_en_mask                                 (0x00000800)
#define  MISC_SMARTCARD0_SC_IRER_edcerr_en_mask                                  (0x00000400)
#define  MISC_SMARTCARD0_SC_IRER_rx_fover_en_mask                                (0x00000200)
#define  MISC_SMARTCARD0_SC_IRER_rxp_en_mask                                     (0x00000100)
#define  MISC_SMARTCARD0_SC_IRER_atrs_en_mask                                    (0x00000080)
#define  MISC_SMARTCARD0_SC_IRER_bgt_en_mask                                     (0x00000040)
#define  MISC_SMARTCARD0_SC_IRER_cwt_en_mask                                     (0x00000020)
#define  MISC_SMARTCARD0_SC_IRER_rlen_en_mask                                    (0x00000010)
#define  MISC_SMARTCARD0_SC_IRER_wwt_en_mask                                     (0x00000008)
#define  MISC_SMARTCARD0_SC_IRER_bwt_en_mask                                     (0x00000004)
#define  MISC_SMARTCARD0_SC_IRER_rcv_en_mask                                     (0x00000002)
#define  MISC_SMARTCARD0_SC_IRER_drdy_en_mask                                    (0x00000001)
#define  MISC_SMARTCARD0_SC_IRER_cpres_en(data)                                  (0x00008000&((data)<<15))
#define  MISC_SMARTCARD0_SC_IRER_txflow_int_en(data)                             (0x00004000&((data)<<14))
#define  MISC_SMARTCARD0_SC_IRER_txp_en(data)                                    (0x00002000&((data)<<13))
#define  MISC_SMARTCARD0_SC_IRER_txdone_en(data)                                 (0x00001000&((data)<<12))
#define  MISC_SMARTCARD0_SC_IRER_txempty_en(data)                                (0x00000800&((data)<<11))
#define  MISC_SMARTCARD0_SC_IRER_edcerr_en(data)                                 (0x00000400&((data)<<10))
#define  MISC_SMARTCARD0_SC_IRER_rx_fover_en(data)                               (0x00000200&((data)<<9))
#define  MISC_SMARTCARD0_SC_IRER_rxp_en(data)                                    (0x00000100&((data)<<8))
#define  MISC_SMARTCARD0_SC_IRER_atrs_en(data)                                   (0x00000080&((data)<<7))
#define  MISC_SMARTCARD0_SC_IRER_bgt_en(data)                                    (0x00000040&((data)<<6))
#define  MISC_SMARTCARD0_SC_IRER_cwt_en(data)                                    (0x00000020&((data)<<5))
#define  MISC_SMARTCARD0_SC_IRER_rlen_en(data)                                   (0x00000010&((data)<<4))
#define  MISC_SMARTCARD0_SC_IRER_wwt_en(data)                                    (0x00000008&((data)<<3))
#define  MISC_SMARTCARD0_SC_IRER_bwt_en(data)                                    (0x00000004&((data)<<2))
#define  MISC_SMARTCARD0_SC_IRER_rcv_en(data)                                    (0x00000002&((data)<<1))
#define  MISC_SMARTCARD0_SC_IRER_drdy_en(data)                                   (0x00000001&(data))
#define  MISC_SMARTCARD0_SC_IRER_get_cpres_en(data)                              ((0x00008000&(data))>>15)
#define  MISC_SMARTCARD0_SC_IRER_get_txflow_int_en(data)                         ((0x00004000&(data))>>14)
#define  MISC_SMARTCARD0_SC_IRER_get_txp_en(data)                                ((0x00002000&(data))>>13)
#define  MISC_SMARTCARD0_SC_IRER_get_txdone_en(data)                             ((0x00001000&(data))>>12)
#define  MISC_SMARTCARD0_SC_IRER_get_txempty_en(data)                            ((0x00000800&(data))>>11)
#define  MISC_SMARTCARD0_SC_IRER_get_edcerr_en(data)                             ((0x00000400&(data))>>10)
#define  MISC_SMARTCARD0_SC_IRER_get_rx_fover_en(data)                           ((0x00000200&(data))>>9)
#define  MISC_SMARTCARD0_SC_IRER_get_rxp_en(data)                                ((0x00000100&(data))>>8)
#define  MISC_SMARTCARD0_SC_IRER_get_atrs_en(data)                               ((0x00000080&(data))>>7)
#define  MISC_SMARTCARD0_SC_IRER_get_bgt_en(data)                                ((0x00000040&(data))>>6)
#define  MISC_SMARTCARD0_SC_IRER_get_cwt_en(data)                                ((0x00000020&(data))>>5)
#define  MISC_SMARTCARD0_SC_IRER_get_rlen_en(data)                               ((0x00000010&(data))>>4)
#define  MISC_SMARTCARD0_SC_IRER_get_wwt_en(data)                                ((0x00000008&(data))>>3)
#define  MISC_SMARTCARD0_SC_IRER_get_bwt_en(data)                                ((0x00000004&(data))>>2)
#define  MISC_SMARTCARD0_SC_IRER_get_rcv_en(data)                                ((0x00000002&(data))>>1)
#define  MISC_SMARTCARD0_SC_IRER_get_drdy_en(data)                               (0x00000001&(data))

#define  MISC_SMARTCARD0_SC_FF_TEST                                              0x1801B87C
#define  MISC_SMARTCARD0_SC_FF_TEST_reg_addr                                     "0xB801B87C"
#define  MISC_SMARTCARD0_SC_FF_TEST_reg                                          0xB801B87C
#define  MISC_SMARTCARD0_SC_FF_TEST_inst_addr                                    "0x0009"
#define  set_MISC_SMARTCARD0_SC_FF_TEST_reg(data)                                (*((volatile unsigned int*)MISC_SMARTCARD0_SC_FF_TEST_reg)=data)
#define  get_MISC_SMARTCARD0_SC_FF_TEST_reg                                      (*((volatile unsigned int*)MISC_SMARTCARD0_SC_FF_TEST_reg))
#define  MISC_SMARTCARD0_SC_FF_TEST_cpu_ff_test_en_shift                         (0)
#define  MISC_SMARTCARD0_SC_FF_TEST_cpu_ff_test_en_mask                          (0x00000001)
#define  MISC_SMARTCARD0_SC_FF_TEST_cpu_ff_test_en(data)                         (0x00000001&(data))
#define  MISC_SMARTCARD0_SC_FF_TEST_get_cpu_ff_test_en(data)                     (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MISC_SMARTCARD0 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  clk_en:1;
        RBus_UInt32  sc_clkdiv:6;
        RBus_UInt32  bauddiv2:2;
        RBus_UInt32  bauddiv1:8;
        RBus_UInt32  pre_clkdiv:8;
    };
}misc_smartcard0_sc_fp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_rst:1;
        RBus_UInt32  rst:1;
        RBus_UInt32  scen:1;
        RBus_UInt32  tx_go:1;
        RBus_UInt32  auto_atr:1;
        RBus_UInt32  conv:1;
        RBus_UInt32  clk_stop:1;
        RBus_UInt32  ps:1;
        RBus_UInt32  mask_sc_pres:1;
        RBus_UInt32  rst_waitmode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  scc_conv:1;
        RBus_UInt32  act_seq:1;
        RBus_UInt32  res2:19;
    };
}misc_smartcard0_sc_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txgrdt:8;
        RBus_UInt32  cwi:4;
        RBus_UInt32  bwi:4;
        RBus_UInt32  wwi:4;
        RBus_UInt32  bgt:5;
        RBus_UInt32  edc_en:1;
        RBus_UInt32  crclrc:1;
        RBus_UInt32  protocol_t:1;
        RBus_UInt32  t0rty:1;
        RBus_UInt32  t0rty_cnt:3;
    };
}misc_smartcard0_sc_pcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  tx_fifo_full:1;
        RBus_UInt32  dat:8;
    };
}misc_smartcard0_sc_txfifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dat:8;
    };
}misc_smartcard0_sc_rxfifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  fifo_level:6;
    };
}misc_smartcard0_sc_rxlenr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  rxflow:1;
        RBus_UInt32  flow_en:1;
    };
}misc_smartcard0_sc_fcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  pres:1;
        RBus_UInt32  cpres_int:1;
        RBus_UInt32  tx_flow_int:1;
        RBus_UInt32  txp_int:1;
        RBus_UInt32  txdone_int:1;
        RBus_UInt32  txempty_int:1;
        RBus_UInt32  edcerr_int:1;
        RBus_UInt32  rx_fover:1;
        RBus_UInt32  rxp_int:1;
        RBus_UInt32  atrs_int:1;
        RBus_UInt32  bgt_int:1;
        RBus_UInt32  cwt_int:1;
        RBus_UInt32  rlen_int:1;
        RBus_UInt32  wwt_int:1;
        RBus_UInt32  bwt_int:1;
        RBus_UInt32  rcv_int:1;
        RBus_UInt32  drdy_int:1;
    };
}misc_smartcard0_sc_irsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  cpres_en:1;
        RBus_UInt32  txflow_int_en:1;
        RBus_UInt32  txp_en:1;
        RBus_UInt32  txdone_en:1;
        RBus_UInt32  txempty_en:1;
        RBus_UInt32  edcerr_en:1;
        RBus_UInt32  rx_fover_en:1;
        RBus_UInt32  rxp_en:1;
        RBus_UInt32  atrs_en:1;
        RBus_UInt32  bgt_en:1;
        RBus_UInt32  cwt_en:1;
        RBus_UInt32  rlen_en:1;
        RBus_UInt32  wwt_en:1;
        RBus_UInt32  bwt_en:1;
        RBus_UInt32  rcv_en:1;
        RBus_UInt32  drdy_en:1;
    };
}misc_smartcard0_sc_irer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cpu_ff_test_en:1;
    };
}misc_smartcard0_sc_ff_test_RBUS;

#else //apply LITTLE_ENDIAN

//======MISC_SMARTCARD0 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_clkdiv:8;
        RBus_UInt32  bauddiv1:8;
        RBus_UInt32  bauddiv2:2;
        RBus_UInt32  sc_clkdiv:6;
        RBus_UInt32  clk_en:1;
        RBus_UInt32  res1:7;
    };
}misc_smartcard0_sc_fp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  act_seq:1;
        RBus_UInt32  scc_conv:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rst_waitmode:1;
        RBus_UInt32  mask_sc_pres:1;
        RBus_UInt32  ps:1;
        RBus_UInt32  clk_stop:1;
        RBus_UInt32  conv:1;
        RBus_UInt32  auto_atr:1;
        RBus_UInt32  tx_go:1;
        RBus_UInt32  scen:1;
        RBus_UInt32  rst:1;
        RBus_UInt32  fifo_rst:1;
    };
}misc_smartcard0_sc_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t0rty_cnt:3;
        RBus_UInt32  t0rty:1;
        RBus_UInt32  protocol_t:1;
        RBus_UInt32  crclrc:1;
        RBus_UInt32  edc_en:1;
        RBus_UInt32  bgt:5;
        RBus_UInt32  wwi:4;
        RBus_UInt32  bwi:4;
        RBus_UInt32  cwi:4;
        RBus_UInt32  txgrdt:8;
    };
}misc_smartcard0_sc_pcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:8;
        RBus_UInt32  tx_fifo_full:1;
        RBus_UInt32  res1:23;
    };
}misc_smartcard0_sc_txfifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:8;
        RBus_UInt32  res1:24;
    };
}misc_smartcard0_sc_rxfifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_level:6;
        RBus_UInt32  res1:26;
    };
}misc_smartcard0_sc_rxlenr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flow_en:1;
        RBus_UInt32  rxflow:1;
        RBus_UInt32  res1:30;
    };
}misc_smartcard0_sc_fcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drdy_int:1;
        RBus_UInt32  rcv_int:1;
        RBus_UInt32  bwt_int:1;
        RBus_UInt32  wwt_int:1;
        RBus_UInt32  rlen_int:1;
        RBus_UInt32  cwt_int:1;
        RBus_UInt32  bgt_int:1;
        RBus_UInt32  atrs_int:1;
        RBus_UInt32  rxp_int:1;
        RBus_UInt32  rx_fover:1;
        RBus_UInt32  edcerr_int:1;
        RBus_UInt32  txempty_int:1;
        RBus_UInt32  txdone_int:1;
        RBus_UInt32  txp_int:1;
        RBus_UInt32  tx_flow_int:1;
        RBus_UInt32  cpres_int:1;
        RBus_UInt32  pres:1;
        RBus_UInt32  res1:15;
    };
}misc_smartcard0_sc_irsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drdy_en:1;
        RBus_UInt32  rcv_en:1;
        RBus_UInt32  bwt_en:1;
        RBus_UInt32  wwt_en:1;
        RBus_UInt32  rlen_en:1;
        RBus_UInt32  cwt_en:1;
        RBus_UInt32  bgt_en:1;
        RBus_UInt32  atrs_en:1;
        RBus_UInt32  rxp_en:1;
        RBus_UInt32  rx_fover_en:1;
        RBus_UInt32  edcerr_en:1;
        RBus_UInt32  txempty_en:1;
        RBus_UInt32  txdone_en:1;
        RBus_UInt32  txp_en:1;
        RBus_UInt32  txflow_int_en:1;
        RBus_UInt32  cpres_en:1;
        RBus_UInt32  res1:16;
    };
}misc_smartcard0_sc_irer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpu_ff_test_en:1;
        RBus_UInt32  res1:31;
    };
}misc_smartcard0_sc_ff_test_RBUS;




#endif 


#endif 
