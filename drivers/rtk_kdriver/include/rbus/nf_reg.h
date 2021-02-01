/**
* @file Mac5-DesignSpec-NAND_arch
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_NF_REG_H_
#define _RBUS_NF_REG_H_

#include "rbus_types.h"



//  NF Register Address
#define  NF_ND_PA0                                                               0x18010000
#define  NF_ND_PA0_reg_addr                                                      "0xB8010000"
#define  NF_ND_PA0_reg                                                           0xB8010000
#define  NF_ND_PA0_inst_addr                                                     "0x0000"
#define  set_NF_ND_PA0_reg(data)                                                 (*((volatile unsigned int*)NF_ND_PA0_reg)=data)
#define  get_NF_ND_PA0_reg                                                       (*((volatile unsigned int*)NF_ND_PA0_reg))
#define  NF_ND_PA0_page_addr0_shift                                              (0)
#define  NF_ND_PA0_page_addr0_mask                                               (0x000000FF)
#define  NF_ND_PA0_page_addr0(data)                                              (0x000000FF&(data))
#define  NF_ND_PA0_get_page_addr0(data)                                          (0x000000FF&(data))

#define  NF_ND_PA1                                                               0x18010004
#define  NF_ND_PA1_reg_addr                                                      "0xB8010004"
#define  NF_ND_PA1_reg                                                           0xB8010004
#define  NF_ND_PA1_inst_addr                                                     "0x0001"
#define  set_NF_ND_PA1_reg(data)                                                 (*((volatile unsigned int*)NF_ND_PA1_reg)=data)
#define  get_NF_ND_PA1_reg                                                       (*((volatile unsigned int*)NF_ND_PA1_reg))
#define  NF_ND_PA1_page_addr1_shift                                              (0)
#define  NF_ND_PA1_page_addr1_mask                                               (0x000000FF)
#define  NF_ND_PA1_page_addr1(data)                                              (0x000000FF&(data))
#define  NF_ND_PA1_get_page_addr1(data)                                          (0x000000FF&(data))

#define  NF_ND_PA2                                                               0x18010008
#define  NF_ND_PA2_reg_addr                                                      "0xB8010008"
#define  NF_ND_PA2_reg                                                           0xB8010008
#define  NF_ND_PA2_inst_addr                                                     "0x0002"
#define  set_NF_ND_PA2_reg(data)                                                 (*((volatile unsigned int*)NF_ND_PA2_reg)=data)
#define  get_NF_ND_PA2_reg                                                       (*((volatile unsigned int*)NF_ND_PA2_reg))
#define  NF_ND_PA2_addr_mode_shift                                               (5)
#define  NF_ND_PA2_page_addr2_shift                                              (0)
#define  NF_ND_PA2_addr_mode_mask                                                (0x000000E0)
#define  NF_ND_PA2_page_addr2_mask                                               (0x0000001F)
#define  NF_ND_PA2_addr_mode(data)                                               (0x000000E0&((data)<<5))
#define  NF_ND_PA2_page_addr2(data)                                              (0x0000001F&(data))
#define  NF_ND_PA2_get_addr_mode(data)                                           ((0x000000E0&(data))>>5)
#define  NF_ND_PA2_get_page_addr2(data)                                          (0x0000001F&(data))

#define  NF_ND_CA0                                                               0x1801000C
#define  NF_ND_CA0_reg_addr                                                      "0xB801000C"
#define  NF_ND_CA0_reg                                                           0xB801000C
#define  NF_ND_CA0_inst_addr                                                     "0x0003"
#define  set_NF_ND_CA0_reg(data)                                                 (*((volatile unsigned int*)NF_ND_CA0_reg)=data)
#define  get_NF_ND_CA0_reg                                                       (*((volatile unsigned int*)NF_ND_CA0_reg))
#define  NF_ND_CA0_col_addr0_shift                                               (0)
#define  NF_ND_CA0_col_addr0_mask                                                (0x000000FF)
#define  NF_ND_CA0_col_addr0(data)                                               (0x000000FF&(data))
#define  NF_ND_CA0_get_col_addr0(data)                                           (0x000000FF&(data))

#define  NF_ND_CMD                                                               0x18010010
#define  NF_ND_CMD_reg_addr                                                      "0xB8010010"
#define  NF_ND_CMD_reg                                                           0xB8010010
#define  NF_ND_CMD_inst_addr                                                     "0x0004"
#define  set_NF_ND_CMD_reg(data)                                                 (*((volatile unsigned int*)NF_ND_CMD_reg)=data)
#define  get_NF_ND_CMD_reg                                                       (*((volatile unsigned int*)NF_ND_CMD_reg))
#define  NF_ND_CMD_cmd_shift                                                     (0)
#define  NF_ND_CMD_cmd_mask                                                      (0x000000FF)
#define  NF_ND_CMD_cmd(data)                                                     (0x000000FF&(data))
#define  NF_ND_CMD_get_cmd(data)                                                 (0x000000FF&(data))

#define  NF_ND_DAT                                                               0x18010014
#define  NF_ND_DAT_reg_addr                                                      "0xB8010014"
#define  NF_ND_DAT_reg                                                           0xB8010014
#define  NF_ND_DAT_inst_addr                                                     "0x0005"
#define  set_NF_ND_DAT_reg(data)                                                 (*((volatile unsigned int*)NF_ND_DAT_reg)=data)
#define  get_NF_ND_DAT_reg                                                       (*((volatile unsigned int*)NF_ND_DAT_reg))
#define  NF_ND_DAT_dat_shift                                                     (0)
#define  NF_ND_DAT_dat_mask                                                      (0x000000FF)
#define  NF_ND_DAT_dat(data)                                                     (0x000000FF&(data))
#define  NF_ND_DAT_get_dat(data)                                                 (0x000000FF&(data))

#define  NF_ND_CTL                                                               0x18010018
#define  NF_ND_CTL_reg_addr                                                      "0xB8010018"
#define  NF_ND_CTL_reg                                                           0xB8010018
#define  NF_ND_CTL_inst_addr                                                     "0x0006"
#define  set_NF_ND_CTL_reg(data)                                                 (*((volatile unsigned int*)NF_ND_CTL_reg)=data)
#define  get_NF_ND_CTL_reg                                                       (*((volatile unsigned int*)NF_ND_CTL_reg))
#define  NF_ND_CTL_xfer_shift                                                    (7)
#define  NF_ND_CTL_ready_busy_shift                                              (6)
#define  NF_ND_CTL_ecc_tran_shift                                                (5)
#define  NF_ND_CTL_ecc_enable_shift                                              (3)
#define  NF_ND_CTL_tran_mode_shift                                               (0)
#define  NF_ND_CTL_xfer_mask                                                     (0x00000080)
#define  NF_ND_CTL_ready_busy_mask                                               (0x00000040)
#define  NF_ND_CTL_ecc_tran_mask                                                 (0x00000020)
#define  NF_ND_CTL_ecc_enable_mask                                               (0x00000008)
#define  NF_ND_CTL_tran_mode_mask                                                (0x00000007)
#define  NF_ND_CTL_xfer(data)                                                    (0x00000080&((data)<<7))
#define  NF_ND_CTL_ready_busy(data)                                              (0x00000040&((data)<<6))
#define  NF_ND_CTL_ecc_tran(data)                                                (0x00000020&((data)<<5))
#define  NF_ND_CTL_ecc_enable(data)                                              (0x00000008&((data)<<3))
#define  NF_ND_CTL_tran_mode(data)                                               (0x00000007&(data))
#define  NF_ND_CTL_get_xfer(data)                                                ((0x00000080&(data))>>7)
#define  NF_ND_CTL_get_ready_busy(data)                                          ((0x00000040&(data))>>6)
#define  NF_ND_CTL_get_ecc_tran(data)                                            ((0x00000020&(data))>>5)
#define  NF_ND_CTL_get_ecc_enable(data)                                          ((0x00000008&(data))>>3)
#define  NF_ND_CTL_get_tran_mode(data)                                           (0x00000007&(data))

#define  NF_BLANK_ZERO_NUM                                                       0x1801001C
#define  NF_BLANK_ZERO_NUM_reg_addr                                              "0xB801001C"
#define  NF_BLANK_ZERO_NUM_reg                                                   0xB801001C
#define  NF_BLANK_ZERO_NUM_inst_addr                                             "0x0007"
#define  set_NF_BLANK_ZERO_NUM_reg(data)                                         (*((volatile unsigned int*)NF_BLANK_ZERO_NUM_reg)=data)
#define  get_NF_BLANK_ZERO_NUM_reg                                               (*((volatile unsigned int*)NF_BLANK_ZERO_NUM_reg))
#define  NF_BLANK_ZERO_NUM_blank_zero_num_shift                                  (0)
#define  NF_BLANK_ZERO_NUM_blank_zero_num_mask                                   (0x0000007F)
#define  NF_BLANK_ZERO_NUM_blank_zero_num(data)                                  (0x0000007F&(data))
#define  NF_BLANK_ZERO_NUM_get_blank_zero_num(data)                              (0x0000007F&(data))

#define  NF_CMD3                                                                 0x18010028
#define  NF_CMD3_reg_addr                                                        "0xB8010028"
#define  NF_CMD3_reg                                                             0xB8010028
#define  NF_CMD3_inst_addr                                                       "0x0008"
#define  set_NF_CMD3_reg(data)                                                   (*((volatile unsigned int*)NF_CMD3_reg)=data)
#define  get_NF_CMD3_reg                                                         (*((volatile unsigned int*)NF_CMD3_reg))
#define  NF_CMD3_cmd3_shift                                                      (0)
#define  NF_CMD3_cmd3_mask                                                       (0x000000FF)
#define  NF_CMD3_cmd3(data)                                                      (0x000000FF&(data))
#define  NF_CMD3_get_cmd3(data)                                                  (0x000000FF&(data))

#define  NF_ND_PA3                                                               0x1801002C
#define  NF_ND_PA3_reg_addr                                                      "0xB801002C"
#define  NF_ND_PA3_reg                                                           0xB801002C
#define  NF_ND_PA3_inst_addr                                                     "0x0009"
#define  set_NF_ND_PA3_reg(data)                                                 (*((volatile unsigned int*)NF_ND_PA3_reg)=data)
#define  get_NF_ND_PA3_reg                                                       (*((volatile unsigned int*)NF_ND_PA3_reg))
#define  NF_ND_PA3_page_addr3_shift                                              (5)
#define  NF_ND_PA3_page_addr3_mask                                               (0x000000E0)
#define  NF_ND_PA3_page_addr3(data)                                              (0x000000E0&((data)<<5))
#define  NF_ND_PA3_get_page_addr3(data)                                          ((0x000000E0&(data))>>5)

#define  NF_POLL_FSTS                                                            0x18010030
#define  NF_POLL_FSTS_reg_addr                                                   "0xB8010030"
#define  NF_POLL_FSTS_reg                                                        0xB8010030
#define  NF_POLL_FSTS_inst_addr                                                  "0x000A"
#define  set_NF_POLL_FSTS_reg(data)                                              (*((volatile unsigned int*)NF_POLL_FSTS_reg)=data)
#define  get_NF_POLL_FSTS_reg                                                    (*((volatile unsigned int*)NF_POLL_FSTS_reg))
#define  NF_POLL_FSTS_bit_sel_shift                                              (1)
#define  NF_POLL_FSTS_trig_poll_shift                                            (0)
#define  NF_POLL_FSTS_bit_sel_mask                                               (0x0000000E)
#define  NF_POLL_FSTS_trig_poll_mask                                             (0x00000001)
#define  NF_POLL_FSTS_bit_sel(data)                                              (0x0000000E&((data)<<1))
#define  NF_POLL_FSTS_trig_poll(data)                                            (0x00000001&(data))
#define  NF_POLL_FSTS_get_bit_sel(data)                                          ((0x0000000E&(data))>>1)
#define  NF_POLL_FSTS_get_trig_poll(data)                                        (0x00000001&(data))

#define  NF_BLANK_CHK                                                            0x18010034
#define  NF_BLANK_CHK_reg_addr                                                   "0xB8010034"
#define  NF_BLANK_CHK_reg                                                        0xB8010034
#define  NF_BLANK_CHK_inst_addr                                                  "0x000B"
#define  set_NF_BLANK_CHK_reg(data)                                              (*((volatile unsigned int*)NF_BLANK_CHK_reg)=data)
#define  get_NF_BLANK_CHK_reg                                                    (*((volatile unsigned int*)NF_BLANK_CHK_reg))
#define  NF_BLANK_CHK_blank_zero_over_shift                                      (3)
#define  NF_BLANK_CHK_read_ecc_xnor_ena_shift                                    (2)
#define  NF_BLANK_CHK_blank_all_one_shift                                        (1)
#define  NF_BLANK_CHK_blank_ena_shift                                            (0)
#define  NF_BLANK_CHK_blank_zero_over_mask                                       (0x00000008)
#define  NF_BLANK_CHK_read_ecc_xnor_ena_mask                                     (0x00000004)
#define  NF_BLANK_CHK_blank_all_one_mask                                         (0x00000002)
#define  NF_BLANK_CHK_blank_ena_mask                                             (0x00000001)
#define  NF_BLANK_CHK_blank_zero_over(data)                                      (0x00000008&((data)<<3))
#define  NF_BLANK_CHK_read_ecc_xnor_ena(data)                                    (0x00000004&((data)<<2))
#define  NF_BLANK_CHK_blank_all_one(data)                                        (0x00000002&((data)<<1))
#define  NF_BLANK_CHK_blank_ena(data)                                            (0x00000001&(data))
#define  NF_BLANK_CHK_get_blank_zero_over(data)                                  ((0x00000008&(data))>>3)
#define  NF_BLANK_CHK_get_read_ecc_xnor_ena(data)                                ((0x00000004&(data))>>2)
#define  NF_BLANK_CHK_get_blank_all_one(data)                                    ((0x00000002&(data))>>1)
#define  NF_BLANK_CHK_get_blank_ena(data)                                        (0x00000001&(data))

#define  NF_ND_ECC                                                               0x18010038
#define  NF_ND_ECC_reg_addr                                                      "0xB8010038"
#define  NF_ND_ECC_reg                                                           0xB8010038
#define  NF_ND_ECC_inst_addr                                                     "0x000C"
#define  set_NF_ND_ECC_reg(data)                                                 (*((volatile unsigned int*)NF_ND_ECC_reg)=data)
#define  get_NF_ND_ECC_reg                                                       (*((volatile unsigned int*)NF_ND_ECC_reg))
#define  NF_ND_ECC_ecc_not_clr_shift                                             (3)
#define  NF_ND_ECC_ecc_err_shift                                                 (2)
#define  NF_ND_ECC_ecc_not_clr_mask                                              (0x00000008)
#define  NF_ND_ECC_ecc_err_mask                                                  (0x00000004)
#define  NF_ND_ECC_ecc_not_clr(data)                                             (0x00000008&((data)<<3))
#define  NF_ND_ECC_ecc_err(data)                                                 (0x00000004&((data)<<2))
#define  NF_ND_ECC_get_ecc_not_clr(data)                                         ((0x00000008&(data))>>3)
#define  NF_ND_ECC_get_ecc_err(data)                                             ((0x00000004&(data))>>2)

#define  NF_ND_CA1                                                               0x1801003C
#define  NF_ND_CA1_reg_addr                                                      "0xB801003C"
#define  NF_ND_CA1_reg                                                           0xB801003C
#define  NF_ND_CA1_inst_addr                                                     "0x000D"
#define  set_NF_ND_CA1_reg(data)                                                 (*((volatile unsigned int*)NF_ND_CA1_reg)=data)
#define  get_NF_ND_CA1_reg                                                       (*((volatile unsigned int*)NF_ND_CA1_reg))
#define  NF_ND_CA1_col_addr1_shift                                               (0)
#define  NF_ND_CA1_col_addr1_mask                                                (0x000000FF)
#define  NF_ND_CA1_col_addr1(data)                                               (0x000000FF&(data))
#define  NF_ND_CA1_get_col_addr1(data)                                           (0x000000FF&(data))

#define  NF_DATA_TL0                                                             0x18010100
#define  NF_DATA_TL0_reg_addr                                                    "0xB8010100"
#define  NF_DATA_TL0_reg                                                         0xB8010100
#define  NF_DATA_TL0_inst_addr                                                   "0x000E"
#define  set_NF_DATA_TL0_reg(data)                                               (*((volatile unsigned int*)NF_DATA_TL0_reg)=data)
#define  get_NF_DATA_TL0_reg                                                     (*((volatile unsigned int*)NF_DATA_TL0_reg))
#define  NF_DATA_TL0_length0_shift                                               (0)
#define  NF_DATA_TL0_length0_mask                                                (0x000000FF)
#define  NF_DATA_TL0_length0(data)                                               (0x000000FF&(data))
#define  NF_DATA_TL0_get_length0(data)                                           (0x000000FF&(data))

#define  NF_DATA_TL1                                                             0x18010104
#define  NF_DATA_TL1_reg_addr                                                    "0xB8010104"
#define  NF_DATA_TL1_reg                                                         0xB8010104
#define  NF_DATA_TL1_inst_addr                                                   "0x000F"
#define  set_NF_DATA_TL1_reg(data)                                               (*((volatile unsigned int*)NF_DATA_TL1_reg)=data)
#define  get_NF_DATA_TL1_reg                                                     (*((volatile unsigned int*)NF_DATA_TL1_reg))
#define  NF_DATA_TL1_access_mode_shift                                           (7)
#define  NF_DATA_TL1_length1_shift                                               (0)
#define  NF_DATA_TL1_access_mode_mask                                            (0x00000080)
#define  NF_DATA_TL1_length1_mask                                                (0x0000003F)
#define  NF_DATA_TL1_access_mode(data)                                           (0x00000080&((data)<<7))
#define  NF_DATA_TL1_length1(data)                                               (0x0000003F&(data))
#define  NF_DATA_TL1_get_access_mode(data)                                       ((0x00000080&(data))>>7)
#define  NF_DATA_TL1_get_length1(data)                                           (0x0000003F&(data))

#define  NF_DMA1_CTL                                                             0x1801010C
#define  NF_DMA1_CTL_reg_addr                                                    "0xB801010C"
#define  NF_DMA1_CTL_reg                                                         0xB801010C
#define  NF_DMA1_CTL_inst_addr                                                   "0x0010"
#define  set_NF_DMA1_CTL_reg(data)                                               (*((volatile unsigned int*)NF_DMA1_CTL_reg)=data)
#define  get_NF_DMA1_CTL_reg                                                     (*((volatile unsigned int*)NF_DMA1_CTL_reg))
#define  NF_DMA1_CTL_eot_gen_shift                                               (3)
#define  NF_DMA1_CTL_dma_max_pkt_shift                                           (2)
#define  NF_DMA1_CTL_spec_pkt_shift                                              (1)
#define  NF_DMA1_CTL_eot_gen_mask                                                (0x00000008)
#define  NF_DMA1_CTL_dma_max_pkt_mask                                            (0x00000004)
#define  NF_DMA1_CTL_spec_pkt_mask                                               (0x00000002)
#define  NF_DMA1_CTL_eot_gen(data)                                               (0x00000008&((data)<<3))
#define  NF_DMA1_CTL_dma_max_pkt(data)                                           (0x00000004&((data)<<2))
#define  NF_DMA1_CTL_spec_pkt(data)                                              (0x00000002&((data)<<1))
#define  NF_DMA1_CTL_get_eot_gen(data)                                           ((0x00000008&(data))>>3)
#define  NF_DMA1_CTL_get_dma_max_pkt(data)                                       ((0x00000004&(data))>>2)
#define  NF_DMA1_CTL_get_spec_pkt(data)                                          ((0x00000002&(data))>>1)

#define  NF_PP_CTL0                                                              0x18010110
#define  NF_PP_CTL0_reg_addr                                                     "0xB8010110"
#define  NF_PP_CTL0_reg                                                          0xB8010110
#define  NF_PP_CTL0_inst_addr                                                    "0x0011"
#define  set_NF_PP_CTL0_reg(data)                                                (*((volatile unsigned int*)NF_PP_CTL0_reg)=data)
#define  get_NF_PP_CTL0_reg                                                      (*((volatile unsigned int*)NF_PP_CTL0_reg))
#define  NF_PP_CTL0_pp_start_addr_shift                                          (4)
#define  NF_PP_CTL0_pp_busy_shift                                                (2)
#define  NF_PP_CTL0_pp_reset_shift                                               (1)
#define  NF_PP_CTL0_pp_enable_shift                                              (0)
#define  NF_PP_CTL0_pp_start_addr_mask                                           (0x000000F0)
#define  NF_PP_CTL0_pp_busy_mask                                                 (0x00000004)
#define  NF_PP_CTL0_pp_reset_mask                                                (0x00000002)
#define  NF_PP_CTL0_pp_enable_mask                                               (0x00000001)
#define  NF_PP_CTL0_pp_start_addr(data)                                          (0x000000F0&((data)<<4))
#define  NF_PP_CTL0_pp_busy(data)                                                (0x00000004&((data)<<2))
#define  NF_PP_CTL0_pp_reset(data)                                               (0x00000002&((data)<<1))
#define  NF_PP_CTL0_pp_enable(data)                                              (0x00000001&(data))
#define  NF_PP_CTL0_get_pp_start_addr(data)                                      ((0x000000F0&(data))>>4)
#define  NF_PP_CTL0_get_pp_busy(data)                                            ((0x00000004&(data))>>2)
#define  NF_PP_CTL0_get_pp_reset(data)                                           ((0x00000002&(data))>>1)
#define  NF_PP_CTL0_get_pp_enable(data)                                          (0x00000001&(data))

#define  NF_ECC_SEL                                                              0x18010128
#define  NF_ECC_SEL_reg_addr                                                     "0xB8010128"
#define  NF_ECC_SEL_reg                                                          0xB8010128
#define  NF_ECC_SEL_inst_addr                                                    "0x0012"
#define  set_NF_ECC_SEL_reg(data)                                                (*((volatile unsigned int*)NF_ECC_SEL_reg)=data)
#define  get_NF_ECC_SEL_reg                                                      (*((volatile unsigned int*)NF_ECC_SEL_reg))
#define  NF_ECC_SEL_ecc_bch_72b_ena_shift                                        (3)
#define  NF_ECC_SEL_ecc_bch_40b_ena_shift                                        (2)
#define  NF_ECC_SEL_ecc_bch_24b_ena_shift                                        (1)
#define  NF_ECC_SEL_ecc_bch_12b_ena_shift                                        (0)
#define  NF_ECC_SEL_ecc_bch_72b_ena_mask                                         (0x00000008)
#define  NF_ECC_SEL_ecc_bch_40b_ena_mask                                         (0x00000004)
#define  NF_ECC_SEL_ecc_bch_24b_ena_mask                                         (0x00000002)
#define  NF_ECC_SEL_ecc_bch_12b_ena_mask                                         (0x00000001)
#define  NF_ECC_SEL_ecc_bch_72b_ena(data)                                        (0x00000008&((data)<<3))
#define  NF_ECC_SEL_ecc_bch_40b_ena(data)                                        (0x00000004&((data)<<2))
#define  NF_ECC_SEL_ecc_bch_24b_ena(data)                                        (0x00000002&((data)<<1))
#define  NF_ECC_SEL_ecc_bch_12b_ena(data)                                        (0x00000001&(data))
#define  NF_ECC_SEL_get_ecc_bch_72b_ena(data)                                    ((0x00000008&(data))>>3)
#define  NF_ECC_SEL_get_ecc_bch_40b_ena(data)                                    ((0x00000004&(data))>>2)
#define  NF_ECC_SEL_get_ecc_bch_24b_ena(data)                                    ((0x00000002&(data))>>1)
#define  NF_ECC_SEL_get_ecc_bch_12b_ena(data)                                    (0x00000001&(data))

#define  NF_PP_CTL1                                                              0x1801012C
#define  NF_PP_CTL1_reg_addr                                                     "0xB801012C"
#define  NF_PP_CTL1_reg                                                          0xB801012C
#define  NF_PP_CTL1_inst_addr                                                    "0x0013"
#define  set_NF_PP_CTL1_reg(data)                                                (*((volatile unsigned int*)NF_PP_CTL1_reg)=data)
#define  get_NF_PP_CTL1_reg                                                      (*((volatile unsigned int*)NF_PP_CTL1_reg))
#define  NF_PP_CTL1_pp_start_addr_shift                                          (0)
#define  NF_PP_CTL1_pp_start_addr_mask                                           (0x000000FF)
#define  NF_PP_CTL1_pp_start_addr(data)                                          (0x000000FF&(data))
#define  NF_PP_CTL1_get_pp_start_addr(data)                                      (0x000000FF&(data))

#define  NF_PD                                                                   0x18010130
#define  NF_PD_reg_addr                                                          "0xB8010130"
#define  NF_PD_reg                                                               0xB8010130
#define  NF_PD_inst_addr                                                         "0x0014"
#define  set_NF_PD_reg(data)                                                     (*((volatile unsigned int*)NF_PD_reg)=data)
#define  get_NF_PD_reg                                                           (*((volatile unsigned int*)NF_PD_reg))
#define  NF_PD_ce_hw_sw_mode_shift                                               (5)
#define  NF_PD_pd_shift                                                          (0)
#define  NF_PD_ce_hw_sw_mode_mask                                                (0x00000020)
#define  NF_PD_pd_mask                                                           (0x0000001F)
#define  NF_PD_ce_hw_sw_mode(data)                                               (0x00000020&((data)<<5))
#define  NF_PD_pd(data)                                                          (0x0000001F&(data))
#define  NF_PD_get_ce_hw_sw_mode(data)                                           ((0x00000020&(data))>>5)
#define  NF_PD_get_pd(data)                                                      (0x0000001F&(data))

#define  NF_NF_LOW_PWR                                                           0x1801013C
#define  NF_NF_LOW_PWR_reg_addr                                                  "0xB801013C"
#define  NF_NF_LOW_PWR_reg                                                       0xB801013C
#define  NF_NF_LOW_PWR_inst_addr                                                 "0x0015"
#define  set_NF_NF_LOW_PWR_reg(data)                                             (*((volatile unsigned int*)NF_NF_LOW_PWR_reg)=data)
#define  get_NF_NF_LOW_PWR_reg                                                   (*((volatile unsigned int*)NF_NF_LOW_PWR_reg))
#define  NF_NF_LOW_PWR_pp_lp_mode_shift                                          (7)
#define  NF_NF_LOW_PWR_pp_lp_ena_shift                                           (6)
#define  NF_NF_LOW_PWR_ecc_clk_gate_ena_shift                                    (5)
#define  NF_NF_LOW_PWR_ip_clk_gate_ena_shift                                     (4)
#define  NF_NF_LOW_PWR_dma_clk_gate_ena_shift                                    (3)
#define  NF_NF_LOW_PWR_pp_sram_rdy_num_shift                                     (0)
#define  NF_NF_LOW_PWR_pp_lp_mode_mask                                           (0x00000080)
#define  NF_NF_LOW_PWR_pp_lp_ena_mask                                            (0x00000040)
#define  NF_NF_LOW_PWR_ecc_clk_gate_ena_mask                                     (0x00000020)
#define  NF_NF_LOW_PWR_ip_clk_gate_ena_mask                                      (0x00000010)
#define  NF_NF_LOW_PWR_dma_clk_gate_ena_mask                                     (0x00000008)
#define  NF_NF_LOW_PWR_pp_sram_rdy_num_mask                                      (0x00000007)
#define  NF_NF_LOW_PWR_pp_lp_mode(data)                                          (0x00000080&((data)<<7))
#define  NF_NF_LOW_PWR_pp_lp_ena(data)                                           (0x00000040&((data)<<6))
#define  NF_NF_LOW_PWR_ecc_clk_gate_ena(data)                                    (0x00000020&((data)<<5))
#define  NF_NF_LOW_PWR_ip_clk_gate_ena(data)                                     (0x00000010&((data)<<4))
#define  NF_NF_LOW_PWR_dma_clk_gate_ena(data)                                    (0x00000008&((data)<<3))
#define  NF_NF_LOW_PWR_pp_sram_rdy_num(data)                                     (0x00000007&(data))
#define  NF_NF_LOW_PWR_get_pp_lp_mode(data)                                      ((0x00000080&(data))>>7)
#define  NF_NF_LOW_PWR_get_pp_lp_ena(data)                                       ((0x00000040&(data))>>6)
#define  NF_NF_LOW_PWR_get_ecc_clk_gate_ena(data)                                ((0x00000020&(data))>>5)
#define  NF_NF_LOW_PWR_get_ip_clk_gate_ena(data)                                 ((0x00000010&(data))>>4)
#define  NF_NF_LOW_PWR_get_dma_clk_gate_ena(data)                                ((0x00000008&(data))>>3)
#define  NF_NF_LOW_PWR_get_pp_sram_rdy_num(data)                                 (0x00000007&(data))

#define  NF_DUMMY_NF1                                                            0x18010158
#define  NF_DUMMY_NF1_reg_addr                                                   "0xB8010158"
#define  NF_DUMMY_NF1_reg                                                        0xB8010158
#define  NF_DUMMY_NF1_inst_addr                                                  "0x0016"
#define  set_NF_DUMMY_NF1_reg(data)                                              (*((volatile unsigned int*)NF_DUMMY_NF1_reg)=data)
#define  get_NF_DUMMY_NF1_reg                                                    (*((volatile unsigned int*)NF_DUMMY_NF1_reg))
#define  NF_DUMMY_NF1_dmy1_shift                                                 (0)
#define  NF_DUMMY_NF1_dmy1_mask                                                  (0x000000FF)
#define  NF_DUMMY_NF1_dmy1(data)                                                 (0x000000FF&(data))
#define  NF_DUMMY_NF1_get_dmy1(data)                                             (0x000000FF&(data))

#define  NF_DUMMY_NF2                                                            0x1801015C
#define  NF_DUMMY_NF2_reg_addr                                                   "0xB801015C"
#define  NF_DUMMY_NF2_reg                                                        0xB801015C
#define  NF_DUMMY_NF2_inst_addr                                                  "0x0017"
#define  set_NF_DUMMY_NF2_reg(data)                                              (*((volatile unsigned int*)NF_DUMMY_NF2_reg)=data)
#define  get_NF_DUMMY_NF2_reg                                                    (*((volatile unsigned int*)NF_DUMMY_NF2_reg))
#define  NF_DUMMY_NF2_dmy2_shift                                                 (0)
#define  NF_DUMMY_NF2_dmy2_mask                                                  (0x000000FF)
#define  NF_DUMMY_NF2_dmy2(data)                                                 (0x000000FF&(data))
#define  NF_DUMMY_NF2_get_dmy2(data)                                             (0x000000FF&(data))

#define  NF_DUMMY_NF3                                                            0x18010160
#define  NF_DUMMY_NF3_reg_addr                                                   "0xB8010160"
#define  NF_DUMMY_NF3_reg                                                        0xB8010160
#define  NF_DUMMY_NF3_inst_addr                                                  "0x0018"
#define  set_NF_DUMMY_NF3_reg(data)                                              (*((volatile unsigned int*)NF_DUMMY_NF3_reg)=data)
#define  get_NF_DUMMY_NF3_reg                                                    (*((volatile unsigned int*)NF_DUMMY_NF3_reg))
#define  NF_DUMMY_NF3_dmy3_shift                                                 (0)
#define  NF_DUMMY_NF3_dmy3_mask                                                  (0x000000FF)
#define  NF_DUMMY_NF3_dmy3(data)                                                 (0x000000FF&(data))
#define  NF_DUMMY_NF3_get_dmy3(data)                                             (0x000000FF&(data))

#define  NF_DUMMY_NF4                                                            0x18010164
#define  NF_DUMMY_NF4_reg_addr                                                   "0xB8010164"
#define  NF_DUMMY_NF4_reg                                                        0xB8010164
#define  NF_DUMMY_NF4_inst_addr                                                  "0x0019"
#define  set_NF_DUMMY_NF4_reg(data)                                              (*((volatile unsigned int*)NF_DUMMY_NF4_reg)=data)
#define  get_NF_DUMMY_NF4_reg                                                    (*((volatile unsigned int*)NF_DUMMY_NF4_reg))
#define  NF_DUMMY_NF4_dmy4_shift                                                 (0)
#define  NF_DUMMY_NF4_dmy4_mask                                                  (0x000000FF)
#define  NF_DUMMY_NF4_dmy4(data)                                                 (0x000000FF&(data))
#define  NF_DUMMY_NF4_get_dmy4(data)                                             (0x000000FF&(data))

#define  NF_ND_SECU_PA0                                                          0x18010180
#define  NF_ND_SECU_PA0_reg_addr                                                 "0xB8010180"
#define  NF_ND_SECU_PA0_reg                                                      0xB8010180
#define  NF_ND_SECU_PA0_inst_addr                                                "0x001A"
#define  set_NF_ND_SECU_PA0_reg(data)                                            (*((volatile unsigned int*)NF_ND_SECU_PA0_reg)=data)
#define  get_NF_ND_SECU_PA0_reg                                                  (*((volatile unsigned int*)NF_ND_SECU_PA0_reg))
#define  NF_ND_SECU_PA0_page_addr0_shift                                         (0)
#define  NF_ND_SECU_PA0_page_addr0_mask                                          (0x000000FF)
#define  NF_ND_SECU_PA0_page_addr0(data)                                         (0x000000FF&(data))
#define  NF_ND_SECU_PA0_get_page_addr0(data)                                     (0x000000FF&(data))

#define  NF_ND_SECU_PA1                                                          0x18010184
#define  NF_ND_SECU_PA1_reg_addr                                                 "0xB8010184"
#define  NF_ND_SECU_PA1_reg                                                      0xB8010184
#define  NF_ND_SECU_PA1_inst_addr                                                "0x001B"
#define  set_NF_ND_SECU_PA1_reg(data)                                            (*((volatile unsigned int*)NF_ND_SECU_PA1_reg)=data)
#define  get_NF_ND_SECU_PA1_reg                                                  (*((volatile unsigned int*)NF_ND_SECU_PA1_reg))
#define  NF_ND_SECU_PA1_page_addr1_shift                                         (0)
#define  NF_ND_SECU_PA1_page_addr1_mask                                          (0x000000FF)
#define  NF_ND_SECU_PA1_page_addr1(data)                                         (0x000000FF&(data))
#define  NF_ND_SECU_PA1_get_page_addr1(data)                                     (0x000000FF&(data))

#define  NF_ND_SECU_PA2                                                          0x18010188
#define  NF_ND_SECU_PA2_reg_addr                                                 "0xB8010188"
#define  NF_ND_SECU_PA2_reg                                                      0xB8010188
#define  NF_ND_SECU_PA2_inst_addr                                                "0x001C"
#define  set_NF_ND_SECU_PA2_reg(data)                                            (*((volatile unsigned int*)NF_ND_SECU_PA2_reg)=data)
#define  get_NF_ND_SECU_PA2_reg                                                  (*((volatile unsigned int*)NF_ND_SECU_PA2_reg))
#define  NF_ND_SECU_PA2_addr_mode_shift                                          (5)
#define  NF_ND_SECU_PA2_page_addr2_shift                                         (0)
#define  NF_ND_SECU_PA2_addr_mode_mask                                           (0x000000E0)
#define  NF_ND_SECU_PA2_page_addr2_mask                                          (0x0000001F)
#define  NF_ND_SECU_PA2_addr_mode(data)                                          (0x000000E0&((data)<<5))
#define  NF_ND_SECU_PA2_page_addr2(data)                                         (0x0000001F&(data))
#define  NF_ND_SECU_PA2_get_addr_mode(data)                                      ((0x000000E0&(data))>>5)
#define  NF_ND_SECU_PA2_get_page_addr2(data)                                     (0x0000001F&(data))

#define  NF_ND_SECU_PA3                                                          0x1801018C
#define  NF_ND_SECU_PA3_reg_addr                                                 "0xB801018C"
#define  NF_ND_SECU_PA3_reg                                                      0xB801018C
#define  NF_ND_SECU_PA3_inst_addr                                                "0x001D"
#define  set_NF_ND_SECU_PA3_reg(data)                                            (*((volatile unsigned int*)NF_ND_SECU_PA3_reg)=data)
#define  get_NF_ND_SECU_PA3_reg                                                  (*((volatile unsigned int*)NF_ND_SECU_PA3_reg))
#define  NF_ND_SECU_PA3_page_addr3_shift                                         (5)
#define  NF_ND_SECU_PA3_page_addr3_mask                                          (0x000000E0)
#define  NF_ND_SECU_PA3_page_addr3(data)                                         (0x000000E0&((data)<<5))
#define  NF_ND_SECU_PA3_get_page_addr3(data)                                     ((0x000000E0&(data))>>5)

#define  NF_ND_SECU_CTL                                                          0x18010190
#define  NF_ND_SECU_CTL_reg_addr                                                 "0xB8010190"
#define  NF_ND_SECU_CTL_reg                                                      0xB8010190
#define  NF_ND_SECU_CTL_inst_addr                                                "0x001E"
#define  set_NF_ND_SECU_CTL_reg(data)                                            (*((volatile unsigned int*)NF_ND_SECU_CTL_reg)=data)
#define  get_NF_ND_SECU_CTL_reg                                                  (*((volatile unsigned int*)NF_ND_SECU_CTL_reg))
#define  NF_ND_SECU_CTL_xfer_shift                                               (7)
#define  NF_ND_SECU_CTL_ready_busy_shift                                         (6)
#define  NF_ND_SECU_CTL_ecc_tran_shift                                           (5)
#define  NF_ND_SECU_CTL_ecc_enable_shift                                         (3)
#define  NF_ND_SECU_CTL_tran_mode_shift                                          (0)
#define  NF_ND_SECU_CTL_xfer_mask                                                (0x00000080)
#define  NF_ND_SECU_CTL_ready_busy_mask                                          (0x00000040)
#define  NF_ND_SECU_CTL_ecc_tran_mask                                            (0x00000020)
#define  NF_ND_SECU_CTL_ecc_enable_mask                                          (0x00000008)
#define  NF_ND_SECU_CTL_tran_mode_mask                                           (0x00000007)
#define  NF_ND_SECU_CTL_xfer(data)                                               (0x00000080&((data)<<7))
#define  NF_ND_SECU_CTL_ready_busy(data)                                         (0x00000040&((data)<<6))
#define  NF_ND_SECU_CTL_ecc_tran(data)                                           (0x00000020&((data)<<5))
#define  NF_ND_SECU_CTL_ecc_enable(data)                                         (0x00000008&((data)<<3))
#define  NF_ND_SECU_CTL_tran_mode(data)                                          (0x00000007&(data))
#define  NF_ND_SECU_CTL_get_xfer(data)                                           ((0x00000080&(data))>>7)
#define  NF_ND_SECU_CTL_get_ready_busy(data)                                     ((0x00000040&(data))>>6)
#define  NF_ND_SECU_CTL_get_ecc_tran(data)                                       ((0x00000020&(data))>>5)
#define  NF_ND_SECU_CTL_get_ecc_enable(data)                                     ((0x00000008&(data))>>3)
#define  NF_ND_SECU_CTL_get_tran_mode(data)                                      (0x00000007&(data))

#define  NF_SECU_AUTO_TRIG                                                       0x18010194
#define  NF_SECU_AUTO_TRIG_reg_addr                                              "0xB8010194"
#define  NF_SECU_AUTO_TRIG_reg                                                   0xB8010194
#define  NF_SECU_AUTO_TRIG_inst_addr                                             "0x001F"
#define  set_NF_SECU_AUTO_TRIG_reg(data)                                         (*((volatile unsigned int*)NF_SECU_AUTO_TRIG_reg)=data)
#define  get_NF_SECU_AUTO_TRIG_reg                                               (*((volatile unsigned int*)NF_SECU_AUTO_TRIG_reg))
#define  NF_SECU_AUTO_TRIG_auto_trig_shift                                       (7)
#define  NF_SECU_AUTO_TRIG_addr_fbd_shift                                        (6)
#define  NF_SECU_AUTO_TRIG_pp_empty_shift                                        (5)
#define  NF_SECU_AUTO_TRIG_spec_auto_case_shift                                  (3)
#define  NF_SECU_AUTO_TRIG_auto_case_shift                                       (0)
#define  NF_SECU_AUTO_TRIG_auto_trig_mask                                        (0x00000080)
#define  NF_SECU_AUTO_TRIG_addr_fbd_mask                                         (0x00000040)
#define  NF_SECU_AUTO_TRIG_pp_empty_mask                                         (0x00000020)
#define  NF_SECU_AUTO_TRIG_spec_auto_case_mask                                   (0x00000018)
#define  NF_SECU_AUTO_TRIG_auto_case_mask                                        (0x00000007)
#define  NF_SECU_AUTO_TRIG_auto_trig(data)                                       (0x00000080&((data)<<7))
#define  NF_SECU_AUTO_TRIG_addr_fbd(data)                                        (0x00000040&((data)<<6))
#define  NF_SECU_AUTO_TRIG_pp_empty(data)                                        (0x00000020&((data)<<5))
#define  NF_SECU_AUTO_TRIG_spec_auto_case(data)                                  (0x00000018&((data)<<3))
#define  NF_SECU_AUTO_TRIG_auto_case(data)                                       (0x00000007&(data))
#define  NF_SECU_AUTO_TRIG_get_auto_trig(data)                                   ((0x00000080&(data))>>7)
#define  NF_SECU_AUTO_TRIG_get_addr_fbd(data)                                    ((0x00000040&(data))>>6)
#define  NF_SECU_AUTO_TRIG_get_pp_empty(data)                                    ((0x00000020&(data))>>5)
#define  NF_SECU_AUTO_TRIG_get_spec_auto_case(data)                              ((0x00000018&(data))>>3)
#define  NF_SECU_AUTO_TRIG_get_auto_case(data)                                   (0x00000007&(data))

#define  NF_ND_SECU_BLOCK_MODE                                                   0x18010198
#define  NF_ND_SECU_BLOCK_MODE_reg_addr                                          "0xB8010198"
#define  NF_ND_SECU_BLOCK_MODE_reg                                               0xB8010198
#define  NF_ND_SECU_BLOCK_MODE_inst_addr                                         "0x0020"
#define  set_NF_ND_SECU_BLOCK_MODE_reg(data)                                     (*((volatile unsigned int*)NF_ND_SECU_BLOCK_MODE_reg)=data)
#define  get_NF_ND_SECU_BLOCK_MODE_reg                                           (*((volatile unsigned int*)NF_ND_SECU_BLOCK_MODE_reg))
#define  NF_ND_SECU_BLOCK_MODE_access_err_shift                                  (1)
#define  NF_ND_SECU_BLOCK_MODE_block_trig_shift                                  (0)
#define  NF_ND_SECU_BLOCK_MODE_access_err_mask                                   (0x00000002)
#define  NF_ND_SECU_BLOCK_MODE_block_trig_mask                                   (0x00000001)
#define  NF_ND_SECU_BLOCK_MODE_access_err(data)                                  (0x00000002&((data)<<1))
#define  NF_ND_SECU_BLOCK_MODE_block_trig(data)                                  (0x00000001&(data))
#define  NF_ND_SECU_BLOCK_MODE_get_access_err(data)                              ((0x00000002&(data))>>1)
#define  NF_ND_SECU_BLOCK_MODE_get_block_trig(data)                              (0x00000001&(data))

#define  NF_AUTO_TRIG                                                            0x18010200
#define  NF_AUTO_TRIG_reg_addr                                                   "0xB8010200"
#define  NF_AUTO_TRIG_reg                                                        0xB8010200
#define  NF_AUTO_TRIG_inst_addr                                                  "0x0021"
#define  set_NF_AUTO_TRIG_reg(data)                                              (*((volatile unsigned int*)NF_AUTO_TRIG_reg)=data)
#define  get_NF_AUTO_TRIG_reg                                                    (*((volatile unsigned int*)NF_AUTO_TRIG_reg))
#define  NF_AUTO_TRIG_auto_trig_shift                                            (7)
#define  NF_AUTO_TRIG_addr_fbd_shift                                             (6)
#define  NF_AUTO_TRIG_pp_empty_shift                                             (5)
#define  NF_AUTO_TRIG_spec_auto_case_shift                                       (3)
#define  NF_AUTO_TRIG_auto_case_shift                                            (0)
#define  NF_AUTO_TRIG_auto_trig_mask                                             (0x00000080)
#define  NF_AUTO_TRIG_addr_fbd_mask                                              (0x00000040)
#define  NF_AUTO_TRIG_pp_empty_mask                                              (0x00000020)
#define  NF_AUTO_TRIG_spec_auto_case_mask                                        (0x00000018)
#define  NF_AUTO_TRIG_auto_case_mask                                             (0x00000007)
#define  NF_AUTO_TRIG_auto_trig(data)                                            (0x00000080&((data)<<7))
#define  NF_AUTO_TRIG_addr_fbd(data)                                             (0x00000040&((data)<<6))
#define  NF_AUTO_TRIG_pp_empty(data)                                             (0x00000020&((data)<<5))
#define  NF_AUTO_TRIG_spec_auto_case(data)                                       (0x00000018&((data)<<3))
#define  NF_AUTO_TRIG_auto_case(data)                                            (0x00000007&(data))
#define  NF_AUTO_TRIG_get_auto_trig(data)                                        ((0x00000080&(data))>>7)
#define  NF_AUTO_TRIG_get_addr_fbd(data)                                         ((0x00000040&(data))>>6)
#define  NF_AUTO_TRIG_get_pp_empty(data)                                         ((0x00000020&(data))>>5)
#define  NF_AUTO_TRIG_get_spec_auto_case(data)                                   ((0x00000018&(data))>>3)
#define  NF_AUTO_TRIG_get_auto_case(data)                                        (0x00000007&(data))

#define  NF_RSECC_NUM                                                            0x18010204
#define  NF_RSECC_NUM_reg_addr                                                   "0xB8010204"
#define  NF_RSECC_NUM_reg                                                        0xB8010204
#define  NF_RSECC_NUM_inst_addr                                                  "0x0022"
#define  set_NF_RSECC_NUM_reg(data)                                              (*((volatile unsigned int*)NF_RSECC_NUM_reg)=data)
#define  get_NF_RSECC_NUM_reg                                                    (*((volatile unsigned int*)NF_RSECC_NUM_reg))
#define  NF_RSECC_NUM_ecc_num_shift                                              (0)
#define  NF_RSECC_NUM_ecc_num_mask                                               (0x0000007F)
#define  NF_RSECC_NUM_ecc_num(data)                                              (0x0000007F&(data))
#define  NF_RSECC_NUM_get_ecc_num(data)                                          (0x0000007F&(data))

#define  NF_RND_CMD1                                                             0x18010208
#define  NF_RND_CMD1_reg_addr                                                    "0xB8010208"
#define  NF_RND_CMD1_reg                                                         0xB8010208
#define  NF_RND_CMD1_inst_addr                                                   "0x0023"
#define  set_NF_RND_CMD1_reg(data)                                               (*((volatile unsigned int*)NF_RND_CMD1_reg)=data)
#define  get_NF_RND_CMD1_reg                                                     (*((volatile unsigned int*)NF_RND_CMD1_reg))
#define  NF_RND_CMD1_rnd_cmd1_shift                                              (0)
#define  NF_RND_CMD1_rnd_cmd1_mask                                               (0x000000FF)
#define  NF_RND_CMD1_rnd_cmd1(data)                                              (0x000000FF&(data))
#define  NF_RND_CMD1_get_rnd_cmd1(data)                                          (0x000000FF&(data))

#define  NF_RND_CMD2                                                             0x1801020C
#define  NF_RND_CMD2_reg_addr                                                    "0xB801020C"
#define  NF_RND_CMD2_reg                                                         0xB801020C
#define  NF_RND_CMD2_inst_addr                                                   "0x0024"
#define  set_NF_RND_CMD2_reg(data)                                               (*((volatile unsigned int*)NF_RND_CMD2_reg)=data)
#define  get_NF_RND_CMD2_reg                                                     (*((volatile unsigned int*)NF_RND_CMD2_reg))
#define  NF_RND_CMD2_rnd_cmd2_shift                                              (0)
#define  NF_RND_CMD2_rnd_cmd2_mask                                               (0x000000FF)
#define  NF_RND_CMD2_rnd_cmd2(data)                                              (0x000000FF&(data))
#define  NF_RND_CMD2_get_rnd_cmd2(data)                                          (0x000000FF&(data))

#define  NF_RND_DATASTR_COL_H                                                    0x18010210
#define  NF_RND_DATASTR_COL_H_reg_addr                                           "0xB8010210"
#define  NF_RND_DATASTR_COL_H_reg                                                0xB8010210
#define  NF_RND_DATASTR_COL_H_inst_addr                                          "0x0025"
#define  set_NF_RND_DATASTR_COL_H_reg(data)                                      (*((volatile unsigned int*)NF_RND_DATASTR_COL_H_reg)=data)
#define  get_NF_RND_DATASTR_COL_H_reg                                            (*((volatile unsigned int*)NF_RND_DATASTR_COL_H_reg))
#define  NF_RND_DATASTR_COL_H_data_col_msb_shift                                 (0)
#define  NF_RND_DATASTR_COL_H_data_col_msb_mask                                  (0x000000FF)
#define  NF_RND_DATASTR_COL_H_data_col_msb(data)                                 (0x000000FF&(data))
#define  NF_RND_DATASTR_COL_H_get_data_col_msb(data)                             (0x000000FF&(data))

#define  NF_RND_SPR_STR_COL_H                                                    0x18010214
#define  NF_RND_SPR_STR_COL_H_reg_addr                                           "0xB8010214"
#define  NF_RND_SPR_STR_COL_H_reg                                                0xB8010214
#define  NF_RND_SPR_STR_COL_H_inst_addr                                          "0x0026"
#define  set_NF_RND_SPR_STR_COL_H_reg(data)                                      (*((volatile unsigned int*)NF_RND_SPR_STR_COL_H_reg)=data)
#define  get_NF_RND_SPR_STR_COL_H_reg                                            (*((volatile unsigned int*)NF_RND_SPR_STR_COL_H_reg))
#define  NF_RND_SPR_STR_COL_H_spr_col_msb_shift                                  (0)
#define  NF_RND_SPR_STR_COL_H_spr_col_msb_mask                                   (0x000000FF)
#define  NF_RND_SPR_STR_COL_H_spr_col_msb(data)                                  (0x000000FF&(data))
#define  NF_RND_SPR_STR_COL_H_get_spr_col_msb(data)                              (0x000000FF&(data))

#define  NF_RND_SPR_STR_COL_L                                                    0x18010218
#define  NF_RND_SPR_STR_COL_L_reg_addr                                           "0xB8010218"
#define  NF_RND_SPR_STR_COL_L_reg                                                0xB8010218
#define  NF_RND_SPR_STR_COL_L_inst_addr                                          "0x0027"
#define  set_NF_RND_SPR_STR_COL_L_reg(data)                                      (*((volatile unsigned int*)NF_RND_SPR_STR_COL_L_reg)=data)
#define  get_NF_RND_SPR_STR_COL_L_reg                                            (*((volatile unsigned int*)NF_RND_SPR_STR_COL_L_reg))
#define  NF_RND_SPR_STR_COL_L_spr_col_lsb_shift                                  (0)
#define  NF_RND_SPR_STR_COL_L_spr_col_lsb_mask                                   (0x000000FF)
#define  NF_RND_SPR_STR_COL_L_spr_col_lsb(data)                                  (0x000000FF&(data))
#define  NF_RND_SPR_STR_COL_L_get_spr_col_lsb(data)                              (0x000000FF&(data))

#define  NF_RND_RW_EN                                                            0x1801021C
#define  NF_RND_RW_EN_reg_addr                                                   "0xB801021C"
#define  NF_RND_RW_EN_reg                                                        0xB801021C
#define  NF_RND_RW_EN_inst_addr                                                  "0x0028"
#define  set_NF_RND_RW_EN_reg(data)                                              (*((volatile unsigned int*)NF_RND_RW_EN_reg)=data)
#define  get_NF_RND_RW_EN_reg                                                    (*((volatile unsigned int*)NF_RND_RW_EN_reg))
#define  NF_RND_RW_EN_rnd_rw_enable_shift                                        (0)
#define  NF_RND_RW_EN_rnd_rw_enable_mask                                         (0x00000001)
#define  NF_RND_RW_EN_rnd_rw_enable(data)                                        (0x00000001&(data))
#define  NF_RND_RW_EN_get_rnd_rw_enable(data)                                    (0x00000001&(data))

#define  NF_PP_SRAM_FLUSH                                                        0x18010220
#define  NF_PP_SRAM_FLUSH_reg_addr                                               "0xB8010220"
#define  NF_PP_SRAM_FLUSH_reg                                                    0xB8010220
#define  NF_PP_SRAM_FLUSH_inst_addr                                              "0x0029"
#define  set_NF_PP_SRAM_FLUSH_reg(data)                                          (*((volatile unsigned int*)NF_PP_SRAM_FLUSH_reg)=data)
#define  get_NF_PP_SRAM_FLUSH_reg                                                (*((volatile unsigned int*)NF_PP_SRAM_FLUSH_reg))
#define  NF_PP_SRAM_FLUSH_flush_status_shift                                     (1)
#define  NF_PP_SRAM_FLUSH_start_flush_shift                                      (0)
#define  NF_PP_SRAM_FLUSH_flush_status_mask                                      (0x00000002)
#define  NF_PP_SRAM_FLUSH_start_flush_mask                                       (0x00000001)
#define  NF_PP_SRAM_FLUSH_flush_status(data)                                     (0x00000002&((data)<<1))
#define  NF_PP_SRAM_FLUSH_start_flush(data)                                      (0x00000001&(data))
#define  NF_PP_SRAM_FLUSH_get_flush_status(data)                                 ((0x00000002&(data))>>1)
#define  NF_PP_SRAM_FLUSH_get_start_flush(data)                                  (0x00000001&(data))

#define  NF_READ_BY_PP                                                           0x18010228
#define  NF_READ_BY_PP_reg_addr                                                  "0xB8010228"
#define  NF_READ_BY_PP_reg                                                       0xB8010228
#define  NF_READ_BY_PP_inst_addr                                                 "0x002A"
#define  set_NF_READ_BY_PP_reg(data)                                             (*((volatile unsigned int*)NF_READ_BY_PP_reg)=data)
#define  get_NF_READ_BY_PP_reg                                                   (*((volatile unsigned int*)NF_READ_BY_PP_reg))
#define  NF_READ_BY_PP_read_by_pp_shift                                          (7)
#define  NF_READ_BY_PP_read_by_pp_mask                                           (0x00000080)
#define  NF_READ_BY_PP_read_by_pp(data)                                          (0x00000080&((data)<<7))
#define  NF_READ_BY_PP_get_read_by_pp(data)                                      ((0x00000080&(data))>>7)

#define  NF_MAX_ECC_NUM                                                          0x1801022C
#define  NF_MAX_ECC_NUM_reg_addr                                                 "0xB801022C"
#define  NF_MAX_ECC_NUM_reg                                                      0xB801022C
#define  NF_MAX_ECC_NUM_inst_addr                                                "0x002B"
#define  set_NF_MAX_ECC_NUM_reg(data)                                            (*((volatile unsigned int*)NF_MAX_ECC_NUM_reg)=data)
#define  get_NF_MAX_ECC_NUM_reg                                                  (*((volatile unsigned int*)NF_MAX_ECC_NUM_reg))
#define  NF_MAX_ECC_NUM_max_ecc_num_shift                                        (0)
#define  NF_MAX_ECC_NUM_max_ecc_num_mask                                         (0x0000007F)
#define  NF_MAX_ECC_NUM_max_ecc_num(data)                                        (0x0000007F&(data))
#define  NF_MAX_ECC_NUM_get_max_ecc_num(data)                                    (0x0000007F&(data))

#define  NF_PAGE_ECC_NUM                                                         0x18010230
#define  NF_PAGE_ECC_NUM_reg_addr                                                "0xB8010230"
#define  NF_PAGE_ECC_NUM_reg                                                     0xB8010230
#define  NF_PAGE_ECC_NUM_inst_addr                                               "0x002C"
#define  set_NF_PAGE_ECC_NUM_reg(data)                                           (*((volatile unsigned int*)NF_PAGE_ECC_NUM_reg)=data)
#define  get_NF_PAGE_ECC_NUM_reg                                                 (*((volatile unsigned int*)NF_PAGE_ECC_NUM_reg))
#define  NF_PAGE_ECC_NUM_page_ecc_num_shift                                      (0)
#define  NF_PAGE_ECC_NUM_page_ecc_num_mask                                       (0x000000FF)
#define  NF_PAGE_ECC_NUM_page_ecc_num(data)                                      (0x000000FF&(data))
#define  NF_PAGE_ECC_NUM_get_page_ecc_num(data)                                  (0x000000FF&(data))

#define  NF_TIME_PARA3                                                           0x18010234
#define  NF_TIME_PARA3_reg_addr                                                  "0xB8010234"
#define  NF_TIME_PARA3_reg                                                       0xB8010234
#define  NF_TIME_PARA3_inst_addr                                                 "0x002D"
#define  set_NF_TIME_PARA3_reg(data)                                             (*((volatile unsigned int*)NF_TIME_PARA3_reg)=data)
#define  get_NF_TIME_PARA3_reg                                                   (*((volatile unsigned int*)NF_TIME_PARA3_reg))
#define  NF_TIME_PARA3_t3_shift                                                  (0)
#define  NF_TIME_PARA3_t3_mask                                                   (0x000000FF)
#define  NF_TIME_PARA3_t3(data)                                                  (0x000000FF&(data))
#define  NF_TIME_PARA3_get_t3(data)                                              (0x000000FF&(data))

#define  NF_TIME_PARA2                                                           0x18010238
#define  NF_TIME_PARA2_reg_addr                                                  "0xB8010238"
#define  NF_TIME_PARA2_reg                                                       0xB8010238
#define  NF_TIME_PARA2_inst_addr                                                 "0x002E"
#define  set_NF_TIME_PARA2_reg(data)                                             (*((volatile unsigned int*)NF_TIME_PARA2_reg)=data)
#define  get_NF_TIME_PARA2_reg                                                   (*((volatile unsigned int*)NF_TIME_PARA2_reg))
#define  NF_TIME_PARA2_t2_shift                                                  (0)
#define  NF_TIME_PARA2_t2_mask                                                   (0x000000FF)
#define  NF_TIME_PARA2_t2(data)                                                  (0x000000FF&(data))
#define  NF_TIME_PARA2_get_t2(data)                                              (0x000000FF&(data))

#define  NF_TIME_PARA1                                                           0x1801023C
#define  NF_TIME_PARA1_reg_addr                                                  "0xB801023C"
#define  NF_TIME_PARA1_reg                                                       0xB801023C
#define  NF_TIME_PARA1_inst_addr                                                 "0x002F"
#define  set_NF_TIME_PARA1_reg(data)                                             (*((volatile unsigned int*)NF_TIME_PARA1_reg)=data)
#define  get_NF_TIME_PARA1_reg                                                   (*((volatile unsigned int*)NF_TIME_PARA1_reg))
#define  NF_TIME_PARA1_t1_shift                                                  (0)
#define  NF_TIME_PARA1_t1_mask                                                   (0x000000FF)
#define  NF_TIME_PARA1_t1(data)                                                  (0x000000FF&(data))
#define  NF_TIME_PARA1_get_t1(data)                                              (0x000000FF&(data))

#define  NF_ND_BLOCK_MODE                                                        0x18010240
#define  NF_ND_BLOCK_MODE_reg_addr                                               "0xB8010240"
#define  NF_ND_BLOCK_MODE_reg                                                    0xB8010240
#define  NF_ND_BLOCK_MODE_inst_addr                                              "0x0030"
#define  set_NF_ND_BLOCK_MODE_reg(data)                                          (*((volatile unsigned int*)NF_ND_BLOCK_MODE_reg)=data)
#define  get_NF_ND_BLOCK_MODE_reg                                                (*((volatile unsigned int*)NF_ND_BLOCK_MODE_reg))
#define  NF_ND_BLOCK_MODE_access_err_shift                                       (1)
#define  NF_ND_BLOCK_MODE_block_trig_shift                                       (0)
#define  NF_ND_BLOCK_MODE_access_err_mask                                        (0x00000002)
#define  NF_ND_BLOCK_MODE_block_trig_mask                                        (0x00000001)
#define  NF_ND_BLOCK_MODE_access_err(data)                                       (0x00000002&((data)<<1))
#define  NF_ND_BLOCK_MODE_block_trig(data)                                       (0x00000001&(data))
#define  NF_ND_BLOCK_MODE_get_access_err(data)                                   ((0x00000002&(data))>>1)
#define  NF_ND_BLOCK_MODE_get_block_trig(data)                                   (0x00000001&(data))

#define  NF_ND_BLOCK_PAGE0                                                       0x18010244
#define  NF_ND_BLOCK_PAGE0_reg_addr                                              "0xB8010244"
#define  NF_ND_BLOCK_PAGE0_reg                                                   0xB8010244
#define  NF_ND_BLOCK_PAGE0_inst_addr                                             "0x0031"
#define  set_NF_ND_BLOCK_PAGE0_reg(data)                                         (*((volatile unsigned int*)NF_ND_BLOCK_PAGE0_reg)=data)
#define  get_NF_ND_BLOCK_PAGE0_reg                                               (*((volatile unsigned int*)NF_ND_BLOCK_PAGE0_reg))
#define  NF_ND_BLOCK_PAGE0_block_page_len0_shift                                 (0)
#define  NF_ND_BLOCK_PAGE0_block_page_len0_mask                                  (0x000000FF)
#define  NF_ND_BLOCK_PAGE0_block_page_len0(data)                                 (0x000000FF&(data))
#define  NF_ND_BLOCK_PAGE0_get_block_page_len0(data)                             (0x000000FF&(data))

#define  NF_ND_BLOCK_PAGE1                                                       0x18010248
#define  NF_ND_BLOCK_PAGE1_reg_addr                                              "0xB8010248"
#define  NF_ND_BLOCK_PAGE1_reg                                                   0xB8010248
#define  NF_ND_BLOCK_PAGE1_inst_addr                                             "0x0032"
#define  set_NF_ND_BLOCK_PAGE1_reg(data)                                         (*((volatile unsigned int*)NF_ND_BLOCK_PAGE1_reg)=data)
#define  get_NF_ND_BLOCK_PAGE1_reg                                               (*((volatile unsigned int*)NF_ND_BLOCK_PAGE1_reg))
#define  NF_ND_BLOCK_PAGE1_block_page_len1_shift                                 (0)
#define  NF_ND_BLOCK_PAGE1_block_page_len1_mask                                  (0x000000FF)
#define  NF_ND_BLOCK_PAGE1_block_page_len1(data)                                 (0x000000FF&(data))
#define  NF_ND_BLOCK_PAGE1_get_block_page_len1(data)                             (0x000000FF&(data))

#define  NF_ND_BLOCK_PAGE_CNT0                                                   0x1801024C
#define  NF_ND_BLOCK_PAGE_CNT0_reg_addr                                          "0xB801024C"
#define  NF_ND_BLOCK_PAGE_CNT0_reg                                               0xB801024C
#define  NF_ND_BLOCK_PAGE_CNT0_inst_addr                                         "0x0033"
#define  set_NF_ND_BLOCK_PAGE_CNT0_reg(data)                                     (*((volatile unsigned int*)NF_ND_BLOCK_PAGE_CNT0_reg)=data)
#define  get_NF_ND_BLOCK_PAGE_CNT0_reg                                           (*((volatile unsigned int*)NF_ND_BLOCK_PAGE_CNT0_reg))
#define  NF_ND_BLOCK_PAGE_CNT0_block_page_cnt0_shift                             (0)
#define  NF_ND_BLOCK_PAGE_CNT0_block_page_cnt0_mask                              (0x000000FF)
#define  NF_ND_BLOCK_PAGE_CNT0_block_page_cnt0(data)                             (0x000000FF&(data))
#define  NF_ND_BLOCK_PAGE_CNT0_get_block_page_cnt0(data)                         (0x000000FF&(data))

#define  NF_ND_BLOCK_PAGE_CNT1                                                   0x18010250
#define  NF_ND_BLOCK_PAGE_CNT1_reg_addr                                          "0xB8010250"
#define  NF_ND_BLOCK_PAGE_CNT1_reg                                               0xB8010250
#define  NF_ND_BLOCK_PAGE_CNT1_inst_addr                                         "0x0034"
#define  set_NF_ND_BLOCK_PAGE_CNT1_reg(data)                                     (*((volatile unsigned int*)NF_ND_BLOCK_PAGE_CNT1_reg)=data)
#define  get_NF_ND_BLOCK_PAGE_CNT1_reg                                           (*((volatile unsigned int*)NF_ND_BLOCK_PAGE_CNT1_reg))
#define  NF_ND_BLOCK_PAGE_CNT1_block_page_cnt1_shift                             (0)
#define  NF_ND_BLOCK_PAGE_CNT1_block_page_cnt1_mask                              (0x000000FF)
#define  NF_ND_BLOCK_PAGE_CNT1_block_page_cnt1(data)                             (0x000000FF&(data))
#define  NF_ND_BLOCK_PAGE_CNT1_get_block_page_cnt1(data)                         (0x000000FF&(data))

#define  NF_PIN_MUX_STOP                                                         0x1801025C
#define  NF_PIN_MUX_STOP_reg_addr                                                "0xB801025C"
#define  NF_PIN_MUX_STOP_reg                                                     0xB801025C
#define  NF_PIN_MUX_STOP_inst_addr                                               "0x0035"
#define  set_NF_PIN_MUX_STOP_reg(data)                                           (*((volatile unsigned int*)NF_PIN_MUX_STOP_reg)=data)
#define  get_NF_PIN_MUX_STOP_reg                                                 (*((volatile unsigned int*)NF_PIN_MUX_STOP_reg))
#define  NF_PIN_MUX_STOP_pin_stop_shift                                          (2)
#define  NF_PIN_MUX_STOP_intlev_pin_ena_shift                                    (1)
#define  NF_PIN_MUX_STOP_pin_mux_ena_shift                                       (0)
#define  NF_PIN_MUX_STOP_pin_stop_mask                                           (0x00000004)
#define  NF_PIN_MUX_STOP_intlev_pin_ena_mask                                     (0x00000002)
#define  NF_PIN_MUX_STOP_pin_mux_ena_mask                                        (0x00000001)
#define  NF_PIN_MUX_STOP_pin_stop(data)                                          (0x00000004&((data)<<2))
#define  NF_PIN_MUX_STOP_intlev_pin_ena(data)                                    (0x00000002&((data)<<1))
#define  NF_PIN_MUX_STOP_pin_mux_ena(data)                                       (0x00000001&(data))
#define  NF_PIN_MUX_STOP_get_pin_stop(data)                                      ((0x00000004&(data))>>2)
#define  NF_PIN_MUX_STOP_get_intlev_pin_ena(data)                                ((0x00000002&(data))>>1)
#define  NF_PIN_MUX_STOP_get_pin_mux_ena(data)                                   (0x00000001&(data))

#define  NF_DELAY_CTL                                                            0x18010260
#define  NF_DELAY_CTL_reg_addr                                                   "0xB8010260"
#define  NF_DELAY_CTL_reg                                                        0xB8010260
#define  NF_DELAY_CTL_inst_addr                                                  "0x0036"
#define  set_NF_DELAY_CTL_reg(data)                                              (*((volatile unsigned int*)NF_DELAY_CTL_reg)=data)
#define  get_NF_DELAY_CTL_reg                                                    (*((volatile unsigned int*)NF_DELAY_CTL_reg))
#define  NF_DELAY_CTL_t_swait_busy_shift                                         (6)
#define  NF_DELAY_CTL_t_whr_adl_shift                                            (0)
#define  NF_DELAY_CTL_t_swait_busy_mask                                          (0x000000C0)
#define  NF_DELAY_CTL_t_whr_adl_mask                                             (0x0000003F)
#define  NF_DELAY_CTL_t_swait_busy(data)                                         (0x000000C0&((data)<<6))
#define  NF_DELAY_CTL_t_whr_adl(data)                                            (0x0000003F&(data))
#define  NF_DELAY_CTL_get_t_swait_busy(data)                                     ((0x000000C0&(data))>>6)
#define  NF_DELAY_CTL_get_t_whr_adl(data)                                        (0x0000003F&(data))

#define  NF_ECC_STOP                                                             0x18010264
#define  NF_ECC_STOP_reg_addr                                                    "0xB8010264"
#define  NF_ECC_STOP_reg                                                         0xB8010264
#define  NF_ECC_STOP_inst_addr                                                   "0x0037"
#define  set_NF_ECC_STOP_reg(data)                                               (*((volatile unsigned int*)NF_ECC_STOP_reg)=data)
#define  get_NF_ECC_STOP_reg                                                     (*((volatile unsigned int*)NF_ECC_STOP_reg))
#define  NF_ECC_STOP_ecc_n_stop_shift                                            (7)
#define  NF_ECC_STOP_ecc_n_stop_mask                                             (0x00000080)
#define  NF_ECC_STOP_ecc_n_stop(data)                                            (0x00000080&((data)<<7))
#define  NF_ECC_STOP_get_ecc_n_stop(data)                                        ((0x00000080&(data))>>7)

#define  NF_ECC_PAGE                                                             0x18010268
#define  NF_ECC_PAGE_reg_addr                                                    "0xB8010268"
#define  NF_ECC_PAGE_reg                                                         0xB8010268
#define  NF_ECC_PAGE_inst_addr                                                   "0x0038"
#define  set_NF_ECC_PAGE_reg(data)                                               (*((volatile unsigned int*)NF_ECC_PAGE_reg)=data)
#define  get_NF_ECC_PAGE_reg                                                     (*((volatile unsigned int*)NF_ECC_PAGE_reg))
#define  NF_ECC_PAGE_ecc_page_shift                                              (0)
#define  NF_ECC_PAGE_ecc_page_mask                                               (0x000000FF)
#define  NF_ECC_PAGE_ecc_page(data)                                              (0x000000FF&(data))
#define  NF_ECC_PAGE_get_ecc_page(data)                                          (0x000000FF&(data))

#define  NF_PAGE_CNT                                                             0x1801026C
#define  NF_PAGE_CNT_reg_addr                                                    "0xB801026C"
#define  NF_PAGE_CNT_reg                                                         0xB801026C
#define  NF_PAGE_CNT_inst_addr                                                   "0x0039"
#define  set_NF_PAGE_CNT_reg(data)                                               (*((volatile unsigned int*)NF_PAGE_CNT_reg)=data)
#define  get_NF_PAGE_CNT_reg                                                     (*((volatile unsigned int*)NF_PAGE_CNT_reg))
#define  NF_PAGE_CNT_page_cnt_shift                                              (0)
#define  NF_PAGE_CNT_page_cnt_mask                                               (0x000000FF)
#define  NF_PAGE_CNT_page_cnt(data)                                              (0x000000FF&(data))
#define  NF_PAGE_CNT_get_page_cnt(data)                                          (0x000000FF&(data))

#define  NF_PAGE_LEN                                                             0x18010270
#define  NF_PAGE_LEN_reg_addr                                                    "0xB8010270"
#define  NF_PAGE_LEN_reg                                                         0xB8010270
#define  NF_PAGE_LEN_inst_addr                                                   "0x003A"
#define  set_NF_PAGE_LEN_reg(data)                                               (*((volatile unsigned int*)NF_PAGE_LEN_reg)=data)
#define  get_NF_PAGE_LEN_reg                                                     (*((volatile unsigned int*)NF_PAGE_LEN_reg))
#define  NF_PAGE_LEN_page_len_shift                                              (0)
#define  NF_PAGE_LEN_page_len_mask                                               (0x000000FF)
#define  NF_PAGE_LEN_page_len(data)                                              (0x000000FF&(data))
#define  NF_PAGE_LEN_get_page_len(data)                                          (0x000000FF&(data))

#define  NF_CMD2                                                                 0x18010274
#define  NF_CMD2_reg_addr                                                        "0xB8010274"
#define  NF_CMD2_reg                                                             0xB8010274
#define  NF_CMD2_inst_addr                                                       "0x003B"
#define  set_NF_CMD2_reg(data)                                                   (*((volatile unsigned int*)NF_CMD2_reg)=data)
#define  get_NF_CMD2_reg                                                         (*((volatile unsigned int*)NF_CMD2_reg))
#define  NF_CMD2_cmd2_shift                                                      (0)
#define  NF_CMD2_cmd2_mask                                                       (0x000000FF)
#define  NF_CMD2_cmd2(data)                                                      (0x000000FF&(data))
#define  NF_CMD2_get_cmd2(data)                                                  (0x000000FF&(data))

#define  NF_MULTI_CHNL_MODE                                                      0x1801027C
#define  NF_MULTI_CHNL_MODE_reg_addr                                             "0xB801027C"
#define  NF_MULTI_CHNL_MODE_reg                                                  0xB801027C
#define  NF_MULTI_CHNL_MODE_inst_addr                                            "0x003C"
#define  set_NF_MULTI_CHNL_MODE_reg(data)                                        (*((volatile unsigned int*)NF_MULTI_CHNL_MODE_reg)=data)
#define  get_NF_MULTI_CHNL_MODE_reg                                              (*((volatile unsigned int*)NF_MULTI_CHNL_MODE_reg))
#define  NF_MULTI_CHNL_MODE_ecc_pass_shift                                       (7)
#define  NF_MULTI_CHNL_MODE_ecc_no_check_shift                                   (6)
#define  NF_MULTI_CHNL_MODE_edo_shift                                            (5)
#define  NF_MULTI_CHNL_MODE_no_wait_busy_shift                                   (4)
#define  NF_MULTI_CHNL_MODE_wait_ready_shift                                     (2)
#define  NF_MULTI_CHNL_MODE_ecc_pass_mask                                        (0x00000080)
#define  NF_MULTI_CHNL_MODE_ecc_no_check_mask                                    (0x00000040)
#define  NF_MULTI_CHNL_MODE_edo_mask                                             (0x00000020)
#define  NF_MULTI_CHNL_MODE_no_wait_busy_mask                                    (0x00000010)
#define  NF_MULTI_CHNL_MODE_wait_ready_mask                                      (0x0000000C)
#define  NF_MULTI_CHNL_MODE_ecc_pass(data)                                       (0x00000080&((data)<<7))
#define  NF_MULTI_CHNL_MODE_ecc_no_check(data)                                   (0x00000040&((data)<<6))
#define  NF_MULTI_CHNL_MODE_edo(data)                                            (0x00000020&((data)<<5))
#define  NF_MULTI_CHNL_MODE_no_wait_busy(data)                                   (0x00000010&((data)<<4))
#define  NF_MULTI_CHNL_MODE_wait_ready(data)                                     (0x0000000C&((data)<<2))
#define  NF_MULTI_CHNL_MODE_get_ecc_pass(data)                                   ((0x00000080&(data))>>7)
#define  NF_MULTI_CHNL_MODE_get_ecc_no_check(data)                               ((0x00000040&(data))>>6)
#define  NF_MULTI_CHNL_MODE_get_edo(data)                                        ((0x00000020&(data))>>5)
#define  NF_MULTI_CHNL_MODE_get_no_wait_busy(data)                               ((0x00000010&(data))>>4)
#define  NF_MULTI_CHNL_MODE_get_wait_ready(data)                                 ((0x0000000C&(data))>>2)

#define  NF_ND_SECU_START_PA0                                                    0x18010280
#define  NF_ND_SECU_START_PA0_reg_addr                                           "0xB8010280"
#define  NF_ND_SECU_START_PA0_reg                                                0xB8010280
#define  NF_ND_SECU_START_PA0_inst_addr                                          "0x003D"
#define  set_NF_ND_SECU_START_PA0_reg(data)                                      (*((volatile unsigned int*)NF_ND_SECU_START_PA0_reg)=data)
#define  get_NF_ND_SECU_START_PA0_reg                                            (*((volatile unsigned int*)NF_ND_SECU_START_PA0_reg))
#define  NF_ND_SECU_START_PA0_page_addr0_shift                                   (0)
#define  NF_ND_SECU_START_PA0_page_addr0_mask                                    (0x000000FF)
#define  NF_ND_SECU_START_PA0_page_addr0(data)                                   (0x000000FF&(data))
#define  NF_ND_SECU_START_PA0_get_page_addr0(data)                               (0x000000FF&(data))

#define  NF_ND_SECU_START_PA1                                                    0x18010284
#define  NF_ND_SECU_START_PA1_reg_addr                                           "0xB8010284"
#define  NF_ND_SECU_START_PA1_reg                                                0xB8010284
#define  NF_ND_SECU_START_PA1_inst_addr                                          "0x003E"
#define  set_NF_ND_SECU_START_PA1_reg(data)                                      (*((volatile unsigned int*)NF_ND_SECU_START_PA1_reg)=data)
#define  get_NF_ND_SECU_START_PA1_reg                                            (*((volatile unsigned int*)NF_ND_SECU_START_PA1_reg))
#define  NF_ND_SECU_START_PA1_page_addr1_shift                                   (0)
#define  NF_ND_SECU_START_PA1_page_addr1_mask                                    (0x000000FF)
#define  NF_ND_SECU_START_PA1_page_addr1(data)                                   (0x000000FF&(data))
#define  NF_ND_SECU_START_PA1_get_page_addr1(data)                               (0x000000FF&(data))

#define  NF_ND_SECU_START_PA2                                                    0x18010288
#define  NF_ND_SECU_START_PA2_reg_addr                                           "0xB8010288"
#define  NF_ND_SECU_START_PA2_reg                                                0xB8010288
#define  NF_ND_SECU_START_PA2_inst_addr                                          "0x003F"
#define  set_NF_ND_SECU_START_PA2_reg(data)                                      (*((volatile unsigned int*)NF_ND_SECU_START_PA2_reg)=data)
#define  get_NF_ND_SECU_START_PA2_reg                                            (*((volatile unsigned int*)NF_ND_SECU_START_PA2_reg))
#define  NF_ND_SECU_START_PA2_page_addr2_shift                                   (0)
#define  NF_ND_SECU_START_PA2_page_addr2_mask                                    (0x000000FF)
#define  NF_ND_SECU_START_PA2_page_addr2(data)                                   (0x000000FF&(data))
#define  NF_ND_SECU_START_PA2_get_page_addr2(data)                               (0x000000FF&(data))

#define  NF_ND_SECU_END_PA0                                                      0x18010290
#define  NF_ND_SECU_END_PA0_reg_addr                                             "0xB8010290"
#define  NF_ND_SECU_END_PA0_reg                                                  0xB8010290
#define  NF_ND_SECU_END_PA0_inst_addr                                            "0x0040"
#define  set_NF_ND_SECU_END_PA0_reg(data)                                        (*((volatile unsigned int*)NF_ND_SECU_END_PA0_reg)=data)
#define  get_NF_ND_SECU_END_PA0_reg                                              (*((volatile unsigned int*)NF_ND_SECU_END_PA0_reg))
#define  NF_ND_SECU_END_PA0_page_addr0_shift                                     (0)
#define  NF_ND_SECU_END_PA0_page_addr0_mask                                      (0x000000FF)
#define  NF_ND_SECU_END_PA0_page_addr0(data)                                     (0x000000FF&(data))
#define  NF_ND_SECU_END_PA0_get_page_addr0(data)                                 (0x000000FF&(data))

#define  NF_ND_SECU_END_PA1                                                      0x18010294
#define  NF_ND_SECU_END_PA1_reg_addr                                             "0xB8010294"
#define  NF_ND_SECU_END_PA1_reg                                                  0xB8010294
#define  NF_ND_SECU_END_PA1_inst_addr                                            "0x0041"
#define  set_NF_ND_SECU_END_PA1_reg(data)                                        (*((volatile unsigned int*)NF_ND_SECU_END_PA1_reg)=data)
#define  get_NF_ND_SECU_END_PA1_reg                                              (*((volatile unsigned int*)NF_ND_SECU_END_PA1_reg))
#define  NF_ND_SECU_END_PA1_page_addr1_shift                                     (0)
#define  NF_ND_SECU_END_PA1_page_addr1_mask                                      (0x000000FF)
#define  NF_ND_SECU_END_PA1_page_addr1(data)                                     (0x000000FF&(data))
#define  NF_ND_SECU_END_PA1_get_page_addr1(data)                                 (0x000000FF&(data))

#define  NF_ND_SECU_END_PA2                                                      0x18010298
#define  NF_ND_SECU_END_PA2_reg_addr                                             "0xB8010298"
#define  NF_ND_SECU_END_PA2_reg                                                  0xB8010298
#define  NF_ND_SECU_END_PA2_inst_addr                                            "0x0042"
#define  set_NF_ND_SECU_END_PA2_reg(data)                                        (*((volatile unsigned int*)NF_ND_SECU_END_PA2_reg)=data)
#define  get_NF_ND_SECU_END_PA2_reg                                              (*((volatile unsigned int*)NF_ND_SECU_END_PA2_reg))
#define  NF_ND_SECU_END_PA2_page_addr2_shift                                     (0)
#define  NF_ND_SECU_END_PA2_page_addr2_mask                                      (0x000000FF)
#define  NF_ND_SECU_END_PA2_page_addr2(data)                                     (0x000000FF&(data))
#define  NF_ND_SECU_END_PA2_get_page_addr2(data)                                 (0x000000FF&(data))

#define  NF_ND_SECU_START2_PA0                                                   0x180102A0
#define  NF_ND_SECU_START2_PA0_reg_addr                                          "0xB80102A0"
#define  NF_ND_SECU_START2_PA0_reg                                               0xB80102A0
#define  NF_ND_SECU_START2_PA0_inst_addr                                         "0x0043"
#define  set_NF_ND_SECU_START2_PA0_reg(data)                                     (*((volatile unsigned int*)NF_ND_SECU_START2_PA0_reg)=data)
#define  get_NF_ND_SECU_START2_PA0_reg                                           (*((volatile unsigned int*)NF_ND_SECU_START2_PA0_reg))
#define  NF_ND_SECU_START2_PA0_page_addr0_shift                                  (0)
#define  NF_ND_SECU_START2_PA0_page_addr0_mask                                   (0x000000FF)
#define  NF_ND_SECU_START2_PA0_page_addr0(data)                                  (0x000000FF&(data))
#define  NF_ND_SECU_START2_PA0_get_page_addr0(data)                              (0x000000FF&(data))

#define  NF_ND_SECU_START2_PA1                                                   0x180102A4
#define  NF_ND_SECU_START2_PA1_reg_addr                                          "0xB80102A4"
#define  NF_ND_SECU_START2_PA1_reg                                               0xB80102A4
#define  NF_ND_SECU_START2_PA1_inst_addr                                         "0x0044"
#define  set_NF_ND_SECU_START2_PA1_reg(data)                                     (*((volatile unsigned int*)NF_ND_SECU_START2_PA1_reg)=data)
#define  get_NF_ND_SECU_START2_PA1_reg                                           (*((volatile unsigned int*)NF_ND_SECU_START2_PA1_reg))
#define  NF_ND_SECU_START2_PA1_page_addr1_shift                                  (0)
#define  NF_ND_SECU_START2_PA1_page_addr1_mask                                   (0x000000FF)
#define  NF_ND_SECU_START2_PA1_page_addr1(data)                                  (0x000000FF&(data))
#define  NF_ND_SECU_START2_PA1_get_page_addr1(data)                              (0x000000FF&(data))

#define  NF_ND_SECU_START2_PA2                                                   0x180102A8
#define  NF_ND_SECU_START2_PA2_reg_addr                                          "0xB80102A8"
#define  NF_ND_SECU_START2_PA2_reg                                               0xB80102A8
#define  NF_ND_SECU_START2_PA2_inst_addr                                         "0x0045"
#define  set_NF_ND_SECU_START2_PA2_reg(data)                                     (*((volatile unsigned int*)NF_ND_SECU_START2_PA2_reg)=data)
#define  get_NF_ND_SECU_START2_PA2_reg                                           (*((volatile unsigned int*)NF_ND_SECU_START2_PA2_reg))
#define  NF_ND_SECU_START2_PA2_page_addr2_shift                                  (0)
#define  NF_ND_SECU_START2_PA2_page_addr2_mask                                   (0x000000FF)
#define  NF_ND_SECU_START2_PA2_page_addr2(data)                                  (0x000000FF&(data))
#define  NF_ND_SECU_START2_PA2_get_page_addr2(data)                              (0x000000FF&(data))

#define  NF_ND_SECU_END2_PA0                                                     0x180102B0
#define  NF_ND_SECU_END2_PA0_reg_addr                                            "0xB80102B0"
#define  NF_ND_SECU_END2_PA0_reg                                                 0xB80102B0
#define  NF_ND_SECU_END2_PA0_inst_addr                                           "0x0046"
#define  set_NF_ND_SECU_END2_PA0_reg(data)                                       (*((volatile unsigned int*)NF_ND_SECU_END2_PA0_reg)=data)
#define  get_NF_ND_SECU_END2_PA0_reg                                             (*((volatile unsigned int*)NF_ND_SECU_END2_PA0_reg))
#define  NF_ND_SECU_END2_PA0_page_addr0_shift                                    (0)
#define  NF_ND_SECU_END2_PA0_page_addr0_mask                                     (0x000000FF)
#define  NF_ND_SECU_END2_PA0_page_addr0(data)                                    (0x000000FF&(data))
#define  NF_ND_SECU_END2_PA0_get_page_addr0(data)                                (0x000000FF&(data))

#define  NF_ND_SECU_END2_PA1                                                     0x180102B4
#define  NF_ND_SECU_END2_PA1_reg_addr                                            "0xB80102B4"
#define  NF_ND_SECU_END2_PA1_reg                                                 0xB80102B4
#define  NF_ND_SECU_END2_PA1_inst_addr                                           "0x0047"
#define  set_NF_ND_SECU_END2_PA1_reg(data)                                       (*((volatile unsigned int*)NF_ND_SECU_END2_PA1_reg)=data)
#define  get_NF_ND_SECU_END2_PA1_reg                                             (*((volatile unsigned int*)NF_ND_SECU_END2_PA1_reg))
#define  NF_ND_SECU_END2_PA1_page_addr1_shift                                    (0)
#define  NF_ND_SECU_END2_PA1_page_addr1_mask                                     (0x000000FF)
#define  NF_ND_SECU_END2_PA1_page_addr1(data)                                    (0x000000FF&(data))
#define  NF_ND_SECU_END2_PA1_get_page_addr1(data)                                (0x000000FF&(data))

#define  NF_ND_SECU_END2_PA2                                                     0x180102B8
#define  NF_ND_SECU_END2_PA2_reg_addr                                            "0xB80102B8"
#define  NF_ND_SECU_END2_PA2_reg                                                 0xB80102B8
#define  NF_ND_SECU_END2_PA2_inst_addr                                           "0x0048"
#define  set_NF_ND_SECU_END2_PA2_reg(data)                                       (*((volatile unsigned int*)NF_ND_SECU_END2_PA2_reg)=data)
#define  get_NF_ND_SECU_END2_PA2_reg                                             (*((volatile unsigned int*)NF_ND_SECU_END2_PA2_reg))
#define  NF_ND_SECU_END2_PA2_page_addr2_shift                                    (0)
#define  NF_ND_SECU_END2_PA2_page_addr2_mask                                     (0x000000FF)
#define  NF_ND_SECU_END2_PA2_page_addr2(data)                                    (0x000000FF&(data))
#define  NF_ND_SECU_END2_PA2_get_page_addr2(data)                                (0x000000FF&(data))

#define  NF_ND_SECU_MASK_EN                                                      0x180102BC
#define  NF_ND_SECU_MASK_EN_reg_addr                                             "0xB80102BC"
#define  NF_ND_SECU_MASK_EN_reg                                                  0xB80102BC
#define  NF_ND_SECU_MASK_EN_inst_addr                                            "0x0049"
#define  set_NF_ND_SECU_MASK_EN_reg(data)                                        (*((volatile unsigned int*)NF_ND_SECU_MASK_EN_reg)=data)
#define  get_NF_ND_SECU_MASK_EN_reg                                              (*((volatile unsigned int*)NF_ND_SECU_MASK_EN_reg))
#define  NF_ND_SECU_MASK_EN_xcpu_block_xfer_stop_en_shift                        (2)
#define  NF_ND_SECU_MASK_EN_enable1_shift                                        (1)
#define  NF_ND_SECU_MASK_EN_enable0_shift                                        (0)
#define  NF_ND_SECU_MASK_EN_xcpu_block_xfer_stop_en_mask                         (0x00000004)
#define  NF_ND_SECU_MASK_EN_enable1_mask                                         (0x00000002)
#define  NF_ND_SECU_MASK_EN_enable0_mask                                         (0x00000001)
#define  NF_ND_SECU_MASK_EN_xcpu_block_xfer_stop_en(data)                        (0x00000004&((data)<<2))
#define  NF_ND_SECU_MASK_EN_enable1(data)                                        (0x00000002&((data)<<1))
#define  NF_ND_SECU_MASK_EN_enable0(data)                                        (0x00000001&(data))
#define  NF_ND_SECU_MASK_EN_get_xcpu_block_xfer_stop_en(data)                    ((0x00000004&(data))>>2)
#define  NF_ND_SECU_MASK_EN_get_enable1(data)                                    ((0x00000002&(data))>>1)
#define  NF_ND_SECU_MASK_EN_get_enable0(data)                                    (0x00000001&(data))

#define  NF_SRAM_CTL                                                             0x18010300
#define  NF_SRAM_CTL_reg_addr                                                    "0xB8010300"
#define  NF_SRAM_CTL_reg                                                         0xB8010300
#define  NF_SRAM_CTL_inst_addr                                                   "0x004A"
#define  set_NF_SRAM_CTL_reg(data)                                               (*((volatile unsigned int*)NF_SRAM_CTL_reg)=data)
#define  get_NF_SRAM_CTL_reg                                                     (*((volatile unsigned int*)NF_SRAM_CTL_reg))
#define  NF_SRAM_CTL_map_sel_shift                                               (5)
#define  NF_SRAM_CTL_access_en_shift                                             (4)
#define  NF_SRAM_CTL_mem_region_shift                                            (0)
#define  NF_SRAM_CTL_map_sel_mask                                                (0x00000020)
#define  NF_SRAM_CTL_access_en_mask                                              (0x00000010)
#define  NF_SRAM_CTL_mem_region_mask                                             (0x0000000F)
#define  NF_SRAM_CTL_map_sel(data)                                               (0x00000020&((data)<<5))
#define  NF_SRAM_CTL_access_en(data)                                             (0x00000010&((data)<<4))
#define  NF_SRAM_CTL_mem_region(data)                                            (0x0000000F&(data))
#define  NF_SRAM_CTL_get_map_sel(data)                                           ((0x00000020&(data))>>5)
#define  NF_SRAM_CTL_get_access_en(data)                                         ((0x00000010&(data))>>4)
#define  NF_SRAM_CTL_get_mem_region(data)                                        (0x0000000F&(data))

#define  NF_DMA_CTL1                                                             0x18010304
#define  NF_DMA_CTL1_reg_addr                                                    "0xB8010304"
#define  NF_DMA_CTL1_reg                                                         0xB8010304
#define  NF_DMA_CTL1_inst_addr                                                   "0x004B"
#define  set_NF_DMA_CTL1_reg(data)                                               (*((volatile unsigned int*)NF_DMA_CTL1_reg)=data)
#define  get_NF_DMA_CTL1_reg                                                     (*((volatile unsigned int*)NF_DMA_CTL1_reg))
#define  NF_DMA_CTL1_dram_sa_shift                                               (0)
#define  NF_DMA_CTL1_dram_sa_mask                                                (0x1FFFFFFF)
#define  NF_DMA_CTL1_dram_sa(data)                                               (0x1FFFFFFF&(data))
#define  NF_DMA_CTL1_get_dram_sa(data)                                           (0x1FFFFFFF&(data))

#define  NF_DMA_CTL2                                                             0x18010308
#define  NF_DMA_CTL2_reg_addr                                                    "0xB8010308"
#define  NF_DMA_CTL2_reg                                                         0xB8010308
#define  NF_DMA_CTL2_inst_addr                                                   "0x004C"
#define  set_NF_DMA_CTL2_reg(data)                                               (*((volatile unsigned int*)NF_DMA_CTL2_reg)=data)
#define  get_NF_DMA_CTL2_reg                                                     (*((volatile unsigned int*)NF_DMA_CTL2_reg))
#define  NF_DMA_CTL2_dma_len_shift                                               (0)
#define  NF_DMA_CTL2_dma_len_mask                                                (0x0000FFFF)
#define  NF_DMA_CTL2_dma_len(data)                                               (0x0000FFFF&(data))
#define  NF_DMA_CTL2_get_dma_len(data)                                           (0x0000FFFF&(data))

#define  NF_DMA_CTL3                                                             0x1801030C
#define  NF_DMA_CTL3_reg_addr                                                    "0xB801030C"
#define  NF_DMA_CTL3_reg                                                         0xB801030C
#define  NF_DMA_CTL3_inst_addr                                                   "0x004D"
#define  set_NF_DMA_CTL3_reg(data)                                               (*((volatile unsigned int*)NF_DMA_CTL3_reg)=data)
#define  get_NF_DMA_CTL3_reg                                                     (*((volatile unsigned int*)NF_DMA_CTL3_reg))
#define  NF_DMA_CTL3_cp_first_shift                                              (3)
#define  NF_DMA_CTL3_cp_enable_shift                                             (2)
#define  NF_DMA_CTL3_ddr_wr_shift                                                (1)
#define  NF_DMA_CTL3_dma_xfer_shift                                              (0)
#define  NF_DMA_CTL3_cp_first_mask                                               (0x00000008)
#define  NF_DMA_CTL3_cp_enable_mask                                              (0x00000004)
#define  NF_DMA_CTL3_ddr_wr_mask                                                 (0x00000002)
#define  NF_DMA_CTL3_dma_xfer_mask                                               (0x00000001)
#define  NF_DMA_CTL3_cp_first(data)                                              (0x00000008&((data)<<3))
#define  NF_DMA_CTL3_cp_enable(data)                                             (0x00000004&((data)<<2))
#define  NF_DMA_CTL3_ddr_wr(data)                                                (0x00000002&((data)<<1))
#define  NF_DMA_CTL3_dma_xfer(data)                                              (0x00000001&(data))
#define  NF_DMA_CTL3_get_cp_first(data)                                          ((0x00000008&(data))>>3)
#define  NF_DMA_CTL3_get_cp_enable(data)                                         ((0x00000004&(data))>>2)
#define  NF_DMA_CTL3_get_ddr_wr(data)                                            ((0x00000002&(data))>>1)
#define  NF_DMA_CTL3_get_dma_xfer(data)                                          (0x00000001&(data))

#define  NF_SYS_LOW_PWR                                                          0x18010310
#define  NF_SYS_LOW_PWR_reg_addr                                                 "0xB8010310"
#define  NF_SYS_LOW_PWR_reg                                                      0xB8010310
#define  NF_SYS_LOW_PWR_inst_addr                                                "0x004E"
#define  set_NF_SYS_LOW_PWR_reg(data)                                            (*((volatile unsigned int*)NF_SYS_LOW_PWR_reg)=data)
#define  get_NF_SYS_LOW_PWR_reg                                                  (*((volatile unsigned int*)NF_SYS_LOW_PWR_reg))
#define  NF_SYS_LOW_PWR_mcu_pp_sram_lp_ena_shift                                 (7)
#define  NF_SYS_LOW_PWR_sys_clk_gate_ena_shift                                   (6)
#define  NF_SYS_LOW_PWR_cp_clk_gate_ena_shift                                    (5)
#define  NF_SYS_LOW_PWR_dma_sram_lp_ena_shift                                    (4)
#define  NF_SYS_LOW_PWR_dma_sram_rdy_num_shift                                   (0)
#define  NF_SYS_LOW_PWR_mcu_pp_sram_lp_ena_mask                                  (0x00000080)
#define  NF_SYS_LOW_PWR_sys_clk_gate_ena_mask                                    (0x00000040)
#define  NF_SYS_LOW_PWR_cp_clk_gate_ena_mask                                     (0x00000020)
#define  NF_SYS_LOW_PWR_dma_sram_lp_ena_mask                                     (0x00000010)
#define  NF_SYS_LOW_PWR_dma_sram_rdy_num_mask                                    (0x0000000F)
#define  NF_SYS_LOW_PWR_mcu_pp_sram_lp_ena(data)                                 (0x00000080&((data)<<7))
#define  NF_SYS_LOW_PWR_sys_clk_gate_ena(data)                                   (0x00000040&((data)<<6))
#define  NF_SYS_LOW_PWR_cp_clk_gate_ena(data)                                    (0x00000020&((data)<<5))
#define  NF_SYS_LOW_PWR_dma_sram_lp_ena(data)                                    (0x00000010&((data)<<4))
#define  NF_SYS_LOW_PWR_dma_sram_rdy_num(data)                                   (0x0000000F&(data))
#define  NF_SYS_LOW_PWR_get_mcu_pp_sram_lp_ena(data)                             ((0x00000080&(data))>>7)
#define  NF_SYS_LOW_PWR_get_sys_clk_gate_ena(data)                               ((0x00000040&(data))>>6)
#define  NF_SYS_LOW_PWR_get_cp_clk_gate_ena(data)                                ((0x00000020&(data))>>5)
#define  NF_SYS_LOW_PWR_get_dma_sram_lp_ena(data)                                ((0x00000010&(data))>>4)
#define  NF_SYS_LOW_PWR_get_dma_sram_rdy_num(data)                               (0x0000000F&(data))

#define  NF_DMA_SECU_CTL1                                                        0x18010314
#define  NF_DMA_SECU_CTL1_reg_addr                                               "0xB8010314"
#define  NF_DMA_SECU_CTL1_reg                                                    0xB8010314
#define  NF_DMA_SECU_CTL1_inst_addr                                              "0x004F"
#define  set_NF_DMA_SECU_CTL1_reg(data)                                          (*((volatile unsigned int*)NF_DMA_SECU_CTL1_reg)=data)
#define  get_NF_DMA_SECU_CTL1_reg                                                (*((volatile unsigned int*)NF_DMA_SECU_CTL1_reg))
#define  NF_DMA_SECU_CTL1_dram_sa_shift                                          (0)
#define  NF_DMA_SECU_CTL1_dram_sa_mask                                           (0x1FFFFFFF)
#define  NF_DMA_SECU_CTL1_dram_sa(data)                                          (0x1FFFFFFF&(data))
#define  NF_DMA_SECU_CTL1_get_dram_sa(data)                                      (0x1FFFFFFF&(data))

#define  NF_DMA_SECU_CTL2                                                        0x18010318
#define  NF_DMA_SECU_CTL2_reg_addr                                               "0xB8010318"
#define  NF_DMA_SECU_CTL2_reg                                                    0xB8010318
#define  NF_DMA_SECU_CTL2_inst_addr                                              "0x0050"
#define  set_NF_DMA_SECU_CTL2_reg(data)                                          (*((volatile unsigned int*)NF_DMA_SECU_CTL2_reg)=data)
#define  get_NF_DMA_SECU_CTL2_reg                                                (*((volatile unsigned int*)NF_DMA_SECU_CTL2_reg))
#define  NF_DMA_SECU_CTL2_dma_len_shift                                          (0)
#define  NF_DMA_SECU_CTL2_dma_len_mask                                           (0x0000FFFF)
#define  NF_DMA_SECU_CTL2_dma_len(data)                                          (0x0000FFFF&(data))
#define  NF_DMA_SECU_CTL2_get_dma_len(data)                                      (0x0000FFFF&(data))

#define  NF_DMA_SECU_CTL3                                                        0x1801031C
#define  NF_DMA_SECU_CTL3_reg_addr                                               "0xB801031C"
#define  NF_DMA_SECU_CTL3_reg                                                    0xB801031C
#define  NF_DMA_SECU_CTL3_inst_addr                                              "0x0051"
#define  set_NF_DMA_SECU_CTL3_reg(data)                                          (*((volatile unsigned int*)NF_DMA_SECU_CTL3_reg)=data)
#define  get_NF_DMA_SECU_CTL3_reg                                                (*((volatile unsigned int*)NF_DMA_SECU_CTL3_reg))
#define  NF_DMA_SECU_CTL3_cp_first_shift                                         (3)
#define  NF_DMA_SECU_CTL3_cp_enable_shift                                        (2)
#define  NF_DMA_SECU_CTL3_ddr_wr_shift                                           (1)
#define  NF_DMA_SECU_CTL3_dma_xfer_shift                                         (0)
#define  NF_DMA_SECU_CTL3_cp_first_mask                                          (0x00000008)
#define  NF_DMA_SECU_CTL3_cp_enable_mask                                         (0x00000004)
#define  NF_DMA_SECU_CTL3_ddr_wr_mask                                            (0x00000002)
#define  NF_DMA_SECU_CTL3_dma_xfer_mask                                          (0x00000001)
#define  NF_DMA_SECU_CTL3_cp_first(data)                                         (0x00000008&((data)<<3))
#define  NF_DMA_SECU_CTL3_cp_enable(data)                                        (0x00000004&((data)<<2))
#define  NF_DMA_SECU_CTL3_ddr_wr(data)                                           (0x00000002&((data)<<1))
#define  NF_DMA_SECU_CTL3_dma_xfer(data)                                         (0x00000001&(data))
#define  NF_DMA_SECU_CTL3_get_cp_first(data)                                     ((0x00000008&(data))>>3)
#define  NF_DMA_SECU_CTL3_get_cp_enable(data)                                    ((0x00000004&(data))>>2)
#define  NF_DMA_SECU_CTL3_get_ddr_wr(data)                                       ((0x00000002&(data))>>1)
#define  NF_DMA_SECU_CTL3_get_dma_xfer(data)                                     (0x00000001&(data))

#define  NF_NF_SECU_REQ                                                          0x18010320
#define  NF_NF_SECU_REQ_reg_addr                                                 "0xB8010320"
#define  NF_NF_SECU_REQ_reg                                                      0xB8010320
#define  NF_NF_SECU_REQ_inst_addr                                                "0x0052"
#define  set_NF_NF_SECU_REQ_reg(data)                                            (*((volatile unsigned int*)NF_NF_SECU_REQ_reg)=data)
#define  get_NF_NF_SECU_REQ_reg                                                  (*((volatile unsigned int*)NF_NF_SECU_REQ_reg))
#define  NF_NF_SECU_REQ_reg_lock_nf_sram_shift                                   (1)
#define  NF_NF_SECU_REQ_kcpu_nf_req_shift                                        (0)
#define  NF_NF_SECU_REQ_reg_lock_nf_sram_mask                                    (0x00000002)
#define  NF_NF_SECU_REQ_kcpu_nf_req_mask                                         (0x00000001)
#define  NF_NF_SECU_REQ_reg_lock_nf_sram(data)                                   (0x00000002&((data)<<1))
#define  NF_NF_SECU_REQ_kcpu_nf_req(data)                                        (0x00000001&(data))
#define  NF_NF_SECU_REQ_get_reg_lock_nf_sram(data)                               ((0x00000002&(data))>>1)
#define  NF_NF_SECU_REQ_get_kcpu_nf_req(data)                                    (0x00000001&(data))

#define  NF_NAND_KCPU_ISR                                                        0x18010324
#define  NF_NAND_KCPU_ISR_reg_addr                                               "0xB8010324"
#define  NF_NAND_KCPU_ISR_reg                                                    0xB8010324
#define  NF_NAND_KCPU_ISR_inst_addr                                              "0x0053"
#define  set_NF_NAND_KCPU_ISR_reg(data)                                          (*((volatile unsigned int*)NF_NAND_KCPU_ISR_reg)=data)
#define  get_NF_NAND_KCPU_ISR_reg                                                (*((volatile unsigned int*)NF_NAND_KCPU_ISR_reg))
#define  NF_NAND_KCPU_ISR_int8_shift                                             (8)
#define  NF_NAND_KCPU_ISR_int7_shift                                             (7)
#define  NF_NAND_KCPU_ISR_int6_shift                                             (6)
#define  NF_NAND_KCPU_ISR_int5_shift                                             (5)
#define  NF_NAND_KCPU_ISR_int4_shift                                             (4)
#define  NF_NAND_KCPU_ISR_int3_shift                                             (3)
#define  NF_NAND_KCPU_ISR_int2_shift                                             (2)
#define  NF_NAND_KCPU_ISR_int1_shift                                             (1)
#define  NF_NAND_KCPU_ISR_write_data_shift                                       (0)
#define  NF_NAND_KCPU_ISR_int8_mask                                              (0x00000100)
#define  NF_NAND_KCPU_ISR_int7_mask                                              (0x00000080)
#define  NF_NAND_KCPU_ISR_int6_mask                                              (0x00000040)
#define  NF_NAND_KCPU_ISR_int5_mask                                              (0x00000020)
#define  NF_NAND_KCPU_ISR_int4_mask                                              (0x00000010)
#define  NF_NAND_KCPU_ISR_int3_mask                                              (0x00000008)
#define  NF_NAND_KCPU_ISR_int2_mask                                              (0x00000004)
#define  NF_NAND_KCPU_ISR_int1_mask                                              (0x00000002)
#define  NF_NAND_KCPU_ISR_write_data_mask                                        (0x00000001)
#define  NF_NAND_KCPU_ISR_int8(data)                                             (0x00000100&((data)<<8))
#define  NF_NAND_KCPU_ISR_int7(data)                                             (0x00000080&((data)<<7))
#define  NF_NAND_KCPU_ISR_int6(data)                                             (0x00000040&((data)<<6))
#define  NF_NAND_KCPU_ISR_int5(data)                                             (0x00000020&((data)<<5))
#define  NF_NAND_KCPU_ISR_int4(data)                                             (0x00000010&((data)<<4))
#define  NF_NAND_KCPU_ISR_int3(data)                                             (0x00000008&((data)<<3))
#define  NF_NAND_KCPU_ISR_int2(data)                                             (0x00000004&((data)<<2))
#define  NF_NAND_KCPU_ISR_int1(data)                                             (0x00000002&((data)<<1))
#define  NF_NAND_KCPU_ISR_write_data(data)                                       (0x00000001&(data))
#define  NF_NAND_KCPU_ISR_get_int8(data)                                         ((0x00000100&(data))>>8)
#define  NF_NAND_KCPU_ISR_get_int7(data)                                         ((0x00000080&(data))>>7)
#define  NF_NAND_KCPU_ISR_get_int6(data)                                         ((0x00000040&(data))>>6)
#define  NF_NAND_KCPU_ISR_get_int5(data)                                         ((0x00000020&(data))>>5)
#define  NF_NAND_KCPU_ISR_get_int4(data)                                         ((0x00000010&(data))>>4)
#define  NF_NAND_KCPU_ISR_get_int3(data)                                         ((0x00000008&(data))>>3)
#define  NF_NAND_KCPU_ISR_get_int2(data)                                         ((0x00000004&(data))>>2)
#define  NF_NAND_KCPU_ISR_get_int1(data)                                         ((0x00000002&(data))>>1)
#define  NF_NAND_KCPU_ISR_get_write_data(data)                                   (0x00000001&(data))

#define  NF_NAND_KCPU_ISREN                                                      0x18010328
#define  NF_NAND_KCPU_ISREN_reg_addr                                             "0xB8010328"
#define  NF_NAND_KCPU_ISREN_reg                                                  0xB8010328
#define  NF_NAND_KCPU_ISREN_inst_addr                                            "0x0054"
#define  set_NF_NAND_KCPU_ISREN_reg(data)                                        (*((volatile unsigned int*)NF_NAND_KCPU_ISREN_reg)=data)
#define  get_NF_NAND_KCPU_ISREN_reg                                              (*((volatile unsigned int*)NF_NAND_KCPU_ISREN_reg))
#define  NF_NAND_KCPU_ISREN_int8en_shift                                         (8)
#define  NF_NAND_KCPU_ISREN_int7en_shift                                         (7)
#define  NF_NAND_KCPU_ISREN_int6en_shift                                         (6)
#define  NF_NAND_KCPU_ISREN_int5en_shift                                         (5)
#define  NF_NAND_KCPU_ISREN_int4en_shift                                         (4)
#define  NF_NAND_KCPU_ISREN_int3en_shift                                         (3)
#define  NF_NAND_KCPU_ISREN_int2en_shift                                         (2)
#define  NF_NAND_KCPU_ISREN_int1en_shift                                         (1)
#define  NF_NAND_KCPU_ISREN_write_data_shift                                     (0)
#define  NF_NAND_KCPU_ISREN_int8en_mask                                          (0x00000100)
#define  NF_NAND_KCPU_ISREN_int7en_mask                                          (0x00000080)
#define  NF_NAND_KCPU_ISREN_int6en_mask                                          (0x00000040)
#define  NF_NAND_KCPU_ISREN_int5en_mask                                          (0x00000020)
#define  NF_NAND_KCPU_ISREN_int4en_mask                                          (0x00000010)
#define  NF_NAND_KCPU_ISREN_int3en_mask                                          (0x00000008)
#define  NF_NAND_KCPU_ISREN_int2en_mask                                          (0x00000004)
#define  NF_NAND_KCPU_ISREN_int1en_mask                                          (0x00000002)
#define  NF_NAND_KCPU_ISREN_write_data_mask                                      (0x00000001)
#define  NF_NAND_KCPU_ISREN_int8en(data)                                         (0x00000100&((data)<<8))
#define  NF_NAND_KCPU_ISREN_int7en(data)                                         (0x00000080&((data)<<7))
#define  NF_NAND_KCPU_ISREN_int6en(data)                                         (0x00000040&((data)<<6))
#define  NF_NAND_KCPU_ISREN_int5en(data)                                         (0x00000020&((data)<<5))
#define  NF_NAND_KCPU_ISREN_int4en(data)                                         (0x00000010&((data)<<4))
#define  NF_NAND_KCPU_ISREN_int3en(data)                                         (0x00000008&((data)<<3))
#define  NF_NAND_KCPU_ISREN_int2en(data)                                         (0x00000004&((data)<<2))
#define  NF_NAND_KCPU_ISREN_int1en(data)                                         (0x00000002&((data)<<1))
#define  NF_NAND_KCPU_ISREN_write_data(data)                                     (0x00000001&(data))
#define  NF_NAND_KCPU_ISREN_get_int8en(data)                                     ((0x00000100&(data))>>8)
#define  NF_NAND_KCPU_ISREN_get_int7en(data)                                     ((0x00000080&(data))>>7)
#define  NF_NAND_KCPU_ISREN_get_int6en(data)                                     ((0x00000040&(data))>>6)
#define  NF_NAND_KCPU_ISREN_get_int5en(data)                                     ((0x00000020&(data))>>5)
#define  NF_NAND_KCPU_ISREN_get_int4en(data)                                     ((0x00000010&(data))>>4)
#define  NF_NAND_KCPU_ISREN_get_int3en(data)                                     ((0x00000008&(data))>>3)
#define  NF_NAND_KCPU_ISREN_get_int2en(data)                                     ((0x00000004&(data))>>2)
#define  NF_NAND_KCPU_ISREN_get_int1en(data)                                     ((0x00000002&(data))>>1)
#define  NF_NAND_KCPU_ISREN_get_write_data(data)                                 (0x00000001&(data))

#define  NF_DUMMY_SYS                                                            0x1801032C
#define  NF_DUMMY_SYS_reg_addr                                                   "0xB801032C"
#define  NF_DUMMY_SYS_reg                                                        0xB801032C
#define  NF_DUMMY_SYS_inst_addr                                                  "0x0055"
#define  set_NF_DUMMY_SYS_reg(data)                                              (*((volatile unsigned int*)NF_DUMMY_SYS_reg)=data)
#define  get_NF_DUMMY_SYS_reg                                                    (*((volatile unsigned int*)NF_DUMMY_SYS_reg))
#define  NF_DUMMY_SYS_dmy_shift                                                  (0)
#define  NF_DUMMY_SYS_dmy_mask                                                   (0xFFFFFFFF)
#define  NF_DUMMY_SYS_dmy(data)                                                  (0xFFFFFFFF&(data))
#define  NF_DUMMY_SYS_get_dmy(data)                                              (0xFFFFFFFF&(data))

#define  NF_CP_NF_CR_MUX                                                         0x18010330
#define  NF_CP_NF_CR_MUX_reg_addr                                                "0xB8010330"
#define  NF_CP_NF_CR_MUX_reg                                                     0xB8010330
#define  NF_CP_NF_CR_MUX_inst_addr                                               "0x0056"
#define  set_NF_CP_NF_CR_MUX_reg(data)                                           (*((volatile unsigned int*)NF_CP_NF_CR_MUX_reg)=data)
#define  get_NF_CP_NF_CR_MUX_reg                                                 (*((volatile unsigned int*)NF_CP_NF_CR_MUX_reg))
#define  NF_CP_NF_CR_MUX_dummy_0_shift                                           (0)
#define  NF_CP_NF_CR_MUX_dummy_0_mask                                            (0x00000001)
#define  NF_CP_NF_CR_MUX_dummy_0(data)                                           (0x00000001&(data))
#define  NF_CP_NF_CR_MUX_get_dummy_0(data)                                       (0x00000001&(data))

#define  NF_NF_MULTI_CPU_ST                                                      0x18010334
#define  NF_NF_MULTI_CPU_ST_reg_addr                                             "0xB8010334"
#define  NF_NF_MULTI_CPU_ST_reg                                                  0xB8010334
#define  NF_NF_MULTI_CPU_ST_inst_addr                                            "0x0057"
#define  set_NF_NF_MULTI_CPU_ST_reg(data)                                        (*((volatile unsigned int*)NF_NF_MULTI_CPU_ST_reg)=data)
#define  get_NF_NF_MULTI_CPU_ST_reg                                              (*((volatile unsigned int*)NF_NF_MULTI_CPU_ST_reg))
#define  NF_NF_MULTI_CPU_ST_xcpu_nf_req_shift                                    (2)
#define  NF_NF_MULTI_CPU_ST_kcpu_occupy_shift                                    (1)
#define  NF_NF_MULTI_CPU_ST_xcpu_occupy_shift                                    (0)
#define  NF_NF_MULTI_CPU_ST_xcpu_nf_req_mask                                     (0x00000004)
#define  NF_NF_MULTI_CPU_ST_kcpu_occupy_mask                                     (0x00000002)
#define  NF_NF_MULTI_CPU_ST_xcpu_occupy_mask                                     (0x00000001)
#define  NF_NF_MULTI_CPU_ST_xcpu_nf_req(data)                                    (0x00000004&((data)<<2))
#define  NF_NF_MULTI_CPU_ST_kcpu_occupy(data)                                    (0x00000002&((data)<<1))
#define  NF_NF_MULTI_CPU_ST_xcpu_occupy(data)                                    (0x00000001&(data))
#define  NF_NF_MULTI_CPU_ST_get_xcpu_nf_req(data)                                ((0x00000004&(data))>>2)
#define  NF_NF_MULTI_CPU_ST_get_kcpu_occupy(data)                                ((0x00000002&(data))>>1)
#define  NF_NF_MULTI_CPU_ST_get_xcpu_occupy(data)                                (0x00000001&(data))

#define  NF_NAND_ISR                                                             0x18010338
#define  NF_NAND_ISR_reg_addr                                                    "0xB8010338"
#define  NF_NAND_ISR_reg                                                         0xB8010338
#define  NF_NAND_ISR_inst_addr                                                   "0x0058"
#define  set_NF_NAND_ISR_reg(data)                                               (*((volatile unsigned int*)NF_NAND_ISR_reg)=data)
#define  get_NF_NAND_ISR_reg                                                     (*((volatile unsigned int*)NF_NAND_ISR_reg))
#define  NF_NAND_ISR_int8_shift                                                  (8)
#define  NF_NAND_ISR_int7_shift                                                  (7)
#define  NF_NAND_ISR_int5_shift                                                  (5)
#define  NF_NAND_ISR_int4_shift                                                  (4)
#define  NF_NAND_ISR_int3_shift                                                  (3)
#define  NF_NAND_ISR_int2_shift                                                  (2)
#define  NF_NAND_ISR_int1_shift                                                  (1)
#define  NF_NAND_ISR_write_data_shift                                            (0)
#define  NF_NAND_ISR_int8_mask                                                   (0x00000100)
#define  NF_NAND_ISR_int7_mask                                                   (0x00000080)
#define  NF_NAND_ISR_int5_mask                                                   (0x00000020)
#define  NF_NAND_ISR_int4_mask                                                   (0x00000010)
#define  NF_NAND_ISR_int3_mask                                                   (0x00000008)
#define  NF_NAND_ISR_int2_mask                                                   (0x00000004)
#define  NF_NAND_ISR_int1_mask                                                   (0x00000002)
#define  NF_NAND_ISR_write_data_mask                                             (0x00000001)
#define  NF_NAND_ISR_int8(data)                                                  (0x00000100&((data)<<8))
#define  NF_NAND_ISR_int7(data)                                                  (0x00000080&((data)<<7))
#define  NF_NAND_ISR_int5(data)                                                  (0x00000020&((data)<<5))
#define  NF_NAND_ISR_int4(data)                                                  (0x00000010&((data)<<4))
#define  NF_NAND_ISR_int3(data)                                                  (0x00000008&((data)<<3))
#define  NF_NAND_ISR_int2(data)                                                  (0x00000004&((data)<<2))
#define  NF_NAND_ISR_int1(data)                                                  (0x00000002&((data)<<1))
#define  NF_NAND_ISR_write_data(data)                                            (0x00000001&(data))
#define  NF_NAND_ISR_get_int8(data)                                              ((0x00000100&(data))>>8)
#define  NF_NAND_ISR_get_int7(data)                                              ((0x00000080&(data))>>7)
#define  NF_NAND_ISR_get_int5(data)                                              ((0x00000020&(data))>>5)
#define  NF_NAND_ISR_get_int4(data)                                              ((0x00000010&(data))>>4)
#define  NF_NAND_ISR_get_int3(data)                                              ((0x00000008&(data))>>3)
#define  NF_NAND_ISR_get_int2(data)                                              ((0x00000004&(data))>>2)
#define  NF_NAND_ISR_get_int1(data)                                              ((0x00000002&(data))>>1)
#define  NF_NAND_ISR_get_write_data(data)                                        (0x00000001&(data))

#define  NF_NAND_ISREN                                                           0x1801033C
#define  NF_NAND_ISREN_reg_addr                                                  "0xB801033C"
#define  NF_NAND_ISREN_reg                                                       0xB801033C
#define  NF_NAND_ISREN_inst_addr                                                 "0x0059"
#define  set_NF_NAND_ISREN_reg(data)                                             (*((volatile unsigned int*)NF_NAND_ISREN_reg)=data)
#define  get_NF_NAND_ISREN_reg                                                   (*((volatile unsigned int*)NF_NAND_ISREN_reg))
#define  NF_NAND_ISREN_int8en_shift                                              (8)
#define  NF_NAND_ISREN_int7en_shift                                              (7)
#define  NF_NAND_ISREN_int5en_shift                                              (5)
#define  NF_NAND_ISREN_int4en_shift                                              (4)
#define  NF_NAND_ISREN_int3en_shift                                              (3)
#define  NF_NAND_ISREN_int2en_shift                                              (2)
#define  NF_NAND_ISREN_int1en_shift                                              (1)
#define  NF_NAND_ISREN_write_data_shift                                          (0)
#define  NF_NAND_ISREN_int8en_mask                                               (0x00000100)
#define  NF_NAND_ISREN_int7en_mask                                               (0x00000080)
#define  NF_NAND_ISREN_int5en_mask                                               (0x00000020)
#define  NF_NAND_ISREN_int4en_mask                                               (0x00000010)
#define  NF_NAND_ISREN_int3en_mask                                               (0x00000008)
#define  NF_NAND_ISREN_int2en_mask                                               (0x00000004)
#define  NF_NAND_ISREN_int1en_mask                                               (0x00000002)
#define  NF_NAND_ISREN_write_data_mask                                           (0x00000001)
#define  NF_NAND_ISREN_int8en(data)                                              (0x00000100&((data)<<8))
#define  NF_NAND_ISREN_int7en(data)                                              (0x00000080&((data)<<7))
#define  NF_NAND_ISREN_int5en(data)                                              (0x00000020&((data)<<5))
#define  NF_NAND_ISREN_int4en(data)                                              (0x00000010&((data)<<4))
#define  NF_NAND_ISREN_int3en(data)                                              (0x00000008&((data)<<3))
#define  NF_NAND_ISREN_int2en(data)                                              (0x00000004&((data)<<2))
#define  NF_NAND_ISREN_int1en(data)                                              (0x00000002&((data)<<1))
#define  NF_NAND_ISREN_write_data(data)                                          (0x00000001&(data))
#define  NF_NAND_ISREN_get_int8en(data)                                          ((0x00000100&(data))>>8)
#define  NF_NAND_ISREN_get_int7en(data)                                          ((0x00000080&(data))>>7)
#define  NF_NAND_ISREN_get_int5en(data)                                          ((0x00000020&(data))>>5)
#define  NF_NAND_ISREN_get_int4en(data)                                          ((0x00000010&(data))>>4)
#define  NF_NAND_ISREN_get_int3en(data)                                          ((0x00000008&(data))>>3)
#define  NF_NAND_ISREN_get_int2en(data)                                          ((0x00000004&(data))>>2)
#define  NF_NAND_ISREN_get_int1en(data)                                          ((0x00000002&(data))>>1)
#define  NF_NAND_ISREN_get_write_data(data)                                      (0x00000001&(data))

#define  NF_DBG                                                                  0x18010344
#define  NF_DBG_reg_addr                                                         "0xB8010344"
#define  NF_DBG_reg                                                              0xB8010344
#define  NF_DBG_inst_addr                                                        "0x005A"
#define  set_NF_DBG_reg(data)                                                    (*((volatile unsigned int*)NF_DBG_reg)=data)
#define  get_NF_DBG_reg                                                          (*((volatile unsigned int*)NF_DBG_reg))
#define  NF_DBG_write_enable3_shift                                              (9)
#define  NF_DBG_sel1_shift                                                       (6)
#define  NF_DBG_write_enable2_shift                                              (5)
#define  NF_DBG_sel0_shift                                                       (2)
#define  NF_DBG_write_enable1_shift                                              (1)
#define  NF_DBG_enable_shift                                                     (0)
#define  NF_DBG_write_enable3_mask                                               (0x00000200)
#define  NF_DBG_sel1_mask                                                        (0x000001C0)
#define  NF_DBG_write_enable2_mask                                               (0x00000020)
#define  NF_DBG_sel0_mask                                                        (0x0000001C)
#define  NF_DBG_write_enable1_mask                                               (0x00000002)
#define  NF_DBG_enable_mask                                                      (0x00000001)
#define  NF_DBG_write_enable3(data)                                              (0x00000200&((data)<<9))
#define  NF_DBG_sel1(data)                                                       (0x000001C0&((data)<<6))
#define  NF_DBG_write_enable2(data)                                              (0x00000020&((data)<<5))
#define  NF_DBG_sel0(data)                                                       (0x0000001C&((data)<<2))
#define  NF_DBG_write_enable1(data)                                              (0x00000002&((data)<<1))
#define  NF_DBG_enable(data)                                                     (0x00000001&(data))
#define  NF_DBG_get_write_enable3(data)                                          ((0x00000200&(data))>>9)
#define  NF_DBG_get_sel1(data)                                                   ((0x000001C0&(data))>>6)
#define  NF_DBG_get_write_enable2(data)                                          ((0x00000020&(data))>>5)
#define  NF_DBG_get_sel0(data)                                                   ((0x0000001C&(data))>>2)
#define  NF_DBG_get_write_enable1(data)                                          ((0x00000002&(data))>>1)
#define  NF_DBG_get_enable(data)                                                 (0x00000001&(data))

#define  NF_SPR_DDR_CTL                                                          0x18010348
#define  NF_SPR_DDR_CTL_reg_addr                                                 "0xB8010348"
#define  NF_SPR_DDR_CTL_reg                                                      0xB8010348
#define  NF_SPR_DDR_CTL_inst_addr                                                "0x005B"
#define  set_NF_SPR_DDR_CTL_reg(data)                                            (*((volatile unsigned int*)NF_SPR_DDR_CTL_reg)=data)
#define  get_NF_SPR_DDR_CTL_reg                                                  (*((volatile unsigned int*)NF_SPR_DDR_CTL_reg))
#define  NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena_shift                                (31)
#define  NF_SPR_DDR_CTL_spare_ddr_ena_shift                                      (30)
#define  NF_SPR_DDR_CTL_per_2k_spr_ena_shift                                     (29)
#define  NF_SPR_DDR_CTL_spare_dram_sa_shift                                      (0)
#define  NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena_mask                                 (0x80000000)
#define  NF_SPR_DDR_CTL_spare_ddr_ena_mask                                       (0x40000000)
#define  NF_SPR_DDR_CTL_per_2k_spr_ena_mask                                      (0x20000000)
#define  NF_SPR_DDR_CTL_spare_dram_sa_mask                                       (0x1FFFFFFF)
#define  NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(data)                                (0x80000000&((data)<<31))
#define  NF_SPR_DDR_CTL_spare_ddr_ena(data)                                      (0x40000000&((data)<<30))
#define  NF_SPR_DDR_CTL_per_2k_spr_ena(data)                                     (0x20000000&((data)<<29))
#define  NF_SPR_DDR_CTL_spare_dram_sa(data)                                      (0x1FFFFFFF&(data))
#define  NF_SPR_DDR_CTL_get_cr_nf_hw_pinmux_ena(data)                            ((0x80000000&(data))>>31)
#define  NF_SPR_DDR_CTL_get_spare_ddr_ena(data)                                  ((0x40000000&(data))>>30)
#define  NF_SPR_DDR_CTL_get_per_2k_spr_ena(data)                                 ((0x20000000&(data))>>29)
#define  NF_SPR_DDR_CTL_get_spare_dram_sa(data)                                  (0x1FFFFFFF&(data))

#define  NF_CP_LEN                                                               0x1801034C
#define  NF_CP_LEN_reg_addr                                                      "0xB801034C"
#define  NF_CP_LEN_reg                                                           0xB801034C
#define  NF_CP_LEN_inst_addr                                                     "0x005C"
#define  set_NF_CP_LEN_reg(data)                                                 (*((volatile unsigned int*)NF_CP_LEN_reg)=data)
#define  get_NF_CP_LEN_reg                                                       (*((volatile unsigned int*)NF_CP_LEN_reg))
#define  NF_CP_LEN_cp_length_shift                                               (9)
#define  NF_CP_LEN_cp_length_mask                                                (0x01FFFE00)
#define  NF_CP_LEN_cp_length(data)                                               (0x01FFFE00&((data)<<9))
#define  NF_CP_LEN_get_cp_length(data)                                           ((0x01FFFE00&(data))>>9)

#define  NF_NF_BIST_MODE                                                         0x18010350
#define  NF_NF_BIST_MODE_reg_addr                                                "0xB8010350"
#define  NF_NF_BIST_MODE_reg                                                     0xB8010350
#define  NF_NF_BIST_MODE_inst_addr                                               "0x005D"
#define  set_NF_NF_BIST_MODE_reg(data)                                           (*((volatile unsigned int*)NF_NF_BIST_MODE_reg)=data)
#define  get_NF_NF_BIST_MODE_reg                                                 (*((volatile unsigned int*)NF_NF_BIST_MODE_reg))
#define  NF_NF_BIST_MODE_nf_pp_bist_mode_shift                                   (1)
#define  NF_NF_BIST_MODE_nf_dma_bist_mode_shift                                  (0)
#define  NF_NF_BIST_MODE_nf_pp_bist_mode_mask                                    (0x00000002)
#define  NF_NF_BIST_MODE_nf_dma_bist_mode_mask                                   (0x00000001)
#define  NF_NF_BIST_MODE_nf_pp_bist_mode(data)                                   (0x00000002&((data)<<1))
#define  NF_NF_BIST_MODE_nf_dma_bist_mode(data)                                  (0x00000001&(data))
#define  NF_NF_BIST_MODE_get_nf_pp_bist_mode(data)                               ((0x00000002&(data))>>1)
#define  NF_NF_BIST_MODE_get_nf_dma_bist_mode(data)                              (0x00000001&(data))

#define  NF_NF_BIST_DONE                                                         0x18010354
#define  NF_NF_BIST_DONE_reg_addr                                                "0xB8010354"
#define  NF_NF_BIST_DONE_reg                                                     0xB8010354
#define  NF_NF_BIST_DONE_inst_addr                                               "0x005E"
#define  set_NF_NF_BIST_DONE_reg(data)                                           (*((volatile unsigned int*)NF_NF_BIST_DONE_reg)=data)
#define  get_NF_NF_BIST_DONE_reg                                                 (*((volatile unsigned int*)NF_NF_BIST_DONE_reg))
#define  NF_NF_BIST_DONE_nf_pp_bist_done_shift                                   (1)
#define  NF_NF_BIST_DONE_nf_dma_bist_done_shift                                  (0)
#define  NF_NF_BIST_DONE_nf_pp_bist_done_mask                                    (0x00000002)
#define  NF_NF_BIST_DONE_nf_dma_bist_done_mask                                   (0x00000001)
#define  NF_NF_BIST_DONE_nf_pp_bist_done(data)                                   (0x00000002&((data)<<1))
#define  NF_NF_BIST_DONE_nf_dma_bist_done(data)                                  (0x00000001&(data))
#define  NF_NF_BIST_DONE_get_nf_pp_bist_done(data)                               ((0x00000002&(data))>>1)
#define  NF_NF_BIST_DONE_get_nf_dma_bist_done(data)                              (0x00000001&(data))

#define  NF_NF_BIST_FAIL_GROUP                                                   0x18010358
#define  NF_NF_BIST_FAIL_GROUP_reg_addr                                          "0xB8010358"
#define  NF_NF_BIST_FAIL_GROUP_reg                                               0xB8010358
#define  NF_NF_BIST_FAIL_GROUP_inst_addr                                         "0x005F"
#define  set_NF_NF_BIST_FAIL_GROUP_reg(data)                                     (*((volatile unsigned int*)NF_NF_BIST_FAIL_GROUP_reg)=data)
#define  get_NF_NF_BIST_FAIL_GROUP_reg                                           (*((volatile unsigned int*)NF_NF_BIST_FAIL_GROUP_reg))
#define  NF_NF_BIST_FAIL_GROUP_nf_pp_bist_fail_group_shift                       (1)
#define  NF_NF_BIST_FAIL_GROUP_nf_dma_bist_fail_group_shift                      (0)
#define  NF_NF_BIST_FAIL_GROUP_nf_pp_bist_fail_group_mask                        (0x00000002)
#define  NF_NF_BIST_FAIL_GROUP_nf_dma_bist_fail_group_mask                       (0x00000001)
#define  NF_NF_BIST_FAIL_GROUP_nf_pp_bist_fail_group(data)                       (0x00000002&((data)<<1))
#define  NF_NF_BIST_FAIL_GROUP_nf_dma_bist_fail_group(data)                      (0x00000001&(data))
#define  NF_NF_BIST_FAIL_GROUP_get_nf_pp_bist_fail_group(data)                   ((0x00000002&(data))>>1)
#define  NF_NF_BIST_FAIL_GROUP_get_nf_dma_bist_fail_group(data)                  (0x00000001&(data))

#define  NF_NF_BIST_NF_FAIL                                                      0x1801035C
#define  NF_NF_BIST_NF_FAIL_reg_addr                                             "0xB801035C"
#define  NF_NF_BIST_NF_FAIL_reg                                                  0xB801035C
#define  NF_NF_BIST_NF_FAIL_inst_addr                                            "0x0060"
#define  set_NF_NF_BIST_NF_FAIL_reg(data)                                        (*((volatile unsigned int*)NF_NF_BIST_NF_FAIL_reg)=data)
#define  get_NF_NF_BIST_NF_FAIL_reg                                              (*((volatile unsigned int*)NF_NF_BIST_NF_FAIL_reg))
#define  NF_NF_BIST_NF_FAIL_nf_bist_nf_fail_2_shift                              (2)
#define  NF_NF_BIST_NF_FAIL_nf_bist_nf_fail_1_shift                              (1)
#define  NF_NF_BIST_NF_FAIL_nf_bist_nf_fail_0_shift                              (0)
#define  NF_NF_BIST_NF_FAIL_nf_bist_nf_fail_2_mask                               (0x00000004)
#define  NF_NF_BIST_NF_FAIL_nf_bist_nf_fail_1_mask                               (0x00000002)
#define  NF_NF_BIST_NF_FAIL_nf_bist_nf_fail_0_mask                               (0x00000001)
#define  NF_NF_BIST_NF_FAIL_nf_bist_nf_fail_2(data)                              (0x00000004&((data)<<2))
#define  NF_NF_BIST_NF_FAIL_nf_bist_nf_fail_1(data)                              (0x00000002&((data)<<1))
#define  NF_NF_BIST_NF_FAIL_nf_bist_nf_fail_0(data)                              (0x00000001&(data))
#define  NF_NF_BIST_NF_FAIL_get_nf_bist_nf_fail_2(data)                          ((0x00000004&(data))>>2)
#define  NF_NF_BIST_NF_FAIL_get_nf_bist_nf_fail_1(data)                          ((0x00000002&(data))>>1)
#define  NF_NF_BIST_NF_FAIL_get_nf_bist_nf_fail_0(data)                          (0x00000001&(data))

#define  NF_NF_DRF_MODE                                                          0x18010360
#define  NF_NF_DRF_MODE_reg_addr                                                 "0xB8010360"
#define  NF_NF_DRF_MODE_reg                                                      0xB8010360
#define  NF_NF_DRF_MODE_inst_addr                                                "0x0061"
#define  set_NF_NF_DRF_MODE_reg(data)                                            (*((volatile unsigned int*)NF_NF_DRF_MODE_reg)=data)
#define  get_NF_NF_DRF_MODE_reg                                                  (*((volatile unsigned int*)NF_NF_DRF_MODE_reg))
#define  NF_NF_DRF_MODE_nf_pp_drf_mode_shift                                     (1)
#define  NF_NF_DRF_MODE_nf_dma_drf_mode_shift                                    (0)
#define  NF_NF_DRF_MODE_nf_pp_drf_mode_mask                                      (0x00000002)
#define  NF_NF_DRF_MODE_nf_dma_drf_mode_mask                                     (0x00000001)
#define  NF_NF_DRF_MODE_nf_pp_drf_mode(data)                                     (0x00000002&((data)<<1))
#define  NF_NF_DRF_MODE_nf_dma_drf_mode(data)                                    (0x00000001&(data))
#define  NF_NF_DRF_MODE_get_nf_pp_drf_mode(data)                                 ((0x00000002&(data))>>1)
#define  NF_NF_DRF_MODE_get_nf_dma_drf_mode(data)                                (0x00000001&(data))

#define  NF_NF_DRF_RESUME                                                        0x18010364
#define  NF_NF_DRF_RESUME_reg_addr                                               "0xB8010364"
#define  NF_NF_DRF_RESUME_reg                                                    0xB8010364
#define  NF_NF_DRF_RESUME_inst_addr                                              "0x0062"
#define  set_NF_NF_DRF_RESUME_reg(data)                                          (*((volatile unsigned int*)NF_NF_DRF_RESUME_reg)=data)
#define  get_NF_NF_DRF_RESUME_reg                                                (*((volatile unsigned int*)NF_NF_DRF_RESUME_reg))
#define  NF_NF_DRF_RESUME_nf_pp_drf_resume_shift                                 (1)
#define  NF_NF_DRF_RESUME_nf_dma_drf_resume_shift                                (0)
#define  NF_NF_DRF_RESUME_nf_pp_drf_resume_mask                                  (0x00000002)
#define  NF_NF_DRF_RESUME_nf_dma_drf_resume_mask                                 (0x00000001)
#define  NF_NF_DRF_RESUME_nf_pp_drf_resume(data)                                 (0x00000002&((data)<<1))
#define  NF_NF_DRF_RESUME_nf_dma_drf_resume(data)                                (0x00000001&(data))
#define  NF_NF_DRF_RESUME_get_nf_pp_drf_resume(data)                             ((0x00000002&(data))>>1)
#define  NF_NF_DRF_RESUME_get_nf_dma_drf_resume(data)                            (0x00000001&(data))

#define  NF_NF_DRF_DONE                                                          0x18010368
#define  NF_NF_DRF_DONE_reg_addr                                                 "0xB8010368"
#define  NF_NF_DRF_DONE_reg                                                      0xB8010368
#define  NF_NF_DRF_DONE_inst_addr                                                "0x0063"
#define  set_NF_NF_DRF_DONE_reg(data)                                            (*((volatile unsigned int*)NF_NF_DRF_DONE_reg)=data)
#define  get_NF_NF_DRF_DONE_reg                                                  (*((volatile unsigned int*)NF_NF_DRF_DONE_reg))
#define  NF_NF_DRF_DONE_nf_pp_drf_done_shift                                     (1)
#define  NF_NF_DRF_DONE_nf_dma_drf_done_shift                                    (0)
#define  NF_NF_DRF_DONE_nf_pp_drf_done_mask                                      (0x00000002)
#define  NF_NF_DRF_DONE_nf_dma_drf_done_mask                                     (0x00000001)
#define  NF_NF_DRF_DONE_nf_pp_drf_done(data)                                     (0x00000002&((data)<<1))
#define  NF_NF_DRF_DONE_nf_dma_drf_done(data)                                    (0x00000001&(data))
#define  NF_NF_DRF_DONE_get_nf_pp_drf_done(data)                                 ((0x00000002&(data))>>1)
#define  NF_NF_DRF_DONE_get_nf_dma_drf_done(data)                                (0x00000001&(data))

#define  NF_NF_DRF_PAUSE                                                         0x1801036C
#define  NF_NF_DRF_PAUSE_reg_addr                                                "0xB801036C"
#define  NF_NF_DRF_PAUSE_reg                                                     0xB801036C
#define  NF_NF_DRF_PAUSE_inst_addr                                               "0x0064"
#define  set_NF_NF_DRF_PAUSE_reg(data)                                           (*((volatile unsigned int*)NF_NF_DRF_PAUSE_reg)=data)
#define  get_NF_NF_DRF_PAUSE_reg                                                 (*((volatile unsigned int*)NF_NF_DRF_PAUSE_reg))
#define  NF_NF_DRF_PAUSE_nf_pp_drf_pause_shift                                   (1)
#define  NF_NF_DRF_PAUSE_nf_dma_drf_pause_shift                                  (0)
#define  NF_NF_DRF_PAUSE_nf_pp_drf_pause_mask                                    (0x00000002)
#define  NF_NF_DRF_PAUSE_nf_dma_drf_pause_mask                                   (0x00000001)
#define  NF_NF_DRF_PAUSE_nf_pp_drf_pause(data)                                   (0x00000002&((data)<<1))
#define  NF_NF_DRF_PAUSE_nf_dma_drf_pause(data)                                  (0x00000001&(data))
#define  NF_NF_DRF_PAUSE_get_nf_pp_drf_pause(data)                               ((0x00000002&(data))>>1)
#define  NF_NF_DRF_PAUSE_get_nf_dma_drf_pause(data)                              (0x00000001&(data))

#define  NF_NF_DRF_FAIL_GROUP                                                    0x18010370
#define  NF_NF_DRF_FAIL_GROUP_reg_addr                                           "0xB8010370"
#define  NF_NF_DRF_FAIL_GROUP_reg                                                0xB8010370
#define  NF_NF_DRF_FAIL_GROUP_inst_addr                                          "0x0065"
#define  set_NF_NF_DRF_FAIL_GROUP_reg(data)                                      (*((volatile unsigned int*)NF_NF_DRF_FAIL_GROUP_reg)=data)
#define  get_NF_NF_DRF_FAIL_GROUP_reg                                            (*((volatile unsigned int*)NF_NF_DRF_FAIL_GROUP_reg))
#define  NF_NF_DRF_FAIL_GROUP_nf_pp_drf_fail_group_shift                         (1)
#define  NF_NF_DRF_FAIL_GROUP_nf_dma_drf_fail_group_shift                        (0)
#define  NF_NF_DRF_FAIL_GROUP_nf_pp_drf_fail_group_mask                          (0x00000002)
#define  NF_NF_DRF_FAIL_GROUP_nf_dma_drf_fail_group_mask                         (0x00000001)
#define  NF_NF_DRF_FAIL_GROUP_nf_pp_drf_fail_group(data)                         (0x00000002&((data)<<1))
#define  NF_NF_DRF_FAIL_GROUP_nf_dma_drf_fail_group(data)                        (0x00000001&(data))
#define  NF_NF_DRF_FAIL_GROUP_get_nf_pp_drf_fail_group(data)                     ((0x00000002&(data))>>1)
#define  NF_NF_DRF_FAIL_GROUP_get_nf_dma_drf_fail_group(data)                    (0x00000001&(data))

#define  NF_NF_DRF_NF_FAIL                                                       0x18010374
#define  NF_NF_DRF_NF_FAIL_reg_addr                                              "0xB8010374"
#define  NF_NF_DRF_NF_FAIL_reg                                                   0xB8010374
#define  NF_NF_DRF_NF_FAIL_inst_addr                                             "0x0066"
#define  set_NF_NF_DRF_NF_FAIL_reg(data)                                         (*((volatile unsigned int*)NF_NF_DRF_NF_FAIL_reg)=data)
#define  get_NF_NF_DRF_NF_FAIL_reg                                               (*((volatile unsigned int*)NF_NF_DRF_NF_FAIL_reg))
#define  NF_NF_DRF_NF_FAIL_nf_drf_nf_fail_2_shift                                (2)
#define  NF_NF_DRF_NF_FAIL_nf_drf_nf_fail_1_shift                                (1)
#define  NF_NF_DRF_NF_FAIL_nf_drf_nf_fail_0_shift                                (0)
#define  NF_NF_DRF_NF_FAIL_nf_drf_nf_fail_2_mask                                 (0x00000004)
#define  NF_NF_DRF_NF_FAIL_nf_drf_nf_fail_1_mask                                 (0x00000002)
#define  NF_NF_DRF_NF_FAIL_nf_drf_nf_fail_0_mask                                 (0x00000001)
#define  NF_NF_DRF_NF_FAIL_nf_drf_nf_fail_2(data)                                (0x00000004&((data)<<2))
#define  NF_NF_DRF_NF_FAIL_nf_drf_nf_fail_1(data)                                (0x00000002&((data)<<1))
#define  NF_NF_DRF_NF_FAIL_nf_drf_nf_fail_0(data)                                (0x00000001&(data))
#define  NF_NF_DRF_NF_FAIL_get_nf_drf_nf_fail_2(data)                            ((0x00000004&(data))>>2)
#define  NF_NF_DRF_NF_FAIL_get_nf_drf_nf_fail_1(data)                            ((0x00000002&(data))>>1)
#define  NF_NF_DRF_NF_FAIL_get_nf_drf_nf_fail_0(data)                            (0x00000001&(data))

#define  NF_NF_SRAM_CTL                                                          0x18010378
#define  NF_NF_SRAM_CTL_reg_addr                                                 "0xB8010378"
#define  NF_NF_SRAM_CTL_reg                                                      0xB8010378
#define  NF_NF_SRAM_CTL_inst_addr                                                "0x0067"
#define  set_NF_NF_SRAM_CTL_reg(data)                                            (*((volatile unsigned int*)NF_NF_SRAM_CTL_reg)=data)
#define  get_NF_NF_SRAM_CTL_reg                                                  (*((volatile unsigned int*)NF_NF_SRAM_CTL_reg))
#define  NF_NF_SRAM_CTL_nf_sram_ls_shift                                         (15)
#define  NF_NF_SRAM_CTL_dma1_sram_rm_shift                                       (11)
#define  NF_NF_SRAM_CTL_dma0_sram_rm_shift                                       (7)
#define  NF_NF_SRAM_CTL_pp_sram_rm_shift                                         (3)
#define  NF_NF_SRAM_CTL_dma1_sram_rme_shift                                      (2)
#define  NF_NF_SRAM_CTL_dma0_sram_rme_shift                                      (1)
#define  NF_NF_SRAM_CTL_pp_sram_rme_shift                                        (0)
#define  NF_NF_SRAM_CTL_nf_sram_ls_mask                                          (0x00008000)
#define  NF_NF_SRAM_CTL_dma1_sram_rm_mask                                        (0x00007800)
#define  NF_NF_SRAM_CTL_dma0_sram_rm_mask                                        (0x00000780)
#define  NF_NF_SRAM_CTL_pp_sram_rm_mask                                          (0x00000078)
#define  NF_NF_SRAM_CTL_dma1_sram_rme_mask                                       (0x00000004)
#define  NF_NF_SRAM_CTL_dma0_sram_rme_mask                                       (0x00000002)
#define  NF_NF_SRAM_CTL_pp_sram_rme_mask                                         (0x00000001)
#define  NF_NF_SRAM_CTL_nf_sram_ls(data)                                         (0x00008000&((data)<<15))
#define  NF_NF_SRAM_CTL_dma1_sram_rm(data)                                       (0x00007800&((data)<<11))
#define  NF_NF_SRAM_CTL_dma0_sram_rm(data)                                       (0x00000780&((data)<<7))
#define  NF_NF_SRAM_CTL_pp_sram_rm(data)                                         (0x00000078&((data)<<3))
#define  NF_NF_SRAM_CTL_dma1_sram_rme(data)                                      (0x00000004&((data)<<2))
#define  NF_NF_SRAM_CTL_dma0_sram_rme(data)                                      (0x00000002&((data)<<1))
#define  NF_NF_SRAM_CTL_pp_sram_rme(data)                                        (0x00000001&(data))
#define  NF_NF_SRAM_CTL_get_nf_sram_ls(data)                                     ((0x00008000&(data))>>15)
#define  NF_NF_SRAM_CTL_get_dma1_sram_rm(data)                                   ((0x00007800&(data))>>11)
#define  NF_NF_SRAM_CTL_get_dma0_sram_rm(data)                                   ((0x00000780&(data))>>7)
#define  NF_NF_SRAM_CTL_get_pp_sram_rm(data)                                     ((0x00000078&(data))>>3)
#define  NF_NF_SRAM_CTL_get_dma1_sram_rme(data)                                  ((0x00000004&(data))>>2)
#define  NF_NF_SRAM_CTL_get_dma0_sram_rme(data)                                  ((0x00000002&(data))>>1)
#define  NF_NF_SRAM_CTL_get_pp_sram_rme(data)                                    (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======NF register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr0:8;
    };
}nf_nd_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr1:8;
    };
}nf_nd_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  addr_mode:3;
        RBus_UInt32  page_addr2:5;
    };
}nf_nd_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  col_addr0:8;
    };
}nf_nd_ca0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cmd:8;
    };
}nf_nd_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dat:8;
    };
}nf_nd_dat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xfer:1;
        RBus_UInt32  ready_busy:1;
        RBus_UInt32  ecc_tran:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ecc_enable:1;
        RBus_UInt32  tran_mode:3;
    };
}nf_nd_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  blank_zero_num:7;
    };
}nf_blank_zero_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cmd3:8;
    };
}nf_cmd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr3:3;
        RBus_UInt32  res2:5;
    };
}nf_nd_pa3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  bit_sel:3;
        RBus_UInt32  trig_poll:1;
    };
}nf_poll_fsts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  blank_zero_over:1;
        RBus_UInt32  read_ecc_xnor_ena:1;
        RBus_UInt32  blank_all_one:1;
        RBus_UInt32  blank_ena:1;
    };
}nf_blank_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ecc_not_clr:1;
        RBus_UInt32  ecc_err:1;
        RBus_UInt32  res2:2;
    };
}nf_nd_ecc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  col_addr1:8;
    };
}nf_nd_ca1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  length0:8;
    };
}nf_data_tl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  access_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  length1:6;
    };
}nf_data_tl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  eot_gen:1;
        RBus_UInt32  dma_max_pkt:1;
        RBus_UInt32  spec_pkt:1;
        RBus_UInt32  res2:1;
    };
}nf_dma1_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pp_start_addr:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pp_busy:1;
        RBus_UInt32  pp_reset:1;
        RBus_UInt32  pp_enable:1;
    };
}nf_pp_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ecc_bch_72b_ena:1;
        RBus_UInt32  ecc_bch_40b_ena:1;
        RBus_UInt32  ecc_bch_24b_ena:1;
        RBus_UInt32  ecc_bch_12b_ena:1;
    };
}nf_ecc_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pp_start_addr:8;
    };
}nf_pp_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ce_hw_sw_mode:1;
        RBus_UInt32  pd:5;
    };
}nf_pd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pp_lp_mode:1;
        RBus_UInt32  pp_lp_ena:1;
        RBus_UInt32  ecc_clk_gate_ena:1;
        RBus_UInt32  ip_clk_gate_ena:1;
        RBus_UInt32  dma_clk_gate_ena:1;
        RBus_UInt32  pp_sram_rdy_num:3;
    };
}nf_nf_low_pwr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dmy1:8;
    };
}nf_dummy_nf1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dmy2:8;
    };
}nf_dummy_nf2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dmy3:8;
    };
}nf_dummy_nf3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dmy4:8;
    };
}nf_dummy_nf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr0:8;
    };
}nf_nd_secu_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr1:8;
    };
}nf_nd_secu_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  addr_mode:3;
        RBus_UInt32  page_addr2:5;
    };
}nf_nd_secu_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr3:3;
        RBus_UInt32  res2:5;
    };
}nf_nd_secu_pa3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xfer:1;
        RBus_UInt32  ready_busy:1;
        RBus_UInt32  ecc_tran:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ecc_enable:1;
        RBus_UInt32  tran_mode:3;
    };
}nf_nd_secu_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_trig:1;
        RBus_UInt32  addr_fbd:1;
        RBus_UInt32  pp_empty:1;
        RBus_UInt32  spec_auto_case:2;
        RBus_UInt32  auto_case:3;
    };
}nf_secu_auto_trig_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  access_err:1;
        RBus_UInt32  block_trig:1;
    };
}nf_nd_secu_block_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_trig:1;
        RBus_UInt32  addr_fbd:1;
        RBus_UInt32  pp_empty:1;
        RBus_UInt32  spec_auto_case:2;
        RBus_UInt32  auto_case:3;
    };
}nf_auto_trig_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ecc_num:7;
    };
}nf_rsecc_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rnd_cmd1:8;
    };
}nf_rnd_cmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rnd_cmd2:8;
    };
}nf_rnd_cmd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  data_col_msb:8;
    };
}nf_rnd_datastr_col_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  spr_col_msb:8;
    };
}nf_rnd_spr_str_col_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  spr_col_lsb:8;
    };
}nf_rnd_spr_str_col_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  rnd_rw_enable:1;
    };
}nf_rnd_rw_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  flush_status:1;
        RBus_UInt32  start_flush:1;
    };
}nf_pp_sram_flush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  read_by_pp:1;
        RBus_UInt32  res2:7;
    };
}nf_read_by_pp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  max_ecc_num:7;
    };
}nf_max_ecc_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_ecc_num:8;
    };
}nf_page_ecc_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  t3:8;
    };
}nf_time_para3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  t2:8;
    };
}nf_time_para2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  t1:8;
    };
}nf_time_para1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  access_err:1;
        RBus_UInt32  block_trig:1;
    };
}nf_nd_block_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  block_page_len0:8;
    };
}nf_nd_block_page0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  block_page_len1:8;
    };
}nf_nd_block_page1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  block_page_cnt0:8;
    };
}nf_nd_block_page_cnt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  block_page_cnt1:8;
    };
}nf_nd_block_page_cnt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pin_stop:1;
        RBus_UInt32  intlev_pin_ena:1;
        RBus_UInt32  pin_mux_ena:1;
    };
}nf_pin_mux_stop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  t_swait_busy:2;
        RBus_UInt32  t_whr_adl:6;
    };
}nf_delay_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ecc_n_stop:1;
        RBus_UInt32  res2:7;
    };
}nf_ecc_stop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ecc_page:8;
    };
}nf_ecc_page_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_cnt:8;
    };
}nf_page_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_len:8;
    };
}nf_page_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cmd2:8;
    };
}nf_cmd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ecc_pass:1;
        RBus_UInt32  ecc_no_check:1;
        RBus_UInt32  edo:1;
        RBus_UInt32  no_wait_busy:1;
        RBus_UInt32  wait_ready:2;
        RBus_UInt32  res2:2;
    };
}nf_multi_chnl_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr0:8;
    };
}nf_nd_secu_start_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr1:8;
    };
}nf_nd_secu_start_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr2:8;
    };
}nf_nd_secu_start_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr0:8;
    };
}nf_nd_secu_end_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr1:8;
    };
}nf_nd_secu_end_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr2:8;
    };
}nf_nd_secu_end_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr0:8;
    };
}nf_nd_secu_start2_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr1:8;
    };
}nf_nd_secu_start2_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr2:8;
    };
}nf_nd_secu_start2_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr0:8;
    };
}nf_nd_secu_end2_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr1:8;
    };
}nf_nd_secu_end2_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page_addr2:8;
    };
}nf_nd_secu_end2_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  xcpu_block_xfer_stop_en:1;
        RBus_UInt32  enable1:1;
        RBus_UInt32  enable0:1;
    };
}nf_nd_secu_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  map_sel:1;
        RBus_UInt32  access_en:1;
        RBus_UInt32  mem_region:4;
    };
}nf_sram_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dram_sa:29;
    };
}nf_dma_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dma_len:16;
    };
}nf_dma_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  cp_first:1;
        RBus_UInt32  cp_enable:1;
        RBus_UInt32  ddr_wr:1;
        RBus_UInt32  dma_xfer:1;
    };
}nf_dma_ctl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mcu_pp_sram_lp_ena:1;
        RBus_UInt32  sys_clk_gate_ena:1;
        RBus_UInt32  cp_clk_gate_ena:1;
        RBus_UInt32  dma_sram_lp_ena:1;
        RBus_UInt32  dma_sram_rdy_num:4;
    };
}nf_sys_low_pwr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dram_sa:29;
    };
}nf_dma_secu_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dma_len:16;
    };
}nf_dma_secu_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  cp_first:1;
        RBus_UInt32  cp_enable:1;
        RBus_UInt32  ddr_wr:1;
        RBus_UInt32  dma_xfer:1;
    };
}nf_dma_secu_ctl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  reg_lock_nf_sram:1;
        RBus_UInt32  kcpu_nf_req:1;
    };
}nf_nf_secu_req_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  int8:1;
        RBus_UInt32  int7:1;
        RBus_UInt32  int6:1;
        RBus_UInt32  int5:1;
        RBus_UInt32  int4:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  write_data:1;
    };
}nf_nand_kcpu_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  int8en:1;
        RBus_UInt32  int7en:1;
        RBus_UInt32  int6en:1;
        RBus_UInt32  int5en:1;
        RBus_UInt32  int4en:1;
        RBus_UInt32  int3en:1;
        RBus_UInt32  int2en:1;
        RBus_UInt32  int1en:1;
        RBus_UInt32  write_data:1;
    };
}nf_nand_kcpu_isren_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}nf_dummy_sys_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  dummy18010330_0:1;
    };
}nf_cp_nf_cr_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  xcpu_nf_req:1;
        RBus_UInt32  kcpu_occupy:1;
        RBus_UInt32  xcpu_occupy:1;
    };
}nf_nf_multi_cpu_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  int8:1;
        RBus_UInt32  int7:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  int5:1;
        RBus_UInt32  int4:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  write_data:1;
    };
}nf_nand_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  int8en:1;
        RBus_UInt32  int7en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  int5en:1;
        RBus_UInt32  int4en:1;
        RBus_UInt32  int3en:1;
        RBus_UInt32  int2en:1;
        RBus_UInt32  int1en:1;
        RBus_UInt32  write_data:1;
    };
}nf_nand_isren_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  sel1:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  sel0:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  enable:1;
    };
}nf_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_nf_hw_pinmux_ena:1;
        RBus_UInt32  spare_ddr_ena:1;
        RBus_UInt32  per_2k_spr_ena:1;
        RBus_UInt32  spare_dram_sa:29;
    };
}nf_spr_ddr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cp_length:16;
        RBus_UInt32  res2:9;
    };
}nf_cp_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  nf_pp_bist_mode:1;
        RBus_UInt32  nf_dma_bist_mode:1;
    };
}nf_nf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  nf_pp_bist_done:1;
        RBus_UInt32  nf_dma_bist_done:1;
    };
}nf_nf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  nf_pp_bist_fail_group:1;
        RBus_UInt32  nf_dma_bist_fail_group:1;
    };
}nf_nf_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  nf_bist_nf_fail_2:1;
        RBus_UInt32  nf_bist_nf_fail_1:1;
        RBus_UInt32  nf_bist_nf_fail_0:1;
    };
}nf_nf_bist_nf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  nf_pp_drf_mode:1;
        RBus_UInt32  nf_dma_drf_mode:1;
    };
}nf_nf_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  nf_pp_drf_resume:1;
        RBus_UInt32  nf_dma_drf_resume:1;
    };
}nf_nf_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  nf_pp_drf_done:1;
        RBus_UInt32  nf_dma_drf_done:1;
    };
}nf_nf_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  nf_pp_drf_pause:1;
        RBus_UInt32  nf_dma_drf_pause:1;
    };
}nf_nf_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  nf_pp_drf_fail_group:1;
        RBus_UInt32  nf_dma_drf_fail_group:1;
    };
}nf_nf_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  nf_drf_nf_fail_2:1;
        RBus_UInt32  nf_drf_nf_fail_1:1;
        RBus_UInt32  nf_drf_nf_fail_0:1;
    };
}nf_nf_drf_nf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  nf_sram_ls:1;
        RBus_UInt32  dma1_sram_rm:4;
        RBus_UInt32  dma0_sram_rm:4;
        RBus_UInt32  pp_sram_rm:4;
        RBus_UInt32  dma1_sram_rme:1;
        RBus_UInt32  dma0_sram_rme:1;
        RBus_UInt32  pp_sram_rme:1;
    };
}nf_nf_sram_ctl_RBUS;

#else //apply LITTLE_ENDIAN

//======NF register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr0:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr1:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr2:5;
        RBus_UInt32  addr_mode:3;
        RBus_UInt32  res1:24;
    };
}nf_nd_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  col_addr0:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_ca0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_dat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tran_mode:3;
        RBus_UInt32  ecc_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ecc_tran:1;
        RBus_UInt32  ready_busy:1;
        RBus_UInt32  xfer:1;
        RBus_UInt32  res2:24;
    };
}nf_nd_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blank_zero_num:7;
        RBus_UInt32  res1:25;
    };
}nf_blank_zero_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd3:8;
        RBus_UInt32  res1:24;
    };
}nf_cmd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  page_addr3:3;
        RBus_UInt32  res2:24;
    };
}nf_nd_pa3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trig_poll:1;
        RBus_UInt32  bit_sel:3;
        RBus_UInt32  res1:28;
    };
}nf_poll_fsts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blank_ena:1;
        RBus_UInt32  blank_all_one:1;
        RBus_UInt32  read_ecc_xnor_ena:1;
        RBus_UInt32  blank_zero_over:1;
        RBus_UInt32  res1:28;
    };
}nf_blank_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ecc_err:1;
        RBus_UInt32  ecc_not_clr:1;
        RBus_UInt32  res2:28;
    };
}nf_nd_ecc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  col_addr1:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_ca1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  length0:8;
        RBus_UInt32  res1:24;
    };
}nf_data_tl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  length1:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  access_mode:1;
        RBus_UInt32  res2:24;
    };
}nf_data_tl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  spec_pkt:1;
        RBus_UInt32  dma_max_pkt:1;
        RBus_UInt32  eot_gen:1;
        RBus_UInt32  res2:28;
    };
}nf_dma1_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pp_enable:1;
        RBus_UInt32  pp_reset:1;
        RBus_UInt32  pp_busy:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pp_start_addr:4;
        RBus_UInt32  res2:24;
    };
}nf_pp_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecc_bch_12b_ena:1;
        RBus_UInt32  ecc_bch_24b_ena:1;
        RBus_UInt32  ecc_bch_40b_ena:1;
        RBus_UInt32  ecc_bch_72b_ena:1;
        RBus_UInt32  res1:28;
    };
}nf_ecc_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pp_start_addr:8;
        RBus_UInt32  res1:24;
    };
}nf_pp_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pd:5;
        RBus_UInt32  ce_hw_sw_mode:1;
        RBus_UInt32  res1:26;
    };
}nf_pd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pp_sram_rdy_num:3;
        RBus_UInt32  dma_clk_gate_ena:1;
        RBus_UInt32  ip_clk_gate_ena:1;
        RBus_UInt32  ecc_clk_gate_ena:1;
        RBus_UInt32  pp_lp_ena:1;
        RBus_UInt32  pp_lp_mode:1;
        RBus_UInt32  res1:24;
    };
}nf_nf_low_pwr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy1:8;
        RBus_UInt32  res1:24;
    };
}nf_dummy_nf1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy2:8;
        RBus_UInt32  res1:24;
    };
}nf_dummy_nf2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy3:8;
        RBus_UInt32  res1:24;
    };
}nf_dummy_nf3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy4:8;
        RBus_UInt32  res1:24;
    };
}nf_dummy_nf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr0:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr1:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr2:5;
        RBus_UInt32  addr_mode:3;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  page_addr3:3;
        RBus_UInt32  res2:24;
    };
}nf_nd_secu_pa3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tran_mode:3;
        RBus_UInt32  ecc_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ecc_tran:1;
        RBus_UInt32  ready_busy:1;
        RBus_UInt32  xfer:1;
        RBus_UInt32  res2:24;
    };
}nf_nd_secu_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_case:3;
        RBus_UInt32  spec_auto_case:2;
        RBus_UInt32  pp_empty:1;
        RBus_UInt32  addr_fbd:1;
        RBus_UInt32  auto_trig:1;
        RBus_UInt32  res1:24;
    };
}nf_secu_auto_trig_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  block_trig:1;
        RBus_UInt32  access_err:1;
        RBus_UInt32  res1:30;
    };
}nf_nd_secu_block_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_case:3;
        RBus_UInt32  spec_auto_case:2;
        RBus_UInt32  pp_empty:1;
        RBus_UInt32  addr_fbd:1;
        RBus_UInt32  auto_trig:1;
        RBus_UInt32  res1:24;
    };
}nf_auto_trig_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecc_num:7;
        RBus_UInt32  res1:25;
    };
}nf_rsecc_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_cmd1:8;
        RBus_UInt32  res1:24;
    };
}nf_rnd_cmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_cmd2:8;
        RBus_UInt32  res1:24;
    };
}nf_rnd_cmd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_col_msb:8;
        RBus_UInt32  res1:24;
    };
}nf_rnd_datastr_col_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spr_col_msb:8;
        RBus_UInt32  res1:24;
    };
}nf_rnd_spr_str_col_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spr_col_lsb:8;
        RBus_UInt32  res1:24;
    };
}nf_rnd_spr_str_col_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_rw_enable:1;
        RBus_UInt32  res1:31;
    };
}nf_rnd_rw_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_flush:1;
        RBus_UInt32  flush_status:1;
        RBus_UInt32  res1:30;
    };
}nf_pp_sram_flush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  read_by_pp:1;
        RBus_UInt32  res2:24;
    };
}nf_read_by_pp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_ecc_num:7;
        RBus_UInt32  res1:25;
    };
}nf_max_ecc_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_ecc_num:8;
        RBus_UInt32  res1:24;
    };
}nf_page_ecc_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t3:8;
        RBus_UInt32  res1:24;
    };
}nf_time_para3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t2:8;
        RBus_UInt32  res1:24;
    };
}nf_time_para2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t1:8;
        RBus_UInt32  res1:24;
    };
}nf_time_para1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  block_trig:1;
        RBus_UInt32  access_err:1;
        RBus_UInt32  res1:30;
    };
}nf_nd_block_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  block_page_len0:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_block_page0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  block_page_len1:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_block_page1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  block_page_cnt0:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_block_page_cnt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  block_page_cnt1:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_block_page_cnt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pin_mux_ena:1;
        RBus_UInt32  intlev_pin_ena:1;
        RBus_UInt32  pin_stop:1;
        RBus_UInt32  res1:29;
    };
}nf_pin_mux_stop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t_whr_adl:6;
        RBus_UInt32  t_swait_busy:2;
        RBus_UInt32  res1:24;
    };
}nf_delay_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ecc_n_stop:1;
        RBus_UInt32  res2:24;
    };
}nf_ecc_stop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecc_page:8;
        RBus_UInt32  res1:24;
    };
}nf_ecc_page_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_cnt:8;
        RBus_UInt32  res1:24;
    };
}nf_page_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_len:8;
        RBus_UInt32  res1:24;
    };
}nf_page_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd2:8;
        RBus_UInt32  res1:24;
    };
}nf_cmd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  wait_ready:2;
        RBus_UInt32  no_wait_busy:1;
        RBus_UInt32  edo:1;
        RBus_UInt32  ecc_no_check:1;
        RBus_UInt32  ecc_pass:1;
        RBus_UInt32  res2:24;
    };
}nf_multi_chnl_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr0:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_start_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr1:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_start_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr2:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_start_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr0:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_end_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr1:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_end_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr2:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_end_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr0:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_start2_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr1:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_start2_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr2:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_start2_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr0:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_end2_pa0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr1:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_end2_pa1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page_addr2:8;
        RBus_UInt32  res1:24;
    };
}nf_nd_secu_end2_pa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable0:1;
        RBus_UInt32  enable1:1;
        RBus_UInt32  xcpu_block_xfer_stop_en:1;
        RBus_UInt32  res1:29;
    };
}nf_nd_secu_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_region:4;
        RBus_UInt32  access_en:1;
        RBus_UInt32  map_sel:1;
        RBus_UInt32  res1:26;
    };
}nf_sram_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dram_sa:29;
        RBus_UInt32  res1:3;
    };
}nf_dma_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_len:16;
        RBus_UInt32  res1:16;
    };
}nf_dma_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_xfer:1;
        RBus_UInt32  ddr_wr:1;
        RBus_UInt32  cp_enable:1;
        RBus_UInt32  cp_first:1;
        RBus_UInt32  res1:28;
    };
}nf_dma_ctl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_sram_rdy_num:4;
        RBus_UInt32  dma_sram_lp_ena:1;
        RBus_UInt32  cp_clk_gate_ena:1;
        RBus_UInt32  sys_clk_gate_ena:1;
        RBus_UInt32  mcu_pp_sram_lp_ena:1;
        RBus_UInt32  res1:24;
    };
}nf_sys_low_pwr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dram_sa:29;
        RBus_UInt32  res1:3;
    };
}nf_dma_secu_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_len:16;
        RBus_UInt32  res1:16;
    };
}nf_dma_secu_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_xfer:1;
        RBus_UInt32  ddr_wr:1;
        RBus_UInt32  cp_enable:1;
        RBus_UInt32  cp_first:1;
        RBus_UInt32  res1:28;
    };
}nf_dma_secu_ctl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_nf_req:1;
        RBus_UInt32  reg_lock_nf_sram:1;
        RBus_UInt32  res1:30;
    };
}nf_nf_secu_req_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int4:1;
        RBus_UInt32  int5:1;
        RBus_UInt32  int6:1;
        RBus_UInt32  int7:1;
        RBus_UInt32  int8:1;
        RBus_UInt32  res1:23;
    };
}nf_nand_kcpu_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int1en:1;
        RBus_UInt32  int2en:1;
        RBus_UInt32  int3en:1;
        RBus_UInt32  int4en:1;
        RBus_UInt32  int5en:1;
        RBus_UInt32  int6en:1;
        RBus_UInt32  int7en:1;
        RBus_UInt32  int8en:1;
        RBus_UInt32  res1:23;
    };
}nf_nand_kcpu_isren_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}nf_dummy_sys_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18010330_0:1;
        RBus_UInt32  res1:31;
    };
}nf_cp_nf_cr_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xcpu_occupy:1;
        RBus_UInt32  kcpu_occupy:1;
        RBus_UInt32  xcpu_nf_req:1;
        RBus_UInt32  res1:29;
    };
}nf_nf_multi_cpu_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int4:1;
        RBus_UInt32  int5:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  int7:1;
        RBus_UInt32  int8:1;
        RBus_UInt32  res2:23;
    };
}nf_nand_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int1en:1;
        RBus_UInt32  int2en:1;
        RBus_UInt32  int3en:1;
        RBus_UInt32  int4en:1;
        RBus_UInt32  int5en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  int7en:1;
        RBus_UInt32  int8en:1;
        RBus_UInt32  res2:23;
    };
}nf_nand_isren_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  sel0:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  sel1:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:22;
    };
}nf_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spare_dram_sa:29;
        RBus_UInt32  per_2k_spr_ena:1;
        RBus_UInt32  spare_ddr_ena:1;
        RBus_UInt32  cr_nf_hw_pinmux_ena:1;
    };
}nf_spr_ddr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cp_length:16;
        RBus_UInt32  res2:7;
    };
}nf_cp_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_dma_bist_mode:1;
        RBus_UInt32  nf_pp_bist_mode:1;
        RBus_UInt32  res1:30;
    };
}nf_nf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_dma_bist_done:1;
        RBus_UInt32  nf_pp_bist_done:1;
        RBus_UInt32  res1:30;
    };
}nf_nf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_dma_bist_fail_group:1;
        RBus_UInt32  nf_pp_bist_fail_group:1;
        RBus_UInt32  res1:30;
    };
}nf_nf_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_bist_nf_fail_0:1;
        RBus_UInt32  nf_bist_nf_fail_1:1;
        RBus_UInt32  nf_bist_nf_fail_2:1;
        RBus_UInt32  res1:29;
    };
}nf_nf_bist_nf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_dma_drf_mode:1;
        RBus_UInt32  nf_pp_drf_mode:1;
        RBus_UInt32  res1:30;
    };
}nf_nf_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_dma_drf_resume:1;
        RBus_UInt32  nf_pp_drf_resume:1;
        RBus_UInt32  res1:30;
    };
}nf_nf_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_dma_drf_done:1;
        RBus_UInt32  nf_pp_drf_done:1;
        RBus_UInt32  res1:30;
    };
}nf_nf_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_dma_drf_pause:1;
        RBus_UInt32  nf_pp_drf_pause:1;
        RBus_UInt32  res1:30;
    };
}nf_nf_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_dma_drf_fail_group:1;
        RBus_UInt32  nf_pp_drf_fail_group:1;
        RBus_UInt32  res1:30;
    };
}nf_nf_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nf_drf_nf_fail_0:1;
        RBus_UInt32  nf_drf_nf_fail_1:1;
        RBus_UInt32  nf_drf_nf_fail_2:1;
        RBus_UInt32  res1:29;
    };
}nf_nf_drf_nf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pp_sram_rme:1;
        RBus_UInt32  dma0_sram_rme:1;
        RBus_UInt32  dma1_sram_rme:1;
        RBus_UInt32  pp_sram_rm:4;
        RBus_UInt32  dma0_sram_rm:4;
        RBus_UInt32  dma1_sram_rm:4;
        RBus_UInt32  nf_sram_ls:1;
        RBus_UInt32  res1:16;
    };
}nf_nf_sram_ctl_RBUS;




#endif 


#endif 
