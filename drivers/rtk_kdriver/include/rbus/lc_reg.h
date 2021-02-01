/**
* @file Mac5-DesignSpec-D-Domain_Local_Contrast
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LC_REG_H_
#define _RBUS_LC_REG_H_

#include "rbus_types.h"



//  LC Register Address
#define  LC_LC_Global_Ctrl0                                                      0x1802E000
#define  LC_LC_Global_Ctrl0_reg_addr                                             "0xB802E000"
#define  LC_LC_Global_Ctrl0_reg                                                  0xB802E000
#define  LC_LC_Global_Ctrl0_inst_addr                                            "0x0000"
#define  set_LC_LC_Global_Ctrl0_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Ctrl0_reg)=data)
#define  get_LC_LC_Global_Ctrl0_reg                                              (*((volatile unsigned int*)LC_LC_Global_Ctrl0_reg))
#define  LC_LC_Global_Ctrl0_dummy_31_shift                                       (31)
#define  LC_LC_Global_Ctrl0_lc_apl_en_shift                                      (30)
#define  LC_LC_Global_Ctrl0_lc_local_sharp_en_shift                              (29)
#define  LC_LC_Global_Ctrl0_lc_tone_mapping_en_shift                             (28)
#define  LC_LC_Global_Ctrl0_dummy_27_2_shift                                     (2)
#define  LC_LC_Global_Ctrl0_lc_debugmode_shift                                   (0)
#define  LC_LC_Global_Ctrl0_dummy_31_mask                                        (0x80000000)
#define  LC_LC_Global_Ctrl0_lc_apl_en_mask                                       (0x40000000)
#define  LC_LC_Global_Ctrl0_lc_local_sharp_en_mask                               (0x20000000)
#define  LC_LC_Global_Ctrl0_lc_tone_mapping_en_mask                              (0x10000000)
#define  LC_LC_Global_Ctrl0_dummy_27_2_mask                                      (0x0FFFFFFC)
#define  LC_LC_Global_Ctrl0_lc_debugmode_mask                                    (0x00000003)
#define  LC_LC_Global_Ctrl0_dummy_31(data)                                       (0x80000000&((data)<<31))
#define  LC_LC_Global_Ctrl0_lc_apl_en(data)                                      (0x40000000&((data)<<30))
#define  LC_LC_Global_Ctrl0_lc_local_sharp_en(data)                              (0x20000000&((data)<<29))
#define  LC_LC_Global_Ctrl0_lc_tone_mapping_en(data)                             (0x10000000&((data)<<28))
#define  LC_LC_Global_Ctrl0_dummy_27_2(data)                                     (0x0FFFFFFC&((data)<<2))
#define  LC_LC_Global_Ctrl0_lc_debugmode(data)                                   (0x00000003&(data))
#define  LC_LC_Global_Ctrl0_get_dummy_31(data)                                   ((0x80000000&(data))>>31)
#define  LC_LC_Global_Ctrl0_get_lc_apl_en(data)                                  ((0x40000000&(data))>>30)
#define  LC_LC_Global_Ctrl0_get_lc_local_sharp_en(data)                          ((0x20000000&(data))>>29)
#define  LC_LC_Global_Ctrl0_get_lc_tone_mapping_en(data)                         ((0x10000000&(data))>>28)
#define  LC_LC_Global_Ctrl0_get_dummy_27_2(data)                                 ((0x0FFFFFFC&(data))>>2)
#define  LC_LC_Global_Ctrl0_get_lc_debugmode(data)                               (0x00000003&(data))

#define  LC_LC_Global_Ctrl1                                                      0x1802E004
#define  LC_LC_Global_Ctrl1_reg_addr                                             "0xB802E004"
#define  LC_LC_Global_Ctrl1_reg                                                  0xB802E004
#define  LC_LC_Global_Ctrl1_inst_addr                                            "0x0001"
#define  set_LC_LC_Global_Ctrl1_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Ctrl1_reg)=data)
#define  get_LC_LC_Global_Ctrl1_reg                                              (*((volatile unsigned int*)LC_LC_Global_Ctrl1_reg))
#define  LC_LC_Global_Ctrl1_lc_db_en_shift                                       (31)
#define  LC_LC_Global_Ctrl1_dummy_30_shift                                       (30)
#define  LC_LC_Global_Ctrl1_lc_db_apply_shift                                    (29)
#define  LC_LC_Global_Ctrl1_dummy_28_shift                                       (28)
#define  LC_LC_Global_Ctrl1_lc_db_read_level_shift                               (27)
#define  LC_LC_Global_Ctrl1_dummy_26_0_shift                                     (0)
#define  LC_LC_Global_Ctrl1_lc_db_en_mask                                        (0x80000000)
#define  LC_LC_Global_Ctrl1_dummy_30_mask                                        (0x40000000)
#define  LC_LC_Global_Ctrl1_lc_db_apply_mask                                     (0x20000000)
#define  LC_LC_Global_Ctrl1_dummy_28_mask                                        (0x10000000)
#define  LC_LC_Global_Ctrl1_lc_db_read_level_mask                                (0x08000000)
#define  LC_LC_Global_Ctrl1_dummy_26_0_mask                                      (0x07FFFFFF)
#define  LC_LC_Global_Ctrl1_lc_db_en(data)                                       (0x80000000&((data)<<31))
#define  LC_LC_Global_Ctrl1_dummy_30(data)                                       (0x40000000&((data)<<30))
#define  LC_LC_Global_Ctrl1_lc_db_apply(data)                                    (0x20000000&((data)<<29))
#define  LC_LC_Global_Ctrl1_dummy_28(data)                                       (0x10000000&((data)<<28))
#define  LC_LC_Global_Ctrl1_lc_db_read_level(data)                               (0x08000000&((data)<<27))
#define  LC_LC_Global_Ctrl1_dummy_26_0(data)                                     (0x07FFFFFF&(data))
#define  LC_LC_Global_Ctrl1_get_lc_db_en(data)                                   ((0x80000000&(data))>>31)
#define  LC_LC_Global_Ctrl1_get_dummy_30(data)                                   ((0x40000000&(data))>>30)
#define  LC_LC_Global_Ctrl1_get_lc_db_apply(data)                                ((0x20000000&(data))>>29)
#define  LC_LC_Global_Ctrl1_get_dummy_28(data)                                   ((0x10000000&(data))>>28)
#define  LC_LC_Global_Ctrl1_get_lc_db_read_level(data)                           ((0x08000000&(data))>>27)
#define  LC_LC_Global_Ctrl1_get_dummy_26_0(data)                                 (0x07FFFFFF&(data))

#define  LC_LC_Global_Ctrl2                                                      0x1802E008
#define  LC_LC_Global_Ctrl2_reg_addr                                             "0xB802E008"
#define  LC_LC_Global_Ctrl2_reg                                                  0xB802E008
#define  LC_LC_Global_Ctrl2_inst_addr                                            "0x0002"
#define  set_LC_LC_Global_Ctrl2_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Ctrl2_reg)=data)
#define  get_LC_LC_Global_Ctrl2_reg                                              (*((volatile unsigned int*)LC_LC_Global_Ctrl2_reg))
#define  LC_LC_Global_Ctrl2_dummy_31_shift                                       (31)
#define  LC_LC_Global_Ctrl2_lc_3d_mode_shift                                     (29)
#define  LC_LC_Global_Ctrl2_lc_blk_hnum_shift                                    (24)
#define  LC_LC_Global_Ctrl2_dummy_23_21_shift                                    (21)
#define  LC_LC_Global_Ctrl2_lc_blk_vnum_shift                                    (16)
#define  LC_LC_Global_Ctrl2_dummy_15_8_shift                                     (8)
#define  LC_LC_Global_Ctrl2_lc_subblk_mode_shift                                 (7)
#define  LC_LC_Global_Ctrl2_lc_gcon_mode_shift                                   (6)
#define  LC_LC_Global_Ctrl2_dummy_5_4_shift                                      (4)
#define  LC_LC_Global_Ctrl2_lc_hist_mode_shift                                   (2)
#define  LC_LC_Global_Ctrl2_lc_tenable_shift                                     (1)
#define  LC_LC_Global_Ctrl2_lc_valid_shift                                       (0)
#define  LC_LC_Global_Ctrl2_dummy_31_mask                                        (0x80000000)
#define  LC_LC_Global_Ctrl2_lc_3d_mode_mask                                      (0x60000000)
#define  LC_LC_Global_Ctrl2_lc_blk_hnum_mask                                     (0x1F000000)
#define  LC_LC_Global_Ctrl2_dummy_23_21_mask                                     (0x00E00000)
#define  LC_LC_Global_Ctrl2_lc_blk_vnum_mask                                     (0x001F0000)
#define  LC_LC_Global_Ctrl2_dummy_15_8_mask                                      (0x0000FF00)
#define  LC_LC_Global_Ctrl2_lc_subblk_mode_mask                                  (0x00000080)
#define  LC_LC_Global_Ctrl2_lc_gcon_mode_mask                                    (0x00000040)
#define  LC_LC_Global_Ctrl2_dummy_5_4_mask                                       (0x00000030)
#define  LC_LC_Global_Ctrl2_lc_hist_mode_mask                                    (0x0000000C)
#define  LC_LC_Global_Ctrl2_lc_tenable_mask                                      (0x00000002)
#define  LC_LC_Global_Ctrl2_lc_valid_mask                                        (0x00000001)
#define  LC_LC_Global_Ctrl2_dummy_31(data)                                       (0x80000000&((data)<<31))
#define  LC_LC_Global_Ctrl2_lc_3d_mode(data)                                     (0x60000000&((data)<<29))
#define  LC_LC_Global_Ctrl2_lc_blk_hnum(data)                                    (0x1F000000&((data)<<24))
#define  LC_LC_Global_Ctrl2_dummy_23_21(data)                                    (0x00E00000&((data)<<21))
#define  LC_LC_Global_Ctrl2_lc_blk_vnum(data)                                    (0x001F0000&((data)<<16))
#define  LC_LC_Global_Ctrl2_dummy_15_8(data)                                     (0x0000FF00&((data)<<8))
#define  LC_LC_Global_Ctrl2_lc_subblk_mode(data)                                 (0x00000080&((data)<<7))
#define  LC_LC_Global_Ctrl2_lc_gcon_mode(data)                                   (0x00000040&((data)<<6))
#define  LC_LC_Global_Ctrl2_dummy_5_4(data)                                      (0x00000030&((data)<<4))
#define  LC_LC_Global_Ctrl2_lc_hist_mode(data)                                   (0x0000000C&((data)<<2))
#define  LC_LC_Global_Ctrl2_lc_tenable(data)                                     (0x00000002&((data)<<1))
#define  LC_LC_Global_Ctrl2_lc_valid(data)                                       (0x00000001&(data))
#define  LC_LC_Global_Ctrl2_get_dummy_31(data)                                   ((0x80000000&(data))>>31)
#define  LC_LC_Global_Ctrl2_get_lc_3d_mode(data)                                 ((0x60000000&(data))>>29)
#define  LC_LC_Global_Ctrl2_get_lc_blk_hnum(data)                                ((0x1F000000&(data))>>24)
#define  LC_LC_Global_Ctrl2_get_dummy_23_21(data)                                ((0x00E00000&(data))>>21)
#define  LC_LC_Global_Ctrl2_get_lc_blk_vnum(data)                                ((0x001F0000&(data))>>16)
#define  LC_LC_Global_Ctrl2_get_dummy_15_8(data)                                 ((0x0000FF00&(data))>>8)
#define  LC_LC_Global_Ctrl2_get_lc_subblk_mode(data)                             ((0x00000080&(data))>>7)
#define  LC_LC_Global_Ctrl2_get_lc_gcon_mode(data)                               ((0x00000040&(data))>>6)
#define  LC_LC_Global_Ctrl2_get_dummy_5_4(data)                                  ((0x00000030&(data))>>4)
#define  LC_LC_Global_Ctrl2_get_lc_hist_mode(data)                               ((0x0000000C&(data))>>2)
#define  LC_LC_Global_Ctrl2_get_lc_tenable(data)                                 ((0x00000002&(data))>>1)
#define  LC_LC_Global_Ctrl2_get_lc_valid(data)                                   (0x00000001&(data))

#define  LC_LC_Global_Ctrl3                                                      0x1802E00C
#define  LC_LC_Global_Ctrl3_reg_addr                                             "0xB802E00C"
#define  LC_LC_Global_Ctrl3_reg                                                  0xB802E00C
#define  LC_LC_Global_Ctrl3_inst_addr                                            "0x0003"
#define  set_LC_LC_Global_Ctrl3_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Ctrl3_reg)=data)
#define  get_LC_LC_Global_Ctrl3_reg                                              (*((volatile unsigned int*)LC_LC_Global_Ctrl3_reg))
#define  LC_LC_Global_Ctrl3_dummy_31_29_shift                                    (29)
#define  LC_LC_Global_Ctrl3_lc_blk_hsize_shift                                   (16)
#define  LC_LC_Global_Ctrl3_dummy_15_12_shift                                    (12)
#define  LC_LC_Global_Ctrl3_lc_blk_vsize_shift                                   (0)
#define  LC_LC_Global_Ctrl3_dummy_31_29_mask                                     (0xE0000000)
#define  LC_LC_Global_Ctrl3_lc_blk_hsize_mask                                    (0x1FFF0000)
#define  LC_LC_Global_Ctrl3_dummy_15_12_mask                                     (0x0000F000)
#define  LC_LC_Global_Ctrl3_lc_blk_vsize_mask                                    (0x00000FFF)
#define  LC_LC_Global_Ctrl3_dummy_31_29(data)                                    (0xE0000000&((data)<<29))
#define  LC_LC_Global_Ctrl3_lc_blk_hsize(data)                                   (0x1FFF0000&((data)<<16))
#define  LC_LC_Global_Ctrl3_dummy_15_12(data)                                    (0x0000F000&((data)<<12))
#define  LC_LC_Global_Ctrl3_lc_blk_vsize(data)                                   (0x00000FFF&(data))
#define  LC_LC_Global_Ctrl3_get_dummy_31_29(data)                                ((0xE0000000&(data))>>29)
#define  LC_LC_Global_Ctrl3_get_lc_blk_hsize(data)                               ((0x1FFF0000&(data))>>16)
#define  LC_LC_Global_Ctrl3_get_dummy_15_12(data)                                ((0x0000F000&(data))>>12)
#define  LC_LC_Global_Ctrl3_get_lc_blk_vsize(data)                               (0x00000FFF&(data))

#define  LC_LC_Global_Ctrl4                                                      0x1802E010
#define  LC_LC_Global_Ctrl4_reg_addr                                             "0xB802E010"
#define  LC_LC_Global_Ctrl4_reg                                                  0xB802E010
#define  LC_LC_Global_Ctrl4_inst_addr                                            "0x0004"
#define  set_LC_LC_Global_Ctrl4_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Ctrl4_reg)=data)
#define  get_LC_LC_Global_Ctrl4_reg                                              (*((volatile unsigned int*)LC_LC_Global_Ctrl4_reg))
#define  LC_LC_Global_Ctrl4_lc_drf_rme_7_shift                                   (31)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_6_shift                                   (30)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_5_shift                                   (29)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_4_shift                                   (28)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_3_shift                                   (27)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_2_shift                                   (26)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_1_shift                                   (25)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_0_shift                                   (24)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_7_shift                                    (23)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_6_shift                                    (22)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_5_shift                                    (21)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_4_shift                                    (20)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_3_shift                                    (19)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_2_shift                                    (18)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_1_shift                                    (17)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_0_shift                                    (16)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_7_shift                             (15)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_6_shift                             (14)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_5_shift                             (13)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_4_shift                             (12)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_3_shift                             (11)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_2_shift                             (10)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_1_shift                             (9)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_0_shift                             (8)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_7_shift                                 (7)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_6_shift                                 (6)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_5_shift                                 (5)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_4_shift                                 (4)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_3_shift                                 (3)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_2_shift                                 (2)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_1_shift                                 (1)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_0_shift                                 (0)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_7_mask                                    (0x80000000)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_6_mask                                    (0x40000000)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_5_mask                                    (0x20000000)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_4_mask                                    (0x10000000)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_3_mask                                    (0x08000000)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_2_mask                                    (0x04000000)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_1_mask                                    (0x02000000)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_0_mask                                    (0x01000000)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_7_mask                                     (0x00800000)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_6_mask                                     (0x00400000)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_5_mask                                     (0x00200000)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_4_mask                                     (0x00100000)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_3_mask                                     (0x00080000)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_2_mask                                     (0x00040000)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_1_mask                                     (0x00020000)
#define  LC_LC_Global_Ctrl4_lc_drf_ls_0_mask                                     (0x00010000)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_7_mask                              (0x00008000)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_6_mask                              (0x00004000)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_5_mask                              (0x00002000)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_4_mask                              (0x00001000)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_3_mask                              (0x00000800)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_2_mask                              (0x00000400)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_1_mask                              (0x00000200)
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_0_mask                              (0x00000100)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_7_mask                                  (0x00000080)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_6_mask                                  (0x00000040)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_5_mask                                  (0x00000020)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_4_mask                                  (0x00000010)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_3_mask                                  (0x00000008)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_2_mask                                  (0x00000004)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_1_mask                                  (0x00000002)
#define  LC_LC_Global_Ctrl4_lc_bist_fail_0_mask                                  (0x00000001)
#define  LC_LC_Global_Ctrl4_lc_drf_rme_7(data)                                   (0x80000000&((data)<<31))
#define  LC_LC_Global_Ctrl4_lc_drf_rme_6(data)                                   (0x40000000&((data)<<30))
#define  LC_LC_Global_Ctrl4_lc_drf_rme_5(data)                                   (0x20000000&((data)<<29))
#define  LC_LC_Global_Ctrl4_lc_drf_rme_4(data)                                   (0x10000000&((data)<<28))
#define  LC_LC_Global_Ctrl4_lc_drf_rme_3(data)                                   (0x08000000&((data)<<27))
#define  LC_LC_Global_Ctrl4_lc_drf_rme_2(data)                                   (0x04000000&((data)<<26))
#define  LC_LC_Global_Ctrl4_lc_drf_rme_1(data)                                   (0x02000000&((data)<<25))
#define  LC_LC_Global_Ctrl4_lc_drf_rme_0(data)                                   (0x01000000&((data)<<24))
#define  LC_LC_Global_Ctrl4_lc_drf_ls_7(data)                                    (0x00800000&((data)<<23))
#define  LC_LC_Global_Ctrl4_lc_drf_ls_6(data)                                    (0x00400000&((data)<<22))
#define  LC_LC_Global_Ctrl4_lc_drf_ls_5(data)                                    (0x00200000&((data)<<21))
#define  LC_LC_Global_Ctrl4_lc_drf_ls_4(data)                                    (0x00100000&((data)<<20))
#define  LC_LC_Global_Ctrl4_lc_drf_ls_3(data)                                    (0x00080000&((data)<<19))
#define  LC_LC_Global_Ctrl4_lc_drf_ls_2(data)                                    (0x00040000&((data)<<18))
#define  LC_LC_Global_Ctrl4_lc_drf_ls_1(data)                                    (0x00020000&((data)<<17))
#define  LC_LC_Global_Ctrl4_lc_drf_ls_0(data)                                    (0x00010000&((data)<<16))
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_7(data)                             (0x00008000&((data)<<15))
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_6(data)                             (0x00004000&((data)<<14))
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_5(data)                             (0x00002000&((data)<<13))
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_4(data)                             (0x00001000&((data)<<12))
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_3(data)                             (0x00000800&((data)<<11))
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_2(data)                             (0x00000400&((data)<<10))
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_1(data)                             (0x00000200&((data)<<9))
#define  LC_LC_Global_Ctrl4_lc_drf_bist_fail_0(data)                             (0x00000100&((data)<<8))
#define  LC_LC_Global_Ctrl4_lc_bist_fail_7(data)                                 (0x00000080&((data)<<7))
#define  LC_LC_Global_Ctrl4_lc_bist_fail_6(data)                                 (0x00000040&((data)<<6))
#define  LC_LC_Global_Ctrl4_lc_bist_fail_5(data)                                 (0x00000020&((data)<<5))
#define  LC_LC_Global_Ctrl4_lc_bist_fail_4(data)                                 (0x00000010&((data)<<4))
#define  LC_LC_Global_Ctrl4_lc_bist_fail_3(data)                                 (0x00000008&((data)<<3))
#define  LC_LC_Global_Ctrl4_lc_bist_fail_2(data)                                 (0x00000004&((data)<<2))
#define  LC_LC_Global_Ctrl4_lc_bist_fail_1(data)                                 (0x00000002&((data)<<1))
#define  LC_LC_Global_Ctrl4_lc_bist_fail_0(data)                                 (0x00000001&(data))
#define  LC_LC_Global_Ctrl4_get_lc_drf_rme_7(data)                               ((0x80000000&(data))>>31)
#define  LC_LC_Global_Ctrl4_get_lc_drf_rme_6(data)                               ((0x40000000&(data))>>30)
#define  LC_LC_Global_Ctrl4_get_lc_drf_rme_5(data)                               ((0x20000000&(data))>>29)
#define  LC_LC_Global_Ctrl4_get_lc_drf_rme_4(data)                               ((0x10000000&(data))>>28)
#define  LC_LC_Global_Ctrl4_get_lc_drf_rme_3(data)                               ((0x08000000&(data))>>27)
#define  LC_LC_Global_Ctrl4_get_lc_drf_rme_2(data)                               ((0x04000000&(data))>>26)
#define  LC_LC_Global_Ctrl4_get_lc_drf_rme_1(data)                               ((0x02000000&(data))>>25)
#define  LC_LC_Global_Ctrl4_get_lc_drf_rme_0(data)                               ((0x01000000&(data))>>24)
#define  LC_LC_Global_Ctrl4_get_lc_drf_ls_7(data)                                ((0x00800000&(data))>>23)
#define  LC_LC_Global_Ctrl4_get_lc_drf_ls_6(data)                                ((0x00400000&(data))>>22)
#define  LC_LC_Global_Ctrl4_get_lc_drf_ls_5(data)                                ((0x00200000&(data))>>21)
#define  LC_LC_Global_Ctrl4_get_lc_drf_ls_4(data)                                ((0x00100000&(data))>>20)
#define  LC_LC_Global_Ctrl4_get_lc_drf_ls_3(data)                                ((0x00080000&(data))>>19)
#define  LC_LC_Global_Ctrl4_get_lc_drf_ls_2(data)                                ((0x00040000&(data))>>18)
#define  LC_LC_Global_Ctrl4_get_lc_drf_ls_1(data)                                ((0x00020000&(data))>>17)
#define  LC_LC_Global_Ctrl4_get_lc_drf_ls_0(data)                                ((0x00010000&(data))>>16)
#define  LC_LC_Global_Ctrl4_get_lc_drf_bist_fail_7(data)                         ((0x00008000&(data))>>15)
#define  LC_LC_Global_Ctrl4_get_lc_drf_bist_fail_6(data)                         ((0x00004000&(data))>>14)
#define  LC_LC_Global_Ctrl4_get_lc_drf_bist_fail_5(data)                         ((0x00002000&(data))>>13)
#define  LC_LC_Global_Ctrl4_get_lc_drf_bist_fail_4(data)                         ((0x00001000&(data))>>12)
#define  LC_LC_Global_Ctrl4_get_lc_drf_bist_fail_3(data)                         ((0x00000800&(data))>>11)
#define  LC_LC_Global_Ctrl4_get_lc_drf_bist_fail_2(data)                         ((0x00000400&(data))>>10)
#define  LC_LC_Global_Ctrl4_get_lc_drf_bist_fail_1(data)                         ((0x00000200&(data))>>9)
#define  LC_LC_Global_Ctrl4_get_lc_drf_bist_fail_0(data)                         ((0x00000100&(data))>>8)
#define  LC_LC_Global_Ctrl4_get_lc_bist_fail_7(data)                             ((0x00000080&(data))>>7)
#define  LC_LC_Global_Ctrl4_get_lc_bist_fail_6(data)                             ((0x00000040&(data))>>6)
#define  LC_LC_Global_Ctrl4_get_lc_bist_fail_5(data)                             ((0x00000020&(data))>>5)
#define  LC_LC_Global_Ctrl4_get_lc_bist_fail_4(data)                             ((0x00000010&(data))>>4)
#define  LC_LC_Global_Ctrl4_get_lc_bist_fail_3(data)                             ((0x00000008&(data))>>3)
#define  LC_LC_Global_Ctrl4_get_lc_bist_fail_2(data)                             ((0x00000004&(data))>>2)
#define  LC_LC_Global_Ctrl4_get_lc_bist_fail_1(data)                             ((0x00000002&(data))>>1)
#define  LC_LC_Global_Ctrl4_get_lc_bist_fail_0(data)                             (0x00000001&(data))

#define  LC_LC_Global_Ctrl5                                                      0x1802E014
#define  LC_LC_Global_Ctrl5_reg_addr                                             "0xB802E014"
#define  LC_LC_Global_Ctrl5_reg                                                  0xB802E014
#define  LC_LC_Global_Ctrl5_inst_addr                                            "0x0005"
#define  set_LC_LC_Global_Ctrl5_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Ctrl5_reg)=data)
#define  get_LC_LC_Global_Ctrl5_reg                                              (*((volatile unsigned int*)LC_LC_Global_Ctrl5_reg))
#define  LC_LC_Global_Ctrl5_lc_drf_rm_7_shift                                    (28)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_6_shift                                    (24)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_5_shift                                    (20)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_4_shift                                    (16)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_3_shift                                    (12)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_2_shift                                    (8)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_1_shift                                    (4)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_0_shift                                    (0)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_7_mask                                     (0xF0000000)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_6_mask                                     (0x0F000000)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_5_mask                                     (0x00F00000)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_4_mask                                     (0x000F0000)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_3_mask                                     (0x0000F000)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_2_mask                                     (0x00000F00)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_1_mask                                     (0x000000F0)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_0_mask                                     (0x0000000F)
#define  LC_LC_Global_Ctrl5_lc_drf_rm_7(data)                                    (0xF0000000&((data)<<28))
#define  LC_LC_Global_Ctrl5_lc_drf_rm_6(data)                                    (0x0F000000&((data)<<24))
#define  LC_LC_Global_Ctrl5_lc_drf_rm_5(data)                                    (0x00F00000&((data)<<20))
#define  LC_LC_Global_Ctrl5_lc_drf_rm_4(data)                                    (0x000F0000&((data)<<16))
#define  LC_LC_Global_Ctrl5_lc_drf_rm_3(data)                                    (0x0000F000&((data)<<12))
#define  LC_LC_Global_Ctrl5_lc_drf_rm_2(data)                                    (0x00000F00&((data)<<8))
#define  LC_LC_Global_Ctrl5_lc_drf_rm_1(data)                                    (0x000000F0&((data)<<4))
#define  LC_LC_Global_Ctrl5_lc_drf_rm_0(data)                                    (0x0000000F&(data))
#define  LC_LC_Global_Ctrl5_get_lc_drf_rm_7(data)                                ((0xF0000000&(data))>>28)
#define  LC_LC_Global_Ctrl5_get_lc_drf_rm_6(data)                                ((0x0F000000&(data))>>24)
#define  LC_LC_Global_Ctrl5_get_lc_drf_rm_5(data)                                ((0x00F00000&(data))>>20)
#define  LC_LC_Global_Ctrl5_get_lc_drf_rm_4(data)                                ((0x000F0000&(data))>>16)
#define  LC_LC_Global_Ctrl5_get_lc_drf_rm_3(data)                                ((0x0000F000&(data))>>12)
#define  LC_LC_Global_Ctrl5_get_lc_drf_rm_2(data)                                ((0x00000F00&(data))>>8)
#define  LC_LC_Global_Ctrl5_get_lc_drf_rm_1(data)                                ((0x000000F0&(data))>>4)
#define  LC_LC_Global_Ctrl5_get_lc_drf_rm_0(data)                                (0x0000000F&(data))

#define  LC_LC_Global_Max_Ctrl                                                   0x1802E018
#define  LC_LC_Global_Max_Ctrl_reg_addr                                          "0xB802E018"
#define  LC_LC_Global_Max_Ctrl_reg                                               0xB802E018
#define  LC_LC_Global_Max_Ctrl_inst_addr                                         "0x0006"
#define  set_LC_LC_Global_Max_Ctrl_reg(data)                                     (*((volatile unsigned int*)LC_LC_Global_Max_Ctrl_reg)=data)
#define  get_LC_LC_Global_Max_Ctrl_reg                                           (*((volatile unsigned int*)LC_LC_Global_Max_Ctrl_reg))
#define  LC_LC_Global_Max_Ctrl_lc_global_max_shift                               (0)
#define  LC_LC_Global_Max_Ctrl_lc_global_max_mask                                (0x00000FFF)
#define  LC_LC_Global_Max_Ctrl_lc_global_max(data)                               (0x00000FFF&(data))
#define  LC_LC_Global_Max_Ctrl_get_lc_global_max(data)                           (0x00000FFF&(data))

#define  LC_LC_Global_Hist1                                                      0x1802E01C
#define  LC_LC_Global_Hist1_reg_addr                                             "0xB802E01C"
#define  LC_LC_Global_Hist1_reg                                                  0xB802E01C
#define  LC_LC_Global_Hist1_inst_addr                                            "0x0007"
#define  set_LC_LC_Global_Hist1_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Hist1_reg)=data)
#define  get_LC_LC_Global_Hist1_reg                                              (*((volatile unsigned int*)LC_LC_Global_Hist1_reg))
#define  LC_LC_Global_Hist1_lc_global_hist0_shift                                (16)
#define  LC_LC_Global_Hist1_lc_global_hist1_shift                                (0)
#define  LC_LC_Global_Hist1_lc_global_hist0_mask                                 (0xFFFF0000)
#define  LC_LC_Global_Hist1_lc_global_hist1_mask                                 (0x0000FFFF)
#define  LC_LC_Global_Hist1_lc_global_hist0(data)                                (0xFFFF0000&((data)<<16))
#define  LC_LC_Global_Hist1_lc_global_hist1(data)                                (0x0000FFFF&(data))
#define  LC_LC_Global_Hist1_get_lc_global_hist0(data)                            ((0xFFFF0000&(data))>>16)
#define  LC_LC_Global_Hist1_get_lc_global_hist1(data)                            (0x0000FFFF&(data))

#define  LC_LC_Global_Hist2                                                      0x1802E020
#define  LC_LC_Global_Hist2_reg_addr                                             "0xB802E020"
#define  LC_LC_Global_Hist2_reg                                                  0xB802E020
#define  LC_LC_Global_Hist2_inst_addr                                            "0x0008"
#define  set_LC_LC_Global_Hist2_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Hist2_reg)=data)
#define  get_LC_LC_Global_Hist2_reg                                              (*((volatile unsigned int*)LC_LC_Global_Hist2_reg))
#define  LC_LC_Global_Hist2_lc_global_hist2_shift                                (16)
#define  LC_LC_Global_Hist2_lc_global_hist3_shift                                (0)
#define  LC_LC_Global_Hist2_lc_global_hist2_mask                                 (0xFFFF0000)
#define  LC_LC_Global_Hist2_lc_global_hist3_mask                                 (0x0000FFFF)
#define  LC_LC_Global_Hist2_lc_global_hist2(data)                                (0xFFFF0000&((data)<<16))
#define  LC_LC_Global_Hist2_lc_global_hist3(data)                                (0x0000FFFF&(data))
#define  LC_LC_Global_Hist2_get_lc_global_hist2(data)                            ((0xFFFF0000&(data))>>16)
#define  LC_LC_Global_Hist2_get_lc_global_hist3(data)                            (0x0000FFFF&(data))

#define  LC_LC_Global_Hist3                                                      0x1802E024
#define  LC_LC_Global_Hist3_reg_addr                                             "0xB802E024"
#define  LC_LC_Global_Hist3_reg                                                  0xB802E024
#define  LC_LC_Global_Hist3_inst_addr                                            "0x0009"
#define  set_LC_LC_Global_Hist3_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Hist3_reg)=data)
#define  get_LC_LC_Global_Hist3_reg                                              (*((volatile unsigned int*)LC_LC_Global_Hist3_reg))
#define  LC_LC_Global_Hist3_lc_global_hist4_shift                                (16)
#define  LC_LC_Global_Hist3_lc_global_hist5_shift                                (0)
#define  LC_LC_Global_Hist3_lc_global_hist4_mask                                 (0xFFFF0000)
#define  LC_LC_Global_Hist3_lc_global_hist5_mask                                 (0x0000FFFF)
#define  LC_LC_Global_Hist3_lc_global_hist4(data)                                (0xFFFF0000&((data)<<16))
#define  LC_LC_Global_Hist3_lc_global_hist5(data)                                (0x0000FFFF&(data))
#define  LC_LC_Global_Hist3_get_lc_global_hist4(data)                            ((0xFFFF0000&(data))>>16)
#define  LC_LC_Global_Hist3_get_lc_global_hist5(data)                            (0x0000FFFF&(data))

#define  LC_LC_Global_Hist4                                                      0x1802E028
#define  LC_LC_Global_Hist4_reg_addr                                             "0xB802E028"
#define  LC_LC_Global_Hist4_reg                                                  0xB802E028
#define  LC_LC_Global_Hist4_inst_addr                                            "0x000A"
#define  set_LC_LC_Global_Hist4_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Hist4_reg)=data)
#define  get_LC_LC_Global_Hist4_reg                                              (*((volatile unsigned int*)LC_LC_Global_Hist4_reg))
#define  LC_LC_Global_Hist4_lc_global_hist6_shift                                (16)
#define  LC_LC_Global_Hist4_lc_global_hist7_shift                                (0)
#define  LC_LC_Global_Hist4_lc_global_hist6_mask                                 (0xFFFF0000)
#define  LC_LC_Global_Hist4_lc_global_hist7_mask                                 (0x0000FFFF)
#define  LC_LC_Global_Hist4_lc_global_hist6(data)                                (0xFFFF0000&((data)<<16))
#define  LC_LC_Global_Hist4_lc_global_hist7(data)                                (0x0000FFFF&(data))
#define  LC_LC_Global_Hist4_get_lc_global_hist6(data)                            ((0xFFFF0000&(data))>>16)
#define  LC_LC_Global_Hist4_get_lc_global_hist7(data)                            (0x0000FFFF&(data))

#define  LC_LC_Global_Hist5                                                      0x1802E02C
#define  LC_LC_Global_Hist5_reg_addr                                             "0xB802E02C"
#define  LC_LC_Global_Hist5_reg                                                  0xB802E02C
#define  LC_LC_Global_Hist5_inst_addr                                            "0x000B"
#define  set_LC_LC_Global_Hist5_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Hist5_reg)=data)
#define  get_LC_LC_Global_Hist5_reg                                              (*((volatile unsigned int*)LC_LC_Global_Hist5_reg))
#define  LC_LC_Global_Hist5_lc_global_hist8_shift                                (16)
#define  LC_LC_Global_Hist5_lc_global_hist9_shift                                (0)
#define  LC_LC_Global_Hist5_lc_global_hist8_mask                                 (0xFFFF0000)
#define  LC_LC_Global_Hist5_lc_global_hist9_mask                                 (0x0000FFFF)
#define  LC_LC_Global_Hist5_lc_global_hist8(data)                                (0xFFFF0000&((data)<<16))
#define  LC_LC_Global_Hist5_lc_global_hist9(data)                                (0x0000FFFF&(data))
#define  LC_LC_Global_Hist5_get_lc_global_hist8(data)                            ((0xFFFF0000&(data))>>16)
#define  LC_LC_Global_Hist5_get_lc_global_hist9(data)                            (0x0000FFFF&(data))

#define  LC_LC_Global_Hist6                                                      0x1802E030
#define  LC_LC_Global_Hist6_reg_addr                                             "0xB802E030"
#define  LC_LC_Global_Hist6_reg                                                  0xB802E030
#define  LC_LC_Global_Hist6_inst_addr                                            "0x000C"
#define  set_LC_LC_Global_Hist6_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Hist6_reg)=data)
#define  get_LC_LC_Global_Hist6_reg                                              (*((volatile unsigned int*)LC_LC_Global_Hist6_reg))
#define  LC_LC_Global_Hist6_lc_global_hist10_shift                               (16)
#define  LC_LC_Global_Hist6_lc_global_hist11_shift                               (0)
#define  LC_LC_Global_Hist6_lc_global_hist10_mask                                (0xFFFF0000)
#define  LC_LC_Global_Hist6_lc_global_hist11_mask                                (0x0000FFFF)
#define  LC_LC_Global_Hist6_lc_global_hist10(data)                               (0xFFFF0000&((data)<<16))
#define  LC_LC_Global_Hist6_lc_global_hist11(data)                               (0x0000FFFF&(data))
#define  LC_LC_Global_Hist6_get_lc_global_hist10(data)                           ((0xFFFF0000&(data))>>16)
#define  LC_LC_Global_Hist6_get_lc_global_hist11(data)                           (0x0000FFFF&(data))

#define  LC_LC_Global_Hist7                                                      0x1802E034
#define  LC_LC_Global_Hist7_reg_addr                                             "0xB802E034"
#define  LC_LC_Global_Hist7_reg                                                  0xB802E034
#define  LC_LC_Global_Hist7_inst_addr                                            "0x000D"
#define  set_LC_LC_Global_Hist7_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Hist7_reg)=data)
#define  get_LC_LC_Global_Hist7_reg                                              (*((volatile unsigned int*)LC_LC_Global_Hist7_reg))
#define  LC_LC_Global_Hist7_lc_global_hist12_shift                               (16)
#define  LC_LC_Global_Hist7_lc_global_hist13_shift                               (0)
#define  LC_LC_Global_Hist7_lc_global_hist12_mask                                (0xFFFF0000)
#define  LC_LC_Global_Hist7_lc_global_hist13_mask                                (0x0000FFFF)
#define  LC_LC_Global_Hist7_lc_global_hist12(data)                               (0xFFFF0000&((data)<<16))
#define  LC_LC_Global_Hist7_lc_global_hist13(data)                               (0x0000FFFF&(data))
#define  LC_LC_Global_Hist7_get_lc_global_hist12(data)                           ((0xFFFF0000&(data))>>16)
#define  LC_LC_Global_Hist7_get_lc_global_hist13(data)                           (0x0000FFFF&(data))

#define  LC_LC_Global_Hist8                                                      0x1802E038
#define  LC_LC_Global_Hist8_reg_addr                                             "0xB802E038"
#define  LC_LC_Global_Hist8_reg                                                  0xB802E038
#define  LC_LC_Global_Hist8_inst_addr                                            "0x000E"
#define  set_LC_LC_Global_Hist8_reg(data)                                        (*((volatile unsigned int*)LC_LC_Global_Hist8_reg)=data)
#define  get_LC_LC_Global_Hist8_reg                                              (*((volatile unsigned int*)LC_LC_Global_Hist8_reg))
#define  LC_LC_Global_Hist8_lc_global_hist14_shift                               (16)
#define  LC_LC_Global_Hist8_lc_global_hist15_shift                               (0)
#define  LC_LC_Global_Hist8_lc_global_hist14_mask                                (0xFFFF0000)
#define  LC_LC_Global_Hist8_lc_global_hist15_mask                                (0x0000FFFF)
#define  LC_LC_Global_Hist8_lc_global_hist14(data)                               (0xFFFF0000&((data)<<16))
#define  LC_LC_Global_Hist8_lc_global_hist15(data)                               (0x0000FFFF&(data))
#define  LC_LC_Global_Hist8_get_lc_global_hist14(data)                           ((0xFFFF0000&(data))>>16)
#define  LC_LC_Global_Hist8_get_lc_global_hist15(data)                           (0x0000FFFF&(data))

#define  LC_LC_Decision_Ctrl1                                                    0x1802E03C
#define  LC_LC_Decision_Ctrl1_reg_addr                                           "0xB802E03C"
#define  LC_LC_Decision_Ctrl1_reg                                                0xB802E03C
#define  LC_LC_Decision_Ctrl1_inst_addr                                          "0x000F"
#define  set_LC_LC_Decision_Ctrl1_reg(data)                                      (*((volatile unsigned int*)LC_LC_Decision_Ctrl1_reg)=data)
#define  get_LC_LC_Decision_Ctrl1_reg                                            (*((volatile unsigned int*)LC_LC_Decision_Ctrl1_reg))
#define  LC_LC_Decision_Ctrl1_lc_maxgain_shift                                   (24)
#define  LC_LC_Decision_Ctrl1_lc_avegain_shift                                   (16)
#define  LC_LC_Decision_Ctrl1_lc_histshiftbit_shift                              (0)
#define  LC_LC_Decision_Ctrl1_lc_maxgain_mask                                    (0x3F000000)
#define  LC_LC_Decision_Ctrl1_lc_avegain_mask                                    (0x003F0000)
#define  LC_LC_Decision_Ctrl1_lc_histshiftbit_mask                               (0x0000000F)
#define  LC_LC_Decision_Ctrl1_lc_maxgain(data)                                   (0x3F000000&((data)<<24))
#define  LC_LC_Decision_Ctrl1_lc_avegain(data)                                   (0x003F0000&((data)<<16))
#define  LC_LC_Decision_Ctrl1_lc_histshiftbit(data)                              (0x0000000F&(data))
#define  LC_LC_Decision_Ctrl1_get_lc_maxgain(data)                               ((0x3F000000&(data))>>24)
#define  LC_LC_Decision_Ctrl1_get_lc_avegain(data)                               ((0x003F0000&(data))>>16)
#define  LC_LC_Decision_Ctrl1_get_lc_histshiftbit(data)                          (0x0000000F&(data))

#define  LC_LC_Decision_Ctrl2                                                    0x1802E040
#define  LC_LC_Decision_Ctrl2_reg_addr                                           "0xB802E040"
#define  LC_LC_Decision_Ctrl2_reg                                                0xB802E040
#define  LC_LC_Decision_Ctrl2_inst_addr                                          "0x0010"
#define  set_LC_LC_Decision_Ctrl2_reg(data)                                      (*((volatile unsigned int*)LC_LC_Decision_Ctrl2_reg)=data)
#define  get_LC_LC_Decision_Ctrl2_reg                                            (*((volatile unsigned int*)LC_LC_Decision_Ctrl2_reg))
#define  LC_LC_Decision_Ctrl2_lc_hist0gain_shift                                 (24)
#define  LC_LC_Decision_Ctrl2_lc_hist1gain_shift                                 (16)
#define  LC_LC_Decision_Ctrl2_lc_hist2gain_shift                                 (8)
#define  LC_LC_Decision_Ctrl2_lc_hist3gain_shift                                 (0)
#define  LC_LC_Decision_Ctrl2_lc_hist0gain_mask                                  (0x3F000000)
#define  LC_LC_Decision_Ctrl2_lc_hist1gain_mask                                  (0x003F0000)
#define  LC_LC_Decision_Ctrl2_lc_hist2gain_mask                                  (0x00003F00)
#define  LC_LC_Decision_Ctrl2_lc_hist3gain_mask                                  (0x0000003F)
#define  LC_LC_Decision_Ctrl2_lc_hist0gain(data)                                 (0x3F000000&((data)<<24))
#define  LC_LC_Decision_Ctrl2_lc_hist1gain(data)                                 (0x003F0000&((data)<<16))
#define  LC_LC_Decision_Ctrl2_lc_hist2gain(data)                                 (0x00003F00&((data)<<8))
#define  LC_LC_Decision_Ctrl2_lc_hist3gain(data)                                 (0x0000003F&(data))
#define  LC_LC_Decision_Ctrl2_get_lc_hist0gain(data)                             ((0x3F000000&(data))>>24)
#define  LC_LC_Decision_Ctrl2_get_lc_hist1gain(data)                             ((0x003F0000&(data))>>16)
#define  LC_LC_Decision_Ctrl2_get_lc_hist2gain(data)                             ((0x00003F00&(data))>>8)
#define  LC_LC_Decision_Ctrl2_get_lc_hist3gain(data)                             (0x0000003F&(data))

#define  LC_LC_Decision_Ctrl3                                                    0x1802E044
#define  LC_LC_Decision_Ctrl3_reg_addr                                           "0xB802E044"
#define  LC_LC_Decision_Ctrl3_reg                                                0xB802E044
#define  LC_LC_Decision_Ctrl3_inst_addr                                          "0x0011"
#define  set_LC_LC_Decision_Ctrl3_reg(data)                                      (*((volatile unsigned int*)LC_LC_Decision_Ctrl3_reg)=data)
#define  get_LC_LC_Decision_Ctrl3_reg                                            (*((volatile unsigned int*)LC_LC_Decision_Ctrl3_reg))
#define  LC_LC_Decision_Ctrl3_lc_hist4gain_shift                                 (24)
#define  LC_LC_Decision_Ctrl3_lc_hist5gain_shift                                 (16)
#define  LC_LC_Decision_Ctrl3_lc_hist6gain_shift                                 (8)
#define  LC_LC_Decision_Ctrl3_lc_hist7gain_shift                                 (0)
#define  LC_LC_Decision_Ctrl3_lc_hist4gain_mask                                  (0x3F000000)
#define  LC_LC_Decision_Ctrl3_lc_hist5gain_mask                                  (0x003F0000)
#define  LC_LC_Decision_Ctrl3_lc_hist6gain_mask                                  (0x00003F00)
#define  LC_LC_Decision_Ctrl3_lc_hist7gain_mask                                  (0x0000003F)
#define  LC_LC_Decision_Ctrl3_lc_hist4gain(data)                                 (0x3F000000&((data)<<24))
#define  LC_LC_Decision_Ctrl3_lc_hist5gain(data)                                 (0x003F0000&((data)<<16))
#define  LC_LC_Decision_Ctrl3_lc_hist6gain(data)                                 (0x00003F00&((data)<<8))
#define  LC_LC_Decision_Ctrl3_lc_hist7gain(data)                                 (0x0000003F&(data))
#define  LC_LC_Decision_Ctrl3_get_lc_hist4gain(data)                             ((0x3F000000&(data))>>24)
#define  LC_LC_Decision_Ctrl3_get_lc_hist5gain(data)                             ((0x003F0000&(data))>>16)
#define  LC_LC_Decision_Ctrl3_get_lc_hist6gain(data)                             ((0x00003F00&(data))>>8)
#define  LC_LC_Decision_Ctrl3_get_lc_hist7gain(data)                             (0x0000003F&(data))

#define  LC_LC_Decision_Ctrl4                                                    0x1802E048
#define  LC_LC_Decision_Ctrl4_reg_addr                                           "0xB802E048"
#define  LC_LC_Decision_Ctrl4_reg                                                0xB802E048
#define  LC_LC_Decision_Ctrl4_inst_addr                                          "0x0012"
#define  set_LC_LC_Decision_Ctrl4_reg(data)                                      (*((volatile unsigned int*)LC_LC_Decision_Ctrl4_reg)=data)
#define  get_LC_LC_Decision_Ctrl4_reg                                            (*((volatile unsigned int*)LC_LC_Decision_Ctrl4_reg))
#define  LC_LC_Decision_Ctrl4_lc_decaccess_addr_shift                            (16)
#define  LC_LC_Decision_Ctrl4_lc_decaccess_en_shift                              (0)
#define  LC_LC_Decision_Ctrl4_lc_decaccess_addr_mask                             (0x01FF0000)
#define  LC_LC_Decision_Ctrl4_lc_decaccess_en_mask                               (0x00000001)
#define  LC_LC_Decision_Ctrl4_lc_decaccess_addr(data)                            (0x01FF0000&((data)<<16))
#define  LC_LC_Decision_Ctrl4_lc_decaccess_en(data)                              (0x00000001&(data))
#define  LC_LC_Decision_Ctrl4_get_lc_decaccess_addr(data)                        ((0x01FF0000&(data))>>16)
#define  LC_LC_Decision_Ctrl4_get_lc_decaccess_en(data)                          (0x00000001&(data))

#define  LC_LC_Decision_Ctrl5                                                    0x1802E04C
#define  LC_LC_Decision_Ctrl5_reg_addr                                           "0xB802E04C"
#define  LC_LC_Decision_Ctrl5_reg                                                0xB802E04C
#define  LC_LC_Decision_Ctrl5_inst_addr                                          "0x0013"
#define  set_LC_LC_Decision_Ctrl5_reg(data)                                      (*((volatile unsigned int*)LC_LC_Decision_Ctrl5_reg)=data)
#define  get_LC_LC_Decision_Ctrl5_reg                                            (*((volatile unsigned int*)LC_LC_Decision_Ctrl5_reg))
#define  LC_LC_Decision_Ctrl5_lc_decaccess_data_shift                            (0)
#define  LC_LC_Decision_Ctrl5_lc_decaccess_data_mask                             (0x3FFFFFFF)
#define  LC_LC_Decision_Ctrl5_lc_decaccess_data(data)                            (0x3FFFFFFF&(data))
#define  LC_LC_Decision_Ctrl5_get_lc_decaccess_data(data)                        (0x3FFFFFFF&(data))

#define  LC_LC_Spatial_Ctrl1                                                     0x1802E050
#define  LC_LC_Spatial_Ctrl1_reg_addr                                            "0xB802E050"
#define  LC_LC_Spatial_Ctrl1_reg                                                 0xB802E050
#define  LC_LC_Spatial_Ctrl1_inst_addr                                           "0x0014"
#define  set_LC_LC_Spatial_Ctrl1_reg(data)                                       (*((volatile unsigned int*)LC_LC_Spatial_Ctrl1_reg)=data)
#define  get_LC_LC_Spatial_Ctrl1_reg                                             (*((volatile unsigned int*)LC_LC_Spatial_Ctrl1_reg))
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef0_shift                               (28)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef1_shift                               (24)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef2_shift                               (20)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef3_shift                               (16)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef4_shift                               (12)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef5_shift                               (8)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef6_shift                               (4)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef7_shift                               (0)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef0_mask                                (0xF0000000)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef1_mask                                (0x0F000000)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef2_mask                                (0x00F00000)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef3_mask                                (0x000F0000)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef4_mask                                (0x0000F000)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef5_mask                                (0x00000F00)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef6_mask                                (0x000000F0)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef7_mask                                (0x0000000F)
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef0(data)                               (0xF0000000&((data)<<28))
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef1(data)                               (0x0F000000&((data)<<24))
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef2(data)                               (0x00F00000&((data)<<20))
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef3(data)                               (0x000F0000&((data)<<16))
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef4(data)                               (0x0000F000&((data)<<12))
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef5(data)                               (0x00000F00&((data)<<8))
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef6(data)                               (0x000000F0&((data)<<4))
#define  LC_LC_Spatial_Ctrl1_lc_spatialcoef7(data)                               (0x0000000F&(data))
#define  LC_LC_Spatial_Ctrl1_get_lc_spatialcoef0(data)                           ((0xF0000000&(data))>>28)
#define  LC_LC_Spatial_Ctrl1_get_lc_spatialcoef1(data)                           ((0x0F000000&(data))>>24)
#define  LC_LC_Spatial_Ctrl1_get_lc_spatialcoef2(data)                           ((0x00F00000&(data))>>20)
#define  LC_LC_Spatial_Ctrl1_get_lc_spatialcoef3(data)                           ((0x000F0000&(data))>>16)
#define  LC_LC_Spatial_Ctrl1_get_lc_spatialcoef4(data)                           ((0x0000F000&(data))>>12)
#define  LC_LC_Spatial_Ctrl1_get_lc_spatialcoef5(data)                           ((0x00000F00&(data))>>8)
#define  LC_LC_Spatial_Ctrl1_get_lc_spatialcoef6(data)                           ((0x000000F0&(data))>>4)
#define  LC_LC_Spatial_Ctrl1_get_lc_spatialcoef7(data)                           (0x0000000F&(data))

#define  LC_LC_Spatial_Ctrl2                                                     0x1802E054
#define  LC_LC_Spatial_Ctrl2_reg_addr                                            "0xB802E054"
#define  LC_LC_Spatial_Ctrl2_reg                                                 0xB802E054
#define  LC_LC_Spatial_Ctrl2_inst_addr                                           "0x0015"
#define  set_LC_LC_Spatial_Ctrl2_reg(data)                                       (*((volatile unsigned int*)LC_LC_Spatial_Ctrl2_reg)=data)
#define  get_LC_LC_Spatial_Ctrl2_reg                                             (*((volatile unsigned int*)LC_LC_Spatial_Ctrl2_reg))
#define  LC_LC_Spatial_Ctrl2_lc_spatialcoef8_shift                               (28)
#define  LC_LC_Spatial_Ctrl2_lc_spatialcoef9_shift                               (24)
#define  LC_LC_Spatial_Ctrl2_lc_spatialcoef10_shift                              (20)
#define  LC_LC_Spatial_Ctrl2_dummy_19_2_shift                                    (2)
#define  LC_LC_Spatial_Ctrl2_lc_spatialremapbusy_shift                           (1)
#define  LC_LC_Spatial_Ctrl2_lc_spatialremapen_shift                             (0)
#define  LC_LC_Spatial_Ctrl2_lc_spatialcoef8_mask                                (0xF0000000)
#define  LC_LC_Spatial_Ctrl2_lc_spatialcoef9_mask                                (0x0F000000)
#define  LC_LC_Spatial_Ctrl2_lc_spatialcoef10_mask                               (0x00F00000)
#define  LC_LC_Spatial_Ctrl2_dummy_19_2_mask                                     (0x000FFFFC)
#define  LC_LC_Spatial_Ctrl2_lc_spatialremapbusy_mask                            (0x00000002)
#define  LC_LC_Spatial_Ctrl2_lc_spatialremapen_mask                              (0x00000001)
#define  LC_LC_Spatial_Ctrl2_lc_spatialcoef8(data)                               (0xF0000000&((data)<<28))
#define  LC_LC_Spatial_Ctrl2_lc_spatialcoef9(data)                               (0x0F000000&((data)<<24))
#define  LC_LC_Spatial_Ctrl2_lc_spatialcoef10(data)                              (0x00F00000&((data)<<20))
#define  LC_LC_Spatial_Ctrl2_dummy_19_2(data)                                    (0x000FFFFC&((data)<<2))
#define  LC_LC_Spatial_Ctrl2_lc_spatialremapbusy(data)                           (0x00000002&((data)<<1))
#define  LC_LC_Spatial_Ctrl2_lc_spatialremapen(data)                             (0x00000001&(data))
#define  LC_LC_Spatial_Ctrl2_get_lc_spatialcoef8(data)                           ((0xF0000000&(data))>>28)
#define  LC_LC_Spatial_Ctrl2_get_lc_spatialcoef9(data)                           ((0x0F000000&(data))>>24)
#define  LC_LC_Spatial_Ctrl2_get_lc_spatialcoef10(data)                          ((0x00F00000&(data))>>20)
#define  LC_LC_Spatial_Ctrl2_get_dummy_19_2(data)                                ((0x000FFFFC&(data))>>2)
#define  LC_LC_Spatial_Ctrl2_get_lc_spatialremapbusy(data)                       ((0x00000002&(data))>>1)
#define  LC_LC_Spatial_Ctrl2_get_lc_spatialremapen(data)                         (0x00000001&(data))

#define  LC_LC_Spatial_Ctrl3                                                     0x1802E058
#define  LC_LC_Spatial_Ctrl3_reg_addr                                            "0xB802E058"
#define  LC_LC_Spatial_Ctrl3_reg                                                 0xB802E058
#define  LC_LC_Spatial_Ctrl3_inst_addr                                           "0x0016"
#define  set_LC_LC_Spatial_Ctrl3_reg(data)                                       (*((volatile unsigned int*)LC_LC_Spatial_Ctrl3_reg)=data)
#define  get_LC_LC_Spatial_Ctrl3_reg                                             (*((volatile unsigned int*)LC_LC_Spatial_Ctrl3_reg))
#define  LC_LC_Spatial_Ctrl3_lc_spatialremapadr_shift                            (24)
#define  LC_LC_Spatial_Ctrl3_lc_spatialremaptab1_shift                           (12)
#define  LC_LC_Spatial_Ctrl3_lc_spatialremaptab0_shift                           (0)
#define  LC_LC_Spatial_Ctrl3_lc_spatialremapadr_mask                             (0x1F000000)
#define  LC_LC_Spatial_Ctrl3_lc_spatialremaptab1_mask                            (0x003FF000)
#define  LC_LC_Spatial_Ctrl3_lc_spatialremaptab0_mask                            (0x000003FF)
#define  LC_LC_Spatial_Ctrl3_lc_spatialremapadr(data)                            (0x1F000000&((data)<<24))
#define  LC_LC_Spatial_Ctrl3_lc_spatialremaptab1(data)                           (0x003FF000&((data)<<12))
#define  LC_LC_Spatial_Ctrl3_lc_spatialremaptab0(data)                           (0x000003FF&(data))
#define  LC_LC_Spatial_Ctrl3_get_lc_spatialremapadr(data)                        ((0x1F000000&(data))>>24)
#define  LC_LC_Spatial_Ctrl3_get_lc_spatialremaptab1(data)                       ((0x003FF000&(data))>>12)
#define  LC_LC_Spatial_Ctrl3_get_lc_spatialremaptab0(data)                       (0x000003FF&(data))

#define  LC_LC_Spatial_Ctrl4                                                     0x1802E068
#define  LC_LC_Spatial_Ctrl4_reg_addr                                            "0xB802E068"
#define  LC_LC_Spatial_Ctrl4_reg                                                 0xB802E068
#define  LC_LC_Spatial_Ctrl4_inst_addr                                           "0x0017"
#define  set_LC_LC_Spatial_Ctrl4_reg(data)                                       (*((volatile unsigned int*)LC_LC_Spatial_Ctrl4_reg)=data)
#define  get_LC_LC_Spatial_Ctrl4_reg                                             (*((volatile unsigned int*)LC_LC_Spatial_Ctrl4_reg))
#define  LC_LC_Spatial_Ctrl4_lc_spatialremaptab_initial_shift                    (0)
#define  LC_LC_Spatial_Ctrl4_lc_spatialremaptab_initial_mask                     (0x000003FF)
#define  LC_LC_Spatial_Ctrl4_lc_spatialremaptab_initial(data)                    (0x000003FF&(data))
#define  LC_LC_Spatial_Ctrl4_get_lc_spatialremaptab_initial(data)                (0x000003FF&(data))

#define  LC_LC_Temporal_Ctrl1                                                    0x1802E05C
#define  LC_LC_Temporal_Ctrl1_reg_addr                                           "0xB802E05C"
#define  LC_LC_Temporal_Ctrl1_reg                                                0xB802E05C
#define  LC_LC_Temporal_Ctrl1_inst_addr                                          "0x0018"
#define  set_LC_LC_Temporal_Ctrl1_reg(data)                                      (*((volatile unsigned int*)LC_LC_Temporal_Ctrl1_reg)=data)
#define  get_LC_LC_Temporal_Ctrl1_reg                                            (*((volatile unsigned int*)LC_LC_Temporal_Ctrl1_reg))
#define  LC_LC_Temporal_Ctrl1_lc_tmp_pos0thd_shift                               (24)
#define  LC_LC_Temporal_Ctrl1_lc_tmp_pos1thd_shift                               (16)
#define  LC_LC_Temporal_Ctrl1_lc_tmp_posmingain_shift                            (8)
#define  LC_LC_Temporal_Ctrl1_lc_tmp_posmaxgain_shift                            (0)
#define  LC_LC_Temporal_Ctrl1_lc_tmp_pos0thd_mask                                (0xFF000000)
#define  LC_LC_Temporal_Ctrl1_lc_tmp_pos1thd_mask                                (0x00FF0000)
#define  LC_LC_Temporal_Ctrl1_lc_tmp_posmingain_mask                             (0x00001F00)
#define  LC_LC_Temporal_Ctrl1_lc_tmp_posmaxgain_mask                             (0x0000001F)
#define  LC_LC_Temporal_Ctrl1_lc_tmp_pos0thd(data)                               (0xFF000000&((data)<<24))
#define  LC_LC_Temporal_Ctrl1_lc_tmp_pos1thd(data)                               (0x00FF0000&((data)<<16))
#define  LC_LC_Temporal_Ctrl1_lc_tmp_posmingain(data)                            (0x00001F00&((data)<<8))
#define  LC_LC_Temporal_Ctrl1_lc_tmp_posmaxgain(data)                            (0x0000001F&(data))
#define  LC_LC_Temporal_Ctrl1_get_lc_tmp_pos0thd(data)                           ((0xFF000000&(data))>>24)
#define  LC_LC_Temporal_Ctrl1_get_lc_tmp_pos1thd(data)                           ((0x00FF0000&(data))>>16)
#define  LC_LC_Temporal_Ctrl1_get_lc_tmp_posmingain(data)                        ((0x00001F00&(data))>>8)
#define  LC_LC_Temporal_Ctrl1_get_lc_tmp_posmaxgain(data)                        (0x0000001F&(data))

#define  LC_LC_Temporal_Ctrl2                                                    0x1802E060
#define  LC_LC_Temporal_Ctrl2_reg_addr                                           "0xB802E060"
#define  LC_LC_Temporal_Ctrl2_reg                                                0xB802E060
#define  LC_LC_Temporal_Ctrl2_inst_addr                                          "0x0019"
#define  set_LC_LC_Temporal_Ctrl2_reg(data)                                      (*((volatile unsigned int*)LC_LC_Temporal_Ctrl2_reg)=data)
#define  get_LC_LC_Temporal_Ctrl2_reg                                            (*((volatile unsigned int*)LC_LC_Temporal_Ctrl2_reg))
#define  LC_LC_Temporal_Ctrl2_lc_tmp_neg0thd_shift                               (24)
#define  LC_LC_Temporal_Ctrl2_lc_tmp_neg1thd_shift                               (16)
#define  LC_LC_Temporal_Ctrl2_lc_tmp_negmingain_shift                            (8)
#define  LC_LC_Temporal_Ctrl2_lc_tmp_negmaxgain_shift                            (0)
#define  LC_LC_Temporal_Ctrl2_lc_tmp_neg0thd_mask                                (0xFF000000)
#define  LC_LC_Temporal_Ctrl2_lc_tmp_neg1thd_mask                                (0x00FF0000)
#define  LC_LC_Temporal_Ctrl2_lc_tmp_negmingain_mask                             (0x00001F00)
#define  LC_LC_Temporal_Ctrl2_lc_tmp_negmaxgain_mask                             (0x0000001F)
#define  LC_LC_Temporal_Ctrl2_lc_tmp_neg0thd(data)                               (0xFF000000&((data)<<24))
#define  LC_LC_Temporal_Ctrl2_lc_tmp_neg1thd(data)                               (0x00FF0000&((data)<<16))
#define  LC_LC_Temporal_Ctrl2_lc_tmp_negmingain(data)                            (0x00001F00&((data)<<8))
#define  LC_LC_Temporal_Ctrl2_lc_tmp_negmaxgain(data)                            (0x0000001F&(data))
#define  LC_LC_Temporal_Ctrl2_get_lc_tmp_neg0thd(data)                           ((0xFF000000&(data))>>24)
#define  LC_LC_Temporal_Ctrl2_get_lc_tmp_neg1thd(data)                           ((0x00FF0000&(data))>>16)
#define  LC_LC_Temporal_Ctrl2_get_lc_tmp_negmingain(data)                        ((0x00001F00&(data))>>8)
#define  LC_LC_Temporal_Ctrl2_get_lc_tmp_negmaxgain(data)                        (0x0000001F&(data))

#define  LC_LC_Temporal_Ctrl3                                                    0x1802E064
#define  LC_LC_Temporal_Ctrl3_reg_addr                                           "0xB802E064"
#define  LC_LC_Temporal_Ctrl3_reg                                                0xB802E064
#define  LC_LC_Temporal_Ctrl3_inst_addr                                          "0x001A"
#define  set_LC_LC_Temporal_Ctrl3_reg(data)                                      (*((volatile unsigned int*)LC_LC_Temporal_Ctrl3_reg)=data)
#define  get_LC_LC_Temporal_Ctrl3_reg                                            (*((volatile unsigned int*)LC_LC_Temporal_Ctrl3_reg))
#define  LC_LC_Temporal_Ctrl3_lc_tmp_maxdiff_shift                               (16)
#define  LC_LC_Temporal_Ctrl3_lc_tmp_scenechangegain1_shift                      (8)
#define  LC_LC_Temporal_Ctrl3_lc_tmp_maxdiff_mask                                (0x00FF0000)
#define  LC_LC_Temporal_Ctrl3_lc_tmp_scenechangegain1_mask                       (0x00001F00)
#define  LC_LC_Temporal_Ctrl3_lc_tmp_maxdiff(data)                               (0x00FF0000&((data)<<16))
#define  LC_LC_Temporal_Ctrl3_lc_tmp_scenechangegain1(data)                      (0x00001F00&((data)<<8))
#define  LC_LC_Temporal_Ctrl3_get_lc_tmp_maxdiff(data)                           ((0x00FF0000&(data))>>16)
#define  LC_LC_Temporal_Ctrl3_get_lc_tmp_scenechangegain1(data)                  ((0x00001F00&(data))>>8)

#define  LC_LC_Inter_HCtrl3                                                      0x1802E06C
#define  LC_LC_Inter_HCtrl3_reg_addr                                             "0xB802E06C"
#define  LC_LC_Inter_HCtrl3_reg                                                  0xB802E06C
#define  LC_LC_Inter_HCtrl3_inst_addr                                            "0x001B"
#define  set_LC_LC_Inter_HCtrl3_reg(data)                                        (*((volatile unsigned int*)LC_LC_Inter_HCtrl3_reg)=data)
#define  get_LC_LC_Inter_HCtrl3_reg                                              (*((volatile unsigned int*)LC_LC_Inter_HCtrl3_reg))
#define  LC_LC_Inter_HCtrl3_lc_drf_rm_8_shift                                    (4)
#define  LC_LC_Inter_HCtrl3_lc_drf_rme_8_shift                                   (3)
#define  LC_LC_Inter_HCtrl3_lc_drf_ls_8_shift                                    (2)
#define  LC_LC_Inter_HCtrl3_lc_drf_bist_fail_8_shift                             (1)
#define  LC_LC_Inter_HCtrl3_lc_bist_fail_8_shift                                 (0)
#define  LC_LC_Inter_HCtrl3_lc_drf_rm_8_mask                                     (0x000000F0)
#define  LC_LC_Inter_HCtrl3_lc_drf_rme_8_mask                                    (0x00000008)
#define  LC_LC_Inter_HCtrl3_lc_drf_ls_8_mask                                     (0x00000004)
#define  LC_LC_Inter_HCtrl3_lc_drf_bist_fail_8_mask                              (0x00000002)
#define  LC_LC_Inter_HCtrl3_lc_bist_fail_8_mask                                  (0x00000001)
#define  LC_LC_Inter_HCtrl3_lc_drf_rm_8(data)                                    (0x000000F0&((data)<<4))
#define  LC_LC_Inter_HCtrl3_lc_drf_rme_8(data)                                   (0x00000008&((data)<<3))
#define  LC_LC_Inter_HCtrl3_lc_drf_ls_8(data)                                    (0x00000004&((data)<<2))
#define  LC_LC_Inter_HCtrl3_lc_drf_bist_fail_8(data)                             (0x00000002&((data)<<1))
#define  LC_LC_Inter_HCtrl3_lc_bist_fail_8(data)                                 (0x00000001&(data))
#define  LC_LC_Inter_HCtrl3_get_lc_drf_rm_8(data)                                ((0x000000F0&(data))>>4)
#define  LC_LC_Inter_HCtrl3_get_lc_drf_rme_8(data)                               ((0x00000008&(data))>>3)
#define  LC_LC_Inter_HCtrl3_get_lc_drf_ls_8(data)                                ((0x00000004&(data))>>2)
#define  LC_LC_Inter_HCtrl3_get_lc_drf_bist_fail_8(data)                         ((0x00000002&(data))>>1)
#define  LC_LC_Inter_HCtrl3_get_lc_bist_fail_8(data)                             (0x00000001&(data))

#define  LC_LC_Inter_HCtrl1                                                      0x1802E074
#define  LC_LC_Inter_HCtrl1_reg_addr                                             "0xB802E074"
#define  LC_LC_Inter_HCtrl1_reg                                                  0xB802E074
#define  LC_LC_Inter_HCtrl1_inst_addr                                            "0x001C"
#define  set_LC_LC_Inter_HCtrl1_reg(data)                                        (*((volatile unsigned int*)LC_LC_Inter_HCtrl1_reg)=data)
#define  get_LC_LC_Inter_HCtrl1_reg                                              (*((volatile unsigned int*)LC_LC_Inter_HCtrl1_reg))
#define  LC_LC_Inter_HCtrl1_lc_tab_hsize_shift                                   (24)
#define  LC_LC_Inter_HCtrl1_lc_hfactor_shift                                     (0)
#define  LC_LC_Inter_HCtrl1_lc_tab_hsize_mask                                    (0xFF000000)
#define  LC_LC_Inter_HCtrl1_lc_hfactor_mask                                      (0x000FFFFF)
#define  LC_LC_Inter_HCtrl1_lc_tab_hsize(data)                                   (0xFF000000&((data)<<24))
#define  LC_LC_Inter_HCtrl1_lc_hfactor(data)                                     (0x000FFFFF&(data))
#define  LC_LC_Inter_HCtrl1_get_lc_tab_hsize(data)                               ((0xFF000000&(data))>>24)
#define  LC_LC_Inter_HCtrl1_get_lc_hfactor(data)                                 (0x000FFFFF&(data))

#define  LC_LC_Inter_HCtrl2                                                      0x1802E078
#define  LC_LC_Inter_HCtrl2_reg_addr                                             "0xB802E078"
#define  LC_LC_Inter_HCtrl2_reg                                                  0xB802E078
#define  LC_LC_Inter_HCtrl2_inst_addr                                            "0x001D"
#define  set_LC_LC_Inter_HCtrl2_reg(data)                                        (*((volatile unsigned int*)LC_LC_Inter_HCtrl2_reg)=data)
#define  get_LC_LC_Inter_HCtrl2_reg                                              (*((volatile unsigned int*)LC_LC_Inter_HCtrl2_reg))
#define  LC_LC_Inter_HCtrl2_lc_hinitphase3_right_shift                           (24)
#define  LC_LC_Inter_HCtrl2_lc_hboundary_shift                                   (20)
#define  LC_LC_Inter_HCtrl2_lc_hinitphase1_shift                                 (16)
#define  LC_LC_Inter_HCtrl2_lc_hinitphase2_shift                                 (8)
#define  LC_LC_Inter_HCtrl2_lc_hinitphase3_left_shift                            (0)
#define  LC_LC_Inter_HCtrl2_lc_hinitphase3_right_mask                            (0xFF000000)
#define  LC_LC_Inter_HCtrl2_lc_hboundary_mask                                    (0x00100000)
#define  LC_LC_Inter_HCtrl2_lc_hinitphase1_mask                                  (0x00010000)
#define  LC_LC_Inter_HCtrl2_lc_hinitphase2_mask                                  (0x0000FF00)
#define  LC_LC_Inter_HCtrl2_lc_hinitphase3_left_mask                             (0x000000FF)
#define  LC_LC_Inter_HCtrl2_lc_hinitphase3_right(data)                           (0xFF000000&((data)<<24))
#define  LC_LC_Inter_HCtrl2_lc_hboundary(data)                                   (0x00100000&((data)<<20))
#define  LC_LC_Inter_HCtrl2_lc_hinitphase1(data)                                 (0x00010000&((data)<<16))
#define  LC_LC_Inter_HCtrl2_lc_hinitphase2(data)                                 (0x0000FF00&((data)<<8))
#define  LC_LC_Inter_HCtrl2_lc_hinitphase3_left(data)                            (0x000000FF&(data))
#define  LC_LC_Inter_HCtrl2_get_lc_hinitphase3_right(data)                       ((0xFF000000&(data))>>24)
#define  LC_LC_Inter_HCtrl2_get_lc_hboundary(data)                               ((0x00100000&(data))>>20)
#define  LC_LC_Inter_HCtrl2_get_lc_hinitphase1(data)                             ((0x00010000&(data))>>16)
#define  LC_LC_Inter_HCtrl2_get_lc_hinitphase2(data)                             ((0x0000FF00&(data))>>8)
#define  LC_LC_Inter_HCtrl2_get_lc_hinitphase3_left(data)                        (0x000000FF&(data))

#define  LC_LC_Inter_VCtrl1                                                      0x1802E07C
#define  LC_LC_Inter_VCtrl1_reg_addr                                             "0xB802E07C"
#define  LC_LC_Inter_VCtrl1_reg                                                  0xB802E07C
#define  LC_LC_Inter_VCtrl1_inst_addr                                            "0x001E"
#define  set_LC_LC_Inter_VCtrl1_reg(data)                                        (*((volatile unsigned int*)LC_LC_Inter_VCtrl1_reg)=data)
#define  get_LC_LC_Inter_VCtrl1_reg                                              (*((volatile unsigned int*)LC_LC_Inter_VCtrl1_reg))
#define  LC_LC_Inter_VCtrl1_lc_tab_vsize_shift                                   (24)
#define  LC_LC_Inter_VCtrl1_lc_vfactor_shift                                     (0)
#define  LC_LC_Inter_VCtrl1_lc_tab_vsize_mask                                    (0xFF000000)
#define  LC_LC_Inter_VCtrl1_lc_vfactor_mask                                      (0x000FFFFF)
#define  LC_LC_Inter_VCtrl1_lc_tab_vsize(data)                                   (0xFF000000&((data)<<24))
#define  LC_LC_Inter_VCtrl1_lc_vfactor(data)                                     (0x000FFFFF&(data))
#define  LC_LC_Inter_VCtrl1_get_lc_tab_vsize(data)                               ((0xFF000000&(data))>>24)
#define  LC_LC_Inter_VCtrl1_get_lc_vfactor(data)                                 (0x000FFFFF&(data))

#define  LC_LC_Inter_VCtrl2                                                      0x1802E080
#define  LC_LC_Inter_VCtrl2_reg_addr                                             "0xB802E080"
#define  LC_LC_Inter_VCtrl2_reg                                                  0xB802E080
#define  LC_LC_Inter_VCtrl2_inst_addr                                            "0x001F"
#define  set_LC_LC_Inter_VCtrl2_reg(data)                                        (*((volatile unsigned int*)LC_LC_Inter_VCtrl2_reg)=data)
#define  get_LC_LC_Inter_VCtrl2_reg                                              (*((volatile unsigned int*)LC_LC_Inter_VCtrl2_reg))
#define  LC_LC_Inter_VCtrl2_lc_vinitphase3_right_shift                           (24)
#define  LC_LC_Inter_VCtrl2_lc_vboundary_shift                                   (20)
#define  LC_LC_Inter_VCtrl2_lc_vinitphase1_shift                                 (16)
#define  LC_LC_Inter_VCtrl2_lc_vinitphase2_shift                                 (8)
#define  LC_LC_Inter_VCtrl2_lc_vinitphase3_left_shift                            (0)
#define  LC_LC_Inter_VCtrl2_lc_vinitphase3_right_mask                            (0xFF000000)
#define  LC_LC_Inter_VCtrl2_lc_vboundary_mask                                    (0x00100000)
#define  LC_LC_Inter_VCtrl2_lc_vinitphase1_mask                                  (0x00010000)
#define  LC_LC_Inter_VCtrl2_lc_vinitphase2_mask                                  (0x0000FF00)
#define  LC_LC_Inter_VCtrl2_lc_vinitphase3_left_mask                             (0x000000FF)
#define  LC_LC_Inter_VCtrl2_lc_vinitphase3_right(data)                           (0xFF000000&((data)<<24))
#define  LC_LC_Inter_VCtrl2_lc_vboundary(data)                                   (0x00100000&((data)<<20))
#define  LC_LC_Inter_VCtrl2_lc_vinitphase1(data)                                 (0x00010000&((data)<<16))
#define  LC_LC_Inter_VCtrl2_lc_vinitphase2(data)                                 (0x0000FF00&((data)<<8))
#define  LC_LC_Inter_VCtrl2_lc_vinitphase3_left(data)                            (0x000000FF&(data))
#define  LC_LC_Inter_VCtrl2_get_lc_vinitphase3_right(data)                       ((0xFF000000&(data))>>24)
#define  LC_LC_Inter_VCtrl2_get_lc_vboundary(data)                               ((0x00100000&(data))>>20)
#define  LC_LC_Inter_VCtrl2_get_lc_vinitphase1(data)                             ((0x00010000&(data))>>16)
#define  LC_LC_Inter_VCtrl2_get_lc_vinitphase2(data)                             ((0x0000FF00&(data))>>8)
#define  LC_LC_Inter_VCtrl2_get_lc_vinitphase3_left(data)                        (0x000000FF&(data))

#define  LC_LC_VTAB_AP                                                           0x1802E084
#define  LC_LC_VTAB_AP_reg_addr                                                  "0xB802E084"
#define  LC_LC_VTAB_AP_reg                                                       0xB802E084
#define  LC_LC_VTAB_AP_inst_addr                                                 "0x0020"
#define  set_LC_LC_VTAB_AP_reg(data)                                             (*((volatile unsigned int*)LC_LC_VTAB_AP_reg)=data)
#define  get_LC_LC_VTAB_AP_reg                                                   (*((volatile unsigned int*)LC_LC_VTAB_AP_reg))
#define  LC_LC_VTAB_AP_dummy_31_9_shift                                          (9)
#define  LC_LC_VTAB_AP_lc_vtab_adr_shift                                         (0)
#define  LC_LC_VTAB_AP_dummy_31_9_mask                                           (0xFFFFFE00)
#define  LC_LC_VTAB_AP_lc_vtab_adr_mask                                          (0x000001FF)
#define  LC_LC_VTAB_AP_dummy_31_9(data)                                          (0xFFFFFE00&((data)<<9))
#define  LC_LC_VTAB_AP_lc_vtab_adr(data)                                         (0x000001FF&(data))
#define  LC_LC_VTAB_AP_get_dummy_31_9(data)                                      ((0xFFFFFE00&(data))>>9)
#define  LC_LC_VTAB_AP_get_lc_vtab_adr(data)                                     (0x000001FF&(data))

#define  LC_LC_VTAB_DP                                                           0x1802E088
#define  LC_LC_VTAB_DP_reg_addr                                                  "0xB802E088"
#define  LC_LC_VTAB_DP_reg                                                       0xB802E088
#define  LC_LC_VTAB_DP_inst_addr                                                 "0x0021"
#define  set_LC_LC_VTAB_DP_reg(data)                                             (*((volatile unsigned int*)LC_LC_VTAB_DP_reg)=data)
#define  get_LC_LC_VTAB_DP_reg                                                   (*((volatile unsigned int*)LC_LC_VTAB_DP_reg))
#define  LC_LC_VTAB_DP_dummy_31_26_shift                                         (26)
#define  LC_LC_VTAB_DP_lc_vtab_dat_msb_shift                                     (16)
#define  LC_LC_VTAB_DP_dummy_15_10_shift                                         (10)
#define  LC_LC_VTAB_DP_lc_vtab_dat_lsb_shift                                     (0)
#define  LC_LC_VTAB_DP_dummy_31_26_mask                                          (0xFC000000)
#define  LC_LC_VTAB_DP_lc_vtab_dat_msb_mask                                      (0x03FF0000)
#define  LC_LC_VTAB_DP_dummy_15_10_mask                                          (0x0000FC00)
#define  LC_LC_VTAB_DP_lc_vtab_dat_lsb_mask                                      (0x000003FF)
#define  LC_LC_VTAB_DP_dummy_31_26(data)                                         (0xFC000000&((data)<<26))
#define  LC_LC_VTAB_DP_lc_vtab_dat_msb(data)                                     (0x03FF0000&((data)<<16))
#define  LC_LC_VTAB_DP_dummy_15_10(data)                                         (0x0000FC00&((data)<<10))
#define  LC_LC_VTAB_DP_lc_vtab_dat_lsb(data)                                     (0x000003FF&(data))
#define  LC_LC_VTAB_DP_get_dummy_31_26(data)                                     ((0xFC000000&(data))>>26)
#define  LC_LC_VTAB_DP_get_lc_vtab_dat_msb(data)                                 ((0x03FF0000&(data))>>16)
#define  LC_LC_VTAB_DP_get_dummy_15_10(data)                                     ((0x0000FC00&(data))>>10)
#define  LC_LC_VTAB_DP_get_lc_vtab_dat_lsb(data)                                 (0x000003FF&(data))

#define  LC_LC_HTAB_AP                                                           0x1802E08C
#define  LC_LC_HTAB_AP_reg_addr                                                  "0xB802E08C"
#define  LC_LC_HTAB_AP_reg                                                       0xB802E08C
#define  LC_LC_HTAB_AP_inst_addr                                                 "0x0022"
#define  set_LC_LC_HTAB_AP_reg(data)                                             (*((volatile unsigned int*)LC_LC_HTAB_AP_reg)=data)
#define  get_LC_LC_HTAB_AP_reg                                                   (*((volatile unsigned int*)LC_LC_HTAB_AP_reg))
#define  LC_LC_HTAB_AP_dummy_31_9_shift                                          (9)
#define  LC_LC_HTAB_AP_lc_htab_adr_shift                                         (0)
#define  LC_LC_HTAB_AP_dummy_31_9_mask                                           (0xFFFFFE00)
#define  LC_LC_HTAB_AP_lc_htab_adr_mask                                          (0x000001FF)
#define  LC_LC_HTAB_AP_dummy_31_9(data)                                          (0xFFFFFE00&((data)<<9))
#define  LC_LC_HTAB_AP_lc_htab_adr(data)                                         (0x000001FF&(data))
#define  LC_LC_HTAB_AP_get_dummy_31_9(data)                                      ((0xFFFFFE00&(data))>>9)
#define  LC_LC_HTAB_AP_get_lc_htab_adr(data)                                     (0x000001FF&(data))

#define  LC_LC_HTAB_DP                                                           0x1802E090
#define  LC_LC_HTAB_DP_reg_addr                                                  "0xB802E090"
#define  LC_LC_HTAB_DP_reg                                                       0xB802E090
#define  LC_LC_HTAB_DP_inst_addr                                                 "0x0023"
#define  set_LC_LC_HTAB_DP_reg(data)                                             (*((volatile unsigned int*)LC_LC_HTAB_DP_reg)=data)
#define  get_LC_LC_HTAB_DP_reg                                                   (*((volatile unsigned int*)LC_LC_HTAB_DP_reg))
#define  LC_LC_HTAB_DP_dummy_31_26_shift                                         (26)
#define  LC_LC_HTAB_DP_lc_htab_dat_msb_shift                                     (16)
#define  LC_LC_HTAB_DP_dummy_15_10_shift                                         (10)
#define  LC_LC_HTAB_DP_lc_htab_dat_lsb_shift                                     (0)
#define  LC_LC_HTAB_DP_dummy_31_26_mask                                          (0xFC000000)
#define  LC_LC_HTAB_DP_lc_htab_dat_msb_mask                                      (0x03FF0000)
#define  LC_LC_HTAB_DP_dummy_15_10_mask                                          (0x0000FC00)
#define  LC_LC_HTAB_DP_lc_htab_dat_lsb_mask                                      (0x000003FF)
#define  LC_LC_HTAB_DP_dummy_31_26(data)                                         (0xFC000000&((data)<<26))
#define  LC_LC_HTAB_DP_lc_htab_dat_msb(data)                                     (0x03FF0000&((data)<<16))
#define  LC_LC_HTAB_DP_dummy_15_10(data)                                         (0x0000FC00&((data)<<10))
#define  LC_LC_HTAB_DP_lc_htab_dat_lsb(data)                                     (0x000003FF&(data))
#define  LC_LC_HTAB_DP_get_dummy_31_26(data)                                     ((0xFC000000&(data))>>26)
#define  LC_LC_HTAB_DP_get_lc_htab_dat_msb(data)                                 ((0x03FF0000&(data))>>16)
#define  LC_LC_HTAB_DP_get_dummy_15_10(data)                                     ((0x0000FC00&(data))>>10)
#define  LC_LC_HTAB_DP_get_lc_htab_dat_lsb(data)                                 (0x000003FF&(data))

#define  LC_LC_SRAM_CTRL                                                         0x1802E094
#define  LC_LC_SRAM_CTRL_reg_addr                                                "0xB802E094"
#define  LC_LC_SRAM_CTRL_reg                                                     0xB802E094
#define  LC_LC_SRAM_CTRL_inst_addr                                               "0x0024"
#define  set_LC_LC_SRAM_CTRL_reg(data)                                           (*((volatile unsigned int*)LC_LC_SRAM_CTRL_reg)=data)
#define  get_LC_LC_SRAM_CTRL_reg                                                 (*((volatile unsigned int*)LC_LC_SRAM_CTRL_reg))
#define  LC_LC_SRAM_CTRL_dummy_31_3_shift                                        (3)
#define  LC_LC_SRAM_CTRL_lc_blight_update_en_shift                               (2)
#define  LC_LC_SRAM_CTRL_lc_blight_sw_mode_shift                                 (1)
#define  LC_LC_SRAM_CTRL_lc_table_sw_mode_shift                                  (0)
#define  LC_LC_SRAM_CTRL_dummy_31_3_mask                                         (0xFFFFFFF8)
#define  LC_LC_SRAM_CTRL_lc_blight_update_en_mask                                (0x00000004)
#define  LC_LC_SRAM_CTRL_lc_blight_sw_mode_mask                                  (0x00000002)
#define  LC_LC_SRAM_CTRL_lc_table_sw_mode_mask                                   (0x00000001)
#define  LC_LC_SRAM_CTRL_dummy_31_3(data)                                        (0xFFFFFFF8&((data)<<3))
#define  LC_LC_SRAM_CTRL_lc_blight_update_en(data)                               (0x00000004&((data)<<2))
#define  LC_LC_SRAM_CTRL_lc_blight_sw_mode(data)                                 (0x00000002&((data)<<1))
#define  LC_LC_SRAM_CTRL_lc_table_sw_mode(data)                                  (0x00000001&(data))
#define  LC_LC_SRAM_CTRL_get_dummy_31_3(data)                                    ((0xFFFFFFF8&(data))>>3)
#define  LC_LC_SRAM_CTRL_get_lc_blight_update_en(data)                           ((0x00000004&(data))>>2)
#define  LC_LC_SRAM_CTRL_get_lc_blight_sw_mode(data)                             ((0x00000002&(data))>>1)
#define  LC_LC_SRAM_CTRL_get_lc_table_sw_mode(data)                              (0x00000001&(data))

#define  LC_LC_BLIGHT_AP                                                         0x1802E098
#define  LC_LC_BLIGHT_AP_reg_addr                                                "0xB802E098"
#define  LC_LC_BLIGHT_AP_reg                                                     0xB802E098
#define  LC_LC_BLIGHT_AP_inst_addr                                               "0x0025"
#define  set_LC_LC_BLIGHT_AP_reg(data)                                           (*((volatile unsigned int*)LC_LC_BLIGHT_AP_reg)=data)
#define  get_LC_LC_BLIGHT_AP_reg                                                 (*((volatile unsigned int*)LC_LC_BLIGHT_AP_reg))
#define  LC_LC_BLIGHT_AP_dummy_31_8_shift                                        (8)
#define  LC_LC_BLIGHT_AP_lc_blight_adr_shift                                     (0)
#define  LC_LC_BLIGHT_AP_dummy_31_8_mask                                         (0xFFFFFF00)
#define  LC_LC_BLIGHT_AP_lc_blight_adr_mask                                      (0x000000FF)
#define  LC_LC_BLIGHT_AP_dummy_31_8(data)                                        (0xFFFFFF00&((data)<<8))
#define  LC_LC_BLIGHT_AP_lc_blight_adr(data)                                     (0x000000FF&(data))
#define  LC_LC_BLIGHT_AP_get_dummy_31_8(data)                                    ((0xFFFFFF00&(data))>>8)
#define  LC_LC_BLIGHT_AP_get_lc_blight_adr(data)                                 (0x000000FF&(data))

#define  LC_LC_BLIGHT_DP                                                         0x1802E09C
#define  LC_LC_BLIGHT_DP_reg_addr                                                "0xB802E09C"
#define  LC_LC_BLIGHT_DP_reg                                                     0xB802E09C
#define  LC_LC_BLIGHT_DP_inst_addr                                               "0x0026"
#define  set_LC_LC_BLIGHT_DP_reg(data)                                           (*((volatile unsigned int*)LC_LC_BLIGHT_DP_reg)=data)
#define  get_LC_LC_BLIGHT_DP_reg                                                 (*((volatile unsigned int*)LC_LC_BLIGHT_DP_reg))
#define  LC_LC_BLIGHT_DP_dummy_31_26_shift                                       (26)
#define  LC_LC_BLIGHT_DP_lc_blight_dat_msb_shift                                 (16)
#define  LC_LC_BLIGHT_DP_dummy_15_10_shift                                       (10)
#define  LC_LC_BLIGHT_DP_lc_blight_dat_lsb_shift                                 (0)
#define  LC_LC_BLIGHT_DP_dummy_31_26_mask                                        (0xFC000000)
#define  LC_LC_BLIGHT_DP_lc_blight_dat_msb_mask                                  (0x03FF0000)
#define  LC_LC_BLIGHT_DP_dummy_15_10_mask                                        (0x0000FC00)
#define  LC_LC_BLIGHT_DP_lc_blight_dat_lsb_mask                                  (0x000003FF)
#define  LC_LC_BLIGHT_DP_dummy_31_26(data)                                       (0xFC000000&((data)<<26))
#define  LC_LC_BLIGHT_DP_lc_blight_dat_msb(data)                                 (0x03FF0000&((data)<<16))
#define  LC_LC_BLIGHT_DP_dummy_15_10(data)                                       (0x0000FC00&((data)<<10))
#define  LC_LC_BLIGHT_DP_lc_blight_dat_lsb(data)                                 (0x000003FF&(data))
#define  LC_LC_BLIGHT_DP_get_dummy_31_26(data)                                   ((0xFC000000&(data))>>26)
#define  LC_LC_BLIGHT_DP_get_lc_blight_dat_msb(data)                             ((0x03FF0000&(data))>>16)
#define  LC_LC_BLIGHT_DP_get_dummy_15_10(data)                                   ((0x0000FC00&(data))>>10)
#define  LC_LC_BLIGHT_DP_get_lc_blight_dat_lsb(data)                             (0x000003FF&(data))

#define  LC_LC_ToneMapping_grid0_0                                               0x1802E0A0
#define  LC_LC_ToneMapping_grid0_0_reg_addr                                      "0xB802E0A0"
#define  LC_LC_ToneMapping_grid0_0_reg                                           0xB802E0A0
#define  LC_LC_ToneMapping_grid0_0_inst_addr                                     "0x0027"
#define  set_LC_LC_ToneMapping_grid0_0_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_0_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_0_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_0_reg))
#define  LC_LC_ToneMapping_grid0_0_lc_tmap_g0_th1_shift                          (0)
#define  LC_LC_ToneMapping_grid0_0_lc_tmap_g0_th1_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_0_lc_tmap_g0_th1(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_0_get_lc_tmap_g0_th1(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_1                                               0x1802E0A4
#define  LC_LC_ToneMapping_grid0_1_reg_addr                                      "0xB802E0A4"
#define  LC_LC_ToneMapping_grid0_1_reg                                           0xB802E0A4
#define  LC_LC_ToneMapping_grid0_1_inst_addr                                     "0x0028"
#define  set_LC_LC_ToneMapping_grid0_1_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_1_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_1_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_1_reg))
#define  LC_LC_ToneMapping_grid0_1_lc_tmap_g0_th2_shift                          (16)
#define  LC_LC_ToneMapping_grid0_1_lc_tmap_g0_th3_shift                          (0)
#define  LC_LC_ToneMapping_grid0_1_lc_tmap_g0_th2_mask                           (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_1_lc_tmap_g0_th3_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_1_lc_tmap_g0_th2(data)                          (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_1_lc_tmap_g0_th3(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_1_get_lc_tmap_g0_th2(data)                      ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_1_get_lc_tmap_g0_th3(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_2                                               0x1802E0A8
#define  LC_LC_ToneMapping_grid0_2_reg_addr                                      "0xB802E0A8"
#define  LC_LC_ToneMapping_grid0_2_reg                                           0xB802E0A8
#define  LC_LC_ToneMapping_grid0_2_inst_addr                                     "0x0029"
#define  set_LC_LC_ToneMapping_grid0_2_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_2_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_2_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_2_reg))
#define  LC_LC_ToneMapping_grid0_2_lc_tmap_g0_th4_shift                          (16)
#define  LC_LC_ToneMapping_grid0_2_lc_tmap_g0_th5_shift                          (0)
#define  LC_LC_ToneMapping_grid0_2_lc_tmap_g0_th4_mask                           (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_2_lc_tmap_g0_th5_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_2_lc_tmap_g0_th4(data)                          (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_2_lc_tmap_g0_th5(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_2_get_lc_tmap_g0_th4(data)                      ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_2_get_lc_tmap_g0_th5(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_3                                               0x1802E0AC
#define  LC_LC_ToneMapping_grid0_3_reg_addr                                      "0xB802E0AC"
#define  LC_LC_ToneMapping_grid0_3_reg                                           0xB802E0AC
#define  LC_LC_ToneMapping_grid0_3_inst_addr                                     "0x002A"
#define  set_LC_LC_ToneMapping_grid0_3_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_3_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_3_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_3_reg))
#define  LC_LC_ToneMapping_grid0_3_lc_tmap_g0_th6_shift                          (16)
#define  LC_LC_ToneMapping_grid0_3_lc_tmap_g0_th7_shift                          (0)
#define  LC_LC_ToneMapping_grid0_3_lc_tmap_g0_th6_mask                           (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_3_lc_tmap_g0_th7_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_3_lc_tmap_g0_th6(data)                          (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_3_lc_tmap_g0_th7(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_3_get_lc_tmap_g0_th6(data)                      ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_3_get_lc_tmap_g0_th7(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_4                                               0x1802E0B0
#define  LC_LC_ToneMapping_grid0_4_reg_addr                                      "0xB802E0B0"
#define  LC_LC_ToneMapping_grid0_4_reg                                           0xB802E0B0
#define  LC_LC_ToneMapping_grid0_4_inst_addr                                     "0x002B"
#define  set_LC_LC_ToneMapping_grid0_4_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_4_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_4_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_4_reg))
#define  LC_LC_ToneMapping_grid0_4_lc_tmap_g0_th8_shift                          (16)
#define  LC_LC_ToneMapping_grid0_4_lc_tmap_g0_th9_shift                          (0)
#define  LC_LC_ToneMapping_grid0_4_lc_tmap_g0_th8_mask                           (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_4_lc_tmap_g0_th9_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_4_lc_tmap_g0_th8(data)                          (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_4_lc_tmap_g0_th9(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_4_get_lc_tmap_g0_th8(data)                      ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_4_get_lc_tmap_g0_th9(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_5                                               0x1802E0B4
#define  LC_LC_ToneMapping_grid0_5_reg_addr                                      "0xB802E0B4"
#define  LC_LC_ToneMapping_grid0_5_reg                                           0xB802E0B4
#define  LC_LC_ToneMapping_grid0_5_inst_addr                                     "0x002C"
#define  set_LC_LC_ToneMapping_grid0_5_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_5_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_5_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_5_reg))
#define  LC_LC_ToneMapping_grid0_5_lc_tmap_g0_th10_shift                         (16)
#define  LC_LC_ToneMapping_grid0_5_lc_tmap_g0_th11_shift                         (0)
#define  LC_LC_ToneMapping_grid0_5_lc_tmap_g0_th10_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_5_lc_tmap_g0_th11_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_5_lc_tmap_g0_th10(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_5_lc_tmap_g0_th11(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_5_get_lc_tmap_g0_th10(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_5_get_lc_tmap_g0_th11(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_6                                               0x1802E0B8
#define  LC_LC_ToneMapping_grid0_6_reg_addr                                      "0xB802E0B8"
#define  LC_LC_ToneMapping_grid0_6_reg                                           0xB802E0B8
#define  LC_LC_ToneMapping_grid0_6_inst_addr                                     "0x002D"
#define  set_LC_LC_ToneMapping_grid0_6_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_6_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_6_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_6_reg))
#define  LC_LC_ToneMapping_grid0_6_lc_tmap_g0_th12_shift                         (16)
#define  LC_LC_ToneMapping_grid0_6_lc_tmap_g0_th13_shift                         (0)
#define  LC_LC_ToneMapping_grid0_6_lc_tmap_g0_th12_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_6_lc_tmap_g0_th13_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_6_lc_tmap_g0_th12(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_6_lc_tmap_g0_th13(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_6_get_lc_tmap_g0_th12(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_6_get_lc_tmap_g0_th13(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_7                                               0x1802E0BC
#define  LC_LC_ToneMapping_grid0_7_reg_addr                                      "0xB802E0BC"
#define  LC_LC_ToneMapping_grid0_7_reg                                           0xB802E0BC
#define  LC_LC_ToneMapping_grid0_7_inst_addr                                     "0x002E"
#define  set_LC_LC_ToneMapping_grid0_7_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_7_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_7_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_7_reg))
#define  LC_LC_ToneMapping_grid0_7_lc_tmap_g0_th14_shift                         (16)
#define  LC_LC_ToneMapping_grid0_7_lc_tmap_g0_th15_shift                         (0)
#define  LC_LC_ToneMapping_grid0_7_lc_tmap_g0_th14_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_7_lc_tmap_g0_th15_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_7_lc_tmap_g0_th14(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_7_lc_tmap_g0_th15(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_7_get_lc_tmap_g0_th14(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_7_get_lc_tmap_g0_th15(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_8                                               0x1802E0C0
#define  LC_LC_ToneMapping_grid0_8_reg_addr                                      "0xB802E0C0"
#define  LC_LC_ToneMapping_grid0_8_reg                                           0xB802E0C0
#define  LC_LC_ToneMapping_grid0_8_inst_addr                                     "0x002F"
#define  set_LC_LC_ToneMapping_grid0_8_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_8_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_8_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_8_reg))
#define  LC_LC_ToneMapping_grid0_8_lc_tmap_g0_th16_shift                         (16)
#define  LC_LC_ToneMapping_grid0_8_lc_tmap_g0_th17_shift                         (0)
#define  LC_LC_ToneMapping_grid0_8_lc_tmap_g0_th16_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_8_lc_tmap_g0_th17_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_8_lc_tmap_g0_th16(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_8_lc_tmap_g0_th17(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_8_get_lc_tmap_g0_th16(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_8_get_lc_tmap_g0_th17(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_9                                               0x1802E0C4
#define  LC_LC_ToneMapping_grid0_9_reg_addr                                      "0xB802E0C4"
#define  LC_LC_ToneMapping_grid0_9_reg                                           0xB802E0C4
#define  LC_LC_ToneMapping_grid0_9_inst_addr                                     "0x0030"
#define  set_LC_LC_ToneMapping_grid0_9_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_9_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_9_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_9_reg))
#define  LC_LC_ToneMapping_grid0_9_lc_tmap_g0_th18_shift                         (16)
#define  LC_LC_ToneMapping_grid0_9_lc_tmap_g0_th19_shift                         (0)
#define  LC_LC_ToneMapping_grid0_9_lc_tmap_g0_th18_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_9_lc_tmap_g0_th19_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_9_lc_tmap_g0_th18(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_9_lc_tmap_g0_th19(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_9_get_lc_tmap_g0_th18(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_9_get_lc_tmap_g0_th19(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_10                                              0x1802E0C8
#define  LC_LC_ToneMapping_grid0_10_reg_addr                                     "0xB802E0C8"
#define  LC_LC_ToneMapping_grid0_10_reg                                          0xB802E0C8
#define  LC_LC_ToneMapping_grid0_10_inst_addr                                    "0x0031"
#define  set_LC_LC_ToneMapping_grid0_10_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_10_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_10_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_10_reg))
#define  LC_LC_ToneMapping_grid0_10_lc_tmap_g0_th20_shift                        (16)
#define  LC_LC_ToneMapping_grid0_10_lc_tmap_g0_th21_shift                        (0)
#define  LC_LC_ToneMapping_grid0_10_lc_tmap_g0_th20_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_10_lc_tmap_g0_th21_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_10_lc_tmap_g0_th20(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_10_lc_tmap_g0_th21(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_10_get_lc_tmap_g0_th20(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_10_get_lc_tmap_g0_th21(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_11                                              0x1802E0CC
#define  LC_LC_ToneMapping_grid0_11_reg_addr                                     "0xB802E0CC"
#define  LC_LC_ToneMapping_grid0_11_reg                                          0xB802E0CC
#define  LC_LC_ToneMapping_grid0_11_inst_addr                                    "0x0032"
#define  set_LC_LC_ToneMapping_grid0_11_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_11_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_11_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_11_reg))
#define  LC_LC_ToneMapping_grid0_11_lc_tmap_g0_th22_shift                        (16)
#define  LC_LC_ToneMapping_grid0_11_lc_tmap_g0_th23_shift                        (0)
#define  LC_LC_ToneMapping_grid0_11_lc_tmap_g0_th22_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_11_lc_tmap_g0_th23_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_11_lc_tmap_g0_th22(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_11_lc_tmap_g0_th23(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_11_get_lc_tmap_g0_th22(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_11_get_lc_tmap_g0_th23(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_12                                              0x1802E0D0
#define  LC_LC_ToneMapping_grid0_12_reg_addr                                     "0xB802E0D0"
#define  LC_LC_ToneMapping_grid0_12_reg                                          0xB802E0D0
#define  LC_LC_ToneMapping_grid0_12_inst_addr                                    "0x0033"
#define  set_LC_LC_ToneMapping_grid0_12_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_12_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_12_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_12_reg))
#define  LC_LC_ToneMapping_grid0_12_lc_tmap_g0_th24_shift                        (16)
#define  LC_LC_ToneMapping_grid0_12_lc_tmap_g0_th25_shift                        (0)
#define  LC_LC_ToneMapping_grid0_12_lc_tmap_g0_th24_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_12_lc_tmap_g0_th25_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_12_lc_tmap_g0_th24(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_12_lc_tmap_g0_th25(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_12_get_lc_tmap_g0_th24(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_12_get_lc_tmap_g0_th25(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_13                                              0x1802E0D4
#define  LC_LC_ToneMapping_grid0_13_reg_addr                                     "0xB802E0D4"
#define  LC_LC_ToneMapping_grid0_13_reg                                          0xB802E0D4
#define  LC_LC_ToneMapping_grid0_13_inst_addr                                    "0x0034"
#define  set_LC_LC_ToneMapping_grid0_13_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_13_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_13_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_13_reg))
#define  LC_LC_ToneMapping_grid0_13_lc_tmap_g0_th26_shift                        (16)
#define  LC_LC_ToneMapping_grid0_13_lc_tmap_g0_th27_shift                        (0)
#define  LC_LC_ToneMapping_grid0_13_lc_tmap_g0_th26_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_13_lc_tmap_g0_th27_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_13_lc_tmap_g0_th26(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_13_lc_tmap_g0_th27(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_13_get_lc_tmap_g0_th26(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_13_get_lc_tmap_g0_th27(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_14                                              0x1802E0D8
#define  LC_LC_ToneMapping_grid0_14_reg_addr                                     "0xB802E0D8"
#define  LC_LC_ToneMapping_grid0_14_reg                                          0xB802E0D8
#define  LC_LC_ToneMapping_grid0_14_inst_addr                                    "0x0035"
#define  set_LC_LC_ToneMapping_grid0_14_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_14_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_14_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_14_reg))
#define  LC_LC_ToneMapping_grid0_14_lc_tmap_g0_th28_shift                        (16)
#define  LC_LC_ToneMapping_grid0_14_lc_tmap_g0_th29_shift                        (0)
#define  LC_LC_ToneMapping_grid0_14_lc_tmap_g0_th28_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_14_lc_tmap_g0_th29_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_14_lc_tmap_g0_th28(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_14_lc_tmap_g0_th29(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_14_get_lc_tmap_g0_th28(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_14_get_lc_tmap_g0_th29(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid0_15                                              0x1802E0DC
#define  LC_LC_ToneMapping_grid0_15_reg_addr                                     "0xB802E0DC"
#define  LC_LC_ToneMapping_grid0_15_reg                                          0xB802E0DC
#define  LC_LC_ToneMapping_grid0_15_inst_addr                                    "0x0036"
#define  set_LC_LC_ToneMapping_grid0_15_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_15_reg)=data)
#define  get_LC_LC_ToneMapping_grid0_15_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid0_15_reg))
#define  LC_LC_ToneMapping_grid0_15_lc_tmap_g0_th30_shift                        (16)
#define  LC_LC_ToneMapping_grid0_15_lc_tmap_g0_th31_shift                        (0)
#define  LC_LC_ToneMapping_grid0_15_lc_tmap_g0_th30_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid0_15_lc_tmap_g0_th31_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid0_15_lc_tmap_g0_th30(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid0_15_lc_tmap_g0_th31(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid0_15_get_lc_tmap_g0_th30(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid0_15_get_lc_tmap_g0_th31(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_0                                               0x1802E0E0
#define  LC_LC_ToneMapping_grid2_0_reg_addr                                      "0xB802E0E0"
#define  LC_LC_ToneMapping_grid2_0_reg                                           0xB802E0E0
#define  LC_LC_ToneMapping_grid2_0_inst_addr                                     "0x0037"
#define  set_LC_LC_ToneMapping_grid2_0_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_0_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_0_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_0_reg))
#define  LC_LC_ToneMapping_grid2_0_lc_tmap_g2_th1_shift                          (0)
#define  LC_LC_ToneMapping_grid2_0_lc_tmap_g2_th1_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_0_lc_tmap_g2_th1(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_0_get_lc_tmap_g2_th1(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_1                                               0x1802E0E4
#define  LC_LC_ToneMapping_grid2_1_reg_addr                                      "0xB802E0E4"
#define  LC_LC_ToneMapping_grid2_1_reg                                           0xB802E0E4
#define  LC_LC_ToneMapping_grid2_1_inst_addr                                     "0x0038"
#define  set_LC_LC_ToneMapping_grid2_1_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_1_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_1_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_1_reg))
#define  LC_LC_ToneMapping_grid2_1_lc_tmap_g2_th2_shift                          (16)
#define  LC_LC_ToneMapping_grid2_1_lc_tmap_g2_th3_shift                          (0)
#define  LC_LC_ToneMapping_grid2_1_lc_tmap_g2_th2_mask                           (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_1_lc_tmap_g2_th3_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_1_lc_tmap_g2_th2(data)                          (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_1_lc_tmap_g2_th3(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_1_get_lc_tmap_g2_th2(data)                      ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_1_get_lc_tmap_g2_th3(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_2                                               0x1802E0E8
#define  LC_LC_ToneMapping_grid2_2_reg_addr                                      "0xB802E0E8"
#define  LC_LC_ToneMapping_grid2_2_reg                                           0xB802E0E8
#define  LC_LC_ToneMapping_grid2_2_inst_addr                                     "0x0039"
#define  set_LC_LC_ToneMapping_grid2_2_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_2_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_2_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_2_reg))
#define  LC_LC_ToneMapping_grid2_2_lc_tmap_g2_th4_shift                          (16)
#define  LC_LC_ToneMapping_grid2_2_lc_tmap_g2_th5_shift                          (0)
#define  LC_LC_ToneMapping_grid2_2_lc_tmap_g2_th4_mask                           (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_2_lc_tmap_g2_th5_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_2_lc_tmap_g2_th4(data)                          (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_2_lc_tmap_g2_th5(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_2_get_lc_tmap_g2_th4(data)                      ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_2_get_lc_tmap_g2_th5(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_3                                               0x1802E0EC
#define  LC_LC_ToneMapping_grid2_3_reg_addr                                      "0xB802E0EC"
#define  LC_LC_ToneMapping_grid2_3_reg                                           0xB802E0EC
#define  LC_LC_ToneMapping_grid2_3_inst_addr                                     "0x003A"
#define  set_LC_LC_ToneMapping_grid2_3_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_3_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_3_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_3_reg))
#define  LC_LC_ToneMapping_grid2_3_lc_tmap_g2_th6_shift                          (16)
#define  LC_LC_ToneMapping_grid2_3_lc_tmap_g2_th7_shift                          (0)
#define  LC_LC_ToneMapping_grid2_3_lc_tmap_g2_th6_mask                           (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_3_lc_tmap_g2_th7_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_3_lc_tmap_g2_th6(data)                          (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_3_lc_tmap_g2_th7(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_3_get_lc_tmap_g2_th6(data)                      ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_3_get_lc_tmap_g2_th7(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_4                                               0x1802E0F0
#define  LC_LC_ToneMapping_grid2_4_reg_addr                                      "0xB802E0F0"
#define  LC_LC_ToneMapping_grid2_4_reg                                           0xB802E0F0
#define  LC_LC_ToneMapping_grid2_4_inst_addr                                     "0x003B"
#define  set_LC_LC_ToneMapping_grid2_4_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_4_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_4_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_4_reg))
#define  LC_LC_ToneMapping_grid2_4_lc_tmap_g2_th8_shift                          (16)
#define  LC_LC_ToneMapping_grid2_4_lc_tmap_g2_th9_shift                          (0)
#define  LC_LC_ToneMapping_grid2_4_lc_tmap_g2_th8_mask                           (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_4_lc_tmap_g2_th9_mask                           (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_4_lc_tmap_g2_th8(data)                          (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_4_lc_tmap_g2_th9(data)                          (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_4_get_lc_tmap_g2_th8(data)                      ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_4_get_lc_tmap_g2_th9(data)                      (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_5                                               0x1802E0F4
#define  LC_LC_ToneMapping_grid2_5_reg_addr                                      "0xB802E0F4"
#define  LC_LC_ToneMapping_grid2_5_reg                                           0xB802E0F4
#define  LC_LC_ToneMapping_grid2_5_inst_addr                                     "0x003C"
#define  set_LC_LC_ToneMapping_grid2_5_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_5_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_5_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_5_reg))
#define  LC_LC_ToneMapping_grid2_5_lc_tmap_g2_th10_shift                         (16)
#define  LC_LC_ToneMapping_grid2_5_lc_tmap_g2_th11_shift                         (0)
#define  LC_LC_ToneMapping_grid2_5_lc_tmap_g2_th10_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_5_lc_tmap_g2_th11_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_5_lc_tmap_g2_th10(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_5_lc_tmap_g2_th11(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_5_get_lc_tmap_g2_th10(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_5_get_lc_tmap_g2_th11(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_6                                               0x1802E0F8
#define  LC_LC_ToneMapping_grid2_6_reg_addr                                      "0xB802E0F8"
#define  LC_LC_ToneMapping_grid2_6_reg                                           0xB802E0F8
#define  LC_LC_ToneMapping_grid2_6_inst_addr                                     "0x003D"
#define  set_LC_LC_ToneMapping_grid2_6_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_6_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_6_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_6_reg))
#define  LC_LC_ToneMapping_grid2_6_lc_tmap_g2_th12_shift                         (16)
#define  LC_LC_ToneMapping_grid2_6_lc_tmap_g2_th13_shift                         (0)
#define  LC_LC_ToneMapping_grid2_6_lc_tmap_g2_th12_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_6_lc_tmap_g2_th13_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_6_lc_tmap_g2_th12(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_6_lc_tmap_g2_th13(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_6_get_lc_tmap_g2_th12(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_6_get_lc_tmap_g2_th13(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_7                                               0x1802E0FC
#define  LC_LC_ToneMapping_grid2_7_reg_addr                                      "0xB802E0FC"
#define  LC_LC_ToneMapping_grid2_7_reg                                           0xB802E0FC
#define  LC_LC_ToneMapping_grid2_7_inst_addr                                     "0x003E"
#define  set_LC_LC_ToneMapping_grid2_7_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_7_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_7_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_7_reg))
#define  LC_LC_ToneMapping_grid2_7_lc_tmap_g2_th14_shift                         (16)
#define  LC_LC_ToneMapping_grid2_7_lc_tmap_g2_th15_shift                         (0)
#define  LC_LC_ToneMapping_grid2_7_lc_tmap_g2_th14_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_7_lc_tmap_g2_th15_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_7_lc_tmap_g2_th14(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_7_lc_tmap_g2_th15(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_7_get_lc_tmap_g2_th14(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_7_get_lc_tmap_g2_th15(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_8                                               0x1802E100
#define  LC_LC_ToneMapping_grid2_8_reg_addr                                      "0xB802E100"
#define  LC_LC_ToneMapping_grid2_8_reg                                           0xB802E100
#define  LC_LC_ToneMapping_grid2_8_inst_addr                                     "0x003F"
#define  set_LC_LC_ToneMapping_grid2_8_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_8_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_8_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_8_reg))
#define  LC_LC_ToneMapping_grid2_8_lc_tmap_g2_th16_shift                         (16)
#define  LC_LC_ToneMapping_grid2_8_lc_tmap_g2_th17_shift                         (0)
#define  LC_LC_ToneMapping_grid2_8_lc_tmap_g2_th16_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_8_lc_tmap_g2_th17_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_8_lc_tmap_g2_th16(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_8_lc_tmap_g2_th17(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_8_get_lc_tmap_g2_th16(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_8_get_lc_tmap_g2_th17(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_9                                               0x1802E104
#define  LC_LC_ToneMapping_grid2_9_reg_addr                                      "0xB802E104"
#define  LC_LC_ToneMapping_grid2_9_reg                                           0xB802E104
#define  LC_LC_ToneMapping_grid2_9_inst_addr                                     "0x0040"
#define  set_LC_LC_ToneMapping_grid2_9_reg(data)                                 (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_9_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_9_reg                                       (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_9_reg))
#define  LC_LC_ToneMapping_grid2_9_lc_tmap_g2_th18_shift                         (16)
#define  LC_LC_ToneMapping_grid2_9_lc_tmap_g2_th19_shift                         (0)
#define  LC_LC_ToneMapping_grid2_9_lc_tmap_g2_th18_mask                          (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_9_lc_tmap_g2_th19_mask                          (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_9_lc_tmap_g2_th18(data)                         (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_9_lc_tmap_g2_th19(data)                         (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_9_get_lc_tmap_g2_th18(data)                     ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_9_get_lc_tmap_g2_th19(data)                     (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_10                                              0x1802E108
#define  LC_LC_ToneMapping_grid2_10_reg_addr                                     "0xB802E108"
#define  LC_LC_ToneMapping_grid2_10_reg                                          0xB802E108
#define  LC_LC_ToneMapping_grid2_10_inst_addr                                    "0x0041"
#define  set_LC_LC_ToneMapping_grid2_10_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_10_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_10_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_10_reg))
#define  LC_LC_ToneMapping_grid2_10_lc_tmap_g2_th20_shift                        (16)
#define  LC_LC_ToneMapping_grid2_10_lc_tmap_g2_th21_shift                        (0)
#define  LC_LC_ToneMapping_grid2_10_lc_tmap_g2_th20_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_10_lc_tmap_g2_th21_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_10_lc_tmap_g2_th20(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_10_lc_tmap_g2_th21(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_10_get_lc_tmap_g2_th20(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_10_get_lc_tmap_g2_th21(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_11                                              0x1802E10C
#define  LC_LC_ToneMapping_grid2_11_reg_addr                                     "0xB802E10C"
#define  LC_LC_ToneMapping_grid2_11_reg                                          0xB802E10C
#define  LC_LC_ToneMapping_grid2_11_inst_addr                                    "0x0042"
#define  set_LC_LC_ToneMapping_grid2_11_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_11_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_11_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_11_reg))
#define  LC_LC_ToneMapping_grid2_11_lc_tmap_g2_th22_shift                        (16)
#define  LC_LC_ToneMapping_grid2_11_lc_tmap_g2_th23_shift                        (0)
#define  LC_LC_ToneMapping_grid2_11_lc_tmap_g2_th22_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_11_lc_tmap_g2_th23_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_11_lc_tmap_g2_th22(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_11_lc_tmap_g2_th23(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_11_get_lc_tmap_g2_th22(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_11_get_lc_tmap_g2_th23(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_12                                              0x1802E110
#define  LC_LC_ToneMapping_grid2_12_reg_addr                                     "0xB802E110"
#define  LC_LC_ToneMapping_grid2_12_reg                                          0xB802E110
#define  LC_LC_ToneMapping_grid2_12_inst_addr                                    "0x0043"
#define  set_LC_LC_ToneMapping_grid2_12_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_12_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_12_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_12_reg))
#define  LC_LC_ToneMapping_grid2_12_lc_tmap_g2_th24_shift                        (16)
#define  LC_LC_ToneMapping_grid2_12_lc_tmap_g2_th25_shift                        (0)
#define  LC_LC_ToneMapping_grid2_12_lc_tmap_g2_th24_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_12_lc_tmap_g2_th25_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_12_lc_tmap_g2_th24(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_12_lc_tmap_g2_th25(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_12_get_lc_tmap_g2_th24(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_12_get_lc_tmap_g2_th25(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_13                                              0x1802E114
#define  LC_LC_ToneMapping_grid2_13_reg_addr                                     "0xB802E114"
#define  LC_LC_ToneMapping_grid2_13_reg                                          0xB802E114
#define  LC_LC_ToneMapping_grid2_13_inst_addr                                    "0x0044"
#define  set_LC_LC_ToneMapping_grid2_13_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_13_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_13_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_13_reg))
#define  LC_LC_ToneMapping_grid2_13_lc_tmap_g2_th26_shift                        (16)
#define  LC_LC_ToneMapping_grid2_13_lc_tmap_g2_th27_shift                        (0)
#define  LC_LC_ToneMapping_grid2_13_lc_tmap_g2_th26_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_13_lc_tmap_g2_th27_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_13_lc_tmap_g2_th26(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_13_lc_tmap_g2_th27(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_13_get_lc_tmap_g2_th26(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_13_get_lc_tmap_g2_th27(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_14                                              0x1802E118
#define  LC_LC_ToneMapping_grid2_14_reg_addr                                     "0xB802E118"
#define  LC_LC_ToneMapping_grid2_14_reg                                          0xB802E118
#define  LC_LC_ToneMapping_grid2_14_inst_addr                                    "0x0045"
#define  set_LC_LC_ToneMapping_grid2_14_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_14_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_14_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_14_reg))
#define  LC_LC_ToneMapping_grid2_14_lc_tmap_g2_th28_shift                        (16)
#define  LC_LC_ToneMapping_grid2_14_lc_tmap_g2_th29_shift                        (0)
#define  LC_LC_ToneMapping_grid2_14_lc_tmap_g2_th28_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_14_lc_tmap_g2_th29_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_14_lc_tmap_g2_th28(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_14_lc_tmap_g2_th29(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_14_get_lc_tmap_g2_th28(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_14_get_lc_tmap_g2_th29(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_grid2_15                                              0x1802E11C
#define  LC_LC_ToneMapping_grid2_15_reg_addr                                     "0xB802E11C"
#define  LC_LC_ToneMapping_grid2_15_reg                                          0xB802E11C
#define  LC_LC_ToneMapping_grid2_15_inst_addr                                    "0x0046"
#define  set_LC_LC_ToneMapping_grid2_15_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_15_reg)=data)
#define  get_LC_LC_ToneMapping_grid2_15_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_grid2_15_reg))
#define  LC_LC_ToneMapping_grid2_15_lc_tmap_g2_th30_shift                        (16)
#define  LC_LC_ToneMapping_grid2_15_lc_tmap_g2_th31_shift                        (0)
#define  LC_LC_ToneMapping_grid2_15_lc_tmap_g2_th30_mask                         (0x0FFF0000)
#define  LC_LC_ToneMapping_grid2_15_lc_tmap_g2_th31_mask                         (0x00000FFF)
#define  LC_LC_ToneMapping_grid2_15_lc_tmap_g2_th30(data)                        (0x0FFF0000&((data)<<16))
#define  LC_LC_ToneMapping_grid2_15_lc_tmap_g2_th31(data)                        (0x00000FFF&(data))
#define  LC_LC_ToneMapping_grid2_15_get_lc_tmap_g2_th30(data)                    ((0x0FFF0000&(data))>>16)
#define  LC_LC_ToneMapping_grid2_15_get_lc_tmap_g2_th31(data)                    (0x00000FFF&(data))

#define  LC_LC_ToneMapping_Curve_sel_0                                           0x1802E120
#define  LC_LC_ToneMapping_Curve_sel_0_reg_addr                                  "0xB802E120"
#define  LC_LC_ToneMapping_Curve_sel_0_reg                                       0xB802E120
#define  LC_LC_ToneMapping_Curve_sel_0_inst_addr                                 "0x0047"
#define  set_LC_LC_ToneMapping_Curve_sel_0_reg(data)                             (*((volatile unsigned int*)LC_LC_ToneMapping_Curve_sel_0_reg)=data)
#define  get_LC_LC_ToneMapping_Curve_sel_0_reg                                   (*((volatile unsigned int*)LC_LC_ToneMapping_Curve_sel_0_reg))
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve0_grid_shift                 (28)
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve0_tone_shift                 (16)
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve1_grid_shift                 (12)
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve1_tone_shift                 (0)
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve0_grid_mask                  (0x30000000)
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve0_tone_mask                  (0x03FF0000)
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve1_grid_mask                  (0x00003000)
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve1_tone_mask                  (0x000003FF)
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve0_grid(data)                 (0x30000000&((data)<<28))
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve0_tone(data)                 (0x03FF0000&((data)<<16))
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve1_grid(data)                 (0x00003000&((data)<<12))
#define  LC_LC_ToneMapping_Curve_sel_0_lc_tmap_curve1_tone(data)                 (0x000003FF&(data))
#define  LC_LC_ToneMapping_Curve_sel_0_get_lc_tmap_curve0_grid(data)             ((0x30000000&(data))>>28)
#define  LC_LC_ToneMapping_Curve_sel_0_get_lc_tmap_curve0_tone(data)             ((0x03FF0000&(data))>>16)
#define  LC_LC_ToneMapping_Curve_sel_0_get_lc_tmap_curve1_grid(data)             ((0x00003000&(data))>>12)
#define  LC_LC_ToneMapping_Curve_sel_0_get_lc_tmap_curve1_tone(data)             (0x000003FF&(data))

#define  LC_LC_ToneMapping_Curve_sel_1                                           0x1802E124
#define  LC_LC_ToneMapping_Curve_sel_1_reg_addr                                  "0xB802E124"
#define  LC_LC_ToneMapping_Curve_sel_1_reg                                       0xB802E124
#define  LC_LC_ToneMapping_Curve_sel_1_inst_addr                                 "0x0048"
#define  set_LC_LC_ToneMapping_Curve_sel_1_reg(data)                             (*((volatile unsigned int*)LC_LC_ToneMapping_Curve_sel_1_reg)=data)
#define  get_LC_LC_ToneMapping_Curve_sel_1_reg                                   (*((volatile unsigned int*)LC_LC_ToneMapping_Curve_sel_1_reg))
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve2_grid_shift                 (28)
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve2_tone_shift                 (16)
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve3_grid_shift                 (12)
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve3_tone_shift                 (0)
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve2_grid_mask                  (0x30000000)
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve2_tone_mask                  (0x03FF0000)
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve3_grid_mask                  (0x00003000)
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve3_tone_mask                  (0x000003FF)
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve2_grid(data)                 (0x30000000&((data)<<28))
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve2_tone(data)                 (0x03FF0000&((data)<<16))
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve3_grid(data)                 (0x00003000&((data)<<12))
#define  LC_LC_ToneMapping_Curve_sel_1_lc_tmap_curve3_tone(data)                 (0x000003FF&(data))
#define  LC_LC_ToneMapping_Curve_sel_1_get_lc_tmap_curve2_grid(data)             ((0x30000000&(data))>>28)
#define  LC_LC_ToneMapping_Curve_sel_1_get_lc_tmap_curve2_tone(data)             ((0x03FF0000&(data))>>16)
#define  LC_LC_ToneMapping_Curve_sel_1_get_lc_tmap_curve3_grid(data)             ((0x00003000&(data))>>12)
#define  LC_LC_ToneMapping_Curve_sel_1_get_lc_tmap_curve3_tone(data)             (0x000003FF&(data))

#define  LC_LC_ToneMapping_Curve_sel_2                                           0x1802E128
#define  LC_LC_ToneMapping_Curve_sel_2_reg_addr                                  "0xB802E128"
#define  LC_LC_ToneMapping_Curve_sel_2_reg                                       0xB802E128
#define  LC_LC_ToneMapping_Curve_sel_2_inst_addr                                 "0x0049"
#define  set_LC_LC_ToneMapping_Curve_sel_2_reg(data)                             (*((volatile unsigned int*)LC_LC_ToneMapping_Curve_sel_2_reg)=data)
#define  get_LC_LC_ToneMapping_Curve_sel_2_reg                                   (*((volatile unsigned int*)LC_LC_ToneMapping_Curve_sel_2_reg))
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve4_grid_shift                 (28)
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve4_tone_shift                 (16)
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve5_grid_shift                 (12)
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve5_tone_shift                 (0)
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve4_grid_mask                  (0x30000000)
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve4_tone_mask                  (0x03FF0000)
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve5_grid_mask                  (0x00003000)
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve5_tone_mask                  (0x000003FF)
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve4_grid(data)                 (0x30000000&((data)<<28))
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve4_tone(data)                 (0x03FF0000&((data)<<16))
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve5_grid(data)                 (0x00003000&((data)<<12))
#define  LC_LC_ToneMapping_Curve_sel_2_lc_tmap_curve5_tone(data)                 (0x000003FF&(data))
#define  LC_LC_ToneMapping_Curve_sel_2_get_lc_tmap_curve4_grid(data)             ((0x30000000&(data))>>28)
#define  LC_LC_ToneMapping_Curve_sel_2_get_lc_tmap_curve4_tone(data)             ((0x03FF0000&(data))>>16)
#define  LC_LC_ToneMapping_Curve_sel_2_get_lc_tmap_curve5_grid(data)             ((0x00003000&(data))>>12)
#define  LC_LC_ToneMapping_Curve_sel_2_get_lc_tmap_curve5_tone(data)             (0x000003FF&(data))

#define  LC_LC_ToneMapping_Curve_sel_3                                           0x1802E12C
#define  LC_LC_ToneMapping_Curve_sel_3_reg_addr                                  "0xB802E12C"
#define  LC_LC_ToneMapping_Curve_sel_3_reg                                       0xB802E12C
#define  LC_LC_ToneMapping_Curve_sel_3_inst_addr                                 "0x004A"
#define  set_LC_LC_ToneMapping_Curve_sel_3_reg(data)                             (*((volatile unsigned int*)LC_LC_ToneMapping_Curve_sel_3_reg)=data)
#define  get_LC_LC_ToneMapping_Curve_sel_3_reg                                   (*((volatile unsigned int*)LC_LC_ToneMapping_Curve_sel_3_reg))
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve6_grid_shift                 (28)
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve6_tone_shift                 (16)
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve7_grid_shift                 (12)
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve7_tone_shift                 (0)
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve6_grid_mask                  (0x30000000)
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve6_tone_mask                  (0x03FF0000)
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve7_grid_mask                  (0x00003000)
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve7_tone_mask                  (0x000003FF)
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve6_grid(data)                 (0x30000000&((data)<<28))
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve6_tone(data)                 (0x03FF0000&((data)<<16))
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve7_grid(data)                 (0x00003000&((data)<<12))
#define  LC_LC_ToneMapping_Curve_sel_3_lc_tmap_curve7_tone(data)                 (0x000003FF&(data))
#define  LC_LC_ToneMapping_Curve_sel_3_get_lc_tmap_curve6_grid(data)             ((0x30000000&(data))>>28)
#define  LC_LC_ToneMapping_Curve_sel_3_get_lc_tmap_curve6_tone(data)             ((0x03FF0000&(data))>>16)
#define  LC_LC_ToneMapping_Curve_sel_3_get_lc_tmap_curve7_grid(data)             ((0x00003000&(data))>>12)
#define  LC_LC_ToneMapping_Curve_sel_3_get_lc_tmap_curve7_tone(data)             (0x000003FF&(data))

#define  LC_LC_ToneMapping_SRAM_Addr                                             0x1802E130
#define  LC_LC_ToneMapping_SRAM_Addr_reg_addr                                    "0xB802E130"
#define  LC_LC_ToneMapping_SRAM_Addr_reg                                         0xB802E130
#define  LC_LC_ToneMapping_SRAM_Addr_inst_addr                                   "0x004B"
#define  set_LC_LC_ToneMapping_SRAM_Addr_reg(data)                               (*((volatile unsigned int*)LC_LC_ToneMapping_SRAM_Addr_reg)=data)
#define  get_LC_LC_ToneMapping_SRAM_Addr_reg                                     (*((volatile unsigned int*)LC_LC_ToneMapping_SRAM_Addr_reg))
#define  LC_LC_ToneMapping_SRAM_Addr_lc_tmap_sram_num_shift                      (16)
#define  LC_LC_ToneMapping_SRAM_Addr_lc_tmap_sram_addr_shift                     (0)
#define  LC_LC_ToneMapping_SRAM_Addr_lc_tmap_sram_num_mask                       (0x00070000)
#define  LC_LC_ToneMapping_SRAM_Addr_lc_tmap_sram_addr_mask                      (0x0000001F)
#define  LC_LC_ToneMapping_SRAM_Addr_lc_tmap_sram_num(data)                      (0x00070000&((data)<<16))
#define  LC_LC_ToneMapping_SRAM_Addr_lc_tmap_sram_addr(data)                     (0x0000001F&(data))
#define  LC_LC_ToneMapping_SRAM_Addr_get_lc_tmap_sram_num(data)                  ((0x00070000&(data))>>16)
#define  LC_LC_ToneMapping_SRAM_Addr_get_lc_tmap_sram_addr(data)                 (0x0000001F&(data))

#define  LC_LC_ToneMapping_SRAM_Data                                             0x1802E134
#define  LC_LC_ToneMapping_SRAM_Data_reg_addr                                    "0xB802E134"
#define  LC_LC_ToneMapping_SRAM_Data_reg                                         0xB802E134
#define  LC_LC_ToneMapping_SRAM_Data_inst_addr                                   "0x004C"
#define  set_LC_LC_ToneMapping_SRAM_Data_reg(data)                               (*((volatile unsigned int*)LC_LC_ToneMapping_SRAM_Data_reg)=data)
#define  get_LC_LC_ToneMapping_SRAM_Data_reg                                     (*((volatile unsigned int*)LC_LC_ToneMapping_SRAM_Data_reg))
#define  LC_LC_ToneMapping_SRAM_Data_lc_tmap_sram_ds_shift                       (16)
#define  LC_LC_ToneMapping_SRAM_Data_lc_tmap_sram_dp_shift                       (0)
#define  LC_LC_ToneMapping_SRAM_Data_lc_tmap_sram_ds_mask                        (0x00FF0000)
#define  LC_LC_ToneMapping_SRAM_Data_lc_tmap_sram_dp_mask                        (0x00000FFF)
#define  LC_LC_ToneMapping_SRAM_Data_lc_tmap_sram_ds(data)                       (0x00FF0000&((data)<<16))
#define  LC_LC_ToneMapping_SRAM_Data_lc_tmap_sram_dp(data)                       (0x00000FFF&(data))
#define  LC_LC_ToneMapping_SRAM_Data_get_lc_tmap_sram_ds(data)                   ((0x00FF0000&(data))>>16)
#define  LC_LC_ToneMapping_SRAM_Data_get_lc_tmap_sram_dp(data)                   (0x00000FFF&(data))

#define  LC_LC_ToneMapping_blending                                              0x1802E138
#define  LC_LC_ToneMapping_blending_reg_addr                                     "0xB802E138"
#define  LC_LC_ToneMapping_blending_reg                                          0xB802E138
#define  LC_LC_ToneMapping_blending_inst_addr                                    "0x004D"
#define  set_LC_LC_ToneMapping_blending_reg(data)                                (*((volatile unsigned int*)LC_LC_ToneMapping_blending_reg)=data)
#define  get_LC_LC_ToneMapping_blending_reg                                      (*((volatile unsigned int*)LC_LC_ToneMapping_blending_reg))
#define  LC_LC_ToneMapping_blending_lc_tmap_slope_unit_shift                     (16)
#define  LC_LC_ToneMapping_blending_lc_tmap_blend_factor_shift                   (0)
#define  LC_LC_ToneMapping_blending_lc_tmap_slope_unit_mask                      (0x00010000)
#define  LC_LC_ToneMapping_blending_lc_tmap_blend_factor_mask                    (0x000000FF)
#define  LC_LC_ToneMapping_blending_lc_tmap_slope_unit(data)                     (0x00010000&((data)<<16))
#define  LC_LC_ToneMapping_blending_lc_tmap_blend_factor(data)                   (0x000000FF&(data))
#define  LC_LC_ToneMapping_blending_get_lc_tmap_slope_unit(data)                 ((0x00010000&(data))>>16)
#define  LC_LC_ToneMapping_blending_get_lc_tmap_blend_factor(data)               (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_1st_gain_0                                            0x1802E140
#define  LC_LC_Local_Shpnr_1st_gain_0_reg_addr                                   "0xB802E140"
#define  LC_LC_Local_Shpnr_1st_gain_0_reg                                        0xB802E140
#define  LC_LC_Local_Shpnr_1st_gain_0_inst_addr                                  "0x004E"
#define  set_LC_LC_Local_Shpnr_1st_gain_0_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_0_reg)=data)
#define  get_LC_LC_Local_Shpnr_1st_gain_0_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_0_reg))
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_0_shift                     (24)
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_1_shift                     (16)
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_2_shift                     (8)
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_3_shift                     (0)
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_0_mask                      (0xFF000000)
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_1_mask                      (0x00FF0000)
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_2_mask                      (0x0000FF00)
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_3_mask                      (0x000000FF)
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_0(data)                     (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_1(data)                     (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_2(data)                     (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_1st_gain_0_lc_gain_by_yin_3(data)                     (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_1st_gain_0_get_lc_gain_by_yin_0(data)                 ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_1st_gain_0_get_lc_gain_by_yin_1(data)                 ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_1st_gain_0_get_lc_gain_by_yin_2(data)                 ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_1st_gain_0_get_lc_gain_by_yin_3(data)                 (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_1st_gain_1                                            0x1802E144
#define  LC_LC_Local_Shpnr_1st_gain_1_reg_addr                                   "0xB802E144"
#define  LC_LC_Local_Shpnr_1st_gain_1_reg                                        0xB802E144
#define  LC_LC_Local_Shpnr_1st_gain_1_inst_addr                                  "0x004F"
#define  set_LC_LC_Local_Shpnr_1st_gain_1_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_1_reg)=data)
#define  get_LC_LC_Local_Shpnr_1st_gain_1_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_1_reg))
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_4_shift                     (24)
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_5_shift                     (16)
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_6_shift                     (8)
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_7_shift                     (0)
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_4_mask                      (0xFF000000)
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_5_mask                      (0x00FF0000)
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_6_mask                      (0x0000FF00)
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_7_mask                      (0x000000FF)
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_4(data)                     (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_5(data)                     (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_6(data)                     (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_1st_gain_1_lc_gain_by_yin_7(data)                     (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_1st_gain_1_get_lc_gain_by_yin_4(data)                 ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_1st_gain_1_get_lc_gain_by_yin_5(data)                 ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_1st_gain_1_get_lc_gain_by_yin_6(data)                 ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_1st_gain_1_get_lc_gain_by_yin_7(data)                 (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_1st_gain_2                                            0x1802E148
#define  LC_LC_Local_Shpnr_1st_gain_2_reg_addr                                   "0xB802E148"
#define  LC_LC_Local_Shpnr_1st_gain_2_reg                                        0xB802E148
#define  LC_LC_Local_Shpnr_1st_gain_2_inst_addr                                  "0x0050"
#define  set_LC_LC_Local_Shpnr_1st_gain_2_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_2_reg)=data)
#define  get_LC_LC_Local_Shpnr_1st_gain_2_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_2_reg))
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_8_shift                     (24)
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_9_shift                     (16)
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_10_shift                    (8)
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_11_shift                    (0)
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_8_mask                      (0xFF000000)
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_9_mask                      (0x00FF0000)
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_10_mask                     (0x0000FF00)
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_11_mask                     (0x000000FF)
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_8(data)                     (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_9(data)                     (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_10(data)                    (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_1st_gain_2_lc_gain_by_yin_11(data)                    (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_1st_gain_2_get_lc_gain_by_yin_8(data)                 ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_1st_gain_2_get_lc_gain_by_yin_9(data)                 ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_1st_gain_2_get_lc_gain_by_yin_10(data)                ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_1st_gain_2_get_lc_gain_by_yin_11(data)                (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_1st_gain_3                                            0x1802E14C
#define  LC_LC_Local_Shpnr_1st_gain_3_reg_addr                                   "0xB802E14C"
#define  LC_LC_Local_Shpnr_1st_gain_3_reg                                        0xB802E14C
#define  LC_LC_Local_Shpnr_1st_gain_3_inst_addr                                  "0x0051"
#define  set_LC_LC_Local_Shpnr_1st_gain_3_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_3_reg)=data)
#define  get_LC_LC_Local_Shpnr_1st_gain_3_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_3_reg))
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_12_shift                    (24)
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_13_shift                    (16)
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_14_shift                    (8)
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_15_shift                    (0)
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_12_mask                     (0xFF000000)
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_13_mask                     (0x00FF0000)
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_14_mask                     (0x0000FF00)
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_15_mask                     (0x000000FF)
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_12(data)                    (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_13(data)                    (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_14(data)                    (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_1st_gain_3_lc_gain_by_yin_15(data)                    (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_1st_gain_3_get_lc_gain_by_yin_12(data)                ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_1st_gain_3_get_lc_gain_by_yin_13(data)                ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_1st_gain_3_get_lc_gain_by_yin_14(data)                ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_1st_gain_3_get_lc_gain_by_yin_15(data)                (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_1st_gain_4                                            0x1802E150
#define  LC_LC_Local_Shpnr_1st_gain_4_reg_addr                                   "0xB802E150"
#define  LC_LC_Local_Shpnr_1st_gain_4_reg                                        0xB802E150
#define  LC_LC_Local_Shpnr_1st_gain_4_inst_addr                                  "0x0052"
#define  set_LC_LC_Local_Shpnr_1st_gain_4_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_4_reg)=data)
#define  get_LC_LC_Local_Shpnr_1st_gain_4_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_4_reg))
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_16_shift                    (24)
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_17_shift                    (16)
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_18_shift                    (8)
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_19_shift                    (0)
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_16_mask                     (0xFF000000)
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_17_mask                     (0x00FF0000)
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_18_mask                     (0x0000FF00)
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_19_mask                     (0x000000FF)
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_16(data)                    (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_17(data)                    (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_18(data)                    (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_1st_gain_4_lc_gain_by_yin_19(data)                    (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_1st_gain_4_get_lc_gain_by_yin_16(data)                ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_1st_gain_4_get_lc_gain_by_yin_17(data)                ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_1st_gain_4_get_lc_gain_by_yin_18(data)                ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_1st_gain_4_get_lc_gain_by_yin_19(data)                (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_1st_gain_5                                            0x1802E154
#define  LC_LC_Local_Shpnr_1st_gain_5_reg_addr                                   "0xB802E154"
#define  LC_LC_Local_Shpnr_1st_gain_5_reg                                        0xB802E154
#define  LC_LC_Local_Shpnr_1st_gain_5_inst_addr                                  "0x0053"
#define  set_LC_LC_Local_Shpnr_1st_gain_5_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_5_reg)=data)
#define  get_LC_LC_Local_Shpnr_1st_gain_5_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_5_reg))
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_20_shift                    (24)
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_21_shift                    (16)
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_22_shift                    (8)
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_23_shift                    (0)
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_20_mask                     (0xFF000000)
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_21_mask                     (0x00FF0000)
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_22_mask                     (0x0000FF00)
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_23_mask                     (0x000000FF)
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_20(data)                    (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_21(data)                    (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_22(data)                    (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_1st_gain_5_lc_gain_by_yin_23(data)                    (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_1st_gain_5_get_lc_gain_by_yin_20(data)                ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_1st_gain_5_get_lc_gain_by_yin_21(data)                ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_1st_gain_5_get_lc_gain_by_yin_22(data)                ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_1st_gain_5_get_lc_gain_by_yin_23(data)                (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_1st_gain_6                                            0x1802E158
#define  LC_LC_Local_Shpnr_1st_gain_6_reg_addr                                   "0xB802E158"
#define  LC_LC_Local_Shpnr_1st_gain_6_reg                                        0xB802E158
#define  LC_LC_Local_Shpnr_1st_gain_6_inst_addr                                  "0x0054"
#define  set_LC_LC_Local_Shpnr_1st_gain_6_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_6_reg)=data)
#define  get_LC_LC_Local_Shpnr_1st_gain_6_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_6_reg))
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_24_shift                    (24)
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_25_shift                    (16)
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_26_shift                    (8)
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_27_shift                    (0)
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_24_mask                     (0xFF000000)
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_25_mask                     (0x00FF0000)
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_26_mask                     (0x0000FF00)
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_27_mask                     (0x000000FF)
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_24(data)                    (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_25(data)                    (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_26(data)                    (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_1st_gain_6_lc_gain_by_yin_27(data)                    (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_1st_gain_6_get_lc_gain_by_yin_24(data)                ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_1st_gain_6_get_lc_gain_by_yin_25(data)                ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_1st_gain_6_get_lc_gain_by_yin_26(data)                ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_1st_gain_6_get_lc_gain_by_yin_27(data)                (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_1st_gain_7                                            0x1802E15C
#define  LC_LC_Local_Shpnr_1st_gain_7_reg_addr                                   "0xB802E15C"
#define  LC_LC_Local_Shpnr_1st_gain_7_reg                                        0xB802E15C
#define  LC_LC_Local_Shpnr_1st_gain_7_inst_addr                                  "0x0055"
#define  set_LC_LC_Local_Shpnr_1st_gain_7_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_7_reg)=data)
#define  get_LC_LC_Local_Shpnr_1st_gain_7_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_7_reg))
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_28_shift                    (24)
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_29_shift                    (16)
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_30_shift                    (8)
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_31_shift                    (0)
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_28_mask                     (0xFF000000)
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_29_mask                     (0x00FF0000)
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_30_mask                     (0x0000FF00)
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_31_mask                     (0x000000FF)
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_28(data)                    (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_29(data)                    (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_30(data)                    (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_1st_gain_7_lc_gain_by_yin_31(data)                    (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_1st_gain_7_get_lc_gain_by_yin_28(data)                ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_1st_gain_7_get_lc_gain_by_yin_29(data)                ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_1st_gain_7_get_lc_gain_by_yin_30(data)                ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_1st_gain_7_get_lc_gain_by_yin_31(data)                (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_1st_gain_8                                            0x1802E160
#define  LC_LC_Local_Shpnr_1st_gain_8_reg_addr                                   "0xB802E160"
#define  LC_LC_Local_Shpnr_1st_gain_8_reg                                        0xB802E160
#define  LC_LC_Local_Shpnr_1st_gain_8_inst_addr                                  "0x0056"
#define  set_LC_LC_Local_Shpnr_1st_gain_8_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_8_reg)=data)
#define  get_LC_LC_Local_Shpnr_1st_gain_8_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_1st_gain_8_reg))
#define  LC_LC_Local_Shpnr_1st_gain_8_lc_gain_by_yin_32_shift                    (24)
#define  LC_LC_Local_Shpnr_1st_gain_8_lc_gain_by_yin_divisor_shift               (0)
#define  LC_LC_Local_Shpnr_1st_gain_8_lc_gain_by_yin_32_mask                     (0xFF000000)
#define  LC_LC_Local_Shpnr_1st_gain_8_lc_gain_by_yin_divisor_mask                (0x00000007)
#define  LC_LC_Local_Shpnr_1st_gain_8_lc_gain_by_yin_32(data)                    (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_1st_gain_8_lc_gain_by_yin_divisor(data)               (0x00000007&(data))
#define  LC_LC_Local_Shpnr_1st_gain_8_get_lc_gain_by_yin_32(data)                ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_1st_gain_8_get_lc_gain_by_yin_divisor(data)           (0x00000007&(data))

#define  LC_LC_Local_Shpnr_2nd_gain_0                                            0x1802E170
#define  LC_LC_Local_Shpnr_2nd_gain_0_reg_addr                                   "0xB802E170"
#define  LC_LC_Local_Shpnr_2nd_gain_0_reg                                        0xB802E170
#define  LC_LC_Local_Shpnr_2nd_gain_0_inst_addr                                  "0x0057"
#define  set_LC_LC_Local_Shpnr_2nd_gain_0_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_0_reg)=data)
#define  get_LC_LC_Local_Shpnr_2nd_gain_0_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_0_reg))
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_0_shift                   (24)
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_1_shift                   (16)
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_2_shift                   (8)
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_3_shift                   (0)
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_0_mask                    (0xFF000000)
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_1_mask                    (0x00FF0000)
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_2_mask                    (0x0000FF00)
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_3_mask                    (0x000000FF)
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_0(data)                   (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_1(data)                   (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_2(data)                   (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_2nd_gain_0_lc_gain_by_ydiff_3(data)                   (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_2nd_gain_0_get_lc_gain_by_ydiff_0(data)               ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_2nd_gain_0_get_lc_gain_by_ydiff_1(data)               ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_2nd_gain_0_get_lc_gain_by_ydiff_2(data)               ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_2nd_gain_0_get_lc_gain_by_ydiff_3(data)               (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_2nd_gain_1                                            0x1802E174
#define  LC_LC_Local_Shpnr_2nd_gain_1_reg_addr                                   "0xB802E174"
#define  LC_LC_Local_Shpnr_2nd_gain_1_reg                                        0xB802E174
#define  LC_LC_Local_Shpnr_2nd_gain_1_inst_addr                                  "0x0058"
#define  set_LC_LC_Local_Shpnr_2nd_gain_1_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_1_reg)=data)
#define  get_LC_LC_Local_Shpnr_2nd_gain_1_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_1_reg))
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_4_shift                   (24)
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_5_shift                   (16)
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_6_shift                   (8)
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_7_shift                   (0)
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_4_mask                    (0xFF000000)
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_5_mask                    (0x00FF0000)
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_6_mask                    (0x0000FF00)
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_7_mask                    (0x000000FF)
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_4(data)                   (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_5(data)                   (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_6(data)                   (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_2nd_gain_1_lc_gain_by_ydiff_7(data)                   (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_2nd_gain_1_get_lc_gain_by_ydiff_4(data)               ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_2nd_gain_1_get_lc_gain_by_ydiff_5(data)               ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_2nd_gain_1_get_lc_gain_by_ydiff_6(data)               ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_2nd_gain_1_get_lc_gain_by_ydiff_7(data)               (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_2nd_gain_2                                            0x1802E178
#define  LC_LC_Local_Shpnr_2nd_gain_2_reg_addr                                   "0xB802E178"
#define  LC_LC_Local_Shpnr_2nd_gain_2_reg                                        0xB802E178
#define  LC_LC_Local_Shpnr_2nd_gain_2_inst_addr                                  "0x0059"
#define  set_LC_LC_Local_Shpnr_2nd_gain_2_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_2_reg)=data)
#define  get_LC_LC_Local_Shpnr_2nd_gain_2_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_2_reg))
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_8_shift                   (24)
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_9_shift                   (16)
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_10_shift                  (8)
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_11_shift                  (0)
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_8_mask                    (0xFF000000)
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_9_mask                    (0x00FF0000)
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_10_mask                   (0x0000FF00)
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_11_mask                   (0x000000FF)
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_8(data)                   (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_9(data)                   (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_10(data)                  (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_2nd_gain_2_lc_gain_by_ydiff_11(data)                  (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_2nd_gain_2_get_lc_gain_by_ydiff_8(data)               ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_2nd_gain_2_get_lc_gain_by_ydiff_9(data)               ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_2nd_gain_2_get_lc_gain_by_ydiff_10(data)              ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_2nd_gain_2_get_lc_gain_by_ydiff_11(data)              (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_2nd_gain_3                                            0x1802E17C
#define  LC_LC_Local_Shpnr_2nd_gain_3_reg_addr                                   "0xB802E17C"
#define  LC_LC_Local_Shpnr_2nd_gain_3_reg                                        0xB802E17C
#define  LC_LC_Local_Shpnr_2nd_gain_3_inst_addr                                  "0x005A"
#define  set_LC_LC_Local_Shpnr_2nd_gain_3_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_3_reg)=data)
#define  get_LC_LC_Local_Shpnr_2nd_gain_3_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_3_reg))
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_12_shift                  (24)
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_13_shift                  (16)
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_14_shift                  (8)
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_15_shift                  (0)
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_12_mask                   (0xFF000000)
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_13_mask                   (0x00FF0000)
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_14_mask                   (0x0000FF00)
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_15_mask                   (0x000000FF)
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_12(data)                  (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_13(data)                  (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_14(data)                  (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_2nd_gain_3_lc_gain_by_ydiff_15(data)                  (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_2nd_gain_3_get_lc_gain_by_ydiff_12(data)              ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_2nd_gain_3_get_lc_gain_by_ydiff_13(data)              ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_2nd_gain_3_get_lc_gain_by_ydiff_14(data)              ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_2nd_gain_3_get_lc_gain_by_ydiff_15(data)              (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_2nd_gain_4                                            0x1802E180
#define  LC_LC_Local_Shpnr_2nd_gain_4_reg_addr                                   "0xB802E180"
#define  LC_LC_Local_Shpnr_2nd_gain_4_reg                                        0xB802E180
#define  LC_LC_Local_Shpnr_2nd_gain_4_inst_addr                                  "0x005B"
#define  set_LC_LC_Local_Shpnr_2nd_gain_4_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_4_reg)=data)
#define  get_LC_LC_Local_Shpnr_2nd_gain_4_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_4_reg))
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_16_shift                  (24)
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_17_shift                  (16)
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_18_shift                  (8)
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_19_shift                  (0)
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_16_mask                   (0xFF000000)
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_17_mask                   (0x00FF0000)
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_18_mask                   (0x0000FF00)
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_19_mask                   (0x000000FF)
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_16(data)                  (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_17(data)                  (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_18(data)                  (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_2nd_gain_4_lc_gain_by_ydiff_19(data)                  (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_2nd_gain_4_get_lc_gain_by_ydiff_16(data)              ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_2nd_gain_4_get_lc_gain_by_ydiff_17(data)              ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_2nd_gain_4_get_lc_gain_by_ydiff_18(data)              ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_2nd_gain_4_get_lc_gain_by_ydiff_19(data)              (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_2nd_gain_5                                            0x1802E184
#define  LC_LC_Local_Shpnr_2nd_gain_5_reg_addr                                   "0xB802E184"
#define  LC_LC_Local_Shpnr_2nd_gain_5_reg                                        0xB802E184
#define  LC_LC_Local_Shpnr_2nd_gain_5_inst_addr                                  "0x005C"
#define  set_LC_LC_Local_Shpnr_2nd_gain_5_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_5_reg)=data)
#define  get_LC_LC_Local_Shpnr_2nd_gain_5_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_5_reg))
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_20_shift                  (24)
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_21_shift                  (16)
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_22_shift                  (8)
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_23_shift                  (0)
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_20_mask                   (0xFF000000)
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_21_mask                   (0x00FF0000)
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_22_mask                   (0x0000FF00)
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_23_mask                   (0x000000FF)
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_20(data)                  (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_21(data)                  (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_22(data)                  (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_2nd_gain_5_lc_gain_by_ydiff_23(data)                  (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_2nd_gain_5_get_lc_gain_by_ydiff_20(data)              ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_2nd_gain_5_get_lc_gain_by_ydiff_21(data)              ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_2nd_gain_5_get_lc_gain_by_ydiff_22(data)              ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_2nd_gain_5_get_lc_gain_by_ydiff_23(data)              (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_2nd_gain_6                                            0x1802E188
#define  LC_LC_Local_Shpnr_2nd_gain_6_reg_addr                                   "0xB802E188"
#define  LC_LC_Local_Shpnr_2nd_gain_6_reg                                        0xB802E188
#define  LC_LC_Local_Shpnr_2nd_gain_6_inst_addr                                  "0x005D"
#define  set_LC_LC_Local_Shpnr_2nd_gain_6_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_6_reg)=data)
#define  get_LC_LC_Local_Shpnr_2nd_gain_6_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_6_reg))
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_24_shift                  (24)
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_25_shift                  (16)
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_26_shift                  (8)
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_27_shift                  (0)
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_24_mask                   (0xFF000000)
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_25_mask                   (0x00FF0000)
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_26_mask                   (0x0000FF00)
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_27_mask                   (0x000000FF)
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_24(data)                  (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_25(data)                  (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_26(data)                  (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_2nd_gain_6_lc_gain_by_ydiff_27(data)                  (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_2nd_gain_6_get_lc_gain_by_ydiff_24(data)              ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_2nd_gain_6_get_lc_gain_by_ydiff_25(data)              ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_2nd_gain_6_get_lc_gain_by_ydiff_26(data)              ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_2nd_gain_6_get_lc_gain_by_ydiff_27(data)              (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_2nd_gain_7                                            0x1802E18C
#define  LC_LC_Local_Shpnr_2nd_gain_7_reg_addr                                   "0xB802E18C"
#define  LC_LC_Local_Shpnr_2nd_gain_7_reg                                        0xB802E18C
#define  LC_LC_Local_Shpnr_2nd_gain_7_inst_addr                                  "0x005E"
#define  set_LC_LC_Local_Shpnr_2nd_gain_7_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_7_reg)=data)
#define  get_LC_LC_Local_Shpnr_2nd_gain_7_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_7_reg))
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_28_shift                  (24)
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_29_shift                  (16)
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_30_shift                  (8)
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_31_shift                  (0)
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_28_mask                   (0xFF000000)
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_29_mask                   (0x00FF0000)
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_30_mask                   (0x0000FF00)
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_31_mask                   (0x000000FF)
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_28(data)                  (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_29(data)                  (0x00FF0000&((data)<<16))
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_30(data)                  (0x0000FF00&((data)<<8))
#define  LC_LC_Local_Shpnr_2nd_gain_7_lc_gain_by_ydiff_31(data)                  (0x000000FF&(data))
#define  LC_LC_Local_Shpnr_2nd_gain_7_get_lc_gain_by_ydiff_28(data)              ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_2nd_gain_7_get_lc_gain_by_ydiff_29(data)              ((0x00FF0000&(data))>>16)
#define  LC_LC_Local_Shpnr_2nd_gain_7_get_lc_gain_by_ydiff_30(data)              ((0x0000FF00&(data))>>8)
#define  LC_LC_Local_Shpnr_2nd_gain_7_get_lc_gain_by_ydiff_31(data)              (0x000000FF&(data))

#define  LC_LC_Local_Shpnr_2nd_gain_8                                            0x1802E190
#define  LC_LC_Local_Shpnr_2nd_gain_8_reg_addr                                   "0xB802E190"
#define  LC_LC_Local_Shpnr_2nd_gain_8_reg                                        0xB802E190
#define  LC_LC_Local_Shpnr_2nd_gain_8_inst_addr                                  "0x005F"
#define  set_LC_LC_Local_Shpnr_2nd_gain_8_reg(data)                              (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_8_reg)=data)
#define  get_LC_LC_Local_Shpnr_2nd_gain_8_reg                                    (*((volatile unsigned int*)LC_LC_Local_Shpnr_2nd_gain_8_reg))
#define  LC_LC_Local_Shpnr_2nd_gain_8_lc_gain_by_ydiff_32_shift                  (24)
#define  LC_LC_Local_Shpnr_2nd_gain_8_lc_gain_by_ydiff_divisor_shift             (0)
#define  LC_LC_Local_Shpnr_2nd_gain_8_lc_gain_by_ydiff_32_mask                   (0xFF000000)
#define  LC_LC_Local_Shpnr_2nd_gain_8_lc_gain_by_ydiff_divisor_mask              (0x00000007)
#define  LC_LC_Local_Shpnr_2nd_gain_8_lc_gain_by_ydiff_32(data)                  (0xFF000000&((data)<<24))
#define  LC_LC_Local_Shpnr_2nd_gain_8_lc_gain_by_ydiff_divisor(data)             (0x00000007&(data))
#define  LC_LC_Local_Shpnr_2nd_gain_8_get_lc_gain_by_ydiff_32(data)              ((0xFF000000&(data))>>24)
#define  LC_LC_Local_Shpnr_2nd_gain_8_get_lc_gain_by_ydiff_divisor(data)         (0x00000007&(data))

#define  LC_LC_diff_ctrl0                                                        0x1802E1A0
#define  LC_LC_diff_ctrl0_reg_addr                                               "0xB802E1A0"
#define  LC_LC_diff_ctrl0_reg                                                    0xB802E1A0
#define  LC_LC_diff_ctrl0_inst_addr                                              "0x0060"
#define  set_LC_LC_diff_ctrl0_reg(data)                                          (*((volatile unsigned int*)LC_LC_diff_ctrl0_reg)=data)
#define  get_LC_LC_diff_ctrl0_reg                                                (*((volatile unsigned int*)LC_LC_diff_ctrl0_reg))
#define  LC_LC_diff_ctrl0_lc_ydiff_measure_en_shift                              (31)
#define  LC_LC_diff_ctrl0_lc_ydiff_abs_th_shift                                  (0)
#define  LC_LC_diff_ctrl0_lc_ydiff_measure_en_mask                               (0x80000000)
#define  LC_LC_diff_ctrl0_lc_ydiff_abs_th_mask                                   (0x00000FFF)
#define  LC_LC_diff_ctrl0_lc_ydiff_measure_en(data)                              (0x80000000&((data)<<31))
#define  LC_LC_diff_ctrl0_lc_ydiff_abs_th(data)                                  (0x00000FFF&(data))
#define  LC_LC_diff_ctrl0_get_lc_ydiff_measure_en(data)                          ((0x80000000&(data))>>31)
#define  LC_LC_diff_ctrl0_get_lc_ydiff_abs_th(data)                              (0x00000FFF&(data))

#define  LC_LC_diff_status                                                       0x1802E1A4
#define  LC_LC_diff_status_reg_addr                                              "0xB802E1A4"
#define  LC_LC_diff_status_reg                                                   0xB802E1A4
#define  LC_LC_diff_status_inst_addr                                             "0x0061"
#define  set_LC_LC_diff_status_reg(data)                                         (*((volatile unsigned int*)LC_LC_diff_status_reg)=data)
#define  get_LC_LC_diff_status_reg                                               (*((volatile unsigned int*)LC_LC_diff_status_reg))
#define  LC_LC_diff_status_lc_ydiff_over_abs_th_shift                            (0)
#define  LC_LC_diff_status_lc_ydiff_over_abs_th_mask                             (0x01FFFFFF)
#define  LC_LC_diff_status_lc_ydiff_over_abs_th(data)                            (0x01FFFFFF&(data))
#define  LC_LC_diff_status_get_lc_ydiff_over_abs_th(data)                        (0x01FFFFFF&(data))

#define  LC_LC_Demo_window_ctrl0                                                 0x1802E1B0
#define  LC_LC_Demo_window_ctrl0_reg_addr                                        "0xB802E1B0"
#define  LC_LC_Demo_window_ctrl0_reg                                             0xB802E1B0
#define  LC_LC_Demo_window_ctrl0_inst_addr                                       "0x0062"
#define  set_LC_LC_Demo_window_ctrl0_reg(data)                                   (*((volatile unsigned int*)LC_LC_Demo_window_ctrl0_reg)=data)
#define  get_LC_LC_Demo_window_ctrl0_reg                                         (*((volatile unsigned int*)LC_LC_Demo_window_ctrl0_reg))
#define  LC_LC_Demo_window_ctrl0_lc_demo_en_shift                                (31)
#define  LC_LC_Demo_window_ctrl0_lc_demo_mode_shift                              (30)
#define  LC_LC_Demo_window_ctrl0_lc_demo_top_shift                               (16)
#define  LC_LC_Demo_window_ctrl0_lc_demo_bottom_shift                            (0)
#define  LC_LC_Demo_window_ctrl0_lc_demo_en_mask                                 (0x80000000)
#define  LC_LC_Demo_window_ctrl0_lc_demo_mode_mask                               (0x40000000)
#define  LC_LC_Demo_window_ctrl0_lc_demo_top_mask                                (0x0FFF0000)
#define  LC_LC_Demo_window_ctrl0_lc_demo_bottom_mask                             (0x00000FFF)
#define  LC_LC_Demo_window_ctrl0_lc_demo_en(data)                                (0x80000000&((data)<<31))
#define  LC_LC_Demo_window_ctrl0_lc_demo_mode(data)                              (0x40000000&((data)<<30))
#define  LC_LC_Demo_window_ctrl0_lc_demo_top(data)                               (0x0FFF0000&((data)<<16))
#define  LC_LC_Demo_window_ctrl0_lc_demo_bottom(data)                            (0x00000FFF&(data))
#define  LC_LC_Demo_window_ctrl0_get_lc_demo_en(data)                            ((0x80000000&(data))>>31)
#define  LC_LC_Demo_window_ctrl0_get_lc_demo_mode(data)                          ((0x40000000&(data))>>30)
#define  LC_LC_Demo_window_ctrl0_get_lc_demo_top(data)                           ((0x0FFF0000&(data))>>16)
#define  LC_LC_Demo_window_ctrl0_get_lc_demo_bottom(data)                        (0x00000FFF&(data))

#define  LC_LC_Demo_window_ctrl1                                                 0x1802E1B4
#define  LC_LC_Demo_window_ctrl1_reg_addr                                        "0xB802E1B4"
#define  LC_LC_Demo_window_ctrl1_reg                                             0xB802E1B4
#define  LC_LC_Demo_window_ctrl1_inst_addr                                       "0x0063"
#define  set_LC_LC_Demo_window_ctrl1_reg(data)                                   (*((volatile unsigned int*)LC_LC_Demo_window_ctrl1_reg)=data)
#define  get_LC_LC_Demo_window_ctrl1_reg                                         (*((volatile unsigned int*)LC_LC_Demo_window_ctrl1_reg))
#define  LC_LC_Demo_window_ctrl1_lc_demo_left_shift                              (16)
#define  LC_LC_Demo_window_ctrl1_lc_demo_right_shift                             (0)
#define  LC_LC_Demo_window_ctrl1_lc_demo_left_mask                               (0x1FFF0000)
#define  LC_LC_Demo_window_ctrl1_lc_demo_right_mask                              (0x00001FFF)
#define  LC_LC_Demo_window_ctrl1_lc_demo_left(data)                              (0x1FFF0000&((data)<<16))
#define  LC_LC_Demo_window_ctrl1_lc_demo_right(data)                             (0x00001FFF&(data))
#define  LC_LC_Demo_window_ctrl1_get_lc_demo_left(data)                          ((0x1FFF0000&(data))>>16)
#define  LC_LC_Demo_window_ctrl1_get_lc_demo_right(data)                         (0x00001FFF&(data))

#define  LC_LC_APL_READ_ADDR                                                     0x1802E1C0
#define  LC_LC_APL_READ_ADDR_reg_addr                                            "0xB802E1C0"
#define  LC_LC_APL_READ_ADDR_reg                                                 0xB802E1C0
#define  LC_LC_APL_READ_ADDR_inst_addr                                           "0x0064"
#define  set_LC_LC_APL_READ_ADDR_reg(data)                                       (*((volatile unsigned int*)LC_LC_APL_READ_ADDR_reg)=data)
#define  get_LC_LC_APL_READ_ADDR_reg                                             (*((volatile unsigned int*)LC_LC_APL_READ_ADDR_reg))
#define  LC_LC_APL_READ_ADDR_lc_apl_mod_shift                                    (31)
#define  LC_LC_APL_READ_ADDR_lc_apl_idx_shift                                    (8)
#define  LC_LC_APL_READ_ADDR_lc_apl_addr_shift                                   (0)
#define  LC_LC_APL_READ_ADDR_lc_apl_mod_mask                                     (0x80000000)
#define  LC_LC_APL_READ_ADDR_lc_apl_idx_mask                                     (0x00000100)
#define  LC_LC_APL_READ_ADDR_lc_apl_addr_mask                                    (0x000000FF)
#define  LC_LC_APL_READ_ADDR_lc_apl_mod(data)                                    (0x80000000&((data)<<31))
#define  LC_LC_APL_READ_ADDR_lc_apl_idx(data)                                    (0x00000100&((data)<<8))
#define  LC_LC_APL_READ_ADDR_lc_apl_addr(data)                                   (0x000000FF&(data))
#define  LC_LC_APL_READ_ADDR_get_lc_apl_mod(data)                                ((0x80000000&(data))>>31)
#define  LC_LC_APL_READ_ADDR_get_lc_apl_idx(data)                                ((0x00000100&(data))>>8)
#define  LC_LC_APL_READ_ADDR_get_lc_apl_addr(data)                               (0x000000FF&(data))

#define  LC_LC_APL_READ_DATA                                                     0x1802E1C4
#define  LC_LC_APL_READ_DATA_reg_addr                                            "0xB802E1C4"
#define  LC_LC_APL_READ_DATA_reg                                                 0xB802E1C4
#define  LC_LC_APL_READ_DATA_inst_addr                                           "0x0065"
#define  set_LC_LC_APL_READ_DATA_reg(data)                                       (*((volatile unsigned int*)LC_LC_APL_READ_DATA_reg)=data)
#define  get_LC_LC_APL_READ_DATA_reg                                             (*((volatile unsigned int*)LC_LC_APL_READ_DATA_reg))
#define  LC_LC_APL_READ_DATA_lc_apl_sram_read_idx_shift                          (28)
#define  LC_LC_APL_READ_DATA_lc_apl_sram_read_addr_shift                         (20)
#define  LC_LC_APL_READ_DATA_lc_apl_dat_msb_shift                                (10)
#define  LC_LC_APL_READ_DATA_lc_apl_dat_lsb_shift                                (0)
#define  LC_LC_APL_READ_DATA_lc_apl_sram_read_idx_mask                           (0x10000000)
#define  LC_LC_APL_READ_DATA_lc_apl_sram_read_addr_mask                          (0x0FF00000)
#define  LC_LC_APL_READ_DATA_lc_apl_dat_msb_mask                                 (0x000FFC00)
#define  LC_LC_APL_READ_DATA_lc_apl_dat_lsb_mask                                 (0x000003FF)
#define  LC_LC_APL_READ_DATA_lc_apl_sram_read_idx(data)                          (0x10000000&((data)<<28))
#define  LC_LC_APL_READ_DATA_lc_apl_sram_read_addr(data)                         (0x0FF00000&((data)<<20))
#define  LC_LC_APL_READ_DATA_lc_apl_dat_msb(data)                                (0x000FFC00&((data)<<10))
#define  LC_LC_APL_READ_DATA_lc_apl_dat_lsb(data)                                (0x000003FF&(data))
#define  LC_LC_APL_READ_DATA_get_lc_apl_sram_read_idx(data)                      ((0x10000000&(data))>>28)
#define  LC_LC_APL_READ_DATA_get_lc_apl_sram_read_addr(data)                     ((0x0FF00000&(data))>>20)
#define  LC_LC_APL_READ_DATA_get_lc_apl_dat_msb(data)                            ((0x000FFC00&(data))>>10)
#define  LC_LC_APL_READ_DATA_get_lc_apl_dat_lsb(data)                            (0x000003FF&(data))

#define  LC_LC_APL_write_addr                                                    0x1802E1C8
#define  LC_LC_APL_write_addr_reg_addr                                           "0xB802E1C8"
#define  LC_LC_APL_write_addr_reg                                                0xB802E1C8
#define  LC_LC_APL_write_addr_inst_addr                                          "0x0066"
#define  set_LC_LC_APL_write_addr_reg(data)                                      (*((volatile unsigned int*)LC_LC_APL_write_addr_reg)=data)
#define  get_LC_LC_APL_write_addr_reg                                            (*((volatile unsigned int*)LC_LC_APL_write_addr_reg))
#define  LC_LC_APL_write_addr_lc_apl_sram_write_idx_shift                        (8)
#define  LC_LC_APL_write_addr_lc_apl_sram_write_addr_shift                       (0)
#define  LC_LC_APL_write_addr_lc_apl_sram_write_idx_mask                         (0x00000100)
#define  LC_LC_APL_write_addr_lc_apl_sram_write_addr_mask                        (0x000000FF)
#define  LC_LC_APL_write_addr_lc_apl_sram_write_idx(data)                        (0x00000100&((data)<<8))
#define  LC_LC_APL_write_addr_lc_apl_sram_write_addr(data)                       (0x000000FF&(data))
#define  LC_LC_APL_write_addr_get_lc_apl_sram_write_idx(data)                    ((0x00000100&(data))>>8)
#define  LC_LC_APL_write_addr_get_lc_apl_sram_write_addr(data)                   (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e000_31:1;
        RBus_UInt32  lc_apl_en:1;
        RBus_UInt32  lc_local_sharp_en:1;
        RBus_UInt32  lc_tone_mapping_en:1;
        RBus_UInt32  dummy1802e000_27_2:26;
        RBus_UInt32  lc_debugmode:2;
    };
}lc_lc_global_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_db_en:1;
        RBus_UInt32  dummy1802e004_30:1;
        RBus_UInt32  lc_db_apply:1;
        RBus_UInt32  dummy1802e004_28:1;
        RBus_UInt32  lc_db_read_level:1;
        RBus_UInt32  dummy1802e004_26_0:27;
    };
}lc_lc_global_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e008_31:1;
        RBus_UInt32  lc_3d_mode:2;
        RBus_UInt32  lc_blk_hnum:5;
        RBus_UInt32  dummy1802e008_23_21:3;
        RBus_UInt32  lc_blk_vnum:5;
        RBus_UInt32  dummy1802e008_15_8:8;
        RBus_UInt32  lc_subblk_mode:1;
        RBus_UInt32  lc_gcon_mode:1;
        RBus_UInt32  dummy1802e008_5_4:2;
        RBus_UInt32  lc_hist_mode:2;
        RBus_UInt32  lc_tenable:1;
        RBus_UInt32  lc_valid:1;
    };
}lc_lc_global_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e00c_31_29:3;
        RBus_UInt32  lc_blk_hsize:13;
        RBus_UInt32  dummy1802e00c_15_12:4;
        RBus_UInt32  lc_blk_vsize:12;
    };
}lc_lc_global_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_drf_rme_7:1;
        RBus_UInt32  lc_drf_rme_6:1;
        RBus_UInt32  lc_drf_rme_5:1;
        RBus_UInt32  lc_drf_rme_4:1;
        RBus_UInt32  lc_drf_rme_3:1;
        RBus_UInt32  lc_drf_rme_2:1;
        RBus_UInt32  lc_drf_rme_1:1;
        RBus_UInt32  lc_drf_rme_0:1;
        RBus_UInt32  lc_drf_ls_7:1;
        RBus_UInt32  lc_drf_ls_6:1;
        RBus_UInt32  lc_drf_ls_5:1;
        RBus_UInt32  lc_drf_ls_4:1;
        RBus_UInt32  lc_drf_ls_3:1;
        RBus_UInt32  lc_drf_ls_2:1;
        RBus_UInt32  lc_drf_ls_1:1;
        RBus_UInt32  lc_drf_ls_0:1;
        RBus_UInt32  lc_drf_bist_fail_7:1;
        RBus_UInt32  lc_drf_bist_fail_6:1;
        RBus_UInt32  lc_drf_bist_fail_5:1;
        RBus_UInt32  lc_drf_bist_fail_4:1;
        RBus_UInt32  lc_drf_bist_fail_3:1;
        RBus_UInt32  lc_drf_bist_fail_2:1;
        RBus_UInt32  lc_drf_bist_fail_1:1;
        RBus_UInt32  lc_drf_bist_fail_0:1;
        RBus_UInt32  lc_bist_fail_7:1;
        RBus_UInt32  lc_bist_fail_6:1;
        RBus_UInt32  lc_bist_fail_5:1;
        RBus_UInt32  lc_bist_fail_4:1;
        RBus_UInt32  lc_bist_fail_3:1;
        RBus_UInt32  lc_bist_fail_2:1;
        RBus_UInt32  lc_bist_fail_1:1;
        RBus_UInt32  lc_bist_fail_0:1;
    };
}lc_lc_global_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_drf_rm_7:4;
        RBus_UInt32  lc_drf_rm_6:4;
        RBus_UInt32  lc_drf_rm_5:4;
        RBus_UInt32  lc_drf_rm_4:4;
        RBus_UInt32  lc_drf_rm_3:4;
        RBus_UInt32  lc_drf_rm_2:4;
        RBus_UInt32  lc_drf_rm_1:4;
        RBus_UInt32  lc_drf_rm_0:4;
    };
}lc_lc_global_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  lc_global_max:12;
    };
}lc_lc_global_max_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist0:16;
        RBus_UInt32  lc_global_hist1:16;
    };
}lc_lc_global_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist2:16;
        RBus_UInt32  lc_global_hist3:16;
    };
}lc_lc_global_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist4:16;
        RBus_UInt32  lc_global_hist5:16;
    };
}lc_lc_global_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist6:16;
        RBus_UInt32  lc_global_hist7:16;
    };
}lc_lc_global_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist8:16;
        RBus_UInt32  lc_global_hist9:16;
    };
}lc_lc_global_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist10:16;
        RBus_UInt32  lc_global_hist11:16;
    };
}lc_lc_global_hist6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist12:16;
        RBus_UInt32  lc_global_hist13:16;
    };
}lc_lc_global_hist7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist14:16;
        RBus_UInt32  lc_global_hist15:16;
    };
}lc_lc_global_hist8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_maxgain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_avegain:6;
        RBus_UInt32  res3:12;
        RBus_UInt32  lc_histshiftbit:4;
    };
}lc_lc_decision_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_hist0gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_hist1gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_hist2gain:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  lc_hist3gain:6;
    };
}lc_lc_decision_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_hist4gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_hist5gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_hist6gain:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  lc_hist7gain:6;
    };
}lc_lc_decision_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  lc_decaccess_addr:9;
        RBus_UInt32  res2:15;
        RBus_UInt32  lc_decaccess_en:1;
    };
}lc_lc_decision_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_decaccess_data:30;
    };
}lc_lc_decision_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_spatialcoef0:4;
        RBus_UInt32  lc_spatialcoef1:4;
        RBus_UInt32  lc_spatialcoef2:4;
        RBus_UInt32  lc_spatialcoef3:4;
        RBus_UInt32  lc_spatialcoef4:4;
        RBus_UInt32  lc_spatialcoef5:4;
        RBus_UInt32  lc_spatialcoef6:4;
        RBus_UInt32  lc_spatialcoef7:4;
    };
}lc_lc_spatial_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_spatialcoef8:4;
        RBus_UInt32  lc_spatialcoef9:4;
        RBus_UInt32  lc_spatialcoef10:4;
        RBus_UInt32  dummy1802e054_19_2:18;
        RBus_UInt32  lc_spatialremapbusy:1;
        RBus_UInt32  lc_spatialremapen:1;
    };
}lc_lc_spatial_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_spatialremapadr:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_spatialremaptab1:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_spatialremaptab0:10;
    };
}lc_lc_spatial_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  lc_spatialremaptab_initial:10;
    };
}lc_lc_spatial_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmp_pos0thd:8;
        RBus_UInt32  lc_tmp_pos1thd:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_tmp_posmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_tmp_posmaxgain:5;
    };
}lc_lc_temporal_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmp_neg0thd:8;
        RBus_UInt32  lc_tmp_neg1thd:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_tmp_negmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_tmp_negmaxgain:5;
    };
}lc_lc_temporal_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lc_tmp_maxdiff:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_tmp_scenechangegain1:5;
        RBus_UInt32  res3:8;
    };
}lc_lc_temporal_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lc_drf_rm_8:4;
        RBus_UInt32  lc_drf_rme_8:1;
        RBus_UInt32  lc_drf_ls_8:1;
        RBus_UInt32  lc_drf_bist_fail_8:1;
        RBus_UInt32  lc_bist_fail_8:1;
    };
}lc_lc_inter_hctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tab_hsize:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_hfactor:20;
    };
}lc_lc_inter_hctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_hinitphase3_right:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_hboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_hinitphase1:1;
        RBus_UInt32  lc_hinitphase2:8;
        RBus_UInt32  lc_hinitphase3_left:8;
    };
}lc_lc_inter_hctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tab_vsize:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_vfactor:20;
    };
}lc_lc_inter_vctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_vinitphase3_right:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_vboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_vinitphase1:1;
        RBus_UInt32  lc_vinitphase2:8;
        RBus_UInt32  lc_vinitphase3_left:8;
    };
}lc_lc_inter_vctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e084_31_9:23;
        RBus_UInt32  lc_vtab_adr:9;
    };
}lc_lc_vtab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e088_31_26:6;
        RBus_UInt32  lc_vtab_dat_msb:10;
        RBus_UInt32  dummy1802e088_15_10:6;
        RBus_UInt32  lc_vtab_dat_lsb:10;
    };
}lc_lc_vtab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e08c_31_9:23;
        RBus_UInt32  lc_htab_adr:9;
    };
}lc_lc_htab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e090_31_26:6;
        RBus_UInt32  lc_htab_dat_msb:10;
        RBus_UInt32  dummy1802e090_15_10:6;
        RBus_UInt32  lc_htab_dat_lsb:10;
    };
}lc_lc_htab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e094_31_3:29;
        RBus_UInt32  lc_blight_update_en:1;
        RBus_UInt32  lc_blight_sw_mode:1;
        RBus_UInt32  lc_table_sw_mode:1;
    };
}lc_lc_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e098_31_8:24;
        RBus_UInt32  lc_blight_adr:8;
    };
}lc_lc_blight_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e09c_31_26:6;
        RBus_UInt32  lc_blight_dat_msb:10;
        RBus_UInt32  dummy1802e09c_15_10:6;
        RBus_UInt32  lc_blight_dat_lsb:10;
    };
}lc_lc_blight_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  res3:4;
        RBus_UInt32  lc_tmap_g0_th1:12;
    };
}lc_lc_tonemapping_grid0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th3:12;
    };
}lc_lc_tonemapping_grid0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th5:12;
    };
}lc_lc_tonemapping_grid0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th7:12;
    };
}lc_lc_tonemapping_grid0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th9:12;
    };
}lc_lc_tonemapping_grid0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th11:12;
    };
}lc_lc_tonemapping_grid0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th13:12;
    };
}lc_lc_tonemapping_grid0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th15:12;
    };
}lc_lc_tonemapping_grid0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th17:12;
    };
}lc_lc_tonemapping_grid0_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th19:12;
    };
}lc_lc_tonemapping_grid0_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th21:12;
    };
}lc_lc_tonemapping_grid0_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th23:12;
    };
}lc_lc_tonemapping_grid0_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th25:12;
    };
}lc_lc_tonemapping_grid0_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th27:12;
    };
}lc_lc_tonemapping_grid0_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th29:12;
    };
}lc_lc_tonemapping_grid0_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g0_th31:12;
    };
}lc_lc_tonemapping_grid0_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  res3:4;
        RBus_UInt32  lc_tmap_g2_th1:12;
    };
}lc_lc_tonemapping_grid2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th3:12;
    };
}lc_lc_tonemapping_grid2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th5:12;
    };
}lc_lc_tonemapping_grid2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th7:12;
    };
}lc_lc_tonemapping_grid2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th9:12;
    };
}lc_lc_tonemapping_grid2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th11:12;
    };
}lc_lc_tonemapping_grid2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th13:12;
    };
}lc_lc_tonemapping_grid2_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th15:12;
    };
}lc_lc_tonemapping_grid2_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th17:12;
    };
}lc_lc_tonemapping_grid2_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th19:12;
    };
}lc_lc_tonemapping_grid2_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th21:12;
    };
}lc_lc_tonemapping_grid2_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th23:12;
    };
}lc_lc_tonemapping_grid2_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th25:12;
    };
}lc_lc_tonemapping_grid2_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th27:12;
    };
}lc_lc_tonemapping_grid2_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th29:12;
    };
}lc_lc_tonemapping_grid2_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_g2_th31:12;
    };
}lc_lc_tonemapping_grid2_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_tmap_curve0_grid:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_tmap_curve0_tone:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_tmap_curve1_grid:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  lc_tmap_curve1_tone:10;
    };
}lc_lc_tonemapping_curve_sel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_tmap_curve2_grid:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_tmap_curve2_tone:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_tmap_curve3_grid:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  lc_tmap_curve3_tone:10;
    };
}lc_lc_tonemapping_curve_sel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_tmap_curve4_grid:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_tmap_curve4_tone:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_tmap_curve5_grid:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  lc_tmap_curve5_tone:10;
    };
}lc_lc_tonemapping_curve_sel_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_tmap_curve6_grid:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_tmap_curve6_tone:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_tmap_curve7_grid:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  lc_tmap_curve7_tone:10;
    };
}lc_lc_tonemapping_curve_sel_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  lc_tmap_sram_num:3;
        RBus_UInt32  res2:11;
        RBus_UInt32  lc_tmap_sram_addr:5;
    };
}lc_lc_tonemapping_sram_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lc_tmap_sram_ds:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_tmap_sram_dp:12;
    };
}lc_lc_tonemapping_sram_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  lc_tmap_slope_unit:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  lc_tmap_blend_factor:8;
    };
}lc_lc_tonemapping_blending_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_0:8;
        RBus_UInt32  lc_gain_by_yin_1:8;
        RBus_UInt32  lc_gain_by_yin_2:8;
        RBus_UInt32  lc_gain_by_yin_3:8;
    };
}lc_lc_local_shpnr_1st_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_4:8;
        RBus_UInt32  lc_gain_by_yin_5:8;
        RBus_UInt32  lc_gain_by_yin_6:8;
        RBus_UInt32  lc_gain_by_yin_7:8;
    };
}lc_lc_local_shpnr_1st_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_8:8;
        RBus_UInt32  lc_gain_by_yin_9:8;
        RBus_UInt32  lc_gain_by_yin_10:8;
        RBus_UInt32  lc_gain_by_yin_11:8;
    };
}lc_lc_local_shpnr_1st_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_12:8;
        RBus_UInt32  lc_gain_by_yin_13:8;
        RBus_UInt32  lc_gain_by_yin_14:8;
        RBus_UInt32  lc_gain_by_yin_15:8;
    };
}lc_lc_local_shpnr_1st_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_16:8;
        RBus_UInt32  lc_gain_by_yin_17:8;
        RBus_UInt32  lc_gain_by_yin_18:8;
        RBus_UInt32  lc_gain_by_yin_19:8;
    };
}lc_lc_local_shpnr_1st_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_20:8;
        RBus_UInt32  lc_gain_by_yin_21:8;
        RBus_UInt32  lc_gain_by_yin_22:8;
        RBus_UInt32  lc_gain_by_yin_23:8;
    };
}lc_lc_local_shpnr_1st_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_24:8;
        RBus_UInt32  lc_gain_by_yin_25:8;
        RBus_UInt32  lc_gain_by_yin_26:8;
        RBus_UInt32  lc_gain_by_yin_27:8;
    };
}lc_lc_local_shpnr_1st_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_28:8;
        RBus_UInt32  lc_gain_by_yin_29:8;
        RBus_UInt32  lc_gain_by_yin_30:8;
        RBus_UInt32  lc_gain_by_yin_31:8;
    };
}lc_lc_local_shpnr_1st_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_32:8;
        RBus_UInt32  res1:21;
        RBus_UInt32  lc_gain_by_yin_divisor:3;
    };
}lc_lc_local_shpnr_1st_gain_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_0:8;
        RBus_UInt32  lc_gain_by_ydiff_1:8;
        RBus_UInt32  lc_gain_by_ydiff_2:8;
        RBus_UInt32  lc_gain_by_ydiff_3:8;
    };
}lc_lc_local_shpnr_2nd_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_4:8;
        RBus_UInt32  lc_gain_by_ydiff_5:8;
        RBus_UInt32  lc_gain_by_ydiff_6:8;
        RBus_UInt32  lc_gain_by_ydiff_7:8;
    };
}lc_lc_local_shpnr_2nd_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_8:8;
        RBus_UInt32  lc_gain_by_ydiff_9:8;
        RBus_UInt32  lc_gain_by_ydiff_10:8;
        RBus_UInt32  lc_gain_by_ydiff_11:8;
    };
}lc_lc_local_shpnr_2nd_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_12:8;
        RBus_UInt32  lc_gain_by_ydiff_13:8;
        RBus_UInt32  lc_gain_by_ydiff_14:8;
        RBus_UInt32  lc_gain_by_ydiff_15:8;
    };
}lc_lc_local_shpnr_2nd_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_16:8;
        RBus_UInt32  lc_gain_by_ydiff_17:8;
        RBus_UInt32  lc_gain_by_ydiff_18:8;
        RBus_UInt32  lc_gain_by_ydiff_19:8;
    };
}lc_lc_local_shpnr_2nd_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_20:8;
        RBus_UInt32  lc_gain_by_ydiff_21:8;
        RBus_UInt32  lc_gain_by_ydiff_22:8;
        RBus_UInt32  lc_gain_by_ydiff_23:8;
    };
}lc_lc_local_shpnr_2nd_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_24:8;
        RBus_UInt32  lc_gain_by_ydiff_25:8;
        RBus_UInt32  lc_gain_by_ydiff_26:8;
        RBus_UInt32  lc_gain_by_ydiff_27:8;
    };
}lc_lc_local_shpnr_2nd_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_28:8;
        RBus_UInt32  lc_gain_by_ydiff_29:8;
        RBus_UInt32  lc_gain_by_ydiff_30:8;
        RBus_UInt32  lc_gain_by_ydiff_31:8;
    };
}lc_lc_local_shpnr_2nd_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_32:8;
        RBus_UInt32  res1:21;
        RBus_UInt32  lc_gain_by_ydiff_divisor:3;
    };
}lc_lc_local_shpnr_2nd_gain_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_ydiff_measure_en:1;
        RBus_UInt32  res1:19;
        RBus_UInt32  lc_ydiff_abs_th:12;
    };
}lc_lc_diff_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  lc_ydiff_over_abs_th:25;
    };
}lc_lc_diff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_demo_en:1;
        RBus_UInt32  lc_demo_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_demo_top:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  lc_demo_bottom:12;
    };
}lc_lc_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_demo_left:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_demo_right:13;
    };
}lc_lc_demo_window_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_apl_mod:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  lc_apl_idx:1;
        RBus_UInt32  lc_apl_addr:8;
    };
}lc_lc_apl_read_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_apl_sram_read_idx:1;
        RBus_UInt32  lc_apl_sram_read_addr:8;
        RBus_UInt32  lc_apl_dat_msb:10;
        RBus_UInt32  lc_apl_dat_lsb:10;
    };
}lc_lc_apl_read_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  lc_apl_sram_write_idx:1;
        RBus_UInt32  lc_apl_sram_write_addr:8;
    };
}lc_lc_apl_write_addr_RBUS;

#else //apply LITTLE_ENDIAN

//======LC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_debugmode:2;
        RBus_UInt32  dummy1802e000_27_2:26;
        RBus_UInt32  lc_tone_mapping_en:1;
        RBus_UInt32  lc_local_sharp_en:1;
        RBus_UInt32  lc_apl_en:1;
        RBus_UInt32  dummy1802e000_31:1;
    };
}lc_lc_global_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e004_26_0:27;
        RBus_UInt32  lc_db_read_level:1;
        RBus_UInt32  dummy1802e004_28:1;
        RBus_UInt32  lc_db_apply:1;
        RBus_UInt32  dummy1802e004_30:1;
        RBus_UInt32  lc_db_en:1;
    };
}lc_lc_global_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_valid:1;
        RBus_UInt32  lc_tenable:1;
        RBus_UInt32  lc_hist_mode:2;
        RBus_UInt32  dummy1802e008_5_4:2;
        RBus_UInt32  lc_gcon_mode:1;
        RBus_UInt32  lc_subblk_mode:1;
        RBus_UInt32  dummy1802e008_15_8:8;
        RBus_UInt32  lc_blk_vnum:5;
        RBus_UInt32  dummy1802e008_23_21:3;
        RBus_UInt32  lc_blk_hnum:5;
        RBus_UInt32  lc_3d_mode:2;
        RBus_UInt32  dummy1802e008_31:1;
    };
}lc_lc_global_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_blk_vsize:12;
        RBus_UInt32  dummy1802e00c_15_12:4;
        RBus_UInt32  lc_blk_hsize:13;
        RBus_UInt32  dummy1802e00c_31_29:3;
    };
}lc_lc_global_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_bist_fail_0:1;
        RBus_UInt32  lc_bist_fail_1:1;
        RBus_UInt32  lc_bist_fail_2:1;
        RBus_UInt32  lc_bist_fail_3:1;
        RBus_UInt32  lc_bist_fail_4:1;
        RBus_UInt32  lc_bist_fail_5:1;
        RBus_UInt32  lc_bist_fail_6:1;
        RBus_UInt32  lc_bist_fail_7:1;
        RBus_UInt32  lc_drf_bist_fail_0:1;
        RBus_UInt32  lc_drf_bist_fail_1:1;
        RBus_UInt32  lc_drf_bist_fail_2:1;
        RBus_UInt32  lc_drf_bist_fail_3:1;
        RBus_UInt32  lc_drf_bist_fail_4:1;
        RBus_UInt32  lc_drf_bist_fail_5:1;
        RBus_UInt32  lc_drf_bist_fail_6:1;
        RBus_UInt32  lc_drf_bist_fail_7:1;
        RBus_UInt32  lc_drf_ls_0:1;
        RBus_UInt32  lc_drf_ls_1:1;
        RBus_UInt32  lc_drf_ls_2:1;
        RBus_UInt32  lc_drf_ls_3:1;
        RBus_UInt32  lc_drf_ls_4:1;
        RBus_UInt32  lc_drf_ls_5:1;
        RBus_UInt32  lc_drf_ls_6:1;
        RBus_UInt32  lc_drf_ls_7:1;
        RBus_UInt32  lc_drf_rme_0:1;
        RBus_UInt32  lc_drf_rme_1:1;
        RBus_UInt32  lc_drf_rme_2:1;
        RBus_UInt32  lc_drf_rme_3:1;
        RBus_UInt32  lc_drf_rme_4:1;
        RBus_UInt32  lc_drf_rme_5:1;
        RBus_UInt32  lc_drf_rme_6:1;
        RBus_UInt32  lc_drf_rme_7:1;
    };
}lc_lc_global_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_drf_rm_0:4;
        RBus_UInt32  lc_drf_rm_1:4;
        RBus_UInt32  lc_drf_rm_2:4;
        RBus_UInt32  lc_drf_rm_3:4;
        RBus_UInt32  lc_drf_rm_4:4;
        RBus_UInt32  lc_drf_rm_5:4;
        RBus_UInt32  lc_drf_rm_6:4;
        RBus_UInt32  lc_drf_rm_7:4;
    };
}lc_lc_global_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_max:12;
        RBus_UInt32  res1:20;
    };
}lc_lc_global_max_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist1:16;
        RBus_UInt32  lc_global_hist0:16;
    };
}lc_lc_global_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist3:16;
        RBus_UInt32  lc_global_hist2:16;
    };
}lc_lc_global_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist5:16;
        RBus_UInt32  lc_global_hist4:16;
    };
}lc_lc_global_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist7:16;
        RBus_UInt32  lc_global_hist6:16;
    };
}lc_lc_global_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist9:16;
        RBus_UInt32  lc_global_hist8:16;
    };
}lc_lc_global_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist11:16;
        RBus_UInt32  lc_global_hist10:16;
    };
}lc_lc_global_hist6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist13:16;
        RBus_UInt32  lc_global_hist12:16;
    };
}lc_lc_global_hist7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_global_hist15:16;
        RBus_UInt32  lc_global_hist14:16;
    };
}lc_lc_global_hist8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_histshiftbit:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  lc_avegain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_maxgain:6;
        RBus_UInt32  res3:2;
    };
}lc_lc_decision_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_hist3gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_hist2gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_hist1gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_hist0gain:6;
        RBus_UInt32  res4:2;
    };
}lc_lc_decision_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_hist7gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_hist6gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_hist5gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_hist4gain:6;
        RBus_UInt32  res4:2;
    };
}lc_lc_decision_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_decaccess_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  lc_decaccess_addr:9;
        RBus_UInt32  res2:7;
    };
}lc_lc_decision_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_decaccess_data:30;
        RBus_UInt32  res1:2;
    };
}lc_lc_decision_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_spatialcoef7:4;
        RBus_UInt32  lc_spatialcoef6:4;
        RBus_UInt32  lc_spatialcoef5:4;
        RBus_UInt32  lc_spatialcoef4:4;
        RBus_UInt32  lc_spatialcoef3:4;
        RBus_UInt32  lc_spatialcoef2:4;
        RBus_UInt32  lc_spatialcoef1:4;
        RBus_UInt32  lc_spatialcoef0:4;
    };
}lc_lc_spatial_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_spatialremapen:1;
        RBus_UInt32  lc_spatialremapbusy:1;
        RBus_UInt32  dummy1802e054_19_2:18;
        RBus_UInt32  lc_spatialcoef10:4;
        RBus_UInt32  lc_spatialcoef9:4;
        RBus_UInt32  lc_spatialcoef8:4;
    };
}lc_lc_spatial_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_spatialremaptab0:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_spatialremaptab1:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_spatialremapadr:5;
        RBus_UInt32  res3:3;
    };
}lc_lc_spatial_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_spatialremaptab_initial:10;
        RBus_UInt32  res1:22;
    };
}lc_lc_spatial_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmp_posmaxgain:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_tmp_posmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_tmp_pos1thd:8;
        RBus_UInt32  lc_tmp_pos0thd:8;
    };
}lc_lc_temporal_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmp_negmaxgain:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_tmp_negmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_tmp_neg1thd:8;
        RBus_UInt32  lc_tmp_neg0thd:8;
    };
}lc_lc_temporal_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lc_tmp_scenechangegain1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_tmp_maxdiff:8;
        RBus_UInt32  res3:8;
    };
}lc_lc_temporal_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_bist_fail_8:1;
        RBus_UInt32  lc_drf_bist_fail_8:1;
        RBus_UInt32  lc_drf_ls_8:1;
        RBus_UInt32  lc_drf_rme_8:1;
        RBus_UInt32  lc_drf_rm_8:4;
        RBus_UInt32  res1:24;
    };
}lc_lc_inter_hctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_hfactor:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tab_hsize:8;
    };
}lc_lc_inter_hctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_hinitphase3_left:8;
        RBus_UInt32  lc_hinitphase2:8;
        RBus_UInt32  lc_hinitphase1:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_hboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_hinitphase3_right:8;
    };
}lc_lc_inter_hctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_vfactor:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tab_vsize:8;
    };
}lc_lc_inter_vctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_vinitphase3_left:8;
        RBus_UInt32  lc_vinitphase2:8;
        RBus_UInt32  lc_vinitphase1:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_vboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  lc_vinitphase3_right:8;
    };
}lc_lc_inter_vctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_vtab_adr:9;
        RBus_UInt32  dummy1802e084_31_9:23;
    };
}lc_lc_vtab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_vtab_dat_lsb:10;
        RBus_UInt32  dummy1802e088_15_10:6;
        RBus_UInt32  lc_vtab_dat_msb:10;
        RBus_UInt32  dummy1802e088_31_26:6;
    };
}lc_lc_vtab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_htab_adr:9;
        RBus_UInt32  dummy1802e08c_31_9:23;
    };
}lc_lc_htab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_htab_dat_lsb:10;
        RBus_UInt32  dummy1802e090_15_10:6;
        RBus_UInt32  lc_htab_dat_msb:10;
        RBus_UInt32  dummy1802e090_31_26:6;
    };
}lc_lc_htab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_table_sw_mode:1;
        RBus_UInt32  lc_blight_sw_mode:1;
        RBus_UInt32  lc_blight_update_en:1;
        RBus_UInt32  dummy1802e094_31_3:29;
    };
}lc_lc_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_blight_adr:8;
        RBus_UInt32  dummy1802e098_31_8:24;
    };
}lc_lc_blight_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_blight_dat_lsb:10;
        RBus_UInt32  dummy1802e09c_15_10:6;
        RBus_UInt32  lc_blight_dat_msb:10;
        RBus_UInt32  dummy1802e09c_31_26:6;
    };
}lc_lc_blight_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  res3:4;
    };
}lc_lc_tonemapping_grid0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th2:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th4:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th6:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th8:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th10:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th12:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th14:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th16:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th18:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th20:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th22:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th24:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th26:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th28:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g0_th31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g0_th30:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid0_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  res3:4;
    };
}lc_lc_tonemapping_grid2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th2:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th4:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th6:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th8:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th10:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th12:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th14:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th16:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th18:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th20:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th22:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th24:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th26:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th28:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_g2_th31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_g2_th30:12;
        RBus_UInt32  res2:4;
    };
}lc_lc_tonemapping_grid2_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_curve1_tone:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_tmap_curve1_grid:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_tmap_curve0_tone:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_tmap_curve0_grid:2;
        RBus_UInt32  res4:2;
    };
}lc_lc_tonemapping_curve_sel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_curve3_tone:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_tmap_curve3_grid:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_tmap_curve2_tone:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_tmap_curve2_grid:2;
        RBus_UInt32  res4:2;
    };
}lc_lc_tonemapping_curve_sel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_curve5_tone:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_tmap_curve5_grid:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_tmap_curve4_tone:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_tmap_curve4_grid:2;
        RBus_UInt32  res4:2;
    };
}lc_lc_tonemapping_curve_sel_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_curve7_tone:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  lc_tmap_curve7_grid:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_tmap_curve6_tone:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  lc_tmap_curve6_grid:2;
        RBus_UInt32  res4:2;
    };
}lc_lc_tonemapping_curve_sel_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_sram_addr:5;
        RBus_UInt32  res1:11;
        RBus_UInt32  lc_tmap_sram_num:3;
        RBus_UInt32  res2:13;
    };
}lc_lc_tonemapping_sram_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_sram_dp:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_tmap_sram_ds:8;
        RBus_UInt32  res2:8;
    };
}lc_lc_tonemapping_sram_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_tmap_blend_factor:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  lc_tmap_slope_unit:1;
        RBus_UInt32  res2:15;
    };
}lc_lc_tonemapping_blending_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_3:8;
        RBus_UInt32  lc_gain_by_yin_2:8;
        RBus_UInt32  lc_gain_by_yin_1:8;
        RBus_UInt32  lc_gain_by_yin_0:8;
    };
}lc_lc_local_shpnr_1st_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_7:8;
        RBus_UInt32  lc_gain_by_yin_6:8;
        RBus_UInt32  lc_gain_by_yin_5:8;
        RBus_UInt32  lc_gain_by_yin_4:8;
    };
}lc_lc_local_shpnr_1st_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_11:8;
        RBus_UInt32  lc_gain_by_yin_10:8;
        RBus_UInt32  lc_gain_by_yin_9:8;
        RBus_UInt32  lc_gain_by_yin_8:8;
    };
}lc_lc_local_shpnr_1st_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_15:8;
        RBus_UInt32  lc_gain_by_yin_14:8;
        RBus_UInt32  lc_gain_by_yin_13:8;
        RBus_UInt32  lc_gain_by_yin_12:8;
    };
}lc_lc_local_shpnr_1st_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_19:8;
        RBus_UInt32  lc_gain_by_yin_18:8;
        RBus_UInt32  lc_gain_by_yin_17:8;
        RBus_UInt32  lc_gain_by_yin_16:8;
    };
}lc_lc_local_shpnr_1st_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_23:8;
        RBus_UInt32  lc_gain_by_yin_22:8;
        RBus_UInt32  lc_gain_by_yin_21:8;
        RBus_UInt32  lc_gain_by_yin_20:8;
    };
}lc_lc_local_shpnr_1st_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_27:8;
        RBus_UInt32  lc_gain_by_yin_26:8;
        RBus_UInt32  lc_gain_by_yin_25:8;
        RBus_UInt32  lc_gain_by_yin_24:8;
    };
}lc_lc_local_shpnr_1st_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_31:8;
        RBus_UInt32  lc_gain_by_yin_30:8;
        RBus_UInt32  lc_gain_by_yin_29:8;
        RBus_UInt32  lc_gain_by_yin_28:8;
    };
}lc_lc_local_shpnr_1st_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_yin_divisor:3;
        RBus_UInt32  res1:21;
        RBus_UInt32  lc_gain_by_yin_32:8;
    };
}lc_lc_local_shpnr_1st_gain_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_3:8;
        RBus_UInt32  lc_gain_by_ydiff_2:8;
        RBus_UInt32  lc_gain_by_ydiff_1:8;
        RBus_UInt32  lc_gain_by_ydiff_0:8;
    };
}lc_lc_local_shpnr_2nd_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_7:8;
        RBus_UInt32  lc_gain_by_ydiff_6:8;
        RBus_UInt32  lc_gain_by_ydiff_5:8;
        RBus_UInt32  lc_gain_by_ydiff_4:8;
    };
}lc_lc_local_shpnr_2nd_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_11:8;
        RBus_UInt32  lc_gain_by_ydiff_10:8;
        RBus_UInt32  lc_gain_by_ydiff_9:8;
        RBus_UInt32  lc_gain_by_ydiff_8:8;
    };
}lc_lc_local_shpnr_2nd_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_15:8;
        RBus_UInt32  lc_gain_by_ydiff_14:8;
        RBus_UInt32  lc_gain_by_ydiff_13:8;
        RBus_UInt32  lc_gain_by_ydiff_12:8;
    };
}lc_lc_local_shpnr_2nd_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_19:8;
        RBus_UInt32  lc_gain_by_ydiff_18:8;
        RBus_UInt32  lc_gain_by_ydiff_17:8;
        RBus_UInt32  lc_gain_by_ydiff_16:8;
    };
}lc_lc_local_shpnr_2nd_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_23:8;
        RBus_UInt32  lc_gain_by_ydiff_22:8;
        RBus_UInt32  lc_gain_by_ydiff_21:8;
        RBus_UInt32  lc_gain_by_ydiff_20:8;
    };
}lc_lc_local_shpnr_2nd_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_27:8;
        RBus_UInt32  lc_gain_by_ydiff_26:8;
        RBus_UInt32  lc_gain_by_ydiff_25:8;
        RBus_UInt32  lc_gain_by_ydiff_24:8;
    };
}lc_lc_local_shpnr_2nd_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_31:8;
        RBus_UInt32  lc_gain_by_ydiff_30:8;
        RBus_UInt32  lc_gain_by_ydiff_29:8;
        RBus_UInt32  lc_gain_by_ydiff_28:8;
    };
}lc_lc_local_shpnr_2nd_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_gain_by_ydiff_divisor:3;
        RBus_UInt32  res1:21;
        RBus_UInt32  lc_gain_by_ydiff_32:8;
    };
}lc_lc_local_shpnr_2nd_gain_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_ydiff_abs_th:12;
        RBus_UInt32  res1:19;
        RBus_UInt32  lc_ydiff_measure_en:1;
    };
}lc_lc_diff_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_ydiff_over_abs_th:25;
        RBus_UInt32  res1:7;
    };
}lc_lc_diff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_demo_bottom:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  lc_demo_top:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  lc_demo_mode:1;
        RBus_UInt32  lc_demo_en:1;
    };
}lc_lc_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_demo_right:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  lc_demo_left:13;
        RBus_UInt32  res2:3;
    };
}lc_lc_demo_window_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_apl_addr:8;
        RBus_UInt32  lc_apl_idx:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  lc_apl_mod:1;
    };
}lc_lc_apl_read_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_apl_dat_lsb:10;
        RBus_UInt32  lc_apl_dat_msb:10;
        RBus_UInt32  lc_apl_sram_read_addr:8;
        RBus_UInt32  lc_apl_sram_read_idx:1;
        RBus_UInt32  res1:3;
    };
}lc_lc_apl_read_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc_apl_sram_write_addr:8;
        RBus_UInt32  lc_apl_sram_write_idx:1;
        RBus_UInt32  res1:23;
    };
}lc_lc_apl_write_addr_RBUS;




#endif 


#endif 
