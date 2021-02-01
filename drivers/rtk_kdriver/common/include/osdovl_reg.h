/**
* @file rbusOsdOvlReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_OSDOVL_REG_H_
#define _RBUS_OSDOVL_REG_H_

#include "rbus_types.h"



//  OSDOVL Register Address
#define  OSDOVL_Mixer_CTRL2                                                      0x1802B000
#define  OSDOVL_Mixer_CTRL2_reg_addr                                             "0xB802B000"
#define  OSDOVL_Mixer_CTRL2_reg                                                  0xB802B000
#define  OSDOVL_Mixer_CTRL2_inst_addr                                            "0x0000"
#define  set_OSDOVL_Mixer_CTRL2_reg(data)                                        (*((volatile unsigned int*)OSDOVL_Mixer_CTRL2_reg)=data)
#define  get_OSDOVL_Mixer_CTRL2_reg                                              (*((volatile unsigned int*)OSDOVL_Mixer_CTRL2_reg))
#define  OSDOVL_Mixer_CTRL2_measure_osd_zone_en_shift                            (31)
#define  OSDOVL_Mixer_CTRL2_measure_osd_zone_type_shift                          (30)
#define  OSDOVL_Mixer_CTRL2_video_src_sel_shift                                  (24)
#define  OSDOVL_Mixer_CTRL2_video_alpha_shift                                    (16)
#define  OSDOVL_Mixer_CTRL2_mixero6_en_shift                                     (6)
#define  OSDOVL_Mixer_CTRL2_mixero5_en_shift                                     (5)
#define  OSDOVL_Mixer_CTRL2_mixero4_en_shift                                     (4)
#define  OSDOVL_Mixer_CTRL2_mixero3_en_shift                                     (3)
#define  OSDOVL_Mixer_CTRL2_mixero2_en_shift                                     (2)
#define  OSDOVL_Mixer_CTRL2_mixero1_en_shift                                     (1)
#define  OSDOVL_Mixer_CTRL2_mixer_en_shift                                       (0)
#define  OSDOVL_Mixer_CTRL2_measure_osd_zone_en_mask                             (0x80000000)
#define  OSDOVL_Mixer_CTRL2_measure_osd_zone_type_mask                           (0x40000000)
#define  OSDOVL_Mixer_CTRL2_video_src_sel_mask                                   (0x01000000)
#define  OSDOVL_Mixer_CTRL2_video_alpha_mask                                     (0x00FF0000)
#define  OSDOVL_Mixer_CTRL2_mixero6_en_mask                                      (0x00000040)
#define  OSDOVL_Mixer_CTRL2_mixero5_en_mask                                      (0x00000020)
#define  OSDOVL_Mixer_CTRL2_mixero4_en_mask                                      (0x00000010)
#define  OSDOVL_Mixer_CTRL2_mixero3_en_mask                                      (0x00000008)
#define  OSDOVL_Mixer_CTRL2_mixero2_en_mask                                      (0x00000004)
#define  OSDOVL_Mixer_CTRL2_mixero1_en_mask                                      (0x00000002)
#define  OSDOVL_Mixer_CTRL2_mixer_en_mask                                        (0x00000001)
#define  OSDOVL_Mixer_CTRL2_measure_osd_zone_en(data)                            (0x80000000&((data)<<31))
#define  OSDOVL_Mixer_CTRL2_measure_osd_zone_type(data)                          (0x40000000&((data)<<30))
#define  OSDOVL_Mixer_CTRL2_video_src_sel(data)                                  (0x01000000&((data)<<24))
#define  OSDOVL_Mixer_CTRL2_video_alpha(data)                                    (0x00FF0000&((data)<<16))
#define  OSDOVL_Mixer_CTRL2_mixero6_en(data)                                     (0x00000040&((data)<<6))
#define  OSDOVL_Mixer_CTRL2_mixero5_en(data)                                     (0x00000020&((data)<<5))
#define  OSDOVL_Mixer_CTRL2_mixero4_en(data)                                     (0x00000010&((data)<<4))
#define  OSDOVL_Mixer_CTRL2_mixero3_en(data)                                     (0x00000008&((data)<<3))
#define  OSDOVL_Mixer_CTRL2_mixero2_en(data)                                     (0x00000004&((data)<<2))
#define  OSDOVL_Mixer_CTRL2_mixero1_en(data)                                     (0x00000002&((data)<<1))
#define  OSDOVL_Mixer_CTRL2_mixer_en(data)                                       (0x00000001&(data))
#define  OSDOVL_Mixer_CTRL2_get_measure_osd_zone_en(data)                        ((0x80000000&(data))>>31)
#define  OSDOVL_Mixer_CTRL2_get_measure_osd_zone_type(data)                      ((0x40000000&(data))>>30)
#define  OSDOVL_Mixer_CTRL2_get_video_src_sel(data)                              ((0x01000000&(data))>>24)
#define  OSDOVL_Mixer_CTRL2_get_video_alpha(data)                                ((0x00FF0000&(data))>>16)
#define  OSDOVL_Mixer_CTRL2_get_mixero6_en(data)                                 ((0x00000040&(data))>>6)
#define  OSDOVL_Mixer_CTRL2_get_mixero5_en(data)                                 ((0x00000020&(data))>>5)
#define  OSDOVL_Mixer_CTRL2_get_mixero4_en(data)                                 ((0x00000010&(data))>>4)
#define  OSDOVL_Mixer_CTRL2_get_mixero3_en(data)                                 ((0x00000008&(data))>>3)
#define  OSDOVL_Mixer_CTRL2_get_mixero2_en(data)                                 ((0x00000004&(data))>>2)
#define  OSDOVL_Mixer_CTRL2_get_mixero1_en(data)                                 ((0x00000002&(data))>>1)
#define  OSDOVL_Mixer_CTRL2_get_mixer_en(data)                                   (0x00000001&(data))

#define  OSDOVL_Mixer_layer_sel                                                  0x1802B004
#define  OSDOVL_Mixer_layer_sel_reg_addr                                         "0xB802B004"
#define  OSDOVL_Mixer_layer_sel_reg                                              0xB802B004
#define  OSDOVL_Mixer_layer_sel_inst_addr                                        "0x0001"
#define  set_OSDOVL_Mixer_layer_sel_reg(data)                                    (*((volatile unsigned int*)OSDOVL_Mixer_layer_sel_reg)=data)
#define  get_OSDOVL_Mixer_layer_sel_reg                                          (*((volatile unsigned int*)OSDOVL_Mixer_layer_sel_reg))
#define  OSDOVL_Mixer_layer_sel_c5_plane_alpha_en_shift                          (29)
#define  OSDOVL_Mixer_layer_sel_c4_plane_alpha_en_shift                          (28)
#define  OSDOVL_Mixer_layer_sel_c3_plane_alpha_en_shift                          (27)
#define  OSDOVL_Mixer_layer_sel_c2_plane_alpha_en_shift                          (26)
#define  OSDOVL_Mixer_layer_sel_c1_plane_alpha_en_shift                          (25)
#define  OSDOVL_Mixer_layer_sel_c0_plane_alpha_en_shift                          (24)
#define  OSDOVL_Mixer_layer_sel_c5_sel_shift                                     (20)
#define  OSDOVL_Mixer_layer_sel_c4_sel_shift                                     (16)
#define  OSDOVL_Mixer_layer_sel_c3_sel_shift                                     (12)
#define  OSDOVL_Mixer_layer_sel_c2_sel_shift                                     (8)
#define  OSDOVL_Mixer_layer_sel_c1_sel_shift                                     (4)
#define  OSDOVL_Mixer_layer_sel_c0_sel_shift                                     (0)
#define  OSDOVL_Mixer_layer_sel_c5_plane_alpha_en_mask                           (0x20000000)
#define  OSDOVL_Mixer_layer_sel_c4_plane_alpha_en_mask                           (0x10000000)
#define  OSDOVL_Mixer_layer_sel_c3_plane_alpha_en_mask                           (0x08000000)
#define  OSDOVL_Mixer_layer_sel_c2_plane_alpha_en_mask                           (0x04000000)
#define  OSDOVL_Mixer_layer_sel_c1_plane_alpha_en_mask                           (0x02000000)
#define  OSDOVL_Mixer_layer_sel_c0_plane_alpha_en_mask                           (0x01000000)
#define  OSDOVL_Mixer_layer_sel_c5_sel_mask                                      (0x00700000)
#define  OSDOVL_Mixer_layer_sel_c4_sel_mask                                      (0x00070000)
#define  OSDOVL_Mixer_layer_sel_c3_sel_mask                                      (0x00007000)
#define  OSDOVL_Mixer_layer_sel_c2_sel_mask                                      (0x00000700)
#define  OSDOVL_Mixer_layer_sel_c1_sel_mask                                      (0x00000070)
#define  OSDOVL_Mixer_layer_sel_c0_sel_mask                                      (0x00000007)
#define  OSDOVL_Mixer_layer_sel_c5_plane_alpha_en(data)                          (0x20000000&((data)<<29))
#define  OSDOVL_Mixer_layer_sel_c4_plane_alpha_en(data)                          (0x10000000&((data)<<28))
#define  OSDOVL_Mixer_layer_sel_c3_plane_alpha_en(data)                          (0x08000000&((data)<<27))
#define  OSDOVL_Mixer_layer_sel_c2_plane_alpha_en(data)                          (0x04000000&((data)<<26))
#define  OSDOVL_Mixer_layer_sel_c1_plane_alpha_en(data)                          (0x02000000&((data)<<25))
#define  OSDOVL_Mixer_layer_sel_c0_plane_alpha_en(data)                          (0x01000000&((data)<<24))
#define  OSDOVL_Mixer_layer_sel_c5_sel(data)                                     (0x00700000&((data)<<20))
#define  OSDOVL_Mixer_layer_sel_c4_sel(data)                                     (0x00070000&((data)<<16))
#define  OSDOVL_Mixer_layer_sel_c3_sel(data)                                     (0x00007000&((data)<<12))
#define  OSDOVL_Mixer_layer_sel_c2_sel(data)                                     (0x00000700&((data)<<8))
#define  OSDOVL_Mixer_layer_sel_c1_sel(data)                                     (0x00000070&((data)<<4))
#define  OSDOVL_Mixer_layer_sel_c0_sel(data)                                     (0x00000007&(data))
#define  OSDOVL_Mixer_layer_sel_get_c5_plane_alpha_en(data)                      ((0x20000000&(data))>>29)
#define  OSDOVL_Mixer_layer_sel_get_c4_plane_alpha_en(data)                      ((0x10000000&(data))>>28)
#define  OSDOVL_Mixer_layer_sel_get_c3_plane_alpha_en(data)                      ((0x08000000&(data))>>27)
#define  OSDOVL_Mixer_layer_sel_get_c2_plane_alpha_en(data)                      ((0x04000000&(data))>>26)
#define  OSDOVL_Mixer_layer_sel_get_c1_plane_alpha_en(data)                      ((0x02000000&(data))>>25)
#define  OSDOVL_Mixer_layer_sel_get_c0_plane_alpha_en(data)                      ((0x01000000&(data))>>24)
#define  OSDOVL_Mixer_layer_sel_get_c5_sel(data)                                 ((0x00700000&(data))>>20)
#define  OSDOVL_Mixer_layer_sel_get_c4_sel(data)                                 ((0x00070000&(data))>>16)
#define  OSDOVL_Mixer_layer_sel_get_c3_sel(data)                                 ((0x00007000&(data))>>12)
#define  OSDOVL_Mixer_layer_sel_get_c2_sel(data)                                 ((0x00000700&(data))>>8)
#define  OSDOVL_Mixer_layer_sel_get_c1_sel(data)                                 ((0x00000070&(data))>>4)
#define  OSDOVL_Mixer_layer_sel_get_c0_sel(data)                                 (0x00000007&(data))

#define  OSDOVL_Mixer_c0_plane_alpha1                                            0x1802B008
#define  OSDOVL_Mixer_c0_plane_alpha1_reg_addr                                   "0xB802B008"
#define  OSDOVL_Mixer_c0_plane_alpha1_reg                                        0xB802B008
#define  OSDOVL_Mixer_c0_plane_alpha1_inst_addr                                  "0x0002"
#define  set_OSDOVL_Mixer_c0_plane_alpha1_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c0_plane_alpha1_reg)=data)
#define  get_OSDOVL_Mixer_c0_plane_alpha1_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c0_plane_alpha1_reg))
#define  OSDOVL_Mixer_c0_plane_alpha1_plane_alpha_a_shift                        (16)
#define  OSDOVL_Mixer_c0_plane_alpha1_plane_alpha_r_shift                        (0)
#define  OSDOVL_Mixer_c0_plane_alpha1_plane_alpha_a_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c0_plane_alpha1_plane_alpha_r_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c0_plane_alpha1_plane_alpha_a(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c0_plane_alpha1_plane_alpha_r(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c0_plane_alpha1_get_plane_alpha_a(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c0_plane_alpha1_get_plane_alpha_r(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c0_plane_alpha2                                            0x1802B00C
#define  OSDOVL_Mixer_c0_plane_alpha2_reg_addr                                   "0xB802B00C"
#define  OSDOVL_Mixer_c0_plane_alpha2_reg                                        0xB802B00C
#define  OSDOVL_Mixer_c0_plane_alpha2_inst_addr                                  "0x0003"
#define  set_OSDOVL_Mixer_c0_plane_alpha2_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c0_plane_alpha2_reg)=data)
#define  get_OSDOVL_Mixer_c0_plane_alpha2_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c0_plane_alpha2_reg))
#define  OSDOVL_Mixer_c0_plane_alpha2_plane_alpha_g_shift                        (16)
#define  OSDOVL_Mixer_c0_plane_alpha2_plane_alpha_b_shift                        (0)
#define  OSDOVL_Mixer_c0_plane_alpha2_plane_alpha_g_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c0_plane_alpha2_plane_alpha_b_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c0_plane_alpha2_plane_alpha_g(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c0_plane_alpha2_plane_alpha_b(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c0_plane_alpha2_get_plane_alpha_g(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c0_plane_alpha2_get_plane_alpha_b(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c0_plane_offset                                            0x1802B010
#define  OSDOVL_Mixer_c0_plane_offset_reg_addr                                   "0xB802B010"
#define  OSDOVL_Mixer_c0_plane_offset_reg                                        0xB802B010
#define  OSDOVL_Mixer_c0_plane_offset_inst_addr                                  "0x0004"
#define  set_OSDOVL_Mixer_c0_plane_offset_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c0_plane_offset_reg)=data)
#define  get_OSDOVL_Mixer_c0_plane_offset_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c0_plane_offset_reg))
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_a_shift                       (24)
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_r_shift                       (16)
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_g_shift                       (8)
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_b_shift                       (0)
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_a_mask                        (0xFF000000)
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_r_mask                        (0x00FF0000)
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_g_mask                        (0x0000FF00)
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_b_mask                        (0x000000FF)
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_a(data)                       (0xFF000000&((data)<<24))
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_r(data)                       (0x00FF0000&((data)<<16))
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_g(data)                       (0x0000FF00&((data)<<8))
#define  OSDOVL_Mixer_c0_plane_offset_plane_offset_b(data)                       (0x000000FF&(data))
#define  OSDOVL_Mixer_c0_plane_offset_get_plane_offset_a(data)                   ((0xFF000000&(data))>>24)
#define  OSDOVL_Mixer_c0_plane_offset_get_plane_offset_r(data)                   ((0x00FF0000&(data))>>16)
#define  OSDOVL_Mixer_c0_plane_offset_get_plane_offset_g(data)                   ((0x0000FF00&(data))>>8)
#define  OSDOVL_Mixer_c0_plane_offset_get_plane_offset_b(data)                   (0x000000FF&(data))

#define  OSDOVL_Mixer_c1_plane_alpha1                                            0x1802B014
#define  OSDOVL_Mixer_c1_plane_alpha1_reg_addr                                   "0xB802B014"
#define  OSDOVL_Mixer_c1_plane_alpha1_reg                                        0xB802B014
#define  OSDOVL_Mixer_c1_plane_alpha1_inst_addr                                  "0x0005"
#define  set_OSDOVL_Mixer_c1_plane_alpha1_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c1_plane_alpha1_reg)=data)
#define  get_OSDOVL_Mixer_c1_plane_alpha1_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c1_plane_alpha1_reg))
#define  OSDOVL_Mixer_c1_plane_alpha1_plane_alpha_a_shift                        (16)
#define  OSDOVL_Mixer_c1_plane_alpha1_plane_alpha_r_shift                        (0)
#define  OSDOVL_Mixer_c1_plane_alpha1_plane_alpha_a_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c1_plane_alpha1_plane_alpha_r_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c1_plane_alpha1_plane_alpha_a(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c1_plane_alpha1_plane_alpha_r(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c1_plane_alpha1_get_plane_alpha_a(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c1_plane_alpha1_get_plane_alpha_r(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c1_plane_alpha2                                            0x1802B018
#define  OSDOVL_Mixer_c1_plane_alpha2_reg_addr                                   "0xB802B018"
#define  OSDOVL_Mixer_c1_plane_alpha2_reg                                        0xB802B018
#define  OSDOVL_Mixer_c1_plane_alpha2_inst_addr                                  "0x0006"
#define  set_OSDOVL_Mixer_c1_plane_alpha2_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c1_plane_alpha2_reg)=data)
#define  get_OSDOVL_Mixer_c1_plane_alpha2_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c1_plane_alpha2_reg))
#define  OSDOVL_Mixer_c1_plane_alpha2_plane_alpha_g_shift                        (16)
#define  OSDOVL_Mixer_c1_plane_alpha2_plane_alpha_b_shift                        (0)
#define  OSDOVL_Mixer_c1_plane_alpha2_plane_alpha_g_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c1_plane_alpha2_plane_alpha_b_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c1_plane_alpha2_plane_alpha_g(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c1_plane_alpha2_plane_alpha_b(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c1_plane_alpha2_get_plane_alpha_g(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c1_plane_alpha2_get_plane_alpha_b(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c1_plane_offset                                            0x1802B01C
#define  OSDOVL_Mixer_c1_plane_offset_reg_addr                                   "0xB802B01C"
#define  OSDOVL_Mixer_c1_plane_offset_reg                                        0xB802B01C
#define  OSDOVL_Mixer_c1_plane_offset_inst_addr                                  "0x0007"
#define  set_OSDOVL_Mixer_c1_plane_offset_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c1_plane_offset_reg)=data)
#define  get_OSDOVL_Mixer_c1_plane_offset_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c1_plane_offset_reg))
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_a_shift                       (24)
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_r_shift                       (16)
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_g_shift                       (8)
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_b_shift                       (0)
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_a_mask                        (0xFF000000)
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_r_mask                        (0x00FF0000)
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_g_mask                        (0x0000FF00)
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_b_mask                        (0x000000FF)
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_a(data)                       (0xFF000000&((data)<<24))
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_r(data)                       (0x00FF0000&((data)<<16))
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_g(data)                       (0x0000FF00&((data)<<8))
#define  OSDOVL_Mixer_c1_plane_offset_plane_offset_b(data)                       (0x000000FF&(data))
#define  OSDOVL_Mixer_c1_plane_offset_get_plane_offset_a(data)                   ((0xFF000000&(data))>>24)
#define  OSDOVL_Mixer_c1_plane_offset_get_plane_offset_r(data)                   ((0x00FF0000&(data))>>16)
#define  OSDOVL_Mixer_c1_plane_offset_get_plane_offset_g(data)                   ((0x0000FF00&(data))>>8)
#define  OSDOVL_Mixer_c1_plane_offset_get_plane_offset_b(data)                   (0x000000FF&(data))

#define  OSDOVL_Mixer_c2_plane_alpha1                                            0x1802B020
#define  OSDOVL_Mixer_c2_plane_alpha1_reg_addr                                   "0xB802B020"
#define  OSDOVL_Mixer_c2_plane_alpha1_reg                                        0xB802B020
#define  OSDOVL_Mixer_c2_plane_alpha1_inst_addr                                  "0x0008"
#define  set_OSDOVL_Mixer_c2_plane_alpha1_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c2_plane_alpha1_reg)=data)
#define  get_OSDOVL_Mixer_c2_plane_alpha1_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c2_plane_alpha1_reg))
#define  OSDOVL_Mixer_c2_plane_alpha1_plane_alpha_a_shift                        (16)
#define  OSDOVL_Mixer_c2_plane_alpha1_plane_alpha_r_shift                        (0)
#define  OSDOVL_Mixer_c2_plane_alpha1_plane_alpha_a_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c2_plane_alpha1_plane_alpha_r_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c2_plane_alpha1_plane_alpha_a(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c2_plane_alpha1_plane_alpha_r(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c2_plane_alpha1_get_plane_alpha_a(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c2_plane_alpha1_get_plane_alpha_r(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c2_plane_alpha2                                            0x1802B024
#define  OSDOVL_Mixer_c2_plane_alpha2_reg_addr                                   "0xB802B024"
#define  OSDOVL_Mixer_c2_plane_alpha2_reg                                        0xB802B024
#define  OSDOVL_Mixer_c2_plane_alpha2_inst_addr                                  "0x0009"
#define  set_OSDOVL_Mixer_c2_plane_alpha2_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c2_plane_alpha2_reg)=data)
#define  get_OSDOVL_Mixer_c2_plane_alpha2_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c2_plane_alpha2_reg))
#define  OSDOVL_Mixer_c2_plane_alpha2_plane_alpha_g_shift                        (16)
#define  OSDOVL_Mixer_c2_plane_alpha2_plane_alpha_b_shift                        (0)
#define  OSDOVL_Mixer_c2_plane_alpha2_plane_alpha_g_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c2_plane_alpha2_plane_alpha_b_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c2_plane_alpha2_plane_alpha_g(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c2_plane_alpha2_plane_alpha_b(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c2_plane_alpha2_get_plane_alpha_g(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c2_plane_alpha2_get_plane_alpha_b(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c2_plane_offset                                            0x1802B028
#define  OSDOVL_Mixer_c2_plane_offset_reg_addr                                   "0xB802B028"
#define  OSDOVL_Mixer_c2_plane_offset_reg                                        0xB802B028
#define  OSDOVL_Mixer_c2_plane_offset_inst_addr                                  "0x000A"
#define  set_OSDOVL_Mixer_c2_plane_offset_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c2_plane_offset_reg)=data)
#define  get_OSDOVL_Mixer_c2_plane_offset_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c2_plane_offset_reg))
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_a_shift                       (24)
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_r_shift                       (16)
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_g_shift                       (8)
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_b_shift                       (0)
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_a_mask                        (0xFF000000)
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_r_mask                        (0x00FF0000)
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_g_mask                        (0x0000FF00)
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_b_mask                        (0x000000FF)
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_a(data)                       (0xFF000000&((data)<<24))
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_r(data)                       (0x00FF0000&((data)<<16))
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_g(data)                       (0x0000FF00&((data)<<8))
#define  OSDOVL_Mixer_c2_plane_offset_plane_offset_b(data)                       (0x000000FF&(data))
#define  OSDOVL_Mixer_c2_plane_offset_get_plane_offset_a(data)                   ((0xFF000000&(data))>>24)
#define  OSDOVL_Mixer_c2_plane_offset_get_plane_offset_r(data)                   ((0x00FF0000&(data))>>16)
#define  OSDOVL_Mixer_c2_plane_offset_get_plane_offset_g(data)                   ((0x0000FF00&(data))>>8)
#define  OSDOVL_Mixer_c2_plane_offset_get_plane_offset_b(data)                   (0x000000FF&(data))

#define  OSDOVL_Mixer_c3_plane_alpha1                                            0x1802B02C
#define  OSDOVL_Mixer_c3_plane_alpha1_reg_addr                                   "0xB802B02C"
#define  OSDOVL_Mixer_c3_plane_alpha1_reg                                        0xB802B02C
#define  OSDOVL_Mixer_c3_plane_alpha1_inst_addr                                  "0x000B"
#define  set_OSDOVL_Mixer_c3_plane_alpha1_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c3_plane_alpha1_reg)=data)
#define  get_OSDOVL_Mixer_c3_plane_alpha1_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c3_plane_alpha1_reg))
#define  OSDOVL_Mixer_c3_plane_alpha1_plane_alpha_a_shift                        (16)
#define  OSDOVL_Mixer_c3_plane_alpha1_plane_alpha_r_shift                        (0)
#define  OSDOVL_Mixer_c3_plane_alpha1_plane_alpha_a_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c3_plane_alpha1_plane_alpha_r_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c3_plane_alpha1_plane_alpha_a(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c3_plane_alpha1_plane_alpha_r(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c3_plane_alpha1_get_plane_alpha_a(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c3_plane_alpha1_get_plane_alpha_r(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c3_plane_alpha2                                            0x1802B030
#define  OSDOVL_Mixer_c3_plane_alpha2_reg_addr                                   "0xB802B030"
#define  OSDOVL_Mixer_c3_plane_alpha2_reg                                        0xB802B030
#define  OSDOVL_Mixer_c3_plane_alpha2_inst_addr                                  "0x000C"
#define  set_OSDOVL_Mixer_c3_plane_alpha2_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c3_plane_alpha2_reg)=data)
#define  get_OSDOVL_Mixer_c3_plane_alpha2_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c3_plane_alpha2_reg))
#define  OSDOVL_Mixer_c3_plane_alpha2_plane_alpha_g_shift                        (16)
#define  OSDOVL_Mixer_c3_plane_alpha2_plane_alpha_b_shift                        (0)
#define  OSDOVL_Mixer_c3_plane_alpha2_plane_alpha_g_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c3_plane_alpha2_plane_alpha_b_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c3_plane_alpha2_plane_alpha_g(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c3_plane_alpha2_plane_alpha_b(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c3_plane_alpha2_get_plane_alpha_g(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c3_plane_alpha2_get_plane_alpha_b(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c3_plane_offset                                            0x1802B034
#define  OSDOVL_Mixer_c3_plane_offset_reg_addr                                   "0xB802B034"
#define  OSDOVL_Mixer_c3_plane_offset_reg                                        0xB802B034
#define  OSDOVL_Mixer_c3_plane_offset_inst_addr                                  "0x000D"
#define  set_OSDOVL_Mixer_c3_plane_offset_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c3_plane_offset_reg)=data)
#define  get_OSDOVL_Mixer_c3_plane_offset_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c3_plane_offset_reg))
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_a_shift                       (24)
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_r_shift                       (16)
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_g_shift                       (8)
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_b_shift                       (0)
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_a_mask                        (0xFF000000)
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_r_mask                        (0x00FF0000)
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_g_mask                        (0x0000FF00)
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_b_mask                        (0x000000FF)
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_a(data)                       (0xFF000000&((data)<<24))
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_r(data)                       (0x00FF0000&((data)<<16))
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_g(data)                       (0x0000FF00&((data)<<8))
#define  OSDOVL_Mixer_c3_plane_offset_plane_offset_b(data)                       (0x000000FF&(data))
#define  OSDOVL_Mixer_c3_plane_offset_get_plane_offset_a(data)                   ((0xFF000000&(data))>>24)
#define  OSDOVL_Mixer_c3_plane_offset_get_plane_offset_r(data)                   ((0x00FF0000&(data))>>16)
#define  OSDOVL_Mixer_c3_plane_offset_get_plane_offset_g(data)                   ((0x0000FF00&(data))>>8)
#define  OSDOVL_Mixer_c3_plane_offset_get_plane_offset_b(data)                   (0x000000FF&(data))

#define  OSDOVL_Mixer_c4_plane_alpha1                                            0x1802B038
#define  OSDOVL_Mixer_c4_plane_alpha1_reg_addr                                   "0xB802B038"
#define  OSDOVL_Mixer_c4_plane_alpha1_reg                                        0xB802B038
#define  OSDOVL_Mixer_c4_plane_alpha1_inst_addr                                  "0x000E"
#define  set_OSDOVL_Mixer_c4_plane_alpha1_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c4_plane_alpha1_reg)=data)
#define  get_OSDOVL_Mixer_c4_plane_alpha1_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c4_plane_alpha1_reg))
#define  OSDOVL_Mixer_c4_plane_alpha1_plane_alpha_a_shift                        (16)
#define  OSDOVL_Mixer_c4_plane_alpha1_plane_alpha_r_shift                        (0)
#define  OSDOVL_Mixer_c4_plane_alpha1_plane_alpha_a_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c4_plane_alpha1_plane_alpha_r_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c4_plane_alpha1_plane_alpha_a(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c4_plane_alpha1_plane_alpha_r(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c4_plane_alpha1_get_plane_alpha_a(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c4_plane_alpha1_get_plane_alpha_r(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c4_plane_alpha2                                            0x1802B03C
#define  OSDOVL_Mixer_c4_plane_alpha2_reg_addr                                   "0xB802B03C"
#define  OSDOVL_Mixer_c4_plane_alpha2_reg                                        0xB802B03C
#define  OSDOVL_Mixer_c4_plane_alpha2_inst_addr                                  "0x000F"
#define  set_OSDOVL_Mixer_c4_plane_alpha2_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c4_plane_alpha2_reg)=data)
#define  get_OSDOVL_Mixer_c4_plane_alpha2_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c4_plane_alpha2_reg))
#define  OSDOVL_Mixer_c4_plane_alpha2_plane_alpha_g_shift                        (16)
#define  OSDOVL_Mixer_c4_plane_alpha2_plane_alpha_b_shift                        (0)
#define  OSDOVL_Mixer_c4_plane_alpha2_plane_alpha_g_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c4_plane_alpha2_plane_alpha_b_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c4_plane_alpha2_plane_alpha_g(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c4_plane_alpha2_plane_alpha_b(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c4_plane_alpha2_get_plane_alpha_g(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c4_plane_alpha2_get_plane_alpha_b(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c4_plane_offset                                            0x1802B040
#define  OSDOVL_Mixer_c4_plane_offset_reg_addr                                   "0xB802B040"
#define  OSDOVL_Mixer_c4_plane_offset_reg                                        0xB802B040
#define  OSDOVL_Mixer_c4_plane_offset_inst_addr                                  "0x0010"
#define  set_OSDOVL_Mixer_c4_plane_offset_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c4_plane_offset_reg)=data)
#define  get_OSDOVL_Mixer_c4_plane_offset_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c4_plane_offset_reg))
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_a_shift                       (24)
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_r_shift                       (16)
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_g_shift                       (8)
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_b_shift                       (0)
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_a_mask                        (0xFF000000)
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_r_mask                        (0x00FF0000)
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_g_mask                        (0x0000FF00)
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_b_mask                        (0x000000FF)
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_a(data)                       (0xFF000000&((data)<<24))
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_r(data)                       (0x00FF0000&((data)<<16))
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_g(data)                       (0x0000FF00&((data)<<8))
#define  OSDOVL_Mixer_c4_plane_offset_plane_offset_b(data)                       (0x000000FF&(data))
#define  OSDOVL_Mixer_c4_plane_offset_get_plane_offset_a(data)                   ((0xFF000000&(data))>>24)
#define  OSDOVL_Mixer_c4_plane_offset_get_plane_offset_r(data)                   ((0x00FF0000&(data))>>16)
#define  OSDOVL_Mixer_c4_plane_offset_get_plane_offset_g(data)                   ((0x0000FF00&(data))>>8)
#define  OSDOVL_Mixer_c4_plane_offset_get_plane_offset_b(data)                   (0x000000FF&(data))

#define  OSDOVL_Mixer_c5_plane_alpha1                                            0x1802B044
#define  OSDOVL_Mixer_c5_plane_alpha1_reg_addr                                   "0xB802B044"
#define  OSDOVL_Mixer_c5_plane_alpha1_reg                                        0xB802B044
#define  OSDOVL_Mixer_c5_plane_alpha1_inst_addr                                  "0x0011"
#define  set_OSDOVL_Mixer_c5_plane_alpha1_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c5_plane_alpha1_reg)=data)
#define  get_OSDOVL_Mixer_c5_plane_alpha1_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c5_plane_alpha1_reg))
#define  OSDOVL_Mixer_c5_plane_alpha1_plane_alpha_a_shift                        (16)
#define  OSDOVL_Mixer_c5_plane_alpha1_plane_alpha_r_shift                        (0)
#define  OSDOVL_Mixer_c5_plane_alpha1_plane_alpha_a_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c5_plane_alpha1_plane_alpha_r_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c5_plane_alpha1_plane_alpha_a(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c5_plane_alpha1_plane_alpha_r(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c5_plane_alpha1_get_plane_alpha_a(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c5_plane_alpha1_get_plane_alpha_r(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c5_plane_alpha2                                            0x1802B048
#define  OSDOVL_Mixer_c5_plane_alpha2_reg_addr                                   "0xB802B048"
#define  OSDOVL_Mixer_c5_plane_alpha2_reg                                        0xB802B048
#define  OSDOVL_Mixer_c5_plane_alpha2_inst_addr                                  "0x0012"
#define  set_OSDOVL_Mixer_c5_plane_alpha2_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c5_plane_alpha2_reg)=data)
#define  get_OSDOVL_Mixer_c5_plane_alpha2_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c5_plane_alpha2_reg))
#define  OSDOVL_Mixer_c5_plane_alpha2_plane_alpha_g_shift                        (16)
#define  OSDOVL_Mixer_c5_plane_alpha2_plane_alpha_b_shift                        (0)
#define  OSDOVL_Mixer_c5_plane_alpha2_plane_alpha_g_mask                         (0x01FF0000)
#define  OSDOVL_Mixer_c5_plane_alpha2_plane_alpha_b_mask                         (0x000001FF)
#define  OSDOVL_Mixer_c5_plane_alpha2_plane_alpha_g(data)                        (0x01FF0000&((data)<<16))
#define  OSDOVL_Mixer_c5_plane_alpha2_plane_alpha_b(data)                        (0x000001FF&(data))
#define  OSDOVL_Mixer_c5_plane_alpha2_get_plane_alpha_g(data)                    ((0x01FF0000&(data))>>16)
#define  OSDOVL_Mixer_c5_plane_alpha2_get_plane_alpha_b(data)                    (0x000001FF&(data))

#define  OSDOVL_Mixer_c5_plane_offset                                            0x1802B04C
#define  OSDOVL_Mixer_c5_plane_offset_reg_addr                                   "0xB802B04C"
#define  OSDOVL_Mixer_c5_plane_offset_reg                                        0xB802B04C
#define  OSDOVL_Mixer_c5_plane_offset_inst_addr                                  "0x0013"
#define  set_OSDOVL_Mixer_c5_plane_offset_reg(data)                              (*((volatile unsigned int*)OSDOVL_Mixer_c5_plane_offset_reg)=data)
#define  get_OSDOVL_Mixer_c5_plane_offset_reg                                    (*((volatile unsigned int*)OSDOVL_Mixer_c5_plane_offset_reg))
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_a_shift                       (24)
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_r_shift                       (16)
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_g_shift                       (8)
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_b_shift                       (0)
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_a_mask                        (0xFF000000)
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_r_mask                        (0x00FF0000)
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_g_mask                        (0x0000FF00)
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_b_mask                        (0x000000FF)
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_a(data)                       (0xFF000000&((data)<<24))
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_r(data)                       (0x00FF0000&((data)<<16))
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_g(data)                       (0x0000FF00&((data)<<8))
#define  OSDOVL_Mixer_c5_plane_offset_plane_offset_b(data)                       (0x000000FF&(data))
#define  OSDOVL_Mixer_c5_plane_offset_get_plane_offset_a(data)                   ((0xFF000000&(data))>>24)
#define  OSDOVL_Mixer_c5_plane_offset_get_plane_offset_r(data)                   ((0x00FF0000&(data))>>16)
#define  OSDOVL_Mixer_c5_plane_offset_get_plane_offset_g(data)                   ((0x0000FF00&(data))>>8)
#define  OSDOVL_Mixer_c5_plane_offset_get_plane_offset_b(data)                   (0x000000FF&(data))

#define  OSDOVL_Mixer_b1                                                         0x1802B060
#define  OSDOVL_Mixer_b1_reg_addr                                                "0xB802B060"
#define  OSDOVL_Mixer_b1_reg                                                     0xB802B060
#define  OSDOVL_Mixer_b1_inst_addr                                               "0x0014"
#define  set_OSDOVL_Mixer_b1_reg(data)                                           (*((volatile unsigned int*)OSDOVL_Mixer_b1_reg)=data)
#define  get_OSDOVL_Mixer_b1_reg                                                 (*((volatile unsigned int*)OSDOVL_Mixer_b1_reg))
#define  OSDOVL_Mixer_b1_k1_shift                                                (24)
#define  OSDOVL_Mixer_b1_k2_shift                                                (16)
#define  OSDOVL_Mixer_b1_k3_shift                                                (8)
#define  OSDOVL_Mixer_b1_k4_shift                                                (0)
#define  OSDOVL_Mixer_b1_k1_mask                                                 (0x3F000000)
#define  OSDOVL_Mixer_b1_k2_mask                                                 (0x003F0000)
#define  OSDOVL_Mixer_b1_k3_mask                                                 (0x00003F00)
#define  OSDOVL_Mixer_b1_k4_mask                                                 (0x0000003F)
#define  OSDOVL_Mixer_b1_k1(data)                                                (0x3F000000&((data)<<24))
#define  OSDOVL_Mixer_b1_k2(data)                                                (0x003F0000&((data)<<16))
#define  OSDOVL_Mixer_b1_k3(data)                                                (0x00003F00&((data)<<8))
#define  OSDOVL_Mixer_b1_k4(data)                                                (0x0000003F&(data))
#define  OSDOVL_Mixer_b1_get_k1(data)                                            ((0x3F000000&(data))>>24)
#define  OSDOVL_Mixer_b1_get_k2(data)                                            ((0x003F0000&(data))>>16)
#define  OSDOVL_Mixer_b1_get_k3(data)                                            ((0x00003F00&(data))>>8)
#define  OSDOVL_Mixer_b1_get_k4(data)                                            (0x0000003F&(data))

#define  OSDOVL_Mixer_b2                                                         0x1802B064
#define  OSDOVL_Mixer_b2_reg_addr                                                "0xB802B064"
#define  OSDOVL_Mixer_b2_reg                                                     0xB802B064
#define  OSDOVL_Mixer_b2_inst_addr                                               "0x0015"
#define  set_OSDOVL_Mixer_b2_reg(data)                                           (*((volatile unsigned int*)OSDOVL_Mixer_b2_reg)=data)
#define  get_OSDOVL_Mixer_b2_reg                                                 (*((volatile unsigned int*)OSDOVL_Mixer_b2_reg))
#define  OSDOVL_Mixer_b2_k1_shift                                                (24)
#define  OSDOVL_Mixer_b2_k2_shift                                                (16)
#define  OSDOVL_Mixer_b2_k3_shift                                                (8)
#define  OSDOVL_Mixer_b2_k4_shift                                                (0)
#define  OSDOVL_Mixer_b2_k1_mask                                                 (0x3F000000)
#define  OSDOVL_Mixer_b2_k2_mask                                                 (0x003F0000)
#define  OSDOVL_Mixer_b2_k3_mask                                                 (0x00003F00)
#define  OSDOVL_Mixer_b2_k4_mask                                                 (0x0000003F)
#define  OSDOVL_Mixer_b2_k1(data)                                                (0x3F000000&((data)<<24))
#define  OSDOVL_Mixer_b2_k2(data)                                                (0x003F0000&((data)<<16))
#define  OSDOVL_Mixer_b2_k3(data)                                                (0x00003F00&((data)<<8))
#define  OSDOVL_Mixer_b2_k4(data)                                                (0x0000003F&(data))
#define  OSDOVL_Mixer_b2_get_k1(data)                                            ((0x3F000000&(data))>>24)
#define  OSDOVL_Mixer_b2_get_k2(data)                                            ((0x003F0000&(data))>>16)
#define  OSDOVL_Mixer_b2_get_k3(data)                                            ((0x00003F00&(data))>>8)
#define  OSDOVL_Mixer_b2_get_k4(data)                                            (0x0000003F&(data))

#define  OSDOVL_Mixer_b3                                                         0x1802B068
#define  OSDOVL_Mixer_b3_reg_addr                                                "0xB802B068"
#define  OSDOVL_Mixer_b3_reg                                                     0xB802B068
#define  OSDOVL_Mixer_b3_inst_addr                                               "0x0016"
#define  set_OSDOVL_Mixer_b3_reg(data)                                           (*((volatile unsigned int*)OSDOVL_Mixer_b3_reg)=data)
#define  get_OSDOVL_Mixer_b3_reg                                                 (*((volatile unsigned int*)OSDOVL_Mixer_b3_reg))
#define  OSDOVL_Mixer_b3_k1_shift                                                (24)
#define  OSDOVL_Mixer_b3_k2_shift                                                (16)
#define  OSDOVL_Mixer_b3_k3_shift                                                (8)
#define  OSDOVL_Mixer_b3_k4_shift                                                (0)
#define  OSDOVL_Mixer_b3_k1_mask                                                 (0x3F000000)
#define  OSDOVL_Mixer_b3_k2_mask                                                 (0x003F0000)
#define  OSDOVL_Mixer_b3_k3_mask                                                 (0x00003F00)
#define  OSDOVL_Mixer_b3_k4_mask                                                 (0x0000003F)
#define  OSDOVL_Mixer_b3_k1(data)                                                (0x3F000000&((data)<<24))
#define  OSDOVL_Mixer_b3_k2(data)                                                (0x003F0000&((data)<<16))
#define  OSDOVL_Mixer_b3_k3(data)                                                (0x00003F00&((data)<<8))
#define  OSDOVL_Mixer_b3_k4(data)                                                (0x0000003F&(data))
#define  OSDOVL_Mixer_b3_get_k1(data)                                            ((0x3F000000&(data))>>24)
#define  OSDOVL_Mixer_b3_get_k2(data)                                            ((0x003F0000&(data))>>16)
#define  OSDOVL_Mixer_b3_get_k3(data)                                            ((0x00003F00&(data))>>8)
#define  OSDOVL_Mixer_b3_get_k4(data)                                            (0x0000003F&(data))

#define  OSDOVL_Mixer_b4                                                         0x1802B06C
#define  OSDOVL_Mixer_b4_reg_addr                                                "0xB802B06C"
#define  OSDOVL_Mixer_b4_reg                                                     0xB802B06C
#define  OSDOVL_Mixer_b4_inst_addr                                               "0x0017"
#define  set_OSDOVL_Mixer_b4_reg(data)                                           (*((volatile unsigned int*)OSDOVL_Mixer_b4_reg)=data)
#define  get_OSDOVL_Mixer_b4_reg                                                 (*((volatile unsigned int*)OSDOVL_Mixer_b4_reg))
#define  OSDOVL_Mixer_b4_k1_shift                                                (24)
#define  OSDOVL_Mixer_b4_k2_shift                                                (16)
#define  OSDOVL_Mixer_b4_k3_shift                                                (8)
#define  OSDOVL_Mixer_b4_k4_shift                                                (0)
#define  OSDOVL_Mixer_b4_k1_mask                                                 (0x3F000000)
#define  OSDOVL_Mixer_b4_k2_mask                                                 (0x003F0000)
#define  OSDOVL_Mixer_b4_k3_mask                                                 (0x00003F00)
#define  OSDOVL_Mixer_b4_k4_mask                                                 (0x0000003F)
#define  OSDOVL_Mixer_b4_k1(data)                                                (0x3F000000&((data)<<24))
#define  OSDOVL_Mixer_b4_k2(data)                                                (0x003F0000&((data)<<16))
#define  OSDOVL_Mixer_b4_k3(data)                                                (0x00003F00&((data)<<8))
#define  OSDOVL_Mixer_b4_k4(data)                                                (0x0000003F&(data))
#define  OSDOVL_Mixer_b4_get_k1(data)                                            ((0x3F000000&(data))>>24)
#define  OSDOVL_Mixer_b4_get_k2(data)                                            ((0x003F0000&(data))>>16)
#define  OSDOVL_Mixer_b4_get_k3(data)                                            ((0x00003F00&(data))>>8)
#define  OSDOVL_Mixer_b4_get_k4(data)                                            (0x0000003F&(data))

#define  OSDOVL_Mixer_b5                                                         0x1802B070
#define  OSDOVL_Mixer_b5_reg_addr                                                "0xB802B070"
#define  OSDOVL_Mixer_b5_reg                                                     0xB802B070
#define  OSDOVL_Mixer_b5_inst_addr                                               "0x0018"
#define  set_OSDOVL_Mixer_b5_reg(data)                                           (*((volatile unsigned int*)OSDOVL_Mixer_b5_reg)=data)
#define  get_OSDOVL_Mixer_b5_reg                                                 (*((volatile unsigned int*)OSDOVL_Mixer_b5_reg))
#define  OSDOVL_Mixer_b5_k1_shift                                                (24)
#define  OSDOVL_Mixer_b5_k2_shift                                                (16)
#define  OSDOVL_Mixer_b5_k3_shift                                                (8)
#define  OSDOVL_Mixer_b5_k4_shift                                                (0)
#define  OSDOVL_Mixer_b5_k1_mask                                                 (0x3F000000)
#define  OSDOVL_Mixer_b5_k2_mask                                                 (0x003F0000)
#define  OSDOVL_Mixer_b5_k3_mask                                                 (0x00003F00)
#define  OSDOVL_Mixer_b5_k4_mask                                                 (0x0000003F)
#define  OSDOVL_Mixer_b5_k1(data)                                                (0x3F000000&((data)<<24))
#define  OSDOVL_Mixer_b5_k2(data)                                                (0x003F0000&((data)<<16))
#define  OSDOVL_Mixer_b5_k3(data)                                                (0x00003F00&((data)<<8))
#define  OSDOVL_Mixer_b5_k4(data)                                                (0x0000003F&(data))
#define  OSDOVL_Mixer_b5_get_k1(data)                                            ((0x3F000000&(data))>>24)
#define  OSDOVL_Mixer_b5_get_k2(data)                                            ((0x003F0000&(data))>>16)
#define  OSDOVL_Mixer_b5_get_k3(data)                                            ((0x00003F00&(data))>>8)
#define  OSDOVL_Mixer_b5_get_k4(data)                                            (0x0000003F&(data))

#define  OSDOVL_Mixer_writeback                                                  0x1802B080
#define  OSDOVL_Mixer_writeback_reg_addr                                         "0xB802B080"
#define  OSDOVL_Mixer_writeback_reg                                              0xB802B080
#define  OSDOVL_Mixer_writeback_inst_addr                                        "0x0019"
#define  set_OSDOVL_Mixer_writeback_reg(data)                                    (*((volatile unsigned int*)OSDOVL_Mixer_writeback_reg)=data)
#define  get_OSDOVL_Mixer_writeback_reg                                          (*((volatile unsigned int*)OSDOVL_Mixer_writeback_reg))
#define  OSDOVL_Mixer_writeback_writeback_en_shift                               (4)
#define  OSDOVL_Mixer_writeback_writeback_sel_shift                              (0)
#define  OSDOVL_Mixer_writeback_writeback_en_mask                                (0x00000010)
#define  OSDOVL_Mixer_writeback_writeback_sel_mask                               (0x0000000F)
#define  OSDOVL_Mixer_writeback_writeback_en(data)                               (0x00000010&((data)<<4))
#define  OSDOVL_Mixer_writeback_writeback_sel(data)                              (0x0000000F&(data))
#define  OSDOVL_Mixer_writeback_get_writeback_en(data)                           ((0x00000010&(data))>>4)
#define  OSDOVL_Mixer_writeback_get_writeback_sel(data)                          (0x0000000F&(data))

#define  OSDOVL_Mixer_writeback_size                                             0x1802B084
#define  OSDOVL_Mixer_writeback_size_reg_addr                                    "0xB802B084"
#define  OSDOVL_Mixer_writeback_size_reg                                         0xB802B084
#define  OSDOVL_Mixer_writeback_size_inst_addr                                   "0x001A"
#define  set_OSDOVL_Mixer_writeback_size_reg(data)                               (*((volatile unsigned int*)OSDOVL_Mixer_writeback_size_reg)=data)
#define  get_OSDOVL_Mixer_writeback_size_reg                                     (*((volatile unsigned int*)OSDOVL_Mixer_writeback_size_reg))
#define  OSDOVL_Mixer_writeback_size_width_shift                                 (16)
#define  OSDOVL_Mixer_writeback_size_height_shift                                (0)
#define  OSDOVL_Mixer_writeback_size_width_mask                                  (0x1FFF0000)
#define  OSDOVL_Mixer_writeback_size_height_mask                                 (0x00001FFF)
#define  OSDOVL_Mixer_writeback_size_width(data)                                 (0x1FFF0000&((data)<<16))
#define  OSDOVL_Mixer_writeback_size_height(data)                                (0x00001FFF&(data))
#define  OSDOVL_Mixer_writeback_size_get_width(data)                             ((0x1FFF0000&(data))>>16)
#define  OSDOVL_Mixer_writeback_size_get_height(data)                            (0x00001FFF&(data))

#define  OSDOVL_Mixer_writeback_position                                         0x1802B088
#define  OSDOVL_Mixer_writeback_position_reg_addr                                "0xB802B088"
#define  OSDOVL_Mixer_writeback_position_reg                                     0xB802B088
#define  OSDOVL_Mixer_writeback_position_inst_addr                               "0x001B"
#define  set_OSDOVL_Mixer_writeback_position_reg(data)                           (*((volatile unsigned int*)OSDOVL_Mixer_writeback_position_reg)=data)
#define  get_OSDOVL_Mixer_writeback_position_reg                                 (*((volatile unsigned int*)OSDOVL_Mixer_writeback_position_reg))
#define  OSDOVL_Mixer_writeback_position_x_shift                                 (16)
#define  OSDOVL_Mixer_writeback_position_y_shift                                 (0)
#define  OSDOVL_Mixer_writeback_position_x_mask                                  (0x1FFF0000)
#define  OSDOVL_Mixer_writeback_position_y_mask                                  (0x00001FFF)
#define  OSDOVL_Mixer_writeback_position_x(data)                                 (0x1FFF0000&((data)<<16))
#define  OSDOVL_Mixer_writeback_position_y(data)                                 (0x00001FFF&(data))
#define  OSDOVL_Mixer_writeback_position_get_x(data)                             ((0x1FFF0000&(data))>>16)
#define  OSDOVL_Mixer_writeback_position_get_y(data)                             (0x00001FFF&(data))

#define  OSDOVL_Mixer_CRC_Sel                                                    0x1802B090
#define  OSDOVL_Mixer_CRC_Sel_reg_addr                                           "0xB802B090"
#define  OSDOVL_Mixer_CRC_Sel_reg                                                0xB802B090
#define  OSDOVL_Mixer_CRC_Sel_inst_addr                                          "0x001C"
#define  set_OSDOVL_Mixer_CRC_Sel_reg(data)                                      (*((volatile unsigned int*)OSDOVL_Mixer_CRC_Sel_reg)=data)
#define  get_OSDOVL_Mixer_CRC_Sel_reg                                            (*((volatile unsigned int*)OSDOVL_Mixer_CRC_Sel_reg))
#define  OSDOVL_Mixer_CRC_Sel_mixer_crc_sel_shift                                (0)
#define  OSDOVL_Mixer_CRC_Sel_mixer_crc_sel_mask                                 (0x0000000F)
#define  OSDOVL_Mixer_CRC_Sel_mixer_crc_sel(data)                                (0x0000000F&(data))
#define  OSDOVL_Mixer_CRC_Sel_get_mixer_crc_sel(data)                            (0x0000000F&(data))

#define  OSDOVL_Mixer_CRC_Ctrl                                                   0x1802B094
#define  OSDOVL_Mixer_CRC_Ctrl_reg_addr                                          "0xB802B094"
#define  OSDOVL_Mixer_CRC_Ctrl_reg                                               0xB802B094
#define  OSDOVL_Mixer_CRC_Ctrl_inst_addr                                         "0x001D"
#define  set_OSDOVL_Mixer_CRC_Ctrl_reg(data)                                     (*((volatile unsigned int*)OSDOVL_Mixer_CRC_Ctrl_reg)=data)
#define  get_OSDOVL_Mixer_CRC_Ctrl_reg                                           (*((volatile unsigned int*)OSDOVL_Mixer_CRC_Ctrl_reg))
#define  OSDOVL_Mixer_CRC_Ctrl_mixer_crc_done_shift                              (2)
#define  OSDOVL_Mixer_CRC_Ctrl_mixer_crc_cont_shift                              (1)
#define  OSDOVL_Mixer_CRC_Ctrl_mixer_crc_start_shift                             (0)
#define  OSDOVL_Mixer_CRC_Ctrl_mixer_crc_done_mask                               (0x00000004)
#define  OSDOVL_Mixer_CRC_Ctrl_mixer_crc_cont_mask                               (0x00000002)
#define  OSDOVL_Mixer_CRC_Ctrl_mixer_crc_start_mask                              (0x00000001)
#define  OSDOVL_Mixer_CRC_Ctrl_mixer_crc_done(data)                              (0x00000004&((data)<<2))
#define  OSDOVL_Mixer_CRC_Ctrl_mixer_crc_cont(data)                              (0x00000002&((data)<<1))
#define  OSDOVL_Mixer_CRC_Ctrl_mixer_crc_start(data)                             (0x00000001&(data))
#define  OSDOVL_Mixer_CRC_Ctrl_get_mixer_crc_done(data)                          ((0x00000004&(data))>>2)
#define  OSDOVL_Mixer_CRC_Ctrl_get_mixer_crc_cont(data)                          ((0x00000002&(data))>>1)
#define  OSDOVL_Mixer_CRC_Ctrl_get_mixer_crc_start(data)                         (0x00000001&(data))

#define  OSDOVL_Mixer_CRC_Result                                                 0x1802B098
#define  OSDOVL_Mixer_CRC_Result_reg_addr                                        "0xB802B098"
#define  OSDOVL_Mixer_CRC_Result_reg                                             0xB802B098
#define  OSDOVL_Mixer_CRC_Result_inst_addr                                       "0x001E"
#define  set_OSDOVL_Mixer_CRC_Result_reg(data)                                   (*((volatile unsigned int*)OSDOVL_Mixer_CRC_Result_reg)=data)
#define  get_OSDOVL_Mixer_CRC_Result_reg                                         (*((volatile unsigned int*)OSDOVL_Mixer_CRC_Result_reg))
#define  OSDOVL_Mixer_CRC_Result_mixer_crc_result_shift                          (0)
#define  OSDOVL_Mixer_CRC_Result_mixer_crc_result_mask                           (0xFFFFFFFF)
#define  OSDOVL_Mixer_CRC_Result_mixer_crc_result(data)                          (0xFFFFFFFF&(data))
#define  OSDOVL_Mixer_CRC_Result_get_mixer_crc_result(data)                      (0xFFFFFFFF&(data))

#define  OSDOVL_Mixer_CRC_Result_ODD                                             0x1802B09C
#define  OSDOVL_Mixer_CRC_Result_ODD_reg_addr                                    "0xB802B09C"
#define  OSDOVL_Mixer_CRC_Result_ODD_reg                                         0xB802B09C
#define  OSDOVL_Mixer_CRC_Result_ODD_inst_addr                                   "0x001F"
#define  set_OSDOVL_Mixer_CRC_Result_ODD_reg(data)                               (*((volatile unsigned int*)OSDOVL_Mixer_CRC_Result_ODD_reg)=data)
#define  get_OSDOVL_Mixer_CRC_Result_ODD_reg                                     (*((volatile unsigned int*)OSDOVL_Mixer_CRC_Result_ODD_reg))
#define  OSDOVL_Mixer_CRC_Result_ODD_mixer_crc_result_odd_shift                  (0)
#define  OSDOVL_Mixer_CRC_Result_ODD_mixer_crc_result_odd_mask                   (0xFFFFFFFF)
#define  OSDOVL_Mixer_CRC_Result_ODD_mixer_crc_result_odd(data)                  (0xFFFFFFFF&(data))
#define  OSDOVL_Mixer_CRC_Result_ODD_get_mixer_crc_result_odd(data)              (0xFFFFFFFF&(data))

#define  OSDOVL_OSD_Db_Ctrl                                                      0x1802B0A0
#define  OSDOVL_OSD_Db_Ctrl_reg_addr                                             "0xB802B0A0"
#define  OSDOVL_OSD_Db_Ctrl_reg                                                  0xB802B0A0
#define  OSDOVL_OSD_Db_Ctrl_inst_addr                                            "0x0020"
#define  set_OSDOVL_OSD_Db_Ctrl_reg(data)                                        (*((volatile unsigned int*)OSDOVL_OSD_Db_Ctrl_reg)=data)
#define  get_OSDOVL_OSD_Db_Ctrl_reg                                              (*((volatile unsigned int*)OSDOVL_OSD_Db_Ctrl_reg))
#define  OSDOVL_OSD_Db_Ctrl_db_read_shift                                        (2)
#define  OSDOVL_OSD_Db_Ctrl_db_en_shift                                          (1)
#define  OSDOVL_OSD_Db_Ctrl_db_load_shift                                        (0)
#define  OSDOVL_OSD_Db_Ctrl_db_read_mask                                         (0x00000004)
#define  OSDOVL_OSD_Db_Ctrl_db_en_mask                                           (0x00000002)
#define  OSDOVL_OSD_Db_Ctrl_db_load_mask                                         (0x00000001)
#define  OSDOVL_OSD_Db_Ctrl_db_read(data)                                        (0x00000004&((data)<<2))
#define  OSDOVL_OSD_Db_Ctrl_db_en(data)                                          (0x00000002&((data)<<1))
#define  OSDOVL_OSD_Db_Ctrl_db_load(data)                                        (0x00000001&(data))
#define  OSDOVL_OSD_Db_Ctrl_get_db_read(data)                                    ((0x00000004&(data))>>2)
#define  OSDOVL_OSD_Db_Ctrl_get_db_en(data)                                      ((0x00000002&(data))>>1)
#define  OSDOVL_OSD_Db_Ctrl_get_db_load(data)                                    (0x00000001&(data))

#define  OSDOVL_Mixer_writeback_info                                             0x1802B0B0
#define  OSDOVL_Mixer_writeback_info_reg_addr                                    "0xB802B0B0"
#define  OSDOVL_Mixer_writeback_info_reg                                         0xB802B0B0
#define  OSDOVL_Mixer_writeback_info_inst_addr                                   "0x0021"
#define  set_OSDOVL_Mixer_writeback_info_reg(data)                               (*((volatile unsigned int*)OSDOVL_Mixer_writeback_info_reg)=data)
#define  get_OSDOVL_Mixer_writeback_info_reg                                     (*((volatile unsigned int*)OSDOVL_Mixer_writeback_info_reg))
#define  OSDOVL_Mixer_writeback_info_width_shift                                 (16)
#define  OSDOVL_Mixer_writeback_info_height_shift                                (0)
#define  OSDOVL_Mixer_writeback_info_width_mask                                  (0x1FFF0000)
#define  OSDOVL_Mixer_writeback_info_height_mask                                 (0x00001FFF)
#define  OSDOVL_Mixer_writeback_info_width(data)                                 (0x1FFF0000&((data)<<16))
#define  OSDOVL_Mixer_writeback_info_height(data)                                (0x00001FFF&(data))
#define  OSDOVL_Mixer_writeback_info_get_width(data)                             ((0x1FFF0000&(data))>>16)
#define  OSDOVL_Mixer_writeback_info_get_height(data)                            (0x00001FFF&(data))

#define  OSDOVL_Mixer_setting_error                                              0x1802B0B4
#define  OSDOVL_Mixer_setting_error_reg_addr                                     "0xB802B0B4"
#define  OSDOVL_Mixer_setting_error_reg                                          0xB802B0B4
#define  OSDOVL_Mixer_setting_error_inst_addr                                    "0x0022"
#define  set_OSDOVL_Mixer_setting_error_reg(data)                                (*((volatile unsigned int*)OSDOVL_Mixer_setting_error_reg)=data)
#define  get_OSDOVL_Mixer_setting_error_reg                                      (*((volatile unsigned int*)OSDOVL_Mixer_setting_error_reg))
#define  OSDOVL_Mixer_setting_error_one_layer_setting_conflict_shift             (14)
#define  OSDOVL_Mixer_setting_error_c5_src_conflict_shift                        (13)
#define  OSDOVL_Mixer_setting_error_c4_src_conflict_shift                        (12)
#define  OSDOVL_Mixer_setting_error_c3_src_conflict_shift                        (11)
#define  OSDOVL_Mixer_setting_error_c2_src_conflict_shift                        (10)
#define  OSDOVL_Mixer_setting_error_c1_src_conflict_shift                        (9)
#define  OSDOVL_Mixer_setting_error_c0_src_conflict_shift                        (8)
#define  OSDOVL_Mixer_setting_error_one_layer_setting_offline_shift              (7)
#define  OSDOVL_Mixer_setting_error_osd6_is_offline_shift                        (6)
#define  OSDOVL_Mixer_setting_error_osd5_is_offline_shift                        (5)
#define  OSDOVL_Mixer_setting_error_osd4_is_offline_shift                        (4)
#define  OSDOVL_Mixer_setting_error_osd3_is_offline_shift                        (3)
#define  OSDOVL_Mixer_setting_error_osd2_is_offline_shift                        (2)
#define  OSDOVL_Mixer_setting_error_osd1_is_offline_shift                        (1)
#define  OSDOVL_Mixer_setting_error_one_layer_setting_conflict_mask              (0x00004000)
#define  OSDOVL_Mixer_setting_error_c5_src_conflict_mask                         (0x00002000)
#define  OSDOVL_Mixer_setting_error_c4_src_conflict_mask                         (0x00001000)
#define  OSDOVL_Mixer_setting_error_c3_src_conflict_mask                         (0x00000800)
#define  OSDOVL_Mixer_setting_error_c2_src_conflict_mask                         (0x00000400)
#define  OSDOVL_Mixer_setting_error_c1_src_conflict_mask                         (0x00000200)
#define  OSDOVL_Mixer_setting_error_c0_src_conflict_mask                         (0x00000100)
#define  OSDOVL_Mixer_setting_error_one_layer_setting_offline_mask               (0x00000080)
#define  OSDOVL_Mixer_setting_error_osd6_is_offline_mask                         (0x00000040)
#define  OSDOVL_Mixer_setting_error_osd5_is_offline_mask                         (0x00000020)
#define  OSDOVL_Mixer_setting_error_osd4_is_offline_mask                         (0x00000010)
#define  OSDOVL_Mixer_setting_error_osd3_is_offline_mask                         (0x00000008)
#define  OSDOVL_Mixer_setting_error_osd2_is_offline_mask                         (0x00000004)
#define  OSDOVL_Mixer_setting_error_osd1_is_offline_mask                         (0x00000002)
#define  OSDOVL_Mixer_setting_error_one_layer_setting_conflict(data)             (0x00004000&((data)<<14))
#define  OSDOVL_Mixer_setting_error_c5_src_conflict(data)                        (0x00002000&((data)<<13))
#define  OSDOVL_Mixer_setting_error_c4_src_conflict(data)                        (0x00001000&((data)<<12))
#define  OSDOVL_Mixer_setting_error_c3_src_conflict(data)                        (0x00000800&((data)<<11))
#define  OSDOVL_Mixer_setting_error_c2_src_conflict(data)                        (0x00000400&((data)<<10))
#define  OSDOVL_Mixer_setting_error_c1_src_conflict(data)                        (0x00000200&((data)<<9))
#define  OSDOVL_Mixer_setting_error_c0_src_conflict(data)                        (0x00000100&((data)<<8))
#define  OSDOVL_Mixer_setting_error_one_layer_setting_offline(data)              (0x00000080&((data)<<7))
#define  OSDOVL_Mixer_setting_error_osd6_is_offline(data)                        (0x00000040&((data)<<6))
#define  OSDOVL_Mixer_setting_error_osd5_is_offline(data)                        (0x00000020&((data)<<5))
#define  OSDOVL_Mixer_setting_error_osd4_is_offline(data)                        (0x00000010&((data)<<4))
#define  OSDOVL_Mixer_setting_error_osd3_is_offline(data)                        (0x00000008&((data)<<3))
#define  OSDOVL_Mixer_setting_error_osd2_is_offline(data)                        (0x00000004&((data)<<2))
#define  OSDOVL_Mixer_setting_error_osd1_is_offline(data)                        (0x00000002&((data)<<1))
#define  OSDOVL_Mixer_setting_error_get_one_layer_setting_conflict(data)         ((0x00004000&(data))>>14)
#define  OSDOVL_Mixer_setting_error_get_c5_src_conflict(data)                    ((0x00002000&(data))>>13)
#define  OSDOVL_Mixer_setting_error_get_c4_src_conflict(data)                    ((0x00001000&(data))>>12)
#define  OSDOVL_Mixer_setting_error_get_c3_src_conflict(data)                    ((0x00000800&(data))>>11)
#define  OSDOVL_Mixer_setting_error_get_c2_src_conflict(data)                    ((0x00000400&(data))>>10)
#define  OSDOVL_Mixer_setting_error_get_c1_src_conflict(data)                    ((0x00000200&(data))>>9)
#define  OSDOVL_Mixer_setting_error_get_c0_src_conflict(data)                    ((0x00000100&(data))>>8)
#define  OSDOVL_Mixer_setting_error_get_one_layer_setting_offline(data)          ((0x00000080&(data))>>7)
#define  OSDOVL_Mixer_setting_error_get_osd6_is_offline(data)                    ((0x00000040&(data))>>6)
#define  OSDOVL_Mixer_setting_error_get_osd5_is_offline(data)                    ((0x00000020&(data))>>5)
#define  OSDOVL_Mixer_setting_error_get_osd4_is_offline(data)                    ((0x00000010&(data))>>4)
#define  OSDOVL_Mixer_setting_error_get_osd3_is_offline(data)                    ((0x00000008&(data))>>3)
#define  OSDOVL_Mixer_setting_error_get_osd2_is_offline(data)                    ((0x00000004&(data))>>2)
#define  OSDOVL_Mixer_setting_error_get_osd1_is_offline(data)                    ((0x00000002&(data))>>1)

#define  OSDOVL_Mixer_pixel_mode                                                 0x1802B0B8
#define  OSDOVL_Mixer_pixel_mode_reg_addr                                        "0xB802B0B8"
#define  OSDOVL_Mixer_pixel_mode_reg                                             0xB802B0B8
#define  OSDOVL_Mixer_pixel_mode_inst_addr                                       "0x0023"
#define  set_OSDOVL_Mixer_pixel_mode_reg(data)                                   (*((volatile unsigned int*)OSDOVL_Mixer_pixel_mode_reg)=data)
#define  get_OSDOVL_Mixer_pixel_mode_reg                                         (*((volatile unsigned int*)OSDOVL_Mixer_pixel_mode_reg))
#define  OSDOVL_Mixer_pixel_mode_two_pixel_mode_shift                            (0)
#define  OSDOVL_Mixer_pixel_mode_two_pixel_mode_mask                             (0x00000001)
#define  OSDOVL_Mixer_pixel_mode_two_pixel_mode(data)                            (0x00000001&(data))
#define  OSDOVL_Mixer_pixel_mode_get_two_pixel_mode(data)                        (0x00000001&(data))

#define  OSDOVL_Mixer_line_mask                                                  0x1802B0C0
#define  OSDOVL_Mixer_line_mask_reg_addr                                         "0xB802B0C0"
#define  OSDOVL_Mixer_line_mask_reg                                              0xB802B0C0
#define  OSDOVL_Mixer_line_mask_inst_addr                                        "0x0024"
#define  set_OSDOVL_Mixer_line_mask_reg(data)                                    (*((volatile unsigned int*)OSDOVL_Mixer_line_mask_reg)=data)
#define  get_OSDOVL_Mixer_line_mask_reg                                          (*((volatile unsigned int*)OSDOVL_Mixer_line_mask_reg))
#define  OSDOVL_Mixer_line_mask_osd6_line_mask_shift                             (12)
#define  OSDOVL_Mixer_line_mask_osd5_line_mask_shift                             (10)
#define  OSDOVL_Mixer_line_mask_osd4_line_mask_shift                             (8)
#define  OSDOVL_Mixer_line_mask_osd3_line_mask_shift                             (6)
#define  OSDOVL_Mixer_line_mask_osd2_line_mask_shift                             (4)
#define  OSDOVL_Mixer_line_mask_osd1_line_mask_shift                             (2)
#define  OSDOVL_Mixer_line_mask_video_line_mask_shift                            (0)
#define  OSDOVL_Mixer_line_mask_osd6_line_mask_mask                              (0x00003000)
#define  OSDOVL_Mixer_line_mask_osd5_line_mask_mask                              (0x00000C00)
#define  OSDOVL_Mixer_line_mask_osd4_line_mask_mask                              (0x00000300)
#define  OSDOVL_Mixer_line_mask_osd3_line_mask_mask                              (0x000000C0)
#define  OSDOVL_Mixer_line_mask_osd2_line_mask_mask                              (0x00000030)
#define  OSDOVL_Mixer_line_mask_osd1_line_mask_mask                              (0x0000000C)
#define  OSDOVL_Mixer_line_mask_video_line_mask_mask                             (0x00000003)
#define  OSDOVL_Mixer_line_mask_osd6_line_mask(data)                             (0x00003000&((data)<<12))
#define  OSDOVL_Mixer_line_mask_osd5_line_mask(data)                             (0x00000C00&((data)<<10))
#define  OSDOVL_Mixer_line_mask_osd4_line_mask(data)                             (0x00000300&((data)<<8))
#define  OSDOVL_Mixer_line_mask_osd3_line_mask(data)                             (0x000000C0&((data)<<6))
#define  OSDOVL_Mixer_line_mask_osd2_line_mask(data)                             (0x00000030&((data)<<4))
#define  OSDOVL_Mixer_line_mask_osd1_line_mask(data)                             (0x0000000C&((data)<<2))
#define  OSDOVL_Mixer_line_mask_video_line_mask(data)                            (0x00000003&(data))
#define  OSDOVL_Mixer_line_mask_get_osd6_line_mask(data)                         ((0x00003000&(data))>>12)
#define  OSDOVL_Mixer_line_mask_get_osd5_line_mask(data)                         ((0x00000C00&(data))>>10)
#define  OSDOVL_Mixer_line_mask_get_osd4_line_mask(data)                         ((0x00000300&(data))>>8)
#define  OSDOVL_Mixer_line_mask_get_osd3_line_mask(data)                         ((0x000000C0&(data))>>6)
#define  OSDOVL_Mixer_line_mask_get_osd2_line_mask(data)                         ((0x00000030&(data))>>4)
#define  OSDOVL_Mixer_line_mask_get_osd1_line_mask(data)                         ((0x0000000C&(data))>>2)
#define  OSDOVL_Mixer_line_mask_get_video_line_mask(data)                        (0x00000003&(data))

#define  OSDOVL_measure_osd1_sta                                                 0x1802B0D0
#define  OSDOVL_measure_osd1_sta_reg_addr                                        "0xB802B0D0"
#define  OSDOVL_measure_osd1_sta_reg                                             0xB802B0D0
#define  OSDOVL_measure_osd1_sta_inst_addr                                       "0x0025"
#define  set_OSDOVL_measure_osd1_sta_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd1_sta_reg)=data)
#define  get_OSDOVL_measure_osd1_sta_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd1_sta_reg))
#define  OSDOVL_measure_osd1_sta_x_shift                                         (16)
#define  OSDOVL_measure_osd1_sta_y_shift                                         (0)
#define  OSDOVL_measure_osd1_sta_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd1_sta_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd1_sta_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd1_sta_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd1_sta_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd1_sta_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd1_end                                                 0x1802B0D4
#define  OSDOVL_measure_osd1_end_reg_addr                                        "0xB802B0D4"
#define  OSDOVL_measure_osd1_end_reg                                             0xB802B0D4
#define  OSDOVL_measure_osd1_end_inst_addr                                       "0x0026"
#define  set_OSDOVL_measure_osd1_end_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd1_end_reg)=data)
#define  get_OSDOVL_measure_osd1_end_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd1_end_reg))
#define  OSDOVL_measure_osd1_end_x_shift                                         (16)
#define  OSDOVL_measure_osd1_end_y_shift                                         (0)
#define  OSDOVL_measure_osd1_end_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd1_end_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd1_end_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd1_end_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd1_end_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd1_end_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd2_sta                                                 0x1802B0D8
#define  OSDOVL_measure_osd2_sta_reg_addr                                        "0xB802B0D8"
#define  OSDOVL_measure_osd2_sta_reg                                             0xB802B0D8
#define  OSDOVL_measure_osd2_sta_inst_addr                                       "0x0027"
#define  set_OSDOVL_measure_osd2_sta_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd2_sta_reg)=data)
#define  get_OSDOVL_measure_osd2_sta_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd2_sta_reg))
#define  OSDOVL_measure_osd2_sta_x_shift                                         (16)
#define  OSDOVL_measure_osd2_sta_y_shift                                         (0)
#define  OSDOVL_measure_osd2_sta_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd2_sta_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd2_sta_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd2_sta_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd2_sta_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd2_sta_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd2_end                                                 0x1802B0DC
#define  OSDOVL_measure_osd2_end_reg_addr                                        "0xB802B0DC"
#define  OSDOVL_measure_osd2_end_reg                                             0xB802B0DC
#define  OSDOVL_measure_osd2_end_inst_addr                                       "0x0028"
#define  set_OSDOVL_measure_osd2_end_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd2_end_reg)=data)
#define  get_OSDOVL_measure_osd2_end_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd2_end_reg))
#define  OSDOVL_measure_osd2_end_x_shift                                         (16)
#define  OSDOVL_measure_osd2_end_y_shift                                         (0)
#define  OSDOVL_measure_osd2_end_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd2_end_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd2_end_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd2_end_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd2_end_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd2_end_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd3_sta                                                 0x1802B0E0
#define  OSDOVL_measure_osd3_sta_reg_addr                                        "0xB802B0E0"
#define  OSDOVL_measure_osd3_sta_reg                                             0xB802B0E0
#define  OSDOVL_measure_osd3_sta_inst_addr                                       "0x0029"
#define  set_OSDOVL_measure_osd3_sta_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd3_sta_reg)=data)
#define  get_OSDOVL_measure_osd3_sta_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd3_sta_reg))
#define  OSDOVL_measure_osd3_sta_x_shift                                         (16)
#define  OSDOVL_measure_osd3_sta_y_shift                                         (0)
#define  OSDOVL_measure_osd3_sta_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd3_sta_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd3_sta_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd3_sta_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd3_sta_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd3_sta_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd3_end                                                 0x1802B0E4
#define  OSDOVL_measure_osd3_end_reg_addr                                        "0xB802B0E4"
#define  OSDOVL_measure_osd3_end_reg                                             0xB802B0E4
#define  OSDOVL_measure_osd3_end_inst_addr                                       "0x002A"
#define  set_OSDOVL_measure_osd3_end_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd3_end_reg)=data)
#define  get_OSDOVL_measure_osd3_end_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd3_end_reg))
#define  OSDOVL_measure_osd3_end_x_shift                                         (16)
#define  OSDOVL_measure_osd3_end_y_shift                                         (0)
#define  OSDOVL_measure_osd3_end_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd3_end_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd3_end_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd3_end_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd3_end_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd3_end_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd4_sta                                                 0x1802B0E8
#define  OSDOVL_measure_osd4_sta_reg_addr                                        "0xB802B0E8"
#define  OSDOVL_measure_osd4_sta_reg                                             0xB802B0E8
#define  OSDOVL_measure_osd4_sta_inst_addr                                       "0x002B"
#define  set_OSDOVL_measure_osd4_sta_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd4_sta_reg)=data)
#define  get_OSDOVL_measure_osd4_sta_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd4_sta_reg))
#define  OSDOVL_measure_osd4_sta_x_shift                                         (16)
#define  OSDOVL_measure_osd4_sta_y_shift                                         (0)
#define  OSDOVL_measure_osd4_sta_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd4_sta_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd4_sta_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd4_sta_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd4_sta_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd4_sta_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd4_end                                                 0x1802B0EC
#define  OSDOVL_measure_osd4_end_reg_addr                                        "0xB802B0EC"
#define  OSDOVL_measure_osd4_end_reg                                             0xB802B0EC
#define  OSDOVL_measure_osd4_end_inst_addr                                       "0x002C"
#define  set_OSDOVL_measure_osd4_end_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd4_end_reg)=data)
#define  get_OSDOVL_measure_osd4_end_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd4_end_reg))
#define  OSDOVL_measure_osd4_end_x_shift                                         (16)
#define  OSDOVL_measure_osd4_end_y_shift                                         (0)
#define  OSDOVL_measure_osd4_end_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd4_end_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd4_end_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd4_end_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd4_end_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd4_end_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd5_sta                                                 0x1802B0F0
#define  OSDOVL_measure_osd5_sta_reg_addr                                        "0xB802B0F0"
#define  OSDOVL_measure_osd5_sta_reg                                             0xB802B0F0
#define  OSDOVL_measure_osd5_sta_inst_addr                                       "0x002D"
#define  set_OSDOVL_measure_osd5_sta_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd5_sta_reg)=data)
#define  get_OSDOVL_measure_osd5_sta_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd5_sta_reg))
#define  OSDOVL_measure_osd5_sta_x_shift                                         (16)
#define  OSDOVL_measure_osd5_sta_y_shift                                         (0)
#define  OSDOVL_measure_osd5_sta_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd5_sta_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd5_sta_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd5_sta_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd5_sta_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd5_sta_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd5_end                                                 0x1802B0F4
#define  OSDOVL_measure_osd5_end_reg_addr                                        "0xB802B0F4"
#define  OSDOVL_measure_osd5_end_reg                                             0xB802B0F4
#define  OSDOVL_measure_osd5_end_inst_addr                                       "0x002E"
#define  set_OSDOVL_measure_osd5_end_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd5_end_reg)=data)
#define  get_OSDOVL_measure_osd5_end_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd5_end_reg))
#define  OSDOVL_measure_osd5_end_x_shift                                         (16)
#define  OSDOVL_measure_osd5_end_y_shift                                         (0)
#define  OSDOVL_measure_osd5_end_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd5_end_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd5_end_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd5_end_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd5_end_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd5_end_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd6_sta                                                 0x1802B0F8
#define  OSDOVL_measure_osd6_sta_reg_addr                                        "0xB802B0F8"
#define  OSDOVL_measure_osd6_sta_reg                                             0xB802B0F8
#define  OSDOVL_measure_osd6_sta_inst_addr                                       "0x002F"
#define  set_OSDOVL_measure_osd6_sta_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd6_sta_reg)=data)
#define  get_OSDOVL_measure_osd6_sta_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd6_sta_reg))
#define  OSDOVL_measure_osd6_sta_x_shift                                         (16)
#define  OSDOVL_measure_osd6_sta_y_shift                                         (0)
#define  OSDOVL_measure_osd6_sta_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd6_sta_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd6_sta_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd6_sta_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd6_sta_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd6_sta_get_y(data)                                     (0x00001FFF&(data))

#define  OSDOVL_measure_osd6_end                                                 0x1802B0FC
#define  OSDOVL_measure_osd6_end_reg_addr                                        "0xB802B0FC"
#define  OSDOVL_measure_osd6_end_reg                                             0xB802B0FC
#define  OSDOVL_measure_osd6_end_inst_addr                                       "0x0030"
#define  set_OSDOVL_measure_osd6_end_reg(data)                                   (*((volatile unsigned int*)OSDOVL_measure_osd6_end_reg)=data)
#define  get_OSDOVL_measure_osd6_end_reg                                         (*((volatile unsigned int*)OSDOVL_measure_osd6_end_reg))
#define  OSDOVL_measure_osd6_end_x_shift                                         (16)
#define  OSDOVL_measure_osd6_end_y_shift                                         (0)
#define  OSDOVL_measure_osd6_end_x_mask                                          (0x1FFF0000)
#define  OSDOVL_measure_osd6_end_y_mask                                          (0x00001FFF)
#define  OSDOVL_measure_osd6_end_x(data)                                         (0x1FFF0000&((data)<<16))
#define  OSDOVL_measure_osd6_end_y(data)                                         (0x00001FFF&(data))
#define  OSDOVL_measure_osd6_end_get_x(data)                                     ((0x1FFF0000&(data))>>16)
#define  OSDOVL_measure_osd6_end_get_y(data)                                     (0x00001FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======OSDOVL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_osd_zone_en:1;
        RBus_UInt32  measure_osd_zone_type:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  video_src_sel:1;
        RBus_UInt32  video_alpha:8;
        RBus_UInt32  res2:9;
        RBus_UInt32  mixero6_en:1;
        RBus_UInt32  mixero5_en:1;
        RBus_UInt32  mixero4_en:1;
        RBus_UInt32  mixero3_en:1;
        RBus_UInt32  mixero2_en:1;
        RBus_UInt32  mixero1_en:1;
        RBus_UInt32  mixer_en:1;
    };
}osdovl_mixer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c5_plane_alpha_en:1;
        RBus_UInt32  c4_plane_alpha_en:1;
        RBus_UInt32  c3_plane_alpha_en:1;
        RBus_UInt32  c2_plane_alpha_en:1;
        RBus_UInt32  c1_plane_alpha_en:1;
        RBus_UInt32  c0_plane_alpha_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  c5_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  c4_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  c3_sel:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  c2_sel:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  c1_sel:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  c0_sel:3;
    };
}osdovl_mixer_layer_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_r:9;
    };
}osdovl_mixer_c0_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_b:9;
    };
}osdovl_mixer_c0_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_a:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_b:8;
    };
}osdovl_mixer_c0_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_r:9;
    };
}osdovl_mixer_c1_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_b:9;
    };
}osdovl_mixer_c1_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_a:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_b:8;
    };
}osdovl_mixer_c1_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_r:9;
    };
}osdovl_mixer_c2_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_b:9;
    };
}osdovl_mixer_c2_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_a:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_b:8;
    };
}osdovl_mixer_c2_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_r:9;
    };
}osdovl_mixer_c3_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_b:9;
    };
}osdovl_mixer_c3_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_a:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_b:8;
    };
}osdovl_mixer_c3_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_r:9;
    };
}osdovl_mixer_c4_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_b:9;
    };
}osdovl_mixer_c4_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_a:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_b:8;
    };
}osdovl_mixer_c4_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_r:9;
    };
}osdovl_mixer_c5_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  plane_alpha_b:9;
    };
}osdovl_mixer_c5_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_a:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_b:8;
    };
}osdovl_mixer_c5_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  k4:6;
    };
}osdovl_mixer_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  k4:6;
    };
}osdovl_mixer_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  k4:6;
    };
}osdovl_mixer_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  k4:6;
    };
}osdovl_mixer_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  k4:6;
    };
}osdovl_mixer_b5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  writeback_en:1;
        RBus_UInt32  writeback_sel:4;
    };
}osdovl_mixer_writeback_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  height:13;
    };
}osdovl_mixer_writeback_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_mixer_writeback_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mixer_crc_sel:4;
    };
}osdovl_mixer_crc_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mixer_crc_done:1;
        RBus_UInt32  mixer_crc_cont:1;
        RBus_UInt32  mixer_crc_start:1;
    };
}osdovl_mixer_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_result:32;
    };
}osdovl_mixer_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_result_odd:32;
    };
}osdovl_mixer_crc_result_odd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_load:1;
    };
}osdovl_osd_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  height:13;
    };
}osdovl_mixer_writeback_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  one_layer_setting_conflict:1;
        RBus_UInt32  c5_src_conflict:1;
        RBus_UInt32  c4_src_conflict:1;
        RBus_UInt32  c3_src_conflict:1;
        RBus_UInt32  c2_src_conflict:1;
        RBus_UInt32  c1_src_conflict:1;
        RBus_UInt32  c0_src_conflict:1;
        RBus_UInt32  one_layer_setting_offline:1;
        RBus_UInt32  osd6_is_offline:1;
        RBus_UInt32  osd5_is_offline:1;
        RBus_UInt32  osd4_is_offline:1;
        RBus_UInt32  osd3_is_offline:1;
        RBus_UInt32  osd2_is_offline:1;
        RBus_UInt32  osd1_is_offline:1;
        RBus_UInt32  res2:1;
    };
}osdovl_mixer_setting_error_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  two_pixel_mode:1;
    };
}osdovl_mixer_pixel_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  osd6_line_mask:2;
        RBus_UInt32  osd5_line_mask:2;
        RBus_UInt32  osd4_line_mask:2;
        RBus_UInt32  osd3_line_mask:2;
        RBus_UInt32  osd2_line_mask:2;
        RBus_UInt32  osd1_line_mask:2;
        RBus_UInt32  video_line_mask:2;
    };
}osdovl_mixer_line_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd1_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd1_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd2_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd2_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd3_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd3_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd4_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd4_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd5_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd5_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd6_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}osdovl_measure_osd6_end_RBUS;

#else //apply LITTLE_ENDIAN

//======OSDOVL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_en:1;
        RBus_UInt32  mixero1_en:1;
        RBus_UInt32  mixero2_en:1;
        RBus_UInt32  mixero3_en:1;
        RBus_UInt32  mixero4_en:1;
        RBus_UInt32  mixero5_en:1;
        RBus_UInt32  mixero6_en:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  video_alpha:8;
        RBus_UInt32  video_src_sel:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  measure_osd_zone_type:1;
        RBus_UInt32  measure_osd_zone_en:1;
    };
}osdovl_mixer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  c1_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  c2_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  c3_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  c4_sel:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  c5_sel:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  c0_plane_alpha_en:1;
        RBus_UInt32  c1_plane_alpha_en:1;
        RBus_UInt32  c2_plane_alpha_en:1;
        RBus_UInt32  c3_plane_alpha_en:1;
        RBus_UInt32  c4_plane_alpha_en:1;
        RBus_UInt32  c5_plane_alpha_en:1;
        RBus_UInt32  res7:2;
    };
}osdovl_mixer_layer_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_r:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c0_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_b:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c0_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_b:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_a:8;
    };
}osdovl_mixer_c0_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_r:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c1_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_b:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c1_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_b:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_a:8;
    };
}osdovl_mixer_c1_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_r:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c2_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_b:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c2_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_b:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_a:8;
    };
}osdovl_mixer_c2_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_r:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c3_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_b:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c3_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_b:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_a:8;
    };
}osdovl_mixer_c3_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_r:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c4_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_b:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c4_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_b:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_a:8;
    };
}osdovl_mixer_c4_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_r:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_a:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c5_plane_alpha1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_alpha_b:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  plane_alpha_g:9;
        RBus_UInt32  res2:7;
    };
}osdovl_mixer_c5_plane_alpha2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plane_offset_b:8;
        RBus_UInt32  plane_offset_g:8;
        RBus_UInt32  plane_offset_r:8;
        RBus_UInt32  plane_offset_a:8;
    };
}osdovl_mixer_c5_plane_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res4:2;
    };
}osdovl_mixer_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res4:2;
    };
}osdovl_mixer_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res4:2;
    };
}osdovl_mixer_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res4:2;
    };
}osdovl_mixer_b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  k3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  k1:6;
        RBus_UInt32  res4:2;
    };
}osdovl_mixer_b5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  writeback_sel:4;
        RBus_UInt32  writeback_en:1;
        RBus_UInt32  res1:27;
    };
}osdovl_mixer_writeback_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  height:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  width:13;
        RBus_UInt32  res2:3;
    };
}osdovl_mixer_writeback_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_mixer_writeback_position_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_sel:4;
        RBus_UInt32  res1:28;
    };
}osdovl_mixer_crc_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_start:1;
        RBus_UInt32  mixer_crc_cont:1;
        RBus_UInt32  mixer_crc_done:1;
        RBus_UInt32  res1:29;
    };
}osdovl_mixer_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_result:32;
    };
}osdovl_mixer_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_crc_result_odd:32;
    };
}osdovl_mixer_crc_result_odd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_load:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res1:29;
    };
}osdovl_osd_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  height:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  width:13;
        RBus_UInt32  res2:3;
    };
}osdovl_mixer_writeback_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  osd1_is_offline:1;
        RBus_UInt32  osd2_is_offline:1;
        RBus_UInt32  osd3_is_offline:1;
        RBus_UInt32  osd4_is_offline:1;
        RBus_UInt32  osd5_is_offline:1;
        RBus_UInt32  osd6_is_offline:1;
        RBus_UInt32  one_layer_setting_offline:1;
        RBus_UInt32  c0_src_conflict:1;
        RBus_UInt32  c1_src_conflict:1;
        RBus_UInt32  c2_src_conflict:1;
        RBus_UInt32  c3_src_conflict:1;
        RBus_UInt32  c4_src_conflict:1;
        RBus_UInt32  c5_src_conflict:1;
        RBus_UInt32  one_layer_setting_conflict:1;
        RBus_UInt32  res2:17;
    };
}osdovl_mixer_setting_error_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_pixel_mode:1;
        RBus_UInt32  res1:31;
    };
}osdovl_mixer_pixel_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  video_line_mask:2;
        RBus_UInt32  osd1_line_mask:2;
        RBus_UInt32  osd2_line_mask:2;
        RBus_UInt32  osd3_line_mask:2;
        RBus_UInt32  osd4_line_mask:2;
        RBus_UInt32  osd5_line_mask:2;
        RBus_UInt32  osd6_line_mask:2;
        RBus_UInt32  res1:18;
    };
}osdovl_mixer_line_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd1_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd1_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd2_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd2_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd3_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd3_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd4_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd4_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd5_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd5_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd6_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}osdovl_measure_osd6_end_RBUS;




#endif 


#endif 
