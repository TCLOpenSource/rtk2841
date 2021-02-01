/**
* @file Mac5-DesignSpec-D-Domain_rgbw
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_RGBW_REG_H_
#define _RBUS_RGBW_REG_H_

#include "rbus_types.h"



//  RGBW Register Address
#define  RGBW_D_RGBW_PATGEN_CTL_0                                                0x1802E7C0
#define  RGBW_D_RGBW_PATGEN_CTL_0_reg_addr                                       "0xB802E7C0"
#define  RGBW_D_RGBW_PATGEN_CTL_0_reg                                            0xB802E7C0
#define  RGBW_D_RGBW_PATGEN_CTL_0_inst_addr                                      "0x0000"
#define  set_RGBW_D_RGBW_PATGEN_CTL_0_reg(data)                                  (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_CTL_0_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_CTL_0_reg                                        (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_CTL_0_reg))
#define  RGBW_D_RGBW_PATGEN_CTL_0_patgen_en_shift                                (31)
#define  RGBW_D_RGBW_PATGEN_CTL_0_patgen_ch_num_shift                            (30)
#define  RGBW_D_RGBW_PATGEN_CTL_0_patgen_width_shift                             (0)
#define  RGBW_D_RGBW_PATGEN_CTL_0_patgen_en_mask                                 (0x80000000)
#define  RGBW_D_RGBW_PATGEN_CTL_0_patgen_ch_num_mask                             (0x40000000)
#define  RGBW_D_RGBW_PATGEN_CTL_0_patgen_width_mask                              (0x003FFFFF)
#define  RGBW_D_RGBW_PATGEN_CTL_0_patgen_en(data)                                (0x80000000&((data)<<31))
#define  RGBW_D_RGBW_PATGEN_CTL_0_patgen_ch_num(data)                            (0x40000000&((data)<<30))
#define  RGBW_D_RGBW_PATGEN_CTL_0_patgen_width(data)                             (0x003FFFFF&(data))
#define  RGBW_D_RGBW_PATGEN_CTL_0_get_patgen_en(data)                            ((0x80000000&(data))>>31)
#define  RGBW_D_RGBW_PATGEN_CTL_0_get_patgen_ch_num(data)                        ((0x40000000&(data))>>30)
#define  RGBW_D_RGBW_PATGEN_CTL_0_get_patgen_width(data)                         (0x003FFFFF&(data))

#define  RGBW_D_RGBW_PATGEN_CTL_1                                                0x1802E7C4
#define  RGBW_D_RGBW_PATGEN_CTL_1_reg_addr                                       "0xB802E7C4"
#define  RGBW_D_RGBW_PATGEN_CTL_1_reg                                            0xB802E7C4
#define  RGBW_D_RGBW_PATGEN_CTL_1_inst_addr                                      "0x0001"
#define  set_RGBW_D_RGBW_PATGEN_CTL_1_reg(data)                                  (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_CTL_1_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_CTL_1_reg                                        (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_CTL_1_reg))
#define  RGBW_D_RGBW_PATGEN_CTL_1_dummy_31_16_shift                              (16)
#define  RGBW_D_RGBW_PATGEN_CTL_1_dummy_31_16_mask                               (0xFFFF0000)
#define  RGBW_D_RGBW_PATGEN_CTL_1_dummy_31_16(data)                              (0xFFFF0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_CTL_1_get_dummy_31_16(data)                          ((0xFFFF0000&(data))>>16)

#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M                                           0x1802E7C8
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_reg_addr                                  "0xB802E7C8"
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_reg                                       0xB802E7C8
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_inst_addr                                 "0x0002"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C0_M_reg(data)                             (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C0_M_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C0_M_reg                                   (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C0_M_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_patgen_c0_b_msb_shift                     (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_patgen_c0_g_msb_shift                     (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_patgen_c0_r_msb_shift                     (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_patgen_c0_b_msb_mask                      (0x00FF0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_patgen_c0_g_msb_mask                      (0x0000FF00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_patgen_c0_r_msb_mask                      (0x000000FF)
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_patgen_c0_b_msb(data)                     (0x00FF0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_patgen_c0_g_msb(data)                     (0x0000FF00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_patgen_c0_r_msb(data)                     (0x000000FF&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_get_patgen_c0_b_msb(data)                 ((0x00FF0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_get_patgen_c0_g_msb(data)                 ((0x0000FF00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C0_M_get_patgen_c0_r_msb(data)                 (0x000000FF&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M                                           0x1802E7CC
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_reg_addr                                  "0xB802E7CC"
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_reg                                       0xB802E7CC
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_inst_addr                                 "0x0003"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C1_M_reg(data)                             (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C1_M_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C1_M_reg                                   (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C1_M_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_patgen_c1_b_msb_shift                     (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_patgen_c1_g_msb_shift                     (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_patgen_c1_r_msb_shift                     (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_patgen_c1_b_msb_mask                      (0x00FF0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_patgen_c1_g_msb_mask                      (0x0000FF00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_patgen_c1_r_msb_mask                      (0x000000FF)
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_patgen_c1_b_msb(data)                     (0x00FF0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_patgen_c1_g_msb(data)                     (0x0000FF00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_patgen_c1_r_msb(data)                     (0x000000FF&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_get_patgen_c1_b_msb(data)                 ((0x00FF0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_get_patgen_c1_g_msb(data)                 ((0x0000FF00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C1_M_get_patgen_c1_r_msb(data)                 (0x000000FF&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L                                          0x1802E7D0
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_reg_addr                                 "0xB802E7D0"
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_reg                                      0xB802E7D0
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_inst_addr                                "0x0004"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C01_L_reg(data)                            (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C01_L_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C01_L_reg                                  (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C01_L_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c0_b_lsb_shift                    (24)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c0_g_lsb_shift                    (20)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c0_r_lsb_shift                    (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c1_b_lsb_shift                    (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c1_g_lsb_shift                    (4)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c1_r_lsb_shift                    (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c0_b_lsb_mask                     (0x0F000000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c0_g_lsb_mask                     (0x00F00000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c0_r_lsb_mask                     (0x000F0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c1_b_lsb_mask                     (0x00000F00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c1_g_lsb_mask                     (0x000000F0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c1_r_lsb_mask                     (0x0000000F)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c0_b_lsb(data)                    (0x0F000000&((data)<<24))
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c0_g_lsb(data)                    (0x00F00000&((data)<<20))
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c0_r_lsb(data)                    (0x000F0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c1_b_lsb(data)                    (0x00000F00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c1_g_lsb(data)                    (0x000000F0&((data)<<4))
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_patgen_c1_r_lsb(data)                    (0x0000000F&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_get_patgen_c0_b_lsb(data)                ((0x0F000000&(data))>>24)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_get_patgen_c0_g_lsb(data)                ((0x00F00000&(data))>>20)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_get_patgen_c0_r_lsb(data)                ((0x000F0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_get_patgen_c1_b_lsb(data)                ((0x00000F00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_get_patgen_c1_g_lsb(data)                ((0x000000F0&(data))>>4)
#define  RGBW_D_RGBW_PATGEN_COLOR_C01_L_get_patgen_c1_r_lsb(data)                (0x0000000F&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M                                           0x1802E7D4
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_reg_addr                                  "0xB802E7D4"
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_reg                                       0xB802E7D4
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_inst_addr                                 "0x0005"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C2_M_reg(data)                             (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C2_M_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C2_M_reg                                   (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C2_M_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_patgen_c2_b_msb_shift                     (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_patgen_c2_g_msb_shift                     (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_patgen_c2_r_msb_shift                     (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_patgen_c2_b_msb_mask                      (0x00FF0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_patgen_c2_g_msb_mask                      (0x0000FF00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_patgen_c2_r_msb_mask                      (0x000000FF)
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_patgen_c2_b_msb(data)                     (0x00FF0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_patgen_c2_g_msb(data)                     (0x0000FF00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_patgen_c2_r_msb(data)                     (0x000000FF&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_get_patgen_c2_b_msb(data)                 ((0x00FF0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_get_patgen_c2_g_msb(data)                 ((0x0000FF00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C2_M_get_patgen_c2_r_msb(data)                 (0x000000FF&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M                                           0x1802E7D8
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_reg_addr                                  "0xB802E7D8"
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_reg                                       0xB802E7D8
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_inst_addr                                 "0x0006"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C3_M_reg(data)                             (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C3_M_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C3_M_reg                                   (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C3_M_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_patgen_c3_b_msb_shift                     (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_patgen_c3_g_msb_shift                     (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_patgen_c3_r_msb_shift                     (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_patgen_c3_b_msb_mask                      (0x00FF0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_patgen_c3_g_msb_mask                      (0x0000FF00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_patgen_c3_r_msb_mask                      (0x000000FF)
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_patgen_c3_b_msb(data)                     (0x00FF0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_patgen_c3_g_msb(data)                     (0x0000FF00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_patgen_c3_r_msb(data)                     (0x000000FF&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_get_patgen_c3_b_msb(data)                 ((0x00FF0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_get_patgen_c3_g_msb(data)                 ((0x0000FF00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C3_M_get_patgen_c3_r_msb(data)                 (0x000000FF&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L                                          0x1802E7DC
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_reg_addr                                 "0xB802E7DC"
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_reg                                      0xB802E7DC
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_inst_addr                                "0x0007"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C23_L_reg(data)                            (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C23_L_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C23_L_reg                                  (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C23_L_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c2_b_lsb_shift                    (24)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c2_g_lsb_shift                    (20)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c2_r_lsb_shift                    (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c3_b_lsb_shift                    (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c3_g_lsb_shift                    (4)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c3_r_lsb_shift                    (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c2_b_lsb_mask                     (0x0F000000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c2_g_lsb_mask                     (0x00F00000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c2_r_lsb_mask                     (0x000F0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c3_b_lsb_mask                     (0x00000F00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c3_g_lsb_mask                     (0x000000F0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c3_r_lsb_mask                     (0x0000000F)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c2_b_lsb(data)                    (0x0F000000&((data)<<24))
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c2_g_lsb(data)                    (0x00F00000&((data)<<20))
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c2_r_lsb(data)                    (0x000F0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c3_b_lsb(data)                    (0x00000F00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c3_g_lsb(data)                    (0x000000F0&((data)<<4))
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_patgen_c3_r_lsb(data)                    (0x0000000F&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_get_patgen_c2_b_lsb(data)                ((0x0F000000&(data))>>24)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_get_patgen_c2_g_lsb(data)                ((0x00F00000&(data))>>20)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_get_patgen_c2_r_lsb(data)                ((0x000F0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_get_patgen_c3_b_lsb(data)                ((0x00000F00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_get_patgen_c3_g_lsb(data)                ((0x000000F0&(data))>>4)
#define  RGBW_D_RGBW_PATGEN_COLOR_C23_L_get_patgen_c3_r_lsb(data)                (0x0000000F&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M                                           0x1802E7E0
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_reg_addr                                  "0xB802E7E0"
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_reg                                       0xB802E7E0
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_inst_addr                                 "0x0008"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C4_M_reg(data)                             (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C4_M_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C4_M_reg                                   (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C4_M_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_patgen_c4_b_msb_shift                     (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_patgen_c4_g_msb_shift                     (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_patgen_c4_r_msb_shift                     (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_patgen_c4_b_msb_mask                      (0x00FF0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_patgen_c4_g_msb_mask                      (0x0000FF00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_patgen_c4_r_msb_mask                      (0x000000FF)
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_patgen_c4_b_msb(data)                     (0x00FF0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_patgen_c4_g_msb(data)                     (0x0000FF00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_patgen_c4_r_msb(data)                     (0x000000FF&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_get_patgen_c4_b_msb(data)                 ((0x00FF0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_get_patgen_c4_g_msb(data)                 ((0x0000FF00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C4_M_get_patgen_c4_r_msb(data)                 (0x000000FF&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M                                           0x1802E7E4
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_reg_addr                                  "0xB802E7E4"
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_reg                                       0xB802E7E4
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_inst_addr                                 "0x0009"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C5_M_reg(data)                             (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C5_M_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C5_M_reg                                   (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C5_M_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_patgen_c5_b_msb_shift                     (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_patgen_c5_g_msb_shift                     (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_patgen_c5_r_msb_shift                     (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_patgen_c5_b_msb_mask                      (0x00FF0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_patgen_c5_g_msb_mask                      (0x0000FF00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_patgen_c5_r_msb_mask                      (0x000000FF)
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_patgen_c5_b_msb(data)                     (0x00FF0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_patgen_c5_g_msb(data)                     (0x0000FF00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_patgen_c5_r_msb(data)                     (0x000000FF&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_get_patgen_c5_b_msb(data)                 ((0x00FF0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_get_patgen_c5_g_msb(data)                 ((0x0000FF00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C5_M_get_patgen_c5_r_msb(data)                 (0x000000FF&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L                                          0x1802E7E8
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_reg_addr                                 "0xB802E7E8"
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_reg                                      0xB802E7E8
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_inst_addr                                "0x000A"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C45_L_reg(data)                            (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C45_L_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C45_L_reg                                  (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C45_L_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c4_b_lsb_shift                    (24)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c4_g_lsb_shift                    (20)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c4_r_lsb_shift                    (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c5_b_lsb_shift                    (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c5_g_lsb_shift                    (4)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c5_r_lsb_shift                    (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c4_b_lsb_mask                     (0x0F000000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c4_g_lsb_mask                     (0x00F00000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c4_r_lsb_mask                     (0x000F0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c5_b_lsb_mask                     (0x00000F00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c5_g_lsb_mask                     (0x000000F0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c5_r_lsb_mask                     (0x0000000F)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c4_b_lsb(data)                    (0x0F000000&((data)<<24))
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c4_g_lsb(data)                    (0x00F00000&((data)<<20))
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c4_r_lsb(data)                    (0x000F0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c5_b_lsb(data)                    (0x00000F00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c5_g_lsb(data)                    (0x000000F0&((data)<<4))
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_patgen_c5_r_lsb(data)                    (0x0000000F&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_get_patgen_c4_b_lsb(data)                ((0x0F000000&(data))>>24)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_get_patgen_c4_g_lsb(data)                ((0x00F00000&(data))>>20)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_get_patgen_c4_r_lsb(data)                ((0x000F0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_get_patgen_c5_b_lsb(data)                ((0x00000F00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_get_patgen_c5_g_lsb(data)                ((0x000000F0&(data))>>4)
#define  RGBW_D_RGBW_PATGEN_COLOR_C45_L_get_patgen_c5_r_lsb(data)                (0x0000000F&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M                                           0x1802E7EC
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_reg_addr                                  "0xB802E7EC"
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_reg                                       0xB802E7EC
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_inst_addr                                 "0x000B"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C6_M_reg(data)                             (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C6_M_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C6_M_reg                                   (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C6_M_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_patgen_c6_b_msb_shift                     (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_patgen_c6_g_msb_shift                     (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_patgen_c6_r_msb_shift                     (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_patgen_c6_b_msb_mask                      (0x00FF0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_patgen_c6_g_msb_mask                      (0x0000FF00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_patgen_c6_r_msb_mask                      (0x000000FF)
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_patgen_c6_b_msb(data)                     (0x00FF0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_patgen_c6_g_msb(data)                     (0x0000FF00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_patgen_c6_r_msb(data)                     (0x000000FF&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_get_patgen_c6_b_msb(data)                 ((0x00FF0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_get_patgen_c6_g_msb(data)                 ((0x0000FF00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C6_M_get_patgen_c6_r_msb(data)                 (0x000000FF&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M                                           0x1802E7F0
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_reg_addr                                  "0xB802E7F0"
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_reg                                       0xB802E7F0
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_inst_addr                                 "0x000C"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C7_M_reg(data)                             (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C7_M_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C7_M_reg                                   (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C7_M_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_patgen_c7_b_msb_shift                     (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_patgen_c7_g_msb_shift                     (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_patgen_c7_r_msb_shift                     (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_patgen_c7_b_msb_mask                      (0x00FF0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_patgen_c7_g_msb_mask                      (0x0000FF00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_patgen_c7_r_msb_mask                      (0x000000FF)
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_patgen_c7_b_msb(data)                     (0x00FF0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_patgen_c7_g_msb(data)                     (0x0000FF00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_patgen_c7_r_msb(data)                     (0x000000FF&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_get_patgen_c7_b_msb(data)                 ((0x00FF0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_get_patgen_c7_g_msb(data)                 ((0x0000FF00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C7_M_get_patgen_c7_r_msb(data)                 (0x000000FF&(data))

#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L                                          0x1802E7F4
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_reg_addr                                 "0xB802E7F4"
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_reg                                      0xB802E7F4
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_inst_addr                                "0x000D"
#define  set_RGBW_D_RGBW_PATGEN_COLOR_C67_L_reg(data)                            (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C67_L_reg)=data)
#define  get_RGBW_D_RGBW_PATGEN_COLOR_C67_L_reg                                  (*((volatile unsigned int*)RGBW_D_RGBW_PATGEN_COLOR_C67_L_reg))
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c6_b_lsb_shift                    (24)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c6_g_lsb_shift                    (20)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c6_r_lsb_shift                    (16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c7_b_lsb_shift                    (8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c7_g_lsb_shift                    (4)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c7_r_lsb_shift                    (0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c6_b_lsb_mask                     (0x0F000000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c6_g_lsb_mask                     (0x00F00000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c6_r_lsb_mask                     (0x000F0000)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c7_b_lsb_mask                     (0x00000F00)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c7_g_lsb_mask                     (0x000000F0)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c7_r_lsb_mask                     (0x0000000F)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c6_b_lsb(data)                    (0x0F000000&((data)<<24))
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c6_g_lsb(data)                    (0x00F00000&((data)<<20))
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c6_r_lsb(data)                    (0x000F0000&((data)<<16))
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c7_b_lsb(data)                    (0x00000F00&((data)<<8))
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c7_g_lsb(data)                    (0x000000F0&((data)<<4))
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_patgen_c7_r_lsb(data)                    (0x0000000F&(data))
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_get_patgen_c6_b_lsb(data)                ((0x0F000000&(data))>>24)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_get_patgen_c6_g_lsb(data)                ((0x00F00000&(data))>>20)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_get_patgen_c6_r_lsb(data)                ((0x000F0000&(data))>>16)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_get_patgen_c7_b_lsb(data)                ((0x00000F00&(data))>>8)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_get_patgen_c7_g_lsb(data)                ((0x000000F0&(data))>>4)
#define  RGBW_D_RGBW_PATGEN_COLOR_C67_L_get_patgen_c7_r_lsb(data)                (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======RGBW register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_en:1;
        RBus_UInt32  patgen_ch_num:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_width:22;
    };
}rgbw_d_rgbw_patgen_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e7c4_31_16:16;
        RBus_UInt32  res1:16;
    };
}rgbw_d_rgbw_patgen_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c0_b_msb:8;
        RBus_UInt32  patgen_c0_g_msb:8;
        RBus_UInt32  patgen_c0_r_msb:8;
    };
}rgbw_d_rgbw_patgen_color_c0_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c1_b_msb:8;
        RBus_UInt32  patgen_c1_g_msb:8;
        RBus_UInt32  patgen_c1_r_msb:8;
    };
}rgbw_d_rgbw_patgen_color_c1_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  patgen_c0_b_lsb:4;
        RBus_UInt32  patgen_c0_g_lsb:4;
        RBus_UInt32  patgen_c0_r_lsb:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  patgen_c1_b_lsb:4;
        RBus_UInt32  patgen_c1_g_lsb:4;
        RBus_UInt32  patgen_c1_r_lsb:4;
    };
}rgbw_d_rgbw_patgen_color_c01_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c2_b_msb:8;
        RBus_UInt32  patgen_c2_g_msb:8;
        RBus_UInt32  patgen_c2_r_msb:8;
    };
}rgbw_d_rgbw_patgen_color_c2_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c3_b_msb:8;
        RBus_UInt32  patgen_c3_g_msb:8;
        RBus_UInt32  patgen_c3_r_msb:8;
    };
}rgbw_d_rgbw_patgen_color_c3_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  patgen_c2_b_lsb:4;
        RBus_UInt32  patgen_c2_g_lsb:4;
        RBus_UInt32  patgen_c2_r_lsb:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  patgen_c3_b_lsb:4;
        RBus_UInt32  patgen_c3_g_lsb:4;
        RBus_UInt32  patgen_c3_r_lsb:4;
    };
}rgbw_d_rgbw_patgen_color_c23_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c4_b_msb:8;
        RBus_UInt32  patgen_c4_g_msb:8;
        RBus_UInt32  patgen_c4_r_msb:8;
    };
}rgbw_d_rgbw_patgen_color_c4_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c5_b_msb:8;
        RBus_UInt32  patgen_c5_g_msb:8;
        RBus_UInt32  patgen_c5_r_msb:8;
    };
}rgbw_d_rgbw_patgen_color_c5_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  patgen_c4_b_lsb:4;
        RBus_UInt32  patgen_c4_g_lsb:4;
        RBus_UInt32  patgen_c4_r_lsb:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  patgen_c5_b_lsb:4;
        RBus_UInt32  patgen_c5_g_lsb:4;
        RBus_UInt32  patgen_c5_r_lsb:4;
    };
}rgbw_d_rgbw_patgen_color_c45_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c6_b_msb:8;
        RBus_UInt32  patgen_c6_g_msb:8;
        RBus_UInt32  patgen_c6_r_msb:8;
    };
}rgbw_d_rgbw_patgen_color_c6_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c7_b_msb:8;
        RBus_UInt32  patgen_c7_g_msb:8;
        RBus_UInt32  patgen_c7_r_msb:8;
    };
}rgbw_d_rgbw_patgen_color_c7_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  patgen_c6_b_lsb:4;
        RBus_UInt32  patgen_c6_g_lsb:4;
        RBus_UInt32  patgen_c6_r_lsb:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  patgen_c7_b_lsb:4;
        RBus_UInt32  patgen_c7_g_lsb:4;
        RBus_UInt32  patgen_c7_r_lsb:4;
    };
}rgbw_d_rgbw_patgen_color_c67_l_RBUS;

#else //apply LITTLE_ENDIAN

//======RGBW register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width:22;
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_ch_num:1;
        RBus_UInt32  patgen_en:1;
    };
}rgbw_d_rgbw_patgen_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dummy1802e7c4_31_16:16;
    };
}rgbw_d_rgbw_patgen_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c0_r_msb:8;
        RBus_UInt32  patgen_c0_g_msb:8;
        RBus_UInt32  patgen_c0_b_msb:8;
        RBus_UInt32  res1:8;
    };
}rgbw_d_rgbw_patgen_color_c0_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c1_r_msb:8;
        RBus_UInt32  patgen_c1_g_msb:8;
        RBus_UInt32  patgen_c1_b_msb:8;
        RBus_UInt32  res1:8;
    };
}rgbw_d_rgbw_patgen_color_c1_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c1_r_lsb:4;
        RBus_UInt32  patgen_c1_g_lsb:4;
        RBus_UInt32  patgen_c1_b_lsb:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  patgen_c0_r_lsb:4;
        RBus_UInt32  patgen_c0_g_lsb:4;
        RBus_UInt32  patgen_c0_b_lsb:4;
        RBus_UInt32  res2:4;
    };
}rgbw_d_rgbw_patgen_color_c01_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c2_r_msb:8;
        RBus_UInt32  patgen_c2_g_msb:8;
        RBus_UInt32  patgen_c2_b_msb:8;
        RBus_UInt32  res1:8;
    };
}rgbw_d_rgbw_patgen_color_c2_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c3_r_msb:8;
        RBus_UInt32  patgen_c3_g_msb:8;
        RBus_UInt32  patgen_c3_b_msb:8;
        RBus_UInt32  res1:8;
    };
}rgbw_d_rgbw_patgen_color_c3_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c3_r_lsb:4;
        RBus_UInt32  patgen_c3_g_lsb:4;
        RBus_UInt32  patgen_c3_b_lsb:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  patgen_c2_r_lsb:4;
        RBus_UInt32  patgen_c2_g_lsb:4;
        RBus_UInt32  patgen_c2_b_lsb:4;
        RBus_UInt32  res2:4;
    };
}rgbw_d_rgbw_patgen_color_c23_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c4_r_msb:8;
        RBus_UInt32  patgen_c4_g_msb:8;
        RBus_UInt32  patgen_c4_b_msb:8;
        RBus_UInt32  res1:8;
    };
}rgbw_d_rgbw_patgen_color_c4_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c5_r_msb:8;
        RBus_UInt32  patgen_c5_g_msb:8;
        RBus_UInt32  patgen_c5_b_msb:8;
        RBus_UInt32  res1:8;
    };
}rgbw_d_rgbw_patgen_color_c5_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c5_r_lsb:4;
        RBus_UInt32  patgen_c5_g_lsb:4;
        RBus_UInt32  patgen_c5_b_lsb:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  patgen_c4_r_lsb:4;
        RBus_UInt32  patgen_c4_g_lsb:4;
        RBus_UInt32  patgen_c4_b_lsb:4;
        RBus_UInt32  res2:4;
    };
}rgbw_d_rgbw_patgen_color_c45_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c6_r_msb:8;
        RBus_UInt32  patgen_c6_g_msb:8;
        RBus_UInt32  patgen_c6_b_msb:8;
        RBus_UInt32  res1:8;
    };
}rgbw_d_rgbw_patgen_color_c6_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c7_r_msb:8;
        RBus_UInt32  patgen_c7_g_msb:8;
        RBus_UInt32  patgen_c7_b_msb:8;
        RBus_UInt32  res1:8;
    };
}rgbw_d_rgbw_patgen_color_c7_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c7_r_lsb:4;
        RBus_UInt32  patgen_c7_g_lsb:4;
        RBus_UInt32  patgen_c7_b_lsb:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  patgen_c6_r_lsb:4;
        RBus_UInt32  patgen_c6_g_lsb:4;
        RBus_UInt32  patgen_c6_b_lsb:4;
        RBus_UInt32  res2:4;
    };
}rgbw_d_rgbw_patgen_color_c67_l_RBUS;




#endif 


#endif 
