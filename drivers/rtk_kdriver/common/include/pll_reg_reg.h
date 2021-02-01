/**
* @file rbusPLL_REGReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PLL_REG_REG_H_
#define _RBUS_PLL_REG_REG_H_

#include "rbus_types.h"



//  PLL_REG Register Address
#define  PLL_REG_SYS_PLL_DISPB_SD1                                               0x18000350
#define  PLL_REG_SYS_PLL_DISPB_SD1_reg_addr                                      "0xB8000350"
#define  PLL_REG_SYS_PLL_DISPB_SD1_reg                                           0xB8000350
#define  PLL_REG_SYS_PLL_DISPB_SD1_inst_addr                                     "0x0000"
#define  set_PLL_REG_SYS_PLL_DISPB_SD1_reg(data)                                 (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPB_SD1_reg)=data)
#define  get_PLL_REG_SYS_PLL_DISPB_SD1_reg                                       (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPB_SD1_reg))
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_n_shift                               (30)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_ip_shift                              (20)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_rs_shift                              (17)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_cs_shift                              (15)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_cp_shift                              (13)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_o_shift                               (4)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_wdmode_shift                          (0)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_n_mask                                (0xC0000000)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_ip_mask                               (0x00F00000)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_rs_mask                               (0x000E0000)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_cs_mask                               (0x00018000)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_cp_mask                               (0x00006000)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_o_mask                                (0x00000030)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_wdmode_mask                           (0x00000003)
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_n(data)                               (0xC0000000&((data)<<30))
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_ip(data)                              (0x00F00000&((data)<<20))
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_rs(data)                              (0x000E0000&((data)<<17))
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_cs(data)                              (0x00018000&((data)<<15))
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_cp(data)                              (0x00006000&((data)<<13))
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_o(data)                               (0x00000030&((data)<<4))
#define  PLL_REG_SYS_PLL_DISPB_SD1_pllddsb_wdmode(data)                          (0x00000003&(data))
#define  PLL_REG_SYS_PLL_DISPB_SD1_get_pllddsb_n(data)                           ((0xC0000000&(data))>>30)
#define  PLL_REG_SYS_PLL_DISPB_SD1_get_pllddsb_ip(data)                          ((0x00F00000&(data))>>20)
#define  PLL_REG_SYS_PLL_DISPB_SD1_get_pllddsb_rs(data)                          ((0x000E0000&(data))>>17)
#define  PLL_REG_SYS_PLL_DISPB_SD1_get_pllddsb_cs(data)                          ((0x00018000&(data))>>15)
#define  PLL_REG_SYS_PLL_DISPB_SD1_get_pllddsb_cp(data)                          ((0x00006000&(data))>>13)
#define  PLL_REG_SYS_PLL_DISPB_SD1_get_pllddsb_o(data)                           ((0x00000030&(data))>>4)
#define  PLL_REG_SYS_PLL_DISPB_SD1_get_pllddsb_wdmode(data)                      (0x00000003&(data))

#define  PLL_REG_SYS_PLL_DISPB_SD2                                               0x18000354
#define  PLL_REG_SYS_PLL_DISPB_SD2_reg_addr                                      "0xB8000354"
#define  PLL_REG_SYS_PLL_DISPB_SD2_reg                                           0xB8000354
#define  PLL_REG_SYS_PLL_DISPB_SD2_inst_addr                                     "0x0001"
#define  set_PLL_REG_SYS_PLL_DISPB_SD2_reg(data)                                 (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPB_SD2_reg)=data)
#define  get_PLL_REG_SYS_PLL_DISPB_SD2_reg                                       (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPB_SD2_reg))
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_fcode_shift                           (16)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_ncode_shift                           (8)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_oeb_shift                             (2)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_rstb_shift                            (1)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_pow_shift                             (0)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_fcode_mask                            (0x07FF0000)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_ncode_mask                            (0x0000FF00)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_oeb_mask                              (0x00000004)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_rstb_mask                             (0x00000002)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_pow_mask                              (0x00000001)
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_fcode(data)                           (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_ncode(data)                           (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_oeb(data)                             (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_rstb(data)                            (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_DISPB_SD2_pllddsb_pow(data)                             (0x00000001&(data))
#define  PLL_REG_SYS_PLL_DISPB_SD2_get_pllddsb_fcode(data)                       ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_PLL_DISPB_SD2_get_pllddsb_ncode(data)                       ((0x0000FF00&(data))>>8)
#define  PLL_REG_SYS_PLL_DISPB_SD2_get_pllddsb_oeb(data)                         ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_DISPB_SD2_get_pllddsb_rstb(data)                        ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_DISPB_SD2_get_pllddsb_pow(data)                         (0x00000001&(data))

#define  PLL_REG_SYS_PLL_DISPB_SD3                                               0x18000358
#define  PLL_REG_SYS_PLL_DISPB_SD3_reg_addr                                      "0xB8000358"
#define  PLL_REG_SYS_PLL_DISPB_SD3_reg                                           0xB8000358
#define  PLL_REG_SYS_PLL_DISPB_SD3_inst_addr                                     "0x0002"
#define  set_PLL_REG_SYS_PLL_DISPB_SD3_reg(data)                                 (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPB_SD3_reg)=data)
#define  get_PLL_REG_SYS_PLL_DISPB_SD3_reg                                       (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPB_SD3_reg))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_28_25_shift                             (25)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_24_shift                                (24)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_23_shift                                (23)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_22_shift                                (22)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_21_shift                                (21)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_20_shift                                (20)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_19_shift                                (19)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_18_shift                                (18)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_17_shift                                (17)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_16_shift                                (16)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_15_shift                                (15)
#define  PLL_REG_SYS_PLL_DISPB_SD3_pllddsb_vcorb_shift                           (14)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_13_shift                                (13)
#define  PLL_REG_SYS_PLL_DISPB_SD3_pllddsb_tst_shift                             (12)
#define  PLL_REG_SYS_PLL_DISPB_SD3_pllddsb_pstst_shift                           (11)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_10_shift                                (10)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_28_25_mask                              (0x1E000000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_24_mask                                 (0x01000000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_23_mask                                 (0x00800000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_22_mask                                 (0x00400000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_21_mask                                 (0x00200000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_20_mask                                 (0x00100000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_19_mask                                 (0x00080000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_18_mask                                 (0x00040000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_17_mask                                 (0x00020000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_16_mask                                 (0x00010000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_15_mask                                 (0x00008000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_pllddsb_vcorb_mask                            (0x00004000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_13_mask                                 (0x00002000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_pllddsb_tst_mask                              (0x00001000)
#define  PLL_REG_SYS_PLL_DISPB_SD3_pllddsb_pstst_mask                            (0x00000800)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_10_mask                                 (0x00000400)
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_28_25(data)                             (0x1E000000&((data)<<25))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_24(data)                                (0x01000000&((data)<<24))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_23(data)                                (0x00800000&((data)<<23))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_22(data)                                (0x00400000&((data)<<22))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_21(data)                                (0x00200000&((data)<<21))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_20(data)                                (0x00100000&((data)<<20))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_19(data)                                (0x00080000&((data)<<19))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_18(data)                                (0x00040000&((data)<<18))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_17(data)                                (0x00020000&((data)<<17))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_16(data)                                (0x00010000&((data)<<16))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_15(data)                                (0x00008000&((data)<<15))
#define  PLL_REG_SYS_PLL_DISPB_SD3_pllddsb_vcorb(data)                           (0x00004000&((data)<<14))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_13(data)                                (0x00002000&((data)<<13))
#define  PLL_REG_SYS_PLL_DISPB_SD3_pllddsb_tst(data)                             (0x00001000&((data)<<12))
#define  PLL_REG_SYS_PLL_DISPB_SD3_pllddsb_pstst(data)                           (0x00000800&((data)<<11))
#define  PLL_REG_SYS_PLL_DISPB_SD3_dummy_10(data)                                (0x00000400&((data)<<10))
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_28_25(data)                         ((0x1E000000&(data))>>25)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_24(data)                            ((0x01000000&(data))>>24)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_23(data)                            ((0x00800000&(data))>>23)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_22(data)                            ((0x00400000&(data))>>22)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_21(data)                            ((0x00200000&(data))>>21)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_20(data)                            ((0x00100000&(data))>>20)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_19(data)                            ((0x00080000&(data))>>19)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_18(data)                            ((0x00040000&(data))>>18)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_17(data)                            ((0x00020000&(data))>>17)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_16(data)                            ((0x00010000&(data))>>16)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_15(data)                            ((0x00008000&(data))>>15)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_pllddsb_vcorb(data)                       ((0x00004000&(data))>>14)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_13(data)                            ((0x00002000&(data))>>13)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_pllddsb_tst(data)                         ((0x00001000&(data))>>12)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_pllddsb_pstst(data)                       ((0x00000800&(data))>>11)
#define  PLL_REG_SYS_PLL_DISPB_SD3_get_dummy_10(data)                            ((0x00000400&(data))>>10)

#define  PLL_REG_SYS_PLL_DISPB_SD4                                               0x1800035C
#define  PLL_REG_SYS_PLL_DISPB_SD4_reg_addr                                      "0xB800035C"
#define  PLL_REG_SYS_PLL_DISPB_SD4_reg                                           0xB800035C
#define  PLL_REG_SYS_PLL_DISPB_SD4_inst_addr                                     "0x0003"
#define  set_PLL_REG_SYS_PLL_DISPB_SD4_reg(data)                                 (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPB_SD4_reg)=data)
#define  get_PLL_REG_SYS_PLL_DISPB_SD4_reg                                       (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPB_SD4_reg))
#define  PLL_REG_SYS_PLL_DISPB_SD4_dummy_30_shift                                (30)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_fupdn_shift                           (29)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_div_shift                             (28)
#define  PLL_REG_SYS_PLL_DISPB_SD4_dummy_27_shift                                (27)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_tst_shift                             (26)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_psen_shift                            (25)
#define  PLL_REG_SYS_PLL_DISPB_SD4_dummy_24_shift                                (24)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_fupdn_shift                           (23)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_div_shift                             (22)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_tst_shift                             (21)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_psen_shift                            (20)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_oeb_shift                             (3)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_rstb_shift                            (2)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_oeb_shift                             (1)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_rstb_shift                            (0)
#define  PLL_REG_SYS_PLL_DISPB_SD4_dummy_30_mask                                 (0x40000000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_fupdn_mask                            (0x20000000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_div_mask                              (0x10000000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_dummy_27_mask                                 (0x08000000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_tst_mask                              (0x04000000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_psen_mask                             (0x02000000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_dummy_24_mask                                 (0x01000000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_fupdn_mask                            (0x00800000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_div_mask                              (0x00400000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_tst_mask                              (0x00200000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_psen_mask                             (0x00100000)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_oeb_mask                              (0x00000008)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_rstb_mask                             (0x00000004)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_oeb_mask                              (0x00000002)
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_rstb_mask                             (0x00000001)
#define  PLL_REG_SYS_PLL_DISPB_SD4_dummy_30(data)                                (0x40000000&((data)<<30))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_fupdn(data)                           (0x20000000&((data)<<29))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_div(data)                             (0x10000000&((data)<<28))
#define  PLL_REG_SYS_PLL_DISPB_SD4_dummy_27(data)                                (0x08000000&((data)<<27))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_tst(data)                             (0x04000000&((data)<<26))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_psen(data)                            (0x02000000&((data)<<25))
#define  PLL_REG_SYS_PLL_DISPB_SD4_dummy_24(data)                                (0x01000000&((data)<<24))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_fupdn(data)                           (0x00800000&((data)<<23))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_div(data)                             (0x00400000&((data)<<22))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_tst(data)                             (0x00200000&((data)<<21))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_psen(data)                            (0x00100000&((data)<<20))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_oeb(data)                             (0x00000008&((data)<<3))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud1b_rstb(data)                            (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_oeb(data)                             (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_DISPB_SD4_psaud2b_rstb(data)                            (0x00000001&(data))
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_dummy_30(data)                            ((0x40000000&(data))>>30)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud1b_fupdn(data)                       ((0x20000000&(data))>>29)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud1b_div(data)                         ((0x10000000&(data))>>28)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_dummy_27(data)                            ((0x08000000&(data))>>27)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud1b_tst(data)                         ((0x04000000&(data))>>26)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud1b_psen(data)                        ((0x02000000&(data))>>25)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_dummy_24(data)                            ((0x01000000&(data))>>24)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud2b_fupdn(data)                       ((0x00800000&(data))>>23)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud2b_div(data)                         ((0x00400000&(data))>>22)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud2b_tst(data)                         ((0x00200000&(data))>>21)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud2b_psen(data)                        ((0x00100000&(data))>>20)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud1b_oeb(data)                         ((0x00000008&(data))>>3)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud1b_rstb(data)                        ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud2b_oeb(data)                         ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_DISPB_SD4_get_psaud2b_rstb(data)                        (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_DDSB                                                   0x18000360
#define  PLL_REG_SYS_DVFS_DDSB_reg_addr                                          "0xB8000360"
#define  PLL_REG_SYS_DVFS_DDSB_reg                                               0xB8000360
#define  PLL_REG_SYS_DVFS_DDSB_inst_addr                                         "0x0004"
#define  set_PLL_REG_SYS_DVFS_DDSB_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_DVFS_DDSB_reg)=data)
#define  get_PLL_REG_SYS_DVFS_DDSB_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_DVFS_DDSB_reg))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_bypass_pi_shift                           (31)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_en_pi_debug_shift                         (30)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_hs_oc_stop_shift                          (28)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_pi_cur_sel_shift                          (26)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_sel_oc_mode_shift                         (24)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_done_delay_shift                       (16)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_step_shift                             (4)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_sdm_order_shift                           (2)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_done_shift                             (1)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_en_shift                               (0)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_bypass_pi_mask                            (0x80000000)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_en_pi_debug_mask                          (0x40000000)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_hs_oc_stop_mask                           (0x30000000)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_pi_cur_sel_mask                           (0x0C000000)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_sel_oc_mode_mask                          (0x03000000)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_done_delay_mask                        (0x003F0000)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_step_mask                              (0x00003FF0)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_sdm_order_mask                            (0x00000004)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_done_mask                              (0x00000002)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_en_mask                                (0x00000001)
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_bypass_pi(data)                           (0x80000000&((data)<<31))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_en_pi_debug(data)                         (0x40000000&((data)<<30))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_hs_oc_stop(data)                          (0x30000000&((data)<<28))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_pi_cur_sel(data)                          (0x0C000000&((data)<<26))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_sel_oc_mode(data)                         (0x03000000&((data)<<24))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_done_delay(data)                       (0x003F0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_step(data)                             (0x00003FF0&((data)<<4))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_sdm_order(data)                           (0x00000004&((data)<<2))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_done(data)                             (0x00000002&((data)<<1))
#define  PLL_REG_SYS_DVFS_DDSB_pllddsb_oc_en(data)                               (0x00000001&(data))
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_bypass_pi(data)                       ((0x80000000&(data))>>31)
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_en_pi_debug(data)                     ((0x40000000&(data))>>30)
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_hs_oc_stop(data)                      ((0x30000000&(data))>>28)
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_pi_cur_sel(data)                      ((0x0C000000&(data))>>26)
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_sel_oc_mode(data)                     ((0x03000000&(data))>>24)
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_oc_done_delay(data)                   ((0x003F0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_oc_step(data)                         ((0x00003FF0&(data))>>4)
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_sdm_order(data)                       ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_oc_done(data)                         ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_DVFS_DDSB_get_pllddsb_oc_en(data)                           (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_DDSB2                                                  0x18000364
#define  PLL_REG_SYS_DVFS_DDSB2_reg_addr                                         "0xB8000364"
#define  PLL_REG_SYS_DVFS_DDSB2_reg                                              0xB8000364
#define  PLL_REG_SYS_DVFS_DDSB2_inst_addr                                        "0x0005"
#define  set_PLL_REG_SYS_DVFS_DDSB2_reg(data)                                    (*((volatile unsigned int*)PLL_REG_SYS_DVFS_DDSB2_reg)=data)
#define  get_PLL_REG_SYS_DVFS_DDSB2_reg                                          (*((volatile unsigned int*)PLL_REG_SYS_DVFS_DDSB2_reg))
#define  PLL_REG_SYS_DVFS_DDSB2_pllddsb_fcode_dbg_shift                          (16)
#define  PLL_REG_SYS_DVFS_DDSB2_pllddsb_ncode_dbg_shift                          (8)
#define  PLL_REG_SYS_DVFS_DDSB2_pllddsb_fcode_dbg_mask                           (0x07FF0000)
#define  PLL_REG_SYS_DVFS_DDSB2_pllddsb_ncode_dbg_mask                           (0x0000FF00)
#define  PLL_REG_SYS_DVFS_DDSB2_pllddsb_fcode_dbg(data)                          (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_DDSB2_pllddsb_ncode_dbg(data)                          (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_DVFS_DDSB2_get_pllddsb_fcode_dbg(data)                      ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_DDSB2_get_pllddsb_ncode_dbg(data)                      ((0x0000FF00&(data))>>8)

#define  PLL_REG_AI_B_CLKCR                                                      0x18000370
#define  PLL_REG_AI_B_CLKCR_reg_addr                                             "0xB8000370"
#define  PLL_REG_AI_B_CLKCR_reg                                                  0xB8000370
#define  PLL_REG_AI_B_CLKCR_inst_addr                                            "0x0006"
#define  set_PLL_REG_AI_B_CLKCR_reg(data)                                        (*((volatile unsigned int*)PLL_REG_AI_B_CLKCR_reg)=data)
#define  get_PLL_REG_AI_B_CLKCR_reg                                              (*((volatile unsigned int*)PLL_REG_AI_B_CLKCR_reg))
#define  PLL_REG_AI_B_CLKCR_swsce_b_shift                                        (25)
#define  PLL_REG_AI_B_CLKCR_tme_b_shift                                          (23)
#define  PLL_REG_AI_B_CLKCR_tmps_b_shift                                         (20)
#define  PLL_REG_AI_B_CLKCR_psc_b_shift                                          (19)
#define  PLL_REG_AI_B_CLKCR_swcs_b_shift                                         (9)
#define  PLL_REG_AI_B_CLKCR_sd_b_shift                                           (1)
#define  PLL_REG_AI_B_CLKCR_su_b_shift                                           (0)
#define  PLL_REG_AI_B_CLKCR_swsce_b_mask                                         (0x02000000)
#define  PLL_REG_AI_B_CLKCR_tme_b_mask                                           (0x00800000)
#define  PLL_REG_AI_B_CLKCR_tmps_b_mask                                          (0x00100000)
#define  PLL_REG_AI_B_CLKCR_psc_b_mask                                           (0x00080000)
#define  PLL_REG_AI_B_CLKCR_swcs_b_mask                                          (0x0000FE00)
#define  PLL_REG_AI_B_CLKCR_sd_b_mask                                            (0x00000002)
#define  PLL_REG_AI_B_CLKCR_su_b_mask                                            (0x00000001)
#define  PLL_REG_AI_B_CLKCR_swsce_b(data)                                        (0x02000000&((data)<<25))
#define  PLL_REG_AI_B_CLKCR_tme_b(data)                                          (0x00800000&((data)<<23))
#define  PLL_REG_AI_B_CLKCR_tmps_b(data)                                         (0x00100000&((data)<<20))
#define  PLL_REG_AI_B_CLKCR_psc_b(data)                                          (0x00080000&((data)<<19))
#define  PLL_REG_AI_B_CLKCR_swcs_b(data)                                         (0x0000FE00&((data)<<9))
#define  PLL_REG_AI_B_CLKCR_sd_b(data)                                           (0x00000002&((data)<<1))
#define  PLL_REG_AI_B_CLKCR_su_b(data)                                           (0x00000001&(data))
#define  PLL_REG_AI_B_CLKCR_get_swsce_b(data)                                    ((0x02000000&(data))>>25)
#define  PLL_REG_AI_B_CLKCR_get_tme_b(data)                                      ((0x00800000&(data))>>23)
#define  PLL_REG_AI_B_CLKCR_get_tmps_b(data)                                     ((0x00100000&(data))>>20)
#define  PLL_REG_AI_B_CLKCR_get_psc_b(data)                                      ((0x00080000&(data))>>19)
#define  PLL_REG_AI_B_CLKCR_get_swcs_b(data)                                     ((0x0000FE00&(data))>>9)
#define  PLL_REG_AI_B_CLKCR_get_sd_b(data)                                       ((0x00000002&(data))>>1)
#define  PLL_REG_AI_B_CLKCR_get_su_b(data)                                       (0x00000001&(data))

#define  PLL_REG_AI2_B_CLKCR                                                     0x18000374
#define  PLL_REG_AI2_B_CLKCR_reg_addr                                            "0xB8000374"
#define  PLL_REG_AI2_B_CLKCR_reg                                                 0xB8000374
#define  PLL_REG_AI2_B_CLKCR_inst_addr                                           "0x0007"
#define  set_PLL_REG_AI2_B_CLKCR_reg(data)                                       (*((volatile unsigned int*)PLL_REG_AI2_B_CLKCR_reg)=data)
#define  get_PLL_REG_AI2_B_CLKCR_reg                                             (*((volatile unsigned int*)PLL_REG_AI2_B_CLKCR_reg))
#define  PLL_REG_AI2_B_CLKCR_swsce_b_2_shift                                     (25)
#define  PLL_REG_AI2_B_CLKCR_tme_b_2_shift                                       (23)
#define  PLL_REG_AI2_B_CLKCR_tmps_b_2_shift                                      (20)
#define  PLL_REG_AI2_B_CLKCR_psc_b_2_shift                                       (19)
#define  PLL_REG_AI2_B_CLKCR_swcs_b_2_shift                                      (9)
#define  PLL_REG_AI2_B_CLKCR_sd_b_2_shift                                        (1)
#define  PLL_REG_AI2_B_CLKCR_su_b_2_shift                                        (0)
#define  PLL_REG_AI2_B_CLKCR_swsce_b_2_mask                                      (0x02000000)
#define  PLL_REG_AI2_B_CLKCR_tme_b_2_mask                                        (0x00800000)
#define  PLL_REG_AI2_B_CLKCR_tmps_b_2_mask                                       (0x00100000)
#define  PLL_REG_AI2_B_CLKCR_psc_b_2_mask                                        (0x00080000)
#define  PLL_REG_AI2_B_CLKCR_swcs_b_2_mask                                       (0x0000FE00)
#define  PLL_REG_AI2_B_CLKCR_sd_b_2_mask                                         (0x00000002)
#define  PLL_REG_AI2_B_CLKCR_su_b_2_mask                                         (0x00000001)
#define  PLL_REG_AI2_B_CLKCR_swsce_b_2(data)                                     (0x02000000&((data)<<25))
#define  PLL_REG_AI2_B_CLKCR_tme_b_2(data)                                       (0x00800000&((data)<<23))
#define  PLL_REG_AI2_B_CLKCR_tmps_b_2(data)                                      (0x00100000&((data)<<20))
#define  PLL_REG_AI2_B_CLKCR_psc_b_2(data)                                       (0x00080000&((data)<<19))
#define  PLL_REG_AI2_B_CLKCR_swcs_b_2(data)                                      (0x0000FE00&((data)<<9))
#define  PLL_REG_AI2_B_CLKCR_sd_b_2(data)                                        (0x00000002&((data)<<1))
#define  PLL_REG_AI2_B_CLKCR_su_b_2(data)                                        (0x00000001&(data))
#define  PLL_REG_AI2_B_CLKCR_get_swsce_b_2(data)                                 ((0x02000000&(data))>>25)
#define  PLL_REG_AI2_B_CLKCR_get_tme_b_2(data)                                   ((0x00800000&(data))>>23)
#define  PLL_REG_AI2_B_CLKCR_get_tmps_b_2(data)                                  ((0x00100000&(data))>>20)
#define  PLL_REG_AI2_B_CLKCR_get_psc_b_2(data)                                   ((0x00080000&(data))>>19)
#define  PLL_REG_AI2_B_CLKCR_get_swcs_b_2(data)                                  ((0x0000FE00&(data))>>9)
#define  PLL_REG_AI2_B_CLKCR_get_sd_b_2(data)                                    ((0x00000002&(data))>>1)
#define  PLL_REG_AI2_B_CLKCR_get_su_b_2(data)                                    (0x00000001&(data))

#define  PLL_REG_TEMP_SENSOR_1                                                   0x18000380
#define  PLL_REG_TEMP_SENSOR_1_reg_addr                                          "0xB8000380"
#define  PLL_REG_TEMP_SENSOR_1_reg                                               0xB8000380
#define  PLL_REG_TEMP_SENSOR_1_inst_addr                                         "0x0008"
#define  set_PLL_REG_TEMP_SENSOR_1_reg(data)                                     (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_1_reg)=data)
#define  get_PLL_REG_TEMP_SENSOR_1_reg                                           (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_1_reg))
#define  PLL_REG_TEMP_SENSOR_1_tm_a_shift                                        (0)
#define  PLL_REG_TEMP_SENSOR_1_tm_a_mask                                         (0x1FFFFFFF)
#define  PLL_REG_TEMP_SENSOR_1_tm_a(data)                                        (0x1FFFFFFF&(data))
#define  PLL_REG_TEMP_SENSOR_1_get_tm_a(data)                                    (0x1FFFFFFF&(data))

#define  PLL_REG_TEMP_SENSOR_2                                                   0x18000384
#define  PLL_REG_TEMP_SENSOR_2_reg_addr                                          "0xB8000384"
#define  PLL_REG_TEMP_SENSOR_2_reg                                               0xB8000384
#define  PLL_REG_TEMP_SENSOR_2_inst_addr                                         "0x0009"
#define  set_PLL_REG_TEMP_SENSOR_2_reg(data)                                     (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_2_reg)=data)
#define  get_PLL_REG_TEMP_SENSOR_2_reg                                           (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_2_reg))
#define  PLL_REG_TEMP_SENSOR_2_tm_b_shift                                        (10)
#define  PLL_REG_TEMP_SENSOR_2_tm_adccksel_shift                                 (7)
#define  PLL_REG_TEMP_SENSOR_2_tm_cal_en_shift                                   (6)
#define  PLL_REG_TEMP_SENSOR_2_tm_biaschop_shift                                 (5)
#define  PLL_REG_TEMP_SENSOR_2_tm_chopen_shift                                   (4)
#define  PLL_REG_TEMP_SENSOR_2_tm_cksourcesel_shift                              (3)
#define  PLL_REG_TEMP_SENSOR_2_tm_dsr_shift                                      (0)
#define  PLL_REG_TEMP_SENSOR_2_tm_b_mask                                         (0xFFFFFC00)
#define  PLL_REG_TEMP_SENSOR_2_tm_adccksel_mask                                  (0x00000380)
#define  PLL_REG_TEMP_SENSOR_2_tm_cal_en_mask                                    (0x00000040)
#define  PLL_REG_TEMP_SENSOR_2_tm_biaschop_mask                                  (0x00000020)
#define  PLL_REG_TEMP_SENSOR_2_tm_chopen_mask                                    (0x00000010)
#define  PLL_REG_TEMP_SENSOR_2_tm_cksourcesel_mask                               (0x00000008)
#define  PLL_REG_TEMP_SENSOR_2_tm_dsr_mask                                       (0x00000007)
#define  PLL_REG_TEMP_SENSOR_2_tm_b(data)                                        (0xFFFFFC00&((data)<<10))
#define  PLL_REG_TEMP_SENSOR_2_tm_adccksel(data)                                 (0x00000380&((data)<<7))
#define  PLL_REG_TEMP_SENSOR_2_tm_cal_en(data)                                   (0x00000040&((data)<<6))
#define  PLL_REG_TEMP_SENSOR_2_tm_biaschop(data)                                 (0x00000020&((data)<<5))
#define  PLL_REG_TEMP_SENSOR_2_tm_chopen(data)                                   (0x00000010&((data)<<4))
#define  PLL_REG_TEMP_SENSOR_2_tm_cksourcesel(data)                              (0x00000008&((data)<<3))
#define  PLL_REG_TEMP_SENSOR_2_tm_dsr(data)                                      (0x00000007&(data))
#define  PLL_REG_TEMP_SENSOR_2_get_tm_b(data)                                    ((0xFFFFFC00&(data))>>10)
#define  PLL_REG_TEMP_SENSOR_2_get_tm_adccksel(data)                             ((0x00000380&(data))>>7)
#define  PLL_REG_TEMP_SENSOR_2_get_tm_cal_en(data)                               ((0x00000040&(data))>>6)
#define  PLL_REG_TEMP_SENSOR_2_get_tm_biaschop(data)                             ((0x00000020&(data))>>5)
#define  PLL_REG_TEMP_SENSOR_2_get_tm_chopen(data)                               ((0x00000010&(data))>>4)
#define  PLL_REG_TEMP_SENSOR_2_get_tm_cksourcesel(data)                          ((0x00000008&(data))>>3)
#define  PLL_REG_TEMP_SENSOR_2_get_tm_dsr(data)                                  (0x00000007&(data))

#define  PLL_REG_TEMP_SENSOR_3                                                   0x18000388
#define  PLL_REG_TEMP_SENSOR_3_reg_addr                                          "0xB8000388"
#define  PLL_REG_TEMP_SENSOR_3_reg                                               0xB8000388
#define  PLL_REG_TEMP_SENSOR_3_inst_addr                                         "0x000A"
#define  set_PLL_REG_TEMP_SENSOR_3_reg(data)                                     (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_3_reg)=data)
#define  get_PLL_REG_TEMP_SENSOR_3_reg                                           (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_3_reg))
#define  PLL_REG_TEMP_SENSOR_3_dummy_31_shift                                    (31)
#define  PLL_REG_TEMP_SENSOR_3_tm_filteredgesel_shift                            (30)
#define  PLL_REG_TEMP_SENSOR_3_tm_hold_en_shift                                  (29)
#define  PLL_REG_TEMP_SENSOR_3_tm_order3_shift                                   (28)
#define  PLL_REG_TEMP_SENSOR_3_tm_offset_shift                                   (6)
#define  PLL_REG_TEMP_SENSOR_3_tm_pow_shift                                      (5)
#define  PLL_REG_TEMP_SENSOR_3_dummy_31_mask                                     (0x80000000)
#define  PLL_REG_TEMP_SENSOR_3_tm_filteredgesel_mask                             (0x40000000)
#define  PLL_REG_TEMP_SENSOR_3_tm_hold_en_mask                                   (0x20000000)
#define  PLL_REG_TEMP_SENSOR_3_tm_order3_mask                                    (0x10000000)
#define  PLL_REG_TEMP_SENSOR_3_tm_offset_mask                                    (0x0FFFFFC0)
#define  PLL_REG_TEMP_SENSOR_3_tm_pow_mask                                       (0x00000020)
#define  PLL_REG_TEMP_SENSOR_3_dummy_31(data)                                    (0x80000000&((data)<<31))
#define  PLL_REG_TEMP_SENSOR_3_tm_filteredgesel(data)                            (0x40000000&((data)<<30))
#define  PLL_REG_TEMP_SENSOR_3_tm_hold_en(data)                                  (0x20000000&((data)<<29))
#define  PLL_REG_TEMP_SENSOR_3_tm_order3(data)                                   (0x10000000&((data)<<28))
#define  PLL_REG_TEMP_SENSOR_3_tm_offset(data)                                   (0x0FFFFFC0&((data)<<6))
#define  PLL_REG_TEMP_SENSOR_3_tm_pow(data)                                      (0x00000020&((data)<<5))
#define  PLL_REG_TEMP_SENSOR_3_get_dummy_31(data)                                ((0x80000000&(data))>>31)
#define  PLL_REG_TEMP_SENSOR_3_get_tm_filteredgesel(data)                        ((0x40000000&(data))>>30)
#define  PLL_REG_TEMP_SENSOR_3_get_tm_hold_en(data)                              ((0x20000000&(data))>>29)
#define  PLL_REG_TEMP_SENSOR_3_get_tm_order3(data)                               ((0x10000000&(data))>>28)
#define  PLL_REG_TEMP_SENSOR_3_get_tm_offset(data)                               ((0x0FFFFFC0&(data))>>6)
#define  PLL_REG_TEMP_SENSOR_3_get_tm_pow(data)                                  ((0x00000020&(data))>>5)

#define  PLL_REG_TEMP_SENSOR_4                                                   0x1800038C
#define  PLL_REG_TEMP_SENSOR_4_reg_addr                                          "0xB800038C"
#define  PLL_REG_TEMP_SENSOR_4_reg                                               0xB800038C
#define  PLL_REG_TEMP_SENSOR_4_inst_addr                                         "0x000B"
#define  set_PLL_REG_TEMP_SENSOR_4_reg(data)                                     (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_4_reg)=data)
#define  get_PLL_REG_TEMP_SENSOR_4_reg                                           (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_4_reg))
#define  PLL_REG_TEMP_SENSOR_4_tm_r_shift                                        (8)
#define  PLL_REG_TEMP_SENSOR_4_tm_opcursel_shift                                 (6)
#define  PLL_REG_TEMP_SENSOR_4_tm_hold_dly_shift                                 (4)
#define  PLL_REG_TEMP_SENSOR_4_tm_osccursel_shift                                (2)
#define  PLL_REG_TEMP_SENSOR_4_tm_resol_shift                                    (0)
#define  PLL_REG_TEMP_SENSOR_4_tm_r_mask                                         (0xFFFFFF00)
#define  PLL_REG_TEMP_SENSOR_4_tm_opcursel_mask                                  (0x000000C0)
#define  PLL_REG_TEMP_SENSOR_4_tm_hold_dly_mask                                  (0x00000030)
#define  PLL_REG_TEMP_SENSOR_4_tm_osccursel_mask                                 (0x0000000C)
#define  PLL_REG_TEMP_SENSOR_4_tm_resol_mask                                     (0x00000003)
#define  PLL_REG_TEMP_SENSOR_4_tm_r(data)                                        (0xFFFFFF00&((data)<<8))
#define  PLL_REG_TEMP_SENSOR_4_tm_opcursel(data)                                 (0x000000C0&((data)<<6))
#define  PLL_REG_TEMP_SENSOR_4_tm_hold_dly(data)                                 (0x00000030&((data)<<4))
#define  PLL_REG_TEMP_SENSOR_4_tm_osccursel(data)                                (0x0000000C&((data)<<2))
#define  PLL_REG_TEMP_SENSOR_4_tm_resol(data)                                    (0x00000003&(data))
#define  PLL_REG_TEMP_SENSOR_4_get_tm_r(data)                                    ((0xFFFFFF00&(data))>>8)
#define  PLL_REG_TEMP_SENSOR_4_get_tm_opcursel(data)                             ((0x000000C0&(data))>>6)
#define  PLL_REG_TEMP_SENSOR_4_get_tm_hold_dly(data)                             ((0x00000030&(data))>>4)
#define  PLL_REG_TEMP_SENSOR_4_get_tm_osccursel(data)                            ((0x0000000C&(data))>>2)
#define  PLL_REG_TEMP_SENSOR_4_get_tm_resol(data)                                (0x00000003&(data))

#define  PLL_REG_TEMP_SENSOR_5                                                   0x18000390
#define  PLL_REG_TEMP_SENSOR_5_reg_addr                                          "0xB8000390"
#define  PLL_REG_TEMP_SENSOR_5_reg                                               0xB8000390
#define  PLL_REG_TEMP_SENSOR_5_inst_addr                                         "0x000C"
#define  set_PLL_REG_TEMP_SENSOR_5_reg(data)                                     (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_5_reg)=data)
#define  get_PLL_REG_TEMP_SENSOR_5_reg                                           (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_5_reg))
#define  PLL_REG_TEMP_SENSOR_5_tm_rstb_shift                                     (31)
#define  PLL_REG_TEMP_SENSOR_5_tm_sdm_test_shift                                 (30)
#define  PLL_REG_TEMP_SENSOR_5_tm_sdm_test_en_shift                              (29)
#define  PLL_REG_TEMP_SENSOR_5_tm_test_en_shift                                  (28)
#define  PLL_REG_TEMP_SENSOR_5_tm_vcmsel_shift                                   (25)
#define  PLL_REG_TEMP_SENSOR_5_tm_vbe_biassel_shift                              (23)
#define  PLL_REG_TEMP_SENSOR_5_tm_chopfreqsel_shift                              (12)
#define  PLL_REG_TEMP_SENSOR_5_dummy_8_4_shift                                   (4)
#define  PLL_REG_TEMP_SENSOR_5_dummy_0_shift                                     (0)
#define  PLL_REG_TEMP_SENSOR_5_tm_rstb_mask                                      (0x80000000)
#define  PLL_REG_TEMP_SENSOR_5_tm_sdm_test_mask                                  (0x40000000)
#define  PLL_REG_TEMP_SENSOR_5_tm_sdm_test_en_mask                               (0x20000000)
#define  PLL_REG_TEMP_SENSOR_5_tm_test_en_mask                                   (0x10000000)
#define  PLL_REG_TEMP_SENSOR_5_tm_vcmsel_mask                                    (0x0E000000)
#define  PLL_REG_TEMP_SENSOR_5_tm_vbe_biassel_mask                               (0x01800000)
#define  PLL_REG_TEMP_SENSOR_5_tm_chopfreqsel_mask                               (0x007FF000)
#define  PLL_REG_TEMP_SENSOR_5_dummy_8_4_mask                                    (0x000001F0)
#define  PLL_REG_TEMP_SENSOR_5_dummy_0_mask                                      (0x00000001)
#define  PLL_REG_TEMP_SENSOR_5_tm_rstb(data)                                     (0x80000000&((data)<<31))
#define  PLL_REG_TEMP_SENSOR_5_tm_sdm_test(data)                                 (0x40000000&((data)<<30))
#define  PLL_REG_TEMP_SENSOR_5_tm_sdm_test_en(data)                              (0x20000000&((data)<<29))
#define  PLL_REG_TEMP_SENSOR_5_tm_test_en(data)                                  (0x10000000&((data)<<28))
#define  PLL_REG_TEMP_SENSOR_5_tm_vcmsel(data)                                   (0x0E000000&((data)<<25))
#define  PLL_REG_TEMP_SENSOR_5_tm_vbe_biassel(data)                              (0x01800000&((data)<<23))
#define  PLL_REG_TEMP_SENSOR_5_tm_chopfreqsel(data)                              (0x007FF000&((data)<<12))
#define  PLL_REG_TEMP_SENSOR_5_dummy_8_4(data)                                   (0x000001F0&((data)<<4))
#define  PLL_REG_TEMP_SENSOR_5_dummy_0(data)                                     (0x00000001&(data))
#define  PLL_REG_TEMP_SENSOR_5_get_tm_rstb(data)                                 ((0x80000000&(data))>>31)
#define  PLL_REG_TEMP_SENSOR_5_get_tm_sdm_test(data)                             ((0x40000000&(data))>>30)
#define  PLL_REG_TEMP_SENSOR_5_get_tm_sdm_test_en(data)                          ((0x20000000&(data))>>29)
#define  PLL_REG_TEMP_SENSOR_5_get_tm_test_en(data)                              ((0x10000000&(data))>>28)
#define  PLL_REG_TEMP_SENSOR_5_get_tm_vcmsel(data)                               ((0x0E000000&(data))>>25)
#define  PLL_REG_TEMP_SENSOR_5_get_tm_vbe_biassel(data)                          ((0x01800000&(data))>>23)
#define  PLL_REG_TEMP_SENSOR_5_get_tm_chopfreqsel(data)                          ((0x007FF000&(data))>>12)
#define  PLL_REG_TEMP_SENSOR_5_get_dummy_8_4(data)                               ((0x000001F0&(data))>>4)
#define  PLL_REG_TEMP_SENSOR_5_get_dummy_0(data)                                 (0x00000001&(data))

#define  PLL_REG_TEMP_SENSOR_6                                                   0x18000394
#define  PLL_REG_TEMP_SENSOR_6_reg_addr                                          "0xB8000394"
#define  PLL_REG_TEMP_SENSOR_6_reg                                               0xB8000394
#define  PLL_REG_TEMP_SENSOR_6_inst_addr                                         "0x000D"
#define  set_PLL_REG_TEMP_SENSOR_6_reg(data)                                     (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_6_reg)=data)
#define  get_PLL_REG_TEMP_SENSOR_6_reg                                           (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_6_reg))
#define  PLL_REG_TEMP_SENSOR_6_dummy_31_16_shift                                 (16)
#define  PLL_REG_TEMP_SENSOR_6_dummy_15_0_shift                                  (0)
#define  PLL_REG_TEMP_SENSOR_6_dummy_31_16_mask                                  (0xFFFF0000)
#define  PLL_REG_TEMP_SENSOR_6_dummy_15_0_mask                                   (0x0000FFFF)
#define  PLL_REG_TEMP_SENSOR_6_dummy_31_16(data)                                 (0xFFFF0000&((data)<<16))
#define  PLL_REG_TEMP_SENSOR_6_dummy_15_0(data)                                  (0x0000FFFF&(data))
#define  PLL_REG_TEMP_SENSOR_6_get_dummy_31_16(data)                             ((0xFFFF0000&(data))>>16)
#define  PLL_REG_TEMP_SENSOR_6_get_dummy_15_0(data)                              (0x0000FFFF&(data))

#define  PLL_REG_TEMP_SENSOR_7                                                   0x18000398
#define  PLL_REG_TEMP_SENSOR_7_reg_addr                                          "0xB8000398"
#define  PLL_REG_TEMP_SENSOR_7_reg                                               0xB8000398
#define  PLL_REG_TEMP_SENSOR_7_inst_addr                                         "0x000E"
#define  set_PLL_REG_TEMP_SENSOR_7_reg(data)                                     (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_7_reg)=data)
#define  get_PLL_REG_TEMP_SENSOR_7_reg                                           (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_7_reg))
#define  PLL_REG_TEMP_SENSOR_7_dummy_31_16_shift                                 (16)
#define  PLL_REG_TEMP_SENSOR_7_dummy_15_shift                                    (15)
#define  PLL_REG_TEMP_SENSOR_7_dummy_14_12_shift                                 (12)
#define  PLL_REG_TEMP_SENSOR_7_dummy_11_10_shift                                 (10)
#define  PLL_REG_TEMP_SENSOR_7_dummy_9_7_shift                                   (7)
#define  PLL_REG_TEMP_SENSOR_7_dummy_6_shift                                     (6)
#define  PLL_REG_TEMP_SENSOR_7_dummy_5_shift                                     (5)
#define  PLL_REG_TEMP_SENSOR_7_dummy_4_shift                                     (4)
#define  PLL_REG_TEMP_SENSOR_7_tm_biasdem_sel_shift                              (3)
#define  PLL_REG_TEMP_SENSOR_7_td_wrep_edge_sel_shift                            (1)
#define  PLL_REG_TEMP_SENSOR_7_dummy_0_shift                                     (0)
#define  PLL_REG_TEMP_SENSOR_7_dummy_31_16_mask                                  (0xFFFF0000)
#define  PLL_REG_TEMP_SENSOR_7_dummy_15_mask                                     (0x00008000)
#define  PLL_REG_TEMP_SENSOR_7_dummy_14_12_mask                                  (0x00007000)
#define  PLL_REG_TEMP_SENSOR_7_dummy_11_10_mask                                  (0x00000C00)
#define  PLL_REG_TEMP_SENSOR_7_dummy_9_7_mask                                    (0x00000380)
#define  PLL_REG_TEMP_SENSOR_7_dummy_6_mask                                      (0x00000040)
#define  PLL_REG_TEMP_SENSOR_7_dummy_5_mask                                      (0x00000020)
#define  PLL_REG_TEMP_SENSOR_7_dummy_4_mask                                      (0x00000010)
#define  PLL_REG_TEMP_SENSOR_7_tm_biasdem_sel_mask                               (0x00000008)
#define  PLL_REG_TEMP_SENSOR_7_td_wrep_edge_sel_mask                             (0x00000002)
#define  PLL_REG_TEMP_SENSOR_7_dummy_0_mask                                      (0x00000001)
#define  PLL_REG_TEMP_SENSOR_7_dummy_31_16(data)                                 (0xFFFF0000&((data)<<16))
#define  PLL_REG_TEMP_SENSOR_7_dummy_15(data)                                    (0x00008000&((data)<<15))
#define  PLL_REG_TEMP_SENSOR_7_dummy_14_12(data)                                 (0x00007000&((data)<<12))
#define  PLL_REG_TEMP_SENSOR_7_dummy_11_10(data)                                 (0x00000C00&((data)<<10))
#define  PLL_REG_TEMP_SENSOR_7_dummy_9_7(data)                                   (0x00000380&((data)<<7))
#define  PLL_REG_TEMP_SENSOR_7_dummy_6(data)                                     (0x00000040&((data)<<6))
#define  PLL_REG_TEMP_SENSOR_7_dummy_5(data)                                     (0x00000020&((data)<<5))
#define  PLL_REG_TEMP_SENSOR_7_dummy_4(data)                                     (0x00000010&((data)<<4))
#define  PLL_REG_TEMP_SENSOR_7_tm_biasdem_sel(data)                              (0x00000008&((data)<<3))
#define  PLL_REG_TEMP_SENSOR_7_td_wrep_edge_sel(data)                            (0x00000002&((data)<<1))
#define  PLL_REG_TEMP_SENSOR_7_dummy_0(data)                                     (0x00000001&(data))
#define  PLL_REG_TEMP_SENSOR_7_get_dummy_31_16(data)                             ((0xFFFF0000&(data))>>16)
#define  PLL_REG_TEMP_SENSOR_7_get_dummy_15(data)                                ((0x00008000&(data))>>15)
#define  PLL_REG_TEMP_SENSOR_7_get_dummy_14_12(data)                             ((0x00007000&(data))>>12)
#define  PLL_REG_TEMP_SENSOR_7_get_dummy_11_10(data)                             ((0x00000C00&(data))>>10)
#define  PLL_REG_TEMP_SENSOR_7_get_dummy_9_7(data)                               ((0x00000380&(data))>>7)
#define  PLL_REG_TEMP_SENSOR_7_get_dummy_6(data)                                 ((0x00000040&(data))>>6)
#define  PLL_REG_TEMP_SENSOR_7_get_dummy_5(data)                                 ((0x00000020&(data))>>5)
#define  PLL_REG_TEMP_SENSOR_7_get_dummy_4(data)                                 ((0x00000010&(data))>>4)
#define  PLL_REG_TEMP_SENSOR_7_get_tm_biasdem_sel(data)                          ((0x00000008&(data))>>3)
#define  PLL_REG_TEMP_SENSOR_7_get_td_wrep_edge_sel(data)                        ((0x00000002&(data))>>1)
#define  PLL_REG_TEMP_SENSOR_7_get_dummy_0(data)                                 (0x00000001&(data))

#define  PLL_REG_TEMP_SENSOR_8                                                   0x1800039C
#define  PLL_REG_TEMP_SENSOR_8_reg_addr                                          "0xB800039C"
#define  PLL_REG_TEMP_SENSOR_8_reg                                               0xB800039C
#define  PLL_REG_TEMP_SENSOR_8_inst_addr                                         "0x000F"
#define  set_PLL_REG_TEMP_SENSOR_8_reg(data)                                     (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_8_reg)=data)
#define  get_PLL_REG_TEMP_SENSOR_8_reg                                           (*((volatile unsigned int*)PLL_REG_TEMP_SENSOR_8_reg))
#define  PLL_REG_TEMP_SENSOR_8_tm_s_shift                                        (0)
#define  PLL_REG_TEMP_SENSOR_8_tm_s_mask                                         (0x007FFFFF)
#define  PLL_REG_TEMP_SENSOR_8_tm_s(data)                                        (0x007FFFFF&(data))
#define  PLL_REG_TEMP_SENSOR_8_get_tm_s(data)                                    (0x007FFFFF&(data))

#define  PLL_REG_THERMAL_RESULT_1                                                0x180003A0
#define  PLL_REG_THERMAL_RESULT_1_reg_addr                                       "0xB80003A0"
#define  PLL_REG_THERMAL_RESULT_1_reg                                            0xB80003A0
#define  PLL_REG_THERMAL_RESULT_1_inst_addr                                      "0x0010"
#define  set_PLL_REG_THERMAL_RESULT_1_reg(data)                                  (*((volatile unsigned int*)PLL_REG_THERMAL_RESULT_1_reg)=data)
#define  get_PLL_REG_THERMAL_RESULT_1_reg                                        (*((volatile unsigned int*)PLL_REG_THERMAL_RESULT_1_reg))
#define  PLL_REG_THERMAL_RESULT_1_dummy_30_24_shift                              (24)
#define  PLL_REG_THERMAL_RESULT_1_ct_out_o_tm_shift                              (0)
#define  PLL_REG_THERMAL_RESULT_1_dummy_30_24_mask                               (0x7F000000)
#define  PLL_REG_THERMAL_RESULT_1_ct_out_o_tm_mask                               (0x0007FFFF)
#define  PLL_REG_THERMAL_RESULT_1_dummy_30_24(data)                              (0x7F000000&((data)<<24))
#define  PLL_REG_THERMAL_RESULT_1_ct_out_o_tm(data)                              (0x0007FFFF&(data))
#define  PLL_REG_THERMAL_RESULT_1_get_dummy_30_24(data)                          ((0x7F000000&(data))>>24)
#define  PLL_REG_THERMAL_RESULT_1_get_ct_out_o_tm(data)                          (0x0007FFFF&(data))

#define  PLL_REG_THERMAL_RESULT_2                                                0x180003A4
#define  PLL_REG_THERMAL_RESULT_2_reg_addr                                       "0xB80003A4"
#define  PLL_REG_THERMAL_RESULT_2_reg                                            0xB80003A4
#define  PLL_REG_THERMAL_RESULT_2_inst_addr                                      "0x0011"
#define  set_PLL_REG_THERMAL_RESULT_2_reg(data)                                  (*((volatile unsigned int*)PLL_REG_THERMAL_RESULT_2_reg)=data)
#define  get_PLL_REG_THERMAL_RESULT_2_reg                                        (*((volatile unsigned int*)PLL_REG_THERMAL_RESULT_2_reg))
#define  PLL_REG_THERMAL_RESULT_2_u_out_tm_shift                                 (0)
#define  PLL_REG_THERMAL_RESULT_2_u_out_tm_mask                                  (0x003FFFFF)
#define  PLL_REG_THERMAL_RESULT_2_u_out_tm(data)                                 (0x003FFFFF&(data))
#define  PLL_REG_THERMAL_RESULT_2_get_u_out_tm(data)                             (0x003FFFFF&(data))

#define  PLL_REG_THERMAL_IRQ_Threshold_1                                         0x180003A8
#define  PLL_REG_THERMAL_IRQ_Threshold_1_reg_addr                                "0xB80003A8"
#define  PLL_REG_THERMAL_IRQ_Threshold_1_reg                                     0xB80003A8
#define  PLL_REG_THERMAL_IRQ_Threshold_1_inst_addr                               "0x0012"
#define  set_PLL_REG_THERMAL_IRQ_Threshold_1_reg(data)                           (*((volatile unsigned int*)PLL_REG_THERMAL_IRQ_Threshold_1_reg)=data)
#define  get_PLL_REG_THERMAL_IRQ_Threshold_1_reg                                 (*((volatile unsigned int*)PLL_REG_THERMAL_IRQ_Threshold_1_reg))
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_ie_shift                 (31)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_irq_status_shift         (29)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_kcpu_ie_shift            (27)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_irq_kcpu_status_shift    (25)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_thh_shift                (0)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_ie_mask                  (0x80000000)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_irq_status_mask          (0x60000000)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_kcpu_ie_mask             (0x08000000)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_irq_kcpu_status_mask     (0x06000000)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_thh_mask                 (0x0007FFFF)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_ie(data)                 (0x80000000&((data)<<31))
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_irq_status(data)         (0x60000000&((data)<<29))
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_kcpu_ie(data)            (0x08000000&((data)<<27))
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_irq_kcpu_status(data)    (0x06000000&((data)<<25))
#define  PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_thh(data)                (0x0007FFFF&(data))
#define  PLL_REG_THERMAL_IRQ_Threshold_1_get_thermal_sensor_ie(data)             ((0x80000000&(data))>>31)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_get_thermal_sensor_irq_status(data)     ((0x60000000&(data))>>29)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_get_thermal_sensor_kcpu_ie(data)        ((0x08000000&(data))>>27)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_get_thermal_sensor_irq_kcpu_status(data) ((0x06000000&(data))>>25)
#define  PLL_REG_THERMAL_IRQ_Threshold_1_get_thermal_sensor_thh(data)            (0x0007FFFF&(data))

#define  PLL_REG_THERMAL_IRQ_Threshold_2                                         0x180003AC
#define  PLL_REG_THERMAL_IRQ_Threshold_2_reg_addr                                "0xB80003AC"
#define  PLL_REG_THERMAL_IRQ_Threshold_2_reg                                     0xB80003AC
#define  PLL_REG_THERMAL_IRQ_Threshold_2_inst_addr                               "0x0013"
#define  set_PLL_REG_THERMAL_IRQ_Threshold_2_reg(data)                           (*((volatile unsigned int*)PLL_REG_THERMAL_IRQ_Threshold_2_reg)=data)
#define  get_PLL_REG_THERMAL_IRQ_Threshold_2_reg                                 (*((volatile unsigned int*)PLL_REG_THERMAL_IRQ_Threshold_2_reg))
#define  PLL_REG_THERMAL_IRQ_Threshold_2_thermal_sensor_thl_shift                (0)
#define  PLL_REG_THERMAL_IRQ_Threshold_2_thermal_sensor_thl_mask                 (0x0007FFFF)
#define  PLL_REG_THERMAL_IRQ_Threshold_2_thermal_sensor_thl(data)                (0x0007FFFF&(data))
#define  PLL_REG_THERMAL_IRQ_Threshold_2_get_thermal_sensor_thl(data)            (0x0007FFFF&(data))

#define  PLL_REG_SYS_PLL_KCPU1                                                   0x180003B0
#define  PLL_REG_SYS_PLL_KCPU1_reg_addr                                          "0xB80003B0"
#define  PLL_REG_SYS_PLL_KCPU1_reg                                               0xB80003B0
#define  PLL_REG_SYS_PLL_KCPU1_inst_addr                                         "0x0014"
#define  set_PLL_REG_SYS_PLL_KCPU1_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_PLL_KCPU1_reg)=data)
#define  get_PLL_REG_SYS_PLL_KCPU1_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_PLL_KCPU1_reg))
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_tst_shift                                 (24)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_n_shift                                   (20)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_m_shift                                   (12)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_ip_shift                                  (9)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_o_shift                                   (7)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_wdset_shift                               (6)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_wdrst_shift                               (5)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_cs_shift                                  (3)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_rs_shift                                  (0)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_tst_mask                                  (0x01000000)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_n_mask                                    (0x00300000)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_m_mask                                    (0x000FF000)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_ip_mask                                   (0x00000E00)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_o_mask                                    (0x00000180)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_wdset_mask                                (0x00000040)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_wdrst_mask                                (0x00000020)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_cs_mask                                   (0x00000018)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_rs_mask                                   (0x00000007)
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_tst(data)                                 (0x01000000&((data)<<24))
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_n(data)                                   (0x00300000&((data)<<20))
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_m(data)                                   (0x000FF000&((data)<<12))
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_ip(data)                                  (0x00000E00&((data)<<9))
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_o(data)                                   (0x00000180&((data)<<7))
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_wdset(data)                               (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_wdrst(data)                               (0x00000020&((data)<<5))
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_cs(data)                                  (0x00000018&((data)<<3))
#define  PLL_REG_SYS_PLL_KCPU1_pllkcpu_rs(data)                                  (0x00000007&(data))
#define  PLL_REG_SYS_PLL_KCPU1_get_pllkcpu_tst(data)                             ((0x01000000&(data))>>24)
#define  PLL_REG_SYS_PLL_KCPU1_get_pllkcpu_n(data)                               ((0x00300000&(data))>>20)
#define  PLL_REG_SYS_PLL_KCPU1_get_pllkcpu_m(data)                               ((0x000FF000&(data))>>12)
#define  PLL_REG_SYS_PLL_KCPU1_get_pllkcpu_ip(data)                              ((0x00000E00&(data))>>9)
#define  PLL_REG_SYS_PLL_KCPU1_get_pllkcpu_o(data)                               ((0x00000180&(data))>>7)
#define  PLL_REG_SYS_PLL_KCPU1_get_pllkcpu_wdset(data)                           ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_KCPU1_get_pllkcpu_wdrst(data)                           ((0x00000020&(data))>>5)
#define  PLL_REG_SYS_PLL_KCPU1_get_pllkcpu_cs(data)                              ((0x00000018&(data))>>3)
#define  PLL_REG_SYS_PLL_KCPU1_get_pllkcpu_rs(data)                              (0x00000007&(data))

#define  PLL_REG_SYS_PLL_KCPU2                                                   0x180003B4
#define  PLL_REG_SYS_PLL_KCPU2_reg_addr                                          "0xB80003B4"
#define  PLL_REG_SYS_PLL_KCPU2_reg                                               0xB80003B4
#define  PLL_REG_SYS_PLL_KCPU2_inst_addr                                         "0x0015"
#define  set_PLL_REG_SYS_PLL_KCPU2_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_PLL_KCPU2_reg)=data)
#define  get_PLL_REG_SYS_PLL_KCPU2_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_PLL_KCPU2_reg))
#define  PLL_REG_SYS_PLL_KCPU2_pllkcpu_oeb_shift                                 (2)
#define  PLL_REG_SYS_PLL_KCPU2_pllkcpu_rstb_shift                                (1)
#define  PLL_REG_SYS_PLL_KCPU2_pllkcpu_pow_shift                                 (0)
#define  PLL_REG_SYS_PLL_KCPU2_pllkcpu_oeb_mask                                  (0x00000004)
#define  PLL_REG_SYS_PLL_KCPU2_pllkcpu_rstb_mask                                 (0x00000002)
#define  PLL_REG_SYS_PLL_KCPU2_pllkcpu_pow_mask                                  (0x00000001)
#define  PLL_REG_SYS_PLL_KCPU2_pllkcpu_oeb(data)                                 (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_KCPU2_pllkcpu_rstb(data)                                (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_KCPU2_pllkcpu_pow(data)                                 (0x00000001&(data))
#define  PLL_REG_SYS_PLL_KCPU2_get_pllkcpu_oeb(data)                             ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_KCPU2_get_pllkcpu_rstb(data)                            ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_KCPU2_get_pllkcpu_pow(data)                             (0x00000001&(data))

#define  PLL_REG_PLL_SSC_BUS                                                     0x180003C0
#define  PLL_REG_PLL_SSC_BUS_reg_addr                                            "0xB80003C0"
#define  PLL_REG_PLL_SSC_BUS_reg                                                 0xB80003C0
#define  PLL_REG_PLL_SSC_BUS_inst_addr                                           "0x0016"
#define  set_PLL_REG_PLL_SSC_BUS_reg(data)                                       (*((volatile unsigned int*)PLL_REG_PLL_SSC_BUS_reg)=data)
#define  get_PLL_REG_PLL_SSC_BUS_reg                                             (*((volatile unsigned int*)PLL_REG_PLL_SSC_BUS_reg))
#define  PLL_REG_PLL_SSC_BUS_pllbus_gran_auto_rst_shift                          (28)
#define  PLL_REG_PLL_SSC_BUS_pllbus_dot_gran_shift                               (24)
#define  PLL_REG_PLL_SSC_BUS_pllbus_gran_est_shift                               (4)
#define  PLL_REG_PLL_SSC_BUS_pllbus_en_ssc_shift                                 (0)
#define  PLL_REG_PLL_SSC_BUS_pllbus_gran_auto_rst_mask                           (0x10000000)
#define  PLL_REG_PLL_SSC_BUS_pllbus_dot_gran_mask                                (0x07000000)
#define  PLL_REG_PLL_SSC_BUS_pllbus_gran_est_mask                                (0x007FFFF0)
#define  PLL_REG_PLL_SSC_BUS_pllbus_en_ssc_mask                                  (0x00000001)
#define  PLL_REG_PLL_SSC_BUS_pllbus_gran_auto_rst(data)                          (0x10000000&((data)<<28))
#define  PLL_REG_PLL_SSC_BUS_pllbus_dot_gran(data)                               (0x07000000&((data)<<24))
#define  PLL_REG_PLL_SSC_BUS_pllbus_gran_est(data)                               (0x007FFFF0&((data)<<4))
#define  PLL_REG_PLL_SSC_BUS_pllbus_en_ssc(data)                                 (0x00000001&(data))
#define  PLL_REG_PLL_SSC_BUS_get_pllbus_gran_auto_rst(data)                      ((0x10000000&(data))>>28)
#define  PLL_REG_PLL_SSC_BUS_get_pllbus_dot_gran(data)                           ((0x07000000&(data))>>24)
#define  PLL_REG_PLL_SSC_BUS_get_pllbus_gran_est(data)                           ((0x007FFFF0&(data))>>4)
#define  PLL_REG_PLL_SSC_BUS_get_pllbus_en_ssc(data)                             (0x00000001&(data))

#define  PLL_REG_PLL_SSC_BUS_2                                                   0x180003C4
#define  PLL_REG_PLL_SSC_BUS_2_reg_addr                                          "0xB80003C4"
#define  PLL_REG_PLL_SSC_BUS_2_reg                                               0xB80003C4
#define  PLL_REG_PLL_SSC_BUS_2_inst_addr                                         "0x0017"
#define  set_PLL_REG_PLL_SSC_BUS_2_reg(data)                                     (*((volatile unsigned int*)PLL_REG_PLL_SSC_BUS_2_reg)=data)
#define  get_PLL_REG_PLL_SSC_BUS_2_reg                                           (*((volatile unsigned int*)PLL_REG_PLL_SSC_BUS_2_reg))
#define  PLL_REG_PLL_SSC_BUS_2_pllbus_ncode_ssc_shift                            (16)
#define  PLL_REG_PLL_SSC_BUS_2_pllbus_fcode_ssc_shift                            (0)
#define  PLL_REG_PLL_SSC_BUS_2_pllbus_ncode_ssc_mask                             (0x00FF0000)
#define  PLL_REG_PLL_SSC_BUS_2_pllbus_fcode_ssc_mask                             (0x000007FF)
#define  PLL_REG_PLL_SSC_BUS_2_pllbus_ncode_ssc(data)                            (0x00FF0000&((data)<<16))
#define  PLL_REG_PLL_SSC_BUS_2_pllbus_fcode_ssc(data)                            (0x000007FF&(data))
#define  PLL_REG_PLL_SSC_BUS_2_get_pllbus_ncode_ssc(data)                        ((0x00FF0000&(data))>>16)
#define  PLL_REG_PLL_SSC_BUS_2_get_pllbus_fcode_ssc(data)                        (0x000007FF&(data))

#define  PLL_REG_PLL_SSC_BUSH                                                    0x180003D0
#define  PLL_REG_PLL_SSC_BUSH_reg_addr                                           "0xB80003D0"
#define  PLL_REG_PLL_SSC_BUSH_reg                                                0xB80003D0
#define  PLL_REG_PLL_SSC_BUSH_inst_addr                                          "0x0018"
#define  set_PLL_REG_PLL_SSC_BUSH_reg(data)                                      (*((volatile unsigned int*)PLL_REG_PLL_SSC_BUSH_reg)=data)
#define  get_PLL_REG_PLL_SSC_BUSH_reg                                            (*((volatile unsigned int*)PLL_REG_PLL_SSC_BUSH_reg))
#define  PLL_REG_PLL_SSC_BUSH_pllbus_gran_auto_rst_h_shift                       (28)
#define  PLL_REG_PLL_SSC_BUSH_pllbus_dot_gran_h_shift                            (24)
#define  PLL_REG_PLL_SSC_BUSH_pllbus_gran_est_h_shift                            (4)
#define  PLL_REG_PLL_SSC_BUSH_pllbus_en_ssc_h_shift                              (0)
#define  PLL_REG_PLL_SSC_BUSH_pllbus_gran_auto_rst_h_mask                        (0x10000000)
#define  PLL_REG_PLL_SSC_BUSH_pllbus_dot_gran_h_mask                             (0x07000000)
#define  PLL_REG_PLL_SSC_BUSH_pllbus_gran_est_h_mask                             (0x007FFFF0)
#define  PLL_REG_PLL_SSC_BUSH_pllbus_en_ssc_h_mask                               (0x00000001)
#define  PLL_REG_PLL_SSC_BUSH_pllbus_gran_auto_rst_h(data)                       (0x10000000&((data)<<28))
#define  PLL_REG_PLL_SSC_BUSH_pllbus_dot_gran_h(data)                            (0x07000000&((data)<<24))
#define  PLL_REG_PLL_SSC_BUSH_pllbus_gran_est_h(data)                            (0x007FFFF0&((data)<<4))
#define  PLL_REG_PLL_SSC_BUSH_pllbus_en_ssc_h(data)                              (0x00000001&(data))
#define  PLL_REG_PLL_SSC_BUSH_get_pllbus_gran_auto_rst_h(data)                   ((0x10000000&(data))>>28)
#define  PLL_REG_PLL_SSC_BUSH_get_pllbus_dot_gran_h(data)                        ((0x07000000&(data))>>24)
#define  PLL_REG_PLL_SSC_BUSH_get_pllbus_gran_est_h(data)                        ((0x007FFFF0&(data))>>4)
#define  PLL_REG_PLL_SSC_BUSH_get_pllbus_en_ssc_h(data)                          (0x00000001&(data))

#define  PLL_REG_PLL_SSC_BUSH_2                                                  0x180003D4
#define  PLL_REG_PLL_SSC_BUSH_2_reg_addr                                         "0xB80003D4"
#define  PLL_REG_PLL_SSC_BUSH_2_reg                                              0xB80003D4
#define  PLL_REG_PLL_SSC_BUSH_2_inst_addr                                        "0x0019"
#define  set_PLL_REG_PLL_SSC_BUSH_2_reg(data)                                    (*((volatile unsigned int*)PLL_REG_PLL_SSC_BUSH_2_reg)=data)
#define  get_PLL_REG_PLL_SSC_BUSH_2_reg                                          (*((volatile unsigned int*)PLL_REG_PLL_SSC_BUSH_2_reg))
#define  PLL_REG_PLL_SSC_BUSH_2_pllbus_ncode_ssc_h_shift                         (16)
#define  PLL_REG_PLL_SSC_BUSH_2_pllbus_fcode_ssc_h_shift                         (0)
#define  PLL_REG_PLL_SSC_BUSH_2_pllbus_ncode_ssc_h_mask                          (0x00FF0000)
#define  PLL_REG_PLL_SSC_BUSH_2_pllbus_fcode_ssc_h_mask                          (0x000007FF)
#define  PLL_REG_PLL_SSC_BUSH_2_pllbus_ncode_ssc_h(data)                         (0x00FF0000&((data)<<16))
#define  PLL_REG_PLL_SSC_BUSH_2_pllbus_fcode_ssc_h(data)                         (0x000007FF&(data))
#define  PLL_REG_PLL_SSC_BUSH_2_get_pllbus_ncode_ssc_h(data)                     ((0x00FF0000&(data))>>16)
#define  PLL_REG_PLL_SSC_BUSH_2_get_pllbus_fcode_ssc_h(data)                     (0x000007FF&(data))

#define  PLL_REG_PLL_SSC_DDSA                                                    0x180003E0
#define  PLL_REG_PLL_SSC_DDSA_reg_addr                                           "0xB80003E0"
#define  PLL_REG_PLL_SSC_DDSA_reg                                                0xB80003E0
#define  PLL_REG_PLL_SSC_DDSA_inst_addr                                          "0x001A"
#define  set_PLL_REG_PLL_SSC_DDSA_reg(data)                                      (*((volatile unsigned int*)PLL_REG_PLL_SSC_DDSA_reg)=data)
#define  get_PLL_REG_PLL_SSC_DDSA_reg                                            (*((volatile unsigned int*)PLL_REG_PLL_SSC_DDSA_reg))
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_gran_auto_rst_shift                        (28)
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_dot_gran_shift                             (24)
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_gran_est_shift                             (4)
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_en_ssc_shift                               (0)
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_gran_auto_rst_mask                         (0x10000000)
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_dot_gran_mask                              (0x07000000)
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_gran_est_mask                              (0x007FFFF0)
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_en_ssc_mask                                (0x00000001)
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_gran_auto_rst(data)                        (0x10000000&((data)<<28))
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_dot_gran(data)                             (0x07000000&((data)<<24))
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_gran_est(data)                             (0x007FFFF0&((data)<<4))
#define  PLL_REG_PLL_SSC_DDSA_pllddsa_en_ssc(data)                               (0x00000001&(data))
#define  PLL_REG_PLL_SSC_DDSA_get_pllddsa_gran_auto_rst(data)                    ((0x10000000&(data))>>28)
#define  PLL_REG_PLL_SSC_DDSA_get_pllddsa_dot_gran(data)                         ((0x07000000&(data))>>24)
#define  PLL_REG_PLL_SSC_DDSA_get_pllddsa_gran_est(data)                         ((0x007FFFF0&(data))>>4)
#define  PLL_REG_PLL_SSC_DDSA_get_pllddsa_en_ssc(data)                           (0x00000001&(data))

#define  PLL_REG_PLL_SSC_DDSA_2                                                  0x180003E4
#define  PLL_REG_PLL_SSC_DDSA_2_reg_addr                                         "0xB80003E4"
#define  PLL_REG_PLL_SSC_DDSA_2_reg                                              0xB80003E4
#define  PLL_REG_PLL_SSC_DDSA_2_inst_addr                                        "0x001B"
#define  set_PLL_REG_PLL_SSC_DDSA_2_reg(data)                                    (*((volatile unsigned int*)PLL_REG_PLL_SSC_DDSA_2_reg)=data)
#define  get_PLL_REG_PLL_SSC_DDSA_2_reg                                          (*((volatile unsigned int*)PLL_REG_PLL_SSC_DDSA_2_reg))
#define  PLL_REG_PLL_SSC_DDSA_2_pllddsa_ncode_ssc_shift                          (16)
#define  PLL_REG_PLL_SSC_DDSA_2_pllddsa_fcode_ssc_shift                          (0)
#define  PLL_REG_PLL_SSC_DDSA_2_pllddsa_ncode_ssc_mask                           (0x00FF0000)
#define  PLL_REG_PLL_SSC_DDSA_2_pllddsa_fcode_ssc_mask                           (0x000007FF)
#define  PLL_REG_PLL_SSC_DDSA_2_pllddsa_ncode_ssc(data)                          (0x00FF0000&((data)<<16))
#define  PLL_REG_PLL_SSC_DDSA_2_pllddsa_fcode_ssc(data)                          (0x000007FF&(data))
#define  PLL_REG_PLL_SSC_DDSA_2_get_pllddsa_ncode_ssc(data)                      ((0x00FF0000&(data))>>16)
#define  PLL_REG_PLL_SSC_DDSA_2_get_pllddsa_fcode_ssc(data)                      (0x000007FF&(data))

#define  PLL_REG_PLL_SSC_DDSB                                                    0x180003E8
#define  PLL_REG_PLL_SSC_DDSB_reg_addr                                           "0xB80003E8"
#define  PLL_REG_PLL_SSC_DDSB_reg                                                0xB80003E8
#define  PLL_REG_PLL_SSC_DDSB_inst_addr                                          "0x001C"
#define  set_PLL_REG_PLL_SSC_DDSB_reg(data)                                      (*((volatile unsigned int*)PLL_REG_PLL_SSC_DDSB_reg)=data)
#define  get_PLL_REG_PLL_SSC_DDSB_reg                                            (*((volatile unsigned int*)PLL_REG_PLL_SSC_DDSB_reg))
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_gran_auto_rst_shift                        (28)
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_dot_gran_shift                             (24)
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_gran_est_shift                             (4)
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_en_ssc_shift                               (0)
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_gran_auto_rst_mask                         (0x10000000)
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_dot_gran_mask                              (0x07000000)
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_gran_est_mask                              (0x007FFFF0)
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_en_ssc_mask                                (0x00000001)
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_gran_auto_rst(data)                        (0x10000000&((data)<<28))
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_dot_gran(data)                             (0x07000000&((data)<<24))
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_gran_est(data)                             (0x007FFFF0&((data)<<4))
#define  PLL_REG_PLL_SSC_DDSB_pllddsb_en_ssc(data)                               (0x00000001&(data))
#define  PLL_REG_PLL_SSC_DDSB_get_pllddsb_gran_auto_rst(data)                    ((0x10000000&(data))>>28)
#define  PLL_REG_PLL_SSC_DDSB_get_pllddsb_dot_gran(data)                         ((0x07000000&(data))>>24)
#define  PLL_REG_PLL_SSC_DDSB_get_pllddsb_gran_est(data)                         ((0x007FFFF0&(data))>>4)
#define  PLL_REG_PLL_SSC_DDSB_get_pllddsb_en_ssc(data)                           (0x00000001&(data))

#define  PLL_REG_PLL_SSC_DDSB_2                                                  0x180003EC
#define  PLL_REG_PLL_SSC_DDSB_2_reg_addr                                         "0xB80003EC"
#define  PLL_REG_PLL_SSC_DDSB_2_reg                                              0xB80003EC
#define  PLL_REG_PLL_SSC_DDSB_2_inst_addr                                        "0x001D"
#define  set_PLL_REG_PLL_SSC_DDSB_2_reg(data)                                    (*((volatile unsigned int*)PLL_REG_PLL_SSC_DDSB_2_reg)=data)
#define  get_PLL_REG_PLL_SSC_DDSB_2_reg                                          (*((volatile unsigned int*)PLL_REG_PLL_SSC_DDSB_2_reg))
#define  PLL_REG_PLL_SSC_DDSB_2_pllddsb_ncode_ssc_shift                          (16)
#define  PLL_REG_PLL_SSC_DDSB_2_pllddsb_fcode_ssc_shift                          (0)
#define  PLL_REG_PLL_SSC_DDSB_2_pllddsb_ncode_ssc_mask                           (0x00FF0000)
#define  PLL_REG_PLL_SSC_DDSB_2_pllddsb_fcode_ssc_mask                           (0x000007FF)
#define  PLL_REG_PLL_SSC_DDSB_2_pllddsb_ncode_ssc(data)                          (0x00FF0000&((data)<<16))
#define  PLL_REG_PLL_SSC_DDSB_2_pllddsb_fcode_ssc(data)                          (0x000007FF&(data))
#define  PLL_REG_PLL_SSC_DDSB_2_get_pllddsb_ncode_ssc(data)                      ((0x00FF0000&(data))>>16)
#define  PLL_REG_PLL_SSC_DDSB_2_get_pllddsb_fcode_ssc(data)                      (0x000007FF&(data))

#define  PLL_REG_PLL_SSC_INV                                                     0x180003F0
#define  PLL_REG_PLL_SSC_INV_reg_addr                                            "0xB80003F0"
#define  PLL_REG_PLL_SSC_INV_reg                                                 0xB80003F0
#define  PLL_REG_PLL_SSC_INV_inst_addr                                           "0x001E"
#define  set_PLL_REG_PLL_SSC_INV_reg(data)                                       (*((volatile unsigned int*)PLL_REG_PLL_SSC_INV_reg)=data)
#define  get_PLL_REG_PLL_SSC_INV_reg                                             (*((volatile unsigned int*)PLL_REG_PLL_SSC_INV_reg))
#define  PLL_REG_PLL_SSC_INV_psaud2b_ssc_ckinv_shift                             (11)
#define  PLL_REG_PLL_SSC_INV_psaud2a_ssc_ckinv_shift                             (10)
#define  PLL_REG_PLL_SSC_INV_psaud1b_ssc_ckinv_shift                             (9)
#define  PLL_REG_PLL_SSC_INV_psaud1a_ssc_ckinv_shift                             (8)
#define  PLL_REG_PLL_SSC_INV_dds_ssc_ckinv_shift                                 (4)
#define  PLL_REG_PLL_SSC_INV_gpu_ssc_ckinv_shift                                 (3)
#define  PLL_REG_PLL_SSC_INV_bush_ssc_ckinv_shift                                (1)
#define  PLL_REG_PLL_SSC_INV_bus_ssc_ckinv_shift                                 (0)
#define  PLL_REG_PLL_SSC_INV_psaud2b_ssc_ckinv_mask                              (0x00000800)
#define  PLL_REG_PLL_SSC_INV_psaud2a_ssc_ckinv_mask                              (0x00000400)
#define  PLL_REG_PLL_SSC_INV_psaud1b_ssc_ckinv_mask                              (0x00000200)
#define  PLL_REG_PLL_SSC_INV_psaud1a_ssc_ckinv_mask                              (0x00000100)
#define  PLL_REG_PLL_SSC_INV_dds_ssc_ckinv_mask                                  (0x00000010)
#define  PLL_REG_PLL_SSC_INV_gpu_ssc_ckinv_mask                                  (0x00000008)
#define  PLL_REG_PLL_SSC_INV_bush_ssc_ckinv_mask                                 (0x00000002)
#define  PLL_REG_PLL_SSC_INV_bus_ssc_ckinv_mask                                  (0x00000001)
#define  PLL_REG_PLL_SSC_INV_psaud2b_ssc_ckinv(data)                             (0x00000800&((data)<<11))
#define  PLL_REG_PLL_SSC_INV_psaud2a_ssc_ckinv(data)                             (0x00000400&((data)<<10))
#define  PLL_REG_PLL_SSC_INV_psaud1b_ssc_ckinv(data)                             (0x00000200&((data)<<9))
#define  PLL_REG_PLL_SSC_INV_psaud1a_ssc_ckinv(data)                             (0x00000100&((data)<<8))
#define  PLL_REG_PLL_SSC_INV_dds_ssc_ckinv(data)                                 (0x00000010&((data)<<4))
#define  PLL_REG_PLL_SSC_INV_gpu_ssc_ckinv(data)                                 (0x00000008&((data)<<3))
#define  PLL_REG_PLL_SSC_INV_bush_ssc_ckinv(data)                                (0x00000002&((data)<<1))
#define  PLL_REG_PLL_SSC_INV_bus_ssc_ckinv(data)                                 (0x00000001&(data))
#define  PLL_REG_PLL_SSC_INV_get_psaud2b_ssc_ckinv(data)                         ((0x00000800&(data))>>11)
#define  PLL_REG_PLL_SSC_INV_get_psaud2a_ssc_ckinv(data)                         ((0x00000400&(data))>>10)
#define  PLL_REG_PLL_SSC_INV_get_psaud1b_ssc_ckinv(data)                         ((0x00000200&(data))>>9)
#define  PLL_REG_PLL_SSC_INV_get_psaud1a_ssc_ckinv(data)                         ((0x00000100&(data))>>8)
#define  PLL_REG_PLL_SSC_INV_get_dds_ssc_ckinv(data)                             ((0x00000010&(data))>>4)
#define  PLL_REG_PLL_SSC_INV_get_gpu_ssc_ckinv(data)                             ((0x00000008&(data))>>3)
#define  PLL_REG_PLL_SSC_INV_get_bush_ssc_ckinv(data)                            ((0x00000002&(data))>>1)
#define  PLL_REG_PLL_SSC_INV_get_bus_ssc_ckinv(data)                             (0x00000001&(data))

#define  PLL_REG_SYS_PLL_CPU                                                     0x180003F4
#define  PLL_REG_SYS_PLL_CPU_reg_addr                                            "0xB80003F4"
#define  PLL_REG_SYS_PLL_CPU_reg                                                 0xB80003F4
#define  PLL_REG_SYS_PLL_CPU_inst_addr                                           "0x001F"
#define  set_PLL_REG_SYS_PLL_CPU_reg(data)                                       (*((volatile unsigned int*)PLL_REG_SYS_PLL_CPU_reg)=data)
#define  get_PLL_REG_SYS_PLL_CPU_reg                                             (*((volatile unsigned int*)PLL_REG_SYS_PLL_CPU_reg))
#define  PLL_REG_SYS_PLL_CPU_pow_ldo1v_shift                                     (6)
#define  PLL_REG_SYS_PLL_CPU_ldo1v_sel_shift                                     (4)
#define  PLL_REG_SYS_PLL_CPU_pllcpu_reg_shift                                    (0)
#define  PLL_REG_SYS_PLL_CPU_pow_ldo1v_mask                                      (0x00000040)
#define  PLL_REG_SYS_PLL_CPU_ldo1v_sel_mask                                      (0x00000030)
#define  PLL_REG_SYS_PLL_CPU_pllcpu_reg_mask                                     (0x00000003)
#define  PLL_REG_SYS_PLL_CPU_pow_ldo1v(data)                                     (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_CPU_ldo1v_sel(data)                                     (0x00000030&((data)<<4))
#define  PLL_REG_SYS_PLL_CPU_pllcpu_reg(data)                                    (0x00000003&(data))
#define  PLL_REG_SYS_PLL_CPU_get_pow_ldo1v(data)                                 ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_CPU_get_ldo1v_sel(data)                                 ((0x00000030&(data))>>4)
#define  PLL_REG_SYS_PLL_CPU_get_pllcpu_reg(data)                                (0x00000003&(data))

#define  PLL_REG_SYS_PLL_ACPU1                                                   0x18000408
#define  PLL_REG_SYS_PLL_ACPU1_reg_addr                                          "0xB8000408"
#define  PLL_REG_SYS_PLL_ACPU1_reg                                               0xB8000408
#define  PLL_REG_SYS_PLL_ACPU1_inst_addr                                         "0x0020"
#define  set_PLL_REG_SYS_PLL_ACPU1_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_PLL_ACPU1_reg)=data)
#define  get_PLL_REG_SYS_PLL_ACPU1_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_PLL_ACPU1_reg))
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_tst_shift                                 (24)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_n_shift                                   (20)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_m_shift                                   (12)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_ip_shift                                  (9)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_o_shift                                   (7)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_wdset_shift                               (6)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_wdrst_shift                               (5)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_cs_shift                                  (3)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_rs_shift                                  (0)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_tst_mask                                  (0x01000000)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_n_mask                                    (0x00300000)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_m_mask                                    (0x000FF000)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_ip_mask                                   (0x00000E00)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_o_mask                                    (0x00000180)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_wdset_mask                                (0x00000040)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_wdrst_mask                                (0x00000020)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_cs_mask                                   (0x00000018)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_rs_mask                                   (0x00000007)
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_tst(data)                                 (0x01000000&((data)<<24))
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_n(data)                                   (0x00300000&((data)<<20))
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_m(data)                                   (0x000FF000&((data)<<12))
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_ip(data)                                  (0x00000E00&((data)<<9))
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_o(data)                                   (0x00000180&((data)<<7))
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_wdset(data)                               (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_wdrst(data)                               (0x00000020&((data)<<5))
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_cs(data)                                  (0x00000018&((data)<<3))
#define  PLL_REG_SYS_PLL_ACPU1_pllacpu_rs(data)                                  (0x00000007&(data))
#define  PLL_REG_SYS_PLL_ACPU1_get_pllacpu_tst(data)                             ((0x01000000&(data))>>24)
#define  PLL_REG_SYS_PLL_ACPU1_get_pllacpu_n(data)                               ((0x00300000&(data))>>20)
#define  PLL_REG_SYS_PLL_ACPU1_get_pllacpu_m(data)                               ((0x000FF000&(data))>>12)
#define  PLL_REG_SYS_PLL_ACPU1_get_pllacpu_ip(data)                              ((0x00000E00&(data))>>9)
#define  PLL_REG_SYS_PLL_ACPU1_get_pllacpu_o(data)                               ((0x00000180&(data))>>7)
#define  PLL_REG_SYS_PLL_ACPU1_get_pllacpu_wdset(data)                           ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_ACPU1_get_pllacpu_wdrst(data)                           ((0x00000020&(data))>>5)
#define  PLL_REG_SYS_PLL_ACPU1_get_pllacpu_cs(data)                              ((0x00000018&(data))>>3)
#define  PLL_REG_SYS_PLL_ACPU1_get_pllacpu_rs(data)                              (0x00000007&(data))

#define  PLL_REG_SYS_PLL_ACPU2                                                   0x1800040C
#define  PLL_REG_SYS_PLL_ACPU2_reg_addr                                          "0xB800040C"
#define  PLL_REG_SYS_PLL_ACPU2_reg                                               0xB800040C
#define  PLL_REG_SYS_PLL_ACPU2_inst_addr                                         "0x0021"
#define  set_PLL_REG_SYS_PLL_ACPU2_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_PLL_ACPU2_reg)=data)
#define  get_PLL_REG_SYS_PLL_ACPU2_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_PLL_ACPU2_reg))
#define  PLL_REG_SYS_PLL_ACPU2_pllacpu_oeb_shift                                 (2)
#define  PLL_REG_SYS_PLL_ACPU2_pllacpu_rstb_shift                                (1)
#define  PLL_REG_SYS_PLL_ACPU2_pllacpu_pow_shift                                 (0)
#define  PLL_REG_SYS_PLL_ACPU2_pllacpu_oeb_mask                                  (0x00000004)
#define  PLL_REG_SYS_PLL_ACPU2_pllacpu_rstb_mask                                 (0x00000002)
#define  PLL_REG_SYS_PLL_ACPU2_pllacpu_pow_mask                                  (0x00000001)
#define  PLL_REG_SYS_PLL_ACPU2_pllacpu_oeb(data)                                 (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_ACPU2_pllacpu_rstb(data)                                (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_ACPU2_pllacpu_pow(data)                                 (0x00000001&(data))
#define  PLL_REG_SYS_PLL_ACPU2_get_pllacpu_oeb(data)                             ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_ACPU2_get_pllacpu_rstb(data)                            ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_ACPU2_get_pllacpu_pow(data)                             (0x00000001&(data))

#define  PLL_REG_SYS_PLL_VCPU_1                                                  0x18000410
#define  PLL_REG_SYS_PLL_VCPU_1_reg_addr                                         "0xB8000410"
#define  PLL_REG_SYS_PLL_VCPU_1_reg                                              0xB8000410
#define  PLL_REG_SYS_PLL_VCPU_1_inst_addr                                        "0x0022"
#define  set_PLL_REG_SYS_PLL_VCPU_1_reg(data)                                    (*((volatile unsigned int*)PLL_REG_SYS_PLL_VCPU_1_reg)=data)
#define  get_PLL_REG_SYS_PLL_VCPU_1_reg                                          (*((volatile unsigned int*)PLL_REG_SYS_PLL_VCPU_1_reg))
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_tst_shift                                (24)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_n_shift                                  (20)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_m_shift                                  (12)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_ip_shift                                 (9)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_o_shift                                  (7)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_wdset_shift                              (6)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_wdrst_shift                              (5)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_cs_shift                                 (3)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_rs_shift                                 (0)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_tst_mask                                 (0x01000000)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_n_mask                                   (0x00300000)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_m_mask                                   (0x000FF000)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_ip_mask                                  (0x00000E00)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_o_mask                                   (0x00000180)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_wdset_mask                               (0x00000040)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_wdrst_mask                               (0x00000020)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_cs_mask                                  (0x00000018)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_rs_mask                                  (0x00000007)
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_tst(data)                                (0x01000000&((data)<<24))
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_n(data)                                  (0x00300000&((data)<<20))
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_m(data)                                  (0x000FF000&((data)<<12))
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_ip(data)                                 (0x00000E00&((data)<<9))
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_o(data)                                  (0x00000180&((data)<<7))
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_wdset(data)                              (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_wdrst(data)                              (0x00000020&((data)<<5))
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_cs(data)                                 (0x00000018&((data)<<3))
#define  PLL_REG_SYS_PLL_VCPU_1_pllvcpu_rs(data)                                 (0x00000007&(data))
#define  PLL_REG_SYS_PLL_VCPU_1_get_pllvcpu_tst(data)                            ((0x01000000&(data))>>24)
#define  PLL_REG_SYS_PLL_VCPU_1_get_pllvcpu_n(data)                              ((0x00300000&(data))>>20)
#define  PLL_REG_SYS_PLL_VCPU_1_get_pllvcpu_m(data)                              ((0x000FF000&(data))>>12)
#define  PLL_REG_SYS_PLL_VCPU_1_get_pllvcpu_ip(data)                             ((0x00000E00&(data))>>9)
#define  PLL_REG_SYS_PLL_VCPU_1_get_pllvcpu_o(data)                              ((0x00000180&(data))>>7)
#define  PLL_REG_SYS_PLL_VCPU_1_get_pllvcpu_wdset(data)                          ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_VCPU_1_get_pllvcpu_wdrst(data)                          ((0x00000020&(data))>>5)
#define  PLL_REG_SYS_PLL_VCPU_1_get_pllvcpu_cs(data)                             ((0x00000018&(data))>>3)
#define  PLL_REG_SYS_PLL_VCPU_1_get_pllvcpu_rs(data)                             (0x00000007&(data))

#define  PLL_REG_SYS_PLL_VCPU_2                                                  0x18000414
#define  PLL_REG_SYS_PLL_VCPU_2_reg_addr                                         "0xB8000414"
#define  PLL_REG_SYS_PLL_VCPU_2_reg                                              0xB8000414
#define  PLL_REG_SYS_PLL_VCPU_2_inst_addr                                        "0x0023"
#define  set_PLL_REG_SYS_PLL_VCPU_2_reg(data)                                    (*((volatile unsigned int*)PLL_REG_SYS_PLL_VCPU_2_reg)=data)
#define  get_PLL_REG_SYS_PLL_VCPU_2_reg                                          (*((volatile unsigned int*)PLL_REG_SYS_PLL_VCPU_2_reg))
#define  PLL_REG_SYS_PLL_VCPU_2_pllvcpu_oeb_shift                                (2)
#define  PLL_REG_SYS_PLL_VCPU_2_pllvcpu_rstb_shift                               (1)
#define  PLL_REG_SYS_PLL_VCPU_2_pllvcpu_pow_shift                                (0)
#define  PLL_REG_SYS_PLL_VCPU_2_pllvcpu_oeb_mask                                 (0x00000004)
#define  PLL_REG_SYS_PLL_VCPU_2_pllvcpu_rstb_mask                                (0x00000002)
#define  PLL_REG_SYS_PLL_VCPU_2_pllvcpu_pow_mask                                 (0x00000001)
#define  PLL_REG_SYS_PLL_VCPU_2_pllvcpu_oeb(data)                                (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_VCPU_2_pllvcpu_rstb(data)                               (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_VCPU_2_pllvcpu_pow(data)                                (0x00000001&(data))
#define  PLL_REG_SYS_PLL_VCPU_2_get_pllvcpu_oeb(data)                            ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_VCPU_2_get_pllvcpu_rstb(data)                           ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_VCPU_2_get_pllvcpu_pow(data)                            (0x00000001&(data))

#define  PLL_REG_SYS_PLL_VCPU2_1                                                 0x18000418
#define  PLL_REG_SYS_PLL_VCPU2_1_reg_addr                                        "0xB8000418"
#define  PLL_REG_SYS_PLL_VCPU2_1_reg                                             0xB8000418
#define  PLL_REG_SYS_PLL_VCPU2_1_inst_addr                                       "0x0024"
#define  set_PLL_REG_SYS_PLL_VCPU2_1_reg(data)                                   (*((volatile unsigned int*)PLL_REG_SYS_PLL_VCPU2_1_reg)=data)
#define  get_PLL_REG_SYS_PLL_VCPU2_1_reg                                         (*((volatile unsigned int*)PLL_REG_SYS_PLL_VCPU2_1_reg))
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_tst_2_shift                             (24)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_n_2_shift                               (20)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_m_2_shift                               (12)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_ip_2_shift                              (9)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_o_2_shift                               (7)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_wdset_2_shift                           (6)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_wdrst_2_shift                           (5)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_cs_2_shift                              (3)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_rs_2_shift                              (0)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_tst_2_mask                              (0x01000000)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_n_2_mask                                (0x00300000)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_m_2_mask                                (0x000FF000)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_ip_2_mask                               (0x00000E00)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_o_2_mask                                (0x00000180)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_wdset_2_mask                            (0x00000040)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_wdrst_2_mask                            (0x00000020)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_cs_2_mask                               (0x00000018)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_rs_2_mask                               (0x00000007)
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_tst_2(data)                             (0x01000000&((data)<<24))
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_n_2(data)                               (0x00300000&((data)<<20))
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_m_2(data)                               (0x000FF000&((data)<<12))
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_ip_2(data)                              (0x00000E00&((data)<<9))
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_o_2(data)                               (0x00000180&((data)<<7))
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_wdset_2(data)                           (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_wdrst_2(data)                           (0x00000020&((data)<<5))
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_cs_2(data)                              (0x00000018&((data)<<3))
#define  PLL_REG_SYS_PLL_VCPU2_1_pllvcpu_rs_2(data)                              (0x00000007&(data))
#define  PLL_REG_SYS_PLL_VCPU2_1_get_pllvcpu_tst_2(data)                         ((0x01000000&(data))>>24)
#define  PLL_REG_SYS_PLL_VCPU2_1_get_pllvcpu_n_2(data)                           ((0x00300000&(data))>>20)
#define  PLL_REG_SYS_PLL_VCPU2_1_get_pllvcpu_m_2(data)                           ((0x000FF000&(data))>>12)
#define  PLL_REG_SYS_PLL_VCPU2_1_get_pllvcpu_ip_2(data)                          ((0x00000E00&(data))>>9)
#define  PLL_REG_SYS_PLL_VCPU2_1_get_pllvcpu_o_2(data)                           ((0x00000180&(data))>>7)
#define  PLL_REG_SYS_PLL_VCPU2_1_get_pllvcpu_wdset_2(data)                       ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_VCPU2_1_get_pllvcpu_wdrst_2(data)                       ((0x00000020&(data))>>5)
#define  PLL_REG_SYS_PLL_VCPU2_1_get_pllvcpu_cs_2(data)                          ((0x00000018&(data))>>3)
#define  PLL_REG_SYS_PLL_VCPU2_1_get_pllvcpu_rs_2(data)                          (0x00000007&(data))

#define  PLL_REG_SYS_PLL_VCPU2_2                                                 0x1800041C
#define  PLL_REG_SYS_PLL_VCPU2_2_reg_addr                                        "0xB800041C"
#define  PLL_REG_SYS_PLL_VCPU2_2_reg                                             0xB800041C
#define  PLL_REG_SYS_PLL_VCPU2_2_inst_addr                                       "0x0025"
#define  set_PLL_REG_SYS_PLL_VCPU2_2_reg(data)                                   (*((volatile unsigned int*)PLL_REG_SYS_PLL_VCPU2_2_reg)=data)
#define  get_PLL_REG_SYS_PLL_VCPU2_2_reg                                         (*((volatile unsigned int*)PLL_REG_SYS_PLL_VCPU2_2_reg))
#define  PLL_REG_SYS_PLL_VCPU2_2_pllvcpu_oeb_2_shift                             (2)
#define  PLL_REG_SYS_PLL_VCPU2_2_pllvcpu_rstb_2_shift                            (1)
#define  PLL_REG_SYS_PLL_VCPU2_2_pllvcpu_pow_2_shift                             (0)
#define  PLL_REG_SYS_PLL_VCPU2_2_pllvcpu_oeb_2_mask                              (0x00000004)
#define  PLL_REG_SYS_PLL_VCPU2_2_pllvcpu_rstb_2_mask                             (0x00000002)
#define  PLL_REG_SYS_PLL_VCPU2_2_pllvcpu_pow_2_mask                              (0x00000001)
#define  PLL_REG_SYS_PLL_VCPU2_2_pllvcpu_oeb_2(data)                             (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_VCPU2_2_pllvcpu_rstb_2(data)                            (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_VCPU2_2_pllvcpu_pow_2(data)                             (0x00000001&(data))
#define  PLL_REG_SYS_PLL_VCPU2_2_get_pllvcpu_oeb_2(data)                         ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_VCPU2_2_get_pllvcpu_rstb_2(data)                        ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_VCPU2_2_get_pllvcpu_pow_2(data)                         (0x00000001&(data))

#define  PLL_REG_SYS_PLL_BUS1                                                    0x18000420
#define  PLL_REG_SYS_PLL_BUS1_reg_addr                                           "0xB8000420"
#define  PLL_REG_SYS_PLL_BUS1_reg                                                0xB8000420
#define  PLL_REG_SYS_PLL_BUS1_inst_addr                                          "0x0026"
#define  set_PLL_REG_SYS_PLL_BUS1_reg(data)                                      (*((volatile unsigned int*)PLL_REG_SYS_PLL_BUS1_reg)=data)
#define  get_PLL_REG_SYS_PLL_BUS1_reg                                            (*((volatile unsigned int*)PLL_REG_SYS_PLL_BUS1_reg))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_wdset_shift                                 (21)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_wdrst_shift                                 (20)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_lpf_cs_shift                                (16)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_testsel_shift                               (13)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_sel_cco_shift                               (12)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_icp_shift                                   (8)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_dbug_en_shift                               (7)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_pdiv_bps_shift                              (6)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_pdiv_shift                                  (4)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_lpf_rs_shift                                (0)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_wdset_mask                                  (0x00200000)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_wdrst_mask                                  (0x00100000)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_lpf_cs_mask                                 (0x00030000)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_testsel_mask                                (0x00002000)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_sel_cco_mask                                (0x00001000)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_icp_mask                                    (0x00000F00)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_dbug_en_mask                                (0x00000080)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_pdiv_bps_mask                               (0x00000040)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_pdiv_mask                                   (0x00000030)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_lpf_rs_mask                                 (0x00000007)
#define  PLL_REG_SYS_PLL_BUS1_pllbus_wdset(data)                                 (0x00200000&((data)<<21))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_wdrst(data)                                 (0x00100000&((data)<<20))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_lpf_cs(data)                                (0x00030000&((data)<<16))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_testsel(data)                               (0x00002000&((data)<<13))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_sel_cco(data)                               (0x00001000&((data)<<12))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_icp(data)                                   (0x00000F00&((data)<<8))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_dbug_en(data)                               (0x00000080&((data)<<7))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_pdiv_bps(data)                              (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_pdiv(data)                                  (0x00000030&((data)<<4))
#define  PLL_REG_SYS_PLL_BUS1_pllbus_lpf_rs(data)                                (0x00000007&(data))
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_wdset(data)                             ((0x00200000&(data))>>21)
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_wdrst(data)                             ((0x00100000&(data))>>20)
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_lpf_cs(data)                            ((0x00030000&(data))>>16)
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_testsel(data)                           ((0x00002000&(data))>>13)
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_sel_cco(data)                           ((0x00001000&(data))>>12)
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_icp(data)                               ((0x00000F00&(data))>>8)
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_dbug_en(data)                           ((0x00000080&(data))>>7)
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_pdiv_bps(data)                          ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_pdiv(data)                              ((0x00000030&(data))>>4)
#define  PLL_REG_SYS_PLL_BUS1_get_pllbus_lpf_rs(data)                            (0x00000007&(data))

#define  PLL_REG_SYS_PLL_BUS2                                                    0x18000424
#define  PLL_REG_SYS_PLL_BUS2_reg_addr                                           "0xB8000424"
#define  PLL_REG_SYS_PLL_BUS2_reg                                                0xB8000424
#define  PLL_REG_SYS_PLL_BUS2_inst_addr                                          "0x0027"
#define  set_PLL_REG_SYS_PLL_BUS2_reg(data)                                      (*((volatile unsigned int*)PLL_REG_SYS_PLL_BUS2_reg)=data)
#define  get_PLL_REG_SYS_PLL_BUS2_reg                                            (*((volatile unsigned int*)PLL_REG_SYS_PLL_BUS2_reg))
#define  PLL_REG_SYS_PLL_BUS2_pllbus_fcode_shift                                 (16)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_ncode_shift                                 (8)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_oeb_shift                                   (2)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_rstb_shift                                  (1)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_pow_shift                                   (0)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_fcode_mask                                  (0x07FF0000)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_ncode_mask                                  (0x0000FF00)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_oeb_mask                                    (0x00000004)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_rstb_mask                                   (0x00000002)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_pow_mask                                    (0x00000001)
#define  PLL_REG_SYS_PLL_BUS2_pllbus_fcode(data)                                 (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_PLL_BUS2_pllbus_ncode(data)                                 (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_PLL_BUS2_pllbus_oeb(data)                                   (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_BUS2_pllbus_rstb(data)                                  (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_BUS2_pllbus_pow(data)                                   (0x00000001&(data))
#define  PLL_REG_SYS_PLL_BUS2_get_pllbus_fcode(data)                             ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_PLL_BUS2_get_pllbus_ncode(data)                             ((0x0000FF00&(data))>>8)
#define  PLL_REG_SYS_PLL_BUS2_get_pllbus_oeb(data)                               ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_BUS2_get_pllbus_rstb(data)                              ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_BUS2_get_pllbus_pow(data)                               (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_BUS                                                    0x18000428
#define  PLL_REG_SYS_DVFS_BUS_reg_addr                                           "0xB8000428"
#define  PLL_REG_SYS_DVFS_BUS_reg                                                0xB8000428
#define  PLL_REG_SYS_DVFS_BUS_inst_addr                                          "0x0028"
#define  set_PLL_REG_SYS_DVFS_BUS_reg(data)                                      (*((volatile unsigned int*)PLL_REG_SYS_DVFS_BUS_reg)=data)
#define  get_PLL_REG_SYS_DVFS_BUS_reg                                            (*((volatile unsigned int*)PLL_REG_SYS_DVFS_BUS_reg))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_bypass_pi_shift                             (31)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_en_pi_debug_shift                           (30)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_hs_oc_stop_shift                            (28)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_pi_cur_sel_shift                            (26)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_sel_oc_mode_shift                           (24)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_done_delay_shift                         (16)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_step_shift                               (4)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_sdm_order_shift                             (2)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_done_shift                               (1)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_en_shift                                 (0)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_bypass_pi_mask                              (0x80000000)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_en_pi_debug_mask                            (0x40000000)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_hs_oc_stop_mask                             (0x30000000)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_pi_cur_sel_mask                             (0x0C000000)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_sel_oc_mode_mask                            (0x03000000)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_done_delay_mask                          (0x003F0000)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_step_mask                                (0x00003FF0)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_sdm_order_mask                              (0x00000004)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_done_mask                                (0x00000002)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_en_mask                                  (0x00000001)
#define  PLL_REG_SYS_DVFS_BUS_pllbus_bypass_pi(data)                             (0x80000000&((data)<<31))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_en_pi_debug(data)                           (0x40000000&((data)<<30))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_hs_oc_stop(data)                            (0x30000000&((data)<<28))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_pi_cur_sel(data)                            (0x0C000000&((data)<<26))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_sel_oc_mode(data)                           (0x03000000&((data)<<24))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_done_delay(data)                         (0x003F0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_step(data)                               (0x00003FF0&((data)<<4))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_sdm_order(data)                             (0x00000004&((data)<<2))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_done(data)                               (0x00000002&((data)<<1))
#define  PLL_REG_SYS_DVFS_BUS_pllbus_oc_en(data)                                 (0x00000001&(data))
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_bypass_pi(data)                         ((0x80000000&(data))>>31)
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_en_pi_debug(data)                       ((0x40000000&(data))>>30)
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_hs_oc_stop(data)                        ((0x30000000&(data))>>28)
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_pi_cur_sel(data)                        ((0x0C000000&(data))>>26)
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_sel_oc_mode(data)                       ((0x03000000&(data))>>24)
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_oc_done_delay(data)                     ((0x003F0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_oc_step(data)                           ((0x00003FF0&(data))>>4)
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_sdm_order(data)                         ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_oc_done(data)                           ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_DVFS_BUS_get_pllbus_oc_en(data)                             (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_BUS2                                                   0x1800042C
#define  PLL_REG_SYS_DVFS_BUS2_reg_addr                                          "0xB800042C"
#define  PLL_REG_SYS_DVFS_BUS2_reg                                               0xB800042C
#define  PLL_REG_SYS_DVFS_BUS2_inst_addr                                         "0x0029"
#define  set_PLL_REG_SYS_DVFS_BUS2_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_DVFS_BUS2_reg)=data)
#define  get_PLL_REG_SYS_DVFS_BUS2_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_DVFS_BUS2_reg))
#define  PLL_REG_SYS_DVFS_BUS2_pllbus_fcode_dbg_shift                            (16)
#define  PLL_REG_SYS_DVFS_BUS2_pllbus_ncode_dbg_shift                            (8)
#define  PLL_REG_SYS_DVFS_BUS2_pllbus_fcode_dbg_mask                             (0x07FF0000)
#define  PLL_REG_SYS_DVFS_BUS2_pllbus_ncode_dbg_mask                             (0x0000FF00)
#define  PLL_REG_SYS_DVFS_BUS2_pllbus_fcode_dbg(data)                            (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_BUS2_pllbus_ncode_dbg(data)                            (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_DVFS_BUS2_get_pllbus_fcode_dbg(data)                        ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_BUS2_get_pllbus_ncode_dbg(data)                        ((0x0000FF00&(data))>>8)

#define  PLL_REG_SYS_PLL_BUSH1                                                   0x18000430
#define  PLL_REG_SYS_PLL_BUSH1_reg_addr                                          "0xB8000430"
#define  PLL_REG_SYS_PLL_BUSH1_reg                                               0xB8000430
#define  PLL_REG_SYS_PLL_BUSH1_inst_addr                                         "0x002A"
#define  set_PLL_REG_SYS_PLL_BUSH1_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_PLL_BUSH1_reg)=data)
#define  get_PLL_REG_SYS_PLL_BUSH1_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_PLL_BUSH1_reg))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_wdset_h_shift                              (21)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_wdrst_h_shift                              (20)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_lpf_cs_h_shift                             (16)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_testsel_h_shift                            (13)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_sel_cco_h_shift                            (12)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_icp_h_shift                                (8)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_dbug_en_h_shift                            (7)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_pdiv_bps_h_shift                           (6)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_pdiv_h_shift                               (4)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_lpf_rs_h_shift                             (0)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_wdset_h_mask                               (0x00200000)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_wdrst_h_mask                               (0x00100000)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_lpf_cs_h_mask                              (0x00030000)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_testsel_h_mask                             (0x00002000)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_sel_cco_h_mask                             (0x00001000)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_icp_h_mask                                 (0x00000F00)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_dbug_en_h_mask                             (0x00000080)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_pdiv_bps_h_mask                            (0x00000040)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_pdiv_h_mask                                (0x00000030)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_lpf_rs_h_mask                              (0x00000007)
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_wdset_h(data)                              (0x00200000&((data)<<21))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_wdrst_h(data)                              (0x00100000&((data)<<20))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_lpf_cs_h(data)                             (0x00030000&((data)<<16))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_testsel_h(data)                            (0x00002000&((data)<<13))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_sel_cco_h(data)                            (0x00001000&((data)<<12))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_icp_h(data)                                (0x00000F00&((data)<<8))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_dbug_en_h(data)                            (0x00000080&((data)<<7))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_pdiv_bps_h(data)                           (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_pdiv_h(data)                               (0x00000030&((data)<<4))
#define  PLL_REG_SYS_PLL_BUSH1_pllbus_lpf_rs_h(data)                             (0x00000007&(data))
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_wdset_h(data)                          ((0x00200000&(data))>>21)
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_wdrst_h(data)                          ((0x00100000&(data))>>20)
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_lpf_cs_h(data)                         ((0x00030000&(data))>>16)
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_testsel_h(data)                        ((0x00002000&(data))>>13)
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_sel_cco_h(data)                        ((0x00001000&(data))>>12)
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_icp_h(data)                            ((0x00000F00&(data))>>8)
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_dbug_en_h(data)                        ((0x00000080&(data))>>7)
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_pdiv_bps_h(data)                       ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_pdiv_h(data)                           ((0x00000030&(data))>>4)
#define  PLL_REG_SYS_PLL_BUSH1_get_pllbus_lpf_rs_h(data)                         (0x00000007&(data))

#define  PLL_REG_SYS_PLL_BUSH2                                                   0x18000434
#define  PLL_REG_SYS_PLL_BUSH2_reg_addr                                          "0xB8000434"
#define  PLL_REG_SYS_PLL_BUSH2_reg                                               0xB8000434
#define  PLL_REG_SYS_PLL_BUSH2_inst_addr                                         "0x002B"
#define  set_PLL_REG_SYS_PLL_BUSH2_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_PLL_BUSH2_reg)=data)
#define  get_PLL_REG_SYS_PLL_BUSH2_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_PLL_BUSH2_reg))
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_fcode_h_shift                              (16)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_ncode_h_shift                              (8)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_oeb_h_shift                                (2)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_rstb_h_shift                               (1)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_pow_h_shift                                (0)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_fcode_h_mask                               (0x07FF0000)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_ncode_h_mask                               (0x0000FF00)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_oeb_h_mask                                 (0x00000004)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_rstb_h_mask                                (0x00000002)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_pow_h_mask                                 (0x00000001)
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_fcode_h(data)                              (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_ncode_h(data)                              (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_oeb_h(data)                                (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_rstb_h(data)                               (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_BUSH2_pllbus_pow_h(data)                                (0x00000001&(data))
#define  PLL_REG_SYS_PLL_BUSH2_get_pllbus_fcode_h(data)                          ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_PLL_BUSH2_get_pllbus_ncode_h(data)                          ((0x0000FF00&(data))>>8)
#define  PLL_REG_SYS_PLL_BUSH2_get_pllbus_oeb_h(data)                            ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_BUSH2_get_pllbus_rstb_h(data)                           ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_BUSH2_get_pllbus_pow_h(data)                            (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_BUSH                                                   0x18000438
#define  PLL_REG_SYS_DVFS_BUSH_reg_addr                                          "0xB8000438"
#define  PLL_REG_SYS_DVFS_BUSH_reg                                               0xB8000438
#define  PLL_REG_SYS_DVFS_BUSH_inst_addr                                         "0x002C"
#define  set_PLL_REG_SYS_DVFS_BUSH_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_DVFS_BUSH_reg)=data)
#define  get_PLL_REG_SYS_DVFS_BUSH_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_DVFS_BUSH_reg))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_bypass_pi_h_shift                          (31)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_en_pi_debug_h_shift                        (30)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_hs_oc_stop_h_shift                         (28)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_pi_cur_sel_h_shift                         (26)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_sel_oc_mode_h_shift                        (24)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_done_delay_h_shift                      (16)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_step_h_shift                            (4)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_sdm_order_h_shift                          (2)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_done_h_shift                            (1)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_en_h_shift                              (0)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_bypass_pi_h_mask                           (0x80000000)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_en_pi_debug_h_mask                         (0x40000000)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_hs_oc_stop_h_mask                          (0x30000000)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_pi_cur_sel_h_mask                          (0x0C000000)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_sel_oc_mode_h_mask                         (0x03000000)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_done_delay_h_mask                       (0x003F0000)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_step_h_mask                             (0x00003FF0)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_sdm_order_h_mask                           (0x00000004)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_done_h_mask                             (0x00000002)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_en_h_mask                               (0x00000001)
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_bypass_pi_h(data)                          (0x80000000&((data)<<31))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_en_pi_debug_h(data)                        (0x40000000&((data)<<30))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_hs_oc_stop_h(data)                         (0x30000000&((data)<<28))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_pi_cur_sel_h(data)                         (0x0C000000&((data)<<26))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_sel_oc_mode_h(data)                        (0x03000000&((data)<<24))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_done_delay_h(data)                      (0x003F0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_step_h(data)                            (0x00003FF0&((data)<<4))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_sdm_order_h(data)                          (0x00000004&((data)<<2))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_done_h(data)                            (0x00000002&((data)<<1))
#define  PLL_REG_SYS_DVFS_BUSH_pllbus_oc_en_h(data)                              (0x00000001&(data))
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_bypass_pi_h(data)                      ((0x80000000&(data))>>31)
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_en_pi_debug_h(data)                    ((0x40000000&(data))>>30)
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_hs_oc_stop_h(data)                     ((0x30000000&(data))>>28)
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_pi_cur_sel_h(data)                     ((0x0C000000&(data))>>26)
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_sel_oc_mode_h(data)                    ((0x03000000&(data))>>24)
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_oc_done_delay_h(data)                  ((0x003F0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_oc_step_h(data)                        ((0x00003FF0&(data))>>4)
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_sdm_order_h(data)                      ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_oc_done_h(data)                        ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_DVFS_BUSH_get_pllbus_oc_en_h(data)                          (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_BUSH2                                                  0x1800043C
#define  PLL_REG_SYS_DVFS_BUSH2_reg_addr                                         "0xB800043C"
#define  PLL_REG_SYS_DVFS_BUSH2_reg                                              0xB800043C
#define  PLL_REG_SYS_DVFS_BUSH2_inst_addr                                        "0x002D"
#define  set_PLL_REG_SYS_DVFS_BUSH2_reg(data)                                    (*((volatile unsigned int*)PLL_REG_SYS_DVFS_BUSH2_reg)=data)
#define  get_PLL_REG_SYS_DVFS_BUSH2_reg                                          (*((volatile unsigned int*)PLL_REG_SYS_DVFS_BUSH2_reg))
#define  PLL_REG_SYS_DVFS_BUSH2_pllbus_fcode_dbg_h_shift                         (16)
#define  PLL_REG_SYS_DVFS_BUSH2_pllbus_ncode_dbg_h_shift                         (8)
#define  PLL_REG_SYS_DVFS_BUSH2_pllbus_fcode_dbg_h_mask                          (0x07FF0000)
#define  PLL_REG_SYS_DVFS_BUSH2_pllbus_ncode_dbg_h_mask                          (0x0000FF00)
#define  PLL_REG_SYS_DVFS_BUSH2_pllbus_fcode_dbg_h(data)                         (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_BUSH2_pllbus_ncode_dbg_h(data)                         (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_DVFS_BUSH2_get_pllbus_fcode_dbg_h(data)                     ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_BUSH2_get_pllbus_ncode_dbg_h(data)                     ((0x0000FF00&(data))>>8)

#define  PLL_REG_SYS_PLL_GPU1                                                    0x18000450
#define  PLL_REG_SYS_PLL_GPU1_reg_addr                                           "0xB8000450"
#define  PLL_REG_SYS_PLL_GPU1_reg                                                0xB8000450
#define  PLL_REG_SYS_PLL_GPU1_inst_addr                                          "0x002E"
#define  set_PLL_REG_SYS_PLL_GPU1_reg(data)                                      (*((volatile unsigned int*)PLL_REG_SYS_PLL_GPU1_reg)=data)
#define  get_PLL_REG_SYS_PLL_GPU1_reg                                            (*((volatile unsigned int*)PLL_REG_SYS_PLL_GPU1_reg))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_wdset_shift                                 (21)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_wdrst_shift                                 (20)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_lpf_cs_shift                                (16)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_testsel_shift                               (13)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_sel_cco_shift                               (12)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_icp_shift                                   (8)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_dbug_en_shift                               (7)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_pdiv_bps_shift                              (6)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_pdiv_shift                                  (4)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_lpf_rs_shift                                (0)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_wdset_mask                                  (0x00200000)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_wdrst_mask                                  (0x00100000)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_lpf_cs_mask                                 (0x00030000)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_testsel_mask                                (0x00002000)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_sel_cco_mask                                (0x00001000)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_icp_mask                                    (0x00000F00)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_dbug_en_mask                                (0x00000080)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_pdiv_bps_mask                               (0x00000040)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_pdiv_mask                                   (0x00000030)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_lpf_rs_mask                                 (0x00000007)
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_wdset(data)                                 (0x00200000&((data)<<21))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_wdrst(data)                                 (0x00100000&((data)<<20))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_lpf_cs(data)                                (0x00030000&((data)<<16))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_testsel(data)                               (0x00002000&((data)<<13))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_sel_cco(data)                               (0x00001000&((data)<<12))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_icp(data)                                   (0x00000F00&((data)<<8))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_dbug_en(data)                               (0x00000080&((data)<<7))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_pdiv_bps(data)                              (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_pdiv(data)                                  (0x00000030&((data)<<4))
#define  PLL_REG_SYS_PLL_GPU1_pllgpu_lpf_rs(data)                                (0x00000007&(data))
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_wdset(data)                             ((0x00200000&(data))>>21)
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_wdrst(data)                             ((0x00100000&(data))>>20)
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_lpf_cs(data)                            ((0x00030000&(data))>>16)
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_testsel(data)                           ((0x00002000&(data))>>13)
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_sel_cco(data)                           ((0x00001000&(data))>>12)
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_icp(data)                               ((0x00000F00&(data))>>8)
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_dbug_en(data)                           ((0x00000080&(data))>>7)
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_pdiv_bps(data)                          ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_pdiv(data)                              ((0x00000030&(data))>>4)
#define  PLL_REG_SYS_PLL_GPU1_get_pllgpu_lpf_rs(data)                            (0x00000007&(data))

#define  PLL_REG_SYS_PLL_GPU2                                                    0x18000454
#define  PLL_REG_SYS_PLL_GPU2_reg_addr                                           "0xB8000454"
#define  PLL_REG_SYS_PLL_GPU2_reg                                                0xB8000454
#define  PLL_REG_SYS_PLL_GPU2_inst_addr                                          "0x002F"
#define  set_PLL_REG_SYS_PLL_GPU2_reg(data)                                      (*((volatile unsigned int*)PLL_REG_SYS_PLL_GPU2_reg)=data)
#define  get_PLL_REG_SYS_PLL_GPU2_reg                                            (*((volatile unsigned int*)PLL_REG_SYS_PLL_GPU2_reg))
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_fcode_shift                                 (16)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_ncode_shift                                 (8)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_oeb_shift                                   (2)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_rstb_shift                                  (1)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_pow_shift                                   (0)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_fcode_mask                                  (0x07FF0000)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_ncode_mask                                  (0x0000FF00)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_oeb_mask                                    (0x00000004)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_rstb_mask                                   (0x00000002)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_pow_mask                                    (0x00000001)
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_fcode(data)                                 (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_ncode(data)                                 (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_oeb(data)                                   (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_rstb(data)                                  (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_GPU2_pllgpu_pow(data)                                   (0x00000001&(data))
#define  PLL_REG_SYS_PLL_GPU2_get_pllgpu_fcode(data)                             ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_PLL_GPU2_get_pllgpu_ncode(data)                             ((0x0000FF00&(data))>>8)
#define  PLL_REG_SYS_PLL_GPU2_get_pllgpu_oeb(data)                               ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_GPU2_get_pllgpu_rstb(data)                              ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_GPU2_get_pllgpu_pow(data)                               (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_GPU                                                    0x18000448
#define  PLL_REG_SYS_DVFS_GPU_reg_addr                                           "0xB8000448"
#define  PLL_REG_SYS_DVFS_GPU_reg                                                0xB8000448
#define  PLL_REG_SYS_DVFS_GPU_inst_addr                                          "0x0030"
#define  set_PLL_REG_SYS_DVFS_GPU_reg(data)                                      (*((volatile unsigned int*)PLL_REG_SYS_DVFS_GPU_reg)=data)
#define  get_PLL_REG_SYS_DVFS_GPU_reg                                            (*((volatile unsigned int*)PLL_REG_SYS_DVFS_GPU_reg))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_bypass_pi_shift                             (31)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_en_pi_debug_shift                           (30)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_hs_oc_stop_shift                            (28)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_pi_cur_sel_shift                            (26)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_sel_oc_mode_shift                           (24)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_done_delay_shift                         (16)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_step_shift                               (4)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_sdm_order_shift                             (2)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_done_shift                               (1)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_en_shift                                 (0)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_bypass_pi_mask                              (0x80000000)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_en_pi_debug_mask                            (0x40000000)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_hs_oc_stop_mask                             (0x30000000)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_pi_cur_sel_mask                             (0x0C000000)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_sel_oc_mode_mask                            (0x03000000)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_done_delay_mask                          (0x003F0000)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_step_mask                                (0x00003FF0)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_sdm_order_mask                              (0x00000004)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_done_mask                                (0x00000002)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_en_mask                                  (0x00000001)
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_bypass_pi(data)                             (0x80000000&((data)<<31))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_en_pi_debug(data)                           (0x40000000&((data)<<30))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_hs_oc_stop(data)                            (0x30000000&((data)<<28))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_pi_cur_sel(data)                            (0x0C000000&((data)<<26))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_sel_oc_mode(data)                           (0x03000000&((data)<<24))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_done_delay(data)                         (0x003F0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_step(data)                               (0x00003FF0&((data)<<4))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_sdm_order(data)                             (0x00000004&((data)<<2))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_done(data)                               (0x00000002&((data)<<1))
#define  PLL_REG_SYS_DVFS_GPU_pllgpu_oc_en(data)                                 (0x00000001&(data))
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_bypass_pi(data)                         ((0x80000000&(data))>>31)
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_en_pi_debug(data)                       ((0x40000000&(data))>>30)
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_hs_oc_stop(data)                        ((0x30000000&(data))>>28)
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_pi_cur_sel(data)                        ((0x0C000000&(data))>>26)
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_sel_oc_mode(data)                       ((0x03000000&(data))>>24)
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_oc_done_delay(data)                     ((0x003F0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_oc_step(data)                           ((0x00003FF0&(data))>>4)
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_sdm_order(data)                         ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_oc_done(data)                           ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_DVFS_GPU_get_pllgpu_oc_en(data)                             (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_GPU2                                                   0x1800044C
#define  PLL_REG_SYS_DVFS_GPU2_reg_addr                                          "0xB800044C"
#define  PLL_REG_SYS_DVFS_GPU2_reg                                               0xB800044C
#define  PLL_REG_SYS_DVFS_GPU2_inst_addr                                         "0x0031"
#define  set_PLL_REG_SYS_DVFS_GPU2_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_DVFS_GPU2_reg)=data)
#define  get_PLL_REG_SYS_DVFS_GPU2_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_DVFS_GPU2_reg))
#define  PLL_REG_SYS_DVFS_GPU2_pllgpu_fcode_dbg_shift                            (16)
#define  PLL_REG_SYS_DVFS_GPU2_pllgpu_ncode_dbg_shift                            (8)
#define  PLL_REG_SYS_DVFS_GPU2_pllgpu_fcode_dbg_mask                             (0x07FF0000)
#define  PLL_REG_SYS_DVFS_GPU2_pllgpu_ncode_dbg_mask                             (0x0000FF00)
#define  PLL_REG_SYS_DVFS_GPU2_pllgpu_fcode_dbg(data)                            (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_GPU2_pllgpu_ncode_dbg(data)                            (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_DVFS_GPU2_get_pllgpu_fcode_dbg(data)                        ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_GPU2_get_pllgpu_ncode_dbg(data)                        ((0x0000FF00&(data))>>8)

#define  PLL_REG_SYS_PLL_VODMA1                                                  0x18000460
#define  PLL_REG_SYS_PLL_VODMA1_reg_addr                                         "0xB8000460"
#define  PLL_REG_SYS_PLL_VODMA1_reg                                              0xB8000460
#define  PLL_REG_SYS_PLL_VODMA1_inst_addr                                        "0x0032"
#define  set_PLL_REG_SYS_PLL_VODMA1_reg(data)                                    (*((volatile unsigned int*)PLL_REG_SYS_PLL_VODMA1_reg)=data)
#define  get_PLL_REG_SYS_PLL_VODMA1_reg                                          (*((volatile unsigned int*)PLL_REG_SYS_PLL_VODMA1_reg))
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_n_shift                                 (20)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_m_shift                                 (12)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_ip_shift                                (9)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_o_shift                                 (7)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_wdset_shift                             (6)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_wdrst_shift                             (5)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_cs_shift                                (3)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_rs_shift                                (0)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_n_mask                                  (0x00300000)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_m_mask                                  (0x000FF000)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_ip_mask                                 (0x00000E00)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_o_mask                                  (0x00000180)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_wdset_mask                              (0x00000040)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_wdrst_mask                              (0x00000020)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_cs_mask                                 (0x00000018)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_rs_mask                                 (0x00000007)
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_n(data)                                 (0x00300000&((data)<<20))
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_m(data)                                 (0x000FF000&((data)<<12))
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_ip(data)                                (0x00000E00&((data)<<9))
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_o(data)                                 (0x00000180&((data)<<7))
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_wdset(data)                             (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_wdrst(data)                             (0x00000020&((data)<<5))
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_cs(data)                                (0x00000018&((data)<<3))
#define  PLL_REG_SYS_PLL_VODMA1_pllvodma_rs(data)                                (0x00000007&(data))
#define  PLL_REG_SYS_PLL_VODMA1_get_pllvodma_n(data)                             ((0x00300000&(data))>>20)
#define  PLL_REG_SYS_PLL_VODMA1_get_pllvodma_m(data)                             ((0x000FF000&(data))>>12)
#define  PLL_REG_SYS_PLL_VODMA1_get_pllvodma_ip(data)                            ((0x00000E00&(data))>>9)
#define  PLL_REG_SYS_PLL_VODMA1_get_pllvodma_o(data)                             ((0x00000180&(data))>>7)
#define  PLL_REG_SYS_PLL_VODMA1_get_pllvodma_wdset(data)                         ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_VODMA1_get_pllvodma_wdrst(data)                         ((0x00000020&(data))>>5)
#define  PLL_REG_SYS_PLL_VODMA1_get_pllvodma_cs(data)                            ((0x00000018&(data))>>3)
#define  PLL_REG_SYS_PLL_VODMA1_get_pllvodma_rs(data)                            (0x00000007&(data))

#define  PLL_REG_SYS_PLL_VODMA2                                                  0x18000464
#define  PLL_REG_SYS_PLL_VODMA2_reg_addr                                         "0xB8000464"
#define  PLL_REG_SYS_PLL_VODMA2_reg                                              0xB8000464
#define  PLL_REG_SYS_PLL_VODMA2_inst_addr                                        "0x0033"
#define  set_PLL_REG_SYS_PLL_VODMA2_reg(data)                                    (*((volatile unsigned int*)PLL_REG_SYS_PLL_VODMA2_reg)=data)
#define  get_PLL_REG_SYS_PLL_VODMA2_reg                                          (*((volatile unsigned int*)PLL_REG_SYS_PLL_VODMA2_reg))
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_tst_shift                               (3)
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_oeb_shift                               (2)
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_rstb_shift                              (1)
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_pow_shift                               (0)
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_tst_mask                                (0x00000008)
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_oeb_mask                                (0x00000004)
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_rstb_mask                               (0x00000002)
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_pow_mask                                (0x00000001)
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_tst(data)                               (0x00000008&((data)<<3))
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_oeb(data)                               (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_rstb(data)                              (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_VODMA2_pllvodma_pow(data)                               (0x00000001&(data))
#define  PLL_REG_SYS_PLL_VODMA2_get_pllvodma_tst(data)                           ((0x00000008&(data))>>3)
#define  PLL_REG_SYS_PLL_VODMA2_get_pllvodma_oeb(data)                           ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_VODMA2_get_pllvodma_rstb(data)                          ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_VODMA2_get_pllvodma_pow(data)                           (0x00000001&(data))

#define  PLL_REG_SYS_PLLBUS_TST                                                  0x18000468
#define  PLL_REG_SYS_PLLBUS_TST_reg_addr                                         "0xB8000468"
#define  PLL_REG_SYS_PLLBUS_TST_reg                                              0xB8000468
#define  PLL_REG_SYS_PLLBUS_TST_inst_addr                                        "0x0034"
#define  set_PLL_REG_SYS_PLLBUS_TST_reg(data)                                    (*((volatile unsigned int*)PLL_REG_SYS_PLLBUS_TST_reg)=data)
#define  get_PLL_REG_SYS_PLLBUS_TST_reg                                          (*((volatile unsigned int*)PLL_REG_SYS_PLLBUS_TST_reg))
#define  PLL_REG_SYS_PLLBUS_TST_pllbus_reser_shift                               (16)
#define  PLL_REG_SYS_PLLBUS_TST_pllbus_reg_shift                                 (12)
#define  PLL_REG_SYS_PLLBUS_TST_pllbustst_div_shift                              (8)
#define  PLL_REG_SYS_PLLBUS_TST_pllbustst_sel_shift                              (0)
#define  PLL_REG_SYS_PLLBUS_TST_pllbus_reser_mask                                (0x00FF0000)
#define  PLL_REG_SYS_PLLBUS_TST_pllbus_reg_mask                                  (0x00003000)
#define  PLL_REG_SYS_PLLBUS_TST_pllbustst_div_mask                               (0x00000300)
#define  PLL_REG_SYS_PLLBUS_TST_pllbustst_sel_mask                               (0x0000001F)
#define  PLL_REG_SYS_PLLBUS_TST_pllbus_reser(data)                               (0x00FF0000&((data)<<16))
#define  PLL_REG_SYS_PLLBUS_TST_pllbus_reg(data)                                 (0x00003000&((data)<<12))
#define  PLL_REG_SYS_PLLBUS_TST_pllbustst_div(data)                              (0x00000300&((data)<<8))
#define  PLL_REG_SYS_PLLBUS_TST_pllbustst_sel(data)                              (0x0000001F&(data))
#define  PLL_REG_SYS_PLLBUS_TST_get_pllbus_reser(data)                           ((0x00FF0000&(data))>>16)
#define  PLL_REG_SYS_PLLBUS_TST_get_pllbus_reg(data)                             ((0x00003000&(data))>>12)
#define  PLL_REG_SYS_PLLBUS_TST_get_pllbustst_div(data)                          ((0x00000300&(data))>>8)
#define  PLL_REG_SYS_PLLBUS_TST_get_pllbustst_sel(data)                          (0x0000001F&(data))

#define  PLL_REG_SYS_PLL_DISPA_SD1                                               0x18000470
#define  PLL_REG_SYS_PLL_DISPA_SD1_reg_addr                                      "0xB8000470"
#define  PLL_REG_SYS_PLL_DISPA_SD1_reg                                           0xB8000470
#define  PLL_REG_SYS_PLL_DISPA_SD1_inst_addr                                     "0x0035"
#define  set_PLL_REG_SYS_PLL_DISPA_SD1_reg(data)                                 (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPA_SD1_reg)=data)
#define  get_PLL_REG_SYS_PLL_DISPA_SD1_reg                                       (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPA_SD1_reg))
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_n_shift                               (30)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_ip_shift                              (20)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_rs_shift                              (17)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_cs_shift                              (15)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_cp_shift                              (13)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_o_shift                               (4)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_wdmode_shift                          (0)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_n_mask                                (0xC0000000)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_ip_mask                               (0x00F00000)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_rs_mask                               (0x000E0000)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_cs_mask                               (0x00018000)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_cp_mask                               (0x00006000)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_o_mask                                (0x00000030)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_wdmode_mask                           (0x00000003)
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_n(data)                               (0xC0000000&((data)<<30))
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_ip(data)                              (0x00F00000&((data)<<20))
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_rs(data)                              (0x000E0000&((data)<<17))
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_cs(data)                              (0x00018000&((data)<<15))
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_cp(data)                              (0x00006000&((data)<<13))
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_o(data)                               (0x00000030&((data)<<4))
#define  PLL_REG_SYS_PLL_DISPA_SD1_pllddsa_wdmode(data)                          (0x00000003&(data))
#define  PLL_REG_SYS_PLL_DISPA_SD1_get_pllddsa_n(data)                           ((0xC0000000&(data))>>30)
#define  PLL_REG_SYS_PLL_DISPA_SD1_get_pllddsa_ip(data)                          ((0x00F00000&(data))>>20)
#define  PLL_REG_SYS_PLL_DISPA_SD1_get_pllddsa_rs(data)                          ((0x000E0000&(data))>>17)
#define  PLL_REG_SYS_PLL_DISPA_SD1_get_pllddsa_cs(data)                          ((0x00018000&(data))>>15)
#define  PLL_REG_SYS_PLL_DISPA_SD1_get_pllddsa_cp(data)                          ((0x00006000&(data))>>13)
#define  PLL_REG_SYS_PLL_DISPA_SD1_get_pllddsa_o(data)                           ((0x00000030&(data))>>4)
#define  PLL_REG_SYS_PLL_DISPA_SD1_get_pllddsa_wdmode(data)                      (0x00000003&(data))

#define  PLL_REG_SYS_PLL_DISPA_SD2                                               0x18000474
#define  PLL_REG_SYS_PLL_DISPA_SD2_reg_addr                                      "0xB8000474"
#define  PLL_REG_SYS_PLL_DISPA_SD2_reg                                           0xB8000474
#define  PLL_REG_SYS_PLL_DISPA_SD2_inst_addr                                     "0x0036"
#define  set_PLL_REG_SYS_PLL_DISPA_SD2_reg(data)                                 (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPA_SD2_reg)=data)
#define  get_PLL_REG_SYS_PLL_DISPA_SD2_reg                                       (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPA_SD2_reg))
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_fcode_shift                           (16)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_ncode_shift                           (8)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_oeb_shift                             (2)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_rstb_shift                            (1)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_pow_shift                             (0)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_fcode_mask                            (0x07FF0000)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_ncode_mask                            (0x0000FF00)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_oeb_mask                              (0x00000004)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_rstb_mask                             (0x00000002)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_pow_mask                              (0x00000001)
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_fcode(data)                           (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_ncode(data)                           (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_oeb(data)                             (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_rstb(data)                            (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_DISPA_SD2_pllddsa_pow(data)                             (0x00000001&(data))
#define  PLL_REG_SYS_PLL_DISPA_SD2_get_pllddsa_fcode(data)                       ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_PLL_DISPA_SD2_get_pllddsa_ncode(data)                       ((0x0000FF00&(data))>>8)
#define  PLL_REG_SYS_PLL_DISPA_SD2_get_pllddsa_oeb(data)                         ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_DISPA_SD2_get_pllddsa_rstb(data)                        ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_DISPA_SD2_get_pllddsa_pow(data)                         (0x00000001&(data))

#define  PLL_REG_SYS_PLL_DISPA_SD3                                               0x18000478
#define  PLL_REG_SYS_PLL_DISPA_SD3_reg_addr                                      "0xB8000478"
#define  PLL_REG_SYS_PLL_DISPA_SD3_reg                                           0xB8000478
#define  PLL_REG_SYS_PLL_DISPA_SD3_inst_addr                                     "0x0037"
#define  set_PLL_REG_SYS_PLL_DISPA_SD3_reg(data)                                 (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPA_SD3_reg)=data)
#define  get_PLL_REG_SYS_PLL_DISPA_SD3_reg                                       (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPA_SD3_reg))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_28_25_shift                             (25)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_24_shift                                (24)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_23_shift                                (23)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_22_shift                                (22)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_21_shift                                (21)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_20_shift                                (20)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_19_shift                                (19)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_18_shift                                (18)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_17_shift                                (17)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_16_shift                                (16)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_15_shift                                (15)
#define  PLL_REG_SYS_PLL_DISPA_SD3_pllddsa_vcorb_shift                           (14)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_13_shift                                (13)
#define  PLL_REG_SYS_PLL_DISPA_SD3_pllddsa_tst_shift                             (12)
#define  PLL_REG_SYS_PLL_DISPA_SD3_pllddsa_pstst_shift                           (11)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_10_shift                                (10)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_28_25_mask                              (0x1E000000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_24_mask                                 (0x01000000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_23_mask                                 (0x00800000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_22_mask                                 (0x00400000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_21_mask                                 (0x00200000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_20_mask                                 (0x00100000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_19_mask                                 (0x00080000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_18_mask                                 (0x00040000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_17_mask                                 (0x00020000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_16_mask                                 (0x00010000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_15_mask                                 (0x00008000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_pllddsa_vcorb_mask                            (0x00004000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_13_mask                                 (0x00002000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_pllddsa_tst_mask                              (0x00001000)
#define  PLL_REG_SYS_PLL_DISPA_SD3_pllddsa_pstst_mask                            (0x00000800)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_10_mask                                 (0x00000400)
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_28_25(data)                             (0x1E000000&((data)<<25))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_24(data)                                (0x01000000&((data)<<24))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_23(data)                                (0x00800000&((data)<<23))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_22(data)                                (0x00400000&((data)<<22))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_21(data)                                (0x00200000&((data)<<21))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_20(data)                                (0x00100000&((data)<<20))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_19(data)                                (0x00080000&((data)<<19))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_18(data)                                (0x00040000&((data)<<18))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_17(data)                                (0x00020000&((data)<<17))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_16(data)                                (0x00010000&((data)<<16))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_15(data)                                (0x00008000&((data)<<15))
#define  PLL_REG_SYS_PLL_DISPA_SD3_pllddsa_vcorb(data)                           (0x00004000&((data)<<14))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_13(data)                                (0x00002000&((data)<<13))
#define  PLL_REG_SYS_PLL_DISPA_SD3_pllddsa_tst(data)                             (0x00001000&((data)<<12))
#define  PLL_REG_SYS_PLL_DISPA_SD3_pllddsa_pstst(data)                           (0x00000800&((data)<<11))
#define  PLL_REG_SYS_PLL_DISPA_SD3_dummy_10(data)                                (0x00000400&((data)<<10))
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_28_25(data)                         ((0x1E000000&(data))>>25)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_24(data)                            ((0x01000000&(data))>>24)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_23(data)                            ((0x00800000&(data))>>23)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_22(data)                            ((0x00400000&(data))>>22)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_21(data)                            ((0x00200000&(data))>>21)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_20(data)                            ((0x00100000&(data))>>20)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_19(data)                            ((0x00080000&(data))>>19)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_18(data)                            ((0x00040000&(data))>>18)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_17(data)                            ((0x00020000&(data))>>17)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_16(data)                            ((0x00010000&(data))>>16)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_15(data)                            ((0x00008000&(data))>>15)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_pllddsa_vcorb(data)                       ((0x00004000&(data))>>14)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_13(data)                            ((0x00002000&(data))>>13)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_pllddsa_tst(data)                         ((0x00001000&(data))>>12)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_pllddsa_pstst(data)                       ((0x00000800&(data))>>11)
#define  PLL_REG_SYS_PLL_DISPA_SD3_get_dummy_10(data)                            ((0x00000400&(data))>>10)

#define  PLL_REG_SYS_PLL_DISPA_SD4                                               0x1800047C
#define  PLL_REG_SYS_PLL_DISPA_SD4_reg_addr                                      "0xB800047C"
#define  PLL_REG_SYS_PLL_DISPA_SD4_reg                                           0xB800047C
#define  PLL_REG_SYS_PLL_DISPA_SD4_inst_addr                                     "0x0038"
#define  set_PLL_REG_SYS_PLL_DISPA_SD4_reg(data)                                 (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPA_SD4_reg)=data)
#define  get_PLL_REG_SYS_PLL_DISPA_SD4_reg                                       (*((volatile unsigned int*)PLL_REG_SYS_PLL_DISPA_SD4_reg))
#define  PLL_REG_SYS_PLL_DISPA_SD4_dummy_30_shift                                (30)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_fupdn_shift                           (29)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_div_shift                             (28)
#define  PLL_REG_SYS_PLL_DISPA_SD4_dummy_27_shift                                (27)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_tst_shift                             (26)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_psen_shift                            (25)
#define  PLL_REG_SYS_PLL_DISPA_SD4_dummy_24_shift                                (24)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_fupdn_shift                           (23)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_div_shift                             (22)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_tst_shift                             (21)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_psen_shift                            (20)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_oeb_shift                             (3)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_rstb_shift                            (2)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_oeb_shift                             (1)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_rstb_shift                            (0)
#define  PLL_REG_SYS_PLL_DISPA_SD4_dummy_30_mask                                 (0x40000000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_fupdn_mask                            (0x20000000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_div_mask                              (0x10000000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_dummy_27_mask                                 (0x08000000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_tst_mask                              (0x04000000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_psen_mask                             (0x02000000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_dummy_24_mask                                 (0x01000000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_fupdn_mask                            (0x00800000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_div_mask                              (0x00400000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_tst_mask                              (0x00200000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_psen_mask                             (0x00100000)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_oeb_mask                              (0x00000008)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_rstb_mask                             (0x00000004)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_oeb_mask                              (0x00000002)
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_rstb_mask                             (0x00000001)
#define  PLL_REG_SYS_PLL_DISPA_SD4_dummy_30(data)                                (0x40000000&((data)<<30))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_fupdn(data)                           (0x20000000&((data)<<29))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_div(data)                             (0x10000000&((data)<<28))
#define  PLL_REG_SYS_PLL_DISPA_SD4_dummy_27(data)                                (0x08000000&((data)<<27))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_tst(data)                             (0x04000000&((data)<<26))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_psen(data)                            (0x02000000&((data)<<25))
#define  PLL_REG_SYS_PLL_DISPA_SD4_dummy_24(data)                                (0x01000000&((data)<<24))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_fupdn(data)                           (0x00800000&((data)<<23))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_div(data)                             (0x00400000&((data)<<22))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_tst(data)                             (0x00200000&((data)<<21))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_psen(data)                            (0x00100000&((data)<<20))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_oeb(data)                             (0x00000008&((data)<<3))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud1a_rstb(data)                            (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_oeb(data)                             (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_DISPA_SD4_psaud2a_rstb(data)                            (0x00000001&(data))
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_dummy_30(data)                            ((0x40000000&(data))>>30)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud1a_fupdn(data)                       ((0x20000000&(data))>>29)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud1a_div(data)                         ((0x10000000&(data))>>28)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_dummy_27(data)                            ((0x08000000&(data))>>27)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud1a_tst(data)                         ((0x04000000&(data))>>26)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud1a_psen(data)                        ((0x02000000&(data))>>25)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_dummy_24(data)                            ((0x01000000&(data))>>24)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud2a_fupdn(data)                       ((0x00800000&(data))>>23)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud2a_div(data)                         ((0x00400000&(data))>>22)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud2a_tst(data)                         ((0x00200000&(data))>>21)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud2a_psen(data)                        ((0x00100000&(data))>>20)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud1a_oeb(data)                         ((0x00000008&(data))>>3)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud1a_rstb(data)                        ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud2a_oeb(data)                         ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_PLL_DISPA_SD4_get_psaud2a_rstb(data)                        (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_DDSA                                                   0x18000480
#define  PLL_REG_SYS_DVFS_DDSA_reg_addr                                          "0xB8000480"
#define  PLL_REG_SYS_DVFS_DDSA_reg                                               0xB8000480
#define  PLL_REG_SYS_DVFS_DDSA_inst_addr                                         "0x0039"
#define  set_PLL_REG_SYS_DVFS_DDSA_reg(data)                                     (*((volatile unsigned int*)PLL_REG_SYS_DVFS_DDSA_reg)=data)
#define  get_PLL_REG_SYS_DVFS_DDSA_reg                                           (*((volatile unsigned int*)PLL_REG_SYS_DVFS_DDSA_reg))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_bypass_pi_shift                           (31)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_en_pi_debug_shift                         (30)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_hs_oc_stop_shift                          (28)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_pi_cur_sel_shift                          (26)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_sel_oc_mode_shift                         (24)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_done_delay_shift                       (16)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_step_shift                             (4)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_sdm_order_shift                           (2)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_done_shift                             (1)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_en_shift                               (0)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_bypass_pi_mask                            (0x80000000)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_en_pi_debug_mask                          (0x40000000)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_hs_oc_stop_mask                           (0x30000000)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_pi_cur_sel_mask                           (0x0C000000)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_sel_oc_mode_mask                          (0x03000000)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_done_delay_mask                        (0x003F0000)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_step_mask                              (0x00003FF0)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_sdm_order_mask                            (0x00000004)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_done_mask                              (0x00000002)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_en_mask                                (0x00000001)
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_bypass_pi(data)                           (0x80000000&((data)<<31))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_en_pi_debug(data)                         (0x40000000&((data)<<30))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_hs_oc_stop(data)                          (0x30000000&((data)<<28))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_pi_cur_sel(data)                          (0x0C000000&((data)<<26))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_sel_oc_mode(data)                         (0x03000000&((data)<<24))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_done_delay(data)                       (0x003F0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_step(data)                             (0x00003FF0&((data)<<4))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_sdm_order(data)                           (0x00000004&((data)<<2))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_done(data)                             (0x00000002&((data)<<1))
#define  PLL_REG_SYS_DVFS_DDSA_pllddsa_oc_en(data)                               (0x00000001&(data))
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_bypass_pi(data)                       ((0x80000000&(data))>>31)
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_en_pi_debug(data)                     ((0x40000000&(data))>>30)
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_hs_oc_stop(data)                      ((0x30000000&(data))>>28)
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_pi_cur_sel(data)                      ((0x0C000000&(data))>>26)
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_sel_oc_mode(data)                     ((0x03000000&(data))>>24)
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_oc_done_delay(data)                   ((0x003F0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_oc_step(data)                         ((0x00003FF0&(data))>>4)
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_sdm_order(data)                       ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_oc_done(data)                         ((0x00000002&(data))>>1)
#define  PLL_REG_SYS_DVFS_DDSA_get_pllddsa_oc_en(data)                           (0x00000001&(data))

#define  PLL_REG_SYS_DVFS_DDSA2                                                  0x18000484
#define  PLL_REG_SYS_DVFS_DDSA2_reg_addr                                         "0xB8000484"
#define  PLL_REG_SYS_DVFS_DDSA2_reg                                              0xB8000484
#define  PLL_REG_SYS_DVFS_DDSA2_inst_addr                                        "0x003A"
#define  set_PLL_REG_SYS_DVFS_DDSA2_reg(data)                                    (*((volatile unsigned int*)PLL_REG_SYS_DVFS_DDSA2_reg)=data)
#define  get_PLL_REG_SYS_DVFS_DDSA2_reg                                          (*((volatile unsigned int*)PLL_REG_SYS_DVFS_DDSA2_reg))
#define  PLL_REG_SYS_DVFS_DDSA2_pllddsa_fcode_dbg_shift                          (16)
#define  PLL_REG_SYS_DVFS_DDSA2_pllddsa_ncode_dbg_shift                          (8)
#define  PLL_REG_SYS_DVFS_DDSA2_pllddsa_fcode_dbg_mask                           (0x07FF0000)
#define  PLL_REG_SYS_DVFS_DDSA2_pllddsa_ncode_dbg_mask                           (0x0000FF00)
#define  PLL_REG_SYS_DVFS_DDSA2_pllddsa_fcode_dbg(data)                          (0x07FF0000&((data)<<16))
#define  PLL_REG_SYS_DVFS_DDSA2_pllddsa_ncode_dbg(data)                          (0x0000FF00&((data)<<8))
#define  PLL_REG_SYS_DVFS_DDSA2_get_pllddsa_fcode_dbg(data)                      ((0x07FF0000&(data))>>16)
#define  PLL_REG_SYS_DVFS_DDSA2_get_pllddsa_ncode_dbg(data)                      ((0x0000FF00&(data))>>8)

#define  PLL_REG_AI_CLKCR                                                        0x18000490
#define  PLL_REG_AI_CLKCR_reg_addr                                               "0xB8000490"
#define  PLL_REG_AI_CLKCR_reg                                                    0xB8000490
#define  PLL_REG_AI_CLKCR_inst_addr                                              "0x003B"
#define  set_PLL_REG_AI_CLKCR_reg(data)                                          (*((volatile unsigned int*)PLL_REG_AI_CLKCR_reg)=data)
#define  get_PLL_REG_AI_CLKCR_reg                                                (*((volatile unsigned int*)PLL_REG_AI_CLKCR_reg))
#define  PLL_REG_AI_CLKCR_swsce_shift                                            (25)
#define  PLL_REG_AI_CLKCR_tme_shift                                              (23)
#define  PLL_REG_AI_CLKCR_tmps_shift                                             (20)
#define  PLL_REG_AI_CLKCR_psc_shift                                              (19)
#define  PLL_REG_AI_CLKCR_swcs_shift                                             (9)
#define  PLL_REG_AI_CLKCR_sd_shift                                               (1)
#define  PLL_REG_AI_CLKCR_su_shift                                               (0)
#define  PLL_REG_AI_CLKCR_swsce_mask                                             (0x02000000)
#define  PLL_REG_AI_CLKCR_tme_mask                                               (0x00800000)
#define  PLL_REG_AI_CLKCR_tmps_mask                                              (0x00100000)
#define  PLL_REG_AI_CLKCR_psc_mask                                               (0x00080000)
#define  PLL_REG_AI_CLKCR_swcs_mask                                              (0x0000FE00)
#define  PLL_REG_AI_CLKCR_sd_mask                                                (0x00000002)
#define  PLL_REG_AI_CLKCR_su_mask                                                (0x00000001)
#define  PLL_REG_AI_CLKCR_swsce(data)                                            (0x02000000&((data)<<25))
#define  PLL_REG_AI_CLKCR_tme(data)                                              (0x00800000&((data)<<23))
#define  PLL_REG_AI_CLKCR_tmps(data)                                             (0x00100000&((data)<<20))
#define  PLL_REG_AI_CLKCR_psc(data)                                              (0x00080000&((data)<<19))
#define  PLL_REG_AI_CLKCR_swcs(data)                                             (0x0000FE00&((data)<<9))
#define  PLL_REG_AI_CLKCR_sd(data)                                               (0x00000002&((data)<<1))
#define  PLL_REG_AI_CLKCR_su(data)                                               (0x00000001&(data))
#define  PLL_REG_AI_CLKCR_get_swsce(data)                                        ((0x02000000&(data))>>25)
#define  PLL_REG_AI_CLKCR_get_tme(data)                                          ((0x00800000&(data))>>23)
#define  PLL_REG_AI_CLKCR_get_tmps(data)                                         ((0x00100000&(data))>>20)
#define  PLL_REG_AI_CLKCR_get_psc(data)                                          ((0x00080000&(data))>>19)
#define  PLL_REG_AI_CLKCR_get_swcs(data)                                         ((0x0000FE00&(data))>>9)
#define  PLL_REG_AI_CLKCR_get_sd(data)                                           ((0x00000002&(data))>>1)
#define  PLL_REG_AI_CLKCR_get_su(data)                                           (0x00000001&(data))

#define  PLL_REG_AI2_CLKCR                                                       0x18000494
#define  PLL_REG_AI2_CLKCR_reg_addr                                              "0xB8000494"
#define  PLL_REG_AI2_CLKCR_reg                                                   0xB8000494
#define  PLL_REG_AI2_CLKCR_inst_addr                                             "0x003C"
#define  set_PLL_REG_AI2_CLKCR_reg(data)                                         (*((volatile unsigned int*)PLL_REG_AI2_CLKCR_reg)=data)
#define  get_PLL_REG_AI2_CLKCR_reg                                               (*((volatile unsigned int*)PLL_REG_AI2_CLKCR_reg))
#define  PLL_REG_AI2_CLKCR_swsce_2_shift                                         (25)
#define  PLL_REG_AI2_CLKCR_tme_2_shift                                           (23)
#define  PLL_REG_AI2_CLKCR_tmps_2_shift                                          (20)
#define  PLL_REG_AI2_CLKCR_psc_2_shift                                           (19)
#define  PLL_REG_AI2_CLKCR_swcs_2_shift                                          (9)
#define  PLL_REG_AI2_CLKCR_sd_2_shift                                            (1)
#define  PLL_REG_AI2_CLKCR_su_2_shift                                            (0)
#define  PLL_REG_AI2_CLKCR_swsce_2_mask                                          (0x02000000)
#define  PLL_REG_AI2_CLKCR_tme_2_mask                                            (0x00800000)
#define  PLL_REG_AI2_CLKCR_tmps_2_mask                                           (0x00100000)
#define  PLL_REG_AI2_CLKCR_psc_2_mask                                            (0x00080000)
#define  PLL_REG_AI2_CLKCR_swcs_2_mask                                           (0x0000FE00)
#define  PLL_REG_AI2_CLKCR_sd_2_mask                                             (0x00000002)
#define  PLL_REG_AI2_CLKCR_su_2_mask                                             (0x00000001)
#define  PLL_REG_AI2_CLKCR_swsce_2(data)                                         (0x02000000&((data)<<25))
#define  PLL_REG_AI2_CLKCR_tme_2(data)                                           (0x00800000&((data)<<23))
#define  PLL_REG_AI2_CLKCR_tmps_2(data)                                          (0x00100000&((data)<<20))
#define  PLL_REG_AI2_CLKCR_psc_2(data)                                           (0x00080000&((data)<<19))
#define  PLL_REG_AI2_CLKCR_swcs_2(data)                                          (0x0000FE00&((data)<<9))
#define  PLL_REG_AI2_CLKCR_sd_2(data)                                            (0x00000002&((data)<<1))
#define  PLL_REG_AI2_CLKCR_su_2(data)                                            (0x00000001&(data))
#define  PLL_REG_AI2_CLKCR_get_swsce_2(data)                                     ((0x02000000&(data))>>25)
#define  PLL_REG_AI2_CLKCR_get_tme_2(data)                                       ((0x00800000&(data))>>23)
#define  PLL_REG_AI2_CLKCR_get_tmps_2(data)                                      ((0x00100000&(data))>>20)
#define  PLL_REG_AI2_CLKCR_get_psc_2(data)                                       ((0x00080000&(data))>>19)
#define  PLL_REG_AI2_CLKCR_get_swcs_2(data)                                      ((0x0000FE00&(data))>>9)
#define  PLL_REG_AI2_CLKCR_get_sd_2(data)                                        ((0x00000002&(data))>>1)
#define  PLL_REG_AI2_CLKCR_get_su_2(data)                                        (0x00000001&(data))

#define  PLL_REG_SYS_PLL_WD_OUT                                                  0x180004AC
#define  PLL_REG_SYS_PLL_WD_OUT_reg_addr                                         "0xB80004AC"
#define  PLL_REG_SYS_PLL_WD_OUT_reg                                              0xB80004AC
#define  PLL_REG_SYS_PLL_WD_OUT_inst_addr                                        "0x003D"
#define  set_PLL_REG_SYS_PLL_WD_OUT_reg(data)                                    (*((volatile unsigned int*)PLL_REG_SYS_PLL_WD_OUT_reg)=data)
#define  get_PLL_REG_SYS_PLL_WD_OUT_reg                                          (*((volatile unsigned int*)PLL_REG_SYS_PLL_WD_OUT_reg))
#define  PLL_REG_SYS_PLL_WD_OUT_pllifadc_wdout_shift                             (19)
#define  PLL_REG_SYS_PLL_WD_OUT_pll27x_wdout_shift                               (18)
#define  PLL_REG_SYS_PLL_WD_OUT_pllvodma_wdout_shift                             (17)
#define  PLL_REG_SYS_PLL_WD_OUT_pllkcpu_wdout_shift                              (16)
#define  PLL_REG_SYS_PLL_WD_OUT_pll512fs_wdout_1_shift                           (15)
#define  PLL_REG_SYS_PLL_WD_OUT_pllaud_status_shift                              (14)
#define  PLL_REG_SYS_PLL_WD_OUT_pll512fs_wdout_shift                             (13)
#define  PLL_REG_SYS_PLL_WD_OUT_pllbush_wdout_shift                              (12)
#define  PLL_REG_SYS_PLL_WD_OUT_pllgpu_wdout_shift                               (11)
#define  PLL_REG_SYS_PLL_WD_OUT_plldif_wdout_shift                               (10)
#define  PLL_REG_SYS_PLL_WD_OUT_pllddsb_wdout_shift                              (8)
#define  PLL_REG_SYS_PLL_WD_OUT_pllvby1_wdout_shift                              (7)
#define  PLL_REG_SYS_PLL_WD_OUT_pllbus_wdout_shift                               (6)
#define  PLL_REG_SYS_PLL_WD_OUT_plldisp_wdout_shift                              (5)
#define  PLL_REG_SYS_PLL_WD_OUT_pllvcpu2_wdout_shift                             (4)
#define  PLL_REG_SYS_PLL_WD_OUT_pllddsa_wdout_shift                              (3)
#define  PLL_REG_SYS_PLL_WD_OUT_pllvcpu_wdout_shift                              (2)
#define  PLL_REG_SYS_PLL_WD_OUT_pllacpu_wdout_shift                              (1)
#define  PLL_REG_SYS_PLL_WD_OUT_pllifadc_wdout_mask                              (0x00080000)
#define  PLL_REG_SYS_PLL_WD_OUT_pll27x_wdout_mask                                (0x00040000)
#define  PLL_REG_SYS_PLL_WD_OUT_pllvodma_wdout_mask                              (0x00020000)
#define  PLL_REG_SYS_PLL_WD_OUT_pllkcpu_wdout_mask                               (0x00010000)
#define  PLL_REG_SYS_PLL_WD_OUT_pll512fs_wdout_1_mask                            (0x00008000)
#define  PLL_REG_SYS_PLL_WD_OUT_pllaud_status_mask                               (0x00004000)
#define  PLL_REG_SYS_PLL_WD_OUT_pll512fs_wdout_mask                              (0x00002000)
#define  PLL_REG_SYS_PLL_WD_OUT_pllbush_wdout_mask                               (0x00001000)
#define  PLL_REG_SYS_PLL_WD_OUT_pllgpu_wdout_mask                                (0x00000800)
#define  PLL_REG_SYS_PLL_WD_OUT_plldif_wdout_mask                                (0x00000400)
#define  PLL_REG_SYS_PLL_WD_OUT_pllddsb_wdout_mask                               (0x00000100)
#define  PLL_REG_SYS_PLL_WD_OUT_pllvby1_wdout_mask                               (0x00000080)
#define  PLL_REG_SYS_PLL_WD_OUT_pllbus_wdout_mask                                (0x00000040)
#define  PLL_REG_SYS_PLL_WD_OUT_plldisp_wdout_mask                               (0x00000020)
#define  PLL_REG_SYS_PLL_WD_OUT_pllvcpu2_wdout_mask                              (0x00000010)
#define  PLL_REG_SYS_PLL_WD_OUT_pllddsa_wdout_mask                               (0x00000008)
#define  PLL_REG_SYS_PLL_WD_OUT_pllvcpu_wdout_mask                               (0x00000004)
#define  PLL_REG_SYS_PLL_WD_OUT_pllacpu_wdout_mask                               (0x00000002)
#define  PLL_REG_SYS_PLL_WD_OUT_pllifadc_wdout(data)                             (0x00080000&((data)<<19))
#define  PLL_REG_SYS_PLL_WD_OUT_pll27x_wdout(data)                               (0x00040000&((data)<<18))
#define  PLL_REG_SYS_PLL_WD_OUT_pllvodma_wdout(data)                             (0x00020000&((data)<<17))
#define  PLL_REG_SYS_PLL_WD_OUT_pllkcpu_wdout(data)                              (0x00010000&((data)<<16))
#define  PLL_REG_SYS_PLL_WD_OUT_pll512fs_wdout_1(data)                           (0x00008000&((data)<<15))
#define  PLL_REG_SYS_PLL_WD_OUT_pllaud_status(data)                              (0x00004000&((data)<<14))
#define  PLL_REG_SYS_PLL_WD_OUT_pll512fs_wdout(data)                             (0x00002000&((data)<<13))
#define  PLL_REG_SYS_PLL_WD_OUT_pllbush_wdout(data)                              (0x00001000&((data)<<12))
#define  PLL_REG_SYS_PLL_WD_OUT_pllgpu_wdout(data)                               (0x00000800&((data)<<11))
#define  PLL_REG_SYS_PLL_WD_OUT_plldif_wdout(data)                               (0x00000400&((data)<<10))
#define  PLL_REG_SYS_PLL_WD_OUT_pllddsb_wdout(data)                              (0x00000100&((data)<<8))
#define  PLL_REG_SYS_PLL_WD_OUT_pllvby1_wdout(data)                              (0x00000080&((data)<<7))
#define  PLL_REG_SYS_PLL_WD_OUT_pllbus_wdout(data)                               (0x00000040&((data)<<6))
#define  PLL_REG_SYS_PLL_WD_OUT_plldisp_wdout(data)                              (0x00000020&((data)<<5))
#define  PLL_REG_SYS_PLL_WD_OUT_pllvcpu2_wdout(data)                             (0x00000010&((data)<<4))
#define  PLL_REG_SYS_PLL_WD_OUT_pllddsa_wdout(data)                              (0x00000008&((data)<<3))
#define  PLL_REG_SYS_PLL_WD_OUT_pllvcpu_wdout(data)                              (0x00000004&((data)<<2))
#define  PLL_REG_SYS_PLL_WD_OUT_pllacpu_wdout(data)                              (0x00000002&((data)<<1))
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllifadc_wdout(data)                         ((0x00080000&(data))>>19)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pll27x_wdout(data)                           ((0x00040000&(data))>>18)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllvodma_wdout(data)                         ((0x00020000&(data))>>17)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllkcpu_wdout(data)                          ((0x00010000&(data))>>16)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pll512fs_wdout_1(data)                       ((0x00008000&(data))>>15)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllaud_status(data)                          ((0x00004000&(data))>>14)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pll512fs_wdout(data)                         ((0x00002000&(data))>>13)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllbush_wdout(data)                          ((0x00001000&(data))>>12)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllgpu_wdout(data)                           ((0x00000800&(data))>>11)
#define  PLL_REG_SYS_PLL_WD_OUT_get_plldif_wdout(data)                           ((0x00000400&(data))>>10)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllddsb_wdout(data)                          ((0x00000100&(data))>>8)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllvby1_wdout(data)                          ((0x00000080&(data))>>7)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllbus_wdout(data)                           ((0x00000040&(data))>>6)
#define  PLL_REG_SYS_PLL_WD_OUT_get_plldisp_wdout(data)                          ((0x00000020&(data))>>5)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllvcpu2_wdout(data)                         ((0x00000010&(data))>>4)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllddsa_wdout(data)                          ((0x00000008&(data))>>3)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllvcpu_wdout(data)                          ((0x00000004&(data))>>2)
#define  PLL_REG_SYS_PLL_WD_OUT_get_pllacpu_wdout(data)                          ((0x00000002&(data))>>1)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PLL_REG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_n:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  pllddsb_ip:4;
        RBus_UInt32  pllddsb_rs:3;
        RBus_UInt32  pllddsb_cs:2;
        RBus_UInt32  pllddsb_cp:2;
        RBus_UInt32  res2:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllddsb_o:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pllddsb_wdmode:2;
    };
}pll_reg_sys_pll_dispb_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsb_fcode:11;
        RBus_UInt32  pllddsb_ncode:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsb_oeb:1;
        RBus_UInt32  pllddsb_rstb:1;
        RBus_UInt32  pllddsb_pow:1;
    };
}pll_reg_sys_pll_dispb_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18000358_28_25:4;
        RBus_UInt32  dummy18000358_24:1;
        RBus_UInt32  dummy18000358_23:1;
        RBus_UInt32  dummy18000358_22:1;
        RBus_UInt32  dummy18000358_21:1;
        RBus_UInt32  dummy18000358_20:1;
        RBus_UInt32  dummy18000358_19:1;
        RBus_UInt32  dummy18000358_18:1;
        RBus_UInt32  dummy18000358_17:1;
        RBus_UInt32  dummy18000358_16:1;
        RBus_UInt32  dummy18000358_15:1;
        RBus_UInt32  pllddsb_vcorb:1;
        RBus_UInt32  dummy18000358_13:1;
        RBus_UInt32  pllddsb_tst:1;
        RBus_UInt32  pllddsb_pstst:1;
        RBus_UInt32  dummy18000358_10:1;
        RBus_UInt32  res2:10;
    };
}pll_reg_sys_pll_dispb_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy1800035c_30:1;
        RBus_UInt32  psaud1b_fupdn:1;
        RBus_UInt32  psaud1b_div:1;
        RBus_UInt32  dummy1800035c_27:1;
        RBus_UInt32  psaud1b_tst:1;
        RBus_UInt32  psaud1b_psen:1;
        RBus_UInt32  dummy1800035c_24:1;
        RBus_UInt32  psaud2b_fupdn:1;
        RBus_UInt32  psaud2b_div:1;
        RBus_UInt32  psaud2b_tst:1;
        RBus_UInt32  psaud2b_psen:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  psaud1b_oeb:1;
        RBus_UInt32  psaud1b_rstb:1;
        RBus_UInt32  psaud2b_oeb:1;
        RBus_UInt32  psaud2b_rstb:1;
    };
}pll_reg_sys_pll_dispb_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_bypass_pi:1;
        RBus_UInt32  pllddsb_en_pi_debug:1;
        RBus_UInt32  pllddsb_hs_oc_stop:2;
        RBus_UInt32  pllddsb_pi_cur_sel:2;
        RBus_UInt32  pllddsb_sel_oc_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllddsb_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllddsb_oc_step:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsb_sdm_order:1;
        RBus_UInt32  pllddsb_oc_done:1;
        RBus_UInt32  pllddsb_oc_en:1;
    };
}pll_reg_sys_dvfs_ddsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsb_fcode_dbg:11;
        RBus_UInt32  pllddsb_ncode_dbg:8;
        RBus_UInt32  res2:8;
    };
}pll_reg_sys_dvfs_ddsb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  swsce_b:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tme_b:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmps_b:1;
        RBus_UInt32  psc_b:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  swcs_b:7;
        RBus_UInt32  res5:7;
        RBus_UInt32  sd_b:1;
        RBus_UInt32  su_b:1;
    };
}pll_reg_ai_b_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  swsce_b_2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tme_b_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmps_b_2:1;
        RBus_UInt32  psc_b_2:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  swcs_b_2:7;
        RBus_UInt32  res5:7;
        RBus_UInt32  sd_b_2:1;
        RBus_UInt32  su_b_2:1;
    };
}pll_reg_ai2_b_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tm_a:29;
    };
}pll_reg_temp_sensor_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_b:22;
        RBus_UInt32  tm_adccksel:3;
        RBus_UInt32  tm_cal_en:1;
        RBus_UInt32  tm_biaschop:1;
        RBus_UInt32  tm_chopen:1;
        RBus_UInt32  tm_cksourcesel:1;
        RBus_UInt32  tm_dsr:3;
    };
}pll_reg_temp_sensor_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000388_31:1;
        RBus_UInt32  tm_filteredgesel:1;
        RBus_UInt32  tm_hold_en:1;
        RBus_UInt32  tm_order3:1;
        RBus_UInt32  tm_offset:22;
        RBus_UInt32  tm_pow:1;
        RBus_UInt32  res1:5;
    };
}pll_reg_temp_sensor_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_r:24;
        RBus_UInt32  tm_opcursel:2;
        RBus_UInt32  tm_hold_dly:2;
        RBus_UInt32  tm_osccursel:2;
        RBus_UInt32  tm_resol:2;
    };
}pll_reg_temp_sensor_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_rstb:1;
        RBus_UInt32  tm_sdm_test:1;
        RBus_UInt32  tm_sdm_test_en:1;
        RBus_UInt32  tm_test_en:1;
        RBus_UInt32  tm_vcmsel:3;
        RBus_UInt32  tm_vbe_biassel:2;
        RBus_UInt32  tm_chopfreqsel:11;
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18000390_8_4:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  dummy18000390_0:1;
    };
}pll_reg_temp_sensor_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000394_31_16:16;
        RBus_UInt32  dummy18000394_15_0:16;
    };
}pll_reg_temp_sensor_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000398_31_16:16;
        RBus_UInt32  dummy18000398_15:1;
        RBus_UInt32  dummy18000398_14_12:3;
        RBus_UInt32  dummy18000398_11_10:2;
        RBus_UInt32  dummy18000398_9_7:3;
        RBus_UInt32  dummy18000398_6:1;
        RBus_UInt32  dummy18000398_5:1;
        RBus_UInt32  dummy18000398_4:1;
        RBus_UInt32  tm_biasdem_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  td_wrep_edge_sel:1;
        RBus_UInt32  dummy18000398_0:1;
    };
}pll_reg_temp_sensor_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tm_s:23;
    };
}pll_reg_temp_sensor_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy180003a0_30_24:7;
        RBus_UInt32  res2:5;
        RBus_UInt32  ct_out_o_tm:19;
    };
}pll_reg_thermal_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  u_out_tm:22;
    };
}pll_reg_thermal_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  thermal_sensor_ie:1;
        RBus_UInt32  thermal_sensor_irq_status:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  thermal_sensor_kcpu_ie:1;
        RBus_UInt32  thermal_sensor_irq_kcpu_status:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  thermal_sensor_thh:19;
    };
}pll_reg_thermal_irq_threshold_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  thermal_sensor_thl:19;
    };
}pll_reg_thermal_irq_threshold_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllkcpu_tst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllkcpu_n:2;
        RBus_UInt32  pllkcpu_m:8;
        RBus_UInt32  pllkcpu_ip:3;
        RBus_UInt32  pllkcpu_o:2;
        RBus_UInt32  pllkcpu_wdset:1;
        RBus_UInt32  pllkcpu_wdrst:1;
        RBus_UInt32  pllkcpu_cs:2;
        RBus_UInt32  pllkcpu_rs:3;
    };
}pll_reg_sys_pll_kcpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllkcpu_oeb:1;
        RBus_UInt32  pllkcpu_rstb:1;
        RBus_UInt32  pllkcpu_pow:1;
    };
}pll_reg_sys_pll_kcpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbus_gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllbus_en_ssc:1;
    };
}pll_reg_pll_ssc_bus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllbus_fcode_ssc:11;
    };
}pll_reg_pll_ssc_bus_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbus_gran_auto_rst_h:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_dot_gran_h:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_gran_est_h:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllbus_en_ssc_h:1;
    };
}pll_reg_pll_ssc_bush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_ncode_ssc_h:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllbus_fcode_ssc_h:11;
    };
}pll_reg_pll_ssc_bush_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllddsa_gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsa_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsa_gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllddsa_en_ssc:1;
    };
}pll_reg_pll_ssc_ddsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllddsa_ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllddsa_fcode_ssc:11;
    };
}pll_reg_pll_ssc_ddsa_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllddsb_gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsb_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsb_gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllddsb_en_ssc:1;
    };
}pll_reg_pll_ssc_ddsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllddsb_ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllddsb_fcode_ssc:11;
    };
}pll_reg_pll_ssc_ddsb_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  psaud2b_ssc_ckinv:1;
        RBus_UInt32  psaud2a_ssc_ckinv:1;
        RBus_UInt32  psaud1b_ssc_ckinv:1;
        RBus_UInt32  psaud1a_ssc_ckinv:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dds_ssc_ckinv:1;
        RBus_UInt32  gpu_ssc_ckinv:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  bush_ssc_ckinv:1;
        RBus_UInt32  bus_ssc_ckinv:1;
    };
}pll_reg_pll_ssc_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  pow_ldo1v:1;
        RBus_UInt32  ldo1v_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllcpu_reg:2;
    };
}pll_reg_sys_pll_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllacpu_tst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllacpu_n:2;
        RBus_UInt32  pllacpu_m:8;
        RBus_UInt32  pllacpu_ip:3;
        RBus_UInt32  pllacpu_o:2;
        RBus_UInt32  pllacpu_wdset:1;
        RBus_UInt32  pllacpu_wdrst:1;
        RBus_UInt32  pllacpu_cs:2;
        RBus_UInt32  pllacpu_rs:3;
    };
}pll_reg_sys_pll_acpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllacpu_oeb:1;
        RBus_UInt32  pllacpu_rstb:1;
        RBus_UInt32  pllacpu_pow:1;
    };
}pll_reg_sys_pll_acpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllvcpu_tst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllvcpu_n:2;
        RBus_UInt32  pllvcpu_m:8;
        RBus_UInt32  pllvcpu_ip:3;
        RBus_UInt32  pllvcpu_o:2;
        RBus_UInt32  pllvcpu_wdset:1;
        RBus_UInt32  pllvcpu_wdrst:1;
        RBus_UInt32  pllvcpu_cs:2;
        RBus_UInt32  pllvcpu_rs:3;
    };
}pll_reg_sys_pll_vcpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllvcpu_oeb:1;
        RBus_UInt32  pllvcpu_rstb:1;
        RBus_UInt32  pllvcpu_pow:1;
    };
}pll_reg_sys_pll_vcpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllvcpu_tst_2:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllvcpu_n_2:2;
        RBus_UInt32  pllvcpu_m_2:8;
        RBus_UInt32  pllvcpu_ip_2:3;
        RBus_UInt32  pllvcpu_o_2:2;
        RBus_UInt32  pllvcpu_wdset_2:1;
        RBus_UInt32  pllvcpu_wdrst_2:1;
        RBus_UInt32  pllvcpu_cs_2:2;
        RBus_UInt32  pllvcpu_rs_2:3;
    };
}pll_reg_sys_pll_vcpu2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllvcpu_oeb_2:1;
        RBus_UInt32  pllvcpu_rstb_2:1;
        RBus_UInt32  pllvcpu_pow_2:1;
    };
}pll_reg_sys_pll_vcpu2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  pllbus_wdset:1;
        RBus_UInt32  pllbus_wdrst:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  pllbus_lpf_cs:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  pllbus_testsel:1;
        RBus_UInt32  pllbus_sel_cco:1;
        RBus_UInt32  pllbus_icp:4;
        RBus_UInt32  pllbus_dbug_en:1;
        RBus_UInt32  pllbus_pdiv_bps:1;
        RBus_UInt32  pllbus_pdiv:2;
        RBus_UInt32  res8:1;
        RBus_UInt32  pllbus_lpf_rs:3;
    };
}pll_reg_sys_pll_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_fcode:11;
        RBus_UInt32  pllbus_ncode:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_oeb:1;
        RBus_UInt32  pllbus_rstb:1;
        RBus_UInt32  pllbus_pow:1;
    };
}pll_reg_sys_pll_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_bypass_pi:1;
        RBus_UInt32  pllbus_en_pi_debug:1;
        RBus_UInt32  pllbus_hs_oc_stop:2;
        RBus_UInt32  pllbus_pi_cur_sel:2;
        RBus_UInt32  pllbus_sel_oc_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllbus_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_oc_step:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_sdm_order:1;
        RBus_UInt32  pllbus_oc_done:1;
        RBus_UInt32  pllbus_oc_en:1;
    };
}pll_reg_sys_dvfs_bus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_fcode_dbg:11;
        RBus_UInt32  pllbus_ncode_dbg:8;
        RBus_UInt32  res2:8;
    };
}pll_reg_sys_dvfs_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  pllbus_wdset_h:1;
        RBus_UInt32  pllbus_wdrst_h:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  pllbus_lpf_cs_h:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  pllbus_testsel_h:1;
        RBus_UInt32  pllbus_sel_cco_h:1;
        RBus_UInt32  pllbus_icp_h:4;
        RBus_UInt32  pllbus_dbug_en_h:1;
        RBus_UInt32  pllbus_pdiv_bps_h:1;
        RBus_UInt32  pllbus_pdiv_h:2;
        RBus_UInt32  res8:1;
        RBus_UInt32  pllbus_lpf_rs_h:3;
    };
}pll_reg_sys_pll_bush1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_fcode_h:11;
        RBus_UInt32  pllbus_ncode_h:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_oeb_h:1;
        RBus_UInt32  pllbus_rstb_h:1;
        RBus_UInt32  pllbus_pow_h:1;
    };
}pll_reg_sys_pll_bush2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_bypass_pi_h:1;
        RBus_UInt32  pllbus_en_pi_debug_h:1;
        RBus_UInt32  pllbus_hs_oc_stop_h:2;
        RBus_UInt32  pllbus_pi_cur_sel_h:2;
        RBus_UInt32  pllbus_sel_oc_mode_h:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllbus_oc_done_delay_h:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_oc_step_h:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_sdm_order_h:1;
        RBus_UInt32  pllbus_oc_done_h:1;
        RBus_UInt32  pllbus_oc_en_h:1;
    };
}pll_reg_sys_dvfs_bush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_fcode_dbg_h:11;
        RBus_UInt32  pllbus_ncode_dbg_h:8;
        RBus_UInt32  res2:8;
    };
}pll_reg_sys_dvfs_bush2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  pllgpu_wdset:1;
        RBus_UInt32  pllgpu_wdrst:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  pllgpu_lpf_cs:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  pllgpu_testsel:1;
        RBus_UInt32  pllgpu_sel_cco:1;
        RBus_UInt32  pllgpu_icp:4;
        RBus_UInt32  pllgpu_dbug_en:1;
        RBus_UInt32  pllgpu_pdiv_bps:1;
        RBus_UInt32  pllgpu_pdiv:2;
        RBus_UInt32  res8:1;
        RBus_UInt32  pllgpu_lpf_rs:3;
    };
}pll_reg_sys_pll_gpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllgpu_fcode:11;
        RBus_UInt32  pllgpu_ncode:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllgpu_oeb:1;
        RBus_UInt32  pllgpu_rstb:1;
        RBus_UInt32  pllgpu_pow:1;
    };
}pll_reg_sys_pll_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_bypass_pi:1;
        RBus_UInt32  pllgpu_en_pi_debug:1;
        RBus_UInt32  pllgpu_hs_oc_stop:2;
        RBus_UInt32  pllgpu_pi_cur_sel:2;
        RBus_UInt32  pllgpu_sel_oc_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllgpu_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllgpu_oc_step:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllgpu_sdm_order:1;
        RBus_UInt32  pllgpu_oc_done:1;
        RBus_UInt32  pllgpu_oc_en:1;
    };
}pll_reg_sys_dvfs_gpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllgpu_fcode_dbg:11;
        RBus_UInt32  pllgpu_ncode_dbg:8;
        RBus_UInt32  res2:8;
    };
}pll_reg_sys_dvfs_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllvodma_n:2;
        RBus_UInt32  pllvodma_m:8;
        RBus_UInt32  pllvodma_ip:3;
        RBus_UInt32  pllvodma_o:2;
        RBus_UInt32  pllvodma_wdset:1;
        RBus_UInt32  pllvodma_wdrst:1;
        RBus_UInt32  pllvodma_cs:2;
        RBus_UInt32  pllvodma_rs:3;
    };
}pll_reg_sys_pll_vodma1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllvodma_tst:1;
        RBus_UInt32  pllvodma_oeb:1;
        RBus_UInt32  pllvodma_rstb:1;
        RBus_UInt32  pllvodma_pow:1;
    };
}pll_reg_sys_pll_vodma2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_reser:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_reg:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbustst_div:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllbustst_sel:5;
    };
}pll_reg_sys_pllbus_tst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_n:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  pllddsa_ip:4;
        RBus_UInt32  pllddsa_rs:3;
        RBus_UInt32  pllddsa_cs:2;
        RBus_UInt32  pllddsa_cp:2;
        RBus_UInt32  res2:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllddsa_o:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pllddsa_wdmode:2;
    };
}pll_reg_sys_pll_dispa_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsa_fcode:11;
        RBus_UInt32  pllddsa_ncode:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsa_oeb:1;
        RBus_UInt32  pllddsa_rstb:1;
        RBus_UInt32  pllddsa_pow:1;
    };
}pll_reg_sys_pll_dispa_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18000478_28_25:4;
        RBus_UInt32  dummy18000478_24:1;
        RBus_UInt32  dummy18000478_23:1;
        RBus_UInt32  dummy18000478_22:1;
        RBus_UInt32  dummy18000478_21:1;
        RBus_UInt32  dummy18000478_20:1;
        RBus_UInt32  dummy18000478_19:1;
        RBus_UInt32  dummy18000478_18:1;
        RBus_UInt32  dummy18000478_17:1;
        RBus_UInt32  dummy18000478_16:1;
        RBus_UInt32  dummy18000478_15:1;
        RBus_UInt32  pllddsa_vcorb:1;
        RBus_UInt32  dummy18000478_13:1;
        RBus_UInt32  pllddsa_tst:1;
        RBus_UInt32  pllddsa_pstst:1;
        RBus_UInt32  dummy18000478_10:1;
        RBus_UInt32  res2:10;
    };
}pll_reg_sys_pll_dispa_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy1800047c_30:1;
        RBus_UInt32  psaud1a_fupdn:1;
        RBus_UInt32  psaud1a_div:1;
        RBus_UInt32  dummy1800047c_27:1;
        RBus_UInt32  psaud1a_tst:1;
        RBus_UInt32  psaud1a_psen:1;
        RBus_UInt32  dummy1800047c_24:1;
        RBus_UInt32  psaud2a_fupdn:1;
        RBus_UInt32  psaud2a_div:1;
        RBus_UInt32  psaud2a_tst:1;
        RBus_UInt32  psaud2a_psen:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  psaud1a_oeb:1;
        RBus_UInt32  psaud1a_rstb:1;
        RBus_UInt32  psaud2a_oeb:1;
        RBus_UInt32  psaud2a_rstb:1;
    };
}pll_reg_sys_pll_dispa_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_bypass_pi:1;
        RBus_UInt32  pllddsa_en_pi_debug:1;
        RBus_UInt32  pllddsa_hs_oc_stop:2;
        RBus_UInt32  pllddsa_pi_cur_sel:2;
        RBus_UInt32  pllddsa_sel_oc_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllddsa_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllddsa_oc_step:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsa_sdm_order:1;
        RBus_UInt32  pllddsa_oc_done:1;
        RBus_UInt32  pllddsa_oc_en:1;
    };
}pll_reg_sys_dvfs_ddsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsa_fcode_dbg:11;
        RBus_UInt32  pllddsa_ncode_dbg:8;
        RBus_UInt32  res2:8;
    };
}pll_reg_sys_dvfs_ddsa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  swsce:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tme:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmps:1;
        RBus_UInt32  psc:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  swcs:7;
        RBus_UInt32  res5:7;
        RBus_UInt32  sd:1;
        RBus_UInt32  su:1;
    };
}pll_reg_ai_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  swsce_2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tme_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmps_2:1;
        RBus_UInt32  psc_2:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  swcs_2:7;
        RBus_UInt32  res5:7;
        RBus_UInt32  sd_2:1;
        RBus_UInt32  su_2:1;
    };
}pll_reg_ai2_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  pllifadc_wdout:1;
        RBus_UInt32  pll27x_wdout:1;
        RBus_UInt32  pllvodma_wdout:1;
        RBus_UInt32  pllkcpu_wdout:1;
        RBus_UInt32  pll512fs_wdout_1:1;
        RBus_UInt32  pllaud_status:1;
        RBus_UInt32  pll512fs_wdout:1;
        RBus_UInt32  pllbush_wdout:1;
        RBus_UInt32  pllgpu_wdout:1;
        RBus_UInt32  plldif_wdout:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsb_wdout:1;
        RBus_UInt32  pllvby1_wdout:1;
        RBus_UInt32  pllbus_wdout:1;
        RBus_UInt32  plldisp_wdout:1;
        RBus_UInt32  pllvcpu2_wdout:1;
        RBus_UInt32  pllddsa_wdout:1;
        RBus_UInt32  pllvcpu_wdout:1;
        RBus_UInt32  pllacpu_wdout:1;
        RBus_UInt32  res3:1;
    };
}pll_reg_sys_pll_wd_out_RBUS;

#else //apply LITTLE_ENDIAN

//======PLL_REG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_wdmode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllddsb_o:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  pllddsb_cp:2;
        RBus_UInt32  pllddsb_cs:2;
        RBus_UInt32  pllddsb_rs:3;
        RBus_UInt32  pllddsb_ip:4;
        RBus_UInt32  res4:6;
        RBus_UInt32  pllddsb_n:2;
    };
}pll_reg_sys_pll_dispb_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_pow:1;
        RBus_UInt32  pllddsb_rstb:1;
        RBus_UInt32  pllddsb_oeb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllddsb_ncode:8;
        RBus_UInt32  pllddsb_fcode:11;
        RBus_UInt32  res3:5;
    };
}pll_reg_sys_pll_dispb_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dummy18000358_10_10:1;
        RBus_UInt32  pllddsb_pstst:1;
        RBus_UInt32  pllddsb_tst:1;
        RBus_UInt32  dummy18000358_13_13:1;
        RBus_UInt32  pllddsb_vcorb:1;
        RBus_UInt32  dummy18000358_15_15:1;
        RBus_UInt32  dummy18000358_16_16:1;
        RBus_UInt32  dummy18000358_17_17:1;
        RBus_UInt32  dummy18000358_18_18:1;
        RBus_UInt32  dummy18000358_19_19:1;
        RBus_UInt32  dummy18000358_20_20:1;
        RBus_UInt32  dummy18000358_21_21:1;
        RBus_UInt32  dummy18000358_22_22:1;
        RBus_UInt32  dummy18000358_23_23:1;
        RBus_UInt32  dummy18000358_24_24:1;
        RBus_UInt32  dummy18000358_28_25:4;
        RBus_UInt32  res2:3;
    };
}pll_reg_sys_pll_dispb_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud2b_rstb:1;
        RBus_UInt32  psaud2b_oeb:1;
        RBus_UInt32  psaud1b_rstb:1;
        RBus_UInt32  psaud1b_oeb:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  psaud2b_psen:1;
        RBus_UInt32  psaud2b_tst:1;
        RBus_UInt32  psaud2b_div:1;
        RBus_UInt32  psaud2b_fupdn:1;
        RBus_UInt32  dummy1800035c_24:1;
        RBus_UInt32  psaud1b_psen:1;
        RBus_UInt32  psaud1b_tst:1;
        RBus_UInt32  dummy1800035c_27:1;
        RBus_UInt32  psaud1b_div:1;
        RBus_UInt32  psaud1b_fupdn:1;
        RBus_UInt32  dummy1800035c_30:1;
        RBus_UInt32  res2:1;
    };
}pll_reg_sys_pll_dispb_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_oc_en:1;
        RBus_UInt32  pllddsb_oc_done:1;
        RBus_UInt32  pllddsb_sdm_order:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllddsb_oc_step:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllddsb_oc_done_delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllddsb_sel_oc_mode:2;
        RBus_UInt32  pllddsb_pi_cur_sel:2;
        RBus_UInt32  pllddsb_hs_oc_stop:2;
        RBus_UInt32  pllddsb_en_pi_debug:1;
        RBus_UInt32  pllddsb_bypass_pi:1;
    };
}pll_reg_sys_dvfs_ddsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllddsb_ncode_dbg:8;
        RBus_UInt32  pllddsb_fcode_dbg:11;
        RBus_UInt32  res2:5;
    };
}pll_reg_sys_dvfs_ddsb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_b:1;
        RBus_UInt32  sd_b:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  swcs_b:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  psc_b:1;
        RBus_UInt32  tmps_b:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tme_b:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  swsce_b:1;
        RBus_UInt32  res5:6;
    };
}pll_reg_ai_b_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_b_2:1;
        RBus_UInt32  sd_b_2:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  swcs_b_2:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  psc_b_2:1;
        RBus_UInt32  tmps_b_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tme_b_2:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  swsce_b_2:1;
        RBus_UInt32  res5:6;
    };
}pll_reg_ai2_b_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_a:29;
        RBus_UInt32  res1:3;
    };
}pll_reg_temp_sensor_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_dsr:3;
        RBus_UInt32  tm_cksourcesel:1;
        RBus_UInt32  tm_chopen:1;
        RBus_UInt32  tm_biaschop:1;
        RBus_UInt32  tm_cal_en:1;
        RBus_UInt32  tm_adccksel:3;
        RBus_UInt32  tm_b:22;
    };
}pll_reg_temp_sensor_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tm_pow:1;
        RBus_UInt32  tm_offset:22;
        RBus_UInt32  tm_order3:1;
        RBus_UInt32  tm_hold_en:1;
        RBus_UInt32  tm_filteredgesel:1;
        RBus_UInt32  dummy18000388_31_31:1;
    };
}pll_reg_temp_sensor_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_resol:2;
        RBus_UInt32  tm_osccursel:2;
        RBus_UInt32  tm_hold_dly:2;
        RBus_UInt32  tm_opcursel:2;
        RBus_UInt32  tm_r:24;
    };
}pll_reg_temp_sensor_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000390_0:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18000390_8:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tm_chopfreqsel:11;
        RBus_UInt32  tm_vbe_biassel:2;
        RBus_UInt32  tm_vcmsel:3;
        RBus_UInt32  tm_test_en:1;
        RBus_UInt32  tm_sdm_test_en:1;
        RBus_UInt32  tm_sdm_test:1;
        RBus_UInt32  tm_rstb:1;
    };
}pll_reg_temp_sensor_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000394_15_0:16;
        RBus_UInt32  dummy18000394_31_16:16;
    };
}pll_reg_temp_sensor_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000398_0:1;
        RBus_UInt32  td_wrep_edge_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  tm_biasdem_sel:1;
        RBus_UInt32  dummy18000398_4:1;
        RBus_UInt32  dummy18000398_5:1;
        RBus_UInt32  dummy18000398_6:1;
        RBus_UInt32  dummy18000398_9:3;
        RBus_UInt32  dummy18000398_11:2;
        RBus_UInt32  dummy18000398_14:3;
        RBus_UInt32  dummy18000398_15:1;
        RBus_UInt32  dummy18000398_31:16;
    };
}pll_reg_temp_sensor_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_s:23;
        RBus_UInt32  res1:9;
    };
}pll_reg_temp_sensor_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ct_out_o_tm:19;
        RBus_UInt32  res1:5;
        RBus_UInt32  dummy180003a0_30_24:7;
        RBus_UInt32  res2:1;
    };
}pll_reg_thermal_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u_out_tm:22;
        RBus_UInt32  res1:10;
    };
}pll_reg_thermal_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  thermal_sensor_thh:19;
        RBus_UInt32  res1:6;
        RBus_UInt32  thermal_sensor_irq_kcpu_status:2;
        RBus_UInt32  thermal_sensor_kcpu_ie:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  thermal_sensor_irq_status:2;
        RBus_UInt32  thermal_sensor_ie:1;
    };
}pll_reg_thermal_irq_threshold_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  thermal_sensor_thl:19;
        RBus_UInt32  res1:13;
    };
}pll_reg_thermal_irq_threshold_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllkcpu_rs:3;
        RBus_UInt32  pllkcpu_cs:2;
        RBus_UInt32  pllkcpu_wdrst:1;
        RBus_UInt32  pllkcpu_wdset:1;
        RBus_UInt32  pllkcpu_o:2;
        RBus_UInt32  pllkcpu_ip:3;
        RBus_UInt32  pllkcpu_m:8;
        RBus_UInt32  pllkcpu_n:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllkcpu_tst:1;
        RBus_UInt32  res2:7;
    };
}pll_reg_sys_pll_kcpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllkcpu_pow:1;
        RBus_UInt32  pllkcpu_rstb:1;
        RBus_UInt32  pllkcpu_oeb:1;
        RBus_UInt32  res1:29;
    };
}pll_reg_sys_pll_kcpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbus_gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}pll_reg_pll_ssc_bus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}pll_reg_pll_ssc_bus_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_en_ssc_h:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbus_gran_est_h:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_dot_gran_h:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_gran_auto_rst_h:1;
        RBus_UInt32  res4:3;
    };
}pll_reg_pll_ssc_bush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_fcode_ssc_h:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_ncode_ssc_h:8;
        RBus_UInt32  res2:8;
    };
}pll_reg_pll_ssc_bush_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllddsa_gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsa_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsa_gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}pll_reg_pll_ssc_ddsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsa_ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}pll_reg_pll_ssc_ddsa_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllddsb_gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsb_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsb_gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}pll_reg_pll_ssc_ddsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsb_ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}pll_reg_pll_ssc_ddsb_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bus_ssc_ckinv:1;
        RBus_UInt32  bush_ssc_ckinv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  gpu_ssc_ckinv:1;
        RBus_UInt32  dds_ssc_ckinv:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  psaud1a_ssc_ckinv:1;
        RBus_UInt32  psaud1b_ssc_ckinv:1;
        RBus_UInt32  psaud2a_ssc_ckinv:1;
        RBus_UInt32  psaud2b_ssc_ckinv:1;
        RBus_UInt32  res3:20;
    };
}pll_reg_pll_ssc_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllcpu_reg:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  ldo1v_sel:2;
        RBus_UInt32  pow_ldo1v:1;
        RBus_UInt32  res2:25;
    };
}pll_reg_sys_pll_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllacpu_rs:3;
        RBus_UInt32  pllacpu_cs:2;
        RBus_UInt32  pllacpu_wdrst:1;
        RBus_UInt32  pllacpu_wdset:1;
        RBus_UInt32  pllacpu_o:2;
        RBus_UInt32  pllacpu_ip:3;
        RBus_UInt32  pllacpu_m:8;
        RBus_UInt32  pllacpu_n:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllacpu_tst:1;
        RBus_UInt32  res2:7;
    };
}pll_reg_sys_pll_acpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllacpu_pow:1;
        RBus_UInt32  pllacpu_rstb:1;
        RBus_UInt32  pllacpu_oeb:1;
        RBus_UInt32  res1:29;
    };
}pll_reg_sys_pll_acpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_rs:3;
        RBus_UInt32  pllvcpu_cs:2;
        RBus_UInt32  pllvcpu_wdrst:1;
        RBus_UInt32  pllvcpu_wdset:1;
        RBus_UInt32  pllvcpu_o:2;
        RBus_UInt32  pllvcpu_ip:3;
        RBus_UInt32  pllvcpu_m:8;
        RBus_UInt32  pllvcpu_n:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllvcpu_tst:1;
        RBus_UInt32  res2:7;
    };
}pll_reg_sys_pll_vcpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_pow:1;
        RBus_UInt32  pllvcpu_rstb:1;
        RBus_UInt32  pllvcpu_oeb:1;
        RBus_UInt32  res1:29;
    };
}pll_reg_sys_pll_vcpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_rs_2:3;
        RBus_UInt32  pllvcpu_cs_2:2;
        RBus_UInt32  pllvcpu_wdrst_2:1;
        RBus_UInt32  pllvcpu_wdset_2:1;
        RBus_UInt32  pllvcpu_o_2:2;
        RBus_UInt32  pllvcpu_ip_2:3;
        RBus_UInt32  pllvcpu_m_2:8;
        RBus_UInt32  pllvcpu_n_2:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllvcpu_tst_2:1;
        RBus_UInt32  res2:7;
    };
}pll_reg_sys_pll_vcpu2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_pow_2:1;
        RBus_UInt32  pllvcpu_rstb_2:1;
        RBus_UInt32  pllvcpu_oeb_2:1;
        RBus_UInt32  res1:29;
    };
}pll_reg_sys_pll_vcpu2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_lpf_rs:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllbus_pdiv:2;
        RBus_UInt32  pllbus_pdiv_bps:1;
        RBus_UInt32  pllbus_dbug_en:1;
        RBus_UInt32  pllbus_icp:4;
        RBus_UInt32  pllbus_sel_cco:1;
        RBus_UInt32  pllbus_testsel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_lpf_cs:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_wdrst:1;
        RBus_UInt32  pllbus_wdset:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  res5:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:2;
        RBus_UInt32  res8:2;
    };
}pll_reg_sys_pll_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pow:1;
        RBus_UInt32  pllbus_rstb:1;
        RBus_UInt32  pllbus_oeb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllbus_ncode:8;
        RBus_UInt32  pllbus_fcode:11;
        RBus_UInt32  res3:5;
    };
}pll_reg_sys_pll_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_oc_en:1;
        RBus_UInt32  pllbus_oc_done:1;
        RBus_UInt32  pllbus_sdm_order:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllbus_oc_step:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_oc_done_delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_sel_oc_mode:2;
        RBus_UInt32  pllbus_pi_cur_sel:2;
        RBus_UInt32  pllbus_hs_oc_stop:2;
        RBus_UInt32  pllbus_en_pi_debug:1;
        RBus_UInt32  pllbus_bypass_pi:1;
    };
}pll_reg_sys_dvfs_bus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_ncode_dbg:8;
        RBus_UInt32  pllbus_fcode_dbg:11;
        RBus_UInt32  res2:5;
    };
}pll_reg_sys_dvfs_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_lpf_rs_h:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllbus_pdiv_h:2;
        RBus_UInt32  pllbus_pdiv_bps_h:1;
        RBus_UInt32  pllbus_dbug_en_h:1;
        RBus_UInt32  pllbus_icp_h:4;
        RBus_UInt32  pllbus_sel_cco_h:1;
        RBus_UInt32  pllbus_testsel_h:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_lpf_cs_h:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_wdrst_h:1;
        RBus_UInt32  pllbus_wdset_h:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  res5:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:2;
        RBus_UInt32  res8:2;
    };
}pll_reg_sys_pll_bush1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pow_h:1;
        RBus_UInt32  pllbus_rstb_h:1;
        RBus_UInt32  pllbus_oeb_h:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllbus_ncode_h:8;
        RBus_UInt32  pllbus_fcode_h:11;
        RBus_UInt32  res3:5;
    };
}pll_reg_sys_pll_bush2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_oc_en_h:1;
        RBus_UInt32  pllbus_oc_done_h:1;
        RBus_UInt32  pllbus_sdm_order_h:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllbus_oc_step_h:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_oc_done_delay_h:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_sel_oc_mode_h:2;
        RBus_UInt32  pllbus_pi_cur_sel_h:2;
        RBus_UInt32  pllbus_hs_oc_stop_h:2;
        RBus_UInt32  pllbus_en_pi_debug_h:1;
        RBus_UInt32  pllbus_bypass_pi_h:1;
    };
}pll_reg_sys_dvfs_bush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_ncode_dbg_h:8;
        RBus_UInt32  pllbus_fcode_dbg_h:11;
        RBus_UInt32  res2:5;
    };
}pll_reg_sys_dvfs_bush2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_lpf_rs:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllgpu_pdiv:2;
        RBus_UInt32  pllgpu_pdiv_bps:1;
        RBus_UInt32  pllgpu_dbug_en:1;
        RBus_UInt32  pllgpu_icp:4;
        RBus_UInt32  pllgpu_sel_cco:1;
        RBus_UInt32  pllgpu_testsel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllgpu_lpf_cs:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllgpu_wdrst:1;
        RBus_UInt32  pllgpu_wdset:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  res5:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:2;
        RBus_UInt32  res8:2;
    };
}pll_reg_sys_pll_gpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_pow:1;
        RBus_UInt32  pllgpu_rstb:1;
        RBus_UInt32  pllgpu_oeb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllgpu_ncode:8;
        RBus_UInt32  pllgpu_fcode:11;
        RBus_UInt32  res3:5;
    };
}pll_reg_sys_pll_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_oc_en:1;
        RBus_UInt32  pllgpu_oc_done:1;
        RBus_UInt32  pllgpu_sdm_order:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllgpu_oc_step:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllgpu_oc_done_delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllgpu_sel_oc_mode:2;
        RBus_UInt32  pllgpu_pi_cur_sel:2;
        RBus_UInt32  pllgpu_hs_oc_stop:2;
        RBus_UInt32  pllgpu_en_pi_debug:1;
        RBus_UInt32  pllgpu_bypass_pi:1;
    };
}pll_reg_sys_dvfs_gpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllgpu_ncode_dbg:8;
        RBus_UInt32  pllgpu_fcode_dbg:11;
        RBus_UInt32  res2:5;
    };
}pll_reg_sys_dvfs_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvodma_rs:3;
        RBus_UInt32  pllvodma_cs:2;
        RBus_UInt32  pllvodma_wdrst:1;
        RBus_UInt32  pllvodma_wdset:1;
        RBus_UInt32  pllvodma_o:2;
        RBus_UInt32  pllvodma_ip:3;
        RBus_UInt32  pllvodma_m:8;
        RBus_UInt32  pllvodma_n:2;
        RBus_UInt32  res1:10;
    };
}pll_reg_sys_pll_vodma1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvodma_pow:1;
        RBus_UInt32  pllvodma_rstb:1;
        RBus_UInt32  pllvodma_oeb:1;
        RBus_UInt32  pllvodma_tst:1;
        RBus_UInt32  res1:28;
    };
}pll_reg_sys_pll_vodma2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbustst_sel:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbustst_div:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_reg:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_reser:8;
        RBus_UInt32  res4:8;
    };
}pll_reg_sys_pllbus_tst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_wdmode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllddsa_o:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  pllddsa_cp:2;
        RBus_UInt32  pllddsa_cs:2;
        RBus_UInt32  pllddsa_rs:3;
        RBus_UInt32  pllddsa_ip:4;
        RBus_UInt32  res4:6;
        RBus_UInt32  pllddsa_n:2;
    };
}pll_reg_sys_pll_dispa_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_pow:1;
        RBus_UInt32  pllddsa_rstb:1;
        RBus_UInt32  pllddsa_oeb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllddsa_ncode:8;
        RBus_UInt32  pllddsa_fcode:11;
        RBus_UInt32  res3:5;
    };
}pll_reg_sys_pll_dispa_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dummy18000478_10_10:1;
        RBus_UInt32  pllddsa_pstst:1;
        RBus_UInt32  pllddsa_tst:1;
        RBus_UInt32  dummy18000478_13_13:1;
        RBus_UInt32  pllddsa_vcorb:1;
        RBus_UInt32  dummy18000478_15_15:1;
        RBus_UInt32  dummy18000478_16_16:1;
        RBus_UInt32  dummy18000478_17_17:1;
        RBus_UInt32  dummy18000478_18_18:1;
        RBus_UInt32  dummy18000478_19_19:1;
        RBus_UInt32  dummy18000478_20_20:1;
        RBus_UInt32  dummy18000478_21_21:1;
        RBus_UInt32  dummy18000478_22_22:1;
        RBus_UInt32  dummy18000478_23_23:1;
        RBus_UInt32  dummy18000478_24_24:1;
        RBus_UInt32  dummy18000478_28_25:4;
        RBus_UInt32  res2:3;
    };
}pll_reg_sys_pll_dispa_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud2a_rstb:1;
        RBus_UInt32  psaud2a_oeb:1;
        RBus_UInt32  psaud1a_rstb:1;
        RBus_UInt32  psaud1a_oeb:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  psaud2a_psen:1;
        RBus_UInt32  psaud2a_tst:1;
        RBus_UInt32  psaud2a_div:1;
        RBus_UInt32  psaud2a_fupdn:1;
        RBus_UInt32  dummy1800047c_24:1;
        RBus_UInt32  psaud1a_psen:1;
        RBus_UInt32  psaud1a_tst:1;
        RBus_UInt32  dummy1800047c_27:1;
        RBus_UInt32  psaud1a_div:1;
        RBus_UInt32  psaud1a_fupdn:1;
        RBus_UInt32  dummy1800047c_30:1;
        RBus_UInt32  res2:1;
    };
}pll_reg_sys_pll_dispa_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_oc_en:1;
        RBus_UInt32  pllddsa_oc_done:1;
        RBus_UInt32  pllddsa_sdm_order:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllddsa_oc_step:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllddsa_oc_done_delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllddsa_sel_oc_mode:2;
        RBus_UInt32  pllddsa_pi_cur_sel:2;
        RBus_UInt32  pllddsa_hs_oc_stop:2;
        RBus_UInt32  pllddsa_en_pi_debug:1;
        RBus_UInt32  pllddsa_bypass_pi:1;
    };
}pll_reg_sys_dvfs_ddsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllddsa_ncode_dbg:8;
        RBus_UInt32  pllddsa_fcode_dbg:11;
        RBus_UInt32  res2:5;
    };
}pll_reg_sys_dvfs_ddsa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su:1;
        RBus_UInt32  sd:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  swcs:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  psc:1;
        RBus_UInt32  tmps:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tme:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  swsce:1;
        RBus_UInt32  res5:6;
    };
}pll_reg_ai_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_2:1;
        RBus_UInt32  sd_2:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  swcs_2:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  psc_2:1;
        RBus_UInt32  tmps_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tme_2:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  swsce_2:1;
        RBus_UInt32  res5:6;
    };
}pll_reg_ai2_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pllacpu_wdout:1;
        RBus_UInt32  pllvcpu_wdout:1;
        RBus_UInt32  pllddsa_wdout:1;
        RBus_UInt32  pllvcpu2_wdout:1;
        RBus_UInt32  plldisp_wdout:1;
        RBus_UInt32  pllbus_wdout:1;
        RBus_UInt32  pllvby1_wdout:1;
        RBus_UInt32  pllddsb_wdout:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldif_wdout:1;
        RBus_UInt32  pllgpu_wdout:1;
        RBus_UInt32  pllbush_wdout:1;
        RBus_UInt32  pll512fs_wdout:1;
        RBus_UInt32  pllaud_status:1;
        RBus_UInt32  pll512fs_wdout_1:1;
        RBus_UInt32  pllkcpu_wdout:1;
        RBus_UInt32  pllvodma_wdout:1;
        RBus_UInt32  pll27x_wdout:1;
        RBus_UInt32  pllifadc_wdout:1;
        RBus_UInt32  res3:12;
    };
}pll_reg_sys_pll_wd_out_RBUS;




#endif 


#endif 
