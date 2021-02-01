/**
* @file rbusTwo_step_uzuReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/22
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TWO_STEP_UZU_REG_H_
#define _RBUS_TWO_STEP_UZU_REG_H_

#include "rbus_types.h"



//  TWO_STEP_UZU Register Address
#define  TWO_STEP_UZU_Two_Step_uzu_Ctrl                                          0x18029B00
#define  TWO_STEP_UZU_Two_Step_uzu_Ctrl_reg_addr                                 "0xB8029B00"
#define  TWO_STEP_UZU_Two_Step_uzu_Ctrl_reg                                      0xB8029B00
#define  TWO_STEP_UZU_Two_Step_uzu_Ctrl_inst_addr                                "0x0000"
#define  set_TWO_STEP_UZU_Two_Step_uzu_Ctrl_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_Two_Step_uzu_Ctrl_reg)=data)
#define  get_TWO_STEP_UZU_Two_Step_uzu_Ctrl_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_Two_Step_uzu_Ctrl_reg))
#define  TWO_STEP_UZU_Two_Step_uzu_Ctrl_two_step_uzu_ratio_shift                 (2)
#define  TWO_STEP_UZU_Two_Step_uzu_Ctrl_two_step_uzu_ratio_mask                  (0x00000004)
#define  TWO_STEP_UZU_Two_Step_uzu_Ctrl_two_step_uzu_ratio(data)                 (0x00000004&((data)<<2))
#define  TWO_STEP_UZU_Two_Step_uzu_Ctrl_get_two_step_uzu_ratio(data)             ((0x00000004&(data))>>2)

#define  TWO_STEP_UZU_MFLTI_Ctrl                                                 0x18029B04
#define  TWO_STEP_UZU_MFLTI_Ctrl_reg_addr                                        "0xB8029B04"
#define  TWO_STEP_UZU_MFLTI_Ctrl_reg                                             0xB8029B04
#define  TWO_STEP_UZU_MFLTI_Ctrl_inst_addr                                       "0x0001"
#define  set_TWO_STEP_UZU_MFLTI_Ctrl_reg(data)                                   (*((volatile unsigned int*)TWO_STEP_UZU_MFLTI_Ctrl_reg)=data)
#define  get_TWO_STEP_UZU_MFLTI_Ctrl_reg                                         (*((volatile unsigned int*)TWO_STEP_UZU_MFLTI_Ctrl_reg))
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_en_shift                                  (31)
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_blend_en_shift                            (30)
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_blend_gain_shift                          (24)
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_blend_offset_shift                        (16)
#define  TWO_STEP_UZU_MFLTI_Ctrl_h_range_shift                                   (14)
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_en_mask                                   (0x80000000)
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_blend_en_mask                             (0x40000000)
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_blend_gain_mask                           (0x1F000000)
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_blend_offset_mask                         (0x003F0000)
#define  TWO_STEP_UZU_MFLTI_Ctrl_h_range_mask                                    (0x0000C000)
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_en(data)                                  (0x80000000&((data)<<31))
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_blend_en(data)                            (0x40000000&((data)<<30))
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_blend_gain(data)                          (0x1F000000&((data)<<24))
#define  TWO_STEP_UZU_MFLTI_Ctrl_mflti_blend_offset(data)                        (0x003F0000&((data)<<16))
#define  TWO_STEP_UZU_MFLTI_Ctrl_h_range(data)                                   (0x0000C000&((data)<<14))
#define  TWO_STEP_UZU_MFLTI_Ctrl_get_mflti_en(data)                              ((0x80000000&(data))>>31)
#define  TWO_STEP_UZU_MFLTI_Ctrl_get_mflti_blend_en(data)                        ((0x40000000&(data))>>30)
#define  TWO_STEP_UZU_MFLTI_Ctrl_get_mflti_blend_gain(data)                      ((0x1F000000&(data))>>24)
#define  TWO_STEP_UZU_MFLTI_Ctrl_get_mflti_blend_offset(data)                    ((0x003F0000&(data))>>16)
#define  TWO_STEP_UZU_MFLTI_Ctrl_get_h_range(data)                               ((0x0000C000&(data))>>14)

#define  TWO_STEP_UZU_SR_12tap_dering_ctrl                                       0x18029B08
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_reg_addr                              "0xB8029B08"
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_reg                                   0xB8029B08
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_inst_addr                             "0x0002"
#define  set_TWO_STEP_UZU_SR_12tap_dering_ctrl_reg(data)                         (*((volatile unsigned int*)TWO_STEP_UZU_SR_12tap_dering_ctrl_reg)=data)
#define  get_TWO_STEP_UZU_SR_12tap_dering_ctrl_reg                               (*((volatile unsigned int*)TWO_STEP_UZU_SR_12tap_dering_ctrl_reg))
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_dering_edgelevel_gain_shift           (4)
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_sr_hor_tap_sel_shift                  (0)
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_dering_edgelevel_gain_mask            (0x000000F0)
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_sr_hor_tap_sel_mask                   (0x00000003)
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_dering_edgelevel_gain(data)           (0x000000F0&((data)<<4))
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_sr_hor_tap_sel(data)                  (0x00000003&(data))
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_get_dering_edgelevel_gain(data)       ((0x000000F0&(data))>>4)
#define  TWO_STEP_UZU_SR_12tap_dering_ctrl_get_sr_hor_tap_sel(data)              (0x00000003&(data))

#define  TWO_STEP_UZU_SR_12tap_dering                                            0x18029B0C
#define  TWO_STEP_UZU_SR_12tap_dering_reg_addr                                   "0xB8029B0C"
#define  TWO_STEP_UZU_SR_12tap_dering_reg                                        0xB8029B0C
#define  TWO_STEP_UZU_SR_12tap_dering_inst_addr                                  "0x0003"
#define  set_TWO_STEP_UZU_SR_12tap_dering_reg(data)                              (*((volatile unsigned int*)TWO_STEP_UZU_SR_12tap_dering_reg)=data)
#define  get_TWO_STEP_UZU_SR_12tap_dering_reg                                    (*((volatile unsigned int*)TWO_STEP_UZU_SR_12tap_dering_reg))
#define  TWO_STEP_UZU_SR_12tap_dering_level_flatness_coeff_shift                 (28)
#define  TWO_STEP_UZU_SR_12tap_dering_dering_dbg_mode_shift                      (26)
#define  TWO_STEP_UZU_SR_12tap_dering_h4h12_blend_range_shift                    (24)
#define  TWO_STEP_UZU_SR_12tap_dering_h4h12_blend_lowbound_shift                 (16)
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_mask_sel_shift                   (15)
#define  TWO_STEP_UZU_SR_12tap_dering_level_maxmin_coeff_shift                   (12)
#define  TWO_STEP_UZU_SR_12tap_dering_h4h12_blend_en_shift                       (11)
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_en_shift                         (10)
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_range_shift                      (8)
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_lowbound_shift                   (0)
#define  TWO_STEP_UZU_SR_12tap_dering_level_flatness_coeff_mask                  (0x70000000)
#define  TWO_STEP_UZU_SR_12tap_dering_dering_dbg_mode_mask                       (0x0C000000)
#define  TWO_STEP_UZU_SR_12tap_dering_h4h12_blend_range_mask                     (0x03000000)
#define  TWO_STEP_UZU_SR_12tap_dering_h4h12_blend_lowbound_mask                  (0x00FF0000)
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_mask_sel_mask                    (0x00008000)
#define  TWO_STEP_UZU_SR_12tap_dering_level_maxmin_coeff_mask                    (0x00007000)
#define  TWO_STEP_UZU_SR_12tap_dering_h4h12_blend_en_mask                        (0x00000800)
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_en_mask                          (0x00000400)
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_range_mask                       (0x00000300)
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_lowbound_mask                    (0x000000FF)
#define  TWO_STEP_UZU_SR_12tap_dering_level_flatness_coeff(data)                 (0x70000000&((data)<<28))
#define  TWO_STEP_UZU_SR_12tap_dering_dering_dbg_mode(data)                      (0x0C000000&((data)<<26))
#define  TWO_STEP_UZU_SR_12tap_dering_h4h12_blend_range(data)                    (0x03000000&((data)<<24))
#define  TWO_STEP_UZU_SR_12tap_dering_h4h12_blend_lowbound(data)                 (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_mask_sel(data)                   (0x00008000&((data)<<15))
#define  TWO_STEP_UZU_SR_12tap_dering_level_maxmin_coeff(data)                   (0x00007000&((data)<<12))
#define  TWO_STEP_UZU_SR_12tap_dering_h4h12_blend_en(data)                       (0x00000800&((data)<<11))
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_en(data)                         (0x00000400&((data)<<10))
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_range(data)                      (0x00000300&((data)<<8))
#define  TWO_STEP_UZU_SR_12tap_dering_lpf_blend_lowbound(data)                   (0x000000FF&(data))
#define  TWO_STEP_UZU_SR_12tap_dering_get_level_flatness_coeff(data)             ((0x70000000&(data))>>28)
#define  TWO_STEP_UZU_SR_12tap_dering_get_dering_dbg_mode(data)                  ((0x0C000000&(data))>>26)
#define  TWO_STEP_UZU_SR_12tap_dering_get_h4h12_blend_range(data)                ((0x03000000&(data))>>24)
#define  TWO_STEP_UZU_SR_12tap_dering_get_h4h12_blend_lowbound(data)             ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_12tap_dering_get_lpf_blend_mask_sel(data)               ((0x00008000&(data))>>15)
#define  TWO_STEP_UZU_SR_12tap_dering_get_level_maxmin_coeff(data)               ((0x00007000&(data))>>12)
#define  TWO_STEP_UZU_SR_12tap_dering_get_h4h12_blend_en(data)                   ((0x00000800&(data))>>11)
#define  TWO_STEP_UZU_SR_12tap_dering_get_lpf_blend_en(data)                     ((0x00000400&(data))>>10)
#define  TWO_STEP_UZU_SR_12tap_dering_get_lpf_blend_range(data)                  ((0x00000300&(data))>>8)
#define  TWO_STEP_UZU_SR_12tap_dering_get_lpf_blend_lowbound(data)               (0x000000FF&(data))

#define  TWO_STEP_UZU_SR_Ctrl                                                    0x18029B10
#define  TWO_STEP_UZU_SR_Ctrl_reg_addr                                           "0xB8029B10"
#define  TWO_STEP_UZU_SR_Ctrl_reg                                                0xB8029B10
#define  TWO_STEP_UZU_SR_Ctrl_inst_addr                                          "0x0004"
#define  set_TWO_STEP_UZU_SR_Ctrl_reg(data)                                      (*((volatile unsigned int*)TWO_STEP_UZU_SR_Ctrl_reg)=data)
#define  get_TWO_STEP_UZU_SR_Ctrl_reg                                            (*((volatile unsigned int*)TWO_STEP_UZU_SR_Ctrl_reg))
#define  TWO_STEP_UZU_SR_Ctrl_sr_maxmin_shift_shift                              (24)
#define  TWO_STEP_UZU_SR_Ctrl_sr_var_thd_shift                                   (16)
#define  TWO_STEP_UZU_SR_Ctrl_sr_maxmin_limit_en_shift                           (15)
#define  TWO_STEP_UZU_SR_Ctrl_sr_hor_ini_shift                                   (8)
#define  TWO_STEP_UZU_SR_Ctrl_sr_ver_ini_shift                                   (0)
#define  TWO_STEP_UZU_SR_Ctrl_sr_maxmin_shift_mask                               (0xFF000000)
#define  TWO_STEP_UZU_SR_Ctrl_sr_var_thd_mask                                    (0x00FF0000)
#define  TWO_STEP_UZU_SR_Ctrl_sr_maxmin_limit_en_mask                            (0x00008000)
#define  TWO_STEP_UZU_SR_Ctrl_sr_hor_ini_mask                                    (0x00007F00)
#define  TWO_STEP_UZU_SR_Ctrl_sr_ver_ini_mask                                    (0x0000007F)
#define  TWO_STEP_UZU_SR_Ctrl_sr_maxmin_shift(data)                              (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_Ctrl_sr_var_thd(data)                                   (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_Ctrl_sr_maxmin_limit_en(data)                           (0x00008000&((data)<<15))
#define  TWO_STEP_UZU_SR_Ctrl_sr_hor_ini(data)                                   (0x00007F00&((data)<<8))
#define  TWO_STEP_UZU_SR_Ctrl_sr_ver_ini(data)                                   (0x0000007F&(data))
#define  TWO_STEP_UZU_SR_Ctrl_get_sr_maxmin_shift(data)                          ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_Ctrl_get_sr_var_thd(data)                               ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_Ctrl_get_sr_maxmin_limit_en(data)                       ((0x00008000&(data))>>15)
#define  TWO_STEP_UZU_SR_Ctrl_get_sr_hor_ini(data)                               ((0x00007F00&(data))>>8)
#define  TWO_STEP_UZU_SR_Ctrl_get_sr_ver_ini(data)                               (0x0000007F&(data))

#define  TWO_STEP_UZU_H12_Y_ph0_coeff00                                          0x18029B80
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_reg_addr                                 "0xB8029B80"
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_reg                                      0xB8029B80
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_inst_addr                                "0x0005"
#define  set_TWO_STEP_UZU_H12_Y_ph0_coeff00_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph0_coeff00_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff00_reg))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_h12_y_c0_1_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_h12_y_c0_0_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_h12_y_c0_1_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_h12_y_c0_0_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_h12_y_c0_1(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_h12_y_c0_0(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_get_h12_y_c0_1(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff00_get_h12_y_c0_0(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph0_coeff01                                          0x18029B84
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_reg_addr                                 "0xB8029B84"
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_reg                                      0xB8029B84
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_inst_addr                                "0x0006"
#define  set_TWO_STEP_UZU_H12_Y_ph0_coeff01_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph0_coeff01_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff01_reg))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_h12_y_c0_3_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_h12_y_c0_2_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_h12_y_c0_3_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_h12_y_c0_2_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_h12_y_c0_3(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_h12_y_c0_2(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_get_h12_y_c0_3(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff01_get_h12_y_c0_2(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph0_coeff02                                          0x18029B88
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_reg_addr                                 "0xB8029B88"
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_reg                                      0xB8029B88
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_inst_addr                                "0x0007"
#define  set_TWO_STEP_UZU_H12_Y_ph0_coeff02_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff02_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph0_coeff02_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff02_reg))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_h12_y_c0_5_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_h12_y_c0_4_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_h12_y_c0_5_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_h12_y_c0_4_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_h12_y_c0_5(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_h12_y_c0_4(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_get_h12_y_c0_5(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff02_get_h12_y_c0_4(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph0_coeff03                                          0x18029B8C
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_reg_addr                                 "0xB8029B8C"
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_reg                                      0xB8029B8C
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_inst_addr                                "0x0008"
#define  set_TWO_STEP_UZU_H12_Y_ph0_coeff03_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff03_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph0_coeff03_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff03_reg))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_h12_y_c0_7_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_h12_y_c0_6_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_h12_y_c0_7_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_h12_y_c0_6_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_h12_y_c0_7(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_h12_y_c0_6(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_get_h12_y_c0_7(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff03_get_h12_y_c0_6(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph0_coeff04                                          0x18029B90
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_reg_addr                                 "0xB8029B90"
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_reg                                      0xB8029B90
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_inst_addr                                "0x0009"
#define  set_TWO_STEP_UZU_H12_Y_ph0_coeff04_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff04_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph0_coeff04_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff04_reg))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_h12_y_c0_9_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_h12_y_c0_8_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_h12_y_c0_9_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_h12_y_c0_8_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_h12_y_c0_9(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_h12_y_c0_8(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_get_h12_y_c0_9(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff04_get_h12_y_c0_8(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph0_coeff05                                          0x18029B94
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_reg_addr                                 "0xB8029B94"
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_reg                                      0xB8029B94
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_inst_addr                                "0x000A"
#define  set_TWO_STEP_UZU_H12_Y_ph0_coeff05_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff05_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph0_coeff05_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph0_coeff05_reg))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_h12_y_c0_11_shift                        (16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_h12_y_c0_10_shift                        (0)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_h12_y_c0_11_mask                         (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_h12_y_c0_10_mask                         (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_h12_y_c0_11(data)                        (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_h12_y_c0_10(data)                        (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_get_h12_y_c0_11(data)                    ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph0_coeff05_get_h12_y_c0_10(data)                    (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph1_coeff00                                          0x18029B98
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_reg_addr                                 "0xB8029B98"
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_reg                                      0xB8029B98
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_inst_addr                                "0x000B"
#define  set_TWO_STEP_UZU_H12_Y_ph1_coeff00_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph1_coeff00_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff00_reg))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_h12_y_c1_1_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_h12_y_c1_0_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_h12_y_c1_1_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_h12_y_c1_0_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_h12_y_c1_1(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_h12_y_c1_0(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_get_h12_y_c1_1(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff00_get_h12_y_c1_0(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph1_coeff01                                          0x18029B9C
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_reg_addr                                 "0xB8029B9C"
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_reg                                      0xB8029B9C
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_inst_addr                                "0x000C"
#define  set_TWO_STEP_UZU_H12_Y_ph1_coeff01_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph1_coeff01_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff01_reg))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_h12_y_c1_3_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_h12_y_c1_2_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_h12_y_c1_3_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_h12_y_c1_2_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_h12_y_c1_3(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_h12_y_c1_2(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_get_h12_y_c1_3(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff01_get_h12_y_c1_2(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph1_coeff02                                          0x18029BA0
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_reg_addr                                 "0xB8029BA0"
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_reg                                      0xB8029BA0
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_inst_addr                                "0x000D"
#define  set_TWO_STEP_UZU_H12_Y_ph1_coeff02_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff02_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph1_coeff02_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff02_reg))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_h12_y_c1_5_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_h12_y_c1_4_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_h12_y_c1_5_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_h12_y_c1_4_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_h12_y_c1_5(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_h12_y_c1_4(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_get_h12_y_c1_5(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff02_get_h12_y_c1_4(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph1_coeff03                                          0x18029BA4
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_reg_addr                                 "0xB8029BA4"
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_reg                                      0xB8029BA4
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_inst_addr                                "0x000E"
#define  set_TWO_STEP_UZU_H12_Y_ph1_coeff03_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff03_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph1_coeff03_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff03_reg))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_h12_y_c1_7_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_h12_y_c1_6_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_h12_y_c1_7_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_h12_y_c1_6_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_h12_y_c1_7(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_h12_y_c1_6(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_get_h12_y_c1_7(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff03_get_h12_y_c1_6(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph1_coeff04                                          0x18029BA8
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_reg_addr                                 "0xB8029BA8"
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_reg                                      0xB8029BA8
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_inst_addr                                "0x000F"
#define  set_TWO_STEP_UZU_H12_Y_ph1_coeff04_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff04_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph1_coeff04_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff04_reg))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_h12_y_c1_9_shift                         (16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_h12_y_c1_8_shift                         (0)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_h12_y_c1_9_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_h12_y_c1_8_mask                          (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_h12_y_c1_9(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_h12_y_c1_8(data)                         (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_get_h12_y_c1_9(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff04_get_h12_y_c1_8(data)                     (0x00000FFF&(data))

#define  TWO_STEP_UZU_H12_Y_ph1_coeff05                                          0x18029BAC
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_reg_addr                                 "0xB8029BAC"
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_reg                                      0xB8029BAC
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_inst_addr                                "0x0010"
#define  set_TWO_STEP_UZU_H12_Y_ph1_coeff05_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff05_reg)=data)
#define  get_TWO_STEP_UZU_H12_Y_ph1_coeff05_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_H12_Y_ph1_coeff05_reg))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_h12_y_c1_11_shift                        (16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_h12_y_c1_10_shift                        (0)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_h12_y_c1_11_mask                         (0x0FFF0000)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_h12_y_c1_10_mask                         (0x00000FFF)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_h12_y_c1_11(data)                        (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_h12_y_c1_10(data)                        (0x00000FFF&(data))
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_get_h12_y_c1_11(data)                    ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H12_Y_ph1_coeff05_get_h12_y_c1_10(data)                    (0x00000FFF&(data))

#define  TWO_STEP_UZU_H4_Y_ph0_coeff00                                           0x18029BB0
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_reg_addr                                  "0xB8029BB0"
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_reg                                       0xB8029BB0
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_inst_addr                                 "0x0011"
#define  set_TWO_STEP_UZU_H4_Y_ph0_coeff00_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_H4_Y_ph0_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_H4_Y_ph0_coeff00_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_H4_Y_ph0_coeff00_reg))
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_h4_y_c0_1_shift                           (16)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_h4_y_c0_0_shift                           (0)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_h4_y_c0_1_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_h4_y_c0_0_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_h4_y_c0_1(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_h4_y_c0_0(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_get_h4_y_c0_1(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff00_get_h4_y_c0_0(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_H4_Y_ph0_coeff01                                           0x18029BB4
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_reg_addr                                  "0xB8029BB4"
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_reg                                       0xB8029BB4
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_inst_addr                                 "0x0012"
#define  set_TWO_STEP_UZU_H4_Y_ph0_coeff01_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_H4_Y_ph0_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_H4_Y_ph0_coeff01_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_H4_Y_ph0_coeff01_reg))
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_h4_y_c0_3_shift                           (16)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_h4_y_c0_2_shift                           (0)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_h4_y_c0_3_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_h4_y_c0_2_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_h4_y_c0_3(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_h4_y_c0_2(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_get_h4_y_c0_3(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H4_Y_ph0_coeff01_get_h4_y_c0_2(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_H4_Y_ph1_coeff00                                           0x18029BB8
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_reg_addr                                  "0xB8029BB8"
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_reg                                       0xB8029BB8
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_inst_addr                                 "0x0013"
#define  set_TWO_STEP_UZU_H4_Y_ph1_coeff00_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_H4_Y_ph1_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_H4_Y_ph1_coeff00_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_H4_Y_ph1_coeff00_reg))
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_h4_y_c1_1_shift                           (16)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_h4_y_c1_0_shift                           (0)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_h4_y_c1_1_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_h4_y_c1_0_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_h4_y_c1_1(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_h4_y_c1_0(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_get_h4_y_c1_1(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff00_get_h4_y_c1_0(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_H4_Y_ph1_coeff01                                           0x18029BBC
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_reg_addr                                  "0xB8029BBC"
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_reg                                       0xB8029BBC
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_inst_addr                                 "0x0014"
#define  set_TWO_STEP_UZU_H4_Y_ph1_coeff01_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_H4_Y_ph1_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_H4_Y_ph1_coeff01_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_H4_Y_ph1_coeff01_reg))
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_h4_y_c1_3_shift                           (16)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_h4_y_c1_2_shift                           (0)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_h4_y_c1_3_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_h4_y_c1_2_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_h4_y_c1_3(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_h4_y_c1_2(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_get_h4_y_c1_3(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H4_Y_ph1_coeff01_get_h4_y_c1_2(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_V4_Y_ph0_coeff00                                           0x18029BC0
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_reg_addr                                  "0xB8029BC0"
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_reg                                       0xB8029BC0
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_inst_addr                                 "0x0015"
#define  set_TWO_STEP_UZU_V4_Y_ph0_coeff00_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_V4_Y_ph0_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_V4_Y_ph0_coeff00_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_V4_Y_ph0_coeff00_reg))
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_v4_y_c0_1_shift                           (16)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_v4_y_c0_0_shift                           (0)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_v4_y_c0_1_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_v4_y_c0_0_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_v4_y_c0_1(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_v4_y_c0_0(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_get_v4_y_c0_1(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff00_get_v4_y_c0_0(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_V4_Y_ph0_coeff01                                           0x18029BC4
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_reg_addr                                  "0xB8029BC4"
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_reg                                       0xB8029BC4
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_inst_addr                                 "0x0016"
#define  set_TWO_STEP_UZU_V4_Y_ph0_coeff01_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_V4_Y_ph0_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_V4_Y_ph0_coeff01_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_V4_Y_ph0_coeff01_reg))
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_v4_y_c0_3_shift                           (16)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_v4_y_c0_2_shift                           (0)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_v4_y_c0_3_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_v4_y_c0_2_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_v4_y_c0_3(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_v4_y_c0_2(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_get_v4_y_c0_3(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_V4_Y_ph0_coeff01_get_v4_y_c0_2(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_V4_Y_ph1_coeff00                                           0x18029BC8
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_reg_addr                                  "0xB8029BC8"
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_reg                                       0xB8029BC8
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_inst_addr                                 "0x0017"
#define  set_TWO_STEP_UZU_V4_Y_ph1_coeff00_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_V4_Y_ph1_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_V4_Y_ph1_coeff00_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_V4_Y_ph1_coeff00_reg))
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_v4_y_c1_1_shift                           (16)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_v4_y_c1_0_shift                           (0)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_v4_y_c1_1_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_v4_y_c1_0_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_v4_y_c1_1(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_v4_y_c1_0(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_get_v4_y_c1_1(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff00_get_v4_y_c1_0(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_V4_Y_ph1_coeff01                                           0x18029BCC
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_reg_addr                                  "0xB8029BCC"
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_reg                                       0xB8029BCC
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_inst_addr                                 "0x0018"
#define  set_TWO_STEP_UZU_V4_Y_ph1_coeff01_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_V4_Y_ph1_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_V4_Y_ph1_coeff01_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_V4_Y_ph1_coeff01_reg))
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_v4_y_c1_3_shift                           (16)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_v4_y_c1_2_shift                           (0)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_v4_y_c1_3_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_v4_y_c1_2_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_v4_y_c1_3(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_v4_y_c1_2(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_get_v4_y_c1_3(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_V4_Y_ph1_coeff01_get_v4_y_c1_2(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_H4_C_ph0_coeff00                                           0x18029BD0
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_reg_addr                                  "0xB8029BD0"
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_reg                                       0xB8029BD0
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_inst_addr                                 "0x0019"
#define  set_TWO_STEP_UZU_H4_C_ph0_coeff00_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_H4_C_ph0_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_H4_C_ph0_coeff00_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_H4_C_ph0_coeff00_reg))
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_h4_c_c0_1_shift                           (16)
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_h4_c_c0_0_shift                           (0)
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_h4_c_c0_1_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_h4_c_c0_0_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_h4_c_c0_1(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_h4_c_c0_0(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_get_h4_c_c0_1(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H4_C_ph0_coeff00_get_h4_c_c0_0(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_H4_C_ph0_coeff01                                           0x18029BD4
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_reg_addr                                  "0xB8029BD4"
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_reg                                       0xB8029BD4
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_inst_addr                                 "0x001A"
#define  set_TWO_STEP_UZU_H4_C_ph0_coeff01_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_H4_C_ph0_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_H4_C_ph0_coeff01_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_H4_C_ph0_coeff01_reg))
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_h4_c_c0_3_shift                           (16)
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_h4_c_c0_2_shift                           (0)
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_h4_c_c0_3_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_h4_c_c0_2_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_h4_c_c0_3(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_h4_c_c0_2(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_get_h4_c_c0_3(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H4_C_ph0_coeff01_get_h4_c_c0_2(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_H4_C_ph1_coeff00                                           0x18029BD8
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_reg_addr                                  "0xB8029BD8"
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_reg                                       0xB8029BD8
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_inst_addr                                 "0x001B"
#define  set_TWO_STEP_UZU_H4_C_ph1_coeff00_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_H4_C_ph1_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_H4_C_ph1_coeff00_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_H4_C_ph1_coeff00_reg))
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_h4_c_c1_1_shift                           (16)
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_h4_c_c1_0_shift                           (0)
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_h4_c_c1_1_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_h4_c_c1_0_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_h4_c_c1_1(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_h4_c_c1_0(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_get_h4_c_c1_1(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H4_C_ph1_coeff00_get_h4_c_c1_0(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_H4_C_ph1_coeff01                                           0x18029BDC
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_reg_addr                                  "0xB8029BDC"
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_reg                                       0xB8029BDC
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_inst_addr                                 "0x001C"
#define  set_TWO_STEP_UZU_H4_C_ph1_coeff01_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_H4_C_ph1_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_H4_C_ph1_coeff01_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_H4_C_ph1_coeff01_reg))
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_h4_c_c1_3_shift                           (16)
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_h4_c_c1_2_shift                           (0)
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_h4_c_c1_3_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_h4_c_c1_2_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_h4_c_c1_3(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_h4_c_c1_2(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_get_h4_c_c1_3(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_H4_C_ph1_coeff01_get_h4_c_c1_2(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_V4_C_ph0_coeff00                                           0x18029BE0
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_reg_addr                                  "0xB8029BE0"
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_reg                                       0xB8029BE0
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_inst_addr                                 "0x001D"
#define  set_TWO_STEP_UZU_V4_C_ph0_coeff00_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_V4_C_ph0_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_V4_C_ph0_coeff00_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_V4_C_ph0_coeff00_reg))
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_v4_c_c0_1_shift                           (16)
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_v4_c_c0_0_shift                           (0)
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_v4_c_c0_1_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_v4_c_c0_0_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_v4_c_c0_1(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_v4_c_c0_0(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_get_v4_c_c0_1(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_V4_C_ph0_coeff00_get_v4_c_c0_0(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_V4_C_ph0_coeff01                                           0x18029BE4
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_reg_addr                                  "0xB8029BE4"
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_reg                                       0xB8029BE4
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_inst_addr                                 "0x001E"
#define  set_TWO_STEP_UZU_V4_C_ph0_coeff01_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_V4_C_ph0_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_V4_C_ph0_coeff01_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_V4_C_ph0_coeff01_reg))
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_v4_c_c0_3_shift                           (16)
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_v4_c_c0_2_shift                           (0)
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_v4_c_c0_3_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_v4_c_c0_2_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_v4_c_c0_3(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_v4_c_c0_2(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_get_v4_c_c0_3(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_V4_C_ph0_coeff01_get_v4_c_c0_2(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_V4_C_ph1_coeff00                                           0x18029BE8
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_reg_addr                                  "0xB8029BE8"
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_reg                                       0xB8029BE8
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_inst_addr                                 "0x001F"
#define  set_TWO_STEP_UZU_V4_C_ph1_coeff00_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_V4_C_ph1_coeff00_reg)=data)
#define  get_TWO_STEP_UZU_V4_C_ph1_coeff00_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_V4_C_ph1_coeff00_reg))
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_v4_c_c1_1_shift                           (16)
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_v4_c_c1_0_shift                           (0)
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_v4_c_c1_1_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_v4_c_c1_0_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_v4_c_c1_1(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_v4_c_c1_0(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_get_v4_c_c1_1(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_V4_C_ph1_coeff00_get_v4_c_c1_0(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_V4_C_ph1_coeff01                                           0x18029BEC
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_reg_addr                                  "0xB8029BEC"
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_reg                                       0xB8029BEC
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_inst_addr                                 "0x0020"
#define  set_TWO_STEP_UZU_V4_C_ph1_coeff01_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_V4_C_ph1_coeff01_reg)=data)
#define  get_TWO_STEP_UZU_V4_C_ph1_coeff01_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_V4_C_ph1_coeff01_reg))
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_v4_c_c1_3_shift                           (16)
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_v4_c_c1_2_shift                           (0)
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_v4_c_c1_3_mask                            (0x0FFF0000)
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_v4_c_c1_2_mask                            (0x00000FFF)
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_v4_c_c1_3(data)                           (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_v4_c_c1_2(data)                           (0x00000FFF&(data))
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_get_v4_c_c1_3(data)                       ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_V4_C_ph1_coeff01_get_v4_c_c1_2(data)                       (0x00000FFF&(data))

#define  TWO_STEP_UZU_SR_Filter_Ctrl0                                            0x18029B14
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_reg_addr                                   "0xB8029B14"
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_reg                                        0xB8029B14
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_inst_addr                                  "0x0021"
#define  set_TWO_STEP_UZU_SR_Filter_Ctrl0_reg(data)                              (*((volatile unsigned int*)TWO_STEP_UZU_SR_Filter_Ctrl0_reg)=data)
#define  get_TWO_STEP_UZU_SR_Filter_Ctrl0_reg                                    (*((volatile unsigned int*)TWO_STEP_UZU_SR_Filter_Ctrl0_reg))
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_maxmin_thd_shift                        (16)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_maxmin_mode_shift                       (9)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_maxmin_range_shift                      (8)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_delta_gain_shift                        (5)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_edge_range_shift                        (4)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_lpf_range_shift                         (0)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_maxmin_thd_mask                         (0x00FF0000)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_maxmin_mode_mask                        (0x00000200)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_maxmin_range_mask                       (0x00000100)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_delta_gain_mask                         (0x00000060)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_edge_range_mask                         (0x00000010)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_lpf_range_mask                          (0x00000001)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_maxmin_thd(data)                        (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_maxmin_mode(data)                       (0x00000200&((data)<<9))
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_maxmin_range(data)                      (0x00000100&((data)<<8))
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_delta_gain(data)                        (0x00000060&((data)<<5))
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_edge_range(data)                        (0x00000010&((data)<<4))
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_sr_lpf_range(data)                         (0x00000001&(data))
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_get_sr_maxmin_thd(data)                    ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_get_sr_maxmin_mode(data)                   ((0x00000200&(data))>>9)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_get_sr_maxmin_range(data)                  ((0x00000100&(data))>>8)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_get_sr_delta_gain(data)                    ((0x00000060&(data))>>5)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_get_sr_edge_range(data)                    ((0x00000010&(data))>>4)
#define  TWO_STEP_UZU_SR_Filter_Ctrl0_get_sr_lpf_range(data)                     (0x00000001&(data))

#define  TWO_STEP_UZU_SR_Filter_Ctrl1                                            0x18029B18
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_reg_addr                                   "0xB8029B18"
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_reg                                        0xB8029B18
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_inst_addr                                  "0x0022"
#define  set_TWO_STEP_UZU_SR_Filter_Ctrl1_reg(data)                              (*((volatile unsigned int*)TWO_STEP_UZU_SR_Filter_Ctrl1_reg)=data)
#define  get_TWO_STEP_UZU_SR_Filter_Ctrl1_reg                                    (*((volatile unsigned int*)TWO_STEP_UZU_SR_Filter_Ctrl1_reg))
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd0_shift                          (24)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd1_shift                          (16)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd2_shift                          (8)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd3_shift                          (0)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd0_mask                           (0xFF000000)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd1_mask                           (0x00FF0000)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd2_mask                           (0x0000FF00)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd3_mask                           (0x000000FF)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd0(data)                          (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd1(data)                          (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd2(data)                          (0x0000FF00&((data)<<8))
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_sr_bif_thd3(data)                          (0x000000FF&(data))
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_get_sr_bif_thd0(data)                      ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_get_sr_bif_thd1(data)                      ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_get_sr_bif_thd2(data)                      ((0x0000FF00&(data))>>8)
#define  TWO_STEP_UZU_SR_Filter_Ctrl1_get_sr_bif_thd3(data)                      (0x000000FF&(data))

#define  TWO_STEP_UZU_SR_Filter_Ctrl2                                            0x18029B1C
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_reg_addr                                   "0xB8029B1C"
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_reg                                        0xB8029B1C
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_inst_addr                                  "0x0023"
#define  set_TWO_STEP_UZU_SR_Filter_Ctrl2_reg(data)                              (*((volatile unsigned int*)TWO_STEP_UZU_SR_Filter_Ctrl2_reg)=data)
#define  get_TWO_STEP_UZU_SR_Filter_Ctrl2_reg                                    (*((volatile unsigned int*)TWO_STEP_UZU_SR_Filter_Ctrl2_reg))
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd4_shift                          (24)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd5_shift                          (16)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd6_shift                          (8)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd7_shift                          (0)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd4_mask                           (0xFF000000)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd5_mask                           (0x00FF0000)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd6_mask                           (0x0000FF00)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd7_mask                           (0x000000FF)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd4(data)                          (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd5(data)                          (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd6(data)                          (0x0000FF00&((data)<<8))
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_sr_bif_thd7(data)                          (0x000000FF&(data))
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_get_sr_bif_thd4(data)                      ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_get_sr_bif_thd5(data)                      ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_get_sr_bif_thd6(data)                      ((0x0000FF00&(data))>>8)
#define  TWO_STEP_UZU_SR_Filter_Ctrl2_get_sr_bif_thd7(data)                      (0x000000FF&(data))

#define  TWO_STEP_UZU_SR_GainY_Ctrl0                                             0x18029B20
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_reg_addr                                    "0xB8029B20"
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_reg                                         0xB8029B20
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_inst_addr                                   "0x0024"
#define  set_TWO_STEP_UZU_SR_GainY_Ctrl0_reg(data)                               (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl0_reg)=data)
#define  get_TWO_STEP_UZU_SR_GainY_Ctrl0_reg                                     (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl0_reg))
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_by_pgain0_shift                          (24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_by_ngain0_shift                          (16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_lpf_gain_shift                           (10)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_bif_gain_shift                           (2)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_diffdir_cond_en_shift                    (1)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_by_gain_en_shift                         (0)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_by_pgain0_mask                           (0xFF000000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_by_ngain0_mask                           (0x00FF0000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_lpf_gain_mask                            (0x0000FC00)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_bif_gain_mask                            (0x000000FC)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_diffdir_cond_en_mask                     (0x00000002)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_by_gain_en_mask                          (0x00000001)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_by_pgain0(data)                          (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_by_ngain0(data)                          (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_lpf_gain(data)                           (0x0000FC00&((data)<<10))
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_bif_gain(data)                           (0x000000FC&((data)<<2))
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_diffdir_cond_en(data)                    (0x00000002&((data)<<1))
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_sr_by_gain_en(data)                         (0x00000001&(data))
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_get_sr_by_pgain0(data)                      ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_get_sr_by_ngain0(data)                      ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_get_sr_lpf_gain(data)                       ((0x0000FC00&(data))>>10)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_get_sr_bif_gain(data)                       ((0x000000FC&(data))>>2)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_get_sr_diffdir_cond_en(data)                ((0x00000002&(data))>>1)
#define  TWO_STEP_UZU_SR_GainY_Ctrl0_get_sr_by_gain_en(data)                     (0x00000001&(data))

#define  TWO_STEP_UZU_SR_GainY_Ctrl1                                             0x18029B24
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_reg_addr                                    "0xB8029B24"
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_reg                                         0xB8029B24
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_inst_addr                                   "0x0025"
#define  set_TWO_STEP_UZU_SR_GainY_Ctrl1_reg(data)                               (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl1_reg)=data)
#define  get_TWO_STEP_UZU_SR_GainY_Ctrl1_reg                                     (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl1_reg))
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain1_shift                          (24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain2_shift                          (16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain3_shift                          (8)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain4_shift                          (0)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain1_mask                           (0xFF000000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain2_mask                           (0x00FF0000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain3_mask                           (0x0000FF00)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain4_mask                           (0x000000FF)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain1(data)                          (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain2(data)                          (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain3(data)                          (0x0000FF00&((data)<<8))
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_sr_by_pgain4(data)                          (0x000000FF&(data))
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_get_sr_by_pgain1(data)                      ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_get_sr_by_pgain2(data)                      ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_get_sr_by_pgain3(data)                      ((0x0000FF00&(data))>>8)
#define  TWO_STEP_UZU_SR_GainY_Ctrl1_get_sr_by_pgain4(data)                      (0x000000FF&(data))

#define  TWO_STEP_UZU_SR_GainY_Ctrl2                                             0x18029B28
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_reg_addr                                    "0xB8029B28"
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_reg                                         0xB8029B28
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_inst_addr                                   "0x0026"
#define  set_TWO_STEP_UZU_SR_GainY_Ctrl2_reg(data)                               (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl2_reg)=data)
#define  get_TWO_STEP_UZU_SR_GainY_Ctrl2_reg                                     (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl2_reg))
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain5_shift                          (24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain6_shift                          (16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain7_shift                          (8)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain8_shift                          (0)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain5_mask                           (0xFF000000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain6_mask                           (0x00FF0000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain7_mask                           (0x0000FF00)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain8_mask                           (0x000000FF)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain5(data)                          (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain6(data)                          (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain7(data)                          (0x0000FF00&((data)<<8))
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_sr_by_pgain8(data)                          (0x000000FF&(data))
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_get_sr_by_pgain5(data)                      ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_get_sr_by_pgain6(data)                      ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_get_sr_by_pgain7(data)                      ((0x0000FF00&(data))>>8)
#define  TWO_STEP_UZU_SR_GainY_Ctrl2_get_sr_by_pgain8(data)                      (0x000000FF&(data))

#define  TWO_STEP_UZU_SR_GainY_Ctrl3                                             0x18029B2C
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_reg_addr                                    "0xB8029B2C"
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_reg                                         0xB8029B2C
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_inst_addr                                   "0x0027"
#define  set_TWO_STEP_UZU_SR_GainY_Ctrl3_reg(data)                               (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl3_reg)=data)
#define  get_TWO_STEP_UZU_SR_GainY_Ctrl3_reg                                     (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl3_reg))
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain1_shift                          (24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain2_shift                          (16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain3_shift                          (8)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain4_shift                          (0)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain1_mask                           (0xFF000000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain2_mask                           (0x00FF0000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain3_mask                           (0x0000FF00)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain4_mask                           (0x000000FF)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain1(data)                          (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain2(data)                          (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain3(data)                          (0x0000FF00&((data)<<8))
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_sr_by_ngain4(data)                          (0x000000FF&(data))
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_get_sr_by_ngain1(data)                      ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_get_sr_by_ngain2(data)                      ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_get_sr_by_ngain3(data)                      ((0x0000FF00&(data))>>8)
#define  TWO_STEP_UZU_SR_GainY_Ctrl3_get_sr_by_ngain4(data)                      (0x000000FF&(data))

#define  TWO_STEP_UZU_SR_GainY_Ctrl4                                             0x18029B30
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_reg_addr                                    "0xB8029B30"
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_reg                                         0xB8029B30
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_inst_addr                                   "0x0028"
#define  set_TWO_STEP_UZU_SR_GainY_Ctrl4_reg(data)                               (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl4_reg)=data)
#define  get_TWO_STEP_UZU_SR_GainY_Ctrl4_reg                                     (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainY_Ctrl4_reg))
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain5_shift                          (24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain6_shift                          (16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain7_shift                          (8)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain8_shift                          (0)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain5_mask                           (0xFF000000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain6_mask                           (0x00FF0000)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain7_mask                           (0x0000FF00)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain8_mask                           (0x000000FF)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain5(data)                          (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain6(data)                          (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain7(data)                          (0x0000FF00&((data)<<8))
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_sr_by_ngain8(data)                          (0x000000FF&(data))
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_get_sr_by_ngain5(data)                      ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_get_sr_by_ngain6(data)                      ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_get_sr_by_ngain7(data)                      ((0x0000FF00&(data))>>8)
#define  TWO_STEP_UZU_SR_GainY_Ctrl4_get_sr_by_ngain8(data)                      (0x000000FF&(data))

#define  TWO_STEP_UZU_SR_GainMap_Ctrl0                                           0x18029B34
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_reg_addr                                  "0xB8029B34"
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_reg                                       0xB8029B34
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_inst_addr                                 "0x0029"
#define  set_TWO_STEP_UZU_SR_GainMap_Ctrl0_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainMap_Ctrl0_reg)=data)
#define  get_TWO_STEP_UZU_SR_GainMap_Ctrl0_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainMap_Ctrl0_reg))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_thd_shift                    (24)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_gain_shift                   (19)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_step_shift                   (17)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_en_shift                     (16)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_thd_shift                     (8)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_gain_shift                    (3)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_step_shift                    (1)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_en_shift                      (0)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_thd_mask                     (0xFF000000)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_gain_mask                    (0x00F80000)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_step_mask                    (0x00060000)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_en_mask                      (0x00010000)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_thd_mask                      (0x0000FF00)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_gain_mask                     (0x000000F8)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_step_mask                     (0x00000006)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_en_mask                       (0x00000001)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_thd(data)                    (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_gain(data)                   (0x00F80000&((data)<<19))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_step(data)                   (0x00060000&((data)<<17))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_range_en(data)                     (0x00010000&((data)<<16))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_thd(data)                     (0x0000FF00&((data)<<8))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_gain(data)                    (0x000000F8&((data)<<3))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_step(data)                    (0x00000006&((data)<<1))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_sr_lpf_edge_en(data)                      (0x00000001&(data))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_get_sr_lpf_range_thd(data)                ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_get_sr_lpf_range_gain(data)               ((0x00F80000&(data))>>19)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_get_sr_lpf_range_step(data)               ((0x00060000&(data))>>17)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_get_sr_lpf_range_en(data)                 ((0x00010000&(data))>>16)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_get_sr_lpf_edge_thd(data)                 ((0x0000FF00&(data))>>8)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_get_sr_lpf_edge_gain(data)                ((0x000000F8&(data))>>3)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_get_sr_lpf_edge_step(data)                ((0x00000006&(data))>>1)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl0_get_sr_lpf_edge_en(data)                  (0x00000001&(data))

#define  TWO_STEP_UZU_SR_GainMap_Ctrl1                                           0x18029B38
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_reg_addr                                  "0xB8029B38"
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_reg                                       0xB8029B38
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_inst_addr                                 "0x002A"
#define  set_TWO_STEP_UZU_SR_GainMap_Ctrl1_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainMap_Ctrl1_reg)=data)
#define  get_TWO_STEP_UZU_SR_GainMap_Ctrl1_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainMap_Ctrl1_reg))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_thd0_shift                   (24)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_thd1_shift                   (16)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_gain0_shift                  (11)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_step0_shift                  (9)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_gain1_shift                  (3)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_step1_shift                  (1)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_en_shift                     (0)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_thd0_mask                    (0xFF000000)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_thd1_mask                    (0x00FF0000)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_gain0_mask                   (0x0000F800)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_step0_mask                   (0x00000600)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_gain1_mask                   (0x000000F8)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_step1_mask                   (0x00000006)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_en_mask                      (0x00000001)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_thd0(data)                   (0xFF000000&((data)<<24))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_thd1(data)                   (0x00FF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_gain0(data)                  (0x0000F800&((data)<<11))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_step0(data)                  (0x00000600&((data)<<9))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_gain1(data)                  (0x000000F8&((data)<<3))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_step1(data)                  (0x00000006&((data)<<1))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_sr_bif_range_en(data)                     (0x00000001&(data))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_get_sr_bif_range_thd0(data)               ((0xFF000000&(data))>>24)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_get_sr_bif_range_thd1(data)               ((0x00FF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_get_sr_bif_range_gain0(data)              ((0x0000F800&(data))>>11)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_get_sr_bif_range_step0(data)              ((0x00000600&(data))>>9)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_get_sr_bif_range_gain1(data)              ((0x000000F8&(data))>>3)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_get_sr_bif_range_step1(data)              ((0x00000006&(data))>>1)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl1_get_sr_bif_range_en(data)                 (0x00000001&(data))

#define  TWO_STEP_UZU_SR_GainMap_Ctrl2                                           0x18029B3C
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_reg_addr                                  "0xB8029B3C"
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_reg                                       0xB8029B3C
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_inst_addr                                 "0x002B"
#define  set_TWO_STEP_UZU_SR_GainMap_Ctrl2_reg(data)                             (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainMap_Ctrl2_reg)=data)
#define  get_TWO_STEP_UZU_SR_GainMap_Ctrl2_reg                                   (*((volatile unsigned int*)TWO_STEP_UZU_SR_GainMap_Ctrl2_reg))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_thd_shift                     (8)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_gain_shift                    (3)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_step_shift                    (1)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_en_shift                      (0)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_thd_mask                      (0x0000FF00)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_gain_mask                     (0x000000F8)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_step_mask                     (0x00000006)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_en_mask                       (0x00000001)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_thd(data)                     (0x0000FF00&((data)<<8))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_gain(data)                    (0x000000F8&((data)<<3))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_step(data)                    (0x00000006&((data)<<1))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_sr_bif_edge_en(data)                      (0x00000001&(data))
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_get_sr_bif_edge_thd(data)                 ((0x0000FF00&(data))>>8)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_get_sr_bif_edge_gain(data)                ((0x000000F8&(data))>>3)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_get_sr_bif_edge_step(data)                ((0x00000006&(data))>>1)
#define  TWO_STEP_UZU_SR_GainMap_Ctrl2_get_sr_bif_edge_en(data)                  (0x00000001&(data))

#define  TWO_STEP_UZU_SR_Debug0                                                  0x18029B40
#define  TWO_STEP_UZU_SR_Debug0_reg_addr                                         "0xB8029B40"
#define  TWO_STEP_UZU_SR_Debug0_reg                                              0xB8029B40
#define  TWO_STEP_UZU_SR_Debug0_inst_addr                                        "0x002C"
#define  set_TWO_STEP_UZU_SR_Debug0_reg(data)                                    (*((volatile unsigned int*)TWO_STEP_UZU_SR_Debug0_reg)=data)
#define  get_TWO_STEP_UZU_SR_Debug0_reg                                          (*((volatile unsigned int*)TWO_STEP_UZU_SR_Debug0_reg))
#define  TWO_STEP_UZU_SR_Debug0_sr_dbg_mode_shift                                (8)
#define  TWO_STEP_UZU_SR_Debug0_sr_dbg_inv_shift                                 (4)
#define  TWO_STEP_UZU_SR_Debug0_sr_dbg_en_shift                                  (0)
#define  TWO_STEP_UZU_SR_Debug0_sr_dbg_mode_mask                                 (0x00000F00)
#define  TWO_STEP_UZU_SR_Debug0_sr_dbg_inv_mask                                  (0x00000010)
#define  TWO_STEP_UZU_SR_Debug0_sr_dbg_en_mask                                   (0x00000001)
#define  TWO_STEP_UZU_SR_Debug0_sr_dbg_mode(data)                                (0x00000F00&((data)<<8))
#define  TWO_STEP_UZU_SR_Debug0_sr_dbg_inv(data)                                 (0x00000010&((data)<<4))
#define  TWO_STEP_UZU_SR_Debug0_sr_dbg_en(data)                                  (0x00000001&(data))
#define  TWO_STEP_UZU_SR_Debug0_get_sr_dbg_mode(data)                            ((0x00000F00&(data))>>8)
#define  TWO_STEP_UZU_SR_Debug0_get_sr_dbg_inv(data)                             ((0x00000010&(data))>>4)
#define  TWO_STEP_UZU_SR_Debug0_get_sr_dbg_en(data)                              (0x00000001&(data))

#define  TWO_STEP_UZU_SR_Debug1                                                  0x18029B44
#define  TWO_STEP_UZU_SR_Debug1_reg_addr                                         "0xB8029B44"
#define  TWO_STEP_UZU_SR_Debug1_reg                                              0xB8029B44
#define  TWO_STEP_UZU_SR_Debug1_inst_addr                                        "0x002D"
#define  set_TWO_STEP_UZU_SR_Debug1_reg(data)                                    (*((volatile unsigned int*)TWO_STEP_UZU_SR_Debug1_reg)=data)
#define  get_TWO_STEP_UZU_SR_Debug1_reg                                          (*((volatile unsigned int*)TWO_STEP_UZU_SR_Debug1_reg))
#define  TWO_STEP_UZU_SR_Debug1_sr_dbg_h_sta_shift                               (16)
#define  TWO_STEP_UZU_SR_Debug1_sr_dbg_h_end_shift                               (0)
#define  TWO_STEP_UZU_SR_Debug1_sr_dbg_h_sta_mask                                (0x0FFF0000)
#define  TWO_STEP_UZU_SR_Debug1_sr_dbg_h_end_mask                                (0x00000FFF)
#define  TWO_STEP_UZU_SR_Debug1_sr_dbg_h_sta(data)                               (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_Debug1_sr_dbg_h_end(data)                               (0x00000FFF&(data))
#define  TWO_STEP_UZU_SR_Debug1_get_sr_dbg_h_sta(data)                           ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_Debug1_get_sr_dbg_h_end(data)                           (0x00000FFF&(data))

#define  TWO_STEP_UZU_SR_Debug2                                                  0x18029B48
#define  TWO_STEP_UZU_SR_Debug2_reg_addr                                         "0xB8029B48"
#define  TWO_STEP_UZU_SR_Debug2_reg                                              0xB8029B48
#define  TWO_STEP_UZU_SR_Debug2_inst_addr                                        "0x002E"
#define  set_TWO_STEP_UZU_SR_Debug2_reg(data)                                    (*((volatile unsigned int*)TWO_STEP_UZU_SR_Debug2_reg)=data)
#define  get_TWO_STEP_UZU_SR_Debug2_reg                                          (*((volatile unsigned int*)TWO_STEP_UZU_SR_Debug2_reg))
#define  TWO_STEP_UZU_SR_Debug2_sr_dbg_v_sta_shift                               (16)
#define  TWO_STEP_UZU_SR_Debug2_sr_dbg_v_end_shift                               (0)
#define  TWO_STEP_UZU_SR_Debug2_sr_dbg_v_sta_mask                                (0x0FFF0000)
#define  TWO_STEP_UZU_SR_Debug2_sr_dbg_v_end_mask                                (0x00000FFF)
#define  TWO_STEP_UZU_SR_Debug2_sr_dbg_v_sta(data)                               (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_Debug2_sr_dbg_v_end(data)                               (0x00000FFF&(data))
#define  TWO_STEP_UZU_SR_Debug2_get_sr_dbg_v_sta(data)                           ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_Debug2_get_sr_dbg_v_end(data)                           (0x00000FFF&(data))

#define  TWO_STEP_UZU_SR_CRC_Ctrl1                                               0x18029B4C
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_reg_addr                                      "0xB8029B4C"
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_reg                                           0xB8029B4C
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_inst_addr                                     "0x002F"
#define  set_TWO_STEP_UZU_SR_CRC_Ctrl1_reg(data)                                 (*((volatile unsigned int*)TWO_STEP_UZU_SR_CRC_Ctrl1_reg)=data)
#define  get_TWO_STEP_UZU_SR_CRC_Ctrl1_reg                                       (*((volatile unsigned int*)TWO_STEP_UZU_SR_CRC_Ctrl1_reg))
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_dummy_31_2_shift                              (2)
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_sr_crc_conti_shift                            (1)
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_sr_crc_start_shift                            (0)
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_dummy_31_2_mask                               (0xFFFFFFFC)
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_sr_crc_conti_mask                             (0x00000002)
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_sr_crc_start_mask                             (0x00000001)
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_dummy_31_2(data)                              (0xFFFFFFFC&((data)<<2))
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_sr_crc_conti(data)                            (0x00000002&((data)<<1))
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_sr_crc_start(data)                            (0x00000001&(data))
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_get_dummy_31_2(data)                          ((0xFFFFFFFC&(data))>>2)
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_get_sr_crc_conti(data)                        ((0x00000002&(data))>>1)
#define  TWO_STEP_UZU_SR_CRC_Ctrl1_get_sr_crc_start(data)                        (0x00000001&(data))

#define  TWO_STEP_UZU_SR_CRC_Result1                                             0x18029B50
#define  TWO_STEP_UZU_SR_CRC_Result1_reg_addr                                    "0xB8029B50"
#define  TWO_STEP_UZU_SR_CRC_Result1_reg                                         0xB8029B50
#define  TWO_STEP_UZU_SR_CRC_Result1_inst_addr                                   "0x0030"
#define  set_TWO_STEP_UZU_SR_CRC_Result1_reg(data)                               (*((volatile unsigned int*)TWO_STEP_UZU_SR_CRC_Result1_reg)=data)
#define  get_TWO_STEP_UZU_SR_CRC_Result1_reg                                     (*((volatile unsigned int*)TWO_STEP_UZU_SR_CRC_Result1_reg))
#define  TWO_STEP_UZU_SR_CRC_Result1_sr_crc_cur_result_shift                     (0)
#define  TWO_STEP_UZU_SR_CRC_Result1_sr_crc_cur_result_mask                      (0xFFFFFFFF)
#define  TWO_STEP_UZU_SR_CRC_Result1_sr_crc_cur_result(data)                     (0xFFFFFFFF&(data))
#define  TWO_STEP_UZU_SR_CRC_Result1_get_sr_crc_cur_result(data)                 (0xFFFFFFFF&(data))

#define  TWO_STEP_UZU_SR_DB_CTRL                                                 0x18029B54
#define  TWO_STEP_UZU_SR_DB_CTRL_reg_addr                                        "0xB8029B54"
#define  TWO_STEP_UZU_SR_DB_CTRL_reg                                             0xB8029B54
#define  TWO_STEP_UZU_SR_DB_CTRL_inst_addr                                       "0x0031"
#define  set_TWO_STEP_UZU_SR_DB_CTRL_reg(data)                                   (*((volatile unsigned int*)TWO_STEP_UZU_SR_DB_CTRL_reg)=data)
#define  get_TWO_STEP_UZU_SR_DB_CTRL_reg                                         (*((volatile unsigned int*)TWO_STEP_UZU_SR_DB_CTRL_reg))
#define  TWO_STEP_UZU_SR_DB_CTRL_db_en_shift                                     (2)
#define  TWO_STEP_UZU_SR_DB_CTRL_db_read_level_shift                             (1)
#define  TWO_STEP_UZU_SR_DB_CTRL_db_apply_shift                                  (0)
#define  TWO_STEP_UZU_SR_DB_CTRL_db_en_mask                                      (0x00000004)
#define  TWO_STEP_UZU_SR_DB_CTRL_db_read_level_mask                              (0x00000002)
#define  TWO_STEP_UZU_SR_DB_CTRL_db_apply_mask                                   (0x00000001)
#define  TWO_STEP_UZU_SR_DB_CTRL_db_en(data)                                     (0x00000004&((data)<<2))
#define  TWO_STEP_UZU_SR_DB_CTRL_db_read_level(data)                             (0x00000002&((data)<<1))
#define  TWO_STEP_UZU_SR_DB_CTRL_db_apply(data)                                  (0x00000001&(data))
#define  TWO_STEP_UZU_SR_DB_CTRL_get_db_en(data)                                 ((0x00000004&(data))>>2)
#define  TWO_STEP_UZU_SR_DB_CTRL_get_db_read_level(data)                         ((0x00000002&(data))>>1)
#define  TWO_STEP_UZU_SR_DB_CTRL_get_db_apply(data)                              (0x00000001&(data))

#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST                                          0x18029B58
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_reg_addr                                 "0xB8029B58"
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_reg                                      0xB8029B58
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_inst_addr                                "0x0032"
#define  set_TWO_STEP_UZU_TWO_STEP_UZU_BIST_reg(data)                            (*((volatile unsigned int*)TWO_STEP_UZU_TWO_STEP_UZU_BIST_reg)=data)
#define  get_TWO_STEP_UZU_TWO_STEP_UZU_BIST_reg                                  (*((volatile unsigned int*)TWO_STEP_UZU_TWO_STEP_UZU_BIST_reg))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_ls_shift                                 (31)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_rme_shift                                (30)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_rm_shift                                 (24)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_3_shift                    (7)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_2_shift                    (6)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_1_shift                    (5)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_0_shift                    (4)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_3_shift                        (3)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_2_shift                        (2)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_1_shift                        (1)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_0_shift                        (0)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_ls_mask                                  (0x80000000)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_rme_mask                                 (0x40000000)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_rm_mask                                  (0x0F000000)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_3_mask                     (0x00000080)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_2_mask                     (0x00000040)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_1_mask                     (0x00000020)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_0_mask                     (0x00000010)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_3_mask                         (0x00000008)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_2_mask                         (0x00000004)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_1_mask                         (0x00000002)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_0_mask                         (0x00000001)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_ls(data)                                 (0x80000000&((data)<<31))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_rme(data)                                (0x40000000&((data)<<30))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_rm(data)                                 (0x0F000000&((data)<<24))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_3(data)                    (0x00000080&((data)<<7))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_2(data)                    (0x00000040&((data)<<6))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_1(data)                    (0x00000020&((data)<<5))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_drf_bist_fail_0(data)                    (0x00000010&((data)<<4))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_3(data)                        (0x00000008&((data)<<3))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_2(data)                        (0x00000004&((data)<<2))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_1(data)                        (0x00000002&((data)<<1))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_bist_fail_0(data)                        (0x00000001&(data))
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_ls(data)                             ((0x80000000&(data))>>31)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_rme(data)                            ((0x40000000&(data))>>30)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_rm(data)                             ((0x0F000000&(data))>>24)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_drf_bist_fail_3(data)                ((0x00000080&(data))>>7)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_drf_bist_fail_2(data)                ((0x00000040&(data))>>6)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_drf_bist_fail_1(data)                ((0x00000020&(data))>>5)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_drf_bist_fail_0(data)                ((0x00000010&(data))>>4)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_bist_fail_3(data)                    ((0x00000008&(data))>>3)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_bist_fail_2(data)                    ((0x00000004&(data))>>2)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_bist_fail_1(data)                    ((0x00000002&(data))>>1)
#define  TWO_STEP_UZU_TWO_STEP_UZU_BIST_get_bist_fail_0(data)                    (0x00000001&(data))

#define  TWO_STEP_UZU_SR_Timing_0                                                0x18029B60
#define  TWO_STEP_UZU_SR_Timing_0_reg_addr                                       "0xB8029B60"
#define  TWO_STEP_UZU_SR_Timing_0_reg                                            0xB8029B60
#define  TWO_STEP_UZU_SR_Timing_0_inst_addr                                      "0x0033"
#define  set_TWO_STEP_UZU_SR_Timing_0_reg(data)                                  (*((volatile unsigned int*)TWO_STEP_UZU_SR_Timing_0_reg)=data)
#define  get_TWO_STEP_UZU_SR_Timing_0_reg                                        (*((volatile unsigned int*)TWO_STEP_UZU_SR_Timing_0_reg))
#define  TWO_STEP_UZU_SR_Timing_0_rd_line_wr_st_en_shift                         (31)
#define  TWO_STEP_UZU_SR_Timing_0_rd_line0_wr_line_shift                         (16)
#define  TWO_STEP_UZU_SR_Timing_0_rd_line0_wr_pxl_shift                          (0)
#define  TWO_STEP_UZU_SR_Timing_0_rd_line_wr_st_en_mask                          (0x80000000)
#define  TWO_STEP_UZU_SR_Timing_0_rd_line0_wr_line_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_SR_Timing_0_rd_line0_wr_pxl_mask                           (0x00000FFF)
#define  TWO_STEP_UZU_SR_Timing_0_rd_line_wr_st_en(data)                         (0x80000000&((data)<<31))
#define  TWO_STEP_UZU_SR_Timing_0_rd_line0_wr_line(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_Timing_0_rd_line0_wr_pxl(data)                          (0x00000FFF&(data))
#define  TWO_STEP_UZU_SR_Timing_0_get_rd_line_wr_st_en(data)                     ((0x80000000&(data))>>31)
#define  TWO_STEP_UZU_SR_Timing_0_get_rd_line0_wr_line(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_Timing_0_get_rd_line0_wr_pxl(data)                      (0x00000FFF&(data))

#define  TWO_STEP_UZU_SR_Timing_1                                                0x18029B64
#define  TWO_STEP_UZU_SR_Timing_1_reg_addr                                       "0xB8029B64"
#define  TWO_STEP_UZU_SR_Timing_1_reg                                            0xB8029B64
#define  TWO_STEP_UZU_SR_Timing_1_inst_addr                                      "0x0034"
#define  set_TWO_STEP_UZU_SR_Timing_1_reg(data)                                  (*((volatile unsigned int*)TWO_STEP_UZU_SR_Timing_1_reg)=data)
#define  get_TWO_STEP_UZU_SR_Timing_1_reg                                        (*((volatile unsigned int*)TWO_STEP_UZU_SR_Timing_1_reg))
#define  TWO_STEP_UZU_SR_Timing_1_rd_line1_wr_line_shift                         (16)
#define  TWO_STEP_UZU_SR_Timing_1_rd_line1_wr_pxl_shift                          (0)
#define  TWO_STEP_UZU_SR_Timing_1_rd_line1_wr_line_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_SR_Timing_1_rd_line1_wr_pxl_mask                           (0x00000FFF)
#define  TWO_STEP_UZU_SR_Timing_1_rd_line1_wr_line(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_Timing_1_rd_line1_wr_pxl(data)                          (0x00000FFF&(data))
#define  TWO_STEP_UZU_SR_Timing_1_get_rd_line1_wr_line(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_Timing_1_get_rd_line1_wr_pxl(data)                      (0x00000FFF&(data))

#define  TWO_STEP_UZU_SR_Timing_2                                                0x18029B68
#define  TWO_STEP_UZU_SR_Timing_2_reg_addr                                       "0xB8029B68"
#define  TWO_STEP_UZU_SR_Timing_2_reg                                            0xB8029B68
#define  TWO_STEP_UZU_SR_Timing_2_inst_addr                                      "0x0035"
#define  set_TWO_STEP_UZU_SR_Timing_2_reg(data)                                  (*((volatile unsigned int*)TWO_STEP_UZU_SR_Timing_2_reg)=data)
#define  get_TWO_STEP_UZU_SR_Timing_2_reg                                        (*((volatile unsigned int*)TWO_STEP_UZU_SR_Timing_2_reg))
#define  TWO_STEP_UZU_SR_Timing_2_rd_line2_wr_line_shift                         (16)
#define  TWO_STEP_UZU_SR_Timing_2_rd_line2_wr_pxl_shift                          (0)
#define  TWO_STEP_UZU_SR_Timing_2_rd_line2_wr_line_mask                          (0x0FFF0000)
#define  TWO_STEP_UZU_SR_Timing_2_rd_line2_wr_pxl_mask                           (0x00000FFF)
#define  TWO_STEP_UZU_SR_Timing_2_rd_line2_wr_line(data)                         (0x0FFF0000&((data)<<16))
#define  TWO_STEP_UZU_SR_Timing_2_rd_line2_wr_pxl(data)                          (0x00000FFF&(data))
#define  TWO_STEP_UZU_SR_Timing_2_get_rd_line2_wr_line(data)                     ((0x0FFF0000&(data))>>16)
#define  TWO_STEP_UZU_SR_Timing_2_get_rd_line2_wr_pxl(data)                      (0x00000FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TWO_STEP_UZU register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  two_step_uzu_ratio:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
    };
}two_step_uzu_two_step_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mflti_en:1;
        RBus_UInt32  mflti_blend_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mflti_blend_gain:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  mflti_blend_offset:6;
        RBus_UInt32  h_range:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:13;
    };
}two_step_uzu_mflti_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dering_edgelevel_gain:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  sr_hor_tap_sel:2;
    };
}two_step_uzu_sr_12tap_dering_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  level_flatness_coeff:3;
        RBus_UInt32  dering_dbg_mode:2;
        RBus_UInt32  h4h12_blend_range:2;
        RBus_UInt32  h4h12_blend_lowbound:8;
        RBus_UInt32  lpf_blend_mask_sel:1;
        RBus_UInt32  level_maxmin_coeff:3;
        RBus_UInt32  h4h12_blend_en:1;
        RBus_UInt32  lpf_blend_en:1;
        RBus_UInt32  lpf_blend_range:2;
        RBus_UInt32  lpf_blend_lowbound:8;
    };
}two_step_uzu_sr_12tap_dering_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_maxmin_shift:8;
        RBus_UInt32  sr_var_thd:8;
        RBus_UInt32  sr_maxmin_limit_en:1;
        RBus_UInt32  sr_hor_ini:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  sr_ver_ini:7;
    };
}two_step_uzu_sr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c0_0:12;
    };
}two_step_uzu_h12_y_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c0_2:12;
    };
}two_step_uzu_h12_y_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_5:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c0_4:12;
    };
}two_step_uzu_h12_y_ph0_coeff02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_7:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c0_6:12;
    };
}two_step_uzu_h12_y_ph0_coeff03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_9:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c0_8:12;
    };
}two_step_uzu_h12_y_ph0_coeff04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_11:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c0_10:12;
    };
}two_step_uzu_h12_y_ph0_coeff05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c1_0:12;
    };
}two_step_uzu_h12_y_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c1_2:12;
    };
}two_step_uzu_h12_y_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_5:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c1_4:12;
    };
}two_step_uzu_h12_y_ph1_coeff02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_7:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c1_6:12;
    };
}two_step_uzu_h12_y_ph1_coeff03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_9:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c1_8:12;
    };
}two_step_uzu_h12_y_ph1_coeff04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_11:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h12_y_c1_10:12;
    };
}two_step_uzu_h12_y_ph1_coeff05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_y_c0_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h4_y_c0_0:12;
    };
}two_step_uzu_h4_y_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_y_c0_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h4_y_c0_2:12;
    };
}two_step_uzu_h4_y_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_y_c1_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h4_y_c1_0:12;
    };
}two_step_uzu_h4_y_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_y_c1_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h4_y_c1_2:12;
    };
}two_step_uzu_h4_y_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_y_c0_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v4_y_c0_0:12;
    };
}two_step_uzu_v4_y_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_y_c0_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v4_y_c0_2:12;
    };
}two_step_uzu_v4_y_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_y_c1_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v4_y_c1_0:12;
    };
}two_step_uzu_v4_y_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_y_c1_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v4_y_c1_2:12;
    };
}two_step_uzu_v4_y_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_c_c0_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h4_c_c0_0:12;
    };
}two_step_uzu_h4_c_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_c_c0_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h4_c_c0_2:12;
    };
}two_step_uzu_h4_c_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_c_c1_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h4_c_c1_0:12;
    };
}two_step_uzu_h4_c_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_c_c1_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  h4_c_c1_2:12;
    };
}two_step_uzu_h4_c_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_c_c0_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v4_c_c0_0:12;
    };
}two_step_uzu_v4_c_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_c_c0_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v4_c_c0_2:12;
    };
}two_step_uzu_v4_c_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_c_c1_1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v4_c_c1_0:12;
    };
}two_step_uzu_v4_c_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_c_c1_3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  v4_c_c1_2:12;
    };
}two_step_uzu_v4_c_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sr_maxmin_thd:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  sr_maxmin_mode:1;
        RBus_UInt32  sr_maxmin_range:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sr_delta_gain:2;
        RBus_UInt32  sr_edge_range:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sr_lpf_range:1;
    };
}two_step_uzu_sr_filter_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_thd0:8;
        RBus_UInt32  sr_bif_thd1:8;
        RBus_UInt32  sr_bif_thd2:8;
        RBus_UInt32  sr_bif_thd3:8;
    };
}two_step_uzu_sr_filter_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_thd4:8;
        RBus_UInt32  sr_bif_thd5:8;
        RBus_UInt32  sr_bif_thd6:8;
        RBus_UInt32  sr_bif_thd7:8;
    };
}two_step_uzu_sr_filter_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain0:8;
        RBus_UInt32  sr_by_ngain0:8;
        RBus_UInt32  sr_lpf_gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  sr_bif_gain:6;
        RBus_UInt32  sr_diffdir_cond_en:1;
        RBus_UInt32  sr_by_gain_en:1;
    };
}two_step_uzu_sr_gainy_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain1:8;
        RBus_UInt32  sr_by_pgain2:8;
        RBus_UInt32  sr_by_pgain3:8;
        RBus_UInt32  sr_by_pgain4:8;
    };
}two_step_uzu_sr_gainy_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain5:8;
        RBus_UInt32  sr_by_pgain6:8;
        RBus_UInt32  sr_by_pgain7:8;
        RBus_UInt32  sr_by_pgain8:8;
    };
}two_step_uzu_sr_gainy_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_ngain1:8;
        RBus_UInt32  sr_by_ngain2:8;
        RBus_UInt32  sr_by_ngain3:8;
        RBus_UInt32  sr_by_ngain4:8;
    };
}two_step_uzu_sr_gainy_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_ngain5:8;
        RBus_UInt32  sr_by_ngain6:8;
        RBus_UInt32  sr_by_ngain7:8;
        RBus_UInt32  sr_by_ngain8:8;
    };
}two_step_uzu_sr_gainy_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_lpf_range_thd:8;
        RBus_UInt32  sr_lpf_range_gain:5;
        RBus_UInt32  sr_lpf_range_step:2;
        RBus_UInt32  sr_lpf_range_en:1;
        RBus_UInt32  sr_lpf_edge_thd:8;
        RBus_UInt32  sr_lpf_edge_gain:5;
        RBus_UInt32  sr_lpf_edge_step:2;
        RBus_UInt32  sr_lpf_edge_en:1;
    };
}two_step_uzu_sr_gainmap_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_range_thd0:8;
        RBus_UInt32  sr_bif_range_thd1:8;
        RBus_UInt32  sr_bif_range_gain0:5;
        RBus_UInt32  sr_bif_range_step0:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  sr_bif_range_gain1:5;
        RBus_UInt32  sr_bif_range_step1:2;
        RBus_UInt32  sr_bif_range_en:1;
    };
}two_step_uzu_sr_gainmap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sr_bif_edge_thd:8;
        RBus_UInt32  sr_bif_edge_gain:5;
        RBus_UInt32  sr_bif_edge_step:2;
        RBus_UInt32  sr_bif_edge_en:1;
    };
}two_step_uzu_sr_gainmap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sr_dbg_mode:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  sr_dbg_inv:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sr_dbg_en:1;
    };
}two_step_uzu_sr_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  sr_dbg_h_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sr_dbg_h_end:12;
    };
}two_step_uzu_sr_debug1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  sr_dbg_v_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sr_dbg_v_end:12;
    };
}two_step_uzu_sr_debug2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029b4c_31_2:30;
        RBus_UInt32  sr_crc_conti:1;
        RBus_UInt32  sr_crc_start:1;
    };
}two_step_uzu_sr_crc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_crc_cur_result:32;
    };
}two_step_uzu_sr_crc_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
    };
}two_step_uzu_sr_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rm:4;
        RBus_UInt32  res2:16;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}two_step_uzu_two_step_uzu_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_line_wr_st_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rd_line0_wr_line:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  rd_line0_wr_pxl:12;
    };
}two_step_uzu_sr_timing_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rd_line1_wr_line:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  rd_line1_wr_pxl:12;
    };
}two_step_uzu_sr_timing_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rd_line2_wr_line:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  rd_line2_wr_pxl:12;
    };
}two_step_uzu_sr_timing_2_RBUS;

#else //apply LITTLE_ENDIAN

//======TWO_STEP_UZU register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  two_step_uzu_ratio:1;
        RBus_UInt32  res3:29;
    };
}two_step_uzu_two_step_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  res2:1;
        RBus_UInt32  h_range:2;
        RBus_UInt32  mflti_blend_offset:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  mflti_blend_gain:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  mflti_blend_en:1;
        RBus_UInt32  mflti_en:1;
    };
}two_step_uzu_mflti_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_hor_tap_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  dering_edgelevel_gain:4;
        RBus_UInt32  res2:24;
    };
}two_step_uzu_sr_12tap_dering_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpf_blend_lowbound:8;
        RBus_UInt32  lpf_blend_range:2;
        RBus_UInt32  lpf_blend_en:1;
        RBus_UInt32  h4h12_blend_en:1;
        RBus_UInt32  level_maxmin_coeff:3;
        RBus_UInt32  lpf_blend_mask_sel:1;
        RBus_UInt32  h4h12_blend_lowbound:8;
        RBus_UInt32  h4h12_blend_range:2;
        RBus_UInt32  dering_dbg_mode:2;
        RBus_UInt32  level_flatness_coeff:3;
        RBus_UInt32  res1:1;
    };
}two_step_uzu_sr_12tap_dering_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_ini:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  sr_hor_ini:7;
        RBus_UInt32  sr_maxmin_limit_en:1;
        RBus_UInt32  sr_var_thd:8;
        RBus_UInt32  sr_maxmin_shift:8;
    };
}two_step_uzu_sr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c0_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c0_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c0_4:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_5:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph0_coeff02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c0_6:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_7:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph0_coeff03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c0_8:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_9:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph0_coeff04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c0_10:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c0_11:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph0_coeff05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c1_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c1_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c1_4:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_5:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph1_coeff02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c1_6:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_7:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph1_coeff03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c1_8:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_9:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph1_coeff04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h12_y_c1_10:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h12_y_c1_11:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h12_y_ph1_coeff05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h4_y_c0_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_y_c0_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h4_y_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h4_y_c0_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_y_c0_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h4_y_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h4_y_c1_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_y_c1_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h4_y_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h4_y_c1_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_y_c1_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h4_y_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v4_y_c0_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_y_c0_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_v4_y_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v4_y_c0_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_y_c0_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_v4_y_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v4_y_c1_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_y_c1_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_v4_y_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v4_y_c1_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_y_c1_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_v4_y_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h4_c_c0_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_c_c0_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h4_c_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h4_c_c0_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_c_c0_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h4_c_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h4_c_c1_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_c_c1_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h4_c_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h4_c_c1_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  h4_c_c1_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_h4_c_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v4_c_c0_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_c_c0_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_v4_c_ph0_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v4_c_c0_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_c_c0_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_v4_c_ph0_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v4_c_c1_0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_c_c1_1:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_v4_c_ph1_coeff00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v4_c_c1_2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  v4_c_c1_3:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_v4_c_ph1_coeff01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_lpf_range:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sr_edge_range:1;
        RBus_UInt32  sr_delta_gain:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  sr_maxmin_range:1;
        RBus_UInt32  sr_maxmin_mode:1;
        RBus_UInt32  res3:6;
        RBus_UInt32  sr_maxmin_thd:8;
        RBus_UInt32  res4:8;
    };
}two_step_uzu_sr_filter_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_thd3:8;
        RBus_UInt32  sr_bif_thd2:8;
        RBus_UInt32  sr_bif_thd1:8;
        RBus_UInt32  sr_bif_thd0:8;
    };
}two_step_uzu_sr_filter_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_thd7:8;
        RBus_UInt32  sr_bif_thd6:8;
        RBus_UInt32  sr_bif_thd5:8;
        RBus_UInt32  sr_bif_thd4:8;
    };
}two_step_uzu_sr_filter_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_gain_en:1;
        RBus_UInt32  sr_diffdir_cond_en:1;
        RBus_UInt32  sr_bif_gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  sr_lpf_gain:6;
        RBus_UInt32  sr_by_ngain0:8;
        RBus_UInt32  sr_by_pgain0:8;
    };
}two_step_uzu_sr_gainy_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain4:8;
        RBus_UInt32  sr_by_pgain3:8;
        RBus_UInt32  sr_by_pgain2:8;
        RBus_UInt32  sr_by_pgain1:8;
    };
}two_step_uzu_sr_gainy_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_pgain8:8;
        RBus_UInt32  sr_by_pgain7:8;
        RBus_UInt32  sr_by_pgain6:8;
        RBus_UInt32  sr_by_pgain5:8;
    };
}two_step_uzu_sr_gainy_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_ngain4:8;
        RBus_UInt32  sr_by_ngain3:8;
        RBus_UInt32  sr_by_ngain2:8;
        RBus_UInt32  sr_by_ngain1:8;
    };
}two_step_uzu_sr_gainy_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_by_ngain8:8;
        RBus_UInt32  sr_by_ngain7:8;
        RBus_UInt32  sr_by_ngain6:8;
        RBus_UInt32  sr_by_ngain5:8;
    };
}two_step_uzu_sr_gainy_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_lpf_edge_en:1;
        RBus_UInt32  sr_lpf_edge_step:2;
        RBus_UInt32  sr_lpf_edge_gain:5;
        RBus_UInt32  sr_lpf_edge_thd:8;
        RBus_UInt32  sr_lpf_range_en:1;
        RBus_UInt32  sr_lpf_range_step:2;
        RBus_UInt32  sr_lpf_range_gain:5;
        RBus_UInt32  sr_lpf_range_thd:8;
    };
}two_step_uzu_sr_gainmap_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_range_en:1;
        RBus_UInt32  sr_bif_range_step1:2;
        RBus_UInt32  sr_bif_range_gain1:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  sr_bif_range_step0:2;
        RBus_UInt32  sr_bif_range_gain0:5;
        RBus_UInt32  sr_bif_range_thd1:8;
        RBus_UInt32  sr_bif_range_thd0:8;
    };
}two_step_uzu_sr_gainmap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_bif_edge_en:1;
        RBus_UInt32  sr_bif_edge_step:2;
        RBus_UInt32  sr_bif_edge_gain:5;
        RBus_UInt32  sr_bif_edge_thd:8;
        RBus_UInt32  res1:16;
    };
}two_step_uzu_sr_gainmap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_dbg_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sr_dbg_inv:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sr_dbg_mode:4;
        RBus_UInt32  res3:20;
    };
}two_step_uzu_sr_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_dbg_h_end:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  sr_dbg_h_sta:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_sr_debug1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_dbg_v_end:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  sr_dbg_v_sta:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_sr_debug2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_crc_start:1;
        RBus_UInt32  sr_crc_conti:1;
        RBus_UInt32  dummy18029b4c_31:30;
    };
}two_step_uzu_sr_crc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_crc_cur_result:32;
    };
}two_step_uzu_sr_crc_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  res1:29;
    };
}two_step_uzu_sr_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  rm:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  rme:1;
        RBus_UInt32  ls:1;
    };
}two_step_uzu_two_step_uzu_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_line0_wr_pxl:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  rd_line0_wr_line:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  rd_line_wr_st_en:1;
    };
}two_step_uzu_sr_timing_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_line1_wr_pxl:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  rd_line1_wr_line:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_sr_timing_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_line2_wr_pxl:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  rd_line2_wr_line:12;
        RBus_UInt32  res2:4;
    };
}two_step_uzu_sr_timing_2_RBUS;




#endif 


#endif 
