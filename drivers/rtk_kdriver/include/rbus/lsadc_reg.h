/**
* @file Macarthur5-DesignSpec-ISO_MISC_LSADC
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LSADC_REG_H_
#define _RBUS_LSADC_REG_H_

#include "rbus_types.h"



//  LSADC Register Address
#define  LSADC_ST_pad0                                                           0x18061500
#define  LSADC_ST_pad0_reg_addr                                                  "0xB8061500"
#define  LSADC_ST_pad0_reg                                                       0xB8061500
#define  LSADC_ST_pad0_inst_addr                                                 "0x0000"
#define  set_LSADC_ST_pad0_reg(data)                                             (*((volatile unsigned int*)LSADC_ST_pad0_reg)=data)
#define  get_LSADC_ST_pad0_reg                                                   (*((volatile unsigned int*)LSADC_ST_pad0_reg))
#define  LSADC_ST_pad0_pad0_active_shift                                         (31)
#define  LSADC_ST_pad0_pad0_thred_shift                                          (16)
#define  LSADC_ST_pad0_pad0_sw_shift                                             (12)
#define  LSADC_ST_pad0_pad0_ctrl_shift                                           (8)
#define  LSADC_ST_pad0_adc_val0_shift                                            (0)
#define  LSADC_ST_pad0_pad0_active_mask                                          (0x80000000)
#define  LSADC_ST_pad0_pad0_thred_mask                                           (0x00FF0000)
#define  LSADC_ST_pad0_pad0_sw_mask                                              (0x0000F000)
#define  LSADC_ST_pad0_pad0_ctrl_mask                                            (0x00000100)
#define  LSADC_ST_pad0_adc_val0_mask                                             (0x000000FF)
#define  LSADC_ST_pad0_pad0_active(data)                                         (0x80000000&((data)<<31))
#define  LSADC_ST_pad0_pad0_thred(data)                                          (0x00FF0000&((data)<<16))
#define  LSADC_ST_pad0_pad0_sw(data)                                             (0x0000F000&((data)<<12))
#define  LSADC_ST_pad0_pad0_ctrl(data)                                           (0x00000100&((data)<<8))
#define  LSADC_ST_pad0_adc_val0(data)                                            (0x000000FF&(data))
#define  LSADC_ST_pad0_get_pad0_active(data)                                     ((0x80000000&(data))>>31)
#define  LSADC_ST_pad0_get_pad0_thred(data)                                      ((0x00FF0000&(data))>>16)
#define  LSADC_ST_pad0_get_pad0_sw(data)                                         ((0x0000F000&(data))>>12)
#define  LSADC_ST_pad0_get_pad0_ctrl(data)                                       ((0x00000100&(data))>>8)
#define  LSADC_ST_pad0_get_adc_val0(data)                                        (0x000000FF&(data))

#define  LSADC_ST_pad1                                                           0x18061504
#define  LSADC_ST_pad1_reg_addr                                                  "0xB8061504"
#define  LSADC_ST_pad1_reg                                                       0xB8061504
#define  LSADC_ST_pad1_inst_addr                                                 "0x0001"
#define  set_LSADC_ST_pad1_reg(data)                                             (*((volatile unsigned int*)LSADC_ST_pad1_reg)=data)
#define  get_LSADC_ST_pad1_reg                                                   (*((volatile unsigned int*)LSADC_ST_pad1_reg))
#define  LSADC_ST_pad1_pad1_active_shift                                         (31)
#define  LSADC_ST_pad1_pad1_thred_shift                                          (16)
#define  LSADC_ST_pad1_pad1_sw_shift                                             (12)
#define  LSADC_ST_pad1_pad1_ctrl_shift                                           (8)
#define  LSADC_ST_pad1_adc_val1_shift                                            (0)
#define  LSADC_ST_pad1_pad1_active_mask                                          (0x80000000)
#define  LSADC_ST_pad1_pad1_thred_mask                                           (0x00FF0000)
#define  LSADC_ST_pad1_pad1_sw_mask                                              (0x0000F000)
#define  LSADC_ST_pad1_pad1_ctrl_mask                                            (0x00000100)
#define  LSADC_ST_pad1_adc_val1_mask                                             (0x000000FF)
#define  LSADC_ST_pad1_pad1_active(data)                                         (0x80000000&((data)<<31))
#define  LSADC_ST_pad1_pad1_thred(data)                                          (0x00FF0000&((data)<<16))
#define  LSADC_ST_pad1_pad1_sw(data)                                             (0x0000F000&((data)<<12))
#define  LSADC_ST_pad1_pad1_ctrl(data)                                           (0x00000100&((data)<<8))
#define  LSADC_ST_pad1_adc_val1(data)                                            (0x000000FF&(data))
#define  LSADC_ST_pad1_get_pad1_active(data)                                     ((0x80000000&(data))>>31)
#define  LSADC_ST_pad1_get_pad1_thred(data)                                      ((0x00FF0000&(data))>>16)
#define  LSADC_ST_pad1_get_pad1_sw(data)                                         ((0x0000F000&(data))>>12)
#define  LSADC_ST_pad1_get_pad1_ctrl(data)                                       ((0x00000100&(data))>>8)
#define  LSADC_ST_pad1_get_adc_val1(data)                                        (0x000000FF&(data))

#define  LSADC_ST_pad2                                                           0x18061508
#define  LSADC_ST_pad2_reg_addr                                                  "0xB8061508"
#define  LSADC_ST_pad2_reg                                                       0xB8061508
#define  LSADC_ST_pad2_inst_addr                                                 "0x0002"
#define  set_LSADC_ST_pad2_reg(data)                                             (*((volatile unsigned int*)LSADC_ST_pad2_reg)=data)
#define  get_LSADC_ST_pad2_reg                                                   (*((volatile unsigned int*)LSADC_ST_pad2_reg))
#define  LSADC_ST_pad2_pad2_active_shift                                         (31)
#define  LSADC_ST_pad2_pad2_thred_shift                                          (16)
#define  LSADC_ST_pad2_pad2_sw_shift                                             (12)
#define  LSADC_ST_pad2_pad2_ctrl_shift                                           (8)
#define  LSADC_ST_pad2_adc_val2_shift                                            (0)
#define  LSADC_ST_pad2_pad2_active_mask                                          (0x80000000)
#define  LSADC_ST_pad2_pad2_thred_mask                                           (0x00FF0000)
#define  LSADC_ST_pad2_pad2_sw_mask                                              (0x0000F000)
#define  LSADC_ST_pad2_pad2_ctrl_mask                                            (0x00000100)
#define  LSADC_ST_pad2_adc_val2_mask                                             (0x000000FF)
#define  LSADC_ST_pad2_pad2_active(data)                                         (0x80000000&((data)<<31))
#define  LSADC_ST_pad2_pad2_thred(data)                                          (0x00FF0000&((data)<<16))
#define  LSADC_ST_pad2_pad2_sw(data)                                             (0x0000F000&((data)<<12))
#define  LSADC_ST_pad2_pad2_ctrl(data)                                           (0x00000100&((data)<<8))
#define  LSADC_ST_pad2_adc_val2(data)                                            (0x000000FF&(data))
#define  LSADC_ST_pad2_get_pad2_active(data)                                     ((0x80000000&(data))>>31)
#define  LSADC_ST_pad2_get_pad2_thred(data)                                      ((0x00FF0000&(data))>>16)
#define  LSADC_ST_pad2_get_pad2_sw(data)                                         ((0x0000F000&(data))>>12)
#define  LSADC_ST_pad2_get_pad2_ctrl(data)                                       ((0x00000100&(data))>>8)
#define  LSADC_ST_pad2_get_adc_val2(data)                                        (0x000000FF&(data))

#define  LSADC_ST_pad3                                                           0x1806150C
#define  LSADC_ST_pad3_reg_addr                                                  "0xB806150C"
#define  LSADC_ST_pad3_reg                                                       0xB806150C
#define  LSADC_ST_pad3_inst_addr                                                 "0x0003"
#define  set_LSADC_ST_pad3_reg(data)                                             (*((volatile unsigned int*)LSADC_ST_pad3_reg)=data)
#define  get_LSADC_ST_pad3_reg                                                   (*((volatile unsigned int*)LSADC_ST_pad3_reg))
#define  LSADC_ST_pad3_pad3_active_shift                                         (31)
#define  LSADC_ST_pad3_pad3_thred_shift                                          (16)
#define  LSADC_ST_pad3_pad3_sw_shift                                             (12)
#define  LSADC_ST_pad3_pad3_ctrl_shift                                           (8)
#define  LSADC_ST_pad3_adc_val3_shift                                            (0)
#define  LSADC_ST_pad3_pad3_active_mask                                          (0x80000000)
#define  LSADC_ST_pad3_pad3_thred_mask                                           (0x00FF0000)
#define  LSADC_ST_pad3_pad3_sw_mask                                              (0x0000F000)
#define  LSADC_ST_pad3_pad3_ctrl_mask                                            (0x00000100)
#define  LSADC_ST_pad3_adc_val3_mask                                             (0x000000FF)
#define  LSADC_ST_pad3_pad3_active(data)                                         (0x80000000&((data)<<31))
#define  LSADC_ST_pad3_pad3_thred(data)                                          (0x00FF0000&((data)<<16))
#define  LSADC_ST_pad3_pad3_sw(data)                                             (0x0000F000&((data)<<12))
#define  LSADC_ST_pad3_pad3_ctrl(data)                                           (0x00000100&((data)<<8))
#define  LSADC_ST_pad3_adc_val3(data)                                            (0x000000FF&(data))
#define  LSADC_ST_pad3_get_pad3_active(data)                                     ((0x80000000&(data))>>31)
#define  LSADC_ST_pad3_get_pad3_thred(data)                                      ((0x00FF0000&(data))>>16)
#define  LSADC_ST_pad3_get_pad3_sw(data)                                         ((0x0000F000&(data))>>12)
#define  LSADC_ST_pad3_get_pad3_ctrl(data)                                       ((0x00000100&(data))>>8)
#define  LSADC_ST_pad3_get_adc_val3(data)                                        (0x000000FF&(data))

#define  LSADC_ST_pad4                                                           0x18061510
#define  LSADC_ST_pad4_reg_addr                                                  "0xB8061510"
#define  LSADC_ST_pad4_reg                                                       0xB8061510
#define  LSADC_ST_pad4_inst_addr                                                 "0x0004"
#define  set_LSADC_ST_pad4_reg(data)                                             (*((volatile unsigned int*)LSADC_ST_pad4_reg)=data)
#define  get_LSADC_ST_pad4_reg                                                   (*((volatile unsigned int*)LSADC_ST_pad4_reg))
#define  LSADC_ST_pad4_pad4_active_shift                                         (31)
#define  LSADC_ST_pad4_pad4_thred_shift                                          (16)
#define  LSADC_ST_pad4_pad4_sw_shift                                             (12)
#define  LSADC_ST_pad4_pad4_ctrl_shift                                           (8)
#define  LSADC_ST_pad4_adc_val4_shift                                            (0)
#define  LSADC_ST_pad4_pad4_active_mask                                          (0x80000000)
#define  LSADC_ST_pad4_pad4_thred_mask                                           (0x00FF0000)
#define  LSADC_ST_pad4_pad4_sw_mask                                              (0x0000F000)
#define  LSADC_ST_pad4_pad4_ctrl_mask                                            (0x00000100)
#define  LSADC_ST_pad4_adc_val4_mask                                             (0x000000FF)
#define  LSADC_ST_pad4_pad4_active(data)                                         (0x80000000&((data)<<31))
#define  LSADC_ST_pad4_pad4_thred(data)                                          (0x00FF0000&((data)<<16))
#define  LSADC_ST_pad4_pad4_sw(data)                                             (0x0000F000&((data)<<12))
#define  LSADC_ST_pad4_pad4_ctrl(data)                                           (0x00000100&((data)<<8))
#define  LSADC_ST_pad4_adc_val4(data)                                            (0x000000FF&(data))
#define  LSADC_ST_pad4_get_pad4_active(data)                                     ((0x80000000&(data))>>31)
#define  LSADC_ST_pad4_get_pad4_thred(data)                                      ((0x00FF0000&(data))>>16)
#define  LSADC_ST_pad4_get_pad4_sw(data)                                         ((0x0000F000&(data))>>12)
#define  LSADC_ST_pad4_get_pad4_ctrl(data)                                       ((0x00000100&(data))>>8)
#define  LSADC_ST_pad4_get_adc_val4(data)                                        (0x000000FF&(data))

#define  LSADC_ST_pad5                                                           0x18061514
#define  LSADC_ST_pad5_reg_addr                                                  "0xB8061514"
#define  LSADC_ST_pad5_reg                                                       0xB8061514
#define  LSADC_ST_pad5_inst_addr                                                 "0x0005"
#define  set_LSADC_ST_pad5_reg(data)                                             (*((volatile unsigned int*)LSADC_ST_pad5_reg)=data)
#define  get_LSADC_ST_pad5_reg                                                   (*((volatile unsigned int*)LSADC_ST_pad5_reg))
#define  LSADC_ST_pad5_pad5_active_shift                                         (31)
#define  LSADC_ST_pad5_pad5_thred_shift                                          (16)
#define  LSADC_ST_pad5_pad5_sw_shift                                             (12)
#define  LSADC_ST_pad5_pad5_ctrl_shift                                           (8)
#define  LSADC_ST_pad5_adc_val5_shift                                            (0)
#define  LSADC_ST_pad5_pad5_active_mask                                          (0x80000000)
#define  LSADC_ST_pad5_pad5_thred_mask                                           (0x00FF0000)
#define  LSADC_ST_pad5_pad5_sw_mask                                              (0x0000F000)
#define  LSADC_ST_pad5_pad5_ctrl_mask                                            (0x00000100)
#define  LSADC_ST_pad5_adc_val5_mask                                             (0x000000FF)
#define  LSADC_ST_pad5_pad5_active(data)                                         (0x80000000&((data)<<31))
#define  LSADC_ST_pad5_pad5_thred(data)                                          (0x00FF0000&((data)<<16))
#define  LSADC_ST_pad5_pad5_sw(data)                                             (0x0000F000&((data)<<12))
#define  LSADC_ST_pad5_pad5_ctrl(data)                                           (0x00000100&((data)<<8))
#define  LSADC_ST_pad5_adc_val5(data)                                            (0x000000FF&(data))
#define  LSADC_ST_pad5_get_pad5_active(data)                                     ((0x80000000&(data))>>31)
#define  LSADC_ST_pad5_get_pad5_thred(data)                                      ((0x00FF0000&(data))>>16)
#define  LSADC_ST_pad5_get_pad5_sw(data)                                         ((0x0000F000&(data))>>12)
#define  LSADC_ST_pad5_get_pad5_ctrl(data)                                       ((0x00000100&(data))>>8)
#define  LSADC_ST_pad5_get_adc_val5(data)                                        (0x000000FF&(data))

#define  LSADC_ST_pad6                                                           0x18061518
#define  LSADC_ST_pad6_reg_addr                                                  "0xB8061518"
#define  LSADC_ST_pad6_reg                                                       0xB8061518
#define  LSADC_ST_pad6_inst_addr                                                 "0x0006"
#define  set_LSADC_ST_pad6_reg(data)                                             (*((volatile unsigned int*)LSADC_ST_pad6_reg)=data)
#define  get_LSADC_ST_pad6_reg                                                   (*((volatile unsigned int*)LSADC_ST_pad6_reg))
#define  LSADC_ST_pad6_pad6_active_shift                                         (31)
#define  LSADC_ST_pad6_pad6_thred_shift                                          (16)
#define  LSADC_ST_pad6_pad6_sw_shift                                             (12)
#define  LSADC_ST_pad6_pad6_ctrl_shift                                           (8)
#define  LSADC_ST_pad6_adc_val6_shift                                            (0)
#define  LSADC_ST_pad6_pad6_active_mask                                          (0x80000000)
#define  LSADC_ST_pad6_pad6_thred_mask                                           (0x00FF0000)
#define  LSADC_ST_pad6_pad6_sw_mask                                              (0x0000F000)
#define  LSADC_ST_pad6_pad6_ctrl_mask                                            (0x00000100)
#define  LSADC_ST_pad6_adc_val6_mask                                             (0x000000FF)
#define  LSADC_ST_pad6_pad6_active(data)                                         (0x80000000&((data)<<31))
#define  LSADC_ST_pad6_pad6_thred(data)                                          (0x00FF0000&((data)<<16))
#define  LSADC_ST_pad6_pad6_sw(data)                                             (0x0000F000&((data)<<12))
#define  LSADC_ST_pad6_pad6_ctrl(data)                                           (0x00000100&((data)<<8))
#define  LSADC_ST_pad6_adc_val6(data)                                            (0x000000FF&(data))
#define  LSADC_ST_pad6_get_pad6_active(data)                                     ((0x80000000&(data))>>31)
#define  LSADC_ST_pad6_get_pad6_thred(data)                                      ((0x00FF0000&(data))>>16)
#define  LSADC_ST_pad6_get_pad6_sw(data)                                         ((0x0000F000&(data))>>12)
#define  LSADC_ST_pad6_get_pad6_ctrl(data)                                       ((0x00000100&(data))>>8)
#define  LSADC_ST_pad6_get_adc_val6(data)                                        (0x000000FF&(data))

#define  LSADC_ST_pad7                                                           0x1806151C
#define  LSADC_ST_pad7_reg_addr                                                  "0xB806151C"
#define  LSADC_ST_pad7_reg                                                       0xB806151C
#define  LSADC_ST_pad7_inst_addr                                                 "0x0007"
#define  set_LSADC_ST_pad7_reg(data)                                             (*((volatile unsigned int*)LSADC_ST_pad7_reg)=data)
#define  get_LSADC_ST_pad7_reg                                                   (*((volatile unsigned int*)LSADC_ST_pad7_reg))
#define  LSADC_ST_pad7_pad7_active_shift                                         (31)
#define  LSADC_ST_pad7_pad7_thred_shift                                          (16)
#define  LSADC_ST_pad7_pad7_sw_shift                                             (12)
#define  LSADC_ST_pad7_pad7_ctrl_shift                                           (8)
#define  LSADC_ST_pad7_adc_val7_shift                                            (0)
#define  LSADC_ST_pad7_pad7_active_mask                                          (0x80000000)
#define  LSADC_ST_pad7_pad7_thred_mask                                           (0x00FF0000)
#define  LSADC_ST_pad7_pad7_sw_mask                                              (0x0000F000)
#define  LSADC_ST_pad7_pad7_ctrl_mask                                            (0x00000100)
#define  LSADC_ST_pad7_adc_val7_mask                                             (0x000000FF)
#define  LSADC_ST_pad7_pad7_active(data)                                         (0x80000000&((data)<<31))
#define  LSADC_ST_pad7_pad7_thred(data)                                          (0x00FF0000&((data)<<16))
#define  LSADC_ST_pad7_pad7_sw(data)                                             (0x0000F000&((data)<<12))
#define  LSADC_ST_pad7_pad7_ctrl(data)                                           (0x00000100&((data)<<8))
#define  LSADC_ST_pad7_adc_val7(data)                                            (0x000000FF&(data))
#define  LSADC_ST_pad7_get_pad7_active(data)                                     ((0x80000000&(data))>>31)
#define  LSADC_ST_pad7_get_pad7_thred(data)                                      ((0x00FF0000&(data))>>16)
#define  LSADC_ST_pad7_get_pad7_sw(data)                                         ((0x0000F000&(data))>>12)
#define  LSADC_ST_pad7_get_pad7_ctrl(data)                                       ((0x00000100&(data))>>8)
#define  LSADC_ST_pad7_get_adc_val7(data)                                        (0x000000FF&(data))

#define  LSADC_ST_LSADC_ctrl                                                     0x18061520
#define  LSADC_ST_LSADC_ctrl_reg_addr                                            "0xB8061520"
#define  LSADC_ST_LSADC_ctrl_reg                                                 0xB8061520
#define  LSADC_ST_LSADC_ctrl_inst_addr                                           "0x0008"
#define  set_LSADC_ST_LSADC_ctrl_reg(data)                                       (*((volatile unsigned int*)LSADC_ST_LSADC_ctrl_reg)=data)
#define  get_LSADC_ST_LSADC_ctrl_reg                                             (*((volatile unsigned int*)LSADC_ST_LSADC_ctrl_reg))
#define  LSADC_ST_LSADC_ctrl_sel_wait_shift                                      (28)
#define  LSADC_ST_LSADC_ctrl_sel_adc_ck_shift                                    (24)
#define  LSADC_ST_LSADC_ctrl_debounce_cnt_shift                                  (20)
#define  LSADC_ST_LSADC_ctrl_dout_test_in_shift                                  (8)
#define  LSADC_ST_LSADC_ctrl_test_en_shift                                       (1)
#define  LSADC_ST_LSADC_ctrl_enable_shift                                        (0)
#define  LSADC_ST_LSADC_ctrl_sel_wait_mask                                       (0xF0000000)
#define  LSADC_ST_LSADC_ctrl_sel_adc_ck_mask                                     (0x0F000000)
#define  LSADC_ST_LSADC_ctrl_debounce_cnt_mask                                   (0x00F00000)
#define  LSADC_ST_LSADC_ctrl_dout_test_in_mask                                   (0x0000FF00)
#define  LSADC_ST_LSADC_ctrl_test_en_mask                                        (0x00000002)
#define  LSADC_ST_LSADC_ctrl_enable_mask                                         (0x00000001)
#define  LSADC_ST_LSADC_ctrl_sel_wait(data)                                      (0xF0000000&((data)<<28))
#define  LSADC_ST_LSADC_ctrl_sel_adc_ck(data)                                    (0x0F000000&((data)<<24))
#define  LSADC_ST_LSADC_ctrl_debounce_cnt(data)                                  (0x00F00000&((data)<<20))
#define  LSADC_ST_LSADC_ctrl_dout_test_in(data)                                  (0x0000FF00&((data)<<8))
#define  LSADC_ST_LSADC_ctrl_test_en(data)                                       (0x00000002&((data)<<1))
#define  LSADC_ST_LSADC_ctrl_enable(data)                                        (0x00000001&(data))
#define  LSADC_ST_LSADC_ctrl_get_sel_wait(data)                                  ((0xF0000000&(data))>>28)
#define  LSADC_ST_LSADC_ctrl_get_sel_adc_ck(data)                                ((0x0F000000&(data))>>24)
#define  LSADC_ST_LSADC_ctrl_get_debounce_cnt(data)                              ((0x00F00000&(data))>>20)
#define  LSADC_ST_LSADC_ctrl_get_dout_test_in(data)                              ((0x0000FF00&(data))>>8)
#define  LSADC_ST_LSADC_ctrl_get_test_en(data)                                   ((0x00000002&(data))>>1)
#define  LSADC_ST_LSADC_ctrl_get_enable(data)                                    (0x00000001&(data))

#define  LSADC_ST_LSADC_status                                                   0x18061524
#define  LSADC_ST_LSADC_status_reg_addr                                          "0xB8061524"
#define  LSADC_ST_LSADC_status_reg                                               0xB8061524
#define  LSADC_ST_LSADC_status_inst_addr                                         "0x0009"
#define  set_LSADC_ST_LSADC_status_reg(data)                                     (*((volatile unsigned int*)LSADC_ST_LSADC_status_reg)=data)
#define  get_LSADC_ST_LSADC_status_reg                                           (*((volatile unsigned int*)LSADC_ST_LSADC_status_reg))
#define  LSADC_ST_LSADC_status_irq_en_shift                                      (24)
#define  LSADC_ST_LSADC_status_pad_cnt_shift                                     (20)
#define  LSADC_ST_LSADC_status_adc_busy_shift                                    (19)
#define  LSADC_ST_LSADC_status_pad_ctrl_shift                                    (12)
#define  LSADC_ST_LSADC_status_pad7_status_shift                                 (7)
#define  LSADC_ST_LSADC_status_pad6_status_shift                                 (6)
#define  LSADC_ST_LSADC_status_pad5_status_shift                                 (5)
#define  LSADC_ST_LSADC_status_pad4_status_shift                                 (4)
#define  LSADC_ST_LSADC_status_pad3_status_shift                                 (3)
#define  LSADC_ST_LSADC_status_pad2_status_shift                                 (2)
#define  LSADC_ST_LSADC_status_pad1_status_shift                                 (1)
#define  LSADC_ST_LSADC_status_pad0_status_shift                                 (0)
#define  LSADC_ST_LSADC_status_irq_en_mask                                       (0xFF000000)
#define  LSADC_ST_LSADC_status_pad_cnt_mask                                      (0x00F00000)
#define  LSADC_ST_LSADC_status_adc_busy_mask                                     (0x00080000)
#define  LSADC_ST_LSADC_status_pad_ctrl_mask                                     (0x0001F000)
#define  LSADC_ST_LSADC_status_pad7_status_mask                                  (0x00000080)
#define  LSADC_ST_LSADC_status_pad6_status_mask                                  (0x00000040)
#define  LSADC_ST_LSADC_status_pad5_status_mask                                  (0x00000020)
#define  LSADC_ST_LSADC_status_pad4_status_mask                                  (0x00000010)
#define  LSADC_ST_LSADC_status_pad3_status_mask                                  (0x00000008)
#define  LSADC_ST_LSADC_status_pad2_status_mask                                  (0x00000004)
#define  LSADC_ST_LSADC_status_pad1_status_mask                                  (0x00000002)
#define  LSADC_ST_LSADC_status_pad0_status_mask                                  (0x00000001)
#define  LSADC_ST_LSADC_status_irq_en(data)                                      (0xFF000000&((data)<<24))
#define  LSADC_ST_LSADC_status_pad_cnt(data)                                     (0x00F00000&((data)<<20))
#define  LSADC_ST_LSADC_status_adc_busy(data)                                    (0x00080000&((data)<<19))
#define  LSADC_ST_LSADC_status_pad_ctrl(data)                                    (0x0001F000&((data)<<12))
#define  LSADC_ST_LSADC_status_pad7_status(data)                                 (0x00000080&((data)<<7))
#define  LSADC_ST_LSADC_status_pad6_status(data)                                 (0x00000040&((data)<<6))
#define  LSADC_ST_LSADC_status_pad5_status(data)                                 (0x00000020&((data)<<5))
#define  LSADC_ST_LSADC_status_pad4_status(data)                                 (0x00000010&((data)<<4))
#define  LSADC_ST_LSADC_status_pad3_status(data)                                 (0x00000008&((data)<<3))
#define  LSADC_ST_LSADC_status_pad2_status(data)                                 (0x00000004&((data)<<2))
#define  LSADC_ST_LSADC_status_pad1_status(data)                                 (0x00000002&((data)<<1))
#define  LSADC_ST_LSADC_status_pad0_status(data)                                 (0x00000001&(data))
#define  LSADC_ST_LSADC_status_get_irq_en(data)                                  ((0xFF000000&(data))>>24)
#define  LSADC_ST_LSADC_status_get_pad_cnt(data)                                 ((0x00F00000&(data))>>20)
#define  LSADC_ST_LSADC_status_get_adc_busy(data)                                ((0x00080000&(data))>>19)
#define  LSADC_ST_LSADC_status_get_pad_ctrl(data)                                ((0x0001F000&(data))>>12)
#define  LSADC_ST_LSADC_status_get_pad7_status(data)                             ((0x00000080&(data))>>7)
#define  LSADC_ST_LSADC_status_get_pad6_status(data)                             ((0x00000040&(data))>>6)
#define  LSADC_ST_LSADC_status_get_pad5_status(data)                             ((0x00000020&(data))>>5)
#define  LSADC_ST_LSADC_status_get_pad4_status(data)                             ((0x00000010&(data))>>4)
#define  LSADC_ST_LSADC_status_get_pad3_status(data)                             ((0x00000008&(data))>>3)
#define  LSADC_ST_LSADC_status_get_pad2_status(data)                             ((0x00000004&(data))>>2)
#define  LSADC_ST_LSADC_status_get_pad1_status(data)                             ((0x00000002&(data))>>1)
#define  LSADC_ST_LSADC_status_get_pad0_status(data)                             (0x00000001&(data))

#define  LSADC_ST_LSADC_analog_ctrl                                              0x18061528
#define  LSADC_ST_LSADC_analog_ctrl_reg_addr                                     "0xB8061528"
#define  LSADC_ST_LSADC_analog_ctrl_reg                                          0xB8061528
#define  LSADC_ST_LSADC_analog_ctrl_inst_addr                                    "0x000A"
#define  set_LSADC_ST_LSADC_analog_ctrl_reg(data)                                (*((volatile unsigned int*)LSADC_ST_LSADC_analog_ctrl_reg)=data)
#define  get_LSADC_ST_LSADC_analog_ctrl_reg                                      (*((volatile unsigned int*)LSADC_ST_LSADC_analog_ctrl_reg))
#define  LSADC_ST_LSADC_analog_ctrl_jd_sbias_shift                               (16)
#define  LSADC_ST_LSADC_analog_ctrl_jd_adsbias_shift                             (12)
#define  LSADC_ST_LSADC_analog_ctrl_jd_dummy_shift                               (10)
#define  LSADC_ST_LSADC_analog_ctrl_jd_svr_shift                                 (8)
#define  LSADC_ST_LSADC_analog_ctrl_jd_adcksel_shift                             (4)
#define  LSADC_ST_LSADC_analog_ctrl_jd_power_shift                               (0)
#define  LSADC_ST_LSADC_analog_ctrl_jd_sbias_mask                                (0x00030000)
#define  LSADC_ST_LSADC_analog_ctrl_jd_adsbias_mask                              (0x00003000)
#define  LSADC_ST_LSADC_analog_ctrl_jd_dummy_mask                                (0x00000C00)
#define  LSADC_ST_LSADC_analog_ctrl_jd_svr_mask                                  (0x00000100)
#define  LSADC_ST_LSADC_analog_ctrl_jd_adcksel_mask                              (0x00000010)
#define  LSADC_ST_LSADC_analog_ctrl_jd_power_mask                                (0x00000001)
#define  LSADC_ST_LSADC_analog_ctrl_jd_sbias(data)                               (0x00030000&((data)<<16))
#define  LSADC_ST_LSADC_analog_ctrl_jd_adsbias(data)                             (0x00003000&((data)<<12))
#define  LSADC_ST_LSADC_analog_ctrl_jd_dummy(data)                               (0x00000C00&((data)<<10))
#define  LSADC_ST_LSADC_analog_ctrl_jd_svr(data)                                 (0x00000100&((data)<<8))
#define  LSADC_ST_LSADC_analog_ctrl_jd_adcksel(data)                             (0x00000010&((data)<<4))
#define  LSADC_ST_LSADC_analog_ctrl_jd_power(data)                               (0x00000001&(data))
#define  LSADC_ST_LSADC_analog_ctrl_get_jd_sbias(data)                           ((0x00030000&(data))>>16)
#define  LSADC_ST_LSADC_analog_ctrl_get_jd_adsbias(data)                         ((0x00003000&(data))>>12)
#define  LSADC_ST_LSADC_analog_ctrl_get_jd_dummy(data)                           ((0x00000C00&(data))>>10)
#define  LSADC_ST_LSADC_analog_ctrl_get_jd_svr(data)                             ((0x00000100&(data))>>8)
#define  LSADC_ST_LSADC_analog_ctrl_get_jd_adcksel(data)                         ((0x00000010&(data))>>4)
#define  LSADC_ST_LSADC_analog_ctrl_get_jd_power(data)                           (0x00000001&(data))

#define  LSADC_ST_LSADC_peri_top_debug                                           0x1806152C
#define  LSADC_ST_LSADC_peri_top_debug_reg_addr                                  "0xB806152C"
#define  LSADC_ST_LSADC_peri_top_debug_reg                                       0xB806152C
#define  LSADC_ST_LSADC_peri_top_debug_inst_addr                                 "0x000B"
#define  set_LSADC_ST_LSADC_peri_top_debug_reg(data)                             (*((volatile unsigned int*)LSADC_ST_LSADC_peri_top_debug_reg)=data)
#define  get_LSADC_ST_LSADC_peri_top_debug_reg                                   (*((volatile unsigned int*)LSADC_ST_LSADC_peri_top_debug_reg))
#define  LSADC_ST_LSADC_peri_top_debug_lsadc_2_ifd_data_sel_shift                (16)
#define  LSADC_ST_LSADC_peri_top_debug_peri_top_debug_shift                      (0)
#define  LSADC_ST_LSADC_peri_top_debug_lsadc_2_ifd_data_sel_mask                 (0x00070000)
#define  LSADC_ST_LSADC_peri_top_debug_peri_top_debug_mask                       (0x000000FF)
#define  LSADC_ST_LSADC_peri_top_debug_lsadc_2_ifd_data_sel(data)                (0x00070000&((data)<<16))
#define  LSADC_ST_LSADC_peri_top_debug_peri_top_debug(data)                      (0x000000FF&(data))
#define  LSADC_ST_LSADC_peri_top_debug_get_lsadc_2_ifd_data_sel(data)            ((0x00070000&(data))>>16)
#define  LSADC_ST_LSADC_peri_top_debug_get_peri_top_debug(data)                  (0x000000FF&(data))

#define  LSADC_LSADC_pad5_level_set0                                             0x18061530
#define  LSADC_LSADC_pad5_level_set0_reg_addr                                    "0xB8061530"
#define  LSADC_LSADC_pad5_level_set0_reg                                         0xB8061530
#define  LSADC_LSADC_pad5_level_set0_inst_addr                                   "0x000C"
#define  set_LSADC_LSADC_pad5_level_set0_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set0_reg)=data)
#define  get_LSADC_LSADC_pad5_level_set0_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set0_reg))
#define  LSADC_LSADC_pad5_level_set0_level_0_top_bound_shift                     (24)
#define  LSADC_LSADC_pad5_level_set0_level_0_low_bound_shift                     (16)
#define  LSADC_LSADC_pad5_level_set0_block0_en_shift                             (15)
#define  LSADC_LSADC_pad5_level_set0_int_en0_shift                               (1)
#define  LSADC_LSADC_pad5_level_set0_int_pending_bit0_shift                      (0)
#define  LSADC_LSADC_pad5_level_set0_level_0_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad5_level_set0_level_0_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad5_level_set0_block0_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad5_level_set0_int_en0_mask                                (0x00000002)
#define  LSADC_LSADC_pad5_level_set0_int_pending_bit0_mask                       (0x00000001)
#define  LSADC_LSADC_pad5_level_set0_level_0_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad5_level_set0_level_0_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad5_level_set0_block0_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad5_level_set0_int_en0(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad5_level_set0_int_pending_bit0(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad5_level_set0_get_level_0_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad5_level_set0_get_level_0_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad5_level_set0_get_block0_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad5_level_set0_get_int_en0(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad5_level_set0_get_int_pending_bit0(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad5_level_set1                                             0x18061534
#define  LSADC_LSADC_pad5_level_set1_reg_addr                                    "0xB8061534"
#define  LSADC_LSADC_pad5_level_set1_reg                                         0xB8061534
#define  LSADC_LSADC_pad5_level_set1_inst_addr                                   "0x000D"
#define  set_LSADC_LSADC_pad5_level_set1_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set1_reg)=data)
#define  get_LSADC_LSADC_pad5_level_set1_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set1_reg))
#define  LSADC_LSADC_pad5_level_set1_level_1_top_bound_shift                     (24)
#define  LSADC_LSADC_pad5_level_set1_level_0_low_bound_shift                     (16)
#define  LSADC_LSADC_pad5_level_set1_block1_en_shift                             (15)
#define  LSADC_LSADC_pad5_level_set1_int_en1_shift                               (1)
#define  LSADC_LSADC_pad5_level_set1_int_pending_bit1_shift                      (0)
#define  LSADC_LSADC_pad5_level_set1_level_1_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad5_level_set1_level_0_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad5_level_set1_block1_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad5_level_set1_int_en1_mask                                (0x00000002)
#define  LSADC_LSADC_pad5_level_set1_int_pending_bit1_mask                       (0x00000001)
#define  LSADC_LSADC_pad5_level_set1_level_1_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad5_level_set1_level_0_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad5_level_set1_block1_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad5_level_set1_int_en1(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad5_level_set1_int_pending_bit1(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad5_level_set1_get_level_1_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad5_level_set1_get_level_0_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad5_level_set1_get_block1_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad5_level_set1_get_int_en1(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad5_level_set1_get_int_pending_bit1(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad5_level_set2                                             0x18061538
#define  LSADC_LSADC_pad5_level_set2_reg_addr                                    "0xB8061538"
#define  LSADC_LSADC_pad5_level_set2_reg                                         0xB8061538
#define  LSADC_LSADC_pad5_level_set2_inst_addr                                   "0x000E"
#define  set_LSADC_LSADC_pad5_level_set2_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set2_reg)=data)
#define  get_LSADC_LSADC_pad5_level_set2_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set2_reg))
#define  LSADC_LSADC_pad5_level_set2_level_2_top_bound_shift                     (24)
#define  LSADC_LSADC_pad5_level_set2_level_2_low_bound_shift                     (16)
#define  LSADC_LSADC_pad5_level_set2_block2_en_shift                             (15)
#define  LSADC_LSADC_pad5_level_set2_int_en2_shift                               (1)
#define  LSADC_LSADC_pad5_level_set2_int_pending_bit2_shift                      (0)
#define  LSADC_LSADC_pad5_level_set2_level_2_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad5_level_set2_level_2_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad5_level_set2_block2_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad5_level_set2_int_en2_mask                                (0x00000002)
#define  LSADC_LSADC_pad5_level_set2_int_pending_bit2_mask                       (0x00000001)
#define  LSADC_LSADC_pad5_level_set2_level_2_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad5_level_set2_level_2_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad5_level_set2_block2_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad5_level_set2_int_en2(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad5_level_set2_int_pending_bit2(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad5_level_set2_get_level_2_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad5_level_set2_get_level_2_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad5_level_set2_get_block2_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad5_level_set2_get_int_en2(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad5_level_set2_get_int_pending_bit2(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad5_level_set3                                             0x1806153C
#define  LSADC_LSADC_pad5_level_set3_reg_addr                                    "0xB806153C"
#define  LSADC_LSADC_pad5_level_set3_reg                                         0xB806153C
#define  LSADC_LSADC_pad5_level_set3_inst_addr                                   "0x000F"
#define  set_LSADC_LSADC_pad5_level_set3_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set3_reg)=data)
#define  get_LSADC_LSADC_pad5_level_set3_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set3_reg))
#define  LSADC_LSADC_pad5_level_set3_level_3_top_bound_shift                     (24)
#define  LSADC_LSADC_pad5_level_set3_level_3_low_bound_shift                     (16)
#define  LSADC_LSADC_pad5_level_set3_block3_en_shift                             (15)
#define  LSADC_LSADC_pad5_level_set3_int_en3_shift                               (1)
#define  LSADC_LSADC_pad5_level_set3_int_pending_bit3_shift                      (0)
#define  LSADC_LSADC_pad5_level_set3_level_3_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad5_level_set3_level_3_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad5_level_set3_block3_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad5_level_set3_int_en3_mask                                (0x00000002)
#define  LSADC_LSADC_pad5_level_set3_int_pending_bit3_mask                       (0x00000001)
#define  LSADC_LSADC_pad5_level_set3_level_3_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad5_level_set3_level_3_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad5_level_set3_block3_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad5_level_set3_int_en3(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad5_level_set3_int_pending_bit3(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad5_level_set3_get_level_3_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad5_level_set3_get_level_3_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad5_level_set3_get_block3_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad5_level_set3_get_int_en3(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad5_level_set3_get_int_pending_bit3(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad5_level_set4                                             0x18061540
#define  LSADC_LSADC_pad5_level_set4_reg_addr                                    "0xB8061540"
#define  LSADC_LSADC_pad5_level_set4_reg                                         0xB8061540
#define  LSADC_LSADC_pad5_level_set4_inst_addr                                   "0x0010"
#define  set_LSADC_LSADC_pad5_level_set4_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set4_reg)=data)
#define  get_LSADC_LSADC_pad5_level_set4_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set4_reg))
#define  LSADC_LSADC_pad5_level_set4_level_4_top_bound_shift                     (24)
#define  LSADC_LSADC_pad5_level_set4_level_4_low_bound_shift                     (16)
#define  LSADC_LSADC_pad5_level_set4_block4_en_shift                             (15)
#define  LSADC_LSADC_pad5_level_set4_int_en4_shift                               (1)
#define  LSADC_LSADC_pad5_level_set4_int_pending_bit4_shift                      (0)
#define  LSADC_LSADC_pad5_level_set4_level_4_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad5_level_set4_level_4_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad5_level_set4_block4_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad5_level_set4_int_en4_mask                                (0x00000002)
#define  LSADC_LSADC_pad5_level_set4_int_pending_bit4_mask                       (0x00000001)
#define  LSADC_LSADC_pad5_level_set4_level_4_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad5_level_set4_level_4_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad5_level_set4_block4_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad5_level_set4_int_en4(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad5_level_set4_int_pending_bit4(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad5_level_set4_get_level_4_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad5_level_set4_get_level_4_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad5_level_set4_get_block4_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad5_level_set4_get_int_en4(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad5_level_set4_get_int_pending_bit4(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad5_level_set5                                             0x18061544
#define  LSADC_LSADC_pad5_level_set5_reg_addr                                    "0xB8061544"
#define  LSADC_LSADC_pad5_level_set5_reg                                         0xB8061544
#define  LSADC_LSADC_pad5_level_set5_inst_addr                                   "0x0011"
#define  set_LSADC_LSADC_pad5_level_set5_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set5_reg)=data)
#define  get_LSADC_LSADC_pad5_level_set5_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad5_level_set5_reg))
#define  LSADC_LSADC_pad5_level_set5_level_5_top_bound_shift                     (24)
#define  LSADC_LSADC_pad5_level_set5_level_5_low_bound_shift                     (16)
#define  LSADC_LSADC_pad5_level_set5_block5_en_shift                             (15)
#define  LSADC_LSADC_pad5_level_set5_int_en5_shift                               (1)
#define  LSADC_LSADC_pad5_level_set5_int_pending_bit5_shift                      (0)
#define  LSADC_LSADC_pad5_level_set5_level_5_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad5_level_set5_level_5_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad5_level_set5_block5_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad5_level_set5_int_en5_mask                                (0x00000002)
#define  LSADC_LSADC_pad5_level_set5_int_pending_bit5_mask                       (0x00000001)
#define  LSADC_LSADC_pad5_level_set5_level_5_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad5_level_set5_level_5_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad5_level_set5_block5_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad5_level_set5_int_en5(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad5_level_set5_int_pending_bit5(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad5_level_set5_get_level_5_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad5_level_set5_get_level_5_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad5_level_set5_get_block5_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad5_level_set5_get_int_en5(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad5_level_set5_get_int_pending_bit5(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad6_level_set0                                             0x18061548
#define  LSADC_LSADC_pad6_level_set0_reg_addr                                    "0xB8061548"
#define  LSADC_LSADC_pad6_level_set0_reg                                         0xB8061548
#define  LSADC_LSADC_pad6_level_set0_inst_addr                                   "0x0012"
#define  set_LSADC_LSADC_pad6_level_set0_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set0_reg)=data)
#define  get_LSADC_LSADC_pad6_level_set0_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set0_reg))
#define  LSADC_LSADC_pad6_level_set0_level_0_top_bound_shift                     (24)
#define  LSADC_LSADC_pad6_level_set0_level_0_low_bound_shift                     (16)
#define  LSADC_LSADC_pad6_level_set0_block0_en_shift                             (15)
#define  LSADC_LSADC_pad6_level_set0_int_en0_shift                               (1)
#define  LSADC_LSADC_pad6_level_set0_int_pending_bit0_shift                      (0)
#define  LSADC_LSADC_pad6_level_set0_level_0_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad6_level_set0_level_0_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad6_level_set0_block0_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad6_level_set0_int_en0_mask                                (0x00000002)
#define  LSADC_LSADC_pad6_level_set0_int_pending_bit0_mask                       (0x00000001)
#define  LSADC_LSADC_pad6_level_set0_level_0_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad6_level_set0_level_0_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad6_level_set0_block0_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad6_level_set0_int_en0(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad6_level_set0_int_pending_bit0(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad6_level_set0_get_level_0_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad6_level_set0_get_level_0_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad6_level_set0_get_block0_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad6_level_set0_get_int_en0(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad6_level_set0_get_int_pending_bit0(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad6_level_set1                                             0x1806154C
#define  LSADC_LSADC_pad6_level_set1_reg_addr                                    "0xB806154C"
#define  LSADC_LSADC_pad6_level_set1_reg                                         0xB806154C
#define  LSADC_LSADC_pad6_level_set1_inst_addr                                   "0x0013"
#define  set_LSADC_LSADC_pad6_level_set1_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set1_reg)=data)
#define  get_LSADC_LSADC_pad6_level_set1_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set1_reg))
#define  LSADC_LSADC_pad6_level_set1_level_1_top_bound_shift                     (24)
#define  LSADC_LSADC_pad6_level_set1_level_0_low_bound_shift                     (16)
#define  LSADC_LSADC_pad6_level_set1_block1_en_shift                             (15)
#define  LSADC_LSADC_pad6_level_set1_int_en1_shift                               (1)
#define  LSADC_LSADC_pad6_level_set1_int_pending_bit1_shift                      (0)
#define  LSADC_LSADC_pad6_level_set1_level_1_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad6_level_set1_level_0_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad6_level_set1_block1_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad6_level_set1_int_en1_mask                                (0x00000002)
#define  LSADC_LSADC_pad6_level_set1_int_pending_bit1_mask                       (0x00000001)
#define  LSADC_LSADC_pad6_level_set1_level_1_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad6_level_set1_level_0_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad6_level_set1_block1_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad6_level_set1_int_en1(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad6_level_set1_int_pending_bit1(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad6_level_set1_get_level_1_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad6_level_set1_get_level_0_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad6_level_set1_get_block1_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad6_level_set1_get_int_en1(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad6_level_set1_get_int_pending_bit1(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad6_level_set2                                             0x18061550
#define  LSADC_LSADC_pad6_level_set2_reg_addr                                    "0xB8061550"
#define  LSADC_LSADC_pad6_level_set2_reg                                         0xB8061550
#define  LSADC_LSADC_pad6_level_set2_inst_addr                                   "0x0014"
#define  set_LSADC_LSADC_pad6_level_set2_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set2_reg)=data)
#define  get_LSADC_LSADC_pad6_level_set2_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set2_reg))
#define  LSADC_LSADC_pad6_level_set2_level_2_top_bound_shift                     (24)
#define  LSADC_LSADC_pad6_level_set2_level_2_low_bound_shift                     (16)
#define  LSADC_LSADC_pad6_level_set2_block2_en_shift                             (15)
#define  LSADC_LSADC_pad6_level_set2_int_en2_shift                               (1)
#define  LSADC_LSADC_pad6_level_set2_int_pending_bit2_shift                      (0)
#define  LSADC_LSADC_pad6_level_set2_level_2_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad6_level_set2_level_2_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad6_level_set2_block2_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad6_level_set2_int_en2_mask                                (0x00000002)
#define  LSADC_LSADC_pad6_level_set2_int_pending_bit2_mask                       (0x00000001)
#define  LSADC_LSADC_pad6_level_set2_level_2_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad6_level_set2_level_2_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad6_level_set2_block2_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad6_level_set2_int_en2(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad6_level_set2_int_pending_bit2(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad6_level_set2_get_level_2_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad6_level_set2_get_level_2_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad6_level_set2_get_block2_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad6_level_set2_get_int_en2(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad6_level_set2_get_int_pending_bit2(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad6_level_set3                                             0x18061554
#define  LSADC_LSADC_pad6_level_set3_reg_addr                                    "0xB8061554"
#define  LSADC_LSADC_pad6_level_set3_reg                                         0xB8061554
#define  LSADC_LSADC_pad6_level_set3_inst_addr                                   "0x0015"
#define  set_LSADC_LSADC_pad6_level_set3_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set3_reg)=data)
#define  get_LSADC_LSADC_pad6_level_set3_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set3_reg))
#define  LSADC_LSADC_pad6_level_set3_level_3_top_bound_shift                     (24)
#define  LSADC_LSADC_pad6_level_set3_level_3_low_bound_shift                     (16)
#define  LSADC_LSADC_pad6_level_set3_block3_en_shift                             (15)
#define  LSADC_LSADC_pad6_level_set3_int_en3_shift                               (1)
#define  LSADC_LSADC_pad6_level_set3_int_pending_bit3_shift                      (0)
#define  LSADC_LSADC_pad6_level_set3_level_3_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad6_level_set3_level_3_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad6_level_set3_block3_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad6_level_set3_int_en3_mask                                (0x00000002)
#define  LSADC_LSADC_pad6_level_set3_int_pending_bit3_mask                       (0x00000001)
#define  LSADC_LSADC_pad6_level_set3_level_3_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad6_level_set3_level_3_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad6_level_set3_block3_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad6_level_set3_int_en3(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad6_level_set3_int_pending_bit3(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad6_level_set3_get_level_3_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad6_level_set3_get_level_3_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad6_level_set3_get_block3_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad6_level_set3_get_int_en3(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad6_level_set3_get_int_pending_bit3(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad6_level_set4                                             0x18061558
#define  LSADC_LSADC_pad6_level_set4_reg_addr                                    "0xB8061558"
#define  LSADC_LSADC_pad6_level_set4_reg                                         0xB8061558
#define  LSADC_LSADC_pad6_level_set4_inst_addr                                   "0x0016"
#define  set_LSADC_LSADC_pad6_level_set4_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set4_reg)=data)
#define  get_LSADC_LSADC_pad6_level_set4_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set4_reg))
#define  LSADC_LSADC_pad6_level_set4_level_4_top_bound_shift                     (24)
#define  LSADC_LSADC_pad6_level_set4_level_4_low_bound_shift                     (16)
#define  LSADC_LSADC_pad6_level_set4_block4_en_shift                             (15)
#define  LSADC_LSADC_pad6_level_set4_int_en4_shift                               (1)
#define  LSADC_LSADC_pad6_level_set4_int_pending_bit4_shift                      (0)
#define  LSADC_LSADC_pad6_level_set4_level_4_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad6_level_set4_level_4_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad6_level_set4_block4_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad6_level_set4_int_en4_mask                                (0x00000002)
#define  LSADC_LSADC_pad6_level_set4_int_pending_bit4_mask                       (0x00000001)
#define  LSADC_LSADC_pad6_level_set4_level_4_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad6_level_set4_level_4_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad6_level_set4_block4_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad6_level_set4_int_en4(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad6_level_set4_int_pending_bit4(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad6_level_set4_get_level_4_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad6_level_set4_get_level_4_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad6_level_set4_get_block4_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad6_level_set4_get_int_en4(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad6_level_set4_get_int_pending_bit4(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad6_level_set5                                             0x1806155C
#define  LSADC_LSADC_pad6_level_set5_reg_addr                                    "0xB806155C"
#define  LSADC_LSADC_pad6_level_set5_reg                                         0xB806155C
#define  LSADC_LSADC_pad6_level_set5_inst_addr                                   "0x0017"
#define  set_LSADC_LSADC_pad6_level_set5_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set5_reg)=data)
#define  get_LSADC_LSADC_pad6_level_set5_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad6_level_set5_reg))
#define  LSADC_LSADC_pad6_level_set5_level_5_top_bound_shift                     (24)
#define  LSADC_LSADC_pad6_level_set5_level_5_low_bound_shift                     (16)
#define  LSADC_LSADC_pad6_level_set5_block5_en_shift                             (15)
#define  LSADC_LSADC_pad6_level_set5_int_en5_shift                               (1)
#define  LSADC_LSADC_pad6_level_set5_int_pending_bit5_shift                      (0)
#define  LSADC_LSADC_pad6_level_set5_level_5_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad6_level_set5_level_5_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad6_level_set5_block5_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad6_level_set5_int_en5_mask                                (0x00000002)
#define  LSADC_LSADC_pad6_level_set5_int_pending_bit5_mask                       (0x00000001)
#define  LSADC_LSADC_pad6_level_set5_level_5_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad6_level_set5_level_5_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad6_level_set5_block5_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad6_level_set5_int_en5(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad6_level_set5_int_pending_bit5(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad6_level_set5_get_level_5_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad6_level_set5_get_level_5_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad6_level_set5_get_block5_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad6_level_set5_get_int_en5(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad6_level_set5_get_int_pending_bit5(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad7_level_set0                                             0x18061560
#define  LSADC_LSADC_pad7_level_set0_reg_addr                                    "0xB8061560"
#define  LSADC_LSADC_pad7_level_set0_reg                                         0xB8061560
#define  LSADC_LSADC_pad7_level_set0_inst_addr                                   "0x0018"
#define  set_LSADC_LSADC_pad7_level_set0_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set0_reg)=data)
#define  get_LSADC_LSADC_pad7_level_set0_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set0_reg))
#define  LSADC_LSADC_pad7_level_set0_level_0_top_bound_shift                     (24)
#define  LSADC_LSADC_pad7_level_set0_level_0_low_bound_shift                     (16)
#define  LSADC_LSADC_pad7_level_set0_block0_en_shift                             (15)
#define  LSADC_LSADC_pad7_level_set0_int_en0_shift                               (1)
#define  LSADC_LSADC_pad7_level_set0_int_pending_bit0_shift                      (0)
#define  LSADC_LSADC_pad7_level_set0_level_0_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad7_level_set0_level_0_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad7_level_set0_block0_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad7_level_set0_int_en0_mask                                (0x00000002)
#define  LSADC_LSADC_pad7_level_set0_int_pending_bit0_mask                       (0x00000001)
#define  LSADC_LSADC_pad7_level_set0_level_0_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad7_level_set0_level_0_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad7_level_set0_block0_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad7_level_set0_int_en0(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad7_level_set0_int_pending_bit0(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad7_level_set0_get_level_0_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad7_level_set0_get_level_0_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad7_level_set0_get_block0_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad7_level_set0_get_int_en0(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad7_level_set0_get_int_pending_bit0(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad7_level_set1                                             0x18061564
#define  LSADC_LSADC_pad7_level_set1_reg_addr                                    "0xB8061564"
#define  LSADC_LSADC_pad7_level_set1_reg                                         0xB8061564
#define  LSADC_LSADC_pad7_level_set1_inst_addr                                   "0x0019"
#define  set_LSADC_LSADC_pad7_level_set1_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set1_reg)=data)
#define  get_LSADC_LSADC_pad7_level_set1_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set1_reg))
#define  LSADC_LSADC_pad7_level_set1_level_1_top_bound_shift                     (24)
#define  LSADC_LSADC_pad7_level_set1_level_0_low_bound_shift                     (16)
#define  LSADC_LSADC_pad7_level_set1_block1_en_shift                             (15)
#define  LSADC_LSADC_pad7_level_set1_int_en1_shift                               (1)
#define  LSADC_LSADC_pad7_level_set1_int_pending_bit1_shift                      (0)
#define  LSADC_LSADC_pad7_level_set1_level_1_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad7_level_set1_level_0_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad7_level_set1_block1_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad7_level_set1_int_en1_mask                                (0x00000002)
#define  LSADC_LSADC_pad7_level_set1_int_pending_bit1_mask                       (0x00000001)
#define  LSADC_LSADC_pad7_level_set1_level_1_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad7_level_set1_level_0_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad7_level_set1_block1_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad7_level_set1_int_en1(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad7_level_set1_int_pending_bit1(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad7_level_set1_get_level_1_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad7_level_set1_get_level_0_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad7_level_set1_get_block1_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad7_level_set1_get_int_en1(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad7_level_set1_get_int_pending_bit1(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad7_level_set2                                             0x18061568
#define  LSADC_LSADC_pad7_level_set2_reg_addr                                    "0xB8061568"
#define  LSADC_LSADC_pad7_level_set2_reg                                         0xB8061568
#define  LSADC_LSADC_pad7_level_set2_inst_addr                                   "0x001A"
#define  set_LSADC_LSADC_pad7_level_set2_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set2_reg)=data)
#define  get_LSADC_LSADC_pad7_level_set2_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set2_reg))
#define  LSADC_LSADC_pad7_level_set2_level_2_top_bound_shift                     (24)
#define  LSADC_LSADC_pad7_level_set2_level_2_low_bound_shift                     (16)
#define  LSADC_LSADC_pad7_level_set2_block2_en_shift                             (15)
#define  LSADC_LSADC_pad7_level_set2_int_en2_shift                               (1)
#define  LSADC_LSADC_pad7_level_set2_int_pending_bit2_shift                      (0)
#define  LSADC_LSADC_pad7_level_set2_level_2_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad7_level_set2_level_2_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad7_level_set2_block2_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad7_level_set2_int_en2_mask                                (0x00000002)
#define  LSADC_LSADC_pad7_level_set2_int_pending_bit2_mask                       (0x00000001)
#define  LSADC_LSADC_pad7_level_set2_level_2_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad7_level_set2_level_2_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad7_level_set2_block2_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad7_level_set2_int_en2(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad7_level_set2_int_pending_bit2(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad7_level_set2_get_level_2_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad7_level_set2_get_level_2_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad7_level_set2_get_block2_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad7_level_set2_get_int_en2(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad7_level_set2_get_int_pending_bit2(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad7_level_set3                                             0x1806156C
#define  LSADC_LSADC_pad7_level_set3_reg_addr                                    "0xB806156C"
#define  LSADC_LSADC_pad7_level_set3_reg                                         0xB806156C
#define  LSADC_LSADC_pad7_level_set3_inst_addr                                   "0x001B"
#define  set_LSADC_LSADC_pad7_level_set3_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set3_reg)=data)
#define  get_LSADC_LSADC_pad7_level_set3_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set3_reg))
#define  LSADC_LSADC_pad7_level_set3_level_3_top_bound_shift                     (24)
#define  LSADC_LSADC_pad7_level_set3_level_3_low_bound_shift                     (16)
#define  LSADC_LSADC_pad7_level_set3_block3_en_shift                             (15)
#define  LSADC_LSADC_pad7_level_set3_int_en3_shift                               (1)
#define  LSADC_LSADC_pad7_level_set3_int_pending_bit3_shift                      (0)
#define  LSADC_LSADC_pad7_level_set3_level_3_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad7_level_set3_level_3_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad7_level_set3_block3_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad7_level_set3_int_en3_mask                                (0x00000002)
#define  LSADC_LSADC_pad7_level_set3_int_pending_bit3_mask                       (0x00000001)
#define  LSADC_LSADC_pad7_level_set3_level_3_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad7_level_set3_level_3_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad7_level_set3_block3_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad7_level_set3_int_en3(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad7_level_set3_int_pending_bit3(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad7_level_set3_get_level_3_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad7_level_set3_get_level_3_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad7_level_set3_get_block3_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad7_level_set3_get_int_en3(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad7_level_set3_get_int_pending_bit3(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad7_level_set4                                             0x18061570
#define  LSADC_LSADC_pad7_level_set4_reg_addr                                    "0xB8061570"
#define  LSADC_LSADC_pad7_level_set4_reg                                         0xB8061570
#define  LSADC_LSADC_pad7_level_set4_inst_addr                                   "0x001C"
#define  set_LSADC_LSADC_pad7_level_set4_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set4_reg)=data)
#define  get_LSADC_LSADC_pad7_level_set4_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set4_reg))
#define  LSADC_LSADC_pad7_level_set4_level_4_top_bound_shift                     (24)
#define  LSADC_LSADC_pad7_level_set4_level_4_low_bound_shift                     (16)
#define  LSADC_LSADC_pad7_level_set4_block4_en_shift                             (15)
#define  LSADC_LSADC_pad7_level_set4_int_en4_shift                               (1)
#define  LSADC_LSADC_pad7_level_set4_int_pending_bit4_shift                      (0)
#define  LSADC_LSADC_pad7_level_set4_level_4_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad7_level_set4_level_4_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad7_level_set4_block4_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad7_level_set4_int_en4_mask                                (0x00000002)
#define  LSADC_LSADC_pad7_level_set4_int_pending_bit4_mask                       (0x00000001)
#define  LSADC_LSADC_pad7_level_set4_level_4_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad7_level_set4_level_4_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad7_level_set4_block4_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad7_level_set4_int_en4(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad7_level_set4_int_pending_bit4(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad7_level_set4_get_level_4_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad7_level_set4_get_level_4_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad7_level_set4_get_block4_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad7_level_set4_get_int_en4(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad7_level_set4_get_int_pending_bit4(data)                  (0x00000001&(data))

#define  LSADC_LSADC_pad7_level_set5                                             0x18061574
#define  LSADC_LSADC_pad7_level_set5_reg_addr                                    "0xB8061574"
#define  LSADC_LSADC_pad7_level_set5_reg                                         0xB8061574
#define  LSADC_LSADC_pad7_level_set5_inst_addr                                   "0x001D"
#define  set_LSADC_LSADC_pad7_level_set5_reg(data)                               (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set5_reg)=data)
#define  get_LSADC_LSADC_pad7_level_set5_reg                                     (*((volatile unsigned int*)LSADC_LSADC_pad7_level_set5_reg))
#define  LSADC_LSADC_pad7_level_set5_level_5_top_bound_shift                     (24)
#define  LSADC_LSADC_pad7_level_set5_level_5_low_bound_shift                     (16)
#define  LSADC_LSADC_pad7_level_set5_block5_en_shift                             (15)
#define  LSADC_LSADC_pad7_level_set5_int_en5_shift                               (1)
#define  LSADC_LSADC_pad7_level_set5_int_pending_bit5_shift                      (0)
#define  LSADC_LSADC_pad7_level_set5_level_5_top_bound_mask                      (0xFF000000)
#define  LSADC_LSADC_pad7_level_set5_level_5_low_bound_mask                      (0x00FF0000)
#define  LSADC_LSADC_pad7_level_set5_block5_en_mask                              (0x00008000)
#define  LSADC_LSADC_pad7_level_set5_int_en5_mask                                (0x00000002)
#define  LSADC_LSADC_pad7_level_set5_int_pending_bit5_mask                       (0x00000001)
#define  LSADC_LSADC_pad7_level_set5_level_5_top_bound(data)                     (0xFF000000&((data)<<24))
#define  LSADC_LSADC_pad7_level_set5_level_5_low_bound(data)                     (0x00FF0000&((data)<<16))
#define  LSADC_LSADC_pad7_level_set5_block5_en(data)                             (0x00008000&((data)<<15))
#define  LSADC_LSADC_pad7_level_set5_int_en5(data)                               (0x00000002&((data)<<1))
#define  LSADC_LSADC_pad7_level_set5_int_pending_bit5(data)                      (0x00000001&(data))
#define  LSADC_LSADC_pad7_level_set5_get_level_5_top_bound(data)                 ((0xFF000000&(data))>>24)
#define  LSADC_LSADC_pad7_level_set5_get_level_5_low_bound(data)                 ((0x00FF0000&(data))>>16)
#define  LSADC_LSADC_pad7_level_set5_get_block5_en(data)                         ((0x00008000&(data))>>15)
#define  LSADC_LSADC_pad7_level_set5_get_int_en5(data)                           ((0x00000002&(data))>>1)
#define  LSADC_LSADC_pad7_level_set5_get_int_pending_bit5(data)                  (0x00000001&(data))

#define  LSADC_LSADC_INT_pad5                                                    0x18061578
#define  LSADC_LSADC_INT_pad5_reg_addr                                           "0xB8061578"
#define  LSADC_LSADC_INT_pad5_reg                                                0xB8061578
#define  LSADC_LSADC_INT_pad5_inst_addr                                          "0x001E"
#define  set_LSADC_LSADC_INT_pad5_reg(data)                                      (*((volatile unsigned int*)LSADC_LSADC_INT_pad5_reg)=data)
#define  get_LSADC_LSADC_INT_pad5_reg                                            (*((volatile unsigned int*)LSADC_LSADC_INT_pad5_reg))
#define  LSADC_LSADC_INT_pad5_adc_value5latch_shift                              (8)
#define  LSADC_LSADC_INT_pad5_int_latchset5status_shift                          (5)
#define  LSADC_LSADC_INT_pad5_int_latchset4status_shift                          (4)
#define  LSADC_LSADC_INT_pad5_int_latchset3status_shift                          (3)
#define  LSADC_LSADC_INT_pad5_int_latchset2status_shift                          (2)
#define  LSADC_LSADC_INT_pad5_int_latchset1status_shift                          (1)
#define  LSADC_LSADC_INT_pad5_int_latchset0status_shift                          (0)
#define  LSADC_LSADC_INT_pad5_adc_value5latch_mask                               (0x00003F00)
#define  LSADC_LSADC_INT_pad5_int_latchset5status_mask                           (0x00000020)
#define  LSADC_LSADC_INT_pad5_int_latchset4status_mask                           (0x00000010)
#define  LSADC_LSADC_INT_pad5_int_latchset3status_mask                           (0x00000008)
#define  LSADC_LSADC_INT_pad5_int_latchset2status_mask                           (0x00000004)
#define  LSADC_LSADC_INT_pad5_int_latchset1status_mask                           (0x00000002)
#define  LSADC_LSADC_INT_pad5_int_latchset0status_mask                           (0x00000001)
#define  LSADC_LSADC_INT_pad5_adc_value5latch(data)                              (0x00003F00&((data)<<8))
#define  LSADC_LSADC_INT_pad5_int_latchset5status(data)                          (0x00000020&((data)<<5))
#define  LSADC_LSADC_INT_pad5_int_latchset4status(data)                          (0x00000010&((data)<<4))
#define  LSADC_LSADC_INT_pad5_int_latchset3status(data)                          (0x00000008&((data)<<3))
#define  LSADC_LSADC_INT_pad5_int_latchset2status(data)                          (0x00000004&((data)<<2))
#define  LSADC_LSADC_INT_pad5_int_latchset1status(data)                          (0x00000002&((data)<<1))
#define  LSADC_LSADC_INT_pad5_int_latchset0status(data)                          (0x00000001&(data))
#define  LSADC_LSADC_INT_pad5_get_adc_value5latch(data)                          ((0x00003F00&(data))>>8)
#define  LSADC_LSADC_INT_pad5_get_int_latchset5status(data)                      ((0x00000020&(data))>>5)
#define  LSADC_LSADC_INT_pad5_get_int_latchset4status(data)                      ((0x00000010&(data))>>4)
#define  LSADC_LSADC_INT_pad5_get_int_latchset3status(data)                      ((0x00000008&(data))>>3)
#define  LSADC_LSADC_INT_pad5_get_int_latchset2status(data)                      ((0x00000004&(data))>>2)
#define  LSADC_LSADC_INT_pad5_get_int_latchset1status(data)                      ((0x00000002&(data))>>1)
#define  LSADC_LSADC_INT_pad5_get_int_latchset0status(data)                      (0x00000001&(data))

#define  LSADC_LSADC_INT_pad6                                                    0x1806157C
#define  LSADC_LSADC_INT_pad6_reg_addr                                           "0xB806157C"
#define  LSADC_LSADC_INT_pad6_reg                                                0xB806157C
#define  LSADC_LSADC_INT_pad6_inst_addr                                          "0x001F"
#define  set_LSADC_LSADC_INT_pad6_reg(data)                                      (*((volatile unsigned int*)LSADC_LSADC_INT_pad6_reg)=data)
#define  get_LSADC_LSADC_INT_pad6_reg                                            (*((volatile unsigned int*)LSADC_LSADC_INT_pad6_reg))
#define  LSADC_LSADC_INT_pad6_adc_value6latch_shift                              (8)
#define  LSADC_LSADC_INT_pad6_int_latchset5status_shift                          (5)
#define  LSADC_LSADC_INT_pad6_int_latchset4status_shift                          (4)
#define  LSADC_LSADC_INT_pad6_int_latchset3status_shift                          (3)
#define  LSADC_LSADC_INT_pad6_int_latchset2status_shift                          (2)
#define  LSADC_LSADC_INT_pad6_int_latchset1status_shift                          (1)
#define  LSADC_LSADC_INT_pad6_int_latchset0status_shift                          (0)
#define  LSADC_LSADC_INT_pad6_adc_value6latch_mask                               (0x00003F00)
#define  LSADC_LSADC_INT_pad6_int_latchset5status_mask                           (0x00000020)
#define  LSADC_LSADC_INT_pad6_int_latchset4status_mask                           (0x00000010)
#define  LSADC_LSADC_INT_pad6_int_latchset3status_mask                           (0x00000008)
#define  LSADC_LSADC_INT_pad6_int_latchset2status_mask                           (0x00000004)
#define  LSADC_LSADC_INT_pad6_int_latchset1status_mask                           (0x00000002)
#define  LSADC_LSADC_INT_pad6_int_latchset0status_mask                           (0x00000001)
#define  LSADC_LSADC_INT_pad6_adc_value6latch(data)                              (0x00003F00&((data)<<8))
#define  LSADC_LSADC_INT_pad6_int_latchset5status(data)                          (0x00000020&((data)<<5))
#define  LSADC_LSADC_INT_pad6_int_latchset4status(data)                          (0x00000010&((data)<<4))
#define  LSADC_LSADC_INT_pad6_int_latchset3status(data)                          (0x00000008&((data)<<3))
#define  LSADC_LSADC_INT_pad6_int_latchset2status(data)                          (0x00000004&((data)<<2))
#define  LSADC_LSADC_INT_pad6_int_latchset1status(data)                          (0x00000002&((data)<<1))
#define  LSADC_LSADC_INT_pad6_int_latchset0status(data)                          (0x00000001&(data))
#define  LSADC_LSADC_INT_pad6_get_adc_value6latch(data)                          ((0x00003F00&(data))>>8)
#define  LSADC_LSADC_INT_pad6_get_int_latchset5status(data)                      ((0x00000020&(data))>>5)
#define  LSADC_LSADC_INT_pad6_get_int_latchset4status(data)                      ((0x00000010&(data))>>4)
#define  LSADC_LSADC_INT_pad6_get_int_latchset3status(data)                      ((0x00000008&(data))>>3)
#define  LSADC_LSADC_INT_pad6_get_int_latchset2status(data)                      ((0x00000004&(data))>>2)
#define  LSADC_LSADC_INT_pad6_get_int_latchset1status(data)                      ((0x00000002&(data))>>1)
#define  LSADC_LSADC_INT_pad6_get_int_latchset0status(data)                      (0x00000001&(data))

#define  LSADC_LSADC_INT_pad7                                                    0x18061580
#define  LSADC_LSADC_INT_pad7_reg_addr                                           "0xB8061580"
#define  LSADC_LSADC_INT_pad7_reg                                                0xB8061580
#define  LSADC_LSADC_INT_pad7_inst_addr                                          "0x0020"
#define  set_LSADC_LSADC_INT_pad7_reg(data)                                      (*((volatile unsigned int*)LSADC_LSADC_INT_pad7_reg)=data)
#define  get_LSADC_LSADC_INT_pad7_reg                                            (*((volatile unsigned int*)LSADC_LSADC_INT_pad7_reg))
#define  LSADC_LSADC_INT_pad7_adc_value7latch_shift                              (8)
#define  LSADC_LSADC_INT_pad7_int_latchset5status_shift                          (5)
#define  LSADC_LSADC_INT_pad7_int_latchset4status_shift                          (4)
#define  LSADC_LSADC_INT_pad7_int_latchset3status_shift                          (3)
#define  LSADC_LSADC_INT_pad7_int_latchset2status_shift                          (2)
#define  LSADC_LSADC_INT_pad7_int_latchset1status_shift                          (1)
#define  LSADC_LSADC_INT_pad7_int_latchset0status_shift                          (0)
#define  LSADC_LSADC_INT_pad7_adc_value7latch_mask                               (0x00003F00)
#define  LSADC_LSADC_INT_pad7_int_latchset5status_mask                           (0x00000020)
#define  LSADC_LSADC_INT_pad7_int_latchset4status_mask                           (0x00000010)
#define  LSADC_LSADC_INT_pad7_int_latchset3status_mask                           (0x00000008)
#define  LSADC_LSADC_INT_pad7_int_latchset2status_mask                           (0x00000004)
#define  LSADC_LSADC_INT_pad7_int_latchset1status_mask                           (0x00000002)
#define  LSADC_LSADC_INT_pad7_int_latchset0status_mask                           (0x00000001)
#define  LSADC_LSADC_INT_pad7_adc_value7latch(data)                              (0x00003F00&((data)<<8))
#define  LSADC_LSADC_INT_pad7_int_latchset5status(data)                          (0x00000020&((data)<<5))
#define  LSADC_LSADC_INT_pad7_int_latchset4status(data)                          (0x00000010&((data)<<4))
#define  LSADC_LSADC_INT_pad7_int_latchset3status(data)                          (0x00000008&((data)<<3))
#define  LSADC_LSADC_INT_pad7_int_latchset2status(data)                          (0x00000004&((data)<<2))
#define  LSADC_LSADC_INT_pad7_int_latchset1status(data)                          (0x00000002&((data)<<1))
#define  LSADC_LSADC_INT_pad7_int_latchset0status(data)                          (0x00000001&(data))
#define  LSADC_LSADC_INT_pad7_get_adc_value7latch(data)                          ((0x00003F00&(data))>>8)
#define  LSADC_LSADC_INT_pad7_get_int_latchset5status(data)                      ((0x00000020&(data))>>5)
#define  LSADC_LSADC_INT_pad7_get_int_latchset4status(data)                      ((0x00000010&(data))>>4)
#define  LSADC_LSADC_INT_pad7_get_int_latchset3status(data)                      ((0x00000008&(data))>>3)
#define  LSADC_LSADC_INT_pad7_get_int_latchset2status(data)                      ((0x00000004&(data))>>2)
#define  LSADC_LSADC_INT_pad7_get_int_latchset1status(data)                      ((0x00000002&(data))>>1)
#define  LSADC_LSADC_INT_pad7_get_int_latchset0status(data)                      (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LSADC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad0_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad0_thred:8;
        RBus_UInt32  pad0_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad0_ctrl:1;
        RBus_UInt32  adc_val0:8;
    };
}lsadc_st_pad0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad1_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad1_thred:8;
        RBus_UInt32  pad1_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad1_ctrl:1;
        RBus_UInt32  adc_val1:8;
    };
}lsadc_st_pad1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad2_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad2_thred:8;
        RBus_UInt32  pad2_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad2_ctrl:1;
        RBus_UInt32  adc_val2:8;
    };
}lsadc_st_pad2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad3_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad3_thred:8;
        RBus_UInt32  pad3_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad3_ctrl:1;
        RBus_UInt32  adc_val3:8;
    };
}lsadc_st_pad3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad4_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad4_thred:8;
        RBus_UInt32  pad4_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad4_ctrl:1;
        RBus_UInt32  adc_val4:8;
    };
}lsadc_st_pad4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad5_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad5_thred:8;
        RBus_UInt32  pad5_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad5_ctrl:1;
        RBus_UInt32  adc_val5:8;
    };
}lsadc_st_pad5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad6_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad6_thred:8;
        RBus_UInt32  pad6_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad6_ctrl:1;
        RBus_UInt32  adc_val6:8;
    };
}lsadc_st_pad6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad7_active:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pad7_thred:8;
        RBus_UInt32  pad7_sw:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  pad7_ctrl:1;
        RBus_UInt32  adc_val7:8;
    };
}lsadc_st_pad7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_wait:4;
        RBus_UInt32  sel_adc_ck:4;
        RBus_UInt32  debounce_cnt:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  dout_test_in:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  test_en:1;
        RBus_UInt32  enable:1;
    };
}lsadc_st_lsadc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irq_en:8;
        RBus_UInt32  pad_cnt:4;
        RBus_UInt32  adc_busy:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pad_ctrl:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  pad7_status:1;
        RBus_UInt32  pad6_status:1;
        RBus_UInt32  pad5_status:1;
        RBus_UInt32  pad4_status:1;
        RBus_UInt32  pad3_status:1;
        RBus_UInt32  pad2_status:1;
        RBus_UInt32  pad1_status:1;
        RBus_UInt32  pad0_status:1;
    };
}lsadc_st_lsadc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  jd_sbias:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  jd_adsbias:2;
        RBus_UInt32  jd_dummy:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  jd_svr:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  jd_adcksel:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  jd_power:1;
    };
}lsadc_st_lsadc_analog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  lsadc_2_ifd_data_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  peri_top_debug:8;
    };
}lsadc_st_lsadc_peri_top_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_0_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  int_pending_bit0:1;
    };
}lsadc_lsadc_pad5_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_1_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  int_pending_bit1:1;
    };
}lsadc_lsadc_pad5_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_2_top_bound:8;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  int_pending_bit2:1;
    };
}lsadc_lsadc_pad5_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_3_top_bound:8;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  int_pending_bit3:1;
    };
}lsadc_lsadc_pad5_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_4_top_bound:8;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  int_pending_bit4:1;
    };
}lsadc_lsadc_pad5_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_5_top_bound:8;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  int_pending_bit5:1;
    };
}lsadc_lsadc_pad5_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_0_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  int_pending_bit0:1;
    };
}lsadc_lsadc_pad6_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_1_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  int_pending_bit1:1;
    };
}lsadc_lsadc_pad6_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_2_top_bound:8;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  int_pending_bit2:1;
    };
}lsadc_lsadc_pad6_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_3_top_bound:8;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  int_pending_bit3:1;
    };
}lsadc_lsadc_pad6_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_4_top_bound:8;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  int_pending_bit4:1;
    };
}lsadc_lsadc_pad6_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_5_top_bound:8;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  int_pending_bit5:1;
    };
}lsadc_lsadc_pad6_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_0_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  int_pending_bit0:1;
    };
}lsadc_lsadc_pad7_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_1_top_bound:8;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  int_pending_bit1:1;
    };
}lsadc_lsadc_pad7_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_2_top_bound:8;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  int_pending_bit2:1;
    };
}lsadc_lsadc_pad7_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_3_top_bound:8;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  int_pending_bit3:1;
    };
}lsadc_lsadc_pad7_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_4_top_bound:8;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  int_pending_bit4:1;
    };
}lsadc_lsadc_pad7_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_5_top_bound:8;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  int_pending_bit5:1;
    };
}lsadc_lsadc_pad7_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_value5latch:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  int_latchset5status:1;
        RBus_UInt32  int_latchset4status:1;
        RBus_UInt32  int_latchset3status:1;
        RBus_UInt32  int_latchset2status:1;
        RBus_UInt32  int_latchset1status:1;
        RBus_UInt32  int_latchset0status:1;
    };
}lsadc_lsadc_int_pad5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_value6latch:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  int_latchset5status:1;
        RBus_UInt32  int_latchset4status:1;
        RBus_UInt32  int_latchset3status:1;
        RBus_UInt32  int_latchset2status:1;
        RBus_UInt32  int_latchset1status:1;
        RBus_UInt32  int_latchset0status:1;
    };
}lsadc_lsadc_int_pad6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_value7latch:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  int_latchset5status:1;
        RBus_UInt32  int_latchset4status:1;
        RBus_UInt32  int_latchset3status:1;
        RBus_UInt32  int_latchset2status:1;
        RBus_UInt32  int_latchset1status:1;
        RBus_UInt32  int_latchset0status:1;
    };
}lsadc_lsadc_int_pad7_RBUS;

#else //apply LITTLE_ENDIAN

//======LSADC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val0:8;
        RBus_UInt32  pad0_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad0_sw:4;
        RBus_UInt32  pad0_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad0_active:1;
    };
}lsadc_st_pad0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val1:8;
        RBus_UInt32  pad1_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad1_sw:4;
        RBus_UInt32  pad1_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad1_active:1;
    };
}lsadc_st_pad1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val2:8;
        RBus_UInt32  pad2_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad2_sw:4;
        RBus_UInt32  pad2_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad2_active:1;
    };
}lsadc_st_pad2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val3:8;
        RBus_UInt32  pad3_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad3_sw:4;
        RBus_UInt32  pad3_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad3_active:1;
    };
}lsadc_st_pad3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val4:8;
        RBus_UInt32  pad4_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad4_sw:4;
        RBus_UInt32  pad4_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad4_active:1;
    };
}lsadc_st_pad4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val5:8;
        RBus_UInt32  pad5_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad5_sw:4;
        RBus_UInt32  pad5_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad5_active:1;
    };
}lsadc_st_pad5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val6:8;
        RBus_UInt32  pad6_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad6_sw:4;
        RBus_UInt32  pad6_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad6_active:1;
    };
}lsadc_st_pad6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_val7:8;
        RBus_UInt32  pad7_ctrl:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pad7_sw:4;
        RBus_UInt32  pad7_thred:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  pad7_active:1;
    };
}lsadc_st_pad7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  test_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  dout_test_in:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  debounce_cnt:4;
        RBus_UInt32  sel_adc_ck:4;
        RBus_UInt32  sel_wait:4;
    };
}lsadc_st_lsadc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pad0_status:1;
        RBus_UInt32  pad1_status:1;
        RBus_UInt32  pad2_status:1;
        RBus_UInt32  pad3_status:1;
        RBus_UInt32  pad4_status:1;
        RBus_UInt32  pad5_status:1;
        RBus_UInt32  pad6_status:1;
        RBus_UInt32  pad7_status:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  pad_ctrl:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_busy:1;
        RBus_UInt32  pad_cnt:4;
        RBus_UInt32  irq_en:8;
    };
}lsadc_st_lsadc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  jd_power:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  jd_adcksel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  jd_svr:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  jd_dummy:2;
        RBus_UInt32  jd_adsbias:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  jd_sbias:2;
        RBus_UInt32  res5:14;
    };
}lsadc_st_lsadc_analog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peri_top_debug:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  lsadc_2_ifd_data_sel:3;
        RBus_UInt32  res3:13;
    };
}lsadc_st_lsadc_peri_top_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit0:1;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_0_top_bound:8;
    };
}lsadc_lsadc_pad5_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit1:1;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_1_top_bound:8;
    };
}lsadc_lsadc_pad5_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit2:1;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  level_2_top_bound:8;
    };
}lsadc_lsadc_pad5_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit3:1;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  level_3_top_bound:8;
    };
}lsadc_lsadc_pad5_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit4:1;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  level_4_top_bound:8;
    };
}lsadc_lsadc_pad5_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit5:1;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  level_5_top_bound:8;
    };
}lsadc_lsadc_pad5_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit0:1;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_0_top_bound:8;
    };
}lsadc_lsadc_pad6_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit1:1;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_1_top_bound:8;
    };
}lsadc_lsadc_pad6_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit2:1;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  level_2_top_bound:8;
    };
}lsadc_lsadc_pad6_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit3:1;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  level_3_top_bound:8;
    };
}lsadc_lsadc_pad6_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit4:1;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  level_4_top_bound:8;
    };
}lsadc_lsadc_pad6_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit5:1;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  level_5_top_bound:8;
    };
}lsadc_lsadc_pad6_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit0:1;
        RBus_UInt32  int_en0:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block0_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_0_top_bound:8;
    };
}lsadc_lsadc_pad7_level_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit1:1;
        RBus_UInt32  int_en1:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block1_en:1;
        RBus_UInt32  level_0_low_bound:8;
        RBus_UInt32  level_1_top_bound:8;
    };
}lsadc_lsadc_pad7_level_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit2:1;
        RBus_UInt32  int_en2:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block2_en:1;
        RBus_UInt32  level_2_low_bound:8;
        RBus_UInt32  level_2_top_bound:8;
    };
}lsadc_lsadc_pad7_level_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit3:1;
        RBus_UInt32  int_en3:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block3_en:1;
        RBus_UInt32  level_3_low_bound:8;
        RBus_UInt32  level_3_top_bound:8;
    };
}lsadc_lsadc_pad7_level_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit4:1;
        RBus_UInt32  int_en4:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block4_en:1;
        RBus_UInt32  level_4_low_bound:8;
        RBus_UInt32  level_4_top_bound:8;
    };
}lsadc_lsadc_pad7_level_set4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_pending_bit5:1;
        RBus_UInt32  int_en5:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  block5_en:1;
        RBus_UInt32  level_5_low_bound:8;
        RBus_UInt32  level_5_top_bound:8;
    };
}lsadc_lsadc_pad7_level_set5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_latchset0status:1;
        RBus_UInt32  int_latchset1status:1;
        RBus_UInt32  int_latchset2status:1;
        RBus_UInt32  int_latchset3status:1;
        RBus_UInt32  int_latchset4status:1;
        RBus_UInt32  int_latchset5status:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  adc_value5latch:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:16;
    };
}lsadc_lsadc_int_pad5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_latchset0status:1;
        RBus_UInt32  int_latchset1status:1;
        RBus_UInt32  int_latchset2status:1;
        RBus_UInt32  int_latchset3status:1;
        RBus_UInt32  int_latchset4status:1;
        RBus_UInt32  int_latchset5status:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  adc_value6latch:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:16;
    };
}lsadc_lsadc_int_pad6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_latchset0status:1;
        RBus_UInt32  int_latchset1status:1;
        RBus_UInt32  int_latchset2status:1;
        RBus_UInt32  int_latchset3status:1;
        RBus_UInt32  int_latchset4status:1;
        RBus_UInt32  int_latchset5status:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  adc_value7latch:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:16;
    };
}lsadc_lsadc_int_pad7_RBUS;




#endif 


#endif 
