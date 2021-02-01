/**
* @file rbusD_2d_to_3dReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/4/1
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_D_2D_TO_3D_REG_H_
#define _RBUS_D_2D_TO_3D_REG_H_

#include "rbus_types.h"



//  D_2D_TO_3D Register Address
#define  D_2D_TO_3D_D_2D3D_Db_Control                                            0x18029600
#define  D_2D_TO_3D_D_2D3D_Db_Control_reg_addr                                   "0xB8029600"
#define  D_2D_TO_3D_D_2D3D_Db_Control_reg                                        0xB8029600
#define  D_2D_TO_3D_D_2D3D_Db_Control_inst_addr                                  "0x0000"
#define  set_D_2D_TO_3D_D_2D3D_Db_Control_reg(data)                              (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Db_Control_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Db_Control_reg                                    (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Db_Control_reg))
#define  D_2D_TO_3D_D_2D3D_Db_Control_db_en_shift                                (31)
#define  D_2D_TO_3D_D_2D3D_Db_Control_db_read_level_shift                        (30)
#define  D_2D_TO_3D_D_2D3D_Db_Control_db_apply_shift                             (29)
#define  D_2D_TO_3D_D_2D3D_Db_Control_db_en_mask                                 (0x80000000)
#define  D_2D_TO_3D_D_2D3D_Db_Control_db_read_level_mask                         (0x40000000)
#define  D_2D_TO_3D_D_2D3D_Db_Control_db_apply_mask                              (0x20000000)
#define  D_2D_TO_3D_D_2D3D_Db_Control_db_en(data)                                (0x80000000&((data)<<31))
#define  D_2D_TO_3D_D_2D3D_Db_Control_db_read_level(data)                        (0x40000000&((data)<<30))
#define  D_2D_TO_3D_D_2D3D_Db_Control_db_apply(data)                             (0x20000000&((data)<<29))
#define  D_2D_TO_3D_D_2D3D_Db_Control_get_db_en(data)                            ((0x80000000&(data))>>31)
#define  D_2D_TO_3D_D_2D3D_Db_Control_get_db_read_level(data)                    ((0x40000000&(data))>>30)
#define  D_2D_TO_3D_D_2D3D_Db_Control_get_db_apply(data)                         ((0x20000000&(data))>>29)

#define  D_2D_TO_3D_D_2D3D_Control                                               0x18029604
#define  D_2D_TO_3D_D_2D3D_Control_reg_addr                                      "0xB8029604"
#define  D_2D_TO_3D_D_2D3D_Control_reg                                           0xB8029604
#define  D_2D_TO_3D_D_2D3D_Control_inst_addr                                     "0x0001"
#define  set_D_2D_TO_3D_D_2D3D_Control_reg(data)                                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Control_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Control_reg                                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Control_reg))
#define  D_2D_TO_3D_D_2D3D_Control_object6_depth_en_shift                        (17)
#define  D_2D_TO_3D_D_2D3D_Control_object5_depth_en_shift                        (16)
#define  D_2D_TO_3D_D_2D3D_Control_object4_depth_en_shift                        (15)
#define  D_2D_TO_3D_D_2D3D_Control_depth_src_mux_shift                           (14)
#define  D_2D_TO_3D_D_2D3D_Control_render_method_shift                           (13)
#define  D_2D_TO_3D_D_2D3D_Control_input_sbs_render_mode_shift                   (12)
#define  D_2D_TO_3D_D_2D3D_Control_obj_y_src_sel_shift                           (11)
#define  D_2D_TO_3D_D_2D3D_Control_output_format_shift                           (10)
#define  D_2D_TO_3D_D_2D3D_Control_d_2d3d_depth_frac_en_shift                    (9)
#define  D_2D_TO_3D_D_2D3D_Control_depth_debug_mode_shift                        (8)
#define  D_2D_TO_3D_D_2D3D_Control_l_frame_shift_en_shift                        (7)
#define  D_2D_TO_3D_D_2D3D_Control_r_frame_shift_en_shift                        (6)
#define  D_2D_TO_3D_D_2D3D_Control_l_flag_inv_shift                              (5)
#define  D_2D_TO_3D_D_2D3D_Control_tilt_depth_en_shift                           (4)
#define  D_2D_TO_3D_D_2D3D_Control_object3_depth_en_shift                        (3)
#define  D_2D_TO_3D_D_2D3D_Control_object2_depth_en_shift                        (2)
#define  D_2D_TO_3D_D_2D3D_Control_object1_depth_en_shift                        (1)
#define  D_2D_TO_3D_D_2D3D_Control_object6_depth_en_mask                         (0x00020000)
#define  D_2D_TO_3D_D_2D3D_Control_object5_depth_en_mask                         (0x00010000)
#define  D_2D_TO_3D_D_2D3D_Control_object4_depth_en_mask                         (0x00008000)
#define  D_2D_TO_3D_D_2D3D_Control_depth_src_mux_mask                            (0x00004000)
#define  D_2D_TO_3D_D_2D3D_Control_render_method_mask                            (0x00002000)
#define  D_2D_TO_3D_D_2D3D_Control_input_sbs_render_mode_mask                    (0x00001000)
#define  D_2D_TO_3D_D_2D3D_Control_obj_y_src_sel_mask                            (0x00000800)
#define  D_2D_TO_3D_D_2D3D_Control_output_format_mask                            (0x00000400)
#define  D_2D_TO_3D_D_2D3D_Control_d_2d3d_depth_frac_en_mask                     (0x00000200)
#define  D_2D_TO_3D_D_2D3D_Control_depth_debug_mode_mask                         (0x00000100)
#define  D_2D_TO_3D_D_2D3D_Control_l_frame_shift_en_mask                         (0x00000080)
#define  D_2D_TO_3D_D_2D3D_Control_r_frame_shift_en_mask                         (0x00000040)
#define  D_2D_TO_3D_D_2D3D_Control_l_flag_inv_mask                               (0x00000020)
#define  D_2D_TO_3D_D_2D3D_Control_tilt_depth_en_mask                            (0x00000010)
#define  D_2D_TO_3D_D_2D3D_Control_object3_depth_en_mask                         (0x00000008)
#define  D_2D_TO_3D_D_2D3D_Control_object2_depth_en_mask                         (0x00000004)
#define  D_2D_TO_3D_D_2D3D_Control_object1_depth_en_mask                         (0x00000002)
#define  D_2D_TO_3D_D_2D3D_Control_object6_depth_en(data)                        (0x00020000&((data)<<17))
#define  D_2D_TO_3D_D_2D3D_Control_object5_depth_en(data)                        (0x00010000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_Control_object4_depth_en(data)                        (0x00008000&((data)<<15))
#define  D_2D_TO_3D_D_2D3D_Control_depth_src_mux(data)                           (0x00004000&((data)<<14))
#define  D_2D_TO_3D_D_2D3D_Control_render_method(data)                           (0x00002000&((data)<<13))
#define  D_2D_TO_3D_D_2D3D_Control_input_sbs_render_mode(data)                   (0x00001000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_Control_obj_y_src_sel(data)                           (0x00000800&((data)<<11))
#define  D_2D_TO_3D_D_2D3D_Control_output_format(data)                           (0x00000400&((data)<<10))
#define  D_2D_TO_3D_D_2D3D_Control_d_2d3d_depth_frac_en(data)                    (0x00000200&((data)<<9))
#define  D_2D_TO_3D_D_2D3D_Control_depth_debug_mode(data)                        (0x00000100&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Control_l_frame_shift_en(data)                        (0x00000080&((data)<<7))
#define  D_2D_TO_3D_D_2D3D_Control_r_frame_shift_en(data)                        (0x00000040&((data)<<6))
#define  D_2D_TO_3D_D_2D3D_Control_l_flag_inv(data)                              (0x00000020&((data)<<5))
#define  D_2D_TO_3D_D_2D3D_Control_tilt_depth_en(data)                           (0x00000010&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_Control_object3_depth_en(data)                        (0x00000008&((data)<<3))
#define  D_2D_TO_3D_D_2D3D_Control_object2_depth_en(data)                        (0x00000004&((data)<<2))
#define  D_2D_TO_3D_D_2D3D_Control_object1_depth_en(data)                        (0x00000002&((data)<<1))
#define  D_2D_TO_3D_D_2D3D_Control_get_object6_depth_en(data)                    ((0x00020000&(data))>>17)
#define  D_2D_TO_3D_D_2D3D_Control_get_object5_depth_en(data)                    ((0x00010000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_Control_get_object4_depth_en(data)                    ((0x00008000&(data))>>15)
#define  D_2D_TO_3D_D_2D3D_Control_get_depth_src_mux(data)                       ((0x00004000&(data))>>14)
#define  D_2D_TO_3D_D_2D3D_Control_get_render_method(data)                       ((0x00002000&(data))>>13)
#define  D_2D_TO_3D_D_2D3D_Control_get_input_sbs_render_mode(data)               ((0x00001000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_Control_get_obj_y_src_sel(data)                       ((0x00000800&(data))>>11)
#define  D_2D_TO_3D_D_2D3D_Control_get_output_format(data)                       ((0x00000400&(data))>>10)
#define  D_2D_TO_3D_D_2D3D_Control_get_d_2d3d_depth_frac_en(data)                ((0x00000200&(data))>>9)
#define  D_2D_TO_3D_D_2D3D_Control_get_depth_debug_mode(data)                    ((0x00000100&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Control_get_l_frame_shift_en(data)                    ((0x00000080&(data))>>7)
#define  D_2D_TO_3D_D_2D3D_Control_get_r_frame_shift_en(data)                    ((0x00000040&(data))>>6)
#define  D_2D_TO_3D_D_2D3D_Control_get_l_flag_inv(data)                          ((0x00000020&(data))>>5)
#define  D_2D_TO_3D_D_2D3D_Control_get_tilt_depth_en(data)                       ((0x00000010&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_Control_get_object3_depth_en(data)                    ((0x00000008&(data))>>3)
#define  D_2D_TO_3D_D_2D3D_Control_get_object2_depth_en(data)                    ((0x00000004&(data))>>2)
#define  D_2D_TO_3D_D_2D3D_Control_get_object1_depth_en(data)                    ((0x00000002&(data))>>1)

#define  D_2D_TO_3D_D_2D3D_Object1_Operation                                     0x18029608
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_reg_addr                            "0xB8029608"
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_reg                                 0xB8029608
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_inst_addr                           "0x0002"
#define  set_D_2D_TO_3D_D_2D3D_Object1_Operation_reg(data)                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object1_Operation_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Object1_Operation_reg                             (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object1_Operation_reg))
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_object1_thd_shift                   (20)
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_object1_offset_shift                (8)
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_object1_gain_shift                  (0)
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_object1_thd_mask                    (0x0FF00000)
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_object1_offset_mask                 (0x0001FF00)
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_object1_gain_mask                   (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_object1_thd(data)                   (0x0FF00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_object1_offset(data)                (0x0001FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_object1_gain(data)                  (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_get_object1_thd(data)               ((0x0FF00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_get_object1_offset(data)            ((0x0001FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Object1_Operation_get_object1_gain(data)              (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_Object2_Operation                                     0x1802960C
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_reg_addr                            "0xB802960C"
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_reg                                 0xB802960C
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_inst_addr                           "0x0003"
#define  set_D_2D_TO_3D_D_2D3D_Object2_Operation_reg(data)                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object2_Operation_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Object2_Operation_reg                             (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object2_Operation_reg))
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_object2_thd_shift                   (20)
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_object2_offset_shift                (8)
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_object2_gain_shift                  (0)
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_object2_thd_mask                    (0x0FF00000)
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_object2_offset_mask                 (0x0001FF00)
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_object2_gain_mask                   (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_object2_thd(data)                   (0x0FF00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_object2_offset(data)                (0x0001FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_object2_gain(data)                  (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_get_object2_thd(data)               ((0x0FF00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_get_object2_offset(data)            ((0x0001FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Object2_Operation_get_object2_gain(data)              (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_Object3_Operation                                     0x18029610
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_reg_addr                            "0xB8029610"
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_reg                                 0xB8029610
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_inst_addr                           "0x0004"
#define  set_D_2D_TO_3D_D_2D3D_Object3_Operation_reg(data)                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object3_Operation_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Object3_Operation_reg                             (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object3_Operation_reg))
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_object3_thd_shift                   (20)
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_object3_offset_shift                (8)
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_object3_gain_shift                  (0)
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_object3_thd_mask                    (0x0FF00000)
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_object3_offset_mask                 (0x0001FF00)
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_object3_gain_mask                   (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_object3_thd(data)                   (0x0FF00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_object3_offset(data)                (0x0001FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_object3_gain(data)                  (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_get_object3_thd(data)               ((0x0FF00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_get_object3_offset(data)            ((0x0001FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Object3_Operation_get_object3_gain(data)              (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_Object4_Operation                                     0x18029624
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_reg_addr                            "0xB8029624"
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_reg                                 0xB8029624
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_inst_addr                           "0x0005"
#define  set_D_2D_TO_3D_D_2D3D_Object4_Operation_reg(data)                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object4_Operation_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Object4_Operation_reg                             (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object4_Operation_reg))
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_object4_thd_shift                   (20)
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_object4_offset_shift                (8)
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_object4_gain_shift                  (0)
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_object4_thd_mask                    (0x0FF00000)
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_object4_offset_mask                 (0x0001FF00)
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_object4_gain_mask                   (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_object4_thd(data)                   (0x0FF00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_object4_offset(data)                (0x0001FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_object4_gain(data)                  (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_get_object4_thd(data)               ((0x0FF00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_get_object4_offset(data)            ((0x0001FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Object4_Operation_get_object4_gain(data)              (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_Object5_Operation                                     0x18029628
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_reg_addr                            "0xB8029628"
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_reg                                 0xB8029628
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_inst_addr                           "0x0006"
#define  set_D_2D_TO_3D_D_2D3D_Object5_Operation_reg(data)                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object5_Operation_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Object5_Operation_reg                             (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object5_Operation_reg))
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_object5_thd_shift                   (20)
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_object5_offset_shift                (8)
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_object5_gain_shift                  (0)
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_object5_thd_mask                    (0x0FF00000)
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_object5_offset_mask                 (0x0001FF00)
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_object5_gain_mask                   (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_object5_thd(data)                   (0x0FF00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_object5_offset(data)                (0x0001FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_object5_gain(data)                  (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_get_object5_thd(data)               ((0x0FF00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_get_object5_offset(data)            ((0x0001FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Object5_Operation_get_object5_gain(data)              (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_Object6_Operation                                     0x1802962C
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_reg_addr                            "0xB802962C"
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_reg                                 0xB802962C
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_inst_addr                           "0x0007"
#define  set_D_2D_TO_3D_D_2D3D_Object6_Operation_reg(data)                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object6_Operation_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Object6_Operation_reg                             (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Object6_Operation_reg))
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_object6_thd_shift                   (20)
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_object6_offset_shift                (8)
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_object6_gain_shift                  (0)
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_object6_thd_mask                    (0x0FF00000)
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_object6_offset_mask                 (0x0001FF00)
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_object6_gain_mask                   (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_object6_thd(data)                   (0x0FF00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_object6_offset(data)                (0x0001FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_object6_gain(data)                  (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_get_object6_thd(data)               ((0x0FF00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_get_object6_offset(data)            ((0x0001FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Object6_Operation_get_object6_gain(data)              (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_Tilt_Operation                                        0x18029614
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_reg_addr                               "0xB8029614"
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_reg                                    0xB8029614
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_inst_addr                              "0x0008"
#define  set_D_2D_TO_3D_D_2D3D_Tilt_Operation_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Tilt_Operation_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Tilt_Operation_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Tilt_Operation_reg))
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_tilt_thd_shift                         (16)
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_tilt_offset_shift                      (8)
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_tilt_gain_shift                        (0)
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_tilt_thd_mask                          (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_tilt_offset_mask                       (0x0000FF00)
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_tilt_gain_mask                         (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_tilt_thd(data)                         (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_tilt_offset(data)                      (0x0000FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_tilt_gain(data)                        (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_get_tilt_thd(data)                     ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_get_tilt_offset(data)                  ((0x0000FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Tilt_Operation_get_tilt_gain(data)                    (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_Histo_Operation                                       0x18029618
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_reg_addr                              "0xB8029618"
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_reg                                   0xB8029618
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_inst_addr                             "0x0009"
#define  set_D_2D_TO_3D_D_2D3D_Histo_Operation_reg(data)                         (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Histo_Operation_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Histo_Operation_reg                               (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Histo_Operation_reg))
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_histo_thd_shift                       (16)
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_histo_offset_shift                    (8)
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_histo_gain_shift                      (0)
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_histo_thd_mask                        (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_histo_offset_mask                     (0x0000FF00)
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_histo_gain_mask                       (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_histo_thd(data)                       (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_histo_offset(data)                    (0x0000FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_histo_gain(data)                      (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_get_histo_thd(data)                   ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_get_histo_offset(data)                ((0x0000FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Histo_Operation_get_histo_gain(data)                  (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_B_BORDER                                              0x18029620
#define  D_2D_TO_3D_D_2D3D_B_BORDER_reg_addr                                     "0xB8029620"
#define  D_2D_TO_3D_D_2D3D_B_BORDER_reg                                          0xB8029620
#define  D_2D_TO_3D_D_2D3D_B_BORDER_inst_addr                                    "0x000A"
#define  set_D_2D_TO_3D_D_2D3D_B_BORDER_reg(data)                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_B_BORDER_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_B_BORDER_reg                                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_B_BORDER_reg))
#define  D_2D_TO_3D_D_2D3D_B_BORDER_border_en_shift                              (31)
#define  D_2D_TO_3D_D_2D3D_B_BORDER_border_den_start_shift                       (16)
#define  D_2D_TO_3D_D_2D3D_B_BORDER_border_den_end_shift                         (0)
#define  D_2D_TO_3D_D_2D3D_B_BORDER_border_en_mask                               (0x80000000)
#define  D_2D_TO_3D_D_2D3D_B_BORDER_border_den_start_mask                        (0x1FFF0000)
#define  D_2D_TO_3D_D_2D3D_B_BORDER_border_den_end_mask                          (0x00001FFF)
#define  D_2D_TO_3D_D_2D3D_B_BORDER_border_en(data)                              (0x80000000&((data)<<31))
#define  D_2D_TO_3D_D_2D3D_B_BORDER_border_den_start(data)                       (0x1FFF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_B_BORDER_border_den_end(data)                         (0x00001FFF&(data))
#define  D_2D_TO_3D_D_2D3D_B_BORDER_get_border_en(data)                          ((0x80000000&(data))>>31)
#define  D_2D_TO_3D_D_2D3D_B_BORDER_get_border_den_start(data)                   ((0x1FFF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_B_BORDER_get_border_den_end(data)                     (0x00001FFF&(data))

#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH                                            0x18029630
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg_addr                                   "0xB8029630"
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg                                        0xB8029630
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_inst_addr                                  "0x000B"
#define  set_D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg(data)                              (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg                                    (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg))
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_tilt_depth_step_shift                      (16)
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_initial_depth_shift                        (0)
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_tilt_depth_step_mask                       (0x0FFF0000)
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_initial_depth_mask                         (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_tilt_depth_step(data)                      (0x0FFF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_initial_depth(data)                        (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_get_tilt_depth_step(data)                  ((0x0FFF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_get_initial_depth(data)                    (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1                                        0x18029634
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg_addr                               "0xB8029634"
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg                                    0xB8029634
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_inst_addr                              "0x000C"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_object1_depth_weight1_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_object1_depth_ref1_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_object1_depth_dir_shift                (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_object1_depth_weight1_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_object1_depth_ref1_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_object1_depth_dir_mask                 (0x00000001)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_object1_depth_weight1(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_object1_depth_ref1(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_object1_depth_dir(data)                (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_get_object1_depth_weight1(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_get_object1_depth_ref1(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_get_object1_depth_dir(data)            (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2                                        0x18029638
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg_addr                               "0xB8029638"
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg                                    0xB8029638
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_inst_addr                              "0x000D"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_weight3_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_ref3_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_weight2_shift            (8)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_ref2_shift               (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_weight3_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_ref3_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_weight2_mask             (0x00000700)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_ref2_mask                (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_weight3(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_ref3(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_weight2(data)            (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_object1_depth_ref2(data)               (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_get_object1_depth_weight3(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_get_object1_depth_ref3(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_get_object1_depth_weight2(data)        ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_get_object1_depth_ref2(data)           (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1                                        0x1802963C
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_reg_addr                               "0xB802963C"
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_reg                                    0xB802963C
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_inst_addr                              "0x000E"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_object2_depth_weight1_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_object2_depth_ref1_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_object2_depth_dir_shift                (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_object2_depth_weight1_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_object2_depth_ref1_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_object2_depth_dir_mask                 (0x00000001)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_object2_depth_weight1(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_object2_depth_ref1(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_object2_depth_dir(data)                (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_get_object2_depth_weight1(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_get_object2_depth_ref1(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_get_object2_depth_dir(data)            (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2                                        0x18029640
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg_addr                               "0xB8029640"
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg                                    0xB8029640
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_inst_addr                              "0x000F"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_weight3_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_ref3_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_weight2_shift            (8)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_ref2_shift               (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_weight3_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_ref3_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_weight2_mask             (0x00000700)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_ref2_mask                (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_weight3(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_ref3(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_weight2(data)            (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_object2_depth_ref2(data)               (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_get_object2_depth_weight3(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_get_object2_depth_ref3(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_get_object2_depth_weight2(data)        ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_get_object2_depth_ref2(data)           (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1                                        0x18029644
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg_addr                               "0xB8029644"
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg                                    0xB8029644
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_inst_addr                              "0x0010"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_object3_depth_weight1_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_object3_depth_ref1_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_object3_depth_dir_shift                (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_object3_depth_weight1_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_object3_depth_ref1_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_object3_depth_dir_mask                 (0x00000001)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_object3_depth_weight1(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_object3_depth_ref1(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_object3_depth_dir(data)                (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_get_object3_depth_weight1(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_get_object3_depth_ref1(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_get_object3_depth_dir(data)            (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2                                        0x18029648
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg_addr                               "0xB8029648"
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg                                    0xB8029648
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_inst_addr                              "0x0011"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_weight3_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_ref3_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_weight2_shift            (8)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_ref2_shift               (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_weight3_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_ref3_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_weight2_mask             (0x00000700)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_ref2_mask                (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_weight3(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_ref3(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_weight2(data)            (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_object3_depth_ref2(data)               (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_get_object3_depth_weight3(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_get_object3_depth_ref3(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_get_object3_depth_weight2(data)        ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_get_object3_depth_ref2(data)           (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1                                        0x180296A0
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_reg_addr                               "0xB80296A0"
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_reg                                    0xB80296A0
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_inst_addr                              "0x0012"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_object4_depth_weight1_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_object4_depth_ref1_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_object4_depth_dir_shift                (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_object4_depth_weight1_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_object4_depth_ref1_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_object4_depth_dir_mask                 (0x00000001)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_object4_depth_weight1(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_object4_depth_ref1(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_object4_depth_dir(data)                (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_get_object4_depth_weight1(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_get_object4_depth_ref1(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH1_get_object4_depth_dir(data)            (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2                                        0x180296A4
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_reg_addr                               "0xB80296A4"
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_reg                                    0xB80296A4
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_inst_addr                              "0x0013"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_weight3_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_ref3_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_weight2_shift            (8)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_ref2_shift               (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_weight3_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_ref3_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_weight2_mask             (0x00000700)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_ref2_mask                (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_weight3(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_ref3(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_weight2(data)            (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_object4_depth_ref2(data)               (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_get_object4_depth_weight3(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_get_object4_depth_ref3(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_get_object4_depth_weight2(data)        ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_OBJECT4_DEPTH2_get_object4_depth_ref2(data)           (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1                                        0x180296A8
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_reg_addr                               "0xB80296A8"
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_reg                                    0xB80296A8
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_inst_addr                              "0x0014"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_object5_depth_weight1_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_object5_depth_ref1_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_object5_depth_dir_shift                (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_object5_depth_weight1_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_object5_depth_ref1_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_object5_depth_dir_mask                 (0x00000001)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_object5_depth_weight1(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_object5_depth_ref1(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_object5_depth_dir(data)                (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_get_object5_depth_weight1(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_get_object5_depth_ref1(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH1_get_object5_depth_dir(data)            (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2                                        0x180296AC
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_reg_addr                               "0xB80296AC"
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_reg                                    0xB80296AC
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_inst_addr                              "0x0015"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_weight3_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_ref3_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_weight2_shift            (8)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_ref2_shift               (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_weight3_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_ref3_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_weight2_mask             (0x00000700)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_ref2_mask                (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_weight3(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_ref3(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_weight2(data)            (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_object5_depth_ref2(data)               (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_get_object5_depth_weight3(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_get_object5_depth_ref3(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_get_object5_depth_weight2(data)        ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_OBJECT5_DEPTH2_get_object5_depth_ref2(data)           (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1                                        0x180296B0
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_reg_addr                               "0xB80296B0"
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_reg                                    0xB80296B0
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_inst_addr                              "0x0016"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_object6_depth_weight1_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_object6_depth_ref1_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_object6_depth_dir_shift                (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_object6_depth_weight1_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_object6_depth_ref1_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_object6_depth_dir_mask                 (0x00000001)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_object6_depth_weight1(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_object6_depth_ref1(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_object6_depth_dir(data)                (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_get_object6_depth_weight1(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_get_object6_depth_ref1(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH1_get_object6_depth_dir(data)            (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2                                        0x180296B4
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_reg_addr                               "0xB80296B4"
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_reg                                    0xB80296B4
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_inst_addr                              "0x0017"
#define  set_D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_reg))
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_weight3_shift            (24)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_ref3_shift               (16)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_weight2_shift            (8)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_ref2_shift               (0)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_weight3_mask             (0x07000000)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_ref3_mask                (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_weight2_mask             (0x00000700)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_ref2_mask                (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_weight3(data)            (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_ref3(data)               (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_weight2(data)            (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_object6_depth_ref2(data)               (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_get_object6_depth_weight3(data)        ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_get_object6_depth_ref3(data)           ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_get_object6_depth_weight2(data)        ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_OBJECT6_DEPTH2_get_object6_depth_ref2(data)           (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL                                             0x18029660
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg_addr                                    "0xB8029660"
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg                                         0xB8029660
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_inst_addr                                   "0x0018"
#define  set_D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg(data)                               (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg                                     (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg))
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_c0_shift                   (20)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_c1_shift                   (16)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_c2_shift                   (12)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_en_shift                   (0)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_c0_mask                    (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_c1_mask                    (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_c2_mask                    (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_en_mask                    (0x00000001)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_c0(data)                   (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_c1(data)                   (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_c2(data)                   (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_d_2d3d_depth_lpf_en(data)                   (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_get_d_2d3d_depth_lpf_c0(data)               ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_get_d_2d3d_depth_lpf_c1(data)               ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_get_d_2d3d_depth_lpf_c2(data)               ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_get_d_2d3d_depth_lpf_en(data)               (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_SHIFTER                                               0x18029664
#define  D_2D_TO_3D_D_2D3D_SHIFTER_reg_addr                                      "0xB8029664"
#define  D_2D_TO_3D_D_2D3D_SHIFTER_reg                                           0xB8029664
#define  D_2D_TO_3D_D_2D3D_SHIFTER_inst_addr                                     "0x0019"
#define  set_D_2D_TO_3D_D_2D3D_SHIFTER_reg(data)                                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_SHIFTER_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_SHIFTER_reg                                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_SHIFTER_reg))
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_offset2_shift                         (22)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_thd_shift                             (16)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_offset_shift                          (8)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_gain_shift                            (0)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_offset2_mask                          (0xFFC00000)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_thd_mask                              (0x003F0000)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_offset_mask                           (0x0000FF00)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_gain_mask                             (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_offset2(data)                         (0xFFC00000&((data)<<22))
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_thd(data)                             (0x003F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_offset(data)                          (0x0000FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_SHIFTER_shifter_gain(data)                            (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_SHIFTER_get_shifter_offset2(data)                     ((0xFFC00000&(data))>>22)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_get_shifter_thd(data)                         ((0x003F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_get_shifter_offset(data)                      ((0x0000FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_get_shifter_gain(data)                        (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_boundary_scaling                                      0x18029668
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_reg_addr                             "0xB8029668"
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_reg                                  0xB8029668
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_inst_addr                            "0x001A"
#define  set_D_2D_TO_3D_D_2D3D_boundary_scaling_reg(data)                        (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_boundary_scaling_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_boundary_scaling_reg                              (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_boundary_scaling_reg))
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_dbs_seg_num_shift                    (1)
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_dbs_en_shift                         (0)
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_dbs_seg_num_mask                     (0x00000006)
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_dbs_en_mask                          (0x00000001)
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_dbs_seg_num(data)                    (0x00000006&((data)<<1))
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_dbs_en(data)                         (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_get_dbs_seg_num(data)                ((0x00000006&(data))>>1)
#define  D_2D_TO_3D_D_2D3D_boundary_scaling_get_dbs_en(data)                     (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_HOLE_FILL                                             0x18029670
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_reg_addr                                    "0xB8029670"
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_reg                                         0xB8029670
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_inst_addr                                   "0x001B"
#define  set_D_2D_TO_3D_D_2D3D_HOLE_FILL_reg(data)                               (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HOLE_FILL_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HOLE_FILL_reg                                     (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HOLE_FILL_reg))
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_hf_new_en_shift                             (3)
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_hole_fil_sel_shift                          (0)
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_hf_new_en_mask                              (0x00000008)
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_hole_fil_sel_mask                           (0x00000007)
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_hf_new_en(data)                             (0x00000008&((data)<<3))
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_hole_fil_sel(data)                          (0x00000007&(data))
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_get_hf_new_en(data)                         ((0x00000008&(data))>>3)
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_get_hole_fil_sel(data)                      (0x00000007&(data))

#define  D_2D_TO_3D_D_2D3D_DUMMY0                                                0x18029674
#define  D_2D_TO_3D_D_2D3D_DUMMY0_reg_addr                                       "0xB8029674"
#define  D_2D_TO_3D_D_2D3D_DUMMY0_reg                                            0xB8029674
#define  D_2D_TO_3D_D_2D3D_DUMMY0_inst_addr                                      "0x001C"
#define  set_D_2D_TO_3D_D_2D3D_DUMMY0_reg(data)                                  (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_DUMMY0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_DUMMY0_reg                                        (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_DUMMY0_reg))
#define  D_2D_TO_3D_D_2D3D_DUMMY0_dummy_31_0_shift                               (0)
#define  D_2D_TO_3D_D_2D3D_DUMMY0_dummy_31_0_mask                                (0xFFFFFFFF)
#define  D_2D_TO_3D_D_2D3D_DUMMY0_dummy_31_0(data)                               (0xFFFFFFFF&(data))
#define  D_2D_TO_3D_D_2D3D_DUMMY0_get_dummy_31_0(data)                           (0xFFFFFFFF&(data))

#define  D_2D_TO_3D_D_2D3D_DUMMY1                                                0x18029678
#define  D_2D_TO_3D_D_2D3D_DUMMY1_reg_addr                                       "0xB8029678"
#define  D_2D_TO_3D_D_2D3D_DUMMY1_reg                                            0xB8029678
#define  D_2D_TO_3D_D_2D3D_DUMMY1_inst_addr                                      "0x001D"
#define  set_D_2D_TO_3D_D_2D3D_DUMMY1_reg(data)                                  (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_DUMMY1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_DUMMY1_reg                                        (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_DUMMY1_reg))
#define  D_2D_TO_3D_D_2D3D_DUMMY1_dummy_31_0_shift                               (0)
#define  D_2D_TO_3D_D_2D3D_DUMMY1_dummy_31_0_mask                                (0xFFFFFFFF)
#define  D_2D_TO_3D_D_2D3D_DUMMY1_dummy_31_0(data)                               (0xFFFFFFFF&(data))
#define  D_2D_TO_3D_D_2D3D_DUMMY1_get_dummy_31_0(data)                           (0xFFFFFFFF&(data))

#define  D_2D_TO_3D_D_2D3D_Bist0                                                 0x18029680
#define  D_2D_TO_3D_D_2D3D_Bist0_reg_addr                                        "0xB8029680"
#define  D_2D_TO_3D_D_2D3D_Bist0_reg                                             0xB8029680
#define  D_2D_TO_3D_D_2D3D_Bist0_inst_addr                                       "0x001E"
#define  set_D_2D_TO_3D_D_2D3D_Bist0_reg(data)                                   (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Bist0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Bist0_reg                                         (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Bist0_reg))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_3_shift                           (31)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_2_shift                           (30)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_1_shift                           (29)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_0_shift                           (28)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmea_1_shift                          (27)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmeb_1_shift                          (26)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmea_0_shift                          (25)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmeb_0_shift                          (24)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_3_shift                            (23)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_2_shift                            (22)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_1_shift                            (21)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_0_shift                            (20)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_ls_1_shift                            (19)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_ls_0_shift                            (18)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_3_shift                 (15)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_2_shift                 (14)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_1_shift                 (13)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_0_shift                 (12)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_drf_bist_fail_1_shift                 (11)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_drf_bist_fail_0_shift                 (10)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_3_shift                     (7)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_2_shift                     (6)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_1_shift                     (5)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_0_shift                     (4)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_bist_fail_1_shift                     (3)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_bist_fail_0_shift                     (2)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_3_mask                            (0x80000000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_2_mask                            (0x40000000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_1_mask                            (0x20000000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_0_mask                            (0x10000000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmea_1_mask                           (0x08000000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmeb_1_mask                           (0x04000000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmea_0_mask                           (0x02000000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmeb_0_mask                           (0x01000000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_3_mask                             (0x00800000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_2_mask                             (0x00400000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_1_mask                             (0x00200000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_0_mask                             (0x00100000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_ls_1_mask                             (0x00080000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_ls_0_mask                             (0x00040000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_3_mask                  (0x00008000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_2_mask                  (0x00004000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_1_mask                  (0x00002000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_0_mask                  (0x00001000)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_drf_bist_fail_1_mask                  (0x00000800)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_drf_bist_fail_0_mask                  (0x00000400)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_3_mask                      (0x00000080)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_2_mask                      (0x00000040)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_1_mask                      (0x00000020)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_0_mask                      (0x00000010)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_bist_fail_1_mask                      (0x00000008)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_bist_fail_0_mask                      (0x00000004)
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_3(data)                           (0x80000000&((data)<<31))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_2(data)                           (0x40000000&((data)<<30))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_1(data)                           (0x20000000&((data)<<29))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_rme_0(data)                           (0x10000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmea_1(data)                          (0x08000000&((data)<<27))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmeb_1(data)                          (0x04000000&((data)<<26))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmea_0(data)                          (0x02000000&((data)<<25))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_rmeb_0(data)                          (0x01000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_3(data)                            (0x00800000&((data)<<23))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_2(data)                            (0x00400000&((data)<<22))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_1(data)                            (0x00200000&((data)<<21))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_ls_0(data)                            (0x00100000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_ls_1(data)                            (0x00080000&((data)<<19))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_ls_0(data)                            (0x00040000&((data)<<18))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_3(data)                 (0x00008000&((data)<<15))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_2(data)                 (0x00004000&((data)<<14))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_1(data)                 (0x00002000&((data)<<13))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_drf_bist_fail_0(data)                 (0x00001000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_drf_bist_fail_1(data)                 (0x00000800&((data)<<11))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_drf_bist_fail_0(data)                 (0x00000400&((data)<<10))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_3(data)                     (0x00000080&((data)<<7))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_2(data)                     (0x00000040&((data)<<6))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_1(data)                     (0x00000020&((data)<<5))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_1p_bist_fail_0(data)                     (0x00000010&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_bist_fail_1(data)                     (0x00000008&((data)<<3))
#define  D_2D_TO_3D_D_2D3D_Bist0_render_2p_bist_fail_0(data)                     (0x00000004&((data)<<2))
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_rme_3(data)                       ((0x80000000&(data))>>31)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_rme_2(data)                       ((0x40000000&(data))>>30)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_rme_1(data)                       ((0x20000000&(data))>>29)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_rme_0(data)                       ((0x10000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_rmea_1(data)                      ((0x08000000&(data))>>27)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_rmeb_1(data)                      ((0x04000000&(data))>>26)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_rmea_0(data)                      ((0x02000000&(data))>>25)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_rmeb_0(data)                      ((0x01000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_ls_3(data)                        ((0x00800000&(data))>>23)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_ls_2(data)                        ((0x00400000&(data))>>22)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_ls_1(data)                        ((0x00200000&(data))>>21)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_ls_0(data)                        ((0x00100000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_ls_1(data)                        ((0x00080000&(data))>>19)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_ls_0(data)                        ((0x00040000&(data))>>18)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_drf_bist_fail_3(data)             ((0x00008000&(data))>>15)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_drf_bist_fail_2(data)             ((0x00004000&(data))>>14)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_drf_bist_fail_1(data)             ((0x00002000&(data))>>13)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_drf_bist_fail_0(data)             ((0x00001000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_drf_bist_fail_1(data)             ((0x00000800&(data))>>11)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_drf_bist_fail_0(data)             ((0x00000400&(data))>>10)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_bist_fail_3(data)                 ((0x00000080&(data))>>7)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_bist_fail_2(data)                 ((0x00000040&(data))>>6)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_bist_fail_1(data)                 ((0x00000020&(data))>>5)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_1p_bist_fail_0(data)                 ((0x00000010&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_bist_fail_1(data)                 ((0x00000008&(data))>>3)
#define  D_2D_TO_3D_D_2D3D_Bist0_get_render_2p_bist_fail_0(data)                 ((0x00000004&(data))>>2)

#define  D_2D_TO_3D_D_2D3D_Bist1                                                 0x18029684
#define  D_2D_TO_3D_D_2D3D_Bist1_reg_addr                                        "0xB8029684"
#define  D_2D_TO_3D_D_2D3D_Bist1_reg                                             0xB8029684
#define  D_2D_TO_3D_D_2D3D_Bist1_inst_addr                                       "0x001F"
#define  set_D_2D_TO_3D_D_2D3D_Bist1_reg(data)                                   (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Bist1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Bist1_reg                                         (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Bist1_reg))
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_3_shift                            (28)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_2_shift                            (24)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_1_shift                            (20)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_0_shift                            (16)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rma_1_shift                           (12)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rmb_1_shift                           (8)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rma_0_shift                           (4)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rmb_0_shift                           (0)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_3_mask                             (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_2_mask                             (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_1_mask                             (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_0_mask                             (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rma_1_mask                            (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rmb_1_mask                            (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rma_0_mask                            (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rmb_0_mask                            (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_3(data)                            (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_2(data)                            (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_1(data)                            (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_Bist1_render_1p_rm_0(data)                            (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rma_1(data)                           (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rmb_1(data)                           (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rma_0(data)                           (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_Bist1_render_2p_rmb_0(data)                           (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_Bist1_get_render_1p_rm_3(data)                        ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_Bist1_get_render_1p_rm_2(data)                        ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_Bist1_get_render_1p_rm_1(data)                        ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_Bist1_get_render_1p_rm_0(data)                        ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_Bist1_get_render_2p_rma_1(data)                       ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_Bist1_get_render_2p_rmb_1(data)                       ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_Bist1_get_render_2p_rma_0(data)                       ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_Bist1_get_render_2p_rmb_0(data)                       (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_Bist2                                                 0x18029688
#define  D_2D_TO_3D_D_2D3D_Bist2_reg_addr                                        "0xB8029688"
#define  D_2D_TO_3D_D_2D3D_Bist2_reg                                             0xB8029688
#define  D_2D_TO_3D_D_2D3D_Bist2_inst_addr                                       "0x0020"
#define  set_D_2D_TO_3D_D_2D3D_Bist2_reg(data)                                   (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Bist2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_Bist2_reg                                         (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_Bist2_reg))
#define  D_2D_TO_3D_D_2D3D_Bist2_render_2p_testrwm_1_shift                       (1)
#define  D_2D_TO_3D_D_2D3D_Bist2_render_2p_testrwm_0_shift                       (0)
#define  D_2D_TO_3D_D_2D3D_Bist2_render_2p_testrwm_1_mask                        (0x00000002)
#define  D_2D_TO_3D_D_2D3D_Bist2_render_2p_testrwm_0_mask                        (0x00000001)
#define  D_2D_TO_3D_D_2D3D_Bist2_render_2p_testrwm_1(data)                       (0x00000002&((data)<<1))
#define  D_2D_TO_3D_D_2D3D_Bist2_render_2p_testrwm_0(data)                       (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_Bist2_get_render_2p_testrwm_1(data)                   ((0x00000002&(data))>>1)
#define  D_2D_TO_3D_D_2D3D_Bist2_get_render_2p_testrwm_0(data)                   (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y                                          0x18029690
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg_addr                                 "0xB8029690"
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg                                      0xB8029690
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_inst_addr                                "0x0021"
#define  set_D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg(data)                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg                                  (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_y_lpf_c0_shift             (24)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_y_lpf_c1_shift             (20)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_y_lpf_c2_shift             (16)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_lpf_y_en_shift             (0)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_y_lpf_c0_mask              (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_y_lpf_c1_mask              (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_y_lpf_c2_mask              (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_lpf_y_en_mask              (0x00000001)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_y_lpf_c0(data)             (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_y_lpf_c1(data)             (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_y_lpf_c2(data)             (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_d_2d3d_output_lpf_y_en(data)             (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_get_d_2d3d_output_y_lpf_c0(data)         ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_get_d_2d3d_output_y_lpf_c1(data)         ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_get_d_2d3d_output_y_lpf_c2(data)         ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_get_d_2d3d_output_lpf_y_en(data)         (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C                                          0x18029694
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg_addr                                 "0xB8029694"
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg                                      0xB8029694
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_inst_addr                                "0x0022"
#define  set_D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg(data)                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg                                  (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_c_lpf_c0_shift             (24)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_c_lpf_c1_shift             (20)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_c_lpf_c2_shift             (16)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_lpf_c_en_shift             (0)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_c_lpf_c0_mask              (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_c_lpf_c1_mask              (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_c_lpf_c2_mask              (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_lpf_c_en_mask              (0x00000001)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_c_lpf_c0(data)             (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_c_lpf_c1(data)             (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_c_lpf_c2(data)             (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_d_2d3d_output_lpf_c_en(data)             (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_get_d_2d3d_output_c_lpf_c0(data)         ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_get_d_2d3d_output_c_lpf_c1(data)         ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_get_d_2d3d_output_c_lpf_c2(data)         ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_get_d_2d3d_output_lpf_c_en(data)         (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0                                           0x18029700
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_reg_addr                                  "0xB8029700"
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_reg                                       0xB8029700
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_inst_addr                                 "0x0023"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_CTRL0_reg(data)                             (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_CTRL0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_CTRL0_reg                                   (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_CTRL0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_histo_depth_weight_shift                  (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_h_grid_size_shift                         (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_v_grid_size_shift                         (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_histo_en_shift                            (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_histo_depth_weight_mask                   (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_h_grid_size_mask                          (0x01FF0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_v_grid_size_mask                          (0x00001FF0)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_histo_en_mask                             (0x00000001)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_histo_depth_weight(data)                  (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_h_grid_size(data)                         (0x01FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_v_grid_size(data)                         (0x00001FF0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_histo_en(data)                            (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_get_histo_depth_weight(data)              ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_get_h_grid_size(data)                     ((0x01FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_get_v_grid_size(data)                     ((0x00001FF0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL0_get_histo_en(data)                        (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1                                           0x18029704
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_reg_addr                                  "0xB8029704"
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_reg                                       0xB8029704
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_inst_addr                                 "0x0024"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_CTRL1_reg(data)                             (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_CTRL1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_CTRL1_reg                                   (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_CTRL1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color6_y_act_shift                        (5)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color5_y_act_shift                        (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color4_y_act_shift                        (3)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color3_y_act_shift                        (2)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color2_y_act_shift                        (1)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color1_y_act_shift                        (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color6_y_act_mask                         (0x00000020)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color5_y_act_mask                         (0x00000010)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color4_y_act_mask                         (0x00000008)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color3_y_act_mask                         (0x00000004)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color2_y_act_mask                         (0x00000002)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color1_y_act_mask                         (0x00000001)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color6_y_act(data)                        (0x00000020&((data)<<5))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color5_y_act(data)                        (0x00000010&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color4_y_act(data)                        (0x00000008&((data)<<3))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color3_y_act(data)                        (0x00000004&((data)<<2))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color2_y_act(data)                        (0x00000002&((data)<<1))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_color1_y_act(data)                        (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_get_color6_y_act(data)                    ((0x00000020&(data))>>5)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_get_color5_y_act(data)                    ((0x00000010&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_get_color4_y_act(data)                    ((0x00000008&(data))>>3)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_get_color3_y_act(data)                    ((0x00000004&(data))>>2)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_get_color2_y_act(data)                    ((0x00000002&(data))>>1)
#define  D_2D_TO_3D_D_2D3D_HISTO_CTRL1_get_color1_y_act(data)                    (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0                               0x18029710
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_reg_addr                      "0xB8029710"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_reg                           0xB8029710
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_inst_addr                     "0x0025"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_reg(data)                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_reg                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up7_shift          (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up6_shift          (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up5_shift          (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up4_shift          (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up3_shift          (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up2_shift          (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up1_shift          (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up0_shift          (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up7_mask           (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up6_mask           (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up5_mask           (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up4_mask           (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up3_mask           (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up2_mask           (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up1_mask           (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up0_mask           (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up7(data)          (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up6(data)          (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up5(data)          (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up4(data)          (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up3(data)          (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up2(data)          (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up1(data)          (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_weight_dis_up0(data)          (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_get_weight_dis_up7(data)      ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_get_weight_dis_up6(data)      ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_get_weight_dis_up5(data)      ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_get_weight_dis_up4(data)      ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_get_weight_dis_up3(data)      ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_get_weight_dis_up2(data)      ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_get_weight_dis_up1(data)      ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_0_get_weight_dis_up0(data)      (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1                               0x18029714
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_reg_addr                      "0xB8029714"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_reg                           0xB8029714
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_inst_addr                     "0x0026"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_reg(data)                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_reg                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up15_shift         (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up14_shift         (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up13_shift         (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up12_shift         (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up11_shift         (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up10_shift         (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up9_shift          (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up8_shift          (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up15_mask          (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up14_mask          (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up13_mask          (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up12_mask          (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up11_mask          (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up10_mask          (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up9_mask           (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up8_mask           (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up15(data)         (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up14(data)         (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up13(data)         (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up12(data)         (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up11(data)         (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up10(data)         (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up9(data)          (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_weight_dis_up8(data)          (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_get_weight_dis_up15(data)     ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_get_weight_dis_up14(data)     ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_get_weight_dis_up13(data)     ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_get_weight_dis_up12(data)     ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_get_weight_dis_up11(data)     ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_get_weight_dis_up10(data)     ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_get_weight_dis_up9(data)      ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_1_get_weight_dis_up8(data)      (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2                               0x18029718
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_reg_addr                      "0xB8029718"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_reg                           0xB8029718
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_inst_addr                     "0x0027"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_reg(data)                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_reg                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr7_shift          (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr6_shift          (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr5_shift          (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr4_shift          (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr3_shift          (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr2_shift          (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr1_shift          (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr0_shift          (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr7_mask           (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr6_mask           (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr5_mask           (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr4_mask           (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr3_mask           (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr2_mask           (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr1_mask           (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr0_mask           (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr7(data)          (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr6(data)          (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr5(data)          (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr4(data)          (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr3(data)          (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr2(data)          (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr1(data)          (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_weight_dis_lr0(data)          (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_get_weight_dis_lr7(data)      ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_get_weight_dis_lr6(data)      ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_get_weight_dis_lr5(data)      ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_get_weight_dis_lr4(data)      ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_get_weight_dis_lr3(data)      ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_get_weight_dis_lr2(data)      ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_get_weight_dis_lr1(data)      ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_2_get_weight_dis_lr0(data)      (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3                               0x1802971C
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_reg_addr                      "0xB802971C"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_reg                           0xB802971C
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_inst_addr                     "0x0028"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_reg(data)                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_reg                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr15_shift         (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr14_shift         (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr13_shift         (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr12_shift         (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr11_shift         (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr10_shift         (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr9_shift          (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr8_shift          (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr15_mask          (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr14_mask          (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr13_mask          (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr12_mask          (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr11_mask          (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr10_mask          (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr9_mask           (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr8_mask           (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr15(data)         (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr14(data)         (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr13(data)         (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr12(data)         (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr11(data)         (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr10(data)         (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr9(data)          (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_weight_dis_lr8(data)          (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_get_weight_dis_lr15(data)     ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_get_weight_dis_lr14(data)     ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_get_weight_dis_lr13(data)     ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_get_weight_dis_lr12(data)     ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_get_weight_dis_lr11(data)     ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_get_weight_dis_lr10(data)     ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_get_weight_dis_lr9(data)      ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_3_get_weight_dis_lr8(data)      (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4                               0x18029720
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_reg_addr                      "0xB8029720"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_reg                           0xB8029720
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_inst_addr                     "0x0029"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_reg(data)                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_reg                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr23_shift         (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr22_shift         (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr21_shift         (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr20_shift         (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr19_shift         (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr18_shift         (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr17_shift         (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr16_shift         (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr23_mask          (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr22_mask          (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr21_mask          (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr20_mask          (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr19_mask          (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr18_mask          (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr17_mask          (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr16_mask          (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr23(data)         (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr22(data)         (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr21(data)         (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr20(data)         (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr19(data)         (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr18(data)         (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr17(data)         (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_weight_dis_lr16(data)         (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_get_weight_dis_lr23(data)     ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_get_weight_dis_lr22(data)     ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_get_weight_dis_lr21(data)     ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_get_weight_dis_lr20(data)     ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_get_weight_dis_lr19(data)     ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_get_weight_dis_lr18(data)     ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_get_weight_dis_lr17(data)     ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_4_get_weight_dis_lr16(data)     (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5                               0x18029724
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_reg_addr                      "0xB8029724"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_reg                           0xB8029724
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_inst_addr                     "0x002A"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_reg(data)                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_reg                       (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr31_shift         (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr30_shift         (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr29_shift         (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr28_shift         (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr27_shift         (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr26_shift         (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr25_shift         (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr24_shift         (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr31_mask          (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr30_mask          (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr29_mask          (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr28_mask          (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr27_mask          (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr26_mask          (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr25_mask          (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr24_mask          (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr31(data)         (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr30(data)         (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr29(data)         (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr28(data)         (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr27(data)         (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr26(data)         (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr25(data)         (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_weight_dis_lr24(data)         (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_get_weight_dis_lr31(data)     ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_get_weight_dis_lr30(data)     ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_get_weight_dis_lr29(data)     ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_get_weight_dis_lr28(data)     ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_get_weight_dis_lr27(data)     ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_get_weight_dis_lr26(data)     ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_get_weight_dis_lr25(data)     ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_DISPREAD_5_get_weight_dis_lr24(data)     (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0                                    0x18029730
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_reg_addr                           "0xB8029730"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_reg                                0xB8029730
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_inst_addr                          "0x002B"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_7_shift                 (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_6_shift                 (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_5_shift                 (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_4_shift                 (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_3_shift                 (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_2_shift                 (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_1_shift                 (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_0_shift                 (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_7_mask                  (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_6_mask                  (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_5_mask                  (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_4_mask                  (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_3_mask                  (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_2_mask                  (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_1_mask                  (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_0_mask                  (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_7(data)                 (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_6(data)                 (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_5(data)                 (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_4(data)                 (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_3(data)                 (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_2(data)                 (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_1(data)                 (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_weight_up2_0(data)                 (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_get_weight_up2_7(data)             ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_get_weight_up2_6(data)             ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_get_weight_up2_5(data)             ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_get_weight_up2_4(data)             ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_get_weight_up2_3(data)             ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_get_weight_up2_2(data)             ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_get_weight_up2_1(data)             ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_0_get_weight_up2_0(data)             (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1                                    0x18029734
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_reg_addr                           "0xB8029734"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_reg                                0xB8029734
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_inst_addr                          "0x002C"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_15_shift                (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_14_shift                (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_13_shift                (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_12_shift                (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_11_shift                (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_10_shift                (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_9_shift                 (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_8_shift                 (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_15_mask                 (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_14_mask                 (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_13_mask                 (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_12_mask                 (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_11_mask                 (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_10_mask                 (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_9_mask                  (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_8_mask                  (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_15(data)                (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_14(data)                (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_13(data)                (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_12(data)                (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_11(data)                (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_10(data)                (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_9(data)                 (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_weight_up2_8(data)                 (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_get_weight_up2_15(data)            ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_get_weight_up2_14(data)            ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_get_weight_up2_13(data)            ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_get_weight_up2_12(data)            ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_get_weight_up2_11(data)            ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_get_weight_up2_10(data)            ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_get_weight_up2_9(data)             ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP2_1_get_weight_up2_8(data)             (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0                                    0x18029738
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_reg_addr                           "0xB8029738"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_reg                                0xB8029738
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_inst_addr                          "0x002D"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_7_shift                 (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_6_shift                 (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_5_shift                 (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_4_shift                 (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_3_shift                 (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_2_shift                 (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_1_shift                 (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_0_shift                 (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_7_mask                  (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_6_mask                  (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_5_mask                  (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_4_mask                  (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_3_mask                  (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_2_mask                  (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_1_mask                  (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_0_mask                  (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_7(data)                 (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_6(data)                 (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_5(data)                 (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_4(data)                 (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_3(data)                 (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_2(data)                 (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_1(data)                 (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_weight_up3_0(data)                 (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_get_weight_up3_7(data)             ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_get_weight_up3_6(data)             ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_get_weight_up3_5(data)             ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_get_weight_up3_4(data)             ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_get_weight_up3_3(data)             ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_get_weight_up3_2(data)             ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_get_weight_up3_1(data)             ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_0_get_weight_up3_0(data)             (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1                                    0x1802973C
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_reg_addr                           "0xB802973C"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_reg                                0xB802973C
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_inst_addr                          "0x002E"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_15_shift                (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_14_shift                (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_13_shift                (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_12_shift                (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_11_shift                (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_10_shift                (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_9_shift                 (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_8_shift                 (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_15_mask                 (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_14_mask                 (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_13_mask                 (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_12_mask                 (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_11_mask                 (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_10_mask                 (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_9_mask                  (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_8_mask                  (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_15(data)                (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_14(data)                (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_13(data)                (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_12(data)                (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_11(data)                (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_10(data)                (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_9(data)                 (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_weight_up3_8(data)                 (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_get_weight_up3_15(data)            ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_get_weight_up3_14(data)            ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_get_weight_up3_13(data)            ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_get_weight_up3_12(data)            ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_get_weight_up3_11(data)            ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_get_weight_up3_10(data)            ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_get_weight_up3_9(data)             ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP3_1_get_weight_up3_8(data)             (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4                                         0x18029740
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_reg_addr                                "0xB8029740"
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_reg                                     0xB8029740
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_inst_addr                               "0x002F"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_reg(data)                           (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_reg                                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_weight_01_on_color4_shift               (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_v1_shift                         (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_u1_shift                         (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_y1_shift                         (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_v0_shift                         (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_u0_shift                         (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_y0_shift                         (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_weight_01_on_color4_mask                (0x07000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_v1_mask                          (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_u1_mask                          (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_y1_mask                          (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_v0_mask                          (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_u0_mask                          (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_y0_mask                          (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_weight_01_on_color4(data)               (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_v1(data)                         (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_u1(data)                         (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_y1(data)                         (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_v0(data)                         (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_u0(data)                         (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_color4_y0(data)                         (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_get_weight_01_on_color4(data)           ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_get_color4_v1(data)                     ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_get_color4_u1(data)                     ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_get_color4_y1(data)                     ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_get_color4_v0(data)                     ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_get_color4_u0(data)                     ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_4_get_color4_y0(data)                     (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0                                    0x18029744
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_reg_addr                           "0xB8029744"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_reg                                0xB8029744
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_inst_addr                          "0x0030"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_7_shift                 (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_6_shift                 (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_5_shift                 (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_4_shift                 (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_3_shift                 (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_2_shift                 (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_1_shift                 (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_0_shift                 (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_7_mask                  (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_6_mask                  (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_5_mask                  (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_4_mask                  (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_3_mask                  (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_2_mask                  (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_1_mask                  (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_0_mask                  (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_7(data)                 (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_6(data)                 (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_5(data)                 (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_4(data)                 (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_3(data)                 (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_2(data)                 (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_1(data)                 (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_weight_up4_0(data)                 (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_get_weight_up4_7(data)             ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_get_weight_up4_6(data)             ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_get_weight_up4_5(data)             ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_get_weight_up4_4(data)             ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_get_weight_up4_3(data)             ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_get_weight_up4_2(data)             ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_get_weight_up4_1(data)             ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_0_get_weight_up4_0(data)             (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1                                    0x18029748
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_reg_addr                           "0xB8029748"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_reg                                0xB8029748
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_inst_addr                          "0x0031"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_15_shift                (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_14_shift                (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_13_shift                (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_12_shift                (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_11_shift                (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_10_shift                (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_9_shift                 (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_8_shift                 (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_15_mask                 (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_14_mask                 (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_13_mask                 (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_12_mask                 (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_11_mask                 (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_10_mask                 (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_9_mask                  (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_8_mask                  (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_15(data)                (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_14(data)                (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_13(data)                (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_12(data)                (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_11(data)                (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_10(data)                (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_9(data)                 (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_weight_up4_8(data)                 (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_get_weight_up4_15(data)            ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_get_weight_up4_14(data)            ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_get_weight_up4_13(data)            ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_get_weight_up4_12(data)            ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_get_weight_up4_11(data)            ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_get_weight_up4_10(data)            ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_get_weight_up4_9(data)             ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP4_1_get_weight_up4_8(data)             (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5                                         0x1802974C
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_reg_addr                                "0xB802974C"
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_reg                                     0xB802974C
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_inst_addr                               "0x0032"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_reg(data)                           (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_reg                                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_color5_v_shift                          (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_color5_u_shift                          (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_color5_y_shift                          (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_color5_v_mask                           (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_color5_u_mask                           (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_color5_y_mask                           (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_color5_v(data)                          (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_color5_u(data)                          (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_color5_y(data)                          (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_get_color5_v(data)                      ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_get_color5_u(data)                      ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_5_get_color5_y(data)                      (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0                                    0x18029750
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_reg_addr                           "0xB8029750"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_reg                                0xB8029750
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_inst_addr                          "0x0033"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_7_shift                 (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_6_shift                 (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_5_shift                 (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_4_shift                 (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_3_shift                 (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_2_shift                 (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_1_shift                 (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_0_shift                 (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_7_mask                  (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_6_mask                  (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_5_mask                  (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_4_mask                  (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_3_mask                  (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_2_mask                  (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_1_mask                  (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_0_mask                  (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_7(data)                 (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_6(data)                 (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_5(data)                 (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_4(data)                 (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_3(data)                 (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_2(data)                 (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_1(data)                 (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_weight_up5_0(data)                 (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_get_weight_up5_7(data)             ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_get_weight_up5_6(data)             ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_get_weight_up5_5(data)             ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_get_weight_up5_4(data)             ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_get_weight_up5_3(data)             ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_get_weight_up5_2(data)             ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_get_weight_up5_1(data)             ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_0_get_weight_up5_0(data)             (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1                                    0x18029754
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_reg_addr                           "0xB8029754"
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_reg                                0xB8029754
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_inst_addr                          "0x0034"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_15_shift                (28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_14_shift                (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_13_shift                (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_12_shift                (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_11_shift                (12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_10_shift                (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_9_shift                 (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_8_shift                 (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_15_mask                 (0xF0000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_14_mask                 (0x0F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_13_mask                 (0x00F00000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_12_mask                 (0x000F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_11_mask                 (0x0000F000)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_10_mask                 (0x00000F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_9_mask                  (0x000000F0)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_8_mask                  (0x0000000F)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_15(data)                (0xF0000000&((data)<<28))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_14(data)                (0x0F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_13(data)                (0x00F00000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_12(data)                (0x000F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_11(data)                (0x0000F000&((data)<<12))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_10(data)                (0x00000F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_9(data)                 (0x000000F0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_weight_up5_8(data)                 (0x0000000F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_get_weight_up5_15(data)            ((0xF0000000&(data))>>28)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_get_weight_up5_14(data)            ((0x0F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_get_weight_up5_13(data)            ((0x00F00000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_get_weight_up5_12(data)            ((0x000F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_get_weight_up5_11(data)            ((0x0000F000&(data))>>12)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_get_weight_up5_10(data)            ((0x00000F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_get_weight_up5_9(data)             ((0x000000F0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_WEIGHT_UP5_1_get_weight_up5_8(data)             (0x0000000F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6                                         0x18029758
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_reg_addr                                "0xB8029758"
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_reg                                     0xB8029758
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_inst_addr                               "0x0035"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_reg(data)                           (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_reg                                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_color6_v_shift                          (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_color6_u_shift                          (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_color6_y_shift                          (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_color6_v_mask                           (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_color6_u_mask                           (0x0000FF00)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_color6_y_mask                           (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_color6_v(data)                          (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_color6_u(data)                          (0x0000FF00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_color6_y(data)                          (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_get_color6_v(data)                      ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_get_color6_u(data)                      ((0x0000FF00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_COLOR_6_get_color6_y(data)                      (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0                                  0x1802975C
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_reg_addr                         "0xB802975C"
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_reg                              0xB802975C
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_inst_addr                        "0x0036"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_reg(data)                    (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_reg                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_4_shift             (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_3_shift             (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_2_shift             (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_1_shift             (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_4_mask              (0x3F000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_3_mask              (0x003F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_2_mask              (0x00003F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_1_mask              (0x0000003F)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_4(data)             (0x3F000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_3(data)             (0x003F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_2(data)             (0x00003F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_depth_weight_1(data)             (0x0000003F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_get_depth_weight_4(data)         ((0x3F000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_get_depth_weight_3(data)         ((0x003F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_get_depth_weight_2(data)         ((0x00003F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_0_get_depth_weight_1(data)         (0x0000003F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1                                  0x18029760
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_reg_addr                         "0xB8029760"
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_reg                              0xB8029760
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_inst_addr                        "0x0037"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_reg(data)                    (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_reg                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_depth_weight_6_shift             (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_depth_weight_5_shift             (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_depth_weight_6_mask              (0x00003F00)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_depth_weight_5_mask              (0x0000003F)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_depth_weight_6(data)             (0x00003F00&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_depth_weight_5(data)             (0x0000003F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_get_depth_weight_6(data)         ((0x00003F00&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DEPTH_WEIGHT_1_get_depth_weight_5(data)         (0x0000003F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0                                    0x18029770
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_reg_addr                           "0xB8029770"
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_reg                                0xB8029770
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_inst_addr                          "0x0038"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_slope_2_shift                      (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_margin_2_shift                     (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_slope_1_shift                      (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_margin_1_shift                     (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_slope_2_mask                       (0x07000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_margin_2_mask                      (0x007F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_slope_1_mask                       (0x00000700)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_margin_1_mask                      (0x0000007F)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_slope_2(data)                      (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_margin_2(data)                     (0x007F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_slope_1(data)                      (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_margin_1(data)                     (0x0000007F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_get_slope_2(data)                  ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_get_margin_2(data)                 ((0x007F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_get_slope_1(data)                  ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_0_get_margin_1(data)                 (0x0000007F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1                                    0x18029774
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_reg_addr                           "0xB8029774"
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_reg                                0xB8029774
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_inst_addr                          "0x0039"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_slope_4_shift                      (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_margin_4_shift                     (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_slope_3_shift                      (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_margin_3_shift                     (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_slope_4_mask                       (0x07000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_margin_4_mask                      (0x007F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_slope_3_mask                       (0x00000700)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_margin_3_mask                      (0x0000007F)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_slope_4(data)                      (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_margin_4(data)                     (0x007F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_slope_3(data)                      (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_margin_3(data)                     (0x0000007F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_get_slope_4(data)                  ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_get_margin_4(data)                 ((0x007F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_get_slope_3(data)                  ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_1_get_margin_3(data)                 (0x0000007F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2                                    0x18029778
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_reg_addr                           "0xB8029778"
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_reg                                0xB8029778
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_inst_addr                          "0x003A"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_reg(data)                      (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_reg                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_slope_6_shift                      (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_margin_6_shift                     (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_slope_5_shift                      (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_margin_5_shift                     (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_slope_6_mask                       (0x07000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_margin_6_mask                      (0x007F0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_slope_5_mask                       (0x00000700)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_margin_5_mask                      (0x0000007F)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_slope_6(data)                      (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_margin_6(data)                     (0x007F0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_slope_5(data)                      (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_margin_5(data)                     (0x0000007F&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_get_slope_6(data)                  ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_get_margin_6(data)                 ((0x007F0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_get_slope_5(data)                  ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_DIFF_DEPTH_2_get_margin_5(data)                 (0x0000007F&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0                                          0x18029780
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_reg_addr                                 "0xB8029780"
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_reg                                      0xB8029780
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_inst_addr                                "0x003B"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_reg(data)                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_reg                                  (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_2_th_s_shift                    (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_2_th_l_shift                    (20)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_2_en_shift                      (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_1_th_s_shift                    (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_1_th_l_shift                    (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_1_en_shift                      (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_2_th_s_mask                     (0x07000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_2_th_l_mask                     (0x00700000)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_2_en_mask                       (0x00010000)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_1_th_s_mask                     (0x00000700)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_1_th_l_mask                     (0x00000070)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_1_en_mask                       (0x00000001)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_2_th_s(data)                    (0x07000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_2_th_l(data)                    (0x00700000&((data)<<20))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_2_en(data)                      (0x00010000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_1_th_s(data)                    (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_1_th_l(data)                    (0x00000070&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_temporal_1_en(data)                      (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_get_temporal_2_th_s(data)                ((0x07000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_get_temporal_2_th_l(data)                ((0x00700000&(data))>>20)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_get_temporal_2_en(data)                  ((0x00010000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_get_temporal_1_th_s(data)                ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_get_temporal_1_th_l(data)                ((0x00000070&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_get_temporal_1_en(data)                  (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1                                          0x18029784
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_reg_addr                                 "0xB8029784"
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_reg                                      0xB8029784
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_inst_addr                                "0x003C"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_reg(data)                            (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_reg                                  (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_temporal_3_th_s_shift                    (8)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_temporal_3_th_l_shift                    (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_temporal_3_en_shift                      (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_temporal_3_th_s_mask                     (0x00000700)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_temporal_3_th_l_mask                     (0x00000070)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_temporal_3_en_mask                       (0x00000001)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_temporal_3_th_s(data)                    (0x00000700&((data)<<8))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_temporal_3_th_l(data)                    (0x00000070&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_temporal_3_en(data)                      (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_get_temporal_3_th_s(data)                ((0x00000700&(data))>>8)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_get_temporal_3_th_l(data)                ((0x00000070&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_get_temporal_3_en(data)                  (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0                                        0x180297B0
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_reg_addr                               "0xB80297B0"
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_reg                                    0xB80297B0
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_inst_addr                              "0x003D"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_su_en_shift                            (31)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_su_hfactor_shift                       (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_su_en_mask                             (0x80000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_su_hfactor_mask                        (0x000FFFFF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_su_en(data)                            (0x80000000&((data)<<31))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_su_hfactor(data)                       (0x000FFFFF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_get_su_en(data)                        ((0x80000000&(data))>>31)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_get_su_hfactor(data)                   (0x000FFFFF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2                                        0x180297B4
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_reg_addr                               "0xB80297B4"
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_reg                                    0xB80297B4
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_inst_addr                              "0x003E"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_su_vfactor_shift                       (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_su_vfactor_mask                        (0x000FFFFF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_su_vfactor(data)                       (0x000FFFFF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_get_su_vfactor(data)                   (0x000FFFFF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0                                        0x180297B8
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_reg_addr                               "0xB80297B8"
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_reg                                    0xB80297B8
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_inst_addr                              "0x003F"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_su_scaleup_htab_coef0_shift            (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_su_scaleup_htab_coef1_shift            (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_su_scaleup_htab_coef0_mask             (0x03FF0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_su_scaleup_htab_coef1_mask             (0x000003FF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_su_scaleup_htab_coef0(data)            (0x03FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_su_scaleup_htab_coef1(data)            (0x000003FF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_get_su_scaleup_htab_coef0(data)        ((0x03FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF0_get_su_scaleup_htab_coef1(data)        (0x000003FF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1                                        0x180297BC
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_reg_addr                               "0xB80297BC"
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_reg                                    0xB80297BC
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_inst_addr                              "0x0040"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_su_scaleup_htab_coef3_shift            (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_su_scaleup_htab_coef2_shift            (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_su_scaleup_htab_coef3_mask             (0x03FF0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_su_scaleup_htab_coef2_mask             (0x000003FF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_su_scaleup_htab_coef3(data)            (0x03FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_su_scaleup_htab_coef2(data)            (0x000003FF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_get_su_scaleup_htab_coef3(data)        ((0x03FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF1_get_su_scaleup_htab_coef2(data)        (0x000003FF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2                                        0x180297C0
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_reg_addr                               "0xB80297C0"
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_reg                                    0xB80297C0
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_inst_addr                              "0x0041"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_su_scaleup_htab_coef4_shift            (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_su_scaleup_htab_coef4_mask             (0x000003FF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_su_scaleup_htab_coef4(data)            (0x000003FF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF2_get_su_scaleup_htab_coef4(data)        (0x000003FF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3                                        0x180297C4
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_reg_addr                               "0xB80297C4"
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_reg                                    0xB80297C4
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_inst_addr                              "0x0042"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_su_scaleup_vtab_coef0_shift            (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_su_scaleup_vtab_coef1_shift            (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_su_scaleup_vtab_coef0_mask             (0x03FF0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_su_scaleup_vtab_coef1_mask             (0x000003FF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_su_scaleup_vtab_coef0(data)            (0x03FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_su_scaleup_vtab_coef1(data)            (0x000003FF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_get_su_scaleup_vtab_coef0(data)        ((0x03FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF3_get_su_scaleup_vtab_coef1(data)        (0x000003FF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4                                        0x180297C8
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_reg_addr                               "0xB80297C8"
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_reg                                    0xB80297C8
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_inst_addr                              "0x0043"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_su_scaleup_vtab_coef3_shift            (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_su_scaleup_vtab_coef2_shift            (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_su_scaleup_vtab_coef3_mask             (0x03FF0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_su_scaleup_vtab_coef2_mask             (0x000003FF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_su_scaleup_vtab_coef3(data)            (0x03FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_su_scaleup_vtab_coef2(data)            (0x000003FF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_get_su_scaleup_vtab_coef3(data)        ((0x03FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF4_get_su_scaleup_vtab_coef2(data)        (0x000003FF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5                                        0x180297CC
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_reg_addr                               "0xB80297CC"
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_reg                                    0xB80297CC
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_inst_addr                              "0x0044"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_reg(data)                          (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_reg                                (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_su_scaleup_vtab_coef4_shift            (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_su_scaleup_vtab_coef4_mask             (0x000003FF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_su_scaleup_vtab_coef4(data)            (0x000003FF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SU_COEF5_get_su_scaleup_vtab_coef4(data)        (0x000003FF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL                                       0x180297D0
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_reg_addr                              "0xB80297D0"
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_reg                                   0xB80297D0
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_inst_addr                             "0x0045"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_reg(data)                         (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_reg                               (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_depth_update_en_shift                 (1)
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_depth_sw_mode_shift                   (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_depth_update_en_mask                  (0x00000002)
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_depth_sw_mode_mask                    (0x00000001)
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_depth_update_en(data)                 (0x00000002&((data)<<1))
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_depth_sw_mode(data)                   (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_get_depth_update_en(data)             ((0x00000002&(data))>>1)
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_CTRL_get_depth_sw_mode(data)               (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP                                         0x180297D4
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_reg_addr                                "0xB80297D4"
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_reg                                     0xB80297D4
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_inst_addr                               "0x0046"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_reg(data)                           (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_reg                                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_depth_adr_shift                         (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_depth_adr_mask                          (0x000001FF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_depth_adr(data)                         (0x000001FF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_AP_get_depth_adr(data)                     (0x000001FF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP                                         0x180297D8
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_reg_addr                                "0xB80297D8"
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_reg                                     0xB80297D8
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_inst_addr                               "0x0047"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_reg(data)                           (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_reg                                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_depth_dat_shift                         (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_depth_dat_mask                          (0x000000FF)
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_depth_dat(data)                         (0x000000FF&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_SRAM_DP_get_depth_dat(data)                     (0x000000FF&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN                                         0x180297F0
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_reg_addr                                "0xB80297F0"
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_reg                                     0xB80297F0
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_inst_addr                               "0x0048"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_reg(data)                           (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_reg                                 (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_depth_max_shift                         (24)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_depth_min_shift                         (16)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_max_min_mux_shift                       (1)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_max_min_en_shift                        (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_depth_max_mask                          (0xFF000000)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_depth_min_mask                          (0x00FF0000)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_max_min_mux_mask                        (0x00000006)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_max_min_en_mask                         (0x00000001)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_depth_max(data)                         (0xFF000000&((data)<<24))
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_depth_min(data)                         (0x00FF0000&((data)<<16))
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_max_min_mux(data)                       (0x00000006&((data)<<1))
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_max_min_en(data)                        (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_get_depth_max(data)                     ((0xFF000000&(data))>>24)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_get_depth_min(data)                     ((0x00FF0000&(data))>>16)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_get_max_min_mux(data)                   ((0x00000006&(data))>>1)
#define  D_2D_TO_3D_D_2D3D_HISTO_MAX_MIN_get_max_min_en(data)                    (0x00000001&(data))

#define  D_2D_TO_3D_D_2D3D_HISTO_IIR                                             0x180297F4
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_reg_addr                                    "0xB80297F4"
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_reg                                         0xB80297F4
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_inst_addr                                   "0x0049"
#define  set_D_2D_TO_3D_D_2D3D_HISTO_IIR_reg(data)                               (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_IIR_reg)=data)
#define  get_D_2D_TO_3D_D_2D3D_HISTO_IIR_reg                                     (*((volatile unsigned int*)D_2D_TO_3D_D_2D3D_HISTO_IIR_reg))
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_iir_weight_shift                            (4)
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_iir_en_shift                                (0)
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_iir_weight_mask                             (0x00000FF0)
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_iir_en_mask                                 (0x00000001)
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_iir_weight(data)                            (0x00000FF0&((data)<<4))
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_iir_en(data)                                (0x00000001&(data))
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_get_iir_weight(data)                        ((0x00000FF0&(data))>>4)
#define  D_2D_TO_3D_D_2D3D_HISTO_IIR_get_iir_en(data)                            (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======D_2D_TO_3D register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  res1:29;
    };
}d_2d_to_3d_d_2d3d_db_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  object6_depth_en:1;
        RBus_UInt32  object5_depth_en:1;
        RBus_UInt32  object4_depth_en:1;
        RBus_UInt32  depth_src_mux:1;
        RBus_UInt32  render_method:1;
        RBus_UInt32  input_sbs_render_mode:1;
        RBus_UInt32  obj_y_src_sel:1;
        RBus_UInt32  output_format:1;
        RBus_UInt32  d_2d3d_depth_frac_en:1;
        RBus_UInt32  depth_debug_mode:1;
        RBus_UInt32  l_frame_shift_en:1;
        RBus_UInt32  r_frame_shift_en:1;
        RBus_UInt32  l_flag_inv:1;
        RBus_UInt32  tilt_depth_en:1;
        RBus_UInt32  object3_depth_en:1;
        RBus_UInt32  object2_depth_en:1;
        RBus_UInt32  object1_depth_en:1;
        RBus_UInt32  res2:1;
    };
}d_2d_to_3d_d_2d3d_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  object1_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  object1_offset:9;
        RBus_UInt32  object1_gain:8;
    };
}d_2d_to_3d_d_2d3d_object1_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  object2_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  object2_offset:9;
        RBus_UInt32  object2_gain:8;
    };
}d_2d_to_3d_d_2d3d_object2_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  object3_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  object3_offset:9;
        RBus_UInt32  object3_gain:8;
    };
}d_2d_to_3d_d_2d3d_object3_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  object4_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  object4_offset:9;
        RBus_UInt32  object4_gain:8;
    };
}d_2d_to_3d_d_2d3d_object4_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  object5_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  object5_offset:9;
        RBus_UInt32  object5_gain:8;
    };
}d_2d_to_3d_d_2d3d_object5_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  object6_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  object6_offset:9;
        RBus_UInt32  object6_gain:8;
    };
}d_2d_to_3d_d_2d3d_object6_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tilt_thd:8;
        RBus_UInt32  tilt_offset:8;
        RBus_UInt32  tilt_gain:8;
    };
}d_2d_to_3d_d_2d3d_tilt_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  histo_thd:8;
        RBus_UInt32  histo_offset:8;
        RBus_UInt32  histo_gain:8;
    };
}d_2d_to_3d_d_2d3d_histo_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  border_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  border_den_start:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  border_den_end:13;
    };
}d_2d_to_3d_d_2d3d_b_border_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tilt_depth_step:12;
        RBus_UInt32  res2:8;
        RBus_UInt32  initial_depth:8;
    };
}d_2d_to_3d_d_2d3d_tilt_depth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object1_depth_weight1:3;
        RBus_UInt32  object1_depth_ref1:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  object1_depth_dir:1;
    };
}d_2d_to_3d_d_2d3d_object1_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object1_depth_weight3:3;
        RBus_UInt32  object1_depth_ref3:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  object1_depth_weight2:3;
        RBus_UInt32  object1_depth_ref2:8;
    };
}d_2d_to_3d_d_2d3d_object1_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object2_depth_weight1:3;
        RBus_UInt32  object2_depth_ref1:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  object2_depth_dir:1;
    };
}d_2d_to_3d_d_2d3d_object2_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object2_depth_weight3:3;
        RBus_UInt32  object2_depth_ref3:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  object2_depth_weight2:3;
        RBus_UInt32  object2_depth_ref2:8;
    };
}d_2d_to_3d_d_2d3d_object2_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object3_depth_weight1:3;
        RBus_UInt32  object3_depth_ref1:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  object3_depth_dir:1;
    };
}d_2d_to_3d_d_2d3d_object3_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object3_depth_weight3:3;
        RBus_UInt32  object3_depth_ref3:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  object3_depth_weight2:3;
        RBus_UInt32  object3_depth_ref2:8;
    };
}d_2d_to_3d_d_2d3d_object3_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object4_depth_weight1:3;
        RBus_UInt32  object4_depth_ref1:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  object4_depth_dir:1;
    };
}d_2d_to_3d_d_2d3d_object4_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object4_depth_weight3:3;
        RBus_UInt32  object4_depth_ref3:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  object4_depth_weight2:3;
        RBus_UInt32  object4_depth_ref2:8;
    };
}d_2d_to_3d_d_2d3d_object4_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object5_depth_weight1:3;
        RBus_UInt32  object5_depth_ref1:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  object5_depth_dir:1;
    };
}d_2d_to_3d_d_2d3d_object5_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object5_depth_weight3:3;
        RBus_UInt32  object5_depth_ref3:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  object5_depth_weight2:3;
        RBus_UInt32  object5_depth_ref2:8;
    };
}d_2d_to_3d_d_2d3d_object5_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object6_depth_weight1:3;
        RBus_UInt32  object6_depth_ref1:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  object6_depth_dir:1;
    };
}d_2d_to_3d_d_2d3d_object6_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object6_depth_weight3:3;
        RBus_UInt32  object6_depth_ref3:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  object6_depth_weight2:3;
        RBus_UInt32  object6_depth_ref2:8;
    };
}d_2d_to_3d_d_2d3d_object6_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  d_2d3d_depth_lpf_c0:4;
        RBus_UInt32  d_2d3d_depth_lpf_c1:4;
        RBus_UInt32  d_2d3d_depth_lpf_c2:4;
        RBus_UInt32  res2:11;
        RBus_UInt32  d_2d3d_depth_lpf_en:1;
    };
}d_2d_to_3d_d_2d3d_depth_fil_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shifter_offset2:10;
        RBus_UInt32  shifter_thd:6;
        RBus_UInt32  shifter_offset:8;
        RBus_UInt32  shifter_gain:8;
    };
}d_2d_to_3d_d_2d3d_shifter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dbs_seg_num:2;
        RBus_UInt32  dbs_en:1;
    };
}d_2d_to_3d_d_2d3d_boundary_scaling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  hf_new_en:1;
        RBus_UInt32  hole_fil_sel:3;
    };
}d_2d_to_3d_d_2d3d_hole_fill_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029674_31_0:32;
    };
}d_2d_to_3d_d_2d3d_dummy0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029678_31_0:32;
    };
}d_2d_to_3d_d_2d3d_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  render_1p_rme_3:1;
        RBus_UInt32  render_1p_rme_2:1;
        RBus_UInt32  render_1p_rme_1:1;
        RBus_UInt32  render_1p_rme_0:1;
        RBus_UInt32  render_2p_rmea_1:1;
        RBus_UInt32  render_2p_rmeb_1:1;
        RBus_UInt32  render_2p_rmea_0:1;
        RBus_UInt32  render_2p_rmeb_0:1;
        RBus_UInt32  render_1p_ls_3:1;
        RBus_UInt32  render_1p_ls_2:1;
        RBus_UInt32  render_1p_ls_1:1;
        RBus_UInt32  render_1p_ls_0:1;
        RBus_UInt32  render_2p_ls_1:1;
        RBus_UInt32  render_2p_ls_0:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  render_1p_drf_bist_fail_3:1;
        RBus_UInt32  render_1p_drf_bist_fail_2:1;
        RBus_UInt32  render_1p_drf_bist_fail_1:1;
        RBus_UInt32  render_1p_drf_bist_fail_0:1;
        RBus_UInt32  render_2p_drf_bist_fail_1:1;
        RBus_UInt32  render_2p_drf_bist_fail_0:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  render_1p_bist_fail_3:1;
        RBus_UInt32  render_1p_bist_fail_2:1;
        RBus_UInt32  render_1p_bist_fail_1:1;
        RBus_UInt32  render_1p_bist_fail_0:1;
        RBus_UInt32  render_2p_bist_fail_1:1;
        RBus_UInt32  render_2p_bist_fail_0:1;
        RBus_UInt32  res3:2;
    };
}d_2d_to_3d_d_2d3d_bist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  render_1p_rm_3:4;
        RBus_UInt32  render_1p_rm_2:4;
        RBus_UInt32  render_1p_rm_1:4;
        RBus_UInt32  render_1p_rm_0:4;
        RBus_UInt32  render_2p_rma_1:4;
        RBus_UInt32  render_2p_rmb_1:4;
        RBus_UInt32  render_2p_rma_0:4;
        RBus_UInt32  render_2p_rmb_0:4;
    };
}d_2d_to_3d_d_2d3d_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  render_2p_testrwm_1:1;
        RBus_UInt32  render_2p_testrwm_0:1;
    };
}d_2d_to_3d_d_2d3d_bist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c0:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c1:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c2:4;
        RBus_UInt32  res2:15;
        RBus_UInt32  d_2d3d_output_lpf_y_en:1;
    };
}d_2d_to_3d_d_2d3d_output_fil_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c0:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c1:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c2:4;
        RBus_UInt32  res2:15;
        RBus_UInt32  d_2d3d_output_lpf_c_en:1;
    };
}d_2d_to_3d_d_2d3d_output_fil_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  histo_depth_weight:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  h_grid_size:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  v_grid_size:9;
        RBus_UInt32  res3:3;
        RBus_UInt32  histo_en:1;
    };
}d_2d_to_3d_d_2d3d_histo_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  color6_y_act:1;
        RBus_UInt32  color5_y_act:1;
        RBus_UInt32  color4_y_act:1;
        RBus_UInt32  color3_y_act:1;
        RBus_UInt32  color2_y_act:1;
        RBus_UInt32  color1_y_act:1;
    };
}d_2d_to_3d_d_2d3d_histo_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_up7:4;
        RBus_UInt32  weight_dis_up6:4;
        RBus_UInt32  weight_dis_up5:4;
        RBus_UInt32  weight_dis_up4:4;
        RBus_UInt32  weight_dis_up3:4;
        RBus_UInt32  weight_dis_up2:4;
        RBus_UInt32  weight_dis_up1:4;
        RBus_UInt32  weight_dis_up0:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_up15:4;
        RBus_UInt32  weight_dis_up14:4;
        RBus_UInt32  weight_dis_up13:4;
        RBus_UInt32  weight_dis_up12:4;
        RBus_UInt32  weight_dis_up11:4;
        RBus_UInt32  weight_dis_up10:4;
        RBus_UInt32  weight_dis_up9:4;
        RBus_UInt32  weight_dis_up8:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_lr7:4;
        RBus_UInt32  weight_dis_lr6:4;
        RBus_UInt32  weight_dis_lr5:4;
        RBus_UInt32  weight_dis_lr4:4;
        RBus_UInt32  weight_dis_lr3:4;
        RBus_UInt32  weight_dis_lr2:4;
        RBus_UInt32  weight_dis_lr1:4;
        RBus_UInt32  weight_dis_lr0:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_lr15:4;
        RBus_UInt32  weight_dis_lr14:4;
        RBus_UInt32  weight_dis_lr13:4;
        RBus_UInt32  weight_dis_lr12:4;
        RBus_UInt32  weight_dis_lr11:4;
        RBus_UInt32  weight_dis_lr10:4;
        RBus_UInt32  weight_dis_lr9:4;
        RBus_UInt32  weight_dis_lr8:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_lr23:4;
        RBus_UInt32  weight_dis_lr22:4;
        RBus_UInt32  weight_dis_lr21:4;
        RBus_UInt32  weight_dis_lr20:4;
        RBus_UInt32  weight_dis_lr19:4;
        RBus_UInt32  weight_dis_lr18:4;
        RBus_UInt32  weight_dis_lr17:4;
        RBus_UInt32  weight_dis_lr16:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_lr31:4;
        RBus_UInt32  weight_dis_lr30:4;
        RBus_UInt32  weight_dis_lr29:4;
        RBus_UInt32  weight_dis_lr28:4;
        RBus_UInt32  weight_dis_lr27:4;
        RBus_UInt32  weight_dis_lr26:4;
        RBus_UInt32  weight_dis_lr25:4;
        RBus_UInt32  weight_dis_lr24:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up2_7:4;
        RBus_UInt32  weight_up2_6:4;
        RBus_UInt32  weight_up2_5:4;
        RBus_UInt32  weight_up2_4:4;
        RBus_UInt32  weight_up2_3:4;
        RBus_UInt32  weight_up2_2:4;
        RBus_UInt32  weight_up2_1:4;
        RBus_UInt32  weight_up2_0:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up2_15:4;
        RBus_UInt32  weight_up2_14:4;
        RBus_UInt32  weight_up2_13:4;
        RBus_UInt32  weight_up2_12:4;
        RBus_UInt32  weight_up2_11:4;
        RBus_UInt32  weight_up2_10:4;
        RBus_UInt32  weight_up2_9:4;
        RBus_UInt32  weight_up2_8:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up3_7:4;
        RBus_UInt32  weight_up3_6:4;
        RBus_UInt32  weight_up3_5:4;
        RBus_UInt32  weight_up3_4:4;
        RBus_UInt32  weight_up3_3:4;
        RBus_UInt32  weight_up3_2:4;
        RBus_UInt32  weight_up3_1:4;
        RBus_UInt32  weight_up3_0:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up3_15:4;
        RBus_UInt32  weight_up3_14:4;
        RBus_UInt32  weight_up3_13:4;
        RBus_UInt32  weight_up3_12:4;
        RBus_UInt32  weight_up3_11:4;
        RBus_UInt32  weight_up3_10:4;
        RBus_UInt32  weight_up3_9:4;
        RBus_UInt32  weight_up3_8:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  weight_01_on_color4:3;
        RBus_UInt32  color4_v1:4;
        RBus_UInt32  color4_u1:4;
        RBus_UInt32  color4_y1:4;
        RBus_UInt32  color4_v0:4;
        RBus_UInt32  color4_u0:4;
        RBus_UInt32  color4_y0:4;
    };
}d_2d_to_3d_d_2d3d_histo_color_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up4_7:4;
        RBus_UInt32  weight_up4_6:4;
        RBus_UInt32  weight_up4_5:4;
        RBus_UInt32  weight_up4_4:4;
        RBus_UInt32  weight_up4_3:4;
        RBus_UInt32  weight_up4_2:4;
        RBus_UInt32  weight_up4_1:4;
        RBus_UInt32  weight_up4_0:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up4_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up4_15:4;
        RBus_UInt32  weight_up4_14:4;
        RBus_UInt32  weight_up4_13:4;
        RBus_UInt32  weight_up4_12:4;
        RBus_UInt32  weight_up4_11:4;
        RBus_UInt32  weight_up4_10:4;
        RBus_UInt32  weight_up4_9:4;
        RBus_UInt32  weight_up4_8:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  color5_v:4;
        RBus_UInt32  color5_u:4;
        RBus_UInt32  color5_y:4;
    };
}d_2d_to_3d_d_2d3d_histo_color_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up5_7:4;
        RBus_UInt32  weight_up5_6:4;
        RBus_UInt32  weight_up5_5:4;
        RBus_UInt32  weight_up5_4:4;
        RBus_UInt32  weight_up5_3:4;
        RBus_UInt32  weight_up5_2:4;
        RBus_UInt32  weight_up5_1:4;
        RBus_UInt32  weight_up5_0:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up5_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up5_15:4;
        RBus_UInt32  weight_up5_14:4;
        RBus_UInt32  weight_up5_13:4;
        RBus_UInt32  weight_up5_12:4;
        RBus_UInt32  weight_up5_11:4;
        RBus_UInt32  weight_up5_10:4;
        RBus_UInt32  weight_up5_9:4;
        RBus_UInt32  weight_up5_8:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  color6_v:8;
        RBus_UInt32  color6_u:8;
        RBus_UInt32  color6_y:8;
    };
}d_2d_to_3d_d_2d3d_histo_color_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  depth_weight_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  depth_weight_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  depth_weight_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  depth_weight_1:6;
    };
}d_2d_to_3d_d_2d3d_histo_depth_weight_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  depth_weight_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  depth_weight_5:6;
    };
}d_2d_to_3d_d_2d3d_histo_depth_weight_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  slope_2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  margin_2:7;
        RBus_UInt32  res3:5;
        RBus_UInt32  slope_1:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  margin_1:7;
    };
}d_2d_to_3d_d_2d3d_histo_diff_depth_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  slope_4:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  margin_4:7;
        RBus_UInt32  res3:5;
        RBus_UInt32  slope_3:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  margin_3:7;
    };
}d_2d_to_3d_d_2d3d_histo_diff_depth_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  slope_6:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  margin_6:7;
        RBus_UInt32  res3:5;
        RBus_UInt32  slope_5:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  margin_5:7;
    };
}d_2d_to_3d_d_2d3d_histo_diff_depth_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  temporal_2_th_s:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  temporal_2_th_l:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  temporal_2_en:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  temporal_1_th_s:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  temporal_1_th_l:3;
        RBus_UInt32  res6:3;
        RBus_UInt32  temporal_1_en:1;
    };
}d_2d_to_3d_d_2d3d_histo_temp_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  temporal_3_th_s:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  temporal_3_th_l:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  temporal_3_en:1;
    };
}d_2d_to_3d_d_2d3d_histo_temp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  su_hfactor:20;
    };
}d_2d_to_3d_d_2d3d_histo_su_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  su_vfactor:20;
    };
}d_2d_to_3d_d_2d3d_histo_su_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  su_scaleup_htab_coef0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  su_scaleup_htab_coef1:10;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  su_scaleup_htab_coef3:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  su_scaleup_htab_coef2:10;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  su_scaleup_htab_coef4:10;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  su_scaleup_vtab_coef0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  su_scaleup_vtab_coef1:10;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  su_scaleup_vtab_coef3:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  su_scaleup_vtab_coef2:10;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  su_scaleup_vtab_coef4:10;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  depth_update_en:1;
        RBus_UInt32  depth_sw_mode:1;
    };
}d_2d_to_3d_d_2d3d_histo_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  depth_adr:9;
    };
}d_2d_to_3d_d_2d3d_histo_sram_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  depth_dat:8;
    };
}d_2d_to_3d_d_2d3d_histo_sram_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  depth_max:8;
        RBus_UInt32  depth_min:8;
        RBus_UInt32  res1:13;
        RBus_UInt32  max_min_mux:2;
        RBus_UInt32  max_min_en:1;
    };
}d_2d_to_3d_d_2d3d_histo_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  iir_weight:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  iir_en:1;
    };
}d_2d_to_3d_d_2d3d_histo_iir_RBUS;

#else //apply LITTLE_ENDIAN

//======D_2D_TO_3D register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
    };
}d_2d_to_3d_d_2d3d_db_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  object1_depth_en:1;
        RBus_UInt32  object2_depth_en:1;
        RBus_UInt32  object3_depth_en:1;
        RBus_UInt32  tilt_depth_en:1;
        RBus_UInt32  l_flag_inv:1;
        RBus_UInt32  r_frame_shift_en:1;
        RBus_UInt32  l_frame_shift_en:1;
        RBus_UInt32  depth_debug_mode:1;
        RBus_UInt32  d_2d3d_depth_frac_en:1;
        RBus_UInt32  output_format:1;
        RBus_UInt32  obj_y_src_sel:1;
        RBus_UInt32  input_sbs_render_mode:1;
        RBus_UInt32  render_method:1;
        RBus_UInt32  depth_src_mux:1;
        RBus_UInt32  object4_depth_en:1;
        RBus_UInt32  object5_depth_en:1;
        RBus_UInt32  object6_depth_en:1;
        RBus_UInt32  res2:14;
    };
}d_2d_to_3d_d_2d3d_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object1_gain:8;
        RBus_UInt32  object1_offset:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  object1_thd:8;
        RBus_UInt32  res2:4;
    };
}d_2d_to_3d_d_2d3d_object1_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object2_gain:8;
        RBus_UInt32  object2_offset:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  object2_thd:8;
        RBus_UInt32  res2:4;
    };
}d_2d_to_3d_d_2d3d_object2_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object3_gain:8;
        RBus_UInt32  object3_offset:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  object3_thd:8;
        RBus_UInt32  res2:4;
    };
}d_2d_to_3d_d_2d3d_object3_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object4_gain:8;
        RBus_UInt32  object4_offset:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  object4_thd:8;
        RBus_UInt32  res2:4;
    };
}d_2d_to_3d_d_2d3d_object4_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object5_gain:8;
        RBus_UInt32  object5_offset:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  object5_thd:8;
        RBus_UInt32  res2:4;
    };
}d_2d_to_3d_d_2d3d_object5_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object6_gain:8;
        RBus_UInt32  object6_offset:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  object6_thd:8;
        RBus_UInt32  res2:4;
    };
}d_2d_to_3d_d_2d3d_object6_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tilt_gain:8;
        RBus_UInt32  tilt_offset:8;
        RBus_UInt32  tilt_thd:8;
        RBus_UInt32  res1:8;
    };
}d_2d_to_3d_d_2d3d_tilt_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  histo_gain:8;
        RBus_UInt32  histo_offset:8;
        RBus_UInt32  histo_thd:8;
        RBus_UInt32  res1:8;
    };
}d_2d_to_3d_d_2d3d_histo_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  border_den_end:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  border_den_start:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  border_en:1;
    };
}d_2d_to_3d_d_2d3d_b_border_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  initial_depth:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  tilt_depth_step:12;
        RBus_UInt32  res2:4;
    };
}d_2d_to_3d_d_2d3d_tilt_depth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object1_depth_dir:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  object1_depth_ref1:8;
        RBus_UInt32  object1_depth_weight1:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object1_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object1_depth_ref2:8;
        RBus_UInt32  object1_depth_weight2:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  object1_depth_ref3:8;
        RBus_UInt32  object1_depth_weight3:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object1_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object2_depth_dir:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  object2_depth_ref1:8;
        RBus_UInt32  object2_depth_weight1:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object2_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object2_depth_ref2:8;
        RBus_UInt32  object2_depth_weight2:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  object2_depth_ref3:8;
        RBus_UInt32  object2_depth_weight3:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object2_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object3_depth_dir:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  object3_depth_ref1:8;
        RBus_UInt32  object3_depth_weight1:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object3_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object3_depth_ref2:8;
        RBus_UInt32  object3_depth_weight2:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  object3_depth_ref3:8;
        RBus_UInt32  object3_depth_weight3:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object3_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object4_depth_dir:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  object4_depth_ref1:8;
        RBus_UInt32  object4_depth_weight1:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object4_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object4_depth_ref2:8;
        RBus_UInt32  object4_depth_weight2:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  object4_depth_ref3:8;
        RBus_UInt32  object4_depth_weight3:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object4_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object5_depth_dir:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  object5_depth_ref1:8;
        RBus_UInt32  object5_depth_weight1:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object5_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object5_depth_ref2:8;
        RBus_UInt32  object5_depth_weight2:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  object5_depth_ref3:8;
        RBus_UInt32  object5_depth_weight3:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object5_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object6_depth_dir:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  object6_depth_ref1:8;
        RBus_UInt32  object6_depth_weight1:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object6_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object6_depth_ref2:8;
        RBus_UInt32  object6_depth_weight2:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  object6_depth_ref3:8;
        RBus_UInt32  object6_depth_weight3:3;
        RBus_UInt32  res2:5;
    };
}d_2d_to_3d_d_2d3d_object6_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_2d3d_depth_lpf_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  d_2d3d_depth_lpf_c2:4;
        RBus_UInt32  d_2d3d_depth_lpf_c1:4;
        RBus_UInt32  d_2d3d_depth_lpf_c0:4;
        RBus_UInt32  res2:8;
    };
}d_2d_to_3d_d_2d3d_depth_fil_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shifter_gain:8;
        RBus_UInt32  shifter_offset:8;
        RBus_UInt32  shifter_thd:6;
        RBus_UInt32  shifter_offset2:10;
    };
}d_2d_to_3d_d_2d3d_shifter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbs_en:1;
        RBus_UInt32  dbs_seg_num:2;
        RBus_UInt32  res1:29;
    };
}d_2d_to_3d_d_2d3d_boundary_scaling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hole_fil_sel:3;
        RBus_UInt32  hf_new_en:1;
        RBus_UInt32  res1:28;
    };
}d_2d_to_3d_d_2d3d_hole_fill_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029674_31_0:32;
    };
}d_2d_to_3d_d_2d3d_dummy0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029678_31_0:32;
    };
}d_2d_to_3d_d_2d3d_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  render_2p_bist_fail_0:1;
        RBus_UInt32  render_2p_bist_fail_1:1;
        RBus_UInt32  render_1p_bist_fail_0:1;
        RBus_UInt32  render_1p_bist_fail_1:1;
        RBus_UInt32  render_1p_bist_fail_2:1;
        RBus_UInt32  render_1p_bist_fail_3:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  render_2p_drf_bist_fail_0:1;
        RBus_UInt32  render_2p_drf_bist_fail_1:1;
        RBus_UInt32  render_1p_drf_bist_fail_0:1;
        RBus_UInt32  render_1p_drf_bist_fail_1:1;
        RBus_UInt32  render_1p_drf_bist_fail_2:1;
        RBus_UInt32  render_1p_drf_bist_fail_3:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  render_2p_ls_0:1;
        RBus_UInt32  render_2p_ls_1:1;
        RBus_UInt32  render_1p_ls_0:1;
        RBus_UInt32  render_1p_ls_1:1;
        RBus_UInt32  render_1p_ls_2:1;
        RBus_UInt32  render_1p_ls_3:1;
        RBus_UInt32  render_2p_rmeb_0:1;
        RBus_UInt32  render_2p_rmea_0:1;
        RBus_UInt32  render_2p_rmeb_1:1;
        RBus_UInt32  render_2p_rmea_1:1;
        RBus_UInt32  render_1p_rme_0:1;
        RBus_UInt32  render_1p_rme_1:1;
        RBus_UInt32  render_1p_rme_2:1;
        RBus_UInt32  render_1p_rme_3:1;
    };
}d_2d_to_3d_d_2d3d_bist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  render_2p_rmb_0:4;
        RBus_UInt32  render_2p_rma_0:4;
        RBus_UInt32  render_2p_rmb_1:4;
        RBus_UInt32  render_2p_rma_1:4;
        RBus_UInt32  render_1p_rm_0:4;
        RBus_UInt32  render_1p_rm_1:4;
        RBus_UInt32  render_1p_rm_2:4;
        RBus_UInt32  render_1p_rm_3:4;
    };
}d_2d_to_3d_d_2d3d_bist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  render_2p_testrwm_0:1;
        RBus_UInt32  render_2p_testrwm_1:1;
        RBus_UInt32  res1:30;
    };
}d_2d_to_3d_d_2d3d_bist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_2d3d_output_lpf_y_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  d_2d3d_output_y_lpf_c2:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c1:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c0:4;
        RBus_UInt32  res2:4;
    };
}d_2d_to_3d_d_2d3d_output_fil_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_2d3d_output_lpf_c_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  d_2d3d_output_c_lpf_c2:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c1:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c0:4;
        RBus_UInt32  res2:4;
    };
}d_2d_to_3d_d_2d3d_output_fil_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  histo_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  v_grid_size:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  h_grid_size:9;
        RBus_UInt32  res3:3;
        RBus_UInt32  histo_depth_weight:4;
    };
}d_2d_to_3d_d_2d3d_histo_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color1_y_act:1;
        RBus_UInt32  color2_y_act:1;
        RBus_UInt32  color3_y_act:1;
        RBus_UInt32  color4_y_act:1;
        RBus_UInt32  color5_y_act:1;
        RBus_UInt32  color6_y_act:1;
        RBus_UInt32  res1:26;
    };
}d_2d_to_3d_d_2d3d_histo_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_up0:4;
        RBus_UInt32  weight_dis_up1:4;
        RBus_UInt32  weight_dis_up2:4;
        RBus_UInt32  weight_dis_up3:4;
        RBus_UInt32  weight_dis_up4:4;
        RBus_UInt32  weight_dis_up5:4;
        RBus_UInt32  weight_dis_up6:4;
        RBus_UInt32  weight_dis_up7:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_up8:4;
        RBus_UInt32  weight_dis_up9:4;
        RBus_UInt32  weight_dis_up10:4;
        RBus_UInt32  weight_dis_up11:4;
        RBus_UInt32  weight_dis_up12:4;
        RBus_UInt32  weight_dis_up13:4;
        RBus_UInt32  weight_dis_up14:4;
        RBus_UInt32  weight_dis_up15:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_lr0:4;
        RBus_UInt32  weight_dis_lr1:4;
        RBus_UInt32  weight_dis_lr2:4;
        RBus_UInt32  weight_dis_lr3:4;
        RBus_UInt32  weight_dis_lr4:4;
        RBus_UInt32  weight_dis_lr5:4;
        RBus_UInt32  weight_dis_lr6:4;
        RBus_UInt32  weight_dis_lr7:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_lr8:4;
        RBus_UInt32  weight_dis_lr9:4;
        RBus_UInt32  weight_dis_lr10:4;
        RBus_UInt32  weight_dis_lr11:4;
        RBus_UInt32  weight_dis_lr12:4;
        RBus_UInt32  weight_dis_lr13:4;
        RBus_UInt32  weight_dis_lr14:4;
        RBus_UInt32  weight_dis_lr15:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_lr16:4;
        RBus_UInt32  weight_dis_lr17:4;
        RBus_UInt32  weight_dis_lr18:4;
        RBus_UInt32  weight_dis_lr19:4;
        RBus_UInt32  weight_dis_lr20:4;
        RBus_UInt32  weight_dis_lr21:4;
        RBus_UInt32  weight_dis_lr22:4;
        RBus_UInt32  weight_dis_lr23:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_dis_lr24:4;
        RBus_UInt32  weight_dis_lr25:4;
        RBus_UInt32  weight_dis_lr26:4;
        RBus_UInt32  weight_dis_lr27:4;
        RBus_UInt32  weight_dis_lr28:4;
        RBus_UInt32  weight_dis_lr29:4;
        RBus_UInt32  weight_dis_lr30:4;
        RBus_UInt32  weight_dis_lr31:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_dispread_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up2_0:4;
        RBus_UInt32  weight_up2_1:4;
        RBus_UInt32  weight_up2_2:4;
        RBus_UInt32  weight_up2_3:4;
        RBus_UInt32  weight_up2_4:4;
        RBus_UInt32  weight_up2_5:4;
        RBus_UInt32  weight_up2_6:4;
        RBus_UInt32  weight_up2_7:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up2_8:4;
        RBus_UInt32  weight_up2_9:4;
        RBus_UInt32  weight_up2_10:4;
        RBus_UInt32  weight_up2_11:4;
        RBus_UInt32  weight_up2_12:4;
        RBus_UInt32  weight_up2_13:4;
        RBus_UInt32  weight_up2_14:4;
        RBus_UInt32  weight_up2_15:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up3_0:4;
        RBus_UInt32  weight_up3_1:4;
        RBus_UInt32  weight_up3_2:4;
        RBus_UInt32  weight_up3_3:4;
        RBus_UInt32  weight_up3_4:4;
        RBus_UInt32  weight_up3_5:4;
        RBus_UInt32  weight_up3_6:4;
        RBus_UInt32  weight_up3_7:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up3_8:4;
        RBus_UInt32  weight_up3_9:4;
        RBus_UInt32  weight_up3_10:4;
        RBus_UInt32  weight_up3_11:4;
        RBus_UInt32  weight_up3_12:4;
        RBus_UInt32  weight_up3_13:4;
        RBus_UInt32  weight_up3_14:4;
        RBus_UInt32  weight_up3_15:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color4_y0:4;
        RBus_UInt32  color4_u0:4;
        RBus_UInt32  color4_v0:4;
        RBus_UInt32  color4_y1:4;
        RBus_UInt32  color4_u1:4;
        RBus_UInt32  color4_v1:4;
        RBus_UInt32  weight_01_on_color4:3;
        RBus_UInt32  res1:5;
    };
}d_2d_to_3d_d_2d3d_histo_color_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up4_0:4;
        RBus_UInt32  weight_up4_1:4;
        RBus_UInt32  weight_up4_2:4;
        RBus_UInt32  weight_up4_3:4;
        RBus_UInt32  weight_up4_4:4;
        RBus_UInt32  weight_up4_5:4;
        RBus_UInt32  weight_up4_6:4;
        RBus_UInt32  weight_up4_7:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up4_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up4_8:4;
        RBus_UInt32  weight_up4_9:4;
        RBus_UInt32  weight_up4_10:4;
        RBus_UInt32  weight_up4_11:4;
        RBus_UInt32  weight_up4_12:4;
        RBus_UInt32  weight_up4_13:4;
        RBus_UInt32  weight_up4_14:4;
        RBus_UInt32  weight_up4_15:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color5_y:4;
        RBus_UInt32  color5_u:4;
        RBus_UInt32  color5_v:4;
        RBus_UInt32  res1:20;
    };
}d_2d_to_3d_d_2d3d_histo_color_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up5_0:4;
        RBus_UInt32  weight_up5_1:4;
        RBus_UInt32  weight_up5_2:4;
        RBus_UInt32  weight_up5_3:4;
        RBus_UInt32  weight_up5_4:4;
        RBus_UInt32  weight_up5_5:4;
        RBus_UInt32  weight_up5_6:4;
        RBus_UInt32  weight_up5_7:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up5_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  weight_up5_8:4;
        RBus_UInt32  weight_up5_9:4;
        RBus_UInt32  weight_up5_10:4;
        RBus_UInt32  weight_up5_11:4;
        RBus_UInt32  weight_up5_12:4;
        RBus_UInt32  weight_up5_13:4;
        RBus_UInt32  weight_up5_14:4;
        RBus_UInt32  weight_up5_15:4;
    };
}d_2d_to_3d_d_2d3d_histo_weight_up5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color6_y:8;
        RBus_UInt32  color6_u:8;
        RBus_UInt32  color6_v:8;
        RBus_UInt32  res1:8;
    };
}d_2d_to_3d_d_2d3d_histo_color_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  depth_weight_1:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  depth_weight_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  depth_weight_3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  depth_weight_4:6;
        RBus_UInt32  res4:2;
    };
}d_2d_to_3d_d_2d3d_histo_depth_weight_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  depth_weight_5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  depth_weight_6:6;
        RBus_UInt32  res2:18;
    };
}d_2d_to_3d_d_2d3d_histo_depth_weight_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  margin_1:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  slope_1:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  margin_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  slope_2:3;
        RBus_UInt32  res4:5;
    };
}d_2d_to_3d_d_2d3d_histo_diff_depth_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  margin_3:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  slope_3:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  margin_4:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  slope_4:3;
        RBus_UInt32  res4:5;
    };
}d_2d_to_3d_d_2d3d_histo_diff_depth_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  margin_5:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  slope_5:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  margin_6:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  slope_6:3;
        RBus_UInt32  res4:5;
    };
}d_2d_to_3d_d_2d3d_histo_diff_depth_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  temporal_1_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  temporal_1_th_l:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  temporal_1_th_s:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  temporal_2_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  temporal_2_th_l:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  temporal_2_th_s:3;
        RBus_UInt32  res6:5;
    };
}d_2d_to_3d_d_2d3d_histo_temp_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  temporal_3_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  temporal_3_th_l:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  temporal_3_th_s:3;
        RBus_UInt32  res3:21;
    };
}d_2d_to_3d_d_2d3d_histo_temp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_hfactor:20;
        RBus_UInt32  res1:11;
        RBus_UInt32  su_en:1;
    };
}d_2d_to_3d_d_2d3d_histo_su_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_vfactor:20;
        RBus_UInt32  res1:12;
    };
}d_2d_to_3d_d_2d3d_histo_su_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_scaleup_htab_coef1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  su_scaleup_htab_coef0:10;
        RBus_UInt32  res2:6;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_scaleup_htab_coef2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  su_scaleup_htab_coef3:10;
        RBus_UInt32  res2:6;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_scaleup_htab_coef4:10;
        RBus_UInt32  res1:22;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_scaleup_vtab_coef1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  su_scaleup_vtab_coef0:10;
        RBus_UInt32  res2:6;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_scaleup_vtab_coef2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  su_scaleup_vtab_coef3:10;
        RBus_UInt32  res2:6;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_scaleup_vtab_coef4:10;
        RBus_UInt32  res1:22;
    };
}d_2d_to_3d_d_2d3d_histo_su_coef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  depth_sw_mode:1;
        RBus_UInt32  depth_update_en:1;
        RBus_UInt32  res1:30;
    };
}d_2d_to_3d_d_2d3d_histo_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  depth_adr:9;
        RBus_UInt32  res1:23;
    };
}d_2d_to_3d_d_2d3d_histo_sram_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  depth_dat:8;
        RBus_UInt32  res1:24;
    };
}d_2d_to_3d_d_2d3d_histo_sram_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_min_en:1;
        RBus_UInt32  max_min_mux:2;
        RBus_UInt32  res1:13;
        RBus_UInt32  depth_min:8;
        RBus_UInt32  depth_max:8;
    };
}d_2d_to_3d_d_2d3d_histo_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iir_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  iir_weight:8;
        RBus_UInt32  res2:20;
    };
}d_2d_to_3d_d_2d3d_histo_iir_RBUS;




#endif 


#endif 
