/**
* @file Mac5_LGCY_VE_VMBLK_dmab
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGCY_VMB_REG_H_
#define _RBUS_LGCY_VMB_REG_H_

#include "rbus_types.h"



//  LGCY_VMB Register Address
#define  LGCY_VMB_DMAREG1B_0                                                     0x1800EF00
#define  LGCY_VMB_DMAREG1B_0_reg_addr                                            "0xB800EF00"
#define  LGCY_VMB_DMAREG1B_0_reg                                                 0xB800EF00
#define  LGCY_VMB_DMAREG1B_0_inst_addr                                           "0x0000"
#define  set_LGCY_VMB_DMAREG1B_0_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_0_reg)=data)
#define  get_LGCY_VMB_DMAREG1B_0_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_0_reg))
#define  LGCY_VMB_DMAREG1B_0_x_shift                                             (14)
#define  LGCY_VMB_DMAREG1B_0_y_shift                                             (0)
#define  LGCY_VMB_DMAREG1B_0_x_mask                                              (0x07FFC000)
#define  LGCY_VMB_DMAREG1B_0_y_mask                                              (0x00003FFF)
#define  LGCY_VMB_DMAREG1B_0_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_VMB_DMAREG1B_0_y(data)                                             (0x00003FFF&(data))
#define  LGCY_VMB_DMAREG1B_0_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_VMB_DMAREG1B_0_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_VMB_DMAREG1B_1                                                     0x1800EF04
#define  LGCY_VMB_DMAREG1B_1_reg_addr                                            "0xB800EF04"
#define  LGCY_VMB_DMAREG1B_1_reg                                                 0xB800EF04
#define  LGCY_VMB_DMAREG1B_1_inst_addr                                           "0x0001"
#define  set_LGCY_VMB_DMAREG1B_1_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_1_reg)=data)
#define  get_LGCY_VMB_DMAREG1B_1_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_1_reg))
#define  LGCY_VMB_DMAREG1B_1_x_shift                                             (14)
#define  LGCY_VMB_DMAREG1B_1_y_shift                                             (0)
#define  LGCY_VMB_DMAREG1B_1_x_mask                                              (0x07FFC000)
#define  LGCY_VMB_DMAREG1B_1_y_mask                                              (0x00003FFF)
#define  LGCY_VMB_DMAREG1B_1_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_VMB_DMAREG1B_1_y(data)                                             (0x00003FFF&(data))
#define  LGCY_VMB_DMAREG1B_1_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_VMB_DMAREG1B_1_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_VMB_DMAREG1B_2                                                     0x1800EF08
#define  LGCY_VMB_DMAREG1B_2_reg_addr                                            "0xB800EF08"
#define  LGCY_VMB_DMAREG1B_2_reg                                                 0xB800EF08
#define  LGCY_VMB_DMAREG1B_2_inst_addr                                           "0x0002"
#define  set_LGCY_VMB_DMAREG1B_2_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_2_reg)=data)
#define  get_LGCY_VMB_DMAREG1B_2_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_2_reg))
#define  LGCY_VMB_DMAREG1B_2_x_shift                                             (14)
#define  LGCY_VMB_DMAREG1B_2_y_shift                                             (0)
#define  LGCY_VMB_DMAREG1B_2_x_mask                                              (0x07FFC000)
#define  LGCY_VMB_DMAREG1B_2_y_mask                                              (0x00003FFF)
#define  LGCY_VMB_DMAREG1B_2_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_VMB_DMAREG1B_2_y(data)                                             (0x00003FFF&(data))
#define  LGCY_VMB_DMAREG1B_2_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_VMB_DMAREG1B_2_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_VMB_DMAREG1B_3                                                     0x1800EF0C
#define  LGCY_VMB_DMAREG1B_3_reg_addr                                            "0xB800EF0C"
#define  LGCY_VMB_DMAREG1B_3_reg                                                 0xB800EF0C
#define  LGCY_VMB_DMAREG1B_3_inst_addr                                           "0x0003"
#define  set_LGCY_VMB_DMAREG1B_3_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_3_reg)=data)
#define  get_LGCY_VMB_DMAREG1B_3_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_3_reg))
#define  LGCY_VMB_DMAREG1B_3_x_shift                                             (14)
#define  LGCY_VMB_DMAREG1B_3_y_shift                                             (0)
#define  LGCY_VMB_DMAREG1B_3_x_mask                                              (0x07FFC000)
#define  LGCY_VMB_DMAREG1B_3_y_mask                                              (0x00003FFF)
#define  LGCY_VMB_DMAREG1B_3_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_VMB_DMAREG1B_3_y(data)                                             (0x00003FFF&(data))
#define  LGCY_VMB_DMAREG1B_3_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_VMB_DMAREG1B_3_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_VMB_DMAREG1B_4                                                     0x1800EF10
#define  LGCY_VMB_DMAREG1B_4_reg_addr                                            "0xB800EF10"
#define  LGCY_VMB_DMAREG1B_4_reg                                                 0xB800EF10
#define  LGCY_VMB_DMAREG1B_4_inst_addr                                           "0x0004"
#define  set_LGCY_VMB_DMAREG1B_4_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_4_reg)=data)
#define  get_LGCY_VMB_DMAREG1B_4_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_4_reg))
#define  LGCY_VMB_DMAREG1B_4_x_shift                                             (14)
#define  LGCY_VMB_DMAREG1B_4_y_shift                                             (0)
#define  LGCY_VMB_DMAREG1B_4_x_mask                                              (0x07FFC000)
#define  LGCY_VMB_DMAREG1B_4_y_mask                                              (0x00003FFF)
#define  LGCY_VMB_DMAREG1B_4_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_VMB_DMAREG1B_4_y(data)                                             (0x00003FFF&(data))
#define  LGCY_VMB_DMAREG1B_4_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_VMB_DMAREG1B_4_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_VMB_DMAREG1B_5                                                     0x1800EF14
#define  LGCY_VMB_DMAREG1B_5_reg_addr                                            "0xB800EF14"
#define  LGCY_VMB_DMAREG1B_5_reg                                                 0xB800EF14
#define  LGCY_VMB_DMAREG1B_5_inst_addr                                           "0x0005"
#define  set_LGCY_VMB_DMAREG1B_5_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_5_reg)=data)
#define  get_LGCY_VMB_DMAREG1B_5_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_5_reg))
#define  LGCY_VMB_DMAREG1B_5_x_shift                                             (14)
#define  LGCY_VMB_DMAREG1B_5_y_shift                                             (0)
#define  LGCY_VMB_DMAREG1B_5_x_mask                                              (0x07FFC000)
#define  LGCY_VMB_DMAREG1B_5_y_mask                                              (0x00003FFF)
#define  LGCY_VMB_DMAREG1B_5_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_VMB_DMAREG1B_5_y(data)                                             (0x00003FFF&(data))
#define  LGCY_VMB_DMAREG1B_5_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_VMB_DMAREG1B_5_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_VMB_DMAREG1B_6                                                     0x1800EF18
#define  LGCY_VMB_DMAREG1B_6_reg_addr                                            "0xB800EF18"
#define  LGCY_VMB_DMAREG1B_6_reg                                                 0xB800EF18
#define  LGCY_VMB_DMAREG1B_6_inst_addr                                           "0x0006"
#define  set_LGCY_VMB_DMAREG1B_6_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_6_reg)=data)
#define  get_LGCY_VMB_DMAREG1B_6_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_6_reg))
#define  LGCY_VMB_DMAREG1B_6_x_shift                                             (14)
#define  LGCY_VMB_DMAREG1B_6_y_shift                                             (0)
#define  LGCY_VMB_DMAREG1B_6_x_mask                                              (0x07FFC000)
#define  LGCY_VMB_DMAREG1B_6_y_mask                                              (0x00003FFF)
#define  LGCY_VMB_DMAREG1B_6_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_VMB_DMAREG1B_6_y(data)                                             (0x00003FFF&(data))
#define  LGCY_VMB_DMAREG1B_6_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_VMB_DMAREG1B_6_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_VMB_DMAREG1B_7                                                     0x1800EF1C
#define  LGCY_VMB_DMAREG1B_7_reg_addr                                            "0xB800EF1C"
#define  LGCY_VMB_DMAREG1B_7_reg                                                 0xB800EF1C
#define  LGCY_VMB_DMAREG1B_7_inst_addr                                           "0x0007"
#define  set_LGCY_VMB_DMAREG1B_7_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_7_reg)=data)
#define  get_LGCY_VMB_DMAREG1B_7_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG1B_7_reg))
#define  LGCY_VMB_DMAREG1B_7_x_shift                                             (14)
#define  LGCY_VMB_DMAREG1B_7_y_shift                                             (0)
#define  LGCY_VMB_DMAREG1B_7_x_mask                                              (0x07FFC000)
#define  LGCY_VMB_DMAREG1B_7_y_mask                                              (0x00003FFF)
#define  LGCY_VMB_DMAREG1B_7_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_VMB_DMAREG1B_7_y(data)                                             (0x00003FFF&(data))
#define  LGCY_VMB_DMAREG1B_7_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_VMB_DMAREG1B_7_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_VMB_DMAREG2B_0                                                     0x1800EF20
#define  LGCY_VMB_DMAREG2B_0_reg_addr                                            "0xB800EF20"
#define  LGCY_VMB_DMAREG2B_0_reg                                                 0xB800EF20
#define  LGCY_VMB_DMAREG2B_0_inst_addr                                           "0x0008"
#define  set_LGCY_VMB_DMAREG2B_0_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_0_reg)=data)
#define  get_LGCY_VMB_DMAREG2B_0_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_0_reg))
#define  LGCY_VMB_DMAREG2B_0_cbcr_vmoffset_shift                                 (23)
#define  LGCY_VMB_DMAREG2B_0_mode_shift                                          (22)
#define  LGCY_VMB_DMAREG2B_0_right_offset_shift                                  (19)
#define  LGCY_VMB_DMAREG2B_0_left_offset_shift                                   (16)
#define  LGCY_VMB_DMAREG2B_0_addr_idx_shift                                      (8)
#define  LGCY_VMB_DMAREG2B_0_post_inc_sel_shift                                  (7)
#define  LGCY_VMB_DMAREG2B_0_post_inc_shift                                      (0)
#define  LGCY_VMB_DMAREG2B_0_cbcr_vmoffset_mask                                  (0x3F800000)
#define  LGCY_VMB_DMAREG2B_0_mode_mask                                           (0x00400000)
#define  LGCY_VMB_DMAREG2B_0_right_offset_mask                                   (0x00380000)
#define  LGCY_VMB_DMAREG2B_0_left_offset_mask                                    (0x00070000)
#define  LGCY_VMB_DMAREG2B_0_addr_idx_mask                                       (0x00007F00)
#define  LGCY_VMB_DMAREG2B_0_post_inc_sel_mask                                   (0x00000080)
#define  LGCY_VMB_DMAREG2B_0_post_inc_mask                                       (0x0000003F)
#define  LGCY_VMB_DMAREG2B_0_cbcr_vmoffset(data)                                 (0x3F800000&((data)<<23))
#define  LGCY_VMB_DMAREG2B_0_mode(data)                                          (0x00400000&((data)<<22))
#define  LGCY_VMB_DMAREG2B_0_right_offset(data)                                  (0x00380000&((data)<<19))
#define  LGCY_VMB_DMAREG2B_0_left_offset(data)                                   (0x00070000&((data)<<16))
#define  LGCY_VMB_DMAREG2B_0_addr_idx(data)                                      (0x00007F00&((data)<<8))
#define  LGCY_VMB_DMAREG2B_0_post_inc_sel(data)                                  (0x00000080&((data)<<7))
#define  LGCY_VMB_DMAREG2B_0_post_inc(data)                                      (0x0000003F&(data))
#define  LGCY_VMB_DMAREG2B_0_get_cbcr_vmoffset(data)                             ((0x3F800000&(data))>>23)
#define  LGCY_VMB_DMAREG2B_0_get_mode(data)                                      ((0x00400000&(data))>>22)
#define  LGCY_VMB_DMAREG2B_0_get_right_offset(data)                              ((0x00380000&(data))>>19)
#define  LGCY_VMB_DMAREG2B_0_get_left_offset(data)                               ((0x00070000&(data))>>16)
#define  LGCY_VMB_DMAREG2B_0_get_addr_idx(data)                                  ((0x00007F00&(data))>>8)
#define  LGCY_VMB_DMAREG2B_0_get_post_inc_sel(data)                              ((0x00000080&(data))>>7)
#define  LGCY_VMB_DMAREG2B_0_get_post_inc(data)                                  (0x0000003F&(data))

#define  LGCY_VMB_DMAREG2B_1                                                     0x1800EF24
#define  LGCY_VMB_DMAREG2B_1_reg_addr                                            "0xB800EF24"
#define  LGCY_VMB_DMAREG2B_1_reg                                                 0xB800EF24
#define  LGCY_VMB_DMAREG2B_1_inst_addr                                           "0x0009"
#define  set_LGCY_VMB_DMAREG2B_1_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_1_reg)=data)
#define  get_LGCY_VMB_DMAREG2B_1_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_1_reg))
#define  LGCY_VMB_DMAREG2B_1_cbcr_vmoffset_shift                                 (23)
#define  LGCY_VMB_DMAREG2B_1_mode_shift                                          (22)
#define  LGCY_VMB_DMAREG2B_1_right_offset_shift                                  (19)
#define  LGCY_VMB_DMAREG2B_1_left_offset_shift                                   (16)
#define  LGCY_VMB_DMAREG2B_1_addr_idx_shift                                      (8)
#define  LGCY_VMB_DMAREG2B_1_post_inc_sel_shift                                  (7)
#define  LGCY_VMB_DMAREG2B_1_post_inc_shift                                      (0)
#define  LGCY_VMB_DMAREG2B_1_cbcr_vmoffset_mask                                  (0x3F800000)
#define  LGCY_VMB_DMAREG2B_1_mode_mask                                           (0x00400000)
#define  LGCY_VMB_DMAREG2B_1_right_offset_mask                                   (0x00380000)
#define  LGCY_VMB_DMAREG2B_1_left_offset_mask                                    (0x00070000)
#define  LGCY_VMB_DMAREG2B_1_addr_idx_mask                                       (0x00007F00)
#define  LGCY_VMB_DMAREG2B_1_post_inc_sel_mask                                   (0x00000080)
#define  LGCY_VMB_DMAREG2B_1_post_inc_mask                                       (0x0000003F)
#define  LGCY_VMB_DMAREG2B_1_cbcr_vmoffset(data)                                 (0x3F800000&((data)<<23))
#define  LGCY_VMB_DMAREG2B_1_mode(data)                                          (0x00400000&((data)<<22))
#define  LGCY_VMB_DMAREG2B_1_right_offset(data)                                  (0x00380000&((data)<<19))
#define  LGCY_VMB_DMAREG2B_1_left_offset(data)                                   (0x00070000&((data)<<16))
#define  LGCY_VMB_DMAREG2B_1_addr_idx(data)                                      (0x00007F00&((data)<<8))
#define  LGCY_VMB_DMAREG2B_1_post_inc_sel(data)                                  (0x00000080&((data)<<7))
#define  LGCY_VMB_DMAREG2B_1_post_inc(data)                                      (0x0000003F&(data))
#define  LGCY_VMB_DMAREG2B_1_get_cbcr_vmoffset(data)                             ((0x3F800000&(data))>>23)
#define  LGCY_VMB_DMAREG2B_1_get_mode(data)                                      ((0x00400000&(data))>>22)
#define  LGCY_VMB_DMAREG2B_1_get_right_offset(data)                              ((0x00380000&(data))>>19)
#define  LGCY_VMB_DMAREG2B_1_get_left_offset(data)                               ((0x00070000&(data))>>16)
#define  LGCY_VMB_DMAREG2B_1_get_addr_idx(data)                                  ((0x00007F00&(data))>>8)
#define  LGCY_VMB_DMAREG2B_1_get_post_inc_sel(data)                              ((0x00000080&(data))>>7)
#define  LGCY_VMB_DMAREG2B_1_get_post_inc(data)                                  (0x0000003F&(data))

#define  LGCY_VMB_DMAREG2B_2                                                     0x1800EF28
#define  LGCY_VMB_DMAREG2B_2_reg_addr                                            "0xB800EF28"
#define  LGCY_VMB_DMAREG2B_2_reg                                                 0xB800EF28
#define  LGCY_VMB_DMAREG2B_2_inst_addr                                           "0x000A"
#define  set_LGCY_VMB_DMAREG2B_2_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_2_reg)=data)
#define  get_LGCY_VMB_DMAREG2B_2_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_2_reg))
#define  LGCY_VMB_DMAREG2B_2_cbcr_vmoffset_shift                                 (23)
#define  LGCY_VMB_DMAREG2B_2_mode_shift                                          (22)
#define  LGCY_VMB_DMAREG2B_2_right_offset_shift                                  (19)
#define  LGCY_VMB_DMAREG2B_2_left_offset_shift                                   (16)
#define  LGCY_VMB_DMAREG2B_2_addr_idx_shift                                      (8)
#define  LGCY_VMB_DMAREG2B_2_post_inc_sel_shift                                  (7)
#define  LGCY_VMB_DMAREG2B_2_post_inc_shift                                      (0)
#define  LGCY_VMB_DMAREG2B_2_cbcr_vmoffset_mask                                  (0x3F800000)
#define  LGCY_VMB_DMAREG2B_2_mode_mask                                           (0x00400000)
#define  LGCY_VMB_DMAREG2B_2_right_offset_mask                                   (0x00380000)
#define  LGCY_VMB_DMAREG2B_2_left_offset_mask                                    (0x00070000)
#define  LGCY_VMB_DMAREG2B_2_addr_idx_mask                                       (0x00007F00)
#define  LGCY_VMB_DMAREG2B_2_post_inc_sel_mask                                   (0x00000080)
#define  LGCY_VMB_DMAREG2B_2_post_inc_mask                                       (0x0000003F)
#define  LGCY_VMB_DMAREG2B_2_cbcr_vmoffset(data)                                 (0x3F800000&((data)<<23))
#define  LGCY_VMB_DMAREG2B_2_mode(data)                                          (0x00400000&((data)<<22))
#define  LGCY_VMB_DMAREG2B_2_right_offset(data)                                  (0x00380000&((data)<<19))
#define  LGCY_VMB_DMAREG2B_2_left_offset(data)                                   (0x00070000&((data)<<16))
#define  LGCY_VMB_DMAREG2B_2_addr_idx(data)                                      (0x00007F00&((data)<<8))
#define  LGCY_VMB_DMAREG2B_2_post_inc_sel(data)                                  (0x00000080&((data)<<7))
#define  LGCY_VMB_DMAREG2B_2_post_inc(data)                                      (0x0000003F&(data))
#define  LGCY_VMB_DMAREG2B_2_get_cbcr_vmoffset(data)                             ((0x3F800000&(data))>>23)
#define  LGCY_VMB_DMAREG2B_2_get_mode(data)                                      ((0x00400000&(data))>>22)
#define  LGCY_VMB_DMAREG2B_2_get_right_offset(data)                              ((0x00380000&(data))>>19)
#define  LGCY_VMB_DMAREG2B_2_get_left_offset(data)                               ((0x00070000&(data))>>16)
#define  LGCY_VMB_DMAREG2B_2_get_addr_idx(data)                                  ((0x00007F00&(data))>>8)
#define  LGCY_VMB_DMAREG2B_2_get_post_inc_sel(data)                              ((0x00000080&(data))>>7)
#define  LGCY_VMB_DMAREG2B_2_get_post_inc(data)                                  (0x0000003F&(data))

#define  LGCY_VMB_DMAREG2B_3                                                     0x1800EF2C
#define  LGCY_VMB_DMAREG2B_3_reg_addr                                            "0xB800EF2C"
#define  LGCY_VMB_DMAREG2B_3_reg                                                 0xB800EF2C
#define  LGCY_VMB_DMAREG2B_3_inst_addr                                           "0x000B"
#define  set_LGCY_VMB_DMAREG2B_3_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_3_reg)=data)
#define  get_LGCY_VMB_DMAREG2B_3_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_3_reg))
#define  LGCY_VMB_DMAREG2B_3_cbcr_vmoffset_shift                                 (23)
#define  LGCY_VMB_DMAREG2B_3_mode_shift                                          (22)
#define  LGCY_VMB_DMAREG2B_3_right_offset_shift                                  (19)
#define  LGCY_VMB_DMAREG2B_3_left_offset_shift                                   (16)
#define  LGCY_VMB_DMAREG2B_3_addr_idx_shift                                      (8)
#define  LGCY_VMB_DMAREG2B_3_post_inc_sel_shift                                  (7)
#define  LGCY_VMB_DMAREG2B_3_post_inc_shift                                      (0)
#define  LGCY_VMB_DMAREG2B_3_cbcr_vmoffset_mask                                  (0x3F800000)
#define  LGCY_VMB_DMAREG2B_3_mode_mask                                           (0x00400000)
#define  LGCY_VMB_DMAREG2B_3_right_offset_mask                                   (0x00380000)
#define  LGCY_VMB_DMAREG2B_3_left_offset_mask                                    (0x00070000)
#define  LGCY_VMB_DMAREG2B_3_addr_idx_mask                                       (0x00007F00)
#define  LGCY_VMB_DMAREG2B_3_post_inc_sel_mask                                   (0x00000080)
#define  LGCY_VMB_DMAREG2B_3_post_inc_mask                                       (0x0000003F)
#define  LGCY_VMB_DMAREG2B_3_cbcr_vmoffset(data)                                 (0x3F800000&((data)<<23))
#define  LGCY_VMB_DMAREG2B_3_mode(data)                                          (0x00400000&((data)<<22))
#define  LGCY_VMB_DMAREG2B_3_right_offset(data)                                  (0x00380000&((data)<<19))
#define  LGCY_VMB_DMAREG2B_3_left_offset(data)                                   (0x00070000&((data)<<16))
#define  LGCY_VMB_DMAREG2B_3_addr_idx(data)                                      (0x00007F00&((data)<<8))
#define  LGCY_VMB_DMAREG2B_3_post_inc_sel(data)                                  (0x00000080&((data)<<7))
#define  LGCY_VMB_DMAREG2B_3_post_inc(data)                                      (0x0000003F&(data))
#define  LGCY_VMB_DMAREG2B_3_get_cbcr_vmoffset(data)                             ((0x3F800000&(data))>>23)
#define  LGCY_VMB_DMAREG2B_3_get_mode(data)                                      ((0x00400000&(data))>>22)
#define  LGCY_VMB_DMAREG2B_3_get_right_offset(data)                              ((0x00380000&(data))>>19)
#define  LGCY_VMB_DMAREG2B_3_get_left_offset(data)                               ((0x00070000&(data))>>16)
#define  LGCY_VMB_DMAREG2B_3_get_addr_idx(data)                                  ((0x00007F00&(data))>>8)
#define  LGCY_VMB_DMAREG2B_3_get_post_inc_sel(data)                              ((0x00000080&(data))>>7)
#define  LGCY_VMB_DMAREG2B_3_get_post_inc(data)                                  (0x0000003F&(data))

#define  LGCY_VMB_DMAREG2B_4                                                     0x1800EF30
#define  LGCY_VMB_DMAREG2B_4_reg_addr                                            "0xB800EF30"
#define  LGCY_VMB_DMAREG2B_4_reg                                                 0xB800EF30
#define  LGCY_VMB_DMAREG2B_4_inst_addr                                           "0x000C"
#define  set_LGCY_VMB_DMAREG2B_4_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_4_reg)=data)
#define  get_LGCY_VMB_DMAREG2B_4_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_4_reg))
#define  LGCY_VMB_DMAREG2B_4_cbcr_vmoffset_shift                                 (23)
#define  LGCY_VMB_DMAREG2B_4_mode_shift                                          (22)
#define  LGCY_VMB_DMAREG2B_4_right_offset_shift                                  (19)
#define  LGCY_VMB_DMAREG2B_4_left_offset_shift                                   (16)
#define  LGCY_VMB_DMAREG2B_4_addr_idx_shift                                      (8)
#define  LGCY_VMB_DMAREG2B_4_post_inc_sel_shift                                  (7)
#define  LGCY_VMB_DMAREG2B_4_post_inc_shift                                      (0)
#define  LGCY_VMB_DMAREG2B_4_cbcr_vmoffset_mask                                  (0x3F800000)
#define  LGCY_VMB_DMAREG2B_4_mode_mask                                           (0x00400000)
#define  LGCY_VMB_DMAREG2B_4_right_offset_mask                                   (0x00380000)
#define  LGCY_VMB_DMAREG2B_4_left_offset_mask                                    (0x00070000)
#define  LGCY_VMB_DMAREG2B_4_addr_idx_mask                                       (0x00007F00)
#define  LGCY_VMB_DMAREG2B_4_post_inc_sel_mask                                   (0x00000080)
#define  LGCY_VMB_DMAREG2B_4_post_inc_mask                                       (0x0000003F)
#define  LGCY_VMB_DMAREG2B_4_cbcr_vmoffset(data)                                 (0x3F800000&((data)<<23))
#define  LGCY_VMB_DMAREG2B_4_mode(data)                                          (0x00400000&((data)<<22))
#define  LGCY_VMB_DMAREG2B_4_right_offset(data)                                  (0x00380000&((data)<<19))
#define  LGCY_VMB_DMAREG2B_4_left_offset(data)                                   (0x00070000&((data)<<16))
#define  LGCY_VMB_DMAREG2B_4_addr_idx(data)                                      (0x00007F00&((data)<<8))
#define  LGCY_VMB_DMAREG2B_4_post_inc_sel(data)                                  (0x00000080&((data)<<7))
#define  LGCY_VMB_DMAREG2B_4_post_inc(data)                                      (0x0000003F&(data))
#define  LGCY_VMB_DMAREG2B_4_get_cbcr_vmoffset(data)                             ((0x3F800000&(data))>>23)
#define  LGCY_VMB_DMAREG2B_4_get_mode(data)                                      ((0x00400000&(data))>>22)
#define  LGCY_VMB_DMAREG2B_4_get_right_offset(data)                              ((0x00380000&(data))>>19)
#define  LGCY_VMB_DMAREG2B_4_get_left_offset(data)                               ((0x00070000&(data))>>16)
#define  LGCY_VMB_DMAREG2B_4_get_addr_idx(data)                                  ((0x00007F00&(data))>>8)
#define  LGCY_VMB_DMAREG2B_4_get_post_inc_sel(data)                              ((0x00000080&(data))>>7)
#define  LGCY_VMB_DMAREG2B_4_get_post_inc(data)                                  (0x0000003F&(data))

#define  LGCY_VMB_DMAREG2B_5                                                     0x1800EF34
#define  LGCY_VMB_DMAREG2B_5_reg_addr                                            "0xB800EF34"
#define  LGCY_VMB_DMAREG2B_5_reg                                                 0xB800EF34
#define  LGCY_VMB_DMAREG2B_5_inst_addr                                           "0x000D"
#define  set_LGCY_VMB_DMAREG2B_5_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_5_reg)=data)
#define  get_LGCY_VMB_DMAREG2B_5_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_5_reg))
#define  LGCY_VMB_DMAREG2B_5_cbcr_vmoffset_shift                                 (23)
#define  LGCY_VMB_DMAREG2B_5_mode_shift                                          (22)
#define  LGCY_VMB_DMAREG2B_5_right_offset_shift                                  (19)
#define  LGCY_VMB_DMAREG2B_5_left_offset_shift                                   (16)
#define  LGCY_VMB_DMAREG2B_5_addr_idx_shift                                      (8)
#define  LGCY_VMB_DMAREG2B_5_post_inc_sel_shift                                  (7)
#define  LGCY_VMB_DMAREG2B_5_post_inc_shift                                      (0)
#define  LGCY_VMB_DMAREG2B_5_cbcr_vmoffset_mask                                  (0x3F800000)
#define  LGCY_VMB_DMAREG2B_5_mode_mask                                           (0x00400000)
#define  LGCY_VMB_DMAREG2B_5_right_offset_mask                                   (0x00380000)
#define  LGCY_VMB_DMAREG2B_5_left_offset_mask                                    (0x00070000)
#define  LGCY_VMB_DMAREG2B_5_addr_idx_mask                                       (0x00007F00)
#define  LGCY_VMB_DMAREG2B_5_post_inc_sel_mask                                   (0x00000080)
#define  LGCY_VMB_DMAREG2B_5_post_inc_mask                                       (0x0000003F)
#define  LGCY_VMB_DMAREG2B_5_cbcr_vmoffset(data)                                 (0x3F800000&((data)<<23))
#define  LGCY_VMB_DMAREG2B_5_mode(data)                                          (0x00400000&((data)<<22))
#define  LGCY_VMB_DMAREG2B_5_right_offset(data)                                  (0x00380000&((data)<<19))
#define  LGCY_VMB_DMAREG2B_5_left_offset(data)                                   (0x00070000&((data)<<16))
#define  LGCY_VMB_DMAREG2B_5_addr_idx(data)                                      (0x00007F00&((data)<<8))
#define  LGCY_VMB_DMAREG2B_5_post_inc_sel(data)                                  (0x00000080&((data)<<7))
#define  LGCY_VMB_DMAREG2B_5_post_inc(data)                                      (0x0000003F&(data))
#define  LGCY_VMB_DMAREG2B_5_get_cbcr_vmoffset(data)                             ((0x3F800000&(data))>>23)
#define  LGCY_VMB_DMAREG2B_5_get_mode(data)                                      ((0x00400000&(data))>>22)
#define  LGCY_VMB_DMAREG2B_5_get_right_offset(data)                              ((0x00380000&(data))>>19)
#define  LGCY_VMB_DMAREG2B_5_get_left_offset(data)                               ((0x00070000&(data))>>16)
#define  LGCY_VMB_DMAREG2B_5_get_addr_idx(data)                                  ((0x00007F00&(data))>>8)
#define  LGCY_VMB_DMAREG2B_5_get_post_inc_sel(data)                              ((0x00000080&(data))>>7)
#define  LGCY_VMB_DMAREG2B_5_get_post_inc(data)                                  (0x0000003F&(data))

#define  LGCY_VMB_DMAREG2B_6                                                     0x1800EF38
#define  LGCY_VMB_DMAREG2B_6_reg_addr                                            "0xB800EF38"
#define  LGCY_VMB_DMAREG2B_6_reg                                                 0xB800EF38
#define  LGCY_VMB_DMAREG2B_6_inst_addr                                           "0x000E"
#define  set_LGCY_VMB_DMAREG2B_6_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_6_reg)=data)
#define  get_LGCY_VMB_DMAREG2B_6_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_6_reg))
#define  LGCY_VMB_DMAREG2B_6_cbcr_vmoffset_shift                                 (23)
#define  LGCY_VMB_DMAREG2B_6_mode_shift                                          (22)
#define  LGCY_VMB_DMAREG2B_6_right_offset_shift                                  (19)
#define  LGCY_VMB_DMAREG2B_6_left_offset_shift                                   (16)
#define  LGCY_VMB_DMAREG2B_6_addr_idx_shift                                      (8)
#define  LGCY_VMB_DMAREG2B_6_post_inc_sel_shift                                  (7)
#define  LGCY_VMB_DMAREG2B_6_post_inc_shift                                      (0)
#define  LGCY_VMB_DMAREG2B_6_cbcr_vmoffset_mask                                  (0x3F800000)
#define  LGCY_VMB_DMAREG2B_6_mode_mask                                           (0x00400000)
#define  LGCY_VMB_DMAREG2B_6_right_offset_mask                                   (0x00380000)
#define  LGCY_VMB_DMAREG2B_6_left_offset_mask                                    (0x00070000)
#define  LGCY_VMB_DMAREG2B_6_addr_idx_mask                                       (0x00007F00)
#define  LGCY_VMB_DMAREG2B_6_post_inc_sel_mask                                   (0x00000080)
#define  LGCY_VMB_DMAREG2B_6_post_inc_mask                                       (0x0000003F)
#define  LGCY_VMB_DMAREG2B_6_cbcr_vmoffset(data)                                 (0x3F800000&((data)<<23))
#define  LGCY_VMB_DMAREG2B_6_mode(data)                                          (0x00400000&((data)<<22))
#define  LGCY_VMB_DMAREG2B_6_right_offset(data)                                  (0x00380000&((data)<<19))
#define  LGCY_VMB_DMAREG2B_6_left_offset(data)                                   (0x00070000&((data)<<16))
#define  LGCY_VMB_DMAREG2B_6_addr_idx(data)                                      (0x00007F00&((data)<<8))
#define  LGCY_VMB_DMAREG2B_6_post_inc_sel(data)                                  (0x00000080&((data)<<7))
#define  LGCY_VMB_DMAREG2B_6_post_inc(data)                                      (0x0000003F&(data))
#define  LGCY_VMB_DMAREG2B_6_get_cbcr_vmoffset(data)                             ((0x3F800000&(data))>>23)
#define  LGCY_VMB_DMAREG2B_6_get_mode(data)                                      ((0x00400000&(data))>>22)
#define  LGCY_VMB_DMAREG2B_6_get_right_offset(data)                              ((0x00380000&(data))>>19)
#define  LGCY_VMB_DMAREG2B_6_get_left_offset(data)                               ((0x00070000&(data))>>16)
#define  LGCY_VMB_DMAREG2B_6_get_addr_idx(data)                                  ((0x00007F00&(data))>>8)
#define  LGCY_VMB_DMAREG2B_6_get_post_inc_sel(data)                              ((0x00000080&(data))>>7)
#define  LGCY_VMB_DMAREG2B_6_get_post_inc(data)                                  (0x0000003F&(data))

#define  LGCY_VMB_DMAREG2B_7                                                     0x1800EF3C
#define  LGCY_VMB_DMAREG2B_7_reg_addr                                            "0xB800EF3C"
#define  LGCY_VMB_DMAREG2B_7_reg                                                 0xB800EF3C
#define  LGCY_VMB_DMAREG2B_7_inst_addr                                           "0x000F"
#define  set_LGCY_VMB_DMAREG2B_7_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_7_reg)=data)
#define  get_LGCY_VMB_DMAREG2B_7_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG2B_7_reg))
#define  LGCY_VMB_DMAREG2B_7_cbcr_vmoffset_shift                                 (23)
#define  LGCY_VMB_DMAREG2B_7_mode_shift                                          (22)
#define  LGCY_VMB_DMAREG2B_7_right_offset_shift                                  (19)
#define  LGCY_VMB_DMAREG2B_7_left_offset_shift                                   (16)
#define  LGCY_VMB_DMAREG2B_7_addr_idx_shift                                      (8)
#define  LGCY_VMB_DMAREG2B_7_post_inc_sel_shift                                  (7)
#define  LGCY_VMB_DMAREG2B_7_post_inc_shift                                      (0)
#define  LGCY_VMB_DMAREG2B_7_cbcr_vmoffset_mask                                  (0x3F800000)
#define  LGCY_VMB_DMAREG2B_7_mode_mask                                           (0x00400000)
#define  LGCY_VMB_DMAREG2B_7_right_offset_mask                                   (0x00380000)
#define  LGCY_VMB_DMAREG2B_7_left_offset_mask                                    (0x00070000)
#define  LGCY_VMB_DMAREG2B_7_addr_idx_mask                                       (0x00007F00)
#define  LGCY_VMB_DMAREG2B_7_post_inc_sel_mask                                   (0x00000080)
#define  LGCY_VMB_DMAREG2B_7_post_inc_mask                                       (0x0000003F)
#define  LGCY_VMB_DMAREG2B_7_cbcr_vmoffset(data)                                 (0x3F800000&((data)<<23))
#define  LGCY_VMB_DMAREG2B_7_mode(data)                                          (0x00400000&((data)<<22))
#define  LGCY_VMB_DMAREG2B_7_right_offset(data)                                  (0x00380000&((data)<<19))
#define  LGCY_VMB_DMAREG2B_7_left_offset(data)                                   (0x00070000&((data)<<16))
#define  LGCY_VMB_DMAREG2B_7_addr_idx(data)                                      (0x00007F00&((data)<<8))
#define  LGCY_VMB_DMAREG2B_7_post_inc_sel(data)                                  (0x00000080&((data)<<7))
#define  LGCY_VMB_DMAREG2B_7_post_inc(data)                                      (0x0000003F&(data))
#define  LGCY_VMB_DMAREG2B_7_get_cbcr_vmoffset(data)                             ((0x3F800000&(data))>>23)
#define  LGCY_VMB_DMAREG2B_7_get_mode(data)                                      ((0x00400000&(data))>>22)
#define  LGCY_VMB_DMAREG2B_7_get_right_offset(data)                              ((0x00380000&(data))>>19)
#define  LGCY_VMB_DMAREG2B_7_get_left_offset(data)                               ((0x00070000&(data))>>16)
#define  LGCY_VMB_DMAREG2B_7_get_addr_idx(data)                                  ((0x00007F00&(data))>>8)
#define  LGCY_VMB_DMAREG2B_7_get_post_inc_sel(data)                              ((0x00000080&(data))>>7)
#define  LGCY_VMB_DMAREG2B_7_get_post_inc(data)                                  (0x0000003F&(data))

#define  LGCY_VMB_DMAREG3B_0                                                     0x1800EF40
#define  LGCY_VMB_DMAREG3B_0_reg_addr                                            "0xB800EF40"
#define  LGCY_VMB_DMAREG3B_0_reg                                                 0xB800EF40
#define  LGCY_VMB_DMAREG3B_0_inst_addr                                           "0x0010"
#define  set_LGCY_VMB_DMAREG3B_0_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_0_reg)=data)
#define  get_LGCY_VMB_DMAREG3B_0_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_0_reg))
#define  LGCY_VMB_DMAREG3B_0_line_off_shift                                      (28)
#define  LGCY_VMB_DMAREG3B_0_vmrowoffset_shift                                   (22)
#define  LGCY_VMB_DMAREG3B_0_vm_addr_shift                                       (12)
#define  LGCY_VMB_DMAREG3B_0_h_shift                                             (6)
#define  LGCY_VMB_DMAREG3B_0_w_shift                                             (0)
#define  LGCY_VMB_DMAREG3B_0_line_off_mask                                       (0x10000000)
#define  LGCY_VMB_DMAREG3B_0_vmrowoffset_mask                                    (0x07C00000)
#define  LGCY_VMB_DMAREG3B_0_vm_addr_mask                                        (0x0007F000)
#define  LGCY_VMB_DMAREG3B_0_h_mask                                              (0x00000FC0)
#define  LGCY_VMB_DMAREG3B_0_w_mask                                              (0x0000003F)
#define  LGCY_VMB_DMAREG3B_0_line_off(data)                                      (0x10000000&((data)<<28))
#define  LGCY_VMB_DMAREG3B_0_vmrowoffset(data)                                   (0x07C00000&((data)<<22))
#define  LGCY_VMB_DMAREG3B_0_vm_addr(data)                                       (0x0007F000&((data)<<12))
#define  LGCY_VMB_DMAREG3B_0_h(data)                                             (0x00000FC0&((data)<<6))
#define  LGCY_VMB_DMAREG3B_0_w(data)                                             (0x0000003F&(data))
#define  LGCY_VMB_DMAREG3B_0_get_line_off(data)                                  ((0x10000000&(data))>>28)
#define  LGCY_VMB_DMAREG3B_0_get_vmrowoffset(data)                               ((0x07C00000&(data))>>22)
#define  LGCY_VMB_DMAREG3B_0_get_vm_addr(data)                                   ((0x0007F000&(data))>>12)
#define  LGCY_VMB_DMAREG3B_0_get_h(data)                                         ((0x00000FC0&(data))>>6)
#define  LGCY_VMB_DMAREG3B_0_get_w(data)                                         (0x0000003F&(data))

#define  LGCY_VMB_DMAREG3B_1                                                     0x1800EF44
#define  LGCY_VMB_DMAREG3B_1_reg_addr                                            "0xB800EF44"
#define  LGCY_VMB_DMAREG3B_1_reg                                                 0xB800EF44
#define  LGCY_VMB_DMAREG3B_1_inst_addr                                           "0x0011"
#define  set_LGCY_VMB_DMAREG3B_1_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_1_reg)=data)
#define  get_LGCY_VMB_DMAREG3B_1_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_1_reg))
#define  LGCY_VMB_DMAREG3B_1_line_off_shift                                      (28)
#define  LGCY_VMB_DMAREG3B_1_vmrowoffset_shift                                   (22)
#define  LGCY_VMB_DMAREG3B_1_vm_addr_shift                                       (12)
#define  LGCY_VMB_DMAREG3B_1_h_shift                                             (6)
#define  LGCY_VMB_DMAREG3B_1_w_shift                                             (0)
#define  LGCY_VMB_DMAREG3B_1_line_off_mask                                       (0x10000000)
#define  LGCY_VMB_DMAREG3B_1_vmrowoffset_mask                                    (0x07C00000)
#define  LGCY_VMB_DMAREG3B_1_vm_addr_mask                                        (0x0007F000)
#define  LGCY_VMB_DMAREG3B_1_h_mask                                              (0x00000FC0)
#define  LGCY_VMB_DMAREG3B_1_w_mask                                              (0x0000003F)
#define  LGCY_VMB_DMAREG3B_1_line_off(data)                                      (0x10000000&((data)<<28))
#define  LGCY_VMB_DMAREG3B_1_vmrowoffset(data)                                   (0x07C00000&((data)<<22))
#define  LGCY_VMB_DMAREG3B_1_vm_addr(data)                                       (0x0007F000&((data)<<12))
#define  LGCY_VMB_DMAREG3B_1_h(data)                                             (0x00000FC0&((data)<<6))
#define  LGCY_VMB_DMAREG3B_1_w(data)                                             (0x0000003F&(data))
#define  LGCY_VMB_DMAREG3B_1_get_line_off(data)                                  ((0x10000000&(data))>>28)
#define  LGCY_VMB_DMAREG3B_1_get_vmrowoffset(data)                               ((0x07C00000&(data))>>22)
#define  LGCY_VMB_DMAREG3B_1_get_vm_addr(data)                                   ((0x0007F000&(data))>>12)
#define  LGCY_VMB_DMAREG3B_1_get_h(data)                                         ((0x00000FC0&(data))>>6)
#define  LGCY_VMB_DMAREG3B_1_get_w(data)                                         (0x0000003F&(data))

#define  LGCY_VMB_DMAREG3B_2                                                     0x1800EF48
#define  LGCY_VMB_DMAREG3B_2_reg_addr                                            "0xB800EF48"
#define  LGCY_VMB_DMAREG3B_2_reg                                                 0xB800EF48
#define  LGCY_VMB_DMAREG3B_2_inst_addr                                           "0x0012"
#define  set_LGCY_VMB_DMAREG3B_2_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_2_reg)=data)
#define  get_LGCY_VMB_DMAREG3B_2_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_2_reg))
#define  LGCY_VMB_DMAREG3B_2_line_off_shift                                      (28)
#define  LGCY_VMB_DMAREG3B_2_vmrowoffset_shift                                   (22)
#define  LGCY_VMB_DMAREG3B_2_vm_addr_shift                                       (12)
#define  LGCY_VMB_DMAREG3B_2_h_shift                                             (6)
#define  LGCY_VMB_DMAREG3B_2_w_shift                                             (0)
#define  LGCY_VMB_DMAREG3B_2_line_off_mask                                       (0x10000000)
#define  LGCY_VMB_DMAREG3B_2_vmrowoffset_mask                                    (0x07C00000)
#define  LGCY_VMB_DMAREG3B_2_vm_addr_mask                                        (0x0007F000)
#define  LGCY_VMB_DMAREG3B_2_h_mask                                              (0x00000FC0)
#define  LGCY_VMB_DMAREG3B_2_w_mask                                              (0x0000003F)
#define  LGCY_VMB_DMAREG3B_2_line_off(data)                                      (0x10000000&((data)<<28))
#define  LGCY_VMB_DMAREG3B_2_vmrowoffset(data)                                   (0x07C00000&((data)<<22))
#define  LGCY_VMB_DMAREG3B_2_vm_addr(data)                                       (0x0007F000&((data)<<12))
#define  LGCY_VMB_DMAREG3B_2_h(data)                                             (0x00000FC0&((data)<<6))
#define  LGCY_VMB_DMAREG3B_2_w(data)                                             (0x0000003F&(data))
#define  LGCY_VMB_DMAREG3B_2_get_line_off(data)                                  ((0x10000000&(data))>>28)
#define  LGCY_VMB_DMAREG3B_2_get_vmrowoffset(data)                               ((0x07C00000&(data))>>22)
#define  LGCY_VMB_DMAREG3B_2_get_vm_addr(data)                                   ((0x0007F000&(data))>>12)
#define  LGCY_VMB_DMAREG3B_2_get_h(data)                                         ((0x00000FC0&(data))>>6)
#define  LGCY_VMB_DMAREG3B_2_get_w(data)                                         (0x0000003F&(data))

#define  LGCY_VMB_DMAREG3B_3                                                     0x1800EF4C
#define  LGCY_VMB_DMAREG3B_3_reg_addr                                            "0xB800EF4C"
#define  LGCY_VMB_DMAREG3B_3_reg                                                 0xB800EF4C
#define  LGCY_VMB_DMAREG3B_3_inst_addr                                           "0x0013"
#define  set_LGCY_VMB_DMAREG3B_3_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_3_reg)=data)
#define  get_LGCY_VMB_DMAREG3B_3_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_3_reg))
#define  LGCY_VMB_DMAREG3B_3_line_off_shift                                      (28)
#define  LGCY_VMB_DMAREG3B_3_vmrowoffset_shift                                   (22)
#define  LGCY_VMB_DMAREG3B_3_vm_addr_shift                                       (12)
#define  LGCY_VMB_DMAREG3B_3_h_shift                                             (6)
#define  LGCY_VMB_DMAREG3B_3_w_shift                                             (0)
#define  LGCY_VMB_DMAREG3B_3_line_off_mask                                       (0x10000000)
#define  LGCY_VMB_DMAREG3B_3_vmrowoffset_mask                                    (0x07C00000)
#define  LGCY_VMB_DMAREG3B_3_vm_addr_mask                                        (0x0007F000)
#define  LGCY_VMB_DMAREG3B_3_h_mask                                              (0x00000FC0)
#define  LGCY_VMB_DMAREG3B_3_w_mask                                              (0x0000003F)
#define  LGCY_VMB_DMAREG3B_3_line_off(data)                                      (0x10000000&((data)<<28))
#define  LGCY_VMB_DMAREG3B_3_vmrowoffset(data)                                   (0x07C00000&((data)<<22))
#define  LGCY_VMB_DMAREG3B_3_vm_addr(data)                                       (0x0007F000&((data)<<12))
#define  LGCY_VMB_DMAREG3B_3_h(data)                                             (0x00000FC0&((data)<<6))
#define  LGCY_VMB_DMAREG3B_3_w(data)                                             (0x0000003F&(data))
#define  LGCY_VMB_DMAREG3B_3_get_line_off(data)                                  ((0x10000000&(data))>>28)
#define  LGCY_VMB_DMAREG3B_3_get_vmrowoffset(data)                               ((0x07C00000&(data))>>22)
#define  LGCY_VMB_DMAREG3B_3_get_vm_addr(data)                                   ((0x0007F000&(data))>>12)
#define  LGCY_VMB_DMAREG3B_3_get_h(data)                                         ((0x00000FC0&(data))>>6)
#define  LGCY_VMB_DMAREG3B_3_get_w(data)                                         (0x0000003F&(data))

#define  LGCY_VMB_DMAREG3B_4                                                     0x1800EF50
#define  LGCY_VMB_DMAREG3B_4_reg_addr                                            "0xB800EF50"
#define  LGCY_VMB_DMAREG3B_4_reg                                                 0xB800EF50
#define  LGCY_VMB_DMAREG3B_4_inst_addr                                           "0x0014"
#define  set_LGCY_VMB_DMAREG3B_4_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_4_reg)=data)
#define  get_LGCY_VMB_DMAREG3B_4_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_4_reg))
#define  LGCY_VMB_DMAREG3B_4_line_off_shift                                      (28)
#define  LGCY_VMB_DMAREG3B_4_vmrowoffset_shift                                   (22)
#define  LGCY_VMB_DMAREG3B_4_vm_addr_shift                                       (12)
#define  LGCY_VMB_DMAREG3B_4_h_shift                                             (6)
#define  LGCY_VMB_DMAREG3B_4_w_shift                                             (0)
#define  LGCY_VMB_DMAREG3B_4_line_off_mask                                       (0x10000000)
#define  LGCY_VMB_DMAREG3B_4_vmrowoffset_mask                                    (0x07C00000)
#define  LGCY_VMB_DMAREG3B_4_vm_addr_mask                                        (0x0007F000)
#define  LGCY_VMB_DMAREG3B_4_h_mask                                              (0x00000FC0)
#define  LGCY_VMB_DMAREG3B_4_w_mask                                              (0x0000003F)
#define  LGCY_VMB_DMAREG3B_4_line_off(data)                                      (0x10000000&((data)<<28))
#define  LGCY_VMB_DMAREG3B_4_vmrowoffset(data)                                   (0x07C00000&((data)<<22))
#define  LGCY_VMB_DMAREG3B_4_vm_addr(data)                                       (0x0007F000&((data)<<12))
#define  LGCY_VMB_DMAREG3B_4_h(data)                                             (0x00000FC0&((data)<<6))
#define  LGCY_VMB_DMAREG3B_4_w(data)                                             (0x0000003F&(data))
#define  LGCY_VMB_DMAREG3B_4_get_line_off(data)                                  ((0x10000000&(data))>>28)
#define  LGCY_VMB_DMAREG3B_4_get_vmrowoffset(data)                               ((0x07C00000&(data))>>22)
#define  LGCY_VMB_DMAREG3B_4_get_vm_addr(data)                                   ((0x0007F000&(data))>>12)
#define  LGCY_VMB_DMAREG3B_4_get_h(data)                                         ((0x00000FC0&(data))>>6)
#define  LGCY_VMB_DMAREG3B_4_get_w(data)                                         (0x0000003F&(data))

#define  LGCY_VMB_DMAREG3B_5                                                     0x1800EF54
#define  LGCY_VMB_DMAREG3B_5_reg_addr                                            "0xB800EF54"
#define  LGCY_VMB_DMAREG3B_5_reg                                                 0xB800EF54
#define  LGCY_VMB_DMAREG3B_5_inst_addr                                           "0x0015"
#define  set_LGCY_VMB_DMAREG3B_5_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_5_reg)=data)
#define  get_LGCY_VMB_DMAREG3B_5_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_5_reg))
#define  LGCY_VMB_DMAREG3B_5_line_off_shift                                      (28)
#define  LGCY_VMB_DMAREG3B_5_vmrowoffset_shift                                   (22)
#define  LGCY_VMB_DMAREG3B_5_vm_addr_shift                                       (12)
#define  LGCY_VMB_DMAREG3B_5_h_shift                                             (6)
#define  LGCY_VMB_DMAREG3B_5_w_shift                                             (0)
#define  LGCY_VMB_DMAREG3B_5_line_off_mask                                       (0x10000000)
#define  LGCY_VMB_DMAREG3B_5_vmrowoffset_mask                                    (0x07C00000)
#define  LGCY_VMB_DMAREG3B_5_vm_addr_mask                                        (0x0007F000)
#define  LGCY_VMB_DMAREG3B_5_h_mask                                              (0x00000FC0)
#define  LGCY_VMB_DMAREG3B_5_w_mask                                              (0x0000003F)
#define  LGCY_VMB_DMAREG3B_5_line_off(data)                                      (0x10000000&((data)<<28))
#define  LGCY_VMB_DMAREG3B_5_vmrowoffset(data)                                   (0x07C00000&((data)<<22))
#define  LGCY_VMB_DMAREG3B_5_vm_addr(data)                                       (0x0007F000&((data)<<12))
#define  LGCY_VMB_DMAREG3B_5_h(data)                                             (0x00000FC0&((data)<<6))
#define  LGCY_VMB_DMAREG3B_5_w(data)                                             (0x0000003F&(data))
#define  LGCY_VMB_DMAREG3B_5_get_line_off(data)                                  ((0x10000000&(data))>>28)
#define  LGCY_VMB_DMAREG3B_5_get_vmrowoffset(data)                               ((0x07C00000&(data))>>22)
#define  LGCY_VMB_DMAREG3B_5_get_vm_addr(data)                                   ((0x0007F000&(data))>>12)
#define  LGCY_VMB_DMAREG3B_5_get_h(data)                                         ((0x00000FC0&(data))>>6)
#define  LGCY_VMB_DMAREG3B_5_get_w(data)                                         (0x0000003F&(data))

#define  LGCY_VMB_DMAREG3B_6                                                     0x1800EF58
#define  LGCY_VMB_DMAREG3B_6_reg_addr                                            "0xB800EF58"
#define  LGCY_VMB_DMAREG3B_6_reg                                                 0xB800EF58
#define  LGCY_VMB_DMAREG3B_6_inst_addr                                           "0x0016"
#define  set_LGCY_VMB_DMAREG3B_6_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_6_reg)=data)
#define  get_LGCY_VMB_DMAREG3B_6_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_6_reg))
#define  LGCY_VMB_DMAREG3B_6_line_off_shift                                      (28)
#define  LGCY_VMB_DMAREG3B_6_vmrowoffset_shift                                   (22)
#define  LGCY_VMB_DMAREG3B_6_vm_addr_shift                                       (12)
#define  LGCY_VMB_DMAREG3B_6_h_shift                                             (6)
#define  LGCY_VMB_DMAREG3B_6_w_shift                                             (0)
#define  LGCY_VMB_DMAREG3B_6_line_off_mask                                       (0x10000000)
#define  LGCY_VMB_DMAREG3B_6_vmrowoffset_mask                                    (0x07C00000)
#define  LGCY_VMB_DMAREG3B_6_vm_addr_mask                                        (0x0007F000)
#define  LGCY_VMB_DMAREG3B_6_h_mask                                              (0x00000FC0)
#define  LGCY_VMB_DMAREG3B_6_w_mask                                              (0x0000003F)
#define  LGCY_VMB_DMAREG3B_6_line_off(data)                                      (0x10000000&((data)<<28))
#define  LGCY_VMB_DMAREG3B_6_vmrowoffset(data)                                   (0x07C00000&((data)<<22))
#define  LGCY_VMB_DMAREG3B_6_vm_addr(data)                                       (0x0007F000&((data)<<12))
#define  LGCY_VMB_DMAREG3B_6_h(data)                                             (0x00000FC0&((data)<<6))
#define  LGCY_VMB_DMAREG3B_6_w(data)                                             (0x0000003F&(data))
#define  LGCY_VMB_DMAREG3B_6_get_line_off(data)                                  ((0x10000000&(data))>>28)
#define  LGCY_VMB_DMAREG3B_6_get_vmrowoffset(data)                               ((0x07C00000&(data))>>22)
#define  LGCY_VMB_DMAREG3B_6_get_vm_addr(data)                                   ((0x0007F000&(data))>>12)
#define  LGCY_VMB_DMAREG3B_6_get_h(data)                                         ((0x00000FC0&(data))>>6)
#define  LGCY_VMB_DMAREG3B_6_get_w(data)                                         (0x0000003F&(data))

#define  LGCY_VMB_DMAREG3B_7                                                     0x1800EF5C
#define  LGCY_VMB_DMAREG3B_7_reg_addr                                            "0xB800EF5C"
#define  LGCY_VMB_DMAREG3B_7_reg                                                 0xB800EF5C
#define  LGCY_VMB_DMAREG3B_7_inst_addr                                           "0x0017"
#define  set_LGCY_VMB_DMAREG3B_7_reg(data)                                       (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_7_reg)=data)
#define  get_LGCY_VMB_DMAREG3B_7_reg                                             (*((volatile unsigned int*)LGCY_VMB_DMAREG3B_7_reg))
#define  LGCY_VMB_DMAREG3B_7_line_off_shift                                      (28)
#define  LGCY_VMB_DMAREG3B_7_vmrowoffset_shift                                   (22)
#define  LGCY_VMB_DMAREG3B_7_vm_addr_shift                                       (12)
#define  LGCY_VMB_DMAREG3B_7_h_shift                                             (6)
#define  LGCY_VMB_DMAREG3B_7_w_shift                                             (0)
#define  LGCY_VMB_DMAREG3B_7_line_off_mask                                       (0x10000000)
#define  LGCY_VMB_DMAREG3B_7_vmrowoffset_mask                                    (0x07C00000)
#define  LGCY_VMB_DMAREG3B_7_vm_addr_mask                                        (0x0007F000)
#define  LGCY_VMB_DMAREG3B_7_h_mask                                              (0x00000FC0)
#define  LGCY_VMB_DMAREG3B_7_w_mask                                              (0x0000003F)
#define  LGCY_VMB_DMAREG3B_7_line_off(data)                                      (0x10000000&((data)<<28))
#define  LGCY_VMB_DMAREG3B_7_vmrowoffset(data)                                   (0x07C00000&((data)<<22))
#define  LGCY_VMB_DMAREG3B_7_vm_addr(data)                                       (0x0007F000&((data)<<12))
#define  LGCY_VMB_DMAREG3B_7_h(data)                                             (0x00000FC0&((data)<<6))
#define  LGCY_VMB_DMAREG3B_7_w(data)                                             (0x0000003F&(data))
#define  LGCY_VMB_DMAREG3B_7_get_line_off(data)                                  ((0x10000000&(data))>>28)
#define  LGCY_VMB_DMAREG3B_7_get_vmrowoffset(data)                               ((0x07C00000&(data))>>22)
#define  LGCY_VMB_DMAREG3B_7_get_vm_addr(data)                                   ((0x0007F000&(data))>>12)
#define  LGCY_VMB_DMAREG3B_7_get_h(data)                                         ((0x00000FC0&(data))>>6)
#define  LGCY_VMB_DMAREG3B_7_get_w(data)                                         (0x0000003F&(data))

#define  LGCY_VMB_SDMACNTLB                                                      0x1800EF60
#define  LGCY_VMB_SDMACNTLB_reg_addr                                             "0xB800EF60"
#define  LGCY_VMB_SDMACNTLB_reg                                                  0xB800EF60
#define  LGCY_VMB_SDMACNTLB_inst_addr                                            "0x0018"
#define  set_LGCY_VMB_SDMACNTLB_reg(data)                                        (*((volatile unsigned int*)LGCY_VMB_SDMACNTLB_reg)=data)
#define  get_LGCY_VMB_SDMACNTLB_reg                                              (*((volatile unsigned int*)LGCY_VMB_SDMACNTLB_reg))
#define  LGCY_VMB_SDMACNTLB_seq_vmem_addr_shift                                  (16)
#define  LGCY_VMB_SDMACNTLB_seq_xsfr_size_shift                                  (0)
#define  LGCY_VMB_SDMACNTLB_seq_vmem_addr_mask                                   (0x1FFF0000)
#define  LGCY_VMB_SDMACNTLB_seq_xsfr_size_mask                                   (0x000001FF)
#define  LGCY_VMB_SDMACNTLB_seq_vmem_addr(data)                                  (0x1FFF0000&((data)<<16))
#define  LGCY_VMB_SDMACNTLB_seq_xsfr_size(data)                                  (0x000001FF&(data))
#define  LGCY_VMB_SDMACNTLB_get_seq_vmem_addr(data)                              ((0x1FFF0000&(data))>>16)
#define  LGCY_VMB_SDMACNTLB_get_seq_xsfr_size(data)                              (0x000001FF&(data))

#define  LGCY_VMB_SDMAADRB                                                       0x1800EF64
#define  LGCY_VMB_SDMAADRB_reg_addr                                              "0xB800EF64"
#define  LGCY_VMB_SDMAADRB_reg                                                   0xB800EF64
#define  LGCY_VMB_SDMAADRB_inst_addr                                             "0x0019"
#define  set_LGCY_VMB_SDMAADRB_reg(data)                                         (*((volatile unsigned int*)LGCY_VMB_SDMAADRB_reg)=data)
#define  get_LGCY_VMB_SDMAADRB_reg                                               (*((volatile unsigned int*)LGCY_VMB_SDMAADRB_reg))
#define  LGCY_VMB_SDMAADRB_seq_line_addr_shift                                   (0)
#define  LGCY_VMB_SDMAADRB_seq_line_addr_mask                                    (0xFFFFFFFF)
#define  LGCY_VMB_SDMAADRB_seq_line_addr(data)                                   (0xFFFFFFFF&(data))
#define  LGCY_VMB_SDMAADRB_get_seq_line_addr(data)                               (0xFFFFFFFF&(data))

#define  LGCY_VMB_DMACTLB                                                        0x1800EF68
#define  LGCY_VMB_DMACTLB_reg_addr                                               "0xB800EF68"
#define  LGCY_VMB_DMACTLB_reg                                                    0xB800EF68
#define  LGCY_VMB_DMACTLB_inst_addr                                              "0x001A"
#define  set_LGCY_VMB_DMACTLB_reg(data)                                          (*((volatile unsigned int*)LGCY_VMB_DMACTLB_reg)=data)
#define  get_LGCY_VMB_DMACTLB_reg                                                (*((volatile unsigned int*)LGCY_VMB_DMACTLB_reg))
#define  LGCY_VMB_DMACTLB_write_enable1_shift                                    (1)
#define  LGCY_VMB_DMACTLB_post_write_disable_shift                               (0)
#define  LGCY_VMB_DMACTLB_write_enable1_mask                                     (0x00000002)
#define  LGCY_VMB_DMACTLB_post_write_disable_mask                                (0x00000001)
#define  LGCY_VMB_DMACTLB_write_enable1(data)                                    (0x00000002&((data)<<1))
#define  LGCY_VMB_DMACTLB_post_write_disable(data)                               (0x00000001&(data))
#define  LGCY_VMB_DMACTLB_get_write_enable1(data)                                ((0x00000002&(data))>>1)
#define  LGCY_VMB_DMACTLB_get_post_write_disable(data)                           (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGCY_VMB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  x:13;
        RBus_UInt32  y:14;
    };
}lgcy_vmb_dmareg1b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cbcr_vmoffset:7;
        RBus_UInt32  mode:1;
        RBus_UInt32  right_offset:3;
        RBus_UInt32  left_offset:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  addr_idx:7;
        RBus_UInt32  post_inc_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  post_inc:6;
    };
}lgcy_vmb_dmareg2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  line_off:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vmrowoffset:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vm_addr:7;
        RBus_UInt32  h:6;
        RBus_UInt32  w:6;
    };
}lgcy_vmb_dmareg3b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  seq_vmem_addr:13;
        RBus_UInt32  res2:7;
        RBus_UInt32  seq_xsfr_size:9;
    };
}lgcy_vmb_sdmacntlb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:32;
    };
}lgcy_vmb_sdmaadrb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  post_write_disable:1;
    };
}lgcy_vmb_dmactlb_RBUS;

#else //apply LITTLE_ENDIAN

//======LGCY_VMB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:14;
        RBus_UInt32  x:13;
        RBus_UInt32  res1:5;
    };
}lgcy_vmb_dmareg1b_RBUS;

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
        RBus_UInt32  cbcr_vmoffset:7;
        RBus_UInt32  res3:2;
    };
}lgcy_vmb_dmareg2b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w:6;
        RBus_UInt32  h:6;
        RBus_UInt32  vm_addr:7;
        RBus_UInt32  res1:3;
        RBus_UInt32  vmrowoffset:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  line_off:1;
        RBus_UInt32  res3:3;
    };
}lgcy_vmb_dmareg3b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_xsfr_size:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  seq_vmem_addr:13;
        RBus_UInt32  res2:3;
    };
}lgcy_vmb_sdmacntlb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:32;
    };
}lgcy_vmb_sdmaadrb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  post_write_disable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res1:30;
    };
}lgcy_vmb_dmactlb_RBUS;




#endif 


#endif 
