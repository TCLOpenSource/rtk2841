/**
* @file rbusFCIC_TOPReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_FCIC_TOP_REG_H_
#define _RBUS_FCIC_TOP_REG_H_

#include "rbus_types.h"



//  FCIC_TOP Register Address
#define  FCIC_TOP_FCIC_CTRL_1                                                    0x1802EC00
#define  FCIC_TOP_FCIC_CTRL_1_reg_addr                                           "0xB802EC00"
#define  FCIC_TOP_FCIC_CTRL_1_reg                                                0xB802EC00
#define  FCIC_TOP_FCIC_CTRL_1_inst_addr                                          "0x0000"
#define  set_FCIC_TOP_FCIC_CTRL_1_reg(data)                                      (*((volatile unsigned int*)FCIC_TOP_FCIC_CTRL_1_reg)=data)
#define  get_FCIC_TOP_FCIC_CTRL_1_reg                                            (*((volatile unsigned int*)FCIC_TOP_FCIC_CTRL_1_reg))
#define  FCIC_TOP_FCIC_CTRL_1_fcic_rbus_if_enable_shift                          (0)
#define  FCIC_TOP_FCIC_CTRL_1_fcic_rbus_if_enable_mask                           (0x00000003)
#define  FCIC_TOP_FCIC_CTRL_1_fcic_rbus_if_enable(data)                          (0x00000003&(data))
#define  FCIC_TOP_FCIC_CTRL_1_get_fcic_rbus_if_enable(data)                      (0x00000003&(data))

#define  FCIC_TOP_FCIC_CRTL_2                                                    0x1802EC04
#define  FCIC_TOP_FCIC_CRTL_2_reg_addr                                           "0xB802EC04"
#define  FCIC_TOP_FCIC_CRTL_2_reg                                                0xB802EC04
#define  FCIC_TOP_FCIC_CRTL_2_inst_addr                                          "0x0001"
#define  set_FCIC_TOP_FCIC_CRTL_2_reg(data)                                      (*((volatile unsigned int*)FCIC_TOP_FCIC_CRTL_2_reg)=data)
#define  get_FCIC_TOP_FCIC_CRTL_2_reg                                            (*((volatile unsigned int*)FCIC_TOP_FCIC_CRTL_2_reg))
#define  FCIC_TOP_FCIC_CRTL_2_auto_detect_result_shift                           (7)
#define  FCIC_TOP_FCIC_CRTL_2_auto_detect_en_shift                               (6)
#define  FCIC_TOP_FCIC_CRTL_2_user_timing_sel_shift                              (4)
#define  FCIC_TOP_FCIC_CRTL_2_multi_access_en_shift                              (3)
#define  FCIC_TOP_FCIC_CRTL_2_flash_write_enable_shift                           (2)
#define  FCIC_TOP_FCIC_CRTL_2_eeprom_write_enable_shift                          (0)
#define  FCIC_TOP_FCIC_CRTL_2_auto_detect_result_mask                            (0x00000180)
#define  FCIC_TOP_FCIC_CRTL_2_auto_detect_en_mask                                (0x00000040)
#define  FCIC_TOP_FCIC_CRTL_2_user_timing_sel_mask                               (0x00000030)
#define  FCIC_TOP_FCIC_CRTL_2_multi_access_en_mask                               (0x00000008)
#define  FCIC_TOP_FCIC_CRTL_2_flash_write_enable_mask                            (0x00000004)
#define  FCIC_TOP_FCIC_CRTL_2_eeprom_write_enable_mask                           (0x00000001)
#define  FCIC_TOP_FCIC_CRTL_2_auto_detect_result(data)                           (0x00000180&((data)<<7))
#define  FCIC_TOP_FCIC_CRTL_2_auto_detect_en(data)                               (0x00000040&((data)<<6))
#define  FCIC_TOP_FCIC_CRTL_2_user_timing_sel(data)                              (0x00000030&((data)<<4))
#define  FCIC_TOP_FCIC_CRTL_2_multi_access_en(data)                              (0x00000008&((data)<<3))
#define  FCIC_TOP_FCIC_CRTL_2_flash_write_enable(data)                           (0x00000004&((data)<<2))
#define  FCIC_TOP_FCIC_CRTL_2_eeprom_write_enable(data)                          (0x00000001&(data))
#define  FCIC_TOP_FCIC_CRTL_2_get_auto_detect_result(data)                       ((0x00000180&(data))>>7)
#define  FCIC_TOP_FCIC_CRTL_2_get_auto_detect_en(data)                           ((0x00000040&(data))>>6)
#define  FCIC_TOP_FCIC_CRTL_2_get_user_timing_sel(data)                          ((0x00000030&(data))>>4)
#define  FCIC_TOP_FCIC_CRTL_2_get_multi_access_en(data)                          ((0x00000008&(data))>>3)
#define  FCIC_TOP_FCIC_CRTL_2_get_flash_write_enable(data)                       ((0x00000004&(data))>>2)
#define  FCIC_TOP_FCIC_CRTL_2_get_eeprom_write_enable(data)                      (0x00000001&(data))

#define  FCIC_TOP_FCIC_EEPROM_IF_1                                               0x1802EC08
#define  FCIC_TOP_FCIC_EEPROM_IF_1_reg_addr                                      "0xB802EC08"
#define  FCIC_TOP_FCIC_EEPROM_IF_1_reg                                           0xB802EC08
#define  FCIC_TOP_FCIC_EEPROM_IF_1_inst_addr                                     "0x0002"
#define  set_FCIC_TOP_FCIC_EEPROM_IF_1_reg(data)                                 (*((volatile unsigned int*)FCIC_TOP_FCIC_EEPROM_IF_1_reg)=data)
#define  get_FCIC_TOP_FCIC_EEPROM_IF_1_reg                                       (*((volatile unsigned int*)FCIC_TOP_FCIC_EEPROM_IF_1_reg))
#define  FCIC_TOP_FCIC_EEPROM_IF_1_cfg_rdata_shift                               (12)
#define  FCIC_TOP_FCIC_EEPROM_IF_1_cfg_addr_shift                                (0)
#define  FCIC_TOP_FCIC_EEPROM_IF_1_cfg_rdata_mask                                (0x000FF000)
#define  FCIC_TOP_FCIC_EEPROM_IF_1_cfg_addr_mask                                 (0x00000FFF)
#define  FCIC_TOP_FCIC_EEPROM_IF_1_cfg_rdata(data)                               (0x000FF000&((data)<<12))
#define  FCIC_TOP_FCIC_EEPROM_IF_1_cfg_addr(data)                                (0x00000FFF&(data))
#define  FCIC_TOP_FCIC_EEPROM_IF_1_get_cfg_rdata(data)                           ((0x000FF000&(data))>>12)
#define  FCIC_TOP_FCIC_EEPROM_IF_1_get_cfg_addr(data)                            (0x00000FFF&(data))

#define  FCIC_TOP_FCIC_EEPROM_IF_2                                               0x1802EC0C
#define  FCIC_TOP_FCIC_EEPROM_IF_2_reg_addr                                      "0xB802EC0C"
#define  FCIC_TOP_FCIC_EEPROM_IF_2_reg                                           0xB802EC0C
#define  FCIC_TOP_FCIC_EEPROM_IF_2_inst_addr                                     "0x0003"
#define  set_FCIC_TOP_FCIC_EEPROM_IF_2_reg(data)                                 (*((volatile unsigned int*)FCIC_TOP_FCIC_EEPROM_IF_2_reg)=data)
#define  get_FCIC_TOP_FCIC_EEPROM_IF_2_reg                                       (*((volatile unsigned int*)FCIC_TOP_FCIC_EEPROM_IF_2_reg))
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_3_shift                              (24)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_2_shift                              (16)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_1_shift                              (8)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_0_shift                              (0)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_3_mask                               (0xFF000000)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_2_mask                               (0x00FF0000)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_1_mask                               (0x0000FF00)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_0_mask                               (0x000000FF)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_3(data)                              (0xFF000000&((data)<<24))
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_2(data)                              (0x00FF0000&((data)<<16))
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_1(data)                              (0x0000FF00&((data)<<8))
#define  FCIC_TOP_FCIC_EEPROM_IF_2_cfg_data_0(data)                              (0x000000FF&(data))
#define  FCIC_TOP_FCIC_EEPROM_IF_2_get_cfg_data_3(data)                          ((0xFF000000&(data))>>24)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_get_cfg_data_2(data)                          ((0x00FF0000&(data))>>16)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_get_cfg_data_1(data)                          ((0x0000FF00&(data))>>8)
#define  FCIC_TOP_FCIC_EEPROM_IF_2_get_cfg_data_0(data)                          (0x000000FF&(data))

#define  FCIC_TOP_FCIC_FLASH_IF_1                                                0x1802EC10
#define  FCIC_TOP_FCIC_FLASH_IF_1_reg_addr                                       "0xB802EC10"
#define  FCIC_TOP_FCIC_FLASH_IF_1_reg                                            0xB802EC10
#define  FCIC_TOP_FCIC_FLASH_IF_1_inst_addr                                      "0x0004"
#define  set_FCIC_TOP_FCIC_FLASH_IF_1_reg(data)                                  (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_1_reg)=data)
#define  get_FCIC_TOP_FCIC_FLASH_IF_1_reg                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_1_reg))
#define  FCIC_TOP_FCIC_FLASH_IF_1_flash_done_shift                               (17)
#define  FCIC_TOP_FCIC_FLASH_IF_1_flash_addr_shift                               (0)
#define  FCIC_TOP_FCIC_FLASH_IF_1_flash_done_mask                                (0x00020000)
#define  FCIC_TOP_FCIC_FLASH_IF_1_flash_addr_mask                                (0x0001FFFF)
#define  FCIC_TOP_FCIC_FLASH_IF_1_flash_done(data)                               (0x00020000&((data)<<17))
#define  FCIC_TOP_FCIC_FLASH_IF_1_flash_addr(data)                               (0x0001FFFF&(data))
#define  FCIC_TOP_FCIC_FLASH_IF_1_get_flash_done(data)                           ((0x00020000&(data))>>17)
#define  FCIC_TOP_FCIC_FLASH_IF_1_get_flash_addr(data)                           (0x0001FFFF&(data))

#define  FCIC_TOP_FCIC_FLASH_IF_2                                                0x1802EC14
#define  FCIC_TOP_FCIC_FLASH_IF_2_reg_addr                                       "0xB802EC14"
#define  FCIC_TOP_FCIC_FLASH_IF_2_reg                                            0xB802EC14
#define  FCIC_TOP_FCIC_FLASH_IF_2_inst_addr                                      "0x0005"
#define  set_FCIC_TOP_FCIC_FLASH_IF_2_reg(data)                                  (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_2_reg)=data)
#define  get_FCIC_TOP_FCIC_FLASH_IF_2_reg                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_2_reg))
#define  FCIC_TOP_FCIC_FLASH_IF_2_flash_data_0_shift                             (0)
#define  FCIC_TOP_FCIC_FLASH_IF_2_flash_data_0_mask                              (0xFFFFFFFF)
#define  FCIC_TOP_FCIC_FLASH_IF_2_flash_data_0(data)                             (0xFFFFFFFF&(data))
#define  FCIC_TOP_FCIC_FLASH_IF_2_get_flash_data_0(data)                         (0xFFFFFFFF&(data))

#define  FCIC_TOP_FCIC_FLASH_IF_3                                                0x1802EC18
#define  FCIC_TOP_FCIC_FLASH_IF_3_reg_addr                                       "0xB802EC18"
#define  FCIC_TOP_FCIC_FLASH_IF_3_reg                                            0xB802EC18
#define  FCIC_TOP_FCIC_FLASH_IF_3_inst_addr                                      "0x0006"
#define  set_FCIC_TOP_FCIC_FLASH_IF_3_reg(data)                                  (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_3_reg)=data)
#define  get_FCIC_TOP_FCIC_FLASH_IF_3_reg                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_3_reg))
#define  FCIC_TOP_FCIC_FLASH_IF_3_flash_data_1_shift                             (0)
#define  FCIC_TOP_FCIC_FLASH_IF_3_flash_data_1_mask                              (0xFFFFFFFF)
#define  FCIC_TOP_FCIC_FLASH_IF_3_flash_data_1(data)                             (0xFFFFFFFF&(data))
#define  FCIC_TOP_FCIC_FLASH_IF_3_get_flash_data_1(data)                         (0xFFFFFFFF&(data))

#define  FCIC_TOP_FCIC_FLASH_IF_4                                                0x1802EC1C
#define  FCIC_TOP_FCIC_FLASH_IF_4_reg_addr                                       "0xB802EC1C"
#define  FCIC_TOP_FCIC_FLASH_IF_4_reg                                            0xB802EC1C
#define  FCIC_TOP_FCIC_FLASH_IF_4_inst_addr                                      "0x0007"
#define  set_FCIC_TOP_FCIC_FLASH_IF_4_reg(data)                                  (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_4_reg)=data)
#define  get_FCIC_TOP_FCIC_FLASH_IF_4_reg                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_4_reg))
#define  FCIC_TOP_FCIC_FLASH_IF_4_flash_data_2_shift                             (0)
#define  FCIC_TOP_FCIC_FLASH_IF_4_flash_data_2_mask                              (0xFFFFFFFF)
#define  FCIC_TOP_FCIC_FLASH_IF_4_flash_data_2(data)                             (0xFFFFFFFF&(data))
#define  FCIC_TOP_FCIC_FLASH_IF_4_get_flash_data_2(data)                         (0xFFFFFFFF&(data))

#define  FCIC_TOP_FCIC_FLASH_IF_5                                                0x1802EC20
#define  FCIC_TOP_FCIC_FLASH_IF_5_reg_addr                                       "0xB802EC20"
#define  FCIC_TOP_FCIC_FLASH_IF_5_reg                                            0xB802EC20
#define  FCIC_TOP_FCIC_FLASH_IF_5_inst_addr                                      "0x0008"
#define  set_FCIC_TOP_FCIC_FLASH_IF_5_reg(data)                                  (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_5_reg)=data)
#define  get_FCIC_TOP_FCIC_FLASH_IF_5_reg                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_IF_5_reg))
#define  FCIC_TOP_FCIC_FLASH_IF_5_flash_data_3_shift                             (0)
#define  FCIC_TOP_FCIC_FLASH_IF_5_flash_data_3_mask                              (0xFFFFFFFF)
#define  FCIC_TOP_FCIC_FLASH_IF_5_flash_data_3(data)                             (0xFFFFFFFF&(data))
#define  FCIC_TOP_FCIC_FLASH_IF_5_get_flash_data_3(data)                         (0xFFFFFFFF&(data))

#define  FCIC_TOP_FCIC_FLASH_dbg_1                                               0x1802EC24
#define  FCIC_TOP_FCIC_FLASH_dbg_1_reg_addr                                      "0xB802EC24"
#define  FCIC_TOP_FCIC_FLASH_dbg_1_reg                                           0xB802EC24
#define  FCIC_TOP_FCIC_FLASH_dbg_1_inst_addr                                     "0x0009"
#define  set_FCIC_TOP_FCIC_FLASH_dbg_1_reg(data)                                 (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_dbg_1_reg)=data)
#define  get_FCIC_TOP_FCIC_FLASH_dbg_1_reg                                       (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_dbg_1_reg))
#define  FCIC_TOP_FCIC_FLASH_dbg_1_rd_addr_shift                                 (16)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_flash_dbg_rd_en_shift                         (9)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_eep_dbg_rd_en_shift                           (8)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_template_data_mux_shift                       (4)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_flash_dbg_mux_shift                           (0)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_rd_addr_mask                                  (0x7FFF0000)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_flash_dbg_rd_en_mask                          (0x00000200)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_eep_dbg_rd_en_mask                            (0x00000100)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_template_data_mux_mask                        (0x00000070)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_flash_dbg_mux_mask                            (0x0000000F)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_rd_addr(data)                                 (0x7FFF0000&((data)<<16))
#define  FCIC_TOP_FCIC_FLASH_dbg_1_flash_dbg_rd_en(data)                         (0x00000200&((data)<<9))
#define  FCIC_TOP_FCIC_FLASH_dbg_1_eep_dbg_rd_en(data)                           (0x00000100&((data)<<8))
#define  FCIC_TOP_FCIC_FLASH_dbg_1_template_data_mux(data)                       (0x00000070&((data)<<4))
#define  FCIC_TOP_FCIC_FLASH_dbg_1_flash_dbg_mux(data)                           (0x0000000F&(data))
#define  FCIC_TOP_FCIC_FLASH_dbg_1_get_rd_addr(data)                             ((0x7FFF0000&(data))>>16)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_get_flash_dbg_rd_en(data)                     ((0x00000200&(data))>>9)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_get_eep_dbg_rd_en(data)                       ((0x00000100&(data))>>8)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_get_template_data_mux(data)                   ((0x00000070&(data))>>4)
#define  FCIC_TOP_FCIC_FLASH_dbg_1_get_flash_dbg_mux(data)                       (0x0000000F&(data))

#define  FCIC_TOP_FCIC_FLASH_dbg_2                                               0x1802EC28
#define  FCIC_TOP_FCIC_FLASH_dbg_2_reg_addr                                      "0xB802EC28"
#define  FCIC_TOP_FCIC_FLASH_dbg_2_reg                                           0xB802EC28
#define  FCIC_TOP_FCIC_FLASH_dbg_2_inst_addr                                     "0x000A"
#define  set_FCIC_TOP_FCIC_FLASH_dbg_2_reg(data)                                 (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_dbg_2_reg)=data)
#define  get_FCIC_TOP_FCIC_FLASH_dbg_2_reg                                       (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_dbg_2_reg))
#define  FCIC_TOP_FCIC_FLASH_dbg_2_flash_rdata_0_shift                           (0)
#define  FCIC_TOP_FCIC_FLASH_dbg_2_flash_rdata_0_mask                            (0xFFFFFFFF)
#define  FCIC_TOP_FCIC_FLASH_dbg_2_flash_rdata_0(data)                           (0xFFFFFFFF&(data))
#define  FCIC_TOP_FCIC_FLASH_dbg_2_get_flash_rdata_0(data)                       (0xFFFFFFFF&(data))

#define  FCIC_TOP_FCIC_FLASH_dbg_3                                               0x1802EC2C
#define  FCIC_TOP_FCIC_FLASH_dbg_3_reg_addr                                      "0xB802EC2C"
#define  FCIC_TOP_FCIC_FLASH_dbg_3_reg                                           0xB802EC2C
#define  FCIC_TOP_FCIC_FLASH_dbg_3_inst_addr                                     "0x000B"
#define  set_FCIC_TOP_FCIC_FLASH_dbg_3_reg(data)                                 (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_dbg_3_reg)=data)
#define  get_FCIC_TOP_FCIC_FLASH_dbg_3_reg                                       (*((volatile unsigned int*)FCIC_TOP_FCIC_FLASH_dbg_3_reg))
#define  FCIC_TOP_FCIC_FLASH_dbg_3_flash_rdata_1_shift                           (0)
#define  FCIC_TOP_FCIC_FLASH_dbg_3_flash_rdata_1_mask                            (0xFFFFFFFF)
#define  FCIC_TOP_FCIC_FLASH_dbg_3_flash_rdata_1(data)                           (0xFFFFFFFF&(data))
#define  FCIC_TOP_FCIC_FLASH_dbg_3_get_flash_rdata_1(data)                       (0xFFFFFFFF&(data))

#define  FCIC_TOP_FCIC_BIST_MODE                                                 0x1802EC30
#define  FCIC_TOP_FCIC_BIST_MODE_reg_addr                                        "0xB802EC30"
#define  FCIC_TOP_FCIC_BIST_MODE_reg                                             0xB802EC30
#define  FCIC_TOP_FCIC_BIST_MODE_inst_addr                                       "0x000C"
#define  set_FCIC_TOP_FCIC_BIST_MODE_reg(data)                                   (*((volatile unsigned int*)FCIC_TOP_FCIC_BIST_MODE_reg)=data)
#define  get_FCIC_TOP_FCIC_BIST_MODE_reg                                         (*((volatile unsigned int*)FCIC_TOP_FCIC_BIST_MODE_reg))
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_ed_bist_mode_shift                   (7)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_template_bist_mode_shift             (6)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_template_2_bist_mode_shift           (5)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_template_1_bist_mode_shift           (4)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_int_2_bist_mode_shift                (3)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_int_1_bist_mode_shift                (2)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_16728_2_bist_mode_shift              (1)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_16728_1_bist_mode_shift              (0)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_ed_bist_mode_mask                    (0x00000080)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_template_bist_mode_mask              (0x00000040)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_template_2_bist_mode_mask            (0x00000020)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_template_1_bist_mode_mask            (0x00000010)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_int_2_bist_mode_mask                 (0x00000008)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_int_1_bist_mode_mask                 (0x00000004)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_16728_2_bist_mode_mask               (0x00000002)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_16728_1_bist_mode_mask               (0x00000001)
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_ed_bist_mode(data)                   (0x00000080&((data)<<7))
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_template_bist_mode(data)             (0x00000040&((data)<<6))
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_template_2_bist_mode(data)           (0x00000020&((data)<<5))
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_template_1_bist_mode(data)           (0x00000010&((data)<<4))
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_int_2_bist_mode(data)                (0x00000008&((data)<<3))
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_int_1_bist_mode(data)                (0x00000004&((data)<<2))
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_16728_2_bist_mode(data)              (0x00000002&((data)<<1))
#define  FCIC_TOP_FCIC_BIST_MODE_mbist_fcic_16728_1_bist_mode(data)              (0x00000001&(data))
#define  FCIC_TOP_FCIC_BIST_MODE_get_mbist_fcic_ed_bist_mode(data)               ((0x00000080&(data))>>7)
#define  FCIC_TOP_FCIC_BIST_MODE_get_mbist_fcic_template_bist_mode(data)         ((0x00000040&(data))>>6)
#define  FCIC_TOP_FCIC_BIST_MODE_get_mbist_fcic_template_2_bist_mode(data)       ((0x00000020&(data))>>5)
#define  FCIC_TOP_FCIC_BIST_MODE_get_mbist_fcic_template_1_bist_mode(data)       ((0x00000010&(data))>>4)
#define  FCIC_TOP_FCIC_BIST_MODE_get_mbist_fcic_int_2_bist_mode(data)            ((0x00000008&(data))>>3)
#define  FCIC_TOP_FCIC_BIST_MODE_get_mbist_fcic_int_1_bist_mode(data)            ((0x00000004&(data))>>2)
#define  FCIC_TOP_FCIC_BIST_MODE_get_mbist_fcic_16728_2_bist_mode(data)          ((0x00000002&(data))>>1)
#define  FCIC_TOP_FCIC_BIST_MODE_get_mbist_fcic_16728_1_bist_mode(data)          (0x00000001&(data))

#define  FCIC_TOP_FCIC_DRF_MODE                                                  0x1802EC34
#define  FCIC_TOP_FCIC_DRF_MODE_reg_addr                                         "0xB802EC34"
#define  FCIC_TOP_FCIC_DRF_MODE_reg                                              0xB802EC34
#define  FCIC_TOP_FCIC_DRF_MODE_inst_addr                                        "0x000D"
#define  set_FCIC_TOP_FCIC_DRF_MODE_reg(data)                                    (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_MODE_reg)=data)
#define  get_FCIC_TOP_FCIC_DRF_MODE_reg                                          (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_MODE_reg))
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_ed_drf_mode_shift                     (7)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_template_drf_mode_shift               (6)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_template_2_drf_mode_shift             (5)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_template_1_drf_mode_shift             (4)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_int_2_drf_mode_shift                  (3)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_int_1_drf_mode_shift                  (2)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_16728_2_drf_mode_shift                (1)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_16728_1_drf_mode_shift                (0)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_ed_drf_mode_mask                      (0x00000080)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_template_drf_mode_mask                (0x00000040)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_template_2_drf_mode_mask              (0x00000020)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_template_1_drf_mode_mask              (0x00000010)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_int_2_drf_mode_mask                   (0x00000008)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_int_1_drf_mode_mask                   (0x00000004)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_16728_2_drf_mode_mask                 (0x00000002)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_16728_1_drf_mode_mask                 (0x00000001)
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_ed_drf_mode(data)                     (0x00000080&((data)<<7))
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_template_drf_mode(data)               (0x00000040&((data)<<6))
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_template_2_drf_mode(data)             (0x00000020&((data)<<5))
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_template_1_drf_mode(data)             (0x00000010&((data)<<4))
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_int_2_drf_mode(data)                  (0x00000008&((data)<<3))
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_int_1_drf_mode(data)                  (0x00000004&((data)<<2))
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_16728_2_drf_mode(data)                (0x00000002&((data)<<1))
#define  FCIC_TOP_FCIC_DRF_MODE_mbist_fcic_16728_1_drf_mode(data)                (0x00000001&(data))
#define  FCIC_TOP_FCIC_DRF_MODE_get_mbist_fcic_ed_drf_mode(data)                 ((0x00000080&(data))>>7)
#define  FCIC_TOP_FCIC_DRF_MODE_get_mbist_fcic_template_drf_mode(data)           ((0x00000040&(data))>>6)
#define  FCIC_TOP_FCIC_DRF_MODE_get_mbist_fcic_template_2_drf_mode(data)         ((0x00000020&(data))>>5)
#define  FCIC_TOP_FCIC_DRF_MODE_get_mbist_fcic_template_1_drf_mode(data)         ((0x00000010&(data))>>4)
#define  FCIC_TOP_FCIC_DRF_MODE_get_mbist_fcic_int_2_drf_mode(data)              ((0x00000008&(data))>>3)
#define  FCIC_TOP_FCIC_DRF_MODE_get_mbist_fcic_int_1_drf_mode(data)              ((0x00000004&(data))>>2)
#define  FCIC_TOP_FCIC_DRF_MODE_get_mbist_fcic_16728_2_drf_mode(data)            ((0x00000002&(data))>>1)
#define  FCIC_TOP_FCIC_DRF_MODE_get_mbist_fcic_16728_1_drf_mode(data)            (0x00000001&(data))

#define  FCIC_TOP_FCIC_DRF_RESUME                                                0x1802EC38
#define  FCIC_TOP_FCIC_DRF_RESUME_reg_addr                                       "0xB802EC38"
#define  FCIC_TOP_FCIC_DRF_RESUME_reg                                            0xB802EC38
#define  FCIC_TOP_FCIC_DRF_RESUME_inst_addr                                      "0x000E"
#define  set_FCIC_TOP_FCIC_DRF_RESUME_reg(data)                                  (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_RESUME_reg)=data)
#define  get_FCIC_TOP_FCIC_DRF_RESUME_reg                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_RESUME_reg))
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_ed_drf_resume_shift                 (7)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_template_drf_resume_shift           (6)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_template_2_drf_resume_shift         (5)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_template_1_drf_resume_shift         (4)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_int_2_drf_resume_shift              (3)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_int_1_drf_resume_shift              (2)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_16728_2_drf_resume_shift            (1)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_16728_1_drf_resume_shift            (0)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_ed_drf_resume_mask                  (0x00000080)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_template_drf_resume_mask            (0x00000040)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_template_2_drf_resume_mask          (0x00000020)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_template_1_drf_resume_mask          (0x00000010)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_int_2_drf_resume_mask               (0x00000008)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_int_1_drf_resume_mask               (0x00000004)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_16728_2_drf_resume_mask             (0x00000002)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_16728_1_drf_resume_mask             (0x00000001)
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_ed_drf_resume(data)                 (0x00000080&((data)<<7))
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_template_drf_resume(data)           (0x00000040&((data)<<6))
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_template_2_drf_resume(data)         (0x00000020&((data)<<5))
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_template_1_drf_resume(data)         (0x00000010&((data)<<4))
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_int_2_drf_resume(data)              (0x00000008&((data)<<3))
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_int_1_drf_resume(data)              (0x00000004&((data)<<2))
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_16728_2_drf_resume(data)            (0x00000002&((data)<<1))
#define  FCIC_TOP_FCIC_DRF_RESUME_mbist_fcic_16728_1_drf_resume(data)            (0x00000001&(data))
#define  FCIC_TOP_FCIC_DRF_RESUME_get_mbist_fcic_ed_drf_resume(data)             ((0x00000080&(data))>>7)
#define  FCIC_TOP_FCIC_DRF_RESUME_get_mbist_fcic_template_drf_resume(data)       ((0x00000040&(data))>>6)
#define  FCIC_TOP_FCIC_DRF_RESUME_get_mbist_fcic_template_2_drf_resume(data)     ((0x00000020&(data))>>5)
#define  FCIC_TOP_FCIC_DRF_RESUME_get_mbist_fcic_template_1_drf_resume(data)     ((0x00000010&(data))>>4)
#define  FCIC_TOP_FCIC_DRF_RESUME_get_mbist_fcic_int_2_drf_resume(data)          ((0x00000008&(data))>>3)
#define  FCIC_TOP_FCIC_DRF_RESUME_get_mbist_fcic_int_1_drf_resume(data)          ((0x00000004&(data))>>2)
#define  FCIC_TOP_FCIC_DRF_RESUME_get_mbist_fcic_16728_2_drf_resume(data)        ((0x00000002&(data))>>1)
#define  FCIC_TOP_FCIC_DRF_RESUME_get_mbist_fcic_16728_1_drf_resume(data)        (0x00000001&(data))

#define  FCIC_TOP_FCIC_BIST_DONE                                                 0x1802EC3C
#define  FCIC_TOP_FCIC_BIST_DONE_reg_addr                                        "0xB802EC3C"
#define  FCIC_TOP_FCIC_BIST_DONE_reg                                             0xB802EC3C
#define  FCIC_TOP_FCIC_BIST_DONE_inst_addr                                       "0x000F"
#define  set_FCIC_TOP_FCIC_BIST_DONE_reg(data)                                   (*((volatile unsigned int*)FCIC_TOP_FCIC_BIST_DONE_reg)=data)
#define  get_FCIC_TOP_FCIC_BIST_DONE_reg                                         (*((volatile unsigned int*)FCIC_TOP_FCIC_BIST_DONE_reg))
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_ed_bist_done_shift                   (7)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_template_bist_done_shift             (6)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_template_2_bist_done_shift           (5)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_template_1_bist_done_shift           (4)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_int_2_bist_done_shift                (3)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_int_1_bist_done_shift                (2)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_16728_2_bist_done_shift              (1)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_16728_1_bist_done_shift              (0)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_ed_bist_done_mask                    (0x00000080)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_template_bist_done_mask              (0x00000040)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_template_2_bist_done_mask            (0x00000020)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_template_1_bist_done_mask            (0x00000010)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_int_2_bist_done_mask                 (0x00000008)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_int_1_bist_done_mask                 (0x00000004)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_16728_2_bist_done_mask               (0x00000002)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_16728_1_bist_done_mask               (0x00000001)
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_ed_bist_done(data)                   (0x00000080&((data)<<7))
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_template_bist_done(data)             (0x00000040&((data)<<6))
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_template_2_bist_done(data)           (0x00000020&((data)<<5))
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_template_1_bist_done(data)           (0x00000010&((data)<<4))
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_int_2_bist_done(data)                (0x00000008&((data)<<3))
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_int_1_bist_done(data)                (0x00000004&((data)<<2))
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_16728_2_bist_done(data)              (0x00000002&((data)<<1))
#define  FCIC_TOP_FCIC_BIST_DONE_mbist_fcic_16728_1_bist_done(data)              (0x00000001&(data))
#define  FCIC_TOP_FCIC_BIST_DONE_get_mbist_fcic_ed_bist_done(data)               ((0x00000080&(data))>>7)
#define  FCIC_TOP_FCIC_BIST_DONE_get_mbist_fcic_template_bist_done(data)         ((0x00000040&(data))>>6)
#define  FCIC_TOP_FCIC_BIST_DONE_get_mbist_fcic_template_2_bist_done(data)       ((0x00000020&(data))>>5)
#define  FCIC_TOP_FCIC_BIST_DONE_get_mbist_fcic_template_1_bist_done(data)       ((0x00000010&(data))>>4)
#define  FCIC_TOP_FCIC_BIST_DONE_get_mbist_fcic_int_2_bist_done(data)            ((0x00000008&(data))>>3)
#define  FCIC_TOP_FCIC_BIST_DONE_get_mbist_fcic_int_1_bist_done(data)            ((0x00000004&(data))>>2)
#define  FCIC_TOP_FCIC_BIST_DONE_get_mbist_fcic_16728_2_bist_done(data)          ((0x00000002&(data))>>1)
#define  FCIC_TOP_FCIC_BIST_DONE_get_mbist_fcic_16728_1_bist_done(data)          (0x00000001&(data))

#define  FCIC_TOP_FCIC_DRF_DONE                                                  0x1802EC40
#define  FCIC_TOP_FCIC_DRF_DONE_reg_addr                                         "0xB802EC40"
#define  FCIC_TOP_FCIC_DRF_DONE_reg                                              0xB802EC40
#define  FCIC_TOP_FCIC_DRF_DONE_inst_addr                                        "0x0010"
#define  set_FCIC_TOP_FCIC_DRF_DONE_reg(data)                                    (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_DONE_reg)=data)
#define  get_FCIC_TOP_FCIC_DRF_DONE_reg                                          (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_DONE_reg))
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_ed_drf_done_shift                     (7)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_template_drf_done_shift               (6)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_template_2_drf_done_shift             (5)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_template_1_drf_done_shift             (4)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_int_2_drf_done_shift                  (3)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_int_1_drf_done_shift                  (2)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_16728_2_drf_done_shift                (1)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_16728_1_drf_done_shift                (0)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_ed_drf_done_mask                      (0x00000080)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_template_drf_done_mask                (0x00000040)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_template_2_drf_done_mask              (0x00000020)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_template_1_drf_done_mask              (0x00000010)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_int_2_drf_done_mask                   (0x00000008)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_int_1_drf_done_mask                   (0x00000004)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_16728_2_drf_done_mask                 (0x00000002)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_16728_1_drf_done_mask                 (0x00000001)
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_ed_drf_done(data)                     (0x00000080&((data)<<7))
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_template_drf_done(data)               (0x00000040&((data)<<6))
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_template_2_drf_done(data)             (0x00000020&((data)<<5))
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_template_1_drf_done(data)             (0x00000010&((data)<<4))
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_int_2_drf_done(data)                  (0x00000008&((data)<<3))
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_int_1_drf_done(data)                  (0x00000004&((data)<<2))
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_16728_2_drf_done(data)                (0x00000002&((data)<<1))
#define  FCIC_TOP_FCIC_DRF_DONE_mbist_fcic_16728_1_drf_done(data)                (0x00000001&(data))
#define  FCIC_TOP_FCIC_DRF_DONE_get_mbist_fcic_ed_drf_done(data)                 ((0x00000080&(data))>>7)
#define  FCIC_TOP_FCIC_DRF_DONE_get_mbist_fcic_template_drf_done(data)           ((0x00000040&(data))>>6)
#define  FCIC_TOP_FCIC_DRF_DONE_get_mbist_fcic_template_2_drf_done(data)         ((0x00000020&(data))>>5)
#define  FCIC_TOP_FCIC_DRF_DONE_get_mbist_fcic_template_1_drf_done(data)         ((0x00000010&(data))>>4)
#define  FCIC_TOP_FCIC_DRF_DONE_get_mbist_fcic_int_2_drf_done(data)              ((0x00000008&(data))>>3)
#define  FCIC_TOP_FCIC_DRF_DONE_get_mbist_fcic_int_1_drf_done(data)              ((0x00000004&(data))>>2)
#define  FCIC_TOP_FCIC_DRF_DONE_get_mbist_fcic_16728_2_drf_done(data)            ((0x00000002&(data))>>1)
#define  FCIC_TOP_FCIC_DRF_DONE_get_mbist_fcic_16728_1_drf_done(data)            (0x00000001&(data))

#define  FCIC_TOP_FCIC_BIST_Fail_0                                               0x1802EC44
#define  FCIC_TOP_FCIC_BIST_Fail_0_reg_addr                                      "0xB802EC44"
#define  FCIC_TOP_FCIC_BIST_Fail_0_reg                                           0xB802EC44
#define  FCIC_TOP_FCIC_BIST_Fail_0_inst_addr                                     "0x0011"
#define  set_FCIC_TOP_FCIC_BIST_Fail_0_reg(data)                                 (*((volatile unsigned int*)FCIC_TOP_FCIC_BIST_Fail_0_reg)=data)
#define  get_FCIC_TOP_FCIC_BIST_Fail_0_reg                                       (*((volatile unsigned int*)FCIC_TOP_FCIC_BIST_Fail_0_reg))
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_int_2_bist_fail_shift              (22)
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_int_1_bist_fail_shift              (16)
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_16728_2_bist_fail_shift            (8)
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_16728_1_bist_fail_shift            (0)
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_int_2_bist_fail_mask               (0x0FC00000)
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_int_1_bist_fail_mask               (0x003F0000)
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_16728_2_bist_fail_mask             (0x0000FF00)
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_16728_1_bist_fail_mask             (0x000000FF)
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_int_2_bist_fail(data)              (0x0FC00000&((data)<<22))
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_int_1_bist_fail(data)              (0x003F0000&((data)<<16))
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_16728_2_bist_fail(data)            (0x0000FF00&((data)<<8))
#define  FCIC_TOP_FCIC_BIST_Fail_0_mbist_fcic_16728_1_bist_fail(data)            (0x000000FF&(data))
#define  FCIC_TOP_FCIC_BIST_Fail_0_get_mbist_fcic_int_2_bist_fail(data)          ((0x0FC00000&(data))>>22)
#define  FCIC_TOP_FCIC_BIST_Fail_0_get_mbist_fcic_int_1_bist_fail(data)          ((0x003F0000&(data))>>16)
#define  FCIC_TOP_FCIC_BIST_Fail_0_get_mbist_fcic_16728_2_bist_fail(data)        ((0x0000FF00&(data))>>8)
#define  FCIC_TOP_FCIC_BIST_Fail_0_get_mbist_fcic_16728_1_bist_fail(data)        (0x000000FF&(data))

#define  FCIC_TOP_FCIC_BIST_Fail_1                                               0x1802EC48
#define  FCIC_TOP_FCIC_BIST_Fail_1_reg_addr                                      "0xB802EC48"
#define  FCIC_TOP_FCIC_BIST_Fail_1_reg                                           0xB802EC48
#define  FCIC_TOP_FCIC_BIST_Fail_1_inst_addr                                     "0x0012"
#define  set_FCIC_TOP_FCIC_BIST_Fail_1_reg(data)                                 (*((volatile unsigned int*)FCIC_TOP_FCIC_BIST_Fail_1_reg)=data)
#define  get_FCIC_TOP_FCIC_BIST_Fail_1_reg                                       (*((volatile unsigned int*)FCIC_TOP_FCIC_BIST_Fail_1_reg))
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_ed_bist_fail_shift                 (23)
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_template_bist_fail_shift           (16)
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_template_2_bist_fail_shift         (8)
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_template_1_bist_fail_shift         (0)
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_ed_bist_fail_mask                  (0x00800000)
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_template_bist_fail_mask            (0x007F0000)
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_template_2_bist_fail_mask          (0x0000FF00)
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_template_1_bist_fail_mask          (0x000000FF)
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_ed_bist_fail(data)                 (0x00800000&((data)<<23))
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_template_bist_fail(data)           (0x007F0000&((data)<<16))
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_template_2_bist_fail(data)         (0x0000FF00&((data)<<8))
#define  FCIC_TOP_FCIC_BIST_Fail_1_mbist_fcic_template_1_bist_fail(data)         (0x000000FF&(data))
#define  FCIC_TOP_FCIC_BIST_Fail_1_get_mbist_fcic_ed_bist_fail(data)             ((0x00800000&(data))>>23)
#define  FCIC_TOP_FCIC_BIST_Fail_1_get_mbist_fcic_template_bist_fail(data)       ((0x007F0000&(data))>>16)
#define  FCIC_TOP_FCIC_BIST_Fail_1_get_mbist_fcic_template_2_bist_fail(data)     ((0x0000FF00&(data))>>8)
#define  FCIC_TOP_FCIC_BIST_Fail_1_get_mbist_fcic_template_1_bist_fail(data)     (0x000000FF&(data))

#define  FCIC_TOP_FCIC_DRF_Fail_0                                                0x1802EC4C
#define  FCIC_TOP_FCIC_DRF_Fail_0_reg_addr                                       "0xB802EC4C"
#define  FCIC_TOP_FCIC_DRF_Fail_0_reg                                            0xB802EC4C
#define  FCIC_TOP_FCIC_DRF_Fail_0_inst_addr                                      "0x0013"
#define  set_FCIC_TOP_FCIC_DRF_Fail_0_reg(data)                                  (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_Fail_0_reg)=data)
#define  get_FCIC_TOP_FCIC_DRF_Fail_0_reg                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_Fail_0_reg))
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_int_2_drf_fail_shift                (22)
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_int_1_drf_fail_shift                (16)
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_16728_2_drf_fail_shift              (8)
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_16728_1_drf_fail_shift              (0)
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_int_2_drf_fail_mask                 (0x0FC00000)
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_int_1_drf_fail_mask                 (0x003F0000)
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_16728_2_drf_fail_mask               (0x0000FF00)
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_16728_1_drf_fail_mask               (0x000000FF)
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_int_2_drf_fail(data)                (0x0FC00000&((data)<<22))
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_int_1_drf_fail(data)                (0x003F0000&((data)<<16))
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_16728_2_drf_fail(data)              (0x0000FF00&((data)<<8))
#define  FCIC_TOP_FCIC_DRF_Fail_0_mbist_fcic_16728_1_drf_fail(data)              (0x000000FF&(data))
#define  FCIC_TOP_FCIC_DRF_Fail_0_get_mbist_fcic_int_2_drf_fail(data)            ((0x0FC00000&(data))>>22)
#define  FCIC_TOP_FCIC_DRF_Fail_0_get_mbist_fcic_int_1_drf_fail(data)            ((0x003F0000&(data))>>16)
#define  FCIC_TOP_FCIC_DRF_Fail_0_get_mbist_fcic_16728_2_drf_fail(data)          ((0x0000FF00&(data))>>8)
#define  FCIC_TOP_FCIC_DRF_Fail_0_get_mbist_fcic_16728_1_drf_fail(data)          (0x000000FF&(data))

#define  FCIC_TOP_FCIC_DRF_Fail_1                                                0x1802EC50
#define  FCIC_TOP_FCIC_DRF_Fail_1_reg_addr                                       "0xB802EC50"
#define  FCIC_TOP_FCIC_DRF_Fail_1_reg                                            0xB802EC50
#define  FCIC_TOP_FCIC_DRF_Fail_1_inst_addr                                      "0x0014"
#define  set_FCIC_TOP_FCIC_DRF_Fail_1_reg(data)                                  (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_Fail_1_reg)=data)
#define  get_FCIC_TOP_FCIC_DRF_Fail_1_reg                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_Fail_1_reg))
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_ed_drf_fail_shift                   (23)
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_template_drf_fail_shift             (16)
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_template_2_drf_fail_shift           (8)
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_template_1_drf_fail_shift           (0)
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_ed_drf_fail_mask                    (0x00800000)
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_template_drf_fail_mask              (0x007F0000)
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_template_2_drf_fail_mask            (0x0000FF00)
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_template_1_drf_fail_mask            (0x000000FF)
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_ed_drf_fail(data)                   (0x00800000&((data)<<23))
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_template_drf_fail(data)             (0x007F0000&((data)<<16))
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_template_2_drf_fail(data)           (0x0000FF00&((data)<<8))
#define  FCIC_TOP_FCIC_DRF_Fail_1_mbist_fcic_template_1_drf_fail(data)           (0x000000FF&(data))
#define  FCIC_TOP_FCIC_DRF_Fail_1_get_mbist_fcic_ed_drf_fail(data)               ((0x00800000&(data))>>23)
#define  FCIC_TOP_FCIC_DRF_Fail_1_get_mbist_fcic_template_drf_fail(data)         ((0x007F0000&(data))>>16)
#define  FCIC_TOP_FCIC_DRF_Fail_1_get_mbist_fcic_template_2_drf_fail(data)       ((0x0000FF00&(data))>>8)
#define  FCIC_TOP_FCIC_DRF_Fail_1_get_mbist_fcic_template_1_drf_fail(data)       (0x000000FF&(data))

#define  FCIC_TOP_FCIC_DRF_Pause                                                 0x1802EC54
#define  FCIC_TOP_FCIC_DRF_Pause_reg_addr                                        "0xB802EC54"
#define  FCIC_TOP_FCIC_DRF_Pause_reg                                             0xB802EC54
#define  FCIC_TOP_FCIC_DRF_Pause_inst_addr                                       "0x0015"
#define  set_FCIC_TOP_FCIC_DRF_Pause_reg(data)                                   (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_Pause_reg)=data)
#define  get_FCIC_TOP_FCIC_DRF_Pause_reg                                         (*((volatile unsigned int*)FCIC_TOP_FCIC_DRF_Pause_reg))
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_ed_drf_pause_shift                   (7)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_template_drf_pause_shift             (6)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_template_2_drf_pause_shift           (5)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_template_1_drf_pause_shift           (4)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_int_2_drf_pause_shift                (3)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_int_1_drf_pause_shift                (2)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_16728_2_drf_pause_shift              (1)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_16728_1_drf_pause_shift              (0)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_ed_drf_pause_mask                    (0x00000080)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_template_drf_pause_mask              (0x00000040)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_template_2_drf_pause_mask            (0x00000020)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_template_1_drf_pause_mask            (0x00000010)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_int_2_drf_pause_mask                 (0x00000008)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_int_1_drf_pause_mask                 (0x00000004)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_16728_2_drf_pause_mask               (0x00000002)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_16728_1_drf_pause_mask               (0x00000001)
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_ed_drf_pause(data)                   (0x00000080&((data)<<7))
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_template_drf_pause(data)             (0x00000040&((data)<<6))
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_template_2_drf_pause(data)           (0x00000020&((data)<<5))
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_template_1_drf_pause(data)           (0x00000010&((data)<<4))
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_int_2_drf_pause(data)                (0x00000008&((data)<<3))
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_int_1_drf_pause(data)                (0x00000004&((data)<<2))
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_16728_2_drf_pause(data)              (0x00000002&((data)<<1))
#define  FCIC_TOP_FCIC_DRF_Pause_mbist_fcic_16728_1_drf_pause(data)              (0x00000001&(data))
#define  FCIC_TOP_FCIC_DRF_Pause_get_mbist_fcic_ed_drf_pause(data)               ((0x00000080&(data))>>7)
#define  FCIC_TOP_FCIC_DRF_Pause_get_mbist_fcic_template_drf_pause(data)         ((0x00000040&(data))>>6)
#define  FCIC_TOP_FCIC_DRF_Pause_get_mbist_fcic_template_2_drf_pause(data)       ((0x00000020&(data))>>5)
#define  FCIC_TOP_FCIC_DRF_Pause_get_mbist_fcic_template_1_drf_pause(data)       ((0x00000010&(data))>>4)
#define  FCIC_TOP_FCIC_DRF_Pause_get_mbist_fcic_int_2_drf_pause(data)            ((0x00000008&(data))>>3)
#define  FCIC_TOP_FCIC_DRF_Pause_get_mbist_fcic_int_1_drf_pause(data)            ((0x00000004&(data))>>2)
#define  FCIC_TOP_FCIC_DRF_Pause_get_mbist_fcic_16728_2_drf_pause(data)          ((0x00000002&(data))>>1)
#define  FCIC_TOP_FCIC_DRF_Pause_get_mbist_fcic_16728_1_drf_pause(data)          (0x00000001&(data))

#define  FCIC_TOP_FCIC_RME_0                                                     0x1802EC58
#define  FCIC_TOP_FCIC_RME_0_reg_addr                                            "0xB802EC58"
#define  FCIC_TOP_FCIC_RME_0_reg                                                 0xB802EC58
#define  FCIC_TOP_FCIC_RME_0_inst_addr                                           "0x0016"
#define  set_FCIC_TOP_FCIC_RME_0_reg(data)                                       (*((volatile unsigned int*)FCIC_TOP_FCIC_RME_0_reg)=data)
#define  get_FCIC_TOP_FCIC_RME_0_reg                                             (*((volatile unsigned int*)FCIC_TOP_FCIC_RME_0_reg))
#define  FCIC_TOP_FCIC_RME_0_testrwm_shift                                       (31)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_5_shift                              (27)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_4_shift                              (26)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_3_shift                              (25)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_2_shift                              (24)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_1_shift                              (23)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_0_shift                              (22)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_5_shift                              (21)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_4_shift                              (20)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_3_shift                              (19)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_2_shift                              (18)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_1_shift                              (17)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_0_shift                              (16)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_7_shift                            (15)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_6_shift                            (14)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_5_shift                            (13)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_4_shift                            (12)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_3_shift                            (11)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_2_shift                            (10)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_1_shift                            (9)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_0_shift                            (8)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_7_shift                            (7)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_6_shift                            (6)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_5_shift                            (5)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_4_shift                            (4)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_3_shift                            (3)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_2_shift                            (2)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_1_shift                            (1)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_0_shift                            (0)
#define  FCIC_TOP_FCIC_RME_0_testrwm_mask                                        (0x80000000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_5_mask                               (0x08000000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_4_mask                               (0x04000000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_3_mask                               (0x02000000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_2_mask                               (0x01000000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_1_mask                               (0x00800000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_0_mask                               (0x00400000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_5_mask                               (0x00200000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_4_mask                               (0x00100000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_3_mask                               (0x00080000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_2_mask                               (0x00040000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_1_mask                               (0x00020000)
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_0_mask                               (0x00010000)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_7_mask                             (0x00008000)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_6_mask                             (0x00004000)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_5_mask                             (0x00002000)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_4_mask                             (0x00001000)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_3_mask                             (0x00000800)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_2_mask                             (0x00000400)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_1_mask                             (0x00000200)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_0_mask                             (0x00000100)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_7_mask                             (0x00000080)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_6_mask                             (0x00000040)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_5_mask                             (0x00000020)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_4_mask                             (0x00000010)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_3_mask                             (0x00000008)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_2_mask                             (0x00000004)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_1_mask                             (0x00000002)
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_0_mask                             (0x00000001)
#define  FCIC_TOP_FCIC_RME_0_testrwm(data)                                       (0x80000000&((data)<<31))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_5(data)                              (0x08000000&((data)<<27))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_4(data)                              (0x04000000&((data)<<26))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_3(data)                              (0x02000000&((data)<<25))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_2(data)                              (0x01000000&((data)<<24))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_1(data)                              (0x00800000&((data)<<23))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_2_rme_0(data)                              (0x00400000&((data)<<22))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_5(data)                              (0x00200000&((data)<<21))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_4(data)                              (0x00100000&((data)<<20))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_3(data)                              (0x00080000&((data)<<19))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_2(data)                              (0x00040000&((data)<<18))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_1(data)                              (0x00020000&((data)<<17))
#define  FCIC_TOP_FCIC_RME_0_fcic_int_1_rme_0(data)                              (0x00010000&((data)<<16))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_7(data)                            (0x00008000&((data)<<15))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_6(data)                            (0x00004000&((data)<<14))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_5(data)                            (0x00002000&((data)<<13))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_4(data)                            (0x00001000&((data)<<12))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_3(data)                            (0x00000800&((data)<<11))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_2(data)                            (0x00000400&((data)<<10))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_1(data)                            (0x00000200&((data)<<9))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_2_rme_0(data)                            (0x00000100&((data)<<8))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_7(data)                            (0x00000080&((data)<<7))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_6(data)                            (0x00000040&((data)<<6))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_5(data)                            (0x00000020&((data)<<5))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_4(data)                            (0x00000010&((data)<<4))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_3(data)                            (0x00000008&((data)<<3))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_2(data)                            (0x00000004&((data)<<2))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_1(data)                            (0x00000002&((data)<<1))
#define  FCIC_TOP_FCIC_RME_0_fcic_16728_1_rme_0(data)                            (0x00000001&(data))
#define  FCIC_TOP_FCIC_RME_0_get_testrwm(data)                                   ((0x80000000&(data))>>31)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_2_rme_5(data)                          ((0x08000000&(data))>>27)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_2_rme_4(data)                          ((0x04000000&(data))>>26)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_2_rme_3(data)                          ((0x02000000&(data))>>25)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_2_rme_2(data)                          ((0x01000000&(data))>>24)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_2_rme_1(data)                          ((0x00800000&(data))>>23)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_2_rme_0(data)                          ((0x00400000&(data))>>22)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_1_rme_5(data)                          ((0x00200000&(data))>>21)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_1_rme_4(data)                          ((0x00100000&(data))>>20)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_1_rme_3(data)                          ((0x00080000&(data))>>19)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_1_rme_2(data)                          ((0x00040000&(data))>>18)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_1_rme_1(data)                          ((0x00020000&(data))>>17)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_int_1_rme_0(data)                          ((0x00010000&(data))>>16)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_2_rme_7(data)                        ((0x00008000&(data))>>15)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_2_rme_6(data)                        ((0x00004000&(data))>>14)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_2_rme_5(data)                        ((0x00002000&(data))>>13)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_2_rme_4(data)                        ((0x00001000&(data))>>12)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_2_rme_3(data)                        ((0x00000800&(data))>>11)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_2_rme_2(data)                        ((0x00000400&(data))>>10)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_2_rme_1(data)                        ((0x00000200&(data))>>9)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_2_rme_0(data)                        ((0x00000100&(data))>>8)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_1_rme_7(data)                        ((0x00000080&(data))>>7)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_1_rme_6(data)                        ((0x00000040&(data))>>6)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_1_rme_5(data)                        ((0x00000020&(data))>>5)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_1_rme_4(data)                        ((0x00000010&(data))>>4)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_1_rme_3(data)                        ((0x00000008&(data))>>3)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_1_rme_2(data)                        ((0x00000004&(data))>>2)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_1_rme_1(data)                        ((0x00000002&(data))>>1)
#define  FCIC_TOP_FCIC_RME_0_get_fcic_16728_1_rme_0(data)                        (0x00000001&(data))

#define  FCIC_TOP_FCIC_RME_1                                                     0x1802EC5C
#define  FCIC_TOP_FCIC_RME_1_reg_addr                                            "0xB802EC5C"
#define  FCIC_TOP_FCIC_RME_1_reg                                                 0xB802EC5C
#define  FCIC_TOP_FCIC_RME_1_inst_addr                                           "0x0017"
#define  set_FCIC_TOP_FCIC_RME_1_reg(data)                                       (*((volatile unsigned int*)FCIC_TOP_FCIC_RME_1_reg)=data)
#define  get_FCIC_TOP_FCIC_RME_1_reg                                             (*((volatile unsigned int*)FCIC_TOP_FCIC_RME_1_reg))
#define  FCIC_TOP_FCIC_RME_1_fcic_ed_rme_0_shift                                 (23)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_6_shift                           (22)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_5_shift                           (21)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_4_shift                           (20)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_3_shift                           (19)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_2_shift                           (18)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_1_shift                           (17)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_0_shift                           (16)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_7_shift                         (15)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_6_shift                         (14)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_5_shift                         (13)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_4_shift                         (12)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_3_shift                         (11)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_2_shift                         (10)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_1_shift                         (9)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_0_shift                         (8)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_7_shift                         (7)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_6_shift                         (6)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_5_shift                         (5)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_4_shift                         (4)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_3_shift                         (3)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_2_shift                         (2)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_1_shift                         (1)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_0_shift                         (0)
#define  FCIC_TOP_FCIC_RME_1_fcic_ed_rme_0_mask                                  (0x00800000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_6_mask                            (0x00400000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_5_mask                            (0x00200000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_4_mask                            (0x00100000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_3_mask                            (0x00080000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_2_mask                            (0x00040000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_1_mask                            (0x00020000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_0_mask                            (0x00010000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_7_mask                          (0x00008000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_6_mask                          (0x00004000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_5_mask                          (0x00002000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_4_mask                          (0x00001000)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_3_mask                          (0x00000800)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_2_mask                          (0x00000400)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_1_mask                          (0x00000200)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_0_mask                          (0x00000100)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_7_mask                          (0x00000080)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_6_mask                          (0x00000040)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_5_mask                          (0x00000020)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_4_mask                          (0x00000010)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_3_mask                          (0x00000008)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_2_mask                          (0x00000004)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_1_mask                          (0x00000002)
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_0_mask                          (0x00000001)
#define  FCIC_TOP_FCIC_RME_1_fcic_ed_rme_0(data)                                 (0x00800000&((data)<<23))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_6(data)                           (0x00400000&((data)<<22))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_5(data)                           (0x00200000&((data)<<21))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_4(data)                           (0x00100000&((data)<<20))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_3(data)                           (0x00080000&((data)<<19))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_2(data)                           (0x00040000&((data)<<18))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_1(data)                           (0x00020000&((data)<<17))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_rme_0(data)                           (0x00010000&((data)<<16))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_7(data)                         (0x00008000&((data)<<15))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_6(data)                         (0x00004000&((data)<<14))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_5(data)                         (0x00002000&((data)<<13))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_4(data)                         (0x00001000&((data)<<12))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_3(data)                         (0x00000800&((data)<<11))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_2(data)                         (0x00000400&((data)<<10))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_1(data)                         (0x00000200&((data)<<9))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_2_rme_0(data)                         (0x00000100&((data)<<8))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_7(data)                         (0x00000080&((data)<<7))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_6(data)                         (0x00000040&((data)<<6))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_5(data)                         (0x00000020&((data)<<5))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_4(data)                         (0x00000010&((data)<<4))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_3(data)                         (0x00000008&((data)<<3))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_2(data)                         (0x00000004&((data)<<2))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_1(data)                         (0x00000002&((data)<<1))
#define  FCIC_TOP_FCIC_RME_1_fcic_template_1_rme_0(data)                         (0x00000001&(data))
#define  FCIC_TOP_FCIC_RME_1_get_fcic_ed_rme_0(data)                             ((0x00800000&(data))>>23)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_rme_6(data)                       ((0x00400000&(data))>>22)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_rme_5(data)                       ((0x00200000&(data))>>21)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_rme_4(data)                       ((0x00100000&(data))>>20)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_rme_3(data)                       ((0x00080000&(data))>>19)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_rme_2(data)                       ((0x00040000&(data))>>18)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_rme_1(data)                       ((0x00020000&(data))>>17)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_rme_0(data)                       ((0x00010000&(data))>>16)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_2_rme_7(data)                     ((0x00008000&(data))>>15)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_2_rme_6(data)                     ((0x00004000&(data))>>14)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_2_rme_5(data)                     ((0x00002000&(data))>>13)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_2_rme_4(data)                     ((0x00001000&(data))>>12)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_2_rme_3(data)                     ((0x00000800&(data))>>11)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_2_rme_2(data)                     ((0x00000400&(data))>>10)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_2_rme_1(data)                     ((0x00000200&(data))>>9)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_2_rme_0(data)                     ((0x00000100&(data))>>8)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_1_rme_7(data)                     ((0x00000080&(data))>>7)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_1_rme_6(data)                     ((0x00000040&(data))>>6)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_1_rme_5(data)                     ((0x00000020&(data))>>5)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_1_rme_4(data)                     ((0x00000010&(data))>>4)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_1_rme_3(data)                     ((0x00000008&(data))>>3)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_1_rme_2(data)                     ((0x00000004&(data))>>2)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_1_rme_1(data)                     ((0x00000002&(data))>>1)
#define  FCIC_TOP_FCIC_RME_1_get_fcic_template_1_rme_0(data)                     (0x00000001&(data))

#define  FCIC_TOP_FCIC_RM_0                                                      0x1802EC60
#define  FCIC_TOP_FCIC_RM_0_reg_addr                                             "0xB802EC60"
#define  FCIC_TOP_FCIC_RM_0_reg                                                  0xB802EC60
#define  FCIC_TOP_FCIC_RM_0_inst_addr                                            "0x0018"
#define  set_FCIC_TOP_FCIC_RM_0_reg(data)                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_0_reg)=data)
#define  get_FCIC_TOP_FCIC_RM_0_reg                                              (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_0_reg))
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_7_shift                              (28)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_6_shift                              (24)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_5_shift                              (20)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_4_shift                              (16)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_3_shift                              (12)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_2_shift                              (8)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_1_shift                              (4)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_0_shift                              (0)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_7_mask                               (0xF0000000)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_6_mask                               (0x0F000000)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_5_mask                               (0x00F00000)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_4_mask                               (0x000F0000)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_3_mask                               (0x0000F000)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_2_mask                               (0x00000F00)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_1_mask                               (0x000000F0)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_0_mask                               (0x0000000F)
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_7(data)                              (0xF0000000&((data)<<28))
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_6(data)                              (0x0F000000&((data)<<24))
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_5(data)                              (0x00F00000&((data)<<20))
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_4(data)                              (0x000F0000&((data)<<16))
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_3(data)                              (0x0000F000&((data)<<12))
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_2(data)                              (0x00000F00&((data)<<8))
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_1(data)                              (0x000000F0&((data)<<4))
#define  FCIC_TOP_FCIC_RM_0_fcic_16728_1_rm_0(data)                              (0x0000000F&(data))
#define  FCIC_TOP_FCIC_RM_0_get_fcic_16728_1_rm_7(data)                          ((0xF0000000&(data))>>28)
#define  FCIC_TOP_FCIC_RM_0_get_fcic_16728_1_rm_6(data)                          ((0x0F000000&(data))>>24)
#define  FCIC_TOP_FCIC_RM_0_get_fcic_16728_1_rm_5(data)                          ((0x00F00000&(data))>>20)
#define  FCIC_TOP_FCIC_RM_0_get_fcic_16728_1_rm_4(data)                          ((0x000F0000&(data))>>16)
#define  FCIC_TOP_FCIC_RM_0_get_fcic_16728_1_rm_3(data)                          ((0x0000F000&(data))>>12)
#define  FCIC_TOP_FCIC_RM_0_get_fcic_16728_1_rm_2(data)                          ((0x00000F00&(data))>>8)
#define  FCIC_TOP_FCIC_RM_0_get_fcic_16728_1_rm_1(data)                          ((0x000000F0&(data))>>4)
#define  FCIC_TOP_FCIC_RM_0_get_fcic_16728_1_rm_0(data)                          (0x0000000F&(data))

#define  FCIC_TOP_FCIC_RM_1                                                      0x1802EC64
#define  FCIC_TOP_FCIC_RM_1_reg_addr                                             "0xB802EC64"
#define  FCIC_TOP_FCIC_RM_1_reg                                                  0xB802EC64
#define  FCIC_TOP_FCIC_RM_1_inst_addr                                            "0x0019"
#define  set_FCIC_TOP_FCIC_RM_1_reg(data)                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_1_reg)=data)
#define  get_FCIC_TOP_FCIC_RM_1_reg                                              (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_1_reg))
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_7_shift                              (28)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_6_shift                              (24)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_5_shift                              (20)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_4_shift                              (16)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_3_shift                              (12)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_2_shift                              (8)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_1_shift                              (4)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_0_shift                              (0)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_7_mask                               (0xF0000000)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_6_mask                               (0x0F000000)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_5_mask                               (0x00F00000)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_4_mask                               (0x000F0000)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_3_mask                               (0x0000F000)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_2_mask                               (0x00000F00)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_1_mask                               (0x000000F0)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_0_mask                               (0x0000000F)
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_7(data)                              (0xF0000000&((data)<<28))
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_6(data)                              (0x0F000000&((data)<<24))
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_5(data)                              (0x00F00000&((data)<<20))
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_4(data)                              (0x000F0000&((data)<<16))
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_3(data)                              (0x0000F000&((data)<<12))
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_2(data)                              (0x00000F00&((data)<<8))
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_1(data)                              (0x000000F0&((data)<<4))
#define  FCIC_TOP_FCIC_RM_1_fcic_16728_2_rm_0(data)                              (0x0000000F&(data))
#define  FCIC_TOP_FCIC_RM_1_get_fcic_16728_2_rm_7(data)                          ((0xF0000000&(data))>>28)
#define  FCIC_TOP_FCIC_RM_1_get_fcic_16728_2_rm_6(data)                          ((0x0F000000&(data))>>24)
#define  FCIC_TOP_FCIC_RM_1_get_fcic_16728_2_rm_5(data)                          ((0x00F00000&(data))>>20)
#define  FCIC_TOP_FCIC_RM_1_get_fcic_16728_2_rm_4(data)                          ((0x000F0000&(data))>>16)
#define  FCIC_TOP_FCIC_RM_1_get_fcic_16728_2_rm_3(data)                          ((0x0000F000&(data))>>12)
#define  FCIC_TOP_FCIC_RM_1_get_fcic_16728_2_rm_2(data)                          ((0x00000F00&(data))>>8)
#define  FCIC_TOP_FCIC_RM_1_get_fcic_16728_2_rm_1(data)                          ((0x000000F0&(data))>>4)
#define  FCIC_TOP_FCIC_RM_1_get_fcic_16728_2_rm_0(data)                          (0x0000000F&(data))

#define  FCIC_TOP_FCIC_RM_2                                                      0x1802EC68
#define  FCIC_TOP_FCIC_RM_2_reg_addr                                             "0xB802EC68"
#define  FCIC_TOP_FCIC_RM_2_reg                                                  0xB802EC68
#define  FCIC_TOP_FCIC_RM_2_inst_addr                                            "0x001A"
#define  set_FCIC_TOP_FCIC_RM_2_reg(data)                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_2_reg)=data)
#define  get_FCIC_TOP_FCIC_RM_2_reg                                              (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_2_reg))
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_5_shift                                (20)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_4_shift                                (16)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_3_shift                                (12)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_2_shift                                (8)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_1_shift                                (4)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_0_shift                                (0)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_5_mask                                 (0x00F00000)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_4_mask                                 (0x000F0000)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_3_mask                                 (0x0000F000)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_2_mask                                 (0x00000F00)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_1_mask                                 (0x000000F0)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_0_mask                                 (0x0000000F)
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_5(data)                                (0x00F00000&((data)<<20))
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_4(data)                                (0x000F0000&((data)<<16))
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_3(data)                                (0x0000F000&((data)<<12))
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_2(data)                                (0x00000F00&((data)<<8))
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_1(data)                                (0x000000F0&((data)<<4))
#define  FCIC_TOP_FCIC_RM_2_fcic_int_1_rm_0(data)                                (0x0000000F&(data))
#define  FCIC_TOP_FCIC_RM_2_get_fcic_int_1_rm_5(data)                            ((0x00F00000&(data))>>20)
#define  FCIC_TOP_FCIC_RM_2_get_fcic_int_1_rm_4(data)                            ((0x000F0000&(data))>>16)
#define  FCIC_TOP_FCIC_RM_2_get_fcic_int_1_rm_3(data)                            ((0x0000F000&(data))>>12)
#define  FCIC_TOP_FCIC_RM_2_get_fcic_int_1_rm_2(data)                            ((0x00000F00&(data))>>8)
#define  FCIC_TOP_FCIC_RM_2_get_fcic_int_1_rm_1(data)                            ((0x000000F0&(data))>>4)
#define  FCIC_TOP_FCIC_RM_2_get_fcic_int_1_rm_0(data)                            (0x0000000F&(data))

#define  FCIC_TOP_FCIC_RM_3                                                      0x1802EC6C
#define  FCIC_TOP_FCIC_RM_3_reg_addr                                             "0xB802EC6C"
#define  FCIC_TOP_FCIC_RM_3_reg                                                  0xB802EC6C
#define  FCIC_TOP_FCIC_RM_3_inst_addr                                            "0x001B"
#define  set_FCIC_TOP_FCIC_RM_3_reg(data)                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_3_reg)=data)
#define  get_FCIC_TOP_FCIC_RM_3_reg                                              (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_3_reg))
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_5_shift                                (20)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_4_shift                                (16)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_3_shift                                (12)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_2_shift                                (8)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_1_shift                                (4)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_0_shift                                (0)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_5_mask                                 (0x00F00000)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_4_mask                                 (0x000F0000)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_3_mask                                 (0x0000F000)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_2_mask                                 (0x00000F00)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_1_mask                                 (0x000000F0)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_0_mask                                 (0x0000000F)
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_5(data)                                (0x00F00000&((data)<<20))
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_4(data)                                (0x000F0000&((data)<<16))
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_3(data)                                (0x0000F000&((data)<<12))
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_2(data)                                (0x00000F00&((data)<<8))
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_1(data)                                (0x000000F0&((data)<<4))
#define  FCIC_TOP_FCIC_RM_3_fcic_int_2_rm_0(data)                                (0x0000000F&(data))
#define  FCIC_TOP_FCIC_RM_3_get_fcic_int_2_rm_5(data)                            ((0x00F00000&(data))>>20)
#define  FCIC_TOP_FCIC_RM_3_get_fcic_int_2_rm_4(data)                            ((0x000F0000&(data))>>16)
#define  FCIC_TOP_FCIC_RM_3_get_fcic_int_2_rm_3(data)                            ((0x0000F000&(data))>>12)
#define  FCIC_TOP_FCIC_RM_3_get_fcic_int_2_rm_2(data)                            ((0x00000F00&(data))>>8)
#define  FCIC_TOP_FCIC_RM_3_get_fcic_int_2_rm_1(data)                            ((0x000000F0&(data))>>4)
#define  FCIC_TOP_FCIC_RM_3_get_fcic_int_2_rm_0(data)                            (0x0000000F&(data))

#define  FCIC_TOP_FCIC_RM_4                                                      0x1802EC70
#define  FCIC_TOP_FCIC_RM_4_reg_addr                                             "0xB802EC70"
#define  FCIC_TOP_FCIC_RM_4_reg                                                  0xB802EC70
#define  FCIC_TOP_FCIC_RM_4_inst_addr                                            "0x001C"
#define  set_FCIC_TOP_FCIC_RM_4_reg(data)                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_4_reg)=data)
#define  get_FCIC_TOP_FCIC_RM_4_reg                                              (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_4_reg))
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_7_shift                           (28)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_6_shift                           (24)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_5_shift                           (20)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_4_shift                           (16)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_3_shift                           (12)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_2_shift                           (8)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_1_shift                           (4)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_0_shift                           (0)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_7_mask                            (0xF0000000)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_6_mask                            (0x0F000000)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_5_mask                            (0x00F00000)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_4_mask                            (0x000F0000)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_3_mask                            (0x0000F000)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_2_mask                            (0x00000F00)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_1_mask                            (0x000000F0)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_0_mask                            (0x0000000F)
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_7(data)                           (0xF0000000&((data)<<28))
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_6(data)                           (0x0F000000&((data)<<24))
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_5(data)                           (0x00F00000&((data)<<20))
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_4(data)                           (0x000F0000&((data)<<16))
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_3(data)                           (0x0000F000&((data)<<12))
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_2(data)                           (0x00000F00&((data)<<8))
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_1(data)                           (0x000000F0&((data)<<4))
#define  FCIC_TOP_FCIC_RM_4_fcic_template_1_rm_0(data)                           (0x0000000F&(data))
#define  FCIC_TOP_FCIC_RM_4_get_fcic_template_1_rm_7(data)                       ((0xF0000000&(data))>>28)
#define  FCIC_TOP_FCIC_RM_4_get_fcic_template_1_rm_6(data)                       ((0x0F000000&(data))>>24)
#define  FCIC_TOP_FCIC_RM_4_get_fcic_template_1_rm_5(data)                       ((0x00F00000&(data))>>20)
#define  FCIC_TOP_FCIC_RM_4_get_fcic_template_1_rm_4(data)                       ((0x000F0000&(data))>>16)
#define  FCIC_TOP_FCIC_RM_4_get_fcic_template_1_rm_3(data)                       ((0x0000F000&(data))>>12)
#define  FCIC_TOP_FCIC_RM_4_get_fcic_template_1_rm_2(data)                       ((0x00000F00&(data))>>8)
#define  FCIC_TOP_FCIC_RM_4_get_fcic_template_1_rm_1(data)                       ((0x000000F0&(data))>>4)
#define  FCIC_TOP_FCIC_RM_4_get_fcic_template_1_rm_0(data)                       (0x0000000F&(data))

#define  FCIC_TOP_FCIC_RM_5                                                      0x1802EC74
#define  FCIC_TOP_FCIC_RM_5_reg_addr                                             "0xB802EC74"
#define  FCIC_TOP_FCIC_RM_5_reg                                                  0xB802EC74
#define  FCIC_TOP_FCIC_RM_5_inst_addr                                            "0x001D"
#define  set_FCIC_TOP_FCIC_RM_5_reg(data)                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_5_reg)=data)
#define  get_FCIC_TOP_FCIC_RM_5_reg                                              (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_5_reg))
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_7_shift                           (28)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_6_shift                           (24)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_5_shift                           (20)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_4_shift                           (16)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_3_shift                           (12)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_2_shift                           (8)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_1_shift                           (4)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_0_shift                           (0)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_7_mask                            (0xF0000000)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_6_mask                            (0x0F000000)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_5_mask                            (0x00F00000)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_4_mask                            (0x000F0000)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_3_mask                            (0x0000F000)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_2_mask                            (0x00000F00)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_1_mask                            (0x000000F0)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_0_mask                            (0x0000000F)
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_7(data)                           (0xF0000000&((data)<<28))
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_6(data)                           (0x0F000000&((data)<<24))
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_5(data)                           (0x00F00000&((data)<<20))
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_4(data)                           (0x000F0000&((data)<<16))
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_3(data)                           (0x0000F000&((data)<<12))
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_2(data)                           (0x00000F00&((data)<<8))
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_1(data)                           (0x000000F0&((data)<<4))
#define  FCIC_TOP_FCIC_RM_5_fcic_template_2_rm_0(data)                           (0x0000000F&(data))
#define  FCIC_TOP_FCIC_RM_5_get_fcic_template_2_rm_7(data)                       ((0xF0000000&(data))>>28)
#define  FCIC_TOP_FCIC_RM_5_get_fcic_template_2_rm_6(data)                       ((0x0F000000&(data))>>24)
#define  FCIC_TOP_FCIC_RM_5_get_fcic_template_2_rm_5(data)                       ((0x00F00000&(data))>>20)
#define  FCIC_TOP_FCIC_RM_5_get_fcic_template_2_rm_4(data)                       ((0x000F0000&(data))>>16)
#define  FCIC_TOP_FCIC_RM_5_get_fcic_template_2_rm_3(data)                       ((0x0000F000&(data))>>12)
#define  FCIC_TOP_FCIC_RM_5_get_fcic_template_2_rm_2(data)                       ((0x00000F00&(data))>>8)
#define  FCIC_TOP_FCIC_RM_5_get_fcic_template_2_rm_1(data)                       ((0x000000F0&(data))>>4)
#define  FCIC_TOP_FCIC_RM_5_get_fcic_template_2_rm_0(data)                       (0x0000000F&(data))

#define  FCIC_TOP_FCIC_RM_6                                                      0x1802EC78
#define  FCIC_TOP_FCIC_RM_6_reg_addr                                             "0xB802EC78"
#define  FCIC_TOP_FCIC_RM_6_reg                                                  0xB802EC78
#define  FCIC_TOP_FCIC_RM_6_inst_addr                                            "0x001E"
#define  set_FCIC_TOP_FCIC_RM_6_reg(data)                                        (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_6_reg)=data)
#define  get_FCIC_TOP_FCIC_RM_6_reg                                              (*((volatile unsigned int*)FCIC_TOP_FCIC_RM_6_reg))
#define  FCIC_TOP_FCIC_RM_6_fcic_ed_rm_0_shift                                   (28)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_6_shift                             (24)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_5_shift                             (20)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_4_shift                             (16)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_3_shift                             (12)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_2_shift                             (8)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_1_shift                             (4)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_0_shift                             (0)
#define  FCIC_TOP_FCIC_RM_6_fcic_ed_rm_0_mask                                    (0xF0000000)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_6_mask                              (0x0F000000)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_5_mask                              (0x00F00000)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_4_mask                              (0x000F0000)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_3_mask                              (0x0000F000)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_2_mask                              (0x00000F00)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_1_mask                              (0x000000F0)
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_0_mask                              (0x0000000F)
#define  FCIC_TOP_FCIC_RM_6_fcic_ed_rm_0(data)                                   (0xF0000000&((data)<<28))
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_6(data)                             (0x0F000000&((data)<<24))
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_5(data)                             (0x00F00000&((data)<<20))
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_4(data)                             (0x000F0000&((data)<<16))
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_3(data)                             (0x0000F000&((data)<<12))
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_2(data)                             (0x00000F00&((data)<<8))
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_1(data)                             (0x000000F0&((data)<<4))
#define  FCIC_TOP_FCIC_RM_6_fcic_template_rm_0(data)                             (0x0000000F&(data))
#define  FCIC_TOP_FCIC_RM_6_get_fcic_ed_rm_0(data)                               ((0xF0000000&(data))>>28)
#define  FCIC_TOP_FCIC_RM_6_get_fcic_template_rm_6(data)                         ((0x0F000000&(data))>>24)
#define  FCIC_TOP_FCIC_RM_6_get_fcic_template_rm_5(data)                         ((0x00F00000&(data))>>20)
#define  FCIC_TOP_FCIC_RM_6_get_fcic_template_rm_4(data)                         ((0x000F0000&(data))>>16)
#define  FCIC_TOP_FCIC_RM_6_get_fcic_template_rm_3(data)                         ((0x0000F000&(data))>>12)
#define  FCIC_TOP_FCIC_RM_6_get_fcic_template_rm_2(data)                         ((0x00000F00&(data))>>8)
#define  FCIC_TOP_FCIC_RM_6_get_fcic_template_rm_1(data)                         ((0x000000F0&(data))>>4)
#define  FCIC_TOP_FCIC_RM_6_get_fcic_template_rm_0(data)                         (0x0000000F&(data))

#define  FCIC_TOP_FCIC_IO_reg                                                    0x1802EC7C
#define  FCIC_TOP_FCIC_IO_reg_reg_addr                                           "0xB802EC7C"
#define  FCIC_TOP_FCIC_IO_reg_reg                                                0xB802EC7C
#define  FCIC_TOP_FCIC_IO_reg_inst_addr                                          "0x001F"
#define  set_FCIC_TOP_FCIC_IO_reg_reg(data)                                      (*((volatile unsigned int*)FCIC_TOP_FCIC_IO_reg_reg)=data)
#define  get_FCIC_TOP_FCIC_IO_reg_reg                                            (*((volatile unsigned int*)FCIC_TOP_FCIC_IO_reg_reg))
#define  FCIC_TOP_FCIC_IO_reg_color_4_shift                                      (8)
#define  FCIC_TOP_FCIC_IO_reg_color_3_shift                                      (6)
#define  FCIC_TOP_FCIC_IO_reg_color_2_shift                                      (4)
#define  FCIC_TOP_FCIC_IO_reg_color_1_shift                                      (2)
#define  FCIC_TOP_FCIC_IO_reg_mplus_opt_shift                                    (1)
#define  FCIC_TOP_FCIC_IO_reg_fcic_io_reg_en_shift                               (0)
#define  FCIC_TOP_FCIC_IO_reg_color_4_mask                                       (0x00000300)
#define  FCIC_TOP_FCIC_IO_reg_color_3_mask                                       (0x000000C0)
#define  FCIC_TOP_FCIC_IO_reg_color_2_mask                                       (0x00000030)
#define  FCIC_TOP_FCIC_IO_reg_color_1_mask                                       (0x0000000C)
#define  FCIC_TOP_FCIC_IO_reg_mplus_opt_mask                                     (0x00000002)
#define  FCIC_TOP_FCIC_IO_reg_fcic_io_reg_en_mask                                (0x00000001)
#define  FCIC_TOP_FCIC_IO_reg_color_4(data)                                      (0x00000300&((data)<<8))
#define  FCIC_TOP_FCIC_IO_reg_color_3(data)                                      (0x000000C0&((data)<<6))
#define  FCIC_TOP_FCIC_IO_reg_color_2(data)                                      (0x00000030&((data)<<4))
#define  FCIC_TOP_FCIC_IO_reg_color_1(data)                                      (0x0000000C&((data)<<2))
#define  FCIC_TOP_FCIC_IO_reg_mplus_opt(data)                                    (0x00000002&((data)<<1))
#define  FCIC_TOP_FCIC_IO_reg_fcic_io_reg_en(data)                               (0x00000001&(data))
#define  FCIC_TOP_FCIC_IO_reg_get_color_4(data)                                  ((0x00000300&(data))>>8)
#define  FCIC_TOP_FCIC_IO_reg_get_color_3(data)                                  ((0x000000C0&(data))>>6)
#define  FCIC_TOP_FCIC_IO_reg_get_color_2(data)                                  ((0x00000030&(data))>>4)
#define  FCIC_TOP_FCIC_IO_reg_get_color_1(data)                                  ((0x0000000C&(data))>>2)
#define  FCIC_TOP_FCIC_IO_reg_get_mplus_opt(data)                                ((0x00000002&(data))>>1)
#define  FCIC_TOP_FCIC_IO_reg_get_fcic_io_reg_en(data)                           (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======FCIC_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  fcic_rbus_if_enable:2;
    };
}fcic_top_fcic_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  auto_detect_result:2;
        RBus_UInt32  auto_detect_en:1;
        RBus_UInt32  user_timing_sel:2;
        RBus_UInt32  multi_access_en:1;
        RBus_UInt32  flash_write_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  eeprom_write_enable:1;
    };
}fcic_top_fcic_crtl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cfg_rdata:8;
        RBus_UInt32  cfg_addr:12;
    };
}fcic_top_fcic_eeprom_if_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cfg_data_3:8;
        RBus_UInt32  cfg_data_2:8;
        RBus_UInt32  cfg_data_1:8;
        RBus_UInt32  cfg_data_0:8;
    };
}fcic_top_fcic_eeprom_if_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  flash_done:1;
        RBus_UInt32  flash_addr:17;
    };
}fcic_top_fcic_flash_if_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_data_0:32;
    };
}fcic_top_fcic_flash_if_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_data_1:32;
    };
}fcic_top_fcic_flash_if_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_data_2:32;
    };
}fcic_top_fcic_flash_if_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_data_3:32;
    };
}fcic_top_fcic_flash_if_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rd_addr:15;
        RBus_UInt32  res2:6;
        RBus_UInt32  flash_dbg_rd_en:1;
        RBus_UInt32  eep_dbg_rd_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  template_data_mux:3;
        RBus_UInt32  flash_dbg_mux:4;
    };
}fcic_top_fcic_flash_dbg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_rdata_0:32;
    };
}fcic_top_fcic_flash_dbg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_rdata_1:32;
    };
}fcic_top_fcic_flash_dbg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_fcic_ed_bist_mode:1;
        RBus_UInt32  mbist_fcic_template_bist_mode:1;
        RBus_UInt32  mbist_fcic_template_2_bist_mode:1;
        RBus_UInt32  mbist_fcic_template_1_bist_mode:1;
        RBus_UInt32  mbist_fcic_int_2_bist_mode:1;
        RBus_UInt32  mbist_fcic_int_1_bist_mode:1;
        RBus_UInt32  mbist_fcic_16728_2_bist_mode:1;
        RBus_UInt32  mbist_fcic_16728_1_bist_mode:1;
    };
}fcic_top_fcic_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_fcic_ed_drf_mode:1;
        RBus_UInt32  mbist_fcic_template_drf_mode:1;
        RBus_UInt32  mbist_fcic_template_2_drf_mode:1;
        RBus_UInt32  mbist_fcic_template_1_drf_mode:1;
        RBus_UInt32  mbist_fcic_int_2_drf_mode:1;
        RBus_UInt32  mbist_fcic_int_1_drf_mode:1;
        RBus_UInt32  mbist_fcic_16728_2_drf_mode:1;
        RBus_UInt32  mbist_fcic_16728_1_drf_mode:1;
    };
}fcic_top_fcic_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_fcic_ed_drf_resume:1;
        RBus_UInt32  mbist_fcic_template_drf_resume:1;
        RBus_UInt32  mbist_fcic_template_2_drf_resume:1;
        RBus_UInt32  mbist_fcic_template_1_drf_resume:1;
        RBus_UInt32  mbist_fcic_int_2_drf_resume:1;
        RBus_UInt32  mbist_fcic_int_1_drf_resume:1;
        RBus_UInt32  mbist_fcic_16728_2_drf_resume:1;
        RBus_UInt32  mbist_fcic_16728_1_drf_resume:1;
    };
}fcic_top_fcic_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_fcic_ed_bist_done:1;
        RBus_UInt32  mbist_fcic_template_bist_done:1;
        RBus_UInt32  mbist_fcic_template_2_bist_done:1;
        RBus_UInt32  mbist_fcic_template_1_bist_done:1;
        RBus_UInt32  mbist_fcic_int_2_bist_done:1;
        RBus_UInt32  mbist_fcic_int_1_bist_done:1;
        RBus_UInt32  mbist_fcic_16728_2_bist_done:1;
        RBus_UInt32  mbist_fcic_16728_1_bist_done:1;
    };
}fcic_top_fcic_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_fcic_ed_drf_done:1;
        RBus_UInt32  mbist_fcic_template_drf_done:1;
        RBus_UInt32  mbist_fcic_template_2_drf_done:1;
        RBus_UInt32  mbist_fcic_template_1_drf_done:1;
        RBus_UInt32  mbist_fcic_int_2_drf_done:1;
        RBus_UInt32  mbist_fcic_int_1_drf_done:1;
        RBus_UInt32  mbist_fcic_16728_2_drf_done:1;
        RBus_UInt32  mbist_fcic_16728_1_drf_done:1;
    };
}fcic_top_fcic_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mbist_fcic_int_2_bist_fail:6;
        RBus_UInt32  mbist_fcic_int_1_bist_fail:6;
        RBus_UInt32  mbist_fcic_16728_2_bist_fail:8;
        RBus_UInt32  mbist_fcic_16728_1_bist_fail:8;
    };
}fcic_top_fcic_bist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  mbist_fcic_ed_bist_fail:1;
        RBus_UInt32  mbist_fcic_template_bist_fail:7;
        RBus_UInt32  mbist_fcic_template_2_bist_fail:8;
        RBus_UInt32  mbist_fcic_template_1_bist_fail:8;
    };
}fcic_top_fcic_bist_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  mbist_fcic_int_2_drf_fail:6;
        RBus_UInt32  mbist_fcic_int_1_drf_fail:6;
        RBus_UInt32  mbist_fcic_16728_2_drf_fail:8;
        RBus_UInt32  mbist_fcic_16728_1_drf_fail:8;
    };
}fcic_top_fcic_drf_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  mbist_fcic_ed_drf_fail:1;
        RBus_UInt32  mbist_fcic_template_drf_fail:7;
        RBus_UInt32  mbist_fcic_template_2_drf_fail:8;
        RBus_UInt32  mbist_fcic_template_1_drf_fail:8;
    };
}fcic_top_fcic_drf_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_fcic_ed_drf_pause:1;
        RBus_UInt32  mbist_fcic_template_drf_pause:1;
        RBus_UInt32  mbist_fcic_template_2_drf_pause:1;
        RBus_UInt32  mbist_fcic_template_1_drf_pause:1;
        RBus_UInt32  mbist_fcic_int_2_drf_pause:1;
        RBus_UInt32  mbist_fcic_int_1_drf_pause:1;
        RBus_UInt32  mbist_fcic_16728_2_drf_pause:1;
        RBus_UInt32  mbist_fcic_16728_1_drf_pause:1;
    };
}fcic_top_fcic_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  testrwm:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fcic_int_2_rme_5:1;
        RBus_UInt32  fcic_int_2_rme_4:1;
        RBus_UInt32  fcic_int_2_rme_3:1;
        RBus_UInt32  fcic_int_2_rme_2:1;
        RBus_UInt32  fcic_int_2_rme_1:1;
        RBus_UInt32  fcic_int_2_rme_0:1;
        RBus_UInt32  fcic_int_1_rme_5:1;
        RBus_UInt32  fcic_int_1_rme_4:1;
        RBus_UInt32  fcic_int_1_rme_3:1;
        RBus_UInt32  fcic_int_1_rme_2:1;
        RBus_UInt32  fcic_int_1_rme_1:1;
        RBus_UInt32  fcic_int_1_rme_0:1;
        RBus_UInt32  fcic_16728_2_rme_7:1;
        RBus_UInt32  fcic_16728_2_rme_6:1;
        RBus_UInt32  fcic_16728_2_rme_5:1;
        RBus_UInt32  fcic_16728_2_rme_4:1;
        RBus_UInt32  fcic_16728_2_rme_3:1;
        RBus_UInt32  fcic_16728_2_rme_2:1;
        RBus_UInt32  fcic_16728_2_rme_1:1;
        RBus_UInt32  fcic_16728_2_rme_0:1;
        RBus_UInt32  fcic_16728_1_rme_7:1;
        RBus_UInt32  fcic_16728_1_rme_6:1;
        RBus_UInt32  fcic_16728_1_rme_5:1;
        RBus_UInt32  fcic_16728_1_rme_4:1;
        RBus_UInt32  fcic_16728_1_rme_3:1;
        RBus_UInt32  fcic_16728_1_rme_2:1;
        RBus_UInt32  fcic_16728_1_rme_1:1;
        RBus_UInt32  fcic_16728_1_rme_0:1;
    };
}fcic_top_fcic_rme_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fcic_ed_rme_0:1;
        RBus_UInt32  fcic_template_rme_6:1;
        RBus_UInt32  fcic_template_rme_5:1;
        RBus_UInt32  fcic_template_rme_4:1;
        RBus_UInt32  fcic_template_rme_3:1;
        RBus_UInt32  fcic_template_rme_2:1;
        RBus_UInt32  fcic_template_rme_1:1;
        RBus_UInt32  fcic_template_rme_0:1;
        RBus_UInt32  fcic_template_2_rme_7:1;
        RBus_UInt32  fcic_template_2_rme_6:1;
        RBus_UInt32  fcic_template_2_rme_5:1;
        RBus_UInt32  fcic_template_2_rme_4:1;
        RBus_UInt32  fcic_template_2_rme_3:1;
        RBus_UInt32  fcic_template_2_rme_2:1;
        RBus_UInt32  fcic_template_2_rme_1:1;
        RBus_UInt32  fcic_template_2_rme_0:1;
        RBus_UInt32  fcic_template_1_rme_7:1;
        RBus_UInt32  fcic_template_1_rme_6:1;
        RBus_UInt32  fcic_template_1_rme_5:1;
        RBus_UInt32  fcic_template_1_rme_4:1;
        RBus_UInt32  fcic_template_1_rme_3:1;
        RBus_UInt32  fcic_template_1_rme_2:1;
        RBus_UInt32  fcic_template_1_rme_1:1;
        RBus_UInt32  fcic_template_1_rme_0:1;
    };
}fcic_top_fcic_rme_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_16728_1_rm_7:4;
        RBus_UInt32  fcic_16728_1_rm_6:4;
        RBus_UInt32  fcic_16728_1_rm_5:4;
        RBus_UInt32  fcic_16728_1_rm_4:4;
        RBus_UInt32  fcic_16728_1_rm_3:4;
        RBus_UInt32  fcic_16728_1_rm_2:4;
        RBus_UInt32  fcic_16728_1_rm_1:4;
        RBus_UInt32  fcic_16728_1_rm_0:4;
    };
}fcic_top_fcic_rm_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_16728_2_rm_7:4;
        RBus_UInt32  fcic_16728_2_rm_6:4;
        RBus_UInt32  fcic_16728_2_rm_5:4;
        RBus_UInt32  fcic_16728_2_rm_4:4;
        RBus_UInt32  fcic_16728_2_rm_3:4;
        RBus_UInt32  fcic_16728_2_rm_2:4;
        RBus_UInt32  fcic_16728_2_rm_1:4;
        RBus_UInt32  fcic_16728_2_rm_0:4;
    };
}fcic_top_fcic_rm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fcic_int_1_rm_5:4;
        RBus_UInt32  fcic_int_1_rm_4:4;
        RBus_UInt32  fcic_int_1_rm_3:4;
        RBus_UInt32  fcic_int_1_rm_2:4;
        RBus_UInt32  fcic_int_1_rm_1:4;
        RBus_UInt32  fcic_int_1_rm_0:4;
    };
}fcic_top_fcic_rm_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fcic_int_2_rm_5:4;
        RBus_UInt32  fcic_int_2_rm_4:4;
        RBus_UInt32  fcic_int_2_rm_3:4;
        RBus_UInt32  fcic_int_2_rm_2:4;
        RBus_UInt32  fcic_int_2_rm_1:4;
        RBus_UInt32  fcic_int_2_rm_0:4;
    };
}fcic_top_fcic_rm_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_template_1_rm_7:4;
        RBus_UInt32  fcic_template_1_rm_6:4;
        RBus_UInt32  fcic_template_1_rm_5:4;
        RBus_UInt32  fcic_template_1_rm_4:4;
        RBus_UInt32  fcic_template_1_rm_3:4;
        RBus_UInt32  fcic_template_1_rm_2:4;
        RBus_UInt32  fcic_template_1_rm_1:4;
        RBus_UInt32  fcic_template_1_rm_0:4;
    };
}fcic_top_fcic_rm_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_template_2_rm_7:4;
        RBus_UInt32  fcic_template_2_rm_6:4;
        RBus_UInt32  fcic_template_2_rm_5:4;
        RBus_UInt32  fcic_template_2_rm_4:4;
        RBus_UInt32  fcic_template_2_rm_3:4;
        RBus_UInt32  fcic_template_2_rm_2:4;
        RBus_UInt32  fcic_template_2_rm_1:4;
        RBus_UInt32  fcic_template_2_rm_0:4;
    };
}fcic_top_fcic_rm_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_ed_rm_0:4;
        RBus_UInt32  fcic_template_rm_6:4;
        RBus_UInt32  fcic_template_rm_5:4;
        RBus_UInt32  fcic_template_rm_4:4;
        RBus_UInt32  fcic_template_rm_3:4;
        RBus_UInt32  fcic_template_rm_2:4;
        RBus_UInt32  fcic_template_rm_1:4;
        RBus_UInt32  fcic_template_rm_0:4;
    };
}fcic_top_fcic_rm_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  color_4:2;
        RBus_UInt32  color_3:2;
        RBus_UInt32  color_2:2;
        RBus_UInt32  color_1:2;
        RBus_UInt32  mplus_opt:1;
        RBus_UInt32  fcic_io_reg_en:1;
    };
}fcic_top_fcic_io_reg_RBUS;

#else //apply LITTLE_ENDIAN

//======FCIC_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_rbus_if_enable:2;
        RBus_UInt32  res1:30;
    };
}fcic_top_fcic_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eeprom_write_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  flash_write_enable:1;
        RBus_UInt32  multi_access_en:1;
        RBus_UInt32  user_timing_sel:2;
        RBus_UInt32  auto_detect_en:1;
        RBus_UInt32  auto_detect_result:2;
        RBus_UInt32  res2:23;
    };
}fcic_top_fcic_crtl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cfg_addr:12;
        RBus_UInt32  cfg_rdata:8;
        RBus_UInt32  res1:12;
    };
}fcic_top_fcic_eeprom_if_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cfg_data_0:8;
        RBus_UInt32  cfg_data_1:8;
        RBus_UInt32  cfg_data_2:8;
        RBus_UInt32  cfg_data_3:8;
    };
}fcic_top_fcic_eeprom_if_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_addr:17;
        RBus_UInt32  flash_done:1;
        RBus_UInt32  res1:14;
    };
}fcic_top_fcic_flash_if_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_data_0:32;
    };
}fcic_top_fcic_flash_if_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_data_1:32;
    };
}fcic_top_fcic_flash_if_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_data_2:32;
    };
}fcic_top_fcic_flash_if_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_data_3:32;
    };
}fcic_top_fcic_flash_if_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_dbg_mux:4;
        RBus_UInt32  template_data_mux:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  eep_dbg_rd_en:1;
        RBus_UInt32  flash_dbg_rd_en:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  rd_addr:15;
        RBus_UInt32  res3:1;
    };
}fcic_top_fcic_flash_dbg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_rdata_0:32;
    };
}fcic_top_fcic_flash_dbg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flash_rdata_1:32;
    };
}fcic_top_fcic_flash_dbg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_16728_1_bist_mode:1;
        RBus_UInt32  mbist_fcic_16728_2_bist_mode:1;
        RBus_UInt32  mbist_fcic_int_1_bist_mode:1;
        RBus_UInt32  mbist_fcic_int_2_bist_mode:1;
        RBus_UInt32  mbist_fcic_template_1_bist_mode:1;
        RBus_UInt32  mbist_fcic_template_2_bist_mode:1;
        RBus_UInt32  mbist_fcic_template_bist_mode:1;
        RBus_UInt32  mbist_fcic_ed_bist_mode:1;
        RBus_UInt32  res1:24;
    };
}fcic_top_fcic_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_16728_1_drf_mode:1;
        RBus_UInt32  mbist_fcic_16728_2_drf_mode:1;
        RBus_UInt32  mbist_fcic_int_1_drf_mode:1;
        RBus_UInt32  mbist_fcic_int_2_drf_mode:1;
        RBus_UInt32  mbist_fcic_template_1_drf_mode:1;
        RBus_UInt32  mbist_fcic_template_2_drf_mode:1;
        RBus_UInt32  mbist_fcic_template_drf_mode:1;
        RBus_UInt32  mbist_fcic_ed_drf_mode:1;
        RBus_UInt32  res1:24;
    };
}fcic_top_fcic_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_16728_1_drf_resume:1;
        RBus_UInt32  mbist_fcic_16728_2_drf_resume:1;
        RBus_UInt32  mbist_fcic_int_1_drf_resume:1;
        RBus_UInt32  mbist_fcic_int_2_drf_resume:1;
        RBus_UInt32  mbist_fcic_template_1_drf_resume:1;
        RBus_UInt32  mbist_fcic_template_2_drf_resume:1;
        RBus_UInt32  mbist_fcic_template_drf_resume:1;
        RBus_UInt32  mbist_fcic_ed_drf_resume:1;
        RBus_UInt32  res1:24;
    };
}fcic_top_fcic_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_16728_1_bist_done:1;
        RBus_UInt32  mbist_fcic_16728_2_bist_done:1;
        RBus_UInt32  mbist_fcic_int_1_bist_done:1;
        RBus_UInt32  mbist_fcic_int_2_bist_done:1;
        RBus_UInt32  mbist_fcic_template_1_bist_done:1;
        RBus_UInt32  mbist_fcic_template_2_bist_done:1;
        RBus_UInt32  mbist_fcic_template_bist_done:1;
        RBus_UInt32  mbist_fcic_ed_bist_done:1;
        RBus_UInt32  res1:24;
    };
}fcic_top_fcic_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_16728_1_drf_done:1;
        RBus_UInt32  mbist_fcic_16728_2_drf_done:1;
        RBus_UInt32  mbist_fcic_int_1_drf_done:1;
        RBus_UInt32  mbist_fcic_int_2_drf_done:1;
        RBus_UInt32  mbist_fcic_template_1_drf_done:1;
        RBus_UInt32  mbist_fcic_template_2_drf_done:1;
        RBus_UInt32  mbist_fcic_template_drf_done:1;
        RBus_UInt32  mbist_fcic_ed_drf_done:1;
        RBus_UInt32  res1:24;
    };
}fcic_top_fcic_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_16728_1_bist_fail:8;
        RBus_UInt32  mbist_fcic_16728_2_bist_fail:8;
        RBus_UInt32  mbist_fcic_int_1_bist_fail:6;
        RBus_UInt32  mbist_fcic_int_2_bist_fail:6;
        RBus_UInt32  res1:4;
    };
}fcic_top_fcic_bist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_template_1_bist_fail:8;
        RBus_UInt32  mbist_fcic_template_2_bist_fail:8;
        RBus_UInt32  mbist_fcic_template_bist_fail:7;
        RBus_UInt32  mbist_fcic_ed_bist_fail:1;
        RBus_UInt32  res1:8;
    };
}fcic_top_fcic_bist_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_16728_1_drf_fail:8;
        RBus_UInt32  mbist_fcic_16728_2_drf_fail:8;
        RBus_UInt32  mbist_fcic_int_1_drf_fail:6;
        RBus_UInt32  mbist_fcic_int_2_drf_fail:6;
        RBus_UInt32  res1:4;
    };
}fcic_top_fcic_drf_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_template_1_drf_fail:8;
        RBus_UInt32  mbist_fcic_template_2_drf_fail:8;
        RBus_UInt32  mbist_fcic_template_drf_fail:7;
        RBus_UInt32  mbist_fcic_ed_drf_fail:1;
        RBus_UInt32  res1:8;
    };
}fcic_top_fcic_drf_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_fcic_16728_1_drf_pause:1;
        RBus_UInt32  mbist_fcic_16728_2_drf_pause:1;
        RBus_UInt32  mbist_fcic_int_1_drf_pause:1;
        RBus_UInt32  mbist_fcic_int_2_drf_pause:1;
        RBus_UInt32  mbist_fcic_template_1_drf_pause:1;
        RBus_UInt32  mbist_fcic_template_2_drf_pause:1;
        RBus_UInt32  mbist_fcic_template_drf_pause:1;
        RBus_UInt32  mbist_fcic_ed_drf_pause:1;
        RBus_UInt32  res1:24;
    };
}fcic_top_fcic_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_16728_1_rme_0:1;
        RBus_UInt32  fcic_16728_1_rme_1:1;
        RBus_UInt32  fcic_16728_1_rme_2:1;
        RBus_UInt32  fcic_16728_1_rme_3:1;
        RBus_UInt32  fcic_16728_1_rme_4:1;
        RBus_UInt32  fcic_16728_1_rme_5:1;
        RBus_UInt32  fcic_16728_1_rme_6:1;
        RBus_UInt32  fcic_16728_1_rme_7:1;
        RBus_UInt32  fcic_16728_2_rme_0:1;
        RBus_UInt32  fcic_16728_2_rme_1:1;
        RBus_UInt32  fcic_16728_2_rme_2:1;
        RBus_UInt32  fcic_16728_2_rme_3:1;
        RBus_UInt32  fcic_16728_2_rme_4:1;
        RBus_UInt32  fcic_16728_2_rme_5:1;
        RBus_UInt32  fcic_16728_2_rme_6:1;
        RBus_UInt32  fcic_16728_2_rme_7:1;
        RBus_UInt32  fcic_int_1_rme_0:1;
        RBus_UInt32  fcic_int_1_rme_1:1;
        RBus_UInt32  fcic_int_1_rme_2:1;
        RBus_UInt32  fcic_int_1_rme_3:1;
        RBus_UInt32  fcic_int_1_rme_4:1;
        RBus_UInt32  fcic_int_1_rme_5:1;
        RBus_UInt32  fcic_int_2_rme_0:1;
        RBus_UInt32  fcic_int_2_rme_1:1;
        RBus_UInt32  fcic_int_2_rme_2:1;
        RBus_UInt32  fcic_int_2_rme_3:1;
        RBus_UInt32  fcic_int_2_rme_4:1;
        RBus_UInt32  fcic_int_2_rme_5:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  testrwm:1;
    };
}fcic_top_fcic_rme_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_template_1_rme_0:1;
        RBus_UInt32  fcic_template_1_rme_1:1;
        RBus_UInt32  fcic_template_1_rme_2:1;
        RBus_UInt32  fcic_template_1_rme_3:1;
        RBus_UInt32  fcic_template_1_rme_4:1;
        RBus_UInt32  fcic_template_1_rme_5:1;
        RBus_UInt32  fcic_template_1_rme_6:1;
        RBus_UInt32  fcic_template_1_rme_7:1;
        RBus_UInt32  fcic_template_2_rme_0:1;
        RBus_UInt32  fcic_template_2_rme_1:1;
        RBus_UInt32  fcic_template_2_rme_2:1;
        RBus_UInt32  fcic_template_2_rme_3:1;
        RBus_UInt32  fcic_template_2_rme_4:1;
        RBus_UInt32  fcic_template_2_rme_5:1;
        RBus_UInt32  fcic_template_2_rme_6:1;
        RBus_UInt32  fcic_template_2_rme_7:1;
        RBus_UInt32  fcic_template_rme_0:1;
        RBus_UInt32  fcic_template_rme_1:1;
        RBus_UInt32  fcic_template_rme_2:1;
        RBus_UInt32  fcic_template_rme_3:1;
        RBus_UInt32  fcic_template_rme_4:1;
        RBus_UInt32  fcic_template_rme_5:1;
        RBus_UInt32  fcic_template_rme_6:1;
        RBus_UInt32  fcic_ed_rme_0:1;
        RBus_UInt32  res1:8;
    };
}fcic_top_fcic_rme_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_16728_1_rm_0:4;
        RBus_UInt32  fcic_16728_1_rm_1:4;
        RBus_UInt32  fcic_16728_1_rm_2:4;
        RBus_UInt32  fcic_16728_1_rm_3:4;
        RBus_UInt32  fcic_16728_1_rm_4:4;
        RBus_UInt32  fcic_16728_1_rm_5:4;
        RBus_UInt32  fcic_16728_1_rm_6:4;
        RBus_UInt32  fcic_16728_1_rm_7:4;
    };
}fcic_top_fcic_rm_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_16728_2_rm_0:4;
        RBus_UInt32  fcic_16728_2_rm_1:4;
        RBus_UInt32  fcic_16728_2_rm_2:4;
        RBus_UInt32  fcic_16728_2_rm_3:4;
        RBus_UInt32  fcic_16728_2_rm_4:4;
        RBus_UInt32  fcic_16728_2_rm_5:4;
        RBus_UInt32  fcic_16728_2_rm_6:4;
        RBus_UInt32  fcic_16728_2_rm_7:4;
    };
}fcic_top_fcic_rm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_int_1_rm_0:4;
        RBus_UInt32  fcic_int_1_rm_1:4;
        RBus_UInt32  fcic_int_1_rm_2:4;
        RBus_UInt32  fcic_int_1_rm_3:4;
        RBus_UInt32  fcic_int_1_rm_4:4;
        RBus_UInt32  fcic_int_1_rm_5:4;
        RBus_UInt32  res1:8;
    };
}fcic_top_fcic_rm_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_int_2_rm_0:4;
        RBus_UInt32  fcic_int_2_rm_1:4;
        RBus_UInt32  fcic_int_2_rm_2:4;
        RBus_UInt32  fcic_int_2_rm_3:4;
        RBus_UInt32  fcic_int_2_rm_4:4;
        RBus_UInt32  fcic_int_2_rm_5:4;
        RBus_UInt32  res1:8;
    };
}fcic_top_fcic_rm_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_template_1_rm_0:4;
        RBus_UInt32  fcic_template_1_rm_1:4;
        RBus_UInt32  fcic_template_1_rm_2:4;
        RBus_UInt32  fcic_template_1_rm_3:4;
        RBus_UInt32  fcic_template_1_rm_4:4;
        RBus_UInt32  fcic_template_1_rm_5:4;
        RBus_UInt32  fcic_template_1_rm_6:4;
        RBus_UInt32  fcic_template_1_rm_7:4;
    };
}fcic_top_fcic_rm_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_template_2_rm_0:4;
        RBus_UInt32  fcic_template_2_rm_1:4;
        RBus_UInt32  fcic_template_2_rm_2:4;
        RBus_UInt32  fcic_template_2_rm_3:4;
        RBus_UInt32  fcic_template_2_rm_4:4;
        RBus_UInt32  fcic_template_2_rm_5:4;
        RBus_UInt32  fcic_template_2_rm_6:4;
        RBus_UInt32  fcic_template_2_rm_7:4;
    };
}fcic_top_fcic_rm_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_template_rm_0:4;
        RBus_UInt32  fcic_template_rm_1:4;
        RBus_UInt32  fcic_template_rm_2:4;
        RBus_UInt32  fcic_template_rm_3:4;
        RBus_UInt32  fcic_template_rm_4:4;
        RBus_UInt32  fcic_template_rm_5:4;
        RBus_UInt32  fcic_template_rm_6:4;
        RBus_UInt32  fcic_ed_rm_0:4;
    };
}fcic_top_fcic_rm_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcic_io_reg_en:1;
        RBus_UInt32  mplus_opt:1;
        RBus_UInt32  color_1:2;
        RBus_UInt32  color_2:2;
        RBus_UInt32  color_3:2;
        RBus_UInt32  color_4:2;
        RBus_UInt32  res1:22;
    };
}fcic_top_fcic_io_reg_RBUS;




#endif 


#endif 
