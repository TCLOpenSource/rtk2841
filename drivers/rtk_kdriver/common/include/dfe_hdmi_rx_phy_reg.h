/**
* @file rbusDFE_HDMI_RX_PHYReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/4/1
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DFE_HDMI_RX_PHY_REG_H_
#define _RBUS_DFE_HDMI_RX_PHY_REG_H_

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

#define  DFE_HDMI_RX_PHY_MD                                                      0x1800DA04
#define  DFE_HDMI_RX_PHY_MD_reg_addr                                             "0xB800DA04"
#define  DFE_HDMI_RX_PHY_MD_reg                                                  0xB800DA04
#define  DFE_HDMI_RX_PHY_MD_inst_addr                                            "0x0001"
#define  set_DFE_HDMI_RX_PHY_MD_reg(data)                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_MD_reg)=data)
#define  get_DFE_HDMI_RX_PHY_MD_reg                                              (*((volatile unsigned int*)DFE_HDMI_RX_PHY_MD_reg))
#define  DFE_HDMI_RX_PHY_MD_reg_ck_latch_shift                                   (5)
#define  DFE_HDMI_RX_PHY_MD_reg_ck_cmp_shift                                     (4)
#define  DFE_HDMI_RX_PHY_MD_reg_ck_ckdet_shift                                   (0)
#define  DFE_HDMI_RX_PHY_MD_reg_ck_latch_mask                                    (0x00000020)
#define  DFE_HDMI_RX_PHY_MD_reg_ck_cmp_mask                                      (0x00000010)
#define  DFE_HDMI_RX_PHY_MD_reg_ck_ckdet_mask                                    (0x0000000F)
#define  DFE_HDMI_RX_PHY_MD_reg_ck_latch(data)                                   (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_MD_reg_ck_cmp(data)                                     (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_MD_reg_ck_ckdet(data)                                   (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_MD_get_reg_ck_latch(data)                               ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_MD_get_reg_ck_cmp(data)                                 ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_MD_get_reg_ck_ckdet(data)                               (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_LDO                                                     0x1800DA08
#define  DFE_HDMI_RX_PHY_LDO_reg_addr                                            "0xB800DA08"
#define  DFE_HDMI_RX_PHY_LDO_reg                                                 0xB800DA08
#define  DFE_HDMI_RX_PHY_LDO_inst_addr                                           "0x0002"
#define  set_DFE_HDMI_RX_PHY_LDO_reg(data)                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_LDO_reg)=data)
#define  get_DFE_HDMI_RX_PHY_LDO_reg                                             (*((volatile unsigned int*)DFE_HDMI_RX_PHY_LDO_reg))
#define  DFE_HDMI_RX_PHY_LDO_reg_ldo_mossel_shift                                (12)
#define  DFE_HDMI_RX_PHY_LDO_reg_p3_ldo_sel_shift                                (10)
#define  DFE_HDMI_RX_PHY_LDO_reg_p2_ldo_sel_shift                                (8)
#define  DFE_HDMI_RX_PHY_LDO_reg_p1_ldo_sel_shift                                (6)
#define  DFE_HDMI_RX_PHY_LDO_reg_p0_ldo_sel_shift                                (4)
#define  DFE_HDMI_RX_PHY_LDO_reg_p3_ldo_pow_shift                                (3)
#define  DFE_HDMI_RX_PHY_LDO_reg_p2_ldo_pow_shift                                (2)
#define  DFE_HDMI_RX_PHY_LDO_reg_p1_ldo_pow_shift                                (1)
#define  DFE_HDMI_RX_PHY_LDO_reg_p0_ldo_pow_shift                                (0)
#define  DFE_HDMI_RX_PHY_LDO_reg_ldo_mossel_mask                                 (0x00007000)
#define  DFE_HDMI_RX_PHY_LDO_reg_p3_ldo_sel_mask                                 (0x00000C00)
#define  DFE_HDMI_RX_PHY_LDO_reg_p2_ldo_sel_mask                                 (0x00000300)
#define  DFE_HDMI_RX_PHY_LDO_reg_p1_ldo_sel_mask                                 (0x000000C0)
#define  DFE_HDMI_RX_PHY_LDO_reg_p0_ldo_sel_mask                                 (0x00000030)
#define  DFE_HDMI_RX_PHY_LDO_reg_p3_ldo_pow_mask                                 (0x00000008)
#define  DFE_HDMI_RX_PHY_LDO_reg_p2_ldo_pow_mask                                 (0x00000004)
#define  DFE_HDMI_RX_PHY_LDO_reg_p1_ldo_pow_mask                                 (0x00000002)
#define  DFE_HDMI_RX_PHY_LDO_reg_p0_ldo_pow_mask                                 (0x00000001)
#define  DFE_HDMI_RX_PHY_LDO_reg_ldo_mossel(data)                                (0x00007000&((data)<<12))
#define  DFE_HDMI_RX_PHY_LDO_reg_p3_ldo_sel(data)                                (0x00000C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_LDO_reg_p2_ldo_sel(data)                                (0x00000300&((data)<<8))
#define  DFE_HDMI_RX_PHY_LDO_reg_p1_ldo_sel(data)                                (0x000000C0&((data)<<6))
#define  DFE_HDMI_RX_PHY_LDO_reg_p0_ldo_sel(data)                                (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_LDO_reg_p3_ldo_pow(data)                                (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_LDO_reg_p2_ldo_pow(data)                                (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_LDO_reg_p1_ldo_pow(data)                                (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_LDO_reg_p0_ldo_pow(data)                                (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_LDO_get_reg_ldo_mossel(data)                            ((0x00007000&(data))>>12)
#define  DFE_HDMI_RX_PHY_LDO_get_reg_p3_ldo_sel(data)                            ((0x00000C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_LDO_get_reg_p2_ldo_sel(data)                            ((0x00000300&(data))>>8)
#define  DFE_HDMI_RX_PHY_LDO_get_reg_p1_ldo_sel(data)                            ((0x000000C0&(data))>>6)
#define  DFE_HDMI_RX_PHY_LDO_get_reg_p0_ldo_sel(data)                            ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_LDO_get_reg_p3_ldo_pow(data)                            ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_LDO_get_reg_p2_ldo_pow(data)                            ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_LDO_get_reg_p1_ldo_pow(data)                            ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_LDO_get_reg_p0_ldo_pow(data)                            (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_MHL                                                     0x1800DA0C
#define  DFE_HDMI_RX_PHY_MHL_reg_addr                                            "0xB800DA0C"
#define  DFE_HDMI_RX_PHY_MHL_reg                                                 0xB800DA0C
#define  DFE_HDMI_RX_PHY_MHL_inst_addr                                           "0x0003"
#define  set_DFE_HDMI_RX_PHY_MHL_reg(data)                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_MHL_reg)=data)
#define  get_DFE_HDMI_RX_PHY_MHL_reg                                             (*((volatile unsigned int*)DFE_HDMI_RX_PHY_MHL_reg))
#define  DFE_HDMI_RX_PHY_MHL_reg_p3_mhl_hdmi_datasel_shift                       (12)
#define  DFE_HDMI_RX_PHY_MHL_reg_p3_mhl_hdmi_cksel_shift                         (11)
#define  DFE_HDMI_RX_PHY_MHL_reg_p3_mhl_pow_shift                                (10)
#define  DFE_HDMI_RX_PHY_MHL_reg_p2_mhl_hdmi_datasel_shift                       (9)
#define  DFE_HDMI_RX_PHY_MHL_reg_p2_mhl_hdmi_cksel_shift                         (8)
#define  DFE_HDMI_RX_PHY_MHL_reg_p2_mhl_pow_shift                                (7)
#define  DFE_HDMI_RX_PHY_MHL_reg_p1_mhl_hdmi_datasel_shift                       (6)
#define  DFE_HDMI_RX_PHY_MHL_reg_p1_mhl_hdmi_cksel_shift                         (5)
#define  DFE_HDMI_RX_PHY_MHL_reg_p1_mhl_pow_shift                                (4)
#define  DFE_HDMI_RX_PHY_MHL_reg_p0_mhl_hdmi_cksel_shift                         (3)
#define  DFE_HDMI_RX_PHY_MHL_reg_p0_mhl_hdmi_datasel_shift                       (2)
#define  DFE_HDMI_RX_PHY_MHL_reg_p0_mhl_pow_shift                                (1)
#define  DFE_HDMI_RX_PHY_MHL_reg_mhl_hdmisel_shift                               (0)
#define  DFE_HDMI_RX_PHY_MHL_reg_p3_mhl_hdmi_datasel_mask                        (0x00001000)
#define  DFE_HDMI_RX_PHY_MHL_reg_p3_mhl_hdmi_cksel_mask                          (0x00000800)
#define  DFE_HDMI_RX_PHY_MHL_reg_p3_mhl_pow_mask                                 (0x00000400)
#define  DFE_HDMI_RX_PHY_MHL_reg_p2_mhl_hdmi_datasel_mask                        (0x00000200)
#define  DFE_HDMI_RX_PHY_MHL_reg_p2_mhl_hdmi_cksel_mask                          (0x00000100)
#define  DFE_HDMI_RX_PHY_MHL_reg_p2_mhl_pow_mask                                 (0x00000080)
#define  DFE_HDMI_RX_PHY_MHL_reg_p1_mhl_hdmi_datasel_mask                        (0x00000040)
#define  DFE_HDMI_RX_PHY_MHL_reg_p1_mhl_hdmi_cksel_mask                          (0x00000020)
#define  DFE_HDMI_RX_PHY_MHL_reg_p1_mhl_pow_mask                                 (0x00000010)
#define  DFE_HDMI_RX_PHY_MHL_reg_p0_mhl_hdmi_cksel_mask                          (0x00000008)
#define  DFE_HDMI_RX_PHY_MHL_reg_p0_mhl_hdmi_datasel_mask                        (0x00000004)
#define  DFE_HDMI_RX_PHY_MHL_reg_p0_mhl_pow_mask                                 (0x00000002)
#define  DFE_HDMI_RX_PHY_MHL_reg_mhl_hdmisel_mask                                (0x00000001)
#define  DFE_HDMI_RX_PHY_MHL_reg_p3_mhl_hdmi_datasel(data)                       (0x00001000&((data)<<12))
#define  DFE_HDMI_RX_PHY_MHL_reg_p3_mhl_hdmi_cksel(data)                         (0x00000800&((data)<<11))
#define  DFE_HDMI_RX_PHY_MHL_reg_p3_mhl_pow(data)                                (0x00000400&((data)<<10))
#define  DFE_HDMI_RX_PHY_MHL_reg_p2_mhl_hdmi_datasel(data)                       (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_MHL_reg_p2_mhl_hdmi_cksel(data)                         (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_MHL_reg_p2_mhl_pow(data)                                (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_MHL_reg_p1_mhl_hdmi_datasel(data)                       (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_MHL_reg_p1_mhl_hdmi_cksel(data)                         (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_MHL_reg_p1_mhl_pow(data)                                (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_MHL_reg_p0_mhl_hdmi_cksel(data)                         (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_MHL_reg_p0_mhl_hdmi_datasel(data)                       (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_MHL_reg_p0_mhl_pow(data)                                (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_MHL_reg_mhl_hdmisel(data)                               (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p3_mhl_hdmi_datasel(data)                   ((0x00001000&(data))>>12)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p3_mhl_hdmi_cksel(data)                     ((0x00000800&(data))>>11)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p3_mhl_pow(data)                            ((0x00000400&(data))>>10)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p2_mhl_hdmi_datasel(data)                   ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p2_mhl_hdmi_cksel(data)                     ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p2_mhl_pow(data)                            ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p1_mhl_hdmi_datasel(data)                   ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p1_mhl_hdmi_cksel(data)                     ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p1_mhl_pow(data)                            ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p0_mhl_hdmi_cksel(data)                     ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p0_mhl_hdmi_datasel(data)                   ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_p0_mhl_pow(data)                            ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_MHL_get_reg_mhl_hdmisel(data)                           (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_ENABLE                                                  0x1800DA10
#define  DFE_HDMI_RX_PHY_ENABLE_reg_addr                                         "0xB800DA10"
#define  DFE_HDMI_RX_PHY_ENABLE_reg                                              0xB800DA10
#define  DFE_HDMI_RX_PHY_ENABLE_inst_addr                                        "0x0004"
#define  set_DFE_HDMI_RX_PHY_ENABLE_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_ENABLE_reg)=data)
#define  get_DFE_HDMI_RX_PHY_ENABLE_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_ENABLE_reg))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p3_en_rx_shift                               (25)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p3_en_cmu_shift                              (24)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p3_en_cdr_shift                              (21)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p2_en_rx_shift                               (18)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p2_en_cmu_shift                              (17)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p2_en_cdr_shift                              (14)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p1_en_rx_shift                               (11)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p1_en_cmu_shift                              (10)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p1_en_cdr_shift                              (7)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p0_en_rx_shift                               (4)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p0_en_cmu_shift                              (3)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p0_en_cdr_shift                              (0)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p3_en_rx_mask                                (0x0E000000)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p3_en_cmu_mask                               (0x01000000)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p3_en_cdr_mask                               (0x00E00000)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p2_en_rx_mask                                (0x001C0000)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p2_en_cmu_mask                               (0x00020000)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p2_en_cdr_mask                               (0x0001C000)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p1_en_rx_mask                                (0x00003800)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p1_en_cmu_mask                               (0x00000400)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p1_en_cdr_mask                               (0x00000380)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p0_en_rx_mask                                (0x00000070)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p0_en_cmu_mask                               (0x00000008)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p0_en_cdr_mask                               (0x00000007)
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p3_en_rx(data)                               (0x0E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p3_en_cmu(data)                              (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p3_en_cdr(data)                              (0x00E00000&((data)<<21))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p2_en_rx(data)                               (0x001C0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p2_en_cmu(data)                              (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p2_en_cdr(data)                              (0x0001C000&((data)<<14))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p1_en_rx(data)                               (0x00003800&((data)<<11))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p1_en_cmu(data)                              (0x00000400&((data)<<10))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p1_en_cdr(data)                              (0x00000380&((data)<<7))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p0_en_rx(data)                               (0x00000070&((data)<<4))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p0_en_cmu(data)                              (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_ENABLE_reg_p0_en_cdr(data)                              (0x00000007&(data))
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p3_en_rx(data)                           ((0x0E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p3_en_cmu(data)                          ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p3_en_cdr(data)                          ((0x00E00000&(data))>>21)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p2_en_rx(data)                           ((0x001C0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p2_en_cmu(data)                          ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p2_en_cdr(data)                          ((0x0001C000&(data))>>14)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p1_en_rx(data)                           ((0x00003800&(data))>>11)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p1_en_cmu(data)                          ((0x00000400&(data))>>10)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p1_en_cdr(data)                          ((0x00000380&(data))>>7)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p0_en_rx(data)                           ((0x00000070&(data))>>4)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p0_en_cmu(data)                          ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_ENABLE_get_reg_p0_en_cdr(data)                          (0x00000007&(data))

#define  DFE_HDMI_RX_PHY_TEST                                                    0x1800DA14
#define  DFE_HDMI_RX_PHY_TEST_reg_addr                                           "0xB800DA14"
#define  DFE_HDMI_RX_PHY_TEST_reg                                                0xB800DA14
#define  DFE_HDMI_RX_PHY_TEST_inst_addr                                          "0x0005"
#define  set_DFE_HDMI_RX_PHY_TEST_reg(data)                                      (*((volatile unsigned int*)DFE_HDMI_RX_PHY_TEST_reg)=data)
#define  get_DFE_HDMI_RX_PHY_TEST_reg                                            (*((volatile unsigned int*)DFE_HDMI_RX_PHY_TEST_reg))
#define  DFE_HDMI_RX_PHY_TEST_reg_tst_spad_shift                                 (4)
#define  DFE_HDMI_RX_PHY_TEST_reg_stst_shift                                     (0)
#define  DFE_HDMI_RX_PHY_TEST_reg_tst_spad_mask                                  (0x00000010)
#define  DFE_HDMI_RX_PHY_TEST_reg_stst_mask                                      (0x0000000F)
#define  DFE_HDMI_RX_PHY_TEST_reg_tst_spad(data)                                 (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_TEST_reg_stst(data)                                     (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_TEST_get_reg_tst_spad(data)                             ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_TEST_get_reg_stst(data)                                 (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_TOP_IN                                                  0x1800DA18
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_addr                                         "0xB800DA18"
#define  DFE_HDMI_RX_PHY_TOP_IN_reg                                              0xB800DA18
#define  DFE_HDMI_RX_PHY_TOP_IN_inst_addr                                        "0x0006"
#define  set_DFE_HDMI_RX_PHY_TOP_IN_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_TOP_IN_reg)=data)
#define  get_DFE_HDMI_RX_PHY_TOP_IN_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_TOP_IN_reg))
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_4_shift                               (24)
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_3_shift                               (16)
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_2_shift                               (8)
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_1_shift                               (0)
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_4_mask                                (0xFF000000)
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_3_mask                                (0x00FF0000)
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_2_mask                                (0x0000FF00)
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_1_mask                                (0x000000FF)
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_4(data)                               (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_3(data)                               (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_2(data)                               (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_TOP_IN_reg_top_in_1(data)                               (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_TOP_IN_get_reg_top_in_4(data)                           ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_TOP_IN_get_reg_top_in_3(data)                           ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_TOP_IN_get_reg_top_in_2(data)                           ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_TOP_IN_get_reg_top_in_1(data)                           (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_TOP_OUT                                                 0x1800DA1C
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_addr                                        "0xB800DA1C"
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg                                             0xB800DA1C
#define  DFE_HDMI_RX_PHY_TOP_OUT_inst_addr                                       "0x0007"
#define  set_DFE_HDMI_RX_PHY_TOP_OUT_reg(data)                                   (*((volatile unsigned int*)DFE_HDMI_RX_PHY_TOP_OUT_reg)=data)
#define  get_DFE_HDMI_RX_PHY_TOP_OUT_reg                                         (*((volatile unsigned int*)DFE_HDMI_RX_PHY_TOP_OUT_reg))
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_4_shift                             (24)
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_3_shift                             (16)
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_2_shift                             (8)
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_1_shift                             (0)
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_4_mask                              (0xFF000000)
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_3_mask                              (0x00FF0000)
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_2_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_1_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_4(data)                             (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_3(data)                             (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_2(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_TOP_OUT_reg_top_out_1(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_TOP_OUT_get_reg_top_out_4(data)                         ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_TOP_OUT_get_reg_top_out_3(data)                         ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_TOP_OUT_get_reg_top_out_2(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_TOP_OUT_get_reg_top_out_1(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_Z0POW                                                   0x1800DA20
#define  DFE_HDMI_RX_PHY_Z0POW_reg_addr                                          "0xB800DA20"
#define  DFE_HDMI_RX_PHY_Z0POW_reg                                               0xB800DA20
#define  DFE_HDMI_RX_PHY_Z0POW_inst_addr                                         "0x0008"
#define  set_DFE_HDMI_RX_PHY_Z0POW_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_Z0POW_reg)=data)
#define  get_DFE_HDMI_RX_PHY_Z0POW_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_Z0POW_reg))
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z300_sel_shift                             (24)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z300pow_shift                              (20)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z100_en_shift                              (16)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_r_shift                              (12)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_g_shift                              (8)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_ck_shift                             (4)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_b_shift                              (0)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z300_sel_mask                              (0x0F000000)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z300pow_mask                               (0x00F00000)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z100_en_mask                               (0x000F0000)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_r_mask                               (0x0000F000)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_g_mask                               (0x00000F00)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_ck_mask                              (0x000000F0)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_b_mask                               (0x0000000F)
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z300_sel(data)                             (0x0F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z300pow(data)                              (0x00F00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z100_en(data)                              (0x000F0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_r(data)                              (0x0000F000&((data)<<12))
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_g(data)                              (0x00000F00&((data)<<8))
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_ck(data)                             (0x000000F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_Z0POW_reg_z0_z0pow_b(data)                              (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_Z0POW_get_reg_z0_z300_sel(data)                         ((0x0F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_Z0POW_get_reg_z0_z300pow(data)                          ((0x00F00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_Z0POW_get_reg_z0_z100_en(data)                          ((0x000F0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_Z0POW_get_reg_z0_z0pow_r(data)                          ((0x0000F000&(data))>>12)
#define  DFE_HDMI_RX_PHY_Z0POW_get_reg_z0_z0pow_g(data)                          ((0x00000F00&(data))>>8)
#define  DFE_HDMI_RX_PHY_Z0POW_get_reg_z0_z0pow_ck(data)                         ((0x000000F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_Z0POW_get_reg_z0_z0pow_b(data)                          (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_Z0K                                                     0x1800DA24
#define  DFE_HDMI_RX_PHY_Z0K_reg_addr                                            "0xB800DA24"
#define  DFE_HDMI_RX_PHY_Z0K_reg                                                 0xB800DA24
#define  DFE_HDMI_RX_PHY_Z0K_inst_addr                                           "0x0009"
#define  set_DFE_HDMI_RX_PHY_Z0K_reg(data)                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_Z0K_reg)=data)
#define  get_DFE_HDMI_RX_PHY_Z0K_reg                                             (*((volatile unsigned int*)DFE_HDMI_RX_PHY_Z0K_reg))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_z0pow_shift                                  (28)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_stune_shift                                  (27)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_res_shift                                    (22)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_ok_shift                                     (21)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_entst_shift                                  (20)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_bound_shift                                  (19)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_adjr_2_shift                                 (14)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_adjr_1_shift                                 (9)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_adjr_0_shift                                 (4)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0tst_shift                                     (0)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_z0pow_mask                                   (0x10000000)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_stune_mask                                   (0x08000000)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_res_mask                                     (0x07C00000)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_ok_mask                                      (0x00200000)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_entst_mask                                   (0x00100000)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_bound_mask                                   (0x00080000)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_adjr_2_mask                                  (0x0007C000)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_adjr_1_mask                                  (0x00003E00)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_adjr_0_mask                                  (0x000001F0)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0tst_mask                                      (0x0000000F)
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_z0pow(data)                                  (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_stune(data)                                  (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_res(data)                                    (0x07C00000&((data)<<22))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_ok(data)                                     (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_entst(data)                                  (0x00100000&((data)<<20))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_bound(data)                                  (0x00080000&((data)<<19))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_adjr_2(data)                                 (0x0007C000&((data)<<14))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_adjr_1(data)                                 (0x00003E00&((data)<<9))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0_adjr_0(data)                                 (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_Z0K_reg_z0tst(data)                                     (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0_z0pow(data)                              ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0_stune(data)                              ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0_res(data)                                ((0x07C00000&(data))>>22)
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0_ok(data)                                 ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0_entst(data)                              ((0x00100000&(data))>>20)
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0_bound(data)                              ((0x00080000&(data))>>19)
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0_adjr_2(data)                             ((0x0007C000&(data))>>14)
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0_adjr_1(data)                             ((0x00003E00&(data))>>9)
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0_adjr_0(data)                             ((0x000001F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_Z0K_get_reg_z0tst(data)                                 (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_Z0K_2                                                   0x1800DA28
#define  DFE_HDMI_RX_PHY_Z0K_2_reg_addr                                          "0xB800DA28"
#define  DFE_HDMI_RX_PHY_Z0K_2_reg                                               0xB800DA28
#define  DFE_HDMI_RX_PHY_Z0K_2_inst_addr                                         "0x000A"
#define  set_DFE_HDMI_RX_PHY_Z0K_2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_Z0K_2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_Z0K_2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_Z0K_2_reg))
#define  DFE_HDMI_RX_PHY_Z0K_2_reg_z0_adjr_3_shift                               (0)
#define  DFE_HDMI_RX_PHY_Z0K_2_reg_z0_adjr_3_mask                                (0x0000001F)
#define  DFE_HDMI_RX_PHY_Z0K_2_reg_z0_adjr_3(data)                               (0x0000001F&(data))
#define  DFE_HDMI_RX_PHY_Z0K_2_get_reg_z0_adjr_3(data)                           (0x0000001F&(data))

#define  DFE_HDMI_RX_PHY_P0_ACDR1                                                0x1800DA30
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_addr                                       "0xB800DA30"
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg                                            0xB800DA30
#define  DFE_HDMI_RX_PHY_P0_ACDR1_inst_addr                                      "0x000B"
#define  set_DFE_HDMI_RX_PHY_P0_ACDR1_reg(data)                                  (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_ACDR1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_ACDR1_reg                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_ACDR1_reg))
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_4_shift                            (24)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_3_shift                            (16)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_2_shift                            (8)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_1_shift                            (0)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_4_mask                             (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_3_mask                             (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_2_mask                             (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_1_mask                             (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_4(data)                            (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_3(data)                            (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_2(data)                            (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_ACDR1_reg_p0_acdr_1(data)                            (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_ACDR1_get_reg_p0_acdr_4(data)                        ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_get_reg_p0_acdr_3(data)                        ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_get_reg_p0_acdr_2(data)                        ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_ACDR1_get_reg_p0_acdr_1(data)                        (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_ACDR2                                                0x1800DA34
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_addr                                       "0xB800DA34"
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg                                            0xB800DA34
#define  DFE_HDMI_RX_PHY_P0_ACDR2_inst_addr                                      "0x000C"
#define  set_DFE_HDMI_RX_PHY_P0_ACDR2_reg(data)                                  (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_ACDR2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_ACDR2_reg                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_ACDR2_reg))
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_8_shift                            (24)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_7_shift                            (16)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_6_shift                            (8)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_5_shift                            (0)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_8_mask                             (0xFF000000)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_7_mask                             (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_6_mask                             (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_5_mask                             (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_8(data)                            (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_7(data)                            (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_6(data)                            (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_ACDR2_reg_p0_acdr_5(data)                            (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_ACDR2_get_reg_p0_acdr_8(data)                        ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_get_reg_p0_acdr_7(data)                        ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_get_reg_p0_acdr_6(data)                        ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P0_ACDR2_get_reg_p0_acdr_5(data)                        (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_B1                                                   0x1800DA40
#define  DFE_HDMI_RX_PHY_P0_B1_reg_addr                                          "0xB800DA40"
#define  DFE_HDMI_RX_PHY_P0_B1_reg                                               0xB800DA40
#define  DFE_HDMI_RX_PHY_P0_B1_inst_addr                                         "0x000D"
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
#define  DFE_HDMI_RX_PHY_P0_B2_inst_addr                                         "0x000E"
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
#define  DFE_HDMI_RX_PHY_P0_B3_inst_addr                                         "0x000F"
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
#define  DFE_HDMI_RX_PHY_P0_B4_inst_addr                                         "0x0010"
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
#define  DFE_HDMI_RX_PHY_P0_CK1_inst_addr                                        "0x0011"
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
#define  DFE_HDMI_RX_PHY_P0_CK2_inst_addr                                        "0x0012"
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
#define  DFE_HDMI_RX_PHY_P0_CK3_inst_addr                                        "0x0013"
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
#define  DFE_HDMI_RX_PHY_P0_CK4_inst_addr                                        "0x0014"
#define  set_DFE_HDMI_RX_PHY_P0_CK4_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P0_CK4_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P0_CK4_reg))
#define  DFE_HDMI_RX_PHY_P0_CK4_reg_p0_ck_13_shift                               (0)
#define  DFE_HDMI_RX_PHY_P0_CK4_reg_p0_ck_13_mask                                (0x000000FF)
#define  DFE_HDMI_RX_PHY_P0_CK4_reg_p0_ck_13(data)                               (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P0_CK4_get_reg_p0_ck_13(data)                           (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P0_G1                                                   0x1800DA60
#define  DFE_HDMI_RX_PHY_P0_G1_reg_addr                                          "0xB800DA60"
#define  DFE_HDMI_RX_PHY_P0_G1_reg                                               0xB800DA60
#define  DFE_HDMI_RX_PHY_P0_G1_inst_addr                                         "0x0015"
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
#define  DFE_HDMI_RX_PHY_P0_G2_inst_addr                                         "0x0016"
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
#define  DFE_HDMI_RX_PHY_P0_G3_inst_addr                                         "0x0017"
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
#define  DFE_HDMI_RX_PHY_P0_G4_inst_addr                                         "0x0018"
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
#define  DFE_HDMI_RX_PHY_P0_R1_inst_addr                                         "0x0019"
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
#define  DFE_HDMI_RX_PHY_P0_R2_inst_addr                                         "0x001A"
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
#define  DFE_HDMI_RX_PHY_P0_R3_inst_addr                                         "0x001B"
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
#define  DFE_HDMI_RX_PHY_P0_R4_inst_addr                                         "0x001C"
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

#define  DFE_HDMI_RX_PHY_P1_ACDR1                                                0x1800DA80
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_addr                                       "0xB800DA80"
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg                                            0xB800DA80
#define  DFE_HDMI_RX_PHY_P1_ACDR1_inst_addr                                      "0x001D"
#define  set_DFE_HDMI_RX_PHY_P1_ACDR1_reg(data)                                  (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_ACDR1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_ACDR1_reg                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_ACDR1_reg))
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_4_shift                            (24)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_3_shift                            (16)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_2_shift                            (8)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_1_shift                            (0)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_4_mask                             (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_3_mask                             (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_2_mask                             (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_1_mask                             (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_4(data)                            (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_3(data)                            (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_2(data)                            (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_ACDR1_reg_p1_acdr_1(data)                            (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_ACDR1_get_reg_p1_acdr_4(data)                        ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_get_reg_p1_acdr_3(data)                        ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_get_reg_p1_acdr_2(data)                        ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_ACDR1_get_reg_p1_acdr_1(data)                        (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_ACDR2                                                0x1800DA84
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_addr                                       "0xB800DA84"
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg                                            0xB800DA84
#define  DFE_HDMI_RX_PHY_P1_ACDR2_inst_addr                                      "0x001E"
#define  set_DFE_HDMI_RX_PHY_P1_ACDR2_reg(data)                                  (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_ACDR2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_ACDR2_reg                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_ACDR2_reg))
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_8_shift                            (24)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_7_shift                            (16)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_6_shift                            (8)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_5_shift                            (0)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_8_mask                             (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_7_mask                             (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_6_mask                             (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_5_mask                             (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_8(data)                            (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_7(data)                            (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_6(data)                            (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_ACDR2_reg_p1_acdr_5(data)                            (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_ACDR2_get_reg_p1_acdr_8(data)                        ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_get_reg_p1_acdr_7(data)                        ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_get_reg_p1_acdr_6(data)                        ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_ACDR2_get_reg_p1_acdr_5(data)                        (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_B1                                                   0x1800DA90
#define  DFE_HDMI_RX_PHY_P1_B1_reg_addr                                          "0xB800DA90"
#define  DFE_HDMI_RX_PHY_P1_B1_reg                                               0xB800DA90
#define  DFE_HDMI_RX_PHY_P1_B1_inst_addr                                         "0x001F"
#define  set_DFE_HDMI_RX_PHY_P1_B1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_B1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_B1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_B1_reg))
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_B1_reg_p1_b_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_B1_get_reg_p1_b_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_B1_get_reg_p1_b_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_B1_get_reg_p1_b_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_B1_get_reg_p1_b_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_B2                                                   0x1800DA94
#define  DFE_HDMI_RX_PHY_P1_B2_reg_addr                                          "0xB800DA94"
#define  DFE_HDMI_RX_PHY_P1_B2_reg                                               0xB800DA94
#define  DFE_HDMI_RX_PHY_P1_B2_inst_addr                                         "0x0020"
#define  set_DFE_HDMI_RX_PHY_P1_B2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_B2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_B2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_B2_reg))
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_B2_reg_p1_b_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_B2_get_reg_p1_b_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_B2_get_reg_p1_b_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_B2_get_reg_p1_b_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_B2_get_reg_p1_b_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_B3                                                   0x1800DA98
#define  DFE_HDMI_RX_PHY_P1_B3_reg_addr                                          "0xB800DA98"
#define  DFE_HDMI_RX_PHY_P1_B3_reg                                               0xB800DA98
#define  DFE_HDMI_RX_PHY_P1_B3_inst_addr                                         "0x0021"
#define  set_DFE_HDMI_RX_PHY_P1_B3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_B3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_B3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_B3_reg))
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_B3_reg_p1_b_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_B3_get_reg_p1_b_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_B3_get_reg_p1_b_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_B3_get_reg_p1_b_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_B3_get_reg_p1_b_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_B4                                                   0x1800DA9C
#define  DFE_HDMI_RX_PHY_P1_B4_reg_addr                                          "0xB800DA9C"
#define  DFE_HDMI_RX_PHY_P1_B4_reg                                               0xB800DA9C
#define  DFE_HDMI_RX_PHY_P1_B4_inst_addr                                         "0x0022"
#define  set_DFE_HDMI_RX_PHY_P1_B4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_B4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_B4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_B4_reg))
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_B4_reg_p1_b_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_B4_get_reg_p1_b_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P1_B4_get_reg_p1_b_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P1_B4_get_reg_p1_b_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_B4_get_reg_p1_b_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_CK1                                                  0x1800DAA0
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_addr                                         "0xB800DAA0"
#define  DFE_HDMI_RX_PHY_P1_CK1_reg                                              0xB800DAA0
#define  DFE_HDMI_RX_PHY_P1_CK1_inst_addr                                        "0x0023"
#define  set_DFE_HDMI_RX_PHY_P1_CK1_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_CK1_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK1_reg))
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_4_shift                                (24)
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_3_shift                                (16)
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_2_shift                                (8)
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_1_shift                                (0)
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_4_mask                                 (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_3_mask                                 (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_2_mask                                 (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_1_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_4(data)                                (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_3(data)                                (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_2(data)                                (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_p1_ck_1(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_CK1_get_reg_p1_ck_4(data)                            ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_CK1_get_reg_p1_ck_3(data)                            ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_CK1_get_reg_p1_ck_2(data)                            ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_CK1_get_reg_p1_ck_1(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_CK2                                                  0x1800DAA4
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_addr                                         "0xB800DAA4"
#define  DFE_HDMI_RX_PHY_P1_CK2_reg                                              0xB800DAA4
#define  DFE_HDMI_RX_PHY_P1_CK2_inst_addr                                        "0x0024"
#define  set_DFE_HDMI_RX_PHY_P1_CK2_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_CK2_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK2_reg))
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_8_shift                                (24)
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_7_shift                                (16)
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_6_shift                                (8)
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_5_shift                                (0)
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_8_mask                                 (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_7_mask                                 (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_6_mask                                 (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_5_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_8(data)                                (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_7(data)                                (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_6(data)                                (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_p1_ck_5(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_CK2_get_reg_p1_ck_8(data)                            ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_CK2_get_reg_p1_ck_7(data)                            ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_CK2_get_reg_p1_ck_6(data)                            ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_CK2_get_reg_p1_ck_5(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_CK3                                                  0x1800DAA8
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_addr                                         "0xB800DAA8"
#define  DFE_HDMI_RX_PHY_P1_CK3_reg                                              0xB800DAA8
#define  DFE_HDMI_RX_PHY_P1_CK3_inst_addr                                        "0x0025"
#define  set_DFE_HDMI_RX_PHY_P1_CK3_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_CK3_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK3_reg))
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_12_shift                               (24)
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_11_shift                               (16)
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_10_shift                               (8)
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_9_shift                                (0)
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_12_mask                                (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_11_mask                                (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_10_mask                                (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_9_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_12(data)                               (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_11(data)                               (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_10(data)                               (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_p1_ck_9(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_CK3_get_reg_p1_ck_12(data)                           ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_CK3_get_reg_p1_ck_11(data)                           ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_CK3_get_reg_p1_ck_10(data)                           ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_CK3_get_reg_p1_ck_9(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_CK4                                                  0x1800DAAC
#define  DFE_HDMI_RX_PHY_P1_CK4_reg_addr                                         "0xB800DAAC"
#define  DFE_HDMI_RX_PHY_P1_CK4_reg                                              0xB800DAAC
#define  DFE_HDMI_RX_PHY_P1_CK4_inst_addr                                        "0x0026"
#define  set_DFE_HDMI_RX_PHY_P1_CK4_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_CK4_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK4_reg))
#define  DFE_HDMI_RX_PHY_P1_CK4_reg_p1_ck_13_shift                               (0)
#define  DFE_HDMI_RX_PHY_P1_CK4_reg_p1_ck_13_mask                                (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_CK4_reg_p1_ck_13(data)                               (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_CK4_get_reg_p1_ck_13(data)                           (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_G1                                                   0x1800DAB0
#define  DFE_HDMI_RX_PHY_P1_G1_reg_addr                                          "0xB800DAB0"
#define  DFE_HDMI_RX_PHY_P1_G1_reg                                               0xB800DAB0
#define  DFE_HDMI_RX_PHY_P1_G1_inst_addr                                         "0x0027"
#define  set_DFE_HDMI_RX_PHY_P1_G1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_G1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_G1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_G1_reg))
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_G1_reg_p1_g_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_G1_get_reg_p1_g_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_G1_get_reg_p1_g_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_G1_get_reg_p1_g_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_G1_get_reg_p1_g_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_G2                                                   0x1800DAB4
#define  DFE_HDMI_RX_PHY_P1_G2_reg_addr                                          "0xB800DAB4"
#define  DFE_HDMI_RX_PHY_P1_G2_reg                                               0xB800DAB4
#define  DFE_HDMI_RX_PHY_P1_G2_inst_addr                                         "0x0028"
#define  set_DFE_HDMI_RX_PHY_P1_G2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_G2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_G2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_G2_reg))
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_G2_reg_p1_g_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_G2_get_reg_p1_g_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_G2_get_reg_p1_g_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_G2_get_reg_p1_g_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_G2_get_reg_p1_g_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_G3                                                   0x1800DAB8
#define  DFE_HDMI_RX_PHY_P1_G3_reg_addr                                          "0xB800DAB8"
#define  DFE_HDMI_RX_PHY_P1_G3_reg                                               0xB800DAB8
#define  DFE_HDMI_RX_PHY_P1_G3_inst_addr                                         "0x0029"
#define  set_DFE_HDMI_RX_PHY_P1_G3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_G3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_G3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_G3_reg))
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_G3_reg_p1_g_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_G3_get_reg_p1_g_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_G3_get_reg_p1_g_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_G3_get_reg_p1_g_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_G3_get_reg_p1_g_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_G4                                                   0x1800DABC
#define  DFE_HDMI_RX_PHY_P1_G4_reg_addr                                          "0xB800DABC"
#define  DFE_HDMI_RX_PHY_P1_G4_reg                                               0xB800DABC
#define  DFE_HDMI_RX_PHY_P1_G4_inst_addr                                         "0x002A"
#define  set_DFE_HDMI_RX_PHY_P1_G4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_G4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_G4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_G4_reg))
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_G4_reg_p1_g_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_G4_get_reg_p1_g_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P1_G4_get_reg_p1_g_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P1_G4_get_reg_p1_g_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_G4_get_reg_p1_g_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_R1                                                   0x1800DAC0
#define  DFE_HDMI_RX_PHY_P1_R1_reg_addr                                          "0xB800DAC0"
#define  DFE_HDMI_RX_PHY_P1_R1_reg                                               0xB800DAC0
#define  DFE_HDMI_RX_PHY_P1_R1_inst_addr                                         "0x002B"
#define  set_DFE_HDMI_RX_PHY_P1_R1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_R1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_R1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_R1_reg))
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_R1_reg_p1_r_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_R1_get_reg_p1_r_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_R1_get_reg_p1_r_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_R1_get_reg_p1_r_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_R1_get_reg_p1_r_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_R2                                                   0x1800DAC4
#define  DFE_HDMI_RX_PHY_P1_R2_reg_addr                                          "0xB800DAC4"
#define  DFE_HDMI_RX_PHY_P1_R2_reg                                               0xB800DAC4
#define  DFE_HDMI_RX_PHY_P1_R2_inst_addr                                         "0x002C"
#define  set_DFE_HDMI_RX_PHY_P1_R2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_R2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_R2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_R2_reg))
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_R2_reg_p1_r_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_R2_get_reg_p1_r_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_R2_get_reg_p1_r_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_R2_get_reg_p1_r_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_R2_get_reg_p1_r_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_R3                                                   0x1800DAC8
#define  DFE_HDMI_RX_PHY_P1_R3_reg_addr                                          "0xB800DAC8"
#define  DFE_HDMI_RX_PHY_P1_R3_reg                                               0xB800DAC8
#define  DFE_HDMI_RX_PHY_P1_R3_inst_addr                                         "0x002D"
#define  set_DFE_HDMI_RX_PHY_P1_R3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_R3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_R3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_R3_reg))
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_R3_reg_p1_r_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_R3_get_reg_p1_r_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_R3_get_reg_p1_r_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_R3_get_reg_p1_r_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_R3_get_reg_p1_r_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_R4                                                   0x1800DACC
#define  DFE_HDMI_RX_PHY_P1_R4_reg_addr                                          "0xB800DACC"
#define  DFE_HDMI_RX_PHY_P1_R4_reg                                               0xB800DACC
#define  DFE_HDMI_RX_PHY_P1_R4_inst_addr                                         "0x002E"
#define  set_DFE_HDMI_RX_PHY_P1_R4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_R4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_R4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_R4_reg))
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_R4_reg_p1_r_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_R4_get_reg_p1_r_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P1_R4_get_reg_p1_r_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P1_R4_get_reg_p1_r_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_R4_get_reg_p1_r_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_ACDR1                                                0x1800DAD0
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_addr                                       "0xB800DAD0"
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg                                            0xB800DAD0
#define  DFE_HDMI_RX_PHY_P2_ACDR1_inst_addr                                      "0x002F"
#define  set_DFE_HDMI_RX_PHY_P2_ACDR1_reg(data)                                  (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_ACDR1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_ACDR1_reg                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_ACDR1_reg))
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_4_shift                            (24)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_3_shift                            (16)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_2_shift                            (8)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_1_shift                            (0)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_4_mask                             (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_3_mask                             (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_2_mask                             (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_1_mask                             (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_4(data)                            (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_3(data)                            (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_2(data)                            (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_ACDR1_reg_p2_acdr_1(data)                            (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_ACDR1_get_reg_p2_acdr_4(data)                        ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_get_reg_p2_acdr_3(data)                        ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_get_reg_p2_acdr_2(data)                        ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_ACDR1_get_reg_p2_acdr_1(data)                        (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_ACDR2                                                0x1800DAD4
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_addr                                       "0xB800DAD4"
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg                                            0xB800DAD4
#define  DFE_HDMI_RX_PHY_P2_ACDR2_inst_addr                                      "0x0030"
#define  set_DFE_HDMI_RX_PHY_P2_ACDR2_reg(data)                                  (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_ACDR2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_ACDR2_reg                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_ACDR2_reg))
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_8_shift                            (24)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_7_shift                            (16)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_6_shift                            (8)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_5_shift                            (0)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_8_mask                             (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_7_mask                             (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_6_mask                             (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_5_mask                             (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_8(data)                            (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_7(data)                            (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_6(data)                            (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_ACDR2_reg_p2_acdr_5(data)                            (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_ACDR2_get_reg_p2_acdr_8(data)                        ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_get_reg_p2_acdr_7(data)                        ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_get_reg_p2_acdr_6(data)                        ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_ACDR2_get_reg_p2_acdr_5(data)                        (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_B1                                                   0x1800DAE0
#define  DFE_HDMI_RX_PHY_P2_B1_reg_addr                                          "0xB800DAE0"
#define  DFE_HDMI_RX_PHY_P2_B1_reg                                               0xB800DAE0
#define  DFE_HDMI_RX_PHY_P2_B1_inst_addr                                         "0x0031"
#define  set_DFE_HDMI_RX_PHY_P2_B1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_B1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_B1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_B1_reg))
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_B1_reg_p2_b_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_B1_get_reg_p2_b_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_B1_get_reg_p2_b_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_B1_get_reg_p2_b_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_B1_get_reg_p2_b_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_B2                                                   0x1800DAE4
#define  DFE_HDMI_RX_PHY_P2_B2_reg_addr                                          "0xB800DAE4"
#define  DFE_HDMI_RX_PHY_P2_B2_reg                                               0xB800DAE4
#define  DFE_HDMI_RX_PHY_P2_B2_inst_addr                                         "0x0032"
#define  set_DFE_HDMI_RX_PHY_P2_B2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_B2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_B2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_B2_reg))
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_B2_reg_p2_b_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_B2_get_reg_p2_b_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_B2_get_reg_p2_b_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_B2_get_reg_p2_b_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_B2_get_reg_p2_b_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_B3                                                   0x1800DAE8
#define  DFE_HDMI_RX_PHY_P2_B3_reg_addr                                          "0xB800DAE8"
#define  DFE_HDMI_RX_PHY_P2_B3_reg                                               0xB800DAE8
#define  DFE_HDMI_RX_PHY_P2_B3_inst_addr                                         "0x0033"
#define  set_DFE_HDMI_RX_PHY_P2_B3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_B3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_B3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_B3_reg))
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_B3_reg_p2_b_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_B3_get_reg_p2_b_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_B3_get_reg_p2_b_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_B3_get_reg_p2_b_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_B3_get_reg_p2_b_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_B4                                                   0x1800DAEC
#define  DFE_HDMI_RX_PHY_P2_B4_reg_addr                                          "0xB800DAEC"
#define  DFE_HDMI_RX_PHY_P2_B4_reg                                               0xB800DAEC
#define  DFE_HDMI_RX_PHY_P2_B4_inst_addr                                         "0x0034"
#define  set_DFE_HDMI_RX_PHY_P2_B4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_B4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_B4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_B4_reg))
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_B4_reg_p2_b_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_B4_get_reg_p2_b_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P2_B4_get_reg_p2_b_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P2_B4_get_reg_p2_b_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_B4_get_reg_p2_b_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_CK1                                                  0x1800DAF0
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_addr                                         "0xB800DAF0"
#define  DFE_HDMI_RX_PHY_P2_CK1_reg                                              0xB800DAF0
#define  DFE_HDMI_RX_PHY_P2_CK1_inst_addr                                        "0x0035"
#define  set_DFE_HDMI_RX_PHY_P2_CK1_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_CK1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_CK1_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_CK1_reg))
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_4_shift                                (24)
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_3_shift                                (16)
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_2_shift                                (8)
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_1_shift                                (0)
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_4_mask                                 (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_3_mask                                 (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_2_mask                                 (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_1_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_4(data)                                (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_3(data)                                (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_2(data)                                (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_CK1_reg_p2_ck_1(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_CK1_get_reg_p2_ck_4(data)                            ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_CK1_get_reg_p2_ck_3(data)                            ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_CK1_get_reg_p2_ck_2(data)                            ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_CK1_get_reg_p2_ck_1(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_CK2                                                  0x1800DAF4
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_addr                                         "0xB800DAF4"
#define  DFE_HDMI_RX_PHY_P2_CK2_reg                                              0xB800DAF4
#define  DFE_HDMI_RX_PHY_P2_CK2_inst_addr                                        "0x0036"
#define  set_DFE_HDMI_RX_PHY_P2_CK2_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_CK2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_CK2_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_CK2_reg))
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_8_shift                                (24)
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_7_shift                                (16)
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_6_shift                                (8)
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_5_shift                                (0)
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_8_mask                                 (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_7_mask                                 (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_6_mask                                 (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_5_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_8(data)                                (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_7(data)                                (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_6(data)                                (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_CK2_reg_p2_ck_5(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_CK2_get_reg_p2_ck_8(data)                            ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_CK2_get_reg_p2_ck_7(data)                            ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_CK2_get_reg_p2_ck_6(data)                            ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_CK2_get_reg_p2_ck_5(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_CK3                                                  0x1800DAF8
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_addr                                         "0xB800DAF8"
#define  DFE_HDMI_RX_PHY_P2_CK3_reg                                              0xB800DAF8
#define  DFE_HDMI_RX_PHY_P2_CK3_inst_addr                                        "0x0037"
#define  set_DFE_HDMI_RX_PHY_P2_CK3_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_CK3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_CK3_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_CK3_reg))
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_12_shift                               (24)
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_11_shift                               (16)
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_10_shift                               (8)
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_9_shift                                (0)
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_12_mask                                (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_11_mask                                (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_10_mask                                (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_9_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_12(data)                               (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_11(data)                               (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_10(data)                               (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_CK3_reg_p2_ck_9(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_CK3_get_reg_p2_ck_12(data)                           ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_CK3_get_reg_p2_ck_11(data)                           ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_CK3_get_reg_p2_ck_10(data)                           ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_CK3_get_reg_p2_ck_9(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_CK4                                                  0x1800DAFC
#define  DFE_HDMI_RX_PHY_P2_CK4_reg_addr                                         "0xB800DAFC"
#define  DFE_HDMI_RX_PHY_P2_CK4_reg                                              0xB800DAFC
#define  DFE_HDMI_RX_PHY_P2_CK4_inst_addr                                        "0x0038"
#define  set_DFE_HDMI_RX_PHY_P2_CK4_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_CK4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_CK4_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_CK4_reg))
#define  DFE_HDMI_RX_PHY_P2_CK4_reg_p2_ck_13_shift                               (0)
#define  DFE_HDMI_RX_PHY_P2_CK4_reg_p2_ck_13_mask                                (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_CK4_reg_p2_ck_13(data)                               (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_CK4_get_reg_p2_ck_13(data)                           (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_G1                                                   0x1800DB00
#define  DFE_HDMI_RX_PHY_P2_G1_reg_addr                                          "0xB800DB00"
#define  DFE_HDMI_RX_PHY_P2_G1_reg                                               0xB800DB00
#define  DFE_HDMI_RX_PHY_P2_G1_inst_addr                                         "0x0039"
#define  set_DFE_HDMI_RX_PHY_P2_G1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_G1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_G1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_G1_reg))
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_G1_reg_p2_g_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_G1_get_reg_p2_g_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_G1_get_reg_p2_g_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_G1_get_reg_p2_g_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_G1_get_reg_p2_g_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_G2                                                   0x1800DB04
#define  DFE_HDMI_RX_PHY_P2_G2_reg_addr                                          "0xB800DB04"
#define  DFE_HDMI_RX_PHY_P2_G2_reg                                               0xB800DB04
#define  DFE_HDMI_RX_PHY_P2_G2_inst_addr                                         "0x003A"
#define  set_DFE_HDMI_RX_PHY_P2_G2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_G2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_G2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_G2_reg))
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_G2_reg_p2_g_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_G2_get_reg_p2_g_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_G2_get_reg_p2_g_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_G2_get_reg_p2_g_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_G2_get_reg_p2_g_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_G3                                                   0x1800DB08
#define  DFE_HDMI_RX_PHY_P2_G3_reg_addr                                          "0xB800DB08"
#define  DFE_HDMI_RX_PHY_P2_G3_reg                                               0xB800DB08
#define  DFE_HDMI_RX_PHY_P2_G3_inst_addr                                         "0x003B"
#define  set_DFE_HDMI_RX_PHY_P2_G3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_G3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_G3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_G3_reg))
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_G3_reg_p2_g_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_G3_get_reg_p2_g_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_G3_get_reg_p2_g_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_G3_get_reg_p2_g_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_G3_get_reg_p2_g_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_G4                                                   0x1800DB0C
#define  DFE_HDMI_RX_PHY_P2_G4_reg_addr                                          "0xB800DB0C"
#define  DFE_HDMI_RX_PHY_P2_G4_reg                                               0xB800DB0C
#define  DFE_HDMI_RX_PHY_P2_G4_inst_addr                                         "0x003C"
#define  set_DFE_HDMI_RX_PHY_P2_G4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_G4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_G4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_G4_reg))
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_G4_reg_p2_g_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_G4_get_reg_p2_g_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P2_G4_get_reg_p2_g_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P2_G4_get_reg_p2_g_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_G4_get_reg_p2_g_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_R1                                                   0x1800DB10
#define  DFE_HDMI_RX_PHY_P2_R1_reg_addr                                          "0xB800DB10"
#define  DFE_HDMI_RX_PHY_P2_R1_reg                                               0xB800DB10
#define  DFE_HDMI_RX_PHY_P2_R1_inst_addr                                         "0x003D"
#define  set_DFE_HDMI_RX_PHY_P2_R1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_R1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_R1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_R1_reg))
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_R1_reg_p2_r_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_R1_get_reg_p2_r_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_R1_get_reg_p2_r_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_R1_get_reg_p2_r_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_R1_get_reg_p2_r_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_R2                                                   0x1800DB14
#define  DFE_HDMI_RX_PHY_P2_R2_reg_addr                                          "0xB800DB14"
#define  DFE_HDMI_RX_PHY_P2_R2_reg                                               0xB800DB14
#define  DFE_HDMI_RX_PHY_P2_R2_inst_addr                                         "0x003E"
#define  set_DFE_HDMI_RX_PHY_P2_R2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_R2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_R2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_R2_reg))
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_R2_reg_p2_r_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_R2_get_reg_p2_r_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_R2_get_reg_p2_r_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_R2_get_reg_p2_r_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_R2_get_reg_p2_r_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_R3                                                   0x1800DB18
#define  DFE_HDMI_RX_PHY_P2_R3_reg_addr                                          "0xB800DB18"
#define  DFE_HDMI_RX_PHY_P2_R3_reg                                               0xB800DB18
#define  DFE_HDMI_RX_PHY_P2_R3_inst_addr                                         "0x003F"
#define  set_DFE_HDMI_RX_PHY_P2_R3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_R3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_R3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_R3_reg))
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_R3_reg_p2_r_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_R3_get_reg_p2_r_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P2_R3_get_reg_p2_r_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P2_R3_get_reg_p2_r_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_R3_get_reg_p2_r_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P2_R4                                                   0x1800DB1C
#define  DFE_HDMI_RX_PHY_P2_R4_reg_addr                                          "0xB800DB1C"
#define  DFE_HDMI_RX_PHY_P2_R4_reg                                               0xB800DB1C
#define  DFE_HDMI_RX_PHY_P2_R4_inst_addr                                         "0x0040"
#define  set_DFE_HDMI_RX_PHY_P2_R4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_R4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P2_R4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P2_R4_reg))
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P2_R4_reg_p2_r_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P2_R4_get_reg_p2_r_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P2_R4_get_reg_p2_r_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P2_R4_get_reg_p2_r_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P2_R4_get_reg_p2_r_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_ACDR1                                                0x1800DB20
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_addr                                       "0xB800DB20"
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg                                            0xB800DB20
#define  DFE_HDMI_RX_PHY_P3_ACDR1_inst_addr                                      "0x0041"
#define  set_DFE_HDMI_RX_PHY_P3_ACDR1_reg(data)                                  (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_ACDR1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_ACDR1_reg                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_ACDR1_reg))
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_4_shift                            (24)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_3_shift                            (16)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_2_shift                            (8)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_1_shift                            (0)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_4_mask                             (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_3_mask                             (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_2_mask                             (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_1_mask                             (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_4(data)                            (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_3(data)                            (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_2(data)                            (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_ACDR1_reg_p3_acdr_1(data)                            (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_ACDR1_get_reg_p3_acdr_4(data)                        ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_get_reg_p3_acdr_3(data)                        ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_get_reg_p3_acdr_2(data)                        ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_ACDR1_get_reg_p3_acdr_1(data)                        (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_ACDR2                                                0x1800DB24
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_addr                                       "0xB800DB24"
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg                                            0xB800DB24
#define  DFE_HDMI_RX_PHY_P3_ACDR2_inst_addr                                      "0x0042"
#define  set_DFE_HDMI_RX_PHY_P3_ACDR2_reg(data)                                  (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_ACDR2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_ACDR2_reg                                        (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_ACDR2_reg))
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_8_shift                            (24)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_7_shift                            (16)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_6_shift                            (8)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_5_shift                            (0)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_8_mask                             (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_7_mask                             (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_6_mask                             (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_5_mask                             (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_8(data)                            (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_7(data)                            (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_6(data)                            (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_ACDR2_reg_p3_acdr_5(data)                            (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_ACDR2_get_reg_p3_acdr_8(data)                        ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_get_reg_p3_acdr_7(data)                        ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_get_reg_p3_acdr_6(data)                        ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_ACDR2_get_reg_p3_acdr_5(data)                        (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_B1                                                   0x1800DB30
#define  DFE_HDMI_RX_PHY_P3_B1_reg_addr                                          "0xB800DB30"
#define  DFE_HDMI_RX_PHY_P3_B1_reg                                               0xB800DB30
#define  DFE_HDMI_RX_PHY_P3_B1_inst_addr                                         "0x0043"
#define  set_DFE_HDMI_RX_PHY_P3_B1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_B1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_B1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_B1_reg))
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_B1_reg_p3_b_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_B1_get_reg_p3_b_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_B1_get_reg_p3_b_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_B1_get_reg_p3_b_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_B1_get_reg_p3_b_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_B2                                                   0x1800DB34
#define  DFE_HDMI_RX_PHY_P3_B2_reg_addr                                          "0xB800DB34"
#define  DFE_HDMI_RX_PHY_P3_B2_reg                                               0xB800DB34
#define  DFE_HDMI_RX_PHY_P3_B2_inst_addr                                         "0x0044"
#define  set_DFE_HDMI_RX_PHY_P3_B2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_B2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_B2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_B2_reg))
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_B2_reg_p3_b_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_B2_get_reg_p3_b_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_B2_get_reg_p3_b_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_B2_get_reg_p3_b_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_B2_get_reg_p3_b_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_B3                                                   0x1800DB38
#define  DFE_HDMI_RX_PHY_P3_B3_reg_addr                                          "0xB800DB38"
#define  DFE_HDMI_RX_PHY_P3_B3_reg                                               0xB800DB38
#define  DFE_HDMI_RX_PHY_P3_B3_inst_addr                                         "0x0045"
#define  set_DFE_HDMI_RX_PHY_P3_B3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_B3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_B3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_B3_reg))
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_B3_reg_p3_b_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_B3_get_reg_p3_b_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_B3_get_reg_p3_b_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_B3_get_reg_p3_b_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_B3_get_reg_p3_b_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_B4                                                   0x1800DB3C
#define  DFE_HDMI_RX_PHY_P3_B4_reg_addr                                          "0xB800DB3C"
#define  DFE_HDMI_RX_PHY_P3_B4_reg                                               0xB800DB3C
#define  DFE_HDMI_RX_PHY_P3_B4_inst_addr                                         "0x0046"
#define  set_DFE_HDMI_RX_PHY_P3_B4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_B4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_B4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_B4_reg))
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_B4_reg_p3_b_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_B4_get_reg_p3_b_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P3_B4_get_reg_p3_b_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P3_B4_get_reg_p3_b_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_B4_get_reg_p3_b_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_CK1                                                  0x1800DB40
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_addr                                         "0xB800DB40"
#define  DFE_HDMI_RX_PHY_P3_CK1_reg                                              0xB800DB40
#define  DFE_HDMI_RX_PHY_P3_CK1_inst_addr                                        "0x0047"
#define  set_DFE_HDMI_RX_PHY_P3_CK1_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_CK1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_CK1_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_CK1_reg))
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_4_shift                                (24)
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_3_shift                                (16)
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_2_shift                                (8)
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_1_shift                                (0)
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_4_mask                                 (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_3_mask                                 (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_2_mask                                 (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_1_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_4(data)                                (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_3(data)                                (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_2(data)                                (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_CK1_reg_p3_ck_1(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_CK1_get_reg_p3_ck_4(data)                            ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_CK1_get_reg_p3_ck_3(data)                            ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_CK1_get_reg_p3_ck_2(data)                            ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_CK1_get_reg_p3_ck_1(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_CK2                                                  0x1800DB44
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_addr                                         "0xB800DB44"
#define  DFE_HDMI_RX_PHY_P3_CK2_reg                                              0xB800DB44
#define  DFE_HDMI_RX_PHY_P3_CK2_inst_addr                                        "0x0048"
#define  set_DFE_HDMI_RX_PHY_P3_CK2_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_CK2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_CK2_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_CK2_reg))
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_8_shift                                (24)
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_7_shift                                (16)
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_6_shift                                (8)
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_5_shift                                (0)
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_8_mask                                 (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_7_mask                                 (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_6_mask                                 (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_5_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_8(data)                                (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_7(data)                                (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_6(data)                                (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_CK2_reg_p3_ck_5(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_CK2_get_reg_p3_ck_8(data)                            ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_CK2_get_reg_p3_ck_7(data)                            ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_CK2_get_reg_p3_ck_6(data)                            ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_CK2_get_reg_p3_ck_5(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_CK3                                                  0x1800DB48
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_addr                                         "0xB800DB48"
#define  DFE_HDMI_RX_PHY_P3_CK3_reg                                              0xB800DB48
#define  DFE_HDMI_RX_PHY_P3_CK3_inst_addr                                        "0x0049"
#define  set_DFE_HDMI_RX_PHY_P3_CK3_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_CK3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_CK3_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_CK3_reg))
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_12_shift                               (24)
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_11_shift                               (16)
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_10_shift                               (8)
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_9_shift                                (0)
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_12_mask                                (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_11_mask                                (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_10_mask                                (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_9_mask                                 (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_12(data)                               (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_11(data)                               (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_10(data)                               (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_CK3_reg_p3_ck_9(data)                                (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_CK3_get_reg_p3_ck_12(data)                           ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_CK3_get_reg_p3_ck_11(data)                           ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_CK3_get_reg_p3_ck_10(data)                           ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_CK3_get_reg_p3_ck_9(data)                            (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_CK4                                                  0x1800DB4C
#define  DFE_HDMI_RX_PHY_P3_CK4_reg_addr                                         "0xB800DB4C"
#define  DFE_HDMI_RX_PHY_P3_CK4_reg                                              0xB800DB4C
#define  DFE_HDMI_RX_PHY_P3_CK4_inst_addr                                        "0x004A"
#define  set_DFE_HDMI_RX_PHY_P3_CK4_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_CK4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_CK4_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_CK4_reg))
#define  DFE_HDMI_RX_PHY_P3_CK4_reg_p3_ck_13_shift                               (0)
#define  DFE_HDMI_RX_PHY_P3_CK4_reg_p3_ck_13_mask                                (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_CK4_reg_p3_ck_13(data)                               (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_CK4_get_reg_p3_ck_13(data)                           (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_G1                                                   0x1800DB50
#define  DFE_HDMI_RX_PHY_P3_G1_reg_addr                                          "0xB800DB50"
#define  DFE_HDMI_RX_PHY_P3_G1_reg                                               0xB800DB50
#define  DFE_HDMI_RX_PHY_P3_G1_inst_addr                                         "0x004B"
#define  set_DFE_HDMI_RX_PHY_P3_G1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_G1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_G1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_G1_reg))
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_G1_reg_p3_g_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_G1_get_reg_p3_g_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_G1_get_reg_p3_g_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_G1_get_reg_p3_g_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_G1_get_reg_p3_g_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_G2                                                   0x1800DB54
#define  DFE_HDMI_RX_PHY_P3_G2_reg_addr                                          "0xB800DB54"
#define  DFE_HDMI_RX_PHY_P3_G2_reg                                               0xB800DB54
#define  DFE_HDMI_RX_PHY_P3_G2_inst_addr                                         "0x004C"
#define  set_DFE_HDMI_RX_PHY_P3_G2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_G2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_G2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_G2_reg))
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_G2_reg_p3_g_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_G2_get_reg_p3_g_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_G2_get_reg_p3_g_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_G2_get_reg_p3_g_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_G2_get_reg_p3_g_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_G3                                                   0x1800DB58
#define  DFE_HDMI_RX_PHY_P3_G3_reg_addr                                          "0xB800DB58"
#define  DFE_HDMI_RX_PHY_P3_G3_reg                                               0xB800DB58
#define  DFE_HDMI_RX_PHY_P3_G3_inst_addr                                         "0x004D"
#define  set_DFE_HDMI_RX_PHY_P3_G3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_G3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_G3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_G3_reg))
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_G3_reg_p3_g_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_G3_get_reg_p3_g_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_G3_get_reg_p3_g_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_G3_get_reg_p3_g_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_G3_get_reg_p3_g_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_G4                                                   0x1800DB5C
#define  DFE_HDMI_RX_PHY_P3_G4_reg_addr                                          "0xB800DB5C"
#define  DFE_HDMI_RX_PHY_P3_G4_reg                                               0xB800DB5C
#define  DFE_HDMI_RX_PHY_P3_G4_inst_addr                                         "0x004E"
#define  set_DFE_HDMI_RX_PHY_P3_G4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_G4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_G4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_G4_reg))
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_G4_reg_p3_g_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_G4_get_reg_p3_g_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P3_G4_get_reg_p3_g_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P3_G4_get_reg_p3_g_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_G4_get_reg_p3_g_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_R1                                                   0x1800DB60
#define  DFE_HDMI_RX_PHY_P3_R1_reg_addr                                          "0xB800DB60"
#define  DFE_HDMI_RX_PHY_P3_R1_reg                                               0xB800DB60
#define  DFE_HDMI_RX_PHY_P3_R1_inst_addr                                         "0x004F"
#define  set_DFE_HDMI_RX_PHY_P3_R1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_R1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_R1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_R1_reg))
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_4_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_3_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_2_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_1_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_4_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_3_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_2_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_1_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_4(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_3(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_2(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_R1_reg_p3_r_1(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_R1_get_reg_p3_r_4(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_R1_get_reg_p3_r_3(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_R1_get_reg_p3_r_2(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_R1_get_reg_p3_r_1(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_R2                                                   0x1800DB64
#define  DFE_HDMI_RX_PHY_P3_R2_reg_addr                                          "0xB800DB64"
#define  DFE_HDMI_RX_PHY_P3_R2_reg                                               0xB800DB64
#define  DFE_HDMI_RX_PHY_P3_R2_inst_addr                                         "0x0050"
#define  set_DFE_HDMI_RX_PHY_P3_R2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_R2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_R2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_R2_reg))
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_8_shift                                  (24)
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_7_shift                                  (16)
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_6_shift                                  (8)
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_5_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_8_mask                                   (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_7_mask                                   (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_6_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_5_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_8(data)                                  (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_7(data)                                  (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_6(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_R2_reg_p3_r_5(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_R2_get_reg_p3_r_8(data)                              ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_R2_get_reg_p3_r_7(data)                              ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_R2_get_reg_p3_r_6(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_R2_get_reg_p3_r_5(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_R3                                                   0x1800DB68
#define  DFE_HDMI_RX_PHY_P3_R3_reg_addr                                          "0xB800DB68"
#define  DFE_HDMI_RX_PHY_P3_R3_reg                                               0xB800DB68
#define  DFE_HDMI_RX_PHY_P3_R3_inst_addr                                         "0x0051"
#define  set_DFE_HDMI_RX_PHY_P3_R3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_R3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_R3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_R3_reg))
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_12_shift                                 (24)
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_11_shift                                 (16)
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_10_shift                                 (8)
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_9_shift                                  (0)
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_12_mask                                  (0xFF000000)
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_11_mask                                  (0x00FF0000)
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_10_mask                                  (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_9_mask                                   (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_12(data)                                 (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_11(data)                                 (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_10(data)                                 (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_R3_reg_p3_r_9(data)                                  (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_R3_get_reg_p3_r_12(data)                             ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P3_R3_get_reg_p3_r_11(data)                             ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P3_R3_get_reg_p3_r_10(data)                             ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_R3_get_reg_p3_r_9(data)                              (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P3_R4                                                   0x1800DB6C
#define  DFE_HDMI_RX_PHY_P3_R4_reg_addr                                          "0xB800DB6C"
#define  DFE_HDMI_RX_PHY_P3_R4_reg                                               0xB800DB6C
#define  DFE_HDMI_RX_PHY_P3_R4_inst_addr                                         "0x0052"
#define  set_DFE_HDMI_RX_PHY_P3_R4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_R4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P3_R4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P3_R4_reg))
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_koff_sel_shift                           (10)
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_koff_bound_shift                         (9)
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_koffok_shift                             (8)
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_13_shift                                 (0)
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_koff_sel_mask                            (0x00007C00)
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_koff_bound_mask                          (0x00000200)
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_koffok_mask                              (0x00000100)
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_13_mask                                  (0x000000FF)
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_koff_sel(data)                           (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_koff_bound(data)                         (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_koffok(data)                             (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P3_R4_reg_p3_r_13(data)                                 (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P3_R4_get_reg_p3_r_koff_sel(data)                       ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P3_R4_get_reg_p3_r_koff_bound(data)                     ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P3_R4_get_reg_p3_r_koffok(data)                         ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_P3_R4_get_reg_p3_r_13(data)                             (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_EYE1                                                    0x1800DB70
#define  DFE_HDMI_RX_PHY_EYE1_reg_addr                                           "0xB800DB70"
#define  DFE_HDMI_RX_PHY_EYE1_reg                                                0xB800DB70
#define  DFE_HDMI_RX_PHY_EYE1_inst_addr                                          "0x0053"
#define  set_DFE_HDMI_RX_PHY_EYE1_reg(data)                                      (*((volatile unsigned int*)DFE_HDMI_RX_PHY_EYE1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_EYE1_reg                                            (*((volatile unsigned int*)DFE_HDMI_RX_PHY_EYE1_reg))
#define  DFE_HDMI_RX_PHY_EYE1_reg_eye_ref_ctrl_shift                             (4)
#define  DFE_HDMI_RX_PHY_EYE1_reg_eye_pi_en_shift                                (0)
#define  DFE_HDMI_RX_PHY_EYE1_reg_eye_ref_ctrl_mask                              (0x000003F0)
#define  DFE_HDMI_RX_PHY_EYE1_reg_eye_pi_en_mask                                 (0x0000000F)
#define  DFE_HDMI_RX_PHY_EYE1_reg_eye_ref_ctrl(data)                             (0x000003F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_EYE1_reg_eye_pi_en(data)                                (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_EYE1_get_reg_eye_ref_ctrl(data)                         ((0x000003F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_EYE1_get_reg_eye_pi_en(data)                            (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_EYE2                                                    0x1800DB74
#define  DFE_HDMI_RX_PHY_EYE2_reg_addr                                           "0xB800DB74"
#define  DFE_HDMI_RX_PHY_EYE2_reg                                                0xB800DB74
#define  DFE_HDMI_RX_PHY_EYE2_inst_addr                                          "0x0054"
#define  set_DFE_HDMI_RX_PHY_EYE2_reg(data)                                      (*((volatile unsigned int*)DFE_HDMI_RX_PHY_EYE2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_EYE2_reg                                            (*((volatile unsigned int*)DFE_HDMI_RX_PHY_EYE2_reg))
#define  DFE_HDMI_RX_PHY_EYE2_reg_eye_pi_st_shift                                (0)
#define  DFE_HDMI_RX_PHY_EYE2_reg_eye_pi_st_mask                                 (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_EYE2_reg_eye_pi_st(data)                                (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_EYE2_get_reg_eye_pi_st(data)                            (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_BYPASS                                                  0x1800DB78
#define  DFE_HDMI_RX_PHY_BYPASS_reg_addr                                         "0xB800DB78"
#define  DFE_HDMI_RX_PHY_BYPASS_reg                                              0xB800DB78
#define  DFE_HDMI_RX_PHY_BYPASS_inst_addr                                        "0x0055"
#define  set_DFE_HDMI_RX_PHY_BYPASS_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_BYPASS_reg)=data)
#define  get_DFE_HDMI_RX_PHY_BYPASS_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_BYPASS_reg))
#define  DFE_HDMI_RX_PHY_BYPASS_p3_bypass_ok_shift                               (3)
#define  DFE_HDMI_RX_PHY_BYPASS_p2_bypass_ok_shift                               (2)
#define  DFE_HDMI_RX_PHY_BYPASS_p1_bypass_ok_shift                               (1)
#define  DFE_HDMI_RX_PHY_BYPASS_p0_bypass_ok_shift                               (0)
#define  DFE_HDMI_RX_PHY_BYPASS_p3_bypass_ok_mask                                (0x00000008)
#define  DFE_HDMI_RX_PHY_BYPASS_p2_bypass_ok_mask                                (0x00000004)
#define  DFE_HDMI_RX_PHY_BYPASS_p1_bypass_ok_mask                                (0x00000002)
#define  DFE_HDMI_RX_PHY_BYPASS_p0_bypass_ok_mask                                (0x00000001)
#define  DFE_HDMI_RX_PHY_BYPASS_p3_bypass_ok(data)                               (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_BYPASS_p2_bypass_ok(data)                               (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_BYPASS_p1_bypass_ok(data)                               (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_BYPASS_p0_bypass_ok(data)                               (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_BYPASS_get_p3_bypass_ok(data)                           ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_BYPASS_get_p2_bypass_ok(data)                           ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_BYPASS_get_p1_bypass_ok(data)                           ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_BYPASS_get_p0_bypass_ok(data)                           (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_RST                                                     0x1800DB7C
#define  DFE_HDMI_RX_PHY_RST_reg_addr                                            "0xB800DB7C"
#define  DFE_HDMI_RX_PHY_RST_reg                                                 0xB800DB7C
#define  DFE_HDMI_RX_PHY_RST_inst_addr                                           "0x0056"
#define  set_DFE_HDMI_RX_PHY_RST_reg(data)                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_RST_reg)=data)
#define  get_DFE_HDMI_RX_PHY_RST_reg                                             (*((volatile unsigned int*)DFE_HDMI_RX_PHY_RST_reg))
#define  DFE_HDMI_RX_PHY_RST_eye_monitor_rstn_shift                              (25)
#define  DFE_HDMI_RX_PHY_RST_reg_p3_acdr_rstb_fsm_shift                          (23)
#define  DFE_HDMI_RX_PHY_RST_reg_p2_acdr_rstb_fsm_shift                          (22)
#define  DFE_HDMI_RX_PHY_RST_reg_p1_acdr_rstb_fsm_shift                          (21)
#define  DFE_HDMI_RX_PHY_RST_reg_p0_acdr_rstb_fsm_shift                          (20)
#define  DFE_HDMI_RX_PHY_RST_p3_ck_vcorstb_shift                                 (19)
#define  DFE_HDMI_RX_PHY_RST_p2_ck_vcorstb_shift                                 (18)
#define  DFE_HDMI_RX_PHY_RST_p1_ck_vcorstb_shift                                 (17)
#define  DFE_HDMI_RX_PHY_RST_p0_ck_vcorstb_shift                                 (16)
#define  DFE_HDMI_RX_PHY_RST_p3_ck_pllrstb_shift                                 (15)
#define  DFE_HDMI_RX_PHY_RST_p2_ck_pllrstb_shift                                 (14)
#define  DFE_HDMI_RX_PHY_RST_p1_ck_pllrstb_shift                                 (13)
#define  DFE_HDMI_RX_PHY_RST_p0_ck_pllrstb_shift                                 (12)
#define  DFE_HDMI_RX_PHY_RST_p3_r_demux_rstb_shift                               (11)
#define  DFE_HDMI_RX_PHY_RST_p3_g_demux_rstb_shift                               (10)
#define  DFE_HDMI_RX_PHY_RST_p3_b_demux_rstb_shift                               (9)
#define  DFE_HDMI_RX_PHY_RST_p2_r_demux_rstb_shift                               (8)
#define  DFE_HDMI_RX_PHY_RST_p2_g_demux_rstb_shift                               (7)
#define  DFE_HDMI_RX_PHY_RST_p2_b_demux_rstb_shift                               (6)
#define  DFE_HDMI_RX_PHY_RST_p1_r_demux_rstb_shift                               (5)
#define  DFE_HDMI_RX_PHY_RST_p1_g_demux_rstb_shift                               (4)
#define  DFE_HDMI_RX_PHY_RST_p1_b_demux_rstb_shift                               (3)
#define  DFE_HDMI_RX_PHY_RST_p0_r_demux_rstb_shift                               (2)
#define  DFE_HDMI_RX_PHY_RST_p0_g_demux_rstb_shift                               (1)
#define  DFE_HDMI_RX_PHY_RST_p0_b_demux_rstb_shift                               (0)
#define  DFE_HDMI_RX_PHY_RST_eye_monitor_rstn_mask                               (0x02000000)
#define  DFE_HDMI_RX_PHY_RST_reg_p3_acdr_rstb_fsm_mask                           (0x00800000)
#define  DFE_HDMI_RX_PHY_RST_reg_p2_acdr_rstb_fsm_mask                           (0x00400000)
#define  DFE_HDMI_RX_PHY_RST_reg_p1_acdr_rstb_fsm_mask                           (0x00200000)
#define  DFE_HDMI_RX_PHY_RST_reg_p0_acdr_rstb_fsm_mask                           (0x00100000)
#define  DFE_HDMI_RX_PHY_RST_p3_ck_vcorstb_mask                                  (0x00080000)
#define  DFE_HDMI_RX_PHY_RST_p2_ck_vcorstb_mask                                  (0x00040000)
#define  DFE_HDMI_RX_PHY_RST_p1_ck_vcorstb_mask                                  (0x00020000)
#define  DFE_HDMI_RX_PHY_RST_p0_ck_vcorstb_mask                                  (0x00010000)
#define  DFE_HDMI_RX_PHY_RST_p3_ck_pllrstb_mask                                  (0x00008000)
#define  DFE_HDMI_RX_PHY_RST_p2_ck_pllrstb_mask                                  (0x00004000)
#define  DFE_HDMI_RX_PHY_RST_p1_ck_pllrstb_mask                                  (0x00002000)
#define  DFE_HDMI_RX_PHY_RST_p0_ck_pllrstb_mask                                  (0x00001000)
#define  DFE_HDMI_RX_PHY_RST_p3_r_demux_rstb_mask                                (0x00000800)
#define  DFE_HDMI_RX_PHY_RST_p3_g_demux_rstb_mask                                (0x00000400)
#define  DFE_HDMI_RX_PHY_RST_p3_b_demux_rstb_mask                                (0x00000200)
#define  DFE_HDMI_RX_PHY_RST_p2_r_demux_rstb_mask                                (0x00000100)
#define  DFE_HDMI_RX_PHY_RST_p2_g_demux_rstb_mask                                (0x00000080)
#define  DFE_HDMI_RX_PHY_RST_p2_b_demux_rstb_mask                                (0x00000040)
#define  DFE_HDMI_RX_PHY_RST_p1_r_demux_rstb_mask                                (0x00000020)
#define  DFE_HDMI_RX_PHY_RST_p1_g_demux_rstb_mask                                (0x00000010)
#define  DFE_HDMI_RX_PHY_RST_p1_b_demux_rstb_mask                                (0x00000008)
#define  DFE_HDMI_RX_PHY_RST_p0_r_demux_rstb_mask                                (0x00000004)
#define  DFE_HDMI_RX_PHY_RST_p0_g_demux_rstb_mask                                (0x00000002)
#define  DFE_HDMI_RX_PHY_RST_p0_b_demux_rstb_mask                                (0x00000001)
#define  DFE_HDMI_RX_PHY_RST_eye_monitor_rstn(data)                              (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_RST_reg_p3_acdr_rstb_fsm(data)                          (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_RST_reg_p2_acdr_rstb_fsm(data)                          (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_RST_reg_p1_acdr_rstb_fsm(data)                          (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_RST_reg_p0_acdr_rstb_fsm(data)                          (0x00100000&((data)<<20))
#define  DFE_HDMI_RX_PHY_RST_p3_ck_vcorstb(data)                                 (0x00080000&((data)<<19))
#define  DFE_HDMI_RX_PHY_RST_p2_ck_vcorstb(data)                                 (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_RST_p1_ck_vcorstb(data)                                 (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_RST_p0_ck_vcorstb(data)                                 (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_RST_p3_ck_pllrstb(data)                                 (0x00008000&((data)<<15))
#define  DFE_HDMI_RX_PHY_RST_p2_ck_pllrstb(data)                                 (0x00004000&((data)<<14))
#define  DFE_HDMI_RX_PHY_RST_p1_ck_pllrstb(data)                                 (0x00002000&((data)<<13))
#define  DFE_HDMI_RX_PHY_RST_p0_ck_pllrstb(data)                                 (0x00001000&((data)<<12))
#define  DFE_HDMI_RX_PHY_RST_p3_r_demux_rstb(data)                               (0x00000800&((data)<<11))
#define  DFE_HDMI_RX_PHY_RST_p3_g_demux_rstb(data)                               (0x00000400&((data)<<10))
#define  DFE_HDMI_RX_PHY_RST_p3_b_demux_rstb(data)                               (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_RST_p2_r_demux_rstb(data)                               (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_RST_p2_g_demux_rstb(data)                               (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_RST_p2_b_demux_rstb(data)                               (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_RST_p1_r_demux_rstb(data)                               (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_RST_p1_g_demux_rstb(data)                               (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_RST_p1_b_demux_rstb(data)                               (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_RST_p0_r_demux_rstb(data)                               (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_RST_p0_g_demux_rstb(data)                               (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_RST_p0_b_demux_rstb(data)                               (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_RST_get_eye_monitor_rstn(data)                          ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_RST_get_reg_p3_acdr_rstb_fsm(data)                      ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_RST_get_reg_p2_acdr_rstb_fsm(data)                      ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_RST_get_reg_p1_acdr_rstb_fsm(data)                      ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_RST_get_reg_p0_acdr_rstb_fsm(data)                      ((0x00100000&(data))>>20)
#define  DFE_HDMI_RX_PHY_RST_get_p3_ck_vcorstb(data)                             ((0x00080000&(data))>>19)
#define  DFE_HDMI_RX_PHY_RST_get_p2_ck_vcorstb(data)                             ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_RST_get_p1_ck_vcorstb(data)                             ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_RST_get_p0_ck_vcorstb(data)                             ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_RST_get_p3_ck_pllrstb(data)                             ((0x00008000&(data))>>15)
#define  DFE_HDMI_RX_PHY_RST_get_p2_ck_pllrstb(data)                             ((0x00004000&(data))>>14)
#define  DFE_HDMI_RX_PHY_RST_get_p1_ck_pllrstb(data)                             ((0x00002000&(data))>>13)
#define  DFE_HDMI_RX_PHY_RST_get_p0_ck_pllrstb(data)                             ((0x00001000&(data))>>12)
#define  DFE_HDMI_RX_PHY_RST_get_p3_r_demux_rstb(data)                           ((0x00000800&(data))>>11)
#define  DFE_HDMI_RX_PHY_RST_get_p3_g_demux_rstb(data)                           ((0x00000400&(data))>>10)
#define  DFE_HDMI_RX_PHY_RST_get_p3_b_demux_rstb(data)                           ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_RST_get_p2_r_demux_rstb(data)                           ((0x00000100&(data))>>8)
#define  DFE_HDMI_RX_PHY_RST_get_p2_g_demux_rstb(data)                           ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_RST_get_p2_b_demux_rstb(data)                           ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_RST_get_p1_r_demux_rstb(data)                           ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_RST_get_p1_g_demux_rstb(data)                           ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_RST_get_p1_b_demux_rstb(data)                           ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_RST_get_p0_r_demux_rstb(data)                           ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_RST_get_p0_g_demux_rstb(data)                           ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_RST_get_p0_b_demux_rstb(data)                           (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_REGD0                                                   0x1800DB8C
#define  DFE_HDMI_RX_PHY_REGD0_reg_addr                                          "0xB800DB8C"
#define  DFE_HDMI_RX_PHY_REGD0_reg                                               0xB800DB8C
#define  DFE_HDMI_RX_PHY_REGD0_inst_addr                                         "0x0057"
#define  set_DFE_HDMI_RX_PHY_REGD0_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD0_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD0_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD0_reg))
#define  DFE_HDMI_RX_PHY_REGD0_p0_r_dig_rst_n_shift                              (31)
#define  DFE_HDMI_RX_PHY_REGD0_p0_g_dig_rst_n_shift                              (30)
#define  DFE_HDMI_RX_PHY_REGD0_p0_b_dig_rst_n_shift                              (29)
#define  DFE_HDMI_RX_PHY_REGD0_p0_r_cdr_rst_n_shift                              (28)
#define  DFE_HDMI_RX_PHY_REGD0_p0_g_cdr_rst_n_shift                              (27)
#define  DFE_HDMI_RX_PHY_REGD0_p0_b_cdr_rst_n_shift                              (26)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_cdr_ckinv_r_shift                          (25)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_cdr_ckinv_g_shift                          (24)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_cdr_ckinv_b_shift                          (23)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_shift_inv_r_shift                          (22)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_shift_inv_g_shift                          (21)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_shift_inv_b_shift                          (20)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_rate_sel_shift                             (17)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_kd_shift                                   (16)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_kp_shift                                   (8)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_ki_shift                                   (5)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_bypass_sdm_int_shift                       (4)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_data_order_shift                           (3)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_infifo_cnt_shift                           (0)
#define  DFE_HDMI_RX_PHY_REGD0_p0_r_dig_rst_n_mask                               (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD0_p0_g_dig_rst_n_mask                               (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD0_p0_b_dig_rst_n_mask                               (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD0_p0_r_cdr_rst_n_mask                               (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD0_p0_g_cdr_rst_n_mask                               (0x08000000)
#define  DFE_HDMI_RX_PHY_REGD0_p0_b_cdr_rst_n_mask                               (0x04000000)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_cdr_ckinv_r_mask                           (0x02000000)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_cdr_ckinv_g_mask                           (0x01000000)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_cdr_ckinv_b_mask                           (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_shift_inv_r_mask                           (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_shift_inv_g_mask                           (0x00200000)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_shift_inv_b_mask                           (0x00100000)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_rate_sel_mask                              (0x000E0000)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_kd_mask                                    (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_kp_mask                                    (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_ki_mask                                    (0x000000E0)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_bypass_sdm_int_mask                        (0x00000010)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_data_order_mask                            (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_infifo_cnt_mask                            (0x00000007)
#define  DFE_HDMI_RX_PHY_REGD0_p0_r_dig_rst_n(data)                              (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD0_p0_g_dig_rst_n(data)                              (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD0_p0_b_dig_rst_n(data)                              (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD0_p0_r_cdr_rst_n(data)                              (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD0_p0_g_cdr_rst_n(data)                              (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD0_p0_b_cdr_rst_n(data)                              (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_cdr_ckinv_r(data)                          (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_cdr_ckinv_g(data)                          (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_cdr_ckinv_b(data)                          (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_shift_inv_r(data)                          (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_shift_inv_g(data)                          (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_shift_inv_b(data)                          (0x00100000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_rate_sel(data)                             (0x000E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_kd(data)                                   (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_kp(data)                                   (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_ki(data)                                   (0x000000E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_bypass_sdm_int(data)                       (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_data_order(data)                           (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD0_reg_p0_infifo_cnt(data)                           (0x00000007&(data))
#define  DFE_HDMI_RX_PHY_REGD0_get_p0_r_dig_rst_n(data)                          ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD0_get_p0_g_dig_rst_n(data)                          ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD0_get_p0_b_dig_rst_n(data)                          ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD0_get_p0_r_cdr_rst_n(data)                          ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD0_get_p0_g_cdr_rst_n(data)                          ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD0_get_p0_b_cdr_rst_n(data)                          ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_cdr_ckinv_r(data)                      ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_cdr_ckinv_g(data)                      ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_cdr_ckinv_b(data)                      ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_shift_inv_r(data)                      ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_shift_inv_g(data)                      ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_shift_inv_b(data)                      ((0x00100000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_rate_sel(data)                         ((0x000E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_kd(data)                               ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_kp(data)                               ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_ki(data)                               ((0x000000E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_bypass_sdm_int(data)                   ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_data_order(data)                       ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD0_get_reg_p0_infifo_cnt(data)                       (0x00000007&(data))

#define  DFE_HDMI_RX_PHY_REGD1                                                   0x1800DB90
#define  DFE_HDMI_RX_PHY_REGD1_reg_addr                                          "0xB800DB90"
#define  DFE_HDMI_RX_PHY_REGD1_reg                                               0xB800DB90
#define  DFE_HDMI_RX_PHY_REGD1_inst_addr                                         "0x0058"
#define  set_DFE_HDMI_RX_PHY_REGD1_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD1_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD1_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD1_reg))
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_int_init_shift                             (18)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_acc2_period_shift                          (8)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_squ_tri_shift                              (7)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_acc2_manual_shift                          (6)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_testout_sel_shift                          (4)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_ercnt_en_shift                             (3)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_edge_out_shift                             (2)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_pi_m_mode_shift                            (1)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_dyn_kp_en_shift                            (0)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_int_init_mask                              (0xFFFC0000)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_acc2_period_mask                           (0x0003FF00)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_squ_tri_mask                               (0x00000080)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_acc2_manual_mask                           (0x00000040)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_testout_sel_mask                           (0x00000030)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_ercnt_en_mask                              (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_edge_out_mask                              (0x00000004)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_pi_m_mode_mask                             (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_dyn_kp_en_mask                             (0x00000001)
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_int_init(data)                             (0xFFFC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_acc2_period(data)                          (0x0003FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_squ_tri(data)                              (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_acc2_manual(data)                          (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_testout_sel(data)                          (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_ercnt_en(data)                             (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_edge_out(data)                             (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_pi_m_mode(data)                            (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD1_reg_p0_dyn_kp_en(data)                            (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_REGD1_get_reg_p0_int_init(data)                         ((0xFFFC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD1_get_reg_p0_acc2_period(data)                      ((0x0003FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD1_get_reg_p0_squ_tri(data)                          ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD1_get_reg_p0_acc2_manual(data)                      ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD1_get_reg_p0_testout_sel(data)                      ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD1_get_reg_p0_ercnt_en(data)                         ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD1_get_reg_p0_edge_out(data)                         ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD1_get_reg_p0_pi_m_mode(data)                        ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_REGD1_get_reg_p0_dyn_kp_en(data)                        (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_REGD2                                                   0x1800DB94
#define  DFE_HDMI_RX_PHY_REGD2_reg_addr                                          "0xB800DB94"
#define  DFE_HDMI_RX_PHY_REGD2_reg                                               0xB800DB94
#define  DFE_HDMI_RX_PHY_REGD2_inst_addr                                         "0x0059"
#define  set_DFE_HDMI_RX_PHY_REGD2_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD2_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD2_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD2_reg))
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_en_m_value_shift                           (28)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_st_mode_shift                              (27)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_timer_lpf_shift                            (18)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_timer_eq_shift                             (13)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_timer_ber_shift                            (8)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_en_m_value_mask                            (0xF0000000)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_st_mode_mask                               (0x08000000)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_timer_lpf_mask                             (0x007C0000)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_timer_eq_mask                              (0x0003E000)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_timer_ber_mask                             (0x00001F00)
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_en_m_value(data)                           (0xF0000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_st_mode(data)                              (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_timer_lpf(data)                            (0x007C0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_timer_eq(data)                             (0x0003E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_REGD2_reg_p0_timer_ber(data)                            (0x00001F00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD2_get_reg_p0_en_m_value(data)                       ((0xF0000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD2_get_reg_p0_st_mode(data)                          ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD2_get_reg_p0_timer_lpf(data)                        ((0x007C0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD2_get_reg_p0_timer_eq(data)                         ((0x0003E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_REGD2_get_reg_p0_timer_ber(data)                        ((0x00001F00&(data))>>8)

#define  DFE_HDMI_RX_PHY_REGD3                                                   0x1800DB98
#define  DFE_HDMI_RX_PHY_REGD3_reg_addr                                          "0xB800DB98"
#define  DFE_HDMI_RX_PHY_REGD3_reg                                               0xB800DB98
#define  DFE_HDMI_RX_PHY_REGD3_inst_addr                                         "0x005A"
#define  set_DFE_HDMI_RX_PHY_REGD3_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD3_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD3_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD3_reg))
#define  DFE_HDMI_RX_PHY_REGD3_p0_st_ro_r_shift                                  (24)
#define  DFE_HDMI_RX_PHY_REGD3_p0_en_ro_r_shift                                  (20)
#define  DFE_HDMI_RX_PHY_REGD3_p0_st_ro_g_shift                                  (14)
#define  DFE_HDMI_RX_PHY_REGD3_p0_en_ro_g_shift                                  (10)
#define  DFE_HDMI_RX_PHY_REGD3_p0_st_ro_b_shift                                  (4)
#define  DFE_HDMI_RX_PHY_REGD3_p0_en_ro_b_shift                                  (0)
#define  DFE_HDMI_RX_PHY_REGD3_p0_st_ro_r_mask                                   (0x1F000000)
#define  DFE_HDMI_RX_PHY_REGD3_p0_en_ro_r_mask                                   (0x00F00000)
#define  DFE_HDMI_RX_PHY_REGD3_p0_st_ro_g_mask                                   (0x0007C000)
#define  DFE_HDMI_RX_PHY_REGD3_p0_en_ro_g_mask                                   (0x00003C00)
#define  DFE_HDMI_RX_PHY_REGD3_p0_st_ro_b_mask                                   (0x000001F0)
#define  DFE_HDMI_RX_PHY_REGD3_p0_en_ro_b_mask                                   (0x0000000F)
#define  DFE_HDMI_RX_PHY_REGD3_p0_st_ro_r(data)                                  (0x1F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD3_p0_en_ro_r(data)                                  (0x00F00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD3_p0_st_ro_g(data)                                  (0x0007C000&((data)<<14))
#define  DFE_HDMI_RX_PHY_REGD3_p0_en_ro_g(data)                                  (0x00003C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD3_p0_st_ro_b(data)                                  (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD3_p0_en_ro_b(data)                                  (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_REGD3_get_p0_st_ro_r(data)                              ((0x1F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD3_get_p0_en_ro_r(data)                              ((0x00F00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD3_get_p0_st_ro_g(data)                              ((0x0007C000&(data))>>14)
#define  DFE_HDMI_RX_PHY_REGD3_get_p0_en_ro_g(data)                              ((0x00003C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD3_get_p0_st_ro_b(data)                              ((0x000001F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD3_get_p0_en_ro_b(data)                              (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_REGD4                                                   0x1800DB9C
#define  DFE_HDMI_RX_PHY_REGD4_reg_addr                                          "0xB800DB9C"
#define  DFE_HDMI_RX_PHY_REGD4_reg                                               0xB800DB9C
#define  DFE_HDMI_RX_PHY_REGD4_inst_addr                                         "0x005B"
#define  set_DFE_HDMI_RX_PHY_REGD4_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD4_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD4_reg))
#define  DFE_HDMI_RX_PHY_REGD4_p0_er_count_r_shift                               (20)
#define  DFE_HDMI_RX_PHY_REGD4_p0_er_count_g_shift                               (10)
#define  DFE_HDMI_RX_PHY_REGD4_p0_er_count_b_shift                               (0)
#define  DFE_HDMI_RX_PHY_REGD4_p0_er_count_r_mask                                (0x3FF00000)
#define  DFE_HDMI_RX_PHY_REGD4_p0_er_count_g_mask                                (0x000FFC00)
#define  DFE_HDMI_RX_PHY_REGD4_p0_er_count_b_mask                                (0x000003FF)
#define  DFE_HDMI_RX_PHY_REGD4_p0_er_count_r(data)                               (0x3FF00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD4_p0_er_count_g(data)                               (0x000FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD4_p0_er_count_b(data)                               (0x000003FF&(data))
#define  DFE_HDMI_RX_PHY_REGD4_get_p0_er_count_r(data)                           ((0x3FF00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD4_get_p0_er_count_g(data)                           ((0x000FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD4_get_p0_er_count_b(data)                           (0x000003FF&(data))

#define  DFE_HDMI_RX_PHY_REGD5                                                   0x1800DBA0
#define  DFE_HDMI_RX_PHY_REGD5_reg_addr                                          "0xB800DBA0"
#define  DFE_HDMI_RX_PHY_REGD5_reg                                               0xB800DBA0
#define  DFE_HDMI_RX_PHY_REGD5_inst_addr                                         "0x005C"
#define  set_DFE_HDMI_RX_PHY_REGD5_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD5_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD5_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD5_reg))
#define  DFE_HDMI_RX_PHY_REGD5_p1_r_dig_rst_n_shift                              (31)
#define  DFE_HDMI_RX_PHY_REGD5_p1_g_dig_rst_n_shift                              (30)
#define  DFE_HDMI_RX_PHY_REGD5_p1_b_dig_rst_n_shift                              (29)
#define  DFE_HDMI_RX_PHY_REGD5_p1_r_cdr_rst_n_shift                              (28)
#define  DFE_HDMI_RX_PHY_REGD5_p1_g_cdr_rst_n_shift                              (27)
#define  DFE_HDMI_RX_PHY_REGD5_p1_b_cdr_rst_n_shift                              (26)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_cdr_ckinv_r_shift                          (25)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_cdr_ckinv_g_shift                          (24)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_cdr_ckinv_b_shift                          (23)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_shift_inv_r_shift                          (22)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_shift_inv_g_shift                          (21)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_shift_inv_b_shift                          (20)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_rate_sel_shift                             (17)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_kd_shift                                   (16)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_kp_shift                                   (8)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_ki_shift                                   (5)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_bypass_sdm_int_shift                       (4)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_data_order_shift                           (3)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_infifo_cnt_shift                           (0)
#define  DFE_HDMI_RX_PHY_REGD5_p1_r_dig_rst_n_mask                               (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD5_p1_g_dig_rst_n_mask                               (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD5_p1_b_dig_rst_n_mask                               (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD5_p1_r_cdr_rst_n_mask                               (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD5_p1_g_cdr_rst_n_mask                               (0x08000000)
#define  DFE_HDMI_RX_PHY_REGD5_p1_b_cdr_rst_n_mask                               (0x04000000)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_cdr_ckinv_r_mask                           (0x02000000)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_cdr_ckinv_g_mask                           (0x01000000)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_cdr_ckinv_b_mask                           (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_shift_inv_r_mask                           (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_shift_inv_g_mask                           (0x00200000)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_shift_inv_b_mask                           (0x00100000)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_rate_sel_mask                              (0x000E0000)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_kd_mask                                    (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_kp_mask                                    (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_ki_mask                                    (0x000000E0)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_bypass_sdm_int_mask                        (0x00000010)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_data_order_mask                            (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_infifo_cnt_mask                            (0x00000007)
#define  DFE_HDMI_RX_PHY_REGD5_p1_r_dig_rst_n(data)                              (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD5_p1_g_dig_rst_n(data)                              (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD5_p1_b_dig_rst_n(data)                              (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD5_p1_r_cdr_rst_n(data)                              (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD5_p1_g_cdr_rst_n(data)                              (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD5_p1_b_cdr_rst_n(data)                              (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_cdr_ckinv_r(data)                          (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_cdr_ckinv_g(data)                          (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_cdr_ckinv_b(data)                          (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_shift_inv_r(data)                          (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_shift_inv_g(data)                          (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_shift_inv_b(data)                          (0x00100000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_rate_sel(data)                             (0x000E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_kd(data)                                   (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_kp(data)                                   (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_ki(data)                                   (0x000000E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_bypass_sdm_int(data)                       (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_data_order(data)                           (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD5_reg_p1_infifo_cnt(data)                           (0x00000007&(data))
#define  DFE_HDMI_RX_PHY_REGD5_get_p1_r_dig_rst_n(data)                          ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD5_get_p1_g_dig_rst_n(data)                          ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD5_get_p1_b_dig_rst_n(data)                          ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD5_get_p1_r_cdr_rst_n(data)                          ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD5_get_p1_g_cdr_rst_n(data)                          ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD5_get_p1_b_cdr_rst_n(data)                          ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_cdr_ckinv_r(data)                      ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_cdr_ckinv_g(data)                      ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_cdr_ckinv_b(data)                      ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_shift_inv_r(data)                      ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_shift_inv_g(data)                      ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_shift_inv_b(data)                      ((0x00100000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_rate_sel(data)                         ((0x000E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_kd(data)                               ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_kp(data)                               ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_ki(data)                               ((0x000000E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_bypass_sdm_int(data)                   ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_data_order(data)                       ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD5_get_reg_p1_infifo_cnt(data)                       (0x00000007&(data))

#define  DFE_HDMI_RX_PHY_REGD6                                                   0x1800DBA4
#define  DFE_HDMI_RX_PHY_REGD6_reg_addr                                          "0xB800DBA4"
#define  DFE_HDMI_RX_PHY_REGD6_reg                                               0xB800DBA4
#define  DFE_HDMI_RX_PHY_REGD6_inst_addr                                         "0x005D"
#define  set_DFE_HDMI_RX_PHY_REGD6_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD6_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD6_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD6_reg))
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_int_init_shift                             (18)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_acc2_period_shift                          (8)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_squ_tri_shift                              (7)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_acc2_manual_shift                          (6)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_testout_sel_shift                          (4)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_ercnt_en_shift                             (3)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_edge_out_shift                             (2)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_pi_m_mode_shift                            (1)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_dyn_kp_en_shift                            (0)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_int_init_mask                              (0xFFFC0000)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_acc2_period_mask                           (0x0003FF00)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_squ_tri_mask                               (0x00000080)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_acc2_manual_mask                           (0x00000040)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_testout_sel_mask                           (0x00000030)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_ercnt_en_mask                              (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_edge_out_mask                              (0x00000004)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_pi_m_mode_mask                             (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_dyn_kp_en_mask                             (0x00000001)
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_int_init(data)                             (0xFFFC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_acc2_period(data)                          (0x0003FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_squ_tri(data)                              (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_acc2_manual(data)                          (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_testout_sel(data)                          (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_ercnt_en(data)                             (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_edge_out(data)                             (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_pi_m_mode(data)                            (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD6_reg_p1_dyn_kp_en(data)                            (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_REGD6_get_reg_p1_int_init(data)                         ((0xFFFC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD6_get_reg_p1_acc2_period(data)                      ((0x0003FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD6_get_reg_p1_squ_tri(data)                          ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD6_get_reg_p1_acc2_manual(data)                      ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD6_get_reg_p1_testout_sel(data)                      ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD6_get_reg_p1_ercnt_en(data)                         ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD6_get_reg_p1_edge_out(data)                         ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD6_get_reg_p1_pi_m_mode(data)                        ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_REGD6_get_reg_p1_dyn_kp_en(data)                        (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_REGD7                                                   0x1800DBA8
#define  DFE_HDMI_RX_PHY_REGD7_reg_addr                                          "0xB800DBA8"
#define  DFE_HDMI_RX_PHY_REGD7_reg                                               0xB800DBA8
#define  DFE_HDMI_RX_PHY_REGD7_inst_addr                                         "0x005E"
#define  set_DFE_HDMI_RX_PHY_REGD7_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD7_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD7_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD7_reg))
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_en_m_value_shift                           (28)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_st_mode_shift                              (27)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_timer_lpf_shift                            (18)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_timer_eq_shift                             (13)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_timer_ber_shift                            (8)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_en_m_value_mask                            (0xF0000000)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_st_mode_mask                               (0x08000000)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_timer_lpf_mask                             (0x007C0000)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_timer_eq_mask                              (0x0003E000)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_timer_ber_mask                             (0x00001F00)
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_en_m_value(data)                           (0xF0000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_st_mode(data)                              (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_timer_lpf(data)                            (0x007C0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_timer_eq(data)                             (0x0003E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_REGD7_reg_p1_timer_ber(data)                            (0x00001F00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD7_get_reg_p1_en_m_value(data)                       ((0xF0000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD7_get_reg_p1_st_mode(data)                          ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD7_get_reg_p1_timer_lpf(data)                        ((0x007C0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD7_get_reg_p1_timer_eq(data)                         ((0x0003E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_REGD7_get_reg_p1_timer_ber(data)                        ((0x00001F00&(data))>>8)

#define  DFE_HDMI_RX_PHY_REGD8                                                   0x1800DBAC
#define  DFE_HDMI_RX_PHY_REGD8_reg_addr                                          "0xB800DBAC"
#define  DFE_HDMI_RX_PHY_REGD8_reg                                               0xB800DBAC
#define  DFE_HDMI_RX_PHY_REGD8_inst_addr                                         "0x005F"
#define  set_DFE_HDMI_RX_PHY_REGD8_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD8_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD8_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD8_reg))
#define  DFE_HDMI_RX_PHY_REGD8_p1_st_ro_r_shift                                  (24)
#define  DFE_HDMI_RX_PHY_REGD8_p1_en_ro_r_shift                                  (20)
#define  DFE_HDMI_RX_PHY_REGD8_p1_st_ro_g_shift                                  (14)
#define  DFE_HDMI_RX_PHY_REGD8_p1_en_ro_g_shift                                  (10)
#define  DFE_HDMI_RX_PHY_REGD8_p1_st_ro_b_shift                                  (4)
#define  DFE_HDMI_RX_PHY_REGD8_p1_en_ro_b_shift                                  (0)
#define  DFE_HDMI_RX_PHY_REGD8_p1_st_ro_r_mask                                   (0x1F000000)
#define  DFE_HDMI_RX_PHY_REGD8_p1_en_ro_r_mask                                   (0x00F00000)
#define  DFE_HDMI_RX_PHY_REGD8_p1_st_ro_g_mask                                   (0x0007C000)
#define  DFE_HDMI_RX_PHY_REGD8_p1_en_ro_g_mask                                   (0x00003C00)
#define  DFE_HDMI_RX_PHY_REGD8_p1_st_ro_b_mask                                   (0x000001F0)
#define  DFE_HDMI_RX_PHY_REGD8_p1_en_ro_b_mask                                   (0x0000000F)
#define  DFE_HDMI_RX_PHY_REGD8_p1_st_ro_r(data)                                  (0x1F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD8_p1_en_ro_r(data)                                  (0x00F00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD8_p1_st_ro_g(data)                                  (0x0007C000&((data)<<14))
#define  DFE_HDMI_RX_PHY_REGD8_p1_en_ro_g(data)                                  (0x00003C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD8_p1_st_ro_b(data)                                  (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD8_p1_en_ro_b(data)                                  (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_REGD8_get_p1_st_ro_r(data)                              ((0x1F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD8_get_p1_en_ro_r(data)                              ((0x00F00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD8_get_p1_st_ro_g(data)                              ((0x0007C000&(data))>>14)
#define  DFE_HDMI_RX_PHY_REGD8_get_p1_en_ro_g(data)                              ((0x00003C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD8_get_p1_st_ro_b(data)                              ((0x000001F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD8_get_p1_en_ro_b(data)                              (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_REGD9                                                   0x1800DBB0
#define  DFE_HDMI_RX_PHY_REGD9_reg_addr                                          "0xB800DBB0"
#define  DFE_HDMI_RX_PHY_REGD9_reg                                               0xB800DBB0
#define  DFE_HDMI_RX_PHY_REGD9_inst_addr                                         "0x0060"
#define  set_DFE_HDMI_RX_PHY_REGD9_reg(data)                                     (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD9_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD9_reg                                           (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD9_reg))
#define  DFE_HDMI_RX_PHY_REGD9_p1_er_count_r_shift                               (20)
#define  DFE_HDMI_RX_PHY_REGD9_p1_er_count_g_shift                               (10)
#define  DFE_HDMI_RX_PHY_REGD9_p1_er_count_b_shift                               (0)
#define  DFE_HDMI_RX_PHY_REGD9_p1_er_count_r_mask                                (0x3FF00000)
#define  DFE_HDMI_RX_PHY_REGD9_p1_er_count_g_mask                                (0x000FFC00)
#define  DFE_HDMI_RX_PHY_REGD9_p1_er_count_b_mask                                (0x000003FF)
#define  DFE_HDMI_RX_PHY_REGD9_p1_er_count_r(data)                               (0x3FF00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD9_p1_er_count_g(data)                               (0x000FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD9_p1_er_count_b(data)                               (0x000003FF&(data))
#define  DFE_HDMI_RX_PHY_REGD9_get_p1_er_count_r(data)                           ((0x3FF00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD9_get_p1_er_count_g(data)                           ((0x000FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD9_get_p1_er_count_b(data)                           (0x000003FF&(data))

#define  DFE_HDMI_RX_PHY_REGD10                                                  0x1800DBB4
#define  DFE_HDMI_RX_PHY_REGD10_reg_addr                                         "0xB800DBB4"
#define  DFE_HDMI_RX_PHY_REGD10_reg                                              0xB800DBB4
#define  DFE_HDMI_RX_PHY_REGD10_inst_addr                                        "0x0061"
#define  set_DFE_HDMI_RX_PHY_REGD10_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD10_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD10_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD10_reg))
#define  DFE_HDMI_RX_PHY_REGD10_p2_r_dig_rst_n_shift                             (31)
#define  DFE_HDMI_RX_PHY_REGD10_p2_g_dig_rst_n_shift                             (30)
#define  DFE_HDMI_RX_PHY_REGD10_p2_b_dig_rst_n_shift                             (29)
#define  DFE_HDMI_RX_PHY_REGD10_p2_r_cdr_rst_n_shift                             (28)
#define  DFE_HDMI_RX_PHY_REGD10_p2_g_cdr_rst_n_shift                             (27)
#define  DFE_HDMI_RX_PHY_REGD10_p2_b_cdr_rst_n_shift                             (26)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_cdr_ckinv_r_shift                         (25)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_cdr_ckinv_g_shift                         (24)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_cdr_ckinv_b_shift                         (23)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_shift_inv_r_shift                         (22)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_shift_inv_g_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_shift_inv_b_shift                         (20)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_rate_sel_shift                            (17)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_kd_shift                                  (16)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_kp_shift                                  (8)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_ki_shift                                  (5)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_bypass_sdm_int_shift                      (4)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_data_order_shift                          (3)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_infifo_cnt_shift                          (0)
#define  DFE_HDMI_RX_PHY_REGD10_p2_r_dig_rst_n_mask                              (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD10_p2_g_dig_rst_n_mask                              (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD10_p2_b_dig_rst_n_mask                              (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD10_p2_r_cdr_rst_n_mask                              (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD10_p2_g_cdr_rst_n_mask                              (0x08000000)
#define  DFE_HDMI_RX_PHY_REGD10_p2_b_cdr_rst_n_mask                              (0x04000000)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_cdr_ckinv_r_mask                          (0x02000000)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_cdr_ckinv_g_mask                          (0x01000000)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_cdr_ckinv_b_mask                          (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_shift_inv_r_mask                          (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_shift_inv_g_mask                          (0x00200000)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_shift_inv_b_mask                          (0x00100000)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_rate_sel_mask                             (0x000E0000)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_kd_mask                                   (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_kp_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_ki_mask                                   (0x000000E0)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_bypass_sdm_int_mask                       (0x00000010)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_data_order_mask                           (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_infifo_cnt_mask                           (0x00000007)
#define  DFE_HDMI_RX_PHY_REGD10_p2_r_dig_rst_n(data)                             (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD10_p2_g_dig_rst_n(data)                             (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD10_p2_b_dig_rst_n(data)                             (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD10_p2_r_cdr_rst_n(data)                             (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD10_p2_g_cdr_rst_n(data)                             (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD10_p2_b_cdr_rst_n(data)                             (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_cdr_ckinv_r(data)                         (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_cdr_ckinv_g(data)                         (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_cdr_ckinv_b(data)                         (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_shift_inv_r(data)                         (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_shift_inv_g(data)                         (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_shift_inv_b(data)                         (0x00100000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_rate_sel(data)                            (0x000E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_kd(data)                                  (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_kp(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_ki(data)                                  (0x000000E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_bypass_sdm_int(data)                      (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_data_order(data)                          (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD10_reg_p2_infifo_cnt(data)                          (0x00000007&(data))
#define  DFE_HDMI_RX_PHY_REGD10_get_p2_r_dig_rst_n(data)                         ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD10_get_p2_g_dig_rst_n(data)                         ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD10_get_p2_b_dig_rst_n(data)                         ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD10_get_p2_r_cdr_rst_n(data)                         ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD10_get_p2_g_cdr_rst_n(data)                         ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD10_get_p2_b_cdr_rst_n(data)                         ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_cdr_ckinv_r(data)                     ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_cdr_ckinv_g(data)                     ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_cdr_ckinv_b(data)                     ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_shift_inv_r(data)                     ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_shift_inv_g(data)                     ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_shift_inv_b(data)                     ((0x00100000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_rate_sel(data)                        ((0x000E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_kd(data)                              ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_kp(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_ki(data)                              ((0x000000E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_bypass_sdm_int(data)                  ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_data_order(data)                      ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD10_get_reg_p2_infifo_cnt(data)                      (0x00000007&(data))

#define  DFE_HDMI_RX_PHY_REGD11                                                  0x1800DBB8
#define  DFE_HDMI_RX_PHY_REGD11_reg_addr                                         "0xB800DBB8"
#define  DFE_HDMI_RX_PHY_REGD11_reg                                              0xB800DBB8
#define  DFE_HDMI_RX_PHY_REGD11_inst_addr                                        "0x0062"
#define  set_DFE_HDMI_RX_PHY_REGD11_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD11_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD11_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD11_reg))
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_int_init_shift                            (18)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_acc2_period_shift                         (8)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_squ_tri_shift                             (7)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_acc2_manual_shift                         (6)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_testout_sel_shift                         (4)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_ercnt_en_shift                            (3)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_edge_out_shift                            (2)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_pi_m_mode_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_dyn_kp_en_shift                           (0)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_int_init_mask                             (0xFFFC0000)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_acc2_period_mask                          (0x0003FF00)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_squ_tri_mask                              (0x00000080)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_acc2_manual_mask                          (0x00000040)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_testout_sel_mask                          (0x00000030)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_ercnt_en_mask                             (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_edge_out_mask                             (0x00000004)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_pi_m_mode_mask                            (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_dyn_kp_en_mask                            (0x00000001)
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_int_init(data)                            (0xFFFC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_acc2_period(data)                         (0x0003FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_squ_tri(data)                             (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_acc2_manual(data)                         (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_testout_sel(data)                         (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_ercnt_en(data)                            (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_edge_out(data)                            (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_pi_m_mode(data)                           (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD11_reg_p2_dyn_kp_en(data)                           (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_REGD11_get_reg_p2_int_init(data)                        ((0xFFFC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD11_get_reg_p2_acc2_period(data)                     ((0x0003FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD11_get_reg_p2_squ_tri(data)                         ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD11_get_reg_p2_acc2_manual(data)                     ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD11_get_reg_p2_testout_sel(data)                     ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD11_get_reg_p2_ercnt_en(data)                        ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD11_get_reg_p2_edge_out(data)                        ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD11_get_reg_p2_pi_m_mode(data)                       ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_REGD11_get_reg_p2_dyn_kp_en(data)                       (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_REGD12                                                  0x1800DBBC
#define  DFE_HDMI_RX_PHY_REGD12_reg_addr                                         "0xB800DBBC"
#define  DFE_HDMI_RX_PHY_REGD12_reg                                              0xB800DBBC
#define  DFE_HDMI_RX_PHY_REGD12_inst_addr                                        "0x0063"
#define  set_DFE_HDMI_RX_PHY_REGD12_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD12_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD12_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD12_reg))
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_en_m_value_shift                          (28)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_st_mode_shift                             (27)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_timer_lpf_shift                           (18)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_timer_eq_shift                            (13)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_timer_ber_shift                           (8)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_en_m_value_mask                           (0xF0000000)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_st_mode_mask                              (0x08000000)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_timer_lpf_mask                            (0x007C0000)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_timer_eq_mask                             (0x0003E000)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_timer_ber_mask                            (0x00001F00)
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_en_m_value(data)                          (0xF0000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_st_mode(data)                             (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_timer_lpf(data)                           (0x007C0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_timer_eq(data)                            (0x0003E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_REGD12_reg_p2_timer_ber(data)                           (0x00001F00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD12_get_reg_p2_en_m_value(data)                      ((0xF0000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD12_get_reg_p2_st_mode(data)                         ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD12_get_reg_p2_timer_lpf(data)                       ((0x007C0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD12_get_reg_p2_timer_eq(data)                        ((0x0003E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_REGD12_get_reg_p2_timer_ber(data)                       ((0x00001F00&(data))>>8)

#define  DFE_HDMI_RX_PHY_REGD13                                                  0x1800DBC0
#define  DFE_HDMI_RX_PHY_REGD13_reg_addr                                         "0xB800DBC0"
#define  DFE_HDMI_RX_PHY_REGD13_reg                                              0xB800DBC0
#define  DFE_HDMI_RX_PHY_REGD13_inst_addr                                        "0x0064"
#define  set_DFE_HDMI_RX_PHY_REGD13_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD13_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD13_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD13_reg))
#define  DFE_HDMI_RX_PHY_REGD13_p2_st_ro_r_shift                                 (24)
#define  DFE_HDMI_RX_PHY_REGD13_p2_en_ro_r_shift                                 (20)
#define  DFE_HDMI_RX_PHY_REGD13_p2_st_ro_g_shift                                 (14)
#define  DFE_HDMI_RX_PHY_REGD13_p2_en_ro_g_shift                                 (10)
#define  DFE_HDMI_RX_PHY_REGD13_p2_st_ro_b_shift                                 (4)
#define  DFE_HDMI_RX_PHY_REGD13_p2_en_ro_b_shift                                 (0)
#define  DFE_HDMI_RX_PHY_REGD13_p2_st_ro_r_mask                                  (0x1F000000)
#define  DFE_HDMI_RX_PHY_REGD13_p2_en_ro_r_mask                                  (0x00F00000)
#define  DFE_HDMI_RX_PHY_REGD13_p2_st_ro_g_mask                                  (0x0007C000)
#define  DFE_HDMI_RX_PHY_REGD13_p2_en_ro_g_mask                                  (0x00003C00)
#define  DFE_HDMI_RX_PHY_REGD13_p2_st_ro_b_mask                                  (0x000001F0)
#define  DFE_HDMI_RX_PHY_REGD13_p2_en_ro_b_mask                                  (0x0000000F)
#define  DFE_HDMI_RX_PHY_REGD13_p2_st_ro_r(data)                                 (0x1F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD13_p2_en_ro_r(data)                                 (0x00F00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD13_p2_st_ro_g(data)                                 (0x0007C000&((data)<<14))
#define  DFE_HDMI_RX_PHY_REGD13_p2_en_ro_g(data)                                 (0x00003C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD13_p2_st_ro_b(data)                                 (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD13_p2_en_ro_b(data)                                 (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_REGD13_get_p2_st_ro_r(data)                             ((0x1F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD13_get_p2_en_ro_r(data)                             ((0x00F00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD13_get_p2_st_ro_g(data)                             ((0x0007C000&(data))>>14)
#define  DFE_HDMI_RX_PHY_REGD13_get_p2_en_ro_g(data)                             ((0x00003C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD13_get_p2_st_ro_b(data)                             ((0x000001F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD13_get_p2_en_ro_b(data)                             (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_REGD14                                                  0x1800DBC4
#define  DFE_HDMI_RX_PHY_REGD14_reg_addr                                         "0xB800DBC4"
#define  DFE_HDMI_RX_PHY_REGD14_reg                                              0xB800DBC4
#define  DFE_HDMI_RX_PHY_REGD14_inst_addr                                        "0x0065"
#define  set_DFE_HDMI_RX_PHY_REGD14_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD14_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD14_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD14_reg))
#define  DFE_HDMI_RX_PHY_REGD14_p2_er_count_r_shift                              (20)
#define  DFE_HDMI_RX_PHY_REGD14_p2_er_count_g_shift                              (10)
#define  DFE_HDMI_RX_PHY_REGD14_p2_er_count_b_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD14_p2_er_count_r_mask                               (0x3FF00000)
#define  DFE_HDMI_RX_PHY_REGD14_p2_er_count_g_mask                               (0x000FFC00)
#define  DFE_HDMI_RX_PHY_REGD14_p2_er_count_b_mask                               (0x000003FF)
#define  DFE_HDMI_RX_PHY_REGD14_p2_er_count_r(data)                              (0x3FF00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD14_p2_er_count_g(data)                              (0x000FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD14_p2_er_count_b(data)                              (0x000003FF&(data))
#define  DFE_HDMI_RX_PHY_REGD14_get_p2_er_count_r(data)                          ((0x3FF00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD14_get_p2_er_count_g(data)                          ((0x000FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD14_get_p2_er_count_b(data)                          (0x000003FF&(data))

#define  DFE_HDMI_RX_PHY_REGD15                                                  0x1800DBC8
#define  DFE_HDMI_RX_PHY_REGD15_reg_addr                                         "0xB800DBC8"
#define  DFE_HDMI_RX_PHY_REGD15_reg                                              0xB800DBC8
#define  DFE_HDMI_RX_PHY_REGD15_inst_addr                                        "0x0066"
#define  set_DFE_HDMI_RX_PHY_REGD15_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD15_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD15_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD15_reg))
#define  DFE_HDMI_RX_PHY_REGD15_p3_r_dig_rst_n_shift                             (31)
#define  DFE_HDMI_RX_PHY_REGD15_p3_g_dig_rst_n_shift                             (30)
#define  DFE_HDMI_RX_PHY_REGD15_p3_b_dig_rst_n_shift                             (29)
#define  DFE_HDMI_RX_PHY_REGD15_p3_r_cdr_rst_n_shift                             (28)
#define  DFE_HDMI_RX_PHY_REGD15_p3_g_cdr_rst_n_shift                             (27)
#define  DFE_HDMI_RX_PHY_REGD15_p3_b_cdr_rst_n_shift                             (26)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_cdr_ckinv_r_shift                         (25)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_cdr_ckinv_g_shift                         (24)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_cdr_ckinv_b_shift                         (23)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_shift_inv_r_shift                         (22)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_shift_inv_g_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_shift_inv_b_shift                         (20)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_rate_sel_shift                            (17)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_kd_shift                                  (16)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_kp_shift                                  (8)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_ki_shift                                  (5)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_bypass_sdm_int_shift                      (4)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_data_order_shift                          (3)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_infifo_cnt_shift                          (0)
#define  DFE_HDMI_RX_PHY_REGD15_p3_r_dig_rst_n_mask                              (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD15_p3_g_dig_rst_n_mask                              (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD15_p3_b_dig_rst_n_mask                              (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD15_p3_r_cdr_rst_n_mask                              (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD15_p3_g_cdr_rst_n_mask                              (0x08000000)
#define  DFE_HDMI_RX_PHY_REGD15_p3_b_cdr_rst_n_mask                              (0x04000000)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_cdr_ckinv_r_mask                          (0x02000000)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_cdr_ckinv_g_mask                          (0x01000000)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_cdr_ckinv_b_mask                          (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_shift_inv_r_mask                          (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_shift_inv_g_mask                          (0x00200000)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_shift_inv_b_mask                          (0x00100000)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_rate_sel_mask                             (0x000E0000)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_kd_mask                                   (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_kp_mask                                   (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_ki_mask                                   (0x000000E0)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_bypass_sdm_int_mask                       (0x00000010)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_data_order_mask                           (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_infifo_cnt_mask                           (0x00000007)
#define  DFE_HDMI_RX_PHY_REGD15_p3_r_dig_rst_n(data)                             (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD15_p3_g_dig_rst_n(data)                             (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD15_p3_b_dig_rst_n(data)                             (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD15_p3_r_cdr_rst_n(data)                             (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD15_p3_g_cdr_rst_n(data)                             (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD15_p3_b_cdr_rst_n(data)                             (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_cdr_ckinv_r(data)                         (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_cdr_ckinv_g(data)                         (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_cdr_ckinv_b(data)                         (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_shift_inv_r(data)                         (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_shift_inv_g(data)                         (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_shift_inv_b(data)                         (0x00100000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_rate_sel(data)                            (0x000E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_kd(data)                                  (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_kp(data)                                  (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_ki(data)                                  (0x000000E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_bypass_sdm_int(data)                      (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_data_order(data)                          (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD15_reg_p3_infifo_cnt(data)                          (0x00000007&(data))
#define  DFE_HDMI_RX_PHY_REGD15_get_p3_r_dig_rst_n(data)                         ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD15_get_p3_g_dig_rst_n(data)                         ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD15_get_p3_b_dig_rst_n(data)                         ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD15_get_p3_r_cdr_rst_n(data)                         ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD15_get_p3_g_cdr_rst_n(data)                         ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD15_get_p3_b_cdr_rst_n(data)                         ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_cdr_ckinv_r(data)                     ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_cdr_ckinv_g(data)                     ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_cdr_ckinv_b(data)                     ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_shift_inv_r(data)                     ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_shift_inv_g(data)                     ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_shift_inv_b(data)                     ((0x00100000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_rate_sel(data)                        ((0x000E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_kd(data)                              ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_kp(data)                              ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_ki(data)                              ((0x000000E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_bypass_sdm_int(data)                  ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_data_order(data)                      ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD15_get_reg_p3_infifo_cnt(data)                      (0x00000007&(data))

#define  DFE_HDMI_RX_PHY_REGD16                                                  0x1800DBCC
#define  DFE_HDMI_RX_PHY_REGD16_reg_addr                                         "0xB800DBCC"
#define  DFE_HDMI_RX_PHY_REGD16_reg                                              0xB800DBCC
#define  DFE_HDMI_RX_PHY_REGD16_inst_addr                                        "0x0067"
#define  set_DFE_HDMI_RX_PHY_REGD16_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD16_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD16_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD16_reg))
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_int_init_shift                            (18)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_acc2_period_shift                         (8)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_squ_tri_shift                             (7)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_acc2_manual_shift                         (6)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_testout_sel_shift                         (4)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_ercnt_en_shift                            (3)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_edge_out_shift                            (2)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_pi_m_mode_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_dyn_kp_en_shift                           (0)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_int_init_mask                             (0xFFFC0000)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_acc2_period_mask                          (0x0003FF00)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_squ_tri_mask                              (0x00000080)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_acc2_manual_mask                          (0x00000040)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_testout_sel_mask                          (0x00000030)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_ercnt_en_mask                             (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_edge_out_mask                             (0x00000004)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_pi_m_mode_mask                            (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_dyn_kp_en_mask                            (0x00000001)
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_int_init(data)                            (0xFFFC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_acc2_period(data)                         (0x0003FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_squ_tri(data)                             (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_acc2_manual(data)                         (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_testout_sel(data)                         (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_ercnt_en(data)                            (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_edge_out(data)                            (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_pi_m_mode(data)                           (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD16_reg_p3_dyn_kp_en(data)                           (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_REGD16_get_reg_p3_int_init(data)                        ((0xFFFC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD16_get_reg_p3_acc2_period(data)                     ((0x0003FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD16_get_reg_p3_squ_tri(data)                         ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD16_get_reg_p3_acc2_manual(data)                     ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD16_get_reg_p3_testout_sel(data)                     ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD16_get_reg_p3_ercnt_en(data)                        ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD16_get_reg_p3_edge_out(data)                        ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD16_get_reg_p3_pi_m_mode(data)                       ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_REGD16_get_reg_p3_dyn_kp_en(data)                       (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_REGD17                                                  0x1800DBD0
#define  DFE_HDMI_RX_PHY_REGD17_reg_addr                                         "0xB800DBD0"
#define  DFE_HDMI_RX_PHY_REGD17_reg                                              0xB800DBD0
#define  DFE_HDMI_RX_PHY_REGD17_inst_addr                                        "0x0068"
#define  set_DFE_HDMI_RX_PHY_REGD17_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD17_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD17_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD17_reg))
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_en_m_value_shift                          (28)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_st_mode_shift                             (27)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_timer_lpf_shift                           (18)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_timer_eq_shift                            (13)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_timer_ber_shift                           (8)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_en_m_value_mask                           (0xF0000000)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_st_mode_mask                              (0x08000000)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_timer_lpf_mask                            (0x007C0000)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_timer_eq_mask                             (0x0003E000)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_timer_ber_mask                            (0x00001F00)
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_en_m_value(data)                          (0xF0000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_st_mode(data)                             (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_timer_lpf(data)                           (0x007C0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_timer_eq(data)                            (0x0003E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_REGD17_reg_p3_timer_ber(data)                           (0x00001F00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD17_get_reg_p3_en_m_value(data)                      ((0xF0000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD17_get_reg_p3_st_mode(data)                         ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD17_get_reg_p3_timer_lpf(data)                       ((0x007C0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD17_get_reg_p3_timer_eq(data)                        ((0x0003E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_REGD17_get_reg_p3_timer_ber(data)                       ((0x00001F00&(data))>>8)

#define  DFE_HDMI_RX_PHY_REGD18                                                  0x1800DBD4
#define  DFE_HDMI_RX_PHY_REGD18_reg_addr                                         "0xB800DBD4"
#define  DFE_HDMI_RX_PHY_REGD18_reg                                              0xB800DBD4
#define  DFE_HDMI_RX_PHY_REGD18_inst_addr                                        "0x0069"
#define  set_DFE_HDMI_RX_PHY_REGD18_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD18_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD18_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD18_reg))
#define  DFE_HDMI_RX_PHY_REGD18_p3_st_ro_r_shift                                 (24)
#define  DFE_HDMI_RX_PHY_REGD18_p3_en_ro_r_shift                                 (20)
#define  DFE_HDMI_RX_PHY_REGD18_p3_st_ro_g_shift                                 (14)
#define  DFE_HDMI_RX_PHY_REGD18_p3_en_ro_g_shift                                 (10)
#define  DFE_HDMI_RX_PHY_REGD18_p3_st_ro_b_shift                                 (4)
#define  DFE_HDMI_RX_PHY_REGD18_p3_en_ro_b_shift                                 (0)
#define  DFE_HDMI_RX_PHY_REGD18_p3_st_ro_r_mask                                  (0x1F000000)
#define  DFE_HDMI_RX_PHY_REGD18_p3_en_ro_r_mask                                  (0x00F00000)
#define  DFE_HDMI_RX_PHY_REGD18_p3_st_ro_g_mask                                  (0x0007C000)
#define  DFE_HDMI_RX_PHY_REGD18_p3_en_ro_g_mask                                  (0x00003C00)
#define  DFE_HDMI_RX_PHY_REGD18_p3_st_ro_b_mask                                  (0x000001F0)
#define  DFE_HDMI_RX_PHY_REGD18_p3_en_ro_b_mask                                  (0x0000000F)
#define  DFE_HDMI_RX_PHY_REGD18_p3_st_ro_r(data)                                 (0x1F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD18_p3_en_ro_r(data)                                 (0x00F00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD18_p3_st_ro_g(data)                                 (0x0007C000&((data)<<14))
#define  DFE_HDMI_RX_PHY_REGD18_p3_en_ro_g(data)                                 (0x00003C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD18_p3_st_ro_b(data)                                 (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD18_p3_en_ro_b(data)                                 (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_REGD18_get_p3_st_ro_r(data)                             ((0x1F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD18_get_p3_en_ro_r(data)                             ((0x00F00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD18_get_p3_st_ro_g(data)                             ((0x0007C000&(data))>>14)
#define  DFE_HDMI_RX_PHY_REGD18_get_p3_en_ro_g(data)                             ((0x00003C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD18_get_p3_st_ro_b(data)                             ((0x000001F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD18_get_p3_en_ro_b(data)                             (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_REGD19                                                  0x1800DBD8
#define  DFE_HDMI_RX_PHY_REGD19_reg_addr                                         "0xB800DBD8"
#define  DFE_HDMI_RX_PHY_REGD19_reg                                              0xB800DBD8
#define  DFE_HDMI_RX_PHY_REGD19_inst_addr                                        "0x006A"
#define  set_DFE_HDMI_RX_PHY_REGD19_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD19_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD19_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD19_reg))
#define  DFE_HDMI_RX_PHY_REGD19_p3_er_count_r_shift                              (20)
#define  DFE_HDMI_RX_PHY_REGD19_p3_er_count_g_shift                              (10)
#define  DFE_HDMI_RX_PHY_REGD19_p3_er_count_b_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD19_p3_er_count_r_mask                               (0x3FF00000)
#define  DFE_HDMI_RX_PHY_REGD19_p3_er_count_g_mask                               (0x000FFC00)
#define  DFE_HDMI_RX_PHY_REGD19_p3_er_count_b_mask                               (0x000003FF)
#define  DFE_HDMI_RX_PHY_REGD19_p3_er_count_r(data)                              (0x3FF00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD19_p3_er_count_g(data)                              (0x000FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD19_p3_er_count_b(data)                              (0x000003FF&(data))
#define  DFE_HDMI_RX_PHY_REGD19_get_p3_er_count_r(data)                          ((0x3FF00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD19_get_p3_er_count_g(data)                          ((0x000FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD19_get_p3_er_count_b(data)                          (0x000003FF&(data))

#define  DFE_HDMI_RX_PHY_REGD20                                                  0x1800DBDC
#define  DFE_HDMI_RX_PHY_REGD20_reg_addr                                         "0xB800DBDC"
#define  DFE_HDMI_RX_PHY_REGD20_reg                                              0xB800DBDC
#define  DFE_HDMI_RX_PHY_REGD20_inst_addr                                        "0x006B"
#define  set_DFE_HDMI_RX_PHY_REGD20_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD20_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD20_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD20_reg))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_clk_rdy_shift                      (31)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_eqen_rdy_shift                     (30)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_data_rdy_shift                     (29)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_pi_shift                           (28)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_data_rdy_time_shift                       (24)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_clkout_manual_shift                    (23)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_eqen_manual_shift                      (22)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_data_manual_shift                      (21)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_eqen_rdy_time_shift                       (17)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_order_shift                               (16)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_base_time_shift                    (13)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_en_shift                           (12)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_rst_wid_shift                      (10)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_time_rdy_shift                     (8)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_acdr_l0_en_shift                          (7)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_eqen_rdy_l0_shift                  (6)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_data_rdy_l0_shift                  (5)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_eqen_manual_l0_shift                   (4)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_data_manual_l0_shift                   (3)
#define  DFE_HDMI_RX_PHY_REGD20_p0_pll_wd_ckrdy_ro_shift                         (2)
#define  DFE_HDMI_RX_PHY_REGD20_p0_pll_wd_rst_wc_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD20_p0_wdog_rst_n_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_clk_rdy_mask                       (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_eqen_rdy_mask                      (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_data_rdy_mask                      (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_pi_mask                            (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_data_rdy_time_mask                        (0x0F000000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_clkout_manual_mask                     (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_eqen_manual_mask                       (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_data_manual_mask                       (0x00200000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_eqen_rdy_time_mask                        (0x001E0000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_order_mask                                (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_base_time_mask                     (0x0000E000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_en_mask                            (0x00001000)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_rst_wid_mask                       (0x00000C00)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_time_rdy_mask                      (0x00000300)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_acdr_l0_en_mask                           (0x00000080)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_eqen_rdy_l0_mask                   (0x00000040)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_data_rdy_l0_mask                   (0x00000020)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_eqen_manual_l0_mask                    (0x00000010)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_data_manual_l0_mask                    (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD20_p0_pll_wd_ckrdy_ro_mask                          (0x00000004)
#define  DFE_HDMI_RX_PHY_REGD20_p0_pll_wd_rst_wc_mask                            (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD20_p0_wdog_rst_n_mask                               (0x00000001)
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_clk_rdy(data)                      (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_eqen_rdy(data)                     (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_data_rdy(data)                     (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_pi(data)                           (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_data_rdy_time(data)                       (0x0F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_clkout_manual(data)                    (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_eqen_manual(data)                      (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_data_manual(data)                      (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_eqen_rdy_time(data)                       (0x001E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_order(data)                               (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_base_time(data)                    (0x0000E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_en(data)                           (0x00001000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_rst_wid(data)                      (0x00000C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_pll_wd_time_rdy(data)                     (0x00000300&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_acdr_l0_en(data)                          (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_eqen_rdy_l0(data)                  (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_bypass_data_rdy_l0(data)                  (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_eqen_manual_l0(data)                   (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD20_reg_p0_en_data_manual_l0(data)                   (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD20_p0_pll_wd_ckrdy_ro(data)                         (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD20_p0_pll_wd_rst_wc(data)                           (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD20_p0_wdog_rst_n(data)                              (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_bypass_clk_rdy(data)                  ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_bypass_eqen_rdy(data)                 ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_bypass_data_rdy(data)                 ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_bypass_pi(data)                       ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_data_rdy_time(data)                   ((0x0F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_en_clkout_manual(data)                ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_en_eqen_manual(data)                  ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_en_data_manual(data)                  ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_eqen_rdy_time(data)                   ((0x001E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_order(data)                           ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_pll_wd_base_time(data)                ((0x0000E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_pll_wd_en(data)                       ((0x00001000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_pll_wd_rst_wid(data)                  ((0x00000C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_pll_wd_time_rdy(data)                 ((0x00000300&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_acdr_l0_en(data)                      ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_bypass_eqen_rdy_l0(data)              ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_bypass_data_rdy_l0(data)              ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_en_eqen_manual_l0(data)               ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD20_get_reg_p0_en_data_manual_l0(data)               ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD20_get_p0_pll_wd_ckrdy_ro(data)                     ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD20_get_p0_pll_wd_rst_wc(data)                       ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_REGD20_get_p0_wdog_rst_n(data)                          (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_REGD21                                                  0x1800DBE0
#define  DFE_HDMI_RX_PHY_REGD21_reg_addr                                         "0xB800DBE0"
#define  DFE_HDMI_RX_PHY_REGD21_reg                                              0xB800DBE0
#define  DFE_HDMI_RX_PHY_REGD21_inst_addr                                        "0x006C"
#define  set_DFE_HDMI_RX_PHY_REGD21_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD21_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD21_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD21_reg))
#define  DFE_HDMI_RX_PHY_REGD21_reg_p0_wd_sdm_en_shift                           (31)
#define  DFE_HDMI_RX_PHY_REGD21_reg_p0_f_code_shift                              (16)
#define  DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD21_reg_p0_wd_sdm_en_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD21_reg_p0_f_code_mask                               (0x0FFF0000)
#define  DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_mask                               (0x000001FF)
#define  DFE_HDMI_RX_PHY_REGD21_reg_p0_wd_sdm_en(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD21_reg_p0_f_code(data)                              (0x0FFF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code(data)                              (0x000001FF&(data))
#define  DFE_HDMI_RX_PHY_REGD21_get_reg_p0_wd_sdm_en(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD21_get_reg_p0_f_code(data)                          ((0x0FFF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD21_get_reg_p0_n_code(data)                          (0x000001FF&(data))

#define  DFE_HDMI_RX_PHY_REGD22                                                  0x1800DBE4
#define  DFE_HDMI_RX_PHY_REGD22_reg_addr                                         "0xB800DBE4"
#define  DFE_HDMI_RX_PHY_REGD22_reg                                              0xB800DBE4
#define  DFE_HDMI_RX_PHY_REGD22_inst_addr                                        "0x006D"
#define  set_DFE_HDMI_RX_PHY_REGD22_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD22_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD22_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD22_reg))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_clk_rdy_shift                      (31)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_eqen_rdy_shift                     (30)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_data_rdy_shift                     (29)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_pi_shift                           (28)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_data_rdy_time_shift                       (24)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_clkout_manual_shift                    (23)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_eqen_manual_shift                      (22)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_data_manual_shift                      (21)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_eqen_rdy_time_shift                       (17)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_order_shift                               (16)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_base_time_shift                    (13)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_en_shift                           (12)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_rst_wid_shift                      (10)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_time_rdy_shift                     (8)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_acdr_l0_en_shift                          (7)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_eqen_rdy_l0_shift                  (6)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_data_rdy_l0_shift                  (5)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_eqen_manual_l0_shift                   (4)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_data_manual_l0_shift                   (3)
#define  DFE_HDMI_RX_PHY_REGD22_p1_pll_wd_ckrdy_ro_shift                         (2)
#define  DFE_HDMI_RX_PHY_REGD22_p1_pll_wd_rst_wc_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD22_p1_wdog_rst_n_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_clk_rdy_mask                       (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_eqen_rdy_mask                      (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_data_rdy_mask                      (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_pi_mask                            (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_data_rdy_time_mask                        (0x0F000000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_clkout_manual_mask                     (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_eqen_manual_mask                       (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_data_manual_mask                       (0x00200000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_eqen_rdy_time_mask                        (0x001E0000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_order_mask                                (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_base_time_mask                     (0x0000E000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_en_mask                            (0x00001000)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_rst_wid_mask                       (0x00000C00)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_time_rdy_mask                      (0x00000300)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_acdr_l0_en_mask                           (0x00000080)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_eqen_rdy_l0_mask                   (0x00000040)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_data_rdy_l0_mask                   (0x00000020)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_eqen_manual_l0_mask                    (0x00000010)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_data_manual_l0_mask                    (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD22_p1_pll_wd_ckrdy_ro_mask                          (0x00000004)
#define  DFE_HDMI_RX_PHY_REGD22_p1_pll_wd_rst_wc_mask                            (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD22_p1_wdog_rst_n_mask                               (0x00000001)
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_clk_rdy(data)                      (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_eqen_rdy(data)                     (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_data_rdy(data)                     (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_pi(data)                           (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_data_rdy_time(data)                       (0x0F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_clkout_manual(data)                    (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_eqen_manual(data)                      (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_data_manual(data)                      (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_eqen_rdy_time(data)                       (0x001E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_order(data)                               (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_base_time(data)                    (0x0000E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_en(data)                           (0x00001000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_rst_wid(data)                      (0x00000C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_pll_wd_time_rdy(data)                     (0x00000300&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_acdr_l0_en(data)                          (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_eqen_rdy_l0(data)                  (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_bypass_data_rdy_l0(data)                  (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_eqen_manual_l0(data)                   (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD22_reg_p1_en_data_manual_l0(data)                   (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD22_p1_pll_wd_ckrdy_ro(data)                         (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD22_p1_pll_wd_rst_wc(data)                           (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD22_p1_wdog_rst_n(data)                              (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_bypass_clk_rdy(data)                  ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_bypass_eqen_rdy(data)                 ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_bypass_data_rdy(data)                 ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_bypass_pi(data)                       ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_data_rdy_time(data)                   ((0x0F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_en_clkout_manual(data)                ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_en_eqen_manual(data)                  ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_en_data_manual(data)                  ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_eqen_rdy_time(data)                   ((0x001E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_order(data)                           ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_pll_wd_base_time(data)                ((0x0000E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_pll_wd_en(data)                       ((0x00001000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_pll_wd_rst_wid(data)                  ((0x00000C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_pll_wd_time_rdy(data)                 ((0x00000300&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_acdr_l0_en(data)                      ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_bypass_eqen_rdy_l0(data)              ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_bypass_data_rdy_l0(data)              ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_en_eqen_manual_l0(data)               ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD22_get_reg_p1_en_data_manual_l0(data)               ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD22_get_p1_pll_wd_ckrdy_ro(data)                     ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD22_get_p1_pll_wd_rst_wc(data)                       ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_REGD22_get_p1_wdog_rst_n(data)                          (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_REGD23                                                  0x1800DBE8
#define  DFE_HDMI_RX_PHY_REGD23_reg_addr                                         "0xB800DBE8"
#define  DFE_HDMI_RX_PHY_REGD23_reg                                              0xB800DBE8
#define  DFE_HDMI_RX_PHY_REGD23_inst_addr                                        "0x006E"
#define  set_DFE_HDMI_RX_PHY_REGD23_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD23_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD23_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD23_reg))
#define  DFE_HDMI_RX_PHY_REGD23_reg_p1_wd_sdm_en_shift                           (31)
#define  DFE_HDMI_RX_PHY_REGD23_reg_p1_f_code_shift                              (16)
#define  DFE_HDMI_RX_PHY_REGD23_reg_p1_n_code_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD23_reg_p1_wd_sdm_en_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD23_reg_p1_f_code_mask                               (0x0FFF0000)
#define  DFE_HDMI_RX_PHY_REGD23_reg_p1_n_code_mask                               (0x000001FF)
#define  DFE_HDMI_RX_PHY_REGD23_reg_p1_wd_sdm_en(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD23_reg_p1_f_code(data)                              (0x0FFF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD23_reg_p1_n_code(data)                              (0x000001FF&(data))
#define  DFE_HDMI_RX_PHY_REGD23_get_reg_p1_wd_sdm_en(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD23_get_reg_p1_f_code(data)                          ((0x0FFF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD23_get_reg_p1_n_code(data)                          (0x000001FF&(data))

#define  DFE_HDMI_RX_PHY_REGD24                                                  0x1800DBEC
#define  DFE_HDMI_RX_PHY_REGD24_reg_addr                                         "0xB800DBEC"
#define  DFE_HDMI_RX_PHY_REGD24_reg                                              0xB800DBEC
#define  DFE_HDMI_RX_PHY_REGD24_inst_addr                                        "0x006F"
#define  set_DFE_HDMI_RX_PHY_REGD24_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD24_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD24_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD24_reg))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_clk_rdy_shift                      (31)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_eqen_rdy_shift                     (30)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_data_rdy_shift                     (29)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_pi_shift                           (28)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_data_rdy_time_shift                       (24)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_clkout_manual_shift                    (23)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_eqen_manual_shift                      (22)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_data_manual_shift                      (21)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_eqen_rdy_time_shift                       (17)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_order_shift                               (16)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_base_time_shift                    (13)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_en_shift                           (12)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_rst_wid_shift                      (10)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_time_rdy_shift                     (8)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_acdr_l0_en_shift                          (7)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_eqen_rdy_l0_shift                  (6)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_data_rdy_l0_shift                  (5)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_eqen_manual_l0_shift                   (4)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_data_manual_l0_shift                   (3)
#define  DFE_HDMI_RX_PHY_REGD24_p2_pll_wd_ckrdy_ro_shift                         (2)
#define  DFE_HDMI_RX_PHY_REGD24_p2_pll_wd_rst_wc_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD24_p2_wdog_rst_n_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_clk_rdy_mask                       (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_eqen_rdy_mask                      (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_data_rdy_mask                      (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_pi_mask                            (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_data_rdy_time_mask                        (0x0F000000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_clkout_manual_mask                     (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_eqen_manual_mask                       (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_data_manual_mask                       (0x00200000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_eqen_rdy_time_mask                        (0x001E0000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_order_mask                                (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_base_time_mask                     (0x0000E000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_en_mask                            (0x00001000)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_rst_wid_mask                       (0x00000C00)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_time_rdy_mask                      (0x00000300)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_acdr_l0_en_mask                           (0x00000080)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_eqen_rdy_l0_mask                   (0x00000040)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_data_rdy_l0_mask                   (0x00000020)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_eqen_manual_l0_mask                    (0x00000010)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_data_manual_l0_mask                    (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD24_p2_pll_wd_ckrdy_ro_mask                          (0x00000004)
#define  DFE_HDMI_RX_PHY_REGD24_p2_pll_wd_rst_wc_mask                            (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD24_p2_wdog_rst_n_mask                               (0x00000001)
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_clk_rdy(data)                      (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_eqen_rdy(data)                     (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_data_rdy(data)                     (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_pi(data)                           (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_data_rdy_time(data)                       (0x0F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_clkout_manual(data)                    (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_eqen_manual(data)                      (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_data_manual(data)                      (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_eqen_rdy_time(data)                       (0x001E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_order(data)                               (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_base_time(data)                    (0x0000E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_en(data)                           (0x00001000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_rst_wid(data)                      (0x00000C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_pll_wd_time_rdy(data)                     (0x00000300&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_acdr_l0_en(data)                          (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_eqen_rdy_l0(data)                  (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_bypass_data_rdy_l0(data)                  (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_eqen_manual_l0(data)                   (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD24_reg_p2_en_data_manual_l0(data)                   (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD24_p2_pll_wd_ckrdy_ro(data)                         (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD24_p2_pll_wd_rst_wc(data)                           (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD24_p2_wdog_rst_n(data)                              (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_bypass_clk_rdy(data)                  ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_bypass_eqen_rdy(data)                 ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_bypass_data_rdy(data)                 ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_bypass_pi(data)                       ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_data_rdy_time(data)                   ((0x0F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_en_clkout_manual(data)                ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_en_eqen_manual(data)                  ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_en_data_manual(data)                  ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_eqen_rdy_time(data)                   ((0x001E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_order(data)                           ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_pll_wd_base_time(data)                ((0x0000E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_pll_wd_en(data)                       ((0x00001000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_pll_wd_rst_wid(data)                  ((0x00000C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_pll_wd_time_rdy(data)                 ((0x00000300&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_acdr_l0_en(data)                      ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_bypass_eqen_rdy_l0(data)              ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_bypass_data_rdy_l0(data)              ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_en_eqen_manual_l0(data)               ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD24_get_reg_p2_en_data_manual_l0(data)               ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD24_get_p2_pll_wd_ckrdy_ro(data)                     ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD24_get_p2_pll_wd_rst_wc(data)                       ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_REGD24_get_p2_wdog_rst_n(data)                          (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_REGD25                                                  0x1800DBF0
#define  DFE_HDMI_RX_PHY_REGD25_reg_addr                                         "0xB800DBF0"
#define  DFE_HDMI_RX_PHY_REGD25_reg                                              0xB800DBF0
#define  DFE_HDMI_RX_PHY_REGD25_inst_addr                                        "0x0070"
#define  set_DFE_HDMI_RX_PHY_REGD25_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD25_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD25_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD25_reg))
#define  DFE_HDMI_RX_PHY_REGD25_reg_p2_wd_sdm_en_shift                           (31)
#define  DFE_HDMI_RX_PHY_REGD25_reg_p2_f_code_shift                              (16)
#define  DFE_HDMI_RX_PHY_REGD25_reg_p2_n_code_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD25_reg_p2_wd_sdm_en_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD25_reg_p2_f_code_mask                               (0x0FFF0000)
#define  DFE_HDMI_RX_PHY_REGD25_reg_p2_n_code_mask                               (0x000001FF)
#define  DFE_HDMI_RX_PHY_REGD25_reg_p2_wd_sdm_en(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD25_reg_p2_f_code(data)                              (0x0FFF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD25_reg_p2_n_code(data)                              (0x000001FF&(data))
#define  DFE_HDMI_RX_PHY_REGD25_get_reg_p2_wd_sdm_en(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD25_get_reg_p2_f_code(data)                          ((0x0FFF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD25_get_reg_p2_n_code(data)                          (0x000001FF&(data))

#define  DFE_HDMI_RX_PHY_REGD26                                                  0x1800DBF4
#define  DFE_HDMI_RX_PHY_REGD26_reg_addr                                         "0xB800DBF4"
#define  DFE_HDMI_RX_PHY_REGD26_reg                                              0xB800DBF4
#define  DFE_HDMI_RX_PHY_REGD26_inst_addr                                        "0x0071"
#define  set_DFE_HDMI_RX_PHY_REGD26_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD26_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD26_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD26_reg))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_clk_rdy_shift                      (31)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_eqen_rdy_shift                     (30)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_data_rdy_shift                     (29)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_pi_shift                           (28)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_data_rdy_time_shift                       (24)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_clkout_manual_shift                    (23)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_eqen_manual_shift                      (22)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_data_manual_shift                      (21)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_eqen_rdy_time_shift                       (17)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_order_shift                               (16)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_base_time_shift                    (13)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_en_shift                           (12)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_rst_wid_shift                      (10)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_time_rdy_shift                     (8)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_acdr_l0_en_shift                          (7)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_eqen_rdy_l0_shift                  (6)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_data_rdy_l0_shift                  (5)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_eqen_manual_l0_shift                   (4)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_data_manual_l0_shift                   (3)
#define  DFE_HDMI_RX_PHY_REGD26_p3_pll_wd_ckrdy_ro_shift                         (2)
#define  DFE_HDMI_RX_PHY_REGD26_p3_pll_wd_rst_wc_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD26_p3_wdog_rst_n_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_clk_rdy_mask                       (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_eqen_rdy_mask                      (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_data_rdy_mask                      (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_pi_mask                            (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_data_rdy_time_mask                        (0x0F000000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_clkout_manual_mask                     (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_eqen_manual_mask                       (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_data_manual_mask                       (0x00200000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_eqen_rdy_time_mask                        (0x001E0000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_order_mask                                (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_base_time_mask                     (0x0000E000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_en_mask                            (0x00001000)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_rst_wid_mask                       (0x00000C00)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_time_rdy_mask                      (0x00000300)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_acdr_l0_en_mask                           (0x00000080)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_eqen_rdy_l0_mask                   (0x00000040)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_data_rdy_l0_mask                   (0x00000020)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_eqen_manual_l0_mask                    (0x00000010)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_data_manual_l0_mask                    (0x00000008)
#define  DFE_HDMI_RX_PHY_REGD26_p3_pll_wd_ckrdy_ro_mask                          (0x00000004)
#define  DFE_HDMI_RX_PHY_REGD26_p3_pll_wd_rst_wc_mask                            (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD26_p3_wdog_rst_n_mask                               (0x00000001)
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_clk_rdy(data)                      (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_eqen_rdy(data)                     (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_data_rdy(data)                     (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_pi(data)                           (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_data_rdy_time(data)                       (0x0F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_clkout_manual(data)                    (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_eqen_manual(data)                      (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_data_manual(data)                      (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_eqen_rdy_time(data)                       (0x001E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_order(data)                               (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_base_time(data)                    (0x0000E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_en(data)                           (0x00001000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_rst_wid(data)                      (0x00000C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_pll_wd_time_rdy(data)                     (0x00000300&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_acdr_l0_en(data)                          (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_eqen_rdy_l0(data)                  (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_bypass_data_rdy_l0(data)                  (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_eqen_manual_l0(data)                   (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD26_reg_p3_en_data_manual_l0(data)                   (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_REGD26_p3_pll_wd_ckrdy_ro(data)                         (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD26_p3_pll_wd_rst_wc(data)                           (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD26_p3_wdog_rst_n(data)                              (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_bypass_clk_rdy(data)                  ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_bypass_eqen_rdy(data)                 ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_bypass_data_rdy(data)                 ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_bypass_pi(data)                       ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_data_rdy_time(data)                   ((0x0F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_en_clkout_manual(data)                ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_en_eqen_manual(data)                  ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_en_data_manual(data)                  ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_eqen_rdy_time(data)                   ((0x001E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_order(data)                           ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_pll_wd_base_time(data)                ((0x0000E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_pll_wd_en(data)                       ((0x00001000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_pll_wd_rst_wid(data)                  ((0x00000C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_pll_wd_time_rdy(data)                 ((0x00000300&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_acdr_l0_en(data)                      ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_bypass_eqen_rdy_l0(data)              ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_bypass_data_rdy_l0(data)              ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_en_eqen_manual_l0(data)               ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD26_get_reg_p3_en_data_manual_l0(data)               ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_REGD26_get_p3_pll_wd_ckrdy_ro(data)                     ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD26_get_p3_pll_wd_rst_wc(data)                       ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_REGD26_get_p3_wdog_rst_n(data)                          (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_REGD27                                                  0x1800DBF8
#define  DFE_HDMI_RX_PHY_REGD27_reg_addr                                         "0xB800DBF8"
#define  DFE_HDMI_RX_PHY_REGD27_reg                                              0xB800DBF8
#define  DFE_HDMI_RX_PHY_REGD27_inst_addr                                        "0x0072"
#define  set_DFE_HDMI_RX_PHY_REGD27_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD27_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD27_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD27_reg))
#define  DFE_HDMI_RX_PHY_REGD27_reg_p3_wd_sdm_en_shift                           (31)
#define  DFE_HDMI_RX_PHY_REGD27_reg_p3_f_code_shift                              (16)
#define  DFE_HDMI_RX_PHY_REGD27_reg_p3_n_code_shift                              (0)
#define  DFE_HDMI_RX_PHY_REGD27_reg_p3_wd_sdm_en_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD27_reg_p3_f_code_mask                               (0x0FFF0000)
#define  DFE_HDMI_RX_PHY_REGD27_reg_p3_n_code_mask                               (0x000001FF)
#define  DFE_HDMI_RX_PHY_REGD27_reg_p3_wd_sdm_en(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD27_reg_p3_f_code(data)                              (0x0FFF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD27_reg_p3_n_code(data)                              (0x000001FF&(data))
#define  DFE_HDMI_RX_PHY_REGD27_get_reg_p3_wd_sdm_en(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD27_get_reg_p3_f_code(data)                          ((0x0FFF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD27_get_reg_p3_n_code(data)                          (0x000001FF&(data))

#define  DFE_HDMI_RX_PHY_REGD28                                                  0x1800DBFC
#define  DFE_HDMI_RX_PHY_REGD28_reg_addr                                         "0xB800DBFC"
#define  DFE_HDMI_RX_PHY_REGD28_reg                                              0xB800DBFC
#define  DFE_HDMI_RX_PHY_REGD28_inst_addr                                        "0x0073"
#define  set_DFE_HDMI_RX_PHY_REGD28_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD28_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD28_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD28_reg))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_auto_mode_shift                           (31)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_adp_en_manual_shift                       (30)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_cp_en_manual_shift                        (29)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_adap_eq_off_shift                         (28)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_adp_time_shift                            (23)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_time_shift                          (20)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_manual_shift                        (19)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_late_shift                          (18)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_vco_coarse_shift                          (11)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_divide_num_shift                          (4)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_init_time_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_auto_mode_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_adp_en_manual_mask                        (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_cp_en_manual_mask                         (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_adap_eq_off_mask                          (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_adp_time_mask                             (0x0F800000)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_time_mask                           (0x00700000)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_manual_mask                         (0x00080000)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_late_mask                           (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_vco_coarse_mask                           (0x0003F800)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_divide_num_mask                           (0x000007F0)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_init_time_mask                            (0x0000000E)
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_auto_mode(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_adp_en_manual(data)                       (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_cp_en_manual(data)                        (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_adap_eq_off(data)                         (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_adp_time(data)                            (0x0F800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_time(data)                          (0x00700000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_manual(data)                        (0x00080000&((data)<<19))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_late(data)                          (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_vco_coarse(data)                          (0x0003F800&((data)<<11))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_divide_num(data)                          (0x000007F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD28_reg_p0_init_time(data)                           (0x0000000E&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_auto_mode(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_adp_en_manual(data)                   ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_cp_en_manual(data)                    ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_adap_eq_off(data)                     ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_adp_time(data)                        ((0x0F800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_calib_time(data)                      ((0x00700000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_calib_manual(data)                    ((0x00080000&(data))>>19)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_calib_late(data)                      ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_vco_coarse(data)                      ((0x0003F800&(data))>>11)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_divide_num(data)                      ((0x000007F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD28_get_reg_p0_init_time(data)                       ((0x0000000E&(data))>>1)

#define  DFE_HDMI_RX_PHY_REGD29                                                  0x1800DC00
#define  DFE_HDMI_RX_PHY_REGD29_reg_addr                                         "0xB800DC00"
#define  DFE_HDMI_RX_PHY_REGD29_reg                                              0xB800DC00
#define  DFE_HDMI_RX_PHY_REGD29_inst_addr                                        "0x0074"
#define  set_DFE_HDMI_RX_PHY_REGD29_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD29_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD29_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD29_reg))
#define  DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit_shift                       (0)
#define  DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit_mask                        (0x07FF0000)
#define  DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit_mask                        (0x000007FF)
#define  DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit(data)                       (0x07FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit(data)                       (0x000007FF&(data))
#define  DFE_HDMI_RX_PHY_REGD29_get_reg_p0_lock_up_limit(data)                   ((0x07FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD29_get_reg_p0_lock_dn_limit(data)                   (0x000007FF&(data))

#define  DFE_HDMI_RX_PHY_REGD30                                                  0x1800DC04
#define  DFE_HDMI_RX_PHY_REGD30_reg_addr                                         "0xB800DC04"
#define  DFE_HDMI_RX_PHY_REGD30_reg                                              0xB800DC04
#define  DFE_HDMI_RX_PHY_REGD30_inst_addr                                        "0x0075"
#define  set_DFE_HDMI_RX_PHY_REGD30_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD30_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD30_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD30_reg))
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp_shift                              (12)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_r_shift                               (6)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_c_shift                               (4)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_vc_sel_shift                              (2)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_calib_reset_sel_shift                     (1)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp_mask                               (0xFFFFF000)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_r_mask                                (0x00000FC0)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_c_mask                                (0x00000030)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_vc_sel_mask                               (0x0000000C)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_calib_reset_sel_mask                      (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp(data)                              (0xFFFFF000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_r(data)                               (0x00000FC0&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_c(data)                               (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_vc_sel(data)                              (0x0000000C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD30_reg_p0_calib_reset_sel(data)                     (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD30_get_reg_p0_cdr_cp(data)                          ((0xFFFFF000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD30_get_reg_p0_cdr_r(data)                           ((0x00000FC0&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD30_get_reg_p0_cdr_c(data)                           ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD30_get_reg_p0_vc_sel(data)                          ((0x0000000C&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD30_get_reg_p0_calib_reset_sel(data)                 ((0x00000002&(data))>>1)

#define  DFE_HDMI_RX_PHY_REGD31                                                  0x1800DC08
#define  DFE_HDMI_RX_PHY_REGD31_reg_addr                                         "0xB800DC08"
#define  DFE_HDMI_RX_PHY_REGD31_reg                                              0xB800DC08
#define  DFE_HDMI_RX_PHY_REGD31_inst_addr                                        "0x0076"
#define  set_DFE_HDMI_RX_PHY_REGD31_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD31_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD31_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD31_reg))
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_slope_lv_up_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_slope_lv_dn_shift                         (10)
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_cp_time_shift                             (5)
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_timer_4_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_slope_lv_up_mask                          (0xFFE00000)
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_slope_lv_dn_mask                          (0x001FFC00)
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_cp_time_mask                              (0x000003E0)
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_timer_4_mask                              (0x0000001F)
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_slope_lv_up(data)                         (0xFFE00000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_slope_lv_dn(data)                         (0x001FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_cp_time(data)                             (0x000003E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD31_reg_p0_timer_4(data)                             (0x0000001F&(data))
#define  DFE_HDMI_RX_PHY_REGD31_get_reg_p0_slope_lv_up(data)                     ((0xFFE00000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD31_get_reg_p0_slope_lv_dn(data)                     ((0x001FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD31_get_reg_p0_cp_time(data)                         ((0x000003E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD31_get_reg_p0_timer_4(data)                         (0x0000001F&(data))

#define  DFE_HDMI_RX_PHY_REGD32                                                  0x1800DC0C
#define  DFE_HDMI_RX_PHY_REGD32_reg_addr                                         "0xB800DC0C"
#define  DFE_HDMI_RX_PHY_REGD32_reg                                              0xB800DC0C
#define  DFE_HDMI_RX_PHY_REGD32_inst_addr                                        "0x0077"
#define  set_DFE_HDMI_RX_PHY_REGD32_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD32_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD32_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD32_reg))
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_slope_hv_up_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_slope_hv_dn_shift                         (10)
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_timer_5_shift                             (9)
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_timer_6_shift                             (4)
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_slope_hv_up_mask                          (0xFFE00000)
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_slope_hv_dn_mask                          (0x001FFC00)
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_timer_5_mask                              (0x00000200)
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_timer_6_mask                              (0x000001F0)
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_slope_hv_up(data)                         (0xFFE00000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_slope_hv_dn(data)                         (0x001FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_timer_5(data)                             (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_REGD32_reg_p0_timer_6(data)                             (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD32_get_reg_p0_slope_hv_up(data)                     ((0xFFE00000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD32_get_reg_p0_slope_hv_dn(data)                     ((0x001FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD32_get_reg_p0_timer_5(data)                         ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_REGD32_get_reg_p0_timer_6(data)                         ((0x000001F0&(data))>>4)

#define  DFE_HDMI_RX_PHY_REGD33                                                  0x1800DC10
#define  DFE_HDMI_RX_PHY_REGD33_reg_addr                                         "0xB800DC10"
#define  DFE_HDMI_RX_PHY_REGD33_reg                                              0xB800DC10
#define  DFE_HDMI_RX_PHY_REGD33_inst_addr                                        "0x0078"
#define  set_DFE_HDMI_RX_PHY_REGD33_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD33_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD33_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD33_reg))
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_start_en_manual_shift                     (31)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_pfd_en_manual_shift                       (30)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_pfd_time_shift                            (25)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_pfd_bypass_shift                          (24)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_rxidle_bypass_shift                       (23)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_slope_manual_shift                        (22)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_slope_band_shift                          (17)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_old_mode_shift                            (16)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_start_en_manual_mask                      (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_pfd_en_manual_mask                        (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_pfd_time_mask                             (0x3E000000)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_pfd_bypass_mask                           (0x01000000)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_rxidle_bypass_mask                        (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_slope_manual_mask                         (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_slope_band_mask                           (0x003E0000)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_old_mode_mask                             (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_start_en_manual(data)                     (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_pfd_en_manual(data)                       (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_pfd_time(data)                            (0x3E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_pfd_bypass(data)                          (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_rxidle_bypass(data)                       (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_slope_manual(data)                        (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_slope_band(data)                          (0x003E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD33_reg_p0_old_mode(data)                            (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD33_get_reg_p0_start_en_manual(data)                 ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD33_get_reg_p0_pfd_en_manual(data)                   ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD33_get_reg_p0_pfd_time(data)                        ((0x3E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD33_get_reg_p0_pfd_bypass(data)                      ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD33_get_reg_p0_rxidle_bypass(data)                   ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD33_get_reg_p0_slope_manual(data)                    ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD33_get_reg_p0_slope_band(data)                      ((0x003E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD33_get_reg_p0_old_mode(data)                        ((0x00010000&(data))>>16)

#define  DFE_HDMI_RX_PHY_REGD34                                                  0x1800DC14
#define  DFE_HDMI_RX_PHY_REGD34_reg_addr                                         "0xB800DC14"
#define  DFE_HDMI_RX_PHY_REGD34_reg                                              0xB800DC14
#define  DFE_HDMI_RX_PHY_REGD34_inst_addr                                        "0x0079"
#define  set_DFE_HDMI_RX_PHY_REGD34_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD34_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD34_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD34_reg))
#define  DFE_HDMI_RX_PHY_REGD34_p0_fld_st_reg_shift                              (27)
#define  DFE_HDMI_RX_PHY_REGD34_p0_adp_en_fsm_reg_shift                          (26)
#define  DFE_HDMI_RX_PHY_REGD34_p0_cp_en_fsm_reg_shift                           (25)
#define  DFE_HDMI_RX_PHY_REGD34_p0_coarse_fsm_reg_shift                          (18)
#define  DFE_HDMI_RX_PHY_REGD34_p0_pfd_en_fsm_reg_shift                          (17)
#define  DFE_HDMI_RX_PHY_REGD34_p0_slope_lv_reg_shift                            (12)
#define  DFE_HDMI_RX_PHY_REGD34_p0_slope_hv_reg_shift                            (7)
#define  DFE_HDMI_RX_PHY_REGD34_p0_slope_final_reg_shift                         (2)
#define  DFE_HDMI_RX_PHY_REGD34_p0_fld_st_reg_mask                               (0xF8000000)
#define  DFE_HDMI_RX_PHY_REGD34_p0_adp_en_fsm_reg_mask                           (0x04000000)
#define  DFE_HDMI_RX_PHY_REGD34_p0_cp_en_fsm_reg_mask                            (0x02000000)
#define  DFE_HDMI_RX_PHY_REGD34_p0_coarse_fsm_reg_mask                           (0x01FC0000)
#define  DFE_HDMI_RX_PHY_REGD34_p0_pfd_en_fsm_reg_mask                           (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD34_p0_slope_lv_reg_mask                             (0x0001F000)
#define  DFE_HDMI_RX_PHY_REGD34_p0_slope_hv_reg_mask                             (0x00000F80)
#define  DFE_HDMI_RX_PHY_REGD34_p0_slope_final_reg_mask                          (0x0000007C)
#define  DFE_HDMI_RX_PHY_REGD34_p0_fld_st_reg(data)                              (0xF8000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD34_p0_adp_en_fsm_reg(data)                          (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_REGD34_p0_cp_en_fsm_reg(data)                           (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD34_p0_coarse_fsm_reg(data)                          (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD34_p0_pfd_en_fsm_reg(data)                          (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD34_p0_slope_lv_reg(data)                            (0x0001F000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD34_p0_slope_hv_reg(data)                            (0x00000F80&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD34_p0_slope_final_reg(data)                         (0x0000007C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD34_get_p0_fld_st_reg(data)                          ((0xF8000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD34_get_p0_adp_en_fsm_reg(data)                      ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_REGD34_get_p0_cp_en_fsm_reg(data)                       ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD34_get_p0_coarse_fsm_reg(data)                      ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD34_get_p0_pfd_en_fsm_reg(data)                      ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD34_get_p0_slope_lv_reg(data)                        ((0x0001F000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD34_get_p0_slope_hv_reg(data)                        ((0x00000F80&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD34_get_p0_slope_final_reg(data)                     ((0x0000007C&(data))>>2)

#define  DFE_HDMI_RX_PHY_REGD35                                                  0x1800DC18
#define  DFE_HDMI_RX_PHY_REGD35_reg_addr                                         "0xB800DC18"
#define  DFE_HDMI_RX_PHY_REGD35_reg                                              0xB800DC18
#define  DFE_HDMI_RX_PHY_REGD35_inst_addr                                        "0x007A"
#define  set_DFE_HDMI_RX_PHY_REGD35_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD35_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD35_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD35_reg))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_auto_mode_shift                           (31)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_adp_en_manual_shift                       (30)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_cp_en_manual_shift                        (29)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_adap_eq_off_shift                         (28)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_adp_time_shift                            (23)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_calib_time_shift                          (20)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_calib_manual_shift                        (19)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_calib_late_shift                          (18)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_vco_coarse_shift                          (11)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_divide_num_shift                          (4)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_init_time_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_auto_mode_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_adp_en_manual_mask                        (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_cp_en_manual_mask                         (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_adap_eq_off_mask                          (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_adp_time_mask                             (0x0F800000)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_calib_time_mask                           (0x00700000)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_calib_manual_mask                         (0x00080000)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_calib_late_mask                           (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_vco_coarse_mask                           (0x0003F800)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_divide_num_mask                           (0x000007F0)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_init_time_mask                            (0x0000000E)
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_auto_mode(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_adp_en_manual(data)                       (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_cp_en_manual(data)                        (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_adap_eq_off(data)                         (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_adp_time(data)                            (0x0F800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_calib_time(data)                          (0x00700000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_calib_manual(data)                        (0x00080000&((data)<<19))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_calib_late(data)                          (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_vco_coarse(data)                          (0x0003F800&((data)<<11))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_divide_num(data)                          (0x000007F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD35_reg_p1_init_time(data)                           (0x0000000E&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_auto_mode(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_adp_en_manual(data)                   ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_cp_en_manual(data)                    ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_adap_eq_off(data)                     ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_adp_time(data)                        ((0x0F800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_calib_time(data)                      ((0x00700000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_calib_manual(data)                    ((0x00080000&(data))>>19)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_calib_late(data)                      ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_vco_coarse(data)                      ((0x0003F800&(data))>>11)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_divide_num(data)                      ((0x000007F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD35_get_reg_p1_init_time(data)                       ((0x0000000E&(data))>>1)

#define  DFE_HDMI_RX_PHY_REGD36                                                  0x1800DC1C
#define  DFE_HDMI_RX_PHY_REGD36_reg_addr                                         "0xB800DC1C"
#define  DFE_HDMI_RX_PHY_REGD36_reg                                              0xB800DC1C
#define  DFE_HDMI_RX_PHY_REGD36_inst_addr                                        "0x007B"
#define  set_DFE_HDMI_RX_PHY_REGD36_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD36_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD36_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD36_reg))
#define  DFE_HDMI_RX_PHY_REGD36_reg_p1_lock_up_limit_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD36_reg_p1_lock_dn_limit_shift                       (0)
#define  DFE_HDMI_RX_PHY_REGD36_reg_p1_lock_up_limit_mask                        (0x07FF0000)
#define  DFE_HDMI_RX_PHY_REGD36_reg_p1_lock_dn_limit_mask                        (0x000007FF)
#define  DFE_HDMI_RX_PHY_REGD36_reg_p1_lock_up_limit(data)                       (0x07FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD36_reg_p1_lock_dn_limit(data)                       (0x000007FF&(data))
#define  DFE_HDMI_RX_PHY_REGD36_get_reg_p1_lock_up_limit(data)                   ((0x07FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD36_get_reg_p1_lock_dn_limit(data)                   (0x000007FF&(data))

#define  DFE_HDMI_RX_PHY_REGD37                                                  0x1800DC20
#define  DFE_HDMI_RX_PHY_REGD37_reg_addr                                         "0xB800DC20"
#define  DFE_HDMI_RX_PHY_REGD37_reg                                              0xB800DC20
#define  DFE_HDMI_RX_PHY_REGD37_inst_addr                                        "0x007C"
#define  set_DFE_HDMI_RX_PHY_REGD37_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD37_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD37_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD37_reg))
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_cdr_cp_shift                              (12)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_cdr_r_shift                               (6)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_cdr_c_shift                               (4)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_vc_sel_shift                              (2)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_calib_reset_sel_shift                     (1)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_cdr_cp_mask                               (0xFFFFF000)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_cdr_r_mask                                (0x00000FC0)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_cdr_c_mask                                (0x00000030)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_vc_sel_mask                               (0x0000000C)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_calib_reset_sel_mask                      (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_cdr_cp(data)                              (0xFFFFF000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_cdr_r(data)                               (0x00000FC0&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_cdr_c(data)                               (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_vc_sel(data)                              (0x0000000C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD37_reg_p1_calib_reset_sel(data)                     (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD37_get_reg_p1_cdr_cp(data)                          ((0xFFFFF000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD37_get_reg_p1_cdr_r(data)                           ((0x00000FC0&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD37_get_reg_p1_cdr_c(data)                           ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD37_get_reg_p1_vc_sel(data)                          ((0x0000000C&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD37_get_reg_p1_calib_reset_sel(data)                 ((0x00000002&(data))>>1)

#define  DFE_HDMI_RX_PHY_REGD38                                                  0x1800DC24
#define  DFE_HDMI_RX_PHY_REGD38_reg_addr                                         "0xB800DC24"
#define  DFE_HDMI_RX_PHY_REGD38_reg                                              0xB800DC24
#define  DFE_HDMI_RX_PHY_REGD38_inst_addr                                        "0x007D"
#define  set_DFE_HDMI_RX_PHY_REGD38_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD38_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD38_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD38_reg))
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_slope_lv_up_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_slope_lv_dn_shift                         (10)
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_cp_time_shift                             (5)
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_timer_4_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_slope_lv_up_mask                          (0xFFE00000)
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_slope_lv_dn_mask                          (0x001FFC00)
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_cp_time_mask                              (0x000003E0)
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_timer_4_mask                              (0x0000001F)
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_slope_lv_up(data)                         (0xFFE00000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_slope_lv_dn(data)                         (0x001FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_cp_time(data)                             (0x000003E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD38_reg_p1_timer_4(data)                             (0x0000001F&(data))
#define  DFE_HDMI_RX_PHY_REGD38_get_reg_p1_slope_lv_up(data)                     ((0xFFE00000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD38_get_reg_p1_slope_lv_dn(data)                     ((0x001FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD38_get_reg_p1_cp_time(data)                         ((0x000003E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD38_get_reg_p1_timer_4(data)                         (0x0000001F&(data))

#define  DFE_HDMI_RX_PHY_REGD39                                                  0x1800DC28
#define  DFE_HDMI_RX_PHY_REGD39_reg_addr                                         "0xB800DC28"
#define  DFE_HDMI_RX_PHY_REGD39_reg                                              0xB800DC28
#define  DFE_HDMI_RX_PHY_REGD39_inst_addr                                        "0x007E"
#define  set_DFE_HDMI_RX_PHY_REGD39_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD39_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD39_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD39_reg))
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_slope_hv_up_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_slope_hv_dn_shift                         (10)
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_timer_5_shift                             (9)
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_timer_6_shift                             (4)
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_slope_hv_up_mask                          (0xFFE00000)
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_slope_hv_dn_mask                          (0x001FFC00)
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_timer_5_mask                              (0x00000200)
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_timer_6_mask                              (0x000001F0)
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_slope_hv_up(data)                         (0xFFE00000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_slope_hv_dn(data)                         (0x001FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_timer_5(data)                             (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_REGD39_reg_p1_timer_6(data)                             (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD39_get_reg_p1_slope_hv_up(data)                     ((0xFFE00000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD39_get_reg_p1_slope_hv_dn(data)                     ((0x001FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD39_get_reg_p1_timer_5(data)                         ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_REGD39_get_reg_p1_timer_6(data)                         ((0x000001F0&(data))>>4)

#define  DFE_HDMI_RX_PHY_REGD40                                                  0x1800DC2C
#define  DFE_HDMI_RX_PHY_REGD40_reg_addr                                         "0xB800DC2C"
#define  DFE_HDMI_RX_PHY_REGD40_reg                                              0xB800DC2C
#define  DFE_HDMI_RX_PHY_REGD40_inst_addr                                        "0x007F"
#define  set_DFE_HDMI_RX_PHY_REGD40_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD40_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD40_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD40_reg))
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_start_en_manual_shift                     (31)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_pfd_en_manual_shift                       (30)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_pfd_time_shift                            (25)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_pfd_bypass_shift                          (24)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_rxidle_bypass_shift                       (23)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_slope_manual_shift                        (22)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_slope_band_shift                          (17)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_old_mode_shift                            (16)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_start_en_manual_mask                      (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_pfd_en_manual_mask                        (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_pfd_time_mask                             (0x3E000000)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_pfd_bypass_mask                           (0x01000000)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_rxidle_bypass_mask                        (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_slope_manual_mask                         (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_slope_band_mask                           (0x003E0000)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_old_mode_mask                             (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_start_en_manual(data)                     (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_pfd_en_manual(data)                       (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_pfd_time(data)                            (0x3E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_pfd_bypass(data)                          (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_rxidle_bypass(data)                       (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_slope_manual(data)                        (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_slope_band(data)                          (0x003E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD40_reg_p1_old_mode(data)                            (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD40_get_reg_p1_start_en_manual(data)                 ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD40_get_reg_p1_pfd_en_manual(data)                   ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD40_get_reg_p1_pfd_time(data)                        ((0x3E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD40_get_reg_p1_pfd_bypass(data)                      ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD40_get_reg_p1_rxidle_bypass(data)                   ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD40_get_reg_p1_slope_manual(data)                    ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD40_get_reg_p1_slope_band(data)                      ((0x003E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD40_get_reg_p1_old_mode(data)                        ((0x00010000&(data))>>16)

#define  DFE_HDMI_RX_PHY_REGD41                                                  0x1800DC30
#define  DFE_HDMI_RX_PHY_REGD41_reg_addr                                         "0xB800DC30"
#define  DFE_HDMI_RX_PHY_REGD41_reg                                              0xB800DC30
#define  DFE_HDMI_RX_PHY_REGD41_inst_addr                                        "0x0080"
#define  set_DFE_HDMI_RX_PHY_REGD41_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD41_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD41_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD41_reg))
#define  DFE_HDMI_RX_PHY_REGD41_p1_fld_st_reg_shift                              (27)
#define  DFE_HDMI_RX_PHY_REGD41_p1_adp_en_fsm_reg_shift                          (26)
#define  DFE_HDMI_RX_PHY_REGD41_p1_cp_en_fsm_reg_shift                           (25)
#define  DFE_HDMI_RX_PHY_REGD41_p1_coarse_fsm_reg_shift                          (18)
#define  DFE_HDMI_RX_PHY_REGD41_p1_pfd_en_fsm_reg_shift                          (17)
#define  DFE_HDMI_RX_PHY_REGD41_p1_slope_lv_reg_shift                            (12)
#define  DFE_HDMI_RX_PHY_REGD41_p1_slope_hv_reg_shift                            (7)
#define  DFE_HDMI_RX_PHY_REGD41_p1_slope_final_reg_shift                         (2)
#define  DFE_HDMI_RX_PHY_REGD41_p1_fld_st_reg_mask                               (0xF8000000)
#define  DFE_HDMI_RX_PHY_REGD41_p1_adp_en_fsm_reg_mask                           (0x04000000)
#define  DFE_HDMI_RX_PHY_REGD41_p1_cp_en_fsm_reg_mask                            (0x02000000)
#define  DFE_HDMI_RX_PHY_REGD41_p1_coarse_fsm_reg_mask                           (0x01FC0000)
#define  DFE_HDMI_RX_PHY_REGD41_p1_pfd_en_fsm_reg_mask                           (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD41_p1_slope_lv_reg_mask                             (0x0001F000)
#define  DFE_HDMI_RX_PHY_REGD41_p1_slope_hv_reg_mask                             (0x00000F80)
#define  DFE_HDMI_RX_PHY_REGD41_p1_slope_final_reg_mask                          (0x0000007C)
#define  DFE_HDMI_RX_PHY_REGD41_p1_fld_st_reg(data)                              (0xF8000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD41_p1_adp_en_fsm_reg(data)                          (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_REGD41_p1_cp_en_fsm_reg(data)                           (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD41_p1_coarse_fsm_reg(data)                          (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD41_p1_pfd_en_fsm_reg(data)                          (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD41_p1_slope_lv_reg(data)                            (0x0001F000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD41_p1_slope_hv_reg(data)                            (0x00000F80&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD41_p1_slope_final_reg(data)                         (0x0000007C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD41_get_p1_fld_st_reg(data)                          ((0xF8000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD41_get_p1_adp_en_fsm_reg(data)                      ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_REGD41_get_p1_cp_en_fsm_reg(data)                       ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD41_get_p1_coarse_fsm_reg(data)                      ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD41_get_p1_pfd_en_fsm_reg(data)                      ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD41_get_p1_slope_lv_reg(data)                        ((0x0001F000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD41_get_p1_slope_hv_reg(data)                        ((0x00000F80&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD41_get_p1_slope_final_reg(data)                     ((0x0000007C&(data))>>2)

#define  DFE_HDMI_RX_PHY_REGD42                                                  0x1800DC34
#define  DFE_HDMI_RX_PHY_REGD42_reg_addr                                         "0xB800DC34"
#define  DFE_HDMI_RX_PHY_REGD42_reg                                              0xB800DC34
#define  DFE_HDMI_RX_PHY_REGD42_inst_addr                                        "0x0081"
#define  set_DFE_HDMI_RX_PHY_REGD42_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD42_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD42_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD42_reg))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_auto_mode_shift                           (31)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_adp_en_manual_shift                       (30)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_cp_en_manual_shift                        (29)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_adap_eq_off_shift                         (28)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_adp_time_shift                            (23)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_calib_time_shift                          (20)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_calib_manual_shift                        (19)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_calib_late_shift                          (18)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_vco_coarse_shift                          (11)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_divide_num_shift                          (4)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_init_time_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_auto_mode_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_adp_en_manual_mask                        (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_cp_en_manual_mask                         (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_adap_eq_off_mask                          (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_adp_time_mask                             (0x0F800000)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_calib_time_mask                           (0x00700000)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_calib_manual_mask                         (0x00080000)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_calib_late_mask                           (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_vco_coarse_mask                           (0x0003F800)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_divide_num_mask                           (0x000007F0)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_init_time_mask                            (0x0000000E)
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_auto_mode(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_adp_en_manual(data)                       (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_cp_en_manual(data)                        (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_adap_eq_off(data)                         (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_adp_time(data)                            (0x0F800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_calib_time(data)                          (0x00700000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_calib_manual(data)                        (0x00080000&((data)<<19))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_calib_late(data)                          (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_vco_coarse(data)                          (0x0003F800&((data)<<11))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_divide_num(data)                          (0x000007F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD42_reg_p2_init_time(data)                           (0x0000000E&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_auto_mode(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_adp_en_manual(data)                   ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_cp_en_manual(data)                    ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_adap_eq_off(data)                     ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_adp_time(data)                        ((0x0F800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_calib_time(data)                      ((0x00700000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_calib_manual(data)                    ((0x00080000&(data))>>19)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_calib_late(data)                      ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_vco_coarse(data)                      ((0x0003F800&(data))>>11)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_divide_num(data)                      ((0x000007F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD42_get_reg_p2_init_time(data)                       ((0x0000000E&(data))>>1)

#define  DFE_HDMI_RX_PHY_REGD43                                                  0x1800DC38
#define  DFE_HDMI_RX_PHY_REGD43_reg_addr                                         "0xB800DC38"
#define  DFE_HDMI_RX_PHY_REGD43_reg                                              0xB800DC38
#define  DFE_HDMI_RX_PHY_REGD43_inst_addr                                        "0x0082"
#define  set_DFE_HDMI_RX_PHY_REGD43_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD43_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD43_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD43_reg))
#define  DFE_HDMI_RX_PHY_REGD43_reg_p2_lock_up_limit_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD43_reg_p2_lock_dn_limit_shift                       (0)
#define  DFE_HDMI_RX_PHY_REGD43_reg_p2_lock_up_limit_mask                        (0x07FF0000)
#define  DFE_HDMI_RX_PHY_REGD43_reg_p2_lock_dn_limit_mask                        (0x000007FF)
#define  DFE_HDMI_RX_PHY_REGD43_reg_p2_lock_up_limit(data)                       (0x07FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD43_reg_p2_lock_dn_limit(data)                       (0x000007FF&(data))
#define  DFE_HDMI_RX_PHY_REGD43_get_reg_p2_lock_up_limit(data)                   ((0x07FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD43_get_reg_p2_lock_dn_limit(data)                   (0x000007FF&(data))

#define  DFE_HDMI_RX_PHY_REGD44                                                  0x1800DC3C
#define  DFE_HDMI_RX_PHY_REGD44_reg_addr                                         "0xB800DC3C"
#define  DFE_HDMI_RX_PHY_REGD44_reg                                              0xB800DC3C
#define  DFE_HDMI_RX_PHY_REGD44_inst_addr                                        "0x0083"
#define  set_DFE_HDMI_RX_PHY_REGD44_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD44_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD44_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD44_reg))
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_cdr_cp_shift                              (12)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_cdr_r_shift                               (6)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_cdr_c_shift                               (4)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_vc_sel_shift                              (2)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_calib_reset_sel_shift                     (1)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_cdr_cp_mask                               (0xFFFFF000)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_cdr_r_mask                                (0x00000FC0)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_cdr_c_mask                                (0x00000030)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_vc_sel_mask                               (0x0000000C)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_calib_reset_sel_mask                      (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_cdr_cp(data)                              (0xFFFFF000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_cdr_r(data)                               (0x00000FC0&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_cdr_c(data)                               (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_vc_sel(data)                              (0x0000000C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD44_reg_p2_calib_reset_sel(data)                     (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD44_get_reg_p2_cdr_cp(data)                          ((0xFFFFF000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD44_get_reg_p2_cdr_r(data)                           ((0x00000FC0&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD44_get_reg_p2_cdr_c(data)                           ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD44_get_reg_p2_vc_sel(data)                          ((0x0000000C&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD44_get_reg_p2_calib_reset_sel(data)                 ((0x00000002&(data))>>1)

#define  DFE_HDMI_RX_PHY_REGD45                                                  0x1800DC40
#define  DFE_HDMI_RX_PHY_REGD45_reg_addr                                         "0xB800DC40"
#define  DFE_HDMI_RX_PHY_REGD45_reg                                              0xB800DC40
#define  DFE_HDMI_RX_PHY_REGD45_inst_addr                                        "0x0084"
#define  set_DFE_HDMI_RX_PHY_REGD45_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD45_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD45_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD45_reg))
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_slope_lv_up_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_slope_lv_dn_shift                         (10)
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_cp_time_shift                             (5)
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_timer_4_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_slope_lv_up_mask                          (0xFFE00000)
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_slope_lv_dn_mask                          (0x001FFC00)
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_cp_time_mask                              (0x000003E0)
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_timer_4_mask                              (0x0000001F)
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_slope_lv_up(data)                         (0xFFE00000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_slope_lv_dn(data)                         (0x001FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_cp_time(data)                             (0x000003E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD45_reg_p2_timer_4(data)                             (0x0000001F&(data))
#define  DFE_HDMI_RX_PHY_REGD45_get_reg_p2_slope_lv_up(data)                     ((0xFFE00000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD45_get_reg_p2_slope_lv_dn(data)                     ((0x001FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD45_get_reg_p2_cp_time(data)                         ((0x000003E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD45_get_reg_p2_timer_4(data)                         (0x0000001F&(data))

#define  DFE_HDMI_RX_PHY_REGD46                                                  0x1800DC44
#define  DFE_HDMI_RX_PHY_REGD46_reg_addr                                         "0xB800DC44"
#define  DFE_HDMI_RX_PHY_REGD46_reg                                              0xB800DC44
#define  DFE_HDMI_RX_PHY_REGD46_inst_addr                                        "0x0085"
#define  set_DFE_HDMI_RX_PHY_REGD46_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD46_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD46_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD46_reg))
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_slope_hv_up_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_slope_hv_dn_shift                         (10)
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_timer_5_shift                             (9)
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_timer_6_shift                             (4)
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_slope_hv_up_mask                          (0xFFE00000)
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_slope_hv_dn_mask                          (0x001FFC00)
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_timer_5_mask                              (0x00000200)
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_timer_6_mask                              (0x000001F0)
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_slope_hv_up(data)                         (0xFFE00000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_slope_hv_dn(data)                         (0x001FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_timer_5(data)                             (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_REGD46_reg_p2_timer_6(data)                             (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD46_get_reg_p2_slope_hv_up(data)                     ((0xFFE00000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD46_get_reg_p2_slope_hv_dn(data)                     ((0x001FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD46_get_reg_p2_timer_5(data)                         ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_REGD46_get_reg_p2_timer_6(data)                         ((0x000001F0&(data))>>4)

#define  DFE_HDMI_RX_PHY_REGD47                                                  0x1800DC48
#define  DFE_HDMI_RX_PHY_REGD47_reg_addr                                         "0xB800DC48"
#define  DFE_HDMI_RX_PHY_REGD47_reg                                              0xB800DC48
#define  DFE_HDMI_RX_PHY_REGD47_inst_addr                                        "0x0086"
#define  set_DFE_HDMI_RX_PHY_REGD47_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD47_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD47_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD47_reg))
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_start_en_manual_shift                     (31)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_pfd_en_manual_shift                       (30)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_pfd_time_shift                            (25)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_pfd_bypass_shift                          (24)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_rxidle_bypass_shift                       (23)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_slope_manual_shift                        (22)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_slope_band_shift                          (17)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_old_mode_shift                            (16)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_start_en_manual_mask                      (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_pfd_en_manual_mask                        (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_pfd_time_mask                             (0x3E000000)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_pfd_bypass_mask                           (0x01000000)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_rxidle_bypass_mask                        (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_slope_manual_mask                         (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_slope_band_mask                           (0x003E0000)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_old_mode_mask                             (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_start_en_manual(data)                     (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_pfd_en_manual(data)                       (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_pfd_time(data)                            (0x3E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_pfd_bypass(data)                          (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_rxidle_bypass(data)                       (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_slope_manual(data)                        (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_slope_band(data)                          (0x003E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD47_reg_p2_old_mode(data)                            (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD47_get_reg_p2_start_en_manual(data)                 ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD47_get_reg_p2_pfd_en_manual(data)                   ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD47_get_reg_p2_pfd_time(data)                        ((0x3E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD47_get_reg_p2_pfd_bypass(data)                      ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD47_get_reg_p2_rxidle_bypass(data)                   ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD47_get_reg_p2_slope_manual(data)                    ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD47_get_reg_p2_slope_band(data)                      ((0x003E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD47_get_reg_p2_old_mode(data)                        ((0x00010000&(data))>>16)

#define  DFE_HDMI_RX_PHY_REGD48                                                  0x1800DC4C
#define  DFE_HDMI_RX_PHY_REGD48_reg_addr                                         "0xB800DC4C"
#define  DFE_HDMI_RX_PHY_REGD48_reg                                              0xB800DC4C
#define  DFE_HDMI_RX_PHY_REGD48_inst_addr                                        "0x0087"
#define  set_DFE_HDMI_RX_PHY_REGD48_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD48_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD48_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD48_reg))
#define  DFE_HDMI_RX_PHY_REGD48_p2_fld_st_reg_shift                              (27)
#define  DFE_HDMI_RX_PHY_REGD48_p2_adp_en_fsm_reg_shift                          (26)
#define  DFE_HDMI_RX_PHY_REGD48_p2_cp_en_fsm_reg_shift                           (25)
#define  DFE_HDMI_RX_PHY_REGD48_p2_coarse_fsm_reg_shift                          (18)
#define  DFE_HDMI_RX_PHY_REGD48_p2_pfd_en_fsm_reg_shift                          (17)
#define  DFE_HDMI_RX_PHY_REGD48_p2_slope_lv_reg_shift                            (12)
#define  DFE_HDMI_RX_PHY_REGD48_p2_slope_hv_reg_shift                            (7)
#define  DFE_HDMI_RX_PHY_REGD48_p2_slope_final_reg_shift                         (2)
#define  DFE_HDMI_RX_PHY_REGD48_p2_fld_st_reg_mask                               (0xF8000000)
#define  DFE_HDMI_RX_PHY_REGD48_p2_adp_en_fsm_reg_mask                           (0x04000000)
#define  DFE_HDMI_RX_PHY_REGD48_p2_cp_en_fsm_reg_mask                            (0x02000000)
#define  DFE_HDMI_RX_PHY_REGD48_p2_coarse_fsm_reg_mask                           (0x01FC0000)
#define  DFE_HDMI_RX_PHY_REGD48_p2_pfd_en_fsm_reg_mask                           (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD48_p2_slope_lv_reg_mask                             (0x0001F000)
#define  DFE_HDMI_RX_PHY_REGD48_p2_slope_hv_reg_mask                             (0x00000F80)
#define  DFE_HDMI_RX_PHY_REGD48_p2_slope_final_reg_mask                          (0x0000007C)
#define  DFE_HDMI_RX_PHY_REGD48_p2_fld_st_reg(data)                              (0xF8000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD48_p2_adp_en_fsm_reg(data)                          (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_REGD48_p2_cp_en_fsm_reg(data)                           (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD48_p2_coarse_fsm_reg(data)                          (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD48_p2_pfd_en_fsm_reg(data)                          (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD48_p2_slope_lv_reg(data)                            (0x0001F000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD48_p2_slope_hv_reg(data)                            (0x00000F80&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD48_p2_slope_final_reg(data)                         (0x0000007C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD48_get_p2_fld_st_reg(data)                          ((0xF8000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD48_get_p2_adp_en_fsm_reg(data)                      ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_REGD48_get_p2_cp_en_fsm_reg(data)                       ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD48_get_p2_coarse_fsm_reg(data)                      ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD48_get_p2_pfd_en_fsm_reg(data)                      ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD48_get_p2_slope_lv_reg(data)                        ((0x0001F000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD48_get_p2_slope_hv_reg(data)                        ((0x00000F80&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD48_get_p2_slope_final_reg(data)                     ((0x0000007C&(data))>>2)

#define  DFE_HDMI_RX_PHY_REGD49                                                  0x1800DC50
#define  DFE_HDMI_RX_PHY_REGD49_reg_addr                                         "0xB800DC50"
#define  DFE_HDMI_RX_PHY_REGD49_reg                                              0xB800DC50
#define  DFE_HDMI_RX_PHY_REGD49_inst_addr                                        "0x0088"
#define  set_DFE_HDMI_RX_PHY_REGD49_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD49_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD49_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD49_reg))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_auto_mode_shift                           (31)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_adp_en_manual_shift                       (30)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_cp_en_manual_shift                        (29)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_adap_eq_off_shift                         (28)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_adp_time_shift                            (23)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_calib_time_shift                          (20)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_calib_manual_shift                        (19)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_calib_late_shift                          (18)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_vco_coarse_shift                          (11)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_divide_num_shift                          (4)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_init_time_shift                           (1)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_auto_mode_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_adp_en_manual_mask                        (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_cp_en_manual_mask                         (0x20000000)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_adap_eq_off_mask                          (0x10000000)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_adp_time_mask                             (0x0F800000)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_calib_time_mask                           (0x00700000)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_calib_manual_mask                         (0x00080000)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_calib_late_mask                           (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_vco_coarse_mask                           (0x0003F800)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_divide_num_mask                           (0x000007F0)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_init_time_mask                            (0x0000000E)
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_auto_mode(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_adp_en_manual(data)                       (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_cp_en_manual(data)                        (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_adap_eq_off(data)                         (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_adp_time(data)                            (0x0F800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_calib_time(data)                          (0x00700000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_calib_manual(data)                        (0x00080000&((data)<<19))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_calib_late(data)                          (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_vco_coarse(data)                          (0x0003F800&((data)<<11))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_divide_num(data)                          (0x000007F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD49_reg_p3_init_time(data)                           (0x0000000E&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_auto_mode(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_adp_en_manual(data)                   ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_cp_en_manual(data)                    ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_adap_eq_off(data)                     ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_adp_time(data)                        ((0x0F800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_calib_time(data)                      ((0x00700000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_calib_manual(data)                    ((0x00080000&(data))>>19)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_calib_late(data)                      ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_vco_coarse(data)                      ((0x0003F800&(data))>>11)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_divide_num(data)                      ((0x000007F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD49_get_reg_p3_init_time(data)                       ((0x0000000E&(data))>>1)

#define  DFE_HDMI_RX_PHY_REGD50                                                  0x1800DC54
#define  DFE_HDMI_RX_PHY_REGD50_reg_addr                                         "0xB800DC54"
#define  DFE_HDMI_RX_PHY_REGD50_reg                                              0xB800DC54
#define  DFE_HDMI_RX_PHY_REGD50_inst_addr                                        "0x0089"
#define  set_DFE_HDMI_RX_PHY_REGD50_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD50_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD50_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD50_reg))
#define  DFE_HDMI_RX_PHY_REGD50_reg_p3_lock_up_limit_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD50_reg_p3_lock_dn_limit_shift                       (0)
#define  DFE_HDMI_RX_PHY_REGD50_reg_p3_lock_up_limit_mask                        (0x07FF0000)
#define  DFE_HDMI_RX_PHY_REGD50_reg_p3_lock_dn_limit_mask                        (0x000007FF)
#define  DFE_HDMI_RX_PHY_REGD50_reg_p3_lock_up_limit(data)                       (0x07FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD50_reg_p3_lock_dn_limit(data)                       (0x000007FF&(data))
#define  DFE_HDMI_RX_PHY_REGD50_get_reg_p3_lock_up_limit(data)                   ((0x07FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD50_get_reg_p3_lock_dn_limit(data)                   (0x000007FF&(data))

#define  DFE_HDMI_RX_PHY_REGD51                                                  0x1800DC58
#define  DFE_HDMI_RX_PHY_REGD51_reg_addr                                         "0xB800DC58"
#define  DFE_HDMI_RX_PHY_REGD51_reg                                              0xB800DC58
#define  DFE_HDMI_RX_PHY_REGD51_inst_addr                                        "0x008A"
#define  set_DFE_HDMI_RX_PHY_REGD51_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD51_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD51_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD51_reg))
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_cdr_cp_shift                              (12)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_cdr_r_shift                               (6)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_cdr_c_shift                               (4)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_vc_sel_shift                              (2)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_calib_reset_sel_shift                     (1)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_cdr_cp_mask                               (0xFFFFF000)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_cdr_r_mask                                (0x00000FC0)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_cdr_c_mask                                (0x00000030)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_vc_sel_mask                               (0x0000000C)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_calib_reset_sel_mask                      (0x00000002)
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_cdr_cp(data)                              (0xFFFFF000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_cdr_r(data)                               (0x00000FC0&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_cdr_c(data)                               (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_vc_sel(data)                              (0x0000000C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD51_reg_p3_calib_reset_sel(data)                     (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_REGD51_get_reg_p3_cdr_cp(data)                          ((0xFFFFF000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD51_get_reg_p3_cdr_r(data)                           ((0x00000FC0&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD51_get_reg_p3_cdr_c(data)                           ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_REGD51_get_reg_p3_vc_sel(data)                          ((0x0000000C&(data))>>2)
#define  DFE_HDMI_RX_PHY_REGD51_get_reg_p3_calib_reset_sel(data)                 ((0x00000002&(data))>>1)

#define  DFE_HDMI_RX_PHY_REGD52                                                  0x1800DC5C
#define  DFE_HDMI_RX_PHY_REGD52_reg_addr                                         "0xB800DC5C"
#define  DFE_HDMI_RX_PHY_REGD52_reg                                              0xB800DC5C
#define  DFE_HDMI_RX_PHY_REGD52_inst_addr                                        "0x008B"
#define  set_DFE_HDMI_RX_PHY_REGD52_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD52_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD52_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD52_reg))
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_slope_lv_up_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_slope_lv_dn_shift                         (10)
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_cp_time_shift                             (5)
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_timer_4_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_slope_lv_up_mask                          (0xFFE00000)
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_slope_lv_dn_mask                          (0x001FFC00)
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_cp_time_mask                              (0x000003E0)
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_timer_4_mask                              (0x0000001F)
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_slope_lv_up(data)                         (0xFFE00000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_slope_lv_dn(data)                         (0x001FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_cp_time(data)                             (0x000003E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_REGD52_reg_p3_timer_4(data)                             (0x0000001F&(data))
#define  DFE_HDMI_RX_PHY_REGD52_get_reg_p3_slope_lv_up(data)                     ((0xFFE00000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD52_get_reg_p3_slope_lv_dn(data)                     ((0x001FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD52_get_reg_p3_cp_time(data)                         ((0x000003E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_REGD52_get_reg_p3_timer_4(data)                         (0x0000001F&(data))

#define  DFE_HDMI_RX_PHY_REGD53                                                  0x1800DC60
#define  DFE_HDMI_RX_PHY_REGD53_reg_addr                                         "0xB800DC60"
#define  DFE_HDMI_RX_PHY_REGD53_reg                                              0xB800DC60
#define  DFE_HDMI_RX_PHY_REGD53_inst_addr                                        "0x008C"
#define  set_DFE_HDMI_RX_PHY_REGD53_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD53_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD53_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD53_reg))
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_slope_hv_up_shift                         (21)
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_slope_hv_dn_shift                         (10)
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_timer_5_shift                             (9)
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_timer_6_shift                             (4)
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_slope_hv_up_mask                          (0xFFE00000)
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_slope_hv_dn_mask                          (0x001FFC00)
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_timer_5_mask                              (0x00000200)
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_timer_6_mask                              (0x000001F0)
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_slope_hv_up(data)                         (0xFFE00000&((data)<<21))
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_slope_hv_dn(data)                         (0x001FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_timer_5(data)                             (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_REGD53_reg_p3_timer_6(data)                             (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_REGD53_get_reg_p3_slope_hv_up(data)                     ((0xFFE00000&(data))>>21)
#define  DFE_HDMI_RX_PHY_REGD53_get_reg_p3_slope_hv_dn(data)                     ((0x001FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD53_get_reg_p3_timer_5(data)                         ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_REGD53_get_reg_p3_timer_6(data)                         ((0x000001F0&(data))>>4)

#define  DFE_HDMI_RX_PHY_REGD54                                                  0x1800DC64
#define  DFE_HDMI_RX_PHY_REGD54_reg_addr                                         "0xB800DC64"
#define  DFE_HDMI_RX_PHY_REGD54_reg                                              0xB800DC64
#define  DFE_HDMI_RX_PHY_REGD54_inst_addr                                        "0x008D"
#define  set_DFE_HDMI_RX_PHY_REGD54_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD54_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD54_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD54_reg))
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_start_en_manual_shift                     (31)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_pfd_en_manual_shift                       (30)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_pfd_time_shift                            (25)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_pfd_bypass_shift                          (24)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_rxidle_bypass_shift                       (23)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_slope_manual_shift                        (22)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_slope_band_shift                          (17)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_old_mode_shift                            (16)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_start_en_manual_mask                      (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_pfd_en_manual_mask                        (0x40000000)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_pfd_time_mask                             (0x3E000000)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_pfd_bypass_mask                           (0x01000000)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_rxidle_bypass_mask                        (0x00800000)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_slope_manual_mask                         (0x00400000)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_slope_band_mask                           (0x003E0000)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_old_mode_mask                             (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_start_en_manual(data)                     (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_pfd_en_manual(data)                       (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_pfd_time(data)                            (0x3E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_pfd_bypass(data)                          (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_rxidle_bypass(data)                       (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_slope_manual(data)                        (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_slope_band(data)                          (0x003E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD54_reg_p3_old_mode(data)                            (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD54_get_reg_p3_start_en_manual(data)                 ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD54_get_reg_p3_pfd_en_manual(data)                   ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_REGD54_get_reg_p3_pfd_time(data)                        ((0x3E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD54_get_reg_p3_pfd_bypass(data)                      ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD54_get_reg_p3_rxidle_bypass(data)                   ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_REGD54_get_reg_p3_slope_manual(data)                    ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_REGD54_get_reg_p3_slope_band(data)                      ((0x003E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD54_get_reg_p3_old_mode(data)                        ((0x00010000&(data))>>16)

#define  DFE_HDMI_RX_PHY_REGD55                                                  0x1800DC68
#define  DFE_HDMI_RX_PHY_REGD55_reg_addr                                         "0xB800DC68"
#define  DFE_HDMI_RX_PHY_REGD55_reg                                              0xB800DC68
#define  DFE_HDMI_RX_PHY_REGD55_inst_addr                                        "0x008E"
#define  set_DFE_HDMI_RX_PHY_REGD55_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD55_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD55_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD55_reg))
#define  DFE_HDMI_RX_PHY_REGD55_p3_fld_st_reg_shift                              (27)
#define  DFE_HDMI_RX_PHY_REGD55_p3_adp_en_fsm_reg_shift                          (26)
#define  DFE_HDMI_RX_PHY_REGD55_p3_cp_en_fsm_reg_shift                           (25)
#define  DFE_HDMI_RX_PHY_REGD55_p3_coarse_fsm_reg_shift                          (18)
#define  DFE_HDMI_RX_PHY_REGD55_p3_pfd_en_fsm_reg_shift                          (17)
#define  DFE_HDMI_RX_PHY_REGD55_p3_slope_lv_reg_shift                            (12)
#define  DFE_HDMI_RX_PHY_REGD55_p3_slope_hv_reg_shift                            (7)
#define  DFE_HDMI_RX_PHY_REGD55_p3_slope_final_reg_shift                         (2)
#define  DFE_HDMI_RX_PHY_REGD55_p3_fld_st_reg_mask                               (0xF8000000)
#define  DFE_HDMI_RX_PHY_REGD55_p3_adp_en_fsm_reg_mask                           (0x04000000)
#define  DFE_HDMI_RX_PHY_REGD55_p3_cp_en_fsm_reg_mask                            (0x02000000)
#define  DFE_HDMI_RX_PHY_REGD55_p3_coarse_fsm_reg_mask                           (0x01FC0000)
#define  DFE_HDMI_RX_PHY_REGD55_p3_pfd_en_fsm_reg_mask                           (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD55_p3_slope_lv_reg_mask                             (0x0001F000)
#define  DFE_HDMI_RX_PHY_REGD55_p3_slope_hv_reg_mask                             (0x00000F80)
#define  DFE_HDMI_RX_PHY_REGD55_p3_slope_final_reg_mask                          (0x0000007C)
#define  DFE_HDMI_RX_PHY_REGD55_p3_fld_st_reg(data)                              (0xF8000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD55_p3_adp_en_fsm_reg(data)                          (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_REGD55_p3_cp_en_fsm_reg(data)                           (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD55_p3_coarse_fsm_reg(data)                          (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD55_p3_pfd_en_fsm_reg(data)                          (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD55_p3_slope_lv_reg(data)                            (0x0001F000&((data)<<12))
#define  DFE_HDMI_RX_PHY_REGD55_p3_slope_hv_reg(data)                            (0x00000F80&((data)<<7))
#define  DFE_HDMI_RX_PHY_REGD55_p3_slope_final_reg(data)                         (0x0000007C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD55_get_p3_fld_st_reg(data)                          ((0xF8000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_REGD55_get_p3_adp_en_fsm_reg(data)                      ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_REGD55_get_p3_cp_en_fsm_reg(data)                       ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD55_get_p3_coarse_fsm_reg(data)                      ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD55_get_p3_pfd_en_fsm_reg(data)                      ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD55_get_p3_slope_lv_reg(data)                        ((0x0001F000&(data))>>12)
#define  DFE_HDMI_RX_PHY_REGD55_get_p3_slope_hv_reg(data)                        ((0x00000F80&(data))>>7)
#define  DFE_HDMI_RX_PHY_REGD55_get_p3_slope_final_reg(data)                     ((0x0000007C&(data))>>2)

#define  DFE_HDMI_RX_PHY_REGD56                                                  0x1800DC6C
#define  DFE_HDMI_RX_PHY_REGD56_reg_addr                                         "0xB800DC6C"
#define  DFE_HDMI_RX_PHY_REGD56_reg                                              0xB800DC6C
#define  DFE_HDMI_RX_PHY_REGD56_inst_addr                                        "0x008F"
#define  set_DFE_HDMI_RX_PHY_REGD56_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD56_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD56_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD56_reg))
#define  DFE_HDMI_RX_PHY_REGD56_p0_ck_md_rstb_shift                              (31)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_threshold_shift                     (25)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_debounce_shift                      (18)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_sel_shift                           (16)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_auto_shift                          (15)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_adj_shift                           (11)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_error_limit_shift                      (6)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_reserved_shift                      (2)
#define  DFE_HDMI_RX_PHY_REGD56_p0_ck_md_rstb_mask                               (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_threshold_mask                      (0x7E000000)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_debounce_mask                       (0x01FC0000)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_sel_mask                            (0x00030000)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_auto_mask                           (0x00008000)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_adj_mask                            (0x00007800)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_error_limit_mask                       (0x000007C0)
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_reserved_mask                       (0x0000003C)
#define  DFE_HDMI_RX_PHY_REGD56_p0_ck_md_rstb(data)                              (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_threshold(data)                     (0x7E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_debounce(data)                      (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_sel(data)                           (0x00030000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_auto(data)                          (0x00008000&((data)<<15))
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_adj(data)                           (0x00007800&((data)<<11))
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_error_limit(data)                      (0x000007C0&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_reserved(data)                      (0x0000003C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD56_get_p0_ck_md_rstb(data)                          ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD56_get_reg_p0_ck_md_threshold(data)                 ((0x7E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD56_get_reg_p0_ck_md_debounce(data)                  ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD56_get_reg_p0_ck_md_sel(data)                       ((0x00030000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD56_get_reg_p0_ck_md_auto(data)                      ((0x00008000&(data))>>15)
#define  DFE_HDMI_RX_PHY_REGD56_get_reg_p0_ck_md_adj(data)                       ((0x00007800&(data))>>11)
#define  DFE_HDMI_RX_PHY_REGD56_get_reg_p0_ck_error_limit(data)                  ((0x000007C0&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD56_get_reg_p0_ck_md_reserved(data)                  ((0x0000003C&(data))>>2)

#define  DFE_HDMI_RX_PHY_REGD57                                                  0x1800DC70
#define  DFE_HDMI_RX_PHY_REGD57_reg_addr                                         "0xB800DC70"
#define  DFE_HDMI_RX_PHY_REGD57_reg                                              0xB800DC70
#define  DFE_HDMI_RX_PHY_REGD57_inst_addr                                        "0x0090"
#define  set_DFE_HDMI_RX_PHY_REGD57_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD57_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD57_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD57_reg))
#define  DFE_HDMI_RX_PHY_REGD57_p0_ck_md_count_shift                             (19)
#define  DFE_HDMI_RX_PHY_REGD57_p0_ck_rate_shift                                 (15)
#define  DFE_HDMI_RX_PHY_REGD57_p0_unstable_count_shift                          (10)
#define  DFE_HDMI_RX_PHY_REGD57_p0_ck_md_ok_shift                                (9)
#define  DFE_HDMI_RX_PHY_REGD57_p0_clock_unstable_flag_shift                     (8)
#define  DFE_HDMI_RX_PHY_REGD57_p0_ck_md_count_mask                              (0xFFF80000)
#define  DFE_HDMI_RX_PHY_REGD57_p0_ck_rate_mask                                  (0x00078000)
#define  DFE_HDMI_RX_PHY_REGD57_p0_unstable_count_mask                           (0x00007C00)
#define  DFE_HDMI_RX_PHY_REGD57_p0_ck_md_ok_mask                                 (0x00000200)
#define  DFE_HDMI_RX_PHY_REGD57_p0_clock_unstable_flag_mask                      (0x00000100)
#define  DFE_HDMI_RX_PHY_REGD57_p0_ck_md_count(data)                             (0xFFF80000&((data)<<19))
#define  DFE_HDMI_RX_PHY_REGD57_p0_ck_rate(data)                                 (0x00078000&((data)<<15))
#define  DFE_HDMI_RX_PHY_REGD57_p0_unstable_count(data)                          (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD57_p0_ck_md_ok(data)                                (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_REGD57_p0_clock_unstable_flag(data)                     (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD57_get_p0_ck_md_count(data)                         ((0xFFF80000&(data))>>19)
#define  DFE_HDMI_RX_PHY_REGD57_get_p0_ck_rate(data)                             ((0x00078000&(data))>>15)
#define  DFE_HDMI_RX_PHY_REGD57_get_p0_unstable_count(data)                      ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD57_get_p0_ck_md_ok(data)                            ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_REGD57_get_p0_clock_unstable_flag(data)                 ((0x00000100&(data))>>8)

#define  DFE_HDMI_RX_PHY_REGD58                                                  0x1800DC74
#define  DFE_HDMI_RX_PHY_REGD58_reg_addr                                         "0xB800DC74"
#define  DFE_HDMI_RX_PHY_REGD58_reg                                              0xB800DC74
#define  DFE_HDMI_RX_PHY_REGD58_inst_addr                                        "0x0091"
#define  set_DFE_HDMI_RX_PHY_REGD58_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD58_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD58_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD58_reg))
#define  DFE_HDMI_RX_PHY_REGD58_p1_ck_md_rstb_shift                              (31)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_threshold_shift                     (25)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_debounce_shift                      (18)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_sel_shift                           (16)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_auto_shift                          (15)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_adj_shift                           (11)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_error_limit_shift                      (6)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_reserved_shift                      (2)
#define  DFE_HDMI_RX_PHY_REGD58_p1_ck_md_rstb_mask                               (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_threshold_mask                      (0x7E000000)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_debounce_mask                       (0x01FC0000)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_sel_mask                            (0x00030000)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_auto_mask                           (0x00008000)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_adj_mask                            (0x00007800)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_error_limit_mask                       (0x000007C0)
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_reserved_mask                       (0x0000003C)
#define  DFE_HDMI_RX_PHY_REGD58_p1_ck_md_rstb(data)                              (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_threshold(data)                     (0x7E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_debounce(data)                      (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_sel(data)                           (0x00030000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_auto(data)                          (0x00008000&((data)<<15))
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_adj(data)                           (0x00007800&((data)<<11))
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_error_limit(data)                      (0x000007C0&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD58_reg_p1_ck_md_reserved(data)                      (0x0000003C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD58_get_p1_ck_md_rstb(data)                          ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD58_get_reg_p1_ck_md_threshold(data)                 ((0x7E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD58_get_reg_p1_ck_md_debounce(data)                  ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD58_get_reg_p1_ck_md_sel(data)                       ((0x00030000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD58_get_reg_p1_ck_md_auto(data)                      ((0x00008000&(data))>>15)
#define  DFE_HDMI_RX_PHY_REGD58_get_reg_p1_ck_md_adj(data)                       ((0x00007800&(data))>>11)
#define  DFE_HDMI_RX_PHY_REGD58_get_reg_p1_ck_error_limit(data)                  ((0x000007C0&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD58_get_reg_p1_ck_md_reserved(data)                  ((0x0000003C&(data))>>2)

#define  DFE_HDMI_RX_PHY_REGD59                                                  0x1800DC78
#define  DFE_HDMI_RX_PHY_REGD59_reg_addr                                         "0xB800DC78"
#define  DFE_HDMI_RX_PHY_REGD59_reg                                              0xB800DC78
#define  DFE_HDMI_RX_PHY_REGD59_inst_addr                                        "0x0092"
#define  set_DFE_HDMI_RX_PHY_REGD59_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD59_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD59_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD59_reg))
#define  DFE_HDMI_RX_PHY_REGD59_p1_ck_md_count_shift                             (19)
#define  DFE_HDMI_RX_PHY_REGD59_p1_ck_rate_shift                                 (15)
#define  DFE_HDMI_RX_PHY_REGD59_p1_unstable_count_shift                          (10)
#define  DFE_HDMI_RX_PHY_REGD59_p1_ck_md_ok_shift                                (9)
#define  DFE_HDMI_RX_PHY_REGD59_p1_clock_unstable_flag_shift                     (8)
#define  DFE_HDMI_RX_PHY_REGD59_p1_ck_md_count_mask                              (0xFFF80000)
#define  DFE_HDMI_RX_PHY_REGD59_p1_ck_rate_mask                                  (0x00078000)
#define  DFE_HDMI_RX_PHY_REGD59_p1_unstable_count_mask                           (0x00007C00)
#define  DFE_HDMI_RX_PHY_REGD59_p1_ck_md_ok_mask                                 (0x00000200)
#define  DFE_HDMI_RX_PHY_REGD59_p1_clock_unstable_flag_mask                      (0x00000100)
#define  DFE_HDMI_RX_PHY_REGD59_p1_ck_md_count(data)                             (0xFFF80000&((data)<<19))
#define  DFE_HDMI_RX_PHY_REGD59_p1_ck_rate(data)                                 (0x00078000&((data)<<15))
#define  DFE_HDMI_RX_PHY_REGD59_p1_unstable_count(data)                          (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD59_p1_ck_md_ok(data)                                (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_REGD59_p1_clock_unstable_flag(data)                     (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD59_get_p1_ck_md_count(data)                         ((0xFFF80000&(data))>>19)
#define  DFE_HDMI_RX_PHY_REGD59_get_p1_ck_rate(data)                             ((0x00078000&(data))>>15)
#define  DFE_HDMI_RX_PHY_REGD59_get_p1_unstable_count(data)                      ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD59_get_p1_ck_md_ok(data)                            ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_REGD59_get_p1_clock_unstable_flag(data)                 ((0x00000100&(data))>>8)

#define  DFE_HDMI_RX_PHY_REGD60                                                  0x1800DC7C
#define  DFE_HDMI_RX_PHY_REGD60_reg_addr                                         "0xB800DC7C"
#define  DFE_HDMI_RX_PHY_REGD60_reg                                              0xB800DC7C
#define  DFE_HDMI_RX_PHY_REGD60_inst_addr                                        "0x0093"
#define  set_DFE_HDMI_RX_PHY_REGD60_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD60_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD60_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD60_reg))
#define  DFE_HDMI_RX_PHY_REGD60_p2_ck_md_rstb_shift                              (31)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_threshold_shift                     (25)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_debounce_shift                      (18)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_sel_shift                           (16)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_auto_shift                          (15)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_adj_shift                           (11)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_error_limit_shift                      (6)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_reserved_shift                      (2)
#define  DFE_HDMI_RX_PHY_REGD60_p2_ck_md_rstb_mask                               (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_threshold_mask                      (0x7E000000)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_debounce_mask                       (0x01FC0000)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_sel_mask                            (0x00030000)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_auto_mask                           (0x00008000)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_adj_mask                            (0x00007800)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_error_limit_mask                       (0x000007C0)
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_reserved_mask                       (0x0000003C)
#define  DFE_HDMI_RX_PHY_REGD60_p2_ck_md_rstb(data)                              (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_threshold(data)                     (0x7E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_debounce(data)                      (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_sel(data)                           (0x00030000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_auto(data)                          (0x00008000&((data)<<15))
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_adj(data)                           (0x00007800&((data)<<11))
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_error_limit(data)                      (0x000007C0&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD60_reg_p2_ck_md_reserved(data)                      (0x0000003C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD60_get_p2_ck_md_rstb(data)                          ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD60_get_reg_p2_ck_md_threshold(data)                 ((0x7E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD60_get_reg_p2_ck_md_debounce(data)                  ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD60_get_reg_p2_ck_md_sel(data)                       ((0x00030000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD60_get_reg_p2_ck_md_auto(data)                      ((0x00008000&(data))>>15)
#define  DFE_HDMI_RX_PHY_REGD60_get_reg_p2_ck_md_adj(data)                       ((0x00007800&(data))>>11)
#define  DFE_HDMI_RX_PHY_REGD60_get_reg_p2_ck_error_limit(data)                  ((0x000007C0&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD60_get_reg_p2_ck_md_reserved(data)                  ((0x0000003C&(data))>>2)

#define  DFE_HDMI_RX_PHY_REGD61                                                  0x1800DC80
#define  DFE_HDMI_RX_PHY_REGD61_reg_addr                                         "0xB800DC80"
#define  DFE_HDMI_RX_PHY_REGD61_reg                                              0xB800DC80
#define  DFE_HDMI_RX_PHY_REGD61_inst_addr                                        "0x0094"
#define  set_DFE_HDMI_RX_PHY_REGD61_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD61_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD61_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD61_reg))
#define  DFE_HDMI_RX_PHY_REGD61_p2_ck_md_count_shift                             (19)
#define  DFE_HDMI_RX_PHY_REGD61_p2_ck_rate_shift                                 (15)
#define  DFE_HDMI_RX_PHY_REGD61_p2_unstable_count_shift                          (10)
#define  DFE_HDMI_RX_PHY_REGD61_p2_ck_md_ok_shift                                (9)
#define  DFE_HDMI_RX_PHY_REGD61_p2_clock_unstable_flag_shift                     (8)
#define  DFE_HDMI_RX_PHY_REGD61_p2_ck_md_count_mask                              (0xFFF80000)
#define  DFE_HDMI_RX_PHY_REGD61_p2_ck_rate_mask                                  (0x00078000)
#define  DFE_HDMI_RX_PHY_REGD61_p2_unstable_count_mask                           (0x00007C00)
#define  DFE_HDMI_RX_PHY_REGD61_p2_ck_md_ok_mask                                 (0x00000200)
#define  DFE_HDMI_RX_PHY_REGD61_p2_clock_unstable_flag_mask                      (0x00000100)
#define  DFE_HDMI_RX_PHY_REGD61_p2_ck_md_count(data)                             (0xFFF80000&((data)<<19))
#define  DFE_HDMI_RX_PHY_REGD61_p2_ck_rate(data)                                 (0x00078000&((data)<<15))
#define  DFE_HDMI_RX_PHY_REGD61_p2_unstable_count(data)                          (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD61_p2_ck_md_ok(data)                                (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_REGD61_p2_clock_unstable_flag(data)                     (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD61_get_p2_ck_md_count(data)                         ((0xFFF80000&(data))>>19)
#define  DFE_HDMI_RX_PHY_REGD61_get_p2_ck_rate(data)                             ((0x00078000&(data))>>15)
#define  DFE_HDMI_RX_PHY_REGD61_get_p2_unstable_count(data)                      ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD61_get_p2_ck_md_ok(data)                            ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_REGD61_get_p2_clock_unstable_flag(data)                 ((0x00000100&(data))>>8)

#define  DFE_HDMI_RX_PHY_REGD62                                                  0x1800DC84
#define  DFE_HDMI_RX_PHY_REGD62_reg_addr                                         "0xB800DC84"
#define  DFE_HDMI_RX_PHY_REGD62_reg                                              0xB800DC84
#define  DFE_HDMI_RX_PHY_REGD62_inst_addr                                        "0x0095"
#define  set_DFE_HDMI_RX_PHY_REGD62_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD62_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD62_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD62_reg))
#define  DFE_HDMI_RX_PHY_REGD62_p3_ck_md_rstb_shift                              (31)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_threshold_shift                     (25)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_debounce_shift                      (18)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_sel_shift                           (16)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_auto_shift                          (15)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_adj_shift                           (11)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_error_limit_shift                      (6)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_reserved_shift                      (2)
#define  DFE_HDMI_RX_PHY_REGD62_p3_ck_md_rstb_mask                               (0x80000000)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_threshold_mask                      (0x7E000000)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_debounce_mask                       (0x01FC0000)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_sel_mask                            (0x00030000)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_auto_mask                           (0x00008000)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_adj_mask                            (0x00007800)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_error_limit_mask                       (0x000007C0)
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_reserved_mask                       (0x0000003C)
#define  DFE_HDMI_RX_PHY_REGD62_p3_ck_md_rstb(data)                              (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_threshold(data)                     (0x7E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_debounce(data)                      (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_sel(data)                           (0x00030000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_auto(data)                          (0x00008000&((data)<<15))
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_adj(data)                           (0x00007800&((data)<<11))
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_error_limit(data)                      (0x000007C0&((data)<<6))
#define  DFE_HDMI_RX_PHY_REGD62_reg_p3_ck_md_reserved(data)                      (0x0000003C&((data)<<2))
#define  DFE_HDMI_RX_PHY_REGD62_get_p3_ck_md_rstb(data)                          ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_REGD62_get_reg_p3_ck_md_threshold(data)                 ((0x7E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_REGD62_get_reg_p3_ck_md_debounce(data)                  ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD62_get_reg_p3_ck_md_sel(data)                       ((0x00030000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD62_get_reg_p3_ck_md_auto(data)                      ((0x00008000&(data))>>15)
#define  DFE_HDMI_RX_PHY_REGD62_get_reg_p3_ck_md_adj(data)                       ((0x00007800&(data))>>11)
#define  DFE_HDMI_RX_PHY_REGD62_get_reg_p3_ck_error_limit(data)                  ((0x000007C0&(data))>>6)
#define  DFE_HDMI_RX_PHY_REGD62_get_reg_p3_ck_md_reserved(data)                  ((0x0000003C&(data))>>2)

#define  DFE_HDMI_RX_PHY_REGD63                                                  0x1800DC88
#define  DFE_HDMI_RX_PHY_REGD63_reg_addr                                         "0xB800DC88"
#define  DFE_HDMI_RX_PHY_REGD63_reg                                              0xB800DC88
#define  DFE_HDMI_RX_PHY_REGD63_inst_addr                                        "0x0096"
#define  set_DFE_HDMI_RX_PHY_REGD63_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD63_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD63_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD63_reg))
#define  DFE_HDMI_RX_PHY_REGD63_p3_ck_md_count_shift                             (19)
#define  DFE_HDMI_RX_PHY_REGD63_p3_ck_rate_shift                                 (15)
#define  DFE_HDMI_RX_PHY_REGD63_p3_unstable_count_shift                          (10)
#define  DFE_HDMI_RX_PHY_REGD63_p3_ck_md_ok_shift                                (9)
#define  DFE_HDMI_RX_PHY_REGD63_p3_clock_unstable_flag_shift                     (8)
#define  DFE_HDMI_RX_PHY_REGD63_p3_ck_md_count_mask                              (0xFFF80000)
#define  DFE_HDMI_RX_PHY_REGD63_p3_ck_rate_mask                                  (0x00078000)
#define  DFE_HDMI_RX_PHY_REGD63_p3_unstable_count_mask                           (0x00007C00)
#define  DFE_HDMI_RX_PHY_REGD63_p3_ck_md_ok_mask                                 (0x00000200)
#define  DFE_HDMI_RX_PHY_REGD63_p3_clock_unstable_flag_mask                      (0x00000100)
#define  DFE_HDMI_RX_PHY_REGD63_p3_ck_md_count(data)                             (0xFFF80000&((data)<<19))
#define  DFE_HDMI_RX_PHY_REGD63_p3_ck_rate(data)                                 (0x00078000&((data)<<15))
#define  DFE_HDMI_RX_PHY_REGD63_p3_unstable_count(data)                          (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_REGD63_p3_ck_md_ok(data)                                (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_REGD63_p3_clock_unstable_flag(data)                     (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD63_get_p3_ck_md_count(data)                         ((0xFFF80000&(data))>>19)
#define  DFE_HDMI_RX_PHY_REGD63_get_p3_ck_rate(data)                             ((0x00078000&(data))>>15)
#define  DFE_HDMI_RX_PHY_REGD63_get_p3_unstable_count(data)                      ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_REGD63_get_p3_ck_md_ok(data)                            ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_REGD63_get_p3_clock_unstable_flag(data)                 ((0x00000100&(data))>>8)

#define  DFE_HDMI_RX_PHY_REGD64                                                  0x1800DC8C
#define  DFE_HDMI_RX_PHY_REGD64_reg_addr                                         "0xB800DC8C"
#define  DFE_HDMI_RX_PHY_REGD64_reg                                              0xB800DC8C
#define  DFE_HDMI_RX_PHY_REGD64_inst_addr                                        "0x0097"
#define  set_DFE_HDMI_RX_PHY_REGD64_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD64_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD64_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD64_reg))
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_0_shift                         (24)
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_1_shift                         (16)
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_2_shift                         (8)
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_3_shift                         (0)
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_0_mask                          (0xFF000000)
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_1_mask                          (0x00FF0000)
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_2_mask                          (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_3_mask                          (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_0(data)                         (0xFF000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_1(data)                         (0x00FF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_2(data)                         (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD64_reg_dig_reserved_3(data)                         (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD64_get_reg_dig_reserved_0(data)                     ((0xFF000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_REGD64_get_reg_dig_reserved_1(data)                     ((0x00FF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD64_get_reg_dig_reserved_2(data)                     ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD64_get_reg_dig_reserved_3(data)                     (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD65                                                  0x1800DC90
#define  DFE_HDMI_RX_PHY_REGD65_reg_addr                                         "0xB800DC90"
#define  DFE_HDMI_RX_PHY_REGD65_reg                                              0xB800DC90
#define  DFE_HDMI_RX_PHY_REGD65_inst_addr                                        "0x0098"
#define  set_DFE_HDMI_RX_PHY_REGD65_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD65_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD65_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD65_reg))
#define  DFE_HDMI_RX_PHY_REGD65_reg_dig_debug_sel_shift                          (27)
#define  DFE_HDMI_RX_PHY_REGD65_reg_dig_debug_sel_mask                           (0xF8000000)
#define  DFE_HDMI_RX_PHY_REGD65_reg_dig_debug_sel(data)                          (0xF8000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_REGD65_get_reg_dig_debug_sel(data)                      ((0xF8000000&(data))>>27)

#define  DFE_HDMI_RX_PHY_REGD66                                                  0x1800DC94
#define  DFE_HDMI_RX_PHY_REGD66_reg_addr                                         "0xB800DC94"
#define  DFE_HDMI_RX_PHY_REGD66_reg                                              0xB800DC94
#define  DFE_HDMI_RX_PHY_REGD66_inst_addr                                        "0x0099"
#define  set_DFE_HDMI_RX_PHY_REGD66_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD66_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD66_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD66_reg))
#define  DFE_HDMI_RX_PHY_REGD66_reg_p0_st_m_value_shift                          (0)
#define  DFE_HDMI_RX_PHY_REGD66_reg_p0_st_m_value_mask                           (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD66_reg_p0_st_m_value(data)                          (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD66_get_reg_p0_st_m_value(data)                      (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD67                                                  0x1800DC98
#define  DFE_HDMI_RX_PHY_REGD67_reg_addr                                         "0xB800DC98"
#define  DFE_HDMI_RX_PHY_REGD67_reg                                              0xB800DC98
#define  DFE_HDMI_RX_PHY_REGD67_inst_addr                                        "0x009A"
#define  set_DFE_HDMI_RX_PHY_REGD67_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD67_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD67_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD67_reg))
#define  DFE_HDMI_RX_PHY_REGD67_reg_p1_st_m_value_shift                          (0)
#define  DFE_HDMI_RX_PHY_REGD67_reg_p1_st_m_value_mask                           (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD67_reg_p1_st_m_value(data)                          (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD67_get_reg_p1_st_m_value(data)                      (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD68                                                  0x1800DC9C
#define  DFE_HDMI_RX_PHY_REGD68_reg_addr                                         "0xB800DC9C"
#define  DFE_HDMI_RX_PHY_REGD68_reg                                              0xB800DC9C
#define  DFE_HDMI_RX_PHY_REGD68_inst_addr                                        "0x009B"
#define  set_DFE_HDMI_RX_PHY_REGD68_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD68_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD68_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD68_reg))
#define  DFE_HDMI_RX_PHY_REGD68_reg_p2_st_m_value_shift                          (0)
#define  DFE_HDMI_RX_PHY_REGD68_reg_p2_st_m_value_mask                           (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD68_reg_p2_st_m_value(data)                          (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD68_get_reg_p2_st_m_value(data)                      (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD69                                                  0x1800DCA0
#define  DFE_HDMI_RX_PHY_REGD69_reg_addr                                         "0xB800DCA0"
#define  DFE_HDMI_RX_PHY_REGD69_reg                                              0xB800DCA0
#define  DFE_HDMI_RX_PHY_REGD69_inst_addr                                        "0x009C"
#define  set_DFE_HDMI_RX_PHY_REGD69_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD69_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD69_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD69_reg))
#define  DFE_HDMI_RX_PHY_REGD69_reg_p3_st_m_value_shift                          (0)
#define  DFE_HDMI_RX_PHY_REGD69_reg_p3_st_m_value_mask                           (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD69_reg_p3_st_m_value(data)                          (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD69_get_reg_p3_st_m_value(data)                      (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD70                                                  0x1800DCA4
#define  DFE_HDMI_RX_PHY_REGD70_reg_addr                                         "0xB800DCA4"
#define  DFE_HDMI_RX_PHY_REGD70_reg                                              0xB800DCA4
#define  DFE_HDMI_RX_PHY_REGD70_inst_addr                                        "0x009D"
#define  set_DFE_HDMI_RX_PHY_REGD70_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD70_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD70_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD70_reg))
#define  DFE_HDMI_RX_PHY_REGD70_reg_eye_monitor_ck_sel_shift                     (20)
#define  DFE_HDMI_RX_PHY_REGD70_eye_monitor_dout_shift                           (0)
#define  DFE_HDMI_RX_PHY_REGD70_reg_eye_monitor_ck_sel_mask                      (0x00300000)
#define  DFE_HDMI_RX_PHY_REGD70_eye_monitor_dout_mask                            (0x0000FFFF)
#define  DFE_HDMI_RX_PHY_REGD70_reg_eye_monitor_ck_sel(data)                     (0x00300000&((data)<<20))
#define  DFE_HDMI_RX_PHY_REGD70_eye_monitor_dout(data)                           (0x0000FFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD70_get_reg_eye_monitor_ck_sel(data)                 ((0x00300000&(data))>>20)
#define  DFE_HDMI_RX_PHY_REGD70_get_eye_monitor_dout(data)                       (0x0000FFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD71                                                  0x1800DCA8
#define  DFE_HDMI_RX_PHY_REGD71_reg_addr                                         "0xB800DCA8"
#define  DFE_HDMI_RX_PHY_REGD71_reg                                              0xB800DCA8
#define  DFE_HDMI_RX_PHY_REGD71_inst_addr                                        "0x009E"
#define  set_DFE_HDMI_RX_PHY_REGD71_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD71_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD71_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD71_reg))
#define  DFE_HDMI_RX_PHY_REGD71_reg_p0_st_m_value_g_shift                        (0)
#define  DFE_HDMI_RX_PHY_REGD71_reg_p0_st_m_value_g_mask                         (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD71_reg_p0_st_m_value_g(data)                        (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD71_get_reg_p0_st_m_value_g(data)                    (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD72                                                  0x1800DCAC
#define  DFE_HDMI_RX_PHY_REGD72_reg_addr                                         "0xB800DCAC"
#define  DFE_HDMI_RX_PHY_REGD72_reg                                              0xB800DCAC
#define  DFE_HDMI_RX_PHY_REGD72_inst_addr                                        "0x009F"
#define  set_DFE_HDMI_RX_PHY_REGD72_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD72_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD72_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD72_reg))
#define  DFE_HDMI_RX_PHY_REGD72_reg_p1_st_m_value_g_shift                        (0)
#define  DFE_HDMI_RX_PHY_REGD72_reg_p1_st_m_value_g_mask                         (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD72_reg_p1_st_m_value_g(data)                        (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD72_get_reg_p1_st_m_value_g(data)                    (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD73                                                  0x1800DCB0
#define  DFE_HDMI_RX_PHY_REGD73_reg_addr                                         "0xB800DCB0"
#define  DFE_HDMI_RX_PHY_REGD73_reg                                              0xB800DCB0
#define  DFE_HDMI_RX_PHY_REGD73_inst_addr                                        "0x00A0"
#define  set_DFE_HDMI_RX_PHY_REGD73_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD73_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD73_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD73_reg))
#define  DFE_HDMI_RX_PHY_REGD73_reg_p2_st_m_value_g_shift                        (0)
#define  DFE_HDMI_RX_PHY_REGD73_reg_p2_st_m_value_g_mask                         (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD73_reg_p2_st_m_value_g(data)                        (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD73_get_reg_p2_st_m_value_g(data)                    (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD74                                                  0x1800DCB4
#define  DFE_HDMI_RX_PHY_REGD74_reg_addr                                         "0xB800DCB4"
#define  DFE_HDMI_RX_PHY_REGD74_reg                                              0xB800DCB4
#define  DFE_HDMI_RX_PHY_REGD74_inst_addr                                        "0x00A1"
#define  set_DFE_HDMI_RX_PHY_REGD74_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD74_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD74_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD74_reg))
#define  DFE_HDMI_RX_PHY_REGD74_reg_p3_st_m_value_g_shift                        (0)
#define  DFE_HDMI_RX_PHY_REGD74_reg_p3_st_m_value_g_mask                         (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD74_reg_p3_st_m_value_g(data)                        (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD74_get_reg_p3_st_m_value_g(data)                    (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD75                                                  0x1800DCB8
#define  DFE_HDMI_RX_PHY_REGD75_reg_addr                                         "0xB800DCB8"
#define  DFE_HDMI_RX_PHY_REGD75_reg                                              0xB800DCB8
#define  DFE_HDMI_RX_PHY_REGD75_inst_addr                                        "0x00A2"
#define  set_DFE_HDMI_RX_PHY_REGD75_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD75_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD75_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD75_reg))
#define  DFE_HDMI_RX_PHY_REGD75_reg_p0_st_m_value_b_shift                        (0)
#define  DFE_HDMI_RX_PHY_REGD75_reg_p0_st_m_value_b_mask                         (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD75_reg_p0_st_m_value_b(data)                        (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD75_get_reg_p0_st_m_value_b(data)                    (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD76                                                  0x1800DCBC
#define  DFE_HDMI_RX_PHY_REGD76_reg_addr                                         "0xB800DCBC"
#define  DFE_HDMI_RX_PHY_REGD76_reg                                              0xB800DCBC
#define  DFE_HDMI_RX_PHY_REGD76_inst_addr                                        "0x00A3"
#define  set_DFE_HDMI_RX_PHY_REGD76_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD76_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD76_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD76_reg))
#define  DFE_HDMI_RX_PHY_REGD76_reg_p1_st_m_value_b_shift                        (0)
#define  DFE_HDMI_RX_PHY_REGD76_reg_p1_st_m_value_b_mask                         (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD76_reg_p1_st_m_value_b(data)                        (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD76_get_reg_p1_st_m_value_b(data)                    (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD77                                                  0x1800DCC0
#define  DFE_HDMI_RX_PHY_REGD77_reg_addr                                         "0xB800DCC0"
#define  DFE_HDMI_RX_PHY_REGD77_reg                                              0xB800DCC0
#define  DFE_HDMI_RX_PHY_REGD77_inst_addr                                        "0x00A4"
#define  set_DFE_HDMI_RX_PHY_REGD77_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD77_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD77_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD77_reg))
#define  DFE_HDMI_RX_PHY_REGD77_reg_p2_st_m_value_b_shift                        (0)
#define  DFE_HDMI_RX_PHY_REGD77_reg_p2_st_m_value_b_mask                         (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD77_reg_p2_st_m_value_b(data)                        (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD77_get_reg_p2_st_m_value_b(data)                    (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD78                                                  0x1800DCC4
#define  DFE_HDMI_RX_PHY_REGD78_reg_addr                                         "0xB800DCC4"
#define  DFE_HDMI_RX_PHY_REGD78_reg                                              0xB800DCC4
#define  DFE_HDMI_RX_PHY_REGD78_inst_addr                                        "0x00A5"
#define  set_DFE_HDMI_RX_PHY_REGD78_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD78_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD78_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD78_reg))
#define  DFE_HDMI_RX_PHY_REGD78_reg_p3_st_m_value_b_shift                        (0)
#define  DFE_HDMI_RX_PHY_REGD78_reg_p3_st_m_value_b_mask                         (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_REGD78_reg_p3_st_m_value_b(data)                        (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_REGD78_get_reg_p3_st_m_value_b(data)                    (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_REGD79                                                  0x1800DCC8
#define  DFE_HDMI_RX_PHY_REGD79_reg_addr                                         "0xB800DCC8"
#define  DFE_HDMI_RX_PHY_REGD79_reg                                              0xB800DCC8
#define  DFE_HDMI_RX_PHY_REGD79_inst_addr                                        "0x00A6"
#define  set_DFE_HDMI_RX_PHY_REGD79_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD79_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD79_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD79_reg))
#define  DFE_HDMI_RX_PHY_REGD79_reg_p0_enable_one_zero_r_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD79_reg_p0_prbs_invs_r_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD79_reg_p0_pattern_sel_r_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD79_p0_pkt_count_r_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD79_p0_err_count_r_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD79_reg_p0_enable_one_zero_r_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD79_reg_p0_prbs_invs_r_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD79_reg_p0_pattern_sel_r_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD79_p0_pkt_count_r_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD79_p0_err_count_r_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD79_reg_p0_enable_one_zero_r(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD79_reg_p0_prbs_invs_r(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD79_reg_p0_pattern_sel_r(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD79_p0_pkt_count_r(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD79_p0_err_count_r(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD79_get_reg_p0_enable_one_zero_r(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD79_get_reg_p0_prbs_invs_r(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD79_get_reg_p0_pattern_sel_r(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD79_get_p0_pkt_count_r(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD79_get_p0_err_count_r(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD80                                                  0x1800DCCC
#define  DFE_HDMI_RX_PHY_REGD80_reg_addr                                         "0xB800DCCC"
#define  DFE_HDMI_RX_PHY_REGD80_reg                                              0xB800DCCC
#define  DFE_HDMI_RX_PHY_REGD80_inst_addr                                        "0x00A7"
#define  set_DFE_HDMI_RX_PHY_REGD80_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD80_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD80_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD80_reg))
#define  DFE_HDMI_RX_PHY_REGD80_reg_p0_enable_one_zero_g_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD80_reg_p0_prbs_invs_g_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD80_reg_p0_pattern_sel_g_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD80_p0_pkt_count_g_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD80_p0_err_count_g_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD80_reg_p0_enable_one_zero_g_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD80_reg_p0_prbs_invs_g_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD80_reg_p0_pattern_sel_g_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD80_p0_pkt_count_g_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD80_p0_err_count_g_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD80_reg_p0_enable_one_zero_g(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD80_reg_p0_prbs_invs_g(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD80_reg_p0_pattern_sel_g(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD80_p0_pkt_count_g(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD80_p0_err_count_g(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD80_get_reg_p0_enable_one_zero_g(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD80_get_reg_p0_prbs_invs_g(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD80_get_reg_p0_pattern_sel_g(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD80_get_p0_pkt_count_g(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD80_get_p0_err_count_g(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD81                                                  0x1800DCD0
#define  DFE_HDMI_RX_PHY_REGD81_reg_addr                                         "0xB800DCD0"
#define  DFE_HDMI_RX_PHY_REGD81_reg                                              0xB800DCD0
#define  DFE_HDMI_RX_PHY_REGD81_inst_addr                                        "0x00A8"
#define  set_DFE_HDMI_RX_PHY_REGD81_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD81_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD81_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD81_reg))
#define  DFE_HDMI_RX_PHY_REGD81_reg_p0_enable_one_zero_b_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD81_reg_p0_prbs_invs_b_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD81_reg_p0_pattern_sel_b_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD81_p0_pkt_count_b_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD81_p0_err_count_b_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD81_reg_p0_enable_one_zero_b_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD81_reg_p0_prbs_invs_b_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD81_reg_p0_pattern_sel_b_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD81_p0_pkt_count_b_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD81_p0_err_count_b_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD81_reg_p0_enable_one_zero_b(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD81_reg_p0_prbs_invs_b(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD81_reg_p0_pattern_sel_b(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD81_p0_pkt_count_b(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD81_p0_err_count_b(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD81_get_reg_p0_enable_one_zero_b(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD81_get_reg_p0_prbs_invs_b(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD81_get_reg_p0_pattern_sel_b(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD81_get_p0_pkt_count_b(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD81_get_p0_err_count_b(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD82                                                  0x1800DCD4
#define  DFE_HDMI_RX_PHY_REGD82_reg_addr                                         "0xB800DCD4"
#define  DFE_HDMI_RX_PHY_REGD82_reg                                              0xB800DCD4
#define  DFE_HDMI_RX_PHY_REGD82_inst_addr                                        "0x00A9"
#define  set_DFE_HDMI_RX_PHY_REGD82_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD82_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD82_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD82_reg))
#define  DFE_HDMI_RX_PHY_REGD82_reg_p1_enable_one_zero_r_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD82_reg_p1_prbs_invs_r_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD82_reg_p1_pattern_sel_r_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD82_p1_pkt_count_r_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD82_p1_err_count_r_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD82_reg_p1_enable_one_zero_r_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD82_reg_p1_prbs_invs_r_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD82_reg_p1_pattern_sel_r_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD82_p1_pkt_count_r_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD82_p1_err_count_r_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD82_reg_p1_enable_one_zero_r(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD82_reg_p1_prbs_invs_r(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD82_reg_p1_pattern_sel_r(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD82_p1_pkt_count_r(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD82_p1_err_count_r(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD82_get_reg_p1_enable_one_zero_r(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD82_get_reg_p1_prbs_invs_r(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD82_get_reg_p1_pattern_sel_r(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD82_get_p1_pkt_count_r(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD82_get_p1_err_count_r(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD83                                                  0x1800DCD8
#define  DFE_HDMI_RX_PHY_REGD83_reg_addr                                         "0xB800DCD8"
#define  DFE_HDMI_RX_PHY_REGD83_reg                                              0xB800DCD8
#define  DFE_HDMI_RX_PHY_REGD83_inst_addr                                        "0x00AA"
#define  set_DFE_HDMI_RX_PHY_REGD83_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD83_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD83_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD83_reg))
#define  DFE_HDMI_RX_PHY_REGD83_reg_p1_enable_one_zero_g_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD83_reg_p1_prbs_invs_g_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD83_reg_p1_pattern_sel_g_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD83_p1_pkt_count_g_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD83_p1_err_count_g_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD83_reg_p1_enable_one_zero_g_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD83_reg_p1_prbs_invs_g_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD83_reg_p1_pattern_sel_g_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD83_p1_pkt_count_g_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD83_p1_err_count_g_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD83_reg_p1_enable_one_zero_g(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD83_reg_p1_prbs_invs_g(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD83_reg_p1_pattern_sel_g(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD83_p1_pkt_count_g(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD83_p1_err_count_g(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD83_get_reg_p1_enable_one_zero_g(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD83_get_reg_p1_prbs_invs_g(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD83_get_reg_p1_pattern_sel_g(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD83_get_p1_pkt_count_g(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD83_get_p1_err_count_g(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD84                                                  0x1800DCDC
#define  DFE_HDMI_RX_PHY_REGD84_reg_addr                                         "0xB800DCDC"
#define  DFE_HDMI_RX_PHY_REGD84_reg                                              0xB800DCDC
#define  DFE_HDMI_RX_PHY_REGD84_inst_addr                                        "0x00AB"
#define  set_DFE_HDMI_RX_PHY_REGD84_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD84_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD84_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD84_reg))
#define  DFE_HDMI_RX_PHY_REGD84_reg_p1_enable_one_zero_b_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD84_reg_p1_prbs_invs_b_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD84_reg_p1_pattern_sel_b_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD84_p1_pkt_count_b_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD84_p1_err_count_b_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD84_reg_p1_enable_one_zero_b_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD84_reg_p1_prbs_invs_b_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD84_reg_p1_pattern_sel_b_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD84_p1_pkt_count_b_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD84_p1_err_count_b_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD84_reg_p1_enable_one_zero_b(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD84_reg_p1_prbs_invs_b(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD84_reg_p1_pattern_sel_b(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD84_p1_pkt_count_b(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD84_p1_err_count_b(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD84_get_reg_p1_enable_one_zero_b(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD84_get_reg_p1_prbs_invs_b(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD84_get_reg_p1_pattern_sel_b(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD84_get_p1_pkt_count_b(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD84_get_p1_err_count_b(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD85                                                  0x1800DCE0
#define  DFE_HDMI_RX_PHY_REGD85_reg_addr                                         "0xB800DCE0"
#define  DFE_HDMI_RX_PHY_REGD85_reg                                              0xB800DCE0
#define  DFE_HDMI_RX_PHY_REGD85_inst_addr                                        "0x00AC"
#define  set_DFE_HDMI_RX_PHY_REGD85_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD85_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD85_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD85_reg))
#define  DFE_HDMI_RX_PHY_REGD85_reg_p2_enable_one_zero_r_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD85_reg_p2_prbs_invs_r_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD85_reg_p2_pattern_sel_r_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD85_p2_pkt_count_r_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD85_p2_err_count_r_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD85_reg_p2_enable_one_zero_r_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD85_reg_p2_prbs_invs_r_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD85_reg_p2_pattern_sel_r_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD85_p2_pkt_count_r_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD85_p2_err_count_r_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD85_reg_p2_enable_one_zero_r(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD85_reg_p2_prbs_invs_r(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD85_reg_p2_pattern_sel_r(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD85_p2_pkt_count_r(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD85_p2_err_count_r(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD85_get_reg_p2_enable_one_zero_r(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD85_get_reg_p2_prbs_invs_r(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD85_get_reg_p2_pattern_sel_r(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD85_get_p2_pkt_count_r(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD85_get_p2_err_count_r(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD86                                                  0x1800DCE4
#define  DFE_HDMI_RX_PHY_REGD86_reg_addr                                         "0xB800DCE4"
#define  DFE_HDMI_RX_PHY_REGD86_reg                                              0xB800DCE4
#define  DFE_HDMI_RX_PHY_REGD86_inst_addr                                        "0x00AD"
#define  set_DFE_HDMI_RX_PHY_REGD86_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD86_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD86_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD86_reg))
#define  DFE_HDMI_RX_PHY_REGD86_reg_p2_enable_one_zero_g_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD86_reg_p2_prbs_invs_g_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD86_reg_p2_pattern_sel_g_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD86_p2_pkt_count_g_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD86_p2_err_count_g_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD86_reg_p2_enable_one_zero_g_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD86_reg_p2_prbs_invs_g_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD86_reg_p2_pattern_sel_g_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD86_p2_pkt_count_g_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD86_p2_err_count_g_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD86_reg_p2_enable_one_zero_g(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD86_reg_p2_prbs_invs_g(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD86_reg_p2_pattern_sel_g(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD86_p2_pkt_count_g(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD86_p2_err_count_g(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD86_get_reg_p2_enable_one_zero_g(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD86_get_reg_p2_prbs_invs_g(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD86_get_reg_p2_pattern_sel_g(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD86_get_p2_pkt_count_g(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD86_get_p2_err_count_g(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD87                                                  0x1800DCE8
#define  DFE_HDMI_RX_PHY_REGD87_reg_addr                                         "0xB800DCE8"
#define  DFE_HDMI_RX_PHY_REGD87_reg                                              0xB800DCE8
#define  DFE_HDMI_RX_PHY_REGD87_inst_addr                                        "0x00AE"
#define  set_DFE_HDMI_RX_PHY_REGD87_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD87_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD87_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD87_reg))
#define  DFE_HDMI_RX_PHY_REGD87_reg_p2_enable_one_zero_b_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD87_reg_p2_prbs_invs_b_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD87_reg_p2_pattern_sel_b_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD87_p2_pkt_count_b_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD87_p2_err_count_b_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD87_reg_p2_enable_one_zero_b_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD87_reg_p2_prbs_invs_b_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD87_reg_p2_pattern_sel_b_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD87_p2_pkt_count_b_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD87_p2_err_count_b_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD87_reg_p2_enable_one_zero_b(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD87_reg_p2_prbs_invs_b(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD87_reg_p2_pattern_sel_b(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD87_p2_pkt_count_b(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD87_p2_err_count_b(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD87_get_reg_p2_enable_one_zero_b(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD87_get_reg_p2_prbs_invs_b(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD87_get_reg_p2_pattern_sel_b(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD87_get_p2_pkt_count_b(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD87_get_p2_err_count_b(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD88                                                  0x1800DCEC
#define  DFE_HDMI_RX_PHY_REGD88_reg_addr                                         "0xB800DCEC"
#define  DFE_HDMI_RX_PHY_REGD88_reg                                              0xB800DCEC
#define  DFE_HDMI_RX_PHY_REGD88_inst_addr                                        "0x00AF"
#define  set_DFE_HDMI_RX_PHY_REGD88_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD88_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD88_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD88_reg))
#define  DFE_HDMI_RX_PHY_REGD88_reg_p3_enable_one_zero_r_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD88_reg_p3_prbs_invs_r_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD88_reg_p3_pattern_sel_r_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD88_p3_pkt_count_r_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD88_p3_err_count_r_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD88_reg_p3_enable_one_zero_r_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD88_reg_p3_prbs_invs_r_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD88_reg_p3_pattern_sel_r_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD88_p3_pkt_count_r_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD88_p3_err_count_r_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD88_reg_p3_enable_one_zero_r(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD88_reg_p3_prbs_invs_r(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD88_reg_p3_pattern_sel_r(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD88_p3_pkt_count_r(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD88_p3_err_count_r(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD88_get_reg_p3_enable_one_zero_r(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD88_get_reg_p3_prbs_invs_r(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD88_get_reg_p3_pattern_sel_r(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD88_get_p3_pkt_count_r(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD88_get_p3_err_count_r(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD89                                                  0x1800DCF0
#define  DFE_HDMI_RX_PHY_REGD89_reg_addr                                         "0xB800DCF0"
#define  DFE_HDMI_RX_PHY_REGD89_reg                                              0xB800DCF0
#define  DFE_HDMI_RX_PHY_REGD89_inst_addr                                        "0x00B0"
#define  set_DFE_HDMI_RX_PHY_REGD89_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD89_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD89_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD89_reg))
#define  DFE_HDMI_RX_PHY_REGD89_reg_p3_enable_one_zero_g_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD89_reg_p3_prbs_invs_g_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD89_reg_p3_pattern_sel_g_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD89_p3_pkt_count_g_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD89_p3_err_count_g_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD89_reg_p3_enable_one_zero_g_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD89_reg_p3_prbs_invs_g_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD89_reg_p3_pattern_sel_g_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD89_p3_pkt_count_g_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD89_p3_err_count_g_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD89_reg_p3_enable_one_zero_g(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD89_reg_p3_prbs_invs_g(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD89_reg_p3_pattern_sel_g(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD89_p3_pkt_count_g(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD89_p3_err_count_g(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD89_get_reg_p3_enable_one_zero_g(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD89_get_reg_p3_prbs_invs_g(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD89_get_reg_p3_pattern_sel_g(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD89_get_p3_pkt_count_g(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD89_get_p3_err_count_g(data)                         (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_REGD90                                                  0x1800DCF4
#define  DFE_HDMI_RX_PHY_REGD90_reg_addr                                         "0xB800DCF4"
#define  DFE_HDMI_RX_PHY_REGD90_reg                                              0xB800DCF4
#define  DFE_HDMI_RX_PHY_REGD90_inst_addr                                        "0x00B1"
#define  set_DFE_HDMI_RX_PHY_REGD90_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD90_reg)=data)
#define  get_DFE_HDMI_RX_PHY_REGD90_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_REGD90_reg))
#define  DFE_HDMI_RX_PHY_REGD90_reg_p3_enable_one_zero_b_shift                   (18)
#define  DFE_HDMI_RX_PHY_REGD90_reg_p3_prbs_invs_b_shift                         (17)
#define  DFE_HDMI_RX_PHY_REGD90_reg_p3_pattern_sel_b_shift                       (16)
#define  DFE_HDMI_RX_PHY_REGD90_p3_pkt_count_b_shift                             (8)
#define  DFE_HDMI_RX_PHY_REGD90_p3_err_count_b_shift                             (0)
#define  DFE_HDMI_RX_PHY_REGD90_reg_p3_enable_one_zero_b_mask                    (0x00040000)
#define  DFE_HDMI_RX_PHY_REGD90_reg_p3_prbs_invs_b_mask                          (0x00020000)
#define  DFE_HDMI_RX_PHY_REGD90_reg_p3_pattern_sel_b_mask                        (0x00010000)
#define  DFE_HDMI_RX_PHY_REGD90_p3_pkt_count_b_mask                              (0x0000FF00)
#define  DFE_HDMI_RX_PHY_REGD90_p3_err_count_b_mask                              (0x000000FF)
#define  DFE_HDMI_RX_PHY_REGD90_reg_p3_enable_one_zero_b(data)                   (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_REGD90_reg_p3_prbs_invs_b(data)                         (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_REGD90_reg_p3_pattern_sel_b(data)                       (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_REGD90_p3_pkt_count_b(data)                             (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_REGD90_p3_err_count_b(data)                             (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_REGD90_get_reg_p3_enable_one_zero_b(data)               ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_REGD90_get_reg_p3_prbs_invs_b(data)                     ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_REGD90_get_reg_p3_pattern_sel_b(data)                   ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_REGD90_get_p3_pkt_count_b(data)                         ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_REGD90_get_p3_err_count_b(data)                         (0x000000FF&(data))

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
        RBus_UInt32  reg_ck_ckdet:4;
    };
}dfe_hdmi_rx_phy_md_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_ldo_mossel:3;
        RBus_UInt32  reg_p3_ldo_sel:2;
        RBus_UInt32  reg_p2_ldo_sel:2;
        RBus_UInt32  reg_p1_ldo_sel:2;
        RBus_UInt32  reg_p0_ldo_sel:2;
        RBus_UInt32  reg_p3_ldo_pow:1;
        RBus_UInt32  reg_p2_ldo_pow:1;
        RBus_UInt32  reg_p1_ldo_pow:1;
        RBus_UInt32  reg_p0_ldo_pow:1;
    };
}dfe_hdmi_rx_phy_ldo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  reg_p3_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p3_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p3_mhl_pow:1;
        RBus_UInt32  reg_p2_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p2_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p2_mhl_pow:1;
        RBus_UInt32  reg_p1_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p1_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p1_mhl_pow:1;
        RBus_UInt32  reg_p0_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p0_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p0_mhl_pow:1;
        RBus_UInt32  reg_mhl_hdmisel:1;
    };
}dfe_hdmi_rx_phy_mhl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_p3_en_rx:3;
        RBus_UInt32  reg_p3_en_cmu:1;
        RBus_UInt32  reg_p3_en_cdr:3;
        RBus_UInt32  reg_p2_en_rx:3;
        RBus_UInt32  reg_p2_en_cmu:1;
        RBus_UInt32  reg_p2_en_cdr:3;
        RBus_UInt32  reg_p1_en_rx:3;
        RBus_UInt32  reg_p1_en_cmu:1;
        RBus_UInt32  reg_p1_en_cdr:3;
        RBus_UInt32  reg_p0_en_rx:3;
        RBus_UInt32  reg_p0_en_cmu:1;
        RBus_UInt32  reg_p0_en_cdr:3;
    };
}dfe_hdmi_rx_phy_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  reg_tst_spad:1;
        RBus_UInt32  reg_stst:4;
    };
}dfe_hdmi_rx_phy_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_top_in_4:8;
        RBus_UInt32  reg_top_in_3:8;
        RBus_UInt32  reg_top_in_2:8;
        RBus_UInt32  reg_top_in_1:8;
    };
}dfe_hdmi_rx_phy_top_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_top_out_4:8;
        RBus_UInt32  reg_top_out_3:8;
        RBus_UInt32  reg_top_out_2:8;
        RBus_UInt32  reg_top_out_1:8;
    };
}dfe_hdmi_rx_phy_top_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_z0_z300_sel:4;
        RBus_UInt32  reg_z0_z300pow:4;
        RBus_UInt32  reg_z0_z100_en:4;
        RBus_UInt32  reg_z0_z0pow_r:4;
        RBus_UInt32  reg_z0_z0pow_g:4;
        RBus_UInt32  reg_z0_z0pow_ck:4;
        RBus_UInt32  reg_z0_z0pow_b:4;
    };
}dfe_hdmi_rx_phy_z0pow_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_z0_z0pow:1;
        RBus_UInt32  reg_z0_stune:1;
        RBus_UInt32  reg_z0_res:5;
        RBus_UInt32  reg_z0_ok:1;
        RBus_UInt32  reg_z0_entst:1;
        RBus_UInt32  reg_z0_bound:1;
        RBus_UInt32  reg_z0_adjr_2:5;
        RBus_UInt32  reg_z0_adjr_1:5;
        RBus_UInt32  reg_z0_adjr_0:5;
        RBus_UInt32  reg_z0tst:4;
    };
}dfe_hdmi_rx_phy_z0k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  reg_z0_adjr_3:5;
    };
}dfe_hdmi_rx_phy_z0k_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_acdr_4:8;
        RBus_UInt32  reg_p0_acdr_3:8;
        RBus_UInt32  reg_p0_acdr_2:8;
        RBus_UInt32  reg_p0_acdr_1:8;
    };
}dfe_hdmi_rx_phy_p0_acdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_acdr_8:8;
        RBus_UInt32  reg_p0_acdr_7:8;
        RBus_UInt32  reg_p0_acdr_6:8;
        RBus_UInt32  reg_p0_acdr_5:8;
    };
}dfe_hdmi_rx_phy_p0_acdr2_RBUS;

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
        RBus_UInt32  reg_p1_acdr_4:8;
        RBus_UInt32  reg_p1_acdr_3:8;
        RBus_UInt32  reg_p1_acdr_2:8;
        RBus_UInt32  reg_p1_acdr_1:8;
    };
}dfe_hdmi_rx_phy_p1_acdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_acdr_8:8;
        RBus_UInt32  reg_p1_acdr_7:8;
        RBus_UInt32  reg_p1_acdr_6:8;
        RBus_UInt32  reg_p1_acdr_5:8;
    };
}dfe_hdmi_rx_phy_p1_acdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_b_4:8;
        RBus_UInt32  reg_p1_b_3:8;
        RBus_UInt32  reg_p1_b_2:8;
        RBus_UInt32  reg_p1_b_1:8;
    };
}dfe_hdmi_rx_phy_p1_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_b_8:8;
        RBus_UInt32  reg_p1_b_7:8;
        RBus_UInt32  reg_p1_b_6:8;
        RBus_UInt32  reg_p1_b_5:8;
    };
}dfe_hdmi_rx_phy_p1_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_b_12:8;
        RBus_UInt32  reg_p1_b_11:8;
        RBus_UInt32  reg_p1_b_10:8;
        RBus_UInt32  reg_p1_b_9:8;
    };
}dfe_hdmi_rx_phy_p1_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p1_b_koff_sel:5;
        RBus_UInt32  reg_p1_b_koff_bound:1;
        RBus_UInt32  reg_p1_b_koffok:1;
        RBus_UInt32  reg_p1_b_13:8;
    };
}dfe_hdmi_rx_phy_p1_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_ck_4:8;
        RBus_UInt32  reg_p1_ck_3:8;
        RBus_UInt32  reg_p1_ck_2:8;
        RBus_UInt32  reg_p1_ck_1:8;
    };
}dfe_hdmi_rx_phy_p1_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_ck_8:8;
        RBus_UInt32  reg_p1_ck_7:8;
        RBus_UInt32  reg_p1_ck_6:8;
        RBus_UInt32  reg_p1_ck_5:8;
    };
}dfe_hdmi_rx_phy_p1_ck2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_ck_12:8;
        RBus_UInt32  reg_p1_ck_11:8;
        RBus_UInt32  reg_p1_ck_10:8;
        RBus_UInt32  reg_p1_ck_9:8;
    };
}dfe_hdmi_rx_phy_p1_ck3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_p1_ck_13:8;
    };
}dfe_hdmi_rx_phy_p1_ck4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_g_4:8;
        RBus_UInt32  reg_p1_g_3:8;
        RBus_UInt32  reg_p1_g_2:8;
        RBus_UInt32  reg_p1_g_1:8;
    };
}dfe_hdmi_rx_phy_p1_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_g_8:8;
        RBus_UInt32  reg_p1_g_7:8;
        RBus_UInt32  reg_p1_g_6:8;
        RBus_UInt32  reg_p1_g_5:8;
    };
}dfe_hdmi_rx_phy_p1_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_g_12:8;
        RBus_UInt32  reg_p1_g_11:8;
        RBus_UInt32  reg_p1_g_10:8;
        RBus_UInt32  reg_p1_g_9:8;
    };
}dfe_hdmi_rx_phy_p1_g3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p1_g_koff_sel:5;
        RBus_UInt32  reg_p1_g_koff_bound:1;
        RBus_UInt32  reg_p1_g_koffok:1;
        RBus_UInt32  reg_p1_g_13:8;
    };
}dfe_hdmi_rx_phy_p1_g4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_r_4:8;
        RBus_UInt32  reg_p1_r_3:8;
        RBus_UInt32  reg_p1_r_2:8;
        RBus_UInt32  reg_p1_r_1:8;
    };
}dfe_hdmi_rx_phy_p1_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_r_8:8;
        RBus_UInt32  reg_p1_r_7:8;
        RBus_UInt32  reg_p1_r_6:8;
        RBus_UInt32  reg_p1_r_5:8;
    };
}dfe_hdmi_rx_phy_p1_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_r_12:8;
        RBus_UInt32  reg_p1_r_11:8;
        RBus_UInt32  reg_p1_r_10:8;
        RBus_UInt32  reg_p1_r_9:8;
    };
}dfe_hdmi_rx_phy_p1_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p1_r_koff_sel:5;
        RBus_UInt32  reg_p1_r_koff_bound:1;
        RBus_UInt32  reg_p1_r_koffok:1;
        RBus_UInt32  reg_p1_r_13:8;
    };
}dfe_hdmi_rx_phy_p1_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_acdr_4:8;
        RBus_UInt32  reg_p2_acdr_3:8;
        RBus_UInt32  reg_p2_acdr_2:8;
        RBus_UInt32  reg_p2_acdr_1:8;
    };
}dfe_hdmi_rx_phy_p2_acdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_acdr_8:8;
        RBus_UInt32  reg_p2_acdr_7:8;
        RBus_UInt32  reg_p2_acdr_6:8;
        RBus_UInt32  reg_p2_acdr_5:8;
    };
}dfe_hdmi_rx_phy_p2_acdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_b_4:8;
        RBus_UInt32  reg_p2_b_3:8;
        RBus_UInt32  reg_p2_b_2:8;
        RBus_UInt32  reg_p2_b_1:8;
    };
}dfe_hdmi_rx_phy_p2_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_b_8:8;
        RBus_UInt32  reg_p2_b_7:8;
        RBus_UInt32  reg_p2_b_6:8;
        RBus_UInt32  reg_p2_b_5:8;
    };
}dfe_hdmi_rx_phy_p2_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_b_12:8;
        RBus_UInt32  reg_p2_b_11:8;
        RBus_UInt32  reg_p2_b_10:8;
        RBus_UInt32  reg_p2_b_9:8;
    };
}dfe_hdmi_rx_phy_p2_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p2_b_koff_sel:5;
        RBus_UInt32  reg_p2_b_koff_bound:1;
        RBus_UInt32  reg_p2_b_koffok:1;
        RBus_UInt32  reg_p2_b_13:8;
    };
}dfe_hdmi_rx_phy_p2_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_ck_4:8;
        RBus_UInt32  reg_p2_ck_3:8;
        RBus_UInt32  reg_p2_ck_2:8;
        RBus_UInt32  reg_p2_ck_1:8;
    };
}dfe_hdmi_rx_phy_p2_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_ck_8:8;
        RBus_UInt32  reg_p2_ck_7:8;
        RBus_UInt32  reg_p2_ck_6:8;
        RBus_UInt32  reg_p2_ck_5:8;
    };
}dfe_hdmi_rx_phy_p2_ck2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_ck_12:8;
        RBus_UInt32  reg_p2_ck_11:8;
        RBus_UInt32  reg_p2_ck_10:8;
        RBus_UInt32  reg_p2_ck_9:8;
    };
}dfe_hdmi_rx_phy_p2_ck3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_p2_ck_13:8;
    };
}dfe_hdmi_rx_phy_p2_ck4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_g_4:8;
        RBus_UInt32  reg_p2_g_3:8;
        RBus_UInt32  reg_p2_g_2:8;
        RBus_UInt32  reg_p2_g_1:8;
    };
}dfe_hdmi_rx_phy_p2_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_g_8:8;
        RBus_UInt32  reg_p2_g_7:8;
        RBus_UInt32  reg_p2_g_6:8;
        RBus_UInt32  reg_p2_g_5:8;
    };
}dfe_hdmi_rx_phy_p2_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_g_12:8;
        RBus_UInt32  reg_p2_g_11:8;
        RBus_UInt32  reg_p2_g_10:8;
        RBus_UInt32  reg_p2_g_9:8;
    };
}dfe_hdmi_rx_phy_p2_g3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p2_g_koff_sel:5;
        RBus_UInt32  reg_p2_g_koff_bound:1;
        RBus_UInt32  reg_p2_g_koffok:1;
        RBus_UInt32  reg_p2_g_13:8;
    };
}dfe_hdmi_rx_phy_p2_g4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_r_4:8;
        RBus_UInt32  reg_p2_r_3:8;
        RBus_UInt32  reg_p2_r_2:8;
        RBus_UInt32  reg_p2_r_1:8;
    };
}dfe_hdmi_rx_phy_p2_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_r_8:8;
        RBus_UInt32  reg_p2_r_7:8;
        RBus_UInt32  reg_p2_r_6:8;
        RBus_UInt32  reg_p2_r_5:8;
    };
}dfe_hdmi_rx_phy_p2_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_r_12:8;
        RBus_UInt32  reg_p2_r_11:8;
        RBus_UInt32  reg_p2_r_10:8;
        RBus_UInt32  reg_p2_r_9:8;
    };
}dfe_hdmi_rx_phy_p2_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p2_r_koff_sel:5;
        RBus_UInt32  reg_p2_r_koff_bound:1;
        RBus_UInt32  reg_p2_r_koffok:1;
        RBus_UInt32  reg_p2_r_13:8;
    };
}dfe_hdmi_rx_phy_p2_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_acdr_4:8;
        RBus_UInt32  reg_p3_acdr_3:8;
        RBus_UInt32  reg_p3_acdr_2:8;
        RBus_UInt32  reg_p3_acdr_1:8;
    };
}dfe_hdmi_rx_phy_p3_acdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_acdr_8:8;
        RBus_UInt32  reg_p3_acdr_7:8;
        RBus_UInt32  reg_p3_acdr_6:8;
        RBus_UInt32  reg_p3_acdr_5:8;
    };
}dfe_hdmi_rx_phy_p3_acdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_b_4:8;
        RBus_UInt32  reg_p3_b_3:8;
        RBus_UInt32  reg_p3_b_2:8;
        RBus_UInt32  reg_p3_b_1:8;
    };
}dfe_hdmi_rx_phy_p3_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_b_8:8;
        RBus_UInt32  reg_p3_b_7:8;
        RBus_UInt32  reg_p3_b_6:8;
        RBus_UInt32  reg_p3_b_5:8;
    };
}dfe_hdmi_rx_phy_p3_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_b_12:8;
        RBus_UInt32  reg_p3_b_11:8;
        RBus_UInt32  reg_p3_b_10:8;
        RBus_UInt32  reg_p3_b_9:8;
    };
}dfe_hdmi_rx_phy_p3_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p3_b_koff_sel:5;
        RBus_UInt32  reg_p3_b_koff_bound:1;
        RBus_UInt32  reg_p3_b_koffok:1;
        RBus_UInt32  reg_p3_b_13:8;
    };
}dfe_hdmi_rx_phy_p3_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_ck_4:8;
        RBus_UInt32  reg_p3_ck_3:8;
        RBus_UInt32  reg_p3_ck_2:8;
        RBus_UInt32  reg_p3_ck_1:8;
    };
}dfe_hdmi_rx_phy_p3_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_ck_8:8;
        RBus_UInt32  reg_p3_ck_7:8;
        RBus_UInt32  reg_p3_ck_6:8;
        RBus_UInt32  reg_p3_ck_5:8;
    };
}dfe_hdmi_rx_phy_p3_ck2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_ck_12:8;
        RBus_UInt32  reg_p3_ck_11:8;
        RBus_UInt32  reg_p3_ck_10:8;
        RBus_UInt32  reg_p3_ck_9:8;
    };
}dfe_hdmi_rx_phy_p3_ck3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_p3_ck_13:8;
    };
}dfe_hdmi_rx_phy_p3_ck4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_g_4:8;
        RBus_UInt32  reg_p3_g_3:8;
        RBus_UInt32  reg_p3_g_2:8;
        RBus_UInt32  reg_p3_g_1:8;
    };
}dfe_hdmi_rx_phy_p3_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_g_8:8;
        RBus_UInt32  reg_p3_g_7:8;
        RBus_UInt32  reg_p3_g_6:8;
        RBus_UInt32  reg_p3_g_5:8;
    };
}dfe_hdmi_rx_phy_p3_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_g_12:8;
        RBus_UInt32  reg_p3_g_11:8;
        RBus_UInt32  reg_p3_g_10:8;
        RBus_UInt32  reg_p3_g_9:8;
    };
}dfe_hdmi_rx_phy_p3_g3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p3_g_koff_sel:5;
        RBus_UInt32  reg_p3_g_koff_bound:1;
        RBus_UInt32  reg_p3_g_koffok:1;
        RBus_UInt32  reg_p3_g_13:8;
    };
}dfe_hdmi_rx_phy_p3_g4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_r_4:8;
        RBus_UInt32  reg_p3_r_3:8;
        RBus_UInt32  reg_p3_r_2:8;
        RBus_UInt32  reg_p3_r_1:8;
    };
}dfe_hdmi_rx_phy_p3_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_r_8:8;
        RBus_UInt32  reg_p3_r_7:8;
        RBus_UInt32  reg_p3_r_6:8;
        RBus_UInt32  reg_p3_r_5:8;
    };
}dfe_hdmi_rx_phy_p3_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_r_12:8;
        RBus_UInt32  reg_p3_r_11:8;
        RBus_UInt32  reg_p3_r_10:8;
        RBus_UInt32  reg_p3_r_9:8;
    };
}dfe_hdmi_rx_phy_p3_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  reg_p3_r_koff_sel:5;
        RBus_UInt32  reg_p3_r_koff_bound:1;
        RBus_UInt32  reg_p3_r_koffok:1;
        RBus_UInt32  reg_p3_r_13:8;
    };
}dfe_hdmi_rx_phy_p3_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  reg_eye_ref_ctrl:6;
        RBus_UInt32  reg_eye_pi_en:4;
    };
}dfe_hdmi_rx_phy_eye1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_eye_pi_st:32;
    };
}dfe_hdmi_rx_phy_eye2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  p3_bypass_ok:1;
        RBus_UInt32  p2_bypass_ok:1;
        RBus_UInt32  p1_bypass_ok:1;
        RBus_UInt32  p0_bypass_ok:1;
    };
}dfe_hdmi_rx_phy_bypass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  eye_monitor_rstn:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_p3_acdr_rstb_fsm:1;
        RBus_UInt32  reg_p2_acdr_rstb_fsm:1;
        RBus_UInt32  reg_p1_acdr_rstb_fsm:1;
        RBus_UInt32  reg_p0_acdr_rstb_fsm:1;
        RBus_UInt32  p3_ck_vcorstb:1;
        RBus_UInt32  p2_ck_vcorstb:1;
        RBus_UInt32  p1_ck_vcorstb:1;
        RBus_UInt32  p0_ck_vcorstb:1;
        RBus_UInt32  p3_ck_pllrstb:1;
        RBus_UInt32  p2_ck_pllrstb:1;
        RBus_UInt32  p1_ck_pllrstb:1;
        RBus_UInt32  p0_ck_pllrstb:1;
        RBus_UInt32  p3_r_demux_rstb:1;
        RBus_UInt32  p3_g_demux_rstb:1;
        RBus_UInt32  p3_b_demux_rstb:1;
        RBus_UInt32  p2_r_demux_rstb:1;
        RBus_UInt32  p2_g_demux_rstb:1;
        RBus_UInt32  p2_b_demux_rstb:1;
        RBus_UInt32  p1_r_demux_rstb:1;
        RBus_UInt32  p1_g_demux_rstb:1;
        RBus_UInt32  p1_b_demux_rstb:1;
        RBus_UInt32  p0_r_demux_rstb:1;
        RBus_UInt32  p0_g_demux_rstb:1;
        RBus_UInt32  p0_b_demux_rstb:1;
    };
}dfe_hdmi_rx_phy_rst_RBUS;

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
}dfe_hdmi_rx_phy_regd0_RBUS;

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
}dfe_hdmi_rx_phy_regd1_RBUS;

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
}dfe_hdmi_rx_phy_regd2_RBUS;

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
}dfe_hdmi_rx_phy_regd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p0_er_count_r:10;
        RBus_UInt32  p0_er_count_g:10;
        RBus_UInt32  p0_er_count_b:10;
    };
}dfe_hdmi_rx_phy_regd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_r_dig_rst_n:1;
        RBus_UInt32  p1_g_dig_rst_n:1;
        RBus_UInt32  p1_b_dig_rst_n:1;
        RBus_UInt32  p1_r_cdr_rst_n:1;
        RBus_UInt32  p1_g_cdr_rst_n:1;
        RBus_UInt32  p1_b_cdr_rst_n:1;
        RBus_UInt32  reg_p1_cdr_ckinv_r:1;
        RBus_UInt32  reg_p1_cdr_ckinv_g:1;
        RBus_UInt32  reg_p1_cdr_ckinv_b:1;
        RBus_UInt32  reg_p1_shift_inv_r:1;
        RBus_UInt32  reg_p1_shift_inv_g:1;
        RBus_UInt32  reg_p1_shift_inv_b:1;
        RBus_UInt32  reg_p1_rate_sel:3;
        RBus_UInt32  reg_p1_kd:1;
        RBus_UInt32  reg_p1_kp:8;
        RBus_UInt32  reg_p1_ki:3;
        RBus_UInt32  reg_p1_bypass_sdm_int:1;
        RBus_UInt32  reg_p1_data_order:1;
        RBus_UInt32  reg_p1_infifo_cnt:3;
    };
}dfe_hdmi_rx_phy_regd5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_int_init:14;
        RBus_UInt32  reg_p1_acc2_period:10;
        RBus_UInt32  reg_p1_squ_tri:1;
        RBus_UInt32  reg_p1_acc2_manual:1;
        RBus_UInt32  reg_p1_testout_sel:2;
        RBus_UInt32  reg_p1_ercnt_en:1;
        RBus_UInt32  reg_p1_edge_out:1;
        RBus_UInt32  reg_p1_pi_m_mode:1;
        RBus_UInt32  reg_p1_dyn_kp_en:1;
    };
}dfe_hdmi_rx_phy_regd6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_en_m_value:4;
        RBus_UInt32  reg_p1_st_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_p1_timer_lpf:5;
        RBus_UInt32  reg_p1_timer_eq:5;
        RBus_UInt32  reg_p1_timer_ber:5;
        RBus_UInt32  res2:8;
    };
}dfe_hdmi_rx_phy_regd7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  p1_st_ro_r:5;
        RBus_UInt32  p1_en_ro_r:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  p1_st_ro_g:5;
        RBus_UInt32  p1_en_ro_g:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  p1_st_ro_b:5;
        RBus_UInt32  p1_en_ro_b:4;
    };
}dfe_hdmi_rx_phy_regd8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p1_er_count_r:10;
        RBus_UInt32  p1_er_count_g:10;
        RBus_UInt32  p1_er_count_b:10;
    };
}dfe_hdmi_rx_phy_regd9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_r_dig_rst_n:1;
        RBus_UInt32  p2_g_dig_rst_n:1;
        RBus_UInt32  p2_b_dig_rst_n:1;
        RBus_UInt32  p2_r_cdr_rst_n:1;
        RBus_UInt32  p2_g_cdr_rst_n:1;
        RBus_UInt32  p2_b_cdr_rst_n:1;
        RBus_UInt32  reg_p2_cdr_ckinv_r:1;
        RBus_UInt32  reg_p2_cdr_ckinv_g:1;
        RBus_UInt32  reg_p2_cdr_ckinv_b:1;
        RBus_UInt32  reg_p2_shift_inv_r:1;
        RBus_UInt32  reg_p2_shift_inv_g:1;
        RBus_UInt32  reg_p2_shift_inv_b:1;
        RBus_UInt32  reg_p2_rate_sel:3;
        RBus_UInt32  reg_p2_kd:1;
        RBus_UInt32  reg_p2_kp:8;
        RBus_UInt32  reg_p2_ki:3;
        RBus_UInt32  reg_p2_bypass_sdm_int:1;
        RBus_UInt32  reg_p2_data_order:1;
        RBus_UInt32  reg_p2_infifo_cnt:3;
    };
}dfe_hdmi_rx_phy_regd10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_int_init:14;
        RBus_UInt32  reg_p2_acc2_period:10;
        RBus_UInt32  reg_p2_squ_tri:1;
        RBus_UInt32  reg_p2_acc2_manual:1;
        RBus_UInt32  reg_p2_testout_sel:2;
        RBus_UInt32  reg_p2_ercnt_en:1;
        RBus_UInt32  reg_p2_edge_out:1;
        RBus_UInt32  reg_p2_pi_m_mode:1;
        RBus_UInt32  reg_p2_dyn_kp_en:1;
    };
}dfe_hdmi_rx_phy_regd11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_en_m_value:4;
        RBus_UInt32  reg_p2_st_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_p2_timer_lpf:5;
        RBus_UInt32  reg_p2_timer_eq:5;
        RBus_UInt32  reg_p2_timer_ber:5;
        RBus_UInt32  res2:8;
    };
}dfe_hdmi_rx_phy_regd12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  p2_st_ro_r:5;
        RBus_UInt32  p2_en_ro_r:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  p2_st_ro_g:5;
        RBus_UInt32  p2_en_ro_g:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  p2_st_ro_b:5;
        RBus_UInt32  p2_en_ro_b:4;
    };
}dfe_hdmi_rx_phy_regd13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p2_er_count_r:10;
        RBus_UInt32  p2_er_count_g:10;
        RBus_UInt32  p2_er_count_b:10;
    };
}dfe_hdmi_rx_phy_regd14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_r_dig_rst_n:1;
        RBus_UInt32  p3_g_dig_rst_n:1;
        RBus_UInt32  p3_b_dig_rst_n:1;
        RBus_UInt32  p3_r_cdr_rst_n:1;
        RBus_UInt32  p3_g_cdr_rst_n:1;
        RBus_UInt32  p3_b_cdr_rst_n:1;
        RBus_UInt32  reg_p3_cdr_ckinv_r:1;
        RBus_UInt32  reg_p3_cdr_ckinv_g:1;
        RBus_UInt32  reg_p3_cdr_ckinv_b:1;
        RBus_UInt32  reg_p3_shift_inv_r:1;
        RBus_UInt32  reg_p3_shift_inv_g:1;
        RBus_UInt32  reg_p3_shift_inv_b:1;
        RBus_UInt32  reg_p3_rate_sel:3;
        RBus_UInt32  reg_p3_kd:1;
        RBus_UInt32  reg_p3_kp:8;
        RBus_UInt32  reg_p3_ki:3;
        RBus_UInt32  reg_p3_bypass_sdm_int:1;
        RBus_UInt32  reg_p3_data_order:1;
        RBus_UInt32  reg_p3_infifo_cnt:3;
    };
}dfe_hdmi_rx_phy_regd15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_int_init:14;
        RBus_UInt32  reg_p3_acc2_period:10;
        RBus_UInt32  reg_p3_squ_tri:1;
        RBus_UInt32  reg_p3_acc2_manual:1;
        RBus_UInt32  reg_p3_testout_sel:2;
        RBus_UInt32  reg_p3_ercnt_en:1;
        RBus_UInt32  reg_p3_edge_out:1;
        RBus_UInt32  reg_p3_pi_m_mode:1;
        RBus_UInt32  reg_p3_dyn_kp_en:1;
    };
}dfe_hdmi_rx_phy_regd16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_en_m_value:4;
        RBus_UInt32  reg_p3_st_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_p3_timer_lpf:5;
        RBus_UInt32  reg_p3_timer_eq:5;
        RBus_UInt32  reg_p3_timer_ber:5;
        RBus_UInt32  res2:8;
    };
}dfe_hdmi_rx_phy_regd17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  p3_st_ro_r:5;
        RBus_UInt32  p3_en_ro_r:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  p3_st_ro_g:5;
        RBus_UInt32  p3_en_ro_g:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  p3_st_ro_b:5;
        RBus_UInt32  p3_en_ro_b:4;
    };
}dfe_hdmi_rx_phy_regd18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p3_er_count_r:10;
        RBus_UInt32  p3_er_count_g:10;
        RBus_UInt32  p3_er_count_b:10;
    };
}dfe_hdmi_rx_phy_regd19_RBUS;

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
}dfe_hdmi_rx_phy_regd20_RBUS;

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
}dfe_hdmi_rx_phy_regd21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_bypass_clk_rdy:1;
        RBus_UInt32  reg_p1_bypass_eqen_rdy:1;
        RBus_UInt32  reg_p1_bypass_data_rdy:1;
        RBus_UInt32  reg_p1_bypass_pi:1;
        RBus_UInt32  reg_p1_data_rdy_time:4;
        RBus_UInt32  reg_p1_en_clkout_manual:1;
        RBus_UInt32  reg_p1_en_eqen_manual:1;
        RBus_UInt32  reg_p1_en_data_manual:1;
        RBus_UInt32  reg_p1_eqen_rdy_time:4;
        RBus_UInt32  reg_p1_order:1;
        RBus_UInt32  reg_p1_pll_wd_base_time:3;
        RBus_UInt32  reg_p1_pll_wd_en:1;
        RBus_UInt32  reg_p1_pll_wd_rst_wid:2;
        RBus_UInt32  reg_p1_pll_wd_time_rdy:2;
        RBus_UInt32  reg_p1_acdr_l0_en:1;
        RBus_UInt32  reg_p1_bypass_eqen_rdy_l0:1;
        RBus_UInt32  reg_p1_bypass_data_rdy_l0:1;
        RBus_UInt32  reg_p1_en_eqen_manual_l0:1;
        RBus_UInt32  reg_p1_en_data_manual_l0:1;
        RBus_UInt32  p1_pll_wd_ckrdy_ro:1;
        RBus_UInt32  p1_pll_wd_rst_wc:1;
        RBus_UInt32  p1_wdog_rst_n:1;
    };
}dfe_hdmi_rx_phy_regd22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_wd_sdm_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_p1_f_code:12;
        RBus_UInt32  res2:7;
        RBus_UInt32  reg_p1_n_code:9;
    };
}dfe_hdmi_rx_phy_regd23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_bypass_clk_rdy:1;
        RBus_UInt32  reg_p2_bypass_eqen_rdy:1;
        RBus_UInt32  reg_p2_bypass_data_rdy:1;
        RBus_UInt32  reg_p2_bypass_pi:1;
        RBus_UInt32  reg_p2_data_rdy_time:4;
        RBus_UInt32  reg_p2_en_clkout_manual:1;
        RBus_UInt32  reg_p2_en_eqen_manual:1;
        RBus_UInt32  reg_p2_en_data_manual:1;
        RBus_UInt32  reg_p2_eqen_rdy_time:4;
        RBus_UInt32  reg_p2_order:1;
        RBus_UInt32  reg_p2_pll_wd_base_time:3;
        RBus_UInt32  reg_p2_pll_wd_en:1;
        RBus_UInt32  reg_p2_pll_wd_rst_wid:2;
        RBus_UInt32  reg_p2_pll_wd_time_rdy:2;
        RBus_UInt32  reg_p2_acdr_l0_en:1;
        RBus_UInt32  reg_p2_bypass_eqen_rdy_l0:1;
        RBus_UInt32  reg_p2_bypass_data_rdy_l0:1;
        RBus_UInt32  reg_p2_en_eqen_manual_l0:1;
        RBus_UInt32  reg_p2_en_data_manual_l0:1;
        RBus_UInt32  p2_pll_wd_ckrdy_ro:1;
        RBus_UInt32  p2_pll_wd_rst_wc:1;
        RBus_UInt32  p2_wdog_rst_n:1;
    };
}dfe_hdmi_rx_phy_regd24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_wd_sdm_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_p2_f_code:12;
        RBus_UInt32  res2:7;
        RBus_UInt32  reg_p2_n_code:9;
    };
}dfe_hdmi_rx_phy_regd25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_bypass_clk_rdy:1;
        RBus_UInt32  reg_p3_bypass_eqen_rdy:1;
        RBus_UInt32  reg_p3_bypass_data_rdy:1;
        RBus_UInt32  reg_p3_bypass_pi:1;
        RBus_UInt32  reg_p3_data_rdy_time:4;
        RBus_UInt32  reg_p3_en_clkout_manual:1;
        RBus_UInt32  reg_p3_en_eqen_manual:1;
        RBus_UInt32  reg_p3_en_data_manual:1;
        RBus_UInt32  reg_p3_eqen_rdy_time:4;
        RBus_UInt32  reg_p3_order:1;
        RBus_UInt32  reg_p3_pll_wd_base_time:3;
        RBus_UInt32  reg_p3_pll_wd_en:1;
        RBus_UInt32  reg_p3_pll_wd_rst_wid:2;
        RBus_UInt32  reg_p3_pll_wd_time_rdy:2;
        RBus_UInt32  reg_p3_acdr_l0_en:1;
        RBus_UInt32  reg_p3_bypass_eqen_rdy_l0:1;
        RBus_UInt32  reg_p3_bypass_data_rdy_l0:1;
        RBus_UInt32  reg_p3_en_eqen_manual_l0:1;
        RBus_UInt32  reg_p3_en_data_manual_l0:1;
        RBus_UInt32  p3_pll_wd_ckrdy_ro:1;
        RBus_UInt32  p3_pll_wd_rst_wc:1;
        RBus_UInt32  p3_wdog_rst_n:1;
    };
}dfe_hdmi_rx_phy_regd26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_wd_sdm_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_p3_f_code:12;
        RBus_UInt32  res2:7;
        RBus_UInt32  reg_p3_n_code:9;
    };
}dfe_hdmi_rx_phy_regd27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_auto_mode:1;
        RBus_UInt32  reg_p0_adp_en_manual:1;
        RBus_UInt32  reg_p0_cp_en_manual:1;
        RBus_UInt32  reg_p0_adap_eq_off:1;
        RBus_UInt32  reg_p0_adp_time:5;
        RBus_UInt32  reg_p0_calib_time:3;
        RBus_UInt32  reg_p0_calib_manual:1;
        RBus_UInt32  reg_p0_calib_late:1;
        RBus_UInt32  reg_p0_vco_coarse:7;
        RBus_UInt32  reg_p0_divide_num:7;
        RBus_UInt32  reg_p0_init_time:3;
        RBus_UInt32  res1:1;
    };
}dfe_hdmi_rx_phy_regd28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  reg_p0_lock_up_limit:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  reg_p0_lock_dn_limit:11;
    };
}dfe_hdmi_rx_phy_regd29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_cdr_cp:20;
        RBus_UInt32  reg_p0_cdr_r:6;
        RBus_UInt32  reg_p0_cdr_c:2;
        RBus_UInt32  reg_p0_vc_sel:2;
        RBus_UInt32  reg_p0_calib_reset_sel:1;
        RBus_UInt32  res1:1;
    };
}dfe_hdmi_rx_phy_regd30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_slope_lv_up:11;
        RBus_UInt32  reg_p0_slope_lv_dn:11;
        RBus_UInt32  reg_p0_cp_time:5;
        RBus_UInt32  reg_p0_timer_4:5;
    };
}dfe_hdmi_rx_phy_regd31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_slope_hv_up:11;
        RBus_UInt32  reg_p0_slope_hv_dn:11;
        RBus_UInt32  reg_p0_timer_5:1;
        RBus_UInt32  reg_p0_timer_6:5;
        RBus_UInt32  res1:4;
    };
}dfe_hdmi_rx_phy_regd32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_start_en_manual:1;
        RBus_UInt32  reg_p0_pfd_en_manual:1;
        RBus_UInt32  reg_p0_pfd_time:5;
        RBus_UInt32  reg_p0_pfd_bypass:1;
        RBus_UInt32  reg_p0_rxidle_bypass:1;
        RBus_UInt32  reg_p0_slope_manual:1;
        RBus_UInt32  reg_p0_slope_band:5;
        RBus_UInt32  reg_p0_old_mode:1;
        RBus_UInt32  res1:16;
    };
}dfe_hdmi_rx_phy_regd33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_fld_st_reg:5;
        RBus_UInt32  p0_adp_en_fsm_reg:1;
        RBus_UInt32  p0_cp_en_fsm_reg:1;
        RBus_UInt32  p0_coarse_fsm_reg:7;
        RBus_UInt32  p0_pfd_en_fsm_reg:1;
        RBus_UInt32  p0_slope_lv_reg:5;
        RBus_UInt32  p0_slope_hv_reg:5;
        RBus_UInt32  p0_slope_final_reg:5;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_auto_mode:1;
        RBus_UInt32  reg_p1_adp_en_manual:1;
        RBus_UInt32  reg_p1_cp_en_manual:1;
        RBus_UInt32  reg_p1_adap_eq_off:1;
        RBus_UInt32  reg_p1_adp_time:5;
        RBus_UInt32  reg_p1_calib_time:3;
        RBus_UInt32  reg_p1_calib_manual:1;
        RBus_UInt32  reg_p1_calib_late:1;
        RBus_UInt32  reg_p1_vco_coarse:7;
        RBus_UInt32  reg_p1_divide_num:7;
        RBus_UInt32  reg_p1_init_time:3;
        RBus_UInt32  res1:1;
    };
}dfe_hdmi_rx_phy_regd35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  reg_p1_lock_up_limit:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  reg_p1_lock_dn_limit:11;
    };
}dfe_hdmi_rx_phy_regd36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_cdr_cp:20;
        RBus_UInt32  reg_p1_cdr_r:6;
        RBus_UInt32  reg_p1_cdr_c:2;
        RBus_UInt32  reg_p1_vc_sel:2;
        RBus_UInt32  reg_p1_calib_reset_sel:1;
        RBus_UInt32  res1:1;
    };
}dfe_hdmi_rx_phy_regd37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_slope_lv_up:11;
        RBus_UInt32  reg_p1_slope_lv_dn:11;
        RBus_UInt32  reg_p1_cp_time:5;
        RBus_UInt32  reg_p1_timer_4:5;
    };
}dfe_hdmi_rx_phy_regd38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_slope_hv_up:11;
        RBus_UInt32  reg_p1_slope_hv_dn:11;
        RBus_UInt32  reg_p1_timer_5:1;
        RBus_UInt32  reg_p1_timer_6:5;
        RBus_UInt32  res1:4;
    };
}dfe_hdmi_rx_phy_regd39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_start_en_manual:1;
        RBus_UInt32  reg_p1_pfd_en_manual:1;
        RBus_UInt32  reg_p1_pfd_time:5;
        RBus_UInt32  reg_p1_pfd_bypass:1;
        RBus_UInt32  reg_p1_rxidle_bypass:1;
        RBus_UInt32  reg_p1_slope_manual:1;
        RBus_UInt32  reg_p1_slope_band:5;
        RBus_UInt32  reg_p1_old_mode:1;
        RBus_UInt32  res1:16;
    };
}dfe_hdmi_rx_phy_regd40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_fld_st_reg:5;
        RBus_UInt32  p1_adp_en_fsm_reg:1;
        RBus_UInt32  p1_cp_en_fsm_reg:1;
        RBus_UInt32  p1_coarse_fsm_reg:7;
        RBus_UInt32  p1_pfd_en_fsm_reg:1;
        RBus_UInt32  p1_slope_lv_reg:5;
        RBus_UInt32  p1_slope_hv_reg:5;
        RBus_UInt32  p1_slope_final_reg:5;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_auto_mode:1;
        RBus_UInt32  reg_p2_adp_en_manual:1;
        RBus_UInt32  reg_p2_cp_en_manual:1;
        RBus_UInt32  reg_p2_adap_eq_off:1;
        RBus_UInt32  reg_p2_adp_time:5;
        RBus_UInt32  reg_p2_calib_time:3;
        RBus_UInt32  reg_p2_calib_manual:1;
        RBus_UInt32  reg_p2_calib_late:1;
        RBus_UInt32  reg_p2_vco_coarse:7;
        RBus_UInt32  reg_p2_divide_num:7;
        RBus_UInt32  reg_p2_init_time:3;
        RBus_UInt32  res1:1;
    };
}dfe_hdmi_rx_phy_regd42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  reg_p2_lock_up_limit:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  reg_p2_lock_dn_limit:11;
    };
}dfe_hdmi_rx_phy_regd43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_cdr_cp:20;
        RBus_UInt32  reg_p2_cdr_r:6;
        RBus_UInt32  reg_p2_cdr_c:2;
        RBus_UInt32  reg_p2_vc_sel:2;
        RBus_UInt32  reg_p2_calib_reset_sel:1;
        RBus_UInt32  res1:1;
    };
}dfe_hdmi_rx_phy_regd44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_slope_lv_up:11;
        RBus_UInt32  reg_p2_slope_lv_dn:11;
        RBus_UInt32  reg_p2_cp_time:5;
        RBus_UInt32  reg_p2_timer_4:5;
    };
}dfe_hdmi_rx_phy_regd45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_slope_hv_up:11;
        RBus_UInt32  reg_p2_slope_hv_dn:11;
        RBus_UInt32  reg_p2_timer_5:1;
        RBus_UInt32  reg_p2_timer_6:5;
        RBus_UInt32  res1:4;
    };
}dfe_hdmi_rx_phy_regd46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_start_en_manual:1;
        RBus_UInt32  reg_p2_pfd_en_manual:1;
        RBus_UInt32  reg_p2_pfd_time:5;
        RBus_UInt32  reg_p2_pfd_bypass:1;
        RBus_UInt32  reg_p2_rxidle_bypass:1;
        RBus_UInt32  reg_p2_slope_manual:1;
        RBus_UInt32  reg_p2_slope_band:5;
        RBus_UInt32  reg_p2_old_mode:1;
        RBus_UInt32  res1:16;
    };
}dfe_hdmi_rx_phy_regd47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_fld_st_reg:5;
        RBus_UInt32  p2_adp_en_fsm_reg:1;
        RBus_UInt32  p2_cp_en_fsm_reg:1;
        RBus_UInt32  p2_coarse_fsm_reg:7;
        RBus_UInt32  p2_pfd_en_fsm_reg:1;
        RBus_UInt32  p2_slope_lv_reg:5;
        RBus_UInt32  p2_slope_hv_reg:5;
        RBus_UInt32  p2_slope_final_reg:5;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_auto_mode:1;
        RBus_UInt32  reg_p3_adp_en_manual:1;
        RBus_UInt32  reg_p3_cp_en_manual:1;
        RBus_UInt32  reg_p3_adap_eq_off:1;
        RBus_UInt32  reg_p3_adp_time:5;
        RBus_UInt32  reg_p3_calib_time:3;
        RBus_UInt32  reg_p3_calib_manual:1;
        RBus_UInt32  reg_p3_calib_late:1;
        RBus_UInt32  reg_p3_vco_coarse:7;
        RBus_UInt32  reg_p3_divide_num:7;
        RBus_UInt32  reg_p3_init_time:3;
        RBus_UInt32  res1:1;
    };
}dfe_hdmi_rx_phy_regd49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  reg_p3_lock_up_limit:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  reg_p3_lock_dn_limit:11;
    };
}dfe_hdmi_rx_phy_regd50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_cdr_cp:20;
        RBus_UInt32  reg_p3_cdr_r:6;
        RBus_UInt32  reg_p3_cdr_c:2;
        RBus_UInt32  reg_p3_vc_sel:2;
        RBus_UInt32  reg_p3_calib_reset_sel:1;
        RBus_UInt32  res1:1;
    };
}dfe_hdmi_rx_phy_regd51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_slope_lv_up:11;
        RBus_UInt32  reg_p3_slope_lv_dn:11;
        RBus_UInt32  reg_p3_cp_time:5;
        RBus_UInt32  reg_p3_timer_4:5;
    };
}dfe_hdmi_rx_phy_regd52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_slope_hv_up:11;
        RBus_UInt32  reg_p3_slope_hv_dn:11;
        RBus_UInt32  reg_p3_timer_5:1;
        RBus_UInt32  reg_p3_timer_6:5;
        RBus_UInt32  res1:4;
    };
}dfe_hdmi_rx_phy_regd53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_start_en_manual:1;
        RBus_UInt32  reg_p3_pfd_en_manual:1;
        RBus_UInt32  reg_p3_pfd_time:5;
        RBus_UInt32  reg_p3_pfd_bypass:1;
        RBus_UInt32  reg_p3_rxidle_bypass:1;
        RBus_UInt32  reg_p3_slope_manual:1;
        RBus_UInt32  reg_p3_slope_band:5;
        RBus_UInt32  reg_p3_old_mode:1;
        RBus_UInt32  res1:16;
    };
}dfe_hdmi_rx_phy_regd54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_fld_st_reg:5;
        RBus_UInt32  p3_adp_en_fsm_reg:1;
        RBus_UInt32  p3_cp_en_fsm_reg:1;
        RBus_UInt32  p3_coarse_fsm_reg:7;
        RBus_UInt32  p3_pfd_en_fsm_reg:1;
        RBus_UInt32  p3_slope_lv_reg:5;
        RBus_UInt32  p3_slope_hv_reg:5;
        RBus_UInt32  p3_slope_final_reg:5;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd55_RBUS;

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
}dfe_hdmi_rx_phy_regd56_RBUS;

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
}dfe_hdmi_rx_phy_regd57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_ck_md_rstb:1;
        RBus_UInt32  reg_p1_ck_md_threshold:6;
        RBus_UInt32  reg_p1_ck_md_debounce:7;
        RBus_UInt32  reg_p1_ck_md_sel:2;
        RBus_UInt32  reg_p1_ck_md_auto:1;
        RBus_UInt32  reg_p1_ck_md_adj:4;
        RBus_UInt32  reg_p1_ck_error_limit:5;
        RBus_UInt32  reg_p1_ck_md_reserved:4;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_ck_md_count:13;
        RBus_UInt32  p1_ck_rate:4;
        RBus_UInt32  p1_unstable_count:5;
        RBus_UInt32  p1_ck_md_ok:1;
        RBus_UInt32  p1_clock_unstable_flag:1;
        RBus_UInt32  res1:8;
    };
}dfe_hdmi_rx_phy_regd59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_ck_md_rstb:1;
        RBus_UInt32  reg_p2_ck_md_threshold:6;
        RBus_UInt32  reg_p2_ck_md_debounce:7;
        RBus_UInt32  reg_p2_ck_md_sel:2;
        RBus_UInt32  reg_p2_ck_md_auto:1;
        RBus_UInt32  reg_p2_ck_md_adj:4;
        RBus_UInt32  reg_p2_ck_error_limit:5;
        RBus_UInt32  reg_p2_ck_md_reserved:4;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_ck_md_count:13;
        RBus_UInt32  p2_ck_rate:4;
        RBus_UInt32  p2_unstable_count:5;
        RBus_UInt32  p2_ck_md_ok:1;
        RBus_UInt32  p2_clock_unstable_flag:1;
        RBus_UInt32  res1:8;
    };
}dfe_hdmi_rx_phy_regd61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_ck_md_rstb:1;
        RBus_UInt32  reg_p3_ck_md_threshold:6;
        RBus_UInt32  reg_p3_ck_md_debounce:7;
        RBus_UInt32  reg_p3_ck_md_sel:2;
        RBus_UInt32  reg_p3_ck_md_auto:1;
        RBus_UInt32  reg_p3_ck_md_adj:4;
        RBus_UInt32  reg_p3_ck_error_limit:5;
        RBus_UInt32  reg_p3_ck_md_reserved:4;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_ck_md_count:13;
        RBus_UInt32  p3_ck_rate:4;
        RBus_UInt32  p3_unstable_count:5;
        RBus_UInt32  p3_ck_md_ok:1;
        RBus_UInt32  p3_clock_unstable_flag:1;
        RBus_UInt32  res1:8;
    };
}dfe_hdmi_rx_phy_regd63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dig_reserved_0:8;
        RBus_UInt32  reg_dig_reserved_1:8;
        RBus_UInt32  reg_dig_reserved_2:8;
        RBus_UInt32  reg_dig_reserved_3:8;
    };
}dfe_hdmi_rx_phy_regd64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dig_debug_sel:5;
        RBus_UInt32  res1:27;
    };
}dfe_hdmi_rx_phy_regd65_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value:32;
    };
}dfe_hdmi_rx_phy_regd66_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value:32;
    };
}dfe_hdmi_rx_phy_regd67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_st_m_value:32;
    };
}dfe_hdmi_rx_phy_regd68_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_st_m_value:32;
    };
}dfe_hdmi_rx_phy_regd69_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  reg_eye_monitor_ck_sel:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  eye_monitor_dout:16;
    };
}dfe_hdmi_rx_phy_regd70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_regd71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_regd72_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_regd73_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_regd74_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_regd75_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_regd76_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_regd77_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_regd78_RBUS;

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
}dfe_hdmi_rx_phy_regd79_RBUS;

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
}dfe_hdmi_rx_phy_regd80_RBUS;

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
}dfe_hdmi_rx_phy_regd81_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p1_enable_one_zero_r:1;
        RBus_UInt32  reg_p1_prbs_invs_r:1;
        RBus_UInt32  reg_p1_pattern_sel_r:1;
        RBus_UInt32  p1_pkt_count_r:8;
        RBus_UInt32  p1_err_count_r:8;
    };
}dfe_hdmi_rx_phy_regd82_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p1_enable_one_zero_g:1;
        RBus_UInt32  reg_p1_prbs_invs_g:1;
        RBus_UInt32  reg_p1_pattern_sel_g:1;
        RBus_UInt32  p1_pkt_count_g:8;
        RBus_UInt32  p1_err_count_g:8;
    };
}dfe_hdmi_rx_phy_regd83_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p1_enable_one_zero_b:1;
        RBus_UInt32  reg_p1_prbs_invs_b:1;
        RBus_UInt32  reg_p1_pattern_sel_b:1;
        RBus_UInt32  p1_pkt_count_b:8;
        RBus_UInt32  p1_err_count_b:8;
    };
}dfe_hdmi_rx_phy_regd84_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p2_enable_one_zero_r:1;
        RBus_UInt32  reg_p2_prbs_invs_r:1;
        RBus_UInt32  reg_p2_pattern_sel_r:1;
        RBus_UInt32  p2_pkt_count_r:8;
        RBus_UInt32  p2_err_count_r:8;
    };
}dfe_hdmi_rx_phy_regd85_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p2_enable_one_zero_g:1;
        RBus_UInt32  reg_p2_prbs_invs_g:1;
        RBus_UInt32  reg_p2_pattern_sel_g:1;
        RBus_UInt32  p2_pkt_count_g:8;
        RBus_UInt32  p2_err_count_g:8;
    };
}dfe_hdmi_rx_phy_regd86_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p2_enable_one_zero_b:1;
        RBus_UInt32  reg_p2_prbs_invs_b:1;
        RBus_UInt32  reg_p2_pattern_sel_b:1;
        RBus_UInt32  p2_pkt_count_b:8;
        RBus_UInt32  p2_err_count_b:8;
    };
}dfe_hdmi_rx_phy_regd87_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p3_enable_one_zero_r:1;
        RBus_UInt32  reg_p3_prbs_invs_r:1;
        RBus_UInt32  reg_p3_pattern_sel_r:1;
        RBus_UInt32  p3_pkt_count_r:8;
        RBus_UInt32  p3_err_count_r:8;
    };
}dfe_hdmi_rx_phy_regd88_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p3_enable_one_zero_g:1;
        RBus_UInt32  reg_p3_prbs_invs_g:1;
        RBus_UInt32  reg_p3_pattern_sel_g:1;
        RBus_UInt32  p3_pkt_count_g:8;
        RBus_UInt32  p3_err_count_g:8;
    };
}dfe_hdmi_rx_phy_regd89_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_p3_enable_one_zero_b:1;
        RBus_UInt32  reg_p3_prbs_invs_b:1;
        RBus_UInt32  reg_p3_pattern_sel_b:1;
        RBus_UInt32  p3_pkt_count_b:8;
        RBus_UInt32  p3_err_count_b:8;
    };
}dfe_hdmi_rx_phy_regd90_RBUS;

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
        RBus_UInt32  reg_ck_ckdet:4;
        RBus_UInt32  reg_ck_cmp:1;
        RBus_UInt32  reg_ck_latch:1;
        RBus_UInt32  res1:26;
    };
}dfe_hdmi_rx_phy_md_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_ldo_pow:1;
        RBus_UInt32  reg_p1_ldo_pow:1;
        RBus_UInt32  reg_p2_ldo_pow:1;
        RBus_UInt32  reg_p3_ldo_pow:1;
        RBus_UInt32  reg_p0_ldo_sel:2;
        RBus_UInt32  reg_p1_ldo_sel:2;
        RBus_UInt32  reg_p2_ldo_sel:2;
        RBus_UInt32  reg_p3_ldo_sel:2;
        RBus_UInt32  reg_ldo_mossel:3;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_ldo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mhl_hdmisel:1;
        RBus_UInt32  reg_p0_mhl_pow:1;
        RBus_UInt32  reg_p0_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p0_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p1_mhl_pow:1;
        RBus_UInt32  reg_p1_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p1_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p2_mhl_pow:1;
        RBus_UInt32  reg_p2_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p2_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p3_mhl_pow:1;
        RBus_UInt32  reg_p3_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p3_mhl_hdmi_datasel:1;
        RBus_UInt32  res1:19;
    };
}dfe_hdmi_rx_phy_mhl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_en_cdr:3;
        RBus_UInt32  reg_p0_en_cmu:1;
        RBus_UInt32  reg_p0_en_rx:3;
        RBus_UInt32  reg_p1_en_cdr:3;
        RBus_UInt32  reg_p1_en_cmu:1;
        RBus_UInt32  reg_p1_en_rx:3;
        RBus_UInt32  reg_p2_en_cdr:3;
        RBus_UInt32  reg_p2_en_cmu:1;
        RBus_UInt32  reg_p2_en_rx:3;
        RBus_UInt32  reg_p3_en_cdr:3;
        RBus_UInt32  reg_p3_en_cmu:1;
        RBus_UInt32  reg_p3_en_rx:3;
        RBus_UInt32  res1:4;
    };
}dfe_hdmi_rx_phy_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_stst:4;
        RBus_UInt32  reg_tst_spad:1;
        RBus_UInt32  res1:27;
    };
}dfe_hdmi_rx_phy_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_top_in_1:8;
        RBus_UInt32  reg_top_in_2:8;
        RBus_UInt32  reg_top_in_3:8;
        RBus_UInt32  reg_top_in_4:8;
    };
}dfe_hdmi_rx_phy_top_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_top_out_1:8;
        RBus_UInt32  reg_top_out_2:8;
        RBus_UInt32  reg_top_out_3:8;
        RBus_UInt32  reg_top_out_4:8;
    };
}dfe_hdmi_rx_phy_top_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_z0_z0pow_b:4;
        RBus_UInt32  reg_z0_z0pow_ck:4;
        RBus_UInt32  reg_z0_z0pow_g:4;
        RBus_UInt32  reg_z0_z0pow_r:4;
        RBus_UInt32  reg_z0_z100_en:4;
        RBus_UInt32  reg_z0_z300pow:4;
        RBus_UInt32  reg_z0_z300_sel:4;
        RBus_UInt32  res1:4;
    };
}dfe_hdmi_rx_phy_z0pow_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_z0tst:4;
        RBus_UInt32  reg_z0_adjr_0:5;
        RBus_UInt32  reg_z0_adjr_1:5;
        RBus_UInt32  reg_z0_adjr_2:5;
        RBus_UInt32  reg_z0_bound:1;
        RBus_UInt32  reg_z0_entst:1;
        RBus_UInt32  reg_z0_ok:1;
        RBus_UInt32  reg_z0_res:5;
        RBus_UInt32  reg_z0_stune:1;
        RBus_UInt32  reg_z0_z0pow:1;
        RBus_UInt32  res1:3;
    };
}dfe_hdmi_rx_phy_z0k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_z0_adjr_3:5;
        RBus_UInt32  res1:27;
    };
}dfe_hdmi_rx_phy_z0k_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_acdr_1:8;
        RBus_UInt32  reg_p0_acdr_2:8;
        RBus_UInt32  reg_p0_acdr_3:8;
        RBus_UInt32  reg_p0_acdr_4:8;
    };
}dfe_hdmi_rx_phy_p0_acdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_acdr_5:8;
        RBus_UInt32  reg_p0_acdr_6:8;
        RBus_UInt32  reg_p0_acdr_7:8;
        RBus_UInt32  reg_p0_acdr_8:8;
    };
}dfe_hdmi_rx_phy_p0_acdr2_RBUS;

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
        RBus_UInt32  reg_p1_acdr_1:8;
        RBus_UInt32  reg_p1_acdr_2:8;
        RBus_UInt32  reg_p1_acdr_3:8;
        RBus_UInt32  reg_p1_acdr_4:8;
    };
}dfe_hdmi_rx_phy_p1_acdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_acdr_5:8;
        RBus_UInt32  reg_p1_acdr_6:8;
        RBus_UInt32  reg_p1_acdr_7:8;
        RBus_UInt32  reg_p1_acdr_8:8;
    };
}dfe_hdmi_rx_phy_p1_acdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_b_1:8;
        RBus_UInt32  reg_p1_b_2:8;
        RBus_UInt32  reg_p1_b_3:8;
        RBus_UInt32  reg_p1_b_4:8;
    };
}dfe_hdmi_rx_phy_p1_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_b_5:8;
        RBus_UInt32  reg_p1_b_6:8;
        RBus_UInt32  reg_p1_b_7:8;
        RBus_UInt32  reg_p1_b_8:8;
    };
}dfe_hdmi_rx_phy_p1_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_b_9:8;
        RBus_UInt32  reg_p1_b_10:8;
        RBus_UInt32  reg_p1_b_11:8;
        RBus_UInt32  reg_p1_b_12:8;
    };
}dfe_hdmi_rx_phy_p1_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_b_13:8;
        RBus_UInt32  reg_p1_b_koffok:1;
        RBus_UInt32  reg_p1_b_koff_bound:1;
        RBus_UInt32  reg_p1_b_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p1_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_ck_1:8;
        RBus_UInt32  reg_p1_ck_2:8;
        RBus_UInt32  reg_p1_ck_3:8;
        RBus_UInt32  reg_p1_ck_4:8;
    };
}dfe_hdmi_rx_phy_p1_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_ck_5:8;
        RBus_UInt32  reg_p1_ck_6:8;
        RBus_UInt32  reg_p1_ck_7:8;
        RBus_UInt32  reg_p1_ck_8:8;
    };
}dfe_hdmi_rx_phy_p1_ck2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_ck_9:8;
        RBus_UInt32  reg_p1_ck_10:8;
        RBus_UInt32  reg_p1_ck_11:8;
        RBus_UInt32  reg_p1_ck_12:8;
    };
}dfe_hdmi_rx_phy_p1_ck3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_ck_13:8;
        RBus_UInt32  res1:24;
    };
}dfe_hdmi_rx_phy_p1_ck4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_g_1:8;
        RBus_UInt32  reg_p1_g_2:8;
        RBus_UInt32  reg_p1_g_3:8;
        RBus_UInt32  reg_p1_g_4:8;
    };
}dfe_hdmi_rx_phy_p1_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_g_5:8;
        RBus_UInt32  reg_p1_g_6:8;
        RBus_UInt32  reg_p1_g_7:8;
        RBus_UInt32  reg_p1_g_8:8;
    };
}dfe_hdmi_rx_phy_p1_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_g_9:8;
        RBus_UInt32  reg_p1_g_10:8;
        RBus_UInt32  reg_p1_g_11:8;
        RBus_UInt32  reg_p1_g_12:8;
    };
}dfe_hdmi_rx_phy_p1_g3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_g_13:8;
        RBus_UInt32  reg_p1_g_koffok:1;
        RBus_UInt32  reg_p1_g_koff_bound:1;
        RBus_UInt32  reg_p1_g_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p1_g4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_r_1:8;
        RBus_UInt32  reg_p1_r_2:8;
        RBus_UInt32  reg_p1_r_3:8;
        RBus_UInt32  reg_p1_r_4:8;
    };
}dfe_hdmi_rx_phy_p1_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_r_5:8;
        RBus_UInt32  reg_p1_r_6:8;
        RBus_UInt32  reg_p1_r_7:8;
        RBus_UInt32  reg_p1_r_8:8;
    };
}dfe_hdmi_rx_phy_p1_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_r_9:8;
        RBus_UInt32  reg_p1_r_10:8;
        RBus_UInt32  reg_p1_r_11:8;
        RBus_UInt32  reg_p1_r_12:8;
    };
}dfe_hdmi_rx_phy_p1_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_r_13:8;
        RBus_UInt32  reg_p1_r_koffok:1;
        RBus_UInt32  reg_p1_r_koff_bound:1;
        RBus_UInt32  reg_p1_r_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p1_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_acdr_1:8;
        RBus_UInt32  reg_p2_acdr_2:8;
        RBus_UInt32  reg_p2_acdr_3:8;
        RBus_UInt32  reg_p2_acdr_4:8;
    };
}dfe_hdmi_rx_phy_p2_acdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_acdr_5:8;
        RBus_UInt32  reg_p2_acdr_6:8;
        RBus_UInt32  reg_p2_acdr_7:8;
        RBus_UInt32  reg_p2_acdr_8:8;
    };
}dfe_hdmi_rx_phy_p2_acdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_b_1:8;
        RBus_UInt32  reg_p2_b_2:8;
        RBus_UInt32  reg_p2_b_3:8;
        RBus_UInt32  reg_p2_b_4:8;
    };
}dfe_hdmi_rx_phy_p2_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_b_5:8;
        RBus_UInt32  reg_p2_b_6:8;
        RBus_UInt32  reg_p2_b_7:8;
        RBus_UInt32  reg_p2_b_8:8;
    };
}dfe_hdmi_rx_phy_p2_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_b_9:8;
        RBus_UInt32  reg_p2_b_10:8;
        RBus_UInt32  reg_p2_b_11:8;
        RBus_UInt32  reg_p2_b_12:8;
    };
}dfe_hdmi_rx_phy_p2_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_b_13:8;
        RBus_UInt32  reg_p2_b_koffok:1;
        RBus_UInt32  reg_p2_b_koff_bound:1;
        RBus_UInt32  reg_p2_b_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p2_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_ck_1:8;
        RBus_UInt32  reg_p2_ck_2:8;
        RBus_UInt32  reg_p2_ck_3:8;
        RBus_UInt32  reg_p2_ck_4:8;
    };
}dfe_hdmi_rx_phy_p2_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_ck_5:8;
        RBus_UInt32  reg_p2_ck_6:8;
        RBus_UInt32  reg_p2_ck_7:8;
        RBus_UInt32  reg_p2_ck_8:8;
    };
}dfe_hdmi_rx_phy_p2_ck2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_ck_9:8;
        RBus_UInt32  reg_p2_ck_10:8;
        RBus_UInt32  reg_p2_ck_11:8;
        RBus_UInt32  reg_p2_ck_12:8;
    };
}dfe_hdmi_rx_phy_p2_ck3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_ck_13:8;
        RBus_UInt32  res1:24;
    };
}dfe_hdmi_rx_phy_p2_ck4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_g_1:8;
        RBus_UInt32  reg_p2_g_2:8;
        RBus_UInt32  reg_p2_g_3:8;
        RBus_UInt32  reg_p2_g_4:8;
    };
}dfe_hdmi_rx_phy_p2_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_g_5:8;
        RBus_UInt32  reg_p2_g_6:8;
        RBus_UInt32  reg_p2_g_7:8;
        RBus_UInt32  reg_p2_g_8:8;
    };
}dfe_hdmi_rx_phy_p2_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_g_9:8;
        RBus_UInt32  reg_p2_g_10:8;
        RBus_UInt32  reg_p2_g_11:8;
        RBus_UInt32  reg_p2_g_12:8;
    };
}dfe_hdmi_rx_phy_p2_g3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_g_13:8;
        RBus_UInt32  reg_p2_g_koffok:1;
        RBus_UInt32  reg_p2_g_koff_bound:1;
        RBus_UInt32  reg_p2_g_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p2_g4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_r_1:8;
        RBus_UInt32  reg_p2_r_2:8;
        RBus_UInt32  reg_p2_r_3:8;
        RBus_UInt32  reg_p2_r_4:8;
    };
}dfe_hdmi_rx_phy_p2_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_r_5:8;
        RBus_UInt32  reg_p2_r_6:8;
        RBus_UInt32  reg_p2_r_7:8;
        RBus_UInt32  reg_p2_r_8:8;
    };
}dfe_hdmi_rx_phy_p2_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_r_9:8;
        RBus_UInt32  reg_p2_r_10:8;
        RBus_UInt32  reg_p2_r_11:8;
        RBus_UInt32  reg_p2_r_12:8;
    };
}dfe_hdmi_rx_phy_p2_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_r_13:8;
        RBus_UInt32  reg_p2_r_koffok:1;
        RBus_UInt32  reg_p2_r_koff_bound:1;
        RBus_UInt32  reg_p2_r_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p2_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_acdr_1:8;
        RBus_UInt32  reg_p3_acdr_2:8;
        RBus_UInt32  reg_p3_acdr_3:8;
        RBus_UInt32  reg_p3_acdr_4:8;
    };
}dfe_hdmi_rx_phy_p3_acdr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_acdr_5:8;
        RBus_UInt32  reg_p3_acdr_6:8;
        RBus_UInt32  reg_p3_acdr_7:8;
        RBus_UInt32  reg_p3_acdr_8:8;
    };
}dfe_hdmi_rx_phy_p3_acdr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_b_1:8;
        RBus_UInt32  reg_p3_b_2:8;
        RBus_UInt32  reg_p3_b_3:8;
        RBus_UInt32  reg_p3_b_4:8;
    };
}dfe_hdmi_rx_phy_p3_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_b_5:8;
        RBus_UInt32  reg_p3_b_6:8;
        RBus_UInt32  reg_p3_b_7:8;
        RBus_UInt32  reg_p3_b_8:8;
    };
}dfe_hdmi_rx_phy_p3_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_b_9:8;
        RBus_UInt32  reg_p3_b_10:8;
        RBus_UInt32  reg_p3_b_11:8;
        RBus_UInt32  reg_p3_b_12:8;
    };
}dfe_hdmi_rx_phy_p3_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_b_13:8;
        RBus_UInt32  reg_p3_b_koffok:1;
        RBus_UInt32  reg_p3_b_koff_bound:1;
        RBus_UInt32  reg_p3_b_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p3_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_ck_1:8;
        RBus_UInt32  reg_p3_ck_2:8;
        RBus_UInt32  reg_p3_ck_3:8;
        RBus_UInt32  reg_p3_ck_4:8;
    };
}dfe_hdmi_rx_phy_p3_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_ck_5:8;
        RBus_UInt32  reg_p3_ck_6:8;
        RBus_UInt32  reg_p3_ck_7:8;
        RBus_UInt32  reg_p3_ck_8:8;
    };
}dfe_hdmi_rx_phy_p3_ck2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_ck_9:8;
        RBus_UInt32  reg_p3_ck_10:8;
        RBus_UInt32  reg_p3_ck_11:8;
        RBus_UInt32  reg_p3_ck_12:8;
    };
}dfe_hdmi_rx_phy_p3_ck3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_ck_13:8;
        RBus_UInt32  res1:24;
    };
}dfe_hdmi_rx_phy_p3_ck4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_g_1:8;
        RBus_UInt32  reg_p3_g_2:8;
        RBus_UInt32  reg_p3_g_3:8;
        RBus_UInt32  reg_p3_g_4:8;
    };
}dfe_hdmi_rx_phy_p3_g1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_g_5:8;
        RBus_UInt32  reg_p3_g_6:8;
        RBus_UInt32  reg_p3_g_7:8;
        RBus_UInt32  reg_p3_g_8:8;
    };
}dfe_hdmi_rx_phy_p3_g2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_g_9:8;
        RBus_UInt32  reg_p3_g_10:8;
        RBus_UInt32  reg_p3_g_11:8;
        RBus_UInt32  reg_p3_g_12:8;
    };
}dfe_hdmi_rx_phy_p3_g3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_g_13:8;
        RBus_UInt32  reg_p3_g_koffok:1;
        RBus_UInt32  reg_p3_g_koff_bound:1;
        RBus_UInt32  reg_p3_g_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p3_g4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_r_1:8;
        RBus_UInt32  reg_p3_r_2:8;
        RBus_UInt32  reg_p3_r_3:8;
        RBus_UInt32  reg_p3_r_4:8;
    };
}dfe_hdmi_rx_phy_p3_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_r_5:8;
        RBus_UInt32  reg_p3_r_6:8;
        RBus_UInt32  reg_p3_r_7:8;
        RBus_UInt32  reg_p3_r_8:8;
    };
}dfe_hdmi_rx_phy_p3_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_r_9:8;
        RBus_UInt32  reg_p3_r_10:8;
        RBus_UInt32  reg_p3_r_11:8;
        RBus_UInt32  reg_p3_r_12:8;
    };
}dfe_hdmi_rx_phy_p3_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_r_13:8;
        RBus_UInt32  reg_p3_r_koffok:1;
        RBus_UInt32  reg_p3_r_koff_bound:1;
        RBus_UInt32  reg_p3_r_koff_sel:5;
        RBus_UInt32  res1:17;
    };
}dfe_hdmi_rx_phy_p3_r4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_eye_pi_en:4;
        RBus_UInt32  reg_eye_ref_ctrl:6;
        RBus_UInt32  res1:22;
    };
}dfe_hdmi_rx_phy_eye1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_eye_pi_st:32;
    };
}dfe_hdmi_rx_phy_eye2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_bypass_ok:1;
        RBus_UInt32  p1_bypass_ok:1;
        RBus_UInt32  p2_bypass_ok:1;
        RBus_UInt32  p3_bypass_ok:1;
        RBus_UInt32  res1:28;
    };
}dfe_hdmi_rx_phy_bypass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_b_demux_rstb:1;
        RBus_UInt32  p0_g_demux_rstb:1;
        RBus_UInt32  p0_r_demux_rstb:1;
        RBus_UInt32  p1_b_demux_rstb:1;
        RBus_UInt32  p1_g_demux_rstb:1;
        RBus_UInt32  p1_r_demux_rstb:1;
        RBus_UInt32  p2_b_demux_rstb:1;
        RBus_UInt32  p2_g_demux_rstb:1;
        RBus_UInt32  p2_r_demux_rstb:1;
        RBus_UInt32  p3_b_demux_rstb:1;
        RBus_UInt32  p3_g_demux_rstb:1;
        RBus_UInt32  p3_r_demux_rstb:1;
        RBus_UInt32  p0_ck_pllrstb:1;
        RBus_UInt32  p1_ck_pllrstb:1;
        RBus_UInt32  p2_ck_pllrstb:1;
        RBus_UInt32  p3_ck_pllrstb:1;
        RBus_UInt32  p0_ck_vcorstb:1;
        RBus_UInt32  p1_ck_vcorstb:1;
        RBus_UInt32  p2_ck_vcorstb:1;
        RBus_UInt32  p3_ck_vcorstb:1;
        RBus_UInt32  reg_p0_acdr_rstb_fsm:1;
        RBus_UInt32  reg_p1_acdr_rstb_fsm:1;
        RBus_UInt32  reg_p2_acdr_rstb_fsm:1;
        RBus_UInt32  reg_p3_acdr_rstb_fsm:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  eye_monitor_rstn:1;
        RBus_UInt32  res2:6;
    };
}dfe_hdmi_rx_phy_rst_RBUS;

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
}dfe_hdmi_rx_phy_regd0_RBUS;

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
}dfe_hdmi_rx_phy_regd1_RBUS;

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
}dfe_hdmi_rx_phy_regd2_RBUS;

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
}dfe_hdmi_rx_phy_regd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p0_er_count_b:10;
        RBus_UInt32  p0_er_count_g:10;
        RBus_UInt32  p0_er_count_r:10;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_infifo_cnt:3;
        RBus_UInt32  reg_p1_data_order:1;
        RBus_UInt32  reg_p1_bypass_sdm_int:1;
        RBus_UInt32  reg_p1_ki:3;
        RBus_UInt32  reg_p1_kp:8;
        RBus_UInt32  reg_p1_kd:1;
        RBus_UInt32  reg_p1_rate_sel:3;
        RBus_UInt32  reg_p1_shift_inv_b:1;
        RBus_UInt32  reg_p1_shift_inv_g:1;
        RBus_UInt32  reg_p1_shift_inv_r:1;
        RBus_UInt32  reg_p1_cdr_ckinv_b:1;
        RBus_UInt32  reg_p1_cdr_ckinv_g:1;
        RBus_UInt32  reg_p1_cdr_ckinv_r:1;
        RBus_UInt32  p1_b_cdr_rst_n:1;
        RBus_UInt32  p1_g_cdr_rst_n:1;
        RBus_UInt32  p1_r_cdr_rst_n:1;
        RBus_UInt32  p1_b_dig_rst_n:1;
        RBus_UInt32  p1_g_dig_rst_n:1;
        RBus_UInt32  p1_r_dig_rst_n:1;
    };
}dfe_hdmi_rx_phy_regd5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_dyn_kp_en:1;
        RBus_UInt32  reg_p1_pi_m_mode:1;
        RBus_UInt32  reg_p1_edge_out:1;
        RBus_UInt32  reg_p1_ercnt_en:1;
        RBus_UInt32  reg_p1_testout_sel:2;
        RBus_UInt32  reg_p1_acc2_manual:1;
        RBus_UInt32  reg_p1_squ_tri:1;
        RBus_UInt32  reg_p1_acc2_period:10;
        RBus_UInt32  reg_p1_int_init:14;
    };
}dfe_hdmi_rx_phy_regd6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_p1_timer_ber:5;
        RBus_UInt32  reg_p1_timer_eq:5;
        RBus_UInt32  reg_p1_timer_lpf:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  reg_p1_st_mode:1;
        RBus_UInt32  reg_p1_en_m_value:4;
    };
}dfe_hdmi_rx_phy_regd7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_en_ro_b:4;
        RBus_UInt32  p1_st_ro_b:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  p1_en_ro_g:4;
        RBus_UInt32  p1_st_ro_g:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  p1_en_ro_r:4;
        RBus_UInt32  p1_st_ro_r:5;
        RBus_UInt32  res3:3;
    };
}dfe_hdmi_rx_phy_regd8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_er_count_b:10;
        RBus_UInt32  p1_er_count_g:10;
        RBus_UInt32  p1_er_count_r:10;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_infifo_cnt:3;
        RBus_UInt32  reg_p2_data_order:1;
        RBus_UInt32  reg_p2_bypass_sdm_int:1;
        RBus_UInt32  reg_p2_ki:3;
        RBus_UInt32  reg_p2_kp:8;
        RBus_UInt32  reg_p2_kd:1;
        RBus_UInt32  reg_p2_rate_sel:3;
        RBus_UInt32  reg_p2_shift_inv_b:1;
        RBus_UInt32  reg_p2_shift_inv_g:1;
        RBus_UInt32  reg_p2_shift_inv_r:1;
        RBus_UInt32  reg_p2_cdr_ckinv_b:1;
        RBus_UInt32  reg_p2_cdr_ckinv_g:1;
        RBus_UInt32  reg_p2_cdr_ckinv_r:1;
        RBus_UInt32  p2_b_cdr_rst_n:1;
        RBus_UInt32  p2_g_cdr_rst_n:1;
        RBus_UInt32  p2_r_cdr_rst_n:1;
        RBus_UInt32  p2_b_dig_rst_n:1;
        RBus_UInt32  p2_g_dig_rst_n:1;
        RBus_UInt32  p2_r_dig_rst_n:1;
    };
}dfe_hdmi_rx_phy_regd10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_dyn_kp_en:1;
        RBus_UInt32  reg_p2_pi_m_mode:1;
        RBus_UInt32  reg_p2_edge_out:1;
        RBus_UInt32  reg_p2_ercnt_en:1;
        RBus_UInt32  reg_p2_testout_sel:2;
        RBus_UInt32  reg_p2_acc2_manual:1;
        RBus_UInt32  reg_p2_squ_tri:1;
        RBus_UInt32  reg_p2_acc2_period:10;
        RBus_UInt32  reg_p2_int_init:14;
    };
}dfe_hdmi_rx_phy_regd11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_p2_timer_ber:5;
        RBus_UInt32  reg_p2_timer_eq:5;
        RBus_UInt32  reg_p2_timer_lpf:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  reg_p2_st_mode:1;
        RBus_UInt32  reg_p2_en_m_value:4;
    };
}dfe_hdmi_rx_phy_regd12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_en_ro_b:4;
        RBus_UInt32  p2_st_ro_b:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  p2_en_ro_g:4;
        RBus_UInt32  p2_st_ro_g:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  p2_en_ro_r:4;
        RBus_UInt32  p2_st_ro_r:5;
        RBus_UInt32  res3:3;
    };
}dfe_hdmi_rx_phy_regd13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_er_count_b:10;
        RBus_UInt32  p2_er_count_g:10;
        RBus_UInt32  p2_er_count_r:10;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_infifo_cnt:3;
        RBus_UInt32  reg_p3_data_order:1;
        RBus_UInt32  reg_p3_bypass_sdm_int:1;
        RBus_UInt32  reg_p3_ki:3;
        RBus_UInt32  reg_p3_kp:8;
        RBus_UInt32  reg_p3_kd:1;
        RBus_UInt32  reg_p3_rate_sel:3;
        RBus_UInt32  reg_p3_shift_inv_b:1;
        RBus_UInt32  reg_p3_shift_inv_g:1;
        RBus_UInt32  reg_p3_shift_inv_r:1;
        RBus_UInt32  reg_p3_cdr_ckinv_b:1;
        RBus_UInt32  reg_p3_cdr_ckinv_g:1;
        RBus_UInt32  reg_p3_cdr_ckinv_r:1;
        RBus_UInt32  p3_b_cdr_rst_n:1;
        RBus_UInt32  p3_g_cdr_rst_n:1;
        RBus_UInt32  p3_r_cdr_rst_n:1;
        RBus_UInt32  p3_b_dig_rst_n:1;
        RBus_UInt32  p3_g_dig_rst_n:1;
        RBus_UInt32  p3_r_dig_rst_n:1;
    };
}dfe_hdmi_rx_phy_regd15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_dyn_kp_en:1;
        RBus_UInt32  reg_p3_pi_m_mode:1;
        RBus_UInt32  reg_p3_edge_out:1;
        RBus_UInt32  reg_p3_ercnt_en:1;
        RBus_UInt32  reg_p3_testout_sel:2;
        RBus_UInt32  reg_p3_acc2_manual:1;
        RBus_UInt32  reg_p3_squ_tri:1;
        RBus_UInt32  reg_p3_acc2_period:10;
        RBus_UInt32  reg_p3_int_init:14;
    };
}dfe_hdmi_rx_phy_regd16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_p3_timer_ber:5;
        RBus_UInt32  reg_p3_timer_eq:5;
        RBus_UInt32  reg_p3_timer_lpf:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  reg_p3_st_mode:1;
        RBus_UInt32  reg_p3_en_m_value:4;
    };
}dfe_hdmi_rx_phy_regd17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_en_ro_b:4;
        RBus_UInt32  p3_st_ro_b:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  p3_en_ro_g:4;
        RBus_UInt32  p3_st_ro_g:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  p3_en_ro_r:4;
        RBus_UInt32  p3_st_ro_r:5;
        RBus_UInt32  res3:3;
    };
}dfe_hdmi_rx_phy_regd18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_er_count_b:10;
        RBus_UInt32  p3_er_count_g:10;
        RBus_UInt32  p3_er_count_r:10;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_regd19_RBUS;

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
}dfe_hdmi_rx_phy_regd20_RBUS;

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
}dfe_hdmi_rx_phy_regd21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_wdog_rst_n:1;
        RBus_UInt32  p1_pll_wd_rst_wc:1;
        RBus_UInt32  p1_pll_wd_ckrdy_ro:1;
        RBus_UInt32  reg_p1_en_data_manual_l0:1;
        RBus_UInt32  reg_p1_en_eqen_manual_l0:1;
        RBus_UInt32  reg_p1_bypass_data_rdy_l0:1;
        RBus_UInt32  reg_p1_bypass_eqen_rdy_l0:1;
        RBus_UInt32  reg_p1_acdr_l0_en:1;
        RBus_UInt32  reg_p1_pll_wd_time_rdy:2;
        RBus_UInt32  reg_p1_pll_wd_rst_wid:2;
        RBus_UInt32  reg_p1_pll_wd_en:1;
        RBus_UInt32  reg_p1_pll_wd_base_time:3;
        RBus_UInt32  reg_p1_order:1;
        RBus_UInt32  reg_p1_eqen_rdy_time:4;
        RBus_UInt32  reg_p1_en_data_manual:1;
        RBus_UInt32  reg_p1_en_eqen_manual:1;
        RBus_UInt32  reg_p1_en_clkout_manual:1;
        RBus_UInt32  reg_p1_data_rdy_time:4;
        RBus_UInt32  reg_p1_bypass_pi:1;
        RBus_UInt32  reg_p1_bypass_data_rdy:1;
        RBus_UInt32  reg_p1_bypass_eqen_rdy:1;
        RBus_UInt32  reg_p1_bypass_clk_rdy:1;
    };
}dfe_hdmi_rx_phy_regd22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_n_code:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_p1_f_code:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_p1_wd_sdm_en:1;
    };
}dfe_hdmi_rx_phy_regd23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_wdog_rst_n:1;
        RBus_UInt32  p2_pll_wd_rst_wc:1;
        RBus_UInt32  p2_pll_wd_ckrdy_ro:1;
        RBus_UInt32  reg_p2_en_data_manual_l0:1;
        RBus_UInt32  reg_p2_en_eqen_manual_l0:1;
        RBus_UInt32  reg_p2_bypass_data_rdy_l0:1;
        RBus_UInt32  reg_p2_bypass_eqen_rdy_l0:1;
        RBus_UInt32  reg_p2_acdr_l0_en:1;
        RBus_UInt32  reg_p2_pll_wd_time_rdy:2;
        RBus_UInt32  reg_p2_pll_wd_rst_wid:2;
        RBus_UInt32  reg_p2_pll_wd_en:1;
        RBus_UInt32  reg_p2_pll_wd_base_time:3;
        RBus_UInt32  reg_p2_order:1;
        RBus_UInt32  reg_p2_eqen_rdy_time:4;
        RBus_UInt32  reg_p2_en_data_manual:1;
        RBus_UInt32  reg_p2_en_eqen_manual:1;
        RBus_UInt32  reg_p2_en_clkout_manual:1;
        RBus_UInt32  reg_p2_data_rdy_time:4;
        RBus_UInt32  reg_p2_bypass_pi:1;
        RBus_UInt32  reg_p2_bypass_data_rdy:1;
        RBus_UInt32  reg_p2_bypass_eqen_rdy:1;
        RBus_UInt32  reg_p2_bypass_clk_rdy:1;
    };
}dfe_hdmi_rx_phy_regd24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_n_code:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_p2_f_code:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_p2_wd_sdm_en:1;
    };
}dfe_hdmi_rx_phy_regd25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_wdog_rst_n:1;
        RBus_UInt32  p3_pll_wd_rst_wc:1;
        RBus_UInt32  p3_pll_wd_ckrdy_ro:1;
        RBus_UInt32  reg_p3_en_data_manual_l0:1;
        RBus_UInt32  reg_p3_en_eqen_manual_l0:1;
        RBus_UInt32  reg_p3_bypass_data_rdy_l0:1;
        RBus_UInt32  reg_p3_bypass_eqen_rdy_l0:1;
        RBus_UInt32  reg_p3_acdr_l0_en:1;
        RBus_UInt32  reg_p3_pll_wd_time_rdy:2;
        RBus_UInt32  reg_p3_pll_wd_rst_wid:2;
        RBus_UInt32  reg_p3_pll_wd_en:1;
        RBus_UInt32  reg_p3_pll_wd_base_time:3;
        RBus_UInt32  reg_p3_order:1;
        RBus_UInt32  reg_p3_eqen_rdy_time:4;
        RBus_UInt32  reg_p3_en_data_manual:1;
        RBus_UInt32  reg_p3_en_eqen_manual:1;
        RBus_UInt32  reg_p3_en_clkout_manual:1;
        RBus_UInt32  reg_p3_data_rdy_time:4;
        RBus_UInt32  reg_p3_bypass_pi:1;
        RBus_UInt32  reg_p3_bypass_data_rdy:1;
        RBus_UInt32  reg_p3_bypass_eqen_rdy:1;
        RBus_UInt32  reg_p3_bypass_clk_rdy:1;
    };
}dfe_hdmi_rx_phy_regd26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_n_code:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_p3_f_code:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_p3_wd_sdm_en:1;
    };
}dfe_hdmi_rx_phy_regd27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p0_init_time:3;
        RBus_UInt32  reg_p0_divide_num:7;
        RBus_UInt32  reg_p0_vco_coarse:7;
        RBus_UInt32  reg_p0_calib_late:1;
        RBus_UInt32  reg_p0_calib_manual:1;
        RBus_UInt32  reg_p0_calib_time:3;
        RBus_UInt32  reg_p0_adp_time:5;
        RBus_UInt32  reg_p0_adap_eq_off:1;
        RBus_UInt32  reg_p0_cp_en_manual:1;
        RBus_UInt32  reg_p0_adp_en_manual:1;
        RBus_UInt32  reg_p0_auto_mode:1;
    };
}dfe_hdmi_rx_phy_regd28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_lock_dn_limit:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  reg_p0_lock_up_limit:11;
        RBus_UInt32  res2:5;
    };
}dfe_hdmi_rx_phy_regd29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p0_calib_reset_sel:1;
        RBus_UInt32  reg_p0_vc_sel:2;
        RBus_UInt32  reg_p0_cdr_c:2;
        RBus_UInt32  reg_p0_cdr_r:6;
        RBus_UInt32  reg_p0_cdr_cp:20;
    };
}dfe_hdmi_rx_phy_regd30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_timer_4:5;
        RBus_UInt32  reg_p0_cp_time:5;
        RBus_UInt32  reg_p0_slope_lv_dn:11;
        RBus_UInt32  reg_p0_slope_lv_up:11;
    };
}dfe_hdmi_rx_phy_regd31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_p0_timer_6:5;
        RBus_UInt32  reg_p0_timer_5:1;
        RBus_UInt32  reg_p0_slope_hv_dn:11;
        RBus_UInt32  reg_p0_slope_hv_up:11;
    };
}dfe_hdmi_rx_phy_regd32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_p0_old_mode:1;
        RBus_UInt32  reg_p0_slope_band:5;
        RBus_UInt32  reg_p0_slope_manual:1;
        RBus_UInt32  reg_p0_rxidle_bypass:1;
        RBus_UInt32  reg_p0_pfd_bypass:1;
        RBus_UInt32  reg_p0_pfd_time:5;
        RBus_UInt32  reg_p0_pfd_en_manual:1;
        RBus_UInt32  reg_p0_start_en_manual:1;
    };
}dfe_hdmi_rx_phy_regd33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p0_slope_final_reg:5;
        RBus_UInt32  p0_slope_hv_reg:5;
        RBus_UInt32  p0_slope_lv_reg:5;
        RBus_UInt32  p0_pfd_en_fsm_reg:1;
        RBus_UInt32  p0_coarse_fsm_reg:7;
        RBus_UInt32  p0_cp_en_fsm_reg:1;
        RBus_UInt32  p0_adp_en_fsm_reg:1;
        RBus_UInt32  p0_fld_st_reg:5;
    };
}dfe_hdmi_rx_phy_regd34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p1_init_time:3;
        RBus_UInt32  reg_p1_divide_num:7;
        RBus_UInt32  reg_p1_vco_coarse:7;
        RBus_UInt32  reg_p1_calib_late:1;
        RBus_UInt32  reg_p1_calib_manual:1;
        RBus_UInt32  reg_p1_calib_time:3;
        RBus_UInt32  reg_p1_adp_time:5;
        RBus_UInt32  reg_p1_adap_eq_off:1;
        RBus_UInt32  reg_p1_cp_en_manual:1;
        RBus_UInt32  reg_p1_adp_en_manual:1;
        RBus_UInt32  reg_p1_auto_mode:1;
    };
}dfe_hdmi_rx_phy_regd35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_lock_dn_limit:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  reg_p1_lock_up_limit:11;
        RBus_UInt32  res2:5;
    };
}dfe_hdmi_rx_phy_regd36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p1_calib_reset_sel:1;
        RBus_UInt32  reg_p1_vc_sel:2;
        RBus_UInt32  reg_p1_cdr_c:2;
        RBus_UInt32  reg_p1_cdr_r:6;
        RBus_UInt32  reg_p1_cdr_cp:20;
    };
}dfe_hdmi_rx_phy_regd37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_timer_4:5;
        RBus_UInt32  reg_p1_cp_time:5;
        RBus_UInt32  reg_p1_slope_lv_dn:11;
        RBus_UInt32  reg_p1_slope_lv_up:11;
    };
}dfe_hdmi_rx_phy_regd38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_p1_timer_6:5;
        RBus_UInt32  reg_p1_timer_5:1;
        RBus_UInt32  reg_p1_slope_hv_dn:11;
        RBus_UInt32  reg_p1_slope_hv_up:11;
    };
}dfe_hdmi_rx_phy_regd39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_p1_old_mode:1;
        RBus_UInt32  reg_p1_slope_band:5;
        RBus_UInt32  reg_p1_slope_manual:1;
        RBus_UInt32  reg_p1_rxidle_bypass:1;
        RBus_UInt32  reg_p1_pfd_bypass:1;
        RBus_UInt32  reg_p1_pfd_time:5;
        RBus_UInt32  reg_p1_pfd_en_manual:1;
        RBus_UInt32  reg_p1_start_en_manual:1;
    };
}dfe_hdmi_rx_phy_regd40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p1_slope_final_reg:5;
        RBus_UInt32  p1_slope_hv_reg:5;
        RBus_UInt32  p1_slope_lv_reg:5;
        RBus_UInt32  p1_pfd_en_fsm_reg:1;
        RBus_UInt32  p1_coarse_fsm_reg:7;
        RBus_UInt32  p1_cp_en_fsm_reg:1;
        RBus_UInt32  p1_adp_en_fsm_reg:1;
        RBus_UInt32  p1_fld_st_reg:5;
    };
}dfe_hdmi_rx_phy_regd41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p2_init_time:3;
        RBus_UInt32  reg_p2_divide_num:7;
        RBus_UInt32  reg_p2_vco_coarse:7;
        RBus_UInt32  reg_p2_calib_late:1;
        RBus_UInt32  reg_p2_calib_manual:1;
        RBus_UInt32  reg_p2_calib_time:3;
        RBus_UInt32  reg_p2_adp_time:5;
        RBus_UInt32  reg_p2_adap_eq_off:1;
        RBus_UInt32  reg_p2_cp_en_manual:1;
        RBus_UInt32  reg_p2_adp_en_manual:1;
        RBus_UInt32  reg_p2_auto_mode:1;
    };
}dfe_hdmi_rx_phy_regd42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_lock_dn_limit:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  reg_p2_lock_up_limit:11;
        RBus_UInt32  res2:5;
    };
}dfe_hdmi_rx_phy_regd43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p2_calib_reset_sel:1;
        RBus_UInt32  reg_p2_vc_sel:2;
        RBus_UInt32  reg_p2_cdr_c:2;
        RBus_UInt32  reg_p2_cdr_r:6;
        RBus_UInt32  reg_p2_cdr_cp:20;
    };
}dfe_hdmi_rx_phy_regd44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_timer_4:5;
        RBus_UInt32  reg_p2_cp_time:5;
        RBus_UInt32  reg_p2_slope_lv_dn:11;
        RBus_UInt32  reg_p2_slope_lv_up:11;
    };
}dfe_hdmi_rx_phy_regd45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_p2_timer_6:5;
        RBus_UInt32  reg_p2_timer_5:1;
        RBus_UInt32  reg_p2_slope_hv_dn:11;
        RBus_UInt32  reg_p2_slope_hv_up:11;
    };
}dfe_hdmi_rx_phy_regd46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_p2_old_mode:1;
        RBus_UInt32  reg_p2_slope_band:5;
        RBus_UInt32  reg_p2_slope_manual:1;
        RBus_UInt32  reg_p2_rxidle_bypass:1;
        RBus_UInt32  reg_p2_pfd_bypass:1;
        RBus_UInt32  reg_p2_pfd_time:5;
        RBus_UInt32  reg_p2_pfd_en_manual:1;
        RBus_UInt32  reg_p2_start_en_manual:1;
    };
}dfe_hdmi_rx_phy_regd47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p2_slope_final_reg:5;
        RBus_UInt32  p2_slope_hv_reg:5;
        RBus_UInt32  p2_slope_lv_reg:5;
        RBus_UInt32  p2_pfd_en_fsm_reg:1;
        RBus_UInt32  p2_coarse_fsm_reg:7;
        RBus_UInt32  p2_cp_en_fsm_reg:1;
        RBus_UInt32  p2_adp_en_fsm_reg:1;
        RBus_UInt32  p2_fld_st_reg:5;
    };
}dfe_hdmi_rx_phy_regd48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p3_init_time:3;
        RBus_UInt32  reg_p3_divide_num:7;
        RBus_UInt32  reg_p3_vco_coarse:7;
        RBus_UInt32  reg_p3_calib_late:1;
        RBus_UInt32  reg_p3_calib_manual:1;
        RBus_UInt32  reg_p3_calib_time:3;
        RBus_UInt32  reg_p3_adp_time:5;
        RBus_UInt32  reg_p3_adap_eq_off:1;
        RBus_UInt32  reg_p3_cp_en_manual:1;
        RBus_UInt32  reg_p3_adp_en_manual:1;
        RBus_UInt32  reg_p3_auto_mode:1;
    };
}dfe_hdmi_rx_phy_regd49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_lock_dn_limit:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  reg_p3_lock_up_limit:11;
        RBus_UInt32  res2:5;
    };
}dfe_hdmi_rx_phy_regd50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p3_calib_reset_sel:1;
        RBus_UInt32  reg_p3_vc_sel:2;
        RBus_UInt32  reg_p3_cdr_c:2;
        RBus_UInt32  reg_p3_cdr_r:6;
        RBus_UInt32  reg_p3_cdr_cp:20;
    };
}dfe_hdmi_rx_phy_regd51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_timer_4:5;
        RBus_UInt32  reg_p3_cp_time:5;
        RBus_UInt32  reg_p3_slope_lv_dn:11;
        RBus_UInt32  reg_p3_slope_lv_up:11;
    };
}dfe_hdmi_rx_phy_regd52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_p3_timer_6:5;
        RBus_UInt32  reg_p3_timer_5:1;
        RBus_UInt32  reg_p3_slope_hv_dn:11;
        RBus_UInt32  reg_p3_slope_hv_up:11;
    };
}dfe_hdmi_rx_phy_regd53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_p3_old_mode:1;
        RBus_UInt32  reg_p3_slope_band:5;
        RBus_UInt32  reg_p3_slope_manual:1;
        RBus_UInt32  reg_p3_rxidle_bypass:1;
        RBus_UInt32  reg_p3_pfd_bypass:1;
        RBus_UInt32  reg_p3_pfd_time:5;
        RBus_UInt32  reg_p3_pfd_en_manual:1;
        RBus_UInt32  reg_p3_start_en_manual:1;
    };
}dfe_hdmi_rx_phy_regd54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p3_slope_final_reg:5;
        RBus_UInt32  p3_slope_hv_reg:5;
        RBus_UInt32  p3_slope_lv_reg:5;
        RBus_UInt32  p3_pfd_en_fsm_reg:1;
        RBus_UInt32  p3_coarse_fsm_reg:7;
        RBus_UInt32  p3_cp_en_fsm_reg:1;
        RBus_UInt32  p3_adp_en_fsm_reg:1;
        RBus_UInt32  p3_fld_st_reg:5;
    };
}dfe_hdmi_rx_phy_regd55_RBUS;

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
}dfe_hdmi_rx_phy_regd56_RBUS;

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
}dfe_hdmi_rx_phy_regd57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_p1_ck_md_reserved:4;
        RBus_UInt32  reg_p1_ck_error_limit:5;
        RBus_UInt32  reg_p1_ck_md_adj:4;
        RBus_UInt32  reg_p1_ck_md_auto:1;
        RBus_UInt32  reg_p1_ck_md_sel:2;
        RBus_UInt32  reg_p1_ck_md_debounce:7;
        RBus_UInt32  reg_p1_ck_md_threshold:6;
        RBus_UInt32  p1_ck_md_rstb:1;
    };
}dfe_hdmi_rx_phy_regd58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  p1_clock_unstable_flag:1;
        RBus_UInt32  p1_ck_md_ok:1;
        RBus_UInt32  p1_unstable_count:5;
        RBus_UInt32  p1_ck_rate:4;
        RBus_UInt32  p1_ck_md_count:13;
    };
}dfe_hdmi_rx_phy_regd59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_p2_ck_md_reserved:4;
        RBus_UInt32  reg_p2_ck_error_limit:5;
        RBus_UInt32  reg_p2_ck_md_adj:4;
        RBus_UInt32  reg_p2_ck_md_auto:1;
        RBus_UInt32  reg_p2_ck_md_sel:2;
        RBus_UInt32  reg_p2_ck_md_debounce:7;
        RBus_UInt32  reg_p2_ck_md_threshold:6;
        RBus_UInt32  p2_ck_md_rstb:1;
    };
}dfe_hdmi_rx_phy_regd60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  p2_clock_unstable_flag:1;
        RBus_UInt32  p2_ck_md_ok:1;
        RBus_UInt32  p2_unstable_count:5;
        RBus_UInt32  p2_ck_rate:4;
        RBus_UInt32  p2_ck_md_count:13;
    };
}dfe_hdmi_rx_phy_regd61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_p3_ck_md_reserved:4;
        RBus_UInt32  reg_p3_ck_error_limit:5;
        RBus_UInt32  reg_p3_ck_md_adj:4;
        RBus_UInt32  reg_p3_ck_md_auto:1;
        RBus_UInt32  reg_p3_ck_md_sel:2;
        RBus_UInt32  reg_p3_ck_md_debounce:7;
        RBus_UInt32  reg_p3_ck_md_threshold:6;
        RBus_UInt32  p3_ck_md_rstb:1;
    };
}dfe_hdmi_rx_phy_regd62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  p3_clock_unstable_flag:1;
        RBus_UInt32  p3_ck_md_ok:1;
        RBus_UInt32  p3_unstable_count:5;
        RBus_UInt32  p3_ck_rate:4;
        RBus_UInt32  p3_ck_md_count:13;
    };
}dfe_hdmi_rx_phy_regd63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dig_reserved_3:8;
        RBus_UInt32  reg_dig_reserved_2:8;
        RBus_UInt32  reg_dig_reserved_1:8;
        RBus_UInt32  reg_dig_reserved_0:8;
    };
}dfe_hdmi_rx_phy_regd64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  reg_dig_debug_sel:5;
    };
}dfe_hdmi_rx_phy_regd65_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value:32;
    };
}dfe_hdmi_rx_phy_regd66_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value:32;
    };
}dfe_hdmi_rx_phy_regd67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_st_m_value:32;
    };
}dfe_hdmi_rx_phy_regd68_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_st_m_value:32;
    };
}dfe_hdmi_rx_phy_regd69_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eye_monitor_dout:16;
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_eye_monitor_ck_sel:2;
        RBus_UInt32  res2:10;
    };
}dfe_hdmi_rx_phy_regd70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_regd71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_regd72_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_regd73_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_regd74_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p0_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_regd75_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_regd76_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p2_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_regd77_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p3_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_regd78_RBUS;

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
}dfe_hdmi_rx_phy_regd79_RBUS;

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
}dfe_hdmi_rx_phy_regd80_RBUS;

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
}dfe_hdmi_rx_phy_regd81_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_err_count_r:8;
        RBus_UInt32  p1_pkt_count_r:8;
        RBus_UInt32  reg_p1_pattern_sel_r:1;
        RBus_UInt32  reg_p1_prbs_invs_r:1;
        RBus_UInt32  reg_p1_enable_one_zero_r:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_regd82_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_err_count_g:8;
        RBus_UInt32  p1_pkt_count_g:8;
        RBus_UInt32  reg_p1_pattern_sel_g:1;
        RBus_UInt32  reg_p1_prbs_invs_g:1;
        RBus_UInt32  reg_p1_enable_one_zero_g:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_regd83_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_err_count_b:8;
        RBus_UInt32  p1_pkt_count_b:8;
        RBus_UInt32  reg_p1_pattern_sel_b:1;
        RBus_UInt32  reg_p1_prbs_invs_b:1;
        RBus_UInt32  reg_p1_enable_one_zero_b:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_regd84_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_err_count_r:8;
        RBus_UInt32  p2_pkt_count_r:8;
        RBus_UInt32  reg_p2_pattern_sel_r:1;
        RBus_UInt32  reg_p2_prbs_invs_r:1;
        RBus_UInt32  reg_p2_enable_one_zero_r:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_regd85_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_err_count_g:8;
        RBus_UInt32  p2_pkt_count_g:8;
        RBus_UInt32  reg_p2_pattern_sel_g:1;
        RBus_UInt32  reg_p2_prbs_invs_g:1;
        RBus_UInt32  reg_p2_enable_one_zero_g:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_regd86_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p2_err_count_b:8;
        RBus_UInt32  p2_pkt_count_b:8;
        RBus_UInt32  reg_p2_pattern_sel_b:1;
        RBus_UInt32  reg_p2_prbs_invs_b:1;
        RBus_UInt32  reg_p2_enable_one_zero_b:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_regd87_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_err_count_r:8;
        RBus_UInt32  p3_pkt_count_r:8;
        RBus_UInt32  reg_p3_pattern_sel_r:1;
        RBus_UInt32  reg_p3_prbs_invs_r:1;
        RBus_UInt32  reg_p3_enable_one_zero_r:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_regd88_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_err_count_g:8;
        RBus_UInt32  p3_pkt_count_g:8;
        RBus_UInt32  reg_p3_pattern_sel_g:1;
        RBus_UInt32  reg_p3_prbs_invs_g:1;
        RBus_UInt32  reg_p3_enable_one_zero_g:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_regd89_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p3_err_count_b:8;
        RBus_UInt32  p3_pkt_count_b:8;
        RBus_UInt32  reg_p3_pattern_sel_b:1;
        RBus_UInt32  reg_p3_prbs_invs_b:1;
        RBus_UInt32  reg_p3_enable_one_zero_b:1;
        RBus_UInt32  res1:13;
    };
}dfe_hdmi_rx_phy_regd90_RBUS;




#endif 


#endif 
