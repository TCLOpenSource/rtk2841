/**
* @file MacArthur5-DesignSpec-I-Domain_VGIP
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SUB_VGIP_PTG_REG_H_
#define _RBUS_SUB_VGIP_PTG_REG_H_

#include "rbus_types.h"



//  SUB_VGIP_PTG Register Address
#define  SUB_VGIP_PTG_CH2_PTG_CTRL                                               0x180227C0
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_reg_addr                                      "0xB80227C0"
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_reg                                           0xB80227C0
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_inst_addr                                     "0x0000"
#define  set_SUB_VGIP_PTG_CH2_PTG_CTRL_reg(data)                                 (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_CTRL_reg)=data)
#define  get_SUB_VGIP_PTG_CH2_PTG_CTRL_reg                                       (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_CTRL_reg))
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_mode_en_shift                   (22)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_ptg_den_sel_shift                         (7)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_mask_one_eye_en_shift                     (6)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_mask_one_eye_left_shift                   (5)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_vertical_mode_shift             (4)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_interlaced_mode_shift           (3)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_3d_mode_shift                   (2)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_num_shift                           (0)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_mode_en_mask                    (0x00400000)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_ptg_den_sel_mask                          (0x00000080)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_mask_one_eye_en_mask                      (0x00000040)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_mask_one_eye_left_mask                    (0x00000020)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_vertical_mode_mask              (0x00000010)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_interlaced_mode_mask            (0x00000008)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_3d_mode_mask                    (0x00000004)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_num_mask                            (0x00000003)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_mode_en(data)                   (0x00400000&((data)<<22))
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_ptg_den_sel(data)                         (0x00000080&((data)<<7))
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_mask_one_eye_en(data)                     (0x00000040&((data)<<6))
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_mask_one_eye_left(data)                   (0x00000020&((data)<<5))
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_vertical_mode(data)             (0x00000010&((data)<<4))
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_interlaced_mode(data)           (0x00000008&((data)<<3))
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_bar_3d_mode(data)                   (0x00000004&((data)<<2))
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_ch2_color_num(data)                           (0x00000003&(data))
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_get_ch2_color_bar_mode_en(data)               ((0x00400000&(data))>>22)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_get_ch2_ptg_den_sel(data)                     ((0x00000080&(data))>>7)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_get_ch2_mask_one_eye_en(data)                 ((0x00000040&(data))>>6)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_get_ch2_mask_one_eye_left(data)               ((0x00000020&(data))>>5)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_get_ch2_color_bar_vertical_mode(data)         ((0x00000010&(data))>>4)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_get_ch2_color_bar_interlaced_mode(data)       ((0x00000008&(data))>>3)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_get_ch2_color_bar_3d_mode(data)               ((0x00000004&(data))>>2)
#define  SUB_VGIP_PTG_CH2_PTG_CTRL_get_ch2_color_num(data)                       (0x00000003&(data))

#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr                                          0x180227C4
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_reg_addr                                 "0xB80227C4"
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_reg                                      0xB80227C4
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_inst_addr                                "0x0001"
#define  set_SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_reg(data)                            (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_reg)=data)
#define  get_SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_reg                                  (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_reg))
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_ch2_i_c0y_92b_shift                      (16)
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_ch2_i_c0cr_92b_shift                     (8)
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_ch2_i_c0cb_92b_shift                     (0)
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_ch2_i_c0y_92b_mask                       (0x00FF0000)
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_ch2_i_c0cr_92b_mask                      (0x0000FF00)
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_ch2_i_c0cb_92b_mask                      (0x000000FF)
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_ch2_i_c0y_92b(data)                      (0x00FF0000&((data)<<16))
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_ch2_i_c0cr_92b(data)                     (0x0000FF00&((data)<<8))
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_ch2_i_c0cb_92b(data)                     (0x000000FF&(data))
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_get_ch2_i_c0y_92b(data)                  ((0x00FF0000&(data))>>16)
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_get_ch2_i_c0cr_92b(data)                 ((0x0000FF00&(data))>>8)
#define  SUB_VGIP_PTG_CH2_PTG_C0Y_Cb_Cr_get_ch2_i_c0cb_92b(data)                 (0x000000FF&(data))

#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr                                          0x180227C8
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_reg_addr                                 "0xB80227C8"
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_reg                                      0xB80227C8
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_inst_addr                                "0x0002"
#define  set_SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_reg(data)                            (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_reg)=data)
#define  get_SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_reg                                  (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_reg))
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_ch2_i_c1y_92b_shift                      (16)
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_ch2_i_c1cr_92b_shift                     (8)
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_ch2_i_c1cb_92b_shift                     (0)
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_ch2_i_c1y_92b_mask                       (0x00FF0000)
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_ch2_i_c1cr_92b_mask                      (0x0000FF00)
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_ch2_i_c1cb_92b_mask                      (0x000000FF)
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_ch2_i_c1y_92b(data)                      (0x00FF0000&((data)<<16))
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_ch2_i_c1cr_92b(data)                     (0x0000FF00&((data)<<8))
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_ch2_i_c1cb_92b(data)                     (0x000000FF&(data))
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_get_ch2_i_c1y_92b(data)                  ((0x00FF0000&(data))>>16)
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_get_ch2_i_c1cr_92b(data)                 ((0x0000FF00&(data))>>8)
#define  SUB_VGIP_PTG_CH2_PTG_C1Y_Cb_Cr_get_ch2_i_c1cb_92b(data)                 (0x000000FF&(data))

#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr                                          0x180227CC
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_reg_addr                                 "0xB80227CC"
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_reg                                      0xB80227CC
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_inst_addr                                "0x0003"
#define  set_SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_reg(data)                            (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_reg)=data)
#define  get_SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_reg                                  (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_reg))
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_ch2_i_c2y_92b_shift                      (16)
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_ch2_i_c2cr_92b_shift                     (8)
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_ch2_i_c2cb_92b_shift                     (0)
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_ch2_i_c2y_92b_mask                       (0x00FF0000)
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_ch2_i_c2cr_92b_mask                      (0x0000FF00)
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_ch2_i_c2cb_92b_mask                      (0x000000FF)
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_ch2_i_c2y_92b(data)                      (0x00FF0000&((data)<<16))
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_ch2_i_c2cr_92b(data)                     (0x0000FF00&((data)<<8))
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_ch2_i_c2cb_92b(data)                     (0x000000FF&(data))
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_get_ch2_i_c2y_92b(data)                  ((0x00FF0000&(data))>>16)
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_get_ch2_i_c2cr_92b(data)                 ((0x0000FF00&(data))>>8)
#define  SUB_VGIP_PTG_CH2_PTG_C2Y_Cb_Cr_get_ch2_i_c2cb_92b(data)                 (0x000000FF&(data))

#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr                                          0x180227D0
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_reg_addr                                 "0xB80227D0"
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_reg                                      0xB80227D0
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_inst_addr                                "0x0004"
#define  set_SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_reg(data)                            (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_reg)=data)
#define  get_SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_reg                                  (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_reg))
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_ch2_i_c3y_92b_shift                      (16)
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_ch2_i_c3cr_92b_shift                     (8)
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_ch2_i_c3cb_92b_shift                     (0)
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_ch2_i_c3y_92b_mask                       (0x00FF0000)
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_ch2_i_c3cr_92b_mask                      (0x0000FF00)
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_ch2_i_c3cb_92b_mask                      (0x000000FF)
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_ch2_i_c3y_92b(data)                      (0x00FF0000&((data)<<16))
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_ch2_i_c3cr_92b(data)                     (0x0000FF00&((data)<<8))
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_ch2_i_c3cb_92b(data)                     (0x000000FF&(data))
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_get_ch2_i_c3y_92b(data)                  ((0x00FF0000&(data))>>16)
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_get_ch2_i_c3cr_92b(data)                 ((0x0000FF00&(data))>>8)
#define  SUB_VGIP_PTG_CH2_PTG_C3Y_Cb_Cr_get_ch2_i_c3cb_92b(data)                 (0x000000FF&(data))

#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr                                          0x180227D4
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_reg_addr                                 "0xB80227D4"
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_reg                                      0xB80227D4
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_inst_addr                                "0x0005"
#define  set_SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_reg(data)                            (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_reg)=data)
#define  get_SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_reg                                  (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_reg))
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_ch2_i_c4y_92b_shift                      (16)
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_ch2_i_c4cr_92b_shift                     (8)
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_ch2_i_c4cb_92b_shift                     (0)
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_ch2_i_c4y_92b_mask                       (0x00FF0000)
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_ch2_i_c4cr_92b_mask                      (0x0000FF00)
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_ch2_i_c4cb_92b_mask                      (0x000000FF)
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_ch2_i_c4y_92b(data)                      (0x00FF0000&((data)<<16))
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_ch2_i_c4cr_92b(data)                     (0x0000FF00&((data)<<8))
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_ch2_i_c4cb_92b(data)                     (0x000000FF&(data))
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_get_ch2_i_c4y_92b(data)                  ((0x00FF0000&(data))>>16)
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_get_ch2_i_c4cr_92b(data)                 ((0x0000FF00&(data))>>8)
#define  SUB_VGIP_PTG_CH2_PTG_C4Y_Cb_Cr_get_ch2_i_c4cb_92b(data)                 (0x000000FF&(data))

#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb                                          0x180227D8
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_reg_addr                                 "0xB80227D8"
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_reg                                      0xB80227D8
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_inst_addr                                "0x0006"
#define  set_SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_reg(data)                            (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_reg)=data)
#define  get_SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_reg                                  (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_reg))
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_ch2_i_c5y_92b_shift                      (16)
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_ch2_i_c5cr_92b_shift                     (8)
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_ch2_i_c5cb_92b_shift                     (0)
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_ch2_i_c5y_92b_mask                       (0x00FF0000)
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_ch2_i_c5cr_92b_mask                      (0x0000FF00)
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_ch2_i_c5cb_92b_mask                      (0x000000FF)
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_ch2_i_c5y_92b(data)                      (0x00FF0000&((data)<<16))
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_ch2_i_c5cr_92b(data)                     (0x0000FF00&((data)<<8))
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_ch2_i_c5cb_92b(data)                     (0x000000FF&(data))
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_get_ch2_i_c5y_92b(data)                  ((0x00FF0000&(data))>>16)
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_get_ch2_i_c5cr_92b(data)                 ((0x0000FF00&(data))>>8)
#define  SUB_VGIP_PTG_CH2_PTG_C5Y_Cr_Cb_get_ch2_i_c5cb_92b(data)                 (0x000000FF&(data))

#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr                                          0x180227DC
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_reg_addr                                 "0xB80227DC"
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_reg                                      0xB80227DC
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_inst_addr                                "0x0007"
#define  set_SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_reg(data)                            (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_reg)=data)
#define  get_SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_reg                                  (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_reg))
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_ch2_i_c6y_92b_shift                      (16)
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_ch2_i_c6cr_92b_shift                     (8)
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_ch2_i_c6cb_92b_shift                     (0)
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_ch2_i_c6y_92b_mask                       (0x00FF0000)
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_ch2_i_c6cr_92b_mask                      (0x0000FF00)
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_ch2_i_c6cb_92b_mask                      (0x000000FF)
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_ch2_i_c6y_92b(data)                      (0x00FF0000&((data)<<16))
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_ch2_i_c6cr_92b(data)                     (0x0000FF00&((data)<<8))
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_ch2_i_c6cb_92b(data)                     (0x000000FF&(data))
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_get_ch2_i_c6y_92b(data)                  ((0x00FF0000&(data))>>16)
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_get_ch2_i_c6cr_92b(data)                 ((0x0000FF00&(data))>>8)
#define  SUB_VGIP_PTG_CH2_PTG_C6Y_Cb_Cr_get_ch2_i_c6cb_92b(data)                 (0x000000FF&(data))

#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr                                          0x180227E0
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_reg_addr                                 "0xB80227E0"
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_reg                                      0xB80227E0
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_inst_addr                                "0x0008"
#define  set_SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_reg(data)                            (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_reg)=data)
#define  get_SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_reg                                  (*((volatile unsigned int*)SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_reg))
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_ch2_i_c7y_92b_shift                      (16)
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_ch2_i_c7cr_92b_shift                     (8)
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_ch2_i_c7cb_92b_shift                     (0)
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_ch2_i_c7y_92b_mask                       (0x00FF0000)
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_ch2_i_c7cr_92b_mask                      (0x0000FF00)
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_ch2_i_c7cb_92b_mask                      (0x000000FF)
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_ch2_i_c7y_92b(data)                      (0x00FF0000&((data)<<16))
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_ch2_i_c7cr_92b(data)                     (0x0000FF00&((data)<<8))
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_ch2_i_c7cb_92b(data)                     (0x000000FF&(data))
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_get_ch2_i_c7y_92b(data)                  ((0x00FF0000&(data))>>16)
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_get_ch2_i_c7cr_92b(data)                 ((0x0000FF00&(data))>>8)
#define  SUB_VGIP_PTG_CH2_PTG_C7Y_Cb_Cr_get_ch2_i_c7cb_92b(data)                 (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SUB_VGIP_PTG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ch2_color_bar_mode_en:1;
        RBus_UInt32  res2:14;
        RBus_UInt32  ch2_ptg_den_sel:1;
        RBus_UInt32  ch2_mask_one_eye_en:1;
        RBus_UInt32  ch2_mask_one_eye_left:1;
        RBus_UInt32  ch2_color_bar_vertical_mode:1;
        RBus_UInt32  ch2_color_bar_interlaced_mode:1;
        RBus_UInt32  ch2_color_bar_3d_mode:1;
        RBus_UInt32  ch2_color_num:2;
    };
}sub_vgip_ptg_ch2_ptg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_i_c0y_92b:8;
        RBus_UInt32  ch2_i_c0cr_92b:8;
        RBus_UInt32  ch2_i_c0cb_92b:8;
    };
}sub_vgip_ptg_ch2_ptg_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_i_c1y_92b:8;
        RBus_UInt32  ch2_i_c1cr_92b:8;
        RBus_UInt32  ch2_i_c1cb_92b:8;
    };
}sub_vgip_ptg_ch2_ptg_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_i_c2y_92b:8;
        RBus_UInt32  ch2_i_c2cr_92b:8;
        RBus_UInt32  ch2_i_c2cb_92b:8;
    };
}sub_vgip_ptg_ch2_ptg_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_i_c3y_92b:8;
        RBus_UInt32  ch2_i_c3cr_92b:8;
        RBus_UInt32  ch2_i_c3cb_92b:8;
    };
}sub_vgip_ptg_ch2_ptg_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_i_c4y_92b:8;
        RBus_UInt32  ch2_i_c4cr_92b:8;
        RBus_UInt32  ch2_i_c4cb_92b:8;
    };
}sub_vgip_ptg_ch2_ptg_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_i_c5y_92b:8;
        RBus_UInt32  ch2_i_c5cr_92b:8;
        RBus_UInt32  ch2_i_c5cb_92b:8;
    };
}sub_vgip_ptg_ch2_ptg_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_i_c6y_92b:8;
        RBus_UInt32  ch2_i_c6cr_92b:8;
        RBus_UInt32  ch2_i_c6cb_92b:8;
    };
}sub_vgip_ptg_ch2_ptg_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch2_i_c7y_92b:8;
        RBus_UInt32  ch2_i_c7cr_92b:8;
        RBus_UInt32  ch2_i_c7cb_92b:8;
    };
}sub_vgip_ptg_ch2_ptg_c7y_cb_cr_RBUS;

#else //apply LITTLE_ENDIAN

//======SUB_VGIP_PTG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_color_num:2;
        RBus_UInt32  ch2_color_bar_3d_mode:1;
        RBus_UInt32  ch2_color_bar_interlaced_mode:1;
        RBus_UInt32  ch2_color_bar_vertical_mode:1;
        RBus_UInt32  ch2_mask_one_eye_left:1;
        RBus_UInt32  ch2_mask_one_eye_en:1;
        RBus_UInt32  ch2_ptg_den_sel:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  ch2_color_bar_mode_en:1;
        RBus_UInt32  res2:9;
    };
}sub_vgip_ptg_ch2_ptg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_i_c0cb_92b:8;
        RBus_UInt32  ch2_i_c0cr_92b:8;
        RBus_UInt32  ch2_i_c0y_92b:8;
        RBus_UInt32  res1:8;
    };
}sub_vgip_ptg_ch2_ptg_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_i_c1cb_92b:8;
        RBus_UInt32  ch2_i_c1cr_92b:8;
        RBus_UInt32  ch2_i_c1y_92b:8;
        RBus_UInt32  res1:8;
    };
}sub_vgip_ptg_ch2_ptg_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_i_c2cb_92b:8;
        RBus_UInt32  ch2_i_c2cr_92b:8;
        RBus_UInt32  ch2_i_c2y_92b:8;
        RBus_UInt32  res1:8;
    };
}sub_vgip_ptg_ch2_ptg_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_i_c3cb_92b:8;
        RBus_UInt32  ch2_i_c3cr_92b:8;
        RBus_UInt32  ch2_i_c3y_92b:8;
        RBus_UInt32  res1:8;
    };
}sub_vgip_ptg_ch2_ptg_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_i_c4cb_92b:8;
        RBus_UInt32  ch2_i_c4cr_92b:8;
        RBus_UInt32  ch2_i_c4y_92b:8;
        RBus_UInt32  res1:8;
    };
}sub_vgip_ptg_ch2_ptg_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_i_c5cb_92b:8;
        RBus_UInt32  ch2_i_c5cr_92b:8;
        RBus_UInt32  ch2_i_c5y_92b:8;
        RBus_UInt32  res1:8;
    };
}sub_vgip_ptg_ch2_ptg_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_i_c6cb_92b:8;
        RBus_UInt32  ch2_i_c6cr_92b:8;
        RBus_UInt32  ch2_i_c6y_92b:8;
        RBus_UInt32  res1:8;
    };
}sub_vgip_ptg_ch2_ptg_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch2_i_c7cb_92b:8;
        RBus_UInt32  ch2_i_c7cr_92b:8;
        RBus_UInt32  ch2_i_c7y_92b:8;
        RBus_UInt32  res1:8;
    };
}sub_vgip_ptg_ch2_ptg_c7y_cb_cr_RBUS;




#endif 


#endif 
