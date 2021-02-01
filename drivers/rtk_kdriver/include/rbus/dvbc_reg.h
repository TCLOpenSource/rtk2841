/**
* @file Mac5_DesignSpec_DVBC_OPENCABLE
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DVBC_REG_H_
#define _RBUS_DVBC_REG_H_

#include "rbus_types.h"



//  DVBC Register Address
#define  DVBC_CHIP_VERSION                                                       0x180E8004
#define  DVBC_CHIP_VERSION_reg_addr                                              "0xB80E8004"
#define  DVBC_CHIP_VERSION_reg                                                   0xB80E8004
#define  DVBC_CHIP_VERSION_inst_addr                                             "0x0000"
#define  set_DVBC_CHIP_VERSION_reg(data)                                         (*((volatile unsigned int*)DVBC_CHIP_VERSION_reg)=data)
#define  get_DVBC_CHIP_VERSION_reg                                               (*((volatile unsigned int*)DVBC_CHIP_VERSION_reg))
#define  DVBC_CHIP_VERSION_chip_version_shift                                    (0)
#define  DVBC_CHIP_VERSION_chip_version_mask                                     (0x000000FF)
#define  DVBC_CHIP_VERSION_chip_version(data)                                    (0x000000FF&(data))
#define  DVBC_CHIP_VERSION_get_chip_version(data)                                (0x000000FF&(data))

#define  DVBC_OPT_ADCDATA_I_QAM                                                  0x180E8008
#define  DVBC_OPT_ADCDATA_I_QAM_reg_addr                                         "0xB80E8008"
#define  DVBC_OPT_ADCDATA_I_QAM_reg                                              0xB80E8008
#define  DVBC_OPT_ADCDATA_I_QAM_inst_addr                                        "0x0001"
#define  set_DVBC_OPT_ADCDATA_I_QAM_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_ADCDATA_I_QAM_reg)=data)
#define  get_DVBC_OPT_ADCDATA_I_QAM_reg                                          (*((volatile unsigned int*)DVBC_OPT_ADCDATA_I_QAM_reg))
#define  DVBC_OPT_ADCDATA_I_QAM_opt_adcdata_q_qam_shift                          (6)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_tst_in_sel_shift                             (4)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_qam_outer_data_shift                         (3)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_adcclk_qam_shift                             (2)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_adcdata_i_qam_shift                          (0)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_adcdata_q_qam_mask                           (0x000000C0)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_tst_in_sel_mask                              (0x00000030)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_qam_outer_data_mask                          (0x00000008)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_adcclk_qam_mask                              (0x00000004)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_adcdata_i_qam_mask                           (0x00000003)
#define  DVBC_OPT_ADCDATA_I_QAM_opt_adcdata_q_qam(data)                          (0x000000C0&((data)<<6))
#define  DVBC_OPT_ADCDATA_I_QAM_opt_tst_in_sel(data)                             (0x00000030&((data)<<4))
#define  DVBC_OPT_ADCDATA_I_QAM_opt_qam_outer_data(data)                         (0x00000008&((data)<<3))
#define  DVBC_OPT_ADCDATA_I_QAM_opt_adcclk_qam(data)                             (0x00000004&((data)<<2))
#define  DVBC_OPT_ADCDATA_I_QAM_opt_adcdata_i_qam(data)                          (0x00000003&(data))
#define  DVBC_OPT_ADCDATA_I_QAM_get_opt_adcdata_q_qam(data)                      ((0x000000C0&(data))>>6)
#define  DVBC_OPT_ADCDATA_I_QAM_get_opt_tst_in_sel(data)                         ((0x00000030&(data))>>4)
#define  DVBC_OPT_ADCDATA_I_QAM_get_opt_qam_outer_data(data)                     ((0x00000008&(data))>>3)
#define  DVBC_OPT_ADCDATA_I_QAM_get_opt_adcclk_qam(data)                         ((0x00000004&(data))>>2)
#define  DVBC_OPT_ADCDATA_I_QAM_get_opt_adcdata_i_qam(data)                      (0x00000003&(data))

#define  DVBC_OPT_QAM_STD                                                        0x180E800C
#define  DVBC_OPT_QAM_STD_reg_addr                                               "0xB80E800C"
#define  DVBC_OPT_QAM_STD_reg                                                    0xB80E800C
#define  DVBC_OPT_QAM_STD_inst_addr                                              "0x0002"
#define  set_DVBC_OPT_QAM_STD_reg(data)                                          (*((volatile unsigned int*)DVBC_OPT_QAM_STD_reg)=data)
#define  get_DVBC_OPT_QAM_STD_reg                                                (*((volatile unsigned int*)DVBC_OPT_QAM_STD_reg))
#define  DVBC_OPT_QAM_STD_opt_qam_std_shift                                      (0)
#define  DVBC_OPT_QAM_STD_opt_qam_std_mask                                       (0x00000001)
#define  DVBC_OPT_QAM_STD_opt_qam_std(data)                                      (0x00000001&(data))
#define  DVBC_OPT_QAM_STD_get_opt_qam_std(data)                                  (0x00000001&(data))

#define  DVBC_OPT_QAM_ON                                                         0x180E8010
#define  DVBC_OPT_QAM_ON_reg_addr                                                "0xB80E8010"
#define  DVBC_OPT_QAM_ON_reg                                                     0xB80E8010
#define  DVBC_OPT_QAM_ON_inst_addr                                               "0x0003"
#define  set_DVBC_OPT_QAM_ON_reg(data)                                           (*((volatile unsigned int*)DVBC_OPT_QAM_ON_reg)=data)
#define  get_DVBC_OPT_QAM_ON_reg                                                 (*((volatile unsigned int*)DVBC_OPT_QAM_ON_reg))
#define  DVBC_OPT_QAM_ON_opt_qam_on_shift                                        (0)
#define  DVBC_OPT_QAM_ON_opt_qam_on_mask                                         (0x00000001)
#define  DVBC_OPT_QAM_ON_opt_qam_on(data)                                        (0x00000001&(data))
#define  DVBC_OPT_QAM_ON_get_opt_qam_on(data)                                    (0x00000001&(data))

#define  DVBC_OPT_SOFT_RESET_QAM                                                 0x180E8014
#define  DVBC_OPT_SOFT_RESET_QAM_reg_addr                                        "0xB80E8014"
#define  DVBC_OPT_SOFT_RESET_QAM_reg                                             0xB80E8014
#define  DVBC_OPT_SOFT_RESET_QAM_inst_addr                                       "0x0004"
#define  set_DVBC_OPT_SOFT_RESET_QAM_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_SOFT_RESET_QAM_reg)=data)
#define  get_DVBC_OPT_SOFT_RESET_QAM_reg                                         (*((volatile unsigned int*)DVBC_OPT_SOFT_RESET_QAM_reg))
#define  DVBC_OPT_SOFT_RESET_QAM_opt_soft_reset_qam_shift                        (0)
#define  DVBC_OPT_SOFT_RESET_QAM_opt_soft_reset_qam_mask                         (0x00000001)
#define  DVBC_OPT_SOFT_RESET_QAM_opt_soft_reset_qam(data)                        (0x00000001&(data))
#define  DVBC_OPT_SOFT_RESET_QAM_get_opt_soft_reset_qam(data)                    (0x00000001&(data))

#define  DVBC_OPT_RF_AAGC_DRIVE                                                  0x180E8018
#define  DVBC_OPT_RF_AAGC_DRIVE_reg_addr                                         "0xB80E8018"
#define  DVBC_OPT_RF_AAGC_DRIVE_reg                                              0xB80E8018
#define  DVBC_OPT_RF_AAGC_DRIVE_inst_addr                                        "0x0005"
#define  set_DVBC_OPT_RF_AAGC_DRIVE_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_RF_AAGC_DRIVE_reg)=data)
#define  get_DVBC_OPT_RF_AAGC_DRIVE_reg                                          (*((volatile unsigned int*)DVBC_OPT_RF_AAGC_DRIVE_reg))
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_if_aagc_oe_shift                             (7)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_par_if_sd_ib_shift                           (6)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_if_aagc_drive_shift                          (5)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_rf_aagc_oe_shift                             (3)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_par_rf_sd_ib_shift                           (2)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_rf_aagc_drive_shift                          (1)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_if_aagc_oe_mask                              (0x00000080)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_par_if_sd_ib_mask                            (0x00000040)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_if_aagc_drive_mask                           (0x00000020)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_rf_aagc_oe_mask                              (0x00000008)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_par_rf_sd_ib_mask                            (0x00000004)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_rf_aagc_drive_mask                           (0x00000002)
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_if_aagc_oe(data)                             (0x00000080&((data)<<7))
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_par_if_sd_ib(data)                           (0x00000040&((data)<<6))
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_if_aagc_drive(data)                          (0x00000020&((data)<<5))
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_rf_aagc_oe(data)                             (0x00000008&((data)<<3))
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_par_rf_sd_ib(data)                           (0x00000004&((data)<<2))
#define  DVBC_OPT_RF_AAGC_DRIVE_opt_rf_aagc_drive(data)                          (0x00000002&((data)<<1))
#define  DVBC_OPT_RF_AAGC_DRIVE_get_opt_if_aagc_oe(data)                         ((0x00000080&(data))>>7)
#define  DVBC_OPT_RF_AAGC_DRIVE_get_opt_par_if_sd_ib(data)                       ((0x00000040&(data))>>6)
#define  DVBC_OPT_RF_AAGC_DRIVE_get_opt_if_aagc_drive(data)                      ((0x00000020&(data))>>5)
#define  DVBC_OPT_RF_AAGC_DRIVE_get_opt_rf_aagc_oe(data)                         ((0x00000008&(data))>>3)
#define  DVBC_OPT_RF_AAGC_DRIVE_get_opt_par_rf_sd_ib(data)                       ((0x00000004&(data))>>2)
#define  DVBC_OPT_RF_AAGC_DRIVE_get_opt_rf_aagc_drive(data)                      ((0x00000002&(data))>>1)

#define  DVBC_OPT_IF_AAGC_SEL                                                    0x180E801C
#define  DVBC_OPT_IF_AAGC_SEL_reg_addr                                           "0xB80E801C"
#define  DVBC_OPT_IF_AAGC_SEL_reg                                                0xB80E801C
#define  DVBC_OPT_IF_AAGC_SEL_inst_addr                                          "0x0006"
#define  set_DVBC_OPT_IF_AAGC_SEL_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_IF_AAGC_SEL_reg)=data)
#define  get_DVBC_OPT_IF_AAGC_SEL_reg                                            (*((volatile unsigned int*)DVBC_OPT_IF_AAGC_SEL_reg))
#define  DVBC_OPT_IF_AAGC_SEL_opt_rf_aagc_sel_shift                              (4)
#define  DVBC_OPT_IF_AAGC_SEL_opt_if_aagc_sel_shift                              (0)
#define  DVBC_OPT_IF_AAGC_SEL_opt_rf_aagc_sel_mask                               (0x00000070)
#define  DVBC_OPT_IF_AAGC_SEL_opt_if_aagc_sel_mask                               (0x00000007)
#define  DVBC_OPT_IF_AAGC_SEL_opt_rf_aagc_sel(data)                              (0x00000070&((data)<<4))
#define  DVBC_OPT_IF_AAGC_SEL_opt_if_aagc_sel(data)                              (0x00000007&(data))
#define  DVBC_OPT_IF_AAGC_SEL_get_opt_rf_aagc_sel(data)                          ((0x00000070&(data))>>4)
#define  DVBC_OPT_IF_AAGC_SEL_get_opt_if_aagc_sel(data)                          (0x00000007&(data))

#define  DVBC_OPT_DEBUG_SEL                                                      0x180E8020
#define  DVBC_OPT_DEBUG_SEL_reg_addr                                             "0xB80E8020"
#define  DVBC_OPT_DEBUG_SEL_reg                                                  0xB80E8020
#define  DVBC_OPT_DEBUG_SEL_inst_addr                                            "0x0007"
#define  set_DVBC_OPT_DEBUG_SEL_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_DEBUG_SEL_reg)=data)
#define  get_DVBC_OPT_DEBUG_SEL_reg                                              (*((volatile unsigned int*)DVBC_OPT_DEBUG_SEL_reg))
#define  DVBC_OPT_DEBUG_SEL_opt_ro_debug_sel_shift                               (4)
#define  DVBC_OPT_DEBUG_SEL_opt_debug_sel_shift                                  (0)
#define  DVBC_OPT_DEBUG_SEL_opt_ro_debug_sel_mask                                (0x00000070)
#define  DVBC_OPT_DEBUG_SEL_opt_debug_sel_mask                                   (0x00000007)
#define  DVBC_OPT_DEBUG_SEL_opt_ro_debug_sel(data)                               (0x00000070&((data)<<4))
#define  DVBC_OPT_DEBUG_SEL_opt_debug_sel(data)                                  (0x00000007&(data))
#define  DVBC_OPT_DEBUG_SEL_get_opt_ro_debug_sel(data)                           ((0x00000070&(data))>>4)
#define  DVBC_OPT_DEBUG_SEL_get_opt_debug_sel(data)                              (0x00000007&(data))

#define  DVBC_OPT_DEBUG_OE                                                       0x180E8024
#define  DVBC_OPT_DEBUG_OE_reg_addr                                              "0xB80E8024"
#define  DVBC_OPT_DEBUG_OE_reg                                                   0xB80E8024
#define  DVBC_OPT_DEBUG_OE_inst_addr                                             "0x0008"
#define  set_DVBC_OPT_DEBUG_OE_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_DEBUG_OE_reg)=data)
#define  get_DVBC_OPT_DEBUG_OE_reg                                               (*((volatile unsigned int*)DVBC_OPT_DEBUG_OE_reg))
#define  DVBC_OPT_DEBUG_OE_opt_debug_oe_7_0_shift                                (0)
#define  DVBC_OPT_DEBUG_OE_opt_debug_oe_7_0_mask                                 (0x000000FF)
#define  DVBC_OPT_DEBUG_OE_opt_debug_oe_7_0(data)                                (0x000000FF&(data))
#define  DVBC_OPT_DEBUG_OE_get_opt_debug_oe_7_0(data)                            (0x000000FF&(data))

#define  DVBC_OPT_DEBUG_OE_1                                                     0x180E8028
#define  DVBC_OPT_DEBUG_OE_1_reg_addr                                            "0xB80E8028"
#define  DVBC_OPT_DEBUG_OE_1_reg                                                 0xB80E8028
#define  DVBC_OPT_DEBUG_OE_1_inst_addr                                           "0x0009"
#define  set_DVBC_OPT_DEBUG_OE_1_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_DEBUG_OE_1_reg)=data)
#define  get_DVBC_OPT_DEBUG_OE_1_reg                                             (*((volatile unsigned int*)DVBC_OPT_DEBUG_OE_1_reg))
#define  DVBC_OPT_DEBUG_OE_1_opt_debug_oe_15_8_shift                             (0)
#define  DVBC_OPT_DEBUG_OE_1_opt_debug_oe_15_8_mask                              (0x000000FF)
#define  DVBC_OPT_DEBUG_OE_1_opt_debug_oe_15_8(data)                             (0x000000FF&(data))
#define  DVBC_OPT_DEBUG_OE_1_get_opt_debug_oe_15_8(data)                         (0x000000FF&(data))

#define  DVBC_OPT_DEBUG_OE_2                                                     0x180E802C
#define  DVBC_OPT_DEBUG_OE_2_reg_addr                                            "0xB80E802C"
#define  DVBC_OPT_DEBUG_OE_2_reg                                                 0xB80E802C
#define  DVBC_OPT_DEBUG_OE_2_inst_addr                                           "0x000A"
#define  set_DVBC_OPT_DEBUG_OE_2_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_DEBUG_OE_2_reg)=data)
#define  get_DVBC_OPT_DEBUG_OE_2_reg                                             (*((volatile unsigned int*)DVBC_OPT_DEBUG_OE_2_reg))
#define  DVBC_OPT_DEBUG_OE_2_opt_debug_oe_23_16_shift                            (0)
#define  DVBC_OPT_DEBUG_OE_2_opt_debug_oe_23_16_mask                             (0x000000FF)
#define  DVBC_OPT_DEBUG_OE_2_opt_debug_oe_23_16(data)                            (0x000000FF&(data))
#define  DVBC_OPT_DEBUG_OE_2_get_opt_debug_oe_23_16(data)                        (0x000000FF&(data))

#define  DVBC_OPT_DEBUG_OE_3                                                     0x180E8030
#define  DVBC_OPT_DEBUG_OE_3_reg_addr                                            "0xB80E8030"
#define  DVBC_OPT_DEBUG_OE_3_reg                                                 0xB80E8030
#define  DVBC_OPT_DEBUG_OE_3_inst_addr                                           "0x000B"
#define  set_DVBC_OPT_DEBUG_OE_3_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_DEBUG_OE_3_reg)=data)
#define  get_DVBC_OPT_DEBUG_OE_3_reg                                             (*((volatile unsigned int*)DVBC_OPT_DEBUG_OE_3_reg))
#define  DVBC_OPT_DEBUG_OE_3_opt_debug_oe_31_24_shift                            (0)
#define  DVBC_OPT_DEBUG_OE_3_opt_debug_oe_31_24_mask                             (0x000000FF)
#define  DVBC_OPT_DEBUG_OE_3_opt_debug_oe_31_24(data)                            (0x000000FF&(data))
#define  DVBC_OPT_DEBUG_OE_3_get_opt_debug_oe_31_24(data)                        (0x000000FF&(data))

#define  DVBC_DEBUG_REG                                                          0x180E8034
#define  DVBC_DEBUG_REG_reg_addr                                                 "0xB80E8034"
#define  DVBC_DEBUG_REG_reg                                                      0xB80E8034
#define  DVBC_DEBUG_REG_inst_addr                                                "0x000C"
#define  set_DVBC_DEBUG_REG_reg(data)                                            (*((volatile unsigned int*)DVBC_DEBUG_REG_reg)=data)
#define  get_DVBC_DEBUG_REG_reg                                                  (*((volatile unsigned int*)DVBC_DEBUG_REG_reg))
#define  DVBC_DEBUG_REG_debug_reg_7_0_shift                                      (0)
#define  DVBC_DEBUG_REG_debug_reg_7_0_mask                                       (0x000000FF)
#define  DVBC_DEBUG_REG_debug_reg_7_0(data)                                      (0x000000FF&(data))
#define  DVBC_DEBUG_REG_get_debug_reg_7_0(data)                                  (0x000000FF&(data))

#define  DVBC_DEBUG_REG_1                                                        0x180E8038
#define  DVBC_DEBUG_REG_1_reg_addr                                               "0xB80E8038"
#define  DVBC_DEBUG_REG_1_reg                                                    0xB80E8038
#define  DVBC_DEBUG_REG_1_inst_addr                                              "0x000D"
#define  set_DVBC_DEBUG_REG_1_reg(data)                                          (*((volatile unsigned int*)DVBC_DEBUG_REG_1_reg)=data)
#define  get_DVBC_DEBUG_REG_1_reg                                                (*((volatile unsigned int*)DVBC_DEBUG_REG_1_reg))
#define  DVBC_DEBUG_REG_1_debug_reg_15_8_shift                                   (0)
#define  DVBC_DEBUG_REG_1_debug_reg_15_8_mask                                    (0x000000FF)
#define  DVBC_DEBUG_REG_1_debug_reg_15_8(data)                                   (0x000000FF&(data))
#define  DVBC_DEBUG_REG_1_get_debug_reg_15_8(data)                               (0x000000FF&(data))

#define  DVBC_DEBUG_REG_2                                                        0x180E803C
#define  DVBC_DEBUG_REG_2_reg_addr                                               "0xB80E803C"
#define  DVBC_DEBUG_REG_2_reg                                                    0xB80E803C
#define  DVBC_DEBUG_REG_2_inst_addr                                              "0x000E"
#define  set_DVBC_DEBUG_REG_2_reg(data)                                          (*((volatile unsigned int*)DVBC_DEBUG_REG_2_reg)=data)
#define  get_DVBC_DEBUG_REG_2_reg                                                (*((volatile unsigned int*)DVBC_DEBUG_REG_2_reg))
#define  DVBC_DEBUG_REG_2_debug_reg_23_16_shift                                  (0)
#define  DVBC_DEBUG_REG_2_debug_reg_23_16_mask                                   (0x000000FF)
#define  DVBC_DEBUG_REG_2_debug_reg_23_16(data)                                  (0x000000FF&(data))
#define  DVBC_DEBUG_REG_2_get_debug_reg_23_16(data)                              (0x000000FF&(data))

#define  DVBC_DEBUG_REG_3                                                        0x180E8040
#define  DVBC_DEBUG_REG_3_reg_addr                                               "0xB80E8040"
#define  DVBC_DEBUG_REG_3_reg                                                    0xB80E8040
#define  DVBC_DEBUG_REG_3_inst_addr                                              "0x000F"
#define  set_DVBC_DEBUG_REG_3_reg(data)                                          (*((volatile unsigned int*)DVBC_DEBUG_REG_3_reg)=data)
#define  get_DVBC_DEBUG_REG_3_reg                                                (*((volatile unsigned int*)DVBC_DEBUG_REG_3_reg))
#define  DVBC_DEBUG_REG_3_debug_reg_31_24_shift                                  (0)
#define  DVBC_DEBUG_REG_3_debug_reg_31_24_mask                                   (0x000000FF)
#define  DVBC_DEBUG_REG_3_debug_reg_31_24(data)                                  (0x000000FF&(data))
#define  DVBC_DEBUG_REG_3_get_debug_reg_31_24(data)                              (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_PU                                                       0x180E8044
#define  DVBC_QAM_DEBUG_PU_reg_addr                                              "0xB80E8044"
#define  DVBC_QAM_DEBUG_PU_reg                                                   0xB80E8044
#define  DVBC_QAM_DEBUG_PU_inst_addr                                             "0x0010"
#define  set_DVBC_QAM_DEBUG_PU_reg(data)                                         (*((volatile unsigned int*)DVBC_QAM_DEBUG_PU_reg)=data)
#define  get_DVBC_QAM_DEBUG_PU_reg                                               (*((volatile unsigned int*)DVBC_QAM_DEBUG_PU_reg))
#define  DVBC_QAM_DEBUG_PU_qam_debug_pu_7_0_shift                                (0)
#define  DVBC_QAM_DEBUG_PU_qam_debug_pu_7_0_mask                                 (0x000000FF)
#define  DVBC_QAM_DEBUG_PU_qam_debug_pu_7_0(data)                                (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_PU_get_qam_debug_pu_7_0(data)                            (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_PU_1                                                     0x180E8048
#define  DVBC_QAM_DEBUG_PU_1_reg_addr                                            "0xB80E8048"
#define  DVBC_QAM_DEBUG_PU_1_reg                                                 0xB80E8048
#define  DVBC_QAM_DEBUG_PU_1_inst_addr                                           "0x0011"
#define  set_DVBC_QAM_DEBUG_PU_1_reg(data)                                       (*((volatile unsigned int*)DVBC_QAM_DEBUG_PU_1_reg)=data)
#define  get_DVBC_QAM_DEBUG_PU_1_reg                                             (*((volatile unsigned int*)DVBC_QAM_DEBUG_PU_1_reg))
#define  DVBC_QAM_DEBUG_PU_1_qam_debug_pu_15_8_shift                             (0)
#define  DVBC_QAM_DEBUG_PU_1_qam_debug_pu_15_8_mask                              (0x000000FF)
#define  DVBC_QAM_DEBUG_PU_1_qam_debug_pu_15_8(data)                             (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_PU_1_get_qam_debug_pu_15_8(data)                         (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_PU_2                                                     0x180E804C
#define  DVBC_QAM_DEBUG_PU_2_reg_addr                                            "0xB80E804C"
#define  DVBC_QAM_DEBUG_PU_2_reg                                                 0xB80E804C
#define  DVBC_QAM_DEBUG_PU_2_inst_addr                                           "0x0012"
#define  set_DVBC_QAM_DEBUG_PU_2_reg(data)                                       (*((volatile unsigned int*)DVBC_QAM_DEBUG_PU_2_reg)=data)
#define  get_DVBC_QAM_DEBUG_PU_2_reg                                             (*((volatile unsigned int*)DVBC_QAM_DEBUG_PU_2_reg))
#define  DVBC_QAM_DEBUG_PU_2_qam_debug_pu_23_16_shift                            (0)
#define  DVBC_QAM_DEBUG_PU_2_qam_debug_pu_23_16_mask                             (0x000000FF)
#define  DVBC_QAM_DEBUG_PU_2_qam_debug_pu_23_16(data)                            (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_PU_2_get_qam_debug_pu_23_16(data)                        (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_PU_3                                                     0x180E8050
#define  DVBC_QAM_DEBUG_PU_3_reg_addr                                            "0xB80E8050"
#define  DVBC_QAM_DEBUG_PU_3_reg                                                 0xB80E8050
#define  DVBC_QAM_DEBUG_PU_3_inst_addr                                           "0x0013"
#define  set_DVBC_QAM_DEBUG_PU_3_reg(data)                                       (*((volatile unsigned int*)DVBC_QAM_DEBUG_PU_3_reg)=data)
#define  get_DVBC_QAM_DEBUG_PU_3_reg                                             (*((volatile unsigned int*)DVBC_QAM_DEBUG_PU_3_reg))
#define  DVBC_QAM_DEBUG_PU_3_qam_debug_pu_31_24_shift                            (0)
#define  DVBC_QAM_DEBUG_PU_3_qam_debug_pu_31_24_mask                             (0x000000FF)
#define  DVBC_QAM_DEBUG_PU_3_qam_debug_pu_31_24(data)                            (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_PU_3_get_qam_debug_pu_31_24(data)                        (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_PD                                                       0x180E8054
#define  DVBC_QAM_DEBUG_PD_reg_addr                                              "0xB80E8054"
#define  DVBC_QAM_DEBUG_PD_reg                                                   0xB80E8054
#define  DVBC_QAM_DEBUG_PD_inst_addr                                             "0x0014"
#define  set_DVBC_QAM_DEBUG_PD_reg(data)                                         (*((volatile unsigned int*)DVBC_QAM_DEBUG_PD_reg)=data)
#define  get_DVBC_QAM_DEBUG_PD_reg                                               (*((volatile unsigned int*)DVBC_QAM_DEBUG_PD_reg))
#define  DVBC_QAM_DEBUG_PD_qam_debug_pd_7_0_shift                                (0)
#define  DVBC_QAM_DEBUG_PD_qam_debug_pd_7_0_mask                                 (0x000000FF)
#define  DVBC_QAM_DEBUG_PD_qam_debug_pd_7_0(data)                                (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_PD_get_qam_debug_pd_7_0(data)                            (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_PD_1                                                     0x180E8058
#define  DVBC_QAM_DEBUG_PD_1_reg_addr                                            "0xB80E8058"
#define  DVBC_QAM_DEBUG_PD_1_reg                                                 0xB80E8058
#define  DVBC_QAM_DEBUG_PD_1_inst_addr                                           "0x0015"
#define  set_DVBC_QAM_DEBUG_PD_1_reg(data)                                       (*((volatile unsigned int*)DVBC_QAM_DEBUG_PD_1_reg)=data)
#define  get_DVBC_QAM_DEBUG_PD_1_reg                                             (*((volatile unsigned int*)DVBC_QAM_DEBUG_PD_1_reg))
#define  DVBC_QAM_DEBUG_PD_1_qam_debug_pd_15_8_shift                             (0)
#define  DVBC_QAM_DEBUG_PD_1_qam_debug_pd_15_8_mask                              (0x000000FF)
#define  DVBC_QAM_DEBUG_PD_1_qam_debug_pd_15_8(data)                             (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_PD_1_get_qam_debug_pd_15_8(data)                         (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_PD_2                                                     0x180E805C
#define  DVBC_QAM_DEBUG_PD_2_reg_addr                                            "0xB80E805C"
#define  DVBC_QAM_DEBUG_PD_2_reg                                                 0xB80E805C
#define  DVBC_QAM_DEBUG_PD_2_inst_addr                                           "0x0016"
#define  set_DVBC_QAM_DEBUG_PD_2_reg(data)                                       (*((volatile unsigned int*)DVBC_QAM_DEBUG_PD_2_reg)=data)
#define  get_DVBC_QAM_DEBUG_PD_2_reg                                             (*((volatile unsigned int*)DVBC_QAM_DEBUG_PD_2_reg))
#define  DVBC_QAM_DEBUG_PD_2_qam_debug_pd_23_16_shift                            (0)
#define  DVBC_QAM_DEBUG_PD_2_qam_debug_pd_23_16_mask                             (0x000000FF)
#define  DVBC_QAM_DEBUG_PD_2_qam_debug_pd_23_16(data)                            (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_PD_2_get_qam_debug_pd_23_16(data)                        (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_PD_3                                                     0x180E8060
#define  DVBC_QAM_DEBUG_PD_3_reg_addr                                            "0xB80E8060"
#define  DVBC_QAM_DEBUG_PD_3_reg                                                 0xB80E8060
#define  DVBC_QAM_DEBUG_PD_3_inst_addr                                           "0x0017"
#define  set_DVBC_QAM_DEBUG_PD_3_reg(data)                                       (*((volatile unsigned int*)DVBC_QAM_DEBUG_PD_3_reg)=data)
#define  get_DVBC_QAM_DEBUG_PD_3_reg                                             (*((volatile unsigned int*)DVBC_QAM_DEBUG_PD_3_reg))
#define  DVBC_QAM_DEBUG_PD_3_qam_debug_pd_31_24_shift                            (0)
#define  DVBC_QAM_DEBUG_PD_3_qam_debug_pd_31_24_mask                             (0x000000FF)
#define  DVBC_QAM_DEBUG_PD_3_qam_debug_pd_31_24(data)                            (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_PD_3_get_qam_debug_pd_31_24(data)                        (0x000000FF&(data))

#define  DVBC_OPT_ADC_OUT_SEL                                                    0x180E8064
#define  DVBC_OPT_ADC_OUT_SEL_reg_addr                                           "0xB80E8064"
#define  DVBC_OPT_ADC_OUT_SEL_reg                                                0xB80E8064
#define  DVBC_OPT_ADC_OUT_SEL_inst_addr                                          "0x0018"
#define  set_DVBC_OPT_ADC_OUT_SEL_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_ADC_OUT_SEL_reg)=data)
#define  get_DVBC_OPT_ADC_OUT_SEL_reg                                            (*((volatile unsigned int*)DVBC_OPT_ADC_OUT_SEL_reg))
#define  DVBC_OPT_ADC_OUT_SEL_opt_adc_out_sel_shift                              (0)
#define  DVBC_OPT_ADC_OUT_SEL_opt_adc_out_sel_mask                               (0x00000001)
#define  DVBC_OPT_ADC_OUT_SEL_opt_adc_out_sel(data)                              (0x00000001&(data))
#define  DVBC_OPT_ADC_OUT_SEL_get_opt_adc_out_sel(data)                          (0x00000001&(data))

#define  DVBC_OPT_TST_OUT_SEL                                                    0x180E8094
#define  DVBC_OPT_TST_OUT_SEL_reg_addr                                           "0xB80E8094"
#define  DVBC_OPT_TST_OUT_SEL_reg                                                0xB80E8094
#define  DVBC_OPT_TST_OUT_SEL_inst_addr                                          "0x0019"
#define  set_DVBC_OPT_TST_OUT_SEL_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_TST_OUT_SEL_reg)=data)
#define  get_DVBC_OPT_TST_OUT_SEL_reg                                            (*((volatile unsigned int*)DVBC_OPT_TST_OUT_SEL_reg))
#define  DVBC_OPT_TST_OUT_SEL_opt_par_tstclk_shift                               (7)
#define  DVBC_OPT_TST_OUT_SEL_opt_tst_out_tri2_shift                             (4)
#define  DVBC_OPT_TST_OUT_SEL_opt_tst_out_tri1_shift                             (1)
#define  DVBC_OPT_TST_OUT_SEL_opt_tst_out_sel_shift                              (0)
#define  DVBC_OPT_TST_OUT_SEL_opt_par_tstclk_mask                                (0x00000080)
#define  DVBC_OPT_TST_OUT_SEL_opt_tst_out_tri2_mask                              (0x00000070)
#define  DVBC_OPT_TST_OUT_SEL_opt_tst_out_tri1_mask                              (0x0000000E)
#define  DVBC_OPT_TST_OUT_SEL_opt_tst_out_sel_mask                               (0x00000001)
#define  DVBC_OPT_TST_OUT_SEL_opt_par_tstclk(data)                               (0x00000080&((data)<<7))
#define  DVBC_OPT_TST_OUT_SEL_opt_tst_out_tri2(data)                             (0x00000070&((data)<<4))
#define  DVBC_OPT_TST_OUT_SEL_opt_tst_out_tri1(data)                             (0x0000000E&((data)<<1))
#define  DVBC_OPT_TST_OUT_SEL_opt_tst_out_sel(data)                              (0x00000001&(data))
#define  DVBC_OPT_TST_OUT_SEL_get_opt_par_tstclk(data)                           ((0x00000080&(data))>>7)
#define  DVBC_OPT_TST_OUT_SEL_get_opt_tst_out_tri2(data)                         ((0x00000070&(data))>>4)
#define  DVBC_OPT_TST_OUT_SEL_get_opt_tst_out_tri1(data)                         ((0x0000000E&(data))>>1)
#define  DVBC_OPT_TST_OUT_SEL_get_opt_tst_out_sel(data)                          (0x00000001&(data))

#define  DVBC_OPT_MPEG_OUT_SEL                                                   0x180E8098
#define  DVBC_OPT_MPEG_OUT_SEL_reg_addr                                          "0xB80E8098"
#define  DVBC_OPT_MPEG_OUT_SEL_reg                                               0xB80E8098
#define  DVBC_OPT_MPEG_OUT_SEL_inst_addr                                         "0x001A"
#define  set_DVBC_OPT_MPEG_OUT_SEL_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_MPEG_OUT_SEL_reg)=data)
#define  get_DVBC_OPT_MPEG_OUT_SEL_reg                                           (*((volatile unsigned int*)DVBC_OPT_MPEG_OUT_SEL_reg))
#define  DVBC_OPT_MPEG_OUT_SEL_opt_mpeg_out_sel_shift                            (0)
#define  DVBC_OPT_MPEG_OUT_SEL_opt_mpeg_out_sel_mask                             (0x00000003)
#define  DVBC_OPT_MPEG_OUT_SEL_opt_mpeg_out_sel(data)                            (0x00000003&(data))
#define  DVBC_OPT_MPEG_OUT_SEL_get_opt_mpeg_out_sel(data)                        (0x00000003&(data))

#define  DVBC_OPT_PAGE0_RO_STB                                                   0x180E809C
#define  DVBC_OPT_PAGE0_RO_STB_reg_addr                                          "0xB80E809C"
#define  DVBC_OPT_PAGE0_RO_STB_reg                                               0xB80E809C
#define  DVBC_OPT_PAGE0_RO_STB_inst_addr                                         "0x001B"
#define  set_DVBC_OPT_PAGE0_RO_STB_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_PAGE0_RO_STB_reg)=data)
#define  get_DVBC_OPT_PAGE0_RO_STB_reg                                           (*((volatile unsigned int*)DVBC_OPT_PAGE0_RO_STB_reg))
#define  DVBC_OPT_PAGE0_RO_STB_ro_reg_on_shift                                   (1)
#define  DVBC_OPT_PAGE0_RO_STB_opt_page0_ro_stb_shift                            (0)
#define  DVBC_OPT_PAGE0_RO_STB_ro_reg_on_mask                                    (0x00000002)
#define  DVBC_OPT_PAGE0_RO_STB_opt_page0_ro_stb_mask                             (0x00000001)
#define  DVBC_OPT_PAGE0_RO_STB_ro_reg_on(data)                                   (0x00000002&((data)<<1))
#define  DVBC_OPT_PAGE0_RO_STB_opt_page0_ro_stb(data)                            (0x00000001&(data))
#define  DVBC_OPT_PAGE0_RO_STB_get_ro_reg_on(data)                               ((0x00000002&(data))>>1)
#define  DVBC_OPT_PAGE0_RO_STB_get_opt_page0_ro_stb(data)                        (0x00000001&(data))

#define  DVBC_OPT_8051_INT0_EN                                                   0x180E80A0
#define  DVBC_OPT_8051_INT0_EN_reg_addr                                          "0xB80E80A0"
#define  DVBC_OPT_8051_INT0_EN_reg                                               0xB80E80A0
#define  DVBC_OPT_8051_INT0_EN_inst_addr                                         "0x001C"
#define  set_DVBC_OPT_8051_INT0_EN_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_8051_INT0_EN_reg)=data)
#define  get_DVBC_OPT_8051_INT0_EN_reg                                           (*((volatile unsigned int*)DVBC_OPT_8051_INT0_EN_reg))
#define  DVBC_OPT_8051_INT0_EN_opt_8051_int0_en_shift                            (0)
#define  DVBC_OPT_8051_INT0_EN_opt_8051_int0_en_mask                             (0x00000001)
#define  DVBC_OPT_8051_INT0_EN_opt_8051_int0_en(data)                            (0x00000001&(data))
#define  DVBC_OPT_8051_INT0_EN_get_opt_8051_int0_en(data)                        (0x00000001&(data))

#define  DVBC_RO_AGC                                                             0x180E80A8
#define  DVBC_RO_AGC_reg_addr                                                    "0xB80E80A8"
#define  DVBC_RO_AGC_reg                                                         0xB80E80A8
#define  DVBC_RO_AGC_inst_addr                                                   "0x001D"
#define  set_DVBC_RO_AGC_reg(data)                                               (*((volatile unsigned int*)DVBC_RO_AGC_reg)=data)
#define  get_DVBC_RO_AGC_reg                                                     (*((volatile unsigned int*)DVBC_RO_AGC_reg))
#define  DVBC_RO_AGC_ro_if_agc_oe_ro_shift                                       (5)
#define  DVBC_RO_AGC_ro_if_agc_ro_shift                                          (3)
#define  DVBC_RO_AGC_ro_rf_agc_oe_ro_shift                                       (2)
#define  DVBC_RO_AGC_ro_rf_agc_ro_shift                                          (0)
#define  DVBC_RO_AGC_ro_if_agc_oe_ro_mask                                        (0x00000020)
#define  DVBC_RO_AGC_ro_if_agc_ro_mask                                           (0x00000008)
#define  DVBC_RO_AGC_ro_rf_agc_oe_ro_mask                                        (0x00000004)
#define  DVBC_RO_AGC_ro_rf_agc_ro_mask                                           (0x00000001)
#define  DVBC_RO_AGC_ro_if_agc_oe_ro(data)                                       (0x00000020&((data)<<5))
#define  DVBC_RO_AGC_ro_if_agc_ro(data)                                          (0x00000008&((data)<<3))
#define  DVBC_RO_AGC_ro_rf_agc_oe_ro(data)                                       (0x00000004&((data)<<2))
#define  DVBC_RO_AGC_ro_rf_agc_ro(data)                                          (0x00000001&(data))
#define  DVBC_RO_AGC_get_ro_if_agc_oe_ro(data)                                   ((0x00000020&(data))>>5)
#define  DVBC_RO_AGC_get_ro_if_agc_ro(data)                                      ((0x00000008&(data))>>3)
#define  DVBC_RO_AGC_get_ro_rf_agc_oe_ro(data)                                   ((0x00000004&(data))>>2)
#define  DVBC_RO_AGC_get_ro_rf_agc_ro(data)                                      (0x00000001&(data))

#define  DVBC_RSSI_AGC_Q_0                                                       0x180E80AC
#define  DVBC_RSSI_AGC_Q_0_reg_addr                                              "0xB80E80AC"
#define  DVBC_RSSI_AGC_Q_0_reg                                                   0xB80E80AC
#define  DVBC_RSSI_AGC_Q_0_inst_addr                                             "0x001E"
#define  set_DVBC_RSSI_AGC_Q_0_reg(data)                                         (*((volatile unsigned int*)DVBC_RSSI_AGC_Q_0_reg)=data)
#define  get_DVBC_RSSI_AGC_Q_0_reg                                               (*((volatile unsigned int*)DVBC_RSSI_AGC_Q_0_reg))
#define  DVBC_RSSI_AGC_Q_0_rssi_agc_q_ro_7_0_shift                               (0)
#define  DVBC_RSSI_AGC_Q_0_rssi_agc_q_ro_7_0_mask                                (0x000000FF)
#define  DVBC_RSSI_AGC_Q_0_rssi_agc_q_ro_7_0(data)                               (0x000000FF&(data))
#define  DVBC_RSSI_AGC_Q_0_get_rssi_agc_q_ro_7_0(data)                           (0x000000FF&(data))

#define  DVBC_RSSI_AGC_Q_1                                                       0x180E80B0
#define  DVBC_RSSI_AGC_Q_1_reg_addr                                              "0xB80E80B0"
#define  DVBC_RSSI_AGC_Q_1_reg                                                   0xB80E80B0
#define  DVBC_RSSI_AGC_Q_1_inst_addr                                             "0x001F"
#define  set_DVBC_RSSI_AGC_Q_1_reg(data)                                         (*((volatile unsigned int*)DVBC_RSSI_AGC_Q_1_reg)=data)
#define  get_DVBC_RSSI_AGC_Q_1_reg                                               (*((volatile unsigned int*)DVBC_RSSI_AGC_Q_1_reg))
#define  DVBC_RSSI_AGC_Q_1_rssi_agc_q_ro_13_8_shift                              (0)
#define  DVBC_RSSI_AGC_Q_1_rssi_agc_q_ro_13_8_mask                               (0x0000003F)
#define  DVBC_RSSI_AGC_Q_1_rssi_agc_q_ro_13_8(data)                              (0x0000003F&(data))
#define  DVBC_RSSI_AGC_Q_1_get_rssi_agc_q_ro_13_8(data)                          (0x0000003F&(data))

#define  DVBC_RSSI_AGC_LOOP_SAT                                                  0x180E80B4
#define  DVBC_RSSI_AGC_LOOP_SAT_reg_addr                                         "0xB80E80B4"
#define  DVBC_RSSI_AGC_LOOP_SAT_reg                                              0xB80E80B4
#define  DVBC_RSSI_AGC_LOOP_SAT_inst_addr                                        "0x0020"
#define  set_DVBC_RSSI_AGC_LOOP_SAT_reg(data)                                    (*((volatile unsigned int*)DVBC_RSSI_AGC_LOOP_SAT_reg)=data)
#define  get_DVBC_RSSI_AGC_LOOP_SAT_reg                                          (*((volatile unsigned int*)DVBC_RSSI_AGC_LOOP_SAT_reg))
#define  DVBC_RSSI_AGC_LOOP_SAT_rssi_agc_loop_sat_ro_shift                       (0)
#define  DVBC_RSSI_AGC_LOOP_SAT_rssi_agc_loop_sat_ro_mask                        (0x00000001)
#define  DVBC_RSSI_AGC_LOOP_SAT_rssi_agc_loop_sat_ro(data)                       (0x00000001&(data))
#define  DVBC_RSSI_AGC_LOOP_SAT_get_rssi_agc_loop_sat_ro(data)                   (0x00000001&(data))

#define  DVBC_AD7_OUT                                                            0x180E80B8
#define  DVBC_AD7_OUT_reg_addr                                                   "0xB80E80B8"
#define  DVBC_AD7_OUT_reg                                                        0xB80E80B8
#define  DVBC_AD7_OUT_inst_addr                                                  "0x0021"
#define  set_DVBC_AD7_OUT_reg(data)                                              (*((volatile unsigned int*)DVBC_AD7_OUT_reg)=data)
#define  get_DVBC_AD7_OUT_reg                                                    (*((volatile unsigned int*)DVBC_AD7_OUT_reg))
#define  DVBC_AD7_OUT_ad7_out_ro_shift                                           (0)
#define  DVBC_AD7_OUT_ad7_out_ro_mask                                            (0x0000007F)
#define  DVBC_AD7_OUT_ad7_out_ro(data)                                           (0x0000007F&(data))
#define  DVBC_AD7_OUT_get_ad7_out_ro(data)                                       (0x0000007F&(data))

#define  DVBC_QAM_MPEG_OUT_0                                                     0x180E80BC
#define  DVBC_QAM_MPEG_OUT_0_reg_addr                                            "0xB80E80BC"
#define  DVBC_QAM_MPEG_OUT_0_reg                                                 0xB80E80BC
#define  DVBC_QAM_MPEG_OUT_0_inst_addr                                           "0x0022"
#define  set_DVBC_QAM_MPEG_OUT_0_reg(data)                                       (*((volatile unsigned int*)DVBC_QAM_MPEG_OUT_0_reg)=data)
#define  get_DVBC_QAM_MPEG_OUT_0_reg                                             (*((volatile unsigned int*)DVBC_QAM_MPEG_OUT_0_reg))
#define  DVBC_QAM_MPEG_OUT_0_qam_mpeg_out_ro_7_0_shift                           (0)
#define  DVBC_QAM_MPEG_OUT_0_qam_mpeg_out_ro_7_0_mask                            (0x000000FF)
#define  DVBC_QAM_MPEG_OUT_0_qam_mpeg_out_ro_7_0(data)                           (0x000000FF&(data))
#define  DVBC_QAM_MPEG_OUT_0_get_qam_mpeg_out_ro_7_0(data)                       (0x000000FF&(data))

#define  DVBC_QAM_MPEG_OUT_1                                                     0x180E80C0
#define  DVBC_QAM_MPEG_OUT_1_reg_addr                                            "0xB80E80C0"
#define  DVBC_QAM_MPEG_OUT_1_reg                                                 0xB80E80C0
#define  DVBC_QAM_MPEG_OUT_1_inst_addr                                           "0x0023"
#define  set_DVBC_QAM_MPEG_OUT_1_reg(data)                                       (*((volatile unsigned int*)DVBC_QAM_MPEG_OUT_1_reg)=data)
#define  get_DVBC_QAM_MPEG_OUT_1_reg                                             (*((volatile unsigned int*)DVBC_QAM_MPEG_OUT_1_reg))
#define  DVBC_QAM_MPEG_OUT_1_qam_mpeg_out_ro_11_8_shift                          (0)
#define  DVBC_QAM_MPEG_OUT_1_qam_mpeg_out_ro_11_8_mask                           (0x0000000F)
#define  DVBC_QAM_MPEG_OUT_1_qam_mpeg_out_ro_11_8(data)                          (0x0000000F&(data))
#define  DVBC_QAM_MPEG_OUT_1_get_qam_mpeg_out_ro_11_8(data)                      (0x0000000F&(data))

#define  DVBC_QAM_DEBUG_0                                                        0x180E80D4
#define  DVBC_QAM_DEBUG_0_reg_addr                                               "0xB80E80D4"
#define  DVBC_QAM_DEBUG_0_reg                                                    0xB80E80D4
#define  DVBC_QAM_DEBUG_0_inst_addr                                              "0x0024"
#define  set_DVBC_QAM_DEBUG_0_reg(data)                                          (*((volatile unsigned int*)DVBC_QAM_DEBUG_0_reg)=data)
#define  get_DVBC_QAM_DEBUG_0_reg                                                (*((volatile unsigned int*)DVBC_QAM_DEBUG_0_reg))
#define  DVBC_QAM_DEBUG_0_ro_debug_ro_7_0_shift                                  (0)
#define  DVBC_QAM_DEBUG_0_ro_debug_ro_7_0_mask                                   (0x000000FF)
#define  DVBC_QAM_DEBUG_0_ro_debug_ro_7_0(data)                                  (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_0_get_ro_debug_ro_7_0(data)                              (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_1                                                        0x180E80D8
#define  DVBC_QAM_DEBUG_1_reg_addr                                               "0xB80E80D8"
#define  DVBC_QAM_DEBUG_1_reg                                                    0xB80E80D8
#define  DVBC_QAM_DEBUG_1_inst_addr                                              "0x0025"
#define  set_DVBC_QAM_DEBUG_1_reg(data)                                          (*((volatile unsigned int*)DVBC_QAM_DEBUG_1_reg)=data)
#define  get_DVBC_QAM_DEBUG_1_reg                                                (*((volatile unsigned int*)DVBC_QAM_DEBUG_1_reg))
#define  DVBC_QAM_DEBUG_1_ro_debug_ro_15_8_shift                                 (0)
#define  DVBC_QAM_DEBUG_1_ro_debug_ro_15_8_mask                                  (0x000000FF)
#define  DVBC_QAM_DEBUG_1_ro_debug_ro_15_8(data)                                 (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_1_get_ro_debug_ro_15_8(data)                             (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_2                                                        0x180E80DC
#define  DVBC_QAM_DEBUG_2_reg_addr                                               "0xB80E80DC"
#define  DVBC_QAM_DEBUG_2_reg                                                    0xB80E80DC
#define  DVBC_QAM_DEBUG_2_inst_addr                                              "0x0026"
#define  set_DVBC_QAM_DEBUG_2_reg(data)                                          (*((volatile unsigned int*)DVBC_QAM_DEBUG_2_reg)=data)
#define  get_DVBC_QAM_DEBUG_2_reg                                                (*((volatile unsigned int*)DVBC_QAM_DEBUG_2_reg))
#define  DVBC_QAM_DEBUG_2_ro_debug_ro_23_16_shift                                (0)
#define  DVBC_QAM_DEBUG_2_ro_debug_ro_23_16_mask                                 (0x000000FF)
#define  DVBC_QAM_DEBUG_2_ro_debug_ro_23_16(data)                                (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_2_get_ro_debug_ro_23_16(data)                            (0x000000FF&(data))

#define  DVBC_QAM_DEBUG_3                                                        0x180E80E0
#define  DVBC_QAM_DEBUG_3_reg_addr                                               "0xB80E80E0"
#define  DVBC_QAM_DEBUG_3_reg                                                    0xB80E80E0
#define  DVBC_QAM_DEBUG_3_inst_addr                                              "0x0027"
#define  set_DVBC_QAM_DEBUG_3_reg(data)                                          (*((volatile unsigned int*)DVBC_QAM_DEBUG_3_reg)=data)
#define  get_DVBC_QAM_DEBUG_3_reg                                                (*((volatile unsigned int*)DVBC_QAM_DEBUG_3_reg))
#define  DVBC_QAM_DEBUG_3_ro_debug_ro_31_24_shift                                (0)
#define  DVBC_QAM_DEBUG_3_ro_debug_ro_31_24_mask                                 (0x000000FF)
#define  DVBC_QAM_DEBUG_3_ro_debug_ro_31_24(data)                                (0x000000FF&(data))
#define  DVBC_QAM_DEBUG_3_get_ro_debug_ro_31_24(data)                            (0x000000FF&(data))

#define  DVBC_PAGE0_RW40_RESERVED                                                0x180E8100
#define  DVBC_PAGE0_RW40_RESERVED_reg_addr                                       "0xB80E8100"
#define  DVBC_PAGE0_RW40_RESERVED_reg                                            0xB80E8100
#define  DVBC_PAGE0_RW40_RESERVED_inst_addr                                      "0x0028"
#define  set_DVBC_PAGE0_RW40_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW40_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW40_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW40_RESERVED_reg))
#define  DVBC_PAGE0_RW40_RESERVED_page0_rw40_reserved_shift                      (0)
#define  DVBC_PAGE0_RW40_RESERVED_page0_rw40_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW40_RESERVED_page0_rw40_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW40_RESERVED_get_page0_rw40_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW41_RESERVED                                                0x180E8104
#define  DVBC_PAGE0_RW41_RESERVED_reg_addr                                       "0xB80E8104"
#define  DVBC_PAGE0_RW41_RESERVED_reg                                            0xB80E8104
#define  DVBC_PAGE0_RW41_RESERVED_inst_addr                                      "0x0029"
#define  set_DVBC_PAGE0_RW41_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW41_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW41_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW41_RESERVED_reg))
#define  DVBC_PAGE0_RW41_RESERVED_page0_rw41_reserved_shift                      (0)
#define  DVBC_PAGE0_RW41_RESERVED_page0_rw41_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW41_RESERVED_page0_rw41_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW41_RESERVED_get_page0_rw41_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW42_RESERVED                                                0x180E8108
#define  DVBC_PAGE0_RW42_RESERVED_reg_addr                                       "0xB80E8108"
#define  DVBC_PAGE0_RW42_RESERVED_reg                                            0xB80E8108
#define  DVBC_PAGE0_RW42_RESERVED_inst_addr                                      "0x002A"
#define  set_DVBC_PAGE0_RW42_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW42_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW42_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW42_RESERVED_reg))
#define  DVBC_PAGE0_RW42_RESERVED_page0_rw42_reserved_shift                      (0)
#define  DVBC_PAGE0_RW42_RESERVED_page0_rw42_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW42_RESERVED_page0_rw42_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW42_RESERVED_get_page0_rw42_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW43_RESERVED                                                0x180E810C
#define  DVBC_PAGE0_RW43_RESERVED_reg_addr                                       "0xB80E810C"
#define  DVBC_PAGE0_RW43_RESERVED_reg                                            0xB80E810C
#define  DVBC_PAGE0_RW43_RESERVED_inst_addr                                      "0x002B"
#define  set_DVBC_PAGE0_RW43_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW43_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW43_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW43_RESERVED_reg))
#define  DVBC_PAGE0_RW43_RESERVED_page0_rw43_reserved_shift                      (0)
#define  DVBC_PAGE0_RW43_RESERVED_page0_rw43_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW43_RESERVED_page0_rw43_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW43_RESERVED_get_page0_rw43_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW44_RESERVED                                                0x180E8110
#define  DVBC_PAGE0_RW44_RESERVED_reg_addr                                       "0xB80E8110"
#define  DVBC_PAGE0_RW44_RESERVED_reg                                            0xB80E8110
#define  DVBC_PAGE0_RW44_RESERVED_inst_addr                                      "0x002C"
#define  set_DVBC_PAGE0_RW44_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW44_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW44_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW44_RESERVED_reg))
#define  DVBC_PAGE0_RW44_RESERVED_page0_rw44_reserved_shift                      (0)
#define  DVBC_PAGE0_RW44_RESERVED_page0_rw44_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW44_RESERVED_page0_rw44_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW44_RESERVED_get_page0_rw44_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW45_RESERVED                                                0x180E8114
#define  DVBC_PAGE0_RW45_RESERVED_reg_addr                                       "0xB80E8114"
#define  DVBC_PAGE0_RW45_RESERVED_reg                                            0xB80E8114
#define  DVBC_PAGE0_RW45_RESERVED_inst_addr                                      "0x002D"
#define  set_DVBC_PAGE0_RW45_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW45_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW45_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW45_RESERVED_reg))
#define  DVBC_PAGE0_RW45_RESERVED_page0_rw45_reserved_shift                      (0)
#define  DVBC_PAGE0_RW45_RESERVED_page0_rw45_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW45_RESERVED_page0_rw45_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW45_RESERVED_get_page0_rw45_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW46_RESERVED                                                0x180E8118
#define  DVBC_PAGE0_RW46_RESERVED_reg_addr                                       "0xB80E8118"
#define  DVBC_PAGE0_RW46_RESERVED_reg                                            0xB80E8118
#define  DVBC_PAGE0_RW46_RESERVED_inst_addr                                      "0x002E"
#define  set_DVBC_PAGE0_RW46_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW46_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW46_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW46_RESERVED_reg))
#define  DVBC_PAGE0_RW46_RESERVED_page0_rw46_reserved_shift                      (0)
#define  DVBC_PAGE0_RW46_RESERVED_page0_rw46_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW46_RESERVED_page0_rw46_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW46_RESERVED_get_page0_rw46_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW47_RESERVED                                                0x180E811C
#define  DVBC_PAGE0_RW47_RESERVED_reg_addr                                       "0xB80E811C"
#define  DVBC_PAGE0_RW47_RESERVED_reg                                            0xB80E811C
#define  DVBC_PAGE0_RW47_RESERVED_inst_addr                                      "0x002F"
#define  set_DVBC_PAGE0_RW47_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW47_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW47_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW47_RESERVED_reg))
#define  DVBC_PAGE0_RW47_RESERVED_page0_rw47_reserved_shift                      (0)
#define  DVBC_PAGE0_RW47_RESERVED_page0_rw47_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW47_RESERVED_page0_rw47_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW47_RESERVED_get_page0_rw47_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW48_RESERVED                                                0x180E8120
#define  DVBC_PAGE0_RW48_RESERVED_reg_addr                                       "0xB80E8120"
#define  DVBC_PAGE0_RW48_RESERVED_reg                                            0xB80E8120
#define  DVBC_PAGE0_RW48_RESERVED_inst_addr                                      "0x0030"
#define  set_DVBC_PAGE0_RW48_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW48_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW48_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW48_RESERVED_reg))
#define  DVBC_PAGE0_RW48_RESERVED_page0_ro48_reserved_shift                      (0)
#define  DVBC_PAGE0_RW48_RESERVED_page0_ro48_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW48_RESERVED_page0_ro48_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW48_RESERVED_get_page0_ro48_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW49_RESERVED                                                0x180E8124
#define  DVBC_PAGE0_RW49_RESERVED_reg_addr                                       "0xB80E8124"
#define  DVBC_PAGE0_RW49_RESERVED_reg                                            0xB80E8124
#define  DVBC_PAGE0_RW49_RESERVED_inst_addr                                      "0x0031"
#define  set_DVBC_PAGE0_RW49_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW49_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW49_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW49_RESERVED_reg))
#define  DVBC_PAGE0_RW49_RESERVED_page0_ro49_reserved_shift                      (0)
#define  DVBC_PAGE0_RW49_RESERVED_page0_ro49_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW49_RESERVED_page0_ro49_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW49_RESERVED_get_page0_ro49_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW4A_RESERVED                                                0x180E8128
#define  DVBC_PAGE0_RW4A_RESERVED_reg_addr                                       "0xB80E8128"
#define  DVBC_PAGE0_RW4A_RESERVED_reg                                            0xB80E8128
#define  DVBC_PAGE0_RW4A_RESERVED_inst_addr                                      "0x0032"
#define  set_DVBC_PAGE0_RW4A_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW4A_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW4A_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW4A_RESERVED_reg))
#define  DVBC_PAGE0_RW4A_RESERVED_page0_ro4a_reserved_shift                      (0)
#define  DVBC_PAGE0_RW4A_RESERVED_page0_ro4a_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW4A_RESERVED_page0_ro4a_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW4A_RESERVED_get_page0_ro4a_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE0_RW4B_RESERVED                                                0x180E812C
#define  DVBC_PAGE0_RW4B_RESERVED_reg_addr                                       "0xB80E812C"
#define  DVBC_PAGE0_RW4B_RESERVED_reg                                            0xB80E812C
#define  DVBC_PAGE0_RW4B_RESERVED_inst_addr                                      "0x0033"
#define  set_DVBC_PAGE0_RW4B_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE0_RW4B_RESERVED_reg)=data)
#define  get_DVBC_PAGE0_RW4B_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE0_RW4B_RESERVED_reg))
#define  DVBC_PAGE0_RW4B_RESERVED_page0_ro4b_reserved_shift                      (0)
#define  DVBC_PAGE0_RW4B_RESERVED_page0_ro4b_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE0_RW4B_RESERVED_page0_ro4b_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE0_RW4B_RESERVED_get_page0_ro4b_reserved(data)                  (0x000000FF&(data))

#define  DVBC_OPT_SOFT_RESET_RSSI_AGC                                            0x180E8140
#define  DVBC_OPT_SOFT_RESET_RSSI_AGC_reg_addr                                   "0xB80E8140"
#define  DVBC_OPT_SOFT_RESET_RSSI_AGC_reg                                        0xB80E8140
#define  DVBC_OPT_SOFT_RESET_RSSI_AGC_inst_addr                                  "0x0034"
#define  set_DVBC_OPT_SOFT_RESET_RSSI_AGC_reg(data)                              (*((volatile unsigned int*)DVBC_OPT_SOFT_RESET_RSSI_AGC_reg)=data)
#define  get_DVBC_OPT_SOFT_RESET_RSSI_AGC_reg                                    (*((volatile unsigned int*)DVBC_OPT_SOFT_RESET_RSSI_AGC_reg))
#define  DVBC_OPT_SOFT_RESET_RSSI_AGC_opt_soft_reset_rssi_agc_shift              (0)
#define  DVBC_OPT_SOFT_RESET_RSSI_AGC_opt_soft_reset_rssi_agc_mask               (0x00000001)
#define  DVBC_OPT_SOFT_RESET_RSSI_AGC_opt_soft_reset_rssi_agc(data)              (0x00000001&(data))
#define  DVBC_OPT_SOFT_RESET_RSSI_AGC_get_opt_soft_reset_rssi_agc(data)          (0x00000001&(data))

#define  DVBC_OPT_RSSI_AGC_ON                                                    0x180E8144
#define  DVBC_OPT_RSSI_AGC_ON_reg_addr                                           "0xB80E8144"
#define  DVBC_OPT_RSSI_AGC_ON_reg                                                0xB80E8144
#define  DVBC_OPT_RSSI_AGC_ON_inst_addr                                          "0x0035"
#define  set_DVBC_OPT_RSSI_AGC_ON_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_RSSI_AGC_ON_reg)=data)
#define  get_DVBC_OPT_RSSI_AGC_ON_reg                                            (*((volatile unsigned int*)DVBC_OPT_RSSI_AGC_ON_reg))
#define  DVBC_OPT_RSSI_AGC_ON_u_rssi_agc_exp_shift                               (2)
#define  DVBC_OPT_RSSI_AGC_ON_rssi_in_ph_sel_shift                               (1)
#define  DVBC_OPT_RSSI_AGC_ON_opt_rssi_agc_on_shift                              (0)
#define  DVBC_OPT_RSSI_AGC_ON_u_rssi_agc_exp_mask                                (0x0000001C)
#define  DVBC_OPT_RSSI_AGC_ON_rssi_in_ph_sel_mask                                (0x00000002)
#define  DVBC_OPT_RSSI_AGC_ON_opt_rssi_agc_on_mask                               (0x00000001)
#define  DVBC_OPT_RSSI_AGC_ON_u_rssi_agc_exp(data)                               (0x0000001C&((data)<<2))
#define  DVBC_OPT_RSSI_AGC_ON_rssi_in_ph_sel(data)                               (0x00000002&((data)<<1))
#define  DVBC_OPT_RSSI_AGC_ON_opt_rssi_agc_on(data)                              (0x00000001&(data))
#define  DVBC_OPT_RSSI_AGC_ON_get_u_rssi_agc_exp(data)                           ((0x0000001C&(data))>>2)
#define  DVBC_OPT_RSSI_AGC_ON_get_rssi_in_ph_sel(data)                           ((0x00000002&(data))>>1)
#define  DVBC_OPT_RSSI_AGC_ON_get_opt_rssi_agc_on(data)                          (0x00000001&(data))

#define  DVBC_RSSI_IN_CLK_RATIO                                                  0x180E8148
#define  DVBC_RSSI_IN_CLK_RATIO_reg_addr                                         "0xB80E8148"
#define  DVBC_RSSI_IN_CLK_RATIO_reg                                              0xB80E8148
#define  DVBC_RSSI_IN_CLK_RATIO_inst_addr                                        "0x0036"
#define  set_DVBC_RSSI_IN_CLK_RATIO_reg(data)                                    (*((volatile unsigned int*)DVBC_RSSI_IN_CLK_RATIO_reg)=data)
#define  get_DVBC_RSSI_IN_CLK_RATIO_reg                                          (*((volatile unsigned int*)DVBC_RSSI_IN_CLK_RATIO_reg))
#define  DVBC_RSSI_IN_CLK_RATIO_rssi_in_clk_ratio_shift                          (0)
#define  DVBC_RSSI_IN_CLK_RATIO_rssi_in_clk_ratio_mask                           (0x000000FF)
#define  DVBC_RSSI_IN_CLK_RATIO_rssi_in_clk_ratio(data)                          (0x000000FF&(data))
#define  DVBC_RSSI_IN_CLK_RATIO_get_rssi_in_clk_ratio(data)                      (0x000000FF&(data))

#define  DVBC_RSSI_AGC_MAX                                                       0x180E814C
#define  DVBC_RSSI_AGC_MAX_reg_addr                                              "0xB80E814C"
#define  DVBC_RSSI_AGC_MAX_reg                                                   0xB80E814C
#define  DVBC_RSSI_AGC_MAX_inst_addr                                             "0x0037"
#define  set_DVBC_RSSI_AGC_MAX_reg(data)                                         (*((volatile unsigned int*)DVBC_RSSI_AGC_MAX_reg)=data)
#define  get_DVBC_RSSI_AGC_MAX_reg                                               (*((volatile unsigned int*)DVBC_RSSI_AGC_MAX_reg))
#define  DVBC_RSSI_AGC_MAX_rssi_agc_max_shift                                    (0)
#define  DVBC_RSSI_AGC_MAX_rssi_agc_max_mask                                     (0x000000FF)
#define  DVBC_RSSI_AGC_MAX_rssi_agc_max(data)                                    (0x000000FF&(data))
#define  DVBC_RSSI_AGC_MAX_get_rssi_agc_max(data)                                (0x000000FF&(data))

#define  DVBC_RSSI_AGC_MIN                                                       0x180E8150
#define  DVBC_RSSI_AGC_MIN_reg_addr                                              "0xB80E8150"
#define  DVBC_RSSI_AGC_MIN_reg                                                   0xB80E8150
#define  DVBC_RSSI_AGC_MIN_inst_addr                                             "0x0038"
#define  set_DVBC_RSSI_AGC_MIN_reg(data)                                         (*((volatile unsigned int*)DVBC_RSSI_AGC_MIN_reg)=data)
#define  get_DVBC_RSSI_AGC_MIN_reg                                               (*((volatile unsigned int*)DVBC_RSSI_AGC_MIN_reg))
#define  DVBC_RSSI_AGC_MIN_rssi_agc_min_shift                                    (0)
#define  DVBC_RSSI_AGC_MIN_rssi_agc_min_mask                                     (0x000000FF)
#define  DVBC_RSSI_AGC_MIN_rssi_agc_min(data)                                    (0x000000FF&(data))
#define  DVBC_RSSI_AGC_MIN_get_rssi_agc_min(data)                                (0x000000FF&(data))

#define  DVBC_RSSI_AGC_TARG_VAL                                                  0x180E8154
#define  DVBC_RSSI_AGC_TARG_VAL_reg_addr                                         "0xB80E8154"
#define  DVBC_RSSI_AGC_TARG_VAL_reg                                              0xB80E8154
#define  DVBC_RSSI_AGC_TARG_VAL_inst_addr                                        "0x0039"
#define  set_DVBC_RSSI_AGC_TARG_VAL_reg(data)                                    (*((volatile unsigned int*)DVBC_RSSI_AGC_TARG_VAL_reg)=data)
#define  get_DVBC_RSSI_AGC_TARG_VAL_reg                                          (*((volatile unsigned int*)DVBC_RSSI_AGC_TARG_VAL_reg))
#define  DVBC_RSSI_AGC_TARG_VAL_rssi_agc_pol_shift                               (7)
#define  DVBC_RSSI_AGC_TARG_VAL_rssi_agc_targ_val_shift                          (0)
#define  DVBC_RSSI_AGC_TARG_VAL_rssi_agc_pol_mask                                (0x00000080)
#define  DVBC_RSSI_AGC_TARG_VAL_rssi_agc_targ_val_mask                           (0x0000007F)
#define  DVBC_RSSI_AGC_TARG_VAL_rssi_agc_pol(data)                               (0x00000080&((data)<<7))
#define  DVBC_RSSI_AGC_TARG_VAL_rssi_agc_targ_val(data)                          (0x0000007F&(data))
#define  DVBC_RSSI_AGC_TARG_VAL_get_rssi_agc_pol(data)                           ((0x00000080&(data))>>7)
#define  DVBC_RSSI_AGC_TARG_VAL_get_rssi_agc_targ_val(data)                      (0x0000007F&(data))

#define  DVBC_OPT_AD7_CKOUT_INV                                                  0x180E8158
#define  DVBC_OPT_AD7_CKOUT_INV_reg_addr                                         "0xB80E8158"
#define  DVBC_OPT_AD7_CKOUT_INV_reg                                              0xB80E8158
#define  DVBC_OPT_AD7_CKOUT_INV_inst_addr                                        "0x003A"
#define  set_DVBC_OPT_AD7_CKOUT_INV_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_AD7_CKOUT_INV_reg)=data)
#define  get_DVBC_OPT_AD7_CKOUT_INV_reg                                          (*((volatile unsigned int*)DVBC_OPT_AD7_CKOUT_INV_reg))
#define  DVBC_OPT_AD7_CKOUT_INV_rssi_in_ph_sel2_shift                            (1)
#define  DVBC_OPT_AD7_CKOUT_INV_opt_ad7_ckout_inv_shift                          (0)
#define  DVBC_OPT_AD7_CKOUT_INV_rssi_in_ph_sel2_mask                             (0x00000002)
#define  DVBC_OPT_AD7_CKOUT_INV_opt_ad7_ckout_inv_mask                           (0x00000001)
#define  DVBC_OPT_AD7_CKOUT_INV_rssi_in_ph_sel2(data)                            (0x00000002&((data)<<1))
#define  DVBC_OPT_AD7_CKOUT_INV_opt_ad7_ckout_inv(data)                          (0x00000001&(data))
#define  DVBC_OPT_AD7_CKOUT_INV_get_rssi_in_ph_sel2(data)                        ((0x00000002&(data))>>1)
#define  DVBC_OPT_AD7_CKOUT_INV_get_opt_ad7_ckout_inv(data)                      (0x00000001&(data))

#define  DVBC_REG_ADC_CLK_XOR                                                    0x180E8180
#define  DVBC_REG_ADC_CLK_XOR_reg_addr                                           "0xB80E8180"
#define  DVBC_REG_ADC_CLK_XOR_reg                                                0xB80E8180
#define  DVBC_REG_ADC_CLK_XOR_inst_addr                                          "0x003B"
#define  set_DVBC_REG_ADC_CLK_XOR_reg(data)                                      (*((volatile unsigned int*)DVBC_REG_ADC_CLK_XOR_reg)=data)
#define  get_DVBC_REG_ADC_CLK_XOR_reg                                            (*((volatile unsigned int*)DVBC_REG_ADC_CLK_XOR_reg))
#define  DVBC_REG_ADC_CLK_XOR_reg_hold_pga_shift                                 (7)
#define  DVBC_REG_ADC_CLK_XOR_reg_pset_aagc_shift                                (6)
#define  DVBC_REG_ADC_CLK_XOR_reg_aagc_cal_payload_shift                         (5)
#define  DVBC_REG_ADC_CLK_XOR_reg_aagc_hold_shift                                (4)
#define  DVBC_REG_ADC_CLK_XOR_reg_en_gi_pga_shift                                (3)
#define  DVBC_REG_ADC_CLK_XOR_reg_en_pga_mode_shift                              (2)
#define  DVBC_REG_ADC_CLK_XOR_reg_en_dcr_shift                                   (1)
#define  DVBC_REG_ADC_CLK_XOR_reg_adc_clk_xor_shift                              (0)
#define  DVBC_REG_ADC_CLK_XOR_reg_hold_pga_mask                                  (0x00000080)
#define  DVBC_REG_ADC_CLK_XOR_reg_pset_aagc_mask                                 (0x00000040)
#define  DVBC_REG_ADC_CLK_XOR_reg_aagc_cal_payload_mask                          (0x00000020)
#define  DVBC_REG_ADC_CLK_XOR_reg_aagc_hold_mask                                 (0x00000010)
#define  DVBC_REG_ADC_CLK_XOR_reg_en_gi_pga_mask                                 (0x00000008)
#define  DVBC_REG_ADC_CLK_XOR_reg_en_pga_mode_mask                               (0x00000004)
#define  DVBC_REG_ADC_CLK_XOR_reg_en_dcr_mask                                    (0x00000002)
#define  DVBC_REG_ADC_CLK_XOR_reg_adc_clk_xor_mask                               (0x00000001)
#define  DVBC_REG_ADC_CLK_XOR_reg_hold_pga(data)                                 (0x00000080&((data)<<7))
#define  DVBC_REG_ADC_CLK_XOR_reg_pset_aagc(data)                                (0x00000040&((data)<<6))
#define  DVBC_REG_ADC_CLK_XOR_reg_aagc_cal_payload(data)                         (0x00000020&((data)<<5))
#define  DVBC_REG_ADC_CLK_XOR_reg_aagc_hold(data)                                (0x00000010&((data)<<4))
#define  DVBC_REG_ADC_CLK_XOR_reg_en_gi_pga(data)                                (0x00000008&((data)<<3))
#define  DVBC_REG_ADC_CLK_XOR_reg_en_pga_mode(data)                              (0x00000004&((data)<<2))
#define  DVBC_REG_ADC_CLK_XOR_reg_en_dcr(data)                                   (0x00000002&((data)<<1))
#define  DVBC_REG_ADC_CLK_XOR_reg_adc_clk_xor(data)                              (0x00000001&(data))
#define  DVBC_REG_ADC_CLK_XOR_get_reg_hold_pga(data)                             ((0x00000080&(data))>>7)
#define  DVBC_REG_ADC_CLK_XOR_get_reg_pset_aagc(data)                            ((0x00000040&(data))>>6)
#define  DVBC_REG_ADC_CLK_XOR_get_reg_aagc_cal_payload(data)                     ((0x00000020&(data))>>5)
#define  DVBC_REG_ADC_CLK_XOR_get_reg_aagc_hold(data)                            ((0x00000010&(data))>>4)
#define  DVBC_REG_ADC_CLK_XOR_get_reg_en_gi_pga(data)                            ((0x00000008&(data))>>3)
#define  DVBC_REG_ADC_CLK_XOR_get_reg_en_pga_mode(data)                          ((0x00000004&(data))>>2)
#define  DVBC_REG_ADC_CLK_XOR_get_reg_en_dcr(data)                               ((0x00000002&(data))>>1)
#define  DVBC_REG_ADC_CLK_XOR_get_reg_adc_clk_xor(data)                          (0x00000001&(data))

#define  DVBC_REG_TARGET_VAL                                                     0x180E8184
#define  DVBC_REG_TARGET_VAL_reg_addr                                            "0xB80E8184"
#define  DVBC_REG_TARGET_VAL_reg                                                 0xB80E8184
#define  DVBC_REG_TARGET_VAL_inst_addr                                           "0x003C"
#define  set_DVBC_REG_TARGET_VAL_reg(data)                                       (*((volatile unsigned int*)DVBC_REG_TARGET_VAL_reg)=data)
#define  get_DVBC_REG_TARGET_VAL_reg                                             (*((volatile unsigned int*)DVBC_REG_TARGET_VAL_reg))
#define  DVBC_REG_TARGET_VAL_reg_target_val_shift                                (0)
#define  DVBC_REG_TARGET_VAL_reg_target_val_mask                                 (0x000000FF)
#define  DVBC_REG_TARGET_VAL_reg_target_val(data)                                (0x000000FF&(data))
#define  DVBC_REG_TARGET_VAL_get_reg_target_val(data)                            (0x000000FF&(data))

#define  DVBC_REG_AAGC_LOOPGAIN0                                                 0x180E8188
#define  DVBC_REG_AAGC_LOOPGAIN0_reg_addr                                        "0xB80E8188"
#define  DVBC_REG_AAGC_LOOPGAIN0_reg                                             0xB80E8188
#define  DVBC_REG_AAGC_LOOPGAIN0_inst_addr                                       "0x003D"
#define  set_DVBC_REG_AAGC_LOOPGAIN0_reg(data)                                   (*((volatile unsigned int*)DVBC_REG_AAGC_LOOPGAIN0_reg)=data)
#define  get_DVBC_REG_AAGC_LOOPGAIN0_reg                                         (*((volatile unsigned int*)DVBC_REG_AAGC_LOOPGAIN0_reg))
#define  DVBC_REG_AAGC_LOOPGAIN0_reg_aagc_loopgain1_2_0_shift                    (5)
#define  DVBC_REG_AAGC_LOOPGAIN0_reg_aagc_loopgain0_shift                        (0)
#define  DVBC_REG_AAGC_LOOPGAIN0_reg_aagc_loopgain1_2_0_mask                     (0x000000E0)
#define  DVBC_REG_AAGC_LOOPGAIN0_reg_aagc_loopgain0_mask                         (0x0000001F)
#define  DVBC_REG_AAGC_LOOPGAIN0_reg_aagc_loopgain1_2_0(data)                    (0x000000E0&((data)<<5))
#define  DVBC_REG_AAGC_LOOPGAIN0_reg_aagc_loopgain0(data)                        (0x0000001F&(data))
#define  DVBC_REG_AAGC_LOOPGAIN0_get_reg_aagc_loopgain1_2_0(data)                ((0x000000E0&(data))>>5)
#define  DVBC_REG_AAGC_LOOPGAIN0_get_reg_aagc_loopgain0(data)                    (0x0000001F&(data))

#define  DVBC_REG_AAGC_LOOPGAIN0_1                                               0x180E818C
#define  DVBC_REG_AAGC_LOOPGAIN0_1_reg_addr                                      "0xB80E818C"
#define  DVBC_REG_AAGC_LOOPGAIN0_1_reg                                           0xB80E818C
#define  DVBC_REG_AAGC_LOOPGAIN0_1_inst_addr                                     "0x003E"
#define  set_DVBC_REG_AAGC_LOOPGAIN0_1_reg(data)                                 (*((volatile unsigned int*)DVBC_REG_AAGC_LOOPGAIN0_1_reg)=data)
#define  get_DVBC_REG_AAGC_LOOPGAIN0_1_reg                                       (*((volatile unsigned int*)DVBC_REG_AAGC_LOOPGAIN0_1_reg))
#define  DVBC_REG_AAGC_LOOPGAIN0_1_reg_aagc_loopgain2_shift                      (2)
#define  DVBC_REG_AAGC_LOOPGAIN0_1_reg_aagc_loopgain1_4_3_shift                  (0)
#define  DVBC_REG_AAGC_LOOPGAIN0_1_reg_aagc_loopgain2_mask                       (0x0000007C)
#define  DVBC_REG_AAGC_LOOPGAIN0_1_reg_aagc_loopgain1_4_3_mask                   (0x00000003)
#define  DVBC_REG_AAGC_LOOPGAIN0_1_reg_aagc_loopgain2(data)                      (0x0000007C&((data)<<2))
#define  DVBC_REG_AAGC_LOOPGAIN0_1_reg_aagc_loopgain1_4_3(data)                  (0x00000003&(data))
#define  DVBC_REG_AAGC_LOOPGAIN0_1_get_reg_aagc_loopgain2(data)                  ((0x0000007C&(data))>>2)
#define  DVBC_REG_AAGC_LOOPGAIN0_1_get_reg_aagc_loopgain1_4_3(data)              (0x00000003&(data))

#define  DVBC_REG_AAGC_LOCK_DET_LEN                                              0x180E8190
#define  DVBC_REG_AAGC_LOCK_DET_LEN_reg_addr                                     "0xB80E8190"
#define  DVBC_REG_AAGC_LOCK_DET_LEN_reg                                          0xB80E8190
#define  DVBC_REG_AAGC_LOCK_DET_LEN_inst_addr                                    "0x003F"
#define  set_DVBC_REG_AAGC_LOCK_DET_LEN_reg(data)                                (*((volatile unsigned int*)DVBC_REG_AAGC_LOCK_DET_LEN_reg)=data)
#define  get_DVBC_REG_AAGC_LOCK_DET_LEN_reg                                      (*((volatile unsigned int*)DVBC_REG_AAGC_LOCK_DET_LEN_reg))
#define  DVBC_REG_AAGC_LOCK_DET_LEN_reg_aagc_lock_det_thd_shift                  (4)
#define  DVBC_REG_AAGC_LOCK_DET_LEN_reg_aagc_lock_det_len_shift                  (0)
#define  DVBC_REG_AAGC_LOCK_DET_LEN_reg_aagc_lock_det_thd_mask                   (0x000000F0)
#define  DVBC_REG_AAGC_LOCK_DET_LEN_reg_aagc_lock_det_len_mask                   (0x0000000F)
#define  DVBC_REG_AAGC_LOCK_DET_LEN_reg_aagc_lock_det_thd(data)                  (0x000000F0&((data)<<4))
#define  DVBC_REG_AAGC_LOCK_DET_LEN_reg_aagc_lock_det_len(data)                  (0x0000000F&(data))
#define  DVBC_REG_AAGC_LOCK_DET_LEN_get_reg_aagc_lock_det_thd(data)              ((0x000000F0&(data))>>4)
#define  DVBC_REG_AAGC_LOCK_DET_LEN_get_reg_aagc_lock_det_len(data)              (0x0000000F&(data))

#define  DVBC_REG_PSET_AAGC_VAL                                                  0x180E8194
#define  DVBC_REG_PSET_AAGC_VAL_reg_addr                                         "0xB80E8194"
#define  DVBC_REG_PSET_AAGC_VAL_reg                                              0xB80E8194
#define  DVBC_REG_PSET_AAGC_VAL_inst_addr                                        "0x0040"
#define  set_DVBC_REG_PSET_AAGC_VAL_reg(data)                                    (*((volatile unsigned int*)DVBC_REG_PSET_AAGC_VAL_reg)=data)
#define  get_DVBC_REG_PSET_AAGC_VAL_reg                                          (*((volatile unsigned int*)DVBC_REG_PSET_AAGC_VAL_reg))
#define  DVBC_REG_PSET_AAGC_VAL_reg_pset_aagc_val_shift                          (0)
#define  DVBC_REG_PSET_AAGC_VAL_reg_pset_aagc_val_mask                           (0x000000FF)
#define  DVBC_REG_PSET_AAGC_VAL_reg_pset_aagc_val(data)                          (0x000000FF&(data))
#define  DVBC_REG_PSET_AAGC_VAL_get_reg_pset_aagc_val(data)                      (0x000000FF&(data))

#define  DVBC_REG_AAGC_LATENCY                                                   0x180E8198
#define  DVBC_REG_AAGC_LATENCY_reg_addr                                          "0xB80E8198"
#define  DVBC_REG_AAGC_LATENCY_reg                                               0xB80E8198
#define  DVBC_REG_AAGC_LATENCY_inst_addr                                         "0x0041"
#define  set_DVBC_REG_AAGC_LATENCY_reg(data)                                     (*((volatile unsigned int*)DVBC_REG_AAGC_LATENCY_reg)=data)
#define  get_DVBC_REG_AAGC_LATENCY_reg                                           (*((volatile unsigned int*)DVBC_REG_AAGC_LATENCY_reg))
#define  DVBC_REG_AAGC_LATENCY_reg_aagc_latency_7_0_shift                        (0)
#define  DVBC_REG_AAGC_LATENCY_reg_aagc_latency_7_0_mask                         (0x000000FF)
#define  DVBC_REG_AAGC_LATENCY_reg_aagc_latency_7_0(data)                        (0x000000FF&(data))
#define  DVBC_REG_AAGC_LATENCY_get_reg_aagc_latency_7_0(data)                    (0x000000FF&(data))

#define  DVBC_REG_AAGC_LATENCY_1                                                 0x180E819C
#define  DVBC_REG_AAGC_LATENCY_1_reg_addr                                        "0xB80E819C"
#define  DVBC_REG_AAGC_LATENCY_1_reg                                             0xB80E819C
#define  DVBC_REG_AAGC_LATENCY_1_inst_addr                                       "0x0042"
#define  set_DVBC_REG_AAGC_LATENCY_1_reg(data)                                   (*((volatile unsigned int*)DVBC_REG_AAGC_LATENCY_1_reg)=data)
#define  get_DVBC_REG_AAGC_LATENCY_1_reg                                         (*((volatile unsigned int*)DVBC_REG_AAGC_LATENCY_1_reg))
#define  DVBC_REG_AAGC_LATENCY_1_reg_aagc_latency_12_8_shift                     (0)
#define  DVBC_REG_AAGC_LATENCY_1_reg_aagc_latency_12_8_mask                      (0x0000001F)
#define  DVBC_REG_AAGC_LATENCY_1_reg_aagc_latency_12_8(data)                     (0x0000001F&(data))
#define  DVBC_REG_AAGC_LATENCY_1_get_reg_aagc_latency_12_8(data)                 (0x0000001F&(data))

#define  DVBC_REG_INTEGRAL_CNT_LEN                                               0x180E81A0
#define  DVBC_REG_INTEGRAL_CNT_LEN_reg_addr                                      "0xB80E81A0"
#define  DVBC_REG_INTEGRAL_CNT_LEN_reg                                           0xB80E81A0
#define  DVBC_REG_INTEGRAL_CNT_LEN_inst_addr                                     "0x0043"
#define  set_DVBC_REG_INTEGRAL_CNT_LEN_reg(data)                                 (*((volatile unsigned int*)DVBC_REG_INTEGRAL_CNT_LEN_reg)=data)
#define  get_DVBC_REG_INTEGRAL_CNT_LEN_reg                                       (*((volatile unsigned int*)DVBC_REG_INTEGRAL_CNT_LEN_reg))
#define  DVBC_REG_INTEGRAL_CNT_LEN_reg_aagc_lock_pga_hit_len_shift               (5)
#define  DVBC_REG_INTEGRAL_CNT_LEN_reg_integral_cnt_len_shift                    (0)
#define  DVBC_REG_INTEGRAL_CNT_LEN_reg_aagc_lock_pga_hit_len_mask                (0x000000E0)
#define  DVBC_REG_INTEGRAL_CNT_LEN_reg_integral_cnt_len_mask                     (0x0000001F)
#define  DVBC_REG_INTEGRAL_CNT_LEN_reg_aagc_lock_pga_hit_len(data)               (0x000000E0&((data)<<5))
#define  DVBC_REG_INTEGRAL_CNT_LEN_reg_integral_cnt_len(data)                    (0x0000001F&(data))
#define  DVBC_REG_INTEGRAL_CNT_LEN_get_reg_aagc_lock_pga_hit_len(data)           ((0x000000E0&(data))>>5)
#define  DVBC_REG_INTEGRAL_CNT_LEN_get_reg_integral_cnt_len(data)                (0x0000001F&(data))

#define  DVBC_REG_THD_LOCK_UP                                                    0x180E81A4
#define  DVBC_REG_THD_LOCK_UP_reg_addr                                           "0xB80E81A4"
#define  DVBC_REG_THD_LOCK_UP_reg                                                0xB80E81A4
#define  DVBC_REG_THD_LOCK_UP_inst_addr                                          "0x0044"
#define  set_DVBC_REG_THD_LOCK_UP_reg(data)                                      (*((volatile unsigned int*)DVBC_REG_THD_LOCK_UP_reg)=data)
#define  get_DVBC_REG_THD_LOCK_UP_reg                                            (*((volatile unsigned int*)DVBC_REG_THD_LOCK_UP_reg))
#define  DVBC_REG_THD_LOCK_UP_reg_thd_lock_up_7_0_shift                          (0)
#define  DVBC_REG_THD_LOCK_UP_reg_thd_lock_up_7_0_mask                           (0x000000FF)
#define  DVBC_REG_THD_LOCK_UP_reg_thd_lock_up_7_0(data)                          (0x000000FF&(data))
#define  DVBC_REG_THD_LOCK_UP_get_reg_thd_lock_up_7_0(data)                      (0x000000FF&(data))

#define  DVBC_REG_THD_LOCK_UP_1                                                  0x180E81A8
#define  DVBC_REG_THD_LOCK_UP_1_reg_addr                                         "0xB80E81A8"
#define  DVBC_REG_THD_LOCK_UP_1_reg                                              0xB80E81A8
#define  DVBC_REG_THD_LOCK_UP_1_inst_addr                                        "0x0045"
#define  set_DVBC_REG_THD_LOCK_UP_1_reg(data)                                    (*((volatile unsigned int*)DVBC_REG_THD_LOCK_UP_1_reg)=data)
#define  get_DVBC_REG_THD_LOCK_UP_1_reg                                          (*((volatile unsigned int*)DVBC_REG_THD_LOCK_UP_1_reg))
#define  DVBC_REG_THD_LOCK_UP_1_reg_thd_lock_dw_5_0_shift                        (2)
#define  DVBC_REG_THD_LOCK_UP_1_reg_thd_lock_up_9_8_shift                        (0)
#define  DVBC_REG_THD_LOCK_UP_1_reg_thd_lock_dw_5_0_mask                         (0x000000FC)
#define  DVBC_REG_THD_LOCK_UP_1_reg_thd_lock_up_9_8_mask                         (0x00000003)
#define  DVBC_REG_THD_LOCK_UP_1_reg_thd_lock_dw_5_0(data)                        (0x000000FC&((data)<<2))
#define  DVBC_REG_THD_LOCK_UP_1_reg_thd_lock_up_9_8(data)                        (0x00000003&(data))
#define  DVBC_REG_THD_LOCK_UP_1_get_reg_thd_lock_dw_5_0(data)                    ((0x000000FC&(data))>>2)
#define  DVBC_REG_THD_LOCK_UP_1_get_reg_thd_lock_up_9_8(data)                    (0x00000003&(data))

#define  DVBC_REG_THD_LOCK_UP_1_1                                                0x180E81AC
#define  DVBC_REG_THD_LOCK_UP_1_1_reg_addr                                       "0xB80E81AC"
#define  DVBC_REG_THD_LOCK_UP_1_1_reg                                            0xB80E81AC
#define  DVBC_REG_THD_LOCK_UP_1_1_inst_addr                                      "0x0046"
#define  set_DVBC_REG_THD_LOCK_UP_1_1_reg(data)                                  (*((volatile unsigned int*)DVBC_REG_THD_LOCK_UP_1_1_reg)=data)
#define  get_DVBC_REG_THD_LOCK_UP_1_1_reg                                        (*((volatile unsigned int*)DVBC_REG_THD_LOCK_UP_1_1_reg))
#define  DVBC_REG_THD_LOCK_UP_1_1_reg_thd_lock_dw_9_6_shift                      (0)
#define  DVBC_REG_THD_LOCK_UP_1_1_reg_thd_lock_dw_9_6_mask                       (0x0000000F)
#define  DVBC_REG_THD_LOCK_UP_1_1_reg_thd_lock_dw_9_6(data)                      (0x0000000F&(data))
#define  DVBC_REG_THD_LOCK_UP_1_1_get_reg_thd_lock_dw_9_6(data)                  (0x0000000F&(data))

#define  DVBC_REG_THD_UP1                                                        0x180E81B0
#define  DVBC_REG_THD_UP1_reg_addr                                               "0xB80E81B0"
#define  DVBC_REG_THD_UP1_reg                                                    0xB80E81B0
#define  DVBC_REG_THD_UP1_inst_addr                                              "0x0047"
#define  set_DVBC_REG_THD_UP1_reg(data)                                          (*((volatile unsigned int*)DVBC_REG_THD_UP1_reg)=data)
#define  get_DVBC_REG_THD_UP1_reg                                                (*((volatile unsigned int*)DVBC_REG_THD_UP1_reg))
#define  DVBC_REG_THD_UP1_reg_thd_up1_7_0_shift                                  (0)
#define  DVBC_REG_THD_UP1_reg_thd_up1_7_0_mask                                   (0x000000FF)
#define  DVBC_REG_THD_UP1_reg_thd_up1_7_0(data)                                  (0x000000FF&(data))
#define  DVBC_REG_THD_UP1_get_reg_thd_up1_7_0(data)                              (0x000000FF&(data))

#define  DVBC_REG_THD_UP1_1                                                      0x180E81B4
#define  DVBC_REG_THD_UP1_1_reg_addr                                             "0xB80E81B4"
#define  DVBC_REG_THD_UP1_1_reg                                                  0xB80E81B4
#define  DVBC_REG_THD_UP1_1_inst_addr                                            "0x0048"
#define  set_DVBC_REG_THD_UP1_1_reg(data)                                        (*((volatile unsigned int*)DVBC_REG_THD_UP1_1_reg)=data)
#define  get_DVBC_REG_THD_UP1_1_reg                                              (*((volatile unsigned int*)DVBC_REG_THD_UP1_1_reg))
#define  DVBC_REG_THD_UP1_1_reg_thd_dw1_5_0_shift                                (2)
#define  DVBC_REG_THD_UP1_1_reg_thd_up1_9_8_shift                                (0)
#define  DVBC_REG_THD_UP1_1_reg_thd_dw1_5_0_mask                                 (0x000000FC)
#define  DVBC_REG_THD_UP1_1_reg_thd_up1_9_8_mask                                 (0x00000003)
#define  DVBC_REG_THD_UP1_1_reg_thd_dw1_5_0(data)                                (0x000000FC&((data)<<2))
#define  DVBC_REG_THD_UP1_1_reg_thd_up1_9_8(data)                                (0x00000003&(data))
#define  DVBC_REG_THD_UP1_1_get_reg_thd_dw1_5_0(data)                            ((0x000000FC&(data))>>2)
#define  DVBC_REG_THD_UP1_1_get_reg_thd_up1_9_8(data)                            (0x00000003&(data))

#define  DVBC_REG_THD_UP1_1_1                                                    0x180E81B8
#define  DVBC_REG_THD_UP1_1_1_reg_addr                                           "0xB80E81B8"
#define  DVBC_REG_THD_UP1_1_1_reg                                                0xB80E81B8
#define  DVBC_REG_THD_UP1_1_1_inst_addr                                          "0x0049"
#define  set_DVBC_REG_THD_UP1_1_1_reg(data)                                      (*((volatile unsigned int*)DVBC_REG_THD_UP1_1_1_reg)=data)
#define  get_DVBC_REG_THD_UP1_1_1_reg                                            (*((volatile unsigned int*)DVBC_REG_THD_UP1_1_1_reg))
#define  DVBC_REG_THD_UP1_1_1_reg_thd_dw1_9_6_shift                              (0)
#define  DVBC_REG_THD_UP1_1_1_reg_thd_dw1_9_6_mask                               (0x0000000F)
#define  DVBC_REG_THD_UP1_1_1_reg_thd_dw1_9_6(data)                              (0x0000000F&(data))
#define  DVBC_REG_THD_UP1_1_1_get_reg_thd_dw1_9_6(data)                          (0x0000000F&(data))

#define  DVBC_REG_THD_UP2                                                        0x180E81BC
#define  DVBC_REG_THD_UP2_reg_addr                                               "0xB80E81BC"
#define  DVBC_REG_THD_UP2_reg                                                    0xB80E81BC
#define  DVBC_REG_THD_UP2_inst_addr                                              "0x004A"
#define  set_DVBC_REG_THD_UP2_reg(data)                                          (*((volatile unsigned int*)DVBC_REG_THD_UP2_reg)=data)
#define  get_DVBC_REG_THD_UP2_reg                                                (*((volatile unsigned int*)DVBC_REG_THD_UP2_reg))
#define  DVBC_REG_THD_UP2_reg_thd_up2_shift                                      (0)
#define  DVBC_REG_THD_UP2_reg_thd_up2_mask                                       (0x000000FF)
#define  DVBC_REG_THD_UP2_reg_thd_up2(data)                                      (0x000000FF&(data))
#define  DVBC_REG_THD_UP2_get_reg_thd_up2(data)                                  (0x000000FF&(data))

#define  DVBC_REG_THD_DW2                                                        0x180E81C0
#define  DVBC_REG_THD_DW2_reg_addr                                               "0xB80E81C0"
#define  DVBC_REG_THD_DW2_reg                                                    0xB80E81C0
#define  DVBC_REG_THD_DW2_inst_addr                                              "0x004B"
#define  set_DVBC_REG_THD_DW2_reg(data)                                          (*((volatile unsigned int*)DVBC_REG_THD_DW2_reg)=data)
#define  get_DVBC_REG_THD_DW2_reg                                                (*((volatile unsigned int*)DVBC_REG_THD_DW2_reg))
#define  DVBC_REG_THD_DW2_reg_thd_dw2_shift                                      (0)
#define  DVBC_REG_THD_DW2_reg_thd_dw2_mask                                       (0x000000FF)
#define  DVBC_REG_THD_DW2_reg_thd_dw2(data)                                      (0x000000FF&(data))
#define  DVBC_REG_THD_DW2_get_reg_thd_dw2(data)                                  (0x000000FF&(data))

#define  DVBC_REG_GAIN_STEP_SUM_UP_THD                                           0x180E81C4
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_reg_addr                                  "0xB80E81C4"
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_reg                                       0xB80E81C4
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_inst_addr                                 "0x004C"
#define  set_DVBC_REG_GAIN_STEP_SUM_UP_THD_reg(data)                             (*((volatile unsigned int*)DVBC_REG_GAIN_STEP_SUM_UP_THD_reg)=data)
#define  get_DVBC_REG_GAIN_STEP_SUM_UP_THD_reg                                   (*((volatile unsigned int*)DVBC_REG_GAIN_STEP_SUM_UP_THD_reg))
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_reg_gain_step_sum_dw_thd_shift            (4)
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_reg_gain_step_sum_up_thd_shift            (0)
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_reg_gain_step_sum_dw_thd_mask             (0x000000F0)
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_reg_gain_step_sum_up_thd_mask             (0x0000000F)
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_reg_gain_step_sum_dw_thd(data)            (0x000000F0&((data)<<4))
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_reg_gain_step_sum_up_thd(data)            (0x0000000F&(data))
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_get_reg_gain_step_sum_dw_thd(data)        ((0x000000F0&(data))>>4)
#define  DVBC_REG_GAIN_STEP_SUM_UP_THD_get_reg_gain_step_sum_up_thd(data)        (0x0000000F&(data))

#define  DVBC_REG_GAIN_PULSE_SPACE_LEN                                           0x180E81C8
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_reg_addr                                  "0xB80E81C8"
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_reg                                       0xB80E81C8
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_inst_addr                                 "0x004D"
#define  set_DVBC_REG_GAIN_PULSE_SPACE_LEN_reg(data)                             (*((volatile unsigned int*)DVBC_REG_GAIN_PULSE_SPACE_LEN_reg)=data)
#define  get_DVBC_REG_GAIN_PULSE_SPACE_LEN_reg                                   (*((volatile unsigned int*)DVBC_REG_GAIN_PULSE_SPACE_LEN_reg))
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_reg_gain_pulse_hold_len_shift             (4)
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_reg_gain_pulse_space_len_shift            (0)
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_reg_gain_pulse_hold_len_mask              (0x000000F0)
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_reg_gain_pulse_space_len_mask             (0x0000000F)
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_reg_gain_pulse_hold_len(data)             (0x000000F0&((data)<<4))
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_reg_gain_pulse_space_len(data)            (0x0000000F&(data))
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_get_reg_gain_pulse_hold_len(data)         ((0x000000F0&(data))>>4)
#define  DVBC_REG_GAIN_PULSE_SPACE_LEN_get_reg_gain_pulse_space_len(data)        (0x0000000F&(data))

#define  DVBC_QAM_IN_VERSION                                                     0x180E8404
#define  DVBC_QAM_IN_VERSION_reg_addr                                            "0xB80E8404"
#define  DVBC_QAM_IN_VERSION_reg                                                 0xB80E8404
#define  DVBC_QAM_IN_VERSION_inst_addr                                           "0x004E"
#define  set_DVBC_QAM_IN_VERSION_reg(data)                                       (*((volatile unsigned int*)DVBC_QAM_IN_VERSION_reg)=data)
#define  get_DVBC_QAM_IN_VERSION_reg                                             (*((volatile unsigned int*)DVBC_QAM_IN_VERSION_reg))
#define  DVBC_QAM_IN_VERSION_qam_in_version_shift                                (0)
#define  DVBC_QAM_IN_VERSION_qam_in_version_mask                                 (0x000000FF)
#define  DVBC_QAM_IN_VERSION_qam_in_version(data)                                (0x000000FF&(data))
#define  DVBC_QAM_IN_VERSION_get_qam_in_version(data)                            (0x000000FF&(data))

#define  DVBC_OPT_QAM_MODE                                                       0x180E8408
#define  DVBC_OPT_QAM_MODE_reg_addr                                              "0xB80E8408"
#define  DVBC_OPT_QAM_MODE_reg                                                   0xB80E8408
#define  DVBC_OPT_QAM_MODE_inst_addr                                             "0x004F"
#define  set_DVBC_OPT_QAM_MODE_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_QAM_MODE_reg)=data)
#define  get_DVBC_OPT_QAM_MODE_reg                                               (*((volatile unsigned int*)DVBC_OPT_QAM_MODE_reg))
#define  DVBC_OPT_QAM_MODE_opt_adc_samp_ph_shift                                 (3)
#define  DVBC_OPT_QAM_MODE_opt_qam_mode_shift                                    (0)
#define  DVBC_OPT_QAM_MODE_opt_adc_samp_ph_mask                                  (0x00000038)
#define  DVBC_OPT_QAM_MODE_opt_qam_mode_mask                                     (0x00000007)
#define  DVBC_OPT_QAM_MODE_opt_adc_samp_ph(data)                                 (0x00000038&((data)<<3))
#define  DVBC_OPT_QAM_MODE_opt_qam_mode(data)                                    (0x00000007&(data))
#define  DVBC_OPT_QAM_MODE_get_opt_adc_samp_ph(data)                             ((0x00000038&(data))>>3)
#define  DVBC_OPT_QAM_MODE_get_opt_qam_mode(data)                                (0x00000007&(data))

#define  DVBC_OPT_ADC_TRUNC_BITS                                                 0x180E840C
#define  DVBC_OPT_ADC_TRUNC_BITS_reg_addr                                        "0xB80E840C"
#define  DVBC_OPT_ADC_TRUNC_BITS_reg                                             0xB80E840C
#define  DVBC_OPT_ADC_TRUNC_BITS_inst_addr                                       "0x0050"
#define  set_DVBC_OPT_ADC_TRUNC_BITS_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_ADC_TRUNC_BITS_reg)=data)
#define  get_DVBC_OPT_ADC_TRUNC_BITS_reg                                         (*((volatile unsigned int*)DVBC_OPT_ADC_TRUNC_BITS_reg))
#define  DVBC_OPT_ADC_TRUNC_BITS_opt_adc_format_sel_shift                        (2)
#define  DVBC_OPT_ADC_TRUNC_BITS_opt_adc_trunc_bits_shift                        (0)
#define  DVBC_OPT_ADC_TRUNC_BITS_opt_adc_format_sel_mask                         (0x00000004)
#define  DVBC_OPT_ADC_TRUNC_BITS_opt_adc_trunc_bits_mask                         (0x00000003)
#define  DVBC_OPT_ADC_TRUNC_BITS_opt_adc_format_sel(data)                        (0x00000004&((data)<<2))
#define  DVBC_OPT_ADC_TRUNC_BITS_opt_adc_trunc_bits(data)                        (0x00000003&(data))
#define  DVBC_OPT_ADC_TRUNC_BITS_get_opt_adc_format_sel(data)                    ((0x00000004&(data))>>2)
#define  DVBC_OPT_ADC_TRUNC_BITS_get_opt_adc_trunc_bits(data)                    (0x00000003&(data))

#define  DVBC_OPT_ADC_NB_ON                                                      0x180E8410
#define  DVBC_OPT_ADC_NB_ON_reg_addr                                             "0xB80E8410"
#define  DVBC_OPT_ADC_NB_ON_reg                                                  0xB80E8410
#define  DVBC_OPT_ADC_NB_ON_inst_addr                                            "0x0051"
#define  set_DVBC_OPT_ADC_NB_ON_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_ADC_NB_ON_reg)=data)
#define  get_DVBC_OPT_ADC_NB_ON_reg                                              (*((volatile unsigned int*)DVBC_OPT_ADC_NB_ON_reg))
#define  DVBC_OPT_ADC_NB_ON_opt_aagc_s_k_rf_lsb_shift                            (6)
#define  DVBC_OPT_ADC_NB_ON_opt_aagc_fz_shift                                    (4)
#define  DVBC_OPT_ADC_NB_ON_opt_if_aagc_pol_shift                                (3)
#define  DVBC_OPT_ADC_NB_ON_opt_rf_aagc_pol_shift                                (2)
#define  DVBC_OPT_ADC_NB_ON_opt_aagc_loop_pol_shift                              (1)
#define  DVBC_OPT_ADC_NB_ON_opt_adc_nb_on_shift                                  (0)
#define  DVBC_OPT_ADC_NB_ON_opt_aagc_s_k_rf_lsb_mask                             (0x000000C0)
#define  DVBC_OPT_ADC_NB_ON_opt_aagc_fz_mask                                     (0x00000030)
#define  DVBC_OPT_ADC_NB_ON_opt_if_aagc_pol_mask                                 (0x00000008)
#define  DVBC_OPT_ADC_NB_ON_opt_rf_aagc_pol_mask                                 (0x00000004)
#define  DVBC_OPT_ADC_NB_ON_opt_aagc_loop_pol_mask                               (0x00000002)
#define  DVBC_OPT_ADC_NB_ON_opt_adc_nb_on_mask                                   (0x00000001)
#define  DVBC_OPT_ADC_NB_ON_opt_aagc_s_k_rf_lsb(data)                            (0x000000C0&((data)<<6))
#define  DVBC_OPT_ADC_NB_ON_opt_aagc_fz(data)                                    (0x00000030&((data)<<4))
#define  DVBC_OPT_ADC_NB_ON_opt_if_aagc_pol(data)                                (0x00000008&((data)<<3))
#define  DVBC_OPT_ADC_NB_ON_opt_rf_aagc_pol(data)                                (0x00000004&((data)<<2))
#define  DVBC_OPT_ADC_NB_ON_opt_aagc_loop_pol(data)                              (0x00000002&((data)<<1))
#define  DVBC_OPT_ADC_NB_ON_opt_adc_nb_on(data)                                  (0x00000001&(data))
#define  DVBC_OPT_ADC_NB_ON_get_opt_aagc_s_k_rf_lsb(data)                        ((0x000000C0&(data))>>6)
#define  DVBC_OPT_ADC_NB_ON_get_opt_aagc_fz(data)                                ((0x00000030&(data))>>4)
#define  DVBC_OPT_ADC_NB_ON_get_opt_if_aagc_pol(data)                            ((0x00000008&(data))>>3)
#define  DVBC_OPT_ADC_NB_ON_get_opt_rf_aagc_pol(data)                            ((0x00000004&(data))>>2)
#define  DVBC_OPT_ADC_NB_ON_get_opt_aagc_loop_pol(data)                          ((0x00000002&(data))>>1)
#define  DVBC_OPT_ADC_NB_ON_get_opt_adc_nb_on(data)                              (0x00000001&(data))

#define  DVBC_OPT_AAGC_TARGET_AMP                                                0x180E8414
#define  DVBC_OPT_AAGC_TARGET_AMP_reg_addr                                       "0xB80E8414"
#define  DVBC_OPT_AAGC_TARGET_AMP_reg                                            0xB80E8414
#define  DVBC_OPT_AAGC_TARGET_AMP_inst_addr                                      "0x0052"
#define  set_DVBC_OPT_AAGC_TARGET_AMP_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_AAGC_TARGET_AMP_reg)=data)
#define  get_DVBC_OPT_AAGC_TARGET_AMP_reg                                        (*((volatile unsigned int*)DVBC_OPT_AAGC_TARGET_AMP_reg))
#define  DVBC_OPT_AAGC_TARGET_AMP_opt_aagc_target_amp_shift                      (0)
#define  DVBC_OPT_AAGC_TARGET_AMP_opt_aagc_target_amp_mask                       (0x000000FF)
#define  DVBC_OPT_AAGC_TARGET_AMP_opt_aagc_target_amp(data)                      (0x000000FF&(data))
#define  DVBC_OPT_AAGC_TARGET_AMP_get_opt_aagc_target_amp(data)                  (0x000000FF&(data))

#define  DVBC_OPT_RF_AAGC_MAX                                                    0x180E8418
#define  DVBC_OPT_RF_AAGC_MAX_reg_addr                                           "0xB80E8418"
#define  DVBC_OPT_RF_AAGC_MAX_reg                                                0xB80E8418
#define  DVBC_OPT_RF_AAGC_MAX_inst_addr                                          "0x0053"
#define  set_DVBC_OPT_RF_AAGC_MAX_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_RF_AAGC_MAX_reg)=data)
#define  get_DVBC_OPT_RF_AAGC_MAX_reg                                            (*((volatile unsigned int*)DVBC_OPT_RF_AAGC_MAX_reg))
#define  DVBC_OPT_RF_AAGC_MAX_opt_rf_aagc_max_shift                              (0)
#define  DVBC_OPT_RF_AAGC_MAX_opt_rf_aagc_max_mask                               (0x000000FF)
#define  DVBC_OPT_RF_AAGC_MAX_opt_rf_aagc_max(data)                              (0x000000FF&(data))
#define  DVBC_OPT_RF_AAGC_MAX_get_opt_rf_aagc_max(data)                          (0x000000FF&(data))

#define  DVBC_OPT_RF_AAGC_MIN                                                    0x180E841C
#define  DVBC_OPT_RF_AAGC_MIN_reg_addr                                           "0xB80E841C"
#define  DVBC_OPT_RF_AAGC_MIN_reg                                                0xB80E841C
#define  DVBC_OPT_RF_AAGC_MIN_inst_addr                                          "0x0054"
#define  set_DVBC_OPT_RF_AAGC_MIN_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_RF_AAGC_MIN_reg)=data)
#define  get_DVBC_OPT_RF_AAGC_MIN_reg                                            (*((volatile unsigned int*)DVBC_OPT_RF_AAGC_MIN_reg))
#define  DVBC_OPT_RF_AAGC_MIN_opt_rf_aagc_min_shift                              (0)
#define  DVBC_OPT_RF_AAGC_MIN_opt_rf_aagc_min_mask                               (0x000000FF)
#define  DVBC_OPT_RF_AAGC_MIN_opt_rf_aagc_min(data)                              (0x000000FF&(data))
#define  DVBC_OPT_RF_AAGC_MIN_get_opt_rf_aagc_min(data)                          (0x000000FF&(data))

#define  DVBC_OPT_IF_AAGC_MAX                                                    0x180E8420
#define  DVBC_OPT_IF_AAGC_MAX_reg_addr                                           "0xB80E8420"
#define  DVBC_OPT_IF_AAGC_MAX_reg                                                0xB80E8420
#define  DVBC_OPT_IF_AAGC_MAX_inst_addr                                          "0x0055"
#define  set_DVBC_OPT_IF_AAGC_MAX_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_IF_AAGC_MAX_reg)=data)
#define  get_DVBC_OPT_IF_AAGC_MAX_reg                                            (*((volatile unsigned int*)DVBC_OPT_IF_AAGC_MAX_reg))
#define  DVBC_OPT_IF_AAGC_MAX_opt_if_aagc_max_shift                              (0)
#define  DVBC_OPT_IF_AAGC_MAX_opt_if_aagc_max_mask                               (0x000000FF)
#define  DVBC_OPT_IF_AAGC_MAX_opt_if_aagc_max(data)                              (0x000000FF&(data))
#define  DVBC_OPT_IF_AAGC_MAX_get_opt_if_aagc_max(data)                          (0x000000FF&(data))

#define  DVBC_OPT_IF_AAGC_MIN                                                    0x180E8424
#define  DVBC_OPT_IF_AAGC_MIN_reg_addr                                           "0xB80E8424"
#define  DVBC_OPT_IF_AAGC_MIN_reg                                                0xB80E8424
#define  DVBC_OPT_IF_AAGC_MIN_inst_addr                                          "0x0056"
#define  set_DVBC_OPT_IF_AAGC_MIN_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_IF_AAGC_MIN_reg)=data)
#define  get_DVBC_OPT_IF_AAGC_MIN_reg                                            (*((volatile unsigned int*)DVBC_OPT_IF_AAGC_MIN_reg))
#define  DVBC_OPT_IF_AAGC_MIN_opt_if_aagc_min_shift                              (0)
#define  DVBC_OPT_IF_AAGC_MIN_opt_if_aagc_min_mask                               (0x000000FF)
#define  DVBC_OPT_IF_AAGC_MIN_opt_if_aagc_min(data)                              (0x000000FF&(data))
#define  DVBC_OPT_IF_AAGC_MIN_get_opt_if_aagc_min(data)                          (0x000000FF&(data))

#define  DVBC_OPT_AAGC_INIT_LEVEL                                                0x180E8428
#define  DVBC_OPT_AAGC_INIT_LEVEL_reg_addr                                       "0xB80E8428"
#define  DVBC_OPT_AAGC_INIT_LEVEL_reg                                            0xB80E8428
#define  DVBC_OPT_AAGC_INIT_LEVEL_inst_addr                                      "0x0057"
#define  set_DVBC_OPT_AAGC_INIT_LEVEL_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_AAGC_INIT_LEVEL_reg)=data)
#define  get_DVBC_OPT_AAGC_INIT_LEVEL_reg                                        (*((volatile unsigned int*)DVBC_OPT_AAGC_INIT_LEVEL_reg))
#define  DVBC_OPT_AAGC_INIT_LEVEL_opt_aagc_init_level_shift                      (0)
#define  DVBC_OPT_AAGC_INIT_LEVEL_opt_aagc_init_level_mask                       (0x000000FF)
#define  DVBC_OPT_AAGC_INIT_LEVEL_opt_aagc_init_level(data)                      (0x000000FF&(data))
#define  DVBC_OPT_AAGC_INIT_LEVEL_get_opt_aagc_init_level(data)                  (0x000000FF&(data))

#define  DVBC_OPT_AAGC_S_IF_TH                                                   0x180E842C
#define  DVBC_OPT_AAGC_S_IF_TH_reg_addr                                          "0xB80E842C"
#define  DVBC_OPT_AAGC_S_IF_TH_reg                                               0xB80E842C
#define  DVBC_OPT_AAGC_S_IF_TH_inst_addr                                         "0x0058"
#define  set_DVBC_OPT_AAGC_S_IF_TH_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_AAGC_S_IF_TH_reg)=data)
#define  get_DVBC_OPT_AAGC_S_IF_TH_reg                                           (*((volatile unsigned int*)DVBC_OPT_AAGC_S_IF_TH_reg))
#define  DVBC_OPT_AAGC_S_IF_TH_opt_aagc_s_if_th_shift                            (0)
#define  DVBC_OPT_AAGC_S_IF_TH_opt_aagc_s_if_th_mask                             (0x000000FF)
#define  DVBC_OPT_AAGC_S_IF_TH_opt_aagc_s_if_th(data)                            (0x000000FF&(data))
#define  DVBC_OPT_AAGC_S_IF_TH_get_opt_aagc_s_if_th(data)                        (0x000000FF&(data))

#define  DVBC_OPT_AAGC_LOCK_TH                                                   0x180E8430
#define  DVBC_OPT_AAGC_LOCK_TH_reg_addr                                          "0xB80E8430"
#define  DVBC_OPT_AAGC_LOCK_TH_reg                                               0xB80E8430
#define  DVBC_OPT_AAGC_LOCK_TH_inst_addr                                         "0x0059"
#define  set_DVBC_OPT_AAGC_LOCK_TH_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_AAGC_LOCK_TH_reg)=data)
#define  get_DVBC_OPT_AAGC_LOCK_TH_reg                                           (*((volatile unsigned int*)DVBC_OPT_AAGC_LOCK_TH_reg))
#define  DVBC_OPT_AAGC_LOCK_TH_opt_aagc_p_s_sel_shift                            (7)
#define  DVBC_OPT_AAGC_LOCK_TH_opt_aagc_s_k_rf_msb_shift                         (3)
#define  DVBC_OPT_AAGC_LOCK_TH_opt_aagc_lock_th_shift                            (0)
#define  DVBC_OPT_AAGC_LOCK_TH_opt_aagc_p_s_sel_mask                             (0x00000080)
#define  DVBC_OPT_AAGC_LOCK_TH_opt_aagc_s_k_rf_msb_mask                          (0x00000078)
#define  DVBC_OPT_AAGC_LOCK_TH_opt_aagc_lock_th_mask                             (0x00000007)
#define  DVBC_OPT_AAGC_LOCK_TH_opt_aagc_p_s_sel(data)                            (0x00000080&((data)<<7))
#define  DVBC_OPT_AAGC_LOCK_TH_opt_aagc_s_k_rf_msb(data)                         (0x00000078&((data)<<3))
#define  DVBC_OPT_AAGC_LOCK_TH_opt_aagc_lock_th(data)                            (0x00000007&(data))
#define  DVBC_OPT_AAGC_LOCK_TH_get_opt_aagc_p_s_sel(data)                        ((0x00000080&(data))>>7)
#define  DVBC_OPT_AAGC_LOCK_TH_get_opt_aagc_s_k_rf_msb(data)                     ((0x00000078&(data))>>3)
#define  DVBC_OPT_AAGC_LOCK_TH_get_opt_aagc_lock_th(data)                        (0x00000007&(data))

#define  DVBC_OPT_DDC_FREQ                                                       0x180E8434
#define  DVBC_OPT_DDC_FREQ_reg_addr                                              "0xB80E8434"
#define  DVBC_OPT_DDC_FREQ_reg                                                   0xB80E8434
#define  DVBC_OPT_DDC_FREQ_inst_addr                                             "0x005A"
#define  set_DVBC_OPT_DDC_FREQ_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_DDC_FREQ_reg)=data)
#define  get_DVBC_OPT_DDC_FREQ_reg                                               (*((volatile unsigned int*)DVBC_OPT_DDC_FREQ_reg))
#define  DVBC_OPT_DDC_FREQ_opt_ddc_freq_7_0_shift                                (0)
#define  DVBC_OPT_DDC_FREQ_opt_ddc_freq_7_0_mask                                 (0x000000FF)
#define  DVBC_OPT_DDC_FREQ_opt_ddc_freq_7_0(data)                                (0x000000FF&(data))
#define  DVBC_OPT_DDC_FREQ_get_opt_ddc_freq_7_0(data)                            (0x000000FF&(data))

#define  DVBC_OPT_DDC_FREQ_1                                                     0x180E8438
#define  DVBC_OPT_DDC_FREQ_1_reg_addr                                            "0xB80E8438"
#define  DVBC_OPT_DDC_FREQ_1_reg                                                 0xB80E8438
#define  DVBC_OPT_DDC_FREQ_1_inst_addr                                           "0x005B"
#define  set_DVBC_OPT_DDC_FREQ_1_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_DDC_FREQ_1_reg)=data)
#define  get_DVBC_OPT_DDC_FREQ_1_reg                                             (*((volatile unsigned int*)DVBC_OPT_DDC_FREQ_1_reg))
#define  DVBC_OPT_DDC_FREQ_1_opt_spec_inv_shift                                  (7)
#define  DVBC_OPT_DDC_FREQ_1_opt_ddc_freq_14_8_shift                             (0)
#define  DVBC_OPT_DDC_FREQ_1_opt_spec_inv_mask                                   (0x00000080)
#define  DVBC_OPT_DDC_FREQ_1_opt_ddc_freq_14_8_mask                              (0x0000007F)
#define  DVBC_OPT_DDC_FREQ_1_opt_spec_inv(data)                                  (0x00000080&((data)<<7))
#define  DVBC_OPT_DDC_FREQ_1_opt_ddc_freq_14_8(data)                             (0x0000007F&(data))
#define  DVBC_OPT_DDC_FREQ_1_get_opt_spec_inv(data)                              ((0x00000080&(data))>>7)
#define  DVBC_OPT_DDC_FREQ_1_get_opt_ddc_freq_14_8(data)                         (0x0000007F&(data))

#define  DVBC_OPT_DDC_LPF_SCALING                                                0x180E843C
#define  DVBC_OPT_DDC_LPF_SCALING_reg_addr                                       "0xB80E843C"
#define  DVBC_OPT_DDC_LPF_SCALING_reg                                            0xB80E843C
#define  DVBC_OPT_DDC_LPF_SCALING_inst_addr                                      "0x005C"
#define  set_DVBC_OPT_DDC_LPF_SCALING_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_DDC_LPF_SCALING_reg)=data)
#define  get_DVBC_OPT_DDC_LPF_SCALING_reg                                        (*((volatile unsigned int*)DVBC_OPT_DDC_LPF_SCALING_reg))
#define  DVBC_OPT_DDC_LPF_SCALING_specmode_shift                                 (5)
#define  DVBC_OPT_DDC_LPF_SCALING_opt_auto_spec_shift                            (4)
#define  DVBC_OPT_DDC_LPF_SCALING_opt_set_spec_shift                             (3)
#define  DVBC_OPT_DDC_LPF_SCALING_opt_ddc_lpf_scaling_shift                      (0)
#define  DVBC_OPT_DDC_LPF_SCALING_specmode_mask                                  (0x00000020)
#define  DVBC_OPT_DDC_LPF_SCALING_opt_auto_spec_mask                             (0x00000010)
#define  DVBC_OPT_DDC_LPF_SCALING_opt_set_spec_mask                              (0x00000008)
#define  DVBC_OPT_DDC_LPF_SCALING_opt_ddc_lpf_scaling_mask                       (0x00000007)
#define  DVBC_OPT_DDC_LPF_SCALING_specmode(data)                                 (0x00000020&((data)<<5))
#define  DVBC_OPT_DDC_LPF_SCALING_opt_auto_spec(data)                            (0x00000010&((data)<<4))
#define  DVBC_OPT_DDC_LPF_SCALING_opt_set_spec(data)                             (0x00000008&((data)<<3))
#define  DVBC_OPT_DDC_LPF_SCALING_opt_ddc_lpf_scaling(data)                      (0x00000007&(data))
#define  DVBC_OPT_DDC_LPF_SCALING_get_specmode(data)                             ((0x00000020&(data))>>5)
#define  DVBC_OPT_DDC_LPF_SCALING_get_opt_auto_spec(data)                        ((0x00000010&(data))>>4)
#define  DVBC_OPT_DDC_LPF_SCALING_get_opt_set_spec(data)                         ((0x00000008&(data))>>3)
#define  DVBC_OPT_DDC_LPF_SCALING_get_opt_ddc_lpf_scaling(data)                  (0x00000007&(data))

#define  DVBC_OPT_NOTCH1_ON                                                      0x180E8440
#define  DVBC_OPT_NOTCH1_ON_reg_addr                                             "0xB80E8440"
#define  DVBC_OPT_NOTCH1_ON_reg                                                  0xB80E8440
#define  DVBC_OPT_NOTCH1_ON_inst_addr                                            "0x005D"
#define  set_DVBC_OPT_NOTCH1_ON_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_NOTCH1_ON_reg)=data)
#define  get_DVBC_OPT_NOTCH1_ON_reg                                              (*((volatile unsigned int*)DVBC_OPT_NOTCH1_ON_reg))
#define  DVBC_OPT_NOTCH1_ON_notch_sel_shift                                      (4)
#define  DVBC_OPT_NOTCH1_ON_notch_wr_stb_shift                                   (3)
#define  DVBC_OPT_NOTCH1_ON_opt_notch3_on_shift                                  (2)
#define  DVBC_OPT_NOTCH1_ON_opt_notch2_on_shift                                  (1)
#define  DVBC_OPT_NOTCH1_ON_opt_notch1_on_shift                                  (0)
#define  DVBC_OPT_NOTCH1_ON_notch_sel_mask                                       (0x000000F0)
#define  DVBC_OPT_NOTCH1_ON_notch_wr_stb_mask                                    (0x00000008)
#define  DVBC_OPT_NOTCH1_ON_opt_notch3_on_mask                                   (0x00000004)
#define  DVBC_OPT_NOTCH1_ON_opt_notch2_on_mask                                   (0x00000002)
#define  DVBC_OPT_NOTCH1_ON_opt_notch1_on_mask                                   (0x00000001)
#define  DVBC_OPT_NOTCH1_ON_notch_sel(data)                                      (0x000000F0&((data)<<4))
#define  DVBC_OPT_NOTCH1_ON_notch_wr_stb(data)                                   (0x00000008&((data)<<3))
#define  DVBC_OPT_NOTCH1_ON_opt_notch3_on(data)                                  (0x00000004&((data)<<2))
#define  DVBC_OPT_NOTCH1_ON_opt_notch2_on(data)                                  (0x00000002&((data)<<1))
#define  DVBC_OPT_NOTCH1_ON_opt_notch1_on(data)                                  (0x00000001&(data))
#define  DVBC_OPT_NOTCH1_ON_get_notch_sel(data)                                  ((0x000000F0&(data))>>4)
#define  DVBC_OPT_NOTCH1_ON_get_notch_wr_stb(data)                               ((0x00000008&(data))>>3)
#define  DVBC_OPT_NOTCH1_ON_get_opt_notch3_on(data)                              ((0x00000004&(data))>>2)
#define  DVBC_OPT_NOTCH1_ON_get_opt_notch2_on(data)                              ((0x00000002&(data))>>1)
#define  DVBC_OPT_NOTCH1_ON_get_opt_notch1_on(data)                              (0x00000001&(data))

#define  DVBC_NOTCH_COEFF                                                        0x180E8444
#define  DVBC_NOTCH_COEFF_reg_addr                                               "0xB80E8444"
#define  DVBC_NOTCH_COEFF_reg                                                    0xB80E8444
#define  DVBC_NOTCH_COEFF_inst_addr                                              "0x005E"
#define  set_DVBC_NOTCH_COEFF_reg(data)                                          (*((volatile unsigned int*)DVBC_NOTCH_COEFF_reg)=data)
#define  get_DVBC_NOTCH_COEFF_reg                                                (*((volatile unsigned int*)DVBC_NOTCH_COEFF_reg))
#define  DVBC_NOTCH_COEFF_notch_coeff_7_0_shift                                  (0)
#define  DVBC_NOTCH_COEFF_notch_coeff_7_0_mask                                   (0x000000FF)
#define  DVBC_NOTCH_COEFF_notch_coeff_7_0(data)                                  (0x000000FF&(data))
#define  DVBC_NOTCH_COEFF_get_notch_coeff_7_0(data)                              (0x000000FF&(data))

#define  DVBC_NOTCH_COEFF_1                                                      0x180E8448
#define  DVBC_NOTCH_COEFF_1_reg_addr                                             "0xB80E8448"
#define  DVBC_NOTCH_COEFF_1_reg                                                  0xB80E8448
#define  DVBC_NOTCH_COEFF_1_inst_addr                                            "0x005F"
#define  set_DVBC_NOTCH_COEFF_1_reg(data)                                        (*((volatile unsigned int*)DVBC_NOTCH_COEFF_1_reg)=data)
#define  get_DVBC_NOTCH_COEFF_1_reg                                              (*((volatile unsigned int*)DVBC_NOTCH_COEFF_1_reg))
#define  DVBC_NOTCH_COEFF_1_notch_coeff_r_shift                                  (8)
#define  DVBC_NOTCH_COEFF_1_notch_coeff_10_8_shift                               (0)
#define  DVBC_NOTCH_COEFF_1_notch_coeff_r_mask                                   (0x0007FF00)
#define  DVBC_NOTCH_COEFF_1_notch_coeff_10_8_mask                                (0x00000007)
#define  DVBC_NOTCH_COEFF_1_notch_coeff_r(data)                                  (0x0007FF00&((data)<<8))
#define  DVBC_NOTCH_COEFF_1_notch_coeff_10_8(data)                               (0x00000007&(data))
#define  DVBC_NOTCH_COEFF_1_get_notch_coeff_r(data)                              ((0x0007FF00&(data))>>8)
#define  DVBC_NOTCH_COEFF_1_get_notch_coeff_10_8(data)                           (0x00000007&(data))

#define  DVBC_OPT_DAGC_MAX                                                       0x180E844C
#define  DVBC_OPT_DAGC_MAX_reg_addr                                              "0xB80E844C"
#define  DVBC_OPT_DAGC_MAX_reg                                                   0xB80E844C
#define  DVBC_OPT_DAGC_MAX_inst_addr                                             "0x0060"
#define  set_DVBC_OPT_DAGC_MAX_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_DAGC_MAX_reg)=data)
#define  get_DVBC_OPT_DAGC_MAX_reg                                               (*((volatile unsigned int*)DVBC_OPT_DAGC_MAX_reg))
#define  DVBC_OPT_DAGC_MAX_opt_dagc_min_shift                                    (4)
#define  DVBC_OPT_DAGC_MAX_opt_dagc_max_shift                                    (0)
#define  DVBC_OPT_DAGC_MAX_opt_dagc_min_mask                                     (0x000000F0)
#define  DVBC_OPT_DAGC_MAX_opt_dagc_max_mask                                     (0x0000000F)
#define  DVBC_OPT_DAGC_MAX_opt_dagc_min(data)                                    (0x000000F0&((data)<<4))
#define  DVBC_OPT_DAGC_MAX_opt_dagc_max(data)                                    (0x0000000F&(data))
#define  DVBC_OPT_DAGC_MAX_get_opt_dagc_min(data)                                ((0x000000F0&(data))>>4)
#define  DVBC_OPT_DAGC_MAX_get_opt_dagc_max(data)                                (0x0000000F&(data))

#define  DVBC_OPT_INITIAL_CR_FREQ                                                0x180E8454
#define  DVBC_OPT_INITIAL_CR_FREQ_reg_addr                                       "0xB80E8454"
#define  DVBC_OPT_INITIAL_CR_FREQ_reg                                            0xB80E8454
#define  DVBC_OPT_INITIAL_CR_FREQ_inst_addr                                      "0x0061"
#define  set_DVBC_OPT_INITIAL_CR_FREQ_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_INITIAL_CR_FREQ_reg)=data)
#define  get_DVBC_OPT_INITIAL_CR_FREQ_reg                                        (*((volatile unsigned int*)DVBC_OPT_INITIAL_CR_FREQ_reg))
#define  DVBC_OPT_INITIAL_CR_FREQ_opt_initial_cr_freq_7_0_shift                  (0)
#define  DVBC_OPT_INITIAL_CR_FREQ_opt_initial_cr_freq_7_0_mask                   (0x000000FF)
#define  DVBC_OPT_INITIAL_CR_FREQ_opt_initial_cr_freq_7_0(data)                  (0x000000FF&(data))
#define  DVBC_OPT_INITIAL_CR_FREQ_get_opt_initial_cr_freq_7_0(data)              (0x000000FF&(data))

#define  DVBC_OPT_INITIAL_CR_FREQ_1                                              0x180E8458
#define  DVBC_OPT_INITIAL_CR_FREQ_1_reg_addr                                     "0xB80E8458"
#define  DVBC_OPT_INITIAL_CR_FREQ_1_reg                                          0xB80E8458
#define  DVBC_OPT_INITIAL_CR_FREQ_1_inst_addr                                    "0x0062"
#define  set_DVBC_OPT_INITIAL_CR_FREQ_1_reg(data)                                (*((volatile unsigned int*)DVBC_OPT_INITIAL_CR_FREQ_1_reg)=data)
#define  get_DVBC_OPT_INITIAL_CR_FREQ_1_reg                                      (*((volatile unsigned int*)DVBC_OPT_INITIAL_CR_FREQ_1_reg))
#define  DVBC_OPT_INITIAL_CR_FREQ_1_opt_initial_cr_freq_12_8_shift               (0)
#define  DVBC_OPT_INITIAL_CR_FREQ_1_opt_initial_cr_freq_12_8_mask                (0x0000001F)
#define  DVBC_OPT_INITIAL_CR_FREQ_1_opt_initial_cr_freq_12_8(data)               (0x0000001F&(data))
#define  DVBC_OPT_INITIAL_CR_FREQ_1_get_opt_initial_cr_freq_12_8(data)           (0x0000001F&(data))

#define  DVBC_OPT_KI_CR_OUT_MAX                                                  0x180E845C
#define  DVBC_OPT_KI_CR_OUT_MAX_reg_addr                                         "0xB80E845C"
#define  DVBC_OPT_KI_CR_OUT_MAX_reg                                              0xB80E845C
#define  DVBC_OPT_KI_CR_OUT_MAX_inst_addr                                        "0x0063"
#define  set_DVBC_OPT_KI_CR_OUT_MAX_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_KI_CR_OUT_MAX_reg)=data)
#define  get_DVBC_OPT_KI_CR_OUT_MAX_reg                                          (*((volatile unsigned int*)DVBC_OPT_KI_CR_OUT_MAX_reg))
#define  DVBC_OPT_KI_CR_OUT_MAX_opt_ki_cr_out_max_shift                          (0)
#define  DVBC_OPT_KI_CR_OUT_MAX_opt_ki_cr_out_max_mask                           (0x000000FF)
#define  DVBC_OPT_KI_CR_OUT_MAX_opt_ki_cr_out_max(data)                          (0x000000FF&(data))
#define  DVBC_OPT_KI_CR_OUT_MAX_get_opt_ki_cr_out_max(data)                      (0x000000FF&(data))

#define  DVBC_OPT_CR_ACQ_PWR_TH                                                  0x180E8460
#define  DVBC_OPT_CR_ACQ_PWR_TH_reg_addr                                         "0xB80E8460"
#define  DVBC_OPT_CR_ACQ_PWR_TH_reg                                              0xB80E8460
#define  DVBC_OPT_CR_ACQ_PWR_TH_inst_addr                                        "0x0064"
#define  set_DVBC_OPT_CR_ACQ_PWR_TH_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_CR_ACQ_PWR_TH_reg)=data)
#define  get_DVBC_OPT_CR_ACQ_PWR_TH_reg                                          (*((volatile unsigned int*)DVBC_OPT_CR_ACQ_PWR_TH_reg))
#define  DVBC_OPT_CR_ACQ_PWR_TH_opt_cr_acq_pwr_th_shift                          (0)
#define  DVBC_OPT_CR_ACQ_PWR_TH_opt_cr_acq_pwr_th_mask                           (0x000000FF)
#define  DVBC_OPT_CR_ACQ_PWR_TH_opt_cr_acq_pwr_th(data)                          (0x000000FF&(data))
#define  DVBC_OPT_CR_ACQ_PWR_TH_get_opt_cr_acq_pwr_th(data)                      (0x000000FF&(data))

#define  DVBC_OPT_CR_METRIC_DD_MAX                                               0x180E8464
#define  DVBC_OPT_CR_METRIC_DD_MAX_reg_addr                                      "0xB80E8464"
#define  DVBC_OPT_CR_METRIC_DD_MAX_reg                                           0xB80E8464
#define  DVBC_OPT_CR_METRIC_DD_MAX_inst_addr                                     "0x0065"
#define  set_DVBC_OPT_CR_METRIC_DD_MAX_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_CR_METRIC_DD_MAX_reg)=data)
#define  get_DVBC_OPT_CR_METRIC_DD_MAX_reg                                       (*((volatile unsigned int*)DVBC_OPT_CR_METRIC_DD_MAX_reg))
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_bn_cr_bw_half_en_shift                    (7)
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_bn_cr_blank_en_shift                      (6)
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_cr_metric_dd_sat_ctrl_shift               (5)
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_cr_metric_dd_max_shift                    (0)
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_bn_cr_bw_half_en_mask                     (0x00000080)
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_bn_cr_blank_en_mask                       (0x00000040)
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_cr_metric_dd_sat_ctrl_mask                (0x00000020)
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_cr_metric_dd_max_mask                     (0x0000001F)
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_bn_cr_bw_half_en(data)                    (0x00000080&((data)<<7))
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_bn_cr_blank_en(data)                      (0x00000040&((data)<<6))
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_cr_metric_dd_sat_ctrl(data)               (0x00000020&((data)<<5))
#define  DVBC_OPT_CR_METRIC_DD_MAX_opt_cr_metric_dd_max(data)                    (0x0000001F&(data))
#define  DVBC_OPT_CR_METRIC_DD_MAX_get_opt_bn_cr_bw_half_en(data)                ((0x00000080&(data))>>7)
#define  DVBC_OPT_CR_METRIC_DD_MAX_get_opt_bn_cr_blank_en(data)                  ((0x00000040&(data))>>6)
#define  DVBC_OPT_CR_METRIC_DD_MAX_get_opt_cr_metric_dd_sat_ctrl(data)           ((0x00000020&(data))>>5)
#define  DVBC_OPT_CR_METRIC_DD_MAX_get_opt_cr_metric_dd_max(data)                (0x0000001F&(data))

#define  DVBC_OPT_BN_EQ_STOP_EN                                                  0x180E8468
#define  DVBC_OPT_BN_EQ_STOP_EN_reg_addr                                         "0xB80E8468"
#define  DVBC_OPT_BN_EQ_STOP_EN_reg                                              0xB80E8468
#define  DVBC_OPT_BN_EQ_STOP_EN_inst_addr                                        "0x0066"
#define  set_DVBC_OPT_BN_EQ_STOP_EN_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_BN_EQ_STOP_EN_reg)=data)
#define  get_DVBC_OPT_BN_EQ_STOP_EN_reg                                          (*((volatile unsigned int*)DVBC_OPT_BN_EQ_STOP_EN_reg))
#define  DVBC_OPT_BN_EQ_STOP_EN_opt_bn_cond_and_or_shift                         (7)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond5_en_shift                                (6)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond4_en_shift                                (5)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond3_en_shift                                (4)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond2_en_shift                                (3)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond1_en_shift                                (2)
#define  DVBC_OPT_BN_EQ_STOP_EN_opt_bn_cr_blank_c2_shift                         (1)
#define  DVBC_OPT_BN_EQ_STOP_EN_opt_bn_eq_stop_en_shift                          (0)
#define  DVBC_OPT_BN_EQ_STOP_EN_opt_bn_cond_and_or_mask                          (0x00000080)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond5_en_mask                                 (0x00000040)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond4_en_mask                                 (0x00000020)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond3_en_mask                                 (0x00000010)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond2_en_mask                                 (0x00000008)
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond1_en_mask                                 (0x00000004)
#define  DVBC_OPT_BN_EQ_STOP_EN_opt_bn_cr_blank_c2_mask                          (0x00000002)
#define  DVBC_OPT_BN_EQ_STOP_EN_opt_bn_eq_stop_en_mask                           (0x00000001)
#define  DVBC_OPT_BN_EQ_STOP_EN_opt_bn_cond_and_or(data)                         (0x00000080&((data)<<7))
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond5_en(data)                                (0x00000040&((data)<<6))
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond4_en(data)                                (0x00000020&((data)<<5))
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond3_en(data)                                (0x00000010&((data)<<4))
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond2_en(data)                                (0x00000008&((data)<<3))
#define  DVBC_OPT_BN_EQ_STOP_EN_bn_cond1_en(data)                                (0x00000004&((data)<<2))
#define  DVBC_OPT_BN_EQ_STOP_EN_opt_bn_cr_blank_c2(data)                         (0x00000002&((data)<<1))
#define  DVBC_OPT_BN_EQ_STOP_EN_opt_bn_eq_stop_en(data)                          (0x00000001&(data))
#define  DVBC_OPT_BN_EQ_STOP_EN_get_opt_bn_cond_and_or(data)                     ((0x00000080&(data))>>7)
#define  DVBC_OPT_BN_EQ_STOP_EN_get_bn_cond5_en(data)                            ((0x00000040&(data))>>6)
#define  DVBC_OPT_BN_EQ_STOP_EN_get_bn_cond4_en(data)                            ((0x00000020&(data))>>5)
#define  DVBC_OPT_BN_EQ_STOP_EN_get_bn_cond3_en(data)                            ((0x00000010&(data))>>4)
#define  DVBC_OPT_BN_EQ_STOP_EN_get_bn_cond2_en(data)                            ((0x00000008&(data))>>3)
#define  DVBC_OPT_BN_EQ_STOP_EN_get_bn_cond1_en(data)                            ((0x00000004&(data))>>2)
#define  DVBC_OPT_BN_EQ_STOP_EN_get_opt_bn_cr_blank_c2(data)                     ((0x00000002&(data))>>1)
#define  DVBC_OPT_BN_EQ_STOP_EN_get_opt_bn_eq_stop_en(data)                      (0x00000001&(data))

#define  DVBC_OPT_BN_MSE_TH                                                      0x180E846C
#define  DVBC_OPT_BN_MSE_TH_reg_addr                                             "0xB80E846C"
#define  DVBC_OPT_BN_MSE_TH_reg                                                  0xB80E846C
#define  DVBC_OPT_BN_MSE_TH_inst_addr                                            "0x0067"
#define  set_DVBC_OPT_BN_MSE_TH_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_BN_MSE_TH_reg)=data)
#define  get_DVBC_OPT_BN_MSE_TH_reg                                              (*((volatile unsigned int*)DVBC_OPT_BN_MSE_TH_reg))
#define  DVBC_OPT_BN_MSE_TH_opt_bn_ek_amp_th_shift                               (4)
#define  DVBC_OPT_BN_MSE_TH_opt_bn_mse_th_shift                                  (0)
#define  DVBC_OPT_BN_MSE_TH_opt_bn_ek_amp_th_mask                                (0x000000F0)
#define  DVBC_OPT_BN_MSE_TH_opt_bn_mse_th_mask                                   (0x0000000F)
#define  DVBC_OPT_BN_MSE_TH_opt_bn_ek_amp_th(data)                               (0x000000F0&((data)<<4))
#define  DVBC_OPT_BN_MSE_TH_opt_bn_mse_th(data)                                  (0x0000000F&(data))
#define  DVBC_OPT_BN_MSE_TH_get_opt_bn_ek_amp_th(data)                           ((0x000000F0&(data))>>4)
#define  DVBC_OPT_BN_MSE_TH_get_opt_bn_mse_th(data)                              (0x0000000F&(data))

#define  DVBC_OPT_BN_COND1_CNT_TH                                                0x180E8470
#define  DVBC_OPT_BN_COND1_CNT_TH_reg_addr                                       "0xB80E8470"
#define  DVBC_OPT_BN_COND1_CNT_TH_reg                                            0xB80E8470
#define  DVBC_OPT_BN_COND1_CNT_TH_inst_addr                                      "0x0068"
#define  set_DVBC_OPT_BN_COND1_CNT_TH_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_BN_COND1_CNT_TH_reg)=data)
#define  get_DVBC_OPT_BN_COND1_CNT_TH_reg                                        (*((volatile unsigned int*)DVBC_OPT_BN_COND1_CNT_TH_reg))
#define  DVBC_OPT_BN_COND1_CNT_TH_opt_bn_cond2_cnt_th_shift                      (3)
#define  DVBC_OPT_BN_COND1_CNT_TH_opt_bn_cond1_cnt_th_shift                      (0)
#define  DVBC_OPT_BN_COND1_CNT_TH_opt_bn_cond2_cnt_th_mask                       (0x00000038)
#define  DVBC_OPT_BN_COND1_CNT_TH_opt_bn_cond1_cnt_th_mask                       (0x00000007)
#define  DVBC_OPT_BN_COND1_CNT_TH_opt_bn_cond2_cnt_th(data)                      (0x00000038&((data)<<3))
#define  DVBC_OPT_BN_COND1_CNT_TH_opt_bn_cond1_cnt_th(data)                      (0x00000007&(data))
#define  DVBC_OPT_BN_COND1_CNT_TH_get_opt_bn_cond2_cnt_th(data)                  ((0x00000038&(data))>>3)
#define  DVBC_OPT_BN_COND1_CNT_TH_get_opt_bn_cond1_cnt_th(data)                  (0x00000007&(data))

#define  DVBC_OPT_BN_ERR_ACC_TH                                                  0x180E8474
#define  DVBC_OPT_BN_ERR_ACC_TH_reg_addr                                         "0xB80E8474"
#define  DVBC_OPT_BN_ERR_ACC_TH_reg                                              0xB80E8474
#define  DVBC_OPT_BN_ERR_ACC_TH_inst_addr                                        "0x0069"
#define  set_DVBC_OPT_BN_ERR_ACC_TH_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_BN_ERR_ACC_TH_reg)=data)
#define  get_DVBC_OPT_BN_ERR_ACC_TH_reg                                          (*((volatile unsigned int*)DVBC_OPT_BN_ERR_ACC_TH_reg))
#define  DVBC_OPT_BN_ERR_ACC_TH_opt_ak_pow_in_cr_sel_shift                       (6)
#define  DVBC_OPT_BN_ERR_ACC_TH_opt_bn_err_acc_th_shift                          (0)
#define  DVBC_OPT_BN_ERR_ACC_TH_opt_ak_pow_in_cr_sel_mask                        (0x000000C0)
#define  DVBC_OPT_BN_ERR_ACC_TH_opt_bn_err_acc_th_mask                           (0x0000003F)
#define  DVBC_OPT_BN_ERR_ACC_TH_opt_ak_pow_in_cr_sel(data)                       (0x000000C0&((data)<<6))
#define  DVBC_OPT_BN_ERR_ACC_TH_opt_bn_err_acc_th(data)                          (0x0000003F&(data))
#define  DVBC_OPT_BN_ERR_ACC_TH_get_opt_ak_pow_in_cr_sel(data)                   ((0x000000C0&(data))>>6)
#define  DVBC_OPT_BN_ERR_ACC_TH_get_opt_bn_err_acc_th(data)                      (0x0000003F&(data))

#define  DVBC_OPT_AK_DD_CR_POW_TH                                                0x180E8478
#define  DVBC_OPT_AK_DD_CR_POW_TH_reg_addr                                       "0xB80E8478"
#define  DVBC_OPT_AK_DD_CR_POW_TH_reg                                            0xB80E8478
#define  DVBC_OPT_AK_DD_CR_POW_TH_inst_addr                                      "0x006A"
#define  set_DVBC_OPT_AK_DD_CR_POW_TH_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_AK_DD_CR_POW_TH_reg)=data)
#define  get_DVBC_OPT_AK_DD_CR_POW_TH_reg                                        (*((volatile unsigned int*)DVBC_OPT_AK_DD_CR_POW_TH_reg))
#define  DVBC_OPT_AK_DD_CR_POW_TH_opt_tr_ld_gard_on_shift                        (7)
#define  DVBC_OPT_AK_DD_CR_POW_TH_opt_ak_pow_in_shift                            (6)
#define  DVBC_OPT_AK_DD_CR_POW_TH_opt_ak_dd_cr_pow_th_shift                      (0)
#define  DVBC_OPT_AK_DD_CR_POW_TH_opt_tr_ld_gard_on_mask                         (0x00000080)
#define  DVBC_OPT_AK_DD_CR_POW_TH_opt_ak_pow_in_mask                             (0x00000040)
#define  DVBC_OPT_AK_DD_CR_POW_TH_opt_ak_dd_cr_pow_th_mask                       (0x0000003F)
#define  DVBC_OPT_AK_DD_CR_POW_TH_opt_tr_ld_gard_on(data)                        (0x00000080&((data)<<7))
#define  DVBC_OPT_AK_DD_CR_POW_TH_opt_ak_pow_in(data)                            (0x00000040&((data)<<6))
#define  DVBC_OPT_AK_DD_CR_POW_TH_opt_ak_dd_cr_pow_th(data)                      (0x0000003F&(data))
#define  DVBC_OPT_AK_DD_CR_POW_TH_get_opt_tr_ld_gard_on(data)                    ((0x00000080&(data))>>7)
#define  DVBC_OPT_AK_DD_CR_POW_TH_get_opt_ak_pow_in(data)                        ((0x00000040&(data))>>6)
#define  DVBC_OPT_AK_DD_CR_POW_TH_get_opt_ak_dd_cr_pow_th(data)                  (0x0000003F&(data))

#define  DVBC_OPT_TR_DECI_RATIO                                                  0x180E847C
#define  DVBC_OPT_TR_DECI_RATIO_reg_addr                                         "0xB80E847C"
#define  DVBC_OPT_TR_DECI_RATIO_reg                                              0xB80E847C
#define  DVBC_OPT_TR_DECI_RATIO_inst_addr                                        "0x006B"
#define  set_DVBC_OPT_TR_DECI_RATIO_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_TR_DECI_RATIO_reg)=data)
#define  get_DVBC_OPT_TR_DECI_RATIO_reg                                          (*((volatile unsigned int*)DVBC_OPT_TR_DECI_RATIO_reg))
#define  DVBC_OPT_TR_DECI_RATIO_opt_tr_deci_ratio_7_0_shift                      (0)
#define  DVBC_OPT_TR_DECI_RATIO_opt_tr_deci_ratio_7_0_mask                       (0x000000FF)
#define  DVBC_OPT_TR_DECI_RATIO_opt_tr_deci_ratio_7_0(data)                      (0x000000FF&(data))
#define  DVBC_OPT_TR_DECI_RATIO_get_opt_tr_deci_ratio_7_0(data)                  (0x000000FF&(data))

#define  DVBC_OPT_TR_DECI_RATIO_1                                                0x180E8480
#define  DVBC_OPT_TR_DECI_RATIO_1_reg_addr                                       "0xB80E8480"
#define  DVBC_OPT_TR_DECI_RATIO_1_reg                                            0xB80E8480
#define  DVBC_OPT_TR_DECI_RATIO_1_inst_addr                                      "0x006C"
#define  set_DVBC_OPT_TR_DECI_RATIO_1_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_TR_DECI_RATIO_1_reg)=data)
#define  get_DVBC_OPT_TR_DECI_RATIO_1_reg                                        (*((volatile unsigned int*)DVBC_OPT_TR_DECI_RATIO_1_reg))
#define  DVBC_OPT_TR_DECI_RATIO_1_opt_tr_deci_ratio_15_8_shift                   (0)
#define  DVBC_OPT_TR_DECI_RATIO_1_opt_tr_deci_ratio_15_8_mask                    (0x000000FF)
#define  DVBC_OPT_TR_DECI_RATIO_1_opt_tr_deci_ratio_15_8(data)                   (0x000000FF&(data))
#define  DVBC_OPT_TR_DECI_RATIO_1_get_opt_tr_deci_ratio_15_8(data)               (0x000000FF&(data))

#define  DVBC_OPT_TR_DECI_RATIO_2                                                0x180E8484
#define  DVBC_OPT_TR_DECI_RATIO_2_reg_addr                                       "0xB80E8484"
#define  DVBC_OPT_TR_DECI_RATIO_2_reg                                            0xB80E8484
#define  DVBC_OPT_TR_DECI_RATIO_2_inst_addr                                      "0x006D"
#define  set_DVBC_OPT_TR_DECI_RATIO_2_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_TR_DECI_RATIO_2_reg)=data)
#define  get_DVBC_OPT_TR_DECI_RATIO_2_reg                                        (*((volatile unsigned int*)DVBC_OPT_TR_DECI_RATIO_2_reg))
#define  DVBC_OPT_TR_DECI_RATIO_2_opt_tr_deci_ratio_23_16_shift                  (0)
#define  DVBC_OPT_TR_DECI_RATIO_2_opt_tr_deci_ratio_23_16_mask                   (0x000000FF)
#define  DVBC_OPT_TR_DECI_RATIO_2_opt_tr_deci_ratio_23_16(data)                  (0x000000FF&(data))
#define  DVBC_OPT_TR_DECI_RATIO_2_get_opt_tr_deci_ratio_23_16(data)              (0x000000FF&(data))

#define  DVBC_OPT_KI_TR_OUT_MAX                                                  0x180E8488
#define  DVBC_OPT_KI_TR_OUT_MAX_reg_addr                                         "0xB80E8488"
#define  DVBC_OPT_KI_TR_OUT_MAX_reg                                              0xB80E8488
#define  DVBC_OPT_KI_TR_OUT_MAX_inst_addr                                        "0x006E"
#define  set_DVBC_OPT_KI_TR_OUT_MAX_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_KI_TR_OUT_MAX_reg)=data)
#define  get_DVBC_OPT_KI_TR_OUT_MAX_reg                                          (*((volatile unsigned int*)DVBC_OPT_KI_TR_OUT_MAX_reg))
#define  DVBC_OPT_KI_TR_OUT_MAX_opt_ki_tr_out_max_shift                          (0)
#define  DVBC_OPT_KI_TR_OUT_MAX_opt_ki_tr_out_max_mask                           (0x000000FF)
#define  DVBC_OPT_KI_TR_OUT_MAX_opt_ki_tr_out_max(data)                          (0x000000FF&(data))
#define  DVBC_OPT_KI_TR_OUT_MAX_get_opt_ki_tr_out_max(data)                      (0x000000FF&(data))

#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD                                            0x180E848C
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_reg_addr                                   "0xB80E848C"
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_reg                                        0xB80E848C
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_inst_addr                                  "0x006F"
#define  set_DVBC_OPT_POSTEQ_TR_MM_MAX_DD_reg(data)                              (*((volatile unsigned int*)DVBC_OPT_POSTEQ_TR_MM_MAX_DD_reg)=data)
#define  get_DVBC_OPT_POSTEQ_TR_MM_MAX_DD_reg                                    (*((volatile unsigned int*)DVBC_OPT_POSTEQ_TR_MM_MAX_DD_reg))
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_preeq_tr_phase_inv_shift               (7)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_interl_tr_on_shift                     (6)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_tr_metric_dd_sat_ctrl_shift            (5)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_posteq_tr_mm_max_dd_shift              (0)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_preeq_tr_phase_inv_mask                (0x00000080)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_interl_tr_on_mask                      (0x00000040)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_tr_metric_dd_sat_ctrl_mask             (0x00000020)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_posteq_tr_mm_max_dd_mask               (0x0000001F)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_preeq_tr_phase_inv(data)               (0x00000080&((data)<<7))
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_interl_tr_on(data)                     (0x00000040&((data)<<6))
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_tr_metric_dd_sat_ctrl(data)            (0x00000020&((data)<<5))
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_opt_posteq_tr_mm_max_dd(data)              (0x0000001F&(data))
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_get_opt_preeq_tr_phase_inv(data)           ((0x00000080&(data))>>7)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_get_opt_interl_tr_on(data)                 ((0x00000040&(data))>>6)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_get_opt_tr_metric_dd_sat_ctrl(data)        ((0x00000020&(data))>>5)
#define  DVBC_OPT_POSTEQ_TR_MM_MAX_DD_get_opt_posteq_tr_mm_max_dd(data)          (0x0000001F&(data))

#define  DVBC_OPT_POSTEQ_TR_SEL                                                  0x180E8490
#define  DVBC_OPT_POSTEQ_TR_SEL_reg_addr                                         "0xB80E8490"
#define  DVBC_OPT_POSTEQ_TR_SEL_reg                                              0xB80E8490
#define  DVBC_OPT_POSTEQ_TR_SEL_inst_addr                                        "0x0070"
#define  set_DVBC_OPT_POSTEQ_TR_SEL_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_POSTEQ_TR_SEL_reg)=data)
#define  get_DVBC_OPT_POSTEQ_TR_SEL_reg                                          (*((volatile unsigned int*)DVBC_OPT_POSTEQ_TR_SEL_reg))
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_mk_uk_min_shift                              (3)
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_preeq_tr_guard_on_shift                      (2)
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_posteq_tr_acq_sel_shift                      (1)
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_posteq_tr_sel_shift                          (0)
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_mk_uk_min_mask                               (0x000000F8)
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_preeq_tr_guard_on_mask                       (0x00000004)
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_posteq_tr_acq_sel_mask                       (0x00000002)
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_posteq_tr_sel_mask                           (0x00000001)
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_mk_uk_min(data)                              (0x000000F8&((data)<<3))
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_preeq_tr_guard_on(data)                      (0x00000004&((data)<<2))
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_posteq_tr_acq_sel(data)                      (0x00000002&((data)<<1))
#define  DVBC_OPT_POSTEQ_TR_SEL_opt_posteq_tr_sel(data)                          (0x00000001&(data))
#define  DVBC_OPT_POSTEQ_TR_SEL_get_opt_mk_uk_min(data)                          ((0x000000F8&(data))>>3)
#define  DVBC_OPT_POSTEQ_TR_SEL_get_opt_preeq_tr_guard_on(data)                  ((0x00000004&(data))>>2)
#define  DVBC_OPT_POSTEQ_TR_SEL_get_opt_posteq_tr_acq_sel(data)                  ((0x00000002&(data))>>1)
#define  DVBC_OPT_POSTEQ_TR_SEL_get_opt_posteq_tr_sel(data)                      (0x00000001&(data))

#define  DVBC_OPT_MSE_TH_COND4                                                   0x180E8494
#define  DVBC_OPT_MSE_TH_COND4_reg_addr                                          "0xB80E8494"
#define  DVBC_OPT_MSE_TH_COND4_reg                                               0xB80E8494
#define  DVBC_OPT_MSE_TH_COND4_inst_addr                                         "0x0071"
#define  set_DVBC_OPT_MSE_TH_COND4_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND4_reg)=data)
#define  get_DVBC_OPT_MSE_TH_COND4_reg                                           (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND4_reg))
#define  DVBC_OPT_MSE_TH_COND4_opt_mse_th_cond4_7_0_shift                        (0)
#define  DVBC_OPT_MSE_TH_COND4_opt_mse_th_cond4_7_0_mask                         (0x000000FF)
#define  DVBC_OPT_MSE_TH_COND4_opt_mse_th_cond4_7_0(data)                        (0x000000FF&(data))
#define  DVBC_OPT_MSE_TH_COND4_get_opt_mse_th_cond4_7_0(data)                    (0x000000FF&(data))

#define  DVBC_OPT_MSE_TH_COND4_1                                                 0x180E8498
#define  DVBC_OPT_MSE_TH_COND4_1_reg_addr                                        "0xB80E8498"
#define  DVBC_OPT_MSE_TH_COND4_1_reg                                             0xB80E8498
#define  DVBC_OPT_MSE_TH_COND4_1_inst_addr                                       "0x0072"
#define  set_DVBC_OPT_MSE_TH_COND4_1_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND4_1_reg)=data)
#define  get_DVBC_OPT_MSE_TH_COND4_1_reg                                         (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND4_1_reg))
#define  DVBC_OPT_MSE_TH_COND4_1_opt_tr_ld_out_th_shift                          (2)
#define  DVBC_OPT_MSE_TH_COND4_1_opt_mse_th_cond4_9_8_shift                      (0)
#define  DVBC_OPT_MSE_TH_COND4_1_opt_tr_ld_out_th_mask                           (0x0000007C)
#define  DVBC_OPT_MSE_TH_COND4_1_opt_mse_th_cond4_9_8_mask                       (0x00000003)
#define  DVBC_OPT_MSE_TH_COND4_1_opt_tr_ld_out_th(data)                          (0x0000007C&((data)<<2))
#define  DVBC_OPT_MSE_TH_COND4_1_opt_mse_th_cond4_9_8(data)                      (0x00000003&(data))
#define  DVBC_OPT_MSE_TH_COND4_1_get_opt_tr_ld_out_th(data)                      ((0x0000007C&(data))>>2)
#define  DVBC_OPT_MSE_TH_COND4_1_get_opt_mse_th_cond4_9_8(data)                  (0x00000003&(data))

#define  DVBC_OPT_MSE_TH_COND5                                                   0x180E849C
#define  DVBC_OPT_MSE_TH_COND5_reg_addr                                          "0xB80E849C"
#define  DVBC_OPT_MSE_TH_COND5_reg                                               0xB80E849C
#define  DVBC_OPT_MSE_TH_COND5_inst_addr                                         "0x0073"
#define  set_DVBC_OPT_MSE_TH_COND5_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND5_reg)=data)
#define  get_DVBC_OPT_MSE_TH_COND5_reg                                           (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND5_reg))
#define  DVBC_OPT_MSE_TH_COND5_opt_mse_th_cond5_7_0_shift                        (0)
#define  DVBC_OPT_MSE_TH_COND5_opt_mse_th_cond5_7_0_mask                         (0x000000FF)
#define  DVBC_OPT_MSE_TH_COND5_opt_mse_th_cond5_7_0(data)                        (0x000000FF&(data))
#define  DVBC_OPT_MSE_TH_COND5_get_opt_mse_th_cond5_7_0(data)                    (0x000000FF&(data))

#define  DVBC_OPT_MSE_TH_COND5_1                                                 0x180E84A0
#define  DVBC_OPT_MSE_TH_COND5_1_reg_addr                                        "0xB80E84A0"
#define  DVBC_OPT_MSE_TH_COND5_1_reg                                             0xB80E84A0
#define  DVBC_OPT_MSE_TH_COND5_1_inst_addr                                       "0x0074"
#define  set_DVBC_OPT_MSE_TH_COND5_1_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND5_1_reg)=data)
#define  get_DVBC_OPT_MSE_TH_COND5_1_reg                                         (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND5_1_reg))
#define  DVBC_OPT_MSE_TH_COND5_1_opt_fsm_final_state_shift                       (2)
#define  DVBC_OPT_MSE_TH_COND5_1_opt_mse_th_cond5_9_8_shift                      (0)
#define  DVBC_OPT_MSE_TH_COND5_1_opt_fsm_final_state_mask                        (0x0000003C)
#define  DVBC_OPT_MSE_TH_COND5_1_opt_mse_th_cond5_9_8_mask                       (0x00000003)
#define  DVBC_OPT_MSE_TH_COND5_1_opt_fsm_final_state(data)                       (0x0000003C&((data)<<2))
#define  DVBC_OPT_MSE_TH_COND5_1_opt_mse_th_cond5_9_8(data)                      (0x00000003&(data))
#define  DVBC_OPT_MSE_TH_COND5_1_get_opt_fsm_final_state(data)                   ((0x0000003C&(data))>>2)
#define  DVBC_OPT_MSE_TH_COND5_1_get_opt_mse_th_cond5_9_8(data)                  (0x00000003&(data))

#define  DVBC_OPT_MSE_TH_COND6                                                   0x180E84A4
#define  DVBC_OPT_MSE_TH_COND6_reg_addr                                          "0xB80E84A4"
#define  DVBC_OPT_MSE_TH_COND6_reg                                               0xB80E84A4
#define  DVBC_OPT_MSE_TH_COND6_inst_addr                                         "0x0075"
#define  set_DVBC_OPT_MSE_TH_COND6_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND6_reg)=data)
#define  get_DVBC_OPT_MSE_TH_COND6_reg                                           (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND6_reg))
#define  DVBC_OPT_MSE_TH_COND6_opt_mse_th_cond6_7_0_shift                        (0)
#define  DVBC_OPT_MSE_TH_COND6_opt_mse_th_cond6_7_0_mask                         (0x000000FF)
#define  DVBC_OPT_MSE_TH_COND6_opt_mse_th_cond6_7_0(data)                        (0x000000FF&(data))
#define  DVBC_OPT_MSE_TH_COND6_get_opt_mse_th_cond6_7_0(data)                    (0x000000FF&(data))

#define  DVBC_OPT_MSE_TH_COND6_1                                                 0x180E84A8
#define  DVBC_OPT_MSE_TH_COND6_1_reg_addr                                        "0xB80E84A8"
#define  DVBC_OPT_MSE_TH_COND6_1_reg                                             0xB80E84A8
#define  DVBC_OPT_MSE_TH_COND6_1_inst_addr                                       "0x0076"
#define  set_DVBC_OPT_MSE_TH_COND6_1_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND6_1_reg)=data)
#define  get_DVBC_OPT_MSE_TH_COND6_1_reg                                         (*((volatile unsigned int*)DVBC_OPT_MSE_TH_COND6_1_reg))
#define  DVBC_OPT_MSE_TH_COND6_1_opt_fsm_cond7_sel_shift                         (6)
#define  DVBC_OPT_MSE_TH_COND6_1_opt_cr_cnt_shift                                (2)
#define  DVBC_OPT_MSE_TH_COND6_1_opt_mse_th_cond6_9_8_shift                      (0)
#define  DVBC_OPT_MSE_TH_COND6_1_opt_fsm_cond7_sel_mask                          (0x00000040)
#define  DVBC_OPT_MSE_TH_COND6_1_opt_cr_cnt_mask                                 (0x0000003C)
#define  DVBC_OPT_MSE_TH_COND6_1_opt_mse_th_cond6_9_8_mask                       (0x00000003)
#define  DVBC_OPT_MSE_TH_COND6_1_opt_fsm_cond7_sel(data)                         (0x00000040&((data)<<6))
#define  DVBC_OPT_MSE_TH_COND6_1_opt_cr_cnt(data)                                (0x0000003C&((data)<<2))
#define  DVBC_OPT_MSE_TH_COND6_1_opt_mse_th_cond6_9_8(data)                      (0x00000003&(data))
#define  DVBC_OPT_MSE_TH_COND6_1_get_opt_fsm_cond7_sel(data)                     ((0x00000040&(data))>>6)
#define  DVBC_OPT_MSE_TH_COND6_1_get_opt_cr_cnt(data)                            ((0x0000003C&(data))>>2)
#define  DVBC_OPT_MSE_TH_COND6_1_get_opt_mse_th_cond6_9_8(data)                  (0x00000003&(data))

#define  DVBC_OPT_RST_STATE0_ON                                                  0x180E84AC
#define  DVBC_OPT_RST_STATE0_ON_reg_addr                                         "0xB80E84AC"
#define  DVBC_OPT_RST_STATE0_ON_reg                                              0xB80E84AC
#define  DVBC_OPT_RST_STATE0_ON_inst_addr                                        "0x0077"
#define  set_DVBC_OPT_RST_STATE0_ON_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_RST_STATE0_ON_reg)=data)
#define  get_DVBC_OPT_RST_STATE0_ON_reg                                          (*((volatile unsigned int*)DVBC_OPT_RST_STATE0_ON_reg))
#define  DVBC_OPT_RST_STATE0_ON_opt_rt_cond_and_or_shift                         (7)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond5_en_shift                                (6)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond4_en_shift                                (5)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond3_en_shift                                (4)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond2_en_shift                                (3)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond1_en_shift                                (2)
#define  DVBC_OPT_RST_STATE0_ON_opt_retry_on_shift                               (1)
#define  DVBC_OPT_RST_STATE0_ON_opt_rst_state0_on_shift                          (0)
#define  DVBC_OPT_RST_STATE0_ON_opt_rt_cond_and_or_mask                          (0x00000080)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond5_en_mask                                 (0x00000040)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond4_en_mask                                 (0x00000020)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond3_en_mask                                 (0x00000010)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond2_en_mask                                 (0x00000008)
#define  DVBC_OPT_RST_STATE0_ON_rt_cond1_en_mask                                 (0x00000004)
#define  DVBC_OPT_RST_STATE0_ON_opt_retry_on_mask                                (0x00000002)
#define  DVBC_OPT_RST_STATE0_ON_opt_rst_state0_on_mask                           (0x00000001)
#define  DVBC_OPT_RST_STATE0_ON_opt_rt_cond_and_or(data)                         (0x00000080&((data)<<7))
#define  DVBC_OPT_RST_STATE0_ON_rt_cond5_en(data)                                (0x00000040&((data)<<6))
#define  DVBC_OPT_RST_STATE0_ON_rt_cond4_en(data)                                (0x00000020&((data)<<5))
#define  DVBC_OPT_RST_STATE0_ON_rt_cond3_en(data)                                (0x00000010&((data)<<4))
#define  DVBC_OPT_RST_STATE0_ON_rt_cond2_en(data)                                (0x00000008&((data)<<3))
#define  DVBC_OPT_RST_STATE0_ON_rt_cond1_en(data)                                (0x00000004&((data)<<2))
#define  DVBC_OPT_RST_STATE0_ON_opt_retry_on(data)                               (0x00000002&((data)<<1))
#define  DVBC_OPT_RST_STATE0_ON_opt_rst_state0_on(data)                          (0x00000001&(data))
#define  DVBC_OPT_RST_STATE0_ON_get_opt_rt_cond_and_or(data)                     ((0x00000080&(data))>>7)
#define  DVBC_OPT_RST_STATE0_ON_get_rt_cond5_en(data)                            ((0x00000040&(data))>>6)
#define  DVBC_OPT_RST_STATE0_ON_get_rt_cond4_en(data)                            ((0x00000020&(data))>>5)
#define  DVBC_OPT_RST_STATE0_ON_get_rt_cond3_en(data)                            ((0x00000010&(data))>>4)
#define  DVBC_OPT_RST_STATE0_ON_get_rt_cond2_en(data)                            ((0x00000008&(data))>>3)
#define  DVBC_OPT_RST_STATE0_ON_get_rt_cond1_en(data)                            ((0x00000004&(data))>>2)
#define  DVBC_OPT_RST_STATE0_ON_get_opt_retry_on(data)                           ((0x00000002&(data))>>1)
#define  DVBC_OPT_RST_STATE0_ON_get_opt_rst_state0_on(data)                      (0x00000001&(data))

#define  DVBC_OPT_RT_LOOP_CNT_MIN                                                0x180E84B0
#define  DVBC_OPT_RT_LOOP_CNT_MIN_reg_addr                                       "0xB80E84B0"
#define  DVBC_OPT_RT_LOOP_CNT_MIN_reg                                            0xB80E84B0
#define  DVBC_OPT_RT_LOOP_CNT_MIN_inst_addr                                      "0x0078"
#define  set_DVBC_OPT_RT_LOOP_CNT_MIN_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_RT_LOOP_CNT_MIN_reg)=data)
#define  get_DVBC_OPT_RT_LOOP_CNT_MIN_reg                                        (*((volatile unsigned int*)DVBC_OPT_RT_LOOP_CNT_MIN_reg))
#define  DVBC_OPT_RT_LOOP_CNT_MIN_opt_rt_loop_cnt_min_shift                      (0)
#define  DVBC_OPT_RT_LOOP_CNT_MIN_opt_rt_loop_cnt_min_mask                       (0x000000FF)
#define  DVBC_OPT_RT_LOOP_CNT_MIN_opt_rt_loop_cnt_min(data)                      (0x000000FF&(data))
#define  DVBC_OPT_RT_LOOP_CNT_MIN_get_opt_rt_loop_cnt_min(data)                  (0x000000FF&(data))

#define  DVBC_OPT_RT_MSE_TH                                                      0x180E84B4
#define  DVBC_OPT_RT_MSE_TH_reg_addr                                             "0xB80E84B4"
#define  DVBC_OPT_RT_MSE_TH_reg                                                  0xB80E84B4
#define  DVBC_OPT_RT_MSE_TH_inst_addr                                            "0x0079"
#define  set_DVBC_OPT_RT_MSE_TH_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_RT_MSE_TH_reg)=data)
#define  get_DVBC_OPT_RT_MSE_TH_reg                                              (*((volatile unsigned int*)DVBC_OPT_RT_MSE_TH_reg))
#define  DVBC_OPT_RT_MSE_TH_rt_cond7_en_shift                                    (7)
#define  DVBC_OPT_RT_MSE_TH_rt_cond6_en_shift                                    (6)
#define  DVBC_OPT_RT_MSE_TH_opt_rt_mse_th_shift                                  (0)
#define  DVBC_OPT_RT_MSE_TH_rt_cond7_en_mask                                     (0x00000080)
#define  DVBC_OPT_RT_MSE_TH_rt_cond6_en_mask                                     (0x00000040)
#define  DVBC_OPT_RT_MSE_TH_opt_rt_mse_th_mask                                   (0x0000003F)
#define  DVBC_OPT_RT_MSE_TH_rt_cond7_en(data)                                    (0x00000080&((data)<<7))
#define  DVBC_OPT_RT_MSE_TH_rt_cond6_en(data)                                    (0x00000040&((data)<<6))
#define  DVBC_OPT_RT_MSE_TH_opt_rt_mse_th(data)                                  (0x0000003F&(data))
#define  DVBC_OPT_RT_MSE_TH_get_rt_cond7_en(data)                                ((0x00000080&(data))>>7)
#define  DVBC_OPT_RT_MSE_TH_get_rt_cond6_en(data)                                ((0x00000040&(data))>>6)
#define  DVBC_OPT_RT_MSE_TH_get_opt_rt_mse_th(data)                              (0x0000003F&(data))

#define  DVBC_OPT_DD_EQ_BOUND                                                    0x180E84B8
#define  DVBC_OPT_DD_EQ_BOUND_reg_addr                                           "0xB80E84B8"
#define  DVBC_OPT_DD_EQ_BOUND_reg                                                0xB80E84B8
#define  DVBC_OPT_DD_EQ_BOUND_inst_addr                                          "0x007A"
#define  set_DVBC_OPT_DD_EQ_BOUND_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_DD_EQ_BOUND_reg)=data)
#define  get_DVBC_OPT_DD_EQ_BOUND_reg                                            (*((volatile unsigned int*)DVBC_OPT_DD_EQ_BOUND_reg))
#define  DVBC_OPT_DD_EQ_BOUND_opt_u_iq_exp_shift                                 (6)
#define  DVBC_OPT_DD_EQ_BOUND_opt_dd_eq_bound_shift                              (0)
#define  DVBC_OPT_DD_EQ_BOUND_opt_u_iq_exp_mask                                  (0x000000C0)
#define  DVBC_OPT_DD_EQ_BOUND_opt_dd_eq_bound_mask                               (0x0000003F)
#define  DVBC_OPT_DD_EQ_BOUND_opt_u_iq_exp(data)                                 (0x000000C0&((data)<<6))
#define  DVBC_OPT_DD_EQ_BOUND_opt_dd_eq_bound(data)                              (0x0000003F&(data))
#define  DVBC_OPT_DD_EQ_BOUND_get_opt_u_iq_exp(data)                             ((0x000000C0&(data))>>6)
#define  DVBC_OPT_DD_EQ_BOUND_get_opt_dd_eq_bound(data)                          (0x0000003F&(data))

#define  DVBC_OPT_SIGN_DATA                                                      0x180E84BC
#define  DVBC_OPT_SIGN_DATA_reg_addr                                             "0xB80E84BC"
#define  DVBC_OPT_SIGN_DATA_reg                                                  0xB80E84BC
#define  DVBC_OPT_SIGN_DATA_inst_addr                                            "0x007B"
#define  set_DVBC_OPT_SIGN_DATA_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_SIGN_DATA_reg)=data)
#define  get_DVBC_OPT_SIGN_DATA_reg                                              (*((volatile unsigned int*)DVBC_OPT_SIGN_DATA_reg))
#define  DVBC_OPT_SIGN_DATA_opt_rca_lvl_sqrt_2_0_shift                           (5)
#define  DVBC_OPT_SIGN_DATA_opt_sign_data_exp_fbf_shift                          (3)
#define  DVBC_OPT_SIGN_DATA_opt_sign_data_exp_fff_shift                          (1)
#define  DVBC_OPT_SIGN_DATA_opt_sign_data_shift                                  (0)
#define  DVBC_OPT_SIGN_DATA_opt_rca_lvl_sqrt_2_0_mask                            (0x000000E0)
#define  DVBC_OPT_SIGN_DATA_opt_sign_data_exp_fbf_mask                           (0x00000018)
#define  DVBC_OPT_SIGN_DATA_opt_sign_data_exp_fff_mask                           (0x00000006)
#define  DVBC_OPT_SIGN_DATA_opt_sign_data_mask                                   (0x00000001)
#define  DVBC_OPT_SIGN_DATA_opt_rca_lvl_sqrt_2_0(data)                           (0x000000E0&((data)<<5))
#define  DVBC_OPT_SIGN_DATA_opt_sign_data_exp_fbf(data)                          (0x00000018&((data)<<3))
#define  DVBC_OPT_SIGN_DATA_opt_sign_data_exp_fff(data)                          (0x00000006&((data)<<1))
#define  DVBC_OPT_SIGN_DATA_opt_sign_data(data)                                  (0x00000001&(data))
#define  DVBC_OPT_SIGN_DATA_get_opt_rca_lvl_sqrt_2_0(data)                       ((0x000000E0&(data))>>5)
#define  DVBC_OPT_SIGN_DATA_get_opt_sign_data_exp_fbf(data)                      ((0x00000018&(data))>>3)
#define  DVBC_OPT_SIGN_DATA_get_opt_sign_data_exp_fff(data)                      ((0x00000006&(data))>>1)
#define  DVBC_OPT_SIGN_DATA_get_opt_sign_data(data)                              (0x00000001&(data))

#define  DVBC_OPT_SIGN_DATA_1                                                    0x180E84C0
#define  DVBC_OPT_SIGN_DATA_1_reg_addr                                           "0xB80E84C0"
#define  DVBC_OPT_SIGN_DATA_1_reg                                                0xB80E84C0
#define  DVBC_OPT_SIGN_DATA_1_inst_addr                                          "0x007C"
#define  set_DVBC_OPT_SIGN_DATA_1_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_SIGN_DATA_1_reg)=data)
#define  get_DVBC_OPT_SIGN_DATA_1_reg                                            (*((volatile unsigned int*)DVBC_OPT_SIGN_DATA_1_reg))
#define  DVBC_OPT_SIGN_DATA_1_opt_rca_lvl_sqrt_10_3_shift                        (0)
#define  DVBC_OPT_SIGN_DATA_1_opt_rca_lvl_sqrt_10_3_mask                         (0x000000FF)
#define  DVBC_OPT_SIGN_DATA_1_opt_rca_lvl_sqrt_10_3(data)                        (0x000000FF&(data))
#define  DVBC_OPT_SIGN_DATA_1_get_opt_rca_lvl_sqrt_10_3(data)                    (0x000000FF&(data))

#define  DVBC_OPT_CIRCLE                                                         0x180E84C4
#define  DVBC_OPT_CIRCLE_reg_addr                                                "0xB80E84C4"
#define  DVBC_OPT_CIRCLE_reg                                                     0xB80E84C4
#define  DVBC_OPT_CIRCLE_inst_addr                                               "0x007D"
#define  set_DVBC_OPT_CIRCLE_reg(data)                                           (*((volatile unsigned int*)DVBC_OPT_CIRCLE_reg)=data)
#define  get_DVBC_OPT_CIRCLE_reg                                                 (*((volatile unsigned int*)DVBC_OPT_CIRCLE_reg))
#define  DVBC_OPT_CIRCLE_opt_circle_shift                                        (0)
#define  DVBC_OPT_CIRCLE_opt_circle_mask                                         (0x0000003F)
#define  DVBC_OPT_CIRCLE_opt_circle(data)                                        (0x0000003F&(data))
#define  DVBC_OPT_CIRCLE_get_opt_circle(data)                                    (0x0000003F&(data))

#define  DVBC_OPT_LEAKAGE_SIZE_EXP                                               0x180E84C8
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_reg_addr                                      "0xB80E84C8"
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_reg                                           0xB80E84C8
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_inst_addr                                     "0x007E"
#define  set_DVBC_OPT_LEAKAGE_SIZE_EXP_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_LEAKAGE_SIZE_EXP_reg)=data)
#define  get_DVBC_OPT_LEAKAGE_SIZE_EXP_reg                                       (*((volatile unsigned int*)DVBC_OPT_LEAKAGE_SIZE_EXP_reg))
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_opt_leakage_f_u_en_acq_shift                  (7)
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_opt_leakage_f_u_en_dd_shift                   (6)
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_opt_leakage_size_exp_shift                    (3)
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_opt_leakage_f_u_en_acq_mask                   (0x00000080)
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_opt_leakage_f_u_en_dd_mask                    (0x00000040)
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_opt_leakage_size_exp_mask                     (0x00000038)
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_opt_leakage_f_u_en_acq(data)                  (0x00000080&((data)<<7))
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_opt_leakage_f_u_en_dd(data)                   (0x00000040&((data)<<6))
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_opt_leakage_size_exp(data)                    (0x00000038&((data)<<3))
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_get_opt_leakage_f_u_en_acq(data)              ((0x00000080&(data))>>7)
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_get_opt_leakage_f_u_en_dd(data)               ((0x00000040&(data))>>6)
#define  DVBC_OPT_LEAKAGE_SIZE_EXP_get_opt_leakage_size_exp(data)                ((0x00000038&(data))>>3)

#define  DVBC_OPT_LEAKAGE_PERIOD                                                 0x180E84CC
#define  DVBC_OPT_LEAKAGE_PERIOD_reg_addr                                        "0xB80E84CC"
#define  DVBC_OPT_LEAKAGE_PERIOD_reg                                             0xB80E84CC
#define  DVBC_OPT_LEAKAGE_PERIOD_inst_addr                                       "0x007F"
#define  set_DVBC_OPT_LEAKAGE_PERIOD_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_LEAKAGE_PERIOD_reg)=data)
#define  get_DVBC_OPT_LEAKAGE_PERIOD_reg                                         (*((volatile unsigned int*)DVBC_OPT_LEAKAGE_PERIOD_reg))
#define  DVBC_OPT_LEAKAGE_PERIOD_opt_leakage_f_amp_en_shift                      (7)
#define  DVBC_OPT_LEAKAGE_PERIOD_opt_leakage_period_shift                        (0)
#define  DVBC_OPT_LEAKAGE_PERIOD_opt_leakage_f_amp_en_mask                       (0x00000080)
#define  DVBC_OPT_LEAKAGE_PERIOD_opt_leakage_period_mask                         (0x0000007F)
#define  DVBC_OPT_LEAKAGE_PERIOD_opt_leakage_f_amp_en(data)                      (0x00000080&((data)<<7))
#define  DVBC_OPT_LEAKAGE_PERIOD_opt_leakage_period(data)                        (0x0000007F&(data))
#define  DVBC_OPT_LEAKAGE_PERIOD_get_opt_leakage_f_amp_en(data)                  ((0x00000080&(data))>>7)
#define  DVBC_OPT_LEAKAGE_PERIOD_get_opt_leakage_period(data)                    (0x0000007F&(data))

#define  DVBC_OPT_MSE_AMP_THR1                                                   0x180E84D0
#define  DVBC_OPT_MSE_AMP_THR1_reg_addr                                          "0xB80E84D0"
#define  DVBC_OPT_MSE_AMP_THR1_reg                                               0xB80E84D0
#define  DVBC_OPT_MSE_AMP_THR1_inst_addr                                         "0x0080"
#define  set_DVBC_OPT_MSE_AMP_THR1_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_MSE_AMP_THR1_reg)=data)
#define  get_DVBC_OPT_MSE_AMP_THR1_reg                                           (*((volatile unsigned int*)DVBC_OPT_MSE_AMP_THR1_reg))
#define  DVBC_OPT_MSE_AMP_THR1_opt_mse_amp_thr1_shift                            (0)
#define  DVBC_OPT_MSE_AMP_THR1_opt_mse_amp_thr1_mask                             (0x000000FF)
#define  DVBC_OPT_MSE_AMP_THR1_opt_mse_amp_thr1(data)                            (0x000000FF&(data))
#define  DVBC_OPT_MSE_AMP_THR1_get_opt_mse_amp_thr1(data)                        (0x000000FF&(data))

#define  DVBC_OPT_MSE_AMP_THR2                                                   0x180E84D4
#define  DVBC_OPT_MSE_AMP_THR2_reg_addr                                          "0xB80E84D4"
#define  DVBC_OPT_MSE_AMP_THR2_reg                                               0xB80E84D4
#define  DVBC_OPT_MSE_AMP_THR2_inst_addr                                         "0x0081"
#define  set_DVBC_OPT_MSE_AMP_THR2_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_MSE_AMP_THR2_reg)=data)
#define  get_DVBC_OPT_MSE_AMP_THR2_reg                                           (*((volatile unsigned int*)DVBC_OPT_MSE_AMP_THR2_reg))
#define  DVBC_OPT_MSE_AMP_THR2_opt_mse_amp_thr2_shift                            (0)
#define  DVBC_OPT_MSE_AMP_THR2_opt_mse_amp_thr2_mask                             (0x000000FF)
#define  DVBC_OPT_MSE_AMP_THR2_opt_mse_amp_thr2(data)                            (0x000000FF&(data))
#define  DVBC_OPT_MSE_AMP_THR2_get_opt_mse_amp_thr2(data)                        (0x000000FF&(data))

#define  DVBC_OPT_MAX_AMP0                                                       0x180E84D8
#define  DVBC_OPT_MAX_AMP0_reg_addr                                              "0xB80E84D8"
#define  DVBC_OPT_MAX_AMP0_reg                                                   0xB80E84D8
#define  DVBC_OPT_MAX_AMP0_inst_addr                                             "0x0082"
#define  set_DVBC_OPT_MAX_AMP0_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_MAX_AMP0_reg)=data)
#define  get_DVBC_OPT_MAX_AMP0_reg                                               (*((volatile unsigned int*)DVBC_OPT_MAX_AMP0_reg))
#define  DVBC_OPT_MAX_AMP0_opt_leakage_f_amp_exp_shift                           (6)
#define  DVBC_OPT_MAX_AMP0_opt_leakage_f_amp_exp_en_shift                        (5)
#define  DVBC_OPT_MAX_AMP0_opt_max_amp0_shift                                    (0)
#define  DVBC_OPT_MAX_AMP0_opt_leakage_f_amp_exp_mask                            (0x000000C0)
#define  DVBC_OPT_MAX_AMP0_opt_leakage_f_amp_exp_en_mask                         (0x00000020)
#define  DVBC_OPT_MAX_AMP0_opt_max_amp0_mask                                     (0x0000001F)
#define  DVBC_OPT_MAX_AMP0_opt_leakage_f_amp_exp(data)                           (0x000000C0&((data)<<6))
#define  DVBC_OPT_MAX_AMP0_opt_leakage_f_amp_exp_en(data)                        (0x00000020&((data)<<5))
#define  DVBC_OPT_MAX_AMP0_opt_max_amp0(data)                                    (0x0000001F&(data))
#define  DVBC_OPT_MAX_AMP0_get_opt_leakage_f_amp_exp(data)                       ((0x000000C0&(data))>>6)
#define  DVBC_OPT_MAX_AMP0_get_opt_leakage_f_amp_exp_en(data)                    ((0x00000020&(data))>>5)
#define  DVBC_OPT_MAX_AMP0_get_opt_max_amp0(data)                                (0x0000001F&(data))

#define  DVBC_OPT_MAX_AMP1                                                       0x180E84DC
#define  DVBC_OPT_MAX_AMP1_reg_addr                                              "0xB80E84DC"
#define  DVBC_OPT_MAX_AMP1_reg                                                   0xB80E84DC
#define  DVBC_OPT_MAX_AMP1_inst_addr                                             "0x0083"
#define  set_DVBC_OPT_MAX_AMP1_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_MAX_AMP1_reg)=data)
#define  get_DVBC_OPT_MAX_AMP1_reg                                               (*((volatile unsigned int*)DVBC_OPT_MAX_AMP1_reg))
#define  DVBC_OPT_MAX_AMP1_opt_max_amp1_shift                                    (0)
#define  DVBC_OPT_MAX_AMP1_opt_max_amp1_mask                                     (0x0000001F)
#define  DVBC_OPT_MAX_AMP1_opt_max_amp1(data)                                    (0x0000001F&(data))
#define  DVBC_OPT_MAX_AMP1_get_opt_max_amp1(data)                                (0x0000001F&(data))

#define  DVBC_OPT_MAX_AMP2                                                       0x180E84E0
#define  DVBC_OPT_MAX_AMP2_reg_addr                                              "0xB80E84E0"
#define  DVBC_OPT_MAX_AMP2_reg                                                   0xB80E84E0
#define  DVBC_OPT_MAX_AMP2_inst_addr                                             "0x0084"
#define  set_DVBC_OPT_MAX_AMP2_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_MAX_AMP2_reg)=data)
#define  get_DVBC_OPT_MAX_AMP2_reg                                               (*((volatile unsigned int*)DVBC_OPT_MAX_AMP2_reg))
#define  DVBC_OPT_MAX_AMP2_opt_max_amp2_shift                                    (0)
#define  DVBC_OPT_MAX_AMP2_opt_max_amp2_mask                                     (0x0000001F)
#define  DVBC_OPT_MAX_AMP2_opt_max_amp2(data)                                    (0x0000001F&(data))
#define  DVBC_OPT_MAX_AMP2_get_opt_max_amp2(data)                                (0x0000001F&(data))

#define  DVBC_OPT_MSE_TH_EQ_ACQ1                                                 0x180E84E4
#define  DVBC_OPT_MSE_TH_EQ_ACQ1_reg_addr                                        "0xB80E84E4"
#define  DVBC_OPT_MSE_TH_EQ_ACQ1_reg                                             0xB80E84E4
#define  DVBC_OPT_MSE_TH_EQ_ACQ1_inst_addr                                       "0x0085"
#define  set_DVBC_OPT_MSE_TH_EQ_ACQ1_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_MSE_TH_EQ_ACQ1_reg)=data)
#define  get_DVBC_OPT_MSE_TH_EQ_ACQ1_reg                                         (*((volatile unsigned int*)DVBC_OPT_MSE_TH_EQ_ACQ1_reg))
#define  DVBC_OPT_MSE_TH_EQ_ACQ1_opt_mse_th_eq_acq1_shift                        (0)
#define  DVBC_OPT_MSE_TH_EQ_ACQ1_opt_mse_th_eq_acq1_mask                         (0x000000FF)
#define  DVBC_OPT_MSE_TH_EQ_ACQ1_opt_mse_th_eq_acq1(data)                        (0x000000FF&(data))
#define  DVBC_OPT_MSE_TH_EQ_ACQ1_get_opt_mse_th_eq_acq1(data)                    (0x000000FF&(data))

#define  DVBC_OPT_MSE_TH_EQ_ACQ2                                                 0x180E84E8
#define  DVBC_OPT_MSE_TH_EQ_ACQ2_reg_addr                                        "0xB80E84E8"
#define  DVBC_OPT_MSE_TH_EQ_ACQ2_reg                                             0xB80E84E8
#define  DVBC_OPT_MSE_TH_EQ_ACQ2_inst_addr                                       "0x0086"
#define  set_DVBC_OPT_MSE_TH_EQ_ACQ2_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_MSE_TH_EQ_ACQ2_reg)=data)
#define  get_DVBC_OPT_MSE_TH_EQ_ACQ2_reg                                         (*((volatile unsigned int*)DVBC_OPT_MSE_TH_EQ_ACQ2_reg))
#define  DVBC_OPT_MSE_TH_EQ_ACQ2_opt_mse_th_eq_acq2_shift                        (0)
#define  DVBC_OPT_MSE_TH_EQ_ACQ2_opt_mse_th_eq_acq2_mask                         (0x000000FF)
#define  DVBC_OPT_MSE_TH_EQ_ACQ2_opt_mse_th_eq_acq2(data)                        (0x000000FF&(data))
#define  DVBC_OPT_MSE_TH_EQ_ACQ2_get_opt_mse_th_eq_acq2(data)                    (0x000000FF&(data))

#define  DVBC_OPT_U_FFF_ACQ0                                                     0x180E84EC
#define  DVBC_OPT_U_FFF_ACQ0_reg_addr                                            "0xB80E84EC"
#define  DVBC_OPT_U_FFF_ACQ0_reg                                                 0xB80E84EC
#define  DVBC_OPT_U_FFF_ACQ0_inst_addr                                           "0x0087"
#define  set_DVBC_OPT_U_FFF_ACQ0_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_U_FFF_ACQ0_reg)=data)
#define  get_DVBC_OPT_U_FFF_ACQ0_reg                                             (*((volatile unsigned int*)DVBC_OPT_U_FFF_ACQ0_reg))
#define  DVBC_OPT_U_FFF_ACQ0_opt_u_fff_acq1_shift                                (3)
#define  DVBC_OPT_U_FFF_ACQ0_opt_u_fff_acq0_shift                                (0)
#define  DVBC_OPT_U_FFF_ACQ0_opt_u_fff_acq1_mask                                 (0x00000038)
#define  DVBC_OPT_U_FFF_ACQ0_opt_u_fff_acq0_mask                                 (0x00000007)
#define  DVBC_OPT_U_FFF_ACQ0_opt_u_fff_acq1(data)                                (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF_ACQ0_opt_u_fff_acq0(data)                                (0x00000007&(data))
#define  DVBC_OPT_U_FFF_ACQ0_get_opt_u_fff_acq1(data)                            ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF_ACQ0_get_opt_u_fff_acq0(data)                            (0x00000007&(data))

#define  DVBC_OPT_U_FFF_ACQ2                                                     0x180E84F0
#define  DVBC_OPT_U_FFF_ACQ2_reg_addr                                            "0xB80E84F0"
#define  DVBC_OPT_U_FFF_ACQ2_reg                                                 0xB80E84F0
#define  DVBC_OPT_U_FFF_ACQ2_inst_addr                                           "0x0088"
#define  set_DVBC_OPT_U_FFF_ACQ2_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_U_FFF_ACQ2_reg)=data)
#define  get_DVBC_OPT_U_FFF_ACQ2_reg                                             (*((volatile unsigned int*)DVBC_OPT_U_FFF_ACQ2_reg))
#define  DVBC_OPT_U_FFF_ACQ2_opt_u_fbf_acq1_shift                                (5)
#define  DVBC_OPT_U_FFF_ACQ2_opt_u_fbf_acq0_shift                                (3)
#define  DVBC_OPT_U_FFF_ACQ2_opt_u_fff_acq2_shift                                (0)
#define  DVBC_OPT_U_FFF_ACQ2_opt_u_fbf_acq1_mask                                 (0x00000060)
#define  DVBC_OPT_U_FFF_ACQ2_opt_u_fbf_acq0_mask                                 (0x00000018)
#define  DVBC_OPT_U_FFF_ACQ2_opt_u_fff_acq2_mask                                 (0x00000007)
#define  DVBC_OPT_U_FFF_ACQ2_opt_u_fbf_acq1(data)                                (0x00000060&((data)<<5))
#define  DVBC_OPT_U_FFF_ACQ2_opt_u_fbf_acq0(data)                                (0x00000018&((data)<<3))
#define  DVBC_OPT_U_FFF_ACQ2_opt_u_fff_acq2(data)                                (0x00000007&(data))
#define  DVBC_OPT_U_FFF_ACQ2_get_opt_u_fbf_acq1(data)                            ((0x00000060&(data))>>5)
#define  DVBC_OPT_U_FFF_ACQ2_get_opt_u_fbf_acq0(data)                            ((0x00000018&(data))>>3)
#define  DVBC_OPT_U_FFF_ACQ2_get_opt_u_fff_acq2(data)                            (0x00000007&(data))

#define  DVBC_OPT_U_FBF_ACQ2                                                     0x180E84F4
#define  DVBC_OPT_U_FBF_ACQ2_reg_addr                                            "0xB80E84F4"
#define  DVBC_OPT_U_FBF_ACQ2_reg                                                 0xB80E84F4
#define  DVBC_OPT_U_FBF_ACQ2_inst_addr                                           "0x0089"
#define  set_DVBC_OPT_U_FBF_ACQ2_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_U_FBF_ACQ2_reg)=data)
#define  get_DVBC_OPT_U_FBF_ACQ2_reg                                             (*((volatile unsigned int*)DVBC_OPT_U_FBF_ACQ2_reg))
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf2_acq2_shift                               (6)
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf2_acq1_shift                               (4)
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf2_acq0_shift                               (2)
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf_acq2_shift                                (0)
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf2_acq2_mask                                (0x000000C0)
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf2_acq1_mask                                (0x00000030)
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf2_acq0_mask                                (0x0000000C)
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf_acq2_mask                                 (0x00000003)
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf2_acq2(data)                               (0x000000C0&((data)<<6))
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf2_acq1(data)                               (0x00000030&((data)<<4))
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf2_acq0(data)                               (0x0000000C&((data)<<2))
#define  DVBC_OPT_U_FBF_ACQ2_opt_u_fbf_acq2(data)                                (0x00000003&(data))
#define  DVBC_OPT_U_FBF_ACQ2_get_opt_u_fbf2_acq2(data)                           ((0x000000C0&(data))>>6)
#define  DVBC_OPT_U_FBF_ACQ2_get_opt_u_fbf2_acq1(data)                           ((0x00000030&(data))>>4)
#define  DVBC_OPT_U_FBF_ACQ2_get_opt_u_fbf2_acq0(data)                           ((0x0000000C&(data))>>2)
#define  DVBC_OPT_U_FBF_ACQ2_get_opt_u_fbf_acq2(data)                            (0x00000003&(data))

#define  DVBC_OPT_MSE_TH_EQ_DD1                                                  0x180E84F8
#define  DVBC_OPT_MSE_TH_EQ_DD1_reg_addr                                         "0xB80E84F8"
#define  DVBC_OPT_MSE_TH_EQ_DD1_reg                                              0xB80E84F8
#define  DVBC_OPT_MSE_TH_EQ_DD1_inst_addr                                        "0x008A"
#define  set_DVBC_OPT_MSE_TH_EQ_DD1_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_MSE_TH_EQ_DD1_reg)=data)
#define  get_DVBC_OPT_MSE_TH_EQ_DD1_reg                                          (*((volatile unsigned int*)DVBC_OPT_MSE_TH_EQ_DD1_reg))
#define  DVBC_OPT_MSE_TH_EQ_DD1_opt_mse_th_eq_dd1_shift                          (0)
#define  DVBC_OPT_MSE_TH_EQ_DD1_opt_mse_th_eq_dd1_mask                           (0x000000FF)
#define  DVBC_OPT_MSE_TH_EQ_DD1_opt_mse_th_eq_dd1(data)                          (0x000000FF&(data))
#define  DVBC_OPT_MSE_TH_EQ_DD1_get_opt_mse_th_eq_dd1(data)                      (0x000000FF&(data))

#define  DVBC_OPT_MSE_TH_EQ_DD2                                                  0x180E84FC
#define  DVBC_OPT_MSE_TH_EQ_DD2_reg_addr                                         "0xB80E84FC"
#define  DVBC_OPT_MSE_TH_EQ_DD2_reg                                              0xB80E84FC
#define  DVBC_OPT_MSE_TH_EQ_DD2_inst_addr                                        "0x008B"
#define  set_DVBC_OPT_MSE_TH_EQ_DD2_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_MSE_TH_EQ_DD2_reg)=data)
#define  get_DVBC_OPT_MSE_TH_EQ_DD2_reg                                          (*((volatile unsigned int*)DVBC_OPT_MSE_TH_EQ_DD2_reg))
#define  DVBC_OPT_MSE_TH_EQ_DD2_opt_mse_th_eq_dd2_shift                          (0)
#define  DVBC_OPT_MSE_TH_EQ_DD2_opt_mse_th_eq_dd2_mask                           (0x000000FF)
#define  DVBC_OPT_MSE_TH_EQ_DD2_opt_mse_th_eq_dd2(data)                          (0x000000FF&(data))
#define  DVBC_OPT_MSE_TH_EQ_DD2_get_opt_mse_th_eq_dd2(data)                      (0x000000FF&(data))

#define  DVBC_OPT_U_FFF_DD0                                                      0x180E8500
#define  DVBC_OPT_U_FFF_DD0_reg_addr                                             "0xB80E8500"
#define  DVBC_OPT_U_FFF_DD0_reg                                                  0xB80E8500
#define  DVBC_OPT_U_FFF_DD0_inst_addr                                            "0x008C"
#define  set_DVBC_OPT_U_FFF_DD0_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_U_FFF_DD0_reg)=data)
#define  get_DVBC_OPT_U_FFF_DD0_reg                                              (*((volatile unsigned int*)DVBC_OPT_U_FFF_DD0_reg))
#define  DVBC_OPT_U_FFF_DD0_opt_u_fff_dd1_shift                                  (3)
#define  DVBC_OPT_U_FFF_DD0_opt_u_fff_dd0_shift                                  (0)
#define  DVBC_OPT_U_FFF_DD0_opt_u_fff_dd1_mask                                   (0x00000038)
#define  DVBC_OPT_U_FFF_DD0_opt_u_fff_dd0_mask                                   (0x00000007)
#define  DVBC_OPT_U_FFF_DD0_opt_u_fff_dd1(data)                                  (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF_DD0_opt_u_fff_dd0(data)                                  (0x00000007&(data))
#define  DVBC_OPT_U_FFF_DD0_get_opt_u_fff_dd1(data)                              ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF_DD0_get_opt_u_fff_dd0(data)                              (0x00000007&(data))

#define  DVBC_OPT_U_FFF_DD2                                                      0x180E8504
#define  DVBC_OPT_U_FFF_DD2_reg_addr                                             "0xB80E8504"
#define  DVBC_OPT_U_FFF_DD2_reg                                                  0xB80E8504
#define  DVBC_OPT_U_FFF_DD2_inst_addr                                            "0x008D"
#define  set_DVBC_OPT_U_FFF_DD2_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_U_FFF_DD2_reg)=data)
#define  get_DVBC_OPT_U_FFF_DD2_reg                                              (*((volatile unsigned int*)DVBC_OPT_U_FFF_DD2_reg))
#define  DVBC_OPT_U_FFF_DD2_opt_u_fbf_dd1_shift                                  (5)
#define  DVBC_OPT_U_FFF_DD2_opt_u_fbf_dd0_shift                                  (3)
#define  DVBC_OPT_U_FFF_DD2_opt_u_fff_dd2_shift                                  (0)
#define  DVBC_OPT_U_FFF_DD2_opt_u_fbf_dd1_mask                                   (0x00000060)
#define  DVBC_OPT_U_FFF_DD2_opt_u_fbf_dd0_mask                                   (0x00000018)
#define  DVBC_OPT_U_FFF_DD2_opt_u_fff_dd2_mask                                   (0x00000007)
#define  DVBC_OPT_U_FFF_DD2_opt_u_fbf_dd1(data)                                  (0x00000060&((data)<<5))
#define  DVBC_OPT_U_FFF_DD2_opt_u_fbf_dd0(data)                                  (0x00000018&((data)<<3))
#define  DVBC_OPT_U_FFF_DD2_opt_u_fff_dd2(data)                                  (0x00000007&(data))
#define  DVBC_OPT_U_FFF_DD2_get_opt_u_fbf_dd1(data)                              ((0x00000060&(data))>>5)
#define  DVBC_OPT_U_FFF_DD2_get_opt_u_fbf_dd0(data)                              ((0x00000018&(data))>>3)
#define  DVBC_OPT_U_FFF_DD2_get_opt_u_fff_dd2(data)                              (0x00000007&(data))

#define  DVBC_OPT_U_FBF_DD2                                                      0x180E8508
#define  DVBC_OPT_U_FBF_DD2_reg_addr                                             "0xB80E8508"
#define  DVBC_OPT_U_FBF_DD2_reg                                                  0xB80E8508
#define  DVBC_OPT_U_FBF_DD2_inst_addr                                            "0x008E"
#define  set_DVBC_OPT_U_FBF_DD2_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_U_FBF_DD2_reg)=data)
#define  get_DVBC_OPT_U_FBF_DD2_reg                                              (*((volatile unsigned int*)DVBC_OPT_U_FBF_DD2_reg))
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf2_dd2_shift                                 (6)
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf2_dd1_shift                                 (4)
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf2_dd0_shift                                 (2)
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf_dd2_shift                                  (0)
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf2_dd2_mask                                  (0x000000C0)
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf2_dd1_mask                                  (0x00000030)
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf2_dd0_mask                                  (0x0000000C)
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf_dd2_mask                                   (0x00000003)
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf2_dd2(data)                                 (0x000000C0&((data)<<6))
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf2_dd1(data)                                 (0x00000030&((data)<<4))
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf2_dd0(data)                                 (0x0000000C&((data)<<2))
#define  DVBC_OPT_U_FBF_DD2_opt_u_fbf_dd2(data)                                  (0x00000003&(data))
#define  DVBC_OPT_U_FBF_DD2_get_opt_u_fbf2_dd2(data)                             ((0x000000C0&(data))>>6)
#define  DVBC_OPT_U_FBF_DD2_get_opt_u_fbf2_dd1(data)                             ((0x00000030&(data))>>4)
#define  DVBC_OPT_U_FBF_DD2_get_opt_u_fbf2_dd0(data)                             ((0x0000000C&(data))>>2)
#define  DVBC_OPT_U_FBF_DD2_get_opt_u_fbf_dd2(data)                              (0x00000003&(data))

#define  DVBC_OPT_EQ_UPD_PERIOD_FFF                                              0x180E850C
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_reg_addr                                     "0xB80E850C"
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_reg                                          0xB80E850C
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_inst_addr                                    "0x008F"
#define  set_DVBC_OPT_EQ_UPD_PERIOD_FFF_reg(data)                                (*((volatile unsigned int*)DVBC_OPT_EQ_UPD_PERIOD_FFF_reg)=data)
#define  get_DVBC_OPT_EQ_UPD_PERIOD_FFF_reg                                      (*((volatile unsigned int*)DVBC_OPT_EQ_UPD_PERIOD_FFF_reg))
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_opt_eq_upd_period_fff_en_shift               (7)
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_opt_eq_upd_period_fff_shift                  (0)
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_opt_eq_upd_period_fff_en_mask                (0x00000080)
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_opt_eq_upd_period_fff_mask                   (0x0000007F)
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_opt_eq_upd_period_fff_en(data)               (0x00000080&((data)<<7))
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_opt_eq_upd_period_fff(data)                  (0x0000007F&(data))
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_get_opt_eq_upd_period_fff_en(data)           ((0x00000080&(data))>>7)
#define  DVBC_OPT_EQ_UPD_PERIOD_FFF_get_opt_eq_upd_period_fff(data)              (0x0000007F&(data))

#define  DVBC_OPT_EQ_UPD_PERIOD_FBF                                              0x180E8510
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_reg_addr                                     "0xB80E8510"
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_reg                                          0xB80E8510
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_inst_addr                                    "0x0090"
#define  set_DVBC_OPT_EQ_UPD_PERIOD_FBF_reg(data)                                (*((volatile unsigned int*)DVBC_OPT_EQ_UPD_PERIOD_FBF_reg)=data)
#define  get_DVBC_OPT_EQ_UPD_PERIOD_FBF_reg                                      (*((volatile unsigned int*)DVBC_OPT_EQ_UPD_PERIOD_FBF_reg))
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_opt_eq_upd_period_fbf_en_shift               (7)
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_opt_eq_upd_period_fbf_shift                  (0)
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_opt_eq_upd_period_fbf_en_mask                (0x00000080)
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_opt_eq_upd_period_fbf_mask                   (0x0000007F)
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_opt_eq_upd_period_fbf_en(data)               (0x00000080&((data)<<7))
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_opt_eq_upd_period_fbf(data)                  (0x0000007F&(data))
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_get_opt_eq_upd_period_fbf_en(data)           ((0x00000080&(data))>>7)
#define  DVBC_OPT_EQ_UPD_PERIOD_FBF_get_opt_eq_upd_period_fbf(data)              (0x0000007F&(data))

#define  DVBC_OPT_MAX_ERR_PERIOD                                                 0x180E8514
#define  DVBC_OPT_MAX_ERR_PERIOD_reg_addr                                        "0xB80E8514"
#define  DVBC_OPT_MAX_ERR_PERIOD_reg                                             0xB80E8514
#define  DVBC_OPT_MAX_ERR_PERIOD_inst_addr                                       "0x0091"
#define  set_DVBC_OPT_MAX_ERR_PERIOD_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_MAX_ERR_PERIOD_reg)=data)
#define  get_DVBC_OPT_MAX_ERR_PERIOD_reg                                         (*((volatile unsigned int*)DVBC_OPT_MAX_ERR_PERIOD_reg))
#define  DVBC_OPT_MAX_ERR_PERIOD_opt_max_err_period_shift                        (0)
#define  DVBC_OPT_MAX_ERR_PERIOD_opt_max_err_period_mask                         (0x000000FF)
#define  DVBC_OPT_MAX_ERR_PERIOD_opt_max_err_period(data)                        (0x000000FF&(data))
#define  DVBC_OPT_MAX_ERR_PERIOD_get_opt_max_err_period(data)                    (0x000000FF&(data))

#define  DVBC_OPT_CLIP_MO_PERIOD                                                 0x180E851C
#define  DVBC_OPT_CLIP_MO_PERIOD_reg_addr                                        "0xB80E851C"
#define  DVBC_OPT_CLIP_MO_PERIOD_reg                                             0xB80E851C
#define  DVBC_OPT_CLIP_MO_PERIOD_inst_addr                                       "0x0092"
#define  set_DVBC_OPT_CLIP_MO_PERIOD_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_CLIP_MO_PERIOD_reg)=data)
#define  get_DVBC_OPT_CLIP_MO_PERIOD_reg                                         (*((volatile unsigned int*)DVBC_OPT_CLIP_MO_PERIOD_reg))
#define  DVBC_OPT_CLIP_MO_PERIOD_opt_clip_mo_period_shift                        (0)
#define  DVBC_OPT_CLIP_MO_PERIOD_opt_clip_mo_period_mask                         (0x000000FF)
#define  DVBC_OPT_CLIP_MO_PERIOD_opt_clip_mo_period(data)                        (0x000000FF&(data))
#define  DVBC_OPT_CLIP_MO_PERIOD_get_opt_clip_mo_period(data)                    (0x000000FF&(data))

#define  DVBC_OPT_DB_SIGNAL_SEL1                                                 0x180E8520
#define  DVBC_OPT_DB_SIGNAL_SEL1_reg_addr                                        "0xB80E8520"
#define  DVBC_OPT_DB_SIGNAL_SEL1_reg                                             0xB80E8520
#define  DVBC_OPT_DB_SIGNAL_SEL1_inst_addr                                       "0x0093"
#define  set_DVBC_OPT_DB_SIGNAL_SEL1_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_SEL1_reg)=data)
#define  get_DVBC_OPT_DB_SIGNAL_SEL1_reg                                         (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_SEL1_reg))
#define  DVBC_OPT_DB_SIGNAL_SEL1_opt_db_signal_sel1_shift                        (0)
#define  DVBC_OPT_DB_SIGNAL_SEL1_opt_db_signal_sel1_mask                         (0x000000FF)
#define  DVBC_OPT_DB_SIGNAL_SEL1_opt_db_signal_sel1(data)                        (0x000000FF&(data))
#define  DVBC_OPT_DB_SIGNAL_SEL1_get_opt_db_signal_sel1(data)                    (0x000000FF&(data))

#define  DVBC_OPT_DB_SIGNAL_SEL2                                                 0x180E8524
#define  DVBC_OPT_DB_SIGNAL_SEL2_reg_addr                                        "0xB80E8524"
#define  DVBC_OPT_DB_SIGNAL_SEL2_reg                                             0xB80E8524
#define  DVBC_OPT_DB_SIGNAL_SEL2_inst_addr                                       "0x0094"
#define  set_DVBC_OPT_DB_SIGNAL_SEL2_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_SEL2_reg)=data)
#define  get_DVBC_OPT_DB_SIGNAL_SEL2_reg                                         (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_SEL2_reg))
#define  DVBC_OPT_DB_SIGNAL_SEL2_opt_db_signal_sel2_shift                        (0)
#define  DVBC_OPT_DB_SIGNAL_SEL2_opt_db_signal_sel2_mask                         (0x000000FF)
#define  DVBC_OPT_DB_SIGNAL_SEL2_opt_db_signal_sel2(data)                        (0x000000FF&(data))
#define  DVBC_OPT_DB_SIGNAL_SEL2_get_opt_db_signal_sel2(data)                    (0x000000FF&(data))

#define  DVBC_OPT_DB_TST_ENA_SEL                                                 0x180E8528
#define  DVBC_OPT_DB_TST_ENA_SEL_reg_addr                                        "0xB80E8528"
#define  DVBC_OPT_DB_TST_ENA_SEL_reg                                             0xB80E8528
#define  DVBC_OPT_DB_TST_ENA_SEL_inst_addr                                       "0x0095"
#define  set_DVBC_OPT_DB_TST_ENA_SEL_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_DB_TST_ENA_SEL_reg)=data)
#define  get_DVBC_OPT_DB_TST_ENA_SEL_reg                                         (*((volatile unsigned int*)DVBC_OPT_DB_TST_ENA_SEL_reg))
#define  DVBC_OPT_DB_TST_ENA_SEL_opt_db_tst_ena_sel_shift                        (0)
#define  DVBC_OPT_DB_TST_ENA_SEL_opt_db_tst_ena_sel_mask                         (0x00000007)
#define  DVBC_OPT_DB_TST_ENA_SEL_opt_db_tst_ena_sel(data)                        (0x00000007&(data))
#define  DVBC_OPT_DB_TST_ENA_SEL_get_opt_db_tst_ena_sel(data)                    (0x00000007&(data))

#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1                                            0x180E852C
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_reg_addr                                   "0xB80E852C"
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_reg                                        0xB80E852C
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_inst_addr                                  "0x0096"
#define  set_DVBC_OPT_DB_SIGNAL_GATE_SEL1_reg(data)                              (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_GATE_SEL1_reg)=data)
#define  get_DVBC_OPT_DB_SIGNAL_GATE_SEL1_reg                                    (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_GATE_SEL1_reg))
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_opt_db_signal_gate_sel1_7_0_shift          (0)
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_opt_db_signal_gate_sel1_7_0_mask           (0x000000FF)
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_opt_db_signal_gate_sel1_7_0(data)          (0x000000FF&(data))
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_get_opt_db_signal_gate_sel1_7_0(data)      (0x000000FF&(data))

#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_1                                          0x180E8530
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_reg_addr                                 "0xB80E8530"
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_reg                                      0xB80E8530
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_inst_addr                                "0x0097"
#define  set_DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_reg(data)                            (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_reg)=data)
#define  get_DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_reg                                  (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_reg))
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_opt_db_signal_gate_sel1_8_shift          (0)
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_opt_db_signal_gate_sel1_8_mask           (0x00000001)
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_opt_db_signal_gate_sel1_8(data)          (0x00000001&(data))
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL1_1_get_opt_db_signal_gate_sel1_8(data)      (0x00000001&(data))

#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2                                            0x180E8534
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_reg_addr                                   "0xB80E8534"
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_reg                                        0xB80E8534
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_inst_addr                                  "0x0098"
#define  set_DVBC_OPT_DB_SIGNAL_GATE_SEL2_reg(data)                              (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_GATE_SEL2_reg)=data)
#define  get_DVBC_OPT_DB_SIGNAL_GATE_SEL2_reg                                    (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_GATE_SEL2_reg))
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_opt_db_signal_gate_sel2_7_0_shift          (0)
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_opt_db_signal_gate_sel2_7_0_mask           (0x000000FF)
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_opt_db_signal_gate_sel2_7_0(data)          (0x000000FF&(data))
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_get_opt_db_signal_gate_sel2_7_0(data)      (0x000000FF&(data))

#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_1                                          0x180E8538
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_reg_addr                                 "0xB80E8538"
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_reg                                      0xB80E8538
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_inst_addr                                "0x0099"
#define  set_DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_reg(data)                            (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_reg)=data)
#define  get_DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_reg                                  (*((volatile unsigned int*)DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_reg))
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_opt_db_signal_gate_sel2_8_shift          (0)
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_opt_db_signal_gate_sel2_8_mask           (0x00000001)
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_opt_db_signal_gate_sel2_8(data)          (0x00000001&(data))
#define  DVBC_OPT_DB_SIGNAL_GATE_SEL2_1_get_opt_db_signal_gate_sel2_8(data)      (0x00000001&(data))

#define  DVBC_OPT_DB_FSM_STATE1                                                  0x180E853C
#define  DVBC_OPT_DB_FSM_STATE1_reg_addr                                         "0xB80E853C"
#define  DVBC_OPT_DB_FSM_STATE1_reg                                              0xB80E853C
#define  DVBC_OPT_DB_FSM_STATE1_inst_addr                                        "0x009A"
#define  set_DVBC_OPT_DB_FSM_STATE1_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_DB_FSM_STATE1_reg)=data)
#define  get_DVBC_OPT_DB_FSM_STATE1_reg                                          (*((volatile unsigned int*)DVBC_OPT_DB_FSM_STATE1_reg))
#define  DVBC_OPT_DB_FSM_STATE1_opt_db_fsm_state1_shift                          (0)
#define  DVBC_OPT_DB_FSM_STATE1_opt_db_fsm_state1_mask                           (0x0000000F)
#define  DVBC_OPT_DB_FSM_STATE1_opt_db_fsm_state1(data)                          (0x0000000F&(data))
#define  DVBC_OPT_DB_FSM_STATE1_get_opt_db_fsm_state1(data)                      (0x0000000F&(data))

#define  DVBC_OPT_DB_TR_LD_TH1                                                   0x180E8540
#define  DVBC_OPT_DB_TR_LD_TH1_reg_addr                                          "0xB80E8540"
#define  DVBC_OPT_DB_TR_LD_TH1_reg                                               0xB80E8540
#define  DVBC_OPT_DB_TR_LD_TH1_inst_addr                                         "0x009B"
#define  set_DVBC_OPT_DB_TR_LD_TH1_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_DB_TR_LD_TH1_reg)=data)
#define  get_DVBC_OPT_DB_TR_LD_TH1_reg                                           (*((volatile unsigned int*)DVBC_OPT_DB_TR_LD_TH1_reg))
#define  DVBC_OPT_DB_TR_LD_TH1_opt_db_cr_ld_th1_shift                            (4)
#define  DVBC_OPT_DB_TR_LD_TH1_opt_db_tr_ld_th1_shift                            (0)
#define  DVBC_OPT_DB_TR_LD_TH1_opt_db_cr_ld_th1_mask                             (0x000000F0)
#define  DVBC_OPT_DB_TR_LD_TH1_opt_db_tr_ld_th1_mask                             (0x0000000F)
#define  DVBC_OPT_DB_TR_LD_TH1_opt_db_cr_ld_th1(data)                            (0x000000F0&((data)<<4))
#define  DVBC_OPT_DB_TR_LD_TH1_opt_db_tr_ld_th1(data)                            (0x0000000F&(data))
#define  DVBC_OPT_DB_TR_LD_TH1_get_opt_db_cr_ld_th1(data)                        ((0x000000F0&(data))>>4)
#define  DVBC_OPT_DB_TR_LD_TH1_get_opt_db_tr_ld_th1(data)                        (0x0000000F&(data))

#define  DVBC_OPT_DB_MSE_TH1                                                     0x180E8544
#define  DVBC_OPT_DB_MSE_TH1_reg_addr                                            "0xB80E8544"
#define  DVBC_OPT_DB_MSE_TH1_reg                                                 0xB80E8544
#define  DVBC_OPT_DB_MSE_TH1_inst_addr                                           "0x009C"
#define  set_DVBC_OPT_DB_MSE_TH1_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_DB_MSE_TH1_reg)=data)
#define  get_DVBC_OPT_DB_MSE_TH1_reg                                             (*((volatile unsigned int*)DVBC_OPT_DB_MSE_TH1_reg))
#define  DVBC_OPT_DB_MSE_TH1_opt_db_mse_th1_shift                                (0)
#define  DVBC_OPT_DB_MSE_TH1_opt_db_mse_th1_mask                                 (0x000000FF)
#define  DVBC_OPT_DB_MSE_TH1_opt_db_mse_th1(data)                                (0x000000FF&(data))
#define  DVBC_OPT_DB_MSE_TH1_get_opt_db_mse_th1(data)                            (0x000000FF&(data))

#define  DVBC_DB_COND1_EN1                                                       0x180E8548
#define  DVBC_DB_COND1_EN1_reg_addr                                              "0xB80E8548"
#define  DVBC_DB_COND1_EN1_reg                                                   0xB80E8548
#define  DVBC_DB_COND1_EN1_inst_addr                                             "0x009D"
#define  set_DVBC_DB_COND1_EN1_reg(data)                                         (*((volatile unsigned int*)DVBC_DB_COND1_EN1_reg)=data)
#define  get_DVBC_DB_COND1_EN1_reg                                               (*((volatile unsigned int*)DVBC_DB_COND1_EN1_reg))
#define  DVBC_DB_COND1_EN1_opt_db_cond_and_or1_shift                             (7)
#define  DVBC_DB_COND1_EN1_db_cond7_en1_shift                                    (6)
#define  DVBC_DB_COND1_EN1_db_cond6_en1_shift                                    (5)
#define  DVBC_DB_COND1_EN1_db_cond5_en1_shift                                    (4)
#define  DVBC_DB_COND1_EN1_db_cond4_en1_shift                                    (3)
#define  DVBC_DB_COND1_EN1_db_cond3_en1_shift                                    (2)
#define  DVBC_DB_COND1_EN1_db_cond2_en1_shift                                    (1)
#define  DVBC_DB_COND1_EN1_db_cond1_en1_shift                                    (0)
#define  DVBC_DB_COND1_EN1_opt_db_cond_and_or1_mask                              (0x00000080)
#define  DVBC_DB_COND1_EN1_db_cond7_en1_mask                                     (0x00000040)
#define  DVBC_DB_COND1_EN1_db_cond6_en1_mask                                     (0x00000020)
#define  DVBC_DB_COND1_EN1_db_cond5_en1_mask                                     (0x00000010)
#define  DVBC_DB_COND1_EN1_db_cond4_en1_mask                                     (0x00000008)
#define  DVBC_DB_COND1_EN1_db_cond3_en1_mask                                     (0x00000004)
#define  DVBC_DB_COND1_EN1_db_cond2_en1_mask                                     (0x00000002)
#define  DVBC_DB_COND1_EN1_db_cond1_en1_mask                                     (0x00000001)
#define  DVBC_DB_COND1_EN1_opt_db_cond_and_or1(data)                             (0x00000080&((data)<<7))
#define  DVBC_DB_COND1_EN1_db_cond7_en1(data)                                    (0x00000040&((data)<<6))
#define  DVBC_DB_COND1_EN1_db_cond6_en1(data)                                    (0x00000020&((data)<<5))
#define  DVBC_DB_COND1_EN1_db_cond5_en1(data)                                    (0x00000010&((data)<<4))
#define  DVBC_DB_COND1_EN1_db_cond4_en1(data)                                    (0x00000008&((data)<<3))
#define  DVBC_DB_COND1_EN1_db_cond3_en1(data)                                    (0x00000004&((data)<<2))
#define  DVBC_DB_COND1_EN1_db_cond2_en1(data)                                    (0x00000002&((data)<<1))
#define  DVBC_DB_COND1_EN1_db_cond1_en1(data)                                    (0x00000001&(data))
#define  DVBC_DB_COND1_EN1_get_opt_db_cond_and_or1(data)                         ((0x00000080&(data))>>7)
#define  DVBC_DB_COND1_EN1_get_db_cond7_en1(data)                                ((0x00000040&(data))>>6)
#define  DVBC_DB_COND1_EN1_get_db_cond6_en1(data)                                ((0x00000020&(data))>>5)
#define  DVBC_DB_COND1_EN1_get_db_cond5_en1(data)                                ((0x00000010&(data))>>4)
#define  DVBC_DB_COND1_EN1_get_db_cond4_en1(data)                                ((0x00000008&(data))>>3)
#define  DVBC_DB_COND1_EN1_get_db_cond3_en1(data)                                ((0x00000004&(data))>>2)
#define  DVBC_DB_COND1_EN1_get_db_cond2_en1(data)                                ((0x00000002&(data))>>1)
#define  DVBC_DB_COND1_EN1_get_db_cond1_en1(data)                                (0x00000001&(data))

#define  DVBC_OPT_DB_TR_LD_TH2                                                   0x180E854C
#define  DVBC_OPT_DB_TR_LD_TH2_reg_addr                                          "0xB80E854C"
#define  DVBC_OPT_DB_TR_LD_TH2_reg                                               0xB80E854C
#define  DVBC_OPT_DB_TR_LD_TH2_inst_addr                                         "0x009E"
#define  set_DVBC_OPT_DB_TR_LD_TH2_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_DB_TR_LD_TH2_reg)=data)
#define  get_DVBC_OPT_DB_TR_LD_TH2_reg                                           (*((volatile unsigned int*)DVBC_OPT_DB_TR_LD_TH2_reg))
#define  DVBC_OPT_DB_TR_LD_TH2_opt_db_cr_ld_th2_shift                            (4)
#define  DVBC_OPT_DB_TR_LD_TH2_opt_db_tr_ld_th2_shift                            (0)
#define  DVBC_OPT_DB_TR_LD_TH2_opt_db_cr_ld_th2_mask                             (0x000000F0)
#define  DVBC_OPT_DB_TR_LD_TH2_opt_db_tr_ld_th2_mask                             (0x0000000F)
#define  DVBC_OPT_DB_TR_LD_TH2_opt_db_cr_ld_th2(data)                            (0x000000F0&((data)<<4))
#define  DVBC_OPT_DB_TR_LD_TH2_opt_db_tr_ld_th2(data)                            (0x0000000F&(data))
#define  DVBC_OPT_DB_TR_LD_TH2_get_opt_db_cr_ld_th2(data)                        ((0x000000F0&(data))>>4)
#define  DVBC_OPT_DB_TR_LD_TH2_get_opt_db_tr_ld_th2(data)                        (0x0000000F&(data))

#define  DVBC_OPT_DB_MSE_TH2                                                     0x180E8550
#define  DVBC_OPT_DB_MSE_TH2_reg_addr                                            "0xB80E8550"
#define  DVBC_OPT_DB_MSE_TH2_reg                                                 0xB80E8550
#define  DVBC_OPT_DB_MSE_TH2_inst_addr                                           "0x009F"
#define  set_DVBC_OPT_DB_MSE_TH2_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_DB_MSE_TH2_reg)=data)
#define  get_DVBC_OPT_DB_MSE_TH2_reg                                             (*((volatile unsigned int*)DVBC_OPT_DB_MSE_TH2_reg))
#define  DVBC_OPT_DB_MSE_TH2_opt_db_mse_th2_shift                                (0)
#define  DVBC_OPT_DB_MSE_TH2_opt_db_mse_th2_mask                                 (0x000000FF)
#define  DVBC_OPT_DB_MSE_TH2_opt_db_mse_th2(data)                                (0x000000FF&(data))
#define  DVBC_OPT_DB_MSE_TH2_get_opt_db_mse_th2(data)                            (0x000000FF&(data))

#define  DVBC_OPT_DB_FSM_STATE2                                                  0x180E8554
#define  DVBC_OPT_DB_FSM_STATE2_reg_addr                                         "0xB80E8554"
#define  DVBC_OPT_DB_FSM_STATE2_reg                                              0xB80E8554
#define  DVBC_OPT_DB_FSM_STATE2_inst_addr                                        "0x00A0"
#define  set_DVBC_OPT_DB_FSM_STATE2_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_DB_FSM_STATE2_reg)=data)
#define  get_DVBC_OPT_DB_FSM_STATE2_reg                                          (*((volatile unsigned int*)DVBC_OPT_DB_FSM_STATE2_reg))
#define  DVBC_OPT_DB_FSM_STATE2_opt_db_fsm_state2_shift                          (0)
#define  DVBC_OPT_DB_FSM_STATE2_opt_db_fsm_state2_mask                           (0x0000000F)
#define  DVBC_OPT_DB_FSM_STATE2_opt_db_fsm_state2(data)                          (0x0000000F&(data))
#define  DVBC_OPT_DB_FSM_STATE2_get_opt_db_fsm_state2(data)                      (0x0000000F&(data))

#define  DVBC_DB_COND1_EN2                                                       0x180E8558
#define  DVBC_DB_COND1_EN2_reg_addr                                              "0xB80E8558"
#define  DVBC_DB_COND1_EN2_reg                                                   0xB80E8558
#define  DVBC_DB_COND1_EN2_inst_addr                                             "0x00A1"
#define  set_DVBC_DB_COND1_EN2_reg(data)                                         (*((volatile unsigned int*)DVBC_DB_COND1_EN2_reg)=data)
#define  get_DVBC_DB_COND1_EN2_reg                                               (*((volatile unsigned int*)DVBC_DB_COND1_EN2_reg))
#define  DVBC_DB_COND1_EN2_opt_db_cond_and_or2_shift                             (7)
#define  DVBC_DB_COND1_EN2_db_cond7_en2_shift                                    (6)
#define  DVBC_DB_COND1_EN2_db_cond6_en2_shift                                    (5)
#define  DVBC_DB_COND1_EN2_db_cond5_en2_shift                                    (4)
#define  DVBC_DB_COND1_EN2_db_cond4_en2_shift                                    (3)
#define  DVBC_DB_COND1_EN2_db_cond3_en2_shift                                    (2)
#define  DVBC_DB_COND1_EN2_db_cond2_en2_shift                                    (1)
#define  DVBC_DB_COND1_EN2_db_cond1_en2_shift                                    (0)
#define  DVBC_DB_COND1_EN2_opt_db_cond_and_or2_mask                              (0x00000080)
#define  DVBC_DB_COND1_EN2_db_cond7_en2_mask                                     (0x00000040)
#define  DVBC_DB_COND1_EN2_db_cond6_en2_mask                                     (0x00000020)
#define  DVBC_DB_COND1_EN2_db_cond5_en2_mask                                     (0x00000010)
#define  DVBC_DB_COND1_EN2_db_cond4_en2_mask                                     (0x00000008)
#define  DVBC_DB_COND1_EN2_db_cond3_en2_mask                                     (0x00000004)
#define  DVBC_DB_COND1_EN2_db_cond2_en2_mask                                     (0x00000002)
#define  DVBC_DB_COND1_EN2_db_cond1_en2_mask                                     (0x00000001)
#define  DVBC_DB_COND1_EN2_opt_db_cond_and_or2(data)                             (0x00000080&((data)<<7))
#define  DVBC_DB_COND1_EN2_db_cond7_en2(data)                                    (0x00000040&((data)<<6))
#define  DVBC_DB_COND1_EN2_db_cond6_en2(data)                                    (0x00000020&((data)<<5))
#define  DVBC_DB_COND1_EN2_db_cond5_en2(data)                                    (0x00000010&((data)<<4))
#define  DVBC_DB_COND1_EN2_db_cond4_en2(data)                                    (0x00000008&((data)<<3))
#define  DVBC_DB_COND1_EN2_db_cond3_en2(data)                                    (0x00000004&((data)<<2))
#define  DVBC_DB_COND1_EN2_db_cond2_en2(data)                                    (0x00000002&((data)<<1))
#define  DVBC_DB_COND1_EN2_db_cond1_en2(data)                                    (0x00000001&(data))
#define  DVBC_DB_COND1_EN2_get_opt_db_cond_and_or2(data)                         ((0x00000080&(data))>>7)
#define  DVBC_DB_COND1_EN2_get_db_cond7_en2(data)                                ((0x00000040&(data))>>6)
#define  DVBC_DB_COND1_EN2_get_db_cond6_en2(data)                                ((0x00000020&(data))>>5)
#define  DVBC_DB_COND1_EN2_get_db_cond5_en2(data)                                ((0x00000010&(data))>>4)
#define  DVBC_DB_COND1_EN2_get_db_cond4_en2(data)                                ((0x00000008&(data))>>3)
#define  DVBC_DB_COND1_EN2_get_db_cond3_en2(data)                                ((0x00000004&(data))>>2)
#define  DVBC_DB_COND1_EN2_get_db_cond2_en2(data)                                ((0x00000002&(data))>>1)
#define  DVBC_DB_COND1_EN2_get_db_cond1_en2(data)                                (0x00000001&(data))

#define  DVBC_RXMF_WR_STB                                                        0x180E855C
#define  DVBC_RXMF_WR_STB_reg_addr                                               "0xB80E855C"
#define  DVBC_RXMF_WR_STB_reg                                                    0xB80E855C
#define  DVBC_RXMF_WR_STB_inst_addr                                              "0x00A2"
#define  set_DVBC_RXMF_WR_STB_reg(data)                                          (*((volatile unsigned int*)DVBC_RXMF_WR_STB_reg)=data)
#define  get_DVBC_RXMF_WR_STB_reg                                                (*((volatile unsigned int*)DVBC_RXMF_WR_STB_reg))
#define  DVBC_RXMF_WR_STB_rxmf_coeff_2_0_shift                                   (5)
#define  DVBC_RXMF_WR_STB_rxmf_sel_shift                                         (1)
#define  DVBC_RXMF_WR_STB_rxmf_wr_stb_shift                                      (0)
#define  DVBC_RXMF_WR_STB_rxmf_coeff_2_0_mask                                    (0x000000E0)
#define  DVBC_RXMF_WR_STB_rxmf_sel_mask                                          (0x0000001E)
#define  DVBC_RXMF_WR_STB_rxmf_wr_stb_mask                                       (0x00000001)
#define  DVBC_RXMF_WR_STB_rxmf_coeff_2_0(data)                                   (0x000000E0&((data)<<5))
#define  DVBC_RXMF_WR_STB_rxmf_sel(data)                                         (0x0000001E&((data)<<1))
#define  DVBC_RXMF_WR_STB_rxmf_wr_stb(data)                                      (0x00000001&(data))
#define  DVBC_RXMF_WR_STB_get_rxmf_coeff_2_0(data)                               ((0x000000E0&(data))>>5)
#define  DVBC_RXMF_WR_STB_get_rxmf_sel(data)                                     ((0x0000001E&(data))>>1)
#define  DVBC_RXMF_WR_STB_get_rxmf_wr_stb(data)                                  (0x00000001&(data))

#define  DVBC_RXMF_WR_STB_1                                                      0x180E8560
#define  DVBC_RXMF_WR_STB_1_reg_addr                                             "0xB80E8560"
#define  DVBC_RXMF_WR_STB_1_reg                                                  0xB80E8560
#define  DVBC_RXMF_WR_STB_1_inst_addr                                            "0x00A3"
#define  set_DVBC_RXMF_WR_STB_1_reg(data)                                        (*((volatile unsigned int*)DVBC_RXMF_WR_STB_1_reg)=data)
#define  get_DVBC_RXMF_WR_STB_1_reg                                              (*((volatile unsigned int*)DVBC_RXMF_WR_STB_1_reg))
#define  DVBC_RXMF_WR_STB_1_rxmf_coeff_r_shift                                   (8)
#define  DVBC_RXMF_WR_STB_1_rxmf_coeff_9_3_shift                                 (0)
#define  DVBC_RXMF_WR_STB_1_rxmf_coeff_r_mask                                    (0x0003FF00)
#define  DVBC_RXMF_WR_STB_1_rxmf_coeff_9_3_mask                                  (0x0000007F)
#define  DVBC_RXMF_WR_STB_1_rxmf_coeff_r(data)                                   (0x0003FF00&((data)<<8))
#define  DVBC_RXMF_WR_STB_1_rxmf_coeff_9_3(data)                                 (0x0000007F&(data))
#define  DVBC_RXMF_WR_STB_1_get_rxmf_coeff_r(data)                               ((0x0003FF00&(data))>>8)
#define  DVBC_RXMF_WR_STB_1_get_rxmf_coeff_9_3(data)                             (0x0000007F&(data))

#define  DVBC_INTERP_WR_STB                                                      0x180E8564
#define  DVBC_INTERP_WR_STB_reg_addr                                             "0xB80E8564"
#define  DVBC_INTERP_WR_STB_reg                                                  0xB80E8564
#define  DVBC_INTERP_WR_STB_inst_addr                                            "0x00A4"
#define  set_DVBC_INTERP_WR_STB_reg(data)                                        (*((volatile unsigned int*)DVBC_INTERP_WR_STB_reg)=data)
#define  get_DVBC_INTERP_WR_STB_reg                                              (*((volatile unsigned int*)DVBC_INTERP_WR_STB_reg))
#define  DVBC_INTERP_WR_STB_interp_coeff_1_0_shift                               (6)
#define  DVBC_INTERP_WR_STB_interp_sel_shift                                     (1)
#define  DVBC_INTERP_WR_STB_interp_wr_stb_shift                                  (0)
#define  DVBC_INTERP_WR_STB_interp_coeff_1_0_mask                                (0x000000C0)
#define  DVBC_INTERP_WR_STB_interp_sel_mask                                      (0x0000003E)
#define  DVBC_INTERP_WR_STB_interp_wr_stb_mask                                   (0x00000001)
#define  DVBC_INTERP_WR_STB_interp_coeff_1_0(data)                               (0x000000C0&((data)<<6))
#define  DVBC_INTERP_WR_STB_interp_sel(data)                                     (0x0000003E&((data)<<1))
#define  DVBC_INTERP_WR_STB_interp_wr_stb(data)                                  (0x00000001&(data))
#define  DVBC_INTERP_WR_STB_get_interp_coeff_1_0(data)                           ((0x000000C0&(data))>>6)
#define  DVBC_INTERP_WR_STB_get_interp_sel(data)                                 ((0x0000003E&(data))>>1)
#define  DVBC_INTERP_WR_STB_get_interp_wr_stb(data)                              (0x00000001&(data))

#define  DVBC_INTERP_WR_STB_1                                                    0x180E8568
#define  DVBC_INTERP_WR_STB_1_reg_addr                                           "0xB80E8568"
#define  DVBC_INTERP_WR_STB_1_reg                                                0xB80E8568
#define  DVBC_INTERP_WR_STB_1_inst_addr                                          "0x00A5"
#define  set_DVBC_INTERP_WR_STB_1_reg(data)                                      (*((volatile unsigned int*)DVBC_INTERP_WR_STB_1_reg)=data)
#define  get_DVBC_INTERP_WR_STB_1_reg                                            (*((volatile unsigned int*)DVBC_INTERP_WR_STB_1_reg))
#define  DVBC_INTERP_WR_STB_1_interp_coeff_r_shift                               (8)
#define  DVBC_INTERP_WR_STB_1_interp_coeff_9_2_shift                             (0)
#define  DVBC_INTERP_WR_STB_1_interp_coeff_r_mask                                (0x0003FF00)
#define  DVBC_INTERP_WR_STB_1_interp_coeff_9_2_mask                              (0x000000FF)
#define  DVBC_INTERP_WR_STB_1_interp_coeff_r(data)                               (0x0003FF00&((data)<<8))
#define  DVBC_INTERP_WR_STB_1_interp_coeff_9_2(data)                             (0x000000FF&(data))
#define  DVBC_INTERP_WR_STB_1_get_interp_coeff_r(data)                           ((0x0003FF00&(data))>>8)
#define  DVBC_INTERP_WR_STB_1_get_interp_coeff_9_2(data)                         (0x000000FF&(data))

#define  DVBC_DDC_WR_STB                                                         0x180E856C
#define  DVBC_DDC_WR_STB_reg_addr                                                "0xB80E856C"
#define  DVBC_DDC_WR_STB_reg                                                     0xB80E856C
#define  DVBC_DDC_WR_STB_inst_addr                                               "0x00A6"
#define  set_DVBC_DDC_WR_STB_reg(data)                                           (*((volatile unsigned int*)DVBC_DDC_WR_STB_reg)=data)
#define  get_DVBC_DDC_WR_STB_reg                                                 (*((volatile unsigned int*)DVBC_DDC_WR_STB_reg))
#define  DVBC_DDC_WR_STB_ddc_coeff_2_0_shift                                     (5)
#define  DVBC_DDC_WR_STB_ddc_sel_shift                                           (1)
#define  DVBC_DDC_WR_STB_ddc_wr_stb_shift                                        (0)
#define  DVBC_DDC_WR_STB_ddc_coeff_2_0_mask                                      (0x000000E0)
#define  DVBC_DDC_WR_STB_ddc_sel_mask                                            (0x0000001E)
#define  DVBC_DDC_WR_STB_ddc_wr_stb_mask                                         (0x00000001)
#define  DVBC_DDC_WR_STB_ddc_coeff_2_0(data)                                     (0x000000E0&((data)<<5))
#define  DVBC_DDC_WR_STB_ddc_sel(data)                                           (0x0000001E&((data)<<1))
#define  DVBC_DDC_WR_STB_ddc_wr_stb(data)                                        (0x00000001&(data))
#define  DVBC_DDC_WR_STB_get_ddc_coeff_2_0(data)                                 ((0x000000E0&(data))>>5)
#define  DVBC_DDC_WR_STB_get_ddc_sel(data)                                       ((0x0000001E&(data))>>1)
#define  DVBC_DDC_WR_STB_get_ddc_wr_stb(data)                                    (0x00000001&(data))

#define  DVBC_DDC_WR_STB_1                                                       0x180E8570
#define  DVBC_DDC_WR_STB_1_reg_addr                                              "0xB80E8570"
#define  DVBC_DDC_WR_STB_1_reg                                                   0xB80E8570
#define  DVBC_DDC_WR_STB_1_inst_addr                                             "0x00A7"
#define  set_DVBC_DDC_WR_STB_1_reg(data)                                         (*((volatile unsigned int*)DVBC_DDC_WR_STB_1_reg)=data)
#define  get_DVBC_DDC_WR_STB_1_reg                                               (*((volatile unsigned int*)DVBC_DDC_WR_STB_1_reg))
#define  DVBC_DDC_WR_STB_1_ddc_coeff_r_shift                                     (8)
#define  DVBC_DDC_WR_STB_1_ddc_coeff_9_3_shift                                   (0)
#define  DVBC_DDC_WR_STB_1_ddc_coeff_r_mask                                      (0x0003FF00)
#define  DVBC_DDC_WR_STB_1_ddc_coeff_9_3_mask                                    (0x0000007F)
#define  DVBC_DDC_WR_STB_1_ddc_coeff_r(data)                                     (0x0003FF00&((data)<<8))
#define  DVBC_DDC_WR_STB_1_ddc_coeff_9_3(data)                                   (0x0000007F&(data))
#define  DVBC_DDC_WR_STB_1_get_ddc_coeff_r(data)                                 ((0x0003FF00&(data))>>8)
#define  DVBC_DDC_WR_STB_1_get_ddc_coeff_9_3(data)                               (0x0000007F&(data))

#define  DVBC_FSM_WR_STB                                                         0x180E8574
#define  DVBC_FSM_WR_STB_reg_addr                                                "0xB80E8574"
#define  DVBC_FSM_WR_STB_reg                                                     0xB80E8574
#define  DVBC_FSM_WR_STB_inst_addr                                               "0x00A8"
#define  set_DVBC_FSM_WR_STB_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WR_STB_reg)=data)
#define  get_DVBC_FSM_WR_STB_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WR_STB_reg))
#define  DVBC_FSM_WR_STB_opt_fsm_fix_ste_en_shift                                (12)
#define  DVBC_FSM_WR_STB_opt_fsm_fix_ste_end_shift                               (8)
#define  DVBC_FSM_WR_STB_fsm_sel_shift                                           (1)
#define  DVBC_FSM_WR_STB_fsm_wr_stb_shift                                        (0)
#define  DVBC_FSM_WR_STB_opt_fsm_fix_ste_en_mask                                 (0x00001000)
#define  DVBC_FSM_WR_STB_opt_fsm_fix_ste_end_mask                                (0x00000F00)
#define  DVBC_FSM_WR_STB_fsm_sel_mask                                            (0x0000001E)
#define  DVBC_FSM_WR_STB_fsm_wr_stb_mask                                         (0x00000001)
#define  DVBC_FSM_WR_STB_opt_fsm_fix_ste_en(data)                                (0x00001000&((data)<<12))
#define  DVBC_FSM_WR_STB_opt_fsm_fix_ste_end(data)                               (0x00000F00&((data)<<8))
#define  DVBC_FSM_WR_STB_fsm_sel(data)                                           (0x0000001E&((data)<<1))
#define  DVBC_FSM_WR_STB_fsm_wr_stb(data)                                        (0x00000001&(data))
#define  DVBC_FSM_WR_STB_get_opt_fsm_fix_ste_en(data)                            ((0x00001000&(data))>>12)
#define  DVBC_FSM_WR_STB_get_opt_fsm_fix_ste_end(data)                           ((0x00000F00&(data))>>8)
#define  DVBC_FSM_WR_STB_get_fsm_sel(data)                                       ((0x0000001E&(data))>>1)
#define  DVBC_FSM_WR_STB_get_fsm_wr_stb(data)                                    (0x00000001&(data))

#define  DVBC_FSM_WORD                                                           0x180E8578
#define  DVBC_FSM_WORD_reg_addr                                                  "0xB80E8578"
#define  DVBC_FSM_WORD_reg                                                       0xB80E8578
#define  DVBC_FSM_WORD_inst_addr                                                 "0x00A9"
#define  set_DVBC_FSM_WORD_reg(data)                                             (*((volatile unsigned int*)DVBC_FSM_WORD_reg)=data)
#define  get_DVBC_FSM_WORD_reg                                                   (*((volatile unsigned int*)DVBC_FSM_WORD_reg))
#define  DVBC_FSM_WORD_fsm_word_r_7_0_shift                                      (8)
#define  DVBC_FSM_WORD_fsm_word_7_0_shift                                        (0)
#define  DVBC_FSM_WORD_fsm_word_r_7_0_mask                                       (0x0000FF00)
#define  DVBC_FSM_WORD_fsm_word_7_0_mask                                         (0x000000FF)
#define  DVBC_FSM_WORD_fsm_word_r_7_0(data)                                      (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_fsm_word_7_0(data)                                        (0x000000FF&(data))
#define  DVBC_FSM_WORD_get_fsm_word_r_7_0(data)                                  ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_get_fsm_word_7_0(data)                                    (0x000000FF&(data))

#define  DVBC_FSM_WORD_1                                                         0x180E857C
#define  DVBC_FSM_WORD_1_reg_addr                                                "0xB80E857C"
#define  DVBC_FSM_WORD_1_reg                                                     0xB80E857C
#define  DVBC_FSM_WORD_1_inst_addr                                               "0x00AA"
#define  set_DVBC_FSM_WORD_1_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WORD_1_reg)=data)
#define  get_DVBC_FSM_WORD_1_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WORD_1_reg))
#define  DVBC_FSM_WORD_1_fsm_word_r_15_8_shift                                   (8)
#define  DVBC_FSM_WORD_1_fsm_word_15_8_shift                                     (0)
#define  DVBC_FSM_WORD_1_fsm_word_r_15_8_mask                                    (0x0000FF00)
#define  DVBC_FSM_WORD_1_fsm_word_15_8_mask                                      (0x000000FF)
#define  DVBC_FSM_WORD_1_fsm_word_r_15_8(data)                                   (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_1_fsm_word_15_8(data)                                     (0x000000FF&(data))
#define  DVBC_FSM_WORD_1_get_fsm_word_r_15_8(data)                               ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_1_get_fsm_word_15_8(data)                                 (0x000000FF&(data))

#define  DVBC_FSM_WORD_2                                                         0x180E8580
#define  DVBC_FSM_WORD_2_reg_addr                                                "0xB80E8580"
#define  DVBC_FSM_WORD_2_reg                                                     0xB80E8580
#define  DVBC_FSM_WORD_2_inst_addr                                               "0x00AB"
#define  set_DVBC_FSM_WORD_2_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WORD_2_reg)=data)
#define  get_DVBC_FSM_WORD_2_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WORD_2_reg))
#define  DVBC_FSM_WORD_2_fsm_word_r_23_16_shift                                  (8)
#define  DVBC_FSM_WORD_2_fsm_word_23_16_shift                                    (0)
#define  DVBC_FSM_WORD_2_fsm_word_r_23_16_mask                                   (0x0000FF00)
#define  DVBC_FSM_WORD_2_fsm_word_23_16_mask                                     (0x000000FF)
#define  DVBC_FSM_WORD_2_fsm_word_r_23_16(data)                                  (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_2_fsm_word_23_16(data)                                    (0x000000FF&(data))
#define  DVBC_FSM_WORD_2_get_fsm_word_r_23_16(data)                              ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_2_get_fsm_word_23_16(data)                                (0x000000FF&(data))

#define  DVBC_FSM_WORD_3                                                         0x180E8584
#define  DVBC_FSM_WORD_3_reg_addr                                                "0xB80E8584"
#define  DVBC_FSM_WORD_3_reg                                                     0xB80E8584
#define  DVBC_FSM_WORD_3_inst_addr                                               "0x00AC"
#define  set_DVBC_FSM_WORD_3_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WORD_3_reg)=data)
#define  get_DVBC_FSM_WORD_3_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WORD_3_reg))
#define  DVBC_FSM_WORD_3_fsm_word_r_31_24_shift                                  (8)
#define  DVBC_FSM_WORD_3_fsm_word_31_24_shift                                    (0)
#define  DVBC_FSM_WORD_3_fsm_word_r_31_24_mask                                   (0x0000FF00)
#define  DVBC_FSM_WORD_3_fsm_word_31_24_mask                                     (0x000000FF)
#define  DVBC_FSM_WORD_3_fsm_word_r_31_24(data)                                  (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_3_fsm_word_31_24(data)                                    (0x000000FF&(data))
#define  DVBC_FSM_WORD_3_get_fsm_word_r_31_24(data)                              ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_3_get_fsm_word_31_24(data)                                (0x000000FF&(data))

#define  DVBC_FSM_WORD_4                                                         0x180E8588
#define  DVBC_FSM_WORD_4_reg_addr                                                "0xB80E8588"
#define  DVBC_FSM_WORD_4_reg                                                     0xB80E8588
#define  DVBC_FSM_WORD_4_inst_addr                                               "0x00AD"
#define  set_DVBC_FSM_WORD_4_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WORD_4_reg)=data)
#define  get_DVBC_FSM_WORD_4_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WORD_4_reg))
#define  DVBC_FSM_WORD_4_fsm_word_r_39_32_shift                                  (8)
#define  DVBC_FSM_WORD_4_fsm_word_39_32_shift                                    (0)
#define  DVBC_FSM_WORD_4_fsm_word_r_39_32_mask                                   (0x0000FF00)
#define  DVBC_FSM_WORD_4_fsm_word_39_32_mask                                     (0x000000FF)
#define  DVBC_FSM_WORD_4_fsm_word_r_39_32(data)                                  (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_4_fsm_word_39_32(data)                                    (0x000000FF&(data))
#define  DVBC_FSM_WORD_4_get_fsm_word_r_39_32(data)                              ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_4_get_fsm_word_39_32(data)                                (0x000000FF&(data))

#define  DVBC_FSM_WORD_5                                                         0x180E858C
#define  DVBC_FSM_WORD_5_reg_addr                                                "0xB80E858C"
#define  DVBC_FSM_WORD_5_reg                                                     0xB80E858C
#define  DVBC_FSM_WORD_5_inst_addr                                               "0x00AE"
#define  set_DVBC_FSM_WORD_5_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WORD_5_reg)=data)
#define  get_DVBC_FSM_WORD_5_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WORD_5_reg))
#define  DVBC_FSM_WORD_5_fsm_word_r_47_40_shift                                  (8)
#define  DVBC_FSM_WORD_5_fsm_word_47_40_shift                                    (0)
#define  DVBC_FSM_WORD_5_fsm_word_r_47_40_mask                                   (0x0000FF00)
#define  DVBC_FSM_WORD_5_fsm_word_47_40_mask                                     (0x000000FF)
#define  DVBC_FSM_WORD_5_fsm_word_r_47_40(data)                                  (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_5_fsm_word_47_40(data)                                    (0x000000FF&(data))
#define  DVBC_FSM_WORD_5_get_fsm_word_r_47_40(data)                              ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_5_get_fsm_word_47_40(data)                                (0x000000FF&(data))

#define  DVBC_FSM_WORD_6                                                         0x180E8590
#define  DVBC_FSM_WORD_6_reg_addr                                                "0xB80E8590"
#define  DVBC_FSM_WORD_6_reg                                                     0xB80E8590
#define  DVBC_FSM_WORD_6_inst_addr                                               "0x00AF"
#define  set_DVBC_FSM_WORD_6_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WORD_6_reg)=data)
#define  get_DVBC_FSM_WORD_6_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WORD_6_reg))
#define  DVBC_FSM_WORD_6_fsm_word_r_55_48_shift                                  (8)
#define  DVBC_FSM_WORD_6_fsm_word_55_48_shift                                    (0)
#define  DVBC_FSM_WORD_6_fsm_word_r_55_48_mask                                   (0x0000FF00)
#define  DVBC_FSM_WORD_6_fsm_word_55_48_mask                                     (0x000000FF)
#define  DVBC_FSM_WORD_6_fsm_word_r_55_48(data)                                  (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_6_fsm_word_55_48(data)                                    (0x000000FF&(data))
#define  DVBC_FSM_WORD_6_get_fsm_word_r_55_48(data)                              ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_6_get_fsm_word_55_48(data)                                (0x000000FF&(data))

#define  DVBC_FSM_WORD_7                                                         0x180E8594
#define  DVBC_FSM_WORD_7_reg_addr                                                "0xB80E8594"
#define  DVBC_FSM_WORD_7_reg                                                     0xB80E8594
#define  DVBC_FSM_WORD_7_inst_addr                                               "0x00B0"
#define  set_DVBC_FSM_WORD_7_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WORD_7_reg)=data)
#define  get_DVBC_FSM_WORD_7_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WORD_7_reg))
#define  DVBC_FSM_WORD_7_fsm_word_r_63_56_shift                                  (8)
#define  DVBC_FSM_WORD_7_fsm_word_63_56_shift                                    (0)
#define  DVBC_FSM_WORD_7_fsm_word_r_63_56_mask                                   (0x0000FF00)
#define  DVBC_FSM_WORD_7_fsm_word_63_56_mask                                     (0x000000FF)
#define  DVBC_FSM_WORD_7_fsm_word_r_63_56(data)                                  (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_7_fsm_word_63_56(data)                                    (0x000000FF&(data))
#define  DVBC_FSM_WORD_7_get_fsm_word_r_63_56(data)                              ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_7_get_fsm_word_63_56(data)                                (0x000000FF&(data))

#define  DVBC_FSM_WORD_8                                                         0x180E8598
#define  DVBC_FSM_WORD_8_reg_addr                                                "0xB80E8598"
#define  DVBC_FSM_WORD_8_reg                                                     0xB80E8598
#define  DVBC_FSM_WORD_8_inst_addr                                               "0x00B1"
#define  set_DVBC_FSM_WORD_8_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WORD_8_reg)=data)
#define  get_DVBC_FSM_WORD_8_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WORD_8_reg))
#define  DVBC_FSM_WORD_8_fsm_word_r_71_64_shift                                  (8)
#define  DVBC_FSM_WORD_8_fsm_word_71_64_shift                                    (0)
#define  DVBC_FSM_WORD_8_fsm_word_r_71_64_mask                                   (0x0000FF00)
#define  DVBC_FSM_WORD_8_fsm_word_71_64_mask                                     (0x000000FF)
#define  DVBC_FSM_WORD_8_fsm_word_r_71_64(data)                                  (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_8_fsm_word_71_64(data)                                    (0x000000FF&(data))
#define  DVBC_FSM_WORD_8_get_fsm_word_r_71_64(data)                              ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_8_get_fsm_word_71_64(data)                                (0x000000FF&(data))

#define  DVBC_FSM_WORD_9                                                         0x180E859C
#define  DVBC_FSM_WORD_9_reg_addr                                                "0xB80E859C"
#define  DVBC_FSM_WORD_9_reg                                                     0xB80E859C
#define  DVBC_FSM_WORD_9_inst_addr                                               "0x00B2"
#define  set_DVBC_FSM_WORD_9_reg(data)                                           (*((volatile unsigned int*)DVBC_FSM_WORD_9_reg)=data)
#define  get_DVBC_FSM_WORD_9_reg                                                 (*((volatile unsigned int*)DVBC_FSM_WORD_9_reg))
#define  DVBC_FSM_WORD_9_fsm_word_r_79_72_shift                                  (8)
#define  DVBC_FSM_WORD_9_fsm_word_79_72_shift                                    (0)
#define  DVBC_FSM_WORD_9_fsm_word_r_79_72_mask                                   (0x0000FF00)
#define  DVBC_FSM_WORD_9_fsm_word_79_72_mask                                     (0x000000FF)
#define  DVBC_FSM_WORD_9_fsm_word_r_79_72(data)                                  (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_9_fsm_word_79_72(data)                                    (0x000000FF&(data))
#define  DVBC_FSM_WORD_9_get_fsm_word_r_79_72(data)                              ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_9_get_fsm_word_79_72(data)                                (0x000000FF&(data))

#define  DVBC_FSM_WORD_10                                                        0x180E85A0
#define  DVBC_FSM_WORD_10_reg_addr                                               "0xB80E85A0"
#define  DVBC_FSM_WORD_10_reg                                                    0xB80E85A0
#define  DVBC_FSM_WORD_10_inst_addr                                              "0x00B3"
#define  set_DVBC_FSM_WORD_10_reg(data)                                          (*((volatile unsigned int*)DVBC_FSM_WORD_10_reg)=data)
#define  get_DVBC_FSM_WORD_10_reg                                                (*((volatile unsigned int*)DVBC_FSM_WORD_10_reg))
#define  DVBC_FSM_WORD_10_fsm_word_r_87_80_shift                                 (8)
#define  DVBC_FSM_WORD_10_fsm_word_87_80_shift                                   (0)
#define  DVBC_FSM_WORD_10_fsm_word_r_87_80_mask                                  (0x0000FF00)
#define  DVBC_FSM_WORD_10_fsm_word_87_80_mask                                    (0x000000FF)
#define  DVBC_FSM_WORD_10_fsm_word_r_87_80(data)                                 (0x0000FF00&((data)<<8))
#define  DVBC_FSM_WORD_10_fsm_word_87_80(data)                                   (0x000000FF&(data))
#define  DVBC_FSM_WORD_10_get_fsm_word_r_87_80(data)                             ((0x0000FF00&(data))>>8)
#define  DVBC_FSM_WORD_10_get_fsm_word_87_80(data)                               (0x000000FF&(data))

#define  DVBC_TST_OUT_STB                                                        0x180E85A4
#define  DVBC_TST_OUT_STB_reg_addr                                               "0xB80E85A4"
#define  DVBC_TST_OUT_STB_reg                                                    0xB80E85A4
#define  DVBC_TST_OUT_STB_inst_addr                                              "0x00B4"
#define  set_DVBC_TST_OUT_STB_reg(data)                                          (*((volatile unsigned int*)DVBC_TST_OUT_STB_reg)=data)
#define  get_DVBC_TST_OUT_STB_reg                                                (*((volatile unsigned int*)DVBC_TST_OUT_STB_reg))
#define  DVBC_TST_OUT_STB_tst_out_stb_shift                                      (0)
#define  DVBC_TST_OUT_STB_tst_out_stb_mask                                       (0x00000001)
#define  DVBC_TST_OUT_STB_tst_out_stb(data)                                      (0x00000001&(data))
#define  DVBC_TST_OUT_STB_get_tst_out_stb(data)                                  (0x00000001&(data))

#define  DVBC_TST_OUT1                                                           0x180E85A8
#define  DVBC_TST_OUT1_reg_addr                                                  "0xB80E85A8"
#define  DVBC_TST_OUT1_reg                                                       0xB80E85A8
#define  DVBC_TST_OUT1_inst_addr                                                 "0x00B5"
#define  set_DVBC_TST_OUT1_reg(data)                                             (*((volatile unsigned int*)DVBC_TST_OUT1_reg)=data)
#define  get_DVBC_TST_OUT1_reg                                                   (*((volatile unsigned int*)DVBC_TST_OUT1_reg))
#define  DVBC_TST_OUT1_tst_out1_7_0_shift                                        (0)
#define  DVBC_TST_OUT1_tst_out1_7_0_mask                                         (0x000000FF)
#define  DVBC_TST_OUT1_tst_out1_7_0(data)                                        (0x000000FF&(data))
#define  DVBC_TST_OUT1_get_tst_out1_7_0(data)                                    (0x000000FF&(data))

#define  DVBC_TST_OUT1_1                                                         0x180E85AC
#define  DVBC_TST_OUT1_1_reg_addr                                                "0xB80E85AC"
#define  DVBC_TST_OUT1_1_reg                                                     0xB80E85AC
#define  DVBC_TST_OUT1_1_inst_addr                                               "0x00B6"
#define  set_DVBC_TST_OUT1_1_reg(data)                                           (*((volatile unsigned int*)DVBC_TST_OUT1_1_reg)=data)
#define  get_DVBC_TST_OUT1_1_reg                                                 (*((volatile unsigned int*)DVBC_TST_OUT1_1_reg))
#define  DVBC_TST_OUT1_1_tst_out1_15_8_shift                                     (0)
#define  DVBC_TST_OUT1_1_tst_out1_15_8_mask                                      (0x000000FF)
#define  DVBC_TST_OUT1_1_tst_out1_15_8(data)                                     (0x000000FF&(data))
#define  DVBC_TST_OUT1_1_get_tst_out1_15_8(data)                                 (0x000000FF&(data))

#define  DVBC_TST_OUT2                                                           0x180E85B0
#define  DVBC_TST_OUT2_reg_addr                                                  "0xB80E85B0"
#define  DVBC_TST_OUT2_reg                                                       0xB80E85B0
#define  DVBC_TST_OUT2_inst_addr                                                 "0x00B7"
#define  set_DVBC_TST_OUT2_reg(data)                                             (*((volatile unsigned int*)DVBC_TST_OUT2_reg)=data)
#define  get_DVBC_TST_OUT2_reg                                                   (*((volatile unsigned int*)DVBC_TST_OUT2_reg))
#define  DVBC_TST_OUT2_tst_out2_7_0_shift                                        (0)
#define  DVBC_TST_OUT2_tst_out2_7_0_mask                                         (0x000000FF)
#define  DVBC_TST_OUT2_tst_out2_7_0(data)                                        (0x000000FF&(data))
#define  DVBC_TST_OUT2_get_tst_out2_7_0(data)                                    (0x000000FF&(data))

#define  DVBC_TST_OUT2_1                                                         0x180E85B4
#define  DVBC_TST_OUT2_1_reg_addr                                                "0xB80E85B4"
#define  DVBC_TST_OUT2_1_reg                                                     0xB80E85B4
#define  DVBC_TST_OUT2_1_inst_addr                                               "0x00B8"
#define  set_DVBC_TST_OUT2_1_reg(data)                                           (*((volatile unsigned int*)DVBC_TST_OUT2_1_reg)=data)
#define  get_DVBC_TST_OUT2_1_reg                                                 (*((volatile unsigned int*)DVBC_TST_OUT2_1_reg))
#define  DVBC_TST_OUT2_1_tst_out2_15_8_shift                                     (0)
#define  DVBC_TST_OUT2_1_tst_out2_15_8_mask                                      (0x000000FF)
#define  DVBC_TST_OUT2_1_tst_out2_15_8(data)                                     (0x000000FF&(data))
#define  DVBC_TST_OUT2_1_get_tst_out2_15_8(data)                                 (0x000000FF&(data))

#define  DVBC_INRX_MO1                                                           0x180E85B8
#define  DVBC_INRX_MO1_reg_addr                                                  "0xB80E85B8"
#define  DVBC_INRX_MO1_reg                                                       0xB80E85B8
#define  DVBC_INRX_MO1_inst_addr                                                 "0x00B9"
#define  set_DVBC_INRX_MO1_reg(data)                                             (*((volatile unsigned int*)DVBC_INRX_MO1_reg)=data)
#define  get_DVBC_INRX_MO1_reg                                                   (*((volatile unsigned int*)DVBC_INRX_MO1_reg))
#define  DVBC_INRX_MO1_inrx_mo1_7_0_shift                                        (0)
#define  DVBC_INRX_MO1_inrx_mo1_7_0_mask                                         (0x000000FF)
#define  DVBC_INRX_MO1_inrx_mo1_7_0(data)                                        (0x000000FF&(data))
#define  DVBC_INRX_MO1_get_inrx_mo1_7_0(data)                                    (0x000000FF&(data))

#define  DVBC_INRX_MO1_1                                                         0x180E85BC
#define  DVBC_INRX_MO1_1_reg_addr                                                "0xB80E85BC"
#define  DVBC_INRX_MO1_1_reg                                                     0xB80E85BC
#define  DVBC_INRX_MO1_1_inst_addr                                               "0x00BA"
#define  set_DVBC_INRX_MO1_1_reg(data)                                           (*((volatile unsigned int*)DVBC_INRX_MO1_1_reg)=data)
#define  get_DVBC_INRX_MO1_1_reg                                                 (*((volatile unsigned int*)DVBC_INRX_MO1_1_reg))
#define  DVBC_INRX_MO1_1_inrx_mo1_15_8_shift                                     (0)
#define  DVBC_INRX_MO1_1_inrx_mo1_15_8_mask                                      (0x000000FF)
#define  DVBC_INRX_MO1_1_inrx_mo1_15_8(data)                                     (0x000000FF&(data))
#define  DVBC_INRX_MO1_1_get_inrx_mo1_15_8(data)                                 (0x000000FF&(data))

#define  DVBC_INRX_MO1_2                                                         0x180E85C0
#define  DVBC_INRX_MO1_2_reg_addr                                                "0xB80E85C0"
#define  DVBC_INRX_MO1_2_reg                                                     0xB80E85C0
#define  DVBC_INRX_MO1_2_inst_addr                                               "0x00BB"
#define  set_DVBC_INRX_MO1_2_reg(data)                                           (*((volatile unsigned int*)DVBC_INRX_MO1_2_reg)=data)
#define  get_DVBC_INRX_MO1_2_reg                                                 (*((volatile unsigned int*)DVBC_INRX_MO1_2_reg))
#define  DVBC_INRX_MO1_2_inrx_mo1_23_16_shift                                    (0)
#define  DVBC_INRX_MO1_2_inrx_mo1_23_16_mask                                     (0x000000FF)
#define  DVBC_INRX_MO1_2_inrx_mo1_23_16(data)                                    (0x000000FF&(data))
#define  DVBC_INRX_MO1_2_get_inrx_mo1_23_16(data)                                (0x000000FF&(data))

#define  DVBC_INRX_MO1_3                                                         0x180E85C4
#define  DVBC_INRX_MO1_3_reg_addr                                                "0xB80E85C4"
#define  DVBC_INRX_MO1_3_reg                                                     0xB80E85C4
#define  DVBC_INRX_MO1_3_inst_addr                                               "0x00BC"
#define  set_DVBC_INRX_MO1_3_reg(data)                                           (*((volatile unsigned int*)DVBC_INRX_MO1_3_reg)=data)
#define  get_DVBC_INRX_MO1_3_reg                                                 (*((volatile unsigned int*)DVBC_INRX_MO1_3_reg))
#define  DVBC_INRX_MO1_3_inrx_mo1_31_24_shift                                    (0)
#define  DVBC_INRX_MO1_3_inrx_mo1_31_24_mask                                     (0x000000FF)
#define  DVBC_INRX_MO1_3_inrx_mo1_31_24(data)                                    (0x000000FF&(data))
#define  DVBC_INRX_MO1_3_get_inrx_mo1_31_24(data)                                (0x000000FF&(data))

#define  DVBC_INRX_MO2                                                           0x180E85C8
#define  DVBC_INRX_MO2_reg_addr                                                  "0xB80E85C8"
#define  DVBC_INRX_MO2_reg                                                       0xB80E85C8
#define  DVBC_INRX_MO2_inst_addr                                                 "0x00BD"
#define  set_DVBC_INRX_MO2_reg(data)                                             (*((volatile unsigned int*)DVBC_INRX_MO2_reg)=data)
#define  get_DVBC_INRX_MO2_reg                                                   (*((volatile unsigned int*)DVBC_INRX_MO2_reg))
#define  DVBC_INRX_MO2_inrx_mo2_7_0_shift                                        (0)
#define  DVBC_INRX_MO2_inrx_mo2_7_0_mask                                         (0x000000FF)
#define  DVBC_INRX_MO2_inrx_mo2_7_0(data)                                        (0x000000FF&(data))
#define  DVBC_INRX_MO2_get_inrx_mo2_7_0(data)                                    (0x000000FF&(data))

#define  DVBC_INRX_MO2_1                                                         0x180E85CC
#define  DVBC_INRX_MO2_1_reg_addr                                                "0xB80E85CC"
#define  DVBC_INRX_MO2_1_reg                                                     0xB80E85CC
#define  DVBC_INRX_MO2_1_inst_addr                                               "0x00BE"
#define  set_DVBC_INRX_MO2_1_reg(data)                                           (*((volatile unsigned int*)DVBC_INRX_MO2_1_reg)=data)
#define  get_DVBC_INRX_MO2_1_reg                                                 (*((volatile unsigned int*)DVBC_INRX_MO2_1_reg))
#define  DVBC_INRX_MO2_1_inrx_mo2_15_8_shift                                     (0)
#define  DVBC_INRX_MO2_1_inrx_mo2_15_8_mask                                      (0x000000FF)
#define  DVBC_INRX_MO2_1_inrx_mo2_15_8(data)                                     (0x000000FF&(data))
#define  DVBC_INRX_MO2_1_get_inrx_mo2_15_8(data)                                 (0x000000FF&(data))

#define  DVBC_INRX_MO2_2                                                         0x180E85D0
#define  DVBC_INRX_MO2_2_reg_addr                                                "0xB80E85D0"
#define  DVBC_INRX_MO2_2_reg                                                     0xB80E85D0
#define  DVBC_INRX_MO2_2_inst_addr                                               "0x00BF"
#define  set_DVBC_INRX_MO2_2_reg(data)                                           (*((volatile unsigned int*)DVBC_INRX_MO2_2_reg)=data)
#define  get_DVBC_INRX_MO2_2_reg                                                 (*((volatile unsigned int*)DVBC_INRX_MO2_2_reg))
#define  DVBC_INRX_MO2_2_inrx_mo2_18_16_shift                                    (0)
#define  DVBC_INRX_MO2_2_inrx_mo2_18_16_mask                                     (0x00000007)
#define  DVBC_INRX_MO2_2_inrx_mo2_18_16(data)                                    (0x00000007&(data))
#define  DVBC_INRX_MO2_2_get_inrx_mo2_18_16(data)                                (0x00000007&(data))

#define  DVBC_INRX_MO3                                                           0x180E85D8
#define  DVBC_INRX_MO3_reg_addr                                                  "0xB80E85D8"
#define  DVBC_INRX_MO3_reg                                                       0xB80E85D8
#define  DVBC_INRX_MO3_inst_addr                                                 "0x00C0"
#define  set_DVBC_INRX_MO3_reg(data)                                             (*((volatile unsigned int*)DVBC_INRX_MO3_reg)=data)
#define  get_DVBC_INRX_MO3_reg                                                   (*((volatile unsigned int*)DVBC_INRX_MO3_reg))
#define  DVBC_INRX_MO3_inrx_mo3_7_0_shift                                        (0)
#define  DVBC_INRX_MO3_inrx_mo3_7_0_mask                                         (0x000000FF)
#define  DVBC_INRX_MO3_inrx_mo3_7_0(data)                                        (0x000000FF&(data))
#define  DVBC_INRX_MO3_get_inrx_mo3_7_0(data)                                    (0x000000FF&(data))

#define  DVBC_INRX_MO3_1                                                         0x180E85DC
#define  DVBC_INRX_MO3_1_reg_addr                                                "0xB80E85DC"
#define  DVBC_INRX_MO3_1_reg                                                     0xB80E85DC
#define  DVBC_INRX_MO3_1_inst_addr                                               "0x00C1"
#define  set_DVBC_INRX_MO3_1_reg(data)                                           (*((volatile unsigned int*)DVBC_INRX_MO3_1_reg)=data)
#define  get_DVBC_INRX_MO3_1_reg                                                 (*((volatile unsigned int*)DVBC_INRX_MO3_1_reg))
#define  DVBC_INRX_MO3_1_inrx_mo3_15_8_shift                                     (0)
#define  DVBC_INRX_MO3_1_inrx_mo3_15_8_mask                                      (0x000000FF)
#define  DVBC_INRX_MO3_1_inrx_mo3_15_8(data)                                     (0x000000FF&(data))
#define  DVBC_INRX_MO3_1_get_inrx_mo3_15_8(data)                                 (0x000000FF&(data))

#define  DVBC_INRX_MO3_2                                                         0x180E85E0
#define  DVBC_INRX_MO3_2_reg_addr                                                "0xB80E85E0"
#define  DVBC_INRX_MO3_2_reg                                                     0xB80E85E0
#define  DVBC_INRX_MO3_2_inst_addr                                               "0x00C2"
#define  set_DVBC_INRX_MO3_2_reg(data)                                           (*((volatile unsigned int*)DVBC_INRX_MO3_2_reg)=data)
#define  get_DVBC_INRX_MO3_2_reg                                                 (*((volatile unsigned int*)DVBC_INRX_MO3_2_reg))
#define  DVBC_INRX_MO3_2_inrx_mo3_23_16_shift                                    (0)
#define  DVBC_INRX_MO3_2_inrx_mo3_23_16_mask                                     (0x000000FF)
#define  DVBC_INRX_MO3_2_inrx_mo3_23_16(data)                                    (0x000000FF&(data))
#define  DVBC_INRX_MO3_2_get_inrx_mo3_23_16(data)                                (0x000000FF&(data))

#define  DVBC_INRX_MO3_3                                                         0x180E85E4
#define  DVBC_INRX_MO3_3_reg_addr                                                "0xB80E85E4"
#define  DVBC_INRX_MO3_3_reg                                                     0xB80E85E4
#define  DVBC_INRX_MO3_3_inst_addr                                               "0x00C3"
#define  set_DVBC_INRX_MO3_3_reg(data)                                           (*((volatile unsigned int*)DVBC_INRX_MO3_3_reg)=data)
#define  get_DVBC_INRX_MO3_3_reg                                                 (*((volatile unsigned int*)DVBC_INRX_MO3_3_reg))
#define  DVBC_INRX_MO3_3_inrx_mo3_31_24_shift                                    (0)
#define  DVBC_INRX_MO3_3_inrx_mo3_31_24_mask                                     (0x000000FF)
#define  DVBC_INRX_MO3_3_inrx_mo3_31_24(data)                                    (0x000000FF&(data))
#define  DVBC_INRX_MO3_3_get_inrx_mo3_31_24(data)                                (0x000000FF&(data))

#define  DVBC_OPT_RT_FSM_STATE1                                                  0x180E85E8
#define  DVBC_OPT_RT_FSM_STATE1_reg_addr                                         "0xB80E85E8"
#define  DVBC_OPT_RT_FSM_STATE1_reg                                              0xB80E85E8
#define  DVBC_OPT_RT_FSM_STATE1_inst_addr                                        "0x00C4"
#define  set_DVBC_OPT_RT_FSM_STATE1_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_RT_FSM_STATE1_reg)=data)
#define  get_DVBC_OPT_RT_FSM_STATE1_reg                                          (*((volatile unsigned int*)DVBC_OPT_RT_FSM_STATE1_reg))
#define  DVBC_OPT_RT_FSM_STATE1_opt_rt_fsm_state2_shift                          (4)
#define  DVBC_OPT_RT_FSM_STATE1_opt_rt_fsm_state1_shift                          (0)
#define  DVBC_OPT_RT_FSM_STATE1_opt_rt_fsm_state2_mask                           (0x000000F0)
#define  DVBC_OPT_RT_FSM_STATE1_opt_rt_fsm_state1_mask                           (0x0000000F)
#define  DVBC_OPT_RT_FSM_STATE1_opt_rt_fsm_state2(data)                          (0x000000F0&((data)<<4))
#define  DVBC_OPT_RT_FSM_STATE1_opt_rt_fsm_state1(data)                          (0x0000000F&(data))
#define  DVBC_OPT_RT_FSM_STATE1_get_opt_rt_fsm_state2(data)                      ((0x000000F0&(data))>>4)
#define  DVBC_OPT_RT_FSM_STATE1_get_opt_rt_fsm_state1(data)                      (0x0000000F&(data))

#define  DVBC_OPT_RT_FSM_CNT_MIN                                                 0x180E85EC
#define  DVBC_OPT_RT_FSM_CNT_MIN_reg_addr                                        "0xB80E85EC"
#define  DVBC_OPT_RT_FSM_CNT_MIN_reg                                             0xB80E85EC
#define  DVBC_OPT_RT_FSM_CNT_MIN_inst_addr                                       "0x00C5"
#define  set_DVBC_OPT_RT_FSM_CNT_MIN_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_RT_FSM_CNT_MIN_reg)=data)
#define  get_DVBC_OPT_RT_FSM_CNT_MIN_reg                                         (*((volatile unsigned int*)DVBC_OPT_RT_FSM_CNT_MIN_reg))
#define  DVBC_OPT_RT_FSM_CNT_MIN_opt_rt_fsm_cnt_min_shift                        (0)
#define  DVBC_OPT_RT_FSM_CNT_MIN_opt_rt_fsm_cnt_min_mask                         (0x000000FF)
#define  DVBC_OPT_RT_FSM_CNT_MIN_opt_rt_fsm_cnt_min(data)                        (0x000000FF&(data))
#define  DVBC_OPT_RT_FSM_CNT_MIN_get_opt_rt_fsm_cnt_min(data)                    (0x000000FF&(data))

#define  DVBC_OPT_RT_FSM_F_CNT_MIN                                               0x180E85F0
#define  DVBC_OPT_RT_FSM_F_CNT_MIN_reg_addr                                      "0xB80E85F0"
#define  DVBC_OPT_RT_FSM_F_CNT_MIN_reg                                           0xB80E85F0
#define  DVBC_OPT_RT_FSM_F_CNT_MIN_inst_addr                                     "0x00C6"
#define  set_DVBC_OPT_RT_FSM_F_CNT_MIN_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_RT_FSM_F_CNT_MIN_reg)=data)
#define  get_DVBC_OPT_RT_FSM_F_CNT_MIN_reg                                       (*((volatile unsigned int*)DVBC_OPT_RT_FSM_F_CNT_MIN_reg))
#define  DVBC_OPT_RT_FSM_F_CNT_MIN_opt_rt_fsm_f_cnt_min_shift                    (0)
#define  DVBC_OPT_RT_FSM_F_CNT_MIN_opt_rt_fsm_f_cnt_min_mask                     (0x000000FF)
#define  DVBC_OPT_RT_FSM_F_CNT_MIN_opt_rt_fsm_f_cnt_min(data)                    (0x000000FF&(data))
#define  DVBC_OPT_RT_FSM_F_CNT_MIN_get_opt_rt_fsm_f_cnt_min(data)                (0x000000FF&(data))

#define  DVBC_OPT_AAGC_CNT_TH                                                    0x180E85F4
#define  DVBC_OPT_AAGC_CNT_TH_reg_addr                                           "0xB80E85F4"
#define  DVBC_OPT_AAGC_CNT_TH_reg                                                0xB80E85F4
#define  DVBC_OPT_AAGC_CNT_TH_inst_addr                                          "0x00C7"
#define  set_DVBC_OPT_AAGC_CNT_TH_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_AAGC_CNT_TH_reg)=data)
#define  get_DVBC_OPT_AAGC_CNT_TH_reg                                            (*((volatile unsigned int*)DVBC_OPT_AAGC_CNT_TH_reg))
#define  DVBC_OPT_AAGC_CNT_TH_opt_aagc_cnt_th_shift                              (0)
#define  DVBC_OPT_AAGC_CNT_TH_opt_aagc_cnt_th_mask                               (0x000000FF)
#define  DVBC_OPT_AAGC_CNT_TH_opt_aagc_cnt_th(data)                              (0x000000FF&(data))
#define  DVBC_OPT_AAGC_CNT_TH_get_opt_aagc_cnt_th(data)                          (0x000000FF&(data))

#define  DVBC_OPT_RT_FSM_F_J_CNT_MIN                                             0x180E85F8
#define  DVBC_OPT_RT_FSM_F_J_CNT_MIN_reg_addr                                    "0xB80E85F8"
#define  DVBC_OPT_RT_FSM_F_J_CNT_MIN_reg                                         0xB80E85F8
#define  DVBC_OPT_RT_FSM_F_J_CNT_MIN_inst_addr                                   "0x00C8"
#define  set_DVBC_OPT_RT_FSM_F_J_CNT_MIN_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_RT_FSM_F_J_CNT_MIN_reg)=data)
#define  get_DVBC_OPT_RT_FSM_F_J_CNT_MIN_reg                                     (*((volatile unsigned int*)DVBC_OPT_RT_FSM_F_J_CNT_MIN_reg))
#define  DVBC_OPT_RT_FSM_F_J_CNT_MIN_opt_rt_fsm_f_j_cnt_min_shift                (0)
#define  DVBC_OPT_RT_FSM_F_J_CNT_MIN_opt_rt_fsm_f_j_cnt_min_mask                 (0x000000FF)
#define  DVBC_OPT_RT_FSM_F_J_CNT_MIN_opt_rt_fsm_f_j_cnt_min(data)                (0x000000FF&(data))
#define  DVBC_OPT_RT_FSM_F_J_CNT_MIN_get_opt_rt_fsm_f_j_cnt_min(data)            (0x000000FF&(data))

#define  DVBC_OPT_RST_TR                                                         0x180E85FC
#define  DVBC_OPT_RST_TR_reg_addr                                                "0xB80E85FC"
#define  DVBC_OPT_RST_TR_reg                                                     0xB80E85FC
#define  DVBC_OPT_RST_TR_inst_addr                                               "0x00C9"
#define  set_DVBC_OPT_RST_TR_reg(data)                                           (*((volatile unsigned int*)DVBC_OPT_RST_TR_reg)=data)
#define  get_DVBC_OPT_RST_TR_reg                                                 (*((volatile unsigned int*)DVBC_OPT_RST_TR_reg))
#define  DVBC_OPT_RST_TR_rt_cond8_sel_shift                                      (4)
#define  DVBC_OPT_RST_TR_rt_cond8_en_shift                                       (3)
#define  DVBC_OPT_RST_TR_opt_rst_txiq_shift                                      (2)
#define  DVBC_OPT_RST_TR_opt_rst_cr_shift                                        (1)
#define  DVBC_OPT_RST_TR_opt_rst_tr_shift                                        (0)
#define  DVBC_OPT_RST_TR_rt_cond8_sel_mask                                       (0x00000030)
#define  DVBC_OPT_RST_TR_rt_cond8_en_mask                                        (0x00000008)
#define  DVBC_OPT_RST_TR_opt_rst_txiq_mask                                       (0x00000004)
#define  DVBC_OPT_RST_TR_opt_rst_cr_mask                                         (0x00000002)
#define  DVBC_OPT_RST_TR_opt_rst_tr_mask                                         (0x00000001)
#define  DVBC_OPT_RST_TR_rt_cond8_sel(data)                                      (0x00000030&((data)<<4))
#define  DVBC_OPT_RST_TR_rt_cond8_en(data)                                       (0x00000008&((data)<<3))
#define  DVBC_OPT_RST_TR_opt_rst_txiq(data)                                      (0x00000004&((data)<<2))
#define  DVBC_OPT_RST_TR_opt_rst_cr(data)                                        (0x00000002&((data)<<1))
#define  DVBC_OPT_RST_TR_opt_rst_tr(data)                                        (0x00000001&(data))
#define  DVBC_OPT_RST_TR_get_rt_cond8_sel(data)                                  ((0x00000030&(data))>>4)
#define  DVBC_OPT_RST_TR_get_rt_cond8_en(data)                                   ((0x00000008&(data))>>3)
#define  DVBC_OPT_RST_TR_get_opt_rst_txiq(data)                                  ((0x00000004&(data))>>2)
#define  DVBC_OPT_RST_TR_get_opt_rst_cr(data)                                    ((0x00000002&(data))>>1)
#define  DVBC_OPT_RST_TR_get_opt_rst_tr(data)                                    (0x00000001&(data))

#define  DVBC_LD_MSE_TH                                                          0x180E8600
#define  DVBC_LD_MSE_TH_reg_addr                                                 "0xB80E8600"
#define  DVBC_LD_MSE_TH_reg                                                      0xB80E8600
#define  DVBC_LD_MSE_TH_inst_addr                                                "0x00CA"
#define  set_DVBC_LD_MSE_TH_reg(data)                                            (*((volatile unsigned int*)DVBC_LD_MSE_TH_reg)=data)
#define  get_DVBC_LD_MSE_TH_reg                                                  (*((volatile unsigned int*)DVBC_LD_MSE_TH_reg))
#define  DVBC_LD_MSE_TH_ld_mse_th_7_0_shift                                      (0)
#define  DVBC_LD_MSE_TH_ld_mse_th_7_0_mask                                       (0x000000FF)
#define  DVBC_LD_MSE_TH_ld_mse_th_7_0(data)                                      (0x000000FF&(data))
#define  DVBC_LD_MSE_TH_get_ld_mse_th_7_0(data)                                  (0x000000FF&(data))

#define  DVBC_LD_MSE_TH_1                                                        0x180E8604
#define  DVBC_LD_MSE_TH_1_reg_addr                                               "0xB80E8604"
#define  DVBC_LD_MSE_TH_1_reg                                                    0xB80E8604
#define  DVBC_LD_MSE_TH_1_inst_addr                                              "0x00CB"
#define  set_DVBC_LD_MSE_TH_1_reg(data)                                          (*((volatile unsigned int*)DVBC_LD_MSE_TH_1_reg)=data)
#define  get_DVBC_LD_MSE_TH_1_reg                                                (*((volatile unsigned int*)DVBC_LD_MSE_TH_1_reg))
#define  DVBC_LD_MSE_TH_1_ld_mse_th_9_8_shift                                    (0)
#define  DVBC_LD_MSE_TH_1_ld_mse_th_9_8_mask                                     (0x00000003)
#define  DVBC_LD_MSE_TH_1_ld_mse_th_9_8(data)                                    (0x00000003&(data))
#define  DVBC_LD_MSE_TH_1_get_ld_mse_th_9_8(data)                                (0x00000003&(data))

#define  DVBC_LD_CR_TH                                                           0x180E8608
#define  DVBC_LD_CR_TH_reg_addr                                                  "0xB80E8608"
#define  DVBC_LD_CR_TH_reg                                                       0xB80E8608
#define  DVBC_LD_CR_TH_inst_addr                                                 "0x00CC"
#define  set_DVBC_LD_CR_TH_reg(data)                                             (*((volatile unsigned int*)DVBC_LD_CR_TH_reg)=data)
#define  get_DVBC_LD_CR_TH_reg                                                   (*((volatile unsigned int*)DVBC_LD_CR_TH_reg))
#define  DVBC_LD_CR_TH_ld_cr_th_shift                                            (0)
#define  DVBC_LD_CR_TH_ld_cr_th_mask                                             (0x0000001F)
#define  DVBC_LD_CR_TH_ld_cr_th(data)                                            (0x0000001F&(data))
#define  DVBC_LD_CR_TH_get_ld_cr_th(data)                                        (0x0000001F&(data))

#define  DVBC_LD_TR_TH                                                           0x180E860C
#define  DVBC_LD_TR_TH_reg_addr                                                  "0xB80E860C"
#define  DVBC_LD_TR_TH_reg                                                       0xB80E860C
#define  DVBC_LD_TR_TH_inst_addr                                                 "0x00CD"
#define  set_DVBC_LD_TR_TH_reg(data)                                             (*((volatile unsigned int*)DVBC_LD_TR_TH_reg)=data)
#define  get_DVBC_LD_TR_TH_reg                                                   (*((volatile unsigned int*)DVBC_LD_TR_TH_reg))
#define  DVBC_LD_TR_TH_ld_tr_th_shift                                            (0)
#define  DVBC_LD_TR_TH_ld_tr_th_mask                                             (0x0000001F)
#define  DVBC_LD_TR_TH_ld_tr_th(data)                                            (0x0000001F&(data))
#define  DVBC_LD_TR_TH_get_ld_tr_th(data)                                        (0x0000001F&(data))

#define  DVBC_LD_PERIOD_TH                                                       0x180E8610
#define  DVBC_LD_PERIOD_TH_reg_addr                                              "0xB80E8610"
#define  DVBC_LD_PERIOD_TH_reg                                                   0xB80E8610
#define  DVBC_LD_PERIOD_TH_inst_addr                                             "0x00CE"
#define  set_DVBC_LD_PERIOD_TH_reg(data)                                         (*((volatile unsigned int*)DVBC_LD_PERIOD_TH_reg)=data)
#define  get_DVBC_LD_PERIOD_TH_reg                                               (*((volatile unsigned int*)DVBC_LD_PERIOD_TH_reg))
#define  DVBC_LD_PERIOD_TH_ld_period_th_7_0_shift                                (0)
#define  DVBC_LD_PERIOD_TH_ld_period_th_7_0_mask                                 (0x000000FF)
#define  DVBC_LD_PERIOD_TH_ld_period_th_7_0(data)                                (0x000000FF&(data))
#define  DVBC_LD_PERIOD_TH_get_ld_period_th_7_0(data)                            (0x000000FF&(data))

#define  DVBC_LD_PERIOD_TH_1                                                     0x180E8614
#define  DVBC_LD_PERIOD_TH_1_reg_addr                                            "0xB80E8614"
#define  DVBC_LD_PERIOD_TH_1_reg                                                 0xB80E8614
#define  DVBC_LD_PERIOD_TH_1_inst_addr                                           "0x00CF"
#define  set_DVBC_LD_PERIOD_TH_1_reg(data)                                       (*((volatile unsigned int*)DVBC_LD_PERIOD_TH_1_reg)=data)
#define  get_DVBC_LD_PERIOD_TH_1_reg                                             (*((volatile unsigned int*)DVBC_LD_PERIOD_TH_1_reg))
#define  DVBC_LD_PERIOD_TH_1_ld_period_th_9_8_shift                              (0)
#define  DVBC_LD_PERIOD_TH_1_ld_period_th_9_8_mask                               (0x00000003)
#define  DVBC_LD_PERIOD_TH_1_ld_period_th_9_8(data)                              (0x00000003&(data))
#define  DVBC_LD_PERIOD_TH_1_get_ld_period_th_9_8(data)                          (0x00000003&(data))

#define  DVBC_LD_MAX_ERR_TH                                                      0x180E8618
#define  DVBC_LD_MAX_ERR_TH_reg_addr                                             "0xB80E8618"
#define  DVBC_LD_MAX_ERR_TH_reg                                                  0xB80E8618
#define  DVBC_LD_MAX_ERR_TH_inst_addr                                            "0x00D0"
#define  set_DVBC_LD_MAX_ERR_TH_reg(data)                                        (*((volatile unsigned int*)DVBC_LD_MAX_ERR_TH_reg)=data)
#define  get_DVBC_LD_MAX_ERR_TH_reg                                              (*((volatile unsigned int*)DVBC_LD_MAX_ERR_TH_reg))
#define  DVBC_LD_MAX_ERR_TH_ld_max_err_th_7_0_shift                              (0)
#define  DVBC_LD_MAX_ERR_TH_ld_max_err_th_7_0_mask                               (0x000000FF)
#define  DVBC_LD_MAX_ERR_TH_ld_max_err_th_7_0(data)                              (0x000000FF&(data))
#define  DVBC_LD_MAX_ERR_TH_get_ld_max_err_th_7_0(data)                          (0x000000FF&(data))

#define  DVBC_LD_MAX_ERR_TH_1                                                    0x180E861C
#define  DVBC_LD_MAX_ERR_TH_1_reg_addr                                           "0xB80E861C"
#define  DVBC_LD_MAX_ERR_TH_1_reg                                                0xB80E861C
#define  DVBC_LD_MAX_ERR_TH_1_inst_addr                                          "0x00D1"
#define  set_DVBC_LD_MAX_ERR_TH_1_reg(data)                                      (*((volatile unsigned int*)DVBC_LD_MAX_ERR_TH_1_reg)=data)
#define  get_DVBC_LD_MAX_ERR_TH_1_reg                                            (*((volatile unsigned int*)DVBC_LD_MAX_ERR_TH_1_reg))
#define  DVBC_LD_MAX_ERR_TH_1_ld_max_err_th_14_8_shift                           (0)
#define  DVBC_LD_MAX_ERR_TH_1_ld_max_err_th_14_8_mask                            (0x0000007F)
#define  DVBC_LD_MAX_ERR_TH_1_ld_max_err_th_14_8(data)                           (0x0000007F&(data))
#define  DVBC_LD_MAX_ERR_TH_1_get_ld_max_err_th_14_8(data)                       (0x0000007F&(data))

#define  DVBC_LD_OUTER_TH                                                        0x180E8620
#define  DVBC_LD_OUTER_TH_reg_addr                                               "0xB80E8620"
#define  DVBC_LD_OUTER_TH_reg                                                    0xB80E8620
#define  DVBC_LD_OUTER_TH_inst_addr                                              "0x00D2"
#define  set_DVBC_LD_OUTER_TH_reg(data)                                          (*((volatile unsigned int*)DVBC_LD_OUTER_TH_reg)=data)
#define  get_DVBC_LD_OUTER_TH_reg                                                (*((volatile unsigned int*)DVBC_LD_OUTER_TH_reg))
#define  DVBC_LD_OUTER_TH_ld_outer_th_shift                                      (0)
#define  DVBC_LD_OUTER_TH_ld_outer_th_mask                                       (0x000000FF)
#define  DVBC_LD_OUTER_TH_ld_outer_th(data)                                      (0x000000FF&(data))
#define  DVBC_LD_OUTER_TH_get_ld_outer_th(data)                                  (0x000000FF&(data))

#define  DVBC_LD_COND_EN                                                         0x180E8624
#define  DVBC_LD_COND_EN_reg_addr                                                "0xB80E8624"
#define  DVBC_LD_COND_EN_reg                                                     0xB80E8624
#define  DVBC_LD_COND_EN_inst_addr                                               "0x00D3"
#define  set_DVBC_LD_COND_EN_reg(data)                                           (*((volatile unsigned int*)DVBC_LD_COND_EN_reg)=data)
#define  get_DVBC_LD_COND_EN_reg                                                 (*((volatile unsigned int*)DVBC_LD_COND_EN_reg))
#define  DVBC_LD_COND_EN_ld_cond_en_shift                                        (0)
#define  DVBC_LD_COND_EN_ld_cond_en_mask                                         (0x000000FF)
#define  DVBC_LD_COND_EN_ld_cond_en(data)                                        (0x000000FF&(data))
#define  DVBC_LD_COND_EN_get_ld_cond_en(data)                                    (0x000000FF&(data))

#define  DVBC_LD_COND_AND                                                        0x180E8628
#define  DVBC_LD_COND_AND_reg_addr                                               "0xB80E8628"
#define  DVBC_LD_COND_AND_reg                                                    0xB80E8628
#define  DVBC_LD_COND_AND_inst_addr                                              "0x00D4"
#define  set_DVBC_LD_COND_AND_reg(data)                                          (*((volatile unsigned int*)DVBC_LD_COND_AND_reg)=data)
#define  get_DVBC_LD_COND_AND_reg                                                (*((volatile unsigned int*)DVBC_LD_COND_AND_reg))
#define  DVBC_LD_COND_AND_outer_ld_shift                                         (1)
#define  DVBC_LD_COND_AND_ld_cond_and_shift                                      (0)
#define  DVBC_LD_COND_AND_outer_ld_mask                                          (0x00000002)
#define  DVBC_LD_COND_AND_ld_cond_and_mask                                       (0x00000001)
#define  DVBC_LD_COND_AND_outer_ld(data)                                         (0x00000002&((data)<<1))
#define  DVBC_LD_COND_AND_ld_cond_and(data)                                      (0x00000001&(data))
#define  DVBC_LD_COND_AND_get_outer_ld(data)                                     ((0x00000002&(data))>>1)
#define  DVBC_LD_COND_AND_get_ld_cond_and(data)                                  (0x00000001&(data))

#define  DVBC_OPT_CR_METRIC_DD_SEL                                               0x180E862C
#define  DVBC_OPT_CR_METRIC_DD_SEL_reg_addr                                      "0xB80E862C"
#define  DVBC_OPT_CR_METRIC_DD_SEL_reg                                           0xB80E862C
#define  DVBC_OPT_CR_METRIC_DD_SEL_inst_addr                                     "0x00D5"
#define  set_DVBC_OPT_CR_METRIC_DD_SEL_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_CR_METRIC_DD_SEL_reg)=data)
#define  get_DVBC_OPT_CR_METRIC_DD_SEL_reg                                       (*((volatile unsigned int*)DVBC_OPT_CR_METRIC_DD_SEL_reg))
#define  DVBC_OPT_CR_METRIC_DD_SEL_opt_cr_dd_cordic_max_shift                    (4)
#define  DVBC_OPT_CR_METRIC_DD_SEL_opt_cr_dd_cordic_sat_shift                    (2)
#define  DVBC_OPT_CR_METRIC_DD_SEL_opt_cr_metric_dd_sel_shift                    (0)
#define  DVBC_OPT_CR_METRIC_DD_SEL_opt_cr_dd_cordic_max_mask                     (0x000000F0)
#define  DVBC_OPT_CR_METRIC_DD_SEL_opt_cr_dd_cordic_sat_mask                     (0x00000004)
#define  DVBC_OPT_CR_METRIC_DD_SEL_opt_cr_metric_dd_sel_mask                     (0x00000003)
#define  DVBC_OPT_CR_METRIC_DD_SEL_opt_cr_dd_cordic_max(data)                    (0x000000F0&((data)<<4))
#define  DVBC_OPT_CR_METRIC_DD_SEL_opt_cr_dd_cordic_sat(data)                    (0x00000004&((data)<<2))
#define  DVBC_OPT_CR_METRIC_DD_SEL_opt_cr_metric_dd_sel(data)                    (0x00000003&(data))
#define  DVBC_OPT_CR_METRIC_DD_SEL_get_opt_cr_dd_cordic_max(data)                ((0x000000F0&(data))>>4)
#define  DVBC_OPT_CR_METRIC_DD_SEL_get_opt_cr_dd_cordic_sat(data)                ((0x00000004&(data))>>2)
#define  DVBC_OPT_CR_METRIC_DD_SEL_get_opt_cr_metric_dd_sel(data)                (0x00000003&(data))

#define  DVBC_OPT_AK_POW_ON                                                      0x180E8630
#define  DVBC_OPT_AK_POW_ON_reg_addr                                             "0xB80E8630"
#define  DVBC_OPT_AK_POW_ON_reg                                                  0xB80E8630
#define  DVBC_OPT_AK_POW_ON_inst_addr                                            "0x00D6"
#define  set_DVBC_OPT_AK_POW_ON_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_AK_POW_ON_reg)=data)
#define  get_DVBC_OPT_AK_POW_ON_reg                                              (*((volatile unsigned int*)DVBC_OPT_AK_POW_ON_reg))
#define  DVBC_OPT_AK_POW_ON_opt_ak_pow_on_shift                                  (0)
#define  DVBC_OPT_AK_POW_ON_opt_ak_pow_on_mask                                   (0x00000007)
#define  DVBC_OPT_AK_POW_ON_opt_ak_pow_on(data)                                  (0x00000007&(data))
#define  DVBC_OPT_AK_POW_ON_get_opt_ak_pow_on(data)                              (0x00000007&(data))

#define  DVBC_OPT_PN_BN_ERR_RATIO                                                0x180E8634
#define  DVBC_OPT_PN_BN_ERR_RATIO_reg_addr                                       "0xB80E8634"
#define  DVBC_OPT_PN_BN_ERR_RATIO_reg                                            0xB80E8634
#define  DVBC_OPT_PN_BN_ERR_RATIO_inst_addr                                      "0x00D7"
#define  set_DVBC_OPT_PN_BN_ERR_RATIO_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_PN_BN_ERR_RATIO_reg)=data)
#define  get_DVBC_OPT_PN_BN_ERR_RATIO_reg                                        (*((volatile unsigned int*)DVBC_OPT_PN_BN_ERR_RATIO_reg))
#define  DVBC_OPT_PN_BN_ERR_RATIO_opt_pn_det_th_shift                            (4)
#define  DVBC_OPT_PN_BN_ERR_RATIO_opt_pn_bn_err_ratio_shift                      (0)
#define  DVBC_OPT_PN_BN_ERR_RATIO_opt_pn_det_th_mask                             (0x000000F0)
#define  DVBC_OPT_PN_BN_ERR_RATIO_opt_pn_bn_err_ratio_mask                       (0x0000000F)
#define  DVBC_OPT_PN_BN_ERR_RATIO_opt_pn_det_th(data)                            (0x000000F0&((data)<<4))
#define  DVBC_OPT_PN_BN_ERR_RATIO_opt_pn_bn_err_ratio(data)                      (0x0000000F&(data))
#define  DVBC_OPT_PN_BN_ERR_RATIO_get_opt_pn_det_th(data)                        ((0x000000F0&(data))>>4)
#define  DVBC_OPT_PN_BN_ERR_RATIO_get_opt_pn_bn_err_ratio(data)                  (0x0000000F&(data))

#define  DVBC_OPT_MAIN_TAP_SEL                                                   0x180E8640
#define  DVBC_OPT_MAIN_TAP_SEL_reg_addr                                          "0xB80E8640"
#define  DVBC_OPT_MAIN_TAP_SEL_reg                                               0xB80E8640
#define  DVBC_OPT_MAIN_TAP_SEL_inst_addr                                         "0x00D8"
#define  set_DVBC_OPT_MAIN_TAP_SEL_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_MAIN_TAP_SEL_reg)=data)
#define  get_DVBC_OPT_MAIN_TAP_SEL_reg                                           (*((volatile unsigned int*)DVBC_OPT_MAIN_TAP_SEL_reg))
#define  DVBC_OPT_MAIN_TAP_SEL_opt_u_fff2_acq0_shift                             (5)
#define  DVBC_OPT_MAIN_TAP_SEL_opt_main_tap_sel_shift                            (0)
#define  DVBC_OPT_MAIN_TAP_SEL_opt_u_fff2_acq0_mask                              (0x000000E0)
#define  DVBC_OPT_MAIN_TAP_SEL_opt_main_tap_sel_mask                             (0x0000001F)
#define  DVBC_OPT_MAIN_TAP_SEL_opt_u_fff2_acq0(data)                             (0x000000E0&((data)<<5))
#define  DVBC_OPT_MAIN_TAP_SEL_opt_main_tap_sel(data)                            (0x0000001F&(data))
#define  DVBC_OPT_MAIN_TAP_SEL_get_opt_u_fff2_acq0(data)                         ((0x000000E0&(data))>>5)
#define  DVBC_OPT_MAIN_TAP_SEL_get_opt_main_tap_sel(data)                        (0x0000001F&(data))

#define  DVBC_OPT_U_FFF2_ACQ1                                                    0x180E8644
#define  DVBC_OPT_U_FFF2_ACQ1_reg_addr                                           "0xB80E8644"
#define  DVBC_OPT_U_FFF2_ACQ1_reg                                                0xB80E8644
#define  DVBC_OPT_U_FFF2_ACQ1_inst_addr                                          "0x00D9"
#define  set_DVBC_OPT_U_FFF2_ACQ1_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_U_FFF2_ACQ1_reg)=data)
#define  get_DVBC_OPT_U_FFF2_ACQ1_reg                                            (*((volatile unsigned int*)DVBC_OPT_U_FFF2_ACQ1_reg))
#define  DVBC_OPT_U_FFF2_ACQ1_opt_u_fff2_acq2_shift                              (3)
#define  DVBC_OPT_U_FFF2_ACQ1_opt_u_fff2_acq1_shift                              (0)
#define  DVBC_OPT_U_FFF2_ACQ1_opt_u_fff2_acq2_mask                               (0x00000038)
#define  DVBC_OPT_U_FFF2_ACQ1_opt_u_fff2_acq1_mask                               (0x00000007)
#define  DVBC_OPT_U_FFF2_ACQ1_opt_u_fff2_acq2(data)                              (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF2_ACQ1_opt_u_fff2_acq1(data)                              (0x00000007&(data))
#define  DVBC_OPT_U_FFF2_ACQ1_get_opt_u_fff2_acq2(data)                          ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF2_ACQ1_get_opt_u_fff2_acq1(data)                          (0x00000007&(data))

#define  DVBC_OPT_U_FFF3_ACQ0                                                    0x180E8648
#define  DVBC_OPT_U_FFF3_ACQ0_reg_addr                                           "0xB80E8648"
#define  DVBC_OPT_U_FFF3_ACQ0_reg                                                0xB80E8648
#define  DVBC_OPT_U_FFF3_ACQ0_inst_addr                                          "0x00DA"
#define  set_DVBC_OPT_U_FFF3_ACQ0_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_U_FFF3_ACQ0_reg)=data)
#define  get_DVBC_OPT_U_FFF3_ACQ0_reg                                            (*((volatile unsigned int*)DVBC_OPT_U_FFF3_ACQ0_reg))
#define  DVBC_OPT_U_FFF3_ACQ0_opt_u_fff3_acq1_shift                              (3)
#define  DVBC_OPT_U_FFF3_ACQ0_opt_u_fff3_acq0_shift                              (0)
#define  DVBC_OPT_U_FFF3_ACQ0_opt_u_fff3_acq1_mask                               (0x00000038)
#define  DVBC_OPT_U_FFF3_ACQ0_opt_u_fff3_acq0_mask                               (0x00000007)
#define  DVBC_OPT_U_FFF3_ACQ0_opt_u_fff3_acq1(data)                              (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF3_ACQ0_opt_u_fff3_acq0(data)                              (0x00000007&(data))
#define  DVBC_OPT_U_FFF3_ACQ0_get_opt_u_fff3_acq1(data)                          ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF3_ACQ0_get_opt_u_fff3_acq0(data)                          (0x00000007&(data))

#define  DVBC_OPT_U_FFF3_ACQ2                                                    0x180E864C
#define  DVBC_OPT_U_FFF3_ACQ2_reg_addr                                           "0xB80E864C"
#define  DVBC_OPT_U_FFF3_ACQ2_reg                                                0xB80E864C
#define  DVBC_OPT_U_FFF3_ACQ2_inst_addr                                          "0x00DB"
#define  set_DVBC_OPT_U_FFF3_ACQ2_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_U_FFF3_ACQ2_reg)=data)
#define  get_DVBC_OPT_U_FFF3_ACQ2_reg                                            (*((volatile unsigned int*)DVBC_OPT_U_FFF3_ACQ2_reg))
#define  DVBC_OPT_U_FFF3_ACQ2_opt_u_fff4_acq0_shift                              (3)
#define  DVBC_OPT_U_FFF3_ACQ2_opt_u_fff3_acq2_shift                              (0)
#define  DVBC_OPT_U_FFF3_ACQ2_opt_u_fff4_acq0_mask                               (0x00000038)
#define  DVBC_OPT_U_FFF3_ACQ2_opt_u_fff3_acq2_mask                               (0x00000007)
#define  DVBC_OPT_U_FFF3_ACQ2_opt_u_fff4_acq0(data)                              (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF3_ACQ2_opt_u_fff3_acq2(data)                              (0x00000007&(data))
#define  DVBC_OPT_U_FFF3_ACQ2_get_opt_u_fff4_acq0(data)                          ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF3_ACQ2_get_opt_u_fff3_acq2(data)                          (0x00000007&(data))

#define  DVBC_OPT_U_FFF4_ACQ1                                                    0x180E8650
#define  DVBC_OPT_U_FFF4_ACQ1_reg_addr                                           "0xB80E8650"
#define  DVBC_OPT_U_FFF4_ACQ1_reg                                                0xB80E8650
#define  DVBC_OPT_U_FFF4_ACQ1_inst_addr                                          "0x00DC"
#define  set_DVBC_OPT_U_FFF4_ACQ1_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_U_FFF4_ACQ1_reg)=data)
#define  get_DVBC_OPT_U_FFF4_ACQ1_reg                                            (*((volatile unsigned int*)DVBC_OPT_U_FFF4_ACQ1_reg))
#define  DVBC_OPT_U_FFF4_ACQ1_opt_u_fff4_acq2_shift                              (3)
#define  DVBC_OPT_U_FFF4_ACQ1_opt_u_fff4_acq1_shift                              (0)
#define  DVBC_OPT_U_FFF4_ACQ1_opt_u_fff4_acq2_mask                               (0x00000038)
#define  DVBC_OPT_U_FFF4_ACQ1_opt_u_fff4_acq1_mask                               (0x00000007)
#define  DVBC_OPT_U_FFF4_ACQ1_opt_u_fff4_acq2(data)                              (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF4_ACQ1_opt_u_fff4_acq1(data)                              (0x00000007&(data))
#define  DVBC_OPT_U_FFF4_ACQ1_get_opt_u_fff4_acq2(data)                          ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF4_ACQ1_get_opt_u_fff4_acq1(data)                          (0x00000007&(data))

#define  DVBC_OPT_U_FBF3_ACQ0                                                    0x180E8654
#define  DVBC_OPT_U_FBF3_ACQ0_reg_addr                                           "0xB80E8654"
#define  DVBC_OPT_U_FBF3_ACQ0_reg                                                0xB80E8654
#define  DVBC_OPT_U_FBF3_ACQ0_inst_addr                                          "0x00DD"
#define  set_DVBC_OPT_U_FBF3_ACQ0_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_U_FBF3_ACQ0_reg)=data)
#define  get_DVBC_OPT_U_FBF3_ACQ0_reg                                            (*((volatile unsigned int*)DVBC_OPT_U_FBF3_ACQ0_reg))
#define  DVBC_OPT_U_FBF3_ACQ0_opt_u_fbf3_acq2_shift                              (4)
#define  DVBC_OPT_U_FBF3_ACQ0_opt_u_fbf3_acq1_shift                              (2)
#define  DVBC_OPT_U_FBF3_ACQ0_opt_u_fbf3_acq0_shift                              (0)
#define  DVBC_OPT_U_FBF3_ACQ0_opt_u_fbf3_acq2_mask                               (0x00000030)
#define  DVBC_OPT_U_FBF3_ACQ0_opt_u_fbf3_acq1_mask                               (0x0000000C)
#define  DVBC_OPT_U_FBF3_ACQ0_opt_u_fbf3_acq0_mask                               (0x00000003)
#define  DVBC_OPT_U_FBF3_ACQ0_opt_u_fbf3_acq2(data)                              (0x00000030&((data)<<4))
#define  DVBC_OPT_U_FBF3_ACQ0_opt_u_fbf3_acq1(data)                              (0x0000000C&((data)<<2))
#define  DVBC_OPT_U_FBF3_ACQ0_opt_u_fbf3_acq0(data)                              (0x00000003&(data))
#define  DVBC_OPT_U_FBF3_ACQ0_get_opt_u_fbf3_acq2(data)                          ((0x00000030&(data))>>4)
#define  DVBC_OPT_U_FBF3_ACQ0_get_opt_u_fbf3_acq1(data)                          ((0x0000000C&(data))>>2)
#define  DVBC_OPT_U_FBF3_ACQ0_get_opt_u_fbf3_acq0(data)                          (0x00000003&(data))

#define  DVBC_OPT_U_FBF4_ACQ0                                                    0x180E8658
#define  DVBC_OPT_U_FBF4_ACQ0_reg_addr                                           "0xB80E8658"
#define  DVBC_OPT_U_FBF4_ACQ0_reg                                                0xB80E8658
#define  DVBC_OPT_U_FBF4_ACQ0_inst_addr                                          "0x00DE"
#define  set_DVBC_OPT_U_FBF4_ACQ0_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_U_FBF4_ACQ0_reg)=data)
#define  get_DVBC_OPT_U_FBF4_ACQ0_reg                                            (*((volatile unsigned int*)DVBC_OPT_U_FBF4_ACQ0_reg))
#define  DVBC_OPT_U_FBF4_ACQ0_opt_u_fbf4_acq2_shift                              (4)
#define  DVBC_OPT_U_FBF4_ACQ0_opt_u_fbf4_acq1_shift                              (2)
#define  DVBC_OPT_U_FBF4_ACQ0_opt_u_fbf4_acq0_shift                              (0)
#define  DVBC_OPT_U_FBF4_ACQ0_opt_u_fbf4_acq2_mask                               (0x00000030)
#define  DVBC_OPT_U_FBF4_ACQ0_opt_u_fbf4_acq1_mask                               (0x0000000C)
#define  DVBC_OPT_U_FBF4_ACQ0_opt_u_fbf4_acq0_mask                               (0x00000003)
#define  DVBC_OPT_U_FBF4_ACQ0_opt_u_fbf4_acq2(data)                              (0x00000030&((data)<<4))
#define  DVBC_OPT_U_FBF4_ACQ0_opt_u_fbf4_acq1(data)                              (0x0000000C&((data)<<2))
#define  DVBC_OPT_U_FBF4_ACQ0_opt_u_fbf4_acq0(data)                              (0x00000003&(data))
#define  DVBC_OPT_U_FBF4_ACQ0_get_opt_u_fbf4_acq2(data)                          ((0x00000030&(data))>>4)
#define  DVBC_OPT_U_FBF4_ACQ0_get_opt_u_fbf4_acq1(data)                          ((0x0000000C&(data))>>2)
#define  DVBC_OPT_U_FBF4_ACQ0_get_opt_u_fbf4_acq0(data)                          (0x00000003&(data))

#define  DVBC_OPT_U_FFF2_DD0                                                     0x180E865C
#define  DVBC_OPT_U_FFF2_DD0_reg_addr                                            "0xB80E865C"
#define  DVBC_OPT_U_FFF2_DD0_reg                                                 0xB80E865C
#define  DVBC_OPT_U_FFF2_DD0_inst_addr                                           "0x00DF"
#define  set_DVBC_OPT_U_FFF2_DD0_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_U_FFF2_DD0_reg)=data)
#define  get_DVBC_OPT_U_FFF2_DD0_reg                                             (*((volatile unsigned int*)DVBC_OPT_U_FFF2_DD0_reg))
#define  DVBC_OPT_U_FFF2_DD0_opt_u_fff2_dd1_shift                                (3)
#define  DVBC_OPT_U_FFF2_DD0_opt_u_fff2_dd0_shift                                (0)
#define  DVBC_OPT_U_FFF2_DD0_opt_u_fff2_dd1_mask                                 (0x00000038)
#define  DVBC_OPT_U_FFF2_DD0_opt_u_fff2_dd0_mask                                 (0x00000007)
#define  DVBC_OPT_U_FFF2_DD0_opt_u_fff2_dd1(data)                                (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF2_DD0_opt_u_fff2_dd0(data)                                (0x00000007&(data))
#define  DVBC_OPT_U_FFF2_DD0_get_opt_u_fff2_dd1(data)                            ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF2_DD0_get_opt_u_fff2_dd0(data)                            (0x00000007&(data))

#define  DVBC_OPT_U_FFF2_DD2                                                     0x180E8660
#define  DVBC_OPT_U_FFF2_DD2_reg_addr                                            "0xB80E8660"
#define  DVBC_OPT_U_FFF2_DD2_reg                                                 0xB80E8660
#define  DVBC_OPT_U_FFF2_DD2_inst_addr                                           "0x00E0"
#define  set_DVBC_OPT_U_FFF2_DD2_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_U_FFF2_DD2_reg)=data)
#define  get_DVBC_OPT_U_FFF2_DD2_reg                                             (*((volatile unsigned int*)DVBC_OPT_U_FFF2_DD2_reg))
#define  DVBC_OPT_U_FFF2_DD2_opt_u_fff3_dd0_shift                                (3)
#define  DVBC_OPT_U_FFF2_DD2_opt_u_fff2_dd2_shift                                (0)
#define  DVBC_OPT_U_FFF2_DD2_opt_u_fff3_dd0_mask                                 (0x00000038)
#define  DVBC_OPT_U_FFF2_DD2_opt_u_fff2_dd2_mask                                 (0x00000007)
#define  DVBC_OPT_U_FFF2_DD2_opt_u_fff3_dd0(data)                                (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF2_DD2_opt_u_fff2_dd2(data)                                (0x00000007&(data))
#define  DVBC_OPT_U_FFF2_DD2_get_opt_u_fff3_dd0(data)                            ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF2_DD2_get_opt_u_fff2_dd2(data)                            (0x00000007&(data))

#define  DVBC_OPT_U_FFF3_DD1                                                     0x180E8664
#define  DVBC_OPT_U_FFF3_DD1_reg_addr                                            "0xB80E8664"
#define  DVBC_OPT_U_FFF3_DD1_reg                                                 0xB80E8664
#define  DVBC_OPT_U_FFF3_DD1_inst_addr                                           "0x00E1"
#define  set_DVBC_OPT_U_FFF3_DD1_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_U_FFF3_DD1_reg)=data)
#define  get_DVBC_OPT_U_FFF3_DD1_reg                                             (*((volatile unsigned int*)DVBC_OPT_U_FFF3_DD1_reg))
#define  DVBC_OPT_U_FFF3_DD1_opt_u_fff3_dd2_shift                                (3)
#define  DVBC_OPT_U_FFF3_DD1_opt_u_fff3_dd1_shift                                (0)
#define  DVBC_OPT_U_FFF3_DD1_opt_u_fff3_dd2_mask                                 (0x00000038)
#define  DVBC_OPT_U_FFF3_DD1_opt_u_fff3_dd1_mask                                 (0x00000007)
#define  DVBC_OPT_U_FFF3_DD1_opt_u_fff3_dd2(data)                                (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF3_DD1_opt_u_fff3_dd1(data)                                (0x00000007&(data))
#define  DVBC_OPT_U_FFF3_DD1_get_opt_u_fff3_dd2(data)                            ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF3_DD1_get_opt_u_fff3_dd1(data)                            (0x00000007&(data))

#define  DVBC_OPT_U_FFF4_DD0                                                     0x180E8668
#define  DVBC_OPT_U_FFF4_DD0_reg_addr                                            "0xB80E8668"
#define  DVBC_OPT_U_FFF4_DD0_reg                                                 0xB80E8668
#define  DVBC_OPT_U_FFF4_DD0_inst_addr                                           "0x00E2"
#define  set_DVBC_OPT_U_FFF4_DD0_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_U_FFF4_DD0_reg)=data)
#define  get_DVBC_OPT_U_FFF4_DD0_reg                                             (*((volatile unsigned int*)DVBC_OPT_U_FFF4_DD0_reg))
#define  DVBC_OPT_U_FFF4_DD0_opt_u_fff4_dd1_shift                                (3)
#define  DVBC_OPT_U_FFF4_DD0_opt_u_fff4_dd0_shift                                (0)
#define  DVBC_OPT_U_FFF4_DD0_opt_u_fff4_dd1_mask                                 (0x00000038)
#define  DVBC_OPT_U_FFF4_DD0_opt_u_fff4_dd0_mask                                 (0x00000007)
#define  DVBC_OPT_U_FFF4_DD0_opt_u_fff4_dd1(data)                                (0x00000038&((data)<<3))
#define  DVBC_OPT_U_FFF4_DD0_opt_u_fff4_dd0(data)                                (0x00000007&(data))
#define  DVBC_OPT_U_FFF4_DD0_get_opt_u_fff4_dd1(data)                            ((0x00000038&(data))>>3)
#define  DVBC_OPT_U_FFF4_DD0_get_opt_u_fff4_dd0(data)                            (0x00000007&(data))

#define  DVBC_OPT_U_FFF4_DD2                                                     0x180E866C
#define  DVBC_OPT_U_FFF4_DD2_reg_addr                                            "0xB80E866C"
#define  DVBC_OPT_U_FFF4_DD2_reg                                                 0xB80E866C
#define  DVBC_OPT_U_FFF4_DD2_inst_addr                                           "0x00E3"
#define  set_DVBC_OPT_U_FFF4_DD2_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_U_FFF4_DD2_reg)=data)
#define  get_DVBC_OPT_U_FFF4_DD2_reg                                             (*((volatile unsigned int*)DVBC_OPT_U_FFF4_DD2_reg))
#define  DVBC_OPT_U_FFF4_DD2_opt_u_fbf3_dd1_shift                                (5)
#define  DVBC_OPT_U_FFF4_DD2_opt_u_fbf3_dd0_shift                                (3)
#define  DVBC_OPT_U_FFF4_DD2_opt_u_fff4_dd2_shift                                (0)
#define  DVBC_OPT_U_FFF4_DD2_opt_u_fbf3_dd1_mask                                 (0x00000060)
#define  DVBC_OPT_U_FFF4_DD2_opt_u_fbf3_dd0_mask                                 (0x00000018)
#define  DVBC_OPT_U_FFF4_DD2_opt_u_fff4_dd2_mask                                 (0x00000007)
#define  DVBC_OPT_U_FFF4_DD2_opt_u_fbf3_dd1(data)                                (0x00000060&((data)<<5))
#define  DVBC_OPT_U_FFF4_DD2_opt_u_fbf3_dd0(data)                                (0x00000018&((data)<<3))
#define  DVBC_OPT_U_FFF4_DD2_opt_u_fff4_dd2(data)                                (0x00000007&(data))
#define  DVBC_OPT_U_FFF4_DD2_get_opt_u_fbf3_dd1(data)                            ((0x00000060&(data))>>5)
#define  DVBC_OPT_U_FFF4_DD2_get_opt_u_fbf3_dd0(data)                            ((0x00000018&(data))>>3)
#define  DVBC_OPT_U_FFF4_DD2_get_opt_u_fff4_dd2(data)                            (0x00000007&(data))

#define  DVBC_OPT_U_FBF3_DD2                                                     0x180E8670
#define  DVBC_OPT_U_FBF3_DD2_reg_addr                                            "0xB80E8670"
#define  DVBC_OPT_U_FBF3_DD2_reg                                                 0xB80E8670
#define  DVBC_OPT_U_FBF3_DD2_inst_addr                                           "0x00E4"
#define  set_DVBC_OPT_U_FBF3_DD2_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_U_FBF3_DD2_reg)=data)
#define  get_DVBC_OPT_U_FBF3_DD2_reg                                             (*((volatile unsigned int*)DVBC_OPT_U_FBF3_DD2_reg))
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf4_dd2_shift                                (6)
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf4_dd1_shift                                (4)
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf4_dd0_shift                                (2)
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf3_dd2_shift                                (0)
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf4_dd2_mask                                 (0x000000C0)
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf4_dd1_mask                                 (0x00000030)
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf4_dd0_mask                                 (0x0000000C)
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf3_dd2_mask                                 (0x00000003)
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf4_dd2(data)                                (0x000000C0&((data)<<6))
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf4_dd1(data)                                (0x00000030&((data)<<4))
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf4_dd0(data)                                (0x0000000C&((data)<<2))
#define  DVBC_OPT_U_FBF3_DD2_opt_u_fbf3_dd2(data)                                (0x00000003&(data))
#define  DVBC_OPT_U_FBF3_DD2_get_opt_u_fbf4_dd2(data)                            ((0x000000C0&(data))>>6)
#define  DVBC_OPT_U_FBF3_DD2_get_opt_u_fbf4_dd1(data)                            ((0x00000030&(data))>>4)
#define  DVBC_OPT_U_FBF3_DD2_get_opt_u_fbf4_dd0(data)                            ((0x0000000C&(data))>>2)
#define  DVBC_OPT_U_FBF3_DD2_get_opt_u_fbf3_dd2(data)                            (0x00000003&(data))

#define  DVBC_OPT_FBF_NB_NUM                                                     0x180E8674
#define  DVBC_OPT_FBF_NB_NUM_reg_addr                                            "0xB80E8674"
#define  DVBC_OPT_FBF_NB_NUM_reg                                                 0xB80E8674
#define  DVBC_OPT_FBF_NB_NUM_inst_addr                                           "0x00E5"
#define  set_DVBC_OPT_FBF_NB_NUM_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_FBF_NB_NUM_reg)=data)
#define  get_DVBC_OPT_FBF_NB_NUM_reg                                             (*((volatile unsigned int*)DVBC_OPT_FBF_NB_NUM_reg))
#define  DVBC_OPT_FBF_NB_NUM_opt_fbf_nb_num_shift                                (0)
#define  DVBC_OPT_FBF_NB_NUM_opt_fbf_nb_num_mask                                 (0x00000001)
#define  DVBC_OPT_FBF_NB_NUM_opt_fbf_nb_num(data)                                (0x00000001&(data))
#define  DVBC_OPT_FBF_NB_NUM_get_opt_fbf_nb_num(data)                            (0x00000001&(data))

#define  DVBC_BN_COND6_EN                                                        0x180E8678
#define  DVBC_BN_COND6_EN_reg_addr                                               "0xB80E8678"
#define  DVBC_BN_COND6_EN_reg                                                    0xB80E8678
#define  DVBC_BN_COND6_EN_inst_addr                                              "0x00E6"
#define  set_DVBC_BN_COND6_EN_reg(data)                                          (*((volatile unsigned int*)DVBC_BN_COND6_EN_reg)=data)
#define  get_DVBC_BN_COND6_EN_reg                                                (*((volatile unsigned int*)DVBC_BN_COND6_EN_reg))
#define  DVBC_BN_COND6_EN_bn_cond7_en_shift                                      (1)
#define  DVBC_BN_COND6_EN_bn_cond6_en_shift                                      (0)
#define  DVBC_BN_COND6_EN_bn_cond7_en_mask                                       (0x00000002)
#define  DVBC_BN_COND6_EN_bn_cond6_en_mask                                       (0x00000001)
#define  DVBC_BN_COND6_EN_bn_cond7_en(data)                                      (0x00000002&((data)<<1))
#define  DVBC_BN_COND6_EN_bn_cond6_en(data)                                      (0x00000001&(data))
#define  DVBC_BN_COND6_EN_get_bn_cond7_en(data)                                  ((0x00000002&(data))>>1)
#define  DVBC_BN_COND6_EN_get_bn_cond6_en(data)                                  (0x00000001&(data))

#define  DVBC_OPT_BN_COND6_CNT_TH                                                0x180E867C
#define  DVBC_OPT_BN_COND6_CNT_TH_reg_addr                                       "0xB80E867C"
#define  DVBC_OPT_BN_COND6_CNT_TH_reg                                            0xB80E867C
#define  DVBC_OPT_BN_COND6_CNT_TH_inst_addr                                      "0x00E7"
#define  set_DVBC_OPT_BN_COND6_CNT_TH_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_BN_COND6_CNT_TH_reg)=data)
#define  get_DVBC_OPT_BN_COND6_CNT_TH_reg                                        (*((volatile unsigned int*)DVBC_OPT_BN_COND6_CNT_TH_reg))
#define  DVBC_OPT_BN_COND6_CNT_TH_opt_bn_eq_amp_th_shift                         (3)
#define  DVBC_OPT_BN_COND6_CNT_TH_opt_bn_cond6_cnt_th_shift                      (0)
#define  DVBC_OPT_BN_COND6_CNT_TH_opt_bn_eq_amp_th_mask                          (0x00000078)
#define  DVBC_OPT_BN_COND6_CNT_TH_opt_bn_cond6_cnt_th_mask                       (0x00000007)
#define  DVBC_OPT_BN_COND6_CNT_TH_opt_bn_eq_amp_th(data)                         (0x00000078&((data)<<3))
#define  DVBC_OPT_BN_COND6_CNT_TH_opt_bn_cond6_cnt_th(data)                      (0x00000007&(data))
#define  DVBC_OPT_BN_COND6_CNT_TH_get_opt_bn_eq_amp_th(data)                     ((0x00000078&(data))>>3)
#define  DVBC_OPT_BN_COND6_CNT_TH_get_opt_bn_cond6_cnt_th(data)                  (0x00000007&(data))

#define  DVBC_EQ_TAP_I                                                           0x180E8680
#define  DVBC_EQ_TAP_I_reg_addr                                                  "0xB80E8680"
#define  DVBC_EQ_TAP_I_reg                                                       0xB80E8680
#define  DVBC_EQ_TAP_I_inst_addr                                                 "0x00E8"
#define  set_DVBC_EQ_TAP_I_reg(data)                                             (*((volatile unsigned int*)DVBC_EQ_TAP_I_reg)=data)
#define  get_DVBC_EQ_TAP_I_reg                                                   (*((volatile unsigned int*)DVBC_EQ_TAP_I_reg))
#define  DVBC_EQ_TAP_I_eq_tap_i_7_0_shift                                        (0)
#define  DVBC_EQ_TAP_I_eq_tap_i_7_0_mask                                         (0x000000FF)
#define  DVBC_EQ_TAP_I_eq_tap_i_7_0(data)                                        (0x000000FF&(data))
#define  DVBC_EQ_TAP_I_get_eq_tap_i_7_0(data)                                    (0x000000FF&(data))

#define  DVBC_EQ_TAP_I_1                                                         0x180E8684
#define  DVBC_EQ_TAP_I_1_reg_addr                                                "0xB80E8684"
#define  DVBC_EQ_TAP_I_1_reg                                                     0xB80E8684
#define  DVBC_EQ_TAP_I_1_inst_addr                                               "0x00E9"
#define  set_DVBC_EQ_TAP_I_1_reg(data)                                           (*((volatile unsigned int*)DVBC_EQ_TAP_I_1_reg)=data)
#define  get_DVBC_EQ_TAP_I_1_reg                                                 (*((volatile unsigned int*)DVBC_EQ_TAP_I_1_reg))
#define  DVBC_EQ_TAP_I_1_eq_tap_i_15_8_shift                                     (0)
#define  DVBC_EQ_TAP_I_1_eq_tap_i_15_8_mask                                      (0x000000FF)
#define  DVBC_EQ_TAP_I_1_eq_tap_i_15_8(data)                                     (0x000000FF&(data))
#define  DVBC_EQ_TAP_I_1_get_eq_tap_i_15_8(data)                                 (0x000000FF&(data))

#define  DVBC_EQ_TAP_Q                                                           0x180E8688
#define  DVBC_EQ_TAP_Q_reg_addr                                                  "0xB80E8688"
#define  DVBC_EQ_TAP_Q_reg                                                       0xB80E8688
#define  DVBC_EQ_TAP_Q_inst_addr                                                 "0x00EA"
#define  set_DVBC_EQ_TAP_Q_reg(data)                                             (*((volatile unsigned int*)DVBC_EQ_TAP_Q_reg)=data)
#define  get_DVBC_EQ_TAP_Q_reg                                                   (*((volatile unsigned int*)DVBC_EQ_TAP_Q_reg))
#define  DVBC_EQ_TAP_Q_eq_tap_q_7_0_shift                                        (0)
#define  DVBC_EQ_TAP_Q_eq_tap_q_7_0_mask                                         (0x000000FF)
#define  DVBC_EQ_TAP_Q_eq_tap_q_7_0(data)                                        (0x000000FF&(data))
#define  DVBC_EQ_TAP_Q_get_eq_tap_q_7_0(data)                                    (0x000000FF&(data))

#define  DVBC_EQ_TAP_Q_1                                                         0x180E868C
#define  DVBC_EQ_TAP_Q_1_reg_addr                                                "0xB80E868C"
#define  DVBC_EQ_TAP_Q_1_reg                                                     0xB80E868C
#define  DVBC_EQ_TAP_Q_1_inst_addr                                               "0x00EB"
#define  set_DVBC_EQ_TAP_Q_1_reg(data)                                           (*((volatile unsigned int*)DVBC_EQ_TAP_Q_1_reg)=data)
#define  get_DVBC_EQ_TAP_Q_1_reg                                                 (*((volatile unsigned int*)DVBC_EQ_TAP_Q_1_reg))
#define  DVBC_EQ_TAP_Q_1_eq_tap_q_15_8_shift                                     (0)
#define  DVBC_EQ_TAP_Q_1_eq_tap_q_15_8_mask                                      (0x000000FF)
#define  DVBC_EQ_TAP_Q_1_eq_tap_q_15_8(data)                                     (0x000000FF&(data))
#define  DVBC_EQ_TAP_Q_1_get_eq_tap_q_15_8(data)                                 (0x000000FF&(data))

#define  DVBC_PAGE1_RWB0_RESERVED                                                0x180E86C0
#define  DVBC_PAGE1_RWB0_RESERVED_reg_addr                                       "0xB80E86C0"
#define  DVBC_PAGE1_RWB0_RESERVED_reg                                            0xB80E86C0
#define  DVBC_PAGE1_RWB0_RESERVED_inst_addr                                      "0x00EC"
#define  set_DVBC_PAGE1_RWB0_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE1_RWB0_RESERVED_reg)=data)
#define  get_DVBC_PAGE1_RWB0_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE1_RWB0_RESERVED_reg))
#define  DVBC_PAGE1_RWB0_RESERVED_page1_rwb0_reserved_shift                      (0)
#define  DVBC_PAGE1_RWB0_RESERVED_page1_rwb0_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE1_RWB0_RESERVED_page1_rwb0_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE1_RWB0_RESERVED_get_page1_rwb0_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE1_RWB1_RESERVED                                                0x180E86C4
#define  DVBC_PAGE1_RWB1_RESERVED_reg_addr                                       "0xB80E86C4"
#define  DVBC_PAGE1_RWB1_RESERVED_reg                                            0xB80E86C4
#define  DVBC_PAGE1_RWB1_RESERVED_inst_addr                                      "0x00ED"
#define  set_DVBC_PAGE1_RWB1_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE1_RWB1_RESERVED_reg)=data)
#define  get_DVBC_PAGE1_RWB1_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE1_RWB1_RESERVED_reg))
#define  DVBC_PAGE1_RWB1_RESERVED_page1_rwb1_reserved_shift                      (0)
#define  DVBC_PAGE1_RWB1_RESERVED_page1_rwb1_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE1_RWB1_RESERVED_page1_rwb1_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE1_RWB1_RESERVED_get_page1_rwb1_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE1_RWB2_RESERVED                                                0x180E86C8
#define  DVBC_PAGE1_RWB2_RESERVED_reg_addr                                       "0xB80E86C8"
#define  DVBC_PAGE1_RWB2_RESERVED_reg                                            0xB80E86C8
#define  DVBC_PAGE1_RWB2_RESERVED_inst_addr                                      "0x00EE"
#define  set_DVBC_PAGE1_RWB2_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE1_RWB2_RESERVED_reg)=data)
#define  get_DVBC_PAGE1_RWB2_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE1_RWB2_RESERVED_reg))
#define  DVBC_PAGE1_RWB2_RESERVED_page1_rwb2_reserved_shift                      (0)
#define  DVBC_PAGE1_RWB2_RESERVED_page1_rwb2_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE1_RWB2_RESERVED_page1_rwb2_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE1_RWB2_RESERVED_get_page1_rwb2_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE1_RWB3_RESERVED                                                0x180E86CC
#define  DVBC_PAGE1_RWB3_RESERVED_reg_addr                                       "0xB80E86CC"
#define  DVBC_PAGE1_RWB3_RESERVED_reg                                            0xB80E86CC
#define  DVBC_PAGE1_RWB3_RESERVED_inst_addr                                      "0x00EF"
#define  set_DVBC_PAGE1_RWB3_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE1_RWB3_RESERVED_reg)=data)
#define  get_DVBC_PAGE1_RWB3_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE1_RWB3_RESERVED_reg))
#define  DVBC_PAGE1_RWB3_RESERVED_page1_rwb3_reserved_shift                      (0)
#define  DVBC_PAGE1_RWB3_RESERVED_page1_rwb3_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE1_RWB3_RESERVED_page1_rwb3_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE1_RWB3_RESERVED_get_page1_rwb3_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE1_RWB4_RESERVED                                                0x180E86D0
#define  DVBC_PAGE1_RWB4_RESERVED_reg_addr                                       "0xB80E86D0"
#define  DVBC_PAGE1_RWB4_RESERVED_reg                                            0xB80E86D0
#define  DVBC_PAGE1_RWB4_RESERVED_inst_addr                                      "0x00F0"
#define  set_DVBC_PAGE1_RWB4_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE1_RWB4_RESERVED_reg)=data)
#define  get_DVBC_PAGE1_RWB4_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE1_RWB4_RESERVED_reg))
#define  DVBC_PAGE1_RWB4_RESERVED_page1_rwb4_reserved_shift                      (0)
#define  DVBC_PAGE1_RWB4_RESERVED_page1_rwb4_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE1_RWB4_RESERVED_page1_rwb4_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE1_RWB4_RESERVED_get_page1_rwb4_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE1_RWB5_RESERVED                                                0x180E86D4
#define  DVBC_PAGE1_RWB5_RESERVED_reg_addr                                       "0xB80E86D4"
#define  DVBC_PAGE1_RWB5_RESERVED_reg                                            0xB80E86D4
#define  DVBC_PAGE1_RWB5_RESERVED_inst_addr                                      "0x00F1"
#define  set_DVBC_PAGE1_RWB5_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE1_RWB5_RESERVED_reg)=data)
#define  get_DVBC_PAGE1_RWB5_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE1_RWB5_RESERVED_reg))
#define  DVBC_PAGE1_RWB5_RESERVED_page1_rwb5_reserved_shift                      (0)
#define  DVBC_PAGE1_RWB5_RESERVED_page1_rwb5_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE1_RWB5_RESERVED_page1_rwb5_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE1_RWB5_RESERVED_get_page1_rwb5_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE1_RWB6_RESERVED                                                0x180E86D8
#define  DVBC_PAGE1_RWB6_RESERVED_reg_addr                                       "0xB80E86D8"
#define  DVBC_PAGE1_RWB6_RESERVED_reg                                            0xB80E86D8
#define  DVBC_PAGE1_RWB6_RESERVED_inst_addr                                      "0x00F2"
#define  set_DVBC_PAGE1_RWB6_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE1_RWB6_RESERVED_reg)=data)
#define  get_DVBC_PAGE1_RWB6_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE1_RWB6_RESERVED_reg))
#define  DVBC_PAGE1_RWB6_RESERVED_page1_rwb6_reserved_shift                      (0)
#define  DVBC_PAGE1_RWB6_RESERVED_page1_rwb6_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE1_RWB6_RESERVED_page1_rwb6_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE1_RWB6_RESERVED_get_page1_rwb6_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE1_RWB7_RESERVED                                                0x180E86DC
#define  DVBC_PAGE1_RWB7_RESERVED_reg_addr                                       "0xB80E86DC"
#define  DVBC_PAGE1_RWB7_RESERVED_reg                                            0xB80E86DC
#define  DVBC_PAGE1_RWB7_RESERVED_inst_addr                                      "0x00F3"
#define  set_DVBC_PAGE1_RWB7_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE1_RWB7_RESERVED_reg)=data)
#define  get_DVBC_PAGE1_RWB7_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE1_RWB7_RESERVED_reg))
#define  DVBC_PAGE1_RWB7_RESERVED_page1_rwb7_reserved_shift                      (0)
#define  DVBC_PAGE1_RWB7_RESERVED_page1_rwb7_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE1_RWB7_RESERVED_page1_rwb7_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE1_RWB7_RESERVED_get_page1_rwb7_reserved(data)                  (0x000000FF&(data))

#define  DVBC_OPT_AAGC_IQ_SWAP                                                   0x180E86E0
#define  DVBC_OPT_AAGC_IQ_SWAP_reg_addr                                          "0xB80E86E0"
#define  DVBC_OPT_AAGC_IQ_SWAP_reg                                               0xB80E86E0
#define  DVBC_OPT_AAGC_IQ_SWAP_inst_addr                                         "0x00F4"
#define  set_DVBC_OPT_AAGC_IQ_SWAP_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_AAGC_IQ_SWAP_reg)=data)
#define  get_DVBC_OPT_AAGC_IQ_SWAP_reg                                           (*((volatile unsigned int*)DVBC_OPT_AAGC_IQ_SWAP_reg))
#define  DVBC_OPT_AAGC_IQ_SWAP_opt_adc_im_shift                                  (3)
#define  DVBC_OPT_AAGC_IQ_SWAP_opt_adc_clip_iq_shift                             (1)
#define  DVBC_OPT_AAGC_IQ_SWAP_opt_aagc_iq_swap_shift                            (0)
#define  DVBC_OPT_AAGC_IQ_SWAP_opt_adc_im_mask                                   (0x00000008)
#define  DVBC_OPT_AAGC_IQ_SWAP_opt_adc_clip_iq_mask                              (0x00000006)
#define  DVBC_OPT_AAGC_IQ_SWAP_opt_aagc_iq_swap_mask                             (0x00000001)
#define  DVBC_OPT_AAGC_IQ_SWAP_opt_adc_im(data)                                  (0x00000008&((data)<<3))
#define  DVBC_OPT_AAGC_IQ_SWAP_opt_adc_clip_iq(data)                             (0x00000006&((data)<<1))
#define  DVBC_OPT_AAGC_IQ_SWAP_opt_aagc_iq_swap(data)                            (0x00000001&(data))
#define  DVBC_OPT_AAGC_IQ_SWAP_get_opt_adc_im(data)                              ((0x00000008&(data))>>3)
#define  DVBC_OPT_AAGC_IQ_SWAP_get_opt_adc_clip_iq(data)                         ((0x00000006&(data))>>1)
#define  DVBC_OPT_AAGC_IQ_SWAP_get_opt_aagc_iq_swap(data)                        (0x00000001&(data))

#define  DVBC_OPT_FE_DCC1_EN                                                     0x180E86E4
#define  DVBC_OPT_FE_DCC1_EN_reg_addr                                            "0xB80E86E4"
#define  DVBC_OPT_FE_DCC1_EN_reg                                                 0xB80E86E4
#define  DVBC_OPT_FE_DCC1_EN_inst_addr                                           "0x00F5"
#define  set_DVBC_OPT_FE_DCC1_EN_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_FE_DCC1_EN_reg)=data)
#define  get_DVBC_OPT_FE_DCC1_EN_reg                                             (*((volatile unsigned int*)DVBC_OPT_FE_DCC1_EN_reg))
#define  DVBC_OPT_FE_DCC1_EN_opt_fe_dcc1_max_shift                               (2)
#define  DVBC_OPT_FE_DCC1_EN_opt_fe_dcc1_max_en_shift                            (1)
#define  DVBC_OPT_FE_DCC1_EN_opt_fe_dcc1_en_shift                                (0)
#define  DVBC_OPT_FE_DCC1_EN_opt_fe_dcc1_max_mask                                (0x0000001C)
#define  DVBC_OPT_FE_DCC1_EN_opt_fe_dcc1_max_en_mask                             (0x00000002)
#define  DVBC_OPT_FE_DCC1_EN_opt_fe_dcc1_en_mask                                 (0x00000001)
#define  DVBC_OPT_FE_DCC1_EN_opt_fe_dcc1_max(data)                               (0x0000001C&((data)<<2))
#define  DVBC_OPT_FE_DCC1_EN_opt_fe_dcc1_max_en(data)                            (0x00000002&((data)<<1))
#define  DVBC_OPT_FE_DCC1_EN_opt_fe_dcc1_en(data)                                (0x00000001&(data))
#define  DVBC_OPT_FE_DCC1_EN_get_opt_fe_dcc1_max(data)                           ((0x0000001C&(data))>>2)
#define  DVBC_OPT_FE_DCC1_EN_get_opt_fe_dcc1_max_en(data)                        ((0x00000002&(data))>>1)
#define  DVBC_OPT_FE_DCC1_EN_get_opt_fe_dcc1_en(data)                            (0x00000001&(data))

#define  DVBC_OPT_FE_DCC1_U_ACQ                                                  0x180E86E8
#define  DVBC_OPT_FE_DCC1_U_ACQ_reg_addr                                         "0xB80E86E8"
#define  DVBC_OPT_FE_DCC1_U_ACQ_reg                                              0xB80E86E8
#define  DVBC_OPT_FE_DCC1_U_ACQ_inst_addr                                        "0x00F6"
#define  set_DVBC_OPT_FE_DCC1_U_ACQ_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_FE_DCC1_U_ACQ_reg)=data)
#define  get_DVBC_OPT_FE_DCC1_U_ACQ_reg                                          (*((volatile unsigned int*)DVBC_OPT_FE_DCC1_U_ACQ_reg))
#define  DVBC_OPT_FE_DCC1_U_ACQ_opt_fe_dcc1_u_trk_shift                          (4)
#define  DVBC_OPT_FE_DCC1_U_ACQ_opt_fe_dcc1_u_acq_shift                          (0)
#define  DVBC_OPT_FE_DCC1_U_ACQ_opt_fe_dcc1_u_trk_mask                           (0x000000F0)
#define  DVBC_OPT_FE_DCC1_U_ACQ_opt_fe_dcc1_u_acq_mask                           (0x0000000F)
#define  DVBC_OPT_FE_DCC1_U_ACQ_opt_fe_dcc1_u_trk(data)                          (0x000000F0&((data)<<4))
#define  DVBC_OPT_FE_DCC1_U_ACQ_opt_fe_dcc1_u_acq(data)                          (0x0000000F&(data))
#define  DVBC_OPT_FE_DCC1_U_ACQ_get_opt_fe_dcc1_u_trk(data)                      ((0x000000F0&(data))>>4)
#define  DVBC_OPT_FE_DCC1_U_ACQ_get_opt_fe_dcc1_u_acq(data)                      (0x0000000F&(data))

#define  DVBC_OPT_FE_DCC1_U                                                      0x180E86EC
#define  DVBC_OPT_FE_DCC1_U_reg_addr                                             "0xB80E86EC"
#define  DVBC_OPT_FE_DCC1_U_reg                                                  0xB80E86EC
#define  DVBC_OPT_FE_DCC1_U_inst_addr                                            "0x00F7"
#define  set_DVBC_OPT_FE_DCC1_U_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_FE_DCC1_U_reg)=data)
#define  get_DVBC_OPT_FE_DCC1_U_reg                                              (*((volatile unsigned int*)DVBC_OPT_FE_DCC1_U_reg))
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_acq_dly_prd_shift                        (6)
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_clr_shift                                (4)
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_upd_shift                                (2)
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_u_shift                                  (0)
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_acq_dly_prd_mask                         (0x000000C0)
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_clr_mask                                 (0x00000030)
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_upd_mask                                 (0x0000000C)
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_u_mask                                   (0x00000003)
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_acq_dly_prd(data)                        (0x000000C0&((data)<<6))
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_clr(data)                                (0x00000030&((data)<<4))
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_upd(data)                                (0x0000000C&((data)<<2))
#define  DVBC_OPT_FE_DCC1_U_opt_fe_dcc1_u(data)                                  (0x00000003&(data))
#define  DVBC_OPT_FE_DCC1_U_get_opt_fe_dcc1_acq_dly_prd(data)                    ((0x000000C0&(data))>>6)
#define  DVBC_OPT_FE_DCC1_U_get_opt_fe_dcc1_clr(data)                            ((0x00000030&(data))>>4)
#define  DVBC_OPT_FE_DCC1_U_get_opt_fe_dcc1_upd(data)                            ((0x0000000C&(data))>>2)
#define  DVBC_OPT_FE_DCC1_U_get_opt_fe_dcc1_u(data)                              (0x00000003&(data))

#define  DVBC_OPT_AAGC_LOOP_IN                                                   0x180E86F0
#define  DVBC_OPT_AAGC_LOOP_IN_reg_addr                                          "0xB80E86F0"
#define  DVBC_OPT_AAGC_LOOP_IN_reg                                               0xB80E86F0
#define  DVBC_OPT_AAGC_LOOP_IN_inst_addr                                         "0x00F8"
#define  set_DVBC_OPT_AAGC_LOOP_IN_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_AAGC_LOOP_IN_reg)=data)
#define  get_DVBC_OPT_AAGC_LOOP_IN_reg                                           (*((volatile unsigned int*)DVBC_OPT_AAGC_LOOP_IN_reg))
#define  DVBC_OPT_AAGC_LOOP_IN_zif_spec_inv_on_shift                             (4)
#define  DVBC_OPT_AAGC_LOOP_IN_ddc_zif_mode_shift                                (3)
#define  DVBC_OPT_AAGC_LOOP_IN_opt_aagc_loop_in_shift                            (0)
#define  DVBC_OPT_AAGC_LOOP_IN_zif_spec_inv_on_mask                              (0x00000010)
#define  DVBC_OPT_AAGC_LOOP_IN_ddc_zif_mode_mask                                 (0x00000008)
#define  DVBC_OPT_AAGC_LOOP_IN_opt_aagc_loop_in_mask                             (0x00000007)
#define  DVBC_OPT_AAGC_LOOP_IN_zif_spec_inv_on(data)                             (0x00000010&((data)<<4))
#define  DVBC_OPT_AAGC_LOOP_IN_ddc_zif_mode(data)                                (0x00000008&((data)<<3))
#define  DVBC_OPT_AAGC_LOOP_IN_opt_aagc_loop_in(data)                            (0x00000007&(data))
#define  DVBC_OPT_AAGC_LOOP_IN_get_zif_spec_inv_on(data)                         ((0x00000010&(data))>>4)
#define  DVBC_OPT_AAGC_LOOP_IN_get_ddc_zif_mode(data)                            ((0x00000008&(data))>>3)
#define  DVBC_OPT_AAGC_LOOP_IN_get_opt_aagc_loop_in(data)                        (0x00000007&(data))

#define  DVBC_OPT_FE_DCC2_EN                                                     0x180E86F4
#define  DVBC_OPT_FE_DCC2_EN_reg_addr                                            "0xB80E86F4"
#define  DVBC_OPT_FE_DCC2_EN_reg                                                 0xB80E86F4
#define  DVBC_OPT_FE_DCC2_EN_inst_addr                                           "0x00F9"
#define  set_DVBC_OPT_FE_DCC2_EN_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_FE_DCC2_EN_reg)=data)
#define  get_DVBC_OPT_FE_DCC2_EN_reg                                             (*((volatile unsigned int*)DVBC_OPT_FE_DCC2_EN_reg))
#define  DVBC_OPT_FE_DCC2_EN_opt_fe_dcc2_max_shift                               (2)
#define  DVBC_OPT_FE_DCC2_EN_opt_fe_dcc2_max_en_shift                            (1)
#define  DVBC_OPT_FE_DCC2_EN_opt_fe_dcc2_en_shift                                (0)
#define  DVBC_OPT_FE_DCC2_EN_opt_fe_dcc2_max_mask                                (0x0000001C)
#define  DVBC_OPT_FE_DCC2_EN_opt_fe_dcc2_max_en_mask                             (0x00000002)
#define  DVBC_OPT_FE_DCC2_EN_opt_fe_dcc2_en_mask                                 (0x00000001)
#define  DVBC_OPT_FE_DCC2_EN_opt_fe_dcc2_max(data)                               (0x0000001C&((data)<<2))
#define  DVBC_OPT_FE_DCC2_EN_opt_fe_dcc2_max_en(data)                            (0x00000002&((data)<<1))
#define  DVBC_OPT_FE_DCC2_EN_opt_fe_dcc2_en(data)                                (0x00000001&(data))
#define  DVBC_OPT_FE_DCC2_EN_get_opt_fe_dcc2_max(data)                           ((0x0000001C&(data))>>2)
#define  DVBC_OPT_FE_DCC2_EN_get_opt_fe_dcc2_max_en(data)                        ((0x00000002&(data))>>1)
#define  DVBC_OPT_FE_DCC2_EN_get_opt_fe_dcc2_en(data)                            (0x00000001&(data))

#define  DVBC_OPT_FE_DCC2_U_ACQ                                                  0x180E86F8
#define  DVBC_OPT_FE_DCC2_U_ACQ_reg_addr                                         "0xB80E86F8"
#define  DVBC_OPT_FE_DCC2_U_ACQ_reg                                              0xB80E86F8
#define  DVBC_OPT_FE_DCC2_U_ACQ_inst_addr                                        "0x00FA"
#define  set_DVBC_OPT_FE_DCC2_U_ACQ_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_FE_DCC2_U_ACQ_reg)=data)
#define  get_DVBC_OPT_FE_DCC2_U_ACQ_reg                                          (*((volatile unsigned int*)DVBC_OPT_FE_DCC2_U_ACQ_reg))
#define  DVBC_OPT_FE_DCC2_U_ACQ_opt_fe_dcc2_u_trk_shift                          (4)
#define  DVBC_OPT_FE_DCC2_U_ACQ_opt_fe_dcc2_u_acq_shift                          (0)
#define  DVBC_OPT_FE_DCC2_U_ACQ_opt_fe_dcc2_u_trk_mask                           (0x000000F0)
#define  DVBC_OPT_FE_DCC2_U_ACQ_opt_fe_dcc2_u_acq_mask                           (0x0000000F)
#define  DVBC_OPT_FE_DCC2_U_ACQ_opt_fe_dcc2_u_trk(data)                          (0x000000F0&((data)<<4))
#define  DVBC_OPT_FE_DCC2_U_ACQ_opt_fe_dcc2_u_acq(data)                          (0x0000000F&(data))
#define  DVBC_OPT_FE_DCC2_U_ACQ_get_opt_fe_dcc2_u_trk(data)                      ((0x000000F0&(data))>>4)
#define  DVBC_OPT_FE_DCC2_U_ACQ_get_opt_fe_dcc2_u_acq(data)                      (0x0000000F&(data))

#define  DVBC_OPT_FE_DCC2_U                                                      0x180E86FC
#define  DVBC_OPT_FE_DCC2_U_reg_addr                                             "0xB80E86FC"
#define  DVBC_OPT_FE_DCC2_U_reg                                                  0xB80E86FC
#define  DVBC_OPT_FE_DCC2_U_inst_addr                                            "0x00FB"
#define  set_DVBC_OPT_FE_DCC2_U_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_FE_DCC2_U_reg)=data)
#define  get_DVBC_OPT_FE_DCC2_U_reg                                              (*((volatile unsigned int*)DVBC_OPT_FE_DCC2_U_reg))
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_acq_dly_prd_shift                        (6)
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_clr_shift                                (4)
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_upd_shift                                (2)
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_u_shift                                  (0)
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_acq_dly_prd_mask                         (0x000000C0)
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_clr_mask                                 (0x00000030)
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_upd_mask                                 (0x0000000C)
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_u_mask                                   (0x00000003)
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_acq_dly_prd(data)                        (0x000000C0&((data)<<6))
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_clr(data)                                (0x00000030&((data)<<4))
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_upd(data)                                (0x0000000C&((data)<<2))
#define  DVBC_OPT_FE_DCC2_U_opt_fe_dcc2_u(data)                                  (0x00000003&(data))
#define  DVBC_OPT_FE_DCC2_U_get_opt_fe_dcc2_acq_dly_prd(data)                    ((0x000000C0&(data))>>6)
#define  DVBC_OPT_FE_DCC2_U_get_opt_fe_dcc2_clr(data)                            ((0x00000030&(data))>>4)
#define  DVBC_OPT_FE_DCC2_U_get_opt_fe_dcc2_upd(data)                            ((0x0000000C&(data))>>2)
#define  DVBC_OPT_FE_DCC2_U_get_opt_fe_dcc2_u(data)                              (0x00000003&(data))

#define  DVBC_OPT_FE_DCC3_EN                                                     0x180E8700
#define  DVBC_OPT_FE_DCC3_EN_reg_addr                                            "0xB80E8700"
#define  DVBC_OPT_FE_DCC3_EN_reg                                                 0xB80E8700
#define  DVBC_OPT_FE_DCC3_EN_inst_addr                                           "0x00FC"
#define  set_DVBC_OPT_FE_DCC3_EN_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_FE_DCC3_EN_reg)=data)
#define  get_DVBC_OPT_FE_DCC3_EN_reg                                             (*((volatile unsigned int*)DVBC_OPT_FE_DCC3_EN_reg))
#define  DVBC_OPT_FE_DCC3_EN_opt_fe_dcc3_max_shift                               (2)
#define  DVBC_OPT_FE_DCC3_EN_opt_fe_dcc3_max_en_shift                            (1)
#define  DVBC_OPT_FE_DCC3_EN_opt_fe_dcc3_en_shift                                (0)
#define  DVBC_OPT_FE_DCC3_EN_opt_fe_dcc3_max_mask                                (0x0000001C)
#define  DVBC_OPT_FE_DCC3_EN_opt_fe_dcc3_max_en_mask                             (0x00000002)
#define  DVBC_OPT_FE_DCC3_EN_opt_fe_dcc3_en_mask                                 (0x00000001)
#define  DVBC_OPT_FE_DCC3_EN_opt_fe_dcc3_max(data)                               (0x0000001C&((data)<<2))
#define  DVBC_OPT_FE_DCC3_EN_opt_fe_dcc3_max_en(data)                            (0x00000002&((data)<<1))
#define  DVBC_OPT_FE_DCC3_EN_opt_fe_dcc3_en(data)                                (0x00000001&(data))
#define  DVBC_OPT_FE_DCC3_EN_get_opt_fe_dcc3_max(data)                           ((0x0000001C&(data))>>2)
#define  DVBC_OPT_FE_DCC3_EN_get_opt_fe_dcc3_max_en(data)                        ((0x00000002&(data))>>1)
#define  DVBC_OPT_FE_DCC3_EN_get_opt_fe_dcc3_en(data)                            (0x00000001&(data))

#define  DVBC_OPT_FE_DCC3_U_ACQ                                                  0x180E8704
#define  DVBC_OPT_FE_DCC3_U_ACQ_reg_addr                                         "0xB80E8704"
#define  DVBC_OPT_FE_DCC3_U_ACQ_reg                                              0xB80E8704
#define  DVBC_OPT_FE_DCC3_U_ACQ_inst_addr                                        "0x00FD"
#define  set_DVBC_OPT_FE_DCC3_U_ACQ_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_FE_DCC3_U_ACQ_reg)=data)
#define  get_DVBC_OPT_FE_DCC3_U_ACQ_reg                                          (*((volatile unsigned int*)DVBC_OPT_FE_DCC3_U_ACQ_reg))
#define  DVBC_OPT_FE_DCC3_U_ACQ_opt_fe_dcc3_u_trk_shift                          (4)
#define  DVBC_OPT_FE_DCC3_U_ACQ_opt_fe_dcc3_u_acq_shift                          (0)
#define  DVBC_OPT_FE_DCC3_U_ACQ_opt_fe_dcc3_u_trk_mask                           (0x000000F0)
#define  DVBC_OPT_FE_DCC3_U_ACQ_opt_fe_dcc3_u_acq_mask                           (0x0000000F)
#define  DVBC_OPT_FE_DCC3_U_ACQ_opt_fe_dcc3_u_trk(data)                          (0x000000F0&((data)<<4))
#define  DVBC_OPT_FE_DCC3_U_ACQ_opt_fe_dcc3_u_acq(data)                          (0x0000000F&(data))
#define  DVBC_OPT_FE_DCC3_U_ACQ_get_opt_fe_dcc3_u_trk(data)                      ((0x000000F0&(data))>>4)
#define  DVBC_OPT_FE_DCC3_U_ACQ_get_opt_fe_dcc3_u_acq(data)                      (0x0000000F&(data))

#define  DVBC_OPT_FE_DCC3_U                                                      0x180E8708
#define  DVBC_OPT_FE_DCC3_U_reg_addr                                             "0xB80E8708"
#define  DVBC_OPT_FE_DCC3_U_reg                                                  0xB80E8708
#define  DVBC_OPT_FE_DCC3_U_inst_addr                                            "0x00FE"
#define  set_DVBC_OPT_FE_DCC3_U_reg(data)                                        (*((volatile unsigned int*)DVBC_OPT_FE_DCC3_U_reg)=data)
#define  get_DVBC_OPT_FE_DCC3_U_reg                                              (*((volatile unsigned int*)DVBC_OPT_FE_DCC3_U_reg))
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_acq_dly_prd_shift                        (6)
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_clr_shift                                (4)
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_upd_shift                                (2)
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_u_shift                                  (0)
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_acq_dly_prd_mask                         (0x000000C0)
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_clr_mask                                 (0x00000030)
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_upd_mask                                 (0x0000000C)
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_u_mask                                   (0x00000003)
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_acq_dly_prd(data)                        (0x000000C0&((data)<<6))
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_clr(data)                                (0x00000030&((data)<<4))
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_upd(data)                                (0x0000000C&((data)<<2))
#define  DVBC_OPT_FE_DCC3_U_opt_fe_dcc3_u(data)                                  (0x00000003&(data))
#define  DVBC_OPT_FE_DCC3_U_get_opt_fe_dcc3_acq_dly_prd(data)                    ((0x000000C0&(data))>>6)
#define  DVBC_OPT_FE_DCC3_U_get_opt_fe_dcc3_clr(data)                            ((0x00000030&(data))>>4)
#define  DVBC_OPT_FE_DCC3_U_get_opt_fe_dcc3_upd(data)                            ((0x0000000C&(data))>>2)
#define  DVBC_OPT_FE_DCC3_U_get_opt_fe_dcc3_u(data)                              (0x00000003&(data))

#define  DVBC_OPT_FE_IQ_U                                                        0x180E870C
#define  DVBC_OPT_FE_IQ_U_reg_addr                                               "0xB80E870C"
#define  DVBC_OPT_FE_IQ_U_reg                                                    0xB80E870C
#define  DVBC_OPT_FE_IQ_U_inst_addr                                              "0x00FF"
#define  set_DVBC_OPT_FE_IQ_U_reg(data)                                          (*((volatile unsigned int*)DVBC_OPT_FE_IQ_U_reg)=data)
#define  get_DVBC_OPT_FE_IQ_U_reg                                                (*((volatile unsigned int*)DVBC_OPT_FE_IQ_U_reg))
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_acq_dly_prd_shift                            (6)
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_clr_shift                                    (4)
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_upd_shift                                    (2)
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_u_shift                                      (0)
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_acq_dly_prd_mask                             (0x000000C0)
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_clr_mask                                     (0x00000030)
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_upd_mask                                     (0x0000000C)
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_u_mask                                       (0x00000003)
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_acq_dly_prd(data)                            (0x000000C0&((data)<<6))
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_clr(data)                                    (0x00000030&((data)<<4))
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_upd(data)                                    (0x0000000C&((data)<<2))
#define  DVBC_OPT_FE_IQ_U_opt_fe_iq_u(data)                                      (0x00000003&(data))
#define  DVBC_OPT_FE_IQ_U_get_opt_fe_iq_acq_dly_prd(data)                        ((0x000000C0&(data))>>6)
#define  DVBC_OPT_FE_IQ_U_get_opt_fe_iq_clr(data)                                ((0x00000030&(data))>>4)
#define  DVBC_OPT_FE_IQ_U_get_opt_fe_iq_upd(data)                                ((0x0000000C&(data))>>2)
#define  DVBC_OPT_FE_IQ_U_get_opt_fe_iq_u(data)                                  (0x00000003&(data))

#define  DVBC_OPT_FE_IQAMP_EN                                                    0x180E8710
#define  DVBC_OPT_FE_IQAMP_EN_reg_addr                                           "0xB80E8710"
#define  DVBC_OPT_FE_IQAMP_EN_reg                                                0xB80E8710
#define  DVBC_OPT_FE_IQAMP_EN_inst_addr                                          "0x0100"
#define  set_DVBC_OPT_FE_IQAMP_EN_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_FE_IQAMP_EN_reg)=data)
#define  get_DVBC_OPT_FE_IQAMP_EN_reg                                            (*((volatile unsigned int*)DVBC_OPT_FE_IQAMP_EN_reg))
#define  DVBC_OPT_FE_IQAMP_EN_opt_fe_iqamp_max_shift                             (2)
#define  DVBC_OPT_FE_IQAMP_EN_opt_fe_iqamp_max_en_shift                          (1)
#define  DVBC_OPT_FE_IQAMP_EN_opt_fe_iqamp_en_shift                              (0)
#define  DVBC_OPT_FE_IQAMP_EN_opt_fe_iqamp_max_mask                              (0x0000001C)
#define  DVBC_OPT_FE_IQAMP_EN_opt_fe_iqamp_max_en_mask                           (0x00000002)
#define  DVBC_OPT_FE_IQAMP_EN_opt_fe_iqamp_en_mask                               (0x00000001)
#define  DVBC_OPT_FE_IQAMP_EN_opt_fe_iqamp_max(data)                             (0x0000001C&((data)<<2))
#define  DVBC_OPT_FE_IQAMP_EN_opt_fe_iqamp_max_en(data)                          (0x00000002&((data)<<1))
#define  DVBC_OPT_FE_IQAMP_EN_opt_fe_iqamp_en(data)                              (0x00000001&(data))
#define  DVBC_OPT_FE_IQAMP_EN_get_opt_fe_iqamp_max(data)                         ((0x0000001C&(data))>>2)
#define  DVBC_OPT_FE_IQAMP_EN_get_opt_fe_iqamp_max_en(data)                      ((0x00000002&(data))>>1)
#define  DVBC_OPT_FE_IQAMP_EN_get_opt_fe_iqamp_en(data)                          (0x00000001&(data))

#define  DVBC_OPT_FE_IQAMP_U_ACQ                                                 0x180E8714
#define  DVBC_OPT_FE_IQAMP_U_ACQ_reg_addr                                        "0xB80E8714"
#define  DVBC_OPT_FE_IQAMP_U_ACQ_reg                                             0xB80E8714
#define  DVBC_OPT_FE_IQAMP_U_ACQ_inst_addr                                       "0x0101"
#define  set_DVBC_OPT_FE_IQAMP_U_ACQ_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_FE_IQAMP_U_ACQ_reg)=data)
#define  get_DVBC_OPT_FE_IQAMP_U_ACQ_reg                                         (*((volatile unsigned int*)DVBC_OPT_FE_IQAMP_U_ACQ_reg))
#define  DVBC_OPT_FE_IQAMP_U_ACQ_opt_fe_iqamp_u_trk_shift                        (4)
#define  DVBC_OPT_FE_IQAMP_U_ACQ_opt_fe_iqamp_u_acq_shift                        (0)
#define  DVBC_OPT_FE_IQAMP_U_ACQ_opt_fe_iqamp_u_trk_mask                         (0x000000F0)
#define  DVBC_OPT_FE_IQAMP_U_ACQ_opt_fe_iqamp_u_acq_mask                         (0x0000000F)
#define  DVBC_OPT_FE_IQAMP_U_ACQ_opt_fe_iqamp_u_trk(data)                        (0x000000F0&((data)<<4))
#define  DVBC_OPT_FE_IQAMP_U_ACQ_opt_fe_iqamp_u_acq(data)                        (0x0000000F&(data))
#define  DVBC_OPT_FE_IQAMP_U_ACQ_get_opt_fe_iqamp_u_trk(data)                    ((0x000000F0&(data))>>4)
#define  DVBC_OPT_FE_IQAMP_U_ACQ_get_opt_fe_iqamp_u_acq(data)                    (0x0000000F&(data))

#define  DVBC_OPT_FE_IQAMP_MANU_EN                                               0x180E8718
#define  DVBC_OPT_FE_IQAMP_MANU_EN_reg_addr                                      "0xB80E8718"
#define  DVBC_OPT_FE_IQAMP_MANU_EN_reg                                           0xB80E8718
#define  DVBC_OPT_FE_IQAMP_MANU_EN_inst_addr                                     "0x0102"
#define  set_DVBC_OPT_FE_IQAMP_MANU_EN_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_FE_IQAMP_MANU_EN_reg)=data)
#define  get_DVBC_OPT_FE_IQAMP_MANU_EN_reg                                       (*((volatile unsigned int*)DVBC_OPT_FE_IQAMP_MANU_EN_reg))
#define  DVBC_OPT_FE_IQAMP_MANU_EN_opt_fe_iqamp_manu_6_0_shift                   (1)
#define  DVBC_OPT_FE_IQAMP_MANU_EN_opt_fe_iqamp_manu_en_shift                    (0)
#define  DVBC_OPT_FE_IQAMP_MANU_EN_opt_fe_iqamp_manu_6_0_mask                    (0x000000FE)
#define  DVBC_OPT_FE_IQAMP_MANU_EN_opt_fe_iqamp_manu_en_mask                     (0x00000001)
#define  DVBC_OPT_FE_IQAMP_MANU_EN_opt_fe_iqamp_manu_6_0(data)                   (0x000000FE&((data)<<1))
#define  DVBC_OPT_FE_IQAMP_MANU_EN_opt_fe_iqamp_manu_en(data)                    (0x00000001&(data))
#define  DVBC_OPT_FE_IQAMP_MANU_EN_get_opt_fe_iqamp_manu_6_0(data)               ((0x000000FE&(data))>>1)
#define  DVBC_OPT_FE_IQAMP_MANU_EN_get_opt_fe_iqamp_manu_en(data)                (0x00000001&(data))

#define  DVBC_OPT_FE_IQAMP_MANU_EN_1                                             0x180E871C
#define  DVBC_OPT_FE_IQAMP_MANU_EN_1_reg_addr                                    "0xB80E871C"
#define  DVBC_OPT_FE_IQAMP_MANU_EN_1_reg                                         0xB80E871C
#define  DVBC_OPT_FE_IQAMP_MANU_EN_1_inst_addr                                   "0x0103"
#define  set_DVBC_OPT_FE_IQAMP_MANU_EN_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_FE_IQAMP_MANU_EN_1_reg)=data)
#define  get_DVBC_OPT_FE_IQAMP_MANU_EN_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_FE_IQAMP_MANU_EN_1_reg))
#define  DVBC_OPT_FE_IQAMP_MANU_EN_1_opt_fe_iqamp_manu_9_7_shift                 (0)
#define  DVBC_OPT_FE_IQAMP_MANU_EN_1_opt_fe_iqamp_manu_9_7_mask                  (0x00000007)
#define  DVBC_OPT_FE_IQAMP_MANU_EN_1_opt_fe_iqamp_manu_9_7(data)                 (0x00000007&(data))
#define  DVBC_OPT_FE_IQAMP_MANU_EN_1_get_opt_fe_iqamp_manu_9_7(data)             (0x00000007&(data))

#define  DVBC_OPT_FE_IQPH_EN                                                     0x180E8720
#define  DVBC_OPT_FE_IQPH_EN_reg_addr                                            "0xB80E8720"
#define  DVBC_OPT_FE_IQPH_EN_reg                                                 0xB80E8720
#define  DVBC_OPT_FE_IQPH_EN_inst_addr                                           "0x0104"
#define  set_DVBC_OPT_FE_IQPH_EN_reg(data)                                       (*((volatile unsigned int*)DVBC_OPT_FE_IQPH_EN_reg)=data)
#define  get_DVBC_OPT_FE_IQPH_EN_reg                                             (*((volatile unsigned int*)DVBC_OPT_FE_IQPH_EN_reg))
#define  DVBC_OPT_FE_IQPH_EN_opt_fe_iqph_max_shift                               (2)
#define  DVBC_OPT_FE_IQPH_EN_opt_fe_iqph_max_en_shift                            (1)
#define  DVBC_OPT_FE_IQPH_EN_opt_fe_iqph_en_shift                                (0)
#define  DVBC_OPT_FE_IQPH_EN_opt_fe_iqph_max_mask                                (0x0000001C)
#define  DVBC_OPT_FE_IQPH_EN_opt_fe_iqph_max_en_mask                             (0x00000002)
#define  DVBC_OPT_FE_IQPH_EN_opt_fe_iqph_en_mask                                 (0x00000001)
#define  DVBC_OPT_FE_IQPH_EN_opt_fe_iqph_max(data)                               (0x0000001C&((data)<<2))
#define  DVBC_OPT_FE_IQPH_EN_opt_fe_iqph_max_en(data)                            (0x00000002&((data)<<1))
#define  DVBC_OPT_FE_IQPH_EN_opt_fe_iqph_en(data)                                (0x00000001&(data))
#define  DVBC_OPT_FE_IQPH_EN_get_opt_fe_iqph_max(data)                           ((0x0000001C&(data))>>2)
#define  DVBC_OPT_FE_IQPH_EN_get_opt_fe_iqph_max_en(data)                        ((0x00000002&(data))>>1)
#define  DVBC_OPT_FE_IQPH_EN_get_opt_fe_iqph_en(data)                            (0x00000001&(data))

#define  DVBC_OPT_FE_IQPH_U_ACQ                                                  0x180E8724
#define  DVBC_OPT_FE_IQPH_U_ACQ_reg_addr                                         "0xB80E8724"
#define  DVBC_OPT_FE_IQPH_U_ACQ_reg                                              0xB80E8724
#define  DVBC_OPT_FE_IQPH_U_ACQ_inst_addr                                        "0x0105"
#define  set_DVBC_OPT_FE_IQPH_U_ACQ_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_FE_IQPH_U_ACQ_reg)=data)
#define  get_DVBC_OPT_FE_IQPH_U_ACQ_reg                                          (*((volatile unsigned int*)DVBC_OPT_FE_IQPH_U_ACQ_reg))
#define  DVBC_OPT_FE_IQPH_U_ACQ_opt_fe_iqph_u_trk_shift                          (4)
#define  DVBC_OPT_FE_IQPH_U_ACQ_opt_fe_iqph_u_acq_shift                          (0)
#define  DVBC_OPT_FE_IQPH_U_ACQ_opt_fe_iqph_u_trk_mask                           (0x000000F0)
#define  DVBC_OPT_FE_IQPH_U_ACQ_opt_fe_iqph_u_acq_mask                           (0x0000000F)
#define  DVBC_OPT_FE_IQPH_U_ACQ_opt_fe_iqph_u_trk(data)                          (0x000000F0&((data)<<4))
#define  DVBC_OPT_FE_IQPH_U_ACQ_opt_fe_iqph_u_acq(data)                          (0x0000000F&(data))
#define  DVBC_OPT_FE_IQPH_U_ACQ_get_opt_fe_iqph_u_trk(data)                      ((0x000000F0&(data))>>4)
#define  DVBC_OPT_FE_IQPH_U_ACQ_get_opt_fe_iqph_u_acq(data)                      (0x0000000F&(data))

#define  DVBC_OPT_FE_IQPH_MANU_EN                                                0x180E8728
#define  DVBC_OPT_FE_IQPH_MANU_EN_reg_addr                                       "0xB80E8728"
#define  DVBC_OPT_FE_IQPH_MANU_EN_reg                                            0xB80E8728
#define  DVBC_OPT_FE_IQPH_MANU_EN_inst_addr                                      "0x0106"
#define  set_DVBC_OPT_FE_IQPH_MANU_EN_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_FE_IQPH_MANU_EN_reg)=data)
#define  get_DVBC_OPT_FE_IQPH_MANU_EN_reg                                        (*((volatile unsigned int*)DVBC_OPT_FE_IQPH_MANU_EN_reg))
#define  DVBC_OPT_FE_IQPH_MANU_EN_opt_fe_iqph_manu_6_0_shift                     (1)
#define  DVBC_OPT_FE_IQPH_MANU_EN_opt_fe_iqph_manu_en_shift                      (0)
#define  DVBC_OPT_FE_IQPH_MANU_EN_opt_fe_iqph_manu_6_0_mask                      (0x000000FE)
#define  DVBC_OPT_FE_IQPH_MANU_EN_opt_fe_iqph_manu_en_mask                       (0x00000001)
#define  DVBC_OPT_FE_IQPH_MANU_EN_opt_fe_iqph_manu_6_0(data)                     (0x000000FE&((data)<<1))
#define  DVBC_OPT_FE_IQPH_MANU_EN_opt_fe_iqph_manu_en(data)                      (0x00000001&(data))
#define  DVBC_OPT_FE_IQPH_MANU_EN_get_opt_fe_iqph_manu_6_0(data)                 ((0x000000FE&(data))>>1)
#define  DVBC_OPT_FE_IQPH_MANU_EN_get_opt_fe_iqph_manu_en(data)                  (0x00000001&(data))

#define  DVBC_OPT_FE_IQPH_MANU_EN_1                                              0x180E872C
#define  DVBC_OPT_FE_IQPH_MANU_EN_1_reg_addr                                     "0xB80E872C"
#define  DVBC_OPT_FE_IQPH_MANU_EN_1_reg                                          0xB80E872C
#define  DVBC_OPT_FE_IQPH_MANU_EN_1_inst_addr                                    "0x0107"
#define  set_DVBC_OPT_FE_IQPH_MANU_EN_1_reg(data)                                (*((volatile unsigned int*)DVBC_OPT_FE_IQPH_MANU_EN_1_reg)=data)
#define  get_DVBC_OPT_FE_IQPH_MANU_EN_1_reg                                      (*((volatile unsigned int*)DVBC_OPT_FE_IQPH_MANU_EN_1_reg))
#define  DVBC_OPT_FE_IQPH_MANU_EN_1_opt_fe_iqph_manu_9_7_shift                   (0)
#define  DVBC_OPT_FE_IQPH_MANU_EN_1_opt_fe_iqph_manu_9_7_mask                    (0x00000007)
#define  DVBC_OPT_FE_IQPH_MANU_EN_1_opt_fe_iqph_manu_9_7(data)                   (0x00000007&(data))
#define  DVBC_OPT_FE_IQPH_MANU_EN_1_get_opt_fe_iqph_manu_9_7(data)               (0x00000007&(data))

#define  DVBC_FSM_WORD_11                                                        0x180E8730
#define  DVBC_FSM_WORD_11_reg_addr                                               "0xB80E8730"
#define  DVBC_FSM_WORD_11_reg                                                    0xB80E8730
#define  DVBC_FSM_WORD_11_inst_addr                                              "0x0108"
#define  set_DVBC_FSM_WORD_11_reg(data)                                          (*((volatile unsigned int*)DVBC_FSM_WORD_11_reg)=data)
#define  get_DVBC_FSM_WORD_11_reg                                                (*((volatile unsigned int*)DVBC_FSM_WORD_11_reg))
#define  DVBC_FSM_WORD_11_fsm_word_r_90_88_shift                                 (8)
#define  DVBC_FSM_WORD_11_fsm_word_90_88_shift                                   (0)
#define  DVBC_FSM_WORD_11_fsm_word_r_90_88_mask                                  (0x00000700)
#define  DVBC_FSM_WORD_11_fsm_word_90_88_mask                                    (0x00000007)
#define  DVBC_FSM_WORD_11_fsm_word_r_90_88(data)                                 (0x00000700&((data)<<8))
#define  DVBC_FSM_WORD_11_fsm_word_90_88(data)                                   (0x00000007&(data))
#define  DVBC_FSM_WORD_11_get_fsm_word_r_90_88(data)                             ((0x00000700&(data))>>8)
#define  DVBC_FSM_WORD_11_get_fsm_word_90_88(data)                               (0x00000007&(data))

#define  DVBC_VERSION_DVBC_OUTER                                                 0x180E8804
#define  DVBC_VERSION_DVBC_OUTER_reg_addr                                        "0xB80E8804"
#define  DVBC_VERSION_DVBC_OUTER_reg                                             0xB80E8804
#define  DVBC_VERSION_DVBC_OUTER_inst_addr                                       "0x0109"
#define  set_DVBC_VERSION_DVBC_OUTER_reg(data)                                   (*((volatile unsigned int*)DVBC_VERSION_DVBC_OUTER_reg)=data)
#define  get_DVBC_VERSION_DVBC_OUTER_reg                                         (*((volatile unsigned int*)DVBC_VERSION_DVBC_OUTER_reg))
#define  DVBC_VERSION_DVBC_OUTER_version_dvbc_outer_shift                        (0)
#define  DVBC_VERSION_DVBC_OUTER_version_dvbc_outer_mask                         (0x000000FF)
#define  DVBC_VERSION_DVBC_OUTER_version_dvbc_outer(data)                        (0x000000FF&(data))
#define  DVBC_VERSION_DVBC_OUTER_get_version_dvbc_outer(data)                    (0x000000FF&(data))

#define  DVBC_OPT_FREEZE                                                         0x180E8808
#define  DVBC_OPT_FREEZE_reg_addr                                                "0xB80E8808"
#define  DVBC_OPT_FREEZE_reg                                                     0xB80E8808
#define  DVBC_OPT_FREEZE_inst_addr                                               "0x010A"
#define  set_DVBC_OPT_FREEZE_reg(data)                                           (*((volatile unsigned int*)DVBC_OPT_FREEZE_reg)=data)
#define  get_DVBC_OPT_FREEZE_reg                                                 (*((volatile unsigned int*)DVBC_OPT_FREEZE_reg))
#define  DVBC_OPT_FREEZE_synclost_shift                                          (7)
#define  DVBC_OPT_FREEZE_opt_trk_mode_shift                                      (5)
#define  DVBC_OPT_FREEZE_opt_acq_mode_shift                                      (3)
#define  DVBC_OPT_FREEZE_opt_mismatch_bit_num_shift                              (1)
#define  DVBC_OPT_FREEZE_opt_freeze_shift                                        (0)
#define  DVBC_OPT_FREEZE_synclost_mask                                           (0x00000080)
#define  DVBC_OPT_FREEZE_opt_trk_mode_mask                                       (0x00000060)
#define  DVBC_OPT_FREEZE_opt_acq_mode_mask                                       (0x00000018)
#define  DVBC_OPT_FREEZE_opt_mismatch_bit_num_mask                               (0x00000006)
#define  DVBC_OPT_FREEZE_opt_freeze_mask                                         (0x00000001)
#define  DVBC_OPT_FREEZE_synclost(data)                                          (0x00000080&((data)<<7))
#define  DVBC_OPT_FREEZE_opt_trk_mode(data)                                      (0x00000060&((data)<<5))
#define  DVBC_OPT_FREEZE_opt_acq_mode(data)                                      (0x00000018&((data)<<3))
#define  DVBC_OPT_FREEZE_opt_mismatch_bit_num(data)                              (0x00000006&((data)<<1))
#define  DVBC_OPT_FREEZE_opt_freeze(data)                                        (0x00000001&(data))
#define  DVBC_OPT_FREEZE_get_synclost(data)                                      ((0x00000080&(data))>>7)
#define  DVBC_OPT_FREEZE_get_opt_trk_mode(data)                                  ((0x00000060&(data))>>5)
#define  DVBC_OPT_FREEZE_get_opt_acq_mode(data)                                  ((0x00000018&(data))>>3)
#define  DVBC_OPT_FREEZE_get_opt_mismatch_bit_num(data)                          ((0x00000006&(data))>>1)
#define  DVBC_OPT_FREEZE_get_opt_freeze(data)                                    (0x00000001&(data))

#define  DVBC_OPT_DEINTL_I                                                       0x180E880C
#define  DVBC_OPT_DEINTL_I_reg_addr                                              "0xB80E880C"
#define  DVBC_OPT_DEINTL_I_reg                                                   0xB80E880C
#define  DVBC_OPT_DEINTL_I_inst_addr                                             "0x010B"
#define  set_DVBC_OPT_DEINTL_I_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_DEINTL_I_reg)=data)
#define  get_DVBC_OPT_DEINTL_I_reg                                               (*((volatile unsigned int*)DVBC_OPT_DEINTL_I_reg))
#define  DVBC_OPT_DEINTL_I_opt_deintl_i_shift                                    (0)
#define  DVBC_OPT_DEINTL_I_opt_deintl_i_mask                                     (0x0000007F)
#define  DVBC_OPT_DEINTL_I_opt_deintl_i(data)                                    (0x0000007F&(data))
#define  DVBC_OPT_DEINTL_I_get_opt_deintl_i(data)                                (0x0000007F&(data))

#define  DVBC_OPT_DEINTL_M                                                       0x180E8810
#define  DVBC_OPT_DEINTL_M_reg_addr                                              "0xB80E8810"
#define  DVBC_OPT_DEINTL_M_reg                                                   0xB80E8810
#define  DVBC_OPT_DEINTL_M_inst_addr                                             "0x010C"
#define  set_DVBC_OPT_DEINTL_M_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_DEINTL_M_reg)=data)
#define  get_DVBC_OPT_DEINTL_M_reg                                               (*((volatile unsigned int*)DVBC_OPT_DEINTL_M_reg))
#define  DVBC_OPT_DEINTL_M_opt_deintl_m_shift                                    (0)
#define  DVBC_OPT_DEINTL_M_opt_deintl_m_mask                                     (0x0000001F)
#define  DVBC_OPT_DEINTL_M_opt_deintl_m(data)                                    (0x0000001F&(data))
#define  DVBC_OPT_DEINTL_M_get_opt_deintl_m(data)                                (0x0000001F&(data))

#define  DVBC_OPT_RSD_DISABLE                                                    0x180E8814
#define  DVBC_OPT_RSD_DISABLE_reg_addr                                           "0xB80E8814"
#define  DVBC_OPT_RSD_DISABLE_reg                                                0xB80E8814
#define  DVBC_OPT_RSD_DISABLE_inst_addr                                          "0x010D"
#define  set_DVBC_OPT_RSD_DISABLE_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_RSD_DISABLE_reg)=data)
#define  get_DVBC_OPT_RSD_DISABLE_reg                                            (*((volatile unsigned int*)DVBC_OPT_RSD_DISABLE_reg))
#define  DVBC_OPT_RSD_DISABLE_opt_ber_rd_strobe_shift                            (7)
#define  DVBC_OPT_RSD_DISABLE_opt_errmode_shift                                  (2)
#define  DVBC_OPT_RSD_DISABLE_opt_nocorr_shift                                   (1)
#define  DVBC_OPT_RSD_DISABLE_opt_rsd_disable_shift                              (0)
#define  DVBC_OPT_RSD_DISABLE_opt_ber_rd_strobe_mask                             (0x00000080)
#define  DVBC_OPT_RSD_DISABLE_opt_errmode_mask                                   (0x00000004)
#define  DVBC_OPT_RSD_DISABLE_opt_nocorr_mask                                    (0x00000002)
#define  DVBC_OPT_RSD_DISABLE_opt_rsd_disable_mask                               (0x00000001)
#define  DVBC_OPT_RSD_DISABLE_opt_ber_rd_strobe(data)                            (0x00000080&((data)<<7))
#define  DVBC_OPT_RSD_DISABLE_opt_errmode(data)                                  (0x00000004&((data)<<2))
#define  DVBC_OPT_RSD_DISABLE_opt_nocorr(data)                                   (0x00000002&((data)<<1))
#define  DVBC_OPT_RSD_DISABLE_opt_rsd_disable(data)                              (0x00000001&(data))
#define  DVBC_OPT_RSD_DISABLE_get_opt_ber_rd_strobe(data)                        ((0x00000080&(data))>>7)
#define  DVBC_OPT_RSD_DISABLE_get_opt_errmode(data)                              ((0x00000004&(data))>>2)
#define  DVBC_OPT_RSD_DISABLE_get_opt_nocorr(data)                               ((0x00000002&(data))>>1)
#define  DVBC_OPT_RSD_DISABLE_get_opt_rsd_disable(data)                          (0x00000001&(data))

#define  DVBC_OPT_BER_EN                                                         0x180E8818
#define  DVBC_OPT_BER_EN_reg_addr                                                "0xB80E8818"
#define  DVBC_OPT_BER_EN_reg                                                     0xB80E8818
#define  DVBC_OPT_BER_EN_inst_addr                                               "0x010E"
#define  set_DVBC_OPT_BER_EN_reg(data)                                           (*((volatile unsigned int*)DVBC_OPT_BER_EN_reg)=data)
#define  get_DVBC_OPT_BER_EN_reg                                                 (*((volatile unsigned int*)DVBC_OPT_BER_EN_reg))
#define  DVBC_OPT_BER_EN_ber_en_stb_shift                                        (6)
#define  DVBC_OPT_BER_EN_opt_volume_shift                                        (3)
#define  DVBC_OPT_BER_EN_opt_dis_auto_mode_shift                                 (2)
#define  DVBC_OPT_BER_EN_opt_ber_hold_shift                                      (1)
#define  DVBC_OPT_BER_EN_opt_ber_en_shift                                        (0)
#define  DVBC_OPT_BER_EN_ber_en_stb_mask                                         (0x00000040)
#define  DVBC_OPT_BER_EN_opt_volume_mask                                         (0x00000038)
#define  DVBC_OPT_BER_EN_opt_dis_auto_mode_mask                                  (0x00000004)
#define  DVBC_OPT_BER_EN_opt_ber_hold_mask                                       (0x00000002)
#define  DVBC_OPT_BER_EN_opt_ber_en_mask                                         (0x00000001)
#define  DVBC_OPT_BER_EN_ber_en_stb(data)                                        (0x00000040&((data)<<6))
#define  DVBC_OPT_BER_EN_opt_volume(data)                                        (0x00000038&((data)<<3))
#define  DVBC_OPT_BER_EN_opt_dis_auto_mode(data)                                 (0x00000004&((data)<<2))
#define  DVBC_OPT_BER_EN_opt_ber_hold(data)                                      (0x00000002&((data)<<1))
#define  DVBC_OPT_BER_EN_opt_ber_en(data)                                        (0x00000001&(data))
#define  DVBC_OPT_BER_EN_get_ber_en_stb(data)                                    ((0x00000040&(data))>>6)
#define  DVBC_OPT_BER_EN_get_opt_volume(data)                                    ((0x00000038&(data))>>3)
#define  DVBC_OPT_BER_EN_get_opt_dis_auto_mode(data)                             ((0x00000004&(data))>>2)
#define  DVBC_OPT_BER_EN_get_opt_ber_hold(data)                                  ((0x00000002&(data))>>1)
#define  DVBC_OPT_BER_EN_get_opt_ber_en(data)                                    (0x00000001&(data))

#define  DVBC_BER_COUNT                                                          0x180E881C
#define  DVBC_BER_COUNT_reg_addr                                                 "0xB80E881C"
#define  DVBC_BER_COUNT_reg                                                      0xB80E881C
#define  DVBC_BER_COUNT_inst_addr                                                "0x010F"
#define  set_DVBC_BER_COUNT_reg(data)                                            (*((volatile unsigned int*)DVBC_BER_COUNT_reg)=data)
#define  get_DVBC_BER_COUNT_reg                                                  (*((volatile unsigned int*)DVBC_BER_COUNT_reg))
#define  DVBC_BER_COUNT_ber_count_7_0_shift                                      (0)
#define  DVBC_BER_COUNT_ber_count_7_0_mask                                       (0x000000FF)
#define  DVBC_BER_COUNT_ber_count_7_0(data)                                      (0x000000FF&(data))
#define  DVBC_BER_COUNT_get_ber_count_7_0(data)                                  (0x000000FF&(data))

#define  DVBC_BER_COUNT_1                                                        0x180E8820
#define  DVBC_BER_COUNT_1_reg_addr                                               "0xB80E8820"
#define  DVBC_BER_COUNT_1_reg                                                    0xB80E8820
#define  DVBC_BER_COUNT_1_inst_addr                                              "0x0110"
#define  set_DVBC_BER_COUNT_1_reg(data)                                          (*((volatile unsigned int*)DVBC_BER_COUNT_1_reg)=data)
#define  get_DVBC_BER_COUNT_1_reg                                                (*((volatile unsigned int*)DVBC_BER_COUNT_1_reg))
#define  DVBC_BER_COUNT_1_ber_count_15_8_shift                                   (0)
#define  DVBC_BER_COUNT_1_ber_count_15_8_mask                                    (0x000000FF)
#define  DVBC_BER_COUNT_1_ber_count_15_8(data)                                   (0x000000FF&(data))
#define  DVBC_BER_COUNT_1_get_ber_count_15_8(data)                               (0x000000FF&(data))

#define  DVBC_BER_COUNT_2                                                        0x180E8824
#define  DVBC_BER_COUNT_2_reg_addr                                               "0xB80E8824"
#define  DVBC_BER_COUNT_2_reg                                                    0xB80E8824
#define  DVBC_BER_COUNT_2_inst_addr                                              "0x0111"
#define  set_DVBC_BER_COUNT_2_reg(data)                                          (*((volatile unsigned int*)DVBC_BER_COUNT_2_reg)=data)
#define  get_DVBC_BER_COUNT_2_reg                                                (*((volatile unsigned int*)DVBC_BER_COUNT_2_reg))
#define  DVBC_BER_COUNT_2_block_count_18_16_shift                                (5)
#define  DVBC_BER_COUNT_2_ber_count_20_16_shift                                  (0)
#define  DVBC_BER_COUNT_2_block_count_18_16_mask                                 (0x000000E0)
#define  DVBC_BER_COUNT_2_ber_count_20_16_mask                                   (0x0000001F)
#define  DVBC_BER_COUNT_2_block_count_18_16(data)                                (0x000000E0&((data)<<5))
#define  DVBC_BER_COUNT_2_ber_count_20_16(data)                                  (0x0000001F&(data))
#define  DVBC_BER_COUNT_2_get_block_count_18_16(data)                            ((0x000000E0&(data))>>5)
#define  DVBC_BER_COUNT_2_get_ber_count_20_16(data)                              (0x0000001F&(data))

#define  DVBC_BLOCK_COUNT                                                        0x180E8828
#define  DVBC_BLOCK_COUNT_reg_addr                                               "0xB80E8828"
#define  DVBC_BLOCK_COUNT_reg                                                    0xB80E8828
#define  DVBC_BLOCK_COUNT_inst_addr                                              "0x0112"
#define  set_DVBC_BLOCK_COUNT_reg(data)                                          (*((volatile unsigned int*)DVBC_BLOCK_COUNT_reg)=data)
#define  get_DVBC_BLOCK_COUNT_reg                                                (*((volatile unsigned int*)DVBC_BLOCK_COUNT_reg))
#define  DVBC_BLOCK_COUNT_block_count_7_0_shift                                  (0)
#define  DVBC_BLOCK_COUNT_block_count_7_0_mask                                   (0x000000FF)
#define  DVBC_BLOCK_COUNT_block_count_7_0(data)                                  (0x000000FF&(data))
#define  DVBC_BLOCK_COUNT_get_block_count_7_0(data)                              (0x000000FF&(data))

#define  DVBC_BLOCK_COUNT_1                                                      0x180E882C
#define  DVBC_BLOCK_COUNT_1_reg_addr                                             "0xB80E882C"
#define  DVBC_BLOCK_COUNT_1_reg                                                  0xB80E882C
#define  DVBC_BLOCK_COUNT_1_inst_addr                                            "0x0113"
#define  set_DVBC_BLOCK_COUNT_1_reg(data)                                        (*((volatile unsigned int*)DVBC_BLOCK_COUNT_1_reg)=data)
#define  get_DVBC_BLOCK_COUNT_1_reg                                              (*((volatile unsigned int*)DVBC_BLOCK_COUNT_1_reg))
#define  DVBC_BLOCK_COUNT_1_block_count_15_8_shift                               (0)
#define  DVBC_BLOCK_COUNT_1_block_count_15_8_mask                                (0x000000FF)
#define  DVBC_BLOCK_COUNT_1_block_count_15_8(data)                               (0x000000FF&(data))
#define  DVBC_BLOCK_COUNT_1_get_block_count_15_8(data)                           (0x000000FF&(data))

#define  DVBC_CORR_COUNT                                                         0x180E8830
#define  DVBC_CORR_COUNT_reg_addr                                                "0xB80E8830"
#define  DVBC_CORR_COUNT_reg                                                     0xB80E8830
#define  DVBC_CORR_COUNT_inst_addr                                               "0x0114"
#define  set_DVBC_CORR_COUNT_reg(data)                                           (*((volatile unsigned int*)DVBC_CORR_COUNT_reg)=data)
#define  get_DVBC_CORR_COUNT_reg                                                 (*((volatile unsigned int*)DVBC_CORR_COUNT_reg))
#define  DVBC_CORR_COUNT_corr_count_7_0_shift                                    (0)
#define  DVBC_CORR_COUNT_corr_count_7_0_mask                                     (0x000000FF)
#define  DVBC_CORR_COUNT_corr_count_7_0(data)                                    (0x000000FF&(data))
#define  DVBC_CORR_COUNT_get_corr_count_7_0(data)                                (0x000000FF&(data))

#define  DVBC_CORR_COUNT_1                                                       0x180E8834
#define  DVBC_CORR_COUNT_1_reg_addr                                              "0xB80E8834"
#define  DVBC_CORR_COUNT_1_reg                                                   0xB80E8834
#define  DVBC_CORR_COUNT_1_inst_addr                                             "0x0115"
#define  set_DVBC_CORR_COUNT_1_reg(data)                                         (*((volatile unsigned int*)DVBC_CORR_COUNT_1_reg)=data)
#define  get_DVBC_CORR_COUNT_1_reg                                               (*((volatile unsigned int*)DVBC_CORR_COUNT_1_reg))
#define  DVBC_CORR_COUNT_1_corr_count_15_8_shift                                 (0)
#define  DVBC_CORR_COUNT_1_corr_count_15_8_mask                                  (0x000000FF)
#define  DVBC_CORR_COUNT_1_corr_count_15_8(data)                                 (0x000000FF&(data))
#define  DVBC_CORR_COUNT_1_get_corr_count_15_8(data)                             (0x000000FF&(data))

#define  DVBC_UNCORR_COUNT                                                       0x180E8838
#define  DVBC_UNCORR_COUNT_reg_addr                                              "0xB80E8838"
#define  DVBC_UNCORR_COUNT_reg                                                   0xB80E8838
#define  DVBC_UNCORR_COUNT_inst_addr                                             "0x0116"
#define  set_DVBC_UNCORR_COUNT_reg(data)                                         (*((volatile unsigned int*)DVBC_UNCORR_COUNT_reg)=data)
#define  get_DVBC_UNCORR_COUNT_reg                                               (*((volatile unsigned int*)DVBC_UNCORR_COUNT_reg))
#define  DVBC_UNCORR_COUNT_uncorr_count_7_0_shift                                (0)
#define  DVBC_UNCORR_COUNT_uncorr_count_7_0_mask                                 (0x000000FF)
#define  DVBC_UNCORR_COUNT_uncorr_count_7_0(data)                                (0x000000FF&(data))
#define  DVBC_UNCORR_COUNT_get_uncorr_count_7_0(data)                            (0x000000FF&(data))

#define  DVBC_UNCORR_COUNT_1                                                     0x180E883C
#define  DVBC_UNCORR_COUNT_1_reg_addr                                            "0xB80E883C"
#define  DVBC_UNCORR_COUNT_1_reg                                                 0xB80E883C
#define  DVBC_UNCORR_COUNT_1_inst_addr                                           "0x0117"
#define  set_DVBC_UNCORR_COUNT_1_reg(data)                                       (*((volatile unsigned int*)DVBC_UNCORR_COUNT_1_reg)=data)
#define  get_DVBC_UNCORR_COUNT_1_reg                                             (*((volatile unsigned int*)DVBC_UNCORR_COUNT_1_reg))
#define  DVBC_UNCORR_COUNT_1_uncorr_count_15_8_shift                             (0)
#define  DVBC_UNCORR_COUNT_1_uncorr_count_15_8_mask                              (0x000000FF)
#define  DVBC_UNCORR_COUNT_1_uncorr_count_15_8(data)                             (0x000000FF&(data))
#define  DVBC_UNCORR_COUNT_1_get_uncorr_count_15_8(data)                         (0x000000FF&(data))

#define  DVBC_OPT_DESC_DISABLE                                                   0x180E8840
#define  DVBC_OPT_DESC_DISABLE_reg_addr                                          "0xB80E8840"
#define  DVBC_OPT_DESC_DISABLE_reg                                               0xB80E8840
#define  DVBC_OPT_DESC_DISABLE_inst_addr                                         "0x0118"
#define  set_DVBC_OPT_DESC_DISABLE_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_DESC_DISABLE_reg)=data)
#define  get_DVBC_OPT_DESC_DISABLE_reg                                           (*((volatile unsigned int*)DVBC_OPT_DESC_DISABLE_reg))
#define  DVBC_OPT_DESC_DISABLE_opt_dvbc_smooth_shift                             (7)
#define  DVBC_OPT_DESC_DISABLE_opt_fix_invsync_shift                             (6)
#define  DVBC_OPT_DESC_DISABLE_opt_syncmode_shift                                (4)
#define  DVBC_OPT_DESC_DISABLE_opt_fix_tei_shift                                 (3)
#define  DVBC_OPT_DESC_DISABLE_opt_no_reinvert_shift                             (2)
#define  DVBC_OPT_DESC_DISABLE_desc_syncstate_shift                              (1)
#define  DVBC_OPT_DESC_DISABLE_opt_desc_disable_shift                            (0)
#define  DVBC_OPT_DESC_DISABLE_opt_dvbc_smooth_mask                              (0x00000080)
#define  DVBC_OPT_DESC_DISABLE_opt_fix_invsync_mask                              (0x00000040)
#define  DVBC_OPT_DESC_DISABLE_opt_syncmode_mask                                 (0x00000030)
#define  DVBC_OPT_DESC_DISABLE_opt_fix_tei_mask                                  (0x00000008)
#define  DVBC_OPT_DESC_DISABLE_opt_no_reinvert_mask                              (0x00000004)
#define  DVBC_OPT_DESC_DISABLE_desc_syncstate_mask                               (0x00000002)
#define  DVBC_OPT_DESC_DISABLE_opt_desc_disable_mask                             (0x00000001)
#define  DVBC_OPT_DESC_DISABLE_opt_dvbc_smooth(data)                             (0x00000080&((data)<<7))
#define  DVBC_OPT_DESC_DISABLE_opt_fix_invsync(data)                             (0x00000040&((data)<<6))
#define  DVBC_OPT_DESC_DISABLE_opt_syncmode(data)                                (0x00000030&((data)<<4))
#define  DVBC_OPT_DESC_DISABLE_opt_fix_tei(data)                                 (0x00000008&((data)<<3))
#define  DVBC_OPT_DESC_DISABLE_opt_no_reinvert(data)                             (0x00000004&((data)<<2))
#define  DVBC_OPT_DESC_DISABLE_desc_syncstate(data)                              (0x00000002&((data)<<1))
#define  DVBC_OPT_DESC_DISABLE_opt_desc_disable(data)                            (0x00000001&(data))
#define  DVBC_OPT_DESC_DISABLE_get_opt_dvbc_smooth(data)                         ((0x00000080&(data))>>7)
#define  DVBC_OPT_DESC_DISABLE_get_opt_fix_invsync(data)                         ((0x00000040&(data))>>6)
#define  DVBC_OPT_DESC_DISABLE_get_opt_syncmode(data)                            ((0x00000030&(data))>>4)
#define  DVBC_OPT_DESC_DISABLE_get_opt_fix_tei(data)                             ((0x00000008&(data))>>3)
#define  DVBC_OPT_DESC_DISABLE_get_opt_no_reinvert(data)                         ((0x00000004&(data))>>2)
#define  DVBC_OPT_DESC_DISABLE_get_desc_syncstate(data)                          ((0x00000002&(data))>>1)
#define  DVBC_OPT_DESC_DISABLE_get_opt_desc_disable(data)                        (0x00000001&(data))

#define  DVBC_OPT_CKOUTPAR                                                       0x180E8844
#define  DVBC_OPT_CKOUTPAR_reg_addr                                              "0xB80E8844"
#define  DVBC_OPT_CKOUTPAR_reg                                                   0xB80E8844
#define  DVBC_OPT_CKOUTPAR_inst_addr                                             "0x0119"
#define  set_DVBC_OPT_CKOUTPAR_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_CKOUTPAR_reg)=data)
#define  get_DVBC_OPT_CKOUTPAR_reg                                               (*((volatile unsigned int*)DVBC_OPT_CKOUTPAR_reg))
#define  DVBC_OPT_CKOUTPAR_opt_sync_byte_shift                                   (3)
#define  DVBC_OPT_CKOUTPAR_opt_serial_shift                                      (2)
#define  DVBC_OPT_CKOUTPAR_opt_ckout_pwr_shift                                   (1)
#define  DVBC_OPT_CKOUTPAR_opt_ckoutpar_shift                                    (0)
#define  DVBC_OPT_CKOUTPAR_opt_sync_byte_mask                                    (0x00000008)
#define  DVBC_OPT_CKOUTPAR_opt_serial_mask                                       (0x00000004)
#define  DVBC_OPT_CKOUTPAR_opt_ckout_pwr_mask                                    (0x00000002)
#define  DVBC_OPT_CKOUTPAR_opt_ckoutpar_mask                                     (0x00000001)
#define  DVBC_OPT_CKOUTPAR_opt_sync_byte(data)                                   (0x00000008&((data)<<3))
#define  DVBC_OPT_CKOUTPAR_opt_serial(data)                                      (0x00000004&((data)<<2))
#define  DVBC_OPT_CKOUTPAR_opt_ckout_pwr(data)                                   (0x00000002&((data)<<1))
#define  DVBC_OPT_CKOUTPAR_opt_ckoutpar(data)                                    (0x00000001&(data))
#define  DVBC_OPT_CKOUTPAR_get_opt_sync_byte(data)                               ((0x00000008&(data))>>3)
#define  DVBC_OPT_CKOUTPAR_get_opt_serial(data)                                  ((0x00000004&(data))>>2)
#define  DVBC_OPT_CKOUTPAR_get_opt_ckout_pwr(data)                               ((0x00000002&(data))>>1)
#define  DVBC_OPT_CKOUTPAR_get_opt_ckoutpar(data)                                (0x00000001&(data))

#define  DVBC_OPT_CDIV_PH0                                                       0x180E8848
#define  DVBC_OPT_CDIV_PH0_reg_addr                                              "0xB80E8848"
#define  DVBC_OPT_CDIV_PH0_reg                                                   0xB80E8848
#define  DVBC_OPT_CDIV_PH0_inst_addr                                             "0x011A"
#define  set_DVBC_OPT_CDIV_PH0_reg(data)                                         (*((volatile unsigned int*)DVBC_OPT_CDIV_PH0_reg)=data)
#define  get_DVBC_OPT_CDIV_PH0_reg                                               (*((volatile unsigned int*)DVBC_OPT_CDIV_PH0_reg))
#define  DVBC_OPT_CDIV_PH0_opt_cdiv_ph1_shift                                    (4)
#define  DVBC_OPT_CDIV_PH0_opt_cdiv_ph0_shift                                    (0)
#define  DVBC_OPT_CDIV_PH0_opt_cdiv_ph1_mask                                     (0x000000F0)
#define  DVBC_OPT_CDIV_PH0_opt_cdiv_ph0_mask                                     (0x0000000F)
#define  DVBC_OPT_CDIV_PH0_opt_cdiv_ph1(data)                                    (0x000000F0&((data)<<4))
#define  DVBC_OPT_CDIV_PH0_opt_cdiv_ph0(data)                                    (0x0000000F&(data))
#define  DVBC_OPT_CDIV_PH0_get_opt_cdiv_ph1(data)                                ((0x000000F0&(data))>>4)
#define  DVBC_OPT_CDIV_PH0_get_opt_cdiv_ph0(data)                                (0x0000000F&(data))

#define  DVBC_OPT_BIST                                                           0x180E884C
#define  DVBC_OPT_BIST_reg_addr                                                  "0xB80E884C"
#define  DVBC_OPT_BIST_reg                                                       0xB80E884C
#define  DVBC_OPT_BIST_inst_addr                                                 "0x011B"
#define  set_DVBC_OPT_BIST_reg(data)                                             (*((volatile unsigned int*)DVBC_OPT_BIST_reg)=data)
#define  get_DVBC_OPT_BIST_reg                                                   (*((volatile unsigned int*)DVBC_OPT_BIST_reg))
#define  DVBC_OPT_BIST_bist_sta_stb_shift                                        (7)
#define  DVBC_OPT_BIST_bist_mode_shift                                           (4)
#define  DVBC_OPT_BIST_bist_done_shift                                           (3)
#define  DVBC_OPT_BIST_bist_sta_stb_mask                                         (0x00000080)
#define  DVBC_OPT_BIST_bist_mode_mask                                            (0x00000010)
#define  DVBC_OPT_BIST_bist_done_mask                                            (0x00000008)
#define  DVBC_OPT_BIST_bist_sta_stb(data)                                        (0x00000080&((data)<<7))
#define  DVBC_OPT_BIST_bist_mode(data)                                           (0x00000010&((data)<<4))
#define  DVBC_OPT_BIST_bist_done(data)                                           (0x00000008&((data)<<3))
#define  DVBC_OPT_BIST_get_bist_sta_stb(data)                                    ((0x00000080&(data))>>7)
#define  DVBC_OPT_BIST_get_bist_mode(data)                                       ((0x00000010&(data))>>4)
#define  DVBC_OPT_BIST_get_bist_done(data)                                       ((0x00000008&(data))>>3)

#define  DVBC_AUTO_BER_BLK_COUNT                                                 0x180E8850
#define  DVBC_AUTO_BER_BLK_COUNT_reg_addr                                        "0xB80E8850"
#define  DVBC_AUTO_BER_BLK_COUNT_reg                                             0xB80E8850
#define  DVBC_AUTO_BER_BLK_COUNT_inst_addr                                       "0x011C"
#define  set_DVBC_AUTO_BER_BLK_COUNT_reg(data)                                   (*((volatile unsigned int*)DVBC_AUTO_BER_BLK_COUNT_reg)=data)
#define  get_DVBC_AUTO_BER_BLK_COUNT_reg                                         (*((volatile unsigned int*)DVBC_AUTO_BER_BLK_COUNT_reg))
#define  DVBC_AUTO_BER_BLK_COUNT_auto_ber_blk_count_shift                        (0)
#define  DVBC_AUTO_BER_BLK_COUNT_auto_ber_blk_count_mask                         (0x000000FF)
#define  DVBC_AUTO_BER_BLK_COUNT_auto_ber_blk_count(data)                        (0x000000FF&(data))
#define  DVBC_AUTO_BER_BLK_COUNT_get_auto_ber_blk_count(data)                    (0x000000FF&(data))

#define  DVBC_AUTO_BER_COUNT_0                                                   0x180E8854
#define  DVBC_AUTO_BER_COUNT_0_reg_addr                                          "0xB80E8854"
#define  DVBC_AUTO_BER_COUNT_0_reg                                               0xB80E8854
#define  DVBC_AUTO_BER_COUNT_0_inst_addr                                         "0x011D"
#define  set_DVBC_AUTO_BER_COUNT_0_reg(data)                                     (*((volatile unsigned int*)DVBC_AUTO_BER_COUNT_0_reg)=data)
#define  get_DVBC_AUTO_BER_COUNT_0_reg                                           (*((volatile unsigned int*)DVBC_AUTO_BER_COUNT_0_reg))
#define  DVBC_AUTO_BER_COUNT_0_auto_ber_count_0_shift                            (0)
#define  DVBC_AUTO_BER_COUNT_0_auto_ber_count_0_mask                             (0x000000FF)
#define  DVBC_AUTO_BER_COUNT_0_auto_ber_count_0(data)                            (0x000000FF&(data))
#define  DVBC_AUTO_BER_COUNT_0_get_auto_ber_count_0(data)                        (0x000000FF&(data))

#define  DVBC_AUTO_BER_COUNT_1                                                   0x180E8858
#define  DVBC_AUTO_BER_COUNT_1_reg_addr                                          "0xB80E8858"
#define  DVBC_AUTO_BER_COUNT_1_reg                                               0xB80E8858
#define  DVBC_AUTO_BER_COUNT_1_inst_addr                                         "0x011E"
#define  set_DVBC_AUTO_BER_COUNT_1_reg(data)                                     (*((volatile unsigned int*)DVBC_AUTO_BER_COUNT_1_reg)=data)
#define  get_DVBC_AUTO_BER_COUNT_1_reg                                           (*((volatile unsigned int*)DVBC_AUTO_BER_COUNT_1_reg))
#define  DVBC_AUTO_BER_COUNT_1_auto_ber_count_1_shift                            (0)
#define  DVBC_AUTO_BER_COUNT_1_auto_ber_count_1_mask                             (0x000000FF)
#define  DVBC_AUTO_BER_COUNT_1_auto_ber_count_1(data)                            (0x000000FF&(data))
#define  DVBC_AUTO_BER_COUNT_1_get_auto_ber_count_1(data)                        (0x000000FF&(data))

#define  DVBC_AUTO_BER_COUNT_2                                                   0x180E885C
#define  DVBC_AUTO_BER_COUNT_2_reg_addr                                          "0xB80E885C"
#define  DVBC_AUTO_BER_COUNT_2_reg                                               0xB80E885C
#define  DVBC_AUTO_BER_COUNT_2_inst_addr                                         "0x011F"
#define  set_DVBC_AUTO_BER_COUNT_2_reg(data)                                     (*((volatile unsigned int*)DVBC_AUTO_BER_COUNT_2_reg)=data)
#define  get_DVBC_AUTO_BER_COUNT_2_reg                                           (*((volatile unsigned int*)DVBC_AUTO_BER_COUNT_2_reg))
#define  DVBC_AUTO_BER_COUNT_2_auto_blk_count_2_shift                            (5)
#define  DVBC_AUTO_BER_COUNT_2_auto_ber_count_2_shift                            (0)
#define  DVBC_AUTO_BER_COUNT_2_auto_blk_count_2_mask                             (0x000000E0)
#define  DVBC_AUTO_BER_COUNT_2_auto_ber_count_2_mask                             (0x0000001F)
#define  DVBC_AUTO_BER_COUNT_2_auto_blk_count_2(data)                            (0x000000E0&((data)<<5))
#define  DVBC_AUTO_BER_COUNT_2_auto_ber_count_2(data)                            (0x0000001F&(data))
#define  DVBC_AUTO_BER_COUNT_2_get_auto_blk_count_2(data)                        ((0x000000E0&(data))>>5)
#define  DVBC_AUTO_BER_COUNT_2_get_auto_ber_count_2(data)                        (0x0000001F&(data))

#define  DVBC_AUTO_BLK_COUNT_0                                                   0x180E8860
#define  DVBC_AUTO_BLK_COUNT_0_reg_addr                                          "0xB80E8860"
#define  DVBC_AUTO_BLK_COUNT_0_reg                                               0xB80E8860
#define  DVBC_AUTO_BLK_COUNT_0_inst_addr                                         "0x0120"
#define  set_DVBC_AUTO_BLK_COUNT_0_reg(data)                                     (*((volatile unsigned int*)DVBC_AUTO_BLK_COUNT_0_reg)=data)
#define  get_DVBC_AUTO_BLK_COUNT_0_reg                                           (*((volatile unsigned int*)DVBC_AUTO_BLK_COUNT_0_reg))
#define  DVBC_AUTO_BLK_COUNT_0_auto_blk_count_0_shift                            (0)
#define  DVBC_AUTO_BLK_COUNT_0_auto_blk_count_0_mask                             (0x000000FF)
#define  DVBC_AUTO_BLK_COUNT_0_auto_blk_count_0(data)                            (0x000000FF&(data))
#define  DVBC_AUTO_BLK_COUNT_0_get_auto_blk_count_0(data)                        (0x000000FF&(data))

#define  DVBC_AUTO_BLK_COUNT_1                                                   0x180E8864
#define  DVBC_AUTO_BLK_COUNT_1_reg_addr                                          "0xB80E8864"
#define  DVBC_AUTO_BLK_COUNT_1_reg                                               0xB80E8864
#define  DVBC_AUTO_BLK_COUNT_1_inst_addr                                         "0x0121"
#define  set_DVBC_AUTO_BLK_COUNT_1_reg(data)                                     (*((volatile unsigned int*)DVBC_AUTO_BLK_COUNT_1_reg)=data)
#define  get_DVBC_AUTO_BLK_COUNT_1_reg                                           (*((volatile unsigned int*)DVBC_AUTO_BLK_COUNT_1_reg))
#define  DVBC_AUTO_BLK_COUNT_1_auto_blk_count_1_shift                            (0)
#define  DVBC_AUTO_BLK_COUNT_1_auto_blk_count_1_mask                             (0x000000FF)
#define  DVBC_AUTO_BLK_COUNT_1_auto_blk_count_1(data)                            (0x000000FF&(data))
#define  DVBC_AUTO_BLK_COUNT_1_get_auto_blk_count_1(data)                        (0x000000FF&(data))

#define  DVBC_AUTO_CORR_COUNT_0                                                  0x180E8868
#define  DVBC_AUTO_CORR_COUNT_0_reg_addr                                         "0xB80E8868"
#define  DVBC_AUTO_CORR_COUNT_0_reg                                              0xB80E8868
#define  DVBC_AUTO_CORR_COUNT_0_inst_addr                                        "0x0122"
#define  set_DVBC_AUTO_CORR_COUNT_0_reg(data)                                    (*((volatile unsigned int*)DVBC_AUTO_CORR_COUNT_0_reg)=data)
#define  get_DVBC_AUTO_CORR_COUNT_0_reg                                          (*((volatile unsigned int*)DVBC_AUTO_CORR_COUNT_0_reg))
#define  DVBC_AUTO_CORR_COUNT_0_auto_corr_count_0_shift                          (0)
#define  DVBC_AUTO_CORR_COUNT_0_auto_corr_count_0_mask                           (0x000000FF)
#define  DVBC_AUTO_CORR_COUNT_0_auto_corr_count_0(data)                          (0x000000FF&(data))
#define  DVBC_AUTO_CORR_COUNT_0_get_auto_corr_count_0(data)                      (0x000000FF&(data))

#define  DVBC_AUTO_CORR_COUNT_1                                                  0x180E886C
#define  DVBC_AUTO_CORR_COUNT_1_reg_addr                                         "0xB80E886C"
#define  DVBC_AUTO_CORR_COUNT_1_reg                                              0xB80E886C
#define  DVBC_AUTO_CORR_COUNT_1_inst_addr                                        "0x0123"
#define  set_DVBC_AUTO_CORR_COUNT_1_reg(data)                                    (*((volatile unsigned int*)DVBC_AUTO_CORR_COUNT_1_reg)=data)
#define  get_DVBC_AUTO_CORR_COUNT_1_reg                                          (*((volatile unsigned int*)DVBC_AUTO_CORR_COUNT_1_reg))
#define  DVBC_AUTO_CORR_COUNT_1_auto_corr_count_1_shift                          (0)
#define  DVBC_AUTO_CORR_COUNT_1_auto_corr_count_1_mask                           (0x000000FF)
#define  DVBC_AUTO_CORR_COUNT_1_auto_corr_count_1(data)                          (0x000000FF&(data))
#define  DVBC_AUTO_CORR_COUNT_1_get_auto_corr_count_1(data)                      (0x000000FF&(data))

#define  DVBC_AUTO_UNCORR_COUNT_0                                                0x180E8870
#define  DVBC_AUTO_UNCORR_COUNT_0_reg_addr                                       "0xB80E8870"
#define  DVBC_AUTO_UNCORR_COUNT_0_reg                                            0xB80E8870
#define  DVBC_AUTO_UNCORR_COUNT_0_inst_addr                                      "0x0124"
#define  set_DVBC_AUTO_UNCORR_COUNT_0_reg(data)                                  (*((volatile unsigned int*)DVBC_AUTO_UNCORR_COUNT_0_reg)=data)
#define  get_DVBC_AUTO_UNCORR_COUNT_0_reg                                        (*((volatile unsigned int*)DVBC_AUTO_UNCORR_COUNT_0_reg))
#define  DVBC_AUTO_UNCORR_COUNT_0_auto_uncorr_count_0_shift                      (0)
#define  DVBC_AUTO_UNCORR_COUNT_0_auto_uncorr_count_0_mask                       (0x000000FF)
#define  DVBC_AUTO_UNCORR_COUNT_0_auto_uncorr_count_0(data)                      (0x000000FF&(data))
#define  DVBC_AUTO_UNCORR_COUNT_0_get_auto_uncorr_count_0(data)                  (0x000000FF&(data))

#define  DVBC_AUTO_UNCORR_COUNT_1                                                0x180E8874
#define  DVBC_AUTO_UNCORR_COUNT_1_reg_addr                                       "0xB80E8874"
#define  DVBC_AUTO_UNCORR_COUNT_1_reg                                            0xB80E8874
#define  DVBC_AUTO_UNCORR_COUNT_1_inst_addr                                      "0x0125"
#define  set_DVBC_AUTO_UNCORR_COUNT_1_reg(data)                                  (*((volatile unsigned int*)DVBC_AUTO_UNCORR_COUNT_1_reg)=data)
#define  get_DVBC_AUTO_UNCORR_COUNT_1_reg                                        (*((volatile unsigned int*)DVBC_AUTO_UNCORR_COUNT_1_reg))
#define  DVBC_AUTO_UNCORR_COUNT_1_auto_uncorr_count_1_shift                      (0)
#define  DVBC_AUTO_UNCORR_COUNT_1_auto_uncorr_count_1_mask                       (0x000000FF)
#define  DVBC_AUTO_UNCORR_COUNT_1_auto_uncorr_count_1(data)                      (0x000000FF&(data))
#define  DVBC_AUTO_UNCORR_COUNT_1_get_auto_uncorr_count_1(data)                  (0x000000FF&(data))

#define  DVBC_PAGE2_RW21_RESERVED                                                0x180E8884
#define  DVBC_PAGE2_RW21_RESERVED_reg_addr                                       "0xB80E8884"
#define  DVBC_PAGE2_RW21_RESERVED_reg                                            0xB80E8884
#define  DVBC_PAGE2_RW21_RESERVED_inst_addr                                      "0x0126"
#define  set_DVBC_PAGE2_RW21_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE2_RW21_RESERVED_reg)=data)
#define  get_DVBC_PAGE2_RW21_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE2_RW21_RESERVED_reg))
#define  DVBC_PAGE2_RW21_RESERVED_page2_rw21_reserved_shift                      (0)
#define  DVBC_PAGE2_RW21_RESERVED_page2_rw21_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE2_RW21_RESERVED_page2_rw21_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE2_RW21_RESERVED_get_page2_rw21_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE2_RW22_RESERVED                                                0x180E8888
#define  DVBC_PAGE2_RW22_RESERVED_reg_addr                                       "0xB80E8888"
#define  DVBC_PAGE2_RW22_RESERVED_reg                                            0xB80E8888
#define  DVBC_PAGE2_RW22_RESERVED_inst_addr                                      "0x0127"
#define  set_DVBC_PAGE2_RW22_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE2_RW22_RESERVED_reg)=data)
#define  get_DVBC_PAGE2_RW22_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE2_RW22_RESERVED_reg))
#define  DVBC_PAGE2_RW22_RESERVED_page2_rw22_reserved_shift                      (0)
#define  DVBC_PAGE2_RW22_RESERVED_page2_rw22_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE2_RW22_RESERVED_page2_rw22_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE2_RW22_RESERVED_get_page2_rw22_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE2_RW23_RESERVED                                                0x180E888C
#define  DVBC_PAGE2_RW23_RESERVED_reg_addr                                       "0xB80E888C"
#define  DVBC_PAGE2_RW23_RESERVED_reg                                            0xB80E888C
#define  DVBC_PAGE2_RW23_RESERVED_inst_addr                                      "0x0128"
#define  set_DVBC_PAGE2_RW23_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE2_RW23_RESERVED_reg)=data)
#define  get_DVBC_PAGE2_RW23_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE2_RW23_RESERVED_reg))
#define  DVBC_PAGE2_RW23_RESERVED_page2_rw23_reserved_shift                      (0)
#define  DVBC_PAGE2_RW23_RESERVED_page2_rw23_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE2_RW23_RESERVED_page2_rw23_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE2_RW23_RESERVED_get_page2_rw23_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE2_RW24_RESERVED                                                0x180E8890
#define  DVBC_PAGE2_RW24_RESERVED_reg_addr                                       "0xB80E8890"
#define  DVBC_PAGE2_RW24_RESERVED_reg                                            0xB80E8890
#define  DVBC_PAGE2_RW24_RESERVED_inst_addr                                      "0x0129"
#define  set_DVBC_PAGE2_RW24_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE2_RW24_RESERVED_reg)=data)
#define  get_DVBC_PAGE2_RW24_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE2_RW24_RESERVED_reg))
#define  DVBC_PAGE2_RW24_RESERVED_page2_rw24_reserved_shift                      (0)
#define  DVBC_PAGE2_RW24_RESERVED_page2_rw24_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE2_RW24_RESERVED_page2_rw24_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE2_RW24_RESERVED_get_page2_rw24_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE2_RW25_RESERVED                                                0x180E8894
#define  DVBC_PAGE2_RW25_RESERVED_reg_addr                                       "0xB80E8894"
#define  DVBC_PAGE2_RW25_RESERVED_reg                                            0xB80E8894
#define  DVBC_PAGE2_RW25_RESERVED_inst_addr                                      "0x012A"
#define  set_DVBC_PAGE2_RW25_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE2_RW25_RESERVED_reg)=data)
#define  get_DVBC_PAGE2_RW25_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE2_RW25_RESERVED_reg))
#define  DVBC_PAGE2_RW25_RESERVED_page2_rw25_reserved_shift                      (0)
#define  DVBC_PAGE2_RW25_RESERVED_page2_rw25_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE2_RW25_RESERVED_page2_rw25_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE2_RW25_RESERVED_get_page2_rw25_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE2_RW26_RESERVED                                                0x180E8898
#define  DVBC_PAGE2_RW26_RESERVED_reg_addr                                       "0xB80E8898"
#define  DVBC_PAGE2_RW26_RESERVED_reg                                            0xB80E8898
#define  DVBC_PAGE2_RW26_RESERVED_inst_addr                                      "0x012B"
#define  set_DVBC_PAGE2_RW26_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE2_RW26_RESERVED_reg)=data)
#define  get_DVBC_PAGE2_RW26_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE2_RW26_RESERVED_reg))
#define  DVBC_PAGE2_RW26_RESERVED_page2_rw26_reserved_shift                      (0)
#define  DVBC_PAGE2_RW26_RESERVED_page2_rw26_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE2_RW26_RESERVED_page2_rw26_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE2_RW26_RESERVED_get_page2_rw26_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE2_RW27_RESERVED                                                0x180E889C
#define  DVBC_PAGE2_RW27_RESERVED_reg_addr                                       "0xB80E889C"
#define  DVBC_PAGE2_RW27_RESERVED_reg                                            0xB80E889C
#define  DVBC_PAGE2_RW27_RESERVED_inst_addr                                      "0x012C"
#define  set_DVBC_PAGE2_RW27_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE2_RW27_RESERVED_reg)=data)
#define  get_DVBC_PAGE2_RW27_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE2_RW27_RESERVED_reg))
#define  DVBC_PAGE2_RW27_RESERVED_page2_rw27_reserved_shift                      (0)
#define  DVBC_PAGE2_RW27_RESERVED_page2_rw27_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE2_RW27_RESERVED_page2_rw27_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE2_RW27_RESERVED_get_page2_rw27_reserved(data)                  (0x000000FF&(data))

#define  DVBC_PAGE2_RW28_RESERVED                                                0x180E88A0
#define  DVBC_PAGE2_RW28_RESERVED_reg_addr                                       "0xB80E88A0"
#define  DVBC_PAGE2_RW28_RESERVED_reg                                            0xB80E88A0
#define  DVBC_PAGE2_RW28_RESERVED_inst_addr                                      "0x012D"
#define  set_DVBC_PAGE2_RW28_RESERVED_reg(data)                                  (*((volatile unsigned int*)DVBC_PAGE2_RW28_RESERVED_reg)=data)
#define  get_DVBC_PAGE2_RW28_RESERVED_reg                                        (*((volatile unsigned int*)DVBC_PAGE2_RW28_RESERVED_reg))
#define  DVBC_PAGE2_RW28_RESERVED_page2_rw28_reserved_shift                      (0)
#define  DVBC_PAGE2_RW28_RESERVED_page2_rw28_reserved_mask                       (0x000000FF)
#define  DVBC_PAGE2_RW28_RESERVED_page2_rw28_reserved(data)                      (0x000000FF&(data))
#define  DVBC_PAGE2_RW28_RESERVED_get_page2_rw28_reserved(data)                  (0x000000FF&(data))

#define  DVBC_OPT_DSP_FIRST_OUT_IDX                                              0x180E88B8
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_reg_addr                                     "0xB80E88B8"
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_reg                                          0xB80E88B8
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_inst_addr                                    "0x012E"
#define  set_DVBC_OPT_DSP_FIRST_OUT_IDX_reg(data)                                (*((volatile unsigned int*)DVBC_OPT_DSP_FIRST_OUT_IDX_reg)=data)
#define  get_DVBC_OPT_DSP_FIRST_OUT_IDX_reg                                      (*((volatile unsigned int*)DVBC_OPT_DSP_FIRST_OUT_IDX_reg))
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_opt_dsp_first_out_idx_7_0_shift              (0)
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_opt_dsp_first_out_idx_7_0_mask               (0x000000FF)
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_opt_dsp_first_out_idx_7_0(data)              (0x000000FF&(data))
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_get_opt_dsp_first_out_idx_7_0(data)          (0x000000FF&(data))

#define  DVBC_OPT_DSP_FIRST_OUT_IDX_1                                            0x180E88BC
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_1_reg_addr                                   "0xB80E88BC"
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_1_reg                                        0xB80E88BC
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_1_inst_addr                                  "0x012F"
#define  set_DVBC_OPT_DSP_FIRST_OUT_IDX_1_reg(data)                              (*((volatile unsigned int*)DVBC_OPT_DSP_FIRST_OUT_IDX_1_reg)=data)
#define  get_DVBC_OPT_DSP_FIRST_OUT_IDX_1_reg                                    (*((volatile unsigned int*)DVBC_OPT_DSP_FIRST_OUT_IDX_1_reg))
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_1_opt_dsp_first_out_idx_12_8_shift           (0)
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_1_opt_dsp_first_out_idx_12_8_mask            (0x0000001F)
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_1_opt_dsp_first_out_idx_12_8(data)           (0x0000001F&(data))
#define  DVBC_OPT_DSP_FIRST_OUT_IDX_1_get_opt_dsp_first_out_idx_12_8(data)       (0x0000001F&(data))

#define  DVBC_OPT_FFT_ABS_OUT                                                    0x180E88C0
#define  DVBC_OPT_FFT_ABS_OUT_reg_addr                                           "0xB80E88C0"
#define  DVBC_OPT_FFT_ABS_OUT_reg                                                0xB80E88C0
#define  DVBC_OPT_FFT_ABS_OUT_inst_addr                                          "0x0130"
#define  set_DVBC_OPT_FFT_ABS_OUT_reg(data)                                      (*((volatile unsigned int*)DVBC_OPT_FFT_ABS_OUT_reg)=data)
#define  get_DVBC_OPT_FFT_ABS_OUT_reg                                            (*((volatile unsigned int*)DVBC_OPT_FFT_ABS_OUT_reg))
#define  DVBC_OPT_FFT_ABS_OUT_opt_fft_abs_out_shift                              (0)
#define  DVBC_OPT_FFT_ABS_OUT_opt_fft_abs_out_mask                               (0x00000001)
#define  DVBC_OPT_FFT_ABS_OUT_opt_fft_abs_out(data)                              (0x00000001&(data))
#define  DVBC_OPT_FFT_ABS_OUT_get_opt_fft_abs_out(data)                          (0x00000001&(data))

#define  DVBC_OPT_FFT_DSP_READ                                                   0x180E88C4
#define  DVBC_OPT_FFT_DSP_READ_reg_addr                                          "0xB80E88C4"
#define  DVBC_OPT_FFT_DSP_READ_reg                                               0xB80E88C4
#define  DVBC_OPT_FFT_DSP_READ_inst_addr                                         "0x0131"
#define  set_DVBC_OPT_FFT_DSP_READ_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_FFT_DSP_READ_reg)=data)
#define  get_DVBC_OPT_FFT_DSP_READ_reg                                           (*((volatile unsigned int*)DVBC_OPT_FFT_DSP_READ_reg))
#define  DVBC_OPT_FFT_DSP_READ_opt_fft_dsp_read_shift                            (0)
#define  DVBC_OPT_FFT_DSP_READ_opt_fft_dsp_read_mask                             (0x00000001)
#define  DVBC_OPT_FFT_DSP_READ_opt_fft_dsp_read(data)                            (0x00000001&(data))
#define  DVBC_OPT_FFT_DSP_READ_get_opt_fft_dsp_read(data)                        (0x00000001&(data))

#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN                                             0x180E88C8
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_reg_addr                                    "0xB80E88C8"
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_reg                                         0xB80E88C8
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_inst_addr                                   "0x0132"
#define  set_DVBC_OPT_POS_FRQ_SLOT_SR_EN_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_SLOT_SR_EN_reg)=data)
#define  get_DVBC_OPT_POS_FRQ_SLOT_SR_EN_reg                                     (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_SLOT_SR_EN_reg))
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_opt_pos_frq_slot_sr_en_7_0_shift            (0)
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_opt_pos_frq_slot_sr_en_7_0_mask             (0x000000FF)
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_opt_pos_frq_slot_sr_en_7_0(data)            (0x000000FF&(data))
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_get_opt_pos_frq_slot_sr_en_7_0(data)        (0x000000FF&(data))

#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_1                                           0x180E88CC
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_reg_addr                                  "0xB80E88CC"
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_reg                                       0xB80E88CC
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_inst_addr                                 "0x0133"
#define  set_DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_reg(data)                             (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_reg)=data)
#define  get_DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_reg                                   (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_reg))
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_opt_pos_frq_slot_sr_en_15_8_shift         (0)
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_opt_pos_frq_slot_sr_en_15_8_mask          (0x000000FF)
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_opt_pos_frq_slot_sr_en_15_8(data)         (0x000000FF&(data))
#define  DVBC_OPT_POS_FRQ_SLOT_SR_EN_1_get_opt_pos_frq_slot_sr_en_15_8(data)     (0x000000FF&(data))

#define  DVBC_OPT_FFT_OUT_MODE                                                   0x180E88D0
#define  DVBC_OPT_FFT_OUT_MODE_reg_addr                                          "0xB80E88D0"
#define  DVBC_OPT_FFT_OUT_MODE_reg                                               0xB80E88D0
#define  DVBC_OPT_FFT_OUT_MODE_inst_addr                                         "0x0134"
#define  set_DVBC_OPT_FFT_OUT_MODE_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_FFT_OUT_MODE_reg)=data)
#define  get_DVBC_OPT_FFT_OUT_MODE_reg                                           (*((volatile unsigned int*)DVBC_OPT_FFT_OUT_MODE_reg))
#define  DVBC_OPT_FFT_OUT_MODE_opt_fft_out_mode_shift                            (0)
#define  DVBC_OPT_FFT_OUT_MODE_opt_fft_out_mode_mask                             (0x00000001)
#define  DVBC_OPT_FFT_OUT_MODE_opt_fft_out_mode(data)                            (0x00000001&(data))
#define  DVBC_OPT_FFT_OUT_MODE_get_opt_fft_out_mode(data)                        (0x00000001&(data))

#define  DVBC_OPT_PAPD_PAPR_SEL                                                  0x180E88D4
#define  DVBC_OPT_PAPD_PAPR_SEL_reg_addr                                         "0xB80E88D4"
#define  DVBC_OPT_PAPD_PAPR_SEL_reg                                              0xB80E88D4
#define  DVBC_OPT_PAPD_PAPR_SEL_inst_addr                                        "0x0135"
#define  set_DVBC_OPT_PAPD_PAPR_SEL_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_PAPD_PAPR_SEL_reg)=data)
#define  get_DVBC_OPT_PAPD_PAPR_SEL_reg                                          (*((volatile unsigned int*)DVBC_OPT_PAPD_PAPR_SEL_reg))
#define  DVBC_OPT_PAPD_PAPR_SEL_opt_papd_papr_sel_shift                          (0)
#define  DVBC_OPT_PAPD_PAPR_SEL_opt_papd_papr_sel_mask                           (0x00000001)
#define  DVBC_OPT_PAPD_PAPR_SEL_opt_papd_papr_sel(data)                          (0x00000001&(data))
#define  DVBC_OPT_PAPD_PAPR_SEL_get_opt_papd_papr_sel(data)                      (0x00000001&(data))

#define  DVBC_OPT_FFT_OUTPUT_ACC_NUM                                             0x180E88D8
#define  DVBC_OPT_FFT_OUTPUT_ACC_NUM_reg_addr                                    "0xB80E88D8"
#define  DVBC_OPT_FFT_OUTPUT_ACC_NUM_reg                                         0xB80E88D8
#define  DVBC_OPT_FFT_OUTPUT_ACC_NUM_inst_addr                                   "0x0136"
#define  set_DVBC_OPT_FFT_OUTPUT_ACC_NUM_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_FFT_OUTPUT_ACC_NUM_reg)=data)
#define  get_DVBC_OPT_FFT_OUTPUT_ACC_NUM_reg                                     (*((volatile unsigned int*)DVBC_OPT_FFT_OUTPUT_ACC_NUM_reg))
#define  DVBC_OPT_FFT_OUTPUT_ACC_NUM_opt_fft_output_acc_num_shift                (0)
#define  DVBC_OPT_FFT_OUTPUT_ACC_NUM_opt_fft_output_acc_num_mask                 (0x0000000F)
#define  DVBC_OPT_FFT_OUTPUT_ACC_NUM_opt_fft_output_acc_num(data)                (0x0000000F&(data))
#define  DVBC_OPT_FFT_OUTPUT_ACC_NUM_get_opt_fft_output_acc_num(data)            (0x0000000F&(data))

#define  DVBC_OPT_NBD_TDFT_IDX                                                   0x180E88DC
#define  DVBC_OPT_NBD_TDFT_IDX_reg_addr                                          "0xB80E88DC"
#define  DVBC_OPT_NBD_TDFT_IDX_reg                                               0xB80E88DC
#define  DVBC_OPT_NBD_TDFT_IDX_inst_addr                                         "0x0137"
#define  set_DVBC_OPT_NBD_TDFT_IDX_reg(data)                                     (*((volatile unsigned int*)DVBC_OPT_NBD_TDFT_IDX_reg)=data)
#define  get_DVBC_OPT_NBD_TDFT_IDX_reg                                           (*((volatile unsigned int*)DVBC_OPT_NBD_TDFT_IDX_reg))
#define  DVBC_OPT_NBD_TDFT_IDX_opt_nbd_tdft_idx_shift                            (0)
#define  DVBC_OPT_NBD_TDFT_IDX_opt_nbd_tdft_idx_mask                             (0x0000000F)
#define  DVBC_OPT_NBD_TDFT_IDX_opt_nbd_tdft_idx(data)                            (0x0000000F&(data))
#define  DVBC_OPT_NBD_TDFT_IDX_get_opt_nbd_tdft_idx(data)                        (0x0000000F&(data))

#define  DVBC_OPT_SLOT_AVG_RATIO_SEL                                             0x180E88E0
#define  DVBC_OPT_SLOT_AVG_RATIO_SEL_reg_addr                                    "0xB80E88E0"
#define  DVBC_OPT_SLOT_AVG_RATIO_SEL_reg                                         0xB80E88E0
#define  DVBC_OPT_SLOT_AVG_RATIO_SEL_inst_addr                                   "0x0138"
#define  set_DVBC_OPT_SLOT_AVG_RATIO_SEL_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_SLOT_AVG_RATIO_SEL_reg)=data)
#define  get_DVBC_OPT_SLOT_AVG_RATIO_SEL_reg                                     (*((volatile unsigned int*)DVBC_OPT_SLOT_AVG_RATIO_SEL_reg))
#define  DVBC_OPT_SLOT_AVG_RATIO_SEL_opt_slot_avg_ratio_sel_shift                (0)
#define  DVBC_OPT_SLOT_AVG_RATIO_SEL_opt_slot_avg_ratio_sel_mask                 (0x0000000F)
#define  DVBC_OPT_SLOT_AVG_RATIO_SEL_opt_slot_avg_ratio_sel(data)                (0x0000000F&(data))
#define  DVBC_OPT_SLOT_AVG_RATIO_SEL_get_opt_slot_avg_ratio_sel(data)            (0x0000000F&(data))

#define  DVBC_OPT_COMP_SLOT_AVG_THD                                              0x180E88E4
#define  DVBC_OPT_COMP_SLOT_AVG_THD_reg_addr                                     "0xB80E88E4"
#define  DVBC_OPT_COMP_SLOT_AVG_THD_reg                                          0xB80E88E4
#define  DVBC_OPT_COMP_SLOT_AVG_THD_inst_addr                                    "0x0139"
#define  set_DVBC_OPT_COMP_SLOT_AVG_THD_reg(data)                                (*((volatile unsigned int*)DVBC_OPT_COMP_SLOT_AVG_THD_reg)=data)
#define  get_DVBC_OPT_COMP_SLOT_AVG_THD_reg                                      (*((volatile unsigned int*)DVBC_OPT_COMP_SLOT_AVG_THD_reg))
#define  DVBC_OPT_COMP_SLOT_AVG_THD_opt_comp_slot_avg_thd_7_0_shift              (0)
#define  DVBC_OPT_COMP_SLOT_AVG_THD_opt_comp_slot_avg_thd_7_0_mask               (0x000000FF)
#define  DVBC_OPT_COMP_SLOT_AVG_THD_opt_comp_slot_avg_thd_7_0(data)              (0x000000FF&(data))
#define  DVBC_OPT_COMP_SLOT_AVG_THD_get_opt_comp_slot_avg_thd_7_0(data)          (0x000000FF&(data))

#define  DVBC_OPT_COMP_SLOT_AVG_THD_1                                            0x180E88E8
#define  DVBC_OPT_COMP_SLOT_AVG_THD_1_reg_addr                                   "0xB80E88E8"
#define  DVBC_OPT_COMP_SLOT_AVG_THD_1_reg                                        0xB80E88E8
#define  DVBC_OPT_COMP_SLOT_AVG_THD_1_inst_addr                                  "0x013A"
#define  set_DVBC_OPT_COMP_SLOT_AVG_THD_1_reg(data)                              (*((volatile unsigned int*)DVBC_OPT_COMP_SLOT_AVG_THD_1_reg)=data)
#define  get_DVBC_OPT_COMP_SLOT_AVG_THD_1_reg                                    (*((volatile unsigned int*)DVBC_OPT_COMP_SLOT_AVG_THD_1_reg))
#define  DVBC_OPT_COMP_SLOT_AVG_THD_1_opt_comp_slot_avg_thd_15_8_shift           (0)
#define  DVBC_OPT_COMP_SLOT_AVG_THD_1_opt_comp_slot_avg_thd_15_8_mask            (0x000000FF)
#define  DVBC_OPT_COMP_SLOT_AVG_THD_1_opt_comp_slot_avg_thd_15_8(data)           (0x000000FF&(data))
#define  DVBC_OPT_COMP_SLOT_AVG_THD_1_get_opt_comp_slot_avg_thd_15_8(data)       (0x000000FF&(data))

#define  DVBC_OPT_POS_FRQ_MAX_SR                                                 0x180E88F8
#define  DVBC_OPT_POS_FRQ_MAX_SR_reg_addr                                        "0xB80E88F8"
#define  DVBC_OPT_POS_FRQ_MAX_SR_reg                                             0xB80E88F8
#define  DVBC_OPT_POS_FRQ_MAX_SR_inst_addr                                       "0x013B"
#define  set_DVBC_OPT_POS_FRQ_MAX_SR_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_MAX_SR_reg)=data)
#define  get_DVBC_OPT_POS_FRQ_MAX_SR_reg                                         (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_MAX_SR_reg))
#define  DVBC_OPT_POS_FRQ_MAX_SR_opt_pos_frq_max_sr_7_0_shift                    (0)
#define  DVBC_OPT_POS_FRQ_MAX_SR_opt_pos_frq_max_sr_7_0_mask                     (0x000000FF)
#define  DVBC_OPT_POS_FRQ_MAX_SR_opt_pos_frq_max_sr_7_0(data)                    (0x000000FF&(data))
#define  DVBC_OPT_POS_FRQ_MAX_SR_get_opt_pos_frq_max_sr_7_0(data)                (0x000000FF&(data))

#define  DVBC_OPT_POS_FRQ_MAX_SR_1                                               0x180E88FC
#define  DVBC_OPT_POS_FRQ_MAX_SR_1_reg_addr                                      "0xB80E88FC"
#define  DVBC_OPT_POS_FRQ_MAX_SR_1_reg                                           0xB80E88FC
#define  DVBC_OPT_POS_FRQ_MAX_SR_1_inst_addr                                     "0x013C"
#define  set_DVBC_OPT_POS_FRQ_MAX_SR_1_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_MAX_SR_1_reg)=data)
#define  get_DVBC_OPT_POS_FRQ_MAX_SR_1_reg                                       (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_MAX_SR_1_reg))
#define  DVBC_OPT_POS_FRQ_MAX_SR_1_opt_pos_frq_max_sr_11_8_shift                 (0)
#define  DVBC_OPT_POS_FRQ_MAX_SR_1_opt_pos_frq_max_sr_11_8_mask                  (0x0000000F)
#define  DVBC_OPT_POS_FRQ_MAX_SR_1_opt_pos_frq_max_sr_11_8(data)                 (0x0000000F&(data))
#define  DVBC_OPT_POS_FRQ_MAX_SR_1_get_opt_pos_frq_max_sr_11_8(data)             (0x0000000F&(data))

#define  DVBC_OPT_POS_FRQ_MIN_SR                                                 0x180E8900
#define  DVBC_OPT_POS_FRQ_MIN_SR_reg_addr                                        "0xB80E8900"
#define  DVBC_OPT_POS_FRQ_MIN_SR_reg                                             0xB80E8900
#define  DVBC_OPT_POS_FRQ_MIN_SR_inst_addr                                       "0x013D"
#define  set_DVBC_OPT_POS_FRQ_MIN_SR_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_MIN_SR_reg)=data)
#define  get_DVBC_OPT_POS_FRQ_MIN_SR_reg                                         (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_MIN_SR_reg))
#define  DVBC_OPT_POS_FRQ_MIN_SR_opt_pos_frq_min_sr_7_0_shift                    (0)
#define  DVBC_OPT_POS_FRQ_MIN_SR_opt_pos_frq_min_sr_7_0_mask                     (0x000000FF)
#define  DVBC_OPT_POS_FRQ_MIN_SR_opt_pos_frq_min_sr_7_0(data)                    (0x000000FF&(data))
#define  DVBC_OPT_POS_FRQ_MIN_SR_get_opt_pos_frq_min_sr_7_0(data)                (0x000000FF&(data))

#define  DVBC_OPT_POS_FRQ_MIN_SR_1                                               0x180E8904
#define  DVBC_OPT_POS_FRQ_MIN_SR_1_reg_addr                                      "0xB80E8904"
#define  DVBC_OPT_POS_FRQ_MIN_SR_1_reg                                           0xB80E8904
#define  DVBC_OPT_POS_FRQ_MIN_SR_1_inst_addr                                     "0x013E"
#define  set_DVBC_OPT_POS_FRQ_MIN_SR_1_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_MIN_SR_1_reg)=data)
#define  get_DVBC_OPT_POS_FRQ_MIN_SR_1_reg                                       (*((volatile unsigned int*)DVBC_OPT_POS_FRQ_MIN_SR_1_reg))
#define  DVBC_OPT_POS_FRQ_MIN_SR_1_opt_pos_frq_min_sr_11_8_shift                 (0)
#define  DVBC_OPT_POS_FRQ_MIN_SR_1_opt_pos_frq_min_sr_11_8_mask                  (0x0000000F)
#define  DVBC_OPT_POS_FRQ_MIN_SR_1_opt_pos_frq_min_sr_11_8(data)                 (0x0000000F&(data))
#define  DVBC_OPT_POS_FRQ_MIN_SR_1_get_opt_pos_frq_min_sr_11_8(data)             (0x0000000F&(data))

#define  DVBC_OPT_QAMD_CNT_STOP                                                  0x180E8908
#define  DVBC_OPT_QAMD_CNT_STOP_reg_addr                                         "0xB80E8908"
#define  DVBC_OPT_QAMD_CNT_STOP_reg                                              0xB80E8908
#define  DVBC_OPT_QAMD_CNT_STOP_inst_addr                                        "0x013F"
#define  set_DVBC_OPT_QAMD_CNT_STOP_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_QAMD_CNT_STOP_reg)=data)
#define  get_DVBC_OPT_QAMD_CNT_STOP_reg                                          (*((volatile unsigned int*)DVBC_OPT_QAMD_CNT_STOP_reg))
#define  DVBC_OPT_QAMD_CNT_STOP_opt_qamd_cnt_stop_7_0_shift                      (0)
#define  DVBC_OPT_QAMD_CNT_STOP_opt_qamd_cnt_stop_7_0_mask                       (0x000000FF)
#define  DVBC_OPT_QAMD_CNT_STOP_opt_qamd_cnt_stop_7_0(data)                      (0x000000FF&(data))
#define  DVBC_OPT_QAMD_CNT_STOP_get_opt_qamd_cnt_stop_7_0(data)                  (0x000000FF&(data))

#define  DVBC_OPT_QAMD_CNT_STOP_1                                                0x180E890C
#define  DVBC_OPT_QAMD_CNT_STOP_1_reg_addr                                       "0xB80E890C"
#define  DVBC_OPT_QAMD_CNT_STOP_1_reg                                            0xB80E890C
#define  DVBC_OPT_QAMD_CNT_STOP_1_inst_addr                                      "0x0140"
#define  set_DVBC_OPT_QAMD_CNT_STOP_1_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_QAMD_CNT_STOP_1_reg)=data)
#define  get_DVBC_OPT_QAMD_CNT_STOP_1_reg                                        (*((volatile unsigned int*)DVBC_OPT_QAMD_CNT_STOP_1_reg))
#define  DVBC_OPT_QAMD_CNT_STOP_1_opt_qamd_cnt_stop_12_8_shift                   (0)
#define  DVBC_OPT_QAMD_CNT_STOP_1_opt_qamd_cnt_stop_12_8_mask                    (0x0000001F)
#define  DVBC_OPT_QAMD_CNT_STOP_1_opt_qamd_cnt_stop_12_8(data)                   (0x0000001F&(data))
#define  DVBC_OPT_QAMD_CNT_STOP_1_get_opt_qamd_cnt_stop_12_8(data)               (0x0000001F&(data))

#define  DVBC_OPT_QAMD_EQP_ZN0_MAX                                               0x180E8910
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_reg_addr                                      "0xB80E8910"
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_reg                                           0xB80E8910
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_inst_addr                                     "0x0141"
#define  set_DVBC_OPT_QAMD_EQP_ZN0_MAX_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN0_MAX_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN0_MAX_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN0_MAX_reg))
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_opt_qamd_eqp_zn0_max_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_opt_qamd_eqp_zn0_max_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_opt_qamd_eqp_zn0_max_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_get_opt_qamd_eqp_zn0_max_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_1                                             0x180E8914
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_1_reg_addr                                    "0xB80E8914"
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_1_reg                                         0xB80E8914
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_1_inst_addr                                   "0x0142"
#define  set_DVBC_OPT_QAMD_EQP_ZN0_MAX_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN0_MAX_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN0_MAX_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN0_MAX_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_1_opt_qamd_eqp_zn0_max_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_1_opt_qamd_eqp_zn0_max_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_1_opt_qamd_eqp_zn0_max_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN0_MAX_1_get_opt_qamd_eqp_zn0_max_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN0_MIN                                               0x180E8918
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_reg_addr                                      "0xB80E8918"
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_reg                                           0xB80E8918
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_inst_addr                                     "0x0143"
#define  set_DVBC_OPT_QAMD_EQP_ZN0_MIN_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN0_MIN_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN0_MIN_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN0_MIN_reg))
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_opt_qamd_eqp_zn0_min_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_opt_qamd_eqp_zn0_min_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_opt_qamd_eqp_zn0_min_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_get_opt_qamd_eqp_zn0_min_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_1                                             0x180E891C
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_1_reg_addr                                    "0xB80E891C"
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_1_reg                                         0xB80E891C
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_1_inst_addr                                   "0x0144"
#define  set_DVBC_OPT_QAMD_EQP_ZN0_MIN_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN0_MIN_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN0_MIN_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN0_MIN_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_1_opt_qamd_eqp_zn0_min_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_1_opt_qamd_eqp_zn0_min_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_1_opt_qamd_eqp_zn0_min_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN0_MIN_1_get_opt_qamd_eqp_zn0_min_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN1_MAX                                               0x180E8920
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_reg_addr                                      "0xB80E8920"
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_reg                                           0xB80E8920
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_inst_addr                                     "0x0145"
#define  set_DVBC_OPT_QAMD_EQP_ZN1_MAX_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN1_MAX_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN1_MAX_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN1_MAX_reg))
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_opt_qamd_eqp_zn1_max_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_opt_qamd_eqp_zn1_max_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_opt_qamd_eqp_zn1_max_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_get_opt_qamd_eqp_zn1_max_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_1                                             0x180E8924
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_1_reg_addr                                    "0xB80E8924"
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_1_reg                                         0xB80E8924
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_1_inst_addr                                   "0x0146"
#define  set_DVBC_OPT_QAMD_EQP_ZN1_MAX_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN1_MAX_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN1_MAX_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN1_MAX_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_1_opt_qamd_eqp_zn1_max_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_1_opt_qamd_eqp_zn1_max_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_1_opt_qamd_eqp_zn1_max_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN1_MAX_1_get_opt_qamd_eqp_zn1_max_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN1_MIN                                               0x180E8928
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_reg_addr                                      "0xB80E8928"
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_reg                                           0xB80E8928
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_inst_addr                                     "0x0147"
#define  set_DVBC_OPT_QAMD_EQP_ZN1_MIN_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN1_MIN_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN1_MIN_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN1_MIN_reg))
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_opt_qamd_eqp_zn1_min_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_opt_qamd_eqp_zn1_min_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_opt_qamd_eqp_zn1_min_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_get_opt_qamd_eqp_zn1_min_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_1                                             0x180E892C
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_1_reg_addr                                    "0xB80E892C"
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_1_reg                                         0xB80E892C
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_1_inst_addr                                   "0x0148"
#define  set_DVBC_OPT_QAMD_EQP_ZN1_MIN_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN1_MIN_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN1_MIN_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN1_MIN_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_1_opt_qamd_eqp_zn1_min_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_1_opt_qamd_eqp_zn1_min_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_1_opt_qamd_eqp_zn1_min_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN1_MIN_1_get_opt_qamd_eqp_zn1_min_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN2_MAX                                               0x180E8930
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_reg_addr                                      "0xB80E8930"
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_reg                                           0xB80E8930
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_inst_addr                                     "0x0149"
#define  set_DVBC_OPT_QAMD_EQP_ZN2_MAX_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN2_MAX_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN2_MAX_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN2_MAX_reg))
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_opt_qamd_eqp_zn2_max_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_opt_qamd_eqp_zn2_max_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_opt_qamd_eqp_zn2_max_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_get_opt_qamd_eqp_zn2_max_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_1                                             0x180E8934
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_1_reg_addr                                    "0xB80E8934"
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_1_reg                                         0xB80E8934
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_1_inst_addr                                   "0x014A"
#define  set_DVBC_OPT_QAMD_EQP_ZN2_MAX_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN2_MAX_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN2_MAX_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN2_MAX_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_1_opt_qamd_eqp_zn2_max_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_1_opt_qamd_eqp_zn2_max_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_1_opt_qamd_eqp_zn2_max_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN2_MAX_1_get_opt_qamd_eqp_zn2_max_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN2_MIN                                               0x180E8938
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_reg_addr                                      "0xB80E8938"
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_reg                                           0xB80E8938
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_inst_addr                                     "0x014B"
#define  set_DVBC_OPT_QAMD_EQP_ZN2_MIN_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN2_MIN_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN2_MIN_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN2_MIN_reg))
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_opt_qamd_eqp_zn2_min_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_opt_qamd_eqp_zn2_min_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_opt_qamd_eqp_zn2_min_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_get_opt_qamd_eqp_zn2_min_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_1                                             0x180E893C
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_1_reg_addr                                    "0xB80E893C"
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_1_reg                                         0xB80E893C
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_1_inst_addr                                   "0x014C"
#define  set_DVBC_OPT_QAMD_EQP_ZN2_MIN_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN2_MIN_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN2_MIN_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN2_MIN_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_1_opt_qamd_eqp_zn2_min_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_1_opt_qamd_eqp_zn2_min_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_1_opt_qamd_eqp_zn2_min_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN2_MIN_1_get_opt_qamd_eqp_zn2_min_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN3_MAX                                               0x180E8940
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_reg_addr                                      "0xB80E8940"
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_reg                                           0xB80E8940
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_inst_addr                                     "0x014D"
#define  set_DVBC_OPT_QAMD_EQP_ZN3_MAX_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN3_MAX_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN3_MAX_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN3_MAX_reg))
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_opt_qamd_eqp_zn3_max_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_opt_qamd_eqp_zn3_max_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_opt_qamd_eqp_zn3_max_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_get_opt_qamd_eqp_zn3_max_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_1                                             0x180E8944
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_1_reg_addr                                    "0xB80E8944"
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_1_reg                                         0xB80E8944
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_1_inst_addr                                   "0x014E"
#define  set_DVBC_OPT_QAMD_EQP_ZN3_MAX_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN3_MAX_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN3_MAX_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN3_MAX_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_1_opt_qamd_eqp_zn3_max_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_1_opt_qamd_eqp_zn3_max_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_1_opt_qamd_eqp_zn3_max_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN3_MAX_1_get_opt_qamd_eqp_zn3_max_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN3_MIN                                               0x180E8948
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_reg_addr                                      "0xB80E8948"
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_reg                                           0xB80E8948
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_inst_addr                                     "0x014F"
#define  set_DVBC_OPT_QAMD_EQP_ZN3_MIN_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN3_MIN_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN3_MIN_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN3_MIN_reg))
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_opt_qamd_eqp_zn3_min_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_opt_qamd_eqp_zn3_min_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_opt_qamd_eqp_zn3_min_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_get_opt_qamd_eqp_zn3_min_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_1                                             0x180E894C
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_1_reg_addr                                    "0xB80E894C"
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_1_reg                                         0xB80E894C
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_1_inst_addr                                   "0x0150"
#define  set_DVBC_OPT_QAMD_EQP_ZN3_MIN_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN3_MIN_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN3_MIN_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN3_MIN_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_1_opt_qamd_eqp_zn3_min_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_1_opt_qamd_eqp_zn3_min_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_1_opt_qamd_eqp_zn3_min_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN3_MIN_1_get_opt_qamd_eqp_zn3_min_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN4_MAX                                               0x180E8950
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_reg_addr                                      "0xB80E8950"
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_reg                                           0xB80E8950
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_inst_addr                                     "0x0151"
#define  set_DVBC_OPT_QAMD_EQP_ZN4_MAX_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN4_MAX_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN4_MAX_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN4_MAX_reg))
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_opt_qamd_eqp_zn4_max_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_opt_qamd_eqp_zn4_max_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_opt_qamd_eqp_zn4_max_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_get_opt_qamd_eqp_zn4_max_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_1                                             0x180E8954
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_1_reg_addr                                    "0xB80E8954"
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_1_reg                                         0xB80E8954
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_1_inst_addr                                   "0x0152"
#define  set_DVBC_OPT_QAMD_EQP_ZN4_MAX_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN4_MAX_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN4_MAX_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN4_MAX_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_1_opt_qamd_eqp_zn4_max_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_1_opt_qamd_eqp_zn4_max_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_1_opt_qamd_eqp_zn4_max_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN4_MAX_1_get_opt_qamd_eqp_zn4_max_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN4_MIN                                               0x180E8958
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_reg_addr                                      "0xB80E8958"
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_reg                                           0xB80E8958
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_inst_addr                                     "0x0153"
#define  set_DVBC_OPT_QAMD_EQP_ZN4_MIN_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN4_MIN_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN4_MIN_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN4_MIN_reg))
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_opt_qamd_eqp_zn4_min_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_opt_qamd_eqp_zn4_min_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_opt_qamd_eqp_zn4_min_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_get_opt_qamd_eqp_zn4_min_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_1                                             0x180E895C
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_1_reg_addr                                    "0xB80E895C"
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_1_reg                                         0xB80E895C
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_1_inst_addr                                   "0x0154"
#define  set_DVBC_OPT_QAMD_EQP_ZN4_MIN_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN4_MIN_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN4_MIN_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN4_MIN_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_1_opt_qamd_eqp_zn4_min_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_1_opt_qamd_eqp_zn4_min_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_1_opt_qamd_eqp_zn4_min_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN4_MIN_1_get_opt_qamd_eqp_zn4_min_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN5_MAX                                               0x180E8960
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_reg_addr                                      "0xB80E8960"
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_reg                                           0xB80E8960
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_inst_addr                                     "0x0155"
#define  set_DVBC_OPT_QAMD_EQP_ZN5_MAX_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN5_MAX_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN5_MAX_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN5_MAX_reg))
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_opt_qamd_eqp_zn5_max_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_opt_qamd_eqp_zn5_max_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_opt_qamd_eqp_zn5_max_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_get_opt_qamd_eqp_zn5_max_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_1                                             0x180E8964
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_1_reg_addr                                    "0xB80E8964"
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_1_reg                                         0xB80E8964
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_1_inst_addr                                   "0x0156"
#define  set_DVBC_OPT_QAMD_EQP_ZN5_MAX_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN5_MAX_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN5_MAX_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN5_MAX_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_1_opt_qamd_eqp_zn5_max_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_1_opt_qamd_eqp_zn5_max_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_1_opt_qamd_eqp_zn5_max_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN5_MAX_1_get_opt_qamd_eqp_zn5_max_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_EQP_ZN5_MIN                                               0x180E8968
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_reg_addr                                      "0xB80E8968"
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_reg                                           0xB80E8968
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_inst_addr                                     "0x0157"
#define  set_DVBC_OPT_QAMD_EQP_ZN5_MIN_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN5_MIN_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN5_MIN_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN5_MIN_reg))
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_opt_qamd_eqp_zn5_min_7_0_shift                (0)
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_opt_qamd_eqp_zn5_min_7_0_mask                 (0x000000FF)
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_opt_qamd_eqp_zn5_min_7_0(data)                (0x000000FF&(data))
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_get_opt_qamd_eqp_zn5_min_7_0(data)            (0x000000FF&(data))

#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_1                                             0x180E896C
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_1_reg_addr                                    "0xB80E896C"
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_1_reg                                         0xB80E896C
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_1_inst_addr                                   "0x0158"
#define  set_DVBC_OPT_QAMD_EQP_ZN5_MIN_1_reg(data)                               (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN5_MIN_1_reg)=data)
#define  get_DVBC_OPT_QAMD_EQP_ZN5_MIN_1_reg                                     (*((volatile unsigned int*)DVBC_OPT_QAMD_EQP_ZN5_MIN_1_reg))
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_1_opt_qamd_eqp_zn5_min_9_8_shift              (0)
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_1_opt_qamd_eqp_zn5_min_9_8_mask               (0x00000003)
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_1_opt_qamd_eqp_zn5_min_9_8(data)              (0x00000003&(data))
#define  DVBC_OPT_QAMD_EQP_ZN5_MIN_1_get_opt_qamd_eqp_zn5_min_9_8(data)          (0x00000003&(data))

#define  DVBC_OPT_QAMD_SELF_RESET                                                0x180E8970
#define  DVBC_OPT_QAMD_SELF_RESET_reg_addr                                       "0xB80E8970"
#define  DVBC_OPT_QAMD_SELF_RESET_reg                                            0xB80E8970
#define  DVBC_OPT_QAMD_SELF_RESET_inst_addr                                      "0x0159"
#define  set_DVBC_OPT_QAMD_SELF_RESET_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_QAMD_SELF_RESET_reg)=data)
#define  get_DVBC_OPT_QAMD_SELF_RESET_reg                                        (*((volatile unsigned int*)DVBC_OPT_QAMD_SELF_RESET_reg))
#define  DVBC_OPT_QAMD_SELF_RESET_opt_qamd_self_reset_shift                      (0)
#define  DVBC_OPT_QAMD_SELF_RESET_opt_qamd_self_reset_mask                       (0x00000001)
#define  DVBC_OPT_QAMD_SELF_RESET_opt_qamd_self_reset(data)                      (0x00000001&(data))
#define  DVBC_OPT_QAMD_SELF_RESET_get_opt_qamd_self_reset(data)                  (0x00000001&(data))

#define  DVBC_OPT_QAMD_START_STATE                                               0x180E8974
#define  DVBC_OPT_QAMD_START_STATE_reg_addr                                      "0xB80E8974"
#define  DVBC_OPT_QAMD_START_STATE_reg                                           0xB80E8974
#define  DVBC_OPT_QAMD_START_STATE_inst_addr                                     "0x015A"
#define  set_DVBC_OPT_QAMD_START_STATE_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_START_STATE_reg)=data)
#define  get_DVBC_OPT_QAMD_START_STATE_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_START_STATE_reg))
#define  DVBC_OPT_QAMD_START_STATE_opt_qamd_start_state_shift                    (0)
#define  DVBC_OPT_QAMD_START_STATE_opt_qamd_start_state_mask                     (0x0000000F)
#define  DVBC_OPT_QAMD_START_STATE_opt_qamd_start_state(data)                    (0x0000000F&(data))
#define  DVBC_OPT_QAMD_START_STATE_get_opt_qamd_start_state(data)                (0x0000000F&(data))

#define  DVBC_OPT_QAMD_THD_128QAM                                                0x180E8978
#define  DVBC_OPT_QAMD_THD_128QAM_reg_addr                                       "0xB80E8978"
#define  DVBC_OPT_QAMD_THD_128QAM_reg                                            0xB80E8978
#define  DVBC_OPT_QAMD_THD_128QAM_inst_addr                                      "0x015B"
#define  set_DVBC_OPT_QAMD_THD_128QAM_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_128QAM_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_128QAM_reg                                        (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_128QAM_reg))
#define  DVBC_OPT_QAMD_THD_128QAM_opt_qamd_thd_128qam_7_0_shift                  (0)
#define  DVBC_OPT_QAMD_THD_128QAM_opt_qamd_thd_128qam_7_0_mask                   (0x000000FF)
#define  DVBC_OPT_QAMD_THD_128QAM_opt_qamd_thd_128qam_7_0(data)                  (0x000000FF&(data))
#define  DVBC_OPT_QAMD_THD_128QAM_get_opt_qamd_thd_128qam_7_0(data)              (0x000000FF&(data))

#define  DVBC_OPT_QAMD_THD_128QAM_1                                              0x180E897C
#define  DVBC_OPT_QAMD_THD_128QAM_1_reg_addr                                     "0xB80E897C"
#define  DVBC_OPT_QAMD_THD_128QAM_1_reg                                          0xB80E897C
#define  DVBC_OPT_QAMD_THD_128QAM_1_inst_addr                                    "0x015C"
#define  set_DVBC_OPT_QAMD_THD_128QAM_1_reg(data)                                (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_128QAM_1_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_128QAM_1_reg                                      (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_128QAM_1_reg))
#define  DVBC_OPT_QAMD_THD_128QAM_1_opt_qamd_thd_128qam_9_8_shift                (0)
#define  DVBC_OPT_QAMD_THD_128QAM_1_opt_qamd_thd_128qam_9_8_mask                 (0x00000003)
#define  DVBC_OPT_QAMD_THD_128QAM_1_opt_qamd_thd_128qam_9_8(data)                (0x00000003&(data))
#define  DVBC_OPT_QAMD_THD_128QAM_1_get_opt_qamd_thd_128qam_9_8(data)            (0x00000003&(data))

#define  DVBC_OPT_QAMD_THD_16QAM                                                 0x180E8980
#define  DVBC_OPT_QAMD_THD_16QAM_reg_addr                                        "0xB80E8980"
#define  DVBC_OPT_QAMD_THD_16QAM_reg                                             0xB80E8980
#define  DVBC_OPT_QAMD_THD_16QAM_inst_addr                                       "0x015D"
#define  set_DVBC_OPT_QAMD_THD_16QAM_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_16QAM_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_16QAM_reg                                         (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_16QAM_reg))
#define  DVBC_OPT_QAMD_THD_16QAM_opt_qamd_thd_16qam_7_0_shift                    (0)
#define  DVBC_OPT_QAMD_THD_16QAM_opt_qamd_thd_16qam_7_0_mask                     (0x000000FF)
#define  DVBC_OPT_QAMD_THD_16QAM_opt_qamd_thd_16qam_7_0(data)                    (0x000000FF&(data))
#define  DVBC_OPT_QAMD_THD_16QAM_get_opt_qamd_thd_16qam_7_0(data)                (0x000000FF&(data))

#define  DVBC_OPT_QAMD_THD_16QAM_1                                               0x180E8984
#define  DVBC_OPT_QAMD_THD_16QAM_1_reg_addr                                      "0xB80E8984"
#define  DVBC_OPT_QAMD_THD_16QAM_1_reg                                           0xB80E8984
#define  DVBC_OPT_QAMD_THD_16QAM_1_inst_addr                                     "0x015E"
#define  set_DVBC_OPT_QAMD_THD_16QAM_1_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_16QAM_1_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_16QAM_1_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_16QAM_1_reg))
#define  DVBC_OPT_QAMD_THD_16QAM_1_opt_qamd_thd_16qam_9_8_shift                  (0)
#define  DVBC_OPT_QAMD_THD_16QAM_1_opt_qamd_thd_16qam_9_8_mask                   (0x00000003)
#define  DVBC_OPT_QAMD_THD_16QAM_1_opt_qamd_thd_16qam_9_8(data)                  (0x00000003&(data))
#define  DVBC_OPT_QAMD_THD_16QAM_1_get_opt_qamd_thd_16qam_9_8(data)              (0x00000003&(data))

#define  DVBC_OPT_QAMD_THD_256QAM                                                0x180E8988
#define  DVBC_OPT_QAMD_THD_256QAM_reg_addr                                       "0xB80E8988"
#define  DVBC_OPT_QAMD_THD_256QAM_reg                                            0xB80E8988
#define  DVBC_OPT_QAMD_THD_256QAM_inst_addr                                      "0x015F"
#define  set_DVBC_OPT_QAMD_THD_256QAM_reg(data)                                  (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_256QAM_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_256QAM_reg                                        (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_256QAM_reg))
#define  DVBC_OPT_QAMD_THD_256QAM_opt_qamd_thd_256qam_7_0_shift                  (0)
#define  DVBC_OPT_QAMD_THD_256QAM_opt_qamd_thd_256qam_7_0_mask                   (0x000000FF)
#define  DVBC_OPT_QAMD_THD_256QAM_opt_qamd_thd_256qam_7_0(data)                  (0x000000FF&(data))
#define  DVBC_OPT_QAMD_THD_256QAM_get_opt_qamd_thd_256qam_7_0(data)              (0x000000FF&(data))

#define  DVBC_OPT_QAMD_THD_256QAM_1                                              0x180E898C
#define  DVBC_OPT_QAMD_THD_256QAM_1_reg_addr                                     "0xB80E898C"
#define  DVBC_OPT_QAMD_THD_256QAM_1_reg                                          0xB80E898C
#define  DVBC_OPT_QAMD_THD_256QAM_1_inst_addr                                    "0x0160"
#define  set_DVBC_OPT_QAMD_THD_256QAM_1_reg(data)                                (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_256QAM_1_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_256QAM_1_reg                                      (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_256QAM_1_reg))
#define  DVBC_OPT_QAMD_THD_256QAM_1_opt_qamd_thd_256qam_9_8_shift                (0)
#define  DVBC_OPT_QAMD_THD_256QAM_1_opt_qamd_thd_256qam_9_8_mask                 (0x00000003)
#define  DVBC_OPT_QAMD_THD_256QAM_1_opt_qamd_thd_256qam_9_8(data)                (0x00000003&(data))
#define  DVBC_OPT_QAMD_THD_256QAM_1_get_opt_qamd_thd_256qam_9_8(data)            (0x00000003&(data))

#define  DVBC_OPT_QAMD_THD_32QAM                                                 0x180E8990
#define  DVBC_OPT_QAMD_THD_32QAM_reg_addr                                        "0xB80E8990"
#define  DVBC_OPT_QAMD_THD_32QAM_reg                                             0xB80E8990
#define  DVBC_OPT_QAMD_THD_32QAM_inst_addr                                       "0x0161"
#define  set_DVBC_OPT_QAMD_THD_32QAM_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_32QAM_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_32QAM_reg                                         (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_32QAM_reg))
#define  DVBC_OPT_QAMD_THD_32QAM_opt_qamd_thd_32qam_7_0_shift                    (0)
#define  DVBC_OPT_QAMD_THD_32QAM_opt_qamd_thd_32qam_7_0_mask                     (0x000000FF)
#define  DVBC_OPT_QAMD_THD_32QAM_opt_qamd_thd_32qam_7_0(data)                    (0x000000FF&(data))
#define  DVBC_OPT_QAMD_THD_32QAM_get_opt_qamd_thd_32qam_7_0(data)                (0x000000FF&(data))

#define  DVBC_OPT_QAMD_THD_32QAM_1                                               0x180E8994
#define  DVBC_OPT_QAMD_THD_32QAM_1_reg_addr                                      "0xB80E8994"
#define  DVBC_OPT_QAMD_THD_32QAM_1_reg                                           0xB80E8994
#define  DVBC_OPT_QAMD_THD_32QAM_1_inst_addr                                     "0x0162"
#define  set_DVBC_OPT_QAMD_THD_32QAM_1_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_32QAM_1_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_32QAM_1_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_32QAM_1_reg))
#define  DVBC_OPT_QAMD_THD_32QAM_1_opt_qamd_thd_32qam_9_8_shift                  (0)
#define  DVBC_OPT_QAMD_THD_32QAM_1_opt_qamd_thd_32qam_9_8_mask                   (0x00000003)
#define  DVBC_OPT_QAMD_THD_32QAM_1_opt_qamd_thd_32qam_9_8(data)                  (0x00000003&(data))
#define  DVBC_OPT_QAMD_THD_32QAM_1_get_opt_qamd_thd_32qam_9_8(data)              (0x00000003&(data))

#define  DVBC_OPT_QAMD_THD_64QAM                                                 0x180E8998
#define  DVBC_OPT_QAMD_THD_64QAM_reg_addr                                        "0xB80E8998"
#define  DVBC_OPT_QAMD_THD_64QAM_reg                                             0xB80E8998
#define  DVBC_OPT_QAMD_THD_64QAM_inst_addr                                       "0x0163"
#define  set_DVBC_OPT_QAMD_THD_64QAM_reg(data)                                   (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_64QAM_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_64QAM_reg                                         (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_64QAM_reg))
#define  DVBC_OPT_QAMD_THD_64QAM_opt_qamd_thd_64qam_7_0_shift                    (0)
#define  DVBC_OPT_QAMD_THD_64QAM_opt_qamd_thd_64qam_7_0_mask                     (0x000000FF)
#define  DVBC_OPT_QAMD_THD_64QAM_opt_qamd_thd_64qam_7_0(data)                    (0x000000FF&(data))
#define  DVBC_OPT_QAMD_THD_64QAM_get_opt_qamd_thd_64qam_7_0(data)                (0x000000FF&(data))

#define  DVBC_OPT_QAMD_THD_64QAM_1                                               0x180E899C
#define  DVBC_OPT_QAMD_THD_64QAM_1_reg_addr                                      "0xB80E899C"
#define  DVBC_OPT_QAMD_THD_64QAM_1_reg                                           0xB80E899C
#define  DVBC_OPT_QAMD_THD_64QAM_1_inst_addr                                     "0x0164"
#define  set_DVBC_OPT_QAMD_THD_64QAM_1_reg(data)                                 (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_64QAM_1_reg)=data)
#define  get_DVBC_OPT_QAMD_THD_64QAM_1_reg                                       (*((volatile unsigned int*)DVBC_OPT_QAMD_THD_64QAM_1_reg))
#define  DVBC_OPT_QAMD_THD_64QAM_1_opt_qamd_thd_64qam_9_8_shift                  (0)
#define  DVBC_OPT_QAMD_THD_64QAM_1_opt_qamd_thd_64qam_9_8_mask                   (0x00000003)
#define  DVBC_OPT_QAMD_THD_64QAM_1_opt_qamd_thd_64qam_9_8(data)                  (0x00000003&(data))
#define  DVBC_OPT_QAMD_THD_64QAM_1_get_opt_qamd_thd_64qam_9_8(data)              (0x00000003&(data))

#define  DVBC_OPT_START_SRS_NBD                                                  0x180E89A0
#define  DVBC_OPT_START_SRS_NBD_reg_addr                                         "0xB80E89A0"
#define  DVBC_OPT_START_SRS_NBD_reg                                              0xB80E89A0
#define  DVBC_OPT_START_SRS_NBD_inst_addr                                        "0x0165"
#define  set_DVBC_OPT_START_SRS_NBD_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_START_SRS_NBD_reg)=data)
#define  get_DVBC_OPT_START_SRS_NBD_reg                                          (*((volatile unsigned int*)DVBC_OPT_START_SRS_NBD_reg))
#define  DVBC_OPT_START_SRS_NBD_opt_start_srs_nbd_shift                          (0)
#define  DVBC_OPT_START_SRS_NBD_opt_start_srs_nbd_mask                           (0x00000001)
#define  DVBC_OPT_START_SRS_NBD_opt_start_srs_nbd(data)                          (0x00000001&(data))
#define  DVBC_OPT_START_SRS_NBD_get_opt_start_srs_nbd(data)                      (0x00000001&(data))

#define  DVBC_NBD_TDFT_OUT                                                       0x180E89A4
#define  DVBC_NBD_TDFT_OUT_reg_addr                                              "0xB80E89A4"
#define  DVBC_NBD_TDFT_OUT_reg                                                   0xB80E89A4
#define  DVBC_NBD_TDFT_OUT_inst_addr                                             "0x0166"
#define  set_DVBC_NBD_TDFT_OUT_reg(data)                                         (*((volatile unsigned int*)DVBC_NBD_TDFT_OUT_reg)=data)
#define  get_DVBC_NBD_TDFT_OUT_reg                                               (*((volatile unsigned int*)DVBC_NBD_TDFT_OUT_reg))
#define  DVBC_NBD_TDFT_OUT_nbd_tdft_out_7_0_shift                                (0)
#define  DVBC_NBD_TDFT_OUT_nbd_tdft_out_7_0_mask                                 (0x000000FF)
#define  DVBC_NBD_TDFT_OUT_nbd_tdft_out_7_0(data)                                (0x000000FF&(data))
#define  DVBC_NBD_TDFT_OUT_get_nbd_tdft_out_7_0(data)                            (0x000000FF&(data))

#define  DVBC_NBD_TDFT_OUT_1                                                     0x180E89A8
#define  DVBC_NBD_TDFT_OUT_1_reg_addr                                            "0xB80E89A8"
#define  DVBC_NBD_TDFT_OUT_1_reg                                                 0xB80E89A8
#define  DVBC_NBD_TDFT_OUT_1_inst_addr                                           "0x0167"
#define  set_DVBC_NBD_TDFT_OUT_1_reg(data)                                       (*((volatile unsigned int*)DVBC_NBD_TDFT_OUT_1_reg)=data)
#define  get_DVBC_NBD_TDFT_OUT_1_reg                                             (*((volatile unsigned int*)DVBC_NBD_TDFT_OUT_1_reg))
#define  DVBC_NBD_TDFT_OUT_1_nbd_tdft_out_15_8_shift                             (0)
#define  DVBC_NBD_TDFT_OUT_1_nbd_tdft_out_15_8_mask                              (0x000000FF)
#define  DVBC_NBD_TDFT_OUT_1_nbd_tdft_out_15_8(data)                             (0x000000FF&(data))
#define  DVBC_NBD_TDFT_OUT_1_get_nbd_tdft_out_15_8(data)                         (0x000000FF&(data))

#define  DVBC_MIN_MAX_SR_INI_CNT                                                 0x180E89AC
#define  DVBC_MIN_MAX_SR_INI_CNT_reg_addr                                        "0xB80E89AC"
#define  DVBC_MIN_MAX_SR_INI_CNT_reg                                             0xB80E89AC
#define  DVBC_MIN_MAX_SR_INI_CNT_inst_addr                                       "0x0168"
#define  set_DVBC_MIN_MAX_SR_INI_CNT_reg(data)                                   (*((volatile unsigned int*)DVBC_MIN_MAX_SR_INI_CNT_reg)=data)
#define  get_DVBC_MIN_MAX_SR_INI_CNT_reg                                         (*((volatile unsigned int*)DVBC_MIN_MAX_SR_INI_CNT_reg))
#define  DVBC_MIN_MAX_SR_INI_CNT_min_max_sr_ini_cnt_shift                        (0)
#define  DVBC_MIN_MAX_SR_INI_CNT_min_max_sr_ini_cnt_mask                         (0x0000001F)
#define  DVBC_MIN_MAX_SR_INI_CNT_min_max_sr_ini_cnt(data)                        (0x0000001F&(data))
#define  DVBC_MIN_MAX_SR_INI_CNT_get_min_max_sr_ini_cnt(data)                    (0x0000001F&(data))

#define  DVBC_POS_TONE_MAX_VAL_0                                                 0x180E89B0
#define  DVBC_POS_TONE_MAX_VAL_0_reg_addr                                        "0xB80E89B0"
#define  DVBC_POS_TONE_MAX_VAL_0_reg                                             0xB80E89B0
#define  DVBC_POS_TONE_MAX_VAL_0_inst_addr                                       "0x0169"
#define  set_DVBC_POS_TONE_MAX_VAL_0_reg(data)                                   (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_0_reg)=data)
#define  get_DVBC_POS_TONE_MAX_VAL_0_reg                                         (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_0_reg))
#define  DVBC_POS_TONE_MAX_VAL_0_pos_tone_max_val_0_7_0_shift                    (0)
#define  DVBC_POS_TONE_MAX_VAL_0_pos_tone_max_val_0_7_0_mask                     (0x000000FF)
#define  DVBC_POS_TONE_MAX_VAL_0_pos_tone_max_val_0_7_0(data)                    (0x000000FF&(data))
#define  DVBC_POS_TONE_MAX_VAL_0_get_pos_tone_max_val_0_7_0(data)                (0x000000FF&(data))

#define  DVBC_POS_TONE_MAX_VAL_0_1                                               0x180E89B4
#define  DVBC_POS_TONE_MAX_VAL_0_1_reg_addr                                      "0xB80E89B4"
#define  DVBC_POS_TONE_MAX_VAL_0_1_reg                                           0xB80E89B4
#define  DVBC_POS_TONE_MAX_VAL_0_1_inst_addr                                     "0x016A"
#define  set_DVBC_POS_TONE_MAX_VAL_0_1_reg(data)                                 (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_0_1_reg)=data)
#define  get_DVBC_POS_TONE_MAX_VAL_0_1_reg                                       (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_0_1_reg))
#define  DVBC_POS_TONE_MAX_VAL_0_1_pos_tone_max_val_0_15_8_shift                 (0)
#define  DVBC_POS_TONE_MAX_VAL_0_1_pos_tone_max_val_0_15_8_mask                  (0x000000FF)
#define  DVBC_POS_TONE_MAX_VAL_0_1_pos_tone_max_val_0_15_8(data)                 (0x000000FF&(data))
#define  DVBC_POS_TONE_MAX_VAL_0_1_get_pos_tone_max_val_0_15_8(data)             (0x000000FF&(data))

#define  DVBC_POS_TONE_MAX_VAL_1                                                 0x180E89B8
#define  DVBC_POS_TONE_MAX_VAL_1_reg_addr                                        "0xB80E89B8"
#define  DVBC_POS_TONE_MAX_VAL_1_reg                                             0xB80E89B8
#define  DVBC_POS_TONE_MAX_VAL_1_inst_addr                                       "0x016B"
#define  set_DVBC_POS_TONE_MAX_VAL_1_reg(data)                                   (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_1_reg)=data)
#define  get_DVBC_POS_TONE_MAX_VAL_1_reg                                         (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_1_reg))
#define  DVBC_POS_TONE_MAX_VAL_1_pos_tone_max_val_1_7_0_shift                    (0)
#define  DVBC_POS_TONE_MAX_VAL_1_pos_tone_max_val_1_7_0_mask                     (0x000000FF)
#define  DVBC_POS_TONE_MAX_VAL_1_pos_tone_max_val_1_7_0(data)                    (0x000000FF&(data))
#define  DVBC_POS_TONE_MAX_VAL_1_get_pos_tone_max_val_1_7_0(data)                (0x000000FF&(data))

#define  DVBC_POS_TONE_MAX_VAL_1_1                                               0x180E89BC
#define  DVBC_POS_TONE_MAX_VAL_1_1_reg_addr                                      "0xB80E89BC"
#define  DVBC_POS_TONE_MAX_VAL_1_1_reg                                           0xB80E89BC
#define  DVBC_POS_TONE_MAX_VAL_1_1_inst_addr                                     "0x016C"
#define  set_DVBC_POS_TONE_MAX_VAL_1_1_reg(data)                                 (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_1_1_reg)=data)
#define  get_DVBC_POS_TONE_MAX_VAL_1_1_reg                                       (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_1_1_reg))
#define  DVBC_POS_TONE_MAX_VAL_1_1_pos_tone_max_val_1_15_8_shift                 (0)
#define  DVBC_POS_TONE_MAX_VAL_1_1_pos_tone_max_val_1_15_8_mask                  (0x000000FF)
#define  DVBC_POS_TONE_MAX_VAL_1_1_pos_tone_max_val_1_15_8(data)                 (0x000000FF&(data))
#define  DVBC_POS_TONE_MAX_VAL_1_1_get_pos_tone_max_val_1_15_8(data)             (0x000000FF&(data))

#define  DVBC_POS_TONE_MAX_VAL_2                                                 0x180E89C0
#define  DVBC_POS_TONE_MAX_VAL_2_reg_addr                                        "0xB80E89C0"
#define  DVBC_POS_TONE_MAX_VAL_2_reg                                             0xB80E89C0
#define  DVBC_POS_TONE_MAX_VAL_2_inst_addr                                       "0x016D"
#define  set_DVBC_POS_TONE_MAX_VAL_2_reg(data)                                   (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_2_reg)=data)
#define  get_DVBC_POS_TONE_MAX_VAL_2_reg                                         (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_2_reg))
#define  DVBC_POS_TONE_MAX_VAL_2_pos_tone_max_val_2_7_0_shift                    (0)
#define  DVBC_POS_TONE_MAX_VAL_2_pos_tone_max_val_2_7_0_mask                     (0x000000FF)
#define  DVBC_POS_TONE_MAX_VAL_2_pos_tone_max_val_2_7_0(data)                    (0x000000FF&(data))
#define  DVBC_POS_TONE_MAX_VAL_2_get_pos_tone_max_val_2_7_0(data)                (0x000000FF&(data))

#define  DVBC_POS_TONE_MAX_VAL_2_1                                               0x180E89C4
#define  DVBC_POS_TONE_MAX_VAL_2_1_reg_addr                                      "0xB80E89C4"
#define  DVBC_POS_TONE_MAX_VAL_2_1_reg                                           0xB80E89C4
#define  DVBC_POS_TONE_MAX_VAL_2_1_inst_addr                                     "0x016E"
#define  set_DVBC_POS_TONE_MAX_VAL_2_1_reg(data)                                 (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_2_1_reg)=data)
#define  get_DVBC_POS_TONE_MAX_VAL_2_1_reg                                       (*((volatile unsigned int*)DVBC_POS_TONE_MAX_VAL_2_1_reg))
#define  DVBC_POS_TONE_MAX_VAL_2_1_pos_tone_max_val_2_15_8_shift                 (0)
#define  DVBC_POS_TONE_MAX_VAL_2_1_pos_tone_max_val_2_15_8_mask                  (0x000000FF)
#define  DVBC_POS_TONE_MAX_VAL_2_1_pos_tone_max_val_2_15_8(data)                 (0x000000FF&(data))
#define  DVBC_POS_TONE_MAX_VAL_2_1_get_pos_tone_max_val_2_15_8(data)             (0x000000FF&(data))

#define  DVBC_POS_TONE_MAX_IDX_0                                                 0x180E89C8
#define  DVBC_POS_TONE_MAX_IDX_0_reg_addr                                        "0xB80E89C8"
#define  DVBC_POS_TONE_MAX_IDX_0_reg                                             0xB80E89C8
#define  DVBC_POS_TONE_MAX_IDX_0_inst_addr                                       "0x016F"
#define  set_DVBC_POS_TONE_MAX_IDX_0_reg(data)                                   (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_0_reg)=data)
#define  get_DVBC_POS_TONE_MAX_IDX_0_reg                                         (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_0_reg))
#define  DVBC_POS_TONE_MAX_IDX_0_pos_tone_max_idx_0_7_0_shift                    (0)
#define  DVBC_POS_TONE_MAX_IDX_0_pos_tone_max_idx_0_7_0_mask                     (0x000000FF)
#define  DVBC_POS_TONE_MAX_IDX_0_pos_tone_max_idx_0_7_0(data)                    (0x000000FF&(data))
#define  DVBC_POS_TONE_MAX_IDX_0_get_pos_tone_max_idx_0_7_0(data)                (0x000000FF&(data))

#define  DVBC_POS_TONE_MAX_IDX_0_1                                               0x180E89CC
#define  DVBC_POS_TONE_MAX_IDX_0_1_reg_addr                                      "0xB80E89CC"
#define  DVBC_POS_TONE_MAX_IDX_0_1_reg                                           0xB80E89CC
#define  DVBC_POS_TONE_MAX_IDX_0_1_inst_addr                                     "0x0170"
#define  set_DVBC_POS_TONE_MAX_IDX_0_1_reg(data)                                 (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_0_1_reg)=data)
#define  get_DVBC_POS_TONE_MAX_IDX_0_1_reg                                       (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_0_1_reg))
#define  DVBC_POS_TONE_MAX_IDX_0_1_pos_tone_max_idx_0_11_8_shift                 (0)
#define  DVBC_POS_TONE_MAX_IDX_0_1_pos_tone_max_idx_0_11_8_mask                  (0x0000000F)
#define  DVBC_POS_TONE_MAX_IDX_0_1_pos_tone_max_idx_0_11_8(data)                 (0x0000000F&(data))
#define  DVBC_POS_TONE_MAX_IDX_0_1_get_pos_tone_max_idx_0_11_8(data)             (0x0000000F&(data))

#define  DVBC_POS_TONE_MAX_IDX_1                                                 0x180E89D0
#define  DVBC_POS_TONE_MAX_IDX_1_reg_addr                                        "0xB80E89D0"
#define  DVBC_POS_TONE_MAX_IDX_1_reg                                             0xB80E89D0
#define  DVBC_POS_TONE_MAX_IDX_1_inst_addr                                       "0x0171"
#define  set_DVBC_POS_TONE_MAX_IDX_1_reg(data)                                   (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_1_reg)=data)
#define  get_DVBC_POS_TONE_MAX_IDX_1_reg                                         (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_1_reg))
#define  DVBC_POS_TONE_MAX_IDX_1_pos_tone_max_idx_1_7_0_shift                    (0)
#define  DVBC_POS_TONE_MAX_IDX_1_pos_tone_max_idx_1_7_0_mask                     (0x000000FF)
#define  DVBC_POS_TONE_MAX_IDX_1_pos_tone_max_idx_1_7_0(data)                    (0x000000FF&(data))
#define  DVBC_POS_TONE_MAX_IDX_1_get_pos_tone_max_idx_1_7_0(data)                (0x000000FF&(data))

#define  DVBC_POS_TONE_MAX_IDX_1_1                                               0x180E89D4
#define  DVBC_POS_TONE_MAX_IDX_1_1_reg_addr                                      "0xB80E89D4"
#define  DVBC_POS_TONE_MAX_IDX_1_1_reg                                           0xB80E89D4
#define  DVBC_POS_TONE_MAX_IDX_1_1_inst_addr                                     "0x0172"
#define  set_DVBC_POS_TONE_MAX_IDX_1_1_reg(data)                                 (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_1_1_reg)=data)
#define  get_DVBC_POS_TONE_MAX_IDX_1_1_reg                                       (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_1_1_reg))
#define  DVBC_POS_TONE_MAX_IDX_1_1_pos_tone_max_idx_1_11_8_shift                 (0)
#define  DVBC_POS_TONE_MAX_IDX_1_1_pos_tone_max_idx_1_11_8_mask                  (0x0000000F)
#define  DVBC_POS_TONE_MAX_IDX_1_1_pos_tone_max_idx_1_11_8(data)                 (0x0000000F&(data))
#define  DVBC_POS_TONE_MAX_IDX_1_1_get_pos_tone_max_idx_1_11_8(data)             (0x0000000F&(data))

#define  DVBC_POS_TONE_MAX_IDX_2                                                 0x180E89D8
#define  DVBC_POS_TONE_MAX_IDX_2_reg_addr                                        "0xB80E89D8"
#define  DVBC_POS_TONE_MAX_IDX_2_reg                                             0xB80E89D8
#define  DVBC_POS_TONE_MAX_IDX_2_inst_addr                                       "0x0173"
#define  set_DVBC_POS_TONE_MAX_IDX_2_reg(data)                                   (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_2_reg)=data)
#define  get_DVBC_POS_TONE_MAX_IDX_2_reg                                         (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_2_reg))
#define  DVBC_POS_TONE_MAX_IDX_2_pos_tone_max_idx_2_7_0_shift                    (0)
#define  DVBC_POS_TONE_MAX_IDX_2_pos_tone_max_idx_2_7_0_mask                     (0x000000FF)
#define  DVBC_POS_TONE_MAX_IDX_2_pos_tone_max_idx_2_7_0(data)                    (0x000000FF&(data))
#define  DVBC_POS_TONE_MAX_IDX_2_get_pos_tone_max_idx_2_7_0(data)                (0x000000FF&(data))

#define  DVBC_QAM_CON_BIT_DET                                                    0x180E89DC
#define  DVBC_QAM_CON_BIT_DET_reg_addr                                           "0xB80E89DC"
#define  DVBC_QAM_CON_BIT_DET_reg                                                0xB80E89DC
#define  DVBC_QAM_CON_BIT_DET_inst_addr                                          "0x0174"
#define  set_DVBC_QAM_CON_BIT_DET_reg(data)                                      (*((volatile unsigned int*)DVBC_QAM_CON_BIT_DET_reg)=data)
#define  get_DVBC_QAM_CON_BIT_DET_reg                                            (*((volatile unsigned int*)DVBC_QAM_CON_BIT_DET_reg))
#define  DVBC_QAM_CON_BIT_DET_qam_con_bit_det_shift                              (0)
#define  DVBC_QAM_CON_BIT_DET_qam_con_bit_det_mask                               (0x0000000F)
#define  DVBC_QAM_CON_BIT_DET_qam_con_bit_det(data)                              (0x0000000F&(data))
#define  DVBC_QAM_CON_BIT_DET_get_qam_con_bit_det(data)                          (0x0000000F&(data))

#define  DVBC_QAMD_RV_ZN0_CDF                                                    0x180E89E0
#define  DVBC_QAMD_RV_ZN0_CDF_reg_addr                                           "0xB80E89E0"
#define  DVBC_QAMD_RV_ZN0_CDF_reg                                                0xB80E89E0
#define  DVBC_QAMD_RV_ZN0_CDF_inst_addr                                          "0x0175"
#define  set_DVBC_QAMD_RV_ZN0_CDF_reg(data)                                      (*((volatile unsigned int*)DVBC_QAMD_RV_ZN0_CDF_reg)=data)
#define  get_DVBC_QAMD_RV_ZN0_CDF_reg                                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN0_CDF_reg))
#define  DVBC_QAMD_RV_ZN0_CDF_qamd_rv_zn0_cdf_7_0_shift                          (0)
#define  DVBC_QAMD_RV_ZN0_CDF_qamd_rv_zn0_cdf_7_0_mask                           (0x000000FF)
#define  DVBC_QAMD_RV_ZN0_CDF_qamd_rv_zn0_cdf_7_0(data)                          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN0_CDF_get_qamd_rv_zn0_cdf_7_0(data)                      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN0_CDF_1                                                  0x180E89E4
#define  DVBC_QAMD_RV_ZN0_CDF_1_reg_addr                                         "0xB80E89E4"
#define  DVBC_QAMD_RV_ZN0_CDF_1_reg                                              0xB80E89E4
#define  DVBC_QAMD_RV_ZN0_CDF_1_inst_addr                                        "0x0176"
#define  set_DVBC_QAMD_RV_ZN0_CDF_1_reg(data)                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN0_CDF_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN0_CDF_1_reg                                          (*((volatile unsigned int*)DVBC_QAMD_RV_ZN0_CDF_1_reg))
#define  DVBC_QAMD_RV_ZN0_CDF_1_qamd_rv_zn0_cdf_9_8_shift                        (0)
#define  DVBC_QAMD_RV_ZN0_CDF_1_qamd_rv_zn0_cdf_9_8_mask                         (0x00000003)
#define  DVBC_QAMD_RV_ZN0_CDF_1_qamd_rv_zn0_cdf_9_8(data)                        (0x00000003&(data))
#define  DVBC_QAMD_RV_ZN0_CDF_1_get_qamd_rv_zn0_cdf_9_8(data)                    (0x00000003&(data))

#define  DVBC_QAMD_RV_ZN1_CDF                                                    0x180E89E8
#define  DVBC_QAMD_RV_ZN1_CDF_reg_addr                                           "0xB80E89E8"
#define  DVBC_QAMD_RV_ZN1_CDF_reg                                                0xB80E89E8
#define  DVBC_QAMD_RV_ZN1_CDF_inst_addr                                          "0x0177"
#define  set_DVBC_QAMD_RV_ZN1_CDF_reg(data)                                      (*((volatile unsigned int*)DVBC_QAMD_RV_ZN1_CDF_reg)=data)
#define  get_DVBC_QAMD_RV_ZN1_CDF_reg                                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN1_CDF_reg))
#define  DVBC_QAMD_RV_ZN1_CDF_qamd_rv_zn1_cdf_7_0_shift                          (0)
#define  DVBC_QAMD_RV_ZN1_CDF_qamd_rv_zn1_cdf_7_0_mask                           (0x000000FF)
#define  DVBC_QAMD_RV_ZN1_CDF_qamd_rv_zn1_cdf_7_0(data)                          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN1_CDF_get_qamd_rv_zn1_cdf_7_0(data)                      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN1_CDF_1                                                  0x180E89EC
#define  DVBC_QAMD_RV_ZN1_CDF_1_reg_addr                                         "0xB80E89EC"
#define  DVBC_QAMD_RV_ZN1_CDF_1_reg                                              0xB80E89EC
#define  DVBC_QAMD_RV_ZN1_CDF_1_inst_addr                                        "0x0178"
#define  set_DVBC_QAMD_RV_ZN1_CDF_1_reg(data)                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN1_CDF_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN1_CDF_1_reg                                          (*((volatile unsigned int*)DVBC_QAMD_RV_ZN1_CDF_1_reg))
#define  DVBC_QAMD_RV_ZN1_CDF_1_qamd_rv_zn1_cdf_9_8_shift                        (0)
#define  DVBC_QAMD_RV_ZN1_CDF_1_qamd_rv_zn1_cdf_9_8_mask                         (0x00000003)
#define  DVBC_QAMD_RV_ZN1_CDF_1_qamd_rv_zn1_cdf_9_8(data)                        (0x00000003&(data))
#define  DVBC_QAMD_RV_ZN1_CDF_1_get_qamd_rv_zn1_cdf_9_8(data)                    (0x00000003&(data))

#define  DVBC_QAMD_RV_ZN2_CDF                                                    0x180E89F0
#define  DVBC_QAMD_RV_ZN2_CDF_reg_addr                                           "0xB80E89F0"
#define  DVBC_QAMD_RV_ZN2_CDF_reg                                                0xB80E89F0
#define  DVBC_QAMD_RV_ZN2_CDF_inst_addr                                          "0x0179"
#define  set_DVBC_QAMD_RV_ZN2_CDF_reg(data)                                      (*((volatile unsigned int*)DVBC_QAMD_RV_ZN2_CDF_reg)=data)
#define  get_DVBC_QAMD_RV_ZN2_CDF_reg                                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN2_CDF_reg))
#define  DVBC_QAMD_RV_ZN2_CDF_qamd_rv_zn2_cdf_7_0_shift                          (0)
#define  DVBC_QAMD_RV_ZN2_CDF_qamd_rv_zn2_cdf_7_0_mask                           (0x000000FF)
#define  DVBC_QAMD_RV_ZN2_CDF_qamd_rv_zn2_cdf_7_0(data)                          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN2_CDF_get_qamd_rv_zn2_cdf_7_0(data)                      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN2_CDF_1                                                  0x180E89F4
#define  DVBC_QAMD_RV_ZN2_CDF_1_reg_addr                                         "0xB80E89F4"
#define  DVBC_QAMD_RV_ZN2_CDF_1_reg                                              0xB80E89F4
#define  DVBC_QAMD_RV_ZN2_CDF_1_inst_addr                                        "0x017A"
#define  set_DVBC_QAMD_RV_ZN2_CDF_1_reg(data)                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN2_CDF_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN2_CDF_1_reg                                          (*((volatile unsigned int*)DVBC_QAMD_RV_ZN2_CDF_1_reg))
#define  DVBC_QAMD_RV_ZN2_CDF_1_qamd_rv_zn2_cdf_9_8_shift                        (0)
#define  DVBC_QAMD_RV_ZN2_CDF_1_qamd_rv_zn2_cdf_9_8_mask                         (0x00000003)
#define  DVBC_QAMD_RV_ZN2_CDF_1_qamd_rv_zn2_cdf_9_8(data)                        (0x00000003&(data))
#define  DVBC_QAMD_RV_ZN2_CDF_1_get_qamd_rv_zn2_cdf_9_8(data)                    (0x00000003&(data))

#define  DVBC_QAMD_RV_ZN3_CDF                                                    0x180E89F8
#define  DVBC_QAMD_RV_ZN3_CDF_reg_addr                                           "0xB80E89F8"
#define  DVBC_QAMD_RV_ZN3_CDF_reg                                                0xB80E89F8
#define  DVBC_QAMD_RV_ZN3_CDF_inst_addr                                          "0x017B"
#define  set_DVBC_QAMD_RV_ZN3_CDF_reg(data)                                      (*((volatile unsigned int*)DVBC_QAMD_RV_ZN3_CDF_reg)=data)
#define  get_DVBC_QAMD_RV_ZN3_CDF_reg                                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN3_CDF_reg))
#define  DVBC_QAMD_RV_ZN3_CDF_qamd_rv_zn3_cdf_7_0_shift                          (0)
#define  DVBC_QAMD_RV_ZN3_CDF_qamd_rv_zn3_cdf_7_0_mask                           (0x000000FF)
#define  DVBC_QAMD_RV_ZN3_CDF_qamd_rv_zn3_cdf_7_0(data)                          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN3_CDF_get_qamd_rv_zn3_cdf_7_0(data)                      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN3_CDF_1                                                  0x180E89FC
#define  DVBC_QAMD_RV_ZN3_CDF_1_reg_addr                                         "0xB80E89FC"
#define  DVBC_QAMD_RV_ZN3_CDF_1_reg                                              0xB80E89FC
#define  DVBC_QAMD_RV_ZN3_CDF_1_inst_addr                                        "0x017C"
#define  set_DVBC_QAMD_RV_ZN3_CDF_1_reg(data)                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN3_CDF_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN3_CDF_1_reg                                          (*((volatile unsigned int*)DVBC_QAMD_RV_ZN3_CDF_1_reg))
#define  DVBC_QAMD_RV_ZN3_CDF_1_qamd_rv_zn3_cdf_9_8_shift                        (0)
#define  DVBC_QAMD_RV_ZN3_CDF_1_qamd_rv_zn3_cdf_9_8_mask                         (0x00000003)
#define  DVBC_QAMD_RV_ZN3_CDF_1_qamd_rv_zn3_cdf_9_8(data)                        (0x00000003&(data))
#define  DVBC_QAMD_RV_ZN3_CDF_1_get_qamd_rv_zn3_cdf_9_8(data)                    (0x00000003&(data))

#define  DVBC_QAMD_RV_ZN4_CDF                                                    0x180E8A00
#define  DVBC_QAMD_RV_ZN4_CDF_reg_addr                                           "0xB80E8A00"
#define  DVBC_QAMD_RV_ZN4_CDF_reg                                                0xB80E8A00
#define  DVBC_QAMD_RV_ZN4_CDF_inst_addr                                          "0x017D"
#define  set_DVBC_QAMD_RV_ZN4_CDF_reg(data)                                      (*((volatile unsigned int*)DVBC_QAMD_RV_ZN4_CDF_reg)=data)
#define  get_DVBC_QAMD_RV_ZN4_CDF_reg                                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN4_CDF_reg))
#define  DVBC_QAMD_RV_ZN4_CDF_qamd_rv_zn4_cdf_7_0_shift                          (0)
#define  DVBC_QAMD_RV_ZN4_CDF_qamd_rv_zn4_cdf_7_0_mask                           (0x000000FF)
#define  DVBC_QAMD_RV_ZN4_CDF_qamd_rv_zn4_cdf_7_0(data)                          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN4_CDF_get_qamd_rv_zn4_cdf_7_0(data)                      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN4_CDF_1                                                  0x180E8A04
#define  DVBC_QAMD_RV_ZN4_CDF_1_reg_addr                                         "0xB80E8A04"
#define  DVBC_QAMD_RV_ZN4_CDF_1_reg                                              0xB80E8A04
#define  DVBC_QAMD_RV_ZN4_CDF_1_inst_addr                                        "0x017E"
#define  set_DVBC_QAMD_RV_ZN4_CDF_1_reg(data)                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN4_CDF_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN4_CDF_1_reg                                          (*((volatile unsigned int*)DVBC_QAMD_RV_ZN4_CDF_1_reg))
#define  DVBC_QAMD_RV_ZN4_CDF_1_qamd_rv_zn4_cdf_9_8_shift                        (0)
#define  DVBC_QAMD_RV_ZN4_CDF_1_qamd_rv_zn4_cdf_9_8_mask                         (0x00000003)
#define  DVBC_QAMD_RV_ZN4_CDF_1_qamd_rv_zn4_cdf_9_8(data)                        (0x00000003&(data))
#define  DVBC_QAMD_RV_ZN4_CDF_1_get_qamd_rv_zn4_cdf_9_8(data)                    (0x00000003&(data))

#define  DVBC_QAMD_RV_ZN5_CDF                                                    0x180E8A08
#define  DVBC_QAMD_RV_ZN5_CDF_reg_addr                                           "0xB80E8A08"
#define  DVBC_QAMD_RV_ZN5_CDF_reg                                                0xB80E8A08
#define  DVBC_QAMD_RV_ZN5_CDF_inst_addr                                          "0x017F"
#define  set_DVBC_QAMD_RV_ZN5_CDF_reg(data)                                      (*((volatile unsigned int*)DVBC_QAMD_RV_ZN5_CDF_reg)=data)
#define  get_DVBC_QAMD_RV_ZN5_CDF_reg                                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN5_CDF_reg))
#define  DVBC_QAMD_RV_ZN5_CDF_qamd_rv_zn5_cdf_7_0_shift                          (0)
#define  DVBC_QAMD_RV_ZN5_CDF_qamd_rv_zn5_cdf_7_0_mask                           (0x000000FF)
#define  DVBC_QAMD_RV_ZN5_CDF_qamd_rv_zn5_cdf_7_0(data)                          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN5_CDF_get_qamd_rv_zn5_cdf_7_0(data)                      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN5_CDF_1                                                  0x180E8A0C
#define  DVBC_QAMD_RV_ZN5_CDF_1_reg_addr                                         "0xB80E8A0C"
#define  DVBC_QAMD_RV_ZN5_CDF_1_reg                                              0xB80E8A0C
#define  DVBC_QAMD_RV_ZN5_CDF_1_inst_addr                                        "0x0180"
#define  set_DVBC_QAMD_RV_ZN5_CDF_1_reg(data)                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN5_CDF_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN5_CDF_1_reg                                          (*((volatile unsigned int*)DVBC_QAMD_RV_ZN5_CDF_1_reg))
#define  DVBC_QAMD_RV_ZN5_CDF_1_qamd_rv_zn5_cdf_9_8_shift                        (0)
#define  DVBC_QAMD_RV_ZN5_CDF_1_qamd_rv_zn5_cdf_9_8_mask                         (0x00000003)
#define  DVBC_QAMD_RV_ZN5_CDF_1_qamd_rv_zn5_cdf_9_8(data)                        (0x00000003&(data))
#define  DVBC_QAMD_RV_ZN5_CDF_1_get_qamd_rv_zn5_cdf_9_8(data)                    (0x00000003&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0                                            0x180E8A10
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_reg_addr                                   "0xB80E8A10"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_reg                                        0xB80E8A10
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_inst_addr                                  "0x0181"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_reg(data)                              (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_reg                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_qamd_rv_zn_cdf_acc_dif0_7_0_shift          (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_qamd_rv_zn_cdf_acc_dif0_7_0_mask           (0x000000FF)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_qamd_rv_zn_cdf_acc_dif0_7_0(data)          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_get_qamd_rv_zn_cdf_acc_dif0_7_0(data)      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1                                          0x180E8A14
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_reg_addr                                 "0xB80E8A14"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_reg                                      0xB80E8A14
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_inst_addr                                "0x0182"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_reg(data)                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_reg                                  (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_qamd_rv_zn_cdf_acc_dif0_10_8_shift       (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_qamd_rv_zn_cdf_acc_dif0_10_8_mask        (0x00000007)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_qamd_rv_zn_cdf_acc_dif0_10_8(data)       (0x00000007&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF0_1_get_qamd_rv_zn_cdf_acc_dif0_10_8(data)   (0x00000007&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1                                            0x180E8A18
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_reg_addr                                   "0xB80E8A18"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_reg                                        0xB80E8A18
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_inst_addr                                  "0x0183"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_reg(data)                              (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_reg                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_qamd_rv_zn_cdf_acc_dif1_7_0_shift          (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_qamd_rv_zn_cdf_acc_dif1_7_0_mask           (0x000000FF)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_qamd_rv_zn_cdf_acc_dif1_7_0(data)          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_get_qamd_rv_zn_cdf_acc_dif1_7_0(data)      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1                                          0x180E8A1C
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_reg_addr                                 "0xB80E8A1C"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_reg                                      0xB80E8A1C
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_inst_addr                                "0x0184"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_reg(data)                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_reg                                  (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_qamd_rv_zn_cdf_acc_dif1_10_8_shift       (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_qamd_rv_zn_cdf_acc_dif1_10_8_mask        (0x00000007)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_qamd_rv_zn_cdf_acc_dif1_10_8(data)       (0x00000007&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF1_1_get_qamd_rv_zn_cdf_acc_dif1_10_8(data)   (0x00000007&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2                                            0x180E8A20
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_reg_addr                                   "0xB80E8A20"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_reg                                        0xB80E8A20
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_inst_addr                                  "0x0185"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_reg(data)                              (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_reg                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_qamd_rv_zn_cdf_acc_dif2_7_0_shift          (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_qamd_rv_zn_cdf_acc_dif2_7_0_mask           (0x000000FF)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_qamd_rv_zn_cdf_acc_dif2_7_0(data)          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_get_qamd_rv_zn_cdf_acc_dif2_7_0(data)      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1                                          0x180E8A24
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_reg_addr                                 "0xB80E8A24"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_reg                                      0xB80E8A24
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_inst_addr                                "0x0186"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_reg(data)                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_reg                                  (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_qamd_rv_zn_cdf_acc_dif2_10_8_shift       (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_qamd_rv_zn_cdf_acc_dif2_10_8_mask        (0x00000007)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_qamd_rv_zn_cdf_acc_dif2_10_8(data)       (0x00000007&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF2_1_get_qamd_rv_zn_cdf_acc_dif2_10_8(data)   (0x00000007&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3                                            0x180E8A28
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_reg_addr                                   "0xB80E8A28"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_reg                                        0xB80E8A28
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_inst_addr                                  "0x0187"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_reg(data)                              (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_reg                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_qamd_rv_zn_cdf_acc_dif3_7_0_shift          (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_qamd_rv_zn_cdf_acc_dif3_7_0_mask           (0x000000FF)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_qamd_rv_zn_cdf_acc_dif3_7_0(data)          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_get_qamd_rv_zn_cdf_acc_dif3_7_0(data)      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1                                          0x180E8A2C
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_reg_addr                                 "0xB80E8A2C"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_reg                                      0xB80E8A2C
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_inst_addr                                "0x0188"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_reg(data)                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_reg                                  (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_qamd_rv_zn_cdf_acc_dif3_10_8_shift       (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_qamd_rv_zn_cdf_acc_dif3_10_8_mask        (0x00000007)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_qamd_rv_zn_cdf_acc_dif3_10_8(data)       (0x00000007&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF3_1_get_qamd_rv_zn_cdf_acc_dif3_10_8(data)   (0x00000007&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4                                            0x180E8A30
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_reg_addr                                   "0xB80E8A30"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_reg                                        0xB80E8A30
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_inst_addr                                  "0x0189"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_reg(data)                              (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_reg                                    (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_qamd_rv_zn_cdf_acc_dif4_7_0_shift          (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_qamd_rv_zn_cdf_acc_dif4_7_0_mask           (0x000000FF)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_qamd_rv_zn_cdf_acc_dif4_7_0(data)          (0x000000FF&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_get_qamd_rv_zn_cdf_acc_dif4_7_0(data)      (0x000000FF&(data))

#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1                                          0x180E8A34
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_reg_addr                                 "0xB80E8A34"
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_reg                                      0xB80E8A34
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_inst_addr                                "0x018A"
#define  set_DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_reg(data)                            (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_reg)=data)
#define  get_DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_reg                                  (*((volatile unsigned int*)DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_reg))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_qamd_rv_zn_cdf_acc_dif4_10_8_shift       (0)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_qamd_rv_zn_cdf_acc_dif4_10_8_mask        (0x00000007)
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_qamd_rv_zn_cdf_acc_dif4_10_8(data)       (0x00000007&(data))
#define  DVBC_QAMD_RV_ZN_CDF_ACC_DIF4_1_get_qamd_rv_zn_cdf_acc_dif4_10_8(data)   (0x00000007&(data))

#define  DVBC_REG_QAMD_DONE                                                      0x180E8A38
#define  DVBC_REG_QAMD_DONE_reg_addr                                             "0xB80E8A38"
#define  DVBC_REG_QAMD_DONE_reg                                                  0xB80E8A38
#define  DVBC_REG_QAMD_DONE_inst_addr                                            "0x018B"
#define  set_DVBC_REG_QAMD_DONE_reg(data)                                        (*((volatile unsigned int*)DVBC_REG_QAMD_DONE_reg)=data)
#define  get_DVBC_REG_QAMD_DONE_reg                                              (*((volatile unsigned int*)DVBC_REG_QAMD_DONE_reg))
#define  DVBC_REG_QAMD_DONE_reg_qamd_done_shift                                  (0)
#define  DVBC_REG_QAMD_DONE_reg_qamd_done_mask                                   (0x00000001)
#define  DVBC_REG_QAMD_DONE_reg_qamd_done(data)                                  (0x00000001&(data))
#define  DVBC_REG_QAMD_DONE_get_reg_qamd_done(data)                              (0x00000001&(data))

#define  DVBC_SOLT_AVG_POW_DIF                                                   0x180E8A3C
#define  DVBC_SOLT_AVG_POW_DIF_reg_addr                                          "0xB80E8A3C"
#define  DVBC_SOLT_AVG_POW_DIF_reg                                               0xB80E8A3C
#define  DVBC_SOLT_AVG_POW_DIF_inst_addr                                         "0x018C"
#define  set_DVBC_SOLT_AVG_POW_DIF_reg(data)                                     (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_DIF_reg)=data)
#define  get_DVBC_SOLT_AVG_POW_DIF_reg                                           (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_DIF_reg))
#define  DVBC_SOLT_AVG_POW_DIF_solt_avg_pow_dif_7_0_shift                        (0)
#define  DVBC_SOLT_AVG_POW_DIF_solt_avg_pow_dif_7_0_mask                         (0x000000FF)
#define  DVBC_SOLT_AVG_POW_DIF_solt_avg_pow_dif_7_0(data)                        (0x000000FF&(data))
#define  DVBC_SOLT_AVG_POW_DIF_get_solt_avg_pow_dif_7_0(data)                    (0x000000FF&(data))

#define  DVBC_SOLT_AVG_POW_DIF_1                                                 0x180E8A40
#define  DVBC_SOLT_AVG_POW_DIF_1_reg_addr                                        "0xB80E8A40"
#define  DVBC_SOLT_AVG_POW_DIF_1_reg                                             0xB80E8A40
#define  DVBC_SOLT_AVG_POW_DIF_1_inst_addr                                       "0x018D"
#define  set_DVBC_SOLT_AVG_POW_DIF_1_reg(data)                                   (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_DIF_1_reg)=data)
#define  get_DVBC_SOLT_AVG_POW_DIF_1_reg                                         (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_DIF_1_reg))
#define  DVBC_SOLT_AVG_POW_DIF_1_solt_avg_pow_dif_15_8_shift                     (0)
#define  DVBC_SOLT_AVG_POW_DIF_1_solt_avg_pow_dif_15_8_mask                      (0x000000FF)
#define  DVBC_SOLT_AVG_POW_DIF_1_solt_avg_pow_dif_15_8(data)                     (0x000000FF&(data))
#define  DVBC_SOLT_AVG_POW_DIF_1_get_solt_avg_pow_dif_15_8(data)                 (0x000000FF&(data))

#define  DVBC_SOLT_AVG_POW_MAX                                                   0x180E8A44
#define  DVBC_SOLT_AVG_POW_MAX_reg_addr                                          "0xB80E8A44"
#define  DVBC_SOLT_AVG_POW_MAX_reg                                               0xB80E8A44
#define  DVBC_SOLT_AVG_POW_MAX_inst_addr                                         "0x018E"
#define  set_DVBC_SOLT_AVG_POW_MAX_reg(data)                                     (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_MAX_reg)=data)
#define  get_DVBC_SOLT_AVG_POW_MAX_reg                                           (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_MAX_reg))
#define  DVBC_SOLT_AVG_POW_MAX_solt_avg_pow_max_7_0_shift                        (0)
#define  DVBC_SOLT_AVG_POW_MAX_solt_avg_pow_max_7_0_mask                         (0x000000FF)
#define  DVBC_SOLT_AVG_POW_MAX_solt_avg_pow_max_7_0(data)                        (0x000000FF&(data))
#define  DVBC_SOLT_AVG_POW_MAX_get_solt_avg_pow_max_7_0(data)                    (0x000000FF&(data))

#define  DVBC_SOLT_AVG_POW_MAX_1                                                 0x180E8A48
#define  DVBC_SOLT_AVG_POW_MAX_1_reg_addr                                        "0xB80E8A48"
#define  DVBC_SOLT_AVG_POW_MAX_1_reg                                             0xB80E8A48
#define  DVBC_SOLT_AVG_POW_MAX_1_inst_addr                                       "0x018F"
#define  set_DVBC_SOLT_AVG_POW_MAX_1_reg(data)                                   (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_MAX_1_reg)=data)
#define  get_DVBC_SOLT_AVG_POW_MAX_1_reg                                         (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_MAX_1_reg))
#define  DVBC_SOLT_AVG_POW_MAX_1_solt_avg_pow_max_15_8_shift                     (0)
#define  DVBC_SOLT_AVG_POW_MAX_1_solt_avg_pow_max_15_8_mask                      (0x000000FF)
#define  DVBC_SOLT_AVG_POW_MAX_1_solt_avg_pow_max_15_8(data)                     (0x000000FF&(data))
#define  DVBC_SOLT_AVG_POW_MAX_1_get_solt_avg_pow_max_15_8(data)                 (0x000000FF&(data))

#define  DVBC_SOLT_AVG_POW_MIN                                                   0x180E8A4C
#define  DVBC_SOLT_AVG_POW_MIN_reg_addr                                          "0xB80E8A4C"
#define  DVBC_SOLT_AVG_POW_MIN_reg                                               0xB80E8A4C
#define  DVBC_SOLT_AVG_POW_MIN_inst_addr                                         "0x0190"
#define  set_DVBC_SOLT_AVG_POW_MIN_reg(data)                                     (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_MIN_reg)=data)
#define  get_DVBC_SOLT_AVG_POW_MIN_reg                                           (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_MIN_reg))
#define  DVBC_SOLT_AVG_POW_MIN_solt_avg_pow_min_7_0_shift                        (0)
#define  DVBC_SOLT_AVG_POW_MIN_solt_avg_pow_min_7_0_mask                         (0x000000FF)
#define  DVBC_SOLT_AVG_POW_MIN_solt_avg_pow_min_7_0(data)                        (0x000000FF&(data))
#define  DVBC_SOLT_AVG_POW_MIN_get_solt_avg_pow_min_7_0(data)                    (0x000000FF&(data))

#define  DVBC_SOLT_AVG_POW_MIN_1                                                 0x180E8A50
#define  DVBC_SOLT_AVG_POW_MIN_1_reg_addr                                        "0xB80E8A50"
#define  DVBC_SOLT_AVG_POW_MIN_1_reg                                             0xB80E8A50
#define  DVBC_SOLT_AVG_POW_MIN_1_inst_addr                                       "0x0191"
#define  set_DVBC_SOLT_AVG_POW_MIN_1_reg(data)                                   (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_MIN_1_reg)=data)
#define  get_DVBC_SOLT_AVG_POW_MIN_1_reg                                         (*((volatile unsigned int*)DVBC_SOLT_AVG_POW_MIN_1_reg))
#define  DVBC_SOLT_AVG_POW_MIN_1_solt_avg_pow_min_15_8_shift                     (0)
#define  DVBC_SOLT_AVG_POW_MIN_1_solt_avg_pow_min_15_8_mask                      (0x000000FF)
#define  DVBC_SOLT_AVG_POW_MIN_1_solt_avg_pow_min_15_8(data)                     (0x000000FF&(data))
#define  DVBC_SOLT_AVG_POW_MIN_1_get_solt_avg_pow_min_15_8(data)                 (0x000000FF&(data))

#define  DVBC_SRS_NBD_DONE                                                       0x180E8A54
#define  DVBC_SRS_NBD_DONE_reg_addr                                              "0xB80E8A54"
#define  DVBC_SRS_NBD_DONE_reg                                                   0xB80E8A54
#define  DVBC_SRS_NBD_DONE_inst_addr                                             "0x0192"
#define  set_DVBC_SRS_NBD_DONE_reg(data)                                         (*((volatile unsigned int*)DVBC_SRS_NBD_DONE_reg)=data)
#define  get_DVBC_SRS_NBD_DONE_reg                                               (*((volatile unsigned int*)DVBC_SRS_NBD_DONE_reg))
#define  DVBC_SRS_NBD_DONE_srs_nbd_done_shift                                    (0)
#define  DVBC_SRS_NBD_DONE_srs_nbd_done_mask                                     (0x00000001)
#define  DVBC_SRS_NBD_DONE_srs_nbd_done(data)                                    (0x00000001&(data))
#define  DVBC_SRS_NBD_DONE_get_srs_nbd_done(data)                                (0x00000001&(data))

#define  DVBC_POS_TONE_MAX_IDX_2_1                                               0x180E8A58
#define  DVBC_POS_TONE_MAX_IDX_2_1_reg_addr                                      "0xB80E8A58"
#define  DVBC_POS_TONE_MAX_IDX_2_1_reg                                           0xB80E8A58
#define  DVBC_POS_TONE_MAX_IDX_2_1_inst_addr                                     "0x0193"
#define  set_DVBC_POS_TONE_MAX_IDX_2_1_reg(data)                                 (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_2_1_reg)=data)
#define  get_DVBC_POS_TONE_MAX_IDX_2_1_reg                                       (*((volatile unsigned int*)DVBC_POS_TONE_MAX_IDX_2_1_reg))
#define  DVBC_POS_TONE_MAX_IDX_2_1_pos_tone_max_idx_2_11_8_shift                 (0)
#define  DVBC_POS_TONE_MAX_IDX_2_1_pos_tone_max_idx_2_11_8_mask                  (0x0000000F)
#define  DVBC_POS_TONE_MAX_IDX_2_1_pos_tone_max_idx_2_11_8(data)                 (0x0000000F&(data))
#define  DVBC_POS_TONE_MAX_IDX_2_1_get_pos_tone_max_idx_2_11_8(data)             (0x0000000F&(data))

#define  DVBC_POS_SLOT_AVG_VAL_0                                                 0x180E8A5C
#define  DVBC_POS_SLOT_AVG_VAL_0_reg_addr                                        "0xB80E8A5C"
#define  DVBC_POS_SLOT_AVG_VAL_0_reg                                             0xB80E8A5C
#define  DVBC_POS_SLOT_AVG_VAL_0_inst_addr                                       "0x0194"
#define  set_DVBC_POS_SLOT_AVG_VAL_0_reg(data)                                   (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_0_reg)=data)
#define  get_DVBC_POS_SLOT_AVG_VAL_0_reg                                         (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_0_reg))
#define  DVBC_POS_SLOT_AVG_VAL_0_pos_slot_avg_val_0_7_0_shift                    (0)
#define  DVBC_POS_SLOT_AVG_VAL_0_pos_slot_avg_val_0_7_0_mask                     (0x000000FF)
#define  DVBC_POS_SLOT_AVG_VAL_0_pos_slot_avg_val_0_7_0(data)                    (0x000000FF&(data))
#define  DVBC_POS_SLOT_AVG_VAL_0_get_pos_slot_avg_val_0_7_0(data)                (0x000000FF&(data))

#define  DVBC_POS_SLOT_AVG_VAL_0_1                                               0x180E8A60
#define  DVBC_POS_SLOT_AVG_VAL_0_1_reg_addr                                      "0xB80E8A60"
#define  DVBC_POS_SLOT_AVG_VAL_0_1_reg                                           0xB80E8A60
#define  DVBC_POS_SLOT_AVG_VAL_0_1_inst_addr                                     "0x0195"
#define  set_DVBC_POS_SLOT_AVG_VAL_0_1_reg(data)                                 (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_0_1_reg)=data)
#define  get_DVBC_POS_SLOT_AVG_VAL_0_1_reg                                       (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_0_1_reg))
#define  DVBC_POS_SLOT_AVG_VAL_0_1_pos_slot_avg_val_0_15_8_shift                 (0)
#define  DVBC_POS_SLOT_AVG_VAL_0_1_pos_slot_avg_val_0_15_8_mask                  (0x000000FF)
#define  DVBC_POS_SLOT_AVG_VAL_0_1_pos_slot_avg_val_0_15_8(data)                 (0x000000FF&(data))
#define  DVBC_POS_SLOT_AVG_VAL_0_1_get_pos_slot_avg_val_0_15_8(data)             (0x000000FF&(data))

#define  DVBC_ROM_BIST_OUT_0                                                     0x180E8A64
#define  DVBC_ROM_BIST_OUT_0_reg_addr                                            "0xB80E8A64"
#define  DVBC_ROM_BIST_OUT_0_reg                                                 0xB80E8A64
#define  DVBC_ROM_BIST_OUT_0_inst_addr                                           "0x0196"
#define  set_DVBC_ROM_BIST_OUT_0_reg(data)                                       (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_0_reg)=data)
#define  get_DVBC_ROM_BIST_OUT_0_reg                                             (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_0_reg))
#define  DVBC_ROM_BIST_OUT_0_inrx_rom_bist_out01_7_0_shift                       (0)
#define  DVBC_ROM_BIST_OUT_0_inrx_rom_bist_out01_7_0_mask                        (0x000000FF)
#define  DVBC_ROM_BIST_OUT_0_inrx_rom_bist_out01_7_0(data)                       (0x000000FF&(data))
#define  DVBC_ROM_BIST_OUT_0_get_inrx_rom_bist_out01_7_0(data)                   (0x000000FF&(data))

#define  DVBC_ROM_BIST_OUT_1                                                     0x180E8A68
#define  DVBC_ROM_BIST_OUT_1_reg_addr                                            "0xB80E8A68"
#define  DVBC_ROM_BIST_OUT_1_reg                                                 0xB80E8A68
#define  DVBC_ROM_BIST_OUT_1_inst_addr                                           "0x0197"
#define  set_DVBC_ROM_BIST_OUT_1_reg(data)                                       (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_1_reg)=data)
#define  get_DVBC_ROM_BIST_OUT_1_reg                                             (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_1_reg))
#define  DVBC_ROM_BIST_OUT_1_inrx_rom_bist_out01_15_8_shift                      (0)
#define  DVBC_ROM_BIST_OUT_1_inrx_rom_bist_out01_15_8_mask                       (0x000000FF)
#define  DVBC_ROM_BIST_OUT_1_inrx_rom_bist_out01_15_8(data)                      (0x000000FF&(data))
#define  DVBC_ROM_BIST_OUT_1_get_inrx_rom_bist_out01_15_8(data)                  (0x000000FF&(data))

#define  DVBC_ROM_BIST_OUT_2                                                     0x180E8A6C
#define  DVBC_ROM_BIST_OUT_2_reg_addr                                            "0xB80E8A6C"
#define  DVBC_ROM_BIST_OUT_2_reg                                                 0xB80E8A6C
#define  DVBC_ROM_BIST_OUT_2_inst_addr                                           "0x0198"
#define  set_DVBC_ROM_BIST_OUT_2_reg(data)                                       (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_2_reg)=data)
#define  get_DVBC_ROM_BIST_OUT_2_reg                                             (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_2_reg))
#define  DVBC_ROM_BIST_OUT_2_inrx_rom_bist_out01_23_16_shift                     (0)
#define  DVBC_ROM_BIST_OUT_2_inrx_rom_bist_out01_23_16_mask                      (0x000000FF)
#define  DVBC_ROM_BIST_OUT_2_inrx_rom_bist_out01_23_16(data)                     (0x000000FF&(data))
#define  DVBC_ROM_BIST_OUT_2_get_inrx_rom_bist_out01_23_16(data)                 (0x000000FF&(data))

#define  DVBC_ROM_BIST_OUT_3                                                     0x180E8A70
#define  DVBC_ROM_BIST_OUT_3_reg_addr                                            "0xB80E8A70"
#define  DVBC_ROM_BIST_OUT_3_reg                                                 0xB80E8A70
#define  DVBC_ROM_BIST_OUT_3_inst_addr                                           "0x0199"
#define  set_DVBC_ROM_BIST_OUT_3_reg(data)                                       (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_3_reg)=data)
#define  get_DVBC_ROM_BIST_OUT_3_reg                                             (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_3_reg))
#define  DVBC_ROM_BIST_OUT_3_inrx_rom_bist_out01_31_24_shift                     (0)
#define  DVBC_ROM_BIST_OUT_3_inrx_rom_bist_out01_31_24_mask                      (0x000000FF)
#define  DVBC_ROM_BIST_OUT_3_inrx_rom_bist_out01_31_24(data)                     (0x000000FF&(data))
#define  DVBC_ROM_BIST_OUT_3_get_inrx_rom_bist_out01_31_24(data)                 (0x000000FF&(data))

#define  DVBC_ROM_BIST_OUT_4                                                     0x180E8A74
#define  DVBC_ROM_BIST_OUT_4_reg_addr                                            "0xB80E8A74"
#define  DVBC_ROM_BIST_OUT_4_reg                                                 0xB80E8A74
#define  DVBC_ROM_BIST_OUT_4_inst_addr                                           "0x019A"
#define  set_DVBC_ROM_BIST_OUT_4_reg(data)                                       (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_4_reg)=data)
#define  get_DVBC_ROM_BIST_OUT_4_reg                                             (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_4_reg))
#define  DVBC_ROM_BIST_OUT_4_inrx_rom_bist_out01_39_32_shift                     (0)
#define  DVBC_ROM_BIST_OUT_4_inrx_rom_bist_out01_39_32_mask                      (0x000000FF)
#define  DVBC_ROM_BIST_OUT_4_inrx_rom_bist_out01_39_32(data)                     (0x000000FF&(data))
#define  DVBC_ROM_BIST_OUT_4_get_inrx_rom_bist_out01_39_32(data)                 (0x000000FF&(data))

#define  DVBC_ROM_BIST_OUT_5                                                     0x180E8A78
#define  DVBC_ROM_BIST_OUT_5_reg_addr                                            "0xB80E8A78"
#define  DVBC_ROM_BIST_OUT_5_reg                                                 0xB80E8A78
#define  DVBC_ROM_BIST_OUT_5_inst_addr                                           "0x019B"
#define  set_DVBC_ROM_BIST_OUT_5_reg(data)                                       (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_5_reg)=data)
#define  get_DVBC_ROM_BIST_OUT_5_reg                                             (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_5_reg))
#define  DVBC_ROM_BIST_OUT_5_inrx_rom_bist_out01_47_40_shift                     (0)
#define  DVBC_ROM_BIST_OUT_5_inrx_rom_bist_out01_47_40_mask                      (0x000000FF)
#define  DVBC_ROM_BIST_OUT_5_inrx_rom_bist_out01_47_40(data)                     (0x000000FF&(data))
#define  DVBC_ROM_BIST_OUT_5_get_inrx_rom_bist_out01_47_40(data)                 (0x000000FF&(data))

#define  DVBC_ROM_BIST_OUT_6                                                     0x180E8A7C
#define  DVBC_ROM_BIST_OUT_6_reg_addr                                            "0xB80E8A7C"
#define  DVBC_ROM_BIST_OUT_6_reg                                                 0xB80E8A7C
#define  DVBC_ROM_BIST_OUT_6_inst_addr                                           "0x019C"
#define  set_DVBC_ROM_BIST_OUT_6_reg(data)                                       (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_6_reg)=data)
#define  get_DVBC_ROM_BIST_OUT_6_reg                                             (*((volatile unsigned int*)DVBC_ROM_BIST_OUT_6_reg))
#define  DVBC_ROM_BIST_OUT_6_inrx_rom_bist_out01_51_48_shift                     (0)
#define  DVBC_ROM_BIST_OUT_6_inrx_rom_bist_out01_51_48_mask                      (0x0000000F)
#define  DVBC_ROM_BIST_OUT_6_inrx_rom_bist_out01_51_48(data)                     (0x0000000F&(data))
#define  DVBC_ROM_BIST_OUT_6_get_inrx_rom_bist_out01_51_48(data)                 (0x0000000F&(data))

#define  DVBC_VERSION_OC_OUTER                                                   0x180E8C04
#define  DVBC_VERSION_OC_OUTER_reg_addr                                          "0xB80E8C04"
#define  DVBC_VERSION_OC_OUTER_reg                                               0xB80E8C04
#define  DVBC_VERSION_OC_OUTER_inst_addr                                         "0x019D"
#define  set_DVBC_VERSION_OC_OUTER_reg(data)                                     (*((volatile unsigned int*)DVBC_VERSION_OC_OUTER_reg)=data)
#define  get_DVBC_VERSION_OC_OUTER_reg                                           (*((volatile unsigned int*)DVBC_VERSION_OC_OUTER_reg))
#define  DVBC_VERSION_OC_OUTER_version_oc_outer_shift                            (0)
#define  DVBC_VERSION_OC_OUTER_version_oc_outer_mask                             (0x000000FF)
#define  DVBC_VERSION_OC_OUTER_version_oc_outer(data)                            (0x000000FF&(data))
#define  DVBC_VERSION_OC_OUTER_get_version_oc_outer(data)                        (0x000000FF&(data))

#define  DVBC_VT_LSB_HD                                                          0x180E8C08
#define  DVBC_VT_LSB_HD_reg_addr                                                 "0xB80E8C08"
#define  DVBC_VT_LSB_HD_reg                                                      0xB80E8C08
#define  DVBC_VT_LSB_HD_inst_addr                                                "0x019E"
#define  set_DVBC_VT_LSB_HD_reg(data)                                            (*((volatile unsigned int*)DVBC_VT_LSB_HD_reg)=data)
#define  get_DVBC_VT_LSB_HD_reg                                                  (*((volatile unsigned int*)DVBC_VT_LSB_HD_reg))
#define  DVBC_VT_LSB_HD_viterbi_rd_stb_shift                                     (7)
#define  DVBC_VT_LSB_HD_puncsync_lost_shift                                      (6)
#define  DVBC_VT_LSB_HD_manu_skip_shift                                          (5)
#define  DVBC_VT_LSB_HD_force_vt_en_shift                                        (4)
#define  DVBC_VT_LSB_HD_zero_metrics_shift                                       (3)
#define  DVBC_VT_LSB_HD_soft_reset_ff_shift                                      (2)
#define  DVBC_VT_LSB_HD_punct_sync_mode_shift                                    (1)
#define  DVBC_VT_LSB_HD_vt_lsb_hd_shift                                          (0)
#define  DVBC_VT_LSB_HD_viterbi_rd_stb_mask                                      (0x00000080)
#define  DVBC_VT_LSB_HD_puncsync_lost_mask                                       (0x00000040)
#define  DVBC_VT_LSB_HD_manu_skip_mask                                           (0x00000020)
#define  DVBC_VT_LSB_HD_force_vt_en_mask                                         (0x00000010)
#define  DVBC_VT_LSB_HD_zero_metrics_mask                                        (0x00000008)
#define  DVBC_VT_LSB_HD_soft_reset_ff_mask                                       (0x00000004)
#define  DVBC_VT_LSB_HD_punct_sync_mode_mask                                     (0x00000002)
#define  DVBC_VT_LSB_HD_vt_lsb_hd_mask                                           (0x00000001)
#define  DVBC_VT_LSB_HD_viterbi_rd_stb(data)                                     (0x00000080&((data)<<7))
#define  DVBC_VT_LSB_HD_puncsync_lost(data)                                      (0x00000040&((data)<<6))
#define  DVBC_VT_LSB_HD_manu_skip(data)                                          (0x00000020&((data)<<5))
#define  DVBC_VT_LSB_HD_force_vt_en(data)                                        (0x00000010&((data)<<4))
#define  DVBC_VT_LSB_HD_zero_metrics(data)                                       (0x00000008&((data)<<3))
#define  DVBC_VT_LSB_HD_soft_reset_ff(data)                                      (0x00000004&((data)<<2))
#define  DVBC_VT_LSB_HD_punct_sync_mode(data)                                    (0x00000002&((data)<<1))
#define  DVBC_VT_LSB_HD_vt_lsb_hd(data)                                          (0x00000001&(data))
#define  DVBC_VT_LSB_HD_get_viterbi_rd_stb(data)                                 ((0x00000080&(data))>>7)
#define  DVBC_VT_LSB_HD_get_puncsync_lost(data)                                  ((0x00000040&(data))>>6)
#define  DVBC_VT_LSB_HD_get_manu_skip(data)                                      ((0x00000020&(data))>>5)
#define  DVBC_VT_LSB_HD_get_force_vt_en(data)                                    ((0x00000010&(data))>>4)
#define  DVBC_VT_LSB_HD_get_zero_metrics(data)                                   ((0x00000008&(data))>>3)
#define  DVBC_VT_LSB_HD_get_soft_reset_ff(data)                                  ((0x00000004&(data))>>2)
#define  DVBC_VT_LSB_HD_get_punct_sync_mode(data)                                ((0x00000002&(data))>>1)
#define  DVBC_VT_LSB_HD_get_vt_lsb_hd(data)                                      (0x00000001&(data))

#define  DVBC_TD_ACQ_MODE                                                        0x180E8C0C
#define  DVBC_TD_ACQ_MODE_reg_addr                                               "0xB80E8C0C"
#define  DVBC_TD_ACQ_MODE_reg                                                    0xB80E8C0C
#define  DVBC_TD_ACQ_MODE_inst_addr                                              "0x019F"
#define  set_DVBC_TD_ACQ_MODE_reg(data)                                          (*((volatile unsigned int*)DVBC_TD_ACQ_MODE_reg)=data)
#define  get_DVBC_TD_ACQ_MODE_reg                                                (*((volatile unsigned int*)DVBC_TD_ACQ_MODE_reg))
#define  DVBC_TD_ACQ_MODE_td_trk_mode_shift                                      (4)
#define  DVBC_TD_ACQ_MODE_td_acq_mode_shift                                      (0)
#define  DVBC_TD_ACQ_MODE_td_trk_mode_mask                                       (0x000000F0)
#define  DVBC_TD_ACQ_MODE_td_acq_mode_mask                                       (0x0000000F)
#define  DVBC_TD_ACQ_MODE_td_trk_mode(data)                                      (0x000000F0&((data)<<4))
#define  DVBC_TD_ACQ_MODE_td_acq_mode(data)                                      (0x0000000F&(data))
#define  DVBC_TD_ACQ_MODE_get_td_trk_mode(data)                                  ((0x000000F0&(data))>>4)
#define  DVBC_TD_ACQ_MODE_get_td_acq_mode(data)                                  (0x0000000F&(data))

#define  DVBC_VT_WINDOW_LEN                                                      0x180E8C10
#define  DVBC_VT_WINDOW_LEN_reg_addr                                             "0xB80E8C10"
#define  DVBC_VT_WINDOW_LEN_reg                                                  0xB80E8C10
#define  DVBC_VT_WINDOW_LEN_inst_addr                                            "0x01A0"
#define  set_DVBC_VT_WINDOW_LEN_reg(data)                                        (*((volatile unsigned int*)DVBC_VT_WINDOW_LEN_reg)=data)
#define  get_DVBC_VT_WINDOW_LEN_reg                                              (*((volatile unsigned int*)DVBC_VT_WINDOW_LEN_reg))
#define  DVBC_VT_WINDOW_LEN_vt_window_len_shift                                  (0)
#define  DVBC_VT_WINDOW_LEN_vt_window_len_mask                                   (0x000000FF)
#define  DVBC_VT_WINDOW_LEN_vt_window_len(data)                                  (0x000000FF&(data))
#define  DVBC_VT_WINDOW_LEN_get_vt_window_len(data)                              (0x000000FF&(data))

#define  DVBC_TRK_GAP                                                            0x180E8C14
#define  DVBC_TRK_GAP_reg_addr                                                   "0xB80E8C14"
#define  DVBC_TRK_GAP_reg                                                        0xB80E8C14
#define  DVBC_TRK_GAP_inst_addr                                                  "0x01A1"
#define  set_DVBC_TRK_GAP_reg(data)                                              (*((volatile unsigned int*)DVBC_TRK_GAP_reg)=data)
#define  get_DVBC_TRK_GAP_reg                                                    (*((volatile unsigned int*)DVBC_TRK_GAP_reg))
#define  DVBC_TRK_GAP_trk_gap_shift                                              (0)
#define  DVBC_TRK_GAP_trk_gap_mask                                               (0x000000FF)
#define  DVBC_TRK_GAP_trk_gap(data)                                              (0x000000FF&(data))
#define  DVBC_TRK_GAP_get_trk_gap(data)                                          (0x000000FF&(data))

#define  DVBC_VT_BER_COUNT                                                       0x180E8C18
#define  DVBC_VT_BER_COUNT_reg_addr                                              "0xB80E8C18"
#define  DVBC_VT_BER_COUNT_reg                                                   0xB80E8C18
#define  DVBC_VT_BER_COUNT_inst_addr                                             "0x01A2"
#define  set_DVBC_VT_BER_COUNT_reg(data)                                         (*((volatile unsigned int*)DVBC_VT_BER_COUNT_reg)=data)
#define  get_DVBC_VT_BER_COUNT_reg                                               (*((volatile unsigned int*)DVBC_VT_BER_COUNT_reg))
#define  DVBC_VT_BER_COUNT_vt_ber_count_7_0_shift                                (0)
#define  DVBC_VT_BER_COUNT_vt_ber_count_7_0_mask                                 (0x000000FF)
#define  DVBC_VT_BER_COUNT_vt_ber_count_7_0(data)                                (0x000000FF&(data))
#define  DVBC_VT_BER_COUNT_get_vt_ber_count_7_0(data)                            (0x000000FF&(data))

#define  DVBC_VT_BER_COUNT_1                                                     0x180E8C1C
#define  DVBC_VT_BER_COUNT_1_reg_addr                                            "0xB80E8C1C"
#define  DVBC_VT_BER_COUNT_1_reg                                                 0xB80E8C1C
#define  DVBC_VT_BER_COUNT_1_inst_addr                                           "0x01A3"
#define  set_DVBC_VT_BER_COUNT_1_reg(data)                                       (*((volatile unsigned int*)DVBC_VT_BER_COUNT_1_reg)=data)
#define  get_DVBC_VT_BER_COUNT_1_reg                                             (*((volatile unsigned int*)DVBC_VT_BER_COUNT_1_reg))
#define  DVBC_VT_BER_COUNT_1_vt_ber_count_15_8_shift                             (0)
#define  DVBC_VT_BER_COUNT_1_vt_ber_count_15_8_mask                              (0x000000FF)
#define  DVBC_VT_BER_COUNT_1_vt_ber_count_15_8(data)                             (0x000000FF&(data))
#define  DVBC_VT_BER_COUNT_1_get_vt_ber_count_15_8(data)                         (0x000000FF&(data))

#define  DVBC_INTL_CHG_FLAG                                                      0x180E8C20
#define  DVBC_INTL_CHG_FLAG_reg_addr                                             "0xB80E8C20"
#define  DVBC_INTL_CHG_FLAG_reg                                                  0xB80E8C20
#define  DVBC_INTL_CHG_FLAG_inst_addr                                            "0x01A4"
#define  set_DVBC_INTL_CHG_FLAG_reg(data)                                        (*((volatile unsigned int*)DVBC_INTL_CHG_FLAG_reg)=data)
#define  get_DVBC_INTL_CHG_FLAG_reg                                              (*((volatile unsigned int*)DVBC_INTL_CHG_FLAG_reg))
#define  DVBC_INTL_CHG_FLAG_deintl_mode_shift                                    (4)
#define  DVBC_INTL_CHG_FLAG_derand_dis_shift                                     (3)
#define  DVBC_INTL_CHG_FLAG_puncsync_en_shift                                    (2)
#define  DVBC_INTL_CHG_FLAG_fs_sync_lost_shift                                   (1)
#define  DVBC_INTL_CHG_FLAG_intl_chg_flag_shift                                  (0)
#define  DVBC_INTL_CHG_FLAG_deintl_mode_mask                                     (0x00000030)
#define  DVBC_INTL_CHG_FLAG_derand_dis_mask                                      (0x00000008)
#define  DVBC_INTL_CHG_FLAG_puncsync_en_mask                                     (0x00000004)
#define  DVBC_INTL_CHG_FLAG_fs_sync_lost_mask                                    (0x00000002)
#define  DVBC_INTL_CHG_FLAG_intl_chg_flag_mask                                   (0x00000001)
#define  DVBC_INTL_CHG_FLAG_deintl_mode(data)                                    (0x00000030&((data)<<4))
#define  DVBC_INTL_CHG_FLAG_derand_dis(data)                                     (0x00000008&((data)<<3))
#define  DVBC_INTL_CHG_FLAG_puncsync_en(data)                                    (0x00000004&((data)<<2))
#define  DVBC_INTL_CHG_FLAG_fs_sync_lost(data)                                   (0x00000002&((data)<<1))
#define  DVBC_INTL_CHG_FLAG_intl_chg_flag(data)                                  (0x00000001&(data))
#define  DVBC_INTL_CHG_FLAG_get_deintl_mode(data)                                ((0x00000030&(data))>>4)
#define  DVBC_INTL_CHG_FLAG_get_derand_dis(data)                                 ((0x00000008&(data))>>3)
#define  DVBC_INTL_CHG_FLAG_get_puncsync_en(data)                                ((0x00000004&(data))>>2)
#define  DVBC_INTL_CHG_FLAG_get_fs_sync_lost(data)                               ((0x00000002&(data))>>1)
#define  DVBC_INTL_CHG_FLAG_get_intl_chg_flag(data)                              (0x00000001&(data))

#define  DVBC_FS_MISMATCH_ACQ                                                    0x180E8C24
#define  DVBC_FS_MISMATCH_ACQ_reg_addr                                           "0xB80E8C24"
#define  DVBC_FS_MISMATCH_ACQ_reg                                                0xB80E8C24
#define  DVBC_FS_MISMATCH_ACQ_inst_addr                                          "0x01A5"
#define  set_DVBC_FS_MISMATCH_ACQ_reg(data)                                      (*((volatile unsigned int*)DVBC_FS_MISMATCH_ACQ_reg)=data)
#define  get_DVBC_FS_MISMATCH_ACQ_reg                                            (*((volatile unsigned int*)DVBC_FS_MISMATCH_ACQ_reg))
#define  DVBC_FS_MISMATCH_ACQ_fs_mismatch_trk_shift                              (4)
#define  DVBC_FS_MISMATCH_ACQ_fs_mismatch_acq_shift                              (0)
#define  DVBC_FS_MISMATCH_ACQ_fs_mismatch_trk_mask                               (0x000000F0)
#define  DVBC_FS_MISMATCH_ACQ_fs_mismatch_acq_mask                               (0x0000000F)
#define  DVBC_FS_MISMATCH_ACQ_fs_mismatch_trk(data)                              (0x000000F0&((data)<<4))
#define  DVBC_FS_MISMATCH_ACQ_fs_mismatch_acq(data)                              (0x0000000F&(data))
#define  DVBC_FS_MISMATCH_ACQ_get_fs_mismatch_trk(data)                          ((0x000000F0&(data))>>4)
#define  DVBC_FS_MISMATCH_ACQ_get_fs_mismatch_acq(data)                          (0x0000000F&(data))

#define  DVBC_FS_ACQ_MODE                                                        0x180E8C28
#define  DVBC_FS_ACQ_MODE_reg_addr                                               "0xB80E8C28"
#define  DVBC_FS_ACQ_MODE_reg                                                    0xB80E8C28
#define  DVBC_FS_ACQ_MODE_inst_addr                                              "0x01A6"
#define  set_DVBC_FS_ACQ_MODE_reg(data)                                          (*((volatile unsigned int*)DVBC_FS_ACQ_MODE_reg)=data)
#define  get_DVBC_FS_ACQ_MODE_reg                                                (*((volatile unsigned int*)DVBC_FS_ACQ_MODE_reg))
#define  DVBC_FS_ACQ_MODE_fs_trk_mode_shift                                      (4)
#define  DVBC_FS_ACQ_MODE_fs_acq_mode_shift                                      (0)
#define  DVBC_FS_ACQ_MODE_fs_trk_mode_mask                                       (0x000000F0)
#define  DVBC_FS_ACQ_MODE_fs_acq_mode_mask                                       (0x0000000F)
#define  DVBC_FS_ACQ_MODE_fs_trk_mode(data)                                      (0x000000F0&((data)<<4))
#define  DVBC_FS_ACQ_MODE_fs_acq_mode(data)                                      (0x0000000F&(data))
#define  DVBC_FS_ACQ_MODE_get_fs_trk_mode(data)                                  ((0x000000F0&(data))>>4)
#define  DVBC_FS_ACQ_MODE_get_fs_acq_mode(data)                                  (0x0000000F&(data))

#define  DVBC_INTL_MODE_CHG_CNT                                                  0x180E8C2C
#define  DVBC_INTL_MODE_CHG_CNT_reg_addr                                         "0xB80E8C2C"
#define  DVBC_INTL_MODE_CHG_CNT_reg                                              0xB80E8C2C
#define  DVBC_INTL_MODE_CHG_CNT_inst_addr                                        "0x01A7"
#define  set_DVBC_INTL_MODE_CHG_CNT_reg(data)                                    (*((volatile unsigned int*)DVBC_INTL_MODE_CHG_CNT_reg)=data)
#define  get_DVBC_INTL_MODE_CHG_CNT_reg                                          (*((volatile unsigned int*)DVBC_INTL_MODE_CHG_CNT_reg))
#define  DVBC_INTL_MODE_CHG_CNT_intl_mode_chg_cnt_shift                          (0)
#define  DVBC_INTL_MODE_CHG_CNT_intl_mode_chg_cnt_mask                           (0x0000000F)
#define  DVBC_INTL_MODE_CHG_CNT_intl_mode_chg_cnt(data)                          (0x0000000F&(data))
#define  DVBC_INTL_MODE_CHG_CNT_get_intl_mode_chg_cnt(data)                      (0x0000000F&(data))

#define  DVBC_TRAILER_0                                                          0x180E8C30
#define  DVBC_TRAILER_0_reg_addr                                                 "0xB80E8C30"
#define  DVBC_TRAILER_0_reg                                                      0xB80E8C30
#define  DVBC_TRAILER_0_inst_addr                                                "0x01A8"
#define  set_DVBC_TRAILER_0_reg(data)                                            (*((volatile unsigned int*)DVBC_TRAILER_0_reg)=data)
#define  get_DVBC_TRAILER_0_reg                                                  (*((volatile unsigned int*)DVBC_TRAILER_0_reg))
#define  DVBC_TRAILER_0_trailer_0_shift                                          (0)
#define  DVBC_TRAILER_0_trailer_0_mask                                           (0x000000FF)
#define  DVBC_TRAILER_0_trailer_0(data)                                          (0x000000FF&(data))
#define  DVBC_TRAILER_0_get_trailer_0(data)                                      (0x000000FF&(data))

#define  DVBC_TRAILER_1                                                          0x180E8C34
#define  DVBC_TRAILER_1_reg_addr                                                 "0xB80E8C34"
#define  DVBC_TRAILER_1_reg                                                      0xB80E8C34
#define  DVBC_TRAILER_1_inst_addr                                                "0x01A9"
#define  set_DVBC_TRAILER_1_reg(data)                                            (*((volatile unsigned int*)DVBC_TRAILER_1_reg)=data)
#define  get_DVBC_TRAILER_1_reg                                                  (*((volatile unsigned int*)DVBC_TRAILER_1_reg))
#define  DVBC_TRAILER_1_trailer_1_shift                                          (0)
#define  DVBC_TRAILER_1_trailer_1_mask                                           (0x000000FF)
#define  DVBC_TRAILER_1_trailer_1(data)                                          (0x000000FF&(data))
#define  DVBC_TRAILER_1_get_trailer_1(data)                                      (0x000000FF&(data))

#define  DVBC_TRAILER_2                                                          0x180E8C38
#define  DVBC_TRAILER_2_reg_addr                                                 "0xB80E8C38"
#define  DVBC_TRAILER_2_reg                                                      0xB80E8C38
#define  DVBC_TRAILER_2_inst_addr                                                "0x01AA"
#define  set_DVBC_TRAILER_2_reg(data)                                            (*((volatile unsigned int*)DVBC_TRAILER_2_reg)=data)
#define  get_DVBC_TRAILER_2_reg                                                  (*((volatile unsigned int*)DVBC_TRAILER_2_reg))
#define  DVBC_TRAILER_2_trailer_2_shift                                          (0)
#define  DVBC_TRAILER_2_trailer_2_mask                                           (0x000000FF)
#define  DVBC_TRAILER_2_trailer_2(data)                                          (0x000000FF&(data))
#define  DVBC_TRAILER_2_get_trailer_2(data)                                      (0x000000FF&(data))

#define  DVBC_TRAILER_3                                                          0x180E8C3C
#define  DVBC_TRAILER_3_reg_addr                                                 "0xB80E8C3C"
#define  DVBC_TRAILER_3_reg                                                      0xB80E8C3C
#define  DVBC_TRAILER_3_inst_addr                                                "0x01AB"
#define  set_DVBC_TRAILER_3_reg(data)                                            (*((volatile unsigned int*)DVBC_TRAILER_3_reg)=data)
#define  get_DVBC_TRAILER_3_reg                                                  (*((volatile unsigned int*)DVBC_TRAILER_3_reg))
#define  DVBC_TRAILER_3_trailer_3_shift                                          (0)
#define  DVBC_TRAILER_3_trailer_3_mask                                           (0x000000FF)
#define  DVBC_TRAILER_3_trailer_3(data)                                          (0x000000FF&(data))
#define  DVBC_TRAILER_3_get_trailer_3(data)                                      (0x000000FF&(data))

#define  DVBC_INVAL_SYNC_CNT                                                     0x180E8C40
#define  DVBC_INVAL_SYNC_CNT_reg_addr                                            "0xB80E8C40"
#define  DVBC_INVAL_SYNC_CNT_reg                                                 0xB80E8C40
#define  DVBC_INVAL_SYNC_CNT_inst_addr                                           "0x01AC"
#define  set_DVBC_INVAL_SYNC_CNT_reg(data)                                       (*((volatile unsigned int*)DVBC_INVAL_SYNC_CNT_reg)=data)
#define  get_DVBC_INVAL_SYNC_CNT_reg                                             (*((volatile unsigned int*)DVBC_INVAL_SYNC_CNT_reg))
#define  DVBC_INVAL_SYNC_CNT_fs_acq_fail_shift                                   (4)
#define  DVBC_INVAL_SYNC_CNT_inval_sync_cnt_shift                                (0)
#define  DVBC_INVAL_SYNC_CNT_fs_acq_fail_mask                                    (0x000000F0)
#define  DVBC_INVAL_SYNC_CNT_inval_sync_cnt_mask                                 (0x0000000F)
#define  DVBC_INVAL_SYNC_CNT_fs_acq_fail(data)                                   (0x000000F0&((data)<<4))
#define  DVBC_INVAL_SYNC_CNT_inval_sync_cnt(data)                                (0x0000000F&(data))
#define  DVBC_INVAL_SYNC_CNT_get_fs_acq_fail(data)                               ((0x000000F0&(data))>>4)
#define  DVBC_INVAL_SYNC_CNT_get_inval_sync_cnt(data)                            (0x0000000F&(data))

#define  DVBC_DEINTL_AUTO_CFG                                                    0x180E8C44
#define  DVBC_DEINTL_AUTO_CFG_reg_addr                                           "0xB80E8C44"
#define  DVBC_DEINTL_AUTO_CFG_reg                                                0xB80E8C44
#define  DVBC_DEINTL_AUTO_CFG_inst_addr                                          "0x01AD"
#define  set_DVBC_DEINTL_AUTO_CFG_reg(data)                                      (*((volatile unsigned int*)DVBC_DEINTL_AUTO_CFG_reg)=data)
#define  get_DVBC_DEINTL_AUTO_CFG_reg                                            (*((volatile unsigned int*)DVBC_DEINTL_AUTO_CFG_reg))
#define  DVBC_DEINTL_AUTO_CFG_detintl_man_cfg_shift                              (4)
#define  DVBC_DEINTL_AUTO_CFG_deintl_auto_cfg_shift                              (0)
#define  DVBC_DEINTL_AUTO_CFG_detintl_man_cfg_mask                               (0x000000F0)
#define  DVBC_DEINTL_AUTO_CFG_deintl_auto_cfg_mask                               (0x0000000F)
#define  DVBC_DEINTL_AUTO_CFG_detintl_man_cfg(data)                              (0x000000F0&((data)<<4))
#define  DVBC_DEINTL_AUTO_CFG_deintl_auto_cfg(data)                              (0x0000000F&(data))
#define  DVBC_DEINTL_AUTO_CFG_get_detintl_man_cfg(data)                          ((0x000000F0&(data))>>4)
#define  DVBC_DEINTL_AUTO_CFG_get_deintl_auto_cfg(data)                          (0x0000000F&(data))

#define  DVBC_OC_RSD_DISABLE                                                     0x180E8C48
#define  DVBC_OC_RSD_DISABLE_reg_addr                                            "0xB80E8C48"
#define  DVBC_OC_RSD_DISABLE_reg                                                 0xB80E8C48
#define  DVBC_OC_RSD_DISABLE_inst_addr                                           "0x01AE"
#define  set_DVBC_OC_RSD_DISABLE_reg(data)                                       (*((volatile unsigned int*)DVBC_OC_RSD_DISABLE_reg)=data)
#define  get_DVBC_OC_RSD_DISABLE_reg                                             (*((volatile unsigned int*)DVBC_OC_RSD_DISABLE_reg))
#define  DVBC_OC_RSD_DISABLE_ber_rd_strobe_shift                                 (7)
#define  DVBC_OC_RSD_DISABLE_oc_errmode_shift                                    (2)
#define  DVBC_OC_RSD_DISABLE_oc_nocorr_shift                                     (1)
#define  DVBC_OC_RSD_DISABLE_oc_rsd_disable_shift                                (0)
#define  DVBC_OC_RSD_DISABLE_ber_rd_strobe_mask                                  (0x00000080)
#define  DVBC_OC_RSD_DISABLE_oc_errmode_mask                                     (0x00000004)
#define  DVBC_OC_RSD_DISABLE_oc_nocorr_mask                                      (0x00000002)
#define  DVBC_OC_RSD_DISABLE_oc_rsd_disable_mask                                 (0x00000001)
#define  DVBC_OC_RSD_DISABLE_ber_rd_strobe(data)                                 (0x00000080&((data)<<7))
#define  DVBC_OC_RSD_DISABLE_oc_errmode(data)                                    (0x00000004&((data)<<2))
#define  DVBC_OC_RSD_DISABLE_oc_nocorr(data)                                     (0x00000002&((data)<<1))
#define  DVBC_OC_RSD_DISABLE_oc_rsd_disable(data)                                (0x00000001&(data))
#define  DVBC_OC_RSD_DISABLE_get_ber_rd_strobe(data)                             ((0x00000080&(data))>>7)
#define  DVBC_OC_RSD_DISABLE_get_oc_errmode(data)                                ((0x00000004&(data))>>2)
#define  DVBC_OC_RSD_DISABLE_get_oc_nocorr(data)                                 ((0x00000002&(data))>>1)
#define  DVBC_OC_RSD_DISABLE_get_oc_rsd_disable(data)                            (0x00000001&(data))

#define  DVBC_OC_BER_EN                                                          0x180E8C4C
#define  DVBC_OC_BER_EN_reg_addr                                                 "0xB80E8C4C"
#define  DVBC_OC_BER_EN_reg                                                      0xB80E8C4C
#define  DVBC_OC_BER_EN_inst_addr                                                "0x01AF"
#define  set_DVBC_OC_BER_EN_reg(data)                                            (*((volatile unsigned int*)DVBC_OC_BER_EN_reg)=data)
#define  get_DVBC_OC_BER_EN_reg                                                  (*((volatile unsigned int*)DVBC_OC_BER_EN_reg))
#define  DVBC_OC_BER_EN_ber_en_stb_oc_shift                                      (7)
#define  DVBC_OC_BER_EN_ber_en_stat_shift                                        (6)
#define  DVBC_OC_BER_EN_oc_volume_shift                                          (3)
#define  DVBC_OC_BER_EN_oc_dis_auto_mode_shift                                   (2)
#define  DVBC_OC_BER_EN_rs_bert_hold_shift                                       (1)
#define  DVBC_OC_BER_EN_oc_ber_en_shift                                          (0)
#define  DVBC_OC_BER_EN_ber_en_stb_oc_mask                                       (0x00000080)
#define  DVBC_OC_BER_EN_ber_en_stat_mask                                         (0x00000040)
#define  DVBC_OC_BER_EN_oc_volume_mask                                           (0x00000038)
#define  DVBC_OC_BER_EN_oc_dis_auto_mode_mask                                    (0x00000004)
#define  DVBC_OC_BER_EN_rs_bert_hold_mask                                        (0x00000002)
#define  DVBC_OC_BER_EN_oc_ber_en_mask                                           (0x00000001)
#define  DVBC_OC_BER_EN_ber_en_stb_oc(data)                                      (0x00000080&((data)<<7))
#define  DVBC_OC_BER_EN_ber_en_stat(data)                                        (0x00000040&((data)<<6))
#define  DVBC_OC_BER_EN_oc_volume(data)                                          (0x00000038&((data)<<3))
#define  DVBC_OC_BER_EN_oc_dis_auto_mode(data)                                   (0x00000004&((data)<<2))
#define  DVBC_OC_BER_EN_rs_bert_hold(data)                                       (0x00000002&((data)<<1))
#define  DVBC_OC_BER_EN_oc_ber_en(data)                                          (0x00000001&(data))
#define  DVBC_OC_BER_EN_get_ber_en_stb_oc(data)                                  ((0x00000080&(data))>>7)
#define  DVBC_OC_BER_EN_get_ber_en_stat(data)                                    ((0x00000040&(data))>>6)
#define  DVBC_OC_BER_EN_get_oc_volume(data)                                      ((0x00000038&(data))>>3)
#define  DVBC_OC_BER_EN_get_oc_dis_auto_mode(data)                               ((0x00000004&(data))>>2)
#define  DVBC_OC_BER_EN_get_rs_bert_hold(data)                                   ((0x00000002&(data))>>1)
#define  DVBC_OC_BER_EN_get_oc_ber_en(data)                                      (0x00000001&(data))

#define  DVBC_RS_BER_COUNT_0                                                     0x180E8C50
#define  DVBC_RS_BER_COUNT_0_reg_addr                                            "0xB80E8C50"
#define  DVBC_RS_BER_COUNT_0_reg                                                 0xB80E8C50
#define  DVBC_RS_BER_COUNT_0_inst_addr                                           "0x01B0"
#define  set_DVBC_RS_BER_COUNT_0_reg(data)                                       (*((volatile unsigned int*)DVBC_RS_BER_COUNT_0_reg)=data)
#define  get_DVBC_RS_BER_COUNT_0_reg                                             (*((volatile unsigned int*)DVBC_RS_BER_COUNT_0_reg))
#define  DVBC_RS_BER_COUNT_0_rs_ber_count_0_shift                                (0)
#define  DVBC_RS_BER_COUNT_0_rs_ber_count_0_mask                                 (0x000000FF)
#define  DVBC_RS_BER_COUNT_0_rs_ber_count_0(data)                                (0x000000FF&(data))
#define  DVBC_RS_BER_COUNT_0_get_rs_ber_count_0(data)                            (0x000000FF&(data))

#define  DVBC_RS_BER_COUNT_1                                                     0x180E8C54
#define  DVBC_RS_BER_COUNT_1_reg_addr                                            "0xB80E8C54"
#define  DVBC_RS_BER_COUNT_1_reg                                                 0xB80E8C54
#define  DVBC_RS_BER_COUNT_1_inst_addr                                           "0x01B1"
#define  set_DVBC_RS_BER_COUNT_1_reg(data)                                       (*((volatile unsigned int*)DVBC_RS_BER_COUNT_1_reg)=data)
#define  get_DVBC_RS_BER_COUNT_1_reg                                             (*((volatile unsigned int*)DVBC_RS_BER_COUNT_1_reg))
#define  DVBC_RS_BER_COUNT_1_rs_ber_count_1_shift                                (0)
#define  DVBC_RS_BER_COUNT_1_rs_ber_count_1_mask                                 (0x000000FF)
#define  DVBC_RS_BER_COUNT_1_rs_ber_count_1(data)                                (0x000000FF&(data))
#define  DVBC_RS_BER_COUNT_1_get_rs_ber_count_1(data)                            (0x000000FF&(data))

#define  DVBC_RS_BER_COUNT_2                                                     0x180E8C58
#define  DVBC_RS_BER_COUNT_2_reg_addr                                            "0xB80E8C58"
#define  DVBC_RS_BER_COUNT_2_reg                                                 0xB80E8C58
#define  DVBC_RS_BER_COUNT_2_inst_addr                                           "0x01B2"
#define  set_DVBC_RS_BER_COUNT_2_reg(data)                                       (*((volatile unsigned int*)DVBC_RS_BER_COUNT_2_reg)=data)
#define  get_DVBC_RS_BER_COUNT_2_reg                                             (*((volatile unsigned int*)DVBC_RS_BER_COUNT_2_reg))
#define  DVBC_RS_BER_COUNT_2_rs_block_count_2_shift                              (5)
#define  DVBC_RS_BER_COUNT_2_rs_ber_count_2_shift                                (0)
#define  DVBC_RS_BER_COUNT_2_rs_block_count_2_mask                               (0x000000E0)
#define  DVBC_RS_BER_COUNT_2_rs_ber_count_2_mask                                 (0x0000001F)
#define  DVBC_RS_BER_COUNT_2_rs_block_count_2(data)                              (0x000000E0&((data)<<5))
#define  DVBC_RS_BER_COUNT_2_rs_ber_count_2(data)                                (0x0000001F&(data))
#define  DVBC_RS_BER_COUNT_2_get_rs_block_count_2(data)                          ((0x000000E0&(data))>>5)
#define  DVBC_RS_BER_COUNT_2_get_rs_ber_count_2(data)                            (0x0000001F&(data))

#define  DVBC_RS_BLOCK_COUNT_0                                                   0x180E8C5C
#define  DVBC_RS_BLOCK_COUNT_0_reg_addr                                          "0xB80E8C5C"
#define  DVBC_RS_BLOCK_COUNT_0_reg                                               0xB80E8C5C
#define  DVBC_RS_BLOCK_COUNT_0_inst_addr                                         "0x01B3"
#define  set_DVBC_RS_BLOCK_COUNT_0_reg(data)                                     (*((volatile unsigned int*)DVBC_RS_BLOCK_COUNT_0_reg)=data)
#define  get_DVBC_RS_BLOCK_COUNT_0_reg                                           (*((volatile unsigned int*)DVBC_RS_BLOCK_COUNT_0_reg))
#define  DVBC_RS_BLOCK_COUNT_0_rs_block_count_0_shift                            (0)
#define  DVBC_RS_BLOCK_COUNT_0_rs_block_count_0_mask                             (0x000000FF)
#define  DVBC_RS_BLOCK_COUNT_0_rs_block_count_0(data)                            (0x000000FF&(data))
#define  DVBC_RS_BLOCK_COUNT_0_get_rs_block_count_0(data)                        (0x000000FF&(data))

#define  DVBC_RS_BLOCK_COUNT_1                                                   0x180E8C60
#define  DVBC_RS_BLOCK_COUNT_1_reg_addr                                          "0xB80E8C60"
#define  DVBC_RS_BLOCK_COUNT_1_reg                                               0xB80E8C60
#define  DVBC_RS_BLOCK_COUNT_1_inst_addr                                         "0x01B4"
#define  set_DVBC_RS_BLOCK_COUNT_1_reg(data)                                     (*((volatile unsigned int*)DVBC_RS_BLOCK_COUNT_1_reg)=data)
#define  get_DVBC_RS_BLOCK_COUNT_1_reg                                           (*((volatile unsigned int*)DVBC_RS_BLOCK_COUNT_1_reg))
#define  DVBC_RS_BLOCK_COUNT_1_rs_block_count_1_shift                            (0)
#define  DVBC_RS_BLOCK_COUNT_1_rs_block_count_1_mask                             (0x000000FF)
#define  DVBC_RS_BLOCK_COUNT_1_rs_block_count_1(data)                            (0x000000FF&(data))
#define  DVBC_RS_BLOCK_COUNT_1_get_rs_block_count_1(data)                        (0x000000FF&(data))

#define  DVBC_RS_CORR_COUNT_0                                                    0x180E8C64
#define  DVBC_RS_CORR_COUNT_0_reg_addr                                           "0xB80E8C64"
#define  DVBC_RS_CORR_COUNT_0_reg                                                0xB80E8C64
#define  DVBC_RS_CORR_COUNT_0_inst_addr                                          "0x01B5"
#define  set_DVBC_RS_CORR_COUNT_0_reg(data)                                      (*((volatile unsigned int*)DVBC_RS_CORR_COUNT_0_reg)=data)
#define  get_DVBC_RS_CORR_COUNT_0_reg                                            (*((volatile unsigned int*)DVBC_RS_CORR_COUNT_0_reg))
#define  DVBC_RS_CORR_COUNT_0_rs_corr_count_0_shift                              (0)
#define  DVBC_RS_CORR_COUNT_0_rs_corr_count_0_mask                               (0x000000FF)
#define  DVBC_RS_CORR_COUNT_0_rs_corr_count_0(data)                              (0x000000FF&(data))
#define  DVBC_RS_CORR_COUNT_0_get_rs_corr_count_0(data)                          (0x000000FF&(data))

#define  DVBC_RS_CORR_COUNT_1                                                    0x180E8C68
#define  DVBC_RS_CORR_COUNT_1_reg_addr                                           "0xB80E8C68"
#define  DVBC_RS_CORR_COUNT_1_reg                                                0xB80E8C68
#define  DVBC_RS_CORR_COUNT_1_inst_addr                                          "0x01B6"
#define  set_DVBC_RS_CORR_COUNT_1_reg(data)                                      (*((volatile unsigned int*)DVBC_RS_CORR_COUNT_1_reg)=data)
#define  get_DVBC_RS_CORR_COUNT_1_reg                                            (*((volatile unsigned int*)DVBC_RS_CORR_COUNT_1_reg))
#define  DVBC_RS_CORR_COUNT_1_rs_corr_count_1_shift                              (0)
#define  DVBC_RS_CORR_COUNT_1_rs_corr_count_1_mask                               (0x000000FF)
#define  DVBC_RS_CORR_COUNT_1_rs_corr_count_1(data)                              (0x000000FF&(data))
#define  DVBC_RS_CORR_COUNT_1_get_rs_corr_count_1(data)                          (0x000000FF&(data))

#define  DVBC_RS_UNCORR_COUNT_0                                                  0x180E8C6C
#define  DVBC_RS_UNCORR_COUNT_0_reg_addr                                         "0xB80E8C6C"
#define  DVBC_RS_UNCORR_COUNT_0_reg                                              0xB80E8C6C
#define  DVBC_RS_UNCORR_COUNT_0_inst_addr                                        "0x01B7"
#define  set_DVBC_RS_UNCORR_COUNT_0_reg(data)                                    (*((volatile unsigned int*)DVBC_RS_UNCORR_COUNT_0_reg)=data)
#define  get_DVBC_RS_UNCORR_COUNT_0_reg                                          (*((volatile unsigned int*)DVBC_RS_UNCORR_COUNT_0_reg))
#define  DVBC_RS_UNCORR_COUNT_0_rs_uncorr_count_0_shift                          (0)
#define  DVBC_RS_UNCORR_COUNT_0_rs_uncorr_count_0_mask                           (0x000000FF)
#define  DVBC_RS_UNCORR_COUNT_0_rs_uncorr_count_0(data)                          (0x000000FF&(data))
#define  DVBC_RS_UNCORR_COUNT_0_get_rs_uncorr_count_0(data)                      (0x000000FF&(data))

#define  DVBC_RS_UNCORR_COUNT_1                                                  0x180E8C70
#define  DVBC_RS_UNCORR_COUNT_1_reg_addr                                         "0xB80E8C70"
#define  DVBC_RS_UNCORR_COUNT_1_reg                                              0xB80E8C70
#define  DVBC_RS_UNCORR_COUNT_1_inst_addr                                        "0x01B8"
#define  set_DVBC_RS_UNCORR_COUNT_1_reg(data)                                    (*((volatile unsigned int*)DVBC_RS_UNCORR_COUNT_1_reg)=data)
#define  get_DVBC_RS_UNCORR_COUNT_1_reg                                          (*((volatile unsigned int*)DVBC_RS_UNCORR_COUNT_1_reg))
#define  DVBC_RS_UNCORR_COUNT_1_rs_uncorr_count_1_shift                          (0)
#define  DVBC_RS_UNCORR_COUNT_1_rs_uncorr_count_1_mask                           (0x000000FF)
#define  DVBC_RS_UNCORR_COUNT_1_rs_uncorr_count_1(data)                          (0x000000FF&(data))
#define  DVBC_RS_UNCORR_COUNT_1_get_rs_uncorr_count_1(data)                      (0x000000FF&(data))

#define  DVBC_OC_CDIV_PH0                                                        0x180E8C74
#define  DVBC_OC_CDIV_PH0_reg_addr                                               "0xB80E8C74"
#define  DVBC_OC_CDIV_PH0_reg                                                    0xB80E8C74
#define  DVBC_OC_CDIV_PH0_inst_addr                                              "0x01B9"
#define  set_DVBC_OC_CDIV_PH0_reg(data)                                          (*((volatile unsigned int*)DVBC_OC_CDIV_PH0_reg)=data)
#define  get_DVBC_OC_CDIV_PH0_reg                                                (*((volatile unsigned int*)DVBC_OC_CDIV_PH0_reg))
#define  DVBC_OC_CDIV_PH0_oc_cdiv_ph1_shift                                      (4)
#define  DVBC_OC_CDIV_PH0_oc_cdiv_ph0_shift                                      (0)
#define  DVBC_OC_CDIV_PH0_oc_cdiv_ph1_mask                                       (0x000000F0)
#define  DVBC_OC_CDIV_PH0_oc_cdiv_ph0_mask                                       (0x0000000F)
#define  DVBC_OC_CDIV_PH0_oc_cdiv_ph1(data)                                      (0x000000F0&((data)<<4))
#define  DVBC_OC_CDIV_PH0_oc_cdiv_ph0(data)                                      (0x0000000F&(data))
#define  DVBC_OC_CDIV_PH0_get_oc_cdiv_ph1(data)                                  ((0x000000F0&(data))>>4)
#define  DVBC_OC_CDIV_PH0_get_oc_cdiv_ph0(data)                                  (0x0000000F&(data))

#define  DVBC_OC_CKOUT_PWR                                                       0x180E8C78
#define  DVBC_OC_CKOUT_PWR_reg_addr                                              "0xB80E8C78"
#define  DVBC_OC_CKOUT_PWR_reg                                                   0xB80E8C78
#define  DVBC_OC_CKOUT_PWR_inst_addr                                             "0x01BA"
#define  set_DVBC_OC_CKOUT_PWR_reg(data)                                         (*((volatile unsigned int*)DVBC_OC_CKOUT_PWR_reg)=data)
#define  get_DVBC_OC_CKOUT_PWR_reg                                               (*((volatile unsigned int*)DVBC_OC_CKOUT_PWR_reg))
#define  DVBC_OC_CKOUT_PWR_oc_ckout_pwr_shift                                    (2)
#define  DVBC_OC_CKOUT_PWR_oc_ckoutpar_shift                                     (1)
#define  DVBC_OC_CKOUT_PWR_oc_serial_shift                                       (0)
#define  DVBC_OC_CKOUT_PWR_oc_ckout_pwr_mask                                     (0x00000004)
#define  DVBC_OC_CKOUT_PWR_oc_ckoutpar_mask                                      (0x00000002)
#define  DVBC_OC_CKOUT_PWR_oc_serial_mask                                        (0x00000001)
#define  DVBC_OC_CKOUT_PWR_oc_ckout_pwr(data)                                    (0x00000004&((data)<<2))
#define  DVBC_OC_CKOUT_PWR_oc_ckoutpar(data)                                     (0x00000002&((data)<<1))
#define  DVBC_OC_CKOUT_PWR_oc_serial(data)                                       (0x00000001&(data))
#define  DVBC_OC_CKOUT_PWR_get_oc_ckout_pwr(data)                                ((0x00000004&(data))>>2)
#define  DVBC_OC_CKOUT_PWR_get_oc_ckoutpar(data)                                 ((0x00000002&(data))>>1)
#define  DVBC_OC_CKOUT_PWR_get_oc_serial(data)                                   (0x00000001&(data))

#define  DVBC_OC_MPEG_SYNC_MODE                                                  0x180E8C7C
#define  DVBC_OC_MPEG_SYNC_MODE_reg_addr                                         "0xB80E8C7C"
#define  DVBC_OC_MPEG_SYNC_MODE_reg                                              0xB80E8C7C
#define  DVBC_OC_MPEG_SYNC_MODE_inst_addr                                        "0x01BB"
#define  set_DVBC_OC_MPEG_SYNC_MODE_reg(data)                                    (*((volatile unsigned int*)DVBC_OC_MPEG_SYNC_MODE_reg)=data)
#define  get_DVBC_OC_MPEG_SYNC_MODE_reg                                          (*((volatile unsigned int*)DVBC_OC_MPEG_SYNC_MODE_reg))
#define  DVBC_OC_MPEG_SYNC_MODE_oc_sync_byte_shift                               (7)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_mpeg_rs_en_shift                              (6)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_set_mpeg_err_shift                            (4)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_tei_rs_err_en_shift                           (3)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_tei_sd_err_en_shift                           (2)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_repla_sd_en_shift                             (1)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_mpeg_sync_mode_shift                          (0)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_sync_byte_mask                                (0x00000080)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_mpeg_rs_en_mask                               (0x00000040)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_set_mpeg_err_mask                             (0x00000030)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_tei_rs_err_en_mask                            (0x00000008)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_tei_sd_err_en_mask                            (0x00000004)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_repla_sd_en_mask                              (0x00000002)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_mpeg_sync_mode_mask                           (0x00000001)
#define  DVBC_OC_MPEG_SYNC_MODE_oc_sync_byte(data)                               (0x00000080&((data)<<7))
#define  DVBC_OC_MPEG_SYNC_MODE_oc_mpeg_rs_en(data)                              (0x00000040&((data)<<6))
#define  DVBC_OC_MPEG_SYNC_MODE_oc_set_mpeg_err(data)                            (0x00000030&((data)<<4))
#define  DVBC_OC_MPEG_SYNC_MODE_oc_tei_rs_err_en(data)                           (0x00000008&((data)<<3))
#define  DVBC_OC_MPEG_SYNC_MODE_oc_tei_sd_err_en(data)                           (0x00000004&((data)<<2))
#define  DVBC_OC_MPEG_SYNC_MODE_oc_repla_sd_en(data)                             (0x00000002&((data)<<1))
#define  DVBC_OC_MPEG_SYNC_MODE_oc_mpeg_sync_mode(data)                          (0x00000001&(data))
#define  DVBC_OC_MPEG_SYNC_MODE_get_oc_sync_byte(data)                           ((0x00000080&(data))>>7)
#define  DVBC_OC_MPEG_SYNC_MODE_get_oc_mpeg_rs_en(data)                          ((0x00000040&(data))>>6)
#define  DVBC_OC_MPEG_SYNC_MODE_get_oc_set_mpeg_err(data)                        ((0x00000030&(data))>>4)
#define  DVBC_OC_MPEG_SYNC_MODE_get_oc_tei_rs_err_en(data)                       ((0x00000008&(data))>>3)
#define  DVBC_OC_MPEG_SYNC_MODE_get_oc_tei_sd_err_en(data)                       ((0x00000004&(data))>>2)
#define  DVBC_OC_MPEG_SYNC_MODE_get_oc_repla_sd_en(data)                         ((0x00000002&(data))>>1)
#define  DVBC_OC_MPEG_SYNC_MODE_get_oc_mpeg_sync_mode(data)                      (0x00000001&(data))

#define  DVBC_OC_MPEG_MISMATCH                                                   0x180E8C80
#define  DVBC_OC_MPEG_MISMATCH_reg_addr                                          "0xB80E8C80"
#define  DVBC_OC_MPEG_MISMATCH_reg                                               0xB80E8C80
#define  DVBC_OC_MPEG_MISMATCH_inst_addr                                         "0x01BC"
#define  set_DVBC_OC_MPEG_MISMATCH_reg(data)                                     (*((volatile unsigned int*)DVBC_OC_MPEG_MISMATCH_reg)=data)
#define  get_DVBC_OC_MPEG_MISMATCH_reg                                           (*((volatile unsigned int*)DVBC_OC_MPEG_MISMATCH_reg))
#define  DVBC_OC_MPEG_MISMATCH_oc_mpeg_mismatch_shift                            (6)
#define  DVBC_OC_MPEG_MISMATCH_oc_mpeg_acq_mode_shift                            (4)
#define  DVBC_OC_MPEG_MISMATCH_oc_mpeg_trk_mode_shift                            (0)
#define  DVBC_OC_MPEG_MISMATCH_oc_mpeg_mismatch_mask                             (0x000000C0)
#define  DVBC_OC_MPEG_MISMATCH_oc_mpeg_acq_mode_mask                             (0x00000030)
#define  DVBC_OC_MPEG_MISMATCH_oc_mpeg_trk_mode_mask                             (0x0000000F)
#define  DVBC_OC_MPEG_MISMATCH_oc_mpeg_mismatch(data)                            (0x000000C0&((data)<<6))
#define  DVBC_OC_MPEG_MISMATCH_oc_mpeg_acq_mode(data)                            (0x00000030&((data)<<4))
#define  DVBC_OC_MPEG_MISMATCH_oc_mpeg_trk_mode(data)                            (0x0000000F&(data))
#define  DVBC_OC_MPEG_MISMATCH_get_oc_mpeg_mismatch(data)                        ((0x000000C0&(data))>>6)
#define  DVBC_OC_MPEG_MISMATCH_get_oc_mpeg_acq_mode(data)                        ((0x00000030&(data))>>4)
#define  DVBC_OC_MPEG_MISMATCH_get_oc_mpeg_trk_mode(data)                        (0x0000000F&(data))

#define  DVBC_OC_MPEG_PER_RD_STROBE                                              0x180E8C84
#define  DVBC_OC_MPEG_PER_RD_STROBE_reg_addr                                     "0xB80E8C84"
#define  DVBC_OC_MPEG_PER_RD_STROBE_reg                                          0xB80E8C84
#define  DVBC_OC_MPEG_PER_RD_STROBE_inst_addr                                    "0x01BD"
#define  set_DVBC_OC_MPEG_PER_RD_STROBE_reg(data)                                (*((volatile unsigned int*)DVBC_OC_MPEG_PER_RD_STROBE_reg)=data)
#define  get_DVBC_OC_MPEG_PER_RD_STROBE_reg                                      (*((volatile unsigned int*)DVBC_OC_MPEG_PER_RD_STROBE_reg))
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_per_rd_strobe_shift                  (6)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_pert_en_shift                        (5)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_pert_hold_shift                      (4)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_dis_auto_mode_shift                  (3)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_test_volume_shift                    (0)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_per_rd_strobe_mask                   (0x00000040)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_pert_en_mask                         (0x00000020)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_pert_hold_mask                       (0x00000010)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_dis_auto_mode_mask                   (0x00000008)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_test_volume_mask                     (0x00000007)
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_per_rd_strobe(data)                  (0x00000040&((data)<<6))
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_pert_en(data)                        (0x00000020&((data)<<5))
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_pert_hold(data)                      (0x00000010&((data)<<4))
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_dis_auto_mode(data)                  (0x00000008&((data)<<3))
#define  DVBC_OC_MPEG_PER_RD_STROBE_oc_mpeg_test_volume(data)                    (0x00000007&(data))
#define  DVBC_OC_MPEG_PER_RD_STROBE_get_oc_mpeg_per_rd_strobe(data)              ((0x00000040&(data))>>6)
#define  DVBC_OC_MPEG_PER_RD_STROBE_get_oc_mpeg_pert_en(data)                    ((0x00000020&(data))>>5)
#define  DVBC_OC_MPEG_PER_RD_STROBE_get_oc_mpeg_pert_hold(data)                  ((0x00000010&(data))>>4)
#define  DVBC_OC_MPEG_PER_RD_STROBE_get_oc_mpeg_dis_auto_mode(data)              ((0x00000008&(data))>>3)
#define  DVBC_OC_MPEG_PER_RD_STROBE_get_oc_mpeg_test_volume(data)                (0x00000007&(data))

#define  DVBC_OC_SYNDM_ERR_COUNT_0                                               0x180E8C88
#define  DVBC_OC_SYNDM_ERR_COUNT_0_reg_addr                                      "0xB80E8C88"
#define  DVBC_OC_SYNDM_ERR_COUNT_0_reg                                           0xB80E8C88
#define  DVBC_OC_SYNDM_ERR_COUNT_0_inst_addr                                     "0x01BE"
#define  set_DVBC_OC_SYNDM_ERR_COUNT_0_reg(data)                                 (*((volatile unsigned int*)DVBC_OC_SYNDM_ERR_COUNT_0_reg)=data)
#define  get_DVBC_OC_SYNDM_ERR_COUNT_0_reg                                       (*((volatile unsigned int*)DVBC_OC_SYNDM_ERR_COUNT_0_reg))
#define  DVBC_OC_SYNDM_ERR_COUNT_0_oc_syndm_err_count_0_shift                    (0)
#define  DVBC_OC_SYNDM_ERR_COUNT_0_oc_syndm_err_count_0_mask                     (0x000000FF)
#define  DVBC_OC_SYNDM_ERR_COUNT_0_oc_syndm_err_count_0(data)                    (0x000000FF&(data))
#define  DVBC_OC_SYNDM_ERR_COUNT_0_get_oc_syndm_err_count_0(data)                (0x000000FF&(data))

#define  DVBC_OC_SYNDM_ERR_COUNT_1                                               0x180E8C8C
#define  DVBC_OC_SYNDM_ERR_COUNT_1_reg_addr                                      "0xB80E8C8C"
#define  DVBC_OC_SYNDM_ERR_COUNT_1_reg                                           0xB80E8C8C
#define  DVBC_OC_SYNDM_ERR_COUNT_1_inst_addr                                     "0x01BF"
#define  set_DVBC_OC_SYNDM_ERR_COUNT_1_reg(data)                                 (*((volatile unsigned int*)DVBC_OC_SYNDM_ERR_COUNT_1_reg)=data)
#define  get_DVBC_OC_SYNDM_ERR_COUNT_1_reg                                       (*((volatile unsigned int*)DVBC_OC_SYNDM_ERR_COUNT_1_reg))
#define  DVBC_OC_SYNDM_ERR_COUNT_1_oc_syndm_err_count_1_shift                    (0)
#define  DVBC_OC_SYNDM_ERR_COUNT_1_oc_syndm_err_count_1_mask                     (0x000000FF)
#define  DVBC_OC_SYNDM_ERR_COUNT_1_oc_syndm_err_count_1(data)                    (0x000000FF&(data))
#define  DVBC_OC_SYNDM_ERR_COUNT_1_get_oc_syndm_err_count_1(data)                (0x000000FF&(data))

#define  DVBC_OC_MPEG_PKT_COUNT_0                                                0x180E8C90
#define  DVBC_OC_MPEG_PKT_COUNT_0_reg_addr                                       "0xB80E8C90"
#define  DVBC_OC_MPEG_PKT_COUNT_0_reg                                            0xB80E8C90
#define  DVBC_OC_MPEG_PKT_COUNT_0_inst_addr                                      "0x01C0"
#define  set_DVBC_OC_MPEG_PKT_COUNT_0_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_MPEG_PKT_COUNT_0_reg)=data)
#define  get_DVBC_OC_MPEG_PKT_COUNT_0_reg                                        (*((volatile unsigned int*)DVBC_OC_MPEG_PKT_COUNT_0_reg))
#define  DVBC_OC_MPEG_PKT_COUNT_0_oc_mpeg_pkt_count_0_shift                      (0)
#define  DVBC_OC_MPEG_PKT_COUNT_0_oc_mpeg_pkt_count_0_mask                       (0x000000FF)
#define  DVBC_OC_MPEG_PKT_COUNT_0_oc_mpeg_pkt_count_0(data)                      (0x000000FF&(data))
#define  DVBC_OC_MPEG_PKT_COUNT_0_get_oc_mpeg_pkt_count_0(data)                  (0x000000FF&(data))

#define  DVBC_OC_MPEG_PKT_COUNT_1                                                0x180E8C94
#define  DVBC_OC_MPEG_PKT_COUNT_1_reg_addr                                       "0xB80E8C94"
#define  DVBC_OC_MPEG_PKT_COUNT_1_reg                                            0xB80E8C94
#define  DVBC_OC_MPEG_PKT_COUNT_1_inst_addr                                      "0x01C1"
#define  set_DVBC_OC_MPEG_PKT_COUNT_1_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_MPEG_PKT_COUNT_1_reg)=data)
#define  get_DVBC_OC_MPEG_PKT_COUNT_1_reg                                        (*((volatile unsigned int*)DVBC_OC_MPEG_PKT_COUNT_1_reg))
#define  DVBC_OC_MPEG_PKT_COUNT_1_oc_mpeg_pkt_count_1_shift                      (0)
#define  DVBC_OC_MPEG_PKT_COUNT_1_oc_mpeg_pkt_count_1_mask                       (0x000000FF)
#define  DVBC_OC_MPEG_PKT_COUNT_1_oc_mpeg_pkt_count_1(data)                      (0x000000FF&(data))
#define  DVBC_OC_MPEG_PKT_COUNT_1_get_oc_mpeg_pkt_count_1(data)                  (0x000000FF&(data))

#define  DVBC_OC_MPEG_PKT_COUNT_2                                                0x180E8C98
#define  DVBC_OC_MPEG_PKT_COUNT_2_reg_addr                                       "0xB80E8C98"
#define  DVBC_OC_MPEG_PKT_COUNT_2_reg                                            0xB80E8C98
#define  DVBC_OC_MPEG_PKT_COUNT_2_inst_addr                                      "0x01C2"
#define  set_DVBC_OC_MPEG_PKT_COUNT_2_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_MPEG_PKT_COUNT_2_reg)=data)
#define  get_DVBC_OC_MPEG_PKT_COUNT_2_reg                                        (*((volatile unsigned int*)DVBC_OC_MPEG_PKT_COUNT_2_reg))
#define  DVBC_OC_MPEG_PKT_COUNT_2_oc_mpeg_pkt_count_2_shift                      (0)
#define  DVBC_OC_MPEG_PKT_COUNT_2_oc_mpeg_pkt_count_2_mask                       (0x000000FF)
#define  DVBC_OC_MPEG_PKT_COUNT_2_oc_mpeg_pkt_count_2(data)                      (0x000000FF&(data))
#define  DVBC_OC_MPEG_PKT_COUNT_2_get_oc_mpeg_pkt_count_2(data)                  (0x000000FF&(data))

#define  DVBC_OC_MPEG_ACQ2_K_MODE                                                0x180E8C9C
#define  DVBC_OC_MPEG_ACQ2_K_MODE_reg_addr                                       "0xB80E8C9C"
#define  DVBC_OC_MPEG_ACQ2_K_MODE_reg                                            0xB80E8C9C
#define  DVBC_OC_MPEG_ACQ2_K_MODE_inst_addr                                      "0x01C3"
#define  set_DVBC_OC_MPEG_ACQ2_K_MODE_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_MPEG_ACQ2_K_MODE_reg)=data)
#define  get_DVBC_OC_MPEG_ACQ2_K_MODE_reg                                        (*((volatile unsigned int*)DVBC_OC_MPEG_ACQ2_K_MODE_reg))
#define  DVBC_OC_MPEG_ACQ2_K_MODE_oc_mpeg_acq2_n_mode_shift                      (4)
#define  DVBC_OC_MPEG_ACQ2_K_MODE_oc_mpeg_acq2_k_mode_shift                      (0)
#define  DVBC_OC_MPEG_ACQ2_K_MODE_oc_mpeg_acq2_n_mode_mask                       (0x000000F0)
#define  DVBC_OC_MPEG_ACQ2_K_MODE_oc_mpeg_acq2_k_mode_mask                       (0x0000000F)
#define  DVBC_OC_MPEG_ACQ2_K_MODE_oc_mpeg_acq2_n_mode(data)                      (0x000000F0&((data)<<4))
#define  DVBC_OC_MPEG_ACQ2_K_MODE_oc_mpeg_acq2_k_mode(data)                      (0x0000000F&(data))
#define  DVBC_OC_MPEG_ACQ2_K_MODE_get_oc_mpeg_acq2_n_mode(data)                  ((0x000000F0&(data))>>4)
#define  DVBC_OC_MPEG_ACQ2_K_MODE_get_oc_mpeg_acq2_k_mode(data)                  (0x0000000F&(data))

#define  DVBC_OC_AUTO_BER_BLK_COUNT                                              0x180E8CA0
#define  DVBC_OC_AUTO_BER_BLK_COUNT_reg_addr                                     "0xB80E8CA0"
#define  DVBC_OC_AUTO_BER_BLK_COUNT_reg                                          0xB80E8CA0
#define  DVBC_OC_AUTO_BER_BLK_COUNT_inst_addr                                    "0x01C4"
#define  set_DVBC_OC_AUTO_BER_BLK_COUNT_reg(data)                                (*((volatile unsigned int*)DVBC_OC_AUTO_BER_BLK_COUNT_reg)=data)
#define  get_DVBC_OC_AUTO_BER_BLK_COUNT_reg                                      (*((volatile unsigned int*)DVBC_OC_AUTO_BER_BLK_COUNT_reg))
#define  DVBC_OC_AUTO_BER_BLK_COUNT_oc_auto_ber_blk_count_shift                  (0)
#define  DVBC_OC_AUTO_BER_BLK_COUNT_oc_auto_ber_blk_count_mask                   (0x000000FF)
#define  DVBC_OC_AUTO_BER_BLK_COUNT_oc_auto_ber_blk_count(data)                  (0x000000FF&(data))
#define  DVBC_OC_AUTO_BER_BLK_COUNT_get_oc_auto_ber_blk_count(data)              (0x000000FF&(data))

#define  DVBC_OC_AUTO_BER_COUNT_0                                                0x180E8CA4
#define  DVBC_OC_AUTO_BER_COUNT_0_reg_addr                                       "0xB80E8CA4"
#define  DVBC_OC_AUTO_BER_COUNT_0_reg                                            0xB80E8CA4
#define  DVBC_OC_AUTO_BER_COUNT_0_inst_addr                                      "0x01C5"
#define  set_DVBC_OC_AUTO_BER_COUNT_0_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_AUTO_BER_COUNT_0_reg)=data)
#define  get_DVBC_OC_AUTO_BER_COUNT_0_reg                                        (*((volatile unsigned int*)DVBC_OC_AUTO_BER_COUNT_0_reg))
#define  DVBC_OC_AUTO_BER_COUNT_0_oc_auto_ber_count_0_shift                      (0)
#define  DVBC_OC_AUTO_BER_COUNT_0_oc_auto_ber_count_0_mask                       (0x000000FF)
#define  DVBC_OC_AUTO_BER_COUNT_0_oc_auto_ber_count_0(data)                      (0x000000FF&(data))
#define  DVBC_OC_AUTO_BER_COUNT_0_get_oc_auto_ber_count_0(data)                  (0x000000FF&(data))

#define  DVBC_OC_AUTO_BER_COUNT_1                                                0x180E8CA8
#define  DVBC_OC_AUTO_BER_COUNT_1_reg_addr                                       "0xB80E8CA8"
#define  DVBC_OC_AUTO_BER_COUNT_1_reg                                            0xB80E8CA8
#define  DVBC_OC_AUTO_BER_COUNT_1_inst_addr                                      "0x01C6"
#define  set_DVBC_OC_AUTO_BER_COUNT_1_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_AUTO_BER_COUNT_1_reg)=data)
#define  get_DVBC_OC_AUTO_BER_COUNT_1_reg                                        (*((volatile unsigned int*)DVBC_OC_AUTO_BER_COUNT_1_reg))
#define  DVBC_OC_AUTO_BER_COUNT_1_oc_auto_ber_count_1_shift                      (0)
#define  DVBC_OC_AUTO_BER_COUNT_1_oc_auto_ber_count_1_mask                       (0x000000FF)
#define  DVBC_OC_AUTO_BER_COUNT_1_oc_auto_ber_count_1(data)                      (0x000000FF&(data))
#define  DVBC_OC_AUTO_BER_COUNT_1_get_oc_auto_ber_count_1(data)                  (0x000000FF&(data))

#define  DVBC_OC_AUTO_BER_COUNT_2                                                0x180E8CAC
#define  DVBC_OC_AUTO_BER_COUNT_2_reg_addr                                       "0xB80E8CAC"
#define  DVBC_OC_AUTO_BER_COUNT_2_reg                                            0xB80E8CAC
#define  DVBC_OC_AUTO_BER_COUNT_2_inst_addr                                      "0x01C7"
#define  set_DVBC_OC_AUTO_BER_COUNT_2_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_AUTO_BER_COUNT_2_reg)=data)
#define  get_DVBC_OC_AUTO_BER_COUNT_2_reg                                        (*((volatile unsigned int*)DVBC_OC_AUTO_BER_COUNT_2_reg))
#define  DVBC_OC_AUTO_BER_COUNT_2_oc_auto_blk_count_2_shift                      (5)
#define  DVBC_OC_AUTO_BER_COUNT_2_oc_auto_ber_count_2_shift                      (0)
#define  DVBC_OC_AUTO_BER_COUNT_2_oc_auto_blk_count_2_mask                       (0x000000E0)
#define  DVBC_OC_AUTO_BER_COUNT_2_oc_auto_ber_count_2_mask                       (0x0000001F)
#define  DVBC_OC_AUTO_BER_COUNT_2_oc_auto_blk_count_2(data)                      (0x000000E0&((data)<<5))
#define  DVBC_OC_AUTO_BER_COUNT_2_oc_auto_ber_count_2(data)                      (0x0000001F&(data))
#define  DVBC_OC_AUTO_BER_COUNT_2_get_oc_auto_blk_count_2(data)                  ((0x000000E0&(data))>>5)
#define  DVBC_OC_AUTO_BER_COUNT_2_get_oc_auto_ber_count_2(data)                  (0x0000001F&(data))

#define  DVBC_OC_AUTO_BLK_COUNT_0                                                0x180E8CB0
#define  DVBC_OC_AUTO_BLK_COUNT_0_reg_addr                                       "0xB80E8CB0"
#define  DVBC_OC_AUTO_BLK_COUNT_0_reg                                            0xB80E8CB0
#define  DVBC_OC_AUTO_BLK_COUNT_0_inst_addr                                      "0x01C8"
#define  set_DVBC_OC_AUTO_BLK_COUNT_0_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_AUTO_BLK_COUNT_0_reg)=data)
#define  get_DVBC_OC_AUTO_BLK_COUNT_0_reg                                        (*((volatile unsigned int*)DVBC_OC_AUTO_BLK_COUNT_0_reg))
#define  DVBC_OC_AUTO_BLK_COUNT_0_oc_auto_blk_count_0_shift                      (0)
#define  DVBC_OC_AUTO_BLK_COUNT_0_oc_auto_blk_count_0_mask                       (0x000000FF)
#define  DVBC_OC_AUTO_BLK_COUNT_0_oc_auto_blk_count_0(data)                      (0x000000FF&(data))
#define  DVBC_OC_AUTO_BLK_COUNT_0_get_oc_auto_blk_count_0(data)                  (0x000000FF&(data))

#define  DVBC_OC_AUTO_BLK_COUNT_1                                                0x180E8CB4
#define  DVBC_OC_AUTO_BLK_COUNT_1_reg_addr                                       "0xB80E8CB4"
#define  DVBC_OC_AUTO_BLK_COUNT_1_reg                                            0xB80E8CB4
#define  DVBC_OC_AUTO_BLK_COUNT_1_inst_addr                                      "0x01C9"
#define  set_DVBC_OC_AUTO_BLK_COUNT_1_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_AUTO_BLK_COUNT_1_reg)=data)
#define  get_DVBC_OC_AUTO_BLK_COUNT_1_reg                                        (*((volatile unsigned int*)DVBC_OC_AUTO_BLK_COUNT_1_reg))
#define  DVBC_OC_AUTO_BLK_COUNT_1_oc_auto_blk_count_1_shift                      (0)
#define  DVBC_OC_AUTO_BLK_COUNT_1_oc_auto_blk_count_1_mask                       (0x000000FF)
#define  DVBC_OC_AUTO_BLK_COUNT_1_oc_auto_blk_count_1(data)                      (0x000000FF&(data))
#define  DVBC_OC_AUTO_BLK_COUNT_1_get_oc_auto_blk_count_1(data)                  (0x000000FF&(data))

#define  DVBC_OC_AUTO_CORR_COUNT_0                                               0x180E8CB8
#define  DVBC_OC_AUTO_CORR_COUNT_0_reg_addr                                      "0xB80E8CB8"
#define  DVBC_OC_AUTO_CORR_COUNT_0_reg                                           0xB80E8CB8
#define  DVBC_OC_AUTO_CORR_COUNT_0_inst_addr                                     "0x01CA"
#define  set_DVBC_OC_AUTO_CORR_COUNT_0_reg(data)                                 (*((volatile unsigned int*)DVBC_OC_AUTO_CORR_COUNT_0_reg)=data)
#define  get_DVBC_OC_AUTO_CORR_COUNT_0_reg                                       (*((volatile unsigned int*)DVBC_OC_AUTO_CORR_COUNT_0_reg))
#define  DVBC_OC_AUTO_CORR_COUNT_0_oc_auto_corr_count_0_shift                    (0)
#define  DVBC_OC_AUTO_CORR_COUNT_0_oc_auto_corr_count_0_mask                     (0x000000FF)
#define  DVBC_OC_AUTO_CORR_COUNT_0_oc_auto_corr_count_0(data)                    (0x000000FF&(data))
#define  DVBC_OC_AUTO_CORR_COUNT_0_get_oc_auto_corr_count_0(data)                (0x000000FF&(data))

#define  DVBC_OC_AUTO_CORR_COUNT_1                                               0x180E8CBC
#define  DVBC_OC_AUTO_CORR_COUNT_1_reg_addr                                      "0xB80E8CBC"
#define  DVBC_OC_AUTO_CORR_COUNT_1_reg                                           0xB80E8CBC
#define  DVBC_OC_AUTO_CORR_COUNT_1_inst_addr                                     "0x01CB"
#define  set_DVBC_OC_AUTO_CORR_COUNT_1_reg(data)                                 (*((volatile unsigned int*)DVBC_OC_AUTO_CORR_COUNT_1_reg)=data)
#define  get_DVBC_OC_AUTO_CORR_COUNT_1_reg                                       (*((volatile unsigned int*)DVBC_OC_AUTO_CORR_COUNT_1_reg))
#define  DVBC_OC_AUTO_CORR_COUNT_1_oc_auto_corr_count_1_shift                    (0)
#define  DVBC_OC_AUTO_CORR_COUNT_1_oc_auto_corr_count_1_mask                     (0x000000FF)
#define  DVBC_OC_AUTO_CORR_COUNT_1_oc_auto_corr_count_1(data)                    (0x000000FF&(data))
#define  DVBC_OC_AUTO_CORR_COUNT_1_get_oc_auto_corr_count_1(data)                (0x000000FF&(data))

#define  DVBC_OC_AUTO_UNCORR_COUNT_0                                             0x180E8CC0
#define  DVBC_OC_AUTO_UNCORR_COUNT_0_reg_addr                                    "0xB80E8CC0"
#define  DVBC_OC_AUTO_UNCORR_COUNT_0_reg                                         0xB80E8CC0
#define  DVBC_OC_AUTO_UNCORR_COUNT_0_inst_addr                                   "0x01CC"
#define  set_DVBC_OC_AUTO_UNCORR_COUNT_0_reg(data)                               (*((volatile unsigned int*)DVBC_OC_AUTO_UNCORR_COUNT_0_reg)=data)
#define  get_DVBC_OC_AUTO_UNCORR_COUNT_0_reg                                     (*((volatile unsigned int*)DVBC_OC_AUTO_UNCORR_COUNT_0_reg))
#define  DVBC_OC_AUTO_UNCORR_COUNT_0_oc_auto_uncorr_count_0_shift                (0)
#define  DVBC_OC_AUTO_UNCORR_COUNT_0_oc_auto_uncorr_count_0_mask                 (0x000000FF)
#define  DVBC_OC_AUTO_UNCORR_COUNT_0_oc_auto_uncorr_count_0(data)                (0x000000FF&(data))
#define  DVBC_OC_AUTO_UNCORR_COUNT_0_get_oc_auto_uncorr_count_0(data)            (0x000000FF&(data))

#define  DVBC_OC_AUTO_UNCORR_COUNT_1                                             0x180E8CC4
#define  DVBC_OC_AUTO_UNCORR_COUNT_1_reg_addr                                    "0xB80E8CC4"
#define  DVBC_OC_AUTO_UNCORR_COUNT_1_reg                                         0xB80E8CC4
#define  DVBC_OC_AUTO_UNCORR_COUNT_1_inst_addr                                   "0x01CD"
#define  set_DVBC_OC_AUTO_UNCORR_COUNT_1_reg(data)                               (*((volatile unsigned int*)DVBC_OC_AUTO_UNCORR_COUNT_1_reg)=data)
#define  get_DVBC_OC_AUTO_UNCORR_COUNT_1_reg                                     (*((volatile unsigned int*)DVBC_OC_AUTO_UNCORR_COUNT_1_reg))
#define  DVBC_OC_AUTO_UNCORR_COUNT_1_oc_auto_uncorr_count_1_shift                (0)
#define  DVBC_OC_AUTO_UNCORR_COUNT_1_oc_auto_uncorr_count_1_mask                 (0x000000FF)
#define  DVBC_OC_AUTO_UNCORR_COUNT_1_oc_auto_uncorr_count_1(data)                (0x000000FF&(data))
#define  DVBC_OC_AUTO_UNCORR_COUNT_1_get_oc_auto_uncorr_count_1(data)            (0x000000FF&(data))

#define  DVBC_OC_BIST_MODE                                                       0x180E8CD0
#define  DVBC_OC_BIST_MODE_reg_addr                                              "0xB80E8CD0"
#define  DVBC_OC_BIST_MODE_reg                                                   0xB80E8CD0
#define  DVBC_OC_BIST_MODE_inst_addr                                             "0x01CE"
#define  set_DVBC_OC_BIST_MODE_reg(data)                                         (*((volatile unsigned int*)DVBC_OC_BIST_MODE_reg)=data)
#define  get_DVBC_OC_BIST_MODE_reg                                               (*((volatile unsigned int*)DVBC_OC_BIST_MODE_reg))
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_bn_shift                        (5)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_debugdma_shift                          (4)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_out_shift                       (3)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_deint_shift                     (2)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_fftbuf_shift                    (1)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_bn_mask                         (0x00000020)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_debugdma_mask                           (0x00000010)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_out_mask                        (0x00000008)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_deint_mask                      (0x00000004)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_fftbuf_mask                     (0x00000002)
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_bn(data)                        (0x00000020&((data)<<5))
#define  DVBC_OC_BIST_MODE_reg_bist_mode_debugdma(data)                          (0x00000010&((data)<<4))
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_out(data)                       (0x00000008&((data)<<3))
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_deint(data)                     (0x00000004&((data)<<2))
#define  DVBC_OC_BIST_MODE_reg_bist_mode_cablerx_fftbuf(data)                    (0x00000002&((data)<<1))
#define  DVBC_OC_BIST_MODE_get_reg_bist_mode_cablerx_bn(data)                    ((0x00000020&(data))>>5)
#define  DVBC_OC_BIST_MODE_get_reg_bist_mode_debugdma(data)                      ((0x00000010&(data))>>4)
#define  DVBC_OC_BIST_MODE_get_reg_bist_mode_cablerx_out(data)                   ((0x00000008&(data))>>3)
#define  DVBC_OC_BIST_MODE_get_reg_bist_mode_cablerx_deint(data)                 ((0x00000004&(data))>>2)
#define  DVBC_OC_BIST_MODE_get_reg_bist_mode_cablerx_fftbuf(data)                ((0x00000002&(data))>>1)

#define  DVBC_OC_DRF_BIST_MODE                                                   0x180E8CD4
#define  DVBC_OC_DRF_BIST_MODE_reg_addr                                          "0xB80E8CD4"
#define  DVBC_OC_DRF_BIST_MODE_reg                                               0xB80E8CD4
#define  DVBC_OC_DRF_BIST_MODE_inst_addr                                         "0x01CF"
#define  set_DVBC_OC_DRF_BIST_MODE_reg(data)                                     (*((volatile unsigned int*)DVBC_OC_DRF_BIST_MODE_reg)=data)
#define  get_DVBC_OC_DRF_BIST_MODE_reg                                           (*((volatile unsigned int*)DVBC_OC_DRF_BIST_MODE_reg))
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_bn_shift                (5)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_debugdma_shift                  (4)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_out_shift               (3)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_deint_shift             (2)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_fftbuf_shift            (1)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_bn_mask                 (0x00000020)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_debugdma_mask                   (0x00000010)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_out_mask                (0x00000008)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_deint_mask              (0x00000004)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_fftbuf_mask             (0x00000002)
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_bn(data)                (0x00000020&((data)<<5))
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_debugdma(data)                  (0x00000010&((data)<<4))
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_out(data)               (0x00000008&((data)<<3))
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_deint(data)             (0x00000004&((data)<<2))
#define  DVBC_OC_DRF_BIST_MODE_reg_drf_bist_mode_cablerx_fftbuf(data)            (0x00000002&((data)<<1))
#define  DVBC_OC_DRF_BIST_MODE_get_reg_drf_bist_mode_cablerx_bn(data)            ((0x00000020&(data))>>5)
#define  DVBC_OC_DRF_BIST_MODE_get_reg_drf_bist_mode_debugdma(data)              ((0x00000010&(data))>>4)
#define  DVBC_OC_DRF_BIST_MODE_get_reg_drf_bist_mode_cablerx_out(data)           ((0x00000008&(data))>>3)
#define  DVBC_OC_DRF_BIST_MODE_get_reg_drf_bist_mode_cablerx_deint(data)         ((0x00000004&(data))>>2)
#define  DVBC_OC_DRF_BIST_MODE_get_reg_drf_bist_mode_cablerx_fftbuf(data)        ((0x00000002&(data))>>1)

#define  DVBC_OC_DRF_RESUME_MODE                                                 0x180E8CD8
#define  DVBC_OC_DRF_RESUME_MODE_reg_addr                                        "0xB80E8CD8"
#define  DVBC_OC_DRF_RESUME_MODE_reg                                             0xB80E8CD8
#define  DVBC_OC_DRF_RESUME_MODE_inst_addr                                       "0x01D0"
#define  set_DVBC_OC_DRF_RESUME_MODE_reg(data)                                   (*((volatile unsigned int*)DVBC_OC_DRF_RESUME_MODE_reg)=data)
#define  get_DVBC_OC_DRF_RESUME_MODE_reg                                         (*((volatile unsigned int*)DVBC_OC_DRF_RESUME_MODE_reg))
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_bn_shift            (5)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_debugdma_shift              (4)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_out_shift           (3)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_deint_shift         (2)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_fftbuf_shift        (1)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_bn_mask             (0x00000020)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_debugdma_mask               (0x00000010)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_out_mask            (0x00000008)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_deint_mask          (0x00000004)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_fftbuf_mask         (0x00000002)
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_bn(data)            (0x00000020&((data)<<5))
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_debugdma(data)              (0x00000010&((data)<<4))
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_out(data)           (0x00000008&((data)<<3))
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_deint(data)         (0x00000004&((data)<<2))
#define  DVBC_OC_DRF_RESUME_MODE_reg_drf_test_resume_cablerx_fftbuf(data)        (0x00000002&((data)<<1))
#define  DVBC_OC_DRF_RESUME_MODE_get_reg_drf_test_resume_cablerx_bn(data)        ((0x00000020&(data))>>5)
#define  DVBC_OC_DRF_RESUME_MODE_get_reg_drf_test_resume_debugdma(data)          ((0x00000010&(data))>>4)
#define  DVBC_OC_DRF_RESUME_MODE_get_reg_drf_test_resume_cablerx_out(data)       ((0x00000008&(data))>>3)
#define  DVBC_OC_DRF_RESUME_MODE_get_reg_drf_test_resume_cablerx_deint(data)     ((0x00000004&(data))>>2)
#define  DVBC_OC_DRF_RESUME_MODE_get_reg_drf_test_resume_cablerx_fftbuf(data)    ((0x00000002&(data))>>1)

#define  DVBC_OC_BIST_DVS                                                        0x180E8CDC
#define  DVBC_OC_BIST_DVS_reg_addr                                               "0xB80E8CDC"
#define  DVBC_OC_BIST_DVS_reg                                                    0xB80E8CDC
#define  DVBC_OC_BIST_DVS_inst_addr                                              "0x01D1"
#define  set_DVBC_OC_BIST_DVS_reg(data)                                          (*((volatile unsigned int*)DVBC_OC_BIST_DVS_reg)=data)
#define  get_DVBC_OC_BIST_DVS_reg                                                (*((volatile unsigned int*)DVBC_OC_BIST_DVS_reg))
#define  DVBC_OC_BIST_DVS_reg_mbist_cablerx_dvs_shift                            (0)
#define  DVBC_OC_BIST_DVS_reg_mbist_cablerx_dvs_mask                             (0x0000000F)
#define  DVBC_OC_BIST_DVS_reg_mbist_cablerx_dvs(data)                            (0x0000000F&(data))
#define  DVBC_OC_BIST_DVS_get_reg_mbist_cablerx_dvs(data)                        (0x0000000F&(data))

#define  DVBC_OC_BIST_DVSE                                                       0x180E8CE0
#define  DVBC_OC_BIST_DVSE_reg_addr                                              "0xB80E8CE0"
#define  DVBC_OC_BIST_DVSE_reg                                                   0xB80E8CE0
#define  DVBC_OC_BIST_DVSE_inst_addr                                             "0x01D2"
#define  set_DVBC_OC_BIST_DVSE_reg(data)                                         (*((volatile unsigned int*)DVBC_OC_BIST_DVSE_reg)=data)
#define  get_DVBC_OC_BIST_DVSE_reg                                               (*((volatile unsigned int*)DVBC_OC_BIST_DVSE_reg))
#define  DVBC_OC_BIST_DVSE_reg_mbist_cablerx_dvse_shift                          (0)
#define  DVBC_OC_BIST_DVSE_reg_mbist_cablerx_dvse_mask                           (0x00000001)
#define  DVBC_OC_BIST_DVSE_reg_mbist_cablerx_dvse(data)                          (0x00000001&(data))
#define  DVBC_OC_BIST_DVSE_get_reg_mbist_cablerx_dvse(data)                      (0x00000001&(data))

#define  DVBC_OC_BIST_LS                                                         0x180E8CE4
#define  DVBC_OC_BIST_LS_reg_addr                                                "0xB80E8CE4"
#define  DVBC_OC_BIST_LS_reg                                                     0xB80E8CE4
#define  DVBC_OC_BIST_LS_inst_addr                                               "0x01D3"
#define  set_DVBC_OC_BIST_LS_reg(data)                                           (*((volatile unsigned int*)DVBC_OC_BIST_LS_reg)=data)
#define  get_DVBC_OC_BIST_LS_reg                                                 (*((volatile unsigned int*)DVBC_OC_BIST_LS_reg))
#define  DVBC_OC_BIST_LS_reg_mbist_cablerx_ls_shift                              (0)
#define  DVBC_OC_BIST_LS_reg_mbist_cablerx_ls_mask                               (0x00000001)
#define  DVBC_OC_BIST_LS_reg_mbist_cablerx_ls(data)                              (0x00000001&(data))
#define  DVBC_OC_BIST_LS_get_reg_mbist_cablerx_ls(data)                          (0x00000001&(data))

#define  DVBC_OC_BIST_DONE                                                       0x180E8CE8
#define  DVBC_OC_BIST_DONE_reg_addr                                              "0xB80E8CE8"
#define  DVBC_OC_BIST_DONE_reg                                                   0xB80E8CE8
#define  DVBC_OC_BIST_DONE_inst_addr                                             "0x01D4"
#define  set_DVBC_OC_BIST_DONE_reg(data)                                         (*((volatile unsigned int*)DVBC_OC_BIST_DONE_reg)=data)
#define  get_DVBC_OC_BIST_DONE_reg                                               (*((volatile unsigned int*)DVBC_OC_BIST_DONE_reg))
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_bn_shift                            (5)
#define  DVBC_OC_BIST_DONE_bist_done_debugdma_shift                              (4)
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_out_shift                           (3)
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_deint_shift                         (2)
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_fftbuf_shift                        (1)
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_bn_mask                             (0x00000020)
#define  DVBC_OC_BIST_DONE_bist_done_debugdma_mask                               (0x00000010)
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_out_mask                            (0x00000008)
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_deint_mask                          (0x00000004)
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_fftbuf_mask                         (0x00000002)
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_bn(data)                            (0x00000020&((data)<<5))
#define  DVBC_OC_BIST_DONE_bist_done_debugdma(data)                              (0x00000010&((data)<<4))
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_out(data)                           (0x00000008&((data)<<3))
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_deint(data)                         (0x00000004&((data)<<2))
#define  DVBC_OC_BIST_DONE_bist_done_cablerx_fftbuf(data)                        (0x00000002&((data)<<1))
#define  DVBC_OC_BIST_DONE_get_bist_done_cablerx_bn(data)                        ((0x00000020&(data))>>5)
#define  DVBC_OC_BIST_DONE_get_bist_done_debugdma(data)                          ((0x00000010&(data))>>4)
#define  DVBC_OC_BIST_DONE_get_bist_done_cablerx_out(data)                       ((0x00000008&(data))>>3)
#define  DVBC_OC_BIST_DONE_get_bist_done_cablerx_deint(data)                     ((0x00000004&(data))>>2)
#define  DVBC_OC_BIST_DONE_get_bist_done_cablerx_fftbuf(data)                    ((0x00000002&(data))>>1)

#define  DVBC_OC_BIST_FAIL                                                       0x180E8CEC
#define  DVBC_OC_BIST_FAIL_reg_addr                                              "0xB80E8CEC"
#define  DVBC_OC_BIST_FAIL_reg                                                   0xB80E8CEC
#define  DVBC_OC_BIST_FAIL_inst_addr                                             "0x01D5"
#define  set_DVBC_OC_BIST_FAIL_reg(data)                                         (*((volatile unsigned int*)DVBC_OC_BIST_FAIL_reg)=data)
#define  get_DVBC_OC_BIST_FAIL_reg                                               (*((volatile unsigned int*)DVBC_OC_BIST_FAIL_reg))
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_bn_shift                            (5)
#define  DVBC_OC_BIST_FAIL_bist_fail_debugdma_shift                              (4)
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_out_shift                           (3)
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_deint_shift                         (2)
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_fftbuf_shift                        (1)
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_bn_mask                             (0x00000020)
#define  DVBC_OC_BIST_FAIL_bist_fail_debugdma_mask                               (0x00000010)
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_out_mask                            (0x00000008)
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_deint_mask                          (0x00000004)
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_fftbuf_mask                         (0x00000002)
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_bn(data)                            (0x00000020&((data)<<5))
#define  DVBC_OC_BIST_FAIL_bist_fail_debugdma(data)                              (0x00000010&((data)<<4))
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_out(data)                           (0x00000008&((data)<<3))
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_deint(data)                         (0x00000004&((data)<<2))
#define  DVBC_OC_BIST_FAIL_bist_fail_cablerx_fftbuf(data)                        (0x00000002&((data)<<1))
#define  DVBC_OC_BIST_FAIL_get_bist_fail_cablerx_bn(data)                        ((0x00000020&(data))>>5)
#define  DVBC_OC_BIST_FAIL_get_bist_fail_debugdma(data)                          ((0x00000010&(data))>>4)
#define  DVBC_OC_BIST_FAIL_get_bist_fail_cablerx_out(data)                       ((0x00000008&(data))>>3)
#define  DVBC_OC_BIST_FAIL_get_bist_fail_cablerx_deint(data)                     ((0x00000004&(data))>>2)
#define  DVBC_OC_BIST_FAIL_get_bist_fail_cablerx_fftbuf(data)                    ((0x00000002&(data))>>1)

#define  DVBC_OC_DRF_BIST_DONE                                                   0x180E8CF0
#define  DVBC_OC_DRF_BIST_DONE_reg_addr                                          "0xB80E8CF0"
#define  DVBC_OC_DRF_BIST_DONE_reg                                               0xB80E8CF0
#define  DVBC_OC_DRF_BIST_DONE_inst_addr                                         "0x01D6"
#define  set_DVBC_OC_DRF_BIST_DONE_reg(data)                                     (*((volatile unsigned int*)DVBC_OC_DRF_BIST_DONE_reg)=data)
#define  get_DVBC_OC_DRF_BIST_DONE_reg                                           (*((volatile unsigned int*)DVBC_OC_DRF_BIST_DONE_reg))
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_bn_shift                    (5)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_debugdma_shift                      (4)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_out_shift                   (3)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_deint_shift                 (2)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_fftbuf_shift                (1)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_bn_mask                     (0x00000020)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_debugdma_mask                       (0x00000010)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_out_mask                    (0x00000008)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_deint_mask                  (0x00000004)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_fftbuf_mask                 (0x00000002)
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_bn(data)                    (0x00000020&((data)<<5))
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_debugdma(data)                      (0x00000010&((data)<<4))
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_out(data)                   (0x00000008&((data)<<3))
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_deint(data)                 (0x00000004&((data)<<2))
#define  DVBC_OC_DRF_BIST_DONE_drf_bist_done_cablerx_fftbuf(data)                (0x00000002&((data)<<1))
#define  DVBC_OC_DRF_BIST_DONE_get_drf_bist_done_cablerx_bn(data)                ((0x00000020&(data))>>5)
#define  DVBC_OC_DRF_BIST_DONE_get_drf_bist_done_debugdma(data)                  ((0x00000010&(data))>>4)
#define  DVBC_OC_DRF_BIST_DONE_get_drf_bist_done_cablerx_out(data)               ((0x00000008&(data))>>3)
#define  DVBC_OC_DRF_BIST_DONE_get_drf_bist_done_cablerx_deint(data)             ((0x00000004&(data))>>2)
#define  DVBC_OC_DRF_BIST_DONE_get_drf_bist_done_cablerx_fftbuf(data)            ((0x00000002&(data))>>1)

#define  DVBC_OC_DRF_BIST_FAIL                                                   0x180E8CF4
#define  DVBC_OC_DRF_BIST_FAIL_reg_addr                                          "0xB80E8CF4"
#define  DVBC_OC_DRF_BIST_FAIL_reg                                               0xB80E8CF4
#define  DVBC_OC_DRF_BIST_FAIL_inst_addr                                         "0x01D7"
#define  set_DVBC_OC_DRF_BIST_FAIL_reg(data)                                     (*((volatile unsigned int*)DVBC_OC_DRF_BIST_FAIL_reg)=data)
#define  get_DVBC_OC_DRF_BIST_FAIL_reg                                           (*((volatile unsigned int*)DVBC_OC_DRF_BIST_FAIL_reg))
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_bn_shift                    (5)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_debugdma_shift                      (4)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_out_shift                   (3)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_deint_shift                 (2)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_fftbuf_shift                (1)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_bn_mask                     (0x00000020)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_debugdma_mask                       (0x00000010)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_out_mask                    (0x00000008)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_deint_mask                  (0x00000004)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_fftbuf_mask                 (0x00000002)
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_bn(data)                    (0x00000020&((data)<<5))
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_debugdma(data)                      (0x00000010&((data)<<4))
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_out(data)                   (0x00000008&((data)<<3))
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_deint(data)                 (0x00000004&((data)<<2))
#define  DVBC_OC_DRF_BIST_FAIL_drf_bist_fail_cablerx_fftbuf(data)                (0x00000002&((data)<<1))
#define  DVBC_OC_DRF_BIST_FAIL_get_drf_bist_fail_cablerx_bn(data)                ((0x00000020&(data))>>5)
#define  DVBC_OC_DRF_BIST_FAIL_get_drf_bist_fail_debugdma(data)                  ((0x00000010&(data))>>4)
#define  DVBC_OC_DRF_BIST_FAIL_get_drf_bist_fail_cablerx_out(data)               ((0x00000008&(data))>>3)
#define  DVBC_OC_DRF_BIST_FAIL_get_drf_bist_fail_cablerx_deint(data)             ((0x00000004&(data))>>2)
#define  DVBC_OC_DRF_BIST_FAIL_get_drf_bist_fail_cablerx_fftbuf(data)            ((0x00000002&(data))>>1)

#define  DVBC_OC_BIST_FFTBUF_FAIL                                                0x180E8CFC
#define  DVBC_OC_BIST_FFTBUF_FAIL_reg_addr                                       "0xB80E8CFC"
#define  DVBC_OC_BIST_FFTBUF_FAIL_reg                                            0xB80E8CFC
#define  DVBC_OC_BIST_FFTBUF_FAIL_inst_addr                                      "0x01D8"
#define  set_DVBC_OC_BIST_FFTBUF_FAIL_reg(data)                                  (*((volatile unsigned int*)DVBC_OC_BIST_FFTBUF_FAIL_reg)=data)
#define  get_DVBC_OC_BIST_FFTBUF_FAIL_reg                                        (*((volatile unsigned int*)DVBC_OC_BIST_FFTBUF_FAIL_reg))
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_3_cablerx_fftbuf_shift               (3)
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_2_cablerx_fftbuf_shift               (2)
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_1_cablerx_fftbuf_shift               (1)
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_0_cablerx_fftbuf_shift               (0)
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_3_cablerx_fftbuf_mask                (0x00000008)
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_2_cablerx_fftbuf_mask                (0x00000004)
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_1_cablerx_fftbuf_mask                (0x00000002)
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_0_cablerx_fftbuf_mask                (0x00000001)
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_3_cablerx_fftbuf(data)               (0x00000008&((data)<<3))
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_2_cablerx_fftbuf(data)               (0x00000004&((data)<<2))
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_1_cablerx_fftbuf(data)               (0x00000002&((data)<<1))
#define  DVBC_OC_BIST_FFTBUF_FAIL_bist_fail_0_cablerx_fftbuf(data)               (0x00000001&(data))
#define  DVBC_OC_BIST_FFTBUF_FAIL_get_bist_fail_3_cablerx_fftbuf(data)           ((0x00000008&(data))>>3)
#define  DVBC_OC_BIST_FFTBUF_FAIL_get_bist_fail_2_cablerx_fftbuf(data)           ((0x00000004&(data))>>2)
#define  DVBC_OC_BIST_FFTBUF_FAIL_get_bist_fail_1_cablerx_fftbuf(data)           ((0x00000002&(data))>>1)
#define  DVBC_OC_BIST_FFTBUF_FAIL_get_bist_fail_0_cablerx_fftbuf(data)           (0x00000001&(data))

#define  DVBC_OC_BIST_DEINT_FAIL                                                 0x180E8D00
#define  DVBC_OC_BIST_DEINT_FAIL_reg_addr                                        "0xB80E8D00"
#define  DVBC_OC_BIST_DEINT_FAIL_reg                                             0xB80E8D00
#define  DVBC_OC_BIST_DEINT_FAIL_inst_addr                                       "0x01D9"
#define  set_DVBC_OC_BIST_DEINT_FAIL_reg(data)                                   (*((volatile unsigned int*)DVBC_OC_BIST_DEINT_FAIL_reg)=data)
#define  get_DVBC_OC_BIST_DEINT_FAIL_reg                                         (*((volatile unsigned int*)DVBC_OC_BIST_DEINT_FAIL_reg))
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_7_cablerx_deint_shift                 (7)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_6_cablerx_deint_shift                 (6)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_5_cablerx_deint_shift                 (5)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_4_cablerx_deint_shift                 (4)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_3_cablerx_deint_shift                 (3)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_2_cablerx_deint_shift                 (2)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_1_cablerx_deint_shift                 (1)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_0_cablerx_deint_shift                 (0)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_7_cablerx_deint_mask                  (0x00000080)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_6_cablerx_deint_mask                  (0x00000040)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_5_cablerx_deint_mask                  (0x00000020)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_4_cablerx_deint_mask                  (0x00000010)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_3_cablerx_deint_mask                  (0x00000008)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_2_cablerx_deint_mask                  (0x00000004)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_1_cablerx_deint_mask                  (0x00000002)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_0_cablerx_deint_mask                  (0x00000001)
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_7_cablerx_deint(data)                 (0x00000080&((data)<<7))
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_6_cablerx_deint(data)                 (0x00000040&((data)<<6))
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_5_cablerx_deint(data)                 (0x00000020&((data)<<5))
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_4_cablerx_deint(data)                 (0x00000010&((data)<<4))
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_3_cablerx_deint(data)                 (0x00000008&((data)<<3))
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_2_cablerx_deint(data)                 (0x00000004&((data)<<2))
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_1_cablerx_deint(data)                 (0x00000002&((data)<<1))
#define  DVBC_OC_BIST_DEINT_FAIL_bist_fail_0_cablerx_deint(data)                 (0x00000001&(data))
#define  DVBC_OC_BIST_DEINT_FAIL_get_bist_fail_7_cablerx_deint(data)             ((0x00000080&(data))>>7)
#define  DVBC_OC_BIST_DEINT_FAIL_get_bist_fail_6_cablerx_deint(data)             ((0x00000040&(data))>>6)
#define  DVBC_OC_BIST_DEINT_FAIL_get_bist_fail_5_cablerx_deint(data)             ((0x00000020&(data))>>5)
#define  DVBC_OC_BIST_DEINT_FAIL_get_bist_fail_4_cablerx_deint(data)             ((0x00000010&(data))>>4)
#define  DVBC_OC_BIST_DEINT_FAIL_get_bist_fail_3_cablerx_deint(data)             ((0x00000008&(data))>>3)
#define  DVBC_OC_BIST_DEINT_FAIL_get_bist_fail_2_cablerx_deint(data)             ((0x00000004&(data))>>2)
#define  DVBC_OC_BIST_DEINT_FAIL_get_bist_fail_1_cablerx_deint(data)             ((0x00000002&(data))>>1)
#define  DVBC_OC_BIST_DEINT_FAIL_get_bist_fail_0_cablerx_deint(data)             (0x00000001&(data))

#define  DVBC_OC_BIST_OUT_FAIL                                                   0x180E8D04
#define  DVBC_OC_BIST_OUT_FAIL_reg_addr                                          "0xB80E8D04"
#define  DVBC_OC_BIST_OUT_FAIL_reg                                               0xB80E8D04
#define  DVBC_OC_BIST_OUT_FAIL_inst_addr                                         "0x01DA"
#define  set_DVBC_OC_BIST_OUT_FAIL_reg(data)                                     (*((volatile unsigned int*)DVBC_OC_BIST_OUT_FAIL_reg)=data)
#define  get_DVBC_OC_BIST_OUT_FAIL_reg                                           (*((volatile unsigned int*)DVBC_OC_BIST_OUT_FAIL_reg))
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_1_cablerx_bn_shift                      (4)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_0_cablerx_bn_shift                      (3)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_2_cablerx_out_shift                     (2)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_1_cablerx_out_shift                     (1)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_0_cablerx_out_shift                     (0)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_1_cablerx_bn_mask                       (0x00000010)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_0_cablerx_bn_mask                       (0x00000008)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_2_cablerx_out_mask                      (0x00000004)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_1_cablerx_out_mask                      (0x00000002)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_0_cablerx_out_mask                      (0x00000001)
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_1_cablerx_bn(data)                      (0x00000010&((data)<<4))
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_0_cablerx_bn(data)                      (0x00000008&((data)<<3))
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_2_cablerx_out(data)                     (0x00000004&((data)<<2))
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_1_cablerx_out(data)                     (0x00000002&((data)<<1))
#define  DVBC_OC_BIST_OUT_FAIL_bist_fail_0_cablerx_out(data)                     (0x00000001&(data))
#define  DVBC_OC_BIST_OUT_FAIL_get_bist_fail_1_cablerx_bn(data)                  ((0x00000010&(data))>>4)
#define  DVBC_OC_BIST_OUT_FAIL_get_bist_fail_0_cablerx_bn(data)                  ((0x00000008&(data))>>3)
#define  DVBC_OC_BIST_OUT_FAIL_get_bist_fail_2_cablerx_out(data)                 ((0x00000004&(data))>>2)
#define  DVBC_OC_BIST_OUT_FAIL_get_bist_fail_1_cablerx_out(data)                 ((0x00000002&(data))>>1)
#define  DVBC_OC_BIST_OUT_FAIL_get_bist_fail_0_cablerx_out(data)                 (0x00000001&(data))

#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL                                            0x180E8D0C
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_reg_addr                                   "0xB80E8D0C"
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_reg                                        0xB80E8D0C
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_inst_addr                                  "0x01DB"
#define  set_DVBC_OC_DRF_BIST_FFTBUF_FAIL_reg(data)                              (*((volatile unsigned int*)DVBC_OC_DRF_BIST_FFTBUF_FAIL_reg)=data)
#define  get_DVBC_OC_DRF_BIST_FFTBUF_FAIL_reg                                    (*((volatile unsigned int*)DVBC_OC_DRF_BIST_FFTBUF_FAIL_reg))
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_3_cablerx_fftbuf_shift       (3)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_2_cablerx_fftbuf_shift       (2)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_1_cablerx_fftbuf_shift       (1)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_0_cablerx_fftbuf_shift       (0)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_3_cablerx_fftbuf_mask        (0x00000008)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_2_cablerx_fftbuf_mask        (0x00000004)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_1_cablerx_fftbuf_mask        (0x00000002)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_0_cablerx_fftbuf_mask        (0x00000001)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_3_cablerx_fftbuf(data)       (0x00000008&((data)<<3))
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_2_cablerx_fftbuf(data)       (0x00000004&((data)<<2))
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_1_cablerx_fftbuf(data)       (0x00000002&((data)<<1))
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_drf_bist_fail_0_cablerx_fftbuf(data)       (0x00000001&(data))
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_get_drf_bist_fail_3_cablerx_fftbuf(data)   ((0x00000008&(data))>>3)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_get_drf_bist_fail_2_cablerx_fftbuf(data)   ((0x00000004&(data))>>2)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_get_drf_bist_fail_1_cablerx_fftbuf(data)   ((0x00000002&(data))>>1)
#define  DVBC_OC_DRF_BIST_FFTBUF_FAIL_get_drf_bist_fail_0_cablerx_fftbuf(data)   (0x00000001&(data))

#define  DVBC_OC_DRF_BIST_DEINT_FAIL                                             0x180E8D10
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_reg_addr                                    "0xB80E8D10"
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_reg                                         0xB80E8D10
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_inst_addr                                   "0x01DC"
#define  set_DVBC_OC_DRF_BIST_DEINT_FAIL_reg(data)                               (*((volatile unsigned int*)DVBC_OC_DRF_BIST_DEINT_FAIL_reg)=data)
#define  get_DVBC_OC_DRF_BIST_DEINT_FAIL_reg                                     (*((volatile unsigned int*)DVBC_OC_DRF_BIST_DEINT_FAIL_reg))
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_7_cablerx_deint_shift         (7)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_6_cablerx_deint_shift         (6)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_5_cablerx_deint_shift         (5)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_4_cablerx_deint_shift         (4)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_3_cablerx_deint_shift         (3)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_2_cablerx_deint_shift         (2)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_1_cablerx_deint_shift         (1)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_0_cablerx_deint_shift         (0)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_7_cablerx_deint_mask          (0x00000080)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_6_cablerx_deint_mask          (0x00000040)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_5_cablerx_deint_mask          (0x00000020)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_4_cablerx_deint_mask          (0x00000010)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_3_cablerx_deint_mask          (0x00000008)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_2_cablerx_deint_mask          (0x00000004)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_1_cablerx_deint_mask          (0x00000002)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_0_cablerx_deint_mask          (0x00000001)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_7_cablerx_deint(data)         (0x00000080&((data)<<7))
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_6_cablerx_deint(data)         (0x00000040&((data)<<6))
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_5_cablerx_deint(data)         (0x00000020&((data)<<5))
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_4_cablerx_deint(data)         (0x00000010&((data)<<4))
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_3_cablerx_deint(data)         (0x00000008&((data)<<3))
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_2_cablerx_deint(data)         (0x00000004&((data)<<2))
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_1_cablerx_deint(data)         (0x00000002&((data)<<1))
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_drf_bist_fail_0_cablerx_deint(data)         (0x00000001&(data))
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_get_drf_bist_fail_7_cablerx_deint(data)     ((0x00000080&(data))>>7)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_get_drf_bist_fail_6_cablerx_deint(data)     ((0x00000040&(data))>>6)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_get_drf_bist_fail_5_cablerx_deint(data)     ((0x00000020&(data))>>5)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_get_drf_bist_fail_4_cablerx_deint(data)     ((0x00000010&(data))>>4)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_get_drf_bist_fail_3_cablerx_deint(data)     ((0x00000008&(data))>>3)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_get_drf_bist_fail_2_cablerx_deint(data)     ((0x00000004&(data))>>2)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_get_drf_bist_fail_1_cablerx_deint(data)     ((0x00000002&(data))>>1)
#define  DVBC_OC_DRF_BIST_DEINT_FAIL_get_drf_bist_fail_0_cablerx_deint(data)     (0x00000001&(data))

#define  DVBC_OC_DRF_BIST_OUT_FAIL                                               0x180E8D14
#define  DVBC_OC_DRF_BIST_OUT_FAIL_reg_addr                                      "0xB80E8D14"
#define  DVBC_OC_DRF_BIST_OUT_FAIL_reg                                           0xB80E8D14
#define  DVBC_OC_DRF_BIST_OUT_FAIL_inst_addr                                     "0x01DD"
#define  set_DVBC_OC_DRF_BIST_OUT_FAIL_reg(data)                                 (*((volatile unsigned int*)DVBC_OC_DRF_BIST_OUT_FAIL_reg)=data)
#define  get_DVBC_OC_DRF_BIST_OUT_FAIL_reg                                       (*((volatile unsigned int*)DVBC_OC_DRF_BIST_OUT_FAIL_reg))
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_1_cablerx_bn_shift              (4)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_0_cablerx_bn_shift              (3)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_2_cablerx_out_shift             (2)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_1_cablerx_out_shift             (1)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_0_cablerx_out_shift             (0)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_1_cablerx_bn_mask               (0x00000010)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_0_cablerx_bn_mask               (0x00000008)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_2_cablerx_out_mask              (0x00000004)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_1_cablerx_out_mask              (0x00000002)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_0_cablerx_out_mask              (0x00000001)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_1_cablerx_bn(data)              (0x00000010&((data)<<4))
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_0_cablerx_bn(data)              (0x00000008&((data)<<3))
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_2_cablerx_out(data)             (0x00000004&((data)<<2))
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_1_cablerx_out(data)             (0x00000002&((data)<<1))
#define  DVBC_OC_DRF_BIST_OUT_FAIL_drf_bist_fail_0_cablerx_out(data)             (0x00000001&(data))
#define  DVBC_OC_DRF_BIST_OUT_FAIL_get_drf_bist_fail_1_cablerx_bn(data)          ((0x00000010&(data))>>4)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_get_drf_bist_fail_0_cablerx_bn(data)          ((0x00000008&(data))>>3)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_get_drf_bist_fail_2_cablerx_out(data)         ((0x00000004&(data))>>2)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_get_drf_bist_fail_1_cablerx_out(data)         ((0x00000002&(data))>>1)
#define  DVBC_OC_DRF_BIST_OUT_FAIL_get_drf_bist_fail_0_cablerx_out(data)         (0x00000001&(data))

#define  DVBC_OC_BIST_DRF_START_PAUSE                                            0x180E8D18
#define  DVBC_OC_BIST_DRF_START_PAUSE_reg_addr                                   "0xB80E8D18"
#define  DVBC_OC_BIST_DRF_START_PAUSE_reg                                        0xB80E8D18
#define  DVBC_OC_BIST_DRF_START_PAUSE_inst_addr                                  "0x01DE"
#define  set_DVBC_OC_BIST_DRF_START_PAUSE_reg(data)                              (*((volatile unsigned int*)DVBC_OC_BIST_DRF_START_PAUSE_reg)=data)
#define  get_DVBC_OC_BIST_DRF_START_PAUSE_reg                                    (*((volatile unsigned int*)DVBC_OC_BIST_DRF_START_PAUSE_reg))
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_bn_shift           (5)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_debugdma_shift             (4)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_out_shift          (3)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_deint_shift        (2)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_fftbuf_shift       (1)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_bn_mask            (0x00000020)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_debugdma_mask              (0x00000010)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_out_mask           (0x00000008)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_deint_mask         (0x00000004)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_fftbuf_mask        (0x00000002)
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_bn(data)           (0x00000020&((data)<<5))
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_debugdma(data)             (0x00000010&((data)<<4))
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_out(data)          (0x00000008&((data)<<3))
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_deint(data)        (0x00000004&((data)<<2))
#define  DVBC_OC_BIST_DRF_START_PAUSE_drf_start_pause_cablerx_fftbuf(data)       (0x00000002&((data)<<1))
#define  DVBC_OC_BIST_DRF_START_PAUSE_get_drf_start_pause_cablerx_bn(data)       ((0x00000020&(data))>>5)
#define  DVBC_OC_BIST_DRF_START_PAUSE_get_drf_start_pause_debugdma(data)         ((0x00000010&(data))>>4)
#define  DVBC_OC_BIST_DRF_START_PAUSE_get_drf_start_pause_cablerx_out(data)      ((0x00000008&(data))>>3)
#define  DVBC_OC_BIST_DRF_START_PAUSE_get_drf_start_pause_cablerx_deint(data)    ((0x00000004&(data))>>2)
#define  DVBC_OC_BIST_DRF_START_PAUSE_get_drf_start_pause_cablerx_fftbuf(data)   ((0x00000002&(data))>>1)

#define  DVBC_DEBUGDMA_CTRL                                                      0x180E8D20
#define  DVBC_DEBUGDMA_CTRL_reg_addr                                             "0xB80E8D20"
#define  DVBC_DEBUGDMA_CTRL_reg                                                  0xB80E8D20
#define  DVBC_DEBUGDMA_CTRL_inst_addr                                            "0x01DF"
#define  set_DVBC_DEBUGDMA_CTRL_reg(data)                                        (*((volatile unsigned int*)DVBC_DEBUGDMA_CTRL_reg)=data)
#define  get_DVBC_DEBUGDMA_CTRL_reg                                              (*((volatile unsigned int*)DVBC_DEBUGDMA_CTRL_reg))
#define  DVBC_DEBUGDMA_CTRL_reg_dump_adc_dagc_sel_shift                          (24)
#define  DVBC_DEBUGDMA_CTRL_reg_dtv_debugdma_en_shift                            (20)
#define  DVBC_DEBUGDMA_CTRL_reg_demod_debugdma_circular_num_shift                (16)
#define  DVBC_DEBUGDMA_CTRL_reg_demod_debugdma_blen_shift                        (8)
#define  DVBC_DEBUGDMA_CTRL_reg_demod_debugdma_waterlvl_shift                    (0)
#define  DVBC_DEBUGDMA_CTRL_reg_dump_adc_dagc_sel_mask                           (0x01000000)
#define  DVBC_DEBUGDMA_CTRL_reg_dtv_debugdma_en_mask                             (0x00100000)
#define  DVBC_DEBUGDMA_CTRL_reg_demod_debugdma_circular_num_mask                 (0x000F0000)
#define  DVBC_DEBUGDMA_CTRL_reg_demod_debugdma_blen_mask                         (0x00003F00)
#define  DVBC_DEBUGDMA_CTRL_reg_demod_debugdma_waterlvl_mask                     (0x0000003F)
#define  DVBC_DEBUGDMA_CTRL_reg_dump_adc_dagc_sel(data)                          (0x01000000&((data)<<24))
#define  DVBC_DEBUGDMA_CTRL_reg_dtv_debugdma_en(data)                            (0x00100000&((data)<<20))
#define  DVBC_DEBUGDMA_CTRL_reg_demod_debugdma_circular_num(data)                (0x000F0000&((data)<<16))
#define  DVBC_DEBUGDMA_CTRL_reg_demod_debugdma_blen(data)                        (0x00003F00&((data)<<8))
#define  DVBC_DEBUGDMA_CTRL_reg_demod_debugdma_waterlvl(data)                    (0x0000003F&(data))
#define  DVBC_DEBUGDMA_CTRL_get_reg_dump_adc_dagc_sel(data)                      ((0x01000000&(data))>>24)
#define  DVBC_DEBUGDMA_CTRL_get_reg_dtv_debugdma_en(data)                        ((0x00100000&(data))>>20)
#define  DVBC_DEBUGDMA_CTRL_get_reg_demod_debugdma_circular_num(data)            ((0x000F0000&(data))>>16)
#define  DVBC_DEBUGDMA_CTRL_get_reg_demod_debugdma_blen(data)                    ((0x00003F00&(data))>>8)
#define  DVBC_DEBUGDMA_CTRL_get_reg_demod_debugdma_waterlvl(data)                (0x0000003F&(data))

#define  DVBC_DEBUGDMA_START_ADDR                                                0x180E8D24
#define  DVBC_DEBUGDMA_START_ADDR_reg_addr                                       "0xB80E8D24"
#define  DVBC_DEBUGDMA_START_ADDR_reg                                            0xB80E8D24
#define  DVBC_DEBUGDMA_START_ADDR_inst_addr                                      "0x01E0"
#define  set_DVBC_DEBUGDMA_START_ADDR_reg(data)                                  (*((volatile unsigned int*)DVBC_DEBUGDMA_START_ADDR_reg)=data)
#define  get_DVBC_DEBUGDMA_START_ADDR_reg                                        (*((volatile unsigned int*)DVBC_DEBUGDMA_START_ADDR_reg))
#define  DVBC_DEBUGDMA_START_ADDR_reg_demod_debugdma_startaddr_shift             (0)
#define  DVBC_DEBUGDMA_START_ADDR_reg_demod_debugdma_startaddr_mask              (0x1FFFFFFF)
#define  DVBC_DEBUGDMA_START_ADDR_reg_demod_debugdma_startaddr(data)             (0x1FFFFFFF&(data))
#define  DVBC_DEBUGDMA_START_ADDR_get_reg_demod_debugdma_startaddr(data)         (0x1FFFFFFF&(data))

#define  DVBC_DEBUGDMA_END_ADDR                                                  0x180E8D28
#define  DVBC_DEBUGDMA_END_ADDR_reg_addr                                         "0xB80E8D28"
#define  DVBC_DEBUGDMA_END_ADDR_reg                                              0xB80E8D28
#define  DVBC_DEBUGDMA_END_ADDR_inst_addr                                        "0x01E1"
#define  set_DVBC_DEBUGDMA_END_ADDR_reg(data)                                    (*((volatile unsigned int*)DVBC_DEBUGDMA_END_ADDR_reg)=data)
#define  get_DVBC_DEBUGDMA_END_ADDR_reg                                          (*((volatile unsigned int*)DVBC_DEBUGDMA_END_ADDR_reg))
#define  DVBC_DEBUGDMA_END_ADDR_reg_demod_debugdma_endaddr_shift                 (0)
#define  DVBC_DEBUGDMA_END_ADDR_reg_demod_debugdma_endaddr_mask                  (0x1FFFFFFF)
#define  DVBC_DEBUGDMA_END_ADDR_reg_demod_debugdma_endaddr(data)                 (0x1FFFFFFF&(data))
#define  DVBC_DEBUGDMA_END_ADDR_get_reg_demod_debugdma_endaddr(data)             (0x1FFFFFFF&(data))

#define  DVBC_DEBUGDMA_STATUS                                                    0x180E8D2C
#define  DVBC_DEBUGDMA_STATUS_reg_addr                                           "0xB80E8D2C"
#define  DVBC_DEBUGDMA_STATUS_reg                                                0xB80E8D2C
#define  DVBC_DEBUGDMA_STATUS_inst_addr                                          "0x01E2"
#define  set_DVBC_DEBUGDMA_STATUS_reg(data)                                      (*((volatile unsigned int*)DVBC_DEBUGDMA_STATUS_reg)=data)
#define  get_DVBC_DEBUGDMA_STATUS_reg                                            (*((volatile unsigned int*)DVBC_DEBUGDMA_STATUS_reg))
#define  DVBC_DEBUGDMA_STATUS_reg_debugdma_underflow_clr_shift                   (5)
#define  DVBC_DEBUGDMA_STATUS_reg_debugdma_overflow_clr_shift                    (4)
#define  DVBC_DEBUGDMA_STATUS_debugdma_underflow_ro_shift                        (1)
#define  DVBC_DEBUGDMA_STATUS_debugdma_overflow_ro_shift                         (0)
#define  DVBC_DEBUGDMA_STATUS_reg_debugdma_underflow_clr_mask                    (0x00000020)
#define  DVBC_DEBUGDMA_STATUS_reg_debugdma_overflow_clr_mask                     (0x00000010)
#define  DVBC_DEBUGDMA_STATUS_debugdma_underflow_ro_mask                         (0x00000002)
#define  DVBC_DEBUGDMA_STATUS_debugdma_overflow_ro_mask                          (0x00000001)
#define  DVBC_DEBUGDMA_STATUS_reg_debugdma_underflow_clr(data)                   (0x00000020&((data)<<5))
#define  DVBC_DEBUGDMA_STATUS_reg_debugdma_overflow_clr(data)                    (0x00000010&((data)<<4))
#define  DVBC_DEBUGDMA_STATUS_debugdma_underflow_ro(data)                        (0x00000002&((data)<<1))
#define  DVBC_DEBUGDMA_STATUS_debugdma_overflow_ro(data)                         (0x00000001&(data))
#define  DVBC_DEBUGDMA_STATUS_get_reg_debugdma_underflow_clr(data)               ((0x00000020&(data))>>5)
#define  DVBC_DEBUGDMA_STATUS_get_reg_debugdma_overflow_clr(data)                ((0x00000010&(data))>>4)
#define  DVBC_DEBUGDMA_STATUS_get_debugdma_underflow_ro(data)                    ((0x00000002&(data))>>1)
#define  DVBC_DEBUGDMA_STATUS_get_debugdma_overflow_ro(data)                     (0x00000001&(data))

#define  DVBC_PSD_START                                                          0x180E8D30
#define  DVBC_PSD_START_reg_addr                                                 "0xB80E8D30"
#define  DVBC_PSD_START_reg                                                      0xB80E8D30
#define  DVBC_PSD_START_inst_addr                                                "0x01E3"
#define  set_DVBC_PSD_START_reg(data)                                            (*((volatile unsigned int*)DVBC_PSD_START_reg)=data)
#define  get_DVBC_PSD_START_reg                                                  (*((volatile unsigned int*)DVBC_PSD_START_reg))
#define  DVBC_PSD_START_reg_r_psd_start_shift                                    (0)
#define  DVBC_PSD_START_reg_r_psd_start_mask                                     (0x00000001)
#define  DVBC_PSD_START_reg_r_psd_start(data)                                    (0x00000001&(data))
#define  DVBC_PSD_START_get_reg_r_psd_start(data)                                (0x00000001&(data))

#define  DVBC_PSD_CTRL                                                           0x180E8D34
#define  DVBC_PSD_CTRL_reg_addr                                                  "0xB80E8D34"
#define  DVBC_PSD_CTRL_reg                                                       0xB80E8D34
#define  DVBC_PSD_CTRL_inst_addr                                                 "0x01E4"
#define  set_DVBC_PSD_CTRL_reg(data)                                             (*((volatile unsigned int*)DVBC_PSD_CTRL_reg)=data)
#define  get_DVBC_PSD_CTRL_reg                                                   (*((volatile unsigned int*)DVBC_PSD_CTRL_reg))
#define  DVBC_PSD_CTRL_reg_r_psd_scale_shift                                     (24)
#define  DVBC_PSD_CTRL_reg_r_psd_dco_shift                                       (16)
#define  DVBC_PSD_CTRL_reg_r_psd_ctrl2_shift                                     (8)
#define  DVBC_PSD_CTRL_reg_r_psd_ctrl1_shift                                     (0)
#define  DVBC_PSD_CTRL_reg_r_psd_scale_mask                                      (0xFF000000)
#define  DVBC_PSD_CTRL_reg_r_psd_dco_mask                                        (0x00FF0000)
#define  DVBC_PSD_CTRL_reg_r_psd_ctrl2_mask                                      (0x0000FF00)
#define  DVBC_PSD_CTRL_reg_r_psd_ctrl1_mask                                      (0x000000FF)
#define  DVBC_PSD_CTRL_reg_r_psd_scale(data)                                     (0xFF000000&((data)<<24))
#define  DVBC_PSD_CTRL_reg_r_psd_dco(data)                                       (0x00FF0000&((data)<<16))
#define  DVBC_PSD_CTRL_reg_r_psd_ctrl2(data)                                     (0x0000FF00&((data)<<8))
#define  DVBC_PSD_CTRL_reg_r_psd_ctrl1(data)                                     (0x000000FF&(data))
#define  DVBC_PSD_CTRL_get_reg_r_psd_scale(data)                                 ((0xFF000000&(data))>>24)
#define  DVBC_PSD_CTRL_get_reg_r_psd_dco(data)                                   ((0x00FF0000&(data))>>16)
#define  DVBC_PSD_CTRL_get_reg_r_psd_ctrl2(data)                                 ((0x0000FF00&(data))>>8)
#define  DVBC_PSD_CTRL_get_reg_r_psd_ctrl1(data)                                 (0x000000FF&(data))

#define  DVBC_PSD_STATUS                                                         0x180E8D38
#define  DVBC_PSD_STATUS_reg_addr                                                "0xB80E8D38"
#define  DVBC_PSD_STATUS_reg                                                     0xB80E8D38
#define  DVBC_PSD_STATUS_inst_addr                                               "0x01E5"
#define  set_DVBC_PSD_STATUS_reg(data)                                           (*((volatile unsigned int*)DVBC_PSD_STATUS_reg)=data)
#define  get_DVBC_PSD_STATUS_reg                                                 (*((volatile unsigned int*)DVBC_PSD_STATUS_reg))
#define  DVBC_PSD_STATUS_psd_done_shift                                          (16)
#define  DVBC_PSD_STATUS_psd_pwr_shift                                           (0)
#define  DVBC_PSD_STATUS_psd_done_mask                                           (0x00010000)
#define  DVBC_PSD_STATUS_psd_pwr_mask                                            (0x0000FFFF)
#define  DVBC_PSD_STATUS_psd_done(data)                                          (0x00010000&((data)<<16))
#define  DVBC_PSD_STATUS_psd_pwr(data)                                           (0x0000FFFF&(data))
#define  DVBC_PSD_STATUS_get_psd_done(data)                                      ((0x00010000&(data))>>16)
#define  DVBC_PSD_STATUS_get_psd_pwr(data)                                       (0x0000FFFF&(data))

#define  DVBC_SRS_DEINT_SRAM                                                     0x180E8D40
#define  DVBC_SRS_DEINT_SRAM_reg_addr                                            "0xB80E8D40"
#define  DVBC_SRS_DEINT_SRAM_reg                                                 0xB80E8D40
#define  DVBC_SRS_DEINT_SRAM_inst_addr                                           "0x01E6"
#define  set_DVBC_SRS_DEINT_SRAM_reg(data)                                       (*((volatile unsigned int*)DVBC_SRS_DEINT_SRAM_reg)=data)
#define  get_DVBC_SRS_DEINT_SRAM_reg                                             (*((volatile unsigned int*)DVBC_SRS_DEINT_SRAM_reg))
#define  DVBC_SRS_DEINT_SRAM_srs_deint_sram_fw_mode_shift                        (1)
#define  DVBC_SRS_DEINT_SRAM_srs_deint_sram_mode_shift                           (0)
#define  DVBC_SRS_DEINT_SRAM_srs_deint_sram_fw_mode_mask                         (0x00000002)
#define  DVBC_SRS_DEINT_SRAM_srs_deint_sram_mode_mask                            (0x00000001)
#define  DVBC_SRS_DEINT_SRAM_srs_deint_sram_fw_mode(data)                        (0x00000002&((data)<<1))
#define  DVBC_SRS_DEINT_SRAM_srs_deint_sram_mode(data)                           (0x00000001&(data))
#define  DVBC_SRS_DEINT_SRAM_get_srs_deint_sram_fw_mode(data)                    ((0x00000002&(data))>>1)
#define  DVBC_SRS_DEINT_SRAM_get_srs_deint_sram_mode(data)                       (0x00000001&(data))

#define  DVBC_POS_SLOT_AVG_VAL_1                                                 0x180E8D44
#define  DVBC_POS_SLOT_AVG_VAL_1_reg_addr                                        "0xB80E8D44"
#define  DVBC_POS_SLOT_AVG_VAL_1_reg                                             0xB80E8D44
#define  DVBC_POS_SLOT_AVG_VAL_1_inst_addr                                       "0x01E7"
#define  set_DVBC_POS_SLOT_AVG_VAL_1_reg(data)                                   (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_1_reg)=data)
#define  get_DVBC_POS_SLOT_AVG_VAL_1_reg                                         (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_1_reg))
#define  DVBC_POS_SLOT_AVG_VAL_1_pos_slot_avg_val_1_7_0_shift                    (0)
#define  DVBC_POS_SLOT_AVG_VAL_1_pos_slot_avg_val_1_7_0_mask                     (0x000000FF)
#define  DVBC_POS_SLOT_AVG_VAL_1_pos_slot_avg_val_1_7_0(data)                    (0x000000FF&(data))
#define  DVBC_POS_SLOT_AVG_VAL_1_get_pos_slot_avg_val_1_7_0(data)                (0x000000FF&(data))

#define  DVBC_POS_SLOT_AVG_VAL_1_1                                               0x180E8D48
#define  DVBC_POS_SLOT_AVG_VAL_1_1_reg_addr                                      "0xB80E8D48"
#define  DVBC_POS_SLOT_AVG_VAL_1_1_reg                                           0xB80E8D48
#define  DVBC_POS_SLOT_AVG_VAL_1_1_inst_addr                                     "0x01E8"
#define  set_DVBC_POS_SLOT_AVG_VAL_1_1_reg(data)                                 (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_1_1_reg)=data)
#define  get_DVBC_POS_SLOT_AVG_VAL_1_1_reg                                       (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_1_1_reg))
#define  DVBC_POS_SLOT_AVG_VAL_1_1_pos_slot_avg_val_1_15_8_shift                 (0)
#define  DVBC_POS_SLOT_AVG_VAL_1_1_pos_slot_avg_val_1_15_8_mask                  (0x000000FF)
#define  DVBC_POS_SLOT_AVG_VAL_1_1_pos_slot_avg_val_1_15_8(data)                 (0x000000FF&(data))
#define  DVBC_POS_SLOT_AVG_VAL_1_1_get_pos_slot_avg_val_1_15_8(data)             (0x000000FF&(data))

#define  DVBC_POS_SLOT_AVG_VAL_2                                                 0x180E8D4C
#define  DVBC_POS_SLOT_AVG_VAL_2_reg_addr                                        "0xB80E8D4C"
#define  DVBC_POS_SLOT_AVG_VAL_2_reg                                             0xB80E8D4C
#define  DVBC_POS_SLOT_AVG_VAL_2_inst_addr                                       "0x01E9"
#define  set_DVBC_POS_SLOT_AVG_VAL_2_reg(data)                                   (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_2_reg)=data)
#define  get_DVBC_POS_SLOT_AVG_VAL_2_reg                                         (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_2_reg))
#define  DVBC_POS_SLOT_AVG_VAL_2_pos_slot_avg_val_2_7_0_shift                    (0)
#define  DVBC_POS_SLOT_AVG_VAL_2_pos_slot_avg_val_2_7_0_mask                     (0x000000FF)
#define  DVBC_POS_SLOT_AVG_VAL_2_pos_slot_avg_val_2_7_0(data)                    (0x000000FF&(data))
#define  DVBC_POS_SLOT_AVG_VAL_2_get_pos_slot_avg_val_2_7_0(data)                (0x000000FF&(data))

#define  DVBC_POS_SLOT_AVG_VAL_2_1                                               0x180E8D50
#define  DVBC_POS_SLOT_AVG_VAL_2_1_reg_addr                                      "0xB80E8D50"
#define  DVBC_POS_SLOT_AVG_VAL_2_1_reg                                           0xB80E8D50
#define  DVBC_POS_SLOT_AVG_VAL_2_1_inst_addr                                     "0x01EA"
#define  set_DVBC_POS_SLOT_AVG_VAL_2_1_reg(data)                                 (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_2_1_reg)=data)
#define  get_DVBC_POS_SLOT_AVG_VAL_2_1_reg                                       (*((volatile unsigned int*)DVBC_POS_SLOT_AVG_VAL_2_1_reg))
#define  DVBC_POS_SLOT_AVG_VAL_2_1_pos_slot_avg_val_2_15_8_shift                 (0)
#define  DVBC_POS_SLOT_AVG_VAL_2_1_pos_slot_avg_val_2_15_8_mask                  (0x000000FF)
#define  DVBC_POS_SLOT_AVG_VAL_2_1_pos_slot_avg_val_2_15_8(data)                 (0x000000FF&(data))
#define  DVBC_POS_SLOT_AVG_VAL_2_1_get_pos_slot_avg_val_2_15_8(data)             (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_VAL_0                                                 0x180E8D54
#define  DVBC_NEG_TONE_MAX_VAL_0_reg_addr                                        "0xB80E8D54"
#define  DVBC_NEG_TONE_MAX_VAL_0_reg                                             0xB80E8D54
#define  DVBC_NEG_TONE_MAX_VAL_0_inst_addr                                       "0x01EB"
#define  set_DVBC_NEG_TONE_MAX_VAL_0_reg(data)                                   (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_0_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_VAL_0_reg                                         (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_0_reg))
#define  DVBC_NEG_TONE_MAX_VAL_0_neg_tone_max_val_0_7_0_shift                    (0)
#define  DVBC_NEG_TONE_MAX_VAL_0_neg_tone_max_val_0_7_0_mask                     (0x000000FF)
#define  DVBC_NEG_TONE_MAX_VAL_0_neg_tone_max_val_0_7_0(data)                    (0x000000FF&(data))
#define  DVBC_NEG_TONE_MAX_VAL_0_get_neg_tone_max_val_0_7_0(data)                (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_VAL_0_1                                               0x180E8D58
#define  DVBC_NEG_TONE_MAX_VAL_0_1_reg_addr                                      "0xB80E8D58"
#define  DVBC_NEG_TONE_MAX_VAL_0_1_reg                                           0xB80E8D58
#define  DVBC_NEG_TONE_MAX_VAL_0_1_inst_addr                                     "0x01EC"
#define  set_DVBC_NEG_TONE_MAX_VAL_0_1_reg(data)                                 (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_0_1_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_VAL_0_1_reg                                       (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_0_1_reg))
#define  DVBC_NEG_TONE_MAX_VAL_0_1_neg_tone_max_val_0_15_8_shift                 (0)
#define  DVBC_NEG_TONE_MAX_VAL_0_1_neg_tone_max_val_0_15_8_mask                  (0x000000FF)
#define  DVBC_NEG_TONE_MAX_VAL_0_1_neg_tone_max_val_0_15_8(data)                 (0x000000FF&(data))
#define  DVBC_NEG_TONE_MAX_VAL_0_1_get_neg_tone_max_val_0_15_8(data)             (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_VAL_1                                                 0x180E8D5C
#define  DVBC_NEG_TONE_MAX_VAL_1_reg_addr                                        "0xB80E8D5C"
#define  DVBC_NEG_TONE_MAX_VAL_1_reg                                             0xB80E8D5C
#define  DVBC_NEG_TONE_MAX_VAL_1_inst_addr                                       "0x01ED"
#define  set_DVBC_NEG_TONE_MAX_VAL_1_reg(data)                                   (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_1_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_VAL_1_reg                                         (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_1_reg))
#define  DVBC_NEG_TONE_MAX_VAL_1_neg_tone_max_val_1_7_0_shift                    (0)
#define  DVBC_NEG_TONE_MAX_VAL_1_neg_tone_max_val_1_7_0_mask                     (0x000000FF)
#define  DVBC_NEG_TONE_MAX_VAL_1_neg_tone_max_val_1_7_0(data)                    (0x000000FF&(data))
#define  DVBC_NEG_TONE_MAX_VAL_1_get_neg_tone_max_val_1_7_0(data)                (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_VAL_1_1                                               0x180E8D60
#define  DVBC_NEG_TONE_MAX_VAL_1_1_reg_addr                                      "0xB80E8D60"
#define  DVBC_NEG_TONE_MAX_VAL_1_1_reg                                           0xB80E8D60
#define  DVBC_NEG_TONE_MAX_VAL_1_1_inst_addr                                     "0x01EE"
#define  set_DVBC_NEG_TONE_MAX_VAL_1_1_reg(data)                                 (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_1_1_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_VAL_1_1_reg                                       (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_1_1_reg))
#define  DVBC_NEG_TONE_MAX_VAL_1_1_neg_tone_max_val_1_15_8_shift                 (0)
#define  DVBC_NEG_TONE_MAX_VAL_1_1_neg_tone_max_val_1_15_8_mask                  (0x000000FF)
#define  DVBC_NEG_TONE_MAX_VAL_1_1_neg_tone_max_val_1_15_8(data)                 (0x000000FF&(data))
#define  DVBC_NEG_TONE_MAX_VAL_1_1_get_neg_tone_max_val_1_15_8(data)             (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_VAL_2                                                 0x180E8D64
#define  DVBC_NEG_TONE_MAX_VAL_2_reg_addr                                        "0xB80E8D64"
#define  DVBC_NEG_TONE_MAX_VAL_2_reg                                             0xB80E8D64
#define  DVBC_NEG_TONE_MAX_VAL_2_inst_addr                                       "0x01EF"
#define  set_DVBC_NEG_TONE_MAX_VAL_2_reg(data)                                   (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_2_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_VAL_2_reg                                         (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_2_reg))
#define  DVBC_NEG_TONE_MAX_VAL_2_neg_tone_max_val_2_7_0_shift                    (0)
#define  DVBC_NEG_TONE_MAX_VAL_2_neg_tone_max_val_2_7_0_mask                     (0x000000FF)
#define  DVBC_NEG_TONE_MAX_VAL_2_neg_tone_max_val_2_7_0(data)                    (0x000000FF&(data))
#define  DVBC_NEG_TONE_MAX_VAL_2_get_neg_tone_max_val_2_7_0(data)                (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_VAL_2_1                                               0x180E8D68
#define  DVBC_NEG_TONE_MAX_VAL_2_1_reg_addr                                      "0xB80E8D68"
#define  DVBC_NEG_TONE_MAX_VAL_2_1_reg                                           0xB80E8D68
#define  DVBC_NEG_TONE_MAX_VAL_2_1_inst_addr                                     "0x01F0"
#define  set_DVBC_NEG_TONE_MAX_VAL_2_1_reg(data)                                 (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_2_1_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_VAL_2_1_reg                                       (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_VAL_2_1_reg))
#define  DVBC_NEG_TONE_MAX_VAL_2_1_neg_tone_max_val_2_15_8_shift                 (0)
#define  DVBC_NEG_TONE_MAX_VAL_2_1_neg_tone_max_val_2_15_8_mask                  (0x000000FF)
#define  DVBC_NEG_TONE_MAX_VAL_2_1_neg_tone_max_val_2_15_8(data)                 (0x000000FF&(data))
#define  DVBC_NEG_TONE_MAX_VAL_2_1_get_neg_tone_max_val_2_15_8(data)             (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_IDX_0                                                 0x180E8D6C
#define  DVBC_NEG_TONE_MAX_IDX_0_reg_addr                                        "0xB80E8D6C"
#define  DVBC_NEG_TONE_MAX_IDX_0_reg                                             0xB80E8D6C
#define  DVBC_NEG_TONE_MAX_IDX_0_inst_addr                                       "0x01F1"
#define  set_DVBC_NEG_TONE_MAX_IDX_0_reg(data)                                   (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_0_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_IDX_0_reg                                         (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_0_reg))
#define  DVBC_NEG_TONE_MAX_IDX_0_neg_tone_max_idx_0_7_0_shift                    (0)
#define  DVBC_NEG_TONE_MAX_IDX_0_neg_tone_max_idx_0_7_0_mask                     (0x000000FF)
#define  DVBC_NEG_TONE_MAX_IDX_0_neg_tone_max_idx_0_7_0(data)                    (0x000000FF&(data))
#define  DVBC_NEG_TONE_MAX_IDX_0_get_neg_tone_max_idx_0_7_0(data)                (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_IDX_0_1                                               0x180E8D70
#define  DVBC_NEG_TONE_MAX_IDX_0_1_reg_addr                                      "0xB80E8D70"
#define  DVBC_NEG_TONE_MAX_IDX_0_1_reg                                           0xB80E8D70
#define  DVBC_NEG_TONE_MAX_IDX_0_1_inst_addr                                     "0x01F2"
#define  set_DVBC_NEG_TONE_MAX_IDX_0_1_reg(data)                                 (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_0_1_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_IDX_0_1_reg                                       (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_0_1_reg))
#define  DVBC_NEG_TONE_MAX_IDX_0_1_neg_tone_max_idx_0_11_8_shift                 (0)
#define  DVBC_NEG_TONE_MAX_IDX_0_1_neg_tone_max_idx_0_11_8_mask                  (0x0000000F)
#define  DVBC_NEG_TONE_MAX_IDX_0_1_neg_tone_max_idx_0_11_8(data)                 (0x0000000F&(data))
#define  DVBC_NEG_TONE_MAX_IDX_0_1_get_neg_tone_max_idx_0_11_8(data)             (0x0000000F&(data))

#define  DVBC_NEG_TONE_MAX_IDX_1                                                 0x180E8D74
#define  DVBC_NEG_TONE_MAX_IDX_1_reg_addr                                        "0xB80E8D74"
#define  DVBC_NEG_TONE_MAX_IDX_1_reg                                             0xB80E8D74
#define  DVBC_NEG_TONE_MAX_IDX_1_inst_addr                                       "0x01F3"
#define  set_DVBC_NEG_TONE_MAX_IDX_1_reg(data)                                   (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_1_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_IDX_1_reg                                         (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_1_reg))
#define  DVBC_NEG_TONE_MAX_IDX_1_neg_tone_max_idx_1_7_0_shift                    (0)
#define  DVBC_NEG_TONE_MAX_IDX_1_neg_tone_max_idx_1_7_0_mask                     (0x000000FF)
#define  DVBC_NEG_TONE_MAX_IDX_1_neg_tone_max_idx_1_7_0(data)                    (0x000000FF&(data))
#define  DVBC_NEG_TONE_MAX_IDX_1_get_neg_tone_max_idx_1_7_0(data)                (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_IDX_1_1                                               0x180E8D78
#define  DVBC_NEG_TONE_MAX_IDX_1_1_reg_addr                                      "0xB80E8D78"
#define  DVBC_NEG_TONE_MAX_IDX_1_1_reg                                           0xB80E8D78
#define  DVBC_NEG_TONE_MAX_IDX_1_1_inst_addr                                     "0x01F4"
#define  set_DVBC_NEG_TONE_MAX_IDX_1_1_reg(data)                                 (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_1_1_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_IDX_1_1_reg                                       (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_1_1_reg))
#define  DVBC_NEG_TONE_MAX_IDX_1_1_neg_tone_max_idx_1_11_8_shift                 (0)
#define  DVBC_NEG_TONE_MAX_IDX_1_1_neg_tone_max_idx_1_11_8_mask                  (0x0000000F)
#define  DVBC_NEG_TONE_MAX_IDX_1_1_neg_tone_max_idx_1_11_8(data)                 (0x0000000F&(data))
#define  DVBC_NEG_TONE_MAX_IDX_1_1_get_neg_tone_max_idx_1_11_8(data)             (0x0000000F&(data))

#define  DVBC_NEG_TONE_MAX_IDX_2                                                 0x180E8D7C
#define  DVBC_NEG_TONE_MAX_IDX_2_reg_addr                                        "0xB80E8D7C"
#define  DVBC_NEG_TONE_MAX_IDX_2_reg                                             0xB80E8D7C
#define  DVBC_NEG_TONE_MAX_IDX_2_inst_addr                                       "0x01F5"
#define  set_DVBC_NEG_TONE_MAX_IDX_2_reg(data)                                   (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_2_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_IDX_2_reg                                         (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_2_reg))
#define  DVBC_NEG_TONE_MAX_IDX_2_neg_tone_max_idx_2_7_0_shift                    (0)
#define  DVBC_NEG_TONE_MAX_IDX_2_neg_tone_max_idx_2_7_0_mask                     (0x000000FF)
#define  DVBC_NEG_TONE_MAX_IDX_2_neg_tone_max_idx_2_7_0(data)                    (0x000000FF&(data))
#define  DVBC_NEG_TONE_MAX_IDX_2_get_neg_tone_max_idx_2_7_0(data)                (0x000000FF&(data))

#define  DVBC_NEG_TONE_MAX_IDX_2_1                                               0x180E8D80
#define  DVBC_NEG_TONE_MAX_IDX_2_1_reg_addr                                      "0xB80E8D80"
#define  DVBC_NEG_TONE_MAX_IDX_2_1_reg                                           0xB80E8D80
#define  DVBC_NEG_TONE_MAX_IDX_2_1_inst_addr                                     "0x01F6"
#define  set_DVBC_NEG_TONE_MAX_IDX_2_1_reg(data)                                 (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_2_1_reg)=data)
#define  get_DVBC_NEG_TONE_MAX_IDX_2_1_reg                                       (*((volatile unsigned int*)DVBC_NEG_TONE_MAX_IDX_2_1_reg))
#define  DVBC_NEG_TONE_MAX_IDX_2_1_neg_tone_max_idx_2_11_8_shift                 (0)
#define  DVBC_NEG_TONE_MAX_IDX_2_1_neg_tone_max_idx_2_11_8_mask                  (0x0000000F)
#define  DVBC_NEG_TONE_MAX_IDX_2_1_neg_tone_max_idx_2_11_8(data)                 (0x0000000F&(data))
#define  DVBC_NEG_TONE_MAX_IDX_2_1_get_neg_tone_max_idx_2_11_8(data)             (0x0000000F&(data))

#define  DVBC_NEG_SLOT_AVG_VAL_0                                                 0x180E8D84
#define  DVBC_NEG_SLOT_AVG_VAL_0_reg_addr                                        "0xB80E8D84"
#define  DVBC_NEG_SLOT_AVG_VAL_0_reg                                             0xB80E8D84
#define  DVBC_NEG_SLOT_AVG_VAL_0_inst_addr                                       "0x01F7"
#define  set_DVBC_NEG_SLOT_AVG_VAL_0_reg(data)                                   (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_0_reg)=data)
#define  get_DVBC_NEG_SLOT_AVG_VAL_0_reg                                         (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_0_reg))
#define  DVBC_NEG_SLOT_AVG_VAL_0_neg_slot_avg_val_0_7_0_shift                    (0)
#define  DVBC_NEG_SLOT_AVG_VAL_0_neg_slot_avg_val_0_7_0_mask                     (0x000000FF)
#define  DVBC_NEG_SLOT_AVG_VAL_0_neg_slot_avg_val_0_7_0(data)                    (0x000000FF&(data))
#define  DVBC_NEG_SLOT_AVG_VAL_0_get_neg_slot_avg_val_0_7_0(data)                (0x000000FF&(data))

#define  DVBC_NEG_SLOT_AVG_VAL_0_1                                               0x180E8D88
#define  DVBC_NEG_SLOT_AVG_VAL_0_1_reg_addr                                      "0xB80E8D88"
#define  DVBC_NEG_SLOT_AVG_VAL_0_1_reg                                           0xB80E8D88
#define  DVBC_NEG_SLOT_AVG_VAL_0_1_inst_addr                                     "0x01F8"
#define  set_DVBC_NEG_SLOT_AVG_VAL_0_1_reg(data)                                 (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_0_1_reg)=data)
#define  get_DVBC_NEG_SLOT_AVG_VAL_0_1_reg                                       (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_0_1_reg))
#define  DVBC_NEG_SLOT_AVG_VAL_0_1_neg_slot_avg_val_0_15_8_shift                 (0)
#define  DVBC_NEG_SLOT_AVG_VAL_0_1_neg_slot_avg_val_0_15_8_mask                  (0x000000FF)
#define  DVBC_NEG_SLOT_AVG_VAL_0_1_neg_slot_avg_val_0_15_8(data)                 (0x000000FF&(data))
#define  DVBC_NEG_SLOT_AVG_VAL_0_1_get_neg_slot_avg_val_0_15_8(data)             (0x000000FF&(data))

#define  DVBC_NEG_SLOT_AVG_VAL_1                                                 0x180E8D8C
#define  DVBC_NEG_SLOT_AVG_VAL_1_reg_addr                                        "0xB80E8D8C"
#define  DVBC_NEG_SLOT_AVG_VAL_1_reg                                             0xB80E8D8C
#define  DVBC_NEG_SLOT_AVG_VAL_1_inst_addr                                       "0x01F9"
#define  set_DVBC_NEG_SLOT_AVG_VAL_1_reg(data)                                   (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_1_reg)=data)
#define  get_DVBC_NEG_SLOT_AVG_VAL_1_reg                                         (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_1_reg))
#define  DVBC_NEG_SLOT_AVG_VAL_1_neg_slot_avg_val_1_7_0_shift                    (0)
#define  DVBC_NEG_SLOT_AVG_VAL_1_neg_slot_avg_val_1_7_0_mask                     (0x000000FF)
#define  DVBC_NEG_SLOT_AVG_VAL_1_neg_slot_avg_val_1_7_0(data)                    (0x000000FF&(data))
#define  DVBC_NEG_SLOT_AVG_VAL_1_get_neg_slot_avg_val_1_7_0(data)                (0x000000FF&(data))

#define  DVBC_NEG_SLOT_AVG_VAL_1_1                                               0x180E8D90
#define  DVBC_NEG_SLOT_AVG_VAL_1_1_reg_addr                                      "0xB80E8D90"
#define  DVBC_NEG_SLOT_AVG_VAL_1_1_reg                                           0xB80E8D90
#define  DVBC_NEG_SLOT_AVG_VAL_1_1_inst_addr                                     "0x01FA"
#define  set_DVBC_NEG_SLOT_AVG_VAL_1_1_reg(data)                                 (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_1_1_reg)=data)
#define  get_DVBC_NEG_SLOT_AVG_VAL_1_1_reg                                       (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_1_1_reg))
#define  DVBC_NEG_SLOT_AVG_VAL_1_1_neg_slot_avg_val_1_15_8_shift                 (0)
#define  DVBC_NEG_SLOT_AVG_VAL_1_1_neg_slot_avg_val_1_15_8_mask                  (0x000000FF)
#define  DVBC_NEG_SLOT_AVG_VAL_1_1_neg_slot_avg_val_1_15_8(data)                 (0x000000FF&(data))
#define  DVBC_NEG_SLOT_AVG_VAL_1_1_get_neg_slot_avg_val_1_15_8(data)             (0x000000FF&(data))

#define  DVBC_NEG_SLOT_AVG_VAL_2                                                 0x180E8D94
#define  DVBC_NEG_SLOT_AVG_VAL_2_reg_addr                                        "0xB80E8D94"
#define  DVBC_NEG_SLOT_AVG_VAL_2_reg                                             0xB80E8D94
#define  DVBC_NEG_SLOT_AVG_VAL_2_inst_addr                                       "0x01FB"
#define  set_DVBC_NEG_SLOT_AVG_VAL_2_reg(data)                                   (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_2_reg)=data)
#define  get_DVBC_NEG_SLOT_AVG_VAL_2_reg                                         (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_2_reg))
#define  DVBC_NEG_SLOT_AVG_VAL_2_neg_slot_avg_val_2_7_0_shift                    (0)
#define  DVBC_NEG_SLOT_AVG_VAL_2_neg_slot_avg_val_2_7_0_mask                     (0x000000FF)
#define  DVBC_NEG_SLOT_AVG_VAL_2_neg_slot_avg_val_2_7_0(data)                    (0x000000FF&(data))
#define  DVBC_NEG_SLOT_AVG_VAL_2_get_neg_slot_avg_val_2_7_0(data)                (0x000000FF&(data))

#define  DVBC_NEG_SLOT_AVG_VAL_2_1                                               0x180E8D98
#define  DVBC_NEG_SLOT_AVG_VAL_2_1_reg_addr                                      "0xB80E8D98"
#define  DVBC_NEG_SLOT_AVG_VAL_2_1_reg                                           0xB80E8D98
#define  DVBC_NEG_SLOT_AVG_VAL_2_1_inst_addr                                     "0x01FC"
#define  set_DVBC_NEG_SLOT_AVG_VAL_2_1_reg(data)                                 (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_2_1_reg)=data)
#define  get_DVBC_NEG_SLOT_AVG_VAL_2_1_reg                                       (*((volatile unsigned int*)DVBC_NEG_SLOT_AVG_VAL_2_1_reg))
#define  DVBC_NEG_SLOT_AVG_VAL_2_1_neg_slot_avg_val_2_15_8_shift                 (0)
#define  DVBC_NEG_SLOT_AVG_VAL_2_1_neg_slot_avg_val_2_15_8_mask                  (0x000000FF)
#define  DVBC_NEG_SLOT_AVG_VAL_2_1_neg_slot_avg_val_2_15_8(data)                 (0x000000FF&(data))
#define  DVBC_NEG_SLOT_AVG_VAL_2_1_get_neg_slot_avg_val_2_15_8(data)             (0x000000FF&(data))

#define  DVBC_OPT_SRS_INPUT_SEL                                                  0x180E8D9C
#define  DVBC_OPT_SRS_INPUT_SEL_reg_addr                                         "0xB80E8D9C"
#define  DVBC_OPT_SRS_INPUT_SEL_reg                                              0xB80E8D9C
#define  DVBC_OPT_SRS_INPUT_SEL_inst_addr                                        "0x01FD"
#define  set_DVBC_OPT_SRS_INPUT_SEL_reg(data)                                    (*((volatile unsigned int*)DVBC_OPT_SRS_INPUT_SEL_reg)=data)
#define  get_DVBC_OPT_SRS_INPUT_SEL_reg                                          (*((volatile unsigned int*)DVBC_OPT_SRS_INPUT_SEL_reg))
#define  DVBC_OPT_SRS_INPUT_SEL_opt_srs_input_sel_shift                          (0)
#define  DVBC_OPT_SRS_INPUT_SEL_opt_srs_input_sel_mask                           (0x00000001)
#define  DVBC_OPT_SRS_INPUT_SEL_opt_srs_input_sel(data)                          (0x00000001&(data))
#define  DVBC_OPT_SRS_INPUT_SEL_get_opt_srs_input_sel(data)                      (0x00000001&(data))

#define  DVBC_BNM_CTRL_0                                                         0x180E8DA0
#define  DVBC_BNM_CTRL_0_reg_addr                                                "0xB80E8DA0"
#define  DVBC_BNM_CTRL_0_reg                                                     0xB80E8DA0
#define  DVBC_BNM_CTRL_0_inst_addr                                               "0x01FE"
#define  set_DVBC_BNM_CTRL_0_reg(data)                                           (*((volatile unsigned int*)DVBC_BNM_CTRL_0_reg)=data)
#define  get_DVBC_BNM_CTRL_0_reg                                                 (*((volatile unsigned int*)DVBC_BNM_CTRL_0_reg))
#define  DVBC_BNM_CTRL_0_bnm_cnt_rst_shift                                       (6)
#define  DVBC_BNM_CTRL_0_bnm_mu_shift                                            (4)
#define  DVBC_BNM_CTRL_0_bnm_on_shift                                            (3)
#define  DVBC_BNM_CTRL_0_bnm_window_en_on_shift                                  (0)
#define  DVBC_BNM_CTRL_0_bnm_cnt_rst_mask                                        (0x00000040)
#define  DVBC_BNM_CTRL_0_bnm_mu_mask                                             (0x00000030)
#define  DVBC_BNM_CTRL_0_bnm_on_mask                                             (0x00000008)
#define  DVBC_BNM_CTRL_0_bnm_window_en_on_mask                                   (0x00000007)
#define  DVBC_BNM_CTRL_0_bnm_cnt_rst(data)                                       (0x00000040&((data)<<6))
#define  DVBC_BNM_CTRL_0_bnm_mu(data)                                            (0x00000030&((data)<<4))
#define  DVBC_BNM_CTRL_0_bnm_on(data)                                            (0x00000008&((data)<<3))
#define  DVBC_BNM_CTRL_0_bnm_window_en_on(data)                                  (0x00000007&(data))
#define  DVBC_BNM_CTRL_0_get_bnm_cnt_rst(data)                                   ((0x00000040&(data))>>6)
#define  DVBC_BNM_CTRL_0_get_bnm_mu(data)                                        ((0x00000030&(data))>>4)
#define  DVBC_BNM_CTRL_0_get_bnm_on(data)                                        ((0x00000008&(data))>>3)
#define  DVBC_BNM_CTRL_0_get_bnm_window_en_on(data)                              (0x00000007&(data))

#define  DVBC_BNM_CTRL_1                                                         0x180E8DA4
#define  DVBC_BNM_CTRL_1_reg_addr                                                "0xB80E8DA4"
#define  DVBC_BNM_CTRL_1_reg                                                     0xB80E8DA4
#define  DVBC_BNM_CTRL_1_inst_addr                                               "0x01FF"
#define  set_DVBC_BNM_CTRL_1_reg(data)                                           (*((volatile unsigned int*)DVBC_BNM_CTRL_1_reg)=data)
#define  get_DVBC_BNM_CTRL_1_reg                                                 (*((volatile unsigned int*)DVBC_BNM_CTRL_1_reg))
#define  DVBC_BNM_CTRL_1_bnm_window1_en_ratio_shift                              (0)
#define  DVBC_BNM_CTRL_1_bnm_window1_en_ratio_mask                               (0x0000001F)
#define  DVBC_BNM_CTRL_1_bnm_window1_en_ratio(data)                              (0x0000001F&(data))
#define  DVBC_BNM_CTRL_1_get_bnm_window1_en_ratio(data)                          (0x0000001F&(data))

#define  DVBC_BNM_CTRL_2                                                         0x180E8DA8
#define  DVBC_BNM_CTRL_2_reg_addr                                                "0xB80E8DA8"
#define  DVBC_BNM_CTRL_2_reg                                                     0xB80E8DA8
#define  DVBC_BNM_CTRL_2_inst_addr                                               "0x0200"
#define  set_DVBC_BNM_CTRL_2_reg(data)                                           (*((volatile unsigned int*)DVBC_BNM_CTRL_2_reg)=data)
#define  get_DVBC_BNM_CTRL_2_reg                                                 (*((volatile unsigned int*)DVBC_BNM_CTRL_2_reg))
#define  DVBC_BNM_CTRL_2_bnm_window1_en_num_shift                                (0)
#define  DVBC_BNM_CTRL_2_bnm_window1_en_num_mask                                 (0x000000FF)
#define  DVBC_BNM_CTRL_2_bnm_window1_en_num(data)                                (0x000000FF&(data))
#define  DVBC_BNM_CTRL_2_get_bnm_window1_en_num(data)                            (0x000000FF&(data))

#define  DVBC_BNM_CTRL_3                                                         0x180E8DAC
#define  DVBC_BNM_CTRL_3_reg_addr                                                "0xB80E8DAC"
#define  DVBC_BNM_CTRL_3_reg                                                     0xB80E8DAC
#define  DVBC_BNM_CTRL_3_inst_addr                                               "0x0201"
#define  set_DVBC_BNM_CTRL_3_reg(data)                                           (*((volatile unsigned int*)DVBC_BNM_CTRL_3_reg)=data)
#define  get_DVBC_BNM_CTRL_3_reg                                                 (*((volatile unsigned int*)DVBC_BNM_CTRL_3_reg))
#define  DVBC_BNM_CTRL_3_bnm_window2_en_ratio_shift                              (0)
#define  DVBC_BNM_CTRL_3_bnm_window2_en_ratio_mask                               (0x0000001F)
#define  DVBC_BNM_CTRL_3_bnm_window2_en_ratio(data)                              (0x0000001F&(data))
#define  DVBC_BNM_CTRL_3_get_bnm_window2_en_ratio(data)                          (0x0000001F&(data))

#define  DVBC_BNM_CTRL_4                                                         0x180E8DB0
#define  DVBC_BNM_CTRL_4_reg_addr                                                "0xB80E8DB0"
#define  DVBC_BNM_CTRL_4_reg                                                     0xB80E8DB0
#define  DVBC_BNM_CTRL_4_inst_addr                                               "0x0202"
#define  set_DVBC_BNM_CTRL_4_reg(data)                                           (*((volatile unsigned int*)DVBC_BNM_CTRL_4_reg)=data)
#define  get_DVBC_BNM_CTRL_4_reg                                                 (*((volatile unsigned int*)DVBC_BNM_CTRL_4_reg))
#define  DVBC_BNM_CTRL_4_bnm_window2_en_num_shift                                (0)
#define  DVBC_BNM_CTRL_4_bnm_window2_en_num_mask                                 (0x0000003F)
#define  DVBC_BNM_CTRL_4_bnm_window2_en_num(data)                                (0x0000003F&(data))
#define  DVBC_BNM_CTRL_4_get_bnm_window2_en_num(data)                            (0x0000003F&(data))

#define  DVBC_BNM_CTRL_5                                                         0x180E8DB4
#define  DVBC_BNM_CTRL_5_reg_addr                                                "0xB80E8DB4"
#define  DVBC_BNM_CTRL_5_reg                                                     0xB80E8DB4
#define  DVBC_BNM_CTRL_5_inst_addr                                               "0x0203"
#define  set_DVBC_BNM_CTRL_5_reg(data)                                           (*((volatile unsigned int*)DVBC_BNM_CTRL_5_reg)=data)
#define  get_DVBC_BNM_CTRL_5_reg                                                 (*((volatile unsigned int*)DVBC_BNM_CTRL_5_reg))
#define  DVBC_BNM_CTRL_5_bnm_window3_en_ratio_shift                              (0)
#define  DVBC_BNM_CTRL_5_bnm_window3_en_ratio_mask                               (0x0000001F)
#define  DVBC_BNM_CTRL_5_bnm_window3_en_ratio(data)                              (0x0000001F&(data))
#define  DVBC_BNM_CTRL_5_get_bnm_window3_en_ratio(data)                          (0x0000001F&(data))

#define  DVBC_BNM_CTRL_6                                                         0x180E8DB8
#define  DVBC_BNM_CTRL_6_reg_addr                                                "0xB80E8DB8"
#define  DVBC_BNM_CTRL_6_reg                                                     0xB80E8DB8
#define  DVBC_BNM_CTRL_6_inst_addr                                               "0x0204"
#define  set_DVBC_BNM_CTRL_6_reg(data)                                           (*((volatile unsigned int*)DVBC_BNM_CTRL_6_reg)=data)
#define  get_DVBC_BNM_CTRL_6_reg                                                 (*((volatile unsigned int*)DVBC_BNM_CTRL_6_reg))
#define  DVBC_BNM_CTRL_6_bnm_null_en_ratio_shift                                 (0)
#define  DVBC_BNM_CTRL_6_bnm_null_en_ratio_mask                                  (0x0000001F)
#define  DVBC_BNM_CTRL_6_bnm_null_en_ratio(data)                                 (0x0000001F&(data))
#define  DVBC_BNM_CTRL_6_get_bnm_null_en_ratio(data)                             (0x0000001F&(data))

#define  DVBC_BNM_DETECT_CNT                                                     0x180E8DBC
#define  DVBC_BNM_DETECT_CNT_reg_addr                                            "0xB80E8DBC"
#define  DVBC_BNM_DETECT_CNT_reg                                                 0xB80E8DBC
#define  DVBC_BNM_DETECT_CNT_inst_addr                                           "0x0205"
#define  set_DVBC_BNM_DETECT_CNT_reg(data)                                       (*((volatile unsigned int*)DVBC_BNM_DETECT_CNT_reg)=data)
#define  get_DVBC_BNM_DETECT_CNT_reg                                             (*((volatile unsigned int*)DVBC_BNM_DETECT_CNT_reg))
#define  DVBC_BNM_DETECT_CNT_bnm_detect_cnt_shift                                (0)
#define  DVBC_BNM_DETECT_CNT_bnm_detect_cnt_mask                                 (0xFFFFFFFF)
#define  DVBC_BNM_DETECT_CNT_bnm_detect_cnt(data)                                (0xFFFFFFFF&(data))
#define  DVBC_BNM_DETECT_CNT_get_bnm_detect_cnt(data)                            (0xFFFFFFFF&(data))

#define  DVBC_BNM_CLIP_CNT                                                       0x180E8DC0
#define  DVBC_BNM_CLIP_CNT_reg_addr                                              "0xB80E8DC0"
#define  DVBC_BNM_CLIP_CNT_reg                                                   0xB80E8DC0
#define  DVBC_BNM_CLIP_CNT_inst_addr                                             "0x0206"
#define  set_DVBC_BNM_CLIP_CNT_reg(data)                                         (*((volatile unsigned int*)DVBC_BNM_CLIP_CNT_reg)=data)
#define  get_DVBC_BNM_CLIP_CNT_reg                                               (*((volatile unsigned int*)DVBC_BNM_CLIP_CNT_reg))
#define  DVBC_BNM_CLIP_CNT_bnm_clip_cnt_shift                                    (0)
#define  DVBC_BNM_CLIP_CNT_bnm_clip_cnt_mask                                     (0xFFFFFFFF)
#define  DVBC_BNM_CLIP_CNT_bnm_clip_cnt(data)                                    (0xFFFFFFFF&(data))
#define  DVBC_BNM_CLIP_CNT_get_bnm_clip_cnt(data)                                (0xFFFFFFFF&(data))

#define  DVBC_PRD_EN                                                             0x180E8DD0
#define  DVBC_PRD_EN_reg_addr                                                    "0xB80E8DD0"
#define  DVBC_PRD_EN_reg                                                         0xB80E8DD0
#define  DVBC_PRD_EN_inst_addr                                                   "0x0207"
#define  set_DVBC_PRD_EN_reg(data)                                               (*((volatile unsigned int*)DVBC_PRD_EN_reg)=data)
#define  get_DVBC_PRD_EN_reg                                                     (*((volatile unsigned int*)DVBC_PRD_EN_reg))
#define  DVBC_PRD_EN_opt_prd_pha_sel_thd_shift                                   (4)
#define  DVBC_PRD_EN_opt_start_prd_shift                                         (0)
#define  DVBC_PRD_EN_opt_prd_pha_sel_thd_mask                                    (0x000001F0)
#define  DVBC_PRD_EN_opt_start_prd_mask                                          (0x00000001)
#define  DVBC_PRD_EN_opt_prd_pha_sel_thd(data)                                   (0x000001F0&((data)<<4))
#define  DVBC_PRD_EN_opt_start_prd(data)                                         (0x00000001&(data))
#define  DVBC_PRD_EN_get_opt_prd_pha_sel_thd(data)                               ((0x000001F0&(data))>>4)
#define  DVBC_PRD_EN_get_opt_start_prd(data)                                     (0x00000001&(data))

#define  DVBC_PRD_THD                                                            0x180E8DD4
#define  DVBC_PRD_THD_reg_addr                                                   "0xB80E8DD4"
#define  DVBC_PRD_THD_reg                                                        0xB80E8DD4
#define  DVBC_PRD_THD_inst_addr                                                  "0x0208"
#define  set_DVBC_PRD_THD_reg(data)                                              (*((volatile unsigned int*)DVBC_PRD_THD_reg)=data)
#define  get_DVBC_PRD_THD_reg                                                    (*((volatile unsigned int*)DVBC_PRD_THD_reg))
#define  DVBC_PRD_THD_opt_prd_thd_l_shift                                        (16)
#define  DVBC_PRD_THD_opt_prd_thd_h_shift                                        (0)
#define  DVBC_PRD_THD_opt_prd_thd_l_mask                                         (0x7FFF0000)
#define  DVBC_PRD_THD_opt_prd_thd_h_mask                                         (0x00007FFF)
#define  DVBC_PRD_THD_opt_prd_thd_l(data)                                        (0x7FFF0000&((data)<<16))
#define  DVBC_PRD_THD_opt_prd_thd_h(data)                                        (0x00007FFF&(data))
#define  DVBC_PRD_THD_get_opt_prd_thd_l(data)                                    ((0x7FFF0000&(data))>>16)
#define  DVBC_PRD_THD_get_opt_prd_thd_h(data)                                    (0x00007FFF&(data))

#define  DVBC_PRD_THD_1_2                                                        0x180E8DD8
#define  DVBC_PRD_THD_1_2_reg_addr                                               "0xB80E8DD8"
#define  DVBC_PRD_THD_1_2_reg                                                    0xB80E8DD8
#define  DVBC_PRD_THD_1_2_inst_addr                                              "0x0209"
#define  set_DVBC_PRD_THD_1_2_reg(data)                                          (*((volatile unsigned int*)DVBC_PRD_THD_1_2_reg)=data)
#define  get_DVBC_PRD_THD_1_2_reg                                                (*((volatile unsigned int*)DVBC_PRD_THD_1_2_reg))
#define  DVBC_PRD_THD_1_2_opt_prd_level2_shift                                   (16)
#define  DVBC_PRD_THD_1_2_opt_prd_level1_shift                                   (0)
#define  DVBC_PRD_THD_1_2_opt_prd_level2_mask                                    (0x7FFF0000)
#define  DVBC_PRD_THD_1_2_opt_prd_level1_mask                                    (0x00007FFF)
#define  DVBC_PRD_THD_1_2_opt_prd_level2(data)                                   (0x7FFF0000&((data)<<16))
#define  DVBC_PRD_THD_1_2_opt_prd_level1(data)                                   (0x00007FFF&(data))
#define  DVBC_PRD_THD_1_2_get_opt_prd_level2(data)                               ((0x7FFF0000&(data))>>16)
#define  DVBC_PRD_THD_1_2_get_opt_prd_level1(data)                               (0x00007FFF&(data))

#define  DVBC_PRD_THD_3_4                                                        0x180E8DDC
#define  DVBC_PRD_THD_3_4_reg_addr                                               "0xB80E8DDC"
#define  DVBC_PRD_THD_3_4_reg                                                    0xB80E8DDC
#define  DVBC_PRD_THD_3_4_inst_addr                                              "0x020A"
#define  set_DVBC_PRD_THD_3_4_reg(data)                                          (*((volatile unsigned int*)DVBC_PRD_THD_3_4_reg)=data)
#define  get_DVBC_PRD_THD_3_4_reg                                                (*((volatile unsigned int*)DVBC_PRD_THD_3_4_reg))
#define  DVBC_PRD_THD_3_4_opt_prd_level4_shift                                   (16)
#define  DVBC_PRD_THD_3_4_opt_prd_level3_shift                                   (0)
#define  DVBC_PRD_THD_3_4_opt_prd_level4_mask                                    (0x7FFF0000)
#define  DVBC_PRD_THD_3_4_opt_prd_level3_mask                                    (0x00007FFF)
#define  DVBC_PRD_THD_3_4_opt_prd_level4(data)                                   (0x7FFF0000&((data)<<16))
#define  DVBC_PRD_THD_3_4_opt_prd_level3(data)                                   (0x00007FFF&(data))
#define  DVBC_PRD_THD_3_4_get_opt_prd_level4(data)                               ((0x7FFF0000&(data))>>16)
#define  DVBC_PRD_THD_3_4_get_opt_prd_level3(data)                               (0x00007FFF&(data))

#define  DVBC_PRD_THD_5                                                          0x180E8DE0
#define  DVBC_PRD_THD_5_reg_addr                                                 "0xB80E8DE0"
#define  DVBC_PRD_THD_5_reg                                                      0xB80E8DE0
#define  DVBC_PRD_THD_5_inst_addr                                                "0x020B"
#define  set_DVBC_PRD_THD_5_reg(data)                                            (*((volatile unsigned int*)DVBC_PRD_THD_5_reg)=data)
#define  get_DVBC_PRD_THD_5_reg                                                  (*((volatile unsigned int*)DVBC_PRD_THD_5_reg))
#define  DVBC_PRD_THD_5_opt_prd_level5_shift                                     (0)
#define  DVBC_PRD_THD_5_opt_prd_level5_mask                                      (0x00007FFF)
#define  DVBC_PRD_THD_5_opt_prd_level5(data)                                     (0x00007FFF&(data))
#define  DVBC_PRD_THD_5_get_opt_prd_level5(data)                                 (0x00007FFF&(data))

#define  DVBC_PRD_COMP_IDX_THD                                                   0x180E8DE4
#define  DVBC_PRD_COMP_IDX_THD_reg_addr                                          "0xB80E8DE4"
#define  DVBC_PRD_COMP_IDX_THD_reg                                               0xB80E8DE4
#define  DVBC_PRD_COMP_IDX_THD_inst_addr                                         "0x020C"
#define  set_DVBC_PRD_COMP_IDX_THD_reg(data)                                     (*((volatile unsigned int*)DVBC_PRD_COMP_IDX_THD_reg)=data)
#define  get_DVBC_PRD_COMP_IDX_THD_reg                                           (*((volatile unsigned int*)DVBC_PRD_COMP_IDX_THD_reg))
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx4_shift                           (24)
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx3_shift                           (16)
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx2_shift                           (8)
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx1_shift                           (0)
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx4_mask                            (0xFF000000)
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx3_mask                            (0x00FF0000)
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx2_mask                            (0x0000FF00)
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx1_mask                            (0x000000FF)
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx4(data)                           (0xFF000000&((data)<<24))
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx3(data)                           (0x00FF0000&((data)<<16))
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx2(data)                           (0x0000FF00&((data)<<8))
#define  DVBC_PRD_COMP_IDX_THD_opt_prd_comp_idx1(data)                           (0x000000FF&(data))
#define  DVBC_PRD_COMP_IDX_THD_get_opt_prd_comp_idx4(data)                       ((0xFF000000&(data))>>24)
#define  DVBC_PRD_COMP_IDX_THD_get_opt_prd_comp_idx3(data)                       ((0x00FF0000&(data))>>16)
#define  DVBC_PRD_COMP_IDX_THD_get_opt_prd_comp_idx2(data)                       ((0x0000FF00&(data))>>8)
#define  DVBC_PRD_COMP_IDX_THD_get_opt_prd_comp_idx1(data)                       (0x000000FF&(data))

#define  DVBC_PRD_ERR                                                            0x180E8DE8
#define  DVBC_PRD_ERR_reg_addr                                                   "0xB80E8DE8"
#define  DVBC_PRD_ERR_reg                                                        0xB80E8DE8
#define  DVBC_PRD_ERR_inst_addr                                                  "0x020D"
#define  set_DVBC_PRD_ERR_reg(data)                                              (*((volatile unsigned int*)DVBC_PRD_ERR_reg)=data)
#define  get_DVBC_PRD_ERR_reg                                                    (*((volatile unsigned int*)DVBC_PRD_ERR_reg))
#define  DVBC_PRD_ERR_opt_prd_err_alpha_shift                                    (24)
#define  DVBC_PRD_ERR_opt_prd_err_term_h_shift                                   (12)
#define  DVBC_PRD_ERR_opt_prd_err_term_l_shift                                   (0)
#define  DVBC_PRD_ERR_opt_prd_err_alpha_mask                                     (0x07000000)
#define  DVBC_PRD_ERR_opt_prd_err_term_h_mask                                    (0x00FFF000)
#define  DVBC_PRD_ERR_opt_prd_err_term_l_mask                                    (0x00000FFF)
#define  DVBC_PRD_ERR_opt_prd_err_alpha(data)                                    (0x07000000&((data)<<24))
#define  DVBC_PRD_ERR_opt_prd_err_term_h(data)                                   (0x00FFF000&((data)<<12))
#define  DVBC_PRD_ERR_opt_prd_err_term_l(data)                                   (0x00000FFF&(data))
#define  DVBC_PRD_ERR_get_opt_prd_err_alpha(data)                                ((0x07000000&(data))>>24)
#define  DVBC_PRD_ERR_get_opt_prd_err_term_h(data)                               ((0x00FFF000&(data))>>12)
#define  DVBC_PRD_ERR_get_opt_prd_err_term_l(data)                               (0x00000FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DVBC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chip_version:8;
    };
}dvbc_chip_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_adcdata_q_qam:2;
        RBus_UInt32  opt_tst_in_sel:2;
        RBus_UInt32  opt_qam_outer_data:1;
        RBus_UInt32  opt_adcclk_qam:1;
        RBus_UInt32  opt_adcdata_i_qam:2;
    };
}dvbc_opt_adcdata_i_qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_qam_std:1;
    };
}dvbc_opt_qam_std_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_qam_on:1;
    };
}dvbc_opt_qam_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_soft_reset_qam:1;
    };
}dvbc_opt_soft_reset_qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_if_aagc_oe:1;
        RBus_UInt32  opt_par_if_sd_ib:1;
        RBus_UInt32  opt_if_aagc_drive:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  opt_rf_aagc_oe:1;
        RBus_UInt32  opt_par_rf_sd_ib:1;
        RBus_UInt32  opt_rf_aagc_drive:1;
        RBus_UInt32  res3:1;
    };
}dvbc_opt_rf_aagc_drive_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  opt_rf_aagc_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  opt_if_aagc_sel:3;
    };
}dvbc_opt_if_aagc_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  opt_ro_debug_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  opt_debug_sel:3;
    };
}dvbc_opt_debug_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_debug_oe_7_0:8;
    };
}dvbc_opt_debug_oe_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_debug_oe_15_8:8;
    };
}dvbc_opt_debug_oe_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_debug_oe_23_16:8;
    };
}dvbc_opt_debug_oe_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_debug_oe_31_24:8;
    };
}dvbc_opt_debug_oe_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  debug_reg_7_0:8;
    };
}dvbc_debug_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  debug_reg_15_8:8;
    };
}dvbc_debug_reg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  debug_reg_23_16:8;
    };
}dvbc_debug_reg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  debug_reg_31_24:8;
    };
}dvbc_debug_reg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_debug_pu_7_0:8;
    };
}dvbc_qam_debug_pu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_debug_pu_15_8:8;
    };
}dvbc_qam_debug_pu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_debug_pu_23_16:8;
    };
}dvbc_qam_debug_pu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_debug_pu_31_24:8;
    };
}dvbc_qam_debug_pu_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_debug_pd_7_0:8;
    };
}dvbc_qam_debug_pd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_debug_pd_15_8:8;
    };
}dvbc_qam_debug_pd_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_debug_pd_23_16:8;
    };
}dvbc_qam_debug_pd_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_debug_pd_31_24:8;
    };
}dvbc_qam_debug_pd_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_adc_out_sel:1;
    };
}dvbc_opt_adc_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_par_tstclk:1;
        RBus_UInt32  opt_tst_out_tri2:3;
        RBus_UInt32  opt_tst_out_tri1:3;
        RBus_UInt32  opt_tst_out_sel:1;
    };
}dvbc_opt_tst_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_mpeg_out_sel:2;
    };
}dvbc_opt_mpeg_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ro_reg_on:1;
        RBus_UInt32  opt_page0_ro_stb:1;
    };
}dvbc_opt_page0_ro_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_8051_int0_en:1;
    };
}dvbc_opt_8051_int0_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ro_if_agc_oe_ro:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ro_if_agc_ro:1;
        RBus_UInt32  ro_rf_agc_oe_ro:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ro_rf_agc_ro:1;
    };
}dvbc_ro_agc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rssi_agc_q_ro_7_0:8;
    };
}dvbc_rssi_agc_q_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  rssi_agc_q_ro_13_8:6;
    };
}dvbc_rssi_agc_q_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  rssi_agc_loop_sat_ro:1;
    };
}dvbc_rssi_agc_loop_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ad7_out_ro:7;
    };
}dvbc_ad7_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_mpeg_out_ro_7_0:8;
    };
}dvbc_qam_mpeg_out_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  qam_mpeg_out_ro_11_8:4;
    };
}dvbc_qam_mpeg_out_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ro_debug_ro_7_0:8;
    };
}dvbc_qam_debug_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ro_debug_ro_15_8:8;
    };
}dvbc_qam_debug_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ro_debug_ro_23_16:8;
    };
}dvbc_qam_debug_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ro_debug_ro_31_24:8;
    };
}dvbc_qam_debug_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_rw40_reserved:8;
    };
}dvbc_page0_rw40_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_rw41_reserved:8;
    };
}dvbc_page0_rw41_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_rw42_reserved:8;
    };
}dvbc_page0_rw42_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_rw43_reserved:8;
    };
}dvbc_page0_rw43_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_rw44_reserved:8;
    };
}dvbc_page0_rw44_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_rw45_reserved:8;
    };
}dvbc_page0_rw45_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_rw46_reserved:8;
    };
}dvbc_page0_rw46_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_rw47_reserved:8;
    };
}dvbc_page0_rw47_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_ro48_reserved:8;
    };
}dvbc_page0_rw48_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_ro49_reserved:8;
    };
}dvbc_page0_rw49_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_ro4a_reserved:8;
    };
}dvbc_page0_rw4a_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page0_ro4b_reserved:8;
    };
}dvbc_page0_rw4b_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_soft_reset_rssi_agc:1;
    };
}dvbc_opt_soft_reset_rssi_agc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  u_rssi_agc_exp:3;
        RBus_UInt32  rssi_in_ph_sel:1;
        RBus_UInt32  opt_rssi_agc_on:1;
    };
}dvbc_opt_rssi_agc_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rssi_in_clk_ratio:8;
    };
}dvbc_rssi_in_clk_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rssi_agc_max:8;
    };
}dvbc_rssi_agc_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rssi_agc_min:8;
    };
}dvbc_rssi_agc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rssi_agc_pol:1;
        RBus_UInt32  rssi_agc_targ_val:7;
    };
}dvbc_rssi_agc_targ_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  rssi_in_ph_sel2:1;
        RBus_UInt32  opt_ad7_ckout_inv:1;
    };
}dvbc_opt_ad7_ckout_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_hold_pga:1;
        RBus_UInt32  reg_pset_aagc:1;
        RBus_UInt32  reg_aagc_cal_payload:1;
        RBus_UInt32  reg_aagc_hold:1;
        RBus_UInt32  reg_en_gi_pga:1;
        RBus_UInt32  reg_en_pga_mode:1;
        RBus_UInt32  reg_en_dcr:1;
        RBus_UInt32  reg_adc_clk_xor:1;
    };
}dvbc_reg_adc_clk_xor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_target_val:8;
    };
}dvbc_reg_target_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_aagc_loopgain1_2_0:3;
        RBus_UInt32  reg_aagc_loopgain0:5;
    };
}dvbc_reg_aagc_loopgain0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  reg_aagc_loopgain2:5;
        RBus_UInt32  reg_aagc_loopgain1_4_3:2;
    };
}dvbc_reg_aagc_loopgain0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_aagc_lock_det_thd:4;
        RBus_UInt32  reg_aagc_lock_det_len:4;
    };
}dvbc_reg_aagc_lock_det_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_pset_aagc_val:8;
    };
}dvbc_reg_pset_aagc_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_aagc_latency_7_0:8;
    };
}dvbc_reg_aagc_latency_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  reg_aagc_latency_12_8:5;
    };
}dvbc_reg_aagc_latency_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_aagc_lock_pga_hit_len:3;
        RBus_UInt32  reg_integral_cnt_len:5;
    };
}dvbc_reg_integral_cnt_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_thd_lock_up_7_0:8;
    };
}dvbc_reg_thd_lock_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_thd_lock_dw_5_0:6;
        RBus_UInt32  reg_thd_lock_up_9_8:2;
    };
}dvbc_reg_thd_lock_up_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  reg_thd_lock_dw_9_6:4;
    };
}dvbc_reg_thd_lock_up_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_thd_up1_7_0:8;
    };
}dvbc_reg_thd_up1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_thd_dw1_5_0:6;
        RBus_UInt32  reg_thd_up1_9_8:2;
    };
}dvbc_reg_thd_up1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  reg_thd_dw1_9_6:4;
    };
}dvbc_reg_thd_up1_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_thd_up2:8;
    };
}dvbc_reg_thd_up2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_thd_dw2:8;
    };
}dvbc_reg_thd_dw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_gain_step_sum_dw_thd:4;
        RBus_UInt32  reg_gain_step_sum_up_thd:4;
    };
}dvbc_reg_gain_step_sum_up_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_gain_pulse_hold_len:4;
        RBus_UInt32  reg_gain_pulse_space_len:4;
    };
}dvbc_reg_gain_pulse_space_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qam_in_version:8;
    };
}dvbc_qam_in_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_adc_samp_ph:3;
        RBus_UInt32  opt_qam_mode:3;
    };
}dvbc_opt_qam_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  opt_adc_format_sel:1;
        RBus_UInt32  opt_adc_trunc_bits:2;
    };
}dvbc_opt_adc_trunc_bits_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_aagc_s_k_rf_lsb:2;
        RBus_UInt32  opt_aagc_fz:2;
        RBus_UInt32  opt_if_aagc_pol:1;
        RBus_UInt32  opt_rf_aagc_pol:1;
        RBus_UInt32  opt_aagc_loop_pol:1;
        RBus_UInt32  opt_adc_nb_on:1;
    };
}dvbc_opt_adc_nb_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_aagc_target_amp:8;
    };
}dvbc_opt_aagc_target_amp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rf_aagc_max:8;
    };
}dvbc_opt_rf_aagc_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rf_aagc_min:8;
    };
}dvbc_opt_rf_aagc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_if_aagc_max:8;
    };
}dvbc_opt_if_aagc_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_if_aagc_min:8;
    };
}dvbc_opt_if_aagc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_aagc_init_level:8;
    };
}dvbc_opt_aagc_init_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_aagc_s_if_th:8;
    };
}dvbc_opt_aagc_s_if_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_aagc_p_s_sel:1;
        RBus_UInt32  opt_aagc_s_k_rf_msb:4;
        RBus_UInt32  opt_aagc_lock_th:3;
    };
}dvbc_opt_aagc_lock_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_ddc_freq_7_0:8;
    };
}dvbc_opt_ddc_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_spec_inv:1;
        RBus_UInt32  opt_ddc_freq_14_8:7;
    };
}dvbc_opt_ddc_freq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  specmode:1;
        RBus_UInt32  opt_auto_spec:1;
        RBus_UInt32  opt_set_spec:1;
        RBus_UInt32  opt_ddc_lpf_scaling:3;
    };
}dvbc_opt_ddc_lpf_scaling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  notch_sel:4;
        RBus_UInt32  notch_wr_stb:1;
        RBus_UInt32  opt_notch3_on:1;
        RBus_UInt32  opt_notch2_on:1;
        RBus_UInt32  opt_notch1_on:1;
    };
}dvbc_opt_notch1_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  notch_coeff_7_0:8;
    };
}dvbc_notch_coeff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  notch_coeff_r:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  notch_coeff_10_8:3;
    };
}dvbc_notch_coeff_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_dagc_min:4;
        RBus_UInt32  opt_dagc_max:4;
    };
}dvbc_opt_dagc_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_initial_cr_freq_7_0:8;
    };
}dvbc_opt_initial_cr_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_initial_cr_freq_12_8:5;
    };
}dvbc_opt_initial_cr_freq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_ki_cr_out_max:8;
    };
}dvbc_opt_ki_cr_out_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_cr_acq_pwr_th:8;
    };
}dvbc_opt_cr_acq_pwr_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_bn_cr_bw_half_en:1;
        RBus_UInt32  opt_bn_cr_blank_en:1;
        RBus_UInt32  opt_cr_metric_dd_sat_ctrl:1;
        RBus_UInt32  opt_cr_metric_dd_max:5;
    };
}dvbc_opt_cr_metric_dd_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_bn_cond_and_or:1;
        RBus_UInt32  bn_cond5_en:1;
        RBus_UInt32  bn_cond4_en:1;
        RBus_UInt32  bn_cond3_en:1;
        RBus_UInt32  bn_cond2_en:1;
        RBus_UInt32  bn_cond1_en:1;
        RBus_UInt32  opt_bn_cr_blank_c2:1;
        RBus_UInt32  opt_bn_eq_stop_en:1;
    };
}dvbc_opt_bn_eq_stop_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_bn_ek_amp_th:4;
        RBus_UInt32  opt_bn_mse_th:4;
    };
}dvbc_opt_bn_mse_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_bn_cond2_cnt_th:3;
        RBus_UInt32  opt_bn_cond1_cnt_th:3;
    };
}dvbc_opt_bn_cond1_cnt_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_ak_pow_in_cr_sel:2;
        RBus_UInt32  opt_bn_err_acc_th:6;
    };
}dvbc_opt_bn_err_acc_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_tr_ld_gard_on:1;
        RBus_UInt32  opt_ak_pow_in:1;
        RBus_UInt32  opt_ak_dd_cr_pow_th:6;
    };
}dvbc_opt_ak_dd_cr_pow_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_tr_deci_ratio_7_0:8;
    };
}dvbc_opt_tr_deci_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_tr_deci_ratio_15_8:8;
    };
}dvbc_opt_tr_deci_ratio_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_tr_deci_ratio_23_16:8;
    };
}dvbc_opt_tr_deci_ratio_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_ki_tr_out_max:8;
    };
}dvbc_opt_ki_tr_out_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_preeq_tr_phase_inv:1;
        RBus_UInt32  opt_interl_tr_on:1;
        RBus_UInt32  opt_tr_metric_dd_sat_ctrl:1;
        RBus_UInt32  opt_posteq_tr_mm_max_dd:5;
    };
}dvbc_opt_posteq_tr_mm_max_dd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mk_uk_min:5;
        RBus_UInt32  opt_preeq_tr_guard_on:1;
        RBus_UInt32  opt_posteq_tr_acq_sel:1;
        RBus_UInt32  opt_posteq_tr_sel:1;
    };
}dvbc_opt_posteq_tr_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mse_th_cond4_7_0:8;
    };
}dvbc_opt_mse_th_cond4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  opt_tr_ld_out_th:5;
        RBus_UInt32  opt_mse_th_cond4_9_8:2;
    };
}dvbc_opt_mse_th_cond4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mse_th_cond5_7_0:8;
    };
}dvbc_opt_mse_th_cond5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_fsm_final_state:4;
        RBus_UInt32  opt_mse_th_cond5_9_8:2;
    };
}dvbc_opt_mse_th_cond5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mse_th_cond6_7_0:8;
    };
}dvbc_opt_mse_th_cond6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  opt_fsm_cond7_sel:1;
        RBus_UInt32  opt_cr_cnt:4;
        RBus_UInt32  opt_mse_th_cond6_9_8:2;
    };
}dvbc_opt_mse_th_cond6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rt_cond_and_or:1;
        RBus_UInt32  rt_cond5_en:1;
        RBus_UInt32  rt_cond4_en:1;
        RBus_UInt32  rt_cond3_en:1;
        RBus_UInt32  rt_cond2_en:1;
        RBus_UInt32  rt_cond1_en:1;
        RBus_UInt32  opt_retry_on:1;
        RBus_UInt32  opt_rst_state0_on:1;
    };
}dvbc_opt_rst_state0_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rt_loop_cnt_min:8;
    };
}dvbc_opt_rt_loop_cnt_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rt_cond7_en:1;
        RBus_UInt32  rt_cond6_en:1;
        RBus_UInt32  opt_rt_mse_th:6;
    };
}dvbc_opt_rt_mse_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_u_iq_exp:2;
        RBus_UInt32  opt_dd_eq_bound:6;
    };
}dvbc_opt_dd_eq_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rca_lvl_sqrt_2_0:3;
        RBus_UInt32  opt_sign_data_exp_fbf:2;
        RBus_UInt32  opt_sign_data_exp_fff:2;
        RBus_UInt32  opt_sign_data:1;
    };
}dvbc_opt_sign_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rca_lvl_sqrt_10_3:8;
    };
}dvbc_opt_sign_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_circle:6;
    };
}dvbc_opt_circle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_leakage_f_u_en_acq:1;
        RBus_UInt32  opt_leakage_f_u_en_dd:1;
        RBus_UInt32  opt_leakage_size_exp:3;
        RBus_UInt32  res2:3;
    };
}dvbc_opt_leakage_size_exp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_leakage_f_amp_en:1;
        RBus_UInt32  opt_leakage_period:7;
    };
}dvbc_opt_leakage_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mse_amp_thr1:8;
    };
}dvbc_opt_mse_amp_thr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mse_amp_thr2:8;
    };
}dvbc_opt_mse_amp_thr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_leakage_f_amp_exp:2;
        RBus_UInt32  opt_leakage_f_amp_exp_en:1;
        RBus_UInt32  opt_max_amp0:5;
    };
}dvbc_opt_max_amp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_max_amp1:5;
    };
}dvbc_opt_max_amp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_max_amp2:5;
    };
}dvbc_opt_max_amp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mse_th_eq_acq1:8;
    };
}dvbc_opt_mse_th_eq_acq1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mse_th_eq_acq2:8;
    };
}dvbc_opt_mse_th_eq_acq2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff_acq1:3;
        RBus_UInt32  opt_u_fff_acq0:3;
    };
}dvbc_opt_u_fff_acq0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  opt_u_fbf_acq1:2;
        RBus_UInt32  opt_u_fbf_acq0:2;
        RBus_UInt32  opt_u_fff_acq2:3;
    };
}dvbc_opt_u_fff_acq2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_u_fbf2_acq2:2;
        RBus_UInt32  opt_u_fbf2_acq1:2;
        RBus_UInt32  opt_u_fbf2_acq0:2;
        RBus_UInt32  opt_u_fbf_acq2:2;
    };
}dvbc_opt_u_fbf_acq2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mse_th_eq_dd1:8;
    };
}dvbc_opt_mse_th_eq_dd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_mse_th_eq_dd2:8;
    };
}dvbc_opt_mse_th_eq_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff_dd1:3;
        RBus_UInt32  opt_u_fff_dd0:3;
    };
}dvbc_opt_u_fff_dd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  opt_u_fbf_dd1:2;
        RBus_UInt32  opt_u_fbf_dd0:2;
        RBus_UInt32  opt_u_fff_dd2:3;
    };
}dvbc_opt_u_fff_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_u_fbf2_dd2:2;
        RBus_UInt32  opt_u_fbf2_dd1:2;
        RBus_UInt32  opt_u_fbf2_dd0:2;
        RBus_UInt32  opt_u_fbf_dd2:2;
    };
}dvbc_opt_u_fbf_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_eq_upd_period_fff_en:1;
        RBus_UInt32  opt_eq_upd_period_fff:7;
    };
}dvbc_opt_eq_upd_period_fff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_eq_upd_period_fbf_en:1;
        RBus_UInt32  opt_eq_upd_period_fbf:7;
    };
}dvbc_opt_eq_upd_period_fbf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_max_err_period:8;
    };
}dvbc_opt_max_err_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_clip_mo_period:8;
    };
}dvbc_opt_clip_mo_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_signal_sel1:8;
    };
}dvbc_opt_db_signal_sel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_signal_sel2:8;
    };
}dvbc_opt_db_signal_sel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  opt_db_tst_ena_sel:3;
    };
}dvbc_opt_db_tst_ena_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_signal_gate_sel1_7_0:8;
    };
}dvbc_opt_db_signal_gate_sel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_db_signal_gate_sel1_8:1;
    };
}dvbc_opt_db_signal_gate_sel1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_signal_gate_sel2_7_0:8;
    };
}dvbc_opt_db_signal_gate_sel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_db_signal_gate_sel2_8:1;
    };
}dvbc_opt_db_signal_gate_sel2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_db_fsm_state1:4;
    };
}dvbc_opt_db_fsm_state1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_cr_ld_th1:4;
        RBus_UInt32  opt_db_tr_ld_th1:4;
    };
}dvbc_opt_db_tr_ld_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_mse_th1:8;
    };
}dvbc_opt_db_mse_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_cond_and_or1:1;
        RBus_UInt32  db_cond7_en1:1;
        RBus_UInt32  db_cond6_en1:1;
        RBus_UInt32  db_cond5_en1:1;
        RBus_UInt32  db_cond4_en1:1;
        RBus_UInt32  db_cond3_en1:1;
        RBus_UInt32  db_cond2_en1:1;
        RBus_UInt32  db_cond1_en1:1;
    };
}dvbc_db_cond1_en1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_cr_ld_th2:4;
        RBus_UInt32  opt_db_tr_ld_th2:4;
    };
}dvbc_opt_db_tr_ld_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_mse_th2:8;
    };
}dvbc_opt_db_mse_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_db_fsm_state2:4;
    };
}dvbc_opt_db_fsm_state2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_db_cond_and_or2:1;
        RBus_UInt32  db_cond7_en2:1;
        RBus_UInt32  db_cond6_en2:1;
        RBus_UInt32  db_cond5_en2:1;
        RBus_UInt32  db_cond4_en2:1;
        RBus_UInt32  db_cond3_en2:1;
        RBus_UInt32  db_cond2_en2:1;
        RBus_UInt32  db_cond1_en2:1;
    };
}dvbc_db_cond1_en2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rxmf_coeff_2_0:3;
        RBus_UInt32  rxmf_sel:4;
        RBus_UInt32  rxmf_wr_stb:1;
    };
}dvbc_rxmf_wr_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  rxmf_coeff_r:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  rxmf_coeff_9_3:7;
    };
}dvbc_rxmf_wr_stb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  interp_coeff_1_0:2;
        RBus_UInt32  interp_sel:5;
        RBus_UInt32  interp_wr_stb:1;
    };
}dvbc_interp_wr_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  interp_coeff_r:10;
        RBus_UInt32  interp_coeff_9_2:8;
    };
}dvbc_interp_wr_stb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ddc_coeff_2_0:3;
        RBus_UInt32  ddc_sel:4;
        RBus_UInt32  ddc_wr_stb:1;
    };
}dvbc_ddc_wr_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ddc_coeff_r:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  ddc_coeff_9_3:7;
    };
}dvbc_ddc_wr_stb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  opt_fsm_fix_ste_en:1;
        RBus_UInt32  opt_fsm_fix_ste_end:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  fsm_sel:4;
        RBus_UInt32  fsm_wr_stb:1;
    };
}dvbc_fsm_wr_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_7_0:8;
        RBus_UInt32  fsm_word_7_0:8;
    };
}dvbc_fsm_word_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_15_8:8;
        RBus_UInt32  fsm_word_15_8:8;
    };
}dvbc_fsm_word_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_23_16:8;
        RBus_UInt32  fsm_word_23_16:8;
    };
}dvbc_fsm_word_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_31_24:8;
        RBus_UInt32  fsm_word_31_24:8;
    };
}dvbc_fsm_word_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_39_32:8;
        RBus_UInt32  fsm_word_39_32:8;
    };
}dvbc_fsm_word_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_47_40:8;
        RBus_UInt32  fsm_word_47_40:8;
    };
}dvbc_fsm_word_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_55_48:8;
        RBus_UInt32  fsm_word_55_48:8;
    };
}dvbc_fsm_word_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_63_56:8;
        RBus_UInt32  fsm_word_63_56:8;
    };
}dvbc_fsm_word_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_71_64:8;
        RBus_UInt32  fsm_word_71_64:8;
    };
}dvbc_fsm_word_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_79_72:8;
        RBus_UInt32  fsm_word_79_72:8;
    };
}dvbc_fsm_word_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fsm_word_r_87_80:8;
        RBus_UInt32  fsm_word_87_80:8;
    };
}dvbc_fsm_word_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  tst_out_stb:1;
    };
}dvbc_tst_out_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tst_out1_7_0:8;
    };
}dvbc_tst_out1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tst_out1_15_8:8;
    };
}dvbc_tst_out1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tst_out2_7_0:8;
    };
}dvbc_tst_out2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tst_out2_15_8:8;
    };
}dvbc_tst_out2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo1_7_0:8;
    };
}dvbc_inrx_mo1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo1_15_8:8;
    };
}dvbc_inrx_mo1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo1_23_16:8;
    };
}dvbc_inrx_mo1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo1_31_24:8;
    };
}dvbc_inrx_mo1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo2_7_0:8;
    };
}dvbc_inrx_mo2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo2_15_8:8;
    };
}dvbc_inrx_mo2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  inrx_mo2_18_16:3;
    };
}dvbc_inrx_mo2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo3_7_0:8;
    };
}dvbc_inrx_mo3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo3_15_8:8;
    };
}dvbc_inrx_mo3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo3_23_16:8;
    };
}dvbc_inrx_mo3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_mo3_31_24:8;
    };
}dvbc_inrx_mo3_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rt_fsm_state2:4;
        RBus_UInt32  opt_rt_fsm_state1:4;
    };
}dvbc_opt_rt_fsm_state1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rt_fsm_cnt_min:8;
    };
}dvbc_opt_rt_fsm_cnt_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rt_fsm_f_cnt_min:8;
    };
}dvbc_opt_rt_fsm_f_cnt_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_aagc_cnt_th:8;
    };
}dvbc_opt_aagc_cnt_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_rt_fsm_f_j_cnt_min:8;
    };
}dvbc_opt_rt_fsm_f_j_cnt_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  rt_cond8_sel:2;
        RBus_UInt32  rt_cond8_en:1;
        RBus_UInt32  opt_rst_txiq:1;
        RBus_UInt32  opt_rst_cr:1;
        RBus_UInt32  opt_rst_tr:1;
    };
}dvbc_opt_rst_tr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ld_mse_th_7_0:8;
    };
}dvbc_ld_mse_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ld_mse_th_9_8:2;
    };
}dvbc_ld_mse_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ld_cr_th:5;
    };
}dvbc_ld_cr_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ld_tr_th:5;
    };
}dvbc_ld_tr_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ld_period_th_7_0:8;
    };
}dvbc_ld_period_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ld_period_th_9_8:2;
    };
}dvbc_ld_period_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ld_max_err_th_7_0:8;
    };
}dvbc_ld_max_err_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ld_max_err_th_14_8:7;
    };
}dvbc_ld_max_err_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ld_outer_th:8;
    };
}dvbc_ld_outer_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ld_cond_en:8;
    };
}dvbc_ld_cond_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  outer_ld:1;
        RBus_UInt32  ld_cond_and:1;
    };
}dvbc_ld_cond_and_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_cr_dd_cordic_max:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  opt_cr_dd_cordic_sat:1;
        RBus_UInt32  opt_cr_metric_dd_sel:2;
    };
}dvbc_opt_cr_metric_dd_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  opt_ak_pow_on:3;
    };
}dvbc_opt_ak_pow_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_pn_det_th:4;
        RBus_UInt32  opt_pn_bn_err_ratio:4;
    };
}dvbc_opt_pn_bn_err_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_u_fff2_acq0:3;
        RBus_UInt32  opt_main_tap_sel:5;
    };
}dvbc_opt_main_tap_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff2_acq2:3;
        RBus_UInt32  opt_u_fff2_acq1:3;
    };
}dvbc_opt_u_fff2_acq1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff3_acq1:3;
        RBus_UInt32  opt_u_fff3_acq0:3;
    };
}dvbc_opt_u_fff3_acq0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff4_acq0:3;
        RBus_UInt32  opt_u_fff3_acq2:3;
    };
}dvbc_opt_u_fff3_acq2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff4_acq2:3;
        RBus_UInt32  opt_u_fff4_acq1:3;
    };
}dvbc_opt_u_fff4_acq1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fbf3_acq2:2;
        RBus_UInt32  opt_u_fbf3_acq1:2;
        RBus_UInt32  opt_u_fbf3_acq0:2;
    };
}dvbc_opt_u_fbf3_acq0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fbf4_acq2:2;
        RBus_UInt32  opt_u_fbf4_acq1:2;
        RBus_UInt32  opt_u_fbf4_acq0:2;
    };
}dvbc_opt_u_fbf4_acq0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff2_dd1:3;
        RBus_UInt32  opt_u_fff2_dd0:3;
    };
}dvbc_opt_u_fff2_dd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff3_dd0:3;
        RBus_UInt32  opt_u_fff2_dd2:3;
    };
}dvbc_opt_u_fff2_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff3_dd2:3;
        RBus_UInt32  opt_u_fff3_dd1:3;
    };
}dvbc_opt_u_fff3_dd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  opt_u_fff4_dd1:3;
        RBus_UInt32  opt_u_fff4_dd0:3;
    };
}dvbc_opt_u_fff4_dd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  opt_u_fbf3_dd1:2;
        RBus_UInt32  opt_u_fbf3_dd0:2;
        RBus_UInt32  opt_u_fff4_dd2:3;
    };
}dvbc_opt_u_fff4_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_u_fbf4_dd2:2;
        RBus_UInt32  opt_u_fbf4_dd1:2;
        RBus_UInt32  opt_u_fbf4_dd0:2;
        RBus_UInt32  opt_u_fbf3_dd2:2;
    };
}dvbc_opt_u_fbf3_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_fbf_nb_num:1;
    };
}dvbc_opt_fbf_nb_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bn_cond7_en:1;
        RBus_UInt32  bn_cond6_en:1;
    };
}dvbc_bn_cond6_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  opt_bn_eq_amp_th:4;
        RBus_UInt32  opt_bn_cond6_cnt_th:3;
    };
}dvbc_opt_bn_cond6_cnt_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  eq_tap_i_7_0:8;
    };
}dvbc_eq_tap_i_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  eq_tap_i_15_8:8;
    };
}dvbc_eq_tap_i_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  eq_tap_q_7_0:8;
    };
}dvbc_eq_tap_q_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  eq_tap_q_15_8:8;
    };
}dvbc_eq_tap_q_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page1_rwb0_reserved:8;
    };
}dvbc_page1_rwb0_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page1_rwb1_reserved:8;
    };
}dvbc_page1_rwb1_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page1_rwb2_reserved:8;
    };
}dvbc_page1_rwb2_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page1_rwb3_reserved:8;
    };
}dvbc_page1_rwb3_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page1_rwb4_reserved:8;
    };
}dvbc_page1_rwb4_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page1_rwb5_reserved:8;
    };
}dvbc_page1_rwb5_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page1_rwb6_reserved:8;
    };
}dvbc_page1_rwb6_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page1_rwb7_reserved:8;
    };
}dvbc_page1_rwb7_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_adc_im:1;
        RBus_UInt32  opt_adc_clip_iq:2;
        RBus_UInt32  opt_aagc_iq_swap:1;
    };
}dvbc_opt_aagc_iq_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_fe_dcc1_max:3;
        RBus_UInt32  opt_fe_dcc1_max_en:1;
        RBus_UInt32  opt_fe_dcc1_en:1;
    };
}dvbc_opt_fe_dcc1_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_dcc1_u_trk:4;
        RBus_UInt32  opt_fe_dcc1_u_acq:4;
    };
}dvbc_opt_fe_dcc1_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_dcc1_acq_dly_prd:2;
        RBus_UInt32  opt_fe_dcc1_clr:2;
        RBus_UInt32  opt_fe_dcc1_upd:2;
        RBus_UInt32  opt_fe_dcc1_u:2;
    };
}dvbc_opt_fe_dcc1_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  zif_spec_inv_on:1;
        RBus_UInt32  ddc_zif_mode:1;
        RBus_UInt32  opt_aagc_loop_in:3;
    };
}dvbc_opt_aagc_loop_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_fe_dcc2_max:3;
        RBus_UInt32  opt_fe_dcc2_max_en:1;
        RBus_UInt32  opt_fe_dcc2_en:1;
    };
}dvbc_opt_fe_dcc2_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_dcc2_u_trk:4;
        RBus_UInt32  opt_fe_dcc2_u_acq:4;
    };
}dvbc_opt_fe_dcc2_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_dcc2_acq_dly_prd:2;
        RBus_UInt32  opt_fe_dcc2_clr:2;
        RBus_UInt32  opt_fe_dcc2_upd:2;
        RBus_UInt32  opt_fe_dcc2_u:2;
    };
}dvbc_opt_fe_dcc2_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_fe_dcc3_max:3;
        RBus_UInt32  opt_fe_dcc3_max_en:1;
        RBus_UInt32  opt_fe_dcc3_en:1;
    };
}dvbc_opt_fe_dcc3_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_dcc3_u_trk:4;
        RBus_UInt32  opt_fe_dcc3_u_acq:4;
    };
}dvbc_opt_fe_dcc3_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_dcc3_acq_dly_prd:2;
        RBus_UInt32  opt_fe_dcc3_clr:2;
        RBus_UInt32  opt_fe_dcc3_upd:2;
        RBus_UInt32  opt_fe_dcc3_u:2;
    };
}dvbc_opt_fe_dcc3_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_iq_acq_dly_prd:2;
        RBus_UInt32  opt_fe_iq_clr:2;
        RBus_UInt32  opt_fe_iq_upd:2;
        RBus_UInt32  opt_fe_iq_u:2;
    };
}dvbc_opt_fe_iq_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_fe_iqamp_max:3;
        RBus_UInt32  opt_fe_iqamp_max_en:1;
        RBus_UInt32  opt_fe_iqamp_en:1;
    };
}dvbc_opt_fe_iqamp_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_iqamp_u_trk:4;
        RBus_UInt32  opt_fe_iqamp_u_acq:4;
    };
}dvbc_opt_fe_iqamp_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_iqamp_manu_6_0:7;
        RBus_UInt32  opt_fe_iqamp_manu_en:1;
    };
}dvbc_opt_fe_iqamp_manu_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  opt_fe_iqamp_manu_9_7:3;
    };
}dvbc_opt_fe_iqamp_manu_en_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_fe_iqph_max:3;
        RBus_UInt32  opt_fe_iqph_max_en:1;
        RBus_UInt32  opt_fe_iqph_en:1;
    };
}dvbc_opt_fe_iqph_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_iqph_u_trk:4;
        RBus_UInt32  opt_fe_iqph_u_acq:4;
    };
}dvbc_opt_fe_iqph_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_fe_iqph_manu_6_0:7;
        RBus_UInt32  opt_fe_iqph_manu_en:1;
    };
}dvbc_opt_fe_iqph_manu_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  opt_fe_iqph_manu_9_7:3;
    };
}dvbc_opt_fe_iqph_manu_en_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  fsm_word_r_90_88:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  fsm_word_90_88:3;
    };
}dvbc_fsm_word_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  version_dvbc_outer:8;
    };
}dvbc_version_dvbc_outer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  synclost:1;
        RBus_UInt32  opt_trk_mode:2;
        RBus_UInt32  opt_acq_mode:2;
        RBus_UInt32  opt_mismatch_bit_num:2;
        RBus_UInt32  opt_freeze:1;
    };
}dvbc_opt_freeze_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  opt_deintl_i:7;
    };
}dvbc_opt_deintl_i_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_deintl_m:5;
    };
}dvbc_opt_deintl_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_ber_rd_strobe:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  opt_errmode:1;
        RBus_UInt32  opt_nocorr:1;
        RBus_UInt32  opt_rsd_disable:1;
    };
}dvbc_opt_rsd_disable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ber_en_stb:1;
        RBus_UInt32  opt_volume:3;
        RBus_UInt32  opt_dis_auto_mode:1;
        RBus_UInt32  opt_ber_hold:1;
        RBus_UInt32  opt_ber_en:1;
    };
}dvbc_opt_ber_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ber_count_7_0:8;
    };
}dvbc_ber_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ber_count_15_8:8;
    };
}dvbc_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  block_count_18_16:3;
        RBus_UInt32  ber_count_20_16:5;
    };
}dvbc_ber_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  block_count_7_0:8;
    };
}dvbc_block_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  block_count_15_8:8;
    };
}dvbc_block_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  corr_count_7_0:8;
    };
}dvbc_corr_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  corr_count_15_8:8;
    };
}dvbc_corr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  uncorr_count_7_0:8;
    };
}dvbc_uncorr_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  uncorr_count_15_8:8;
    };
}dvbc_uncorr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_dvbc_smooth:1;
        RBus_UInt32  opt_fix_invsync:1;
        RBus_UInt32  opt_syncmode:2;
        RBus_UInt32  opt_fix_tei:1;
        RBus_UInt32  opt_no_reinvert:1;
        RBus_UInt32  desc_syncstate:1;
        RBus_UInt32  opt_desc_disable:1;
    };
}dvbc_opt_desc_disable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_sync_byte:1;
        RBus_UInt32  opt_serial:1;
        RBus_UInt32  opt_ckout_pwr:1;
        RBus_UInt32  opt_ckoutpar:1;
    };
}dvbc_opt_ckoutpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_cdiv_ph1:4;
        RBus_UInt32  opt_cdiv_ph0:4;
    };
}dvbc_opt_cdiv_ph0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bist_sta_stb:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  res3:3;
    };
}dvbc_opt_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_ber_blk_count:8;
    };
}dvbc_auto_ber_blk_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_ber_count_0:8;
    };
}dvbc_auto_ber_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_ber_count_1:8;
    };
}dvbc_auto_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_blk_count_2:3;
        RBus_UInt32  auto_ber_count_2:5;
    };
}dvbc_auto_ber_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_blk_count_0:8;
    };
}dvbc_auto_blk_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_blk_count_1:8;
    };
}dvbc_auto_blk_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_corr_count_0:8;
    };
}dvbc_auto_corr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_corr_count_1:8;
    };
}dvbc_auto_corr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_uncorr_count_0:8;
    };
}dvbc_auto_uncorr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  auto_uncorr_count_1:8;
    };
}dvbc_auto_uncorr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page2_rw21_reserved:8;
    };
}dvbc_page2_rw21_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page2_rw22_reserved:8;
    };
}dvbc_page2_rw22_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page2_rw23_reserved:8;
    };
}dvbc_page2_rw23_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page2_rw24_reserved:8;
    };
}dvbc_page2_rw24_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page2_rw25_reserved:8;
    };
}dvbc_page2_rw25_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page2_rw26_reserved:8;
    };
}dvbc_page2_rw26_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page2_rw27_reserved:8;
    };
}dvbc_page2_rw27_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  page2_rw28_reserved:8;
    };
}dvbc_page2_rw28_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_dsp_first_out_idx_7_0:8;
    };
}dvbc_opt_dsp_first_out_idx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_dsp_first_out_idx_12_8:5;
    };
}dvbc_opt_dsp_first_out_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_fft_abs_out:1;
    };
}dvbc_opt_fft_abs_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_fft_dsp_read:1;
    };
}dvbc_opt_fft_dsp_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_pos_frq_slot_sr_en_7_0:8;
    };
}dvbc_opt_pos_frq_slot_sr_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_pos_frq_slot_sr_en_15_8:8;
    };
}dvbc_opt_pos_frq_slot_sr_en_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_fft_out_mode:1;
    };
}dvbc_opt_fft_out_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_papd_papr_sel:1;
    };
}dvbc_opt_papd_papr_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_fft_output_acc_num:4;
    };
}dvbc_opt_fft_output_acc_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_nbd_tdft_idx:4;
    };
}dvbc_opt_nbd_tdft_idx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_slot_avg_ratio_sel:4;
    };
}dvbc_opt_slot_avg_ratio_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_comp_slot_avg_thd_7_0:8;
    };
}dvbc_opt_comp_slot_avg_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_comp_slot_avg_thd_15_8:8;
    };
}dvbc_opt_comp_slot_avg_thd_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dvbc_opt_first_tone_crit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dvbc_opt_neg_frq_comp_crit_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dvbc_opt_pos_frq_comp_crit_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_pos_frq_max_sr_7_0:8;
    };
}dvbc_opt_pos_frq_max_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_pos_frq_max_sr_11_8:4;
    };
}dvbc_opt_pos_frq_max_sr_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_pos_frq_min_sr_7_0:8;
    };
}dvbc_opt_pos_frq_min_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_pos_frq_min_sr_11_8:4;
    };
}dvbc_opt_pos_frq_min_sr_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_cnt_stop_7_0:8;
    };
}dvbc_opt_qamd_cnt_stop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  opt_qamd_cnt_stop_12_8:5;
    };
}dvbc_opt_qamd_cnt_stop_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn0_max_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn0_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn0_max_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn0_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn0_min_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn0_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn0_min_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn0_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn1_max_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn1_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn1_max_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn1_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn1_min_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn1_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn1_min_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn1_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn2_max_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn2_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn2_max_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn2_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn2_min_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn2_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn2_min_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn2_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn3_max_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn3_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn3_max_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn3_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn3_min_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn3_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn3_min_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn3_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn4_max_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn4_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn4_max_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn4_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn4_min_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn4_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn4_min_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn4_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn5_max_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn5_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn5_max_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn5_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_eqp_zn5_min_7_0:8;
    };
}dvbc_opt_qamd_eqp_zn5_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_eqp_zn5_min_9_8:2;
    };
}dvbc_opt_qamd_eqp_zn5_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_qamd_self_reset:1;
    };
}dvbc_opt_qamd_self_reset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  opt_qamd_start_state:4;
    };
}dvbc_opt_qamd_start_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_thd_128qam_7_0:8;
    };
}dvbc_opt_qamd_thd_128qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_thd_128qam_9_8:2;
    };
}dvbc_opt_qamd_thd_128qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_thd_16qam_7_0:8;
    };
}dvbc_opt_qamd_thd_16qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_thd_16qam_9_8:2;
    };
}dvbc_opt_qamd_thd_16qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_thd_256qam_7_0:8;
    };
}dvbc_opt_qamd_thd_256qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_thd_256qam_9_8:2;
    };
}dvbc_opt_qamd_thd_256qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_thd_32qam_7_0:8;
    };
}dvbc_opt_qamd_thd_32qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_thd_32qam_9_8:2;
    };
}dvbc_opt_qamd_thd_32qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  opt_qamd_thd_64qam_7_0:8;
    };
}dvbc_opt_qamd_thd_64qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  opt_qamd_thd_64qam_9_8:2;
    };
}dvbc_opt_qamd_thd_64qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_start_srs_nbd:1;
    };
}dvbc_opt_start_srs_nbd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  nbd_tdft_out_7_0:8;
    };
}dvbc_nbd_tdft_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  nbd_tdft_out_15_8:8;
    };
}dvbc_nbd_tdft_out_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  min_max_sr_ini_cnt:5;
    };
}dvbc_min_max_sr_ini_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_tone_max_val_0_7_0:8;
    };
}dvbc_pos_tone_max_val_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_tone_max_val_0_15_8:8;
    };
}dvbc_pos_tone_max_val_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_tone_max_val_1_7_0:8;
    };
}dvbc_pos_tone_max_val_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_tone_max_val_1_15_8:8;
    };
}dvbc_pos_tone_max_val_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_tone_max_val_2_7_0:8;
    };
}dvbc_pos_tone_max_val_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_tone_max_val_2_15_8:8;
    };
}dvbc_pos_tone_max_val_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_tone_max_idx_0_7_0:8;
    };
}dvbc_pos_tone_max_idx_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pos_tone_max_idx_0_11_8:4;
    };
}dvbc_pos_tone_max_idx_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_tone_max_idx_1_7_0:8;
    };
}dvbc_pos_tone_max_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pos_tone_max_idx_1_11_8:4;
    };
}dvbc_pos_tone_max_idx_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_tone_max_idx_2_7_0:8;
    };
}dvbc_pos_tone_max_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  qam_con_bit_det:4;
    };
}dvbc_qam_con_bit_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn0_cdf_7_0:8;
    };
}dvbc_qamd_rv_zn0_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  qamd_rv_zn0_cdf_9_8:2;
    };
}dvbc_qamd_rv_zn0_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn1_cdf_7_0:8;
    };
}dvbc_qamd_rv_zn1_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  qamd_rv_zn1_cdf_9_8:2;
    };
}dvbc_qamd_rv_zn1_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn2_cdf_7_0:8;
    };
}dvbc_qamd_rv_zn2_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  qamd_rv_zn2_cdf_9_8:2;
    };
}dvbc_qamd_rv_zn2_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn3_cdf_7_0:8;
    };
}dvbc_qamd_rv_zn3_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  qamd_rv_zn3_cdf_9_8:2;
    };
}dvbc_qamd_rv_zn3_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn4_cdf_7_0:8;
    };
}dvbc_qamd_rv_zn4_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  qamd_rv_zn4_cdf_9_8:2;
    };
}dvbc_qamd_rv_zn4_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn5_cdf_7_0:8;
    };
}dvbc_qamd_rv_zn5_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  qamd_rv_zn5_cdf_9_8:2;
    };
}dvbc_qamd_rv_zn5_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif0_7_0:8;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif0_10_8:3;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif1_7_0:8;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif1_10_8:3;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif2_7_0:8;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif2_10_8:3;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif3_7_0:8;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif3_10_8:3;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif4_7_0:8;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif4_10_8:3;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  reg_qamd_done:1;
    };
}dvbc_reg_qamd_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  solt_avg_pow_dif_7_0:8;
    };
}dvbc_solt_avg_pow_dif_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  solt_avg_pow_dif_15_8:8;
    };
}dvbc_solt_avg_pow_dif_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  solt_avg_pow_max_7_0:8;
    };
}dvbc_solt_avg_pow_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  solt_avg_pow_max_15_8:8;
    };
}dvbc_solt_avg_pow_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  solt_avg_pow_min_7_0:8;
    };
}dvbc_solt_avg_pow_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  solt_avg_pow_min_15_8:8;
    };
}dvbc_solt_avg_pow_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  srs_nbd_done:1;
    };
}dvbc_srs_nbd_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pos_tone_max_idx_2_11_8:4;
    };
}dvbc_pos_tone_max_idx_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_slot_avg_val_0_7_0:8;
    };
}dvbc_pos_slot_avg_val_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_slot_avg_val_0_15_8:8;
    };
}dvbc_pos_slot_avg_val_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_rom_bist_out01_7_0:8;
    };
}dvbc_rom_bist_out_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_rom_bist_out01_15_8:8;
    };
}dvbc_rom_bist_out_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_rom_bist_out01_23_16:8;
    };
}dvbc_rom_bist_out_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_rom_bist_out01_31_24:8;
    };
}dvbc_rom_bist_out_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_rom_bist_out01_39_32:8;
    };
}dvbc_rom_bist_out_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  inrx_rom_bist_out01_47_40:8;
    };
}dvbc_rom_bist_out_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  inrx_rom_bist_out01_51_48:4;
    };
}dvbc_rom_bist_out_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  version_oc_outer:8;
    };
}dvbc_version_oc_outer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  viterbi_rd_stb:1;
        RBus_UInt32  puncsync_lost:1;
        RBus_UInt32  manu_skip:1;
        RBus_UInt32  force_vt_en:1;
        RBus_UInt32  zero_metrics:1;
        RBus_UInt32  soft_reset_ff:1;
        RBus_UInt32  punct_sync_mode:1;
        RBus_UInt32  vt_lsb_hd:1;
    };
}dvbc_vt_lsb_hd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  td_trk_mode:4;
        RBus_UInt32  td_acq_mode:4;
    };
}dvbc_td_acq_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vt_window_len:8;
    };
}dvbc_vt_window_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  trk_gap:8;
    };
}dvbc_trk_gap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vt_ber_count_7_0:8;
    };
}dvbc_vt_ber_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vt_ber_count_15_8:8;
    };
}dvbc_vt_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  deintl_mode:2;
        RBus_UInt32  derand_dis:1;
        RBus_UInt32  puncsync_en:1;
        RBus_UInt32  fs_sync_lost:1;
        RBus_UInt32  intl_chg_flag:1;
    };
}dvbc_intl_chg_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fs_mismatch_trk:4;
        RBus_UInt32  fs_mismatch_acq:4;
    };
}dvbc_fs_mismatch_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fs_trk_mode:4;
        RBus_UInt32  fs_acq_mode:4;
    };
}dvbc_fs_acq_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  intl_mode_chg_cnt:4;
    };
}dvbc_intl_mode_chg_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  trailer_0:8;
    };
}dvbc_trailer_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  trailer_1:8;
    };
}dvbc_trailer_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  trailer_2:8;
    };
}dvbc_trailer_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  trailer_3:8;
    };
}dvbc_trailer_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fs_acq_fail:4;
        RBus_UInt32  inval_sync_cnt:4;
    };
}dvbc_inval_sync_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  detintl_man_cfg:4;
        RBus_UInt32  deintl_auto_cfg:4;
    };
}dvbc_deintl_auto_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ber_rd_strobe:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  oc_errmode:1;
        RBus_UInt32  oc_nocorr:1;
        RBus_UInt32  oc_rsd_disable:1;
    };
}dvbc_oc_rsd_disable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ber_en_stb_oc:1;
        RBus_UInt32  ber_en_stat:1;
        RBus_UInt32  oc_volume:3;
        RBus_UInt32  oc_dis_auto_mode:1;
        RBus_UInt32  rs_bert_hold:1;
        RBus_UInt32  oc_ber_en:1;
    };
}dvbc_oc_ber_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rs_ber_count_0:8;
    };
}dvbc_rs_ber_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rs_ber_count_1:8;
    };
}dvbc_rs_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rs_block_count_2:3;
        RBus_UInt32  rs_ber_count_2:5;
    };
}dvbc_rs_ber_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rs_block_count_0:8;
    };
}dvbc_rs_block_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rs_block_count_1:8;
    };
}dvbc_rs_block_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rs_corr_count_0:8;
    };
}dvbc_rs_corr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rs_corr_count_1:8;
    };
}dvbc_rs_corr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rs_uncorr_count_0:8;
    };
}dvbc_rs_uncorr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rs_uncorr_count_1:8;
    };
}dvbc_rs_uncorr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_cdiv_ph1:4;
        RBus_UInt32  oc_cdiv_ph0:4;
    };
}dvbc_oc_cdiv_ph0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  oc_ckout_pwr:1;
        RBus_UInt32  oc_ckoutpar:1;
        RBus_UInt32  oc_serial:1;
    };
}dvbc_oc_ckout_pwr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_sync_byte:1;
        RBus_UInt32  oc_mpeg_rs_en:1;
        RBus_UInt32  oc_set_mpeg_err:2;
        RBus_UInt32  oc_tei_rs_err_en:1;
        RBus_UInt32  oc_tei_sd_err_en:1;
        RBus_UInt32  oc_repla_sd_en:1;
        RBus_UInt32  oc_mpeg_sync_mode:1;
    };
}dvbc_oc_mpeg_sync_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_mpeg_mismatch:2;
        RBus_UInt32  oc_mpeg_acq_mode:2;
        RBus_UInt32  oc_mpeg_trk_mode:4;
    };
}dvbc_oc_mpeg_mismatch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  oc_mpeg_per_rd_strobe:1;
        RBus_UInt32  oc_mpeg_pert_en:1;
        RBus_UInt32  oc_mpeg_pert_hold:1;
        RBus_UInt32  oc_mpeg_dis_auto_mode:1;
        RBus_UInt32  oc_mpeg_test_volume:3;
    };
}dvbc_oc_mpeg_per_rd_strobe_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_syndm_err_count_0:8;
    };
}dvbc_oc_syndm_err_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_syndm_err_count_1:8;
    };
}dvbc_oc_syndm_err_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_mpeg_pkt_count_0:8;
    };
}dvbc_oc_mpeg_pkt_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_mpeg_pkt_count_1:8;
    };
}dvbc_oc_mpeg_pkt_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_mpeg_pkt_count_2:8;
    };
}dvbc_oc_mpeg_pkt_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_mpeg_acq2_n_mode:4;
        RBus_UInt32  oc_mpeg_acq2_k_mode:4;
    };
}dvbc_oc_mpeg_acq2_k_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_ber_blk_count:8;
    };
}dvbc_oc_auto_ber_blk_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_ber_count_0:8;
    };
}dvbc_oc_auto_ber_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_ber_count_1:8;
    };
}dvbc_oc_auto_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_blk_count_2:3;
        RBus_UInt32  oc_auto_ber_count_2:5;
    };
}dvbc_oc_auto_ber_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_blk_count_0:8;
    };
}dvbc_oc_auto_blk_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_blk_count_1:8;
    };
}dvbc_oc_auto_blk_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_corr_count_0:8;
    };
}dvbc_oc_auto_corr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_corr_count_1:8;
    };
}dvbc_oc_auto_corr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_uncorr_count_0:8;
    };
}dvbc_oc_auto_uncorr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  oc_auto_uncorr_count_1:8;
    };
}dvbc_oc_auto_uncorr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  reg_bist_mode_cablerx_bn:1;
        RBus_UInt32  reg_bist_mode_debugdma:1;
        RBus_UInt32  reg_bist_mode_cablerx_out:1;
        RBus_UInt32  reg_bist_mode_cablerx_deint:1;
        RBus_UInt32  reg_bist_mode_cablerx_fftbuf:1;
        RBus_UInt32  res2:1;
    };
}dvbc_oc_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  reg_drf_bist_mode_cablerx_bn:1;
        RBus_UInt32  reg_drf_bist_mode_debugdma:1;
        RBus_UInt32  reg_drf_bist_mode_cablerx_out:1;
        RBus_UInt32  reg_drf_bist_mode_cablerx_deint:1;
        RBus_UInt32  reg_drf_bist_mode_cablerx_fftbuf:1;
        RBus_UInt32  res2:1;
    };
}dvbc_oc_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  reg_drf_test_resume_cablerx_bn:1;
        RBus_UInt32  reg_drf_test_resume_debugdma:1;
        RBus_UInt32  reg_drf_test_resume_cablerx_out:1;
        RBus_UInt32  reg_drf_test_resume_cablerx_deint:1;
        RBus_UInt32  reg_drf_test_resume_cablerx_fftbuf:1;
        RBus_UInt32  res2:1;
    };
}dvbc_oc_drf_resume_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  reg_mbist_cablerx_dvs:4;
    };
}dvbc_oc_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  reg_mbist_cablerx_dvse:1;
    };
}dvbc_oc_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  reg_mbist_cablerx_ls:1;
    };
}dvbc_oc_bist_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  bist_done_cablerx_bn:1;
        RBus_UInt32  bist_done_debugdma:1;
        RBus_UInt32  bist_done_cablerx_out:1;
        RBus_UInt32  bist_done_cablerx_deint:1;
        RBus_UInt32  bist_done_cablerx_fftbuf:1;
        RBus_UInt32  res2:1;
    };
}dvbc_oc_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  bist_fail_cablerx_bn:1;
        RBus_UInt32  bist_fail_debugdma:1;
        RBus_UInt32  bist_fail_cablerx_out:1;
        RBus_UInt32  bist_fail_cablerx_deint:1;
        RBus_UInt32  bist_fail_cablerx_fftbuf:1;
        RBus_UInt32  res2:1;
    };
}dvbc_oc_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  drf_bist_done_cablerx_bn:1;
        RBus_UInt32  drf_bist_done_debugdma:1;
        RBus_UInt32  drf_bist_done_cablerx_out:1;
        RBus_UInt32  drf_bist_done_cablerx_deint:1;
        RBus_UInt32  drf_bist_done_cablerx_fftbuf:1;
        RBus_UInt32  res2:1;
    };
}dvbc_oc_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  drf_bist_fail_cablerx_bn:1;
        RBus_UInt32  drf_bist_fail_debugdma:1;
        RBus_UInt32  drf_bist_fail_cablerx_out:1;
        RBus_UInt32  drf_bist_fail_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_cablerx_fftbuf:1;
        RBus_UInt32  res2:1;
    };
}dvbc_oc_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  bist_fail_3_cablerx_fftbuf:1;
        RBus_UInt32  bist_fail_2_cablerx_fftbuf:1;
        RBus_UInt32  bist_fail_1_cablerx_fftbuf:1;
        RBus_UInt32  bist_fail_0_cablerx_fftbuf:1;
    };
}dvbc_oc_bist_fftbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bist_fail_7_cablerx_deint:1;
        RBus_UInt32  bist_fail_6_cablerx_deint:1;
        RBus_UInt32  bist_fail_5_cablerx_deint:1;
        RBus_UInt32  bist_fail_4_cablerx_deint:1;
        RBus_UInt32  bist_fail_3_cablerx_deint:1;
        RBus_UInt32  bist_fail_2_cablerx_deint:1;
        RBus_UInt32  bist_fail_1_cablerx_deint:1;
        RBus_UInt32  bist_fail_0_cablerx_deint:1;
    };
}dvbc_oc_bist_deint_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_fail_1_cablerx_bn:1;
        RBus_UInt32  bist_fail_0_cablerx_bn:1;
        RBus_UInt32  bist_fail_2_cablerx_out:1;
        RBus_UInt32  bist_fail_1_cablerx_out:1;
        RBus_UInt32  bist_fail_0_cablerx_out:1;
    };
}dvbc_oc_bist_out_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  drf_bist_fail_3_cablerx_fftbuf:1;
        RBus_UInt32  drf_bist_fail_2_cablerx_fftbuf:1;
        RBus_UInt32  drf_bist_fail_1_cablerx_fftbuf:1;
        RBus_UInt32  drf_bist_fail_0_cablerx_fftbuf:1;
    };
}dvbc_oc_drf_bist_fftbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  drf_bist_fail_7_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_6_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_5_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_4_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_3_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_2_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_1_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_0_cablerx_deint:1;
    };
}dvbc_oc_drf_bist_deint_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  drf_bist_fail_1_cablerx_bn:1;
        RBus_UInt32  drf_bist_fail_0_cablerx_bn:1;
        RBus_UInt32  drf_bist_fail_2_cablerx_out:1;
        RBus_UInt32  drf_bist_fail_1_cablerx_out:1;
        RBus_UInt32  drf_bist_fail_0_cablerx_out:1;
    };
}dvbc_oc_drf_bist_out_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  drf_start_pause_cablerx_bn:1;
        RBus_UInt32  drf_start_pause_debugdma:1;
        RBus_UInt32  drf_start_pause_cablerx_out:1;
        RBus_UInt32  drf_start_pause_cablerx_deint:1;
        RBus_UInt32  drf_start_pause_cablerx_fftbuf:1;
        RBus_UInt32  res2:1;
    };
}dvbc_oc_bist_drf_start_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_dump_adc_dagc_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_dtv_debugdma_en:1;
        RBus_UInt32  reg_demod_debugdma_circular_num:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_demod_debugdma_blen:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_demod_debugdma_waterlvl:6;
    };
}dvbc_debugdma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_demod_debugdma_startaddr:29;
    };
}dvbc_debugdma_start_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_demod_debugdma_endaddr:29;
    };
}dvbc_debugdma_end_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  reg_debugdma_underflow_clr:1;
        RBus_UInt32  reg_debugdma_overflow_clr:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  debugdma_underflow_ro:1;
        RBus_UInt32  debugdma_overflow_ro:1;
    };
}dvbc_debugdma_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  reg_r_psd_start:1;
    };
}dvbc_psd_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_r_psd_scale:8;
        RBus_UInt32  reg_r_psd_dco:8;
        RBus_UInt32  reg_r_psd_ctrl2:8;
        RBus_UInt32  reg_r_psd_ctrl1:8;
    };
}dvbc_psd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  psd_done:1;
        RBus_UInt32  psd_pwr:16;
    };
}dvbc_psd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  srs_deint_sram_fw_mode:1;
        RBus_UInt32  srs_deint_sram_mode:1;
    };
}dvbc_srs_deint_sram_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_slot_avg_val_1_7_0:8;
    };
}dvbc_pos_slot_avg_val_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_slot_avg_val_1_15_8:8;
    };
}dvbc_pos_slot_avg_val_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_slot_avg_val_2_7_0:8;
    };
}dvbc_pos_slot_avg_val_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pos_slot_avg_val_2_15_8:8;
    };
}dvbc_pos_slot_avg_val_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_tone_max_val_0_7_0:8;
    };
}dvbc_neg_tone_max_val_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_tone_max_val_0_15_8:8;
    };
}dvbc_neg_tone_max_val_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_tone_max_val_1_7_0:8;
    };
}dvbc_neg_tone_max_val_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_tone_max_val_1_15_8:8;
    };
}dvbc_neg_tone_max_val_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_tone_max_val_2_7_0:8;
    };
}dvbc_neg_tone_max_val_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_tone_max_val_2_15_8:8;
    };
}dvbc_neg_tone_max_val_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_tone_max_idx_0_7_0:8;
    };
}dvbc_neg_tone_max_idx_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  neg_tone_max_idx_0_11_8:4;
    };
}dvbc_neg_tone_max_idx_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_tone_max_idx_1_7_0:8;
    };
}dvbc_neg_tone_max_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  neg_tone_max_idx_1_11_8:4;
    };
}dvbc_neg_tone_max_idx_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_tone_max_idx_2_7_0:8;
    };
}dvbc_neg_tone_max_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  neg_tone_max_idx_2_11_8:4;
    };
}dvbc_neg_tone_max_idx_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_slot_avg_val_0_7_0:8;
    };
}dvbc_neg_slot_avg_val_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_slot_avg_val_0_15_8:8;
    };
}dvbc_neg_slot_avg_val_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_slot_avg_val_1_7_0:8;
    };
}dvbc_neg_slot_avg_val_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_slot_avg_val_1_15_8:8;
    };
}dvbc_neg_slot_avg_val_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_slot_avg_val_2_7_0:8;
    };
}dvbc_neg_slot_avg_val_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  neg_slot_avg_val_2_15_8:8;
    };
}dvbc_neg_slot_avg_val_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  opt_srs_input_sel:1;
    };
}dvbc_opt_srs_input_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  bnm_cnt_rst:1;
        RBus_UInt32  bnm_mu:2;
        RBus_UInt32  bnm_on:1;
        RBus_UInt32  bnm_window_en_on:3;
    };
}dvbc_bnm_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bnm_window1_en_ratio:5;
    };
}dvbc_bnm_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bnm_window1_en_num:8;
    };
}dvbc_bnm_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bnm_window2_en_ratio:5;
    };
}dvbc_bnm_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  bnm_window2_en_num:6;
    };
}dvbc_bnm_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bnm_window3_en_ratio:5;
    };
}dvbc_bnm_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bnm_null_en_ratio:5;
    };
}dvbc_bnm_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_detect_cnt:32;
    };
}dvbc_bnm_detect_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_clip_cnt:32;
    };
}dvbc_bnm_clip_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  opt_prd_pha_sel_thd:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  opt_start_prd:1;
    };
}dvbc_prd_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_prd_thd_l:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  opt_prd_thd_h:15;
    };
}dvbc_prd_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_prd_level2:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  opt_prd_level1:15;
    };
}dvbc_prd_thd_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_prd_level4:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  opt_prd_level3:15;
    };
}dvbc_prd_thd_3_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  opt_prd_level5:15;
    };
}dvbc_prd_thd_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_prd_comp_idx4:8;
        RBus_UInt32  opt_prd_comp_idx3:8;
        RBus_UInt32  opt_prd_comp_idx2:8;
        RBus_UInt32  opt_prd_comp_idx1:8;
    };
}dvbc_prd_comp_idx_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  opt_prd_err_alpha:3;
        RBus_UInt32  opt_prd_err_term_h:12;
        RBus_UInt32  opt_prd_err_term_l:12;
    };
}dvbc_prd_err_RBUS;

#else //apply LITTLE_ENDIAN

//======DVBC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chip_version:8;
        RBus_UInt32  res1:24;
    };
}dvbc_chip_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_adcdata_i_qam:2;
        RBus_UInt32  opt_adcclk_qam:1;
        RBus_UInt32  opt_qam_outer_data:1;
        RBus_UInt32  opt_tst_in_sel:2;
        RBus_UInt32  opt_adcdata_q_qam:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_adcdata_i_qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qam_std:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_qam_std_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qam_on:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_qam_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_soft_reset_qam:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_soft_reset_qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_rf_aagc_drive:1;
        RBus_UInt32  opt_par_rf_sd_ib:1;
        RBus_UInt32  opt_rf_aagc_oe:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  opt_if_aagc_drive:1;
        RBus_UInt32  opt_par_if_sd_ib:1;
        RBus_UInt32  opt_if_aagc_oe:1;
        RBus_UInt32  res3:24;
    };
}dvbc_opt_rf_aagc_drive_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_if_aagc_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_rf_aagc_sel:3;
        RBus_UInt32  res2:25;
    };
}dvbc_opt_if_aagc_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_debug_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_ro_debug_sel:3;
        RBus_UInt32  res2:25;
    };
}dvbc_opt_debug_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_debug_oe_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_debug_oe_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_debug_oe_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_debug_oe_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_debug_oe_23_16:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_debug_oe_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_debug_oe_31_24:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_debug_oe_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_reg_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_debug_reg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_reg_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_debug_reg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_reg_23_16:8;
        RBus_UInt32  res1:24;
    };
}dvbc_debug_reg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_reg_31_24:8;
        RBus_UInt32  res1:24;
    };
}dvbc_debug_reg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_debug_pu_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_pu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_debug_pu_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_pu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_debug_pu_23_16:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_pu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_debug_pu_31_24:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_pu_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_debug_pd_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_pd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_debug_pd_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_pd_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_debug_pd_23_16:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_pd_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_debug_pd_31_24:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_pd_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_adc_out_sel:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_adc_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_tst_out_sel:1;
        RBus_UInt32  opt_tst_out_tri1:3;
        RBus_UInt32  opt_tst_out_tri2:3;
        RBus_UInt32  opt_par_tstclk:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_tst_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mpeg_out_sel:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_mpeg_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_page0_ro_stb:1;
        RBus_UInt32  ro_reg_on:1;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_page0_ro_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_8051_int0_en:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_8051_int0_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ro_rf_agc_ro:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ro_rf_agc_oe_ro:1;
        RBus_UInt32  ro_if_agc_ro:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ro_if_agc_oe_ro:1;
        RBus_UInt32  res3:26;
    };
}dvbc_ro_agc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rssi_agc_q_ro_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rssi_agc_q_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rssi_agc_q_ro_13_8:6;
        RBus_UInt32  res1:26;
    };
}dvbc_rssi_agc_q_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rssi_agc_loop_sat_ro:1;
        RBus_UInt32  res1:31;
    };
}dvbc_rssi_agc_loop_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad7_out_ro:7;
        RBus_UInt32  res1:25;
    };
}dvbc_ad7_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_mpeg_out_ro_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_mpeg_out_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_mpeg_out_ro_11_8:4;
        RBus_UInt32  res1:28;
    };
}dvbc_qam_mpeg_out_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ro_debug_ro_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ro_debug_ro_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ro_debug_ro_23_16:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ro_debug_ro_31_24:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_debug_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_rw40_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw40_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_rw41_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw41_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_rw42_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw42_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_rw43_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw43_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_rw44_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw44_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_rw45_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw45_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_rw46_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw46_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_rw47_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw47_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_ro48_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw48_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_ro49_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw49_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_ro4a_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw4a_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page0_ro4b_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page0_rw4b_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_soft_reset_rssi_agc:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_soft_reset_rssi_agc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rssi_agc_on:1;
        RBus_UInt32  rssi_in_ph_sel:1;
        RBus_UInt32  u_rssi_agc_exp:3;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_rssi_agc_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rssi_in_clk_ratio:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rssi_in_clk_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rssi_agc_max:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rssi_agc_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rssi_agc_min:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rssi_agc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rssi_agc_targ_val:7;
        RBus_UInt32  rssi_agc_pol:1;
        RBus_UInt32  res1:24;
    };
}dvbc_rssi_agc_targ_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ad7_ckout_inv:1;
        RBus_UInt32  rssi_in_ph_sel2:1;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_ad7_ckout_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_adc_clk_xor:1;
        RBus_UInt32  reg_en_dcr:1;
        RBus_UInt32  reg_en_pga_mode:1;
        RBus_UInt32  reg_en_gi_pga:1;
        RBus_UInt32  reg_aagc_hold:1;
        RBus_UInt32  reg_aagc_cal_payload:1;
        RBus_UInt32  reg_pset_aagc:1;
        RBus_UInt32  reg_hold_pga:1;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_adc_clk_xor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_target_val:8;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_target_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_aagc_loopgain0:5;
        RBus_UInt32  reg_aagc_loopgain1_2_0:3;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_aagc_loopgain0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_aagc_loopgain1_4_3:2;
        RBus_UInt32  reg_aagc_loopgain2:5;
        RBus_UInt32  res1:25;
    };
}dvbc_reg_aagc_loopgain0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_aagc_lock_det_len:4;
        RBus_UInt32  reg_aagc_lock_det_thd:4;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_aagc_lock_det_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_pset_aagc_val:8;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_pset_aagc_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_aagc_latency_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_aagc_latency_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_aagc_latency_12_8:5;
        RBus_UInt32  res1:27;
    };
}dvbc_reg_aagc_latency_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_integral_cnt_len:5;
        RBus_UInt32  reg_aagc_lock_pga_hit_len:3;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_integral_cnt_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_thd_lock_up_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_thd_lock_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_thd_lock_up_9_8:2;
        RBus_UInt32  reg_thd_lock_dw_5_0:6;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_thd_lock_up_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_thd_lock_dw_9_6:4;
        RBus_UInt32  res1:28;
    };
}dvbc_reg_thd_lock_up_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_thd_up1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_thd_up1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_thd_up1_9_8:2;
        RBus_UInt32  reg_thd_dw1_5_0:6;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_thd_up1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_thd_dw1_9_6:4;
        RBus_UInt32  res1:28;
    };
}dvbc_reg_thd_up1_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_thd_up2:8;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_thd_up2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_thd_dw2:8;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_thd_dw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_gain_step_sum_up_thd:4;
        RBus_UInt32  reg_gain_step_sum_dw_thd:4;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_gain_step_sum_up_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_gain_pulse_space_len:4;
        RBus_UInt32  reg_gain_pulse_hold_len:4;
        RBus_UInt32  res1:24;
    };
}dvbc_reg_gain_pulse_space_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_in_version:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qam_in_version_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qam_mode:3;
        RBus_UInt32  opt_adc_samp_ph:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_qam_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_adc_trunc_bits:2;
        RBus_UInt32  opt_adc_format_sel:1;
        RBus_UInt32  res1:29;
    };
}dvbc_opt_adc_trunc_bits_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_adc_nb_on:1;
        RBus_UInt32  opt_aagc_loop_pol:1;
        RBus_UInt32  opt_rf_aagc_pol:1;
        RBus_UInt32  opt_if_aagc_pol:1;
        RBus_UInt32  opt_aagc_fz:2;
        RBus_UInt32  opt_aagc_s_k_rf_lsb:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_adc_nb_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_aagc_target_amp:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_aagc_target_amp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rf_aagc_max:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_rf_aagc_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rf_aagc_min:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_rf_aagc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_if_aagc_max:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_if_aagc_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_if_aagc_min:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_if_aagc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_aagc_init_level:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_aagc_init_level_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_aagc_s_if_th:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_aagc_s_if_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_aagc_lock_th:3;
        RBus_UInt32  opt_aagc_s_k_rf_msb:4;
        RBus_UInt32  opt_aagc_p_s_sel:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_aagc_lock_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ddc_freq_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_ddc_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ddc_freq_14_8:7;
        RBus_UInt32  opt_spec_inv:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_ddc_freq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ddc_lpf_scaling:3;
        RBus_UInt32  opt_set_spec:1;
        RBus_UInt32  opt_auto_spec:1;
        RBus_UInt32  specmode:1;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_ddc_lpf_scaling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_notch1_on:1;
        RBus_UInt32  opt_notch2_on:1;
        RBus_UInt32  opt_notch3_on:1;
        RBus_UInt32  notch_wr_stb:1;
        RBus_UInt32  notch_sel:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_notch1_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  notch_coeff_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_notch_coeff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  notch_coeff_10_8:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  notch_coeff_r:11;
        RBus_UInt32  res2:13;
    };
}dvbc_notch_coeff_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_dagc_max:4;
        RBus_UInt32  opt_dagc_min:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_dagc_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_initial_cr_freq_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_initial_cr_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_initial_cr_freq_12_8:5;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_initial_cr_freq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ki_cr_out_max:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_ki_cr_out_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_cr_acq_pwr_th:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_cr_acq_pwr_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_cr_metric_dd_max:5;
        RBus_UInt32  opt_cr_metric_dd_sat_ctrl:1;
        RBus_UInt32  opt_bn_cr_blank_en:1;
        RBus_UInt32  opt_bn_cr_bw_half_en:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_cr_metric_dd_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_bn_eq_stop_en:1;
        RBus_UInt32  opt_bn_cr_blank_c2:1;
        RBus_UInt32  bn_cond1_en:1;
        RBus_UInt32  bn_cond2_en:1;
        RBus_UInt32  bn_cond3_en:1;
        RBus_UInt32  bn_cond4_en:1;
        RBus_UInt32  bn_cond5_en:1;
        RBus_UInt32  opt_bn_cond_and_or:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_bn_eq_stop_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_bn_mse_th:4;
        RBus_UInt32  opt_bn_ek_amp_th:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_bn_mse_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_bn_cond1_cnt_th:3;
        RBus_UInt32  opt_bn_cond2_cnt_th:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_bn_cond1_cnt_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_bn_err_acc_th:6;
        RBus_UInt32  opt_ak_pow_in_cr_sel:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_bn_err_acc_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ak_dd_cr_pow_th:6;
        RBus_UInt32  opt_ak_pow_in:1;
        RBus_UInt32  opt_tr_ld_gard_on:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_ak_dd_cr_pow_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_tr_deci_ratio_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_tr_deci_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_tr_deci_ratio_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_tr_deci_ratio_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_tr_deci_ratio_23_16:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_tr_deci_ratio_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ki_tr_out_max:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_ki_tr_out_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_posteq_tr_mm_max_dd:5;
        RBus_UInt32  opt_tr_metric_dd_sat_ctrl:1;
        RBus_UInt32  opt_interl_tr_on:1;
        RBus_UInt32  opt_preeq_tr_phase_inv:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_posteq_tr_mm_max_dd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_posteq_tr_sel:1;
        RBus_UInt32  opt_posteq_tr_acq_sel:1;
        RBus_UInt32  opt_preeq_tr_guard_on:1;
        RBus_UInt32  opt_mk_uk_min:5;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_posteq_tr_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_cond4_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_mse_th_cond4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_cond4_9_8:2;
        RBus_UInt32  opt_tr_ld_out_th:5;
        RBus_UInt32  res1:25;
    };
}dvbc_opt_mse_th_cond4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_cond5_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_mse_th_cond5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_cond5_9_8:2;
        RBus_UInt32  opt_fsm_final_state:4;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_mse_th_cond5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_cond6_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_mse_th_cond6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_cond6_9_8:2;
        RBus_UInt32  opt_cr_cnt:4;
        RBus_UInt32  opt_fsm_cond7_sel:1;
        RBus_UInt32  res1:25;
    };
}dvbc_opt_mse_th_cond6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rst_state0_on:1;
        RBus_UInt32  opt_retry_on:1;
        RBus_UInt32  rt_cond1_en:1;
        RBus_UInt32  rt_cond2_en:1;
        RBus_UInt32  rt_cond3_en:1;
        RBus_UInt32  rt_cond4_en:1;
        RBus_UInt32  rt_cond5_en:1;
        RBus_UInt32  opt_rt_cond_and_or:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_rst_state0_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rt_loop_cnt_min:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_rt_loop_cnt_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rt_mse_th:6;
        RBus_UInt32  rt_cond6_en:1;
        RBus_UInt32  rt_cond7_en:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_rt_mse_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_dd_eq_bound:6;
        RBus_UInt32  opt_u_iq_exp:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_dd_eq_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_sign_data:1;
        RBus_UInt32  opt_sign_data_exp_fff:2;
        RBus_UInt32  opt_sign_data_exp_fbf:2;
        RBus_UInt32  opt_rca_lvl_sqrt_2_0:3;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_sign_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rca_lvl_sqrt_10_3:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_sign_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_circle:6;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_circle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  opt_leakage_size_exp:3;
        RBus_UInt32  opt_leakage_f_u_en_dd:1;
        RBus_UInt32  opt_leakage_f_u_en_acq:1;
        RBus_UInt32  res2:24;
    };
}dvbc_opt_leakage_size_exp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_leakage_period:7;
        RBus_UInt32  opt_leakage_f_amp_en:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_leakage_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_amp_thr1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_mse_amp_thr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_amp_thr2:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_mse_amp_thr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_max_amp0:5;
        RBus_UInt32  opt_leakage_f_amp_exp_en:1;
        RBus_UInt32  opt_leakage_f_amp_exp:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_max_amp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_max_amp1:5;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_max_amp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_max_amp2:5;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_max_amp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_eq_acq1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_mse_th_eq_acq1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_eq_acq2:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_mse_th_eq_acq2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff_acq0:3;
        RBus_UInt32  opt_u_fff_acq1:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff_acq0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff_acq2:3;
        RBus_UInt32  opt_u_fbf_acq0:2;
        RBus_UInt32  opt_u_fbf_acq1:2;
        RBus_UInt32  res1:25;
    };
}dvbc_opt_u_fff_acq2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fbf_acq2:2;
        RBus_UInt32  opt_u_fbf2_acq0:2;
        RBus_UInt32  opt_u_fbf2_acq1:2;
        RBus_UInt32  opt_u_fbf2_acq2:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_u_fbf_acq2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_eq_dd1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_mse_th_eq_dd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_mse_th_eq_dd2:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_mse_th_eq_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff_dd0:3;
        RBus_UInt32  opt_u_fff_dd1:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff_dd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff_dd2:3;
        RBus_UInt32  opt_u_fbf_dd0:2;
        RBus_UInt32  opt_u_fbf_dd1:2;
        RBus_UInt32  res1:25;
    };
}dvbc_opt_u_fff_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fbf_dd2:2;
        RBus_UInt32  opt_u_fbf2_dd0:2;
        RBus_UInt32  opt_u_fbf2_dd1:2;
        RBus_UInt32  opt_u_fbf2_dd2:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_u_fbf_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_eq_upd_period_fff:7;
        RBus_UInt32  opt_eq_upd_period_fff_en:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_eq_upd_period_fff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_eq_upd_period_fbf:7;
        RBus_UInt32  opt_eq_upd_period_fbf_en:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_eq_upd_period_fbf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_max_err_period:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_max_err_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_clip_mo_period:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_clip_mo_period_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_signal_sel1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_db_signal_sel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_signal_sel2:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_db_signal_sel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_tst_ena_sel:3;
        RBus_UInt32  res1:29;
    };
}dvbc_opt_db_tst_ena_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_signal_gate_sel1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_db_signal_gate_sel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_signal_gate_sel1_8:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_db_signal_gate_sel1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_signal_gate_sel2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_db_signal_gate_sel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_signal_gate_sel2_8:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_db_signal_gate_sel2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_fsm_state1:4;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_db_fsm_state1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_tr_ld_th1:4;
        RBus_UInt32  opt_db_cr_ld_th1:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_db_tr_ld_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_mse_th1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_db_mse_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_cond1_en1:1;
        RBus_UInt32  db_cond2_en1:1;
        RBus_UInt32  db_cond3_en1:1;
        RBus_UInt32  db_cond4_en1:1;
        RBus_UInt32  db_cond5_en1:1;
        RBus_UInt32  db_cond6_en1:1;
        RBus_UInt32  db_cond7_en1:1;
        RBus_UInt32  opt_db_cond_and_or1:1;
        RBus_UInt32  res1:24;
    };
}dvbc_db_cond1_en1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_tr_ld_th2:4;
        RBus_UInt32  opt_db_cr_ld_th2:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_db_tr_ld_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_mse_th2:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_db_mse_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_db_fsm_state2:4;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_db_fsm_state2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_cond1_en2:1;
        RBus_UInt32  db_cond2_en2:1;
        RBus_UInt32  db_cond3_en2:1;
        RBus_UInt32  db_cond4_en2:1;
        RBus_UInt32  db_cond5_en2:1;
        RBus_UInt32  db_cond6_en2:1;
        RBus_UInt32  db_cond7_en2:1;
        RBus_UInt32  opt_db_cond_and_or2:1;
        RBus_UInt32  res1:24;
    };
}dvbc_db_cond1_en2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxmf_wr_stb:1;
        RBus_UInt32  rxmf_sel:4;
        RBus_UInt32  rxmf_coeff_2_0:3;
        RBus_UInt32  res1:24;
    };
}dvbc_rxmf_wr_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rxmf_coeff_9_3:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  rxmf_coeff_r:10;
        RBus_UInt32  res2:14;
    };
}dvbc_rxmf_wr_stb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  interp_wr_stb:1;
        RBus_UInt32  interp_sel:5;
        RBus_UInt32  interp_coeff_1_0:2;
        RBus_UInt32  res1:24;
    };
}dvbc_interp_wr_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  interp_coeff_9_2:8;
        RBus_UInt32  interp_coeff_r:10;
        RBus_UInt32  res1:14;
    };
}dvbc_interp_wr_stb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_wr_stb:1;
        RBus_UInt32  ddc_sel:4;
        RBus_UInt32  ddc_coeff_2_0:3;
        RBus_UInt32  res1:24;
    };
}dvbc_ddc_wr_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_coeff_9_3:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  ddc_coeff_r:10;
        RBus_UInt32  res2:14;
    };
}dvbc_ddc_wr_stb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_wr_stb:1;
        RBus_UInt32  fsm_sel:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  opt_fsm_fix_ste_end:4;
        RBus_UInt32  opt_fsm_fix_ste_en:1;
        RBus_UInt32  res2:19;
    };
}dvbc_fsm_wr_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_7_0:8;
        RBus_UInt32  fsm_word_r_7_0:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_15_8:8;
        RBus_UInt32  fsm_word_r_15_8:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_23_16:8;
        RBus_UInt32  fsm_word_r_23_16:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_31_24:8;
        RBus_UInt32  fsm_word_r_31_24:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_39_32:8;
        RBus_UInt32  fsm_word_r_39_32:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_47_40:8;
        RBus_UInt32  fsm_word_r_47_40:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_55_48:8;
        RBus_UInt32  fsm_word_r_55_48:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_63_56:8;
        RBus_UInt32  fsm_word_r_63_56:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_71_64:8;
        RBus_UInt32  fsm_word_r_71_64:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_79_72:8;
        RBus_UInt32  fsm_word_r_79_72:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_87_80:8;
        RBus_UInt32  fsm_word_r_87_80:8;
        RBus_UInt32  res1:16;
    };
}dvbc_fsm_word_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tst_out_stb:1;
        RBus_UInt32  res1:31;
    };
}dvbc_tst_out_stb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tst_out1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_tst_out1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tst_out1_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_tst_out1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tst_out2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_tst_out2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tst_out2_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_tst_out2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo1_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo1_23_16:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo1_31_24:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo2_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo2_18_16:3;
        RBus_UInt32  res1:29;
    };
}dvbc_inrx_mo2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo3_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo3_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo3_23_16:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_mo3_31_24:8;
        RBus_UInt32  res1:24;
    };
}dvbc_inrx_mo3_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rt_fsm_state1:4;
        RBus_UInt32  opt_rt_fsm_state2:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_rt_fsm_state1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rt_fsm_cnt_min:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_rt_fsm_cnt_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rt_fsm_f_cnt_min:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_rt_fsm_f_cnt_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_aagc_cnt_th:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_aagc_cnt_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rt_fsm_f_j_cnt_min:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_rt_fsm_f_j_cnt_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rst_tr:1;
        RBus_UInt32  opt_rst_cr:1;
        RBus_UInt32  opt_rst_txiq:1;
        RBus_UInt32  rt_cond8_en:1;
        RBus_UInt32  rt_cond8_sel:2;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_rst_tr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_mse_th_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_ld_mse_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_mse_th_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_ld_mse_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_cr_th:5;
        RBus_UInt32  res1:27;
    };
}dvbc_ld_cr_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tr_th:5;
        RBus_UInt32  res1:27;
    };
}dvbc_ld_tr_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_period_th_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_ld_period_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_period_th_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_ld_period_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_max_err_th_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_ld_max_err_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_max_err_th_14_8:7;
        RBus_UInt32  res1:25;
    };
}dvbc_ld_max_err_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_outer_th:8;
        RBus_UInt32  res1:24;
    };
}dvbc_ld_outer_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_cond_en:8;
        RBus_UInt32  res1:24;
    };
}dvbc_ld_cond_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_cond_and:1;
        RBus_UInt32  outer_ld:1;
        RBus_UInt32  res1:30;
    };
}dvbc_ld_cond_and_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_cr_metric_dd_sel:2;
        RBus_UInt32  opt_cr_dd_cordic_sat:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_cr_dd_cordic_max:4;
        RBus_UInt32  res2:24;
    };
}dvbc_opt_cr_metric_dd_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ak_pow_on:3;
        RBus_UInt32  res1:29;
    };
}dvbc_opt_ak_pow_on_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_pn_bn_err_ratio:4;
        RBus_UInt32  opt_pn_det_th:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_pn_bn_err_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_main_tap_sel:5;
        RBus_UInt32  opt_u_fff2_acq0:3;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_main_tap_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff2_acq1:3;
        RBus_UInt32  opt_u_fff2_acq2:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff2_acq1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff3_acq0:3;
        RBus_UInt32  opt_u_fff3_acq1:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff3_acq0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff3_acq2:3;
        RBus_UInt32  opt_u_fff4_acq0:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff3_acq2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff4_acq1:3;
        RBus_UInt32  opt_u_fff4_acq2:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff4_acq1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fbf3_acq0:2;
        RBus_UInt32  opt_u_fbf3_acq1:2;
        RBus_UInt32  opt_u_fbf3_acq2:2;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fbf3_acq0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fbf4_acq0:2;
        RBus_UInt32  opt_u_fbf4_acq1:2;
        RBus_UInt32  opt_u_fbf4_acq2:2;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fbf4_acq0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff2_dd0:3;
        RBus_UInt32  opt_u_fff2_dd1:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff2_dd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff2_dd2:3;
        RBus_UInt32  opt_u_fff3_dd0:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff2_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff3_dd1:3;
        RBus_UInt32  opt_u_fff3_dd2:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff3_dd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff4_dd0:3;
        RBus_UInt32  opt_u_fff4_dd1:3;
        RBus_UInt32  res1:26;
    };
}dvbc_opt_u_fff4_dd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fff4_dd2:3;
        RBus_UInt32  opt_u_fbf3_dd0:2;
        RBus_UInt32  opt_u_fbf3_dd1:2;
        RBus_UInt32  res1:25;
    };
}dvbc_opt_u_fff4_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_u_fbf3_dd2:2;
        RBus_UInt32  opt_u_fbf4_dd0:2;
        RBus_UInt32  opt_u_fbf4_dd1:2;
        RBus_UInt32  opt_u_fbf4_dd2:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_u_fbf3_dd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fbf_nb_num:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_fbf_nb_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bn_cond6_en:1;
        RBus_UInt32  bn_cond7_en:1;
        RBus_UInt32  res1:30;
    };
}dvbc_bn_cond6_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_bn_cond6_cnt_th:3;
        RBus_UInt32  opt_bn_eq_amp_th:4;
        RBus_UInt32  res1:25;
    };
}dvbc_opt_bn_cond6_cnt_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tap_i_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_eq_tap_i_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tap_i_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_eq_tap_i_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tap_q_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_eq_tap_q_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tap_q_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_eq_tap_q_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page1_rwb0_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page1_rwb0_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page1_rwb1_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page1_rwb1_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page1_rwb2_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page1_rwb2_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page1_rwb3_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page1_rwb3_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page1_rwb4_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page1_rwb4_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page1_rwb5_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page1_rwb5_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page1_rwb6_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page1_rwb6_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page1_rwb7_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page1_rwb7_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_aagc_iq_swap:1;
        RBus_UInt32  opt_adc_clip_iq:2;
        RBus_UInt32  opt_adc_im:1;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_aagc_iq_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_dcc1_en:1;
        RBus_UInt32  opt_fe_dcc1_max_en:1;
        RBus_UInt32  opt_fe_dcc1_max:3;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_fe_dcc1_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_dcc1_u_acq:4;
        RBus_UInt32  opt_fe_dcc1_u_trk:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_dcc1_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_dcc1_u:2;
        RBus_UInt32  opt_fe_dcc1_upd:2;
        RBus_UInt32  opt_fe_dcc1_clr:2;
        RBus_UInt32  opt_fe_dcc1_acq_dly_prd:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_dcc1_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_aagc_loop_in:3;
        RBus_UInt32  ddc_zif_mode:1;
        RBus_UInt32  zif_spec_inv_on:1;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_aagc_loop_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_dcc2_en:1;
        RBus_UInt32  opt_fe_dcc2_max_en:1;
        RBus_UInt32  opt_fe_dcc2_max:3;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_fe_dcc2_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_dcc2_u_acq:4;
        RBus_UInt32  opt_fe_dcc2_u_trk:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_dcc2_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_dcc2_u:2;
        RBus_UInt32  opt_fe_dcc2_upd:2;
        RBus_UInt32  opt_fe_dcc2_clr:2;
        RBus_UInt32  opt_fe_dcc2_acq_dly_prd:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_dcc2_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_dcc3_en:1;
        RBus_UInt32  opt_fe_dcc3_max_en:1;
        RBus_UInt32  opt_fe_dcc3_max:3;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_fe_dcc3_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_dcc3_u_acq:4;
        RBus_UInt32  opt_fe_dcc3_u_trk:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_dcc3_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_dcc3_u:2;
        RBus_UInt32  opt_fe_dcc3_upd:2;
        RBus_UInt32  opt_fe_dcc3_clr:2;
        RBus_UInt32  opt_fe_dcc3_acq_dly_prd:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_dcc3_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_iq_u:2;
        RBus_UInt32  opt_fe_iq_upd:2;
        RBus_UInt32  opt_fe_iq_clr:2;
        RBus_UInt32  opt_fe_iq_acq_dly_prd:2;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_iq_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_iqamp_en:1;
        RBus_UInt32  opt_fe_iqamp_max_en:1;
        RBus_UInt32  opt_fe_iqamp_max:3;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_fe_iqamp_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_iqamp_u_acq:4;
        RBus_UInt32  opt_fe_iqamp_u_trk:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_iqamp_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_iqamp_manu_en:1;
        RBus_UInt32  opt_fe_iqamp_manu_6_0:7;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_iqamp_manu_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_iqamp_manu_9_7:3;
        RBus_UInt32  res1:29;
    };
}dvbc_opt_fe_iqamp_manu_en_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_iqph_en:1;
        RBus_UInt32  opt_fe_iqph_max_en:1;
        RBus_UInt32  opt_fe_iqph_max:3;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_fe_iqph_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_iqph_u_acq:4;
        RBus_UInt32  opt_fe_iqph_u_trk:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_iqph_u_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_iqph_manu_en:1;
        RBus_UInt32  opt_fe_iqph_manu_6_0:7;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_fe_iqph_manu_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fe_iqph_manu_9_7:3;
        RBus_UInt32  res1:29;
    };
}dvbc_opt_fe_iqph_manu_en_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsm_word_90_88:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  fsm_word_r_90_88:3;
        RBus_UInt32  res2:21;
    };
}dvbc_fsm_word_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  version_dvbc_outer:8;
        RBus_UInt32  res1:24;
    };
}dvbc_version_dvbc_outer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_freeze:1;
        RBus_UInt32  opt_mismatch_bit_num:2;
        RBus_UInt32  opt_acq_mode:2;
        RBus_UInt32  opt_trk_mode:2;
        RBus_UInt32  synclost:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_freeze_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_deintl_i:7;
        RBus_UInt32  res1:25;
    };
}dvbc_opt_deintl_i_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_deintl_m:5;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_deintl_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_rsd_disable:1;
        RBus_UInt32  opt_nocorr:1;
        RBus_UInt32  opt_errmode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  opt_ber_rd_strobe:1;
        RBus_UInt32  res2:24;
    };
}dvbc_opt_rsd_disable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ber_en:1;
        RBus_UInt32  opt_ber_hold:1;
        RBus_UInt32  opt_dis_auto_mode:1;
        RBus_UInt32  opt_volume:3;
        RBus_UInt32  ber_en_stb:1;
        RBus_UInt32  res1:25;
    };
}dvbc_opt_ber_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ber_count_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_ber_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ber_count_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ber_count_20_16:5;
        RBus_UInt32  block_count_18_16:3;
        RBus_UInt32  res1:24;
    };
}dvbc_ber_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  block_count_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_block_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  block_count_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_block_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  corr_count_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_corr_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  corr_count_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_corr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uncorr_count_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_uncorr_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uncorr_count_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_uncorr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_desc_disable:1;
        RBus_UInt32  desc_syncstate:1;
        RBus_UInt32  opt_no_reinvert:1;
        RBus_UInt32  opt_fix_tei:1;
        RBus_UInt32  opt_syncmode:2;
        RBus_UInt32  opt_fix_invsync:1;
        RBus_UInt32  opt_dvbc_smooth:1;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_desc_disable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_ckoutpar:1;
        RBus_UInt32  opt_ckout_pwr:1;
        RBus_UInt32  opt_serial:1;
        RBus_UInt32  opt_sync_byte:1;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_ckoutpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_cdiv_ph0:4;
        RBus_UInt32  opt_cdiv_ph1:4;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_cdiv_ph0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  bist_done:1;
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  bist_sta_stb:1;
        RBus_UInt32  res3:24;
    };
}dvbc_opt_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_ber_blk_count:8;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_ber_blk_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_ber_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_ber_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_ber_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_ber_count_2:5;
        RBus_UInt32  auto_blk_count_2:3;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_ber_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_blk_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_blk_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_blk_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_blk_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_corr_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_corr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_corr_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_corr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_uncorr_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_uncorr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_uncorr_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_auto_uncorr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page2_rw21_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page2_rw21_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page2_rw22_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page2_rw22_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page2_rw23_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page2_rw23_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page2_rw24_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page2_rw24_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page2_rw25_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page2_rw25_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page2_rw26_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page2_rw26_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page2_rw27_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page2_rw27_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  page2_rw28_reserved:8;
        RBus_UInt32  res1:24;
    };
}dvbc_page2_rw28_reserved_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_dsp_first_out_idx_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_dsp_first_out_idx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_dsp_first_out_idx_12_8:5;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_dsp_first_out_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fft_abs_out:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_fft_abs_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fft_dsp_read:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_fft_dsp_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_pos_frq_slot_sr_en_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_pos_frq_slot_sr_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_pos_frq_slot_sr_en_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_pos_frq_slot_sr_en_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fft_out_mode:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_fft_out_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_papd_papr_sel:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_papd_papr_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_fft_output_acc_num:4;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_fft_output_acc_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_nbd_tdft_idx:4;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_nbd_tdft_idx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_slot_avg_ratio_sel:4;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_slot_avg_ratio_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_comp_slot_avg_thd_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_comp_slot_avg_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_comp_slot_avg_thd_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_comp_slot_avg_thd_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dvbc_opt_first_tone_crit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dvbc_opt_neg_frq_comp_crit_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dvbc_opt_pos_frq_comp_crit_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_pos_frq_max_sr_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_pos_frq_max_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_pos_frq_max_sr_11_8:4;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_pos_frq_max_sr_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_pos_frq_min_sr_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_pos_frq_min_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_pos_frq_min_sr_11_8:4;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_pos_frq_min_sr_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_cnt_stop_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_cnt_stop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_cnt_stop_12_8:5;
        RBus_UInt32  res1:27;
    };
}dvbc_opt_qamd_cnt_stop_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn0_max_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn0_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn0_max_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn0_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn0_min_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn0_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn0_min_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn0_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn1_max_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn1_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn1_max_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn1_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn1_min_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn1_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn1_min_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn1_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn2_max_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn2_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn2_max_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn2_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn2_min_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn2_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn2_min_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn2_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn3_max_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn3_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn3_max_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn3_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn3_min_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn3_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn3_min_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn3_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn4_max_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn4_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn4_max_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn4_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn4_min_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn4_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn4_min_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn4_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn5_max_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn5_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn5_max_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn5_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn5_min_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_eqp_zn5_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_eqp_zn5_min_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_eqp_zn5_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_self_reset:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_qamd_self_reset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_start_state:4;
        RBus_UInt32  res1:28;
    };
}dvbc_opt_qamd_start_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_128qam_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_thd_128qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_128qam_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_thd_128qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_16qam_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_thd_16qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_16qam_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_thd_16qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_256qam_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_thd_256qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_256qam_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_thd_256qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_32qam_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_thd_32qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_32qam_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_thd_32qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_64qam_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_opt_qamd_thd_64qam_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_qamd_thd_64qam_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_opt_qamd_thd_64qam_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_start_srs_nbd:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_start_srs_nbd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nbd_tdft_out_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_nbd_tdft_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nbd_tdft_out_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_nbd_tdft_out_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_max_sr_ini_cnt:5;
        RBus_UInt32  res1:27;
    };
}dvbc_min_max_sr_ini_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_val_0_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_tone_max_val_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_val_0_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_tone_max_val_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_val_1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_tone_max_val_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_val_1_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_tone_max_val_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_val_2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_tone_max_val_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_val_2_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_tone_max_val_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_idx_0_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_tone_max_idx_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_idx_0_11_8:4;
        RBus_UInt32  res1:28;
    };
}dvbc_pos_tone_max_idx_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_idx_1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_tone_max_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_idx_1_11_8:4;
        RBus_UInt32  res1:28;
    };
}dvbc_pos_tone_max_idx_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_idx_2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_tone_max_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qam_con_bit_det:4;
        RBus_UInt32  res1:28;
    };
}dvbc_qam_con_bit_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn0_cdf_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn0_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn0_cdf_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_qamd_rv_zn0_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn1_cdf_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn1_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn1_cdf_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_qamd_rv_zn1_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn2_cdf_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn2_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn2_cdf_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_qamd_rv_zn2_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn3_cdf_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn3_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn3_cdf_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_qamd_rv_zn3_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn4_cdf_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn4_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn4_cdf_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_qamd_rv_zn4_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn5_cdf_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn5_cdf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn5_cdf_9_8:2;
        RBus_UInt32  res1:30;
    };
}dvbc_qamd_rv_zn5_cdf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif0_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif0_10_8:3;
        RBus_UInt32  res1:29;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif1_10_8:3;
        RBus_UInt32  res1:29;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif2_10_8:3;
        RBus_UInt32  res1:29;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif3_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif3_10_8:3;
        RBus_UInt32  res1:29;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif4_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qamd_rv_zn_cdf_acc_dif4_10_8:3;
        RBus_UInt32  res1:29;
    };
}dvbc_qamd_rv_zn_cdf_acc_dif4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_qamd_done:1;
        RBus_UInt32  res1:31;
    };
}dvbc_reg_qamd_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  solt_avg_pow_dif_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_solt_avg_pow_dif_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  solt_avg_pow_dif_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_solt_avg_pow_dif_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  solt_avg_pow_max_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_solt_avg_pow_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  solt_avg_pow_max_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_solt_avg_pow_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  solt_avg_pow_min_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_solt_avg_pow_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  solt_avg_pow_min_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_solt_avg_pow_min_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srs_nbd_done:1;
        RBus_UInt32  res1:31;
    };
}dvbc_srs_nbd_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_tone_max_idx_2_11_8:4;
        RBus_UInt32  res1:28;
    };
}dvbc_pos_tone_max_idx_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_slot_avg_val_0_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_slot_avg_val_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_slot_avg_val_0_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_slot_avg_val_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_rom_bist_out01_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rom_bist_out_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_rom_bist_out01_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rom_bist_out_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_rom_bist_out01_23_16:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rom_bist_out_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_rom_bist_out01_31_24:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rom_bist_out_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_rom_bist_out01_39_32:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rom_bist_out_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_rom_bist_out01_47_40:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rom_bist_out_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inrx_rom_bist_out01_51_48:4;
        RBus_UInt32  res1:28;
    };
}dvbc_rom_bist_out_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  version_oc_outer:8;
        RBus_UInt32  res1:24;
    };
}dvbc_version_oc_outer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vt_lsb_hd:1;
        RBus_UInt32  punct_sync_mode:1;
        RBus_UInt32  soft_reset_ff:1;
        RBus_UInt32  zero_metrics:1;
        RBus_UInt32  force_vt_en:1;
        RBus_UInt32  manu_skip:1;
        RBus_UInt32  puncsync_lost:1;
        RBus_UInt32  viterbi_rd_stb:1;
        RBus_UInt32  res1:24;
    };
}dvbc_vt_lsb_hd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  td_acq_mode:4;
        RBus_UInt32  td_trk_mode:4;
        RBus_UInt32  res1:24;
    };
}dvbc_td_acq_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vt_window_len:8;
        RBus_UInt32  res1:24;
    };
}dvbc_vt_window_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trk_gap:8;
        RBus_UInt32  res1:24;
    };
}dvbc_trk_gap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vt_ber_count_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_vt_ber_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vt_ber_count_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_vt_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intl_chg_flag:1;
        RBus_UInt32  fs_sync_lost:1;
        RBus_UInt32  puncsync_en:1;
        RBus_UInt32  derand_dis:1;
        RBus_UInt32  deintl_mode:2;
        RBus_UInt32  res1:26;
    };
}dvbc_intl_chg_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs_mismatch_acq:4;
        RBus_UInt32  fs_mismatch_trk:4;
        RBus_UInt32  res1:24;
    };
}dvbc_fs_mismatch_acq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fs_acq_mode:4;
        RBus_UInt32  fs_trk_mode:4;
        RBus_UInt32  res1:24;
    };
}dvbc_fs_acq_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intl_mode_chg_cnt:4;
        RBus_UInt32  res1:28;
    };
}dvbc_intl_mode_chg_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trailer_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_trailer_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trailer_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_trailer_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trailer_2:8;
        RBus_UInt32  res1:24;
    };
}dvbc_trailer_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trailer_3:8;
        RBus_UInt32  res1:24;
    };
}dvbc_trailer_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inval_sync_cnt:4;
        RBus_UInt32  fs_acq_fail:4;
        RBus_UInt32  res1:24;
    };
}dvbc_inval_sync_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  deintl_auto_cfg:4;
        RBus_UInt32  detintl_man_cfg:4;
        RBus_UInt32  res1:24;
    };
}dvbc_deintl_auto_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_rsd_disable:1;
        RBus_UInt32  oc_nocorr:1;
        RBus_UInt32  oc_errmode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  ber_rd_strobe:1;
        RBus_UInt32  res2:24;
    };
}dvbc_oc_rsd_disable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_ber_en:1;
        RBus_UInt32  rs_bert_hold:1;
        RBus_UInt32  oc_dis_auto_mode:1;
        RBus_UInt32  oc_volume:3;
        RBus_UInt32  ber_en_stat:1;
        RBus_UInt32  ber_en_stb_oc:1;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_ber_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rs_ber_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rs_ber_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rs_ber_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rs_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rs_ber_count_2:5;
        RBus_UInt32  rs_block_count_2:3;
        RBus_UInt32  res1:24;
    };
}dvbc_rs_ber_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rs_block_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rs_block_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rs_block_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rs_block_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rs_corr_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rs_corr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rs_corr_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rs_corr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rs_uncorr_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rs_uncorr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rs_uncorr_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_rs_uncorr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_cdiv_ph0:4;
        RBus_UInt32  oc_cdiv_ph1:4;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_cdiv_ph0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_serial:1;
        RBus_UInt32  oc_ckoutpar:1;
        RBus_UInt32  oc_ckout_pwr:1;
        RBus_UInt32  res1:29;
    };
}dvbc_oc_ckout_pwr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_mpeg_sync_mode:1;
        RBus_UInt32  oc_repla_sd_en:1;
        RBus_UInt32  oc_tei_sd_err_en:1;
        RBus_UInt32  oc_tei_rs_err_en:1;
        RBus_UInt32  oc_set_mpeg_err:2;
        RBus_UInt32  oc_mpeg_rs_en:1;
        RBus_UInt32  oc_sync_byte:1;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_mpeg_sync_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_mpeg_trk_mode:4;
        RBus_UInt32  oc_mpeg_acq_mode:2;
        RBus_UInt32  oc_mpeg_mismatch:2;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_mpeg_mismatch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_mpeg_test_volume:3;
        RBus_UInt32  oc_mpeg_dis_auto_mode:1;
        RBus_UInt32  oc_mpeg_pert_hold:1;
        RBus_UInt32  oc_mpeg_pert_en:1;
        RBus_UInt32  oc_mpeg_per_rd_strobe:1;
        RBus_UInt32  res1:25;
    };
}dvbc_oc_mpeg_per_rd_strobe_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_syndm_err_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_syndm_err_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_syndm_err_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_syndm_err_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_mpeg_pkt_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_mpeg_pkt_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_mpeg_pkt_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_mpeg_pkt_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_mpeg_pkt_count_2:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_mpeg_pkt_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_mpeg_acq2_k_mode:4;
        RBus_UInt32  oc_mpeg_acq2_n_mode:4;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_mpeg_acq2_k_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_ber_blk_count:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_ber_blk_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_ber_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_ber_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_ber_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_ber_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_ber_count_2:5;
        RBus_UInt32  oc_auto_blk_count_2:3;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_ber_count_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_blk_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_blk_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_blk_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_blk_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_corr_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_corr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_corr_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_corr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_uncorr_count_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_uncorr_count_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_auto_uncorr_count_1:8;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_auto_uncorr_count_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_bist_mode_cablerx_fftbuf:1;
        RBus_UInt32  reg_bist_mode_cablerx_deint:1;
        RBus_UInt32  reg_bist_mode_cablerx_out:1;
        RBus_UInt32  reg_bist_mode_debugdma:1;
        RBus_UInt32  reg_bist_mode_cablerx_bn:1;
        RBus_UInt32  res2:26;
    };
}dvbc_oc_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_drf_bist_mode_cablerx_fftbuf:1;
        RBus_UInt32  reg_drf_bist_mode_cablerx_deint:1;
        RBus_UInt32  reg_drf_bist_mode_cablerx_out:1;
        RBus_UInt32  reg_drf_bist_mode_debugdma:1;
        RBus_UInt32  reg_drf_bist_mode_cablerx_bn:1;
        RBus_UInt32  res2:26;
    };
}dvbc_oc_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_drf_test_resume_cablerx_fftbuf:1;
        RBus_UInt32  reg_drf_test_resume_cablerx_deint:1;
        RBus_UInt32  reg_drf_test_resume_cablerx_out:1;
        RBus_UInt32  reg_drf_test_resume_debugdma:1;
        RBus_UInt32  reg_drf_test_resume_cablerx_bn:1;
        RBus_UInt32  res2:26;
    };
}dvbc_oc_drf_resume_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mbist_cablerx_dvs:4;
        RBus_UInt32  res1:28;
    };
}dvbc_oc_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mbist_cablerx_dvse:1;
        RBus_UInt32  res1:31;
    };
}dvbc_oc_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mbist_cablerx_ls:1;
        RBus_UInt32  res1:31;
    };
}dvbc_oc_bist_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  bist_done_cablerx_fftbuf:1;
        RBus_UInt32  bist_done_cablerx_deint:1;
        RBus_UInt32  bist_done_cablerx_out:1;
        RBus_UInt32  bist_done_debugdma:1;
        RBus_UInt32  bist_done_cablerx_bn:1;
        RBus_UInt32  res2:26;
    };
}dvbc_oc_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  bist_fail_cablerx_fftbuf:1;
        RBus_UInt32  bist_fail_cablerx_deint:1;
        RBus_UInt32  bist_fail_cablerx_out:1;
        RBus_UInt32  bist_fail_debugdma:1;
        RBus_UInt32  bist_fail_cablerx_bn:1;
        RBus_UInt32  res2:26;
    };
}dvbc_oc_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  drf_bist_done_cablerx_fftbuf:1;
        RBus_UInt32  drf_bist_done_cablerx_deint:1;
        RBus_UInt32  drf_bist_done_cablerx_out:1;
        RBus_UInt32  drf_bist_done_debugdma:1;
        RBus_UInt32  drf_bist_done_cablerx_bn:1;
        RBus_UInt32  res2:26;
    };
}dvbc_oc_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  drf_bist_fail_cablerx_fftbuf:1;
        RBus_UInt32  drf_bist_fail_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_cablerx_out:1;
        RBus_UInt32  drf_bist_fail_debugdma:1;
        RBus_UInt32  drf_bist_fail_cablerx_bn:1;
        RBus_UInt32  res2:26;
    };
}dvbc_oc_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0_cablerx_fftbuf:1;
        RBus_UInt32  bist_fail_1_cablerx_fftbuf:1;
        RBus_UInt32  bist_fail_2_cablerx_fftbuf:1;
        RBus_UInt32  bist_fail_3_cablerx_fftbuf:1;
        RBus_UInt32  res1:28;
    };
}dvbc_oc_bist_fftbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0_cablerx_deint:1;
        RBus_UInt32  bist_fail_1_cablerx_deint:1;
        RBus_UInt32  bist_fail_2_cablerx_deint:1;
        RBus_UInt32  bist_fail_3_cablerx_deint:1;
        RBus_UInt32  bist_fail_4_cablerx_deint:1;
        RBus_UInt32  bist_fail_5_cablerx_deint:1;
        RBus_UInt32  bist_fail_6_cablerx_deint:1;
        RBus_UInt32  bist_fail_7_cablerx_deint:1;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_bist_deint_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0_cablerx_out:1;
        RBus_UInt32  bist_fail_1_cablerx_out:1;
        RBus_UInt32  bist_fail_2_cablerx_out:1;
        RBus_UInt32  bist_fail_0_cablerx_bn:1;
        RBus_UInt32  bist_fail_1_cablerx_bn:1;
        RBus_UInt32  res1:27;
    };
}dvbc_oc_bist_out_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_0_cablerx_fftbuf:1;
        RBus_UInt32  drf_bist_fail_1_cablerx_fftbuf:1;
        RBus_UInt32  drf_bist_fail_2_cablerx_fftbuf:1;
        RBus_UInt32  drf_bist_fail_3_cablerx_fftbuf:1;
        RBus_UInt32  res1:28;
    };
}dvbc_oc_drf_bist_fftbuf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_0_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_1_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_2_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_3_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_4_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_5_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_6_cablerx_deint:1;
        RBus_UInt32  drf_bist_fail_7_cablerx_deint:1;
        RBus_UInt32  res1:24;
    };
}dvbc_oc_drf_bist_deint_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_0_cablerx_out:1;
        RBus_UInt32  drf_bist_fail_1_cablerx_out:1;
        RBus_UInt32  drf_bist_fail_2_cablerx_out:1;
        RBus_UInt32  drf_bist_fail_0_cablerx_bn:1;
        RBus_UInt32  drf_bist_fail_1_cablerx_bn:1;
        RBus_UInt32  res1:27;
    };
}dvbc_oc_drf_bist_out_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  drf_start_pause_cablerx_fftbuf:1;
        RBus_UInt32  drf_start_pause_cablerx_deint:1;
        RBus_UInt32  drf_start_pause_cablerx_out:1;
        RBus_UInt32  drf_start_pause_debugdma:1;
        RBus_UInt32  drf_start_pause_cablerx_bn:1;
        RBus_UInt32  res2:26;
    };
}dvbc_oc_bist_drf_start_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_demod_debugdma_waterlvl:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_demod_debugdma_blen:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_demod_debugdma_circular_num:4;
        RBus_UInt32  reg_dtv_debugdma_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_dump_adc_dagc_sel:1;
        RBus_UInt32  res4:7;
    };
}dvbc_debugdma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_demod_debugdma_startaddr:29;
        RBus_UInt32  res1:3;
    };
}dvbc_debugdma_start_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_demod_debugdma_endaddr:29;
        RBus_UInt32  res1:3;
    };
}dvbc_debugdma_end_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debugdma_overflow_ro:1;
        RBus_UInt32  debugdma_underflow_ro:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_debugdma_overflow_clr:1;
        RBus_UInt32  reg_debugdma_underflow_clr:1;
        RBus_UInt32  res2:26;
    };
}dvbc_debugdma_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_r_psd_start:1;
        RBus_UInt32  res1:31;
    };
}dvbc_psd_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_r_psd_ctrl1:8;
        RBus_UInt32  reg_r_psd_ctrl2:8;
        RBus_UInt32  reg_r_psd_dco:8;
        RBus_UInt32  reg_r_psd_scale:8;
    };
}dvbc_psd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psd_pwr:16;
        RBus_UInt32  psd_done:1;
        RBus_UInt32  res1:15;
    };
}dvbc_psd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srs_deint_sram_mode:1;
        RBus_UInt32  srs_deint_sram_fw_mode:1;
        RBus_UInt32  res1:30;
    };
}dvbc_srs_deint_sram_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_slot_avg_val_1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_slot_avg_val_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_slot_avg_val_1_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_slot_avg_val_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_slot_avg_val_2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_slot_avg_val_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_slot_avg_val_2_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_pos_slot_avg_val_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_val_0_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_tone_max_val_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_val_0_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_tone_max_val_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_val_1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_tone_max_val_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_val_1_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_tone_max_val_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_val_2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_tone_max_val_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_val_2_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_tone_max_val_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_idx_0_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_tone_max_idx_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_idx_0_11_8:4;
        RBus_UInt32  res1:28;
    };
}dvbc_neg_tone_max_idx_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_idx_1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_tone_max_idx_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_idx_1_11_8:4;
        RBus_UInt32  res1:28;
    };
}dvbc_neg_tone_max_idx_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_idx_2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_tone_max_idx_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_tone_max_idx_2_11_8:4;
        RBus_UInt32  res1:28;
    };
}dvbc_neg_tone_max_idx_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_slot_avg_val_0_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_slot_avg_val_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_slot_avg_val_0_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_slot_avg_val_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_slot_avg_val_1_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_slot_avg_val_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_slot_avg_val_1_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_slot_avg_val_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_slot_avg_val_2_7_0:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_slot_avg_val_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_slot_avg_val_2_15_8:8;
        RBus_UInt32  res1:24;
    };
}dvbc_neg_slot_avg_val_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_srs_input_sel:1;
        RBus_UInt32  res1:31;
    };
}dvbc_opt_srs_input_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_window_en_on:3;
        RBus_UInt32  bnm_on:1;
        RBus_UInt32  bnm_mu:2;
        RBus_UInt32  bnm_cnt_rst:1;
        RBus_UInt32  res1:25;
    };
}dvbc_bnm_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_window1_en_ratio:5;
        RBus_UInt32  res1:27;
    };
}dvbc_bnm_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_window1_en_num:8;
        RBus_UInt32  res1:24;
    };
}dvbc_bnm_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_window2_en_ratio:5;
        RBus_UInt32  res1:27;
    };
}dvbc_bnm_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_window2_en_num:6;
        RBus_UInt32  res1:26;
    };
}dvbc_bnm_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_window3_en_ratio:5;
        RBus_UInt32  res1:27;
    };
}dvbc_bnm_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_null_en_ratio:5;
        RBus_UInt32  res1:27;
    };
}dvbc_bnm_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_detect_cnt:32;
    };
}dvbc_bnm_detect_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnm_clip_cnt:32;
    };
}dvbc_bnm_clip_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_start_prd:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  opt_prd_pha_sel_thd:5;
        RBus_UInt32  res2:23;
    };
}dvbc_prd_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_prd_thd_h:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_prd_thd_l:15;
        RBus_UInt32  res2:1;
    };
}dvbc_prd_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_prd_level1:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_prd_level2:15;
        RBus_UInt32  res2:1;
    };
}dvbc_prd_thd_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_prd_level3:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  opt_prd_level4:15;
        RBus_UInt32  res2:1;
    };
}dvbc_prd_thd_3_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_prd_level5:15;
        RBus_UInt32  res1:17;
    };
}dvbc_prd_thd_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_prd_comp_idx1:8;
        RBus_UInt32  opt_prd_comp_idx2:8;
        RBus_UInt32  opt_prd_comp_idx3:8;
        RBus_UInt32  opt_prd_comp_idx4:8;
    };
}dvbc_prd_comp_idx_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_prd_err_term_l:12;
        RBus_UInt32  opt_prd_err_term_h:12;
        RBus_UInt32  opt_prd_err_alpha:3;
        RBus_UInt32  res1:5;
    };
}dvbc_prd_err_RBUS;




#endif 


#endif 
