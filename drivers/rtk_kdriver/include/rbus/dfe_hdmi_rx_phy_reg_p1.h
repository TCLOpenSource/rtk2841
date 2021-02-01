/**
* @file rbusDFE_HDMI_RX_PHYReg_P1.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DFE_HDMI_RX_PHY_REG_P1_H_
#define _RBUS_DFE_HDMI_RX_PHY_REG_P1_H_

#include "rbus_types.h"



//  DFE_HDMI_RX_PHY Register Address
#define  DFE_HDMI_RX_PHY_P1_LDO                                                  0x1800DB08
#define  DFE_HDMI_RX_PHY_P1_LDO_reg_addr                                         "0xB800DB08"
#define  DFE_HDMI_RX_PHY_P1_LDO_reg                                              0xB800DB08
#define  DFE_HDMI_RX_PHY_P1_LDO_inst_addr                                        "0x0000"
#define  set_DFE_HDMI_RX_PHY_P1_LDO_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_LDO_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_LDO_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_LDO_reg))
#define  DFE_HDMI_RX_PHY_P1_LDO_reg_p1_ldo_sel_shift                             (4)
#define  DFE_HDMI_RX_PHY_P1_LDO_reg_p1_ldo_pow_shift                             (0)
#define  DFE_HDMI_RX_PHY_P1_LDO_reg_p1_ldo_sel_mask                              (0x00000030)
#define  DFE_HDMI_RX_PHY_P1_LDO_reg_p1_ldo_pow_mask                              (0x00000001)
#define  DFE_HDMI_RX_PHY_P1_LDO_reg_p1_ldo_sel(data)                             (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_P1_LDO_reg_p1_ldo_pow(data)                             (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_P1_LDO_get_reg_p1_ldo_sel(data)                         ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_P1_LDO_get_reg_p1_ldo_pow(data)                         (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_P1_MHL                                                  0x1800DB0C
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_addr                                         "0xB800DB0C"
#define  DFE_HDMI_RX_PHY_P1_MHL_reg                                              0xB800DB0C
#define  DFE_HDMI_RX_PHY_P1_MHL_inst_addr                                        "0x0001"
#define  set_DFE_HDMI_RX_PHY_P1_MHL_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_MHL_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_MHL_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_MHL_reg))
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_hdmi_datasel_shift                    (6)
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_hdmi_cksel_shift                      (5)
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_pow_shift                             (1)
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_hdmi_datasel_mask                     (0x00000040)
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_hdmi_cksel_mask                       (0x00000020)
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_pow_mask                              (0x00000002)
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_hdmi_datasel(data)                    (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_hdmi_cksel(data)                      (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_P1_MHL_reg_p1_mhl_pow(data)                             (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_P1_MHL_get_reg_p1_mhl_hdmi_datasel(data)                ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_P1_MHL_get_reg_p1_mhl_hdmi_cksel(data)                  ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_P1_MHL_get_reg_p1_mhl_pow(data)                         ((0x00000002&(data))>>1)

#define  DFE_HDMI_RX_PHY_P1_ENABLE                                               0x1800DB10
#define  DFE_HDMI_RX_PHY_P1_ENABLE_reg_addr                                      "0xB800DB10"
#define  DFE_HDMI_RX_PHY_P1_ENABLE_reg                                           0xB800DB10
#define  DFE_HDMI_RX_PHY_P1_ENABLE_inst_addr                                     "0x0002"
#define  set_DFE_HDMI_RX_PHY_P1_ENABLE_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_ENABLE_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_ENABLE_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_ENABLE_reg))
#define  DFE_HDMI_RX_PHY_P1_ENABLE_reg_p1_en_cmu_shift                           (3)
#define  DFE_HDMI_RX_PHY_P1_ENABLE_reg_p1_en_cmu_mask                            (0x00000008)
#define  DFE_HDMI_RX_PHY_P1_ENABLE_reg_p1_en_cmu(data)                           (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_P1_ENABLE_get_reg_p1_en_cmu(data)                       ((0x00000008&(data))>>3)

#define  DFE_HDMI_RX_PHY_P1_Z0K                                                  0x1800DB24
#define  DFE_HDMI_RX_PHY_P1_Z0K_reg_addr                                         "0xB800DB24"
#define  DFE_HDMI_RX_PHY_P1_Z0K_reg                                              0xB800DB24
#define  DFE_HDMI_RX_PHY_P1_Z0K_inst_addr                                        "0x0003"
#define  set_DFE_HDMI_RX_PHY_P1_Z0K_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_Z0K_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_Z0K_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_Z0K_reg))
#define  DFE_HDMI_RX_PHY_P1_Z0K_reg_z0_adjr_1_shift                              (4)
#define  DFE_HDMI_RX_PHY_P1_Z0K_reg_z0_adjr_1_mask                               (0x000001F0)
#define  DFE_HDMI_RX_PHY_P1_Z0K_reg_z0_adjr_1(data)                              (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_P1_Z0K_get_reg_z0_adjr_1(data)                          ((0x000001F0&(data))>>4)

#define  DFE_HDMI_RX_PHY_P1_B1                                                   0x1800DB40
#define  DFE_HDMI_RX_PHY_P1_B1_reg_addr                                          "0xB800DB40"
#define  DFE_HDMI_RX_PHY_P1_B1_reg                                               0xB800DB40
#define  DFE_HDMI_RX_PHY_P1_B1_inst_addr                                         "0x0004"
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

#define  DFE_HDMI_RX_PHY_P1_B2                                                   0x1800DB44
#define  DFE_HDMI_RX_PHY_P1_B2_reg_addr                                          "0xB800DB44"
#define  DFE_HDMI_RX_PHY_P1_B2_reg                                               0xB800DB44
#define  DFE_HDMI_RX_PHY_P1_B2_inst_addr                                         "0x0005"
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

#define  DFE_HDMI_RX_PHY_P1_B3                                                   0x1800DB48
#define  DFE_HDMI_RX_PHY_P1_B3_reg_addr                                          "0xB800DB48"
#define  DFE_HDMI_RX_PHY_P1_B3_reg                                               0xB800DB48
#define  DFE_HDMI_RX_PHY_P1_B3_inst_addr                                         "0x0006"
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

#define  DFE_HDMI_RX_PHY_P1_B4                                                   0x1800DB4C
#define  DFE_HDMI_RX_PHY_P1_B4_reg_addr                                          "0xB800DB4C"
#define  DFE_HDMI_RX_PHY_P1_B4_reg                                               0xB800DB4C
#define  DFE_HDMI_RX_PHY_P1_B4_inst_addr                                         "0x0007"
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

#define  DFE_HDMI_RX_PHY_P1_CK1                                                  0x1800DB50
#define  DFE_HDMI_RX_PHY_P1_CK1_reg_addr                                         "0xB800DB50"
#define  DFE_HDMI_RX_PHY_P1_CK1_reg                                              0xB800DB50
#define  DFE_HDMI_RX_PHY_P1_CK1_inst_addr                                        "0x0008"
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

#define  DFE_HDMI_RX_PHY_P1_CK2                                                  0x1800DB54
#define  DFE_HDMI_RX_PHY_P1_CK2_reg_addr                                         "0xB800DB54"
#define  DFE_HDMI_RX_PHY_P1_CK2_reg                                              0xB800DB54
#define  DFE_HDMI_RX_PHY_P1_CK2_inst_addr                                        "0x0009"
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

#define  DFE_HDMI_RX_PHY_P1_CK3                                                  0x1800DB58
#define  DFE_HDMI_RX_PHY_P1_CK3_reg_addr                                         "0xB800DB58"
#define  DFE_HDMI_RX_PHY_P1_CK3_reg                                              0xB800DB58
#define  DFE_HDMI_RX_PHY_P1_CK3_inst_addr                                        "0x000A"
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

#define  DFE_HDMI_RX_PHY_P1_CK4                                                  0x1800DB5C
#define  DFE_HDMI_RX_PHY_P1_CK4_reg_addr                                         "0xB800DB5C"
#define  DFE_HDMI_RX_PHY_P1_CK4_reg                                              0xB800DB5C
#define  DFE_HDMI_RX_PHY_P1_CK4_inst_addr                                        "0x000B"
#define  set_DFE_HDMI_RX_PHY_P1_CK4_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK4_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_CK4_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_CK4_reg))
#define  DFE_HDMI_RX_PHY_P1_CK4_reg_p1_ck_13_shift                               (0)
#define  DFE_HDMI_RX_PHY_P1_CK4_reg_p1_ck_13_mask                                (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_CK4_reg_p1_ck_13(data)                               (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_CK4_get_reg_p1_ck_13(data)                           (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_G1                                                   0x1800DB60
#define  DFE_HDMI_RX_PHY_P1_G1_reg_addr                                          "0xB800DB60"
#define  DFE_HDMI_RX_PHY_P1_G1_reg                                               0xB800DB60
#define  DFE_HDMI_RX_PHY_P1_G1_inst_addr                                         "0x000C"
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

#define  DFE_HDMI_RX_PHY_P1_G2                                                   0x1800DB64
#define  DFE_HDMI_RX_PHY_P1_G2_reg_addr                                          "0xB800DB64"
#define  DFE_HDMI_RX_PHY_P1_G2_reg                                               0xB800DB64
#define  DFE_HDMI_RX_PHY_P1_G2_inst_addr                                         "0x000D"
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

#define  DFE_HDMI_RX_PHY_P1_G3                                                   0x1800DB68
#define  DFE_HDMI_RX_PHY_P1_G3_reg_addr                                          "0xB800DB68"
#define  DFE_HDMI_RX_PHY_P1_G3_reg                                               0xB800DB68
#define  DFE_HDMI_RX_PHY_P1_G3_inst_addr                                         "0x000E"
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

#define  DFE_HDMI_RX_PHY_P1_G4                                                   0x1800DB6C
#define  DFE_HDMI_RX_PHY_P1_G4_reg_addr                                          "0xB800DB6C"
#define  DFE_HDMI_RX_PHY_P1_G4_reg                                               0xB800DB6C
#define  DFE_HDMI_RX_PHY_P1_G4_inst_addr                                         "0x000F"
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

#define  DFE_HDMI_RX_PHY_P1_R1                                                   0x1800DB70
#define  DFE_HDMI_RX_PHY_P1_R1_reg_addr                                          "0xB800DB70"
#define  DFE_HDMI_RX_PHY_P1_R1_reg                                               0xB800DB70
#define  DFE_HDMI_RX_PHY_P1_R1_inst_addr                                         "0x0010"
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

#define  DFE_HDMI_RX_PHY_P1_R2                                                   0x1800DB74
#define  DFE_HDMI_RX_PHY_P1_R2_reg_addr                                          "0xB800DB74"
#define  DFE_HDMI_RX_PHY_P1_R2_reg                                               0xB800DB74
#define  DFE_HDMI_RX_PHY_P1_R2_inst_addr                                         "0x0011"
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

#define  DFE_HDMI_RX_PHY_P1_R3                                                   0x1800DB78
#define  DFE_HDMI_RX_PHY_P1_R3_reg_addr                                          "0xB800DB78"
#define  DFE_HDMI_RX_PHY_P1_R3_reg                                               0xB800DB78
#define  DFE_HDMI_RX_PHY_P1_R3_inst_addr                                         "0x0012"
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

#define  DFE_HDMI_RX_PHY_P1_R4                                                   0x1800DB7C
#define  DFE_HDMI_RX_PHY_P1_R4_reg_addr                                          "0xB800DB7C"
#define  DFE_HDMI_RX_PHY_P1_R4_reg                                               0xB800DB7C
#define  DFE_HDMI_RX_PHY_P1_R4_inst_addr                                         "0x0013"
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

#define  DFE_HDMI_RX_PHY_P1_RST                                                  0x1800DB80
#define  DFE_HDMI_RX_PHY_P1_RST_reg_addr                                         "0xB800DB80"
#define  DFE_HDMI_RX_PHY_P1_RST_reg                                              0xB800DB80
#define  DFE_HDMI_RX_PHY_P1_RST_inst_addr                                        "0x0014"
#define  set_DFE_HDMI_RX_PHY_P1_RST_reg(data)                                    (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_RST_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_RST_reg                                          (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_RST_reg))
#define  DFE_HDMI_RX_PHY_P1_RST_p1_r_demux_rstb_shift                            (2)
#define  DFE_HDMI_RX_PHY_P1_RST_p1_g_demux_rstb_shift                            (1)
#define  DFE_HDMI_RX_PHY_P1_RST_p1_b_demux_rstb_shift                            (0)
#define  DFE_HDMI_RX_PHY_P1_RST_p1_r_demux_rstb_mask                             (0x00000004)
#define  DFE_HDMI_RX_PHY_P1_RST_p1_g_demux_rstb_mask                             (0x00000002)
#define  DFE_HDMI_RX_PHY_P1_RST_p1_b_demux_rstb_mask                             (0x00000001)
#define  DFE_HDMI_RX_PHY_P1_RST_p1_r_demux_rstb(data)                            (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_P1_RST_p1_g_demux_rstb(data)                            (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_P1_RST_p1_b_demux_rstb(data)                            (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_P1_RST_get_p1_r_demux_rstb(data)                        ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_P1_RST_get_p1_g_demux_rstb(data)                        ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_P1_RST_get_p1_b_demux_rstb(data)                        (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD20                                               0x1800DB90
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_addr                                      "0xB800DB90"
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg                                           0xB800DB90
#define  DFE_HDMI_RX_PHY_P1_REGD20_inst_addr                                     "0x0015"
#define  set_DFE_HDMI_RX_PHY_P1_REGD20_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD20_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD20_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD20_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_r_dig_rst_n_shift                          (31)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_g_dig_rst_n_shift                          (30)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_b_dig_rst_n_shift                          (29)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_r_cdr_rst_n_shift                          (28)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_g_cdr_rst_n_shift                          (27)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_b_cdr_rst_n_shift                          (26)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_cdr_ckinv_r_shift                      (25)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_cdr_ckinv_g_shift                      (24)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_cdr_ckinv_b_shift                      (23)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_shift_inv_r_shift                      (22)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_shift_inv_g_shift                      (21)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_shift_inv_b_shift                      (20)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_rate_sel_shift                         (17)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_kd_shift                               (16)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_kp_shift                               (8)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_ki_shift                               (5)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_bypass_sdm_int_shift                   (4)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_data_order_shift                       (3)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_infifo_cnt_shift                       (0)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_r_dig_rst_n_mask                           (0x80000000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_g_dig_rst_n_mask                           (0x40000000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_b_dig_rst_n_mask                           (0x20000000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_r_cdr_rst_n_mask                           (0x10000000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_g_cdr_rst_n_mask                           (0x08000000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_b_cdr_rst_n_mask                           (0x04000000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_cdr_ckinv_r_mask                       (0x02000000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_cdr_ckinv_g_mask                       (0x01000000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_cdr_ckinv_b_mask                       (0x00800000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_shift_inv_r_mask                       (0x00400000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_shift_inv_g_mask                       (0x00200000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_shift_inv_b_mask                       (0x00100000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_rate_sel_mask                          (0x000E0000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_kd_mask                                (0x00010000)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_kp_mask                                (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_ki_mask                                (0x000000E0)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_bypass_sdm_int_mask                    (0x00000010)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_data_order_mask                        (0x00000008)
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_infifo_cnt_mask                        (0x00000007)
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_r_dig_rst_n(data)                          (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_g_dig_rst_n(data)                          (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_b_dig_rst_n(data)                          (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_r_cdr_rst_n(data)                          (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_g_cdr_rst_n(data)                          (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_P1_REGD20_p1_b_cdr_rst_n(data)                          (0x04000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_cdr_ckinv_r(data)                      (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_cdr_ckinv_g(data)                      (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_cdr_ckinv_b(data)                      (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_shift_inv_r(data)                      (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_shift_inv_g(data)                      (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_shift_inv_b(data)                      (0x00100000&((data)<<20))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_rate_sel(data)                         (0x000E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_kd(data)                               (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_kp(data)                               (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_ki(data)                               (0x000000E0&((data)<<5))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_bypass_sdm_int(data)                   (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_data_order(data)                       (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_P1_REGD20_reg_p1_infifo_cnt(data)                       (0x00000007&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_p1_r_dig_rst_n(data)                      ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_p1_g_dig_rst_n(data)                      ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_p1_b_dig_rst_n(data)                      ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_p1_r_cdr_rst_n(data)                      ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_p1_g_cdr_rst_n(data)                      ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_p1_b_cdr_rst_n(data)                      ((0x04000000&(data))>>26)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_cdr_ckinv_r(data)                  ((0x02000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_cdr_ckinv_g(data)                  ((0x01000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_cdr_ckinv_b(data)                  ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_shift_inv_r(data)                  ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_shift_inv_g(data)                  ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_shift_inv_b(data)                  ((0x00100000&(data))>>20)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_rate_sel(data)                     ((0x000E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_kd(data)                           ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_kp(data)                           ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_ki(data)                           ((0x000000E0&(data))>>5)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_bypass_sdm_int(data)               ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_data_order(data)                   ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_P1_REGD20_get_reg_p1_infifo_cnt(data)                   (0x00000007&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD21                                               0x1800DB94
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_addr                                      "0xB800DB94"
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg                                           0xB800DB94
#define  DFE_HDMI_RX_PHY_P1_REGD21_inst_addr                                     "0x0016"
#define  set_DFE_HDMI_RX_PHY_P1_REGD21_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD21_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD21_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD21_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_int_init_shift                         (18)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_acc2_period_shift                      (8)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_squ_tri_shift                          (7)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_acc2_manual_shift                      (6)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_testout_sel_shift                      (4)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_ercnt_en_shift                         (3)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_edge_out_shift                         (2)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_pi_m_mode_shift                        (1)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_dyn_kp_en_shift                        (0)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_int_init_mask                          (0xFFFC0000)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_acc2_period_mask                       (0x0003FF00)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_squ_tri_mask                           (0x00000080)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_acc2_manual_mask                       (0x00000040)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_testout_sel_mask                       (0x00000030)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_ercnt_en_mask                          (0x00000008)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_edge_out_mask                          (0x00000004)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_pi_m_mode_mask                         (0x00000002)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_dyn_kp_en_mask                         (0x00000001)
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_int_init(data)                         (0xFFFC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_acc2_period(data)                      (0x0003FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_squ_tri(data)                          (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_acc2_manual(data)                      (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_testout_sel(data)                      (0x00000030&((data)<<4))
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_ercnt_en(data)                         (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_edge_out(data)                         (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_pi_m_mode(data)                        (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_P1_REGD21_reg_p1_dyn_kp_en(data)                        (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD21_get_reg_p1_int_init(data)                     ((0xFFFC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P1_REGD21_get_reg_p1_acc2_period(data)                  ((0x0003FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_REGD21_get_reg_p1_squ_tri(data)                      ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_P1_REGD21_get_reg_p1_acc2_manual(data)                  ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_P1_REGD21_get_reg_p1_testout_sel(data)                  ((0x00000030&(data))>>4)
#define  DFE_HDMI_RX_PHY_P1_REGD21_get_reg_p1_ercnt_en(data)                     ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_P1_REGD21_get_reg_p1_edge_out(data)                     ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_P1_REGD21_get_reg_p1_pi_m_mode(data)                    ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_P1_REGD21_get_reg_p1_dyn_kp_en(data)                    (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD22                                               0x1800DB98
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_addr                                      "0xB800DB98"
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg                                           0xB800DB98
#define  DFE_HDMI_RX_PHY_P1_REGD22_inst_addr                                     "0x0017"
#define  set_DFE_HDMI_RX_PHY_P1_REGD22_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD22_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD22_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD22_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_en_m_value_shift                       (28)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_st_mode_shift                          (27)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_timer_lpf_shift                        (18)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_timer_eq_shift                         (13)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_timer_ber_shift                        (8)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_en_m_value_mask                        (0xF0000000)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_st_mode_mask                           (0x08000000)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_timer_lpf_mask                         (0x007C0000)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_timer_eq_mask                          (0x0003E000)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_timer_ber_mask                         (0x00001F00)
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_en_m_value(data)                       (0xF0000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_st_mode(data)                          (0x08000000&((data)<<27))
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_timer_lpf(data)                        (0x007C0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_timer_eq(data)                         (0x0003E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_P1_REGD22_reg_p1_timer_ber(data)                        (0x00001F00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_REGD22_get_reg_p1_en_m_value(data)                   ((0xF0000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_P1_REGD22_get_reg_p1_st_mode(data)                      ((0x08000000&(data))>>27)
#define  DFE_HDMI_RX_PHY_P1_REGD22_get_reg_p1_timer_lpf(data)                    ((0x007C0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P1_REGD22_get_reg_p1_timer_eq(data)                     ((0x0003E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_P1_REGD22_get_reg_p1_timer_ber(data)                    ((0x00001F00&(data))>>8)

#define  DFE_HDMI_RX_PHY_P1_REGD23                                               0x1800DB9C
#define  DFE_HDMI_RX_PHY_P1_REGD23_reg_addr                                      "0xB800DB9C"
#define  DFE_HDMI_RX_PHY_P1_REGD23_reg                                           0xB800DB9C
#define  DFE_HDMI_RX_PHY_P1_REGD23_inst_addr                                     "0x0018"
#define  set_DFE_HDMI_RX_PHY_P1_REGD23_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD23_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD23_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD23_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_st_ro_r_shift                              (24)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_en_ro_r_shift                              (20)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_st_ro_g_shift                              (14)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_en_ro_g_shift                              (10)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_st_ro_b_shift                              (4)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_en_ro_b_shift                              (0)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_st_ro_r_mask                               (0x1F000000)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_en_ro_r_mask                               (0x00F00000)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_st_ro_g_mask                               (0x0007C000)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_en_ro_g_mask                               (0x00003C00)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_st_ro_b_mask                               (0x000001F0)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_en_ro_b_mask                               (0x0000000F)
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_st_ro_r(data)                              (0x1F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_en_ro_r(data)                              (0x00F00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_st_ro_g(data)                              (0x0007C000&((data)<<14))
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_en_ro_g(data)                              (0x00003C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_st_ro_b(data)                              (0x000001F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_P1_REGD23_p1_en_ro_b(data)                              (0x0000000F&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD23_get_p1_st_ro_r(data)                          ((0x1F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_REGD23_get_p1_en_ro_r(data)                          ((0x00F00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_P1_REGD23_get_p1_st_ro_g(data)                          ((0x0007C000&(data))>>14)
#define  DFE_HDMI_RX_PHY_P1_REGD23_get_p1_en_ro_g(data)                          ((0x00003C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P1_REGD23_get_p1_st_ro_b(data)                          ((0x000001F0&(data))>>4)
#define  DFE_HDMI_RX_PHY_P1_REGD23_get_p1_en_ro_b(data)                          (0x0000000F&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD24                                               0x1800DBA0
#define  DFE_HDMI_RX_PHY_P1_REGD24_reg_addr                                      "0xB800DBA0"
#define  DFE_HDMI_RX_PHY_P1_REGD24_reg                                           0xB800DBA0
#define  DFE_HDMI_RX_PHY_P1_REGD24_inst_addr                                     "0x0019"
#define  set_DFE_HDMI_RX_PHY_P1_REGD24_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD24_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD24_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD24_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD24_p1_er_count_r_shift                           (20)
#define  DFE_HDMI_RX_PHY_P1_REGD24_p1_er_count_g_shift                           (10)
#define  DFE_HDMI_RX_PHY_P1_REGD24_p1_er_count_b_shift                           (0)
#define  DFE_HDMI_RX_PHY_P1_REGD24_p1_er_count_r_mask                            (0x3FF00000)
#define  DFE_HDMI_RX_PHY_P1_REGD24_p1_er_count_g_mask                            (0x000FFC00)
#define  DFE_HDMI_RX_PHY_P1_REGD24_p1_er_count_b_mask                            (0x000003FF)
#define  DFE_HDMI_RX_PHY_P1_REGD24_p1_er_count_r(data)                           (0x3FF00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_P1_REGD24_p1_er_count_g(data)                           (0x000FFC00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P1_REGD24_p1_er_count_b(data)                           (0x000003FF&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD24_get_p1_er_count_r(data)                       ((0x3FF00000&(data))>>20)
#define  DFE_HDMI_RX_PHY_P1_REGD24_get_p1_er_count_g(data)                       ((0x000FFC00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P1_REGD24_get_p1_er_count_b(data)                       (0x000003FF&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD25                                               0x1800DBA4
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_addr                                      "0xB800DBA4"
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg                                           0xB800DBA4
#define  DFE_HDMI_RX_PHY_P1_REGD25_inst_addr                                     "0x001A"
#define  set_DFE_HDMI_RX_PHY_P1_REGD25_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD25_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD25_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD25_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_clk_rdy_shift                   (31)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_eqen_rdy_shift                  (30)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_data_rdy_shift                  (29)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_pi_shift                        (28)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_data_rdy_time_shift                    (24)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_clkout_manual_shift                 (23)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_eqen_manual_shift                   (22)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_data_manual_shift                   (21)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_eqen_rdy_time_shift                    (17)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_order_shift                            (16)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_base_time_shift                 (13)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_en_shift                        (12)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_rst_wid_shift                   (10)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_time_rdy_shift                  (8)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_acdr_l0_en_shift                       (7)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_eqen_rdy_l0_shift               (6)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_data_rdy_l0_shift               (5)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_eqen_manual_l0_shift                (4)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_data_manual_l0_shift                (3)
#define  DFE_HDMI_RX_PHY_P1_REGD25_p1_pll_wd_ckrdy_ro_shift                      (2)
#define  DFE_HDMI_RX_PHY_P1_REGD25_p1_pll_wd_rst_wc_shift                        (1)
#define  DFE_HDMI_RX_PHY_P1_REGD25_p1_wdog_rst_n_shift                           (0)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_clk_rdy_mask                    (0x80000000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_eqen_rdy_mask                   (0x40000000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_data_rdy_mask                   (0x20000000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_pi_mask                         (0x10000000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_data_rdy_time_mask                     (0x0F000000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_clkout_manual_mask                  (0x00800000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_eqen_manual_mask                    (0x00400000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_data_manual_mask                    (0x00200000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_eqen_rdy_time_mask                     (0x001E0000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_order_mask                             (0x00010000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_base_time_mask                  (0x0000E000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_en_mask                         (0x00001000)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_rst_wid_mask                    (0x00000C00)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_time_rdy_mask                   (0x00000300)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_acdr_l0_en_mask                        (0x00000080)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_eqen_rdy_l0_mask                (0x00000040)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_data_rdy_l0_mask                (0x00000020)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_eqen_manual_l0_mask                 (0x00000010)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_data_manual_l0_mask                 (0x00000008)
#define  DFE_HDMI_RX_PHY_P1_REGD25_p1_pll_wd_ckrdy_ro_mask                       (0x00000004)
#define  DFE_HDMI_RX_PHY_P1_REGD25_p1_pll_wd_rst_wc_mask                         (0x00000002)
#define  DFE_HDMI_RX_PHY_P1_REGD25_p1_wdog_rst_n_mask                            (0x00000001)
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_clk_rdy(data)                   (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_eqen_rdy(data)                  (0x40000000&((data)<<30))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_data_rdy(data)                  (0x20000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_pi(data)                        (0x10000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_data_rdy_time(data)                    (0x0F000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_clkout_manual(data)                 (0x00800000&((data)<<23))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_eqen_manual(data)                   (0x00400000&((data)<<22))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_data_manual(data)                   (0x00200000&((data)<<21))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_eqen_rdy_time(data)                    (0x001E0000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_order(data)                            (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_base_time(data)                 (0x0000E000&((data)<<13))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_en(data)                        (0x00001000&((data)<<12))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_rst_wid(data)                   (0x00000C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_pll_wd_time_rdy(data)                  (0x00000300&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_acdr_l0_en(data)                       (0x00000080&((data)<<7))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_eqen_rdy_l0(data)               (0x00000040&((data)<<6))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_bypass_data_rdy_l0(data)               (0x00000020&((data)<<5))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_eqen_manual_l0(data)                (0x00000010&((data)<<4))
#define  DFE_HDMI_RX_PHY_P1_REGD25_reg_p1_en_data_manual_l0(data)                (0x00000008&((data)<<3))
#define  DFE_HDMI_RX_PHY_P1_REGD25_p1_pll_wd_ckrdy_ro(data)                      (0x00000004&((data)<<2))
#define  DFE_HDMI_RX_PHY_P1_REGD25_p1_pll_wd_rst_wc(data)                        (0x00000002&((data)<<1))
#define  DFE_HDMI_RX_PHY_P1_REGD25_p1_wdog_rst_n(data)                           (0x00000001&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_bypass_clk_rdy(data)               ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_bypass_eqen_rdy(data)              ((0x40000000&(data))>>30)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_bypass_data_rdy(data)              ((0x20000000&(data))>>29)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_bypass_pi(data)                    ((0x10000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_data_rdy_time(data)                ((0x0F000000&(data))>>24)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_en_clkout_manual(data)             ((0x00800000&(data))>>23)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_en_eqen_manual(data)               ((0x00400000&(data))>>22)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_en_data_manual(data)               ((0x00200000&(data))>>21)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_eqen_rdy_time(data)                ((0x001E0000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_order(data)                        ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_pll_wd_base_time(data)             ((0x0000E000&(data))>>13)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_pll_wd_en(data)                    ((0x00001000&(data))>>12)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_pll_wd_rst_wid(data)               ((0x00000C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_pll_wd_time_rdy(data)              ((0x00000300&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_acdr_l0_en(data)                   ((0x00000080&(data))>>7)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_bypass_eqen_rdy_l0(data)           ((0x00000040&(data))>>6)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_bypass_data_rdy_l0(data)           ((0x00000020&(data))>>5)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_en_eqen_manual_l0(data)            ((0x00000010&(data))>>4)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_reg_p1_en_data_manual_l0(data)            ((0x00000008&(data))>>3)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_p1_pll_wd_ckrdy_ro(data)                  ((0x00000004&(data))>>2)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_p1_pll_wd_rst_wc(data)                    ((0x00000002&(data))>>1)
#define  DFE_HDMI_RX_PHY_P1_REGD25_get_p1_wdog_rst_n(data)                       (0x00000001&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD26                                               0x1800DBA8
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_addr                                      "0xB800DBA8"
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg                                           0xB800DBA8
#define  DFE_HDMI_RX_PHY_P1_REGD26_inst_addr                                     "0x001B"
#define  set_DFE_HDMI_RX_PHY_P1_REGD26_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD26_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD26_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD26_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_p1_wd_sdm_en_shift                        (31)
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_p1_f_code_shift                           (16)
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_p1_n_code_shift                           (0)
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_p1_wd_sdm_en_mask                         (0x80000000)
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_p1_f_code_mask                            (0x0FFF0000)
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_p1_n_code_mask                            (0x000001FF)
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_p1_wd_sdm_en(data)                        (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_p1_f_code(data)                           (0x0FFF0000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_REGD26_reg_p1_n_code(data)                           (0x000001FF&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD26_get_reg_p1_wd_sdm_en(data)                    ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_P1_REGD26_get_reg_p1_f_code(data)                       ((0x0FFF0000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_REGD26_get_reg_p1_n_code(data)                       (0x000001FF&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD27                                               0x1800DBAC
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_addr                                      "0xB800DBAC"
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg                                           0xB800DBAC
#define  DFE_HDMI_RX_PHY_P1_REGD27_inst_addr                                     "0x001C"
#define  set_DFE_HDMI_RX_PHY_P1_REGD27_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD27_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD27_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD27_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD27_p1_ck_md_rstb_shift                           (31)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_threshold_shift                  (25)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_debounce_shift                   (18)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_sel_shift                        (16)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_auto_shift                       (15)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_adj_shift                        (11)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_error_limit_shift                   (6)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_reserved_shift                   (2)
#define  DFE_HDMI_RX_PHY_P1_REGD27_p1_ck_md_rstb_mask                            (0x80000000)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_threshold_mask                   (0x7E000000)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_debounce_mask                    (0x01FC0000)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_sel_mask                         (0x00030000)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_auto_mask                        (0x00008000)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_adj_mask                         (0x00007800)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_error_limit_mask                    (0x000007C0)
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_reserved_mask                    (0x0000003C)
#define  DFE_HDMI_RX_PHY_P1_REGD27_p1_ck_md_rstb(data)                           (0x80000000&((data)<<31))
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_threshold(data)                  (0x7E000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_debounce(data)                   (0x01FC0000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_sel(data)                        (0x00030000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_auto(data)                       (0x00008000&((data)<<15))
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_adj(data)                        (0x00007800&((data)<<11))
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_error_limit(data)                   (0x000007C0&((data)<<6))
#define  DFE_HDMI_RX_PHY_P1_REGD27_reg_p1_ck_md_reserved(data)                   (0x0000003C&((data)<<2))
#define  DFE_HDMI_RX_PHY_P1_REGD27_get_p1_ck_md_rstb(data)                       ((0x80000000&(data))>>31)
#define  DFE_HDMI_RX_PHY_P1_REGD27_get_reg_p1_ck_md_threshold(data)              ((0x7E000000&(data))>>25)
#define  DFE_HDMI_RX_PHY_P1_REGD27_get_reg_p1_ck_md_debounce(data)               ((0x01FC0000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P1_REGD27_get_reg_p1_ck_md_sel(data)                    ((0x00030000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_REGD27_get_reg_p1_ck_md_auto(data)                   ((0x00008000&(data))>>15)
#define  DFE_HDMI_RX_PHY_P1_REGD27_get_reg_p1_ck_md_adj(data)                    ((0x00007800&(data))>>11)
#define  DFE_HDMI_RX_PHY_P1_REGD27_get_reg_p1_ck_error_limit(data)               ((0x000007C0&(data))>>6)
#define  DFE_HDMI_RX_PHY_P1_REGD27_get_reg_p1_ck_md_reserved(data)               ((0x0000003C&(data))>>2)

#define  DFE_HDMI_RX_PHY_P1_REGD28                                               0x1800DBB0
#define  DFE_HDMI_RX_PHY_P1_REGD28_reg_addr                                      "0xB800DBB0"
#define  DFE_HDMI_RX_PHY_P1_REGD28_reg                                           0xB800DBB0
#define  DFE_HDMI_RX_PHY_P1_REGD28_inst_addr                                     "0x001D"
#define  set_DFE_HDMI_RX_PHY_P1_REGD28_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD28_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD28_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD28_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_ck_md_count_shift                          (19)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_ck_rate_shift                              (15)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_unstable_count_shift                       (10)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_ck_md_ok_shift                             (9)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_clock_unstable_flag_shift                  (8)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_ck_md_count_mask                           (0xFFF80000)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_ck_rate_mask                               (0x00078000)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_unstable_count_mask                        (0x00007C00)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_ck_md_ok_mask                              (0x00000200)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_clock_unstable_flag_mask                   (0x00000100)
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_ck_md_count(data)                          (0xFFF80000&((data)<<19))
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_ck_rate(data)                              (0x00078000&((data)<<15))
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_unstable_count(data)                       (0x00007C00&((data)<<10))
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_ck_md_ok(data)                             (0x00000200&((data)<<9))
#define  DFE_HDMI_RX_PHY_P1_REGD28_p1_clock_unstable_flag(data)                  (0x00000100&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_REGD28_get_p1_ck_md_count(data)                      ((0xFFF80000&(data))>>19)
#define  DFE_HDMI_RX_PHY_P1_REGD28_get_p1_ck_rate(data)                          ((0x00078000&(data))>>15)
#define  DFE_HDMI_RX_PHY_P1_REGD28_get_p1_unstable_count(data)                   ((0x00007C00&(data))>>10)
#define  DFE_HDMI_RX_PHY_P1_REGD28_get_p1_ck_md_ok(data)                         ((0x00000200&(data))>>9)
#define  DFE_HDMI_RX_PHY_P1_REGD28_get_p1_clock_unstable_flag(data)              ((0x00000100&(data))>>8)

#define  DFE_HDMI_RX_PHY_P1_REGD29                                               0x1800DBB4
#define  DFE_HDMI_RX_PHY_P1_REGD29_reg_addr                                      "0xB800DBB4"
#define  DFE_HDMI_RX_PHY_P1_REGD29_reg                                           0xB800DBB4
#define  DFE_HDMI_RX_PHY_P1_REGD29_inst_addr                                     "0x001E"
#define  set_DFE_HDMI_RX_PHY_P1_REGD29_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD29_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD29_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD29_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD29_reg_p1_dig_debug_sel_shift                    (28)
#define  DFE_HDMI_RX_PHY_P1_REGD29_reg_dig_reserved_1_shift                      (20)
#define  DFE_HDMI_RX_PHY_P1_REGD29_reg_p1_dig_debug_sel_mask                     (0xF0000000)
#define  DFE_HDMI_RX_PHY_P1_REGD29_reg_dig_reserved_1_mask                       (0x0FF00000)
#define  DFE_HDMI_RX_PHY_P1_REGD29_reg_p1_dig_debug_sel(data)                    (0xF0000000&((data)<<28))
#define  DFE_HDMI_RX_PHY_P1_REGD29_reg_dig_reserved_1(data)                      (0x0FF00000&((data)<<20))
#define  DFE_HDMI_RX_PHY_P1_REGD29_get_reg_p1_dig_debug_sel(data)                ((0xF0000000&(data))>>28)
#define  DFE_HDMI_RX_PHY_P1_REGD29_get_reg_dig_reserved_1(data)                  ((0x0FF00000&(data))>>20)

#define  DFE_HDMI_RX_PHY_P1_REGD30                                               0x1800DBB8
#define  DFE_HDMI_RX_PHY_P1_REGD30_reg_addr                                      "0xB800DBB8"
#define  DFE_HDMI_RX_PHY_P1_REGD30_reg                                           0xB800DBB8
#define  DFE_HDMI_RX_PHY_P1_REGD30_inst_addr                                     "0x001F"
#define  set_DFE_HDMI_RX_PHY_P1_REGD30_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD30_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD30_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD30_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD30_reg_p1_st_m_value_shift                       (0)
#define  DFE_HDMI_RX_PHY_P1_REGD30_reg_p1_st_m_value_mask                        (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_P1_REGD30_reg_p1_st_m_value(data)                       (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD30_get_reg_p1_st_m_value(data)                   (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD31                                               0x1800DBBC
#define  DFE_HDMI_RX_PHY_P1_REGD31_reg_addr                                      "0xB800DBBC"
#define  DFE_HDMI_RX_PHY_P1_REGD31_reg                                           0xB800DBBC
#define  DFE_HDMI_RX_PHY_P1_REGD31_inst_addr                                     "0x0020"
#define  set_DFE_HDMI_RX_PHY_P1_REGD31_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD31_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD31_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD31_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD31_reg_p1_st_m_value_g_shift                     (0)
#define  DFE_HDMI_RX_PHY_P1_REGD31_reg_p1_st_m_value_g_mask                      (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_P1_REGD31_reg_p1_st_m_value_g(data)                     (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD31_get_reg_p1_st_m_value_g(data)                 (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD32                                               0x1800DBC0
#define  DFE_HDMI_RX_PHY_P1_REGD32_reg_addr                                      "0xB800DBC0"
#define  DFE_HDMI_RX_PHY_P1_REGD32_reg                                           0xB800DBC0
#define  DFE_HDMI_RX_PHY_P1_REGD32_inst_addr                                     "0x0021"
#define  set_DFE_HDMI_RX_PHY_P1_REGD32_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD32_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD32_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD32_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD32_reg_p1_st_m_value_b_shift                     (0)
#define  DFE_HDMI_RX_PHY_P1_REGD32_reg_p1_st_m_value_b_mask                      (0xFFFFFFFF)
#define  DFE_HDMI_RX_PHY_P1_REGD32_reg_p1_st_m_value_b(data)                     (0xFFFFFFFF&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD32_get_reg_p1_st_m_value_b(data)                 (0xFFFFFFFF&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD33                                               0x1800DBC4
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_addr                                      "0xB800DBC4"
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg                                           0xB800DBC4
#define  DFE_HDMI_RX_PHY_P1_REGD33_inst_addr                                     "0x0022"
#define  set_DFE_HDMI_RX_PHY_P1_REGD33_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD33_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD33_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD33_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_p1_enable_one_zero_r_shift                (18)
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_p1_prbs_invs_r_shift                      (17)
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_p1_pattern_sel_r_shift                    (16)
#define  DFE_HDMI_RX_PHY_P1_REGD33_p1_pkt_count_r_shift                          (8)
#define  DFE_HDMI_RX_PHY_P1_REGD33_p1_err_count_r_shift                          (0)
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_p1_enable_one_zero_r_mask                 (0x00040000)
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_p1_prbs_invs_r_mask                       (0x00020000)
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_p1_pattern_sel_r_mask                     (0x00010000)
#define  DFE_HDMI_RX_PHY_P1_REGD33_p1_pkt_count_r_mask                           (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_REGD33_p1_err_count_r_mask                           (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_p1_enable_one_zero_r(data)                (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_p1_prbs_invs_r(data)                      (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P1_REGD33_reg_p1_pattern_sel_r(data)                    (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_REGD33_p1_pkt_count_r(data)                          (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_REGD33_p1_err_count_r(data)                          (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD33_get_reg_p1_enable_one_zero_r(data)            ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P1_REGD33_get_reg_p1_prbs_invs_r(data)                  ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P1_REGD33_get_reg_p1_pattern_sel_r(data)                ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_REGD33_get_p1_pkt_count_r(data)                      ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_REGD33_get_p1_err_count_r(data)                      (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD34                                               0x1800DBC8
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_addr                                      "0xB800DBC8"
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg                                           0xB800DBC8
#define  DFE_HDMI_RX_PHY_P1_REGD34_inst_addr                                     "0x0023"
#define  set_DFE_HDMI_RX_PHY_P1_REGD34_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD34_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD34_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD34_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_p1_enable_one_zero_g_shift                (18)
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_p1_prbs_invs_g_shift                      (17)
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_p1_pattern_sel_g_shift                    (16)
#define  DFE_HDMI_RX_PHY_P1_REGD34_p1_pkt_count_g_shift                          (8)
#define  DFE_HDMI_RX_PHY_P1_REGD34_p1_err_count_g_shift                          (0)
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_p1_enable_one_zero_g_mask                 (0x00040000)
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_p1_prbs_invs_g_mask                       (0x00020000)
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_p1_pattern_sel_g_mask                     (0x00010000)
#define  DFE_HDMI_RX_PHY_P1_REGD34_p1_pkt_count_g_mask                           (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_REGD34_p1_err_count_g_mask                           (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_p1_enable_one_zero_g(data)                (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_p1_prbs_invs_g(data)                      (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P1_REGD34_reg_p1_pattern_sel_g(data)                    (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_REGD34_p1_pkt_count_g(data)                          (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_REGD34_p1_err_count_g(data)                          (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD34_get_reg_p1_enable_one_zero_g(data)            ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P1_REGD34_get_reg_p1_prbs_invs_g(data)                  ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P1_REGD34_get_reg_p1_pattern_sel_g(data)                ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_REGD34_get_p1_pkt_count_g(data)                      ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_REGD34_get_p1_err_count_g(data)                      (0x000000FF&(data))

#define  DFE_HDMI_RX_PHY_P1_REGD35                                               0x1800DBCC
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_addr                                      "0xB800DBCC"
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg                                           0xB800DBCC
#define  DFE_HDMI_RX_PHY_P1_REGD35_inst_addr                                     "0x0024"
#define  set_DFE_HDMI_RX_PHY_P1_REGD35_reg(data)                                 (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD35_reg)=data)
#define  get_DFE_HDMI_RX_PHY_P1_REGD35_reg                                       (*((volatile unsigned int*)DFE_HDMI_RX_PHY_P1_REGD35_reg))
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_p1_enable_one_zero_b_shift                (18)
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_p1_prbs_invs_b_shift                      (17)
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_p1_pattern_sel_b_shift                    (16)
#define  DFE_HDMI_RX_PHY_P1_REGD35_p1_pkt_count_b_shift                          (8)
#define  DFE_HDMI_RX_PHY_P1_REGD35_p1_err_count_b_shift                          (0)
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_p1_enable_one_zero_b_mask                 (0x00040000)
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_p1_prbs_invs_b_mask                       (0x00020000)
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_p1_pattern_sel_b_mask                     (0x00010000)
#define  DFE_HDMI_RX_PHY_P1_REGD35_p1_pkt_count_b_mask                           (0x0000FF00)
#define  DFE_HDMI_RX_PHY_P1_REGD35_p1_err_count_b_mask                           (0x000000FF)
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_p1_enable_one_zero_b(data)                (0x00040000&((data)<<18))
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_p1_prbs_invs_b(data)                      (0x00020000&((data)<<17))
#define  DFE_HDMI_RX_PHY_P1_REGD35_reg_p1_pattern_sel_b(data)                    (0x00010000&((data)<<16))
#define  DFE_HDMI_RX_PHY_P1_REGD35_p1_pkt_count_b(data)                          (0x0000FF00&((data)<<8))
#define  DFE_HDMI_RX_PHY_P1_REGD35_p1_err_count_b(data)                          (0x000000FF&(data))
#define  DFE_HDMI_RX_PHY_P1_REGD35_get_reg_p1_enable_one_zero_b(data)            ((0x00040000&(data))>>18)
#define  DFE_HDMI_RX_PHY_P1_REGD35_get_reg_p1_prbs_invs_b(data)                  ((0x00020000&(data))>>17)
#define  DFE_HDMI_RX_PHY_P1_REGD35_get_reg_p1_pattern_sel_b(data)                ((0x00010000&(data))>>16)
#define  DFE_HDMI_RX_PHY_P1_REGD35_get_p1_pkt_count_b(data)                      ((0x0000FF00&(data))>>8)
#define  DFE_HDMI_RX_PHY_P1_REGD35_get_p1_err_count_b(data)                      (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DFE_HDMI_RX_PHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  reg_p1_ldo_sel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_p1_ldo_pow:1;
    };
}dfe_hdmi_rx_phy_p1_ldo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  reg_p1_mhl_hdmi_datasel:1;
        RBus_UInt32  reg_p1_mhl_hdmi_cksel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_p1_mhl_pow:1;
        RBus_UInt32  res3:1;
    };
}dfe_hdmi_rx_phy_p1_mhl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  reg_p1_en_cmu:1;
        RBus_UInt32  res2:3;
    };
}dfe_hdmi_rx_phy_p1_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  reg_z0_adjr_1:5;
        RBus_UInt32  res2:4;
    };
}dfe_hdmi_rx_phy_p1_z0k_RBUS;

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
        RBus_UInt32  res1:29;
        RBus_UInt32  p1_r_demux_rstb:1;
        RBus_UInt32  p1_g_demux_rstb:1;
        RBus_UInt32  p1_b_demux_rstb:1;
    };
}dfe_hdmi_rx_phy_p1_rst_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd20_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd21_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd22_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p1_er_count_r:10;
        RBus_UInt32  p1_er_count_g:10;
        RBus_UInt32  p1_er_count_b:10;
    };
}dfe_hdmi_rx_phy_p1_regd24_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd25_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd26_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd27_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_dig_debug_sel:4;
        RBus_UInt32  reg_dig_reserved_1:8;
        RBus_UInt32  res1:20;
    };
}dfe_hdmi_rx_phy_p1_regd29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value:32;
    };
}dfe_hdmi_rx_phy_p1_regd30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_p1_regd31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_p1_regd32_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd33_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd34_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd35_RBUS;

#else //apply LITTLE_ENDIAN

//======DFE_HDMI_RX_PHY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_ldo_pow:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_p1_ldo_sel:2;
        RBus_UInt32  res2:26;
    };
}dfe_hdmi_rx_phy_p1_ldo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_p1_mhl_pow:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_p1_mhl_hdmi_cksel:1;
        RBus_UInt32  reg_p1_mhl_hdmi_datasel:1;
        RBus_UInt32  res3:25;
    };
}dfe_hdmi_rx_phy_p1_mhl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_p1_en_cmu:1;
        RBus_UInt32  res2:28;
    };
}dfe_hdmi_rx_phy_p1_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_z0_adjr_1:5;
        RBus_UInt32  res2:23;
    };
}dfe_hdmi_rx_phy_p1_z0k_RBUS;

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
        RBus_UInt32  p1_b_demux_rstb:1;
        RBus_UInt32  p1_g_demux_rstb:1;
        RBus_UInt32  p1_r_demux_rstb:1;
        RBus_UInt32  res1:29;
    };
}dfe_hdmi_rx_phy_p1_rst_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd20_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd21_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd22_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_er_count_b:10;
        RBus_UInt32  p1_er_count_g:10;
        RBus_UInt32  p1_er_count_r:10;
        RBus_UInt32  res1:2;
    };
}dfe_hdmi_rx_phy_p1_regd24_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd25_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd26_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd27_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  reg_dig_reserved_1:8;
        RBus_UInt32  reg_p1_dig_debug_sel:4;
    };
}dfe_hdmi_rx_phy_p1_regd29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value:32;
    };
}dfe_hdmi_rx_phy_p1_regd30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value_g:32;
    };
}dfe_hdmi_rx_phy_p1_regd31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_p1_st_m_value_b:32;
    };
}dfe_hdmi_rx_phy_p1_regd32_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd33_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd34_RBUS;

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
}dfe_hdmi_rx_phy_p1_regd35_RBUS;




#endif 


#endif 
