/**
* @file Mac5-DesignSpec-ETN
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ETN_REG_H_
#define _RBUS_ETN_REG_H_

#include "rbus_types.h"



//  ETN Register Address
#define  ETN_ETN_IDR_03                                                          0x18016800
#define  ETN_ETN_IDR_03_reg_addr                                                 "0xB8016800"
#define  ETN_ETN_IDR_03_reg                                                      0xB8016800
#define  ETN_ETN_IDR_03_inst_addr                                                "0x0000"
#define  set_ETN_ETN_IDR_03_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_IDR_03_reg)=data)
#define  get_ETN_ETN_IDR_03_reg                                                  (*((volatile unsigned int*)ETN_ETN_IDR_03_reg))
#define  ETN_ETN_IDR_03_idr0_shift                                               (24)
#define  ETN_ETN_IDR_03_idr1_shift                                               (16)
#define  ETN_ETN_IDR_03_idr2_shift                                               (8)
#define  ETN_ETN_IDR_03_idr3_shift                                               (0)
#define  ETN_ETN_IDR_03_idr0_mask                                                (0xFF000000)
#define  ETN_ETN_IDR_03_idr1_mask                                                (0x00FF0000)
#define  ETN_ETN_IDR_03_idr2_mask                                                (0x0000FF00)
#define  ETN_ETN_IDR_03_idr3_mask                                                (0x000000FF)
#define  ETN_ETN_IDR_03_idr0(data)                                               (0xFF000000&((data)<<24))
#define  ETN_ETN_IDR_03_idr1(data)                                               (0x00FF0000&((data)<<16))
#define  ETN_ETN_IDR_03_idr2(data)                                               (0x0000FF00&((data)<<8))
#define  ETN_ETN_IDR_03_idr3(data)                                               (0x000000FF&(data))
#define  ETN_ETN_IDR_03_get_idr0(data)                                           ((0xFF000000&(data))>>24)
#define  ETN_ETN_IDR_03_get_idr1(data)                                           ((0x00FF0000&(data))>>16)
#define  ETN_ETN_IDR_03_get_idr2(data)                                           ((0x0000FF00&(data))>>8)
#define  ETN_ETN_IDR_03_get_idr3(data)                                           (0x000000FF&(data))

#define  ETN_ETN_IDR_45                                                          0x18016804
#define  ETN_ETN_IDR_45_reg_addr                                                 "0xB8016804"
#define  ETN_ETN_IDR_45_reg                                                      0xB8016804
#define  ETN_ETN_IDR_45_inst_addr                                                "0x0001"
#define  set_ETN_ETN_IDR_45_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_IDR_45_reg)=data)
#define  get_ETN_ETN_IDR_45_reg                                                  (*((volatile unsigned int*)ETN_ETN_IDR_45_reg))
#define  ETN_ETN_IDR_45_idr4_shift                                               (24)
#define  ETN_ETN_IDR_45_idr5_shift                                               (16)
#define  ETN_ETN_IDR_45_dummy_15_0_shift                                         (0)
#define  ETN_ETN_IDR_45_idr4_mask                                                (0xFF000000)
#define  ETN_ETN_IDR_45_idr5_mask                                                (0x00FF0000)
#define  ETN_ETN_IDR_45_dummy_15_0_mask                                          (0x0000FFFF)
#define  ETN_ETN_IDR_45_idr4(data)                                               (0xFF000000&((data)<<24))
#define  ETN_ETN_IDR_45_idr5(data)                                               (0x00FF0000&((data)<<16))
#define  ETN_ETN_IDR_45_dummy_15_0(data)                                         (0x0000FFFF&(data))
#define  ETN_ETN_IDR_45_get_idr4(data)                                           ((0xFF000000&(data))>>24)
#define  ETN_ETN_IDR_45_get_idr5(data)                                           ((0x00FF0000&(data))>>16)
#define  ETN_ETN_IDR_45_get_dummy_15_0(data)                                     (0x0000FFFF&(data))

#define  ETN_ETN_MAR_03                                                          0x18016808
#define  ETN_ETN_MAR_03_reg_addr                                                 "0xB8016808"
#define  ETN_ETN_MAR_03_reg                                                      0xB8016808
#define  ETN_ETN_MAR_03_inst_addr                                                "0x0002"
#define  set_ETN_ETN_MAR_03_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_MAR_03_reg)=data)
#define  get_ETN_ETN_MAR_03_reg                                                  (*((volatile unsigned int*)ETN_ETN_MAR_03_reg))
#define  ETN_ETN_MAR_03_mar0_shift                                               (24)
#define  ETN_ETN_MAR_03_mar1_shift                                               (16)
#define  ETN_ETN_MAR_03_mar2_shift                                               (8)
#define  ETN_ETN_MAR_03_mar3_shift                                               (0)
#define  ETN_ETN_MAR_03_mar0_mask                                                (0xFF000000)
#define  ETN_ETN_MAR_03_mar1_mask                                                (0x00FF0000)
#define  ETN_ETN_MAR_03_mar2_mask                                                (0x0000FF00)
#define  ETN_ETN_MAR_03_mar3_mask                                                (0x000000FF)
#define  ETN_ETN_MAR_03_mar0(data)                                               (0xFF000000&((data)<<24))
#define  ETN_ETN_MAR_03_mar1(data)                                               (0x00FF0000&((data)<<16))
#define  ETN_ETN_MAR_03_mar2(data)                                               (0x0000FF00&((data)<<8))
#define  ETN_ETN_MAR_03_mar3(data)                                               (0x000000FF&(data))
#define  ETN_ETN_MAR_03_get_mar0(data)                                           ((0xFF000000&(data))>>24)
#define  ETN_ETN_MAR_03_get_mar1(data)                                           ((0x00FF0000&(data))>>16)
#define  ETN_ETN_MAR_03_get_mar2(data)                                           ((0x0000FF00&(data))>>8)
#define  ETN_ETN_MAR_03_get_mar3(data)                                           (0x000000FF&(data))

#define  ETN_ETN_MAR_47                                                          0x1801680C
#define  ETN_ETN_MAR_47_reg_addr                                                 "0xB801680C"
#define  ETN_ETN_MAR_47_reg                                                      0xB801680C
#define  ETN_ETN_MAR_47_inst_addr                                                "0x0003"
#define  set_ETN_ETN_MAR_47_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_MAR_47_reg)=data)
#define  get_ETN_ETN_MAR_47_reg                                                  (*((volatile unsigned int*)ETN_ETN_MAR_47_reg))
#define  ETN_ETN_MAR_47_mar4_shift                                               (24)
#define  ETN_ETN_MAR_47_mar5_shift                                               (16)
#define  ETN_ETN_MAR_47_mar6_shift                                               (8)
#define  ETN_ETN_MAR_47_mar7_shift                                               (0)
#define  ETN_ETN_MAR_47_mar4_mask                                                (0xFF000000)
#define  ETN_ETN_MAR_47_mar5_mask                                                (0x00FF0000)
#define  ETN_ETN_MAR_47_mar6_mask                                                (0x0000FF00)
#define  ETN_ETN_MAR_47_mar7_mask                                                (0x000000FF)
#define  ETN_ETN_MAR_47_mar4(data)                                               (0xFF000000&((data)<<24))
#define  ETN_ETN_MAR_47_mar5(data)                                               (0x00FF0000&((data)<<16))
#define  ETN_ETN_MAR_47_mar6(data)                                               (0x0000FF00&((data)<<8))
#define  ETN_ETN_MAR_47_mar7(data)                                               (0x000000FF&(data))
#define  ETN_ETN_MAR_47_get_mar4(data)                                           ((0xFF000000&(data))>>24)
#define  ETN_ETN_MAR_47_get_mar5(data)                                           ((0x00FF0000&(data))>>16)
#define  ETN_ETN_MAR_47_get_mar6(data)                                           ((0x0000FF00&(data))>>8)
#define  ETN_ETN_MAR_47_get_mar7(data)                                           (0x000000FF&(data))

#define  ETN_ETN_TX_RX_CNT                                                       0x18016810
#define  ETN_ETN_TX_RX_CNT_reg_addr                                              "0xB8016810"
#define  ETN_ETN_TX_RX_CNT_reg                                                   0xB8016810
#define  ETN_ETN_TX_RX_CNT_inst_addr                                             "0x0004"
#define  set_ETN_ETN_TX_RX_CNT_reg(data)                                         (*((volatile unsigned int*)ETN_ETN_TX_RX_CNT_reg)=data)
#define  get_ETN_ETN_TX_RX_CNT_reg                                               (*((volatile unsigned int*)ETN_ETN_TX_RX_CNT_reg))
#define  ETN_ETN_TX_RX_CNT_txokc_shift                                           (16)
#define  ETN_ETN_TX_RX_CNT_rxokc_shift                                           (0)
#define  ETN_ETN_TX_RX_CNT_txokc_mask                                            (0xFFFF0000)
#define  ETN_ETN_TX_RX_CNT_rxokc_mask                                            (0x0000FFFF)
#define  ETN_ETN_TX_RX_CNT_txokc(data)                                           (0xFFFF0000&((data)<<16))
#define  ETN_ETN_TX_RX_CNT_rxokc(data)                                           (0x0000FFFF&(data))
#define  ETN_ETN_TX_RX_CNT_get_txokc(data)                                       ((0xFFFF0000&(data))>>16)
#define  ETN_ETN_TX_RX_CNT_get_rxokc(data)                                       (0x0000FFFF&(data))

#define  ETN_ETN_TX_RX_ERR                                                       0x18016814
#define  ETN_ETN_TX_RX_ERR_reg_addr                                              "0xB8016814"
#define  ETN_ETN_TX_RX_ERR_reg                                                   0xB8016814
#define  ETN_ETN_TX_RX_ERR_inst_addr                                             "0x0005"
#define  set_ETN_ETN_TX_RX_ERR_reg(data)                                         (*((volatile unsigned int*)ETN_ETN_TX_RX_ERR_reg)=data)
#define  get_ETN_ETN_TX_RX_ERR_reg                                               (*((volatile unsigned int*)ETN_ETN_TX_RX_ERR_reg))
#define  ETN_ETN_TX_RX_ERR_txerr_shift                                           (16)
#define  ETN_ETN_TX_RX_ERR_rxerr_shift                                           (0)
#define  ETN_ETN_TX_RX_ERR_txerr_mask                                            (0xFFFF0000)
#define  ETN_ETN_TX_RX_ERR_rxerr_mask                                            (0x0000FFFF)
#define  ETN_ETN_TX_RX_ERR_txerr(data)                                           (0xFFFF0000&((data)<<16))
#define  ETN_ETN_TX_RX_ERR_rxerr(data)                                           (0x0000FFFF&(data))
#define  ETN_ETN_TX_RX_ERR_get_txerr(data)                                       ((0xFFFF0000&(data))>>16)
#define  ETN_ETN_TX_RX_ERR_get_rxerr(data)                                       (0x0000FFFF&(data))

#define  ETN_ETN_MISS_FAE                                                        0x18016818
#define  ETN_ETN_MISS_FAE_reg_addr                                               "0xB8016818"
#define  ETN_ETN_MISS_FAE_reg                                                    0xB8016818
#define  ETN_ETN_MISS_FAE_inst_addr                                              "0x0006"
#define  set_ETN_ETN_MISS_FAE_reg(data)                                          (*((volatile unsigned int*)ETN_ETN_MISS_FAE_reg)=data)
#define  get_ETN_ETN_MISS_FAE_reg                                                (*((volatile unsigned int*)ETN_ETN_MISS_FAE_reg))
#define  ETN_ETN_MISS_FAE_misspkt_shift                                          (16)
#define  ETN_ETN_MISS_FAE_fae_shift                                              (0)
#define  ETN_ETN_MISS_FAE_misspkt_mask                                           (0xFFFF0000)
#define  ETN_ETN_MISS_FAE_fae_mask                                               (0x0000FFFF)
#define  ETN_ETN_MISS_FAE_misspkt(data)                                          (0xFFFF0000&((data)<<16))
#define  ETN_ETN_MISS_FAE_fae(data)                                              (0x0000FFFF&(data))
#define  ETN_ETN_MISS_FAE_get_misspkt(data)                                      ((0xFFFF0000&(data))>>16)
#define  ETN_ETN_MISS_FAE_get_fae(data)                                          (0x0000FFFF&(data))

#define  ETN_ETN_TX_COL                                                          0x1801681C
#define  ETN_ETN_TX_COL_reg_addr                                                 "0xB801681C"
#define  ETN_ETN_TX_COL_reg                                                      0xB801681C
#define  ETN_ETN_TX_COL_inst_addr                                                "0x0007"
#define  set_ETN_ETN_TX_COL_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_TX_COL_reg)=data)
#define  get_ETN_ETN_TX_COL_reg                                                  (*((volatile unsigned int*)ETN_ETN_TX_COL_reg))
#define  ETN_ETN_TX_COL_tx1col_shift                                             (16)
#define  ETN_ETN_TX_COL_txmcol_shift                                             (0)
#define  ETN_ETN_TX_COL_tx1col_mask                                              (0xFFFF0000)
#define  ETN_ETN_TX_COL_txmcol_mask                                              (0x0000FFFF)
#define  ETN_ETN_TX_COL_tx1col(data)                                             (0xFFFF0000&((data)<<16))
#define  ETN_ETN_TX_COL_txmcol(data)                                             (0x0000FFFF&(data))
#define  ETN_ETN_TX_COL_get_tx1col(data)                                         ((0xFFFF0000&(data))>>16)
#define  ETN_ETN_TX_COL_get_txmcol(data)                                         (0x0000FFFF&(data))

#define  ETN_ETN_RX_OK1                                                          0x18016820
#define  ETN_ETN_RX_OK1_reg_addr                                                 "0xB8016820"
#define  ETN_ETN_RX_OK1_reg                                                      0xB8016820
#define  ETN_ETN_RX_OK1_inst_addr                                                "0x0008"
#define  set_ETN_ETN_RX_OK1_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_RX_OK1_reg)=data)
#define  get_ETN_ETN_RX_OK1_reg                                                  (*((volatile unsigned int*)ETN_ETN_RX_OK1_reg))
#define  ETN_ETN_RX_OK1_rxokphy_shift                                            (16)
#define  ETN_ETN_RX_OK1_rxokbrd_shift                                            (0)
#define  ETN_ETN_RX_OK1_rxokphy_mask                                             (0xFFFF0000)
#define  ETN_ETN_RX_OK1_rxokbrd_mask                                             (0x0000FFFF)
#define  ETN_ETN_RX_OK1_rxokphy(data)                                            (0xFFFF0000&((data)<<16))
#define  ETN_ETN_RX_OK1_rxokbrd(data)                                            (0x0000FFFF&(data))
#define  ETN_ETN_RX_OK1_get_rxokphy(data)                                        ((0xFFFF0000&(data))>>16)
#define  ETN_ETN_RX_OK1_get_rxokbrd(data)                                        (0x0000FFFF&(data))

#define  ETN_ETN_RX_OK2                                                          0x18016824
#define  ETN_ETN_RX_OK2_reg_addr                                                 "0xB8016824"
#define  ETN_ETN_RX_OK2_reg                                                      0xB8016824
#define  ETN_ETN_RX_OK2_inst_addr                                                "0x0009"
#define  set_ETN_ETN_RX_OK2_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_RX_OK2_reg)=data)
#define  get_ETN_ETN_RX_OK2_reg                                                  (*((volatile unsigned int*)ETN_ETN_RX_OK2_reg))
#define  ETN_ETN_RX_OK2_rxokmul_shift                                            (16)
#define  ETN_ETN_RX_OK2_txabt_shift                                              (0)
#define  ETN_ETN_RX_OK2_rxokmul_mask                                             (0xFFFF0000)
#define  ETN_ETN_RX_OK2_txabt_mask                                               (0x0000FFFF)
#define  ETN_ETN_RX_OK2_rxokmul(data)                                            (0xFFFF0000&((data)<<16))
#define  ETN_ETN_RX_OK2_txabt(data)                                              (0x0000FFFF&(data))
#define  ETN_ETN_RX_OK2_get_rxokmul(data)                                        ((0xFFFF0000&(data))>>16)
#define  ETN_ETN_RX_OK2_get_txabt(data)                                          (0x0000FFFF&(data))

#define  ETN_ETN_TX_UN                                                           0x18016828
#define  ETN_ETN_TX_UN_reg_addr                                                  "0xB8016828"
#define  ETN_ETN_TX_UN_reg                                                       0xB8016828
#define  ETN_ETN_TX_UN_inst_addr                                                 "0x000A"
#define  set_ETN_ETN_TX_UN_reg(data)                                             (*((volatile unsigned int*)ETN_ETN_TX_UN_reg)=data)
#define  get_ETN_ETN_TX_UN_reg                                                   (*((volatile unsigned int*)ETN_ETN_TX_UN_reg))
#define  ETN_ETN_TX_UN_txundrn_shift                                             (16)
#define  ETN_ETN_TX_UN_dummy_15_0_shift                                          (0)
#define  ETN_ETN_TX_UN_txundrn_mask                                              (0xFFFF0000)
#define  ETN_ETN_TX_UN_dummy_15_0_mask                                           (0x0000FFFF)
#define  ETN_ETN_TX_UN_txundrn(data)                                             (0xFFFF0000&((data)<<16))
#define  ETN_ETN_TX_UN_dummy_15_0(data)                                          (0x0000FFFF&(data))
#define  ETN_ETN_TX_UN_get_txundrn(data)                                         ((0xFFFF0000&(data))>>16)
#define  ETN_ETN_TX_UN_get_dummy_15_0(data)                                      (0x0000FFFF&(data))

#define  ETN_ETN_TRSR                                                            0x18016834
#define  ETN_ETN_TRSR_reg_addr                                                   "0xB8016834"
#define  ETN_ETN_TRSR_reg                                                        0xB8016834
#define  ETN_ETN_TRSR_inst_addr                                                  "0x000B"
#define  set_ETN_ETN_TRSR_reg(data)                                              (*((volatile unsigned int*)ETN_ETN_TRSR_reg)=data)
#define  get_ETN_ETN_TRSR_reg                                                    (*((volatile unsigned int*)ETN_ETN_TRSR_reg))
#define  ETN_ETN_TRSR_dummy_31_4_shift                                           (4)
#define  ETN_ETN_TRSR_tok_shift                                                  (3)
#define  ETN_ETN_TRSR_tun_shift                                                  (2)
#define  ETN_ETN_TRSR_rxfifoempty_shift                                          (1)
#define  ETN_ETN_TRSR_rxfifofull_shift                                           (0)
#define  ETN_ETN_TRSR_dummy_31_4_mask                                            (0xFFFFFFF0)
#define  ETN_ETN_TRSR_tok_mask                                                   (0x00000008)
#define  ETN_ETN_TRSR_tun_mask                                                   (0x00000004)
#define  ETN_ETN_TRSR_rxfifoempty_mask                                           (0x00000002)
#define  ETN_ETN_TRSR_rxfifofull_mask                                            (0x00000001)
#define  ETN_ETN_TRSR_dummy_31_4(data)                                           (0xFFFFFFF0&((data)<<4))
#define  ETN_ETN_TRSR_tok(data)                                                  (0x00000008&((data)<<3))
#define  ETN_ETN_TRSR_tun(data)                                                  (0x00000004&((data)<<2))
#define  ETN_ETN_TRSR_rxfifoempty(data)                                          (0x00000002&((data)<<1))
#define  ETN_ETN_TRSR_rxfifofull(data)                                           (0x00000001&(data))
#define  ETN_ETN_TRSR_get_dummy_31_4(data)                                       ((0xFFFFFFF0&(data))>>4)
#define  ETN_ETN_TRSR_get_tok(data)                                              ((0x00000008&(data))>>3)
#define  ETN_ETN_TRSR_get_tun(data)                                              ((0x00000004&(data))>>2)
#define  ETN_ETN_TRSR_get_rxfifoempty(data)                                      ((0x00000002&(data))>>1)
#define  ETN_ETN_TRSR_get_rxfifofull(data)                                       (0x00000001&(data))

#define  ETN_ETN_CR                                                              0x18016838
#define  ETN_ETN_CR_reg_addr                                                     "0xB8016838"
#define  ETN_ETN_CR_reg                                                          0xB8016838
#define  ETN_ETN_CR_inst_addr                                                    "0x000C"
#define  set_ETN_ETN_CR_reg(data)                                                (*((volatile unsigned int*)ETN_ETN_CR_reg)=data)
#define  get_ETN_ETN_CR_reg                                                      (*((volatile unsigned int*)ETN_ETN_CR_reg))
#define  ETN_ETN_CR_dummy_31_4_shift                                             (4)
#define  ETN_ETN_CR_pow_etn_l_shift                                              (3)
#define  ETN_ETN_CR_rxvlan_shift                                                 (2)
#define  ETN_ETN_CR_rxchksum_shift                                               (1)
#define  ETN_ETN_CR_rst_shift                                                    (0)
#define  ETN_ETN_CR_dummy_31_4_mask                                              (0xFFFFFFF0)
#define  ETN_ETN_CR_pow_etn_l_mask                                               (0x00000008)
#define  ETN_ETN_CR_rxvlan_mask                                                  (0x00000004)
#define  ETN_ETN_CR_rxchksum_mask                                                (0x00000002)
#define  ETN_ETN_CR_rst_mask                                                     (0x00000001)
#define  ETN_ETN_CR_dummy_31_4(data)                                             (0xFFFFFFF0&((data)<<4))
#define  ETN_ETN_CR_pow_etn_l(data)                                              (0x00000008&((data)<<3))
#define  ETN_ETN_CR_rxvlan(data)                                                 (0x00000004&((data)<<2))
#define  ETN_ETN_CR_rxchksum(data)                                               (0x00000002&((data)<<1))
#define  ETN_ETN_CR_rst(data)                                                    (0x00000001&(data))
#define  ETN_ETN_CR_get_dummy_31_4(data)                                         ((0xFFFFFFF0&(data))>>4)
#define  ETN_ETN_CR_get_pow_etn_l(data)                                          ((0x00000008&(data))>>3)
#define  ETN_ETN_CR_get_rxvlan(data)                                             ((0x00000004&(data))>>2)
#define  ETN_ETN_CR_get_rxchksum(data)                                           ((0x00000002&(data))>>1)
#define  ETN_ETN_CR_get_rst(data)                                                (0x00000001&(data))

#define  ETN_ETN_IMR_ISR                                                         0x1801683C
#define  ETN_ETN_IMR_ISR_reg_addr                                                "0xB801683C"
#define  ETN_ETN_IMR_ISR_reg                                                     0xB801683C
#define  ETN_ETN_IMR_ISR_inst_addr                                               "0x000D"
#define  set_ETN_ETN_IMR_ISR_reg(data)                                           (*((volatile unsigned int*)ETN_ETN_IMR_ISR_reg)=data)
#define  get_ETN_ETN_IMR_ISR_reg                                                 (*((volatile unsigned int*)ETN_ETN_IMR_ISR_reg))
#define  ETN_ETN_IMR_ISR_dummy_31_27_shift                                       (27)
#define  ETN_ETN_IMR_ISR_imr_swint_shift                                         (26)
#define  ETN_ETN_IMR_ISR_imr_tdu_shift                                           (25)
#define  ETN_ETN_IMR_ISR_imr_pun_linkchg_shift                                   (24)
#define  ETN_ETN_IMR_ISR_imr_ter_shift                                           (23)
#define  ETN_ETN_IMR_ISR_imr_tok_ti_shift                                        (22)
#define  ETN_ETN_IMR_ISR_imr_rdu_shift                                           (21)
#define  ETN_ETN_IMR_ISR_imr_rer_ovf_shift                                       (20)
#define  ETN_ETN_IMR_ISR_imr_rer_runt_shift                                      (18)
#define  ETN_ETN_IMR_ISR_imr_rok_shift                                           (16)
#define  ETN_ETN_IMR_ISR_isr_swint_shift                                         (10)
#define  ETN_ETN_IMR_ISR_isr_tdu_shift                                           (9)
#define  ETN_ETN_IMR_ISR_isr_pun_linkchg_shift                                   (8)
#define  ETN_ETN_IMR_ISR_isr_ter_shift                                           (7)
#define  ETN_ETN_IMR_ISR_isr_tok_ti_shift                                        (6)
#define  ETN_ETN_IMR_ISR_isr_rdu_shift                                           (5)
#define  ETN_ETN_IMR_ISR_isr_rer_ovf_shift                                       (4)
#define  ETN_ETN_IMR_ISR_dummy_3_shift                                           (3)
#define  ETN_ETN_IMR_ISR_isr_rer_runt_shift                                      (2)
#define  ETN_ETN_IMR_ISR_dummy_1_shift                                           (1)
#define  ETN_ETN_IMR_ISR_isr_rok_shift                                           (0)
#define  ETN_ETN_IMR_ISR_dummy_31_27_mask                                        (0xF8000000)
#define  ETN_ETN_IMR_ISR_imr_swint_mask                                          (0x04000000)
#define  ETN_ETN_IMR_ISR_imr_tdu_mask                                            (0x02000000)
#define  ETN_ETN_IMR_ISR_imr_pun_linkchg_mask                                    (0x01000000)
#define  ETN_ETN_IMR_ISR_imr_ter_mask                                            (0x00800000)
#define  ETN_ETN_IMR_ISR_imr_tok_ti_mask                                         (0x00400000)
#define  ETN_ETN_IMR_ISR_imr_rdu_mask                                            (0x00200000)
#define  ETN_ETN_IMR_ISR_imr_rer_ovf_mask                                        (0x00100000)
#define  ETN_ETN_IMR_ISR_imr_rer_runt_mask                                       (0x00040000)
#define  ETN_ETN_IMR_ISR_imr_rok_mask                                            (0x00010000)
#define  ETN_ETN_IMR_ISR_isr_swint_mask                                          (0x00000400)
#define  ETN_ETN_IMR_ISR_isr_tdu_mask                                            (0x00000200)
#define  ETN_ETN_IMR_ISR_isr_pun_linkchg_mask                                    (0x00000100)
#define  ETN_ETN_IMR_ISR_isr_ter_mask                                            (0x00000080)
#define  ETN_ETN_IMR_ISR_isr_tok_ti_mask                                         (0x00000040)
#define  ETN_ETN_IMR_ISR_isr_rdu_mask                                            (0x00000020)
#define  ETN_ETN_IMR_ISR_isr_rer_ovf_mask                                        (0x00000010)
#define  ETN_ETN_IMR_ISR_dummy_3_mask                                            (0x00000008)
#define  ETN_ETN_IMR_ISR_isr_rer_runt_mask                                       (0x00000004)
#define  ETN_ETN_IMR_ISR_dummy_1_mask                                            (0x00000002)
#define  ETN_ETN_IMR_ISR_isr_rok_mask                                            (0x00000001)
#define  ETN_ETN_IMR_ISR_dummy_31_27(data)                                       (0xF8000000&((data)<<27))
#define  ETN_ETN_IMR_ISR_imr_swint(data)                                         (0x04000000&((data)<<26))
#define  ETN_ETN_IMR_ISR_imr_tdu(data)                                           (0x02000000&((data)<<25))
#define  ETN_ETN_IMR_ISR_imr_pun_linkchg(data)                                   (0x01000000&((data)<<24))
#define  ETN_ETN_IMR_ISR_imr_ter(data)                                           (0x00800000&((data)<<23))
#define  ETN_ETN_IMR_ISR_imr_tok_ti(data)                                        (0x00400000&((data)<<22))
#define  ETN_ETN_IMR_ISR_imr_rdu(data)                                           (0x00200000&((data)<<21))
#define  ETN_ETN_IMR_ISR_imr_rer_ovf(data)                                       (0x00100000&((data)<<20))
#define  ETN_ETN_IMR_ISR_imr_rer_runt(data)                                      (0x00040000&((data)<<18))
#define  ETN_ETN_IMR_ISR_imr_rok(data)                                           (0x00010000&((data)<<16))
#define  ETN_ETN_IMR_ISR_isr_swint(data)                                         (0x00000400&((data)<<10))
#define  ETN_ETN_IMR_ISR_isr_tdu(data)                                           (0x00000200&((data)<<9))
#define  ETN_ETN_IMR_ISR_isr_pun_linkchg(data)                                   (0x00000100&((data)<<8))
#define  ETN_ETN_IMR_ISR_isr_ter(data)                                           (0x00000080&((data)<<7))
#define  ETN_ETN_IMR_ISR_isr_tok_ti(data)                                        (0x00000040&((data)<<6))
#define  ETN_ETN_IMR_ISR_isr_rdu(data)                                           (0x00000020&((data)<<5))
#define  ETN_ETN_IMR_ISR_isr_rer_ovf(data)                                       (0x00000010&((data)<<4))
#define  ETN_ETN_IMR_ISR_dummy_3(data)                                           (0x00000008&((data)<<3))
#define  ETN_ETN_IMR_ISR_isr_rer_runt(data)                                      (0x00000004&((data)<<2))
#define  ETN_ETN_IMR_ISR_dummy_1(data)                                           (0x00000002&((data)<<1))
#define  ETN_ETN_IMR_ISR_isr_rok(data)                                           (0x00000001&(data))
#define  ETN_ETN_IMR_ISR_get_dummy_31_27(data)                                   ((0xF8000000&(data))>>27)
#define  ETN_ETN_IMR_ISR_get_imr_swint(data)                                     ((0x04000000&(data))>>26)
#define  ETN_ETN_IMR_ISR_get_imr_tdu(data)                                       ((0x02000000&(data))>>25)
#define  ETN_ETN_IMR_ISR_get_imr_pun_linkchg(data)                               ((0x01000000&(data))>>24)
#define  ETN_ETN_IMR_ISR_get_imr_ter(data)                                       ((0x00800000&(data))>>23)
#define  ETN_ETN_IMR_ISR_get_imr_tok_ti(data)                                    ((0x00400000&(data))>>22)
#define  ETN_ETN_IMR_ISR_get_imr_rdu(data)                                       ((0x00200000&(data))>>21)
#define  ETN_ETN_IMR_ISR_get_imr_rer_ovf(data)                                   ((0x00100000&(data))>>20)
#define  ETN_ETN_IMR_ISR_get_imr_rer_runt(data)                                  ((0x00040000&(data))>>18)
#define  ETN_ETN_IMR_ISR_get_imr_rok(data)                                       ((0x00010000&(data))>>16)
#define  ETN_ETN_IMR_ISR_get_isr_swint(data)                                     ((0x00000400&(data))>>10)
#define  ETN_ETN_IMR_ISR_get_isr_tdu(data)                                       ((0x00000200&(data))>>9)
#define  ETN_ETN_IMR_ISR_get_isr_pun_linkchg(data)                               ((0x00000100&(data))>>8)
#define  ETN_ETN_IMR_ISR_get_isr_ter(data)                                       ((0x00000080&(data))>>7)
#define  ETN_ETN_IMR_ISR_get_isr_tok_ti(data)                                    ((0x00000040&(data))>>6)
#define  ETN_ETN_IMR_ISR_get_isr_rdu(data)                                       ((0x00000020&(data))>>5)
#define  ETN_ETN_IMR_ISR_get_isr_rer_ovf(data)                                   ((0x00000010&(data))>>4)
#define  ETN_ETN_IMR_ISR_get_dummy_3(data)                                       ((0x00000008&(data))>>3)
#define  ETN_ETN_IMR_ISR_get_isr_rer_runt(data)                                  ((0x00000004&(data))>>2)
#define  ETN_ETN_IMR_ISR_get_dummy_1(data)                                       ((0x00000002&(data))>>1)
#define  ETN_ETN_IMR_ISR_get_isr_rok(data)                                       (0x00000001&(data))

#define  ETN_ETN_TCR                                                             0x18016840
#define  ETN_ETN_TCR_reg_addr                                                    "0xB8016840"
#define  ETN_ETN_TCR_reg                                                         0xB8016840
#define  ETN_ETN_TCR_inst_addr                                                   "0x000E"
#define  set_ETN_ETN_TCR_reg(data)                                               (*((volatile unsigned int*)ETN_ETN_TCR_reg)=data)
#define  get_ETN_ETN_TCR_reg                                                     (*((volatile unsigned int*)ETN_ETN_TCR_reg))
#define  ETN_ETN_TCR_dummy_31_13_shift                                           (13)
#define  ETN_ETN_TCR_ifg_shift                                                   (10)
#define  ETN_ETN_TCR_lbk_shift                                                   (8)
#define  ETN_ETN_TCR_dummy_7_0_shift                                             (0)
#define  ETN_ETN_TCR_dummy_31_13_mask                                            (0xFFFFE000)
#define  ETN_ETN_TCR_ifg_mask                                                    (0x00001C00)
#define  ETN_ETN_TCR_lbk_mask                                                    (0x00000300)
#define  ETN_ETN_TCR_dummy_7_0_mask                                              (0x000000FF)
#define  ETN_ETN_TCR_dummy_31_13(data)                                           (0xFFFFE000&((data)<<13))
#define  ETN_ETN_TCR_ifg(data)                                                   (0x00001C00&((data)<<10))
#define  ETN_ETN_TCR_lbk(data)                                                   (0x00000300&((data)<<8))
#define  ETN_ETN_TCR_dummy_7_0(data)                                             (0x000000FF&(data))
#define  ETN_ETN_TCR_get_dummy_31_13(data)                                       ((0xFFFFE000&(data))>>13)
#define  ETN_ETN_TCR_get_ifg(data)                                               ((0x00001C00&(data))>>10)
#define  ETN_ETN_TCR_get_lbk(data)                                               ((0x00000300&(data))>>8)
#define  ETN_ETN_TCR_get_dummy_7_0(data)                                         (0x000000FF&(data))

#define  ETN_ETN_RCR                                                             0x18016844
#define  ETN_ETN_RCR_reg_addr                                                    "0xB8016844"
#define  ETN_ETN_RCR_reg                                                         0xB8016844
#define  ETN_ETN_RCR_inst_addr                                                   "0x000F"
#define  set_ETN_ETN_RCR_reg(data)                                               (*((volatile unsigned int*)ETN_ETN_RCR_reg)=data)
#define  get_ETN_ETN_RCR_reg                                                     (*((volatile unsigned int*)ETN_ETN_RCR_reg))
#define  ETN_ETN_RCR_dummy_31_7_shift                                            (7)
#define  ETN_ETN_RCR_afl_shift                                                   (6)
#define  ETN_ETN_RCR_aer_shift                                                   (5)
#define  ETN_ETN_RCR_ar_shift                                                    (4)
#define  ETN_ETN_RCR_ab_shift                                                    (3)
#define  ETN_ETN_RCR_am_shift                                                    (2)
#define  ETN_ETN_RCR_apm_shift                                                   (1)
#define  ETN_ETN_RCR_aap_shift                                                   (0)
#define  ETN_ETN_RCR_dummy_31_7_mask                                             (0xFFFFFF80)
#define  ETN_ETN_RCR_afl_mask                                                    (0x00000040)
#define  ETN_ETN_RCR_aer_mask                                                    (0x00000020)
#define  ETN_ETN_RCR_ar_mask                                                     (0x00000010)
#define  ETN_ETN_RCR_ab_mask                                                     (0x00000008)
#define  ETN_ETN_RCR_am_mask                                                     (0x00000004)
#define  ETN_ETN_RCR_apm_mask                                                    (0x00000002)
#define  ETN_ETN_RCR_aap_mask                                                    (0x00000001)
#define  ETN_ETN_RCR_dummy_31_7(data)                                            (0xFFFFFF80&((data)<<7))
#define  ETN_ETN_RCR_afl(data)                                                   (0x00000040&((data)<<6))
#define  ETN_ETN_RCR_aer(data)                                                   (0x00000020&((data)<<5))
#define  ETN_ETN_RCR_ar(data)                                                    (0x00000010&((data)<<4))
#define  ETN_ETN_RCR_ab(data)                                                    (0x00000008&((data)<<3))
#define  ETN_ETN_RCR_am(data)                                                    (0x00000004&((data)<<2))
#define  ETN_ETN_RCR_apm(data)                                                   (0x00000002&((data)<<1))
#define  ETN_ETN_RCR_aap(data)                                                   (0x00000001&(data))
#define  ETN_ETN_RCR_get_dummy_31_7(data)                                        ((0xFFFFFF80&(data))>>7)
#define  ETN_ETN_RCR_get_afl(data)                                               ((0x00000040&(data))>>6)
#define  ETN_ETN_RCR_get_aer(data)                                               ((0x00000020&(data))>>5)
#define  ETN_ETN_RCR_get_ar(data)                                                ((0x00000010&(data))>>4)
#define  ETN_ETN_RCR_get_ab(data)                                                ((0x00000008&(data))>>3)
#define  ETN_ETN_RCR_get_am(data)                                                ((0x00000004&(data))>>2)
#define  ETN_ETN_RCR_get_apm(data)                                               ((0x00000002&(data))>>1)
#define  ETN_ETN_RCR_get_aap(data)                                               (0x00000001&(data))

#define  ETN_ETN_MSR                                                             0x18016858
#define  ETN_ETN_MSR_reg_addr                                                    "0xB8016858"
#define  ETN_ETN_MSR_reg                                                         0xB8016858
#define  ETN_ETN_MSR_inst_addr                                                   "0x0010"
#define  set_ETN_ETN_MSR_reg(data)                                               (*((volatile unsigned int*)ETN_ETN_MSR_reg)=data)
#define  get_ETN_ETN_MSR_reg                                                     (*((volatile unsigned int*)ETN_ETN_MSR_reg))
#define  ETN_ETN_MSR_force_txfce_shift                                           (31)
#define  ETN_ETN_MSR_rxfce_shift                                                 (30)
#define  ETN_ETN_MSR_txfce_shift                                                 (29)
#define  ETN_ETN_MSR_speed_10_shift                                              (27)
#define  ETN_ETN_MSR_linkb_shift                                                 (26)
#define  ETN_ETN_MSR_txpf_shift                                                  (25)
#define  ETN_ETN_MSR_rxpf_shift                                                  (24)
#define  ETN_ETN_MSR_dummy_23_0_shift                                            (0)
#define  ETN_ETN_MSR_force_txfce_mask                                            (0x80000000)
#define  ETN_ETN_MSR_rxfce_mask                                                  (0x40000000)
#define  ETN_ETN_MSR_txfce_mask                                                  (0x20000000)
#define  ETN_ETN_MSR_speed_10_mask                                               (0x08000000)
#define  ETN_ETN_MSR_linkb_mask                                                  (0x04000000)
#define  ETN_ETN_MSR_txpf_mask                                                   (0x02000000)
#define  ETN_ETN_MSR_rxpf_mask                                                   (0x01000000)
#define  ETN_ETN_MSR_dummy_23_0_mask                                             (0x00FFFFFF)
#define  ETN_ETN_MSR_force_txfce(data)                                           (0x80000000&((data)<<31))
#define  ETN_ETN_MSR_rxfce(data)                                                 (0x40000000&((data)<<30))
#define  ETN_ETN_MSR_txfce(data)                                                 (0x20000000&((data)<<29))
#define  ETN_ETN_MSR_speed_10(data)                                              (0x08000000&((data)<<27))
#define  ETN_ETN_MSR_linkb(data)                                                 (0x04000000&((data)<<26))
#define  ETN_ETN_MSR_txpf(data)                                                  (0x02000000&((data)<<25))
#define  ETN_ETN_MSR_rxpf(data)                                                  (0x01000000&((data)<<24))
#define  ETN_ETN_MSR_dummy_23_0(data)                                            (0x00FFFFFF&(data))
#define  ETN_ETN_MSR_get_force_txfce(data)                                       ((0x80000000&(data))>>31)
#define  ETN_ETN_MSR_get_rxfce(data)                                             ((0x40000000&(data))>>30)
#define  ETN_ETN_MSR_get_txfce(data)                                             ((0x20000000&(data))>>29)
#define  ETN_ETN_MSR_get_speed_10(data)                                          ((0x08000000&(data))>>27)
#define  ETN_ETN_MSR_get_linkb(data)                                             ((0x04000000&(data))>>26)
#define  ETN_ETN_MSR_get_txpf(data)                                              ((0x02000000&(data))>>25)
#define  ETN_ETN_MSR_get_rxpf(data)                                              ((0x01000000&(data))>>24)
#define  ETN_ETN_MSR_get_dummy_23_0(data)                                        (0x00FFFFFF&(data))

#define  ETN_ETN_MII_AR                                                          0x1801685C
#define  ETN_ETN_MII_AR_reg_addr                                                 "0xB801685C"
#define  ETN_ETN_MII_AR_reg                                                      0xB801685C
#define  ETN_ETN_MII_AR_inst_addr                                                "0x0011"
#define  set_ETN_ETN_MII_AR_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_MII_AR_reg)=data)
#define  get_ETN_ETN_MII_AR_reg                                                  (*((volatile unsigned int*)ETN_ETN_MII_AR_reg))
#define  ETN_ETN_MII_AR_flag_shift                                               (31)
#define  ETN_ETN_MII_AR_phyaddress_shift                                         (26)
#define  ETN_ETN_MII_AR_regaddr_shift                                            (16)
#define  ETN_ETN_MII_AR_data_shift                                               (0)
#define  ETN_ETN_MII_AR_flag_mask                                                (0x80000000)
#define  ETN_ETN_MII_AR_phyaddress_mask                                          (0x7C000000)
#define  ETN_ETN_MII_AR_regaddr_mask                                             (0x001F0000)
#define  ETN_ETN_MII_AR_data_mask                                                (0x0000FFFF)
#define  ETN_ETN_MII_AR_flag(data)                                               (0x80000000&((data)<<31))
#define  ETN_ETN_MII_AR_phyaddress(data)                                         (0x7C000000&((data)<<26))
#define  ETN_ETN_MII_AR_regaddr(data)                                            (0x001F0000&((data)<<16))
#define  ETN_ETN_MII_AR_data(data)                                               (0x0000FFFF&(data))
#define  ETN_ETN_MII_AR_get_flag(data)                                           ((0x80000000&(data))>>31)
#define  ETN_ETN_MII_AR_get_phyaddress(data)                                     ((0x7C000000&(data))>>26)
#define  ETN_ETN_MII_AR_get_regaddr(data)                                        ((0x001F0000&(data))>>16)
#define  ETN_ETN_MII_AR_get_data(data)                                           (0x0000FFFF&(data))

#define  ETN_ETN_SWINT                                                           0x18016860
#define  ETN_ETN_SWINT_reg_addr                                                  "0xB8016860"
#define  ETN_ETN_SWINT_reg                                                       0xB8016860
#define  ETN_ETN_SWINT_inst_addr                                                 "0x0012"
#define  set_ETN_ETN_SWINT_reg(data)                                             (*((volatile unsigned int*)ETN_ETN_SWINT_reg)=data)
#define  get_ETN_ETN_SWINT_reg                                                   (*((volatile unsigned int*)ETN_ETN_SWINT_reg))
#define  ETN_ETN_SWINT_swint_shift                                               (24)
#define  ETN_ETN_SWINT_spreg_shift                                               (4)
#define  ETN_ETN_SWINT_reg_debug_4byte_write_shift                               (3)
#define  ETN_ETN_SWINT_pwrdn_ana_pll_shift                                       (2)
#define  ETN_ETN_SWINT_pwrdn_dig_phy_shift                                       (1)
#define  ETN_ETN_SWINT_autostop_en_shift                                         (0)
#define  ETN_ETN_SWINT_swint_mask                                                (0x01000000)
#define  ETN_ETN_SWINT_spreg_mask                                                (0x000000F0)
#define  ETN_ETN_SWINT_reg_debug_4byte_write_mask                                (0x00000008)
#define  ETN_ETN_SWINT_pwrdn_ana_pll_mask                                        (0x00000004)
#define  ETN_ETN_SWINT_pwrdn_dig_phy_mask                                        (0x00000002)
#define  ETN_ETN_SWINT_autostop_en_mask                                          (0x00000001)
#define  ETN_ETN_SWINT_swint(data)                                               (0x01000000&((data)<<24))
#define  ETN_ETN_SWINT_spreg(data)                                               (0x000000F0&((data)<<4))
#define  ETN_ETN_SWINT_reg_debug_4byte_write(data)                               (0x00000008&((data)<<3))
#define  ETN_ETN_SWINT_pwrdn_ana_pll(data)                                       (0x00000004&((data)<<2))
#define  ETN_ETN_SWINT_pwrdn_dig_phy(data)                                       (0x00000002&((data)<<1))
#define  ETN_ETN_SWINT_autostop_en(data)                                         (0x00000001&(data))
#define  ETN_ETN_SWINT_get_swint(data)                                           ((0x01000000&(data))>>24)
#define  ETN_ETN_SWINT_get_spreg(data)                                           ((0x000000F0&(data))>>4)
#define  ETN_ETN_SWINT_get_reg_debug_4byte_write(data)                           ((0x00000008&(data))>>3)
#define  ETN_ETN_SWINT_get_pwrdn_ana_pll(data)                                   ((0x00000004&(data))>>2)
#define  ETN_ETN_SWINT_get_pwrdn_dig_phy(data)                                   ((0x00000002&(data))>>1)
#define  ETN_ETN_SWINT_get_autostop_en(data)                                     (0x00000001&(data))

#define  ETN_ETN_TxFPD1                                                          0x18016900
#define  ETN_ETN_TxFPD1_reg_addr                                                 "0xB8016900"
#define  ETN_ETN_TxFPD1_reg                                                      0xB8016900
#define  ETN_ETN_TxFPD1_inst_addr                                                "0x0013"
#define  set_ETN_ETN_TxFPD1_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_TxFPD1_reg)=data)
#define  get_ETN_ETN_TxFPD1_reg                                                  (*((volatile unsigned int*)ETN_ETN_TxFPD1_reg))
#define  ETN_ETN_TxFPD1_txfpd1_shift                                             (8)
#define  ETN_ETN_TxFPD1_dummy_7_0_shift                                          (0)
#define  ETN_ETN_TxFPD1_txfpd1_mask                                              (0xFFFFFF00)
#define  ETN_ETN_TxFPD1_dummy_7_0_mask                                           (0x000000FF)
#define  ETN_ETN_TxFPD1_txfpd1(data)                                             (0xFFFFFF00&((data)<<8))
#define  ETN_ETN_TxFPD1_dummy_7_0(data)                                          (0x000000FF&(data))
#define  ETN_ETN_TxFPD1_get_txfpd1(data)                                         ((0xFFFFFF00&(data))>>8)
#define  ETN_ETN_TxFPD1_get_dummy_7_0(data)                                      (0x000000FF&(data))

#define  ETN_ETN_TxCDO1                                                          0x18016904
#define  ETN_ETN_TxCDO1_reg_addr                                                 "0xB8016904"
#define  ETN_ETN_TxCDO1_reg                                                      0xB8016904
#define  ETN_ETN_TxCDO1_inst_addr                                                "0x0014"
#define  set_ETN_ETN_TxCDO1_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_TxCDO1_reg)=data)
#define  get_ETN_ETN_TxCDO1_reg                                                  (*((volatile unsigned int*)ETN_ETN_TxCDO1_reg))
#define  ETN_ETN_TxCDO1_dummy_31_22_shift                                        (22)
#define  ETN_ETN_TxCDO1_txcdo1_shift                                             (16)
#define  ETN_ETN_TxCDO1_dummy_15_0_shift                                         (0)
#define  ETN_ETN_TxCDO1_dummy_31_22_mask                                         (0xFFC00000)
#define  ETN_ETN_TxCDO1_txcdo1_mask                                              (0x003F0000)
#define  ETN_ETN_TxCDO1_dummy_15_0_mask                                          (0x0000FFFF)
#define  ETN_ETN_TxCDO1_dummy_31_22(data)                                        (0xFFC00000&((data)<<22))
#define  ETN_ETN_TxCDO1_txcdo1(data)                                             (0x003F0000&((data)<<16))
#define  ETN_ETN_TxCDO1_dummy_15_0(data)                                         (0x0000FFFF&(data))
#define  ETN_ETN_TxCDO1_get_dummy_31_22(data)                                    ((0xFFC00000&(data))>>22)
#define  ETN_ETN_TxCDO1_get_txcdo1(data)                                         ((0x003F0000&(data))>>16)
#define  ETN_ETN_TxCDO1_get_dummy_15_0(data)                                     (0x0000FFFF&(data))

#define  ETN_ETN_TxFPD2                                                          0x18016980
#define  ETN_ETN_TxFPD2_reg_addr                                                 "0xB8016980"
#define  ETN_ETN_TxFPD2_reg                                                      0xB8016980
#define  ETN_ETN_TxFPD2_inst_addr                                                "0x0015"
#define  set_ETN_ETN_TxFPD2_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_TxFPD2_reg)=data)
#define  get_ETN_ETN_TxFPD2_reg                                                  (*((volatile unsigned int*)ETN_ETN_TxFPD2_reg))
#define  ETN_ETN_TxFPD2_txfpd2_shift                                             (8)
#define  ETN_ETN_TxFPD2_dummy_7_0_shift                                          (0)
#define  ETN_ETN_TxFPD2_txfpd2_mask                                              (0xFFFFFF00)
#define  ETN_ETN_TxFPD2_dummy_7_0_mask                                           (0x000000FF)
#define  ETN_ETN_TxFPD2_txfpd2(data)                                             (0xFFFFFF00&((data)<<8))
#define  ETN_ETN_TxFPD2_dummy_7_0(data)                                          (0x000000FF&(data))
#define  ETN_ETN_TxFPD2_get_txfpd2(data)                                         ((0xFFFFFF00&(data))>>8)
#define  ETN_ETN_TxFPD2_get_dummy_7_0(data)                                      (0x000000FF&(data))

#define  ETN_ETN_TxCDO2                                                          0x18016984
#define  ETN_ETN_TxCDO2_reg_addr                                                 "0xB8016984"
#define  ETN_ETN_TxCDO2_reg                                                      0xB8016984
#define  ETN_ETN_TxCDO2_inst_addr                                                "0x0016"
#define  set_ETN_ETN_TxCDO2_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_TxCDO2_reg)=data)
#define  get_ETN_ETN_TxCDO2_reg                                                  (*((volatile unsigned int*)ETN_ETN_TxCDO2_reg))
#define  ETN_ETN_TxCDO2_dummy_31_22_shift                                        (22)
#define  ETN_ETN_TxCDO2_txcdo2_shift                                             (16)
#define  ETN_ETN_TxCDO2_dummy_15_0_shift                                         (0)
#define  ETN_ETN_TxCDO2_dummy_31_22_mask                                         (0xFFC00000)
#define  ETN_ETN_TxCDO2_txcdo2_mask                                              (0x003F0000)
#define  ETN_ETN_TxCDO2_dummy_15_0_mask                                          (0x0000FFFF)
#define  ETN_ETN_TxCDO2_dummy_31_22(data)                                        (0xFFC00000&((data)<<22))
#define  ETN_ETN_TxCDO2_txcdo2(data)                                             (0x003F0000&((data)<<16))
#define  ETN_ETN_TxCDO2_dummy_15_0(data)                                         (0x0000FFFF&(data))
#define  ETN_ETN_TxCDO2_get_dummy_31_22(data)                                    ((0xFFC00000&(data))>>22)
#define  ETN_ETN_TxCDO2_get_txcdo2(data)                                         ((0x003F0000&(data))>>16)
#define  ETN_ETN_TxCDO2_get_dummy_15_0(data)                                     (0x0000FFFF&(data))

#define  ETN_LED_CTRL                                                            0x18016988
#define  ETN_LED_CTRL_reg_addr                                                   "0xB8016988"
#define  ETN_LED_CTRL_reg                                                        0xB8016988
#define  ETN_LED_CTRL_inst_addr                                                  "0x0017"
#define  set_ETN_LED_CTRL_reg(data)                                              (*((volatile unsigned int*)ETN_LED_CTRL_reg)=data)
#define  get_ETN_LED_CTRL_reg                                                    (*((volatile unsigned int*)ETN_LED_CTRL_reg))
#define  ETN_LED_CTRL_etn_led0_inv_shift                                         (23)
#define  ETN_LED_CTRL_dummy_22_shift                                             (22)
#define  ETN_LED_CTRL_etn_led0_ps_shift                                          (20)
#define  ETN_LED_CTRL_etn_led1_inv_shift                                         (19)
#define  ETN_LED_CTRL_dummy_18_shift                                             (18)
#define  ETN_LED_CTRL_etn_led1_ps_shift                                          (16)
#define  ETN_LED_CTRL_etn_led2_inv_shift                                         (15)
#define  ETN_LED_CTRL_dummy_14_shift                                             (14)
#define  ETN_LED_CTRL_etn_led2_ps_shift                                          (12)
#define  ETN_LED_CTRL_etn_led3_inv_shift                                         (11)
#define  ETN_LED_CTRL_dummy_10_shift                                             (10)
#define  ETN_LED_CTRL_etn_led3_ps_shift                                          (8)
#define  ETN_LED_CTRL_etn_led4_inv_shift                                         (7)
#define  ETN_LED_CTRL_dummy_6_shift                                              (6)
#define  ETN_LED_CTRL_etn_led4_ps_shift                                          (4)
#define  ETN_LED_CTRL_dummy_3_0_shift                                            (0)
#define  ETN_LED_CTRL_etn_led0_inv_mask                                          (0x00800000)
#define  ETN_LED_CTRL_dummy_22_mask                                              (0x00400000)
#define  ETN_LED_CTRL_etn_led0_ps_mask                                           (0x00300000)
#define  ETN_LED_CTRL_etn_led1_inv_mask                                          (0x00080000)
#define  ETN_LED_CTRL_dummy_18_mask                                              (0x00040000)
#define  ETN_LED_CTRL_etn_led1_ps_mask                                           (0x00030000)
#define  ETN_LED_CTRL_etn_led2_inv_mask                                          (0x00008000)
#define  ETN_LED_CTRL_dummy_14_mask                                              (0x00004000)
#define  ETN_LED_CTRL_etn_led2_ps_mask                                           (0x00003000)
#define  ETN_LED_CTRL_etn_led3_inv_mask                                          (0x00000800)
#define  ETN_LED_CTRL_dummy_10_mask                                              (0x00000400)
#define  ETN_LED_CTRL_etn_led3_ps_mask                                           (0x00000300)
#define  ETN_LED_CTRL_etn_led4_inv_mask                                          (0x00000080)
#define  ETN_LED_CTRL_dummy_6_mask                                               (0x00000040)
#define  ETN_LED_CTRL_etn_led4_ps_mask                                           (0x00000030)
#define  ETN_LED_CTRL_dummy_3_0_mask                                             (0x0000000F)
#define  ETN_LED_CTRL_etn_led0_inv(data)                                         (0x00800000&((data)<<23))
#define  ETN_LED_CTRL_dummy_22(data)                                             (0x00400000&((data)<<22))
#define  ETN_LED_CTRL_etn_led0_ps(data)                                          (0x00300000&((data)<<20))
#define  ETN_LED_CTRL_etn_led1_inv(data)                                         (0x00080000&((data)<<19))
#define  ETN_LED_CTRL_dummy_18(data)                                             (0x00040000&((data)<<18))
#define  ETN_LED_CTRL_etn_led1_ps(data)                                          (0x00030000&((data)<<16))
#define  ETN_LED_CTRL_etn_led2_inv(data)                                         (0x00008000&((data)<<15))
#define  ETN_LED_CTRL_dummy_14(data)                                             (0x00004000&((data)<<14))
#define  ETN_LED_CTRL_etn_led2_ps(data)                                          (0x00003000&((data)<<12))
#define  ETN_LED_CTRL_etn_led3_inv(data)                                         (0x00000800&((data)<<11))
#define  ETN_LED_CTRL_dummy_10(data)                                             (0x00000400&((data)<<10))
#define  ETN_LED_CTRL_etn_led3_ps(data)                                          (0x00000300&((data)<<8))
#define  ETN_LED_CTRL_etn_led4_inv(data)                                         (0x00000080&((data)<<7))
#define  ETN_LED_CTRL_dummy_6(data)                                              (0x00000040&((data)<<6))
#define  ETN_LED_CTRL_etn_led4_ps(data)                                          (0x00000030&((data)<<4))
#define  ETN_LED_CTRL_dummy_3_0(data)                                            (0x0000000F&(data))
#define  ETN_LED_CTRL_get_etn_led0_inv(data)                                     ((0x00800000&(data))>>23)
#define  ETN_LED_CTRL_get_dummy_22(data)                                         ((0x00400000&(data))>>22)
#define  ETN_LED_CTRL_get_etn_led0_ps(data)                                      ((0x00300000&(data))>>20)
#define  ETN_LED_CTRL_get_etn_led1_inv(data)                                     ((0x00080000&(data))>>19)
#define  ETN_LED_CTRL_get_dummy_18(data)                                         ((0x00040000&(data))>>18)
#define  ETN_LED_CTRL_get_etn_led1_ps(data)                                      ((0x00030000&(data))>>16)
#define  ETN_LED_CTRL_get_etn_led2_inv(data)                                     ((0x00008000&(data))>>15)
#define  ETN_LED_CTRL_get_dummy_14(data)                                         ((0x00004000&(data))>>14)
#define  ETN_LED_CTRL_get_etn_led2_ps(data)                                      ((0x00003000&(data))>>12)
#define  ETN_LED_CTRL_get_etn_led3_inv(data)                                     ((0x00000800&(data))>>11)
#define  ETN_LED_CTRL_get_dummy_10(data)                                         ((0x00000400&(data))>>10)
#define  ETN_LED_CTRL_get_etn_led3_ps(data)                                      ((0x00000300&(data))>>8)
#define  ETN_LED_CTRL_get_etn_led4_inv(data)                                     ((0x00000080&(data))>>7)
#define  ETN_LED_CTRL_get_dummy_6(data)                                          ((0x00000040&(data))>>6)
#define  ETN_LED_CTRL_get_etn_led4_ps(data)                                      ((0x00000030&(data))>>4)
#define  ETN_LED_CTRL_get_dummy_3_0(data)                                        (0x0000000F&(data))

#define  ETN_BIST_CTRL                                                           0x1801698C
#define  ETN_BIST_CTRL_reg_addr                                                  "0xB801698C"
#define  ETN_BIST_CTRL_reg                                                       0xB801698C
#define  ETN_BIST_CTRL_inst_addr                                                 "0x0018"
#define  set_ETN_BIST_CTRL_reg(data)                                             (*((volatile unsigned int*)ETN_BIST_CTRL_reg)=data)
#define  get_ETN_BIST_CTRL_reg                                                   (*((volatile unsigned int*)ETN_BIST_CTRL_reg))
#define  ETN_BIST_CTRL_dvs_shift                                                 (14)
#define  ETN_BIST_CTRL_dvse_shift                                                (11)
#define  ETN_BIST_CTRL_dvs_mask                                                  (0x0003C000)
#define  ETN_BIST_CTRL_dvse_mask                                                 (0x00003800)
#define  ETN_BIST_CTRL_dvs(data)                                                 (0x0003C000&((data)<<14))
#define  ETN_BIST_CTRL_dvse(data)                                                (0x00003800&((data)<<11))
#define  ETN_BIST_CTRL_get_dvs(data)                                             ((0x0003C000&(data))>>14)
#define  ETN_BIST_CTRL_get_dvse(data)                                            ((0x00003800&(data))>>11)

#define  ETN_BIST_MODE                                                           0x18016990
#define  ETN_BIST_MODE_reg_addr                                                  "0xB8016990"
#define  ETN_BIST_MODE_reg                                                       0xB8016990
#define  ETN_BIST_MODE_inst_addr                                                 "0x0019"
#define  set_ETN_BIST_MODE_reg(data)                                             (*((volatile unsigned int*)ETN_BIST_MODE_reg)=data)
#define  get_ETN_BIST_MODE_reg                                                   (*((volatile unsigned int*)ETN_BIST_MODE_reg))
#define  ETN_BIST_MODE_bist_mode_shift                                           (0)
#define  ETN_BIST_MODE_bist_mode_mask                                            (0x00000001)
#define  ETN_BIST_MODE_bist_mode(data)                                           (0x00000001&(data))
#define  ETN_BIST_MODE_get_bist_mode(data)                                       (0x00000001&(data))

#define  ETN_BIST_DONE                                                           0x18016994
#define  ETN_BIST_DONE_reg_addr                                                  "0xB8016994"
#define  ETN_BIST_DONE_reg                                                       0xB8016994
#define  ETN_BIST_DONE_inst_addr                                                 "0x001A"
#define  set_ETN_BIST_DONE_reg(data)                                             (*((volatile unsigned int*)ETN_BIST_DONE_reg)=data)
#define  get_ETN_BIST_DONE_reg                                                   (*((volatile unsigned int*)ETN_BIST_DONE_reg))
#define  ETN_BIST_DONE_bist_done_shift                                           (0)
#define  ETN_BIST_DONE_bist_done_mask                                            (0x00000001)
#define  ETN_BIST_DONE_bist_done(data)                                           (0x00000001&(data))
#define  ETN_BIST_DONE_get_bist_done(data)                                       (0x00000001&(data))

#define  ETN_BIST_FAIL                                                           0x18016998
#define  ETN_BIST_FAIL_reg_addr                                                  "0xB8016998"
#define  ETN_BIST_FAIL_reg                                                       0xB8016998
#define  ETN_BIST_FAIL_inst_addr                                                 "0x001B"
#define  set_ETN_BIST_FAIL_reg(data)                                             (*((volatile unsigned int*)ETN_BIST_FAIL_reg)=data)
#define  get_ETN_BIST_FAIL_reg                                                   (*((volatile unsigned int*)ETN_BIST_FAIL_reg))
#define  ETN_BIST_FAIL_bist_fail_2_shift                                         (2)
#define  ETN_BIST_FAIL_bist_fail_1_shift                                         (1)
#define  ETN_BIST_FAIL_bist_fail_0_shift                                         (0)
#define  ETN_BIST_FAIL_bist_fail_2_mask                                          (0x00000004)
#define  ETN_BIST_FAIL_bist_fail_1_mask                                          (0x00000002)
#define  ETN_BIST_FAIL_bist_fail_0_mask                                          (0x00000001)
#define  ETN_BIST_FAIL_bist_fail_2(data)                                         (0x00000004&((data)<<2))
#define  ETN_BIST_FAIL_bist_fail_1(data)                                         (0x00000002&((data)<<1))
#define  ETN_BIST_FAIL_bist_fail_0(data)                                         (0x00000001&(data))
#define  ETN_BIST_FAIL_get_bist_fail_2(data)                                     ((0x00000004&(data))>>2)
#define  ETN_BIST_FAIL_get_bist_fail_1(data)                                     ((0x00000002&(data))>>1)
#define  ETN_BIST_FAIL_get_bist_fail_0(data)                                     (0x00000001&(data))

#define  ETN_BIST_DRF_MODE                                                       0x1801699C
#define  ETN_BIST_DRF_MODE_reg_addr                                              "0xB801699C"
#define  ETN_BIST_DRF_MODE_reg                                                   0xB801699C
#define  ETN_BIST_DRF_MODE_inst_addr                                             "0x001C"
#define  set_ETN_BIST_DRF_MODE_reg(data)                                         (*((volatile unsigned int*)ETN_BIST_DRF_MODE_reg)=data)
#define  get_ETN_BIST_DRF_MODE_reg                                               (*((volatile unsigned int*)ETN_BIST_DRF_MODE_reg))
#define  ETN_BIST_DRF_MODE_drf_bist_mode_shift                                   (0)
#define  ETN_BIST_DRF_MODE_drf_bist_mode_mask                                    (0x00000001)
#define  ETN_BIST_DRF_MODE_drf_bist_mode(data)                                   (0x00000001&(data))
#define  ETN_BIST_DRF_MODE_get_drf_bist_mode(data)                               (0x00000001&(data))

#define  ETN_BIST_DRF_RESUME                                                     0x180169A0
#define  ETN_BIST_DRF_RESUME_reg_addr                                            "0xB80169A0"
#define  ETN_BIST_DRF_RESUME_reg                                                 0xB80169A0
#define  ETN_BIST_DRF_RESUME_inst_addr                                           "0x001D"
#define  set_ETN_BIST_DRF_RESUME_reg(data)                                       (*((volatile unsigned int*)ETN_BIST_DRF_RESUME_reg)=data)
#define  get_ETN_BIST_DRF_RESUME_reg                                             (*((volatile unsigned int*)ETN_BIST_DRF_RESUME_reg))
#define  ETN_BIST_DRF_RESUME_drf_resume_shift                                    (0)
#define  ETN_BIST_DRF_RESUME_drf_resume_mask                                     (0x00000001)
#define  ETN_BIST_DRF_RESUME_drf_resume(data)                                    (0x00000001&(data))
#define  ETN_BIST_DRF_RESUME_get_drf_resume(data)                                (0x00000001&(data))

#define  ETN_BIST_DRF_DONE                                                       0x180169A4
#define  ETN_BIST_DRF_DONE_reg_addr                                              "0xB80169A4"
#define  ETN_BIST_DRF_DONE_reg                                                   0xB80169A4
#define  ETN_BIST_DRF_DONE_inst_addr                                             "0x001E"
#define  set_ETN_BIST_DRF_DONE_reg(data)                                         (*((volatile unsigned int*)ETN_BIST_DRF_DONE_reg)=data)
#define  get_ETN_BIST_DRF_DONE_reg                                               (*((volatile unsigned int*)ETN_BIST_DRF_DONE_reg))
#define  ETN_BIST_DRF_DONE_drf_done_shift                                        (0)
#define  ETN_BIST_DRF_DONE_drf_done_mask                                         (0x00000001)
#define  ETN_BIST_DRF_DONE_drf_done(data)                                        (0x00000001&(data))
#define  ETN_BIST_DRF_DONE_get_drf_done(data)                                    (0x00000001&(data))

#define  ETN_BIST_DRF_PAUSE                                                      0x180169A8
#define  ETN_BIST_DRF_PAUSE_reg_addr                                             "0xB80169A8"
#define  ETN_BIST_DRF_PAUSE_reg                                                  0xB80169A8
#define  ETN_BIST_DRF_PAUSE_inst_addr                                            "0x001F"
#define  set_ETN_BIST_DRF_PAUSE_reg(data)                                        (*((volatile unsigned int*)ETN_BIST_DRF_PAUSE_reg)=data)
#define  get_ETN_BIST_DRF_PAUSE_reg                                              (*((volatile unsigned int*)ETN_BIST_DRF_PAUSE_reg))
#define  ETN_BIST_DRF_PAUSE_drf_pause_shift                                      (0)
#define  ETN_BIST_DRF_PAUSE_drf_pause_mask                                       (0x00000001)
#define  ETN_BIST_DRF_PAUSE_drf_pause(data)                                      (0x00000001&(data))
#define  ETN_BIST_DRF_PAUSE_get_drf_pause(data)                                  (0x00000001&(data))

#define  ETN_BIST_DRF_FAIL                                                       0x180169AC
#define  ETN_BIST_DRF_FAIL_reg_addr                                              "0xB80169AC"
#define  ETN_BIST_DRF_FAIL_reg                                                   0xB80169AC
#define  ETN_BIST_DRF_FAIL_inst_addr                                             "0x0020"
#define  set_ETN_BIST_DRF_FAIL_reg(data)                                         (*((volatile unsigned int*)ETN_BIST_DRF_FAIL_reg)=data)
#define  get_ETN_BIST_DRF_FAIL_reg                                               (*((volatile unsigned int*)ETN_BIST_DRF_FAIL_reg))
#define  ETN_BIST_DRF_FAIL_drf_fail_2_shift                                      (2)
#define  ETN_BIST_DRF_FAIL_drf_fail_1_shift                                      (1)
#define  ETN_BIST_DRF_FAIL_drf_fail_0_shift                                      (0)
#define  ETN_BIST_DRF_FAIL_drf_fail_2_mask                                       (0x00000004)
#define  ETN_BIST_DRF_FAIL_drf_fail_1_mask                                       (0x00000002)
#define  ETN_BIST_DRF_FAIL_drf_fail_0_mask                                       (0x00000001)
#define  ETN_BIST_DRF_FAIL_drf_fail_2(data)                                      (0x00000004&((data)<<2))
#define  ETN_BIST_DRF_FAIL_drf_fail_1(data)                                      (0x00000002&((data)<<1))
#define  ETN_BIST_DRF_FAIL_drf_fail_0(data)                                      (0x00000001&(data))
#define  ETN_BIST_DRF_FAIL_get_drf_fail_2(data)                                  ((0x00000004&(data))>>2)
#define  ETN_BIST_DRF_FAIL_get_drf_fail_1(data)                                  ((0x00000002&(data))>>1)
#define  ETN_BIST_DRF_FAIL_get_drf_fail_0(data)                                  (0x00000001&(data))

#define  ETN_SELF_TEST_CTRL                                                      0x180169B0
#define  ETN_SELF_TEST_CTRL_reg_addr                                             "0xB80169B0"
#define  ETN_SELF_TEST_CTRL_reg                                                  0xB80169B0
#define  ETN_SELF_TEST_CTRL_inst_addr                                            "0x0021"
#define  set_ETN_SELF_TEST_CTRL_reg(data)                                        (*((volatile unsigned int*)ETN_SELF_TEST_CTRL_reg)=data)
#define  get_ETN_SELF_TEST_CTRL_reg                                              (*((volatile unsigned int*)ETN_SELF_TEST_CTRL_reg))
#define  ETN_SELF_TEST_CTRL_reg_sf_rx_gated_shift                                (6)
#define  ETN_SELF_TEST_CTRL_reg_sf_rx_start_shift                                (5)
#define  ETN_SELF_TEST_CTRL_reg_sf_rx_mode_shift                                 (4)
#define  ETN_SELF_TEST_CTRL_reg_sf_tx_start_shift                                (1)
#define  ETN_SELF_TEST_CTRL_reg_sf_tx_mode_shift                                 (0)
#define  ETN_SELF_TEST_CTRL_reg_sf_rx_gated_mask                                 (0x00000040)
#define  ETN_SELF_TEST_CTRL_reg_sf_rx_start_mask                                 (0x00000020)
#define  ETN_SELF_TEST_CTRL_reg_sf_rx_mode_mask                                  (0x00000010)
#define  ETN_SELF_TEST_CTRL_reg_sf_tx_start_mask                                 (0x00000002)
#define  ETN_SELF_TEST_CTRL_reg_sf_tx_mode_mask                                  (0x00000001)
#define  ETN_SELF_TEST_CTRL_reg_sf_rx_gated(data)                                (0x00000040&((data)<<6))
#define  ETN_SELF_TEST_CTRL_reg_sf_rx_start(data)                                (0x00000020&((data)<<5))
#define  ETN_SELF_TEST_CTRL_reg_sf_rx_mode(data)                                 (0x00000010&((data)<<4))
#define  ETN_SELF_TEST_CTRL_reg_sf_tx_start(data)                                (0x00000002&((data)<<1))
#define  ETN_SELF_TEST_CTRL_reg_sf_tx_mode(data)                                 (0x00000001&(data))
#define  ETN_SELF_TEST_CTRL_get_reg_sf_rx_gated(data)                            ((0x00000040&(data))>>6)
#define  ETN_SELF_TEST_CTRL_get_reg_sf_rx_start(data)                            ((0x00000020&(data))>>5)
#define  ETN_SELF_TEST_CTRL_get_reg_sf_rx_mode(data)                             ((0x00000010&(data))>>4)
#define  ETN_SELF_TEST_CTRL_get_reg_sf_tx_start(data)                            ((0x00000002&(data))>>1)
#define  ETN_SELF_TEST_CTRL_get_reg_sf_tx_mode(data)                             (0x00000001&(data))

#define  ETN_SELF_TEST_STATUS                                                    0x180169B4
#define  ETN_SELF_TEST_STATUS_reg_addr                                           "0xB80169B4"
#define  ETN_SELF_TEST_STATUS_reg                                                0xB80169B4
#define  ETN_SELF_TEST_STATUS_inst_addr                                          "0x0022"
#define  set_ETN_SELF_TEST_STATUS_reg(data)                                      (*((volatile unsigned int*)ETN_SELF_TEST_STATUS_reg)=data)
#define  get_ETN_SELF_TEST_STATUS_reg                                            (*((volatile unsigned int*)ETN_SELF_TEST_STATUS_reg))
#define  ETN_SELF_TEST_STATUS_reg_sf_rx_err_shift                                (5)
#define  ETN_SELF_TEST_STATUS_reg_sf_rx_done_shift                               (4)
#define  ETN_SELF_TEST_STATUS_reg_sf_tx_work_shift                               (0)
#define  ETN_SELF_TEST_STATUS_reg_sf_rx_err_mask                                 (0x00000020)
#define  ETN_SELF_TEST_STATUS_reg_sf_rx_done_mask                                (0x00000010)
#define  ETN_SELF_TEST_STATUS_reg_sf_tx_work_mask                                (0x00000001)
#define  ETN_SELF_TEST_STATUS_reg_sf_rx_err(data)                                (0x00000020&((data)<<5))
#define  ETN_SELF_TEST_STATUS_reg_sf_rx_done(data)                               (0x00000010&((data)<<4))
#define  ETN_SELF_TEST_STATUS_reg_sf_tx_work(data)                               (0x00000001&(data))
#define  ETN_SELF_TEST_STATUS_get_reg_sf_rx_err(data)                            ((0x00000020&(data))>>5)
#define  ETN_SELF_TEST_STATUS_get_reg_sf_rx_done(data)                           ((0x00000010&(data))>>4)
#define  ETN_SELF_TEST_STATUS_get_reg_sf_tx_work(data)                           (0x00000001&(data))

#define  ETN_ETN_RxFPD                                                           0x180169F0
#define  ETN_ETN_RxFPD_reg_addr                                                  "0xB80169F0"
#define  ETN_ETN_RxFPD_reg                                                       0xB80169F0
#define  ETN_ETN_RxFPD_inst_addr                                                 "0x0023"
#define  set_ETN_ETN_RxFPD_reg(data)                                             (*((volatile unsigned int*)ETN_ETN_RxFPD_reg)=data)
#define  get_ETN_ETN_RxFPD_reg                                                   (*((volatile unsigned int*)ETN_ETN_RxFPD_reg))
#define  ETN_ETN_RxFPD_rxfpd_shift                                               (8)
#define  ETN_ETN_RxFPD_dummy_7_0_shift                                           (0)
#define  ETN_ETN_RxFPD_rxfpd_mask                                                (0xFFFFFF00)
#define  ETN_ETN_RxFPD_dummy_7_0_mask                                            (0x000000FF)
#define  ETN_ETN_RxFPD_rxfpd(data)                                               (0xFFFFFF00&((data)<<8))
#define  ETN_ETN_RxFPD_dummy_7_0(data)                                           (0x000000FF&(data))
#define  ETN_ETN_RxFPD_get_rxfpd(data)                                           ((0xFFFFFF00&(data))>>8)
#define  ETN_ETN_RxFPD_get_dummy_7_0(data)                                       (0x000000FF&(data))

#define  ETN_ETN_RxCDO                                                           0x180169F4
#define  ETN_ETN_RxCDO_reg_addr                                                  "0xB80169F4"
#define  ETN_ETN_RxCDO_reg                                                       0xB80169F4
#define  ETN_ETN_RxCDO_inst_addr                                                 "0x0024"
#define  set_ETN_ETN_RxCDO_reg(data)                                             (*((volatile unsigned int*)ETN_ETN_RxCDO_reg)=data)
#define  get_ETN_ETN_RxCDO_reg                                                   (*((volatile unsigned int*)ETN_ETN_RxCDO_reg))
#define  ETN_ETN_RxCDO_dummy_31_22_shift                                         (22)
#define  ETN_ETN_RxCDO_rxcdo_shift                                               (16)
#define  ETN_ETN_RxCDO_dummy_15_10_shift                                         (10)
#define  ETN_ETN_RxCDO_rxringsize_shift                                          (8)
#define  ETN_ETN_RxCDO_dummy_7_0_shift                                           (0)
#define  ETN_ETN_RxCDO_dummy_31_22_mask                                          (0xFFC00000)
#define  ETN_ETN_RxCDO_rxcdo_mask                                                (0x003F0000)
#define  ETN_ETN_RxCDO_dummy_15_10_mask                                          (0x0000FC00)
#define  ETN_ETN_RxCDO_rxringsize_mask                                           (0x00000300)
#define  ETN_ETN_RxCDO_dummy_7_0_mask                                            (0x000000FF)
#define  ETN_ETN_RxCDO_dummy_31_22(data)                                         (0xFFC00000&((data)<<22))
#define  ETN_ETN_RxCDO_rxcdo(data)                                               (0x003F0000&((data)<<16))
#define  ETN_ETN_RxCDO_dummy_15_10(data)                                         (0x0000FC00&((data)<<10))
#define  ETN_ETN_RxCDO_rxringsize(data)                                          (0x00000300&((data)<<8))
#define  ETN_ETN_RxCDO_dummy_7_0(data)                                           (0x000000FF&(data))
#define  ETN_ETN_RxCDO_get_dummy_31_22(data)                                     ((0xFFC00000&(data))>>22)
#define  ETN_ETN_RxCDO_get_rxcdo(data)                                           ((0x003F0000&(data))>>16)
#define  ETN_ETN_RxCDO_get_dummy_15_10(data)                                     ((0x0000FC00&(data))>>10)
#define  ETN_ETN_RxCDO_get_rxringsize(data)                                      ((0x00000300&(data))>>8)
#define  ETN_ETN_RxCDO_get_dummy_7_0(data)                                       (0x000000FF&(data))

#define  ETN_ETN_RxPLEN                                                          0x18016A00
#define  ETN_ETN_RxPLEN_reg_addr                                                 "0xB8016A00"
#define  ETN_ETN_RxPLEN_reg                                                      0xB8016A00
#define  ETN_ETN_RxPLEN_inst_addr                                                "0x0025"
#define  set_ETN_ETN_RxPLEN_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_RxPLEN_reg)=data)
#define  get_ETN_ETN_RxPLEN_reg                                                  (*((volatile unsigned int*)ETN_ETN_RxPLEN_reg))
#define  ETN_ETN_RxPLEN_dummy_31_17_shift                                        (17)
#define  ETN_ETN_RxPLEN_fephy_led_sel_shift                                      (16)
#define  ETN_ETN_RxPLEN_fephy_int_mask_shift                                     (15)
#define  ETN_ETN_RxPLEN_acpu_int_en_shift                                        (14)
#define  ETN_ETN_RxPLEN_scup_int_en_shift                                        (13)
#define  ETN_ETN_RxPLEN_mdio_dbg_shift                                           (12)
#define  ETN_ETN_RxPLEN_sel_ext_mii_shift                                        (11)
#define  ETN_ETN_RxPLEN_phy_test_en_shift                                        (10)
#define  ETN_ETN_RxPLEN_etn_dbg_en_shift                                         (9)
#define  ETN_ETN_RxPLEN_etn_sel1_shift                                           (6)
#define  ETN_ETN_RxPLEN_etn_sel0_shift                                           (3)
#define  ETN_ETN_RxPLEN_nowr_own_shift                                           (2)
#define  ETN_ETN_RxPLEN_probe_signal_select_shift                                (0)
#define  ETN_ETN_RxPLEN_dummy_31_17_mask                                         (0xFFFE0000)
#define  ETN_ETN_RxPLEN_fephy_led_sel_mask                                       (0x00010000)
#define  ETN_ETN_RxPLEN_fephy_int_mask_mask                                      (0x00008000)
#define  ETN_ETN_RxPLEN_acpu_int_en_mask                                         (0x00004000)
#define  ETN_ETN_RxPLEN_scup_int_en_mask                                         (0x00002000)
#define  ETN_ETN_RxPLEN_mdio_dbg_mask                                            (0x00001000)
#define  ETN_ETN_RxPLEN_sel_ext_mii_mask                                         (0x00000800)
#define  ETN_ETN_RxPLEN_phy_test_en_mask                                         (0x00000400)
#define  ETN_ETN_RxPLEN_etn_dbg_en_mask                                          (0x00000200)
#define  ETN_ETN_RxPLEN_etn_sel1_mask                                            (0x000001C0)
#define  ETN_ETN_RxPLEN_etn_sel0_mask                                            (0x00000038)
#define  ETN_ETN_RxPLEN_nowr_own_mask                                            (0x00000004)
#define  ETN_ETN_RxPLEN_probe_signal_select_mask                                 (0x00000003)
#define  ETN_ETN_RxPLEN_dummy_31_17(data)                                        (0xFFFE0000&((data)<<17))
#define  ETN_ETN_RxPLEN_fephy_led_sel(data)                                      (0x00010000&((data)<<16))
#define  ETN_ETN_RxPLEN_fephy_int_mask(data)                                     (0x00008000&((data)<<15))
#define  ETN_ETN_RxPLEN_acpu_int_en(data)                                        (0x00004000&((data)<<14))
#define  ETN_ETN_RxPLEN_scup_int_en(data)                                        (0x00002000&((data)<<13))
#define  ETN_ETN_RxPLEN_mdio_dbg(data)                                           (0x00001000&((data)<<12))
#define  ETN_ETN_RxPLEN_sel_ext_mii(data)                                        (0x00000800&((data)<<11))
#define  ETN_ETN_RxPLEN_phy_test_en(data)                                        (0x00000400&((data)<<10))
#define  ETN_ETN_RxPLEN_etn_dbg_en(data)                                         (0x00000200&((data)<<9))
#define  ETN_ETN_RxPLEN_etn_sel1(data)                                           (0x000001C0&((data)<<6))
#define  ETN_ETN_RxPLEN_etn_sel0(data)                                           (0x00000038&((data)<<3))
#define  ETN_ETN_RxPLEN_nowr_own(data)                                           (0x00000004&((data)<<2))
#define  ETN_ETN_RxPLEN_probe_signal_select(data)                                (0x00000003&(data))
#define  ETN_ETN_RxPLEN_get_dummy_31_17(data)                                    ((0xFFFE0000&(data))>>17)
#define  ETN_ETN_RxPLEN_get_fephy_led_sel(data)                                  ((0x00010000&(data))>>16)
#define  ETN_ETN_RxPLEN_get_fephy_int_mask(data)                                 ((0x00008000&(data))>>15)
#define  ETN_ETN_RxPLEN_get_acpu_int_en(data)                                    ((0x00004000&(data))>>14)
#define  ETN_ETN_RxPLEN_get_scup_int_en(data)                                    ((0x00002000&(data))>>13)
#define  ETN_ETN_RxPLEN_get_mdio_dbg(data)                                       ((0x00001000&(data))>>12)
#define  ETN_ETN_RxPLEN_get_sel_ext_mii(data)                                    ((0x00000800&(data))>>11)
#define  ETN_ETN_RxPLEN_get_phy_test_en(data)                                    ((0x00000400&(data))>>10)
#define  ETN_ETN_RxPLEN_get_etn_dbg_en(data)                                     ((0x00000200&(data))>>9)
#define  ETN_ETN_RxPLEN_get_etn_sel1(data)                                       ((0x000001C0&(data))>>6)
#define  ETN_ETN_RxPLEN_get_etn_sel0(data)                                       ((0x00000038&(data))>>3)
#define  ETN_ETN_RxPLEN_get_nowr_own(data)                                       ((0x00000004&(data))>>2)
#define  ETN_ETN_RxPLEN_get_probe_signal_select(data)                            (0x00000003&(data))

#define  ETN_ETN_RDESN0                                                          0x18016A30
#define  ETN_ETN_RDESN0_reg_addr                                                 "0xB8016A30"
#define  ETN_ETN_RDESN0_reg                                                      0xB8016A30
#define  ETN_ETN_RDESN0_inst_addr                                                "0x0026"
#define  set_ETN_ETN_RDESN0_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_RDESN0_reg)=data)
#define  get_ETN_ETN_RDESN0_reg                                                  (*((volatile unsigned int*)ETN_ETN_RDESN0_reg))
#define  ETN_ETN_RDESN0_dummy_31_30_shift                                        (30)
#define  ETN_ETN_RDESN0_ethrntrxcpu_des_num_shift                                (24)
#define  ETN_ETN_RDESN0_wrap_shift                                               (16)
#define  ETN_ETN_RDESN0_rx_pse_des_thres_shift                                   (8)
#define  ETN_ETN_RDESN0_dummy_31_30_mask                                         (0xC0000000)
#define  ETN_ETN_RDESN0_ethrntrxcpu_des_num_mask                                 (0x3F000000)
#define  ETN_ETN_RDESN0_wrap_mask                                                (0x00010000)
#define  ETN_ETN_RDESN0_rx_pse_des_thres_mask                                    (0x00001F00)
#define  ETN_ETN_RDESN0_dummy_31_30(data)                                        (0xC0000000&((data)<<30))
#define  ETN_ETN_RDESN0_ethrntrxcpu_des_num(data)                                (0x3F000000&((data)<<24))
#define  ETN_ETN_RDESN0_wrap(data)                                               (0x00010000&((data)<<16))
#define  ETN_ETN_RDESN0_rx_pse_des_thres(data)                                   (0x00001F00&((data)<<8))
#define  ETN_ETN_RDESN0_get_dummy_31_30(data)                                    ((0xC0000000&(data))>>30)
#define  ETN_ETN_RDESN0_get_ethrntrxcpu_des_num(data)                            ((0x3F000000&(data))>>24)
#define  ETN_ETN_RDESN0_get_wrap(data)                                           ((0x00010000&(data))>>16)
#define  ETN_ETN_RDESN0_get_rx_pse_des_thres(data)                               ((0x00001F00&(data))>>8)

#define  ETN_ETN_RDESN1                                                          0x18016A34
#define  ETN_ETN_RDESN1_reg_addr                                                 "0xB8016A34"
#define  ETN_ETN_RDESN1_reg                                                      0xB8016A34
#define  ETN_ETN_RDESN1_inst_addr                                                "0x0027"
#define  set_ETN_ETN_RDESN1_reg(data)                                            (*((volatile unsigned int*)ETN_ETN_RDESN1_reg)=data)
#define  get_ETN_ETN_RDESN1_reg                                                  (*((volatile unsigned int*)ETN_ETN_RDESN1_reg))
#define  ETN_ETN_RDESN1_test1_shift                                              (31)
#define  ETN_ETN_RDESN1_dummy_30_21_shift                                        (21)
#define  ETN_ETN_RDESN1_txth_shift                                               (19)
#define  ETN_ETN_RDESN1_txintmitigation_shift                                    (16)
#define  ETN_ETN_RDESN1_rxpkttimer_shift                                         (13)
#define  ETN_ETN_RDESN1_rxfth_shift                                              (11)
#define  ETN_ETN_RDESN1_rxintmitigation_shift                                    (8)
#define  ETN_ETN_RDESN1_re_shift                                                 (3)
#define  ETN_ETN_RDESN1_te_shift                                                 (2)
#define  ETN_ETN_RDESN1_txfnl_shift                                              (1)
#define  ETN_ETN_RDESN1_txfnh_shift                                              (0)
#define  ETN_ETN_RDESN1_test1_mask                                               (0x80000000)
#define  ETN_ETN_RDESN1_dummy_30_21_mask                                         (0x7FE00000)
#define  ETN_ETN_RDESN1_txth_mask                                                (0x00180000)
#define  ETN_ETN_RDESN1_txintmitigation_mask                                     (0x00070000)
#define  ETN_ETN_RDESN1_rxpkttimer_mask                                          (0x0000E000)
#define  ETN_ETN_RDESN1_rxfth_mask                                               (0x00001800)
#define  ETN_ETN_RDESN1_rxintmitigation_mask                                     (0x00000700)
#define  ETN_ETN_RDESN1_re_mask                                                  (0x00000008)
#define  ETN_ETN_RDESN1_te_mask                                                  (0x00000004)
#define  ETN_ETN_RDESN1_txfnl_mask                                               (0x00000002)
#define  ETN_ETN_RDESN1_txfnh_mask                                               (0x00000001)
#define  ETN_ETN_RDESN1_test1(data)                                              (0x80000000&((data)<<31))
#define  ETN_ETN_RDESN1_dummy_30_21(data)                                        (0x7FE00000&((data)<<21))
#define  ETN_ETN_RDESN1_txth(data)                                               (0x00180000&((data)<<19))
#define  ETN_ETN_RDESN1_txintmitigation(data)                                    (0x00070000&((data)<<16))
#define  ETN_ETN_RDESN1_rxpkttimer(data)                                         (0x0000E000&((data)<<13))
#define  ETN_ETN_RDESN1_rxfth(data)                                              (0x00001800&((data)<<11))
#define  ETN_ETN_RDESN1_rxintmitigation(data)                                    (0x00000700&((data)<<8))
#define  ETN_ETN_RDESN1_re(data)                                                 (0x00000008&((data)<<3))
#define  ETN_ETN_RDESN1_te(data)                                                 (0x00000004&((data)<<2))
#define  ETN_ETN_RDESN1_txfnl(data)                                              (0x00000002&((data)<<1))
#define  ETN_ETN_RDESN1_txfnh(data)                                              (0x00000001&(data))
#define  ETN_ETN_RDESN1_get_test1(data)                                          ((0x80000000&(data))>>31)
#define  ETN_ETN_RDESN1_get_dummy_30_21(data)                                    ((0x7FE00000&(data))>>21)
#define  ETN_ETN_RDESN1_get_txth(data)                                           ((0x00180000&(data))>>19)
#define  ETN_ETN_RDESN1_get_txintmitigation(data)                                ((0x00070000&(data))>>16)
#define  ETN_ETN_RDESN1_get_rxpkttimer(data)                                     ((0x0000E000&(data))>>13)
#define  ETN_ETN_RDESN1_get_rxfth(data)                                          ((0x00001800&(data))>>11)
#define  ETN_ETN_RDESN1_get_rxintmitigation(data)                                ((0x00000700&(data))>>8)
#define  ETN_ETN_RDESN1_get_re(data)                                             ((0x00000008&(data))>>3)
#define  ETN_ETN_RDESN1_get_te(data)                                             ((0x00000004&(data))>>2)
#define  ETN_ETN_RDESN1_get_txfnl(data)                                          ((0x00000002&(data))>>1)
#define  ETN_ETN_RDESN1_get_txfnh(data)                                          (0x00000001&(data))

#define  ETN_ETN_WOL                                                             0x18016A38
#define  ETN_ETN_WOL_reg_addr                                                    "0xB8016A38"
#define  ETN_ETN_WOL_reg                                                         0xB8016A38
#define  ETN_ETN_WOL_inst_addr                                                   "0x0028"
#define  set_ETN_ETN_WOL_reg(data)                                               (*((volatile unsigned int*)ETN_ETN_WOL_reg)=data)
#define  get_ETN_ETN_WOL_reg                                                     (*((volatile unsigned int*)ETN_ETN_WOL_reg))
#define  ETN_ETN_WOL_force_4byte_align_shift                                     (11)
#define  ETN_ETN_WOL_swap_wol_compare_nibble_shift                               (8)
#define  ETN_ETN_WOL_wol_int_en_shift                                            (7)
#define  ETN_ETN_WOL_wol_pme_shift                                               (6)
#define  ETN_ETN_WOL_wol_sts_shift                                               (5)
#define  ETN_ETN_WOL_wol_cmd_shift                                               (4)
#define  ETN_ETN_WOL_fetch_descriptor_swap_enable_shift                          (1)
#define  ETN_ETN_WOL_close_descriptor_swap_enable_shift                          (0)
#define  ETN_ETN_WOL_force_4byte_align_mask                                      (0x00000800)
#define  ETN_ETN_WOL_swap_wol_compare_nibble_mask                                (0x00000100)
#define  ETN_ETN_WOL_wol_int_en_mask                                             (0x00000080)
#define  ETN_ETN_WOL_wol_pme_mask                                                (0x00000040)
#define  ETN_ETN_WOL_wol_sts_mask                                                (0x00000020)
#define  ETN_ETN_WOL_wol_cmd_mask                                                (0x00000010)
#define  ETN_ETN_WOL_fetch_descriptor_swap_enable_mask                           (0x00000002)
#define  ETN_ETN_WOL_close_descriptor_swap_enable_mask                           (0x00000001)
#define  ETN_ETN_WOL_force_4byte_align(data)                                     (0x00000800&((data)<<11))
#define  ETN_ETN_WOL_swap_wol_compare_nibble(data)                               (0x00000100&((data)<<8))
#define  ETN_ETN_WOL_wol_int_en(data)                                            (0x00000080&((data)<<7))
#define  ETN_ETN_WOL_wol_pme(data)                                               (0x00000040&((data)<<6))
#define  ETN_ETN_WOL_wol_sts(data)                                               (0x00000020&((data)<<5))
#define  ETN_ETN_WOL_wol_cmd(data)                                               (0x00000010&((data)<<4))
#define  ETN_ETN_WOL_fetch_descriptor_swap_enable(data)                          (0x00000002&((data)<<1))
#define  ETN_ETN_WOL_close_descriptor_swap_enable(data)                          (0x00000001&(data))
#define  ETN_ETN_WOL_get_force_4byte_align(data)                                 ((0x00000800&(data))>>11)
#define  ETN_ETN_WOL_get_swap_wol_compare_nibble(data)                           ((0x00000100&(data))>>8)
#define  ETN_ETN_WOL_get_wol_int_en(data)                                        ((0x00000080&(data))>>7)
#define  ETN_ETN_WOL_get_wol_pme(data)                                           ((0x00000040&(data))>>6)
#define  ETN_ETN_WOL_get_wol_sts(data)                                           ((0x00000020&(data))>>5)
#define  ETN_ETN_WOL_get_wol_cmd(data)                                           ((0x00000010&(data))>>4)
#define  ETN_ETN_WOL_get_fetch_descriptor_swap_enable(data)                      ((0x00000002&(data))>>1)
#define  ETN_ETN_WOL_get_close_descriptor_swap_enable(data)                      (0x00000001&(data))

#define  ETN_ETN_phy_info_reg                                                    0x18016A3C
#define  ETN_ETN_phy_info_reg_reg_addr                                           "0xB8016A3C"
#define  ETN_ETN_phy_info_reg_reg                                                0xB8016A3C
#define  ETN_ETN_phy_info_reg_inst_addr                                          "0x0029"
#define  set_ETN_ETN_phy_info_reg_reg(data)                                      (*((volatile unsigned int*)ETN_ETN_phy_info_reg_reg)=data)
#define  get_ETN_ETN_phy_info_reg_reg                                            (*((volatile unsigned int*)ETN_ETN_phy_info_reg_reg))
#define  ETN_ETN_phy_info_reg_efuse_rdy_shift                                    (31)
#define  ETN_ETN_phy_info_reg_efuse_default_shift                                (30)
#define  ETN_ETN_phy_info_reg_afe_pow_state_shift                                (29)
#define  ETN_ETN_phy_info_reg_page_now_shift                                     (8)
#define  ETN_ETN_phy_info_reg_reg_now_shift                                      (0)
#define  ETN_ETN_phy_info_reg_efuse_rdy_mask                                     (0x80000000)
#define  ETN_ETN_phy_info_reg_efuse_default_mask                                 (0x40000000)
#define  ETN_ETN_phy_info_reg_afe_pow_state_mask                                 (0x20000000)
#define  ETN_ETN_phy_info_reg_page_now_mask                                      (0x00FFFF00)
#define  ETN_ETN_phy_info_reg_reg_now_mask                                       (0x0000001F)
#define  ETN_ETN_phy_info_reg_efuse_rdy(data)                                    (0x80000000&((data)<<31))
#define  ETN_ETN_phy_info_reg_efuse_default(data)                                (0x40000000&((data)<<30))
#define  ETN_ETN_phy_info_reg_afe_pow_state(data)                                (0x20000000&((data)<<29))
#define  ETN_ETN_phy_info_reg_page_now(data)                                     (0x00FFFF00&((data)<<8))
#define  ETN_ETN_phy_info_reg_reg_now(data)                                      (0x0000001F&(data))
#define  ETN_ETN_phy_info_reg_get_efuse_rdy(data)                                ((0x80000000&(data))>>31)
#define  ETN_ETN_phy_info_reg_get_efuse_default(data)                            ((0x40000000&(data))>>30)
#define  ETN_ETN_phy_info_reg_get_afe_pow_state(data)                            ((0x20000000&(data))>>29)
#define  ETN_ETN_phy_info_reg_get_page_now(data)                                 ((0x00FFFF00&(data))>>8)
#define  ETN_ETN_phy_info_reg_get_reg_now(data)                                  (0x0000001F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ETN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idr0:8;
        RBus_UInt32  idr1:8;
        RBus_UInt32  idr2:8;
        RBus_UInt32  idr3:8;
    };
}etn_etn_idr_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idr4:8;
        RBus_UInt32  idr5:8;
        RBus_UInt32  dummy18016804_15_0:16;
    };
}etn_etn_idr_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mar0:8;
        RBus_UInt32  mar1:8;
        RBus_UInt32  mar2:8;
        RBus_UInt32  mar3:8;
    };
}etn_etn_mar_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mar4:8;
        RBus_UInt32  mar5:8;
        RBus_UInt32  mar6:8;
        RBus_UInt32  mar7:8;
    };
}etn_etn_mar_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txokc:16;
        RBus_UInt32  rxokc:16;
    };
}etn_etn_tx_rx_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txerr:16;
        RBus_UInt32  rxerr:16;
    };
}etn_etn_tx_rx_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  misspkt:16;
        RBus_UInt32  fae:16;
    };
}etn_etn_miss_fae_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx1col:16;
        RBus_UInt32  txmcol:16;
    };
}etn_etn_tx_col_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxokphy:16;
        RBus_UInt32  rxokbrd:16;
    };
}etn_etn_rx_ok1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxokmul:16;
        RBus_UInt32  txabt:16;
    };
}etn_etn_rx_ok2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txundrn:16;
        RBus_UInt32  dummy18016828_15_0:16;
    };
}etn_etn_tx_un_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016834_31_4:28;
        RBus_UInt32  tok:1;
        RBus_UInt32  tun:1;
        RBus_UInt32  rxfifoempty:1;
        RBus_UInt32  rxfifofull:1;
    };
}etn_etn_trsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016838_31_4:28;
        RBus_UInt32  pow_etn_l:1;
        RBus_UInt32  rxvlan:1;
        RBus_UInt32  rxchksum:1;
        RBus_UInt32  rst:1;
    };
}etn_etn_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1801683c_31_27:5;
        RBus_UInt32  imr_swint:1;
        RBus_UInt32  imr_tdu:1;
        RBus_UInt32  imr_pun_linkchg:1;
        RBus_UInt32  imr_ter:1;
        RBus_UInt32  imr_tok_ti:1;
        RBus_UInt32  imr_rdu:1;
        RBus_UInt32  imr_rer_ovf:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  imr_rer_runt:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  imr_rok:1;
        RBus_UInt32  res3:5;
        RBus_UInt32  isr_swint:1;
        RBus_UInt32  isr_tdu:1;
        RBus_UInt32  isr_pun_linkchg:1;
        RBus_UInt32  isr_ter:1;
        RBus_UInt32  isr_tok_ti:1;
        RBus_UInt32  isr_rdu:1;
        RBus_UInt32  isr_rer_ovf:1;
        RBus_UInt32  dummy1801683c_3:1;
        RBus_UInt32  isr_rer_runt:1;
        RBus_UInt32  dummy1801683c_1:1;
        RBus_UInt32  isr_rok:1;
    };
}etn_etn_imr_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016840_31_13:19;
        RBus_UInt32  ifg:3;
        RBus_UInt32  lbk:2;
        RBus_UInt32  dummy18016840_7_0:8;
    };
}etn_etn_tcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016844_31_7:25;
        RBus_UInt32  afl:1;
        RBus_UInt32  aer:1;
        RBus_UInt32  ar:1;
        RBus_UInt32  ab:1;
        RBus_UInt32  am:1;
        RBus_UInt32  apm:1;
        RBus_UInt32  aap:1;
    };
}etn_etn_rcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  force_txfce:1;
        RBus_UInt32  rxfce:1;
        RBus_UInt32  txfce:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  speed_10:1;
        RBus_UInt32  linkb:1;
        RBus_UInt32  txpf:1;
        RBus_UInt32  rxpf:1;
        RBus_UInt32  dummy18016858_23_0:24;
    };
}etn_etn_msr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag:1;
        RBus_UInt32  phyaddress:5;
        RBus_UInt32  res1:5;
        RBus_UInt32  regaddr:5;
        RBus_UInt32  data:16;
    };
}etn_etn_mii_ar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  swint:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  spreg:4;
        RBus_UInt32  reg_debug_4byte_write:1;
        RBus_UInt32  pwrdn_ana_pll:1;
        RBus_UInt32  pwrdn_dig_phy:1;
        RBus_UInt32  autostop_en:1;
    };
}etn_etn_swint_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txfpd1:24;
        RBus_UInt32  dummy18016900_7_0:8;
    };
}etn_etn_txfpd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016904_31_22:10;
        RBus_UInt32  txcdo1:6;
        RBus_UInt32  dummy18016904_15_0:16;
    };
}etn_etn_txcdo1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txfpd2:24;
        RBus_UInt32  dummy18016980_7_0:8;
    };
}etn_etn_txfpd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016984_31_22:10;
        RBus_UInt32  txcdo2:6;
        RBus_UInt32  dummy18016984_15_0:16;
    };
}etn_etn_txcdo2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  etn_led0_inv:1;
        RBus_UInt32  dummy18016988_22:1;
        RBus_UInt32  etn_led0_ps:2;
        RBus_UInt32  etn_led1_inv:1;
        RBus_UInt32  dummy18016988_18:1;
        RBus_UInt32  etn_led1_ps:2;
        RBus_UInt32  etn_led2_inv:1;
        RBus_UInt32  dummy18016988_14:1;
        RBus_UInt32  etn_led2_ps:2;
        RBus_UInt32  etn_led3_inv:1;
        RBus_UInt32  dummy18016988_10:1;
        RBus_UInt32  etn_led3_ps:2;
        RBus_UInt32  etn_led4_inv:1;
        RBus_UInt32  dummy18016988_6:1;
        RBus_UInt32  etn_led4_ps:2;
        RBus_UInt32  dummy18016988_3_0:4;
    };
}etn_led_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  dvs:4;
        RBus_UInt32  dvse:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:3;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
    };
}etn_bist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_mode:1;
    };
}etn_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_done:1;
    };
}etn_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}etn_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_bist_mode:1;
    };
}etn_bist_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_resume:1;
    };
}etn_bist_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_done:1;
    };
}etn_bist_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_pause:1;
    };
}etn_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  drf_fail_2:1;
        RBus_UInt32  drf_fail_1:1;
        RBus_UInt32  drf_fail_0:1;
    };
}etn_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  reg_sf_rx_gated:1;
        RBus_UInt32  reg_sf_rx_start:1;
        RBus_UInt32  reg_sf_rx_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_sf_tx_start:1;
        RBus_UInt32  reg_sf_tx_mode:1;
    };
}etn_self_test_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  reg_sf_rx_err:1;
        RBus_UInt32  reg_sf_rx_done:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_sf_tx_work:1;
    };
}etn_self_test_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxfpd:24;
        RBus_UInt32  dummy180169f0_7_0:8;
    };
}etn_etn_rxfpd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180169f4_31_22:10;
        RBus_UInt32  rxcdo:6;
        RBus_UInt32  dummy180169f4_15_10:6;
        RBus_UInt32  rxringsize:2;
        RBus_UInt32  dummy180169f4_7_0:8;
    };
}etn_etn_rxcdo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016a00_31_17:15;
        RBus_UInt32  fephy_led_sel:1;
        RBus_UInt32  fephy_int_mask:1;
        RBus_UInt32  acpu_int_en:1;
        RBus_UInt32  scup_int_en:1;
        RBus_UInt32  mdio_dbg:1;
        RBus_UInt32  sel_ext_mii:1;
        RBus_UInt32  phy_test_en:1;
        RBus_UInt32  etn_dbg_en:1;
        RBus_UInt32  etn_sel1:3;
        RBus_UInt32  etn_sel0:3;
        RBus_UInt32  nowr_own:1;
        RBus_UInt32  probe_signal_select:2;
    };
}etn_etn_rxplen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016a30_31_30:2;
        RBus_UInt32  ethrntrxcpu_des_num:6;
        RBus_UInt32  res1:7;
        RBus_UInt32  wrap:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rx_pse_des_thres:5;
        RBus_UInt32  res3:8;
    };
}etn_etn_rdesn0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test1:1;
        RBus_UInt32  dummy18016a34_30_21:10;
        RBus_UInt32  txth:2;
        RBus_UInt32  txintmitigation:3;
        RBus_UInt32  rxpkttimer:3;
        RBus_UInt32  rxfth:2;
        RBus_UInt32  rxintmitigation:3;
        RBus_UInt32  res1:4;
        RBus_UInt32  re:1;
        RBus_UInt32  te:1;
        RBus_UInt32  txfnl:1;
        RBus_UInt32  txfnh:1;
    };
}etn_etn_rdesn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  force_4byte_align:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  swap_wol_compare_nibble:1;
        RBus_UInt32  wol_int_en:1;
        RBus_UInt32  wol_pme:1;
        RBus_UInt32  wol_sts:1;
        RBus_UInt32  wol_cmd:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  fetch_descriptor_swap_enable:1;
        RBus_UInt32  close_descriptor_swap_enable:1;
    };
}etn_etn_wol_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  efuse_rdy:1;
        RBus_UInt32  efuse_default:1;
        RBus_UInt32  afe_pow_state:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  page_now:16;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_now:5;
    };
}etn_etn_phy_info_reg_RBUS;

#else //apply LITTLE_ENDIAN

//======ETN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idr3:8;
        RBus_UInt32  idr2:8;
        RBus_UInt32  idr1:8;
        RBus_UInt32  idr0:8;
    };
}etn_etn_idr_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016804_15_0:16;
        RBus_UInt32  idr5:8;
        RBus_UInt32  idr4:8;
    };
}etn_etn_idr_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mar3:8;
        RBus_UInt32  mar2:8;
        RBus_UInt32  mar1:8;
        RBus_UInt32  mar0:8;
    };
}etn_etn_mar_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mar7:8;
        RBus_UInt32  mar6:8;
        RBus_UInt32  mar5:8;
        RBus_UInt32  mar4:8;
    };
}etn_etn_mar_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxokc:16;
        RBus_UInt32  txokc:16;
    };
}etn_etn_tx_rx_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxerr:16;
        RBus_UInt32  txerr:16;
    };
}etn_etn_tx_rx_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fae:16;
        RBus_UInt32  misspkt:16;
    };
}etn_etn_miss_fae_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txmcol:16;
        RBus_UInt32  tx1col:16;
    };
}etn_etn_tx_col_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxokbrd:16;
        RBus_UInt32  rxokphy:16;
    };
}etn_etn_rx_ok1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txabt:16;
        RBus_UInt32  rxokmul:16;
    };
}etn_etn_rx_ok2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016828_15_0:16;
        RBus_UInt32  txundrn:16;
    };
}etn_etn_tx_un_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxfifofull:1;
        RBus_UInt32  rxfifoempty:1;
        RBus_UInt32  tun:1;
        RBus_UInt32  tok:1;
        RBus_UInt32  dummy18016834_31_4:28;
    };
}etn_etn_trsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rst:1;
        RBus_UInt32  rxchksum:1;
        RBus_UInt32  rxvlan:1;
        RBus_UInt32  pow_etn_l:1;
        RBus_UInt32  dummy18016838_31_4:28;
    };
}etn_etn_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  isr_rok:1;
        RBus_UInt32  dummy1801683c_1:1;
        RBus_UInt32  isr_rer_runt:1;
        RBus_UInt32  dummy1801683c_3:1;
        RBus_UInt32  isr_rer_ovf:1;
        RBus_UInt32  isr_rdu:1;
        RBus_UInt32  isr_tok_ti:1;
        RBus_UInt32  isr_ter:1;
        RBus_UInt32  isr_pun_linkchg:1;
        RBus_UInt32  isr_tdu:1;
        RBus_UInt32  isr_swint:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  imr_rok:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  imr_rer_runt:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  imr_rer_ovf:1;
        RBus_UInt32  imr_rdu:1;
        RBus_UInt32  imr_tok_ti:1;
        RBus_UInt32  imr_ter:1;
        RBus_UInt32  imr_pun_linkchg:1;
        RBus_UInt32  imr_tdu:1;
        RBus_UInt32  imr_swint:1;
        RBus_UInt32  dummy1801683c_31_27:5;
    };
}etn_etn_imr_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016840_7_0:8;
        RBus_UInt32  lbk:2;
        RBus_UInt32  ifg:3;
        RBus_UInt32  dummy18016840_31_13:19;
    };
}etn_etn_tcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aap:1;
        RBus_UInt32  apm:1;
        RBus_UInt32  am:1;
        RBus_UInt32  ab:1;
        RBus_UInt32  ar:1;
        RBus_UInt32  aer:1;
        RBus_UInt32  afl:1;
        RBus_UInt32  dummy18016844_31_7:25;
    };
}etn_etn_rcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016858_23_0:24;
        RBus_UInt32  rxpf:1;
        RBus_UInt32  txpf:1;
        RBus_UInt32  linkb:1;
        RBus_UInt32  speed_10:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  txfce:1;
        RBus_UInt32  rxfce:1;
        RBus_UInt32  force_txfce:1;
    };
}etn_etn_msr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:16;
        RBus_UInt32  regaddr:5;
        RBus_UInt32  res1:5;
        RBus_UInt32  phyaddress:5;
        RBus_UInt32  flag:1;
    };
}etn_etn_mii_ar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  autostop_en:1;
        RBus_UInt32  pwrdn_dig_phy:1;
        RBus_UInt32  pwrdn_ana_pll:1;
        RBus_UInt32  reg_debug_4byte_write:1;
        RBus_UInt32  spreg:4;
        RBus_UInt32  res1:16;
        RBus_UInt32  swint:1;
        RBus_UInt32  res2:7;
    };
}etn_etn_swint_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016900_7_0:8;
        RBus_UInt32  txfpd1:24;
    };
}etn_etn_txfpd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016904_15_0:16;
        RBus_UInt32  txcdo1:6;
        RBus_UInt32  dummy18016904_31_22:10;
    };
}etn_etn_txcdo1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016980_7_0:8;
        RBus_UInt32  txfpd2:24;
    };
}etn_etn_txfpd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016984_15_0:16;
        RBus_UInt32  txcdo2:6;
        RBus_UInt32  dummy18016984_31_22:10;
    };
}etn_etn_txcdo2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18016988_3_0:4;
        RBus_UInt32  etn_led4_ps:2;
        RBus_UInt32  dummy18016988_6:1;
        RBus_UInt32  etn_led4_inv:1;
        RBus_UInt32  etn_led3_ps:2;
        RBus_UInt32  dummy18016988_10:1;
        RBus_UInt32  etn_led3_inv:1;
        RBus_UInt32  etn_led2_ps:2;
        RBus_UInt32  dummy18016988_14:1;
        RBus_UInt32  etn_led2_inv:1;
        RBus_UInt32  etn_led1_ps:2;
        RBus_UInt32  dummy18016988_18:1;
        RBus_UInt32  etn_led1_inv:1;
        RBus_UInt32  etn_led0_ps:2;
        RBus_UInt32  dummy18016988_22:1;
        RBus_UInt32  etn_led0_inv:1;
        RBus_UInt32  res1:8;
    };
}etn_led_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  dvse:3;
        RBus_UInt32  dvs:4;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:8;
    };
}etn_bist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  res1:31;
    };
}etn_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done:1;
        RBus_UInt32  res1:31;
    };
}etn_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  res1:29;
    };
}etn_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_mode:1;
        RBus_UInt32  res1:31;
    };
}etn_bist_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_resume:1;
        RBus_UInt32  res1:31;
    };
}etn_bist_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_done:1;
        RBus_UInt32  res1:31;
    };
}etn_bist_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_pause:1;
        RBus_UInt32  res1:31;
    };
}etn_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_fail_0:1;
        RBus_UInt32  drf_fail_1:1;
        RBus_UInt32  drf_fail_2:1;
        RBus_UInt32  res1:29;
    };
}etn_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_sf_tx_mode:1;
        RBus_UInt32  reg_sf_tx_start:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_sf_rx_mode:1;
        RBus_UInt32  reg_sf_rx_start:1;
        RBus_UInt32  reg_sf_rx_gated:1;
        RBus_UInt32  res2:25;
    };
}etn_self_test_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_sf_tx_work:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_sf_rx_done:1;
        RBus_UInt32  reg_sf_rx_err:1;
        RBus_UInt32  res2:26;
    };
}etn_self_test_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180169f0_7_0:8;
        RBus_UInt32  rxfpd:24;
    };
}etn_etn_rxfpd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180169f4_7_0:8;
        RBus_UInt32  rxringsize:2;
        RBus_UInt32  dummy180169f4_15_10:6;
        RBus_UInt32  rxcdo:6;
        RBus_UInt32  dummy180169f4_31_22:10;
    };
}etn_etn_rxcdo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  probe_signal_select:2;
        RBus_UInt32  nowr_own:1;
        RBus_UInt32  etn_sel0:3;
        RBus_UInt32  etn_sel1:3;
        RBus_UInt32  etn_dbg_en:1;
        RBus_UInt32  phy_test_en:1;
        RBus_UInt32  sel_ext_mii:1;
        RBus_UInt32  mdio_dbg:1;
        RBus_UInt32  scup_int_en:1;
        RBus_UInt32  acpu_int_en:1;
        RBus_UInt32  fephy_int_mask:1;
        RBus_UInt32  fephy_led_sel:1;
        RBus_UInt32  dummy18016a00_31_17:15;
    };
}etn_etn_rxplen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rx_pse_des_thres:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  wrap:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  ethrntrxcpu_des_num:6;
        RBus_UInt32  dummy18016a30_31_30:2;
    };
}etn_etn_rdesn0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txfnh:1;
        RBus_UInt32  txfnl:1;
        RBus_UInt32  te:1;
        RBus_UInt32  re:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  rxintmitigation:3;
        RBus_UInt32  rxfth:2;
        RBus_UInt32  rxpkttimer:3;
        RBus_UInt32  txintmitigation:3;
        RBus_UInt32  txth:2;
        RBus_UInt32  dummy18016a34_30_21:10;
        RBus_UInt32  test1:1;
    };
}etn_etn_rdesn1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  close_descriptor_swap_enable:1;
        RBus_UInt32  fetch_descriptor_swap_enable:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  wol_cmd:1;
        RBus_UInt32  wol_sts:1;
        RBus_UInt32  wol_pme:1;
        RBus_UInt32  wol_int_en:1;
        RBus_UInt32  swap_wol_compare_nibble:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  force_4byte_align:1;
        RBus_UInt32  res3:20;
    };
}etn_etn_wol_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_now:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  page_now:16;
        RBus_UInt32  res2:5;
        RBus_UInt32  afe_pow_state:1;
        RBus_UInt32  efuse_default:1;
        RBus_UInt32  efuse_rdy:1;
    };
}etn_etn_phy_info_reg_RBUS;




#endif 


#endif 
