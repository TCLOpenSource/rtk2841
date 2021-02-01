/**
* @file rbusDFE_HDMI_RX_PHYReg_P0.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DFE_HDMI_RX_PHY_REG_P0_H_
#define _RBUS_DFE_HDMI_RX_PHY_REG_P0_H_

#include "rbus_types.h"



//  DFE_HDMI_RX_PHY Register Address
#define  DFE_HDMI_RX_PHY_BG                                                      0x1800DA00
#define  DFE_HDMI_RX_PHY_BG_reg_addr                                             "0xB800DA00"
#define  DFE_HDMI_RX_PHY_BG_reg                                                  0xB800DA00
#define  DFE_HDMI_RX_PHY_BG_inst_addr                                            "0x0000"
#define  set_DFE_HDMI_RX_PHY_BG_reg(data)                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_BG_reg)=data)
#define  get_DFE_HDMI_RX_PHY_BG_reg                                              (*((volatile unsigned int*)DFE_HDMI_RX_PHY_BG_reg))
#define  DFE_HDMI_RX_PHY_BG_reg_bg_rbgloop2_shift                                (7)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_rbg_shift                                     (4)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_rbg2_shift                                    (2)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_pow_shift                                     (1)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_envbgup_shift                                 (0)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_rbgloop2_mask                                 (0x00000380)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_rbg_mask                                      (0x00000070)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_rbg2_mask                                     (0x0000000C)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_pow_mask                                      (0x00000002)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_envbgup_mask                                  (0x00000001)
#define  DFE_HDMI_RX_PHY_BG_reg_bg_rbgloop2(data)                                (0x00000380&((data)<<7))
#define  DFE_HDMI_RX_PHY_BG_reg_bg_rbg(data)                                     (0x00000070&((data)<<4))
#define  DFE_HDMI_RX_PHY_BG_reg_bg_rbg2(data)                                    (0x0000000C&((data)<<2))
#define  DFE_HDMI_RX_PHY_BG_reg_bg_pow(data)                                     (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_BG_reg_bg_envbgup(data)                                 (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_BG_get_reg_bg_rbgloop2(data)                            ((0x00000380&(data))>>7)
#define  DFE_HDMI_RX_PHY_BG_get_reg_bg_rbg(data)                                 ((0x00000070&(data))>>4)
#define  DFE_HDMI_RX_PHY_BG_get_reg_bg_rbg2(data)                                ((0x0000000C&(data))>>2)
#define  DFE_HDMI_RX_PHY_BG_get_reg_bg_pow(data)                                 ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_BG_get_reg_bg_envbgup(data)                             (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_P0P1_MD                                                 0x1800DA04
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_addr                                        "0xB800DA04"
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg                                             0xB800DA04
#define  DFE_HDMI_RX_PHY_P0P1_MD_inst_addr                                       "0x0001"
#define  set_DFE_HDMI_RX_PHY_P0P1_MD_reg(data)                                   (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_MD_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0P1_MD_reg                                         (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_MD_reg))
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_ck_latch_shift                              (5)
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_ck_cmp_shift                                (4)
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_ck_det_shift                                (0)
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_ck_latch_mask                               (0x00000020)
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_ck_cmp_mask                                 (0x00000010)
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_ck_det_mask                                 (0x00000003)
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_ck_latch(data)                              (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_ck_cmp(data)                                (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_P0P1_MD_reg_ck_det(data)                                (0x00000003&(data))
#define  DFE_HDMI_RX_PHY_P0P1_MD_get_reg_ck_latch(data)                          ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_P0P1_MD_get_reg_ck_cmp(data)                            ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_P0P1_MD_get_reg_ck_det(data)                            (0x00000003&(data))

#define  DFE_HDMI_RX_PHY_P0_LDO                                                  0x1800DA08
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_addr                                         "0xB800DA08"
#define  DFE_HDMI_RX_PHY_P0_LDO_reg                                              0xB800DA08
#define  DFE_HDMI_RX_PHY_P0_LDO_inst_addr                                        "0x0002"
#define  set_DFE_HDMI_RX_PHY_P0_LDO_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_LDO_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_LDO_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_LDO_reg))
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_ldo_mossel_shift                             (12)
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_p0_ldo_sel_shift                             (4)
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_p0_ldo_pow_shift                             (0)
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_ldo_mossel_mask                              (0x00007000)
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_p0_ldo_sel_mask                              (0x00000030)
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_p0_ldo_pow_mask                              (0x00000001)
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_ldo_mossel(data)                             (0x00007000&((data)<<12))
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_p0_ldo_sel(data)                             (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_P0_LDO_reg_p0_ldo_pow(data)                             (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_P0_LDO_get_reg_ldo_mossel(data)                         ((0x00007000&(data))>>12)
#define  DFE_HDMI_RX_PHY_P0_LDO_get_reg_p0_ldo_sel(data)                         ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_P0_LDO_get_reg_p0_ldo_pow(data)                         (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_P0P1_MHL                                                0x1800DA0C
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_addr                                       "0xB800DA0C"
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg                                            0xB800DA0C
#define  DFE_HDMI_RX_PHY_P0P1_MHL_inst_addr                                      "0x0003"
#define  set_DFE_HDMI_RX_PHY_P0P1_MHL_reg(data)                                  (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_MHL_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0P1_MHL_reg                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_MHL_reg))
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_mhlz0en_0_shift                            (7)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_mhlz0en_1_shift                            (5)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_hdmi_cksel_shift                    (3)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_hdmi_datasel_shift                  (2)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_pow_shift                           (1)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_mhlz0en_0_mask                             (0x00000180)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_mhlz0en_1_mask                             (0x00000060)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_hdmi_cksel_mask                     (0x00000008)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_hdmi_datasel_mask                   (0x00000004)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_pow_mask                            (0x00000002)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_mhlz0en_0(data)                            (0x00000180&((data)<<7))
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_mhlz0en_1(data)                            (0x00000060&((data)<<5))
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_hdmi_cksel(data)                    (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_hdmi_datasel(data)                  (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_P0P1_MHL_reg_p0_mhl_pow(data)                           (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_P0P1_MHL_get_reg_mhlz0en_0(data)                        ((0x00000180&(data))>>7)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_get_reg_mhlz0en_1(data)                        ((0x00000060&(data))>>5)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_get_reg_p0_mhl_hdmi_cksel(data)                ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_get_reg_p0_mhl_hdmi_datasel(data)              ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_P0P1_MHL_get_reg_p0_mhl_pow(data)                       ((0x00000002&(data))>>1)

#define  DFE_HDMI_RX_PHY_P0_ENABLE                                               0x1800DA10
#define  DFE_HDMI_RX_PHY_P0_ENABLE_reg_addr                                      "0xB800DA10"
#define  DFE_HDMI_RX_PHY_P0_ENABLE_reg                                           0xB800DA10
#define  DFE_HDMI_RX_PHY_P0_ENABLE_inst_addr                                     "0x0004"
#define  set_DFE_HDMI_RX_PHY_P0_ENABLE_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_ENABLE_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_ENABLE_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_ENABLE_reg))
#define  DFE_HDMI_RX_PHY_P0_ENABLE_reg_p0_en_cmu_shift                           (3)
#define  DFE_HDMI_RX_PHY_P0_ENABLE_reg_p0_en_cmu_mask                            (0x00000008)
#define  DFE_HDMI_RX_PHY_P0_ENABLE_reg_p0_en_cmu(data)                           (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_P0_ENABLE_get_reg_p0_en_cmu(data)                       ((0x00000008&(data))>>3)

#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN                                             0x1800DA18
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_addr                                    "0xB800DA18"
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg                                         0xB800DA18
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_inst_addr                                   "0x0005"
#define  set_DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg(data)                               (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg))
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_4_shift                          (24)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_3_shift                          (16)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_2_shift                          (8)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_1_shift                          (0)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_4_mask                           (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_3_mask                           (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_2_mask                           (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_1_mask                           (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_4(data)                          (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_3(data)                          (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_2(data)                          (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg_top_in_1(data)                          (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_get_reg_top_in_4(data)                      ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_get_reg_top_in_3(data)                      ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_get_reg_top_in_2(data)                      ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_IN_get_reg_top_in_1(data)                      (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0P1_TOP_OUT                                            0x1800DA1C
#define  DFE_HDMI_RX_PHY_P0P1_TOP_OUT_reg_addr                                   "0xB800DA1C"
#define  DFE_HDMI_RX_PHY_P0P1_TOP_OUT_reg                                        0xB800DA1C
#define  DFE_HDMI_RX_PHY_P0P1_TOP_OUT_inst_addr                                  "0x0006"
#define  set_DFE_HDMI_RX_PHY_P0P1_TOP_OUT_reg(data)                              (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_TOP_OUT_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0P1_TOP_OUT_reg                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_TOP_OUT_reg))
#define  DFE_HDMI_RX_PHY_P0P1_TOP_OUT_reg_top_out_4_shift                        (24)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_OUT_reg_top_out_4_mask                         (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0P1_TOP_OUT_reg_top_out_4(data)                        (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0P1_TOP_OUT_get_reg_top_out_4(data)                    ((0xFF000000&(data))>>24)

#define  DFE_HDMI_RX_PHY_P0P1_Z0POW                                              0x1800DA20
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_addr                                     "0xB800DA20"
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg                                          0xB800DA20
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_inst_addr                                    "0x0007"
#define  set_DFE_HDMI_RX_PHY_P0P1_Z0POW_reg(data)                                (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_Z0POW_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0P1_Z0POW_reg                                      (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0P1_Z0POW_reg))
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_sel_shift                        (18)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_pow_shift                        (15)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z100_en_shift                         (12)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_r_shift                         (9)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_g_shift                         (6)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_ck_shift                        (3)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_b_shift                         (0)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_sel_mask                         (0x000C0000)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_pow_mask                         (0x00018000)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z100_en_mask                          (0x00003000)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_r_mask                          (0x00000600)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_g_mask                          (0x000000C0)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_ck_mask                         (0x00000018)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_b_mask                          (0x00000003)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_sel(data)                        (0x000C0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_pow(data)                        (0x00018000&((data)<<15))
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z100_en(data)                         (0x00003000&((data)<<12))
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_r(data)                         (0x00000600&((data)<<9))
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_g(data)                         (0x000000C0&((data)<<6))
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_ck(data)                        (0x00000018&((data)<<3))
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_b(data)                         (0x00000003&(data))
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_get_reg_z0_z300_sel(data)                    ((0x000C0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_get_reg_z0_z300_pow(data)                    ((0x00018000&(data))>>15)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_get_reg_z0_z100_en(data)                     ((0x00003000&(data))>>12)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_get_reg_z0_z0pow_r(data)                     ((0x00000600&(data))>>9)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_get_reg_z0_z0pow_g(data)                     ((0x000000C0&(data))>>6)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_get_reg_z0_z0pow_ck(data)                    ((0x00000018&(data))>>3)
#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_get_reg_z0_z0pow_b(data)                     (0x00000003&(data))

#define  DFE_HDMI_RX_PHY_P0_Z0K                                                  0x1800DA24
#define  DFE_HDMI_RX_PHY_P0_Z0K_reg_addr                                         "0xB800DA24"
#define  DFE_HDMI_RX_PHY_P0_Z0K_reg                                              0xB800DA24
#define  DFE_HDMI_RX_PHY_P0_Z0K_inst_addr                                        "0x0008"
#define  set_DFE_HDMI_RX_PHY_P0_Z0K_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_Z0K_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_Z0K_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_Z0K_reg))
#define  DFE_HDMI_RX_PHY_P0_Z0K_reg_z0_adjr_0_shift                              (4)
#define  DFE_HDMI_RX_PHY_P0_Z0K_reg_z0_adjr_0_mask                               (0x000001F0)
#define  DFE_HDMI_RX_PHY_P0_Z0K_reg_z0_adjr_0(data)                              (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_P0_Z0K_get_reg_z0_adjr_0(data)                          ((0x000001F0&(data))>>4)

#define  DFE_HDMI_RX_PHY_P0_B1                                                   0x1800DA40
#define  DFE_HDMI_RX_PHY_P0_B1_reg_addr                                          "0xB800DA40"
#define  DFE_HDMI_RX_PHY_P0_B1_reg                                               0xB800DA40
#define  DFE_HDMI_RX_PHY_P0_B1_inst_addr                                         "0x0009"
#define  set_DFE_HDMI_RX_PHY_P0_B1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_B1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_B1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_B1_reg))
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_B1_reg_p0_b_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_B1_get_reg_p0_b_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_B1_get_reg_p0_b_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_B1_get_reg_p0_b_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_B1_get_reg_p0_b_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_B2                                                   0x1800DA44
#define  DFE_HDMI_RX_PHY_P0_B2_reg_addr                                          "0xB800DA44"
#define  DFE_HDMI_RX_PHY_P0_B2_reg                                               0xB800DA44
#define  DFE_HDMI_RX_PHY_P0_B2_inst_addr                                         "0x000A"
#define  set_DFE_HDMI_RX_PHY_P0_B2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_B2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_B2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_B2_reg))
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_B2_reg_p0_b_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_B2_get_reg_p0_b_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_B2_get_reg_p0_b_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_B2_get_reg_p0_b_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_B2_get_reg_p0_b_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_B3                                                   0x1800DA48
#define  DFE_HDMI_RX_PHY_P0_B3_reg_addr                                          "0xB800DA48"
#define  DFE_HDMI_RX_PHY_P0_B3_reg                                               0xB800DA48
#define  DFE_HDMI_RX_PHY_P0_B3_inst_addr                                         "0x000B"
#define  set_DFE_HDMI_RX_PHY_P0_B3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_B3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_B3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_B3_reg))
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_B3_reg_p0_b_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_B3_get_reg_p0_b_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_B3_get_reg_p0_b_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_B3_get_reg_p0_b_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_B3_get_reg_p0_b_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_B4                                                   0x1800DA4C
#define  DFE_HDMI_RX_PHY_P0_B4_reg_addr                                          "0xB800DA4C"
#define  DFE_HDMI_RX_PHY_P0_B4_reg                                               0xB800DA4C
#define  DFE_HDMI_RX_PHY_P0_B4_inst_addr                                         "0x000C"
#define  set_DFE_HDMI_RX_PHY_P0_B4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_B4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_B4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_B4_reg))
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_B4_get_reg_p0_b_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P0_B4_get_reg_p0_b_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P0_B4_get_reg_p0_b_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_B4_get_reg_p0_b_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_CK1                                                  0x1800DA50
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_addr                                         "0xB800DA50"
#define  DFE_HDMI_RX_PHY_P0_CK1_reg                                              0xB800DA50
#define  DFE_HDMI_RX_PHY_P0_CK1_inst_addr                                        "0x000D"
#define  set_DFE_HDMI_RX_PHY_P0_CK1_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_CK1_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK1_reg))
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_4_shift                                (24)
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_3_shift                                (16)
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_2_shift                                (8)
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_1_shift                                (0)
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_4_mask                                 (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_3_mask                                 (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_2_mask                                 (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_1_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_4(data)                                (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_3(data)                                (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_2(data)                                (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_1(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_CK1_get_reg_p0_ck_4(data)                            ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_CK1_get_reg_p0_ck_3(data)                            ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_CK1_get_reg_p0_ck_2(data)                            ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_CK1_get_reg_p0_ck_1(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_CK2                                                  0x1800DA54
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_addr                                         "0xB800DA54"
#define  DFE_HDMI_RX_PHY_P0_CK2_reg                                              0xB800DA54
#define  DFE_HDMI_RX_PHY_P0_CK2_inst_addr                                        "0x000E"
#define  set_DFE_HDMI_RX_PHY_P0_CK2_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_CK2_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK2_reg))
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_8_shift                                (24)
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_7_shift                                (16)
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_6_shift                                (8)
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_5_shift                                (0)
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_8_mask                                 (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_7_mask                                 (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_6_mask                                 (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_5_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_8(data)                                (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_7(data)                                (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_6(data)                                (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_CK2_reg_p0_ck_5(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_CK2_get_reg_p0_ck_8(data)                            ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_CK2_get_reg_p0_ck_7(data)                            ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_CK2_get_reg_p0_ck_6(data)                            ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_CK2_get_reg_p0_ck_5(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_CK3                                                  0x1800DA58
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_addr                                         "0xB800DA58"
#define  DFE_HDMI_RX_PHY_P0_CK3_reg                                              0xB800DA58
#define  DFE_HDMI_RX_PHY_P0_CK3_inst_addr                                        "0x000F"
#define  set_DFE_HDMI_RX_PHY_P0_CK3_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_CK3_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK3_reg))
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_12_shift                               (24)
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_11_shift                               (16)
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_10_shift                               (8)
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_9_shift                                (0)
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_12_mask                                (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_11_mask                                (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_10_mask                                (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_9_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_12(data)                               (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_11(data)                               (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_10(data)                               (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_CK3_reg_p0_ck_9(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_CK3_get_reg_p0_ck_12(data)                           ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_CK3_get_reg_p0_ck_11(data)                           ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_CK3_get_reg_p0_ck_10(data)                           ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_CK3_get_reg_p0_ck_9(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_CK4                                                  0x1800DA5C
#define  DFE_HDMI_RX_PHY_P0_CK4_reg_addr                                         "0xB800DA5C"
#define  DFE_HDMI_RX_PHY_P0_CK4_reg                                              0xB800DA5C
#define  DFE_HDMI_RX_PHY_P0_CK4_inst_addr                                        "0x0010"
#define  set_DFE_HDMI_RX_PHY_P0_CK4_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_CK4_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK4_reg))
#define  DFE_HDMI_RX_PHY_P0_CK4_reg_p0_ck_13_shift                               (0)
#define  DFE_HDMI_RX_PHY_P0_CK4_reg_p0_ck_13_mask                                (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_CK4_reg_p0_ck_13(data)                               (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_CK4_get_reg_p0_ck_13(data)                           (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_G1                                                   0x1800DA60
#define  DFE_HDMI_RX_PHY_P0_G1_reg_addr                                          "0xB800DA60"
#define  DFE_HDMI_RX_PHY_P0_G1_reg                                               0xB800DA60
#define  DFE_HDMI_RX_PHY_P0_G1_inst_addr                                         "0x0011"
#define  set_DFE_HDMI_RX_PHY_P0_G1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_G1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_G1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_G1_reg))
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_G1_reg_p0_g_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_G1_get_reg_p0_g_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_G1_get_reg_p0_g_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_G1_get_reg_p0_g_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_G1_get_reg_p0_g_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_G2                                                   0x1800DA64
#define  DFE_HDMI_RX_PHY_P0_G2_reg_addr                                          "0xB800DA64"
#define  DFE_HDMI_RX_PHY_P0_G2_reg                                               0xB800DA64
#define  DFE_HDMI_RX_PHY_P0_G2_inst_addr                                         "0x0012"
#define  set_DFE_HDMI_RX_PHY_P0_G2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_G2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_G2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_G2_reg))
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_G2_reg_p0_g_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_G2_get_reg_p0_g_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_G2_get_reg_p0_g_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_G2_get_reg_p0_g_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_G2_get_reg_p0_g_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_G3                                                   0x1800DA68
#define  DFE_HDMI_RX_PHY_P0_G3_reg_addr                                          "0xB800DA68"
#define  DFE_HDMI_RX_PHY_P0_G3_reg                                               0xB800DA68
#define  DFE_HDMI_RX_PHY_P0_G3_inst_addr                                         "0x0013"
#define  set_DFE_HDMI_RX_PHY_P0_G3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_G3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_G3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_G3_reg))
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_G3_reg_p0_g_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_G3_get_reg_p0_g_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_G3_get_reg_p0_g_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_G3_get_reg_p0_g_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_G3_get_reg_p0_g_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_G4                                                   0x1800DA6C
#define  DFE_HDMI_RX_PHY_P0_G4_reg_addr                                          "0xB800DA6C"
#define  DFE_HDMI_RX_PHY_P0_G4_reg                                               0xB800DA6C
#define  DFE_HDMI_RX_PHY_P0_G4_inst_addr                                         "0x0014"
#define  set_DFE_HDMI_RX_PHY_P0_G4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_G4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_G4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_G4_reg))
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_G4_reg_p0_g_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_G4_get_reg_p0_g_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P0_G4_get_reg_p0_g_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P0_G4_get_reg_p0_g_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_G4_get_reg_p0_g_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_R1                                                   0x1800DA70
#define  DFE_HDMI_RX_PHY_P0_R1_reg_addr                                          "0xB800DA70"
#define  DFE_HDMI_RX_PHY_P0_R1_reg                                               0xB800DA70
#define  DFE_HDMI_RX_PHY_P0_R1_inst_addr                                         "0x0015"
#define  set_DFE_HDMI_RX_PHY_P0_R1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_R1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_R1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_R1_reg))
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_R1_reg_p0_r_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_R1_get_reg_p0_r_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_R1_get_reg_p0_r_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_R1_get_reg_p0_r_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_R1_get_reg_p0_r_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_R2                                                   0x1800DA74
#define  DFE_HDMI_RX_PHY_P0_R2_reg_addr                                          "0xB800DA74"
#define  DFE_HDMI_RX_PHY_P0_R2_reg                                               0xB800DA74
#define  DFE_HDMI_RX_PHY_P0_R2_inst_addr                                         "0x0016"
#define  set_DFE_HDMI_RX_PHY_P0_R2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_R2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_R2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_R2_reg))
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_R2_reg_p0_r_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_R2_get_reg_p0_r_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_R2_get_reg_p0_r_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_R2_get_reg_p0_r_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_R2_get_reg_p0_r_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_R3                                                   0x1800DA78
#define  DFE_HDMI_RX_PHY_P0_R3_reg_addr                                          "0xB800DA78"
#define  DFE_HDMI_RX_PHY_P0_R3_reg                                               0xB800DA78
#define  DFE_HDMI_RX_PHY_P0_R3_inst_addr                                         "0x0017"
#define  set_DFE_HDMI_RX_PHY_P0_R3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_R3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_R3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_R3_reg))
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_R3_reg_p0_r_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_R3_get_reg_p0_r_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_R3_get_reg_p0_r_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_R3_get_reg_p0_r_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_R3_get_reg_p0_r_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_R4                                                   0x1800DA7C
#define  DFE_HDMI_RX_PHY_P0_R4_reg_addr                                          "0xB800DA7C"
#define  DFE_HDMI_RX_PHY_P0_R4_reg                                               0xB800DA7C
#define  DFE_HDMI_RX_PHY_P0_R4_inst_addr                                         "0x0018"
#define  set_DFE_HDMI_RX_PHY_P0_R4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_R4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_R4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_R4_reg))
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_R4_reg_p0_r_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_R4_get_reg_p0_r_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P0_R4_get_reg_p0_r_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P0_R4_get_reg_p0_r_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_R4_get_reg_p0_r_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_RST                                                  0x1800DA80
#define  DFE_HDMI_RX_PHY_P0_RST_reg_addr                                         "0xB800DA80"
#define  DFE_HDMI_RX_PHY_P0_RST_reg                                              0xB800DA80
#define  DFE_HDMI_RX_PHY_P0_RST_inst_addr                                        "0x0019"
#define  set_DFE_HDMI_RX_PHY_P0_RST_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_RST_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_RST_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_RST_reg))
#define  DFE_HDMI_RX_PHY_P0_RST_p0_r_demux_rstb_shift                            (2)
#define  DFE_HDMI_RX_PHY_P0_RST_p0_g_demux_rstb_shift                            (1)
#define  DFE_HDMI_RX_PHY_P0_RST_p0_b_demux_rstb_shift                            (0)
#define  DFE_HDMI_RX_PHY_P0_RST_p0_r_demux_rstb_mask                             (0x00000004)
#define  DFE_HDMI_RX_PHY_P0_RST_p0_g_demux_rstb_mask                             (0x00000002)
#define  DFE_HDMI_RX_PHY_P0_RST_p0_b_demux_rstb_mask                             (0x00000001)
#define  DFE_HDMI_RX_PHY_P0_RST_p0_r_demux_rstb(data)                            (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_P0_RST_p0_g_demux_rstb(data)                            (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_P0_RST_p0_b_demux_rstb(data)                            (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_P0_RST_get_p0_r_demux_rstb(data)                        ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_P0_RST_get_p0_g_demux_rstb(data)                        ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_P0_RST_get_p0_b_demux_rstb(data)                        (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD00                                               0x1800DA90
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_addr                                      "0xB800DA90"
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg                                           0xB800DA90
#define  DFE_HDMI_RX_PHY_P0_REGD00_inst_addr                                     "0x001A"
#define  set_DFE_HDMI_RX_PHY_P0_REGD00_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD00_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD00_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD00_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_r_dig_rst_n_shift                          (31)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_g_dig_rst_n_shift                          (30)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_b_dig_rst_n_shift                          (29)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_r_cdr_rst_n_shift                          (28)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_g_cdr_rst_n_shift                          (27)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_b_cdr_rst_n_shift                          (26)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_cdr_ckinv_r_shift                      (25)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_cdr_ckinv_g_shift                      (24)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_cdr_ckinv_b_shift                      (23)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_shift_inv_r_shift                      (22)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_shift_inv_g_shift                      (21)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_shift_inv_b_shift                      (20)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_rate_sel_shift                         (17)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kd_shift                               (16)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kp_shift                               (8)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_ki_shift                               (5)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_bypass_sdm_int_shift                   (4)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_data_order_shift                       (3)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_infifo_cnt_shift                       (0)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_r_dig_rst_n_mask                           (0x80000000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_g_dig_rst_n_mask                           (0x40000000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_b_dig_rst_n_mask                           (0x20000000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_r_cdr_rst_n_mask                           (0x10000000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_g_cdr_rst_n_mask                           (0x08000000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_b_cdr_rst_n_mask                           (0x04000000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_cdr_ckinv_r_mask                       (0x02000000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_cdr_ckinv_g_mask                       (0x01000000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_cdr_ckinv_b_mask                       (0x00800000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_shift_inv_r_mask                       (0x00400000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_shift_inv_g_mask                       (0x00200000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_shift_inv_b_mask                       (0x00100000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_rate_sel_mask                          (0x000E0000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kd_mask                                (0x00010000)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kp_mask                                (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_ki_mask                                (0x000000E0)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_bypass_sdm_int_mask                    (0x00000010)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_data_order_mask                        (0x00000008)
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_infifo_cnt_mask                        (0x00000007)
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_r_dig_rst_n(data)                          (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_g_dig_rst_n(data)                          (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_b_dig_rst_n(data)                          (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_r_cdr_rst_n(data)                          (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_g_cdr_rst_n(data)                          (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_P0_REGD00_p0_b_cdr_rst_n(data)                          (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_cdr_ckinv_r(data)                      (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_cdr_ckinv_g(data)                      (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_cdr_ckinv_b(data)                      (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_shift_inv_r(data)                      (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_shift_inv_g(data)                      (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_shift_inv_b(data)                      (0x00100000&((data)<<20))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_rate_sel(data)                         (0x000E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kd(data)                               (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kp(data)                               (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_ki(data)                               (0x000000E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_bypass_sdm_int(data)                   (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_data_order(data)                       (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_infifo_cnt(data)                       (0x00000007&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_p0_r_dig_rst_n(data)                      ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_p0_g_dig_rst_n(data)                      ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_p0_b_dig_rst_n(data)                      ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_p0_r_cdr_rst_n(data)                      ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_p0_g_cdr_rst_n(data)                      ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_p0_b_cdr_rst_n(data)                      ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_cdr_ckinv_r(data)                  ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_cdr_ckinv_g(data)                  ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_cdr_ckinv_b(data)                  ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_shift_inv_r(data)                  ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_shift_inv_g(data)                  ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_shift_inv_b(data)                  ((0x00100000&(data))>>20)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_rate_sel(data)                     ((0x000E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_kd(data)                           ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_kp(data)                           ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_ki(data)                           ((0x000000E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_bypass_sdm_int(data)               ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_data_order(data)                   ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_P0_REGD00_get_reg_p0_infifo_cnt(data)                   (0x00000007&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD01                                               0x1800DA94
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_addr                                      "0xB800DA94"
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg                                           0xB800DA94
#define  DFE_HDMI_RX_PHY_P0_REGD01_inst_addr                                     "0x001B"
#define  set_DFE_HDMI_RX_PHY_P0_REGD01_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD01_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD01_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD01_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_int_init_shift                         (18)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_acc2_period_shift                      (8)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_squ_tri_shift                          (7)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_acc2_manual_shift                      (6)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_testout_sel_shift                      (4)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_ercnt_en_shift                         (3)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_edge_out_shift                         (2)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_pi_m_mode_shift                        (1)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_dyn_kp_en_shift                        (0)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_int_init_mask                          (0xFFFC0000)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_acc2_period_mask                       (0x0003FF00)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_squ_tri_mask                           (0x00000080)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_acc2_manual_mask                       (0x00000040)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_testout_sel_mask                       (0x00000030)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_ercnt_en_mask                          (0x00000008)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_edge_out_mask                          (0x00000004)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_pi_m_mode_mask                         (0x00000002)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_dyn_kp_en_mask                         (0x00000001)
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_int_init(data)                         (0xFFFC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_acc2_period(data)                      (0x0003FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_squ_tri(data)                          (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_acc2_manual(data)                      (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_testout_sel(data)                      (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_ercnt_en(data)                         (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_edge_out(data)                         (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_pi_m_mode(data)                        (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_P0_REGD01_reg_p0_dyn_kp_en(data)                        (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD01_get_reg_p0_int_init(data)                     ((0xFFFC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P0_REGD01_get_reg_p0_acc2_period(data)                  ((0x0003FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_REGD01_get_reg_p0_squ_tri(data)                      ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_P0_REGD01_get_reg_p0_acc2_manual(data)                  ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_P0_REGD01_get_reg_p0_testout_sel(data)                  ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_P0_REGD01_get_reg_p0_ercnt_en(data)                     ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_P0_REGD01_get_reg_p0_edge_out(data)                     ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_P0_REGD01_get_reg_p0_pi_m_mode(data)                    ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_P0_REGD01_get_reg_p0_dyn_kp_en(data)                    (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD02                                               0x1800DA98
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_addr                                      "0xB800DA98"
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg                                           0xB800DA98
#define  DFE_HDMI_RX_PHY_P0_REGD02_inst_addr                                     "0x001C"
#define  set_DFE_HDMI_RX_PHY_P0_REGD02_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD02_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD02_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD02_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_en_m_value_shift                       (28)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_st_mode_shift                          (27)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_timer_lpf_shift                        (18)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_timer_eq_shift                         (13)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_timer_ber_shift                        (8)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_en_m_value_mask                        (0xF0000000)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_st_mode_mask                           (0x08000000)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_timer_lpf_mask                         (0x007C0000)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_timer_eq_mask                          (0x0003E000)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_timer_ber_mask                         (0x00001F00)
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_en_m_value(data)                       (0xF0000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_st_mode(data)                          (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_timer_lpf(data)                        (0x007C0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_timer_eq(data)                         (0x0003E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_P0_REGD02_reg_p0_timer_ber(data)                        (0x00001F00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_REGD02_get_reg_p0_en_m_value(data)                   ((0xF0000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_P0_REGD02_get_reg_p0_st_mode(data)                      ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_P0_REGD02_get_reg_p0_timer_lpf(data)                    ((0x007C0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P0_REGD02_get_reg_p0_timer_eq(data)                     ((0x0003E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_P0_REGD02_get_reg_p0_timer_ber(data)                    ((0x00001F00&(data))>>8)

#define  DFE_HDMI_RX_PHY_P0_REGD03                                               0x1800DA9C
#define  DFE_HDMI_RX_PHY_P0_REGD03_reg_addr                                      "0xB800DA9C"
#define  DFE_HDMI_RX_PHY_P0_REGD03_reg                                           0xB800DA9C
#define  DFE_HDMI_RX_PHY_P0_REGD03_inst_addr                                     "0x001D"
#define  set_DFE_HDMI_RX_PHY_P0_REGD03_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD03_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD03_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD03_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_st_ro_r_shift                              (24)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_en_ro_r_shift                              (20)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_st_ro_g_shift                              (14)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_en_ro_g_shift                              (10)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_st_ro_b_shift                              (4)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_en_ro_b_shift                              (0)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_st_ro_r_mask                               (0x1F000000)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_en_ro_r_mask                               (0x00F00000)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_st_ro_g_mask                               (0x0007C000)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_en_ro_g_mask                               (0x00003C00)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_st_ro_b_mask                               (0x000001F0)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_en_ro_b_mask                               (0x0000000F)
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_st_ro_r(data)                              (0x1F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_en_ro_r(data)                              (0x00F00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_st_ro_g(data)                              (0x0007C000&((data)<<14))
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_en_ro_g(data)                              (0x00003C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_st_ro_b(data)                              (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_P0_REGD03_p0_en_ro_b(data)                              (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD03_get_p0_st_ro_r(data)                          ((0x1F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_REGD03_get_p0_en_ro_r(data)                          ((0x00F00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_P0_REGD03_get_p0_st_ro_g(data)                          ((0x0007C000&(data))>>14)
#define  DFE_HDMI_RX_PHY_P0_REGD03_get_p0_en_ro_g(data)                          ((0x00003C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P0_REGD03_get_p0_st_ro_b(data)                          ((0x000001F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_P0_REGD03_get_p0_en_ro_b(data)                          (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD04                                               0x1800DAA0
#define  DFE_HDMI_RX_PHY_P0_REGD04_reg_addr                                      "0xB800DAA0"
#define  DFE_HDMI_RX_PHY_P0_REGD04_reg                                           0xB800DAA0
#define  DFE_HDMI_RX_PHY_P0_REGD04_inst_addr                                     "0x001E"
#define  set_DFE_HDMI_RX_PHY_P0_REGD04_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD04_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD04_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD04_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD04_p0_er_count_r_shift                           (20)
#define  DFE_HDMI_RX_PHY_P0_REGD04_p0_er_count_g_shift                           (10)
#define  DFE_HDMI_RX_PHY_P0_REGD04_p0_er_count_b_shift                           (0)
#define  DFE_HDMI_RX_PHY_P0_REGD04_p0_er_count_r_mask                            (0x3FF00000)
#define  DFE_HDMI_RX_PHY_P0_REGD04_p0_er_count_g_mask                            (0x000FFC00)
#define  DFE_HDMI_RX_PHY_P0_REGD04_p0_er_count_b_mask                            (0x000003FF)
#define  DFE_HDMI_RX_PHY_P0_REGD04_p0_er_count_r(data)                           (0x3FF00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_P0_REGD04_p0_er_count_g(data)                           (0x000FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P0_REGD04_p0_er_count_b(data)                           (0x000003FF&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD04_get_p0_er_count_r(data)                       ((0x3FF00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_P0_REGD04_get_p0_er_count_g(data)                       ((0x000FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P0_REGD04_get_p0_er_count_b(data)                       (0x000003FF&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD05                                               0x1800DAA4
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_addr                                      "0xB800DAA4"
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg                                           0xB800DAA4
#define  DFE_HDMI_RX_PHY_P0_REGD05_inst_addr                                     "0x001F"
#define  set_DFE_HDMI_RX_PHY_P0_REGD05_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD05_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD05_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD05_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_clk_rdy_shift                   (31)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_eqen_rdy_shift                  (30)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_data_rdy_shift                  (29)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_pi_shift                        (28)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_data_rdy_time_shift                    (24)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_clkout_manual_shift                 (23)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_eqen_manual_shift                   (22)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_data_manual_shift                   (21)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_eqen_rdy_time_shift                    (17)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_order_shift                            (16)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_base_time_shift                 (13)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_en_shift                        (12)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_rst_wid_shift                   (10)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_time_rdy_shift                  (8)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_acdr_l0_en_shift                       (7)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_eqen_rdy_l0_shift               (6)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_data_rdy_l0_shift               (5)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_eqen_manual_l0_shift                (4)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_data_manual_l0_shift                (3)
#define  DFE_HDMI_RX_PHY_P0_REGD05_p0_pll_wd_ckrdy_ro_shift                      (2)
#define  DFE_HDMI_RX_PHY_P0_REGD05_p0_pll_wd_rst_wc_shift                        (1)
#define  DFE_HDMI_RX_PHY_P0_REGD05_p0_wdog_rst_n_shift                           (0)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_clk_rdy_mask                    (0x80000000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_eqen_rdy_mask                   (0x40000000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_data_rdy_mask                   (0x20000000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_pi_mask                         (0x10000000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_data_rdy_time_mask                     (0x0F000000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_clkout_manual_mask                  (0x00800000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_eqen_manual_mask                    (0x00400000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_data_manual_mask                    (0x00200000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_eqen_rdy_time_mask                     (0x001E0000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_order_mask                             (0x00010000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_base_time_mask                  (0x0000E000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_en_mask                         (0x00001000)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_rst_wid_mask                    (0x00000C00)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_time_rdy_mask                   (0x00000300)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_acdr_l0_en_mask                        (0x00000080)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_eqen_rdy_l0_mask                (0x00000040)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_data_rdy_l0_mask                (0x00000020)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_eqen_manual_l0_mask                 (0x00000010)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_data_manual_l0_mask                 (0x00000008)
#define  DFE_HDMI_RX_PHY_P0_REGD05_p0_pll_wd_ckrdy_ro_mask                       (0x00000004)
#define  DFE_HDMI_RX_PHY_P0_REGD05_p0_pll_wd_rst_wc_mask                         (0x00000002)
#define  DFE_HDMI_RX_PHY_P0_REGD05_p0_wdog_rst_n_mask                            (0x00000001)
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_clk_rdy(data)                   (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_eqen_rdy(data)                  (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_data_rdy(data)                  (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_pi(data)                        (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_data_rdy_time(data)                    (0x0F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_clkout_manual(data)                 (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_eqen_manual(data)                   (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_data_manual(data)                   (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_eqen_rdy_time(data)                    (0x001E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_order(data)                            (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_base_time(data)                 (0x0000E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_en(data)                        (0x00001000&((data)<<12))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_rst_wid(data)                   (0x00000C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_pll_wd_time_rdy(data)                  (0x00000300&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_acdr_l0_en(data)                       (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_eqen_rdy_l0(data)               (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_bypass_data_rdy_l0(data)               (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_eqen_manual_l0(data)                (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_P0_REGD05_reg_p0_en_data_manual_l0(data)                (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_P0_REGD05_p0_pll_wd_ckrdy_ro(data)                      (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_P0_REGD05_p0_pll_wd_rst_wc(data)                        (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_P0_REGD05_p0_wdog_rst_n(data)                           (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_bypass_clk_rdy(data)               ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_bypass_eqen_rdy(data)              ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_bypass_data_rdy(data)              ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_bypass_pi(data)                    ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_data_rdy_time(data)                ((0x0F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_en_clkout_manual(data)             ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_en_eqen_manual(data)               ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_en_data_manual(data)               ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_eqen_rdy_time(data)                ((0x001E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_order(data)                        ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_pll_wd_base_time(data)             ((0x0000E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_pll_wd_en(data)                    ((0x00001000&(data))>>12)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_pll_wd_rst_wid(data)               ((0x00000C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_pll_wd_time_rdy(data)              ((0x00000300&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_acdr_l0_en(data)                   ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_bypass_eqen_rdy_l0(data)           ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_bypass_data_rdy_l0(data)           ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_en_eqen_manual_l0(data)            ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_reg_p0_en_data_manual_l0(data)            ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_p0_pll_wd_ckrdy_ro(data)                  ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_p0_pll_wd_rst_wc(data)                    ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_P0_REGD05_get_p0_wdog_rst_n(data)                       (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD06                                               0x1800DAA8
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_addr                                      "0xB800DAA8"
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg                                           0xB800DAA8
#define  DFE_HDMI_RX_PHY_P0_REGD06_inst_addr                                     "0x0020"
#define  set_DFE_HDMI_RX_PHY_P0_REGD06_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD06_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD06_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD06_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_wd_sdm_en_shift                        (31)
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_f_code_shift                           (16)
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_n_code_shift                           (0)
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_wd_sdm_en_mask                         (0x80000000)
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_f_code_mask                            (0x0FFF0000)
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_n_code_mask                            (0x000001FF)
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_wd_sdm_en(data)                        (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_f_code(data)                           (0x0FFF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_n_code(data)                           (0x000001FF&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD06_get_reg_p0_wd_sdm_en(data)                    ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_P0_REGD06_get_reg_p0_f_code(data)                       ((0x0FFF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_REGD06_get_reg_p0_n_code(data)                       (0x000001FF&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD07                                               0x1800DAAC
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_addr                                      "0xB800DAAC"
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg                                           0xB800DAAC
#define  DFE_HDMI_RX_PHY_P0_REGD07_inst_addr                                     "0x0021"
#define  set_DFE_HDMI_RX_PHY_P0_REGD07_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD07_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD07_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD07_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_shift                           (31)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_threshold_shift                  (25)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_debounce_shift                   (18)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_sel_shift                        (16)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_auto_shift                       (15)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_adj_shift                        (11)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_error_limit_shift                   (6)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_reserved_shift                   (2)
#define  DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_threshold_mask                   (0x7E000000)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_debounce_mask                    (0x01FC0000)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_sel_mask                         (0x00030000)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_auto_mask                        (0x00008000)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_adj_mask                         (0x00007800)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_error_limit_mask                    (0x000007C0)
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_reserved_mask                    (0x0000003C)
#define  DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_threshold(data)                  (0x7E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_debounce(data)                   (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_sel(data)                        (0x00030000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_auto(data)                       (0x00008000&((data)<<15))
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_adj(data)                        (0x00007800&((data)<<11))
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_error_limit(data)                   (0x000007C0&((data)<<6))
#define  DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_reserved(data)                   (0x0000003C&((data)<<2))
#define  DFE_HDMI_RX_PHY_P0_REGD07_get_p0_ck_md_rstb(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_threshold(data)              ((0x7E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_debounce(data)               ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_sel(data)                    ((0x00030000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_auto(data)                   ((0x00008000&(data))>>15)
#define  DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_adj(data)                    ((0x00007800&(data))>>11)
#define  DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_error_limit(data)               ((0x000007C0&(data))>>6)
#define  DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_reserved(data)               ((0x0000003C&(data))>>2)

#define  DFE_HDMI_RX_PHY_P0_REGD08                                               0x1800DAB0
#define  DFE_HDMI_RX_PHY_P0_REGD08_reg_addr                                      "0xB800DAB0"
#define  DFE_HDMI_RX_PHY_P0_REGD08_reg                                           0xB800DAB0
#define  DFE_HDMI_RX_PHY_P0_REGD08_inst_addr                                     "0x0022"
#define  set_DFE_HDMI_RX_PHY_P0_REGD08_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD08_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD08_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD08_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_count_shift                          (19)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_rate_shift                              (15)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_unstable_count_shift                       (10)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_ok_shift                             (9)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_clock_unstable_flag_shift                  (8)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_count_mask                           (0xFFF80000)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_rate_mask                               (0x00078000)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_unstable_count_mask                        (0x00007C00)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_ok_mask                              (0x00000200)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_clock_unstable_flag_mask                   (0x00000100)
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_count(data)                          (0xFFF80000&((data)<<19))
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_rate(data)                              (0x00078000&((data)<<15))
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_unstable_count(data)                       (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_ok(data)                             (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P0_REGD08_p0_clock_unstable_flag(data)                  (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_REGD08_get_p0_ck_md_count(data)                      ((0xFFF80000&(data))>>19)
#define  DFE_HDMI_RX_PHY_P0_REGD08_get_p0_ck_rate(data)                          ((0x00078000&(data))>>15)
#define  DFE_HDMI_RX_PHY_P0_REGD08_get_p0_unstable_count(data)                   ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P0_REGD08_get_p0_ck_md_ok(data)                         ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P0_REGD08_get_p0_clock_unstable_flag(data)              ((0x00000100&(data))>>8)

#define  DFE_HDMI_RX_PHY_P0_REGD09                                               0x1800DAB4
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_addr                                      "0xB800DAB4"
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg                                           0xB800DAB4
#define  DFE_HDMI_RX_PHY_P0_REGD09_inst_addr                                     "0x0023"
#define  set_DFE_HDMI_RX_PHY_P0_REGD09_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD09_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD09_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD09_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_p0_dig_debug_sel_shift                    (28)
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_dig_reserved_0_shift                      (20)
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_dig_reserved_2_shift                      (12)
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_p0_dig_debug_sel_mask                     (0xF0000000)
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_dig_reserved_0_mask                       (0x0FF00000)
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_dig_reserved_2_mask                       (0x000FF000)
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_p0_dig_debug_sel(data)                    (0xF0000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_dig_reserved_0(data)                      (0x0FF00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_P0_REGD09_reg_dig_reserved_2(data)                      (0x000FF000&((data)<<12))
#define  DFE_HDMI_RX_PHY_P0_REGD09_get_reg_p0_dig_debug_sel(data)                ((0xF0000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_P0_REGD09_get_reg_dig_reserved_0(data)                  ((0x0FF00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_P0_REGD09_get_reg_dig_reserved_2(data)                  ((0x000FF000&(data))>>12)

#define  DFE_HDMI_RX_PHY_P0_REGD10                                               0x1800DAB8
#define  DFE_HDMI_RX_PHY_P0_REGD10_reg_addr                                      "0xB800DAB8"
#define  DFE_HDMI_RX_PHY_P0_REGD10_reg                                           0xB800DAB8
#define  DFE_HDMI_RX_PHY_P0_REGD10_inst_addr                                     "0x0024"
#define  set_DFE_HDMI_RX_PHY_P0_REGD10_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD10_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD10_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD10_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD10_reg_p0_st_m_value_shift                       (0)
#define  DFE_HDMI_RX_PHY_P0_REGD10_reg_p0_st_m_value_mask                        (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_P0_REGD10_reg_p0_st_m_value(data)                       (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD10_get_reg_p0_st_m_value(data)                   (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD11                                               0x1800DABC
#define  DFE_HDMI_RX_PHY_P0_REGD11_reg_addr                                      "0xB800DABC"
#define  DFE_HDMI_RX_PHY_P0_REGD11_reg                                           0xB800DABC
#define  DFE_HDMI_RX_PHY_P0_REGD11_inst_addr                                     "0x0025"
#define  set_DFE_HDMI_RX_PHY_P0_REGD11_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD11_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD11_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD11_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD11_reg_p0_st_m_value_g_shift                     (0)
#define  DFE_HDMI_RX_PHY_P0_REGD11_reg_p0_st_m_value_g_mask                      (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_P0_REGD11_reg_p0_st_m_value_g(data)                     (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD11_get_reg_p0_st_m_value_g(data)                 (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD12                                               0x1800DAC0
#define  DFE_HDMI_RX_PHY_P0_REGD12_reg_addr                                      "0xB800DAC0"
#define  DFE_HDMI_RX_PHY_P0_REGD12_reg                                           0xB800DAC0
#define  DFE_HDMI_RX_PHY_P0_REGD12_inst_addr                                     "0x0026"
#define  set_DFE_HDMI_RX_PHY_P0_REGD12_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD12_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD12_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD12_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD12_reg_p0_st_m_value_b_shift                     (0)
#define  DFE_HDMI_RX_PHY_P0_REGD12_reg_p0_st_m_value_b_mask                      (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_P0_REGD12_reg_p0_st_m_value_b(data)                     (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD12_get_reg_p0_st_m_value_b(data)                 (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD13                                               0x1800DAC4
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_addr                                      "0xB800DAC4"
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg                                           0xB800DAC4
#define  DFE_HDMI_RX_PHY_P0_REGD13_inst_addr                                     "0x0027"
#define  set_DFE_HDMI_RX_PHY_P0_REGD13_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD13_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD13_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD13_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_p0_enable_one_zero_r_shift                (18)
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_p0_prbs_invs_r_shift                      (17)
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_p0_pattern_sel_r_shift                    (16)
#define  DFE_HDMI_RX_PHY_P0_REGD13_p0_pkt_count_r_shift                          (8)
#define  DFE_HDMI_RX_PHY_P0_REGD13_p0_err_count_r_shift                          (0)
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_p0_enable_one_zero_r_mask                 (0x00040000)
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_p0_prbs_invs_r_mask                       (0x00020000)
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_p0_pattern_sel_r_mask                     (0x00010000)
#define  DFE_HDMI_RX_PHY_P0_REGD13_p0_pkt_count_r_mask                           (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_REGD13_p0_err_count_r_mask                           (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_p0_enable_one_zero_r(data)                (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_p0_prbs_invs_r(data)                      (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P0_REGD13_reg_p0_pattern_sel_r(data)                    (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_REGD13_p0_pkt_count_r(data)                          (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_REGD13_p0_err_count_r(data)                          (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD13_get_reg_p0_enable_one_zero_r(data)            ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P0_REGD13_get_reg_p0_prbs_invs_r(data)                  ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P0_REGD13_get_reg_p0_pattern_sel_r(data)                ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_REGD13_get_p0_pkt_count_r(data)                      ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_REGD13_get_p0_err_count_r(data)                      (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD14                                               0x1800DAC8
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_addr                                      "0xB800DAC8"
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg                                           0xB800DAC8
#define  DFE_HDMI_RX_PHY_P0_REGD14_inst_addr                                     "0x0028"
#define  set_DFE_HDMI_RX_PHY_P0_REGD14_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD14_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD14_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD14_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_p0_enable_one_zero_g_shift                (18)
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_p0_prbs_invs_g_shift                      (17)
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_p0_pattern_sel_g_shift                    (16)
#define  DFE_HDMI_RX_PHY_P0_REGD14_p0_pkt_count_g_shift                          (8)
#define  DFE_HDMI_RX_PHY_P0_REGD14_p0_err_count_g_shift                          (0)
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_p0_enable_one_zero_g_mask                 (0x00040000)
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_p0_prbs_invs_g_mask                       (0x00020000)
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_p0_pattern_sel_g_mask                     (0x00010000)
#define  DFE_HDMI_RX_PHY_P0_REGD14_p0_pkt_count_g_mask                           (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_REGD14_p0_err_count_g_mask                           (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_p0_enable_one_zero_g(data)                (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_p0_prbs_invs_g(data)                      (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P0_REGD14_reg_p0_pattern_sel_g(data)                    (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_REGD14_p0_pkt_count_g(data)                          (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_REGD14_p0_err_count_g(data)                          (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD14_get_reg_p0_enable_one_zero_g(data)            ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P0_REGD14_get_reg_p0_prbs_invs_g(data)                  ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P0_REGD14_get_reg_p0_pattern_sel_g(data)                ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_REGD14_get_p0_pkt_count_g(data)                      ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_REGD14_get_p0_err_count_g(data)                      (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_REGD15                                               0x1800DACC
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_addr                                      "0xB800DACC"
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg                                           0xB800DACC
#define  DFE_HDMI_RX_PHY_P0_REGD15_inst_addr                                     "0x0029"
#define  set_DFE_HDMI_RX_PHY_P0_REGD15_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD15_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_REGD15_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_REGD15_reg))
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_p0_enable_one_zero_b_shift                (18)
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_p0_prbs_invs_b_shift                      (17)
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_p0_pattern_sel_b_shift                    (16)
#define  DFE_HDMI_RX_PHY_P0_REGD15_p0_pkt_count_b_shift                          (8)
#define  DFE_HDMI_RX_PHY_P0_REGD15_p0_err_count_b_shift                          (0)
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_p0_enable_one_zero_b_mask                 (0x00040000)
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_p0_prbs_invs_b_mask                       (0x00020000)
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_p0_pattern_sel_b_mask                     (0x00010000)
#define  DFE_HDMI_RX_PHY_P0_REGD15_p0_pkt_count_b_mask                           (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_REGD15_p0_err_count_b_mask                           (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_p0_enable_one_zero_b(data)                (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_p0_prbs_invs_b(data)                      (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P0_REGD15_reg_p0_pattern_sel_b(data)                    (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_REGD15_p0_pkt_count_b(data)                          (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_REGD15_p0_err_count_b(data)                          (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_REGD15_get_reg_p0_enable_one_zero_b(data)            ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P0_REGD15_get_reg_p0_prbs_invs_b(data)                  ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P0_REGD15_get_reg_p0_pattern_sel_b(data)                ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_REGD15_get_p0_pkt_count_b(data)                      ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_REGD15_get_p0_err_count_b(data)                      (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DFE_HDMI_RX_PHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  reg_bg_rbgloop2:3;
        RBus_UInt32  reg_bg_rbg:3;
        RBus_UInt32  reg_bg_rbg2:2;
        RBus_UInt32  reg_bg_pow:1;
        RBus_UInt32  reg_bg_envbgup:1;
    };
}dfe_hdmi_rx_phy_bg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  reg_ck_latch:1;
        RBus_UInt32  reg_ck_cmp:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_ck_det:2;
    };
}dfe_hdmi_rx_phy_p0p1_md_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_ldo_mossel:3;
        RBus_UInt32  res2:6;
        RBus_UInt32  reg_p0_ldo_sel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_p0_ldo_pow:1;
    };
}dfe_hdmi_rx_phy_p0_ldo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  reg_mhlz0en_0:2;
        RBus_UInt32  reg_mhlz0en_1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_p0_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p0_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p0_mhl_pow:1;
        RBus_UInt32  res3:1;
    };
}dfe_hdmi_rx_phy_p0p1_mhl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  reg_p0_en_cmu:1;
        RBus_UInt32  res2:3;
    };
}dfe_hdmi_rx_phy_p0_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_top_in_4:8;
        RBus_UInt32  reg_top_in_3:8;
        RBus_UInt32  reg_top_in_2:8;
        RBus_UInt32  reg_top_in_1:8;
    };
}dfe_hdmi_rx_phy_p0p1_top_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_top_out_4:8;
        RBus_UInt32  res1:24;
    };
}dfe_hdmi_rx_phy_p0p1_top_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  reg_z0_z300_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_z0_z300_pow:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_z0_z100_en:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_z0_z0pow_r:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  reg_z0_z0pow_g:2;
        RBus_UInt32  res6:1;
        RBus_UInt32  reg_z0_z0pow_ck:2;
        RBus_UInt32  res7:1;
        RBus_UInt32  reg_z0_z0pow_b:2;
    };
}dfe_hdmi_rx_phy_p0p1_z0pow_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  reg_z0_adjr_0:5;
        RBus_UInt32  res2:4;
    };
}dfe_hdmi_rx_phy_p0_z0k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_b_4:8;
        RBus_UInt32  reg_p0_b_3:8;
        RBus_UInt32  reg_p0_b_2:8;
        RBus_UInt32  reg_p0_b_1:8;
    };
}dfe_hdmi_rx_phy_p0_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_b_8:8;
        RBus_UInt32  reg_p0_b_7:8;
        RBus_UInt32  reg_p0_b_6:8;
        RBus_UInt32  reg_p0_b_5:8;
    };
}dfe_hdmi_rx_phy_p0_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_b_12:8;
        RBus_UInt32  reg_p0_b_11:8;
        RBus_UInt32  reg_p0_b_10:8;
        RBus_UInt32  reg_p0_b_9:8;
    };
}dfe_hdmi_rx_phy_p0_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p0_b_koff_sel:5;
        RBus_UInt32  reg_p0_b_koff_bound:1;
        RBus_UInt32  reg_p0_b_koffok:1;
        RBus_UInt32  reg_p0_b_13:8;
    };
}dfe_hdmi_rx_phy_p0_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_ck_4:8;
        RBus_UInt32  reg_p0_ck_3:8;
        RBus_UInt32  reg_p0_ck_2:8;
        RBus_UInt32  reg_p0_ck_1:8;
    };
}dfe_hdmi_rx_phy_p0_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_ck_8:8;
        RBus_UInt32  reg_p0_ck_7:8;
        RBus_UInt32  reg_p0_ck_6:8;
        RBus_UInt32  reg_p0_ck_5:8;
    };
}dfe_hdmi_rx_phy_p0_ck2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_ck_12:8;
        RBus_UInt32  reg_p0_ck_11:8;
        RBus_UInt32  reg_p0_ck_10:8;
        RBus_UInt32  reg_p0_ck_9:8;
    };
}dfe_hdmi_rx_phy_p0_ck3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_p0_ck_13:8;
    };
}dfe_hdmi_rx_phy_p0_ck4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_g_4:8;
        RBus_UInt32  reg_p0_g_3:8;
        RBus_UInt32  reg_p0_g_2:8;
        RBus_UInt32  reg_p0_g_1:8;
    };
}dfe_hdmi_rx_phy_p0_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_g_8:8;
        RBus_UInt32  reg_p0_g_7:8;
        RBus_UInt32  reg_p0_g_6:8;
        RBus_UInt32  reg_p0_g_5:8;
    };
}dfe_hdmi_rx_phy_p0_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_g_12:8;
        RBus_UInt32  reg_p0_g_11:8;
        RBus_UInt32  reg_p0_g_10:8;
        RBus_UInt32  reg_p0_g_9:8;
    };
}dfe_hdmi_rx_phy_p0_g3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p0_g_koff_sel:5;
        RBus_UInt32  reg_p0_g_koff_bound:1;
        RBus_UInt32  reg_p0_g_koffok:1;
        RBus_UInt32  reg_p0_g_13:8;
    };
}dfe_hdmi_rx_phy_p0_g4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_r_4:8;
        RBus_UInt32  reg_p0_r_3:8;
        RBus_UInt32  reg_p0_r_2:8;
        RBus_UInt32  reg_p0_r_1:8;
    };
}dfe_hdmi_rx_phy_p0_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_r_8:8;
        RBus_UInt32  reg_p0_r_7:8;
        RBus_UInt32  reg_p0_r_6:8;
        RBus_UInt32  reg_p0_r_5:8;
    };
}dfe_hdmi_rx_phy_p0_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_r_12:8;
        RBus_UInt32  reg_p0_r_11:8;
        RBus_UInt32  reg_p0_r_10:8;
        RBus_UInt32  reg_p0_r_9:8;
    };
}dfe_hdmi_rx_phy_p0_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p0_r_koff_sel:5;
        RBus_UInt32  reg_p0_r_koff_bound:1;
        RBus_UInt32  reg_p0_r_koffok:1;
        RBus_UInt32  reg_p0_r_13:8;
    };
}dfe_hdmi_rx_phy_p0_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  p0_r_demux_rstb:1;
        RBus_UInt32  p0_g_demux_rstb:1;
        RBus_UInt32  p0_b_demux_rstb:1;
    };
}dfe_hdmi_rx_phy_p0_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_r_dig_rst_n:1;
        RBus_UInt32  p0_g_dig_rst_n:1;
        RBus_UInt32  p0_b_dig_rst_n:1;
        RBus_UInt32  p0_r_cdr_rst_n:1;
        RBus_UInt32  p0_g_cdr_rst_n:1;
        RBus_UInt32  p0_b_cdr_rst_n:1;
        RBus_UInt32  reg_p0_cdr_ckinv_r:1;
        RBus_UInt32  reg_p0_cdr_ckinv_g:1;
        RBus_UInt32  reg_p0_cdr_ckinv_b:1;
        RBus_UInt32  reg_p0_shift_inv_r:1;
        RBus_UInt32  reg_p0_shift_inv_g:1;
        RBus_UInt32  reg_p0_shift_inv_b:1;
        RBus_UInt32  reg_p0_rate_sel:3;
        RBus_UInt32  reg_p0_kd:1;
        RBus_UInt32  reg_p0_kp:8;
        RBus_UInt32  reg_p0_ki:3;
        RBus_UInt32  reg_p0_bypass_sdm_int:1;
        RBus_UInt32  reg_p0_data_order:1;
        RBus_UInt32  reg_p0_infifo_cnt:3;
    };
}dfe_hdmi_rx_phy_p0_regd00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_int_init:14;
        RBus_UInt32  reg_p0_acc2_period:10;
        RBus_UInt32  reg_p0_squ_tri:1;
        RBus_UInt32  reg_p0_acc2_manual:1;
        RBus_UInt32  reg_p0_testout_sel:2;
        RBus_UInt32  reg_p0_ercnt_en:1;
        RBus_UInt32  reg_p0_edge_out:1;
        RBus_UInt32  reg_p0_pi_m_mode:1;
        RBus_UInt32  reg_p0_dyn_kp_en:1;
    };
}dfe_hdmi_rx_phy_p0_regd01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_en_m_value:4;
        RBus_UInt32  reg_p0_st_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_p0_timer_lpf:5;
        RBus_UInt32  reg_p0_timer_eq:5;
        RBus_UInt32  reg_p0_timer_ber:5;
        RBus_UInt32  res2:8;
    };
}dfe_hdmi_rx_phy_p0_regd02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  p0_st_ro_r:5;
        RBus_UInt32  p0_en_ro_r:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  p0_st_ro_g:5;
        RBus_UInt32  p0_en_ro_g:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  p0_st_ro_b:5;
        RBus_UInt32  p0_en_ro_b:4;
    };
}dfe_hdmi_rx_phy_p0_regd03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p0_er_count_r:10;
        RBus_UInt32  p0_er_count_g:10;
        RBus_UInt32  p0_er_count_b:10;
    };
}dfe_hdmi_rx_phy_p0_regd04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_bypass_clk_rdy:1;
        RBus_UInt32  reg_p0_bypass_eqen_rdy:1;
        RBus_UInt32  reg_p0_bypass_data_rdy:1;
        RBus_UInt32  reg_p0_bypass_pi:1;
        RBus_UInt32  reg_p0_data_rdy_time:4;
        RBus_UInt32  reg_p0_en_clkout_manual:1;
        RBus_UInt32  reg_p0_en_eqen_manual:1;
        RBus_UInt32  reg_p0_en_data_manual:1;
        RBus_UInt32  reg_p0_eqen_rdy_time:4;
        RBus_UInt32  reg_p0_order:1;
        RBus_UInt32  reg_p0_pll_wd_base_time:3;
        RBus_UInt32  reg_p0_pll_wd_en:1;
        RBus_UInt32  reg_p0_pll_wd_rst_wid:2;
        RBus_UInt32  reg_p0_pll_wd_time_rdy:2;
        RBus_UInt32  reg_p0_acdr_l0_en:1;
        RBus_UInt32  reg_p0_bypass_eqen_rdy_l0:1;
        RBus_UInt32  reg_p0_bypass_data_rdy_l0:1;
        RBus_UInt32  reg_p0_en_eqen_manual_l0:1;
        RBus_UInt32  reg_p0_en_data_manual_l0:1;
        RBus_UInt32  p0_pll_wd_ckrdy_ro:1;
        RBus_UInt32  p0_pll_wd_rst_wc:1;
        RBus_UInt32  p0_wdog_rst_n:1;
    };
}dfe_hdmi_rx_phy_p0_regd05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_wd_sdm_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_p0_f_code:12;
        RBus_UInt32  res2:7;
        RBus_UInt32  reg_p0_n_code:9;
    };
}dfe_hdmi_rx_phy_p0_regd06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_ck_md_rstb:1;
        RBus_UInt32  reg_p0_ck_md_threshold:6;
        RBus_UInt32  reg_p0_ck_md_debounce:7;
        RBus_UInt32  reg_p0_ck_md_sel:2;
        RBus_UInt32  reg_p0_ck_md_auto:1;
        RBus_UInt32  reg_p0_ck_md_adj:4;
        RBus_UInt32  reg_p0_ck_error_limit:5;
        RBus_UInt32  reg_p0_ck_md_reserved:4;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_p0_regd07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_ck_md_count:13;
        RBus_UInt32  p0_ck_rate:4;
        RBus_UInt32  p0_unstable_count:5;
        RBus_UInt32  p0_ck_md_ok:1;
        RBus_UInt32  p0_clock_unstable_flag:1;
        RBus_UInt32  res1:8;
    };
}dfe_hdmi_rx_phy_p0_regd08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_dig_debug_sel:4;
        RBus_UInt32  reg_dig_reserved_0:8;
        RBus_UInt32  reg_dig_reserved_2:8;
        RBus_UInt32  res1:12;
    };
}dfe_hdmi_rx_phy_p0_regd09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value:32;
    };
}dfe_hdmi_rx_phy_p0_regd10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_p0_regd11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_p0_regd12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p0_enable_one_zero_r:1;
        RBus_UInt32  reg_p0_prbs_invs_r:1;
        RBus_UInt32  reg_p0_pattern_sel_r:1;
        RBus_UInt32  p0_pkt_count_r:8;
        RBus_UInt32  p0_err_count_r:8;
    };
}dfe_hdmi_rx_phy_p0_regd13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p0_enable_one_zero_g:1;
        RBus_UInt32  reg_p0_prbs_invs_g:1;
        RBus_UInt32  reg_p0_pattern_sel_g:1;
        RBus_UInt32  p0_pkt_count_g:8;
        RBus_UInt32  p0_err_count_g:8;
    };
}dfe_hdmi_rx_phy_p0_regd14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p0_enable_one_zero_b:1;
        RBus_UInt32  reg_p0_prbs_invs_b:1;
        RBus_UInt32  reg_p0_pattern_sel_b:1;
        RBus_UInt32  p0_pkt_count_b:8;
        RBus_UInt32  p0_err_count_b:8;
    };
}dfe_hdmi_rx_phy_p0_regd15_RBUS;

#else //apply LITTLE_ENDIAN

//======DFE_HDMI_RX_PHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bg_envbgup:1;
        RBus_UInt32  reg_bg_pow:1;
        RBus_UInt32  reg_bg_rbg2:2;
        RBus_UInt32  reg_bg_rbg:3;
        RBus_UInt32  reg_bg_rbgloop2:3;
        RBus_UInt32  res1:22;
    };
}dfe_hdmi_rx_phy_bg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ck_det:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_ck_cmp:1;
        RBus_UInt32  reg_ck_latch:1;
        RBus_UInt32  res2:26;
    };
}dfe_hdmi_rx_phy_p0p1_md_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_ldo_pow:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_p0_ldo_sel:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  reg_ldo_mossel:3;
        RBus_UInt32  res3:17;
    };
}dfe_hdmi_rx_phy_p0_ldo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p0_mhl_pow:1;
        RBus_UInt32  reg_p0_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p0_mhl_hdmi_cksel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_mhlz0en_1:2;
        RBus_UInt32  reg_mhlz0en_0:2;
        RBus_UInt32  res3:23;
    };
}dfe_hdmi_rx_phy_p0p1_mhl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_p0_en_cmu:1;
        RBus_UInt32  res2:28;
    };
}dfe_hdmi_rx_phy_p0_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_top_in_1:8;
        RBus_UInt32  reg_top_in_2:8;
        RBus_UInt32  reg_top_in_3:8;
        RBus_UInt32  reg_top_in_4:8;
    };
}dfe_hdmi_rx_phy_p0p1_top_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_top_out_4:8;
    };
}dfe_hdmi_rx_phy_p0p1_top_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_z0_z0pow_b:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_z0_z0pow_ck:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_z0_z0pow_g:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_z0_z0pow_r:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_z0_z100_en:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  reg_z0_z300_pow:2;
        RBus_UInt32  res6:1;
        RBus_UInt32  reg_z0_z300_sel:2;
        RBus_UInt32  res7:12;
    };
}dfe_hdmi_rx_phy_p0p1_z0pow_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_z0_adjr_0:5;
        RBus_UInt32  res2:23;
    };
}dfe_hdmi_rx_phy_p0_z0k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_b_1:8;
        RBus_UInt32  reg_p0_b_2:8;
        RBus_UInt32  reg_p0_b_3:8;
        RBus_UInt32  reg_p0_b_4:8;
    };
}dfe_hdmi_rx_phy_p0_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_b_5:8;
        RBus_UInt32  reg_p0_b_6:8;
        RBus_UInt32  reg_p0_b_7:8;
        RBus_UInt32  reg_p0_b_8:8;
    };
}dfe_hdmi_rx_phy_p0_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_b_9:8;
        RBus_UInt32  reg_p0_b_10:8;
        RBus_UInt32  reg_p0_b_11:8;
        RBus_UInt32  reg_p0_b_12:8;
    };
}dfe_hdmi_rx_phy_p0_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_b_13:8;
        RBus_UInt32  reg_p0_b_koffok:1;
        RBus_UInt32  reg_p0_b_koff_bound:1;
        RBus_UInt32  reg_p0_b_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p0_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_ck_1:8;
        RBus_UInt32  reg_p0_ck_2:8;
        RBus_UInt32  reg_p0_ck_3:8;
        RBus_UInt32  reg_p0_ck_4:8;
    };
}dfe_hdmi_rx_phy_p0_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_ck_5:8;
        RBus_UInt32  reg_p0_ck_6:8;
        RBus_UInt32  reg_p0_ck_7:8;
        RBus_UInt32  reg_p0_ck_8:8;
    };
}dfe_hdmi_rx_phy_p0_ck2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_ck_9:8;
        RBus_UInt32  reg_p0_ck_10:8;
        RBus_UInt32  reg_p0_ck_11:8;
        RBus_UInt32  reg_p0_ck_12:8;
    };
}dfe_hdmi_rx_phy_p0_ck3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_ck_13:8;
        RBus_UInt32  res1:24;
    };
}dfe_hdmi_rx_phy_p0_ck4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_g_1:8;
        RBus_UInt32  reg_p0_g_2:8;
        RBus_UInt32  reg_p0_g_3:8;
        RBus_UInt32  reg_p0_g_4:8;
    };
}dfe_hdmi_rx_phy_p0_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_g_5:8;
        RBus_UInt32  reg_p0_g_6:8;
        RBus_UInt32  reg_p0_g_7:8;
        RBus_UInt32  reg_p0_g_8:8;
    };
}dfe_hdmi_rx_phy_p0_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_g_9:8;
        RBus_UInt32  reg_p0_g_10:8;
        RBus_UInt32  reg_p0_g_11:8;
        RBus_UInt32  reg_p0_g_12:8;
    };
}dfe_hdmi_rx_phy_p0_g3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_g_13:8;
        RBus_UInt32  reg_p0_g_koffok:1;
        RBus_UInt32  reg_p0_g_koff_bound:1;
        RBus_UInt32  reg_p0_g_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p0_g4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_r_1:8;
        RBus_UInt32  reg_p0_r_2:8;
        RBus_UInt32  reg_p0_r_3:8;
        RBus_UInt32  reg_p0_r_4:8;
    };
}dfe_hdmi_rx_phy_p0_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_r_5:8;
        RBus_UInt32  reg_p0_r_6:8;
        RBus_UInt32  reg_p0_r_7:8;
        RBus_UInt32  reg_p0_r_8:8;
    };
}dfe_hdmi_rx_phy_p0_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_r_9:8;
        RBus_UInt32  reg_p0_r_10:8;
        RBus_UInt32  reg_p0_r_11:8;
        RBus_UInt32  reg_p0_r_12:8;
    };
}dfe_hdmi_rx_phy_p0_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_r_13:8;
        RBus_UInt32  reg_p0_r_koffok:1;
        RBus_UInt32  reg_p0_r_koff_bound:1;
        RBus_UInt32  reg_p0_r_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p0_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_b_demux_rstb:1;
        RBus_UInt32  p0_g_demux_rstb:1;
        RBus_UInt32  p0_r_demux_rstb:1;
        RBus_UInt32  res1:29;
    };
}dfe_hdmi_rx_phy_p0_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_infifo_cnt:3;
        RBus_UInt32  reg_p0_data_order:1;
        RBus_UInt32  reg_p0_bypass_sdm_int:1;
        RBus_UInt32  reg_p0_ki:3;
        RBus_UInt32  reg_p0_kp:8;
        RBus_UInt32  reg_p0_kd:1;
        RBus_UInt32  reg_p0_rate_sel:3;
        RBus_UInt32  reg_p0_shift_inv_b:1;
        RBus_UInt32  reg_p0_shift_inv_g:1;
        RBus_UInt32  reg_p0_shift_inv_r:1;
        RBus_UInt32  reg_p0_cdr_ckinv_b:1;
        RBus_UInt32  reg_p0_cdr_ckinv_g:1;
        RBus_UInt32  reg_p0_cdr_ckinv_r:1;
        RBus_UInt32  p0_b_cdr_rst_n:1;
        RBus_UInt32  p0_g_cdr_rst_n:1;
        RBus_UInt32  p0_r_cdr_rst_n:1;
        RBus_UInt32  p0_b_dig_rst_n:1;
        RBus_UInt32  p0_g_dig_rst_n:1;
        RBus_UInt32  p0_r_dig_rst_n:1;
    };
}dfe_hdmi_rx_phy_p0_regd00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_dyn_kp_en:1;
        RBus_UInt32  reg_p0_pi_m_mode:1;
        RBus_UInt32  reg_p0_edge_out:1;
        RBus_UInt32  reg_p0_ercnt_en:1;
        RBus_UInt32  reg_p0_testout_sel:2;
        RBus_UInt32  reg_p0_acc2_manual:1;
        RBus_UInt32  reg_p0_squ_tri:1;
        RBus_UInt32  reg_p0_acc2_period:10;
        RBus_UInt32  reg_p0_int_init:14;
    };
}dfe_hdmi_rx_phy_p0_regd01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_p0_timer_ber:5;
        RBus_UInt32  reg_p0_timer_eq:5;
        RBus_UInt32  reg_p0_timer_lpf:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  reg_p0_st_mode:1;
        RBus_UInt32  reg_p0_en_m_value:4;
    };
}dfe_hdmi_rx_phy_p0_regd02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_en_ro_b:4;
        RBus_UInt32  p0_st_ro_b:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  p0_en_ro_g:4;
        RBus_UInt32  p0_st_ro_g:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  p0_en_ro_r:4;
        RBus_UInt32  p0_st_ro_r:5;
        RBus_UInt32  res3:3;
    };
}dfe_hdmi_rx_phy_p0_regd03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_er_count_b:10;
        RBus_UInt32  p0_er_count_g:10;
        RBus_UInt32  p0_er_count_r:10;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_p0_regd04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_wdog_rst_n:1;
        RBus_UInt32  p0_pll_wd_rst_wc:1;
        RBus_UInt32  p0_pll_wd_ckrdy_ro:1;
        RBus_UInt32  reg_p0_en_data_manual_l0:1;
        RBus_UInt32  reg_p0_en_eqen_manual_l0:1;
        RBus_UInt32  reg_p0_bypass_data_rdy_l0:1;
        RBus_UInt32  reg_p0_bypass_eqen_rdy_l0:1;
        RBus_UInt32  reg_p0_acdr_l0_en:1;
        RBus_UInt32  reg_p0_pll_wd_time_rdy:2;
        RBus_UInt32  reg_p0_pll_wd_rst_wid:2;
        RBus_UInt32  reg_p0_pll_wd_en:1;
        RBus_UInt32  reg_p0_pll_wd_base_time:3;
        RBus_UInt32  reg_p0_order:1;
        RBus_UInt32  reg_p0_eqen_rdy_time:4;
        RBus_UInt32  reg_p0_en_data_manual:1;
        RBus_UInt32  reg_p0_en_eqen_manual:1;
        RBus_UInt32  reg_p0_en_clkout_manual:1;
        RBus_UInt32  reg_p0_data_rdy_time:4;
        RBus_UInt32  reg_p0_bypass_pi:1;
        RBus_UInt32  reg_p0_bypass_data_rdy:1;
        RBus_UInt32  reg_p0_bypass_eqen_rdy:1;
        RBus_UInt32  reg_p0_bypass_clk_rdy:1;
    };
}dfe_hdmi_rx_phy_p0_regd05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_n_code:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_p0_f_code:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_p0_wd_sdm_en:1;
    };
}dfe_hdmi_rx_phy_p0_regd06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_p0_ck_md_reserved:4;
        RBus_UInt32  reg_p0_ck_error_limit:5;
        RBus_UInt32  reg_p0_ck_md_adj:4;
        RBus_UInt32  reg_p0_ck_md_auto:1;
        RBus_UInt32  reg_p0_ck_md_sel:2;
        RBus_UInt32  reg_p0_ck_md_debounce:7;
        RBus_UInt32  reg_p0_ck_md_threshold:6;
        RBus_UInt32  p0_ck_md_rstb:1;
    };
}dfe_hdmi_rx_phy_p0_regd07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  p0_clock_unstable_flag:1;
        RBus_UInt32  p0_ck_md_ok:1;
        RBus_UInt32  p0_unstable_count:5;
        RBus_UInt32  p0_ck_rate:4;
        RBus_UInt32  p0_ck_md_count:13;
    };
}dfe_hdmi_rx_phy_p0_regd08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  reg_dig_reserved_2:8;
        RBus_UInt32  reg_dig_reserved_0:8;
        RBus_UInt32  reg_p0_dig_debug_sel:4;
    };
}dfe_hdmi_rx_phy_p0_regd09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value:32;
    };
}dfe_hdmi_rx_phy_p0_regd10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_p0_regd11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_p0_regd12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_err_count_r:8;
        RBus_UInt32  p0_pkt_count_r:8;
        RBus_UInt32  reg_p0_pattern_sel_r:1;
        RBus_UInt32  reg_p0_prbs_invs_r:1;
        RBus_UInt32  reg_p0_enable_one_zero_r:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_p0_regd13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_err_count_g:8;
        RBus_UInt32  p0_pkt_count_g:8;
        RBus_UInt32  reg_p0_pattern_sel_g:1;
        RBus_UInt32  reg_p0_prbs_invs_g:1;
        RBus_UInt32  reg_p0_enable_one_zero_g:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_p0_regd14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_err_count_b:8;
        RBus_UInt32  p0_pkt_count_b:8;
        RBus_UInt32  reg_p0_pattern_sel_b:1;
        RBus_UInt32  reg_p0_prbs_invs_b:1;
        RBus_UInt32  reg_p0_enable_one_zero_b:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_p0_regd15_RBUS;




#endif 


#endif 
