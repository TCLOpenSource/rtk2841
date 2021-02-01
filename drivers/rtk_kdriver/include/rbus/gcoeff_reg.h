/**
* @file Mac5_VE_GCOEFF_Arch_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_GCOEFF_REG_H_
#define _RBUS_GCOEFF_REG_H_

#include "rbus_types.h"



//  GCOEFF Register Address
#define  GCOEFF_CTRL                                                             0x1800F800
#define  GCOEFF_CTRL_reg_addr                                                    "0xB800F800"
#define  GCOEFF_CTRL_reg                                                         0xB800F800
#define  GCOEFF_CTRL_inst_addr                                                   "0x0000"
#define  set_GCOEFF_CTRL_reg(data)                                               (*((volatile unsigned int*)GCOEFF_CTRL_reg)=data)
#define  get_GCOEFF_CTRL_reg                                                     (*((volatile unsigned int*)GCOEFF_CTRL_reg))
#define  GCOEFF_CTRL_write_enable14_shift                                        (25)
#define  GCOEFF_CTRL_ipmdoff_shift                                               (24)
#define  GCOEFF_CTRL_write_enable13_shift                                        (23)
#define  GCOEFF_CTRL_sideband_enable_shift                                       (22)
#define  GCOEFF_CTRL_write_enable12_shift                                        (21)
#define  GCOEFF_CTRL_luma16x8_xform_sel_shift                                    (20)
#define  GCOEFF_CTRL_write_enable11_shift                                        (19)
#define  GCOEFF_CTRL_luma8x16_xform_sel_shift                                    (18)
#define  GCOEFF_CTRL_write_enable10_shift                                        (17)
#define  GCOEFF_CTRL_flush_cmd_disable_shift                                     (16)
#define  GCOEFF_CTRL_write_enable9_shift                                         (15)
#define  GCOEFF_CTRL_softrst_disable_shift                                       (14)
#define  GCOEFF_CTRL_write_enable7_shift                                         (13)
#define  GCOEFF_CTRL_trmem_dv_load_shift                                         (12)
#define  GCOEFF_CTRL_write_enable6_shift                                         (11)
#define  GCOEFF_CTRL_umem_bypass_shift                                           (10)
#define  GCOEFF_CTRL_write_enable5_shift                                         (9)
#define  GCOEFF_CTRL_luma16x16_xform_sel_shift                                   (8)
#define  GCOEFF_CTRL_write_enable4_shift                                         (7)
#define  GCOEFF_CTRL_luma8x8_xform_sel_shift                                     (6)
#define  GCOEFF_CTRL_write_enable3_shift                                         (5)
#define  GCOEFF_CTRL_constr_intra_pred_shift                                     (4)
#define  GCOEFF_CTRL_write_enable2_shift                                         (3)
#define  GCOEFF_CTRL_wdone_enable_shift                                          (2)
#define  GCOEFF_CTRL_write_enable1_shift                                         (1)
#define  GCOEFF_CTRL_sreset_busy_clr_shift                                       (0)
#define  GCOEFF_CTRL_write_enable14_mask                                         (0x02000000)
#define  GCOEFF_CTRL_ipmdoff_mask                                                (0x01000000)
#define  GCOEFF_CTRL_write_enable13_mask                                         (0x00800000)
#define  GCOEFF_CTRL_sideband_enable_mask                                        (0x00400000)
#define  GCOEFF_CTRL_write_enable12_mask                                         (0x00200000)
#define  GCOEFF_CTRL_luma16x8_xform_sel_mask                                     (0x00100000)
#define  GCOEFF_CTRL_write_enable11_mask                                         (0x00080000)
#define  GCOEFF_CTRL_luma8x16_xform_sel_mask                                     (0x00040000)
#define  GCOEFF_CTRL_write_enable10_mask                                         (0x00020000)
#define  GCOEFF_CTRL_flush_cmd_disable_mask                                      (0x00010000)
#define  GCOEFF_CTRL_write_enable9_mask                                          (0x00008000)
#define  GCOEFF_CTRL_softrst_disable_mask                                        (0x00004000)
#define  GCOEFF_CTRL_write_enable7_mask                                          (0x00002000)
#define  GCOEFF_CTRL_trmem_dv_load_mask                                          (0x00001000)
#define  GCOEFF_CTRL_write_enable6_mask                                          (0x00000800)
#define  GCOEFF_CTRL_umem_bypass_mask                                            (0x00000400)
#define  GCOEFF_CTRL_write_enable5_mask                                          (0x00000200)
#define  GCOEFF_CTRL_luma16x16_xform_sel_mask                                    (0x00000100)
#define  GCOEFF_CTRL_write_enable4_mask                                          (0x00000080)
#define  GCOEFF_CTRL_luma8x8_xform_sel_mask                                      (0x00000040)
#define  GCOEFF_CTRL_write_enable3_mask                                          (0x00000020)
#define  GCOEFF_CTRL_constr_intra_pred_mask                                      (0x00000010)
#define  GCOEFF_CTRL_write_enable2_mask                                          (0x00000008)
#define  GCOEFF_CTRL_wdone_enable_mask                                           (0x00000004)
#define  GCOEFF_CTRL_write_enable1_mask                                          (0x00000002)
#define  GCOEFF_CTRL_sreset_busy_clr_mask                                        (0x00000001)
#define  GCOEFF_CTRL_write_enable14(data)                                        (0x02000000&((data)<<25))
#define  GCOEFF_CTRL_ipmdoff(data)                                               (0x01000000&((data)<<24))
#define  GCOEFF_CTRL_write_enable13(data)                                        (0x00800000&((data)<<23))
#define  GCOEFF_CTRL_sideband_enable(data)                                       (0x00400000&((data)<<22))
#define  GCOEFF_CTRL_write_enable12(data)                                        (0x00200000&((data)<<21))
#define  GCOEFF_CTRL_luma16x8_xform_sel(data)                                    (0x00100000&((data)<<20))
#define  GCOEFF_CTRL_write_enable11(data)                                        (0x00080000&((data)<<19))
#define  GCOEFF_CTRL_luma8x16_xform_sel(data)                                    (0x00040000&((data)<<18))
#define  GCOEFF_CTRL_write_enable10(data)                                        (0x00020000&((data)<<17))
#define  GCOEFF_CTRL_flush_cmd_disable(data)                                     (0x00010000&((data)<<16))
#define  GCOEFF_CTRL_write_enable9(data)                                         (0x00008000&((data)<<15))
#define  GCOEFF_CTRL_softrst_disable(data)                                       (0x00004000&((data)<<14))
#define  GCOEFF_CTRL_write_enable7(data)                                         (0x00002000&((data)<<13))
#define  GCOEFF_CTRL_trmem_dv_load(data)                                         (0x00001000&((data)<<12))
#define  GCOEFF_CTRL_write_enable6(data)                                         (0x00000800&((data)<<11))
#define  GCOEFF_CTRL_umem_bypass(data)                                           (0x00000400&((data)<<10))
#define  GCOEFF_CTRL_write_enable5(data)                                         (0x00000200&((data)<<9))
#define  GCOEFF_CTRL_luma16x16_xform_sel(data)                                   (0x00000100&((data)<<8))
#define  GCOEFF_CTRL_write_enable4(data)                                         (0x00000080&((data)<<7))
#define  GCOEFF_CTRL_luma8x8_xform_sel(data)                                     (0x00000040&((data)<<6))
#define  GCOEFF_CTRL_write_enable3(data)                                         (0x00000020&((data)<<5))
#define  GCOEFF_CTRL_constr_intra_pred(data)                                     (0x00000010&((data)<<4))
#define  GCOEFF_CTRL_write_enable2(data)                                         (0x00000008&((data)<<3))
#define  GCOEFF_CTRL_wdone_enable(data)                                          (0x00000004&((data)<<2))
#define  GCOEFF_CTRL_write_enable1(data)                                         (0x00000002&((data)<<1))
#define  GCOEFF_CTRL_sreset_busy_clr(data)                                       (0x00000001&(data))
#define  GCOEFF_CTRL_get_write_enable14(data)                                    ((0x02000000&(data))>>25)
#define  GCOEFF_CTRL_get_ipmdoff(data)                                           ((0x01000000&(data))>>24)
#define  GCOEFF_CTRL_get_write_enable13(data)                                    ((0x00800000&(data))>>23)
#define  GCOEFF_CTRL_get_sideband_enable(data)                                   ((0x00400000&(data))>>22)
#define  GCOEFF_CTRL_get_write_enable12(data)                                    ((0x00200000&(data))>>21)
#define  GCOEFF_CTRL_get_luma16x8_xform_sel(data)                                ((0x00100000&(data))>>20)
#define  GCOEFF_CTRL_get_write_enable11(data)                                    ((0x00080000&(data))>>19)
#define  GCOEFF_CTRL_get_luma8x16_xform_sel(data)                                ((0x00040000&(data))>>18)
#define  GCOEFF_CTRL_get_write_enable10(data)                                    ((0x00020000&(data))>>17)
#define  GCOEFF_CTRL_get_flush_cmd_disable(data)                                 ((0x00010000&(data))>>16)
#define  GCOEFF_CTRL_get_write_enable9(data)                                     ((0x00008000&(data))>>15)
#define  GCOEFF_CTRL_get_softrst_disable(data)                                   ((0x00004000&(data))>>14)
#define  GCOEFF_CTRL_get_write_enable7(data)                                     ((0x00002000&(data))>>13)
#define  GCOEFF_CTRL_get_trmem_dv_load(data)                                     ((0x00001000&(data))>>12)
#define  GCOEFF_CTRL_get_write_enable6(data)                                     ((0x00000800&(data))>>11)
#define  GCOEFF_CTRL_get_umem_bypass(data)                                       ((0x00000400&(data))>>10)
#define  GCOEFF_CTRL_get_write_enable5(data)                                     ((0x00000200&(data))>>9)
#define  GCOEFF_CTRL_get_luma16x16_xform_sel(data)                               ((0x00000100&(data))>>8)
#define  GCOEFF_CTRL_get_write_enable4(data)                                     ((0x00000080&(data))>>7)
#define  GCOEFF_CTRL_get_luma8x8_xform_sel(data)                                 ((0x00000040&(data))>>6)
#define  GCOEFF_CTRL_get_write_enable3(data)                                     ((0x00000020&(data))>>5)
#define  GCOEFF_CTRL_get_constr_intra_pred(data)                                 ((0x00000010&(data))>>4)
#define  GCOEFF_CTRL_get_write_enable2(data)                                     ((0x00000008&(data))>>3)
#define  GCOEFF_CTRL_get_wdone_enable(data)                                      ((0x00000004&(data))>>2)
#define  GCOEFF_CTRL_get_write_enable1(data)                                     ((0x00000002&(data))>>1)
#define  GCOEFF_CTRL_get_sreset_busy_clr(data)                                   (0x00000001&(data))

#define  GCOEFF_INTRA_0                                                          0x1800F804
#define  GCOEFF_INTRA_0_reg_addr                                                 "0xB800F804"
#define  GCOEFF_INTRA_0_reg                                                      0xB800F804
#define  GCOEFF_INTRA_0_inst_addr                                                "0x0001"
#define  set_GCOEFF_INTRA_0_reg(data)                                            (*((volatile unsigned int*)GCOEFF_INTRA_0_reg)=data)
#define  get_GCOEFF_INTRA_0_reg                                                  (*((volatile unsigned int*)GCOEFF_INTRA_0_reg))
#define  GCOEFF_INTRA_0_intra_flag_shift                                         (0)
#define  GCOEFF_INTRA_0_intra_flag_mask                                          (0xFFFFFFFF)
#define  GCOEFF_INTRA_0_intra_flag(data)                                         (0xFFFFFFFF&(data))
#define  GCOEFF_INTRA_0_get_intra_flag(data)                                     (0xFFFFFFFF&(data))

#define  GCOEFF_INTRA_1                                                          0x1800F808
#define  GCOEFF_INTRA_1_reg_addr                                                 "0xB800F808"
#define  GCOEFF_INTRA_1_reg                                                      0xB800F808
#define  GCOEFF_INTRA_1_inst_addr                                                "0x0002"
#define  set_GCOEFF_INTRA_1_reg(data)                                            (*((volatile unsigned int*)GCOEFF_INTRA_1_reg)=data)
#define  get_GCOEFF_INTRA_1_reg                                                  (*((volatile unsigned int*)GCOEFF_INTRA_1_reg))
#define  GCOEFF_INTRA_1_intra_flag_shift                                         (0)
#define  GCOEFF_INTRA_1_intra_flag_mask                                          (0xFFFFFFFF)
#define  GCOEFF_INTRA_1_intra_flag(data)                                         (0xFFFFFFFF&(data))
#define  GCOEFF_INTRA_1_get_intra_flag(data)                                     (0xFFFFFFFF&(data))

#define  GCOEFF_INTRA_2                                                          0x1800F80C
#define  GCOEFF_INTRA_2_reg_addr                                                 "0xB800F80C"
#define  GCOEFF_INTRA_2_reg                                                      0xB800F80C
#define  GCOEFF_INTRA_2_inst_addr                                                "0x0003"
#define  set_GCOEFF_INTRA_2_reg(data)                                            (*((volatile unsigned int*)GCOEFF_INTRA_2_reg)=data)
#define  get_GCOEFF_INTRA_2_reg                                                  (*((volatile unsigned int*)GCOEFF_INTRA_2_reg))
#define  GCOEFF_INTRA_2_intra_flag_shift                                         (0)
#define  GCOEFF_INTRA_2_intra_flag_mask                                          (0xFFFFFFFF)
#define  GCOEFF_INTRA_2_intra_flag(data)                                         (0xFFFFFFFF&(data))
#define  GCOEFF_INTRA_2_get_intra_flag(data)                                     (0xFFFFFFFF&(data))

#define  GCOEFF_INTRA_3                                                          0x1800F810
#define  GCOEFF_INTRA_3_reg_addr                                                 "0xB800F810"
#define  GCOEFF_INTRA_3_reg                                                      0xB800F810
#define  GCOEFF_INTRA_3_inst_addr                                                "0x0004"
#define  set_GCOEFF_INTRA_3_reg(data)                                            (*((volatile unsigned int*)GCOEFF_INTRA_3_reg)=data)
#define  get_GCOEFF_INTRA_3_reg                                                  (*((volatile unsigned int*)GCOEFF_INTRA_3_reg))
#define  GCOEFF_INTRA_3_intra_flag_shift                                         (0)
#define  GCOEFF_INTRA_3_intra_flag_mask                                          (0xFFFFFFFF)
#define  GCOEFF_INTRA_3_intra_flag(data)                                         (0xFFFFFFFF&(data))
#define  GCOEFF_INTRA_3_get_intra_flag(data)                                     (0xFFFFFFFF&(data))

#define  GCOEFF_CHMV_0                                                           0x1800F814
#define  GCOEFF_CHMV_0_reg_addr                                                  "0xB800F814"
#define  GCOEFF_CHMV_0_reg                                                       0xB800F814
#define  GCOEFF_CHMV_0_inst_addr                                                 "0x0005"
#define  set_GCOEFF_CHMV_0_reg(data)                                             (*((volatile unsigned int*)GCOEFF_CHMV_0_reg)=data)
#define  get_GCOEFF_CHMV_0_reg                                                   (*((volatile unsigned int*)GCOEFF_CHMV_0_reg))
#define  GCOEFF_CHMV_0_fmvx_shift                                                (16)
#define  GCOEFF_CHMV_0_fmvy_shift                                                (0)
#define  GCOEFF_CHMV_0_fmvx_mask                                                 (0x0FFF0000)
#define  GCOEFF_CHMV_0_fmvy_mask                                                 (0x000003FF)
#define  GCOEFF_CHMV_0_fmvx(data)                                                (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHMV_0_fmvy(data)                                                (0x000003FF&(data))
#define  GCOEFF_CHMV_0_get_fmvx(data)                                            ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHMV_0_get_fmvy(data)                                            (0x000003FF&(data))

#define  GCOEFF_CHMV_1                                                           0x1800F818
#define  GCOEFF_CHMV_1_reg_addr                                                  "0xB800F818"
#define  GCOEFF_CHMV_1_reg                                                       0xB800F818
#define  GCOEFF_CHMV_1_inst_addr                                                 "0x0006"
#define  set_GCOEFF_CHMV_1_reg(data)                                             (*((volatile unsigned int*)GCOEFF_CHMV_1_reg)=data)
#define  get_GCOEFF_CHMV_1_reg                                                   (*((volatile unsigned int*)GCOEFF_CHMV_1_reg))
#define  GCOEFF_CHMV_1_fmvx_shift                                                (16)
#define  GCOEFF_CHMV_1_fmvy_shift                                                (0)
#define  GCOEFF_CHMV_1_fmvx_mask                                                 (0x0FFF0000)
#define  GCOEFF_CHMV_1_fmvy_mask                                                 (0x000003FF)
#define  GCOEFF_CHMV_1_fmvx(data)                                                (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHMV_1_fmvy(data)                                                (0x000003FF&(data))
#define  GCOEFF_CHMV_1_get_fmvx(data)                                            ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHMV_1_get_fmvy(data)                                            (0x000003FF&(data))

#define  GCOEFF_CHMV_2                                                           0x1800F81C
#define  GCOEFF_CHMV_2_reg_addr                                                  "0xB800F81C"
#define  GCOEFF_CHMV_2_reg                                                       0xB800F81C
#define  GCOEFF_CHMV_2_inst_addr                                                 "0x0007"
#define  set_GCOEFF_CHMV_2_reg(data)                                             (*((volatile unsigned int*)GCOEFF_CHMV_2_reg)=data)
#define  get_GCOEFF_CHMV_2_reg                                                   (*((volatile unsigned int*)GCOEFF_CHMV_2_reg))
#define  GCOEFF_CHMV_2_fmvx_shift                                                (16)
#define  GCOEFF_CHMV_2_fmvy_shift                                                (0)
#define  GCOEFF_CHMV_2_fmvx_mask                                                 (0x0FFF0000)
#define  GCOEFF_CHMV_2_fmvy_mask                                                 (0x000003FF)
#define  GCOEFF_CHMV_2_fmvx(data)                                                (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHMV_2_fmvy(data)                                                (0x000003FF&(data))
#define  GCOEFF_CHMV_2_get_fmvx(data)                                            ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHMV_2_get_fmvy(data)                                            (0x000003FF&(data))

#define  GCOEFF_CHMV_3                                                           0x1800F820
#define  GCOEFF_CHMV_3_reg_addr                                                  "0xB800F820"
#define  GCOEFF_CHMV_3_reg                                                       0xB800F820
#define  GCOEFF_CHMV_3_inst_addr                                                 "0x0008"
#define  set_GCOEFF_CHMV_3_reg(data)                                             (*((volatile unsigned int*)GCOEFF_CHMV_3_reg)=data)
#define  get_GCOEFF_CHMV_3_reg                                                   (*((volatile unsigned int*)GCOEFF_CHMV_3_reg))
#define  GCOEFF_CHMV_3_fmvx_shift                                                (16)
#define  GCOEFF_CHMV_3_fmvy_shift                                                (0)
#define  GCOEFF_CHMV_3_fmvx_mask                                                 (0x0FFF0000)
#define  GCOEFF_CHMV_3_fmvy_mask                                                 (0x000003FF)
#define  GCOEFF_CHMV_3_fmvx(data)                                                (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHMV_3_fmvy(data)                                                (0x000003FF&(data))
#define  GCOEFF_CHMV_3_get_fmvx(data)                                            ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHMV_3_get_fmvy(data)                                            (0x000003FF&(data))

#define  GCOEFF_CHBMV_0                                                          0x1800F824
#define  GCOEFF_CHBMV_0_reg_addr                                                 "0xB800F824"
#define  GCOEFF_CHBMV_0_reg                                                      0xB800F824
#define  GCOEFF_CHBMV_0_inst_addr                                                "0x0009"
#define  set_GCOEFF_CHBMV_0_reg(data)                                            (*((volatile unsigned int*)GCOEFF_CHBMV_0_reg)=data)
#define  get_GCOEFF_CHBMV_0_reg                                                  (*((volatile unsigned int*)GCOEFF_CHBMV_0_reg))
#define  GCOEFF_CHBMV_0_fmvx_shift                                               (16)
#define  GCOEFF_CHBMV_0_fmvy_shift                                               (0)
#define  GCOEFF_CHBMV_0_fmvx_mask                                                (0x0FFF0000)
#define  GCOEFF_CHBMV_0_fmvy_mask                                                (0x000003FF)
#define  GCOEFF_CHBMV_0_fmvx(data)                                               (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHBMV_0_fmvy(data)                                               (0x000003FF&(data))
#define  GCOEFF_CHBMV_0_get_fmvx(data)                                           ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHBMV_0_get_fmvy(data)                                           (0x000003FF&(data))

#define  GCOEFF_CHBMV_1                                                          0x1800F828
#define  GCOEFF_CHBMV_1_reg_addr                                                 "0xB800F828"
#define  GCOEFF_CHBMV_1_reg                                                      0xB800F828
#define  GCOEFF_CHBMV_1_inst_addr                                                "0x000A"
#define  set_GCOEFF_CHBMV_1_reg(data)                                            (*((volatile unsigned int*)GCOEFF_CHBMV_1_reg)=data)
#define  get_GCOEFF_CHBMV_1_reg                                                  (*((volatile unsigned int*)GCOEFF_CHBMV_1_reg))
#define  GCOEFF_CHBMV_1_fmvx_shift                                               (16)
#define  GCOEFF_CHBMV_1_fmvy_shift                                               (0)
#define  GCOEFF_CHBMV_1_fmvx_mask                                                (0x0FFF0000)
#define  GCOEFF_CHBMV_1_fmvy_mask                                                (0x000003FF)
#define  GCOEFF_CHBMV_1_fmvx(data)                                               (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHBMV_1_fmvy(data)                                               (0x000003FF&(data))
#define  GCOEFF_CHBMV_1_get_fmvx(data)                                           ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHBMV_1_get_fmvy(data)                                           (0x000003FF&(data))

#define  GCOEFF_CHBMV_2                                                          0x1800F82C
#define  GCOEFF_CHBMV_2_reg_addr                                                 "0xB800F82C"
#define  GCOEFF_CHBMV_2_reg                                                      0xB800F82C
#define  GCOEFF_CHBMV_2_inst_addr                                                "0x000B"
#define  set_GCOEFF_CHBMV_2_reg(data)                                            (*((volatile unsigned int*)GCOEFF_CHBMV_2_reg)=data)
#define  get_GCOEFF_CHBMV_2_reg                                                  (*((volatile unsigned int*)GCOEFF_CHBMV_2_reg))
#define  GCOEFF_CHBMV_2_fmvx_shift                                               (16)
#define  GCOEFF_CHBMV_2_fmvy_shift                                               (0)
#define  GCOEFF_CHBMV_2_fmvx_mask                                                (0x0FFF0000)
#define  GCOEFF_CHBMV_2_fmvy_mask                                                (0x000003FF)
#define  GCOEFF_CHBMV_2_fmvx(data)                                               (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHBMV_2_fmvy(data)                                               (0x000003FF&(data))
#define  GCOEFF_CHBMV_2_get_fmvx(data)                                           ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHBMV_2_get_fmvy(data)                                           (0x000003FF&(data))

#define  GCOEFF_CHBMV_3                                                          0x1800F830
#define  GCOEFF_CHBMV_3_reg_addr                                                 "0xB800F830"
#define  GCOEFF_CHBMV_3_reg                                                      0xB800F830
#define  GCOEFF_CHBMV_3_inst_addr                                                "0x000C"
#define  set_GCOEFF_CHBMV_3_reg(data)                                            (*((volatile unsigned int*)GCOEFF_CHBMV_3_reg)=data)
#define  get_GCOEFF_CHBMV_3_reg                                                  (*((volatile unsigned int*)GCOEFF_CHBMV_3_reg))
#define  GCOEFF_CHBMV_3_fmvx_shift                                               (16)
#define  GCOEFF_CHBMV_3_fmvy_shift                                               (0)
#define  GCOEFF_CHBMV_3_fmvx_mask                                                (0x0FFF0000)
#define  GCOEFF_CHBMV_3_fmvy_mask                                                (0x000003FF)
#define  GCOEFF_CHBMV_3_fmvx(data)                                               (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHBMV_3_fmvy(data)                                               (0x000003FF&(data))
#define  GCOEFF_CHBMV_3_get_fmvx(data)                                           ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHBMV_3_get_fmvy(data)                                           (0x000003FF&(data))

#define  GCOEFF_CHMVD_0                                                          0x1800F904
#define  GCOEFF_CHMVD_0_reg_addr                                                 "0xB800F904"
#define  GCOEFF_CHMVD_0_reg                                                      0xB800F904
#define  GCOEFF_CHMVD_0_inst_addr                                                "0x000D"
#define  set_GCOEFF_CHMVD_0_reg(data)                                            (*((volatile unsigned int*)GCOEFF_CHMVD_0_reg)=data)
#define  get_GCOEFF_CHMVD_0_reg                                                  (*((volatile unsigned int*)GCOEFF_CHMVD_0_reg))
#define  GCOEFF_CHMVD_0_fmvx_shift                                               (16)
#define  GCOEFF_CHMVD_0_fmvy_shift                                               (0)
#define  GCOEFF_CHMVD_0_fmvx_mask                                                (0x0FFF0000)
#define  GCOEFF_CHMVD_0_fmvy_mask                                                (0x000003FF)
#define  GCOEFF_CHMVD_0_fmvx(data)                                               (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHMVD_0_fmvy(data)                                               (0x000003FF&(data))
#define  GCOEFF_CHMVD_0_get_fmvx(data)                                           ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHMVD_0_get_fmvy(data)                                           (0x000003FF&(data))

#define  GCOEFF_CHMVD_1                                                          0x1800F908
#define  GCOEFF_CHMVD_1_reg_addr                                                 "0xB800F908"
#define  GCOEFF_CHMVD_1_reg                                                      0xB800F908
#define  GCOEFF_CHMVD_1_inst_addr                                                "0x000E"
#define  set_GCOEFF_CHMVD_1_reg(data)                                            (*((volatile unsigned int*)GCOEFF_CHMVD_1_reg)=data)
#define  get_GCOEFF_CHMVD_1_reg                                                  (*((volatile unsigned int*)GCOEFF_CHMVD_1_reg))
#define  GCOEFF_CHMVD_1_fmvx_shift                                               (16)
#define  GCOEFF_CHMVD_1_fmvy_shift                                               (0)
#define  GCOEFF_CHMVD_1_fmvx_mask                                                (0x0FFF0000)
#define  GCOEFF_CHMVD_1_fmvy_mask                                                (0x000003FF)
#define  GCOEFF_CHMVD_1_fmvx(data)                                               (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHMVD_1_fmvy(data)                                               (0x000003FF&(data))
#define  GCOEFF_CHMVD_1_get_fmvx(data)                                           ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHMVD_1_get_fmvy(data)                                           (0x000003FF&(data))

#define  GCOEFF_CHMVD_2                                                          0x1800F90C
#define  GCOEFF_CHMVD_2_reg_addr                                                 "0xB800F90C"
#define  GCOEFF_CHMVD_2_reg                                                      0xB800F90C
#define  GCOEFF_CHMVD_2_inst_addr                                                "0x000F"
#define  set_GCOEFF_CHMVD_2_reg(data)                                            (*((volatile unsigned int*)GCOEFF_CHMVD_2_reg)=data)
#define  get_GCOEFF_CHMVD_2_reg                                                  (*((volatile unsigned int*)GCOEFF_CHMVD_2_reg))
#define  GCOEFF_CHMVD_2_fmvx_shift                                               (16)
#define  GCOEFF_CHMVD_2_fmvy_shift                                               (0)
#define  GCOEFF_CHMVD_2_fmvx_mask                                                (0x0FFF0000)
#define  GCOEFF_CHMVD_2_fmvy_mask                                                (0x000003FF)
#define  GCOEFF_CHMVD_2_fmvx(data)                                               (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHMVD_2_fmvy(data)                                               (0x000003FF&(data))
#define  GCOEFF_CHMVD_2_get_fmvx(data)                                           ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHMVD_2_get_fmvy(data)                                           (0x000003FF&(data))

#define  GCOEFF_CHMVD_3                                                          0x1800F910
#define  GCOEFF_CHMVD_3_reg_addr                                                 "0xB800F910"
#define  GCOEFF_CHMVD_3_reg                                                      0xB800F910
#define  GCOEFF_CHMVD_3_inst_addr                                                "0x0010"
#define  set_GCOEFF_CHMVD_3_reg(data)                                            (*((volatile unsigned int*)GCOEFF_CHMVD_3_reg)=data)
#define  get_GCOEFF_CHMVD_3_reg                                                  (*((volatile unsigned int*)GCOEFF_CHMVD_3_reg))
#define  GCOEFF_CHMVD_3_fmvx_shift                                               (16)
#define  GCOEFF_CHMVD_3_fmvy_shift                                               (0)
#define  GCOEFF_CHMVD_3_fmvx_mask                                                (0x0FFF0000)
#define  GCOEFF_CHMVD_3_fmvy_mask                                                (0x000003FF)
#define  GCOEFF_CHMVD_3_fmvx(data)                                               (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHMVD_3_fmvy(data)                                               (0x000003FF&(data))
#define  GCOEFF_CHMVD_3_get_fmvx(data)                                           ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHMVD_3_get_fmvy(data)                                           (0x000003FF&(data))

#define  GCOEFF_CHBMVD_0                                                         0x1800F914
#define  GCOEFF_CHBMVD_0_reg_addr                                                "0xB800F914"
#define  GCOEFF_CHBMVD_0_reg                                                     0xB800F914
#define  GCOEFF_CHBMVD_0_inst_addr                                               "0x0011"
#define  set_GCOEFF_CHBMVD_0_reg(data)                                           (*((volatile unsigned int*)GCOEFF_CHBMVD_0_reg)=data)
#define  get_GCOEFF_CHBMVD_0_reg                                                 (*((volatile unsigned int*)GCOEFF_CHBMVD_0_reg))
#define  GCOEFF_CHBMVD_0_fmvx_shift                                              (16)
#define  GCOEFF_CHBMVD_0_fmvy_shift                                              (0)
#define  GCOEFF_CHBMVD_0_fmvx_mask                                               (0x0FFF0000)
#define  GCOEFF_CHBMVD_0_fmvy_mask                                               (0x000003FF)
#define  GCOEFF_CHBMVD_0_fmvx(data)                                              (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHBMVD_0_fmvy(data)                                              (0x000003FF&(data))
#define  GCOEFF_CHBMVD_0_get_fmvx(data)                                          ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHBMVD_0_get_fmvy(data)                                          (0x000003FF&(data))

#define  GCOEFF_CHBMVD_1                                                         0x1800F918
#define  GCOEFF_CHBMVD_1_reg_addr                                                "0xB800F918"
#define  GCOEFF_CHBMVD_1_reg                                                     0xB800F918
#define  GCOEFF_CHBMVD_1_inst_addr                                               "0x0012"
#define  set_GCOEFF_CHBMVD_1_reg(data)                                           (*((volatile unsigned int*)GCOEFF_CHBMVD_1_reg)=data)
#define  get_GCOEFF_CHBMVD_1_reg                                                 (*((volatile unsigned int*)GCOEFF_CHBMVD_1_reg))
#define  GCOEFF_CHBMVD_1_fmvx_shift                                              (16)
#define  GCOEFF_CHBMVD_1_fmvy_shift                                              (0)
#define  GCOEFF_CHBMVD_1_fmvx_mask                                               (0x0FFF0000)
#define  GCOEFF_CHBMVD_1_fmvy_mask                                               (0x000003FF)
#define  GCOEFF_CHBMVD_1_fmvx(data)                                              (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHBMVD_1_fmvy(data)                                              (0x000003FF&(data))
#define  GCOEFF_CHBMVD_1_get_fmvx(data)                                          ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHBMVD_1_get_fmvy(data)                                          (0x000003FF&(data))

#define  GCOEFF_CHBMVD_2                                                         0x1800F91C
#define  GCOEFF_CHBMVD_2_reg_addr                                                "0xB800F91C"
#define  GCOEFF_CHBMVD_2_reg                                                     0xB800F91C
#define  GCOEFF_CHBMVD_2_inst_addr                                               "0x0013"
#define  set_GCOEFF_CHBMVD_2_reg(data)                                           (*((volatile unsigned int*)GCOEFF_CHBMVD_2_reg)=data)
#define  get_GCOEFF_CHBMVD_2_reg                                                 (*((volatile unsigned int*)GCOEFF_CHBMVD_2_reg))
#define  GCOEFF_CHBMVD_2_fmvx_shift                                              (16)
#define  GCOEFF_CHBMVD_2_fmvy_shift                                              (0)
#define  GCOEFF_CHBMVD_2_fmvx_mask                                               (0x0FFF0000)
#define  GCOEFF_CHBMVD_2_fmvy_mask                                               (0x000003FF)
#define  GCOEFF_CHBMVD_2_fmvx(data)                                              (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHBMVD_2_fmvy(data)                                              (0x000003FF&(data))
#define  GCOEFF_CHBMVD_2_get_fmvx(data)                                          ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHBMVD_2_get_fmvy(data)                                          (0x000003FF&(data))

#define  GCOEFF_CHBMVD_3                                                         0x1800F920
#define  GCOEFF_CHBMVD_3_reg_addr                                                "0xB800F920"
#define  GCOEFF_CHBMVD_3_reg                                                     0xB800F920
#define  GCOEFF_CHBMVD_3_inst_addr                                               "0x0014"
#define  set_GCOEFF_CHBMVD_3_reg(data)                                           (*((volatile unsigned int*)GCOEFF_CHBMVD_3_reg)=data)
#define  get_GCOEFF_CHBMVD_3_reg                                                 (*((volatile unsigned int*)GCOEFF_CHBMVD_3_reg))
#define  GCOEFF_CHBMVD_3_fmvx_shift                                              (16)
#define  GCOEFF_CHBMVD_3_fmvy_shift                                              (0)
#define  GCOEFF_CHBMVD_3_fmvx_mask                                               (0x0FFF0000)
#define  GCOEFF_CHBMVD_3_fmvy_mask                                               (0x000003FF)
#define  GCOEFF_CHBMVD_3_fmvx(data)                                              (0x0FFF0000&((data)<<16))
#define  GCOEFF_CHBMVD_3_fmvy(data)                                              (0x000003FF&(data))
#define  GCOEFF_CHBMVD_3_get_fmvx(data)                                          ((0x0FFF0000&(data))>>16)
#define  GCOEFF_CHBMVD_3_get_fmvy(data)                                          (0x000003FF&(data))

#define  GCOEFF_SDMAADR                                                          0x1800F834
#define  GCOEFF_SDMAADR_reg_addr                                                 "0xB800F834"
#define  GCOEFF_SDMAADR_reg                                                      0xB800F834
#define  GCOEFF_SDMAADR_inst_addr                                                "0x0015"
#define  set_GCOEFF_SDMAADR_reg(data)                                            (*((volatile unsigned int*)GCOEFF_SDMAADR_reg)=data)
#define  get_GCOEFF_SDMAADR_reg                                                  (*((volatile unsigned int*)GCOEFF_SDMAADR_reg))
#define  GCOEFF_SDMAADR_seq_line_addr_shift                                      (0)
#define  GCOEFF_SDMAADR_seq_line_addr_mask                                       (0x7FFFFFFF)
#define  GCOEFF_SDMAADR_seq_line_addr(data)                                      (0x7FFFFFFF&(data))
#define  GCOEFF_SDMAADR_get_seq_line_addr(data)                                  (0x7FFFFFFF&(data))

#define  GCOEFF_INTR_THRESH                                                      0x1800F838
#define  GCOEFF_INTR_THRESH_reg_addr                                             "0xB800F838"
#define  GCOEFF_INTR_THRESH_reg                                                  0xB800F838
#define  GCOEFF_INTR_THRESH_inst_addr                                            "0x0016"
#define  set_GCOEFF_INTR_THRESH_reg(data)                                        (*((volatile unsigned int*)GCOEFF_INTR_THRESH_reg)=data)
#define  get_GCOEFF_INTR_THRESH_reg                                              (*((volatile unsigned int*)GCOEFF_INTR_THRESH_reg))
#define  GCOEFF_INTR_THRESH_value_shift                                          (0)
#define  GCOEFF_INTR_THRESH_value_mask                                           (0x0FFFFFFF)
#define  GCOEFF_INTR_THRESH_value(data)                                          (0x0FFFFFFF&(data))
#define  GCOEFF_INTR_THRESH_get_value(data)                                      (0x0FFFFFFF&(data))

#define  GCOEFF_BUSY                                                             0x1800F83C
#define  GCOEFF_BUSY_reg_addr                                                    "0xB800F83C"
#define  GCOEFF_BUSY_reg                                                         0xB800F83C
#define  GCOEFF_BUSY_inst_addr                                                   "0x0017"
#define  set_GCOEFF_BUSY_reg(data)                                               (*((volatile unsigned int*)GCOEFF_BUSY_reg)=data)
#define  get_GCOEFF_BUSY_reg                                                     (*((volatile unsigned int*)GCOEFF_BUSY_reg))
#define  GCOEFF_BUSY_reach_thresh_shift                                          (28)
#define  GCOEFF_BUSY_count_shift                                                 (0)
#define  GCOEFF_BUSY_reach_thresh_mask                                           (0x10000000)
#define  GCOEFF_BUSY_count_mask                                                  (0x0FFFFFFF)
#define  GCOEFF_BUSY_reach_thresh(data)                                          (0x10000000&((data)<<28))
#define  GCOEFF_BUSY_count(data)                                                 (0x0FFFFFFF&(data))
#define  GCOEFF_BUSY_get_reach_thresh(data)                                      ((0x10000000&(data))>>28)
#define  GCOEFF_BUSY_get_count(data)                                             (0x0FFFFFFF&(data))

#define  GCOEFF_DBUS1                                                            0x1800F840
#define  GCOEFF_DBUS1_reg_addr                                                   "0xB800F840"
#define  GCOEFF_DBUS1_reg                                                        0xB800F840
#define  GCOEFF_DBUS1_inst_addr                                                  "0x0018"
#define  set_GCOEFF_DBUS1_reg(data)                                              (*((volatile unsigned int*)GCOEFF_DBUS1_reg)=data)
#define  get_GCOEFF_DBUS1_reg                                                    (*((volatile unsigned int*)GCOEFF_DBUS1_reg))
#define  GCOEFF_DBUS1_genpulse_shift                                             (31)
#define  GCOEFF_DBUS1_dbgctrl_shift                                              (28)
#define  GCOEFF_DBUS1_piccount_shift                                             (14)
#define  GCOEFF_DBUS1_mbaddrx_shift                                              (7)
#define  GCOEFF_DBUS1_mbaddry_shift                                              (0)
#define  GCOEFF_DBUS1_genpulse_mask                                              (0x80000000)
#define  GCOEFF_DBUS1_dbgctrl_mask                                               (0x70000000)
#define  GCOEFF_DBUS1_piccount_mask                                              (0x0FFFC000)
#define  GCOEFF_DBUS1_mbaddrx_mask                                               (0x00003F80)
#define  GCOEFF_DBUS1_mbaddry_mask                                               (0x0000007F)
#define  GCOEFF_DBUS1_genpulse(data)                                             (0x80000000&((data)<<31))
#define  GCOEFF_DBUS1_dbgctrl(data)                                              (0x70000000&((data)<<28))
#define  GCOEFF_DBUS1_piccount(data)                                             (0x0FFFC000&((data)<<14))
#define  GCOEFF_DBUS1_mbaddrx(data)                                              (0x00003F80&((data)<<7))
#define  GCOEFF_DBUS1_mbaddry(data)                                              (0x0000007F&(data))
#define  GCOEFF_DBUS1_get_genpulse(data)                                         ((0x80000000&(data))>>31)
#define  GCOEFF_DBUS1_get_dbgctrl(data)                                          ((0x70000000&(data))>>28)
#define  GCOEFF_DBUS1_get_piccount(data)                                         ((0x0FFFC000&(data))>>14)
#define  GCOEFF_DBUS1_get_mbaddrx(data)                                          ((0x00003F80&(data))>>7)
#define  GCOEFF_DBUS1_get_mbaddry(data)                                          (0x0000007F&(data))

#define  GCOEFF_DBUS2                                                            0x1800F844
#define  GCOEFF_DBUS2_reg_addr                                                   "0xB800F844"
#define  GCOEFF_DBUS2_reg                                                        0xB800F844
#define  GCOEFF_DBUS2_inst_addr                                                  "0x0019"
#define  set_GCOEFF_DBUS2_reg(data)                                              (*((volatile unsigned int*)GCOEFF_DBUS2_reg)=data)
#define  get_GCOEFF_DBUS2_reg                                                    (*((volatile unsigned int*)GCOEFF_DBUS2_reg))
#define  GCOEFF_DBUS2_dbgctrl_shift                                              (0)
#define  GCOEFF_DBUS2_dbgctrl_mask                                               (0xFFFFFFFF)
#define  GCOEFF_DBUS2_dbgctrl(data)                                              (0xFFFFFFFF&(data))
#define  GCOEFF_DBUS2_get_dbgctrl(data)                                          (0xFFFFFFFF&(data))

#define  GCOEFF_BASEA                                                            0x1800F848
#define  GCOEFF_BASEA_reg_addr                                                   "0xB800F848"
#define  GCOEFF_BASEA_reg                                                        0xB800F848
#define  GCOEFF_BASEA_inst_addr                                                  "0x001A"
#define  set_GCOEFF_BASEA_reg(data)                                              (*((volatile unsigned int*)GCOEFF_BASEA_reg)=data)
#define  get_GCOEFF_BASEA_reg                                                    (*((volatile unsigned int*)GCOEFF_BASEA_reg))
#define  GCOEFF_BASEA_vmadr_en_shift                                             (23)
#define  GCOEFF_BASEA_basea0_shift                                               (16)
#define  GCOEFF_BASEA_vmadr_en_mask                                              (0x00800000)
#define  GCOEFF_BASEA_basea0_mask                                                (0x007F0000)
#define  GCOEFF_BASEA_vmadr_en(data)                                             (0x00800000&((data)<<23))
#define  GCOEFF_BASEA_basea0(data)                                               (0x007F0000&((data)<<16))
#define  GCOEFF_BASEA_get_vmadr_en(data)                                         ((0x00800000&(data))>>23)
#define  GCOEFF_BASEA_get_basea0(data)                                           ((0x007F0000&(data))>>16)

#define  GCOEFF_OFFSETA_0                                                        0x1800F84C
#define  GCOEFF_OFFSETA_0_reg_addr                                               "0xB800F84C"
#define  GCOEFF_OFFSETA_0_reg                                                    0xB800F84C
#define  GCOEFF_OFFSETA_0_inst_addr                                              "0x001B"
#define  set_GCOEFF_OFFSETA_0_reg(data)                                          (*((volatile unsigned int*)GCOEFF_OFFSETA_0_reg)=data)
#define  get_GCOEFF_OFFSETA_0_reg                                                (*((volatile unsigned int*)GCOEFF_OFFSETA_0_reg))
#define  GCOEFF_OFFSETA_0_offseta_shift                                          (3)
#define  GCOEFF_OFFSETA_0_offseta_mask                                           (0x000003F8)
#define  GCOEFF_OFFSETA_0_offseta(data)                                          (0x000003F8&((data)<<3))
#define  GCOEFF_OFFSETA_0_get_offseta(data)                                      ((0x000003F8&(data))>>3)

#define  GCOEFF_OFFSETA_1                                                        0x1800F850
#define  GCOEFF_OFFSETA_1_reg_addr                                               "0xB800F850"
#define  GCOEFF_OFFSETA_1_reg                                                    0xB800F850
#define  GCOEFF_OFFSETA_1_inst_addr                                              "0x001C"
#define  set_GCOEFF_OFFSETA_1_reg(data)                                          (*((volatile unsigned int*)GCOEFF_OFFSETA_1_reg)=data)
#define  get_GCOEFF_OFFSETA_1_reg                                                (*((volatile unsigned int*)GCOEFF_OFFSETA_1_reg))
#define  GCOEFF_OFFSETA_1_offseta_shift                                          (3)
#define  GCOEFF_OFFSETA_1_offseta_mask                                           (0x000003F8)
#define  GCOEFF_OFFSETA_1_offseta(data)                                          (0x000003F8&((data)<<3))
#define  GCOEFF_OFFSETA_1_get_offseta(data)                                      ((0x000003F8&(data))>>3)

#define  GCOEFF_DEBPAR                                                           0x1800F924
#define  GCOEFF_DEBPAR_reg_addr                                                  "0xB800F924"
#define  GCOEFF_DEBPAR_reg                                                       0xB800F924
#define  GCOEFF_DEBPAR_inst_addr                                                 "0x001D"
#define  set_GCOEFF_DEBPAR_reg(data)                                             (*((volatile unsigned int*)GCOEFF_DEBPAR_reg)=data)
#define  get_GCOEFF_DEBPAR_reg                                                   (*((volatile unsigned int*)GCOEFF_DEBPAR_reg))
#define  GCOEFF_DEBPAR_starta_shift                                              (0)
#define  GCOEFF_DEBPAR_starta_mask                                               (0x0000007F)
#define  GCOEFF_DEBPAR_starta(data)                                              (0x0000007F&(data))
#define  GCOEFF_DEBPAR_get_starta(data)                                          (0x0000007F&(data))

#define  GCOEFF_CBPCTRL                                                          0x1800F854
#define  GCOEFF_CBPCTRL_reg_addr                                                 "0xB800F854"
#define  GCOEFF_CBPCTRL_reg                                                      0xB800F854
#define  GCOEFF_CBPCTRL_inst_addr                                                "0x001E"
#define  set_GCOEFF_CBPCTRL_reg(data)                                            (*((volatile unsigned int*)GCOEFF_CBPCTRL_reg)=data)
#define  get_GCOEFF_CBPCTRL_reg                                                  (*((volatile unsigned int*)GCOEFF_CBPCTRL_reg))
#define  GCOEFF_CBPCTRL_intralumastylesel_shift                                  (5)
#define  GCOEFF_CBPCTRL_xvid_combine_style_shift                                 (3)
#define  GCOEFF_CBPCTRL_style_sel_shift                                          (0)
#define  GCOEFF_CBPCTRL_intralumastylesel_mask                                   (0x00000020)
#define  GCOEFF_CBPCTRL_xvid_combine_style_mask                                  (0x00000018)
#define  GCOEFF_CBPCTRL_style_sel_mask                                           (0x00000007)
#define  GCOEFF_CBPCTRL_intralumastylesel(data)                                  (0x00000020&((data)<<5))
#define  GCOEFF_CBPCTRL_xvid_combine_style(data)                                 (0x00000018&((data)<<3))
#define  GCOEFF_CBPCTRL_style_sel(data)                                          (0x00000007&(data))
#define  GCOEFF_CBPCTRL_get_intralumastylesel(data)                              ((0x00000020&(data))>>5)
#define  GCOEFF_CBPCTRL_get_xvid_combine_style(data)                             ((0x00000018&(data))>>3)
#define  GCOEFF_CBPCTRL_get_style_sel(data)                                      (0x00000007&(data))

#define  GCOEFF_SUMRUNCOST_8x8_0                                                 0x1800F858
#define  GCOEFF_SUMRUNCOST_8x8_0_reg_addr                                        "0xB800F858"
#define  GCOEFF_SUMRUNCOST_8x8_0_reg                                             0xB800F858
#define  GCOEFF_SUMRUNCOST_8x8_0_inst_addr                                       "0x001F"
#define  set_GCOEFF_SUMRUNCOST_8x8_0_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_0_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_8x8_0_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_0_reg))
#define  GCOEFF_SUMRUNCOST_8x8_0_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_8x8_0_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_8x8_0_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_8x8_0_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_8x8_1                                                 0x1800F85C
#define  GCOEFF_SUMRUNCOST_8x8_1_reg_addr                                        "0xB800F85C"
#define  GCOEFF_SUMRUNCOST_8x8_1_reg                                             0xB800F85C
#define  GCOEFF_SUMRUNCOST_8x8_1_inst_addr                                       "0x0020"
#define  set_GCOEFF_SUMRUNCOST_8x8_1_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_1_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_8x8_1_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_1_reg))
#define  GCOEFF_SUMRUNCOST_8x8_1_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_8x8_1_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_8x8_1_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_8x8_1_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_8x8_2                                                 0x1800F860
#define  GCOEFF_SUMRUNCOST_8x8_2_reg_addr                                        "0xB800F860"
#define  GCOEFF_SUMRUNCOST_8x8_2_reg                                             0xB800F860
#define  GCOEFF_SUMRUNCOST_8x8_2_inst_addr                                       "0x0021"
#define  set_GCOEFF_SUMRUNCOST_8x8_2_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_2_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_8x8_2_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_2_reg))
#define  GCOEFF_SUMRUNCOST_8x8_2_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_8x8_2_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_8x8_2_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_8x8_2_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_8x8_3                                                 0x1800F864
#define  GCOEFF_SUMRUNCOST_8x8_3_reg_addr                                        "0xB800F864"
#define  GCOEFF_SUMRUNCOST_8x8_3_reg                                             0xB800F864
#define  GCOEFF_SUMRUNCOST_8x8_3_inst_addr                                       "0x0022"
#define  set_GCOEFF_SUMRUNCOST_8x8_3_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_3_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_8x8_3_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_3_reg))
#define  GCOEFF_SUMRUNCOST_8x8_3_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_8x8_3_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_8x8_3_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_8x8_3_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_8x8_4                                                 0x1800F868
#define  GCOEFF_SUMRUNCOST_8x8_4_reg_addr                                        "0xB800F868"
#define  GCOEFF_SUMRUNCOST_8x8_4_reg                                             0xB800F868
#define  GCOEFF_SUMRUNCOST_8x8_4_inst_addr                                       "0x0023"
#define  set_GCOEFF_SUMRUNCOST_8x8_4_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_4_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_8x8_4_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_4_reg))
#define  GCOEFF_SUMRUNCOST_8x8_4_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_8x8_4_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_8x8_4_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_8x8_4_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_8x8_5                                                 0x1800F86C
#define  GCOEFF_SUMRUNCOST_8x8_5_reg_addr                                        "0xB800F86C"
#define  GCOEFF_SUMRUNCOST_8x8_5_reg                                             0xB800F86C
#define  GCOEFF_SUMRUNCOST_8x8_5_inst_addr                                       "0x0024"
#define  set_GCOEFF_SUMRUNCOST_8x8_5_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_5_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_8x8_5_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_5_reg))
#define  GCOEFF_SUMRUNCOST_8x8_5_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_8x8_5_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_8x8_5_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_8x8_5_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_8x8_6                                                 0x1800F870
#define  GCOEFF_SUMRUNCOST_8x8_6_reg_addr                                        "0xB800F870"
#define  GCOEFF_SUMRUNCOST_8x8_6_reg                                             0xB800F870
#define  GCOEFF_SUMRUNCOST_8x8_6_inst_addr                                       "0x0025"
#define  set_GCOEFF_SUMRUNCOST_8x8_6_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_6_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_8x8_6_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_6_reg))
#define  GCOEFF_SUMRUNCOST_8x8_6_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_8x8_6_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_8x8_6_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_8x8_6_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_8x8_7                                                 0x1800F874
#define  GCOEFF_SUMRUNCOST_8x8_7_reg_addr                                        "0xB800F874"
#define  GCOEFF_SUMRUNCOST_8x8_7_reg                                             0xB800F874
#define  GCOEFF_SUMRUNCOST_8x8_7_inst_addr                                       "0x0026"
#define  set_GCOEFF_SUMRUNCOST_8x8_7_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_7_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_8x8_7_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_8x8_7_reg))
#define  GCOEFF_SUMRUNCOST_8x8_7_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_8x8_7_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_8x8_7_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_8x8_7_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_4x4_0                                                 0x1800F878
#define  GCOEFF_SUMRUNCOST_4x4_0_reg_addr                                        "0xB800F878"
#define  GCOEFF_SUMRUNCOST_4x4_0_reg                                             0xB800F878
#define  GCOEFF_SUMRUNCOST_4x4_0_inst_addr                                       "0x0027"
#define  set_GCOEFF_SUMRUNCOST_4x4_0_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_4x4_0_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_4x4_0_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_4x4_0_reg))
#define  GCOEFF_SUMRUNCOST_4x4_0_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_4x4_0_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_4x4_0_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_4x4_0_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_4x4_1                                                 0x1800F87C
#define  GCOEFF_SUMRUNCOST_4x4_1_reg_addr                                        "0xB800F87C"
#define  GCOEFF_SUMRUNCOST_4x4_1_reg                                             0xB800F87C
#define  GCOEFF_SUMRUNCOST_4x4_1_inst_addr                                       "0x0028"
#define  set_GCOEFF_SUMRUNCOST_4x4_1_reg(data)                                   (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_4x4_1_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_4x4_1_reg                                         (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_4x4_1_reg))
#define  GCOEFF_SUMRUNCOST_4x4_1_lookup_shift                                    (0)
#define  GCOEFF_SUMRUNCOST_4x4_1_lookup_mask                                     (0xFFFFFFFF)
#define  GCOEFF_SUMRUNCOST_4x4_1_lookup(data)                                    (0xFFFFFFFF&(data))
#define  GCOEFF_SUMRUNCOST_4x4_1_get_lookup(data)                                (0xFFFFFFFF&(data))

#define  GCOEFF_SUMRUNCOST_THR                                                   0x1800F880
#define  GCOEFF_SUMRUNCOST_THR_reg_addr                                          "0xB800F880"
#define  GCOEFF_SUMRUNCOST_THR_reg                                               0xB800F880
#define  GCOEFF_SUMRUNCOST_THR_inst_addr                                         "0x0029"
#define  set_GCOEFF_SUMRUNCOST_THR_reg(data)                                     (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_THR_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_THR_reg                                           (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_THR_reg))
#define  GCOEFF_SUMRUNCOST_THR_t4x4_shift                                        (16)
#define  GCOEFF_SUMRUNCOST_THR_t8x8_shift                                        (0)
#define  GCOEFF_SUMRUNCOST_THR_t4x4_mask                                         (0x07FF0000)
#define  GCOEFF_SUMRUNCOST_THR_t8x8_mask                                         (0x000007FF)
#define  GCOEFF_SUMRUNCOST_THR_t4x4(data)                                        (0x07FF0000&((data)<<16))
#define  GCOEFF_SUMRUNCOST_THR_t8x8(data)                                        (0x000007FF&(data))
#define  GCOEFF_SUMRUNCOST_THR_get_t4x4(data)                                    ((0x07FF0000&(data))>>16)
#define  GCOEFF_SUMRUNCOST_THR_get_t8x8(data)                                    (0x000007FF&(data))

#define  GCOEFF_FIRSTCFF                                                         0x1800F884
#define  GCOEFF_FIRSTCFF_reg_addr                                                "0xB800F884"
#define  GCOEFF_FIRSTCFF_reg                                                     0xB800F884
#define  GCOEFF_FIRSTCFF_inst_addr                                               "0x002A"
#define  set_GCOEFF_FIRSTCFF_reg(data)                                           (*((volatile unsigned int*)GCOEFF_FIRSTCFF_reg)=data)
#define  get_GCOEFF_FIRSTCFF_reg                                                 (*((volatile unsigned int*)GCOEFF_FIRSTCFF_reg))
#define  GCOEFF_FIRSTCFF_t4x4_shift                                              (16)
#define  GCOEFF_FIRSTCFF_t8x8_shift                                              (0)
#define  GCOEFF_FIRSTCFF_t4x4_mask                                               (0x001F0000)
#define  GCOEFF_FIRSTCFF_t8x8_mask                                               (0x0000007F)
#define  GCOEFF_FIRSTCFF_t4x4(data)                                              (0x001F0000&((data)<<16))
#define  GCOEFF_FIRSTCFF_t8x8(data)                                              (0x0000007F&(data))
#define  GCOEFF_FIRSTCFF_get_t4x4(data)                                          ((0x001F0000&(data))>>16)
#define  GCOEFF_FIRSTCFF_get_t8x8(data)                                          (0x0000007F&(data))

#define  GCOEFF_SUMCFF                                                           0x1800F888
#define  GCOEFF_SUMCFF_reg_addr                                                  "0xB800F888"
#define  GCOEFF_SUMCFF_reg                                                       0xB800F888
#define  GCOEFF_SUMCFF_inst_addr                                                 "0x002B"
#define  set_GCOEFF_SUMCFF_reg(data)                                             (*((volatile unsigned int*)GCOEFF_SUMCFF_reg)=data)
#define  get_GCOEFF_SUMCFF_reg                                                   (*((volatile unsigned int*)GCOEFF_SUMCFF_reg))
#define  GCOEFF_SUMCFF_t4x4_shift                                                (8)
#define  GCOEFF_SUMCFF_t8x8_shift                                                (0)
#define  GCOEFF_SUMCFF_t4x4_mask                                                 (0x0000FF00)
#define  GCOEFF_SUMCFF_t8x8_mask                                                 (0x000000FF)
#define  GCOEFF_SUMCFF_t4x4(data)                                                (0x0000FF00&((data)<<8))
#define  GCOEFF_SUMCFF_t8x8(data)                                                (0x000000FF&(data))
#define  GCOEFF_SUMCFF_get_t4x4(data)                                            ((0x0000FF00&(data))>>8)
#define  GCOEFF_SUMCFF_get_t8x8(data)                                            (0x000000FF&(data))

#define  GCOEFF_CHROMA_LD                                                        0x1800F88C
#define  GCOEFF_CHROMA_LD_reg_addr                                               "0xB800F88C"
#define  GCOEFF_CHROMA_LD_reg                                                    0xB800F88C
#define  GCOEFF_CHROMA_LD_inst_addr                                              "0x002C"
#define  set_GCOEFF_CHROMA_LD_reg(data)                                          (*((volatile unsigned int*)GCOEFF_CHROMA_LD_reg)=data)
#define  get_GCOEFF_CHROMA_LD_reg                                                (*((volatile unsigned int*)GCOEFF_CHROMA_LD_reg))
#define  GCOEFF_CHROMA_LD_list1idx0_shift                                        (14)
#define  GCOEFF_CHROMA_LD_list0idx1_shift                                        (7)
#define  GCOEFF_CHROMA_LD_list0idx0_shift                                        (0)
#define  GCOEFF_CHROMA_LD_list1idx0_mask                                         (0x001FC000)
#define  GCOEFF_CHROMA_LD_list0idx1_mask                                         (0x00003F80)
#define  GCOEFF_CHROMA_LD_list0idx0_mask                                         (0x0000007F)
#define  GCOEFF_CHROMA_LD_list1idx0(data)                                        (0x001FC000&((data)<<14))
#define  GCOEFF_CHROMA_LD_list0idx1(data)                                        (0x00003F80&((data)<<7))
#define  GCOEFF_CHROMA_LD_list0idx0(data)                                        (0x0000007F&(data))
#define  GCOEFF_CHROMA_LD_get_list1idx0(data)                                    ((0x001FC000&(data))>>14)
#define  GCOEFF_CHROMA_LD_get_list0idx1(data)                                    ((0x00003F80&(data))>>7)
#define  GCOEFF_CHROMA_LD_get_list0idx0(data)                                    (0x0000007F&(data))

#define  GCOEFF_INTRAMODE_0                                                      0x1800F890
#define  GCOEFF_INTRAMODE_0_reg_addr                                             "0xB800F890"
#define  GCOEFF_INTRAMODE_0_reg                                                  0xB800F890
#define  GCOEFF_INTRAMODE_0_inst_addr                                            "0x002D"
#define  set_GCOEFF_INTRAMODE_0_reg(data)                                        (*((volatile unsigned int*)GCOEFF_INTRAMODE_0_reg)=data)
#define  get_GCOEFF_INTRAMODE_0_reg                                              (*((volatile unsigned int*)GCOEFF_INTRAMODE_0_reg))
#define  GCOEFF_INTRAMODE_0_value_shift                                          (0)
#define  GCOEFF_INTRAMODE_0_value_mask                                           (0xFFFFFFFF)
#define  GCOEFF_INTRAMODE_0_value(data)                                          (0xFFFFFFFF&(data))
#define  GCOEFF_INTRAMODE_0_get_value(data)                                      (0xFFFFFFFF&(data))

#define  GCOEFF_INTRAMODE_1                                                      0x1800F894
#define  GCOEFF_INTRAMODE_1_reg_addr                                             "0xB800F894"
#define  GCOEFF_INTRAMODE_1_reg                                                  0xB800F894
#define  GCOEFF_INTRAMODE_1_inst_addr                                            "0x002E"
#define  set_GCOEFF_INTRAMODE_1_reg(data)                                        (*((volatile unsigned int*)GCOEFF_INTRAMODE_1_reg)=data)
#define  get_GCOEFF_INTRAMODE_1_reg                                              (*((volatile unsigned int*)GCOEFF_INTRAMODE_1_reg))
#define  GCOEFF_INTRAMODE_1_value_shift                                          (0)
#define  GCOEFF_INTRAMODE_1_value_mask                                           (0xFFFFFFFF)
#define  GCOEFF_INTRAMODE_1_value(data)                                          (0xFFFFFFFF&(data))
#define  GCOEFF_INTRAMODE_1_get_value(data)                                      (0xFFFFFFFF&(data))

#define  GCOEFF_INTRAMODE_2                                                      0x1800F898
#define  GCOEFF_INTRAMODE_2_reg_addr                                             "0xB800F898"
#define  GCOEFF_INTRAMODE_2_reg                                                  0xB800F898
#define  GCOEFF_INTRAMODE_2_inst_addr                                            "0x002F"
#define  set_GCOEFF_INTRAMODE_2_reg(data)                                        (*((volatile unsigned int*)GCOEFF_INTRAMODE_2_reg)=data)
#define  get_GCOEFF_INTRAMODE_2_reg                                              (*((volatile unsigned int*)GCOEFF_INTRAMODE_2_reg))
#define  GCOEFF_INTRAMODE_2_value_shift                                          (0)
#define  GCOEFF_INTRAMODE_2_value_mask                                           (0xFFFFFFFF)
#define  GCOEFF_INTRAMODE_2_value(data)                                          (0xFFFFFFFF&(data))
#define  GCOEFF_INTRAMODE_2_get_value(data)                                      (0xFFFFFFFF&(data))

#define  GCOEFF_SLICE                                                            0x1800F89C
#define  GCOEFF_SLICE_reg_addr                                                   "0xB800F89C"
#define  GCOEFF_SLICE_reg                                                        0xB800F89C
#define  GCOEFF_SLICE_inst_addr                                                  "0x0030"
#define  set_GCOEFF_SLICE_reg(data)                                              (*((volatile unsigned int*)GCOEFF_SLICE_reg)=data)
#define  get_GCOEFF_SLICE_reg                                                    (*((volatile unsigned int*)GCOEFF_SLICE_reg))
#define  GCOEFF_SLICE_y_shift                                                    (0)
#define  GCOEFF_SLICE_y_mask                                                     (0x0000007F)
#define  GCOEFF_SLICE_y(data)                                                    (0x0000007F&(data))
#define  GCOEFF_SLICE_get_y(data)                                                (0x0000007F&(data))

#define  GCOEFF_MBLevel_DROP                                                     0x1800F8A0
#define  GCOEFF_MBLevel_DROP_reg_addr                                            "0xB800F8A0"
#define  GCOEFF_MBLevel_DROP_reg                                                 0xB800F8A0
#define  GCOEFF_MBLevel_DROP_inst_addr                                           "0x0031"
#define  set_GCOEFF_MBLevel_DROP_reg(data)                                       (*((volatile unsigned int*)GCOEFF_MBLevel_DROP_reg)=data)
#define  get_GCOEFF_MBLevel_DROP_reg                                             (*((volatile unsigned int*)GCOEFF_MBLevel_DROP_reg))
#define  GCOEFF_MBLevel_DROP_enable_shift                                        (13)
#define  GCOEFF_MBLevel_DROP_thresh_shift                                        (0)
#define  GCOEFF_MBLevel_DROP_enable_mask                                         (0x00002000)
#define  GCOEFF_MBLevel_DROP_thresh_mask                                         (0x00001FFF)
#define  GCOEFF_MBLevel_DROP_enable(data)                                        (0x00002000&((data)<<13))
#define  GCOEFF_MBLevel_DROP_thresh(data)                                        (0x00001FFF&(data))
#define  GCOEFF_MBLevel_DROP_get_enable(data)                                    ((0x00002000&(data))>>13)
#define  GCOEFF_MBLevel_DROP_get_thresh(data)                                    (0x00001FFF&(data))

#define  GCOEFF_SUMRUNCOST_THR_CHR                                               0x1800F8A4
#define  GCOEFF_SUMRUNCOST_THR_CHR_reg_addr                                      "0xB800F8A4"
#define  GCOEFF_SUMRUNCOST_THR_CHR_reg                                           0xB800F8A4
#define  GCOEFF_SUMRUNCOST_THR_CHR_inst_addr                                     "0x0032"
#define  set_GCOEFF_SUMRUNCOST_THR_CHR_reg(data)                                 (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_THR_CHR_reg)=data)
#define  get_GCOEFF_SUMRUNCOST_THR_CHR_reg                                       (*((volatile unsigned int*)GCOEFF_SUMRUNCOST_THR_CHR_reg))
#define  GCOEFF_SUMRUNCOST_THR_CHR_t4x4_shift                                    (16)
#define  GCOEFF_SUMRUNCOST_THR_CHR_t4x4_mask                                     (0x07FF0000)
#define  GCOEFF_SUMRUNCOST_THR_CHR_t4x4(data)                                    (0x07FF0000&((data)<<16))
#define  GCOEFF_SUMRUNCOST_THR_CHR_get_t4x4(data)                                ((0x07FF0000&(data))>>16)

#define  GCOEFF_FIRSTCFF_CHR                                                     0x1800F8A8
#define  GCOEFF_FIRSTCFF_CHR_reg_addr                                            "0xB800F8A8"
#define  GCOEFF_FIRSTCFF_CHR_reg                                                 0xB800F8A8
#define  GCOEFF_FIRSTCFF_CHR_inst_addr                                           "0x0033"
#define  set_GCOEFF_FIRSTCFF_CHR_reg(data)                                       (*((volatile unsigned int*)GCOEFF_FIRSTCFF_CHR_reg)=data)
#define  get_GCOEFF_FIRSTCFF_CHR_reg                                             (*((volatile unsigned int*)GCOEFF_FIRSTCFF_CHR_reg))
#define  GCOEFF_FIRSTCFF_CHR_t4x4_shift                                          (16)
#define  GCOEFF_FIRSTCFF_CHR_t4x4_mask                                           (0x001F0000)
#define  GCOEFF_FIRSTCFF_CHR_t4x4(data)                                          (0x001F0000&((data)<<16))
#define  GCOEFF_FIRSTCFF_CHR_get_t4x4(data)                                      ((0x001F0000&(data))>>16)

#define  GCOEFF_SUMCFF_CHR                                                       0x1800F8AC
#define  GCOEFF_SUMCFF_CHR_reg_addr                                              "0xB800F8AC"
#define  GCOEFF_SUMCFF_CHR_reg                                                   0xB800F8AC
#define  GCOEFF_SUMCFF_CHR_inst_addr                                             "0x0034"
#define  set_GCOEFF_SUMCFF_CHR_reg(data)                                         (*((volatile unsigned int*)GCOEFF_SUMCFF_CHR_reg)=data)
#define  get_GCOEFF_SUMCFF_CHR_reg                                               (*((volatile unsigned int*)GCOEFF_SUMCFF_CHR_reg))
#define  GCOEFF_SUMCFF_CHR_t4x4_shift                                            (8)
#define  GCOEFF_SUMCFF_CHR_t4x4_mask                                             (0x0000FF00)
#define  GCOEFF_SUMCFF_CHR_t4x4(data)                                            (0x0000FF00&((data)<<8))
#define  GCOEFF_SUMCFF_CHR_get_t4x4(data)                                        ((0x0000FF00&(data))>>8)

#define  GCOEFF_ULPRED                                                           0x1800F8B0
#define  GCOEFF_ULPRED_reg_addr                                                  "0xB800F8B0"
#define  GCOEFF_ULPRED_reg                                                       0xB800F8B0
#define  GCOEFF_ULPRED_inst_addr                                                 "0x0035"
#define  set_GCOEFF_ULPRED_reg(data)                                             (*((volatile unsigned int*)GCOEFF_ULPRED_reg)=data)
#define  get_GCOEFF_ULPRED_reg                                                   (*((volatile unsigned int*)GCOEFF_ULPRED_reg))
#define  GCOEFF_ULPRED_luma_wr_shift                                             (26)
#define  GCOEFF_ULPRED_cb_wr_shift                                               (25)
#define  GCOEFF_ULPRED_cr_wr_shift                                               (24)
#define  GCOEFF_ULPRED_luma_shift                                                (16)
#define  GCOEFF_ULPRED_cb_shift                                                  (8)
#define  GCOEFF_ULPRED_cr_shift                                                  (0)
#define  GCOEFF_ULPRED_luma_wr_mask                                              (0x04000000)
#define  GCOEFF_ULPRED_cb_wr_mask                                                (0x02000000)
#define  GCOEFF_ULPRED_cr_wr_mask                                                (0x01000000)
#define  GCOEFF_ULPRED_luma_mask                                                 (0x00FF0000)
#define  GCOEFF_ULPRED_cb_mask                                                   (0x0000FF00)
#define  GCOEFF_ULPRED_cr_mask                                                   (0x000000FF)
#define  GCOEFF_ULPRED_luma_wr(data)                                             (0x04000000&((data)<<26))
#define  GCOEFF_ULPRED_cb_wr(data)                                               (0x02000000&((data)<<25))
#define  GCOEFF_ULPRED_cr_wr(data)                                               (0x01000000&((data)<<24))
#define  GCOEFF_ULPRED_luma(data)                                                (0x00FF0000&((data)<<16))
#define  GCOEFF_ULPRED_cb(data)                                                  (0x0000FF00&((data)<<8))
#define  GCOEFF_ULPRED_cr(data)                                                  (0x000000FF&(data))
#define  GCOEFF_ULPRED_get_luma_wr(data)                                         ((0x04000000&(data))>>26)
#define  GCOEFF_ULPRED_get_cb_wr(data)                                           ((0x02000000&(data))>>25)
#define  GCOEFF_ULPRED_get_cr_wr(data)                                           ((0x01000000&(data))>>24)
#define  GCOEFF_ULPRED_get_luma(data)                                            ((0x00FF0000&(data))>>16)
#define  GCOEFF_ULPRED_get_cb(data)                                              ((0x0000FF00&(data))>>8)
#define  GCOEFF_ULPRED_get_cr(data)                                              (0x000000FF&(data))

#define  GCOEFF_PMEMCTL_DBG                                                      0x1800F8B4
#define  GCOEFF_PMEMCTL_DBG_reg_addr                                             "0xB800F8B4"
#define  GCOEFF_PMEMCTL_DBG_reg                                                  0xB800F8B4
#define  GCOEFF_PMEMCTL_DBG_inst_addr                                            "0x0036"
#define  set_GCOEFF_PMEMCTL_DBG_reg(data)                                        (*((volatile unsigned int*)GCOEFF_PMEMCTL_DBG_reg)=data)
#define  get_GCOEFF_PMEMCTL_DBG_reg                                              (*((volatile unsigned int*)GCOEFF_PMEMCTL_DBG_reg))
#define  GCOEFF_PMEMCTL_DBG_soft_rst_shift                                       (24)
#define  GCOEFF_PMEMCTL_DBG_init_en_shift                                        (23)
#define  GCOEFF_PMEMCTL_DBG_rng_size_shift                                       (16)
#define  GCOEFF_PMEMCTL_DBG_rdptr_shift                                          (8)
#define  GCOEFF_PMEMCTL_DBG_wrptr_shift                                          (0)
#define  GCOEFF_PMEMCTL_DBG_soft_rst_mask                                        (0x01000000)
#define  GCOEFF_PMEMCTL_DBG_init_en_mask                                         (0x00800000)
#define  GCOEFF_PMEMCTL_DBG_rng_size_mask                                        (0x007F0000)
#define  GCOEFF_PMEMCTL_DBG_rdptr_mask                                           (0x0000FF00)
#define  GCOEFF_PMEMCTL_DBG_wrptr_mask                                           (0x000000FF)
#define  GCOEFF_PMEMCTL_DBG_soft_rst(data)                                       (0x01000000&((data)<<24))
#define  GCOEFF_PMEMCTL_DBG_init_en(data)                                        (0x00800000&((data)<<23))
#define  GCOEFF_PMEMCTL_DBG_rng_size(data)                                       (0x007F0000&((data)<<16))
#define  GCOEFF_PMEMCTL_DBG_rdptr(data)                                          (0x0000FF00&((data)<<8))
#define  GCOEFF_PMEMCTL_DBG_wrptr(data)                                          (0x000000FF&(data))
#define  GCOEFF_PMEMCTL_DBG_get_soft_rst(data)                                   ((0x01000000&(data))>>24)
#define  GCOEFF_PMEMCTL_DBG_get_init_en(data)                                    ((0x00800000&(data))>>23)
#define  GCOEFF_PMEMCTL_DBG_get_rng_size(data)                                   ((0x007F0000&(data))>>16)
#define  GCOEFF_PMEMCTL_DBG_get_rdptr(data)                                      ((0x0000FF00&(data))>>8)
#define  GCOEFF_PMEMCTL_DBG_get_wrptr(data)                                      (0x000000FF&(data))

#define  GCOEFF_QUANTIZER                                                        0x1800F8B8
#define  GCOEFF_QUANTIZER_reg_addr                                               "0xB800F8B8"
#define  GCOEFF_QUANTIZER_reg                                                    0xB800F8B8
#define  GCOEFF_QUANTIZER_inst_addr                                              "0x0037"
#define  set_GCOEFF_QUANTIZER_reg(data)                                          (*((volatile unsigned int*)GCOEFF_QUANTIZER_reg)=data)
#define  get_GCOEFF_QUANTIZER_reg                                                (*((volatile unsigned int*)GCOEFF_QUANTIZER_reg))
#define  GCOEFF_QUANTIZER_write_enable3_shift                                    (15)
#define  GCOEFF_QUANTIZER_flat_qtable_shift                                      (14)
#define  GCOEFF_QUANTIZER_write_enable2_shift                                    (13)
#define  GCOEFF_QUANTIZER_qpy_shift                                              (7)
#define  GCOEFF_QUANTIZER_write_enable1_shift                                    (6)
#define  GCOEFF_QUANTIZER_qpc_shift                                              (0)
#define  GCOEFF_QUANTIZER_write_enable3_mask                                     (0x00008000)
#define  GCOEFF_QUANTIZER_flat_qtable_mask                                       (0x00004000)
#define  GCOEFF_QUANTIZER_write_enable2_mask                                     (0x00002000)
#define  GCOEFF_QUANTIZER_qpy_mask                                               (0x00001F80)
#define  GCOEFF_QUANTIZER_write_enable1_mask                                     (0x00000040)
#define  GCOEFF_QUANTIZER_qpc_mask                                               (0x0000003F)
#define  GCOEFF_QUANTIZER_write_enable3(data)                                    (0x00008000&((data)<<15))
#define  GCOEFF_QUANTIZER_flat_qtable(data)                                      (0x00004000&((data)<<14))
#define  GCOEFF_QUANTIZER_write_enable2(data)                                    (0x00002000&((data)<<13))
#define  GCOEFF_QUANTIZER_qpy(data)                                              (0x00001F80&((data)<<7))
#define  GCOEFF_QUANTIZER_write_enable1(data)                                    (0x00000040&((data)<<6))
#define  GCOEFF_QUANTIZER_qpc(data)                                              (0x0000003F&(data))
#define  GCOEFF_QUANTIZER_get_write_enable3(data)                                ((0x00008000&(data))>>15)
#define  GCOEFF_QUANTIZER_get_flat_qtable(data)                                  ((0x00004000&(data))>>14)
#define  GCOEFF_QUANTIZER_get_write_enable2(data)                                ((0x00002000&(data))>>13)
#define  GCOEFF_QUANTIZER_get_qpy(data)                                          ((0x00001F80&(data))>>7)
#define  GCOEFF_QUANTIZER_get_write_enable1(data)                                ((0x00000040&(data))>>6)
#define  GCOEFF_QUANTIZER_get_qpc(data)                                          (0x0000003F&(data))

#define  GCOEFF_MESTATUS                                                         0x1800F8BC
#define  GCOEFF_MESTATUS_reg_addr                                                "0xB800F8BC"
#define  GCOEFF_MESTATUS_reg                                                     0xB800F8BC
#define  GCOEFF_MESTATUS_inst_addr                                               "0x0038"
#define  set_GCOEFF_MESTATUS_reg(data)                                           (*((volatile unsigned int*)GCOEFF_MESTATUS_reg)=data)
#define  get_GCOEFF_MESTATUS_reg                                                 (*((volatile unsigned int*)GCOEFF_MESTATUS_reg))
#define  GCOEFF_MESTATUS_mem_eng_busy_shift                                      (31)
#define  GCOEFF_MESTATUS_mem_eng_busy_mask                                       (0x80000000)
#define  GCOEFF_MESTATUS_mem_eng_busy(data)                                      (0x80000000&((data)<<31))
#define  GCOEFF_MESTATUS_get_mem_eng_busy(data)                                  ((0x80000000&(data))>>31)

#define  GCOEFF_LISTREF                                                          0x1800F8C0
#define  GCOEFF_LISTREF_reg_addr                                                 "0xB800F8C0"
#define  GCOEFF_LISTREF_reg                                                      0xB800F8C0
#define  GCOEFF_LISTREF_inst_addr                                                "0x0039"
#define  set_GCOEFF_LISTREF_reg(data)                                            (*((volatile unsigned int*)GCOEFF_LISTREF_reg)=data)
#define  get_GCOEFF_LISTREF_reg                                                  (*((volatile unsigned int*)GCOEFF_LISTREF_reg))
#define  GCOEFF_LISTREF_inter_pred_mode_shift                                    (16)
#define  GCOEFF_LISTREF_list0refidx0_shift                                       (14)
#define  GCOEFF_LISTREF_list0refidx1_shift                                       (12)
#define  GCOEFF_LISTREF_list0refidx2_shift                                       (10)
#define  GCOEFF_LISTREF_list0refidx3_shift                                       (8)
#define  GCOEFF_LISTREF_list1refidx0_shift                                       (6)
#define  GCOEFF_LISTREF_list1refidx1_shift                                       (4)
#define  GCOEFF_LISTREF_list1refidx2_shift                                       (2)
#define  GCOEFF_LISTREF_list1refidx3_shift                                       (0)
#define  GCOEFF_LISTREF_inter_pred_mode_mask                                     (0x00FF0000)
#define  GCOEFF_LISTREF_list0refidx0_mask                                        (0x0000C000)
#define  GCOEFF_LISTREF_list0refidx1_mask                                        (0x00003000)
#define  GCOEFF_LISTREF_list0refidx2_mask                                        (0x00000C00)
#define  GCOEFF_LISTREF_list0refidx3_mask                                        (0x00000300)
#define  GCOEFF_LISTREF_list1refidx0_mask                                        (0x000000C0)
#define  GCOEFF_LISTREF_list1refidx1_mask                                        (0x00000030)
#define  GCOEFF_LISTREF_list1refidx2_mask                                        (0x0000000C)
#define  GCOEFF_LISTREF_list1refidx3_mask                                        (0x00000003)
#define  GCOEFF_LISTREF_inter_pred_mode(data)                                    (0x00FF0000&((data)<<16))
#define  GCOEFF_LISTREF_list0refidx0(data)                                       (0x0000C000&((data)<<14))
#define  GCOEFF_LISTREF_list0refidx1(data)                                       (0x00003000&((data)<<12))
#define  GCOEFF_LISTREF_list0refidx2(data)                                       (0x00000C00&((data)<<10))
#define  GCOEFF_LISTREF_list0refidx3(data)                                       (0x00000300&((data)<<8))
#define  GCOEFF_LISTREF_list1refidx0(data)                                       (0x000000C0&((data)<<6))
#define  GCOEFF_LISTREF_list1refidx1(data)                                       (0x00000030&((data)<<4))
#define  GCOEFF_LISTREF_list1refidx2(data)                                       (0x0000000C&((data)<<2))
#define  GCOEFF_LISTREF_list1refidx3(data)                                       (0x00000003&(data))
#define  GCOEFF_LISTREF_get_inter_pred_mode(data)                                ((0x00FF0000&(data))>>16)
#define  GCOEFF_LISTREF_get_list0refidx0(data)                                   ((0x0000C000&(data))>>14)
#define  GCOEFF_LISTREF_get_list0refidx1(data)                                   ((0x00003000&(data))>>12)
#define  GCOEFF_LISTREF_get_list0refidx2(data)                                   ((0x00000C00&(data))>>10)
#define  GCOEFF_LISTREF_get_list0refidx3(data)                                   ((0x00000300&(data))>>8)
#define  GCOEFF_LISTREF_get_list1refidx0(data)                                   ((0x000000C0&(data))>>6)
#define  GCOEFF_LISTREF_get_list1refidx1(data)                                   ((0x00000030&(data))>>4)
#define  GCOEFF_LISTREF_get_list1refidx2(data)                                   ((0x0000000C&(data))>>2)
#define  GCOEFF_LISTREF_get_list1refidx3(data)                                   (0x00000003&(data))

#define  GCOEFF_MBINFO                                                           0x1800F8C4
#define  GCOEFF_MBINFO_reg_addr                                                  "0xB800F8C4"
#define  GCOEFF_MBINFO_reg                                                       0xB800F8C4
#define  GCOEFF_MBINFO_inst_addr                                                 "0x003A"
#define  set_GCOEFF_MBINFO_reg(data)                                             (*((volatile unsigned int*)GCOEFF_MBINFO_reg)=data)
#define  get_GCOEFF_MBINFO_reg                                                   (*((volatile unsigned int*)GCOEFF_MBINFO_reg))
#define  GCOEFF_MBINFO_slicestart_shift                                          (25)
#define  GCOEFF_MBINFO_codingtype_shift                                          (23)
#define  GCOEFF_MBINFO_picturetype_shift                                         (21)
#define  GCOEFF_MBINFO_mbtype_shift                                              (19)
#define  GCOEFF_MBINFO_mbpartition_shift                                         (16)
#define  GCOEFF_MBINFO_curmby_shift                                              (8)
#define  GCOEFF_MBINFO_curmbx_shift                                              (0)
#define  GCOEFF_MBINFO_slicestart_mask                                           (0x02000000)
#define  GCOEFF_MBINFO_codingtype_mask                                           (0x01800000)
#define  GCOEFF_MBINFO_picturetype_mask                                          (0x00600000)
#define  GCOEFF_MBINFO_mbtype_mask                                               (0x00180000)
#define  GCOEFF_MBINFO_mbpartition_mask                                          (0x00070000)
#define  GCOEFF_MBINFO_curmby_mask                                               (0x0000FF00)
#define  GCOEFF_MBINFO_curmbx_mask                                               (0x000000FF)
#define  GCOEFF_MBINFO_slicestart(data)                                          (0x02000000&((data)<<25))
#define  GCOEFF_MBINFO_codingtype(data)                                          (0x01800000&((data)<<23))
#define  GCOEFF_MBINFO_picturetype(data)                                         (0x00600000&((data)<<21))
#define  GCOEFF_MBINFO_mbtype(data)                                              (0x00180000&((data)<<19))
#define  GCOEFF_MBINFO_mbpartition(data)                                         (0x00070000&((data)<<16))
#define  GCOEFF_MBINFO_curmby(data)                                              (0x0000FF00&((data)<<8))
#define  GCOEFF_MBINFO_curmbx(data)                                              (0x000000FF&(data))
#define  GCOEFF_MBINFO_get_slicestart(data)                                      ((0x02000000&(data))>>25)
#define  GCOEFF_MBINFO_get_codingtype(data)                                      ((0x01800000&(data))>>23)
#define  GCOEFF_MBINFO_get_picturetype(data)                                     ((0x00600000&(data))>>21)
#define  GCOEFF_MBINFO_get_mbtype(data)                                          ((0x00180000&(data))>>19)
#define  GCOEFF_MBINFO_get_mbpartition(data)                                     ((0x00070000&(data))>>16)
#define  GCOEFF_MBINFO_get_curmby(data)                                          ((0x0000FF00&(data))>>8)
#define  GCOEFF_MBINFO_get_curmbx(data)                                          (0x000000FF&(data))

#define  GCOEFF_REMMODE_0                                                        0x1800F8C8
#define  GCOEFF_REMMODE_0_reg_addr                                               "0xB800F8C8"
#define  GCOEFF_REMMODE_0_reg                                                    0xB800F8C8
#define  GCOEFF_REMMODE_0_inst_addr                                              "0x003B"
#define  set_GCOEFF_REMMODE_0_reg(data)                                          (*((volatile unsigned int*)GCOEFF_REMMODE_0_reg)=data)
#define  get_GCOEFF_REMMODE_0_reg                                                (*((volatile unsigned int*)GCOEFF_REMMODE_0_reg))
#define  GCOEFF_REMMODE_0_value_shift                                            (0)
#define  GCOEFF_REMMODE_0_value_mask                                             (0xFFFFFFFF)
#define  GCOEFF_REMMODE_0_value(data)                                            (0xFFFFFFFF&(data))
#define  GCOEFF_REMMODE_0_get_value(data)                                        (0xFFFFFFFF&(data))

#define  GCOEFF_REMMODE_1                                                        0x1800F8CC
#define  GCOEFF_REMMODE_1_reg_addr                                               "0xB800F8CC"
#define  GCOEFF_REMMODE_1_reg                                                    0xB800F8CC
#define  GCOEFF_REMMODE_1_inst_addr                                              "0x003C"
#define  set_GCOEFF_REMMODE_1_reg(data)                                          (*((volatile unsigned int*)GCOEFF_REMMODE_1_reg)=data)
#define  get_GCOEFF_REMMODE_1_reg                                                (*((volatile unsigned int*)GCOEFF_REMMODE_1_reg))
#define  GCOEFF_REMMODE_1_value_shift                                            (0)
#define  GCOEFF_REMMODE_1_value_mask                                             (0xFFFFFFFF)
#define  GCOEFF_REMMODE_1_value(data)                                            (0xFFFFFFFF&(data))
#define  GCOEFF_REMMODE_1_get_value(data)                                        (0xFFFFFFFF&(data))

#define  GCOEFF_REMMODE_2                                                        0x1800F8D0
#define  GCOEFF_REMMODE_2_reg_addr                                               "0xB800F8D0"
#define  GCOEFF_REMMODE_2_reg                                                    0xB800F8D0
#define  GCOEFF_REMMODE_2_inst_addr                                              "0x003D"
#define  set_GCOEFF_REMMODE_2_reg(data)                                          (*((volatile unsigned int*)GCOEFF_REMMODE_2_reg)=data)
#define  get_GCOEFF_REMMODE_2_reg                                                (*((volatile unsigned int*)GCOEFF_REMMODE_2_reg))
#define  GCOEFF_REMMODE_2_value_shift                                            (0)
#define  GCOEFF_REMMODE_2_value_mask                                             (0xFFFFFFFF)
#define  GCOEFF_REMMODE_2_value(data)                                            (0xFFFFFFFF&(data))
#define  GCOEFF_REMMODE_2_get_value(data)                                        (0xFFFFFFFF&(data))

#define  GCOEFF_BITSTR_0                                                         0x1800F8D4
#define  GCOEFF_BITSTR_0_reg_addr                                                "0xB800F8D4"
#define  GCOEFF_BITSTR_0_reg                                                     0xB800F8D4
#define  GCOEFF_BITSTR_0_inst_addr                                               "0x003E"
#define  set_GCOEFF_BITSTR_0_reg(data)                                           (*((volatile unsigned int*)GCOEFF_BITSTR_0_reg)=data)
#define  get_GCOEFF_BITSTR_0_reg                                                 (*((volatile unsigned int*)GCOEFF_BITSTR_0_reg))
#define  GCOEFF_BITSTR_0_value_shift                                             (0)
#define  GCOEFF_BITSTR_0_value_mask                                              (0xFFFFFFFF)
#define  GCOEFF_BITSTR_0_value(data)                                             (0xFFFFFFFF&(data))
#define  GCOEFF_BITSTR_0_get_value(data)                                         (0xFFFFFFFF&(data))

#define  GCOEFF_BITSTR_1                                                         0x1800F8D8
#define  GCOEFF_BITSTR_1_reg_addr                                                "0xB800F8D8"
#define  GCOEFF_BITSTR_1_reg                                                     0xB800F8D8
#define  GCOEFF_BITSTR_1_inst_addr                                               "0x003F"
#define  set_GCOEFF_BITSTR_1_reg(data)                                           (*((volatile unsigned int*)GCOEFF_BITSTR_1_reg)=data)
#define  get_GCOEFF_BITSTR_1_reg                                                 (*((volatile unsigned int*)GCOEFF_BITSTR_1_reg))
#define  GCOEFF_BITSTR_1_value_shift                                             (0)
#define  GCOEFF_BITSTR_1_value_mask                                              (0xFFFFFFFF)
#define  GCOEFF_BITSTR_1_value(data)                                             (0xFFFFFFFF&(data))
#define  GCOEFF_BITSTR_1_get_value(data)                                         (0xFFFFFFFF&(data))

#define  GCOEFF_DEBINFO                                                          0x1800F8DC
#define  GCOEFF_DEBINFO_reg_addr                                                 "0xB800F8DC"
#define  GCOEFF_DEBINFO_reg                                                      0xB800F8DC
#define  GCOEFF_DEBINFO_inst_addr                                                "0x0040"
#define  set_GCOEFF_DEBINFO_reg(data)                                            (*((volatile unsigned int*)GCOEFF_DEBINFO_reg)=data)
#define  get_GCOEFF_DEBINFO_reg                                                  (*((volatile unsigned int*)GCOEFF_DEBINFO_reg))
#define  GCOEFF_DEBINFO_mb_mode_shift                                            (3)
#define  GCOEFF_DEBINFO_eob_total_shift                                          (2)
#define  GCOEFF_DEBINFO_transform_size_8x8_flag_shift                            (1)
#define  GCOEFF_DEBINFO_mb_field_decoding_flag_shift                             (0)
#define  GCOEFF_DEBINFO_mb_mode_mask                                             (0x00000038)
#define  GCOEFF_DEBINFO_eob_total_mask                                           (0x00000004)
#define  GCOEFF_DEBINFO_transform_size_8x8_flag_mask                             (0x00000002)
#define  GCOEFF_DEBINFO_mb_field_decoding_flag_mask                              (0x00000001)
#define  GCOEFF_DEBINFO_mb_mode(data)                                            (0x00000038&((data)<<3))
#define  GCOEFF_DEBINFO_eob_total(data)                                          (0x00000004&((data)<<2))
#define  GCOEFF_DEBINFO_transform_size_8x8_flag(data)                            (0x00000002&((data)<<1))
#define  GCOEFF_DEBINFO_mb_field_decoding_flag(data)                             (0x00000001&(data))
#define  GCOEFF_DEBINFO_get_mb_mode(data)                                        ((0x00000038&(data))>>3)
#define  GCOEFF_DEBINFO_get_eob_total(data)                                      ((0x00000004&(data))>>2)
#define  GCOEFF_DEBINFO_get_transform_size_8x8_flag(data)                        ((0x00000002&(data))>>1)
#define  GCOEFF_DEBINFO_get_mb_field_decoding_flag(data)                         (0x00000001&(data))

#define  GCOEFF_SBCTRL                                                           0x1800F900
#define  GCOEFF_SBCTRL_reg_addr                                                  "0xB800F900"
#define  GCOEFF_SBCTRL_reg                                                       0xB800F900
#define  GCOEFF_SBCTRL_inst_addr                                                 "0x0041"
#define  set_GCOEFF_SBCTRL_reg(data)                                             (*((volatile unsigned int*)GCOEFF_SBCTRL_reg)=data)
#define  get_GCOEFF_SBCTRL_reg                                                   (*((volatile unsigned int*)GCOEFF_SBCTRL_reg))
#define  GCOEFF_SBCTRL_write_enable4_shift                                       (10)
#define  GCOEFF_SBCTRL_dv_enable_shift                                           (9)
#define  GCOEFF_SBCTRL_write_enable3_shift                                       (8)
#define  GCOEFF_SBCTRL_size_shift                                                (6)
#define  GCOEFF_SBCTRL_write_enable2_shift                                       (5)
#define  GCOEFF_SBCTRL_rdptr_shift                                               (3)
#define  GCOEFF_SBCTRL_write_enable1_shift                                       (2)
#define  GCOEFF_SBCTRL_wrptr_shift                                               (0)
#define  GCOEFF_SBCTRL_write_enable4_mask                                        (0x00000400)
#define  GCOEFF_SBCTRL_dv_enable_mask                                            (0x00000200)
#define  GCOEFF_SBCTRL_write_enable3_mask                                        (0x00000100)
#define  GCOEFF_SBCTRL_size_mask                                                 (0x000000C0)
#define  GCOEFF_SBCTRL_write_enable2_mask                                        (0x00000020)
#define  GCOEFF_SBCTRL_rdptr_mask                                                (0x00000018)
#define  GCOEFF_SBCTRL_write_enable1_mask                                        (0x00000004)
#define  GCOEFF_SBCTRL_wrptr_mask                                                (0x00000003)
#define  GCOEFF_SBCTRL_write_enable4(data)                                       (0x00000400&((data)<<10))
#define  GCOEFF_SBCTRL_dv_enable(data)                                           (0x00000200&((data)<<9))
#define  GCOEFF_SBCTRL_write_enable3(data)                                       (0x00000100&((data)<<8))
#define  GCOEFF_SBCTRL_size(data)                                                (0x000000C0&((data)<<6))
#define  GCOEFF_SBCTRL_write_enable2(data)                                       (0x00000020&((data)<<5))
#define  GCOEFF_SBCTRL_rdptr(data)                                               (0x00000018&((data)<<3))
#define  GCOEFF_SBCTRL_write_enable1(data)                                       (0x00000004&((data)<<2))
#define  GCOEFF_SBCTRL_wrptr(data)                                               (0x00000003&(data))
#define  GCOEFF_SBCTRL_get_write_enable4(data)                                   ((0x00000400&(data))>>10)
#define  GCOEFF_SBCTRL_get_dv_enable(data)                                       ((0x00000200&(data))>>9)
#define  GCOEFF_SBCTRL_get_write_enable3(data)                                   ((0x00000100&(data))>>8)
#define  GCOEFF_SBCTRL_get_size(data)                                            ((0x000000C0&(data))>>6)
#define  GCOEFF_SBCTRL_get_write_enable2(data)                                   ((0x00000020&(data))>>5)
#define  GCOEFF_SBCTRL_get_rdptr(data)                                           ((0x00000018&(data))>>3)
#define  GCOEFF_SBCTRL_get_write_enable1(data)                                   ((0x00000004&(data))>>2)
#define  GCOEFF_SBCTRL_get_wrptr(data)                                           (0x00000003&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======GCOEFF register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  write_enable14:1;
        RBus_UInt32  ipmdoff:1;
        RBus_UInt32  write_enable13:1;
        RBus_UInt32  sideband_enable:1;
        RBus_UInt32  write_enable12:1;
        RBus_UInt32  luma16x8_xform_sel:1;
        RBus_UInt32  write_enable11:1;
        RBus_UInt32  luma8x16_xform_sel:1;
        RBus_UInt32  write_enable10:1;
        RBus_UInt32  flush_cmd_disable:1;
        RBus_UInt32  write_enable9:1;
        RBus_UInt32  softrst_disable:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  trmem_dv_load:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  umem_bypass:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  luma16x16_xform_sel:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  luma8x8_xform_sel:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  constr_intra_pred:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  wdone_enable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  sreset_busy_clr:1;
    };
}gcoeff_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}gcoeff_intra_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  fmvx:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  fmvy:10;
    };
}gcoeff_chmv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  fmvx:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  fmvy:10;
    };
}gcoeff_chbmv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  fmvx:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  fmvy:10;
    };
}gcoeff_chmvd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  fmvx:12;
        RBus_UInt32  res2:6;
        RBus_UInt32  fmvy:10;
    };
}gcoeff_chbmvd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  seq_line_addr:31;
    };
}gcoeff_sdmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  value:28;
    };
}gcoeff_intr_thresh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reach_thresh:1;
        RBus_UInt32  count:28;
    };
}gcoeff_busy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  genpulse:1;
        RBus_UInt32  dbgctrl:3;
        RBus_UInt32  piccount:14;
        RBus_UInt32  mbaddrx:7;
        RBus_UInt32  mbaddry:7;
    };
}gcoeff_dbus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgctrl:32;
    };
}gcoeff_dbus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  vmadr_en:1;
        RBus_UInt32  basea0:7;
        RBus_UInt32  res2:16;
    };
}gcoeff_basea_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  offseta:7;
        RBus_UInt32  res2:3;
    };
}gcoeff_offseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  starta:7;
    };
}gcoeff_debpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  intralumastylesel:1;
        RBus_UInt32  xvid_combine_style:2;
        RBus_UInt32  style_sel:3;
    };
}gcoeff_cbpctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lookup:32;
    };
}gcoeff_sumruncost_8x8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lookup:32;
    };
}gcoeff_sumruncost_4x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  t4x4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  t8x8:11;
    };
}gcoeff_sumruncost_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  t4x4:5;
        RBus_UInt32  res2:9;
        RBus_UInt32  t8x8:7;
    };
}gcoeff_firstcff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  t4x4:8;
        RBus_UInt32  t8x8:8;
    };
}gcoeff_sumcff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  list1idx0:7;
        RBus_UInt32  list0idx1:7;
        RBus_UInt32  list0idx0:7;
    };
}gcoeff_chroma_ld_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}gcoeff_intramode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  y:7;
    };
}gcoeff_slice_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  enable:1;
        RBus_UInt32  thresh:13;
    };
}gcoeff_mblevel_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  t4x4:11;
        RBus_UInt32  res2:16;
    };
}gcoeff_sumruncost_thr_chr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  t4x4:5;
        RBus_UInt32  res2:16;
    };
}gcoeff_firstcff_chr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  t4x4:8;
        RBus_UInt32  res2:8;
    };
}gcoeff_sumcff_chr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  luma_wr:1;
        RBus_UInt32  cb_wr:1;
        RBus_UInt32  cr_wr:1;
        RBus_UInt32  luma:8;
        RBus_UInt32  cb:8;
        RBus_UInt32  cr:8;
    };
}gcoeff_ulpred_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  soft_rst:1;
        RBus_UInt32  init_en:1;
        RBus_UInt32  rng_size:7;
        RBus_UInt32  rdptr:8;
        RBus_UInt32  wrptr:8;
    };
}gcoeff_pmemctl_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  flat_qtable:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  qpc:6;
    };
}gcoeff_quantizer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_eng_busy:1;
        RBus_UInt32  res1:31;
    };
}gcoeff_mestatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  inter_pred_mode:8;
        RBus_UInt32  list0refidx0:2;
        RBus_UInt32  list0refidx1:2;
        RBus_UInt32  list0refidx2:2;
        RBus_UInt32  list0refidx3:2;
        RBus_UInt32  list1refidx0:2;
        RBus_UInt32  list1refidx1:2;
        RBus_UInt32  list1refidx2:2;
        RBus_UInt32  list1refidx3:2;
    };
}gcoeff_listref_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  slicestart:1;
        RBus_UInt32  codingtype:2;
        RBus_UInt32  picturetype:2;
        RBus_UInt32  mbtype:2;
        RBus_UInt32  mbpartition:3;
        RBus_UInt32  curmby:8;
        RBus_UInt32  curmbx:8;
    };
}gcoeff_mbinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}gcoeff_remmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}gcoeff_bitstr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  mb_mode:3;
        RBus_UInt32  eob_total:1;
        RBus_UInt32  transform_size_8x8_flag:1;
        RBus_UInt32  mb_field_decoding_flag:1;
    };
}gcoeff_debinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  dv_enable:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  size:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  rdptr:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  wrptr:2;
    };
}gcoeff_sbctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======GCOEFF register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sreset_busy_clr:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  wdone_enable:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  constr_intra_pred:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  luma8x8_xform_sel:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  luma16x16_xform_sel:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  umem_bypass:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  trmem_dv_load:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  softrst_disable:1;
        RBus_UInt32  write_enable9:1;
        RBus_UInt32  flush_cmd_disable:1;
        RBus_UInt32  write_enable10:1;
        RBus_UInt32  luma8x16_xform_sel:1;
        RBus_UInt32  write_enable11:1;
        RBus_UInt32  luma16x8_xform_sel:1;
        RBus_UInt32  write_enable12:1;
        RBus_UInt32  sideband_enable:1;
        RBus_UInt32  write_enable13:1;
        RBus_UInt32  ipmdoff:1;
        RBus_UInt32  write_enable14:1;
        RBus_UInt32  res1:6;
    };
}gcoeff_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}gcoeff_intra_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fmvy:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  fmvx:12;
        RBus_UInt32  res2:4;
    };
}gcoeff_chmv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fmvy:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  fmvx:12;
        RBus_UInt32  res2:4;
    };
}gcoeff_chbmv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fmvy:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  fmvx:12;
        RBus_UInt32  res2:4;
    };
}gcoeff_chmvd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fmvy:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  fmvx:12;
        RBus_UInt32  res2:4;
    };
}gcoeff_chbmvd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:31;
        RBus_UInt32  res1:1;
    };
}gcoeff_sdmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:28;
        RBus_UInt32  res1:4;
    };
}gcoeff_intr_thresh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count:28;
        RBus_UInt32  reach_thresh:1;
        RBus_UInt32  res1:3;
    };
}gcoeff_busy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbaddry:7;
        RBus_UInt32  mbaddrx:7;
        RBus_UInt32  piccount:14;
        RBus_UInt32  dbgctrl:3;
        RBus_UInt32  genpulse:1;
    };
}gcoeff_dbus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgctrl:32;
    };
}gcoeff_dbus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  basea0:7;
        RBus_UInt32  vmadr_en:1;
        RBus_UInt32  res2:8;
    };
}gcoeff_basea_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  offseta:7;
        RBus_UInt32  res2:22;
    };
}gcoeff_offseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  starta:7;
        RBus_UInt32  res1:25;
    };
}gcoeff_debpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  style_sel:3;
        RBus_UInt32  xvid_combine_style:2;
        RBus_UInt32  intralumastylesel:1;
        RBus_UInt32  res1:26;
    };
}gcoeff_cbpctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lookup:32;
    };
}gcoeff_sumruncost_8x8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lookup:32;
    };
}gcoeff_sumruncost_4x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t8x8:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  t4x4:11;
        RBus_UInt32  res2:5;
    };
}gcoeff_sumruncost_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t8x8:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  t4x4:5;
        RBus_UInt32  res2:11;
    };
}gcoeff_firstcff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  t8x8:8;
        RBus_UInt32  t4x4:8;
        RBus_UInt32  res1:16;
    };
}gcoeff_sumcff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  list0idx0:7;
        RBus_UInt32  list0idx1:7;
        RBus_UInt32  list1idx0:7;
        RBus_UInt32  res1:11;
    };
}gcoeff_chroma_ld_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}gcoeff_intramode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:7;
        RBus_UInt32  res1:25;
    };
}gcoeff_slice_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  thresh:13;
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:18;
    };
}gcoeff_mblevel_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  t4x4:11;
        RBus_UInt32  res2:5;
    };
}gcoeff_sumruncost_thr_chr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  t4x4:5;
        RBus_UInt32  res2:11;
    };
}gcoeff_firstcff_chr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  t4x4:8;
        RBus_UInt32  res2:16;
    };
}gcoeff_sumcff_chr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr:8;
        RBus_UInt32  cb:8;
        RBus_UInt32  luma:8;
        RBus_UInt32  cr_wr:1;
        RBus_UInt32  cb_wr:1;
        RBus_UInt32  luma_wr:1;
        RBus_UInt32  res1:5;
    };
}gcoeff_ulpred_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrptr:8;
        RBus_UInt32  rdptr:8;
        RBus_UInt32  rng_size:7;
        RBus_UInt32  init_en:1;
        RBus_UInt32  soft_rst:1;
        RBus_UInt32  res1:7;
    };
}gcoeff_pmemctl_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qpc:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  flat_qtable:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:16;
    };
}gcoeff_quantizer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mem_eng_busy:1;
    };
}gcoeff_mestatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  list1refidx3:2;
        RBus_UInt32  list1refidx2:2;
        RBus_UInt32  list1refidx1:2;
        RBus_UInt32  list1refidx0:2;
        RBus_UInt32  list0refidx3:2;
        RBus_UInt32  list0refidx2:2;
        RBus_UInt32  list0refidx1:2;
        RBus_UInt32  list0refidx0:2;
        RBus_UInt32  inter_pred_mode:8;
        RBus_UInt32  res1:8;
    };
}gcoeff_listref_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  curmbx:8;
        RBus_UInt32  curmby:8;
        RBus_UInt32  mbpartition:3;
        RBus_UInt32  mbtype:2;
        RBus_UInt32  picturetype:2;
        RBus_UInt32  codingtype:2;
        RBus_UInt32  slicestart:1;
        RBus_UInt32  res1:6;
    };
}gcoeff_mbinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}gcoeff_remmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}gcoeff_bitstr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_field_decoding_flag:1;
        RBus_UInt32  transform_size_8x8_flag:1;
        RBus_UInt32  eob_total:1;
        RBus_UInt32  mb_mode:3;
        RBus_UInt32  res1:26;
    };
}gcoeff_debinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrptr:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  rdptr:2;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  size:2;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  dv_enable:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  res1:21;
    };
}gcoeff_sbctrl_RBUS;




#endif 


#endif 
