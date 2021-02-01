/**
* @file rbusVmaReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/9/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VMA_REG_H_
#define _RBUS_VMA_REG_H_

#include "rbusTypes.h"



//  VMA Register Address
#define  VMA_DMAREG1A_0                                                          0x1800EE00
#define  VMA_DMAREG1A_0_reg_addr                                                 "0xB800EE00"
#define  VMA_DMAREG1A_0_reg                                                      0xB800EE00
#define  VMA_DMAREG1A_0_inst_addr                                                "0x0000"
#define  VMA_DMAREG1A_0_inst_adr                                                 "0x0080"
#define  VMA_DMAREG1A_0_inst                                                     0x0080
#define  set_VMA_DMAREG1A_0_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG1A_0_reg)=data)
#define  get_VMA_DMAREG1A_0_reg                                                  (*((volatile unsigned int*)VMA_DMAREG1A_0_reg))
#define  VMA_DMAREG1A_x_shift                                                    (14)
#define  VMA_DMAREG1A_y_shift                                                    (0)
#define  VMA_DMAREG1A_x_mask                                                     (0x07FFC000)
#define  VMA_DMAREG1A_y_mask                                                     (0x00003FFF)
#define  VMA_DMAREG1A_x(data)                                                    (0x07FFC000&((data)<<14))
#define  VMA_DMAREG1A_y(data)                                                    (0x00003FFF&(data))
#define  VMA_DMAREG1A_get_x(data)                                                ((0x07FFC000&(data))>>14)
#define  VMA_DMAREG1A_get_y(data)                                                (0x00003FFF&(data))
#define  VMA_DMAREG1A_x_src(data)                                                ((0x07FFC000&(data))>>14)
#define  VMA_DMAREG1A_y_src(data)                                                (0x00003FFF&(data))

#define  VMA_DMAREG1A_1                                                          0x1800EE04
#define  VMA_DMAREG1A_1_reg_addr                                                 "0xB800EE04"
#define  VMA_DMAREG1A_1_reg                                                      0xB800EE04
#define  VMA_DMAREG1A_1_inst_addr                                                "0x0001"
#define  VMA_DMAREG1A_1_inst_adr                                                 "0x0081"
#define  VMA_DMAREG1A_1_inst                                                     0x0081
#define  set_VMA_DMAREG1A_1_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG1A_1_reg)=data)
#define  get_VMA_DMAREG1A_1_reg                                                  (*((volatile unsigned int*)VMA_DMAREG1A_1_reg))

#define  VMA_DMAREG1A_2                                                          0x1800EE08
#define  VMA_DMAREG1A_2_reg_addr                                                 "0xB800EE08"
#define  VMA_DMAREG1A_2_reg                                                      0xB800EE08
#define  VMA_DMAREG1A_2_inst_addr                                                "0x0002"
#define  VMA_DMAREG1A_2_inst_adr                                                 "0x0082"
#define  VMA_DMAREG1A_2_inst                                                     0x0082
#define  set_VMA_DMAREG1A_2_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG1A_2_reg)=data)
#define  get_VMA_DMAREG1A_2_reg                                                  (*((volatile unsigned int*)VMA_DMAREG1A_2_reg))

#define  VMA_DMAREG1A_3                                                          0x1800EE0C
#define  VMA_DMAREG1A_3_reg_addr                                                 "0xB800EE0C"
#define  VMA_DMAREG1A_3_reg                                                      0xB800EE0C
#define  VMA_DMAREG1A_3_inst_addr                                                "0x0003"
#define  VMA_DMAREG1A_3_inst_adr                                                 "0x0083"
#define  VMA_DMAREG1A_3_inst                                                     0x0083
#define  set_VMA_DMAREG1A_3_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG1A_3_reg)=data)
#define  get_VMA_DMAREG1A_3_reg                                                  (*((volatile unsigned int*)VMA_DMAREG1A_3_reg))

#define  VMA_DMAREG1A_4                                                          0x1800EE10
#define  VMA_DMAREG1A_4_reg_addr                                                 "0xB800EE10"
#define  VMA_DMAREG1A_4_reg                                                      0xB800EE10
#define  VMA_DMAREG1A_4_inst_addr                                                "0x0004"
#define  VMA_DMAREG1A_4_inst_adr                                                 "0x0084"
#define  VMA_DMAREG1A_4_inst                                                     0x0084
#define  set_VMA_DMAREG1A_4_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG1A_4_reg)=data)
#define  get_VMA_DMAREG1A_4_reg                                                  (*((volatile unsigned int*)VMA_DMAREG1A_4_reg))

#define  VMA_DMAREG1A_5                                                          0x1800EE14
#define  VMA_DMAREG1A_5_reg_addr                                                 "0xB800EE14"
#define  VMA_DMAREG1A_5_reg                                                      0xB800EE14
#define  VMA_DMAREG1A_5_inst_addr                                                "0x0005"
#define  VMA_DMAREG1A_5_inst_adr                                                 "0x0085"
#define  VMA_DMAREG1A_5_inst                                                     0x0085
#define  set_VMA_DMAREG1A_5_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG1A_5_reg)=data)
#define  get_VMA_DMAREG1A_5_reg                                                  (*((volatile unsigned int*)VMA_DMAREG1A_5_reg))

#define  VMA_DMAREG1A_6                                                          0x1800EE18
#define  VMA_DMAREG1A_6_reg_addr                                                 "0xB800EE18"
#define  VMA_DMAREG1A_6_reg                                                      0xB800EE18
#define  VMA_DMAREG1A_6_inst_addr                                                "0x0006"
#define  VMA_DMAREG1A_6_inst_adr                                                 "0x0086"
#define  VMA_DMAREG1A_6_inst                                                     0x0086
#define  set_VMA_DMAREG1A_6_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG1A_6_reg)=data)
#define  get_VMA_DMAREG1A_6_reg                                                  (*((volatile unsigned int*)VMA_DMAREG1A_6_reg))

#define  VMA_DMAREG1A_7                                                          0x1800EE1C
#define  VMA_DMAREG1A_7_reg_addr                                                 "0xB800EE1C"
#define  VMA_DMAREG1A_7_reg                                                      0xB800EE1C
#define  VMA_DMAREG1A_7_inst_addr                                                "0x0007"
#define  VMA_DMAREG1A_7_inst_adr                                                 "0x0087"
#define  VMA_DMAREG1A_7_inst                                                     0x0087
#define  set_VMA_DMAREG1A_7_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG1A_7_reg)=data)
#define  get_VMA_DMAREG1A_7_reg                                                  (*((volatile unsigned int*)VMA_DMAREG1A_7_reg))

#define  VMA_DMAREG2A_0                                                          0x1800EE20
#define  VMA_DMAREG2A_0_reg_addr                                                 "0xB800EE20"
#define  VMA_DMAREG2A_0_reg                                                      0xB800EE20
#define  VMA_DMAREG2A_0_inst_addr                                                "0x0008"
#define  VMA_DMAREG2A_0_inst_adr                                                 "0x0088"
#define  VMA_DMAREG2A_0_inst                                                     0x0088
#define  set_VMA_DMAREG2A_0_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG2A_0_reg)=data)
#define  get_VMA_DMAREG2A_0_reg                                                  (*((volatile unsigned int*)VMA_DMAREG2A_0_reg))
#define  VMA_DMAREG2A_cbcr_vmOffset_shift                                        (23)
#define  VMA_DMAREG2A_mode_shift                                                 (22)
#define  VMA_DMAREG2A_right_offset_shift                                         (19)
#define  VMA_DMAREG2A_left_offset_shift                                          (16)
#define  VMA_DMAREG2A_addr_idx_shift                                             (8)
#define  VMA_DMAREG2A_post_inc_sel_shift                                         (7)
#define  VMA_DMAREG2A_post_inc_shift                                             (0)
#define  VMA_DMAREG2A_cbcr_vmOffset_mask                                         (0x3F800000)
#define  VMA_DMAREG2A_mode_mask                                                  (0x00400000)
#define  VMA_DMAREG2A_right_offset_mask                                          (0x00380000)
#define  VMA_DMAREG2A_left_offset_mask                                           (0x00070000)
#define  VMA_DMAREG2A_addr_idx_mask                                              (0x00007F00)
#define  VMA_DMAREG2A_post_inc_sel_mask                                          (0x00000080)
#define  VMA_DMAREG2A_post_inc_mask                                              (0x0000003F)
#define  VMA_DMAREG2A_cbcr_vmOffset(data)                                        (0x3F800000&((data)<<23))
#define  VMA_DMAREG2A_mode(data)                                                 (0x00400000&((data)<<22))
#define  VMA_DMAREG2A_right_offset(data)                                         (0x00380000&((data)<<19))
#define  VMA_DMAREG2A_left_offset(data)                                          (0x00070000&((data)<<16))
#define  VMA_DMAREG2A_addr_idx(data)                                             (0x00007F00&((data)<<8))
#define  VMA_DMAREG2A_post_inc_sel(data)                                         (0x00000080&((data)<<7))
#define  VMA_DMAREG2A_post_inc(data)                                             (0x0000003F&(data))
#define  VMA_DMAREG2A_get_cbcr_vmOffset(data)                                    ((0x3F800000&(data))>>23)
#define  VMA_DMAREG2A_get_mode(data)                                             ((0x00400000&(data))>>22)
#define  VMA_DMAREG2A_get_right_offset(data)                                     ((0x00380000&(data))>>19)
#define  VMA_DMAREG2A_get_left_offset(data)                                      ((0x00070000&(data))>>16)
#define  VMA_DMAREG2A_get_addr_idx(data)                                         ((0x00007F00&(data))>>8)
#define  VMA_DMAREG2A_get_post_inc_sel(data)                                     ((0x00000080&(data))>>7)
#define  VMA_DMAREG2A_get_post_inc(data)                                         (0x0000003F&(data))
#define  VMA_DMAREG2A_cbcr_vmOffset_src(data)                                    ((0x3F800000&(data))>>23)
#define  VMA_DMAREG2A_mode_src(data)                                             ((0x00400000&(data))>>22)
#define  VMA_DMAREG2A_right_offset_src(data)                                     ((0x00380000&(data))>>19)
#define  VMA_DMAREG2A_left_offset_src(data)                                      ((0x00070000&(data))>>16)
#define  VMA_DMAREG2A_addr_idx_src(data)                                         ((0x00007F00&(data))>>8)
#define  VMA_DMAREG2A_post_inc_sel_src(data)                                     ((0x00000080&(data))>>7)
#define  VMA_DMAREG2A_post_inc_src(data)                                         (0x0000003F&(data))

#define  VMA_DMAREG2A_1                                                          0x1800EE24
#define  VMA_DMAREG2A_1_reg_addr                                                 "0xB800EE24"
#define  VMA_DMAREG2A_1_reg                                                      0xB800EE24
#define  VMA_DMAREG2A_1_inst_addr                                                "0x0009"
#define  VMA_DMAREG2A_1_inst_adr                                                 "0x0089"
#define  VMA_DMAREG2A_1_inst                                                     0x0089
#define  set_VMA_DMAREG2A_1_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG2A_1_reg)=data)
#define  get_VMA_DMAREG2A_1_reg                                                  (*((volatile unsigned int*)VMA_DMAREG2A_1_reg))

#define  VMA_DMAREG2A_2                                                          0x1800EE28
#define  VMA_DMAREG2A_2_reg_addr                                                 "0xB800EE28"
#define  VMA_DMAREG2A_2_reg                                                      0xB800EE28
#define  VMA_DMAREG2A_2_inst_addr                                                "0x000A"
#define  VMA_DMAREG2A_2_inst_adr                                                 "0x008A"
#define  VMA_DMAREG2A_2_inst                                                     0x008A
#define  set_VMA_DMAREG2A_2_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG2A_2_reg)=data)
#define  get_VMA_DMAREG2A_2_reg                                                  (*((volatile unsigned int*)VMA_DMAREG2A_2_reg))

#define  VMA_DMAREG2A_3                                                          0x1800EE2C
#define  VMA_DMAREG2A_3_reg_addr                                                 "0xB800EE2C"
#define  VMA_DMAREG2A_3_reg                                                      0xB800EE2C
#define  VMA_DMAREG2A_3_inst_addr                                                "0x000B"
#define  VMA_DMAREG2A_3_inst_adr                                                 "0x008B"
#define  VMA_DMAREG2A_3_inst                                                     0x008B
#define  set_VMA_DMAREG2A_3_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG2A_3_reg)=data)
#define  get_VMA_DMAREG2A_3_reg                                                  (*((volatile unsigned int*)VMA_DMAREG2A_3_reg))

#define  VMA_DMAREG2A_4                                                          0x1800EE30
#define  VMA_DMAREG2A_4_reg_addr                                                 "0xB800EE30"
#define  VMA_DMAREG2A_4_reg                                                      0xB800EE30
#define  VMA_DMAREG2A_4_inst_addr                                                "0x000C"
#define  VMA_DMAREG2A_4_inst_adr                                                 "0x008C"
#define  VMA_DMAREG2A_4_inst                                                     0x008C
#define  set_VMA_DMAREG2A_4_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG2A_4_reg)=data)
#define  get_VMA_DMAREG2A_4_reg                                                  (*((volatile unsigned int*)VMA_DMAREG2A_4_reg))

#define  VMA_DMAREG2A_5                                                          0x1800EE34
#define  VMA_DMAREG2A_5_reg_addr                                                 "0xB800EE34"
#define  VMA_DMAREG2A_5_reg                                                      0xB800EE34
#define  VMA_DMAREG2A_5_inst_addr                                                "0x000D"
#define  VMA_DMAREG2A_5_inst_adr                                                 "0x008D"
#define  VMA_DMAREG2A_5_inst                                                     0x008D
#define  set_VMA_DMAREG2A_5_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG2A_5_reg)=data)
#define  get_VMA_DMAREG2A_5_reg                                                  (*((volatile unsigned int*)VMA_DMAREG2A_5_reg))

#define  VMA_DMAREG2A_6                                                          0x1800EE38
#define  VMA_DMAREG2A_6_reg_addr                                                 "0xB800EE38"
#define  VMA_DMAREG2A_6_reg                                                      0xB800EE38
#define  VMA_DMAREG2A_6_inst_addr                                                "0x000E"
#define  VMA_DMAREG2A_6_inst_adr                                                 "0x008E"
#define  VMA_DMAREG2A_6_inst                                                     0x008E
#define  set_VMA_DMAREG2A_6_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG2A_6_reg)=data)
#define  get_VMA_DMAREG2A_6_reg                                                  (*((volatile unsigned int*)VMA_DMAREG2A_6_reg))

#define  VMA_DMAREG2A_7                                                          0x1800EE3C
#define  VMA_DMAREG2A_7_reg_addr                                                 "0xB800EE3C"
#define  VMA_DMAREG2A_7_reg                                                      0xB800EE3C
#define  VMA_DMAREG2A_7_inst_addr                                                "0x000F"
#define  VMA_DMAREG2A_7_inst_adr                                                 "0x008F"
#define  VMA_DMAREG2A_7_inst                                                     0x008F
#define  set_VMA_DMAREG2A_7_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG2A_7_reg)=data)
#define  get_VMA_DMAREG2A_7_reg                                                  (*((volatile unsigned int*)VMA_DMAREG2A_7_reg))

#define  VMA_DMAREG3A_0                                                          0x1800EE40
#define  VMA_DMAREG3A_0_reg_addr                                                 "0xB800EE40"
#define  VMA_DMAREG3A_0_reg                                                      0xB800EE40
#define  VMA_DMAREG3A_0_inst_addr                                                "0x0010"
#define  VMA_DMAREG3A_0_inst_adr                                                 "0x0090"
#define  VMA_DMAREG3A_0_inst                                                     0x0090
#define  set_VMA_DMAREG3A_0_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG3A_0_reg)=data)
#define  get_VMA_DMAREG3A_0_reg                                                  (*((volatile unsigned int*)VMA_DMAREG3A_0_reg))
#define  VMA_DMAREG3A_line_off_shift                                             (28)
#define  VMA_DMAREG3A_vmRowOffset_shift                                          (22)
#define  VMA_DMAREG3A_vm_addr_shift                                              (12)
#define  VMA_DMAREG3A_H_shift                                                    (6)
#define  VMA_DMAREG3A_W_shift                                                    (0)
#define  VMA_DMAREG3A_line_off_mask                                              (0x10000000)
#define  VMA_DMAREG3A_vmRowOffset_mask                                           (0x07C00000)
#define  VMA_DMAREG3A_vm_addr_mask                                               (0x0007F000)
#define  VMA_DMAREG3A_H_mask                                                     (0x00000FC0)
#define  VMA_DMAREG3A_W_mask                                                     (0x0000003F)
#define  VMA_DMAREG3A_line_off(data)                                             (0x10000000&((data)<<28))
#define  VMA_DMAREG3A_vmRowOffset(data)                                          (0x07C00000&((data)<<22))
#define  VMA_DMAREG3A_vm_addr(data)                                              (0x0007F000&((data)<<12))
#define  VMA_DMAREG3A_H(data)                                                    (0x00000FC0&((data)<<6))
#define  VMA_DMAREG3A_W(data)                                                    (0x0000003F&(data))
#define  VMA_DMAREG3A_get_line_off(data)                                         ((0x10000000&(data))>>28)
#define  VMA_DMAREG3A_get_vmRowOffset(data)                                      ((0x07C00000&(data))>>22)
#define  VMA_DMAREG3A_get_vm_addr(data)                                          ((0x0007F000&(data))>>12)
#define  VMA_DMAREG3A_get_H(data)                                                ((0x00000FC0&(data))>>6)
#define  VMA_DMAREG3A_get_W(data)                                                (0x0000003F&(data))
#define  VMA_DMAREG3A_line_off_src(data)                                         ((0x10000000&(data))>>28)
#define  VMA_DMAREG3A_vmRowOffset_src(data)                                      ((0x07C00000&(data))>>22)
#define  VMA_DMAREG3A_vm_addr_src(data)                                          ((0x0007F000&(data))>>12)
#define  VMA_DMAREG3A_H_src(data)                                                ((0x00000FC0&(data))>>6)
#define  VMA_DMAREG3A_W_src(data)                                                (0x0000003F&(data))

#define  VMA_DMAREG3A_1                                                          0x1800EE44
#define  VMA_DMAREG3A_1_reg_addr                                                 "0xB800EE44"
#define  VMA_DMAREG3A_1_reg                                                      0xB800EE44
#define  VMA_DMAREG3A_1_inst_addr                                                "0x0011"
#define  VMA_DMAREG3A_1_inst_adr                                                 "0x0091"
#define  VMA_DMAREG3A_1_inst                                                     0x0091
#define  set_VMA_DMAREG3A_1_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG3A_1_reg)=data)
#define  get_VMA_DMAREG3A_1_reg                                                  (*((volatile unsigned int*)VMA_DMAREG3A_1_reg))

#define  VMA_DMAREG3A_2                                                          0x1800EE48
#define  VMA_DMAREG3A_2_reg_addr                                                 "0xB800EE48"
#define  VMA_DMAREG3A_2_reg                                                      0xB800EE48
#define  VMA_DMAREG3A_2_inst_addr                                                "0x0012"
#define  VMA_DMAREG3A_2_inst_adr                                                 "0x0092"
#define  VMA_DMAREG3A_2_inst                                                     0x0092
#define  set_VMA_DMAREG3A_2_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG3A_2_reg)=data)
#define  get_VMA_DMAREG3A_2_reg                                                  (*((volatile unsigned int*)VMA_DMAREG3A_2_reg))

#define  VMA_DMAREG3A_3                                                          0x1800EE4C
#define  VMA_DMAREG3A_3_reg_addr                                                 "0xB800EE4C"
#define  VMA_DMAREG3A_3_reg                                                      0xB800EE4C
#define  VMA_DMAREG3A_3_inst_addr                                                "0x0013"
#define  VMA_DMAREG3A_3_inst_adr                                                 "0x0093"
#define  VMA_DMAREG3A_3_inst                                                     0x0093
#define  set_VMA_DMAREG3A_3_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG3A_3_reg)=data)
#define  get_VMA_DMAREG3A_3_reg                                                  (*((volatile unsigned int*)VMA_DMAREG3A_3_reg))

#define  VMA_DMAREG3A_4                                                          0x1800EE50
#define  VMA_DMAREG3A_4_reg_addr                                                 "0xB800EE50"
#define  VMA_DMAREG3A_4_reg                                                      0xB800EE50
#define  VMA_DMAREG3A_4_inst_addr                                                "0x0014"
#define  VMA_DMAREG3A_4_inst_adr                                                 "0x0094"
#define  VMA_DMAREG3A_4_inst                                                     0x0094
#define  set_VMA_DMAREG3A_4_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG3A_4_reg)=data)
#define  get_VMA_DMAREG3A_4_reg                                                  (*((volatile unsigned int*)VMA_DMAREG3A_4_reg))

#define  VMA_DMAREG3A_5                                                          0x1800EE54
#define  VMA_DMAREG3A_5_reg_addr                                                 "0xB800EE54"
#define  VMA_DMAREG3A_5_reg                                                      0xB800EE54
#define  VMA_DMAREG3A_5_inst_addr                                                "0x0015"
#define  VMA_DMAREG3A_5_inst_adr                                                 "0x0095"
#define  VMA_DMAREG3A_5_inst                                                     0x0095
#define  set_VMA_DMAREG3A_5_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG3A_5_reg)=data)
#define  get_VMA_DMAREG3A_5_reg                                                  (*((volatile unsigned int*)VMA_DMAREG3A_5_reg))

#define  VMA_DMAREG3A_6                                                          0x1800EE58
#define  VMA_DMAREG3A_6_reg_addr                                                 "0xB800EE58"
#define  VMA_DMAREG3A_6_reg                                                      0xB800EE58
#define  VMA_DMAREG3A_6_inst_addr                                                "0x0016"
#define  VMA_DMAREG3A_6_inst_adr                                                 "0x0096"
#define  VMA_DMAREG3A_6_inst                                                     0x0096
#define  set_VMA_DMAREG3A_6_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG3A_6_reg)=data)
#define  get_VMA_DMAREG3A_6_reg                                                  (*((volatile unsigned int*)VMA_DMAREG3A_6_reg))

#define  VMA_DMAREG3A_7                                                          0x1800EE5C
#define  VMA_DMAREG3A_7_reg_addr                                                 "0xB800EE5C"
#define  VMA_DMAREG3A_7_reg                                                      0xB800EE5C
#define  VMA_DMAREG3A_7_inst_addr                                                "0x0017"
#define  VMA_DMAREG3A_7_inst_adr                                                 "0x0097"
#define  VMA_DMAREG3A_7_inst                                                     0x0097
#define  set_VMA_DMAREG3A_7_reg(data)                                            (*((volatile unsigned int*)VMA_DMAREG3A_7_reg)=data)
#define  get_VMA_DMAREG3A_7_reg                                                  (*((volatile unsigned int*)VMA_DMAREG3A_7_reg))

#define  VMA_SDMACNTLA                                                           0x1800EE60
#define  VMA_SDMACNTLA_reg_addr                                                  "0xB800EE60"
#define  VMA_SDMACNTLA_reg                                                       0xB800EE60
#define  VMA_SDMACNTLA_inst_addr                                                 "0x0018"
#define  VMA_SDMACNTLA_inst_adr                                                  "0x0098"
#define  VMA_SDMACNTLA_inst                                                      0x0098
#define  set_VMA_SDMACNTLA_reg(data)                                             (*((volatile unsigned int*)VMA_SDMACNTLA_reg)=data)
#define  get_VMA_SDMACNTLA_reg                                                   (*((volatile unsigned int*)VMA_SDMACNTLA_reg))
#define  VMA_SDMACNTLA_Seq_VMEM_addr_shift                                       (16)
#define  VMA_SDMACNTLA_Seq_10byte_sel_shift                                      (9)
#define  VMA_SDMACNTLA_Seq_xsfr_size_shift                                       (0)
#define  VMA_SDMACNTLA_Seq_VMEM_addr_mask                                        (0x1FFF0000)
#define  VMA_SDMACNTLA_Seq_10byte_sel_mask                                       (0x00000200)
#define  VMA_SDMACNTLA_Seq_xsfr_size_mask                                        (0x000001FF)
#define  VMA_SDMACNTLA_Seq_VMEM_addr(data)                                       (0x1FFF0000&((data)<<16))
#define  VMA_SDMACNTLA_Seq_10byte_sel(data)                                      (0x00000200&((data)<<9))
#define  VMA_SDMACNTLA_Seq_xsfr_size(data)                                       (0x000001FF&(data))
#define  VMA_SDMACNTLA_get_Seq_VMEM_addr(data)                                   ((0x1FFF0000&(data))>>16)
#define  VMA_SDMACNTLA_get_Seq_10byte_sel(data)                                  ((0x00000200&(data))>>9)
#define  VMA_SDMACNTLA_get_Seq_xsfr_size(data)                                   (0x000001FF&(data))
#define  VMA_SDMACNTLA_Seq_VMEM_addr_src(data)                                   ((0x1FFF0000&(data))>>16)
#define  VMA_SDMACNTLA_Seq_10byte_sel_src(data)                                  ((0x00000200&(data))>>9)
#define  VMA_SDMACNTLA_Seq_xsfr_size_src(data)                                   (0x000001FF&(data))

#define  VMA_SDMAADRA                                                            0x1800EE64
#define  VMA_SDMAADRA_reg_addr                                                   "0xB800EE64"
#define  VMA_SDMAADRA_reg                                                        0xB800EE64
#define  VMA_SDMAADRA_inst_addr                                                  "0x0019"
#define  VMA_SDMAADRA_inst_adr                                                   "0x0099"
#define  VMA_SDMAADRA_inst                                                       0x0099
#define  set_VMA_SDMAADRA_reg(data)                                              (*((volatile unsigned int*)VMA_SDMAADRA_reg)=data)
#define  get_VMA_SDMAADRA_reg                                                    (*((volatile unsigned int*)VMA_SDMAADRA_reg))
#define  VMA_SDMAADRA_seq_line_addr_shift                                        (0)
#define  VMA_SDMAADRA_seq_line_addr_mask                                         (0xFFFFFFFF)
#define  VMA_SDMAADRA_seq_line_addr(data)                                        (0xFFFFFFFF&(data))
#define  VMA_SDMAADRA_get_seq_line_addr(data)                                    (0xFFFFFFFF&(data))
#define  VMA_SDMAADRA_seq_line_addr_src(data)                                    (0xFFFFFFFF&(data))

#define  VMA_DMACTLA                                                             0x1800EE68
#define  VMA_DMACTLA_reg_addr                                                    "0xB800EE68"
#define  VMA_DMACTLA_reg                                                         0xB800EE68
#define  VMA_DMACTLA_inst_addr                                                   "0x001A"
#define  VMA_DMACTLA_inst_adr                                                    "0x009A"
#define  VMA_DMACTLA_inst                                                        0x009A
#define  set_VMA_DMACTLA_reg(data)                                               (*((volatile unsigned int*)VMA_DMACTLA_reg)=data)
#define  get_VMA_DMACTLA_reg                                                     (*((volatile unsigned int*)VMA_DMACTLA_reg))
#define  VMA_DMACTLA_write_enable7_shift                                         (29)
#define  VMA_DMACTLA_H264_dummy_info_shift                                       (27)
#define  VMA_DMACTLA_write_enable6_shift                                         (26)
#define  VMA_DMACTLA_HEVC_debug_shift                                            (25)
#define  VMA_DMACTLA_write_enable5_shift                                         (24)
#define  VMA_DMACTLA_Reset_valid_shift                                           (23)
#define  VMA_DMACTLA_write_enable3_shift                                         (20)
#define  VMA_DMACTLA_dmem_path_shift                                             (19)
#define  VMA_DMACTLA_write_enable2_shift                                         (18)
#define  VMA_DMACTLA_ldst_vmem_count_shift                                       (2)
#define  VMA_DMACTLA_write_enable1_shift                                         (1)
#define  VMA_DMACTLA_post_write_disable_shift                                    (0)
#define  VMA_DMACTLA_write_enable7_mask                                          (0x20000000)
#define  VMA_DMACTLA_H264_dummy_info_mask                                        (0x18000000)
#define  VMA_DMACTLA_write_enable6_mask                                          (0x04000000)
#define  VMA_DMACTLA_HEVC_debug_mask                                             (0x02000000)
#define  VMA_DMACTLA_write_enable5_mask                                          (0x01000000)
#define  VMA_DMACTLA_Reset_valid_mask                                            (0x00800000)
#define  VMA_DMACTLA_write_enable3_mask                                          (0x00100000)
#define  VMA_DMACTLA_dmem_path_mask                                              (0x00080000)
#define  VMA_DMACTLA_write_enable2_mask                                          (0x00040000)
#define  VMA_DMACTLA_ldst_vmem_count_mask                                        (0x0003FFFC)
#define  VMA_DMACTLA_write_enable1_mask                                          (0x00000002)
#define  VMA_DMACTLA_post_write_disable_mask                                     (0x00000001)
#define  VMA_DMACTLA_write_enable7(data)                                         (0x20000000&((data)<<29))
#define  VMA_DMACTLA_H264_dummy_info(data)                                       (0x18000000&((data)<<27))
#define  VMA_DMACTLA_write_enable6(data)                                         (0x04000000&((data)<<26))
#define  VMA_DMACTLA_HEVC_debug(data)                                            (0x02000000&((data)<<25))
#define  VMA_DMACTLA_write_enable5(data)                                         (0x01000000&((data)<<24))
#define  VMA_DMACTLA_Reset_valid(data)                                           (0x00800000&((data)<<23))
#define  VMA_DMACTLA_write_enable3(data)                                         (0x00100000&((data)<<20))
#define  VMA_DMACTLA_dmem_path(data)                                             (0x00080000&((data)<<19))
#define  VMA_DMACTLA_write_enable2(data)                                         (0x00040000&((data)<<18))
#define  VMA_DMACTLA_ldst_vmem_count(data)                                       (0x0003FFFC&((data)<<2))
#define  VMA_DMACTLA_write_enable1(data)                                         (0x00000002&((data)<<1))
#define  VMA_DMACTLA_post_write_disable(data)                                    (0x00000001&(data))
#define  VMA_DMACTLA_get_write_enable7(data)                                     ((0x20000000&(data))>>29)
#define  VMA_DMACTLA_get_H264_dummy_info(data)                                   ((0x18000000&(data))>>27)
#define  VMA_DMACTLA_get_write_enable6(data)                                     ((0x04000000&(data))>>26)
#define  VMA_DMACTLA_get_HEVC_debug(data)                                        ((0x02000000&(data))>>25)
#define  VMA_DMACTLA_get_write_enable5(data)                                     ((0x01000000&(data))>>24)
#define  VMA_DMACTLA_get_Reset_valid(data)                                       ((0x00800000&(data))>>23)
#define  VMA_DMACTLA_get_write_enable3(data)                                     ((0x00100000&(data))>>20)
#define  VMA_DMACTLA_get_dmem_path(data)                                         ((0x00080000&(data))>>19)
#define  VMA_DMACTLA_get_write_enable2(data)                                     ((0x00040000&(data))>>18)
#define  VMA_DMACTLA_get_ldst_vmem_count(data)                                   ((0x0003FFFC&(data))>>2)
#define  VMA_DMACTLA_get_write_enable1(data)                                     ((0x00000002&(data))>>1)
#define  VMA_DMACTLA_get_post_write_disable(data)                                (0x00000001&(data))
#define  VMA_DMACTLA_write_enable7_src(data)                                     ((0x20000000&(data))>>29)
#define  VMA_DMACTLA_H264_dummy_info_src(data)                                   ((0x18000000&(data))>>27)
#define  VMA_DMACTLA_write_enable6_src(data)                                     ((0x04000000&(data))>>26)
#define  VMA_DMACTLA_HEVC_debug_src(data)                                        ((0x02000000&(data))>>25)
#define  VMA_DMACTLA_write_enable5_src(data)                                     ((0x01000000&(data))>>24)
#define  VMA_DMACTLA_Reset_valid_src(data)                                       ((0x00800000&(data))>>23)
#define  VMA_DMACTLA_write_enable3_src(data)                                     ((0x00100000&(data))>>20)
#define  VMA_DMACTLA_dmem_path_src(data)                                         ((0x00080000&(data))>>19)
#define  VMA_DMACTLA_write_enable2_src(data)                                     ((0x00040000&(data))>>18)
#define  VMA_DMACTLA_ldst_vmem_count_src(data)                                   ((0x0003FFFC&(data))>>2)
#define  VMA_DMACTLA_write_enable1_src(data)                                     ((0x00000002&(data))>>1)
#define  VMA_DMACTLA_post_write_disable_src(data)                                (0x00000001&(data))

#define  VMA_BNKCTLA0                                                            0x1800EE6C
#define  VMA_BNKCTLA0_reg_addr                                                   "0xB800EE6C"
#define  VMA_BNKCTLA0_reg                                                        0xB800EE6C
#define  VMA_BNKCTLA0_inst_addr                                                  "0x001B"
#define  VMA_BNKCTLA0_inst_adr                                                   "0x009B"
#define  VMA_BNKCTLA0_inst                                                       0x009B
#define  set_VMA_BNKCTLA0_reg(data)                                              (*((volatile unsigned int*)VMA_BNKCTLA0_reg)=data)
#define  get_VMA_BNKCTLA0_reg                                                    (*((volatile unsigned int*)VMA_BNKCTLA0_reg))
#define  VMA_BNKCTLA0_write_enable6_shift                                        (23)
#define  VMA_BNKCTLA0_bnk5_mstr_shift                                            (20)
#define  VMA_BNKCTLA0_write_enable5_shift                                        (19)
#define  VMA_BNKCTLA0_bnk4_mstr_shift                                            (16)
#define  VMA_BNKCTLA0_write_enable4_shift                                        (15)
#define  VMA_BNKCTLA0_bnk3_mstr_shift                                            (12)
#define  VMA_BNKCTLA0_write_enable3_shift                                        (11)
#define  VMA_BNKCTLA0_bnk2_mstr_shift                                            (8)
#define  VMA_BNKCTLA0_write_enable2_shift                                        (7)
#define  VMA_BNKCTLA0_bnk1_mstr_shift                                            (4)
#define  VMA_BNKCTLA0_write_enable1_shift                                        (3)
#define  VMA_BNKCTLA0_bnk0_mstr_shift                                            (0)
#define  VMA_BNKCTLA0_write_enable6_mask                                         (0x00800000)
#define  VMA_BNKCTLA0_bnk5_mstr_mask                                             (0x00700000)
#define  VMA_BNKCTLA0_write_enable5_mask                                         (0x00080000)
#define  VMA_BNKCTLA0_bnk4_mstr_mask                                             (0x00070000)
#define  VMA_BNKCTLA0_write_enable4_mask                                         (0x00008000)
#define  VMA_BNKCTLA0_bnk3_mstr_mask                                             (0x00007000)
#define  VMA_BNKCTLA0_write_enable3_mask                                         (0x00000800)
#define  VMA_BNKCTLA0_bnk2_mstr_mask                                             (0x00000700)
#define  VMA_BNKCTLA0_write_enable2_mask                                         (0x00000080)
#define  VMA_BNKCTLA0_bnk1_mstr_mask                                             (0x00000070)
#define  VMA_BNKCTLA0_write_enable1_mask                                         (0x00000008)
#define  VMA_BNKCTLA0_bnk0_mstr_mask                                             (0x00000007)
#define  VMA_BNKCTLA0_write_enable6(data)                                        (0x00800000&((data)<<23))
#define  VMA_BNKCTLA0_bnk5_mstr(data)                                            (0x00700000&((data)<<20))
#define  VMA_BNKCTLA0_write_enable5(data)                                        (0x00080000&((data)<<19))
#define  VMA_BNKCTLA0_bnk4_mstr(data)                                            (0x00070000&((data)<<16))
#define  VMA_BNKCTLA0_write_enable4(data)                                        (0x00008000&((data)<<15))
#define  VMA_BNKCTLA0_bnk3_mstr(data)                                            (0x00007000&((data)<<12))
#define  VMA_BNKCTLA0_write_enable3(data)                                        (0x00000800&((data)<<11))
#define  VMA_BNKCTLA0_bnk2_mstr(data)                                            (0x00000700&((data)<<8))
#define  VMA_BNKCTLA0_write_enable2(data)                                        (0x00000080&((data)<<7))
#define  VMA_BNKCTLA0_bnk1_mstr(data)                                            (0x00000070&((data)<<4))
#define  VMA_BNKCTLA0_write_enable1(data)                                        (0x00000008&((data)<<3))
#define  VMA_BNKCTLA0_bnk0_mstr(data)                                            (0x00000007&(data))
#define  VMA_BNKCTLA0_get_write_enable6(data)                                    ((0x00800000&(data))>>23)
#define  VMA_BNKCTLA0_get_bnk5_mstr(data)                                        ((0x00700000&(data))>>20)
#define  VMA_BNKCTLA0_get_write_enable5(data)                                    ((0x00080000&(data))>>19)
#define  VMA_BNKCTLA0_get_bnk4_mstr(data)                                        ((0x00070000&(data))>>16)
#define  VMA_BNKCTLA0_get_write_enable4(data)                                    ((0x00008000&(data))>>15)
#define  VMA_BNKCTLA0_get_bnk3_mstr(data)                                        ((0x00007000&(data))>>12)
#define  VMA_BNKCTLA0_get_write_enable3(data)                                    ((0x00000800&(data))>>11)
#define  VMA_BNKCTLA0_get_bnk2_mstr(data)                                        ((0x00000700&(data))>>8)
#define  VMA_BNKCTLA0_get_write_enable2(data)                                    ((0x00000080&(data))>>7)
#define  VMA_BNKCTLA0_get_bnk1_mstr(data)                                        ((0x00000070&(data))>>4)
#define  VMA_BNKCTLA0_get_write_enable1(data)                                    ((0x00000008&(data))>>3)
#define  VMA_BNKCTLA0_get_bnk0_mstr(data)                                        (0x00000007&(data))
#define  VMA_BNKCTLA0_write_enable6_src(data)                                    ((0x00800000&(data))>>23)
#define  VMA_BNKCTLA0_bnk5_mstr_src(data)                                        ((0x00700000&(data))>>20)
#define  VMA_BNKCTLA0_write_enable5_src(data)                                    ((0x00080000&(data))>>19)
#define  VMA_BNKCTLA0_bnk4_mstr_src(data)                                        ((0x00070000&(data))>>16)
#define  VMA_BNKCTLA0_write_enable4_src(data)                                    ((0x00008000&(data))>>15)
#define  VMA_BNKCTLA0_bnk3_mstr_src(data)                                        ((0x00007000&(data))>>12)
#define  VMA_BNKCTLA0_write_enable3_src(data)                                    ((0x00000800&(data))>>11)
#define  VMA_BNKCTLA0_bnk2_mstr_src(data)                                        ((0x00000700&(data))>>8)
#define  VMA_BNKCTLA0_write_enable2_src(data)                                    ((0x00000080&(data))>>7)
#define  VMA_BNKCTLA0_bnk1_mstr_src(data)                                        ((0x00000070&(data))>>4)
#define  VMA_BNKCTLA0_write_enable1_src(data)                                    ((0x00000008&(data))>>3)
#define  VMA_BNKCTLA0_bnk0_mstr_src(data)                                        (0x00000007&(data))

#define  VMA_BNKCTLA1                                                            0x1800EE70
#define  VMA_BNKCTLA1_reg_addr                                                   "0xB800EE70"
#define  VMA_BNKCTLA1_reg                                                        0xB800EE70
#define  VMA_BNKCTLA1_inst_addr                                                  "0x001C"
#define  VMA_BNKCTLA1_inst_adr                                                   "0x009C"
#define  VMA_BNKCTLA1_inst                                                       0x009C
#define  set_VMA_BNKCTLA1_reg(data)                                              (*((volatile unsigned int*)VMA_BNKCTLA1_reg)=data)
#define  get_VMA_BNKCTLA1_reg                                                    (*((volatile unsigned int*)VMA_BNKCTLA1_reg))
#define  VMA_BNKCTLA1_write_enable5_shift                                        (23)
#define  VMA_BNKCTLA1_vm_vfiller0_shift                                          (20)
#define  VMA_BNKCTLA1_write_enable4_shift                                        (19)
#define  VMA_BNKCTLA1_vm_bnk_shift                                               (16)
#define  VMA_BNKCTLA1_write_enable3_shift                                        (15)
#define  VMA_BNKCTLA1_cmprs_bnk_shift                                            (12)
#define  VMA_BNKCTLA1_write_enable2_shift                                        (11)
#define  VMA_BNKCTLA1_sao_bnk_shift                                              (8)
#define  VMA_BNKCTLA1_write_enable1_shift                                        (7)
#define  VMA_BNKCTLA1_deblk_bnk_shift                                            (4)
#define  VMA_BNKCTLA1_write_enable0_shift                                        (3)
#define  VMA_BNKCTLA1_pred_bnk_shift                                             (0)
#define  VMA_BNKCTLA1_write_enable5_mask                                         (0x00800000)
#define  VMA_BNKCTLA1_vm_vfiller0_mask                                           (0x00700000)
#define  VMA_BNKCTLA1_write_enable4_mask                                         (0x00080000)
#define  VMA_BNKCTLA1_vm_bnk_mask                                                (0x00070000)
#define  VMA_BNKCTLA1_write_enable3_mask                                         (0x00008000)
#define  VMA_BNKCTLA1_cmprs_bnk_mask                                             (0x00007000)
#define  VMA_BNKCTLA1_write_enable2_mask                                         (0x00000800)
#define  VMA_BNKCTLA1_sao_bnk_mask                                               (0x00000700)
#define  VMA_BNKCTLA1_write_enable1_mask                                         (0x00000080)
#define  VMA_BNKCTLA1_deblk_bnk_mask                                             (0x00000070)
#define  VMA_BNKCTLA1_write_enable0_mask                                         (0x00000008)
#define  VMA_BNKCTLA1_pred_bnk_mask                                              (0x00000007)
#define  VMA_BNKCTLA1_write_enable5(data)                                        (0x00800000&((data)<<23))
#define  VMA_BNKCTLA1_vm_vfiller0(data)                                          (0x00700000&((data)<<20))
#define  VMA_BNKCTLA1_write_enable4(data)                                        (0x00080000&((data)<<19))
#define  VMA_BNKCTLA1_vm_bnk(data)                                               (0x00070000&((data)<<16))
#define  VMA_BNKCTLA1_write_enable3(data)                                        (0x00008000&((data)<<15))
#define  VMA_BNKCTLA1_cmprs_bnk(data)                                            (0x00007000&((data)<<12))
#define  VMA_BNKCTLA1_write_enable2(data)                                        (0x00000800&((data)<<11))
#define  VMA_BNKCTLA1_sao_bnk(data)                                              (0x00000700&((data)<<8))
#define  VMA_BNKCTLA1_write_enable1(data)                                        (0x00000080&((data)<<7))
#define  VMA_BNKCTLA1_deblk_bnk(data)                                            (0x00000070&((data)<<4))
#define  VMA_BNKCTLA1_write_enable0(data)                                        (0x00000008&((data)<<3))
#define  VMA_BNKCTLA1_pred_bnk(data)                                             (0x00000007&(data))
#define  VMA_BNKCTLA1_get_write_enable5(data)                                    ((0x00800000&(data))>>23)
#define  VMA_BNKCTLA1_get_vm_vfiller0(data)                                      ((0x00700000&(data))>>20)
#define  VMA_BNKCTLA1_get_write_enable4(data)                                    ((0x00080000&(data))>>19)
#define  VMA_BNKCTLA1_get_vm_bnk(data)                                           ((0x00070000&(data))>>16)
#define  VMA_BNKCTLA1_get_write_enable3(data)                                    ((0x00008000&(data))>>15)
#define  VMA_BNKCTLA1_get_cmprs_bnk(data)                                        ((0x00007000&(data))>>12)
#define  VMA_BNKCTLA1_get_write_enable2(data)                                    ((0x00000800&(data))>>11)
#define  VMA_BNKCTLA1_get_sao_bnk(data)                                          ((0x00000700&(data))>>8)
#define  VMA_BNKCTLA1_get_write_enable1(data)                                    ((0x00000080&(data))>>7)
#define  VMA_BNKCTLA1_get_deblk_bnk(data)                                        ((0x00000070&(data))>>4)
#define  VMA_BNKCTLA1_get_write_enable0(data)                                    ((0x00000008&(data))>>3)
#define  VMA_BNKCTLA1_get_pred_bnk(data)                                         (0x00000007&(data))
#define  VMA_BNKCTLA1_write_enable5_src(data)                                    ((0x00800000&(data))>>23)
#define  VMA_BNKCTLA1_vm_vfiller0_src(data)                                      ((0x00700000&(data))>>20)
#define  VMA_BNKCTLA1_write_enable4_src(data)                                    ((0x00080000&(data))>>19)
#define  VMA_BNKCTLA1_vm_bnk_src(data)                                           ((0x00070000&(data))>>16)
#define  VMA_BNKCTLA1_write_enable3_src(data)                                    ((0x00008000&(data))>>15)
#define  VMA_BNKCTLA1_cmprs_bnk_src(data)                                        ((0x00007000&(data))>>12)
#define  VMA_BNKCTLA1_write_enable2_src(data)                                    ((0x00000800&(data))>>11)
#define  VMA_BNKCTLA1_sao_bnk_src(data)                                          ((0x00000700&(data))>>8)
#define  VMA_BNKCTLA1_write_enable1_src(data)                                    ((0x00000080&(data))>>7)
#define  VMA_BNKCTLA1_deblk_bnk_src(data)                                        ((0x00000070&(data))>>4)
#define  VMA_BNKCTLA1_write_enable0_src(data)                                    ((0x00000008&(data))>>3)
#define  VMA_BNKCTLA1_pred_bnk_src(data)                                         (0x00000007&(data))

#define  VMA_CRCA                                                                0x1800EE74
#define  VMA_CRCA_reg_addr                                                       "0xB800EE74"
#define  VMA_CRCA_reg                                                            0xB800EE74
#define  VMA_CRCA_inst_addr                                                      "0x001D"
#define  VMA_CRCA_inst_adr                                                       "0x009D"
#define  VMA_CRCA_inst                                                           0x009D
#define  set_VMA_CRCA_reg(data)                                                  (*((volatile unsigned int*)VMA_CRCA_reg)=data)
#define  get_VMA_CRCA_reg                                                        (*((volatile unsigned int*)VMA_CRCA_reg))
#define  VMA_CRCA_crc_sum_shift                                                  (0)
#define  VMA_CRCA_crc_sum_mask                                                   (0xFFFFFFFF)
#define  VMA_CRCA_crc_sum(data)                                                  (0xFFFFFFFF&(data))
#define  VMA_CRCA_get_crc_sum(data)                                              (0xFFFFFFFF&(data))
#define  VMA_CRCA_crc_sum_src(data)                                              (0xFFFFFFFF&(data))

#define  VMA_CRCA_CTRL                                                           0x1800EE78
#define  VMA_CRCA_CTRL_reg_addr                                                  "0xB800EE78"
#define  VMA_CRCA_CTRL_reg                                                       0xB800EE78
#define  VMA_CRCA_CTRL_inst_addr                                                 "0x001E"
#define  VMA_CRCA_CTRL_inst_adr                                                  "0x009E"
#define  VMA_CRCA_CTRL_inst                                                      0x009E
#define  set_VMA_CRCA_CTRL_reg(data)                                             (*((volatile unsigned int*)VMA_CRCA_CTRL_reg)=data)
#define  get_VMA_CRCA_CTRL_reg                                                   (*((volatile unsigned int*)VMA_CRCA_CTRL_reg))
#define  VMA_CRCA_CTRL_Crc_sel_shift                                             (0)
#define  VMA_CRCA_CTRL_Crc_sel_mask                                              (0x00000001)
#define  VMA_CRCA_CTRL_Crc_sel(data)                                             (0x00000001&(data))
#define  VMA_CRCA_CTRL_get_Crc_sel(data)                                         (0x00000001&(data))
#define  VMA_CRCA_CTRL_Crc_sel_src(data)                                         (0x00000001&(data))

#ifdef _VMA_USE_STRUCT
#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  x:13;
        RBus_UInt32  y:14;
    };
}VMA_DMAREG1A_RBUS;

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
}VMA_DMAREG2A_RBUS;

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
}VMA_DMAREG3A_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  Seq_VMEM_addr:13;
        RBus_UInt32  res2:6;
        RBus_UInt32  Seq_10byte_sel:1;
        RBus_UInt32  Seq_xsfr_size:9;
    };
}VMA_SDMACNTLA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:32;
    };
}VMA_SDMAADRA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  H264_dummy_info:2;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  HEVC_debug:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  Reset_valid:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  dmem_path:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  ldst_vmem_count:16;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  post_write_disable:1;
    };
}VMA_DMACTLA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  bnk5_mstr:3;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  bnk4_mstr:3;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  bnk3_mstr:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  bnk2_mstr:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  bnk1_mstr:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  bnk0_mstr:3;
    };
}VMA_BNKCTLA0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  vm_vfiller0:3;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  vm_bnk:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cmprs_bnk:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  sao_bnk:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  deblk_bnk:3;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  pred_bnk:3;
    };
}VMA_BNKCTLA1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_sum:32;
    };
}VMA_CRCA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  Crc_sel:1;
    };
}VMA_CRCA_CTRL_RBUS;

#else //apply LITTLE_ENDIAN

//======VMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:14;
        RBus_UInt32  x:13;
        RBus_UInt32  res1:5;
    };
}VMA_DMAREG1A_RBUS;

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
}VMA_DMAREG2A_RBUS;

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
}VMA_DMAREG3A_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Seq_xsfr_size:9;
        RBus_UInt32  Seq_10byte_sel:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  Seq_VMEM_addr:13;
        RBus_UInt32  res2:3;
    };
}VMA_SDMACNTLA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:32;
    };
}VMA_SDMAADRA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  post_write_disable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  ldst_vmem_count:16;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  dmem_path:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  Reset_valid:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  HEVC_debug:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  H264_dummy_info:2;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  res2:2;
    };
}VMA_DMACTLA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bnk0_mstr:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  bnk1_mstr:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  bnk2_mstr:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  bnk3_mstr:3;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  bnk4_mstr:3;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  bnk5_mstr:3;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  res1:8;
    };
}VMA_BNKCTLA0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pred_bnk:3;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  deblk_bnk:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  sao_bnk:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cmprs_bnk:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  vm_bnk:3;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  vm_vfiller0:3;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:8;
    };
}VMA_BNKCTLA1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_sum:32;
    };
}VMA_CRCA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Crc_sel:1;
        RBus_UInt32  res1:31;
    };
}VMA_CRCA_CTRL_RBUS;




#endif 


#endif 
#endif 
