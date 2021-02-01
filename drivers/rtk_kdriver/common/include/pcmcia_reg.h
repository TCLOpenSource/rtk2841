/**
* @file rbusPCMCIAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PCMCIA_REG_H_
#define _RBUS_PCMCIA_REG_H_

#include "rbus_types.h"



//  PCMCIA Register Address
#define  PCMCIA_MIS_PCMCIA0_CMDFF                                                0x1801B700
#define  PCMCIA_MIS_PCMCIA0_CMDFF_reg_addr                                       "0xB801B700"
#define  PCMCIA_MIS_PCMCIA0_CMDFF_reg                                            0xB801B700
#define  PCMCIA_MIS_PCMCIA0_CMDFF_inst_addr                                      "0x0000"
#define  set_PCMCIA_MIS_PCMCIA0_CMDFF_reg(data)                                  (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_CMDFF_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_CMDFF_reg                                        (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_CMDFF_reg))
#define  PCMCIA_MIS_PCMCIA0_CMDFF_ct_shift                                       (24)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_at_shift                                       (23)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_pa_shift                                       (8)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_df_shift                                       (0)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_ct_mask                                        (0x01000000)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_at_mask                                        (0x00800000)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_pa_mask                                        (0x007FFF00)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_df_mask                                        (0x000000FF)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_ct(data)                                       (0x01000000&((data)<<24))
#define  PCMCIA_MIS_PCMCIA0_CMDFF_at(data)                                       (0x00800000&((data)<<23))
#define  PCMCIA_MIS_PCMCIA0_CMDFF_pa(data)                                       (0x007FFF00&((data)<<8))
#define  PCMCIA_MIS_PCMCIA0_CMDFF_df(data)                                       (0x000000FF&(data))
#define  PCMCIA_MIS_PCMCIA0_CMDFF_get_ct(data)                                   ((0x01000000&(data))>>24)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_get_at(data)                                   ((0x00800000&(data))>>23)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_get_pa(data)                                   ((0x007FFF00&(data))>>8)
#define  PCMCIA_MIS_PCMCIA0_CMDFF_get_df(data)                                   (0x000000FF&(data))

#define  PCMCIA_MIS_PCMCIA0_CR                                                   0x1801B704
#define  PCMCIA_MIS_PCMCIA0_CR_reg_addr                                          "0xB801B704"
#define  PCMCIA_MIS_PCMCIA0_CR_reg                                               0xB801B704
#define  PCMCIA_MIS_PCMCIA0_CR_inst_addr                                         "0x0001"
#define  set_PCMCIA_MIS_PCMCIA0_CR_reg(data)                                     (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_CR_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_CR_reg                                           (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_CR_reg))
#define  PCMCIA_MIS_PCMCIA0_CR_psr_shift                                         (31)
#define  PCMCIA_MIS_PCMCIA0_CR_ce1_card1_shift                                   (30)
#define  PCMCIA_MIS_PCMCIA0_CR_ce1_card2_shift                                   (29)
#define  PCMCIA_MIS_PCMCIA0_CR_ce2_card1_shift                                   (28)
#define  PCMCIA_MIS_PCMCIA0_CR_ce2_card2_shift                                   (27)
#define  PCMCIA_MIS_PCMCIA0_CR_pcr1_shift                                        (26)
#define  PCMCIA_MIS_PCMCIA0_CR_pcr2_shift                                        (25)
#define  PCMCIA_MIS_PCMCIA0_CR_pcr1_oe_shift                                     (24)
#define  PCMCIA_MIS_PCMCIA0_CR_pcr2_oe_shift                                     (23)
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_r_en_shift                                   (11)
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_w_en_shift                                   (10)
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_erro_en_shift                                (9)
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_wr_over_en_shift                             (8)
#define  PCMCIA_MIS_PCMCIA0_CR_piie1_shift                                       (7)
#define  PCMCIA_MIS_PCMCIA0_CR_pciie1_shift                                      (6)
#define  PCMCIA_MIS_PCMCIA0_CR_pcrie1_shift                                      (5)
#define  PCMCIA_MIS_PCMCIA0_CR_piie2_shift                                       (4)
#define  PCMCIA_MIS_PCMCIA0_CR_pciie2_shift                                      (3)
#define  PCMCIA_MIS_PCMCIA0_CR_pcrie2_shift                                      (2)
#define  PCMCIA_MIS_PCMCIA0_CR_afie_shift                                        (1)
#define  PCMCIA_MIS_PCMCIA0_CR_apfie_shift                                       (0)
#define  PCMCIA_MIS_PCMCIA0_CR_psr_mask                                          (0x80000000)
#define  PCMCIA_MIS_PCMCIA0_CR_ce1_card1_mask                                    (0x40000000)
#define  PCMCIA_MIS_PCMCIA0_CR_ce1_card2_mask                                    (0x20000000)
#define  PCMCIA_MIS_PCMCIA0_CR_ce2_card1_mask                                    (0x10000000)
#define  PCMCIA_MIS_PCMCIA0_CR_ce2_card2_mask                                    (0x08000000)
#define  PCMCIA_MIS_PCMCIA0_CR_pcr1_mask                                         (0x04000000)
#define  PCMCIA_MIS_PCMCIA0_CR_pcr2_mask                                         (0x02000000)
#define  PCMCIA_MIS_PCMCIA0_CR_pcr1_oe_mask                                      (0x01000000)
#define  PCMCIA_MIS_PCMCIA0_CR_pcr2_oe_mask                                      (0x00800000)
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_r_en_mask                                    (0x00000800)
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_w_en_mask                                    (0x00000400)
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_erro_en_mask                                 (0x00000200)
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_wr_over_en_mask                              (0x00000100)
#define  PCMCIA_MIS_PCMCIA0_CR_piie1_mask                                        (0x00000080)
#define  PCMCIA_MIS_PCMCIA0_CR_pciie1_mask                                       (0x00000040)
#define  PCMCIA_MIS_PCMCIA0_CR_pcrie1_mask                                       (0x00000020)
#define  PCMCIA_MIS_PCMCIA0_CR_piie2_mask                                        (0x00000010)
#define  PCMCIA_MIS_PCMCIA0_CR_pciie2_mask                                       (0x00000008)
#define  PCMCIA_MIS_PCMCIA0_CR_pcrie2_mask                                       (0x00000004)
#define  PCMCIA_MIS_PCMCIA0_CR_afie_mask                                         (0x00000002)
#define  PCMCIA_MIS_PCMCIA0_CR_apfie_mask                                        (0x00000001)
#define  PCMCIA_MIS_PCMCIA0_CR_psr(data)                                         (0x80000000&((data)<<31))
#define  PCMCIA_MIS_PCMCIA0_CR_ce1_card1(data)                                   (0x40000000&((data)<<30))
#define  PCMCIA_MIS_PCMCIA0_CR_ce1_card2(data)                                   (0x20000000&((data)<<29))
#define  PCMCIA_MIS_PCMCIA0_CR_ce2_card1(data)                                   (0x10000000&((data)<<28))
#define  PCMCIA_MIS_PCMCIA0_CR_ce2_card2(data)                                   (0x08000000&((data)<<27))
#define  PCMCIA_MIS_PCMCIA0_CR_pcr1(data)                                        (0x04000000&((data)<<26))
#define  PCMCIA_MIS_PCMCIA0_CR_pcr2(data)                                        (0x02000000&((data)<<25))
#define  PCMCIA_MIS_PCMCIA0_CR_pcr1_oe(data)                                     (0x01000000&((data)<<24))
#define  PCMCIA_MIS_PCMCIA0_CR_pcr2_oe(data)                                     (0x00800000&((data)<<23))
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_r_en(data)                                   (0x00000800&((data)<<11))
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_w_en(data)                                   (0x00000400&((data)<<10))
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_erro_en(data)                                (0x00000200&((data)<<9))
#define  PCMCIA_MIS_PCMCIA0_CR_fifo_wr_over_en(data)                             (0x00000100&((data)<<8))
#define  PCMCIA_MIS_PCMCIA0_CR_piie1(data)                                       (0x00000080&((data)<<7))
#define  PCMCIA_MIS_PCMCIA0_CR_pciie1(data)                                      (0x00000040&((data)<<6))
#define  PCMCIA_MIS_PCMCIA0_CR_pcrie1(data)                                      (0x00000020&((data)<<5))
#define  PCMCIA_MIS_PCMCIA0_CR_piie2(data)                                       (0x00000010&((data)<<4))
#define  PCMCIA_MIS_PCMCIA0_CR_pciie2(data)                                      (0x00000008&((data)<<3))
#define  PCMCIA_MIS_PCMCIA0_CR_pcrie2(data)                                      (0x00000004&((data)<<2))
#define  PCMCIA_MIS_PCMCIA0_CR_afie(data)                                        (0x00000002&((data)<<1))
#define  PCMCIA_MIS_PCMCIA0_CR_apfie(data)                                       (0x00000001&(data))
#define  PCMCIA_MIS_PCMCIA0_CR_get_psr(data)                                     ((0x80000000&(data))>>31)
#define  PCMCIA_MIS_PCMCIA0_CR_get_ce1_card1(data)                               ((0x40000000&(data))>>30)
#define  PCMCIA_MIS_PCMCIA0_CR_get_ce1_card2(data)                               ((0x20000000&(data))>>29)
#define  PCMCIA_MIS_PCMCIA0_CR_get_ce2_card1(data)                               ((0x10000000&(data))>>28)
#define  PCMCIA_MIS_PCMCIA0_CR_get_ce2_card2(data)                               ((0x08000000&(data))>>27)
#define  PCMCIA_MIS_PCMCIA0_CR_get_pcr1(data)                                    ((0x04000000&(data))>>26)
#define  PCMCIA_MIS_PCMCIA0_CR_get_pcr2(data)                                    ((0x02000000&(data))>>25)
#define  PCMCIA_MIS_PCMCIA0_CR_get_pcr1_oe(data)                                 ((0x01000000&(data))>>24)
#define  PCMCIA_MIS_PCMCIA0_CR_get_pcr2_oe(data)                                 ((0x00800000&(data))>>23)
#define  PCMCIA_MIS_PCMCIA0_CR_get_fifo_r_en(data)                               ((0x00000800&(data))>>11)
#define  PCMCIA_MIS_PCMCIA0_CR_get_fifo_w_en(data)                               ((0x00000400&(data))>>10)
#define  PCMCIA_MIS_PCMCIA0_CR_get_fifo_erro_en(data)                            ((0x00000200&(data))>>9)
#define  PCMCIA_MIS_PCMCIA0_CR_get_fifo_wr_over_en(data)                         ((0x00000100&(data))>>8)
#define  PCMCIA_MIS_PCMCIA0_CR_get_piie1(data)                                   ((0x00000080&(data))>>7)
#define  PCMCIA_MIS_PCMCIA0_CR_get_pciie1(data)                                  ((0x00000040&(data))>>6)
#define  PCMCIA_MIS_PCMCIA0_CR_get_pcrie1(data)                                  ((0x00000020&(data))>>5)
#define  PCMCIA_MIS_PCMCIA0_CR_get_piie2(data)                                   ((0x00000010&(data))>>4)
#define  PCMCIA_MIS_PCMCIA0_CR_get_pciie2(data)                                  ((0x00000008&(data))>>3)
#define  PCMCIA_MIS_PCMCIA0_CR_get_pcrie2(data)                                  ((0x00000004&(data))>>2)
#define  PCMCIA_MIS_PCMCIA0_CR_get_afie(data)                                    ((0x00000002&(data))>>1)
#define  PCMCIA_MIS_PCMCIA0_CR_get_apfie(data)                                   (0x00000001&(data))

#define  PCMCIA_MIS_PCMCIA0_STS                                                  0x1801B708
#define  PCMCIA_MIS_PCMCIA0_STS_reg_addr                                         "0xB801B708"
#define  PCMCIA_MIS_PCMCIA0_STS_reg                                              0xB801B708
#define  PCMCIA_MIS_PCMCIA0_STS_inst_addr                                        "0x0002"
#define  set_PCMCIA_MIS_PCMCIA0_STS_reg(data)                                    (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_STS_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_STS_reg                                          (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_STS_reg))
#define  PCMCIA_MIS_PCMCIA0_STS_pres1_shift                                      (13)
#define  PCMCIA_MIS_PCMCIA0_STS_pres2_shift                                      (12)
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_r_shift                                     (11)
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_w_shift                                     (10)
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_erro_shift                                  (9)
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_wr_over_shift                               (8)
#define  PCMCIA_MIS_PCMCIA0_STS_pii1_shift                                       (7)
#define  PCMCIA_MIS_PCMCIA0_STS_pcii1_shift                                      (6)
#define  PCMCIA_MIS_PCMCIA0_STS_pcri1_shift                                      (5)
#define  PCMCIA_MIS_PCMCIA0_STS_pii2_shift                                       (4)
#define  PCMCIA_MIS_PCMCIA0_STS_pcii2_shift                                      (3)
#define  PCMCIA_MIS_PCMCIA0_STS_pcri2_shift                                      (2)
#define  PCMCIA_MIS_PCMCIA0_STS_afi_shift                                        (1)
#define  PCMCIA_MIS_PCMCIA0_STS_apfi_shift                                       (0)
#define  PCMCIA_MIS_PCMCIA0_STS_pres1_mask                                       (0x00002000)
#define  PCMCIA_MIS_PCMCIA0_STS_pres2_mask                                       (0x00001000)
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_r_mask                                      (0x00000800)
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_w_mask                                      (0x00000400)
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_erro_mask                                   (0x00000200)
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_wr_over_mask                                (0x00000100)
#define  PCMCIA_MIS_PCMCIA0_STS_pii1_mask                                        (0x00000080)
#define  PCMCIA_MIS_PCMCIA0_STS_pcii1_mask                                       (0x00000040)
#define  PCMCIA_MIS_PCMCIA0_STS_pcri1_mask                                       (0x00000020)
#define  PCMCIA_MIS_PCMCIA0_STS_pii2_mask                                        (0x00000010)
#define  PCMCIA_MIS_PCMCIA0_STS_pcii2_mask                                       (0x00000008)
#define  PCMCIA_MIS_PCMCIA0_STS_pcri2_mask                                       (0x00000004)
#define  PCMCIA_MIS_PCMCIA0_STS_afi_mask                                         (0x00000002)
#define  PCMCIA_MIS_PCMCIA0_STS_apfi_mask                                        (0x00000001)
#define  PCMCIA_MIS_PCMCIA0_STS_pres1(data)                                      (0x00002000&((data)<<13))
#define  PCMCIA_MIS_PCMCIA0_STS_pres2(data)                                      (0x00001000&((data)<<12))
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_r(data)                                     (0x00000800&((data)<<11))
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_w(data)                                     (0x00000400&((data)<<10))
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_erro(data)                                  (0x00000200&((data)<<9))
#define  PCMCIA_MIS_PCMCIA0_STS_fifo_wr_over(data)                               (0x00000100&((data)<<8))
#define  PCMCIA_MIS_PCMCIA0_STS_pii1(data)                                       (0x00000080&((data)<<7))
#define  PCMCIA_MIS_PCMCIA0_STS_pcii1(data)                                      (0x00000040&((data)<<6))
#define  PCMCIA_MIS_PCMCIA0_STS_pcri1(data)                                      (0x00000020&((data)<<5))
#define  PCMCIA_MIS_PCMCIA0_STS_pii2(data)                                       (0x00000010&((data)<<4))
#define  PCMCIA_MIS_PCMCIA0_STS_pcii2(data)                                      (0x00000008&((data)<<3))
#define  PCMCIA_MIS_PCMCIA0_STS_pcri2(data)                                      (0x00000004&((data)<<2))
#define  PCMCIA_MIS_PCMCIA0_STS_afi(data)                                        (0x00000002&((data)<<1))
#define  PCMCIA_MIS_PCMCIA0_STS_apfi(data)                                       (0x00000001&(data))
#define  PCMCIA_MIS_PCMCIA0_STS_get_pres1(data)                                  ((0x00002000&(data))>>13)
#define  PCMCIA_MIS_PCMCIA0_STS_get_pres2(data)                                  ((0x00001000&(data))>>12)
#define  PCMCIA_MIS_PCMCIA0_STS_get_fifo_r(data)                                 ((0x00000800&(data))>>11)
#define  PCMCIA_MIS_PCMCIA0_STS_get_fifo_w(data)                                 ((0x00000400&(data))>>10)
#define  PCMCIA_MIS_PCMCIA0_STS_get_fifo_erro(data)                              ((0x00000200&(data))>>9)
#define  PCMCIA_MIS_PCMCIA0_STS_get_fifo_wr_over(data)                           ((0x00000100&(data))>>8)
#define  PCMCIA_MIS_PCMCIA0_STS_get_pii1(data)                                   ((0x00000080&(data))>>7)
#define  PCMCIA_MIS_PCMCIA0_STS_get_pcii1(data)                                  ((0x00000040&(data))>>6)
#define  PCMCIA_MIS_PCMCIA0_STS_get_pcri1(data)                                  ((0x00000020&(data))>>5)
#define  PCMCIA_MIS_PCMCIA0_STS_get_pii2(data)                                   ((0x00000010&(data))>>4)
#define  PCMCIA_MIS_PCMCIA0_STS_get_pcii2(data)                                  ((0x00000008&(data))>>3)
#define  PCMCIA_MIS_PCMCIA0_STS_get_pcri2(data)                                  ((0x00000004&(data))>>2)
#define  PCMCIA_MIS_PCMCIA0_STS_get_afi(data)                                    ((0x00000002&(data))>>1)
#define  PCMCIA_MIS_PCMCIA0_STS_get_apfi(data)                                   (0x00000001&(data))

#define  PCMCIA_MIS_PCMCIA0_AMTC_0                                               0x1801B70C
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_reg_addr                                      "0xB801B70C"
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_reg                                           0xB801B70C
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_inst_addr                                     "0x0003"
#define  set_PCMCIA_MIS_PCMCIA0_AMTC_0_reg(data)                                 (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_AMTC_0_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_AMTC_0_reg                                       (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_AMTC_0_reg))
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_twe_shift                                     (16)
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_thd_shift                                     (8)
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_tsu_shift                                     (0)
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_twe_mask                                      (0x03FF0000)
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_thd_mask                                      (0x0000FF00)
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_tsu_mask                                      (0x000000FF)
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_twe(data)                                     (0x03FF0000&((data)<<16))
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_thd(data)                                     (0x0000FF00&((data)<<8))
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_tsu(data)                                     (0x000000FF&(data))
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_get_twe(data)                                 ((0x03FF0000&(data))>>16)
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_get_thd(data)                                 ((0x0000FF00&(data))>>8)
#define  PCMCIA_MIS_PCMCIA0_AMTC_0_get_tsu(data)                                 (0x000000FF&(data))

#define  PCMCIA_MIS_PCMCIA0_AMTC_1                                               0x1801B728
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_reg_addr                                      "0xB801B728"
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_reg                                           0xB801B728
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_inst_addr                                     "0x0004"
#define  set_PCMCIA_MIS_PCMCIA0_AMTC_1_reg(data)                                 (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_AMTC_1_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_AMTC_1_reg                                       (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_AMTC_1_reg))
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_taoe_shift                                    (16)
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_thce_shift                                    (0)
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_taoe_mask                                     (0x03FF0000)
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_thce_mask                                     (0x0000003F)
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_taoe(data)                                    (0x03FF0000&((data)<<16))
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_thce(data)                                    (0x0000003F&(data))
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_get_taoe(data)                                ((0x03FF0000&(data))>>16)
#define  PCMCIA_MIS_PCMCIA0_AMTC_1_get_thce(data)                                (0x0000003F&(data))

#define  PCMCIA_MIS_PCMCIA0_IOMTC                                                0x1801B710
#define  PCMCIA_MIS_PCMCIA0_IOMTC_reg_addr                                       "0xB801B710"
#define  PCMCIA_MIS_PCMCIA0_IOMTC_reg                                            0xB801B710
#define  PCMCIA_MIS_PCMCIA0_IOMTC_inst_addr                                      "0x0005"
#define  set_PCMCIA_MIS_PCMCIA0_IOMTC_reg(data)                                  (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_IOMTC_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_IOMTC_reg                                        (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_IOMTC_reg))
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tdiord_shift                                   (24)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tsuio_shift                                    (16)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tdinpack_shift                                 (8)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tdwt_shift                                     (0)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tdiord_mask                                    (0xFF000000)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tsuio_mask                                     (0x00FF0000)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tdinpack_mask                                  (0x00007F00)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tdwt_mask                                      (0x0000007F)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tdiord(data)                                   (0xFF000000&((data)<<24))
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tsuio(data)                                    (0x00FF0000&((data)<<16))
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tdinpack(data)                                 (0x00007F00&((data)<<8))
#define  PCMCIA_MIS_PCMCIA0_IOMTC_tdwt(data)                                     (0x0000007F&(data))
#define  PCMCIA_MIS_PCMCIA0_IOMTC_get_tdiord(data)                               ((0xFF000000&(data))>>24)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_get_tsuio(data)                                ((0x00FF0000&(data))>>16)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_get_tdinpack(data)                             ((0x00007F00&(data))>>8)
#define  PCMCIA_MIS_PCMCIA0_IOMTC_get_tdwt(data)                                 (0x0000007F&(data))

#define  PCMCIA_MIS_PCMCIA0_MATC_0                                               0x1801B714
#define  PCMCIA_MIS_PCMCIA0_MATC_0_reg_addr                                      "0xB801B714"
#define  PCMCIA_MIS_PCMCIA0_MATC_0_reg                                           0xB801B714
#define  PCMCIA_MIS_PCMCIA0_MATC_0_inst_addr                                     "0x0006"
#define  set_PCMCIA_MIS_PCMCIA0_MATC_0_reg(data)                                 (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_MATC_0_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_MATC_0_reg                                       (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_MATC_0_reg))
#define  PCMCIA_MIS_PCMCIA0_MATC_0_tc_shift                                      (16)
#define  PCMCIA_MIS_PCMCIA0_MATC_0_thdio_shift                                   (0)
#define  PCMCIA_MIS_PCMCIA0_MATC_0_tc_mask                                       (0x03FF0000)
#define  PCMCIA_MIS_PCMCIA0_MATC_0_thdio_mask                                    (0x0000003F)
#define  PCMCIA_MIS_PCMCIA0_MATC_0_tc(data)                                      (0x03FF0000&((data)<<16))
#define  PCMCIA_MIS_PCMCIA0_MATC_0_thdio(data)                                   (0x0000003F&(data))
#define  PCMCIA_MIS_PCMCIA0_MATC_0_get_tc(data)                                  ((0x03FF0000&(data))>>16)
#define  PCMCIA_MIS_PCMCIA0_MATC_0_get_thdio(data)                               (0x0000003F&(data))

#define  PCMCIA_MIS_PCMCIA0_MATC_1                                               0x1801B72C
#define  PCMCIA_MIS_PCMCIA0_MATC_1_reg_addr                                      "0xB801B72C"
#define  PCMCIA_MIS_PCMCIA0_MATC_1_reg                                           0xB801B72C
#define  PCMCIA_MIS_PCMCIA0_MATC_1_inst_addr                                     "0x0007"
#define  set_PCMCIA_MIS_PCMCIA0_MATC_1_reg(data)                                 (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_MATC_1_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_MATC_1_reg                                       (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_MATC_1_reg))
#define  PCMCIA_MIS_PCMCIA0_MATC_1_tcio_shift                                    (16)
#define  PCMCIA_MIS_PCMCIA0_MATC_1_twiowr_shift                                  (0)
#define  PCMCIA_MIS_PCMCIA0_MATC_1_tcio_mask                                     (0x01FF0000)
#define  PCMCIA_MIS_PCMCIA0_MATC_1_twiowr_mask                                   (0x000001FF)
#define  PCMCIA_MIS_PCMCIA0_MATC_1_tcio(data)                                    (0x01FF0000&((data)<<16))
#define  PCMCIA_MIS_PCMCIA0_MATC_1_twiowr(data)                                  (0x000001FF&(data))
#define  PCMCIA_MIS_PCMCIA0_MATC_1_get_tcio(data)                                ((0x01FF0000&(data))>>16)
#define  PCMCIA_MIS_PCMCIA0_MATC_1_get_twiowr(data)                              (0x000001FF&(data))

#define  PCMCIA_MIS_PCMCIA0_ACTRL                                                0x1801B718
#define  PCMCIA_MIS_PCMCIA0_ACTRL_reg_addr                                       "0xB801B718"
#define  PCMCIA_MIS_PCMCIA0_ACTRL_reg                                            0xB801B718
#define  PCMCIA_MIS_PCMCIA0_ACTRL_inst_addr                                      "0x0008"
#define  set_PCMCIA_MIS_PCMCIA0_ACTRL_reg(data)                                  (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_ACTRL_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_ACTRL_reg                                        (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_ACTRL_reg))
#define  PCMCIA_MIS_PCMCIA0_ACTRL_oe_shift                                       (0)
#define  PCMCIA_MIS_PCMCIA0_ACTRL_oe_mask                                        (0x00007FFF)
#define  PCMCIA_MIS_PCMCIA0_ACTRL_oe(data)                                       (0x00007FFF&(data))
#define  PCMCIA_MIS_PCMCIA0_ACTRL_get_oe(data)                                   (0x00007FFF&(data))

#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL                                            0x1801B71C
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_reg_addr                                   "0xB801B71C"
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_reg                                        0xB801B71C
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_inst_addr                                  "0x0009"
#define  set_PCMCIA_MIS_PCMCIA0_FIFO_CTRL_reg(data)                              (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_FIFO_CTRL_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_FIFO_CTRL_reg                                    (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_FIFO_CTRL_reg))
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_addr_step_shift                            (31)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_wr_num_shift                               (8)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_fifo_r_trig_shift                          (4)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_pin_share_sel_shift                        (3)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_fifo_wr_mode_shift                         (1)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_fifo_en_shift                              (0)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_addr_step_mask                             (0x80000000)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_wr_num_mask                                (0x007FFF00)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_fifo_r_trig_mask                           (0x00000030)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_pin_share_sel_mask                         (0x00000008)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_fifo_wr_mode_mask                          (0x00000006)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_fifo_en_mask                               (0x00000001)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_addr_step(data)                            (0x80000000&((data)<<31))
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_wr_num(data)                               (0x007FFF00&((data)<<8))
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_fifo_r_trig(data)                          (0x00000030&((data)<<4))
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_pin_share_sel(data)                        (0x00000008&((data)<<3))
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_fifo_wr_mode(data)                         (0x00000006&((data)<<1))
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_fifo_en(data)                              (0x00000001&(data))
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_get_addr_step(data)                        ((0x80000000&(data))>>31)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_get_wr_num(data)                           ((0x007FFF00&(data))>>8)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_get_fifo_r_trig(data)                      ((0x00000030&(data))>>4)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_get_pin_share_sel(data)                    ((0x00000008&(data))>>3)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_get_fifo_wr_mode(data)                     ((0x00000006&(data))>>1)
#define  PCMCIA_MIS_PCMCIA0_FIFO_CTRL_get_fifo_en(data)                          (0x00000001&(data))

#define  PCMCIA_MIS_PCMCIA0_NUM_TOTAL                                            0x1801B730
#define  PCMCIA_MIS_PCMCIA0_NUM_TOTAL_reg_addr                                   "0xB801B730"
#define  PCMCIA_MIS_PCMCIA0_NUM_TOTAL_reg                                        0xB801B730
#define  PCMCIA_MIS_PCMCIA0_NUM_TOTAL_inst_addr                                  "0x000A"
#define  set_PCMCIA_MIS_PCMCIA0_NUM_TOTAL_reg(data)                              (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_NUM_TOTAL_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_NUM_TOTAL_reg                                    (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_NUM_TOTAL_reg))
#define  PCMCIA_MIS_PCMCIA0_NUM_TOTAL_wr_num_total_shift                         (0)
#define  PCMCIA_MIS_PCMCIA0_NUM_TOTAL_wr_num_total_mask                          (0xFFFFFFFF)
#define  PCMCIA_MIS_PCMCIA0_NUM_TOTAL_wr_num_total(data)                         (0xFFFFFFFF&(data))
#define  PCMCIA_MIS_PCMCIA0_NUM_TOTAL_get_wr_num_total(data)                     (0xFFFFFFFF&(data))

#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS                                          0x1801B720
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_reg_addr                                 "0xB801B720"
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_reg                                      0xB801B720
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_inst_addr                                "0x000B"
#define  set_PCMCIA_MIS_PCMCIA0_FIFO_STATUS_reg(data)                            (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_FIFO_STATUS_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_FIFO_STATUS_reg                                  (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_FIFO_STATUS_reg))
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_fifo_len_shift                           (8)
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_fifo_empty_shift                         (1)
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_fifo_full_shift                          (0)
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_fifo_len_mask                            (0x00003F00)
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_fifo_empty_mask                          (0x00000002)
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_fifo_full_mask                           (0x00000001)
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_fifo_len(data)                           (0x00003F00&((data)<<8))
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_fifo_empty(data)                         (0x00000002&((data)<<1))
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_fifo_full(data)                          (0x00000001&(data))
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_get_fifo_len(data)                       ((0x00003F00&(data))>>8)
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_get_fifo_empty(data)                     ((0x00000002&(data))>>1)
#define  PCMCIA_MIS_PCMCIA0_FIFO_STATUS_get_fifo_full(data)                      (0x00000001&(data))

#define  PCMCIA_MIS_PCMCIA0_PIN_SEL                                              0x1801B724
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_reg_addr                                     "0xB801B724"
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_reg                                          0xB801B724
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_inst_addr                                    "0x000C"
#define  set_PCMCIA_MIS_PCMCIA0_PIN_SEL_reg(data)                                (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_PIN_SEL_reg)=data)
#define  get_PCMCIA_MIS_PCMCIA0_PIN_SEL_reg                                      (*((volatile unsigned int*)PCMCIA_MIS_PCMCIA0_PIN_SEL_reg))
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_inpack1_dis_shift                            (5)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_inpack0_dis_shift                            (4)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_wait1_dis_shift                              (2)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_wait0_dis_shift                              (0)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_inpack1_dis_mask                             (0x00000020)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_inpack0_dis_mask                             (0x00000010)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_wait1_dis_mask                               (0x0000000C)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_wait0_dis_mask                               (0x00000003)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_inpack1_dis(data)                            (0x00000020&((data)<<5))
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_inpack0_dis(data)                            (0x00000010&((data)<<4))
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_wait1_dis(data)                              (0x0000000C&((data)<<2))
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_wait0_dis(data)                              (0x00000003&(data))
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_get_inpack1_dis(data)                        ((0x00000020&(data))>>5)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_get_inpack0_dis(data)                        ((0x00000010&(data))>>4)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_get_wait1_dis(data)                          ((0x0000000C&(data))>>2)
#define  PCMCIA_MIS_PCMCIA0_PIN_SEL_get_wait0_dis(data)                          (0x00000003&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PCMCIA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ct:1;
        RBus_UInt32  at:1;
        RBus_UInt32  pa:15;
        RBus_UInt32  df:8;
    };
}pcmcia_mis_pcmcia0_cmdff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psr:1;
        RBus_UInt32  ce1_card1:1;
        RBus_UInt32  ce1_card2:1;
        RBus_UInt32  ce2_card1:1;
        RBus_UInt32  ce2_card2:1;
        RBus_UInt32  pcr1:1;
        RBus_UInt32  pcr2:1;
        RBus_UInt32  pcr1_oe:1;
        RBus_UInt32  pcr2_oe:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  fifo_r_en:1;
        RBus_UInt32  fifo_w_en:1;
        RBus_UInt32  fifo_erro_en:1;
        RBus_UInt32  fifo_wr_over_en:1;
        RBus_UInt32  piie1:1;
        RBus_UInt32  pciie1:1;
        RBus_UInt32  pcrie1:1;
        RBus_UInt32  piie2:1;
        RBus_UInt32  pciie2:1;
        RBus_UInt32  pcrie2:1;
        RBus_UInt32  afie:1;
        RBus_UInt32  apfie:1;
    };
}pcmcia_mis_pcmcia0_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  pres1:1;
        RBus_UInt32  pres2:1;
        RBus_UInt32  fifo_r:1;
        RBus_UInt32  fifo_w:1;
        RBus_UInt32  fifo_erro:1;
        RBus_UInt32  fifo_wr_over:1;
        RBus_UInt32  pii1:1;
        RBus_UInt32  pcii1:1;
        RBus_UInt32  pcri1:1;
        RBus_UInt32  pii2:1;
        RBus_UInt32  pcii2:1;
        RBus_UInt32  pcri2:1;
        RBus_UInt32  afi:1;
        RBus_UInt32  apfi:1;
    };
}pcmcia_mis_pcmcia0_sts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  twe:10;
        RBus_UInt32  thd:8;
        RBus_UInt32  tsu:8;
    };
}pcmcia_mis_pcmcia0_amtc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  taoe:10;
        RBus_UInt32  res2:10;
        RBus_UInt32  thce:6;
    };
}pcmcia_mis_pcmcia0_amtc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tdiord:8;
        RBus_UInt32  tsuio:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  tdinpack:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  tdwt:7;
    };
}pcmcia_mis_pcmcia0_iomtc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  tc:10;
        RBus_UInt32  res2:10;
        RBus_UInt32  thdio:6;
    };
}pcmcia_mis_pcmcia0_matc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  tcio:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  twiowr:9;
    };
}pcmcia_mis_pcmcia0_matc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  oe:15;
    };
}pcmcia_mis_pcmcia0_actrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr_step:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  wr_num:15;
        RBus_UInt32  res2:2;
        RBus_UInt32  fifo_r_trig:2;
        RBus_UInt32  pin_share_sel:1;
        RBus_UInt32  fifo_wr_mode:2;
        RBus_UInt32  fifo_en:1;
    };
}pcmcia_mis_pcmcia0_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_num_total:32;
    };
}pcmcia_mis_pcmcia0_num_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  fifo_len:6;
        RBus_UInt32  res2:6;
        RBus_UInt32  fifo_empty:1;
        RBus_UInt32  fifo_full:1;
    };
}pcmcia_mis_pcmcia0_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  inpack1_dis:1;
        RBus_UInt32  inpack0_dis:1;
        RBus_UInt32  wait1_dis:2;
        RBus_UInt32  wait0_dis:2;
    };
}pcmcia_mis_pcmcia0_pin_sel_RBUS;

#else //apply LITTLE_ENDIAN

//======PCMCIA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  df:8;
        RBus_UInt32  pa:15;
        RBus_UInt32  at:1;
        RBus_UInt32  ct:1;
        RBus_UInt32  res1:7;
    };
}pcmcia_mis_pcmcia0_cmdff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apfie:1;
        RBus_UInt32  afie:1;
        RBus_UInt32  pcrie2:1;
        RBus_UInt32  pciie2:1;
        RBus_UInt32  piie2:1;
        RBus_UInt32  pcrie1:1;
        RBus_UInt32  pciie1:1;
        RBus_UInt32  piie1:1;
        RBus_UInt32  fifo_wr_over_en:1;
        RBus_UInt32  fifo_erro_en:1;
        RBus_UInt32  fifo_w_en:1;
        RBus_UInt32  fifo_r_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  pcr2_oe:1;
        RBus_UInt32  pcr1_oe:1;
        RBus_UInt32  pcr2:1;
        RBus_UInt32  pcr1:1;
        RBus_UInt32  ce2_card2:1;
        RBus_UInt32  ce2_card1:1;
        RBus_UInt32  ce1_card2:1;
        RBus_UInt32  ce1_card1:1;
        RBus_UInt32  psr:1;
    };
}pcmcia_mis_pcmcia0_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apfi:1;
        RBus_UInt32  afi:1;
        RBus_UInt32  pcri2:1;
        RBus_UInt32  pcii2:1;
        RBus_UInt32  pii2:1;
        RBus_UInt32  pcri1:1;
        RBus_UInt32  pcii1:1;
        RBus_UInt32  pii1:1;
        RBus_UInt32  fifo_wr_over:1;
        RBus_UInt32  fifo_erro:1;
        RBus_UInt32  fifo_w:1;
        RBus_UInt32  fifo_r:1;
        RBus_UInt32  pres2:1;
        RBus_UInt32  pres1:1;
        RBus_UInt32  res1:18;
    };
}pcmcia_mis_pcmcia0_sts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tsu:8;
        RBus_UInt32  thd:8;
        RBus_UInt32  twe:10;
        RBus_UInt32  res1:6;
    };
}pcmcia_mis_pcmcia0_amtc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  thce:6;
        RBus_UInt32  res1:10;
        RBus_UInt32  taoe:10;
        RBus_UInt32  res2:6;
    };
}pcmcia_mis_pcmcia0_amtc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tdwt:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  tdinpack:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  tsuio:8;
        RBus_UInt32  tdiord:8;
    };
}pcmcia_mis_pcmcia0_iomtc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  thdio:6;
        RBus_UInt32  res1:10;
        RBus_UInt32  tc:10;
        RBus_UInt32  res2:6;
    };
}pcmcia_mis_pcmcia0_matc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  twiowr:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  tcio:9;
        RBus_UInt32  res2:7;
    };
}pcmcia_mis_pcmcia0_matc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oe:15;
        RBus_UInt32  res1:17;
    };
}pcmcia_mis_pcmcia0_actrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_en:1;
        RBus_UInt32  fifo_wr_mode:2;
        RBus_UInt32  pin_share_sel:1;
        RBus_UInt32  fifo_r_trig:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  wr_num:15;
        RBus_UInt32  res2:8;
        RBus_UInt32  addr_step:1;
    };
}pcmcia_mis_pcmcia0_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_num_total:32;
    };
}pcmcia_mis_pcmcia0_num_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_full:1;
        RBus_UInt32  fifo_empty:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  fifo_len:6;
        RBus_UInt32  res2:18;
    };
}pcmcia_mis_pcmcia0_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wait0_dis:2;
        RBus_UInt32  wait1_dis:2;
        RBus_UInt32  inpack0_dis:1;
        RBus_UInt32  inpack1_dis:1;
        RBus_UInt32  res1:26;
    };
}pcmcia_mis_pcmcia0_pin_sel_RBUS;




#endif 


#endif 
