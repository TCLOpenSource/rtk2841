/**
* @file rbusVmbReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VMB_REG_H_
#define _RBUS_VMB_REG_H_

#include "rbusTypes.h"



//  VMB Register Address
#define  VMB_DMAREG1B_0                                                          0x1800EF00
#define  VMB_DMAREG1B_0_reg_addr                                                 "0xB800EF00"
#define  VMB_DMAREG1B_0_reg                                                      0xB800EF00
#define  VMB_DMAREG1B_0_inst_addr                                                "0x0000"
#define  VMB_DMAREG1B_0_inst_adr                                                 "0x00C0"
#define  VMB_DMAREG1B_0_inst                                                     0x00C0
#define  set_VMB_DMAREG1B_0_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG1B_0_reg)=data)
#define  get_VMB_DMAREG1B_0_reg                                                  (*((volatile unsigned int*)VMB_DMAREG1B_0_reg))
#define  VMB_DMAREG1B_x_shift                                                    (14)
#define  VMB_DMAREG1B_y_shift                                                    (0)
#define  VMB_DMAREG1B_x_mask                                                     (0x07FFC000)
#define  VMB_DMAREG1B_y_mask                                                     (0x00003FFF)
#define  VMB_DMAREG1B_x(data)                                                    (0x07FFC000&((data)<<14))
#define  VMB_DMAREG1B_y(data)                                                    (0x00003FFF&(data))
#define  VMB_DMAREG1B_get_x(data)                                                ((0x07FFC000&(data))>>14)
#define  VMB_DMAREG1B_get_y(data)                                                (0x00003FFF&(data))
#define  VMB_DMAREG1B_x_src(data)                                                ((0x07FFC000&(data))>>14)
#define  VMB_DMAREG1B_y_src(data)                                                (0x00003FFF&(data))

#define  VMB_DMAREG1B_1                                                          0x1800EF04
#define  VMB_DMAREG1B_1_reg_addr                                                 "0xB800EF04"
#define  VMB_DMAREG1B_1_reg                                                      0xB800EF04
#define  VMB_DMAREG1B_1_inst_addr                                                "0x0001"
#define  VMB_DMAREG1B_1_inst_adr                                                 "0x00C1"
#define  VMB_DMAREG1B_1_inst                                                     0x00C1
#define  set_VMB_DMAREG1B_1_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG1B_1_reg)=data)
#define  get_VMB_DMAREG1B_1_reg                                                  (*((volatile unsigned int*)VMB_DMAREG1B_1_reg))

#define  VMB_DMAREG1B_2                                                          0x1800EF08
#define  VMB_DMAREG1B_2_reg_addr                                                 "0xB800EF08"
#define  VMB_DMAREG1B_2_reg                                                      0xB800EF08
#define  VMB_DMAREG1B_2_inst_addr                                                "0x0002"
#define  VMB_DMAREG1B_2_inst_adr                                                 "0x00C2"
#define  VMB_DMAREG1B_2_inst                                                     0x00C2
#define  set_VMB_DMAREG1B_2_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG1B_2_reg)=data)
#define  get_VMB_DMAREG1B_2_reg                                                  (*((volatile unsigned int*)VMB_DMAREG1B_2_reg))

#define  VMB_DMAREG1B_3                                                          0x1800EF0C
#define  VMB_DMAREG1B_3_reg_addr                                                 "0xB800EF0C"
#define  VMB_DMAREG1B_3_reg                                                      0xB800EF0C
#define  VMB_DMAREG1B_3_inst_addr                                                "0x0003"
#define  VMB_DMAREG1B_3_inst_adr                                                 "0x00C3"
#define  VMB_DMAREG1B_3_inst                                                     0x00C3
#define  set_VMB_DMAREG1B_3_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG1B_3_reg)=data)
#define  get_VMB_DMAREG1B_3_reg                                                  (*((volatile unsigned int*)VMB_DMAREG1B_3_reg))

#define  VMB_DMAREG1B_4                                                          0x1800EF10
#define  VMB_DMAREG1B_4_reg_addr                                                 "0xB800EF10"
#define  VMB_DMAREG1B_4_reg                                                      0xB800EF10
#define  VMB_DMAREG1B_4_inst_addr                                                "0x0004"
#define  VMB_DMAREG1B_4_inst_adr                                                 "0x00C4"
#define  VMB_DMAREG1B_4_inst                                                     0x00C4
#define  set_VMB_DMAREG1B_4_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG1B_4_reg)=data)
#define  get_VMB_DMAREG1B_4_reg                                                  (*((volatile unsigned int*)VMB_DMAREG1B_4_reg))

#define  VMB_DMAREG1B_5                                                          0x1800EF14
#define  VMB_DMAREG1B_5_reg_addr                                                 "0xB800EF14"
#define  VMB_DMAREG1B_5_reg                                                      0xB800EF14
#define  VMB_DMAREG1B_5_inst_addr                                                "0x0005"
#define  VMB_DMAREG1B_5_inst_adr                                                 "0x00C5"
#define  VMB_DMAREG1B_5_inst                                                     0x00C5
#define  set_VMB_DMAREG1B_5_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG1B_5_reg)=data)
#define  get_VMB_DMAREG1B_5_reg                                                  (*((volatile unsigned int*)VMB_DMAREG1B_5_reg))

#define  VMB_DMAREG1B_6                                                          0x1800EF18
#define  VMB_DMAREG1B_6_reg_addr                                                 "0xB800EF18"
#define  VMB_DMAREG1B_6_reg                                                      0xB800EF18
#define  VMB_DMAREG1B_6_inst_addr                                                "0x0006"
#define  VMB_DMAREG1B_6_inst_adr                                                 "0x00C6"
#define  VMB_DMAREG1B_6_inst                                                     0x00C6
#define  set_VMB_DMAREG1B_6_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG1B_6_reg)=data)
#define  get_VMB_DMAREG1B_6_reg                                                  (*((volatile unsigned int*)VMB_DMAREG1B_6_reg))

#define  VMB_DMAREG1B_7                                                          0x1800EF1C
#define  VMB_DMAREG1B_7_reg_addr                                                 "0xB800EF1C"
#define  VMB_DMAREG1B_7_reg                                                      0xB800EF1C
#define  VMB_DMAREG1B_7_inst_addr                                                "0x0007"
#define  VMB_DMAREG1B_7_inst_adr                                                 "0x00C7"
#define  VMB_DMAREG1B_7_inst                                                     0x00C7
#define  set_VMB_DMAREG1B_7_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG1B_7_reg)=data)
#define  get_VMB_DMAREG1B_7_reg                                                  (*((volatile unsigned int*)VMB_DMAREG1B_7_reg))

#define  VMB_DMAREG2B_0                                                          0x1800EF20
#define  VMB_DMAREG2B_0_reg_addr                                                 "0xB800EF20"
#define  VMB_DMAREG2B_0_reg                                                      0xB800EF20
#define  VMB_DMAREG2B_0_inst_addr                                                "0x0008"
#define  VMB_DMAREG2B_0_inst_adr                                                 "0x00C8"
#define  VMB_DMAREG2B_0_inst                                                     0x00C8
#define  set_VMB_DMAREG2B_0_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG2B_0_reg)=data)
#define  get_VMB_DMAREG2B_0_reg                                                  (*((volatile unsigned int*)VMB_DMAREG2B_0_reg))
#define  VMB_DMAREG2B_cbcr_vmOffset_shift                                        (23)
#define  VMB_DMAREG2B_mode_shift                                                 (22)
#define  VMB_DMAREG2B_right_offset_shift                                         (19)
#define  VMB_DMAREG2B_left_offset_shift                                          (16)
#define  VMB_DMAREG2B_addr_idx_shift                                             (8)
#define  VMB_DMAREG2B_post_inc_sel_shift                                         (7)
#define  VMB_DMAREG2B_post_inc_shift                                             (0)
#define  VMB_DMAREG2B_cbcr_vmOffset_mask                                         (0x3F800000)
#define  VMB_DMAREG2B_mode_mask                                                  (0x00400000)
#define  VMB_DMAREG2B_right_offset_mask                                          (0x00380000)
#define  VMB_DMAREG2B_left_offset_mask                                           (0x00070000)
#define  VMB_DMAREG2B_addr_idx_mask                                              (0x00007F00)
#define  VMB_DMAREG2B_post_inc_sel_mask                                          (0x00000080)
#define  VMB_DMAREG2B_post_inc_mask                                              (0x0000003F)
#define  VMB_DMAREG2B_cbcr_vmOffset(data)                                        (0x3F800000&((data)<<23))
#define  VMB_DMAREG2B_mode(data)                                                 (0x00400000&((data)<<22))
#define  VMB_DMAREG2B_right_offset(data)                                         (0x00380000&((data)<<19))
#define  VMB_DMAREG2B_left_offset(data)                                          (0x00070000&((data)<<16))
#define  VMB_DMAREG2B_addr_idx(data)                                             (0x00007F00&((data)<<8))
#define  VMB_DMAREG2B_post_inc_sel(data)                                         (0x00000080&((data)<<7))
#define  VMB_DMAREG2B_post_inc(data)                                             (0x0000003F&(data))
#define  VMB_DMAREG2B_get_cbcr_vmOffset(data)                                    ((0x3F800000&(data))>>23)
#define  VMB_DMAREG2B_get_mode(data)                                             ((0x00400000&(data))>>22)
#define  VMB_DMAREG2B_get_right_offset(data)                                     ((0x00380000&(data))>>19)
#define  VMB_DMAREG2B_get_left_offset(data)                                      ((0x00070000&(data))>>16)
#define  VMB_DMAREG2B_get_addr_idx(data)                                         ((0x00007F00&(data))>>8)
#define  VMB_DMAREG2B_get_post_inc_sel(data)                                     ((0x00000080&(data))>>7)
#define  VMB_DMAREG2B_get_post_inc(data)                                         (0x0000003F&(data))
#define  VMB_DMAREG2B_cbcr_vmOffset_src(data)                                    ((0x3F800000&(data))>>23)
#define  VMB_DMAREG2B_mode_src(data)                                             ((0x00400000&(data))>>22)
#define  VMB_DMAREG2B_right_offset_src(data)                                     ((0x00380000&(data))>>19)
#define  VMB_DMAREG2B_left_offset_src(data)                                      ((0x00070000&(data))>>16)
#define  VMB_DMAREG2B_addr_idx_src(data)                                         ((0x00007F00&(data))>>8)
#define  VMB_DMAREG2B_post_inc_sel_src(data)                                     ((0x00000080&(data))>>7)
#define  VMB_DMAREG2B_post_inc_src(data)                                         (0x0000003F&(data))

#define  VMB_DMAREG2B_1                                                          0x1800EF24
#define  VMB_DMAREG2B_1_reg_addr                                                 "0xB800EF24"
#define  VMB_DMAREG2B_1_reg                                                      0xB800EF24
#define  VMB_DMAREG2B_1_inst_addr                                                "0x0009"
#define  VMB_DMAREG2B_1_inst_adr                                                 "0x00C9"
#define  VMB_DMAREG2B_1_inst                                                     0x00C9
#define  set_VMB_DMAREG2B_1_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG2B_1_reg)=data)
#define  get_VMB_DMAREG2B_1_reg                                                  (*((volatile unsigned int*)VMB_DMAREG2B_1_reg))

#define  VMB_DMAREG2B_2                                                          0x1800EF28
#define  VMB_DMAREG2B_2_reg_addr                                                 "0xB800EF28"
#define  VMB_DMAREG2B_2_reg                                                      0xB800EF28
#define  VMB_DMAREG2B_2_inst_addr                                                "0x000A"
#define  VMB_DMAREG2B_2_inst_adr                                                 "0x00CA"
#define  VMB_DMAREG2B_2_inst                                                     0x00CA
#define  set_VMB_DMAREG2B_2_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG2B_2_reg)=data)
#define  get_VMB_DMAREG2B_2_reg                                                  (*((volatile unsigned int*)VMB_DMAREG2B_2_reg))

#define  VMB_DMAREG2B_3                                                          0x1800EF2C
#define  VMB_DMAREG2B_3_reg_addr                                                 "0xB800EF2C"
#define  VMB_DMAREG2B_3_reg                                                      0xB800EF2C
#define  VMB_DMAREG2B_3_inst_addr                                                "0x000B"
#define  VMB_DMAREG2B_3_inst_adr                                                 "0x00CB"
#define  VMB_DMAREG2B_3_inst                                                     0x00CB
#define  set_VMB_DMAREG2B_3_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG2B_3_reg)=data)
#define  get_VMB_DMAREG2B_3_reg                                                  (*((volatile unsigned int*)VMB_DMAREG2B_3_reg))

#define  VMB_DMAREG2B_4                                                          0x1800EF30
#define  VMB_DMAREG2B_4_reg_addr                                                 "0xB800EF30"
#define  VMB_DMAREG2B_4_reg                                                      0xB800EF30
#define  VMB_DMAREG2B_4_inst_addr                                                "0x000C"
#define  VMB_DMAREG2B_4_inst_adr                                                 "0x00CC"
#define  VMB_DMAREG2B_4_inst                                                     0x00CC
#define  set_VMB_DMAREG2B_4_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG2B_4_reg)=data)
#define  get_VMB_DMAREG2B_4_reg                                                  (*((volatile unsigned int*)VMB_DMAREG2B_4_reg))

#define  VMB_DMAREG2B_5                                                          0x1800EF34
#define  VMB_DMAREG2B_5_reg_addr                                                 "0xB800EF34"
#define  VMB_DMAREG2B_5_reg                                                      0xB800EF34
#define  VMB_DMAREG2B_5_inst_addr                                                "0x000D"
#define  VMB_DMAREG2B_5_inst_adr                                                 "0x00CD"
#define  VMB_DMAREG2B_5_inst                                                     0x00CD
#define  set_VMB_DMAREG2B_5_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG2B_5_reg)=data)
#define  get_VMB_DMAREG2B_5_reg                                                  (*((volatile unsigned int*)VMB_DMAREG2B_5_reg))

#define  VMB_DMAREG2B_6                                                          0x1800EF38
#define  VMB_DMAREG2B_6_reg_addr                                                 "0xB800EF38"
#define  VMB_DMAREG2B_6_reg                                                      0xB800EF38
#define  VMB_DMAREG2B_6_inst_addr                                                "0x000E"
#define  VMB_DMAREG2B_6_inst_adr                                                 "0x00CE"
#define  VMB_DMAREG2B_6_inst                                                     0x00CE
#define  set_VMB_DMAREG2B_6_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG2B_6_reg)=data)
#define  get_VMB_DMAREG2B_6_reg                                                  (*((volatile unsigned int*)VMB_DMAREG2B_6_reg))

#define  VMB_DMAREG2B_7                                                          0x1800EF3C
#define  VMB_DMAREG2B_7_reg_addr                                                 "0xB800EF3C"
#define  VMB_DMAREG2B_7_reg                                                      0xB800EF3C
#define  VMB_DMAREG2B_7_inst_addr                                                "0x000F"
#define  VMB_DMAREG2B_7_inst_adr                                                 "0x00CF"
#define  VMB_DMAREG2B_7_inst                                                     0x00CF
#define  set_VMB_DMAREG2B_7_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG2B_7_reg)=data)
#define  get_VMB_DMAREG2B_7_reg                                                  (*((volatile unsigned int*)VMB_DMAREG2B_7_reg))

#define  VMB_DMAREG3B_0                                                          0x1800EF40
#define  VMB_DMAREG3B_0_reg_addr                                                 "0xB800EF40"
#define  VMB_DMAREG3B_0_reg                                                      0xB800EF40
#define  VMB_DMAREG3B_0_inst_addr                                                "0x0010"
#define  VMB_DMAREG3B_0_inst_adr                                                 "0x00D0"
#define  VMB_DMAREG3B_0_inst                                                     0x00D0
#define  set_VMB_DMAREG3B_0_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG3B_0_reg)=data)
#define  get_VMB_DMAREG3B_0_reg                                                  (*((volatile unsigned int*)VMB_DMAREG3B_0_reg))
#define  VMB_DMAREG3B_line_off_shift                                             (28)
#define  VMB_DMAREG3B_vmRowOffset_shift                                          (22)
#define  VMB_DMAREG3B_vm_addr_shift                                              (12)
#define  VMB_DMAREG3B_H_shift                                                    (6)
#define  VMB_DMAREG3B_W_shift                                                    (0)
#define  VMB_DMAREG3B_line_off_mask                                              (0x10000000)
#define  VMB_DMAREG3B_vmRowOffset_mask                                           (0x07C00000)
#define  VMB_DMAREG3B_vm_addr_mask                                               (0x0007F000)
#define  VMB_DMAREG3B_H_mask                                                     (0x00000FC0)
#define  VMB_DMAREG3B_W_mask                                                     (0x0000003F)
#define  VMB_DMAREG3B_line_off(data)                                             (0x10000000&((data)<<28))
#define  VMB_DMAREG3B_vmRowOffset(data)                                          (0x07C00000&((data)<<22))
#define  VMB_DMAREG3B_vm_addr(data)                                              (0x0007F000&((data)<<12))
#define  VMB_DMAREG3B_H(data)                                                    (0x00000FC0&((data)<<6))
#define  VMB_DMAREG3B_W(data)                                                    (0x0000003F&(data))
#define  VMB_DMAREG3B_get_line_off(data)                                         ((0x10000000&(data))>>28)
#define  VMB_DMAREG3B_get_vmRowOffset(data)                                      ((0x07C00000&(data))>>22)
#define  VMB_DMAREG3B_get_vm_addr(data)                                          ((0x0007F000&(data))>>12)
#define  VMB_DMAREG3B_get_H(data)                                                ((0x00000FC0&(data))>>6)
#define  VMB_DMAREG3B_get_W(data)                                                (0x0000003F&(data))
#define  VMB_DMAREG3B_line_off_src(data)                                         ((0x10000000&(data))>>28)
#define  VMB_DMAREG3B_vmRowOffset_src(data)                                      ((0x07C00000&(data))>>22)
#define  VMB_DMAREG3B_vm_addr_src(data)                                          ((0x0007F000&(data))>>12)
#define  VMB_DMAREG3B_H_src(data)                                                ((0x00000FC0&(data))>>6)
#define  VMB_DMAREG3B_W_src(data)                                                (0x0000003F&(data))

#define  VMB_DMAREG3B_1                                                          0x1800EF44
#define  VMB_DMAREG3B_1_reg_addr                                                 "0xB800EF44"
#define  VMB_DMAREG3B_1_reg                                                      0xB800EF44
#define  VMB_DMAREG3B_1_inst_addr                                                "0x0011"
#define  VMB_DMAREG3B_1_inst_adr                                                 "0x00D1"
#define  VMB_DMAREG3B_1_inst                                                     0x00D1
#define  set_VMB_DMAREG3B_1_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG3B_1_reg)=data)
#define  get_VMB_DMAREG3B_1_reg                                                  (*((volatile unsigned int*)VMB_DMAREG3B_1_reg))

#define  VMB_DMAREG3B_2                                                          0x1800EF48
#define  VMB_DMAREG3B_2_reg_addr                                                 "0xB800EF48"
#define  VMB_DMAREG3B_2_reg                                                      0xB800EF48
#define  VMB_DMAREG3B_2_inst_addr                                                "0x0012"
#define  VMB_DMAREG3B_2_inst_adr                                                 "0x00D2"
#define  VMB_DMAREG3B_2_inst                                                     0x00D2
#define  set_VMB_DMAREG3B_2_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG3B_2_reg)=data)
#define  get_VMB_DMAREG3B_2_reg                                                  (*((volatile unsigned int*)VMB_DMAREG3B_2_reg))

#define  VMB_DMAREG3B_3                                                          0x1800EF4C
#define  VMB_DMAREG3B_3_reg_addr                                                 "0xB800EF4C"
#define  VMB_DMAREG3B_3_reg                                                      0xB800EF4C
#define  VMB_DMAREG3B_3_inst_addr                                                "0x0013"
#define  VMB_DMAREG3B_3_inst_adr                                                 "0x00D3"
#define  VMB_DMAREG3B_3_inst                                                     0x00D3
#define  set_VMB_DMAREG3B_3_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG3B_3_reg)=data)
#define  get_VMB_DMAREG3B_3_reg                                                  (*((volatile unsigned int*)VMB_DMAREG3B_3_reg))

#define  VMB_DMAREG3B_4                                                          0x1800EF50
#define  VMB_DMAREG3B_4_reg_addr                                                 "0xB800EF50"
#define  VMB_DMAREG3B_4_reg                                                      0xB800EF50
#define  VMB_DMAREG3B_4_inst_addr                                                "0x0014"
#define  VMB_DMAREG3B_4_inst_adr                                                 "0x00D4"
#define  VMB_DMAREG3B_4_inst                                                     0x00D4
#define  set_VMB_DMAREG3B_4_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG3B_4_reg)=data)
#define  get_VMB_DMAREG3B_4_reg                                                  (*((volatile unsigned int*)VMB_DMAREG3B_4_reg))

#define  VMB_DMAREG3B_5                                                          0x1800EF54
#define  VMB_DMAREG3B_5_reg_addr                                                 "0xB800EF54"
#define  VMB_DMAREG3B_5_reg                                                      0xB800EF54
#define  VMB_DMAREG3B_5_inst_addr                                                "0x0015"
#define  VMB_DMAREG3B_5_inst_adr                                                 "0x00D5"
#define  VMB_DMAREG3B_5_inst                                                     0x00D5
#define  set_VMB_DMAREG3B_5_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG3B_5_reg)=data)
#define  get_VMB_DMAREG3B_5_reg                                                  (*((volatile unsigned int*)VMB_DMAREG3B_5_reg))

#define  VMB_DMAREG3B_6                                                          0x1800EF58
#define  VMB_DMAREG3B_6_reg_addr                                                 "0xB800EF58"
#define  VMB_DMAREG3B_6_reg                                                      0xB800EF58
#define  VMB_DMAREG3B_6_inst_addr                                                "0x0016"
#define  VMB_DMAREG3B_6_inst_adr                                                 "0x00D6"
#define  VMB_DMAREG3B_6_inst                                                     0x00D6
#define  set_VMB_DMAREG3B_6_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG3B_6_reg)=data)
#define  get_VMB_DMAREG3B_6_reg                                                  (*((volatile unsigned int*)VMB_DMAREG3B_6_reg))

#define  VMB_DMAREG3B_7                                                          0x1800EF5C
#define  VMB_DMAREG3B_7_reg_addr                                                 "0xB800EF5C"
#define  VMB_DMAREG3B_7_reg                                                      0xB800EF5C
#define  VMB_DMAREG3B_7_inst_addr                                                "0x0017"
#define  VMB_DMAREG3B_7_inst_adr                                                 "0x00D7"
#define  VMB_DMAREG3B_7_inst                                                     0x00D7
#define  set_VMB_DMAREG3B_7_reg(data)                                            (*((volatile unsigned int*)VMB_DMAREG3B_7_reg)=data)
#define  get_VMB_DMAREG3B_7_reg                                                  (*((volatile unsigned int*)VMB_DMAREG3B_7_reg))

#define  VMB_SDMACNTLB                                                           0x1800EF60
#define  VMB_SDMACNTLB_reg_addr                                                  "0xB800EF60"
#define  VMB_SDMACNTLB_reg                                                       0xB800EF60
#define  VMB_SDMACNTLB_inst_addr                                                 "0x0018"
#define  VMB_SDMACNTLB_inst_adr                                                  "0x00D8"
#define  VMB_SDMACNTLB_inst                                                      0x00D8
#define  set_VMB_SDMACNTLB_reg(data)                                             (*((volatile unsigned int*)VMB_SDMACNTLB_reg)=data)
#define  get_VMB_SDMACNTLB_reg                                                   (*((volatile unsigned int*)VMB_SDMACNTLB_reg))
#define  VMB_SDMACNTLB_Seq_VMEM_addr_shift                                       (16)
#define  VMB_SDMACNTLB_Seq_xsfr_size_shift                                       (0)
#define  VMB_SDMACNTLB_Seq_VMEM_addr_mask                                        (0x1FFF0000)
#define  VMB_SDMACNTLB_Seq_xsfr_size_mask                                        (0x000001FF)
#define  VMB_SDMACNTLB_Seq_VMEM_addr(data)                                       (0x1FFF0000&((data)<<16))
#define  VMB_SDMACNTLB_Seq_xsfr_size(data)                                       (0x000001FF&(data))
#define  VMB_SDMACNTLB_get_Seq_VMEM_addr(data)                                   ((0x1FFF0000&(data))>>16)
#define  VMB_SDMACNTLB_get_Seq_xsfr_size(data)                                   (0x000001FF&(data))
#define  VMB_SDMACNTLB_Seq_VMEM_addr_src(data)                                   ((0x1FFF0000&(data))>>16)
#define  VMB_SDMACNTLB_Seq_xsfr_size_src(data)                                   (0x000001FF&(data))

#define  VMB_SDMAADRB                                                            0x1800EF64
#define  VMB_SDMAADRB_reg_addr                                                   "0xB800EF64"
#define  VMB_SDMAADRB_reg                                                        0xB800EF64
#define  VMB_SDMAADRB_inst_addr                                                  "0x0019"
#define  VMB_SDMAADRB_inst_adr                                                   "0x00D9"
#define  VMB_SDMAADRB_inst                                                       0x00D9
#define  set_VMB_SDMAADRB_reg(data)                                              (*((volatile unsigned int*)VMB_SDMAADRB_reg)=data)
#define  get_VMB_SDMAADRB_reg                                                    (*((volatile unsigned int*)VMB_SDMAADRB_reg))
#define  VMB_SDMAADRB_seq_line_addr_shift                                        (0)
#define  VMB_SDMAADRB_seq_line_addr_mask                                         (0xFFFFFFFF)
#define  VMB_SDMAADRB_seq_line_addr(data)                                        (0xFFFFFFFF&(data))
#define  VMB_SDMAADRB_get_seq_line_addr(data)                                    (0xFFFFFFFF&(data))
#define  VMB_SDMAADRB_seq_line_addr_src(data)                                    (0xFFFFFFFF&(data))

#define  VMB_DMACTLB                                                             0x1800EF68
#define  VMB_DMACTLB_reg_addr                                                    "0xB800EF68"
#define  VMB_DMACTLB_reg                                                         0xB800EF68
#define  VMB_DMACTLB_inst_addr                                                   "0x001A"
#define  VMB_DMACTLB_inst_adr                                                    "0x00DA"
#define  VMB_DMACTLB_inst                                                        0x00DA
#define  set_VMB_DMACTLB_reg(data)                                               (*((volatile unsigned int*)VMB_DMACTLB_reg)=data)
#define  get_VMB_DMACTLB_reg                                                     (*((volatile unsigned int*)VMB_DMACTLB_reg))
#define  VMB_DMACTLB_write_enable1_shift                                         (1)
#define  VMB_DMACTLB_post_write_disable_shift                                    (0)
#define  VMB_DMACTLB_write_enable1_mask                                          (0x00000002)
#define  VMB_DMACTLB_post_write_disable_mask                                     (0x00000001)
#define  VMB_DMACTLB_write_enable1(data)                                         (0x00000002&((data)<<1))
#define  VMB_DMACTLB_post_write_disable(data)                                    (0x00000001&(data))
#define  VMB_DMACTLB_get_write_enable1(data)                                     ((0x00000002&(data))>>1)
#define  VMB_DMACTLB_get_post_write_disable(data)                                (0x00000001&(data))
#define  VMB_DMACTLB_write_enable1_src(data)                                     ((0x00000002&(data))>>1)
#define  VMB_DMACTLB_post_write_disable_src(data)                                (0x00000001&(data))

#ifdef _VMB_USE_STRUCT
#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VMB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  x:13;
        RBus_UInt32  y:14;
    };
}VMB_DMAREG1B_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cbcr_vmOffset:7;
        RBus_UInt32  mode:1;
        RBus_UInt32  right_offset:3;
        RBus_UInt32  left_offset:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  addr_idx:7;
        RBus_UInt32  post_inc_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  post_inc:6;
    };
}VMB_DMAREG2B_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  line_off:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vmRowOffset:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vm_addr:7;
        RBus_UInt32  H:6;
        RBus_UInt32  W:6;
    };
}VMB_DMAREG3B_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  Seq_VMEM_addr:13;
        RBus_UInt32  res2:7;
        RBus_UInt32  Seq_xsfr_size:9;
    };
}VMB_SDMACNTLB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:32;
    };
}VMB_SDMAADRB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  post_write_disable:1;
    };
}VMB_DMACTLB_RBUS;

#else //apply LITTLE_ENDIAN

//======VMB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:14;
        RBus_UInt32  x:13;
        RBus_UInt32  res1:5;
    };
}VMB_DMAREG1B_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  post_inc:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  post_inc_sel:1;
        RBus_UInt32  addr_idx:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  left_offset:3;
        RBus_UInt32  right_offset:3;
        RBus_UInt32  mode:1;
        RBus_UInt32  cbcr_vmOffset:7;
        RBus_UInt32  res3:2;
    };
}VMB_DMAREG2B_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  W:6;
        RBus_UInt32  H:6;
        RBus_UInt32  vm_addr:7;
        RBus_UInt32  res1:3;
        RBus_UInt32  vmRowOffset:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  line_off:1;
        RBus_UInt32  res3:3;
    };
}VMB_DMAREG3B_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Seq_xsfr_size:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  Seq_VMEM_addr:13;
        RBus_UInt32  res2:3;
    };
}VMB_SDMACNTLB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:32;
    };
}VMB_SDMAADRB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  post_write_disable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res1:30;
    };
}VMB_DMACTLB_RBUS;




#endif 


#endif 
#endif 
