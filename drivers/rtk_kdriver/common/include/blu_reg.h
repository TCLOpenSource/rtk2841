/**
* @file Mac5-DesignSpec-D-Domain_Local_Dimming
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_BLU_REG_H_
#define _RBUS_BLU_REG_H_

#include "rbus_types.h"



//  BLU Register Address
#define  BLU_LD_Global_Ctrl0                                                     0x1802C200
#define  BLU_LD_Global_Ctrl0_reg_addr                                            "0xB802C200"
#define  BLU_LD_Global_Ctrl0_reg                                                 0xB802C200
#define  BLU_LD_Global_Ctrl0_inst_addr                                           "0x0000"
#define  set_BLU_LD_Global_Ctrl0_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Ctrl0_reg)=data)
#define  get_BLU_LD_Global_Ctrl0_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Ctrl0_reg))
#define  BLU_LD_Global_Ctrl0_ld_comp_en_shift                                    (31)
#define  BLU_LD_Global_Ctrl0_dummy_30_0_shift                                    (0)
#define  BLU_LD_Global_Ctrl0_ld_comp_en_mask                                     (0x80000000)
#define  BLU_LD_Global_Ctrl0_dummy_30_0_mask                                     (0x7FFFFFFF)
#define  BLU_LD_Global_Ctrl0_ld_comp_en(data)                                    (0x80000000&((data)<<31))
#define  BLU_LD_Global_Ctrl0_dummy_30_0(data)                                    (0x7FFFFFFF&(data))
#define  BLU_LD_Global_Ctrl0_get_ld_comp_en(data)                                ((0x80000000&(data))>>31)
#define  BLU_LD_Global_Ctrl0_get_dummy_30_0(data)                                (0x7FFFFFFF&(data))

#define  BLU_LD_Global_Ctrl1                                                     0x1802C204
#define  BLU_LD_Global_Ctrl1_reg_addr                                            "0xB802C204"
#define  BLU_LD_Global_Ctrl1_reg                                                 0xB802C204
#define  BLU_LD_Global_Ctrl1_inst_addr                                           "0x0001"
#define  set_BLU_LD_Global_Ctrl1_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Ctrl1_reg)=data)
#define  get_BLU_LD_Global_Ctrl1_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Ctrl1_reg))
#define  BLU_LD_Global_Ctrl1_ld_db_en_shift                                      (31)
#define  BLU_LD_Global_Ctrl1_ld_vs_sel_shift                                     (30)
#define  BLU_LD_Global_Ctrl1_ld_db_apply_shift                                   (29)
#define  BLU_LD_Global_Ctrl1_dummy_28_shift                                      (28)
#define  BLU_LD_Global_Ctrl1_ld_db_read_level_shift                              (27)
#define  BLU_LD_Global_Ctrl1_dummy_26_0_shift                                    (0)
#define  BLU_LD_Global_Ctrl1_ld_db_en_mask                                       (0x80000000)
#define  BLU_LD_Global_Ctrl1_ld_vs_sel_mask                                      (0x40000000)
#define  BLU_LD_Global_Ctrl1_ld_db_apply_mask                                    (0x20000000)
#define  BLU_LD_Global_Ctrl1_dummy_28_mask                                       (0x10000000)
#define  BLU_LD_Global_Ctrl1_ld_db_read_level_mask                               (0x08000000)
#define  BLU_LD_Global_Ctrl1_dummy_26_0_mask                                     (0x07FFFFFF)
#define  BLU_LD_Global_Ctrl1_ld_db_en(data)                                      (0x80000000&((data)<<31))
#define  BLU_LD_Global_Ctrl1_ld_vs_sel(data)                                     (0x40000000&((data)<<30))
#define  BLU_LD_Global_Ctrl1_ld_db_apply(data)                                   (0x20000000&((data)<<29))
#define  BLU_LD_Global_Ctrl1_dummy_28(data)                                      (0x10000000&((data)<<28))
#define  BLU_LD_Global_Ctrl1_ld_db_read_level(data)                              (0x08000000&((data)<<27))
#define  BLU_LD_Global_Ctrl1_dummy_26_0(data)                                    (0x07FFFFFF&(data))
#define  BLU_LD_Global_Ctrl1_get_ld_db_en(data)                                  ((0x80000000&(data))>>31)
#define  BLU_LD_Global_Ctrl1_get_ld_vs_sel(data)                                 ((0x40000000&(data))>>30)
#define  BLU_LD_Global_Ctrl1_get_ld_db_apply(data)                               ((0x20000000&(data))>>29)
#define  BLU_LD_Global_Ctrl1_get_dummy_28(data)                                  ((0x10000000&(data))>>28)
#define  BLU_LD_Global_Ctrl1_get_ld_db_read_level(data)                          ((0x08000000&(data))>>27)
#define  BLU_LD_Global_Ctrl1_get_dummy_26_0(data)                                (0x07FFFFFF&(data))

#define  BLU_LD_Global_Ctrl2                                                     0x1802C208
#define  BLU_LD_Global_Ctrl2_reg_addr                                            "0xB802C208"
#define  BLU_LD_Global_Ctrl2_reg                                                 0xB802C208
#define  BLU_LD_Global_Ctrl2_inst_addr                                           "0x0002"
#define  set_BLU_LD_Global_Ctrl2_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Ctrl2_reg)=data)
#define  get_BLU_LD_Global_Ctrl2_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Ctrl2_reg))
#define  BLU_LD_Global_Ctrl2_dummy_31_shift                                      (31)
#define  BLU_LD_Global_Ctrl2_ld_3d_mode_shift                                    (29)
#define  BLU_LD_Global_Ctrl2_ld_blk_hnum_shift                                   (24)
#define  BLU_LD_Global_Ctrl2_dummy_23_21_shift                                   (21)
#define  BLU_LD_Global_Ctrl2_ld_blk_vnum_shift                                   (16)
#define  BLU_LD_Global_Ctrl2_dummy_15_8_shift                                    (8)
#define  BLU_LD_Global_Ctrl2_ld_subblk_mode_shift                                (7)
#define  BLU_LD_Global_Ctrl2_ld_gdim_mode_shift                                  (6)
#define  BLU_LD_Global_Ctrl2_ld_blk_type_shift                                   (4)
#define  BLU_LD_Global_Ctrl2_ld_hist_mode_shift                                  (2)
#define  BLU_LD_Global_Ctrl2_ld_tenable_shift                                    (1)
#define  BLU_LD_Global_Ctrl2_ld_valid_shift                                      (0)
#define  BLU_LD_Global_Ctrl2_dummy_31_mask                                       (0x80000000)
#define  BLU_LD_Global_Ctrl2_ld_3d_mode_mask                                     (0x60000000)
#define  BLU_LD_Global_Ctrl2_ld_blk_hnum_mask                                    (0x1F000000)
#define  BLU_LD_Global_Ctrl2_dummy_23_21_mask                                    (0x00E00000)
#define  BLU_LD_Global_Ctrl2_ld_blk_vnum_mask                                    (0x001F0000)
#define  BLU_LD_Global_Ctrl2_dummy_15_8_mask                                     (0x0000FF00)
#define  BLU_LD_Global_Ctrl2_ld_subblk_mode_mask                                 (0x00000080)
#define  BLU_LD_Global_Ctrl2_ld_gdim_mode_mask                                   (0x00000040)
#define  BLU_LD_Global_Ctrl2_ld_blk_type_mask                                    (0x00000030)
#define  BLU_LD_Global_Ctrl2_ld_hist_mode_mask                                   (0x0000000C)
#define  BLU_LD_Global_Ctrl2_ld_tenable_mask                                     (0x00000002)
#define  BLU_LD_Global_Ctrl2_ld_valid_mask                                       (0x00000001)
#define  BLU_LD_Global_Ctrl2_dummy_31(data)                                      (0x80000000&((data)<<31))
#define  BLU_LD_Global_Ctrl2_ld_3d_mode(data)                                    (0x60000000&((data)<<29))
#define  BLU_LD_Global_Ctrl2_ld_blk_hnum(data)                                   (0x1F000000&((data)<<24))
#define  BLU_LD_Global_Ctrl2_dummy_23_21(data)                                   (0x00E00000&((data)<<21))
#define  BLU_LD_Global_Ctrl2_ld_blk_vnum(data)                                   (0x001F0000&((data)<<16))
#define  BLU_LD_Global_Ctrl2_dummy_15_8(data)                                    (0x0000FF00&((data)<<8))
#define  BLU_LD_Global_Ctrl2_ld_subblk_mode(data)                                (0x00000080&((data)<<7))
#define  BLU_LD_Global_Ctrl2_ld_gdim_mode(data)                                  (0x00000040&((data)<<6))
#define  BLU_LD_Global_Ctrl2_ld_blk_type(data)                                   (0x00000030&((data)<<4))
#define  BLU_LD_Global_Ctrl2_ld_hist_mode(data)                                  (0x0000000C&((data)<<2))
#define  BLU_LD_Global_Ctrl2_ld_tenable(data)                                    (0x00000002&((data)<<1))
#define  BLU_LD_Global_Ctrl2_ld_valid(data)                                      (0x00000001&(data))
#define  BLU_LD_Global_Ctrl2_get_dummy_31(data)                                  ((0x80000000&(data))>>31)
#define  BLU_LD_Global_Ctrl2_get_ld_3d_mode(data)                                ((0x60000000&(data))>>29)
#define  BLU_LD_Global_Ctrl2_get_ld_blk_hnum(data)                               ((0x1F000000&(data))>>24)
#define  BLU_LD_Global_Ctrl2_get_dummy_23_21(data)                               ((0x00E00000&(data))>>21)
#define  BLU_LD_Global_Ctrl2_get_ld_blk_vnum(data)                               ((0x001F0000&(data))>>16)
#define  BLU_LD_Global_Ctrl2_get_dummy_15_8(data)                                ((0x0000FF00&(data))>>8)
#define  BLU_LD_Global_Ctrl2_get_ld_subblk_mode(data)                            ((0x00000080&(data))>>7)
#define  BLU_LD_Global_Ctrl2_get_ld_gdim_mode(data)                              ((0x00000040&(data))>>6)
#define  BLU_LD_Global_Ctrl2_get_ld_blk_type(data)                               ((0x00000030&(data))>>4)
#define  BLU_LD_Global_Ctrl2_get_ld_hist_mode(data)                              ((0x0000000C&(data))>>2)
#define  BLU_LD_Global_Ctrl2_get_ld_tenable(data)                                ((0x00000002&(data))>>1)
#define  BLU_LD_Global_Ctrl2_get_ld_valid(data)                                  (0x00000001&(data))

#define  BLU_LD_Global_Ctrl3                                                     0x1802C20C
#define  BLU_LD_Global_Ctrl3_reg_addr                                            "0xB802C20C"
#define  BLU_LD_Global_Ctrl3_reg                                                 0xB802C20C
#define  BLU_LD_Global_Ctrl3_inst_addr                                           "0x0003"
#define  set_BLU_LD_Global_Ctrl3_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Ctrl3_reg)=data)
#define  get_BLU_LD_Global_Ctrl3_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Ctrl3_reg))
#define  BLU_LD_Global_Ctrl3_dummy_31_29_shift                                   (29)
#define  BLU_LD_Global_Ctrl3_ld_blk_hsize_shift                                  (16)
#define  BLU_LD_Global_Ctrl3_dummy_15_12_shift                                   (12)
#define  BLU_LD_Global_Ctrl3_ld_blk_vsize_shift                                  (0)
#define  BLU_LD_Global_Ctrl3_dummy_31_29_mask                                    (0xE0000000)
#define  BLU_LD_Global_Ctrl3_ld_blk_hsize_mask                                   (0x1FFF0000)
#define  BLU_LD_Global_Ctrl3_dummy_15_12_mask                                    (0x0000F000)
#define  BLU_LD_Global_Ctrl3_ld_blk_vsize_mask                                   (0x00000FFF)
#define  BLU_LD_Global_Ctrl3_dummy_31_29(data)                                   (0xE0000000&((data)<<29))
#define  BLU_LD_Global_Ctrl3_ld_blk_hsize(data)                                  (0x1FFF0000&((data)<<16))
#define  BLU_LD_Global_Ctrl3_dummy_15_12(data)                                   (0x0000F000&((data)<<12))
#define  BLU_LD_Global_Ctrl3_ld_blk_vsize(data)                                  (0x00000FFF&(data))
#define  BLU_LD_Global_Ctrl3_get_dummy_31_29(data)                               ((0xE0000000&(data))>>29)
#define  BLU_LD_Global_Ctrl3_get_ld_blk_hsize(data)                              ((0x1FFF0000&(data))>>16)
#define  BLU_LD_Global_Ctrl3_get_dummy_15_12(data)                               ((0x0000F000&(data))>>12)
#define  BLU_LD_Global_Ctrl3_get_ld_blk_vsize(data)                              (0x00000FFF&(data))

#define  BLU_LD_Global_Ctrl4                                                     0x1802CC70
#define  BLU_LD_Global_Ctrl4_reg_addr                                            "0xB802CC70"
#define  BLU_LD_Global_Ctrl4_reg                                                 0xB802CC70
#define  BLU_LD_Global_Ctrl4_inst_addr                                           "0x0004"
#define  set_BLU_LD_Global_Ctrl4_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Ctrl4_reg)=data)
#define  get_BLU_LD_Global_Ctrl4_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Ctrl4_reg))
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_7_shift                                  (31)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_6_shift                                  (30)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_5_shift                                  (29)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_4_shift                                  (28)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_3_shift                                  (27)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_2_shift                                  (26)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_1_shift                                  (25)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_0_shift                                  (24)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_7_shift                                   (23)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_6_shift                                   (22)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_5_shift                                   (21)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_4_shift                                   (20)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_3_shift                                   (19)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_2_shift                                   (18)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_1_shift                                   (17)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_0_shift                                   (16)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_7_shift                            (15)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_6_shift                            (14)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_5_shift                            (13)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_4_shift                            (12)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_3_shift                            (11)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_2_shift                            (10)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_1_shift                            (9)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_0_shift                            (8)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_7_shift                                (7)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_6_shift                                (6)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_5_shift                                (5)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_4_shift                                (4)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_3_shift                                (3)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_2_shift                                (2)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_1_shift                                (1)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_0_shift                                (0)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_7_mask                                   (0x80000000)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_6_mask                                   (0x40000000)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_5_mask                                   (0x20000000)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_4_mask                                   (0x10000000)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_3_mask                                   (0x08000000)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_2_mask                                   (0x04000000)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_1_mask                                   (0x02000000)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_0_mask                                   (0x01000000)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_7_mask                                    (0x00800000)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_6_mask                                    (0x00400000)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_5_mask                                    (0x00200000)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_4_mask                                    (0x00100000)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_3_mask                                    (0x00080000)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_2_mask                                    (0x00040000)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_1_mask                                    (0x00020000)
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_0_mask                                    (0x00010000)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_7_mask                             (0x00008000)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_6_mask                             (0x00004000)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_5_mask                             (0x00002000)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_4_mask                             (0x00001000)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_3_mask                             (0x00000800)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_2_mask                             (0x00000400)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_1_mask                             (0x00000200)
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_0_mask                             (0x00000100)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_7_mask                                 (0x00000080)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_6_mask                                 (0x00000040)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_5_mask                                 (0x00000020)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_4_mask                                 (0x00000010)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_3_mask                                 (0x00000008)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_2_mask                                 (0x00000004)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_1_mask                                 (0x00000002)
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_0_mask                                 (0x00000001)
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_7(data)                                  (0x80000000&((data)<<31))
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_6(data)                                  (0x40000000&((data)<<30))
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_5(data)                                  (0x20000000&((data)<<29))
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_4(data)                                  (0x10000000&((data)<<28))
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_3(data)                                  (0x08000000&((data)<<27))
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_2(data)                                  (0x04000000&((data)<<26))
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_1(data)                                  (0x02000000&((data)<<25))
#define  BLU_LD_Global_Ctrl4_ld_drf_rme_0(data)                                  (0x01000000&((data)<<24))
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_7(data)                                   (0x00800000&((data)<<23))
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_6(data)                                   (0x00400000&((data)<<22))
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_5(data)                                   (0x00200000&((data)<<21))
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_4(data)                                   (0x00100000&((data)<<20))
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_3(data)                                   (0x00080000&((data)<<19))
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_2(data)                                   (0x00040000&((data)<<18))
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_1(data)                                   (0x00020000&((data)<<17))
#define  BLU_LD_Global_Ctrl4_ld_drf_ls_0(data)                                   (0x00010000&((data)<<16))
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_7(data)                            (0x00008000&((data)<<15))
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_6(data)                            (0x00004000&((data)<<14))
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_5(data)                            (0x00002000&((data)<<13))
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_4(data)                            (0x00001000&((data)<<12))
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_3(data)                            (0x00000800&((data)<<11))
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_2(data)                            (0x00000400&((data)<<10))
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_1(data)                            (0x00000200&((data)<<9))
#define  BLU_LD_Global_Ctrl4_ld_drf_bist_fail_0(data)                            (0x00000100&((data)<<8))
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_7(data)                                (0x00000080&((data)<<7))
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_6(data)                                (0x00000040&((data)<<6))
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_5(data)                                (0x00000020&((data)<<5))
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_4(data)                                (0x00000010&((data)<<4))
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_3(data)                                (0x00000008&((data)<<3))
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_2(data)                                (0x00000004&((data)<<2))
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_1(data)                                (0x00000002&((data)<<1))
#define  BLU_LD_Global_Ctrl4_ld_bist_fail_0(data)                                (0x00000001&(data))
#define  BLU_LD_Global_Ctrl4_get_ld_drf_rme_7(data)                              ((0x80000000&(data))>>31)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_rme_6(data)                              ((0x40000000&(data))>>30)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_rme_5(data)                              ((0x20000000&(data))>>29)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_rme_4(data)                              ((0x10000000&(data))>>28)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_rme_3(data)                              ((0x08000000&(data))>>27)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_rme_2(data)                              ((0x04000000&(data))>>26)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_rme_1(data)                              ((0x02000000&(data))>>25)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_rme_0(data)                              ((0x01000000&(data))>>24)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_ls_7(data)                               ((0x00800000&(data))>>23)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_ls_6(data)                               ((0x00400000&(data))>>22)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_ls_5(data)                               ((0x00200000&(data))>>21)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_ls_4(data)                               ((0x00100000&(data))>>20)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_ls_3(data)                               ((0x00080000&(data))>>19)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_ls_2(data)                               ((0x00040000&(data))>>18)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_ls_1(data)                               ((0x00020000&(data))>>17)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_ls_0(data)                               ((0x00010000&(data))>>16)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_bist_fail_7(data)                        ((0x00008000&(data))>>15)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_bist_fail_6(data)                        ((0x00004000&(data))>>14)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_bist_fail_5(data)                        ((0x00002000&(data))>>13)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_bist_fail_4(data)                        ((0x00001000&(data))>>12)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_bist_fail_3(data)                        ((0x00000800&(data))>>11)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_bist_fail_2(data)                        ((0x00000400&(data))>>10)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_bist_fail_1(data)                        ((0x00000200&(data))>>9)
#define  BLU_LD_Global_Ctrl4_get_ld_drf_bist_fail_0(data)                        ((0x00000100&(data))>>8)
#define  BLU_LD_Global_Ctrl4_get_ld_bist_fail_7(data)                            ((0x00000080&(data))>>7)
#define  BLU_LD_Global_Ctrl4_get_ld_bist_fail_6(data)                            ((0x00000040&(data))>>6)
#define  BLU_LD_Global_Ctrl4_get_ld_bist_fail_5(data)                            ((0x00000020&(data))>>5)
#define  BLU_LD_Global_Ctrl4_get_ld_bist_fail_4(data)                            ((0x00000010&(data))>>4)
#define  BLU_LD_Global_Ctrl4_get_ld_bist_fail_3(data)                            ((0x00000008&(data))>>3)
#define  BLU_LD_Global_Ctrl4_get_ld_bist_fail_2(data)                            ((0x00000004&(data))>>2)
#define  BLU_LD_Global_Ctrl4_get_ld_bist_fail_1(data)                            ((0x00000002&(data))>>1)
#define  BLU_LD_Global_Ctrl4_get_ld_bist_fail_0(data)                            (0x00000001&(data))

#define  BLU_LD_Global_Ctrl5                                                     0x1802CC74
#define  BLU_LD_Global_Ctrl5_reg_addr                                            "0xB802CC74"
#define  BLU_LD_Global_Ctrl5_reg                                                 0xB802CC74
#define  BLU_LD_Global_Ctrl5_inst_addr                                           "0x0005"
#define  set_BLU_LD_Global_Ctrl5_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Ctrl5_reg)=data)
#define  get_BLU_LD_Global_Ctrl5_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Ctrl5_reg))
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_7_shift                                   (28)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_6_shift                                   (24)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_5_shift                                   (20)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_4_shift                                   (16)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_3_shift                                   (12)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_2_shift                                   (8)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_1_shift                                   (4)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_0_shift                                   (0)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_7_mask                                    (0xF0000000)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_6_mask                                    (0x0F000000)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_5_mask                                    (0x00F00000)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_4_mask                                    (0x000F0000)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_3_mask                                    (0x0000F000)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_2_mask                                    (0x00000F00)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_1_mask                                    (0x000000F0)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_0_mask                                    (0x0000000F)
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_7(data)                                   (0xF0000000&((data)<<28))
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_6(data)                                   (0x0F000000&((data)<<24))
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_5(data)                                   (0x00F00000&((data)<<20))
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_4(data)                                   (0x000F0000&((data)<<16))
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_3(data)                                   (0x0000F000&((data)<<12))
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_2(data)                                   (0x00000F00&((data)<<8))
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_1(data)                                   (0x000000F0&((data)<<4))
#define  BLU_LD_Global_Ctrl5_ld_drf_rm_0(data)                                   (0x0000000F&(data))
#define  BLU_LD_Global_Ctrl5_get_ld_drf_rm_7(data)                               ((0xF0000000&(data))>>28)
#define  BLU_LD_Global_Ctrl5_get_ld_drf_rm_6(data)                               ((0x0F000000&(data))>>24)
#define  BLU_LD_Global_Ctrl5_get_ld_drf_rm_5(data)                               ((0x00F00000&(data))>>20)
#define  BLU_LD_Global_Ctrl5_get_ld_drf_rm_4(data)                               ((0x000F0000&(data))>>16)
#define  BLU_LD_Global_Ctrl5_get_ld_drf_rm_3(data)                               ((0x0000F000&(data))>>12)
#define  BLU_LD_Global_Ctrl5_get_ld_drf_rm_2(data)                               ((0x00000F00&(data))>>8)
#define  BLU_LD_Global_Ctrl5_get_ld_drf_rm_1(data)                               ((0x000000F0&(data))>>4)
#define  BLU_LD_Global_Ctrl5_get_ld_drf_rm_0(data)                               (0x0000000F&(data))

#define  BLU_LD_Global_Ctrl6                                                     0x1802CC78
#define  BLU_LD_Global_Ctrl6_reg_addr                                            "0xB802CC78"
#define  BLU_LD_Global_Ctrl6_reg                                                 0xB802CC78
#define  BLU_LD_Global_Ctrl6_inst_addr                                           "0x0006"
#define  set_BLU_LD_Global_Ctrl6_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Ctrl6_reg)=data)
#define  get_BLU_LD_Global_Ctrl6_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Ctrl6_reg))
#define  BLU_LD_Global_Ctrl6_ld_drf_rm_9_shift                                   (12)
#define  BLU_LD_Global_Ctrl6_ld_drf_rm_8_shift                                   (8)
#define  BLU_LD_Global_Ctrl6_ld_drf_rme_9_shift                                  (7)
#define  BLU_LD_Global_Ctrl6_ld_drf_rme_8_shift                                  (6)
#define  BLU_LD_Global_Ctrl6_ld_drf_ls_9_shift                                   (5)
#define  BLU_LD_Global_Ctrl6_ld_drf_ls_8_shift                                   (4)
#define  BLU_LD_Global_Ctrl6_ld_drf_bist_fail_9_shift                            (3)
#define  BLU_LD_Global_Ctrl6_ld_drf_bist_fail_8_shift                            (2)
#define  BLU_LD_Global_Ctrl6_ld_bist_fail_9_shift                                (1)
#define  BLU_LD_Global_Ctrl6_ld_bist_fail_8_shift                                (0)
#define  BLU_LD_Global_Ctrl6_ld_drf_rm_9_mask                                    (0x0000F000)
#define  BLU_LD_Global_Ctrl6_ld_drf_rm_8_mask                                    (0x00000F00)
#define  BLU_LD_Global_Ctrl6_ld_drf_rme_9_mask                                   (0x00000080)
#define  BLU_LD_Global_Ctrl6_ld_drf_rme_8_mask                                   (0x00000040)
#define  BLU_LD_Global_Ctrl6_ld_drf_ls_9_mask                                    (0x00000020)
#define  BLU_LD_Global_Ctrl6_ld_drf_ls_8_mask                                    (0x00000010)
#define  BLU_LD_Global_Ctrl6_ld_drf_bist_fail_9_mask                             (0x00000008)
#define  BLU_LD_Global_Ctrl6_ld_drf_bist_fail_8_mask                             (0x00000004)
#define  BLU_LD_Global_Ctrl6_ld_bist_fail_9_mask                                 (0x00000002)
#define  BLU_LD_Global_Ctrl6_ld_bist_fail_8_mask                                 (0x00000001)
#define  BLU_LD_Global_Ctrl6_ld_drf_rm_9(data)                                   (0x0000F000&((data)<<12))
#define  BLU_LD_Global_Ctrl6_ld_drf_rm_8(data)                                   (0x00000F00&((data)<<8))
#define  BLU_LD_Global_Ctrl6_ld_drf_rme_9(data)                                  (0x00000080&((data)<<7))
#define  BLU_LD_Global_Ctrl6_ld_drf_rme_8(data)                                  (0x00000040&((data)<<6))
#define  BLU_LD_Global_Ctrl6_ld_drf_ls_9(data)                                   (0x00000020&((data)<<5))
#define  BLU_LD_Global_Ctrl6_ld_drf_ls_8(data)                                   (0x00000010&((data)<<4))
#define  BLU_LD_Global_Ctrl6_ld_drf_bist_fail_9(data)                            (0x00000008&((data)<<3))
#define  BLU_LD_Global_Ctrl6_ld_drf_bist_fail_8(data)                            (0x00000004&((data)<<2))
#define  BLU_LD_Global_Ctrl6_ld_bist_fail_9(data)                                (0x00000002&((data)<<1))
#define  BLU_LD_Global_Ctrl6_ld_bist_fail_8(data)                                (0x00000001&(data))
#define  BLU_LD_Global_Ctrl6_get_ld_drf_rm_9(data)                               ((0x0000F000&(data))>>12)
#define  BLU_LD_Global_Ctrl6_get_ld_drf_rm_8(data)                               ((0x00000F00&(data))>>8)
#define  BLU_LD_Global_Ctrl6_get_ld_drf_rme_9(data)                              ((0x00000080&(data))>>7)
#define  BLU_LD_Global_Ctrl6_get_ld_drf_rme_8(data)                              ((0x00000040&(data))>>6)
#define  BLU_LD_Global_Ctrl6_get_ld_drf_ls_9(data)                               ((0x00000020&(data))>>5)
#define  BLU_LD_Global_Ctrl6_get_ld_drf_ls_8(data)                               ((0x00000010&(data))>>4)
#define  BLU_LD_Global_Ctrl6_get_ld_drf_bist_fail_9(data)                        ((0x00000008&(data))>>3)
#define  BLU_LD_Global_Ctrl6_get_ld_drf_bist_fail_8(data)                        ((0x00000004&(data))>>2)
#define  BLU_LD_Global_Ctrl6_get_ld_bist_fail_9(data)                            ((0x00000002&(data))>>1)
#define  BLU_LD_Global_Ctrl6_get_ld_bist_fail_8(data)                            (0x00000001&(data))

#define  BLU_LD_Global_Max_Ctrl                                                  0x1802C218
#define  BLU_LD_Global_Max_Ctrl_reg_addr                                         "0xB802C218"
#define  BLU_LD_Global_Max_Ctrl_reg                                              0xB802C218
#define  BLU_LD_Global_Max_Ctrl_inst_addr                                        "0x0007"
#define  set_BLU_LD_Global_Max_Ctrl_reg(data)                                    (*((volatile unsigned int*)BLU_LD_Global_Max_Ctrl_reg)=data)
#define  get_BLU_LD_Global_Max_Ctrl_reg                                          (*((volatile unsigned int*)BLU_LD_Global_Max_Ctrl_reg))
#define  BLU_LD_Global_Max_Ctrl_ld_global_max_shift                              (0)
#define  BLU_LD_Global_Max_Ctrl_ld_global_max_mask                               (0x00000FFF)
#define  BLU_LD_Global_Max_Ctrl_ld_global_max(data)                              (0x00000FFF&(data))
#define  BLU_LD_Global_Max_Ctrl_get_ld_global_max(data)                          (0x00000FFF&(data))

#define  BLU_LD_Global_Hist1                                                     0x1802C21C
#define  BLU_LD_Global_Hist1_reg_addr                                            "0xB802C21C"
#define  BLU_LD_Global_Hist1_reg                                                 0xB802C21C
#define  BLU_LD_Global_Hist1_inst_addr                                           "0x0008"
#define  set_BLU_LD_Global_Hist1_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Hist1_reg)=data)
#define  get_BLU_LD_Global_Hist1_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Hist1_reg))
#define  BLU_LD_Global_Hist1_ld_global_hist0_shift                               (16)
#define  BLU_LD_Global_Hist1_ld_global_hist1_shift                               (0)
#define  BLU_LD_Global_Hist1_ld_global_hist0_mask                                (0xFFFF0000)
#define  BLU_LD_Global_Hist1_ld_global_hist1_mask                                (0x0000FFFF)
#define  BLU_LD_Global_Hist1_ld_global_hist0(data)                               (0xFFFF0000&((data)<<16))
#define  BLU_LD_Global_Hist1_ld_global_hist1(data)                               (0x0000FFFF&(data))
#define  BLU_LD_Global_Hist1_get_ld_global_hist0(data)                           ((0xFFFF0000&(data))>>16)
#define  BLU_LD_Global_Hist1_get_ld_global_hist1(data)                           (0x0000FFFF&(data))

#define  BLU_LD_Global_Hist2                                                     0x1802C220
#define  BLU_LD_Global_Hist2_reg_addr                                            "0xB802C220"
#define  BLU_LD_Global_Hist2_reg                                                 0xB802C220
#define  BLU_LD_Global_Hist2_inst_addr                                           "0x0009"
#define  set_BLU_LD_Global_Hist2_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Hist2_reg)=data)
#define  get_BLU_LD_Global_Hist2_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Hist2_reg))
#define  BLU_LD_Global_Hist2_ld_global_hist2_shift                               (16)
#define  BLU_LD_Global_Hist2_ld_global_hist3_shift                               (0)
#define  BLU_LD_Global_Hist2_ld_global_hist2_mask                                (0xFFFF0000)
#define  BLU_LD_Global_Hist2_ld_global_hist3_mask                                (0x0000FFFF)
#define  BLU_LD_Global_Hist2_ld_global_hist2(data)                               (0xFFFF0000&((data)<<16))
#define  BLU_LD_Global_Hist2_ld_global_hist3(data)                               (0x0000FFFF&(data))
#define  BLU_LD_Global_Hist2_get_ld_global_hist2(data)                           ((0xFFFF0000&(data))>>16)
#define  BLU_LD_Global_Hist2_get_ld_global_hist3(data)                           (0x0000FFFF&(data))

#define  BLU_LD_Global_Hist3                                                     0x1802C224
#define  BLU_LD_Global_Hist3_reg_addr                                            "0xB802C224"
#define  BLU_LD_Global_Hist3_reg                                                 0xB802C224
#define  BLU_LD_Global_Hist3_inst_addr                                           "0x000A"
#define  set_BLU_LD_Global_Hist3_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Hist3_reg)=data)
#define  get_BLU_LD_Global_Hist3_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Hist3_reg))
#define  BLU_LD_Global_Hist3_ld_global_hist4_shift                               (16)
#define  BLU_LD_Global_Hist3_ld_global_hist5_shift                               (0)
#define  BLU_LD_Global_Hist3_ld_global_hist4_mask                                (0xFFFF0000)
#define  BLU_LD_Global_Hist3_ld_global_hist5_mask                                (0x0000FFFF)
#define  BLU_LD_Global_Hist3_ld_global_hist4(data)                               (0xFFFF0000&((data)<<16))
#define  BLU_LD_Global_Hist3_ld_global_hist5(data)                               (0x0000FFFF&(data))
#define  BLU_LD_Global_Hist3_get_ld_global_hist4(data)                           ((0xFFFF0000&(data))>>16)
#define  BLU_LD_Global_Hist3_get_ld_global_hist5(data)                           (0x0000FFFF&(data))

#define  BLU_LD_Global_Hist4                                                     0x1802C228
#define  BLU_LD_Global_Hist4_reg_addr                                            "0xB802C228"
#define  BLU_LD_Global_Hist4_reg                                                 0xB802C228
#define  BLU_LD_Global_Hist4_inst_addr                                           "0x000B"
#define  set_BLU_LD_Global_Hist4_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Hist4_reg)=data)
#define  get_BLU_LD_Global_Hist4_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Hist4_reg))
#define  BLU_LD_Global_Hist4_ld_global_hist6_shift                               (16)
#define  BLU_LD_Global_Hist4_ld_global_hist7_shift                               (0)
#define  BLU_LD_Global_Hist4_ld_global_hist6_mask                                (0xFFFF0000)
#define  BLU_LD_Global_Hist4_ld_global_hist7_mask                                (0x0000FFFF)
#define  BLU_LD_Global_Hist4_ld_global_hist6(data)                               (0xFFFF0000&((data)<<16))
#define  BLU_LD_Global_Hist4_ld_global_hist7(data)                               (0x0000FFFF&(data))
#define  BLU_LD_Global_Hist4_get_ld_global_hist6(data)                           ((0xFFFF0000&(data))>>16)
#define  BLU_LD_Global_Hist4_get_ld_global_hist7(data)                           (0x0000FFFF&(data))

#define  BLU_LD_Global_Hist5                                                     0x1802C22C
#define  BLU_LD_Global_Hist5_reg_addr                                            "0xB802C22C"
#define  BLU_LD_Global_Hist5_reg                                                 0xB802C22C
#define  BLU_LD_Global_Hist5_inst_addr                                           "0x000C"
#define  set_BLU_LD_Global_Hist5_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Hist5_reg)=data)
#define  get_BLU_LD_Global_Hist5_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Hist5_reg))
#define  BLU_LD_Global_Hist5_ld_global_hist8_shift                               (16)
#define  BLU_LD_Global_Hist5_ld_global_hist9_shift                               (0)
#define  BLU_LD_Global_Hist5_ld_global_hist8_mask                                (0xFFFF0000)
#define  BLU_LD_Global_Hist5_ld_global_hist9_mask                                (0x0000FFFF)
#define  BLU_LD_Global_Hist5_ld_global_hist8(data)                               (0xFFFF0000&((data)<<16))
#define  BLU_LD_Global_Hist5_ld_global_hist9(data)                               (0x0000FFFF&(data))
#define  BLU_LD_Global_Hist5_get_ld_global_hist8(data)                           ((0xFFFF0000&(data))>>16)
#define  BLU_LD_Global_Hist5_get_ld_global_hist9(data)                           (0x0000FFFF&(data))

#define  BLU_LD_Global_Hist6                                                     0x1802C230
#define  BLU_LD_Global_Hist6_reg_addr                                            "0xB802C230"
#define  BLU_LD_Global_Hist6_reg                                                 0xB802C230
#define  BLU_LD_Global_Hist6_inst_addr                                           "0x000D"
#define  set_BLU_LD_Global_Hist6_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Hist6_reg)=data)
#define  get_BLU_LD_Global_Hist6_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Hist6_reg))
#define  BLU_LD_Global_Hist6_ld_global_hist10_shift                              (16)
#define  BLU_LD_Global_Hist6_ld_global_hist11_shift                              (0)
#define  BLU_LD_Global_Hist6_ld_global_hist10_mask                               (0xFFFF0000)
#define  BLU_LD_Global_Hist6_ld_global_hist11_mask                               (0x0000FFFF)
#define  BLU_LD_Global_Hist6_ld_global_hist10(data)                              (0xFFFF0000&((data)<<16))
#define  BLU_LD_Global_Hist6_ld_global_hist11(data)                              (0x0000FFFF&(data))
#define  BLU_LD_Global_Hist6_get_ld_global_hist10(data)                          ((0xFFFF0000&(data))>>16)
#define  BLU_LD_Global_Hist6_get_ld_global_hist11(data)                          (0x0000FFFF&(data))

#define  BLU_LD_Global_Hist7                                                     0x1802C234
#define  BLU_LD_Global_Hist7_reg_addr                                            "0xB802C234"
#define  BLU_LD_Global_Hist7_reg                                                 0xB802C234
#define  BLU_LD_Global_Hist7_inst_addr                                           "0x000E"
#define  set_BLU_LD_Global_Hist7_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Hist7_reg)=data)
#define  get_BLU_LD_Global_Hist7_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Hist7_reg))
#define  BLU_LD_Global_Hist7_ld_global_hist12_shift                              (16)
#define  BLU_LD_Global_Hist7_ld_global_hist13_shift                              (0)
#define  BLU_LD_Global_Hist7_ld_global_hist12_mask                               (0xFFFF0000)
#define  BLU_LD_Global_Hist7_ld_global_hist13_mask                               (0x0000FFFF)
#define  BLU_LD_Global_Hist7_ld_global_hist12(data)                              (0xFFFF0000&((data)<<16))
#define  BLU_LD_Global_Hist7_ld_global_hist13(data)                              (0x0000FFFF&(data))
#define  BLU_LD_Global_Hist7_get_ld_global_hist12(data)                          ((0xFFFF0000&(data))>>16)
#define  BLU_LD_Global_Hist7_get_ld_global_hist13(data)                          (0x0000FFFF&(data))

#define  BLU_LD_Global_Hist8                                                     0x1802C238
#define  BLU_LD_Global_Hist8_reg_addr                                            "0xB802C238"
#define  BLU_LD_Global_Hist8_reg                                                 0xB802C238
#define  BLU_LD_Global_Hist8_inst_addr                                           "0x000F"
#define  set_BLU_LD_Global_Hist8_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Global_Hist8_reg)=data)
#define  get_BLU_LD_Global_Hist8_reg                                             (*((volatile unsigned int*)BLU_LD_Global_Hist8_reg))
#define  BLU_LD_Global_Hist8_ld_global_hist14_shift                              (16)
#define  BLU_LD_Global_Hist8_ld_global_hist15_shift                              (0)
#define  BLU_LD_Global_Hist8_ld_global_hist14_mask                               (0xFFFF0000)
#define  BLU_LD_Global_Hist8_ld_global_hist15_mask                               (0x0000FFFF)
#define  BLU_LD_Global_Hist8_ld_global_hist14(data)                              (0xFFFF0000&((data)<<16))
#define  BLU_LD_Global_Hist8_ld_global_hist15(data)                              (0x0000FFFF&(data))
#define  BLU_LD_Global_Hist8_get_ld_global_hist14(data)                          ((0xFFFF0000&(data))>>16)
#define  BLU_LD_Global_Hist8_get_ld_global_hist15(data)                          (0x0000FFFF&(data))

#define  BLU_LD_Decision_Ctrl1                                                   0x1802C23C
#define  BLU_LD_Decision_Ctrl1_reg_addr                                          "0xB802C23C"
#define  BLU_LD_Decision_Ctrl1_reg                                               0xB802C23C
#define  BLU_LD_Decision_Ctrl1_inst_addr                                         "0x0010"
#define  set_BLU_LD_Decision_Ctrl1_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Decision_Ctrl1_reg)=data)
#define  get_BLU_LD_Decision_Ctrl1_reg                                           (*((volatile unsigned int*)BLU_LD_Decision_Ctrl1_reg))
#define  BLU_LD_Decision_Ctrl1_ld_maxgain_shift                                  (24)
#define  BLU_LD_Decision_Ctrl1_ld_avegain_shift                                  (16)
#define  BLU_LD_Decision_Ctrl1_ld_histshiftbit_shift                             (0)
#define  BLU_LD_Decision_Ctrl1_ld_maxgain_mask                                   (0x3F000000)
#define  BLU_LD_Decision_Ctrl1_ld_avegain_mask                                   (0x001F0000)
#define  BLU_LD_Decision_Ctrl1_ld_histshiftbit_mask                              (0x0000000F)
#define  BLU_LD_Decision_Ctrl1_ld_maxgain(data)                                  (0x3F000000&((data)<<24))
#define  BLU_LD_Decision_Ctrl1_ld_avegain(data)                                  (0x001F0000&((data)<<16))
#define  BLU_LD_Decision_Ctrl1_ld_histshiftbit(data)                             (0x0000000F&(data))
#define  BLU_LD_Decision_Ctrl1_get_ld_maxgain(data)                              ((0x3F000000&(data))>>24)
#define  BLU_LD_Decision_Ctrl1_get_ld_avegain(data)                              ((0x001F0000&(data))>>16)
#define  BLU_LD_Decision_Ctrl1_get_ld_histshiftbit(data)                         (0x0000000F&(data))

#define  BLU_LD_Decision_Ctrl2                                                   0x1802C240
#define  BLU_LD_Decision_Ctrl2_reg_addr                                          "0xB802C240"
#define  BLU_LD_Decision_Ctrl2_reg                                               0xB802C240
#define  BLU_LD_Decision_Ctrl2_inst_addr                                         "0x0011"
#define  set_BLU_LD_Decision_Ctrl2_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Decision_Ctrl2_reg)=data)
#define  get_BLU_LD_Decision_Ctrl2_reg                                           (*((volatile unsigned int*)BLU_LD_Decision_Ctrl2_reg))
#define  BLU_LD_Decision_Ctrl2_ld_hist0gain_shift                                (24)
#define  BLU_LD_Decision_Ctrl2_ld_hist1gain_shift                                (16)
#define  BLU_LD_Decision_Ctrl2_ld_hist2gain_shift                                (8)
#define  BLU_LD_Decision_Ctrl2_ld_hist3gain_shift                                (0)
#define  BLU_LD_Decision_Ctrl2_ld_hist0gain_mask                                 (0x3F000000)
#define  BLU_LD_Decision_Ctrl2_ld_hist1gain_mask                                 (0x003F0000)
#define  BLU_LD_Decision_Ctrl2_ld_hist2gain_mask                                 (0x00003F00)
#define  BLU_LD_Decision_Ctrl2_ld_hist3gain_mask                                 (0x0000003F)
#define  BLU_LD_Decision_Ctrl2_ld_hist0gain(data)                                (0x3F000000&((data)<<24))
#define  BLU_LD_Decision_Ctrl2_ld_hist1gain(data)                                (0x003F0000&((data)<<16))
#define  BLU_LD_Decision_Ctrl2_ld_hist2gain(data)                                (0x00003F00&((data)<<8))
#define  BLU_LD_Decision_Ctrl2_ld_hist3gain(data)                                (0x0000003F&(data))
#define  BLU_LD_Decision_Ctrl2_get_ld_hist0gain(data)                            ((0x3F000000&(data))>>24)
#define  BLU_LD_Decision_Ctrl2_get_ld_hist1gain(data)                            ((0x003F0000&(data))>>16)
#define  BLU_LD_Decision_Ctrl2_get_ld_hist2gain(data)                            ((0x00003F00&(data))>>8)
#define  BLU_LD_Decision_Ctrl2_get_ld_hist3gain(data)                            (0x0000003F&(data))

#define  BLU_LD_Decision_Ctrl3                                                   0x1802C244
#define  BLU_LD_Decision_Ctrl3_reg_addr                                          "0xB802C244"
#define  BLU_LD_Decision_Ctrl3_reg                                               0xB802C244
#define  BLU_LD_Decision_Ctrl3_inst_addr                                         "0x0012"
#define  set_BLU_LD_Decision_Ctrl3_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Decision_Ctrl3_reg)=data)
#define  get_BLU_LD_Decision_Ctrl3_reg                                           (*((volatile unsigned int*)BLU_LD_Decision_Ctrl3_reg))
#define  BLU_LD_Decision_Ctrl3_ld_hist4gain_shift                                (24)
#define  BLU_LD_Decision_Ctrl3_ld_hist5gain_shift                                (16)
#define  BLU_LD_Decision_Ctrl3_ld_hist6gain_shift                                (8)
#define  BLU_LD_Decision_Ctrl3_ld_hist7gain_shift                                (0)
#define  BLU_LD_Decision_Ctrl3_ld_hist4gain_mask                                 (0x3F000000)
#define  BLU_LD_Decision_Ctrl3_ld_hist5gain_mask                                 (0x003F0000)
#define  BLU_LD_Decision_Ctrl3_ld_hist6gain_mask                                 (0x00003F00)
#define  BLU_LD_Decision_Ctrl3_ld_hist7gain_mask                                 (0x0000003F)
#define  BLU_LD_Decision_Ctrl3_ld_hist4gain(data)                                (0x3F000000&((data)<<24))
#define  BLU_LD_Decision_Ctrl3_ld_hist5gain(data)                                (0x003F0000&((data)<<16))
#define  BLU_LD_Decision_Ctrl3_ld_hist6gain(data)                                (0x00003F00&((data)<<8))
#define  BLU_LD_Decision_Ctrl3_ld_hist7gain(data)                                (0x0000003F&(data))
#define  BLU_LD_Decision_Ctrl3_get_ld_hist4gain(data)                            ((0x3F000000&(data))>>24)
#define  BLU_LD_Decision_Ctrl3_get_ld_hist5gain(data)                            ((0x003F0000&(data))>>16)
#define  BLU_LD_Decision_Ctrl3_get_ld_hist6gain(data)                            ((0x00003F00&(data))>>8)
#define  BLU_LD_Decision_Ctrl3_get_ld_hist7gain(data)                            (0x0000003F&(data))

#define  BLU_LD_Decision_Ctrl4                                                   0x1802C248
#define  BLU_LD_Decision_Ctrl4_reg_addr                                          "0xB802C248"
#define  BLU_LD_Decision_Ctrl4_reg                                               0xB802C248
#define  BLU_LD_Decision_Ctrl4_inst_addr                                         "0x0013"
#define  set_BLU_LD_Decision_Ctrl4_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Decision_Ctrl4_reg)=data)
#define  get_BLU_LD_Decision_Ctrl4_reg                                           (*((volatile unsigned int*)BLU_LD_Decision_Ctrl4_reg))
#define  BLU_LD_Decision_Ctrl4_ld_decaccess_addr_shift                           (16)
#define  BLU_LD_Decision_Ctrl4_ld_decaccess_en_shift                             (0)
#define  BLU_LD_Decision_Ctrl4_ld_decaccess_addr_mask                            (0x01FF0000)
#define  BLU_LD_Decision_Ctrl4_ld_decaccess_en_mask                              (0x00000001)
#define  BLU_LD_Decision_Ctrl4_ld_decaccess_addr(data)                           (0x01FF0000&((data)<<16))
#define  BLU_LD_Decision_Ctrl4_ld_decaccess_en(data)                             (0x00000001&(data))
#define  BLU_LD_Decision_Ctrl4_get_ld_decaccess_addr(data)                       ((0x01FF0000&(data))>>16)
#define  BLU_LD_Decision_Ctrl4_get_ld_decaccess_en(data)                         (0x00000001&(data))

#define  BLU_LD_Decision_Ctrl5                                                   0x1802C24C
#define  BLU_LD_Decision_Ctrl5_reg_addr                                          "0xB802C24C"
#define  BLU_LD_Decision_Ctrl5_reg                                               0xB802C24C
#define  BLU_LD_Decision_Ctrl5_inst_addr                                         "0x0014"
#define  set_BLU_LD_Decision_Ctrl5_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Decision_Ctrl5_reg)=data)
#define  get_BLU_LD_Decision_Ctrl5_reg                                           (*((volatile unsigned int*)BLU_LD_Decision_Ctrl5_reg))
#define  BLU_LD_Decision_Ctrl5_ld_decaccess_data_shift                           (0)
#define  BLU_LD_Decision_Ctrl5_ld_decaccess_data_mask                            (0x3FFFFFFF)
#define  BLU_LD_Decision_Ctrl5_ld_decaccess_data(data)                           (0x3FFFFFFF&(data))
#define  BLU_LD_Decision_Ctrl5_get_ld_decaccess_data(data)                       (0x3FFFFFFF&(data))

#define  BLU_LD_Spatial_Ctrl1                                                    0x1802C250
#define  BLU_LD_Spatial_Ctrl1_reg_addr                                           "0xB802C250"
#define  BLU_LD_Spatial_Ctrl1_reg                                                0xB802C250
#define  BLU_LD_Spatial_Ctrl1_inst_addr                                          "0x0015"
#define  set_BLU_LD_Spatial_Ctrl1_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl1_reg)=data)
#define  get_BLU_LD_Spatial_Ctrl1_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl1_reg))
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef0_shift                              (28)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef1_shift                              (24)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef2_shift                              (20)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef3_shift                              (16)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef4_shift                              (12)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef5_shift                              (8)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef6_shift                              (4)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef7_shift                              (0)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef0_mask                               (0xF0000000)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef1_mask                               (0x0F000000)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef2_mask                               (0x00F00000)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef3_mask                               (0x000F0000)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef4_mask                               (0x0000F000)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef5_mask                               (0x00000F00)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef6_mask                               (0x000000F0)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef7_mask                               (0x0000000F)
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef0(data)                              (0xF0000000&((data)<<28))
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef1(data)                              (0x0F000000&((data)<<24))
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef2(data)                              (0x00F00000&((data)<<20))
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef3(data)                              (0x000F0000&((data)<<16))
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef4(data)                              (0x0000F000&((data)<<12))
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef5(data)                              (0x00000F00&((data)<<8))
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef6(data)                              (0x000000F0&((data)<<4))
#define  BLU_LD_Spatial_Ctrl1_ld_spatialcoef7(data)                              (0x0000000F&(data))
#define  BLU_LD_Spatial_Ctrl1_get_ld_spatialcoef0(data)                          ((0xF0000000&(data))>>28)
#define  BLU_LD_Spatial_Ctrl1_get_ld_spatialcoef1(data)                          ((0x0F000000&(data))>>24)
#define  BLU_LD_Spatial_Ctrl1_get_ld_spatialcoef2(data)                          ((0x00F00000&(data))>>20)
#define  BLU_LD_Spatial_Ctrl1_get_ld_spatialcoef3(data)                          ((0x000F0000&(data))>>16)
#define  BLU_LD_Spatial_Ctrl1_get_ld_spatialcoef4(data)                          ((0x0000F000&(data))>>12)
#define  BLU_LD_Spatial_Ctrl1_get_ld_spatialcoef5(data)                          ((0x00000F00&(data))>>8)
#define  BLU_LD_Spatial_Ctrl1_get_ld_spatialcoef6(data)                          ((0x000000F0&(data))>>4)
#define  BLU_LD_Spatial_Ctrl1_get_ld_spatialcoef7(data)                          (0x0000000F&(data))

#define  BLU_LD_Spatial_Ctrl2                                                    0x1802C254
#define  BLU_LD_Spatial_Ctrl2_reg_addr                                           "0xB802C254"
#define  BLU_LD_Spatial_Ctrl2_reg                                                0xB802C254
#define  BLU_LD_Spatial_Ctrl2_inst_addr                                          "0x0016"
#define  set_BLU_LD_Spatial_Ctrl2_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl2_reg)=data)
#define  get_BLU_LD_Spatial_Ctrl2_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl2_reg))
#define  BLU_LD_Spatial_Ctrl2_ld_spatialcoef8_shift                              (28)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialcoef9_shift                              (24)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialcoef10_shift                             (20)
#define  BLU_LD_Spatial_Ctrl2_dummy_19_3_shift                                   (3)
#define  BLU_LD_Spatial_Ctrl2_ld_backlightboosten_shift                          (2)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialremapbusy_shift                          (1)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialremapen_shift                            (0)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialcoef8_mask                               (0xF0000000)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialcoef9_mask                               (0x0F000000)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialcoef10_mask                              (0x00F00000)
#define  BLU_LD_Spatial_Ctrl2_dummy_19_3_mask                                    (0x000FFFF8)
#define  BLU_LD_Spatial_Ctrl2_ld_backlightboosten_mask                           (0x00000004)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialremapbusy_mask                           (0x00000002)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialremapen_mask                             (0x00000001)
#define  BLU_LD_Spatial_Ctrl2_ld_spatialcoef8(data)                              (0xF0000000&((data)<<28))
#define  BLU_LD_Spatial_Ctrl2_ld_spatialcoef9(data)                              (0x0F000000&((data)<<24))
#define  BLU_LD_Spatial_Ctrl2_ld_spatialcoef10(data)                             (0x00F00000&((data)<<20))
#define  BLU_LD_Spatial_Ctrl2_dummy_19_3(data)                                   (0x000FFFF8&((data)<<3))
#define  BLU_LD_Spatial_Ctrl2_ld_backlightboosten(data)                          (0x00000004&((data)<<2))
#define  BLU_LD_Spatial_Ctrl2_ld_spatialremapbusy(data)                          (0x00000002&((data)<<1))
#define  BLU_LD_Spatial_Ctrl2_ld_spatialremapen(data)                            (0x00000001&(data))
#define  BLU_LD_Spatial_Ctrl2_get_ld_spatialcoef8(data)                          ((0xF0000000&(data))>>28)
#define  BLU_LD_Spatial_Ctrl2_get_ld_spatialcoef9(data)                          ((0x0F000000&(data))>>24)
#define  BLU_LD_Spatial_Ctrl2_get_ld_spatialcoef10(data)                         ((0x00F00000&(data))>>20)
#define  BLU_LD_Spatial_Ctrl2_get_dummy_19_3(data)                               ((0x000FFFF8&(data))>>3)
#define  BLU_LD_Spatial_Ctrl2_get_ld_backlightboosten(data)                      ((0x00000004&(data))>>2)
#define  BLU_LD_Spatial_Ctrl2_get_ld_spatialremapbusy(data)                      ((0x00000002&(data))>>1)
#define  BLU_LD_Spatial_Ctrl2_get_ld_spatialremapen(data)                        (0x00000001&(data))

#define  BLU_LD_Spatial_Ctrl5                                                    0x1802CC00
#define  BLU_LD_Spatial_Ctrl5_reg_addr                                           "0xB802CC00"
#define  BLU_LD_Spatial_Ctrl5_reg                                                0xB802CC00
#define  BLU_LD_Spatial_Ctrl5_inst_addr                                          "0x0017"
#define  set_BLU_LD_Spatial_Ctrl5_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl5_reg)=data)
#define  get_BLU_LD_Spatial_Ctrl5_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl5_reg))
#define  BLU_LD_Spatial_Ctrl5_spatial_new_mode_shift                             (30)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef00_shift                          (24)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef01_shift                          (18)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef02_shift                          (12)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef03_shift                          (6)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef04_shift                          (0)
#define  BLU_LD_Spatial_Ctrl5_spatial_new_mode_mask                              (0x40000000)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef00_mask                           (0x3F000000)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef01_mask                           (0x00FC0000)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef02_mask                           (0x0003F000)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef03_mask                           (0x00000FC0)
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef04_mask                           (0x0000003F)
#define  BLU_LD_Spatial_Ctrl5_spatial_new_mode(data)                             (0x40000000&((data)<<30))
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef00(data)                          (0x3F000000&((data)<<24))
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef01(data)                          (0x00FC0000&((data)<<18))
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef02(data)                          (0x0003F000&((data)<<12))
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef03(data)                          (0x00000FC0&((data)<<6))
#define  BLU_LD_Spatial_Ctrl5_ld_spatialnewcoef04(data)                          (0x0000003F&(data))
#define  BLU_LD_Spatial_Ctrl5_get_spatial_new_mode(data)                         ((0x40000000&(data))>>30)
#define  BLU_LD_Spatial_Ctrl5_get_ld_spatialnewcoef00(data)                      ((0x3F000000&(data))>>24)
#define  BLU_LD_Spatial_Ctrl5_get_ld_spatialnewcoef01(data)                      ((0x00FC0000&(data))>>18)
#define  BLU_LD_Spatial_Ctrl5_get_ld_spatialnewcoef02(data)                      ((0x0003F000&(data))>>12)
#define  BLU_LD_Spatial_Ctrl5_get_ld_spatialnewcoef03(data)                      ((0x00000FC0&(data))>>6)
#define  BLU_LD_Spatial_Ctrl5_get_ld_spatialnewcoef04(data)                      (0x0000003F&(data))

#define  BLU_LD_Spatial_Ctrl6                                                    0x1802CC04
#define  BLU_LD_Spatial_Ctrl6_reg_addr                                           "0xB802CC04"
#define  BLU_LD_Spatial_Ctrl6_reg                                                0xB802CC04
#define  BLU_LD_Spatial_Ctrl6_inst_addr                                          "0x0018"
#define  set_BLU_LD_Spatial_Ctrl6_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl6_reg)=data)
#define  get_BLU_LD_Spatial_Ctrl6_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl6_reg))
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef10_shift                          (24)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef11_shift                          (18)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef12_shift                          (12)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef13_shift                          (6)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef14_shift                          (0)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef10_mask                           (0x3F000000)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef11_mask                           (0x00FC0000)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef12_mask                           (0x0003F000)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef13_mask                           (0x00000FC0)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef14_mask                           (0x0000003F)
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef10(data)                          (0x3F000000&((data)<<24))
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef11(data)                          (0x00FC0000&((data)<<18))
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef12(data)                          (0x0003F000&((data)<<12))
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef13(data)                          (0x00000FC0&((data)<<6))
#define  BLU_LD_Spatial_Ctrl6_ld_spatialnewcoef14(data)                          (0x0000003F&(data))
#define  BLU_LD_Spatial_Ctrl6_get_ld_spatialnewcoef10(data)                      ((0x3F000000&(data))>>24)
#define  BLU_LD_Spatial_Ctrl6_get_ld_spatialnewcoef11(data)                      ((0x00FC0000&(data))>>18)
#define  BLU_LD_Spatial_Ctrl6_get_ld_spatialnewcoef12(data)                      ((0x0003F000&(data))>>12)
#define  BLU_LD_Spatial_Ctrl6_get_ld_spatialnewcoef13(data)                      ((0x00000FC0&(data))>>6)
#define  BLU_LD_Spatial_Ctrl6_get_ld_spatialnewcoef14(data)                      (0x0000003F&(data))

#define  BLU_LD_Spatial_Ctrl7                                                    0x1802CC08
#define  BLU_LD_Spatial_Ctrl7_reg_addr                                           "0xB802CC08"
#define  BLU_LD_Spatial_Ctrl7_reg                                                0xB802CC08
#define  BLU_LD_Spatial_Ctrl7_inst_addr                                          "0x0019"
#define  set_BLU_LD_Spatial_Ctrl7_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl7_reg)=data)
#define  get_BLU_LD_Spatial_Ctrl7_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl7_reg))
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef20_shift                          (24)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef21_shift                          (18)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef22_shift                          (12)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef23_shift                          (6)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef24_shift                          (0)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef20_mask                           (0x3F000000)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef21_mask                           (0x00FC0000)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef22_mask                           (0x0003F000)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef23_mask                           (0x00000FC0)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef24_mask                           (0x0000003F)
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef20(data)                          (0x3F000000&((data)<<24))
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef21(data)                          (0x00FC0000&((data)<<18))
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef22(data)                          (0x0003F000&((data)<<12))
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef23(data)                          (0x00000FC0&((data)<<6))
#define  BLU_LD_Spatial_Ctrl7_ld_spatialnewcoef24(data)                          (0x0000003F&(data))
#define  BLU_LD_Spatial_Ctrl7_get_ld_spatialnewcoef20(data)                      ((0x3F000000&(data))>>24)
#define  BLU_LD_Spatial_Ctrl7_get_ld_spatialnewcoef21(data)                      ((0x00FC0000&(data))>>18)
#define  BLU_LD_Spatial_Ctrl7_get_ld_spatialnewcoef22(data)                      ((0x0003F000&(data))>>12)
#define  BLU_LD_Spatial_Ctrl7_get_ld_spatialnewcoef23(data)                      ((0x00000FC0&(data))>>6)
#define  BLU_LD_Spatial_Ctrl7_get_ld_spatialnewcoef24(data)                      (0x0000003F&(data))

#define  BLU_LD_Spatial_Ctrl8                                                    0x1802CC0C
#define  BLU_LD_Spatial_Ctrl8_reg_addr                                           "0xB802CC0C"
#define  BLU_LD_Spatial_Ctrl8_reg                                                0xB802CC0C
#define  BLU_LD_Spatial_Ctrl8_inst_addr                                          "0x001A"
#define  set_BLU_LD_Spatial_Ctrl8_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl8_reg)=data)
#define  get_BLU_LD_Spatial_Ctrl8_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl8_reg))
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef30_shift                          (24)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef31_shift                          (18)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef32_shift                          (12)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef33_shift                          (6)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef34_shift                          (0)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef30_mask                           (0x3F000000)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef31_mask                           (0x00FC0000)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef32_mask                           (0x0003F000)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef33_mask                           (0x00000FC0)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef34_mask                           (0x0000003F)
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef30(data)                          (0x3F000000&((data)<<24))
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef31(data)                          (0x00FC0000&((data)<<18))
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef32(data)                          (0x0003F000&((data)<<12))
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef33(data)                          (0x00000FC0&((data)<<6))
#define  BLU_LD_Spatial_Ctrl8_ld_spatialnewcoef34(data)                          (0x0000003F&(data))
#define  BLU_LD_Spatial_Ctrl8_get_ld_spatialnewcoef30(data)                      ((0x3F000000&(data))>>24)
#define  BLU_LD_Spatial_Ctrl8_get_ld_spatialnewcoef31(data)                      ((0x00FC0000&(data))>>18)
#define  BLU_LD_Spatial_Ctrl8_get_ld_spatialnewcoef32(data)                      ((0x0003F000&(data))>>12)
#define  BLU_LD_Spatial_Ctrl8_get_ld_spatialnewcoef33(data)                      ((0x00000FC0&(data))>>6)
#define  BLU_LD_Spatial_Ctrl8_get_ld_spatialnewcoef34(data)                      (0x0000003F&(data))

#define  BLU_LD_Spatial_Ctrl9                                                    0x1802CC10
#define  BLU_LD_Spatial_Ctrl9_reg_addr                                           "0xB802CC10"
#define  BLU_LD_Spatial_Ctrl9_reg                                                0xB802CC10
#define  BLU_LD_Spatial_Ctrl9_inst_addr                                          "0x001B"
#define  set_BLU_LD_Spatial_Ctrl9_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl9_reg)=data)
#define  get_BLU_LD_Spatial_Ctrl9_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl9_reg))
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef05_shift                          (18)
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef15_shift                          (12)
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef25_shift                          (6)
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef35_shift                          (0)
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef05_mask                           (0x00FC0000)
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef15_mask                           (0x0003F000)
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef25_mask                           (0x00000FC0)
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef35_mask                           (0x0000003F)
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef05(data)                          (0x00FC0000&((data)<<18))
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef15(data)                          (0x0003F000&((data)<<12))
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef25(data)                          (0x00000FC0&((data)<<6))
#define  BLU_LD_Spatial_Ctrl9_ld_spatialnewcoef35(data)                          (0x0000003F&(data))
#define  BLU_LD_Spatial_Ctrl9_get_ld_spatialnewcoef05(data)                      ((0x00FC0000&(data))>>18)
#define  BLU_LD_Spatial_Ctrl9_get_ld_spatialnewcoef15(data)                      ((0x0003F000&(data))>>12)
#define  BLU_LD_Spatial_Ctrl9_get_ld_spatialnewcoef25(data)                      ((0x00000FC0&(data))>>6)
#define  BLU_LD_Spatial_Ctrl9_get_ld_spatialnewcoef35(data)                      (0x0000003F&(data))

#define  BLU_LD_Spatial_CtrlA                                                    0x1802CC14
#define  BLU_LD_Spatial_CtrlA_reg_addr                                           "0xB802CC14"
#define  BLU_LD_Spatial_CtrlA_reg                                                0xB802CC14
#define  BLU_LD_Spatial_CtrlA_inst_addr                                          "0x001C"
#define  set_BLU_LD_Spatial_CtrlA_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_CtrlA_reg)=data)
#define  get_BLU_LD_Spatial_CtrlA_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_CtrlA_reg))
#define  BLU_LD_Spatial_CtrlA_ld_spatialnewcoef40_shift                          (12)
#define  BLU_LD_Spatial_CtrlA_ld_spatialnewcoef41_shift                          (6)
#define  BLU_LD_Spatial_CtrlA_ld_spatialnewcoef50_shift                          (0)
#define  BLU_LD_Spatial_CtrlA_ld_spatialnewcoef40_mask                           (0x0003F000)
#define  BLU_LD_Spatial_CtrlA_ld_spatialnewcoef41_mask                           (0x00000FC0)
#define  BLU_LD_Spatial_CtrlA_ld_spatialnewcoef50_mask                           (0x0000003F)
#define  BLU_LD_Spatial_CtrlA_ld_spatialnewcoef40(data)                          (0x0003F000&((data)<<12))
#define  BLU_LD_Spatial_CtrlA_ld_spatialnewcoef41(data)                          (0x00000FC0&((data)<<6))
#define  BLU_LD_Spatial_CtrlA_ld_spatialnewcoef50(data)                          (0x0000003F&(data))
#define  BLU_LD_Spatial_CtrlA_get_ld_spatialnewcoef40(data)                      ((0x0003F000&(data))>>12)
#define  BLU_LD_Spatial_CtrlA_get_ld_spatialnewcoef41(data)                      ((0x00000FC0&(data))>>6)
#define  BLU_LD_Spatial_CtrlA_get_ld_spatialnewcoef50(data)                      (0x0000003F&(data))

#define  BLU_LD_DATA_COMP_CTRL                                                   0x1802CC30
#define  BLU_LD_DATA_COMP_CTRL_reg_addr                                          "0xB802CC30"
#define  BLU_LD_DATA_COMP_CTRL_reg                                               0xB802CC30
#define  BLU_LD_DATA_COMP_CTRL_inst_addr                                         "0x001D"
#define  set_BLU_LD_DATA_COMP_CTRL_reg(data)                                     (*((volatile unsigned int*)BLU_LD_DATA_COMP_CTRL_reg)=data)
#define  get_BLU_LD_DATA_COMP_CTRL_reg                                           (*((volatile unsigned int*)BLU_LD_DATA_COMP_CTRL_reg))
#define  BLU_LD_DATA_COMP_CTRL_ld_comp_2dlut_maxmode_shift                       (19)
#define  BLU_LD_DATA_COMP_CTRL_ld_data_comp_mode_shift                           (18)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_ax_en_shift                                (16)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_ax_mode_shift                              (15)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_adr_mode_shift                             (14)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_row_addr_shift                             (6)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_column_addr_shift                          (0)
#define  BLU_LD_DATA_COMP_CTRL_ld_comp_2dlut_maxmode_mask                        (0x00080000)
#define  BLU_LD_DATA_COMP_CTRL_ld_data_comp_mode_mask                            (0x00040000)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_ax_en_mask                                 (0x00010000)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_ax_mode_mask                               (0x00008000)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_adr_mode_mask                              (0x00004000)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_row_addr_mask                              (0x000007C0)
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_column_addr_mask                           (0x0000001F)
#define  BLU_LD_DATA_COMP_CTRL_ld_comp_2dlut_maxmode(data)                       (0x00080000&((data)<<19))
#define  BLU_LD_DATA_COMP_CTRL_ld_data_comp_mode(data)                           (0x00040000&((data)<<18))
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_ax_en(data)                                (0x00010000&((data)<<16))
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_ax_mode(data)                              (0x00008000&((data)<<15))
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_adr_mode(data)                             (0x00004000&((data)<<14))
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_row_addr(data)                             (0x000007C0&((data)<<6))
#define  BLU_LD_DATA_COMP_CTRL_ld_lut_column_addr(data)                          (0x0000001F&(data))
#define  BLU_LD_DATA_COMP_CTRL_get_ld_comp_2dlut_maxmode(data)                   ((0x00080000&(data))>>19)
#define  BLU_LD_DATA_COMP_CTRL_get_ld_data_comp_mode(data)                       ((0x00040000&(data))>>18)
#define  BLU_LD_DATA_COMP_CTRL_get_ld_lut_ax_en(data)                            ((0x00010000&(data))>>16)
#define  BLU_LD_DATA_COMP_CTRL_get_ld_lut_ax_mode(data)                          ((0x00008000&(data))>>15)
#define  BLU_LD_DATA_COMP_CTRL_get_ld_lut_adr_mode(data)                         ((0x00004000&(data))>>14)
#define  BLU_LD_DATA_COMP_CTRL_get_ld_lut_row_addr(data)                         ((0x000007C0&(data))>>6)
#define  BLU_LD_DATA_COMP_CTRL_get_ld_lut_column_addr(data)                      (0x0000001F&(data))

#define  BLU_LD_LUT_DATA                                                         0x1802CC34
#define  BLU_LD_LUT_DATA_reg_addr                                                "0xB802CC34"
#define  BLU_LD_LUT_DATA_reg                                                     0xB802CC34
#define  BLU_LD_LUT_DATA_inst_addr                                               "0x001E"
#define  set_BLU_LD_LUT_DATA_reg(data)                                           (*((volatile unsigned int*)BLU_LD_LUT_DATA_reg)=data)
#define  get_BLU_LD_LUT_DATA_reg                                                 (*((volatile unsigned int*)BLU_LD_LUT_DATA_reg))
#define  BLU_LD_LUT_DATA_ld_lut_data_shift                                       (0)
#define  BLU_LD_LUT_DATA_ld_lut_data_mask                                        (0x0FFFFFFF)
#define  BLU_LD_LUT_DATA_ld_lut_data(data)                                       (0x0FFFFFFF&(data))
#define  BLU_LD_LUT_DATA_get_ld_lut_data(data)                                   (0x0FFFFFFF&(data))

#define  BLU_LD_Spatial_Ctrl3                                                    0x1802C258
#define  BLU_LD_Spatial_Ctrl3_reg_addr                                           "0xB802C258"
#define  BLU_LD_Spatial_Ctrl3_reg                                                0xB802C258
#define  BLU_LD_Spatial_Ctrl3_inst_addr                                          "0x001F"
#define  set_BLU_LD_Spatial_Ctrl3_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl3_reg)=data)
#define  get_BLU_LD_Spatial_Ctrl3_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl3_reg))
#define  BLU_LD_Spatial_Ctrl3_ld_spatialremapadr_shift                           (24)
#define  BLU_LD_Spatial_Ctrl3_ld_spatialremaptab1_shift                          (12)
#define  BLU_LD_Spatial_Ctrl3_ld_spatialremaptab0_shift                          (0)
#define  BLU_LD_Spatial_Ctrl3_ld_spatialremapadr_mask                            (0x7F000000)
#define  BLU_LD_Spatial_Ctrl3_ld_spatialremaptab1_mask                           (0x003FF000)
#define  BLU_LD_Spatial_Ctrl3_ld_spatialremaptab0_mask                           (0x000003FF)
#define  BLU_LD_Spatial_Ctrl3_ld_spatialremapadr(data)                           (0x7F000000&((data)<<24))
#define  BLU_LD_Spatial_Ctrl3_ld_spatialremaptab1(data)                          (0x003FF000&((data)<<12))
#define  BLU_LD_Spatial_Ctrl3_ld_spatialremaptab0(data)                          (0x000003FF&(data))
#define  BLU_LD_Spatial_Ctrl3_get_ld_spatialremapadr(data)                       ((0x7F000000&(data))>>24)
#define  BLU_LD_Spatial_Ctrl3_get_ld_spatialremaptab1(data)                      ((0x003FF000&(data))>>12)
#define  BLU_LD_Spatial_Ctrl3_get_ld_spatialremaptab0(data)                      (0x000003FF&(data))

#define  BLU_LD_backlight_average_option                                         0x1802C2F0
#define  BLU_LD_backlight_average_option_reg_addr                                "0xB802C2F0"
#define  BLU_LD_backlight_average_option_reg                                     0xB802C2F0
#define  BLU_LD_backlight_average_option_inst_addr                               "0x0020"
#define  set_BLU_LD_backlight_average_option_reg(data)                           (*((volatile unsigned int*)BLU_LD_backlight_average_option_reg)=data)
#define  get_BLU_LD_backlight_average_option_reg                                 (*((volatile unsigned int*)BLU_LD_backlight_average_option_reg))
#define  BLU_LD_backlight_average_option_ld_bl_avg_shift_shift                   (0)
#define  BLU_LD_backlight_average_option_ld_bl_avg_shift_mask                    (0x000001FF)
#define  BLU_LD_backlight_average_option_ld_bl_avg_shift(data)                   (0x000001FF&(data))
#define  BLU_LD_backlight_average_option_get_ld_bl_avg_shift(data)               (0x000001FF&(data))

#define  BLU_LD_Spatial_Ctrl4                                                    0x1802C2E8
#define  BLU_LD_Spatial_Ctrl4_reg_addr                                           "0xB802C2E8"
#define  BLU_LD_Spatial_Ctrl4_reg                                                0xB802C2E8
#define  BLU_LD_Spatial_Ctrl4_inst_addr                                          "0x0021"
#define  set_BLU_LD_Spatial_Ctrl4_reg(data)                                      (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl4_reg)=data)
#define  get_BLU_LD_Spatial_Ctrl4_reg                                            (*((volatile unsigned int*)BLU_LD_Spatial_Ctrl4_reg))
#define  BLU_LD_Spatial_Ctrl4_ld_spatialremaptab_initial3_shift                  (20)
#define  BLU_LD_Spatial_Ctrl4_ld_spatialremaptab_initial2_shift                  (10)
#define  BLU_LD_Spatial_Ctrl4_ld_spatialremaptab_initial_shift                   (0)
#define  BLU_LD_Spatial_Ctrl4_ld_spatialremaptab_initial3_mask                   (0x3FF00000)
#define  BLU_LD_Spatial_Ctrl4_ld_spatialremaptab_initial2_mask                   (0x000FFC00)
#define  BLU_LD_Spatial_Ctrl4_ld_spatialremaptab_initial_mask                    (0x000003FF)
#define  BLU_LD_Spatial_Ctrl4_ld_spatialremaptab_initial3(data)                  (0x3FF00000&((data)<<20))
#define  BLU_LD_Spatial_Ctrl4_ld_spatialremaptab_initial2(data)                  (0x000FFC00&((data)<<10))
#define  BLU_LD_Spatial_Ctrl4_ld_spatialremaptab_initial(data)                   (0x000003FF&(data))
#define  BLU_LD_Spatial_Ctrl4_get_ld_spatialremaptab_initial3(data)              ((0x3FF00000&(data))>>20)
#define  BLU_LD_Spatial_Ctrl4_get_ld_spatialremaptab_initial2(data)              ((0x000FFC00&(data))>>10)
#define  BLU_LD_Spatial_Ctrl4_get_ld_spatialremaptab_initial(data)               (0x000003FF&(data))

#define  BLU_LD_APL_read_max_1                                                   0x1802CC50
#define  BLU_LD_APL_read_max_1_reg_addr                                          "0xB802CC50"
#define  BLU_LD_APL_read_max_1_reg                                               0xB802CC50
#define  BLU_LD_APL_read_max_1_inst_addr                                         "0x0022"
#define  set_BLU_LD_APL_read_max_1_reg(data)                                     (*((volatile unsigned int*)BLU_LD_APL_read_max_1_reg)=data)
#define  get_BLU_LD_APL_read_max_1_reg                                           (*((volatile unsigned int*)BLU_LD_APL_read_max_1_reg))
#define  BLU_LD_APL_read_max_1_ld_aplmax_conti_shift                             (1)
#define  BLU_LD_APL_read_max_1_ld_aplmax_start_shift                             (0)
#define  BLU_LD_APL_read_max_1_ld_aplmax_conti_mask                              (0x00000002)
#define  BLU_LD_APL_read_max_1_ld_aplmax_start_mask                              (0x00000001)
#define  BLU_LD_APL_read_max_1_ld_aplmax_conti(data)                             (0x00000002&((data)<<1))
#define  BLU_LD_APL_read_max_1_ld_aplmax_start(data)                             (0x00000001&(data))
#define  BLU_LD_APL_read_max_1_get_ld_aplmax_conti(data)                         ((0x00000002&(data))>>1)
#define  BLU_LD_APL_read_max_1_get_ld_aplmax_start(data)                         (0x00000001&(data))

#define  BLU_LD_APL_read_max_2                                                   0x1802CC54
#define  BLU_LD_APL_read_max_2_reg_addr                                          "0xB802CC54"
#define  BLU_LD_APL_read_max_2_reg                                               0xB802CC54
#define  BLU_LD_APL_read_max_2_inst_addr                                         "0x0023"
#define  set_BLU_LD_APL_read_max_2_reg(data)                                     (*((volatile unsigned int*)BLU_LD_APL_read_max_2_reg)=data)
#define  get_BLU_LD_APL_read_max_2_reg                                           (*((volatile unsigned int*)BLU_LD_APL_read_max_2_reg))
#define  BLU_LD_APL_read_max_2_ld_aplmax_addr_shift                              (16)
#define  BLU_LD_APL_read_max_2_ld_aplmax_access_en_shift                         (0)
#define  BLU_LD_APL_read_max_2_ld_aplmax_addr_mask                               (0x01FF0000)
#define  BLU_LD_APL_read_max_2_ld_aplmax_access_en_mask                          (0x00000001)
#define  BLU_LD_APL_read_max_2_ld_aplmax_addr(data)                              (0x01FF0000&((data)<<16))
#define  BLU_LD_APL_read_max_2_ld_aplmax_access_en(data)                         (0x00000001&(data))
#define  BLU_LD_APL_read_max_2_get_ld_aplmax_addr(data)                          ((0x01FF0000&(data))>>16)
#define  BLU_LD_APL_read_max_2_get_ld_aplmax_access_en(data)                     (0x00000001&(data))

#define  BLU_LD_APL_read_max_3                                                   0x1802CC58
#define  BLU_LD_APL_read_max_3_reg_addr                                          "0xB802CC58"
#define  BLU_LD_APL_read_max_3_reg                                               0xB802CC58
#define  BLU_LD_APL_read_max_3_inst_addr                                         "0x0024"
#define  set_BLU_LD_APL_read_max_3_reg(data)                                     (*((volatile unsigned int*)BLU_LD_APL_read_max_3_reg)=data)
#define  get_BLU_LD_APL_read_max_3_reg                                           (*((volatile unsigned int*)BLU_LD_APL_read_max_3_reg))
#define  BLU_LD_APL_read_max_3_ld_aplmaxaccess_data_shift                        (0)
#define  BLU_LD_APL_read_max_3_ld_aplmaxaccess_data_mask                         (0x3FFFFFFF)
#define  BLU_LD_APL_read_max_3_ld_aplmaxaccess_data(data)                        (0x3FFFFFFF&(data))
#define  BLU_LD_APL_read_max_3_get_ld_aplmaxaccess_data(data)                    (0x3FFFFFFF&(data))

#define  BLU_LD_APL_read_ave_1                                                   0x1802CC60
#define  BLU_LD_APL_read_ave_1_reg_addr                                          "0xB802CC60"
#define  BLU_LD_APL_read_ave_1_reg                                               0xB802CC60
#define  BLU_LD_APL_read_ave_1_inst_addr                                         "0x0025"
#define  set_BLU_LD_APL_read_ave_1_reg(data)                                     (*((volatile unsigned int*)BLU_LD_APL_read_ave_1_reg)=data)
#define  get_BLU_LD_APL_read_ave_1_reg                                           (*((volatile unsigned int*)BLU_LD_APL_read_ave_1_reg))
#define  BLU_LD_APL_read_ave_1_ld_aplave_conti_shift                             (1)
#define  BLU_LD_APL_read_ave_1_ld_aplave_start_shift                             (0)
#define  BLU_LD_APL_read_ave_1_ld_aplave_conti_mask                              (0x00000002)
#define  BLU_LD_APL_read_ave_1_ld_aplave_start_mask                              (0x00000001)
#define  BLU_LD_APL_read_ave_1_ld_aplave_conti(data)                             (0x00000002&((data)<<1))
#define  BLU_LD_APL_read_ave_1_ld_aplave_start(data)                             (0x00000001&(data))
#define  BLU_LD_APL_read_ave_1_get_ld_aplave_conti(data)                         ((0x00000002&(data))>>1)
#define  BLU_LD_APL_read_ave_1_get_ld_aplave_start(data)                         (0x00000001&(data))

#define  BLU_LD_APL_read_ave_2                                                   0x1802CC64
#define  BLU_LD_APL_read_ave_2_reg_addr                                          "0xB802CC64"
#define  BLU_LD_APL_read_ave_2_reg                                               0xB802CC64
#define  BLU_LD_APL_read_ave_2_inst_addr                                         "0x0026"
#define  set_BLU_LD_APL_read_ave_2_reg(data)                                     (*((volatile unsigned int*)BLU_LD_APL_read_ave_2_reg)=data)
#define  get_BLU_LD_APL_read_ave_2_reg                                           (*((volatile unsigned int*)BLU_LD_APL_read_ave_2_reg))
#define  BLU_LD_APL_read_ave_2_ld_aplave_addr_shift                              (16)
#define  BLU_LD_APL_read_ave_2_ld_aplave_access_en_shift                         (0)
#define  BLU_LD_APL_read_ave_2_ld_aplave_addr_mask                               (0x01FF0000)
#define  BLU_LD_APL_read_ave_2_ld_aplave_access_en_mask                          (0x00000001)
#define  BLU_LD_APL_read_ave_2_ld_aplave_addr(data)                              (0x01FF0000&((data)<<16))
#define  BLU_LD_APL_read_ave_2_ld_aplave_access_en(data)                         (0x00000001&(data))
#define  BLU_LD_APL_read_ave_2_get_ld_aplave_addr(data)                          ((0x01FF0000&(data))>>16)
#define  BLU_LD_APL_read_ave_2_get_ld_aplave_access_en(data)                     (0x00000001&(data))

#define  BLU_LD_APL_read_ave_3                                                   0x1802CC68
#define  BLU_LD_APL_read_ave_3_reg_addr                                          "0xB802CC68"
#define  BLU_LD_APL_read_ave_3_reg                                               0xB802CC68
#define  BLU_LD_APL_read_ave_3_inst_addr                                         "0x0027"
#define  set_BLU_LD_APL_read_ave_3_reg(data)                                     (*((volatile unsigned int*)BLU_LD_APL_read_ave_3_reg)=data)
#define  get_BLU_LD_APL_read_ave_3_reg                                           (*((volatile unsigned int*)BLU_LD_APL_read_ave_3_reg))
#define  BLU_LD_APL_read_ave_3_ld_aplaveaccess_data_shift                        (0)
#define  BLU_LD_APL_read_ave_3_ld_aplaveaccess_data_mask                         (0x3FFFFFFF)
#define  BLU_LD_APL_read_ave_3_ld_aplaveaccess_data(data)                        (0x3FFFFFFF&(data))
#define  BLU_LD_APL_read_ave_3_get_ld_aplaveaccess_data(data)                    (0x3FFFFFFF&(data))

#define  BLU_LD_Temporal_Ctrl1                                                   0x1802C25C
#define  BLU_LD_Temporal_Ctrl1_reg_addr                                          "0xB802C25C"
#define  BLU_LD_Temporal_Ctrl1_reg                                               0xB802C25C
#define  BLU_LD_Temporal_Ctrl1_inst_addr                                         "0x0028"
#define  set_BLU_LD_Temporal_Ctrl1_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Temporal_Ctrl1_reg)=data)
#define  get_BLU_LD_Temporal_Ctrl1_reg                                           (*((volatile unsigned int*)BLU_LD_Temporal_Ctrl1_reg))
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_pos0thd_shift                              (24)
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_pos1thd_shift                              (16)
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_posmingain_shift                           (8)
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_posmaxgain_shift                           (0)
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_pos0thd_mask                               (0xFF000000)
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_pos1thd_mask                               (0x00FF0000)
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_posmingain_mask                            (0x00001F00)
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_posmaxgain_mask                            (0x0000001F)
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_pos0thd(data)                              (0xFF000000&((data)<<24))
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_pos1thd(data)                              (0x00FF0000&((data)<<16))
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_posmingain(data)                           (0x00001F00&((data)<<8))
#define  BLU_LD_Temporal_Ctrl1_ld_tmp_posmaxgain(data)                           (0x0000001F&(data))
#define  BLU_LD_Temporal_Ctrl1_get_ld_tmp_pos0thd(data)                          ((0xFF000000&(data))>>24)
#define  BLU_LD_Temporal_Ctrl1_get_ld_tmp_pos1thd(data)                          ((0x00FF0000&(data))>>16)
#define  BLU_LD_Temporal_Ctrl1_get_ld_tmp_posmingain(data)                       ((0x00001F00&(data))>>8)
#define  BLU_LD_Temporal_Ctrl1_get_ld_tmp_posmaxgain(data)                       (0x0000001F&(data))

#define  BLU_LD_Temporal_Ctrl2                                                   0x1802C260
#define  BLU_LD_Temporal_Ctrl2_reg_addr                                          "0xB802C260"
#define  BLU_LD_Temporal_Ctrl2_reg                                               0xB802C260
#define  BLU_LD_Temporal_Ctrl2_inst_addr                                         "0x0029"
#define  set_BLU_LD_Temporal_Ctrl2_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Temporal_Ctrl2_reg)=data)
#define  get_BLU_LD_Temporal_Ctrl2_reg                                           (*((volatile unsigned int*)BLU_LD_Temporal_Ctrl2_reg))
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_neg0thd_shift                              (24)
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_neg1thd_shift                              (16)
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_negmingain_shift                           (8)
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_negmaxgain_shift                           (0)
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_neg0thd_mask                               (0xFF000000)
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_neg1thd_mask                               (0x00FF0000)
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_negmingain_mask                            (0x00001F00)
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_negmaxgain_mask                            (0x0000001F)
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_neg0thd(data)                              (0xFF000000&((data)<<24))
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_neg1thd(data)                              (0x00FF0000&((data)<<16))
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_negmingain(data)                           (0x00001F00&((data)<<8))
#define  BLU_LD_Temporal_Ctrl2_ld_tmp_negmaxgain(data)                           (0x0000001F&(data))
#define  BLU_LD_Temporal_Ctrl2_get_ld_tmp_neg0thd(data)                          ((0xFF000000&(data))>>24)
#define  BLU_LD_Temporal_Ctrl2_get_ld_tmp_neg1thd(data)                          ((0x00FF0000&(data))>>16)
#define  BLU_LD_Temporal_Ctrl2_get_ld_tmp_negmingain(data)                       ((0x00001F00&(data))>>8)
#define  BLU_LD_Temporal_Ctrl2_get_ld_tmp_negmaxgain(data)                       (0x0000001F&(data))

#define  BLU_LD_Temporal_Ctrl3                                                   0x1802C264
#define  BLU_LD_Temporal_Ctrl3_reg_addr                                          "0xB802C264"
#define  BLU_LD_Temporal_Ctrl3_reg                                               0xB802C264
#define  BLU_LD_Temporal_Ctrl3_inst_addr                                         "0x002A"
#define  set_BLU_LD_Temporal_Ctrl3_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Temporal_Ctrl3_reg)=data)
#define  get_BLU_LD_Temporal_Ctrl3_reg                                           (*((volatile unsigned int*)BLU_LD_Temporal_Ctrl3_reg))
#define  BLU_LD_Temporal_Ctrl3_ld_tmp_maxdiff_shift                              (16)
#define  BLU_LD_Temporal_Ctrl3_ld_tmp_scenechangegain1_shift                     (8)
#define  BLU_LD_Temporal_Ctrl3_ld_tmp_maxdiff_mask                               (0x00FF0000)
#define  BLU_LD_Temporal_Ctrl3_ld_tmp_scenechangegain1_mask                      (0x00001F00)
#define  BLU_LD_Temporal_Ctrl3_ld_tmp_maxdiff(data)                              (0x00FF0000&((data)<<16))
#define  BLU_LD_Temporal_Ctrl3_ld_tmp_scenechangegain1(data)                     (0x00001F00&((data)<<8))
#define  BLU_LD_Temporal_Ctrl3_get_ld_tmp_maxdiff(data)                          ((0x00FF0000&(data))>>16)
#define  BLU_LD_Temporal_Ctrl3_get_ld_tmp_scenechangegain1(data)                 ((0x00001F00&(data))>>8)

#define  BLU_LD_Backlight_Ctrl1                                                  0x1802C268
#define  BLU_LD_Backlight_Ctrl1_reg_addr                                         "0xB802C268"
#define  BLU_LD_Backlight_Ctrl1_reg                                              0xB802C268
#define  BLU_LD_Backlight_Ctrl1_inst_addr                                        "0x002B"
#define  set_BLU_LD_Backlight_Ctrl1_reg(data)                                    (*((volatile unsigned int*)BLU_LD_Backlight_Ctrl1_reg)=data)
#define  get_BLU_LD_Backlight_Ctrl1_reg                                          (*((volatile unsigned int*)BLU_LD_Backlight_Ctrl1_reg))
#define  BLU_LD_Backlight_Ctrl1_ld_blu_wr_num_shift                              (25)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_spitotal_shift                            (16)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_spien_shift                               (9)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_nodim_shift                               (8)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_usergain_shift                            (0)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_wr_num_mask                               (0xFE000000)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_spitotal_mask                             (0x01FF0000)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_spien_mask                                (0x00000200)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_nodim_mask                                (0x00000100)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_usergain_mask                             (0x000000FF)
#define  BLU_LD_Backlight_Ctrl1_ld_blu_wr_num(data)                              (0xFE000000&((data)<<25))
#define  BLU_LD_Backlight_Ctrl1_ld_blu_spitotal(data)                            (0x01FF0000&((data)<<16))
#define  BLU_LD_Backlight_Ctrl1_ld_blu_spien(data)                               (0x00000200&((data)<<9))
#define  BLU_LD_Backlight_Ctrl1_ld_blu_nodim(data)                               (0x00000100&((data)<<8))
#define  BLU_LD_Backlight_Ctrl1_ld_blu_usergain(data)                            (0x000000FF&(data))
#define  BLU_LD_Backlight_Ctrl1_get_ld_blu_wr_num(data)                          ((0xFE000000&(data))>>25)
#define  BLU_LD_Backlight_Ctrl1_get_ld_blu_spitotal(data)                        ((0x01FF0000&(data))>>16)
#define  BLU_LD_Backlight_Ctrl1_get_ld_blu_spien(data)                           ((0x00000200&(data))>>9)
#define  BLU_LD_Backlight_Ctrl1_get_ld_blu_nodim(data)                           ((0x00000100&(data))>>8)
#define  BLU_LD_Backlight_Ctrl1_get_ld_blu_usergain(data)                        (0x000000FF&(data))

#define  BLU_LD_DataComp_Ctrl1                                                   0x1802C26C
#define  BLU_LD_DataComp_Ctrl1_reg_addr                                          "0xB802C26C"
#define  BLU_LD_DataComp_Ctrl1_reg                                               0xB802C26C
#define  BLU_LD_DataComp_Ctrl1_inst_addr                                         "0x002C"
#define  set_BLU_LD_DataComp_Ctrl1_reg(data)                                     (*((volatile unsigned int*)BLU_LD_DataComp_Ctrl1_reg)=data)
#define  get_BLU_LD_DataComp_Ctrl1_reg                                           (*((volatile unsigned int*)BLU_LD_DataComp_Ctrl1_reg))
#define  BLU_LD_DataComp_Ctrl1_ld_comp_satrange_shift                            (24)
#define  BLU_LD_DataComp_Ctrl1_ld_comp_softmax_shift                             (16)
#define  BLU_LD_DataComp_Ctrl1_ld_comp_minlimit_shift                            (8)
#define  BLU_LD_DataComp_Ctrl1_ld_softcomp_gain_shift                            (4)
#define  BLU_LD_DataComp_Ctrl1_ld_comp_maxmode_shift                             (2)
#define  BLU_LD_DataComp_Ctrl1_ld_debugmode_shift                                (0)
#define  BLU_LD_DataComp_Ctrl1_ld_comp_satrange_mask                             (0xFF000000)
#define  BLU_LD_DataComp_Ctrl1_ld_comp_softmax_mask                              (0x00FF0000)
#define  BLU_LD_DataComp_Ctrl1_ld_comp_minlimit_mask                             (0x0000FF00)
#define  BLU_LD_DataComp_Ctrl1_ld_softcomp_gain_mask                             (0x000000F0)
#define  BLU_LD_DataComp_Ctrl1_ld_comp_maxmode_mask                              (0x0000000C)
#define  BLU_LD_DataComp_Ctrl1_ld_debugmode_mask                                 (0x00000003)
#define  BLU_LD_DataComp_Ctrl1_ld_comp_satrange(data)                            (0xFF000000&((data)<<24))
#define  BLU_LD_DataComp_Ctrl1_ld_comp_softmax(data)                             (0x00FF0000&((data)<<16))
#define  BLU_LD_DataComp_Ctrl1_ld_comp_minlimit(data)                            (0x0000FF00&((data)<<8))
#define  BLU_LD_DataComp_Ctrl1_ld_softcomp_gain(data)                            (0x000000F0&((data)<<4))
#define  BLU_LD_DataComp_Ctrl1_ld_comp_maxmode(data)                             (0x0000000C&((data)<<2))
#define  BLU_LD_DataComp_Ctrl1_ld_debugmode(data)                                (0x00000003&(data))
#define  BLU_LD_DataComp_Ctrl1_get_ld_comp_satrange(data)                        ((0xFF000000&(data))>>24)
#define  BLU_LD_DataComp_Ctrl1_get_ld_comp_softmax(data)                         ((0x00FF0000&(data))>>16)
#define  BLU_LD_DataComp_Ctrl1_get_ld_comp_minlimit(data)                        ((0x0000FF00&(data))>>8)
#define  BLU_LD_DataComp_Ctrl1_get_ld_softcomp_gain(data)                        ((0x000000F0&(data))>>4)
#define  BLU_LD_DataComp_Ctrl1_get_ld_comp_maxmode(data)                         ((0x0000000C&(data))>>2)
#define  BLU_LD_DataComp_Ctrl1_get_ld_debugmode(data)                            (0x00000003&(data))

#define  BLU_LD_DataComp_Ctrl2                                                   0x1802C270
#define  BLU_LD_DataComp_Ctrl2_reg_addr                                          "0xB802C270"
#define  BLU_LD_DataComp_Ctrl2_reg                                               0xB802C270
#define  BLU_LD_DataComp_Ctrl2_inst_addr                                         "0x002D"
#define  set_BLU_LD_DataComp_Ctrl2_reg(data)                                     (*((volatile unsigned int*)BLU_LD_DataComp_Ctrl2_reg)=data)
#define  get_BLU_LD_DataComp_Ctrl2_reg                                           (*((volatile unsigned int*)BLU_LD_DataComp_Ctrl2_reg))
#define  BLU_LD_DataComp_Ctrl2_dummy_31_20_shift                                 (20)
#define  BLU_LD_DataComp_Ctrl2_ld_comp_inv_shift_shift                           (17)
#define  BLU_LD_DataComp_Ctrl2_ld_comp_inv_mode_shift                            (16)
#define  BLU_LD_DataComp_Ctrl2_ld_srcgainsel_shift                               (0)
#define  BLU_LD_DataComp_Ctrl2_dummy_31_20_mask                                  (0xFFF00000)
#define  BLU_LD_DataComp_Ctrl2_ld_comp_inv_shift_mask                            (0x000E0000)
#define  BLU_LD_DataComp_Ctrl2_ld_comp_inv_mode_mask                             (0x00010000)
#define  BLU_LD_DataComp_Ctrl2_ld_srcgainsel_mask                                (0x00000007)
#define  BLU_LD_DataComp_Ctrl2_dummy_31_20(data)                                 (0xFFF00000&((data)<<20))
#define  BLU_LD_DataComp_Ctrl2_ld_comp_inv_shift(data)                           (0x000E0000&((data)<<17))
#define  BLU_LD_DataComp_Ctrl2_ld_comp_inv_mode(data)                            (0x00010000&((data)<<16))
#define  BLU_LD_DataComp_Ctrl2_ld_srcgainsel(data)                               (0x00000007&(data))
#define  BLU_LD_DataComp_Ctrl2_get_dummy_31_20(data)                             ((0xFFF00000&(data))>>20)
#define  BLU_LD_DataComp_Ctrl2_get_ld_comp_inv_shift(data)                       ((0x000E0000&(data))>>17)
#define  BLU_LD_DataComp_Ctrl2_get_ld_comp_inv_mode(data)                        ((0x00010000&(data))>>16)
#define  BLU_LD_DataComp_Ctrl2_get_ld_srcgainsel(data)                           (0x00000007&(data))

#define  BLU_LD_Inter_HCtrl1                                                     0x1802C274
#define  BLU_LD_Inter_HCtrl1_reg_addr                                            "0xB802C274"
#define  BLU_LD_Inter_HCtrl1_reg                                                 0xB802C274
#define  BLU_LD_Inter_HCtrl1_inst_addr                                           "0x002E"
#define  set_BLU_LD_Inter_HCtrl1_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Inter_HCtrl1_reg)=data)
#define  get_BLU_LD_Inter_HCtrl1_reg                                             (*((volatile unsigned int*)BLU_LD_Inter_HCtrl1_reg))
#define  BLU_LD_Inter_HCtrl1_ld_tab_hsize_shift                                  (24)
#define  BLU_LD_Inter_HCtrl1_ld_hfactor_shift                                    (0)
#define  BLU_LD_Inter_HCtrl1_ld_tab_hsize_mask                                   (0xFF000000)
#define  BLU_LD_Inter_HCtrl1_ld_hfactor_mask                                     (0x000FFFFF)
#define  BLU_LD_Inter_HCtrl1_ld_tab_hsize(data)                                  (0xFF000000&((data)<<24))
#define  BLU_LD_Inter_HCtrl1_ld_hfactor(data)                                    (0x000FFFFF&(data))
#define  BLU_LD_Inter_HCtrl1_get_ld_tab_hsize(data)                              ((0xFF000000&(data))>>24)
#define  BLU_LD_Inter_HCtrl1_get_ld_hfactor(data)                                (0x000FFFFF&(data))

#define  BLU_LD_Inter_HCtrl2                                                     0x1802C278
#define  BLU_LD_Inter_HCtrl2_reg_addr                                            "0xB802C278"
#define  BLU_LD_Inter_HCtrl2_reg                                                 0xB802C278
#define  BLU_LD_Inter_HCtrl2_inst_addr                                           "0x002F"
#define  set_BLU_LD_Inter_HCtrl2_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Inter_HCtrl2_reg)=data)
#define  get_BLU_LD_Inter_HCtrl2_reg                                             (*((volatile unsigned int*)BLU_LD_Inter_HCtrl2_reg))
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase3_right_shift                          (24)
#define  BLU_LD_Inter_HCtrl2_ld_hboundary_shift                                  (20)
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase1_shift                                (16)
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase2_shift                                (8)
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase3_left_shift                           (0)
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase3_right_mask                           (0xFF000000)
#define  BLU_LD_Inter_HCtrl2_ld_hboundary_mask                                   (0x00100000)
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase1_mask                                 (0x00010000)
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase2_mask                                 (0x0000FF00)
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase3_left_mask                            (0x000000FF)
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase3_right(data)                          (0xFF000000&((data)<<24))
#define  BLU_LD_Inter_HCtrl2_ld_hboundary(data)                                  (0x00100000&((data)<<20))
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase1(data)                                (0x00010000&((data)<<16))
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase2(data)                                (0x0000FF00&((data)<<8))
#define  BLU_LD_Inter_HCtrl2_ld_hinitphase3_left(data)                           (0x000000FF&(data))
#define  BLU_LD_Inter_HCtrl2_get_ld_hinitphase3_right(data)                      ((0xFF000000&(data))>>24)
#define  BLU_LD_Inter_HCtrl2_get_ld_hboundary(data)                              ((0x00100000&(data))>>20)
#define  BLU_LD_Inter_HCtrl2_get_ld_hinitphase1(data)                            ((0x00010000&(data))>>16)
#define  BLU_LD_Inter_HCtrl2_get_ld_hinitphase2(data)                            ((0x0000FF00&(data))>>8)
#define  BLU_LD_Inter_HCtrl2_get_ld_hinitphase3_left(data)                       (0x000000FF&(data))

#define  BLU_LD_Inter_VCtrl1                                                     0x1802C27C
#define  BLU_LD_Inter_VCtrl1_reg_addr                                            "0xB802C27C"
#define  BLU_LD_Inter_VCtrl1_reg                                                 0xB802C27C
#define  BLU_LD_Inter_VCtrl1_inst_addr                                           "0x0030"
#define  set_BLU_LD_Inter_VCtrl1_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Inter_VCtrl1_reg)=data)
#define  get_BLU_LD_Inter_VCtrl1_reg                                             (*((volatile unsigned int*)BLU_LD_Inter_VCtrl1_reg))
#define  BLU_LD_Inter_VCtrl1_ld_tab_vsize_shift                                  (24)
#define  BLU_LD_Inter_VCtrl1_ld_vfactor_shift                                    (0)
#define  BLU_LD_Inter_VCtrl1_ld_tab_vsize_mask                                   (0xFF000000)
#define  BLU_LD_Inter_VCtrl1_ld_vfactor_mask                                     (0x000FFFFF)
#define  BLU_LD_Inter_VCtrl1_ld_tab_vsize(data)                                  (0xFF000000&((data)<<24))
#define  BLU_LD_Inter_VCtrl1_ld_vfactor(data)                                    (0x000FFFFF&(data))
#define  BLU_LD_Inter_VCtrl1_get_ld_tab_vsize(data)                              ((0xFF000000&(data))>>24)
#define  BLU_LD_Inter_VCtrl1_get_ld_vfactor(data)                                (0x000FFFFF&(data))

#define  BLU_LD_Inter_VCtrl2                                                     0x1802C280
#define  BLU_LD_Inter_VCtrl2_reg_addr                                            "0xB802C280"
#define  BLU_LD_Inter_VCtrl2_reg                                                 0xB802C280
#define  BLU_LD_Inter_VCtrl2_inst_addr                                           "0x0031"
#define  set_BLU_LD_Inter_VCtrl2_reg(data)                                       (*((volatile unsigned int*)BLU_LD_Inter_VCtrl2_reg)=data)
#define  get_BLU_LD_Inter_VCtrl2_reg                                             (*((volatile unsigned int*)BLU_LD_Inter_VCtrl2_reg))
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase3_right_shift                          (24)
#define  BLU_LD_Inter_VCtrl2_ld_vboundary_shift                                  (20)
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase1_shift                                (16)
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase2_shift                                (8)
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase3_left_shift                           (0)
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase3_right_mask                           (0xFF000000)
#define  BLU_LD_Inter_VCtrl2_ld_vboundary_mask                                   (0x00100000)
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase1_mask                                 (0x00010000)
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase2_mask                                 (0x0000FF00)
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase3_left_mask                            (0x000000FF)
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase3_right(data)                          (0xFF000000&((data)<<24))
#define  BLU_LD_Inter_VCtrl2_ld_vboundary(data)                                  (0x00100000&((data)<<20))
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase1(data)                                (0x00010000&((data)<<16))
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase2(data)                                (0x0000FF00&((data)<<8))
#define  BLU_LD_Inter_VCtrl2_ld_vinitphase3_left(data)                           (0x000000FF&(data))
#define  BLU_LD_Inter_VCtrl2_get_ld_vinitphase3_right(data)                      ((0xFF000000&(data))>>24)
#define  BLU_LD_Inter_VCtrl2_get_ld_vboundary(data)                              ((0x00100000&(data))>>20)
#define  BLU_LD_Inter_VCtrl2_get_ld_vinitphase1(data)                            ((0x00010000&(data))>>16)
#define  BLU_LD_Inter_VCtrl2_get_ld_vinitphase2(data)                            ((0x0000FF00&(data))>>8)
#define  BLU_LD_Inter_VCtrl2_get_ld_vinitphase3_left(data)                       (0x000000FF&(data))

#define  BLU_LD_VTAB_AP                                                          0x1802C284
#define  BLU_LD_VTAB_AP_reg_addr                                                 "0xB802C284"
#define  BLU_LD_VTAB_AP_reg                                                      0xB802C284
#define  BLU_LD_VTAB_AP_inst_addr                                                "0x0032"
#define  set_BLU_LD_VTAB_AP_reg(data)                                            (*((volatile unsigned int*)BLU_LD_VTAB_AP_reg)=data)
#define  get_BLU_LD_VTAB_AP_reg                                                  (*((volatile unsigned int*)BLU_LD_VTAB_AP_reg))
#define  BLU_LD_VTAB_AP_dummy_31_9_shift                                         (9)
#define  BLU_LD_VTAB_AP_ld_vtab_adr_shift                                        (0)
#define  BLU_LD_VTAB_AP_dummy_31_9_mask                                          (0xFFFFFE00)
#define  BLU_LD_VTAB_AP_ld_vtab_adr_mask                                         (0x000001FF)
#define  BLU_LD_VTAB_AP_dummy_31_9(data)                                         (0xFFFFFE00&((data)<<9))
#define  BLU_LD_VTAB_AP_ld_vtab_adr(data)                                        (0x000001FF&(data))
#define  BLU_LD_VTAB_AP_get_dummy_31_9(data)                                     ((0xFFFFFE00&(data))>>9)
#define  BLU_LD_VTAB_AP_get_ld_vtab_adr(data)                                    (0x000001FF&(data))

#define  BLU_LD_VTAB_DP                                                          0x1802C288
#define  BLU_LD_VTAB_DP_reg_addr                                                 "0xB802C288"
#define  BLU_LD_VTAB_DP_reg                                                      0xB802C288
#define  BLU_LD_VTAB_DP_inst_addr                                                "0x0033"
#define  set_BLU_LD_VTAB_DP_reg(data)                                            (*((volatile unsigned int*)BLU_LD_VTAB_DP_reg)=data)
#define  get_BLU_LD_VTAB_DP_reg                                                  (*((volatile unsigned int*)BLU_LD_VTAB_DP_reg))
#define  BLU_LD_VTAB_DP_dummy_31_26_shift                                        (26)
#define  BLU_LD_VTAB_DP_ld_vtab_dat_msb_shift                                    (16)
#define  BLU_LD_VTAB_DP_dummy_15_10_shift                                        (10)
#define  BLU_LD_VTAB_DP_ld_vtab_dat_lsb_shift                                    (0)
#define  BLU_LD_VTAB_DP_dummy_31_26_mask                                         (0xFC000000)
#define  BLU_LD_VTAB_DP_ld_vtab_dat_msb_mask                                     (0x03FF0000)
#define  BLU_LD_VTAB_DP_dummy_15_10_mask                                         (0x0000FC00)
#define  BLU_LD_VTAB_DP_ld_vtab_dat_lsb_mask                                     (0x000003FF)
#define  BLU_LD_VTAB_DP_dummy_31_26(data)                                        (0xFC000000&((data)<<26))
#define  BLU_LD_VTAB_DP_ld_vtab_dat_msb(data)                                    (0x03FF0000&((data)<<16))
#define  BLU_LD_VTAB_DP_dummy_15_10(data)                                        (0x0000FC00&((data)<<10))
#define  BLU_LD_VTAB_DP_ld_vtab_dat_lsb(data)                                    (0x000003FF&(data))
#define  BLU_LD_VTAB_DP_get_dummy_31_26(data)                                    ((0xFC000000&(data))>>26)
#define  BLU_LD_VTAB_DP_get_ld_vtab_dat_msb(data)                                ((0x03FF0000&(data))>>16)
#define  BLU_LD_VTAB_DP_get_dummy_15_10(data)                                    ((0x0000FC00&(data))>>10)
#define  BLU_LD_VTAB_DP_get_ld_vtab_dat_lsb(data)                                (0x000003FF&(data))

#define  BLU_LD_HTAB_AP                                                          0x1802C28C
#define  BLU_LD_HTAB_AP_reg_addr                                                 "0xB802C28C"
#define  BLU_LD_HTAB_AP_reg                                                      0xB802C28C
#define  BLU_LD_HTAB_AP_inst_addr                                                "0x0034"
#define  set_BLU_LD_HTAB_AP_reg(data)                                            (*((volatile unsigned int*)BLU_LD_HTAB_AP_reg)=data)
#define  get_BLU_LD_HTAB_AP_reg                                                  (*((volatile unsigned int*)BLU_LD_HTAB_AP_reg))
#define  BLU_LD_HTAB_AP_dummy_31_9_shift                                         (9)
#define  BLU_LD_HTAB_AP_ld_htab_adr_shift                                        (0)
#define  BLU_LD_HTAB_AP_dummy_31_9_mask                                          (0xFFFFFE00)
#define  BLU_LD_HTAB_AP_ld_htab_adr_mask                                         (0x000001FF)
#define  BLU_LD_HTAB_AP_dummy_31_9(data)                                         (0xFFFFFE00&((data)<<9))
#define  BLU_LD_HTAB_AP_ld_htab_adr(data)                                        (0x000001FF&(data))
#define  BLU_LD_HTAB_AP_get_dummy_31_9(data)                                     ((0xFFFFFE00&(data))>>9)
#define  BLU_LD_HTAB_AP_get_ld_htab_adr(data)                                    (0x000001FF&(data))

#define  BLU_LD_HTAB_DP                                                          0x1802C290
#define  BLU_LD_HTAB_DP_reg_addr                                                 "0xB802C290"
#define  BLU_LD_HTAB_DP_reg                                                      0xB802C290
#define  BLU_LD_HTAB_DP_inst_addr                                                "0x0035"
#define  set_BLU_LD_HTAB_DP_reg(data)                                            (*((volatile unsigned int*)BLU_LD_HTAB_DP_reg)=data)
#define  get_BLU_LD_HTAB_DP_reg                                                  (*((volatile unsigned int*)BLU_LD_HTAB_DP_reg))
#define  BLU_LD_HTAB_DP_dummy_31_26_shift                                        (26)
#define  BLU_LD_HTAB_DP_ld_htab_dat_msb_shift                                    (16)
#define  BLU_LD_HTAB_DP_dummy_15_10_shift                                        (10)
#define  BLU_LD_HTAB_DP_ld_htab_dat_lsb_shift                                    (0)
#define  BLU_LD_HTAB_DP_dummy_31_26_mask                                         (0xFC000000)
#define  BLU_LD_HTAB_DP_ld_htab_dat_msb_mask                                     (0x03FF0000)
#define  BLU_LD_HTAB_DP_dummy_15_10_mask                                         (0x0000FC00)
#define  BLU_LD_HTAB_DP_ld_htab_dat_lsb_mask                                     (0x000003FF)
#define  BLU_LD_HTAB_DP_dummy_31_26(data)                                        (0xFC000000&((data)<<26))
#define  BLU_LD_HTAB_DP_ld_htab_dat_msb(data)                                    (0x03FF0000&((data)<<16))
#define  BLU_LD_HTAB_DP_dummy_15_10(data)                                        (0x0000FC00&((data)<<10))
#define  BLU_LD_HTAB_DP_ld_htab_dat_lsb(data)                                    (0x000003FF&(data))
#define  BLU_LD_HTAB_DP_get_dummy_31_26(data)                                    ((0xFC000000&(data))>>26)
#define  BLU_LD_HTAB_DP_get_ld_htab_dat_msb(data)                                ((0x03FF0000&(data))>>16)
#define  BLU_LD_HTAB_DP_get_dummy_15_10(data)                                    ((0x0000FC00&(data))>>10)
#define  BLU_LD_HTAB_DP_get_ld_htab_dat_lsb(data)                                (0x000003FF&(data))

#define  BLU_LD_SRAM_CTRL                                                        0x1802C294
#define  BLU_LD_SRAM_CTRL_reg_addr                                               "0xB802C294"
#define  BLU_LD_SRAM_CTRL_reg                                                    0xB802C294
#define  BLU_LD_SRAM_CTRL_inst_addr                                              "0x0036"
#define  set_BLU_LD_SRAM_CTRL_reg(data)                                          (*((volatile unsigned int*)BLU_LD_SRAM_CTRL_reg)=data)
#define  get_BLU_LD_SRAM_CTRL_reg                                                (*((volatile unsigned int*)BLU_LD_SRAM_CTRL_reg))
#define  BLU_LD_SRAM_CTRL_dummy_31_3_shift                                       (3)
#define  BLU_LD_SRAM_CTRL_ld_blight_update_en_shift                              (2)
#define  BLU_LD_SRAM_CTRL_ld_blight_sw_mode_shift                                (1)
#define  BLU_LD_SRAM_CTRL_ld_table_sw_mode_shift                                 (0)
#define  BLU_LD_SRAM_CTRL_dummy_31_3_mask                                        (0xFFFFFFF8)
#define  BLU_LD_SRAM_CTRL_ld_blight_update_en_mask                               (0x00000004)
#define  BLU_LD_SRAM_CTRL_ld_blight_sw_mode_mask                                 (0x00000002)
#define  BLU_LD_SRAM_CTRL_ld_table_sw_mode_mask                                  (0x00000001)
#define  BLU_LD_SRAM_CTRL_dummy_31_3(data)                                       (0xFFFFFFF8&((data)<<3))
#define  BLU_LD_SRAM_CTRL_ld_blight_update_en(data)                              (0x00000004&((data)<<2))
#define  BLU_LD_SRAM_CTRL_ld_blight_sw_mode(data)                                (0x00000002&((data)<<1))
#define  BLU_LD_SRAM_CTRL_ld_table_sw_mode(data)                                 (0x00000001&(data))
#define  BLU_LD_SRAM_CTRL_get_dummy_31_3(data)                                   ((0xFFFFFFF8&(data))>>3)
#define  BLU_LD_SRAM_CTRL_get_ld_blight_update_en(data)                          ((0x00000004&(data))>>2)
#define  BLU_LD_SRAM_CTRL_get_ld_blight_sw_mode(data)                            ((0x00000002&(data))>>1)
#define  BLU_LD_SRAM_CTRL_get_ld_table_sw_mode(data)                             (0x00000001&(data))

#define  BLU_LD_BLIGHT_AP                                                        0x1802C298
#define  BLU_LD_BLIGHT_AP_reg_addr                                               "0xB802C298"
#define  BLU_LD_BLIGHT_AP_reg                                                    0xB802C298
#define  BLU_LD_BLIGHT_AP_inst_addr                                              "0x0037"
#define  set_BLU_LD_BLIGHT_AP_reg(data)                                          (*((volatile unsigned int*)BLU_LD_BLIGHT_AP_reg)=data)
#define  get_BLU_LD_BLIGHT_AP_reg                                                (*((volatile unsigned int*)BLU_LD_BLIGHT_AP_reg))
#define  BLU_LD_BLIGHT_AP_dummy_31_8_shift                                       (8)
#define  BLU_LD_BLIGHT_AP_ld_blight_adr_shift                                    (0)
#define  BLU_LD_BLIGHT_AP_dummy_31_8_mask                                        (0xFFFFFF00)
#define  BLU_LD_BLIGHT_AP_ld_blight_adr_mask                                     (0x000000FF)
#define  BLU_LD_BLIGHT_AP_dummy_31_8(data)                                       (0xFFFFFF00&((data)<<8))
#define  BLU_LD_BLIGHT_AP_ld_blight_adr(data)                                    (0x000000FF&(data))
#define  BLU_LD_BLIGHT_AP_get_dummy_31_8(data)                                   ((0xFFFFFF00&(data))>>8)
#define  BLU_LD_BLIGHT_AP_get_ld_blight_adr(data)                                (0x000000FF&(data))

#define  BLU_LD_BLIGHT_DP                                                        0x1802C29C
#define  BLU_LD_BLIGHT_DP_reg_addr                                               "0xB802C29C"
#define  BLU_LD_BLIGHT_DP_reg                                                    0xB802C29C
#define  BLU_LD_BLIGHT_DP_inst_addr                                              "0x0038"
#define  set_BLU_LD_BLIGHT_DP_reg(data)                                          (*((volatile unsigned int*)BLU_LD_BLIGHT_DP_reg)=data)
#define  get_BLU_LD_BLIGHT_DP_reg                                                (*((volatile unsigned int*)BLU_LD_BLIGHT_DP_reg))
#define  BLU_LD_BLIGHT_DP_dummy_31_26_shift                                      (26)
#define  BLU_LD_BLIGHT_DP_ld_blight_dat_msb_shift                                (16)
#define  BLU_LD_BLIGHT_DP_dummy_15_10_shift                                      (10)
#define  BLU_LD_BLIGHT_DP_ld_blight_dat_lsb_shift                                (0)
#define  BLU_LD_BLIGHT_DP_dummy_31_26_mask                                       (0xFC000000)
#define  BLU_LD_BLIGHT_DP_ld_blight_dat_msb_mask                                 (0x03FF0000)
#define  BLU_LD_BLIGHT_DP_dummy_15_10_mask                                       (0x0000FC00)
#define  BLU_LD_BLIGHT_DP_ld_blight_dat_lsb_mask                                 (0x000003FF)
#define  BLU_LD_BLIGHT_DP_dummy_31_26(data)                                      (0xFC000000&((data)<<26))
#define  BLU_LD_BLIGHT_DP_ld_blight_dat_msb(data)                                (0x03FF0000&((data)<<16))
#define  BLU_LD_BLIGHT_DP_dummy_15_10(data)                                      (0x0000FC00&((data)<<10))
#define  BLU_LD_BLIGHT_DP_ld_blight_dat_lsb(data)                                (0x000003FF&(data))
#define  BLU_LD_BLIGHT_DP_get_dummy_31_26(data)                                  ((0xFC000000&(data))>>26)
#define  BLU_LD_BLIGHT_DP_get_ld_blight_dat_msb(data)                            ((0x03FF0000&(data))>>16)
#define  BLU_LD_BLIGHT_DP_get_dummy_15_10(data)                                  ((0x0000FC00&(data))>>10)
#define  BLU_LD_BLIGHT_DP_get_ld_blight_dat_lsb(data)                            (0x000003FF&(data))

#define  BLU_LD_Inter_HTabSel1                                                   0x1802C2A0
#define  BLU_LD_Inter_HTabSel1_reg_addr                                          "0xB802C2A0"
#define  BLU_LD_Inter_HTabSel1_reg                                               0xB802C2A0
#define  BLU_LD_Inter_HTabSel1_inst_addr                                         "0x0039"
#define  set_BLU_LD_Inter_HTabSel1_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_HTabSel1_reg)=data)
#define  get_BLU_LD_Inter_HTabSel1_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_HTabSel1_reg))
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_0_shift                                (24)
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_1_shift                                (16)
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_2_shift                                (8)
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_3_shift                                (0)
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_0_mask                                 (0x3F000000)
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_1_mask                                 (0x003F0000)
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_2_mask                                 (0x00003F00)
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_3_mask                                 (0x0000003F)
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_0(data)                                (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_1(data)                                (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_2(data)                                (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_HTabSel1_ld_htabsel_3(data)                                (0x0000003F&(data))
#define  BLU_LD_Inter_HTabSel1_get_ld_htabsel_0(data)                            ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_HTabSel1_get_ld_htabsel_1(data)                            ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_HTabSel1_get_ld_htabsel_2(data)                            ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_HTabSel1_get_ld_htabsel_3(data)                            (0x0000003F&(data))

#define  BLU_LD_Inter_HtabSel2                                                   0x1802C2A4
#define  BLU_LD_Inter_HtabSel2_reg_addr                                          "0xB802C2A4"
#define  BLU_LD_Inter_HtabSel2_reg                                               0xB802C2A4
#define  BLU_LD_Inter_HtabSel2_inst_addr                                         "0x003A"
#define  set_BLU_LD_Inter_HtabSel2_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_HtabSel2_reg)=data)
#define  get_BLU_LD_Inter_HtabSel2_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_HtabSel2_reg))
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_4_shift                                (24)
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_5_shift                                (16)
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_6_shift                                (8)
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_7_shift                                (0)
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_4_mask                                 (0x3F000000)
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_5_mask                                 (0x003F0000)
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_6_mask                                 (0x00003F00)
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_7_mask                                 (0x0000003F)
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_4(data)                                (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_5(data)                                (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_6(data)                                (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_HtabSel2_ld_htabsel_7(data)                                (0x0000003F&(data))
#define  BLU_LD_Inter_HtabSel2_get_ld_htabsel_4(data)                            ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_HtabSel2_get_ld_htabsel_5(data)                            ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_HtabSel2_get_ld_htabsel_6(data)                            ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_HtabSel2_get_ld_htabsel_7(data)                            (0x0000003F&(data))

#define  BLU_LD_Inter_HtabSel3                                                   0x1802C2A8
#define  BLU_LD_Inter_HtabSel3_reg_addr                                          "0xB802C2A8"
#define  BLU_LD_Inter_HtabSel3_reg                                               0xB802C2A8
#define  BLU_LD_Inter_HtabSel3_inst_addr                                         "0x003B"
#define  set_BLU_LD_Inter_HtabSel3_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_HtabSel3_reg)=data)
#define  get_BLU_LD_Inter_HtabSel3_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_HtabSel3_reg))
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_8_shift                                (24)
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_9_shift                                (16)
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_10_shift                               (8)
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_11_shift                               (0)
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_8_mask                                 (0x3F000000)
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_9_mask                                 (0x003F0000)
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_10_mask                                (0x00003F00)
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_11_mask                                (0x0000003F)
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_8(data)                                (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_9(data)                                (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_10(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_HtabSel3_ld_htabsel_11(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_HtabSel3_get_ld_htabsel_8(data)                            ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_HtabSel3_get_ld_htabsel_9(data)                            ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_HtabSel3_get_ld_htabsel_10(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_HtabSel3_get_ld_htabsel_11(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_HtabSel4                                                   0x1802C2AC
#define  BLU_LD_Inter_HtabSel4_reg_addr                                          "0xB802C2AC"
#define  BLU_LD_Inter_HtabSel4_reg                                               0xB802C2AC
#define  BLU_LD_Inter_HtabSel4_inst_addr                                         "0x003C"
#define  set_BLU_LD_Inter_HtabSel4_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_HtabSel4_reg)=data)
#define  get_BLU_LD_Inter_HtabSel4_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_HtabSel4_reg))
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_12_shift                               (24)
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_13_shift                               (16)
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_14_shift                               (8)
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_15_shift                               (0)
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_12_mask                                (0x3F000000)
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_13_mask                                (0x003F0000)
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_14_mask                                (0x00003F00)
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_15_mask                                (0x0000003F)
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_12(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_13(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_14(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_HtabSel4_ld_htabsel_15(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_HtabSel4_get_ld_htabsel_12(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_HtabSel4_get_ld_htabsel_13(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_HtabSel4_get_ld_htabsel_14(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_HtabSel4_get_ld_htabsel_15(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_HtabSel5                                                   0x1802C2B0
#define  BLU_LD_Inter_HtabSel5_reg_addr                                          "0xB802C2B0"
#define  BLU_LD_Inter_HtabSel5_reg                                               0xB802C2B0
#define  BLU_LD_Inter_HtabSel5_inst_addr                                         "0x003D"
#define  set_BLU_LD_Inter_HtabSel5_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_HtabSel5_reg)=data)
#define  get_BLU_LD_Inter_HtabSel5_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_HtabSel5_reg))
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_16_shift                               (24)
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_17_shift                               (16)
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_18_shift                               (8)
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_19_shift                               (0)
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_16_mask                                (0x3F000000)
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_17_mask                                (0x003F0000)
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_18_mask                                (0x00003F00)
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_19_mask                                (0x0000003F)
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_16(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_17(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_18(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_HtabSel5_ld_htabsel_19(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_HtabSel5_get_ld_htabsel_16(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_HtabSel5_get_ld_htabsel_17(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_HtabSel5_get_ld_htabsel_18(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_HtabSel5_get_ld_htabsel_19(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_HtabSel6                                                   0x1802C2B4
#define  BLU_LD_Inter_HtabSel6_reg_addr                                          "0xB802C2B4"
#define  BLU_LD_Inter_HtabSel6_reg                                               0xB802C2B4
#define  BLU_LD_Inter_HtabSel6_inst_addr                                         "0x003E"
#define  set_BLU_LD_Inter_HtabSel6_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_HtabSel6_reg)=data)
#define  get_BLU_LD_Inter_HtabSel6_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_HtabSel6_reg))
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_20_shift                               (24)
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_21_shift                               (16)
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_22_shift                               (8)
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_23_shift                               (0)
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_20_mask                                (0x3F000000)
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_21_mask                                (0x003F0000)
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_22_mask                                (0x00003F00)
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_23_mask                                (0x0000003F)
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_20(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_21(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_22(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_HtabSel6_ld_htabsel_23(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_HtabSel6_get_ld_htabsel_20(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_HtabSel6_get_ld_htabsel_21(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_HtabSel6_get_ld_htabsel_22(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_HtabSel6_get_ld_htabsel_23(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_HtabSel7                                                   0x1802C2B8
#define  BLU_LD_Inter_HtabSel7_reg_addr                                          "0xB802C2B8"
#define  BLU_LD_Inter_HtabSel7_reg                                               0xB802C2B8
#define  BLU_LD_Inter_HtabSel7_inst_addr                                         "0x003F"
#define  set_BLU_LD_Inter_HtabSel7_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_HtabSel7_reg)=data)
#define  get_BLU_LD_Inter_HtabSel7_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_HtabSel7_reg))
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_24_shift                               (24)
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_25_shift                               (16)
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_26_shift                               (8)
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_27_shift                               (0)
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_24_mask                                (0x3F000000)
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_25_mask                                (0x003F0000)
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_26_mask                                (0x00003F00)
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_27_mask                                (0x0000003F)
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_24(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_25(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_26(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_HtabSel7_ld_htabsel_27(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_HtabSel7_get_ld_htabsel_24(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_HtabSel7_get_ld_htabsel_25(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_HtabSel7_get_ld_htabsel_26(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_HtabSel7_get_ld_htabsel_27(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_HtabSel8                                                   0x1802C2BC
#define  BLU_LD_Inter_HtabSel8_reg_addr                                          "0xB802C2BC"
#define  BLU_LD_Inter_HtabSel8_reg                                               0xB802C2BC
#define  BLU_LD_Inter_HtabSel8_inst_addr                                         "0x0040"
#define  set_BLU_LD_Inter_HtabSel8_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_HtabSel8_reg)=data)
#define  get_BLU_LD_Inter_HtabSel8_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_HtabSel8_reg))
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_28_shift                               (24)
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_29_shift                               (16)
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_30_shift                               (8)
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_31_shift                               (0)
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_28_mask                                (0x3F000000)
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_29_mask                                (0x003F0000)
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_30_mask                                (0x00003F00)
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_31_mask                                (0x0000003F)
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_28(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_29(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_30(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_HtabSel8_ld_htabsel_31(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_HtabSel8_get_ld_htabsel_28(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_HtabSel8_get_ld_htabsel_29(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_HtabSel8_get_ld_htabsel_30(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_HtabSel8_get_ld_htabsel_31(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_VtabSel1                                                   0x1802C2C0
#define  BLU_LD_Inter_VtabSel1_reg_addr                                          "0xB802C2C0"
#define  BLU_LD_Inter_VtabSel1_reg                                               0xB802C2C0
#define  BLU_LD_Inter_VtabSel1_inst_addr                                         "0x0041"
#define  set_BLU_LD_Inter_VtabSel1_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_VtabSel1_reg)=data)
#define  get_BLU_LD_Inter_VtabSel1_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_VtabSel1_reg))
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_0_shift                                (24)
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_1_shift                                (16)
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_2_shift                                (8)
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_3_shift                                (0)
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_0_mask                                 (0x3F000000)
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_1_mask                                 (0x003F0000)
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_2_mask                                 (0x00003F00)
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_3_mask                                 (0x0000003F)
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_0(data)                                (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_1(data)                                (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_2(data)                                (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_VtabSel1_ld_vtabsel_3(data)                                (0x0000003F&(data))
#define  BLU_LD_Inter_VtabSel1_get_ld_vtabsel_0(data)                            ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_VtabSel1_get_ld_vtabsel_1(data)                            ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_VtabSel1_get_ld_vtabsel_2(data)                            ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_VtabSel1_get_ld_vtabsel_3(data)                            (0x0000003F&(data))

#define  BLU_LD_Inter_VtabSel2                                                   0x1802C2C4
#define  BLU_LD_Inter_VtabSel2_reg_addr                                          "0xB802C2C4"
#define  BLU_LD_Inter_VtabSel2_reg                                               0xB802C2C4
#define  BLU_LD_Inter_VtabSel2_inst_addr                                         "0x0042"
#define  set_BLU_LD_Inter_VtabSel2_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_VtabSel2_reg)=data)
#define  get_BLU_LD_Inter_VtabSel2_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_VtabSel2_reg))
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_4_shift                                (24)
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_5_shift                                (16)
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_6_shift                                (8)
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_7_shift                                (0)
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_4_mask                                 (0x3F000000)
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_5_mask                                 (0x003F0000)
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_6_mask                                 (0x00003F00)
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_7_mask                                 (0x0000003F)
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_4(data)                                (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_5(data)                                (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_6(data)                                (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_VtabSel2_ld_vtabsel_7(data)                                (0x0000003F&(data))
#define  BLU_LD_Inter_VtabSel2_get_ld_vtabsel_4(data)                            ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_VtabSel2_get_ld_vtabsel_5(data)                            ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_VtabSel2_get_ld_vtabsel_6(data)                            ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_VtabSel2_get_ld_vtabsel_7(data)                            (0x0000003F&(data))

#define  BLU_LD_Inter_VtabSel3                                                   0x1802C2C8
#define  BLU_LD_Inter_VtabSel3_reg_addr                                          "0xB802C2C8"
#define  BLU_LD_Inter_VtabSel3_reg                                               0xB802C2C8
#define  BLU_LD_Inter_VtabSel3_inst_addr                                         "0x0043"
#define  set_BLU_LD_Inter_VtabSel3_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_VtabSel3_reg)=data)
#define  get_BLU_LD_Inter_VtabSel3_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_VtabSel3_reg))
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_8_shift                                (24)
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_9_shift                                (16)
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_10_shift                               (8)
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_11_shift                               (0)
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_8_mask                                 (0x3F000000)
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_9_mask                                 (0x003F0000)
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_10_mask                                (0x00003F00)
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_11_mask                                (0x0000003F)
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_8(data)                                (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_9(data)                                (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_10(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_VtabSel3_ld_vtabsel_11(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_VtabSel3_get_ld_vtabsel_8(data)                            ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_VtabSel3_get_ld_vtabsel_9(data)                            ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_VtabSel3_get_ld_vtabsel_10(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_VtabSel3_get_ld_vtabsel_11(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_VtabSel4                                                   0x1802C2CC
#define  BLU_LD_Inter_VtabSel4_reg_addr                                          "0xB802C2CC"
#define  BLU_LD_Inter_VtabSel4_reg                                               0xB802C2CC
#define  BLU_LD_Inter_VtabSel4_inst_addr                                         "0x0044"
#define  set_BLU_LD_Inter_VtabSel4_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_VtabSel4_reg)=data)
#define  get_BLU_LD_Inter_VtabSel4_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_VtabSel4_reg))
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_12_shift                               (24)
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_13_shift                               (16)
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_14_shift                               (8)
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_15_shift                               (0)
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_12_mask                                (0x3F000000)
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_13_mask                                (0x003F0000)
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_14_mask                                (0x00003F00)
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_15_mask                                (0x0000003F)
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_12(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_13(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_14(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_VtabSel4_ld_vtabsel_15(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_VtabSel4_get_ld_vtabsel_12(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_VtabSel4_get_ld_vtabsel_13(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_VtabSel4_get_ld_vtabsel_14(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_VtabSel4_get_ld_vtabsel_15(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_VtabSel5                                                   0x1802C2D0
#define  BLU_LD_Inter_VtabSel5_reg_addr                                          "0xB802C2D0"
#define  BLU_LD_Inter_VtabSel5_reg                                               0xB802C2D0
#define  BLU_LD_Inter_VtabSel5_inst_addr                                         "0x0045"
#define  set_BLU_LD_Inter_VtabSel5_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_VtabSel5_reg)=data)
#define  get_BLU_LD_Inter_VtabSel5_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_VtabSel5_reg))
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_16_shift                               (24)
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_17_shift                               (16)
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_18_shift                               (8)
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_19_shift                               (0)
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_16_mask                                (0x3F000000)
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_17_mask                                (0x003F0000)
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_18_mask                                (0x00003F00)
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_19_mask                                (0x0000003F)
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_16(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_17(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_18(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_VtabSel5_ld_vtabsel_19(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_VtabSel5_get_ld_vtabsel_16(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_VtabSel5_get_ld_vtabsel_17(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_VtabSel5_get_ld_vtabsel_18(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_VtabSel5_get_ld_vtabsel_19(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_VtabSel6                                                   0x1802C2D4
#define  BLU_LD_Inter_VtabSel6_reg_addr                                          "0xB802C2D4"
#define  BLU_LD_Inter_VtabSel6_reg                                               0xB802C2D4
#define  BLU_LD_Inter_VtabSel6_inst_addr                                         "0x0046"
#define  set_BLU_LD_Inter_VtabSel6_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_VtabSel6_reg)=data)
#define  get_BLU_LD_Inter_VtabSel6_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_VtabSel6_reg))
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_20_shift                               (24)
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_21_shift                               (16)
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_22_shift                               (8)
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_23_shift                               (0)
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_20_mask                                (0x3F000000)
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_21_mask                                (0x003F0000)
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_22_mask                                (0x00003F00)
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_23_mask                                (0x0000003F)
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_20(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_21(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_22(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_VtabSel6_ld_vtabsel_23(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_VtabSel6_get_ld_vtabsel_20(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_VtabSel6_get_ld_vtabsel_21(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_VtabSel6_get_ld_vtabsel_22(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_VtabSel6_get_ld_vtabsel_23(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_VtabSel7                                                   0x1802C2D8
#define  BLU_LD_Inter_VtabSel7_reg_addr                                          "0xB802C2D8"
#define  BLU_LD_Inter_VtabSel7_reg                                               0xB802C2D8
#define  BLU_LD_Inter_VtabSel7_inst_addr                                         "0x0047"
#define  set_BLU_LD_Inter_VtabSel7_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_VtabSel7_reg)=data)
#define  get_BLU_LD_Inter_VtabSel7_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_VtabSel7_reg))
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_24_shift                               (24)
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_25_shift                               (16)
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_26_shift                               (8)
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_27_shift                               (0)
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_24_mask                                (0x3F000000)
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_25_mask                                (0x003F0000)
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_26_mask                                (0x00003F00)
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_27_mask                                (0x0000003F)
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_24(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_25(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_26(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_VtabSel7_ld_vtabsel_27(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_VtabSel7_get_ld_vtabsel_24(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_VtabSel7_get_ld_vtabsel_25(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_VtabSel7_get_ld_vtabsel_26(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_VtabSel7_get_ld_vtabsel_27(data)                           (0x0000003F&(data))

#define  BLU_LD_Inter_VtabSel8                                                   0x1802C2DC
#define  BLU_LD_Inter_VtabSel8_reg_addr                                          "0xB802C2DC"
#define  BLU_LD_Inter_VtabSel8_reg                                               0xB802C2DC
#define  BLU_LD_Inter_VtabSel8_inst_addr                                         "0x0048"
#define  set_BLU_LD_Inter_VtabSel8_reg(data)                                     (*((volatile unsigned int*)BLU_LD_Inter_VtabSel8_reg)=data)
#define  get_BLU_LD_Inter_VtabSel8_reg                                           (*((volatile unsigned int*)BLU_LD_Inter_VtabSel8_reg))
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_28_shift                               (24)
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_29_shift                               (16)
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_30_shift                               (8)
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_31_shift                               (0)
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_28_mask                                (0x3F000000)
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_29_mask                                (0x003F0000)
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_30_mask                                (0x00003F00)
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_31_mask                                (0x0000003F)
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_28(data)                               (0x3F000000&((data)<<24))
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_29(data)                               (0x003F0000&((data)<<16))
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_30(data)                               (0x00003F00&((data)<<8))
#define  BLU_LD_Inter_VtabSel8_ld_vtabsel_31(data)                               (0x0000003F&(data))
#define  BLU_LD_Inter_VtabSel8_get_ld_vtabsel_28(data)                           ((0x3F000000&(data))>>24)
#define  BLU_LD_Inter_VtabSel8_get_ld_vtabsel_29(data)                           ((0x003F0000&(data))>>16)
#define  BLU_LD_Inter_VtabSel8_get_ld_vtabsel_30(data)                           ((0x00003F00&(data))>>8)
#define  BLU_LD_Inter_VtabSel8_get_ld_vtabsel_31(data)                           (0x0000003F&(data))

#define  BLU_LD_Demo_window_ctrl0                                                0x1802C2E0
#define  BLU_LD_Demo_window_ctrl0_reg_addr                                       "0xB802C2E0"
#define  BLU_LD_Demo_window_ctrl0_reg                                            0xB802C2E0
#define  BLU_LD_Demo_window_ctrl0_inst_addr                                      "0x0049"
#define  set_BLU_LD_Demo_window_ctrl0_reg(data)                                  (*((volatile unsigned int*)BLU_LD_Demo_window_ctrl0_reg)=data)
#define  get_BLU_LD_Demo_window_ctrl0_reg                                        (*((volatile unsigned int*)BLU_LD_Demo_window_ctrl0_reg))
#define  BLU_LD_Demo_window_ctrl0_ld_demo_en_shift                               (31)
#define  BLU_LD_Demo_window_ctrl0_ld_demo_mode_shift                             (30)
#define  BLU_LD_Demo_window_ctrl0_ld_demo_top_shift                              (16)
#define  BLU_LD_Demo_window_ctrl0_ld_demo_bottom_shift                           (0)
#define  BLU_LD_Demo_window_ctrl0_ld_demo_en_mask                                (0x80000000)
#define  BLU_LD_Demo_window_ctrl0_ld_demo_mode_mask                              (0x40000000)
#define  BLU_LD_Demo_window_ctrl0_ld_demo_top_mask                               (0x0FFF0000)
#define  BLU_LD_Demo_window_ctrl0_ld_demo_bottom_mask                            (0x00000FFF)
#define  BLU_LD_Demo_window_ctrl0_ld_demo_en(data)                               (0x80000000&((data)<<31))
#define  BLU_LD_Demo_window_ctrl0_ld_demo_mode(data)                             (0x40000000&((data)<<30))
#define  BLU_LD_Demo_window_ctrl0_ld_demo_top(data)                              (0x0FFF0000&((data)<<16))
#define  BLU_LD_Demo_window_ctrl0_ld_demo_bottom(data)                           (0x00000FFF&(data))
#define  BLU_LD_Demo_window_ctrl0_get_ld_demo_en(data)                           ((0x80000000&(data))>>31)
#define  BLU_LD_Demo_window_ctrl0_get_ld_demo_mode(data)                         ((0x40000000&(data))>>30)
#define  BLU_LD_Demo_window_ctrl0_get_ld_demo_top(data)                          ((0x0FFF0000&(data))>>16)
#define  BLU_LD_Demo_window_ctrl0_get_ld_demo_bottom(data)                       (0x00000FFF&(data))

#define  BLU_LD_Demo_window_ctrl1                                                0x1802C2E4
#define  BLU_LD_Demo_window_ctrl1_reg_addr                                       "0xB802C2E4"
#define  BLU_LD_Demo_window_ctrl1_reg                                            0xB802C2E4
#define  BLU_LD_Demo_window_ctrl1_inst_addr                                      "0x004A"
#define  set_BLU_LD_Demo_window_ctrl1_reg(data)                                  (*((volatile unsigned int*)BLU_LD_Demo_window_ctrl1_reg)=data)
#define  get_BLU_LD_Demo_window_ctrl1_reg                                        (*((volatile unsigned int*)BLU_LD_Demo_window_ctrl1_reg))
#define  BLU_LD_Demo_window_ctrl1_ld_demo_left_shift                             (16)
#define  BLU_LD_Demo_window_ctrl1_ld_demo_right_shift                            (0)
#define  BLU_LD_Demo_window_ctrl1_ld_demo_left_mask                              (0x1FFF0000)
#define  BLU_LD_Demo_window_ctrl1_ld_demo_right_mask                             (0x00001FFF)
#define  BLU_LD_Demo_window_ctrl1_ld_demo_left(data)                             (0x1FFF0000&((data)<<16))
#define  BLU_LD_Demo_window_ctrl1_ld_demo_right(data)                            (0x00001FFF&(data))
#define  BLU_LD_Demo_window_ctrl1_get_ld_demo_left(data)                         ((0x1FFF0000&(data))>>16)
#define  BLU_LD_Demo_window_ctrl1_get_ld_demo_right(data)                        (0x00001FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======BLU register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_comp_en:1;
        RBus_UInt32  dummy1802c200_30_0:31;
    };
}blu_ld_global_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_db_en:1;
        RBus_UInt32  ld_vs_sel:1;
        RBus_UInt32  ld_db_apply:1;
        RBus_UInt32  dummy1802c204_28:1;
        RBus_UInt32  ld_db_read_level:1;
        RBus_UInt32  dummy1802c204_26_0:27;
    };
}blu_ld_global_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c208_31:1;
        RBus_UInt32  ld_3d_mode:2;
        RBus_UInt32  ld_blk_hnum:5;
        RBus_UInt32  dummy1802c208_23_21:3;
        RBus_UInt32  ld_blk_vnum:5;
        RBus_UInt32  dummy1802c208_15_8:8;
        RBus_UInt32  ld_subblk_mode:1;
        RBus_UInt32  ld_gdim_mode:1;
        RBus_UInt32  ld_blk_type:2;
        RBus_UInt32  ld_hist_mode:2;
        RBus_UInt32  ld_tenable:1;
        RBus_UInt32  ld_valid:1;
    };
}blu_ld_global_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c20c_31_29:3;
        RBus_UInt32  ld_blk_hsize:13;
        RBus_UInt32  dummy1802c20c_15_12:4;
        RBus_UInt32  ld_blk_vsize:12;
    };
}blu_ld_global_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_drf_rme_7:1;
        RBus_UInt32  ld_drf_rme_6:1;
        RBus_UInt32  ld_drf_rme_5:1;
        RBus_UInt32  ld_drf_rme_4:1;
        RBus_UInt32  ld_drf_rme_3:1;
        RBus_UInt32  ld_drf_rme_2:1;
        RBus_UInt32  ld_drf_rme_1:1;
        RBus_UInt32  ld_drf_rme_0:1;
        RBus_UInt32  ld_drf_ls_7:1;
        RBus_UInt32  ld_drf_ls_6:1;
        RBus_UInt32  ld_drf_ls_5:1;
        RBus_UInt32  ld_drf_ls_4:1;
        RBus_UInt32  ld_drf_ls_3:1;
        RBus_UInt32  ld_drf_ls_2:1;
        RBus_UInt32  ld_drf_ls_1:1;
        RBus_UInt32  ld_drf_ls_0:1;
        RBus_UInt32  ld_drf_bist_fail_7:1;
        RBus_UInt32  ld_drf_bist_fail_6:1;
        RBus_UInt32  ld_drf_bist_fail_5:1;
        RBus_UInt32  ld_drf_bist_fail_4:1;
        RBus_UInt32  ld_drf_bist_fail_3:1;
        RBus_UInt32  ld_drf_bist_fail_2:1;
        RBus_UInt32  ld_drf_bist_fail_1:1;
        RBus_UInt32  ld_drf_bist_fail_0:1;
        RBus_UInt32  ld_bist_fail_7:1;
        RBus_UInt32  ld_bist_fail_6:1;
        RBus_UInt32  ld_bist_fail_5:1;
        RBus_UInt32  ld_bist_fail_4:1;
        RBus_UInt32  ld_bist_fail_3:1;
        RBus_UInt32  ld_bist_fail_2:1;
        RBus_UInt32  ld_bist_fail_1:1;
        RBus_UInt32  ld_bist_fail_0:1;
    };
}blu_ld_global_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_drf_rm_7:4;
        RBus_UInt32  ld_drf_rm_6:4;
        RBus_UInt32  ld_drf_rm_5:4;
        RBus_UInt32  ld_drf_rm_4:4;
        RBus_UInt32  ld_drf_rm_3:4;
        RBus_UInt32  ld_drf_rm_2:4;
        RBus_UInt32  ld_drf_rm_1:4;
        RBus_UInt32  ld_drf_rm_0:4;
    };
}blu_ld_global_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ld_drf_rm_9:4;
        RBus_UInt32  ld_drf_rm_8:4;
        RBus_UInt32  ld_drf_rme_9:1;
        RBus_UInt32  ld_drf_rme_8:1;
        RBus_UInt32  ld_drf_ls_9:1;
        RBus_UInt32  ld_drf_ls_8:1;
        RBus_UInt32  ld_drf_bist_fail_9:1;
        RBus_UInt32  ld_drf_bist_fail_8:1;
        RBus_UInt32  ld_bist_fail_9:1;
        RBus_UInt32  ld_bist_fail_8:1;
    };
}blu_ld_global_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  ld_global_max:12;
    };
}blu_ld_global_max_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist0:16;
        RBus_UInt32  ld_global_hist1:16;
    };
}blu_ld_global_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist2:16;
        RBus_UInt32  ld_global_hist3:16;
    };
}blu_ld_global_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist4:16;
        RBus_UInt32  ld_global_hist5:16;
    };
}blu_ld_global_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist6:16;
        RBus_UInt32  ld_global_hist7:16;
    };
}blu_ld_global_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist8:16;
        RBus_UInt32  ld_global_hist9:16;
    };
}blu_ld_global_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist10:16;
        RBus_UInt32  ld_global_hist11:16;
    };
}blu_ld_global_hist6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist12:16;
        RBus_UInt32  ld_global_hist13:16;
    };
}blu_ld_global_hist7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist14:16;
        RBus_UInt32  ld_global_hist15:16;
    };
}blu_ld_global_hist8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_maxgain:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_avegain:5;
        RBus_UInt32  res3:12;
        RBus_UInt32  ld_histshiftbit:4;
    };
}blu_ld_decision_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_hist0gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_hist1gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_hist2gain:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_hist3gain:6;
    };
}blu_ld_decision_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_hist4gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_hist5gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_hist6gain:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_hist7gain:6;
    };
}blu_ld_decision_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ld_decaccess_addr:9;
        RBus_UInt32  res2:15;
        RBus_UInt32  ld_decaccess_en:1;
    };
}blu_ld_decision_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_decaccess_data:30;
    };
}blu_ld_decision_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialcoef0:4;
        RBus_UInt32  ld_spatialcoef1:4;
        RBus_UInt32  ld_spatialcoef2:4;
        RBus_UInt32  ld_spatialcoef3:4;
        RBus_UInt32  ld_spatialcoef4:4;
        RBus_UInt32  ld_spatialcoef5:4;
        RBus_UInt32  ld_spatialcoef6:4;
        RBus_UInt32  ld_spatialcoef7:4;
    };
}blu_ld_spatial_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialcoef8:4;
        RBus_UInt32  ld_spatialcoef9:4;
        RBus_UInt32  ld_spatialcoef10:4;
        RBus_UInt32  dummy1802c254_19_3:17;
        RBus_UInt32  ld_backlightboosten:1;
        RBus_UInt32  ld_spatialremapbusy:1;
        RBus_UInt32  ld_spatialremapen:1;
    };
}blu_ld_spatial_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  spatial_new_mode:1;
        RBus_UInt32  ld_spatialnewcoef00:6;
        RBus_UInt32  ld_spatialnewcoef01:6;
        RBus_UInt32  ld_spatialnewcoef02:6;
        RBus_UInt32  ld_spatialnewcoef03:6;
        RBus_UInt32  ld_spatialnewcoef04:6;
    };
}blu_ld_spatial_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_spatialnewcoef10:6;
        RBus_UInt32  ld_spatialnewcoef11:6;
        RBus_UInt32  ld_spatialnewcoef12:6;
        RBus_UInt32  ld_spatialnewcoef13:6;
        RBus_UInt32  ld_spatialnewcoef14:6;
    };
}blu_ld_spatial_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_spatialnewcoef20:6;
        RBus_UInt32  ld_spatialnewcoef21:6;
        RBus_UInt32  ld_spatialnewcoef22:6;
        RBus_UInt32  ld_spatialnewcoef23:6;
        RBus_UInt32  ld_spatialnewcoef24:6;
    };
}blu_ld_spatial_ctrl7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_spatialnewcoef30:6;
        RBus_UInt32  ld_spatialnewcoef31:6;
        RBus_UInt32  ld_spatialnewcoef32:6;
        RBus_UInt32  ld_spatialnewcoef33:6;
        RBus_UInt32  ld_spatialnewcoef34:6;
    };
}blu_ld_spatial_ctrl8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ld_spatialnewcoef05:6;
        RBus_UInt32  ld_spatialnewcoef15:6;
        RBus_UInt32  ld_spatialnewcoef25:6;
        RBus_UInt32  ld_spatialnewcoef35:6;
    };
}blu_ld_spatial_ctrl9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ld_spatialnewcoef40:6;
        RBus_UInt32  ld_spatialnewcoef41:6;
        RBus_UInt32  ld_spatialnewcoef50:6;
    };
}blu_ld_spatial_ctrla_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ld_comp_2dlut_maxmode:1;
        RBus_UInt32  ld_data_comp_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ld_lut_ax_en:1;
        RBus_UInt32  ld_lut_ax_mode:1;
        RBus_UInt32  ld_lut_adr_mode:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  ld_lut_row_addr:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  ld_lut_column_addr:5;
    };
}blu_ld_data_comp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_lut_data:28;
    };
}blu_ld_lut_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ld_spatialremapadr:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_spatialremaptab1:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_spatialremaptab0:10;
    };
}blu_ld_spatial_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ld_bl_avg_shift:9;
    };
}blu_ld_backlight_average_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_spatialremaptab_initial3:10;
        RBus_UInt32  ld_spatialremaptab_initial2:10;
        RBus_UInt32  ld_spatialremaptab_initial:10;
    };
}blu_ld_spatial_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ld_aplmax_conti:1;
        RBus_UInt32  ld_aplmax_start:1;
    };
}blu_ld_apl_read_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ld_aplmax_addr:9;
        RBus_UInt32  res2:15;
        RBus_UInt32  ld_aplmax_access_en:1;
    };
}blu_ld_apl_read_max_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_aplmaxaccess_data:30;
    };
}blu_ld_apl_read_max_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ld_aplave_conti:1;
        RBus_UInt32  ld_aplave_start:1;
    };
}blu_ld_apl_read_ave_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ld_aplave_addr:9;
        RBus_UInt32  res2:15;
        RBus_UInt32  ld_aplave_access_en:1;
    };
}blu_ld_apl_read_ave_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_aplaveaccess_data:30;
    };
}blu_ld_apl_read_ave_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tmp_pos0thd:8;
        RBus_UInt32  ld_tmp_pos1thd:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_tmp_posmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_posmaxgain:5;
    };
}blu_ld_temporal_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tmp_neg0thd:8;
        RBus_UInt32  ld_tmp_neg1thd:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_tmp_negmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_negmaxgain:5;
    };
}blu_ld_temporal_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ld_tmp_maxdiff:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_scenechangegain1:5;
        RBus_UInt32  res3:8;
    };
}blu_ld_temporal_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blu_wr_num:7;
        RBus_UInt32  ld_blu_spitotal:9;
        RBus_UInt32  res1:6;
        RBus_UInt32  ld_blu_spien:1;
        RBus_UInt32  ld_blu_nodim:1;
        RBus_UInt32  ld_blu_usergain:8;
    };
}blu_ld_backlight_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_comp_satrange:8;
        RBus_UInt32  ld_comp_softmax:8;
        RBus_UInt32  ld_comp_minlimit:8;
        RBus_UInt32  ld_softcomp_gain:4;
        RBus_UInt32  ld_comp_maxmode:2;
        RBus_UInt32  ld_debugmode:2;
    };
}blu_ld_datacomp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c270_31_20:12;
        RBus_UInt32  ld_comp_inv_shift:3;
        RBus_UInt32  ld_comp_inv_mode:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  ld_srcgainsel:3;
    };
}blu_ld_datacomp_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tab_hsize:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_hfactor:20;
    };
}blu_ld_inter_hctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hinitphase3_right:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_hboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_hinitphase1:1;
        RBus_UInt32  ld_hinitphase2:8;
        RBus_UInt32  ld_hinitphase3_left:8;
    };
}blu_ld_inter_hctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tab_vsize:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_vfactor:20;
    };
}blu_ld_inter_vctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vinitphase3_right:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_vboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_vinitphase1:1;
        RBus_UInt32  ld_vinitphase2:8;
        RBus_UInt32  ld_vinitphase3_left:8;
    };
}blu_ld_inter_vctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c284_31_9:23;
        RBus_UInt32  ld_vtab_adr:9;
    };
}blu_ld_vtab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c288_31_26:6;
        RBus_UInt32  ld_vtab_dat_msb:10;
        RBus_UInt32  dummy1802c288_15_10:6;
        RBus_UInt32  ld_vtab_dat_lsb:10;
    };
}blu_ld_vtab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c28c_31_9:23;
        RBus_UInt32  ld_htab_adr:9;
    };
}blu_ld_htab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c290_31_26:6;
        RBus_UInt32  ld_htab_dat_msb:10;
        RBus_UInt32  dummy1802c290_15_10:6;
        RBus_UInt32  ld_htab_dat_lsb:10;
    };
}blu_ld_htab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c294_31_3:29;
        RBus_UInt32  ld_blight_update_en:1;
        RBus_UInt32  ld_blight_sw_mode:1;
        RBus_UInt32  ld_table_sw_mode:1;
    };
}blu_ld_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c298_31_8:24;
        RBus_UInt32  ld_blight_adr:8;
    };
}blu_ld_blight_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c29c_31_26:6;
        RBus_UInt32  ld_blight_dat_msb:10;
        RBus_UInt32  dummy1802c29c_15_10:6;
        RBus_UInt32  ld_blight_dat_lsb:10;
    };
}blu_ld_blight_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_3:6;
    };
}blu_ld_inter_htabsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_7:6;
    };
}blu_ld_inter_htabsel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_9:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_11:6;
    };
}blu_ld_inter_htabsel3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_13:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_15:6;
    };
}blu_ld_inter_htabsel4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_17:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_19:6;
    };
}blu_ld_inter_htabsel5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_21:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_23:6;
    };
}blu_ld_inter_htabsel6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_25:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_27:6;
    };
}blu_ld_inter_htabsel7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_29:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_31:6;
    };
}blu_ld_inter_htabsel8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_3:6;
    };
}blu_ld_inter_vtabsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_7:6;
    };
}blu_ld_inter_vtabsel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_9:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_11:6;
    };
}blu_ld_inter_vtabsel3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_13:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_15:6;
    };
}blu_ld_inter_vtabsel4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_17:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_19:6;
    };
}blu_ld_inter_vtabsel5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_21:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_23:6;
    };
}blu_ld_inter_vtabsel6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_25:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_27:6;
    };
}blu_ld_inter_vtabsel7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_29:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_31:6;
    };
}blu_ld_inter_vtabsel8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_demo_en:1;
        RBus_UInt32  ld_demo_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_demo_top:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ld_demo_bottom:12;
    };
}blu_ld_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_demo_left:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_demo_right:13;
    };
}blu_ld_demo_window_ctrl1_RBUS;

#else //apply LITTLE_ENDIAN

//======BLU register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c200_30_0:31;
        RBus_UInt32  ld_comp_en:1;
    };
}blu_ld_global_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c204_26_0:27;
        RBus_UInt32  ld_db_read_level:1;
        RBus_UInt32  dummy1802c204_28:1;
        RBus_UInt32  ld_db_apply:1;
        RBus_UInt32  ld_vs_sel:1;
        RBus_UInt32  ld_db_en:1;
    };
}blu_ld_global_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_valid:1;
        RBus_UInt32  ld_tenable:1;
        RBus_UInt32  ld_hist_mode:2;
        RBus_UInt32  ld_blk_type:2;
        RBus_UInt32  ld_gdim_mode:1;
        RBus_UInt32  ld_subblk_mode:1;
        RBus_UInt32  dummy1802c208_15_8:8;
        RBus_UInt32  ld_blk_vnum:5;
        RBus_UInt32  dummy1802c208_23_21:3;
        RBus_UInt32  ld_blk_hnum:5;
        RBus_UInt32  ld_3d_mode:2;
        RBus_UInt32  dummy1802c208_31:1;
    };
}blu_ld_global_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blk_vsize:12;
        RBus_UInt32  dummy1802c20c_15_12:4;
        RBus_UInt32  ld_blk_hsize:13;
        RBus_UInt32  dummy1802c20c_31_29:3;
    };
}blu_ld_global_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_bist_fail_0:1;
        RBus_UInt32  ld_bist_fail_1:1;
        RBus_UInt32  ld_bist_fail_2:1;
        RBus_UInt32  ld_bist_fail_3:1;
        RBus_UInt32  ld_bist_fail_4:1;
        RBus_UInt32  ld_bist_fail_5:1;
        RBus_UInt32  ld_bist_fail_6:1;
        RBus_UInt32  ld_bist_fail_7:1;
        RBus_UInt32  ld_drf_bist_fail_0:1;
        RBus_UInt32  ld_drf_bist_fail_1:1;
        RBus_UInt32  ld_drf_bist_fail_2:1;
        RBus_UInt32  ld_drf_bist_fail_3:1;
        RBus_UInt32  ld_drf_bist_fail_4:1;
        RBus_UInt32  ld_drf_bist_fail_5:1;
        RBus_UInt32  ld_drf_bist_fail_6:1;
        RBus_UInt32  ld_drf_bist_fail_7:1;
        RBus_UInt32  ld_drf_ls_0:1;
        RBus_UInt32  ld_drf_ls_1:1;
        RBus_UInt32  ld_drf_ls_2:1;
        RBus_UInt32  ld_drf_ls_3:1;
        RBus_UInt32  ld_drf_ls_4:1;
        RBus_UInt32  ld_drf_ls_5:1;
        RBus_UInt32  ld_drf_ls_6:1;
        RBus_UInt32  ld_drf_ls_7:1;
        RBus_UInt32  ld_drf_rme_0:1;
        RBus_UInt32  ld_drf_rme_1:1;
        RBus_UInt32  ld_drf_rme_2:1;
        RBus_UInt32  ld_drf_rme_3:1;
        RBus_UInt32  ld_drf_rme_4:1;
        RBus_UInt32  ld_drf_rme_5:1;
        RBus_UInt32  ld_drf_rme_6:1;
        RBus_UInt32  ld_drf_rme_7:1;
    };
}blu_ld_global_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_drf_rm_0:4;
        RBus_UInt32  ld_drf_rm_1:4;
        RBus_UInt32  ld_drf_rm_2:4;
        RBus_UInt32  ld_drf_rm_3:4;
        RBus_UInt32  ld_drf_rm_4:4;
        RBus_UInt32  ld_drf_rm_5:4;
        RBus_UInt32  ld_drf_rm_6:4;
        RBus_UInt32  ld_drf_rm_7:4;
    };
}blu_ld_global_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_bist_fail_8:1;
        RBus_UInt32  ld_bist_fail_9:1;
        RBus_UInt32  ld_drf_bist_fail_8:1;
        RBus_UInt32  ld_drf_bist_fail_9:1;
        RBus_UInt32  ld_drf_ls_8:1;
        RBus_UInt32  ld_drf_ls_9:1;
        RBus_UInt32  ld_drf_rme_8:1;
        RBus_UInt32  ld_drf_rme_9:1;
        RBus_UInt32  ld_drf_rm_8:4;
        RBus_UInt32  ld_drf_rm_9:4;
        RBus_UInt32  res1:16;
    };
}blu_ld_global_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_max:12;
        RBus_UInt32  res1:20;
    };
}blu_ld_global_max_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist1:16;
        RBus_UInt32  ld_global_hist0:16;
    };
}blu_ld_global_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist3:16;
        RBus_UInt32  ld_global_hist2:16;
    };
}blu_ld_global_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist5:16;
        RBus_UInt32  ld_global_hist4:16;
    };
}blu_ld_global_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist7:16;
        RBus_UInt32  ld_global_hist6:16;
    };
}blu_ld_global_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist9:16;
        RBus_UInt32  ld_global_hist8:16;
    };
}blu_ld_global_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist11:16;
        RBus_UInt32  ld_global_hist10:16;
    };
}blu_ld_global_hist6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist13:16;
        RBus_UInt32  ld_global_hist12:16;
    };
}blu_ld_global_hist7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist15:16;
        RBus_UInt32  ld_global_hist14:16;
    };
}blu_ld_global_hist8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_histshiftbit:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  ld_avegain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_maxgain:6;
        RBus_UInt32  res3:2;
    };
}blu_ld_decision_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hist3gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_hist2gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_hist1gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_hist0gain:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_decision_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hist7gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_hist6gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_hist5gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_hist4gain:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_decision_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_decaccess_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  ld_decaccess_addr:9;
        RBus_UInt32  res2:7;
    };
}blu_ld_decision_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_decaccess_data:30;
        RBus_UInt32  res1:2;
    };
}blu_ld_decision_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialcoef7:4;
        RBus_UInt32  ld_spatialcoef6:4;
        RBus_UInt32  ld_spatialcoef5:4;
        RBus_UInt32  ld_spatialcoef4:4;
        RBus_UInt32  ld_spatialcoef3:4;
        RBus_UInt32  ld_spatialcoef2:4;
        RBus_UInt32  ld_spatialcoef1:4;
        RBus_UInt32  ld_spatialcoef0:4;
    };
}blu_ld_spatial_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialremapen:1;
        RBus_UInt32  ld_spatialremapbusy:1;
        RBus_UInt32  ld_backlightboosten:1;
        RBus_UInt32  dummy1802c254_19_3:17;
        RBus_UInt32  ld_spatialcoef10:4;
        RBus_UInt32  ld_spatialcoef9:4;
        RBus_UInt32  ld_spatialcoef8:4;
    };
}blu_ld_spatial_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialnewcoef04:6;
        RBus_UInt32  ld_spatialnewcoef03:6;
        RBus_UInt32  ld_spatialnewcoef02:6;
        RBus_UInt32  ld_spatialnewcoef01:6;
        RBus_UInt32  ld_spatialnewcoef00:6;
        RBus_UInt32  spatial_new_mode:1;
        RBus_UInt32  res1:1;
    };
}blu_ld_spatial_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialnewcoef14:6;
        RBus_UInt32  ld_spatialnewcoef13:6;
        RBus_UInt32  ld_spatialnewcoef12:6;
        RBus_UInt32  ld_spatialnewcoef11:6;
        RBus_UInt32  ld_spatialnewcoef10:6;
        RBus_UInt32  res1:2;
    };
}blu_ld_spatial_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialnewcoef24:6;
        RBus_UInt32  ld_spatialnewcoef23:6;
        RBus_UInt32  ld_spatialnewcoef22:6;
        RBus_UInt32  ld_spatialnewcoef21:6;
        RBus_UInt32  ld_spatialnewcoef20:6;
        RBus_UInt32  res1:2;
    };
}blu_ld_spatial_ctrl7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialnewcoef34:6;
        RBus_UInt32  ld_spatialnewcoef33:6;
        RBus_UInt32  ld_spatialnewcoef32:6;
        RBus_UInt32  ld_spatialnewcoef31:6;
        RBus_UInt32  ld_spatialnewcoef30:6;
        RBus_UInt32  res1:2;
    };
}blu_ld_spatial_ctrl8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialnewcoef35:6;
        RBus_UInt32  ld_spatialnewcoef25:6;
        RBus_UInt32  ld_spatialnewcoef15:6;
        RBus_UInt32  ld_spatialnewcoef05:6;
        RBus_UInt32  res1:8;
    };
}blu_ld_spatial_ctrl9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialnewcoef50:6;
        RBus_UInt32  ld_spatialnewcoef41:6;
        RBus_UInt32  ld_spatialnewcoef40:6;
        RBus_UInt32  res1:14;
    };
}blu_ld_spatial_ctrla_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_lut_column_addr:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  ld_lut_row_addr:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_lut_adr_mode:1;
        RBus_UInt32  ld_lut_ax_mode:1;
        RBus_UInt32  ld_lut_ax_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ld_data_comp_mode:1;
        RBus_UInt32  ld_comp_2dlut_maxmode:1;
        RBus_UInt32  res4:12;
    };
}blu_ld_data_comp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_lut_data:28;
        RBus_UInt32  res1:4;
    };
}blu_ld_lut_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialremaptab0:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_spatialremaptab1:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_spatialremapadr:7;
        RBus_UInt32  res3:1;
    };
}blu_ld_spatial_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_bl_avg_shift:9;
        RBus_UInt32  res1:23;
    };
}blu_ld_backlight_average_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialremaptab_initial:10;
        RBus_UInt32  ld_spatialremaptab_initial2:10;
        RBus_UInt32  ld_spatialremaptab_initial3:10;
        RBus_UInt32  res1:2;
    };
}blu_ld_spatial_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_aplmax_start:1;
        RBus_UInt32  ld_aplmax_conti:1;
        RBus_UInt32  res1:30;
    };
}blu_ld_apl_read_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_aplmax_access_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  ld_aplmax_addr:9;
        RBus_UInt32  res2:7;
    };
}blu_ld_apl_read_max_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_aplmaxaccess_data:30;
        RBus_UInt32  res1:2;
    };
}blu_ld_apl_read_max_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_aplave_start:1;
        RBus_UInt32  ld_aplave_conti:1;
        RBus_UInt32  res1:30;
    };
}blu_ld_apl_read_ave_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_aplave_access_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  ld_aplave_addr:9;
        RBus_UInt32  res2:7;
    };
}blu_ld_apl_read_ave_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_aplaveaccess_data:30;
        RBus_UInt32  res1:2;
    };
}blu_ld_apl_read_ave_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tmp_posmaxgain:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_tmp_posmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_pos1thd:8;
        RBus_UInt32  ld_tmp_pos0thd:8;
    };
}blu_ld_temporal_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tmp_negmaxgain:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_tmp_negmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_neg1thd:8;
        RBus_UInt32  ld_tmp_neg0thd:8;
    };
}blu_ld_temporal_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ld_tmp_scenechangegain1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_maxdiff:8;
        RBus_UInt32  res3:8;
    };
}blu_ld_temporal_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blu_usergain:8;
        RBus_UInt32  ld_blu_nodim:1;
        RBus_UInt32  ld_blu_spien:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  ld_blu_spitotal:9;
        RBus_UInt32  ld_blu_wr_num:7;
    };
}blu_ld_backlight_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_debugmode:2;
        RBus_UInt32  ld_comp_maxmode:2;
        RBus_UInt32  ld_softcomp_gain:4;
        RBus_UInt32  ld_comp_minlimit:8;
        RBus_UInt32  ld_comp_softmax:8;
        RBus_UInt32  ld_comp_satrange:8;
    };
}blu_ld_datacomp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_srcgainsel:3;
        RBus_UInt32  res1:13;
        RBus_UInt32  ld_comp_inv_mode:1;
        RBus_UInt32  ld_comp_inv_shift:3;
        RBus_UInt32  dummy1802c270_31_20:12;
    };
}blu_ld_datacomp_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hfactor:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_tab_hsize:8;
    };
}blu_ld_inter_hctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hinitphase3_left:8;
        RBus_UInt32  ld_hinitphase2:8;
        RBus_UInt32  ld_hinitphase1:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_hboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_hinitphase3_right:8;
    };
}blu_ld_inter_hctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vfactor:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_tab_vsize:8;
    };
}blu_ld_inter_vctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vinitphase3_left:8;
        RBus_UInt32  ld_vinitphase2:8;
        RBus_UInt32  ld_vinitphase1:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_vboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_vinitphase3_right:8;
    };
}blu_ld_inter_vctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtab_adr:9;
        RBus_UInt32  dummy1802c284_31_9:23;
    };
}blu_ld_vtab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtab_dat_lsb:10;
        RBus_UInt32  dummy1802c288_15_10:6;
        RBus_UInt32  ld_vtab_dat_msb:10;
        RBus_UInt32  dummy1802c288_31_26:6;
    };
}blu_ld_vtab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htab_adr:9;
        RBus_UInt32  dummy1802c28c_31_9:23;
    };
}blu_ld_htab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htab_dat_lsb:10;
        RBus_UInt32  dummy1802c290_15_10:6;
        RBus_UInt32  ld_htab_dat_msb:10;
        RBus_UInt32  dummy1802c290_31_26:6;
    };
}blu_ld_htab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_table_sw_mode:1;
        RBus_UInt32  ld_blight_sw_mode:1;
        RBus_UInt32  ld_blight_update_en:1;
        RBus_UInt32  dummy1802c294_31_3:29;
    };
}blu_ld_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blight_adr:8;
        RBus_UInt32  dummy1802c298_31_8:24;
    };
}blu_ld_blight_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blight_dat_lsb:10;
        RBus_UInt32  dummy1802c29c_15_10:6;
        RBus_UInt32  ld_blight_dat_msb:10;
        RBus_UInt32  dummy1802c29c_31_26:6;
    };
}blu_ld_blight_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_0:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_4:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_11:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_9:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_8:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_15:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_13:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_12:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_19:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_17:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_16:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_23:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_21:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_20:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_27:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_25:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_24:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_31:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_29:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_28:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_0:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_4:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_11:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_9:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_8:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_15:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_13:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_12:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_19:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_17:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_16:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_23:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_21:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_20:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_27:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_25:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_24:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_31:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_29:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_28:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_demo_bottom:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_demo_top:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_demo_mode:1;
        RBus_UInt32  ld_demo_en:1;
    };
}blu_ld_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_demo_right:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_demo_left:13;
        RBus_UInt32  res2:3;
    };
}blu_ld_demo_window_ctrl1_RBUS;




#endif 


#endif 
