/**
* @file Mac5-DesignSpec-D-Domain_LGD_M_plus
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LG_M_PLUS_REG_H_
#define _RBUS_LG_M_PLUS_REG_H_

#include "rbus_types.h"



//  LG_M_PLUS Register Address
#define  LG_M_PLUS_M_plus_ctl                                                    0x18028C00
#define  LG_M_PLUS_M_plus_ctl_reg_addr                                           "0xB8028C00"
#define  LG_M_PLUS_M_plus_ctl_reg                                                0xB8028C00
#define  LG_M_PLUS_M_plus_ctl_inst_addr                                          "0x0000"
#define  set_LG_M_PLUS_M_plus_ctl_reg(data)                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_ctl_reg)=data)
#define  get_LG_M_PLUS_M_plus_ctl_reg                                            (*((volatile unsigned int*)LG_M_PLUS_M_plus_ctl_reg))
#define  LG_M_PLUS_M_plus_ctl_wpr_on_shift                                       (31)
#define  LG_M_PLUS_M_plus_ctl_opc_on_shift                                       (30)
#define  LG_M_PLUS_M_plus_ctl_wse_on_shift                                       (29)
#define  LG_M_PLUS_M_plus_ctl_user_timing_sel_shift                              (12)
#define  LG_M_PLUS_M_plus_ctl_auto_detect_result_shift                           (8)
#define  LG_M_PLUS_M_plus_ctl_type_sel_shift                                     (6)
#define  LG_M_PLUS_M_plus_ctl_bypass_on_shift                                    (5)
#define  LG_M_PLUS_M_plus_ctl_auto_detect_en_shift                               (4)
#define  LG_M_PLUS_M_plus_ctl_mode_3d_shift                                      (3)
#define  LG_M_PLUS_M_plus_ctl_test_mode_shift                                    (2)
#define  LG_M_PLUS_M_plus_ctl_mode_sel_shift                                     (0)
#define  LG_M_PLUS_M_plus_ctl_wpr_on_mask                                        (0x80000000)
#define  LG_M_PLUS_M_plus_ctl_opc_on_mask                                        (0x40000000)
#define  LG_M_PLUS_M_plus_ctl_wse_on_mask                                        (0x20000000)
#define  LG_M_PLUS_M_plus_ctl_user_timing_sel_mask                               (0x00001000)
#define  LG_M_PLUS_M_plus_ctl_auto_detect_result_mask                            (0x00000100)
#define  LG_M_PLUS_M_plus_ctl_type_sel_mask                                      (0x00000040)
#define  LG_M_PLUS_M_plus_ctl_bypass_on_mask                                     (0x00000020)
#define  LG_M_PLUS_M_plus_ctl_auto_detect_en_mask                                (0x00000010)
#define  LG_M_PLUS_M_plus_ctl_mode_3d_mask                                       (0x00000008)
#define  LG_M_PLUS_M_plus_ctl_test_mode_mask                                     (0x00000004)
#define  LG_M_PLUS_M_plus_ctl_mode_sel_mask                                      (0x00000003)
#define  LG_M_PLUS_M_plus_ctl_wpr_on(data)                                       (0x80000000&((data)<<31))
#define  LG_M_PLUS_M_plus_ctl_opc_on(data)                                       (0x40000000&((data)<<30))
#define  LG_M_PLUS_M_plus_ctl_wse_on(data)                                       (0x20000000&((data)<<29))
#define  LG_M_PLUS_M_plus_ctl_user_timing_sel(data)                              (0x00001000&((data)<<12))
#define  LG_M_PLUS_M_plus_ctl_auto_detect_result(data)                           (0x00000100&((data)<<8))
#define  LG_M_PLUS_M_plus_ctl_type_sel(data)                                     (0x00000040&((data)<<6))
#define  LG_M_PLUS_M_plus_ctl_bypass_on(data)                                    (0x00000020&((data)<<5))
#define  LG_M_PLUS_M_plus_ctl_auto_detect_en(data)                               (0x00000010&((data)<<4))
#define  LG_M_PLUS_M_plus_ctl_mode_3d(data)                                      (0x00000008&((data)<<3))
#define  LG_M_PLUS_M_plus_ctl_test_mode(data)                                    (0x00000004&((data)<<2))
#define  LG_M_PLUS_M_plus_ctl_mode_sel(data)                                     (0x00000003&(data))
#define  LG_M_PLUS_M_plus_ctl_get_wpr_on(data)                                   ((0x80000000&(data))>>31)
#define  LG_M_PLUS_M_plus_ctl_get_opc_on(data)                                   ((0x40000000&(data))>>30)
#define  LG_M_PLUS_M_plus_ctl_get_wse_on(data)                                   ((0x20000000&(data))>>29)
#define  LG_M_PLUS_M_plus_ctl_get_user_timing_sel(data)                          ((0x00001000&(data))>>12)
#define  LG_M_PLUS_M_plus_ctl_get_auto_detect_result(data)                       ((0x00000100&(data))>>8)
#define  LG_M_PLUS_M_plus_ctl_get_type_sel(data)                                 ((0x00000040&(data))>>6)
#define  LG_M_PLUS_M_plus_ctl_get_bypass_on(data)                                ((0x00000020&(data))>>5)
#define  LG_M_PLUS_M_plus_ctl_get_auto_detect_en(data)                           ((0x00000010&(data))>>4)
#define  LG_M_PLUS_M_plus_ctl_get_mode_3d(data)                                  ((0x00000008&(data))>>3)
#define  LG_M_PLUS_M_plus_ctl_get_test_mode(data)                                ((0x00000004&(data))>>2)
#define  LG_M_PLUS_M_plus_ctl_get_mode_sel(data)                                 (0x00000003&(data))

#define  LG_M_PLUS_M_plus_reg00                                                  0x18028C04
#define  LG_M_PLUS_M_plus_reg00_reg_addr                                         "0xB8028C04"
#define  LG_M_PLUS_M_plus_reg00_reg                                              0xB8028C04
#define  LG_M_PLUS_M_plus_reg00_inst_addr                                        "0x0001"
#define  set_LG_M_PLUS_M_plus_reg00_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg00_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg00_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg00_reg))
#define  LG_M_PLUS_M_plus_reg00_wpr_reg00_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg00_wpr_reg01_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg00_wpr_reg02_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg00_wpr_reg03_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg00_wpr_reg00_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg00_wpr_reg01_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg00_wpr_reg02_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg00_wpr_reg03_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg00_wpr_reg00(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg00_wpr_reg01(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg00_wpr_reg02(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg00_wpr_reg03(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg00_get_wpr_reg00(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg00_get_wpr_reg01(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg00_get_wpr_reg02(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg00_get_wpr_reg03(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg04                                                  0x18028C08
#define  LG_M_PLUS_M_plus_reg04_reg_addr                                         "0xB8028C08"
#define  LG_M_PLUS_M_plus_reg04_reg                                              0xB8028C08
#define  LG_M_PLUS_M_plus_reg04_inst_addr                                        "0x0002"
#define  set_LG_M_PLUS_M_plus_reg04_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg04_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg04_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg04_reg))
#define  LG_M_PLUS_M_plus_reg04_wpr_reg04_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg04_wpr_reg05_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg04_wpr_reg06_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg04_wpr_reg07_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg04_wpr_reg04_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg04_wpr_reg05_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg04_wpr_reg06_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg04_wpr_reg07_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg04_wpr_reg04(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg04_wpr_reg05(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg04_wpr_reg06(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg04_wpr_reg07(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg04_get_wpr_reg04(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg04_get_wpr_reg05(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg04_get_wpr_reg06(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg04_get_wpr_reg07(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg08                                                  0x18028C0C
#define  LG_M_PLUS_M_plus_reg08_reg_addr                                         "0xB8028C0C"
#define  LG_M_PLUS_M_plus_reg08_reg                                              0xB8028C0C
#define  LG_M_PLUS_M_plus_reg08_inst_addr                                        "0x0003"
#define  set_LG_M_PLUS_M_plus_reg08_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg08_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg08_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg08_reg))
#define  LG_M_PLUS_M_plus_reg08_wpr_reg08_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg08_wpr_reg09_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg08_wpr_reg0a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg08_wpr_reg0b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg08_wpr_reg08_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg08_wpr_reg09_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg08_wpr_reg0a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg08_wpr_reg0b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg08_wpr_reg08(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg08_wpr_reg09(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg08_wpr_reg0a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg08_wpr_reg0b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg08_get_wpr_reg08(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg08_get_wpr_reg09(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg08_get_wpr_reg0a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg08_get_wpr_reg0b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg0c                                                  0x18028C10
#define  LG_M_PLUS_M_plus_reg0c_reg_addr                                         "0xB8028C10"
#define  LG_M_PLUS_M_plus_reg0c_reg                                              0xB8028C10
#define  LG_M_PLUS_M_plus_reg0c_inst_addr                                        "0x0004"
#define  set_LG_M_PLUS_M_plus_reg0c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg0c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg0c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg0c_reg))
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg0c_wpr_reg0f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg0c_get_wpr_reg0c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg0c_get_wpr_reg0d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg0c_get_wpr_reg0e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg0c_get_wpr_reg0f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg10                                                  0x18028C14
#define  LG_M_PLUS_M_plus_reg10_reg_addr                                         "0xB8028C14"
#define  LG_M_PLUS_M_plus_reg10_reg                                              0xB8028C14
#define  LG_M_PLUS_M_plus_reg10_inst_addr                                        "0x0005"
#define  set_LG_M_PLUS_M_plus_reg10_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg10_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg10_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg10_reg))
#define  LG_M_PLUS_M_plus_reg10_wpr_reg10_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg10_wpr_reg11_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg10_wpr_reg12_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg10_wpr_reg13_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg10_wpr_reg10_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg10_wpr_reg11_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg10_wpr_reg12_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg10_wpr_reg13_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg10_wpr_reg10(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg10_wpr_reg11(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg10_wpr_reg12(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg10_wpr_reg13(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg10_get_wpr_reg10(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg10_get_wpr_reg11(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg10_get_wpr_reg12(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg10_get_wpr_reg13(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg14                                                  0x18028C18
#define  LG_M_PLUS_M_plus_reg14_reg_addr                                         "0xB8028C18"
#define  LG_M_PLUS_M_plus_reg14_reg                                              0xB8028C18
#define  LG_M_PLUS_M_plus_reg14_inst_addr                                        "0x0006"
#define  set_LG_M_PLUS_M_plus_reg14_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg14_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg14_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg14_reg))
#define  LG_M_PLUS_M_plus_reg14_wpr_reg14_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg14_wpr_reg15_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg14_wpr_reg16_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg14_wpr_reg17_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg14_wpr_reg14_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg14_wpr_reg15_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg14_wpr_reg16_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg14_wpr_reg17_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg14_wpr_reg14(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg14_wpr_reg15(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg14_wpr_reg16(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg14_wpr_reg17(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg14_get_wpr_reg14(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg14_get_wpr_reg15(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg14_get_wpr_reg16(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg14_get_wpr_reg17(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg18                                                  0x18028C1C
#define  LG_M_PLUS_M_plus_reg18_reg_addr                                         "0xB8028C1C"
#define  LG_M_PLUS_M_plus_reg18_reg                                              0xB8028C1C
#define  LG_M_PLUS_M_plus_reg18_inst_addr                                        "0x0007"
#define  set_LG_M_PLUS_M_plus_reg18_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg18_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg18_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg18_reg))
#define  LG_M_PLUS_M_plus_reg18_wpr_reg18_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg18_wpr_reg19_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg18_wpr_reg1a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg18_wpr_reg1b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg18_wpr_reg18_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg18_wpr_reg19_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg18_wpr_reg1a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg18_wpr_reg1b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg18_wpr_reg18(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg18_wpr_reg19(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg18_wpr_reg1a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg18_wpr_reg1b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg18_get_wpr_reg18(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg18_get_wpr_reg19(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg18_get_wpr_reg1a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg18_get_wpr_reg1b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg1c                                                  0x18028C20
#define  LG_M_PLUS_M_plus_reg1c_reg_addr                                         "0xB8028C20"
#define  LG_M_PLUS_M_plus_reg1c_reg                                              0xB8028C20
#define  LG_M_PLUS_M_plus_reg1c_inst_addr                                        "0x0008"
#define  set_LG_M_PLUS_M_plus_reg1c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg1c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg1c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg1c_reg))
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg1c_wpr_reg1f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg1c_get_wpr_reg1c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg1c_get_wpr_reg1d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg1c_get_wpr_reg1e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg1c_get_wpr_reg1f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg20                                                  0x18028C24
#define  LG_M_PLUS_M_plus_reg20_reg_addr                                         "0xB8028C24"
#define  LG_M_PLUS_M_plus_reg20_reg                                              0xB8028C24
#define  LG_M_PLUS_M_plus_reg20_inst_addr                                        "0x0009"
#define  set_LG_M_PLUS_M_plus_reg20_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg20_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg20_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg20_reg))
#define  LG_M_PLUS_M_plus_reg20_wpr_reg20_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg20_wpr_reg21_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg20_wpr_reg22_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg20_wpr_reg23_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg20_wpr_reg20_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg20_wpr_reg21_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg20_wpr_reg22_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg20_wpr_reg23_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg20_wpr_reg20(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg20_wpr_reg21(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg20_wpr_reg22(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg20_wpr_reg23(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg20_get_wpr_reg20(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg20_get_wpr_reg21(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg20_get_wpr_reg22(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg20_get_wpr_reg23(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg24                                                  0x18028C28
#define  LG_M_PLUS_M_plus_reg24_reg_addr                                         "0xB8028C28"
#define  LG_M_PLUS_M_plus_reg24_reg                                              0xB8028C28
#define  LG_M_PLUS_M_plus_reg24_inst_addr                                        "0x000A"
#define  set_LG_M_PLUS_M_plus_reg24_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg24_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg24_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg24_reg))
#define  LG_M_PLUS_M_plus_reg24_wpr_reg24_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg24_wpr_reg25_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg24_wpr_reg26_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg24_wpr_reg27_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg24_wpr_reg24_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg24_wpr_reg25_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg24_wpr_reg26_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg24_wpr_reg27_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg24_wpr_reg24(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg24_wpr_reg25(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg24_wpr_reg26(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg24_wpr_reg27(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg24_get_wpr_reg24(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg24_get_wpr_reg25(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg24_get_wpr_reg26(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg24_get_wpr_reg27(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg28                                                  0x18028C2C
#define  LG_M_PLUS_M_plus_reg28_reg_addr                                         "0xB8028C2C"
#define  LG_M_PLUS_M_plus_reg28_reg                                              0xB8028C2C
#define  LG_M_PLUS_M_plus_reg28_inst_addr                                        "0x000B"
#define  set_LG_M_PLUS_M_plus_reg28_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg28_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg28_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg28_reg))
#define  LG_M_PLUS_M_plus_reg28_wpr_reg28_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg28_wpr_reg29_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg28_wpr_reg2a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg28_wpr_reg2b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg28_wpr_reg28_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg28_wpr_reg29_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg28_wpr_reg2a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg28_wpr_reg2b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg28_wpr_reg28(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg28_wpr_reg29(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg28_wpr_reg2a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg28_wpr_reg2b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg28_get_wpr_reg28(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg28_get_wpr_reg29(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg28_get_wpr_reg2a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg28_get_wpr_reg2b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg2c                                                  0x18028C30
#define  LG_M_PLUS_M_plus_reg2c_reg_addr                                         "0xB8028C30"
#define  LG_M_PLUS_M_plus_reg2c_reg                                              0xB8028C30
#define  LG_M_PLUS_M_plus_reg2c_inst_addr                                        "0x000C"
#define  set_LG_M_PLUS_M_plus_reg2c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg2c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg2c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg2c_reg))
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg2c_wpr_reg2f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg2c_get_wpr_reg2c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg2c_get_wpr_reg2d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg2c_get_wpr_reg2e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg2c_get_wpr_reg2f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg30                                                  0x18028C34
#define  LG_M_PLUS_M_plus_reg30_reg_addr                                         "0xB8028C34"
#define  LG_M_PLUS_M_plus_reg30_reg                                              0xB8028C34
#define  LG_M_PLUS_M_plus_reg30_inst_addr                                        "0x000D"
#define  set_LG_M_PLUS_M_plus_reg30_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg30_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg30_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg30_reg))
#define  LG_M_PLUS_M_plus_reg30_wpr_reg30_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg30_wpr_reg31_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg30_wpr_reg32_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg30_wpr_reg33_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg30_wpr_reg30_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg30_wpr_reg31_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg30_wpr_reg32_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg30_wpr_reg33_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg30_wpr_reg30(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg30_wpr_reg31(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg30_wpr_reg32(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg30_wpr_reg33(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg30_get_wpr_reg30(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg30_get_wpr_reg31(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg30_get_wpr_reg32(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg30_get_wpr_reg33(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg34                                                  0x18028C38
#define  LG_M_PLUS_M_plus_reg34_reg_addr                                         "0xB8028C38"
#define  LG_M_PLUS_M_plus_reg34_reg                                              0xB8028C38
#define  LG_M_PLUS_M_plus_reg34_inst_addr                                        "0x000E"
#define  set_LG_M_PLUS_M_plus_reg34_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg34_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg34_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg34_reg))
#define  LG_M_PLUS_M_plus_reg34_wpr_reg34_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg34_wpr_reg35_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg34_wpr_reg36_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg34_wpr_reg37_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg34_wpr_reg34_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg34_wpr_reg35_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg34_wpr_reg36_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg34_wpr_reg37_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg34_wpr_reg34(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg34_wpr_reg35(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg34_wpr_reg36(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg34_wpr_reg37(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg34_get_wpr_reg34(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg34_get_wpr_reg35(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg34_get_wpr_reg36(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg34_get_wpr_reg37(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg38                                                  0x18028C3C
#define  LG_M_PLUS_M_plus_reg38_reg_addr                                         "0xB8028C3C"
#define  LG_M_PLUS_M_plus_reg38_reg                                              0xB8028C3C
#define  LG_M_PLUS_M_plus_reg38_inst_addr                                        "0x000F"
#define  set_LG_M_PLUS_M_plus_reg38_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg38_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg38_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg38_reg))
#define  LG_M_PLUS_M_plus_reg38_wpr_reg38_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg38_wpr_reg39_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg38_wpr_reg3a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg38_wpr_reg3b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg38_wpr_reg38_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg38_wpr_reg39_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg38_wpr_reg3a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg38_wpr_reg3b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg38_wpr_reg38(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg38_wpr_reg39(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg38_wpr_reg3a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg38_wpr_reg3b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg38_get_wpr_reg38(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg38_get_wpr_reg39(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg38_get_wpr_reg3a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg38_get_wpr_reg3b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg3c                                                  0x18028C40
#define  LG_M_PLUS_M_plus_reg3c_reg_addr                                         "0xB8028C40"
#define  LG_M_PLUS_M_plus_reg3c_reg                                              0xB8028C40
#define  LG_M_PLUS_M_plus_reg3c_inst_addr                                        "0x0010"
#define  set_LG_M_PLUS_M_plus_reg3c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg3c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg3c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg3c_reg))
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg3c_wpr_reg3f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg3c_get_wpr_reg3c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg3c_get_wpr_reg3d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg3c_get_wpr_reg3e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg3c_get_wpr_reg3f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg40                                                  0x18028C44
#define  LG_M_PLUS_M_plus_reg40_reg_addr                                         "0xB8028C44"
#define  LG_M_PLUS_M_plus_reg40_reg                                              0xB8028C44
#define  LG_M_PLUS_M_plus_reg40_inst_addr                                        "0x0011"
#define  set_LG_M_PLUS_M_plus_reg40_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg40_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg40_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg40_reg))
#define  LG_M_PLUS_M_plus_reg40_wpr_reg40_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg40_wpr_reg41_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg40_wpr_reg42_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg40_wpr_reg43_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg40_wpr_reg40_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg40_wpr_reg41_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg40_wpr_reg42_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg40_wpr_reg43_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg40_wpr_reg40(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg40_wpr_reg41(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg40_wpr_reg42(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg40_wpr_reg43(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg40_get_wpr_reg40(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg40_get_wpr_reg41(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg40_get_wpr_reg42(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg40_get_wpr_reg43(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg44                                                  0x18028C48
#define  LG_M_PLUS_M_plus_reg44_reg_addr                                         "0xB8028C48"
#define  LG_M_PLUS_M_plus_reg44_reg                                              0xB8028C48
#define  LG_M_PLUS_M_plus_reg44_inst_addr                                        "0x0012"
#define  set_LG_M_PLUS_M_plus_reg44_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg44_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg44_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg44_reg))
#define  LG_M_PLUS_M_plus_reg44_wpr_reg44_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg44_wpr_reg45_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg44_wpr_reg46_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg44_wpr_reg47_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg44_wpr_reg44_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg44_wpr_reg45_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg44_wpr_reg46_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg44_wpr_reg47_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg44_wpr_reg44(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg44_wpr_reg45(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg44_wpr_reg46(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg44_wpr_reg47(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg44_get_wpr_reg44(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg44_get_wpr_reg45(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg44_get_wpr_reg46(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg44_get_wpr_reg47(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg48                                                  0x18028C4C
#define  LG_M_PLUS_M_plus_reg48_reg_addr                                         "0xB8028C4C"
#define  LG_M_PLUS_M_plus_reg48_reg                                              0xB8028C4C
#define  LG_M_PLUS_M_plus_reg48_inst_addr                                        "0x0013"
#define  set_LG_M_PLUS_M_plus_reg48_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg48_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg48_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg48_reg))
#define  LG_M_PLUS_M_plus_reg48_wpr_reg48_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg48_wpr_reg49_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg48_wpr_reg4a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg48_wpr_reg4b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg48_wpr_reg48_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg48_wpr_reg49_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg48_wpr_reg4a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg48_wpr_reg4b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg48_wpr_reg48(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg48_wpr_reg49(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg48_wpr_reg4a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg48_wpr_reg4b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg48_get_wpr_reg48(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg48_get_wpr_reg49(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg48_get_wpr_reg4a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg48_get_wpr_reg4b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg4c                                                  0x18028C50
#define  LG_M_PLUS_M_plus_reg4c_reg_addr                                         "0xB8028C50"
#define  LG_M_PLUS_M_plus_reg4c_reg                                              0xB8028C50
#define  LG_M_PLUS_M_plus_reg4c_inst_addr                                        "0x0014"
#define  set_LG_M_PLUS_M_plus_reg4c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg4c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg4c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg4c_reg))
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg4c_wpr_reg4f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg4c_get_wpr_reg4c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg4c_get_wpr_reg4d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg4c_get_wpr_reg4e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg4c_get_wpr_reg4f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg50                                                  0x18028C54
#define  LG_M_PLUS_M_plus_reg50_reg_addr                                         "0xB8028C54"
#define  LG_M_PLUS_M_plus_reg50_reg                                              0xB8028C54
#define  LG_M_PLUS_M_plus_reg50_inst_addr                                        "0x0015"
#define  set_LG_M_PLUS_M_plus_reg50_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg50_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg50_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg50_reg))
#define  LG_M_PLUS_M_plus_reg50_wpr_reg50_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg50_wpr_reg51_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg50_wpr_reg52_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg50_wpr_reg53_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg50_wpr_reg50_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg50_wpr_reg51_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg50_wpr_reg52_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg50_wpr_reg53_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg50_wpr_reg50(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg50_wpr_reg51(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg50_wpr_reg52(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg50_wpr_reg53(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg50_get_wpr_reg50(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg50_get_wpr_reg51(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg50_get_wpr_reg52(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg50_get_wpr_reg53(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg54                                                  0x18028C58
#define  LG_M_PLUS_M_plus_reg54_reg_addr                                         "0xB8028C58"
#define  LG_M_PLUS_M_plus_reg54_reg                                              0xB8028C58
#define  LG_M_PLUS_M_plus_reg54_inst_addr                                        "0x0016"
#define  set_LG_M_PLUS_M_plus_reg54_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg54_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg54_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg54_reg))
#define  LG_M_PLUS_M_plus_reg54_wpr_reg54_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg54_wpr_reg55_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg54_wpr_reg56_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg54_wpr_reg57_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg54_wpr_reg54_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg54_wpr_reg55_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg54_wpr_reg56_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg54_wpr_reg57_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg54_wpr_reg54(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg54_wpr_reg55(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg54_wpr_reg56(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg54_wpr_reg57(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg54_get_wpr_reg54(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg54_get_wpr_reg55(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg54_get_wpr_reg56(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg54_get_wpr_reg57(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg58                                                  0x18028C5C
#define  LG_M_PLUS_M_plus_reg58_reg_addr                                         "0xB8028C5C"
#define  LG_M_PLUS_M_plus_reg58_reg                                              0xB8028C5C
#define  LG_M_PLUS_M_plus_reg58_inst_addr                                        "0x0017"
#define  set_LG_M_PLUS_M_plus_reg58_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg58_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg58_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg58_reg))
#define  LG_M_PLUS_M_plus_reg58_wpr_reg58_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg58_wpr_reg59_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg58_wpr_reg5a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg58_wpr_reg5b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg58_wpr_reg58_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg58_wpr_reg59_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg58_wpr_reg5a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg58_wpr_reg5b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg58_wpr_reg58(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg58_wpr_reg59(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg58_wpr_reg5a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg58_wpr_reg5b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg58_get_wpr_reg58(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg58_get_wpr_reg59(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg58_get_wpr_reg5a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg58_get_wpr_reg5b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg5c                                                  0x18028C60
#define  LG_M_PLUS_M_plus_reg5c_reg_addr                                         "0xB8028C60"
#define  LG_M_PLUS_M_plus_reg5c_reg                                              0xB8028C60
#define  LG_M_PLUS_M_plus_reg5c_inst_addr                                        "0x0018"
#define  set_LG_M_PLUS_M_plus_reg5c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg5c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg5c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg5c_reg))
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg5c_wpr_reg5f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg5c_get_wpr_reg5c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg5c_get_wpr_reg5d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg5c_get_wpr_reg5e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg5c_get_wpr_reg5f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg60                                                  0x18028C64
#define  LG_M_PLUS_M_plus_reg60_reg_addr                                         "0xB8028C64"
#define  LG_M_PLUS_M_plus_reg60_reg                                              0xB8028C64
#define  LG_M_PLUS_M_plus_reg60_inst_addr                                        "0x0019"
#define  set_LG_M_PLUS_M_plus_reg60_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg60_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg60_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg60_reg))
#define  LG_M_PLUS_M_plus_reg60_wpr_reg60_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg60_wpr_reg61_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg60_wpr_reg62_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg60_wpr_reg63_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg60_wpr_reg60_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg60_wpr_reg61_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg60_wpr_reg62_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg60_wpr_reg63_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg60_wpr_reg60(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg60_wpr_reg61(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg60_wpr_reg62(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg60_wpr_reg63(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg60_get_wpr_reg60(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg60_get_wpr_reg61(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg60_get_wpr_reg62(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg60_get_wpr_reg63(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg64                                                  0x18028C68
#define  LG_M_PLUS_M_plus_reg64_reg_addr                                         "0xB8028C68"
#define  LG_M_PLUS_M_plus_reg64_reg                                              0xB8028C68
#define  LG_M_PLUS_M_plus_reg64_inst_addr                                        "0x001A"
#define  set_LG_M_PLUS_M_plus_reg64_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg64_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg64_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg64_reg))
#define  LG_M_PLUS_M_plus_reg64_wpr_reg64_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg64_wpr_reg65_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg64_wpr_reg66_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg64_wpr_reg67_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg64_wpr_reg64_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg64_wpr_reg65_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg64_wpr_reg66_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg64_wpr_reg67_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg64_wpr_reg64(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg64_wpr_reg65(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg64_wpr_reg66(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg64_wpr_reg67(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg64_get_wpr_reg64(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg64_get_wpr_reg65(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg64_get_wpr_reg66(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg64_get_wpr_reg67(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg68                                                  0x18028C6C
#define  LG_M_PLUS_M_plus_reg68_reg_addr                                         "0xB8028C6C"
#define  LG_M_PLUS_M_plus_reg68_reg                                              0xB8028C6C
#define  LG_M_PLUS_M_plus_reg68_inst_addr                                        "0x001B"
#define  set_LG_M_PLUS_M_plus_reg68_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg68_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg68_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg68_reg))
#define  LG_M_PLUS_M_plus_reg68_wpr_reg68_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg68_wpr_reg69_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg68_wpr_reg6a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg68_wpr_reg6b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg68_wpr_reg68_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg68_wpr_reg69_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg68_wpr_reg6a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg68_wpr_reg6b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg68_wpr_reg68(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg68_wpr_reg69(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg68_wpr_reg6a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg68_wpr_reg6b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg68_get_wpr_reg68(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg68_get_wpr_reg69(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg68_get_wpr_reg6a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg68_get_wpr_reg6b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg6c                                                  0x18028C70
#define  LG_M_PLUS_M_plus_reg6c_reg_addr                                         "0xB8028C70"
#define  LG_M_PLUS_M_plus_reg6c_reg                                              0xB8028C70
#define  LG_M_PLUS_M_plus_reg6c_inst_addr                                        "0x001C"
#define  set_LG_M_PLUS_M_plus_reg6c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg6c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg6c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg6c_reg))
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg6c_wpr_reg6f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg6c_get_wpr_reg6c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg6c_get_wpr_reg6d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg6c_get_wpr_reg6e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg6c_get_wpr_reg6f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg70                                                  0x18028C74
#define  LG_M_PLUS_M_plus_reg70_reg_addr                                         "0xB8028C74"
#define  LG_M_PLUS_M_plus_reg70_reg                                              0xB8028C74
#define  LG_M_PLUS_M_plus_reg70_inst_addr                                        "0x001D"
#define  set_LG_M_PLUS_M_plus_reg70_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg70_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg70_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg70_reg))
#define  LG_M_PLUS_M_plus_reg70_wpr_reg70_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg70_wpr_reg71_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg70_wpr_reg72_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg70_wpr_reg73_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg70_wpr_reg70_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg70_wpr_reg71_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg70_wpr_reg72_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg70_wpr_reg73_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg70_wpr_reg70(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg70_wpr_reg71(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg70_wpr_reg72(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg70_wpr_reg73(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg70_get_wpr_reg70(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg70_get_wpr_reg71(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg70_get_wpr_reg72(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg70_get_wpr_reg73(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg74                                                  0x18028C78
#define  LG_M_PLUS_M_plus_reg74_reg_addr                                         "0xB8028C78"
#define  LG_M_PLUS_M_plus_reg74_reg                                              0xB8028C78
#define  LG_M_PLUS_M_plus_reg74_inst_addr                                        "0x001E"
#define  set_LG_M_PLUS_M_plus_reg74_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg74_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg74_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg74_reg))
#define  LG_M_PLUS_M_plus_reg74_wpr_reg74_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg74_wpr_reg75_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg74_wpr_reg76_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg74_wpr_reg77_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg74_wpr_reg74_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg74_wpr_reg75_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg74_wpr_reg76_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg74_wpr_reg77_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg74_wpr_reg74(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg74_wpr_reg75(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg74_wpr_reg76(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg74_wpr_reg77(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg74_get_wpr_reg74(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg74_get_wpr_reg75(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg74_get_wpr_reg76(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg74_get_wpr_reg77(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg78                                                  0x18028C7C
#define  LG_M_PLUS_M_plus_reg78_reg_addr                                         "0xB8028C7C"
#define  LG_M_PLUS_M_plus_reg78_reg                                              0xB8028C7C
#define  LG_M_PLUS_M_plus_reg78_inst_addr                                        "0x001F"
#define  set_LG_M_PLUS_M_plus_reg78_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg78_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg78_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg78_reg))
#define  LG_M_PLUS_M_plus_reg78_wpr_reg78_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg78_wpr_reg79_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg78_wpr_reg7a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg78_wpr_reg7b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg78_wpr_reg78_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg78_wpr_reg79_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg78_wpr_reg7a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg78_wpr_reg7b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg78_wpr_reg78(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg78_wpr_reg79(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg78_wpr_reg7a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg78_wpr_reg7b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg78_get_wpr_reg78(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg78_get_wpr_reg79(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg78_get_wpr_reg7a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg78_get_wpr_reg7b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg7c                                                  0x18028C80
#define  LG_M_PLUS_M_plus_reg7c_reg_addr                                         "0xB8028C80"
#define  LG_M_PLUS_M_plus_reg7c_reg                                              0xB8028C80
#define  LG_M_PLUS_M_plus_reg7c_inst_addr                                        "0x0020"
#define  set_LG_M_PLUS_M_plus_reg7c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg7c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg7c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg7c_reg))
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg7c_wpr_reg7f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg7c_get_wpr_reg7c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg7c_get_wpr_reg7d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg7c_get_wpr_reg7e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg7c_get_wpr_reg7f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg80                                                  0x18028C84
#define  LG_M_PLUS_M_plus_reg80_reg_addr                                         "0xB8028C84"
#define  LG_M_PLUS_M_plus_reg80_reg                                              0xB8028C84
#define  LG_M_PLUS_M_plus_reg80_inst_addr                                        "0x0021"
#define  set_LG_M_PLUS_M_plus_reg80_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg80_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg80_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg80_reg))
#define  LG_M_PLUS_M_plus_reg80_wpr_reg80_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg80_wpr_reg81_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg80_wpr_reg82_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg80_wpr_reg83_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg80_wpr_reg80_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg80_wpr_reg81_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg80_wpr_reg82_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg80_wpr_reg83_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg80_wpr_reg80(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg80_wpr_reg81(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg80_wpr_reg82(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg80_wpr_reg83(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg80_get_wpr_reg80(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg80_get_wpr_reg81(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg80_get_wpr_reg82(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg80_get_wpr_reg83(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg84                                                  0x18028C88
#define  LG_M_PLUS_M_plus_reg84_reg_addr                                         "0xB8028C88"
#define  LG_M_PLUS_M_plus_reg84_reg                                              0xB8028C88
#define  LG_M_PLUS_M_plus_reg84_inst_addr                                        "0x0022"
#define  set_LG_M_PLUS_M_plus_reg84_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg84_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg84_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg84_reg))
#define  LG_M_PLUS_M_plus_reg84_wpr_reg84_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg84_wpr_reg85_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg84_wpr_reg86_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg84_wpr_reg87_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg84_wpr_reg84_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg84_wpr_reg85_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg84_wpr_reg86_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg84_wpr_reg87_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg84_wpr_reg84(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg84_wpr_reg85(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg84_wpr_reg86(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg84_wpr_reg87(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg84_get_wpr_reg84(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg84_get_wpr_reg85(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg84_get_wpr_reg86(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg84_get_wpr_reg87(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg88                                                  0x18028C8C
#define  LG_M_PLUS_M_plus_reg88_reg_addr                                         "0xB8028C8C"
#define  LG_M_PLUS_M_plus_reg88_reg                                              0xB8028C8C
#define  LG_M_PLUS_M_plus_reg88_inst_addr                                        "0x0023"
#define  set_LG_M_PLUS_M_plus_reg88_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg88_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg88_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg88_reg))
#define  LG_M_PLUS_M_plus_reg88_wpr_reg88_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg88_wpr_reg89_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg88_wpr_reg8a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg88_wpr_reg8b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg88_wpr_reg88_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg88_wpr_reg89_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg88_wpr_reg8a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg88_wpr_reg8b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg88_wpr_reg88(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg88_wpr_reg89(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg88_wpr_reg8a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg88_wpr_reg8b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg88_get_wpr_reg88(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg88_get_wpr_reg89(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg88_get_wpr_reg8a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg88_get_wpr_reg8b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg8c                                                  0x18028C90
#define  LG_M_PLUS_M_plus_reg8c_reg_addr                                         "0xB8028C90"
#define  LG_M_PLUS_M_plus_reg8c_reg                                              0xB8028C90
#define  LG_M_PLUS_M_plus_reg8c_inst_addr                                        "0x0024"
#define  set_LG_M_PLUS_M_plus_reg8c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg8c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg8c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg8c_reg))
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg8c_wpr_reg8f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg8c_get_wpr_reg8c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg8c_get_wpr_reg8d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg8c_get_wpr_reg8e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg8c_get_wpr_reg8f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg90                                                  0x18028C94
#define  LG_M_PLUS_M_plus_reg90_reg_addr                                         "0xB8028C94"
#define  LG_M_PLUS_M_plus_reg90_reg                                              0xB8028C94
#define  LG_M_PLUS_M_plus_reg90_inst_addr                                        "0x0025"
#define  set_LG_M_PLUS_M_plus_reg90_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg90_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg90_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg90_reg))
#define  LG_M_PLUS_M_plus_reg90_wpr_reg90_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg90_wpr_reg91_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg90_wpr_reg92_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg90_wpr_reg93_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg90_wpr_reg90_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg90_wpr_reg91_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg90_wpr_reg92_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg90_wpr_reg93_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg90_wpr_reg90(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg90_wpr_reg91(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg90_wpr_reg92(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg90_wpr_reg93(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg90_get_wpr_reg90(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg90_get_wpr_reg91(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg90_get_wpr_reg92(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg90_get_wpr_reg93(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg94                                                  0x18028C98
#define  LG_M_PLUS_M_plus_reg94_reg_addr                                         "0xB8028C98"
#define  LG_M_PLUS_M_plus_reg94_reg                                              0xB8028C98
#define  LG_M_PLUS_M_plus_reg94_inst_addr                                        "0x0026"
#define  set_LG_M_PLUS_M_plus_reg94_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg94_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg94_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg94_reg))
#define  LG_M_PLUS_M_plus_reg94_wpr_reg94_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg94_wpr_reg95_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg94_wpr_reg96_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg94_wpr_reg97_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg94_wpr_reg94_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg94_wpr_reg95_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg94_wpr_reg96_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg94_wpr_reg97_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg94_wpr_reg94(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg94_wpr_reg95(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg94_wpr_reg96(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg94_wpr_reg97(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg94_get_wpr_reg94(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg94_get_wpr_reg95(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg94_get_wpr_reg96(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg94_get_wpr_reg97(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg98                                                  0x18028C9C
#define  LG_M_PLUS_M_plus_reg98_reg_addr                                         "0xB8028C9C"
#define  LG_M_PLUS_M_plus_reg98_reg                                              0xB8028C9C
#define  LG_M_PLUS_M_plus_reg98_inst_addr                                        "0x0027"
#define  set_LG_M_PLUS_M_plus_reg98_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg98_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg98_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg98_reg))
#define  LG_M_PLUS_M_plus_reg98_wpr_reg98_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg98_wpr_reg99_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg98_wpr_reg9a_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg98_wpr_reg9b_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg98_wpr_reg98_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg98_wpr_reg99_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg98_wpr_reg9a_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg98_wpr_reg9b_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg98_wpr_reg98(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg98_wpr_reg99(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg98_wpr_reg9a(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg98_wpr_reg9b(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg98_get_wpr_reg98(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg98_get_wpr_reg99(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg98_get_wpr_reg9a(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg98_get_wpr_reg9b(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_reg9c                                                  0x18028CA0
#define  LG_M_PLUS_M_plus_reg9c_reg_addr                                         "0xB8028CA0"
#define  LG_M_PLUS_M_plus_reg9c_reg                                              0xB8028CA0
#define  LG_M_PLUS_M_plus_reg9c_inst_addr                                        "0x0028"
#define  set_LG_M_PLUS_M_plus_reg9c_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg9c_reg)=data)
#define  get_LG_M_PLUS_M_plus_reg9c_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_reg9c_reg))
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9c_shift                                  (24)
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9d_shift                                  (16)
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9e_shift                                  (8)
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9f_shift                                  (0)
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9c_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9d_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9e_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9f_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9c(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9d(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9e(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_reg9c_wpr_reg9f(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_reg9c_get_wpr_reg9c(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_reg9c_get_wpr_reg9d(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_reg9c_get_wpr_reg9e(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_reg9c_get_wpr_reg9f(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_rega0                                                  0x18028CA4
#define  LG_M_PLUS_M_plus_rega0_reg_addr                                         "0xB8028CA4"
#define  LG_M_PLUS_M_plus_rega0_reg                                              0xB8028CA4
#define  LG_M_PLUS_M_plus_rega0_inst_addr                                        "0x0029"
#define  set_LG_M_PLUS_M_plus_rega0_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_rega0_reg)=data)
#define  get_LG_M_PLUS_M_plus_rega0_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_rega0_reg))
#define  LG_M_PLUS_M_plus_rega0_wpr_rega0_shift                                  (24)
#define  LG_M_PLUS_M_plus_rega0_wpr_rega1_shift                                  (16)
#define  LG_M_PLUS_M_plus_rega0_wpr_rega2_shift                                  (8)
#define  LG_M_PLUS_M_plus_rega0_wpr_rega3_shift                                  (0)
#define  LG_M_PLUS_M_plus_rega0_wpr_rega0_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_rega0_wpr_rega1_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_rega0_wpr_rega2_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_rega0_wpr_rega3_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_rega0_wpr_rega0(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_rega0_wpr_rega1(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_rega0_wpr_rega2(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_rega0_wpr_rega3(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_rega0_get_wpr_rega0(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_rega0_get_wpr_rega1(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_rega0_get_wpr_rega2(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_rega0_get_wpr_rega3(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_rega4                                                  0x18028CA8
#define  LG_M_PLUS_M_plus_rega4_reg_addr                                         "0xB8028CA8"
#define  LG_M_PLUS_M_plus_rega4_reg                                              0xB8028CA8
#define  LG_M_PLUS_M_plus_rega4_inst_addr                                        "0x002A"
#define  set_LG_M_PLUS_M_plus_rega4_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_rega4_reg)=data)
#define  get_LG_M_PLUS_M_plus_rega4_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_rega4_reg))
#define  LG_M_PLUS_M_plus_rega4_wpr_rega4_shift                                  (24)
#define  LG_M_PLUS_M_plus_rega4_wpr_rega5_shift                                  (16)
#define  LG_M_PLUS_M_plus_rega4_wpr_rega6_shift                                  (8)
#define  LG_M_PLUS_M_plus_rega4_wpr_rega7_shift                                  (0)
#define  LG_M_PLUS_M_plus_rega4_wpr_rega4_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_rega4_wpr_rega5_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_rega4_wpr_rega6_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_rega4_wpr_rega7_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_rega4_wpr_rega4(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_rega4_wpr_rega5(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_rega4_wpr_rega6(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_rega4_wpr_rega7(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_rega4_get_wpr_rega4(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_rega4_get_wpr_rega5(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_rega4_get_wpr_rega6(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_rega4_get_wpr_rega7(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_rega8                                                  0x18028CAC
#define  LG_M_PLUS_M_plus_rega8_reg_addr                                         "0xB8028CAC"
#define  LG_M_PLUS_M_plus_rega8_reg                                              0xB8028CAC
#define  LG_M_PLUS_M_plus_rega8_inst_addr                                        "0x002B"
#define  set_LG_M_PLUS_M_plus_rega8_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_rega8_reg)=data)
#define  get_LG_M_PLUS_M_plus_rega8_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_rega8_reg))
#define  LG_M_PLUS_M_plus_rega8_wpr_rega8_shift                                  (24)
#define  LG_M_PLUS_M_plus_rega8_wpr_rega9_shift                                  (16)
#define  LG_M_PLUS_M_plus_rega8_wpr_regaa_shift                                  (8)
#define  LG_M_PLUS_M_plus_rega8_wpr_regab_shift                                  (0)
#define  LG_M_PLUS_M_plus_rega8_wpr_rega8_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_rega8_wpr_rega9_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_rega8_wpr_regaa_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_rega8_wpr_regab_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_rega8_wpr_rega8(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_rega8_wpr_rega9(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_rega8_wpr_regaa(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_rega8_wpr_regab(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_rega8_get_wpr_rega8(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_rega8_get_wpr_rega9(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_rega8_get_wpr_regaa(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_rega8_get_wpr_regab(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regac                                                  0x18028CB0
#define  LG_M_PLUS_M_plus_regac_reg_addr                                         "0xB8028CB0"
#define  LG_M_PLUS_M_plus_regac_reg                                              0xB8028CB0
#define  LG_M_PLUS_M_plus_regac_inst_addr                                        "0x002C"
#define  set_LG_M_PLUS_M_plus_regac_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regac_reg)=data)
#define  get_LG_M_PLUS_M_plus_regac_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regac_reg))
#define  LG_M_PLUS_M_plus_regac_wpr_regac_shift                                  (24)
#define  LG_M_PLUS_M_plus_regac_wpr_regad_shift                                  (16)
#define  LG_M_PLUS_M_plus_regac_wpr_regae_shift                                  (8)
#define  LG_M_PLUS_M_plus_regac_wpr_regaf_shift                                  (0)
#define  LG_M_PLUS_M_plus_regac_wpr_regac_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regac_wpr_regad_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regac_wpr_regae_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regac_wpr_regaf_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regac_wpr_regac(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regac_wpr_regad(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regac_wpr_regae(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regac_wpr_regaf(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regac_get_wpr_regac(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regac_get_wpr_regad(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regac_get_wpr_regae(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regac_get_wpr_regaf(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regb0                                                  0x18028CB4
#define  LG_M_PLUS_M_plus_regb0_reg_addr                                         "0xB8028CB4"
#define  LG_M_PLUS_M_plus_regb0_reg                                              0xB8028CB4
#define  LG_M_PLUS_M_plus_regb0_inst_addr                                        "0x002D"
#define  set_LG_M_PLUS_M_plus_regb0_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regb0_reg)=data)
#define  get_LG_M_PLUS_M_plus_regb0_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regb0_reg))
#define  LG_M_PLUS_M_plus_regb0_wpr_regb0_shift                                  (24)
#define  LG_M_PLUS_M_plus_regb0_wpr_regb1_shift                                  (16)
#define  LG_M_PLUS_M_plus_regb0_wpr_regb2_shift                                  (8)
#define  LG_M_PLUS_M_plus_regb0_wpr_regb3_shift                                  (0)
#define  LG_M_PLUS_M_plus_regb0_wpr_regb0_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regb0_wpr_regb1_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regb0_wpr_regb2_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regb0_wpr_regb3_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regb0_wpr_regb0(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regb0_wpr_regb1(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regb0_wpr_regb2(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regb0_wpr_regb3(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regb0_get_wpr_regb0(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regb0_get_wpr_regb1(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regb0_get_wpr_regb2(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regb0_get_wpr_regb3(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regb4                                                  0x18028CB8
#define  LG_M_PLUS_M_plus_regb4_reg_addr                                         "0xB8028CB8"
#define  LG_M_PLUS_M_plus_regb4_reg                                              0xB8028CB8
#define  LG_M_PLUS_M_plus_regb4_inst_addr                                        "0x002E"
#define  set_LG_M_PLUS_M_plus_regb4_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regb4_reg)=data)
#define  get_LG_M_PLUS_M_plus_regb4_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regb4_reg))
#define  LG_M_PLUS_M_plus_regb4_wpr_regb4_shift                                  (24)
#define  LG_M_PLUS_M_plus_regb4_wpr_regb5_shift                                  (16)
#define  LG_M_PLUS_M_plus_regb4_wpr_regb6_shift                                  (8)
#define  LG_M_PLUS_M_plus_regb4_wpr_regb7_shift                                  (0)
#define  LG_M_PLUS_M_plus_regb4_wpr_regb4_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regb4_wpr_regb5_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regb4_wpr_regb6_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regb4_wpr_regb7_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regb4_wpr_regb4(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regb4_wpr_regb5(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regb4_wpr_regb6(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regb4_wpr_regb7(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regb4_get_wpr_regb4(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regb4_get_wpr_regb5(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regb4_get_wpr_regb6(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regb4_get_wpr_regb7(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regb8                                                  0x18028CBC
#define  LG_M_PLUS_M_plus_regb8_reg_addr                                         "0xB8028CBC"
#define  LG_M_PLUS_M_plus_regb8_reg                                              0xB8028CBC
#define  LG_M_PLUS_M_plus_regb8_inst_addr                                        "0x002F"
#define  set_LG_M_PLUS_M_plus_regb8_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regb8_reg)=data)
#define  get_LG_M_PLUS_M_plus_regb8_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regb8_reg))
#define  LG_M_PLUS_M_plus_regb8_wpr_regb8_shift                                  (24)
#define  LG_M_PLUS_M_plus_regb8_wpr_regb9_shift                                  (16)
#define  LG_M_PLUS_M_plus_regb8_wpr_regba_shift                                  (8)
#define  LG_M_PLUS_M_plus_regb8_wpr_regbb_shift                                  (0)
#define  LG_M_PLUS_M_plus_regb8_wpr_regb8_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regb8_wpr_regb9_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regb8_wpr_regba_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regb8_wpr_regbb_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regb8_wpr_regb8(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regb8_wpr_regb9(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regb8_wpr_regba(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regb8_wpr_regbb(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regb8_get_wpr_regb8(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regb8_get_wpr_regb9(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regb8_get_wpr_regba(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regb8_get_wpr_regbb(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regbc                                                  0x18028CC0
#define  LG_M_PLUS_M_plus_regbc_reg_addr                                         "0xB8028CC0"
#define  LG_M_PLUS_M_plus_regbc_reg                                              0xB8028CC0
#define  LG_M_PLUS_M_plus_regbc_inst_addr                                        "0x0030"
#define  set_LG_M_PLUS_M_plus_regbc_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regbc_reg)=data)
#define  get_LG_M_PLUS_M_plus_regbc_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regbc_reg))
#define  LG_M_PLUS_M_plus_regbc_wpr_regbc_shift                                  (24)
#define  LG_M_PLUS_M_plus_regbc_wpr_regbd_shift                                  (16)
#define  LG_M_PLUS_M_plus_regbc_wpr_regbe_shift                                  (8)
#define  LG_M_PLUS_M_plus_regbc_wpr_regbf_shift                                  (0)
#define  LG_M_PLUS_M_plus_regbc_wpr_regbc_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regbc_wpr_regbd_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regbc_wpr_regbe_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regbc_wpr_regbf_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regbc_wpr_regbc(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regbc_wpr_regbd(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regbc_wpr_regbe(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regbc_wpr_regbf(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regbc_get_wpr_regbc(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regbc_get_wpr_regbd(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regbc_get_wpr_regbe(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regbc_get_wpr_regbf(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regc0                                                  0x18028CC4
#define  LG_M_PLUS_M_plus_regc0_reg_addr                                         "0xB8028CC4"
#define  LG_M_PLUS_M_plus_regc0_reg                                              0xB8028CC4
#define  LG_M_PLUS_M_plus_regc0_inst_addr                                        "0x0031"
#define  set_LG_M_PLUS_M_plus_regc0_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regc0_reg)=data)
#define  get_LG_M_PLUS_M_plus_regc0_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regc0_reg))
#define  LG_M_PLUS_M_plus_regc0_wpr_regc0_shift                                  (24)
#define  LG_M_PLUS_M_plus_regc0_wpr_regc1_shift                                  (16)
#define  LG_M_PLUS_M_plus_regc0_wpr_regc2_shift                                  (8)
#define  LG_M_PLUS_M_plus_regc0_wpr_regc3_shift                                  (0)
#define  LG_M_PLUS_M_plus_regc0_wpr_regc0_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regc0_wpr_regc1_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regc0_wpr_regc2_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regc0_wpr_regc3_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regc0_wpr_regc0(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regc0_wpr_regc1(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regc0_wpr_regc2(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regc0_wpr_regc3(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regc0_get_wpr_regc0(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regc0_get_wpr_regc1(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regc0_get_wpr_regc2(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regc0_get_wpr_regc3(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regc4                                                  0x18028CC8
#define  LG_M_PLUS_M_plus_regc4_reg_addr                                         "0xB8028CC8"
#define  LG_M_PLUS_M_plus_regc4_reg                                              0xB8028CC8
#define  LG_M_PLUS_M_plus_regc4_inst_addr                                        "0x0032"
#define  set_LG_M_PLUS_M_plus_regc4_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regc4_reg)=data)
#define  get_LG_M_PLUS_M_plus_regc4_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regc4_reg))
#define  LG_M_PLUS_M_plus_regc4_wpr_regc4_shift                                  (24)
#define  LG_M_PLUS_M_plus_regc4_wpr_regc5_shift                                  (16)
#define  LG_M_PLUS_M_plus_regc4_wpr_regc6_shift                                  (8)
#define  LG_M_PLUS_M_plus_regc4_wpr_regc7_shift                                  (0)
#define  LG_M_PLUS_M_plus_regc4_wpr_regc4_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regc4_wpr_regc5_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regc4_wpr_regc6_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regc4_wpr_regc7_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regc4_wpr_regc4(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regc4_wpr_regc5(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regc4_wpr_regc6(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regc4_wpr_regc7(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regc4_get_wpr_regc4(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regc4_get_wpr_regc5(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regc4_get_wpr_regc6(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regc4_get_wpr_regc7(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regc8                                                  0x18028CCC
#define  LG_M_PLUS_M_plus_regc8_reg_addr                                         "0xB8028CCC"
#define  LG_M_PLUS_M_plus_regc8_reg                                              0xB8028CCC
#define  LG_M_PLUS_M_plus_regc8_inst_addr                                        "0x0033"
#define  set_LG_M_PLUS_M_plus_regc8_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regc8_reg)=data)
#define  get_LG_M_PLUS_M_plus_regc8_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regc8_reg))
#define  LG_M_PLUS_M_plus_regc8_wpr_regc8_shift                                  (24)
#define  LG_M_PLUS_M_plus_regc8_wpr_regc9_shift                                  (16)
#define  LG_M_PLUS_M_plus_regc8_wpr_regca_shift                                  (8)
#define  LG_M_PLUS_M_plus_regc8_wpr_regcb_shift                                  (0)
#define  LG_M_PLUS_M_plus_regc8_wpr_regc8_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regc8_wpr_regc9_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regc8_wpr_regca_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regc8_wpr_regcb_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regc8_wpr_regc8(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regc8_wpr_regc9(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regc8_wpr_regca(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regc8_wpr_regcb(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regc8_get_wpr_regc8(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regc8_get_wpr_regc9(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regc8_get_wpr_regca(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regc8_get_wpr_regcb(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regcc                                                  0x18028CD0
#define  LG_M_PLUS_M_plus_regcc_reg_addr                                         "0xB8028CD0"
#define  LG_M_PLUS_M_plus_regcc_reg                                              0xB8028CD0
#define  LG_M_PLUS_M_plus_regcc_inst_addr                                        "0x0034"
#define  set_LG_M_PLUS_M_plus_regcc_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regcc_reg)=data)
#define  get_LG_M_PLUS_M_plus_regcc_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regcc_reg))
#define  LG_M_PLUS_M_plus_regcc_wpr_regcc_shift                                  (24)
#define  LG_M_PLUS_M_plus_regcc_wpr_regcd_shift                                  (16)
#define  LG_M_PLUS_M_plus_regcc_wpr_regce_shift                                  (8)
#define  LG_M_PLUS_M_plus_regcc_wpr_regcf_shift                                  (0)
#define  LG_M_PLUS_M_plus_regcc_wpr_regcc_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regcc_wpr_regcd_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regcc_wpr_regce_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regcc_wpr_regcf_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regcc_wpr_regcc(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regcc_wpr_regcd(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regcc_wpr_regce(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regcc_wpr_regcf(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regcc_get_wpr_regcc(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regcc_get_wpr_regcd(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regcc_get_wpr_regce(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regcc_get_wpr_regcf(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regd0                                                  0x18028CD4
#define  LG_M_PLUS_M_plus_regd0_reg_addr                                         "0xB8028CD4"
#define  LG_M_PLUS_M_plus_regd0_reg                                              0xB8028CD4
#define  LG_M_PLUS_M_plus_regd0_inst_addr                                        "0x0035"
#define  set_LG_M_PLUS_M_plus_regd0_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regd0_reg)=data)
#define  get_LG_M_PLUS_M_plus_regd0_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regd0_reg))
#define  LG_M_PLUS_M_plus_regd0_wpr_regd0_shift                                  (24)
#define  LG_M_PLUS_M_plus_regd0_wpr_regd1_shift                                  (16)
#define  LG_M_PLUS_M_plus_regd0_wpr_regd2_shift                                  (8)
#define  LG_M_PLUS_M_plus_regd0_wpr_regd3_shift                                  (0)
#define  LG_M_PLUS_M_plus_regd0_wpr_regd0_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regd0_wpr_regd1_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regd0_wpr_regd2_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regd0_wpr_regd3_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regd0_wpr_regd0(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regd0_wpr_regd1(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regd0_wpr_regd2(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regd0_wpr_regd3(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regd0_get_wpr_regd0(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regd0_get_wpr_regd1(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regd0_get_wpr_regd2(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regd0_get_wpr_regd3(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regd4                                                  0x18028CD8
#define  LG_M_PLUS_M_plus_regd4_reg_addr                                         "0xB8028CD8"
#define  LG_M_PLUS_M_plus_regd4_reg                                              0xB8028CD8
#define  LG_M_PLUS_M_plus_regd4_inst_addr                                        "0x0036"
#define  set_LG_M_PLUS_M_plus_regd4_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regd4_reg)=data)
#define  get_LG_M_PLUS_M_plus_regd4_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regd4_reg))
#define  LG_M_PLUS_M_plus_regd4_wpr_regd4_shift                                  (24)
#define  LG_M_PLUS_M_plus_regd4_wpr_regd5_shift                                  (16)
#define  LG_M_PLUS_M_plus_regd4_wpr_regd6_shift                                  (8)
#define  LG_M_PLUS_M_plus_regd4_wpr_regd7_shift                                  (0)
#define  LG_M_PLUS_M_plus_regd4_wpr_regd4_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regd4_wpr_regd5_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regd4_wpr_regd6_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regd4_wpr_regd7_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regd4_wpr_regd4(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regd4_wpr_regd5(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regd4_wpr_regd6(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regd4_wpr_regd7(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regd4_get_wpr_regd4(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regd4_get_wpr_regd5(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regd4_get_wpr_regd6(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regd4_get_wpr_regd7(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regd8                                                  0x18028CDC
#define  LG_M_PLUS_M_plus_regd8_reg_addr                                         "0xB8028CDC"
#define  LG_M_PLUS_M_plus_regd8_reg                                              0xB8028CDC
#define  LG_M_PLUS_M_plus_regd8_inst_addr                                        "0x0037"
#define  set_LG_M_PLUS_M_plus_regd8_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regd8_reg)=data)
#define  get_LG_M_PLUS_M_plus_regd8_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regd8_reg))
#define  LG_M_PLUS_M_plus_regd8_wpr_regd8_shift                                  (24)
#define  LG_M_PLUS_M_plus_regd8_wpr_regd9_shift                                  (16)
#define  LG_M_PLUS_M_plus_regd8_wpr_regda_shift                                  (8)
#define  LG_M_PLUS_M_plus_regd8_wpr_regdb_shift                                  (0)
#define  LG_M_PLUS_M_plus_regd8_wpr_regd8_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regd8_wpr_regd9_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regd8_wpr_regda_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regd8_wpr_regdb_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regd8_wpr_regd8(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regd8_wpr_regd9(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regd8_wpr_regda(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regd8_wpr_regdb(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regd8_get_wpr_regd8(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regd8_get_wpr_regd9(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regd8_get_wpr_regda(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regd8_get_wpr_regdb(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_regdc                                                  0x18028CE0
#define  LG_M_PLUS_M_plus_regdc_reg_addr                                         "0xB8028CE0"
#define  LG_M_PLUS_M_plus_regdc_reg                                              0xB8028CE0
#define  LG_M_PLUS_M_plus_regdc_inst_addr                                        "0x0038"
#define  set_LG_M_PLUS_M_plus_regdc_reg(data)                                    (*((volatile unsigned int*)LG_M_PLUS_M_plus_regdc_reg)=data)
#define  get_LG_M_PLUS_M_plus_regdc_reg                                          (*((volatile unsigned int*)LG_M_PLUS_M_plus_regdc_reg))
#define  LG_M_PLUS_M_plus_regdc_wpr_regdc_shift                                  (24)
#define  LG_M_PLUS_M_plus_regdc_wpr_regdd_shift                                  (16)
#define  LG_M_PLUS_M_plus_regdc_wpr_regde_shift                                  (8)
#define  LG_M_PLUS_M_plus_regdc_wpr_regdf_shift                                  (0)
#define  LG_M_PLUS_M_plus_regdc_wpr_regdc_mask                                   (0xFF000000)
#define  LG_M_PLUS_M_plus_regdc_wpr_regdd_mask                                   (0x00FF0000)
#define  LG_M_PLUS_M_plus_regdc_wpr_regde_mask                                   (0x0000FF00)
#define  LG_M_PLUS_M_plus_regdc_wpr_regdf_mask                                   (0x000000FF)
#define  LG_M_PLUS_M_plus_regdc_wpr_regdc(data)                                  (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_regdc_wpr_regdd(data)                                  (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_regdc_wpr_regde(data)                                  (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_regdc_wpr_regdf(data)                                  (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_regdc_get_wpr_regdc(data)                              ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_regdc_get_wpr_regdd(data)                              ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_regdc_get_wpr_regde(data)                              ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_regdc_get_wpr_regdf(data)                              (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_rege0                                              0x18028CE4
#define  LG_M_PLUS_M_plus_wpr_rege0_reg_addr                                     "0xB8028CE4"
#define  LG_M_PLUS_M_plus_wpr_rege0_reg                                          0xB8028CE4
#define  LG_M_PLUS_M_plus_wpr_rege0_inst_addr                                    "0x0039"
#define  set_LG_M_PLUS_M_plus_wpr_rege0_reg(data)                                (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_rege0_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_rege0_reg                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_rege0_reg))
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege0_shift                              (24)
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege1_shift                              (16)
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege2_shift                              (8)
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege3_shift                              (0)
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege0_mask                               (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege1_mask                               (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege2_mask                               (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege3_mask                               (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege0(data)                              (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege1(data)                              (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege2(data)                              (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_rege0_wpr_rege3(data)                              (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_rege0_get_wpr_rege0(data)                          ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_rege0_get_wpr_rege1(data)                          ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_rege0_get_wpr_rege2(data)                          ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_rege0_get_wpr_rege3(data)                          (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_rege4                                              0x18028CE8
#define  LG_M_PLUS_M_plus_wpr_rege4_reg_addr                                     "0xB8028CE8"
#define  LG_M_PLUS_M_plus_wpr_rege4_reg                                          0xB8028CE8
#define  LG_M_PLUS_M_plus_wpr_rege4_inst_addr                                    "0x003A"
#define  set_LG_M_PLUS_M_plus_wpr_rege4_reg(data)                                (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_rege4_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_rege4_reg                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_rege4_reg))
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege4_shift                              (24)
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege5_shift                              (16)
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege6_shift                              (8)
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege7_shift                              (0)
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege4_mask                               (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege5_mask                               (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege6_mask                               (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege7_mask                               (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege4(data)                              (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege5(data)                              (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege6(data)                              (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_rege4_wpr_rege7(data)                              (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_rege4_get_wpr_rege4(data)                          ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_rege4_get_wpr_rege5(data)                          ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_rege4_get_wpr_rege6(data)                          ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_rege4_get_wpr_rege7(data)                          (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_rege8                                              0x18028CEC
#define  LG_M_PLUS_M_plus_wpr_rege8_reg_addr                                     "0xB8028CEC"
#define  LG_M_PLUS_M_plus_wpr_rege8_reg                                          0xB8028CEC
#define  LG_M_PLUS_M_plus_wpr_rege8_inst_addr                                    "0x003B"
#define  set_LG_M_PLUS_M_plus_wpr_rege8_reg(data)                                (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_rege8_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_rege8_reg                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_rege8_reg))
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_rege8_shift                              (24)
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_rege9_shift                              (16)
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_regea_shift                              (8)
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_regeb_shift                              (0)
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_rege8_mask                               (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_rege9_mask                               (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_regea_mask                               (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_regeb_mask                               (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_rege8(data)                              (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_rege9(data)                              (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_regea(data)                              (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_rege8_wpr_regeb(data)                              (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_rege8_get_wpr_rege8(data)                          ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_rege8_get_wpr_rege9(data)                          ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_rege8_get_wpr_regea(data)                          ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_rege8_get_wpr_regeb(data)                          (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_regec                                              0x18028CF0
#define  LG_M_PLUS_M_plus_wpr_regec_reg_addr                                     "0xB8028CF0"
#define  LG_M_PLUS_M_plus_wpr_regec_reg                                          0xB8028CF0
#define  LG_M_PLUS_M_plus_wpr_regec_inst_addr                                    "0x003C"
#define  set_LG_M_PLUS_M_plus_wpr_regec_reg(data)                                (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regec_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_regec_reg                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regec_reg))
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_regec_shift                              (24)
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_reged_shift                              (16)
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_regee_shift                              (8)
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_regef_shift                              (0)
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_regec_mask                               (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_reged_mask                               (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_regee_mask                               (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_regef_mask                               (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_regec(data)                              (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_reged(data)                              (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_regee(data)                              (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_regec_wpr_regef(data)                              (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_regec_get_wpr_regec(data)                          ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_regec_get_wpr_reged(data)                          ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_regec_get_wpr_regee(data)                          ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_regec_get_wpr_regef(data)                          (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_dimming_duty_ctrl                                      0x18028CF4
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_reg_addr                             "0xB8028CF4"
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_reg                                  0xB8028CF4
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_inst_addr                            "0x003D"
#define  set_LG_M_PLUS_M_plus_dimming_duty_ctrl_reg(data)                        (*((volatile unsigned int*)LG_M_PLUS_M_plus_dimming_duty_ctrl_reg)=data)
#define  get_LG_M_PLUS_M_plus_dimming_duty_ctrl_reg                              (*((volatile unsigned int*)LG_M_PLUS_M_plus_dimming_duty_ctrl_reg))
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_force_en_shift          (31)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_force_value_shift       (16)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_gain_shift              (8)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_shift_shift             (0)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_force_en_mask           (0x80000000)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_force_value_mask        (0x1FFF0000)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_gain_mask               (0x00003F00)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_shift_mask              (0x000000FF)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_force_en(data)          (0x80000000&((data)<<31))
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_force_value(data)       (0x1FFF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_gain(data)              (0x00003F00&((data)<<8))
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_dimming_duty_shift(data)             (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_get_dimming_duty_force_en(data)      ((0x80000000&(data))>>31)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_get_dimming_duty_force_value(data)   ((0x1FFF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_get_dimming_duty_gain(data)          ((0x00003F00&(data))>>8)
#define  LG_M_PLUS_M_plus_dimming_duty_ctrl_get_dimming_duty_shift(data)         (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_dimming_duty_read                                      0x18028CF8
#define  LG_M_PLUS_M_plus_dimming_duty_read_reg_addr                             "0xB8028CF8"
#define  LG_M_PLUS_M_plus_dimming_duty_read_reg                                  0xB8028CF8
#define  LG_M_PLUS_M_plus_dimming_duty_read_inst_addr                            "0x003E"
#define  set_LG_M_PLUS_M_plus_dimming_duty_read_reg(data)                        (*((volatile unsigned int*)LG_M_PLUS_M_plus_dimming_duty_read_reg)=data)
#define  get_LG_M_PLUS_M_plus_dimming_duty_read_reg                              (*((volatile unsigned int*)LG_M_PLUS_M_plus_dimming_duty_read_reg))
#define  LG_M_PLUS_M_plus_dimming_duty_read_irq_en_shift                         (31)
#define  LG_M_PLUS_M_plus_dimming_duty_read_dimming_duty_update_shift            (30)
#define  LG_M_PLUS_M_plus_dimming_duty_read_frame_cnt_shift                      (16)
#define  LG_M_PLUS_M_plus_dimming_duty_read_dimming_duty_shift                   (0)
#define  LG_M_PLUS_M_plus_dimming_duty_read_irq_en_mask                          (0x80000000)
#define  LG_M_PLUS_M_plus_dimming_duty_read_dimming_duty_update_mask             (0x40000000)
#define  LG_M_PLUS_M_plus_dimming_duty_read_frame_cnt_mask                       (0x00FF0000)
#define  LG_M_PLUS_M_plus_dimming_duty_read_dimming_duty_mask                    (0x00001FFF)
#define  LG_M_PLUS_M_plus_dimming_duty_read_irq_en(data)                         (0x80000000&((data)<<31))
#define  LG_M_PLUS_M_plus_dimming_duty_read_dimming_duty_update(data)            (0x40000000&((data)<<30))
#define  LG_M_PLUS_M_plus_dimming_duty_read_frame_cnt(data)                      (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_dimming_duty_read_dimming_duty(data)                   (0x00001FFF&(data))
#define  LG_M_PLUS_M_plus_dimming_duty_read_get_irq_en(data)                     ((0x80000000&(data))>>31)
#define  LG_M_PLUS_M_plus_dimming_duty_read_get_dimming_duty_update(data)        ((0x40000000&(data))>>30)
#define  LG_M_PLUS_M_plus_dimming_duty_read_get_frame_cnt(data)                  ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_dimming_duty_read_get_dimming_duty(data)               (0x00001FFF&(data))

#define  LG_M_PLUS_M_plus_sram_bist0                                             0x18028D00
#define  LG_M_PLUS_M_plus_sram_bist0_reg_addr                                    "0xB8028D00"
#define  LG_M_PLUS_M_plus_sram_bist0_reg                                         0xB8028D00
#define  LG_M_PLUS_M_plus_sram_bist0_inst_addr                                   "0x003F"
#define  set_LG_M_PLUS_M_plus_sram_bist0_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist0_reg)=data)
#define  get_LG_M_PLUS_M_plus_sram_bist0_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist0_reg))
#define  LG_M_PLUS_M_plus_sram_bist0_ls_shift                                    (31)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_6_shift                                 (30)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_5_shift                                 (29)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_4_shift                                 (28)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_3_shift                                 (27)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_2_shift                                 (26)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_1_shift                                 (25)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_0_shift                                 (24)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_7_shift                                 (23)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_6_shift                       (22)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_5_shift                       (21)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_4_shift                       (20)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_3_shift                       (19)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_2_shift                       (18)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_1_shift                       (17)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_0_shift                       (16)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_7_shift                       (15)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_6_shift                           (14)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_5_shift                           (13)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_4_shift                           (12)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_3_shift                           (11)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_2_shift                           (10)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_1_shift                           (9)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_0_shift                           (8)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_7_shift                           (7)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_6_shift                             (6)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_5_shift                             (5)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_4_shift                             (4)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_3_shift                             (3)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_2_shift                             (2)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_1_shift                             (1)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_0_shift                             (0)
#define  LG_M_PLUS_M_plus_sram_bist0_ls_mask                                     (0x80000000)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_6_mask                                  (0x40000000)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_5_mask                                  (0x20000000)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_4_mask                                  (0x10000000)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_3_mask                                  (0x08000000)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_2_mask                                  (0x04000000)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_1_mask                                  (0x02000000)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_0_mask                                  (0x01000000)
#define  LG_M_PLUS_M_plus_sram_bist0_rme_7_mask                                  (0x00800000)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_6_mask                        (0x00400000)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_5_mask                        (0x00200000)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_4_mask                        (0x00100000)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_3_mask                        (0x00080000)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_2_mask                        (0x00040000)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_1_mask                        (0x00020000)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_0_mask                        (0x00010000)
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_7_mask                        (0x00008000)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_6_mask                            (0x00004000)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_5_mask                            (0x00002000)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_4_mask                            (0x00001000)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_3_mask                            (0x00000800)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_2_mask                            (0x00000400)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_1_mask                            (0x00000200)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_0_mask                            (0x00000100)
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_7_mask                            (0x00000080)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_6_mask                              (0x00000040)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_5_mask                              (0x00000020)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_4_mask                              (0x00000010)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_3_mask                              (0x00000008)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_2_mask                              (0x00000004)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_1_mask                              (0x00000002)
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_0_mask                              (0x00000001)
#define  LG_M_PLUS_M_plus_sram_bist0_ls(data)                                    (0x80000000&((data)<<31))
#define  LG_M_PLUS_M_plus_sram_bist0_rme_6(data)                                 (0x40000000&((data)<<30))
#define  LG_M_PLUS_M_plus_sram_bist0_rme_5(data)                                 (0x20000000&((data)<<29))
#define  LG_M_PLUS_M_plus_sram_bist0_rme_4(data)                                 (0x10000000&((data)<<28))
#define  LG_M_PLUS_M_plus_sram_bist0_rme_3(data)                                 (0x08000000&((data)<<27))
#define  LG_M_PLUS_M_plus_sram_bist0_rme_2(data)                                 (0x04000000&((data)<<26))
#define  LG_M_PLUS_M_plus_sram_bist0_rme_1(data)                                 (0x02000000&((data)<<25))
#define  LG_M_PLUS_M_plus_sram_bist0_rme_0(data)                                 (0x01000000&((data)<<24))
#define  LG_M_PLUS_M_plus_sram_bist0_rme_7(data)                                 (0x00800000&((data)<<23))
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_6(data)                       (0x00400000&((data)<<22))
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_5(data)                       (0x00200000&((data)<<21))
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_4(data)                       (0x00100000&((data)<<20))
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_3(data)                       (0x00080000&((data)<<19))
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_2(data)                       (0x00040000&((data)<<18))
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_1(data)                       (0x00020000&((data)<<17))
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_0(data)                       (0x00010000&((data)<<16))
#define  LG_M_PLUS_M_plus_sram_bist0_drf_bist_fail_7(data)                       (0x00008000&((data)<<15))
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_6(data)                           (0x00004000&((data)<<14))
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_5(data)                           (0x00002000&((data)<<13))
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_4(data)                           (0x00001000&((data)<<12))
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_3(data)                           (0x00000800&((data)<<11))
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_2(data)                           (0x00000400&((data)<<10))
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_1(data)                           (0x00000200&((data)<<9))
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_0(data)                           (0x00000100&((data)<<8))
#define  LG_M_PLUS_M_plus_sram_bist0_bist_fail_7(data)                           (0x00000080&((data)<<7))
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_6(data)                             (0x00000040&((data)<<6))
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_5(data)                             (0x00000020&((data)<<5))
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_4(data)                             (0x00000010&((data)<<4))
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_3(data)                             (0x00000008&((data)<<3))
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_2(data)                             (0x00000004&((data)<<2))
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_1(data)                             (0x00000002&((data)<<1))
#define  LG_M_PLUS_M_plus_sram_bist0_testrwm_0(data)                             (0x00000001&(data))
#define  LG_M_PLUS_M_plus_sram_bist0_get_ls(data)                                ((0x80000000&(data))>>31)
#define  LG_M_PLUS_M_plus_sram_bist0_get_rme_6(data)                             ((0x40000000&(data))>>30)
#define  LG_M_PLUS_M_plus_sram_bist0_get_rme_5(data)                             ((0x20000000&(data))>>29)
#define  LG_M_PLUS_M_plus_sram_bist0_get_rme_4(data)                             ((0x10000000&(data))>>28)
#define  LG_M_PLUS_M_plus_sram_bist0_get_rme_3(data)                             ((0x08000000&(data))>>27)
#define  LG_M_PLUS_M_plus_sram_bist0_get_rme_2(data)                             ((0x04000000&(data))>>26)
#define  LG_M_PLUS_M_plus_sram_bist0_get_rme_1(data)                             ((0x02000000&(data))>>25)
#define  LG_M_PLUS_M_plus_sram_bist0_get_rme_0(data)                             ((0x01000000&(data))>>24)
#define  LG_M_PLUS_M_plus_sram_bist0_get_rme_7(data)                             ((0x00800000&(data))>>23)
#define  LG_M_PLUS_M_plus_sram_bist0_get_drf_bist_fail_6(data)                   ((0x00400000&(data))>>22)
#define  LG_M_PLUS_M_plus_sram_bist0_get_drf_bist_fail_5(data)                   ((0x00200000&(data))>>21)
#define  LG_M_PLUS_M_plus_sram_bist0_get_drf_bist_fail_4(data)                   ((0x00100000&(data))>>20)
#define  LG_M_PLUS_M_plus_sram_bist0_get_drf_bist_fail_3(data)                   ((0x00080000&(data))>>19)
#define  LG_M_PLUS_M_plus_sram_bist0_get_drf_bist_fail_2(data)                   ((0x00040000&(data))>>18)
#define  LG_M_PLUS_M_plus_sram_bist0_get_drf_bist_fail_1(data)                   ((0x00020000&(data))>>17)
#define  LG_M_PLUS_M_plus_sram_bist0_get_drf_bist_fail_0(data)                   ((0x00010000&(data))>>16)
#define  LG_M_PLUS_M_plus_sram_bist0_get_drf_bist_fail_7(data)                   ((0x00008000&(data))>>15)
#define  LG_M_PLUS_M_plus_sram_bist0_get_bist_fail_6(data)                       ((0x00004000&(data))>>14)
#define  LG_M_PLUS_M_plus_sram_bist0_get_bist_fail_5(data)                       ((0x00002000&(data))>>13)
#define  LG_M_PLUS_M_plus_sram_bist0_get_bist_fail_4(data)                       ((0x00001000&(data))>>12)
#define  LG_M_PLUS_M_plus_sram_bist0_get_bist_fail_3(data)                       ((0x00000800&(data))>>11)
#define  LG_M_PLUS_M_plus_sram_bist0_get_bist_fail_2(data)                       ((0x00000400&(data))>>10)
#define  LG_M_PLUS_M_plus_sram_bist0_get_bist_fail_1(data)                       ((0x00000200&(data))>>9)
#define  LG_M_PLUS_M_plus_sram_bist0_get_bist_fail_0(data)                       ((0x00000100&(data))>>8)
#define  LG_M_PLUS_M_plus_sram_bist0_get_bist_fail_7(data)                       ((0x00000080&(data))>>7)
#define  LG_M_PLUS_M_plus_sram_bist0_get_testrwm_6(data)                         ((0x00000040&(data))>>6)
#define  LG_M_PLUS_M_plus_sram_bist0_get_testrwm_5(data)                         ((0x00000020&(data))>>5)
#define  LG_M_PLUS_M_plus_sram_bist0_get_testrwm_4(data)                         ((0x00000010&(data))>>4)
#define  LG_M_PLUS_M_plus_sram_bist0_get_testrwm_3(data)                         ((0x00000008&(data))>>3)
#define  LG_M_PLUS_M_plus_sram_bist0_get_testrwm_2(data)                         ((0x00000004&(data))>>2)
#define  LG_M_PLUS_M_plus_sram_bist0_get_testrwm_1(data)                         ((0x00000002&(data))>>1)
#define  LG_M_PLUS_M_plus_sram_bist0_get_testrwm_0(data)                         (0x00000001&(data))

#define  LG_M_PLUS_M_plus_sram_bist1                                             0x18028D04
#define  LG_M_PLUS_M_plus_sram_bist1_reg_addr                                    "0xB8028D04"
#define  LG_M_PLUS_M_plus_sram_bist1_reg                                         0xB8028D04
#define  LG_M_PLUS_M_plus_sram_bist1_inst_addr                                   "0x0040"
#define  set_LG_M_PLUS_M_plus_sram_bist1_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist1_reg)=data)
#define  get_LG_M_PLUS_M_plus_sram_bist1_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist1_reg))
#define  LG_M_PLUS_M_plus_sram_bist1_rm_7_shift                                  (28)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_6_shift                                  (24)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_5_shift                                  (20)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_4_shift                                  (16)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_3_shift                                  (12)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_2_shift                                  (8)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_1_shift                                  (4)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_0_shift                                  (0)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_7_mask                                   (0xF0000000)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_6_mask                                   (0x0F000000)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_5_mask                                   (0x00F00000)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_4_mask                                   (0x000F0000)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_3_mask                                   (0x0000F000)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_2_mask                                   (0x00000F00)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_1_mask                                   (0x000000F0)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_0_mask                                   (0x0000000F)
#define  LG_M_PLUS_M_plus_sram_bist1_rm_7(data)                                  (0xF0000000&((data)<<28))
#define  LG_M_PLUS_M_plus_sram_bist1_rm_6(data)                                  (0x0F000000&((data)<<24))
#define  LG_M_PLUS_M_plus_sram_bist1_rm_5(data)                                  (0x00F00000&((data)<<20))
#define  LG_M_PLUS_M_plus_sram_bist1_rm_4(data)                                  (0x000F0000&((data)<<16))
#define  LG_M_PLUS_M_plus_sram_bist1_rm_3(data)                                  (0x0000F000&((data)<<12))
#define  LG_M_PLUS_M_plus_sram_bist1_rm_2(data)                                  (0x00000F00&((data)<<8))
#define  LG_M_PLUS_M_plus_sram_bist1_rm_1(data)                                  (0x000000F0&((data)<<4))
#define  LG_M_PLUS_M_plus_sram_bist1_rm_0(data)                                  (0x0000000F&(data))
#define  LG_M_PLUS_M_plus_sram_bist1_get_rm_7(data)                              ((0xF0000000&(data))>>28)
#define  LG_M_PLUS_M_plus_sram_bist1_get_rm_6(data)                              ((0x0F000000&(data))>>24)
#define  LG_M_PLUS_M_plus_sram_bist1_get_rm_5(data)                              ((0x00F00000&(data))>>20)
#define  LG_M_PLUS_M_plus_sram_bist1_get_rm_4(data)                              ((0x000F0000&(data))>>16)
#define  LG_M_PLUS_M_plus_sram_bist1_get_rm_3(data)                              ((0x0000F000&(data))>>12)
#define  LG_M_PLUS_M_plus_sram_bist1_get_rm_2(data)                              ((0x00000F00&(data))>>8)
#define  LG_M_PLUS_M_plus_sram_bist1_get_rm_1(data)                              ((0x000000F0&(data))>>4)
#define  LG_M_PLUS_M_plus_sram_bist1_get_rm_0(data)                              (0x0000000F&(data))

#define  LG_M_PLUS_M_plus_rom_bist                                               0x18028D08
#define  LG_M_PLUS_M_plus_rom_bist_reg_addr                                      "0xB8028D08"
#define  LG_M_PLUS_M_plus_rom_bist_reg                                           0xB8028D08
#define  LG_M_PLUS_M_plus_rom_bist_inst_addr                                     "0x0041"
#define  set_LG_M_PLUS_M_plus_rom_bist_reg(data)                                 (*((volatile unsigned int*)LG_M_PLUS_M_plus_rom_bist_reg)=data)
#define  get_LG_M_PLUS_M_plus_rom_bist_reg                                       (*((volatile unsigned int*)LG_M_PLUS_M_plus_rom_bist_reg))
#define  LG_M_PLUS_M_plus_rom_bist_rme_r2_shift                                  (30)
#define  LG_M_PLUS_M_plus_rom_bist_rme_g2_shift                                  (29)
#define  LG_M_PLUS_M_plus_rom_bist_rme_b2_shift                                  (28)
#define  LG_M_PLUS_M_plus_rom_bist_rme_r1_shift                                  (27)
#define  LG_M_PLUS_M_plus_rom_bist_rme_g1_shift                                  (26)
#define  LG_M_PLUS_M_plus_rom_bist_rme_b1_shift                                  (25)
#define  LG_M_PLUS_M_plus_rom_bist_rm_r2_shift                                   (20)
#define  LG_M_PLUS_M_plus_rom_bist_rm_g2_shift                                   (16)
#define  LG_M_PLUS_M_plus_rom_bist_rm_b2_shift                                   (12)
#define  LG_M_PLUS_M_plus_rom_bist_rm_r1_shift                                   (8)
#define  LG_M_PLUS_M_plus_rom_bist_rm_g1_shift                                   (4)
#define  LG_M_PLUS_M_plus_rom_bist_rm_b1_shift                                   (0)
#define  LG_M_PLUS_M_plus_rom_bist_rme_r2_mask                                   (0x40000000)
#define  LG_M_PLUS_M_plus_rom_bist_rme_g2_mask                                   (0x20000000)
#define  LG_M_PLUS_M_plus_rom_bist_rme_b2_mask                                   (0x10000000)
#define  LG_M_PLUS_M_plus_rom_bist_rme_r1_mask                                   (0x08000000)
#define  LG_M_PLUS_M_plus_rom_bist_rme_g1_mask                                   (0x04000000)
#define  LG_M_PLUS_M_plus_rom_bist_rme_b1_mask                                   (0x02000000)
#define  LG_M_PLUS_M_plus_rom_bist_rm_r2_mask                                    (0x00F00000)
#define  LG_M_PLUS_M_plus_rom_bist_rm_g2_mask                                    (0x000F0000)
#define  LG_M_PLUS_M_plus_rom_bist_rm_b2_mask                                    (0x0000F000)
#define  LG_M_PLUS_M_plus_rom_bist_rm_r1_mask                                    (0x00000F00)
#define  LG_M_PLUS_M_plus_rom_bist_rm_g1_mask                                    (0x000000F0)
#define  LG_M_PLUS_M_plus_rom_bist_rm_b1_mask                                    (0x0000000F)
#define  LG_M_PLUS_M_plus_rom_bist_rme_r2(data)                                  (0x40000000&((data)<<30))
#define  LG_M_PLUS_M_plus_rom_bist_rme_g2(data)                                  (0x20000000&((data)<<29))
#define  LG_M_PLUS_M_plus_rom_bist_rme_b2(data)                                  (0x10000000&((data)<<28))
#define  LG_M_PLUS_M_plus_rom_bist_rme_r1(data)                                  (0x08000000&((data)<<27))
#define  LG_M_PLUS_M_plus_rom_bist_rme_g1(data)                                  (0x04000000&((data)<<26))
#define  LG_M_PLUS_M_plus_rom_bist_rme_b1(data)                                  (0x02000000&((data)<<25))
#define  LG_M_PLUS_M_plus_rom_bist_rm_r2(data)                                   (0x00F00000&((data)<<20))
#define  LG_M_PLUS_M_plus_rom_bist_rm_g2(data)                                   (0x000F0000&((data)<<16))
#define  LG_M_PLUS_M_plus_rom_bist_rm_b2(data)                                   (0x0000F000&((data)<<12))
#define  LG_M_PLUS_M_plus_rom_bist_rm_r1(data)                                   (0x00000F00&((data)<<8))
#define  LG_M_PLUS_M_plus_rom_bist_rm_g1(data)                                   (0x000000F0&((data)<<4))
#define  LG_M_PLUS_M_plus_rom_bist_rm_b1(data)                                   (0x0000000F&(data))
#define  LG_M_PLUS_M_plus_rom_bist_get_rme_r2(data)                              ((0x40000000&(data))>>30)
#define  LG_M_PLUS_M_plus_rom_bist_get_rme_g2(data)                              ((0x20000000&(data))>>29)
#define  LG_M_PLUS_M_plus_rom_bist_get_rme_b2(data)                              ((0x10000000&(data))>>28)
#define  LG_M_PLUS_M_plus_rom_bist_get_rme_r1(data)                              ((0x08000000&(data))>>27)
#define  LG_M_PLUS_M_plus_rom_bist_get_rme_g1(data)                              ((0x04000000&(data))>>26)
#define  LG_M_PLUS_M_plus_rom_bist_get_rme_b1(data)                              ((0x02000000&(data))>>25)
#define  LG_M_PLUS_M_plus_rom_bist_get_rm_r2(data)                               ((0x00F00000&(data))>>20)
#define  LG_M_PLUS_M_plus_rom_bist_get_rm_g2(data)                               ((0x000F0000&(data))>>16)
#define  LG_M_PLUS_M_plus_rom_bist_get_rm_b2(data)                               ((0x0000F000&(data))>>12)
#define  LG_M_PLUS_M_plus_rom_bist_get_rm_r1(data)                               ((0x00000F00&(data))>>8)
#define  LG_M_PLUS_M_plus_rom_bist_get_rm_g1(data)                               ((0x000000F0&(data))>>4)
#define  LG_M_PLUS_M_plus_rom_bist_get_rm_b1(data)                               (0x0000000F&(data))

#define  LG_M_PLUS_M_plus_sram_bist2                                             0x18028D0C
#define  LG_M_PLUS_M_plus_sram_bist2_reg_addr                                    "0xB8028D0C"
#define  LG_M_PLUS_M_plus_sram_bist2_reg                                         0xB8028D0C
#define  LG_M_PLUS_M_plus_sram_bist2_inst_addr                                   "0x0042"
#define  set_LG_M_PLUS_M_plus_sram_bist2_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist2_reg)=data)
#define  get_LG_M_PLUS_M_plus_sram_bist2_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist2_reg))
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_7_shift                             (24)
#define  LG_M_PLUS_M_plus_sram_bist2_rme_2_2_shift                               (23)
#define  LG_M_PLUS_M_plus_sram_bist2_rme_2_1_shift                               (22)
#define  LG_M_PLUS_M_plus_sram_bist2_rme_2_0_shift                               (21)
#define  LG_M_PLUS_M_plus_sram_bist2_drf_bist_fail_2_2_shift                     (20)
#define  LG_M_PLUS_M_plus_sram_bist2_drf_bist_fail_2_1_shift                     (19)
#define  LG_M_PLUS_M_plus_sram_bist2_drf_bist_fail_2_0_shift                     (18)
#define  LG_M_PLUS_M_plus_sram_bist2_bist_fail_2_2_shift                         (17)
#define  LG_M_PLUS_M_plus_sram_bist2_bist_fail_2_1_shift                         (16)
#define  LG_M_PLUS_M_plus_sram_bist2_bist_fail_2_0_shift                         (15)
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_2_2_shift                           (14)
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_2_1_shift                           (13)
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_2_0_shift                           (12)
#define  LG_M_PLUS_M_plus_sram_bist2_rm_2_2_shift                                (8)
#define  LG_M_PLUS_M_plus_sram_bist2_rm_2_1_shift                                (4)
#define  LG_M_PLUS_M_plus_sram_bist2_rm_2_0_shift                                (0)
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_7_mask                              (0x01000000)
#define  LG_M_PLUS_M_plus_sram_bist2_rme_2_2_mask                                (0x00800000)
#define  LG_M_PLUS_M_plus_sram_bist2_rme_2_1_mask                                (0x00400000)
#define  LG_M_PLUS_M_plus_sram_bist2_rme_2_0_mask                                (0x00200000)
#define  LG_M_PLUS_M_plus_sram_bist2_drf_bist_fail_2_2_mask                      (0x00100000)
#define  LG_M_PLUS_M_plus_sram_bist2_drf_bist_fail_2_1_mask                      (0x00080000)
#define  LG_M_PLUS_M_plus_sram_bist2_drf_bist_fail_2_0_mask                      (0x00040000)
#define  LG_M_PLUS_M_plus_sram_bist2_bist_fail_2_2_mask                          (0x00020000)
#define  LG_M_PLUS_M_plus_sram_bist2_bist_fail_2_1_mask                          (0x00010000)
#define  LG_M_PLUS_M_plus_sram_bist2_bist_fail_2_0_mask                          (0x00008000)
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_2_2_mask                            (0x00004000)
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_2_1_mask                            (0x00002000)
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_2_0_mask                            (0x00001000)
#define  LG_M_PLUS_M_plus_sram_bist2_rm_2_2_mask                                 (0x00000F00)
#define  LG_M_PLUS_M_plus_sram_bist2_rm_2_1_mask                                 (0x000000F0)
#define  LG_M_PLUS_M_plus_sram_bist2_rm_2_0_mask                                 (0x0000000F)
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_7(data)                             (0x01000000&((data)<<24))
#define  LG_M_PLUS_M_plus_sram_bist2_rme_2_2(data)                               (0x00800000&((data)<<23))
#define  LG_M_PLUS_M_plus_sram_bist2_rme_2_1(data)                               (0x00400000&((data)<<22))
#define  LG_M_PLUS_M_plus_sram_bist2_rme_2_0(data)                               (0x00200000&((data)<<21))
#define  LG_M_PLUS_M_plus_sram_bist2_drf_bist_fail_2_2(data)                     (0x00100000&((data)<<20))
#define  LG_M_PLUS_M_plus_sram_bist2_drf_bist_fail_2_1(data)                     (0x00080000&((data)<<19))
#define  LG_M_PLUS_M_plus_sram_bist2_drf_bist_fail_2_0(data)                     (0x00040000&((data)<<18))
#define  LG_M_PLUS_M_plus_sram_bist2_bist_fail_2_2(data)                         (0x00020000&((data)<<17))
#define  LG_M_PLUS_M_plus_sram_bist2_bist_fail_2_1(data)                         (0x00010000&((data)<<16))
#define  LG_M_PLUS_M_plus_sram_bist2_bist_fail_2_0(data)                         (0x00008000&((data)<<15))
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_2_2(data)                           (0x00004000&((data)<<14))
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_2_1(data)                           (0x00002000&((data)<<13))
#define  LG_M_PLUS_M_plus_sram_bist2_testrwm_2_0(data)                           (0x00001000&((data)<<12))
#define  LG_M_PLUS_M_plus_sram_bist2_rm_2_2(data)                                (0x00000F00&((data)<<8))
#define  LG_M_PLUS_M_plus_sram_bist2_rm_2_1(data)                                (0x000000F0&((data)<<4))
#define  LG_M_PLUS_M_plus_sram_bist2_rm_2_0(data)                                (0x0000000F&(data))
#define  LG_M_PLUS_M_plus_sram_bist2_get_testrwm_7(data)                         ((0x01000000&(data))>>24)
#define  LG_M_PLUS_M_plus_sram_bist2_get_rme_2_2(data)                           ((0x00800000&(data))>>23)
#define  LG_M_PLUS_M_plus_sram_bist2_get_rme_2_1(data)                           ((0x00400000&(data))>>22)
#define  LG_M_PLUS_M_plus_sram_bist2_get_rme_2_0(data)                           ((0x00200000&(data))>>21)
#define  LG_M_PLUS_M_plus_sram_bist2_get_drf_bist_fail_2_2(data)                 ((0x00100000&(data))>>20)
#define  LG_M_PLUS_M_plus_sram_bist2_get_drf_bist_fail_2_1(data)                 ((0x00080000&(data))>>19)
#define  LG_M_PLUS_M_plus_sram_bist2_get_drf_bist_fail_2_0(data)                 ((0x00040000&(data))>>18)
#define  LG_M_PLUS_M_plus_sram_bist2_get_bist_fail_2_2(data)                     ((0x00020000&(data))>>17)
#define  LG_M_PLUS_M_plus_sram_bist2_get_bist_fail_2_1(data)                     ((0x00010000&(data))>>16)
#define  LG_M_PLUS_M_plus_sram_bist2_get_bist_fail_2_0(data)                     ((0x00008000&(data))>>15)
#define  LG_M_PLUS_M_plus_sram_bist2_get_testrwm_2_2(data)                       ((0x00004000&(data))>>14)
#define  LG_M_PLUS_M_plus_sram_bist2_get_testrwm_2_1(data)                       ((0x00002000&(data))>>13)
#define  LG_M_PLUS_M_plus_sram_bist2_get_testrwm_2_0(data)                       ((0x00001000&(data))>>12)
#define  LG_M_PLUS_M_plus_sram_bist2_get_rm_2_2(data)                            ((0x00000F00&(data))>>8)
#define  LG_M_PLUS_M_plus_sram_bist2_get_rm_2_1(data)                            ((0x000000F0&(data))>>4)
#define  LG_M_PLUS_M_plus_sram_bist2_get_rm_2_0(data)                            (0x0000000F&(data))

#define  LG_M_PLUS_M_plus_sram_bist3                                             0x18028D10
#define  LG_M_PLUS_M_plus_sram_bist3_reg_addr                                    "0xB8028D10"
#define  LG_M_PLUS_M_plus_sram_bist3_reg                                         0xB8028D10
#define  LG_M_PLUS_M_plus_sram_bist3_inst_addr                                   "0x0043"
#define  set_LG_M_PLUS_M_plus_sram_bist3_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist3_reg)=data)
#define  get_LG_M_PLUS_M_plus_sram_bist3_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist3_reg))
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_4_shift                               (14)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_3_shift                               (13)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_2_shift                               (12)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_1_shift                               (11)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_0_shift                               (10)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_4_shift                     (9)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_3_shift                     (8)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_2_shift                     (7)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_1_shift                     (6)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_0_shift                     (5)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_4_shift                         (4)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_3_shift                         (3)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_2_shift                         (2)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_1_shift                         (1)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_0_shift                         (0)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_4_mask                                (0x00004000)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_3_mask                                (0x00002000)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_2_mask                                (0x00001000)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_1_mask                                (0x00000800)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_0_mask                                (0x00000400)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_4_mask                      (0x00000200)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_3_mask                      (0x00000100)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_2_mask                      (0x00000080)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_1_mask                      (0x00000040)
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_0_mask                      (0x00000020)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_4_mask                          (0x00000010)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_3_mask                          (0x00000008)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_2_mask                          (0x00000004)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_1_mask                          (0x00000002)
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_0_mask                          (0x00000001)
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_4(data)                               (0x00004000&((data)<<14))
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_3(data)                               (0x00002000&((data)<<13))
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_2(data)                               (0x00001000&((data)<<12))
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_1(data)                               (0x00000800&((data)<<11))
#define  LG_M_PLUS_M_plus_sram_bist3_rme_3_0(data)                               (0x00000400&((data)<<10))
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_4(data)                     (0x00000200&((data)<<9))
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_3(data)                     (0x00000100&((data)<<8))
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_2(data)                     (0x00000080&((data)<<7))
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_1(data)                     (0x00000040&((data)<<6))
#define  LG_M_PLUS_M_plus_sram_bist3_drf_bist_fail_3_0(data)                     (0x00000020&((data)<<5))
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_4(data)                         (0x00000010&((data)<<4))
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_3(data)                         (0x00000008&((data)<<3))
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_2(data)                         (0x00000004&((data)<<2))
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_1(data)                         (0x00000002&((data)<<1))
#define  LG_M_PLUS_M_plus_sram_bist3_bist_fail_3_0(data)                         (0x00000001&(data))
#define  LG_M_PLUS_M_plus_sram_bist3_get_rme_3_4(data)                           ((0x00004000&(data))>>14)
#define  LG_M_PLUS_M_plus_sram_bist3_get_rme_3_3(data)                           ((0x00002000&(data))>>13)
#define  LG_M_PLUS_M_plus_sram_bist3_get_rme_3_2(data)                           ((0x00001000&(data))>>12)
#define  LG_M_PLUS_M_plus_sram_bist3_get_rme_3_1(data)                           ((0x00000800&(data))>>11)
#define  LG_M_PLUS_M_plus_sram_bist3_get_rme_3_0(data)                           ((0x00000400&(data))>>10)
#define  LG_M_PLUS_M_plus_sram_bist3_get_drf_bist_fail_3_4(data)                 ((0x00000200&(data))>>9)
#define  LG_M_PLUS_M_plus_sram_bist3_get_drf_bist_fail_3_3(data)                 ((0x00000100&(data))>>8)
#define  LG_M_PLUS_M_plus_sram_bist3_get_drf_bist_fail_3_2(data)                 ((0x00000080&(data))>>7)
#define  LG_M_PLUS_M_plus_sram_bist3_get_drf_bist_fail_3_1(data)                 ((0x00000040&(data))>>6)
#define  LG_M_PLUS_M_plus_sram_bist3_get_drf_bist_fail_3_0(data)                 ((0x00000020&(data))>>5)
#define  LG_M_PLUS_M_plus_sram_bist3_get_bist_fail_3_4(data)                     ((0x00000010&(data))>>4)
#define  LG_M_PLUS_M_plus_sram_bist3_get_bist_fail_3_3(data)                     ((0x00000008&(data))>>3)
#define  LG_M_PLUS_M_plus_sram_bist3_get_bist_fail_3_2(data)                     ((0x00000004&(data))>>2)
#define  LG_M_PLUS_M_plus_sram_bist3_get_bist_fail_3_1(data)                     ((0x00000002&(data))>>1)
#define  LG_M_PLUS_M_plus_sram_bist3_get_bist_fail_3_0(data)                     (0x00000001&(data))

#define  LG_M_PLUS_M_plus_sram_bist4                                             0x18028D14
#define  LG_M_PLUS_M_plus_sram_bist4_reg_addr                                    "0xB8028D14"
#define  LG_M_PLUS_M_plus_sram_bist4_reg                                         0xB8028D14
#define  LG_M_PLUS_M_plus_sram_bist4_inst_addr                                   "0x0044"
#define  set_LG_M_PLUS_M_plus_sram_bist4_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist4_reg)=data)
#define  get_LG_M_PLUS_M_plus_sram_bist4_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_sram_bist4_reg))
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_4_shift                                (16)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_3_shift                                (12)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_2_shift                                (8)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_1_shift                                (4)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_0_shift                                (0)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_4_mask                                 (0x000F0000)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_3_mask                                 (0x0000F000)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_2_mask                                 (0x00000F00)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_1_mask                                 (0x000000F0)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_0_mask                                 (0x0000000F)
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_4(data)                                (0x000F0000&((data)<<16))
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_3(data)                                (0x0000F000&((data)<<12))
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_2(data)                                (0x00000F00&((data)<<8))
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_1(data)                                (0x000000F0&((data)<<4))
#define  LG_M_PLUS_M_plus_sram_bist4_rm_3_0(data)                                (0x0000000F&(data))
#define  LG_M_PLUS_M_plus_sram_bist4_get_rm_3_4(data)                            ((0x000F0000&(data))>>16)
#define  LG_M_PLUS_M_plus_sram_bist4_get_rm_3_3(data)                            ((0x0000F000&(data))>>12)
#define  LG_M_PLUS_M_plus_sram_bist4_get_rm_3_2(data)                            ((0x00000F00&(data))>>8)
#define  LG_M_PLUS_M_plus_sram_bist4_get_rm_3_1(data)                            ((0x000000F0&(data))>>4)
#define  LG_M_PLUS_M_plus_sram_bist4_get_rm_3_0(data)                            (0x0000000F&(data))

#define  LG_M_PLUS_M_plus_rom_bist1                                              0x18028D18
#define  LG_M_PLUS_M_plus_rom_bist1_reg_addr                                     "0xB8028D18"
#define  LG_M_PLUS_M_plus_rom_bist1_reg                                          0xB8028D18
#define  LG_M_PLUS_M_plus_rom_bist1_inst_addr                                    "0x0045"
#define  set_LG_M_PLUS_M_plus_rom_bist1_reg(data)                                (*((volatile unsigned int*)LG_M_PLUS_M_plus_rom_bist1_reg)=data)
#define  get_LG_M_PLUS_M_plus_rom_bist1_reg                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_rom_bist1_reg))
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_r2_shift                               (30)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_g2_shift                               (29)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_b2_shift                               (28)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_r1_shift                               (27)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_g1_shift                               (26)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_b1_shift                               (25)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_r2_shift                                (20)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_g2_shift                                (16)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_b2_shift                                (12)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_r1_shift                                (8)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_g1_shift                                (4)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_b1_shift                                (0)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_r2_mask                                (0x40000000)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_g2_mask                                (0x20000000)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_b2_mask                                (0x10000000)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_r1_mask                                (0x08000000)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_g1_mask                                (0x04000000)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_b1_mask                                (0x02000000)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_r2_mask                                 (0x00F00000)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_g2_mask                                 (0x000F0000)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_b2_mask                                 (0x0000F000)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_r1_mask                                 (0x00000F00)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_g1_mask                                 (0x000000F0)
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_b1_mask                                 (0x0000000F)
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_r2(data)                               (0x40000000&((data)<<30))
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_g2(data)                               (0x20000000&((data)<<29))
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_b2(data)                               (0x10000000&((data)<<28))
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_r1(data)                               (0x08000000&((data)<<27))
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_g1(data)                               (0x04000000&((data)<<26))
#define  LG_M_PLUS_M_plus_rom_bist1_rme_2_b1(data)                               (0x02000000&((data)<<25))
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_r2(data)                                (0x00F00000&((data)<<20))
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_g2(data)                                (0x000F0000&((data)<<16))
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_b2(data)                                (0x0000F000&((data)<<12))
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_r1(data)                                (0x00000F00&((data)<<8))
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_g1(data)                                (0x000000F0&((data)<<4))
#define  LG_M_PLUS_M_plus_rom_bist1_rm_2_b1(data)                                (0x0000000F&(data))
#define  LG_M_PLUS_M_plus_rom_bist1_get_rme_2_r2(data)                           ((0x40000000&(data))>>30)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rme_2_g2(data)                           ((0x20000000&(data))>>29)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rme_2_b2(data)                           ((0x10000000&(data))>>28)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rme_2_r1(data)                           ((0x08000000&(data))>>27)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rme_2_g1(data)                           ((0x04000000&(data))>>26)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rme_2_b1(data)                           ((0x02000000&(data))>>25)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rm_2_r2(data)                            ((0x00F00000&(data))>>20)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rm_2_g2(data)                            ((0x000F0000&(data))>>16)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rm_2_b2(data)                            ((0x0000F000&(data))>>12)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rm_2_r1(data)                            ((0x00000F00&(data))>>8)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rm_2_g1(data)                            ((0x000000F0&(data))>>4)
#define  LG_M_PLUS_M_plus_rom_bist1_get_rm_2_b1(data)                            (0x0000000F&(data))

#define  LG_M_PLUS_M_plus_wpr_regf0                                              0x18028D1C
#define  LG_M_PLUS_M_plus_wpr_regf0_reg_addr                                     "0xB8028D1C"
#define  LG_M_PLUS_M_plus_wpr_regf0_reg                                          0xB8028D1C
#define  LG_M_PLUS_M_plus_wpr_regf0_inst_addr                                    "0x0046"
#define  set_LG_M_PLUS_M_plus_wpr_regf0_reg(data)                                (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regf0_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_regf0_reg                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regf0_reg))
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf0_shift                              (24)
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf1_shift                              (16)
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf2_shift                              (8)
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf3_shift                              (0)
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf0_mask                               (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf1_mask                               (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf2_mask                               (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf3_mask                               (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf0(data)                              (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf1(data)                              (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf2(data)                              (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_regf0_wpr_regf3(data)                              (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_regf0_get_wpr_regf0(data)                          ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_regf0_get_wpr_regf1(data)                          ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_regf0_get_wpr_regf2(data)                          ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_regf0_get_wpr_regf3(data)                          (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_regf4                                              0x18028D20
#define  LG_M_PLUS_M_plus_wpr_regf4_reg_addr                                     "0xB8028D20"
#define  LG_M_PLUS_M_plus_wpr_regf4_reg                                          0xB8028D20
#define  LG_M_PLUS_M_plus_wpr_regf4_inst_addr                                    "0x0047"
#define  set_LG_M_PLUS_M_plus_wpr_regf4_reg(data)                                (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regf4_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_regf4_reg                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regf4_reg))
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf4_shift                              (24)
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf5_shift                              (16)
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf6_shift                              (8)
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf7_shift                              (0)
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf4_mask                               (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf5_mask                               (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf6_mask                               (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf7_mask                               (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf4(data)                              (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf5(data)                              (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf6(data)                              (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_regf4_wpr_regf7(data)                              (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_regf4_get_wpr_regf4(data)                          ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_regf4_get_wpr_regf5(data)                          ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_regf4_get_wpr_regf6(data)                          ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_regf4_get_wpr_regf7(data)                          (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_regf8                                              0x18028D24
#define  LG_M_PLUS_M_plus_wpr_regf8_reg_addr                                     "0xB8028D24"
#define  LG_M_PLUS_M_plus_wpr_regf8_reg                                          0xB8028D24
#define  LG_M_PLUS_M_plus_wpr_regf8_inst_addr                                    "0x0048"
#define  set_LG_M_PLUS_M_plus_wpr_regf8_reg(data)                                (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regf8_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_regf8_reg                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regf8_reg))
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regf8_shift                              (24)
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regf9_shift                              (16)
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regfa_shift                              (8)
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regfb_shift                              (0)
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regf8_mask                               (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regf9_mask                               (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regfa_mask                               (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regfb_mask                               (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regf8(data)                              (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regf9(data)                              (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regfa(data)                              (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_regf8_wpr_regfb(data)                              (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_regf8_get_wpr_regf8(data)                          ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_regf8_get_wpr_regf9(data)                          ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_regf8_get_wpr_regfa(data)                          ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_regf8_get_wpr_regfb(data)                          (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_regfc                                              0x18028D28
#define  LG_M_PLUS_M_plus_wpr_regfc_reg_addr                                     "0xB8028D28"
#define  LG_M_PLUS_M_plus_wpr_regfc_reg                                          0xB8028D28
#define  LG_M_PLUS_M_plus_wpr_regfc_inst_addr                                    "0x0049"
#define  set_LG_M_PLUS_M_plus_wpr_regfc_reg(data)                                (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regfc_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_regfc_reg                                      (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_regfc_reg))
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regfc_shift                              (24)
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regfd_shift                              (16)
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regfe_shift                              (8)
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regff_shift                              (0)
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regfc_mask                               (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regfd_mask                               (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regfe_mask                               (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regff_mask                               (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regfc(data)                              (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regfd(data)                              (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regfe(data)                              (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_regfc_wpr_regff(data)                              (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_regfc_get_wpr_regfc(data)                          ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_regfc_get_wpr_regfd(data)                          ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_regfc_get_wpr_regfe(data)                          ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_regfc_get_wpr_regff(data)                          (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg100                                             0x18028D2C
#define  LG_M_PLUS_M_plus_wpr_reg100_reg_addr                                    "0xB8028D2C"
#define  LG_M_PLUS_M_plus_wpr_reg100_reg                                         0xB8028D2C
#define  LG_M_PLUS_M_plus_wpr_reg100_inst_addr                                   "0x004A"
#define  set_LG_M_PLUS_M_plus_wpr_reg100_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg100_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg100_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg100_reg))
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg100_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg101_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg102_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg103_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg100_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg101_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg102_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg103_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg100(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg101(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg102(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg100_wpr_reg103(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg100_get_wpr_reg100(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg100_get_wpr_reg101(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg100_get_wpr_reg102(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg100_get_wpr_reg103(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg104                                             0x18028D30
#define  LG_M_PLUS_M_plus_wpr_reg104_reg_addr                                    "0xB8028D30"
#define  LG_M_PLUS_M_plus_wpr_reg104_reg                                         0xB8028D30
#define  LG_M_PLUS_M_plus_wpr_reg104_inst_addr                                   "0x004B"
#define  set_LG_M_PLUS_M_plus_wpr_reg104_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg104_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg104_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg104_reg))
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg104_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg105_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg106_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg107_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg104_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg105_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg106_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg107_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg104(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg105(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg106(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg104_wpr_reg107(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg104_get_wpr_reg104(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg104_get_wpr_reg105(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg104_get_wpr_reg106(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg104_get_wpr_reg107(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg108                                             0x18028D34
#define  LG_M_PLUS_M_plus_wpr_reg108_reg_addr                                    "0xB8028D34"
#define  LG_M_PLUS_M_plus_wpr_reg108_reg                                         0xB8028D34
#define  LG_M_PLUS_M_plus_wpr_reg108_inst_addr                                   "0x004C"
#define  set_LG_M_PLUS_M_plus_wpr_reg108_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg108_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg108_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg108_reg))
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg108_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg109_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg10a_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg10b_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg108_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg109_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg10a_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg10b_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg108(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg109(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg10a(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg108_wpr_reg10b(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg108_get_wpr_reg108(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg108_get_wpr_reg109(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg108_get_wpr_reg10a(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg108_get_wpr_reg10b(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg10c                                             0x18028D38
#define  LG_M_PLUS_M_plus_wpr_reg10c_reg_addr                                    "0xB8028D38"
#define  LG_M_PLUS_M_plus_wpr_reg10c_reg                                         0xB8028D38
#define  LG_M_PLUS_M_plus_wpr_reg10c_inst_addr                                   "0x004D"
#define  set_LG_M_PLUS_M_plus_wpr_reg10c_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg10c_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg10c_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg10c_reg))
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10c_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10d_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10e_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10f_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10c_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10d_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10e_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10f_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10c(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10d(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10e(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg10c_wpr_reg10f(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg10c_get_wpr_reg10c(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg10c_get_wpr_reg10d(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg10c_get_wpr_reg10e(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg10c_get_wpr_reg10f(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg110                                             0x18028D3C
#define  LG_M_PLUS_M_plus_wpr_reg110_reg_addr                                    "0xB8028D3C"
#define  LG_M_PLUS_M_plus_wpr_reg110_reg                                         0xB8028D3C
#define  LG_M_PLUS_M_plus_wpr_reg110_inst_addr                                   "0x004E"
#define  set_LG_M_PLUS_M_plus_wpr_reg110_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg110_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg110_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg110_reg))
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg110_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg111_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg112_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg113_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg110_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg111_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg112_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg113_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg110(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg111(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg112(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg110_wpr_reg113(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg110_get_wpr_reg110(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg110_get_wpr_reg111(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg110_get_wpr_reg112(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg110_get_wpr_reg113(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg114                                             0x18028D40
#define  LG_M_PLUS_M_plus_wpr_reg114_reg_addr                                    "0xB8028D40"
#define  LG_M_PLUS_M_plus_wpr_reg114_reg                                         0xB8028D40
#define  LG_M_PLUS_M_plus_wpr_reg114_inst_addr                                   "0x004F"
#define  set_LG_M_PLUS_M_plus_wpr_reg114_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg114_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg114_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg114_reg))
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg114_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg115_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg116_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg117_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg114_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg115_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg116_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg117_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg114(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg115(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg116(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg114_wpr_reg117(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg114_get_wpr_reg114(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg114_get_wpr_reg115(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg114_get_wpr_reg116(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg114_get_wpr_reg117(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg118                                             0x18028D44
#define  LG_M_PLUS_M_plus_wpr_reg118_reg_addr                                    "0xB8028D44"
#define  LG_M_PLUS_M_plus_wpr_reg118_reg                                         0xB8028D44
#define  LG_M_PLUS_M_plus_wpr_reg118_inst_addr                                   "0x0050"
#define  set_LG_M_PLUS_M_plus_wpr_reg118_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg118_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg118_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg118_reg))
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg118_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg119_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg11a_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg11b_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg118_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg119_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg11a_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg11b_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg118(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg119(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg11a(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg118_wpr_reg11b(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg118_get_wpr_reg118(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg118_get_wpr_reg119(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg118_get_wpr_reg11a(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg118_get_wpr_reg11b(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg11c                                             0x18028D48
#define  LG_M_PLUS_M_plus_wpr_reg11c_reg_addr                                    "0xB8028D48"
#define  LG_M_PLUS_M_plus_wpr_reg11c_reg                                         0xB8028D48
#define  LG_M_PLUS_M_plus_wpr_reg11c_inst_addr                                   "0x0051"
#define  set_LG_M_PLUS_M_plus_wpr_reg11c_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg11c_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg11c_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg11c_reg))
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11c_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11d_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11e_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11f_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11c_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11d_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11e_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11f_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11c(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11d(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11e(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg11c_wpr_reg11f(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg11c_get_wpr_reg11c(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg11c_get_wpr_reg11d(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg11c_get_wpr_reg11e(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg11c_get_wpr_reg11f(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg120                                             0x18028D4C
#define  LG_M_PLUS_M_plus_wpr_reg120_reg_addr                                    "0xB8028D4C"
#define  LG_M_PLUS_M_plus_wpr_reg120_reg                                         0xB8028D4C
#define  LG_M_PLUS_M_plus_wpr_reg120_inst_addr                                   "0x0052"
#define  set_LG_M_PLUS_M_plus_wpr_reg120_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg120_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg120_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg120_reg))
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg120_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg121_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg122_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg123_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg120_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg121_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg122_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg123_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg120(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg121(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg122(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg120_wpr_reg123(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg120_get_wpr_reg120(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg120_get_wpr_reg121(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg120_get_wpr_reg122(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg120_get_wpr_reg123(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg124                                             0x18028D50
#define  LG_M_PLUS_M_plus_wpr_reg124_reg_addr                                    "0xB8028D50"
#define  LG_M_PLUS_M_plus_wpr_reg124_reg                                         0xB8028D50
#define  LG_M_PLUS_M_plus_wpr_reg124_inst_addr                                   "0x0053"
#define  set_LG_M_PLUS_M_plus_wpr_reg124_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg124_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg124_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg124_reg))
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg124_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg125_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg126_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg127_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg124_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg125_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg126_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg127_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg124(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg125(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg126(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg124_wpr_reg127(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg124_get_wpr_reg124(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg124_get_wpr_reg125(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg124_get_wpr_reg126(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg124_get_wpr_reg127(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg128                                             0x18028D54
#define  LG_M_PLUS_M_plus_wpr_reg128_reg_addr                                    "0xB8028D54"
#define  LG_M_PLUS_M_plus_wpr_reg128_reg                                         0xB8028D54
#define  LG_M_PLUS_M_plus_wpr_reg128_inst_addr                                   "0x0054"
#define  set_LG_M_PLUS_M_plus_wpr_reg128_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg128_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg128_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg128_reg))
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg128_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg129_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg12a_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg12b_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg128_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg129_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg12a_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg12b_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg128(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg129(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg12a(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg128_wpr_reg12b(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg128_get_wpr_reg128(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg128_get_wpr_reg129(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg128_get_wpr_reg12a(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg128_get_wpr_reg12b(data)                        (0x000000FF&(data))

#define  LG_M_PLUS_M_plus_wpr_reg12c                                             0x18028D58
#define  LG_M_PLUS_M_plus_wpr_reg12c_reg_addr                                    "0xB8028D58"
#define  LG_M_PLUS_M_plus_wpr_reg12c_reg                                         0xB8028D58
#define  LG_M_PLUS_M_plus_wpr_reg12c_inst_addr                                   "0x0055"
#define  set_LG_M_PLUS_M_plus_wpr_reg12c_reg(data)                               (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg12c_reg)=data)
#define  get_LG_M_PLUS_M_plus_wpr_reg12c_reg                                     (*((volatile unsigned int*)LG_M_PLUS_M_plus_wpr_reg12c_reg))
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12c_shift                            (24)
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12d_shift                            (16)
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12e_shift                            (8)
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12f_shift                            (0)
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12c_mask                             (0xFF000000)
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12d_mask                             (0x00FF0000)
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12e_mask                             (0x0000FF00)
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12f_mask                             (0x000000FF)
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12c(data)                            (0xFF000000&((data)<<24))
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12d(data)                            (0x00FF0000&((data)<<16))
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12e(data)                            (0x0000FF00&((data)<<8))
#define  LG_M_PLUS_M_plus_wpr_reg12c_wpr_reg12f(data)                            (0x000000FF&(data))
#define  LG_M_PLUS_M_plus_wpr_reg12c_get_wpr_reg12c(data)                        ((0xFF000000&(data))>>24)
#define  LG_M_PLUS_M_plus_wpr_reg12c_get_wpr_reg12d(data)                        ((0x00FF0000&(data))>>16)
#define  LG_M_PLUS_M_plus_wpr_reg12c_get_wpr_reg12e(data)                        ((0x0000FF00&(data))>>8)
#define  LG_M_PLUS_M_plus_wpr_reg12c_get_wpr_reg12f(data)                        (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LG_M_PLUS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_on:1;
        RBus_UInt32  opc_on:1;
        RBus_UInt32  wse_on:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  user_timing_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  auto_detect_result:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  type_sel:1;
        RBus_UInt32  bypass_on:1;
        RBus_UInt32  auto_detect_en:1;
        RBus_UInt32  mode_3d:1;
        RBus_UInt32  test_mode:1;
        RBus_UInt32  mode_sel:2;
    };
}lg_m_plus_m_plus_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg00:8;
        RBus_UInt32  wpr_reg01:8;
        RBus_UInt32  wpr_reg02:8;
        RBus_UInt32  wpr_reg03:8;
    };
}lg_m_plus_m_plus_reg00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg04:8;
        RBus_UInt32  wpr_reg05:8;
        RBus_UInt32  wpr_reg06:8;
        RBus_UInt32  wpr_reg07:8;
    };
}lg_m_plus_m_plus_reg04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg08:8;
        RBus_UInt32  wpr_reg09:8;
        RBus_UInt32  wpr_reg0a:8;
        RBus_UInt32  wpr_reg0b:8;
    };
}lg_m_plus_m_plus_reg08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg0c:8;
        RBus_UInt32  wpr_reg0d:8;
        RBus_UInt32  wpr_reg0e:8;
        RBus_UInt32  wpr_reg0f:8;
    };
}lg_m_plus_m_plus_reg0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg10:8;
        RBus_UInt32  wpr_reg11:8;
        RBus_UInt32  wpr_reg12:8;
        RBus_UInt32  wpr_reg13:8;
    };
}lg_m_plus_m_plus_reg10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg14:8;
        RBus_UInt32  wpr_reg15:8;
        RBus_UInt32  wpr_reg16:8;
        RBus_UInt32  wpr_reg17:8;
    };
}lg_m_plus_m_plus_reg14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg18:8;
        RBus_UInt32  wpr_reg19:8;
        RBus_UInt32  wpr_reg1a:8;
        RBus_UInt32  wpr_reg1b:8;
    };
}lg_m_plus_m_plus_reg18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg1c:8;
        RBus_UInt32  wpr_reg1d:8;
        RBus_UInt32  wpr_reg1e:8;
        RBus_UInt32  wpr_reg1f:8;
    };
}lg_m_plus_m_plus_reg1c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg20:8;
        RBus_UInt32  wpr_reg21:8;
        RBus_UInt32  wpr_reg22:8;
        RBus_UInt32  wpr_reg23:8;
    };
}lg_m_plus_m_plus_reg20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg24:8;
        RBus_UInt32  wpr_reg25:8;
        RBus_UInt32  wpr_reg26:8;
        RBus_UInt32  wpr_reg27:8;
    };
}lg_m_plus_m_plus_reg24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg28:8;
        RBus_UInt32  wpr_reg29:8;
        RBus_UInt32  wpr_reg2a:8;
        RBus_UInt32  wpr_reg2b:8;
    };
}lg_m_plus_m_plus_reg28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg2c:8;
        RBus_UInt32  wpr_reg2d:8;
        RBus_UInt32  wpr_reg2e:8;
        RBus_UInt32  wpr_reg2f:8;
    };
}lg_m_plus_m_plus_reg2c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg30:8;
        RBus_UInt32  wpr_reg31:8;
        RBus_UInt32  wpr_reg32:8;
        RBus_UInt32  wpr_reg33:8;
    };
}lg_m_plus_m_plus_reg30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg34:8;
        RBus_UInt32  wpr_reg35:8;
        RBus_UInt32  wpr_reg36:8;
        RBus_UInt32  wpr_reg37:8;
    };
}lg_m_plus_m_plus_reg34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg38:8;
        RBus_UInt32  wpr_reg39:8;
        RBus_UInt32  wpr_reg3a:8;
        RBus_UInt32  wpr_reg3b:8;
    };
}lg_m_plus_m_plus_reg38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg3c:8;
        RBus_UInt32  wpr_reg3d:8;
        RBus_UInt32  wpr_reg3e:8;
        RBus_UInt32  wpr_reg3f:8;
    };
}lg_m_plus_m_plus_reg3c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg40:8;
        RBus_UInt32  wpr_reg41:8;
        RBus_UInt32  wpr_reg42:8;
        RBus_UInt32  wpr_reg43:8;
    };
}lg_m_plus_m_plus_reg40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg44:8;
        RBus_UInt32  wpr_reg45:8;
        RBus_UInt32  wpr_reg46:8;
        RBus_UInt32  wpr_reg47:8;
    };
}lg_m_plus_m_plus_reg44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg48:8;
        RBus_UInt32  wpr_reg49:8;
        RBus_UInt32  wpr_reg4a:8;
        RBus_UInt32  wpr_reg4b:8;
    };
}lg_m_plus_m_plus_reg48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg4c:8;
        RBus_UInt32  wpr_reg4d:8;
        RBus_UInt32  wpr_reg4e:8;
        RBus_UInt32  wpr_reg4f:8;
    };
}lg_m_plus_m_plus_reg4c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg50:8;
        RBus_UInt32  wpr_reg51:8;
        RBus_UInt32  wpr_reg52:8;
        RBus_UInt32  wpr_reg53:8;
    };
}lg_m_plus_m_plus_reg50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg54:8;
        RBus_UInt32  wpr_reg55:8;
        RBus_UInt32  wpr_reg56:8;
        RBus_UInt32  wpr_reg57:8;
    };
}lg_m_plus_m_plus_reg54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg58:8;
        RBus_UInt32  wpr_reg59:8;
        RBus_UInt32  wpr_reg5a:8;
        RBus_UInt32  wpr_reg5b:8;
    };
}lg_m_plus_m_plus_reg58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg5c:8;
        RBus_UInt32  wpr_reg5d:8;
        RBus_UInt32  wpr_reg5e:8;
        RBus_UInt32  wpr_reg5f:8;
    };
}lg_m_plus_m_plus_reg5c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg60:8;
        RBus_UInt32  wpr_reg61:8;
        RBus_UInt32  wpr_reg62:8;
        RBus_UInt32  wpr_reg63:8;
    };
}lg_m_plus_m_plus_reg60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg64:8;
        RBus_UInt32  wpr_reg65:8;
        RBus_UInt32  wpr_reg66:8;
        RBus_UInt32  wpr_reg67:8;
    };
}lg_m_plus_m_plus_reg64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg68:8;
        RBus_UInt32  wpr_reg69:8;
        RBus_UInt32  wpr_reg6a:8;
        RBus_UInt32  wpr_reg6b:8;
    };
}lg_m_plus_m_plus_reg68_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg6c:8;
        RBus_UInt32  wpr_reg6d:8;
        RBus_UInt32  wpr_reg6e:8;
        RBus_UInt32  wpr_reg6f:8;
    };
}lg_m_plus_m_plus_reg6c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg70:8;
        RBus_UInt32  wpr_reg71:8;
        RBus_UInt32  wpr_reg72:8;
        RBus_UInt32  wpr_reg73:8;
    };
}lg_m_plus_m_plus_reg70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg74:8;
        RBus_UInt32  wpr_reg75:8;
        RBus_UInt32  wpr_reg76:8;
        RBus_UInt32  wpr_reg77:8;
    };
}lg_m_plus_m_plus_reg74_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg78:8;
        RBus_UInt32  wpr_reg79:8;
        RBus_UInt32  wpr_reg7a:8;
        RBus_UInt32  wpr_reg7b:8;
    };
}lg_m_plus_m_plus_reg78_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg7c:8;
        RBus_UInt32  wpr_reg7d:8;
        RBus_UInt32  wpr_reg7e:8;
        RBus_UInt32  wpr_reg7f:8;
    };
}lg_m_plus_m_plus_reg7c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg80:8;
        RBus_UInt32  wpr_reg81:8;
        RBus_UInt32  wpr_reg82:8;
        RBus_UInt32  wpr_reg83:8;
    };
}lg_m_plus_m_plus_reg80_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg84:8;
        RBus_UInt32  wpr_reg85:8;
        RBus_UInt32  wpr_reg86:8;
        RBus_UInt32  wpr_reg87:8;
    };
}lg_m_plus_m_plus_reg84_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg88:8;
        RBus_UInt32  wpr_reg89:8;
        RBus_UInt32  wpr_reg8a:8;
        RBus_UInt32  wpr_reg8b:8;
    };
}lg_m_plus_m_plus_reg88_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg8c:8;
        RBus_UInt32  wpr_reg8d:8;
        RBus_UInt32  wpr_reg8e:8;
        RBus_UInt32  wpr_reg8f:8;
    };
}lg_m_plus_m_plus_reg8c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg90:8;
        RBus_UInt32  wpr_reg91:8;
        RBus_UInt32  wpr_reg92:8;
        RBus_UInt32  wpr_reg93:8;
    };
}lg_m_plus_m_plus_reg90_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg94:8;
        RBus_UInt32  wpr_reg95:8;
        RBus_UInt32  wpr_reg96:8;
        RBus_UInt32  wpr_reg97:8;
    };
}lg_m_plus_m_plus_reg94_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg98:8;
        RBus_UInt32  wpr_reg99:8;
        RBus_UInt32  wpr_reg9a:8;
        RBus_UInt32  wpr_reg9b:8;
    };
}lg_m_plus_m_plus_reg98_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg9c:8;
        RBus_UInt32  wpr_reg9d:8;
        RBus_UInt32  wpr_reg9e:8;
        RBus_UInt32  wpr_reg9f:8;
    };
}lg_m_plus_m_plus_reg9c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rega0:8;
        RBus_UInt32  wpr_rega1:8;
        RBus_UInt32  wpr_rega2:8;
        RBus_UInt32  wpr_rega3:8;
    };
}lg_m_plus_m_plus_rega0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rega4:8;
        RBus_UInt32  wpr_rega5:8;
        RBus_UInt32  wpr_rega6:8;
        RBus_UInt32  wpr_rega7:8;
    };
}lg_m_plus_m_plus_rega4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rega8:8;
        RBus_UInt32  wpr_rega9:8;
        RBus_UInt32  wpr_regaa:8;
        RBus_UInt32  wpr_regab:8;
    };
}lg_m_plus_m_plus_rega8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regac:8;
        RBus_UInt32  wpr_regad:8;
        RBus_UInt32  wpr_regae:8;
        RBus_UInt32  wpr_regaf:8;
    };
}lg_m_plus_m_plus_regac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regb0:8;
        RBus_UInt32  wpr_regb1:8;
        RBus_UInt32  wpr_regb2:8;
        RBus_UInt32  wpr_regb3:8;
    };
}lg_m_plus_m_plus_regb0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regb4:8;
        RBus_UInt32  wpr_regb5:8;
        RBus_UInt32  wpr_regb6:8;
        RBus_UInt32  wpr_regb7:8;
    };
}lg_m_plus_m_plus_regb4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regb8:8;
        RBus_UInt32  wpr_regb9:8;
        RBus_UInt32  wpr_regba:8;
        RBus_UInt32  wpr_regbb:8;
    };
}lg_m_plus_m_plus_regb8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regbc:8;
        RBus_UInt32  wpr_regbd:8;
        RBus_UInt32  wpr_regbe:8;
        RBus_UInt32  wpr_regbf:8;
    };
}lg_m_plus_m_plus_regbc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regc0:8;
        RBus_UInt32  wpr_regc1:8;
        RBus_UInt32  wpr_regc2:8;
        RBus_UInt32  wpr_regc3:8;
    };
}lg_m_plus_m_plus_regc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regc4:8;
        RBus_UInt32  wpr_regc5:8;
        RBus_UInt32  wpr_regc6:8;
        RBus_UInt32  wpr_regc7:8;
    };
}lg_m_plus_m_plus_regc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regc8:8;
        RBus_UInt32  wpr_regc9:8;
        RBus_UInt32  wpr_regca:8;
        RBus_UInt32  wpr_regcb:8;
    };
}lg_m_plus_m_plus_regc8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regcc:8;
        RBus_UInt32  wpr_regcd:8;
        RBus_UInt32  wpr_regce:8;
        RBus_UInt32  wpr_regcf:8;
    };
}lg_m_plus_m_plus_regcc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regd0:8;
        RBus_UInt32  wpr_regd1:8;
        RBus_UInt32  wpr_regd2:8;
        RBus_UInt32  wpr_regd3:8;
    };
}lg_m_plus_m_plus_regd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regd4:8;
        RBus_UInt32  wpr_regd5:8;
        RBus_UInt32  wpr_regd6:8;
        RBus_UInt32  wpr_regd7:8;
    };
}lg_m_plus_m_plus_regd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regd8:8;
        RBus_UInt32  wpr_regd9:8;
        RBus_UInt32  wpr_regda:8;
        RBus_UInt32  wpr_regdb:8;
    };
}lg_m_plus_m_plus_regd8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regdc:8;
        RBus_UInt32  wpr_regdd:8;
        RBus_UInt32  wpr_regde:8;
        RBus_UInt32  wpr_regdf:8;
    };
}lg_m_plus_m_plus_regdc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rege0:8;
        RBus_UInt32  wpr_rege1:8;
        RBus_UInt32  wpr_rege2:8;
        RBus_UInt32  wpr_rege3:8;
    };
}lg_m_plus_m_plus_wpr_rege0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rege4:8;
        RBus_UInt32  wpr_rege5:8;
        RBus_UInt32  wpr_rege6:8;
        RBus_UInt32  wpr_rege7:8;
    };
}lg_m_plus_m_plus_wpr_rege4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rege8:8;
        RBus_UInt32  wpr_rege9:8;
        RBus_UInt32  wpr_regea:8;
        RBus_UInt32  wpr_regeb:8;
    };
}lg_m_plus_m_plus_wpr_rege8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regec:8;
        RBus_UInt32  wpr_reged:8;
        RBus_UInt32  wpr_regee:8;
        RBus_UInt32  wpr_regef:8;
    };
}lg_m_plus_m_plus_wpr_regec_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dimming_duty_force_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dimming_duty_force_value:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  dimming_duty_gain:6;
        RBus_UInt32  dimming_duty_shift:8;
    };
}lg_m_plus_m_plus_dimming_duty_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irq_en:1;
        RBus_UInt32  dimming_duty_update:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  frame_cnt:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  dimming_duty:13;
    };
}lg_m_plus_m_plus_dimming_duty_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  drf_bist_fail_6:1;
        RBus_UInt32  drf_bist_fail_5:1;
        RBus_UInt32  drf_bist_fail_4:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_7:1;
        RBus_UInt32  bist_fail_6:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_7:1;
        RBus_UInt32  testrwm_6:1;
        RBus_UInt32  testrwm_5:1;
        RBus_UInt32  testrwm_4:1;
        RBus_UInt32  testrwm_3:1;
        RBus_UInt32  testrwm_2:1;
        RBus_UInt32  testrwm_1:1;
        RBus_UInt32  testrwm_0:1;
    };
}lg_m_plus_m_plus_sram_bist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_7:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
    };
}lg_m_plus_m_plus_sram_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rme_r2:1;
        RBus_UInt32  rme_g2:1;
        RBus_UInt32  rme_b2:1;
        RBus_UInt32  rme_r1:1;
        RBus_UInt32  rme_g1:1;
        RBus_UInt32  rme_b1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rm_r2:4;
        RBus_UInt32  rm_g2:4;
        RBus_UInt32  rm_b2:4;
        RBus_UInt32  rm_r1:4;
        RBus_UInt32  rm_g1:4;
        RBus_UInt32  rm_b1:4;
    };
}lg_m_plus_m_plus_rom_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  testrwm_7:1;
        RBus_UInt32  rme_2_2:1;
        RBus_UInt32  rme_2_1:1;
        RBus_UInt32  rme_2_0:1;
        RBus_UInt32  drf_bist_fail_2_2:1;
        RBus_UInt32  drf_bist_fail_2_1:1;
        RBus_UInt32  drf_bist_fail_2_0:1;
        RBus_UInt32  bist_fail_2_2:1;
        RBus_UInt32  bist_fail_2_1:1;
        RBus_UInt32  bist_fail_2_0:1;
        RBus_UInt32  testrwm_2_2:1;
        RBus_UInt32  testrwm_2_1:1;
        RBus_UInt32  testrwm_2_0:1;
        RBus_UInt32  rm_2_2:4;
        RBus_UInt32  rm_2_1:4;
        RBus_UInt32  rm_2_0:4;
    };
}lg_m_plus_m_plus_sram_bist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  rme_3_4:1;
        RBus_UInt32  rme_3_3:1;
        RBus_UInt32  rme_3_2:1;
        RBus_UInt32  rme_3_1:1;
        RBus_UInt32  rme_3_0:1;
        RBus_UInt32  drf_bist_fail_3_4:1;
        RBus_UInt32  drf_bist_fail_3_3:1;
        RBus_UInt32  drf_bist_fail_3_2:1;
        RBus_UInt32  drf_bist_fail_3_1:1;
        RBus_UInt32  drf_bist_fail_3_0:1;
        RBus_UInt32  bist_fail_3_4:1;
        RBus_UInt32  bist_fail_3_3:1;
        RBus_UInt32  bist_fail_3_2:1;
        RBus_UInt32  bist_fail_3_1:1;
        RBus_UInt32  bist_fail_3_0:1;
    };
}lg_m_plus_m_plus_sram_bist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  rm_3_4:4;
        RBus_UInt32  rm_3_3:4;
        RBus_UInt32  rm_3_2:4;
        RBus_UInt32  rm_3_1:4;
        RBus_UInt32  rm_3_0:4;
    };
}lg_m_plus_m_plus_sram_bist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rme_2_r2:1;
        RBus_UInt32  rme_2_g2:1;
        RBus_UInt32  rme_2_b2:1;
        RBus_UInt32  rme_2_r1:1;
        RBus_UInt32  rme_2_g1:1;
        RBus_UInt32  rme_2_b1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rm_2_r2:4;
        RBus_UInt32  rm_2_g2:4;
        RBus_UInt32  rm_2_b2:4;
        RBus_UInt32  rm_2_r1:4;
        RBus_UInt32  rm_2_g1:4;
        RBus_UInt32  rm_2_b1:4;
    };
}lg_m_plus_m_plus_rom_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regf0:8;
        RBus_UInt32  wpr_regf1:8;
        RBus_UInt32  wpr_regf2:8;
        RBus_UInt32  wpr_regf3:8;
    };
}lg_m_plus_m_plus_wpr_regf0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regf4:8;
        RBus_UInt32  wpr_regf5:8;
        RBus_UInt32  wpr_regf6:8;
        RBus_UInt32  wpr_regf7:8;
    };
}lg_m_plus_m_plus_wpr_regf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regf8:8;
        RBus_UInt32  wpr_regf9:8;
        RBus_UInt32  wpr_regfa:8;
        RBus_UInt32  wpr_regfb:8;
    };
}lg_m_plus_m_plus_wpr_regf8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regfc:8;
        RBus_UInt32  wpr_regfd:8;
        RBus_UInt32  wpr_regfe:8;
        RBus_UInt32  wpr_regff:8;
    };
}lg_m_plus_m_plus_wpr_regfc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg100:8;
        RBus_UInt32  wpr_reg101:8;
        RBus_UInt32  wpr_reg102:8;
        RBus_UInt32  wpr_reg103:8;
    };
}lg_m_plus_m_plus_wpr_reg100_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg104:8;
        RBus_UInt32  wpr_reg105:8;
        RBus_UInt32  wpr_reg106:8;
        RBus_UInt32  wpr_reg107:8;
    };
}lg_m_plus_m_plus_wpr_reg104_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg108:8;
        RBus_UInt32  wpr_reg109:8;
        RBus_UInt32  wpr_reg10a:8;
        RBus_UInt32  wpr_reg10b:8;
    };
}lg_m_plus_m_plus_wpr_reg108_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg10c:8;
        RBus_UInt32  wpr_reg10d:8;
        RBus_UInt32  wpr_reg10e:8;
        RBus_UInt32  wpr_reg10f:8;
    };
}lg_m_plus_m_plus_wpr_reg10c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg110:8;
        RBus_UInt32  wpr_reg111:8;
        RBus_UInt32  wpr_reg112:8;
        RBus_UInt32  wpr_reg113:8;
    };
}lg_m_plus_m_plus_wpr_reg110_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg114:8;
        RBus_UInt32  wpr_reg115:8;
        RBus_UInt32  wpr_reg116:8;
        RBus_UInt32  wpr_reg117:8;
    };
}lg_m_plus_m_plus_wpr_reg114_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg118:8;
        RBus_UInt32  wpr_reg119:8;
        RBus_UInt32  wpr_reg11a:8;
        RBus_UInt32  wpr_reg11b:8;
    };
}lg_m_plus_m_plus_wpr_reg118_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg11c:8;
        RBus_UInt32  wpr_reg11d:8;
        RBus_UInt32  wpr_reg11e:8;
        RBus_UInt32  wpr_reg11f:8;
    };
}lg_m_plus_m_plus_wpr_reg11c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg120:8;
        RBus_UInt32  wpr_reg121:8;
        RBus_UInt32  wpr_reg122:8;
        RBus_UInt32  wpr_reg123:8;
    };
}lg_m_plus_m_plus_wpr_reg120_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg124:8;
        RBus_UInt32  wpr_reg125:8;
        RBus_UInt32  wpr_reg126:8;
        RBus_UInt32  wpr_reg127:8;
    };
}lg_m_plus_m_plus_wpr_reg124_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg128:8;
        RBus_UInt32  wpr_reg129:8;
        RBus_UInt32  wpr_reg12a:8;
        RBus_UInt32  wpr_reg12b:8;
    };
}lg_m_plus_m_plus_wpr_reg128_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg12c:8;
        RBus_UInt32  wpr_reg12d:8;
        RBus_UInt32  wpr_reg12e:8;
        RBus_UInt32  wpr_reg12f:8;
    };
}lg_m_plus_m_plus_wpr_reg12c_RBUS;

#else //apply LITTLE_ENDIAN

//======LG_M_PLUS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_sel:2;
        RBus_UInt32  test_mode:1;
        RBus_UInt32  mode_3d:1;
        RBus_UInt32  auto_detect_en:1;
        RBus_UInt32  bypass_on:1;
        RBus_UInt32  type_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  auto_detect_result:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  user_timing_sel:1;
        RBus_UInt32  res3:16;
        RBus_UInt32  wse_on:1;
        RBus_UInt32  opc_on:1;
        RBus_UInt32  wpr_on:1;
    };
}lg_m_plus_m_plus_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg03:8;
        RBus_UInt32  wpr_reg02:8;
        RBus_UInt32  wpr_reg01:8;
        RBus_UInt32  wpr_reg00:8;
    };
}lg_m_plus_m_plus_reg00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg07:8;
        RBus_UInt32  wpr_reg06:8;
        RBus_UInt32  wpr_reg05:8;
        RBus_UInt32  wpr_reg04:8;
    };
}lg_m_plus_m_plus_reg04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg0b:8;
        RBus_UInt32  wpr_reg0a:8;
        RBus_UInt32  wpr_reg09:8;
        RBus_UInt32  wpr_reg08:8;
    };
}lg_m_plus_m_plus_reg08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg0f:8;
        RBus_UInt32  wpr_reg0e:8;
        RBus_UInt32  wpr_reg0d:8;
        RBus_UInt32  wpr_reg0c:8;
    };
}lg_m_plus_m_plus_reg0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg13:8;
        RBus_UInt32  wpr_reg12:8;
        RBus_UInt32  wpr_reg11:8;
        RBus_UInt32  wpr_reg10:8;
    };
}lg_m_plus_m_plus_reg10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg17:8;
        RBus_UInt32  wpr_reg16:8;
        RBus_UInt32  wpr_reg15:8;
        RBus_UInt32  wpr_reg14:8;
    };
}lg_m_plus_m_plus_reg14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg1b:8;
        RBus_UInt32  wpr_reg1a:8;
        RBus_UInt32  wpr_reg19:8;
        RBus_UInt32  wpr_reg18:8;
    };
}lg_m_plus_m_plus_reg18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg1f:8;
        RBus_UInt32  wpr_reg1e:8;
        RBus_UInt32  wpr_reg1d:8;
        RBus_UInt32  wpr_reg1c:8;
    };
}lg_m_plus_m_plus_reg1c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg23:8;
        RBus_UInt32  wpr_reg22:8;
        RBus_UInt32  wpr_reg21:8;
        RBus_UInt32  wpr_reg20:8;
    };
}lg_m_plus_m_plus_reg20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg27:8;
        RBus_UInt32  wpr_reg26:8;
        RBus_UInt32  wpr_reg25:8;
        RBus_UInt32  wpr_reg24:8;
    };
}lg_m_plus_m_plus_reg24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg2b:8;
        RBus_UInt32  wpr_reg2a:8;
        RBus_UInt32  wpr_reg29:8;
        RBus_UInt32  wpr_reg28:8;
    };
}lg_m_plus_m_plus_reg28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg2f:8;
        RBus_UInt32  wpr_reg2e:8;
        RBus_UInt32  wpr_reg2d:8;
        RBus_UInt32  wpr_reg2c:8;
    };
}lg_m_plus_m_plus_reg2c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg33:8;
        RBus_UInt32  wpr_reg32:8;
        RBus_UInt32  wpr_reg31:8;
        RBus_UInt32  wpr_reg30:8;
    };
}lg_m_plus_m_plus_reg30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg37:8;
        RBus_UInt32  wpr_reg36:8;
        RBus_UInt32  wpr_reg35:8;
        RBus_UInt32  wpr_reg34:8;
    };
}lg_m_plus_m_plus_reg34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg3b:8;
        RBus_UInt32  wpr_reg3a:8;
        RBus_UInt32  wpr_reg39:8;
        RBus_UInt32  wpr_reg38:8;
    };
}lg_m_plus_m_plus_reg38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg3f:8;
        RBus_UInt32  wpr_reg3e:8;
        RBus_UInt32  wpr_reg3d:8;
        RBus_UInt32  wpr_reg3c:8;
    };
}lg_m_plus_m_plus_reg3c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg43:8;
        RBus_UInt32  wpr_reg42:8;
        RBus_UInt32  wpr_reg41:8;
        RBus_UInt32  wpr_reg40:8;
    };
}lg_m_plus_m_plus_reg40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg47:8;
        RBus_UInt32  wpr_reg46:8;
        RBus_UInt32  wpr_reg45:8;
        RBus_UInt32  wpr_reg44:8;
    };
}lg_m_plus_m_plus_reg44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg4b:8;
        RBus_UInt32  wpr_reg4a:8;
        RBus_UInt32  wpr_reg49:8;
        RBus_UInt32  wpr_reg48:8;
    };
}lg_m_plus_m_plus_reg48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg4f:8;
        RBus_UInt32  wpr_reg4e:8;
        RBus_UInt32  wpr_reg4d:8;
        RBus_UInt32  wpr_reg4c:8;
    };
}lg_m_plus_m_plus_reg4c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg53:8;
        RBus_UInt32  wpr_reg52:8;
        RBus_UInt32  wpr_reg51:8;
        RBus_UInt32  wpr_reg50:8;
    };
}lg_m_plus_m_plus_reg50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg57:8;
        RBus_UInt32  wpr_reg56:8;
        RBus_UInt32  wpr_reg55:8;
        RBus_UInt32  wpr_reg54:8;
    };
}lg_m_plus_m_plus_reg54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg5b:8;
        RBus_UInt32  wpr_reg5a:8;
        RBus_UInt32  wpr_reg59:8;
        RBus_UInt32  wpr_reg58:8;
    };
}lg_m_plus_m_plus_reg58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg5f:8;
        RBus_UInt32  wpr_reg5e:8;
        RBus_UInt32  wpr_reg5d:8;
        RBus_UInt32  wpr_reg5c:8;
    };
}lg_m_plus_m_plus_reg5c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg63:8;
        RBus_UInt32  wpr_reg62:8;
        RBus_UInt32  wpr_reg61:8;
        RBus_UInt32  wpr_reg60:8;
    };
}lg_m_plus_m_plus_reg60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg67:8;
        RBus_UInt32  wpr_reg66:8;
        RBus_UInt32  wpr_reg65:8;
        RBus_UInt32  wpr_reg64:8;
    };
}lg_m_plus_m_plus_reg64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg6b:8;
        RBus_UInt32  wpr_reg6a:8;
        RBus_UInt32  wpr_reg69:8;
        RBus_UInt32  wpr_reg68:8;
    };
}lg_m_plus_m_plus_reg68_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg6f:8;
        RBus_UInt32  wpr_reg6e:8;
        RBus_UInt32  wpr_reg6d:8;
        RBus_UInt32  wpr_reg6c:8;
    };
}lg_m_plus_m_plus_reg6c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg73:8;
        RBus_UInt32  wpr_reg72:8;
        RBus_UInt32  wpr_reg71:8;
        RBus_UInt32  wpr_reg70:8;
    };
}lg_m_plus_m_plus_reg70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg77:8;
        RBus_UInt32  wpr_reg76:8;
        RBus_UInt32  wpr_reg75:8;
        RBus_UInt32  wpr_reg74:8;
    };
}lg_m_plus_m_plus_reg74_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg7b:8;
        RBus_UInt32  wpr_reg7a:8;
        RBus_UInt32  wpr_reg79:8;
        RBus_UInt32  wpr_reg78:8;
    };
}lg_m_plus_m_plus_reg78_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg7f:8;
        RBus_UInt32  wpr_reg7e:8;
        RBus_UInt32  wpr_reg7d:8;
        RBus_UInt32  wpr_reg7c:8;
    };
}lg_m_plus_m_plus_reg7c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg83:8;
        RBus_UInt32  wpr_reg82:8;
        RBus_UInt32  wpr_reg81:8;
        RBus_UInt32  wpr_reg80:8;
    };
}lg_m_plus_m_plus_reg80_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg87:8;
        RBus_UInt32  wpr_reg86:8;
        RBus_UInt32  wpr_reg85:8;
        RBus_UInt32  wpr_reg84:8;
    };
}lg_m_plus_m_plus_reg84_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg8b:8;
        RBus_UInt32  wpr_reg8a:8;
        RBus_UInt32  wpr_reg89:8;
        RBus_UInt32  wpr_reg88:8;
    };
}lg_m_plus_m_plus_reg88_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg8f:8;
        RBus_UInt32  wpr_reg8e:8;
        RBus_UInt32  wpr_reg8d:8;
        RBus_UInt32  wpr_reg8c:8;
    };
}lg_m_plus_m_plus_reg8c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg93:8;
        RBus_UInt32  wpr_reg92:8;
        RBus_UInt32  wpr_reg91:8;
        RBus_UInt32  wpr_reg90:8;
    };
}lg_m_plus_m_plus_reg90_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg97:8;
        RBus_UInt32  wpr_reg96:8;
        RBus_UInt32  wpr_reg95:8;
        RBus_UInt32  wpr_reg94:8;
    };
}lg_m_plus_m_plus_reg94_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg9b:8;
        RBus_UInt32  wpr_reg9a:8;
        RBus_UInt32  wpr_reg99:8;
        RBus_UInt32  wpr_reg98:8;
    };
}lg_m_plus_m_plus_reg98_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg9f:8;
        RBus_UInt32  wpr_reg9e:8;
        RBus_UInt32  wpr_reg9d:8;
        RBus_UInt32  wpr_reg9c:8;
    };
}lg_m_plus_m_plus_reg9c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rega3:8;
        RBus_UInt32  wpr_rega2:8;
        RBus_UInt32  wpr_rega1:8;
        RBus_UInt32  wpr_rega0:8;
    };
}lg_m_plus_m_plus_rega0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rega7:8;
        RBus_UInt32  wpr_rega6:8;
        RBus_UInt32  wpr_rega5:8;
        RBus_UInt32  wpr_rega4:8;
    };
}lg_m_plus_m_plus_rega4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regab:8;
        RBus_UInt32  wpr_regaa:8;
        RBus_UInt32  wpr_rega9:8;
        RBus_UInt32  wpr_rega8:8;
    };
}lg_m_plus_m_plus_rega8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regaf:8;
        RBus_UInt32  wpr_regae:8;
        RBus_UInt32  wpr_regad:8;
        RBus_UInt32  wpr_regac:8;
    };
}lg_m_plus_m_plus_regac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regb3:8;
        RBus_UInt32  wpr_regb2:8;
        RBus_UInt32  wpr_regb1:8;
        RBus_UInt32  wpr_regb0:8;
    };
}lg_m_plus_m_plus_regb0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regb7:8;
        RBus_UInt32  wpr_regb6:8;
        RBus_UInt32  wpr_regb5:8;
        RBus_UInt32  wpr_regb4:8;
    };
}lg_m_plus_m_plus_regb4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regbb:8;
        RBus_UInt32  wpr_regba:8;
        RBus_UInt32  wpr_regb9:8;
        RBus_UInt32  wpr_regb8:8;
    };
}lg_m_plus_m_plus_regb8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regbf:8;
        RBus_UInt32  wpr_regbe:8;
        RBus_UInt32  wpr_regbd:8;
        RBus_UInt32  wpr_regbc:8;
    };
}lg_m_plus_m_plus_regbc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regc3:8;
        RBus_UInt32  wpr_regc2:8;
        RBus_UInt32  wpr_regc1:8;
        RBus_UInt32  wpr_regc0:8;
    };
}lg_m_plus_m_plus_regc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regc7:8;
        RBus_UInt32  wpr_regc6:8;
        RBus_UInt32  wpr_regc5:8;
        RBus_UInt32  wpr_regc4:8;
    };
}lg_m_plus_m_plus_regc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regcb:8;
        RBus_UInt32  wpr_regca:8;
        RBus_UInt32  wpr_regc9:8;
        RBus_UInt32  wpr_regc8:8;
    };
}lg_m_plus_m_plus_regc8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regcf:8;
        RBus_UInt32  wpr_regce:8;
        RBus_UInt32  wpr_regcd:8;
        RBus_UInt32  wpr_regcc:8;
    };
}lg_m_plus_m_plus_regcc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regd3:8;
        RBus_UInt32  wpr_regd2:8;
        RBus_UInt32  wpr_regd1:8;
        RBus_UInt32  wpr_regd0:8;
    };
}lg_m_plus_m_plus_regd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regd7:8;
        RBus_UInt32  wpr_regd6:8;
        RBus_UInt32  wpr_regd5:8;
        RBus_UInt32  wpr_regd4:8;
    };
}lg_m_plus_m_plus_regd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regdb:8;
        RBus_UInt32  wpr_regda:8;
        RBus_UInt32  wpr_regd9:8;
        RBus_UInt32  wpr_regd8:8;
    };
}lg_m_plus_m_plus_regd8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regdf:8;
        RBus_UInt32  wpr_regde:8;
        RBus_UInt32  wpr_regdd:8;
        RBus_UInt32  wpr_regdc:8;
    };
}lg_m_plus_m_plus_regdc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rege3:8;
        RBus_UInt32  wpr_rege2:8;
        RBus_UInt32  wpr_rege1:8;
        RBus_UInt32  wpr_rege0:8;
    };
}lg_m_plus_m_plus_wpr_rege0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_rege7:8;
        RBus_UInt32  wpr_rege6:8;
        RBus_UInt32  wpr_rege5:8;
        RBus_UInt32  wpr_rege4:8;
    };
}lg_m_plus_m_plus_wpr_rege4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regeb:8;
        RBus_UInt32  wpr_regea:8;
        RBus_UInt32  wpr_rege9:8;
        RBus_UInt32  wpr_rege8:8;
    };
}lg_m_plus_m_plus_wpr_rege8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regef:8;
        RBus_UInt32  wpr_regee:8;
        RBus_UInt32  wpr_reged:8;
        RBus_UInt32  wpr_regec:8;
    };
}lg_m_plus_m_plus_wpr_regec_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dimming_duty_shift:8;
        RBus_UInt32  dimming_duty_gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dimming_duty_force_value:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  dimming_duty_force_en:1;
    };
}lg_m_plus_m_plus_dimming_duty_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dimming_duty:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_cnt:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  dimming_duty_update:1;
        RBus_UInt32  irq_en:1;
    };
}lg_m_plus_m_plus_dimming_duty_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  testrwm_0:1;
        RBus_UInt32  testrwm_1:1;
        RBus_UInt32  testrwm_2:1;
        RBus_UInt32  testrwm_3:1;
        RBus_UInt32  testrwm_4:1;
        RBus_UInt32  testrwm_5:1;
        RBus_UInt32  testrwm_6:1;
        RBus_UInt32  bist_fail_7:1;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_6:1;
        RBus_UInt32  drf_bist_fail_7:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_4:1;
        RBus_UInt32  drf_bist_fail_5:1;
        RBus_UInt32  drf_bist_fail_6:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  ls:1;
    };
}lg_m_plus_m_plus_sram_bist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_7:4;
    };
}lg_m_plus_m_plus_sram_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_b1:4;
        RBus_UInt32  rm_g1:4;
        RBus_UInt32  rm_r1:4;
        RBus_UInt32  rm_b2:4;
        RBus_UInt32  rm_g2:4;
        RBus_UInt32  rm_r2:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  rme_b1:1;
        RBus_UInt32  rme_g1:1;
        RBus_UInt32  rme_r1:1;
        RBus_UInt32  rme_b2:1;
        RBus_UInt32  rme_g2:1;
        RBus_UInt32  rme_r2:1;
        RBus_UInt32  res2:1;
    };
}lg_m_plus_m_plus_rom_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_2_0:4;
        RBus_UInt32  rm_2_1:4;
        RBus_UInt32  rm_2_2:4;
        RBus_UInt32  testrwm_2_0:1;
        RBus_UInt32  testrwm_2_1:1;
        RBus_UInt32  testrwm_2_2:1;
        RBus_UInt32  bist_fail_2_0:1;
        RBus_UInt32  bist_fail_2_1:1;
        RBus_UInt32  bist_fail_2_2:1;
        RBus_UInt32  drf_bist_fail_2_0:1;
        RBus_UInt32  drf_bist_fail_2_1:1;
        RBus_UInt32  drf_bist_fail_2_2:1;
        RBus_UInt32  rme_2_0:1;
        RBus_UInt32  rme_2_1:1;
        RBus_UInt32  rme_2_2:1;
        RBus_UInt32  testrwm_7:1;
        RBus_UInt32  res1:7;
    };
}lg_m_plus_m_plus_sram_bist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_3_0:1;
        RBus_UInt32  bist_fail_3_1:1;
        RBus_UInt32  bist_fail_3_2:1;
        RBus_UInt32  bist_fail_3_3:1;
        RBus_UInt32  bist_fail_3_4:1;
        RBus_UInt32  drf_bist_fail_3_0:1;
        RBus_UInt32  drf_bist_fail_3_1:1;
        RBus_UInt32  drf_bist_fail_3_2:1;
        RBus_UInt32  drf_bist_fail_3_3:1;
        RBus_UInt32  drf_bist_fail_3_4:1;
        RBus_UInt32  rme_3_0:1;
        RBus_UInt32  rme_3_1:1;
        RBus_UInt32  rme_3_2:1;
        RBus_UInt32  rme_3_3:1;
        RBus_UInt32  rme_3_4:1;
        RBus_UInt32  res1:17;
    };
}lg_m_plus_m_plus_sram_bist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_3_0:4;
        RBus_UInt32  rm_3_1:4;
        RBus_UInt32  rm_3_2:4;
        RBus_UInt32  rm_3_3:4;
        RBus_UInt32  rm_3_4:4;
        RBus_UInt32  res1:12;
    };
}lg_m_plus_m_plus_sram_bist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_2_b1:4;
        RBus_UInt32  rm_2_g1:4;
        RBus_UInt32  rm_2_r1:4;
        RBus_UInt32  rm_2_b2:4;
        RBus_UInt32  rm_2_g2:4;
        RBus_UInt32  rm_2_r2:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  rme_2_b1:1;
        RBus_UInt32  rme_2_g1:1;
        RBus_UInt32  rme_2_r1:1;
        RBus_UInt32  rme_2_b2:1;
        RBus_UInt32  rme_2_g2:1;
        RBus_UInt32  rme_2_r2:1;
        RBus_UInt32  res2:1;
    };
}lg_m_plus_m_plus_rom_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regf3:8;
        RBus_UInt32  wpr_regf2:8;
        RBus_UInt32  wpr_regf1:8;
        RBus_UInt32  wpr_regf0:8;
    };
}lg_m_plus_m_plus_wpr_regf0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regf7:8;
        RBus_UInt32  wpr_regf6:8;
        RBus_UInt32  wpr_regf5:8;
        RBus_UInt32  wpr_regf4:8;
    };
}lg_m_plus_m_plus_wpr_regf4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regfb:8;
        RBus_UInt32  wpr_regfa:8;
        RBus_UInt32  wpr_regf9:8;
        RBus_UInt32  wpr_regf8:8;
    };
}lg_m_plus_m_plus_wpr_regf8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_regff:8;
        RBus_UInt32  wpr_regfe:8;
        RBus_UInt32  wpr_regfd:8;
        RBus_UInt32  wpr_regfc:8;
    };
}lg_m_plus_m_plus_wpr_regfc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg103:8;
        RBus_UInt32  wpr_reg102:8;
        RBus_UInt32  wpr_reg101:8;
        RBus_UInt32  wpr_reg100:8;
    };
}lg_m_plus_m_plus_wpr_reg100_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg107:8;
        RBus_UInt32  wpr_reg106:8;
        RBus_UInt32  wpr_reg105:8;
        RBus_UInt32  wpr_reg104:8;
    };
}lg_m_plus_m_plus_wpr_reg104_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg10b:8;
        RBus_UInt32  wpr_reg10a:8;
        RBus_UInt32  wpr_reg109:8;
        RBus_UInt32  wpr_reg108:8;
    };
}lg_m_plus_m_plus_wpr_reg108_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg10f:8;
        RBus_UInt32  wpr_reg10e:8;
        RBus_UInt32  wpr_reg10d:8;
        RBus_UInt32  wpr_reg10c:8;
    };
}lg_m_plus_m_plus_wpr_reg10c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg113:8;
        RBus_UInt32  wpr_reg112:8;
        RBus_UInt32  wpr_reg111:8;
        RBus_UInt32  wpr_reg110:8;
    };
}lg_m_plus_m_plus_wpr_reg110_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg117:8;
        RBus_UInt32  wpr_reg116:8;
        RBus_UInt32  wpr_reg115:8;
        RBus_UInt32  wpr_reg114:8;
    };
}lg_m_plus_m_plus_wpr_reg114_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg11b:8;
        RBus_UInt32  wpr_reg11a:8;
        RBus_UInt32  wpr_reg119:8;
        RBus_UInt32  wpr_reg118:8;
    };
}lg_m_plus_m_plus_wpr_reg118_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg11f:8;
        RBus_UInt32  wpr_reg11e:8;
        RBus_UInt32  wpr_reg11d:8;
        RBus_UInt32  wpr_reg11c:8;
    };
}lg_m_plus_m_plus_wpr_reg11c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg123:8;
        RBus_UInt32  wpr_reg122:8;
        RBus_UInt32  wpr_reg121:8;
        RBus_UInt32  wpr_reg120:8;
    };
}lg_m_plus_m_plus_wpr_reg120_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg127:8;
        RBus_UInt32  wpr_reg126:8;
        RBus_UInt32  wpr_reg125:8;
        RBus_UInt32  wpr_reg124:8;
    };
}lg_m_plus_m_plus_wpr_reg124_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg12b:8;
        RBus_UInt32  wpr_reg12a:8;
        RBus_UInt32  wpr_reg129:8;
        RBus_UInt32  wpr_reg128:8;
    };
}lg_m_plus_m_plus_wpr_reg128_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wpr_reg12f:8;
        RBus_UInt32  wpr_reg12e:8;
        RBus_UInt32  wpr_reg12d:8;
        RBus_UInt32  wpr_reg12c:8;
    };
}lg_m_plus_m_plus_wpr_reg12c_RBUS;




#endif 


#endif 
